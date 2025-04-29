# https://www.quantconnect.com/tutorials/strategy-library/intraday-dynamic-pairs-trading-using-correlation-and-cointegration-approach

import pandas as pd
import numpy as np
import statsmodels.api as sm
import statsmodels.tsa.stattools as ts

import matplotlib.pyplot as plt

class pairs(object):
    def __init__(self, a, b):
        self.a = a
        self.b = b
        self.name = a.name + ':' + b.name
        self.df = pd.concat([a, b], axis=1).dropna()

        # num_bar: entire time series
        self.num_bar = self.df.shape[0]
        self.cor = self.df.corr().iloc[0, 1]
        # Set the initial signals to be 0
        self.error = 0
        self.last_error = 0

    def cor_update(self):
        self.cor = self.df.corr().iloc[0, 1]

    def cointegration_test(self):
        constant_added = sm.add_constant(self.df.iloc[:, 1])
        self.model = sm.OLS(self.df.iloc[:, 0], constant_added).fit()
        # This line conduct ADF test on the residual. ts.adfuller() returns a tuple and the first element in
        #   the tuple is the test value.
        self.adf = ts.adfuller(self.model.resid, autolag='BIC')[0]
        self.mean_resid = np.mean(self.model.resid)
        self.sd = np.std(self.model.resid)
        print('pairs head: ', self.df.head())
        print('pairs tail: ', self.df.tail())
        print('adf: ', self.adf)
        print('resid mean: ', self.mean_resid)
        print('resid sd: ', self.sd)

    def df_update(self, a_new, b_new):
        # new_df = pd.DataFrame({str(self.a.columns): self.a_price, str(self.b): self.b}, index=[self.a.index]).dropna()
        new_df = pd.concat([a_new, b_new], axis=1)
        self.df = pd.concat([self.df, new_df], axis=0)
        #rolling windows to compute adf
        self.df = self.df.tail(self.num_bar)


# symbol: list of time series data frame
# num_bar: entire time series
class pair_trading():
    def __init__(self, combined_price, num_bar, num_pair, threshold=0.4):
        self.combined_price = combined_price
        self.num_bar = num_bar
        self.positions = {}
        self.selected_num = num_pair
        self.pair_threshold = threshold


    # symbols and pair_threshold should be given
    def generate_pairs(self):
        # self.pair_num = num_pair
        self.pair_list = []

        for i in range(len(self.combined_price.columns)):
            for j in range(i + 1, len(self.combined_price.columns)):
                self.pair_list.append(pairs(self.combined_price.iloc[:, i], self.combined_price.iloc[:, j]))

        [print('inital pair: ', x.name, x.cor) for x in self.pair_list]

        self.pair_list = [x for x in self.pair_list if x.cor > self.pair_threshold]
        self.pair_list.sort(key=lambda x: x.cor, reverse=True)


    # prevent a stock to be in multiple pairs
    def pair_clean(self, selected_list):
        l = []
        l.append(selected_list[0])
        for i in selected_list:
            # combine pair components
            # update in every loop
            symbols = [x.a for x in l] + [x.b for x in l]
            if i.a not in symbols and i.b not in symbols:
                l.append(i)
            else:
                pass
        return l

    # select final pairs
    def select_final_pairs(self):
        # when no pairs generated in the past
        if len(self.combined_price.index) == self.num_bar:  # self.count == 0 and

            self.generate_pairs()

        # Cointegration test
        for pair in self.pair_list:
            pair.cointegration_test()

        print('pair len: ', len(self.pair_list))
        print('df: ', self.pair_list[0].df.head(), self.pair_list[0].df.tail())
        print('adf: ', self.pair_list[0].adf)
        # TODO: x.adf should be compared with BIC
        self.selected_adf = [x for x in self.pair_list if x.adf < -1]
        self.selected_adf.sort(key=lambda x: x.adf)

        if len(self.selected_adf) == 0:
            return print('no selected pair')

        # clean the pair to avoid overlapping stocks.
        self.selected_final = self.pair_clean(self.selected_adf)
        # assign a property to the selected pair, this is a signal that would be used for trading.
        for pair in self.selected_final:
            pair.touch = 0
        # limit the number of selected pairs.
        if len(self.selected_final) > self.selected_num:
            self.selected_final = self.selected_final[:self.selected_num]

        return

    # update pairs
    def update_pairs(self, data):
        for pair in self.selected_final:
            # when selected pairs are in given data
            if pair.a.name in data.columns and pair.b.name in data.columns:
                pair.df_update(data.loc[:, pair.a.name], data.loc[:, pair.b.name])
            else:
                # self.Log('%s has no data'%str(pair.name))
                self.selected_final.remove(pair)

        for pair in self.selected_final:
            pair.last_error = pair.error


    # opening pairs
    def open_pairs(self):
        for pair in self.selected_final:

            # here error is updated first from initial 0
            # error is the residual from cointegration
            # what does error mean here, greater better? smaller better??? smaller better but small spread
            pair.error = pair.a.values[-1]- (pair.model.params[0] + pair.model.params[1] * pair.b.values[-1])

            if pair.error > pair.mean_resid - pair.sd and pair.last_error < pair.mean_resid - pair.sd:
                # self.Log('long %s and short %s'%(str(i.a),str(i.b)))
                # why record model??
                pair.record_model = pair.model
                pair.record_mean_resid = pair.mean_resid
                pair.record_sd = pair.sd
                self.trading_pairs.append(pair)
                self.positions['a'] = 5.0 / len(self.selected_final)  # self.SetHoldings(i.a, 5.0/(len(self.selected_final)))
                self.positions['b'] = -5.0 / len(self.selected_final)  # self.SetHoldings(i.b, -5.0/(len(self.selected_final)))
                pair.touch = 0

            elif pair.error < pair.mean_resid + pair.sd and pair.last_error > pair.mean_resid + pair.sd:
                # self.Log('long %s and short %s'%(str(i.b),str(i.a)))
                pair.record_model = pair.model
                pair.record_mean_resid = pair.mean_resid
                pair.record_sd = pair.sd
                self.trading_pairs.append(pair)
                self.positions['b'] = 5.0 / len(self.selected_final)  # self.SetHoldings(i.b, 5.0/(len(self.selected_pair)))
                self.positions['a'] = -5.0 / len(self.selected_final)  # self.SetHoldings(i.a, -5.0/(len(self.selected_pair)))
                pair.touch = 0


    # closing pairs
    def close_pairs(self, data):
        for i in self.trading_pairs:
            price_a = float(data[i.a].Close)
            price_b = float(data[i.b].Close)
            i.error = price_a - (i.record_model.params[0] + i.record_model.params[1] * price_b)
            if (i.error < i.record_mean_error + self.close_size * i.record_sd and i.last_error > i.record_mean_error + self.close_size * i.record_sd):
                return
            elif i.error > i.record_mean_error - self.close_size * i.record_sd and i.last_error < i.record_mean_error +  self.stop_loss * i.record_sd:
                return


