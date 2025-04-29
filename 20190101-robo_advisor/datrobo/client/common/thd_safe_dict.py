# -*- coding: utf-8 -*-
import threading


class ThreadSafeDict(dict):
	def __init__(self, *args, **kwargs):
		dict.__init__(self, *args, **kwargs)
		self._lock = threading.Lock()

	def __enter__(self):
		self._lock.acquire()
		return self

	def __exit__(self, exc_type, exc_val, exc_tb):
		self._lock.release()
