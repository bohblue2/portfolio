# -*- coding: utf-8 -*-
import queue
from loguru import logger

from datrobo.client.data_mng.data_mng_trd import DataMngThd
from datrobo.client.data_mng.comm_mng_trd import CommMngThd
from datrobo.client.data_mng.db_mng_trd import DbMngThd
from global_value import CONFIG_FILE_PATH


RCV_DAY_CNT = 1  # 몇일치를 받을것이가


def rcv_main():
	logger.add("log/{time:YYYYMMDD}_rcv_data.log", encoding="utf-8")

	logger.info("데이터 수신 시작 !!")

	db_mng_queue = queue.Queue()
	comm_mng_queue = queue.Queue()
	data_mng_queue = queue.Queue()

	data_mng_trd = DataMngThd(CONFIG_FILE_PATH, data_mng_queue, comm_mng_queue, db_mng_queue, RCV_DAY_CNT)
	data_mng_trd.start()

	db_mng_thd = DbMngThd(CONFIG_FILE_PATH, data_mng_queue, db_mng_queue)
	db_mng_thd.start()

	comm_mng_thd = CommMngThd(data_mng_queue, comm_mng_queue)
	comm_mng_thd.start()

	data_mng_trd.join()
	db_mng_thd.join()
	comm_mng_thd.join()

	logger.info("데이터 수신 종료 !!")


if "__main__" == __name__:
	rcv_main()
