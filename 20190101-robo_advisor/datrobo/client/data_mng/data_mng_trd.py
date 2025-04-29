# -*- coding: utf-8 -*-
import threading
import time
import json
import datetime
import configparser
from datrobo.client.data_mng.data_mng_def import *
from datrobo.util.telegram_api import Telegram
from loguru import logger


class DataMngThd(threading.Thread):
	DEFAULT_MARKET_END_TIME = 153000

	NOT_USE_ADJ_PRC = "0"
	USE_ADJ_PRC = "1"

	TRD_TYPE_BUY = "1"
	TRD_TYPE_SELL = "2"

	def __init__(self, config_file_path, data_mng_queue, comm_mng_queue, db_mng_queue, rcv_day_cnt=1):
		threading.Thread.__init__(self)

		logger.info("Thread Start")

		self._data_mng_queue = data_mng_queue
		self._comm_mng_queue = comm_mng_queue
		self._db_mng_queue = db_mng_queue
		self._codes = []
		self._ext_time = {}
		self._daily_chart_dict = {}
		self._daily_trend_dict = {}
		self._rcv_day_cnt = rcv_day_cnt

		yesterday = datetime.date.today() - datetime.timedelta(days=1)
		self._std_date = yesterday.strftime("%Y%m%d")

		config = configparser.ConfigParser()
		config.sections()
		config.read(config_file_path)
		self.telegram = Telegram(*[
			config["TELEGRAM"]["token"],
			config["TELEGRAM"]["chat_id"]
		])

		self._last_cmd = ""

	def __del__(self):
		self.telegram.send_message("exit_telegram_thread")
		logger.info("Thread Finished")

	def _send_msg_to_telegram(self, msg):
		cur_time = datetime.datetime.now().strftime("%Y-%m-%d %H:%M:%S")
		send_msg = "[{0}] {1}".format(cur_time, msg)
		self.telegram.send_message(send_msg)

	def _send_cmd_to_server(self, cmd):
		evt = ReqToSocketEvt()
		evt.command = cmd
		self._last_cmd = cmd
		self._comm_mng_queue.put(evt)

	def run(self) -> None:
		# Wating Welcome
		logger.info("WebSocket 서버로부터 Welcome을 기다림")

		while True:
			rcv_evt = self._data_mng_queue.get()
			if "WELCOME" in rcv_evt:
				logger.info("Welcome 수신")
				break

		time.sleep(10)

		logger.info("WebSocket 서버로 Master 요청")
		param = [
			COMMAND.GET_MASTER,
			MarketType.ETF
		]
		self._send_cmd_to_server(" ".join(param))

		while True:
			try:
				rcv = self._data_mng_queue.get()

				if str == type(rcv):
					if 3 > len(rcv):
						continue

					rcv_json = json.loads(rcv)

					if KeyName.DATA in rcv_json and KeyName.MSG in rcv_json[KeyName.DATA]:
						msg = rcv_json[KeyName.DATA][KeyName.MSG]

						# ==================== Error Check ====================
						if int == type(msg) and -1 == msg:
							logger.error("서버로부터 msg: -1을 수신 (req cmd: {0})".format(self._last_cmd))

							# 5분뒤에 다시 요청
							time.sleep(300)
							self._send_cmd_to_server(self._last_cmd)
							continue

						if KeyName.REQ_CMD not in rcv_json[KeyName.DATA]:
							logger.error("알 수 없는 Command 발생")
							self._send_msg_to_telegram("알 수 없는 Command 발생")
							continue

						cmd = rcv_json[KeyName.DATA][KeyName.REQ_CMD].split(" ")
						main_cmd = cmd[0]

						# ==================== Rcv Daily Chart ====================
						if COMMAND.GET_STOCK_DAILY_CHART == main_cmd:
							adj_flag = cmd[3]

							shtcode = msg[KeyName.SINGLE]["종목코드"]
							multi_data = msg[KeyName.MULTI]

							if self.NOT_USE_ADJ_PRC == adj_flag:
								self._daily_chart_dict[shtcode] = {}

								for row in multi_data:
									date = row["일자"]
									self._daily_chart_dict[shtcode][int(date)] = [
										shtcode,
										date,
										row["시가"],
										row["고가"],
										row["저가"],
										row["현재가"],
										"0",
										row["거래량"],
										row["거래대금"],
										"0",
										"0",
									]

								param = [
									COMMAND.GET_STOCK_DAILY_CHART,
									shtcode,
									self._std_date,
									self.USE_ADJ_PRC,
								]
								cmd = " ".join(param)
								self._send_cmd_to_server(cmd)

							elif self.USE_ADJ_PRC == adj_flag:
								for row in multi_data:
									date = int(row["일자"])
									buffer = self._daily_chart_dict[shtcode][date]
									buffer[9] = row["수정주가구분"] if 0 < len(row["수정주가구분"]) else "0"
									buffer[10] = row["수정비율"] if 0 < len(row["수정비율"]) else "0"

								param = [
									COMMAND.GET_STOCK_MIN_CHART,
									shtcode,
									"1",
									self.NOT_USE_ADJ_PRC,
								]
								cmd = " ".join(param)
								self._send_cmd_to_server(cmd)

						# ==================== Rcv Min Chart ====================
						elif COMMAND.GET_STOCK_MIN_CHART == main_cmd:
							shtcode = msg[KeyName.SINGLE]["종목코드"]
							multi_data = msg[KeyName.MULTI]
							min_dict = {}

							for row in multi_data:
								buffer = row["체결시간"]
								trd_date = int(buffer[:8])
								trd_time = int(buffer[8:14])

								if trd_date in self._ext_time and self._ext_time[trd_date][1] <= trd_time:
									continue
								elif self.DEFAULT_MARKET_END_TIME <= trd_time:
									continue

								if trd_date not in min_dict:
									min_dict[trd_date] = {}

								min_dict[trd_date][trd_time] = str(abs(int(row["현재가"])))

							for trd_date, trd_times in min_dict.items():
								if 0 < len(trd_times) and shtcode in self._daily_chart_dict and trd_date in self._daily_chart_dict[shtcode]:
									self._daily_chart_dict[shtcode][trd_date][6] = trd_times[max(trd_times)]

							datas = []
							for _, data in self._daily_chart_dict[shtcode].items():
								datas.append(data)

							sorted(datas, key=lambda buf: buf[1])

							evt = WriteDailyCandleEvt()
							evt.data = datas[:self._rcv_day_cnt]
							self._db_mng_queue.put(evt)

							param = [
								COMMAND.GET_STOCK_DAILY_TREND,
								self._std_date,
								shtcode,
								"2",
								self.TRD_TYPE_BUY,
								"1",
								self.NOT_USE_ADJ_PRC,
							]
							cmd = " ".join(param)
							self._send_cmd_to_server(cmd)

						# ==================== Rcv Daily Trend ====================
						elif COMMAND.GET_STOCK_DAILY_TREND == main_cmd:
							shtcode = cmd[2]
							trd_type = cmd[4]
							multi_data = msg[KeyName.MULTI]

							if self.TRD_TYPE_BUY == trd_type:
								self._daily_trend_dict[shtcode] = {}

								for row in multi_data:
									date = row["일자"]
									self._daily_trend_dict[shtcode][int(date)] = [
										shtcode,
										date,
										row["개인투자자"],
										"NULL",
										row["기관계"],
										"NULL",
										row["외국인투자자"],
										"NULL",
										row["투신"],
										"NULL",
										row["연기금등"],
										"NULL",
									]

								param = [
									COMMAND.GET_STOCK_DAILY_TREND,
									self._std_date,
									shtcode,
									"2",
									self.TRD_TYPE_SELL,
									"1",
									self.NOT_USE_ADJ_PRC,
								]
								cmd = " ".join(param)
								self._send_cmd_to_server(cmd)

							elif self.TRD_TYPE_SELL == trd_type:
								for row in multi_data:
									date = int(row["일자"])
									buffer = self._daily_trend_dict[shtcode][date]
									buffer[3] = str(abs(int(row["개인투자자"])))
									buffer[5] = str(abs(int(row["기관계"])))
									buffer[7] = str(abs(int(row["외국인투자자"])))
									buffer[9] = str(abs(int(row["투신"])))
									buffer[11] = str(abs(int(row["연기금등"])))

								datas = []
								for _, data in self._daily_trend_dict[shtcode].items():
									datas.append(data)

								sorted(datas, key=lambda buf: buf[1])

								evt = WriteDailyTrendEvt()
								evt.data = datas[:self._rcv_day_cnt]
								self._db_mng_queue.put(evt)

								i = self._codes.index(shtcode) + 1

								logger.info("[{0}] 수신완료 ({1}/{2})".format(
									shtcode,
									i,
									len(self._codes)
								))

								if len(self._codes) > i:
									time.sleep(18)

									param = [
										COMMAND.GET_STOCK_DAILY_CHART,
										self._codes[i],
										self._std_date,
										"0",
									]
									cmd = " ".join(param)
									self._send_cmd_to_server(cmd)

								else:
									evt = ReqReadResult()
									self._db_mng_queue.put(evt)

						# ==================== Rcv Code List ====================
						elif COMMAND.GET_CODE_LIST == main_cmd:
							pass

						# ==================== Rcv Master ====================
						elif COMMAND.GET_MASTER == main_cmd:
							logger.info("종목 마스터 수신")

							datas = []
							self._codes.clear()

							for shtcode, data in msg.items():
								self._codes.append(shtcode)
								datas.append((
									shtcode,
									data["종목명"],
									data["상장일"],
								))

							self._codes.sort()

							evt = WriteMasterEvt()
							evt.data = datas
							self._db_mng_queue.put(evt)

							evt = ReqReadSpcTrdTrimeEvt()
							self._db_mng_queue.put(evt)

				# ==================== Rcv Special Trade Time ====================
				elif RcvReadSpcTrdTrimeEvt == type(rcv):
					logger.info("특별한 장 종료시간을 불러옴")

					for row in rcv.data:
						self._ext_time[int(row[0])] = (
							int(row[1]),
							int(row[2]),
						)

					time.sleep(20)

					param = [
						COMMAND.GET_STOCK_DAILY_CHART,
						self._codes[0],
						self._std_date,
						"0",
					]
					cmd = " ".join(param)
					self._send_cmd_to_server(cmd)

				# ==================== Send Msg To Telegram ====================
				elif SendMsgToTelegram == type(rcv):
					self._send_msg_to_telegram(rcv.msg)

				# ==================== Read Rcv Data Result ====================
				elif RcvReadResult == type(rcv):
					data = rcv.data

					if "master_cnt" in data and "daily_chart_cnt" in data and "daily_trend_cnt" in data:
						msg = "\nDaily Data 수신 완료\n\n종목마스터: {0}종목\n일봉차트: {1}종목\n투자자별 동향: {2}종목".format(
							data["master_cnt"], data["daily_chart_cnt"], data["daily_trend_cnt"]
						)

						if "daily_chart_ext" in data and 0 < len(data["daily_chart_ext"]):
							msg = msg + "\n\n====================\n일봉차트 중 수신 안된 종목\n"

							for row in data["daily_chart_ext"]:
								msg = msg + "\n코드: {0}, 종목명: {1}".format(row["shtcode"], row["item_name"])

						if "daily_trend_ext" in data and 0 < len(data["daily_trend_ext"]):
							msg = msg + "\n\n====================\n투자자별 동향 중 수신 안된 종목\n"

							for row in data["daily_trend_ext"]:
								msg = msg + "\n코드: {0}, 종목명: {1}".format(row["shtcode"], row["item_name"])

						if "new_listing" in data and 0 < len(data["new_listing"]):
							msg = msg + "\n\n====================\n신규상장\n"

							for row in data["new_listing"]:
								msg = msg + "\n코드: {0}, 종목명: {1}".format(row["shtcode"], row["item_name"])

						logger.info(msg)

						self._send_msg_to_telegram(msg)
					else:
						self._send_msg_to_telegram("Daily Data 수신 완료")

					time.sleep(10)

					evt = TerminateTrdEvt()
					self._db_mng_queue.put(evt)

					evt = TerminateTrdEvt()
					self._comm_mng_queue.put(evt)
					break

			except Exception as e:
				err_msg = "[DataMngThd::run] Exception 발생 (사유: {0})".format(str(e))
				logger.exception(err_msg)
				self._send_msg_to_telegram(err_msg)
