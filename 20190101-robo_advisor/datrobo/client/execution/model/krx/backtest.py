from dattoolbox.robo.action import ModelAction
from dattoolbox.robo.time import TimeSeriesSimultaneousActivation
from dattoolbox.robo.model import VirtualModel


# 백테스트용 가상 KRX 모델 (주문시 50%, 60%, ... 100% 체결되는 백테스트 시스템과 바인딩됨)
class BacktestModelKRX(VirtualModel, ModelAction):
    def __init__(self, agents):
        # set model state here

        # set model schedule
        self.schedule = TimeSeriesSimultaneousActivation(self)

        # create agents
        for agent_name, agent_class in agents.items():
            agent = agent_class(agent_name, self)
            self.schedule.add(agent)

    def step(self):
        self.schedule.step()