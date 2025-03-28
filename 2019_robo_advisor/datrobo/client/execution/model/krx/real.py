from dattoolbox.robo.action import ModelAction
from dattoolbox.robo.time import TimeSeriesSimultaneousParallelActivation
from dattoolbox.robo.model import VirtualModel

from dattoolbox.api.client.kiwoom import KiwoomClient

# 실 투자용 가상 KRX 모델 (실제 KRX와 바인딩됨)
class VirtualModelKRX(VirtualModel, ModelAction):
    def __init__(self, unique_id, name):
        super(VirtualModelKRX, self).__init__()

        # set model state here
        self.name = name
        self.unique_id = unique_id

        # 키움증권 API
        self.kiwoom_client = KiwoomClient(None, None)

        # set model schedule
        self.schedule = TimeSeriesSimultaneousParallelActivation(self)

    def step(self):
        self.schedule.step()

    # Actions
    def _set_cur_account(self, account):
        return self.kiwoom_client.set_cur_account(account)

    def _get_cur_account(self):
        return self.kiwoom_client.get_cur_account()

    def _set_order(self, option: str, hoga: str, code: str, num: int, price: int, prev_order_num: str = ""):
        return self.kiwoom_client.set_order(option, hoga, code, num, price, prev_order_num)

    def _get_account(self):
        return self.kiwoom_client.get_account()

    def _get_balance(self):
        return self.kiwoom_client.get_balance()

    def _get_accounts_num(self):
        return self.kiwoom_client.get_accounts_num()

    def _get_position(self):
        return self.kiwoom_client.get_position()

    def _get_server_status(self):
        return self.kiwoom_client.get_server_status()

    def _get_server_gubun(self):
        return self.kiwoom_client.get_server_gubun()

    def _get_current_price(self, stcode):
        return self.kiwoom_client.get_current_price(stcode)

    def _get_master(self, mk_type):
        return self.kiwoom_client.get_master(mk_type)

    def _get_multi_items(self, shtcodes, code_cnt, mk_kind):
        return self.kiwoom_client.get_multi_items(shtcodes, code_cnt, mk_kind)
