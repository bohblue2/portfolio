from abc import (
    ABCMeta,
    abstractmethod
)

from mesa import (
    Agent
)

from dattoolbox.robo.action import AgentAction

class RoboAdvisor(Agent, AgentAction):
    __metaclass__ = ABCMeta

    def __init__(self, unique_id, model):
        super(RoboAdvisor, self).__init__(unique_id, model)

        # 에이전트 메타 데이터 (상수)
        # 에이전트 이름
        self.agent_name = None

        # 타임존
        self.timezone = None

        # 현재 AUM(총 운용 자산 가치)
        self.AUM = None
        # 현재 MDD
        self.MDD = None
        # 현재 Sharp
        self.sharp = None
        # 현금 보유량
        self.cash = None

        # 목표 포트폴리오 비중 (next) MP
        self.model_portfolio_weight = dict()
        # 실제 포트폴리오 비중 (prev) AP
        self.actual_portfolio_weight = dict()
        # 목표 포트폴리오 포지션(매입금액) MP
        self.model_portfolio_position = dict()
        # 실제 포트폴리오 포지션(종목수량) AP
        self.actual_portfolio_position = dict()

        # 실제 포트폴리오 현재가
        self.actual_portfolio_price = dict()

        # 최종 매수 비중
        self.final_buy_weight = dict()
        # 최종 매도 비중
        self.final_sell_weight = dict()
        # 최종 매수 포지션
        self.final_buy_position = dict()
        # 최종 매도 포지션
        self.final_sell_position = dict()

        # 계좌 정보
        self.account = dict()
        self.account = {'account_num': 0,
                        'account_balance': 0}

        # 리밸런싱 정보
        self.rebalance_result = list()

    @abstractmethod
    def step(self):
        # actions here
        raise NotImplementedError()

    @abstractmethod
    def advance(self):
        # states change here
        raise NotImplementedError()

if __name__ == "__main__":
    test = RoboAdvisor(0, "model")
