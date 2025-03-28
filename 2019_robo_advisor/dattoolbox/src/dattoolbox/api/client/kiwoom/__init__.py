from abc import (
    ABCMeta,
)

import json
import websocket

from dattoolbox.robo.action import Action


class IKiwoomClient(Action):
    __metaclass__ = ABCMeta

class KiwoomClient(IKiwoomClient):
    def __init__(self, input_queue, output_queue):
        self.ws = None

        self.input_queue = input_queue
        self.output_queue = output_queue

    def __del__(self):
        if self.ws is not None:
            self.ws.close()
            self.ws = None

    # 명령어 전송 함수
    def _send_command(self, command, ip='localhost', port='8765'):
        try:
            # 새로운 커낵션 생성
            if (self.ws == None) or (self.ws.connected == False):
                self.ws = websocket.create_connection('ws://{}:{}'.format(ip, port))

            # 커맨드 송신
            request = self.ws.send(command)
            # 결과 수신
            while True:
                response = self.ws.recv()
                response = json.loads(response)

                # 브로드케스트 데이터가 들어오는걸 flush 하고 데이터만 받음.
                if isinstance(response.get('data', {}), dict) and \
                        response.get('data', {}).get('msg', None) != None:
                    break
        except Exception as err:
            raise err
        else:
            return response
        finally:
            self.ws.close()

    # 계좌 설정
    def set_cur_account(self, account):
        return self._set_cur_account(account)

    def _set_cur_account(self, account):
        """
        거래 계좌 설정
        :param account: 계좌번호
        :return:

        >>> set_cur_account(12345678)
        """
        result = None
        command = "set_cur_account " + str(account)
        try:
            result = self._send_command(command)
        except Exception as err:
            print(err)
        else:
            return result
        finally:
            return result

    # 현재 계좌 설정 가져오기
    def get_cur_account(self):
        return self._get_cur_account()

    def _get_cur_account(self):
        """
        현재 계좌 설정 가져오기
        :return:

        >>> get_cur_account()
        {'data': {'msg': '123', 'req_cmd': 'get_cur_account'}}
        """
        result = None
        command = "get_cur_account "
        try:
            result = self._send_command(command)
        except Exception as err:
            print(err)
        else:
            return result
        finally:
            return result


    # 주식주문
    def set_order(self, option: str, hoga: str, code: str, num: int, price: int, prev_order_num: str = ""):
        return self._set_order(option=option, hoga=hoga, code=code, num=num, price=price, prev_order_num=prev_order_num)

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

        >>> _set_order("신규매수", "지정가", "035720", 10, 12300, '0')
        >>> _set_order("신규매도", "시장가", "035720", 10, 0, '0')
        """

        """
        # TODO: 자동으로 주문, 나중에 풀어야 한다.
        result = None
        command = str("trade_stock " + option + " " + hoga + " " + code + " " + str(num) + " " + str(
            price) + " " + prev_order_num)
        try:
            result = self._send_command(command)
        except websocket.WebSocketTimeoutException:
            raise websocket.WebSocketTimeoutException
        except Exception as err:
            raise err
        else:
            return result
        finally:
            return result
        """

        return ["임시로 주문을 막음"]

    # 현재 계좌정보(총 잔고, 평가순익) 현황
    def get_account(self):
        return self._get_account()

    def _get_account(self):
        """

        """
        result = None
        command = "check_deposit"
        try:
            result = self._send_command(command)
        except Exception as err:
            print(err)
        else:
            return result
        finally:
            return result

    def get_balance(self):
        return self._get_balance()

    def _get_balance(self):
        """

        :return:
        """
        result = None
        command = "check_balance"
        try:
            result = self._send_command(command)
        except Exception as err:
            print(err)
        else:
            return result
        finally:
            return result

    # 현재 연결된 계좌번호 목록
    def get_accounts_num(self):
        return self._get_accounts_num()

    def _get_accounts_num(self):
        """
        """
        result = None
        command = "all_account_num"
        try:
            result = self._send_command(command)
        except Exception as err:
            print(err)
        else:
            return result
        finally:
            return result

    # 현재 포지션 현황 (체결/미체결 종목)
    def get_position(self):
        return self._get_position()

    def _get_position(self):
        """
        """
        result = None
        command = "check_balance"
        try:
            result = self._send_command(command)
        except Exception as err:
            print(err)
        else:
            return result
        finally:
            return result

    # 현재 키움 서버(API 게이트웨이) 상태
    def get_server_status(self):
        return self._get_server_status()

    def _get_server_status(self):
        result = None
        command = "status"
        try:
            result = self._send_command(command)
        except Exception as err:
            print(err)
        else:
            return result
        finally:
            return result

    # 접속한 키움 서버 구분(모의거래, 실거래)
    def get_server_gubun(self):
        return self._get_server_gubun()

    def _get_server_gubun(self):
        result = None
        command = "server_gubun"
        try:
            result = self._send_command(command)
        except Exception as err:
            print(err)
        else:
            return result
        finally:
            return result

    def get_current_price(self, stcode):
        return self._get_current_price(stcode)

    # 현재가 요청
    def _get_current_price(self, stcode):
        result = None
        command = "get_current_price" + " " + str(stcode)
        try:
            result = self._send_command(command)
        except Exception as err:
            print(err)
        else:
            return result
        finally:
            return result

    def get_master(self, mk_type):
        return self._get_master(mk_type)

    # 마스터 요청
    def _get_master(self, mk_type):
        result = None
        command = "get_master {0}".format(mk_type)
        try:
            result = self._send_command(command)
        except Exception as err:
            print(err)
        else:
            return result
        finally:
            return result

    def get_multi_items(self, shtcodes, code_cnt, mk_kind):
        return self._get_multi_items(shtcodes, code_cnt, mk_kind)

    # n개 종목의 정보 요청
    def _get_multi_items(self, shtcodes, code_cnt, mk_kind):
        result = None
        command = "get_multi_items {0} {1} {2}".format(";".join(shtcodes), code_cnt, mk_kind)
        try:
            result = self._send_command(command)
        except Exception as err:
            print(err)
        else:
            return result
        finally:
            return result
