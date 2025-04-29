# Configurations

N_STOCK = 15            # 한 전략에서 관리할 종목 수
MIN_STOCK = 7           # 한 전략 최소 보유수량
N_STOCK_OUT = 25        # 기존 선정된 종목에서 이 등수 뒤로 밀려나면 리밸런싱 실행


MARGIN_PCT_AVG = 0.05    # 기존비중과 목표비중의 차이가 평균 값이 MARGIN PCT 이상 났을때 리밸런싱 실행
MARGIN_PCT_MAX = 0.2    # 기존비중과 목표비중의 차이가 최대 값이 MARGIN PCT 이상 났을때 리밸런싱 실행
REGIME_CHG_NUM = 4      # Regime Detector 로 확인되어 종목 변경해야할 종목이 REGIME_CHG_NUM 이상일 때만 리밸런싱 실행

MAX_REBAL_TERM = 90     # n(90)일 이상 리밸런싱 안했을 경우 강제 리밸런싱 실행하기





######
# 전략/ 모멘텀 관련 설정
##########
MOMENTUM_TERM = 5       # 모멘텀 산정시 데이터 관찰 주기 (5일일경우 일주일로 봄)
MOMENTUM_LAG = 5        # 모멘텀 계산 시 몇 주기 뒤까지 계산할 것인지

HRP_TERM = 90           # HRP 계산시 과거 데이터 산입 일수

REBAL_LIMIT_DAY = 5     # 최저 재 리밸런싱 일수 ( 최소 n 일이 지나야 다시 리밸런싱 가능하도록 설정)


############################
# 기본 비중 관련 세팅 정보 #
############################

# 현금 비중
CASH_RATIO_ACTIVE   = 0.07
CASH_RATIO_NEUTRAL  = 0.07
CASH_RATIO_STABLE   = 0.07
CASH_CODE = '00cash'


# 무위험자산(채권) 비중
BOND_RATIO_ACTIVE   = 0.0
BOND_RATIO_NEUTRAL  = 0.3
BOND_RATIO_STABLE   = 0.6


# 기타
N_ROUND = 4         # 비중 반환값 소수점자리수
MAX_WEIGHT = 0.2    # Active 기준 종목 당 최대 보유 비중
MAX_WEIGHT_RECUR_N = 4      # max weight 계산할 때 recursive 하게 계산하는 횟수

# 주요 테이블 네임 정의
ACCOUNT_BOOK = 'account_book'
BALANCE = 'balance'
BALANCE_DETAIL = 'balance_detail'
BALANCE_STOCK = 'balance_stock'
CODE_MASTER = 'code_master'
COMPLETE_MANAGE = 'complete_manage'
HOLIDAY_TABLE = 'holiday_table'
HRP_ACTIVE_WEIGHTS = 'hrp_active_weights'
HRP_NEUTRAL_WEIGHTS = 'hrp_neutral_weights'
HRP_STABLE_WEIGHTS = 'hrp_stable_weights'
HRP_NEUTRAL_WEIGHTS_SAMPLE = 'hrp_neutral_weights_sample'
INVEST_UNIVERSE = 'invest_universe_ver_03'
KIWOOM_DAY_CANDLE = 'kiwoom_day_candle'
KIWOOM_TRD_TRENDS = 'kiwoom_trd_trends'
SPC_TRD_TIME = 'spc_trd_time'
TRADE = 'trade'

# 주요 칼럼 명 정의
ACTUAL_WEIGHT = "current_weight"     # 현재 포트폴리오의 비중 값
MODEL_WEIGHT = "target_weight"      # 매일 산출하는 목표 비중 값
DATE = 'date'                       # 날짜 0000-00-00
SHTCODE = 'shtcode'                 # 종목 코드 6자리 000000
CLOSE_RPC = 'close_prc'             # 일봉의 종가
BCLOSE_PRC = 'bclose_prc'           # 일봉의 장마감 동시호가 직전 종가
CODE_CLASS = '콤비'                 # 투자 종목의 종류(채권, 원자재, 외환 등)
REBAL_DECISION = 'rebal_decision'   # 리밸런싱 했는지 여부
UNIVERSE_DATE = 'universe_date'     # 유니버스 재지정한 날짜
FINISH_DATE = 'finish_date'         # 지정한 유니버스의 마지막 적용 날짜