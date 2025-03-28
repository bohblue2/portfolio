// ps_kosdaq.h
// 코스닥주식

#pragma once
// 주석에 \n이 들어간건 나중에 이쁘게 바꿔야함

#include "ps_stock_common.h"
#include "cb_kosdaq_tr.h"
#include "df_kosdaq_tr.h"


int ParseAZ012(const double& timestamp, const char* in_buff, DF_KOSDAQ_TR_EXP_IDX* out);	// 코스닥 TR예상지수
int ParseAY012(const double& timestamp, const char* in_buff, DF_KOSDAQ_TR_IDX* out);	// 코스닥 TR지수
int ParseA3012(const double& timestamp, const char* in_buff, DF_KOSDAQ_CCLS* out);	// 코스닥_체결
int ParseA4012(const double& timestamp, const char* in_buff, DF_KOSDAQ_BASE_PRC_DCS* out);	// 코스닥_기준가결정
int ParseA6012(const double& timestamp, const char* in_buff, DF_KOSDAQ_STK_CLSG* out);	// 코스닥_종목마감
int ParseA7012(const double& timestamp, const char* in_buff, DF_KOSDAQ_MKT_OPR_TS* out);	// 코스닥_장운영TS
int ParseO6012(const double& timestamp, const char* in_buff, DF_KOSDAQ_ALLC_INFO* out);	// 코스닥_배분정보
int ParseA0012(const double& timestamp, const char* in_buff, DF_KOSDAQ_STK_ARNG* out);	// 코스닥_종목배치
int ParseI5012(const double& timestamp, const char* in_buff, DF_KOSDAQ_STGD_INFO* out);	// 코스닥_결산일 정보
int ParseI6012(const double& timestamp, const char* in_buff, DF_KOSDAQ_STK_EVT_INFO* out);	// 코스닥_종목 이벤트 정보
int ParseI7012(const double& timestamp, const char* in_buff, DF_KOSDAQ_LP_INFO* out);	// 코스닥_LP 정보
int ParseC4012(const double& timestamp, const char* in_buff, DF_KOSDAQ_MSV_CCLS* out);	// 코스닥_대량체결
int ParseA8012(const double& timestamp, const char* in_buff, DF_KOSDAQ_STK_INFO_DCLS* out);	// 코스닥_주식종목정보공개
int ParseR3012(const double& timestamp, const char* in_buff, DF_KOSDAQ_MBR_SCT_CNCL_DCLS* out);	// 코스닥_회원제재해제공개
int ParseM4012(const double& timestamp, const char* in_buff, DF_KOSDAQ_MKT_OPR_DCLS* out);	// 코스닥_장운영스케줄공개
int ParseA9012(const double& timestamp, const char* in_buff, DF_KOSDAQ_TRS_STK_ARNG_INFO* out);	// 코스닥_자사주 배치정보
int ParseB0012(const double& timestamp, const char* in_buff, DF_KOSDAQ_TRS_STK_TRD_INFO* out);	// 코스닥_자사주 매매정보
int ParseB2012(const double& timestamp, const char* in_buff, DF_KOSDAQ_MKT_PRC_RCVR* out);	// 코스닥_시세RECOVERY
int ParseB3012(const double& timestamp, const char* in_buff, DF_KOSDAQ_OFH_RCVR_FINAL* out);	// 코스닥_시간외단일가_리커버리_최종
int ParseB4012(const double& timestamp, const char* in_buff, DF_KOSDAQ_OFH_RCVR* out);	// 코스닥_시간외단일가_리커버리
int ParseB5012(const double& timestamp, const char* in_buff, DF_KOSDAQ_CUR_FLCT* out);	// 코스닥_현재등락
int ParseO4012(const double& timestamp, const char* in_buff, DF_KOSDAQ_BIN_EXCQ* out);	// 코스닥_Buy-in_실행수량
int ParseP2012(const double& timestamp, const char* in_buff, DF_KOSDAQ_BYIND_DYR* out);	// 코스닥 업종별 배당수익률
int ParseB8012(const double& timestamp, const char* in_buff, DF_KOSDAQ_BOPEN_ASK_RSD* out);	// 코스닥_장개시전_호가잔량
int ParseB6012(const double& timestamp, const char* in_buff, DF_KOSDAQ_ASK_RSD_WOLP* out);	// 코스닥_호가잔량_LP호가_제외
int ParseI8012(const double& timestamp, const char* in_buff, DF_KOSDAQ_SHORT* out);	// 코스닥_공매도
int ParseB1012(const double& timestamp, const char* in_buff, DF_KOSDAQ_MKT_PRC_CLS* out);	// 코스닥_시세종가
int ParseC0012(const double& timestamp, const char* in_buff, DF_KOSDAQ_BYIND_BYINV* out);	// 코스닥_업종별투자자별
int ParseA0013(const double& timestamp, const char* in_buff, DF_KOTC_STK_ARNG* out);	// K-OTC 종목배치
int ParseA2013(const double& timestamp, const char* in_buff, DF_KOTC_ASK_PRC* out);	// K-OTC 호가
int ParseA3013(const double& timestamp, const char* in_buff, DF_KOTC_CCLS* out);	// K-OTC 체결
int ParseA6013(const double& timestamp, const char* in_buff, DF_KOTC_STK_CLSG* out);	// K-OTC 종목마감
int ParseA7013(const double& timestamp, const char* in_buff, DF_KOTC_MKT_OPR* out);	// K-OTC 장운영
int ParseG5013(const double& timestamp, const char* in_buff, DF_KOTC_MKT_ACT* out);	// K-OTC 시장조치
int ParseE9013_F0013(const double& timestamp, const char* in_buff, DF_KOTC_DCLS_ARNG_RT* out);	// K-OTC 공시 배치/실시간
int ParseE4012(const double& timestamp, const char* in_buff, DF_KOSDAQ_IDX* out);	// KOSDAQ지수
int ParseE5012(const double& timestamp, const char* in_buff, DF_KOSDAQ_EXP_IDX* out);	// KOSDAQ예상지수
int ParseB9012(const double& timestamp, const char* in_buff, DF_KOSDAQ_TRS* out);	// 코스닥_거래원
int ParseC1012(const double& timestamp, const char* in_buff, DF_KOSDAQ_BYSTK_BYINV_CLS* out);	// 코스닥_종목별투자자별 종가
int ParseC3012(const double& timestamp, const char* in_buff, DF_KOSDAQ_PRGTRD_ASK* out);	// 코스닥_프로그램매매 호가
int ParseJ0012(const double& timestamp, const char* in_buff, DF_KOSDAQ_PRGTRD_TOT* out);	// 코스닥_프로그램매매 전체집계
int ParseC5012(const double& timestamp, const char* in_buff, DF_KOSDAQ_PRGTRD_DCLS* out);	// 코스닥_프로그램매매 사전사후공시
int ParseP0012(const double& timestamp, const char* in_buff, DF_KOSDAQ_PRGTRD_BYINV_STAT* out);	// 코스닥 프로그램매매 투자자별 매매현황
int ParseR8012(const double& timestamp, const char* in_buff, DF_KOSDAQ_STK_STAT_INFO* out);	// 코스닥_종목상태정보(VI)
