from collections import OrderedDict
import ast

from .sample_data import weight

raw = weight.raw
raw_index = weight.raw_index

raw_list = raw.split("\n")[1:-1]
raw_index_list = raw_index.split("\n")[1:-1]

result = OrderedDict()

for index, item in zip(raw_index_list, raw_list):
    temp_item = ast.literal_eval(item)
    result[index] = temp_item

def get_hrp_weight():
    import random
    rnd_idx = random.choice(list(result.keys()))
    return result[rnd_idx]