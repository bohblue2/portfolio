##################################################
# Author: hansang.cho
# Copyright: Copyright 2019, hansang.cho
# Version: 1.0.0
# Mmaintainer: hansang.cho
# Email: hehpollon@gmail.com
# Status: complete
##################################################

from websocket import create_connection
import datetime
import json
from datrobo.client.common.database import Database
from datrobo.util.telegram_api import Telegram
import configparser
from datrobo.server.auth import auth


class Manage:
    def __init__(self, db, account_list: list, config_file_path: str, date: str = 0):
        assert account_list, "No Account Error"
        self.my_account = account_list
        self.my_account_info_dict = dict()
        for v in self.my_account:
            self.my_account_info_dict[v] = dict()
        if date:
            self.cur_date_obj = self._str_to_date(date)
        else:
            self.cur_date_obj = self._str_to_date(self._date_to_str(datetime.datetime.now()))
        self.db = db

        config = configparser.ConfigParser()
        config.sections()
        config.read(config_file_path)
        self.telegram = Telegram(*[
            config['TELEGRAM']['token'],
            config['TELEGRAM']['chat_id']
        ])

    def __del__(self):
        self.telegram.send_message("exit_telegram_thread")

    @staticmethod
    def _str_to_date(date: str) -> datetime.datetime:
        return datetime.datetime.strptime(date, '%Y%m%d')

    @staticmethod
    def _str_to_date_time(date: str) -> datetime.datetime:
        return datetime.datetime.strptime(date, '%Y%m%d %H:%M:%S')

    @staticmethod
    def _date_to_str(date: datetime.datetime) -> str:
        return date.strftime("%Y%m%d")

    @staticmethod
    def reformat(data):
        if not data:
            return data
        if data[0] == '-':
            sign = '-'
            data = data[1:]
        else:
            sign = ''
        for i, v in enumerate(data):
            if v == '0':
                continue
            else:
                return f'{sign}{data[i:]}'
        return '0'

    @staticmethod
    def reformat_percent(data):
        if not data:
            return data
        if data[0] == '-':
            sign = '-'
            data = data[1:]
        else:
            sign = ''
        if len(data) == 1:
            return f'{sign}0.0{data}'
        elif len(data) == 2:
            return f'{sign}0.{data}'
        else:
            return f'{sign}{data[:-2]}.{data[-2:]}'

    def connect(self, auth: auth = None, user_id: str = None):
        ws = create_connection("ws://localhost:8765/")
        print(ws.recv())  # init message
        return ws

    @staticmethod
    def recv_ws(ws) -> dict:
        result = ws.recv()
        dict_result = json.loads(result)
        while 'broadcast' in dict_result.keys():
            result = ws.recv()
            dict_result = json.loads(result)
        return dict_result

    def check_status(self, ws):
        ws.send("status")
        status = self.recv_ws(ws)['data']['msg']
        if status == "1":
            return True
        else:
            return False

    def send_and_recv(self, ws, message) -> dict:
        print(message)
        ws.send(message)
        result = self.recv_ws(ws)
        print(result)
        return result

    def run(self, ws, cur_date):
        self.check_status(ws)
        self.send_and_recv(ws, f'set_cur_account {self.my_account[0]}')
        self.send_and_recv(ws, f"get_detail_trade {cur_date} {cur_date}")

    def insert_balance(self, ws):
        for account in self.my_account:
            self.send_and_recv(ws, f'set_cur_account {account}')
            result = self.send_and_recv(ws, f'check_balance')
            single_data = result['data']['msg']['single']
            for v in single_data:
                single_data[v] = self.reformat(single_data[v])
            계좌번호 = account
            날짜 = self._date_to_str(self.cur_date_obj)
            total_purchage_amount = single_data['총매입금액']
            total_evaluation_amount = single_data['총평가금액']
            total_evaluation_profit = single_data['총평가손익금액']
            presume_deposit_asset = single_data['추정예탁자산']
            self.my_account_info_dict[계좌번호]['추정예탁자산'] = presume_deposit_asset
            total_profit_ratio = self.reformat_percent(single_data['총수익률(%)'])
            self.my_account_info_dict[계좌번호]['총수익률(%)'] = total_profit_ratio
            insert_data = (
                계좌번호,
                날짜,
                total_purchage_amount,
                total_evaluation_amount,
                total_evaluation_profit,
                total_profit_ratio,
                presume_deposit_asset
            )
            self.db.insert_balance(insert_data)
            multi_data = result['data']['msg']['multi']
            single_data = result['data']['msg']['single']
            tot_value = int(single_data['추정예탁자산'])
            if multi_data:
                self.my_account_info_dict[계좌번호]['종목'] = dict()
                for v in multi_data:
                    for k in v:
                        v[k] = self.reformat(v[k])
                    stock_num = v['종목번호']
                    stock_name = v['종목명']
                    evaluate_profit = v['평가손익']
                    profit_ratio = self.reformat_percent(v['수익률(%)'])
                    bought_price = v['매입가']
                    cur_price = v['현재가']
                    possess_amount = v['보유수량']
                    evaluate_price = v['평가금액']
                    possess_weight = 0

                    if 0 < tot_value:
                        possess_weight = round((int(v['평가금액']) - int(v['평가수수료']) - int(v['세금'])) / tot_value * 100.0, 2)

                    self.my_account_info_dict[계좌번호]['종목'][v['종목명']] = {
                        '평가손익': evaluate_profit,
                        '수익률(%)': profit_ratio,
                        # '매입가': bought_price,
                        '현재가': cur_price,
                        '보유수량': possess_amount,
                        # '평가금액': evaluate_price,
                        '보유비중(%)': possess_weight
                    }
                    insert_data = (
                        계좌번호,
                        날짜,
                        stock_num,
                        stock_name,
                        evaluate_profit,
                        profit_ratio,
                        bought_price,
                        cur_price,
                        possess_amount,
                        evaluate_price,
                        possess_weight
                    )
                    self.db.insert_balance_stock(insert_data)

    def insert_balance_detail(self, ws):
        for account in self.my_account:
            self.send_and_recv(ws, f'set_cur_account {account}')
            날짜 = self._date_to_str(self.cur_date_obj)
            result = self.send_and_recv(ws, f'detail_balance {날짜} {날짜}')
            single_data = result['data']['msg']['single']
            for v in single_data:
                single_data[v] = self.reformat(single_data[v])
            계좌번호 = account
            날짜 = self._date_to_str(self.cur_date_obj)
            total_net_asset_early = single_data['순자산액계_초']
            total_net_asset_late = single_data['순자산액계_말']
            evaluate_profit = single_data['평가손익']
            profit_ratio = self.reformat_percent(single_data['수익률'])
            turnover = self.reformat_percent(single_data['회전율'])
            self.my_account_info_dict[계좌번호]['순자산액'] = total_net_asset_late
            insert_data = (
                계좌번호,
                날짜,
                total_net_asset_early,
                total_net_asset_late,
                evaluate_profit,
                profit_ratio,
                turnover
            )
            self.db.insert_balance_detail(insert_data)

    def insert_trade(self, ws):
        for account in self.my_account:
            self.send_and_recv(ws, f'set_cur_account {account}')
            날짜 = self._date_to_str(self.cur_date_obj)
            result = self.send_and_recv(ws, f'get_detail_trade {날짜}')
            single_data = result['data']['msg']['single']
            for v in single_data:
                single_data[v] = self.reformat(single_data[v])
            계좌번호 = account
            num = single_data['조회건수']
            if not num:
                continue
            multi_data = result['data']['msg']['multi']
            if multi_data:
                for v in multi_data:
                    for k in v:
                        v[k] = self.reformat(v[k])
                    order_num = v['주문번호']
                    stock_num = v['종목번호']
                    trade_gubun = v['매매구분']
                    order_kind_gubun = v['주문유형구분']
                    order_amount = v['주문수량']
                    order_price = v['주문단가']
                    fill_num = v['체결번호']
                    fill_amount = v['체결수량']
                    fill_price = v['체결단가']
                    fill_time = self._str_to_date_time(f"{날짜} {v['체결시간']}")

                    insert_data = (
                        계좌번호,
                        날짜,
                        order_num,
                        stock_num,
                        trade_gubun,
                        order_kind_gubun,
                        order_amount,
                        order_price,
                        fill_num,
                        fill_amount,
                        fill_price,
                        fill_time
                    )
                    self.db.insert_trade(insert_data)

    def insert_complete(self):
        날짜 = self._date_to_str(self.cur_date_obj)
        insert_data = (날짜, 1)
        self.db.insert_complete(insert_data)
        message_data = f"[{날짜} 관리sys 수집 완료]\n\n"
        for account_num in self.my_account_info_dict:
            message_data += f'* 계좌번호: {account_num}\n'
            for v in ['총수익률(%)', '추정예탁자산', '종목']:
                if v not in self.my_account_info_dict[account_num]:
                    continue
                if type(self.my_account_info_dict[account_num][v]) is dict:
                    stock_dict = self.my_account_info_dict[account_num][v]
                    for stock_name in stock_dict:
                        message_data += f' - {stock_name}\n'
                        for j in stock_dict[stock_name]:
                            message_data += f'{j}:{stock_dict[stock_name][j]}\n'
                else:
                    message_data += f'{v}: {self.my_account_info_dict[account_num][v]}\n'
            message_data += f'\n'

        # 운용 시작하면 주석 해제
        self.telegram.send_message(message_data)


if __name__ == '__main__':
    config_file_path = "C:\\config\\config.ini"
    with Database(config_file_path) as db:
        account_list = ['5225431710', '5257021710', '5257022310']
        manage = Manage(db=db, account_list=account_list, config_file_path=config_file_path)
        try:
            ws = manage.connect()
            manage.insert_balance(ws)
            manage.insert_balance_detail(ws)
            manage.insert_trade(ws)
            manage.insert_complete()
        except Exception as e:
            print("* Exception", e)
        finally:
            print("websocket closed")
            ws.close()
