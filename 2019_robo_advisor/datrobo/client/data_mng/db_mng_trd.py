# -*- coding: utf-8 -*-
import threading
from datrobo.client.common.database import Database
from datrobo.client.data_mng.data_mng_def import *
from loguru import logger


class DbMngThd(threading.Thread):
	def __init__(self, config_file_path, data_mng_queue, db_mng_queue):
		threading.Thread.__init__(self)

		logger.info("Thread Start")

		self.config_file_path = config_file_path
		self._db_mng_queue = db_mng_queue
		self._data_mng_queue = data_mng_queue

	def __del__(self):
		logger.info("Thread Finished")

	@classmethod
	def _write_daily_candle(cls, db_obj: Database, evt: WriteDailyCandleEvt) -> None:
		db_obj.insert_daily_candle(evt.data)

	@classmethod
	def _write_daily_trend(cls, db_obj: Database, evt: WriteDailyTrendEvt) -> None:
		db_obj.insert_daily_trend(evt.data)

	@classmethod
	def _write_master(cls, db_obj: Database, evt: WriteMasterEvt) -> None:
		db_obj.insert_code_master(evt.data)

	def _req_read_holiday(self, db_obj: Database, req_evt: ReqReadHolidayEvt) -> None:
		rcv_evt = RcvReadHolidayEvt()
		rcv_evt.data = db_obj.select_holiday_tables(req_evt.st_date, req_evt.ed_date)
		self._data_mng_queue.put(rcv_evt)

	def _req_read_spc_trd_time(self, db_obj: Database, req_evt: ReqReadSpcTrdTrimeEvt) -> None:
		rcv_evt = RcvReadSpcTrdTrimeEvt()
		rcv_evt.data = db_obj.select_spc_trd_times(req_evt.st_date, req_evt.ed_date)
		self._data_mng_queue.put(rcv_evt)

	def _req_read_result(self, db_obj: Database):
		rcv_evt = RcvReadResult()
		rcv_evt.data = db_obj.get_data_rcv_result()
		self._data_mng_queue.put(rcv_evt)

	def run(self) -> None:
		with Database(self.config_file_path) as db_obj:
			while True:
				try:
					rcv_evt = self._db_mng_queue.get()
					evt_type = rcv_evt.event_type

					if EventType.WRITE_DAILY_CANDLE == evt_type:
						self._write_daily_candle(db_obj, rcv_evt)

					elif EventType.WRITE_DAILY_TREND == evt_type:
						self._write_daily_trend(db_obj, rcv_evt)

					elif EventType.WRITE_MASTER == evt_type:
						self._write_master(db_obj, rcv_evt)

					elif EventType.REQ_READ_HOLIDAY == evt_type:
						self._req_read_holiday(db_obj, rcv_evt)

					elif EventType.REQ_READ_SPC_TRD_TIME == evt_type:
						self._req_read_spc_trd_time(db_obj, rcv_evt)

					elif EventType.REQ_READ_RESULT == evt_type:
						self._req_read_result(db_obj)

					elif EventType.TERMINATE_THREAD == evt_type:
						break

				except Exception as e:
					err_msg = "[DbMngThd::run] Exception 발생 (사유: {0})".format(str(e))
					logger.exception(err_msg)

					evt = SendMsgToTelegram()
					evt.msg = err_msg
					self._data_mng_queue.put(evt)
