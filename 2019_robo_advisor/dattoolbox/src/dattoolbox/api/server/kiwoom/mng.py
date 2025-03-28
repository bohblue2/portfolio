##################################################
# Author: hansang.cho
# Copyright: Copyright 2019, hansang.cho
# Version: 1.0.0
# Mmaintainer: hansang.cho
# Email: hehpollon@gmail.com
# Status: developing
##################################################

import os
import sys
import threading

from PyQt5 import uic
from PyQt5.QtWidgets import *

from .connector import Kiwoom

ui_path = os.path.dirname(os.path.abspath(__file__))
form_class = uic.loadUiType(os.path.join(ui_path, "mng.ui"))[0]

# kiwoom_instance
class KiwoomWindow(QMainWindow, form_class):
    def __init__(self, input_queue, output_queue, broadcast_queue):
        super().__init__()
        self.setupUi(self)
        self.input_queue = input_queue
        self.output_queue = output_queue
        self.broadcast_queue = broadcast_queue

        self.trade_stocks_done = False

        self.kiwoom = Kiwoom(output_queue, broadcast_queue)
        self.kiwoom.comm_connect()

        # self.pushButton.clicked.connect(self.send_order)
        thread = threading.Thread(target=self.get_command)
        thread.start()

    def get_command(self):

        while True:
            result = ""
            try:
                input_data = self.input_queue.get()
                if isinstance(input_data, str):
                    input_data = input_data.strip()
                raw_command_list = input_data.split(" ")
                data = ["user command", raw_command_list]
                print(data)
                command = raw_command_list[0]
            except EOFError:
                break
            try:
                if command == "status":
                    result = self.get_kiwoom_status()
                elif command == "all_account_num":
                    result = self.kiwoom.get_all_account_num()
                elif command == "user_info":
                    result = self.kiwoom.get_user_info()
                elif command == "check_balance":
                    result = self.kiwoom.check_balance()
                elif command == "trade_stock":
                    assert len(raw_command_list) >= 6, "Not enough parameter"
                    result = self.kiwoom.trade_stocks(* raw_command_list[1:])
                elif command == "get_remain_stock":
                    result = self.kiwoom.get_remain_stock()
                elif command == "set_cur_account":
                    if len(raw_command_list) > 1:
                        result = self.kiwoom.set_cur_account(raw_command_list[1])
                elif command == "check_deposit":
                    result = self.kiwoom.check_deposit()
                elif command == "server_gubun":
                    result = self.kiwoom.get_server_gubun()
                elif command == "get_current_price":
                    result = self.kiwoom.get_current_price(raw_command_list[1])
                self.output_queue.put(result)
            except Exception as e:
                self.output_queue.put(str(e))

    def get_kiwoom_status(self):
        if self.kiwoom:
            return self.kiwoom.get_connect_state()
        else:
            return -1


if __name__ == "__main__":
    app = QApplication(sys.argv)
    xwindow = KiwoomWindow(None, None, None)
    xwindow.show()
    app.exec_()