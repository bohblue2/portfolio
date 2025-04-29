import os
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt

from filterpy.kalman import UnscentedKalmanFilter, MerweScaledSigmaPoints
from time import time

std_x = 3.0
dt = 0.0001
n_obj = 1
x_size = 3
z_size = 1
n_iter = 300

FolderName = 'D:\\07_Data'
FileNames = os.listdir(FolderName)

LOB_KEY = ['offer_total_v', 'bid_total_v', 'sim_call', 'offer_01_p', 'offer_02_p', 'offer_03_p', 'offer_04_p',
           'offer_05_p', 'offer_06_p', 'offer_07_p', 'offer_08_p', 'offer_09_p', 'offer_10_p', 'bid_01_p',
           'bid_02_p', 'bid_03_p', 'bid_04_p', 'bid_05_p', 'bid_06_p', 'bid_07_p', 'bid_08_p', 'bid_09_p',
           'bid_10_p', 'offer_01_v', 'offer_02_v', 'offer_03_v', 'offer_04_v', 'offer_05_v', 'offer_06_v',
           'offer_07_v', 'offer_08_v', 'offer_09_v', 'offer_10_v', 'bid_01_v', 'bid_02_v', 'bid_03_v',
           'bid_04_v', 'bid_05_v', 'bid_06_v', 'bid_07_v', 'bid_08_v', 'bid_09_v', 'bid_10_v']
TR_KEY = ['price', 'volume', 'cum_volume', 'cum_value', 'tr_type', 'w_avg_price', 'bid_1_price', 'offer_1_price']


def call_hdf_bid(code, cols):
    type = code + "_lob"
    Query = "columns = %s" % cols

    return pd.read_hdf(FolderName + '\\' + FileNames[0], type, where=Query)


def call_hdf_cur(code, cols):
    type = code + "_tr"
    Query = "columns = %s" % cols

    return pd.read_hdf(FolderName + '\\' + FileNames[0], type, where=Query)


def get_unit_size(base_price):
    price = base_price
    print(price)
    KOSPI_UNIT = {100: 0, 1000: 1, 5000: 5, 10000: 10, 50000: 50, 100000: 100, 500000: 500, 1000000: 1000}

    if (price > 100) and (price <= 1000):
        ask_unit = 1
    elif (price > 1000) and (price <= 5000):
        ask_unit = 5
    elif (price > 5000) and (price <= 10000):
        ask_unit = 10
    elif (price > 10000) and (price <= 50000):
        ask_unit = 50
    elif (price > 50000) and (price <= 100000):
        ask_unit = 100
    elif (price > 100000) and (price <= 500000):
        ask_unit = 500
    elif price > 500000:
        ask_unit = 1000

    return ask_unit


def f_cv(x, dt):
    """ state transition function for a
    constant velocity aircraft"""
    n_shape = x.shape[0]
    F = np.zeros((n_shape, n_shape))

    for i in range(0, n_shape, x_size):
        F[i:i + x_size, i:i + x_size] += np.array([[1, dt, 0.5 * dt ** 2], [0, 1, dt], [0, 0, 1]])
        # F[i:i + 2, i:i + 2] += np.array([[1, dt], [0, 1]])

    return np.dot(F, x)


def h_cv(x):
    n_shape = x.shape[0]
    return x[[i for i in range(0, n_shape, x_size)]]


