// ps_kosdaq.h
// �ڽ����ֽ�

#pragma once
// �ּ��� \n�� ���� ���߿� �̻ڰ� �ٲ����

#include "ps_stock_common.h"
#include "cb_kosdaq_tr.h"
#include "df_kosdaq_tr.h"


int ParseAZ012(const double& timestamp, const char* in_buff, DF_KOSDAQ_TR_EXP_IDX* out);	// �ڽ��� TR��������
int ParseAY012(const double& timestamp, const char* in_buff, DF_KOSDAQ_TR_IDX* out);	// �ڽ��� TR����
int ParseA3012(const double& timestamp, const char* in_buff, DF_KOSDAQ_CCLS* out);	// �ڽ���_ü��
int ParseA4012(const double& timestamp, const char* in_buff, DF_KOSDAQ_BASE_PRC_DCS* out);	// �ڽ���_���ذ�����
int ParseA6012(const double& timestamp, const char* in_buff, DF_KOSDAQ_STK_CLSG* out);	// �ڽ���_���񸶰�
int ParseA7012(const double& timestamp, const char* in_buff, DF_KOSDAQ_MKT_OPR_TS* out);	// �ڽ���_��TS
int ParseO6012(const double& timestamp, const char* in_buff, DF_KOSDAQ_ALLC_INFO* out);	// �ڽ���_�������
int ParseA0012(const double& timestamp, const char* in_buff, DF_KOSDAQ_STK_ARNG* out);	// �ڽ���_�����ġ
int ParseI5012(const double& timestamp, const char* in_buff, DF_KOSDAQ_STGD_INFO* out);	// �ڽ���_����� ����
int ParseI6012(const double& timestamp, const char* in_buff, DF_KOSDAQ_STK_EVT_INFO* out);	// �ڽ���_���� �̺�Ʈ ����
int ParseI7012(const double& timestamp, const char* in_buff, DF_KOSDAQ_LP_INFO* out);	// �ڽ���_LP ����
int ParseC4012(const double& timestamp, const char* in_buff, DF_KOSDAQ_MSV_CCLS* out);	// �ڽ���_�뷮ü��
int ParseA8012(const double& timestamp, const char* in_buff, DF_KOSDAQ_STK_INFO_DCLS* out);	// �ڽ���_�ֽ�������������
int ParseR3012(const double& timestamp, const char* in_buff, DF_KOSDAQ_MBR_SCT_CNCL_DCLS* out);	// �ڽ���_ȸ��������������
int ParseM4012(const double& timestamp, const char* in_buff, DF_KOSDAQ_MKT_OPR_DCLS* out);	// �ڽ���_�������ٰ���
int ParseA9012(const double& timestamp, const char* in_buff, DF_KOSDAQ_TRS_STK_ARNG_INFO* out);	// �ڽ���_�ڻ��� ��ġ����
int ParseB0012(const double& timestamp, const char* in_buff, DF_KOSDAQ_TRS_STK_TRD_INFO* out);	// �ڽ���_�ڻ��� �Ÿ�����
int ParseB2012(const double& timestamp, const char* in_buff, DF_KOSDAQ_MKT_PRC_RCVR* out);	// �ڽ���_�ü�RECOVERY
int ParseB3012(const double& timestamp, const char* in_buff, DF_KOSDAQ_OFH_RCVR_FINAL* out);	// �ڽ���_�ð��ܴ��ϰ�_��Ŀ����_����
int ParseB4012(const double& timestamp, const char* in_buff, DF_KOSDAQ_OFH_RCVR* out);	// �ڽ���_�ð��ܴ��ϰ�_��Ŀ����
int ParseB5012(const double& timestamp, const char* in_buff, DF_KOSDAQ_CUR_FLCT* out);	// �ڽ���_������
int ParseO4012(const double& timestamp, const char* in_buff, DF_KOSDAQ_BIN_EXCQ* out);	// �ڽ���_Buy-in_�������
int ParseP2012(const double& timestamp, const char* in_buff, DF_KOSDAQ_BYIND_DYR* out);	// �ڽ��� ������ �����ͷ�
int ParseB8012(const double& timestamp, const char* in_buff, DF_KOSDAQ_BOPEN_ASK_RSD* out);	// �ڽ���_�尳����_ȣ���ܷ�
int ParseB6012(const double& timestamp, const char* in_buff, DF_KOSDAQ_ASK_RSD_WOLP* out);	// �ڽ���_ȣ���ܷ�_LPȣ��_����
int ParseI8012(const double& timestamp, const char* in_buff, DF_KOSDAQ_SHORT* out);	// �ڽ���_���ŵ�
int ParseB1012(const double& timestamp, const char* in_buff, DF_KOSDAQ_MKT_PRC_CLS* out);	// �ڽ���_�ü�����
int ParseC0012(const double& timestamp, const char* in_buff, DF_KOSDAQ_BYIND_BYINV* out);	// �ڽ���_�����������ں�
int ParseA0013(const double& timestamp, const char* in_buff, DF_KOTC_STK_ARNG* out);	// K-OTC �����ġ
int ParseA2013(const double& timestamp, const char* in_buff, DF_KOTC_ASK_PRC* out);	// K-OTC ȣ��
int ParseA3013(const double& timestamp, const char* in_buff, DF_KOTC_CCLS* out);	// K-OTC ü��
int ParseA6013(const double& timestamp, const char* in_buff, DF_KOTC_STK_CLSG* out);	// K-OTC ���񸶰�
int ParseA7013(const double& timestamp, const char* in_buff, DF_KOTC_MKT_OPR* out);	// K-OTC ��
int ParseG5013(const double& timestamp, const char* in_buff, DF_KOTC_MKT_ACT* out);	// K-OTC ������ġ
int ParseE9013_F0013(const double& timestamp, const char* in_buff, DF_KOTC_DCLS_ARNG_RT* out);	// K-OTC ���� ��ġ/�ǽð�
int ParseE4012(const double& timestamp, const char* in_buff, DF_KOSDAQ_IDX* out);	// KOSDAQ����
int ParseE5012(const double& timestamp, const char* in_buff, DF_KOSDAQ_EXP_IDX* out);	// KOSDAQ��������
int ParseB9012(const double& timestamp, const char* in_buff, DF_KOSDAQ_TRS* out);	// �ڽ���_�ŷ���
int ParseC1012(const double& timestamp, const char* in_buff, DF_KOSDAQ_BYSTK_BYINV_CLS* out);	// �ڽ���_���������ں� ����
int ParseC3012(const double& timestamp, const char* in_buff, DF_KOSDAQ_PRGTRD_ASK* out);	// �ڽ���_���α׷��Ÿ� ȣ��
int ParseJ0012(const double& timestamp, const char* in_buff, DF_KOSDAQ_PRGTRD_TOT* out);	// �ڽ���_���α׷��Ÿ� ��ü����
int ParseC5012(const double& timestamp, const char* in_buff, DF_KOSDAQ_PRGTRD_DCLS* out);	// �ڽ���_���α׷��Ÿ� �������İ���
int ParseP0012(const double& timestamp, const char* in_buff, DF_KOSDAQ_PRGTRD_BYINV_STAT* out);	// �ڽ��� ���α׷��Ÿ� �����ں� �Ÿ���Ȳ
int ParseR8012(const double& timestamp, const char* in_buff, DF_KOSDAQ_STK_STAT_INFO* out);	// �ڽ���_�����������(VI)
