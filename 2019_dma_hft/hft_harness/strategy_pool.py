import numpy as np
import pandas as pd
import logging

from datetime import datetime, timedelta
from util.utilities_logic import LoggerAdapter
from time import time
from abc import ABCMeta, abstractmethod


def get_prev_bday(calendar):
    idx = np.arange(calendar.shape[0])
    cur_idx = idx[pd.Timestamp(datetime.now().date()) == calendar]
    return cur_idx - 1


class Pool:
    def __int__(self):
        pass

    @abstractmethod
    def judge_trade(self, *args):
        """
        long 조건에 부합하는지 확인
        """
        raise NotImplementedError("Should implement set_long()")


class OrderImbalance(Pool):
    __name__ = "OrderImabalance"

    def __init__(self, que, code, deps, engine):
        super(Pool, self).__init__()
        self.code = code
        self.que = que
        self.deps = deps
        self.db_engine = engine
        self.prev_max = 0
        self.n_day = 3
        self.prev_bid_price, self.prev_bid_vol = 0.0, 0.0
        self.prev_ask_price, self.prev_ask_vol = 0.0, 0.0
        self.prev_b_up_trd, self.prev_b_dn_trd, self.prev_b_ss_trd = False, False, False
        self.trd_cnt = 0
        self.oi_buffer = []
        self.up_trd_thd = 0.0
        self.dn_trd_thd = 0.0
        self.ss_trd_thd = 0.0
        self.cum_data_num = 1000
        self.logger = logging.getLogger("my_setting")
        self.logger = LoggerAdapter(OrderImbalance.__name__, self.logger)

        self.kor_bday_cal = self._get_kor_calendar()
        self._set_init_param()

    def _get_kor_calendar(self):
        kor_holiday = pd.read_excel("data/holiday.xls")
        kor_cal = pd.offsets.CustomBusinessDay(holidays=kor_holiday["일자 및 요일"].values)
        kor_date_rng = pd.date_range(start='20190101', end='20191231', freq=kor_cal)
        return kor_date_rng

    def _set_init_param(self):
        idx = get_prev_bday(self.kor_bday_cal)
        ed_date = self.kor_bday_cal[idx].strftime("%Y%m%d").values[0]
        st_date = self.kor_bday_cal[idx - self.n_day + 1].strftime("%Y%m%d").values[0]

        table = "STOCK_FUT_LIMIT_ORD"
        column = "TOTAL_L_LIMIT_ORD_Q, L_LVL_1_SIGN, L_LVL_1_PRC, L_LVL_1_Q, L_LVL_2_SIGN, L_LVL_2_PRC, \
                 L_LVL_2_Q, L_LVL_3_SIGN, L_LVL_3_PRC, L_LVL_3_Q, L_LVL_4_SIGN, L_LVL_4_PRC, L_LVL_4_Q, L_LVL_5_SIGN, \
                 L_LVL_5_PRC, L_LVL_5_Q, TOTAL_S_LIMIT_ORD_Q, S_LVL_1_SIGN, S_LVL_1_PRC, S_LVL_1_Q, S_LVL_2_SIGN, \
                 S_LVL_2_PRC, S_LVL_2_Q, S_LVL_3_SIGN, S_LVL_3_PRC, S_LVL_3_Q, S_LVL_4_SIGN, S_LVL_4_PRC, S_LVL_4_Q, \
                 S_LVL_5_SIGN, S_LVL_5_PRC, S_LVL_5_Q, TOTAL_L_TRD_CNT, L_LVL_1_TRD_CNT, L_LVL_2_TRD_CNT, L_LVL_3_TRD_CNT, \
                 L_LVL_4_TRD_CNT, L_LVL_5_TRD_CNT, TOTAL_S_TRD_CNT, S_LVL_1_TRD_CNT, S_LVL_2_TRD_CNT, S_LVL_3_TRD_CNT, \
                 S_LVL_4_TRD_CNT, S_LVL_5_TRD_CNT, ORD_RCV_T, RTIME, SEQ"
        condition = "(YMD BETWEEN '{0}' AND '{1}') AND (ISIN_CODE = '{2}')".format(st_date, ed_date, self.code)

        data = self.db_engine.sql_read_column(table, condition, column)
        data["midprice"] = (data["S_LVL_1_PRC"] + data["L_LVL_1_PRC"]) / 2
        data["delta_ml"] = (data['L_LVL_1_PRC'] - data['L_LVL_1_PRC'].shift(1)).fillna(0)
        data["delta_ms"] = (data['S_LVL_1_PRC'] - data['S_LVL_1_PRC'].shift(1)).fillna(0)
        data["delta_vl"] = np.zeros_like(data['L_LVL_1_PRC'])
        data["delta_vs"] = np.zeros_like(data['S_LVL_1_PRC'])
        # 매도호가 거래량 차이 연산
        # 이전 매도1호가 == 현재 매도1호가, (현재 매도1잔량 - 이전 매도1잔량)
        # 이전 매도1호가 > 현재 매도1호가, (현재 매도1잔량)
        # 이전 매도1호가 < 현재 매도1호가, (0)
        sel_time = data["delta_ms"] == 0
        data.loc[sel_time, "delta_vs"] = (data['S_LVL_1_Q'] - data['S_LVL_1_Q'].shift(1)).fillna(0).loc[sel_time]
        sel_time = data["delta_ms"] < 0
        data.loc[sel_time, "delta_vs"] = data['S_LVL_1_Q'].loc[sel_time]
        # 매수호가 거래량 차이 연산
        # 이전 매수1호가 == 현재 매수1호가, (현재 매수1잔량 - 이전 매수1잔량)
        # 이전 매수1호가 < 현재 매수1호가, (현재 매수1잔량)
        # 이전 매수1호가 > 현재 매수1호가, (0)
        sel_time = data["delta_ml"] == 0
        data.loc[sel_time, "delta_vl"] = (data['L_LVL_1_Q'] - data['L_LVL_1_Q'].
                                              shift(1)).fillna(0).loc[sel_time]
        sel_time = data["delta_ml"] > 0
        data.loc[sel_time, "delta_vl"] = data['L_LVL_1_Q'].loc[sel_time]

        data["oi"] = data["delta_vl"] - data["delta_vs"]
        oi_cum = data["oi"].rolling(self.cum_data_num).sum().fillna(method="bfill")
        up_trd = oi_cum.loc[data["midprice"].pct_change(1) > 0].dropna()
        dn_trd = oi_cum.loc[data["midprice"].pct_change(1) < 0].dropna()

        self.up_trd_thd = up_trd.mean() + up_trd.std()
        self.dn_trd_thd = dn_trd.mean() - dn_trd.std()
        self.ss_trd_thd = oi_cum.mean() + oi_cum.std() * 2

        self.logger.debug("{0} / {1}".format(st_date, ed_date))
        self.logger.debug("Rising trend: {0:0.2f} / {1:0.2f}".format(up_trd.mean(), up_trd.std()))
        self.logger.debug("Falling trend: {0:0.2f} / {1:0.2f}".format(dn_trd.mean(), dn_trd.std()))
        self.logger.debug("Standstill: {0:0.2f} / {1:0.2f}".format(oi_cum.mean(), oi_cum.std()))

    def judge_trade(self, data):
        b_log = False
        b_position_settle = False
        bid_cmd, ask_cmd = None, None

        # 매수 조건 작성
        print(data)
        bid_price, bid_vol = data["L_LVL_1_PRC"].iloc[0], data["L_LVL_1_Q"].iloc[0]
        ask_price, ask_vol = data["S_LVL_1_PRC"].iloc[0], data["S_LVL_1_Q"].iloc[0]
        bid_num = self.deps // bid_price
        ask_num = self.deps // ask_price

        if self.prev_bid_price == bid_price:
            delta_vl = bid_vol - self.prev_bid_vol
        elif self.prev_bid_price < bid_price:
            delta_vl = bid_vol
        else:
            delta_vl = 0

        if self.prev_ask_price == ask_price:
            delta_vs = ask_vol - self.prev_ask_vol
        elif self.prev_ask_price > ask_price:
            delta_vs = ask_vol
        else:
            delta_vs = 0

        self.oi_buffer.append(delta_vl - delta_vs)
        oi_sum = np.sum(self.oi_buffer)

        b_up_trd = oi_sum > self.up_trd_thd
        b_dn_trd = oi_sum < self.dn_trd_thd
        b_ss_trd = (abs(oi_sum) < self.ss_trd_thd) and not (b_up_trd or b_dn_trd)

        if len(self.oi_buffer) == self.cum_data_num:
            # 일중 최초 Trading 설정
            if self.trd_cnt == 0:
                if b_up_trd:
                    bid_cmd = [ask_price, ask_num]  # 매수 포지션 설정 [매도1호가 지정가 주문]
                    ask_cmd = None
                    self.trd_cnt += 1
                    b_log = True
                elif b_dn_trd:
                    bid_cmd = None
                    ask_cmd = [bid_price, bid_num]  # 매도 포지션 설정 [매수1호가 지정가 주문]
                    self.trd_cnt += 1
                    b_log = True
                elif b_ss_trd:
                    # 매수 / 매도 포지션 모두 설정 [마켓 메이킹]
                    bid_cmd = [bid_price, bid_num]
                    ask_cmd = [ask_price, ask_num]
                    self.trd_cnt += 1
                    b_log = True

            if self.prev_b_ss_trd:
                if b_dn_trd:
                    # 보합에서 하락 변환시
                    b_position_settle = True  # 기존 포지션 청산
                    bid_cmd = None
                    ask_cmd = [bid_price, bid_num]  # 매도 포지션 설정 [매수1호가 지정가 주문]
                    self.trd_cnt += 1
                    b_log = True
                elif b_up_trd:
                    # 보합에서 상승 변환시
                    b_position_settle = True  # 기존 포지션 청산
                    bid_cmd = [ask_price, ask_num]  # 매수 포지션 설정 [매도1호가 지정가 주문]
                    ask_cmd = None
                    self.trd_cnt += 1
                    b_log = True
            elif self.prev_b_up_trd:
                if b_dn_trd:
                    # 상승에서 하락 변환시
                    b_position_settle = True  # 기존 포지션 청산
                    bid_cmd = None
                    ask_cmd = [bid_price, bid_num]  # 매도 포지션 설정 [매수1호가 지정가 주문]
                    self.trd_cnt += 1
                    b_log = True
                # elif b_up_trd:
                # 상승 유지시, 포지션 유지
                #     bid_cmd = None
                #     ask_cmd = None
            elif self.prev_b_dn_trd:
                if b_up_trd:
                    # 하락에서 상승 변환시
                    b_position_settle = True  # 기존 포지션 청산
                    bid_cmd = [ask_price, ask_num]  # 매수 포지션 설정 [매도1호가 지정가 주문]
                    ask_cmd = None
                    self.trd_cnt += 1
                    b_log = True
                # elif b_dn_trd:
                # 하락 유지시, 포지션 유지
                #     bid_cmd = None
                #     ask_cmd = None

            if b_ss_trd:
                if self.prev_b_up_trd or self.prev_b_dn_trd:
                    # 추세에서 보합 변환시
                    b_position_settle = True  # 기존 포지션 청산
                    self.trd_cnt += 1
                    b_log = True
                else:
                    # 보합 지속시
                    # 매수 / 매도 포지션 모두 설정 [마켓 메이킹]
                    bid_cmd = [bid_price, bid_num]
                    ask_cmd = [ask_price, ask_num]
                    self.trd_cnt += 1
                    b_log = True

            if not b_up_trd and not b_dn_trd and not b_ss_trd:
                b_position_settle = True  # 기존 포지션 청산
                bid_cmd = None
                ask_cmd = None
                self.trd_cnt += 1
                b_log = True

            del self.oi_buffer[0]
            print("trade_count : {0}".format(self.trd_cnt))

        order_cmd = {
            "time": datetime.now().strftime("%Y-%m-%d %H:%M:%S.%f"),
            "code": self.code,
            "b_settle": b_position_settle,
            "bid": bid_cmd,
            "ask": ask_cmd
        }

        if self.trd_cnt > 10000:
            self.trd_cnt = 1

        if b_log:
            self.logger.debug("bid prc {0} / vol {1} / vl {2}".format(bid_price, bid_vol, delta_vl))
            self.logger.debug("ask prc {0} / vol {1} / vl {2}".format(ask_price, ask_vol, delta_vs))
            self.logger.debug("order command: {0}".format(order_cmd))
            self.logger.debug("oi sum: {0}".format(oi_sum))
            self.logger.debug("prev. flag: up {0} / dn {1} / ss {2}".
                              format(self.prev_b_up_trd, self.prev_b_dn_trd, self.prev_b_ss_trd))
            self.logger.debug("curr. flag: up {0} / dn {1} / ss {2}".
                              format(b_up_trd, b_dn_trd, b_ss_trd))

        self.prev_bid_price, self.prev_bid_vol = bid_price, bid_vol
        self.prev_ask_price, self.prev_ask_vol = ask_price, ask_vol
        self.prev_b_up_trd, self.prev_b_dn_trd, self.prev_b_ss_trd = b_up_trd, b_dn_trd, b_ss_trd

        self.que.put(pd.Series(order_cmd))


class PairTrade(Pool):
    def __init__(self, que, code):
        super(Pool, self).__init__()
        self.code = code
        self.que = que

    def judge_trade(self, *args):
        pass


class StrategyLists:
    POOL = \
        {
            "stg000": OrderImbalance,
            "stg001": PairTrade
        }

