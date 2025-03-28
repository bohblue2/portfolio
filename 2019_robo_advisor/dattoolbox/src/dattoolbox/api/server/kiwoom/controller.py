##################################################
# Author: hansang.cho
# Copyright: Copyright 2019, hansang.cho
# Version: 1.0.0
# Mmaintainer: hansang.cho
# Email: hehpollon@gmail.com
# Status: complete
##################################################

from abc import (
    ABCMeta,
    abstractmethod,
    abstractclassmethod,
    abstractstaticmethod
)
import sys
import asyncio
import multiprocessing
from typing import Union

from PyQt5.QtWidgets import *
from .mng import KiwoomWindow

class IController():
    __metaclass__ = ABCMeta

    @abstractmethod
    def get_message(self) -> Union[str, dict]:
        raise NotImplementedError

    @abstractmethod
    def get_broadcast(self) -> Union[str, dict]:
        raise NotImplementedError

    @abstractmethod
    def run_command(self, command: str):
        raise NotImplementedError


class Controller(IController):
    def __init__(self):
        self.input_queue = None
        self.output_queue = None
        self.broadcast_queue = None
        self.pool = None

    def get_message(self) -> Union[str, dict]:
        try:
            result = self.output_queue.get(timeout=15)
        except:
            result = -1
        return result

    async def get_broadcast(self) -> Union[str, dict]:
        while not self.broadcast_queue:
            await asyncio.sleep(0.5)
        try:
            result = self.broadcast_queue.get(block=False)
        except:
            return ""
        return result

    def run_command(self, command: str):
        if not self.input_queue:
            self.run_pool()
        else:
            self.input_queue.put("status")
            if self.get_message() is not 1:
                print("terminate pool")
                self.pool.terminate()
                self.run_pool()
        self.input_queue.put(command)

    @staticmethod
    def _run(arg):
        input_queue, output_queue, broadcast_queue = arg
        app = QApplication(sys.argv)
        xwindow = KiwoomWindow(input_queue, output_queue, broadcast_queue)
        xwindow.show()
        output_queue.put(1)
        app.exec_()

    def run_pool(self):
        m = multiprocessing.Manager()
        self.input_queue = m.Queue()
        self.output_queue = m.Queue()
        self.broadcast_queue = m.Queue()
        self.pool = multiprocessing.Pool()
        self.pool.map_async(
            Controller._run,
            [(self.input_queue, self.output_queue, self.broadcast_queue)]
        )
        try:
            result = self.output_queue.get(timeout=30)
        except Exception as e:
            return -1
        return result

    def run_single(self):
        app = QApplication(sys.argv)
        xwindow = KiwoomWindow(None, None, None)
        xwindow.show()
        app.exec_()


if __name__ == "__main__":
    app = QApplication(sys.argv)
    xwindow = KiwoomWindow(None, None, None)
    xwindow.show()
    app.exec_()