tr_005930 = pd.read_hdf(r'D:\data\tickdata\20190426_kor_stock.h5', "005930_tr")
tr_000660 = pd.read_hdf(r'D:\data\tickdata\20190426_kor_stock.h5', "000660_tr")
tr_012330 = pd.read_hdf(r'D:\data\tickdata\20190426_kor_stock.h5', "012330_tr")
tr_005380 = pd.read_hdf(r'D:\data\tickdata\20190426_kor_stock.h5', "005380_tr")


cur_005930 = tr_005930.reset_index().drop(columns =['time_api']).set_index(['datetime_sys'])
cur_000660 = tr_000660.reset_index().drop(columns =['time_api']).set_index(['datetime_sys'])
cur_012330 = tr_012330.reset_index().drop(columns =['time_api']).set_index(['datetime_sys'])
cur_005380 = tr_005380.reset_index().drop(columns =['time_api']).set_index(['datetime_sys'])

cur_1m_005930 = cur_005930['price'].resample('1T').ohlc().dropna()
cur_1m_000660 = cur_000660['price'].resample('1T').ohlc().dropna()
cur_1m_012330 = cur_012330['price'].resample('1T').ohlc().dropna()
cur_1m_005380 = cur_005380['price'].resample('1T').ohlc().dropna()

close_005930 = cur_1m_005930['close'].to_frame()
close_000660 = cur_1m_000660['close'].to_frame()
close_012330 = cur_1m_012330['close'].to_frame()
close_005380 = cur_1m_005380['close'].to_frame()

close_005930.columns =['A005930']
close_000660.columns =['A000660']
close_012330.columns =['A012330']
close_005380.columns =['A005380']



preset_005930 = close_005930.iloc[:-100, :]
preset_000660 = close_000660.iloc[:-100, :]
preset_005380 = close_005380.iloc[:-100, :]
preset_012330 = close_012330.iloc[:-100, :]


test_005930 = close_005930.iloc[-100:, :]
test_000660 = close_000660.iloc[-100:, :]
test_005380 = close_005380.iloc[-100:, :]
test_012330 = close_012330.iloc[-100:, :]

test_data = pd.concat([test_005930, test_000660, test_005380, test_012330], axis=1)

symbols =[close_005930,
            close_000660,
            close_005380,
            close_012330]

combined_symbols = pd.concat(symbols, join = 'outer', axis=1)
combined_symbols = combined_symbols.fillna(method = 'ffill')
combined_symbols = combined_symbols.dropna()
# p = pairs(close_005930, close_000660)
# p.cointegration_test()
# p.adf
#
# p.num_bar


training_period = combined_symbols.index
pt= pair_trading(combined_symbols, len(training_period), 2)

# use training data
pt.select_final_pairs()

pt.update_pairs(test_data)
pt.open_pairs()


