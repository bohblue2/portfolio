import numpy as np

from util.make_log import save_log_wotime
from abc import ABCMeta, abstractmethod


class Universe:
    def __init__(self):
        pass

    # @abstractmethod
    # def _request_data(self, *args):
    #     """
    #     모니터링해야할 종목을 선택
    #     """
    #     raise NotImplementedError("Should implement _request_data()")

    @abstractmethod
    def select_monitored_subjects(self, *args):
        """
        모니터링해야할 종목을 선택
        """
        raise NotImplementedError("Should implement select_monitored_subjects()")


class UniverseManger(Universe):
    TARGET_VP = 1000000000

    def __init__(self):
        pass

    def _cal_momentum(self, data):
        length = len(data)

        if length < 2:
            print("Not enough length of data! it should be at least 2")
            return 1.0

        momentum = np.ones_like(data) * data[-1]
        momentum = np.prod(momentum[:-1] / data[:-1])

        return momentum ** (1 / (length - 1))

    def select_monitored_subjects(self, data, file_path="../mnt_stocks"):
        stocks = []

        for k, v in data.items():
            vp = v[:, 3]
            if vp >= self.TARGET_VP:
                stocks.append(k)

        save_log_wotime(stocks, file_path, prefix="list_mnt_stocks")
        return stocks

