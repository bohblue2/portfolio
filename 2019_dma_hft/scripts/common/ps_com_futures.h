// ps_com_futures.h
// 상품선물 실시간

#pragma once
// 주석에 \n이 들어간건 나중에 이쁘게 바꿔야함

#include "cb_com_futures_tr.h"
#include "df_com_futures_tr.h"


int ParseC4016(const double& timestamp, const char* in_buff, DF_COM_FUT_COMP_BLOCK* out);	// 상품선물_경쟁+협의합산
int ParseA3016(const double& timestamp, const char* in_buff, DF_COM_FUT_EXEC* out);	// 상품선물_체결
int ParseB6016(const double& timestamp, const char* in_buff, DF_COM_FUT_LIMIT_ORD* out);	// 상품선물_우선호가
int ParseG7016(const double& timestamp, const char* in_buff, DF_COM_FUT_EXEC_LIMIT_ORD* out);	// 상품선물_체결_우선호가
int ParseA6016(const double& timestamp, const char* in_buff, DF_COM_FUT_CLOSE_PRODUCT* out);	// 상품선물_종목마감
int ParseA7016(const double& timestamp, const char* in_buff, DF_COM_FUT_MRK_OP_TS* out);	// 상품선물_장운영TS
int ParseH0016(const double& timestamp, const char* in_buff, DF_COM_FUT_CLOSE* out);	// 상품선물_마감
int ParseM4016(const double& timestamp, const char* in_buff, DF_COM_FUT_MRK_OP_SCHD* out);	// 상품선물_장운영스케줄공개
int ParseO6016(const double& timestamp, const char* in_buff, DF_COM_FUT_DIST_INFO* out);	// 상품선물_배분정보
int ParseQ2016(const double& timestamp, const char* in_buff, DF_COM_FUT_REAL_HIGH_LOW_LIMIT_ON_OFF* out);	// 상품선물_실시간상하한가 적용및해제
int ParseH2016(const double& timestamp, const char* in_buff, DF_COM_FUT_OPEN_INTEREST_DATA* out);	// 상품선물_미결제약정수량 데이터
int ParseH3016(const double& timestamp, const char* in_buff, DF_COM_FUT_SETT_PRC_DATA* out);	// 상품선물_정산가격 데이터
int ParseH1016(const double& timestamp, const char* in_buff, DF_COM_FUT_INVESTOR_DATA* out);	// 상품선물_투자자 데이터
int ParseB2016(const double& timestamp, const char* in_buff, DF_COM_FUT_RECOVERY_DATA* out);	// 상품선물_시세Recovery 데이터
int ParseA0016(const double& timestamp, const char* in_buff, DF_COM_FUTRE_PRD_INFO_DATA* out);	// 상품선물_종목정보 데이터
int ParseH5016(const double& timestamp, const char* in_buff, DF_GOV_BOND_CD_DATA* out);	// 현물정보_국채_CD_데이터
int ParseH6016(const double& timestamp, const char* in_buff, DF_STD_GOV_BOND_DATA* out);	// 현물정보_결제기준채권_데이터
int ParseH9016(const double& timestamp, const char* in_buff, DF_USD_DATA* out);	// 현물정보_USD_데이터
int ParseI0016_FBB1(const double& timestamp, const char* in_buff, DF_USD_BATCH_DATA_1* out);	// 현물정보_USD배치_데이터1
int ParseI0016_FBC1(const double& timestamp, const char* in_buff, DF_USD_BATCH_DATA_2* out);	// 현물정보_USD배치_데이터2
int ParseI0016_FBC2(const double& timestamp, const char* in_buff, DF_USD_BATCH_DATA_3* out);	// 현물정보_USD배치_데이터3
int ParseI0016_FBD1(const double& timestamp, const char* in_buff, DF_USD_BATCH_DATA_4* out);	// 현물정보_USD배치_데이터4
int ParseI0016_FBE1(const double& timestamp, const char* in_buff, DF_USD_BATCH_DATA_5* out);	// 현물정보_USD배치_데이터5
int ParseI0016_FBF1(const double& timestamp, const char* in_buff, DF_USD_BATCH_DATA_6* out);	// 현물정보_USD배치_데이터6
int ParseI0016_FBF2(const double& timestamp, const char* in_buff, DF_USD_BATCH_DATA_7* out);	// 현물정보_USD배치_데이터7
int ParseI0016_FBG1(const double& timestamp, const char* in_buff, DF_USD_BATCH_DATA_8* out);	// 현물정보_USD배치_데이터8
int ParseI0016_CBA1(const double& timestamp, const char* in_buff, DF_USD_BATCH_DATA_9* out);	// 현물정보_USD배치_데이터9
int ParseI0016_CBA2(const double& timestamp, const char* in_buff, DF_USD_BATCH_DATA_10* out);	// 현물정보_USD배치_데이터10
int ParseI1016_FOC1(const double& timestamp, const char* in_buff, DF_USD_REAL_TIME_DATA_1* out);	// 현물정보_USD실시간정보_데이터1
int ParseI1016_FOD1(const double& timestamp, const char* in_buff, DF_USD_REAL_TIME_DATA_2* out);	// 현물정보_USD실시간정보_데이터2
int ParseI1016_FOE1(const double& timestamp, const char* in_buff, DF_USD_REAL_TIME_DATA_3* out);	// 현물정보_USD실시간정보_데이터3
int ParseI1016_HOE1(const double& timestamp, const char* in_buff, DF_CNH_REAL_TIME_DATA* out);	// 현물정보_CNH실시간정보_데이터
int ParseI1016_FOF1(const double& timestamp, const char* in_buff, DF_USD_REAL_TIME_DATA_4* out);	// 현물정보_USD실시간정보_데이터4
int ParseI1016_FOG1(const double& timestamp, const char* in_buff, DF_USD_REAL_TIME_DATA_5* out);	// 현물정보_USD실시간정보_데이터5
int ParseI1016_UOD1(const double& timestamp, const char* in_buff, DF_USD_REAL_TIME_DATA_8* out);	// 현물정보_USD실시간정보_데이터8
int ParseI1016_COA1(const double& timestamp, const char* in_buff, DF_USD_REAL_TIME_DATA_7* out);	// 현물정보_USD실시간정보_데이터7
int ParseI1016_FOQ1(const double& timestamp, const char* in_buff, DF_USD_REAL_TIME_DATA_6* out);	// 현물정보_USD실시간정보_데이터6
int ParseI2016(const double& timestamp, const char* in_buff, DF_COM_FUT_POLLING_DATA* out);	// 상품선물_Polling 데이터
int ParseI1016_UOE1(const double& timestamp, const char* in_buff, DF_USD_REAL_TIME_DATA_9* out);	// 현물정보_USD실시간정보_데이터9
int H8016_1000(const double& timestamp, const char* in_buff, DF_LEAN_HOG_REP_PRC_INDEX_DATA* out);	// 현물정보_돈육대표가격지수_데이터
int H8016_REAL(const double& timestamp, const char* in_buff, DF_LEAN_HOG_REAL_TIME_PRC_INDEX_DATA* out);	// 현물정보_돈육실시간가격지수_데이터
int H8016_1800(const double& timestamp, const char* in_buff, DF_LEAN_HOG_CLOSE_PRICE_INDEX_DATA* out);	// 현물정보_돈육마감가격지수_데이터
int ParseG9016(const double& timestamp, const char* in_buff, DF_COM_FUT_SPACE* out);	// 상품선물_SPACE
