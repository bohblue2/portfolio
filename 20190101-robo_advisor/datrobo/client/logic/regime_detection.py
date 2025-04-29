#  Regime Detection 로직에 맞춰서 종목 발굴 해주는 method
import pandas as pd
from .config_logic import *

class RegimeDetector():
    def check_regime(self):
        return

class DualMomentum():

    def __init__(self, db_engine):
        # 함수로부터 DB 엔진 객체 받기
        self.db_engine = db_engine

        # 모멘텀 설정값
        self.term = MOMENTUM_TERM
        self.lag = MOMENTUM_LAG
        self.nstock = N_STOCK
        self.minStock = MIN_STOCK

    def check_regime(self, price_data, today, trading=True):
        """

        :param past_price: DB 에서 불러온 과거 데이터 + 당일 bprice 데이터            (모든 invest universe)  Dataframe
        :param today: 오늘 날짜 전달 '0000-00-00'
        :param trading: 실제 트레이딩 -> True, 백테스팅 -> False
        :return: list of codes
        """


        # 코드 그룹별로 조화평균 모멘텀 산출
        price_data['momentum'] = self.calc_momentum(price_data, lag = self.lag, term = self.term)

        # 당일 날짜 투자 유니버스의 가격, 모멘텀 확인
        momentum_data = price_data.loc[(today,)]

        # 절대 및 상대모멘텀으로 거르기
        filtered_data = self.filter_momentum(momentum_data=momentum_data)


        return filtered_data


    # 멀티인덱스 데이터 프레임으로 그룹별로 모멘텀 구하기
    def calc_momentum(self, df, lag = 5, term = 5):

        df['momentum'] = 1.0

        for i in range(1, lag+1) :

            df['momentum'] *= df['close_prc'].groupby(level=1).pct_change(i * term) + 1


        return df['momentum'] **( 1/lag)



    # 모멘텀 결과 dataframe으로 trading universe 리스트 산출
    def filter_momentum(self, momentum_data):

        """

        :param momentum_data: dataframe (single index, with momentum column)
        :return: ['000000','000000']
        """

        # 1) 순위 매기기
        momentum_data['rank'] = momentum_data['momentum'].rank(ascending=False)

        # 2) 절대 모멘텀으로 거르기
        filtered_data = momentum_data[momentum_data['momentum'] > 1.0]

        # 3) 결과 확인 후 상대 모멘텀으로 거르기
        #   절대 모멘텀으로 거른 데이터가 최소 수량 이하 일 경우 상대모멘텀 데이터를 불러와서 최소수량 채우기
        if filtered_data.shape[0] <= self.minStock:
            filtered_data = momentum_data.sort_values('rank')[:self.minStock]

        #   절대 모멘텀으로 거른 데이터가 최소 수량 초과, 관리 수량 이하일 경우 패스
        elif filtered_data.shape[0] <= self.nstock :
            pass

        #   절대 모멘텀으로 거른 데이터가 관리 수량 초과할 경우 관리 수량 기준으로 잘라주기
        else :
            filtered_data = filtered_data.sort_values('rank')[:self.nstock]


        return list(filtered_data.index)


