from dattoolbox.robo.action import ModelAction
from dattoolbox.robo.time import TimeSeriesSimultaneousActivation
from dattoolbox.robo.model import VirtualModel


# 모의 투자용 가상 KRX 모델 (증권사 모의투자 서버와 바인딩됨)
class MockVirtualModelKRX(VirtualModel, ModelAction):
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