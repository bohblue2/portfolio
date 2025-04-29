import datetime
from datrobo.util.telegram_api import Telegram
import configparser
import math
import matplotlib.pyplot as plt
from pandas.plotting import register_matplotlib_converters
import matplotlib.font_manager as fm
import os
import numpy as np

register_matplotlib_converters()

# set hangul font
if os.name == "posix":  # mac
    path = '/Library/Fonts/NanumBarunGothic.ttf'
else:  # windows
    path = 'C:/Windows/Fonts/NanumGothicBold.ttf'
font_name = fm.FontProperties(fname=path, size=50).get_name()
plt.rc('font', family=font_name)


class Report:
    def __init__(self, db, account: str, config_file_path: str, start_date: str, cur_date: str = ''):
        assert account, "No Account Error"
        self.my_account = account
        self.my_account_info_dict = dict()
        if cur_date:
            self.cur_date_str = cur_date
            self.cur_date_obj = self._str_to_date(cur_date)
        else:
            self.cur_date_str = self._date_to_str(datetime.datetime.now())
            self.cur_date_obj = self._str_to_date(self.cur_date_str)
        self.db = db
        self.start_date_boj = self._str_to_date(start_date)

        config = configparser.ConfigParser()
        config.sections()
        config.read(config_file_path)
        self.telegram = Telegram(*[
            config['TELEGRAM']['token'],
            config['TELEGRAM']['chat_id']
        ])
        self.gain_ratio_list = []
        self.max_earning = 0
        self.min_earning = 100
        self.mdd = 0

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
    def _date_to_pretty_str(date: datetime.datetime) -> str:
        return date.strftime("%Y-%m-%d")

    @staticmethod
    def geo_mean(iterable):
        iterable = list(map(lambda x: 1+x/100, iterable))
        a = np.array(iterable)
        return (a.prod() ** (1.0 / len(a)) - 1) * 100

    @staticmethod
    def cagr(iterable):
        iterable = list(map(lambda x: 1 + x / 100, iterable))
        a = np.array(iterable)
        return (a.prod() ** (1.0 / (len(a)/252)) - 1) * 100

    def create_report(self):
        balance_list = self.db.get_balance(self.my_account, self.start_date_boj)
        if len(balance_list) == 0:
            return

        total_gain = 0
        current_balance = 0
        line_size = 40
        message = ''
        last_date = ''
        temp_mdd_earning = 0
        start_account_amount = 0
        day_log_profit_ratio = 0
        for idx, balance in enumerate(balance_list):
            data = balance
            총평가손익금액 = int(data['total_evaluation_profit'])
            추정예탁자산 = int(data['presume_deposit_asset'])  # 예수금까지 포함 금액
            총평가금액 = int(data['total_evaluation_amount'])  # 예수금 미포함
            total_gain = 총평가손익금액
            # add list
            day_profit_ratio = total_gain / (추정예탁자산 - total_gain) * 100
            # day_log_profit_ratio = math.log(추정예탁자산/(추정예탁자산 - total_gain)) * 100
            if idx == 0:
                start_account_amount = 추정예탁자산
                day_log_profit_ratio = total_gain/(추정예탁자산 - total_gain) * 100
            else:
                day_log_profit_ratio = (추정예탁자산 - start_account_amount) / start_account_amount * 100
            self.gain_ratio_list.append((data['date'], day_log_profit_ratio, total_gain))
            if self.min_earning > day_profit_ratio:
                self.min_earning = day_profit_ratio
            if self.max_earning < day_profit_ratio:
                self.max_earning = day_profit_ratio
            else:
                temp_mdd_earning = day_profit_ratio - self.max_earning
            if temp_mdd_earning < self.mdd:
                self.mdd = temp_mdd_earning


            cash = 추정예탁자산 - 총평가금액
            if idx == len(balance_list) - 1:
                profit_ratio = (총평가손익금액 - int(balance_list[idx-1]['total_evaluation_profit'])) / 추정예탁자산 * 100
                profit_ratio_str = f'{math.floor(profit_ratio * 100) / 100}'
                current_balance = 추정예탁자산
                cur_date_str = self._date_to_pretty_str(self.cur_date_obj)
                message += f'* 일일운용내역 ({cur_date_str})\n'
                message += f'    {"-"*line_size}\n'
                message += f'     일별수익률: {profit_ratio_str}%\n'
                last_date = data['date']

        if self._date_to_str(last_date) != self.cur_date_str:  # if not market open date
            return
        total_profit_ratio = total_gain / (current_balance - total_gain) * 100
        total_profit_ratio_str = f'{math.floor(total_profit_ratio * 100) / 100}'
        message += f'     누적수익률: {total_profit_ratio_str}%\n'
        message += f'    {"-"*line_size}\n'
        message += f'     비중    보유종목\n'

        balance_stock = self.db.get_account_stock(self.my_account, self.cur_date_obj)
        for stock in balance_stock:
            stock_name = stock['stock_name']
            possess_weight = stock['possess_weight']
            message += f'     {possess_weight[:-3]}%   {stock_name} \n'
        self.telegram.send_message(message)

    def create_detail_report(self):
        date_list = []
        profit_list = []  # 누적수익률
        log_profit_day_list = []  # 일별수익률
        for idx, gain_ratio in enumerate(self.gain_ratio_list):
            date_list.append(gain_ratio[0])
            profit_list.append(gain_ratio[1])
            day_profix = profit_list[idx]
            if idx > 0:
                day_profix -= profit_list[idx-1]

            log_profit_day_list.append(day_profix)

        detail_message = ''
        mdd_str = f'{math.floor(abs(self.mdd) * 100) / 100}%'
        detail_message += f" - 누적수익률: {profit_list[-1]:,.2f}% \n"
        mean_profit = np.mean(log_profit_day_list)
        detail_message += f' - Mean: {mean_profit:,.2f}% \n'
        detail_message += f" - MDD: {mdd_str} \n"
        detail_message += f' - Var: {np.var(log_profit_day_list):,.2f}% \n'
        기준금리 = (1.0175 ** (len(log_profit_day_list)/252) - 1) * 100
        sharpe_ratio = (np.mean(log_profit_day_list) - 기준금리) / math.sqrt(np.var(log_profit_day_list))
        detail_message += f' - Sharpe ratio: {sharpe_ratio:,.2f} \n'
        plt.plot(date_list, profit_list, color='r', label="누적수익률")
        plt.gcf().autofmt_xdate()
        plt.gcf().set_size_inches(5, 3)
        plt.rcParams['axes.unicode_minus'] = False
        plt.legend(loc='upper left')
        plt.savefig('img/return.png', dpi=100)
        plt.clf()
        self.telegram.send_message(detail_message)
        self.telegram.send_message("img_path:img/return.png")
        time.sleep(7)

