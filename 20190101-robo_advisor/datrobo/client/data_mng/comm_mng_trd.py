# -*- coding: utf-8 -*-
import threading
import websocket
import time
from datrobo.client.data_mng.data_mng_def import *
from loguru import logger


def on_open(ws):
	logger.info("WebSocket 서버와 연결됨")


def on_message(ws, msg):
	ws.data_mng_queue.put(msg)


def on_error(ws, msg):
	new_msg = "[comm_mng_trd::on_error] WebSocket Error: {0}".format(msg)

	logger.error(new_msg)

	evt = SendMsgToTelegram()
	evt.msg = new_msg

	ws.data_mng_queue.put(evt)


def on_close(ws):
	logger.info("WebSocket 서버와 연결종료")


class CommMngThd(threading.Thread):
	URL = "ws://localhost:8765"
	CONN_TIMEOUT_SEC = 60
	RE_CONN_SEC = 5

	def __init__(self, data_mng_queue, comm_mng_queue):
		threading.Thread.__init__(self)

		logger.info("Thread Start")

		self._comm_mng_queue = comm_mng_queue
		self._data_mng_queue = data_mng_queue
		self._ws = None

	def __del__(self):
		if self._ws is not None:
			self._ws.close()
			self._ws = None

		logger.info("Thread Finished")

	def run(self) -> None:
		websocket.enableTrace(False)
		self._ws = websocket.WebSocketApp(self.URL, on_open=on_open, on_message=on_message, on_error=on_error, on_close=on_close)
		self._ws.data_mng_queue = self._data_mng_queue
		ws_trd = threading.Thread(target=self._ws.run_forever)
		ws_trd.start()

		conn_timeout = self.CONN_TIMEOUT_SEC
		while self._ws.sock is not None and not self._ws.sock.connected and conn_timeout:
			time.sleep(self.RE_CONN_SEC)
			conn_timeout -= self.RE_CONN_SEC

		time.sleep(10)

		while self._ws.sock is not None and self._ws.sock.connected:
			try:
				rcv_evt = self._comm_mng_queue.get()
				evt_type = rcv_evt.event_type

				if EventType.REQ_TO_SOCKET == evt_type:
					self._ws.send(rcv_evt.command)

				elif EventType.TERMINATE_THREAD == evt_type:
					break

			except Exception as e:
				continue

		self._ws.close()
		self._ws = None

		ws_trd.join()