def sim_ukf(data):
    zs = data
    zs = zs[:, np.newaxis]
    ask_unit = get_unit_size(data[1])

    x_init = zs[0]

    if x_size == 2:
        x_input = np.array([x_init, 0.] * n_obj)
    elif x_size == 3:
        x_input = np.array([x_init, 0., 0.] * n_obj)

    # UKF
    sigmas = MerweScaledSigmaPoints(x_size * n_obj, alpha=.1, beta=2., kappa=1.)
    ukf = UnscentedKalmanFilter(dim_x=x_size * n_obj, dim_z=z_size * n_obj, fx=f_cv, hx=h_cv, dt=dt, points=sigmas)

    ukf.x = x_input
    ukf.R = np.diag([std_x ** 2] * n_obj)

    for i in range(2 * n_obj):
        ukf.Q[i * z_size:i * z_size + z_size, i * z_size:i * z_size + z_size] = np.random.rand()

    uxs_pred = []
    uxs_updated = []
    exc_time = []
    profit = []
    err_pred = []
    x = x_input[np.newaxis, :]

    ukf.predict()
    uxs_pred.append(ukf.x.copy())

    b_bid = False
    prev_price = x_init
    last_idx = zs.shape[0]

    for i, z in enumerate(zs):
        ukf.update(z)
        uxs_updated.append(ukf.x.copy())

        st_time = time()

        ukf.predict()
        ukf.predict()
        #         pred_ = f_cv(ukf.x, dt)
        ed_time = time()
        exc_time.append(ed_time - st_time)
        #         uxs_pred.append(pred_.copy())
        uxs_pred.append(ukf.x.copy())

        err_ = ukf.x[0] - z
        err_pred.append(err_)

        if (not b_bid) and (ukf.x_prior[2] > 2 * ask_unit):  # uxs_pred[-2][0]):
            b_bid = True
            bid_price = z * (1 - 0.00015)
            profit.append(1.0)
        elif b_bid and (ukf.x_prior[2] < -1 * ask_unit):  # uxs_pred[-2][0]):
            b_bid = False
            ask_price = z * (1 - 0.00315)
            profit.append(ask_price / bid_price)
        elif b_bid and (i >= last_idx - 1):  # uxs_pred[-2][0]):
            b_bid = False
            ask_price = z * (1 - 0.00315)
            profit.append(ask_price / bid_price)
        else:
            profit.append(1.0)

        prev_price = z

    uxs_pred.pop(0)
    uxs_pred = np.array(uxs_pred)
    uxs_updated = np.array(uxs_updated)
    profit = np.array(profit)
    exc_time = np.array(exc_time)
    err_pred = np.array(err_pred)

    return profit, uxs_pred, uxs_updated, exc_time, err_pred


def draw_result(data, profit, uxs_pred, uxs_updated, exc_time, err_pred):
    zs = data.loc[:, "midprice"]
    ask_unit = get_unit_size(zs.iloc[1])
    price_diff = (zs - zs.shift(1)) / ask_unit
    print(ask_unit)

    fig, (ax1, ax2, ax3) = plt.subplots(3, 1, figsize=(20, 10))

    ax1.plot(zs.values)
    ax1.plot(uxs_pred[:, 0])
    ax1.set_title("close")
    # ax1.set_xlim([30000, 40000])

    ax2.plot(np.cumprod(profit))
    ax2.set_title("profit")
    ax2.set_yscale("log", nonposy='clip')
    # ax2.set_xlim([30000, 40000])

    # ax3.plot(price_diff.values)
    pred_diff = np.zeros_like(uxs_pred[:, 0])
    pred_diff[1:] = uxs_pred[1:, 0] - uxs_pred[:-1, 0]
    roll_mean = np.zeros_like(uxs_pred[:, 0])
    roll_mean[4:] += (uxs_pred[0:-4, 0] + uxs_pred[1:-3, 0] + uxs_pred[2:-2, 0]
                      + uxs_pred[3:-1, 0] + uxs_pred[4:, 0]) / 5
    roll_mean[0:5] = uxs_pred[0:5, 0]

    ax3.plot(pred_diff, marker=".", label="pred_vel")
    ax3.plot(roll_mean, marker=".", color="r", label="pred_acc")
    ax3.legend()
    # ax3.set_xlim([30000, 40000])
    # ax4 = ax3.twinx()
    # ax4.plot(err_pred, marker=".", color="c", label="price_err")
    # ax4.plot(uxs_pred[:, 2] / ask_unit, marker=".", color="r", label="pred_acc")
    # ax4.legend()
    # ax4.set_xlim([30000, 40000])
    print("exec_time_mean : {0}".format(np.mean(exc_time)))
    plt.show()


def draw_analysis_bid(data):
    zs = data.loc[:, "midprice"]
    ask_unit = get_unit_size(data["midprice"].iloc[1])
    print(ask_unit)

    fig, (ax1, ax2) = plt.subplots(2, 1, figsize=(20, 10))

    ax1.plot(zs.values)
    ax3 = ax1.twinx()
    ax3.plot(data["oi"].cumsum().values)
    ax1.set_title("mid_price vs voi")
    # ax1.set_xlim([30000, 40000])

    ax2.plot(zs.values)
    ax4 = ax1.twinx()
    ax4.plot(data["order_imbal_ratio"].cumsum().values)
    ax2.set_title("mid_price vs imbalratio")
    # ax2.set_yscale("log", nonposy='clip')
    # ax2.set_xlim([30000, 40000])

    plt.show()


