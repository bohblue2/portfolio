# -*- coding: utf-8 -*-


class KeyName:
	MSG = "msg"
	DATA = "data"
	REQ_CMD = "req_cmd"
	SINGLE = "single"
	MULTI = "multi"


class EventType:
	REQ_TO_SOCKET = 0

	WRITE_DAILY_CANDLE = 1
	WRITE_DAILY_TREND = 2
	WRITE_MASTER = 3

	REQ_READ_MASTER = 4
	RCV_READ_MASTER = 5

	REQ_READ_HOLIDAY = 6
	RCV_READ_HOLIDAY = 7

	REQ_READ_SPC_TRD_TIME = 8
	RCV_READ_SPC_TRD_TIME = 9

	TERMINATE_THREAD = 100
	SEND_MSG_TO_TELEGRAM = 101
	REQ_READ_RESULT = 102
	RCV_READ_RESULT = 103


class EventBase:
	event_type = 0


class ReqToSocketEvt(EventBase):
	event_type = EventType.REQ_TO_SOCKET
	command: str = None


class WriteDailyCandleEvt(EventBase):
	event_type = EventType.WRITE_DAILY_CANDLE
	data = []


class WriteDailyTrendEvt(EventBase):
	event_type = EventType.WRITE_DAILY_TREND
	data = []


class WriteMasterEvt(EventBase):
	event_type = EventType.WRITE_MASTER
	data = []


class ReqReadHolidayEvt(EventBase):
	event_type = EventType.REQ_READ_HOLIDAY
	st_date: str = None
	ed_date: str = None


class RcvReadHolidayEvt(EventBase):
	event_type = EventType.RCV_READ_HOLIDAY
	data = []


class ReqReadSpcTrdTrimeEvt(EventBase):
	event_type = EventType.REQ_READ_SPC_TRD_TIME
	st_date: str = None
	ed_date: str = None


class RcvReadSpcTrdTrimeEvt(EventBase):
	event_type = EventType.RCV_READ_SPC_TRD_TIME
	data = []


class TerminateTrdEvt(EventBase):
	event_type = EventType.TERMINATE_THREAD


class SendMsgToTelegram(EventBase):
	event_type = EventType.SEND_MSG_TO_TELEGRAM
	msg: str = None


class ReqReadResult(EventBase):
	event_type = EventType.REQ_READ_RESULT


class RcvReadResult(EventBase):
	event_type = EventType.RCV_READ_RESULT
	data = {}


class MarketType:
	KOSPI = "0"
	ELW = "3"
	ETF = "8"
	KOSDAQ = "10"


class COMMAND:
	GET_CODE_LIST = "get_code_list"
	GET_MASTER = "get_master"
	GET_STOCK_DAILY_CHART = "get_stock_daily_chart"
	GET_STOCK_DAILY_TREND = "get_stock_daily_trend"
	GET_STOCK_MIN_CHART = "get_stock_min_chart"
	GET_MULTI_ITEMS = "get_multi_items"
