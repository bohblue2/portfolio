import pytz
import time
import queue
import threading
import configparser
import math
import inspect
import datetime

from abc import (
    ABCMeta,
    abstractmethod
)

from apscheduler.schedulers.background import BackgroundScheduler
from apscheduler.events import EVENT_JOB_EXECUTED, EVENT_JOB_MISSED, EVENT_JOB_ERROR

from retrying import retry
from websocket._exceptions import WebSocketTimeoutException

from datrobo.client.common.database import Database
from datrobo.client.common.thd_safe_dict import ThreadSafeDict
from datrobo.client.data_mng.data_mng_def import MarketType, KeyName, COMMAND
from datrobo.client.logic import config_logic

from loguru import logger
from datrobo.util.telegram_api import Telegram

from dattoolbox.robo.agent import RoboAdvisor

bclose_lock = threading.Lock()
all_bclose_dict = ThreadSafeDict()  # 전체 ETF 종목에 대한 bclose
ivst_bclose_dict = ThreadSafeDict()  # 투자 유니버스에 대한 bclose

class HrpAgent(RoboAdvisor, threading.Thread):
    def __init__(self, unique_id, model,
                 account_num, model_portfolio, mutex,
                 event_queue, config_file_path):
        RoboAdvisor.__init__(self, unique_id, model)
        threading.Thread.__init__(self, name=unique_id)

        # 타임존
        self.timezone = None

        # 뮤텍스 (주문시 스레드 동기화)
        self.mutex = mutex

        # 이벤트 큐 (월드 모델로부터(월드 모델의 step() 메소드) 오는 이벤트)
        self.event_queue = event_queue

        # 모델 포트폴리오 객체
        self.model_portfolio = model_portfolio

        # 실제 포트폴리오 포지션들의 현재가(Cache)
        self.actual_portfolio_price = dict()

        # 목표 포트폴리오 비중 (next) MP
        self.model_portfolio_weight = dict()
        # 실제 포트폴리오 비중 (prev) AP
        self.actual_portfolio_weight = dict()
        # 목표 포트폴리오 포지션(매입금액) MP
        self.model_portfolio_position = dict()
        # 실제 포트폴리오 포지션(종목수량) AP
        self.actual_portfolio_position = dict()

        # 최종 매수 비중
        self.final_buy_weight = dict()
        # 최종 매도 비중
        self.final_sell_weight = dict()
        # 최종 매수 포지션
        self.final_buy_position = dict()
        # 최종 매도 포지션
        self.final_sell_position = dict()

        # 계좌 정보
        self.account = dict()
        self.account = {'account_num': account_num,
                        '추정예탁자산': -1,
                        '100%종목주문가능금액': -1}

        # 리밸런싱 정보, TODO: 메타오더 도입
        self.rebalance_result = False
        self.rebalance_flag = False

        # 현재 날짜, TODO: Timer, MarketCalender 도입.
        self.date_current = None
        self.date_last_unfilled = None

        # TODO: 이벤트 리스너 구성
        regular_events = [
            #(self._before_open_market, '08:50:00'),
            #(self._on_open_market, '09:00:00'),
            #(self._after_open_market, '09:10:00'),
            (self._before_close_market, '15:20:30'),
            (self._on_close_market, '15:30:30'),
            (self._after_close_market, '15:40:00')
        ]

        # Apscheduler Scheduler
        tz = pytz.timezone('Asia/Seoul')
        self.scheduler = BackgroundScheduler(timezome=tz)
        self.scheduler.start()
        for func, time in regular_events:
            hour, minute, sec = time.split(':')
            self.scheduler.add_job(
                func=func,
                trigger='cron',
                day_of_week='mon-fri', # fri
                hour=hour,
                minute=minute,
                second=sec
            )
        self.scheduler.add_listener(self._cron_listener, EVENT_JOB_EXECUTED | EVENT_JOB_MISSED | EVENT_JOB_ERROR)

        # config.ini의 경로 (임시로 넣었습니다)
        self.config_file_path = config_file_path
        config = configparser.ConfigParser()
        config.sections()
        config.read(self.config_file_path)
        self.telegram = Telegram(*[
            config["TELEGRAM"]["token"],
            config["TELEGRAM"]["chat_id"]
        ])

    def _cron_listener(self, event):
        if event.exception:
            msg = "hrp.py에서 작업 실행중 예외 발생"
            logger.exception(msg)
            self.telegram.send_message(msg)

        else:
            if EVENT_JOB_EXECUTED == event.code:
                logger.info("EVENT_JOB_EXECUTED")

            elif EVENT_JOB_MISSED == event.code:
                now = datetime.datetime.now() + datetime.timedelta(seconds=5)
                job = self.scheduler.get_job(event.job_id)
                msg = "hrp.py에서 작업 실행중 Missing 발생. 5초 후 재실행 (Func: {0})".format(job.func_ref)
                logger.error(msg)
                self.telegram.send_message(msg)

                func = job.name.replace(self.__class__.__name__, "self")

                new_job = self.scheduler.add_job(
                    eval(func),
                    "cron",
                    hour=now.hour,
                    minute=now.minute,
                    second=now.second,
                    args=job.args
                )
                logger.info(new_job)

            elif EVENT_JOB_ERROR == event.code:
                job = self.scheduler.get_job(event.job_id)
                msg = "hrp.py에서 작업 실행중 Error 발생 (Func: {0})".format(job.func_ref)
                logger.error(msg)
                self.telegram.send_message(msg)

    def run(self):
        # TEST 용
        # self._before_close_market()
        # self._after_close_market()
        # TODO: Thread Stop Signal(Conditional)

        logger.info("{}: 변수 초기화 완료. 주문 집행 모듈 정상 가동".format(self.unique_id))
        self.telegram.send_message("{}: 변수 초기화 완료. 주문 집행 모듈 정상 가동".format(self.unique_id))

        while True:
            try:
                event = self.event_queue.get()
                self.step(event)
            except queue.Empty:
                time.sleep(0.1)

    def step(self, event):
        # TODO: Finite State Machine Code
        # print("event:", event)
        pass

    def _initialize(self):

        logger.info("{}: 변수 초기화 시작.".format(self.unique_id))
        self.telegram.send_message(
            "{}/{}: 변수 초기화 시작."
                .format(self.unique_id, inspect.currentframe().f_code.co_name)
        )

        # 목표 포트폴리오 비중 (next) MP
        self.model_portfolio_weight = dict()
        # 실제 포트폴리오 비중 (prev) AP
        self.actual_portfolio_weight = dict()
        # 목표 포트폴리오 포지션(매입금액) MP
        self.model_portfolio_position = dict()
        # 실제 포트폴리오 포지션(종목수량) AP
        self.actual_portfolio_position = dict()

        # 최종 매수 비중
        self.final_buy_weight = dict()
        # 최종 매도 비중
        self.final_sell_weight = dict()
        # 최종 매수 포지션
        self.final_buy_position = dict()
        # 최종 매도 포지션
        self.final_sell_position = dict()

        logger.info("{}: 변수 초기화 완료.".format(self.unique_id))
        self.telegram.send_message("{}: 변수 초기화 완료.".format(self.unique_id))

    # 정규 시장 시작 n분 전 (BOM)
    def _before_open_market(self):
        try:
            self._initialize()
            # 미체결 매수종목 로드
            with Database(self.config_file_path) as dg:
                model_weight = {}
                actual_weight = {}
                ret = dg.select_unfilled_trd_stock(self.unique_id + "_" + "weights") # "hrp_active_weights"
                if len(ret) > 0:
                    for row in ret:
                        (date, shtcode, target_weight, current_weight) = row
                        model_weight[shtcode] = target_weight
                        actual_weight[shtcode] = current_weight
                        self.date_last_unfilled = date

                        logger.info(
                            "{}: 미체결 매수 종목 {}"
                                .format(self.unique_id, row)
                        )

                        self.telegram.send_message(
                            "{}/{}: 미체결 매수 종목 {}"
                                .format(self.unique_id, inspect.currentframe().f_code.co_name, row)
                        )

                    # 미체결 매수종목 리밸런싱 비중 계산
                    (self.final_buy_weight,
                     self.final_sell_weight,
                     self.final_buy_position,
                     self.final_sell_position) = self._get_rebalance_weight(
                        model_weight=model_weight,
                        actual_weight=actual_weight,
                        account=self.account
                    )
                else:
                    pass # 현재 기준 미체결 매수종목이 존재하지 않음.

        except Exception as err:
            raise err

    # 정규 시장 시작 (OOM)
    def _on_open_market(self):
        # 미체결 매수종목 매수
        if self.date_last_unfilled != None:
            if self.final_buy_position != None and \
               self.final_sell_position!= None:
                self.rebalance_result = self._do_rebalance(
                    self.final_buy_position,
                    self.final_sell_position
                )

        logger.info(
            "{}: 미체결 매수 종목 리밸런싱 시작"
                .format(self.unique_id)
        )

        self.telegram.send_message(
            "{}/{}: 미체결 매수 종목 리밸런싱 시작"
                .format(self.unique_id, inspect.currentframe().f_code.co_name)
        )

    # 정규 시장 시작 n분 후 (AOM)
    def _after_open_market(self):
        if self.date_last_unfilled != None:
            execution_result = dict()

            response = self._get_position(self.account)
            if isinstance(response, dict):
                single_data = response.get('data', {}).get('msg', {}).get('single', None)
                tot_value = 0
                if single_data is not None:
                    tot_value = int(single_data['추정예탁자산'])

                response = response.get('data', {}).get('msg', {}).get('multi', None)
                if response != None:
                    for position in response:
                        stcode_parsed = str(position['종목번호'])[1:] if str(position['종목번호']).startswith("A") else str(position['종목번호'])
                        quantity        = int(position['보유수량'])

                        if 0 < tot_value:
                            actual_weight = round((int(position['평가금액']) - int(position['평가수수료']) - int(position['세금'])) / tot_value, 4)
                        else:
                            actual_weight = 0

                        if round(self.model_portfolio_weight[stcode_parsed], 4) == round(actual_weight, 4):
                            # 모델 포트폴리오와 비중이 다름 (비정상)
                            execution_result[stcode_parsed]['exec_success'] = 0
                            execution_result[stcode_parsed]['actual_weight'] = actual_weight
                        else:
                            # 모델 포트폴리오와 비중이 같음 (정상)
                            execution_result[stcode_parsed]['exec_success'] = 1
                            execution_result[stcode_parsed]['actual_weight'] = actual_weight

            with Database(self.config_file_path) as dg:
                table = self.unique_id + "_" + "weights"
                for k, v in execution_result.items():
                    data = [
                        v['exec_success'],      # 주문 집행 성공 여부 (True/False)
                        v['actual_weight'],     # 현재 비중
                        self.date_last_unfilled,# 주문 집행이 실패한 마지막날
                        k                       # 종목 번호
                    ]

                    logger.info(
                        "{}: 미체결 매수 종목 업데이트 {}"
                            .format(self.unique_id, data)
                    )

                    self.telegram.send_message(
                        "{}/{}: 미체결 매수 종목 업데이트 {}"
                            .format(self.unique_id, inspect.currentframe().f_code.co_name, data)
                    )

                    dg.update_unfilled_trd_stock(table, data)

    # 정규 시장 종료 n분 전 (BCM)
    def _before_close_market(self):
        # 리밸런싱 시작

        self._initialize()

        logger.info("{}: 리밸런싱 시작".format(self.unique_id))
        self.telegram.send_message("{}: 리밸런싱 시작".format(self.unique_id))

        # bclose 수신
        bclose_lock.acquire()

        global all_bclose_dict
        global ivst_bclose_dict

        if 0 == len(all_bclose_dict):
            invest_universe = []

            # DB에서 투자 유니버스를 가져옴
            with Database(self.config_file_path) as dg:
                invest_universe = dg.get_invest_universe()

            master_info = self._get_master(MarketType.ETF)
            shtcodes = []

            if KeyName.DATA in master_info and KeyName.MSG in master_info[KeyName.DATA]:
                msg = master_info[KeyName.DATA][KeyName.MSG]

                # Err Chk
                if int == type(msg) and -1 == msg:
                    logger.error("[HrpAgent::_before_close_market] 잘못된 값 수신1 (수신한값: {0})".format(master_info))
                    # TODO : 에러처리 해야함
                    pass

                cmd = master_info[KeyName.DATA][KeyName.REQ_CMD].split(" ")
                main_cmd = cmd[0]
                chunk = 100
                mk_kind_stock = 0  # 주식

                if COMMAND.GET_MASTER == main_cmd:
                    for shtcode, data in msg.items():
                        shtcodes.append(shtcode)

                    shtcode_cnt = len(shtcodes)
                    req_cnt = math.ceil(shtcode_cnt / chunk)  # 몇번 요청해야되나

                    for i in range(req_cnt):
                        st_idx = chunk * i
                        ed_idx = st_idx + chunk
                        ed_idx = ed_idx if ed_idx < shtcode_cnt else shtcode_cnt
                        req_codes = shtcodes[st_idx:ed_idx]
                        rcv_items = self._get_multi_items(req_codes, ed_idx - st_idx, mk_kind_stock)

                        if KeyName.DATA in rcv_items and KeyName.MSG in rcv_items[KeyName.DATA] and KeyName.MULTI in rcv_items[KeyName.DATA][KeyName.MSG]:
                            rows = rcv_items[KeyName.DATA][KeyName.MSG][KeyName.MULTI]

                            for row in rows:
                                rcv_shtcode = row["종목코드"]
                                bclose = abs(int(row["현재가"]))

                                all_bclose_dict[rcv_shtcode] = bclose

                                if rcv_shtcode in invest_universe:
                                    ivst_bclose_dict[rcv_shtcode] = bclose

            else:
                logger.error("[HrpAgent::_before_close_market] 잘못된 값 수신2 (수신한값: {0})".format(master_info))
                # TODO : 에러처리 해야함
                pass

        bclose_lock.release()

        logger.debug("{}: all {}".format(
            self.unique_id,
            all_bclose_dict
        ))
        logger.debug("{}: ivst {}".format(
            self.unique_id,
            ivst_bclose_dict
        ))

        # 서버 상태 확인
        server_stat = self._get_server_status()
        if server_stat == True:
            logger.info("{}: Server is alive".format(self.unique_id))

            # TODO:이부분 바꿔야됨.
            get_account = self._get_account(account=self.account, columns=['100%종목주문가능금액'])
            get_balance = self._get_balance(account=self.account, columns=['추정예탁자산'])
            self.account.update({
                    '100%종목주문가능금액': get_account['100%종목주문가능금액'],
                    '추정예탁자산': get_balance['추정예탁자산']
            })

            logger.info("{}: 추정예탁자산 {}".format(
                self.unique_id,
                self.account['추정예탁자산']
            ))
            self.telegram.send_message("{}: 추정예탁자산 {}".format(
                self.unique_id,
                self.account['추정예탁자산']
            ))

            logger.info("{}: 100%종목주문가능금액 {}".format(
                self.unique_id,
                self.account['100%종목주문가능금액']
            ))
            self.telegram.send_message("{}: 100%종목 주문 가능 금액 {}".format(
                self.unique_id,
                self.account['100%종목주문가능금액']
            ))

            # 실제 포트폴리오 포지션(비중) 업데이트
            actual_position = self._get_position(self.account)
            if isinstance(actual_position, dict):
                logger.debug("{}: actual_position_parsed".format(self.unique_id))

                single_data = actual_position.get('data', {}).get('msg', {}).get('single', None)
                tot_value = 0
                if single_data is not None:
                    tot_value = int(single_data['추정예탁자산'])

                actual_position_parsed = actual_position.get('data', {}).get('msg', {}).get('multi', None)
                if actual_position_parsed is not None and (len(actual_position_parsed) > 0):
                    for position in actual_position_parsed:
                        stcode_parsed = str(position['종목번호'])[1:] if str(position['종목번호']).startswith("A") else str(position['종목번호'])

                        if 0 < tot_value:
                            self.actual_portfolio_weight[stcode_parsed] = round((int(position['평가금액']) - int(position['평가수수료']) - int(position['세금'])) / tot_value, 4)
                        else:
                            self.actual_portfolio_weight[stcode_parsed] = 0

                        self.actual_portfolio_position[stcode_parsed]= int(position['매매가능수량'])
                        self.actual_portfolio_price[stcode_parsed]   = int(position['현재가'])

                    logger.info("{}: 실제 포트폴리오 비중: {}".format(
                        self.unique_id,
                        self.actual_portfolio_weight
                    ))
                    self.telegram.send_message("{}: 실제 포트폴리오 비중: {}".format(
                        self.unique_id,
                        self.actual_portfolio_weight
                    ))

                else:
                    # 현재 가지고있는 포지션이 없거나 API 가 제대로 작동하지 않는것
                    logger.error("{}: 실제 포트폴리오 파싱 실패".format(self.unique_id))


                # 모델 포트폴리오 포지션(비중) 업데이트
                model_weight = self._get_model_weight(ivst_bclose_dict)
                if (model_weight.get('rebalance', None) == True):
                    self.rebalance_flag = True
                    self.model_portfolio_weight = model_weight.get('weights', None)
                    logger.info("{}: 모델 포트폴리오 비중: {}".format(
                        self.unique_id,
                        self.model_portfolio_weight
                    ))
                    self.telegram.send_message("{}: 모델 포트폴리오 비중: {}".format(
                        self.unique_id,
                        self.model_portfolio_weight
                    ))

                    if (self.model_portfolio_weight != None):

                        logger.info("{}: 모델 포트폴리오와 실제 포트폴리오의 비중 차이 계산".format(self.unique_id))
                        self.telegram.send_message("{}: 모델 포트폴리오와 실제 포트폴리오의 비중 차이 계산".format(self.unique_id))

                        # 리밸런싱에 필요한 비중 계산
                        (self.final_buy_weight,
                         self.final_sell_weight,
                         self.final_buy_position,
                         self.final_sell_position) = self._get_rebalance_weight(
                            self.model_portfolio_weight,
                            self.actual_portfolio_weight,
                            self.account
                        )

                        logger.info("{}: 데이터베이스에 모델 포트폴리오 비중 업데이트 시작".format(self.unique_id))
                        self.telegram.send_message("{}: 데이터베이스에 모델 포트폴리오 비중 업데이트 시작".format(self.unique_id))
                        with Database(self.config_file_path) as dg:
                            for symbol, weight in self.model_portfolio_weight.items():
                                table = self.unique_id + "_" + "weights"
                                now = (datetime.datetime.now()).strftime("%Y-%m-%d")
                                # TODO: 00cash 를 `code master` 테이블에 강제로 집어넣었음.
                                shtname = dg.select_shtname(symbol)

                                tfinal_weight = weight
                                try:
                                    tfinal_position = int((self.account['추정예탁자산'] * weight) / all_bclose_dict[symbol])
                                except KeyError as err:
                                    tfinal_position = 0
                                try:
                                    tapfinal_weight = self.actual_portfolio_weight[symbol]
                                except KeyError as err:
                                    tapfinal_weight = 0

                                data = [
                                    now,
                                    str(symbol),
                                    str(shtname['name']),
                                    float(tfinal_weight),
                                    int(tfinal_position),
                                    float(tapfinal_weight),
                                    0,
                                    1
                                ]

                                logger.info(
                                    "{}: 모델 포트폴리오 비중 업데이트 {}"
                                        .format(self.unique_id, data)
                                )
                                self.telegram.send_message(
                                    "{}/{}: 모델 포트폴리오 비중 업데이트 {}"
                                        .format(self.unique_id, inspect.currentframe().f_code.co_name, data)
                                )

                                dg.insert_weight(table, data)

                        logger.info(
                            "{}: 데이터베이스에 모델 포트폴리오 비중 업데이트 완료"
                                .format(self.unique_id)
                        )
                        self.telegram.send_message(
                            "{}/{}: 데이터베이스에 모델 포트폴리오 비중 업데이트 완료"
                                .format(self.unique_id, inspect.currentframe().f_code.co_name)
                        )

                        logger.debug("{}: 모델 포트폴리오와 실제 포트폴리오 비중 차이 계산 완료.\n " \
                                     "최종 매수 비중: {} \n" \
                                     "최종 매도 비중: {} \n" \
                                     "최종 매수 포지션: {} \n" \
                                     "최종 매도 포지션: {} \n".format(
                            self.unique_id,
                            self.final_buy_weight,
                            self.final_sell_weight,
                            self.final_buy_position,
                            self.final_sell_position
                        ))

                        # 주문 집행 실행
                        self.rebalance_result = self._do_rebalance(
                            self.final_buy_position,
                            self.final_sell_position,
                            self.account
                        )
                    else:
                        # 모델 포트폴리오 포지션(비중) 값이 정상적으로 입력되지 않음
                        logger.info(
                            "{}: 모델 포트폴리오 비중 값이 정상적으로 입력되지 않음: {}."
                                .format(self.unique_id, self.model_portfolio_weight)
                        )
                        self.telegram.send_message(
                            "{}/{}: 모델 포트폴리오 비중 값이 정상적으로 입력되지 않음: {}."
                                .format(self.unique_id, inspect.currentframe().f_code.co_name, self.model_portfolio_weight)
                        )
                else:
                    logger.info(
                        "{}: 오늘은 리밸런싱 하지 않습니다."
                            .format(self.unique_id)
                    )
                    self.telegram.send_message(
                        "{}/{}: 오늘은 리밸런싱 하지 않습니다."
                            .format(self.unique_id, inspect.currentframe().f_code.co_name)
                    )

                    self.model_portfolio_weight = model_weight.get('weights', None)
                    if (self.model_portfolio_weight != None):
                        logger.info(
                            "{}: 모델 포트폴리오 비중: {}"
                                .format(self.unique_id, self.model_portfolio_weight)
                        )
                        self.telegram.send_message(
                            "{}/{}: 모델 포트폴리오 비중: {}"
                                .format(self.unique_id, inspect.currentframe().f_code.co_name, self.model_portfolio_weight)
                        )

                        logger.info(
                            "{}: 데이터베이스에 모델 포트폴리오 비중 업데이트 시작"
                                .format(self.unique_id)
                        )
                        self.telegram.send_message(
                            "{}/{}: 데이터베이스에 모델 포트폴리오 비중 업데이트 시작"
                                .format(self.unique_id, inspect.currentframe().f_code.co_name)
                        )

                        with Database(self.config_file_path) as dg:
                            for symbol, weight in self.model_portfolio_weight.items():
                                table = self.unique_id + "_" + "weights"
                                now = (datetime.datetime.now()).strftime("%Y-%m-%d")
                                shtname = dg.select_shtname(symbol)

                                tfinal_weight = weight

                                try:
                                    tfinal_position = int((self.account['추정예탁자산'] * weight) / all_bclose_dict[symbol])
                                except KeyError as err:
                                    tfinal_position = 0

                                try:
                                    tapfinal_weight = self.actual_portfolio_weight[symbol]
                                except KeyError as err:
                                    tapfinal_weight = 0

                                data = [
                                    now,
                                    str(symbol),
                                    str(shtname['name']),
                                    float(tfinal_weight),
                                    int(tfinal_position),
                                    float(tapfinal_weight),
                                    0,
                                    0
                                ]

                                logger.info(
                                    "{}: 모델 포트폴리오 비중 업데이트 {}"
                                        .format(self.unique_id, data)
                                )
                                self.telegram.send_message(
                                    "{}/{}: 모델 포트폴리오 비중 업데이트 {}"
                                        .format(self.unique_id, inspect.currentframe().f_code.co_name, data)
                                )
                                dg.insert_weight(table, data)

                        logger.info(
                            "{}: 데이터베이스에 모델 포트폴리오 비중 업데이트 완료"
                                .format(self.unique_id)
                        )
                        self.telegram.send_message(
                            "{}/{}: 데이터베이스에 모델 포트폴리오 비중 업데이트 완료"
                                .format(self.unique_id, inspect.currentframe().f_code.co_name)
                        )

                    else:
                        # 모델 포트폴리오 포지션(비중) 값이 정상적으로 입력되지 않음
                        logger.info(
                            "{}: 모델 포트폴리오 비중 값이 정상적으로 입력되지 않음: {}."
                                .format(self.unique_id, self.model_portfolio_weight)
                        )
                        self.telegram.send_message(
                            "{}/{}: 모델 포트폴리오 비중 값이 정상적으로 입력되지 않음: {}."
                                .format(self.unique_id, inspect.currentframe().f_code.co_name, self.model_portfolio_weight)
                        )

    # 정규 시장 종료 (OCM)
    def _on_close_market(self):
        logger.info(
            "{}: 정규시장 종료."
                .format(self.unique_id)
        )
        self.telegram.send_message(
            "{}/{}: 정규시장 종료."
                .format(self.unique_id, inspect.currentframe().f_code.co_name)
        )

    # 장규 시장 종료 n분 후 (ACM)
    def _after_close_market(self):
        logger.info(
            "{}: 데이터베이스에 현재 포트폴리오 비중 업데이트 시작"
                .format(self.unique_id)
        )
        self.telegram.send_message(
            "{}/{}: 데이터베이스에 현재 포트폴리오 비중 업데이트 시작"
                .format(self.unique_id, inspect.currentframe().f_code.co_name)
        )

        execution_result = dict()
        response = self._get_position(self.account)
        single_data = response.get('data', {}).get('msg', {}).get('single', None)
        response = response.get('data', {}).get('msg', {}).get('multi', None)

        tot_value = 0
        if single_data is not None:
            tot_value = int(single_data['추정예탁자산'])

        if response != None:

            # 리밸런싱 할 경우에만 실행
            if self.rebalance_flag == True:
                for position in response:
                    stcode_parsed = str(position['종목번호'])[1:] if str(position['종목번호']).startswith("A") else str(position['종목번호'])
                    quantity = int(position['보유수량'])

                    execution_result[stcode_parsed] = {}

                    if self.model_portfolio_weight.get(stcode_parsed, None) != None:

                        if 0 < tot_value:
                            actual_weight = round((int(position['평가금액']) - int(position['평가수수료']) - int(position['세금'])) / tot_value, 4)
                        else:
                            actual_weight = 0

                        if round(self.model_portfolio_weight[stcode_parsed], 2) == round(actual_weight, 2):
                            # 모델 포트폴리오와 비중이 다름 (비정상)
                            execution_result[stcode_parsed]['exec_success'] = 0
                            execution_result[stcode_parsed]['actual_weight'] = actual_weight
                        else:
                            # 모델 포트폴리오와 비중이 같음 (정상)
                            execution_result[stcode_parsed]['exec_success'] = 1
                            execution_result[stcode_parsed]['actual_weight'] = actual_weight
                    else:
                        execution_result[stcode_parsed]['exec_success'] = 0
                        execution_result[stcode_parsed]['actual_weight'] = 0

                with Database(self.config_file_path) as dg:
                    table = self.unique_id + "_" + "weights"
                    today = (datetime.datetime.now()).strftime("%Y-%m-%d")
                    for k, v in execution_result.items():
                        data = [
                            v['exec_success'],  # 주문 집행 성공 여부 (True/False)
                            v['actual_weight'],  # 현재 비중
                            today,  # 주문 집행이 실패한 마지막날
                            k  # 종목 번호
                        ]

                        logger.info(
                            "{}: 실제 포트폴리오 비중 업데이트 {}"
                                .format(self.unique_id, data)
                        )
                        self.telegram.send_message(
                            "{}/{}: 실제 포트폴리오 비중 업데이트 {}"
                                .format(self.unique_id, inspect.currentframe().f_code.co_name, data)
                        )

                        dg.update_unfilled_trd_stock(table, data)

                logger.info(
                    "{}: 데이터베이스에 현재 포트폴리오 비중 업데이트 완료"
                        .format(self.unique_id)
                )
                self.telegram.send_message(
                    "{}/{}: 데이터베이스에 현재 포트폴리오 비중 업데이트 완료"
                        .format(self.unique_id, inspect.currentframe().f_code.co_name)
                )
            else:
                # 리밸런싱 하지 않을 때 실행
                for position in response:
                    stcode_parsed = str(position['종목번호'])[1:] if str(position['종목번호']).startswith("A") else str(
                        position['종목번호'])
                    quantity = int(position['보유수량'])

                    execution_result[stcode_parsed] = {}

                    if self.model_portfolio_weight.get(stcode_parsed, None) != None:

                        if 0 < tot_value:
                            actual_weight = round((int(position['평가금액']) - int(position['평가수수료']) - int(position['세금'])) / tot_value, 4)
                        else:
                            actual_weight = 0

                        execution_result[stcode_parsed]['exec_success'] = 0
                        execution_result[stcode_parsed]['actual_weight'] = actual_weight

                    else:
                        execution_result[stcode_parsed]['exec_success'] = 0
                        execution_result[stcode_parsed]['actual_weight'] = 0

                with Database(self.config_file_path) as dg:
                    table = self.unique_id + "_" + "weights"
                    today = (datetime.datetime.now()).strftime("%Y-%m-%d")
                    for k, v in execution_result.items():
                        data = [
                            v['exec_success'],  # 주문 집행 성공 여부 (True/False)
                            v['actual_weight'],  # 현재 비중
                            today,  # 주문 집행이 실패한 마지막날
                            k  # 종목 번호
                        ]

                        logger.info(
                            "{}: 실제 포트폴리오 비중 업데이트 {}"
                                .format(self.unique_id, data)
                        )
                        self.telegram.send_message(
                            "{}/{}: 실제 포트폴리오 비중 업데이트 {}"
                                .format(self.unique_id, inspect.currentframe().f_code.co_name, data)
                        )

                        dg.update_unfilled_trd_stock(table, data)

                logger.info(
                    "{}: 데이터베이스에 현재 포트폴리오 비중 업데이트 완료"
                        .format(self.unique_id)
                )
                self.telegram.send_message(
                    "{}/{}: 데이터베이스에 현재 포트폴리오 비중 업데이트 완료"
                        .format(self.unique_id, inspect.currentframe().f_code.co_name)
                )
        else:
            logger.info(
                "{}: 실제 포트폴리오 파싱 실패"
                    .format(self.unique_id)
            )
            self.telegram.send_message(
                "{}/{}: 실제 포트폴리오 파싱 실패"
                    .format(self.unique_id, inspect.currentframe().f_code.co_name)
            )
        logger.info(
            "{}: 데이터베이스에 현재 포트폴리오 비중 업데이트 종료"
                .format(self.unique_id)
        )
        self.telegram.send_message(
            "{}/{}: 데이터베이스에 현재 포트폴리오 비중 업데이트 종료"
                .format(self.unique_id, inspect.currentframe().f_code.co_name)
        )

    # 모델 포트폴리와 실제 포트폴리오의 리밸런싱 진행
    def _get_rebalance_weight(self, model_weight, actual_weight, account):
        final_buy_weight = dict()
        final_sell_weight = dict()
        final_buy_position = dict()
        final_sell_position = dict()

        balance = account['추정예탁자산']

        # 새로 편입된 종목
        model_portfolio_set = set(model_weight.keys())
        actual_portfolio_set = set(actual_weight.keys())
        diff_portfolio_set = model_portfolio_set.intersection(actual_portfolio_set)

        # 투자 유니버스가 고정된 경우 (MP와 AP의 종목이 같음)
        if (model_portfolio_set == actual_portfolio_set):
            (final_buy_weight,
             final_sell_weight,
             final_buy_position,
             final_sell_position) = self._calculate_weight(
                model_weight.keys(),
                model_weight.values(),
                actual_weight.values(),
                balance
            )
        else:
            # 투자 유니버스가 변경된 경우 (MP와 AP의 종목이 달라짐, 편입/제외 종목 존재)
            temp_result = list()

            # 편입종목 비율 조정
            add_universe_stocks = model_portfolio_set - actual_portfolio_set
            add_universe_portfolio = {key: model_weight[key] for key in list(add_universe_stocks)}
            actual_portfolio = add_universe_portfolio.fromkeys(add_universe_stocks, 0)
            temp_result.append(self._calculate_weight(
                add_universe_portfolio.keys(),
                add_universe_portfolio.values(),
                actual_portfolio.values(),
                balance
            ))

            # 제외종목 비율 조정
            del_universe_stocks = actual_portfolio_set - model_portfolio_set
            del_universe_portfolio = {key: actual_weight[key] for key in list(del_universe_stocks)}
            model_portfolio = del_universe_portfolio.fromkeys(del_universe_stocks, 0)
            temp_result.append(self._calculate_weight(
                model_portfolio.keys(),
                model_portfolio.values(),
                del_universe_portfolio.values(),
                balance
            ))

            # 편입종목/제외종목외 종목 비율 조정
            intersection_stocks = model_portfolio_set.intersection(actual_portfolio_set)
            intersection_model_portfolio = {key: model_weight[key] for key in list(intersection_stocks)}
            intersection_actual_portfolio = {key: actual_weight[key] for key in list(intersection_stocks)}
            temp_result.append(self._calculate_weight(
                intersection_model_portfolio.keys(),
                intersection_model_portfolio.values(),
                intersection_actual_portfolio.values(),
                balance
            ))

            # 변경된 투자 유니버스의 포트폴리오 비율 합
            for result in temp_result:
                final_buy_weight.update(result[0])
                final_sell_weight.update(result[1])
                final_buy_position.update(result[2])
                final_sell_position.update(result[3])

        return (
            final_buy_weight,
            final_sell_weight,
            final_buy_position,
            final_sell_position,
        )

    # 실제적으로 모델 포트폴리오와 실제 포트폴리오 비중 계산되는 로직.
    # TODO: stcode 를 target_weight.keys()로 변경 후 테스트.
    def _calculate_weight(self, stcode, target_weight, current_weight, balance):
        buy_weight = dict()
        sell_weight = dict()

        buy_position = dict()
        sell_position = dict()

        for stcode, target_weight, current_weight in zip(stcode, target_weight, current_weight):
            diff_weight = target_weight - current_weight

            # Cash가 아닐때
            if config_logic.CASH_CODE != stcode:
                current_price = self._get_current_price(stcode)
                diff_pos = int(balance * target_weight / current_price) - int(balance * current_weight / current_price)

                if target_weight > current_weight:
                    buy_weight[stcode] = diff_weight
                    buy_position[stcode] = diff_pos
                elif target_weight < current_weight:
                    sell_weight[stcode] = abs(diff_weight)
                    sell_position[stcode] = abs(diff_pos)

            # Cash일때
            else:
                if diff_weight > 0:
                    buy_weight[stcode] = diff_weight
                elif diff_weight < 0:
                    sell_weight[stcode] = abs(diff_weight)

        return (
            buy_weight,
            sell_weight,
            buy_position,
            sell_position
        )

    # 실제 주문이 나가며 리벨런싱이 진행되는 로직
    # TODO: 현재는 시장가 주문만을 사용함, 향후 다른 주문 옵션도 고려 필요.
    # TODO: 몇몇 고정적인 단어 (i.e. 신규매수, 시장가, 마켓 etc)에 대해 상수로 대체 필요.
    # TODO: stcode, quantity 변수에 올바르게 값이 들어왔는지 검증 로직 필요.
    # TODO: 주문 발송시 DB 저장 필요.
    def _do_rebalance(self, final_buy_position, final_sell_position, account):

        global all_bclose_dict
        global ivst_bclose_dict

        logger.info("{}: 최종 매수 포지션: {}".format(
            self.unique_id,
            final_buy_position
        ))
        self.telegram.send_message("{}/{}: 최종 매수 포지션: {}".format(
            self.unique_id,
            final_buy_position,
            inspect.currentframe().f_code.co_name
        ))

        logger.info("{}: 최종 매도 포지션: {}".format(
            self.unique_id,
            final_sell_position
        ))
        self.telegram.send_message("{}/{}: 최종 매도 포지션: {}".format(
            self.unique_id,
            final_sell_position,
            inspect.currentframe().f_code.co_name
        ))

        with self.mutex:
            logger.info("{}: 매수/매도 주문 집행 시작".format(self.unique_id))
            self.telegram.send_message("{}: 매수/매도 주문 집행 시작".format(self.unique_id))

            self._set_cur_account(
                account.get('account_num', -1)
            )
            response = self._get_cur_account()
            cur_account = response.get('data', {}).get('msg', -1)

            if str(cur_account) == account.get('account_num', -1):
                sell_order_result = list()
                buy_order_result = list()

                # 매도 주문 발송
                try:
                    for stcode, quantity in final_sell_position.items():
                        stcode_parsed = str(stcode)[1:] if str(stcode).startswith("A") else str(stcode)

                        if not isinstance(all_bclose_dict, dict):
                            logger.error("{}: 매도 주문 집행 실패, all_bclose_dict 가 제공되지않음.".format(self.unique_id))
                            self.telegram.send_message("{}: 매도 주문 집행 실패. all_bclose_dict 가 제공되지않음.".format(self.unique_id))
                            return False

                        if all_bclose_dict.get(stcode_parsed, -1) == -1:
                            logger.error("{}: 매도 주문 집행 실패, all_bclose_dict 에서 {} 종목 bclose 가 제공되지않음.".format(self.unique_id, stcode_parsed))
                            self.telegram.send_message("{}: 매도 주문 집행 실패. all_bclose_dict 에서 {} 종목 bclose 가 제공되지않음.".format(self.unique_id, stcode_parsed))
                            return False

                        if int(quantity) != 0:
                            time.sleep(1)

                            hoga_unit_adjust = int(round((all_bclose_dict[stcode_parsed] * 0.95) / float(5)) * 5)

                            sell_order_result.append(
                                self._set_order("신규매도", "지정가", stcode_parsed, int(quantity), hoga_unit_adjust, '0')
                            )

                except Exception as err:
                    logger.error("{}: 매수/매도 주문 집행 실패 {}".format(self.unique_id, err))
                    self.telegram.send_message("{}: 매도 주문 집행 실패. 에러 로그 참조".format(self.unique_id))
                else:
                    logger.info("{}: 매수/매도 주문 집행 완료".format(self.unique_id))
                    self.telegram.send_message("{}: 매도 주문 집행 완료.".format(self.unique_id))
                finally:
                    logger.info("{}: 매도 주문 발송 {}".format(
                        self.unique_id,
                        sell_order_result
                    ))

                # 매수 주문 발송
                try:
                    for stcode, quantity in final_buy_position.items():
                        stcode_parsed = str(stcode)[1:] if str(stcode).startswith("A") else str(stcode)

                        if not isinstance(all_bclose_dict, dict):
                            logger.error("{}: 매수 주문 집행 실패, all_bclose_dict 가 제공되지않음.".format(self.unique_id))
                            self.telegram.send_message("{}: 매수 주문 집행 실패. all_bclose_dict 가 제공되지않음.".format(self.unique_id))
                            return True

                        if all_bclose_dict.get(stcode_parsed, -1) == -1:
                            logger.error("{}: 매수 주문 집행 실패, all_bclose_dict 에서 {} 종목 bclose 가 제공되지않음.".format(self.unique_id, stcode_parsed))
                            self.telegram.send_message("{}: 매수 주문 집행 실패. all_bclose_dict 에서 {} 종목 bclose 가 제공되지않음.".format(self.unique_id, stcode_parsed))
                            return False

                        if int(quantity) != 0 and 0 < len(stcode_parsed):
                            time.sleep(1)

                            hoga_unit_adjust = int(round((all_bclose_dict[stcode_parsed] * 1.05) / float(5)) * 5)

                            buy_order_result.append(
                                self._set_order("신규매수", "지정가", stcode_parsed, int(quantity), hoga_unit_adjust, '0')
                            )
                except Exception as err:
                    logger.error("{}: 매수 주문 집행 실패 {}".format(self.unique_id, err))
                    self.telegram.send_message("{}: 매수 주문 집행 실패. 에러 로그 참조".format(self.unique_id))
                else:
                    logger.info("{}: 매수 주문 집행 완료".format(self.unique_id))
                    self.telegram.send_message("{}: 매수 주문 집행 완료".format(self.unique_id))
                finally:
                    logger.info("{}: 매수 주문 발송 {}".format(
                        self.unique_id,
                        buy_order_result
                    ))

                return True
            else:
                logger.error("{}: 계좌({}) 변경 실패. 주문 집행 취소".format(
                    self.unique_id,
                    self.account['account_num']
                ))
                self.telegram.send_message("{}: 계좌({}) 변경 실패. 주문 집행 취소".format(
                    self.unique_id,
                    self.account['account_num']
                ))

    # Action
    def _set_cur_account(self, account):
        response = self.model._set_cur_account(account)
        return response

    def _get_cur_account(self):
        response = self.model._get_cur_account()
        return response

    def _set_order(self, option: str, hoga: str, code: str, num: int, price: int, prev_order_num: str = ""):
        try:
            response = self.model._set_order(option, hoga, code, num, price, prev_order_num)
        except Exception as err:
            logger.error("{}: _set_order() Timed Out. "
                         "종목코드:{}, 수량:{}, 유형: {} 수동으로 리밸런싱 부탁드립니다."
                         .format(self.unique_id, code, num, option))
        else:
            return response

    def _get_account(self, account, columns=[]):
        """
        >>> response
            {'data': {'msg': {'single': {'예수금': '000000496143503',
                '주식증거금현금': '000000000000000',
                '수익증권증거금현금': '000000000000000',
                '익일수익증권매도정산대금': '000000000000000',
                '해외주식원화대용설정금': '000000000000000',
                '신용보증금현금': '000000000000000',
                '신용담보금현금': '000000000000000',
                '추가담보금현금': '000000000000000',
                '기타증거금': '000000000000000',
                '미수확보금': '000000000000000',
                '공매도대금': '000000000000000',
                '신용설정평가금': '000000000000000',
                '수표입금액': '000000000000000',
                '기타수표입금액': '000000000000000',
                '신용담보재사용': '000000000000000',
                '코넥스기본예탁금': '000000000000000',
                'ELW예탁평가금': '000000000000000',
                '신용대주권리예정금액': '000000000000000',
                '생계형가입금액': '000000000000000',
                '생계형입금가능금액': '000000000000000',
                '대용금평가금액(합계)': '000000000000000',
                '잔고대용평가금액': '000000000000000',
                '위탁대용잔고평가금액': '000000000000000',
                '수익증권대용평가금액': '000000000000000',
                '위탁증거금대용': '000000000000000',
                '신용보증금대용': '000000000000000',
                '신용담보금대용': '000000000000000',
                '추가담보금대용': '000000000000000',
                '권리대용금': '000000000000000',
                '출금가능금액': '000000496143503',
                '랩출금가능금액': '000000000000000',
                '주문가능금액': '000000498613783',
                '수익증권매수가능금액': '000000000000000',
                '20%종목주문가능금액': '000002493068915',
                '30%종목주문가능금액': '000001662045943',
                '40%종목주문가능금액': '000001246534457',
                '100%종목주문가능금액': '000000496143503',
                '현금미수금': '000000000000000',
                '현금미수연체료': '000000000000000',
                '현금미수금합계': '000000000000000',
                '신용이자미납': '000000000000000',
                '신용이자미납연체료': '000000000000000',
                '신용이자미납합계': '000000000000000',
                '기타대여금': '000000000000000',
                '기타대여금연체료': '000000000000000',
                '기타대여금합계': '000000000000000',
                '미상환융자금': '000000000000000',
                '융자금합계': '000000000000000',
                '대주금합계': '000000000000000',
                '신용담보비율': '000000000.00',
                '중도이용료': '000000000000000',
                '최소주문가능금액': '000000000000000',
                '대출총평가금액': '000000000000000',
                '예탁담보대출잔고': '000000000000000',
                '매도담보대출잔고': '000000000000000',
                'd+1추정예수금': '0',
                'd+1매도매수정산금': '0',
                'd+1매수정산금': '0',
                'd+1미수변제소요금': '0',
                'd+1매도정산금': '0',
                'd+1출금가능금액': '0',
                'd+2추정예수금': '0',
                'd+2매도매수정산금': '0',
                'd+2매수정산금': '0',
                'd+2미수변제소요금': '0',
                'd+2매도정산금': '0',
                'd+2출금가능금액': '0',
                '출력건수': '0'},
                'multi': []},
                'req_cmd': 'check_deposit'}}

        :param account:
        :param columns:
        :return:
        """
        with self.mutex:
            time.sleep(3.6)

            self._set_cur_account(
                account.get('account_num', -1)
            )
            response = self._get_cur_account()
            cur_account = response.get('data', {}).get('msg', -1)

            if str(cur_account) == account.get('account_num', -1):
                ret = {}
                response = self.model._get_account()
                response_parsed = response.get('data', {}).get('msg', {}).get('single', {})
                if len(columns) > 0:
                    for column in columns:
                        ret.update({column: int(response_parsed.get(column, -1))})
                    return ret
                else:
                    return response_parsed
            else:
                logger.error("{}: _get_account() 에서 계좌({}) 변경 실패.".format(
                    self.unique_id,
                    self.account['account_num']
                ))
                self.telegram.send_message("{}: _get_account() 에서 계좌({}) 변경 실패.".format(
                    self.unique_id,
                    self.account['account_num']
                ))

    def _get_balance(self, account, columns=[]):
        """

        >>> response
        {'data': {'msg': {'single': {'총매입금액': '000000006479250',
                                     '총평가금액': '000000006089700',
                                     '총평가손익금액': '-00000000433530',
                                     '총수익률(%)': '-00000006.69',
                                     '추정예탁자산': '000000486643968',
                                     '총대출금': '000000000000000',
                                     '총융자금액': '000000000000000',
                                     '총대주금액': '000000000000000',
                                        '조회건수': '0001'}}}
        :param account:
        :return:
        """

        with self.mutex:
            time.sleep(3.6)

            self._set_cur_account(
                account.get('account_num', -1)
            )
            response = self._get_cur_account()
            cur_account = response.get('data', {}).get('msg', -1)

            if str(cur_account) == account.get('account_num', -1):
                ret = {}
                response = self.model._get_balance()
                response_parsed = response.get('data', {}).get('msg', {}).get('single', {})
                if len(columns) > 0:
                    for column in columns:
                        ret.update({column: int(response_parsed.get(column, -1))})
                    return ret
                else:
                    return response_parsed
            else:
                logger.error("{}: _get_balance() 에서 계좌({}) 변경 실패.".format(
                    self.unique_id,
                    self.account['account_num']
                ))
                self.telegram.send_message("{}: _get_balance() 에서 계좌({}) 변경 실패.".format(
                    self.unique_id,
                    self.account['account_num']
                ))

    def _get_accounts_num(self):
        response = self.model._get_accounts_num()
        return response

    @retry(wait_fixed=2000, stop_max_attempt_number=5)
    def _get_position(self, account):
        with self.mutex:
            time.sleep(1)

            self._set_cur_account(
                account.get('account_num', -1)
            )
            response = self._get_cur_account()
            cur_account = response.get('data', {}).get('msg', -1)

            if str(cur_account) == account.get('account_num', -1):
                try:
                    response = self.model._get_position()
                except WebSocketTimeoutException as err:
                    logger.error("{}: _get_position() Timed Out. 최대 5번 다시 시도함.".format(self.unique_id))
                    raise WebSocketTimeoutException()
                else:
                    return response
            else:
                logger.error("{}: _get_position() 에서 계좌({}) 변경 실패.".format(
                    self.unique_id,
                    self.account['account_num']
                ))
                self.telegram.send_message("{}: _get_position() 에서 계좌({}) 변경 실패.".format(
                    self.unique_id,
                    self.account['account_num']
                ))

    @retry(wait_fixed=2000, stop_max_attempt_number=5)
    def _get_server_status(self):
        with self.mutex:
            time.sleep(1)
            try:
                response = self.model._get_server_status()
                response = response.get('data', {}).get('msg', None)
            except WebSocketTimeoutException as err:
                logger.error("{}: _get_position() Timed Out. 최대 5번 다시 시도함.".format(self.unique_id))
                raise WebSocketTimeoutException()
            else:
                return response

    def _get_server_gubun(self):
        response = self.model._get_server_gubun()
        return response

    @retry(wait_fixed=2000, stop_max_attempt_number=5)
    def _get_current_price(self, stcode):
        # 요청한 종목 현재가가 actual_portfolio_price 에 있으면 이 값을 반환 (TR 요청 최소화)

        global all_bclose_dict
        global ivst_bclose_dict

        if isinstance(all_bclose_dict, dict):
            stcode_parsed = str(stcode)[1:] if str(stcode).startswith("A") else str(stcode)
            cached_current_price = all_bclose_dict.get(stcode_parsed, None)
            if cached_current_price != None:
                return cached_current_price
        else:
            with self.mutex:
                response = self.model._get_current_price(stcode)
                if isinstance(response, dict):
                    response = response.get('data', {}).get('msg', {}).get('single', None)
                    stcode_parsed = str(stcode)[1:] if str(stcode).startswith("A") else str(stcode)
                    if (response != None) and (response['종목코드'] == stcode_parsed):
                        return abs(int(response['현재가']))
                    else:
                        return False

    def _get_master(self, mk_type):
        response = self.model._get_master(mk_type)
        return response

    def _get_multi_items(self, shtcodes, code_cnt, mk_kind):
        response = self.model._get_multi_items(shtcodes, code_cnt, mk_kind)
        return response

    def _get_model_weight(self, bprice):
        model_portfolio = self.model_portfolio()
        return model_portfolio.calc_weight(bprice)