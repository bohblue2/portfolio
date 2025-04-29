import pandas as pd
import threading
import copy
import socket
import logging

try:
    from collections import reduce
except Exception as e:
    from functools import reduce

from queue import Queue
from abc import ABCMeta, abstractmethod
from threading import Thread
from util.utilities_logic import LoggerAdapter
from string_def import QueStr, DataName
from strategy_pool import StrategyLists


ORD_FORM = {
    'MSG_SEQ_NO': [],
    'TR_CD': ['TCHODR10001'],
    'BRD_ID': ['G1'],
    'MEMB_NO': ['00002'],
    'BRNH_NO': ['00144'],
    'ORD_ID': ['1016000003'],
    'ORIG_ORD_ID': [''],
    'ISIN_CODE': [],
    'ORD_TP': [],
    'MDY_TP': ['1'],
    'ACC_NO': ['008011249510'],
    'ORD_VOL': [],
    'ORD_PRC': [],
    'ORD_TP_CD': ['2'],
    'ORD_CND_CD': ['0'],
    'MM_ORD_TP_NO': ['00000000000'],
    'TRSY_STK_STMT_ID': ['0'],
    'TRSY_STK_TRD_MTD_CD': ['0'],
    'ASK_TP_CD': ['00'],
    'CRD_TP_CD': ['10'],
    'TRST_PRN_TP_CD': ['11'],
    'TRST_COMP_NO': [''],
    'PRG_TRD_TP_CD': ['00'],
    'STK_CERT_ACC_NO': [''],
    'ACC_TP_CD': ['31'],
    'ACC_MRGN_TP_CD': ['10'],
    'CNTRY_CD': ['410'],
    'INVT_TP_CD': ['7100'],
    'FRGN_TP_CD': ['00'],
    'ORD_MEDIA_TP_CD': ['9'],
    'ORD_ID_INFO': [''],
    'MAC_ADDR': ['010000010232'],
    'MEMB_COMP_ORD_TM': ['143837949'],
    'FEP_AREA': [''],
    'MKT_TP': ['3'],
    'CHL_TP': [''],
    'SYSTEM_TP': [''],
    'TRST_PRD_TP': ['01'],
    'DMA_SND_TP': ['1'],
    'SFEP_TP': [''],
    'FILLER': [''],
    'USR_DEFINE': [''],
    'PRG_ORD_TYP_CD': ['0'],
    'ORD_YN': ['N'],
    'MSG_TP': ['DATA'],
    'MSG': [None],
    'PK_RTIME': [None]
}


class Strategy:
    def __init__(self):
        pass

    @abstractmethod
    def _manage_mode(self, *args):
        """
        operation의 지시에 따라, 모드 변경 / 각 모드에서 signal 발생시, trade signal 생성
        short : -1, hold : 0, long : 1
        """
        raise NotImplementedError("Should implement manage_mode()")

    # @abstractmethod
    # def _set_long(self, *args):
    #     """
    #     long 조건에 부합하는지 확인
    #     """
    #     raise NotImplementedError("Should implement set_long()")
    #
    # @abstractmethod
    # def _set_short(self, *args):
    #     """
    #     short 조건에 부합하는지 확인
    #     """
    #     raise NotImplementedError("Should implement set_short()")


