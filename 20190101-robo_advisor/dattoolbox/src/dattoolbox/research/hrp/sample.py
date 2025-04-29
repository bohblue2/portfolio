from collections import OrderedDict
import ast

from .sample_data import weight

class HRP_Sample():
    def __init__(self):
        raw = weight.raw
        raw_index = weight.raw_index

        raw_list = raw.split("\n")[1:-1]
        raw_index_list = raw_index.split("\n")[1:-1]

        self.result = OrderedDict()

        for index, item in zip(raw_index_list, raw_list):
            temp_item = ast.literal_eval(item)
            self.result[index] = temp_item

    def calc_weight(self, bprice):
        import random
        rnd_idx = random.choice(list(self.result.keys()))
        return self.result[rnd_idx]