# -*- coding: utf-8 -*-
import logging
import logging.config
import json
import time
import argparse

from datetime import datetime, timedelta
from configparser import ConfigParser
from queue import Queue
from string_def import *
from strategy_manager import *
from universe_manager import *
from util.utilities_logic import SqlUtil


def set_init_stocks(db_engine):
    um = UniverseManger()
    ed_date = datetime.fromtimestamp(time.time()) - timedelta(1)
    st_date = ed_date - timedelta(2)

    ed_date = ed_date.strftime("%Y-%m-%d")
    st_date = st_date.strftime("%Y-%m-%d")

    table = "K200_FUT_LIMIT_ORD"
    column = "ISIN_CODE, TOTAL_L_LIMIT_ORD_Q, L_LVL_1_SIGN, L_LVL_1_PRC, L_LVL_1_Q, L_LVL_2_SIGN, L_LVL_2_PRC, \
              L_LVL_2_Q, L_LVL_3_SIGN, L_LVL_3_PRC, L_LVL_3_Q, L_LVL_4_SIGN, L_LVL_4_PRC, L_LVL_4_Q, L_LVL_5_SIGN, \
              L_LVL_5_PRC, L_LVL_5_Q, TOTAL_S_LIMIT_ORD_Q, S_LVL_1_SIGN, S_LVL_1_PRC, S_LVL_1_Q, S_LVL_2_SIGN, \
              S_LVL_2_PRC, S_LVL_2_Q, S_LVL_3_SIGN, S_LVL_3_PRC, S_LVL_3_Q, S_LVL_4_SIGN, S_LVL_4_PRC, S_LVL_4_Q, \
              S_LVL_5_SIGN, S_LVL_5_PRC, S_LVL_5_Q, TOTAL_L_TRD_CNT, L_LVL_1_TRD_CNT, L_LVL_2_TRD_CNT, \
              L_LVL_3_TRD_CNT, L_LVL_4_TRD_CNT, L_LVL_5_TRD_CNT, TOTAL_S_TRD_CNT, S_LVL_1_TRD_CNT, S_LVL_2_TRD_CNT, \
              S_LVL_3_TRD_CNT, S_LVL_4_TRD_CNT, S_LVL_5_TRD_CNT, ORD_RCV_T, PK_RTIME, RTIME"
    condition = "'{0}' <= RTIME AND RTIME <= '{1}'".format(st_date, ed_date)

    db_data = db_engine.sql_read_column(table, condition, column)
    stcodes = um.select_monitored_subjects(db_data)

    return stcodes


def get_stk_fut_list(db_engine, is_daily=True):
    today_date = datetime.now().strftime("%Y%m%d")
    today_date = "20190719"
    table = "STOCK_FUT_PRD_INFO_DATA" if is_daily else "MSTOCK_FUT_PRD_INFO_DATA"
    column = "ISIN_CODE, SH_PRD_CODE, PRD_NAME_KOR, MATURITY_DATE, EXE_PRC, PRD_UNIT, MULTIPLIER, STD_THEORY_PRC, " \
             "YEST_SETT_PRC, YEST_INIT_PRC, YEST_HIGH_PRIC, YEST_LOW_PRC, YEST_CLOSE_PRC, \
              YEST_EXE_TRD_CNT, YEST_EXE_Q, YEST_TRD_AMT"
    condition = "YMD = '{0}' ORDER BY seq".format(today_date)

    db_data = db_engine.sql_read_column(table, condition, column)

    return db_data


def get_data_today(db_engine, code="KR4111P70002", limits=None):
    table = "MMSTOCK_FUT_EXEC_LIMIT_ORD"
    column = 'CUR_PRC, EXE_Q, EXE_T, TOTAL_L_LIMIT_ORD_Q, L_LVL_1_PRC, L_LVL_1_Q, L_LVL_2_PRC, L_LVL_2_Q, \
             L_LVL_3_PRC, L_LVL_3_Q, L_LVL_4_PRC, L_LVL_4_Q, L_LVL_5_PRC, L_LVL_5_Q, TOTAL_S_LIMIT_ORD_Q, \
             S_LVL_1_PRC, S_LVL_1_Q, S_LVL_2_PRC, S_LVL_2_Q, S_LVL_3_PRC, S_LVL_3_Q, S_LVL_4_PRC, S_LVL_4_Q, \
             S_LVL_5_PRC, S_LVL_5_Q, TOTAL_L_TRD_CNT, L_LVL_1_TRD_CNT, L_LVL_2_TRD_CNT, L_LVL_3_TRD_CNT, \
             L_LVL_4_TRD_CNT, L_LVL_5_TRD_CNT, TOTAL_S_TRD_CNT, S_LVL_1_TRD_CNT, S_LVL_2_TRD_CNT, S_LVL_3_TRD_CNT, \
             S_LVL_4_TRD_CNT, S_LVL_5_TRD_CNT, SEQ'

    if limits is not None:
        condition = "ISIN_CODE = '{0}' ORDER BY seq DESC LIMIT {1}".format(code, limits)
    else:
        condition = "ISIN_CODE = '{0}' ORDER BY seq".format(code)

    db_data = db_engine.sql_read_column(table, condition, column)

    return db_data


