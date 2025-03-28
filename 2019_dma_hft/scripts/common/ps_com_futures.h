// ps_com_futures.h
// ��ǰ���� �ǽð�

#pragma once
// �ּ��� \n�� ���� ���߿� �̻ڰ� �ٲ����

#include "cb_com_futures_tr.h"
#include "df_com_futures_tr.h"


int ParseC4016(const double& timestamp, const char* in_buff, DF_COM_FUT_COMP_BLOCK* out);	// ��ǰ����_����+�����ջ�
int ParseA3016(const double& timestamp, const char* in_buff, DF_COM_FUT_EXEC* out);	// ��ǰ����_ü��
int ParseB6016(const double& timestamp, const char* in_buff, DF_COM_FUT_LIMIT_ORD* out);	// ��ǰ����_�켱ȣ��
int ParseG7016(const double& timestamp, const char* in_buff, DF_COM_FUT_EXEC_LIMIT_ORD* out);	// ��ǰ����_ü��_�켱ȣ��
int ParseA6016(const double& timestamp, const char* in_buff, DF_COM_FUT_CLOSE_PRODUCT* out);	// ��ǰ����_���񸶰�
int ParseA7016(const double& timestamp, const char* in_buff, DF_COM_FUT_MRK_OP_TS* out);	// ��ǰ����_��TS
int ParseH0016(const double& timestamp, const char* in_buff, DF_COM_FUT_CLOSE* out);	// ��ǰ����_����
int ParseM4016(const double& timestamp, const char* in_buff, DF_COM_FUT_MRK_OP_SCHD* out);	// ��ǰ����_�������ٰ���
int ParseO6016(const double& timestamp, const char* in_buff, DF_COM_FUT_DIST_INFO* out);	// ��ǰ����_�������
int ParseQ2016(const double& timestamp, const char* in_buff, DF_COM_FUT_REAL_HIGH_LOW_LIMIT_ON_OFF* out);	// ��ǰ����_�ǽð������Ѱ� ���������
int ParseH2016(const double& timestamp, const char* in_buff, DF_COM_FUT_OPEN_INTEREST_DATA* out);	// ��ǰ����_�̰����������� ������
int ParseH3016(const double& timestamp, const char* in_buff, DF_COM_FUT_SETT_PRC_DATA* out);	// ��ǰ����_���갡�� ������
int ParseH1016(const double& timestamp, const char* in_buff, DF_COM_FUT_INVESTOR_DATA* out);	// ��ǰ����_������ ������
int ParseB2016(const double& timestamp, const char* in_buff, DF_COM_FUT_RECOVERY_DATA* out);	// ��ǰ����_�ü�Recovery ������
int ParseA0016(const double& timestamp, const char* in_buff, DF_COM_FUTRE_PRD_INFO_DATA* out);	// ��ǰ����_�������� ������
int ParseH5016(const double& timestamp, const char* in_buff, DF_GOV_BOND_CD_DATA* out);	// ��������_��ä_CD_������
int ParseH6016(const double& timestamp, const char* in_buff, DF_STD_GOV_BOND_DATA* out);	// ��������_��������ä��_������
int ParseH9016(const double& timestamp, const char* in_buff, DF_USD_DATA* out);	// ��������_USD_������
int ParseI0016_FBB1(const double& timestamp, const char* in_buff, DF_USD_BATCH_DATA_1* out);	// ��������_USD��ġ_������1
int ParseI0016_FBC1(const double& timestamp, const char* in_buff, DF_USD_BATCH_DATA_2* out);	// ��������_USD��ġ_������2
int ParseI0016_FBC2(const double& timestamp, const char* in_buff, DF_USD_BATCH_DATA_3* out);	// ��������_USD��ġ_������3
int ParseI0016_FBD1(const double& timestamp, const char* in_buff, DF_USD_BATCH_DATA_4* out);	// ��������_USD��ġ_������4
int ParseI0016_FBE1(const double& timestamp, const char* in_buff, DF_USD_BATCH_DATA_5* out);	// ��������_USD��ġ_������5
int ParseI0016_FBF1(const double& timestamp, const char* in_buff, DF_USD_BATCH_DATA_6* out);	// ��������_USD��ġ_������6
int ParseI0016_FBF2(const double& timestamp, const char* in_buff, DF_USD_BATCH_DATA_7* out);	// ��������_USD��ġ_������7
int ParseI0016_FBG1(const double& timestamp, const char* in_buff, DF_USD_BATCH_DATA_8* out);	// ��������_USD��ġ_������8
int ParseI0016_CBA1(const double& timestamp, const char* in_buff, DF_USD_BATCH_DATA_9* out);	// ��������_USD��ġ_������9
int ParseI0016_CBA2(const double& timestamp, const char* in_buff, DF_USD_BATCH_DATA_10* out);	// ��������_USD��ġ_������10
int ParseI1016_FOC1(const double& timestamp, const char* in_buff, DF_USD_REAL_TIME_DATA_1* out);	// ��������_USD�ǽð�����_������1
int ParseI1016_FOD1(const double& timestamp, const char* in_buff, DF_USD_REAL_TIME_DATA_2* out);	// ��������_USD�ǽð�����_������2
int ParseI1016_FOE1(const double& timestamp, const char* in_buff, DF_USD_REAL_TIME_DATA_3* out);	// ��������_USD�ǽð�����_������3
int ParseI1016_HOE1(const double& timestamp, const char* in_buff, DF_CNH_REAL_TIME_DATA* out);	// ��������_CNH�ǽð�����_������
int ParseI1016_FOF1(const double& timestamp, const char* in_buff, DF_USD_REAL_TIME_DATA_4* out);	// ��������_USD�ǽð�����_������4
int ParseI1016_FOG1(const double& timestamp, const char* in_buff, DF_USD_REAL_TIME_DATA_5* out);	// ��������_USD�ǽð�����_������5
int ParseI1016_UOD1(const double& timestamp, const char* in_buff, DF_USD_REAL_TIME_DATA_8* out);	// ��������_USD�ǽð�����_������8
int ParseI1016_COA1(const double& timestamp, const char* in_buff, DF_USD_REAL_TIME_DATA_7* out);	// ��������_USD�ǽð�����_������7
int ParseI1016_FOQ1(const double& timestamp, const char* in_buff, DF_USD_REAL_TIME_DATA_6* out);	// ��������_USD�ǽð�����_������6
int ParseI2016(const double& timestamp, const char* in_buff, DF_COM_FUT_POLLING_DATA* out);	// ��ǰ����_Polling ������
int ParseI1016_UOE1(const double& timestamp, const char* in_buff, DF_USD_REAL_TIME_DATA_9* out);	// ��������_USD�ǽð�����_������9
int H8016_1000(const double& timestamp, const char* in_buff, DF_LEAN_HOG_REP_PRC_INDEX_DATA* out);	// ��������_������ǥ��������_������
int H8016_REAL(const double& timestamp, const char* in_buff, DF_LEAN_HOG_REAL_TIME_PRC_INDEX_DATA* out);	// ��������_�����ǽð���������_������
int H8016_1800(const double& timestamp, const char* in_buff, DF_LEAN_HOG_CLOSE_PRICE_INDEX_DATA* out);	// ��������_����������������_������
int ParseG9016(const double& timestamp, const char* in_buff, DF_COM_FUT_SPACE* out);	// ��ǰ����_SPACE
