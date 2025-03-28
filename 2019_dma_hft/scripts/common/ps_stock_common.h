// ps_stock_common.h
// 주식 공통

#pragma once
// 주석에 \n이 들어간건 나중에 이쁘게 바꿔야함

#include "cb_stock_common_tr.h"
#include "df_stock_common_tr.h"


int ParseI2000(const double& timestamp, const char* in_buff, DF_CUR_POLLING_DATA* out);	// 현물 Polling data
int ParseF0011(const double& timestamp, const char* in_buff, DF_DCLS_RT_KOSPI_STK* out);	// 공시(실시간_코스피_주식)
int ParseF0012(const double& timestamp, const char* in_buff, DF_DCLS_RT_KOSDAQ_STK* out);	// 공시(실시간_코스닥_주식)
int ParseF0018(const double& timestamp, const char* in_buff, DF_DCLS_RT_KONEX_STK* out);	// 공시(실시간_코넥스_주식)
int ParseE9011(const double& timestamp, const char* in_buff, DF_DCLS_ARNG_KOSPI_STK* out);	// 공시(배치_코스피_주식)
int ParseE9012(const double& timestamp, const char* in_buff, DF_DCLS_ARNG_KOSDAQ_STK* out);	// 공시(배치_코스닥_주식)
int ParseE9018(const double& timestamp, const char* in_buff, DF_DCLS_ARNG_KONEX_STK* out);	// 공시(배치_코넥스_주식)
int ParseE9909(const double& timestamp, const char* in_buff, DF_DCLS_ARNG_ETC* out);	// 공시(배치_기타)
int ParseF0909(const double& timestamp, const char* in_buff, DF_DCLS_RT_ETC* out);	// 공시(실시간_기타)
