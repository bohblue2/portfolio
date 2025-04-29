// ps_kp200_option.h
// KOSPI200 지수옵션

#pragma once
// 주석에 \n이 들어간건 나중에 이쁘게 바꿔야함

#include "cb_kp200_option_tr.h"
#include "df_kp200_option_tr.h"


int ParseC4034(const double& timestamp, const char* in_buff, DF_K200_OPT_COMP_BLOCK* out);	// K200옵션_경쟁+협의합산
int ParseA3034(const double& timestamp, const char* in_buff, DF_K200_OPT_EXEC* out);	// K200옵션_체결
int ParseB6034(const double& timestamp, const char* in_buff, DF_K200_OPT_LIMIT_ORD* out);	// K200옵션_우선호가
int ParseG7034(const double& timestamp, const char* in_buff, DF_K200_OPT_EXEC_LIMIT_ORD* out);	// K200옵션_체결_우선호가
int ParseA6034(const double& timestamp, const char* in_buff, DF_K200_OPT_CLOSE_PRODUCT* out);	// K200옵션_종목마감
int ParseA7034(const double& timestamp, const char* in_buff, DF_K200_OPT_MRK_OP_TS* out);	// K200옵션_장운영TS
int ParseH0034(const double& timestamp, const char* in_buff, DF_K200_OPT_CLOSE* out);	// K200옵션_마감
int ParseM4034(const double& timestamp, const char* in_buff, DF_K200_OPT_MRK_OP_SCHD* out);	// K200옵션_장운영스케줄공개
int ParseO6034(const double& timestamp, const char* in_buff, DF_K200_OPT_DIST_INFO* out);	// K200옵션_배분정보
int ParseQ2034(const double& timestamp, const char* in_buff, DF_K200_OPT_REAL_HIGH_LOW_LIMIT_ON_OFF* out);	// K200옵션_실시간상하한가 적용및해제
int ParseV1034(const double& timestamp, const char* in_buff, DF_K200_OPT_PRC_LIMIT_ON* out);	// K200옵션_가격제한폭확대발동
int ParseG9034(const double& timestamp, const char* in_buff, DF_K200_OPT_SPACE* out);	// K200옵션_SPACE
int ParseH2034(const double& timestamp, const char* in_buff, DF_K200_OPT_OPEN_INTEREST_DATA* out);	// K200옵션_미결제약정수량 데이터
int ParseH3034(const double& timestamp, const char* in_buff, DF_K200_OPT_TRD_MRG_STD_PRC_DATA* out);	// K200옵션_매매증거금기준가 데이터
int ParseA0034(const double& timestamp, const char* in_buff, DF_K200_OPT_PRD_INFO_DATA* out);	// K200옵션_종목정보 데이터
int ParseN7034(const double& timestamp, const char* in_buff, DF_K200_OPT_SENSITIVITY_DATA* out);	// K200옵션_민감도
int ParseP1034(const double& timestamp, const char* in_buff, DF_K200_OPT_IMPLIED_VOL_DATA* out);	// KOSPI200옵션 내재변동성
int ParseH1034(const double& timestamp, const char* in_buff, DF_K200_OPT_INVESTOR_DATA* out);	// K200옵션_투자자 데이터
int ParseB2034(const double& timestamp, const char* in_buff, DF_K200_OPT_RECOVERY_DATA* out);	// K200옵션_시세Recovery 데이터
int ParseI2034(const double& timestamp, const char* in_buff, DF_K200_OPT_POLLING_DATA* out);	// K200옵션_Polling 데이터
int ParseM7034(const double& timestamp, const char* in_buff, DF_K200_OPT_BLOCK_TRD_BEF_MRK_OPEN* out);	// K200옵션_장개시전협의거래
