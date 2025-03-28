// ps_stock_futures.h
// 개별주식선물

#pragma once
// 주석에 \n이 들어간건 나중에 이쁘게 바꿔야함

#include "cb_stock_futures_tr.h"
#include "df_stock_futures_tr.h"


int ParseA3015(const double& timestamp, const char* in_buff, DF_STOCK_FUT_EXEC* out);	// 주식선물_체결
int ParseB6015(const double& timestamp, const char* in_buff, DF_STOCK_FUT_LIMIT_ORD* out);	// 주식선물_우선호가
int ParseG7015(const double& timestamp, const char* in_buff, DF_STOCK_FUT_EXEC_LIMIT_ORD* out);	// 주식선물_체결_우선호가
int ParseA6015(const double& timestamp, const char* in_buff, DF_STOCK_FUT_CLOSE_PRODUCT* out);	// 주식선물_종목마감
int ParseA7015(const double& timestamp, const char* in_buff, DF_STOCK_FUTURE_MRK_OP_TS* out);	// 주식선물_장운영TS
int ParseH0015(const double& timestamp, const char* in_buff, DF_STOCK_FUTURE_CLOSE* out);	// 주식선물_마감
int ParseM4015(const double& timestamp, const char* in_buff, DF_STOCK_FUT_MRK_OP_SCHD* out);	// 주식선물_장운영스케줄공개
int ParseO6015(const double& timestamp, const char* in_buff, DF_STOCK_FUT_DIST_INFO* out);	// 주식선물_배분정보
int ParseQ2015(const double& timestamp, const char* in_buff, DF_STOCK_FUT_REAL_HIGH_LOW_LIMIT_ON_OFF* out);	// 주식선물_실시간상하한가 적용및해제
int ParseV1015(const double& timestamp, const char* in_buff, DF_STOCK_FUT_PRC_LIMIT_ON* out);	// 주식선물_가격제한폭확대발동
int ParseH2015(const double& timestamp, const char* in_buff, DF_STOCK_FUT_OPEN_INTEREST_DATA* out);	// 주식선물_미결제약정수량 데이터
int ParseH3015(const double& timestamp, const char* in_buff, DF_STOCK_FUT_SETT_PRC_DATA* out);	// 주식선물_정산가격 데이터
int ParseB2015(const double& timestamp, const char* in_buff, DF_STOCK_FUT_RECOVERY_DATA* out);	// 주식선물_선물시세Recovery 데이터
int ParseH1015(const double& timestamp, const char* in_buff, DF_STOCK_FUT_INVESTOR_DATA* out);	// 주식선물_투자자 데이터
int ParseC4015(const double& timestamp, const char* in_buff, DF_STOCK_FUT_COMP_BLOCK* out);	// 주식선물_경쟁+협의합산
int ParseA0015(const double& timestamp, const char* in_buff, DF_STOCK_FUT_PRD_INFO_DATA* out);	// 주식선물_종목정보 데이터
int ParseH4015(const double& timestamp, const char* in_buff, DF_STOCK_FUT_ADJ_INFO_DATA* out);	// 주식선물_조정내역 데이터
int ParseI2015(const double& timestamp, const char* in_buff, DF_STOCK_FUT_POLLING_DATA* out);	// 주식선물_Polling 데이터
int ParseG9015(const double& timestamp, const char* in_buff, DF_STOCK_FUT_SPACE* out);	// 주식선물_SPACE
