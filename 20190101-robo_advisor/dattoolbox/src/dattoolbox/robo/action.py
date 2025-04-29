from abc import (
    ABCMeta,
    abstractmethod
)

class Action():
    __metaclass__ = ABCMeta

    # 계좌 설정
    @abstractmethod
    def _set_cur_account(self, account):
        # KRX Virtual World 에서 다양한 증권사를 사용하게 되는데 한 AWS 인스턴스에서 하나의 증권사 API를 사용한다.
        # KRX Virtual World 또한 하나의 증권사 API 세션만 사용하고 있고, 하나의 증권사 API 세션은 하나의 계좌 연결만 지원한다.
        # 즉, 에이전트별로 계좌를 다르게 사용하면서 KRX Virtual World 에 주문를 날릴 경우 각 주문시 에이전트가 바뀌는 구간에
        # KRX Virtubal World 계좌 셋팅도 다르게 해주어야 한다.
        raise NotImplementedError()

    # 현재 계좌 설정 가져오기
    @abstractmethod
    def _get_cur_account(self):
        raise NotImplementedError()

    # 주문 생성
    @abstractmethod
    def _set_order(self, option: str, hoga: str, code: str, num: int, price: int, prev_order_num: str = ""):
        """
        주식 주문
        :param option: 매수, 매도
        :param hoga: 시장가, 지정가
        :param code: 종목코드
        :param num: 수량
        :param price: 가격
        :param prev_order_num: 원주문번호
        :return:

        >>> trade_stocks("신규매수", "지정가", "035720", 10, 12300, '0')
        >>> trade_stocks("신규매도", "시장가", "035720", 10, 0, '0')
        """
        raise NotImplementedError()

    # 현재 계좌정보(총 잔고, 평가순익) 현황
    @abstractmethod
    def _get_account(self):
        raise NotImplementedError()

    # 현재 계좌정보(계좌평가잔고내역요청)
    @abstractmethod
    def _get_balance(self):
        raise NotImplementedError()

    # 현재 연결된 계좌번호 목록
    @abstractmethod
    def _get_accounts_num(self):
        raise NotImplementedError()

    # 현재 포지션 현황 (체결/미체결 종목)
    @abstractmethod
    def _get_position(self):
        raise NotImplementedError()

    # 현재 서버(API 게이트웨이) 상태
    @abstractmethod
    def _get_server_status(self):
        raise NotImplementedError()

    # 현재 서버 구분(모의거래, 실거래)
    @abstractmethod
    def _get_server_gubun(self):
        raise NotImplementedError()

    # 현재가 요청
    @abstractmethod
    def _get_current_price(self, stcode):
        raise NotImplementedError()

    # 마스터 요청
    @abstractmethod
    def _get_master(self, mk_type):
        raise NotImplementedError()

    # n개 종목의 정보 요청
    @abstractmethod
    def _get_multi_items(self, shtcodes, code_cnt, mk_kind):
        raise NotImplementedError()

    # 정규 시장 시작 n분 전 (BOM)
    @abstractmethod
    def _before_open_market(self):
        raise NotImplementedError()

    # 정규 시장 시작 (OOM)
    @abstractmethod
    def _on_open_market(self):
        raise NotImplementedError()

    # 정규 시장 시작 n분 후 (AOM)
    @abstractmethod
    def _after_open_market(self):
        raise NotImplementedError()

    # 정규 시장 종료 n분 전 (BCM)
    @abstractmethod
    def _before_close_market(self):
        raise NotImplementedError()

    # 정규 시장 종료 (OCM)
    @abstractmethod
    def _on_close_market(self):
        raise NotImplementedError()

    # 장규 시장 종료 n분 후 (ACM)
    @abstractmethod
    def _after_close_market(self):
        raise NotImplementedError()

class AgentAction(Action):
    __metaclass__ = ABCMeta

    @abstractmethod
    def _get_model_weight(self, bprice):
        raise NotImplementedError()

    @abstractmethod
    def _get_rebalance_weight(self, model_weight, actual_weight, account):
        raise NotImplementedError()

    @abstractmethod
    def _do_rebalance(self, final_buy_position, final_sell_position, account):
        raise NotImplementedError()

    @abstractmethod
    def _calculate_weight(self, stode, target_weight, current_weight, balance):
        raise NotImplementedError()

class ModelAction(Action):
    __metaclass__ = ABCMeta