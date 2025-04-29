from mesa.time import SimultaneousActivation

# 상호작용 규칙 (SimultaneousActivation)
class TimeSeriesSimultaneousActivation(SimultaneousActivation):
    def __init__(self, model):
        super(TimeSeriesSimultaneousActivation, self).__init__(model)

    def step(self):
        """ Step all agents, then advance them. """
        agent_keys = list(self._agents.keys())
        for agent_key in agent_keys:
            self._agents[agent_key].step()
        # Deprecated
        #for agent_key in agent_keys:
        #    self._agents[agent_key].advance()
        self.steps += 1
        self.time += 1

# 상호작용 규칙 변경 (SimultaneousActivation For thread workers)
class TimeSeriesSimultaneousParallelActivation(SimultaneousActivation):
    def __init__(self, model):
        super(TimeSeriesSimultaneousParallelActivation, self).__init__(model)
        self._agents_event_queue = dict()

    def add(self, agent, event_queue):
        """ Add an Agent object to the schedule.

        Args:
            agent: An Agent to be added to the schedule. NOTE: The agent must
            have a step() method.

        """
        self._agents[agent.unique_id] = agent
        self._agents_event_queue[agent.unique_id] = event_queue

    def step(self):
        """ Step all agents, then advance them. """
        agent_keys = list(self._agents.keys())
        for agent_key in agent_keys:
            # TODO: 에이전트에 유한상태머신을 구현하고, 이벤트 타입도 구현.
            self._agents_event_queue[agent_key].put("STEP")
        self.steps += 1
        self.time += 1