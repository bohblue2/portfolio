// ps_kp200_option.h
// KOSPI200 �����ɼ�

#pragma once
// �ּ��� \n�� ���� ���߿� �̻ڰ� �ٲ����

#include "cb_kp200_option_tr.h"
#include "df_kp200_option_tr.h"


int ParseC4034(const double& timestamp, const char* in_buff, DF_K200_OPT_COMP_BLOCK* out);	// K200�ɼ�_����+�����ջ�
int ParseA3034(const double& timestamp, const char* in_buff, DF_K200_OPT_EXEC* out);	// K200�ɼ�_ü��
int ParseB6034(const double& timestamp, const char* in_buff, DF_K200_OPT_LIMIT_ORD* out);	// K200�ɼ�_�켱ȣ��
int ParseG7034(const double& timestamp, const char* in_buff, DF_K200_OPT_EXEC_LIMIT_ORD* out);	// K200�ɼ�_ü��_�켱ȣ��
int ParseA6034(const double& timestamp, const char* in_buff, DF_K200_OPT_CLOSE_PRODUCT* out);	// K200�ɼ�_���񸶰�
int ParseA7034(const double& timestamp, const char* in_buff, DF_K200_OPT_MRK_OP_TS* out);	// K200�ɼ�_��TS
int ParseH0034(const double& timestamp, const char* in_buff, DF_K200_OPT_CLOSE* out);	// K200�ɼ�_����
int ParseM4034(const double& timestamp, const char* in_buff, DF_K200_OPT_MRK_OP_SCHD* out);	// K200�ɼ�_�������ٰ���
int ParseO6034(const double& timestamp, const char* in_buff, DF_K200_OPT_DIST_INFO* out);	// K200�ɼ�_�������
int ParseQ2034(const double& timestamp, const char* in_buff, DF_K200_OPT_REAL_HIGH_LOW_LIMIT_ON_OFF* out);	// K200�ɼ�_�ǽð������Ѱ� ���������
int ParseV1034(const double& timestamp, const char* in_buff, DF_K200_OPT_PRC_LIMIT_ON* out);	// K200�ɼ�_����������Ȯ��ߵ�
int ParseG9034(const double& timestamp, const char* in_buff, DF_K200_OPT_SPACE* out);	// K200�ɼ�_SPACE
int ParseH2034(const double& timestamp, const char* in_buff, DF_K200_OPT_OPEN_INTEREST_DATA* out);	// K200�ɼ�_�̰����������� ������
int ParseH3034(const double& timestamp, const char* in_buff, DF_K200_OPT_TRD_MRG_STD_PRC_DATA* out);	// K200�ɼ�_�Ÿ����űݱ��ذ� ������
int ParseA0034(const double& timestamp, const char* in_buff, DF_K200_OPT_PRD_INFO_DATA* out);	// K200�ɼ�_�������� ������
int ParseN7034(const double& timestamp, const char* in_buff, DF_K200_OPT_SENSITIVITY_DATA* out);	// K200�ɼ�_�ΰ���
int ParseP1034(const double& timestamp, const char* in_buff, DF_K200_OPT_IMPLIED_VOL_DATA* out);	// KOSPI200�ɼ� ���纯����
int ParseH1034(const double& timestamp, const char* in_buff, DF_K200_OPT_INVESTOR_DATA* out);	// K200�ɼ�_������ ������
int ParseB2034(const double& timestamp, const char* in_buff, DF_K200_OPT_RECOVERY_DATA* out);	// K200�ɼ�_�ü�Recovery ������
int ParseI2034(const double& timestamp, const char* in_buff, DF_K200_OPT_POLLING_DATA* out);	// K200�ɼ�_Polling ������
int ParseM7034(const double& timestamp, const char* in_buff, DF_K200_OPT_BLOCK_TRD_BEF_MRK_OPEN* out);	// K200�ɼ�_�尳�������ǰŷ�
