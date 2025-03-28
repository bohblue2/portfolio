# 로직의 메인 함수

# Import Known Functions
import pandas as pd
import datetime
import configparser

# Import Private Functions
from .utilities_logic import Utilities
from .config_logic import *
from .regime_detection import DualMomentum
from .method_functions import *
from loguru import logger
from datrobo.util.cipher_mng import Aes256Cipher


# 전략 모클래스 정의
class StrategyLogic():
    def __init__(self):

        # 로거 최초 정의
        logger.add("log/{time:YYYYMMDD}_logic.log", encoding="utf-8")
        try :
            #######################
            # 전략 공통 설정 사항 #
            #######################

            # 유틸리티 함수 불러오기
            self.util = Utilities()

            # DB Connection
            config_file_path = "C:\\config\\config.ini"
            config = configparser.ConfigParser()
            config.sections()
            config.read(config_file_path)

            aes256cipher = Aes256Cipher()
            f = open(config['AES']['key_path'], "r")
            aeskey = f.readline()
            f.close()

            DB_ENDPOINT = aes256cipher.decrypt_str(config['DATABASE']['host'], aeskey)
            DB_PORT = int(aes256cipher.decrypt_str(config['DATABASE']['port'], aeskey))
            DB_ID = aes256cipher.decrypt_str(config['DATABASE']['user'], aeskey)
            DB_PWD = aes256cipher.decrypt_str(config['DATABASE']['password'], aeskey)
            DB_NAME = aes256cipher.decrypt_str(config['DATABASE']['db'], aeskey)


            # 디비 엔진 세팅 (디비 사용 시 넘겨주면서 유용하게 사용)
            self.db_engine = self.util.set_db_engine(DB_ID=DB_ID, DB_PWD=DB_PWD, DB_IP=DB_ENDPOINT,DB_NAME=DB_NAME, DB_PORT=DB_PORT)

            # 한 전략(포트폴리오)에서 관리할 최대 종목 수
            self.nStock = N_STOCK

            # 포트폴리오에서 제외될 조건
            self.nStockOut = N_STOCK_OUT

            # 보유종목, 투자가능종목 비교해 n개 이상 차이가 나면 리밸런싱 실행
            self.regime_chg_num = REGIME_CHG_NUM

            # 리턴 값 소수점 자리수 정의
            self.nRound = N_ROUND

            #
            self.rebal_limit = REBAL_LIMIT_DAY

            # 레짐 디텍터 정의
            self.regime_detector = DualMomentum(self.db_engine)

            # HRP 비중 산출을 위한 과거 데이터 산입 일수
            self.hrp_term = HRP_TERM

            # HRP 메소드
            self.hrp = Hrp_method()

            # 당일 날짜 정의
            todate = datetime.datetime.today()
            self.today = "{0:04d}-{1:02d}-{2:02d}".format(todate.year, todate.month, todate.day)            # 문자열
            self.today_datetime = datetime.datetime(year=todate.year, month=todate.month, day=todate.day)   # datetime 타입

            # 주요 테이블 네임 정의
            self.account_book = ACCOUNT_BOOK
            self.balance = BALANCE
            self.balance_detail = BALANCE_DETAIL
            self.balance_stock = BALANCE_STOCK
            self.code_master = CODE_MASTER
            self.complete_manage = COMPLETE_MANAGE
            self.holiday_table = HOLIDAY_TABLE
            self.rebal_standard_weights = HRP_ACTIVE_WEIGHTS    # 리밸런싱 시 기준이 되는 weight 테이블 (채권이 없는 active 기준)
            self.invest_universe = INVEST_UNIVERSE
            self.kiwoom_day_candle = KIWOOM_DAY_CANDLE
            self.kiwoom_trd_trends = KIWOOM_TRD_TRENDS
            self.spc_trd_time = SPC_TRD_TIME
            self.trade = TRADE

            # 주요 칼럼명 정의
            self.model_weight = MODEL_WEIGHT
            self.actual_weight = ACTUAL_WEIGHT
            self.date = DATE
            self.shtcode = SHTCODE
            self.close_prc = CLOSE_RPC
            self.bclose_prc = BCLOSE_PRC
            self.code_class = CODE_CLASS
            self.rebal_dec = REBAL_DECISION
            self.universe_date = UNIVERSE_DATE
            self.finish_date = FINISH_DATE

            #########################
            # STRATEGY 공통 설정 값 #
            #########################
            self.max_chg_diff = MARGIN_PCT_MAX
            self.avg_chg_diff = MARGIN_PCT_AVG
            self.max_weight = MAX_WEIGHT                    # active 기준 종목당 최대 보유 비중
            self.max_weight_recur_n = MAX_WEIGHT_RECUR_N    # recursive 하게 max weight 산출하는 횟수
            self.max_reabal_term = MAX_REBAL_TERM           # n(90)일 이상 리밸런싱 안했을 경우 강제 리밸런싱 실행하기


            #############################
            # STRATEGY 별 고유 설정 값 #
            #############################

            # 각 전략에서 관리하는 비중의 DB 테이블 이름
            self.weight_table_name = ""
            # 각 전략 현금 보유 비중
            self.cash_ratio = 0.0
            # 각 전략 무위험 자산 보유 비중
            self.rf_ratio = 0.0


        except Exception as e :
            logger.debug("Logic initialization failed")
            logger.debug(str(e))

    # 제일 마지막 종가 입력 받아 리밸런싱 여부 플래그와 종목 비중 반환할 함수
    def calc_weight(self, bprice=None):

        """

        :param bprice: Dictionary {'005930' : price(float), '123456' : price(float), ...}
        :return: Dictionary {'rebalance' : bool, 'weights' : {'005930' : 0.121359, '123456' : 0.556247, ...}}
        """

        # 1) 레짐 디텍터로 상위 15위 trading universe 고르기
        # 2) 선정된 trading universe 에서 HRP 알고리즘으로 목표비중 산출
        # 3) 리밸런싱 여부 플래그 생성
        #   3-1) 직전 리밸런싱한 기존 비중과 목표비중 비교해 기준 비중 이탈 시 T
        #   3-2) 기존 보유하고 있는 종목에서 현재 기준 Dual momentum 순위가 25위 밖으로 밀려나면 T
        #                                     or
        #   3-2) trading universe 와 현재 보유 universe 비교해 2종목 이상 괴리시 T
        # 3) 결론 : 3-1 or 3-2 가 True 이면 True 반환 아니면 False 반환
        # 4) 목표비중과 리밸런싱 플래그 반환

        try :
            # 1) Traing 유니버스 고르기 ()
            ##### 데이터 가져오기

            past_price = self.recall_price_data(self.today)
            bprice = self.dict2Df(bprice)
            whole_data = pd.concat([past_price, bprice])

            ##### 레짐 디텍터로 종목 확인하기 (리스트 가져옴)
            regime_filtered_list = self.regime_detector.check_regime(whole_data, self.today_datetime)


            # 2) 목표 비중 산정하기
            ##### HRP 위한 준비 데이터 가져오기
            hrp_ready_data = whole_data['close_prc'].unstack(level=-1).loc[:self.today_datetime, regime_filtered_list][-self.hrp_term:]
            hrp_result = self.hrp.getHRP(cov= hrp_ready_data.cov(), corr=hrp_ready_data.corr() , link_method="single")

            # 2-0) hrp 결과 중 기준 max weight 초과하는 종목 있으면 비중 재조정 (n회 반복)

            for _ in range(self.max_weight_recur_n) :
                hrp_result = self.get_max_weight_adjust(hrp_result)


            # 2-1) 전략에 따라 현금 비중 추가한 최종 비율 계산하기
            rebal_weights = self.get_cash_adjust_weights(hrp_result)


            # 리밸런싱 할지 말지 여부 결정 ( 3전략 모두 active 최종 리밸런싱 웨이트를 기준으로 의사 결정 내림)
            rebal_decision_flag = self.rebal_decision(rebal_weights)


            # 전략에 따라 최종 채권비율까지 반영해 비율 계산하기
            model_weights = self.get_final_weights(hrp_result)

            # 최종 반환 값 생성
            ret = {'rebalance' : rebal_decision_flag, 'weights' : model_weights}

            return ret

        except Exception as e :
            raise e
            # logger.debug(str(e))
            # return {'rebalance': None, 'weights' : None}
            # raise e


    # 과거 데이터 호출
    def recall_price_data(self, today_date):
        """

        :param today_date: string '0000-00-00'
        :return:
        """
        try :
            query = """
            select `{0}`, `{1}`, `{2}` from {4} 
            where {4}.{1} in
            (select {5}.{1} from {5} where {6} < '{3}' and {7} >= '{3}')
            and {4}.{8} < '{3}'
            and {4}.{8} > '2014-01-01';
            """.format(self.date, self.shtcode, self.close_prc, today_date, self.kiwoom_day_candle,
                       self.invest_universe, self.universe_date, self.finish_date, self.date)

            ret = pd.read_sql(sql=query, con = self.db_engine, index_col=['date', 'shtcode'])

            return ret
        except Exception as e :
            logger.debug(str(e))
            return None

    # bprice 딕셔너리를 희망하는 데이터 프레임 형태로 바꾸기
    def dict2Df(self, bprice):
        """

        :param bprice: 딕셔너리 형태 (키(코드) : 값(가격)
        :return: 멀티인덱스 데이터 프레임에 close_prc 칼럼명을 가진 데이터
        """
        try :
            # 딕셔너리를 datetime을 인덱스로한 데이터 프레임으로 바꾸고 컬럼을 인덱스로 보내 스택하기
            bprice_df = pd.DataFrame(data=bprice, index=[self.today_datetime]).stack()
            bprice_df = bprice_df.to_frame()
            bprice_df.columns = ['close_prc']


            return bprice_df

        except Exception as e:
            logger.debug(str(e))
            return None

    # 시뮬레이션 전용 before price 가져오기
    def recall_bprice_data(self, today_date):
        """

        :param today_date: string '0000-00-00'
        :return:
        """
        try :
            query = """
            select `{0}`,`{1}`,`{2}` as `{3}` from {5} 
            where {5}.{6} in
            (select {7}.{6} from {7} where {8} < '{4}' and {9} >= '{4}')
            and {5}.{0}} = '{4}';
            """.format(self.date,self.shtcode,self.bclose_prc, self.close_prc, today_date,
                       self.kiwoom_day_candle, self.shtcode, self.invest_universe, self.universe_date,
                       self.finish_date)

            ret = pd.read_sql(sql=query, con = self.db_engine, index_col=['date', 'shtcode'])

            return ret

        except Exception as e:
            logger.debug(str(e))
            return None


    # 최대 보유 비중 조절하는 코드
    def get_max_weight_adjust(self, hrp_result):
        """

        :param hrp_result: dictionary {'0000' : 0.0000, ...}
        :return: dictionary {'0000' : 0.0000, ...}
        """
        try :
            ret_dict = {}
            over_weight_count = 0
            over_weight_sum = 0.0

            # 루프 돌면서 max weight 초과하는 종목 찾고 카운팅
            for key, val in hrp_result.items() :
                if val > self.max_weight :
                    over_weight_count += 1
                    over_weight_sum += val


            # 실제 비중 조절해서 넣기
            for key, val in hrp_result.items() :
                if val > self.max_weight :
                    ret_dict[key] = self.max_weight
                else :

                    ret_dict[key] = (val/(1 - over_weight_sum)) * (1 - (over_weight_count * self.max_weight))


            return ret_dict

        except Exception as e:
            logger.debug(str(e))
            return dict()



    # 현금 비중 반영 결과 가져오기
    def get_cash_adjust_weights(self, hrp_result):
        """

        :param hrp_result: dictionary {'0000' : 0.0000, ...}
        :return: dictionary {'0000' : 0.0000, ...}
        """
        try :
            ret_dict = {}

            # 기존 hrp 결과 재조정
            op_ratio = 1 - (self.cash_ratio )
            for key, val in hrp_result.items() :
                ret_dict[key] = round(val * op_ratio, self.nRound)

            # 현금 비중 반영
            ret_dict[CASH_CODE] = self.cash_ratio


            return ret_dict

        except Exception as e:
            logger.debug(str(e))
            return dict()

    # 최종 비중 가져오기 ( 현금 반영된 비중에서, 채권 반영 비중까지 더해서 최종 비중 산정)
    def get_final_weights(self, hrp_result):
        """

        :param hrp_result: dictionary {'0000' : 0.0000, ...}
        :return: dictionary {'0000' : 0.0000, ...}
        """
        try :


            """
            현금만 비중 조정된 상태에서 HRP 순수 결과 원상복구하는 코드이지만
            기존에 hrp_result를 넣으면 필요없어지는 코드
            tmp_dict = {}
            tmp_sum = 0.0
            # 1 cash 만 제외하고 총 비율 합이 1이 되도록 수정
            #   summation 구하기 (cash 제외)
            for key, val in hrp_result.items() :
                if key != CASH_CODE :
                    tmp_sum += val

            #   현금 비중 빼고 비중 다시 조정 ( 현금 빼고 비중 합 1되도록)
            for key, val in hrp_result.items():
                if key != CASH_CODE :
                    tmp_dict[key] = hrp_result[key] / tmp_sum
            """

            ret_dict = {}


            # 기존 hrp 결과 재조정
            op_ratio = 1 - (self.cash_ratio + self.rf_ratio)
            for key, val in hrp_result.items() :
                ret_dict[key] = round(hrp_result[key] * op_ratio, self.nRound)


            # 현금 비중 반영
            ret_dict[CASH_CODE] = 0.07

            # 무위험 자산 비중이 정해져있을때만 코드 추가
            if self.rf_ratio > 0:
                # 무위험 자산 리스트 불러와 채권 비중 반영
                rf_list = self.get_rf_codes()
                n_rf = len(rf_list)     # 채권 종목 수 가져오기

                for idx in rf_list :

                    # rf list 의 채권종목이 hrp_result 안에 있을 경우 더해서 조정하기
                    if idx in hrp_result.keys() :
                        ret_dict[idx] = round( ret_dict[idx] + (self.rf_ratio / n_rf), self.nRound)
                    else :
                        ret_dict[idx] = round( self.rf_ratio / n_rf, self.nRound)


            return ret_dict


        except Exception as e:
            logger.debug(str(e))
            return dict()



    # 무위험 종목 코드 불러오기
    def get_rf_codes(self):

        try :
            query = """
            select {3}.{0} from {3} 
            where {4} < '{1}' and {5} >= '{1}' and `{2}`= '국내채권' ;
            """.format(self.shtcode,self.today, self.code_class, self.invest_universe, self.universe_date, self.finish_date)

            ret_np = pd.read_sql(sql=query, con= self.db_engine).values.squeeze()

            ret_list = list(ret_np)

            return ret_list

        except Exception as e:
            logger.debug(str(e))
            return list()

    # 최종 리밸런싱했던 값과 당일 나온 타겟 웨이트 비교해서 리밸런싱 여부 Flag 반환
    def rebal_decision(self, model_weights):
        """

        :param model_weights: Dictionary {'005930' : weight(float), '123456' : weight(float), ...}
        :return:
        """
        try :
            # 1) 최종 weight 들고오기 (디비에서) active 기준으로 통일
            """
            # select `shtcode`, `target_weight` from hrp_active_weights where `date` = 
            # (select `date` from hrp_active_weights where `rebal_decision` = 1 and `date` < CURDATE() order by `date` desc limit 1); 
            """
            # 1-1) 최초 리밸런싱 여부 확인 쿼리
            pre_weight_query = """
                        select `{2}`, `{1}` from {0} 
                        where `{3}` = (select `{3}` from {0} where `{4}` = 1 and `date` < '{5}' order by `{3}` desc limit 1);
                        """.format(self.rebal_standard_weights, self.model_weight, self.shtcode, self.date,
                                   self.rebal_dec, self.today)
            #### 시리즈 혹은 데이터 프레임으로 받아오기
            pre_weights = pd.read_sql(sql=pre_weight_query, con=self.db_engine, index_col='shtcode')

            # 1-2) 최근 90일 리밸런싱 여부 확인 쿼리
            """
            # select `shtcode`, `target_weight` from hrp_active_weights
            # where `date` > ADDDATE(CURDATE(), -90) and `date` < CURDATE() and `rebal_decision` = 1 ;
            """
            pre_weight_query_90 = """
                        select `{2}`, `{1}` from {0} 
                        where `{3}` > ADDDATE('{6}', -{5}) and `{3}` < '{6}' and `{4}` = 1 ;
                        """.format(self.rebal_standard_weights, self.model_weight, self.shtcode, self.date,
                                   self.rebal_dec, self.max_reabal_term, self.today)
            #### 시리즈 혹은 데이터 프레임으로 받아오기
            pre_weights_90 = pd.read_sql(sql=pre_weight_query_90, con=self.db_engine, index_col='shtcode')



            # 2) 최초 실행으로 이전 리밸런싱 내역이 없을 경우 -> 무조건 리밸런싱 실행
            if len(pre_weights) == 0 or len(pre_weights_90) == 0 :
                final_flag = True

            else :

                # 1-1) 최근 n 일간 리밸런싱 있을 경우 리밸런싱 안하도록 하기 위한 쿼리 작성
                #   최근 n영업일의 날짜 시리즈 가져오기
                n_op_date_query = """
                            select distinct `{2}` from {0} order by `{2}` desc limit {1}; 
                            """.format(self.weight_table_name, self.rebal_limit, self.date)

                op_date_df = pd.read_sql(sql=n_op_date_query, con=self.db_engine)
                op_date_list = op_date_df.values.squeeze().tolist()

                #   최근 리밸런싱한 날짜 시리즈 가져오기
                recent_rebal_date_query = """
                            select `{2}` from {0} where `{1}` = 1 order by `{2}` desc limit 1;
                            """.format(self.weight_table_name, self.rebal_dec, self.date)
                recent_rebal_df = pd.read_sql(sql=recent_rebal_date_query, con=self.db_engine)
                recent_rebal_value = recent_rebal_df.values[0][0]


                if recent_rebal_value in op_date_list :

                    final_flag = False

                else :

                    # 4) weight 비교 하기 (별도 함수 만들어서 어느정도로 비교할지 결정)
                    weight_rabal_flag = self.compare_weights(pre_weights, model_weights)

                    # 5) regime detector 나온 투자유니버스와 현재 보유종목 비교해 리밸런싱 여부 결정
                    posses_list = pre_weights.index.to_list()       # 마지막 투자 리스트
                    invst_list = list(model_weights.keys())         # 모델 weight의 투자 리스트
                    regime_rabal_flag = self.regime_chg_check(posses_list, invst_list)

                    # 6) 최종 플래그 산출
                    if weight_rabal_flag or regime_rabal_flag :
                        final_flag = True
                    else :
                        final_flag = False

            return final_flag

        except Exception as e:
            logger.debug(str(e))
            return False


    #  두 딕셔너리 weight 값 비교해 플래그 발생
    def compare_weights(self, pre_weights, model_weights):
        """

        :param pre_weights:  Dataframe : index = ['000000','111111',...], data =[[0.0000],[0.1111],[0.2222],..]
        :param model_weights:  Dictionary {'005930' : weight(float), '123456' : weight(float), ...}
        :return: rebalancing 여부 flag (boolean)
        """
        try :
            # 비교 가능하도록 데이터 타입 통일하기
            # 1) model_weights 를 df 로 바꾸기
            common_col_name = 'weight'
            model_weights_df = pd.DataFrame.from_dict(data=model_weights, orient='index', columns=[common_col_name])

            # 2) 두 데이터 프레임 모두 칼럼명 통일
            pre_weights.columns = [common_col_name]

            # 키가 같은 값 끼리 매칭 해서 weight 차이 값을 모두 구하기 (키 값이 완전 일치하지 않을 수 있음)
            # 1) 중복되는 교집합 코드 구하기
            inter_codes = list(set(model_weights_df.index).intersection(set(pre_weights.index)))
            # 2) 최대 변경치구하기 (%p)
            max_diff_chg = abs(model_weights_df[inter_codes] - pre_weights[inter_codes]).max()
            # 3) 평균 변경치 구하기 (%p)
            avg_diff_chg = abs(model_weights_df[inter_codes] - pre_weights[inter_codes]).mean()


            # 최대값 혹은 평균치 중 하나가 기준을 초과하면  True  / O.W : False
            if max_diff_chg > self.max_chg_diff or avg_diff_chg > self.avg_chg_diff :
                weight_rebal = True
            else :
                weight_rebal = False

            return weight_rebal

        except Exception as e:
            logger.debug(str(e))
            return None


    # 투자 유니버스 변동에 따른 리밸런싱 여부 결정 하기
    def regime_chg_check(self,posses_list, invst_list):
        """

        :param posses_list: 현재 보유하고 있는 종목 (list)
        :param invst_list: regime detector 에서 제시하는 투자가능종목 (list)
        :return:
       """
        try :
            # 두 input 을 비교해서 invst_list 종목 수 - 교차종목수가 n 개 이상인 경우 True 반환
            inter_codes = list(set(posses_list).intersection(set(invst_list)))

            # 레짐 변경 구하기
            if len(invst_list) - len(inter_codes) > self.regime_chg_num :
                regime_rebal = True
            else :
                regime_rebal = False

            return regime_rebal

        except Exception as e:
            logger.debug(str(e))
            return None

