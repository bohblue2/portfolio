// ps_stock_futures.h
// �����ֽļ���

#pragma once
// �ּ��� \n�� ���� ���߿� �̻ڰ� �ٲ����

#include "cb_stock_futures_tr.h"
#include "df_stock_futures_tr.h"


int ParseA3015(const double& timestamp, const char* in_buff, DF_STOCK_FUT_EXEC* out);	// �ֽļ���_ü��
int ParseB6015(const double& timestamp, const char* in_buff, DF_STOCK_FUT_LIMIT_ORD* out);	// �ֽļ���_�켱ȣ��
int ParseG7015(const double& timestamp, const char* in_buff, DF_STOCK_FUT_EXEC_LIMIT_ORD* out);	// �ֽļ���_ü��_�켱ȣ��
int ParseA6015(const double& timestamp, const char* in_buff, DF_STOCK_FUT_CLOSE_PRODUCT* out);	// �ֽļ���_���񸶰�
int ParseA7015(const double& timestamp, const char* in_buff, DF_STOCK_FUTURE_MRK_OP_TS* out);	// �ֽļ���_��TS
int ParseH0015(const double& timestamp, const char* in_buff, DF_STOCK_FUTURE_CLOSE* out);	// �ֽļ���_����
int ParseM4015(const double& timestamp, const char* in_buff, DF_STOCK_FUT_MRK_OP_SCHD* out);	// �ֽļ���_�������ٰ���
int ParseO6015(const double& timestamp, const char* in_buff, DF_STOCK_FUT_DIST_INFO* out);	// �ֽļ���_�������
int ParseQ2015(const double& timestamp, const char* in_buff, DF_STOCK_FUT_REAL_HIGH_LOW_LIMIT_ON_OFF* out);	// �ֽļ���_�ǽð������Ѱ� ���������
int ParseV1015(const double& timestamp, const char* in_buff, DF_STOCK_FUT_PRC_LIMIT_ON* out);	// �ֽļ���_����������Ȯ��ߵ�
int ParseH2015(const double& timestamp, const char* in_buff, DF_STOCK_FUT_OPEN_INTEREST_DATA* out);	// �ֽļ���_�̰����������� ������
int ParseH3015(const double& timestamp, const char* in_buff, DF_STOCK_FUT_SETT_PRC_DATA* out);	// �ֽļ���_���갡�� ������
int ParseB2015(const double& timestamp, const char* in_buff, DF_STOCK_FUT_RECOVERY_DATA* out);	// �ֽļ���_�����ü�Recovery ������
int ParseH1015(const double& timestamp, const char* in_buff, DF_STOCK_FUT_INVESTOR_DATA* out);	// �ֽļ���_������ ������
int ParseC4015(const double& timestamp, const char* in_buff, DF_STOCK_FUT_COMP_BLOCK* out);	// �ֽļ���_����+�����ջ�
int ParseA0015(const double& timestamp, const char* in_buff, DF_STOCK_FUT_PRD_INFO_DATA* out);	// �ֽļ���_�������� ������
int ParseH4015(const double& timestamp, const char* in_buff, DF_STOCK_FUT_ADJ_INFO_DATA* out);	// �ֽļ���_�������� ������
int ParseI2015(const double& timestamp, const char* in_buff, DF_STOCK_FUT_POLLING_DATA* out);	// �ֽļ���_Polling ������
int ParseG9015(const double& timestamp, const char* in_buff, DF_STOCK_FUT_SPACE* out);	// �ֽļ���_SPACE