def get_deps(db_engine):
    return 10000000


def main(args):
    with open("setting/logging.json", 'rt') as f:
        log_config = json.load(f)
    logging.config.dictConfig(log_config)

    config = ConfigParser()
    config.read('setting/init.ini')
    server = config["server"]

    db_info = {
        DataBase.USR: server["USR"],
        DataBase.PWD: server["PW"],
        DataBase.URL: server["URL"],
        DataBase.PORT: int(server["PORT"]),
        DataBase.DB: server["DB"]
    }

    db_engine = SqlUtil(**db_info)
    # data_que = Queue()
    deps = get_deps(db_engine)
    # stcodes = set_init_stocks(db_engine)

    if args.is_sql:
        st_info = get_stk_fut_list(db_engine)
        st_codes = [code for code, name in st_info[["ISIN_CODE", "PRD_NAME_KOR"]].values
                   if name.split(" ")[0] in ["SK하이닉스", "삼성전자", "현대자동차"]]
    else:
        deps = 100000000
        st_codes = ['KR4111P70002', 'KR4111P80001', 'KR4411P7P8S1', 'KR4150P70000', 'KR4150P80009', 'KR4450P7P8S9']

    db_data = dict()
    if args.is_sql:
        code = st_codes[0]
        if not args.is_run:
            db_data[code] = get_data_today(db_engine, code)
    else:
        code = st_codes[0]
        db_data[code] = pd.read_hdf("data/stk_fut_data.h5", code)

    stg_info = {
        StgInfo.ID: "stg000",
        # StgInfo.MNT_STKS: st_codes,
        StgInfo.MNT_STKS: [code],
        StgInfo.TOT_DEPS: deps
    }

    que = {
        QueStr.DATA: Queue(),
        QueStr.ORDER: Queue(),
        QueStr.STG: Queue()
    }

    # data_obj = TickData(que)
    # stg_obj = Stg(que, db_engine, **stg_info)
    stg_obj = Stg(que, db_engine, **stg_info)
    # order_obj = ...
    # data_obj.setDaemon(True)
    stg_obj.setDaemon(True)
    # order_obj.setDaemon(True)

    # data_obj.start()
    stg_obj.start()
    # order_obj.start()

    data = dict()
    data_cnt = 1000000

    if args.is_run:
        prev_seq = 0
        while args.is_run:
            data[code] = get_data_today(db_engine, code, limits=1)
            cur_seq = data[code]["SEQ"].iloc[0]

            if prev_seq == cur_seq:
                time.sleep(0.001)
                continue
            elif prev_seq > cur_seq:
                print("Wrong Sequence!")
                break

            que[QueStr.STG].put(data)
            prev_seq = cur_seq
    else:
        for k in db_data.keys():
            if not db_data[k].empty:
                data_cnt = min(data_cnt, db_data[k].shape[0])

        for v in db_data[code].values:
            data[code] = pd.DataFrame(v.reshape([1, v.size]), columns=db_data[code].columns)
            que[QueStr.STG].put(data)
            time.sleep(0.01)

        logging.info("Trading is completed!")

    # order_obj.join()
    stg_obj.join()
    # data_obj.join()


if __name__ == "__main__":
    parser = argparse.ArgumentParser("hft_system_v1.0")
    parser.add_argument("-s", "--is_sql", default=True, type=bool, help="use the data from sql db")
    parser.add_argument("-r", "--is_run", default=False, type=bool, help="simulate or run real trading")
    args = parser.parse_args()

    main(args)

