// ps_stock_common.h
// �ֽ� ����

#pragma once
// �ּ��� \n�� ���� ���߿� �̻ڰ� �ٲ����

#include "cb_stock_common_tr.h"
#include "df_stock_common_tr.h"


int ParseI2000(const double& timestamp, const char* in_buff, DF_CUR_POLLING_DATA* out);	// ���� Polling data
int ParseF0011(const double& timestamp, const char* in_buff, DF_DCLS_RT_KOSPI_STK* out);	// ����(�ǽð�_�ڽ���_�ֽ�)
int ParseF0012(const double& timestamp, const char* in_buff, DF_DCLS_RT_KOSDAQ_STK* out);	// ����(�ǽð�_�ڽ���_�ֽ�)
int ParseF0018(const double& timestamp, const char* in_buff, DF_DCLS_RT_KONEX_STK* out);	// ����(�ǽð�_�ڳؽ�_�ֽ�)
int ParseE9011(const double& timestamp, const char* in_buff, DF_DCLS_ARNG_KOSPI_STK* out);	// ����(��ġ_�ڽ���_�ֽ�)
int ParseE9012(const double& timestamp, const char* in_buff, DF_DCLS_ARNG_KOSDAQ_STK* out);	// ����(��ġ_�ڽ���_�ֽ�)
int ParseE9018(const double& timestamp, const char* in_buff, DF_DCLS_ARNG_KONEX_STK* out);	// ����(��ġ_�ڳؽ�_�ֽ�)
int ParseE9909(const double& timestamp, const char* in_buff, DF_DCLS_ARNG_ETC* out);	// ����(��ġ_��Ÿ)
int ParseF0909(const double& timestamp, const char* in_buff, DF_DCLS_RT_ETC* out);	// ����(�ǽð�_��Ÿ)
