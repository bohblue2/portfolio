from mesa import Model

from abc import (
    ABCMeta,
    abstractmethod
)

class IVirtualModel(Model):
    __metaclass__ = ABCMeta

    def __init__(self):
        super(IVirtualModel, self).__init__()

    @abstractmethod
    def step(self):
        raise NotImplementedError

    @abstractmethod
    def set_schedule(self, schdule):
        raise NotImplementedError()

    @abstractmethod
    def add_agent(self, agent: dict):
        raise NotImplementedError()


class VirtualModel(IVirtualModel):
    def __init__(self):
        super(VirtualModel, self).__init__()

        self.agent_num = 0

    def set_schedule(self, schedule):
        self.schedule = schedule

    def add_agent(self, agents: dict):
        # TODO: agent argument 가 dict 인지 확인:
        # TODO: 스케쥴이 설정되지 않은상태에서 add 하는지 확인하는 로직
        # TODO: 이미 인스턴스화된 에이전트도 스케쥴에 등록이 가능해야함.
        if isinstance(agents, dict):
            if self.schedule != None:
                # TODO: Try/Catch 필요.
                for agent_name, agent_conf in agents.items():
                    # agent_args = agent_conf['agent_args']
                    # agent_args.update({'model': self})
                    # agent_class = agent_conf['agent']
                    #
                    # agent = agent_class(
                    #     **agent_args
                    # )

                    agent = agent_conf['agent'](
                        model=self,
                        **agent_conf['agent_args']
                    )

                    agent.start()

                    self.schedule.add(
                        agent=agent,
                        event_queue=agent_conf['agent_args']['event_queue']
                    )

                    self.agent_num += 1
                return True
            else:
                return False # 스케쥴이 설정 안되어 있음
        else:
            return False # agent 인자가 사전 타입이 아님




