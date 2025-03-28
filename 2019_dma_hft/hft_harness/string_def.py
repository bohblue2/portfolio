
class QueStr:
    DATA = "data"
    ORDER = "order"
    COM = "com"
    MAIN = "main"
    STG = "strategy"
    ST = "stock"


class DataBase:
    USR = "DB_ID"
    PWD = "DB_PWD"
    URL = "DB_IP"
    PORT = "DB_PORT"
    DB = "DB_NAME"


class TradeType:
    BID = "bid"
    ASK = "ask"


class StgInfo:
    ID = "id"
    MNT_STKS = "monitoring_stocks"
    TOT_DEPS = "total_deposite"

class InitParam:
    """
    # init json format
        "strategy"
        "balance"
        "manage_funds"
        "manage_weights"
    """
    STG = "strategy"
    BAL = "balance"
    MNG_FUND = "manage_funds"
    MNG_WGHT = "manage_weights"


class StgInfo:
    ID = "id"
    MNT_STKS = "monitoring_stocks"
    TOT_DEPS = "total_deposite"
    HOLD_STKS = "holding_stocks"


class DataName:
    # --- Data ---
    DATA    = "data"
    RT_TICK = "rt_tick"
    RT_QUOTE = "rt_quote"
    RT_CHART = "rt_chart"
    SPOT    = "spot"
    CHART   = "chart"
    BALANCE = "balance"
    # --- Cp Conclusion ---
    CCLN    = "conclusion"
    RT_CCLN = "rt_conclusion"


class Interval:
    SEC = "s"
    MIN = "m"
    HOUR = "h"
    DAY = "d"
    TICK = "t"


class StgSetting:
    STRATEGYID = ""
    STOCKS = []
    TDUNIT = 60
    INTERVAL = 0
    NUMBARS = 0

