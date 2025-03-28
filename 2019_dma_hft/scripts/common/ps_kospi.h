// ps_kospi.h
// ���������ֽ�

#pragma once
// �ּ��� \n�� ���� ���߿� �̻ڰ� �ٲ����

#include "ps_stock_common.h"
#include "cb_kospi_tr.h"
#include "df_kospi_tr.h"


int ParseBD011(const double& timestamp, const char* in_buff, DF_KRX300_TR_EXP_IDX* out);	// KRX 300 TR��������
int ParseBC011(const double& timestamp, const char* in_buff, DF_KRX300_TR_IDX* out);	// KRX 300 TR����
int ParseAX011(const double& timestamp, const char* in_buff, DF_KOSPI_TR_EXP_IDX* out);	// �ڽ��� TR��������
int ParseAW011(const double& timestamp, const char* in_buff, DF_KOSPI_TR_IDX* out);	// �ڽ��� TR����
int ParseAB011(const double& timestamp, const char* in_buff, DF_KRX300_EXP_IDX* out);	// KRX300��������
int ParseAA011(const double& timestamp, const char* in_buff, DF_KRX300_IDX* out);	// KRX300����
int ParseI6011(const double& timestamp, const char* in_buff, DF_KOSPI_STK_EVT_INFO* out);	// �ڽ���_���� �̺�Ʈ ����
int ParseA0011(const double& timestamp, const char* in_buff, DF_KOSPI_STK_ARNG* out);	// �ڽ���_�����ġ
int ParseX8011(const double& timestamp, const char* in_buff, DF_ETN_PRF_STR* out);	// ETN ���ͱ��� ����
int ParseX4011(const double& timestamp, const char* in_buff, DF_ETN_DSPR* out);	// ETN������
int ParseX3011(const double& timestamp, const char* in_buff, DF_ETN_ELY_RDMP_COND* out);	// ETN �����ȯ ����
int ParseV6011(const double& timestamp, const char* in_buff, DF_ETP_IDX_COMP* out);	// ETP��������
int ParseA4011(const double& timestamp, const char* in_buff, DF_KOSPI_BASE_PRC_DCS* out);	// �ڽ���_���ذ�����
int ParseA6011(const double& timestamp, const char* in_buff, DF_KOSPI_STK_CLSG* out);	// �ڽ���_���񸶰�
int ParseA7011(const double& timestamp, const char* in_buff, DF_KOSPI_MKT_OPR_TS* out);	// �ڽ���_��TS
int ParseA3011(const double& timestamp, const char* in_buff, DF_KOSPI_CCLS* out);	// �ڽ���_ü��
int ParseC4011(const double& timestamp, const char* in_buff, DF_KOSPI_MSV_CCLS* out);	// �ڽ���_�뷮ü��
int ParseO6011(const double& timestamp, const char* in_buff, DF_KOSPI_ALLC_INFO* out);	// �ڽ���_�������
int ParseA3021(const double& timestamp, const char* in_buff, DF_ELW_CCLS* out);	// ELW_ü��
int ParseA6021(const double& timestamp, const char* in_buff, DF_ELW_STK_CLSG* out);	// ELW_���񸶰�
int ParseA7021(const double& timestamp, const char* in_buff, DF_ELW_MKT_OPR_TS* out);	// ELW_��TS
int ParseA8011(const double& timestamp, const char* in_buff, DF_KOSPI_STK_INFO_DCLS* out);	// �ڽ���_�ֽ�������������
int ParseM4011(const double& timestamp, const char* in_buff, DF_KOSPI_MKT_OPR_DCLS* out);	// �ڽ���_�������ٰ���
int ParseI5011(const double& timestamp, const char* in_buff, DF_KOSPI_STGD_INFO* out);	// �ڽ���_����� ����
int ParseI7011(const double& timestamp, const char* in_buff, DF_KOSPI_LP_INFO* out);	// �ڽ���_LP ����
int ParseB5011(const double& timestamp, const char* in_buff, DF_KOSPI_CUR_FLCT* out);	// �ڽ���_������
int ParseB4011(const double& timestamp, const char* in_buff, DF_KOSPI_OFH_RCVR* out);	// �ڽ���_�ð��ܴ��ϰ�_��Ŀ����
int ParseB3011(const double& timestamp, const char* in_buff, DF_KOSPI_OFH_RCVR_FINAL* out);	// �ڽ���_�ð��ܴ��ϰ�_��Ŀ����_����
int ParseB6011(const double& timestamp, const char* in_buff, DF_KOSPI_ASK_RSD_WOLP* out);	// �ڽ���_ȣ���ܷ�_LPȣ��_����
int ParseB7011(const double& timestamp, const char* in_buff, DF_KOSPI_ASK_RSD_WLP* out);	// �ڽ���_ȣ���ܷ�_LPȣ��_����
int ParseB8011(const double& timestamp, const char* in_buff, DF_KOSPI_BOPEN_ASK_RSD* out);	// �ڽ���_�尳����_ȣ���ܷ�
int ParseC0011(const double& timestamp, const char* in_buff, DF_KOSPI_BYIND_BYINV* out);	// �ڽ���_�����������ں�
int ParseC3011(const double& timestamp, const char* in_buff, DF_KOSPI_PRGTRD_ASK* out);	// �ڽ���_���α׷��Ÿ� ȣ��
int ParseJ0011(const double& timestamp, const char* in_buff, DF_KOSPI_PRGTRD_TOT* out);	// �ڽ���_���α׷��Ÿ� ��ü����
int ParseC5011(const double& timestamp, const char* in_buff, DF_KOSPI_PRGTRD_DCLS* out);	// �ڽ���_���α׷��Ÿ� ��������
int ParseP0011(const double& timestamp, const char* in_buff, DF_PRGTRD_BYINV_STAT* out);	// ���� ���α׷��Ÿ� �����ں� �Ÿ���Ȳ
int ParseI8011(const double& timestamp, const char* in_buff, DF_KOSPI_SHORT* out);	// �ڽ���_���ŵ�
int ParseO4011(const double& timestamp, const char* in_buff, DF_KOSPI_BIN_EXCQ* out);	// �ڽ���_Buy-in_�������
int ParseO4012(const double& timestamp, const char* in_buff, DF_KOSDQ_BIN_EXCQ* out);	// �ڽ���_Buy-in_�������
int ParseO4018(const double& timestamp, const char* in_buff, DF_KONEX_BIN_EXCQ* out);	// �ڳؽ�_Buy-in_�������
int ParseB1011(const double& timestamp, const char* in_buff, DF_KOSPI_MKT_PRC_CLS* out);	// �ڽ���_�ü�����
int ParseB2011(const double& timestamp, const char* in_buff, DF_KOSPI_MKT_PRC_RCVR* out);	// �ڽ���_�ü�RECOVERY
int ParseF1011(const double& timestamp, const char* in_buff, DF_KOSPI_FRGN_INV_INFO* out);	// �ڽ��� �ܱ��� ������������_Ȯ��ġ
int ParseF2011(const double& timestamp, const char* in_buff, DF_KOSPI_FRGN_ORDL_QTY* out);	// �ڽ��� �ܱ��� �ֹ����ɼ���
int ParseF3011(const double& timestamp, const char* in_buff, DF_KOSPI_FRGN_RSVD_ORD_CNCL* out);	// �ڽ��� �ܱ��� �����ֹ�����_����
int ParseF4011(const double& timestamp, const char* in_buff, DF_KOSPI_FRGN_CFRM_DATA* out);	// �ڽ��� �ܱ��� Ȯ��ġ������������
int ParseF5011(const double& timestamp, const char* in_buff, DF_KOSPI_FRGN_LMT_XHS* out);	// �ڽ��� �ܱ��� �ѵ�������ܸŸ�
int ParseF6011(const double& timestamp, const char* in_buff, DF_KOSPI_FRGN_TRD_STAT* out);	// �ڽ��� �ܱ��� �Ÿ�_������Ȳ
int ParseF5012(const double& timestamp, const char* in_buff, DF_KOSDAQ_FRGN_LMT_XHS* out);	// �ڽ��� �ܱ��� �ѵ�������ܸŸ�
int ParseF6012(const double& timestamp, const char* in_buff, DF_KOSDAQ_FRGN_TRD_STAT* out);	// �ڽ��� �ܱ��� �Ÿ�_������Ȳ
int ParseF3012(const double& timestamp, const char* in_buff, DF_KOSDAQ_FRGN_RSVD_ORD_CNCL* out);	// �ڽ��� �ܱ��� �����ֹ�����_����
int ParseF1012(const double& timestamp, const char* in_buff, DF_KOSDAQ_FRGN_INV_INFO* out);	// �ڽ��� �ܱ��� ������������_Ȯ��ġ
int ParseF2012(const double& timestamp, const char* in_buff, DF_KOSDAQ_FRGN_ORDL_QTY* out);	// �ڽ��� �ܱ��� �ֹ����ɼ���
int ParseF4012(const double& timestamp, const char* in_buff, DF_KOSDAQ_FRGN_CFRM_DATA* out);	// �ڽ��� �ܱ��� Ȯ��ġ������������
int ParseF1018(const double& timestamp, const char* in_buff, DF_KONEX_FRGN_INV_INFO* out);	// �ڳؽ� �ܱ��� ������������_Ȯ��ġ
int ParseF2018(const double& timestamp, const char* in_buff, DF_KONEX_FRGN_ORDL_QTY* out);	// �ڳؽ� �ܱ��� �ֹ����ɼ���
int ParseF3018(const double& timestamp, const char* in_buff, DF_KONEX_FRGN_RSVD_ORD_CNCL* out);	// �ڳؽ� �ܱ��� �����ֹ�����_����
int ParseF4018(const double& timestamp, const char* in_buff, DF_KONEX_FRGN_CFRM_DATA* out);	// �ڳؽ� �ܱ��� Ȯ��ġ������������
int ParseF5018(const double& timestamp, const char* in_buff, DF_KONEX_FRGN_LMT_XHS* out);	// �ڳؽ� �ܱ��� �ѵ�������ܸŸ�
int ParseF6018(const double& timestamp, const char* in_buff, DF_KONEX_FRGN_TRD_STAT* out);	// �ڳؽ� �ܱ��� �Ÿ�_������Ȳ
int ParseP2011(const double& timestamp, const char* in_buff, DF_KOSPI_BYIND_DYR* out);	// ���� ������ �����ͷ�
int ParseA1011(const double& timestamp, const char* in_buff, DF_ELW_STK_ARNG* out);	// ELW �����ġ
int ParseM6011(const double& timestamp, const char* in_buff, DF_ELY_CLS_ELW_STK_ARNG* out);	// ��������ELW_�����ġ
int ParseM5011(const double& timestamp, const char* in_buff, DF_ELY_CLS_ELW_ASSET_HLP* out);	// ��������ELW �򰡱Ⱓ �� �����ڻ������
int ParseB2021(const double& timestamp, const char* in_buff, DF_ELW_MKT_PRC_RCVR* out);	// ELW_�ü�RECOVERY
int ParseC6021(const double& timestamp, const char* in_buff, DF_ELW_INV_IDX* out);	// ELW ������ǥ
int ParseN3021(const double& timestamp, const char* in_buff, DF_ELW_LP_ASK_VOL* out);	// ELW LPȣ�� ���纯����
int ParseB1021(const double& timestamp, const char* in_buff, DF_ELW_MKT_PRC_CLS* out);	// ELW_�ü�����
int ParseC0021(const double& timestamp, const char* in_buff, DF_ELW_BYINV* out);	// ELW_�����ں�
int ParseB7021(const double& timestamp, const char* in_buff, DF_ELW_ASK_RSD_WLP* out);	// ELW_ȣ���ܷ�_LPȣ��_����
int ParseN8011(const double& timestamp, const char* in_buff, DF_ETF_TRA_INFO* out);	// ETF�繫��Ź��ġ
int ParseF8011(const double& timestamp, const char* in_buff, DF_ETF_PDF* out);	// ETF PDF
int ParseM8011(const double& timestamp, const char* in_buff, DF_ETF_OPR_INFO* out);	// ETF�������
int ParseF7011(const double& timestamp, const char* in_buff, DF_ETF_NAV* out);	// ETF NAV
int ParseI3011(const double& timestamp, const char* in_buff, DF_ETF_EXP_NAV* out);	// ETF ����NAV
int ParseP6011(const double& timestamp, const char* in_buff, DF_ETF_TER* out);	// ETF ����������
int ParseC0031(const double& timestamp, const char* in_buff, DF_ETF_BYINV* out);	// ETF_�����ں�
int ParseM9011(const double& timestamp, const char* in_buff, DF_MBR_INFO* out);	// ȸ��������
int ParseD0011(const double& timestamp, const char* in_buff, DF_KOSPI_IDX* out);	// KOSPI����
int ParseD1011(const double& timestamp, const char* in_buff, DF_KOSPI_EXP_IDX* out);	// KOSPI��������
int ParseD2011(const double& timestamp, const char* in_buff, DF_KOSPI_200_IDX* out);	// KOSPI200����
int ParseD3011(const double& timestamp, const char* in_buff, DF_KOSPI_200_EXP_IDX* out);	// KOSPI200��������
int ParseD4011(const double& timestamp, const char* in_buff, DF_KOSPI_100_50_IDX* out);	// KOSPI100/50����
int ParseN6011(const double& timestamp, const char* in_buff, DF_KOSPI_200_STR_EXP_IDX* out);	// KOSPI200 ���Ϳ�������
int ParseN5011(const double& timestamp, const char* in_buff, DF_KOSPI_200_STR_IDX* out);	// KOSPI200 ��������
int ParseC8011(const double& timestamp, const char* in_buff, DF_KOSPI_100_IDX* out);	// KRX100����
int ParseC9011(const double& timestamp, const char* in_buff, DF_KOSPI_100_EXP_IDX* out);	// KRX100��������
int ParseN9011(const double& timestamp, const char* in_buff, DF_EWIDX* out);	// ���ϰ�������
int ParseO1011(const double& timestamp, const char* in_buff, DF_EWEIDX* out);	// ���ϰ��߿�������
int ParseG1067(const double& timestamp, const char* in_buff, DF_MARKET_IDX_GROUP_EXP_CODE* out);	// �������� �׷�_�����ڵ�
int ParseP3011(const double& timestamp, const char* in_buff, DF_WISEFN_IDX* out);	// �������������
int ParseB9011(const double& timestamp, const char* in_buff, DF_KOSPI_TRS* out);	// �ڽ���_�ŷ���
int ParseB9021(const double& timestamp, const char* in_buff, DF_ELW_TRS* out);	// ELW_�ŷ���
int ParseC1011(const double& timestamp, const char* in_buff, DF_KOSPI_BYSTK_BYINV_CLS* out);	// �ڽ���_���������ں� ����
int ParseC1021(const double& timestamp, const char* in_buff, DF_ELW_BYSTK_BYINV_CLS* out);	// ELW_���������ں� ����
int ParseL5011(const double& timestamp, const char* in_buff, DF_FRIDX_ETF_NAV* out);	// �ؿ����� ETF NAV
int ParseP7011(const double& timestamp, const char* in_buff, DF_FRIDX_TER* out);	// �ؿ�ETF ����������
int ParseQ4011(const double& timestamp, const char* in_buff, DF_SETF_DAY_CPTY_RISK_INFO* out);	// �ռ�ETF ���� �ŷ����� �����򰡾� ����
int ParseE2011(const double& timestamp, const char* in_buff, DF_MKF_IDX* out);	// MKF����
int ParseO9011(const double& timestamp, const char* in_buff, DF_MKF_IDX_WYFX* out);	// MKF����(��ȯ���ݿ�)
int ParseM3011(const double& timestamp, const char* in_buff, DF_FRIDX_ETF_IDX* out);	// �ؿ�����ETF�������
int ParseO5019(const double& timestamp, const char* in_buff, DF_FRIDX* out);	// �ؿ�����
int ParseQ5011(const double& timestamp, const char* in_buff, DF_SETF_BASE_IDX_COMP_STK* out);	// �ռ�ETF �������� ��������
int ParseF1013(const double& timestamp, const char* in_buff, DF_FBRD_FRGN_INV_INFO* out);	// �������� �ܱ��� ������������_Ȯ��ġ
int ParseF2013(const double& timestamp, const char* in_buff, DF_FBRD_FRGN_ORDL_QTY* out);	// �������� �ܱ��� �ֹ����ɼ���
int ParseF3013(const double& timestamp, const char* in_buff, DF_FBRD_FRGN_RSVD_ORD_CNCL* out);	// �������� �ܱ��� �����ֹ�����_����
int ParseF4013(const double& timestamp, const char* in_buff, DF_FBRD_FRGN_CFRM_DATA* out);	// �������� �ܱ��� Ȯ��ġ������������
int ParseF5013(const double& timestamp, const char* in_buff, DF_FBRD_FRGN_LMT_XHS* out);	// �������� �ܱ��� �ѵ�������ܸŸ�
int ParseC7021(const double& timestamp, const char* in_buff, DF_ELW_INV_IDX_SST* out);	// ELW ������ǥ�ΰ���
int ParseA9011(const double& timestamp, const char* in_buff, DF_KOSPI_TRS_STK_ARNG_INFO* out);	// �ڽ���_�ڻ��� ��ġ����
int ParseB0011(const double& timestamp, const char* in_buff, DF_KOSPI_TRS_STK_TRD_INFO* out);	// �ڽ���_�ڻ��� �Ÿ�����
int ParseK2011(const double& timestamp, const char* in_buff, DF_LVR_KOSPI200_IDX* out);	// �������� KOSPI200����
int ParseR3011(const double& timestamp, const char* in_buff, DF_KOSPI_MBR_SCT_CNCL_DCLS* out);	// �ڽ���_ȸ��������������
int ParseR8011(const double& timestamp, const char* in_buff, DF_KOSPI_STK_STAT_INFO* out);	// �ڽ���_�����������(VI)
int ParseS1011(const double& timestamp, const char* in_buff, DF_ETN_TRA_INFO* out);	// ETN �繫��Ź����
int ParseS2011(const double& timestamp, const char* in_buff, DF_ETN_BASE_IDX_COMP_STK* out);	// ETN �������� ��������
int ParseC0041(const double& timestamp, const char* in_buff, DF_ETN_BYINV* out);	// ETN_�����ں�
int ParseS3011(const double& timestamp, const char* in_buff, DF_ETN_IIV* out);	// ETN IIV
int ParseA1041(const double& timestamp, const char* in_buff, DF_ETN_STK_ARNG* out);	// ETN �����ġ
int ParseT7011(const double& timestamp, const char* in_buff, DF_KTOP30_IDX* out);	// KTOP30����
int ParseT8011(const double& timestamp, const char* in_buff, DF_KTOP30_EXP_IDX* out);	// KTOP30��������
