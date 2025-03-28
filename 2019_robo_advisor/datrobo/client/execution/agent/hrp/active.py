from .hrp import HrpAgent
from datrobo.client.logic.main_logic import HRP_Active


class HrpActive(HrpAgent):
    def __init__(self, unique_id, model):
        super().__init__(unique_id, model)

        # agent name (수많은 의존성을 가지고 있음, 변경자체)
        self.agent_name = "hrp_active"

        # agent state
        self.account = {'account_num': 0,
                        'account_balance': 3200000}

    def step(self):
        # 로깅, 텔레그램 채널 하나로, Read Only
        print("[Agent_name] Agent HeartBeat")

    def _get_model_weight(self, bclose_dict):
        model_portfolio = HRP_Active()
        model_weight = model_portfolio.calc_weight()
        return model_weight