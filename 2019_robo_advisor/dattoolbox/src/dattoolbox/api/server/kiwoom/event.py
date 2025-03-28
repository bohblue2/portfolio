##################################################
# Author: hansang.cho
# Copyright: Copyright 2019, hansang.cho
# Version: 1.0.0
# Mmaintainer: hansang.cho
# Email: hehpollon@gmail.com
# Status: complete
##################################################

import time


class KWApiConnector:
    def __init__(self):
        self.opt10001_ouput = dict()
        self.opt10002_ouput = dict()
        self.opt10003_ouput = dict()
        self.opt10004_ouput = dict()
        self.opt10005_ouput = dict()
        self.opt10006_ouput = dict()
        self.opt10007_ouput = dict()
        self.opt10008_ouput = dict()
        self.opt10009_ouput = dict()
        self.opt10010_ouput = dict()
        self.opt10012_ouput = dict()
        self.opt10013_ouput = dict()
        self.opt10014_ouput = dict()
        self.opt10015_ouput = dict()
        self.opt10016_ouput = dict()
        self.opt10017_ouput = dict()
        self.opt10018_ouput = dict()
        self.opt10019_ouput = dict()
        self.opt10020_ouput = dict()
        self.opt10021_ouput = dict()
        self.opt10022_ouput = dict()
        self.opt10023_ouput = dict()
        self.opt10024_ouput = dict()
        self.opt10025_ouput = dict()
        self.opt10026_ouput = dict()
        self.opt10027_ouput = dict()
        self.opt10028_ouput = dict()
        self.opt10029_ouput = dict()
        self.opt10030_ouput = dict()
        self.opt10031_ouput = dict()
        self.opt10032_ouput = dict()
        self.opt10033_ouput = dict()
        self.opt10034_ouput = dict()
        self.opt10035_ouput = dict()
        self.opt10036_ouput = dict()
        self.opt10037_ouput = dict()
        self.opt10038_ouput = dict()
        self.opt10039_ouput = dict()
        self.opt10040_ouput = dict()
        self.opt10041_ouput = dict()
        self.opt10042_ouput = dict()
        self.opt10043_ouput = dict()
        self.opt10044_ouput = dict()
        self.opt10045_ouput = dict()
        self.opt10048_ouput = dict()
        self.opt10049_ouput = dict()
        self.opt10050_ouput = dict()
        self.opt10051_ouput = dict()
        self.opt10053_ouput = dict()
        self.opt10055_ouput = dict()
        self.opt10058_ouput = dict()
        self.opt10059_ouput = dict()
        self.opt10060_ouput = dict()
        self.opt10061_ouput = dict()
        self.opt10062_ouput = dict()
        self.opt10063_ouput = dict()
        self.opt10064_ouput = dict()
        self.opt10065_ouput = dict()
        self.opt10066_ouput = dict()
        self.opt10067_ouput = dict()
        self.opt10068_ouput = dict()
        self.opt10069_ouput = dict()
        self.opt10070_ouput = dict()
        self.opt10071_ouput = dict()
        self.opt10072_ouput = dict()
        self.opt10073_ouput = dict()
        self.opt10074_ouput = dict()
        self.opt10075_ouput = dict()
        self.opt10076_ouput = dict()
        self.opt10077_ouput = dict()
        self.opt10078_ouput = dict()
        self.opt10079_ouput = dict()
        self.opt10080_ouput = dict()
        self.opt10081_ouput = dict()
        self.opt10082_ouput = dict()
        self.opt10083_ouput = dict()
        self.opt10084_ouput = dict()
        self.opt10085_ouput = dict()
        self.opt10086_ouput = dict()
        self.opt10087_ouput = dict()
        self.opt10094_ouput = dict()
        self.opt20001_ouput = dict()
        self.opt20002_ouput = dict()
        self.opt20003_ouput = dict()
        self.opt20004_ouput = dict()
        self.opt20005_ouput = dict()
        self.opt20006_ouput = dict()
        self.opt20007_ouput = dict()
        self.opt20008_ouput = dict()
        self.opt20009_ouput = dict()
        self.opt20019_ouput = dict()
        self.opt20068_ouput = dict()
        self.opt30001_ouput = dict()
        self.opt30002_ouput = dict()
        self.opt30003_ouput = dict()
        self.opt30004_ouput = dict()
        self.opt30005_ouput = dict()
        self.opt30006_ouput = dict()
        self.opt30007_ouput = dict()
        self.opt30008_ouput = dict()
        self.opt30009_ouput = dict()
        self.opt30010_ouput = dict()
        self.opt30011_ouput = dict()
        self.opt30012_ouput = dict()
        self.opt40001_ouput = dict()
        self.opt40002_ouput = dict()
        self.opt40003_ouput = dict()
        self.opt40004_ouput = dict()
        self.opt40005_ouput = dict()
        self.opt40006_ouput = dict()
        self.opt40007_ouput = dict()
        self.opt40008_ouput = dict()
        self.opt40009_ouput = dict()
        self.opt40010_ouput = dict()
        self.opt50001_ouput = dict()
        self.opt50002_ouput = dict()
        self.opt50003_ouput = dict()
        self.opt50004_ouput = dict()
        self.opt50005_ouput = dict()
        self.opt50006_ouput = dict()
        self.opt50007_ouput = dict()
        self.opt50008_ouput = dict()
        self.opt50009_ouput = dict()
        self.opt50010_ouput = dict()
        self.opt50011_ouput = dict()
        self.opt50012_ouput = dict()
        self.opt50013_ouput = dict()
        self.opt50014_ouput = dict()
        self.opt50015_ouput = dict()
        self.opt50016_ouput = dict()
        self.opt50017_ouput = dict()
        self.opt50018_ouput = dict()
        self.opt50019_ouput = dict()
        self.opt50020_ouput = dict()
        self.opt50021_ouput = dict()
        self.opt50022_ouput = dict()
        self.opt50023_ouput = dict()
        self.opt50024_ouput = dict()
        self.opt50025_ouput = dict()
        self.opt50026_ouput = dict()
        self.opt50027_ouput = dict()
        self.opt50028_ouput = dict()
        self.opt50029_ouput = dict()
        self.opt50030_ouput = dict()
        self.opt50031_ouput = dict()
        self.opt50032_ouput = dict()
        self.opt50033_ouput = dict()
        self.opt50034_ouput = dict()
        self.opt50035_ouput = dict()
        self.opt50036_ouput = dict()
        self.opt50037_ouput = dict()
        self.opt50038_ouput = dict()
        self.opt50039_ouput = dict()
        self.opt50040_ouput = dict()
        self.opt50043_ouput = dict()
        self.opt50044_ouput = dict()
        self.opt50062_ouput = dict()
        self.opt50063_ouput = dict()
        self.opt50064_ouput = dict()
        self.opt50065_ouput = dict()
        self.opt50066_ouput = dict()
        self.opt50067_ouput = dict()
        self.opt50068_ouput = dict()
        self.opt50071_ouput = dict()
        self.opt50072_ouput = dict()
        self.opt50073_ouput = dict()
        self.opt90001_ouput = dict()
        self.opt90002_ouput = dict()
        self.opt90003_ouput = dict()
        self.opt90004_ouput = dict()
        self.opt90005_ouput = dict()
        self.opt90006_ouput = dict()
        self.opt90007_ouput = dict()
        self.opt90008_ouput = dict()
        self.opt90009_ouput = dict()
        self.opt90010_ouput = dict()
        self.opt90011_ouput = dict()
        self.opt90012_ouput = dict()
        self.opt90013_ouput = dict()
        self.opt99999_ouput = dict()
        self.optfofid_ouput = dict()
        self.optkwfid_ouput = dict()
        self.optkwinv_ouput = dict()
        self.optkwpro_ouput = dict()
        self.opw00001_ouput = dict()
        self.opw00002_ouput = dict()
        self.opw00003_ouput = dict()
        self.opw00004_ouput = dict()
        self.opw00005_ouput = dict()
        self.opw00006_ouput = dict()
        self.opw00007_ouput = dict()
        self.opw00008_ouput = dict()
        self.opw00009_ouput = dict()
        self.opw00010_ouput = dict()
        self.opw00011_ouput = dict()
        self.opw00012_ouput = dict()
        self.opw00013_ouput = dict()
        self.opw00014_ouput = dict()
        self.opw00015_ouput = dict()
        self.opw00016_ouput = dict()
        self.opw00017_ouput = dict()
        self.opw00018_ouput = dict()
        self.opw20001_ouput = dict()
        self.opw20002_ouput = dict()
        self.opw20003_ouput = dict()
        self.opw20004_ouput = dict()
        self.opw20005_ouput = dict()
        self.opw20006_ouput = dict()
        self.opw20007_ouput = dict()
        self.opw20008_ouput = dict()
        self.opw20009_ouput = dict()
        self.opw20010_ouput = dict()
        self.opw20011_ouput = dict()
        self.opw20012_ouput = dict()
        self.opw20013_ouput = dict()
        self.opw20014_ouput = dict()
        self.opw20015_ouput = dict()
        self.opw20016_ouput = dict()
        self.opw20017_ouput = dict()

    def set_input_value(self, id, value):
        raise NotImplementedError

    def comm_rq_data(self, rqname, trcode, next, screen_no):
        raise NotImplementedError

    def tr_opt10001(self, 종목코드):
        """
        주식기본정보요청
        """
        self.set_input_value('종목코드', 종목코드)
        self.comm_rq_data('opt10001_req', 'opt10001', '0', '1001')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('종목코드', 종목코드)
            self.comm_rq_data('opt10001_req', 'opt10001', '2', '1001')

    def tr_opt10002(self, 종목코드):
        """
        주식거래원요청
        """
        self.set_input_value('종목코드', 종목코드)
        self.comm_rq_data('opt10002_req', 'opt10002', '0', '1002')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('종목코드', 종목코드)
            self.comm_rq_data('opt10002_req', 'opt10002', '2', '1002')

    def tr_opt10003(self, 종목코드):
        """
        체결정보요청
        """
        self.set_input_value('종목코드', 종목코드)
        self.comm_rq_data('opt10003_req', 'opt10003', '0', '1003')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('종목코드', 종목코드)
            self.comm_rq_data('opt10003_req', 'opt10003', '2', '1003')

    def tr_opt10004(self, 종목코드):
        """
        주식호가요청
        """
        self.set_input_value('종목코드', 종목코드)
        self.comm_rq_data('opt10004_req', 'opt10004', '0', '1004')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('종목코드', 종목코드)
            self.comm_rq_data('opt10004_req', 'opt10004', '2', '1004')

    def tr_opt10005(self, 종목코드):
        """
        주식일주월시분요청
        """
        self.set_input_value('종목코드', 종목코드)
        self.comm_rq_data('opt10005_req', 'opt10005', '0', '1005')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('종목코드', 종목코드)
            self.comm_rq_data('opt10005_req', 'opt10005', '2', '1005')

    def tr_opt10006(self, 종목코드):
        """
        주식시분요청
        """
        self.set_input_value('종목코드', 종목코드)
        self.comm_rq_data('opt10006_req', 'opt10006', '0', '1006')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('종목코드', 종목코드)
            self.comm_rq_data('opt10006_req', 'opt10006', '2', '1006')

    def tr_opt10007(self, 종목코드):
        """
        시세표성정보요청
        """
        self.set_input_value('종목코드', 종목코드)
        self.comm_rq_data('opt10007_req', 'opt10007', '0', '1007')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('종목코드', 종목코드)
            self.comm_rq_data('opt10007_req', 'opt10007', '2', '1007')

    def tr_opt10008(self, 종목코드):
        """
        주식외국인요청
        """
        self.set_input_value('종목코드', 종목코드)
        self.comm_rq_data('opt10008_req', 'opt10008', '0', '1008')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('종목코드', 종목코드)
            self.comm_rq_data('opt10008_req', 'opt10008', '2', '1008')

    def tr_opt10009(self, 종목코드):
        """
        주식기관요청
        """
        self.set_input_value('종목코드', 종목코드)
        self.comm_rq_data('opt10009_req', 'opt10009', '0', '1009')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('종목코드', 종목코드)
            self.comm_rq_data('opt10009_req', 'opt10009', '2', '1009')

    def tr_opt10010(self, 종목코드):
        """
        업종프로그램요청
        """
        self.set_input_value('종목코드', 종목코드)
        self.comm_rq_data('opt10010_req', 'opt10010', '0', '1010')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('종목코드', 종목코드)
            self.comm_rq_data('opt10010_req', 'opt10010', '2', '1010')

    def tr_opt10012(self, 계좌번호):
        """
        주문체결요청
        """
        self.set_input_value('계좌번호', 계좌번호)
        self.comm_rq_data('opt10012_req', 'opt10012', '0', '1012')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('계좌번호', 계좌번호)
            self.comm_rq_data('opt10012_req', 'opt10012', '2', '1012')

    def tr_opt10013(self, 종목코드, 일자, 조회구분):
        """
        신용매매동향요청
        """
        self.set_input_value('종목코드', 종목코드)
        self.set_input_value('일자', 일자)
        self.set_input_value('조회구분', 조회구분)
        self.comm_rq_data('opt10013_req', 'opt10013', '0', '1013')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('종목코드', 종목코드)
            self.set_input_value('일자', 일자)
            self.set_input_value('조회구분', 조회구분)
            self.comm_rq_data('opt10013_req', 'opt10013', '2', '1013')

    def tr_opt10014(self, 종목코드, 시간구분, 시작일자, 종료일자):
        """
        공매도추이요청
        """
        self.set_input_value('종목코드', 종목코드)
        self.set_input_value('시간구분', 시간구분)
        self.set_input_value('시작일자', 시작일자)
        self.set_input_value('종료일자', 종료일자)
        self.comm_rq_data('opt10014_req', 'opt10014', '0', '1014')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('종목코드', 종목코드)
            self.set_input_value('시간구분', 시간구분)
            self.set_input_value('시작일자', 시작일자)
            self.set_input_value('종료일자', 종료일자)
            self.comm_rq_data('opt10014_req', 'opt10014', '2', '1014')

    def tr_opt10015(self, 종목코드, 시작일자):
        """
        일별거래상세요청
        """
        self.set_input_value('종목코드', 종목코드)
        self.set_input_value('시작일자', 시작일자)
        self.comm_rq_data('opt10015_req', 'opt10015', '0', '1015')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('종목코드', 종목코드)
            self.set_input_value('시작일자', 시작일자)
            self.comm_rq_data('opt10015_req', 'opt10015', '2', '1015')

    def tr_opt10016(self, 시장구분, 신고저구분, 고저종구분, 종목조건, 거래량구분, 신용조건, 상하한포함, 기간):
        """
        신고저가요청
        """
        self.set_input_value('시장구분', 시장구분)
        self.set_input_value('신고저구분', 신고저구분)
        self.set_input_value('고저종구분', 고저종구분)
        self.set_input_value('종목조건', 종목조건)
        self.set_input_value('거래량구분', 거래량구분)
        self.set_input_value('신용조건', 신용조건)
        self.set_input_value('상하한포함', 상하한포함)
        self.set_input_value('기간', 기간)
        self.comm_rq_data('opt10016_req', 'opt10016', '0', '1016')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('시장구분', 시장구분)
            self.set_input_value('신고저구분', 신고저구분)
            self.set_input_value('고저종구분', 고저종구분)
            self.set_input_value('종목조건', 종목조건)
            self.set_input_value('거래량구분', 거래량구분)
            self.set_input_value('신용조건', 신용조건)
            self.set_input_value('상하한포함', 상하한포함)
            self.set_input_value('기간', 기간)
            self.comm_rq_data('opt10016_req', 'opt10016', '2', '1016')

    def tr_opt10017(self, 시장구분, 상하한구분, 정렬구분, 종목조건, 거래량구분, 신용조건, 매매금구분):
        """
        상하한가요청
        """
        self.set_input_value('시장구분', 시장구분)
        self.set_input_value('상하한구분', 상하한구분)
        self.set_input_value('정렬구분', 정렬구분)
        self.set_input_value('종목조건', 종목조건)
        self.set_input_value('거래량구분', 거래량구분)
        self.set_input_value('신용조건', 신용조건)
        self.set_input_value('매매금구분', 매매금구분)
        self.comm_rq_data('opt10017_req', 'opt10017', '0', '1017')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('시장구분', 시장구분)
            self.set_input_value('상하한구분', 상하한구분)
            self.set_input_value('정렬구분', 정렬구분)
            self.set_input_value('종목조건', 종목조건)
            self.set_input_value('거래량구분', 거래량구분)
            self.set_input_value('신용조건', 신용조건)
            self.set_input_value('매매금구분', 매매금구분)
            self.comm_rq_data('opt10017_req', 'opt10017', '2', '1017')

    def tr_opt10018(self, 고저구분, 근접율, 시장구분, 거래량구분, 종목조건, 신용조건):
        """
        고저가근접요청
        """
        self.set_input_value('고저구분', 고저구분)
        self.set_input_value('근접율', 근접율)
        self.set_input_value('시장구분', 시장구분)
        self.set_input_value('거래량구분', 거래량구분)
        self.set_input_value('종목조건', 종목조건)
        self.set_input_value('신용조건', 신용조건)
        self.comm_rq_data('opt10018_req', 'opt10018', '0', '1018')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('고저구분', 고저구분)
            self.set_input_value('근접율', 근접율)
            self.set_input_value('시장구분', 시장구분)
            self.set_input_value('거래량구분', 거래량구분)
            self.set_input_value('종목조건', 종목조건)
            self.set_input_value('신용조건', 신용조건)
            self.comm_rq_data('opt10018_req', 'opt10018', '2', '1018')

    def tr_opt10019(self, 시장구분, 등락구분, 시간구분, 시간, 거래량구분, 종목조건, 신용조건, 가격조건, 상하한포함):
        """
        가격급등락요청
        """
        self.set_input_value('시장구분', 시장구분)
        self.set_input_value('등락구분', 등락구분)
        self.set_input_value('시간구분', 시간구분)
        self.set_input_value('시간', 시간)
        self.set_input_value('거래량구분', 거래량구분)
        self.set_input_value('종목조건', 종목조건)
        self.set_input_value('신용조건', 신용조건)
        self.set_input_value('가격조건', 가격조건)
        self.set_input_value('상하한포함', 상하한포함)
        self.comm_rq_data('opt10019_req', 'opt10019', '0', '1019')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('시장구분', 시장구분)
            self.set_input_value('등락구분', 등락구분)
            self.set_input_value('시간구분', 시간구분)
            self.set_input_value('시간', 시간)
            self.set_input_value('거래량구분', 거래량구분)
            self.set_input_value('종목조건', 종목조건)
            self.set_input_value('신용조건', 신용조건)
            self.set_input_value('가격조건', 가격조건)
            self.set_input_value('상하한포함', 상하한포함)
            self.comm_rq_data('opt10019_req', 'opt10019', '2', '1019')

    def tr_opt10020(self, 시장구분, 정렬구분, 거래량구분, 종목조건, 신용조건):
        """
        호가잔량상위요청
        """
        self.set_input_value('시장구분', 시장구분)
        self.set_input_value('정렬구분', 정렬구분)
        self.set_input_value('거래량구분', 거래량구분)
        self.set_input_value('종목조건', 종목조건)
        self.set_input_value('신용조건', 신용조건)
        self.comm_rq_data('opt10020_req', 'opt10020', '0', '1020')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('시장구분', 시장구분)
            self.set_input_value('정렬구분', 정렬구분)
            self.set_input_value('거래량구분', 거래량구분)
            self.set_input_value('종목조건', 종목조건)
            self.set_input_value('신용조건', 신용조건)
            self.comm_rq_data('opt10020_req', 'opt10020', '2', '1020')

    def tr_opt10021(self, 시장구분, 매매구분, 정렬구분, 시간구분, 거래량구분, 종목조건):
        """
        호가잔량급증요청
        """
        self.set_input_value('시장구분', 시장구분)
        self.set_input_value('매매구분', 매매구분)
        self.set_input_value('정렬구분', 정렬구분)
        self.set_input_value('시간구분', 시간구분)
        self.set_input_value('거래량구분', 거래량구분)
        self.set_input_value('종목조건', 종목조건)
        self.comm_rq_data('opt10021_req', 'opt10021', '0', '1021')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('시장구분', 시장구분)
            self.set_input_value('매매구분', 매매구분)
            self.set_input_value('정렬구분', 정렬구분)
            self.set_input_value('시간구분', 시간구분)
            self.set_input_value('거래량구분', 거래량구분)
            self.set_input_value('종목조건', 종목조건)
            self.comm_rq_data('opt10021_req', 'opt10021', '2', '1021')

    def tr_opt10022(self, 시장구분, 비율구분, 시간구분, 거래량구분, 종목조건):
        """
        잔량율급증요청
        """
        self.set_input_value('시장구분', 시장구분)
        self.set_input_value('비율구분', 비율구분)
        self.set_input_value('시간구분', 시간구분)
        self.set_input_value('거래량구분', 거래량구분)
        self.set_input_value('종목조건', 종목조건)
        self.comm_rq_data('opt10022_req', 'opt10022', '0', '1022')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('시장구분', 시장구분)
            self.set_input_value('비율구분', 비율구분)
            self.set_input_value('시간구분', 시간구분)
            self.set_input_value('거래량구분', 거래량구분)
            self.set_input_value('종목조건', 종목조건)
            self.comm_rq_data('opt10022_req', 'opt10022', '2', '1022')

    def tr_opt10023(self, 시장구분, 정렬구분, 시간구분, 거래량구분, 시간, 종목조건, 가격구분):
        """
        거래량급증요청
        """
        self.set_input_value('시장구분', 시장구분)
        self.set_input_value('정렬구분', 정렬구분)
        self.set_input_value('시간구분', 시간구분)
        self.set_input_value('거래량구분', 거래량구분)
        self.set_input_value('시간', 시간)
        self.set_input_value('종목조건', 종목조건)
        self.set_input_value('가격구분', 가격구분)
        self.comm_rq_data('opt10023_req', 'opt10023', '0', '1023')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('시장구분', 시장구분)
            self.set_input_value('정렬구분', 정렬구분)
            self.set_input_value('시간구분', 시간구분)
            self.set_input_value('거래량구분', 거래량구분)
            self.set_input_value('시간', 시간)
            self.set_input_value('종목조건', 종목조건)
            self.set_input_value('가격구분', 가격구분)
            self.comm_rq_data('opt10023_req', 'opt10023', '2', '1023')

    def tr_opt10024(self, 시장구분, 주기구분, 거래량구분):
        """
        거래량갱신요청
        """
        self.set_input_value('시장구분', 시장구분)
        self.set_input_value('주기구분', 주기구분)
        self.set_input_value('거래량구분', 거래량구분)
        self.comm_rq_data('opt10024_req', 'opt10024', '0', '1024')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('시장구분', 시장구분)
            self.set_input_value('주기구분', 주기구분)
            self.set_input_value('거래량구분', 거래량구분)
            self.comm_rq_data('opt10024_req', 'opt10024', '2', '1024')

    def tr_opt10025(self, 시장구분, 매물집중비율, 현재가진입, 매물대수, 주기구분):
        """
        매물대집중요청
        """
        self.set_input_value('시장구분', 시장구분)
        self.set_input_value('매물집중비율', 매물집중비율)
        self.set_input_value('현재가진입', 현재가진입)
        self.set_input_value('매물대수', 매물대수)
        self.set_input_value('주기구분', 주기구분)
        self.comm_rq_data('opt10025_req', 'opt10025', '0', '1025')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('시장구분', 시장구분)
            self.set_input_value('매물집중비율', 매물집중비율)
            self.set_input_value('현재가진입', 현재가진입)
            self.set_input_value('매물대수', 매물대수)
            self.set_input_value('주기구분', 주기구분)
            self.comm_rq_data('opt10025_req', 'opt10025', '2', '1025')

    def tr_opt10026(self, PER구분):
        """
        고저PER요청
        """
        self.set_input_value('PER구분', PER구분)
        self.comm_rq_data('opt10026_req', 'opt10026', '0', '1026')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('PER구분', PER구분)
            self.comm_rq_data('opt10026_req', 'opt10026', '2', '1026')

    def tr_opt10027(self, 시장구분, 정렬구분, 거래량조건, 종목조건, 신용조건, 상하한포함, 가격조건, 거래대금조건):
        """
        전일대비등락률상위요청
        """
        self.set_input_value('시장구분', 시장구분)
        self.set_input_value('정렬구분', 정렬구분)
        self.set_input_value('거래량조건', 거래량조건)
        self.set_input_value('종목조건', 종목조건)
        self.set_input_value('신용조건', 신용조건)
        self.set_input_value('상하한포함', 상하한포함)
        self.set_input_value('가격조건', 가격조건)
        self.set_input_value('거래대금조건', 거래대금조건)
        self.comm_rq_data('opt10027_req', 'opt10027', '0', '1027')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('시장구분', 시장구분)
            self.set_input_value('정렬구분', 정렬구분)
            self.set_input_value('거래량조건', 거래량조건)
            self.set_input_value('종목조건', 종목조건)
            self.set_input_value('신용조건', 신용조건)
            self.set_input_value('상하한포함', 상하한포함)
            self.set_input_value('가격조건', 가격조건)
            self.set_input_value('거래대금조건', 거래대금조건)
            self.comm_rq_data('opt10027_req', 'opt10027', '2', '1027')

    def tr_opt10028(self, 정렬구분, 거래량조건, 시장구분, 상하한포함, 종목조건, 신용조건, 거래대금조건, 등락조건):
        """
        시가대비등락률요청
        """
        self.set_input_value('정렬구분', 정렬구분)
        self.set_input_value('거래량조건', 거래량조건)
        self.set_input_value('시장구분', 시장구분)
        self.set_input_value('상하한포함', 상하한포함)
        self.set_input_value('종목조건', 종목조건)
        self.set_input_value('신용조건', 신용조건)
        self.set_input_value('거래대금조건', 거래대금조건)
        self.set_input_value('등락조건', 등락조건)
        self.comm_rq_data('opt10028_req', 'opt10028', '0', '1028')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('정렬구분', 정렬구분)
            self.set_input_value('거래량조건', 거래량조건)
            self.set_input_value('시장구분', 시장구분)
            self.set_input_value('상하한포함', 상하한포함)
            self.set_input_value('종목조건', 종목조건)
            self.set_input_value('신용조건', 신용조건)
            self.set_input_value('거래대금조건', 거래대금조건)
            self.set_input_value('등락조건', 등락조건)
            self.comm_rq_data('opt10028_req', 'opt10028', '2', '1028')

    def tr_opt10029(self, 시장구분, 정렬구분, 거래량조건, 종목조건, 신용조건, 가격조건):
        """
        예상체결등락률상위요청
        """
        self.set_input_value('시장구분', 시장구분)
        self.set_input_value('정렬구분', 정렬구분)
        self.set_input_value('거래량조건', 거래량조건)
        self.set_input_value('종목조건', 종목조건)
        self.set_input_value('신용조건', 신용조건)
        self.set_input_value('가격조건', 가격조건)
        self.comm_rq_data('opt10029_req', 'opt10029', '0', '1029')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('시장구분', 시장구분)
            self.set_input_value('정렬구분', 정렬구분)
            self.set_input_value('거래량조건', 거래량조건)
            self.set_input_value('종목조건', 종목조건)
            self.set_input_value('신용조건', 신용조건)
            self.set_input_value('가격조건', 가격조건)
            self.comm_rq_data('opt10029_req', 'opt10029', '2', '1029')

    def tr_opt10030(self, 시장구분, 정렬구분, 관리종목포함):
        """
        당일거래량상위요청
        """
        self.set_input_value('시장구분', 시장구분)
        self.set_input_value('정렬구분', 정렬구분)
        self.set_input_value('관리종목포함', 관리종목포함)
        self.comm_rq_data('opt10030_req', 'opt10030', '0', '1030')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('시장구분', 시장구분)
            self.set_input_value('정렬구분', 정렬구분)
            self.set_input_value('관리종목포함', 관리종목포함)
            self.comm_rq_data('opt10030_req', 'opt10030', '2', '1030')

    def tr_opt10031(self, 시장구분, 조회구분, 순위시작, 순위끝):
        """
        전일거래량상위요청
        """
        self.set_input_value('시장구분', 시장구분)
        self.set_input_value('조회구분', 조회구분)
        self.set_input_value('순위시작', 순위시작)
        self.set_input_value('순위끝', 순위끝)
        self.comm_rq_data('opt10031_req', 'opt10031', '0', '1031')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('시장구분', 시장구분)
            self.set_input_value('조회구분', 조회구분)
            self.set_input_value('순위시작', 순위시작)
            self.set_input_value('순위끝', 순위끝)
            self.comm_rq_data('opt10031_req', 'opt10031', '2', '1031')

    def tr_opt10032(self, 시장구분, 관리종목포함):
        """
        거래대금상위요청
        """
        self.set_input_value('시장구분', 시장구분)
        self.set_input_value('관리종목포함', 관리종목포함)
        self.comm_rq_data('opt10032_req', 'opt10032', '0', '1032')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('시장구분', 시장구분)
            self.set_input_value('관리종목포함', 관리종목포함)
            self.comm_rq_data('opt10032_req', 'opt10032', '2', '1032')

    def tr_opt10033(self, 시장구분, 거래량구분, 종목조건, 상하한포함, 신용조건):
        """
        신용비율상위요청
        """
        self.set_input_value('시장구분', 시장구분)
        self.set_input_value('거래량구분', 거래량구분)
        self.set_input_value('종목조건', 종목조건)
        self.set_input_value('상하한포함', 상하한포함)
        self.set_input_value('신용조건', 신용조건)
        self.comm_rq_data('opt10033_req', 'opt10033', '0', '1033')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('시장구분', 시장구분)
            self.set_input_value('거래량구분', 거래량구분)
            self.set_input_value('종목조건', 종목조건)
            self.set_input_value('상하한포함', 상하한포함)
            self.set_input_value('신용조건', 신용조건)
            self.comm_rq_data('opt10033_req', 'opt10033', '2', '1033')

    def tr_opt10034(self, 시장구분, 매매구분, 기간):
        """
        외인기간별매매상위요청
        """
        self.set_input_value('시장구분', 시장구분)
        self.set_input_value('매매구분', 매매구분)
        self.set_input_value('기간', 기간)
        self.comm_rq_data('opt10034_req', 'opt10034', '0', '1034')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('시장구분', 시장구분)
            self.set_input_value('매매구분', 매매구분)
            self.set_input_value('기간', 기간)
            self.comm_rq_data('opt10034_req', 'opt10034', '2', '1034')

    def tr_opt10035(self, 시장구분, 매매구분, 기준일구분):
        """
        외인연속순매매상위요청
        """
        self.set_input_value('시장구분', 시장구분)
        self.set_input_value('매매구분', 매매구분)
        self.set_input_value('기준일구분', 기준일구분)
        self.comm_rq_data('opt10035_req', 'opt10035', '0', '1035')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('시장구분', 시장구분)
            self.set_input_value('매매구분', 매매구분)
            self.set_input_value('기준일구분', 기준일구분)
            self.comm_rq_data('opt10035_req', 'opt10035', '2', '1035')

    def tr_opt10036(self, 시장구분, 기간):
        """
        매매상위요청
        """
        self.set_input_value('시장구분', 시장구분)
        self.set_input_value('기간', 기간)
        self.comm_rq_data('opt10036_req', 'opt10036', '0', '1036')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('시장구분', 시장구분)
            self.set_input_value('기간', 기간)
            self.comm_rq_data('opt10036_req', 'opt10036', '2', '1036')

    def tr_opt10037(self, 시장구분, 기간, 매매구분, 정렬구분, 현재가조건):
        """
        외국계창구매매상위요청
        """
        self.set_input_value('시장구분', 시장구분)
        self.set_input_value('기간', 기간)
        self.set_input_value('매매구분', 매매구분)
        self.set_input_value('정렬구분', 정렬구분)
        self.set_input_value('현재가조건', 현재가조건)
        self.comm_rq_data('opt10037_req', 'opt10037', '0', '1037')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('시장구분', 시장구분)
            self.set_input_value('기간', 기간)
            self.set_input_value('매매구분', 매매구분)
            self.set_input_value('정렬구분', 정렬구분)
            self.set_input_value('현재가조건', 현재가조건)
            self.comm_rq_data('opt10037_req', 'opt10037', '2', '1037')

    def tr_opt10038(self, 종목코드, 시작일자, 종료일자, 조회구분, 기간):
        """
        종목별증권사순위요청
        """
        self.set_input_value('종목코드', 종목코드)
        self.set_input_value('시작일자', 시작일자)
        self.set_input_value('종료일자', 종료일자)
        self.set_input_value('조회구분', 조회구분)
        self.set_input_value('기간', 기간)
        self.comm_rq_data('opt10038_req', 'opt10038', '0', '1038')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('종목코드', 종목코드)
            self.set_input_value('시작일자', 시작일자)
            self.set_input_value('종료일자', 종료일자)
            self.set_input_value('조회구분', 조회구분)
            self.set_input_value('기간', 기간)
            self.comm_rq_data('opt10038_req', 'opt10038', '2', '1038')

    def tr_opt10039(self, 회원사코드, 거래량구분, 매매구분, 기간):
        """
        증권사별매매상위요청
        """
        self.set_input_value('회원사코드', 회원사코드)
        self.set_input_value('거래량구분', 거래량구분)
        self.set_input_value('매매구분', 매매구분)
        self.set_input_value('기간', 기간)
        self.comm_rq_data('opt10039_req', 'opt10039', '0', '1039')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('회원사코드', 회원사코드)
            self.set_input_value('거래량구분', 거래량구분)
            self.set_input_value('매매구분', 매매구분)
            self.set_input_value('기간', 기간)
            self.comm_rq_data('opt10039_req', 'opt10039', '2', '1039')

    def tr_opt10040(self, 종목코드):
        """
        당일주요거래원요청
        """
        self.set_input_value('종목코드', 종목코드)
        self.comm_rq_data('opt10040_req', 'opt10040', '0', '1040')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('종목코드', 종목코드)
            self.comm_rq_data('opt10040_req', 'opt10040', '2', '1040')

    def tr_opt10041(self, 종목코드, 영웅클럽구분):
        """
        조기종료통화단위요청
        """
        self.set_input_value('종목코드', 종목코드)
        self.set_input_value('영웅클럽구분', 영웅클럽구분)
        self.comm_rq_data('opt10041_req', 'opt10041', '0', '1041')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('종목코드', 종목코드)
            self.set_input_value('영웅클럽구분', 영웅클럽구분)
            self.comm_rq_data('opt10041_req', 'opt10041', '2', '1041')

    def tr_opt10042(self, 종목코드, 시작일자, 종료일자, 조회기간구분, 시점구분, 기간, 정렬기준):
        """
        순매수거래원순위요청
        """
        self.set_input_value('종목코드', 종목코드)
        self.set_input_value('시작일자', 시작일자)
        self.set_input_value('종료일자', 종료일자)
        self.set_input_value('조회기간구분', 조회기간구분)
        self.set_input_value('시점구분', 시점구분)
        self.set_input_value('기간', 기간)
        self.set_input_value('정렬기준', 정렬기준)
        self.comm_rq_data('opt10042_req', 'opt10042', '0', '1042')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('종목코드', 종목코드)
            self.set_input_value('시작일자', 시작일자)
            self.set_input_value('종료일자', 종료일자)
            self.set_input_value('조회기간구분', 조회기간구분)
            self.set_input_value('시점구분', 시점구분)
            self.set_input_value('기간', 기간)
            self.set_input_value('정렬기준', 정렬기준)
            self.comm_rq_data('opt10042_req', 'opt10042', '2', '1042')

    def tr_opt10043(self, 종목코드, 시작일자, 종료일자, 조회기간구분, 시점구분, 기간, 정렬기준, 회원사코드):
        """
        거래원매물대분석요청
        """
        self.set_input_value('종목코드', 종목코드)
        self.set_input_value('시작일자', 시작일자)
        self.set_input_value('종료일자', 종료일자)
        self.set_input_value('조회기간구분', 조회기간구분)
        self.set_input_value('시점구분', 시점구분)
        self.set_input_value('기간', 기간)
        self.set_input_value('정렬기준', 정렬기준)
        self.set_input_value('회원사코드', 회원사코드)
        self.comm_rq_data('opt10043_req', 'opt10043', '0', '1043')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('종목코드', 종목코드)
            self.set_input_value('시작일자', 시작일자)
            self.set_input_value('종료일자', 종료일자)
            self.set_input_value('조회기간구분', 조회기간구분)
            self.set_input_value('시점구분', 시점구분)
            self.set_input_value('기간', 기간)
            self.set_input_value('정렬기준', 정렬기준)
            self.set_input_value('회원사코드', 회원사코드)
            self.comm_rq_data('opt10043_req', 'opt10043', '2', '1043')

    def tr_opt10044(self, 시작일자, 종료일자, 매매구분, 시장구분):
        """
        일별기관매매종목요청
        """
        self.set_input_value('시작일자', 시작일자)
        self.set_input_value('종료일자', 종료일자)
        self.set_input_value('매매구분', 매매구분)
        self.set_input_value('시장구분', 시장구분)
        self.comm_rq_data('opt10044_req', 'opt10044', '0', '1044')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('시작일자', 시작일자)
            self.set_input_value('종료일자', 종료일자)
            self.set_input_value('매매구분', 매매구분)
            self.set_input_value('시장구분', 시장구분)
            self.comm_rq_data('opt10044_req', 'opt10044', '2', '1044')

    def tr_opt10045(self, 종목코드, 시작일자, 종료일자, 기관추정단가구분, 외인추정단가구분, 누적기간, 기간구분):
        """
        종목별기관매매추이요청
        """
        self.set_input_value('종목코드', 종목코드)
        self.set_input_value('시작일자', 시작일자)
        self.set_input_value('종료일자', 종료일자)
        self.set_input_value('기관추정단가구분', 기관추정단가구분)
        self.set_input_value('외인추정단가구분', 외인추정단가구분)
        self.set_input_value('누적기간', 누적기간)
        self.set_input_value('기간구분', 기간구분)
        self.comm_rq_data('opt10045_req', 'opt10045', '0', '1045')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('종목코드', 종목코드)
            self.set_input_value('시작일자', 시작일자)
            self.set_input_value('종료일자', 종료일자)
            self.set_input_value('기관추정단가구분', 기관추정단가구분)
            self.set_input_value('외인추정단가구분', 외인추정단가구분)
            self.set_input_value('누적기간', 누적기간)
            self.set_input_value('기간구분', 기간구분)
            self.comm_rq_data('opt10045_req', 'opt10045', '2', '1045')

    def tr_opt10048(self, 종목코드):
        """
        ELW일별민감도지표요청
        """
        self.set_input_value('종목코드', 종목코드)
        self.comm_rq_data('opt10048_req', 'opt10048', '0', '1048')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('종목코드', 종목코드)
            self.comm_rq_data('opt10048_req', 'opt10048', '2', '1048')

    def tr_opt10049(self, 연속구분, 연속키, 종목코드):
        """
        ELW투자지표요청
        """
        self.set_input_value('연속구분', 연속구분)
        self.set_input_value('연속키', 연속키)
        self.set_input_value('종목코드', 종목코드)
        self.comm_rq_data('opt10049_req', 'opt10049', '0', '1049')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('연속구분', 연속구분)
            self.set_input_value('연속키', 연속키)
            self.set_input_value('종목코드', 종목코드)
            self.comm_rq_data('opt10049_req', 'opt10049', '2', '1049')

    def tr_opt10050(self, 종목코드):
        """
        ELW민감도지표요청
        """
        self.set_input_value('종목코드', 종목코드)
        self.comm_rq_data('opt10050_req', 'opt10050', '0', '1050')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('종목코드', 종목코드)
            self.comm_rq_data('opt10050_req', 'opt10050', '2', '1050')

    def tr_opt10051(self, 시장구분, 금액수량구분, 기준일자):
        """
        업종별투자자순매수요청
        """
        self.set_input_value('시장구분', 시장구분)
        self.set_input_value('금액수량구분    ', 금액수량구분)
        self.set_input_value('기준일자', 기준일자)
        self.comm_rq_data('opt10051_req', 'opt10051', '0', '1051')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('시장구분', 시장구분)
            self.set_input_value('금액수량구분    ', 금액수량구분)
            self.set_input_value('기준일자', 기준일자)
            self.comm_rq_data('opt10051_req', 'opt10051', '2', '1051')

    def tr_opt10053(self, 종목코드):
        """
        당일상위이탈원요청
        """
        self.set_input_value('종목코드', 종목코드)
        self.comm_rq_data('opt10053_req', 'opt10053', '0', '1053')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('종목코드', 종목코드)
            self.comm_rq_data('opt10053_req', 'opt10053', '2', '1053')

    def tr_opt10055(self, 종목코드, 당일전일):
        """
        당일전일체결대량요청
        """
        self.set_input_value('종목코드', 종목코드)
        self.set_input_value('당일전일          ', 당일전일)
        self.comm_rq_data('opt10055_req', 'opt10055', '0', '1055')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('종목코드', 종목코드)
            self.set_input_value('당일전일          ', 당일전일)
            self.comm_rq_data('opt10055_req', 'opt10055', '2', '1055')

    def tr_opt10058(self, 시작일자, 종료일자, 매매구분, 시장구분, 투자자구분):
        """
        투자자별일별매매종목요청
        """
        self.set_input_value('시작일자', 시작일자)
        self.set_input_value('종료일자', 종료일자)
        self.set_input_value('매매구분', 매매구분)
        self.set_input_value('시장구분', 시장구분)
        self.set_input_value('투자자구분', 투자자구분)
        self.comm_rq_data('opt10058_req', 'opt10058', '0', '1058')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('시작일자', 시작일자)
            self.set_input_value('종료일자', 종료일자)
            self.set_input_value('매매구분', 매매구분)
            self.set_input_value('시장구분', 시장구분)
            self.set_input_value('투자자구분', 투자자구분)
            self.comm_rq_data('opt10058_req', 'opt10058', '2', '1058')

    def tr_opt10059(self, 일자, 종목코드, 금액수량구분, 매매구분, 단위구분):
        """
        종목별투자자기관별요청
        """
        self.set_input_value('일자', 일자)
        self.set_input_value('종목코드', 종목코드)
        self.set_input_value('금액수량구분', 금액수량구분)
        self.set_input_value('매매구분', 매매구분)
        self.set_input_value('단위구분', 단위구분)
        self.comm_rq_data('opt10059_req', 'opt10059', '0', '1059')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('일자', 일자)
            self.set_input_value('종목코드', 종목코드)
            self.set_input_value('금액수량구분', 금액수량구분)
            self.set_input_value('매매구분', 매매구분)
            self.set_input_value('단위구분', 단위구분)
            self.comm_rq_data('opt10059_req', 'opt10059', '2', '1059')

    def tr_opt10060(self, 일자, 종목코드, 금액수량구분, 매매구분, 단위구분):
        """
        종목별투자자기관별차트요청
        """
        self.set_input_value('일자', 일자)
        self.set_input_value('종목코드', 종목코드)
        self.set_input_value('금액수량구분', 금액수량구분)
        self.set_input_value('매매구분', 매매구분)
        self.set_input_value('단위구분', 단위구분)
        self.comm_rq_data('opt10060_req', 'opt10060', '0', '1060')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('일자', 일자)
            self.set_input_value('종목코드', 종목코드)
            self.set_input_value('금액수량구분', 금액수량구분)
            self.set_input_value('매매구분', 매매구분)
            self.set_input_value('단위구분', 단위구분)
            self.comm_rq_data('opt10060_req', 'opt10060', '2', '1060')

    def tr_opt10061(self, 종목코드, 시작일자, 종료일자, 금액수량구분, 매매구분, 단위구분):
        """
        종목별투자자기관별합계요청
        """
        self.set_input_value('종목코드', 종목코드)
        self.set_input_value('시작일자', 시작일자)
        self.set_input_value('종료일자', 종료일자)
        self.set_input_value('금액수량구분', 금액수량구분)
        self.set_input_value('매매구분', 매매구분)
        self.set_input_value('단위구분', 단위구분)
        self.comm_rq_data('opt10061_req', 'opt10061', '0', '1061')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('종목코드', 종목코드)
            self.set_input_value('시작일자', 시작일자)
            self.set_input_value('종료일자', 종료일자)
            self.set_input_value('금액수량구분', 금액수량구분)
            self.set_input_value('매매구분', 매매구분)
            self.set_input_value('단위구분', 단위구분)
            self.comm_rq_data('opt10061_req', 'opt10061', '2', '1061')

    def tr_opt10062(self, 시작일자, 종료일자, 시장구분, 매매구분, 정렬조건, 단위구분):
        """
        동일순매매순위요청
        """
        self.set_input_value('시작일자', 시작일자)
        self.set_input_value('종료일자', 종료일자)
        self.set_input_value('시장구분', 시장구분)
        self.set_input_value('매매구분', 매매구분)
        self.set_input_value('정렬조건', 정렬조건)
        self.set_input_value('단위구분', 단위구분)
        self.comm_rq_data('opt10062_req', 'opt10062', '0', '1062')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('시작일자', 시작일자)
            self.set_input_value('종료일자', 종료일자)
            self.set_input_value('시장구분', 시장구분)
            self.set_input_value('매매구분', 매매구분)
            self.set_input_value('정렬조건', 정렬조건)
            self.set_input_value('단위구분', 단위구분)
            self.comm_rq_data('opt10062_req', 'opt10062', '2', '1062')

    def tr_opt10063(self, 시장구분, 금액수량구분, 투자자별, 외국계전체, 동시순매수구분):
        """
        장중투자자별매매요청
        """
        self.set_input_value('시장구분', 시장구분)
        self.set_input_value('금액수량구분', 금액수량구분)
        self.set_input_value('투자자별', 투자자별)
        self.set_input_value('외국계전체', 외국계전체)
        self.set_input_value('동시순매수구분', 동시순매수구분)
        self.comm_rq_data('opt10063_req', 'opt10063', '0', '1063')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('시장구분', 시장구분)
            self.set_input_value('금액수량구분', 금액수량구분)
            self.set_input_value('투자자별', 투자자별)
            self.set_input_value('외국계전체', 외국계전체)
            self.set_input_value('동시순매수구분', 동시순매수구분)
            self.comm_rq_data('opt10063_req', 'opt10063', '2', '1063')

    def tr_opt10064(self, 시장구분, 금액수량구분, 매매구분, 종목코드):
        """
        장중투자자별매매차트요청
        """
        self.set_input_value('시장구분', 시장구분)
        self.set_input_value('금액수량구분', 금액수량구분)
        self.set_input_value('매매구분', 매매구분)
        self.set_input_value('종목코드', 종목코드)
        self.comm_rq_data('opt10064_req', 'opt10064', '0', '1064')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('시장구분', 시장구분)
            self.set_input_value('금액수량구분', 금액수량구분)
            self.set_input_value('매매구분', 매매구분)
            self.set_input_value('종목코드', 종목코드)
            self.comm_rq_data('opt10064_req', 'opt10064', '2', '1064')

    def tr_opt10065(self, 매매구분, 시장구분, 기관구분):
        """
        장중투자자별매매상위요청
        """
        self.set_input_value('매매구분', 매매구분)
        self.set_input_value('시장구분', 시장구분)
        self.set_input_value('기관구분', 기관구분)
        self.comm_rq_data('opt10065_req', 'opt10065', '0', '1065')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('매매구분', 매매구분)
            self.set_input_value('시장구분', 시장구분)
            self.set_input_value('기관구분', 기관구분)
            self.comm_rq_data('opt10065_req', 'opt10065', '2', '1065')

    def tr_opt10066(self, 시장구분, 금액수량구분, 매매구분, 종목코드):
        """
        장중투자자별매매차트요청
        """
        self.set_input_value('시장구분', 시장구분)
        self.set_input_value('금액수량구분', 금액수량구분)
        self.set_input_value('매매구분', 매매구분)
        self.set_input_value('종목코드', 종목코드)
        self.comm_rq_data('opt10066_req', 'opt10066', '0', '1066')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('시장구분', 시장구분)
            self.set_input_value('금액수량구분', 금액수량구분)
            self.set_input_value('매매구분', 매매구분)
            self.set_input_value('종목코드', 종목코드)
            self.comm_rq_data('opt10066_req', 'opt10066', '2', '1066')

    def tr_opt10067(self, 기준일자, 시장구분):
        """
        대차거래내역요청
        """
        self.set_input_value('기준일자', 기준일자)
        self.set_input_value('시장구분', 시장구분)
        self.comm_rq_data('opt10067_req', 'opt10067', '0', '1067')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('기준일자', 기준일자)
            self.set_input_value('시장구분', 시장구분)
            self.comm_rq_data('opt10067_req', 'opt10067', '2', '1067')

    def tr_opt10068(self, 시작일자, 종료일자, 전체구분, 종목코드):
        """
        대차거래추이요청
        """
        self.set_input_value('시작일자', 시작일자)
        self.set_input_value('종료일자', 종료일자)
        self.set_input_value('전체구분', 전체구분)
        self.set_input_value('종목코드', 종목코드)
        self.comm_rq_data('opt10068_req', 'opt10068', '0', '1068')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('시작일자', 시작일자)
            self.set_input_value('종료일자', 종료일자)
            self.set_input_value('전체구분', 전체구분)
            self.set_input_value('종목코드', 종목코드)
            self.comm_rq_data('opt10068_req', 'opt10068', '2', '1068')

    def tr_opt10069(self, 시작일자, 종료일자, 시장구분):
        """
        대차거래상위10종목요청
        """
        self.set_input_value('시작일자', 시작일자)
        self.set_input_value('종료일자', 종료일자)
        self.set_input_value('시장구분', 시장구분)
        self.comm_rq_data('opt10069_req', 'opt10069', '0', '1069')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('시작일자', 시작일자)
            self.set_input_value('종료일자', 종료일자)
            self.set_input_value('시장구분', 시장구분)
            self.comm_rq_data('opt10069_req', 'opt10069', '2', '1069')

    def tr_opt10070(self, 종목코드):
        """
        당일주요거래원요청
        """
        self.set_input_value('종목코드', 종목코드)
        self.comm_rq_data('opt10070_req', 'opt10070', '0', '1070')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('종목코드', 종목코드)
            self.comm_rq_data('opt10070_req', 'opt10070', '2', '1070')

    def tr_opt10071(self, 종목코드, 시간구분):
        """
        시간대별전일비거래비중요청
        """
        self.set_input_value('종목코드', 종목코드)
        self.set_input_value('시간구분', 시간구분)
        self.comm_rq_data('opt10071_req', 'opt10071', '0', '1071')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('종목코드', 종목코드)
            self.set_input_value('시간구분', 시간구분)
            self.comm_rq_data('opt10071_req', 'opt10071', '2', '1071')

    def tr_opt10072(self, 계좌번호, 종목코드, 시작일자):
        """
        일자별종목별실현손익요청
        """
        self.set_input_value('계좌번호', 계좌번호)
        self.set_input_value('종목코드', 종목코드)
        self.set_input_value('시작일자', 시작일자)
        self.comm_rq_data('opt10072_req', 'opt10072', '0', '1072')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('계좌번호', 계좌번호)
            self.set_input_value('종목코드', 종목코드)
            self.set_input_value('시작일자', 시작일자)
            self.comm_rq_data('opt10072_req', 'opt10072', '2', '1072')

    def tr_opt10073(self, 계좌번호, 종목코드, 시작일자, 종료일자):
        """
        일자별종목별실현손익요청
        """
        self.set_input_value('계좌번호', 계좌번호)
        self.set_input_value('종목코드', 종목코드)
        self.set_input_value('시작일자', 시작일자)
        self.set_input_value('종료일자', 종료일자)
        self.comm_rq_data('opt10073_req', 'opt10073', '0', '1073')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('계좌번호', 계좌번호)
            self.set_input_value('종목코드', 종목코드)
            self.set_input_value('시작일자', 시작일자)
            self.set_input_value('종료일자', 종료일자)
            self.comm_rq_data('opt10073_req', 'opt10073', '2', '1073')

    def tr_opt10074(self, 계좌번호, 시작일자, 종료일자):
        """
        일자별실현손익요청
        """
        self.set_input_value('계좌번호', 계좌번호)
        self.set_input_value('시작일자', 시작일자)
        self.set_input_value('종료일자', 종료일자)
        self.comm_rq_data('opt10074_req', 'opt10074', '0', '1074')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('계좌번호', 계좌번호)
            self.set_input_value('시작일자', 시작일자)
            self.set_input_value('종료일자', 종료일자)
            self.comm_rq_data('opt10074_req', 'opt10074', '2', '1074')

    def tr_opt10075(self, 계좌번호, 체결구분, 매매구분):
        """
        실시간미체결요청
        """
        self.set_input_value('계좌번호', 계좌번호)
        self.set_input_value('체결구분', 체결구분)
        self.set_input_value('매매구분', 매매구분)
        self.comm_rq_data('opt10075_req', 'opt10075', '0', '1075')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('계좌번호', 계좌번호)
            self.set_input_value('체결구분', 체결구분)
            self.set_input_value('매매구분', 매매구분)
            self.comm_rq_data('opt10075_req', 'opt10075', '2', '1075')

    def tr_opt10076(self, 종목코드, 조회구분, 모름2, 계좌번호, 비밀번호, 모름3):
        """
        실시간체결요청
        """
        self.set_input_value('종목코드', 종목코드)
        self.set_input_value('조회구분', 조회구분)
        self.set_input_value('모름2', 모름2)
        self.set_input_value('계좌번호', 계좌번호)
        self.set_input_value('비밀번호', 비밀번호)
        self.set_input_value('모름3', 모름3)
        self.comm_rq_data('opt10076_req', 'opt10076', '0', '1076')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('종목코드', 종목코드)
            self.set_input_value('조회구분', 조회구분)
            self.set_input_value('모름2', 모름2)
            self.set_input_value('계좌번호', 계좌번호)
            self.set_input_value('비밀번호', 비밀번호)
            self.set_input_value('모름3', 모름3)
            self.comm_rq_data('opt10076_req', 'opt10076', '2', '1076')

    def tr_opt10077(self, 계좌번호, 비밀번호, 종목코드):
        """
        당일실현손익상세요청
        """
        self.set_input_value('계좌번호', 계좌번호)
        self.set_input_value('비밀번호', 비밀번호)
        self.set_input_value('종목코드', 종목코드)
        self.comm_rq_data('opt10077_req', 'opt10077', '0', '1077')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('계좌번호', 계좌번호)
            self.set_input_value('비밀번호', 비밀번호)
            self.set_input_value('종목코드', 종목코드)
            self.comm_rq_data('opt10077_req', 'opt10077', '2', '1077')

    def tr_opt10078(self, 회원사코드, 종목코드, 시작일자, 종료일자):
        """
        증권사별종목매매동향요청
        """
        self.set_input_value('회원사코드', 회원사코드)
        self.set_input_value('종목코드', 종목코드)
        self.set_input_value('시작일자', 시작일자)
        self.set_input_value('종료일자', 종료일자)
        self.comm_rq_data('opt10078_req', 'opt10078', '0', '1078')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('회원사코드', 회원사코드)
            self.set_input_value('종목코드', 종목코드)
            self.set_input_value('시작일자', 시작일자)
            self.set_input_value('종료일자', 종료일자)
            self.comm_rq_data('opt10078_req', 'opt10078', '2', '1078')

    def tr_opt10079(self, 종목코드, 틱범위, 수정주가구분):
        """
        주식틱차트조회요청
        """
        self.set_input_value('종목코드', 종목코드)
        self.set_input_value('틱범위', 틱범위)
        self.set_input_value('수정주가구분', 수정주가구분)
        self.comm_rq_data('opt10079_req', 'opt10079', '0', '1079')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('종목코드', 종목코드)
            self.set_input_value('틱범위', 틱범위)
            self.set_input_value('수정주가구분', 수정주가구분)
            self.comm_rq_data('opt10079_req', 'opt10079', '2', '1079')

    def tr_opt10080(self, 종목코드, 틱범위, 수정주가구분):
        """
        주식분봉차트조회요청
        """
        self.set_input_value('종목코드', 종목코드)
        self.set_input_value('틱범위', 틱범위)
        self.set_input_value('수정주가구분', 수정주가구분)
        self.comm_rq_data('opt10080_req', 'opt10080', '0', '1080')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('종목코드', 종목코드)
            self.set_input_value('틱범위', 틱범위)
            self.set_input_value('수정주가구분', 수정주가구분)
            self.comm_rq_data('opt10080_req', 'opt10080', '2', '1080')

    def tr_opt10081(self, 종목코드, 기준일자, 수정주가구분):
        """
        주식일봉차트조회요청
        """
        self.set_input_value('종목코드', 종목코드)
        self.set_input_value('기준일자', 기준일자)
        self.set_input_value('수정주가구분', 수정주가구분)
        self.comm_rq_data('opt10081_req', 'opt10081', '0', '1081')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('종목코드', 종목코드)
            self.set_input_value('기준일자', 기준일자)
            self.set_input_value('수정주가구분', 수정주가구분)
            self.comm_rq_data('opt10081_req', 'opt10081', '2', '1081')

    def tr_opt10082(self, 종목코드, 기준일자, 끝일자, 수정주가구분):
        """
        주식주봉차트조회요청
        """
        self.set_input_value('종목코드', 종목코드)
        self.set_input_value('기준일자', 기준일자)
        self.set_input_value('끝일자  ', 끝일자)
        self.set_input_value('수정주가구분', 수정주가구분)
        self.comm_rq_data('opt10082_req', 'opt10082', '0', '1082')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('종목코드', 종목코드)
            self.set_input_value('기준일자', 기준일자)
            self.set_input_value('끝일자  ', 끝일자)
            self.set_input_value('수정주가구분', 수정주가구분)
            self.comm_rq_data('opt10082_req', 'opt10082', '2', '1082')

    def tr_opt10083(self, 종목코드, 기준일자, 끝일자, 수정주가구분):
        """
        주식월봉차트조회요청
        """
        self.set_input_value('종목코드', 종목코드)
        self.set_input_value('기준일자', 기준일자)
        self.set_input_value('끝일자  ', 끝일자)
        self.set_input_value('수정주가구분', 수정주가구분)
        self.comm_rq_data('opt10083_req', 'opt10083', '0', '1083')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('종목코드', 종목코드)
            self.set_input_value('기준일자', 기준일자)
            self.set_input_value('끝일자  ', 끝일자)
            self.set_input_value('수정주가구분', 수정주가구분)
            self.comm_rq_data('opt10083_req', 'opt10083', '2', '1083')

    def tr_opt10084(self, 종목코드, 당일전일, 틱분, 시간):
        """
        당일전일체결요청
        """
        self.set_input_value('종목코드', 종목코드)
        self.set_input_value('당일전일          ', 당일전일)
        self.set_input_value('틱분              ', 틱분)
        self.set_input_value('시간              ', 시간)
        self.comm_rq_data('opt10084_req', 'opt10084', '0', '1084')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('종목코드', 종목코드)
            self.set_input_value('당일전일          ', 당일전일)
            self.set_input_value('틱분              ', 틱분)
            self.set_input_value('시간              ', 시간)
            self.comm_rq_data('opt10084_req', 'opt10084', '2', '1084')

    def tr_opt10085(self, 계좌번호):
        """
        계좌수익률요청
        """
        self.set_input_value('계좌번호', 계좌번호)
        self.comm_rq_data('opt10085_req', 'opt10085', '0', '1085')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('계좌번호', 계좌번호)
            self.comm_rq_data('opt10085_req', 'opt10085', '2', '1085')

    def tr_opt10086(self, 종목코드, 조회일자, 표시구분):
        """
        일별주가요청
        """
        self.set_input_value('종목코드', 종목코드)
        self.set_input_value('조회일자  ', 조회일자)
        self.set_input_value('표시구분  ', 표시구분)
        self.comm_rq_data('opt10086_req', 'opt10086', '0', '1086')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('종목코드', 종목코드)
            self.set_input_value('조회일자  ', 조회일자)
            self.set_input_value('표시구분  ', 표시구분)
            self.comm_rq_data('opt10086_req', 'opt10086', '2', '1086')

    def tr_opt10087(self, 종목코드):
        """
        시간외단일가요청
        """
        self.set_input_value('종목코드', 종목코드)
        self.comm_rq_data('opt10087_req', 'opt10087', '0', '1087')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('종목코드', 종목코드)
            self.comm_rq_data('opt10087_req', 'opt10087', '2', '1087')

    def tr_opt10094(self, 종목코드, 기준일자, 끝일자, 수정주가구분):
        """
        주식년봉차트조회요청
        """
        self.set_input_value('종목코드', 종목코드)
        self.set_input_value('기준일자', 기준일자)
        self.set_input_value('끝일자  ', 끝일자)
        self.set_input_value('수정주가구분', 수정주가구분)
        self.comm_rq_data('opt10094_req', 'opt10094', '0', '1094')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('종목코드', 종목코드)
            self.set_input_value('기준일자', 기준일자)
            self.set_input_value('끝일자  ', 끝일자)
            self.set_input_value('수정주가구분', 수정주가구분)
            self.comm_rq_data('opt10094_req', 'opt10094', '2', '1094')

    def tr_opt20001(self, 시장구분, 업종코드):
        """
        업종현재가요청
        """
        self.set_input_value('시장구분', 시장구분)
        self.set_input_value('업종코드', 업종코드)
        self.comm_rq_data('opt20001_req', 'opt20001', '0', '2001')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('시장구분', 시장구분)
            self.set_input_value('업종코드', 업종코드)
            self.comm_rq_data('opt20001_req', 'opt20001', '2', '2001')

    def tr_opt20002(self, 시장구분, 업종코드):
        """
        업종별주가요청
        """
        self.set_input_value('시장구분', 시장구분)
        self.set_input_value('업종코드', 업종코드)
        self.comm_rq_data('opt20002_req', 'opt20002', '0', '2002')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('시장구분', 시장구분)
            self.set_input_value('업종코드', 업종코드)
            self.comm_rq_data('opt20002_req', 'opt20002', '2', '2002')

    def tr_opt20003(self, 업종코드):
        """
        전업종지수요청
        """
        self.set_input_value('업종코드', 업종코드)
        self.comm_rq_data('opt20003_req', 'opt20003', '0', '2003')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('업종코드', 업종코드)
            self.comm_rq_data('opt20003_req', 'opt20003', '2', '2003')

    def tr_opt20004(self, 업종코드, 틱범위):
        """
        업종틱차트조회요청
        """
        self.set_input_value('업종코드', 업종코드)
        self.set_input_value('틱범위', 틱범위)
        self.comm_rq_data('opt20004_req', 'opt20004', '0', '2004')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('업종코드', 업종코드)
            self.set_input_value('틱범위', 틱범위)
            self.comm_rq_data('opt20004_req', 'opt20004', '2', '2004')

    def tr_opt20005(self, 업종코드, 틱범위):
        """
        업종분봉조회요청
        """
        self.set_input_value('업종코드', 업종코드)
        self.set_input_value('틱범위', 틱범위)
        self.comm_rq_data('opt20005_req', 'opt20005', '0', '2005')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('업종코드', 업종코드)
            self.set_input_value('틱범위', 틱범위)
            self.comm_rq_data('opt20005_req', 'opt20005', '2', '2005')

    def tr_opt20006(self, 업종코드, 기준일자):
        """
        업종일봉조회요청
        """
        self.set_input_value('업종코드', 업종코드)
        self.set_input_value('기준일자', 기준일자)
        self.comm_rq_data('opt20006_req', 'opt20006', '0', '2006')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('업종코드', 업종코드)
            self.set_input_value('기준일자', 기준일자)
            self.comm_rq_data('opt20006_req', 'opt20006', '2', '2006')

    def tr_opt20007(self, 업종코드, 기준일자):
        """
        업종주봉조회요청
        """
        self.set_input_value('업종코드', 업종코드)
        self.set_input_value('기준일자', 기준일자)
        self.comm_rq_data('opt20007_req', 'opt20007', '0', '2007')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('업종코드', 업종코드)
            self.set_input_value('기준일자', 기준일자)
            self.comm_rq_data('opt20007_req', 'opt20007', '2', '2007')

    def tr_opt20008(self, 업종코드, 기준일자):
        """
        업종월봉조회요청
        """
        self.set_input_value('업종코드', 업종코드)
        self.set_input_value('기준일자', 기준일자)
        self.comm_rq_data('opt20008_req', 'opt20008', '0', '2008')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('업종코드', 업종코드)
            self.set_input_value('기준일자', 기준일자)
            self.comm_rq_data('opt20008_req', 'opt20008', '2', '2008')

    def tr_opt20009(self, 시장구분, 업종코드):
        """
        업종현재가일별요청
        """
        self.set_input_value('시장구분', 시장구분)
        self.set_input_value('업종코드', 업종코드)
        self.comm_rq_data('opt20009_req', 'opt20009', '0', '2009')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('시장구분', 시장구분)
            self.set_input_value('업종코드', 업종코드)
            self.comm_rq_data('opt20009_req', 'opt20009', '2', '2009')

    def tr_opt20019(self, 업종코드, 기준일자):
        """
        업종년봉조회요청
        """
        self.set_input_value('업종코드', 업종코드)
        self.set_input_value('기준일자', 기준일자)
        self.comm_rq_data('opt20019_req', 'opt20019', '0', '2019')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('업종코드', 업종코드)
            self.set_input_value('기준일자', 기준일자)
            self.comm_rq_data('opt20019_req', 'opt20019', '2', '2019')

    def tr_opt20068(self, 시작일자, 종료일자, 전체구분, 종목코드):
        """
        대차거래추이요청(종목별)
        """
        self.set_input_value('시작일자', 시작일자)
        self.set_input_value('종료일자', 종료일자)
        self.set_input_value('전체구분', 전체구분)
        self.set_input_value('종목코드', 종목코드)
        self.comm_rq_data('opt20068_req', 'opt20068', '0', '2068')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('시작일자', 시작일자)
            self.set_input_value('종료일자', 종료일자)
            self.set_input_value('전체구분', 전체구분)
            self.set_input_value('종목코드', 종목코드)
            self.comm_rq_data('opt20068_req', 'opt20068', '2', '2068')

    def tr_opt30001(self, 등락구분, 시간구분, 시간, 거래량구분, 발행사코드, 기초자산코드, 권리구분, LP코드, 거래종료ELW제외):
        """
        ELW가격급등락요청
        """
        self.set_input_value('등락구분', 등락구분)
        self.set_input_value('시간구분', 시간구분)
        self.set_input_value('시간', 시간)
        self.set_input_value('거래량구분', 거래량구분)
        self.set_input_value('발행사코드', 발행사코드)
        self.set_input_value('기초자산코드', 기초자산코드)
        self.set_input_value('권리구분', 권리구분)
        self.set_input_value('LP코드', LP코드)
        self.set_input_value('거래종료ELW제외', 거래종료ELW제외)
        self.comm_rq_data('opt30001_req', 'opt30001', '0', '3001')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('등락구분', 등락구분)
            self.set_input_value('시간구분', 시간구분)
            self.set_input_value('시간', 시간)
            self.set_input_value('거래량구분', 거래량구분)
            self.set_input_value('발행사코드', 발행사코드)
            self.set_input_value('기초자산코드', 기초자산코드)
            self.set_input_value('권리구분', 권리구분)
            self.set_input_value('LP코드', LP코드)
            self.set_input_value('거래종료ELW제외', 거래종료ELW제외)
            self.comm_rq_data('opt30001_req', 'opt30001', '2', '3001')

    def tr_opt30002(self, 발행사코드, 거래량구분, 매매구분, 기간, 거래종료ELW제외):
        """
        거래원별ELW순매매상위요청
        """
        self.set_input_value('발행사코드', 발행사코드)
        self.set_input_value('거래량구분', 거래량구분)
        self.set_input_value('매매구분', 매매구분)
        self.set_input_value('기간', 기간)
        self.set_input_value('거래종료ELW제외', 거래종료ELW제외)
        self.comm_rq_data('opt30002_req', 'opt30002', '0', '3002')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('발행사코드', 발행사코드)
            self.set_input_value('거래량구분', 거래량구분)
            self.set_input_value('매매구분', 매매구분)
            self.set_input_value('기간', 기간)
            self.set_input_value('거래종료ELW제외', 거래종료ELW제외)
            self.comm_rq_data('opt30002_req', 'opt30002', '2', '3002')

    def tr_opt30003(self, 기초자산코드, 기준일자):
        """
        ELWLP보유일별추이요청
        """
        self.set_input_value('기초자산코드', 기초자산코드)
        self.set_input_value('기준일자', 기준일자)
        self.comm_rq_data('opt30003_req', 'opt30003', '0', '3003')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('기초자산코드', 기초자산코드)
            self.set_input_value('기준일자', 기준일자)
            self.comm_rq_data('opt30003_req', 'opt30003', '2', '3003')

    def tr_opt30004(self, 발행사코드, 기초자산코드, 권리구분, LP코드, 거래종료ELW제외):
        """
        ELW괴리율요청
        """
        self.set_input_value('발행사코드', 발행사코드)
        self.set_input_value('기초자산코드', 기초자산코드)
        self.set_input_value('권리구분', 권리구분)
        self.set_input_value('LP코드', LP코드)
        self.set_input_value('거래종료ELW제외', 거래종료ELW제외)
        self.comm_rq_data('opt30004_req', 'opt30004', '0', '3004')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('발행사코드', 발행사코드)
            self.set_input_value('기초자산코드', 기초자산코드)
            self.set_input_value('권리구분', 권리구분)
            self.set_input_value('LP코드', LP코드)
            self.set_input_value('거래종료ELW제외', 거래종료ELW제외)
            self.comm_rq_data('opt30004_req', 'opt30004', '2', '3004')

    def tr_opt30005(self, 발행사코드, 기초자산코드, 권리구분, LP코드, 정렬구분):
        """
        ELW조건검색요청
        """
        self.set_input_value('발행사코드', 발행사코드)
        self.set_input_value('기초자산코드', 기초자산코드)
        self.set_input_value('권리구분', 권리구분)
        self.set_input_value('LP코드', LP코드)
        self.set_input_value('정렬구분', 정렬구분)
        self.comm_rq_data('opt30005_req', 'opt30005', '0', '3005')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('발행사코드', 발행사코드)
            self.set_input_value('기초자산코드', 기초자산코드)
            self.set_input_value('권리구분', 권리구분)
            self.set_input_value('LP코드', LP코드)
            self.set_input_value('정렬구분', 정렬구분)
            self.comm_rq_data('opt30005_req', 'opt30005', '2', '3005')

    def tr_opt30006(self, 종목코드):
        """
        ELW종목상세요청
        """
        self.set_input_value('종목코드', 종목코드)
        self.comm_rq_data('opt30006_req', 'opt30006', '0', '3006')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('종목코드', 종목코드)
            self.comm_rq_data('opt30006_req', 'opt30006', '2', '3006')

    def tr_opt30007(self, 발행사코드, 기초자산코드, 권리구분, LP코드, 정렬구분, 거래종료ELW제외):
        """
        ELW종목상세요청
        """
        self.set_input_value('발행사코드', 발행사코드)
        self.set_input_value('기초자산코드', 기초자산코드)
        self.set_input_value('권리구분', 권리구분)
        self.set_input_value('LP코드', LP코드)
        self.set_input_value('정렬구분', 정렬구분)
        self.set_input_value('거래종료ELW제외', 거래종료ELW제외)
        self.comm_rq_data('opt30007_req', 'opt30007', '0', '3007')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('발행사코드', 발행사코드)
            self.set_input_value('기초자산코드', 기초자산코드)
            self.set_input_value('권리구분', 권리구분)
            self.set_input_value('LP코드', LP코드)
            self.set_input_value('정렬구분', 정렬구분)
            self.set_input_value('거래종료ELW제외', 거래종료ELW제외)
            self.comm_rq_data('opt30007_req', 'opt30007', '2', '3007')

    def tr_opt30008(self, 종목코드):
        """
        ELW민감도지표요청
        """
        self.set_input_value('종목코드', 종목코드)
        self.comm_rq_data('opt30008_req', 'opt30008', '0', '3008')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('종목코드', 종목코드)
            self.comm_rq_data('opt30008_req', 'opt30008', '2', '3008')

    def tr_opt30009(self, 정렬구분, 권리구분, 거래종료제외):
        """
        ELW등락율순위요청
        """
        self.set_input_value('정렬구분', 정렬구분)
        self.set_input_value('권리구분', 권리구분)
        self.set_input_value('거래종료제외', 거래종료제외)
        self.comm_rq_data('opt30009_req', 'opt30009', '0', '3009')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('정렬구분', 정렬구분)
            self.set_input_value('권리구분', 권리구분)
            self.set_input_value('거래종료제외', 거래종료제외)
            self.comm_rq_data('opt30009_req', 'opt30009', '2', '3009')

    def tr_opt30010(self, 정렬구분, 권리구분, 거래종료제외):
        """
        ELW잔량순위요청
        """
        self.set_input_value('정렬구분', 정렬구분)
        self.set_input_value('권리구분', 권리구분)
        self.set_input_value('거래종료제외', 거래종료제외)
        self.comm_rq_data('opt30010_req', 'opt30010', '0', '3010')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('정렬구분', 정렬구분)
            self.set_input_value('권리구분', 권리구분)
            self.set_input_value('거래종료제외', 거래종료제외)
            self.comm_rq_data('opt30010_req', 'opt30010', '2', '3010')

    def tr_opt30011(self, 종목코드):
        """
        ELW근접율요청
        """
        self.set_input_value('종목코드', 종목코드)
        self.comm_rq_data('opt30011_req', 'opt30011', '0', '3011')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('종목코드', 종목코드)
            self.comm_rq_data('opt30011_req', 'opt30011', '2', '3011')

    def tr_opt30012(self, 종목코드):
        """
        ELW종목상세정보요청
        """
        self.set_input_value('종목코드', 종목코드)
        self.comm_rq_data('opt30012_req', 'opt30012', '0', '3012')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('종목코드', 종목코드)
            self.comm_rq_data('opt30012_req', 'opt30012', '2', '3012')

    def tr_opt40001(self, 종목코드, 모름, 기간, ):
        """
        ETF수익율요청
        """
        self.set_input_value('종목코드', 종목코드)
        self.set_input_value('모름', 모름)
        self.set_input_value('기간', 기간)
        self.set_input_value('', )
        self.comm_rq_data('opt40001_req', 'opt40001', '0', '4001')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('종목코드', 종목코드)
            self.set_input_value('모름', 모름)
            self.set_input_value('기간', 기간)
            self.set_input_value('', )
            self.comm_rq_data('opt40001_req', 'opt40001', '2', '4001')

    def tr_opt40002(self, 종목코드):
        """
        ETF종목정보요청
        """
        self.set_input_value('종목코드', 종목코드)
        self.comm_rq_data('opt40002_req', 'opt40002', '0', '4002')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('종목코드', 종목코드)
            self.comm_rq_data('opt40002_req', 'opt40002', '2', '4002')

    def tr_opt40003(self, 종목코드):
        """
        ETF일별추이요청
        """
        self.set_input_value('종목코드', 종목코드)
        self.comm_rq_data('opt40003_req', 'opt40003', '0', '4003')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('종목코드', 종목코드)
            self.comm_rq_data('opt40003_req', 'opt40003', '2', '4003')

    def tr_opt40004(self, 과세유형, NAV대비, 운용사, 과세여부, 추적지수):
        """
        ETF전체시세요청
        """
        self.set_input_value('과세유형', 과세유형)
        self.set_input_value('NAV대비', NAV대비)
        self.set_input_value('운용사', 운용사)
        self.set_input_value('과세여부', 과세여부)
        self.set_input_value('추적지수', 추적지수)
        self.comm_rq_data('opt40004_req', 'opt40004', '0', '4004')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('과세유형', 과세유형)
            self.set_input_value('NAV대비', NAV대비)
            self.set_input_value('운용사', 운용사)
            self.set_input_value('과세여부', 과세여부)
            self.set_input_value('추적지수', 추적지수)
            self.comm_rq_data('opt40004_req', 'opt40004', '2', '4004')

    def tr_opt40005(self, 종목코드):
        """
        ETF일별추이요청
        """
        self.set_input_value('종목코드', 종목코드)
        self.comm_rq_data('opt40005_req', 'opt40005', '0', '4005')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('종목코드', 종목코드)
            self.comm_rq_data('opt40005_req', 'opt40005', '2', '4005')

    def tr_opt40006(self, ):
        """
        ETF시간대별추이요청
        """
        self.set_input_value('', )
        self.comm_rq_data('opt40006_req', 'opt40006', '0', '4006')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('', )
            self.comm_rq_data('opt40006_req', 'opt40006', '2', '4006')

    def tr_opt40007(self, 종목코드):
        """
        ETF시간대별체결요청
        """
        self.set_input_value('종목코드', 종목코드)
        self.comm_rq_data('opt40007_req', 'opt40007', '0', '4007')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('종목코드', 종목코드)
            self.comm_rq_data('opt40007_req', 'opt40007', '2', '4007')

    def tr_opt40008(self, 종목코드):
        """
        ETF시간대별체결요청
        """
        self.set_input_value('종목코드', 종목코드)
        self.comm_rq_data('opt40008_req', 'opt40008', '0', '4008')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('종목코드', 종목코드)
            self.comm_rq_data('opt40008_req', 'opt40008', '2', '4008')

    def tr_opt40009(self, 종목코드):
        """
        ETF시간대별체결요청
        """
        self.set_input_value('종목코드', 종목코드)
        self.comm_rq_data('opt40009_req', 'opt40009', '0', '4009')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('종목코드', 종목코드)
            self.comm_rq_data('opt40009_req', 'opt40009', '2', '4009')

    def tr_opt40010(self, 종목코드):
        """
        ETF시간대별추이요청
        """
        self.set_input_value('종목코드', 종목코드)
        self.comm_rq_data('opt40010_req', 'opt40010', '0', '4010')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('종목코드', 종목코드)
            self.comm_rq_data('opt40010_req', 'opt40010', '2', '4010')

    def tr_opt50001(self, 종목코드):
        """
        선옵현재가정보요청
        """
        self.set_input_value('종목코드', 종목코드)
        self.comm_rq_data('opt50001_req', 'opt50001', '0', '5001')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('종목코드', 종목코드)
            self.comm_rq_data('opt50001_req', 'opt50001', '2', '5001')

    def tr_opt50002(self, 종목코드):
        """
        선옵일자별체결요청
        """
        self.set_input_value('종목코드', 종목코드)
        self.comm_rq_data('opt50002_req', 'opt50002', '0', '5002')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('종목코드', 종목코드)
            self.comm_rq_data('opt50002_req', 'opt50002', '2', '5002')

    def tr_opt50003(self, 종목코드):
        """
        선옵시고저가요청
        """
        self.set_input_value('종목코드', 종목코드)
        self.comm_rq_data('opt50003_req', 'opt50003', '0', '5003')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('종목코드', 종목코드)
            self.comm_rq_data('opt50003_req', 'opt50003', '2', '5003')

    def tr_opt50004(self, 만기년월):
        """
        콜옵션행사가요청
        """
        self.set_input_value('만기년월', 만기년월)
        self.comm_rq_data('opt50004_req', 'opt50004', '0', '5004')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('만기년월', 만기년월)
            self.comm_rq_data('opt50004_req', 'opt50004', '2', '5004')

    def tr_opt50005(self, 종목코드):
        """
        선옵시간별거래량요청
        """
        self.set_input_value('종목코드', 종목코드)
        self.comm_rq_data('opt50005_req', 'opt50005', '0', '5005')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('종목코드', 종목코드)
            self.comm_rq_data('opt50005_req', 'opt50005', '2', '5005')

    def tr_opt50006(self, 종목코드):
        """
        선옵체결추이요청
        """
        self.set_input_value('종목코드', 종목코드)
        self.comm_rq_data('opt50006_req', 'opt50006', '0', '5006')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('종목코드', 종목코드)
            self.comm_rq_data('opt50006_req', 'opt50006', '2', '5006')

    def tr_opt50007(self, 종목코드, 시간단위, 시간검색):
        """
        선물시세추이요청
        """
        self.set_input_value('종목코드', 종목코드)
        self.set_input_value('시간단위', 시간단위)
        self.set_input_value('시간검색', 시간검색)
        self.comm_rq_data('opt50007_req', 'opt50007', '0', '5007')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('종목코드', 종목코드)
            self.set_input_value('시간단위', 시간단위)
            self.set_input_value('시간검색', 시간검색)
            self.comm_rq_data('opt50007_req', 'opt50007', '2', '5007')

    def tr_opt50008(self, 종목코드, 시간구분):
        """
        프로그램매매추이차트요청
        """
        self.set_input_value('종목코드', 종목코드)
        self.set_input_value('시간구분', 시간구분)
        self.comm_rq_data('opt50008_req', 'opt50008', '0', '5008')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('종목코드', 종목코드)
            self.set_input_value('시간구분', 시간구분)
            self.comm_rq_data('opt50008_req', 'opt50008', '2', '5008')

    def tr_opt50009(self, 종목코드, 시간검색):
        """
        선옵시간별잔량요청
        """
        self.set_input_value('종목코드', 종목코드)
        self.set_input_value('시간검색', 시간검색)
        self.comm_rq_data('opt50009_req', 'opt50009', '0', '5009')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('종목코드', 종목코드)
            self.set_input_value('시간검색', 시간검색)
            self.comm_rq_data('opt50009_req', 'opt50009', '2', '5009')

    def tr_opt50010(self, 종목코드, 시간검색):
        """
        선옵호가잔량추이요청
        """
        self.set_input_value('종목코드', 종목코드)
        self.set_input_value('시간검색', 시간검색)
        self.comm_rq_data('opt50010_req', 'opt50010', '0', '5010')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('종목코드', 종목코드)
            self.set_input_value('시간검색', 시간검색)
            self.comm_rq_data('opt50010_req', 'opt50010', '2', '5010')

    def tr_opt50011(self, 종목코드, 시간단위, 시간검색):
        """
        선옵호가잔량추이요청
        """
        self.set_input_value('종목코드', 종목코드)
        self.set_input_value('시간단위', 시간단위)
        self.set_input_value('시간검색', 시간검색)
        self.comm_rq_data('opt50011_req', 'opt50011', '0', '5011')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('종목코드', 종목코드)
            self.set_input_value('시간단위', 시간단위)
            self.set_input_value('시간검색', 시간검색)
            self.comm_rq_data('opt50011_req', 'opt50011', '2', '5011')

    def tr_opt50012(self, 종목코드, 시간단위):
        """
        선옵타임스프레드차트요청
        """
        self.set_input_value('종목코드', 종목코드)
        self.set_input_value('시간단위', 시간단위)
        self.comm_rq_data('opt50012_req', 'opt50012', '0', '5012')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('종목코드', 종목코드)
            self.set_input_value('시간단위', 시간단위)
            self.comm_rq_data('opt50012_req', 'opt50012', '2', '5012')

    def tr_opt50013(self, 종목코드, 봉갯수):
        """
        선물가격대별비중차트요청
        """
        self.set_input_value('종목코드', 종목코드)
        self.set_input_value('봉갯수', 봉갯수)
        self.comm_rq_data('opt50013_req', 'opt50013', '0', '5013')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('종목코드', 종목코드)
            self.set_input_value('봉갯수', 봉갯수)
            self.comm_rq_data('opt50013_req', 'opt50013', '2', '5013')

    def tr_opt50014(self, 종목코드, 봉갯수):
        """
        선물가격대별비중차트요청
        """
        self.set_input_value('종목코드', 종목코드)
        self.set_input_value('봉갯수', 봉갯수)
        self.comm_rq_data('opt50014_req', 'opt50014', '0', '5014')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('종목코드', 종목코드)
            self.set_input_value('봉갯수', 봉갯수)
            self.comm_rq_data('opt50014_req', 'opt50014', '2', '5014')

    def tr_opt50015(self, 종목코드, 시간단위):
        """
        선물미결제약정일차트요청
        """
        self.set_input_value('종목코드', 종목코드)
        self.set_input_value('시간단위', 시간단위)
        self.comm_rq_data('opt50015_req', 'opt50015', '0', '5015')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('종목코드', 종목코드)
            self.set_input_value('시간단위', 시간단위)
            self.comm_rq_data('opt50015_req', 'opt50015', '2', '5015')

    def tr_opt50016(self, 종목코드, 시간단위):
        """
        베이시스추이차트요청
        """
        self.set_input_value('종목코드', 종목코드)
        self.set_input_value('시간단위', 시간단위)
        self.comm_rq_data('opt50016_req', 'opt50016', '0', '5016')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('종목코드', 종목코드)
            self.set_input_value('시간단위', 시간단위)
            self.comm_rq_data('opt50016_req', 'opt50016', '2', '5016')

    def tr_opt50017(self, 종목코드, 시간단위):
        """
        베이시스추이차트요청
        """
        self.set_input_value('종목코드', 종목코드)
        self.set_input_value('시간단위', 시간단위)
        self.comm_rq_data('opt50017_req', 'opt50017', '0', '5017')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('종목코드', 종목코드)
            self.set_input_value('시간단위', 시간단위)
            self.comm_rq_data('opt50017_req', 'opt50017', '2', '5017')

    def tr_opt50018(self, 시간단위):
        """
        풋콜옵션비율차트요청
        """
        self.set_input_value('시간단위', 시간단위)
        self.comm_rq_data('opt50018_req', 'opt50018', '0', '5018')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('시간단위', 시간단위)
            self.comm_rq_data('opt50018_req', 'opt50018', '2', '5018')

    def tr_opt50019(self, 종목코드):
        """
        선물옵션현재가정보요청
        """
        self.set_input_value('종목코드', 종목코드)
        self.comm_rq_data('opt50019_req', 'opt50019', '0', '5019')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('종목코드', 종목코드)
            self.comm_rq_data('opt50019_req', 'opt50019', '2', '5019')

    def tr_opt50020(self, 만기년월):
        """
        복수종목결제월별시세요청
        """
        self.set_input_value('만기년월', 만기년월)
        self.comm_rq_data('opt50020_req', 'opt50020', '0', '5020')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('만기년월', 만기년월)
            self.comm_rq_data('opt50020_req', 'opt50020', '2', '5020')

    def tr_opt50021(self, 만기년월):
        """
        콜종목결제월별시세요청
        """
        self.set_input_value('만기년월', 만기년월)
        self.comm_rq_data('opt50021_req', 'opt50021', '0', '5021')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('만기년월', 만기년월)
            self.comm_rq_data('opt50021_req', 'opt50021', '2', '5021')

    def tr_opt50022(self, 만기년월):
        """
        풋종목결제월별시세요청
        """
        self.set_input_value('만기년월', 만기년월)
        self.comm_rq_data('opt50022_req', 'opt50022', '0', '5022')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('만기년월', 만기년월)
            self.comm_rq_data('opt50022_req', 'opt50022', '2', '5022')

    def tr_opt50023(self, 종목코드, 시간구분):
        """
        민감도지표추이요청
        """
        self.set_input_value('종목코드', 종목코드)
        self.set_input_value('시간구분', 시간구분)
        self.comm_rq_data('opt50023_req', 'opt50023', '0', '5023')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('종목코드', 종목코드)
            self.set_input_value('시간구분', 시간구분)
            self.comm_rq_data('opt50023_req', 'opt50023', '2', '5023')

    def tr_opt50024(self, 역사적변동성1, 역사적변동성2, 역사적변동성3, 기간):
        """
        일별변동성분석그래프요청
        """
        self.set_input_value('역사적변동성1', 역사적변동성1)
        self.set_input_value('역사적변동성2', 역사적변동성2)
        self.set_input_value('역사적변동성3', 역사적변동성3)
        self.set_input_value('기간', 기간)
        self.comm_rq_data('opt50024_req', 'opt50024', '0', '5024')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('역사적변동성1', 역사적변동성1)
            self.set_input_value('역사적변동성2', 역사적변동성2)
            self.set_input_value('역사적변동성3', 역사적변동성3)
            self.set_input_value('기간', 기간)
            self.comm_rq_data('opt50024_req', 'opt50024', '2', '5024')

    def tr_opt50025(self, 역사적변동성1, 역사적변동성2, 역사적변동성3, 기간):
        """
        시간별변동성분석그래프요청
        """
        self.set_input_value('역사적변동성1', 역사적변동성1)
        self.set_input_value('역사적변동성2', 역사적변동성2)
        self.set_input_value('역사적변동성3', 역사적변동성3)
        self.set_input_value('기간', 기간)
        self.comm_rq_data('opt50025_req', 'opt50025', '0', '5025')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('역사적변동성1', 역사적변동성1)
            self.set_input_value('역사적변동성2', 역사적변동성2)
            self.set_input_value('역사적변동성3', 역사적변동성3)
            self.set_input_value('기간', 기간)
            self.comm_rq_data('opt50025_req', 'opt50025', '2', '5025')

    def tr_opt50026(self, 종목코드, 조회구분, 매매구분, 체결구분, 계좌번호, 주문번호):
        """
        선옵주문체결요청
        """
        self.set_input_value('종목코드', 종목코드)
        self.set_input_value('조회구분', 조회구분)
        self.set_input_value('매매구분', 매매구분)
        self.set_input_value('체결구분', 체결구분)
        self.set_input_value('계좌번호', 계좌번호)
        self.set_input_value('주문번호', 주문번호)
        self.comm_rq_data('opt50026_req', 'opt50026', '0', '5026')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('종목코드', 종목코드)
            self.set_input_value('조회구분', 조회구분)
            self.set_input_value('매매구분', 매매구분)
            self.set_input_value('체결구분', 체결구분)
            self.set_input_value('계좌번호', 계좌번호)
            self.set_input_value('주문번호', 주문번호)
            self.comm_rq_data('opt50026_req', 'opt50026', '2', '5026')

    def tr_opt50027(self, 계좌번호):
        """
        선옵잔고요청
        """
        self.set_input_value('계좌번호', 계좌번호)
        self.comm_rq_data('opt50027_req', 'opt50027', '0', '5027')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('계좌번호', 계좌번호)
            self.comm_rq_data('opt50027_req', 'opt50027', '2', '5027')

    def tr_opt50028(self, 종목코드, 시간단위):
        """
        선물틱차트요청
        """
        self.set_input_value('종목코드', 종목코드)
        self.set_input_value('시간단위', 시간단위)
        self.comm_rq_data('opt50028_req', 'opt50028', '0', '5028')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('종목코드', 종목코드)
            self.set_input_value('시간단위', 시간단위)
            self.comm_rq_data('opt50028_req', 'opt50028', '2', '5028')

    def tr_opt50029(self, 종목코드, 시간단위):
        """
        선물옵션분차트요청
        """
        self.set_input_value('종목코드', 종목코드)
        self.set_input_value('시간단위', 시간단위)
        self.comm_rq_data('opt50029_req', 'opt50029', '0', '5029')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('종목코드', 종목코드)
            self.set_input_value('시간단위', 시간단위)
            self.comm_rq_data('opt50029_req', 'opt50029', '2', '5029')

    def tr_opt50030(self, 종목코드, 기준일자):
        """
        선물옵션일차트요청
        """
        self.set_input_value('종목코드', 종목코드)
        self.set_input_value('기준일자', 기준일자)
        self.comm_rq_data('opt50030_req', 'opt50030', '0', '5030')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('종목코드', 종목코드)
            self.set_input_value('기준일자', 기준일자)
            self.comm_rq_data('opt50030_req', 'opt50030', '2', '5030')

    def tr_opt50031(self, 계좌번호):
        """
        선옵잔고손익요청
        """
        self.set_input_value('계좌번호', 계좌번호)
        self.comm_rq_data('opt50031_req', 'opt50031', '0', '5031')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('계좌번호', 계좌번호)
            self.comm_rq_data('opt50031_req', 'opt50031', '2', '5031')

    def tr_opt50032(self, 계좌번호, 종목코드):
        """
        선옵당일실현손익요청
        """
        self.set_input_value('계좌번호', 계좌번호)
        self.set_input_value('종목코드', 종목코드)
        self.comm_rq_data('opt50032_req', 'opt50032', '0', '5032')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('계좌번호', 계좌번호)
            self.set_input_value('종목코드', 종목코드)
            self.comm_rq_data('opt50032_req', 'opt50032', '2', '5032')

    def tr_opt50033(self, 종목코드, 기준일자):
        """
        선옵잔존일조회요청
        """
        self.set_input_value('종목코드', 종목코드)
        self.set_input_value('기준일자', 기준일자)
        self.comm_rq_data('opt50033_req', 'opt50033', '0', '5033')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('종목코드', 종목코드)
            self.set_input_value('기준일자', 기준일자)
            self.comm_rq_data('opt50033_req', 'opt50033', '2', '5033')

    def tr_opt50034(self, 종목코드, 기간):
        """
        선옵전일가격요청
        """
        self.set_input_value('종목코드', 종목코드)
        self.set_input_value('기간', 기간)
        self.comm_rq_data('opt50034_req', 'opt50034', '0', '5034')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('종목코드', 종목코드)
            self.set_input_value('기간', 기간)
            self.comm_rq_data('opt50034_req', 'opt50034', '2', '5034')

    def tr_opt50035(self, 종목코드, 기준일자, 기간, 차트구분):
        """
        지수변동성차트요청
        """
        self.set_input_value('종목코드', 종목코드)
        self.set_input_value('기준일자', 기준일자)
        self.set_input_value('기간', 기간)
        self.set_input_value('차트구분', 차트구분)
        self.comm_rq_data('opt50035_req', 'opt50035', '0', '5035')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('종목코드', 종목코드)
            self.set_input_value('기준일자', 기준일자)
            self.set_input_value('기간', 기간)
            self.set_input_value('차트구분', 차트구분)
            self.comm_rq_data('opt50035_req', 'opt50035', '2', '5035')

    def tr_opt50036(self, 종목코드, 기준일자, 기간, 차트구분):
        """
        주요지수변동성차트요청
        """
        self.set_input_value('종목코드', 종목코드)
        self.set_input_value('기준일자', 기준일자)
        self.set_input_value('기간', 기간)
        self.set_input_value('차트구분', 차트구분)
        self.comm_rq_data('opt50036_req', 'opt50036', '0', '5036')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('종목코드', 종목코드)
            self.set_input_value('기준일자', 기준일자)
            self.set_input_value('기간', 기간)
            self.set_input_value('차트구분', 차트구분)
            self.comm_rq_data('opt50036_req', 'opt50036', '2', '5036')

    def tr_opt50037(self, 종목코드, 기준일자):
        """
        코스피200지수요청
        """
        self.set_input_value('종목코드', 종목코드)
        self.set_input_value('기준일자', 기준일자)
        self.comm_rq_data('opt50037_req', 'opt50037', '0', '5037')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('종목코드', 종목코드)
            self.set_input_value('기준일자', 기준일자)
            self.comm_rq_data('opt50037_req', 'opt50037', '2', '5037')

    def tr_opt50038(self, 일자구분, 일자, 투자자구분, 수량금액구분):
        """
        투자자별만기손익차트요청
        """
        self.set_input_value('일자구분', 일자구분)
        self.set_input_value('일자', 일자)
        self.set_input_value('투자자구분', 투자자구분)
        self.set_input_value('수량금액구분', 수량금액구분)
        self.comm_rq_data('opt50038_req', 'opt50038', '0', '5038')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('일자구분', 일자구분)
            self.set_input_value('일자', 일자)
            self.set_input_value('투자자구분', 투자자구분)
            self.set_input_value('수량금액구분', 수량금액구분)
            self.comm_rq_data('opt50038_req', 'opt50038', '2', '5038')

    def tr_opt50039(self, 일자구분, 일자, 수량금액구분, 단위구분):
        """
        투자자별포지션종합요청
        """
        self.set_input_value('일자구분', 일자구분)
        self.set_input_value('일자', 일자)
        self.set_input_value('수량금액구분', 수량금액구분)
        self.set_input_value('단위구분', 단위구분)
        self.comm_rq_data('opt50039_req', 'opt50039', '0', '5039')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('일자구분', 일자구분)
            self.set_input_value('일자', 일자)
            self.set_input_value('수량금액구분', 수량금액구분)
            self.set_input_value('단위구분', 단위구분)
            self.comm_rq_data('opt50039_req', 'opt50039', '2', '5039')

    def tr_opt50040(self, 종목코드):
        """
        선옵시고저가요청
        """
        self.set_input_value('종목코드', 종목코드)
        self.comm_rq_data('opt50040_req', 'opt50040', '0', '5040')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('종목코드', 종목코드)
            self.comm_rq_data('opt50040_req', 'opt50040', '2', '5040')

    def tr_opt50043(self, ):
        """
        주식선물거래량상위종목요청
        """
        self.set_input_value('', )
        self.comm_rq_data('opt50043_req', 'opt50043', '0', '5043')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('', )
            self.comm_rq_data('opt50043_req', 'opt50043', '2', '5043')

    def tr_opt50044(self, 근월물구분):
        """
        주식선물시세표요청
        """
        self.set_input_value('근월물구분', 근월물구분)
        self.comm_rq_data('opt50044_req', 'opt50044', '0', '5044')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('근월물구분', 근월물구분)
            self.comm_rq_data('opt50044_req', 'opt50044', '2', '5044')

    def tr_opt50062(self, 종목코드, 시간단위):
        """
        선물미결제약정분차트요청
        """
        self.set_input_value('종목코드', 종목코드)
        self.set_input_value('시간단위', 시간단위)
        self.comm_rq_data('opt50062_req', 'opt50062', '0', '5062')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('종목코드', 종목코드)
            self.set_input_value('시간단위', 시간단위)
            self.comm_rq_data('opt50062_req', 'opt50062', '2', '5062')

    def tr_opt50063(self, 종목코드, 시간단위):
        """
        옵션미결제약정일차트요청
        """
        self.set_input_value('종목코드', 종목코드)
        self.set_input_value('시간단위', 시간단위)
        self.comm_rq_data('opt50063_req', 'opt50063', '0', '5063')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('종목코드', 종목코드)
            self.set_input_value('시간단위', 시간단위)
            self.comm_rq_data('opt50063_req', 'opt50063', '2', '5063')

    def tr_opt50064(self, 종목코드, 시간단위):
        """
        옵션미결제약정분차트요청
        """
        self.set_input_value('종목코드', 종목코드)
        self.set_input_value('시간단위', 시간단위)
        self.comm_rq_data('opt50064_req', 'opt50064', '0', '5064')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('종목코드', 종목코드)
            self.set_input_value('시간단위', 시간단위)
            self.comm_rq_data('opt50064_req', 'opt50064', '2', '5064')

    def tr_opt50065(self, 만기년월):
        """
        풋옵션행사가요청
        """
        self.set_input_value('만기년월', 만기년월)
        self.comm_rq_data('opt50065_req', 'opt50065', '0', '5065')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('만기년월', 만기년월)
            self.comm_rq_data('opt50065_req', 'opt50065', '2', '5065')

    def tr_opt50066(self, 종목코드, 시간단위):
        """
        옵션틱차트요청
        """
        self.set_input_value('종목코드', 종목코드)
        self.set_input_value('시간단위', 시간단위)
        self.comm_rq_data('opt50066_req', 'opt50066', '0', '5066')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('종목코드', 종목코드)
            self.set_input_value('시간단위', 시간단위)
            self.comm_rq_data('opt50066_req', 'opt50066', '2', '5066')

    def tr_opt50067(self, 종목코드, 시간단위):
        """
        옵션분차트요청
        """
        self.set_input_value('종목코드', 종목코드)
        self.set_input_value('시간단위', 시간단위)
        self.comm_rq_data('opt50067_req', 'opt50067', '0', '5067')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('종목코드', 종목코드)
            self.set_input_value('시간단위', 시간단위)
            self.comm_rq_data('opt50067_req', 'opt50067', '2', '5067')

    def tr_opt50068(self, 종목코드, 기준일자):
        """
        옵션일차트요청
        """
        self.set_input_value('종목코드', 종목코드)
        self.set_input_value('기준일자', 기준일자)
        self.comm_rq_data('opt50068_req', 'opt50068', '0', '5068')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('종목코드', 종목코드)
            self.set_input_value('기준일자', 기준일자)
            self.comm_rq_data('opt50068_req', 'opt50068', '2', '5068')

    def tr_opt50071(self, 종목코드, 기준일자):
        """
        선물주차트요청
        """
        self.set_input_value('종목코드', 종목코드)
        self.set_input_value('기준일자', 기준일자)
        self.comm_rq_data('opt50071_req', 'opt50071', '0', '5071')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('종목코드', 종목코드)
            self.set_input_value('기준일자', 기준일자)
            self.comm_rq_data('opt50071_req', 'opt50071', '2', '5071')

    def tr_opt50072(self, 종목코드, 기준일자):
        """
        선물월차트요청
        """
        self.set_input_value('종목코드', 종목코드)
        self.set_input_value('기준일자', 기준일자)
        self.comm_rq_data('opt50072_req', 'opt50072', '0', '5072')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('종목코드', 종목코드)
            self.set_input_value('기준일자', 기준일자)
            self.comm_rq_data('opt50072_req', 'opt50072', '2', '5072')

    def tr_opt50073(self, 종목코드, 기준일자):
        """
        선물년차트요청
        """
        self.set_input_value('종목코드', 종목코드)
        self.set_input_value('기준일자', 기준일자)
        self.comm_rq_data('opt50073_req', 'opt50073', '0', '5073')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('종목코드', 종목코드)
            self.set_input_value('기준일자', 기준일자)
            self.comm_rq_data('opt50073_req', 'opt50073', '2', '5073')

    def tr_opt90001(self, 검색구분, 종목코드, 날짜구분, 테마명, 등락수익구분):
        """
        테마그룹별요청
        """
        self.set_input_value('검색구분', 검색구분)
        self.set_input_value('종목코드', 종목코드)
        self.set_input_value('날짜구분', 날짜구분)
        self.set_input_value('테마명', 테마명)
        self.set_input_value('등락수익구분', 등락수익구분)
        self.comm_rq_data('opt90001_req', 'opt90001', '0', '9001')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('검색구분', 검색구분)
            self.set_input_value('종목코드', 종목코드)
            self.set_input_value('날짜구분', 날짜구분)
            self.set_input_value('테마명', 테마명)
            self.set_input_value('등락수익구분', 등락수익구분)
            self.comm_rq_data('opt90001_req', 'opt90001', '2', '9001')

    def tr_opt90002(self, 날짜구분, 종목코드):
        """
        테마구성종목요청
        """
        self.set_input_value('날짜구분', 날짜구분)
        self.set_input_value('종목코드', 종목코드)
        self.comm_rq_data('opt90002_req', 'opt90002', '0', '9002')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('날짜구분', 날짜구분)
            self.set_input_value('종목코드', 종목코드)
            self.comm_rq_data('opt90002_req', 'opt90002', '2', '9002')

    def tr_opt90003(self, 매매상위구분, 금액수량구분, 시장구분):
        """
        프로그램순매수상위50요청
        """
        self.set_input_value('매매상위구분', 매매상위구분)
        self.set_input_value('금액수량구분', 금액수량구분)
        self.set_input_value('시장구분', 시장구분)
        self.comm_rq_data('opt90003_req', 'opt90003', '0', '9003')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('매매상위구분', 매매상위구분)
            self.set_input_value('금액수량구분', 금액수량구분)
            self.set_input_value('시장구분', 시장구분)
            self.comm_rq_data('opt90003_req', 'opt90003', '2', '9003')

    def tr_opt90004(self, 일자, 시장구분):
        """
        종목별프로그램매매현황요청
        """
        self.set_input_value('일자', 일자)
        self.set_input_value('시장구분', 시장구분)
        self.comm_rq_data('opt90004_req', 'opt90004', '0', '9004')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('일자', 일자)
            self.set_input_value('시장구분', 시장구분)
            self.comm_rq_data('opt90004_req', 'opt90004', '2', '9004')

    def tr_opt90005(self, 날짜, 시간구분, 금액수량구분, 시장구분, 분틱구분):
        """
        프로그램매매추이요청
        """
        self.set_input_value('날짜', 날짜)
        self.set_input_value('시간구분', 시간구분)
        self.set_input_value('금액수량구분', 금액수량구분)
        self.set_input_value('시장구분', 시장구분)
        self.set_input_value('분틱구분', 분틱구분)
        self.comm_rq_data('opt90005_req', 'opt90005', '0', '9005')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('날짜', 날짜)
            self.set_input_value('시간구분', 시간구분)
            self.set_input_value('금액수량구분', 금액수량구분)
            self.set_input_value('시장구분', 시장구분)
            self.set_input_value('분틱구분', 분틱구분)
            self.comm_rq_data('opt90005_req', 'opt90005', '2', '9005')

    def tr_opt90006(self, 날짜):
        """
        프로그램매매차익잔고추이요청
        """
        self.set_input_value('날짜', 날짜)
        self.comm_rq_data('opt90006_req', 'opt90006', '0', '9006')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('날짜', 날짜)
            self.comm_rq_data('opt90006_req', 'opt90006', '2', '9006')

    def tr_opt90007(self, 날짜, 금액수량구분, 시장구분):
        """
        프로그램매매누적추이요청
        """
        self.set_input_value('날짜', 날짜)
        self.set_input_value('금액수량구분', 금액수량구분)
        self.set_input_value('시장구분', 시장구분)
        self.comm_rq_data('opt90007_req', 'opt90007', '0', '9007')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('날짜', 날짜)
            self.set_input_value('금액수량구분', 금액수량구분)
            self.set_input_value('시장구분', 시장구분)
            self.comm_rq_data('opt90007_req', 'opt90007', '2', '9007')

    def tr_opt90008(self, 시간일자구분, 금액수량구분, 종목코드, 날짜):
        """
        종목시간별프로그램매매추이요청
        """
        self.set_input_value('시간일자구분', 시간일자구분)
        self.set_input_value('금액수량구분', 금액수량구분)
        self.set_input_value('종목코드', 종목코드)
        self.set_input_value('날짜', 날짜)
        self.comm_rq_data('opt90008_req', 'opt90008', '0', '9008')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('시간일자구분', 시간일자구분)
            self.set_input_value('금액수량구분', 금액수량구분)
            self.set_input_value('종목코드', 종목코드)
            self.set_input_value('날짜', 날짜)
            self.comm_rq_data('opt90008_req', 'opt90008', '2', '9008')

    def tr_opt90009(self, 시장구분, 금액수량구분, 조회일자구분, 날짜):
        """
        외국인기관매매상위요청
        """
        self.set_input_value('시장구분', 시장구분)
        self.set_input_value('금액수량구분', 금액수량구분)
        self.set_input_value('조회일자구분', 조회일자구분)
        self.set_input_value('날짜', 날짜)
        self.comm_rq_data('opt90009_req', 'opt90009', '0', '9009')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('시장구분', 시장구분)
            self.set_input_value('금액수량구분', 금액수량구분)
            self.set_input_value('조회일자구분', 조회일자구분)
            self.set_input_value('날짜', 날짜)
            self.comm_rq_data('opt90009_req', 'opt90009', '2', '9009')

    def tr_opt90010(self, 일자, 금액수량구분):
        """
        차익잔고현황요청
        """
        self.set_input_value('일자', 일자)
        self.set_input_value('금액수량구분', 금액수량구분)
        self.comm_rq_data('opt90010_req', 'opt90010', '0', '9010')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('일자', 일자)
            self.set_input_value('금액수량구분', 금액수량구분)
            self.comm_rq_data('opt90010_req', 'opt90010', '2', '9010')

    def tr_opt90011(self, 일자, 금액수량구분):
        """
        차익잔고현황요청
        """
        self.set_input_value('일자', 일자)
        self.set_input_value('금액수량구분', 금액수량구분)
        self.comm_rq_data('opt90011_req', 'opt90011', '0', '9011')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('일자', 일자)
            self.set_input_value('금액수량구분', 금액수량구분)
            self.comm_rq_data('opt90011_req', 'opt90011', '2', '9011')

    def tr_opt90012(self, 일자, 시장구분):
        """
        대차거래내역요청
        """
        self.set_input_value('일자', 일자)
        self.set_input_value('시장구분', 시장구분)
        self.comm_rq_data('opt90012_req', 'opt90012', '0', '9012')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('일자', 일자)
            self.set_input_value('시장구분', 시장구분)
            self.comm_rq_data('opt90012_req', 'opt90012', '2', '9012')

    def tr_opt90013(self, 시간일자구분, 금액수량구분, 종목코드, 날짜):
        """
        종목일별프로그램매매추이요청
        """
        self.set_input_value('시간일자구분', 시간일자구분)
        self.set_input_value('금액수량구분', 금액수량구분)
        self.set_input_value('종목코드', 종목코드)
        self.set_input_value('날짜', 날짜)
        self.comm_rq_data('opt90013_req', 'opt90013', '0', '9013')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('시간일자구분', 시간일자구분)
            self.set_input_value('금액수량구분', 금액수량구분)
            self.set_input_value('종목코드', 종목코드)
            self.set_input_value('날짜', 날짜)
            self.comm_rq_data('opt90013_req', 'opt90013', '2', '9013')

    def tr_opt99999(self, 시작일자, 종료일자, 시장구분):
        """
        대차거래상위10종목요청
        """
        self.set_input_value('시작일자', 시작일자)
        self.set_input_value('종료일자', 종료일자)
        self.set_input_value('시장구분', 시장구분)
        self.comm_rq_data('opt99999_req', 'opt99999', '0', '9999')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('시작일자', 시작일자)
            self.set_input_value('종료일자', 종료일자)
            self.set_input_value('시장구분', 시장구분)
            self.comm_rq_data('opt99999_req', 'opt99999', '2', '9999')

    def tr_optfofid(self, 종목코드):
        """
        선물전체시세요청
        """
        self.set_input_value('종목코드', 종목코드)
        self.comm_rq_data('optfofid_req', 'optfofid', '0', 'foid')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('종목코드', 종목코드)
            self.comm_rq_data('optfofid_req', 'optfofid', '2', 'foid')

    def tr_optkwfid(self, 종목코드):
        """
        관심종목정보요청
        """
        self.set_input_value('종목코드', 종목코드)
        self.comm_rq_data('optkwfid_req', 'optkwfid', '0', 'kwid')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('종목코드', 종목코드)
            self.comm_rq_data('optkwfid_req', 'optkwfid', '2', 'kwid')

    def tr_optkwinv(self, 종목코드):
        """
        관심종목투자자정보요청
        """
        self.set_input_value('종목코드', 종목코드)
        self.comm_rq_data('optkwinv_req', 'optkwinv', '0', 'kwnv')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('종목코드', 종목코드)
            self.comm_rq_data('optkwinv_req', 'optkwinv', '2', 'kwnv')

    def tr_optkwpro(self, 종목코드):
        """
        관심종목프로그램정보요청
        """
        self.set_input_value('종목코드', 종목코드)
        self.comm_rq_data('optkwpro_req', 'optkwpro', '0', 'kwro')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('종목코드', 종목코드)
            self.comm_rq_data('optkwpro_req', 'optkwpro', '2', 'kwro')

    def tr_opw00001(self, 계좌번호, 비밀번호, 비밀번호입력매체구분, 조회구분):
        """
        예수금상세현황요청
        """
        self.set_input_value('계좌번호', 계좌번호)
        self.set_input_value('비밀번호', 비밀번호)
        self.set_input_value('비밀번호입력매체구분', 비밀번호입력매체구분)
        self.set_input_value('조회구분', 조회구분)
        self.comm_rq_data('opw00001_req', 'opw00001', '0', '0001')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('계좌번호', 계좌번호)
            self.set_input_value('비밀번호', 비밀번호)
            self.set_input_value('비밀번호입력매체구분', 비밀번호입력매체구분)
            self.set_input_value('조회구분', 조회구분)
            self.comm_rq_data('opw00001_req', 'opw00001', '2', '0001')

    def tr_opw00002(self, 계좌번호, 비밀번호, 시작조회기간, 종료조회기간):
        """
        일별추정예탁자산현황요청
        """
        self.set_input_value('계좌번호', 계좌번호)
        self.set_input_value('비밀번호', 비밀번호)
        self.set_input_value('시작조회기간', 시작조회기간)
        self.set_input_value('종료조회기간', 종료조회기간)
        self.comm_rq_data('opw00002_req', 'opw00002', '0', '0002')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('계좌번호', 계좌번호)
            self.set_input_value('비밀번호', 비밀번호)
            self.set_input_value('시작조회기간', 시작조회기간)
            self.set_input_value('종료조회기간', 종료조회기간)
            self.comm_rq_data('opw00002_req', 'opw00002', '2', '0002')

    def tr_opw00003(self, 계좌번호, 비밀번호, 상장폐지조회구분):
        """
        추정자산조회요청
        """
        self.set_input_value('계좌번호', 계좌번호)
        self.set_input_value('비밀번호', 비밀번호)
        self.set_input_value('상장폐지조회구분', 상장폐지조회구분)
        self.comm_rq_data('opw00003_req', 'opw00003', '0', '0003')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('계좌번호', 계좌번호)
            self.set_input_value('비밀번호', 비밀번호)
            self.set_input_value('상장폐지조회구분', 상장폐지조회구분)
            self.comm_rq_data('opw00003_req', 'opw00003', '2', '0003')

    def tr_opw00004(self, 계좌번호, 비밀번호, 상장폐지조회구분, 비밀번호입력매체구분):
        """
        계좌평가현황요청
        """
        self.set_input_value('계좌번호', 계좌번호)
        self.set_input_value('비밀번호', 비밀번호)
        self.set_input_value('상장폐지조회구분', 상장폐지조회구분)
        self.set_input_value('비밀번호입력매체구분', 비밀번호입력매체구분)
        self.comm_rq_data('opw00004_req', 'opw00004', '0', '0004')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('계좌번호', 계좌번호)
            self.set_input_value('비밀번호', 비밀번호)
            self.set_input_value('상장폐지조회구분', 상장폐지조회구분)
            self.set_input_value('비밀번호입력매체구분', 비밀번호입력매체구분)
            self.comm_rq_data('opw00004_req', 'opw00004', '2', '0004')

    def tr_opw00005(self, 계좌번호, 비밀번호, 비밀번호입력매체구분):
        """
        체결잔고요청
        """
        self.set_input_value('계좌번호', 계좌번호)
        self.set_input_value('비밀번호', 비밀번호)
        self.set_input_value('비밀번호입력매체구분', 비밀번호입력매체구분)
        self.comm_rq_data('opw00005_req', 'opw00005', '0', '0005')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('계좌번호', 계좌번호)
            self.set_input_value('비밀번호', 비밀번호)
            self.set_input_value('비밀번호입력매체구분', 비밀번호입력매체구분)
            self.comm_rq_data('opw00005_req', 'opw00005', '2', '0005')

    def tr_opw00006(self, 일자, 지점코드, 시작주문번호):
        """
        관리자별주문체결내역요청
        """
        self.set_input_value('일자', 일자)
        self.set_input_value('지점코드', 지점코드)
        self.set_input_value('시작주문번호', 시작주문번호)
        self.comm_rq_data('opw00006_req', 'opw00006', '0', '0006')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('일자', 일자)
            self.set_input_value('지점코드', 지점코드)
            self.set_input_value('시작주문번호', 시작주문번호)
            self.comm_rq_data('opw00006_req', 'opw00006', '2', '0006')

    def tr_opw00007(self, 주문일자, 계좌번호, 비밀번호, 비밀번호입력매체구분, 조회구분, 주식채권구분, 매도수구분, 종목코드, 시작주문번호):
        """
        계좌별주문체결내역상세요청
        """
        self.set_input_value('주문일자', 주문일자)
        self.set_input_value('계좌번호', 계좌번호)
        self.set_input_value('비밀번호', 비밀번호)
        self.set_input_value('비밀번호입력매체구분', 비밀번호입력매체구분)
        self.set_input_value('조회구분', 조회구분)
        self.set_input_value('주식채권구분', 주식채권구분)
        self.set_input_value('매도수구분', 매도수구분)
        self.set_input_value('종목코드', 종목코드)
        self.set_input_value('시작주문번호', 시작주문번호)
        self.comm_rq_data('opw00007_req', 'opw00007', '0', '0007')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('주문일자', 주문일자)
            self.set_input_value('계좌번호', 계좌번호)
            self.set_input_value('비밀번호', 비밀번호)
            self.set_input_value('비밀번호입력매체구분', 비밀번호입력매체구분)
            self.set_input_value('조회구분', 조회구분)
            self.set_input_value('주식채권구분', 주식채권구분)
            self.set_input_value('매도수구분', 매도수구분)
            self.set_input_value('종목코드', 종목코드)
            self.set_input_value('시작주문번호', 시작주문번호)
            self.comm_rq_data('opw00007_req', 'opw00007', '2', '0007')

    def tr_opw00008(self, 계좌번호, 비밀번호, 비밀번호입력매체구분, 시작결제번호):
        """
        계좌별익일결제예정내역요청
        """
        self.set_input_value('계좌번호', 계좌번호)
        self.set_input_value('비밀번호', 비밀번호)
        self.set_input_value('비밀번호입력매체구분', 비밀번호입력매체구분)
        self.set_input_value('시작결제번호', 시작결제번호)
        self.comm_rq_data('opw00008_req', 'opw00008', '0', '0008')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('계좌번호', 계좌번호)
            self.set_input_value('비밀번호', 비밀번호)
            self.set_input_value('비밀번호입력매체구분', 비밀번호입력매체구분)
            self.set_input_value('시작결제번호', 시작결제번호)
            self.comm_rq_data('opw00008_req', 'opw00008', '2', '0008')

    def tr_opw00009(self, 주문일자, 계좌번호, 비밀번호, 비밀번호입력매체구분, 주식채권구분, 시장구분, 매도수구분, 조회구분, 종목코드, 시작주문번호):
        """
        계좌별주문체결현황요청
        """
        self.set_input_value('주문일자', 주문일자)
        self.set_input_value('계좌번호', 계좌번호)
        self.set_input_value('비밀번호', 비밀번호)
        self.set_input_value('비밀번호입력매체구분', 비밀번호입력매체구분)
        self.set_input_value('주식채권구분', 주식채권구분)
        self.set_input_value('시장구분', 시장구분)
        self.set_input_value('매도수구분', 매도수구분)
        self.set_input_value('조회구분', 조회구분)
        self.set_input_value('종목코드', 종목코드)
        self.set_input_value('시작주문번호', 시작주문번호)
        self.comm_rq_data('opw00009_req', 'opw00009', '0', '0009')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('주문일자', 주문일자)
            self.set_input_value('계좌번호', 계좌번호)
            self.set_input_value('비밀번호', 비밀번호)
            self.set_input_value('비밀번호입력매체구분', 비밀번호입력매체구분)
            self.set_input_value('주식채권구분', 주식채권구분)
            self.set_input_value('시장구분', 시장구분)
            self.set_input_value('매도수구분', 매도수구분)
            self.set_input_value('조회구분', 조회구분)
            self.set_input_value('종목코드', 종목코드)
            self.set_input_value('시작주문번호', 시작주문번호)
            self.comm_rq_data('opw00009_req', 'opw00009', '2', '0009')

    def tr_opw00010(self, 계좌번호, 비밀번호, 비밀번호입력매체구분, 입출금액, 종목번호, 매매구분, 매매수량, 매수가격, 예상매수단가):
        """
        주문인출가능금액요청
        """
        self.set_input_value('계좌번호', 계좌번호)
        self.set_input_value('비밀번호', 비밀번호)
        self.set_input_value('비밀번호입력매체구분', 비밀번호입력매체구분)
        self.set_input_value('입출금액', 입출금액)
        self.set_input_value('종목번호', 종목번호)
        self.set_input_value('매매구분', 매매구분)
        self.set_input_value('매매수량', 매매수량)
        self.set_input_value('매수가격', 매수가격)
        self.set_input_value('예상매수단가', 예상매수단가)
        self.comm_rq_data('opw00010_req', 'opw00010', '0', '0010')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('계좌번호', 계좌번호)
            self.set_input_value('비밀번호', 비밀번호)
            self.set_input_value('비밀번호입력매체구분', 비밀번호입력매체구분)
            self.set_input_value('입출금액', 입출금액)
            self.set_input_value('종목번호', 종목번호)
            self.set_input_value('매매구분', 매매구분)
            self.set_input_value('매매수량', 매매수량)
            self.set_input_value('매수가격', 매수가격)
            self.set_input_value('예상매수단가', 예상매수단가)
            self.comm_rq_data('opw00010_req', 'opw00010', '2', '0010')

    def tr_opw00011(self, 계좌번호, 비밀번호, 비밀번호입력매체구분, 종목번호, 매수가격):
        """
        증거금율별주문가능수량조회요청
        """
        self.set_input_value('계좌번호', 계좌번호)
        self.set_input_value('비밀번호', 비밀번호)
        self.set_input_value('비밀번호입력매체구분', 비밀번호입력매체구분)
        self.set_input_value('종목번호', 종목번호)
        self.set_input_value('매수가격', 매수가격)
        self.comm_rq_data('opw00011_req', 'opw00011', '0', '0011')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('계좌번호', 계좌번호)
            self.set_input_value('비밀번호', 비밀번호)
            self.set_input_value('비밀번호입력매체구분', 비밀번호입력매체구분)
            self.set_input_value('종목번호', 종목번호)
            self.set_input_value('매수가격', 매수가격)
            self.comm_rq_data('opw00011_req', 'opw00011', '2', '0011')

    def tr_opw00012(self, 계좌번호, 비밀번호, 비밀번호입력매체구분, 종목번호, 매수가격):
        """
        신용보증금율별주문가능수량조회요청
        """
        self.set_input_value('계좌번호', 계좌번호)
        self.set_input_value('비밀번호', 비밀번호)
        self.set_input_value('비밀번호입력매체구분', 비밀번호입력매체구분)
        self.set_input_value('종목번호', 종목번호)
        self.set_input_value('매수가격', 매수가격)
        self.comm_rq_data('opw00012_req', 'opw00012', '0', '0012')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('계좌번호', 계좌번호)
            self.set_input_value('비밀번호', 비밀번호)
            self.set_input_value('비밀번호입력매체구분', 비밀번호입력매체구분)
            self.set_input_value('종목번호', 종목번호)
            self.set_input_value('매수가격', 매수가격)
            self.comm_rq_data('opw00012_req', 'opw00012', '2', '0012')

    def tr_opw00013(self, 계좌번호, 비밀번호):
        """
        증거금세부내역조회요청
        """
        self.set_input_value('계좌번호', 계좌번호)
        self.set_input_value('비밀번호', 비밀번호)
        self.comm_rq_data('opw00013_req', 'opw00013', '0', '0013')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('계좌번호', 계좌번호)
            self.set_input_value('비밀번호', 비밀번호)
            self.comm_rq_data('opw00013_req', 'opw00013', '2', '0013')

    def tr_opw00014(self, 계좌번호, 비밀번호, 비밀번호입력매체구분):
        """
        비밀번호일치여부요청
        """
        self.set_input_value('계좌번호', 계좌번호)
        self.set_input_value('비밀번호', 비밀번호)
        self.set_input_value('비밀번호입력매체구분', 비밀번호입력매체구분)
        self.comm_rq_data('opw00014_req', 'opw00014', '0', '0014')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('계좌번호', 계좌번호)
            self.set_input_value('비밀번호', 비밀번호)
            self.set_input_value('비밀번호입력매체구분', 비밀번호입력매체구분)
            self.comm_rq_data('opw00014_req', 'opw00014', '2', '0014')

    def tr_opw00015(self, 계좌번호, 비밀번호, 시작일자, 종료일자, 구분, 종목코드, 통화코드, 상품구분, 비밀번호입력매체구분, 고객정보제한여부):
        """
        위탁종합거래내역요청
        """
        self.set_input_value('계좌번호', 계좌번호)
        self.set_input_value('비밀번호', 비밀번호)
        self.set_input_value('시작일자', 시작일자)
        self.set_input_value('종료일자', 종료일자)
        self.set_input_value('구분', 구분)
        self.set_input_value('종목코드', 종목코드)
        self.set_input_value('통화코드', 통화코드)
        self.set_input_value('상품구분', 상품구분)
        self.set_input_value('비밀번호입력매체구분', 비밀번호입력매체구분)
        self.set_input_value('고객정보제한여부', 고객정보제한여부)
        self.comm_rq_data('opw00015_req', 'opw00015', '0', '0015')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('계좌번호', 계좌번호)
            self.set_input_value('비밀번호', 비밀번호)
            self.set_input_value('시작일자', 시작일자)
            self.set_input_value('종료일자', 종료일자)
            self.set_input_value('구분', 구분)
            self.set_input_value('종목코드', 종목코드)
            self.set_input_value('통화코드', 통화코드)
            self.set_input_value('상품구분', 상품구분)
            self.set_input_value('비밀번호입력매체구분', 비밀번호입력매체구분)
            self.set_input_value('고객정보제한여부', 고객정보제한여부)
            self.comm_rq_data('opw00015_req', 'opw00015', '2', '0015')

    def tr_opw00016(self, 계좌번호, 비밀번호, 평가시작일, 평가종료일, 비밀번호입력매체구분):
        """
        일별계좌수익률상세현황요청
        """
        self.set_input_value('계좌번호', 계좌번호)
        self.set_input_value('비밀번호', 비밀번호)
        self.set_input_value('평가시작일', 평가시작일)
        self.set_input_value('평가종료일', 평가종료일)
        self.set_input_value('비밀번호입력매체구분', 비밀번호입력매체구분)
        self.comm_rq_data('opw00016_req', 'opw00016', '0', '0016')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('계좌번호', 계좌번호)
            self.set_input_value('비밀번호', 비밀번호)
            self.set_input_value('평가시작일', 평가시작일)
            self.set_input_value('평가종료일', 평가종료일)
            self.set_input_value('비밀번호입력매체구분', 비밀번호입력매체구분)
            self.comm_rq_data('opw00016_req', 'opw00016', '2', '0016')

    def tr_opw00017(self, 계좌번호, 비밀번호, 비밀번호입력매체구분):
        """
        계좌별당일현황요청
        """
        self.set_input_value('계좌번호', 계좌번호)
        self.set_input_value('비밀번호', 비밀번호)
        self.set_input_value('비밀번호입력매체구분', 비밀번호입력매체구분)
        self.comm_rq_data('opw00017_req', 'opw00017', '0', '0017')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('계좌번호', 계좌번호)
            self.set_input_value('비밀번호', 비밀번호)
            self.set_input_value('비밀번호입력매체구분', 비밀번호입력매체구분)
            self.comm_rq_data('opw00017_req', 'opw00017', '2', '0017')

    def tr_opw00018(self, 계좌번호, 비밀번호, 비밀번호입력매체구분, 조회구분):
        """
        계좌평가잔고내역요청
        """
        self.set_input_value('계좌번호', 계좌번호)
        self.set_input_value('비밀번호', 비밀번호)
        self.set_input_value('비밀번호입력매체구분', 비밀번호입력매체구분)
        self.set_input_value('조회구분', 조회구분)
        self.comm_rq_data('opw00018_req', 'opw00018', '0', '0018')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('계좌번호', 계좌번호)
            self.set_input_value('비밀번호', 비밀번호)
            self.set_input_value('비밀번호입력매체구분', 비밀번호입력매체구분)
            self.set_input_value('조회구분', 조회구분)
            self.comm_rq_data('opw00018_req', 'opw00018', '2', '0018')

    def tr_opw20001(self, 계좌번호, 비밀번호, 입력건수, 종목코드, 매수매도구분, 주문수량, 잔고수량):
        """
        선물옵션청산주문위탁증거금가계산요청
        """
        self.set_input_value('계좌번호', 계좌번호)
        self.set_input_value('비밀번호', 비밀번호)
        self.set_input_value('입력건수', 입력건수)
        self.set_input_value('종목코드', 종목코드)
        self.set_input_value('매수매도구분', 매수매도구분)
        self.set_input_value('주문수량', 주문수량)
        self.set_input_value('잔고수량', 잔고수량)
        self.comm_rq_data('opw20001_req', 'opw20001', '0', '2001')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('계좌번호', 계좌번호)
            self.set_input_value('비밀번호', 비밀번호)
            self.set_input_value('입력건수', 입력건수)
            self.set_input_value('종목코드', 종목코드)
            self.set_input_value('매수매도구분', 매수매도구분)
            self.set_input_value('주문수량', 주문수량)
            self.set_input_value('잔고수량', 잔고수량)
            self.comm_rq_data('opw20001_req', 'opw20001', '2', '2001')

    def tr_opw20002(self, 계좌번호, 비밀번호, 시장구분, 체결일자, 비밀번호입력매체구분):
        """
        선옵당일매매변동현황요청
        """
        self.set_input_value('계좌번호', 계좌번호)
        self.set_input_value('비밀번호', 비밀번호)
        self.set_input_value('시장구분', 시장구분)
        self.set_input_value('체결일자', 체결일자)
        self.set_input_value('비밀번호입력매체구분', 비밀번호입력매체구분)
        self.comm_rq_data('opw20002_req', 'opw20002', '0', '2002')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('계좌번호', 계좌번호)
            self.set_input_value('비밀번호', 비밀번호)
            self.set_input_value('시장구분', 시장구분)
            self.set_input_value('체결일자', 체결일자)
            self.set_input_value('비밀번호입력매체구분', 비밀번호입력매체구분)
            self.comm_rq_data('opw20002_req', 'opw20002', '2', '2002')

    def tr_opw20003(self, 계좌번호, 시장구분, 비밀번호, 시작일자, 종료일자, 비밀번호입력매체구분):
        """
        선옵기간손익조회요청
        """
        self.set_input_value('계좌번호', 계좌번호)
        self.set_input_value('시장구분', 시장구분)
        self.set_input_value('비밀번호', 비밀번호)
        self.set_input_value('시작일자', 시작일자)
        self.set_input_value('종료일자', 종료일자)
        self.set_input_value('비밀번호입력매체구분', 비밀번호입력매체구분)
        self.comm_rq_data('opw20003_req', 'opw20003', '0', '2003')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('계좌번호', 계좌번호)
            self.set_input_value('시장구분', 시장구분)
            self.set_input_value('비밀번호', 비밀번호)
            self.set_input_value('시작일자', 시작일자)
            self.set_input_value('종료일자', 종료일자)
            self.set_input_value('비밀번호입력매체구분', 비밀번호입력매체구분)
            self.comm_rq_data('opw20003_req', 'opw20003', '2', '2003')

    def tr_opw20004(self, 계좌번호, 비밀번호, 조회일, 종목구분, 조회구분, 정렬구분, 비밀번호입력매체구분, 정규시간외구분):
        """
        선옵주문체결내역상세요청
        """
        self.set_input_value('계좌번호', 계좌번호)
        self.set_input_value('비밀번호', 비밀번호)
        self.set_input_value('조회일', 조회일)
        self.set_input_value('종목구분', 종목구분)
        self.set_input_value('조회구분', 조회구분)
        self.set_input_value('정렬구분', 정렬구분)
        self.set_input_value('비밀번호입력매체구분', 비밀번호입력매체구분)
        self.set_input_value('정규시간외구분', 정규시간외구분)
        self.comm_rq_data('opw20004_req', 'opw20004', '0', '2004')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('계좌번호', 계좌번호)
            self.set_input_value('비밀번호', 비밀번호)
            self.set_input_value('조회일', 조회일)
            self.set_input_value('종목구분', 종목구분)
            self.set_input_value('조회구분', 조회구분)
            self.set_input_value('정렬구분', 정렬구분)
            self.set_input_value('비밀번호입력매체구분', 비밀번호입력매체구분)
            self.set_input_value('정규시간외구분', 정규시간외구분)
            self.comm_rq_data('opw20004_req', 'opw20004', '2', '2004')

    def tr_opw20005(self, 계좌번호, 비밀번호, 조회일, 종목구분, 조회구분, 정렬구분, 정규시간외구분, 비밀번호입력매체구분):
        """
        선옵주문체결내역상세평균가요청
        """
        self.set_input_value('계좌번호', 계좌번호)
        self.set_input_value('비밀번호', 비밀번호)
        self.set_input_value('조회일', 조회일)
        self.set_input_value('종목구분', 종목구분)
        self.set_input_value('조회구분', 조회구분)
        self.set_input_value('정렬구분', 정렬구분)
        self.set_input_value('정규시간외구분', 정규시간외구분)
        self.set_input_value('비밀번호입력매체구분', 비밀번호입력매체구분)
        self.comm_rq_data('opw20005_req', 'opw20005', '0', '2005')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('계좌번호', 계좌번호)
            self.set_input_value('비밀번호', 비밀번호)
            self.set_input_value('조회일', 조회일)
            self.set_input_value('종목구분', 종목구분)
            self.set_input_value('조회구분', 조회구분)
            self.set_input_value('정렬구분', 정렬구분)
            self.set_input_value('정규시간외구분', 정규시간외구분)
            self.set_input_value('비밀번호입력매체구분', 비밀번호입력매체구분)
            self.comm_rq_data('opw20005_req', 'opw20005', '2', '2005')

    def tr_opw20006(self, 계좌번호, 비밀번호, 조회일자, 비밀번호입력매체구분):
        """
        선옵잔고상세현황요청
        """
        self.set_input_value('계좌번호', 계좌번호)
        self.set_input_value('비밀번호', 비밀번호)
        self.set_input_value('조회일자', 조회일자)
        self.set_input_value('비밀번호입력매체구분', 비밀번호입력매체구분)
        self.comm_rq_data('opw20006_req', 'opw20006', '0', '2006')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('계좌번호', 계좌번호)
            self.set_input_value('비밀번호', 비밀번호)
            self.set_input_value('조회일자', 조회일자)
            self.set_input_value('비밀번호입력매체구분', 비밀번호입력매체구분)
            self.comm_rq_data('opw20006_req', 'opw20006', '2', '2006')

    def tr_opw20007(self, 계좌번호, 비밀번호, 비밀번호입력매체구분):
        """
        선옵잔고현황정산가기준요청
        """
        self.set_input_value('계좌번호', 계좌번호)
        self.set_input_value('비밀번호', 비밀번호)
        self.set_input_value('비밀번호입력매체구분', 비밀번호입력매체구분)
        self.comm_rq_data('opw20007_req', 'opw20007', '0', '2007')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('계좌번호', 계좌번호)
            self.set_input_value('비밀번호', 비밀번호)
            self.set_input_value('비밀번호입력매체구분', 비밀번호입력매체구분)
            self.comm_rq_data('opw20007_req', 'opw20007', '2', '2007')

    def tr_opw20008(self, 계좌번호, 비밀번호, 비밀번호입력매체구분):
        """
        계좌별결제예상내역조회요청
        """
        self.set_input_value('계좌번호', 계좌번호)
        self.set_input_value('비밀번호', 비밀번호)
        self.set_input_value('비밀번호입력매체구분', 비밀번호입력매체구분)
        self.comm_rq_data('opw20008_req', 'opw20008', '0', '2008')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('계좌번호', 계좌번호)
            self.set_input_value('비밀번호', 비밀번호)
            self.set_input_value('비밀번호입력매체구분', 비밀번호입력매체구분)
            self.comm_rq_data('opw20008_req', 'opw20008', '2', '2008')

    def tr_opw20009(self, 계좌번호, 비밀번호, 종목코드, 매도수구분, 주문유형, 주문가격, 비밀번호입력매체구분):
        """
        선옵계좌별주문가능수량요청
        """
        self.set_input_value('계좌번호', 계좌번호)
        self.set_input_value('비밀번호', 비밀번호)
        self.set_input_value('종목코드', 종목코드)
        self.set_input_value('매도수구분', 매도수구분)
        self.set_input_value('주문유형', 주문유형)
        self.set_input_value('주문가격', 주문가격)
        self.set_input_value('비밀번호입력매체구분', 비밀번호입력매체구분)
        self.comm_rq_data('opw20009_req', 'opw20009', '0', '2009')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('계좌번호', 계좌번호)
            self.set_input_value('비밀번호', 비밀번호)
            self.set_input_value('종목코드', 종목코드)
            self.set_input_value('매도수구분', 매도수구분)
            self.set_input_value('주문유형', 주문유형)
            self.set_input_value('주문가격', 주문가격)
            self.set_input_value('비밀번호입력매체구분', 비밀번호입력매체구분)
            self.comm_rq_data('opw20009_req', 'opw20009', '2', '2009')

    def tr_opw20010(self, 계좌번호, 비밀번호, 비밀번호입력매체구분):
        """
        선옵예탁금및증거금조회요청
        """
        self.set_input_value('계좌번호', 계좌번호)
        self.set_input_value('비밀번호', 비밀번호)
        self.set_input_value('비밀번호입력매체구분', 비밀번호입력매체구분)
        self.comm_rq_data('opw20010_req', 'opw20010', '0', '2010')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('계좌번호', 계좌번호)
            self.set_input_value('비밀번호', 비밀번호)
            self.set_input_value('비밀번호입력매체구분', 비밀번호입력매체구분)
            self.comm_rq_data('opw20010_req', 'opw20010', '2', '2010')

    def tr_opw20011(self, 계좌번호, 비밀번호, 증거금구분, 비밀번호입력매체구분):
        """
        선옵계좌예비증거금상세요청
        """
        self.set_input_value('계좌번호', 계좌번호)
        self.set_input_value('비밀번호', 비밀번호)
        self.set_input_value('증거금구분', 증거금구분)
        self.set_input_value('비밀번호입력매체구분', 비밀번호입력매체구분)
        self.comm_rq_data('opw20011_req', 'opw20011', '0', '2011')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('계좌번호', 계좌번호)
            self.set_input_value('비밀번호', 비밀번호)
            self.set_input_value('증거금구분', 증거금구분)
            self.set_input_value('비밀번호입력매체구분', 비밀번호입력매체구분)
            self.comm_rq_data('opw20011_req', 'opw20011', '2', '2011')

    def tr_opw20012(self, 계좌번호, 비밀번호, 비밀번호입력매체구분):
        """
        선옵증거금상세내역요청
        """
        self.set_input_value('계좌번호', 계좌번호)
        self.set_input_value('비밀번호', 비밀번호)
        self.set_input_value('비밀번호입력매체구분', 비밀번호입력매체구분)
        self.comm_rq_data('opw20012_req', 'opw20012', '0', '2012')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('계좌번호', 계좌번호)
            self.set_input_value('비밀번호', 비밀번호)
            self.set_input_value('비밀번호입력매체구분', 비밀번호입력매체구분)
            self.comm_rq_data('opw20012_req', 'opw20012', '2', '2012')

    def tr_opw20013(self, 계좌번호, 비밀번호, 종목코드, 주문가격):
        """
        계좌미결제청산가능수량조회요청
        """
        self.set_input_value('계좌번호', 계좌번호)
        self.set_input_value('비밀번호', 비밀번호)
        self.set_input_value('종목코드', 종목코드)
        self.set_input_value('주문가격', 주문가격)
        self.comm_rq_data('opw20013_req', 'opw20013', '0', '2013')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('계좌번호', 계좌번호)
            self.set_input_value('비밀번호', 비밀번호)
            self.set_input_value('종목코드', 종목코드)
            self.set_input_value('주문가격', 주문가격)
            self.comm_rq_data('opw20013_req', 'opw20013', '2', '2013')

    def tr_opw20014(self, 계좌번호, 비밀번호, KOSPI200지수, 비밀번호입력매체구분):
        """
        선옵실시간증거금산출요청
        """
        self.set_input_value('계좌번호', 계좌번호)
        self.set_input_value('비밀번호', 비밀번호)
        self.set_input_value('KOSPI200지수', KOSPI200지수)
        self.set_input_value('비밀번호입력매체구분', 비밀번호입력매체구분)
        self.comm_rq_data('opw20014_req', 'opw20014', '0', '2014')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('계좌번호', 계좌번호)
            self.set_input_value('비밀번호', 비밀번호)
            self.set_input_value('KOSPI200지수', KOSPI200지수)
            self.set_input_value('비밀번호입력매체구분', 비밀번호입력매체구분)
            self.comm_rq_data('opw20014_req', 'opw20014', '2', '2014')

    def tr_opw20015(self, 월물구분, 클래스구분):
        """
        옵션매도주문증거금현황요청
        """
        self.set_input_value('월물구분', 월물구분)
        self.set_input_value('클래스구분', 클래스구분)
        self.comm_rq_data('opw20015_req', 'opw20015', '0', '2015')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('월물구분', 월물구분)
            self.set_input_value('클래스구분', 클래스구분)
            self.comm_rq_data('opw20015_req', 'opw20015', '2', '2015')

    def tr_opw20016(self, 신용종목등급구분, 시장거래구분, 종목번호):
        """
        신용융자 가능종목요청
        """
        self.set_input_value('신용종목등급구분', 신용종목등급구분)
        self.set_input_value('시장거래구분', 시장거래구분)
        self.set_input_value('종목번호', 종목번호)
        self.comm_rq_data('opw20016_req', 'opw20016', '0', '2016')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('신용종목등급구분', 신용종목등급구분)
            self.set_input_value('시장거래구분', 시장거래구분)
            self.set_input_value('종목번호', 종목번호)
            self.comm_rq_data('opw20016_req', 'opw20016', '2', '2016')

    def tr_opw20017(self, 종목코드):
        """
        신용융자 가능문의
        """
        self.set_input_value('종목코드', 종목코드)
        self.comm_rq_data('opw20017_req', 'opw20017', '0', '2017')
        while self.remained_data:
            time.sleep(0.2)
            self.set_input_value('종목코드', 종목코드)
            self.comm_rq_data('opw20017_req', 'opw20017', '2', '2017')

    def _opt10001(self, rqname, trcode):
        """
    	주식기본정보요청
    	"""
        self.opt10001_output = {'single': dict()}

        self.opt10001_output['single']['종목코드'] = self._get_comm_data(trcode, rqname, 0, '종목코드')
        self.opt10001_output['single']['종목명'] = self._get_comm_data(trcode, rqname, 0, '종목명')
        self.opt10001_output['single']['결산월'] = self._get_comm_data(trcode, rqname, 0, '결산월')
        self.opt10001_output['single']['액면가'] = self._get_comm_data(trcode, rqname, 0, '액면가')
        self.opt10001_output['single']['자본금'] = self._get_comm_data(trcode, rqname, 0, '자본금')
        self.opt10001_output['single']['상장주식'] = self._get_comm_data(trcode, rqname, 0, '상장주식')
        self.opt10001_output['single']['신용비율'] = self._get_comm_data(trcode, rqname, 0, '신용비율')
        self.opt10001_output['single']['연중최고'] = self._get_comm_data(trcode, rqname, 0, '연중최고')
        self.opt10001_output['single']['연중최저'] = self._get_comm_data(trcode, rqname, 0, '연중최저')
        self.opt10001_output['single']['시가총액'] = self._get_comm_data(trcode, rqname, 0, '시가총액')
        self.opt10001_output['single']['시가총액비중'] = self._get_comm_data(trcode, rqname, 0, '시가총액비중')
        self.opt10001_output['single']['외인소진률'] = self._get_comm_data(trcode, rqname, 0, '외인소진률')
        self.opt10001_output['single']['대용가'] = self._get_comm_data(trcode, rqname, 0, '대용가')
        self.opt10001_output['single']['PER'] = self._get_comm_data(trcode, rqname, 0, 'PER')
        self.opt10001_output['single']['EPS'] = self._get_comm_data(trcode, rqname, 0, 'EPS')
        self.opt10001_output['single']['ROE'] = self._get_comm_data(trcode, rqname, 0, 'ROE')
        self.opt10001_output['single']['PBR'] = self._get_comm_data(trcode, rqname, 0, 'PBR')
        self.opt10001_output['single']['EV'] = self._get_comm_data(trcode, rqname, 0, 'EV')
        self.opt10001_output['single']['BPS'] = self._get_comm_data(trcode, rqname, 0, 'BPS')
        self.opt10001_output['single']['매출액'] = self._get_comm_data(trcode, rqname, 0, '매출액')
        self.opt10001_output['single']['영업이익'] = self._get_comm_data(trcode, rqname, 0, '영업이익')
        self.opt10001_output['single']['당기순이익'] = self._get_comm_data(trcode, rqname, 0, '당기순이익')
        self.opt10001_output['single']['250최고'] = self._get_comm_data(trcode, rqname, 0, '250최고')
        self.opt10001_output['single']['250최저'] = self._get_comm_data(trcode, rqname, 0, '250최저')
        self.opt10001_output['single']['시가'] = self._get_comm_data(trcode, rqname, 0, '시가')
        self.opt10001_output['single']['고가'] = self._get_comm_data(trcode, rqname, 0, '고가')
        self.opt10001_output['single']['저가'] = self._get_comm_data(trcode, rqname, 0, '저가')
        self.opt10001_output['single']['상한가'] = self._get_comm_data(trcode, rqname, 0, '상한가')
        self.opt10001_output['single']['하한가'] = self._get_comm_data(trcode, rqname, 0, '하한가')
        self.opt10001_output['single']['기준가'] = self._get_comm_data(trcode, rqname, 0, '기준가')
        self.opt10001_output['single']['예상체결가'] = self._get_comm_data(trcode, rqname, 0, '예상체결가')
        self.opt10001_output['single']['예상체결수량'] = self._get_comm_data(trcode, rqname, 0, '예상체결수량')
        self.opt10001_output['single']['250최고가일'] = self._get_comm_data(trcode, rqname, 0, '250최고가일')
        self.opt10001_output['single']['250최고가대비율'] = self._get_comm_data(trcode, rqname, 0, '250최고가대비율')
        self.opt10001_output['single']['250최저가일'] = self._get_comm_data(trcode, rqname, 0, '250최저가일')
        self.opt10001_output['single']['250최저가대비율'] = self._get_comm_data(trcode, rqname, 0, '250최저가대비율')
        self.opt10001_output['single']['현재가'] = self._get_comm_data(trcode, rqname, 0, '현재가')
        self.opt10001_output['single']['대비기호'] = self._get_comm_data(trcode, rqname, 0, '대비기호')
        self.opt10001_output['single']['전일대비'] = self._get_comm_data(trcode, rqname, 0, '전일대비')
        self.opt10001_output['single']['등락율'] = self._get_comm_data(trcode, rqname, 0, '등락율')
        self.opt10001_output['single']['거래량'] = self._get_comm_data(trcode, rqname, 0, '거래량')
        self.opt10001_output['single']['거래대비'] = self._get_comm_data(trcode, rqname, 0, '거래대비')
        self.opt10001_output['single']['액면가단위'] = self._get_comm_data(trcode, rqname, 0, '액면가단위')
        self.opt10001_output['single']['유통주식'] = self._get_comm_data(trcode, rqname, 0, '유통주식')
        self.opt10001_output['single']['유통비율'] = self._get_comm_data(trcode, rqname, 0, '유통비율')

    def _opt10002(self, rqname, trcode):
        """
    	주식거래원요청
    	"""
        self.opt10002_output = {'multi': []}

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp[' 종목코드'] = self._get_comm_data(trcode, rqname, i, ' 종목코드')
            temp[' 종목명'] = self._get_comm_data(trcode, rqname, i, ' 종목명')
            temp[' 현재가'] = self._get_comm_data(trcode, rqname, i, ' 현재가')
            temp[' 등락부호'] = self._get_comm_data(trcode, rqname, i, ' 등락부호')
            temp[' 기준가'] = self._get_comm_data(trcode, rqname, i, ' 기준가')
            temp[' 전일대비'] = self._get_comm_data(trcode, rqname, i, ' 전일대비')
            temp[' 등락율'] = self._get_comm_data(trcode, rqname, i, ' 등락율')
            temp[' 매도거래원명1'] = self._get_comm_data(trcode, rqname, i, ' 매도거래원명1')
            temp[' 매도거래원1'] = self._get_comm_data(trcode, rqname, i, ' 매도거래원1')
            temp[' 매도거래량1'] = self._get_comm_data(trcode, rqname, i, ' 매도거래량1')
            temp[' 매수거래원명1'] = self._get_comm_data(trcode, rqname, i, ' 매수거래원명1')
            temp[' 매수거래원1'] = self._get_comm_data(trcode, rqname, i, ' 매수거래원1')
            temp[' 매수거래량1'] = self._get_comm_data(trcode, rqname, i, ' 매수거래량1')
            temp[' 매도거래원명2'] = self._get_comm_data(trcode, rqname, i, ' 매도거래원명2')
            temp[' 매도거래원2'] = self._get_comm_data(trcode, rqname, i, ' 매도거래원2')
            temp[' 매도거래량2'] = self._get_comm_data(trcode, rqname, i, ' 매도거래량2')
            temp[' 매수거래원명2'] = self._get_comm_data(trcode, rqname, i, ' 매수거래원명2')
            temp[' 매수거래원2'] = self._get_comm_data(trcode, rqname, i, ' 매수거래원2')
            temp[' 매수거래량2'] = self._get_comm_data(trcode, rqname, i, ' 매수거래량2')
            temp[' 매도거래원명3'] = self._get_comm_data(trcode, rqname, i, ' 매도거래원명3')
            temp[' 매도거래원3'] = self._get_comm_data(trcode, rqname, i, ' 매도거래원3')
            temp[' 매도거래량3'] = self._get_comm_data(trcode, rqname, i, ' 매도거래량3')
            temp[' 매수거래원명3'] = self._get_comm_data(trcode, rqname, i, ' 매수거래원명3')
            temp[' 매수거래원3'] = self._get_comm_data(trcode, rqname, i, ' 매수거래원3')
            temp[' 매수거래량3'] = self._get_comm_data(trcode, rqname, i, ' 매수거래량3')
            temp[' 매도거래원명4'] = self._get_comm_data(trcode, rqname, i, ' 매도거래원명4')
            temp[' 매도거래원4'] = self._get_comm_data(trcode, rqname, i, ' 매도거래원4')
            temp[' 매도거래량4'] = self._get_comm_data(trcode, rqname, i, ' 매도거래량4')
            temp[' 매수거래원명4'] = self._get_comm_data(trcode, rqname, i, ' 매수거래원명4')
            temp[' 매수거래원4'] = self._get_comm_data(trcode, rqname, i, ' 매수거래원4')
            temp[' 매수거래량4'] = self._get_comm_data(trcode, rqname, i, ' 매수거래량4')
            temp[' 매도거래원명5'] = self._get_comm_data(trcode, rqname, i, ' 매도거래원명5')
            temp[' 매도거래원5'] = self._get_comm_data(trcode, rqname, i, ' 매도거래원5')
            temp[' 매도거래량5'] = self._get_comm_data(trcode, rqname, i, ' 매도거래량5')
            temp[' 매수거래원명5'] = self._get_comm_data(trcode, rqname, i, ' 매수거래원명5')
            temp[' 매수거래원5'] = self._get_comm_data(trcode, rqname, i, ' 매수거래원5')
            temp[' 매수거래량5'] = self._get_comm_data(trcode, rqname, i, ' 매수거래량5')
            self.opt10002_output['multi'].append(temp)

    def _opt10003(self, rqname, trcode):
        """
    	체결정보요청
    	"""
        self.opt10003_output = {'multi': []}

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['시간'] = self._get_comm_data(trcode, rqname, i, '시간')
            temp['현재가'] = self._get_comm_data(trcode, rqname, i, '현재가')
            temp['전일대비'] = self._get_comm_data(trcode, rqname, i, '전일대비')
            temp['대비율'] = self._get_comm_data(trcode, rqname, i, '대비율')
            temp['우선매도호가단위'] = self._get_comm_data(trcode, rqname, i, '우선매도호가단위')
            temp['우선매수호가단위'] = self._get_comm_data(trcode, rqname, i, '우선매수호가단위')
            temp['체결거래량'] = self._get_comm_data(trcode, rqname, i, '체결거래량')
            temp['sign'] = self._get_comm_data(trcode, rqname, i, 'sign')
            temp['누적거래량'] = self._get_comm_data(trcode, rqname, i, '누적거래량')
            temp['누적거래대금'] = self._get_comm_data(trcode, rqname, i, '누적거래대금')
            temp['체결강도'] = self._get_comm_data(trcode, rqname, i, '체결강도')
            self.opt10003_output['multi'].append(temp)

    def _opt10004(self, rqname, trcode):
        """
    	주식호가요청
    	"""
        self.opt10004_output = {'multi': []}

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['호가잔량기준시간'] = self._get_comm_data(trcode, rqname, i, '호가잔량기준시간')
            temp['매도10차선잔량대비'] = self._get_comm_data(trcode, rqname, i, '매도10차선잔량대비')
            temp['매도10차선잔량'] = self._get_comm_data(trcode, rqname, i, '매도10차선잔량')
            temp['매도10차선호가'] = self._get_comm_data(trcode, rqname, i, '매도10차선호가')
            temp['매도9차선잔량대비'] = self._get_comm_data(trcode, rqname, i, '매도9차선잔량대비')
            temp['매도9차선잔량'] = self._get_comm_data(trcode, rqname, i, '매도9차선잔량')
            temp['매도9차선호가'] = self._get_comm_data(trcode, rqname, i, '매도9차선호가')
            temp['매도8차선잔량대비'] = self._get_comm_data(trcode, rqname, i, '매도8차선잔량대비')
            temp['매도8차선잔량'] = self._get_comm_data(trcode, rqname, i, '매도8차선잔량')
            temp['매도8차선호가'] = self._get_comm_data(trcode, rqname, i, '매도8차선호가')
            temp['매도7차선잔량대비'] = self._get_comm_data(trcode, rqname, i, '매도7차선잔량대비')
            temp['매도7차선잔량'] = self._get_comm_data(trcode, rqname, i, '매도7차선잔량')
            temp['매도7차선호가'] = self._get_comm_data(trcode, rqname, i, '매도7차선호가')
            temp['매도6차선잔량대비'] = self._get_comm_data(trcode, rqname, i, '매도6차선잔량대비')
            temp['매도6우선잔량'] = self._get_comm_data(trcode, rqname, i, '매도6우선잔량')
            temp['매도6차선호가'] = self._get_comm_data(trcode, rqname, i, '매도6차선호가')
            temp['매도5차선잔량대비'] = self._get_comm_data(trcode, rqname, i, '매도5차선잔량대비')
            temp['매도5차선잔량'] = self._get_comm_data(trcode, rqname, i, '매도5차선잔량')
            temp['매도5차선호가'] = self._get_comm_data(trcode, rqname, i, '매도5차선호가')
            temp['매도4차선잔량대비'] = self._get_comm_data(trcode, rqname, i, '매도4차선잔량대비')
            temp['매도4차선잔량'] = self._get_comm_data(trcode, rqname, i, '매도4차선잔량')
            temp['매도4차선호가'] = self._get_comm_data(trcode, rqname, i, '매도4차선호가')
            temp['매도3차선잔량대비'] = self._get_comm_data(trcode, rqname, i, '매도3차선잔량대비')
            temp['매도3차선잔량'] = self._get_comm_data(trcode, rqname, i, '매도3차선잔량')
            temp['매도3차선호가'] = self._get_comm_data(trcode, rqname, i, '매도3차선호가')
            temp['매도2차선잔량대비'] = self._get_comm_data(trcode, rqname, i, '매도2차선잔량대비')
            temp['매도2차선잔량'] = self._get_comm_data(trcode, rqname, i, '매도2차선잔량')
            temp['매도2차선호가'] = self._get_comm_data(trcode, rqname, i, '매도2차선호가')
            temp['매도1차선잔량대비'] = self._get_comm_data(trcode, rqname, i, '매도1차선잔량대비')
            temp['매도최우선잔량'] = self._get_comm_data(trcode, rqname, i, '매도최우선잔량')
            temp['매도최우선호가'] = self._get_comm_data(trcode, rqname, i, '매도최우선호가')
            temp['매수최우선호가'] = self._get_comm_data(trcode, rqname, i, '매수최우선호가')
            temp['매수최우선잔량'] = self._get_comm_data(trcode, rqname, i, '매수최우선잔량')
            temp['매수1차선잔량대비'] = self._get_comm_data(trcode, rqname, i, '매수1차선잔량대비')
            temp['매수2차선호가'] = self._get_comm_data(trcode, rqname, i, '매수2차선호가')
            temp['매수2차선잔량'] = self._get_comm_data(trcode, rqname, i, '매수2차선잔량')
            temp['매수2차선잔량대비'] = self._get_comm_data(trcode, rqname, i, '매수2차선잔량대비')
            temp['매수3차선호가'] = self._get_comm_data(trcode, rqname, i, '매수3차선호가')
            temp['매수3차선잔량'] = self._get_comm_data(trcode, rqname, i, '매수3차선잔량')
            temp['매수3차선잔량대비'] = self._get_comm_data(trcode, rqname, i, '매수3차선잔량대비')
            temp['매수4차선호가'] = self._get_comm_data(trcode, rqname, i, '매수4차선호가')
            temp['매수4차선잔량'] = self._get_comm_data(trcode, rqname, i, '매수4차선잔량')
            temp['매수4차선잔량대비'] = self._get_comm_data(trcode, rqname, i, '매수4차선잔량대비')
            temp['매수5차선호가'] = self._get_comm_data(trcode, rqname, i, '매수5차선호가')
            temp['매수5차선잔량'] = self._get_comm_data(trcode, rqname, i, '매수5차선잔량')
            temp['매수5차선잔량대비'] = self._get_comm_data(trcode, rqname, i, '매수5차선잔량대비')
            temp['매수6우선호가'] = self._get_comm_data(trcode, rqname, i, '매수6우선호가')
            temp['매수6우선잔량'] = self._get_comm_data(trcode, rqname, i, '매수6우선잔량')
            temp['매수6차선잔량대비'] = self._get_comm_data(trcode, rqname, i, '매수6차선잔량대비')
            temp['매수7차선호가'] = self._get_comm_data(trcode, rqname, i, '매수7차선호가')
            temp['매수7차선잔량'] = self._get_comm_data(trcode, rqname, i, '매수7차선잔량')
            temp['매수7차선잔량대비'] = self._get_comm_data(trcode, rqname, i, '매수7차선잔량대비')
            temp['매수8차선호가'] = self._get_comm_data(trcode, rqname, i, '매수8차선호가')
            temp['매수8차선잔량'] = self._get_comm_data(trcode, rqname, i, '매수8차선잔량')
            temp['매수8차선잔량대비'] = self._get_comm_data(trcode, rqname, i, '매수8차선잔량대비')
            temp['매수9차선호가'] = self._get_comm_data(trcode, rqname, i, '매수9차선호가')
            temp['매수9차선잔량'] = self._get_comm_data(trcode, rqname, i, '매수9차선잔량')
            temp['매수9차선잔량대비'] = self._get_comm_data(trcode, rqname, i, '매수9차선잔량대비')
            temp['매수10차선호가'] = self._get_comm_data(trcode, rqname, i, '매수10차선호가')
            temp['매수10차선잔량'] = self._get_comm_data(trcode, rqname, i, '매수10차선잔량')
            temp['매수10차선잔량대비'] = self._get_comm_data(trcode, rqname, i, '매수10차선잔량대비')
            temp['총매도잔량직전대비'] = self._get_comm_data(trcode, rqname, i, '총매도잔량직전대비')
            temp['총매도잔량'] = self._get_comm_data(trcode, rqname, i, '총매도잔량')
            temp['총매수잔량'] = self._get_comm_data(trcode, rqname, i, '총매수잔량')
            temp['총매수잔량직전대비'] = self._get_comm_data(trcode, rqname, i, '총매수잔량직전대비')
            temp['시간외매도잔량대비'] = self._get_comm_data(trcode, rqname, i, '시간외매도잔량대비')
            temp['시간외매도잔량'] = self._get_comm_data(trcode, rqname, i, '시간외매도잔량')
            temp['시간외매수잔량'] = self._get_comm_data(trcode, rqname, i, '시간외매수잔량')
            temp['시간외매수잔량대비'] = self._get_comm_data(trcode, rqname, i, '시간외매수잔량대비')
            self.opt10004_output['multi'].append(temp)

    def _opt10005(self, rqname, trcode):
        """
    	주식일주월시분요청
    	"""
        self.opt10005_output = {'multi': []}

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['날짜'] = self._get_comm_data(trcode, rqname, i, '날짜')
            temp['시가'] = self._get_comm_data(trcode, rqname, i, '시가')
            temp['고가'] = self._get_comm_data(trcode, rqname, i, '고가')
            temp['저가'] = self._get_comm_data(trcode, rqname, i, '저가')
            temp['종가'] = self._get_comm_data(trcode, rqname, i, '종가')
            temp['대비'] = self._get_comm_data(trcode, rqname, i, '대비')
            temp['등락률'] = self._get_comm_data(trcode, rqname, i, '등락률')
            temp['거래량'] = self._get_comm_data(trcode, rqname, i, '거래량')
            temp['거래대금'] = self._get_comm_data(trcode, rqname, i, '거래대금')
            temp['체결강도'] = self._get_comm_data(trcode, rqname, i, '체결강도')
            temp['외인보유'] = self._get_comm_data(trcode, rqname, i, '외인보유')
            temp['외인비중'] = self._get_comm_data(trcode, rqname, i, '외인비중')
            temp['외인순매수'] = self._get_comm_data(trcode, rqname, i, '외인순매수')
            temp['기관순매수'] = self._get_comm_data(trcode, rqname, i, '기관순매수')
            temp['개인순매수'] = self._get_comm_data(trcode, rqname, i, '개인순매수')
            temp['외국계'] = self._get_comm_data(trcode, rqname, i, '외국계')
            temp['신용잔고율'] = self._get_comm_data(trcode, rqname, i, '신용잔고율')
            temp['프로그램'] = self._get_comm_data(trcode, rqname, i, '프로그램')
            self.opt10005_output['multi'].append(temp)

    def _opt10006(self, rqname, trcode):
        """
    	주식시분요청
    	"""
        self.opt10006_output = {'multi': []}

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['날짜'] = self._get_comm_data(trcode, rqname, i, '날짜')
            temp['시가'] = self._get_comm_data(trcode, rqname, i, '시가')
            temp['고가'] = self._get_comm_data(trcode, rqname, i, '고가')
            temp['저가'] = self._get_comm_data(trcode, rqname, i, '저가')
            temp['종가'] = self._get_comm_data(trcode, rqname, i, '종가')
            temp['대비'] = self._get_comm_data(trcode, rqname, i, '대비')
            temp['등락률'] = self._get_comm_data(trcode, rqname, i, '등락률')
            temp['거래량'] = self._get_comm_data(trcode, rqname, i, '거래량')
            temp['거래대금'] = self._get_comm_data(trcode, rqname, i, '거래대금')
            temp['체결강도'] = self._get_comm_data(trcode, rqname, i, '체결강도')
            self.opt10006_output['multi'].append(temp)

    def _opt10007(self, rqname, trcode):
        """
    	시세표성정보요청
    	"""
        self.opt10007_output = {'multi': []}

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['종목명'] = self._get_comm_data(trcode, rqname, i, '종목명')
            temp['종목코드'] = self._get_comm_data(trcode, rqname, i, '종목코드')
            temp['날짜'] = self._get_comm_data(trcode, rqname, i, '날짜')
            temp['시간'] = self._get_comm_data(trcode, rqname, i, '시간')
            temp['전일종가'] = self._get_comm_data(trcode, rqname, i, '전일종가')
            temp['전일거래량'] = self._get_comm_data(trcode, rqname, i, '전일거래량')
            temp['상한가'] = self._get_comm_data(trcode, rqname, i, '상한가')
            temp['하한가'] = self._get_comm_data(trcode, rqname, i, '하한가')
            temp['전일거래대금'] = self._get_comm_data(trcode, rqname, i, '전일거래대금')
            temp['상장주식수'] = self._get_comm_data(trcode, rqname, i, '상장주식수')
            temp['현재가'] = self._get_comm_data(trcode, rqname, i, '현재가')
            temp['부호'] = self._get_comm_data(trcode, rqname, i, '부호')
            temp['등락률'] = self._get_comm_data(trcode, rqname, i, '등락률')
            temp['전일비'] = self._get_comm_data(trcode, rqname, i, '전일비')
            temp['시가'] = self._get_comm_data(trcode, rqname, i, '시가')
            temp['고가'] = self._get_comm_data(trcode, rqname, i, '고가')
            temp['저가'] = self._get_comm_data(trcode, rqname, i, '저가')
            temp['체결량'] = self._get_comm_data(trcode, rqname, i, '체결량')
            temp['거래량'] = self._get_comm_data(trcode, rqname, i, '거래량')
            temp['거래대금'] = self._get_comm_data(trcode, rqname, i, '거래대금')
            temp['예상체결가'] = self._get_comm_data(trcode, rqname, i, '예상체결가')
            temp['예상체결량'] = self._get_comm_data(trcode, rqname, i, '예상체결량')
            temp['예상매도우선호가'] = self._get_comm_data(trcode, rqname, i, '예상매도우선호가')
            temp['예상매수우선호가'] = self._get_comm_data(trcode, rqname, i, '예상매수우선호가')
            temp['거래시작일'] = self._get_comm_data(trcode, rqname, i, '거래시작일')
            temp['행사가격'] = self._get_comm_data(trcode, rqname, i, '행사가격')
            temp['최고가'] = self._get_comm_data(trcode, rqname, i, '최고가')
            temp['최저가'] = self._get_comm_data(trcode, rqname, i, '최저가')
            temp['최고가일'] = self._get_comm_data(trcode, rqname, i, '최고가일')
            temp['최저가일'] = self._get_comm_data(trcode, rqname, i, '최저가일')
            temp['매도1호가'] = self._get_comm_data(trcode, rqname, i, '매도1호가')
            temp['매도2호가'] = self._get_comm_data(trcode, rqname, i, '매도2호가')
            temp['매도3호가'] = self._get_comm_data(trcode, rqname, i, '매도3호가')
            temp['매도4호가'] = self._get_comm_data(trcode, rqname, i, '매도4호가')
            temp['매도5호가'] = self._get_comm_data(trcode, rqname, i, '매도5호가')
            temp['매도6호가'] = self._get_comm_data(trcode, rqname, i, '매도6호가')
            temp['매도7호가'] = self._get_comm_data(trcode, rqname, i, '매도7호가')
            temp['매도8호가'] = self._get_comm_data(trcode, rqname, i, '매도8호가')
            temp['매도9호가'] = self._get_comm_data(trcode, rqname, i, '매도9호가')
            temp['매도10호가'] = self._get_comm_data(trcode, rqname, i, '매도10호가')
            temp['매수1호가'] = self._get_comm_data(trcode, rqname, i, '매수1호가')
            temp['매수2호가'] = self._get_comm_data(trcode, rqname, i, '매수2호가')
            temp['매수3호가'] = self._get_comm_data(trcode, rqname, i, '매수3호가')
            temp['매수4호가'] = self._get_comm_data(trcode, rqname, i, '매수4호가')
            temp['매수5호가'] = self._get_comm_data(trcode, rqname, i, '매수5호가')
            temp['매수6호가'] = self._get_comm_data(trcode, rqname, i, '매수6호가')
            temp['매수7호가'] = self._get_comm_data(trcode, rqname, i, '매수7호가')
            temp['매수8호가'] = self._get_comm_data(trcode, rqname, i, '매수8호가')
            temp['매수9호가'] = self._get_comm_data(trcode, rqname, i, '매수9호가')
            temp['매수10호가'] = self._get_comm_data(trcode, rqname, i, '매수10호가')
            temp['매도1호가잔량'] = self._get_comm_data(trcode, rqname, i, '매도1호가잔량')
            temp['매도2호가잔량'] = self._get_comm_data(trcode, rqname, i, '매도2호가잔량')
            temp['매도3호가잔량'] = self._get_comm_data(trcode, rqname, i, '매도3호가잔량')
            temp['매도4호가잔량'] = self._get_comm_data(trcode, rqname, i, '매도4호가잔량')
            temp['매도5호가잔량'] = self._get_comm_data(trcode, rqname, i, '매도5호가잔량')
            temp['매도6호가잔량'] = self._get_comm_data(trcode, rqname, i, '매도6호가잔량')
            temp['매도7호가잔량'] = self._get_comm_data(trcode, rqname, i, '매도7호가잔량')
            temp['매도8호가잔량'] = self._get_comm_data(trcode, rqname, i, '매도8호가잔량')
            temp['매도9호가잔량'] = self._get_comm_data(trcode, rqname, i, '매도9호가잔량')
            temp['매도10호가잔량'] = self._get_comm_data(trcode, rqname, i, '매도10호가잔량')
            temp['매수1호가잔량'] = self._get_comm_data(trcode, rqname, i, '매수1호가잔량')
            temp['매수2호가잔량'] = self._get_comm_data(trcode, rqname, i, '매수2호가잔량')
            temp['매수3호가잔량'] = self._get_comm_data(trcode, rqname, i, '매수3호가잔량')
            temp['매수4호가잔량'] = self._get_comm_data(trcode, rqname, i, '매수4호가잔량')
            temp['매수5호가잔량'] = self._get_comm_data(trcode, rqname, i, '매수5호가잔량')
            temp['매수6호가잔량'] = self._get_comm_data(trcode, rqname, i, '매수6호가잔량')
            temp['매수7호가잔량'] = self._get_comm_data(trcode, rqname, i, '매수7호가잔량')
            temp['매수8호가잔량'] = self._get_comm_data(trcode, rqname, i, '매수8호가잔량')
            temp['매수9호가잔량'] = self._get_comm_data(trcode, rqname, i, '매수9호가잔량')
            temp['매수10호가잔량'] = self._get_comm_data(trcode, rqname, i, '매수10호가잔량')
            temp['매도1호가직전대비'] = self._get_comm_data(trcode, rqname, i, '매도1호가직전대비')
            temp['매도2호가직전대비'] = self._get_comm_data(trcode, rqname, i, '매도2호가직전대비')
            temp['매도3호가직전대비'] = self._get_comm_data(trcode, rqname, i, '매도3호가직전대비')
            temp['매도4호가직전대비'] = self._get_comm_data(trcode, rqname, i, '매도4호가직전대비')
            temp['매도5호가직전대비'] = self._get_comm_data(trcode, rqname, i, '매도5호가직전대비')
            temp['매도6호가직전대비'] = self._get_comm_data(trcode, rqname, i, '매도6호가직전대비')
            temp['매도7호가직전대비'] = self._get_comm_data(trcode, rqname, i, '매도7호가직전대비')
            temp['매도8호가직전대비'] = self._get_comm_data(trcode, rqname, i, '매도8호가직전대비')
            temp['매도9호가직전대비'] = self._get_comm_data(trcode, rqname, i, '매도9호가직전대비')
            temp['매도10호가직전대비'] = self._get_comm_data(trcode, rqname, i, '매도10호가직전대비')
            temp['매수1호가직전대비'] = self._get_comm_data(trcode, rqname, i, '매수1호가직전대비')
            temp['매수2호가직전대비'] = self._get_comm_data(trcode, rqname, i, '매수2호가직전대비')
            temp['매수3호가직전대비'] = self._get_comm_data(trcode, rqname, i, '매수3호가직전대비')
            temp['매수4호가직전대비'] = self._get_comm_data(trcode, rqname, i, '매수4호가직전대비')
            temp['매수5호가직전대비'] = self._get_comm_data(trcode, rqname, i, '매수5호가직전대비')
            temp['매수6호가직전대비'] = self._get_comm_data(trcode, rqname, i, '매수6호가직전대비')
            temp['매수7호가직전대비'] = self._get_comm_data(trcode, rqname, i, '매수7호가직전대비')
            temp['매수8호가직전대비'] = self._get_comm_data(trcode, rqname, i, '매수8호가직전대비')
            temp['매수9호가직전대비'] = self._get_comm_data(trcode, rqname, i, '매수9호가직전대비')
            temp['매수10호가직전대비'] = self._get_comm_data(trcode, rqname, i, '매수10호가직전대비')
            temp['매도1호가건수'] = self._get_comm_data(trcode, rqname, i, '매도1호가건수')
            temp['매도2호가건수'] = self._get_comm_data(trcode, rqname, i, '매도2호가건수')
            temp['매도3호가건수'] = self._get_comm_data(trcode, rqname, i, '매도3호가건수')
            temp['매도4호가건수'] = self._get_comm_data(trcode, rqname, i, '매도4호가건수')
            temp['매도5호가건수'] = self._get_comm_data(trcode, rqname, i, '매도5호가건수')
            temp['매수1호가건수'] = self._get_comm_data(trcode, rqname, i, '매수1호가건수')
            temp['매수2호가건수'] = self._get_comm_data(trcode, rqname, i, '매수2호가건수')
            temp['매수3호가건수'] = self._get_comm_data(trcode, rqname, i, '매수3호가건수')
            temp['매수4호가건수'] = self._get_comm_data(trcode, rqname, i, '매수4호가건수')
            temp['매수5호가건수'] = self._get_comm_data(trcode, rqname, i, '매수5호가건수')
            temp['LP매도1호가잔량'] = self._get_comm_data(trcode, rqname, i, 'LP매도1호가잔량')
            temp['LP매도2호가잔량'] = self._get_comm_data(trcode, rqname, i, 'LP매도2호가잔량')
            temp['LP매도3호가잔량'] = self._get_comm_data(trcode, rqname, i, 'LP매도3호가잔량')
            temp['LP매도4호가잔량'] = self._get_comm_data(trcode, rqname, i, 'LP매도4호가잔량')
            temp['LP매도5호가잔량'] = self._get_comm_data(trcode, rqname, i, 'LP매도5호가잔량')
            temp['LP매도6호가잔량'] = self._get_comm_data(trcode, rqname, i, 'LP매도6호가잔량')
            temp['LP매도7호가잔량'] = self._get_comm_data(trcode, rqname, i, 'LP매도7호가잔량')
            temp['LP매도8호가잔량'] = self._get_comm_data(trcode, rqname, i, 'LP매도8호가잔량')
            temp['LP매도9호가잔량'] = self._get_comm_data(trcode, rqname, i, 'LP매도9호가잔량')
            temp['LP매도10호가잔량'] = self._get_comm_data(trcode, rqname, i, 'LP매도10호가잔량')
            temp['LP매수1호가잔량'] = self._get_comm_data(trcode, rqname, i, 'LP매수1호가잔량')
            temp['LP매수2호가잔량'] = self._get_comm_data(trcode, rqname, i, 'LP매수2호가잔량')
            temp['LP매수3호가잔량'] = self._get_comm_data(trcode, rqname, i, 'LP매수3호가잔량')
            temp['LP매수4호가잔량'] = self._get_comm_data(trcode, rqname, i, 'LP매수4호가잔량')
            temp['LP매수5호가잔량'] = self._get_comm_data(trcode, rqname, i, 'LP매수5호가잔량')
            temp['LP매수6호가잔량'] = self._get_comm_data(trcode, rqname, i, 'LP매수6호가잔량')
            temp['LP매수7호가잔량'] = self._get_comm_data(trcode, rqname, i, 'LP매수7호가잔량')
            temp['LP매수8호가잔량'] = self._get_comm_data(trcode, rqname, i, 'LP매수8호가잔량')
            temp['LP매수9호가잔량'] = self._get_comm_data(trcode, rqname, i, 'LP매수9호가잔량')
            temp['LP매수10호가잔량'] = self._get_comm_data(trcode, rqname, i, 'LP매수10호가잔량')
            temp['총매수잔량'] = self._get_comm_data(trcode, rqname, i, '총매수잔량')
            temp['총매도잔량'] = self._get_comm_data(trcode, rqname, i, '총매도잔량')
            temp['총매수건수'] = self._get_comm_data(trcode, rqname, i, '총매수건수')
            temp['총매도건수'] = self._get_comm_data(trcode, rqname, i, '총매도건수')
            self.opt10007_output['multi'].append(temp)

    def _opt10008(self, rqname, trcode):
        """
    	주식외국인요청
    	"""
        self.opt10008_output = {'multi': []}

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['일자'] = self._get_comm_data(trcode, rqname, i, '일자')
            temp['종가'] = self._get_comm_data(trcode, rqname, i, '종가')
            temp['전일대비'] = self._get_comm_data(trcode, rqname, i, '전일대비')
            temp['거래량'] = self._get_comm_data(trcode, rqname, i, '거래량')
            temp['변동수량'] = self._get_comm_data(trcode, rqname, i, '변동수량')
            temp['보유주식수'] = self._get_comm_data(trcode, rqname, i, '보유주식수')
            temp['비중'] = self._get_comm_data(trcode, rqname, i, '비중')
            temp['취득가능주식수'] = self._get_comm_data(trcode, rqname, i, '취득가능주식수')
            temp['외국인한도'] = self._get_comm_data(trcode, rqname, i, '외국인한도')
            temp['외국인한도증감'] = self._get_comm_data(trcode, rqname, i, '외국인한도증감')
            temp['한도소진률'] = self._get_comm_data(trcode, rqname, i, '한도소진률')
            self.opt10008_output['multi'].append(temp)

    def _opt10009(self, rqname, trcode):
        """
    	주식기관요청
    	"""
        self.opt10009_output = {'multi': []}

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['날짜'] = self._get_comm_data(trcode, rqname, i, '날짜')
            temp['종가'] = self._get_comm_data(trcode, rqname, i, '종가')
            temp['대비'] = self._get_comm_data(trcode, rqname, i, '대비')
            temp['기관기간누적'] = self._get_comm_data(trcode, rqname, i, '기관기간누적')
            temp['기관일변순매매'] = self._get_comm_data(trcode, rqname, i, '기관일변순매매')
            temp['외국인일변순매매'] = self._get_comm_data(trcode, rqname, i, '외국인일변순매매')
            temp['외국인지분율'] = self._get_comm_data(trcode, rqname, i, '외국인지분율')
            self.opt10009_output['multi'].append(temp)

    def _opt10010(self, rqname, trcode):
        """
    	업종프로그램요청
    	"""
        self.opt10010_output = {'multi': []}

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['차익위탁매도수량'] = self._get_comm_data(trcode, rqname, i, '차익위탁매도수량')
            temp['차익위탁매도금액'] = self._get_comm_data(trcode, rqname, i, '차익위탁매도금액')
            temp['차익위탁매수수량'] = self._get_comm_data(trcode, rqname, i, '차익위탁매수수량')
            temp['차익위탁매수금액'] = self._get_comm_data(trcode, rqname, i, '차익위탁매수금액')
            temp['차익위탁순매수수량'] = self._get_comm_data(trcode, rqname, i, '차익위탁순매수수량')
            temp['차익위탁순매수금액'] = self._get_comm_data(trcode, rqname, i, '차익위탁순매수금액')
            temp['비차익위탁매도수량'] = self._get_comm_data(trcode, rqname, i, '비차익위탁매도수량')
            temp['비차익위탁매도금액'] = self._get_comm_data(trcode, rqname, i, '비차익위탁매도금액')
            temp['비차익위탁매수수량'] = self._get_comm_data(trcode, rqname, i, '비차익위탁매수수량')
            temp['비차익위탁매수금액'] = self._get_comm_data(trcode, rqname, i, '비차익위탁매수금액')
            temp['비차익위탁순매수수량'] = self._get_comm_data(trcode, rqname, i, '비차익위탁순매수수량')
            temp['비차익위탁순매수금액'] = self._get_comm_data(trcode, rqname, i, '비차익위탁순매수금액')
            temp['전체차익위탁매도수량'] = self._get_comm_data(trcode, rqname, i, '전체차익위탁매도수량')
            temp['전체차익위탁매도금액'] = self._get_comm_data(trcode, rqname, i, '전체차익위탁매도금액')
            temp['전체차익위탁매수수량'] = self._get_comm_data(trcode, rqname, i, '전체차익위탁매수수량')
            temp['전체차익위탁매수금액'] = self._get_comm_data(trcode, rqname, i, '전체차익위탁매수금액')
            temp['전체차익위탁순매수수량'] = self._get_comm_data(trcode, rqname, i, '전체차익위탁순매수수량')
            temp['전체차익위탁순매수금액'] = self._get_comm_data(trcode, rqname, i, '전체차익위탁순매수금액')
            self.opt10010_output['multi'].append(temp)

    def _opt10012(self, rqname, trcode):
        """
    	주문체결요청
    	"""
        self.opt10012_output = {'multi': []}

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['주문수량'] = self._get_comm_data(trcode, rqname, i, '주문수량')
            temp['주문가격'] = self._get_comm_data(trcode, rqname, i, '주문가격')
            temp['미체결수량'] = self._get_comm_data(trcode, rqname, i, '미체결수량')
            temp['체결누계금액'] = self._get_comm_data(trcode, rqname, i, '체결누계금액')
            temp['원주문번호'] = self._get_comm_data(trcode, rqname, i, '원주문번호')
            temp['주문구분'] = self._get_comm_data(trcode, rqname, i, '주문구분')
            temp['매매구분'] = self._get_comm_data(trcode, rqname, i, '매매구분')
            temp['매도수구분'] = self._get_comm_data(trcode, rqname, i, '매도수구분')
            temp['주문/체결시간'] = self._get_comm_data(trcode, rqname, i, '주문/체결시간')
            temp['체결가'] = self._get_comm_data(trcode, rqname, i, '체결가')
            temp['체결량'] = self._get_comm_data(trcode, rqname, i, '체결량')
            temp['주문상태'] = self._get_comm_data(trcode, rqname, i, '주문상태')
            temp['단위체결가'] = self._get_comm_data(trcode, rqname, i, '단위체결가')
            temp['대출일'] = self._get_comm_data(trcode, rqname, i, '대출일')
            temp['신용구분'] = self._get_comm_data(trcode, rqname, i, '신용구분')
            temp['만기일'] = self._get_comm_data(trcode, rqname, i, '만기일')
            temp['보유수량'] = self._get_comm_data(trcode, rqname, i, '보유수량')
            temp['매입단가'] = self._get_comm_data(trcode, rqname, i, '매입단가')
            temp['총매입가'] = self._get_comm_data(trcode, rqname, i, '총매입가')
            temp['주문가능수량'] = self._get_comm_data(trcode, rqname, i, '주문가능수량')
            temp['당일매도수량'] = self._get_comm_data(trcode, rqname, i, '당일매도수량')
            temp['당일매도금액'] = self._get_comm_data(trcode, rqname, i, '당일매도금액')
            temp['당일매수수량'] = self._get_comm_data(trcode, rqname, i, '당일매수수량')
            temp['당일매수금액'] = self._get_comm_data(trcode, rqname, i, '당일매수금액')
            temp['당일매매수수료'] = self._get_comm_data(trcode, rqname, i, '당일매매수수료')
            temp['당일매매세금'] = self._get_comm_data(trcode, rqname, i, '당일매매세금')
            temp['당일hts매도수수료'] = self._get_comm_data(trcode, rqname, i, '당일hts매도수수료')
            temp['당일hts매수수수료'] = self._get_comm_data(trcode, rqname, i, '당일hts매수수수료')
            temp['당일매도손익'] = self._get_comm_data(trcode, rqname, i, '당일매도손익')
            temp['당일순매수량'] = self._get_comm_data(trcode, rqname, i, '당일순매수량')
            temp['매도/매수구분'] = self._get_comm_data(trcode, rqname, i, '매도/매수구분')
            temp['당일총매도손일'] = self._get_comm_data(trcode, rqname, i, '당일총매도손일')
            temp['예수금'] = self._get_comm_data(trcode, rqname, i, '예수금')
            temp['사용가능현금'] = self._get_comm_data(trcode, rqname, i, '사용가능현금')
            temp['사용가능대용'] = self._get_comm_data(trcode, rqname, i, '사용가능대용')
            temp['전일재사용'] = self._get_comm_data(trcode, rqname, i, '전일재사용')
            temp['당일재사용'] = self._get_comm_data(trcode, rqname, i, '당일재사용')
            temp['담보현금'] = self._get_comm_data(trcode, rqname, i, '담보현금')
            temp['신용금액'] = self._get_comm_data(trcode, rqname, i, '신용금액')
            temp['신용이자'] = self._get_comm_data(trcode, rqname, i, '신용이자')
            temp['담보대출수량'] = self._get_comm_data(trcode, rqname, i, '담보대출수량')
            temp['현물주문체결이상유무'] = self._get_comm_data(trcode, rqname, i, '현물주문체결이상유무')
            temp['현물잔고이상유무'] = self._get_comm_data(trcode, rqname, i, '현물잔고이상유무')
            temp['현물예수금이상유무'] = self._get_comm_data(trcode, rqname, i, '현물예수금이상유무')
            temp['선물주문체결이상유무'] = self._get_comm_data(trcode, rqname, i, '선물주문체결이상유무')
            temp['선물잔고이상유무'] = self._get_comm_data(trcode, rqname, i, '선물잔고이상유무')
            temp['D+1추정예수금'] = self._get_comm_data(trcode, rqname, i, 'D+1추정예수금')
            temp['D+2추정예수금'] = self._get_comm_data(trcode, rqname, i, 'D+2추정예수금')
            temp['D+1매수/매도정산금'] = self._get_comm_data(trcode, rqname, i, 'D+1매수/매도정산금')
            temp['D+2매수/매도정산금'] = self._get_comm_data(trcode, rqname, i, 'D+2매수/매도정산금')
            temp['D+1연체변제소요금'] = self._get_comm_data(trcode, rqname, i, 'D+1연체변제소요금')
            temp['D+2연체변제소요금'] = self._get_comm_data(trcode, rqname, i, 'D+2연체변제소요금')
            temp['D+1추정인출가능금'] = self._get_comm_data(trcode, rqname, i, 'D+1추정인출가능금')
            temp['D+2추정인출가능금'] = self._get_comm_data(trcode, rqname, i, 'D+2추정인출가능금')
            temp['현금증거금'] = self._get_comm_data(trcode, rqname, i, '현금증거금')
            temp['대용잔고'] = self._get_comm_data(trcode, rqname, i, '대용잔고')
            temp['대용증거금'] = self._get_comm_data(trcode, rqname, i, '대용증거금')
            temp['수표금액'] = self._get_comm_data(trcode, rqname, i, '수표금액')
            temp['현금미수금'] = self._get_comm_data(trcode, rqname, i, '현금미수금')
            temp['신용설정보증금'] = self._get_comm_data(trcode, rqname, i, '신용설정보증금')
            temp['인출가능금액'] = self._get_comm_data(trcode, rqname, i, '인출가능금액')
            self.opt10012_output['multi'].append(temp)

    def _opt10013(self, rqname, trcode):
        """
    	신용매매동향요청
    	"""
        self.opt10013_output = {'multi': []}

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['일자'] = self._get_comm_data(trcode, rqname, i, '일자')
            temp['현재가'] = self._get_comm_data(trcode, rqname, i, '현재가')
            temp['전일대비기호'] = self._get_comm_data(trcode, rqname, i, '전일대비기호')
            temp['전일대비'] = self._get_comm_data(trcode, rqname, i, '전일대비')
            temp['거래량'] = self._get_comm_data(trcode, rqname, i, '거래량')
            temp['신규'] = self._get_comm_data(trcode, rqname, i, '신규')
            temp['상환'] = self._get_comm_data(trcode, rqname, i, '상환')
            temp['잔고'] = self._get_comm_data(trcode, rqname, i, '잔고')
            temp['금액'] = self._get_comm_data(trcode, rqname, i, '금액')
            temp['대비'] = self._get_comm_data(trcode, rqname, i, '대비')
            temp['공여율'] = self._get_comm_data(trcode, rqname, i, '공여율')
            temp['잔고율'] = self._get_comm_data(trcode, rqname, i, '잔고율')
            self.opt10013_output['multi'].append(temp)

    def _opt10014(self, rqname, trcode):
        """
    	공매도추이요청
    	"""
        self.opt10014_output = {'multi': []}

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['일자'] = self._get_comm_data(trcode, rqname, i, '일자')
            temp['종가'] = self._get_comm_data(trcode, rqname, i, '종가')
            temp['전일대비기호'] = self._get_comm_data(trcode, rqname, i, '전일대비기호')
            temp['전일대비'] = self._get_comm_data(trcode, rqname, i, '전일대비')
            temp['등락율'] = self._get_comm_data(trcode, rqname, i, '등락율')
            temp['거래량'] = self._get_comm_data(trcode, rqname, i, '거래량')
            temp['공매도량'] = self._get_comm_data(trcode, rqname, i, '공매도량')
            temp['매매비중'] = self._get_comm_data(trcode, rqname, i, '매매비중')
            temp['공매도거래대금'] = self._get_comm_data(trcode, rqname, i, '공매도거래대금')
            temp['공매도평균가'] = self._get_comm_data(trcode, rqname, i, '공매도평균가')
            self.opt10014_output['multi'].append(temp)

    def _opt10015(self, rqname, trcode):
        """
    	일별거래상세요청
    	"""
        self.opt10015_output = {'multi': []}

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['일자'] = self._get_comm_data(trcode, rqname, i, '일자')
            temp['종가'] = self._get_comm_data(trcode, rqname, i, '종가')
            temp['전일대비기호'] = self._get_comm_data(trcode, rqname, i, '전일대비기호')
            temp['전일대비'] = self._get_comm_data(trcode, rqname, i, '전일대비')
            temp['등락율'] = self._get_comm_data(trcode, rqname, i, '등락율')
            temp['거래량'] = self._get_comm_data(trcode, rqname, i, '거래량')
            temp['거래대금'] = self._get_comm_data(trcode, rqname, i, '거래대금')
            temp['장전거래량'] = self._get_comm_data(trcode, rqname, i, '장전거래량')
            temp['장전거래비중'] = self._get_comm_data(trcode, rqname, i, '장전거래비중')
            temp['장중거래량'] = self._get_comm_data(trcode, rqname, i, '장중거래량')
            temp['장중거래비중'] = self._get_comm_data(trcode, rqname, i, '장중거래비중')
            temp['장후거래량'] = self._get_comm_data(trcode, rqname, i, '장후거래량')
            temp['장후거래비중'] = self._get_comm_data(trcode, rqname, i, '장후거래비중')
            temp['합계3'] = self._get_comm_data(trcode, rqname, i, '합계3')
            temp['기간중거래량'] = self._get_comm_data(trcode, rqname, i, '기간중거래량')
            temp['체결강도'] = self._get_comm_data(trcode, rqname, i, '체결강도')
            temp['외인보유'] = self._get_comm_data(trcode, rqname, i, '외인보유')
            temp['외인비중'] = self._get_comm_data(trcode, rqname, i, '외인비중')
            temp['외인순매수'] = self._get_comm_data(trcode, rqname, i, '외인순매수')
            temp['기관순매수'] = self._get_comm_data(trcode, rqname, i, '기관순매수')
            temp['개인순매수'] = self._get_comm_data(trcode, rqname, i, '개인순매수')
            temp['외국계'] = self._get_comm_data(trcode, rqname, i, '외국계')
            temp['신용잔고율'] = self._get_comm_data(trcode, rqname, i, '신용잔고율')
            temp['프로그램'] = self._get_comm_data(trcode, rqname, i, '프로그램')
            temp['장전거래대금'] = self._get_comm_data(trcode, rqname, i, '장전거래대금')
            temp['장전거래대금비중'] = self._get_comm_data(trcode, rqname, i, '장전거래대금비중')
            temp['장중거래대금'] = self._get_comm_data(trcode, rqname, i, '장중거래대금')
            temp['장중거래대금비중'] = self._get_comm_data(trcode, rqname, i, '장중거래대금비중')
            temp['장후거래대금'] = self._get_comm_data(trcode, rqname, i, '장후거래대금')
            temp['장후거래대금비중'] = self._get_comm_data(trcode, rqname, i, '장후거래대금비중')
            self.opt10015_output['multi'].append(temp)

    def _opt10016(self, rqname, trcode):
        """
    	신고저가요청
    	"""
        self.opt10016_output = {'multi': []}

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['종목코드'] = self._get_comm_data(trcode, rqname, i, '종목코드')
            temp['종목명'] = self._get_comm_data(trcode, rqname, i, '종목명')
            temp['현재가'] = self._get_comm_data(trcode, rqname, i, '현재가')
            temp['전일대비기호'] = self._get_comm_data(trcode, rqname, i, '전일대비기호')
            temp['전일대비'] = self._get_comm_data(trcode, rqname, i, '전일대비')
            temp['등락률'] = self._get_comm_data(trcode, rqname, i, '등락률')
            temp['거래량'] = self._get_comm_data(trcode, rqname, i, '거래량')
            temp['전일거래량대비율'] = self._get_comm_data(trcode, rqname, i, '전일거래량대비율')
            temp['매도호가'] = self._get_comm_data(trcode, rqname, i, '매도호가')
            temp['매수호가'] = self._get_comm_data(trcode, rqname, i, '매수호가')
            temp['고가'] = self._get_comm_data(trcode, rqname, i, '고가')
            temp['저가'] = self._get_comm_data(trcode, rqname, i, '저가')
            self.opt10016_output['multi'].append(temp)

    def _opt10017(self, rqname, trcode):
        """
    	상하한가요청
    	"""
        self.opt10017_output = {'multi': []}

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['종목코드'] = self._get_comm_data(trcode, rqname, i, '종목코드')
            temp['종목정보'] = self._get_comm_data(trcode, rqname, i, '종목정보')
            temp['종목명'] = self._get_comm_data(trcode, rqname, i, '종목명')
            temp['현재가'] = self._get_comm_data(trcode, rqname, i, '현재가')
            temp['전일대비기호'] = self._get_comm_data(trcode, rqname, i, '전일대비기호')
            temp['전일대비'] = self._get_comm_data(trcode, rqname, i, '전일대비')
            temp['등락률'] = self._get_comm_data(trcode, rqname, i, '등락률')
            temp['거래량'] = self._get_comm_data(trcode, rqname, i, '거래량')
            temp['전일거래량'] = self._get_comm_data(trcode, rqname, i, '전일거래량')
            temp['매도잔량'] = self._get_comm_data(trcode, rqname, i, '매도잔량')
            temp['매도호가'] = self._get_comm_data(trcode, rqname, i, '매도호가')
            temp['매수호가'] = self._get_comm_data(trcode, rqname, i, '매수호가')
            temp['매수잔량'] = self._get_comm_data(trcode, rqname, i, '매수잔량')
            temp['횟수'] = self._get_comm_data(trcode, rqname, i, '횟수')
            self.opt10017_output['multi'].append(temp)

    def _opt10018(self, rqname, trcode):
        """
    	고저가근접요청
    	"""
        self.opt10018_output = {'multi': []}

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['종목코드'] = self._get_comm_data(trcode, rqname, i, '종목코드')
            temp['종목명'] = self._get_comm_data(trcode, rqname, i, '종목명')
            temp['현재가'] = self._get_comm_data(trcode, rqname, i, '현재가')
            temp['전일대비기호'] = self._get_comm_data(trcode, rqname, i, '전일대비기호')
            temp['전일대비'] = self._get_comm_data(trcode, rqname, i, '전일대비')
            temp['등락률'] = self._get_comm_data(trcode, rqname, i, '등락률')
            temp['거래량'] = self._get_comm_data(trcode, rqname, i, '거래량')
            temp['매도호가'] = self._get_comm_data(trcode, rqname, i, '매도호가')
            temp['매수호가'] = self._get_comm_data(trcode, rqname, i, '매수호가')
            temp['당일고가'] = self._get_comm_data(trcode, rqname, i, '당일고가')
            temp['당일저가'] = self._get_comm_data(trcode, rqname, i, '당일저가')
            self.opt10018_output['multi'].append(temp)

    def _opt10019(self, rqname, trcode):
        """
    	가격급등락요청
    	"""
        self.opt10019_output = {'multi': []}

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['종목코드'] = self._get_comm_data(trcode, rqname, i, '종목코드')
            temp['종목분류'] = self._get_comm_data(trcode, rqname, i, '종목분류')
            temp['종목명'] = self._get_comm_data(trcode, rqname, i, '종목명')
            temp['전일대비기호'] = self._get_comm_data(trcode, rqname, i, '전일대비기호')
            temp['전일대비'] = self._get_comm_data(trcode, rqname, i, '전일대비')
            temp['등락률'] = self._get_comm_data(trcode, rqname, i, '등락률')
            temp['기준가'] = self._get_comm_data(trcode, rqname, i, '기준가')
            temp['현재가'] = self._get_comm_data(trcode, rqname, i, '현재가')
            temp['기준대비'] = self._get_comm_data(trcode, rqname, i, '기준대비')
            temp['거래량'] = self._get_comm_data(trcode, rqname, i, '거래량')
            temp['급등률'] = self._get_comm_data(trcode, rqname, i, '급등률')
            self.opt10019_output['multi'].append(temp)

    def _opt10020(self, rqname, trcode):
        """
    	호가잔량상위요청
    	"""
        self.opt10020_output = {'multi': []}

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['종목코드'] = self._get_comm_data(trcode, rqname, i, '종목코드')
            temp['종목명'] = self._get_comm_data(trcode, rqname, i, '종목명')
            temp['현재가'] = self._get_comm_data(trcode, rqname, i, '현재가')
            temp['전일대비기호'] = self._get_comm_data(trcode, rqname, i, '전일대비기호')
            temp['전일대비'] = self._get_comm_data(trcode, rqname, i, '전일대비')
            temp['거래량'] = self._get_comm_data(trcode, rqname, i, '거래량')
            temp['총매도잔량'] = self._get_comm_data(trcode, rqname, i, '총매도잔량')
            temp['총매수잔량'] = self._get_comm_data(trcode, rqname, i, '총매수잔량')
            temp['순매수잔량'] = self._get_comm_data(trcode, rqname, i, '순매수잔량')
            temp['매수비율'] = self._get_comm_data(trcode, rqname, i, '매수비율')
            self.opt10020_output['multi'].append(temp)

    def _opt10021(self, rqname, trcode):
        """
    	호가잔량급증요청
    	"""
        self.opt10021_output = {'multi': []}

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['종목코드'] = self._get_comm_data(trcode, rqname, i, '종목코드')
            temp['종목명'] = self._get_comm_data(trcode, rqname, i, '종목명')
            temp['현재가'] = self._get_comm_data(trcode, rqname, i, '현재가')
            temp['전일대비기호'] = self._get_comm_data(trcode, rqname, i, '전일대비기호')
            temp['전일대비'] = self._get_comm_data(trcode, rqname, i, '전일대비')
            temp['기준률'] = self._get_comm_data(trcode, rqname, i, '기준률')
            temp['현재'] = self._get_comm_data(trcode, rqname, i, '현재')
            temp['급증수량'] = self._get_comm_data(trcode, rqname, i, '급증수량')
            temp['급증률'] = self._get_comm_data(trcode, rqname, i, '급증률')
            temp['총매수량'] = self._get_comm_data(trcode, rqname, i, '총매수량')
            self.opt10021_output['multi'].append(temp)

    def _opt10022(self, rqname, trcode):
        """
    	잔량율급증요청
    	"""
        self.opt10022_output = {'multi': []}

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['종목코드'] = self._get_comm_data(trcode, rqname, i, '종목코드')
            temp['종목명'] = self._get_comm_data(trcode, rqname, i, '종목명')
            temp['현재가'] = self._get_comm_data(trcode, rqname, i, '현재가')
            temp['전일대비기호'] = self._get_comm_data(trcode, rqname, i, '전일대비기호')
            temp['전일대비'] = self._get_comm_data(trcode, rqname, i, '전일대비')
            temp['기준률'] = self._get_comm_data(trcode, rqname, i, '기준률')
            temp['현재비율'] = self._get_comm_data(trcode, rqname, i, '현재비율')
            temp['급증률'] = self._get_comm_data(trcode, rqname, i, '급증률')
            temp['총매도잔량'] = self._get_comm_data(trcode, rqname, i, '총매도잔량')
            temp['총매수잔량'] = self._get_comm_data(trcode, rqname, i, '총매수잔량')
            self.opt10022_output['multi'].append(temp)

    def _opt10023(self, rqname, trcode):
        """
    	거래량급증요청
    	"""
        self.opt10023_output = {'multi': []}

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['종목코드'] = self._get_comm_data(trcode, rqname, i, '종목코드')
            temp['종목명'] = self._get_comm_data(trcode, rqname, i, '종목명')
            temp['현재가'] = self._get_comm_data(trcode, rqname, i, '현재가')
            temp['전일대비기호'] = self._get_comm_data(trcode, rqname, i, '전일대비기호')
            temp['전일대비'] = self._get_comm_data(trcode, rqname, i, '전일대비')
            temp['등락률'] = self._get_comm_data(trcode, rqname, i, '등락률')
            temp['이전거래량'] = self._get_comm_data(trcode, rqname, i, '이전거래량')
            temp['현재거래량'] = self._get_comm_data(trcode, rqname, i, '현재거래량')
            temp['급증량'] = self._get_comm_data(trcode, rqname, i, '급증량')
            temp['급증률'] = self._get_comm_data(trcode, rqname, i, '급증률')
            self.opt10023_output['multi'].append(temp)

    def _opt10024(self, rqname, trcode):
        """
    	거래량갱신요청
    	"""
        self.opt10024_output = {'multi': []}

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['종목코드'] = self._get_comm_data(trcode, rqname, i, '종목코드')
            temp['종목명'] = self._get_comm_data(trcode, rqname, i, '종목명')
            temp['현재가'] = self._get_comm_data(trcode, rqname, i, '현재가')
            temp['전일대비기호'] = self._get_comm_data(trcode, rqname, i, '전일대비기호')
            temp['전일대비'] = self._get_comm_data(trcode, rqname, i, '전일대비')
            temp['등락률'] = self._get_comm_data(trcode, rqname, i, '등락률')
            temp['이전거래량'] = self._get_comm_data(trcode, rqname, i, '이전거래량')
            temp['현재거래량'] = self._get_comm_data(trcode, rqname, i, '현재거래량')
            temp['매도호가'] = self._get_comm_data(trcode, rqname, i, '매도호가')
            temp['매수호가'] = self._get_comm_data(trcode, rqname, i, '매수호가')
            self.opt10024_output['multi'].append(temp)

    def _opt10025(self, rqname, trcode):
        """
    	매물대집중요청
    	"""
        self.opt10025_output = {'multi': []}

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['종목코드'] = self._get_comm_data(trcode, rqname, i, '종목코드')
            temp['종목명'] = self._get_comm_data(trcode, rqname, i, '종목명')
            temp['현재가'] = self._get_comm_data(trcode, rqname, i, '현재가')
            temp['전일대비기호'] = self._get_comm_data(trcode, rqname, i, '전일대비기호')
            temp['전일대비'] = self._get_comm_data(trcode, rqname, i, '전일대비')
            temp['등락률'] = self._get_comm_data(trcode, rqname, i, '등락률')
            temp['현재거래량'] = self._get_comm_data(trcode, rqname, i, '현재거래량')
            temp['가격대시작'] = self._get_comm_data(trcode, rqname, i, '가격대시작')
            temp['가격대끝'] = self._get_comm_data(trcode, rqname, i, '가격대끝')
            temp['매물량'] = self._get_comm_data(trcode, rqname, i, '매물량')
            temp['매물비'] = self._get_comm_data(trcode, rqname, i, '매물비')
            self.opt10025_output['multi'].append(temp)

    def _opt10026(self, rqname, trcode):
        """
    	고저PER요청
    	"""
        self.opt10026_output = {'multi': []}

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['종목코드'] = self._get_comm_data(trcode, rqname, i, '종목코드')
            temp['종목명'] = self._get_comm_data(trcode, rqname, i, '종목명')
            temp['PER'] = self._get_comm_data(trcode, rqname, i, 'PER')
            temp['현재가'] = self._get_comm_data(trcode, rqname, i, '현재가')
            temp['전일대비기호'] = self._get_comm_data(trcode, rqname, i, '전일대비기호')
            temp['전일대비'] = self._get_comm_data(trcode, rqname, i, '전일대비')
            temp['등락률'] = self._get_comm_data(trcode, rqname, i, '등락률')
            temp['현재거래량'] = self._get_comm_data(trcode, rqname, i, '현재거래량')
            temp['매도호가'] = self._get_comm_data(trcode, rqname, i, '매도호가')
            self.opt10026_output['multi'].append(temp)

    def _opt10027(self, rqname, trcode):
        """
    	전일대비등락률상위요청
    	"""
        self.opt10027_output = {'multi': []}

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['종목분류'] = self._get_comm_data(trcode, rqname, i, '종목분류')
            temp['종목코드'] = self._get_comm_data(trcode, rqname, i, '종목코드')
            temp['종목명'] = self._get_comm_data(trcode, rqname, i, '종목명')
            temp['현재가'] = self._get_comm_data(trcode, rqname, i, '현재가')
            temp['전일대비기호'] = self._get_comm_data(trcode, rqname, i, '전일대비기호')
            temp['전일대비'] = self._get_comm_data(trcode, rqname, i, '전일대비')
            temp['등락률'] = self._get_comm_data(trcode, rqname, i, '등락률')
            temp['매도잔량'] = self._get_comm_data(trcode, rqname, i, '매도잔량')
            temp['매수잔량'] = self._get_comm_data(trcode, rqname, i, '매수잔량')
            temp['현재거래량'] = self._get_comm_data(trcode, rqname, i, '현재거래량')
            temp['체결강도'] = self._get_comm_data(trcode, rqname, i, '체결강도')
            temp['횟수'] = self._get_comm_data(trcode, rqname, i, '횟수')
            self.opt10027_output['multi'].append(temp)

    def _opt10028(self, rqname, trcode):
        """
    	시가대비등락률요청
    	"""
        self.opt10028_output = {'multi': []}

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['종목코드'] = self._get_comm_data(trcode, rqname, i, '종목코드')
            temp['종목명'] = self._get_comm_data(trcode, rqname, i, '종목명')
            temp['현재가'] = self._get_comm_data(trcode, rqname, i, '현재가')
            temp['전일대비기호'] = self._get_comm_data(trcode, rqname, i, '전일대비기호')
            temp['전일대비'] = self._get_comm_data(trcode, rqname, i, '전일대비')
            temp['등락률'] = self._get_comm_data(trcode, rqname, i, '등락률')
            temp['시가'] = self._get_comm_data(trcode, rqname, i, '시가')
            temp['고가'] = self._get_comm_data(trcode, rqname, i, '고가')
            temp['저가'] = self._get_comm_data(trcode, rqname, i, '저가')
            temp['시가대비'] = self._get_comm_data(trcode, rqname, i, '시가대비')
            temp['현재거래량'] = self._get_comm_data(trcode, rqname, i, '현재거래량')
            temp['체결강도'] = self._get_comm_data(trcode, rqname, i, '체결강도')
            self.opt10028_output['multi'].append(temp)

    def _opt10029(self, rqname, trcode):
        """
    	예상체결등락률상위요청
    	"""
        self.opt10029_output = {'multi': []}

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['종목코드'] = self._get_comm_data(trcode, rqname, i, '종목코드')
            temp['종목명'] = self._get_comm_data(trcode, rqname, i, '종목명')
            temp['예상체결가'] = self._get_comm_data(trcode, rqname, i, '예상체결가')
            temp['기준가'] = self._get_comm_data(trcode, rqname, i, '기준가')
            temp['전일대비기호'] = self._get_comm_data(trcode, rqname, i, '전일대비기호')
            temp['전일대비'] = self._get_comm_data(trcode, rqname, i, '전일대비')
            temp['등락률'] = self._get_comm_data(trcode, rqname, i, '등락률')
            temp['예상체결량'] = self._get_comm_data(trcode, rqname, i, '예상체결량')
            temp['매도잔량'] = self._get_comm_data(trcode, rqname, i, '매도잔량')
            temp['매도호가'] = self._get_comm_data(trcode, rqname, i, '매도호가')
            temp['매수호가'] = self._get_comm_data(trcode, rqname, i, '매수호가')
            temp['매수잔량'] = self._get_comm_data(trcode, rqname, i, '매수잔량')
            self.opt10029_output['multi'].append(temp)

    def _opt10030(self, rqname, trcode):
        """
    	당일거래량상위요청
    	"""
        self.opt10030_output = {'multi': []}

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['종목코드'] = self._get_comm_data(trcode, rqname, i, '종목코드')
            temp['종목명'] = self._get_comm_data(trcode, rqname, i, '종목명')
            temp['현재가'] = self._get_comm_data(trcode, rqname, i, '현재가')
            temp['전일대비기호'] = self._get_comm_data(trcode, rqname, i, '전일대비기호')
            temp['전일대비'] = self._get_comm_data(trcode, rqname, i, '전일대비')
            temp['등락률'] = self._get_comm_data(trcode, rqname, i, '등락률')
            temp['거래량'] = self._get_comm_data(trcode, rqname, i, '거래량')
            temp['전일비'] = self._get_comm_data(trcode, rqname, i, '전일비')
            temp['거래회전율'] = self._get_comm_data(trcode, rqname, i, '거래회전율')
            temp['거래금액'] = self._get_comm_data(trcode, rqname, i, '거래금액')
            self.opt10030_output['multi'].append(temp)

    def _opt10031(self, rqname, trcode):
        """
    	전일거래량상위요청
    	"""
        self.opt10031_output = {'multi': []}

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['종목코드'] = self._get_comm_data(trcode, rqname, i, '종목코드')
            temp['종목명'] = self._get_comm_data(trcode, rqname, i, '종목명')
            temp['현재가'] = self._get_comm_data(trcode, rqname, i, '현재가')
            temp['전일대비기호'] = self._get_comm_data(trcode, rqname, i, '전일대비기호')
            temp['전일대비'] = self._get_comm_data(trcode, rqname, i, '전일대비')
            temp['거래량'] = self._get_comm_data(trcode, rqname, i, '거래량')
            self.opt10031_output['multi'].append(temp)

    def _opt10032(self, rqname, trcode):
        """
    	거래대금상위요청
    	"""
        self.opt10032_output = {'multi': []}

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['종목코드'] = self._get_comm_data(trcode, rqname, i, '종목코드')
            temp['현재순위'] = self._get_comm_data(trcode, rqname, i, '현재순위')
            temp['전일순위'] = self._get_comm_data(trcode, rqname, i, '전일순위')
            temp['종목명'] = self._get_comm_data(trcode, rqname, i, '종목명')
            temp['현재가'] = self._get_comm_data(trcode, rqname, i, '현재가')
            temp['전일대비기호'] = self._get_comm_data(trcode, rqname, i, '전일대비기호')
            temp['전일대비'] = self._get_comm_data(trcode, rqname, i, '전일대비')
            temp['등락률'] = self._get_comm_data(trcode, rqname, i, '등락률')
            temp['매도호가'] = self._get_comm_data(trcode, rqname, i, '매도호가')
            temp['매수호가'] = self._get_comm_data(trcode, rqname, i, '매수호가')
            temp['현재거래량'] = self._get_comm_data(trcode, rqname, i, '현재거래량')
            temp['전일거래량'] = self._get_comm_data(trcode, rqname, i, '전일거래량')
            temp['거래대금'] = self._get_comm_data(trcode, rqname, i, '거래대금')
            self.opt10032_output['multi'].append(temp)

    def _opt10033(self, rqname, trcode):
        """
    	신용비율상위요청
    	"""
        self.opt10033_output = {'multi': []}

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['종목정보'] = self._get_comm_data(trcode, rqname, i, '종목정보')
            temp['종목코드'] = self._get_comm_data(trcode, rqname, i, '종목코드')
            temp['종목명'] = self._get_comm_data(trcode, rqname, i, '종목명')
            temp['현재가'] = self._get_comm_data(trcode, rqname, i, '현재가')
            temp['전일대비기호'] = self._get_comm_data(trcode, rqname, i, '전일대비기호')
            temp['전일대비'] = self._get_comm_data(trcode, rqname, i, '전일대비')
            temp['등락률'] = self._get_comm_data(trcode, rqname, i, '등락률')
            temp['신용비율'] = self._get_comm_data(trcode, rqname, i, '신용비율')
            temp['매도잔량'] = self._get_comm_data(trcode, rqname, i, '매도잔량')
            temp['매수잔량'] = self._get_comm_data(trcode, rqname, i, '매수잔량')
            temp['현재거래량'] = self._get_comm_data(trcode, rqname, i, '현재거래량')
            self.opt10033_output['multi'].append(temp)

    def _opt10034(self, rqname, trcode):
        """
    	외인기간별매매상위요청
    	"""
        self.opt10034_output = {'multi': []}

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['순위'] = self._get_comm_data(trcode, rqname, i, '순위')
            temp['종목코드'] = self._get_comm_data(trcode, rqname, i, '종목코드')
            temp['종목명'] = self._get_comm_data(trcode, rqname, i, '종목명')
            temp['현재가'] = self._get_comm_data(trcode, rqname, i, '현재가')
            temp['전일대비기호'] = self._get_comm_data(trcode, rqname, i, '전일대비기호')
            temp['전일대비'] = self._get_comm_data(trcode, rqname, i, '전일대비')
            temp['매도호가'] = self._get_comm_data(trcode, rqname, i, '매도호가')
            temp['매수호가'] = self._get_comm_data(trcode, rqname, i, '매수호가')
            temp['거래량'] = self._get_comm_data(trcode, rqname, i, '거래량')
            temp['순매수량'] = self._get_comm_data(trcode, rqname, i, '순매수량')
            temp['취득가능주식수'] = self._get_comm_data(trcode, rqname, i, '취득가능주식수')
            self.opt10034_output['multi'].append(temp)

    def _opt10035(self, rqname, trcode):
        """
    	외인연속순매매상위요청
    	"""
        self.opt10035_output = {'multi': []}

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['종목코드'] = self._get_comm_data(trcode, rqname, i, '종목코드')
            temp['종목명'] = self._get_comm_data(trcode, rqname, i, '종목명')
            temp['현재가'] = self._get_comm_data(trcode, rqname, i, '현재가')
            temp['전일대비기호'] = self._get_comm_data(trcode, rqname, i, '전일대비기호')
            temp['전일대비'] = self._get_comm_data(trcode, rqname, i, '전일대비')
            temp['D-1'] = self._get_comm_data(trcode, rqname, i, 'D-1')
            temp['D-2'] = self._get_comm_data(trcode, rqname, i, 'D-2')
            temp['D-3'] = self._get_comm_data(trcode, rqname, i, 'D-3')
            temp['합계'] = self._get_comm_data(trcode, rqname, i, '합계')
            temp['한도소진율'] = self._get_comm_data(trcode, rqname, i, '한도소진율')
            temp['전일대비1'] = self._get_comm_data(trcode, rqname, i, '전일대비1')
            temp['전일대비2'] = self._get_comm_data(trcode, rqname, i, '전일대비2')
            temp['전일대비3'] = self._get_comm_data(trcode, rqname, i, '전일대비3')
            self.opt10035_output['multi'].append(temp)

    def _opt10036(self, rqname, trcode):
        """
    	매매상위요청
    	"""
        self.opt10036_output = {'multi': []}

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['순위'] = self._get_comm_data(trcode, rqname, i, '순위')
            temp['종목코드'] = self._get_comm_data(trcode, rqname, i, '종목코드')
            temp['종목명'] = self._get_comm_data(trcode, rqname, i, '종목명')
            temp['현재가'] = self._get_comm_data(trcode, rqname, i, '현재가')
            temp['전일대비기호'] = self._get_comm_data(trcode, rqname, i, '전일대비기호')
            temp['전일대비'] = self._get_comm_data(trcode, rqname, i, '전일대비')
            temp['거래량'] = self._get_comm_data(trcode, rqname, i, '거래량')
            temp['보유주식수'] = self._get_comm_data(trcode, rqname, i, '보유주식수')
            temp['취득가능주식수'] = self._get_comm_data(trcode, rqname, i, '취득가능주식수')
            temp['기준한도소진율'] = self._get_comm_data(trcode, rqname, i, '기준한도소진율')
            temp['한도소진율'] = self._get_comm_data(trcode, rqname, i, '한도소진율')
            temp['소진율증가'] = self._get_comm_data(trcode, rqname, i, '소진율증가')
            self.opt10036_output['multi'].append(temp)

    def _opt10037(self, rqname, trcode):
        """
    	외국계창구매매상위요청
    	"""
        self.opt10037_output = {'multi': []}

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['순위'] = self._get_comm_data(trcode, rqname, i, '순위')
            temp['종목코드'] = self._get_comm_data(trcode, rqname, i, '종목코드')
            temp['종목명'] = self._get_comm_data(trcode, rqname, i, '종목명')
            temp['현재가'] = self._get_comm_data(trcode, rqname, i, '현재가')
            temp['전일대비기호'] = self._get_comm_data(trcode, rqname, i, '전일대비기호')
            temp['전일대비'] = self._get_comm_data(trcode, rqname, i, '전일대비')
            temp['등락율'] = self._get_comm_data(trcode, rqname, i, '등락율')
            temp['매도거래량'] = self._get_comm_data(trcode, rqname, i, '매도거래량')
            temp['매수거래량'] = self._get_comm_data(trcode, rqname, i, '매수거래량')
            temp['순매수거래량'] = self._get_comm_data(trcode, rqname, i, '순매수거래량')
            temp['순매수대금'] = self._get_comm_data(trcode, rqname, i, '순매수대금')
            temp['거래량'] = self._get_comm_data(trcode, rqname, i, '거래량')
            temp['거래대금'] = self._get_comm_data(trcode, rqname, i, '거래대금')
            self.opt10037_output['multi'].append(temp)

    def _opt10038(self, rqname, trcode):
        """
    	종목별증권사순위요청
    	"""
        self.opt10038_output = {'single': dict(), 'multi': []}

        self.opt10038_output['single']['순위1'] = self._get_comm_data(trcode, rqname, 0, '순위1')
        self.opt10038_output['single']['순위2'] = self._get_comm_data(trcode, rqname, 0, '순위2')
        self.opt10038_output['single']['순위3'] = self._get_comm_data(trcode, rqname, 0, '순위3')
        self.opt10038_output['single']['기간중거래량'] = self._get_comm_data(trcode, rqname, 0, '기간중거래량')

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['순위'] = self._get_comm_data(trcode, rqname, i, '순위')
            temp['회원사명'] = self._get_comm_data(trcode, rqname, i, '회원사명')
            temp['매수수량'] = self._get_comm_data(trcode, rqname, i, '매수수량')
            temp['매도수량'] = self._get_comm_data(trcode, rqname, i, '매도수량')
            temp['누적순매수수량'] = self._get_comm_data(trcode, rqname, i, '누적순매수수량')
            self.opt10038_output['multi'].append(temp)

    def _opt10039(self, rqname, trcode):
        """
    	증권사별매매상위요청
    	"""
        self.opt10039_output = {'multi': []}

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['순위'] = self._get_comm_data(trcode, rqname, i, '순위')
            temp['종목코드'] = self._get_comm_data(trcode, rqname, i, '종목코드')
            temp['종목명'] = self._get_comm_data(trcode, rqname, i, '종목명')
            temp['기간중주가등락'] = self._get_comm_data(trcode, rqname, i, '기간중주가등락')
            temp['등락율'] = self._get_comm_data(trcode, rqname, i, '등락율')
            temp['기간중거래량'] = self._get_comm_data(trcode, rqname, i, '기간중거래량')
            temp['순매수'] = self._get_comm_data(trcode, rqname, i, '순매수')
            temp['매수거래량'] = self._get_comm_data(trcode, rqname, i, '매수거래량')
            temp['매도거래량'] = self._get_comm_data(trcode, rqname, i, '매도거래량')
            self.opt10039_output['multi'].append(temp)

    def _opt10040(self, rqname, trcode):
        """
    	당일주요거래원요청
    	"""
        self.opt10040_output = {'single': dict(), 'multi': []}

        self.opt10040_output['single']['매도거래원별증감1'] = self._get_comm_data(trcode, rqname, 0, '매도거래원별증감1')
        self.opt10040_output['single']['매도거래원수량1'] = self._get_comm_data(trcode, rqname, 0, '매도거래원수량1')
        self.opt10040_output['single']['매도거래원1'] = self._get_comm_data(trcode, rqname, 0, '매도거래원1')
        self.opt10040_output['single']['매도거래원코드1'] = self._get_comm_data(trcode, rqname, 0, '매도거래원코드1')
        self.opt10040_output['single']['매수거래원1'] = self._get_comm_data(trcode, rqname, 0, '매수거래원1')
        self.opt10040_output['single']['매수거래원코드1'] = self._get_comm_data(trcode, rqname, 0, '매수거래원코드1')
        self.opt10040_output['single']['매수거래원수량1'] = self._get_comm_data(trcode, rqname, 0, '매수거래원수량1')
        self.opt10040_output['single']['매수거래원별증감1'] = self._get_comm_data(trcode, rqname, 0, '매수거래원별증감1')
        self.opt10040_output['single']['매도거래원별증감2'] = self._get_comm_data(trcode, rqname, 0, '매도거래원별증감2')
        self.opt10040_output['single']['매도거래원수량2'] = self._get_comm_data(trcode, rqname, 0, '매도거래원수량2')
        self.opt10040_output['single']['매도거래원2'] = self._get_comm_data(trcode, rqname, 0, '매도거래원2')
        self.opt10040_output['single']['매도거래원코드2'] = self._get_comm_data(trcode, rqname, 0, '매도거래원코드2')
        self.opt10040_output['single']['매수거래원2'] = self._get_comm_data(trcode, rqname, 0, '매수거래원2')
        self.opt10040_output['single']['매수거래원코드2'] = self._get_comm_data(trcode, rqname, 0, '매수거래원코드2')
        self.opt10040_output['single']['매수거래원수량2'] = self._get_comm_data(trcode, rqname, 0, '매수거래원수량2')
        self.opt10040_output['single']['매수거래원별증감2'] = self._get_comm_data(trcode, rqname, 0, '매수거래원별증감2')
        self.opt10040_output['single']['매도거래원별증감3'] = self._get_comm_data(trcode, rqname, 0, '매도거래원별증감3')
        self.opt10040_output['single']['매도거래원수량3'] = self._get_comm_data(trcode, rqname, 0, '매도거래원수량3')
        self.opt10040_output['single']['매도거래원3'] = self._get_comm_data(trcode, rqname, 0, '매도거래원3')
        self.opt10040_output['single']['매도거래원코드3'] = self._get_comm_data(trcode, rqname, 0, '매도거래원코드3')
        self.opt10040_output['single']['매수거래원3'] = self._get_comm_data(trcode, rqname, 0, '매수거래원3')
        self.opt10040_output['single']['매수거래원코드3'] = self._get_comm_data(trcode, rqname, 0, '매수거래원코드3')
        self.opt10040_output['single']['매수거래원수량3'] = self._get_comm_data(trcode, rqname, 0, '매수거래원수량3')
        self.opt10040_output['single']['매수거래원별증감3'] = self._get_comm_data(trcode, rqname, 0, '매수거래원별증감3')
        self.opt10040_output['single']['매도거래원별증감4'] = self._get_comm_data(trcode, rqname, 0, '매도거래원별증감4')
        self.opt10040_output['single']['매도거래원수량4'] = self._get_comm_data(trcode, rqname, 0, '매도거래원수량4')
        self.opt10040_output['single']['매도거래원4'] = self._get_comm_data(trcode, rqname, 0, '매도거래원4')
        self.opt10040_output['single']['매도거래원코드4'] = self._get_comm_data(trcode, rqname, 0, '매도거래원코드4')
        self.opt10040_output['single']['매수거래원4'] = self._get_comm_data(trcode, rqname, 0, '매수거래원4')
        self.opt10040_output['single']['매수거래원코드4'] = self._get_comm_data(trcode, rqname, 0, '매수거래원코드4')
        self.opt10040_output['single']['매수거래원수량4'] = self._get_comm_data(trcode, rqname, 0, '매수거래원수량4')
        self.opt10040_output['single']['매수거래원별증감4'] = self._get_comm_data(trcode, rqname, 0, '매수거래원별증감4')
        self.opt10040_output['single']['매도거래원별증감5'] = self._get_comm_data(trcode, rqname, 0, '매도거래원별증감5')
        self.opt10040_output['single']['매도거래원수량5'] = self._get_comm_data(trcode, rqname, 0, '매도거래원수량5')
        self.opt10040_output['single']['매도거래원5'] = self._get_comm_data(trcode, rqname, 0, '매도거래원5')
        self.opt10040_output['single']['매도거래원코드5'] = self._get_comm_data(trcode, rqname, 0, '매도거래원코드5')
        self.opt10040_output['single']['매수거래원5'] = self._get_comm_data(trcode, rqname, 0, '매수거래원5')
        self.opt10040_output['single']['매수거래원코드5'] = self._get_comm_data(trcode, rqname, 0, '매수거래원코드5')
        self.opt10040_output['single']['매수거래원수량5'] = self._get_comm_data(trcode, rqname, 0, '매수거래원수량5')
        self.opt10040_output['single']['매수거래원별증감5'] = self._get_comm_data(trcode, rqname, 0, '매수거래원별증감5')
        self.opt10040_output['single']['외국계매도추정합변동'] = self._get_comm_data(trcode, rqname, 0, '외국계매도추정합변동')
        self.opt10040_output['single']['외국계매도추정합'] = self._get_comm_data(trcode, rqname, 0, '외국계매도추정합')
        self.opt10040_output['single']['외국계매수추정합'] = self._get_comm_data(trcode, rqname, 0, '외국계매수추정합')
        self.opt10040_output['single']['외국계매수추정합변동'] = self._get_comm_data(trcode, rqname, 0, '외국계매수추정합변동')

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['매도이탈시간'] = self._get_comm_data(trcode, rqname, i, '매도이탈시간')
            temp['매도수량'] = self._get_comm_data(trcode, rqname, i, '매도수량')
            temp['매도상위이탈원'] = self._get_comm_data(trcode, rqname, i, '매도상위이탈원')
            temp['매수이탈시간'] = self._get_comm_data(trcode, rqname, i, '매수이탈시간')
            temp['매수수량'] = self._get_comm_data(trcode, rqname, i, '매수수량')
            temp['매수상위이탈원'] = self._get_comm_data(trcode, rqname, i, '매수상위이탈원')
            temp['조회일자'] = self._get_comm_data(trcode, rqname, i, '조회일자')
            temp['조회시간'] = self._get_comm_data(trcode, rqname, i, '조회시간')
            self.opt10040_output['multi'].append(temp)

    def _opt10041(self, rqname, trcode):
        """
    	조기종료통화단위요청
    	"""
        self.opt10041_output = {'multi': []}

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['조기종료여부'] = self._get_comm_data(trcode, rqname, i, '조기종료여부')
            temp['통화단위'] = self._get_comm_data(trcode, rqname, i, '통화단위')
            self.opt10041_output['multi'].append(temp)

    def _opt10042(self, rqname, trcode):
        """
    	순매수거래원순위요청
    	"""
        self.opt10042_output = {'multi': []}

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['순위'] = self._get_comm_data(trcode, rqname, i, '순위')
            temp['회원사코드'] = self._get_comm_data(trcode, rqname, i, '회원사코드')
            temp['회원사명'] = self._get_comm_data(trcode, rqname, i, '회원사명')
            self.opt10042_output['multi'].append(temp)

    def _opt10043(self, rqname, trcode):
        """
    	거래원매물대분석요청
    	"""
        self.opt10043_output = {'multi': []}

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['일자'] = self._get_comm_data(trcode, rqname, i, '일자')
            temp['종가'] = self._get_comm_data(trcode, rqname, i, '종가')
            temp['대비기호'] = self._get_comm_data(trcode, rqname, i, '대비기호')
            temp['전일대비'] = self._get_comm_data(trcode, rqname, i, '전일대비')
            temp['매도량'] = self._get_comm_data(trcode, rqname, i, '매도량')
            temp['매수량'] = self._get_comm_data(trcode, rqname, i, '매수량')
            temp['순매수수량'] = self._get_comm_data(trcode, rqname, i, '순매수수량')
            temp['거래량합'] = self._get_comm_data(trcode, rqname, i, '거래량합')
            temp['거래비중'] = self._get_comm_data(trcode, rqname, i, '거래비중')
            self.opt10043_output['multi'].append(temp)

    def _opt10044(self, rqname, trcode):
        """
    	일별기관매매종목요청
    	"""
        self.opt10044_output = {'multi': []}

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['종목코드'] = self._get_comm_data(trcode, rqname, i, '종목코드')
            temp['종목명'] = self._get_comm_data(trcode, rqname, i, '종목명')
            temp['순매수수량'] = self._get_comm_data(trcode, rqname, i, '순매수수량')
            temp['순매수금액'] = self._get_comm_data(trcode, rqname, i, '순매수금액')
            temp['추정평균가'] = self._get_comm_data(trcode, rqname, i, '추정평균가')
            temp['현재가'] = self._get_comm_data(trcode, rqname, i, '현재가')
            temp['평균가대비'] = self._get_comm_data(trcode, rqname, i, '평균가대비')
            temp['대비율'] = self._get_comm_data(trcode, rqname, i, '대비율')
            self.opt10044_output['multi'].append(temp)

    def _opt10045(self, rqname, trcode):
        """
    	종목별기관매매추이요청
    	"""
        self.opt10045_output = {'single': dict(), 'multi': []}

        self.opt10045_output['single']['기관추정평균가'] = self._get_comm_data(trcode, rqname, 0, '기관추정평균가')
        self.opt10045_output['single']['외인추정평균가'] = self._get_comm_data(trcode, rqname, 0, '외인추정평균가')

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['일자'] = self._get_comm_data(trcode, rqname, i, '일자')
            temp['종가'] = self._get_comm_data(trcode, rqname, i, '종가')
            temp['대비기호'] = self._get_comm_data(trcode, rqname, i, '대비기호')
            temp['전일대비'] = self._get_comm_data(trcode, rqname, i, '전일대비')
            temp['등락율'] = self._get_comm_data(trcode, rqname, i, '등락율')
            temp['거래량'] = self._get_comm_data(trcode, rqname, i, '거래량')
            temp['기관기간누적'] = self._get_comm_data(trcode, rqname, i, '기관기간누적')
            temp['기관일별순매매수량'] = self._get_comm_data(trcode, rqname, i, '기관일별순매매수량')
            temp['외인기간누적'] = self._get_comm_data(trcode, rqname, i, '외인기간누적')
            temp['외인일별순매매수량'] = self._get_comm_data(trcode, rqname, i, '외인일별순매매수량')
            temp['한도소진율'] = self._get_comm_data(trcode, rqname, i, '한도소진율')
            self.opt10045_output['multi'].append(temp)

    def _opt10048(self, rqname, trcode):
        """
    	ELW일별민감도지표요청
    	"""
        self.opt10048_output = {'multi': []}

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['일자'] = self._get_comm_data(trcode, rqname, i, '일자')
            temp['IV'] = self._get_comm_data(trcode, rqname, i, 'IV')
            temp['델타'] = self._get_comm_data(trcode, rqname, i, '델타')
            temp['감마'] = self._get_comm_data(trcode, rqname, i, '감마')
            temp['쎄타'] = self._get_comm_data(trcode, rqname, i, '쎄타')
            temp['베가'] = self._get_comm_data(trcode, rqname, i, '베가')
            temp['로'] = self._get_comm_data(trcode, rqname, i, '로')
            temp['LP'] = self._get_comm_data(trcode, rqname, i, 'LP')
            self.opt10048_output['multi'].append(temp)

    def _opt10049(self, rqname, trcode):
        """
    	ELW투자지표요청
    	"""
        self.opt10049_output = {'single': dict(), 'multi': []}

        self.opt10049_output['single']['연속구분'] = self._get_comm_data(trcode, rqname, 0, '연속구분')
        self.opt10049_output['single']['연속키'] = self._get_comm_data(trcode, rqname, 0, '연속키')

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['시간'] = self._get_comm_data(trcode, rqname, i, '시간')
            temp['패리티'] = self._get_comm_data(trcode, rqname, i, '패리티')
            temp['프리미엄'] = self._get_comm_data(trcode, rqname, i, '프리미엄')
            temp['기어링비율'] = self._get_comm_data(trcode, rqname, i, '기어링비율')
            temp['손익분기율'] = self._get_comm_data(trcode, rqname, i, '손익분기율')
            temp['현재가'] = self._get_comm_data(trcode, rqname, i, '현재가')
            temp['레버리지'] = self._get_comm_data(trcode, rqname, i, '레버리지')
            self.opt10049_output['multi'].append(temp)

    def _opt10050(self, rqname, trcode):
        """
    	ELW민감도지표요청
    	"""
        self.opt10050_output = {'multi': []}

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['체결시간'] = self._get_comm_data(trcode, rqname, i, '체결시간')
            temp['현재가'] = self._get_comm_data(trcode, rqname, i, '현재가')
            temp['ELW이론가'] = self._get_comm_data(trcode, rqname, i, 'ELW이론가')
            temp['IV'] = self._get_comm_data(trcode, rqname, i, 'IV')
            temp['델타'] = self._get_comm_data(trcode, rqname, i, '델타')
            temp['감마'] = self._get_comm_data(trcode, rqname, i, '감마')
            temp['쎄타'] = self._get_comm_data(trcode, rqname, i, '쎄타')
            temp['베가'] = self._get_comm_data(trcode, rqname, i, '베가')
            temp['로'] = self._get_comm_data(trcode, rqname, i, '로')
            temp['LP'] = self._get_comm_data(trcode, rqname, i, 'LP')
            self.opt10050_output['multi'].append(temp)

    def _opt10051(self, rqname, trcode):
        """
    	업종별투자자순매수요청
    	"""
        self.opt10051_output = {'multi': []}

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['업종코드'] = self._get_comm_data(trcode, rqname, i, '업종코드')
            temp['업종명'] = self._get_comm_data(trcode, rqname, i, '업종명')
            temp['현재가'] = self._get_comm_data(trcode, rqname, i, '현재가')
            temp['대비부호'] = self._get_comm_data(trcode, rqname, i, '대비부호')
            temp['전일대비'] = self._get_comm_data(trcode, rqname, i, '전일대비')
            temp['등락율'] = self._get_comm_data(trcode, rqname, i, '등락율')
            temp['거래량'] = self._get_comm_data(trcode, rqname, i, '거래량')
            temp['증권순매수'] = self._get_comm_data(trcode, rqname, i, '증권순매수')
            temp['보험순매수'] = self._get_comm_data(trcode, rqname, i, '보험순매수')
            temp['투신순매수'] = self._get_comm_data(trcode, rqname, i, '투신순매수')
            temp['은행순매수'] = self._get_comm_data(trcode, rqname, i, '은행순매수')
            temp['종신금순매수'] = self._get_comm_data(trcode, rqname, i, '종신금순매수')
            temp['기금순매수'] = self._get_comm_data(trcode, rqname, i, '기금순매수')
            temp['기타법인순매수'] = self._get_comm_data(trcode, rqname, i, '기타법인순매수')
            temp['개인순매수'] = self._get_comm_data(trcode, rqname, i, '개인순매수')
            temp['외국인순매수'] = self._get_comm_data(trcode, rqname, i, '외국인순매수')
            temp['내국인대우외국인순매수'] = self._get_comm_data(trcode, rqname, i, '내국인대우외국인순매수')
            temp['국가순매수'] = self._get_comm_data(trcode, rqname, i, '국가순매수')
            temp['사모펀드순매수'] = self._get_comm_data(trcode, rqname, i, '사모펀드순매수')
            temp['기관계순매수'] = self._get_comm_data(trcode, rqname, i, '기관계순매수')
            self.opt10051_output['multi'].append(temp)

    def _opt10053(self, rqname, trcode):
        """
    	당일상위이탈원요청
    	"""
        self.opt10053_output = {'multi': []}

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['매도이탈시간'] = self._get_comm_data(trcode, rqname, i, '매도이탈시간')
            temp['매도수량'] = self._get_comm_data(trcode, rqname, i, '매도수량')
            temp['매도상위이탈원'] = self._get_comm_data(trcode, rqname, i, '매도상위이탈원')
            temp['매수이탈시간'] = self._get_comm_data(trcode, rqname, i, '매수이탈시간')
            temp['매수수량'] = self._get_comm_data(trcode, rqname, i, '매수수량')
            temp['매수상위이탈원'] = self._get_comm_data(trcode, rqname, i, '매수상위이탈원')
            temp['조회일자'] = self._get_comm_data(trcode, rqname, i, '조회일자')
            temp['조회시간'] = self._get_comm_data(trcode, rqname, i, '조회시간')
            self.opt10053_output['multi'].append(temp)

    def _opt10055(self, rqname, trcode):
        """
    	당일전일체결대량요청
    	"""
        self.opt10055_output = {'multi': []}

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['체결시간'] = self._get_comm_data(trcode, rqname, i, '체결시간')
            temp['체결가'] = self._get_comm_data(trcode, rqname, i, '체결가')
            temp['전일대비기호'] = self._get_comm_data(trcode, rqname, i, '전일대비기호')
            temp['전일대비'] = self._get_comm_data(trcode, rqname, i, '전일대비')
            temp['등락율'] = self._get_comm_data(trcode, rqname, i, '등락율')
            temp['체결량'] = self._get_comm_data(trcode, rqname, i, '체결량')
            temp['누적거래량'] = self._get_comm_data(trcode, rqname, i, '누적거래량')
            temp['누적거래대금'] = self._get_comm_data(trcode, rqname, i, '누적거래대금')
            self.opt10055_output['multi'].append(temp)

    def _opt10058(self, rqname, trcode):
        """
    	투자자별일별매매종목요청
    	"""
        self.opt10058_output = {'multi': []}

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['종목코드'] = self._get_comm_data(trcode, rqname, i, '종목코드')
            temp['종목명'] = self._get_comm_data(trcode, rqname, i, '종목명')
            temp['순매도수량'] = self._get_comm_data(trcode, rqname, i, '순매도수량')
            temp['순매도금액'] = self._get_comm_data(trcode, rqname, i, '순매도금액')
            temp['추정평균가'] = self._get_comm_data(trcode, rqname, i, '추정평균가')
            temp['현재가'] = self._get_comm_data(trcode, rqname, i, '현재가')
            temp['대비기호'] = self._get_comm_data(trcode, rqname, i, '대비기호')
            temp['전일대비'] = self._get_comm_data(trcode, rqname, i, '전일대비')
            temp['평균가대비'] = self._get_comm_data(trcode, rqname, i, '평균가대비')
            temp['대비율'] = self._get_comm_data(trcode, rqname, i, '대비율')
            temp['기간거래량'] = self._get_comm_data(trcode, rqname, i, '기간거래량')
            self.opt10058_output['multi'].append(temp)

    def _opt10059(self, rqname, trcode):
        """
    	종목별투자자기관별요청
    	"""
        self.opt10059_output = {'multi': []}

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['일자'] = self._get_comm_data(trcode, rqname, i, '일자')
            temp['현재가'] = self._get_comm_data(trcode, rqname, i, '현재가')
            temp['대비기호'] = self._get_comm_data(trcode, rqname, i, '대비기호')
            temp['전일대비'] = self._get_comm_data(trcode, rqname, i, '전일대비')
            temp['등락율'] = self._get_comm_data(trcode, rqname, i, '등락율')
            temp['누적거래량  '] = self._get_comm_data(trcode, rqname, i, '누적거래량  ')
            temp['누적거래대금'] = self._get_comm_data(trcode, rqname, i, '누적거래대금')
            temp['개인투자자'] = self._get_comm_data(trcode, rqname, i, '개인투자자')
            temp['외국인투자자'] = self._get_comm_data(trcode, rqname, i, '외국인투자자')
            temp['기관계'] = self._get_comm_data(trcode, rqname, i, '기관계')
            temp['금융투자'] = self._get_comm_data(trcode, rqname, i, '금융투자')
            temp['보험'] = self._get_comm_data(trcode, rqname, i, '보험')
            temp['투신'] = self._get_comm_data(trcode, rqname, i, '투신')
            temp['기타금융'] = self._get_comm_data(trcode, rqname, i, '기타금융')
            temp['은행'] = self._get_comm_data(trcode, rqname, i, '은행')
            temp['연기금등'] = self._get_comm_data(trcode, rqname, i, '연기금등')
            temp['사모펀드'] = self._get_comm_data(trcode, rqname, i, '사모펀드')
            temp['국가'] = self._get_comm_data(trcode, rqname, i, '국가')
            temp['기타법인'] = self._get_comm_data(trcode, rqname, i, '기타법인')
            temp['내외국인'] = self._get_comm_data(trcode, rqname, i, '내외국인')
            self.opt10059_output['multi'].append(temp)

    def _opt10060(self, rqname, trcode):
        """
    	종목별투자자기관별차트요청
    	"""
        self.opt10060_output = {'multi': []}

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['일자'] = self._get_comm_data(trcode, rqname, i, '일자')
            temp['현재가'] = self._get_comm_data(trcode, rqname, i, '현재가')
            temp['전일대비'] = self._get_comm_data(trcode, rqname, i, '전일대비')
            temp['누적거래대금'] = self._get_comm_data(trcode, rqname, i, '누적거래대금')
            temp['개인투자자'] = self._get_comm_data(trcode, rqname, i, '개인투자자')
            temp['외국인투자자'] = self._get_comm_data(trcode, rqname, i, '외국인투자자')
            temp['기관계'] = self._get_comm_data(trcode, rqname, i, '기관계')
            temp['금융투자'] = self._get_comm_data(trcode, rqname, i, '금융투자')
            temp['보험'] = self._get_comm_data(trcode, rqname, i, '보험')
            temp['투신'] = self._get_comm_data(trcode, rqname, i, '투신')
            temp['기타금융'] = self._get_comm_data(trcode, rqname, i, '기타금융')
            temp['은행'] = self._get_comm_data(trcode, rqname, i, '은행')
            temp['연기금등'] = self._get_comm_data(trcode, rqname, i, '연기금등')
            temp['사모펀드'] = self._get_comm_data(trcode, rqname, i, '사모펀드')
            temp['국가    '] = self._get_comm_data(trcode, rqname, i, '국가    ')
            temp['기타법인'] = self._get_comm_data(trcode, rqname, i, '기타법인')
            temp['내외국인'] = self._get_comm_data(trcode, rqname, i, '내외국인')
            self.opt10060_output['multi'].append(temp)

    def _opt10061(self, rqname, trcode):
        """
    	종목별투자자기관별합계요청
    	"""
        self.opt10061_output = {'multi': []}

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['개인투자자'] = self._get_comm_data(trcode, rqname, i, '개인투자자')
            temp['외국인투자자'] = self._get_comm_data(trcode, rqname, i, '외국인투자자')
            temp['기관계'] = self._get_comm_data(trcode, rqname, i, '기관계')
            temp['금융투자'] = self._get_comm_data(trcode, rqname, i, '금융투자')
            temp['보험'] = self._get_comm_data(trcode, rqname, i, '보험')
            temp['투신'] = self._get_comm_data(trcode, rqname, i, '투신')
            temp['기타금융'] = self._get_comm_data(trcode, rqname, i, '기타금융')
            temp['은행'] = self._get_comm_data(trcode, rqname, i, '은행')
            temp['연기금등'] = self._get_comm_data(trcode, rqname, i, '연기금등')
            temp['사모펀드'] = self._get_comm_data(trcode, rqname, i, '사모펀드')
            temp['국가'] = self._get_comm_data(trcode, rqname, i, '국가')
            temp['기타법인'] = self._get_comm_data(trcode, rqname, i, '기타법인')
            temp['내외국인'] = self._get_comm_data(trcode, rqname, i, '내외국인')
            self.opt10061_output['multi'].append(temp)

    def _opt10062(self, rqname, trcode):
        """
    	동일순매매순위요청
    	"""
        self.opt10062_output = {'multi': []}

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['종목코드'] = self._get_comm_data(trcode, rqname, i, '종목코드')
            temp['순위'] = self._get_comm_data(trcode, rqname, i, '순위')
            temp['종목명'] = self._get_comm_data(trcode, rqname, i, '종목명')
            temp['현재가'] = self._get_comm_data(trcode, rqname, i, '현재가')
            temp['대비기호'] = self._get_comm_data(trcode, rqname, i, '대비기호')
            temp['전일대비'] = self._get_comm_data(trcode, rqname, i, '전일대비')
            temp['등락율'] = self._get_comm_data(trcode, rqname, i, '등락율')
            temp['누적거래량'] = self._get_comm_data(trcode, rqname, i, '누적거래량')
            temp['기관순매매수량'] = self._get_comm_data(trcode, rqname, i, '기관순매매수량')
            temp['기관순매매금액'] = self._get_comm_data(trcode, rqname, i, '기관순매매금액')
            temp['기관순매매평균가'] = self._get_comm_data(trcode, rqname, i, '기관순매매평균가')
            temp['외인순매매수량'] = self._get_comm_data(trcode, rqname, i, '외인순매매수량')
            temp['외인순매매금액'] = self._get_comm_data(trcode, rqname, i, '외인순매매금액')
            temp['외인순매매평균가'] = self._get_comm_data(trcode, rqname, i, '외인순매매평균가')
            temp['순매매수량'] = self._get_comm_data(trcode, rqname, i, '순매매수량')
            temp['순매매금액'] = self._get_comm_data(trcode, rqname, i, '순매매금액')
            self.opt10062_output['multi'].append(temp)

    def _opt10063(self, rqname, trcode):
        """
    	장중투자자별매매요청
    	"""
        self.opt10063_output = {'multi': []}

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['종목명'] = self._get_comm_data(trcode, rqname, i, '종목명')
            temp['현재가'] = self._get_comm_data(trcode, rqname, i, '현재가')
            temp['대비기호'] = self._get_comm_data(trcode, rqname, i, '대비기호')
            temp['전일대비'] = self._get_comm_data(trcode, rqname, i, '전일대비')
            temp['등락율'] = self._get_comm_data(trcode, rqname, i, '등락율')
            temp['누적거래량'] = self._get_comm_data(trcode, rqname, i, '누적거래량')
            temp['순매수수량'] = self._get_comm_data(trcode, rqname, i, '순매수수량')
            temp['이점시전순매수수량'] = self._get_comm_data(trcode, rqname, i, '이점시전순매수수량')
            temp['순매수증감'] = self._get_comm_data(trcode, rqname, i, '순매수증감')
            temp['매수수량'] = self._get_comm_data(trcode, rqname, i, '매수수량')
            temp['매수수량증감'] = self._get_comm_data(trcode, rqname, i, '매수수량증감')
            temp['매도수량'] = self._get_comm_data(trcode, rqname, i, '매도수량')
            temp['매도수량증감'] = self._get_comm_data(trcode, rqname, i, '매도수량증감')
            self.opt10063_output['multi'].append(temp)

    def _opt10064(self, rqname, trcode):
        """
    	장중투자자별매매차트요청
    	"""
        self.opt10064_output = {'multi': []}

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['시간'] = self._get_comm_data(trcode, rqname, i, '시간')
            temp['외국인투자자'] = self._get_comm_data(trcode, rqname, i, '외국인투자자')
            temp['기관계'] = self._get_comm_data(trcode, rqname, i, '기관계')
            temp['투신'] = self._get_comm_data(trcode, rqname, i, '투신')
            temp['보험'] = self._get_comm_data(trcode, rqname, i, '보험')
            temp['은행'] = self._get_comm_data(trcode, rqname, i, '은행')
            temp['연기금등'] = self._get_comm_data(trcode, rqname, i, '연기금등')
            temp['기타법인'] = self._get_comm_data(trcode, rqname, i, '기타법인')
            temp['국가'] = self._get_comm_data(trcode, rqname, i, '국가')
            self.opt10064_output['multi'].append(temp)

    def _opt10065(self, rqname, trcode):
        """
    	장중투자자별매매상위요청
    	"""
        self.opt10065_output = {'multi': []}

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['종목코드'] = self._get_comm_data(trcode, rqname, i, '종목코드')
            temp['종목명'] = self._get_comm_data(trcode, rqname, i, '종목명')
            temp['매도량'] = self._get_comm_data(trcode, rqname, i, '매도량')
            temp['매수량'] = self._get_comm_data(trcode, rqname, i, '매수량')
            temp['순매도'] = self._get_comm_data(trcode, rqname, i, '순매도')
            self.opt10065_output['multi'].append(temp)

    def _opt10066(self, rqname, trcode):
        """
    	장중투자자별매매차트요청
    	"""
        self.opt10066_output = {'multi': []}

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['종목코드'] = self._get_comm_data(trcode, rqname, i, '종목코드')
            temp['종목명'] = self._get_comm_data(trcode, rqname, i, '종목명')
            temp['현재가'] = self._get_comm_data(trcode, rqname, i, '현재가')
            temp['대비기호'] = self._get_comm_data(trcode, rqname, i, '대비기호')
            temp['전일대비'] = self._get_comm_data(trcode, rqname, i, '전일대비')
            temp['등락률'] = self._get_comm_data(trcode, rqname, i, '등락률')
            temp['거래량'] = self._get_comm_data(trcode, rqname, i, '거래량')
            temp['개인투자자'] = self._get_comm_data(trcode, rqname, i, '개인투자자')
            temp['외국인투자자'] = self._get_comm_data(trcode, rqname, i, '외국인투자자')
            temp['기관계'] = self._get_comm_data(trcode, rqname, i, '기관계')
            temp['금융투자'] = self._get_comm_data(trcode, rqname, i, '금융투자')
            temp['보험'] = self._get_comm_data(trcode, rqname, i, '보험')
            temp['투신'] = self._get_comm_data(trcode, rqname, i, '투신')
            temp['기타금융'] = self._get_comm_data(trcode, rqname, i, '기타금융')
            temp['은행'] = self._get_comm_data(trcode, rqname, i, '은행')
            temp['연기금등'] = self._get_comm_data(trcode, rqname, i, '연기금등')
            temp['사모펀드'] = self._get_comm_data(trcode, rqname, i, '사모펀드')
            temp['국가'] = self._get_comm_data(trcode, rqname, i, '국가')
            temp['기타법인'] = self._get_comm_data(trcode, rqname, i, '기타법인')
            self.opt10066_output['multi'].append(temp)

    def _opt10067(self, rqname, trcode):
        """
    	대차거래내역요청
    	"""
        self.opt10067_output = {'multi': []}

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['종목명'] = self._get_comm_data(trcode, rqname, i, '종목명')
            temp['종목코드'] = self._get_comm_data(trcode, rqname, i, '종목코드')
            temp['대차거래체결주수'] = self._get_comm_data(trcode, rqname, i, '대차거래체결주수')
            temp['대차거래상환주수'] = self._get_comm_data(trcode, rqname, i, '대차거래상환주수')
            temp['잔고주수'] = self._get_comm_data(trcode, rqname, i, '잔고주수')
            temp['잔고금액'] = self._get_comm_data(trcode, rqname, i, '잔고금액')
            self.opt10067_output['multi'].append(temp)

    def _opt10068(self, rqname, trcode):
        """
    	대차거래추이요청
    	"""
        self.opt10068_output = {'multi': []}

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['일자'] = self._get_comm_data(trcode, rqname, i, '일자')
            temp['대차거래체결주수'] = self._get_comm_data(trcode, rqname, i, '대차거래체결주수')
            temp['대차거래상환주수'] = self._get_comm_data(trcode, rqname, i, '대차거래상환주수')
            temp['대차거래증감'] = self._get_comm_data(trcode, rqname, i, '대차거래증감')
            temp['잔고주수'] = self._get_comm_data(trcode, rqname, i, '잔고주수')
            temp['잔고금액'] = self._get_comm_data(trcode, rqname, i, '잔고금액')
            self.opt10068_output['multi'].append(temp)

    def _opt10069(self, rqname, trcode):
        """
    	대차거래상위10종목요청
    	"""
        self.opt10069_output = {'single': dict(), 'multi': []}

        self.opt10069_output['single']['대차거래체결주수합'] = self._get_comm_data(trcode, rqname, 0, '대차거래체결주수합')
        self.opt10069_output['single']['대차거래상환주수합'] = self._get_comm_data(trcode, rqname, 0, '대차거래상환주수합')
        self.opt10069_output['single']['잔고주수합'] = self._get_comm_data(trcode, rqname, 0, '잔고주수합')
        self.opt10069_output['single']['잔고금액합'] = self._get_comm_data(trcode, rqname, 0, '잔고금액합')
        self.opt10069_output['single']['대차거래체결주수비율'] = self._get_comm_data(trcode, rqname, 0, '대차거래체결주수비율')
        self.opt10069_output['single']['대차거래상환주수비율'] = self._get_comm_data(trcode, rqname, 0, '대차거래상환주수비율')
        self.opt10069_output['single']['잔고주수비율'] = self._get_comm_data(trcode, rqname, 0, '잔고주수비율')
        self.opt10069_output['single']['잔고금액비율'] = self._get_comm_data(trcode, rqname, 0, '잔고금액비율')

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['종목명'] = self._get_comm_data(trcode, rqname, i, '종목명')
            temp['종목코드'] = self._get_comm_data(trcode, rqname, i, '종목코드')
            temp['대차거래체결주수'] = self._get_comm_data(trcode, rqname, i, '대차거래체결주수')
            temp['대차거래상환주수'] = self._get_comm_data(trcode, rqname, i, '대차거래상환주수')
            temp['잔고주수'] = self._get_comm_data(trcode, rqname, i, '잔고주수')
            temp['잔고금액'] = self._get_comm_data(trcode, rqname, i, '잔고금액')
            self.opt10069_output['multi'].append(temp)

    def _opt10070(self, rqname, trcode):
        """
    	당일주요거래원요청
    	"""
        self.opt10070_output = {'single': dict()}

        self.opt10070_output['single']['매도거래원별증감1'] = self._get_comm_data(trcode, rqname, 0, '매도거래원별증감1')
        self.opt10070_output['single']['매도거래원수량1'] = self._get_comm_data(trcode, rqname, 0, '매도거래원수량1')
        self.opt10070_output['single']['매도거래원1'] = self._get_comm_data(trcode, rqname, 0, '매도거래원1')
        self.opt10070_output['single']['매도거래원코드1'] = self._get_comm_data(trcode, rqname, 0, '매도거래원코드1')
        self.opt10070_output['single']['매수거래원1'] = self._get_comm_data(trcode, rqname, 0, '매수거래원1')
        self.opt10070_output['single']['매수거래원코드1'] = self._get_comm_data(trcode, rqname, 0, '매수거래원코드1')
        self.opt10070_output['single']['매수거래원수량1'] = self._get_comm_data(trcode, rqname, 0, '매수거래원수량1')
        self.opt10070_output['single']['매수거래원별증감1'] = self._get_comm_data(trcode, rqname, 0, '매수거래원별증감1')
        self.opt10070_output['single']['매도거래원별증감2'] = self._get_comm_data(trcode, rqname, 0, '매도거래원별증감2')
        self.opt10070_output['single']['매도거래원수량2'] = self._get_comm_data(trcode, rqname, 0, '매도거래원수량2')
        self.opt10070_output['single']['매도거래원2'] = self._get_comm_data(trcode, rqname, 0, '매도거래원2')
        self.opt10070_output['single']['매도거래원코드2'] = self._get_comm_data(trcode, rqname, 0, '매도거래원코드2')
        self.opt10070_output['single']['매수거래원2'] = self._get_comm_data(trcode, rqname, 0, '매수거래원2')
        self.opt10070_output['single']['매수거래원코드2'] = self._get_comm_data(trcode, rqname, 0, '매수거래원코드2')
        self.opt10070_output['single']['매수거래원수량2'] = self._get_comm_data(trcode, rqname, 0, '매수거래원수량2')
        self.opt10070_output['single']['매수거래원별증감2'] = self._get_comm_data(trcode, rqname, 0, '매수거래원별증감2')
        self.opt10070_output['single']['매도거래원별증감3'] = self._get_comm_data(trcode, rqname, 0, '매도거래원별증감3')
        self.opt10070_output['single']['매도거래원수량3'] = self._get_comm_data(trcode, rqname, 0, '매도거래원수량3')
        self.opt10070_output['single']['매도거래원3'] = self._get_comm_data(trcode, rqname, 0, '매도거래원3')
        self.opt10070_output['single']['매도거래원코드3'] = self._get_comm_data(trcode, rqname, 0, '매도거래원코드3')
        self.opt10070_output['single']['매수거래원3'] = self._get_comm_data(trcode, rqname, 0, '매수거래원3')
        self.opt10070_output['single']['매수거래원코드3'] = self._get_comm_data(trcode, rqname, 0, '매수거래원코드3')
        self.opt10070_output['single']['매수거래원수량3'] = self._get_comm_data(trcode, rqname, 0, '매수거래원수량3')
        self.opt10070_output['single']['매수거래원별증감3'] = self._get_comm_data(trcode, rqname, 0, '매수거래원별증감3')
        self.opt10070_output['single']['매도거래원별증감4'] = self._get_comm_data(trcode, rqname, 0, '매도거래원별증감4')
        self.opt10070_output['single']['매도거래원수량4'] = self._get_comm_data(trcode, rqname, 0, '매도거래원수량4')
        self.opt10070_output['single']['매도거래원4'] = self._get_comm_data(trcode, rqname, 0, '매도거래원4')
        self.opt10070_output['single']['매도거래원코드4'] = self._get_comm_data(trcode, rqname, 0, '매도거래원코드4')
        self.opt10070_output['single']['매수거래원4'] = self._get_comm_data(trcode, rqname, 0, '매수거래원4')
        self.opt10070_output['single']['매수거래원수량4'] = self._get_comm_data(trcode, rqname, 0, '매수거래원수량4')
        self.opt10070_output['single']['매수거래원별증감4'] = self._get_comm_data(trcode, rqname, 0, '매수거래원별증감4')
        self.opt10070_output['single']['매도거래원별증감5'] = self._get_comm_data(trcode, rqname, 0, '매도거래원별증감5')
        self.opt10070_output['single']['매도거래원수량5'] = self._get_comm_data(trcode, rqname, 0, '매도거래원수량5')
        self.opt10070_output['single']['매도거래원5'] = self._get_comm_data(trcode, rqname, 0, '매도거래원5')
        self.opt10070_output['single']['매도거래원코드5'] = self._get_comm_data(trcode, rqname, 0, '매도거래원코드5')
        self.opt10070_output['single']['매수거래원5'] = self._get_comm_data(trcode, rqname, 0, '매수거래원5')
        self.opt10070_output['single']['매수거래원코드5'] = self._get_comm_data(trcode, rqname, 0, '매수거래원코드5')
        self.opt10070_output['single']['매수거래원수량5'] = self._get_comm_data(trcode, rqname, 0, '매수거래원수량5')
        self.opt10070_output['single']['매수거래원별증감5'] = self._get_comm_data(trcode, rqname, 0, '매수거래원별증감5')
        self.opt10070_output['single']['외국계매도추정합변동'] = self._get_comm_data(trcode, rqname, 0, '외국계매도추정합변동')
        self.opt10070_output['single']['외국계매도추정합'] = self._get_comm_data(trcode, rqname, 0, '외국계매도추정합')
        self.opt10070_output['single']['외국계매수추정합'] = self._get_comm_data(trcode, rqname, 0, '외국계매수추정합')
        self.opt10070_output['single']['외국계매수추정합변동'] = self._get_comm_data(trcode, rqname, 0, '외국계매수추정합변동')

    def _opt10071(self, rqname, trcode):
        """
    	시간대별전일비거래비중요청
    	"""
        self.opt10071_output = {'multi': []}

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['시간'] = self._get_comm_data(trcode, rqname, i, '시간')
            temp['현재가'] = self._get_comm_data(trcode, rqname, i, '현재가')
            temp['대비기호'] = self._get_comm_data(trcode, rqname, i, '대비기호')
            temp['전일대비'] = self._get_comm_data(trcode, rqname, i, '전일대비')
            temp['대비율'] = self._get_comm_data(trcode, rqname, i, '대비율')
            temp['체결거래량'] = self._get_comm_data(trcode, rqname, i, '체결거래량')
            temp['누적거래량'] = self._get_comm_data(trcode, rqname, i, '누적거래량')
            temp['순간비율'] = self._get_comm_data(trcode, rqname, i, '순간비율')
            temp['누적비율'] = self._get_comm_data(trcode, rqname, i, '누적비율')
            self.opt10071_output['multi'].append(temp)

    def _opt10072(self, rqname, trcode):
        """
    	일자별종목별실현손익요청
    	"""
        self.opt10072_output = {'multi': []}

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['일자'] = self._get_comm_data(trcode, rqname, i, '일자')
            temp['당일hts매도수수료'] = self._get_comm_data(trcode, rqname, i, '당일hts매도수수료')
            temp['종목명'] = self._get_comm_data(trcode, rqname, i, '종목명')
            temp['체결량'] = self._get_comm_data(trcode, rqname, i, '체결량')
            temp['매입단가'] = self._get_comm_data(trcode, rqname, i, '매입단가')
            temp['체결가'] = self._get_comm_data(trcode, rqname, i, '체결가')
            temp['당일매도손익'] = self._get_comm_data(trcode, rqname, i, '당일매도손익')
            temp['손익율'] = self._get_comm_data(trcode, rqname, i, '손익율')
            temp['종목코드'] = self._get_comm_data(trcode, rqname, i, '종목코드')
            temp['당일매매수수료'] = self._get_comm_data(trcode, rqname, i, '당일매매수수료')
            temp['당일매매세금'] = self._get_comm_data(trcode, rqname, i, '당일매매세금')
            temp['인출가능금액'] = self._get_comm_data(trcode, rqname, i, '인출가능금액')
            temp['대출일'] = self._get_comm_data(trcode, rqname, i, '대출일')
            temp['신용구분'] = self._get_comm_data(trcode, rqname, i, '신용구분')
            temp['종목코드1'] = self._get_comm_data(trcode, rqname, i, '종목코드1')
            temp['당일매도손익1'] = self._get_comm_data(trcode, rqname, i, '당일매도손익1')
            self.opt10072_output['multi'].append(temp)

    def _opt10073(self, rqname, trcode):
        """
    	일자별종목별실현손익요청
    	"""
        self.opt10073_output = {'multi': []}

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['일자'] = self._get_comm_data(trcode, rqname, i, '일자')
            temp['당일hts매도수수료'] = self._get_comm_data(trcode, rqname, i, '당일hts매도수수료')
            temp['종목명'] = self._get_comm_data(trcode, rqname, i, '종목명')
            temp['체결량'] = self._get_comm_data(trcode, rqname, i, '체결량')
            temp['매입단가'] = self._get_comm_data(trcode, rqname, i, '매입단가')
            temp['체결가'] = self._get_comm_data(trcode, rqname, i, '체결가')
            temp['당일매도손익'] = self._get_comm_data(trcode, rqname, i, '당일매도손익')
            temp['손익율'] = self._get_comm_data(trcode, rqname, i, '손익율')
            temp['종목코드'] = self._get_comm_data(trcode, rqname, i, '종목코드')
            temp['당일매매수수료'] = self._get_comm_data(trcode, rqname, i, '당일매매수수료')
            temp['당일매매세금'] = self._get_comm_data(trcode, rqname, i, '당일매매세금')
            temp['인출가능금액'] = self._get_comm_data(trcode, rqname, i, '인출가능금액')
            temp['대출일'] = self._get_comm_data(trcode, rqname, i, '대출일')
            temp['신용구분'] = self._get_comm_data(trcode, rqname, i, '신용구분')
            temp['종목코드1'] = self._get_comm_data(trcode, rqname, i, '종목코드1')
            temp['당일매도손익1'] = self._get_comm_data(trcode, rqname, i, '당일매도손익1')
            self.opt10073_output['multi'].append(temp)

    def _opt10074(self, rqname, trcode):
        """
    	일자별실현손익요청
    	"""
        self.opt10074_output = {'single': dict(), 'multi': []}

        self.opt10074_output['single']['총매수금액'] = self._get_comm_data(trcode, rqname, 0, '총매수금액')
        self.opt10074_output['single']['총매도금액'] = self._get_comm_data(trcode, rqname, 0, '총매도금액')
        self.opt10074_output['single']['실현손익'] = self._get_comm_data(trcode, rqname, 0, '실현손익')
        self.opt10074_output['single']['매매수수료'] = self._get_comm_data(trcode, rqname, 0, '매매수수료')
        self.opt10074_output['single']['매매세금'] = self._get_comm_data(trcode, rqname, 0, '매매세금')

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['일자'] = self._get_comm_data(trcode, rqname, i, '일자')
            temp['매수금액'] = self._get_comm_data(trcode, rqname, i, '매수금액')
            temp['매도금액'] = self._get_comm_data(trcode, rqname, i, '매도금액')
            temp['당일매도손익'] = self._get_comm_data(trcode, rqname, i, '당일매도손익')
            temp['당일매매수수료'] = self._get_comm_data(trcode, rqname, i, '당일매매수수료')
            temp['당일매매세금'] = self._get_comm_data(trcode, rqname, i, '당일매매세금')
            self.opt10074_output['multi'].append(temp)

    def _opt10075(self, rqname, trcode):
        """
    	실시간미체결요청
    	"""
        self.opt10075_output = {'multi': []}

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['계좌번호'] = self._get_comm_data(trcode, rqname, i, '계좌번호')
            temp['주문번호'] = self._get_comm_data(trcode, rqname, i, '주문번호')
            temp['관리사번'] = self._get_comm_data(trcode, rqname, i, '관리사번')
            temp['종목코드'] = self._get_comm_data(trcode, rqname, i, '종목코드')
            temp['업무구분'] = self._get_comm_data(trcode, rqname, i, '업무구분')
            temp['주문상태'] = self._get_comm_data(trcode, rqname, i, '주문상태')
            temp['종목명'] = self._get_comm_data(trcode, rqname, i, '종목명')
            temp['주문수량'] = self._get_comm_data(trcode, rqname, i, '주문수량')
            temp['주문가격'] = self._get_comm_data(trcode, rqname, i, '주문가격')
            temp['미체결수량'] = self._get_comm_data(trcode, rqname, i, '미체결수량')
            temp['체결누계금액'] = self._get_comm_data(trcode, rqname, i, '체결누계금액')
            temp['원주문번호'] = self._get_comm_data(trcode, rqname, i, '원주문번호')
            temp['주문구분'] = self._get_comm_data(trcode, rqname, i, '주문구분')
            temp['매매구분'] = self._get_comm_data(trcode, rqname, i, '매매구분')
            temp['시간'] = self._get_comm_data(trcode, rqname, i, '시간')
            temp['체결번호'] = self._get_comm_data(trcode, rqname, i, '체결번호')
            temp['체결가'] = self._get_comm_data(trcode, rqname, i, '체결가')
            temp['체결량'] = self._get_comm_data(trcode, rqname, i, '체결량')
            temp['현재가'] = self._get_comm_data(trcode, rqname, i, '현재가')
            temp['매도호가'] = self._get_comm_data(trcode, rqname, i, '매도호가')
            temp['매수호가'] = self._get_comm_data(trcode, rqname, i, '매수호가')
            temp['단위체결가'] = self._get_comm_data(trcode, rqname, i, '단위체결가')
            temp['단위체결량'] = self._get_comm_data(trcode, rqname, i, '단위체결량')
            temp['당일매매수수료'] = self._get_comm_data(trcode, rqname, i, '당일매매수수료')
            temp['당일매매세금'] = self._get_comm_data(trcode, rqname, i, '당일매매세금')
            temp['개인투자자'] = self._get_comm_data(trcode, rqname, i, '개인투자자')
            self.opt10075_output['multi'].append(temp)

    def _opt10076(self, rqname, trcode):
        """
    	실시간체결요청
    	"""
        self.opt10076_output = {'multi': []}

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['주문번호'] = self._get_comm_data(trcode, rqname, i, '주문번호')
            temp['종목명'] = self._get_comm_data(trcode, rqname, i, '종목명')
            temp['주문구분'] = self._get_comm_data(trcode, rqname, i, '주문구분')
            temp['주문가격'] = self._get_comm_data(trcode, rqname, i, '주문가격')
            temp['주문수량'] = self._get_comm_data(trcode, rqname, i, '주문수량')
            temp['체결가'] = self._get_comm_data(trcode, rqname, i, '체결가')
            temp['체결량'] = self._get_comm_data(trcode, rqname, i, '체결량')
            temp['미체결수량'] = self._get_comm_data(trcode, rqname, i, '미체결수량')
            temp['당일매매수수료'] = self._get_comm_data(trcode, rqname, i, '당일매매수수료')
            temp['당일매매세금'] = self._get_comm_data(trcode, rqname, i, '당일매매세금')
            temp['주문상태'] = self._get_comm_data(trcode, rqname, i, '주문상태')
            temp['매매구분'] = self._get_comm_data(trcode, rqname, i, '매매구분')
            temp['원주문번호'] = self._get_comm_data(trcode, rqname, i, '원주문번호')
            temp['시간'] = self._get_comm_data(trcode, rqname, i, '시간')
            temp['계좌번호'] = self._get_comm_data(trcode, rqname, i, '계좌번호')
            self.opt10076_output['multi'].append(temp)

    def _opt10077(self, rqname, trcode):
        """
    	당일실현손익상세요청
    	"""
        self.opt10077_output = {'single': dict(), 'multi': []}

        self.opt10077_output['single']['당일실현손익'] = self._get_comm_data(trcode, rqname, 0, '당일실현손익')

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['종목명'] = self._get_comm_data(trcode, rqname, i, '종목명')
            temp['체결량'] = self._get_comm_data(trcode, rqname, i, '체결량')
            temp['매입단가'] = self._get_comm_data(trcode, rqname, i, '매입단가')
            temp['체결가'] = self._get_comm_data(trcode, rqname, i, '체결가')
            temp['당일매도손익'] = self._get_comm_data(trcode, rqname, i, '당일매도손익')
            temp['손익율'] = self._get_comm_data(trcode, rqname, i, '손익율')
            temp['당일매매수수료'] = self._get_comm_data(trcode, rqname, i, '당일매매수수료')
            temp['당일매매세금'] = self._get_comm_data(trcode, rqname, i, '당일매매세금')
            temp['종목코드'] = self._get_comm_data(trcode, rqname, i, '종목코드')
            self.opt10077_output['multi'].append(temp)

    def _opt10078(self, rqname, trcode):
        """
    	증권사별종목매매동향요청
    	"""
        self.opt10078_output = {'multi': []}

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['일자'] = self._get_comm_data(trcode, rqname, i, '일자')
            temp['현재가'] = self._get_comm_data(trcode, rqname, i, '현재가')
            temp['대비기호'] = self._get_comm_data(trcode, rqname, i, '대비기호')
            temp['전일대비'] = self._get_comm_data(trcode, rqname, i, '전일대비')
            temp['등락율'] = self._get_comm_data(trcode, rqname, i, '등락율')
            temp['누적거래량'] = self._get_comm_data(trcode, rqname, i, '누적거래량')
            temp['순매수수량'] = self._get_comm_data(trcode, rqname, i, '순매수수량')
            temp['매수수량'] = self._get_comm_data(trcode, rqname, i, '매수수량')
            temp['매도수량'] = self._get_comm_data(trcode, rqname, i, '매도수량')
            self.opt10078_output['multi'].append(temp)

    def _opt10079(self, rqname, trcode):
        """
    	주식틱차트조회요청
    	"""
        self.opt10079_output = {'single': dict(), 'multi': []}

        self.opt10079_output['single']['종목코드'] = self._get_comm_data(trcode, rqname, 0, '종목코드')
        self.opt10079_output['single']['마지막틱갯수'] = self._get_comm_data(trcode, rqname, 0, '마지막틱갯수')

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['현재가'] = self._get_comm_data(trcode, rqname, i, '현재가')
            temp['거래량'] = self._get_comm_data(trcode, rqname, i, '거래량')
            temp['체결시간'] = self._get_comm_data(trcode, rqname, i, '체결시간')
            temp['시가'] = self._get_comm_data(trcode, rqname, i, '시가')
            temp['고가'] = self._get_comm_data(trcode, rqname, i, '고가')
            temp['저가'] = self._get_comm_data(trcode, rqname, i, '저가')
            temp['수정주가구분'] = self._get_comm_data(trcode, rqname, i, '수정주가구분')
            temp['수정비율'] = self._get_comm_data(trcode, rqname, i, '수정비율')
            temp['대업종구분'] = self._get_comm_data(trcode, rqname, i, '대업종구분')
            temp['소업종구분'] = self._get_comm_data(trcode, rqname, i, '소업종구분')
            temp['종목정보'] = self._get_comm_data(trcode, rqname, i, '종목정보')
            temp['수정주가이벤트'] = self._get_comm_data(trcode, rqname, i, '수정주가이벤트')
            temp['전일종가'] = self._get_comm_data(trcode, rqname, i, '전일종가')
            self.opt10079_output['multi'].append(temp)

    def _opt10080(self, rqname, trcode):
        """
    	주식분봉차트조회요청
    	"""
        self.opt10080_output = {'single': dict(), 'multi': []}

        self.opt10080_output['single']['종목코드'] = self._get_comm_data(trcode, rqname, 0, '종목코드')

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['현재가'] = self._get_comm_data(trcode, rqname, i, '현재가')
            temp['거래량'] = self._get_comm_data(trcode, rqname, i, '거래량')
            temp['체결시간'] = self._get_comm_data(trcode, rqname, i, '체결시간')
            temp['시가'] = self._get_comm_data(trcode, rqname, i, '시가')
            temp['고가'] = self._get_comm_data(trcode, rqname, i, '고가')
            temp['저가'] = self._get_comm_data(trcode, rqname, i, '저가')
            temp['수정주가구분'] = self._get_comm_data(trcode, rqname, i, '수정주가구분')
            temp['수정비율'] = self._get_comm_data(trcode, rqname, i, '수정비율')
            temp['대업종구분'] = self._get_comm_data(trcode, rqname, i, '대업종구분')
            temp['소업종구분'] = self._get_comm_data(trcode, rqname, i, '소업종구분')
            temp['종목정보'] = self._get_comm_data(trcode, rqname, i, '종목정보')
            temp['수정주가이벤트'] = self._get_comm_data(trcode, rqname, i, '수정주가이벤트')
            temp['전일종가'] = self._get_comm_data(trcode, rqname, i, '전일종가')
            self.opt10080_output['multi'].append(temp)

    def _opt10081(self, rqname, trcode):
        """
    	주식일봉차트조회요청
    	"""
        self.opt10081_output = {'single': dict(), 'multi': []}

        self.opt10081_output['single']['종목코드'] = self._get_comm_data(trcode, rqname, 0, '종목코드')

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['종목코드'] = self._get_comm_data(trcode, rqname, i, '종목코드')
            temp['현재가'] = self._get_comm_data(trcode, rqname, i, '현재가')
            temp['거래량'] = self._get_comm_data(trcode, rqname, i, '거래량')
            temp['거래대금'] = self._get_comm_data(trcode, rqname, i, '거래대금')
            temp['일자'] = self._get_comm_data(trcode, rqname, i, '일자')
            temp['시가'] = self._get_comm_data(trcode, rqname, i, '시가')
            temp['고가'] = self._get_comm_data(trcode, rqname, i, '고가')
            temp['저가'] = self._get_comm_data(trcode, rqname, i, '저가')
            temp['수정주가구분'] = self._get_comm_data(trcode, rqname, i, '수정주가구분')
            temp['수정비율'] = self._get_comm_data(trcode, rqname, i, '수정비율')
            temp['대업종구분'] = self._get_comm_data(trcode, rqname, i, '대업종구분')
            temp['소업종구분'] = self._get_comm_data(trcode, rqname, i, '소업종구분')
            temp['종목정보'] = self._get_comm_data(trcode, rqname, i, '종목정보')
            temp['수정주가이벤트'] = self._get_comm_data(trcode, rqname, i, '수정주가이벤트')
            temp['전일종가'] = self._get_comm_data(trcode, rqname, i, '전일종가')
            self.opt10081_output['multi'].append(temp)

    def _opt10082(self, rqname, trcode):
        """
    	주식주봉차트조회요청
    	"""
        self.opt10082_output = {'single': dict(), 'multi': []}

        self.opt10082_output['single']['종목코드'] = self._get_comm_data(trcode, rqname, 0, '종목코드')

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['현재가'] = self._get_comm_data(trcode, rqname, i, '현재가')
            temp['거래량'] = self._get_comm_data(trcode, rqname, i, '거래량')
            temp['거래대금'] = self._get_comm_data(trcode, rqname, i, '거래대금')
            temp['일자'] = self._get_comm_data(trcode, rqname, i, '일자')
            temp['시가'] = self._get_comm_data(trcode, rqname, i, '시가')
            temp['고가'] = self._get_comm_data(trcode, rqname, i, '고가')
            temp['저가'] = self._get_comm_data(trcode, rqname, i, '저가')
            temp['수정주가구분'] = self._get_comm_data(trcode, rqname, i, '수정주가구분')
            temp['수정비율'] = self._get_comm_data(trcode, rqname, i, '수정비율')
            temp['대업종구분'] = self._get_comm_data(trcode, rqname, i, '대업종구분')
            temp['소업종구분'] = self._get_comm_data(trcode, rqname, i, '소업종구분')
            temp['종목정보'] = self._get_comm_data(trcode, rqname, i, '종목정보')
            temp['수정주가이벤트'] = self._get_comm_data(trcode, rqname, i, '수정주가이벤트')
            temp['전일종가'] = self._get_comm_data(trcode, rqname, i, '전일종가')
            self.opt10082_output['multi'].append(temp)

    def _opt10083(self, rqname, trcode):
        """
    	주식월봉차트조회요청
    	"""
        self.opt10083_output = {'single': dict(), 'multi': []}

        self.opt10083_output['single']['종목코드'] = self._get_comm_data(trcode, rqname, 0, '종목코드')

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['현재가'] = self._get_comm_data(trcode, rqname, i, '현재가')
            temp['거래량'] = self._get_comm_data(trcode, rqname, i, '거래량')
            temp['거래대금'] = self._get_comm_data(trcode, rqname, i, '거래대금')
            temp['일자'] = self._get_comm_data(trcode, rqname, i, '일자')
            temp['시가'] = self._get_comm_data(trcode, rqname, i, '시가')
            temp['고가'] = self._get_comm_data(trcode, rqname, i, '고가')
            temp['저가'] = self._get_comm_data(trcode, rqname, i, '저가')
            temp['수정주가구분'] = self._get_comm_data(trcode, rqname, i, '수정주가구분')
            temp['수정비율'] = self._get_comm_data(trcode, rqname, i, '수정비율')
            temp['대업종구분'] = self._get_comm_data(trcode, rqname, i, '대업종구분')
            temp['소업종구분'] = self._get_comm_data(trcode, rqname, i, '소업종구분')
            temp['종목정보'] = self._get_comm_data(trcode, rqname, i, '종목정보')
            temp['수정주가이벤트'] = self._get_comm_data(trcode, rqname, i, '수정주가이벤트')
            temp['전일종가'] = self._get_comm_data(trcode, rqname, i, '전일종가')
            self.opt10083_output['multi'].append(temp)

    def _opt10084(self, rqname, trcode):
        """
    	당일전일체결요청
    	"""
        self.opt10084_output = {'multi': []}

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['시간'] = self._get_comm_data(trcode, rqname, i, '시간')
            temp['현재가'] = self._get_comm_data(trcode, rqname, i, '현재가')
            temp['전일대비'] = self._get_comm_data(trcode, rqname, i, '전일대비')
            temp['대비율'] = self._get_comm_data(trcode, rqname, i, '대비율')
            temp['우선매도호가단위'] = self._get_comm_data(trcode, rqname, i, '우선매도호가단위')
            temp['우선매수호가단위'] = self._get_comm_data(trcode, rqname, i, '우선매수호가단위')
            temp['체결거래량'] = self._get_comm_data(trcode, rqname, i, '체결거래량')
            temp['sign'] = self._get_comm_data(trcode, rqname, i, 'sign')
            temp['누적거래량'] = self._get_comm_data(trcode, rqname, i, '누적거래량')
            temp['누적거래대금'] = self._get_comm_data(trcode, rqname, i, '누적거래대금')
            temp['체결강도'] = self._get_comm_data(trcode, rqname, i, '체결강도')
            self.opt10084_output['multi'].append(temp)

    def _opt10085(self, rqname, trcode):
        """
    	계좌수익률요청
    	"""
        self.opt10085_output = {'multi': []}

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['일자'] = self._get_comm_data(trcode, rqname, i, '일자')
            temp['종목코드'] = self._get_comm_data(trcode, rqname, i, '종목코드')
            temp['종목명'] = self._get_comm_data(trcode, rqname, i, '종목명')
            temp['현재가  '] = self._get_comm_data(trcode, rqname, i, '현재가  ')
            temp[''] = self._get_comm_data(trcode, rqname, i, '')
            temp['매입금액'] = self._get_comm_data(trcode, rqname, i, '매입금액')
            temp[''] = self._get_comm_data(trcode, rqname, i, '')
            temp['당일매도손익'] = self._get_comm_data(trcode, rqname, i, '당일매도손익')
            temp['당일매매수수료'] = self._get_comm_data(trcode, rqname, i, '당일매매수수료')
            temp['당일매매세금'] = self._get_comm_data(trcode, rqname, i, '당일매매세금')
            temp['100'] = self._get_comm_data(trcode, rqname, i, '100')
            temp['100'] = self._get_comm_data(trcode, rqname, i, '100')
            temp['100'] = self._get_comm_data(trcode, rqname, i, '100')
            temp['100'] = self._get_comm_data(trcode, rqname, i, '100')
            temp['100'] = self._get_comm_data(trcode, rqname, i, '100')
            temp['100'] = self._get_comm_data(trcode, rqname, i, '100')
            temp['100'] = self._get_comm_data(trcode, rqname, i, '100')
            self.opt10085_output['multi'].append(temp)

    def _opt10086(self, rqname, trcode):
        """
    	일별주가요청
    	"""
        self.opt10086_output = {'multi': []}

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['날짜'] = self._get_comm_data(trcode, rqname, i, '날짜')
            temp['시가'] = self._get_comm_data(trcode, rqname, i, '시가')
            temp['고가'] = self._get_comm_data(trcode, rqname, i, '고가')
            temp['저가'] = self._get_comm_data(trcode, rqname, i, '저가')
            temp['종가'] = self._get_comm_data(trcode, rqname, i, '종가')
            temp['전일비'] = self._get_comm_data(trcode, rqname, i, '전일비')
            temp['등락률'] = self._get_comm_data(trcode, rqname, i, '등락률')
            temp['거래량'] = self._get_comm_data(trcode, rqname, i, '거래량')
            temp['금액(백만)'] = self._get_comm_data(trcode, rqname, i, '금액(백만)')
            temp['신용비    '] = self._get_comm_data(trcode, rqname, i, '신용비    ')
            temp['개인      '] = self._get_comm_data(trcode, rqname, i, '개인      ')
            temp['기관      '] = self._get_comm_data(trcode, rqname, i, '기관      ')
            temp['외인수량  '] = self._get_comm_data(trcode, rqname, i, '외인수량  ')
            temp['외국계    '] = self._get_comm_data(trcode, rqname, i, '외국계    ')
            temp['프로그램  '] = self._get_comm_data(trcode, rqname, i, '프로그램  ')
            temp['외인비    '] = self._get_comm_data(trcode, rqname, i, '외인비    ')
            temp['체결강도'] = self._get_comm_data(trcode, rqname, i, '체결강도')
            temp['외인보유'] = self._get_comm_data(trcode, rqname, i, '외인보유')
            temp['외인비중'] = self._get_comm_data(trcode, rqname, i, '외인비중')
            temp['외인순매수'] = self._get_comm_data(trcode, rqname, i, '외인순매수')
            temp['기관순매수'] = self._get_comm_data(trcode, rqname, i, '기관순매수')
            temp['개인순매수'] = self._get_comm_data(trcode, rqname, i, '개인순매수')
            temp['신용잔고율'] = self._get_comm_data(trcode, rqname, i, '신용잔고율')
            self.opt10086_output['multi'].append(temp)

    def _opt10087(self, rqname, trcode):
        """
    	시간외단일가요청
    	"""
        self.opt10087_output = {'multi': []}

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['호가잔량기준시간'] = self._get_comm_data(trcode, rqname, i, '호가잔량기준시간')
            temp['시간외단일가_매도호가직전대비5  '] = self._get_comm_data(trcode, rqname, i, '시간외단일가_매도호가직전대비5  ')
            temp['시간외단일가_매도호가직전대비4  '] = self._get_comm_data(trcode, rqname, i, '시간외단일가_매도호가직전대비4  ')
            temp['시간외단일가_매도호가직전대비3  '] = self._get_comm_data(trcode, rqname, i, '시간외단일가_매도호가직전대비3  ')
            temp['시간외단일가_매도호가직전대비2  '] = self._get_comm_data(trcode, rqname, i, '시간외단일가_매도호가직전대비2  ')
            temp['시간외단일가_매도호가직전대비1  '] = self._get_comm_data(trcode, rqname, i, '시간외단일가_매도호가직전대비1  ')
            temp['시간외단일가_매도호가수량5      '] = self._get_comm_data(trcode, rqname, i, '시간외단일가_매도호가수량5      ')
            temp[','] = self._get_comm_data(trcode, rqname, i, ',')
            temp[','] = self._get_comm_data(trcode, rqname, i, ',')
            temp[','] = self._get_comm_data(trcode, rqname, i, ',')
            temp[','] = self._get_comm_data(trcode, rqname, i, ',')
            temp[','] = self._get_comm_data(trcode, rqname, i, ',')
            temp[','] = self._get_comm_data(trcode, rqname, i, ',')
            temp[','] = self._get_comm_data(trcode, rqname, i, ',')
            temp[','] = self._get_comm_data(trcode, rqname, i, ',')
            temp[','] = self._get_comm_data(trcode, rqname, i, ',')
            temp[','] = self._get_comm_data(trcode, rqname, i, ',')
            temp[','] = self._get_comm_data(trcode, rqname, i, ',')
            temp[','] = self._get_comm_data(trcode, rqname, i, ',')
            temp[','] = self._get_comm_data(trcode, rqname, i, ',')
            temp[','] = self._get_comm_data(trcode, rqname, i, ',')
            temp[','] = self._get_comm_data(trcode, rqname, i, ',')
            temp[','] = self._get_comm_data(trcode, rqname, i, ',')
            temp[','] = self._get_comm_data(trcode, rqname, i, ',')
            temp[','] = self._get_comm_data(trcode, rqname, i, ',')
            temp[','] = self._get_comm_data(trcode, rqname, i, ',')
            temp[','] = self._get_comm_data(trcode, rqname, i, ',')
            temp[','] = self._get_comm_data(trcode, rqname, i, ',')
            temp[','] = self._get_comm_data(trcode, rqname, i, ',')
            temp[','] = self._get_comm_data(trcode, rqname, i, ',')
            temp[','] = self._get_comm_data(trcode, rqname, i, ',')
            temp[','] = self._get_comm_data(trcode, rqname, i, ',')
            temp[','] = self._get_comm_data(trcode, rqname, i, ',')
            temp[','] = self._get_comm_data(trcode, rqname, i, ',')
            temp[','] = self._get_comm_data(trcode, rqname, i, ',')
            temp[','] = self._get_comm_data(trcode, rqname, i, ',')
            temp[','] = self._get_comm_data(trcode, rqname, i, ',')
            temp[','] = self._get_comm_data(trcode, rqname, i, ',')
            temp[','] = self._get_comm_data(trcode, rqname, i, ',')
            temp['시간외매수호가총잔량        '] = self._get_comm_data(trcode, rqname, i, '시간외매수호가총잔량        ')
            temp['시간외매수호가총잔량직전대비  '] = self._get_comm_data(trcode, rqname, i, '시간외매수호가총잔량직전대비  ')
            temp['시간외단일가_현재가             '] = self._get_comm_data(trcode, rqname, i, '시간외단일가_현재가             ')
            temp['시간외단일가_전일대비기호       '] = self._get_comm_data(trcode, rqname, i, '시간외단일가_전일대비기호       ')
            temp['시간외단일가_전일대비           '] = self._get_comm_data(trcode, rqname, i, '시간외단일가_전일대비           ')
            temp['시간외단일가_등락률             '] = self._get_comm_data(trcode, rqname, i, '시간외단일가_등락률             ')
            temp['시간외단일가_누적거래량         '] = self._get_comm_data(trcode, rqname, i, '시간외단일가_누적거래량         ')
            self.opt10087_output['multi'].append(temp)

    def _opt10094(self, rqname, trcode):
        """
    	주식년봉차트조회요청
    	"""
        self.opt10094_output = {'single': dict(), 'multi': []}

        self.opt10094_output['single']['종목코드'] = self._get_comm_data(trcode, rqname, 0, '종목코드')

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['현재가'] = self._get_comm_data(trcode, rqname, i, '현재가')
            temp['거래량'] = self._get_comm_data(trcode, rqname, i, '거래량')
            temp['거래대금'] = self._get_comm_data(trcode, rqname, i, '거래대금')
            temp['일자'] = self._get_comm_data(trcode, rqname, i, '일자')
            temp['시가'] = self._get_comm_data(trcode, rqname, i, '시가')
            temp['고가'] = self._get_comm_data(trcode, rqname, i, '고가')
            temp['저가'] = self._get_comm_data(trcode, rqname, i, '저가')
            temp['수정주가구분'] = self._get_comm_data(trcode, rqname, i, '수정주가구분')
            temp['수정비율'] = self._get_comm_data(trcode, rqname, i, '수정비율')
            temp['대업종구분'] = self._get_comm_data(trcode, rqname, i, '대업종구분')
            temp['소업종구분'] = self._get_comm_data(trcode, rqname, i, '소업종구분')
            temp['종목정보'] = self._get_comm_data(trcode, rqname, i, '종목정보')
            temp['수정주가이벤트'] = self._get_comm_data(trcode, rqname, i, '수정주가이벤트')
            temp['전일종가'] = self._get_comm_data(trcode, rqname, i, '전일종가')
            self.opt10094_output['multi'].append(temp)

    def _opt20001(self, rqname, trcode):
        """
    	업종현재가요청
    	"""
        self.opt20001_output = {'single': dict(), 'multi': []}

        self.opt20001_output['single']['현재가'] = self._get_comm_data(trcode, rqname, 0, '현재가')
        self.opt20001_output['single']['전일대비기호'] = self._get_comm_data(trcode, rqname, 0, '전일대비기호')
        self.opt20001_output['single']['전일대비'] = self._get_comm_data(trcode, rqname, 0, '전일대비')
        self.opt20001_output['single']['등락률'] = self._get_comm_data(trcode, rqname, 0, '등락률')
        self.opt20001_output['single']['거래량'] = self._get_comm_data(trcode, rqname, 0, '거래량')
        self.opt20001_output['single']['거래대금'] = self._get_comm_data(trcode, rqname, 0, '거래대금')
        self.opt20001_output['single']['거래형성종목수  '] = self._get_comm_data(trcode, rqname, 0, '거래형성종목수  ')
        self.opt20001_output['single']['거래형성비율    '] = self._get_comm_data(trcode, rqname, 0, '거래형성비율    ')
        self.opt20001_output['single']['시가  '] = self._get_comm_data(trcode, rqname, 0, '시가  ')
        self.opt20001_output['single']['고가'] = self._get_comm_data(trcode, rqname, 0, '고가')
        self.opt20001_output['single']['저가'] = self._get_comm_data(trcode, rqname, 0, '저가')
        self.opt20001_output['single']['상한'] = self._get_comm_data(trcode, rqname, 0, '상한')
        self.opt20001_output['single']['상승'] = self._get_comm_data(trcode, rqname, 0, '상승')
        self.opt20001_output['single']['보합'] = self._get_comm_data(trcode, rqname, 0, '보합')
        self.opt20001_output['single']['하락'] = self._get_comm_data(trcode, rqname, 0, '하락')
        self.opt20001_output['single']['하한'] = self._get_comm_data(trcode, rqname, 0, '하한')
        self.opt20001_output['single']['52주최고가 '] = self._get_comm_data(trcode, rqname, 0, '52주최고가 ')
        self.opt20001_output['single']['52주최고가일'] = self._get_comm_data(trcode, rqname, 0, '52주최고가일')
        self.opt20001_output['single']['52주최고가대비율'] = self._get_comm_data(trcode, rqname, 0, '52주최고가대비율')
        self.opt20001_output['single']['52주최저가 '] = self._get_comm_data(trcode, rqname, 0, '52주최저가 ')
        self.opt20001_output['single']['52주최저가일'] = self._get_comm_data(trcode, rqname, 0, '52주최저가일')
        self.opt20001_output['single']['52주최저가대비율'] = self._get_comm_data(trcode, rqname, 0, '52주최저가대비율')

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['시간n    '] = self._get_comm_data(trcode, rqname, i, '시간n    ')
            temp['현재가n'] = self._get_comm_data(trcode, rqname, i, '현재가n')
            temp['전일대비기호n'] = self._get_comm_data(trcode, rqname, i, '전일대비기호n')
            temp['전일대비n'] = self._get_comm_data(trcode, rqname, i, '전일대비n')
            temp['등락률n'] = self._get_comm_data(trcode, rqname, i, '등락률n')
            temp['거래량n'] = self._get_comm_data(trcode, rqname, i, '거래량n')
            temp['누적거래량n'] = self._get_comm_data(trcode, rqname, i, '누적거래량n')
            self.opt20001_output['multi'].append(temp)

    def _opt20002(self, rqname, trcode):
        """
    	업종별주가요청
    	"""
        self.opt20002_output = {'multi': []}

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['종목코드'] = self._get_comm_data(trcode, rqname, i, '종목코드')
            temp['종목명'] = self._get_comm_data(trcode, rqname, i, '종목명')
            temp['현재가'] = self._get_comm_data(trcode, rqname, i, '현재가')
            temp['전일대비기호'] = self._get_comm_data(trcode, rqname, i, '전일대비기호')
            temp['전일대비'] = self._get_comm_data(trcode, rqname, i, '전일대비')
            temp['등락률'] = self._get_comm_data(trcode, rqname, i, '등락률')
            temp['현재거래량'] = self._get_comm_data(trcode, rqname, i, '현재거래량')
            temp['매도호가'] = self._get_comm_data(trcode, rqname, i, '매도호가')
            temp['매수호가'] = self._get_comm_data(trcode, rqname, i, '매수호가')
            temp['시가'] = self._get_comm_data(trcode, rqname, i, '시가')
            temp['고가'] = self._get_comm_data(trcode, rqname, i, '고가')
            temp['저가'] = self._get_comm_data(trcode, rqname, i, '저가')
            self.opt20002_output['multi'].append(temp)

    def _opt20003(self, rqname, trcode):
        """
    	전업종지수요청
    	"""
        self.opt20003_output = {'multi': []}

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['종목코드'] = self._get_comm_data(trcode, rqname, i, '종목코드')
            temp['종목명'] = self._get_comm_data(trcode, rqname, i, '종목명')
            temp['현재가'] = self._get_comm_data(trcode, rqname, i, '현재가')
            temp['대비기호'] = self._get_comm_data(trcode, rqname, i, '대비기호')
            temp['전일대비'] = self._get_comm_data(trcode, rqname, i, '전일대비')
            temp['등락률'] = self._get_comm_data(trcode, rqname, i, '등락률')
            temp['거래량'] = self._get_comm_data(trcode, rqname, i, '거래량')
            temp['비중'] = self._get_comm_data(trcode, rqname, i, '비중')
            temp['거래대금'] = self._get_comm_data(trcode, rqname, i, '거래대금')
            temp['상한'] = self._get_comm_data(trcode, rqname, i, '상한')
            temp['상승'] = self._get_comm_data(trcode, rqname, i, '상승')
            temp['보합'] = self._get_comm_data(trcode, rqname, i, '보합')
            temp['하락'] = self._get_comm_data(trcode, rqname, i, '하락')
            temp['하한'] = self._get_comm_data(trcode, rqname, i, '하한')
            temp['상장종목수'] = self._get_comm_data(trcode, rqname, i, '상장종목수')
            self.opt20003_output['multi'].append(temp)

    def _opt20004(self, rqname, trcode):
        """
    	업종틱차트조회요청
    	"""
        self.opt20004_output = {'single': dict(), 'multi': []}

        self.opt20004_output['single']['업종코드'] = self._get_comm_data(trcode, rqname, 0, '업종코드')

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['현재가'] = self._get_comm_data(trcode, rqname, i, '현재가')
            temp['거래량'] = self._get_comm_data(trcode, rqname, i, '거래량')
            temp['체결시간'] = self._get_comm_data(trcode, rqname, i, '체결시간')
            temp['시가'] = self._get_comm_data(trcode, rqname, i, '시가')
            temp['고가'] = self._get_comm_data(trcode, rqname, i, '고가')
            temp['저가'] = self._get_comm_data(trcode, rqname, i, '저가')
            temp['대업종구분'] = self._get_comm_data(trcode, rqname, i, '대업종구분')
            temp['소업종구분'] = self._get_comm_data(trcode, rqname, i, '소업종구분')
            temp['종목정보'] = self._get_comm_data(trcode, rqname, i, '종목정보')
            temp['전일종가'] = self._get_comm_data(trcode, rqname, i, '전일종가')
            self.opt20004_output['multi'].append(temp)

    def _opt20005(self, rqname, trcode):
        """
    	업종분봉조회요청
    	"""
        self.opt20005_output = {'single': dict(), 'multi': []}

        self.opt20005_output['single']['업종코드'] = self._get_comm_data(trcode, rqname, 0, '업종코드')

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['현재가'] = self._get_comm_data(trcode, rqname, i, '현재가')
            temp['거래량'] = self._get_comm_data(trcode, rqname, i, '거래량')
            temp['체결시간'] = self._get_comm_data(trcode, rqname, i, '체결시간')
            temp['시가'] = self._get_comm_data(trcode, rqname, i, '시가')
            temp['고가'] = self._get_comm_data(trcode, rqname, i, '고가')
            temp['저가'] = self._get_comm_data(trcode, rqname, i, '저가')
            temp['대업종구분'] = self._get_comm_data(trcode, rqname, i, '대업종구분')
            temp['소업종구분'] = self._get_comm_data(trcode, rqname, i, '소업종구분')
            temp['종목정보'] = self._get_comm_data(trcode, rqname, i, '종목정보')
            temp['전일종가'] = self._get_comm_data(trcode, rqname, i, '전일종가')
            self.opt20005_output['multi'].append(temp)

    def _opt20006(self, rqname, trcode):
        """
    	업종일봉조회요청
    	"""
        self.opt20006_output = {'single': dict(), 'multi': []}

        self.opt20006_output['single']['업종코드'] = self._get_comm_data(trcode, rqname, 0, '업종코드')

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['현재가'] = self._get_comm_data(trcode, rqname, i, '현재가')
            temp['거래량'] = self._get_comm_data(trcode, rqname, i, '거래량')
            temp['일자'] = self._get_comm_data(trcode, rqname, i, '일자')
            temp['시가'] = self._get_comm_data(trcode, rqname, i, '시가')
            temp['고가'] = self._get_comm_data(trcode, rqname, i, '고가')
            temp['저가'] = self._get_comm_data(trcode, rqname, i, '저가')
            temp['거래대금'] = self._get_comm_data(trcode, rqname, i, '거래대금')
            temp['대업종구분'] = self._get_comm_data(trcode, rqname, i, '대업종구분')
            temp['소업종구분'] = self._get_comm_data(trcode, rqname, i, '소업종구분')
            temp['종목정보'] = self._get_comm_data(trcode, rqname, i, '종목정보')
            temp['전일종가'] = self._get_comm_data(trcode, rqname, i, '전일종가')
            self.opt20006_output['multi'].append(temp)

    def _opt20007(self, rqname, trcode):
        """
    	업종주봉조회요청
    	"""
        self.opt20007_output = {'single': dict(), 'multi': []}

        self.opt20007_output['single']['업종코드'] = self._get_comm_data(trcode, rqname, 0, '업종코드')

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['현재가'] = self._get_comm_data(trcode, rqname, i, '현재가')
            temp['거래량'] = self._get_comm_data(trcode, rqname, i, '거래량')
            temp['일자'] = self._get_comm_data(trcode, rqname, i, '일자')
            temp['시가'] = self._get_comm_data(trcode, rqname, i, '시가')
            temp['고가'] = self._get_comm_data(trcode, rqname, i, '고가')
            temp['저가'] = self._get_comm_data(trcode, rqname, i, '저가')
            temp['거래대금'] = self._get_comm_data(trcode, rqname, i, '거래대금')
            temp['대업종구분'] = self._get_comm_data(trcode, rqname, i, '대업종구분')
            temp['소업종구분'] = self._get_comm_data(trcode, rqname, i, '소업종구분')
            temp['종목정보'] = self._get_comm_data(trcode, rqname, i, '종목정보')
            temp['전일종가'] = self._get_comm_data(trcode, rqname, i, '전일종가')
            self.opt20007_output['multi'].append(temp)

    def _opt20008(self, rqname, trcode):
        """
    	업종월봉조회요청
    	"""
        self.opt20008_output = {'single': dict(), 'multi': []}

        self.opt20008_output['single']['업종코드'] = self._get_comm_data(trcode, rqname, 0, '업종코드')

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['현재가'] = self._get_comm_data(trcode, rqname, i, '현재가')
            temp['거래량'] = self._get_comm_data(trcode, rqname, i, '거래량')
            temp['일자'] = self._get_comm_data(trcode, rqname, i, '일자')
            temp['시가'] = self._get_comm_data(trcode, rqname, i, '시가')
            temp['고가'] = self._get_comm_data(trcode, rqname, i, '고가')
            temp['저가'] = self._get_comm_data(trcode, rqname, i, '저가')
            temp['거래대금'] = self._get_comm_data(trcode, rqname, i, '거래대금')
            temp['대업종구분'] = self._get_comm_data(trcode, rqname, i, '대업종구분')
            temp['소업종구분'] = self._get_comm_data(trcode, rqname, i, '소업종구분')
            temp['종목정보'] = self._get_comm_data(trcode, rqname, i, '종목정보')
            temp['전일종가'] = self._get_comm_data(trcode, rqname, i, '전일종가')
            self.opt20008_output['multi'].append(temp)

    def _opt20009(self, rqname, trcode):
        """
    	업종현재가일별요청
    	"""
        self.opt20009_output = {'single': dict(), 'multi': []}

        self.opt20009_output['single']['현재가'] = self._get_comm_data(trcode, rqname, 0, '현재가')
        self.opt20009_output['single']['전일대비기호'] = self._get_comm_data(trcode, rqname, 0, '전일대비기호')
        self.opt20009_output['single']['전일대비'] = self._get_comm_data(trcode, rqname, 0, '전일대비')
        self.opt20009_output['single']['등락률'] = self._get_comm_data(trcode, rqname, 0, '등락률')
        self.opt20009_output['single']['거래량'] = self._get_comm_data(trcode, rqname, 0, '거래량')
        self.opt20009_output['single']['거래대금'] = self._get_comm_data(trcode, rqname, 0, '거래대금')
        self.opt20009_output['single']['거래형성종목수  '] = self._get_comm_data(trcode, rqname, 0, '거래형성종목수  ')
        self.opt20009_output['single']['거래형성비율    '] = self._get_comm_data(trcode, rqname, 0, '거래형성비율    ')
        self.opt20009_output['single']['시가  '] = self._get_comm_data(trcode, rqname, 0, '시가  ')
        self.opt20009_output['single']['고가'] = self._get_comm_data(trcode, rqname, 0, '고가')
        self.opt20009_output['single']['저가'] = self._get_comm_data(trcode, rqname, 0, '저가')
        self.opt20009_output['single']['상한'] = self._get_comm_data(trcode, rqname, 0, '상한')
        self.opt20009_output['single']['상승'] = self._get_comm_data(trcode, rqname, 0, '상승')
        self.opt20009_output['single']['보합'] = self._get_comm_data(trcode, rqname, 0, '보합')
        self.opt20009_output['single']['하락'] = self._get_comm_data(trcode, rqname, 0, '하락')
        self.opt20009_output['single']['하한'] = self._get_comm_data(trcode, rqname, 0, '하한')
        self.opt20009_output['single']['52주최고가 '] = self._get_comm_data(trcode, rqname, 0, '52주최고가 ')
        self.opt20009_output['single']['52주최고가일'] = self._get_comm_data(trcode, rqname, 0, '52주최고가일')
        self.opt20009_output['single']['52주최고가대비율'] = self._get_comm_data(trcode, rqname, 0, '52주최고가대비율')
        self.opt20009_output['single']['52주최저가 '] = self._get_comm_data(trcode, rqname, 0, '52주최저가 ')
        self.opt20009_output['single']['52주최저가일'] = self._get_comm_data(trcode, rqname, 0, '52주최저가일')
        self.opt20009_output['single']['52주최저가대비율'] = self._get_comm_data(trcode, rqname, 0, '52주최저가대비율')

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['일자n    '] = self._get_comm_data(trcode, rqname, i, '일자n    ')
            temp['현재가n'] = self._get_comm_data(trcode, rqname, i, '현재가n')
            temp['전일대비기호n'] = self._get_comm_data(trcode, rqname, i, '전일대비기호n')
            temp['전일대비n'] = self._get_comm_data(trcode, rqname, i, '전일대비n')
            temp['등락률n'] = self._get_comm_data(trcode, rqname, i, '등락률n')
            temp['누적거래량n'] = self._get_comm_data(trcode, rqname, i, '누적거래량n')
            self.opt20009_output['multi'].append(temp)

    def _opt20019(self, rqname, trcode):
        """
    	업종년봉조회요청
    	"""
        self.opt20019_output = {'single': dict(), 'multi': []}

        self.opt20019_output['single']['업종코드'] = self._get_comm_data(trcode, rqname, 0, '업종코드')

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['현재가'] = self._get_comm_data(trcode, rqname, i, '현재가')
            temp['거래량'] = self._get_comm_data(trcode, rqname, i, '거래량')
            temp['일자'] = self._get_comm_data(trcode, rqname, i, '일자')
            temp['시가'] = self._get_comm_data(trcode, rqname, i, '시가')
            temp['고가'] = self._get_comm_data(trcode, rqname, i, '고가')
            temp['저가'] = self._get_comm_data(trcode, rqname, i, '저가')
            temp['거래대금'] = self._get_comm_data(trcode, rqname, i, '거래대금')
            temp['대업종구분'] = self._get_comm_data(trcode, rqname, i, '대업종구분')
            temp['소업종구분'] = self._get_comm_data(trcode, rqname, i, '소업종구분')
            temp['종목정보'] = self._get_comm_data(trcode, rqname, i, '종목정보')
            temp['전일종가'] = self._get_comm_data(trcode, rqname, i, '전일종가')
            self.opt20019_output['multi'].append(temp)

    def _opt20068(self, rqname, trcode):
        """
    	대차거래추이요청(종목별)
    	"""
        self.opt20068_output = {'multi': []}

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['일자'] = self._get_comm_data(trcode, rqname, i, '일자')
            temp['대차거래체결주수'] = self._get_comm_data(trcode, rqname, i, '대차거래체결주수')
            temp['대차거래상환주수'] = self._get_comm_data(trcode, rqname, i, '대차거래상환주수')
            temp['대차거래증감'] = self._get_comm_data(trcode, rqname, i, '대차거래증감')
            temp['잔고주수'] = self._get_comm_data(trcode, rqname, i, '잔고주수')
            temp['잔고금액'] = self._get_comm_data(trcode, rqname, i, '잔고금액')
            self.opt20068_output['multi'].append(temp)

    def _opt30001(self, rqname, trcode):
        """
    	ELW가격급등락요청
    	"""
        self.opt30001_output = {'single': dict(), 'multi': []}

        self.opt30001_output['single']['기준가시간'] = self._get_comm_data(trcode, rqname, 0, '기준가시간')

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['종목코드'] = self._get_comm_data(trcode, rqname, i, '종목코드')
            temp['순위'] = self._get_comm_data(trcode, rqname, i, '순위')
            temp['종목명'] = self._get_comm_data(trcode, rqname, i, '종목명')
            temp['대비기호'] = self._get_comm_data(trcode, rqname, i, '대비기호')
            temp['전일대비'] = self._get_comm_data(trcode, rqname, i, '전일대비')
            temp['거래종료ELW기준가'] = self._get_comm_data(trcode, rqname, i, '거래종료ELW기준가')
            temp['현재가'] = self._get_comm_data(trcode, rqname, i, '현재가')
            temp['기준대비'] = self._get_comm_data(trcode, rqname, i, '기준대비')
            temp['거래량'] = self._get_comm_data(trcode, rqname, i, '거래량')
            temp['급등율'] = self._get_comm_data(trcode, rqname, i, '급등율')
            self.opt30001_output['multi'].append(temp)

    def _opt30002(self, rqname, trcode):
        """
    	거래원별ELW순매매상위요청
    	"""
        self.opt30002_output = {'multi': []}

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['종목코드'] = self._get_comm_data(trcode, rqname, i, '종목코드')
            temp['종목명'] = self._get_comm_data(trcode, rqname, i, '종목명')
            temp['주가등락'] = self._get_comm_data(trcode, rqname, i, '주가등락')
            temp['등락율'] = self._get_comm_data(trcode, rqname, i, '등락율')
            temp['거래량'] = self._get_comm_data(trcode, rqname, i, '거래량')
            temp['순매수'] = self._get_comm_data(trcode, rqname, i, '순매수')
            temp['매수거래량'] = self._get_comm_data(trcode, rqname, i, '매수거래량')
            temp['매도거래량'] = self._get_comm_data(trcode, rqname, i, '매도거래량')
            self.opt30002_output['multi'].append(temp)

    def _opt30003(self, rqname, trcode):
        """
    	ELWLP보유일별추이요청
    	"""
        self.opt30003_output = {'multi': []}

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['일자'] = self._get_comm_data(trcode, rqname, i, '일자')
            temp['현재가'] = self._get_comm_data(trcode, rqname, i, '현재가')
            temp['대비구분'] = self._get_comm_data(trcode, rqname, i, '대비구분')
            temp['전일대비'] = self._get_comm_data(trcode, rqname, i, '전일대비')
            temp['등락율'] = self._get_comm_data(trcode, rqname, i, '등락율')
            temp['거래량'] = self._get_comm_data(trcode, rqname, i, '거래량')
            temp['거래대금'] = self._get_comm_data(trcode, rqname, i, '거래대금')
            temp['변동수량'] = self._get_comm_data(trcode, rqname, i, '변동수량')
            temp['LP보유수량'] = self._get_comm_data(trcode, rqname, i, 'LP보유수량')
            temp['비중'] = self._get_comm_data(trcode, rqname, i, '비중')
            self.opt30003_output['multi'].append(temp)

    def _opt30004(self, rqname, trcode):
        """
    	ELW괴리율요청
    	"""
        self.opt30004_output = {'multi': []}

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['종목코드'] = self._get_comm_data(trcode, rqname, i, '종목코드')
            temp['발행사명'] = self._get_comm_data(trcode, rqname, i, '발행사명')
            temp['회차'] = self._get_comm_data(trcode, rqname, i, '회차')
            temp['기초자산명'] = self._get_comm_data(trcode, rqname, i, '기초자산명')
            temp['권리구분'] = self._get_comm_data(trcode, rqname, i, '권리구분')
            temp['괴리율'] = self._get_comm_data(trcode, rqname, i, '괴리율')
            temp['베이시스'] = self._get_comm_data(trcode, rqname, i, '베이시스')
            temp['잔존일수'] = self._get_comm_data(trcode, rqname, i, '잔존일수')
            temp['이론가'] = self._get_comm_data(trcode, rqname, i, '이론가')
            temp['현재가'] = self._get_comm_data(trcode, rqname, i, '현재가')
            temp['대비구분'] = self._get_comm_data(trcode, rqname, i, '대비구분')
            temp['전일대비'] = self._get_comm_data(trcode, rqname, i, '전일대비')
            temp['등락율'] = self._get_comm_data(trcode, rqname, i, '등락율')
            temp['거래량'] = self._get_comm_data(trcode, rqname, i, '거래량')
            temp['종목명'] = self._get_comm_data(trcode, rqname, i, '종목명')
            self.opt30004_output['multi'].append(temp)

    def _opt30005(self, rqname, trcode):
        """
    	ELW조건검색요청
    	"""
        self.opt30005_output = {'multi': []}

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['종목코드'] = self._get_comm_data(trcode, rqname, i, '종목코드')
            temp['발행사명'] = self._get_comm_data(trcode, rqname, i, '발행사명')
            temp['회차'] = self._get_comm_data(trcode, rqname, i, '회차')
            temp['기초자산명'] = self._get_comm_data(trcode, rqname, i, '기초자산명')
            temp['권리구분'] = self._get_comm_data(trcode, rqname, i, '권리구분')
            temp['만기일'] = self._get_comm_data(trcode, rqname, i, '만기일')
            temp['현재가'] = self._get_comm_data(trcode, rqname, i, '현재가')
            temp['대비구분'] = self._get_comm_data(trcode, rqname, i, '대비구분')
            temp['전일대비'] = self._get_comm_data(trcode, rqname, i, '전일대비')
            temp['등락율'] = self._get_comm_data(trcode, rqname, i, '등락율')
            temp['거래량'] = self._get_comm_data(trcode, rqname, i, '거래량')
            temp['거래량대비'] = self._get_comm_data(trcode, rqname, i, '거래량대비')
            temp['거래대금'] = self._get_comm_data(trcode, rqname, i, '거래대금')
            temp['전일거래량'] = self._get_comm_data(trcode, rqname, i, '전일거래량')
            temp['매도호가'] = self._get_comm_data(trcode, rqname, i, '매도호가')
            temp['매수호가'] = self._get_comm_data(trcode, rqname, i, '매수호가')
            temp['패리티'] = self._get_comm_data(trcode, rqname, i, '패리티')
            temp['기어링비율'] = self._get_comm_data(trcode, rqname, i, '기어링비율')
            temp['손익분기율'] = self._get_comm_data(trcode, rqname, i, '손익분기율')
            temp['자본지지점'] = self._get_comm_data(trcode, rqname, i, '자본지지점')
            temp['이론가'] = self._get_comm_data(trcode, rqname, i, '이론가')
            temp['내재변동성'] = self._get_comm_data(trcode, rqname, i, '내재변동성')
            temp['델타'] = self._get_comm_data(trcode, rqname, i, '델타')
            temp['레버리지'] = self._get_comm_data(trcode, rqname, i, '레버리지')
            temp['행사가격'] = self._get_comm_data(trcode, rqname, i, '행사가격')
            temp['전환비율'] = self._get_comm_data(trcode, rqname, i, '전환비율')
            temp['LP보유비율'] = self._get_comm_data(trcode, rqname, i, 'LP보유비율')
            temp['손익분기점'] = self._get_comm_data(trcode, rqname, i, '손익분기점')
            temp['최종거래일'] = self._get_comm_data(trcode, rqname, i, '최종거래일')
            temp['상장일'] = self._get_comm_data(trcode, rqname, i, '상장일')
            temp['LP초종공급일'] = self._get_comm_data(trcode, rqname, i, 'LP초종공급일')
            temp['종목명'] = self._get_comm_data(trcode, rqname, i, '종목명')
            temp['잔존일수'] = self._get_comm_data(trcode, rqname, i, '잔존일수')
            temp['괴리율'] = self._get_comm_data(trcode, rqname, i, '괴리율')
            temp['LP회원사명'] = self._get_comm_data(trcode, rqname, i, 'LP회원사명')
            temp['LP회원사명1'] = self._get_comm_data(trcode, rqname, i, 'LP회원사명1')
            temp['LP회원사명2'] = self._get_comm_data(trcode, rqname, i, 'LP회원사명2')
            temp['Xray순간체결량정리매매구분'] = self._get_comm_data(trcode, rqname, i, 'Xray순간체결량정리매매구분')
            temp['Xray순간체결량증거금100구분'] = self._get_comm_data(trcode, rqname, i, 'Xray순간체결량증거금100구분')
            self.opt30005_output['multi'].append(temp)

    def _opt30006(self, rqname, trcode):
        """
    	ELW종목상세요청
    	"""
        self.opt30006_output = {'single': dict()}

        self.opt30006_output['single']['조기종료여부'] = self._get_comm_data(trcode, rqname, 0, '조기종료여부')

    def _opt30007(self, rqname, trcode):
        """
    	ELW종목상세요청
    	"""
        self.opt30007_output = {'multi': []}

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['기초자산코드'] = self._get_comm_data(trcode, rqname, i, '기초자산코드')
            temp['발행사명'] = self._get_comm_data(trcode, rqname, i, '발행사명')
            temp['회차'] = self._get_comm_data(trcode, rqname, i, '회차')
            temp['기초자산명'] = self._get_comm_data(trcode, rqname, i, '기초자산명')
            temp['콜풋구분'] = self._get_comm_data(trcode, rqname, i, '콜풋구분')
            temp['신주인수권행사종료일'] = self._get_comm_data(trcode, rqname, i, '신주인수권행사종료일')
            temp['잔존일수'] = self._get_comm_data(trcode, rqname, i, '잔존일수')
            temp['현재가'] = self._get_comm_data(trcode, rqname, i, '현재가')
            temp['대비기호'] = self._get_comm_data(trcode, rqname, i, '대비기호')
            temp['전일대비'] = self._get_comm_data(trcode, rqname, i, '전일대비')
            temp['등락율'] = self._get_comm_data(trcode, rqname, i, '등락율')
            temp['누적거래량'] = self._get_comm_data(trcode, rqname, i, '누적거래량')
            temp['거래량대비'] = self._get_comm_data(trcode, rqname, i, '거래량대비')
            temp['누적거래대금'] = self._get_comm_data(trcode, rqname, i, '누적거래대금')
            temp['매도호가'] = self._get_comm_data(trcode, rqname, i, '매도호가')
            temp['매수호가'] = self._get_comm_data(trcode, rqname, i, '매수호가')
            temp['패리티'] = self._get_comm_data(trcode, rqname, i, '패리티')
            temp['기어링비율'] = self._get_comm_data(trcode, rqname, i, '기어링비율')
            temp['손익분기율'] = self._get_comm_data(trcode, rqname, i, '손익분기율')
            temp['자본지지점'] = self._get_comm_data(trcode, rqname, i, '자본지지점')
            temp['이론가'] = self._get_comm_data(trcode, rqname, i, '이론가')
            temp['내재변동성'] = self._get_comm_data(trcode, rqname, i, '내재변동성')
            temp['델타'] = self._get_comm_data(trcode, rqname, i, '델타')
            temp['레버리지'] = self._get_comm_data(trcode, rqname, i, '레버리지')
            temp['LP보유비율'] = self._get_comm_data(trcode, rqname, i, 'LP보유비율')
            temp['행사가격'] = self._get_comm_data(trcode, rqname, i, '행사가격')
            temp['전환비율'] = self._get_comm_data(trcode, rqname, i, '전환비율')
            temp['최종거래일'] = self._get_comm_data(trcode, rqname, i, '최종거래일')
            temp['종목명'] = self._get_comm_data(trcode, rqname, i, '종목명')
            temp['조기종료여부'] = self._get_comm_data(trcode, rqname, i, '조기종료여부')
            temp['KO접근도'] = self._get_comm_data(trcode, rqname, i, 'KO접근도')
            self.opt30007_output['multi'].append(temp)

    def _opt30008(self, rqname, trcode):
        """
    	ELW민감도지표요청
    	"""
        self.opt30008_output = {'multi': []}

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['체결시간'] = self._get_comm_data(trcode, rqname, i, '체결시간')
            temp['내재변동성'] = self._get_comm_data(trcode, rqname, i, '내재변동성')
            temp['델타'] = self._get_comm_data(trcode, rqname, i, '델타')
            temp['감마'] = self._get_comm_data(trcode, rqname, i, '감마')
            temp['쎄타'] = self._get_comm_data(trcode, rqname, i, '쎄타')
            temp['베가'] = self._get_comm_data(trcode, rqname, i, '베가')
            temp['로'] = self._get_comm_data(trcode, rqname, i, '로')
            temp['X-Ray순간체결량증거금100%구분'] = self._get_comm_data(trcode, rqname, i, 'X-Ray순간체결량증거금100%구분')
            self.opt30008_output['multi'].append(temp)

    def _opt30009(self, rqname, trcode):
        """
    	ELW등락율순위요청
    	"""
        self.opt30009_output = {'multi': []}

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['순위'] = self._get_comm_data(trcode, rqname, i, '순위')
            temp['종목코드'] = self._get_comm_data(trcode, rqname, i, '종목코드')
            temp['종목명'] = self._get_comm_data(trcode, rqname, i, '종목명')
            temp['현재가'] = self._get_comm_data(trcode, rqname, i, '현재가')
            temp['대비기호'] = self._get_comm_data(trcode, rqname, i, '대비기호')
            temp['전일대비'] = self._get_comm_data(trcode, rqname, i, '전일대비')
            temp['등락률'] = self._get_comm_data(trcode, rqname, i, '등락률')
            temp['매도잔량'] = self._get_comm_data(trcode, rqname, i, '매도잔량')
            temp['매수잔량'] = self._get_comm_data(trcode, rqname, i, '매수잔량')
            temp['거래량'] = self._get_comm_data(trcode, rqname, i, '거래량')
            temp['거래대금'] = self._get_comm_data(trcode, rqname, i, '거래대금')
            self.opt30009_output['multi'].append(temp)

    def _opt30010(self, rqname, trcode):
        """
    	ELW잔량순위요청
    	"""
        self.opt30010_output = {'multi': []}

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['종목코드'] = self._get_comm_data(trcode, rqname, i, '종목코드')
            temp['순위'] = self._get_comm_data(trcode, rqname, i, '순위')
            temp['종목명'] = self._get_comm_data(trcode, rqname, i, '종목명')
            temp['현재가'] = self._get_comm_data(trcode, rqname, i, '현재가')
            temp['대비기호'] = self._get_comm_data(trcode, rqname, i, '대비기호')
            temp['전일대비'] = self._get_comm_data(trcode, rqname, i, '전일대비')
            temp['등락률'] = self._get_comm_data(trcode, rqname, i, '등락률')
            temp['거래량'] = self._get_comm_data(trcode, rqname, i, '거래량')
            temp['매도잔량'] = self._get_comm_data(trcode, rqname, i, '매도잔량')
            temp['매수잔량'] = self._get_comm_data(trcode, rqname, i, '매수잔량')
            temp['순매수잔량'] = self._get_comm_data(trcode, rqname, i, '순매수잔량')
            temp['거래대금'] = self._get_comm_data(trcode, rqname, i, '거래대금')
            self.opt30010_output['multi'].append(temp)

    def _opt30011(self, rqname, trcode):
        """
    	ELW근접율요청
    	"""
        self.opt30011_output = {'multi': []}

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['종목코드'] = self._get_comm_data(trcode, rqname, i, '종목코드')
            temp['종목명'] = self._get_comm_data(trcode, rqname, i, '종목명')
            temp['현재가'] = self._get_comm_data(trcode, rqname, i, '현재가')
            temp['대비기호'] = self._get_comm_data(trcode, rqname, i, '대비기호')
            temp['전일대비'] = self._get_comm_data(trcode, rqname, i, '전일대비')
            temp['등락율'] = self._get_comm_data(trcode, rqname, i, '등락율')
            temp['누적거래량'] = self._get_comm_data(trcode, rqname, i, '누적거래량')
            temp['근접율'] = self._get_comm_data(trcode, rqname, i, '근접율')
            self.opt30011_output['multi'].append(temp)

    def _opt30012(self, rqname, trcode):
        """
    	ELW종목상세정보요청
    	"""
        self.opt30012_output = {'single': dict()}

        self.opt30012_output['single']['자산코드'] = self._get_comm_data(trcode, rqname, 0, '자산코드')
        self.opt30012_output['single']['현재가'] = self._get_comm_data(trcode, rqname, 0, '현재가')
        self.opt30012_output['single']['전일대비기호'] = self._get_comm_data(trcode, rqname, 0, '전일대비기호')
        self.opt30012_output['single']['전일대비'] = self._get_comm_data(trcode, rqname, 0, '전일대비')
        self.opt30012_output['single']['등락율'] = self._get_comm_data(trcode, rqname, 0, '등락율')
        self.opt30012_output['single']['LP회원사명'] = self._get_comm_data(trcode, rqname, 0, 'LP회원사명')
        self.opt30012_output['single']['LP회원사명1'] = self._get_comm_data(trcode, rqname, 0, 'LP회원사명1')
        self.opt30012_output['single']['LP회원사명2'] = self._get_comm_data(trcode, rqname, 0, 'LP회원사명2')
        self.opt30012_output['single']['ELW권리내용'] = self._get_comm_data(trcode, rqname, 0, 'ELW권리내용')
        self.opt30012_output['single']['ELW만기평가가격'] = self._get_comm_data(trcode, rqname, 0, 'ELW만기평가가격')
        self.opt30012_output['single']['ELW이론가'] = self._get_comm_data(trcode, rqname, 0, 'ELW이론가')
        self.opt30012_output['single']['괴리율'] = self._get_comm_data(trcode, rqname, 0, '괴리율')
        self.opt30012_output['single']['ELW내재변동성'] = self._get_comm_data(trcode, rqname, 0, 'ELW내재변동성')
        self.opt30012_output['single']['예상권리가'] = self._get_comm_data(trcode, rqname, 0, '예상권리가')
        self.opt30012_output['single']['ELW손익분기율'] = self._get_comm_data(trcode, rqname, 0, 'ELW손익분기율')
        self.opt30012_output['single']['ELW행사가'] = self._get_comm_data(trcode, rqname, 0, 'ELW행사가')
        self.opt30012_output['single']['ELW전환비율'] = self._get_comm_data(trcode, rqname, 0, 'ELW전환비율')
        self.opt30012_output['single']['ELW보상율'] = self._get_comm_data(trcode, rqname, 0, 'ELW보상율')
        self.opt30012_output['single']['ELW가격상승참여율'] = self._get_comm_data(trcode, rqname, 0, 'ELW가격상승참여율')
        self.opt30012_output['single']['ELW권리유형'] = self._get_comm_data(trcode, rqname, 0, 'ELW권리유형')
        self.opt30012_output['single']['ELW잔존일수'] = self._get_comm_data(trcode, rqname, 0, 'ELW잔존일수')
        self.opt30012_output['single']['주식수'] = self._get_comm_data(trcode, rqname, 0, '주식수')
        self.opt30012_output['single']['ELW LP주문가능'] = self._get_comm_data(trcode, rqname, 0, 'ELW LP주문가능')
        self.opt30012_output['single']['LP보유비율'] = self._get_comm_data(trcode, rqname, 0, 'LP보유비율')
        self.opt30012_output['single']['LP보유수량'] = self._get_comm_data(trcode, rqname, 0, 'LP보유수량')
        self.opt30012_output['single']['ELW스프레드'] = self._get_comm_data(trcode, rqname, 0, 'ELW스프레드')
        self.opt30012_output['single']['ELW패리티'] = self._get_comm_data(trcode, rqname, 0, 'ELW패리티')
        self.opt30012_output['single']['ELW기어링'] = self._get_comm_data(trcode, rqname, 0, 'ELW기어링')
        self.opt30012_output['single']['ELW상장일'] = self._get_comm_data(trcode, rqname, 0, 'ELW상장일')
        self.opt30012_output['single']['ELW최종거래일'] = self._get_comm_data(trcode, rqname, 0, 'ELW최종거래일')
        self.opt30012_output['single']['만기일'] = self._get_comm_data(trcode, rqname, 0, '만기일')
        self.opt30012_output['single']['행사일'] = self._get_comm_data(trcode, rqname, 0, '행사일')
        self.opt30012_output['single']['LP공급종료일'] = self._get_comm_data(trcode, rqname, 0, 'LP공급종료일')
        self.opt30012_output['single']['ELW지급일'] = self._get_comm_data(trcode, rqname, 0, 'ELW지급일')
        self.opt30012_output['single']['ELW투자지표산출'] = self._get_comm_data(trcode, rqname, 0, 'ELW투자지표산출')
        self.opt30012_output['single']['ELW지급대리인'] = self._get_comm_data(trcode, rqname, 0, 'ELW지급대리인')
        self.opt30012_output['single']['ELW결재방법'] = self._get_comm_data(trcode, rqname, 0, 'ELW결재방법')
        self.opt30012_output['single']['ELW권리행사방식'] = self._get_comm_data(trcode, rqname, 0, 'ELW권리행사방식')
        self.opt30012_output['single']['ELW발행기관'] = self._get_comm_data(trcode, rqname, 0, 'ELW발행기관')
        self.opt30012_output['single']['확정지급액'] = self._get_comm_data(trcode, rqname, 0, '확정지급액')
        self.opt30012_output['single']['KO베리어'] = self._get_comm_data(trcode, rqname, 0, 'KO베리어')
        self.opt30012_output['single']['IV'] = self._get_comm_data(trcode, rqname, 0, 'IV')
        self.opt30012_output['single']['종기종료ELW발생'] = self._get_comm_data(trcode, rqname, 0, '종기종료ELW발생')
        self.opt30012_output['single']['기초자산1'] = self._get_comm_data(trcode, rqname, 0, '기초자산1')
        self.opt30012_output['single']['기초자산구성비율1'] = self._get_comm_data(trcode, rqname, 0, '기초자산구성비율1')
        self.opt30012_output['single']['기초자산2'] = self._get_comm_data(trcode, rqname, 0, '기초자산2')
        self.opt30012_output['single']['기초자산구성비율2'] = self._get_comm_data(trcode, rqname, 0, '기초자산구성비율2')
        self.opt30012_output['single']['기초자산3'] = self._get_comm_data(trcode, rqname, 0, '기초자산3')
        self.opt30012_output['single']['기초자산구성비율3'] = self._get_comm_data(trcode, rqname, 0, '기초자산구성비율3')
        self.opt30012_output['single']['기초자산4'] = self._get_comm_data(trcode, rqname, 0, '기초자산4')
        self.opt30012_output['single']['기초자산구성비율4'] = self._get_comm_data(trcode, rqname, 0, '기초자산구성비율4')
        self.opt30012_output['single']['기초자산5'] = self._get_comm_data(trcode, rqname, 0, '기초자산5')
        self.opt30012_output['single']['기초자산구성비율5'] = self._get_comm_data(trcode, rqname, 0, '기초자산구성비율5')
        self.opt30012_output['single']['평가시작일자'] = self._get_comm_data(trcode, rqname, 0, '평가시작일자')
        self.opt30012_output['single']['평가종료일자'] = self._get_comm_data(trcode, rqname, 0, '평가종료일자')
        self.opt30012_output['single']['평가시작시간'] = self._get_comm_data(trcode, rqname, 0, '평가시작시간')
        self.opt30012_output['single']['평가종료시간'] = self._get_comm_data(trcode, rqname, 0, '평가종료시간')
        self.opt30012_output['single']['평가가격'] = self._get_comm_data(trcode, rqname, 0, '평가가격')
        self.opt30012_output['single']['평가완료여부'] = self._get_comm_data(trcode, rqname, 0, '평가완료여부')
        self.opt30012_output['single']['전체최고가'] = self._get_comm_data(trcode, rqname, 0, '전체최고가')
        self.opt30012_output['single']['전체최저가'] = self._get_comm_data(trcode, rqname, 0, '전체최저가')
        self.opt30012_output['single']['직후최고가'] = self._get_comm_data(trcode, rqname, 0, '직후최고가')
        self.opt30012_output['single']['직후최저가'] = self._get_comm_data(trcode, rqname, 0, '직후최저가')
        self.opt30012_output['single']['후반장최고가'] = self._get_comm_data(trcode, rqname, 0, '후반장최고가')
        self.opt30012_output['single']['후반장최저가'] = self._get_comm_data(trcode, rqname, 0, '후반장최저가')

    def _opt40001(self, rqname, trcode):
        """
    	ETF수익율요청
    	"""
        self.opt40001_output = {'multi': []}

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['ETF수익률'] = self._get_comm_data(trcode, rqname, i, 'ETF수익률')
            temp['체결수익률'] = self._get_comm_data(trcode, rqname, i, '체결수익률')
            temp['외인순매수수량'] = self._get_comm_data(trcode, rqname, i, '외인순매수수량')
            temp['기관순매수수량'] = self._get_comm_data(trcode, rqname, i, '기관순매수수량')
            self.opt40001_output['multi'].append(temp)

    def _opt40002(self, rqname, trcode):
        """
    	ETF종목정보요청
    	"""
        self.opt40002_output = {'single': dict()}

        self.opt40002_output['single']['종목명'] = self._get_comm_data(trcode, rqname, 0, '종목명')
        self.opt40002_output['single']['ETF대상지수명'] = self._get_comm_data(trcode, rqname, 0, 'ETF대상지수명')
        self.opt40002_output['single']['원주가격'] = self._get_comm_data(trcode, rqname, 0, '원주가격')
        self.opt40002_output['single']['ETF과세유형'] = self._get_comm_data(trcode, rqname, 0, 'ETF과세유형')
        self.opt40002_output['single']['ETN과세유형'] = self._get_comm_data(trcode, rqname, 0, 'ETN과세유형')

    def _opt40003(self, rqname, trcode):
        """
    	ETF일별추이요청
    	"""
        self.opt40003_output = {'multi': []}

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['체결일자'] = self._get_comm_data(trcode, rqname, i, '체결일자')
            temp['현재가'] = self._get_comm_data(trcode, rqname, i, '현재가')
            temp['대비기호'] = self._get_comm_data(trcode, rqname, i, '대비기호')
            temp['전일대비'] = self._get_comm_data(trcode, rqname, i, '전일대비')
            temp['대비율'] = self._get_comm_data(trcode, rqname, i, '대비율')
            temp['거래량'] = self._get_comm_data(trcode, rqname, i, '거래량')
            temp['NAV'] = self._get_comm_data(trcode, rqname, i, 'NAV')
            temp['누적거래대금'] = self._get_comm_data(trcode, rqname, i, '누적거래대금')
            temp['NAV/지수괴리율'] = self._get_comm_data(trcode, rqname, i, 'NAV/지수괴리율')
            temp['NAV/ETF괴리율'] = self._get_comm_data(trcode, rqname, i, 'NAV/ETF괴리율')
            temp['추적오차율'] = self._get_comm_data(trcode, rqname, i, '추적오차율')
            temp['추적현재가'] = self._get_comm_data(trcode, rqname, i, '추적현재가')
            temp['추적전일대비'] = self._get_comm_data(trcode, rqname, i, '추적전일대비')
            temp['추적대비기호'] = self._get_comm_data(trcode, rqname, i, '추적대비기호')
            self.opt40003_output['multi'].append(temp)

    def _opt40004(self, rqname, trcode):
        """
    	ETF전체시세요청
    	"""
        self.opt40004_output = {'multi': []}

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['종목코드'] = self._get_comm_data(trcode, rqname, i, '종목코드')
            temp['종목분류'] = self._get_comm_data(trcode, rqname, i, '종목분류')
            temp['종목명'] = self._get_comm_data(trcode, rqname, i, '종목명')
            temp['종가'] = self._get_comm_data(trcode, rqname, i, '종가')
            temp['대비기호'] = self._get_comm_data(trcode, rqname, i, '대비기호')
            temp['전일대비'] = self._get_comm_data(trcode, rqname, i, '전일대비')
            temp['대비율'] = self._get_comm_data(trcode, rqname, i, '대비율')
            temp['거래량'] = self._get_comm_data(trcode, rqname, i, '거래량')
            temp['NAV'] = self._get_comm_data(trcode, rqname, i, 'NAV')
            temp['추적오차율'] = self._get_comm_data(trcode, rqname, i, '추적오차율')
            temp['과표기준'] = self._get_comm_data(trcode, rqname, i, '과표기준')
            temp['배당전기준'] = self._get_comm_data(trcode, rqname, i, '배당전기준')
            temp['전일배당금'] = self._get_comm_data(trcode, rqname, i, '전일배당금')
            temp['추적지수명'] = self._get_comm_data(trcode, rqname, i, '추적지수명')
            temp['배수'] = self._get_comm_data(trcode, rqname, i, '배수')
            temp['추적지수코드'] = self._get_comm_data(trcode, rqname, i, '추적지수코드')
            temp['추적지수'] = self._get_comm_data(trcode, rqname, i, '추적지수')
            temp['추적등락율'] = self._get_comm_data(trcode, rqname, i, '추적등락율')
            self.opt40004_output['multi'].append(temp)

    def _opt40005(self, rqname, trcode):
        """
    	ETF일별추이요청
    	"""
        self.opt40005_output = {'multi': []}

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['체결시간'] = self._get_comm_data(trcode, rqname, i, '체결시간')
            temp['종가'] = self._get_comm_data(trcode, rqname, i, '종가')
            temp['대비기호'] = self._get_comm_data(trcode, rqname, i, '대비기호')
            temp['전일대비'] = self._get_comm_data(trcode, rqname, i, '전일대비')
            temp['대비율'] = self._get_comm_data(trcode, rqname, i, '대비율')
            temp['거래량'] = self._get_comm_data(trcode, rqname, i, '거래량')
            temp['NAV'] = self._get_comm_data(trcode, rqname, i, 'NAV')
            temp['누적거래대금'] = self._get_comm_data(trcode, rqname, i, '누적거래대금')
            temp['NAV/지수괴리율'] = self._get_comm_data(trcode, rqname, i, 'NAV/지수괴리율')
            temp['NAV/ETF괴리율'] = self._get_comm_data(trcode, rqname, i, 'NAV/ETF괴리율')
            temp['추적오차율'] = self._get_comm_data(trcode, rqname, i, '추적오차율')
            temp['추적지수'] = self._get_comm_data(trcode, rqname, i, '추적지수')
            temp['추적대비기호'] = self._get_comm_data(trcode, rqname, i, '추적대비기호')
            temp['추적전일대비'] = self._get_comm_data(trcode, rqname, i, '추적전일대비')
            self.opt40005_output['multi'].append(temp)

    def _opt40006(self, rqname, trcode):
        """
    	ETF시간대별추이요청
    	"""
        self.opt40006_output = {'single': dict(), 'multi': []}

        self.opt40006_output['single']['종목명'] = self._get_comm_data(trcode, rqname, 0, '종목명')
        self.opt40006_output['single']['ETF대상지수명'] = self._get_comm_data(trcode, rqname, 0, 'ETF대상지수명')
        self.opt40006_output['single']['원주가격'] = self._get_comm_data(trcode, rqname, 0, '원주가격')
        self.opt40006_output['single']['ETF과세유형'] = self._get_comm_data(trcode, rqname, 0, 'ETF과세유형')
        self.opt40006_output['single']['ETN과세유형'] = self._get_comm_data(trcode, rqname, 0, 'ETN과세유형')

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['시간'] = self._get_comm_data(trcode, rqname, i, '시간')
            temp['종가'] = self._get_comm_data(trcode, rqname, i, '종가')
            temp['대비기호'] = self._get_comm_data(trcode, rqname, i, '대비기호')
            temp['전일대비'] = self._get_comm_data(trcode, rqname, i, '전일대비')
            temp['등락율'] = self._get_comm_data(trcode, rqname, i, '등락율')
            temp['거래량'] = self._get_comm_data(trcode, rqname, i, '거래량')
            temp['NAV'] = self._get_comm_data(trcode, rqname, i, 'NAV')
            temp['거래대금'] = self._get_comm_data(trcode, rqname, i, '거래대금')
            temp['NAV지수'] = self._get_comm_data(trcode, rqname, i, 'NAV지수')
            temp['NAVETF'] = self._get_comm_data(trcode, rqname, i, 'NAVETF')
            temp['추적'] = self._get_comm_data(trcode, rqname, i, '추적')
            temp['추적지수'] = self._get_comm_data(trcode, rqname, i, '추적지수')
            temp['추적지수전일대비'] = self._get_comm_data(trcode, rqname, i, '추적지수전일대비')
            temp['추적지수전일대비기호'] = self._get_comm_data(trcode, rqname, i, '추적지수전일대비기호')
            self.opt40006_output['multi'].append(temp)

    def _opt40007(self, rqname, trcode):
        """
    	ETF시간대별체결요청
    	"""
        self.opt40007_output = {'single': dict(), 'multi': []}

        self.opt40007_output['single']['종목분류'] = self._get_comm_data(trcode, rqname, 0, '종목분류')
        self.opt40007_output['single']['종목명'] = self._get_comm_data(trcode, rqname, 0, '종목명')
        self.opt40007_output['single']['ETF대상지수명'] = self._get_comm_data(trcode, rqname, 0, 'ETF대상지수명')
        self.opt40007_output['single']['ETF대상지수코드'] = self._get_comm_data(trcode, rqname, 0, 'ETF대상지수코드')
        self.opt40007_output['single']['대상지수대비율'] = self._get_comm_data(trcode, rqname, 0, '대상지수대비율')
        self.opt40007_output['single']['원주가격'] = self._get_comm_data(trcode, rqname, 0, '원주가격')

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['체결시간'] = self._get_comm_data(trcode, rqname, i, '체결시간')
            temp['현재가'] = self._get_comm_data(trcode, rqname, i, '현재가')
            temp['대비기호'] = self._get_comm_data(trcode, rqname, i, '대비기호')
            temp['전일대비'] = self._get_comm_data(trcode, rqname, i, '전일대비')
            temp['거래량'] = self._get_comm_data(trcode, rqname, i, '거래량')
            self.opt40007_output['multi'].append(temp)

    def _opt40008(self, rqname, trcode):
        """
    	ETF시간대별체결요청
    	"""
        self.opt40008_output = {'single': dict(), 'multi': []}

        self.opt40008_output['single']['체결시간'] = self._get_comm_data(trcode, rqname, 0, '체결시간')
        self.opt40008_output['single']['현재가'] = self._get_comm_data(trcode, rqname, 0, '현재가')
        self.opt40008_output['single']['대비기호'] = self._get_comm_data(trcode, rqname, 0, '대비기호')
        self.opt40008_output['single']['전일대비'] = self._get_comm_data(trcode, rqname, 0, '전일대비')
        self.opt40008_output['single']['거래량'] = self._get_comm_data(trcode, rqname, 0, '거래량')

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['체결시간n'] = self._get_comm_data(trcode, rqname, i, '체결시간n')
            temp['현재가n'] = self._get_comm_data(trcode, rqname, i, '현재가n')
            temp['대비기호n'] = self._get_comm_data(trcode, rqname, i, '대비기호n')
            temp['전일대비n'] = self._get_comm_data(trcode, rqname, i, '전일대비n')
            temp['누적거래량'] = self._get_comm_data(trcode, rqname, i, '누적거래량')
            temp['외인순매수수량'] = self._get_comm_data(trcode, rqname, i, '외인순매수수량')
            temp['기관순매수수량'] = self._get_comm_data(trcode, rqname, i, '기관순매수수량')
            self.opt40008_output['multi'].append(temp)

    def _opt40009(self, rqname, trcode):
        """
    	ETF시간대별체결요청
    	"""
        self.opt40009_output = {'multi': []}

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['NAV'] = self._get_comm_data(trcode, rqname, i, 'NAV')
            temp['NAV전일대비'] = self._get_comm_data(trcode, rqname, i, 'NAV전일대비')
            temp['NAV등락율'] = self._get_comm_data(trcode, rqname, i, 'NAV등락율')
            temp['추적오차율'] = self._get_comm_data(trcode, rqname, i, '추적오차율')
            temp['괴리율'] = self._get_comm_data(trcode, rqname, i, '괴리율')
            temp['주식수'] = self._get_comm_data(trcode, rqname, i, '주식수')
            temp['기준가'] = self._get_comm_data(trcode, rqname, i, '기준가')
            temp['외인보유수량'] = self._get_comm_data(trcode, rqname, i, '외인보유수량')
            temp['대용가'] = self._get_comm_data(trcode, rqname, i, '대용가')
            temp['모름'] = self._get_comm_data(trcode, rqname, i, '모름')
            temp['환산가격'] = self._get_comm_data(trcode, rqname, i, '환산가격')
            temp['DR/주'] = self._get_comm_data(trcode, rqname, i, 'DR/주')
            temp['원주가격'] = self._get_comm_data(trcode, rqname, i, '원주가격')
            self.opt40009_output['multi'].append(temp)

    def _opt40010(self, rqname, trcode):
        """
    	ETF시간대별추이요청
    	"""
        self.opt40010_output = {'multi': []}

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['현재가'] = self._get_comm_data(trcode, rqname, i, '현재가')
            temp['대비기호'] = self._get_comm_data(trcode, rqname, i, '대비기호')
            temp['전일대비'] = self._get_comm_data(trcode, rqname, i, '전일대비')
            temp['거래량'] = self._get_comm_data(trcode, rqname, i, '거래량')
            temp['외인순매수'] = self._get_comm_data(trcode, rqname, i, '외인순매수')
            self.opt40010_output['multi'].append(temp)

    def _opt50001(self, rqname, trcode):
        """
    	선옵현재가정보요청
    	"""
        self.opt50001_output = {'single': dict(), 'multi': []}

        self.opt50001_output['single']['현재가'] = self._get_comm_data(trcode, rqname, 0, '현재가')
        self.opt50001_output['single']['대비기호'] = self._get_comm_data(trcode, rqname, 0, '대비기호')
        self.opt50001_output['single']['전일대비'] = self._get_comm_data(trcode, rqname, 0, '전일대비')
        self.opt50001_output['single']['등락율'] = self._get_comm_data(trcode, rqname, 0, '등락율')
        self.opt50001_output['single']['거래량'] = self._get_comm_data(trcode, rqname, 0, '거래량')
        self.opt50001_output['single']['거래량대비'] = self._get_comm_data(trcode, rqname, 0, '거래량대비')
        self.opt50001_output['single']['기준가'] = self._get_comm_data(trcode, rqname, 0, '기준가')
        self.opt50001_output['single']['이론가'] = self._get_comm_data(trcode, rqname, 0, '이론가')
        self.opt50001_output['single']['이론베이시스'] = self._get_comm_data(trcode, rqname, 0, '이론베이시스')
        self.opt50001_output['single']['괴리도'] = self._get_comm_data(trcode, rqname, 0, '괴리도')
        self.opt50001_output['single']['괴리율'] = self._get_comm_data(trcode, rqname, 0, '괴리율')
        self.opt50001_output['single']['시장베이시스'] = self._get_comm_data(trcode, rqname, 0, '시장베이시스')
        self.opt50001_output['single']['누적거래대금'] = self._get_comm_data(trcode, rqname, 0, '누적거래대금')
        self.opt50001_output['single']['상한가'] = self._get_comm_data(trcode, rqname, 0, '상한가')
        self.opt50001_output['single']['하한가'] = self._get_comm_data(trcode, rqname, 0, '하한가')
        self.opt50001_output['single']['CB상한가'] = self._get_comm_data(trcode, rqname, 0, 'CB상한가')
        self.opt50001_output['single']['CB하한가'] = self._get_comm_data(trcode, rqname, 0, 'CB하한가')
        self.opt50001_output['single']['대용가'] = self._get_comm_data(trcode, rqname, 0, '대용가')
        self.opt50001_output['single']['최종거래일'] = self._get_comm_data(trcode, rqname, 0, '최종거래일')
        self.opt50001_output['single']['잔존일수'] = self._get_comm_data(trcode, rqname, 0, '잔존일수')
        self.opt50001_output['single']['영업일기준잔존일'] = self._get_comm_data(trcode, rqname, 0, '영업일기준잔존일')
        self.opt50001_output['single']['상장중최고가'] = self._get_comm_data(trcode, rqname, 0, '상장중최고가')
        self.opt50001_output['single']['상장중최고가대비율'] = self._get_comm_data(trcode, rqname, 0, '상장중최고가대비율')
        self.opt50001_output['single']['상장중최고가일'] = self._get_comm_data(trcode, rqname, 0, '상장중최고가일')
        self.opt50001_output['single']['상장중최저가'] = self._get_comm_data(trcode, rqname, 0, '상장중최저가')
        self.opt50001_output['single']['상장중최저가대비율'] = self._get_comm_data(trcode, rqname, 0, '상장중최저가대비율')
        self.opt50001_output['single']['상장중최저가일'] = self._get_comm_data(trcode, rqname, 0, '상장중최저가일')
        self.opt50001_output['single']['종목명'] = self._get_comm_data(trcode, rqname, 0, '종목명')
        self.opt50001_output['single']['호가시간'] = self._get_comm_data(trcode, rqname, 0, '호가시간')
        self.opt50001_output['single']['매도수익율5'] = self._get_comm_data(trcode, rqname, 0, '매도수익율5')
        self.opt50001_output['single']['매도건수5'] = self._get_comm_data(trcode, rqname, 0, '매도건수5')
        self.opt50001_output['single']['매도수량5'] = self._get_comm_data(trcode, rqname, 0, '매도수량5')
        self.opt50001_output['single']['매도수익율4'] = self._get_comm_data(trcode, rqname, 0, '매도수익율4')
        self.opt50001_output['single']['매도건수4'] = self._get_comm_data(trcode, rqname, 0, '매도건수4')
        self.opt50001_output['single']['매도수량4'] = self._get_comm_data(trcode, rqname, 0, '매도수량4')
        self.opt50001_output['single']['매도호가4'] = self._get_comm_data(trcode, rqname, 0, '매도호가4')
        self.opt50001_output['single']['매도호가5'] = self._get_comm_data(trcode, rqname, 0, '매도호가5')
        self.opt50001_output['single']['매도수익율3'] = self._get_comm_data(trcode, rqname, 0, '매도수익율3')
        self.opt50001_output['single']['매도건수3'] = self._get_comm_data(trcode, rqname, 0, '매도건수3')
        self.opt50001_output['single']['매도수량3'] = self._get_comm_data(trcode, rqname, 0, '매도수량3')
        self.opt50001_output['single']['매도호가3'] = self._get_comm_data(trcode, rqname, 0, '매도호가3')
        self.opt50001_output['single']['매도수익율2'] = self._get_comm_data(trcode, rqname, 0, '매도수익율2')
        self.opt50001_output['single']['매도건수2'] = self._get_comm_data(trcode, rqname, 0, '매도건수2')
        self.opt50001_output['single']['매도수량2'] = self._get_comm_data(trcode, rqname, 0, '매도수량2')
        self.opt50001_output['single']['매도호가2'] = self._get_comm_data(trcode, rqname, 0, '매도호가2')
        self.opt50001_output['single']['매도수익율1'] = self._get_comm_data(trcode, rqname, 0, '매도수익율1')
        self.opt50001_output['single']['매도건수1'] = self._get_comm_data(trcode, rqname, 0, '매도건수1')
        self.opt50001_output['single']['매도수량1'] = self._get_comm_data(trcode, rqname, 0, '매도수량1')
        self.opt50001_output['single']['매도호가1'] = self._get_comm_data(trcode, rqname, 0, '매도호가1')
        self.opt50001_output['single']['매수호가1'] = self._get_comm_data(trcode, rqname, 0, '매수호가1')
        self.opt50001_output['single']['매수수량1'] = self._get_comm_data(trcode, rqname, 0, '매수수량1')
        self.opt50001_output['single']['매수건수1'] = self._get_comm_data(trcode, rqname, 0, '매수건수1')
        self.opt50001_output['single']['매수수익율1'] = self._get_comm_data(trcode, rqname, 0, '매수수익율1')
        self.opt50001_output['single']['매수호가2'] = self._get_comm_data(trcode, rqname, 0, '매수호가2')
        self.opt50001_output['single']['매수수량2'] = self._get_comm_data(trcode, rqname, 0, '매수수량2')
        self.opt50001_output['single']['매수건수2'] = self._get_comm_data(trcode, rqname, 0, '매수건수2')
        self.opt50001_output['single']['매수수익율2'] = self._get_comm_data(trcode, rqname, 0, '매수수익율2')
        self.opt50001_output['single']['매수호가3'] = self._get_comm_data(trcode, rqname, 0, '매수호가3')
        self.opt50001_output['single']['매수수량3'] = self._get_comm_data(trcode, rqname, 0, '매수수량3')
        self.opt50001_output['single']['매수건수3'] = self._get_comm_data(trcode, rqname, 0, '매수건수3')
        self.opt50001_output['single']['매수수익율3'] = self._get_comm_data(trcode, rqname, 0, '매수수익율3')
        self.opt50001_output['single']['매수호가4'] = self._get_comm_data(trcode, rqname, 0, '매수호가4')
        self.opt50001_output['single']['매수수량4'] = self._get_comm_data(trcode, rqname, 0, '매수수량4')
        self.opt50001_output['single']['매수건수4'] = self._get_comm_data(trcode, rqname, 0, '매수건수4')
        self.opt50001_output['single']['매수수익율4'] = self._get_comm_data(trcode, rqname, 0, '매수수익율4')
        self.opt50001_output['single']['매수호가5'] = self._get_comm_data(trcode, rqname, 0, '매수호가5')
        self.opt50001_output['single']['매수수량5'] = self._get_comm_data(trcode, rqname, 0, '매수수량5')
        self.opt50001_output['single']['매수건수5'] = self._get_comm_data(trcode, rqname, 0, '매수건수5')
        self.opt50001_output['single']['매수수익율5'] = self._get_comm_data(trcode, rqname, 0, '매수수익율5')
        self.opt50001_output['single']['시가'] = self._get_comm_data(trcode, rqname, 0, '시가')
        self.opt50001_output['single']['고가'] = self._get_comm_data(trcode, rqname, 0, '고가')
        self.opt50001_output['single']['저가'] = self._get_comm_data(trcode, rqname, 0, '저가')
        self.opt50001_output['single']['2차저항'] = self._get_comm_data(trcode, rqname, 0, '2차저항')
        self.opt50001_output['single']['1차저항'] = self._get_comm_data(trcode, rqname, 0, '1차저항')
        self.opt50001_output['single']['피봇'] = self._get_comm_data(trcode, rqname, 0, '피봇')
        self.opt50001_output['single']['1차저지'] = self._get_comm_data(trcode, rqname, 0, '1차저지')
        self.opt50001_output['single']['2차저지'] = self._get_comm_data(trcode, rqname, 0, '2차저지')
        self.opt50001_output['single']['미결제약정'] = self._get_comm_data(trcode, rqname, 0, '미결제약정')
        self.opt50001_output['single']['미결제약정전일대비'] = self._get_comm_data(trcode, rqname, 0, '미결제약정전일대비')
        self.opt50001_output['single']['매도호가총건수'] = self._get_comm_data(trcode, rqname, 0, '매도호가총건수')
        self.opt50001_output['single']['매도호가총잔량'] = self._get_comm_data(trcode, rqname, 0, '매도호가총잔량')
        self.opt50001_output['single']['순매수잔량'] = self._get_comm_data(trcode, rqname, 0, '순매수잔량')
        self.opt50001_output['single']['매수호가총잔량'] = self._get_comm_data(trcode, rqname, 0, '매수호가총잔량')
        self.opt50001_output['single']['매수호가총건수'] = self._get_comm_data(trcode, rqname, 0, '매수호가총건수')
        self.opt50001_output['single']['매도호가총잔량직전대비'] = self._get_comm_data(trcode, rqname, 0, '매도호가총잔량직전대비')
        self.opt50001_output['single']['매수호가총잔량직전대비'] = self._get_comm_data(trcode, rqname, 0, '매수호가총잔량직전대비')
        self.opt50001_output['single']['예상체결가'] = self._get_comm_data(trcode, rqname, 0, '예상체결가')
        self.opt50001_output['single']['예상체결가전일종가대비기호'] = self._get_comm_data(trcode, rqname, 0, '예상체결가전일종가대비기호')
        self.opt50001_output['single']['예상체결가전일종가대비'] = self._get_comm_data(trcode, rqname, 0, '예상체결가전일종가대비')
        self.opt50001_output['single']['예상체결가전일종가대비등락율'] = self._get_comm_data(trcode, rqname, 0, '예상체결가전일종가대비등락율')
        self.opt50001_output['single']['이자율              '] = self._get_comm_data(trcode, rqname, 0,
                                                                                  '이자율              ')

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['체결시간'] = self._get_comm_data(trcode, rqname, i, '체결시간')
            temp['현재가n'] = self._get_comm_data(trcode, rqname, i, '현재가n')
            temp['대비기호n'] = self._get_comm_data(trcode, rqname, i, '대비기호n')
            temp['전일대비n'] = self._get_comm_data(trcode, rqname, i, '전일대비n')
            temp['체결량'] = self._get_comm_data(trcode, rqname, i, '체결량')
            temp['미결제약정n'] = self._get_comm_data(trcode, rqname, i, '미결제약정n')
            temp['코스피200'] = self._get_comm_data(trcode, rqname, i, '코스피200')
            temp['시장베이시스n'] = self._get_comm_data(trcode, rqname, i, '시장베이시스n')
            temp['역사적변동성'] = self._get_comm_data(trcode, rqname, i, '역사적변동성')
            temp['표면이자'] = self._get_comm_data(trcode, rqname, i, '표면이자')
            temp['배당액지수'] = self._get_comm_data(trcode, rqname, i, '배당액지수')
            temp['기준가n'] = self._get_comm_data(trcode, rqname, i, '기준가n')
            temp['등락율n'] = self._get_comm_data(trcode, rqname, i, '등락율n')
            temp['누적거래량'] = self._get_comm_data(trcode, rqname, i, '누적거래량')
            self.opt50001_output['multi'].append(temp)

    def _opt50002(self, rqname, trcode):
        """
    	선옵일자별체결요청
    	"""
        self.opt50002_output = {'single': dict(), 'multi': []}

        self.opt50002_output['single']['종목명'] = self._get_comm_data(trcode, rqname, 0, '종목명')
        self.opt50002_output['single']['현재가'] = self._get_comm_data(trcode, rqname, 0, '현재가')
        self.opt50002_output['single']['대비기호'] = self._get_comm_data(trcode, rqname, 0, '대비기호')
        self.opt50002_output['single']['전일대비'] = self._get_comm_data(trcode, rqname, 0, '전일대비')
        self.opt50002_output['single']['등락율'] = self._get_comm_data(trcode, rqname, 0, '등락율')
        self.opt50002_output['single']['누적거래량'] = self._get_comm_data(trcode, rqname, 0, '누적거래량')

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['체결일자'] = self._get_comm_data(trcode, rqname, i, '체결일자')
            temp['현재가n'] = self._get_comm_data(trcode, rqname, i, '현재가n')
            temp['대비기호n'] = self._get_comm_data(trcode, rqname, i, '대비기호n')
            temp['전일대비n'] = self._get_comm_data(trcode, rqname, i, '전일대비n')
            temp['등락율n '] = self._get_comm_data(trcode, rqname, i, '등락율n ')
            temp['거래량'] = self._get_comm_data(trcode, rqname, i, '거래량')
            temp['시가'] = self._get_comm_data(trcode, rqname, i, '시가')
            temp['고가'] = self._get_comm_data(trcode, rqname, i, '고가')
            temp['저가'] = self._get_comm_data(trcode, rqname, i, '저가')
            temp['예상체결가'] = self._get_comm_data(trcode, rqname, i, '예상체결가')
            temp['미결제약정'] = self._get_comm_data(trcode, rqname, i, '미결제약정')
            temp['예상체결가전일종가대비기호'] = self._get_comm_data(trcode, rqname, i, '예상체결가전일종가대비기호')
            temp['예상체결가전일종가대비'] = self._get_comm_data(trcode, rqname, i, '예상체결가전일종가대비')
            temp['예상체결가전일종가대비등락율'] = self._get_comm_data(trcode, rqname, i, '예상체결가전일종가대비등락율')
            self.opt50002_output['multi'].append(temp)

    def _opt50003(self, rqname, trcode):
        """
    	선옵시고저가요청
    	"""
        self.opt50003_output = {'single': dict()}

        self.opt50003_output['single']['일자'] = self._get_comm_data(trcode, rqname, 0, '일자')
        self.opt50003_output['single']['현재가'] = self._get_comm_data(trcode, rqname, 0, '현재가')
        self.opt50003_output['single']['기준가'] = self._get_comm_data(trcode, rqname, 0, '기준가')
        self.opt50003_output['single']['체결량'] = self._get_comm_data(trcode, rqname, 0, '체결량')
        self.opt50003_output['single']['시가'] = self._get_comm_data(trcode, rqname, 0, '시가')
        self.opt50003_output['single']['고가'] = self._get_comm_data(trcode, rqname, 0, '고가')
        self.opt50003_output['single']['저가'] = self._get_comm_data(trcode, rqname, 0, '저가')
        self.opt50003_output['single']['시초미결제약정수량'] = self._get_comm_data(trcode, rqname, 0, '시초미결제약정수량')
        self.opt50003_output['single']['최고미결제약정수량'] = self._get_comm_data(trcode, rqname, 0, '최고미결제약정수량')
        self.opt50003_output['single']['최저미결제약정수량'] = self._get_comm_data(trcode, rqname, 0, '최저미결제약정수량')
        self.opt50003_output['single']['미결제약정'] = self._get_comm_data(trcode, rqname, 0, '미결제약정')
        self.opt50003_output['single']['전일미결제약정'] = self._get_comm_data(trcode, rqname, 0, '전일미결제약정')
        self.opt50003_output['single']['이론가'] = self._get_comm_data(trcode, rqname, 0, '이론가')
        self.opt50003_output['single']['내재변동성'] = self._get_comm_data(trcode, rqname, 0, '내재변동성')
        self.opt50003_output['single']['델타'] = self._get_comm_data(trcode, rqname, 0, '델타')
        self.opt50003_output['single']['감마'] = self._get_comm_data(trcode, rqname, 0, '감마')
        self.opt50003_output['single']['상한가'] = self._get_comm_data(trcode, rqname, 0, '상한가')
        self.opt50003_output['single']['하한가'] = self._get_comm_data(trcode, rqname, 0, '하한가')
        self.opt50003_output['single']['시장베이시스'] = self._get_comm_data(trcode, rqname, 0, '시장베이시스')
        self.opt50003_output['single']['괴리율'] = self._get_comm_data(trcode, rqname, 0, '괴리율')

    def _opt50004(self, rqname, trcode):
        """
    	콜옵션행사가요청
    	"""
        self.opt50004_output = {'multi': []}

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['종목코드'] = self._get_comm_data(trcode, rqname, i, '종목코드')
            temp['ATM구분'] = self._get_comm_data(trcode, rqname, i, 'ATM구분')
            temp['행사가'] = self._get_comm_data(trcode, rqname, i, '행사가')
            self.opt50004_output['multi'].append(temp)

    def _opt50005(self, rqname, trcode):
        """
    	선옵시간별거래량요청
    	"""
        self.opt50005_output = {'multi': []}

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['체결시간'] = self._get_comm_data(trcode, rqname, i, '체결시간')
            temp['미결제약정'] = self._get_comm_data(trcode, rqname, i, '미결제약정')
            temp['누적거래량'] = self._get_comm_data(trcode, rqname, i, '누적거래량')
            temp['체결량'] = self._get_comm_data(trcode, rqname, i, '체결량')
            self.opt50005_output['multi'].append(temp)

    def _opt50006(self, rqname, trcode):
        """
    	선옵체결추이요청
    	"""
        self.opt50006_output = {'single': dict(), 'multi': []}

        self.opt50006_output['single']['종목명'] = self._get_comm_data(trcode, rqname, 0, '종목명')

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['체결시간'] = self._get_comm_data(trcode, rqname, i, '체결시간')
            temp['현재가'] = self._get_comm_data(trcode, rqname, i, '현재가')
            temp['대비기호'] = self._get_comm_data(trcode, rqname, i, '대비기호')
            temp['전일대비'] = self._get_comm_data(trcode, rqname, i, '전일대비')
            temp['체결량'] = self._get_comm_data(trcode, rqname, i, '체결량')
            temp['누적거래량'] = self._get_comm_data(trcode, rqname, i, '누적거래량')
            temp['미결제약정'] = self._get_comm_data(trcode, rqname, i, '미결제약정')
            temp['미결제증감'] = self._get_comm_data(trcode, rqname, i, '미결제증감')
            temp['전일거래량대비'] = self._get_comm_data(trcode, rqname, i, '전일거래량대비')
            temp['전일거래량'] = self._get_comm_data(trcode, rqname, i, '전일거래량')
            temp['기준가'] = self._get_comm_data(trcode, rqname, i, '기준가')
            self.opt50006_output['multi'].append(temp)

    def _opt50007(self, rqname, trcode):
        """
    	선물시세추이요청
    	"""
        self.opt50007_output = {'single': dict(), 'multi': []}

        self.opt50007_output['single']['현재가'] = self._get_comm_data(trcode, rqname, 0, '현재가')
        self.opt50007_output['single']['대비기호'] = self._get_comm_data(trcode, rqname, 0, '대비기호')
        self.opt50007_output['single']['전일대비'] = self._get_comm_data(trcode, rqname, 0, '전일대비')
        self.opt50007_output['single']['등락율'] = self._get_comm_data(trcode, rqname, 0, '등락율')
        self.opt50007_output['single']['시가'] = self._get_comm_data(trcode, rqname, 0, '시가')
        self.opt50007_output['single']['고가'] = self._get_comm_data(trcode, rqname, 0, '고가')
        self.opt50007_output['single']['저가'] = self._get_comm_data(trcode, rqname, 0, '저가')
        self.opt50007_output['single']['누적거래량'] = self._get_comm_data(trcode, rqname, 0, '누적거래량')
        self.opt50007_output['single']['누적거래대금'] = self._get_comm_data(trcode, rqname, 0, '누적거래대금')
        self.opt50007_output['single']['내재가치'] = self._get_comm_data(trcode, rqname, 0, '내재가치')
        self.opt50007_output['single']['시간가치'] = self._get_comm_data(trcode, rqname, 0, '시간가치')
        self.opt50007_output['single']['이론가'] = self._get_comm_data(trcode, rqname, 0, '이론가')
        self.opt50007_output['single']['괴리율'] = self._get_comm_data(trcode, rqname, 0, '괴리율')

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['체결시간'] = self._get_comm_data(trcode, rqname, i, '체결시간')
            temp['시가n'] = self._get_comm_data(trcode, rqname, i, '시가n')
            temp['고가n'] = self._get_comm_data(trcode, rqname, i, '고가n')
            temp['저가n'] = self._get_comm_data(trcode, rqname, i, '저가n')
            temp['현재가n'] = self._get_comm_data(trcode, rqname, i, '현재가n')
            temp['대비기호n'] = self._get_comm_data(trcode, rqname, i, '대비기호n')
            temp['전일대비n'] = self._get_comm_data(trcode, rqname, i, '전일대비n')
            temp['체결량'] = self._get_comm_data(trcode, rqname, i, '체결량')
            temp['누적거래량n'] = self._get_comm_data(trcode, rqname, i, '누적거래량n')
            temp['미결제약정'] = self._get_comm_data(trcode, rqname, i, '미결제약정')
            temp['미결제증감'] = self._get_comm_data(trcode, rqname, i, '미결제증감')
            temp['시장베이시스'] = self._get_comm_data(trcode, rqname, i, '시장베이시스')
            temp['코스피200'] = self._get_comm_data(trcode, rqname, i, '코스피200')
            temp['종목명'] = self._get_comm_data(trcode, rqname, i, '종목명')
            temp['내재가치n'] = self._get_comm_data(trcode, rqname, i, '내재가치n')
            self.opt50007_output['multi'].append(temp)

    def _opt50008(self, rqname, trcode):
        """
    	프로그램매매추이차트요청
    	"""
        self.opt50008_output = {'multi': []}

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['체결시간'] = self._get_comm_data(trcode, rqname, i, '체결시간')
            temp['투자자별매도금액'] = self._get_comm_data(trcode, rqname, i, '투자자별매도금액')
            temp['투자자별매수금액'] = self._get_comm_data(trcode, rqname, i, '투자자별매수금액')
            temp['투자자별순매수금액'] = self._get_comm_data(trcode, rqname, i, '투자자별순매수금액')
            self.opt50008_output['multi'].append(temp)

    def _opt50009(self, rqname, trcode):
        """
    	선옵시간별잔량요청
    	"""
        self.opt50009_output = {'single': dict(), 'multi': []}

        self.opt50009_output['single']['시가'] = self._get_comm_data(trcode, rqname, 0, '시가')
        self.opt50009_output['single']['고가'] = self._get_comm_data(trcode, rqname, 0, '고가')
        self.opt50009_output['single']['저가'] = self._get_comm_data(trcode, rqname, 0, '저가')

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['호가시간'] = self._get_comm_data(trcode, rqname, i, '호가시간')
            temp['매도호가총잔량'] = self._get_comm_data(trcode, rqname, i, '매도호가총잔량')
            temp['매수호가총잔량'] = self._get_comm_data(trcode, rqname, i, '매수호가총잔량')
            temp['순매수잔량'] = self._get_comm_data(trcode, rqname, i, '순매수잔량')
            self.opt50009_output['multi'].append(temp)

    def _opt50010(self, rqname, trcode):
        """
    	선옵호가잔량추이요청
    	"""
        self.opt50010_output = {'single': dict(), 'multi': []}

        self.opt50010_output['single']['시가'] = self._get_comm_data(trcode, rqname, 0, '시가')
        self.opt50010_output['single']['고가'] = self._get_comm_data(trcode, rqname, 0, '고가')
        self.opt50010_output['single']['저가'] = self._get_comm_data(trcode, rqname, 0, '저가')

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['호가시간'] = self._get_comm_data(trcode, rqname, i, '호가시간')
            temp['매도호가수량'] = self._get_comm_data(trcode, rqname, i, '매도호가수량')
            temp['최우선매도호가'] = self._get_comm_data(trcode, rqname, i, '최우선매도호가')
            temp['매수호가수량'] = self._get_comm_data(trcode, rqname, i, '매수호가수량')
            temp['최우선매수호가'] = self._get_comm_data(trcode, rqname, i, '최우선매수호가')
            temp['호가순잔량'] = self._get_comm_data(trcode, rqname, i, '호가순잔량')
            temp['매도호가총잔량'] = self._get_comm_data(trcode, rqname, i, '매도호가총잔량')
            temp['매수호가총잔량'] = self._get_comm_data(trcode, rqname, i, '매수호가총잔량')
            temp['순매수잔량'] = self._get_comm_data(trcode, rqname, i, '순매수잔량')
            self.opt50010_output['multi'].append(temp)

    def _opt50011(self, rqname, trcode):
        """
    	선옵호가잔량추이요청
    	"""
        self.opt50011_output = {'multi': []}

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['호가시간'] = self._get_comm_data(trcode, rqname, i, '호가시간')
            temp['매도호가수량'] = self._get_comm_data(trcode, rqname, i, '매도호가수량')
            temp['최우선매도호가'] = self._get_comm_data(trcode, rqname, i, '최우선매도호가')
            temp['매수호가수량'] = self._get_comm_data(trcode, rqname, i, '매수호가수량')
            temp['최우선매수호가'] = self._get_comm_data(trcode, rqname, i, '최우선매수호가')
            temp['호가순잔량'] = self._get_comm_data(trcode, rqname, i, '호가순잔량')
            temp['매도호가총잔량'] = self._get_comm_data(trcode, rqname, i, '매도호가총잔량')
            temp['매수호가총잔량'] = self._get_comm_data(trcode, rqname, i, '매수호가총잔량')
            temp['순매수잔량'] = self._get_comm_data(trcode, rqname, i, '순매수잔량')
            self.opt50011_output['multi'].append(temp)

    def _opt50012(self, rqname, trcode):
        """
    	선옵타임스프레드차트요청
    	"""
        self.opt50012_output = {'multi': []}

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['현재가'] = self._get_comm_data(trcode, rqname, i, '현재가')
            temp['체결시간'] = self._get_comm_data(trcode, rqname, i, '체결시간')
            self.opt50012_output['multi'].append(temp)

    def _opt50013(self, rqname, trcode):
        """
    	선물가격대별비중차트요청
    	"""
        self.opt50013_output = {'multi': []}

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['현재가'] = self._get_comm_data(trcode, rqname, i, '현재가')
            temp['거래량'] = self._get_comm_data(trcode, rqname, i, '거래량')
            temp['체결시간'] = self._get_comm_data(trcode, rqname, i, '체결시간')
            self.opt50013_output['multi'].append(temp)

    def _opt50014(self, rqname, trcode):
        """
    	선물가격대별비중차트요청
    	"""
        self.opt50014_output = {'single': dict(), 'multi': []}

        self.opt50014_output['single']['현재가'] = self._get_comm_data(trcode, rqname, 0, '현재가')
        self.opt50014_output['single']['대비기호'] = self._get_comm_data(trcode, rqname, 0, '대비기호')
        self.opt50014_output['single']['전일대비'] = self._get_comm_data(trcode, rqname, 0, '전일대비')
        self.opt50014_output['single']['등락율'] = self._get_comm_data(trcode, rqname, 0, '등락율')
        self.opt50014_output['single']['고가'] = self._get_comm_data(trcode, rqname, 0, '고가')
        self.opt50014_output['single']['저가'] = self._get_comm_data(trcode, rqname, 0, '저가')
        self.opt50014_output['single']['누적거래량'] = self._get_comm_data(trcode, rqname, 0, '누적거래량')
        self.opt50014_output['single']['미결제약정'] = self._get_comm_data(trcode, rqname, 0, '미결제약정')
        self.opt50014_output['single']['종목명'] = self._get_comm_data(trcode, rqname, 0, '종목명')
        self.opt50014_output['single']['누적거래대금'] = self._get_comm_data(trcode, rqname, 0, '누적거래대금')

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['구간구분'] = self._get_comm_data(trcode, rqname, i, '구간구분')
            temp['거래량'] = self._get_comm_data(trcode, rqname, i, '거래량')
            temp['비중'] = self._get_comm_data(trcode, rqname, i, '비중')
            self.opt50014_output['multi'].append(temp)

    def _opt50015(self, rqname, trcode):
        """
    	선물미결제약정일차트요청
    	"""
        self.opt50015_output = {'single': dict(), 'multi': []}

        self.opt50015_output['single']['현재가s'] = self._get_comm_data(trcode, rqname, 0, '현재가s')
        self.opt50015_output['single']['대비기호s'] = self._get_comm_data(trcode, rqname, 0, '대비기호s')
        self.opt50015_output['single']['전일대비s'] = self._get_comm_data(trcode, rqname, 0, '전일대비s')
        self.opt50015_output['single']['등락율s'] = self._get_comm_data(trcode, rqname, 0, '등락율s')
        self.opt50015_output['single']['고가s'] = self._get_comm_data(trcode, rqname, 0, '고가s')
        self.opt50015_output['single']['저가s'] = self._get_comm_data(trcode, rqname, 0, '저가s')
        self.opt50015_output['single']['누적거래량s'] = self._get_comm_data(trcode, rqname, 0, '누적거래량s')
        self.opt50015_output['single']['미결제약정s'] = self._get_comm_data(trcode, rqname, 0, '미결제약정s')
        self.opt50015_output['single']['종목명s'] = self._get_comm_data(trcode, rqname, 0, '종목명s')

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['현재가'] = self._get_comm_data(trcode, rqname, i, '현재가')
            temp['체결시간'] = self._get_comm_data(trcode, rqname, i, '체결시간')
            temp['미결제약정'] = self._get_comm_data(trcode, rqname, i, '미결제약정')
            temp['미결제증감'] = self._get_comm_data(trcode, rqname, i, '미결제증감')
            self.opt50015_output['multi'].append(temp)

    def _opt50016(self, rqname, trcode):
        """
    	베이시스추이차트요청
    	"""
        self.opt50016_output = {'single': dict(), 'multi': []}

        self.opt50016_output['single']['전일종가'] = self._get_comm_data(trcode, rqname, 0, '전일종가')

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['체결시간'] = self._get_comm_data(trcode, rqname, i, '체결시간')
            temp['현재가'] = self._get_comm_data(trcode, rqname, i, '현재가')
            temp['대비기호'] = self._get_comm_data(trcode, rqname, i, '대비기호')
            temp['전일대비'] = self._get_comm_data(trcode, rqname, i, '전일대비')
            temp['코스피200'] = self._get_comm_data(trcode, rqname, i, '코스피200')
            temp['시장베이시스'] = self._get_comm_data(trcode, rqname, i, '시장베이시스')
            temp['이론가'] = self._get_comm_data(trcode, rqname, i, '이론가')
            temp['괴리율'] = self._get_comm_data(trcode, rqname, i, '괴리율')
            temp['거래량'] = self._get_comm_data(trcode, rqname, i, '거래량')
            temp['시가'] = self._get_comm_data(trcode, rqname, i, '시가')
            self.opt50016_output['multi'].append(temp)

    def _opt50017(self, rqname, trcode):
        """
    	베이시스추이차트요청
    	"""
        self.opt50017_output = {'multi': []}

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['현재가'] = self._get_comm_data(trcode, rqname, i, '현재가')
            temp['체결시간'] = self._get_comm_data(trcode, rqname, i, '체결시간')
            temp['거래량'] = self._get_comm_data(trcode, rqname, i, '거래량')
            temp['시장베이시스'] = self._get_comm_data(trcode, rqname, i, '시장베이시스')
            temp['시가'] = self._get_comm_data(trcode, rqname, i, '시가')
            temp['고가'] = self._get_comm_data(trcode, rqname, i, '고가')
            temp['저가'] = self._get_comm_data(trcode, rqname, i, '저가')
            temp['괴리율'] = self._get_comm_data(trcode, rqname, i, '괴리율')
            self.opt50017_output['multi'].append(temp)

    def _opt50018(self, rqname, trcode):
        """
    	풋콜옵션비율차트요청
    	"""
        self.opt50018_output = {'multi': []}

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['체결시간'] = self._get_comm_data(trcode, rqname, i, '체결시간')
            temp['콜풋RATIO'] = self._get_comm_data(trcode, rqname, i, '콜풋RATIO')
            temp['코스피200'] = self._get_comm_data(trcode, rqname, i, '코스피200')
            self.opt50018_output['multi'].append(temp)

    def _opt50019(self, rqname, trcode):
        """
    	선물옵션현재가정보요청
    	"""
        self.opt50019_output = {'single': dict()}

        self.opt50019_output['single']['종목명'] = self._get_comm_data(trcode, rqname, 0, '종목명')
        self.opt50019_output['single']['현재가'] = self._get_comm_data(trcode, rqname, 0, '현재가')
        self.opt50019_output['single']['대비기호'] = self._get_comm_data(trcode, rqname, 0, '대비기호')
        self.opt50019_output['single']['전일대비'] = self._get_comm_data(trcode, rqname, 0, '전일대비')
        self.opt50019_output['single']['내재가치'] = self._get_comm_data(trcode, rqname, 0, '내재가치')
        self.opt50019_output['single']['시간가치'] = self._get_comm_data(trcode, rqname, 0, '시간가치')
        self.opt50019_output['single']['이론가'] = self._get_comm_data(trcode, rqname, 0, '이론가')
        self.opt50019_output['single']['시가'] = self._get_comm_data(trcode, rqname, 0, '시가')
        self.opt50019_output['single']['고가'] = self._get_comm_data(trcode, rqname, 0, '고가')
        self.opt50019_output['single']['저가'] = self._get_comm_data(trcode, rqname, 0, '저가')
        self.opt50019_output['single']['누적거래량'] = self._get_comm_data(trcode, rqname, 0, '누적거래량')
        self.opt50019_output['single']['거래량전일대비'] = self._get_comm_data(trcode, rqname, 0, '거래량전일대비')
        self.opt50019_output['single']['누적거래대금'] = self._get_comm_data(trcode, rqname, 0, '누적거래대금')
        self.opt50019_output['single']['거래대금증감'] = self._get_comm_data(trcode, rqname, 0, '거래대금증감')
        self.opt50019_output['single']['미결제약정'] = self._get_comm_data(trcode, rqname, 0, '미결제약정')
        self.opt50019_output['single']['미결제약정전일대비'] = self._get_comm_data(trcode, rqname, 0, '미결제약정전일대비')
        self.opt50019_output['single']['역사적변동성'] = self._get_comm_data(trcode, rqname, 0, '역사적변동성')
        self.opt50019_output['single']['표면이자'] = self._get_comm_data(trcode, rqname, 0, '표면이자')
        self.opt50019_output['single']['배당액지수'] = self._get_comm_data(trcode, rqname, 0, '배당액지수')
        self.opt50019_output['single']['매도호가'] = self._get_comm_data(trcode, rqname, 0, '매도호가')
        self.opt50019_output['single']['매도수량'] = self._get_comm_data(trcode, rqname, 0, '매도수량')
        self.opt50019_output['single']['매수호가'] = self._get_comm_data(trcode, rqname, 0, '매수호가')
        self.opt50019_output['single']['매수수량'] = self._get_comm_data(trcode, rqname, 0, '매수수량')

    def _opt50020(self, rqname, trcode):
        """
    	복수종목결제월별시세요청
    	"""
        self.opt50020_output = {'multi': []}

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['현재가'] = self._get_comm_data(trcode, rqname, i, '현재가')
            temp['전일대비'] = self._get_comm_data(trcode, rqname, i, '전일대비')
            temp['등락율'] = self._get_comm_data(trcode, rqname, i, '등락율')
            temp['대비기호'] = self._get_comm_data(trcode, rqname, i, '대비기호')
            temp['시간가치'] = self._get_comm_data(trcode, rqname, i, '시간가치')
            temp['내재가치'] = self._get_comm_data(trcode, rqname, i, '내재가치')
            temp['내재변동성'] = self._get_comm_data(trcode, rqname, i, '내재변동성')
            temp['이론가'] = self._get_comm_data(trcode, rqname, i, '이론가')
            temp['괴리율'] = self._get_comm_data(trcode, rqname, i, '괴리율')
            temp['미결제약정전일대비'] = self._get_comm_data(trcode, rqname, i, '미결제약정전일대비')
            temp['미결제약정'] = self._get_comm_data(trcode, rqname, i, '미결제약정')
            temp['누적거래대금'] = self._get_comm_data(trcode, rqname, i, '누적거래대금')
            temp['누적거래량'] = self._get_comm_data(trcode, rqname, i, '누적거래량')
            temp['매수호가총잔량'] = self._get_comm_data(trcode, rqname, i, '매수호가총잔량')
            temp['매도호가총잔량'] = self._get_comm_data(trcode, rqname, i, '매도호가총잔량')
            temp['매수호가수량'] = self._get_comm_data(trcode, rqname, i, '매수호가수량')
            temp['매수호가'] = self._get_comm_data(trcode, rqname, i, '매수호가')
            temp['매도호가수량'] = self._get_comm_data(trcode, rqname, i, '매도호가수량')
            temp['매도호가'] = self._get_comm_data(trcode, rqname, i, '매도호가')
            temp['기준가'] = self._get_comm_data(trcode, rqname, i, '기준가')
            temp['시가'] = self._get_comm_data(trcode, rqname, i, '시가')
            temp['고가'] = self._get_comm_data(trcode, rqname, i, '고가')
            temp['저가'] = self._get_comm_data(trcode, rqname, i, '저가')
            temp['기준가대비시가등락율'] = self._get_comm_data(trcode, rqname, i, '기준가대비시가등락율')
            temp['기준가대비고가등락율'] = self._get_comm_data(trcode, rqname, i, '기준가대비고가등락율')
            temp['기준가대비저가등락율'] = self._get_comm_data(trcode, rqname, i, '기준가대비저가등락율')
            temp['지수환산'] = self._get_comm_data(trcode, rqname, i, '지수환산')
            temp['예상체결가전일종가대비등락율'] = self._get_comm_data(trcode, rqname, i, '예상체결가전일종가대비등락율')
            temp['예상체결가전일종가대비기호'] = self._get_comm_data(trcode, rqname, i, '예상체결가전일종가대비기호')
            temp['예상체결가전일종가대비'] = self._get_comm_data(trcode, rqname, i, '예상체결가전일종가대비')
            temp['예상체결가'] = self._get_comm_data(trcode, rqname, i, '예상체결가')
            temp['종목코드'] = self._get_comm_data(trcode, rqname, i, '종목코드')
            temp['ATM구분'] = self._get_comm_data(trcode, rqname, i, 'ATM구분')
            temp['행사가'] = self._get_comm_data(trcode, rqname, i, '행사가')
            temp['대칭구분 '] = self._get_comm_data(trcode, rqname, i, '대칭구분 ')
            temp['풋_현재가'] = self._get_comm_data(trcode, rqname, i, '풋_현재가')
            temp['풋_전일대비'] = self._get_comm_data(trcode, rqname, i, '풋_전일대비')
            temp['풋_등락율'] = self._get_comm_data(trcode, rqname, i, '풋_등락율')
            temp['풋_대비기호'] = self._get_comm_data(trcode, rqname, i, '풋_대비기호')
            temp['풋_시간가치'] = self._get_comm_data(trcode, rqname, i, '풋_시간가치')
            temp['풋_내재가치'] = self._get_comm_data(trcode, rqname, i, '풋_내재가치')
            temp['풋_내재변동성'] = self._get_comm_data(trcode, rqname, i, '풋_내재변동성')
            temp['풋_이론가'] = self._get_comm_data(trcode, rqname, i, '풋_이론가')
            temp['풋_괴리율'] = self._get_comm_data(trcode, rqname, i, '풋_괴리율')
            temp['풋_미결제약정전일대비'] = self._get_comm_data(trcode, rqname, i, '풋_미결제약정전일대비')
            temp['풋_미결제약정'] = self._get_comm_data(trcode, rqname, i, '풋_미결제약정')
            temp['풋_누적거래대금'] = self._get_comm_data(trcode, rqname, i, '풋_누적거래대금')
            temp['풋_누적거래량'] = self._get_comm_data(trcode, rqname, i, '풋_누적거래량')
            temp['풋_매수호가총잔량'] = self._get_comm_data(trcode, rqname, i, '풋_매수호가총잔량')
            temp['풋_매도호가총잔량'] = self._get_comm_data(trcode, rqname, i, '풋_매도호가총잔량')
            temp['풋_매수호가수량'] = self._get_comm_data(trcode, rqname, i, '풋_매수호가수량')
            temp['풋_매수호가'] = self._get_comm_data(trcode, rqname, i, '풋_매수호가')
            temp['풋_매도호가수량'] = self._get_comm_data(trcode, rqname, i, '풋_매도호가수량')
            temp['풋_매도호가'] = self._get_comm_data(trcode, rqname, i, '풋_매도호가')
            temp['풋_기준가'] = self._get_comm_data(trcode, rqname, i, '풋_기준가')
            temp['풋_시가'] = self._get_comm_data(trcode, rqname, i, '풋_시가')
            temp['풋_고가'] = self._get_comm_data(trcode, rqname, i, '풋_고가')
            temp['풋_저가'] = self._get_comm_data(trcode, rqname, i, '풋_저가')
            temp['풋_기준가대비시가등락율'] = self._get_comm_data(trcode, rqname, i, '풋_기준가대비시가등락율')
            temp['풋_기준가대비고가등락율'] = self._get_comm_data(trcode, rqname, i, '풋_기준가대비고가등락율')
            temp['풋_기준가대비저가등락율'] = self._get_comm_data(trcode, rqname, i, '풋_기준가대비저가등락율')
            temp['풋_지수환산'] = self._get_comm_data(trcode, rqname, i, '풋_지수환산')
            temp['풋_예상체결가전일종가대비등락율'] = self._get_comm_data(trcode, rqname, i, '풋_예상체결가전일종가대비등락율')
            temp['풋_예상체결가전일종가대비기호'] = self._get_comm_data(trcode, rqname, i, '풋_예상체결가전일종가대비기호')
            temp['풋_예상체결가전일종가대비'] = self._get_comm_data(trcode, rqname, i, '풋_예상체결가전일종가대비')
            temp['풋_예상체결가'] = self._get_comm_data(trcode, rqname, i, '풋_예상체결가')
            temp['풋_종목코드'] = self._get_comm_data(trcode, rqname, i, '풋_종목코드')
            temp['풋_ATM구분'] = self._get_comm_data(trcode, rqname, i, '풋_ATM구분')
            temp['풋_행사가'] = self._get_comm_data(trcode, rqname, i, '풋_행사가')
            self.opt50020_output['multi'].append(temp)

    def _opt50021(self, rqname, trcode):
        """
    	콜종목결제월별시세요청
    	"""
        self.opt50021_output = {'multi': []}

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['지수환산'] = self._get_comm_data(trcode, rqname, i, '지수환산')
            temp['ATM구분'] = self._get_comm_data(trcode, rqname, i, 'ATM구분')
            temp['종목코드'] = self._get_comm_data(trcode, rqname, i, '종목코드')
            temp['행사가'] = self._get_comm_data(trcode, rqname, i, '행사가')
            temp['현재가'] = self._get_comm_data(trcode, rqname, i, '현재가')
            temp['대비기호'] = self._get_comm_data(trcode, rqname, i, '대비기호')
            temp['전일대비'] = self._get_comm_data(trcode, rqname, i, '전일대비')
            temp['등락율'] = self._get_comm_data(trcode, rqname, i, '등락율')
            temp['시가'] = self._get_comm_data(trcode, rqname, i, '시가')
            temp['기준가대비시가등락율'] = self._get_comm_data(trcode, rqname, i, '기준가대비시가등락율')
            temp['고가'] = self._get_comm_data(trcode, rqname, i, '고가')
            temp['기준가대비고가등락율'] = self._get_comm_data(trcode, rqname, i, '기준가대비고가등락율')
            temp['저가'] = self._get_comm_data(trcode, rqname, i, '저가')
            temp['기준가대비저가등락율'] = self._get_comm_data(trcode, rqname, i, '기준가대비저가등락율')
            temp['기준가'] = self._get_comm_data(trcode, rqname, i, '기준가')
            temp['매도호가'] = self._get_comm_data(trcode, rqname, i, '매도호가')
            temp['매도호가수량'] = self._get_comm_data(trcode, rqname, i, '매도호가수량')
            temp['매수호가'] = self._get_comm_data(trcode, rqname, i, '매수호가')
            temp['매수호가수량'] = self._get_comm_data(trcode, rqname, i, '매수호가수량')
            temp['매도호가총잔량'] = self._get_comm_data(trcode, rqname, i, '매도호가총잔량')
            temp['매수호가총잔량'] = self._get_comm_data(trcode, rqname, i, '매수호가총잔량')
            temp['누적거래량'] = self._get_comm_data(trcode, rqname, i, '누적거래량')
            temp['누적거래대금'] = self._get_comm_data(trcode, rqname, i, '누적거래대금')
            temp['미결제약정'] = self._get_comm_data(trcode, rqname, i, '미결제약정')
            temp['미결제약정전일대비'] = self._get_comm_data(trcode, rqname, i, '미결제약정전일대비')
            temp['괴리율'] = self._get_comm_data(trcode, rqname, i, '괴리율')
            temp['이론가'] = self._get_comm_data(trcode, rqname, i, '이론가')
            temp['내재변동성'] = self._get_comm_data(trcode, rqname, i, '내재변동성')
            temp['내재가치'] = self._get_comm_data(trcode, rqname, i, '내재가치')
            temp['시간가치'] = self._get_comm_data(trcode, rqname, i, '시간가치')
            temp['델타'] = self._get_comm_data(trcode, rqname, i, '델타')
            temp['감마'] = self._get_comm_data(trcode, rqname, i, '감마')
            temp['세타'] = self._get_comm_data(trcode, rqname, i, '세타')
            temp['베가'] = self._get_comm_data(trcode, rqname, i, '베가')
            temp['로'] = self._get_comm_data(trcode, rqname, i, '로')
            self.opt50021_output['multi'].append(temp)

    def _opt50022(self, rqname, trcode):
        """
    	풋종목결제월별시세요청
    	"""
        self.opt50022_output = {'multi': []}

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['지수환산'] = self._get_comm_data(trcode, rqname, i, '지수환산')
            temp['ATM구분'] = self._get_comm_data(trcode, rqname, i, 'ATM구분')
            temp['종목코드'] = self._get_comm_data(trcode, rqname, i, '종목코드')
            temp['행사가'] = self._get_comm_data(trcode, rqname, i, '행사가')
            temp['현재가'] = self._get_comm_data(trcode, rqname, i, '현재가')
            temp['대비기호'] = self._get_comm_data(trcode, rqname, i, '대비기호')
            temp['전일대비'] = self._get_comm_data(trcode, rqname, i, '전일대비')
            temp['등락율'] = self._get_comm_data(trcode, rqname, i, '등락율')
            temp['시가'] = self._get_comm_data(trcode, rqname, i, '시가')
            temp['기준가대비시가등락율'] = self._get_comm_data(trcode, rqname, i, '기준가대비시가등락율')
            temp['고가'] = self._get_comm_data(trcode, rqname, i, '고가')
            temp['기준가대비고가등락율'] = self._get_comm_data(trcode, rqname, i, '기준가대비고가등락율')
            temp['저가'] = self._get_comm_data(trcode, rqname, i, '저가')
            temp['기준가대비저가등락율'] = self._get_comm_data(trcode, rqname, i, '기준가대비저가등락율')
            temp['기준가'] = self._get_comm_data(trcode, rqname, i, '기준가')
            temp['매도호가'] = self._get_comm_data(trcode, rqname, i, '매도호가')
            temp['매도호가수량'] = self._get_comm_data(trcode, rqname, i, '매도호가수량')
            temp['매수호가'] = self._get_comm_data(trcode, rqname, i, '매수호가')
            temp['매수호가수량'] = self._get_comm_data(trcode, rqname, i, '매수호가수량')
            temp['매도호가총잔량'] = self._get_comm_data(trcode, rqname, i, '매도호가총잔량')
            temp['매수호가총잔량'] = self._get_comm_data(trcode, rqname, i, '매수호가총잔량')
            temp['누적거래량'] = self._get_comm_data(trcode, rqname, i, '누적거래량')
            temp['누적거래대금'] = self._get_comm_data(trcode, rqname, i, '누적거래대금')
            temp['미결제약정'] = self._get_comm_data(trcode, rqname, i, '미결제약정')
            temp['미결제약정전일대비'] = self._get_comm_data(trcode, rqname, i, '미결제약정전일대비')
            temp['괴리율'] = self._get_comm_data(trcode, rqname, i, '괴리율')
            temp['이론가'] = self._get_comm_data(trcode, rqname, i, '이론가')
            temp['내재변동성'] = self._get_comm_data(trcode, rqname, i, '내재변동성')
            temp['내재가치'] = self._get_comm_data(trcode, rqname, i, '내재가치')
            temp['시간가치'] = self._get_comm_data(trcode, rqname, i, '시간가치')
            temp['델타'] = self._get_comm_data(trcode, rqname, i, '델타')
            temp['감마'] = self._get_comm_data(trcode, rqname, i, '감마')
            temp['세타'] = self._get_comm_data(trcode, rqname, i, '세타')
            temp['베가'] = self._get_comm_data(trcode, rqname, i, '베가')
            temp['로'] = self._get_comm_data(trcode, rqname, i, '로')
            self.opt50022_output['multi'].append(temp)

    def _opt50023(self, rqname, trcode):
        """
    	민감도지표추이요청
    	"""
        self.opt50023_output = {'single': dict(), 'multi': []}

        self.opt50023_output['single']['이론가'] = self._get_comm_data(trcode, rqname, 0, '이론가')
        self.opt50023_output['single']['괴리율'] = self._get_comm_data(trcode, rqname, 0, '괴리율')
        self.opt50023_output['single']['내재변동성'] = self._get_comm_data(trcode, rqname, 0, '내재변동성')
        self.opt50023_output['single']['시장베이시스'] = self._get_comm_data(trcode, rqname, 0, '시장베이시스')
        self.opt50023_output['single']['델타'] = self._get_comm_data(trcode, rqname, 0, '델타')
        self.opt50023_output['single']['베가'] = self._get_comm_data(trcode, rqname, 0, '베가')
        self.opt50023_output['single']['감마'] = self._get_comm_data(trcode, rqname, 0, '감마')
        self.opt50023_output['single']['로'] = self._get_comm_data(trcode, rqname, 0, '로')
        self.opt50023_output['single']['종목코드'] = self._get_comm_data(trcode, rqname, 0, '종목코드')
        self.opt50023_output['single']['종목명'] = self._get_comm_data(trcode, rqname, 0, '종목명')
        self.opt50023_output['single']['현재가'] = self._get_comm_data(trcode, rqname, 0, '현재가')
        self.opt50023_output['single']['대비기호'] = self._get_comm_data(trcode, rqname, 0, '대비기호')
        self.opt50023_output['single']['전일대비'] = self._get_comm_data(trcode, rqname, 0, '전일대비')
        self.opt50023_output['single']['등락율'] = self._get_comm_data(trcode, rqname, 0, '등락율')
        self.opt50023_output['single']['누적거래량'] = self._get_comm_data(trcode, rqname, 0, '누적거래량')
        self.opt50023_output['single']['누적거래대금'] = self._get_comm_data(trcode, rqname, 0, '누적거래대금')
        self.opt50023_output['single']['고가'] = self._get_comm_data(trcode, rqname, 0, '고가')
        self.opt50023_output['single']['저가'] = self._get_comm_data(trcode, rqname, 0, '저가')
        self.opt50023_output['single']['종목표준코드'] = self._get_comm_data(trcode, rqname, 0, '종목표준코드')
        self.opt50023_output['single']['내재가치'] = self._get_comm_data(trcode, rqname, 0, '내재가치')
        self.opt50023_output['single']['시간가치'] = self._get_comm_data(trcode, rqname, 0, '시간가치')

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['일자'] = self._get_comm_data(trcode, rqname, i, '일자')
            temp['체결시간'] = self._get_comm_data(trcode, rqname, i, '체결시간')
            temp['현재가n'] = self._get_comm_data(trcode, rqname, i, '현재가n')
            temp['이론가n '] = self._get_comm_data(trcode, rqname, i, '이론가n ')
            temp['내재변동성n'] = self._get_comm_data(trcode, rqname, i, '내재변동성n')
            temp['델타n'] = self._get_comm_data(trcode, rqname, i, '델타n')
            temp['감마n'] = self._get_comm_data(trcode, rqname, i, '감마n')
            temp['세타n'] = self._get_comm_data(trcode, rqname, i, '세타n')
            temp['베가n'] = self._get_comm_data(trcode, rqname, i, '베가n')
            temp['로n'] = self._get_comm_data(trcode, rqname, i, '로n')
            temp['시가'] = self._get_comm_data(trcode, rqname, i, '시가')
            temp['고가n'] = self._get_comm_data(trcode, rqname, i, '고가n')
            temp['저가n'] = self._get_comm_data(trcode, rqname, i, '저가n')
            temp['대비기호n'] = self._get_comm_data(trcode, rqname, i, '대비기호n')
            temp['전일대비n'] = self._get_comm_data(trcode, rqname, i, '전일대비n')
            temp['등락율n'] = self._get_comm_data(trcode, rqname, i, '등락율n')
            temp['누적거래량n'] = self._get_comm_data(trcode, rqname, i, '누적거래량n')
            temp['미결제약정n'] = self._get_comm_data(trcode, rqname, i, '미결제약정n')
            self.opt50023_output['multi'].append(temp)

    def _opt50024(self, rqname, trcode):
        """
    	일별변동성분석그래프요청
    	"""
        self.opt50024_output = {'multi': []}

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['일자'] = self._get_comm_data(trcode, rqname, i, '일자')
            temp['대표내재변동성'] = self._get_comm_data(trcode, rqname, i, '대표내재변동성')
            temp['콜내재변동성'] = self._get_comm_data(trcode, rqname, i, '콜내재변동성')
            temp['풋내재변동성'] = self._get_comm_data(trcode, rqname, i, '풋내재변동성')
            temp['선물대표내재변동성'] = self._get_comm_data(trcode, rqname, i, '선물대표내재변동성')
            temp['선물콜내재변동성'] = self._get_comm_data(trcode, rqname, i, '선물콜내재변동성')
            temp['선물풋내재변동성'] = self._get_comm_data(trcode, rqname, i, '선물풋내재변동성')
            temp['역사적변동성1'] = self._get_comm_data(trcode, rqname, i, '역사적변동성1')
            temp['역사적변동성2'] = self._get_comm_data(trcode, rqname, i, '역사적변동성2')
            temp['역사적변동성3'] = self._get_comm_data(trcode, rqname, i, '역사적변동성3')
            temp['선물역사적변동성1'] = self._get_comm_data(trcode, rqname, i, '선물역사적변동성1')
            temp['선물역사적변동성2'] = self._get_comm_data(trcode, rqname, i, '선물역사적변동성2')
            temp['선물역사적변동성3'] = self._get_comm_data(trcode, rqname, i, '선물역사적변동성3')
            temp['시작일자'] = self._get_comm_data(trcode, rqname, i, '시작일자')
            self.opt50024_output['multi'].append(temp)

    def _opt50025(self, rqname, trcode):
        """
    	시간별변동성분석그래프요청
    	"""
        self.opt50025_output = {'multi': []}

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['체결시간'] = self._get_comm_data(trcode, rqname, i, '체결시간')
            temp['대표내재변동성'] = self._get_comm_data(trcode, rqname, i, '대표내재변동성')
            temp['콜내재변동성'] = self._get_comm_data(trcode, rqname, i, '콜내재변동성')
            temp['풋내재변동성'] = self._get_comm_data(trcode, rqname, i, '풋내재변동성')
            temp['선물대표내재변동성'] = self._get_comm_data(trcode, rqname, i, '선물대표내재변동성')
            temp['선물콜내재변동성'] = self._get_comm_data(trcode, rqname, i, '선물콜내재변동성')
            temp['선물풋내재변동성'] = self._get_comm_data(trcode, rqname, i, '선물풋내재변동성')
            temp['역사적변동성1'] = self._get_comm_data(trcode, rqname, i, '역사적변동성1')
            temp['역사적변동성2'] = self._get_comm_data(trcode, rqname, i, '역사적변동성2')
            temp['역사적변동성3'] = self._get_comm_data(trcode, rqname, i, '역사적변동성3')
            temp['선물역사적변동성1'] = self._get_comm_data(trcode, rqname, i, '선물역사적변동성1')
            temp['선물역사적변동성2'] = self._get_comm_data(trcode, rqname, i, '선물역사적변동성2')
            temp['선물역사적변동성3'] = self._get_comm_data(trcode, rqname, i, '선물역사적변동성3')
            self.opt50025_output['multi'].append(temp)

    def _opt50026(self, rqname, trcode):
        """
    	선옵주문체결요청
    	"""
        self.opt50026_output = {'multi': []}

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['주문번호'] = self._get_comm_data(trcode, rqname, i, '주문번호')
            temp['종목코드'] = self._get_comm_data(trcode, rqname, i, '종목코드')
            temp['종목명'] = self._get_comm_data(trcode, rqname, i, '종목명')
            temp['주문구분'] = self._get_comm_data(trcode, rqname, i, '주문구분')
            temp['주문가격'] = self._get_comm_data(trcode, rqname, i, '주문가격')
            temp['주문수량'] = self._get_comm_data(trcode, rqname, i, '주문수량')
            temp['체결가'] = self._get_comm_data(trcode, rqname, i, '체결가')
            temp['체결량'] = self._get_comm_data(trcode, rqname, i, '체결량')
            temp['미체결수량'] = self._get_comm_data(trcode, rqname, i, '미체결수량')
            temp['주문상태'] = self._get_comm_data(trcode, rqname, i, '주문상태')
            temp['원주문번호'] = self._get_comm_data(trcode, rqname, i, '원주문번호')
            temp['매매구분'] = self._get_comm_data(trcode, rqname, i, '매매구분')
            temp['주문체결시간'] = self._get_comm_data(trcode, rqname, i, '주문체결시간')
            self.opt50026_output['multi'].append(temp)

    def _opt50027(self, rqname, trcode):
        """
    	선옵잔고요청
    	"""
        self.opt50027_output = {'multi': []}

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['계좌번호'] = self._get_comm_data(trcode, rqname, i, '계좌번호')
            temp['종목코드'] = self._get_comm_data(trcode, rqname, i, '종목코드')
            temp['신용구분'] = self._get_comm_data(trcode, rqname, i, '신용구분')
            temp['대출일'] = self._get_comm_data(trcode, rqname, i, '대출일')
            temp['종목명'] = self._get_comm_data(trcode, rqname, i, '종목명')
            temp['현재가'] = self._get_comm_data(trcode, rqname, i, '현재가')
            temp['등락율'] = self._get_comm_data(trcode, rqname, i, '등락율')
            temp['누적거래량'] = self._get_comm_data(trcode, rqname, i, '누적거래량')
            temp['보유수량'] = self._get_comm_data(trcode, rqname, i, '보유수량')
            temp['매입단가'] = self._get_comm_data(trcode, rqname, i, '매입단가')
            temp['총매입가'] = self._get_comm_data(trcode, rqname, i, '총매입가')
            temp['주문가능수량'] = self._get_comm_data(trcode, rqname, i, '주문가능수량')
            temp['당일매도수량'] = self._get_comm_data(trcode, rqname, i, '당일매도수량')
            temp['당일매도금액'] = self._get_comm_data(trcode, rqname, i, '당일매도금액')
            temp['당일매수수량'] = self._get_comm_data(trcode, rqname, i, '당일매수수량')
            temp['당일매수금액'] = self._get_comm_data(trcode, rqname, i, '당일매수금액')
            temp['당일매매수수료'] = self._get_comm_data(trcode, rqname, i, '당일매매수수료')
            temp['당일매매세금'] = self._get_comm_data(trcode, rqname, i, '당일매매세금')
            temp['당일HTS매도수수료'] = self._get_comm_data(trcode, rqname, i, '당일HTS매도수수료')
            temp['당일HTS매수수수료'] = self._get_comm_data(trcode, rqname, i, '당일HTS매수수수료')
            temp['D+2매수정산금'] = self._get_comm_data(trcode, rqname, i, 'D+2매수정산금')
            temp['당일매도손익'] = self._get_comm_data(trcode, rqname, i, '당일매도손익')
            temp['당일순매수량'] = self._get_comm_data(trcode, rqname, i, '당일순매수량')
            temp['매매구분'] = self._get_comm_data(trcode, rqname, i, '매매구분')
            temp['당일총매도손익'] = self._get_comm_data(trcode, rqname, i, '당일총매도손익')
            temp['예수금'] = self._get_comm_data(trcode, rqname, i, '예수금')
            temp['최우선매도호가'] = self._get_comm_data(trcode, rqname, i, '최우선매도호가')
            temp['최우선매수호가'] = self._get_comm_data(trcode, rqname, i, '최우선매수호가')
            temp['결제잔고'] = self._get_comm_data(trcode, rqname, i, '결제잔고')
            temp['결제금액'] = self._get_comm_data(trcode, rqname, i, '결제금액')
            temp['전일매도수량'] = self._get_comm_data(trcode, rqname, i, '전일매도수량')
            temp['전일매수수량'] = self._get_comm_data(trcode, rqname, i, '전일매수수량')
            temp['전일매도금액'] = self._get_comm_data(trcode, rqname, i, '전일매도금액')
            temp['전일매수금액'] = self._get_comm_data(trcode, rqname, i, '전일매수금액')
            temp['전일순매수량'] = self._get_comm_data(trcode, rqname, i, '전일순매수량')
            temp['손익율'] = self._get_comm_data(trcode, rqname, i, '손익율')
            temp['신용금액'] = self._get_comm_data(trcode, rqname, i, '신용금액')
            temp['신용이자'] = self._get_comm_data(trcode, rqname, i, '신용이자')
            temp['만기일'] = self._get_comm_data(trcode, rqname, i, '만기일')
            temp['기준가'] = self._get_comm_data(trcode, rqname, i, '기준가')
            temp['하한가'] = self._get_comm_data(trcode, rqname, i, '하한가')
            temp['상한가'] = self._get_comm_data(trcode, rqname, i, '상한가')
            temp['담보대출수량'] = self._get_comm_data(trcode, rqname, i, '담보대출수량')
            temp['연누적거래대금'] = self._get_comm_data(trcode, rqname, i, '연누적거래대금')
            self.opt50027_output['multi'].append(temp)

    def _opt50028(self, rqname, trcode):
        """
    	선물틱차트요청
    	"""
        self.opt50028_output = {'single': dict(), 'multi': []}

        self.opt50028_output['single']['종목코드'] = self._get_comm_data(trcode, rqname, 0, '종목코드')
        self.opt50028_output['single']['마지막틱갯수'] = self._get_comm_data(trcode, rqname, 0, '마지막틱갯수')

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['현재가'] = self._get_comm_data(trcode, rqname, i, '현재가')
            temp['거래량'] = self._get_comm_data(trcode, rqname, i, '거래량')
            temp['체결시간'] = self._get_comm_data(trcode, rqname, i, '체결시간')
            temp['시가'] = self._get_comm_data(trcode, rqname, i, '시가')
            temp['고가'] = self._get_comm_data(trcode, rqname, i, '고가')
            temp['저가'] = self._get_comm_data(trcode, rqname, i, '저가')
            temp['전일종가'] = self._get_comm_data(trcode, rqname, i, '전일종가')
            self.opt50028_output['multi'].append(temp)

    def _opt50029(self, rqname, trcode):
        """
    	선물옵션분차트요청
    	"""
        self.opt50029_output = {'multi': []}

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['현재가'] = self._get_comm_data(trcode, rqname, i, '현재가')
            temp['거래량'] = self._get_comm_data(trcode, rqname, i, '거래량')
            temp['체결시간'] = self._get_comm_data(trcode, rqname, i, '체결시간')
            temp['시가'] = self._get_comm_data(trcode, rqname, i, '시가')
            temp['고가'] = self._get_comm_data(trcode, rqname, i, '고가')
            temp['저가'] = self._get_comm_data(trcode, rqname, i, '저가')
            temp['수정주가이벤트'] = self._get_comm_data(trcode, rqname, i, '수정주가이벤트')
            temp['전일종가'] = self._get_comm_data(trcode, rqname, i, '전일종가')
            self.opt50029_output['multi'].append(temp)

    def _opt50030(self, rqname, trcode):
        """
    	선물옵션일차트요청
    	"""
        self.opt50030_output = {'multi': []}

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['현재가'] = self._get_comm_data(trcode, rqname, i, '현재가')
            temp['누적거래량'] = self._get_comm_data(trcode, rqname, i, '누적거래량')
            temp['일자'] = self._get_comm_data(trcode, rqname, i, '일자')
            temp['시가'] = self._get_comm_data(trcode, rqname, i, '시가')
            temp['고가'] = self._get_comm_data(trcode, rqname, i, '고가')
            temp['저가'] = self._get_comm_data(trcode, rqname, i, '저가')
            temp['수정주가이벤트'] = self._get_comm_data(trcode, rqname, i, '수정주가이벤트')
            temp['전일종가'] = self._get_comm_data(trcode, rqname, i, '전일종가')
            self.opt50030_output['multi'].append(temp)

    def _opt50031(self, rqname, trcode):
        """
    	선옵잔고손익요청
    	"""
        self.opt50031_output = {'multi': []}

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['종목코드'] = self._get_comm_data(trcode, rqname, i, '종목코드')
            temp['잔고구분'] = self._get_comm_data(trcode, rqname, i, '잔고구분')
            temp['당일매도손익'] = self._get_comm_data(trcode, rqname, i, '당일매도손익')
            temp['손익'] = self._get_comm_data(trcode, rqname, i, '손익')
            temp['손익율'] = self._get_comm_data(trcode, rqname, i, '손익율')
            temp['매입단가'] = self._get_comm_data(trcode, rqname, i, '매입단가')
            temp['보유수량'] = self._get_comm_data(trcode, rqname, i, '보유수량')
            temp['주문가능수량'] = self._get_comm_data(trcode, rqname, i, '주문가능수량')
            temp['현재가'] = self._get_comm_data(trcode, rqname, i, '현재가')
            temp['총매입가'] = self._get_comm_data(trcode, rqname, i, '총매입가')
            temp['평가금액'] = self._get_comm_data(trcode, rqname, i, '평가금액')
            temp['당일매매수수료'] = self._get_comm_data(trcode, rqname, i, '당일매매수수료')
            temp['종목명'] = self._get_comm_data(trcode, rqname, i, '종목명')
            self.opt50031_output['multi'].append(temp)

    def _opt50032(self, rqname, trcode):
        """
    	선옵당일실현손익요청
    	"""
        self.opt50032_output = {'multi': []}

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['종목코드'] = self._get_comm_data(trcode, rqname, i, '종목코드')
            temp['종목명'] = self._get_comm_data(trcode, rqname, i, '종목명')
            temp['체결구분'] = self._get_comm_data(trcode, rqname, i, '체결구분')
            temp['체결량'] = self._get_comm_data(trcode, rqname, i, '체결량')
            temp['매입단가'] = self._get_comm_data(trcode, rqname, i, '매입단가')
            temp['체결가'] = self._get_comm_data(trcode, rqname, i, '체결가')
            temp['당일매도손익'] = self._get_comm_data(trcode, rqname, i, '당일매도손익')
            temp['손익율'] = self._get_comm_data(trcode, rqname, i, '손익율')
            temp['당일매매수수료'] = self._get_comm_data(trcode, rqname, i, '당일매매수수료')
            self.opt50032_output['multi'].append(temp)

    def _opt50033(self, rqname, trcode):
        """
    	선옵잔존일조회요청
    	"""
        self.opt50033_output = {'single': dict()}

        self.opt50033_output['single']['대표내재변동성'] = self._get_comm_data(trcode, rqname, 0, '대표내재변동성')
        self.opt50033_output['single']['콜내재변동성'] = self._get_comm_data(trcode, rqname, 0, '콜내재변동성')
        self.opt50033_output['single']['풋내재변동성'] = self._get_comm_data(trcode, rqname, 0, '풋내재변동성')
        self.opt50033_output['single']['역사적변동성'] = self._get_comm_data(trcode, rqname, 0, '역사적변동성')
        self.opt50033_output['single']['잔존일수'] = self._get_comm_data(trcode, rqname, 0, '잔존일수')
        self.opt50033_output['single']['영업일기준잔존일'] = self._get_comm_data(trcode, rqname, 0, '영업일기준잔존일')
        self.opt50033_output['single']['차근달력기준잔존일'] = self._get_comm_data(trcode, rqname, 0, '차근달력기준잔존일')
        self.opt50033_output['single']['차근영업일기준잔존일'] = self._get_comm_data(trcode, rqname, 0, '차근영업일기준잔존일')
        self.opt50033_output['single']['차차근달력기준잔존일'] = self._get_comm_data(trcode, rqname, 0, '차차근달력기준잔존일')
        self.opt50033_output['single']['차차근영업일기준잔존일'] = self._get_comm_data(trcode, rqname, 0, '차차근영업일기준잔존일')
        self.opt50033_output['single']['차차차근달력기준잔존일'] = self._get_comm_data(trcode, rqname, 0, '차차차근달력기준잔존일')
        self.opt50033_output['single']['차차차근영업일기준잔존일'] = self._get_comm_data(trcode, rqname, 0, '차차차근영업일기준잔존일')
        self.opt50033_output['single']['선물대표내재변동성'] = self._get_comm_data(trcode, rqname, 0, '선물대표내재변동성')
        self.opt50033_output['single']['선물콜내재변동성'] = self._get_comm_data(trcode, rqname, 0, '선물콜내재변동성')
        self.opt50033_output['single']['선물풋내재변동성'] = self._get_comm_data(trcode, rqname, 0, '선물풋내재변동성')

    def _opt50034(self, rqname, trcode):
        """
    	선옵전일가격요청
    	"""
        self.opt50034_output = {'multi': []}

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['현재가'] = self._get_comm_data(trcode, rqname, i, '현재가')
            temp['체결시간'] = self._get_comm_data(trcode, rqname, i, '체결시간')
            self.opt50034_output['multi'].append(temp)

    def _opt50035(self, rqname, trcode):
        """
    	지수변동성차트요청
    	"""
        self.opt50035_output = {'multi': []}

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['현재가'] = self._get_comm_data(trcode, rqname, i, '현재가')
            temp['대비기호'] = self._get_comm_data(trcode, rqname, i, '대비기호')
            temp['전일대비'] = self._get_comm_data(trcode, rqname, i, '전일대비')
            temp['등락율'] = self._get_comm_data(trcode, rqname, i, '등락율')
            temp['시가'] = self._get_comm_data(trcode, rqname, i, '시가')
            temp['고가'] = self._get_comm_data(trcode, rqname, i, '고가')
            temp['저가'] = self._get_comm_data(trcode, rqname, i, '저가')
            temp['누적거래'] = self._get_comm_data(trcode, rqname, i, '누적거래')
            temp['거래량'] = self._get_comm_data(trcode, rqname, i, '거래량')
            self.opt50035_output['multi'].append(temp)

    def _opt50036(self, rqname, trcode):
        """
    	주요지수변동성차트요청
    	"""
        self.opt50036_output = {'multi': []}

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['일자'] = self._get_comm_data(trcode, rqname, i, '일자')
            temp['전일종가'] = self._get_comm_data(trcode, rqname, i, '전일종가')
            temp['선물역사적변동성'] = self._get_comm_data(trcode, rqname, i, '선물역사적변동성')
            self.opt50036_output['multi'].append(temp)

    def _opt50037(self, rqname, trcode):
        """
    	코스피200지수요청
    	"""
        self.opt50037_output = {'multi': []}

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['일자'] = self._get_comm_data(trcode, rqname, i, '일자')
            temp['코스피200'] = self._get_comm_data(trcode, rqname, i, '코스피200')
            self.opt50037_output['multi'].append(temp)

    def _opt50038(self, rqname, trcode):
        """
    	투자자별만기손익차트요청
    	"""
        self.opt50038_output = {'multi': []}

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['평가손익'] = self._get_comm_data(trcode, rqname, i, '평가손익')
            temp['매입단가'] = self._get_comm_data(trcode, rqname, i, '매입단가')
            temp['투자자별순매수수량'] = self._get_comm_data(trcode, rqname, i, '투자자별순매수수량')
            temp['미결제약정'] = self._get_comm_data(trcode, rqname, i, '미결제약정')
            temp['대비기호'] = self._get_comm_data(trcode, rqname, i, '대비기호')
            temp['전일대비'] = self._get_comm_data(trcode, rqname, i, '전일대비')
            temp['현재가'] = self._get_comm_data(trcode, rqname, i, '현재가')
            temp['종목코드'] = self._get_comm_data(trcode, rqname, i, '종목코드')
            temp['행사가            '] = self._get_comm_data(trcode, rqname, i, '행사가            ')
            temp['지수환산'] = self._get_comm_data(trcode, rqname, i, '지수환산')
            temp['ATM구분'] = self._get_comm_data(trcode, rqname, i, 'ATM구분')
            temp['대칭구분 '] = self._get_comm_data(trcode, rqname, i, '대칭구분 ')
            temp['풋_종목코드'] = self._get_comm_data(trcode, rqname, i, '풋_종목코드')
            temp['풋_현재가'] = self._get_comm_data(trcode, rqname, i, '풋_현재가')
            temp[''] = self._get_comm_data(trcode, rqname, i, '')
            temp['풋_전일대비'] = self._get_comm_data(trcode, rqname, i, '풋_전일대비')
            temp['풋_미결제약정'] = self._get_comm_data(trcode, rqname, i, '풋_미결제약정')
            temp['풋_투자자별순매수수량'] = self._get_comm_data(trcode, rqname, i, '풋_투자자별순매수수량')
            temp['풋_매입단가'] = self._get_comm_data(trcode, rqname, i, '풋_매입단가')
            temp['풋_평가손익'] = self._get_comm_data(trcode, rqname, i, '풋_평가손익')
            self.opt50038_output['multi'].append(temp)

    def _opt50039(self, rqname, trcode):
        """
    	투자자별포지션종합요청
    	"""
        self.opt50039_output = {'multi': []}

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['기간중주가등락'] = self._get_comm_data(trcode, rqname, i, '기간중주가등락')
            temp['기타법인'] = self._get_comm_data(trcode, rqname, i, '기타법인')
            temp['연기금등'] = self._get_comm_data(trcode, rqname, i, '연기금등')
            temp['기타금융'] = self._get_comm_data(trcode, rqname, i, '기타금융')
            temp['은행'] = self._get_comm_data(trcode, rqname, i, '은행')
            temp['투신'] = self._get_comm_data(trcode, rqname, i, '투신')
            temp['보험'] = self._get_comm_data(trcode, rqname, i, '보험')
            temp['금융투자'] = self._get_comm_data(trcode, rqname, i, '금융투자')
            temp['외국인'] = self._get_comm_data(trcode, rqname, i, '외국인')
            temp['개인'] = self._get_comm_data(trcode, rqname, i, '개인')
            temp['누적거래량'] = self._get_comm_data(trcode, rqname, i, '누적거래량')
            temp['미결제약정전일대비'] = self._get_comm_data(trcode, rqname, i, '미결제약정전일대비')
            temp['미결제약정'] = self._get_comm_data(trcode, rqname, i, '미결제약정')
            temp['대비기호'] = self._get_comm_data(trcode, rqname, i, '대비기호')
            temp['전일대비'] = self._get_comm_data(trcode, rqname, i, '전일대비')
            temp['등락율'] = self._get_comm_data(trcode, rqname, i, '등락율')
            temp['현재가'] = self._get_comm_data(trcode, rqname, i, '현재가')
            temp['종목코드'] = self._get_comm_data(trcode, rqname, i, '종목코드')
            temp['행사가'] = self._get_comm_data(trcode, rqname, i, '행사가')
            temp['지수환산'] = self._get_comm_data(trcode, rqname, i, '지수환산')
            temp['대칭구분      '] = self._get_comm_data(trcode, rqname, i, '대칭구분      ')
            temp['풋_종목코드'] = self._get_comm_data(trcode, rqname, i, '풋_종목코드')
            temp['풋_현재가'] = self._get_comm_data(trcode, rqname, i, '풋_현재가')
            temp['풋_등락율'] = self._get_comm_data(trcode, rqname, i, '풋_등락율')
            temp['풋_대비기호'] = self._get_comm_data(trcode, rqname, i, '풋_대비기호')
            temp['풋_전일대비'] = self._get_comm_data(trcode, rqname, i, '풋_전일대비')
            temp['풋_미결제약정'] = self._get_comm_data(trcode, rqname, i, '풋_미결제약정')
            temp['풋_미결제약정전일대비'] = self._get_comm_data(trcode, rqname, i, '풋_미결제약정전일대비')
            temp['풋_누적거래량'] = self._get_comm_data(trcode, rqname, i, '풋_누적거래량')
            temp['풋_ATM구분'] = self._get_comm_data(trcode, rqname, i, '풋_ATM구분')
            temp['풋_개인'] = self._get_comm_data(trcode, rqname, i, '풋_개인')
            temp['풋_외국인'] = self._get_comm_data(trcode, rqname, i, '풋_외국인')
            temp['풋_금융투자   '] = self._get_comm_data(trcode, rqname, i, '풋_금융투자   ')
            temp['풋_보험       '] = self._get_comm_data(trcode, rqname, i, '풋_보험       ')
            temp['풋_투신       '] = self._get_comm_data(trcode, rqname, i, '풋_투신       ')
            temp['풋_은행       '] = self._get_comm_data(trcode, rqname, i, '풋_은행       ')
            temp['풋_기타금융   '] = self._get_comm_data(trcode, rqname, i, '풋_기타금융   ')
            temp['풋_연기금등   '] = self._get_comm_data(trcode, rqname, i, '풋_연기금등   ')
            temp['풋_기타법인   '] = self._get_comm_data(trcode, rqname, i, '풋_기타법인   ')
            temp['풋_기간중주가등락'] = self._get_comm_data(trcode, rqname, i, '풋_기간중주가등락')
            self.opt50039_output['multi'].append(temp)

    def _opt50040(self, rqname, trcode):
        """
    	선옵시고저가요청
    	"""
        self.opt50040_output = {'multi': []}

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['일자'] = self._get_comm_data(trcode, rqname, i, '일자')
            temp['현재가'] = self._get_comm_data(trcode, rqname, i, '현재가')
            temp['기준가'] = self._get_comm_data(trcode, rqname, i, '기준가')
            temp['체결량'] = self._get_comm_data(trcode, rqname, i, '체결량')
            temp['시가'] = self._get_comm_data(trcode, rqname, i, '시가')
            temp['고가'] = self._get_comm_data(trcode, rqname, i, '고가')
            temp['저가'] = self._get_comm_data(trcode, rqname, i, '저가')
            temp['시초미결제약정수량'] = self._get_comm_data(trcode, rqname, i, '시초미결제약정수량')
            temp['최고미결제약정수량'] = self._get_comm_data(trcode, rqname, i, '최고미결제약정수량')
            temp['최저미결제약정수량'] = self._get_comm_data(trcode, rqname, i, '최저미결제약정수량')
            temp['미결제약정'] = self._get_comm_data(trcode, rqname, i, '미결제약정')
            temp['전일미결제약정'] = self._get_comm_data(trcode, rqname, i, '전일미결제약정')
            temp['이론가'] = self._get_comm_data(trcode, rqname, i, '이론가')
            temp['내재변동성'] = self._get_comm_data(trcode, rqname, i, '내재변동성')
            temp['델타'] = self._get_comm_data(trcode, rqname, i, '델타')
            temp['감마'] = self._get_comm_data(trcode, rqname, i, '감마')
            temp['상한가'] = self._get_comm_data(trcode, rqname, i, '상한가')
            temp['하한가'] = self._get_comm_data(trcode, rqname, i, '하한가')
            temp['시장베이시스'] = self._get_comm_data(trcode, rqname, i, '시장베이시스')
            temp['괴리율'] = self._get_comm_data(trcode, rqname, i, '괴리율')
            self.opt50040_output['multi'].append(temp)

    def _opt50043(self, rqname, trcode):
        """
    	주식선물거래량상위종목요청
    	"""
        self.opt50043_output = {'multi': []}

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['종목코드'] = self._get_comm_data(trcode, rqname, i, '종목코드')
            temp['종목표준코드'] = self._get_comm_data(trcode, rqname, i, '종목표준코드')
            temp['종목명'] = self._get_comm_data(trcode, rqname, i, '종목명')
            temp['현재가'] = self._get_comm_data(trcode, rqname, i, '현재가')
            temp['대비기호'] = self._get_comm_data(trcode, rqname, i, '대비기호')
            temp['전일대비'] = self._get_comm_data(trcode, rqname, i, '전일대비')
            temp['등락율'] = self._get_comm_data(trcode, rqname, i, '등락율')
            temp['누적거래량'] = self._get_comm_data(trcode, rqname, i, '누적거래량')
            self.opt50043_output['multi'].append(temp)

    def _opt50044(self, rqname, trcode):
        """
    	주식선물시세표요청
    	"""
        self.opt50044_output = {'single': dict(), 'multi': []}

        self.opt50044_output['single']['거래량합계'] = self._get_comm_data(trcode, rqname, 0, '거래량합계')
        self.opt50044_output['single']['거래대금합계'] = self._get_comm_data(trcode, rqname, 0, '거래대금합계')

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['종목코드'] = self._get_comm_data(trcode, rqname, i, '종목코드')
            temp['종목표준코드'] = self._get_comm_data(trcode, rqname, i, '종목표준코드')
            temp['종목명'] = self._get_comm_data(trcode, rqname, i, '종목명')
            temp['현재가'] = self._get_comm_data(trcode, rqname, i, '현재가')
            temp['대비기호'] = self._get_comm_data(trcode, rqname, i, '대비기호')
            temp['전일대비'] = self._get_comm_data(trcode, rqname, i, '전일대비')
            temp['등락율'] = self._get_comm_data(trcode, rqname, i, '등락율')
            temp['누적거래량'] = self._get_comm_data(trcode, rqname, i, '누적거래량')
            temp['누적거래대금'] = self._get_comm_data(trcode, rqname, i, '누적거래대금')
            temp['미결제약정'] = self._get_comm_data(trcode, rqname, i, '미결제약정')
            temp['미결제약정전일대비'] = self._get_comm_data(trcode, rqname, i, '미결제약정전일대비')
            temp['이론가'] = self._get_comm_data(trcode, rqname, i, '이론가')
            temp['괴리율'] = self._get_comm_data(trcode, rqname, i, '괴리율')
            temp['시장베이시스'] = self._get_comm_data(trcode, rqname, i, '시장베이시스')
            temp['최우선매수호가'] = self._get_comm_data(trcode, rqname, i, '최우선매수호가')
            temp['최우선매도호가'] = self._get_comm_data(trcode, rqname, i, '최우선매도호가')
            temp['코스피200'] = self._get_comm_data(trcode, rqname, i, '코스피200')
            self.opt50044_output['multi'].append(temp)

    def _opt50062(self, rqname, trcode):
        """
    	선물미결제약정분차트요청
    	"""
        self.opt50062_output = {'single': dict(), 'multi': []}

        self.opt50062_output['single']['현재가s'] = self._get_comm_data(trcode, rqname, 0, '현재가s')
        self.opt50062_output['single']['대비기호s'] = self._get_comm_data(trcode, rqname, 0, '대비기호s')
        self.opt50062_output['single']['전일대비s'] = self._get_comm_data(trcode, rqname, 0, '전일대비s')
        self.opt50062_output['single']['등락율s'] = self._get_comm_data(trcode, rqname, 0, '등락율s')
        self.opt50062_output['single']['고가s'] = self._get_comm_data(trcode, rqname, 0, '고가s')
        self.opt50062_output['single']['저가s'] = self._get_comm_data(trcode, rqname, 0, '저가s')
        self.opt50062_output['single']['누적거래량s'] = self._get_comm_data(trcode, rqname, 0, '누적거래량s')
        self.opt50062_output['single']['미결제약정s'] = self._get_comm_data(trcode, rqname, 0, '미결제약정s')
        self.opt50062_output['single']['종목명s'] = self._get_comm_data(trcode, rqname, 0, '종목명s')

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['현재가'] = self._get_comm_data(trcode, rqname, i, '현재가')
            temp['체결시간'] = self._get_comm_data(trcode, rqname, i, '체결시간')
            temp['미결제약정'] = self._get_comm_data(trcode, rqname, i, '미결제약정')
            temp['미결제증감'] = self._get_comm_data(trcode, rqname, i, '미결제증감')
            self.opt50062_output['multi'].append(temp)

    def _opt50063(self, rqname, trcode):
        """
    	옵션미결제약정일차트요청
    	"""
        self.opt50063_output = {'single': dict(), 'multi': []}

        self.opt50063_output['single']['현재가s'] = self._get_comm_data(trcode, rqname, 0, '현재가s')
        self.opt50063_output['single']['대비기호s'] = self._get_comm_data(trcode, rqname, 0, '대비기호s')
        self.opt50063_output['single']['전일대비s'] = self._get_comm_data(trcode, rqname, 0, '전일대비s')
        self.opt50063_output['single']['등락율s'] = self._get_comm_data(trcode, rqname, 0, '등락율s')
        self.opt50063_output['single']['고가s'] = self._get_comm_data(trcode, rqname, 0, '고가s')
        self.opt50063_output['single']['저가s'] = self._get_comm_data(trcode, rqname, 0, '저가s')
        self.opt50063_output['single']['누적거래량s'] = self._get_comm_data(trcode, rqname, 0, '누적거래량s')
        self.opt50063_output['single']['미결제약정s'] = self._get_comm_data(trcode, rqname, 0, '미결제약정s')
        self.opt50063_output['single']['종목명s'] = self._get_comm_data(trcode, rqname, 0, '종목명s')

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['현재가'] = self._get_comm_data(trcode, rqname, i, '현재가')
            temp['체결시간'] = self._get_comm_data(trcode, rqname, i, '체결시간')
            temp['미결제약정'] = self._get_comm_data(trcode, rqname, i, '미결제약정')
            temp['미결제증감'] = self._get_comm_data(trcode, rqname, i, '미결제증감')
            self.opt50063_output['multi'].append(temp)

    def _opt50064(self, rqname, trcode):
        """
    	옵션미결제약정분차트요청
    	"""
        self.opt50064_output = {'single': dict(), 'multi': []}

        self.opt50064_output['single']['현재가s'] = self._get_comm_data(trcode, rqname, 0, '현재가s')
        self.opt50064_output['single']['대비기호s'] = self._get_comm_data(trcode, rqname, 0, '대비기호s')
        self.opt50064_output['single']['전일대비s'] = self._get_comm_data(trcode, rqname, 0, '전일대비s')
        self.opt50064_output['single']['등락율s'] = self._get_comm_data(trcode, rqname, 0, '등락율s')
        self.opt50064_output['single']['고가s'] = self._get_comm_data(trcode, rqname, 0, '고가s')
        self.opt50064_output['single']['저가s'] = self._get_comm_data(trcode, rqname, 0, '저가s')
        self.opt50064_output['single']['누적거래량s'] = self._get_comm_data(trcode, rqname, 0, '누적거래량s')
        self.opt50064_output['single']['미결제약정s'] = self._get_comm_data(trcode, rqname, 0, '미결제약정s')
        self.opt50064_output['single']['종목명s'] = self._get_comm_data(trcode, rqname, 0, '종목명s')

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['현재가'] = self._get_comm_data(trcode, rqname, i, '현재가')
            temp['체결시간'] = self._get_comm_data(trcode, rqname, i, '체결시간')
            temp['미결제약정'] = self._get_comm_data(trcode, rqname, i, '미결제약정')
            temp['미결제증감'] = self._get_comm_data(trcode, rqname, i, '미결제증감')
            self.opt50064_output['multi'].append(temp)

    def _opt50065(self, rqname, trcode):
        """
    	풋옵션행사가요청
    	"""
        self.opt50065_output = {'multi': []}

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['종목코드'] = self._get_comm_data(trcode, rqname, i, '종목코드')
            temp['ATM구분'] = self._get_comm_data(trcode, rqname, i, 'ATM구분')
            temp['행사가'] = self._get_comm_data(trcode, rqname, i, '행사가')
            self.opt50065_output['multi'].append(temp)

    def _opt50066(self, rqname, trcode):
        """
    	옵션틱차트요청
    	"""
        self.opt50066_output = {'single': dict(), 'multi': []}

        self.opt50066_output['single']['종목코드'] = self._get_comm_data(trcode, rqname, 0, '종목코드')
        self.opt50066_output['single']['마지막틱갯수'] = self._get_comm_data(trcode, rqname, 0, '마지막틱갯수')

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['현재가'] = self._get_comm_data(trcode, rqname, i, '현재가')
            temp['거래량'] = self._get_comm_data(trcode, rqname, i, '거래량')
            temp['체결시간'] = self._get_comm_data(trcode, rqname, i, '체결시간')
            temp['시가'] = self._get_comm_data(trcode, rqname, i, '시가')
            temp['고가'] = self._get_comm_data(trcode, rqname, i, '고가')
            temp['저가'] = self._get_comm_data(trcode, rqname, i, '저가')
            temp['전일종가'] = self._get_comm_data(trcode, rqname, i, '전일종가')
            self.opt50066_output['multi'].append(temp)

    def _opt50067(self, rqname, trcode):
        """
    	옵션분차트요청
    	"""
        self.opt50067_output = {'multi': []}

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['현재가'] = self._get_comm_data(trcode, rqname, i, '현재가')
            temp['거래량'] = self._get_comm_data(trcode, rqname, i, '거래량')
            temp['체결시간'] = self._get_comm_data(trcode, rqname, i, '체결시간')
            temp['시가'] = self._get_comm_data(trcode, rqname, i, '시가')
            temp['고가'] = self._get_comm_data(trcode, rqname, i, '고가')
            temp['저가'] = self._get_comm_data(trcode, rqname, i, '저가')
            temp['전일종가'] = self._get_comm_data(trcode, rqname, i, '전일종가')
            self.opt50067_output['multi'].append(temp)

    def _opt50068(self, rqname, trcode):
        """
    	옵션일차트요청
    	"""
        self.opt50068_output = {'multi': []}

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['현재가'] = self._get_comm_data(trcode, rqname, i, '현재가')
            temp['누적거래량'] = self._get_comm_data(trcode, rqname, i, '누적거래량')
            temp['일자'] = self._get_comm_data(trcode, rqname, i, '일자')
            temp['시가'] = self._get_comm_data(trcode, rqname, i, '시가')
            temp['고가'] = self._get_comm_data(trcode, rqname, i, '고가')
            temp['저가'] = self._get_comm_data(trcode, rqname, i, '저가')
            temp['전일종가'] = self._get_comm_data(trcode, rqname, i, '전일종가')
            self.opt50068_output['multi'].append(temp)

    def _opt50071(self, rqname, trcode):
        """
    	선물주차트요청
    	"""
        self.opt50071_output = {'multi': []}

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['현재가'] = self._get_comm_data(trcode, rqname, i, '현재가')
            temp['누적거래량'] = self._get_comm_data(trcode, rqname, i, '누적거래량')
            temp['일자'] = self._get_comm_data(trcode, rqname, i, '일자')
            temp['시가'] = self._get_comm_data(trcode, rqname, i, '시가')
            temp['고가'] = self._get_comm_data(trcode, rqname, i, '고가')
            temp['저가'] = self._get_comm_data(trcode, rqname, i, '저가')
            temp['전일종가'] = self._get_comm_data(trcode, rqname, i, '전일종가')
            self.opt50071_output['multi'].append(temp)

    def _opt50072(self, rqname, trcode):
        """
    	선물월차트요청
    	"""
        self.opt50072_output = {'multi': []}

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['현재가'] = self._get_comm_data(trcode, rqname, i, '현재가')
            temp['누적거래량'] = self._get_comm_data(trcode, rqname, i, '누적거래량')
            temp['일자'] = self._get_comm_data(trcode, rqname, i, '일자')
            temp['시가'] = self._get_comm_data(trcode, rqname, i, '시가')
            temp['고가'] = self._get_comm_data(trcode, rqname, i, '고가')
            temp['저가'] = self._get_comm_data(trcode, rqname, i, '저가')
            temp['전일종가'] = self._get_comm_data(trcode, rqname, i, '전일종가')
            self.opt50072_output['multi'].append(temp)

    def _opt50073(self, rqname, trcode):
        """
    	선물년차트요청
    	"""
        self.opt50073_output = {'multi': []}

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['현재가'] = self._get_comm_data(trcode, rqname, i, '현재가')
            temp['누적거래량'] = self._get_comm_data(trcode, rqname, i, '누적거래량')
            temp['일자'] = self._get_comm_data(trcode, rqname, i, '일자')
            temp['시가'] = self._get_comm_data(trcode, rqname, i, '시가')
            temp['고가'] = self._get_comm_data(trcode, rqname, i, '고가')
            temp['저가'] = self._get_comm_data(trcode, rqname, i, '저가')
            temp['전일종가'] = self._get_comm_data(trcode, rqname, i, '전일종가')
            self.opt50073_output['multi'].append(temp)

    def _opt90001(self, rqname, trcode):
        """
    	테마그룹별요청
    	"""
        self.opt90001_output = {'multi': []}

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['종목코드'] = self._get_comm_data(trcode, rqname, i, '종목코드')
            temp['테마명'] = self._get_comm_data(trcode, rqname, i, '테마명')
            temp['종목수'] = self._get_comm_data(trcode, rqname, i, '종목수')
            temp['등락기호'] = self._get_comm_data(trcode, rqname, i, '등락기호')
            temp['등락율'] = self._get_comm_data(trcode, rqname, i, '등락율')
            temp['상승종목수'] = self._get_comm_data(trcode, rqname, i, '상승종목수')
            temp['하락종목수'] = self._get_comm_data(trcode, rqname, i, '하락종목수')
            temp['기간수익률'] = self._get_comm_data(trcode, rqname, i, '기간수익률')
            temp['주요종목'] = self._get_comm_data(trcode, rqname, i, '주요종목')
            self.opt90001_output['multi'].append(temp)

    def _opt90002(self, rqname, trcode):
        """
    	테마구성종목요청
    	"""
        self.opt90002_output = {'single': dict(), 'multi': []}

        self.opt90002_output['single']['등락률'] = self._get_comm_data(trcode, rqname, 0, '등락률')
        self.opt90002_output['single']['기간수익률'] = self._get_comm_data(trcode, rqname, 0, '기간수익률')

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['종목코드'] = self._get_comm_data(trcode, rqname, i, '종목코드')
            temp['종목명'] = self._get_comm_data(trcode, rqname, i, '종목명')
            temp['현재가'] = self._get_comm_data(trcode, rqname, i, '현재가')
            temp['등락기호'] = self._get_comm_data(trcode, rqname, i, '등락기호')
            temp['전일대비'] = self._get_comm_data(trcode, rqname, i, '전일대비')
            temp['등락율'] = self._get_comm_data(trcode, rqname, i, '등락율')
            temp['누적거래량'] = self._get_comm_data(trcode, rqname, i, '누적거래량')
            temp['매도호가'] = self._get_comm_data(trcode, rqname, i, '매도호가')
            temp['매도잔량'] = self._get_comm_data(trcode, rqname, i, '매도잔량')
            temp['매수호가'] = self._get_comm_data(trcode, rqname, i, '매수호가')
            temp['매수잔량'] = self._get_comm_data(trcode, rqname, i, '매수잔량')
            temp['기간수익률n'] = self._get_comm_data(trcode, rqname, i, '기간수익률n')
            self.opt90002_output['multi'].append(temp)

    def _opt90003(self, rqname, trcode):
        """
    	프로그램순매수상위50요청
    	"""
        self.opt90003_output = {'multi': []}

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['순위'] = self._get_comm_data(trcode, rqname, i, '순위')
            temp['종목코드'] = self._get_comm_data(trcode, rqname, i, '종목코드')
            temp['종목명'] = self._get_comm_data(trcode, rqname, i, '종목명')
            temp['현재가'] = self._get_comm_data(trcode, rqname, i, '현재가')
            temp['등락기호'] = self._get_comm_data(trcode, rqname, i, '등락기호')
            temp['전일대비'] = self._get_comm_data(trcode, rqname, i, '전일대비')
            temp['등락율'] = self._get_comm_data(trcode, rqname, i, '등락율')
            temp['누적거래량'] = self._get_comm_data(trcode, rqname, i, '누적거래량')
            temp['프로그램매도금액'] = self._get_comm_data(trcode, rqname, i, '프로그램매도금액')
            temp['프로그램매수금액'] = self._get_comm_data(trcode, rqname, i, '프로그램매수금액')
            temp['프로그램순매수금액'] = self._get_comm_data(trcode, rqname, i, '프로그램순매수금액')
            self.opt90003_output['multi'].append(temp)

    def _opt90004(self, rqname, trcode):
        """
    	종목별프로그램매매현황요청
    	"""
        self.opt90004_output = {'single': dict(), 'multi': []}

        self.opt90004_output['single']['합계1'] = self._get_comm_data(trcode, rqname, 0, '합계1')
        self.opt90004_output['single']['합계2'] = self._get_comm_data(trcode, rqname, 0, '합계2')
        self.opt90004_output['single']['합계3'] = self._get_comm_data(trcode, rqname, 0, '합계3')
        self.opt90004_output['single']['합계4'] = self._get_comm_data(trcode, rqname, 0, '합계4')
        self.opt90004_output['single']['합계5'] = self._get_comm_data(trcode, rqname, 0, '합계5')
        self.opt90004_output['single']['합계6'] = self._get_comm_data(trcode, rqname, 0, '합계6')

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['종목코드'] = self._get_comm_data(trcode, rqname, i, '종목코드')
            temp['종목명'] = self._get_comm_data(trcode, rqname, i, '종목명')
            temp['현재가'] = self._get_comm_data(trcode, rqname, i, '현재가')
            temp['등락기호'] = self._get_comm_data(trcode, rqname, i, '등락기호')
            temp['전일대비'] = self._get_comm_data(trcode, rqname, i, '전일대비')
            temp['매수체결수량'] = self._get_comm_data(trcode, rqname, i, '매수체결수량')
            temp['매수체결금액'] = self._get_comm_data(trcode, rqname, i, '매수체결금액')
            temp['매도체결수량'] = self._get_comm_data(trcode, rqname, i, '매도체결수량')
            temp['매도체결금액'] = self._get_comm_data(trcode, rqname, i, '매도체결금액')
            temp['순매수대금'] = self._get_comm_data(trcode, rqname, i, '순매수대금')
            temp['전체거래비율'] = self._get_comm_data(trcode, rqname, i, '전체거래비율')
            self.opt90004_output['multi'].append(temp)

    def _opt90005(self, rqname, trcode):
        """
    	프로그램매매추이요청
    	"""
        self.opt90005_output = {'multi': []}

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['체결시간'] = self._get_comm_data(trcode, rqname, i, '체결시간')
            temp['차익거래매도'] = self._get_comm_data(trcode, rqname, i, '차익거래매도')
            temp['차익거래매수'] = self._get_comm_data(trcode, rqname, i, '차익거래매수')
            temp['차익거래순매수'] = self._get_comm_data(trcode, rqname, i, '차익거래순매수')
            temp['비차익거래매도'] = self._get_comm_data(trcode, rqname, i, '비차익거래매도')
            temp['비차익거래매수'] = self._get_comm_data(trcode, rqname, i, '비차익거래매수')
            temp['비차익거래순매수'] = self._get_comm_data(trcode, rqname, i, '비차익거래순매수')
            temp['차익거래매도수량'] = self._get_comm_data(trcode, rqname, i, '차익거래매도수량')
            temp['차익거래매수수량'] = self._get_comm_data(trcode, rqname, i, '차익거래매수수량')
            temp['차익거래순매수수량'] = self._get_comm_data(trcode, rqname, i, '차익거래순매수수량')
            temp['비차익거래매도수량'] = self._get_comm_data(trcode, rqname, i, '비차익거래매도수량')
            temp['비차익거래매수수량'] = self._get_comm_data(trcode, rqname, i, '비차익거래매수수량')
            temp['비차익거래순매수수량'] = self._get_comm_data(trcode, rqname, i, '비차익거래순매수수량')
            temp['전체매도'] = self._get_comm_data(trcode, rqname, i, '전체매도')
            temp['전체매수'] = self._get_comm_data(trcode, rqname, i, '전체매수')
            temp['전체순매수'] = self._get_comm_data(trcode, rqname, i, '전체순매수')
            temp['KOSPI200'] = self._get_comm_data(trcode, rqname, i, 'KOSPI200')
            temp['BASIS'] = self._get_comm_data(trcode, rqname, i, 'BASIS')
            self.opt90005_output['multi'].append(temp)

    def _opt90006(self, rqname, trcode):
        """
    	프로그램매매차익잔고추이요청
    	"""
        self.opt90006_output = {'multi': []}

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['일자'] = self._get_comm_data(trcode, rqname, i, '일자')
            temp['매수차익거래수량'] = self._get_comm_data(trcode, rqname, i, '매수차익거래수량')
            temp['매수차익거래금액'] = self._get_comm_data(trcode, rqname, i, '매수차익거래금액')
            temp['매수차익거래증감액'] = self._get_comm_data(trcode, rqname, i, '매수차익거래증감액')
            temp['매도차익거래수량'] = self._get_comm_data(trcode, rqname, i, '매도차익거래수량')
            temp['매도차익거래금액'] = self._get_comm_data(trcode, rqname, i, '매도차익거래금액')
            temp['매도차익거래증감액'] = self._get_comm_data(trcode, rqname, i, '매도차익거래증감액')
            self.opt90006_output['multi'].append(temp)

    def _opt90007(self, rqname, trcode):
        """
    	프로그램매매누적추이요청
    	"""
        self.opt90007_output = {'multi': []}

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['일자'] = self._get_comm_data(trcode, rqname, i, '일자')
            temp['KOSPI200'] = self._get_comm_data(trcode, rqname, i, 'KOSPI200')
            temp['BASIS'] = self._get_comm_data(trcode, rqname, i, 'BASIS')
            temp['차익거래당일'] = self._get_comm_data(trcode, rqname, i, '차익거래당일')
            temp['차익거래누적'] = self._get_comm_data(trcode, rqname, i, '차익거래누적')
            temp['비차익거래당일'] = self._get_comm_data(trcode, rqname, i, '비차익거래당일')
            temp['비차익거래누적'] = self._get_comm_data(trcode, rqname, i, '비차익거래누적')
            temp['전체당일'] = self._get_comm_data(trcode, rqname, i, '전체당일')
            temp['전체누적'] = self._get_comm_data(trcode, rqname, i, '전체누적')
            self.opt90007_output['multi'].append(temp)

    def _opt90008(self, rqname, trcode):
        """
    	종목시간별프로그램매매추이요청
    	"""
        self.opt90008_output = {'multi': []}

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['시간'] = self._get_comm_data(trcode, rqname, i, '시간')
            temp['현재가'] = self._get_comm_data(trcode, rqname, i, '현재가')
            temp['대비기호'] = self._get_comm_data(trcode, rqname, i, '대비기호')
            temp['전일대비'] = self._get_comm_data(trcode, rqname, i, '전일대비')
            temp['등락율'] = self._get_comm_data(trcode, rqname, i, '등락율')
            temp['거래량'] = self._get_comm_data(trcode, rqname, i, '거래량')
            temp['프로그램매도금액'] = self._get_comm_data(trcode, rqname, i, '프로그램매도금액')
            temp['프로그램매수금액'] = self._get_comm_data(trcode, rqname, i, '프로그램매수금액')
            temp['프로그램순매수금액'] = self._get_comm_data(trcode, rqname, i, '프로그램순매수금액')
            temp['프로그램순매수금액증감'] = self._get_comm_data(trcode, rqname, i, '프로그램순매수금액증감')
            temp['프로그램매도수량'] = self._get_comm_data(trcode, rqname, i, '프로그램매도수량')
            temp['프로그램매수수량'] = self._get_comm_data(trcode, rqname, i, '프로그램매수수량')
            temp['프로그램순매수수량'] = self._get_comm_data(trcode, rqname, i, '프로그램순매수수량')
            temp['프로그램순매수수량증감'] = self._get_comm_data(trcode, rqname, i, '프로그램순매수수량증감')
            temp['기준가시간'] = self._get_comm_data(trcode, rqname, i, '기준가시간')
            temp['대차거래상환주수합'] = self._get_comm_data(trcode, rqname, i, '대차거래상환주수합')
            temp['잔고수주합'] = self._get_comm_data(trcode, rqname, i, '잔고수주합')
            self.opt90008_output['multi'].append(temp)

    def _opt90009(self, rqname, trcode):
        """
    	외국인기관매매상위요청
    	"""
        self.opt90009_output = {'single': dict(), 'multi': []}

        self.opt90009_output['single']['기준일자'] = self._get_comm_data(trcode, rqname, 0, '기준일자')

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['외인순매도종목코드'] = self._get_comm_data(trcode, rqname, i, '외인순매도종목코드')
            temp['외인순매도종목명'] = self._get_comm_data(trcode, rqname, i, '외인순매도종목명')
            temp['외인순매도금액'] = self._get_comm_data(trcode, rqname, i, '외인순매도금액')
            temp['외인순매도수량'] = self._get_comm_data(trcode, rqname, i, '외인순매도수량')
            temp['외인순매수종목코드'] = self._get_comm_data(trcode, rqname, i, '외인순매수종목코드')
            temp['외인순매수종목명'] = self._get_comm_data(trcode, rqname, i, '외인순매수종목명')
            temp['외인순매수금액'] = self._get_comm_data(trcode, rqname, i, '외인순매수금액')
            temp['외인순매수수량'] = self._get_comm_data(trcode, rqname, i, '외인순매수수량')
            temp['기관순매도종목코드'] = self._get_comm_data(trcode, rqname, i, '기관순매도종목코드')
            temp['기관순매도종목명'] = self._get_comm_data(trcode, rqname, i, '기관순매도종목명')
            temp['기관순매도금액'] = self._get_comm_data(trcode, rqname, i, '기관순매도금액')
            temp['기관순매도수량'] = self._get_comm_data(trcode, rqname, i, '기관순매도수량')
            temp['기관순매수종목코드'] = self._get_comm_data(trcode, rqname, i, '기관순매수종목코드')
            temp['기관순매수종목명'] = self._get_comm_data(trcode, rqname, i, '기관순매수종목명')
            temp['기관순매수금액'] = self._get_comm_data(trcode, rqname, i, '기관순매수금액')
            temp['기관순매수수량'] = self._get_comm_data(trcode, rqname, i, '기관순매수수량')
            self.opt90009_output['multi'].append(temp)

    def _opt90010(self, rqname, trcode):
        """
    	차익잔고현황요청
    	"""
        self.opt90010_output = {'single': dict(), 'multi': []}

        self.opt90010_output['single']['기준일자'] = self._get_comm_data(trcode, rqname, 0, '기준일자')

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['종목코드1'] = self._get_comm_data(trcode, rqname, i, '종목코드1')
            temp['차익매도위탁금액'] = self._get_comm_data(trcode, rqname, i, '차익매도위탁금액')
            temp['차익매수위탁금액'] = self._get_comm_data(trcode, rqname, i, '차익매수위탁금액')
            temp['차익매도위탁선물금액'] = self._get_comm_data(trcode, rqname, i, '차익매도위탁선물금액')
            temp['차익매수위탁선물금액'] = self._get_comm_data(trcode, rqname, i, '차익매수위탁선물금액')
            temp['차익매도위탁CALL금액'] = self._get_comm_data(trcode, rqname, i, '차익매도위탁CALL금액')
            temp['차익매수위탁CALL금액'] = self._get_comm_data(trcode, rqname, i, '차익매수위탁CALL금액')
            temp['차익매도위탁PUT금액'] = self._get_comm_data(trcode, rqname, i, '차익매도위탁PUT금액')
            temp['차익매수위탁PUT금액'] = self._get_comm_data(trcode, rqname, i, '차익매수위탁PUT금액')
            temp['차익매도자기금액'] = self._get_comm_data(trcode, rqname, i, '차익매도자기금액')
            temp['차익매수자기금액'] = self._get_comm_data(trcode, rqname, i, '차익매수자기금액')
            temp['차익매도자기선물금액'] = self._get_comm_data(trcode, rqname, i, '차익매도자기선물금액')
            temp['차익매수자기선물금액'] = self._get_comm_data(trcode, rqname, i, '차익매수자기선물금액')
            temp['차익매도자기CALL금액'] = self._get_comm_data(trcode, rqname, i, '차익매도자기CALL금액')
            temp['차익매수자기CALL금액'] = self._get_comm_data(trcode, rqname, i, '차익매수자기CALL금액')
            temp['차익매도자기PUT금액'] = self._get_comm_data(trcode, rqname, i, '차익매도자기PUT금액')
            temp['차익매수자기PUT금액'] = self._get_comm_data(trcode, rqname, i, '차익매수자기PUT금액')
            temp['차익매도금액'] = self._get_comm_data(trcode, rqname, i, '차익매도금액')
            temp['차익매수금액'] = self._get_comm_data(trcode, rqname, i, '차익매수금액')
            temp['차익매도선물금액'] = self._get_comm_data(trcode, rqname, i, '차익매도선물금액')
            temp['차익매수선물금액'] = self._get_comm_data(trcode, rqname, i, '차익매수선물금액')
            temp['차익매도CALL금액'] = self._get_comm_data(trcode, rqname, i, '차익매도CALL금액')
            temp['차익매수CALL금액'] = self._get_comm_data(trcode, rqname, i, '차익매수CALL금액')
            temp['차익매도PUT금액'] = self._get_comm_data(trcode, rqname, i, '차익매도PUT금액')
            temp['차익매수PUT금액'] = self._get_comm_data(trcode, rqname, i, '차익매수PUT금액')
            temp['종목코드2'] = self._get_comm_data(trcode, rqname, i, '종목코드2')
            temp['차익매도위탁금액2'] = self._get_comm_data(trcode, rqname, i, '차익매도위탁금액2')
            temp['차익매수위탁금액2'] = self._get_comm_data(trcode, rqname, i, '차익매수위탁금액2')
            temp['차익매도위탁선물금액2'] = self._get_comm_data(trcode, rqname, i, '차익매도위탁선물금액2')
            temp['차익매수위탁선물금액2'] = self._get_comm_data(trcode, rqname, i, '차익매수위탁선물금액2')
            temp['차익매도위탁CALL금액2'] = self._get_comm_data(trcode, rqname, i, '차익매도위탁CALL금액2')
            temp['차익매수위탁CALL금액2'] = self._get_comm_data(trcode, rqname, i, '차익매수위탁CALL금액2')
            temp['차익매도위탁PUT금액2'] = self._get_comm_data(trcode, rqname, i, '차익매도위탁PUT금액2')
            temp['차익매수위탁PUT금액2'] = self._get_comm_data(trcode, rqname, i, '차익매수위탁PUT금액2')
            temp['차익매도자기금액2'] = self._get_comm_data(trcode, rqname, i, '차익매도자기금액2')
            temp['차익매수자기금액2'] = self._get_comm_data(trcode, rqname, i, '차익매수자기금액2')
            temp['차익매도자기선물금액2'] = self._get_comm_data(trcode, rqname, i, '차익매도자기선물금액2')
            temp['차익매수자기선물금액2'] = self._get_comm_data(trcode, rqname, i, '차익매수자기선물금액2')
            temp['차익매도자기CALL금액2'] = self._get_comm_data(trcode, rqname, i, '차익매도자기CALL금액2')
            temp['차익매수자기CALL금액2'] = self._get_comm_data(trcode, rqname, i, '차익매수자기CALL금액2')
            temp['차익매도자기PUT금액2'] = self._get_comm_data(trcode, rqname, i, '차익매도자기PUT금액2')
            temp['차익매수자기PUT금액2'] = self._get_comm_data(trcode, rqname, i, '차익매수자기PUT금액2')
            temp['차익매도금액2'] = self._get_comm_data(trcode, rqname, i, '차익매도금액2')
            temp['차익매수금액2'] = self._get_comm_data(trcode, rqname, i, '차익매수금액2')
            temp['차익매도선물금액2'] = self._get_comm_data(trcode, rqname, i, '차익매도선물금액2')
            temp['차익매수선물금액2'] = self._get_comm_data(trcode, rqname, i, '차익매수선물금액2')
            temp['차익매도CALL금액2'] = self._get_comm_data(trcode, rqname, i, '차익매도CALL금액2')
            temp['차익매수CALL금액2'] = self._get_comm_data(trcode, rqname, i, '차익매수CALL금액2')
            temp['차익매도PUT금액2'] = self._get_comm_data(trcode, rqname, i, '차익매도PUT금액2')
            temp['차익매수PUT금액2'] = self._get_comm_data(trcode, rqname, i, '차익매수PUT금액2')
            self.opt90010_output['multi'].append(temp)

    def _opt90011(self, rqname, trcode):
        """
    	차익잔고현황요청
    	"""
        self.opt90011_output = {'single': dict(), 'multi': []}

        self.opt90011_output['single']['기준일자'] = self._get_comm_data(trcode, rqname, 0, '기준일자')

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['종목코드1'] = self._get_comm_data(trcode, rqname, i, '종목코드1')
            temp['차익매도위탁금액'] = self._get_comm_data(trcode, rqname, i, '차익매도위탁금액')
            temp['차익매수위탁금액'] = self._get_comm_data(trcode, rqname, i, '차익매수위탁금액')
            temp['차익매도위탁선물금액'] = self._get_comm_data(trcode, rqname, i, '차익매도위탁선물금액')
            temp['차익매수위탁선물금액'] = self._get_comm_data(trcode, rqname, i, '차익매수위탁선물금액')
            temp['차익매도위탁CALL금액'] = self._get_comm_data(trcode, rqname, i, '차익매도위탁CALL금액')
            temp['차익매수위탁CALL금액'] = self._get_comm_data(trcode, rqname, i, '차익매수위탁CALL금액')
            temp['차익매도위탁PUT금액'] = self._get_comm_data(trcode, rqname, i, '차익매도위탁PUT금액')
            temp['차익매수위탁PUT금액'] = self._get_comm_data(trcode, rqname, i, '차익매수위탁PUT금액')
            temp['차익매도자기금액'] = self._get_comm_data(trcode, rqname, i, '차익매도자기금액')
            temp['차익매수자기금액'] = self._get_comm_data(trcode, rqname, i, '차익매수자기금액')
            temp['차익매도자기선물금액'] = self._get_comm_data(trcode, rqname, i, '차익매도자기선물금액')
            temp['차익매수자기선물금액'] = self._get_comm_data(trcode, rqname, i, '차익매수자기선물금액')
            temp['차익매도자기CALL금액'] = self._get_comm_data(trcode, rqname, i, '차익매도자기CALL금액')
            temp['차익매수자기CALL금액'] = self._get_comm_data(trcode, rqname, i, '차익매수자기CALL금액')
            temp['차익매도자기PUT금액'] = self._get_comm_data(trcode, rqname, i, '차익매도자기PUT금액')
            temp['차익매수자기PUT금액'] = self._get_comm_data(trcode, rqname, i, '차익매수자기PUT금액')
            temp['차익매도금액'] = self._get_comm_data(trcode, rqname, i, '차익매도금액')
            temp['차익매수금액'] = self._get_comm_data(trcode, rqname, i, '차익매수금액')
            temp['차익매도선물금액'] = self._get_comm_data(trcode, rqname, i, '차익매도선물금액')
            temp['차익매수선물금액'] = self._get_comm_data(trcode, rqname, i, '차익매수선물금액')
            temp['차익매도CALL금액'] = self._get_comm_data(trcode, rqname, i, '차익매도CALL금액')
            temp['차익매수CALL금액'] = self._get_comm_data(trcode, rqname, i, '차익매수CALL금액')
            temp['차익매도PUT금액'] = self._get_comm_data(trcode, rqname, i, '차익매도PUT금액')
            temp['차익매수PUT금액'] = self._get_comm_data(trcode, rqname, i, '차익매수PUT금액')
            temp['종목코드2'] = self._get_comm_data(trcode, rqname, i, '종목코드2')
            temp['차익매도위탁금액2'] = self._get_comm_data(trcode, rqname, i, '차익매도위탁금액2')
            temp['차익매수위탁금액2'] = self._get_comm_data(trcode, rqname, i, '차익매수위탁금액2')
            temp['차익매도위탁선물금액2'] = self._get_comm_data(trcode, rqname, i, '차익매도위탁선물금액2')
            temp['차익매수위탁선물금액2'] = self._get_comm_data(trcode, rqname, i, '차익매수위탁선물금액2')
            temp['차익매도위탁CALL금액2'] = self._get_comm_data(trcode, rqname, i, '차익매도위탁CALL금액2')
            temp['차익매수위탁CALL금액2'] = self._get_comm_data(trcode, rqname, i, '차익매수위탁CALL금액2')
            temp['차익매도위탁PUT금액2'] = self._get_comm_data(trcode, rqname, i, '차익매도위탁PUT금액2')
            temp['차익매수위탁PUT금액2'] = self._get_comm_data(trcode, rqname, i, '차익매수위탁PUT금액2')
            temp['차익매도자기금액2'] = self._get_comm_data(trcode, rqname, i, '차익매도자기금액2')
            temp['차익매수자기금액2'] = self._get_comm_data(trcode, rqname, i, '차익매수자기금액2')
            temp['차익매도자기선물금액2'] = self._get_comm_data(trcode, rqname, i, '차익매도자기선물금액2')
            temp['차익매수자기선물금액2'] = self._get_comm_data(trcode, rqname, i, '차익매수자기선물금액2')
            temp['차익매도자기CALL금액2'] = self._get_comm_data(trcode, rqname, i, '차익매도자기CALL금액2')
            temp['차익매수자기CALL금액2'] = self._get_comm_data(trcode, rqname, i, '차익매수자기CALL금액2')
            temp['차익매도자기PUT금액2'] = self._get_comm_data(trcode, rqname, i, '차익매도자기PUT금액2')
            temp['차익매수자기PUT금액2'] = self._get_comm_data(trcode, rqname, i, '차익매수자기PUT금액2')
            temp['차익매도금액2'] = self._get_comm_data(trcode, rqname, i, '차익매도금액2')
            temp['차익매수금액2'] = self._get_comm_data(trcode, rqname, i, '차익매수금액2')
            temp['차익매도선물금액2'] = self._get_comm_data(trcode, rqname, i, '차익매도선물금액2')
            temp['차익매수선물금액2'] = self._get_comm_data(trcode, rqname, i, '차익매수선물금액2')
            temp['차익매도CALL금액2'] = self._get_comm_data(trcode, rqname, i, '차익매도CALL금액2')
            temp['차익매수CALL금액2'] = self._get_comm_data(trcode, rqname, i, '차익매수CALL금액2')
            temp['차익매도PUT금액2'] = self._get_comm_data(trcode, rqname, i, '차익매도PUT금액2')
            temp['차익매수PUT금액2'] = self._get_comm_data(trcode, rqname, i, '차익매수PUT금액2')
            self.opt90011_output['multi'].append(temp)

    def _opt90012(self, rqname, trcode):
        """
    	대차거래내역요청
    	"""
        self.opt90012_output = {'multi': []}

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['종목명'] = self._get_comm_data(trcode, rqname, i, '종목명')
            temp['종목코드'] = self._get_comm_data(trcode, rqname, i, '종목코드')
            temp['대차거래체결주수'] = self._get_comm_data(trcode, rqname, i, '대차거래체결주수')
            temp['대차거래상환주수'] = self._get_comm_data(trcode, rqname, i, '대차거래상환주수')
            temp['잔고주수'] = self._get_comm_data(trcode, rqname, i, '잔고주수')
            temp['잔고금액'] = self._get_comm_data(trcode, rqname, i, '잔고금액')
            self.opt90012_output['multi'].append(temp)

    def _opt90013(self, rqname, trcode):
        """
    	종목일별프로그램매매추이요청
    	"""
        self.opt90013_output = {'multi': []}

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['일자'] = self._get_comm_data(trcode, rqname, i, '일자')
            temp['현재가'] = self._get_comm_data(trcode, rqname, i, '현재가')
            temp['대비기호'] = self._get_comm_data(trcode, rqname, i, '대비기호')
            temp['전일대비'] = self._get_comm_data(trcode, rqname, i, '전일대비')
            temp['등락율'] = self._get_comm_data(trcode, rqname, i, '등락율')
            temp['거래량'] = self._get_comm_data(trcode, rqname, i, '거래량')
            temp['프로그램매도금액'] = self._get_comm_data(trcode, rqname, i, '프로그램매도금액')
            temp['프로그램매수금액'] = self._get_comm_data(trcode, rqname, i, '프로그램매수금액')
            temp['프로그램순매수금액'] = self._get_comm_data(trcode, rqname, i, '프로그램순매수금액')
            temp['프로그램순매수금액증감'] = self._get_comm_data(trcode, rqname, i, '프로그램순매수금액증감')
            temp['프로그램매도수량'] = self._get_comm_data(trcode, rqname, i, '프로그램매도수량')
            temp['프로그램매수수량'] = self._get_comm_data(trcode, rqname, i, '프로그램매수수량')
            temp['프로그램순매수수량'] = self._get_comm_data(trcode, rqname, i, '프로그램순매수수량')
            temp['프로그램순매수수량증감'] = self._get_comm_data(trcode, rqname, i, '프로그램순매수수량증감')
            temp['기준가시간'] = self._get_comm_data(trcode, rqname, i, '기준가시간')
            temp['대차거래상환주수합'] = self._get_comm_data(trcode, rqname, i, '대차거래상환주수합')
            temp['잔고수주합'] = self._get_comm_data(trcode, rqname, i, '잔고수주합')
            self.opt90013_output['multi'].append(temp)

    def _opt99999(self, rqname, trcode):
        """
    	대차거래상위10종목요청
    	"""
        self.opt99999_output = {'multi': []}

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['일자1'] = self._get_comm_data(trcode, rqname, i, '일자1')
            temp['일자2'] = self._get_comm_data(trcode, rqname, i, '일자2')
            temp['일자3'] = self._get_comm_data(trcode, rqname, i, '일자3')
            temp['일자4'] = self._get_comm_data(trcode, rqname, i, '일자4')
            temp['일자5'] = self._get_comm_data(trcode, rqname, i, '일자5')
            temp['일자6'] = self._get_comm_data(trcode, rqname, i, '일자6')
            temp['일자7'] = self._get_comm_data(trcode, rqname, i, '일자7')
            temp['일자8'] = self._get_comm_data(trcode, rqname, i, '일자8')
            self.opt99999_output['multi'].append(temp)

    def _optfofid(self, rqname, trcode):
        """
    	선물전체시세요청
    	"""
        self.optfofid_output = {'single': dict()}

        self.optfofid_output['single']['종목코드'] = self._get_comm_data(trcode, rqname, 0, '종목코드')
        self.optfofid_output['single']['종목명'] = self._get_comm_data(trcode, rqname, 0, '종목명')
        self.optfofid_output['single']['현재가'] = self._get_comm_data(trcode, rqname, 0, '현재가')
        self.optfofid_output['single']['전일대비'] = self._get_comm_data(trcode, rqname, 0, '전일대비')
        self.optfofid_output['single']['매도호가2'] = self._get_comm_data(trcode, rqname, 0, '매도호가2')
        self.optfofid_output['single']['매도호가1'] = self._get_comm_data(trcode, rqname, 0, '매도호가1')
        self.optfofid_output['single']['매수호가1'] = self._get_comm_data(trcode, rqname, 0, '매수호가1')
        self.optfofid_output['single']['매수호가2'] = self._get_comm_data(trcode, rqname, 0, '매수호가2')
        self.optfofid_output['single']['거래량'] = self._get_comm_data(trcode, rqname, 0, '거래량')
        self.optfofid_output['single']['거래량전일대비'] = self._get_comm_data(trcode, rqname, 0, '거래량전일대비')
        self.optfofid_output['single']['누적거래대금'] = self._get_comm_data(trcode, rqname, 0, '누적거래대금')
        self.optfofid_output['single']['미결제약정'] = self._get_comm_data(trcode, rqname, 0, '미결제약정')
        self.optfofid_output['single']['미결제약정전일대비'] = self._get_comm_data(trcode, rqname, 0, '미결제약정전일대비')
        self.optfofid_output['single']['시가'] = self._get_comm_data(trcode, rqname, 0, '시가')
        self.optfofid_output['single']['고가'] = self._get_comm_data(trcode, rqname, 0, '고가')
        self.optfofid_output['single']['저가'] = self._get_comm_data(trcode, rqname, 0, '저가')
        self.optfofid_output['single']['이론가'] = self._get_comm_data(trcode, rqname, 0, '이론가')
        self.optfofid_output['single']['괴리율'] = self._get_comm_data(trcode, rqname, 0, '괴리율')
        self.optfofid_output['single']['시장베이시스'] = self._get_comm_data(trcode, rqname, 0, '시장베이시스')
        self.optfofid_output['single']['이론베이시스'] = self._get_comm_data(trcode, rqname, 0, '이론베이시스')
        self.optfofid_output['single']['행사가'] = self._get_comm_data(trcode, rqname, 0, '행사가')
        self.optfofid_output['single']['지수환산'] = self._get_comm_data(trcode, rqname, 0, '지수환산')
        self.optfofid_output['single']['대비기호'] = self._get_comm_data(trcode, rqname, 0, '대비기호')
        self.optfofid_output['single']['등락율'] = self._get_comm_data(trcode, rqname, 0, '등락율')
        self.optfofid_output['single']['매수수량'] = self._get_comm_data(trcode, rqname, 0, '매수수량')
        self.optfofid_output['single']['매수호가총건수'] = self._get_comm_data(trcode, rqname, 0, '매수호가총건수')
        self.optfofid_output['single']['매도호가총건수'] = self._get_comm_data(trcode, rqname, 0, '매도호가총건수')
        self.optfofid_output['single']['기준가'] = self._get_comm_data(trcode, rqname, 0, '기준가')
        self.optfofid_output['single']['잔존일수'] = self._get_comm_data(trcode, rqname, 0, '잔존일수')
        self.optfofid_output['single']['영업일기준잔존일'] = self._get_comm_data(trcode, rqname, 0, '영업일기준잔존일')

    def _optkwfid(self, rqname, trcode):
        """
    	관심종목정보요청
    	"""
        self.optkwfid_output = {'multi': []}

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['종목코드'] = self._get_comm_data(trcode, rqname, i, '종목코드')
            temp['종목명'] = self._get_comm_data(trcode, rqname, i, '종목명')
            temp['현재가'] = self._get_comm_data(trcode, rqname, i, '현재가')
            temp['기준가'] = self._get_comm_data(trcode, rqname, i, '기준가')
            temp['전일대비'] = self._get_comm_data(trcode, rqname, i, '전일대비')
            temp['전일대비기호'] = self._get_comm_data(trcode, rqname, i, '전일대비기호')
            temp['등락율'] = self._get_comm_data(trcode, rqname, i, '등락율')
            temp['거래량'] = self._get_comm_data(trcode, rqname, i, '거래량')
            temp['거래대금'] = self._get_comm_data(trcode, rqname, i, '거래대금')
            temp['체결량'] = self._get_comm_data(trcode, rqname, i, '체결량')
            temp['체결강도'] = self._get_comm_data(trcode, rqname, i, '체결강도')
            temp['전일거래량대비'] = self._get_comm_data(trcode, rqname, i, '전일거래량대비')
            temp['매도호가'] = self._get_comm_data(trcode, rqname, i, '매도호가')
            temp['매수호가'] = self._get_comm_data(trcode, rqname, i, '매수호가')
            temp['매도1차호가'] = self._get_comm_data(trcode, rqname, i, '매도1차호가')
            temp['매도2차호가'] = self._get_comm_data(trcode, rqname, i, '매도2차호가')
            temp['매도3차호가'] = self._get_comm_data(trcode, rqname, i, '매도3차호가')
            temp['매도4차호가'] = self._get_comm_data(trcode, rqname, i, '매도4차호가')
            temp['매도5차호가'] = self._get_comm_data(trcode, rqname, i, '매도5차호가')
            temp['매수1차호가'] = self._get_comm_data(trcode, rqname, i, '매수1차호가')
            temp['매수2차호가'] = self._get_comm_data(trcode, rqname, i, '매수2차호가')
            temp['매수3차호가'] = self._get_comm_data(trcode, rqname, i, '매수3차호가')
            temp['매수4차호가'] = self._get_comm_data(trcode, rqname, i, '매수4차호가')
            temp['매수5차호가'] = self._get_comm_data(trcode, rqname, i, '매수5차호가')
            temp['상한가'] = self._get_comm_data(trcode, rqname, i, '상한가')
            temp['하한가'] = self._get_comm_data(trcode, rqname, i, '하한가')
            temp['시가'] = self._get_comm_data(trcode, rqname, i, '시가')
            temp['고가'] = self._get_comm_data(trcode, rqname, i, '고가')
            temp['저가'] = self._get_comm_data(trcode, rqname, i, '저가')
            temp['종가'] = self._get_comm_data(trcode, rqname, i, '종가')
            temp['체결시간'] = self._get_comm_data(trcode, rqname, i, '체결시간')
            temp['예상체결가'] = self._get_comm_data(trcode, rqname, i, '예상체결가')
            temp['예상체결량'] = self._get_comm_data(trcode, rqname, i, '예상체결량')
            temp['자본금'] = self._get_comm_data(trcode, rqname, i, '자본금')
            temp['액면가'] = self._get_comm_data(trcode, rqname, i, '액면가')
            temp['시가총액'] = self._get_comm_data(trcode, rqname, i, '시가총액')
            temp['주식수'] = self._get_comm_data(trcode, rqname, i, '주식수')
            temp['호가시간'] = self._get_comm_data(trcode, rqname, i, '호가시간')
            temp['일자'] = self._get_comm_data(trcode, rqname, i, '일자')
            temp['우선매도잔량'] = self._get_comm_data(trcode, rqname, i, '우선매도잔량')
            temp['우선매수잔량'] = self._get_comm_data(trcode, rqname, i, '우선매수잔량')
            temp['우선매도건수'] = self._get_comm_data(trcode, rqname, i, '우선매도건수')
            temp['우선매수건수'] = self._get_comm_data(trcode, rqname, i, '우선매수건수')
            temp['총매도잔량'] = self._get_comm_data(trcode, rqname, i, '총매도잔량')
            temp['총매수잔량'] = self._get_comm_data(trcode, rqname, i, '총매수잔량')
            temp['총매도건수'] = self._get_comm_data(trcode, rqname, i, '총매도건수')
            temp['총매수건수'] = self._get_comm_data(trcode, rqname, i, '총매수건수')
            temp['패리티'] = self._get_comm_data(trcode, rqname, i, '패리티')
            temp['기어링'] = self._get_comm_data(trcode, rqname, i, '기어링')
            temp['손익분기'] = self._get_comm_data(trcode, rqname, i, '손익분기')
            temp['자본지지'] = self._get_comm_data(trcode, rqname, i, '자본지지')
            temp['ELW행사가'] = self._get_comm_data(trcode, rqname, i, 'ELW행사가')
            temp['전환비율'] = self._get_comm_data(trcode, rqname, i, '전환비율')
            temp['ELW만기일'] = self._get_comm_data(trcode, rqname, i, 'ELW만기일')
            temp['미결제약정'] = self._get_comm_data(trcode, rqname, i, '미결제약정')
            temp['미결제전일대비'] = self._get_comm_data(trcode, rqname, i, '미결제전일대비')
            temp['이론가'] = self._get_comm_data(trcode, rqname, i, '이론가')
            temp['내재변동성'] = self._get_comm_data(trcode, rqname, i, '내재변동성')
            temp['델타'] = self._get_comm_data(trcode, rqname, i, '델타')
            temp['감마'] = self._get_comm_data(trcode, rqname, i, '감마')
            temp['쎄타'] = self._get_comm_data(trcode, rqname, i, '쎄타')
            temp['베가'] = self._get_comm_data(trcode, rqname, i, '베가')
            temp['로'] = self._get_comm_data(trcode, rqname, i, '로')
            self.optkwfid_output['multi'].append(temp)

    def _optkwinv(self, rqname, trcode):
        """
    	관심종목투자자정보요청
    	"""
        self.optkwinv_output = {'multi': []}

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['종목명'] = self._get_comm_data(trcode, rqname, i, '종목명')
            temp['매도수량'] = self._get_comm_data(trcode, rqname, i, '매도수량')
            temp['매수수량'] = self._get_comm_data(trcode, rqname, i, '매수수량')
            temp['순매수수량'] = self._get_comm_data(trcode, rqname, i, '순매수수량')
            temp['매도금액'] = self._get_comm_data(trcode, rqname, i, '매도금액')
            temp['매수금액'] = self._get_comm_data(trcode, rqname, i, '매수금액')
            temp['순매수금액'] = self._get_comm_data(trcode, rqname, i, '순매수금액')
            self.optkwinv_output['multi'].append(temp)

    def _optkwpro(self, rqname, trcode):
        """
    	관심종목프로그램정보요청
    	"""
        self.optkwpro_output = {'multi': []}

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['차익매도량'] = self._get_comm_data(trcode, rqname, i, '차익매도량')
            temp['차익매도대금'] = self._get_comm_data(trcode, rqname, i, '차익매도대금')
            temp['차익매도비율'] = self._get_comm_data(trcode, rqname, i, '차익매도비율')
            temp['차익매수량'] = self._get_comm_data(trcode, rqname, i, '차익매수량')
            temp['차익매수대금'] = self._get_comm_data(trcode, rqname, i, '차익매수대금')
            temp['차익매수비율'] = self._get_comm_data(trcode, rqname, i, '차익매수비율')
            temp['차익순매수금액'] = self._get_comm_data(trcode, rqname, i, '차익순매수금액')
            temp['비차익매도량'] = self._get_comm_data(trcode, rqname, i, '비차익매도량')
            temp['비차익매도대금'] = self._get_comm_data(trcode, rqname, i, '비차익매도대금')
            temp['비차익매도비율'] = self._get_comm_data(trcode, rqname, i, '비차익매도비율')
            temp['비차익매수량'] = self._get_comm_data(trcode, rqname, i, '비차익매수량')
            temp['비차익매수대금'] = self._get_comm_data(trcode, rqname, i, '비차익매수대금')
            temp['비차익매수비율'] = self._get_comm_data(trcode, rqname, i, '비차익매수비율')
            temp['비차익순매수금액'] = self._get_comm_data(trcode, rqname, i, '비차익순매수금액')
            temp['합계매도량'] = self._get_comm_data(trcode, rqname, i, '합계매도량')
            temp['합계매도대금'] = self._get_comm_data(trcode, rqname, i, '합계매도대금')
            temp['합계매수량'] = self._get_comm_data(trcode, rqname, i, '합계매수량')
            temp['합계매수대금'] = self._get_comm_data(trcode, rqname, i, '합계매수대금')
            temp['합계순매수'] = self._get_comm_data(trcode, rqname, i, '합계순매수')
            self.optkwpro_output['multi'].append(temp)

    def _opw00001(self, rqname, trcode):
        """
    	예수금상세현황요청
    	"""
        self.opw00001_output = {'single': dict(), 'multi': []}

        self.opw00001_output['single']['예수금'] = self._get_comm_data(trcode, rqname, 0, '예수금')
        self.opw00001_output['single']['주식증거금현금'] = self._get_comm_data(trcode, rqname, 0, '주식증거금현금')
        self.opw00001_output['single']['수익증권증거금현금'] = self._get_comm_data(trcode, rqname, 0, '수익증권증거금현금')
        self.opw00001_output['single']['익일수익증권매도정산대금'] = self._get_comm_data(trcode, rqname, 0, '익일수익증권매도정산대금')
        self.opw00001_output['single']['해외주식원화대용설정금'] = self._get_comm_data(trcode, rqname, 0, '해외주식원화대용설정금')
        self.opw00001_output['single']['신용보증금현금'] = self._get_comm_data(trcode, rqname, 0, '신용보증금현금')
        self.opw00001_output['single']['신용담보금현금'] = self._get_comm_data(trcode, rqname, 0, '신용담보금현금')
        self.opw00001_output['single']['추가담보금현금'] = self._get_comm_data(trcode, rqname, 0, '추가담보금현금')
        self.opw00001_output['single']['기타증거금'] = self._get_comm_data(trcode, rqname, 0, '기타증거금')
        self.opw00001_output['single']['미수확보금'] = self._get_comm_data(trcode, rqname, 0, '미수확보금')
        self.opw00001_output['single']['공매도대금'] = self._get_comm_data(trcode, rqname, 0, '공매도대금')
        self.opw00001_output['single']['신용설정평가금'] = self._get_comm_data(trcode, rqname, 0, '신용설정평가금')
        self.opw00001_output['single']['수표입금액'] = self._get_comm_data(trcode, rqname, 0, '수표입금액')
        self.opw00001_output['single']['기타수표입금액'] = self._get_comm_data(trcode, rqname, 0, '기타수표입금액')
        self.opw00001_output['single']['신용담보재사용'] = self._get_comm_data(trcode, rqname, 0, '신용담보재사용')
        self.opw00001_output['single']['코넥스기본예탁금'] = self._get_comm_data(trcode, rqname, 0, '코넥스기본예탁금')
        self.opw00001_output['single']['ELW예탁평가금'] = self._get_comm_data(trcode, rqname, 0, 'ELW예탁평가금')
        self.opw00001_output['single']['신용대주권리예정금액'] = self._get_comm_data(trcode, rqname, 0, '신용대주권리예정금액')
        self.opw00001_output['single']['생계형가입금액'] = self._get_comm_data(trcode, rqname, 0, '생계형가입금액')
        self.opw00001_output['single']['생계형입금가능금액'] = self._get_comm_data(trcode, rqname, 0, '생계형입금가능금액')
        self.opw00001_output['single']['대용금평가금액(합계)'] = self._get_comm_data(trcode, rqname, 0, '대용금평가금액(합계)')
        self.opw00001_output['single']['잔고대용평가금액'] = self._get_comm_data(trcode, rqname, 0, '잔고대용평가금액')
        self.opw00001_output['single']['위탁대용잔고평가금액'] = self._get_comm_data(trcode, rqname, 0, '위탁대용잔고평가금액')
        self.opw00001_output['single']['수익증권대용평가금액'] = self._get_comm_data(trcode, rqname, 0, '수익증권대용평가금액')
        self.opw00001_output['single']['위탁증거금대용'] = self._get_comm_data(trcode, rqname, 0, '위탁증거금대용')
        self.opw00001_output['single']['신용보증금대용'] = self._get_comm_data(trcode, rqname, 0, '신용보증금대용')
        self.opw00001_output['single']['신용담보금대용'] = self._get_comm_data(trcode, rqname, 0, '신용담보금대용')
        self.opw00001_output['single']['추가담보금대용'] = self._get_comm_data(trcode, rqname, 0, '추가담보금대용')
        self.opw00001_output['single']['권리대용금'] = self._get_comm_data(trcode, rqname, 0, '권리대용금')
        self.opw00001_output['single']['출금가능금액'] = self._get_comm_data(trcode, rqname, 0, '출금가능금액')
        self.opw00001_output['single']['랩출금가능금액'] = self._get_comm_data(trcode, rqname, 0, '랩출금가능금액')
        self.opw00001_output['single']['주문가능금액'] = self._get_comm_data(trcode, rqname, 0, '주문가능금액')
        self.opw00001_output['single']['수익증권매수가능금액'] = self._get_comm_data(trcode, rqname, 0, '수익증권매수가능금액')
        self.opw00001_output['single']['20%종목주문가능금액'] = self._get_comm_data(trcode, rqname, 0, '20%종목주문가능금액')
        self.opw00001_output['single']['30%종목주문가능금액'] = self._get_comm_data(trcode, rqname, 0, '30%종목주문가능금액')
        self.opw00001_output['single']['40%종목주문가능금액'] = self._get_comm_data(trcode, rqname, 0, '40%종목주문가능금액')
        self.opw00001_output['single']['100%종목주문가능금액'] = self._get_comm_data(trcode, rqname, 0, '100%종목주문가능금액')
        self.opw00001_output['single']['현금미수금'] = self._get_comm_data(trcode, rqname, 0, '현금미수금')
        self.opw00001_output['single']['현금미수연체료'] = self._get_comm_data(trcode, rqname, 0, '현금미수연체료')
        self.opw00001_output['single']['현금미수금합계'] = self._get_comm_data(trcode, rqname, 0, '현금미수금합계')
        self.opw00001_output['single']['신용이자미납'] = self._get_comm_data(trcode, rqname, 0, '신용이자미납')
        self.opw00001_output['single']['신용이자미납연체료'] = self._get_comm_data(trcode, rqname, 0, '신용이자미납연체료')
        self.opw00001_output['single']['신용이자미납합계'] = self._get_comm_data(trcode, rqname, 0, '신용이자미납합계')
        self.opw00001_output['single']['기타대여금'] = self._get_comm_data(trcode, rqname, 0, '기타대여금')
        self.opw00001_output['single']['기타대여금연체료'] = self._get_comm_data(trcode, rqname, 0, '기타대여금연체료')
        self.opw00001_output['single']['기타대여금합계'] = self._get_comm_data(trcode, rqname, 0, '기타대여금합계')
        self.opw00001_output['single']['미상환융자금'] = self._get_comm_data(trcode, rqname, 0, '미상환융자금')
        self.opw00001_output['single']['융자금합계'] = self._get_comm_data(trcode, rqname, 0, '융자금합계')
        self.opw00001_output['single']['대주금합계'] = self._get_comm_data(trcode, rqname, 0, '대주금합계')
        self.opw00001_output['single']['신용담보비율'] = self._get_comm_data(trcode, rqname, 0, '신용담보비율')
        self.opw00001_output['single']['중도이용료'] = self._get_comm_data(trcode, rqname, 0, '중도이용료')
        self.opw00001_output['single']['최소주문가능금액'] = self._get_comm_data(trcode, rqname, 0, '최소주문가능금액')
        self.opw00001_output['single']['대출총평가금액'] = self._get_comm_data(trcode, rqname, 0, '대출총평가금액')
        self.opw00001_output['single']['예탁담보대출잔고'] = self._get_comm_data(trcode, rqname, 0, '예탁담보대출잔고')
        self.opw00001_output['single']['매도담보대출잔고'] = self._get_comm_data(trcode, rqname, 0, '매도담보대출잔고')
        self.opw00001_output['single']['d+1추정예수금'] = self._get_comm_data(trcode, rqname, 0, 'd+1추정예수금')
        self.opw00001_output['single']['d+1매도매수정산금'] = self._get_comm_data(trcode, rqname, 0, 'd+1매도매수정산금')
        self.opw00001_output['single']['d+1매수정산금'] = self._get_comm_data(trcode, rqname, 0, 'd+1매수정산금')
        self.opw00001_output['single']['d+1미수변제소요금'] = self._get_comm_data(trcode, rqname, 0, 'd+1미수변제소요금')
        self.opw00001_output['single']['d+1매도정산금'] = self._get_comm_data(trcode, rqname, 0, 'd+1매도정산금')
        self.opw00001_output['single']['d+1출금가능금액'] = self._get_comm_data(trcode, rqname, 0, 'd+1출금가능금액')
        self.opw00001_output['single']['d+2추정예수금'] = self._get_comm_data(trcode, rqname, 0, 'd+2추정예수금')
        self.opw00001_output['single']['d+2매도매수정산금'] = self._get_comm_data(trcode, rqname, 0, 'd+2매도매수정산금')
        self.opw00001_output['single']['d+2매수정산금'] = self._get_comm_data(trcode, rqname, 0, 'd+2매수정산금')
        self.opw00001_output['single']['d+2미수변제소요금'] = self._get_comm_data(trcode, rqname, 0, 'd+2미수변제소요금')
        self.opw00001_output['single']['d+2매도정산금'] = self._get_comm_data(trcode, rqname, 0, 'd+2매도정산금')
        self.opw00001_output['single']['d+2출금가능금액'] = self._get_comm_data(trcode, rqname, 0, 'd+2출금가능금액')
        self.opw00001_output['single']['출력건수'] = self._get_comm_data(trcode, rqname, 0, '출력건수')

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['통화코드'] = self._get_comm_data(trcode, rqname, i, '통화코드')
            temp['외화예수금'] = self._get_comm_data(trcode, rqname, i, '외화예수금')
            temp['원화대용평가금'] = self._get_comm_data(trcode, rqname, i, '원화대용평가금')
            temp['해외주식증거금'] = self._get_comm_data(trcode, rqname, i, '해외주식증거금')
            temp['출금가능금액(예수금)'] = self._get_comm_data(trcode, rqname, i, '출금가능금액(예수금)')
            temp['주문가능금액(예수금)'] = self._get_comm_data(trcode, rqname, i, '주문가능금액(예수금)')
            temp['외화미수(합계)'] = self._get_comm_data(trcode, rqname, i, '외화미수(합계)')
            temp['외화현금미수금'] = self._get_comm_data(trcode, rqname, i, '외화현금미수금')
            temp['연체료'] = self._get_comm_data(trcode, rqname, i, '연체료')
            temp['d+1외화예수금'] = self._get_comm_data(trcode, rqname, i, 'd+1외화예수금')
            temp['d+2외화예수금'] = self._get_comm_data(trcode, rqname, i, 'd+2외화예수금')
            temp['d+3외화예수금'] = self._get_comm_data(trcode, rqname, i, 'd+3외화예수금')
            temp['d+4외화예수금'] = self._get_comm_data(trcode, rqname, i, 'd+4외화예수금')
            self.opw00001_output['multi'].append(temp)

    def _opw00002(self, rqname, trcode):
        """
    	일별추정예탁자산현황요청
    	"""
        self.opw00002_output = {'single': dict(), 'multi': []}

        self.opw00002_output['single']['출력건수'] = self._get_comm_data(trcode, rqname, 0, '출력건수')

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['일자'] = self._get_comm_data(trcode, rqname, i, '일자')
            temp['예수금'] = self._get_comm_data(trcode, rqname, i, '예수금')
            temp['담보대출금'] = self._get_comm_data(trcode, rqname, i, '담보대출금')
            temp['신용융자금'] = self._get_comm_data(trcode, rqname, i, '신용융자금')
            temp['대주담보금'] = self._get_comm_data(trcode, rqname, i, '대주담보금')
            temp['대용금'] = self._get_comm_data(trcode, rqname, i, '대용금')
            temp['추정예탁자산'] = self._get_comm_data(trcode, rqname, i, '추정예탁자산')
            temp['추정예탁자산수익증권제외'] = self._get_comm_data(trcode, rqname, i, '추정예탁자산수익증권제외')
            self.opw00002_output['multi'].append(temp)

    def _opw00003(self, rqname, trcode):
        """
    	추정자산조회요청
    	"""
        self.opw00003_output = {'single': dict()}

        self.opw00003_output['single']['추정예탁자산'] = self._get_comm_data(trcode, rqname, 0, '추정예탁자산')

    def _opw00004(self, rqname, trcode):
        """
    	계좌평가현황요청
    	"""
        self.opw00004_output = {'single': dict(), 'multi': []}

        self.opw00004_output['single']['계좌명'] = self._get_comm_data(trcode, rqname, 0, '계좌명')
        self.opw00004_output['single']['지점명'] = self._get_comm_data(trcode, rqname, 0, '지점명')
        self.opw00004_output['single']['예수금'] = self._get_comm_data(trcode, rqname, 0, '예수금')
        self.opw00004_output['single']['D+2추정예수금'] = self._get_comm_data(trcode, rqname, 0, 'D+2추정예수금')
        self.opw00004_output['single']['유가잔고평가액'] = self._get_comm_data(trcode, rqname, 0, '유가잔고평가액')
        self.opw00004_output['single']['예탁자산평가액'] = self._get_comm_data(trcode, rqname, 0, '예탁자산평가액')
        self.opw00004_output['single']['총매입금액'] = self._get_comm_data(trcode, rqname, 0, '총매입금액')
        self.opw00004_output['single']['추정예탁자산'] = self._get_comm_data(trcode, rqname, 0, '추정예탁자산')
        self.opw00004_output['single']['매도담보대출금'] = self._get_comm_data(trcode, rqname, 0, '매도담보대출금')
        self.opw00004_output['single']['당일투자원금'] = self._get_comm_data(trcode, rqname, 0, '당일투자원금')
        self.opw00004_output['single']['당월투자원금'] = self._get_comm_data(trcode, rqname, 0, '당월투자원금')
        self.opw00004_output['single']['누적투자원금'] = self._get_comm_data(trcode, rqname, 0, '누적투자원금')
        self.opw00004_output['single']['당일투자손익'] = self._get_comm_data(trcode, rqname, 0, '당일투자손익')
        self.opw00004_output['single']['당월투자손익'] = self._get_comm_data(trcode, rqname, 0, '당월투자손익')
        self.opw00004_output['single']['누적투자손익'] = self._get_comm_data(trcode, rqname, 0, '누적투자손익')
        self.opw00004_output['single']['당일손익율'] = self._get_comm_data(trcode, rqname, 0, '당일손익율')
        self.opw00004_output['single']['당월손익율'] = self._get_comm_data(trcode, rqname, 0, '당월손익율')
        self.opw00004_output['single']['누적손익율'] = self._get_comm_data(trcode, rqname, 0, '누적손익율')
        self.opw00004_output['single']['출력건수'] = self._get_comm_data(trcode, rqname, 0, '출력건수')

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['종목코드'] = self._get_comm_data(trcode, rqname, i, '종목코드')
            temp['종목명'] = self._get_comm_data(trcode, rqname, i, '종목명')
            temp['보유수량'] = self._get_comm_data(trcode, rqname, i, '보유수량')
            temp['평균단가'] = self._get_comm_data(trcode, rqname, i, '평균단가')
            temp['현재가'] = self._get_comm_data(trcode, rqname, i, '현재가')
            temp['평가금액'] = self._get_comm_data(trcode, rqname, i, '평가금액')
            temp['손익금액'] = self._get_comm_data(trcode, rqname, i, '손익금액')
            temp['손익율'] = self._get_comm_data(trcode, rqname, i, '손익율')
            temp['대출일'] = self._get_comm_data(trcode, rqname, i, '대출일')
            temp['매입금액'] = self._get_comm_data(trcode, rqname, i, '매입금액')
            temp['결제잔고'] = self._get_comm_data(trcode, rqname, i, '결제잔고')
            temp['전일매수수량'] = self._get_comm_data(trcode, rqname, i, '전일매수수량')
            temp['전일매도수량'] = self._get_comm_data(trcode, rqname, i, '전일매도수량')
            temp['금일매수수량'] = self._get_comm_data(trcode, rqname, i, '금일매수수량')
            temp['금일매도수량'] = self._get_comm_data(trcode, rqname, i, '금일매도수량')
            self.opw00004_output['multi'].append(temp)

    def _opw00005(self, rqname, trcode):
        """
    	체결잔고요청
    	"""
        self.opw00005_output = {'single': dict(), 'multi': []}

        self.opw00005_output['single']['예수금'] = self._get_comm_data(trcode, rqname, 0, '예수금')
        self.opw00005_output['single']['예수금D+1'] = self._get_comm_data(trcode, rqname, 0, '예수금D+1')
        self.opw00005_output['single']['예수금D+2'] = self._get_comm_data(trcode, rqname, 0, '예수금D+2')
        self.opw00005_output['single']['출금가능금액'] = self._get_comm_data(trcode, rqname, 0, '출금가능금액')
        self.opw00005_output['single']['미수확보금'] = self._get_comm_data(trcode, rqname, 0, '미수확보금')
        self.opw00005_output['single']['대용금'] = self._get_comm_data(trcode, rqname, 0, '대용금')
        self.opw00005_output['single']['권리대용금'] = self._get_comm_data(trcode, rqname, 0, '권리대용금')
        self.opw00005_output['single']['주문가능현금'] = self._get_comm_data(trcode, rqname, 0, '주문가능현금')
        self.opw00005_output['single']['현금미수금'] = self._get_comm_data(trcode, rqname, 0, '현금미수금')
        self.opw00005_output['single']['신용이자미납금'] = self._get_comm_data(trcode, rqname, 0, '신용이자미납금')
        self.opw00005_output['single']['기타대여금'] = self._get_comm_data(trcode, rqname, 0, '기타대여금')
        self.opw00005_output['single']['미상환융자금'] = self._get_comm_data(trcode, rqname, 0, '미상환융자금')
        self.opw00005_output['single']['증거금현금'] = self._get_comm_data(trcode, rqname, 0, '증거금현금')
        self.opw00005_output['single']['증거금대용'] = self._get_comm_data(trcode, rqname, 0, '증거금대용')
        self.opw00005_output['single']['주식매수총액'] = self._get_comm_data(trcode, rqname, 0, '주식매수총액')
        self.opw00005_output['single']['평가금액합계'] = self._get_comm_data(trcode, rqname, 0, '평가금액합계')
        self.opw00005_output['single']['총손익합계'] = self._get_comm_data(trcode, rqname, 0, '총손익합계')
        self.opw00005_output['single']['총손익률'] = self._get_comm_data(trcode, rqname, 0, '총손익률')
        self.opw00005_output['single']['총재매수가능금액'] = self._get_comm_data(trcode, rqname, 0, '총재매수가능금액')
        self.opw00005_output['single']['20주문가능금액'] = self._get_comm_data(trcode, rqname, 0, '20주문가능금액')
        self.opw00005_output['single']['30주문가능금액'] = self._get_comm_data(trcode, rqname, 0, '30주문가능금액')
        self.opw00005_output['single']['40주문가능금액'] = self._get_comm_data(trcode, rqname, 0, '40주문가능금액')
        self.opw00005_output['single']['50주문가능금액'] = self._get_comm_data(trcode, rqname, 0, '50주문가능금액')
        self.opw00005_output['single']['60주문가능금액'] = self._get_comm_data(trcode, rqname, 0, '60주문가능금액')
        self.opw00005_output['single']['100주문가능금액'] = self._get_comm_data(trcode, rqname, 0, '100주문가능금액')
        self.opw00005_output['single']['신용융자합계'] = self._get_comm_data(trcode, rqname, 0, '신용융자합계')
        self.opw00005_output['single']['신용융자대주합계'] = self._get_comm_data(trcode, rqname, 0, '신용융자대주합계')
        self.opw00005_output['single']['신용담보비율'] = self._get_comm_data(trcode, rqname, 0, '신용담보비율')
        self.opw00005_output['single']['예탁담보대출금액'] = self._get_comm_data(trcode, rqname, 0, '예탁담보대출금액')
        self.opw00005_output['single']['매도담보대출금액'] = self._get_comm_data(trcode, rqname, 0, '매도담보대출금액')
        self.opw00005_output['single']['조회건수'] = self._get_comm_data(trcode, rqname, 0, '조회건수')

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['신용구분'] = self._get_comm_data(trcode, rqname, i, '신용구분')
            temp['대출일'] = self._get_comm_data(trcode, rqname, i, '대출일')
            temp['만기일'] = self._get_comm_data(trcode, rqname, i, '만기일')
            temp['종목번호'] = self._get_comm_data(trcode, rqname, i, '종목번호')
            temp['종목명'] = self._get_comm_data(trcode, rqname, i, '종목명')
            temp['결제잔고'] = self._get_comm_data(trcode, rqname, i, '결제잔고')
            temp['현재잔고'] = self._get_comm_data(trcode, rqname, i, '현재잔고')
            temp['현재가'] = self._get_comm_data(trcode, rqname, i, '현재가')
            temp['매입단가'] = self._get_comm_data(trcode, rqname, i, '매입단가')
            temp['매입금액'] = self._get_comm_data(trcode, rqname, i, '매입금액')
            temp['평가금액'] = self._get_comm_data(trcode, rqname, i, '평가금액')
            temp['평가손익'] = self._get_comm_data(trcode, rqname, i, '평가손익')
            temp['손익률'] = self._get_comm_data(trcode, rqname, i, '손익률')
            self.opw00005_output['multi'].append(temp)

    def _opw00006(self, rqname, trcode):
        """
    	관리자별주문체결내역요청
    	"""
        self.opw00006_output = {'single': dict(), 'multi': []}

        self.opw00006_output['single']['출력건수'] = self._get_comm_data(trcode, rqname, 0, '출력건수')

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['주문번호'] = self._get_comm_data(trcode, rqname, i, '주문번호')
            temp['원주문번호'] = self._get_comm_data(trcode, rqname, i, '원주문번호')
            temp['모주문번호'] = self._get_comm_data(trcode, rqname, i, '모주문번호')
            temp['계좌번호'] = self._get_comm_data(trcode, rqname, i, '계좌번호')
            temp['계좌명'] = self._get_comm_data(trcode, rqname, i, '계좌명')
            temp['종목코드'] = self._get_comm_data(trcode, rqname, i, '종목코드')
            temp['정정구분'] = self._get_comm_data(trcode, rqname, i, '정정구분')
            temp['매도수구분'] = self._get_comm_data(trcode, rqname, i, '매도수구분')
            temp['주문구분'] = self._get_comm_data(trcode, rqname, i, '주문구분')
            temp['통신주문구분'] = self._get_comm_data(trcode, rqname, i, '통신주문구분')
            temp['주문수량'] = self._get_comm_data(trcode, rqname, i, '주문수량')
            temp['주문지수'] = self._get_comm_data(trcode, rqname, i, '주문지수')
            temp['주문잔량'] = self._get_comm_data(trcode, rqname, i, '주문잔량')
            temp['체결수량'] = self._get_comm_data(trcode, rqname, i, '체결수량')
            temp['체결지수'] = self._get_comm_data(trcode, rqname, i, '체결지수')
            temp['접수여부'] = self._get_comm_data(trcode, rqname, i, '접수여부')
            temp['체결번호'] = self._get_comm_data(trcode, rqname, i, '체결번호')
            self.opw00006_output['multi'].append(temp)

    def _opw00007(self, rqname, trcode):
        """
    	계좌별주문체결내역상세요청
    	"""
        self.opw00007_output = {'single': dict(), 'multi': []}

        self.opw00007_output['single']['출력건수'] = self._get_comm_data(trcode, rqname, 0, '출력건수')

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['주문번호'] = self._get_comm_data(trcode, rqname, i, '주문번호')
            temp['종목번호'] = self._get_comm_data(trcode, rqname, i, '종목번호')
            temp['매매구분'] = self._get_comm_data(trcode, rqname, i, '매매구분')
            temp['신용구분'] = self._get_comm_data(trcode, rqname, i, '신용구분')
            temp['주문수량'] = self._get_comm_data(trcode, rqname, i, '주문수량')
            temp['주문단가'] = self._get_comm_data(trcode, rqname, i, '주문단가')
            temp['확인수량'] = self._get_comm_data(trcode, rqname, i, '확인수량')
            temp['접수구분'] = self._get_comm_data(trcode, rqname, i, '접수구분')
            temp['반대여부'] = self._get_comm_data(trcode, rqname, i, '반대여부')
            temp['주문시간'] = self._get_comm_data(trcode, rqname, i, '주문시간')
            temp['원주문'] = self._get_comm_data(trcode, rqname, i, '원주문')
            temp['종목명'] = self._get_comm_data(trcode, rqname, i, '종목명')
            temp['주문구분'] = self._get_comm_data(trcode, rqname, i, '주문구분')
            temp['대출일'] = self._get_comm_data(trcode, rqname, i, '대출일')
            temp['체결수량'] = self._get_comm_data(trcode, rqname, i, '체결수량')
            temp['체결단가'] = self._get_comm_data(trcode, rqname, i, '체결단가')
            temp['주문잔량'] = self._get_comm_data(trcode, rqname, i, '주문잔량')
            temp['통신구분'] = self._get_comm_data(trcode, rqname, i, '통신구분')
            temp['정정취소'] = self._get_comm_data(trcode, rqname, i, '정정취소')
            temp['확인시간'] = self._get_comm_data(trcode, rqname, i, '확인시간')
            self.opw00007_output['multi'].append(temp)

    def _opw00008(self, rqname, trcode):
        """
    	계좌별익일결제예정내역요청
    	"""
        self.opw00008_output = {'single': dict(), 'multi': []}

        self.opw00008_output['single']['매매일자'] = self._get_comm_data(trcode, rqname, 0, '매매일자')
        self.opw00008_output['single']['결제일자'] = self._get_comm_data(trcode, rqname, 0, '결제일자')
        self.opw00008_output['single']['매도정산합'] = self._get_comm_data(trcode, rqname, 0, '매도정산합')
        self.opw00008_output['single']['매수정산합'] = self._get_comm_data(trcode, rqname, 0, '매수정산합')
        self.opw00008_output['single']['조회건수'] = self._get_comm_data(trcode, rqname, 0, '조회건수')

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['일련번호'] = self._get_comm_data(trcode, rqname, i, '일련번호')
            temp['종목번호'] = self._get_comm_data(trcode, rqname, i, '종목번호')
            temp['대출일'] = self._get_comm_data(trcode, rqname, i, '대출일')
            temp['수량'] = self._get_comm_data(trcode, rqname, i, '수량')
            temp['약정금액'] = self._get_comm_data(trcode, rqname, i, '약정금액')
            temp['수수료'] = self._get_comm_data(trcode, rqname, i, '수수료')
            temp['소득세'] = self._get_comm_data(trcode, rqname, i, '소득세')
            temp['농특세'] = self._get_comm_data(trcode, rqname, i, '농특세')
            temp['종목명'] = self._get_comm_data(trcode, rqname, i, '종목명')
            temp['매도수구분'] = self._get_comm_data(trcode, rqname, i, '매도수구분')
            temp['단가'] = self._get_comm_data(trcode, rqname, i, '단가')
            temp['정산금액'] = self._get_comm_data(trcode, rqname, i, '정산금액')
            temp['거래세'] = self._get_comm_data(trcode, rqname, i, '거래세')
            temp['주민세'] = self._get_comm_data(trcode, rqname, i, '주민세')
            temp['신용구분'] = self._get_comm_data(trcode, rqname, i, '신용구분')
            self.opw00008_output['multi'].append(temp)

    def _opw00009(self, rqname, trcode):
        """
    	계좌별주문체결현황요청
    	"""
        self.opw00009_output = {'single': dict(), 'multi': []}

        self.opw00009_output['single']['매도약정금액'] = self._get_comm_data(trcode, rqname, 0, '매도약정금액')
        self.opw00009_output['single']['매수약정금액'] = self._get_comm_data(trcode, rqname, 0, '매수약정금액')
        self.opw00009_output['single']['약정금액'] = self._get_comm_data(trcode, rqname, 0, '약정금액')
        self.opw00009_output['single']['조회건수'] = self._get_comm_data(trcode, rqname, 0, '조회건수')

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['주식채권구분'] = self._get_comm_data(trcode, rqname, i, '주식채권구분')
            temp['주문번호'] = self._get_comm_data(trcode, rqname, i, '주문번호')
            temp['종목번호'] = self._get_comm_data(trcode, rqname, i, '종목번호')
            temp['매매구분'] = self._get_comm_data(trcode, rqname, i, '매매구분')
            temp['주문유형구분'] = self._get_comm_data(trcode, rqname, i, '주문유형구분')
            temp['주문수량'] = self._get_comm_data(trcode, rqname, i, '주문수량')
            temp['주문단가'] = self._get_comm_data(trcode, rqname, i, '주문단가')
            temp['확인수량'] = self._get_comm_data(trcode, rqname, i, '확인수량')
            temp['예약반대'] = self._get_comm_data(trcode, rqname, i, '예약반대')
            temp['체결번호'] = self._get_comm_data(trcode, rqname, i, '체결번호')
            temp['접수구분'] = self._get_comm_data(trcode, rqname, i, '접수구분')
            temp['원주문번호'] = self._get_comm_data(trcode, rqname, i, '원주문번호')
            temp['종목명'] = self._get_comm_data(trcode, rqname, i, '종목명')
            temp['결제구분'] = self._get_comm_data(trcode, rqname, i, '결제구분')
            temp['신용거래구분'] = self._get_comm_data(trcode, rqname, i, '신용거래구분')
            temp['체결수량'] = self._get_comm_data(trcode, rqname, i, '체결수량')
            temp['체결단가'] = self._get_comm_data(trcode, rqname, i, '체결단가')
            temp['통신구분'] = self._get_comm_data(trcode, rqname, i, '통신구분')
            temp['정정취소구분'] = self._get_comm_data(trcode, rqname, i, '정정취소구분')
            temp['체결시간'] = self._get_comm_data(trcode, rqname, i, '체결시간')
            self.opw00009_output['multi'].append(temp)

    def _opw00010(self, rqname, trcode):
        """
    	주문인출가능금액요청
    	"""
        self.opw00010_output = {'single': dict()}

        self.opw00010_output['single']['증거금20주문가능금액'] = self._get_comm_data(trcode, rqname, 0, '증거금20주문가능금액')
        self.opw00010_output['single']['증거금20주문가능수량'] = self._get_comm_data(trcode, rqname, 0, '증거금20주문가능수량')
        self.opw00010_output['single']['증거금30주문가능금액'] = self._get_comm_data(trcode, rqname, 0, '증거금30주문가능금액')
        self.opw00010_output['single']['증거금30주문가능수량'] = self._get_comm_data(trcode, rqname, 0, '증거금30주문가능수량')
        self.opw00010_output['single']['증거금40주문가능금액'] = self._get_comm_data(trcode, rqname, 0, '증거금40주문가능금액')
        self.opw00010_output['single']['증거금40주문가능수량'] = self._get_comm_data(trcode, rqname, 0, '증거금40주문가능수량')
        self.opw00010_output['single']['증거금50주문가능금액'] = self._get_comm_data(trcode, rqname, 0, '증거금50주문가능금액')
        self.opw00010_output['single']['증거금50주문가능수량'] = self._get_comm_data(trcode, rqname, 0, '증거금50주문가능수량')
        self.opw00010_output['single']['증거금60주문가능금액'] = self._get_comm_data(trcode, rqname, 0, '증거금60주문가능금액')
        self.opw00010_output['single']['증거금60주문가능수량'] = self._get_comm_data(trcode, rqname, 0, '증거금60주문가능수량')
        self.opw00010_output['single']['증거금감면60주문가능금'] = self._get_comm_data(trcode, rqname, 0, '증거금감면60주문가능금')
        self.opw00010_output['single']['증거금감면60주문가능수'] = self._get_comm_data(trcode, rqname, 0, '증거금감면60주문가능수')
        self.opw00010_output['single']['증거금100주문가능금액'] = self._get_comm_data(trcode, rqname, 0, '증거금100주문가능금액')
        self.opw00010_output['single']['증거금100주문가능수량'] = self._get_comm_data(trcode, rqname, 0, '증거금100주문가능수량')
        self.opw00010_output['single']['전일재사용가능금액'] = self._get_comm_data(trcode, rqname, 0, '전일재사용가능금액')
        self.opw00010_output['single']['금일재사용가능금액'] = self._get_comm_data(trcode, rqname, 0, '금일재사용가능금액')
        self.opw00010_output['single']['예수금'] = self._get_comm_data(trcode, rqname, 0, '예수금')
        self.opw00010_output['single']['대용금'] = self._get_comm_data(trcode, rqname, 0, '대용금')
        self.opw00010_output['single']['미수금'] = self._get_comm_data(trcode, rqname, 0, '미수금')
        self.opw00010_output['single']['주문가능대용'] = self._get_comm_data(trcode, rqname, 0, '주문가능대용')
        self.opw00010_output['single']['주문가능현금'] = self._get_comm_data(trcode, rqname, 0, '주문가능현금')
        self.opw00010_output['single']['인출가능금액'] = self._get_comm_data(trcode, rqname, 0, '인출가능금액')
        self.opw00010_output['single']['익일인출가능금액'] = self._get_comm_data(trcode, rqname, 0, '익일인출가능금액')
        self.opw00010_output['single']['매입금액'] = self._get_comm_data(trcode, rqname, 0, '매입금액')
        self.opw00010_output['single']['수수료'] = self._get_comm_data(trcode, rqname, 0, '수수료')
        self.opw00010_output['single']['매입정산금'] = self._get_comm_data(trcode, rqname, 0, '매입정산금')
        self.opw00010_output['single']['D2추정예수금'] = self._get_comm_data(trcode, rqname, 0, 'D2추정예수금')
        self.opw00010_output['single']['증거금감면적용구분'] = self._get_comm_data(trcode, rqname, 0, '증거금감면적용구분')

    def _opw00011(self, rqname, trcode):
        """
    	증거금율별주문가능수량조회요청
    	"""
        self.opw00011_output = {'single': dict()}

        self.opw00011_output['single']['종목증거금율'] = self._get_comm_data(trcode, rqname, 0, '종목증거금율')
        self.opw00011_output['single']['계좌증거금율'] = self._get_comm_data(trcode, rqname, 0, '계좌증거금율')
        self.opw00011_output['single']['적용증거금율'] = self._get_comm_data(trcode, rqname, 0, '적용증거금율')
        self.opw00011_output['single']['증거금20주문가능금액'] = self._get_comm_data(trcode, rqname, 0, '증거금20주문가능금액')
        self.opw00011_output['single']['증거금20주문가능수량'] = self._get_comm_data(trcode, rqname, 0, '증거금20주문가능수량')
        self.opw00011_output['single']['증거금20전일재사용금액'] = self._get_comm_data(trcode, rqname, 0, '증거금20전일재사용금액')
        self.opw00011_output['single']['증거금20금일재사용금액'] = self._get_comm_data(trcode, rqname, 0, '증거금20금일재사용금액')
        self.opw00011_output['single']['증거금30주문가능금액'] = self._get_comm_data(trcode, rqname, 0, '증거금30주문가능금액')
        self.opw00011_output['single']['증거금30주문가능수량'] = self._get_comm_data(trcode, rqname, 0, '증거금30주문가능수량')
        self.opw00011_output['single']['증거금30전일재사용금액'] = self._get_comm_data(trcode, rqname, 0, '증거금30전일재사용금액')
        self.opw00011_output['single']['증거금30금일재사용금액'] = self._get_comm_data(trcode, rqname, 0, '증거금30금일재사용금액')
        self.opw00011_output['single']['증거금40주문가능금액'] = self._get_comm_data(trcode, rqname, 0, '증거금40주문가능금액')
        self.opw00011_output['single']['증거금40주문가능수량'] = self._get_comm_data(trcode, rqname, 0, '증거금40주문가능수량')
        self.opw00011_output['single']['증거금40전일재사용금액'] = self._get_comm_data(trcode, rqname, 0, '증거금40전일재사용금액')
        self.opw00011_output['single']['증거금40금일재사용금액'] = self._get_comm_data(trcode, rqname, 0, '증거금40금일재사용금액')
        self.opw00011_output['single']['증거금50주문가능금액'] = self._get_comm_data(trcode, rqname, 0, '증거금50주문가능금액')
        self.opw00011_output['single']['증거금50주문가능수량'] = self._get_comm_data(trcode, rqname, 0, '증거금50주문가능수량')
        self.opw00011_output['single']['증거금50전일재사용금액'] = self._get_comm_data(trcode, rqname, 0, '증거금50전일재사용금액')
        self.opw00011_output['single']['증거금50금일재사용금액'] = self._get_comm_data(trcode, rqname, 0, '증거금50금일재사용금액')
        self.opw00011_output['single']['증거금60주문가능금액'] = self._get_comm_data(trcode, rqname, 0, '증거금60주문가능금액')
        self.opw00011_output['single']['증거금60주문가능수량'] = self._get_comm_data(trcode, rqname, 0, '증거금60주문가능수량')
        self.opw00011_output['single']['증거금60전일재사용금액'] = self._get_comm_data(trcode, rqname, 0, '증거금60전일재사용금액')
        self.opw00011_output['single']['증거금60금일재사용금액'] = self._get_comm_data(trcode, rqname, 0, '증거금60금일재사용금액')
        self.opw00011_output['single']['증거금100주문가능금액'] = self._get_comm_data(trcode, rqname, 0, '증거금100주문가능금액')
        self.opw00011_output['single']['증거금100주문가능수량'] = self._get_comm_data(trcode, rqname, 0, '증거금100주문가능수량')
        self.opw00011_output['single']['증거금100전일재사용금액'] = self._get_comm_data(trcode, rqname, 0, '증거금100전일재사용금액')
        self.opw00011_output['single']['증거금100금일재사용금액'] = self._get_comm_data(trcode, rqname, 0, '증거금100금일재사용금액')
        self.opw00011_output['single']['미수불가주문가능금액'] = self._get_comm_data(trcode, rqname, 0, '미수불가주문가능금액')
        self.opw00011_output['single']['미수불가주문가능수량'] = self._get_comm_data(trcode, rqname, 0, '미수불가주문가능수량')
        self.opw00011_output['single']['미수불가전일재사용금액'] = self._get_comm_data(trcode, rqname, 0, '미수불가전일재사용금액')
        self.opw00011_output['single']['미수불가금일재사용금액'] = self._get_comm_data(trcode, rqname, 0, '미수불가금일재사용금액')
        self.opw00011_output['single']['예수금'] = self._get_comm_data(trcode, rqname, 0, '예수금')
        self.opw00011_output['single']['대용금'] = self._get_comm_data(trcode, rqname, 0, '대용금')
        self.opw00011_output['single']['미수금'] = self._get_comm_data(trcode, rqname, 0, '미수금')
        self.opw00011_output['single']['주문가능대용'] = self._get_comm_data(trcode, rqname, 0, '주문가능대용')
        self.opw00011_output['single']['주문가능현금'] = self._get_comm_data(trcode, rqname, 0, '주문가능현금')

    def _opw00012(self, rqname, trcode):
        """
    	신용보증금율별주문가능수량조회요청
    	"""
        self.opw00012_output = {'single': dict()}

        self.opw00012_output['single']['종목보증금율'] = self._get_comm_data(trcode, rqname, 0, '종목보증금율')
        self.opw00012_output['single']['종목보증금율명'] = self._get_comm_data(trcode, rqname, 0, '종목보증금율명')
        self.opw00012_output['single']['보증금30주문가능금액'] = self._get_comm_data(trcode, rqname, 0, '보증금30주문가능금액')
        self.opw00012_output['single']['보증금30주문가능수량'] = self._get_comm_data(trcode, rqname, 0, '보증금30주문가능수량')
        self.opw00012_output['single']['보증금30전일재사용금액'] = self._get_comm_data(trcode, rqname, 0, '보증금30전일재사용금액')
        self.opw00012_output['single']['보증금30금일재사용금액'] = self._get_comm_data(trcode, rqname, 0, '보증금30금일재사용금액')
        self.opw00012_output['single']['보증금40주문가능금액'] = self._get_comm_data(trcode, rqname, 0, '보증금40주문가능금액')
        self.opw00012_output['single']['보증금40주문가능수량'] = self._get_comm_data(trcode, rqname, 0, '보증금40주문가능수량')
        self.opw00012_output['single']['보증금40전일재사용금액'] = self._get_comm_data(trcode, rqname, 0, '보증금40전일재사용금액')
        self.opw00012_output['single']['보증금40금일재사용금액'] = self._get_comm_data(trcode, rqname, 0, '보증금40금일재사용금액')
        self.opw00012_output['single']['보증금50주문가능금액'] = self._get_comm_data(trcode, rqname, 0, '보증금50주문가능금액')
        self.opw00012_output['single']['보증금50주문가능수량'] = self._get_comm_data(trcode, rqname, 0, '보증금50주문가능수량')
        self.opw00012_output['single']['보증금50전일재사용금액'] = self._get_comm_data(trcode, rqname, 0, '보증금50전일재사용금액')
        self.opw00012_output['single']['보증금50금일재사용금액'] = self._get_comm_data(trcode, rqname, 0, '보증금50금일재사용금액')
        self.opw00012_output['single']['보증금60주문가능금액'] = self._get_comm_data(trcode, rqname, 0, '보증금60주문가능금액')
        self.opw00012_output['single']['보증금60주문가능수량'] = self._get_comm_data(trcode, rqname, 0, '보증금60주문가능수량')
        self.opw00012_output['single']['보증금60전일재사용금액'] = self._get_comm_data(trcode, rqname, 0, '보증금60전일재사용금액')
        self.opw00012_output['single']['보증금60금일재사용금액'] = self._get_comm_data(trcode, rqname, 0, '보증금60금일재사용금액')
        self.opw00012_output['single']['예수금'] = self._get_comm_data(trcode, rqname, 0, '예수금')
        self.opw00012_output['single']['대용금'] = self._get_comm_data(trcode, rqname, 0, '대용금')
        self.opw00012_output['single']['미수금'] = self._get_comm_data(trcode, rqname, 0, '미수금')
        self.opw00012_output['single']['주문가능대용'] = self._get_comm_data(trcode, rqname, 0, '주문가능대용')
        self.opw00012_output['single']['주문가능현금'] = self._get_comm_data(trcode, rqname, 0, '주문가능현금')
        self.opw00012_output['single']['미수가능금액'] = self._get_comm_data(trcode, rqname, 0, '미수가능금액')
        self.opw00012_output['single']['미수가능수량'] = self._get_comm_data(trcode, rqname, 0, '미수가능수량')
        self.opw00012_output['single']['미수불가금액'] = self._get_comm_data(trcode, rqname, 0, '미수불가금액')
        self.opw00012_output['single']['미수불가수량'] = self._get_comm_data(trcode, rqname, 0, '미수불가수량')

    def _opw00013(self, rqname, trcode):
        """
    	증거금세부내역조회요청
    	"""
        self.opw00013_output = {'single': dict()}

        self.opw00013_output['single']['금일재사용대상금액'] = self._get_comm_data(trcode, rqname, 0, '금일재사용대상금액')
        self.opw00013_output['single']['금일재사용사용금액'] = self._get_comm_data(trcode, rqname, 0, '금일재사용사용금액')
        self.opw00013_output['single']['금일재사용가능금액'] = self._get_comm_data(trcode, rqname, 0, '금일재사용가능금액')
        self.opw00013_output['single']['금일재사용제한금액'] = self._get_comm_data(trcode, rqname, 0, '금일재사용제한금액')
        self.opw00013_output['single']['금일재사용가능금액최종'] = self._get_comm_data(trcode, rqname, 0, '금일재사용가능금액최종')
        self.opw00013_output['single']['전일재사용대상금액'] = self._get_comm_data(trcode, rqname, 0, '전일재사용대상금액')
        self.opw00013_output['single']['전일재사용사용금액'] = self._get_comm_data(trcode, rqname, 0, '전일재사용사용금액')
        self.opw00013_output['single']['전일재사용가능금액'] = self._get_comm_data(trcode, rqname, 0, '전일재사용가능금액')
        self.opw00013_output['single']['전일재사용제한금액'] = self._get_comm_data(trcode, rqname, 0, '전일재사용제한금액')
        self.opw00013_output['single']['전일재사용가능금액최종'] = self._get_comm_data(trcode, rqname, 0, '전일재사용가능금액최종')
        self.opw00013_output['single']['현금금액'] = self._get_comm_data(trcode, rqname, 0, '현금금액')
        self.opw00013_output['single']['현금증거금'] = self._get_comm_data(trcode, rqname, 0, '현금증거금')
        self.opw00013_output['single']['사용가능현금'] = self._get_comm_data(trcode, rqname, 0, '사용가능현금')
        self.opw00013_output['single']['현금사용제한금액'] = self._get_comm_data(trcode, rqname, 0, '현금사용제한금액')
        self.opw00013_output['single']['사용가능현금최종'] = self._get_comm_data(trcode, rqname, 0, '사용가능현금최종')
        self.opw00013_output['single']['대용금액'] = self._get_comm_data(trcode, rqname, 0, '대용금액')
        self.opw00013_output['single']['대용증거금'] = self._get_comm_data(trcode, rqname, 0, '대용증거금')
        self.opw00013_output['single']['사용가능대용'] = self._get_comm_data(trcode, rqname, 0, '사용가능대용')
        self.opw00013_output['single']['대용사용제한금액'] = self._get_comm_data(trcode, rqname, 0, '대용사용제한금액')
        self.opw00013_output['single']['사용가능대용최종'] = self._get_comm_data(trcode, rqname, 0, '사용가능대용최종')
        self.opw00013_output['single']['신용보증금현금'] = self._get_comm_data(trcode, rqname, 0, '신용보증금현금')
        self.opw00013_output['single']['신용보증금대용'] = self._get_comm_data(trcode, rqname, 0, '신용보증금대용')
        self.opw00013_output['single']['신용담보금현금'] = self._get_comm_data(trcode, rqname, 0, '신용담보금현금')
        self.opw00013_output['single']['신용담보금대용'] = self._get_comm_data(trcode, rqname, 0, '신용담보금대용')
        self.opw00013_output['single']['미수금'] = self._get_comm_data(trcode, rqname, 0, '미수금')
        self.opw00013_output['single']['대주담보금재사용금'] = self._get_comm_data(trcode, rqname, 0, '대주담보금재사용금')
        self.opw00013_output['single']['20주문가능금액'] = self._get_comm_data(trcode, rqname, 0, '20주문가능금액')
        self.opw00013_output['single']['30주문가능금액'] = self._get_comm_data(trcode, rqname, 0, '30주문가능금액')
        self.opw00013_output['single']['40주문가능금액'] = self._get_comm_data(trcode, rqname, 0, '40주문가능금액')
        self.opw00013_output['single']['50주문가능금액'] = self._get_comm_data(trcode, rqname, 0, '50주문가능금액')
        self.opw00013_output['single']['60주문가능금액'] = self._get_comm_data(trcode, rqname, 0, '60주문가능금액')
        self.opw00013_output['single']['100주문가능금액'] = self._get_comm_data(trcode, rqname, 0, '100주문가능금액')
        self.opw00013_output['single']['금일신용상환손실금액'] = self._get_comm_data(trcode, rqname, 0, '금일신용상환손실금액')
        self.opw00013_output['single']['전일신용상환손실금액'] = self._get_comm_data(trcode, rqname, 0, '전일신용상환손실금액')
        self.opw00013_output['single']['금일대주상환손실대용증거금'] = self._get_comm_data(trcode, rqname, 0, '금일대주상환손실대용증거금')
        self.opw00013_output['single']['전일대주상환손실대용증거금'] = self._get_comm_data(trcode, rqname, 0, '전일대주상환손실대용증거금')
        self.opw00013_output['single']['평가대용금(현물사용제외)'] = self._get_comm_data(trcode, rqname, 0, '평가대용금(현물사용제외)')
        self.opw00013_output['single']['평가대용비율'] = self._get_comm_data(trcode, rqname, 0, '평가대용비율')
        self.opw00013_output['single']['신용대용증거금'] = self._get_comm_data(trcode, rqname, 0, '신용대용증거금')
        self.opw00013_output['single']['현금주문대용증거금'] = self._get_comm_data(trcode, rqname, 0, '현금주문대용증거금')
        self.opw00013_output['single']['신용주문대용증거금'] = self._get_comm_data(trcode, rqname, 0, '신용주문대용증거금')
        self.opw00013_output['single']['신용대용환산금'] = self._get_comm_data(trcode, rqname, 0, '신용대용환산금')
        self.opw00013_output['single']['대용가능금액'] = self._get_comm_data(trcode, rqname, 0, '대용가능금액')
        self.opw00013_output['single']['대용가능금액2'] = self._get_comm_data(trcode, rqname, 0, '대용가능금액2')
        self.opw00013_output['single']['현금대용부족금'] = self._get_comm_data(trcode, rqname, 0, '현금대용부족금')
        self.opw00013_output['single']['신용대용부족금'] = self._get_comm_data(trcode, rqname, 0, '신용대용부족금')
        self.opw00013_output['single']['현금주문가능대용금'] = self._get_comm_data(trcode, rqname, 0, '현금주문가능대용금')
        self.opw00013_output['single']['신용주문가능대용금'] = self._get_comm_data(trcode, rqname, 0, '신용주문가능대용금')

    def _opw00014(self, rqname, trcode):
        """
    	비밀번호일치여부요청
    	"""
        self.opw00014_output = {'single': dict()}

        self.opw00014_output['single']['일치여부'] = self._get_comm_data(trcode, rqname, 0, '일치여부')

    def _opw00015(self, rqname, trcode):
        """
    	위탁종합거래내역요청
    	"""
        self.opw00015_output = {'single': dict(), 'multi': []}

        self.opw00015_output['single']['계좌번호'] = self._get_comm_data(trcode, rqname, 0, '계좌번호')
        self.opw00015_output['single']['출력건수'] = self._get_comm_data(trcode, rqname, 0, '출력건수')

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['거래일자'] = self._get_comm_data(trcode, rqname, i, '거래일자')
            temp['거래번호'] = self._get_comm_data(trcode, rqname, i, '거래번호')
            temp['적요명'] = self._get_comm_data(trcode, rqname, i, '적요명')
            temp['신용거래구분명'] = self._get_comm_data(trcode, rqname, i, '신용거래구분명')
            temp['정산금액'] = self._get_comm_data(trcode, rqname, i, '정산금액')
            temp['대출금상환'] = self._get_comm_data(trcode, rqname, i, '대출금상환')
            temp['거래금액(외)'] = self._get_comm_data(trcode, rqname, i, '거래금액(외)')
            temp['정산금액(외)'] = self._get_comm_data(trcode, rqname, i, '정산금액(외)')
            temp['예수금잔고'] = self._get_comm_data(trcode, rqname, i, '예수금잔고')
            temp['통화코드'] = self._get_comm_data(trcode, rqname, i, '통화코드')
            temp['거래종류구분'] = self._get_comm_data(trcode, rqname, i, '거래종류구분')
            temp['거래종류명'] = self._get_comm_data(trcode, rqname, i, '거래종류명')
            temp['종목명'] = self._get_comm_data(trcode, rqname, i, '종목명')
            temp['거래금액'] = self._get_comm_data(trcode, rqname, i, '거래금액')
            temp['거래및농특세'] = self._get_comm_data(trcode, rqname, i, '거래및농특세')
            temp['상환차금'] = self._get_comm_data(trcode, rqname, i, '상환차금')
            temp['거래세(외)'] = self._get_comm_data(trcode, rqname, i, '거래세(외)')
            temp['연체합'] = self._get_comm_data(trcode, rqname, i, '연체합')
            temp['외화예수금잔고'] = self._get_comm_data(trcode, rqname, i, '외화예수금잔고')
            temp['매체구분명'] = self._get_comm_data(trcode, rqname, i, '매체구분명')
            temp['입출구분'] = self._get_comm_data(trcode, rqname, i, '입출구분')
            temp['입출구분명'] = self._get_comm_data(trcode, rqname, i, '입출구분명')
            temp['원거래번호'] = self._get_comm_data(trcode, rqname, i, '원거래번호')
            temp['종목코드'] = self._get_comm_data(trcode, rqname, i, '종목코드')
            temp['거래수량/좌수'] = self._get_comm_data(trcode, rqname, i, '거래수량/좌수')
            temp['수수료'] = self._get_comm_data(trcode, rqname, i, '수수료')
            temp['이자/대주이용'] = self._get_comm_data(trcode, rqname, i, '이자/대주이용')
            temp['수수료(외)'] = self._get_comm_data(trcode, rqname, i, '수수료(외)')
            temp['연체합(외)'] = self._get_comm_data(trcode, rqname, i, '연체합(외)')
            temp['유가금잔'] = self._get_comm_data(trcode, rqname, i, '유가금잔')
            temp['처리시간'] = self._get_comm_data(trcode, rqname, i, '처리시간')
            temp['ISIN코드'] = self._get_comm_data(trcode, rqname, i, 'ISIN코드')
            temp['거래소코드'] = self._get_comm_data(trcode, rqname, i, '거래소코드')
            temp['거래소명'] = self._get_comm_data(trcode, rqname, i, '거래소명')
            temp['거래단가/환율'] = self._get_comm_data(trcode, rqname, i, '거래단가/환율')
            temp['소득/주민세'] = self._get_comm_data(trcode, rqname, i, '소득/주민세')
            temp['대출일'] = self._get_comm_data(trcode, rqname, i, '대출일')
            temp['미수(원/주)'] = self._get_comm_data(trcode, rqname, i, '미수(원/주)')
            temp['변제합'] = self._get_comm_data(trcode, rqname, i, '변제합')
            temp['체결일'] = self._get_comm_data(trcode, rqname, i, '체결일')
            temp['출납번호'] = self._get_comm_data(trcode, rqname, i, '출납번호')
            temp['처리자'] = self._get_comm_data(trcode, rqname, i, '처리자')
            temp['처리점'] = self._get_comm_data(trcode, rqname, i, '처리점')
            temp['매매형태'] = self._get_comm_data(trcode, rqname, i, '매매형태')
            temp['과세기준가'] = self._get_comm_data(trcode, rqname, i, '과세기준가')
            temp['세금수수료합'] = self._get_comm_data(trcode, rqname, i, '세금수수료합')
            temp['외국납부세액(외)'] = self._get_comm_data(trcode, rqname, i, '외국납부세액(외)')
            temp['미수(외)'] = self._get_comm_data(trcode, rqname, i, '미수(외)')
            temp['변제합(외)'] = self._get_comm_data(trcode, rqname, i, '변제합(외)')
            temp['입금자'] = self._get_comm_data(trcode, rqname, i, '입금자')
            temp['거래내역구분'] = self._get_comm_data(trcode, rqname, i, '거래내역구분')
            self.opw00015_output['multi'].append(temp)

    def _opw00016(self, rqname, trcode):
        """
    	일별계좌수익률상세현황요청
    	"""
        self.opw00016_output = {'single': dict()}

        self.opw00016_output['single']['관리사원번호'] = self._get_comm_data(trcode, rqname, 0, '관리사원번호')
        self.opw00016_output['single']['관리자명'] = self._get_comm_data(trcode, rqname, 0, '관리자명')
        self.opw00016_output['single']['관리자지점'] = self._get_comm_data(trcode, rqname, 0, '관리자지점')
        self.opw00016_output['single']['예수금_초'] = self._get_comm_data(trcode, rqname, 0, '예수금_초')
        self.opw00016_output['single']['예수금_말'] = self._get_comm_data(trcode, rqname, 0, '예수금_말')
        self.opw00016_output['single']['유가증권평가금액_초'] = self._get_comm_data(trcode, rqname, 0, '유가증권평가금액_초')
        self.opw00016_output['single']['유가증권평가금액_말'] = self._get_comm_data(trcode, rqname, 0, '유가증권평가금액_말')
        self.opw00016_output['single']['대주담보금_초'] = self._get_comm_data(trcode, rqname, 0, '대주담보금_초')
        self.opw00016_output['single']['대주담보금_말'] = self._get_comm_data(trcode, rqname, 0, '대주담보금_말')
        self.opw00016_output['single']['신용융자금_초'] = self._get_comm_data(trcode, rqname, 0, '신용융자금_초')
        self.opw00016_output['single']['신용융자금_말'] = self._get_comm_data(trcode, rqname, 0, '신용융자금_말')
        self.opw00016_output['single']['현금미수금_초'] = self._get_comm_data(trcode, rqname, 0, '현금미수금_초')
        self.opw00016_output['single']['현금미수금_말'] = self._get_comm_data(trcode, rqname, 0, '현금미수금_말')
        self.opw00016_output['single']['원화대용금_초'] = self._get_comm_data(trcode, rqname, 0, '원화대용금_초')
        self.opw00016_output['single']['원화대용금_말'] = self._get_comm_data(trcode, rqname, 0, '원화대용금_말')
        self.opw00016_output['single']['대주평가금_초'] = self._get_comm_data(trcode, rqname, 0, '대주평가금_초')
        self.opw00016_output['single']['대주평가금_말'] = self._get_comm_data(trcode, rqname, 0, '대주평가금_말')
        self.opw00016_output['single']['권리평가금_초'] = self._get_comm_data(trcode, rqname, 0, '권리평가금_초')
        self.opw00016_output['single']['권리평가금_말'] = self._get_comm_data(trcode, rqname, 0, '권리평가금_말')
        self.opw00016_output['single']['대출금_초'] = self._get_comm_data(trcode, rqname, 0, '대출금_초')
        self.opw00016_output['single']['대출금_말'] = self._get_comm_data(trcode, rqname, 0, '대출금_말')
        self.opw00016_output['single']['기타대여금_초'] = self._get_comm_data(trcode, rqname, 0, '기타대여금_초')
        self.opw00016_output['single']['기타대여금_말'] = self._get_comm_data(trcode, rqname, 0, '기타대여금_말')
        self.opw00016_output['single']['신용이자미납금_초'] = self._get_comm_data(trcode, rqname, 0, '신용이자미납금_초')
        self.opw00016_output['single']['신용이자미납금_말'] = self._get_comm_data(trcode, rqname, 0, '신용이자미납금_말')
        self.opw00016_output['single']['신용이자_초'] = self._get_comm_data(trcode, rqname, 0, '신용이자_초')
        self.opw00016_output['single']['신용이자_말'] = self._get_comm_data(trcode, rqname, 0, '신용이자_말')
        self.opw00016_output['single']['순자산액계_초'] = self._get_comm_data(trcode, rqname, 0, '순자산액계_초')
        self.opw00016_output['single']['순자산액계_말'] = self._get_comm_data(trcode, rqname, 0, '순자산액계_말')
        self.opw00016_output['single']['투자원금평잔'] = self._get_comm_data(trcode, rqname, 0, '투자원금평잔')
        self.opw00016_output['single']['평가손익'] = self._get_comm_data(trcode, rqname, 0, '평가손익')
        self.opw00016_output['single']['수익률'] = self._get_comm_data(trcode, rqname, 0, '수익률')
        self.opw00016_output['single']['회전율'] = self._get_comm_data(trcode, rqname, 0, '회전율')
        self.opw00016_output['single']['기간내총입금'] = self._get_comm_data(trcode, rqname, 0, '기간내총입금')
        self.opw00016_output['single']['기간내총출금'] = self._get_comm_data(trcode, rqname, 0, '기간내총출금')
        self.opw00016_output['single']['기간내총입고'] = self._get_comm_data(trcode, rqname, 0, '기간내총입고')
        self.opw00016_output['single']['기간내총출고'] = self._get_comm_data(trcode, rqname, 0, '기간내총출고')
        self.opw00016_output['single']['선물대용매도금액'] = self._get_comm_data(trcode, rqname, 0, '선물대용매도금액')
        self.opw00016_output['single']['위탁대용매도금액'] = self._get_comm_data(trcode, rqname, 0, '위탁대용매도금액')

    def _opw00017(self, rqname, trcode):
        """
    	계좌별당일현황요청
    	"""
        self.opw00017_output = {'single': dict()}

        self.opw00017_output['single']['D+2추정예수금'] = self._get_comm_data(trcode, rqname, 0, 'D+2추정예수금')
        self.opw00017_output['single']['신용이자미납금'] = self._get_comm_data(trcode, rqname, 0, '신용이자미납금')
        self.opw00017_output['single']['기타대여금'] = self._get_comm_data(trcode, rqname, 0, '기타대여금')
        self.opw00017_output['single']['일반주식평가금액D+2'] = self._get_comm_data(trcode, rqname, 0, '일반주식평가금액D+2')
        self.opw00017_output['single']['예탁담보대출금D+2'] = self._get_comm_data(trcode, rqname, 0, '예탁담보대출금D+2')
        self.opw00017_output['single']['예탁담보주식평가금액D+2'] = self._get_comm_data(trcode, rqname, 0, '예탁담보주식평가금액D+2')
        self.opw00017_output['single']['신용융자금D+2'] = self._get_comm_data(trcode, rqname, 0, '신용융자금D+2')
        self.opw00017_output['single']['신용융자평가금D+2'] = self._get_comm_data(trcode, rqname, 0, '신용융자평가금D+2')
        self.opw00017_output['single']['신용대주담보금D+2'] = self._get_comm_data(trcode, rqname, 0, '신용대주담보금D+2')
        self.opw00017_output['single']['신용대주평가금D+2'] = self._get_comm_data(trcode, rqname, 0, '신용대주평가금D+2')
        self.opw00017_output['single']['입금금액'] = self._get_comm_data(trcode, rqname, 0, '입금금액')
        self.opw00017_output['single']['출금금액'] = self._get_comm_data(trcode, rqname, 0, '출금금액')
        self.opw00017_output['single']['입고금액'] = self._get_comm_data(trcode, rqname, 0, '입고금액')
        self.opw00017_output['single']['출고금액'] = self._get_comm_data(trcode, rqname, 0, '출고금액')
        self.opw00017_output['single']['매도금액'] = self._get_comm_data(trcode, rqname, 0, '매도금액')
        self.opw00017_output['single']['매수금액'] = self._get_comm_data(trcode, rqname, 0, '매수금액')
        self.opw00017_output['single']['수수료'] = self._get_comm_data(trcode, rqname, 0, '수수료')
        self.opw00017_output['single']['세금'] = self._get_comm_data(trcode, rqname, 0, '세금')
        self.opw00017_output['single']['주식매입자금대출금'] = self._get_comm_data(trcode, rqname, 0, '주식매입자금대출금')
        self.opw00017_output['single']['RP평가금액'] = self._get_comm_data(trcode, rqname, 0, 'RP평가금액')
        self.opw00017_output['single']['채권평가금액'] = self._get_comm_data(trcode, rqname, 0, '채권평가금액')
        self.opw00017_output['single']['ELS평가금액'] = self._get_comm_data(trcode, rqname, 0, 'ELS평가금액')
        self.opw00017_output['single']['신용이자금액'] = self._get_comm_data(trcode, rqname, 0, '신용이자금액')
        self.opw00017_output['single']['매도대금담보대출이자금액'] = self._get_comm_data(trcode, rqname, 0, '매도대금담보대출이자금액')
        self.opw00017_output['single']['배당금액'] = self._get_comm_data(trcode, rqname, 0, '배당금액')

    def _opw00018(self, rqname, trcode):
        """
    	계좌평가잔고내역요청
    	"""
        self.opw00018_output = {'single': dict(), 'multi': []}

        self.opw00018_output['single']['총매입금액'] = self._get_comm_data(trcode, rqname, 0, '총매입금액')
        self.opw00018_output['single']['총평가금액'] = self._get_comm_data(trcode, rqname, 0, '총평가금액')
        self.opw00018_output['single']['총평가손익금액'] = self._get_comm_data(trcode, rqname, 0, '총평가손익금액')
        self.opw00018_output['single']['총수익률(%)'] = self._get_comm_data(trcode, rqname, 0, '총수익률(%)')
        self.opw00018_output['single']['추정예탁자산'] = self._get_comm_data(trcode, rqname, 0, '추정예탁자산')
        self.opw00018_output['single']['총대출금'] = self._get_comm_data(trcode, rqname, 0, '총대출금')
        self.opw00018_output['single']['총융자금액'] = self._get_comm_data(trcode, rqname, 0, '총융자금액')
        self.opw00018_output['single']['총대주금액'] = self._get_comm_data(trcode, rqname, 0, '총대주금액')
        self.opw00018_output['single']['조회건수'] = self._get_comm_data(trcode, rqname, 0, '조회건수')

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['종목번호'] = self._get_comm_data(trcode, rqname, i, '종목번호')
            temp['종목명'] = self._get_comm_data(trcode, rqname, i, '종목명')
            temp['평가손익'] = self._get_comm_data(trcode, rqname, i, '평가손익')
            temp['수익률(%)'] = self._get_comm_data(trcode, rqname, i, '수익률(%)')
            temp['매입가'] = self._get_comm_data(trcode, rqname, i, '매입가')
            temp['전일종가'] = self._get_comm_data(trcode, rqname, i, '전일종가')
            temp['보유수량'] = self._get_comm_data(trcode, rqname, i, '보유수량')
            temp['매매가능수량'] = self._get_comm_data(trcode, rqname, i, '매매가능수량')
            temp['현재가'] = self._get_comm_data(trcode, rqname, i, '현재가')
            temp['전일매수수량'] = self._get_comm_data(trcode, rqname, i, '전일매수수량')
            temp['전일매도수량'] = self._get_comm_data(trcode, rqname, i, '전일매도수량')
            temp['금일매수수량'] = self._get_comm_data(trcode, rqname, i, '금일매수수량')
            temp['금일매도수량'] = self._get_comm_data(trcode, rqname, i, '금일매도수량')
            temp['매입금액'] = self._get_comm_data(trcode, rqname, i, '매입금액')
            temp['매입수수료'] = self._get_comm_data(trcode, rqname, i, '매입수수료')
            temp['평가금액'] = self._get_comm_data(trcode, rqname, i, '평가금액')
            temp['평가수수료'] = self._get_comm_data(trcode, rqname, i, '평가수수료')
            temp['세금'] = self._get_comm_data(trcode, rqname, i, '세금')
            temp['수수료합'] = self._get_comm_data(trcode, rqname, i, '수수료합')
            temp['보유비중(%)'] = self._get_comm_data(trcode, rqname, i, '보유비중(%)')
            temp['신용구분'] = self._get_comm_data(trcode, rqname, i, '신용구분')
            temp['신용구분명'] = self._get_comm_data(trcode, rqname, i, '신용구분명')
            temp['대출일'] = self._get_comm_data(trcode, rqname, i, '대출일')
            self.opw00018_output['multi'].append(temp)

    def _opw20001(self, rqname, trcode):
        """
    	선물옵션청산주문위탁증거금가계산요청
    	"""
        self.opw20001_output = {'single': dict()}

        self.opw20001_output['single']['현재위탁증거금총액'] = self._get_comm_data(trcode, rqname, 0, '현재위탁증거금총액')
        self.opw20001_output['single']['현재현금예탁필요액'] = self._get_comm_data(trcode, rqname, 0, '현재현금예탁필요액')
        self.opw20001_output['single']['체결위탁증거금총액'] = self._get_comm_data(trcode, rqname, 0, '체결위탁증거금총액')
        self.opw20001_output['single']['체결현금예탁필요액'] = self._get_comm_data(trcode, rqname, 0, '체결현금예탁필요액')
        self.opw20001_output['single']['증감위탁증거금총액'] = self._get_comm_data(trcode, rqname, 0, '증감위탁증거금총액')
        self.opw20001_output['single']['증감현금예탁필요액'] = self._get_comm_data(trcode, rqname, 0, '증감현금예탁필요액')

    def _opw20002(self, rqname, trcode):
        """
    	선옵당일매매변동현황요청
    	"""
        self.opw20002_output = {'single': dict()}

        self.opw20002_output['single']['선물수수료'] = self._get_comm_data(trcode, rqname, 0, '선물수수료')
        self.opw20002_output['single']['옵션수수료'] = self._get_comm_data(trcode, rqname, 0, '옵션수수료')
        self.opw20002_output['single']['주식옵션수수료'] = self._get_comm_data(trcode, rqname, 0, '주식옵션수수료')
        self.opw20002_output['single']['선물매도수량'] = self._get_comm_data(trcode, rqname, 0, '선물매도수량')
        self.opw20002_output['single']['선물매도금액'] = self._get_comm_data(trcode, rqname, 0, '선물매도금액')
        self.opw20002_output['single']['선물매도평균가격'] = self._get_comm_data(trcode, rqname, 0, '선물매도평균가격')
        self.opw20002_output['single']['선물매수수량'] = self._get_comm_data(trcode, rqname, 0, '선물매수수량')
        self.opw20002_output['single']['선물매수금액'] = self._get_comm_data(trcode, rqname, 0, '선물매수금액')
        self.opw20002_output['single']['선물매수평균가격'] = self._get_comm_data(trcode, rqname, 0, '선물매수평균가격')
        self.opw20002_output['single']['선물전매수량'] = self._get_comm_data(trcode, rqname, 0, '선물전매수량')
        self.opw20002_output['single']['선물전매금액'] = self._get_comm_data(trcode, rqname, 0, '선물전매금액')
        self.opw20002_output['single']['선물환매수량'] = self._get_comm_data(trcode, rqname, 0, '선물환매수량')
        self.opw20002_output['single']['선물환매금액'] = self._get_comm_data(trcode, rqname, 0, '선물환매금액')
        self.opw20002_output['single']['콜매도수량'] = self._get_comm_data(trcode, rqname, 0, '콜매도수량')
        self.opw20002_output['single']['콜매도금액'] = self._get_comm_data(trcode, rqname, 0, '콜매도금액')
        self.opw20002_output['single']['콜매도평균가격'] = self._get_comm_data(trcode, rqname, 0, '콜매도평균가격')
        self.opw20002_output['single']['콜매수수량'] = self._get_comm_data(trcode, rqname, 0, '콜매수수량')
        self.opw20002_output['single']['콜매수금액'] = self._get_comm_data(trcode, rqname, 0, '콜매수금액')
        self.opw20002_output['single']['콜매수평균가격'] = self._get_comm_data(trcode, rqname, 0, '콜매수평균가격')
        self.opw20002_output['single']['콜전매수량'] = self._get_comm_data(trcode, rqname, 0, '콜전매수량')
        self.opw20002_output['single']['콜전매금액'] = self._get_comm_data(trcode, rqname, 0, '콜전매금액')
        self.opw20002_output['single']['콜환매수량'] = self._get_comm_data(trcode, rqname, 0, '콜환매수량')
        self.opw20002_output['single']['콜환매금액'] = self._get_comm_data(trcode, rqname, 0, '콜환매금액')
        self.opw20002_output['single']['풋매도수량'] = self._get_comm_data(trcode, rqname, 0, '풋매도수량')
        self.opw20002_output['single']['풋매도금액'] = self._get_comm_data(trcode, rqname, 0, '풋매도금액')
        self.opw20002_output['single']['풋매도평균가격'] = self._get_comm_data(trcode, rqname, 0, '풋매도평균가격')
        self.opw20002_output['single']['풋매수수량'] = self._get_comm_data(trcode, rqname, 0, '풋매수수량')
        self.opw20002_output['single']['풋매수금액'] = self._get_comm_data(trcode, rqname, 0, '풋매수금액')
        self.opw20002_output['single']['풋매수평균가격'] = self._get_comm_data(trcode, rqname, 0, '풋매수평균가격')
        self.opw20002_output['single']['풋전매수량'] = self._get_comm_data(trcode, rqname, 0, '풋전매수량')
        self.opw20002_output['single']['풋전매금액'] = self._get_comm_data(trcode, rqname, 0, '풋전매금액')
        self.opw20002_output['single']['풋환매수량'] = self._get_comm_data(trcode, rqname, 0, '풋환매수량')
        self.opw20002_output['single']['풋환매금액'] = self._get_comm_data(trcode, rqname, 0, '풋환매금액')
        self.opw20002_output['single']['선물최종매도수량'] = self._get_comm_data(trcode, rqname, 0, '선물최종매도수량')
        self.opw20002_output['single']['선물최종매도금액'] = self._get_comm_data(trcode, rqname, 0, '선물최종매도금액')
        self.opw20002_output['single']['선물최종매도평균가격'] = self._get_comm_data(trcode, rqname, 0, '선물최종매도평균가격')
        self.opw20002_output['single']['선물최종매수수량'] = self._get_comm_data(trcode, rqname, 0, '선물최종매수수량')
        self.opw20002_output['single']['선물최종매수금액'] = self._get_comm_data(trcode, rqname, 0, '선물최종매수금액')
        self.opw20002_output['single']['선물최종매수평균가격'] = self._get_comm_data(trcode, rqname, 0, '선물최종매수평균가격')
        self.opw20002_output['single']['콜권리행사수량'] = self._get_comm_data(trcode, rqname, 0, '콜권리행사수량')
        self.opw20002_output['single']['콜권리행사금액'] = self._get_comm_data(trcode, rqname, 0, '콜권리행사금액')
        self.opw20002_output['single']['콜권리행사가격'] = self._get_comm_data(trcode, rqname, 0, '콜권리행사가격')
        self.opw20002_output['single']['풋권리행사수량'] = self._get_comm_data(trcode, rqname, 0, '풋권리행사수량')
        self.opw20002_output['single']['풋권리행사금액'] = self._get_comm_data(trcode, rqname, 0, '풋권리행사금액')
        self.opw20002_output['single']['풋권리행사가격'] = self._get_comm_data(trcode, rqname, 0, '풋권리행사가격')
        self.opw20002_output['single']['콜권리배정수량'] = self._get_comm_data(trcode, rqname, 0, '콜권리배정수량')
        self.opw20002_output['single']['콜권리배정금액'] = self._get_comm_data(trcode, rqname, 0, '콜권리배정금액')
        self.opw20002_output['single']['콜권리배정가격'] = self._get_comm_data(trcode, rqname, 0, '콜권리배정가격')
        self.opw20002_output['single']['풋권리배정수량'] = self._get_comm_data(trcode, rqname, 0, '풋권리배정수량')
        self.opw20002_output['single']['풋권리배정금액'] = self._get_comm_data(trcode, rqname, 0, '풋권리배정금액')
        self.opw20002_output['single']['풋권리배정가격'] = self._get_comm_data(trcode, rqname, 0, '풋권리배정가격')

    def _opw20003(self, rqname, trcode):
        """
    	선옵기간손익조회요청
    	"""
        self.opw20003_output = {'single': dict(), 'multi': []}

        self.opw20003_output['single']['선물약정금액'] = self._get_comm_data(trcode, rqname, 0, '선물약정금액')
        self.opw20003_output['single']['옵션약정금액'] = self._get_comm_data(trcode, rqname, 0, '옵션약정금액')
        self.opw20003_output['single']['선물정산손익'] = self._get_comm_data(trcode, rqname, 0, '선물정산손익')
        self.opw20003_output['single']['옵션매매손익'] = self._get_comm_data(trcode, rqname, 0, '옵션매매손익')
        self.opw20003_output['single']['총손익'] = self._get_comm_data(trcode, rqname, 0, '총손익')
        self.opw20003_output['single']['평균예탁금액'] = self._get_comm_data(trcode, rqname, 0, '평균예탁금액')
        self.opw20003_output['single']['예탁총액'] = self._get_comm_data(trcode, rqname, 0, '예탁총액')
        self.opw20003_output['single']['수수료'] = self._get_comm_data(trcode, rqname, 0, '수수료')
        self.opw20003_output['single']['수익율'] = self._get_comm_data(trcode, rqname, 0, '수익율')
        self.opw20003_output['single']['조회건수'] = self._get_comm_data(trcode, rqname, 0, '조회건수')

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['종목코드'] = self._get_comm_data(trcode, rqname, i, '종목코드')
            temp['매도수구분'] = self._get_comm_data(trcode, rqname, i, '매도수구분')
            temp['잔고수량'] = self._get_comm_data(trcode, rqname, i, '잔고수량')
            temp['평균가격'] = self._get_comm_data(trcode, rqname, i, '평균가격')
            temp['전일종가'] = self._get_comm_data(trcode, rqname, i, '전일종가')
            temp['평가손익'] = self._get_comm_data(trcode, rqname, i, '평가손익')
            temp['종목명'] = self._get_comm_data(trcode, rqname, i, '종목명')
            self.opw20003_output['multi'].append(temp)

    def _opw20004(self, rqname, trcode):
        """
    	선옵주문체결내역상세요청
    	"""
        self.opw20004_output = {'single': dict(), 'multi': []}

        self.opw20004_output['single']['출력건수'] = self._get_comm_data(trcode, rqname, 0, '출력건수')

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['주문번호'] = self._get_comm_data(trcode, rqname, i, '주문번호')
            temp['매매구분'] = self._get_comm_data(trcode, rqname, i, '매매구분')
            temp['종목코드'] = self._get_comm_data(trcode, rqname, i, '종목코드')
            temp['주문수량'] = self._get_comm_data(trcode, rqname, i, '주문수량')
            temp['체결수량'] = self._get_comm_data(trcode, rqname, i, '체결수량')
            temp['미체결수량'] = self._get_comm_data(trcode, rqname, i, '미체결수량')
            temp['접수번호'] = self._get_comm_data(trcode, rqname, i, '접수번호')
            temp['접수구분'] = self._get_comm_data(trcode, rqname, i, '접수구분')
            temp['조작자사번'] = self._get_comm_data(trcode, rqname, i, '조작자사번')
            temp['원주문번호'] = self._get_comm_data(trcode, rqname, i, '원주문번호')
            temp['주문유형'] = self._get_comm_data(trcode, rqname, i, '주문유형')
            temp['종목명'] = self._get_comm_data(trcode, rqname, i, '종목명')
            temp['주문가격'] = self._get_comm_data(trcode, rqname, i, '주문가격')
            temp['체결가격'] = self._get_comm_data(trcode, rqname, i, '체결가격')
            temp['체결번호'] = self._get_comm_data(trcode, rqname, i, '체결번호')
            temp['약정시간'] = self._get_comm_data(trcode, rqname, i, '약정시간')
            temp['접수시간'] = self._get_comm_data(trcode, rqname, i, '접수시간')
            temp['매체'] = self._get_comm_data(trcode, rqname, i, '매체')
            self.opw20004_output['multi'].append(temp)

    def _opw20005(self, rqname, trcode):
        """
    	선옵주문체결내역상세평균가요청
    	"""
        self.opw20005_output = {'single': dict(), 'multi': []}

        self.opw20005_output['single']['출력건수'] = self._get_comm_data(trcode, rqname, 0, '출력건수')

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['주문번호'] = self._get_comm_data(trcode, rqname, i, '주문번호')
            temp['매매구분'] = self._get_comm_data(trcode, rqname, i, '매매구분')
            temp['종목코드'] = self._get_comm_data(trcode, rqname, i, '종목코드')
            temp['주문수량'] = self._get_comm_data(trcode, rqname, i, '주문수량')
            temp['체결수량'] = self._get_comm_data(trcode, rqname, i, '체결수량')
            temp['미체결수량'] = self._get_comm_data(trcode, rqname, i, '미체결수량')
            temp['접수번호'] = self._get_comm_data(trcode, rqname, i, '접수번호')
            temp['접수구분'] = self._get_comm_data(trcode, rqname, i, '접수구분')
            temp['조작자사번'] = self._get_comm_data(trcode, rqname, i, '조작자사번')
            temp['원주문번호'] = self._get_comm_data(trcode, rqname, i, '원주문번호')
            temp['주문유형'] = self._get_comm_data(trcode, rqname, i, '주문유형')
            temp['종목명'] = self._get_comm_data(trcode, rqname, i, '종목명')
            temp['주문가격'] = self._get_comm_data(trcode, rqname, i, '주문가격')
            temp['체결가'] = self._get_comm_data(trcode, rqname, i, '체결가')
            temp['체결번호'] = self._get_comm_data(trcode, rqname, i, '체결번호')
            temp['약정시간'] = self._get_comm_data(trcode, rqname, i, '약정시간')
            temp['접수시간'] = self._get_comm_data(trcode, rqname, i, '접수시간')
            temp['매체'] = self._get_comm_data(trcode, rqname, i, '매체')
            self.opw20005_output['multi'].append(temp)

    def _opw20006(self, rqname, trcode):
        """
    	선옵잔고상세현황요청
    	"""
        self.opw20006_output = {'single': dict(), 'multi': []}

        self.opw20006_output['single']['선물매도수량'] = self._get_comm_data(trcode, rqname, 0, '선물매도수량')
        self.opw20006_output['single']['선물매수수량'] = self._get_comm_data(trcode, rqname, 0, '선물매수수량')
        self.opw20006_output['single']['콜매도수량'] = self._get_comm_data(trcode, rqname, 0, '콜매도수량')
        self.opw20006_output['single']['콜매수수량'] = self._get_comm_data(trcode, rqname, 0, '콜매수수량')
        self.opw20006_output['single']['풋매도수량'] = self._get_comm_data(trcode, rqname, 0, '풋매도수량')
        self.opw20006_output['single']['풋매수수량'] = self._get_comm_data(trcode, rqname, 0, '풋매수수량')
        self.opw20006_output['single']['선물매도금액'] = self._get_comm_data(trcode, rqname, 0, '선물매도금액')
        self.opw20006_output['single']['선물매수금액'] = self._get_comm_data(trcode, rqname, 0, '선물매수금액')
        self.opw20006_output['single']['콜매도금액'] = self._get_comm_data(trcode, rqname, 0, '콜매도금액')
        self.opw20006_output['single']['콜매수금액'] = self._get_comm_data(trcode, rqname, 0, '콜매수금액')
        self.opw20006_output['single']['풋매도금액'] = self._get_comm_data(trcode, rqname, 0, '풋매도금액')
        self.opw20006_output['single']['풋매수금액'] = self._get_comm_data(trcode, rqname, 0, '풋매수금액')
        self.opw20006_output['single']['약정합계'] = self._get_comm_data(trcode, rqname, 0, '약정합계')
        self.opw20006_output['single']['손익합계'] = self._get_comm_data(trcode, rqname, 0, '손익합계')
        self.opw20006_output['single']['조회건수        '] = self._get_comm_data(trcode, rqname, 0, '조회건수        ')

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['종목코드'] = self._get_comm_data(trcode, rqname, i, '종목코드')
            temp['종목명'] = self._get_comm_data(trcode, rqname, i, '종목명')
            temp['매매일자'] = self._get_comm_data(trcode, rqname, i, '매매일자')
            temp['매매구분'] = self._get_comm_data(trcode, rqname, i, '매매구분')
            temp['잔고수량'] = self._get_comm_data(trcode, rqname, i, '잔고수량')
            temp['매입단가'] = self._get_comm_data(trcode, rqname, i, '매입단가')
            temp['매매금액'] = self._get_comm_data(trcode, rqname, i, '매매금액')
            temp['현재가'] = self._get_comm_data(trcode, rqname, i, '현재가')
            temp['평가손익'] = self._get_comm_data(trcode, rqname, i, '평가손익')
            temp['손익율'] = self._get_comm_data(trcode, rqname, i, '손익율')
            temp['평가금액'] = self._get_comm_data(trcode, rqname, i, '평가금액')
            self.opw20006_output['multi'].append(temp)

    def _opw20007(self, rqname, trcode):
        """
    	선옵잔고현황정산가기준요청
    	"""
        self.opw20007_output = {'single': dict(), 'multi': []}

        self.opw20007_output['single']['약정금액합계'] = self._get_comm_data(trcode, rqname, 0, '약정금액합계')
        self.opw20007_output['single']['평가손익합계'] = self._get_comm_data(trcode, rqname, 0, '평가손익합계')
        self.opw20007_output['single']['출력건수'] = self._get_comm_data(trcode, rqname, 0, '출력건수')

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['종목코드'] = self._get_comm_data(trcode, rqname, i, '종목코드')
            temp['종목명'] = self._get_comm_data(trcode, rqname, i, '종목명')
            temp['매도매수구분'] = self._get_comm_data(trcode, rqname, i, '매도매수구분')
            temp['수량'] = self._get_comm_data(trcode, rqname, i, '수량')
            temp['매입단가'] = self._get_comm_data(trcode, rqname, i, '매입단가')
            temp['현재가'] = self._get_comm_data(trcode, rqname, i, '현재가')
            temp['평가손익'] = self._get_comm_data(trcode, rqname, i, '평가손익')
            temp['청산가능수량'] = self._get_comm_data(trcode, rqname, i, '청산가능수량')
            temp['약정금액'] = self._get_comm_data(trcode, rqname, i, '약정금액')
            temp['평가금액'] = self._get_comm_data(trcode, rqname, i, '평가금액')
            self.opw20007_output['multi'].append(temp)

    def _opw20008(self, rqname, trcode):
        """
    	계좌별결제예상내역조회요청
    	"""
        self.opw20008_output = {'single': dict()}

        self.opw20008_output['single']['계좌명'] = self._get_comm_data(trcode, rqname, 0, '계좌명')
        self.opw20008_output['single']['예탁총액'] = self._get_comm_data(trcode, rqname, 0, '예탁총액')
        self.opw20008_output['single']['추정예탁총액'] = self._get_comm_data(trcode, rqname, 0, '추정예탁총액')
        self.opw20008_output['single']['예탁현금'] = self._get_comm_data(trcode, rqname, 0, '예탁현금')
        self.opw20008_output['single']['추정예탁현금'] = self._get_comm_data(trcode, rqname, 0, '추정예탁현금')
        self.opw20008_output['single']['선물당일차금'] = self._get_comm_data(trcode, rqname, 0, '선물당일차금')
        self.opw20008_output['single']['선물갱신차금'] = self._get_comm_data(trcode, rqname, 0, '선물갱신차금')
        self.opw20008_output['single']['선물최종결제차금'] = self._get_comm_data(trcode, rqname, 0, '선물최종결제차금')
        self.opw20008_output['single']['선물예상정산손익'] = self._get_comm_data(trcode, rqname, 0, '선물예상정산손익')
        self.opw20008_output['single']['옵션매수대금'] = self._get_comm_data(trcode, rqname, 0, '옵션매수대금')
        self.opw20008_output['single']['옵션매도대금'] = self._get_comm_data(trcode, rqname, 0, '옵션매도대금')
        self.opw20008_output['single']['옵션행사차금'] = self._get_comm_data(trcode, rqname, 0, '옵션행사차금')
        self.opw20008_output['single']['옵션배정차금'] = self._get_comm_data(trcode, rqname, 0, '옵션배정차금')
        self.opw20008_output['single']['주식옵션행사대금'] = self._get_comm_data(trcode, rqname, 0, '주식옵션행사대금')
        self.opw20008_output['single']['주식옵션배정대금'] = self._get_comm_data(trcode, rqname, 0, '주식옵션배정대금')
        self.opw20008_output['single']['인수도대금'] = self._get_comm_data(trcode, rqname, 0, '인수도대금')
        self.opw20008_output['single']['전일대용매도체결금액'] = self._get_comm_data(trcode, rqname, 0, '전일대용매도체결금액')
        self.opw20008_output['single']['금일대용매도체결금액'] = self._get_comm_data(trcode, rqname, 0, '금일대용매도체결금액')
        self.opw20008_output['single']['선물수수료'] = self._get_comm_data(trcode, rqname, 0, '선물수수료')
        self.opw20008_output['single']['옵션수수료'] = self._get_comm_data(trcode, rqname, 0, '옵션수수료')
        self.opw20008_output['single']['결제가격수신여부'] = self._get_comm_data(trcode, rqname, 0, '결제가격수신여부')
        self.opw20008_output['single']['유지증거금총액'] = self._get_comm_data(trcode, rqname, 0, '유지증거금총액')
        self.opw20008_output['single']['유지증거금총액부족액'] = self._get_comm_data(trcode, rqname, 0, '유지증거금총액부족액')
        self.opw20008_output['single']['유지증거금현금부족액'] = self._get_comm_data(trcode, rqname, 0, '유지증거금현금부족액')
        self.opw20008_output['single']['옵션잔고평가손익'] = self._get_comm_data(trcode, rqname, 0, '옵션잔고평가손익')
        self.opw20008_output['single']['예탁대용'] = self._get_comm_data(trcode, rqname, 0, '예탁대용')
        self.opw20008_output['single']['익일결제예정금액'] = self._get_comm_data(trcode, rqname, 0, '익일결제예정금액')

    def _opw20009(self, rqname, trcode):
        """
    	선옵계좌별주문가능수량요청
    	"""
        self.opw20009_output = {'single': dict()}

        self.opw20009_output['single']['예탁총액'] = self._get_comm_data(trcode, rqname, 0, '예탁총액')
        self.opw20009_output['single']['예탁현금'] = self._get_comm_data(trcode, rqname, 0, '예탁현금')
        self.opw20009_output['single']['위탁증거금'] = self._get_comm_data(trcode, rqname, 0, '위탁증거금')
        self.opw20009_output['single']['현금증거금'] = self._get_comm_data(trcode, rqname, 0, '현금증거금')
        self.opw20009_output['single']['주문가능금액'] = self._get_comm_data(trcode, rqname, 0, '주문가능금액')
        self.opw20009_output['single']['주문가능총액'] = self._get_comm_data(trcode, rqname, 0, '주문가능총액')
        self.opw20009_output['single']['신규가능수량'] = self._get_comm_data(trcode, rqname, 0, '신규가능수량')
        self.opw20009_output['single']['청산가능수량'] = self._get_comm_data(trcode, rqname, 0, '청산가능수량')
        self.opw20009_output['single']['총가능수량'] = self._get_comm_data(trcode, rqname, 0, '총가능수량')
        self.opw20009_output['single']['필요증거금총액'] = self._get_comm_data(trcode, rqname, 0, '필요증거금총액')
        self.opw20009_output['single']['총액부족액'] = self._get_comm_data(trcode, rqname, 0, '총액부족액')
        self.opw20009_output['single']['주문가능현금'] = self._get_comm_data(trcode, rqname, 0, '주문가능현금')
        self.opw20009_output['single']['필요증거금현금'] = self._get_comm_data(trcode, rqname, 0, '필요증거금현금')
        self.opw20009_output['single']['현금부족액'] = self._get_comm_data(trcode, rqname, 0, '현금부족액')
        self.opw20009_output['single']['주문가능대용금'] = self._get_comm_data(trcode, rqname, 0, '주문가능대용금')
        self.opw20009_output['single']['필요증거금대용금'] = self._get_comm_data(trcode, rqname, 0, '필요증거금대용금')
        self.opw20009_output['single']['대용금부족액'] = self._get_comm_data(trcode, rqname, 0, '대용금부족액')

    def _opw20010(self, rqname, trcode):
        """
    	선옵예탁금및증거금조회요청
    	"""
        self.opw20010_output = {'single': dict()}

        self.opw20010_output['single']['예탁총액'] = self._get_comm_data(trcode, rqname, 0, '예탁총액')
        self.opw20010_output['single']['예탁현금'] = self._get_comm_data(trcode, rqname, 0, '예탁현금')
        self.opw20010_output['single']['에탁대용'] = self._get_comm_data(trcode, rqname, 0, '에탁대용')
        self.opw20010_output['single']['증거금총액'] = self._get_comm_data(trcode, rqname, 0, '증거금총액')
        self.opw20010_output['single']['증거금현금'] = self._get_comm_data(trcode, rqname, 0, '증거금현금')
        self.opw20010_output['single']['증거금대용금'] = self._get_comm_data(trcode, rqname, 0, '증거금대용금')
        self.opw20010_output['single']['주문가능총액'] = self._get_comm_data(trcode, rqname, 0, '주문가능총액')
        self.opw20010_output['single']['주문가능현금'] = self._get_comm_data(trcode, rqname, 0, '주문가능현금')
        self.opw20010_output['single']['주문가능대용금'] = self._get_comm_data(trcode, rqname, 0, '주문가능대용금')
        self.opw20010_output['single']['추가증거금총액'] = self._get_comm_data(trcode, rqname, 0, '추가증거금총액')
        self.opw20010_output['single']['추가증거금현금'] = self._get_comm_data(trcode, rqname, 0, '추가증거금현금')
        self.opw20010_output['single']['추가증거금대용금'] = self._get_comm_data(trcode, rqname, 0, '추가증거금대용금')
        self.opw20010_output['single']['인출가능총액'] = self._get_comm_data(trcode, rqname, 0, '인출가능총액')
        self.opw20010_output['single']['인출가능현금'] = self._get_comm_data(trcode, rqname, 0, '인출가능현금')
        self.opw20010_output['single']['인출가능대용금'] = self._get_comm_data(trcode, rqname, 0, '인출가능대용금')
        self.opw20010_output['single']['순자산금액'] = self._get_comm_data(trcode, rqname, 0, '순자산금액')
        self.opw20010_output['single']['익일예탁총액'] = self._get_comm_data(trcode, rqname, 0, '익일예탁총액')
        self.opw20010_output['single']['개장예탁총액'] = self._get_comm_data(trcode, rqname, 0, '개장예탁총액')
        self.opw20010_output['single']['선물정산차금'] = self._get_comm_data(trcode, rqname, 0, '선물정산차금')
        self.opw20010_output['single']['선물청산손익'] = self._get_comm_data(trcode, rqname, 0, '선물청산손익')
        self.opw20010_output['single']['선물평가손익'] = self._get_comm_data(trcode, rqname, 0, '선물평가손익')
        self.opw20010_output['single']['선물약정금액'] = self._get_comm_data(trcode, rqname, 0, '선물약정금액')
        self.opw20010_output['single']['옵션결제차금'] = self._get_comm_data(trcode, rqname, 0, '옵션결제차금')
        self.opw20010_output['single']['옵션청산손익'] = self._get_comm_data(trcode, rqname, 0, '옵션청산손익')
        self.opw20010_output['single']['옵션평가손익'] = self._get_comm_data(trcode, rqname, 0, '옵션평가손익')
        self.opw20010_output['single']['옵션약정금액'] = self._get_comm_data(trcode, rqname, 0, '옵션약정금액')
        self.opw20010_output['single']['전일장종료예탁총액'] = self._get_comm_data(trcode, rqname, 0, '전일장종료예탁총액')
        self.opw20010_output['single']['전일장종료예탁현금'] = self._get_comm_data(trcode, rqname, 0, '전일장종료예탁현금')
        self.opw20010_output['single']['전일장종료예탁대용금'] = self._get_comm_data(trcode, rqname, 0, '전일장종료예탁대용금')

    def _opw20011(self, rqname, trcode):
        """
    	선옵계좌예비증거금상세요청
    	"""
        self.opw20011_output = {'single': dict(), 'multi': []}

        self.opw20011_output['single']['출력건수'] = self._get_comm_data(trcode, rqname, 0, '출력건수')

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['기초자산명'] = self._get_comm_data(trcode, rqname, i, '기초자산명')
            temp['최대구간증거금'] = self._get_comm_data(trcode, rqname, i, '최대구간증거금')
            temp['증거금감면액'] = self._get_comm_data(trcode, rqname, i, '증거금감면액')
            temp['구간증거금01'] = self._get_comm_data(trcode, rqname, i, '구간증거금01')
            temp['구간증거금02'] = self._get_comm_data(trcode, rqname, i, '구간증거금02')
            temp['구간증거금03'] = self._get_comm_data(trcode, rqname, i, '구간증거금03')
            temp['구간증거금04'] = self._get_comm_data(trcode, rqname, i, '구간증거금04')
            temp['구간증거금05'] = self._get_comm_data(trcode, rqname, i, '구간증거금05')
            temp['구간증거금06'] = self._get_comm_data(trcode, rqname, i, '구간증거금06')
            temp['구간증거금07'] = self._get_comm_data(trcode, rqname, i, '구간증거금07')
            temp['구간증거금08'] = self._get_comm_data(trcode, rqname, i, '구간증거금08')
            temp['구간증거금09'] = self._get_comm_data(trcode, rqname, i, '구간증거금09')
            temp['구간증거금10'] = self._get_comm_data(trcode, rqname, i, '구간증거금10')
            temp['구간증거금11'] = self._get_comm_data(trcode, rqname, i, '구간증거금11')
            temp['구간증거금12'] = self._get_comm_data(trcode, rqname, i, '구간증거금12')
            temp['구간증거금13'] = self._get_comm_data(trcode, rqname, i, '구간증거금13')
            temp['구간증거금14'] = self._get_comm_data(trcode, rqname, i, '구간증거금14')
            temp['구간증거금15'] = self._get_comm_data(trcode, rqname, i, '구간증거금15')
            temp['구간증거금16'] = self._get_comm_data(trcode, rqname, i, '구간증거금16')
            temp['구간증거금17'] = self._get_comm_data(trcode, rqname, i, '구간증거금17')
            temp['구간증거금18'] = self._get_comm_data(trcode, rqname, i, '구간증거금18')
            temp['구간증거금19'] = self._get_comm_data(trcode, rqname, i, '구간증거금19')
            temp['구간증거금20'] = self._get_comm_data(trcode, rqname, i, '구간증거금20')
            temp['구간증거금21'] = self._get_comm_data(trcode, rqname, i, '구간증거금21')
            temp['구간증거금22'] = self._get_comm_data(trcode, rqname, i, '구간증거금22')
            temp['구간증거금23'] = self._get_comm_data(trcode, rqname, i, '구간증거금23')
            temp['구간증거금24'] = self._get_comm_data(trcode, rqname, i, '구간증거금24')
            temp['구간증거금25'] = self._get_comm_data(trcode, rqname, i, '구간증거금25')
            temp['구간증거금26'] = self._get_comm_data(trcode, rqname, i, '구간증거금26')
            temp['구간증거금27'] = self._get_comm_data(trcode, rqname, i, '구간증거금27')
            temp['구간증거금28'] = self._get_comm_data(trcode, rqname, i, '구간증거금28')
            temp['구간증거금29'] = self._get_comm_data(trcode, rqname, i, '구간증거금29')
            temp['구간증거금30'] = self._get_comm_data(trcode, rqname, i, '구간증거금30')
            temp['구간증거금31'] = self._get_comm_data(trcode, rqname, i, '구간증거금31')
            temp['구간증거금32'] = self._get_comm_data(trcode, rqname, i, '구간증거금32')
            temp['구간증거금33'] = self._get_comm_data(trcode, rqname, i, '구간증거금33')
            temp['구간증거금34'] = self._get_comm_data(trcode, rqname, i, '구간증거금34')
            temp['구간증거금35'] = self._get_comm_data(trcode, rqname, i, '구간증거금35')
            temp['구간증거금36'] = self._get_comm_data(trcode, rqname, i, '구간증거금36')
            temp['구간증거금37'] = self._get_comm_data(trcode, rqname, i, '구간증거금37')
            temp['구간증거금38'] = self._get_comm_data(trcode, rqname, i, '구간증거금38')
            temp['구간증거금39'] = self._get_comm_data(trcode, rqname, i, '구간증거금39')
            temp['구간증거금40'] = self._get_comm_data(trcode, rqname, i, '구간증거금40')
            temp['구간증거금41'] = self._get_comm_data(trcode, rqname, i, '구간증거금41')
            temp['구간증거금42'] = self._get_comm_data(trcode, rqname, i, '구간증거금42')
            temp['구간증거금43'] = self._get_comm_data(trcode, rqname, i, '구간증거금43')
            temp['구간증거금44'] = self._get_comm_data(trcode, rqname, i, '구간증거금44')
            temp['구간증거금45'] = self._get_comm_data(trcode, rqname, i, '구간증거금45')
            temp['구간증거금46'] = self._get_comm_data(trcode, rqname, i, '구간증거금46')
            temp['구간증거금47'] = self._get_comm_data(trcode, rqname, i, '구간증거금47')
            temp['구간증거금48'] = self._get_comm_data(trcode, rqname, i, '구간증거금48')
            temp['구간증거금49'] = self._get_comm_data(trcode, rqname, i, '구간증거금49')
            temp['구간증거금50'] = self._get_comm_data(trcode, rqname, i, '구간증거금50')
            temp['구간증거금51'] = self._get_comm_data(trcode, rqname, i, '구간증거금51')
            temp['구간증거금52'] = self._get_comm_data(trcode, rqname, i, '구간증거금52')
            temp['구간증거금53'] = self._get_comm_data(trcode, rqname, i, '구간증거금53')
            temp['구간증거금54'] = self._get_comm_data(trcode, rqname, i, '구간증거금54')
            temp['구간증거금55'] = self._get_comm_data(trcode, rqname, i, '구간증거금55')
            temp['구간증거금56'] = self._get_comm_data(trcode, rqname, i, '구간증거금56')
            temp['구간증거금57'] = self._get_comm_data(trcode, rqname, i, '구간증거금57')
            temp['구간증거금58'] = self._get_comm_data(trcode, rqname, i, '구간증거금58')
            temp['구간증거금59'] = self._get_comm_data(trcode, rqname, i, '구간증거금59')
            temp['구간증거금60'] = self._get_comm_data(trcode, rqname, i, '구간증거금60')
            temp['구간증거금61'] = self._get_comm_data(trcode, rqname, i, '구간증거금61')
            temp['구간증거금62'] = self._get_comm_data(trcode, rqname, i, '구간증거금62')
            self.opw20011_output['multi'].append(temp)

    def _opw20012(self, rqname, trcode):
        """
    	선옵증거금상세내역요청
    	"""
        self.opw20012_output = {'single': dict()}

        self.opw20012_output['single']['예탁총액'] = self._get_comm_data(trcode, rqname, 0, '예탁총액')
        self.opw20012_output['single']['예탁현금'] = self._get_comm_data(trcode, rqname, 0, '예탁현금')
        self.opw20012_output['single']['예탁대용'] = self._get_comm_data(trcode, rqname, 0, '예탁대용')
        self.opw20012_output['single']['위탁증거금총액'] = self._get_comm_data(trcode, rqname, 0, '위탁증거금총액')
        self.opw20012_output['single']['위탁현금증거금'] = self._get_comm_data(trcode, rqname, 0, '위탁현금증거금')
        self.opw20012_output['single']['유지증거금총액'] = self._get_comm_data(trcode, rqname, 0, '유지증거금총액')
        self.opw20012_output['single']['추가증거금총액'] = self._get_comm_data(trcode, rqname, 0, '추가증거금총액')
        self.opw20012_output['single']['추가증거금현금'] = self._get_comm_data(trcode, rqname, 0, '추가증거금현금')
        self.opw20012_output['single']['신규위탁증거금총액'] = self._get_comm_data(trcode, rqname, 0, '신규위탁증거금총액')
        self.opw20012_output['single']['선물신규주문증거금총액'] = self._get_comm_data(trcode, rqname, 0, '선물신규주문증거금총액')
        self.opw20012_output['single']['신규스프레드증거금'] = self._get_comm_data(trcode, rqname, 0, '신규스프레드증거금')
        self.opw20012_output['single']['옵션신규매수주문'] = self._get_comm_data(trcode, rqname, 0, '옵션신규매수주문')
        self.opw20012_output['single']['옵션신규매도주문'] = self._get_comm_data(trcode, rqname, 0, '옵션신규매도주문')
        self.opw20012_output['single']['위험위탁증거금'] = self._get_comm_data(trcode, rqname, 0, '위험위탁증거금')
        self.opw20012_output['single']['옵션가격증거금'] = self._get_comm_data(trcode, rqname, 0, '옵션가격증거금')
        self.opw20012_output['single']['가격변동증거금'] = self._get_comm_data(trcode, rqname, 0, '가격변동증거금')
        self.opw20012_output['single']['선물스프레드증거금'] = self._get_comm_data(trcode, rqname, 0, '선물스프레드증거금')
        self.opw20012_output['single']['인수도증거금'] = self._get_comm_data(trcode, rqname, 0, '인수도증거금')
        self.opw20012_output['single']['최소증거금'] = self._get_comm_data(trcode, rqname, 0, '최소증거금')
        self.opw20012_output['single']['당일옵션순매수대금'] = self._get_comm_data(trcode, rqname, 0, '당일옵션순매수대금')
        self.opw20012_output['single']['옵션매수대금'] = self._get_comm_data(trcode, rqname, 0, '옵션매수대금')
        self.opw20012_output['single']['선물체결순손익'] = self._get_comm_data(trcode, rqname, 0, '선물체결순손익')
        self.opw20012_output['single']['선물정산차금'] = self._get_comm_data(trcode, rqname, 0, '선물정산차금')
        self.opw20012_output['single']['옵션매도결제대금'] = self._get_comm_data(trcode, rqname, 0, '옵션매도결제대금')
        self.opw20012_output['single']['옵션매수결제대금'] = self._get_comm_data(trcode, rqname, 0, '옵션매수결제대금')
        self.opw20012_output['single']['수수료합계'] = self._get_comm_data(trcode, rqname, 0, '수수료합계')
        self.opw20012_output['single']['선물최종결제차금'] = self._get_comm_data(trcode, rqname, 0, '선물최종결제차금')
        self.opw20012_output['single']['인수도대금'] = self._get_comm_data(trcode, rqname, 0, '인수도대금')
        self.opw20012_output['single']['옵션행사대금'] = self._get_comm_data(trcode, rqname, 0, '옵션행사대금')
        self.opw20012_output['single']['옵션배정대금'] = self._get_comm_data(trcode, rqname, 0, '옵션배정대금')
        self.opw20012_output['single']['주문가능총액'] = self._get_comm_data(trcode, rqname, 0, '주문가능총액')
        self.opw20012_output['single']['주문가능현금'] = self._get_comm_data(trcode, rqname, 0, '주문가능현금')
        self.opw20012_output['single']['인출가능총액'] = self._get_comm_data(trcode, rqname, 0, '인출가능총액')
        self.opw20012_output['single']['인출가능현금'] = self._get_comm_data(trcode, rqname, 0, '인출가능현금')
        self.opw20012_output['single']['계좌명'] = self._get_comm_data(trcode, rqname, 0, '계좌명')
        self.opw20012_output['single']['계좌번호'] = self._get_comm_data(trcode, rqname, 0, '계좌번호')
        self.opw20012_output['single']['조회일자'] = self._get_comm_data(trcode, rqname, 0, '조회일자')
        self.opw20012_output['single']['예탁평가총액'] = self._get_comm_data(trcode, rqname, 0, '예탁평가총액')
        self.opw20012_output['single']['익일예탁총액'] = self._get_comm_data(trcode, rqname, 0, '익일예탁총액')
        self.opw20012_output['single']['전일대용매도금'] = self._get_comm_data(trcode, rqname, 0, '전일대용매도금')
        self.opw20012_output['single']['금일대용매도금액'] = self._get_comm_data(trcode, rqname, 0, '금일대용매도금액')
        self.opw20012_output['single']['미수연체료'] = self._get_comm_data(trcode, rqname, 0, '미수연체료')
        self.opw20012_output['single']['전일장종료예탁총액'] = self._get_comm_data(trcode, rqname, 0, '전일장종료예탁총액')
        self.opw20012_output['single']['전일장종료예탁현금'] = self._get_comm_data(trcode, rqname, 0, '전일장종료예탁현금')
        self.opw20012_output['single']['장중인출가능금액변경여부'] = self._get_comm_data(trcode, rqname, 0, '장중인출가능금액변경여부')

    def _opw20013(self, rqname, trcode):
        """
    	계좌미결제청산가능수량조회요청
    	"""
        self.opw20013_output = {'single': dict()}

        self.opw20013_output['single']['미결제수량'] = self._get_comm_data(trcode, rqname, 0, '미결제수량')
        self.opw20013_output['single']['청산가능수량'] = self._get_comm_data(trcode, rqname, 0, '청산가능수량')
        self.opw20013_output['single']['현재증거금총액'] = self._get_comm_data(trcode, rqname, 0, '현재증거금총액')
        self.opw20013_output['single']['현재증거금현금'] = self._get_comm_data(trcode, rqname, 0, '현재증거금현금')
        self.opw20013_output['single']['예상위탁증거금'] = self._get_comm_data(trcode, rqname, 0, '예상위탁증거금')
        self.opw20013_output['single']['예상현금증거금'] = self._get_comm_data(trcode, rqname, 0, '예상현금증거금')

    def _opw20014(self, rqname, trcode):
        """
    	선옵실시간증거금산출요청
    	"""
        self.opw20014_output = {'single': dict(), 'multi': []}

        self.opw20014_output['single']['계좌명'] = self._get_comm_data(trcode, rqname, 0, '계좌명')
        self.opw20014_output['single']['예탁총액'] = self._get_comm_data(trcode, rqname, 0, '예탁총액')
        self.opw20014_output['single']['예탁현금'] = self._get_comm_data(trcode, rqname, 0, '예탁현금')
        self.opw20014_output['single']['예탁대용금'] = self._get_comm_data(trcode, rqname, 0, '예탁대용금')
        self.opw20014_output['single']['위탁증거금'] = self._get_comm_data(trcode, rqname, 0, '위탁증거금')
        self.opw20014_output['single']['현금증거금'] = self._get_comm_data(trcode, rqname, 0, '현금증거금')
        self.opw20014_output['single']['추가증거금총액'] = self._get_comm_data(trcode, rqname, 0, '추가증거금총액')
        self.opw20014_output['single']['추가증거금현금'] = self._get_comm_data(trcode, rqname, 0, '추가증거금현금')
        self.opw20014_output['single']['추정예탁총액'] = self._get_comm_data(trcode, rqname, 0, '추정예탁총액')
        self.opw20014_output['single']['추정예탁현금'] = self._get_comm_data(trcode, rqname, 0, '추정예탁현금')
        self.opw20014_output['single']['추정위탁증거금총액'] = self._get_comm_data(trcode, rqname, 0, '추정위탁증거금총액')
        self.opw20014_output['single']['추정위탁증거금현금'] = self._get_comm_data(trcode, rqname, 0, '추정위탁증거금현금')
        self.opw20014_output['single']['추정유지증거금총액'] = self._get_comm_data(trcode, rqname, 0, '추정유지증거금총액')
        self.opw20014_output['single']['추정유지증거금현금'] = self._get_comm_data(trcode, rqname, 0, '추정유지증거금현금')
        self.opw20014_output['single']['추정추가증거금총액'] = self._get_comm_data(trcode, rqname, 0, '추정추가증거금총액')
        self.opw20014_output['single']['추정추가증거금현금'] = self._get_comm_data(trcode, rqname, 0, '추정추가증거금현금')
        self.opw20014_output['single']['선물당일차금'] = self._get_comm_data(trcode, rqname, 0, '선물당일차금')
        self.opw20014_output['single']['옵션결제대금'] = self._get_comm_data(trcode, rqname, 0, '옵션결제대금')
        self.opw20014_output['single']['인수도대금'] = self._get_comm_data(trcode, rqname, 0, '인수도대금')
        self.opw20014_output['single']['수수료'] = self._get_comm_data(trcode, rqname, 0, '수수료')
        self.opw20014_output['single']['선물갱신차금'] = self._get_comm_data(trcode, rqname, 0, '선물갱신차금')
        self.opw20014_output['single']['선물최종차금'] = self._get_comm_data(trcode, rqname, 0, '선물최종차금')
        self.opw20014_output['single']['옵션행사배정대금'] = self._get_comm_data(trcode, rqname, 0, '옵션행사배정대금')
        self.opw20014_output['single']['유지증거금기준부족액'] = self._get_comm_data(trcode, rqname, 0, '유지증거금기준부족액')
        self.opw20014_output['single']['위탁증거금기준부족액'] = self._get_comm_data(trcode, rqname, 0, '위탁증거금기준부족액')
        self.opw20014_output['single']['사후증거금계좌구분'] = self._get_comm_data(trcode, rqname, 0, '사후증거금계좌구분')
        self.opw20014_output['single']['결제가격수신여부'] = self._get_comm_data(trcode, rqname, 0, '결제가격수신여부')
        self.opw20014_output['single']['장종료예탁총액'] = self._get_comm_data(trcode, rqname, 0, '장종료예탁총액')
        self.opw20014_output['single']['장종료예탁현금'] = self._get_comm_data(trcode, rqname, 0, '장종료예탁현금')
        self.opw20014_output['single']['장종료예탁대용금'] = self._get_comm_data(trcode, rqname, 0, '장종료예탁대용금')
        self.opw20014_output['single']['조회건수'] = self._get_comm_data(trcode, rqname, 0, '조회건수')

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['종목코드'] = self._get_comm_data(trcode, rqname, i, '종목코드')
            temp['매도매수구분'] = self._get_comm_data(trcode, rqname, i, '매도매수구분')
            temp['미결제수량'] = self._get_comm_data(trcode, rqname, i, '미결제수량')
            temp['현재가'] = self._get_comm_data(trcode, rqname, i, '현재가')
            temp['내재변동성'] = self._get_comm_data(trcode, rqname, i, '내재변동성')
            temp['이론지수'] = self._get_comm_data(trcode, rqname, i, '이론지수')
            temp['잔존일수'] = self._get_comm_data(trcode, rqname, i, '잔존일수')
            self.opw20014_output['multi'].append(temp)

    def _opw20015(self, rqname, trcode):
        """
    	옵션매도주문증거금현황요청
    	"""
        self.opw20015_output = {'single': dict(), 'multi': []}

        self.opw20015_output['single']['종목코드'] = self._get_comm_data(trcode, rqname, 0, '종목코드')
        self.opw20015_output['single']['ATM행사가격'] = self._get_comm_data(trcode, rqname, 0, 'ATM행사가격')
        self.opw20015_output['single']['위치'] = self._get_comm_data(trcode, rqname, 0, '위치')
        self.opw20015_output['single']['조회건수'] = self._get_comm_data(trcode, rqname, 0, '조회건수')

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['콜조정이론가'] = self._get_comm_data(trcode, rqname, i, '콜조정이론가')
            temp['콜최대이론가'] = self._get_comm_data(trcode, rqname, i, '콜최대이론가')
            temp['콜전일종가'] = self._get_comm_data(trcode, rqname, i, '콜전일종가')
            temp['콜주문증거금'] = self._get_comm_data(trcode, rqname, i, '콜주문증거금')
            temp['행사가격'] = self._get_comm_data(trcode, rqname, i, '행사가격')
            temp['풋주문증거금'] = self._get_comm_data(trcode, rqname, i, '풋주문증거금')
            temp['풋전일종가'] = self._get_comm_data(trcode, rqname, i, '풋전일종가')
            temp['풋최대이론가'] = self._get_comm_data(trcode, rqname, i, '풋최대이론가')
            temp['풋조정이론가'] = self._get_comm_data(trcode, rqname, i, '풋조정이론가')
            self.opw20015_output['multi'].append(temp)

    def _opw20016(self, rqname, trcode):
        """
    	신용융자 가능종목요청
    	"""
        self.opw20016_output = {'single': dict(), 'multi': []}

        self.opw20016_output['single']['신용융자가능여부'] = self._get_comm_data(trcode, rqname, 0, '신용융자가능여부')
        self.opw20016_output['single']['출력건수'] = self._get_comm_data(trcode, rqname, 0, '출력건수')

        rows = self._get_repeat_cnt(trcode, rqname)
        for i in range(rows):
            temp = dict()
            temp['종목코드'] = self._get_comm_data(trcode, rqname, i, '종목코드')
            temp['종목명      '] = self._get_comm_data(trcode, rqname, i, '종목명      ')
            temp['신용보즘금율'] = self._get_comm_data(trcode, rqname, i, '신용보즘금율')
            temp['대용가'] = self._get_comm_data(trcode, rqname, i, '대용가')
            temp['전일종가'] = self._get_comm_data(trcode, rqname, i, '전일종가')
            temp['신용한도초과여부'] = self._get_comm_data(trcode, rqname, i, '신용한도초과여부')
            temp['신용한도초과'] = self._get_comm_data(trcode, rqname, i, '신용한도초과')
            self.opw20016_output['multi'].append(temp)

    def _opw20017(self, rqname, trcode):
        """
    	신용융자 가능문의
    	"""
        self.opw20017_output = {'single': dict()}

        self.opw20017_output['single']['신용가능여부'] = self._get_comm_data(trcode, rqname, 0, '신용가능여부')


