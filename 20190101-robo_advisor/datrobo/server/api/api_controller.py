##################################################
# Author: hansang.cho
# Copyright: Copyright 2019, hansang.cho
# Version: 1.0.0
# Mmaintainer: hansang.cho
# Email: hehpollon@gmail.com
# Status: developing
##################################################

from typing import Union
import multiprocessing
import asyncio
from PyQt5.QtWidgets import *
from datrobo.server.api.interface import ApiInterface
from datrobo.server.api.kiwoom_window import KiwoomWindow
import sys
# import warnings
# # pywinauto 0.6.4 충돌 => Qt: Could not initialize OLE (error 80010106)
# warnings.simplefilter("ignore", UserWarning)
# sys.coinit_flags = 2

class ApiController(ApiInterface):
    def __init__(self):
        self.input_queue = None
        self.output_queue = None
        self.broadcast_queue = None
        self.run_chk_queue = None
        self.pool = None
        pass

    def get_message(self) -> Union[str, dict]:
        try:
            result = self.output_queue.get(timeout=15)
        except:
            result = {"msg": -1}
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
            rcv = self.get_message()
            if type(rcv) is dict and "msg" in rcv and rcv["msg"] is not 1:
                print("terminate pool")
                self.pool.terminate()
                self.run_pool()
        self.input_queue.put(command)

    @staticmethod
    def _run(arg):
        input_queue, output_queue, broadcast_queue, run_chk_queue = arg
        app = QApplication(sys.argv)
        xwindow = KiwoomWindow(input_queue, output_queue, broadcast_queue)
        xwindow.show()
        run_chk_queue.put(1)
        app.exec_()

    def run_pool(self):
        m = multiprocessing.Manager()
        self.input_queue = m.Queue()
        self.output_queue = m.Queue()
        self.broadcast_queue = m.Queue()
        self.run_chk_queue = m.Queue()
        self.pool = multiprocessing.Pool()
        self.pool.map_async(
            ApiController._run,
            [(self.input_queue, self.output_queue, self.broadcast_queue, self.run_chk_queue)]
        )
        try:
            result = self.run_chk_queue.get(timeout=600)
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
