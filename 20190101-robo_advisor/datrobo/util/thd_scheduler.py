# -*- codings : utf-8 -*-
import threading
from apscheduler.schedulers.blocking import BlockingScheduler
import pytz


class ThdScheduler:
	def __init__(self):
		self.scheds = []
		self._lock = threading.Lock()

	def __del__(self):
		self.remove_all_jobs()

	def _job_func(self, hour, minute, second, func, args):
		sched = BlockingScheduler(timezone=pytz.timezone("Asia/Seoul"))
		ret = sched.add_job(func, "cron", hour=hour, minute=minute, second=second, args=args)

		self._lock.acquire()
		print(ret, "args:", args)
		self.scheds.append(sched)
		self._lock.release()

		sched.start()

	def add_new_cron_job(self, hour, minute, second, func, args=()):
		"""
		cron_job 추가

		:param hour: 시간
		:param minute: 분
		:param second: 초
		:param func: 실행할 함수
		:param args: 함수의 인자
		"""
		thd = threading.Thread(target=self._job_func, args=(hour, minute, second, func, args, ))
		thd.start()

	def remove_all_jobs(self):
		"""
		모든 Job제거
		"""
		for sched in self.scheds:
			sched.shutdown(wait=False)

		self.scheds = []
