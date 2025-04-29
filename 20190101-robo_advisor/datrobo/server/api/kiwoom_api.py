##################################################
# Author: hansang.cho
# Copyright: Copyright 2019, hansang.cho
# Version: 1.0.0
# Mmaintainer: hansang.cho
# Email: hehpollon@gmail.com
# Status: developing
##################################################

from PyQt5.QtCore import *
from PyQt5.QAxContainer import *
from PyQt5.QtWidgets import *
from datrobo.server.api.kiwoom_api_connector import KWApiConnector
import sys
import time


class Kiwoom(QAxWidget, KWApiConnector):
    def __init__(self, output_queue, broadcast_queue):
        super().__init__()
        self._create_kiwoom_instance()
        self._set_signal_slots()
        self.output_queue = output_queue
        self.broadcast_queue = broadcast_queue
        self.tr_event_loop = None
        self.cur_account = None

    def _create_kiwoom_instance(self):
        self.setControl("KHOPENAPI.KHOpenAPICtrl.1")

    def _set_signal_slots(self):
        self.OnReceiveTrData.connect(self._receive_tr_data)
        self.OnReceiveRealData.connect(self._receive_real_data)
        self.OnReceiveMsg.connect(self._receive_msg)
        self.OnReceiveChejanData.connect(self._receive_chejan_data)
        self.OnEventConnect.connect(self._event_connect)
        self.OnReceiveRealCondition.connect(self._receive_real_condition)
        self.OnReceiveTrCondition.connect(self._receive_tr_condition)
        self.OnReceiveConditionVer.connect(self._receive_condition_ver)

    def set_cur_account(self, account_num):
        self.cur_account = account_num
        return "setup account number is complete"

    def get_cur_account(self):
        if self.cur_account == None:
            return "-1"
        else:
            return self.cur_account

    def _get_account(self):
        """
        Get selected account or first account
        :return: account_number
        """
        if not self.cur_account:  # if not set, return first account
            account_number = self.get_login_info("ACCNO")
            return account_number.split(';')[0]
        else:
            account_number = self.cur_account
        return account_number

    def clear_cur_account(self):
        self.cur_account = None
        return "cleared"

    def get_all_account_num(self):
        # 계좌 번호
        accounts = self.get_login_info("ACCNO")
        return accounts

    def get_user_info(self):
        # 유저 정보
        user_id = self.get_login_info("USER_ID")
        user_name = self.get_login_info("USER_NAME")
        return f"{user_id, user_name}"

    def get_remain_stock(self, req_cmd):
        account_number = self._get_account()
        time.sleep(0.2)
        self.tr_opt10075(req_cmd, account_number, "1", "0")
        return self.opt10075_output

    def check_deposit(self, req_cmd):
        account_number = self._get_account()
        time.sleep(0.2)
        self.tr_opw00001(req_cmd, account_number, "", "00", "2")
        return self.opw00001_output

    def check_balance(self, req_cmd):
        account_number = self._get_account()
        time.sleep(0.2)
        self.tr_opw00018(req_cmd, account_number, "", "00", "2")
        return self.opw00018_output

    def get_current_price(self, req_cmd, stcode):
        account_number = self._get_account()
        time.sleep(0.2)
        self.tr_opt10001(req_cmd, stcode)
        return self.opt10001_output

    def detail_balance(self, req_cmd, start_date, end_date):
        account_number = self._get_account()
        time.sleep(0.2)
        self.tr_opw00016(req_cmd, account_number, "", start_date, end_date, "00")
        return self.opw00016_output

    def get_detail_trade(self, req_cmd, date):
        account_number = self._get_account()
        time.sleep(0.2)
        self.tr_opw00009(req_cmd, date, account_number, "", "00", "0", "0", "0", "1", "", "")
        return self.opw00009_output

    def trade_stocks(self, option: str, hoga: str, code: str, num: int, price: int, prev_order_num: str = ""):
        """
        주식 주문
        :param option: 매수, 매도
        :param hoga: 시장가, 지정가
        :param code: 종목코드
        :param num: 수량
        :param price: 가격
        :param prev_order_num: 원주문번호
        :return:

        ex
            trade_stocks("신규매수", "지정가", "035720", 10, 12300)
            trade_stocks("신규매도", "시장가", "035720", 10, 0)
        """
        hoga_lookup = {
            '지정가': "00",
            '시장가': "03",
            '조건부지정가': "05",
            '최유리지정가': "06",
            '최우선지정가': "07",
            '지정가IOC': "10",
            '시장가IOC': "13",
            '최유리IOC': "16",
            '지정가FOK': "20",
            '시장가FOK': "23",
            '최유리FOK': "26",
            '장전시간외종가': "61",
            '시간외단일가매매': "62",
            '장후시간외종가': "81",
        }

        option_lookup = {
            '신규매수': 1,
            '신규매도': 2,
            '매수취소': 3,
            '매도취소': 4,
            '매수정정': 5,
            '매도정정': 6
        }

        if option != '신규매수' and option != '신규매도' and prev_order_num == "":
            return "원주문번호 누락 에러"

        account = self._get_account()

        self.send_order("send_order_req", "0101", account, option_lookup[option],
                        code, num, price, hoga_lookup[hoga], prev_order_num)

        return "주문 전송 완료"

    def get_stock_daily_chart(self, req_cmd: str, shtcode: str, std_date: str, is_adj_prc: str, is_rcv_all: str = "0"):
        """
        주식 일봉 차트
        :param shtcode: 단축코드
        :param std_date: 기준일자 YYYYMMDD
        :param is_adj_prc: 수정주가여부 (0, 1)
        :param is_rcv_all: 모두수신여부
        :return:
        """

        rcv_all = True if "1" == is_rcv_all else False
        self.tr_opt10081(req_cmd, shtcode, std_date, is_adj_prc, rcv_all)
        self._disconnect_real("1081")
        return self.opt10081_output

    def get_stock_daily_trend(self, req_cmd: str, date: str, shtcode: str, data_type: str, trd_type: str, unit: str, is_rcv_all: str = "0"):
        """
        종목별 투자자기관별 차트
        :param date: 일자 YYYYMMDD
        :param shtcode: 종목코드
        :param data_type: 금액수량구분 (1: 금액, 2:수량)
        :param trd_type: 매매구분 (0: 순매수, 1: 매수, 2:매도)
        :param unit: 단위구분 (1000: 천주, 1: 단주)
        :param is_rcv_all: 모두수신여부
        :return:
        """

        rcv_all = True if "1" == is_rcv_all else False
        self.tr_opt10060(req_cmd, date, shtcode, data_type, trd_type, unit, rcv_all)
        self._disconnect_real("1060")
        return self.opt10060_output

    def get_stock_min_chart(self, req_cmd: str, shtcode: str, period: str, is_adj_prc: str, is_rcv_all: str = "0"):
        """
        주식 분봉 차트
        :param shtcode: 단축코드
        :param period: 주기
        :param is_adj_prc: 수정주가여부 (0, 1)
        :param is_rcv_all: 모두수신여부
        :return:
        """

        rcv_all = True if "1" == is_rcv_all else False
        self.tr_opt10080(req_cmd, shtcode, period, is_adj_prc, rcv_all)
        self._disconnect_real("1080")
        return self.opt10080_output

    def get_multi_items(self, req_cmd: str, shtcodes: str, code_cnt: str, type_flag: str):
        """
        관심종목정보요청
        :param shtcodes: 단축코드들 ';'로 구분
        :param code_cnt: 종목코드 갯수
        :param type_flag: (0:주식 관심종목, 3:선물옵션 관심종목)
        :return:
        """

        self.tr_optkwfid(req_cmd, shtcodes, code_cnt, type_flag)
        self._disconnect_real("9998")
        return self.optkwfid_output

    def _receive_tr_data(self, sScrNo, sRQName, sTrCode, sRecordName, sPreNext,
                         unused1, unused2, unused3, unused4):
        # 설명:
        # 서버통신 후 데이터를 받은 시점을 알려준다.
        #
        # 입력값:
        # sScrNo – 화면번호
        # sRQName – 사용자구분 명
        # sTrCode – Tran 명
        # sRecordName – Record 명
        # sPreNext – 연속조회 유무
        #
        # 반환값:
        # 없음
        #
        # 비고:
        # sRQName – CommRqData의 sRQName과 매핑되는 이름이다.
        # sTrCode – CommRqData의 sTrCode과 매핑되는 이름이다.

        try:

            data = ["_receive_tr_data", sScrNo, sRQName, sTrCode, sRecordName, sPreNext]
            print(data)
            self.broadcast_queue.put(" ".join(data))

            if sPreNext == '2':
                self.remained_data = True
            else:
                self.remained_data = False

            getattr(self, f'_{sTrCode.lower()}', lambda a, b: None)(sRQName, sTrCode)
        except Exception as e:
            print(e)

        try:
            self.tr_event_loop.exit()
        except AttributeError:
            pass

    def exit_event_loop(self):
        try:
            self.tr_event_loop.exit()
        except AttributeError:
            pass

    def _receive_real_data(self, sJongmokCode, sRealType, sRealData):
        # 설명:
        # 실시간데이터를 받은 시점을 알려준다.
        #
        # 입력값:
        # sJongmokCode – 종목코드
        # sRealType – 리얼타입
        # sRealData – 실시간 데이터전문
        #
        # 반환값:
        # 없음

        data = ["_receive_real_data", sJongmokCode, sRealType, sRealData]
        print(data)
        self.broadcast_queue.put(" ".join(data))

    def _receive_msg(self, sScrNo, sRQName, sTrCode, sMsg):
        # 설명:
        # 서버통신 후 메시지를 받은 시점을 알려준다.
        #
        # 입력값:
        # sScrNo – 화면번호
        # sRQName – 사용자구분 명
        # sTrCode – Tran 명
        # sMsg – 서버메시지
        #
        # 반환값:
        # 없음
        #
        # 비고:
        # sScrNo – CommRqData의 sScrNo와 매핑된다.
        #
        # sRQName – CommRqData의 sRQName 와 매핑된다.
        # sTrCode – CommRqData의 sTrCode 와 매핑된다.

        data = ["_receive_msg", sScrNo, sRQName, sTrCode, sMsg]
        print(data)
        self.broadcast_queue.put(" ".join(data))

    def _receive_chejan_data(self, sGubun, nItemCnt, sFidList):
        # 설명:
        # 체결데이터를 받은 시점을 알려준다.
        #
        # 입력값:
        # sGubun – 체결구분
        # nItemCnt - 아이템갯수
        # sFidList – 데이터리스트
        #
        # 반환값:
        # 없음
        #
        # 비고:
        # sGubun – 0:주문체결통보, 1:잔고통보, 3:특이신호
        # sFidList – 데이터 구분은 ‘;’ 이다.

        data = ["_receive_chejan_data", sGubun, nItemCnt, sFidList]
        print(data)

        # print('*' * 20)
        # print(sGubun)

        result = dict()
        result[' _func'] = "_receive_chejan_data"
        result['구분'] = sGubun
        result['주문번호'] = self.get_chejan_data(9203)
        result['종목명'] = self.get_chejan_data(302)
        result['주문수량'] = self.get_chejan_data(900)
        result['주문가격'] = self.get_chejan_data(901)
        result['미체결수량'] = self.get_chejan_data(902)
        result['주문/체결시간'] = self.get_chejan_data(908)
        result['체결번호'] = self.get_chejan_data(909)
        result['체결가'] = self.get_chejan_data(910)
        result['체결량'] = self.get_chejan_data(911)
        self.broadcast_queue.put(result)

        # print('주문번호:', self.get_chejan_data(9203))
        # print('종목명:', self.get_chejan_data(302))
        # print('주문수량:', self.get_chejan_data(900))
        # print('주문가격:', self.get_chejan_data(901))
        # print('미체결수량:', self.get_chejan_data(902))
        # print('주문/체결시간:', self.get_chejan_data(908))
        # print('체결번호:', self.get_chejan_data(909))
        # print('체결가:', self.get_chejan_data(910))
        # print('체결량:', self.get_chejan_data(911))
        # print('*' * 20)

    def _event_connect(self, nErrCode):
        # 설명:
        # 서버 접속 관련 이벤트
        #
        # 입력값:
        # LONG nErrCode : 에러 코드
        #
        # 반환값:
        # 없음
        #
        # 비고:
        # nErrCode가 0이면 로그인 성공, 음수면 실패
        # 음수인 경우는 에러 코드 참조

        data = ["_event_connect", nErrCode]
        print(data)

        self.login_event_loop.exit()

    def _receive_real_condition(self, strCode, strType, strConditionIndex):
        # 설명:
        # 조건검색 실시간 편입,이탈 종목을 받을 시점을 알려준다.
        #
        # 입력값:
        # LPCTSTR strCode : 종목코드
        # LPCTSTR strType : 편입(“I”), 이탈(“D”) LPCTSTR strConditionName : 조건명
        # LPCTSTR strConditionIndex : 조건명 인덱스
        #
        # 반환값:
        # 없음
        #
        # 비고:
        # strConditionName에 해당하는 종목이 실시간으로 들어옴.
        # strType으로 편입된 종목인지 이탈된 종목인지 구분한다.

        data = ["_receive_real_condition", strCode, strType, strConditionIndex]
        print(data)
        self.broadcast_queue.put(" ".join(data))

        pass

    def _receive_tr_condition(self, sScrNo, strCodeList, strConditionName, nIndex, nNext):
        # 설명:
        # 조건검색 조회응답으로 종목리스트를 구분자(“;”)로 붙어서 받는 시점.
        #
        # 입력값:
        # LPCTSTR sScrNo : 종목코드
        # LPCTSTR strCodeList : 종목리스트(“;”로 구분)
        # LPCTSTR strConditionName : 조건명
        # int nIndex : 조건명 인덱스
        # int nNext : 연속조회(2:연속조회, 0:연속조회없음)
        #
        # 반환값:
        # 없음

        data = ["_receive_tr_condition", sScrNo, strCodeList, strConditionName, nIndex, nNext]
        print(data)
        self.broadcast_queue.put(" ".join(data))

        pass

    def _receive_condition_ver(self, lRet):
        # 설명:
        # 로컬에 사용자 조건식 저장 성공 여부를 확인하는 시점
        #
        # 입력값:
        # long lRet : 사용자 조건식 저장 성공여부 (1: 성공, 나머지 실패)
        #
        # 반환값:
        # 없음

        data = ["_receive_condition_ver", lRet]
        print(data)
        self.broadcast_queue.put(" ".join(data))

    def comm_connect(self):
        self.dynamicCall("CommConnect()")
        self.login_event_loop = QEventLoop()
        self.login_event_loop.exec_()

    def get_master(self, req_cmd, market):
        code_list = self.get_code_list_by_market(market)
        master = {
            "req_cmd": req_cmd
        }

        for shtcode in code_list:
            if 0 < len(shtcode):
                master[shtcode] = {
                    "시장구분": market,
                    "종목명": self.get_master_code_name(shtcode),
                    "전일가": self.dynamicCall("GetMasterLastPrice(QString)", shtcode),
                    "상장일": self.dynamicCall("GetMasterListedStockDate(QString)", shtcode),
                    "감리구분": self.dynamicCall("GetMasterConstruction(QString)", shtcode),
                    "종목상태": self.dynamicCall("GetMasterStockState(QString)", shtcode),
                }

        return master

    def get_code_list_by_market(self, market):
        code_list = self.dynamicCall("GetCodeListByMarket(QString)", market)
        code_list = code_list.split(';')
        return code_list[:-1]

    def get_master_code_name(self, code):
        code_name = self.dynamicCall("GetMasterCodeName(QString)", code)
        return code_name

    def get_connect_state(self):
        # 1: 로그인 성공, 0: 미연결
        ret = self.dynamicCall("GetConnectState()")
        data = ["get_connect_state", ret]
        print(data)
        return ret

    def _disconnect_real(self, 화면번호):
        ret = self.dynamicCall("DisconnectRealData(QString)", 화면번호)
        return ret

    def set_input_value(self, id, value):
        self.dynamicCall("SetInputValue(QString, QString)", id, value)

    def comm_rq_data(self, rqname, trcode, next, screen_no):
        self.dynamicCall("CommRqData(QString, QString, int, QString)", rqname, trcode, next, screen_no)
        self.tr_event_loop = QEventLoop()
        QTimer.singleShot(3000, self.tr_event_loop.quit)
        self.tr_event_loop.exec_()

    def comm_kw_rq_data(self, shtcodes, next, code_cnt, type_flag, reqname, screen_no):
        self.dynamicCall("CommKwRqData(QString, int, int, int, QString, QString", shtcodes, next, code_cnt, type_flag, reqname, screen_no)
        self.tr_event_loop = QEventLoop()
        QTimer.singleShot(3000, self.tr_event_loop.quit)
        self.tr_event_loop.exec_()

    def _get_comm_data(self, code, field_name, index, item_name):
        ret = self.dynamicCall("GetCommData(QString, QString, int, QString)", code,
                               field_name, index, item_name)
        return ret.strip()

    # def _get_comm_data(self, code, field_name, index, item_name):
    #     ret = self.dynamicCall("GetCommData(QString, QString, int, QString)", code,
    #                            field_name, index, item_name)
    #     return ret.strip()

    def _get_repeat_cnt(self, trcode, rqname):
        ret = self.dynamicCall("GetRepeatCnt(QString, QString)", trcode, rqname)
        return ret

    def send_order(self, rqname, screen_no, acc_no, order_type, code, quantity, price, hoga, order_no):
        self.dynamicCall("SendOrder(QString, QString, QString, int, QString, int, int, QString, QString)",
                         [rqname, screen_no, acc_no, order_type, code, quantity, price, hoga, order_no])

    def get_chejan_data(self, fid):
        # 9201 계좌번호
        # 9203 주문번호
        # 9205 관리자사번
        # 9001 종목코드, 업종코드
        # 912 주문업무분류(JJ:주식주문, FJ:선물옵션, JG:주식잔고, FG:선물옵션잔고)
        # 913 주문상태(접수, 확인, 체결)
        # 302 종목명
        # 900 주문수량
        # 901 주문가격
        # 902 미체결수량
        # 903 체결누계금액
        # 904 원주문번호
        # 905 주문구분(+현금내수,-현금매도...)
        # 906 매매구분(보통,시장가...)
        # 907 매도수구분 (1:매도,2:매수)
        # 908 주문/체결시간(HHMMSSMS)
        # 909 체결번호
        # 910 체결가
        # 911 체결량
        # 10 현재가, 체결가, 실시간종가
        # 27 (최우선)매도호가
        # 28 (최우선)매수호가
        # 914 단위체결가
        # 915 단위체결량
        # 938 당일매매 수수료
        # 939 당일매매세금
        ret = self.dynamicCall("GetChejanData(int)", fid)
        return ret

    def get_login_info(self, tag):
        ret = self.dynamicCall("GetLoginInfo(QString)", tag)
        return ret

    @staticmethod
    def change_format(data):
        strip_data = data.lstrip('-0')
        if strip_data == '':
            strip_data = '0'
        if strip_data == '.00':
            strip_data = '0'
        if '.' in strip_data:
            format_data = '0'+strip_data
        else:
            format_data = format(int(strip_data), ',d')
        if data.startswith('-'):
            format_data = '-' + format_data

        return format_data

    @staticmethod
    def change_format2(data):
        strip_data = data.lstrip('-0')

        if strip_data == '':
            strip_data = '0'

        if strip_data.startswith('.'):
            strip_data = '0' + strip_data

        if data.startswith('-'):
            strip_data = '-' + strip_data

        return strip_data

    def get_server_gubun(self):
        ret = self.dynamicCall("KOA_Functions(QString, QString)", "GetServerGubun", "")
        return ret


if __name__ == "__main__":
    app = QApplication(sys.argv)
    kiwoom = Kiwoom(None, None)
    kiwoom.comm_connect()