def draw_analysis_cur(data):
    zs = data.loc[:, "midprice"]
    ask_unit = get_unit_size(data["midprice"].iloc[1])
    print(ask_unit)

    fig, (ax1, ax2) = plt.subplots(2, 1, figsize=(20, 10))

    ax1.plot(zs.values)
    ax3 = ax1.twinx()
    ax3.plot(data["oi"].cumsum().values)
    ax1.set_title("mid_price vs voi")
    # ax1.set_xlim([30000, 40000])

    ax2.plot(zs.values)
    ax4 = ax1.twinx()
    ax4.plot(data["order_imbal_ratio"].cumsum().values)
    ax2.set_title("mid_price vs imbalratio")
    # ax2.set_yscale("log", nonposy='clip')
    # ax2.set_xlim([30000, 40000])

    plt.show()


def main(st_code="005930"):
    lob_data = call_hdf_bid(st_code, LOB_KEY[3:])
    tr_data = call_hdf_cur(st_code, TR_KEY)
    lob_data.astype(np.int64)
    # lob_data.set_index('datetime', inplace=True, drop=True)
    lob_data = lob_data.apply(np.abs)

    lob_data["midprice"] = (lob_data["offer_01_p"] + lob_data["bid_01_p"]) / 2
    lob_data["delta_md"] = (lob_data['offer_01_p'] - lob_data['offer_01_p'].shift(1)).fillna(0)
    lob_data["delta_ms"] = (lob_data['bid_01_p'] - lob_data['bid_01_p'].shift(1)).fillna(0)
    lob_data["delta_vd"] = np.zeros_like(lob_data['offer_01_p'])
    lob_data["delta_vs"] = np.zeros_like(lob_data['bid_01_p'])

    idx = pd.IndexSlice
    sel_time = idx[:, lob_data["delta_md"] == 0]
    lob_data.loc[sel_time, "delta_vd"] = (lob_data['offer_01_v'] - lob_data['offer_01_v'].shift(1)).fillna(0).loc[sel_time]
    sel_time = idx[:, lob_data["delta_md"] < 0]
    lob_data.loc[sel_time, "delta_vd"] = lob_data['offer_01_v'].loc[sel_time]
    sel_time = idx[:, lob_data["delta_ms"] == 0]
    lob_data.loc[sel_time, "delta_vs"] = (lob_data['bid_01_v'] - lob_data['bid_01_v'].shift(1)).fillna(0).loc[sel_time]
    sel_time = idx[:, lob_data["delta_ms"] > 0]
    lob_data.loc[sel_time, "delta_vs"] = lob_data['bid_01_v'].loc[sel_time]

    lob_data["delta_vd"] = np.zeros_like(lob_data['bid_01_p'])
    sel_time = idx[:, lob_data["delta_md"] == 0]
    lob_data.loc[sel_time, "delta_vd"] = (lob_data['offer_01_v'] - lob_data['offer_01_v'].shift(1)).fillna(0).loc[sel_time]
    sel_time = idx[:, lob_data["delta_md"] < 0]
    lob_data.loc[sel_time, "delta_vd"] = lob_data['bid_01_v'].loc[sel_time]

    lob_data["oi"] = lob_data["delta_vd"] - lob_data["delta_vs"]
    lob_data["order_imbal_ratio"] = (lob_data['offer_01_v'] - lob_data['bid_01_v']) / (lob_data['offer_01_v'] + lob_data['bid_01_v'])

    delta_prc = (lob_data.loc[:, "midprice"] - lob_data.loc[:, "midprice"].shift(1)).fillna(0)
    profit, uxs_pred, uxs_updated, exc_time, err_pred = sim_ukf(lob_data.loc[:, "midprice"])
    draw_result(lob_data, profit, uxs_pred, uxs_updated, exc_time, err_pred)


if __name__ == "__main__":
    main()