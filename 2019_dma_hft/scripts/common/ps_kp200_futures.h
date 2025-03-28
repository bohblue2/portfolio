// ps_kp200_futures.h
// KOSPI200 ��������

#pragma once
// �ּ��� \n�� ���� ���߿� �̻ڰ� �ٲ����

#include "cb_kp200_futures_tr.h"
#include "df_kp200_futures_tr.h"


int ParseC4014(const double& timestamp, const char* in_buff, DF_K200_FUT_COMP_BLOCK* out);	// K200����_����+�����ջ�
int ParseA3014(const double& timestamp, const char* in_buff, DF_K200_FUT_EXEC* out);	// K200����_ü��
int ParseB6014(const double& timestamp, const char* in_buff, DF_K200_FUT_LIMIT_ORD* out);	// K200����_�켱ȣ��
int ParseG7014(const double& timestamp, const char* in_buff, DF_K200_FUT_EXEC_LIMIT_ORD* out);	// K200����_ü��_�켱ȣ��
int ParseA6014(const double& timestamp, const char* in_buff, DF_K200_FUT_CLOSE_PRODUCT* out);	// K200����_���񸶰�
int ParseA7014(const double& timestamp, const char* in_buff, DF_K200_FUT_MRK_OP_TS* out);	// K200����_��TS
int ParseH0014(const double& timestamp, const char* in_buff, DF_K200_FUT_CLOSE* out);	// K200����_����
int ParseM4014(const double& timestamp, const char* in_buff, DF_K200_FUT_MRK_OP_SCHD* out);	// K200����_�������ٰ���
int ParseO6014(const double& timestamp, const char* in_buff, DF_K200_FUT_DIST_INFO* out);	// K200����_�������
int ParseQ2014(const double& timestamp, const char* in_buff, DF_K200_FUT_REAL_HIGH_LOW_LIMIT_ON_OFF* out);	// K200����_�ǽð������Ѱ� ���������
int ParseV1014(const double& timestamp, const char* in_buff, DF_K200_FUT_PRC_LIMIT_ON* out);	// K200����_����������Ȯ��ߵ�
int ParseH2014(const double& timestamp, const char* in_buff, DF_K200_FUT_OPEN_INTEREST_DATA* out);	// K200����_�̰����������� ������
int ParseH3014(const double& timestamp, const char* in_buff, DF_K200_FUT_SETT_PRC_DATA* out);	// K200����_���갡�� ������
int ParseH1014(const double& timestamp, const char* in_buff, DF_K200_FUT_INVESTOR_DATA* out);	// K200����_������ ������
int ParseB2014(const double& timestamp, const char* in_buff, DF_K200_FUT_RECOVERY_DATA* out);	// K200����_�ü�Recovery ������
int ParseA0014(const double& timestamp, const char* in_buff, DF_K200_FUT_PRD_INFO_DATA* out);	// K200����_�������� ������
int ParseI2014(const double& timestamp, const char* in_buff, DF_K200_FUT_POLLING_DATA* out);	// K200����_Polling ������
int ParseG9014(const double& timestamp, const char* in_buff, DF_K200_FUT_SPACE* out);	// K200����_SPACE
