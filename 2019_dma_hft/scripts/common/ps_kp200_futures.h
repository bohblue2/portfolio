// ps_kp200_futures.h
// KOSPI200 지수선물

#pragma once
// 주석에 \n이 들어간건 나중에 이쁘게 바꿔야함

#include "cb_kp200_futures_tr.h"
#include "df_kp200_futures_tr.h"


int ParseC4014(const double& timestamp, const char* in_buff, DF_K200_FUT_COMP_BLOCK* out);	// K200선물_경쟁+협의합산
int ParseA3014(const double& timestamp, const char* in_buff, DF_K200_FUT_EXEC* out);	// K200선물_체결
int ParseB6014(const double& timestamp, const char* in_buff, DF_K200_FUT_LIMIT_ORD* out);	// K200선물_우선호가
int ParseG7014(const double& timestamp, const char* in_buff, DF_K200_FUT_EXEC_LIMIT_ORD* out);	// K200선물_체결_우선호가
int ParseA6014(const double& timestamp, const char* in_buff, DF_K200_FUT_CLOSE_PRODUCT* out);	// K200선물_종목마감
int ParseA7014(const double& timestamp, const char* in_buff, DF_K200_FUT_MRK_OP_TS* out);	// K200선물_장운영TS
int ParseH0014(const double& timestamp, const char* in_buff, DF_K200_FUT_CLOSE* out);	// K200선물_마감
int ParseM4014(const double& timestamp, const char* in_buff, DF_K200_FUT_MRK_OP_SCHD* out);	// K200선물_장운영스케줄공개
int ParseO6014(const double& timestamp, const char* in_buff, DF_K200_FUT_DIST_INFO* out);	// K200선물_배분정보
int ParseQ2014(const double& timestamp, const char* in_buff, DF_K200_FUT_REAL_HIGH_LOW_LIMIT_ON_OFF* out);	// K200선물_실시간상하한가 적용및해제
int ParseV1014(const double& timestamp, const char* in_buff, DF_K200_FUT_PRC_LIMIT_ON* out);	// K200선물_가격제한폭확대발동
int ParseH2014(const double& timestamp, const char* in_buff, DF_K200_FUT_OPEN_INTEREST_DATA* out);	// K200선물_미결제약정수량 데이터
int ParseH3014(const double& timestamp, const char* in_buff, DF_K200_FUT_SETT_PRC_DATA* out);	// K200선물_정산가격 데이터
int ParseH1014(const double& timestamp, const char* in_buff, DF_K200_FUT_INVESTOR_DATA* out);	// K200선물_투자자 데이터
int ParseB2014(const double& timestamp, const char* in_buff, DF_K200_FUT_RECOVERY_DATA* out);	// K200선물_시세Recovery 데이터
int ParseA0014(const double& timestamp, const char* in_buff, DF_K200_FUT_PRD_INFO_DATA* out);	// K200선물_종목정보 데이터
int ParseI2014(const double& timestamp, const char* in_buff, DF_K200_FUT_POLLING_DATA* out);	// K200선물_Polling 데이터
int ParseG9014(const double& timestamp, const char* in_buff, DF_K200_FUT_SPACE* out);	// K200선물_SPACE