class Stg(Strategy, threading.Thread):
    SOCKET_IP = "127.0.0.1"
    SOCKET_PORT = 53465
    DB_INSERTED_MSG = b"TCHODR10001"

    __name__ = "Stg"

    def __init__(self, que, engine=None, **kwargs):
        super(Stg, self).__init__()
        threading.Thread.__init__(self)

        self.strategy_id = kwargs["id"]
        self.stock_code = kwargs["monitoring_stocks"]
        self.tot_stg_deps = kwargs["total_deposite"]
        self.db_engine = engine

        self.is_bid_stop = False
        self.is_ask_stop = False
        self.deps_per_st = self.tot_stg_deps // len(self.stock_code)
        self.data_que = que[QueStr.STG]
        self.put_que = que[QueStr.ORDER]

        # Logger 관련
        self.logger = logging.getLogger("my_setting")
        self.logger = LoggerAdapter(Stg.__name__, self.logger)

        # 원장관련
        self.current_position_log = dict()
        self.current_position_board = dict()

        self._set_param()

        # 소켓연결
        self._socket_obj = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self._socket_obj.connect((Stg.SOCKET_IP, Stg.SOCKET_PORT))

    def __del__(self):
        self._socket_obj.close()

    def _set_param(self):
        """
        data를 설정하고, 현재 매수 / 매도 종목 리스트를 갱신한다.
        :param data:
        :return:
        """
        pass

    def _push_ord_to_sql(self, seq_num, order):
        table = "MHFTORD"

        if order['bid'] is not None and order['ask'] is not None:
            # 매수 / 매도 주문이 동시에 진행될 때,
            ord_ = pd.DataFrame(columns=ORD_FORM.keys())

            for k in ["ask", "bid"]:
                ord_dict = copy.deepcopy(ORD_FORM)
                ord_dict['MSG_SEQ_NO'].append(seq_num)
                ord_dict['ISIN_CODE'].append(order["code"])

                if k == "bid":
                    ord_dict['ORD_TP'].append("1")  # 매수 : 1
                    ord_dict['ORD_VOL'].append("{0:010d}".format(order[k][1]))
                    ord_dict['ORD_PRC'].append("{0:011d}".format(order[k][0]))
                    temp_ord = pd.DataFrame.from_dict(ord_dict)
                else:
                    ord_dict['ORD_TP'].append("2")  # 매도 : 2
                    ord_dict['ORD_VOL'].append("{0:010d}".format(order[k][1]))
                    ord_dict['ORD_PRC'].append("{0:011d}".format(order[k][0]))
                    temp_ord = pd.DataFrame.from_dict(ord_dict)

                ord_ = pd.concat([ord_, temp_ord], axis=0, join="inner")
                del ord_dict

            self.db_engine.sql_push(ord_, table)
            self._send_to_socket(Stg.DB_INSERTED_MSG)
            self.logger.debug(ord_)
        elif order['bid'] is not None:
            # 매수 주문 진행
            ord_dict = copy.deepcopy(ORD_FORM)
            ord_dict['MSG_SEQ_NO'].append(seq_num)
            ord_dict['ISIN_CODE'].append(order["code"])
            ord_dict['ORD_TP'].append("1")
            ord_dict['ORD_VOL'].append("{0:010d}".format(order["bid"][1]))
            ord_dict['ORD_PRC'].append("{0:011d}".format(order["bid"][0]))
            temp_ord = pd.DataFrame.from_dict(ord_dict)
            del ord_dict

            self.db_engine.sql_push(temp_ord, table)
            self._send_to_socket(Stg.DB_INSERTED_MSG)
            self.logger.debug(temp_ord)
        elif order['ask'] is not None:
            # 매도 주문 진행
            ord_dict = copy.deepcopy(ORD_FORM)
            ord_dict['MSG_SEQ_NO'].append(seq_num)
            ord_dict['ISIN_CODE'].append(order["code"])
            ord_dict['ORD_TP'].append("2")
            ord_dict['ORD_VOL'].append("{0:010d}".format(order["ask"][1]))
            ord_dict['ORD_PRC'].append("{0:011d}".format(order["ask"][0]))
            temp_ord = pd.DataFrame.from_dict(ord_dict)
            del ord_dict

            self.db_engine.sql_push(temp_ord, table)
            self._send_to_socket(Stg.DB_INSERTED_MSG)
            self.logger.debug(temp_ord)

    def _manage_mode(self, stg_id, code, get_que, put_que):
        stg_ = StrategyLists()
        stg_mnt = stg_.POOL[stg_id]
        stg_cur = stg_mnt(put_que, code, self.deps_per_st, self.db_engine)

        while True:
            data = get_que.get()

            # if code not in data.keys():
            #     print("Assigned Wrong Data : you have to assign thd data of {}. but, now assigned {}"
            #           .format(code, list(data.keys())[0]))
            #     continue

            # Main
            stg_cur.judge_trade(data)

            del data

    def run(self):
        # Thread 초기화
        thd = {}

        st_get_que = {}
        st_put_que = {}

        ord_seq = 0

        for code in self.stock_code:
            st_get_que[code] = Queue()  # 각 종목별 Data 전달해 주는 Queue
            st_put_que[code] = Queue()  # 각 종목별 Order를 수집하는 Queue

            thd[code] = Thread(target=self._manage_mode,
                               args=(self.strategy_id, code, st_get_que[code], st_put_que[code],))
            thd[code].setDaemon(True)
            thd[code].start()

        while True:
            data = self.data_que.get()  # Trade manager 로부터 Data 입력받음

            if data is None:
                break

            for code, val in data.items():
                if val is not None:
                    st_get_que[code].put(val)  # 각 Stategy Thread로 Data 전달
                del data

            for code in self.stock_code:
                order_cmd = st_put_que[code].get()

                if order_cmd is not None:
                    # self._push_ord_to_sql(ord_seq, order_cmd)
                    print("cmd!!")

            ord_seq += 1

            if ord_seq > 1000:
                ord_seq = 0

        for code in self.stock_code:
            thd[code].join()

    def _send_to_socket(self, data: bytes):
        """
        소켓으로 데이터 전송
        :param data: 전송할 데이터 (bytes)
        :return: None
        """
        self._socket_obj.sendall(data)
