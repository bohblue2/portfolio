import time
from datetime import datetime


class TimeConv:
    MILISECONDS = 1000
    MSCONST = 1000000000

    def __init__(self, timestamp):
        self.timestamp = timestamp
        self.current_time = time.time()

    # timestamp를 'yyyy-mm-dd HH:MM:SS.ff' 형태로 변환
    def get_time(self, timestamp):
        if timestamp // self.MSCONST == 1.0:
            div = 1
        else:
            div = self.MILISECONDS
        return datetime.fromtimestamp(timestamp/div).strftime('%Y-%m-%d %H:%M:%S.%f')

    # delta 일수를 ms단위로 변환
    def get_day_micro_sec(self, delta=1):
        return (3600 * 24 * self.MILISECONDS) * delta

    # 현재 시간의 timstamp를 ms단위로 변환
    def get_today_micro_sec(self):
        return int(time.time() * self.MILISECONDS)

    # Timetuple을 timestamp로 변환
    # Timestring : "2018-01-27 23:59:59"
    def get_time_stamp(self, timestring):
        return time.mktime(time.strptime(timestring, "%Y-%m-%d %H:%M:%S"))

    # Ex :
    # end = datetime.now()
    # time.mktime(end.timetuple())
    def get_time_stamp_from_tuple(self, time_tuple):
        return time.mktime(time_tuple.timetuple())

    def int2datetime(self, intmstime):
        ret = datetime.fromtimestamp(intmstime/1000)
        return ret

    def datetime2str(self, dt):
        return dt.strftime("%Y-%m-%d %H:%M:%S")

