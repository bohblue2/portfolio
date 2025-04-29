##################################################
# Author: hansang.cho
# Copyright: Copyright 2019, hansang.cho
# Version: 1.0.0
# Mmaintainer: hansang.cho
# Email: hehpollon@gmail.com
# Status: developing
##################################################

from PyQt5 import uic
from PyQt5.QtWidgets import *
import sys
from datrobo.server.api.kiwoom_api import Kiwoom
import threading


class KiwoomWindow(QMainWindow):
    def __init__(self, input_queue, output_queue, broadcast_queue):
        super().__init__()
        self.input_queue = input_queue
        self.output_queue = output_queue
        self.broadcast_queue = broadcast_queue

        self.setWindowTitle("Server")

        self.trade_stocks_done = False

        self.kiwoom = Kiwoom(output_queue, broadcast_queue)
        self.kiwoom.comm_connect()

        thread = threading.Thread(target=self.get_command)
        thread.start()

    def get_command(self):

        while True:
            msg = ""
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
                    msg = self.get_kiwoom_status()
                elif command == "all_account_num":
                    msg = self.kiwoom.get_all_account_num()
                elif command == "user_info":
                    msg = self.kiwoom.get_user_info()
                elif command == "check_balance":
                    msg = self.kiwoom.check_balance(input_data)
                elif command == "trade_stock":
                    assert len(raw_command_list) >= 6, "Not enough parameter"
                    msg = self.kiwoom.trade_stocks(*raw_command_list[1:])
                elif command == "get_remain_stock":
                    msg = self.kiwoom.get_remain_stock(input_data)
                elif command == "set_cur_account":
                    if len(raw_command_list) > 1:
                        msg = self.kiwoom.set_cur_account(raw_command_list[1])
                elif command == "get_cur_account":
                    msg = self.kiwoom.get_cur_account()
                elif command == "check_deposit":
                    msg = self.kiwoom.check_deposit(input_data)
                elif command == "server_gubun":
                    msg = self.kiwoom.get_server_gubun()
                elif command == "get_current_price":
                    msg = self.kiwoom.get_current_price(input_data, raw_command_list[1])
                elif command == "get_code_list":
                    assert 2 == len(raw_command_list), "Not enough parameter"
                    msg = self.kiwoom.get_code_list_by_market(raw_command_list[1])
                elif command == "get_master":
                    assert 2 == len(raw_command_list), "Not enough parameter"
                    msg = self.kiwoom.get_master(input_data, raw_command_list[1])
                elif command == "get_stock_daily_chart":
                    arg_len = len(raw_command_list)
                    assert 4 == arg_len or 5 == arg_len, "Not enough parameter"
                    msg = self.kiwoom.get_stock_daily_chart(input_data, *raw_command_list[1:])
                elif command == "get_stock_daily_trend":
                    arg_len = len(raw_command_list)
                    assert 6 == arg_len or 7 == arg_len, "Not enough parameter"
                    msg = self.kiwoom.get_stock_daily_trend(input_data, *raw_command_list[1:])
                elif command == "get_stock_min_chart":
                    arg_len = len(raw_command_list)
                    assert 4 == arg_len or 5 == arg_len, "Not enough parameter"
                    msg = self.kiwoom.get_stock_min_chart(input_data, *raw_command_list[1:])
                elif command == "get_multi_items":
                    assert 4 == len(raw_command_list), "Not enough parameter"
                    msg = self.kiwoom.get_multi_items(input_data, *raw_command_list[1:])
                elif command == "detail_balance":
                    msg = self.kiwoom.detail_balance(input_data, *raw_command_list[1:])
                elif command == "get_detail_trade":
                    msg = self.kiwoom.get_detail_trade(input_data, raw_command_list[1])
                else:
                    continue

                result = {
                    "msg": msg,
                    "req_cmd": input_data
                }

                # req_cmd가 부정확한 경우가 있으므로 다시 확인한다.
                if type(msg) is dict and "req_cmd" in msg:
                    result["req_cmd"] = msg["req_cmd"]
                    del msg["req_cmd"]

                self.output_queue.put(result)
            except Exception as e:
                self.output_queue.put(str(e))

    def get_kiwoom_status(self):
        if self.kiwoom:
            return self.kiwoom.get_connect_state()
        else:
            return -1

    @classmethod
    def on_click_exit_btn(cls):
        sys.exit()


if __name__ == "__main__":
    app = QApplication(sys.argv)
    xwindow = KiwoomWindow(None, None, None)
    xwindow.show()
    app.exec_()