class HRP_Active(StrategyLogic):
    def __init__(self):
        super(__class__, self).__init__()
        # 전략에서 관리하는 비중의 DB 테이블 이름
        self.weight_table_name = HRP_ACTIVE_WEIGHTS
        # 각 전략 현금 보유 비중
        self.cash_ratio = CASH_RATIO_ACTIVE
        # 각 전략 무위험 자산 보유 비중
        self.rf_ratio = BOND_RATIO_ACTIVE

class HRP_Neutral(StrategyLogic):
    def __init__(self):
        super(__class__, self).__init__()
        # 전략에서 관리하는 비중의 DB 테이블 이름
        self.weight_table_name = HRP_NEUTRAL_WEIGHTS
        # 각 전략 현금 보유 비중
        self.cash_ratio = CASH_RATIO_NEUTRAL
        # 각 전략 무위험 자산 보유 비중
        self.rf_ratio = BOND_RATIO_NEUTRAL

class HRP_Stable(StrategyLogic):
    def __init__(self):
        super(__class__, self).__init__()
        # 전략에서 관리하는 비중의 DB 테이블 이름
        self.weight_table_name = HRP_STABLE_WEIGHTS
        # 각 전략 현금 보유 비중
        self.cash_ratio = CASH_RATIO_STABLE
        # 각 전략 무위험 자산 보유 비중
        self.rf_ratio = BOND_RATIO_STABLE