// ps_kospi.h
// 유가증권주식

#pragma once
// 주석에 \n이 들어간건 나중에 이쁘게 바꿔야함

#include "ps_stock_common.h"
#include "cb_kospi_tr.h"
#include "df_kospi_tr.h"


int ParseBD011(const double& timestamp, const char* in_buff, DF_KRX300_TR_EXP_IDX* out);	// KRX 300 TR예상지수
int ParseBC011(const double& timestamp, const char* in_buff, DF_KRX300_TR_IDX* out);	// KRX 300 TR지수
int ParseAX011(const double& timestamp, const char* in_buff, DF_KOSPI_TR_EXP_IDX* out);	// 코스피 TR예상지수
int ParseAW011(const double& timestamp, const char* in_buff, DF_KOSPI_TR_IDX* out);	// 코스피 TR지수
int ParseAB011(const double& timestamp, const char* in_buff, DF_KRX300_EXP_IDX* out);	// KRX300예상지수
int ParseAA011(const double& timestamp, const char* in_buff, DF_KRX300_IDX* out);	// KRX300지수
int ParseI6011(const double& timestamp, const char* in_buff, DF_KOSPI_STK_EVT_INFO* out);	// 코스피_종목 이벤트 정보
int ParseA0011(const double& timestamp, const char* in_buff, DF_KOSPI_STK_ARNG* out);	// 코스피_종목배치
int ParseX8011(const double& timestamp, const char* in_buff, DF_ETN_PRF_STR* out);	// ETN 수익구조 내용
int ParseX4011(const double& timestamp, const char* in_buff, DF_ETN_DSPR* out);	// ETN괴리율
int ParseX3011(const double& timestamp, const char* in_buff, DF_ETN_ELY_RDMP_COND* out);	// ETN 조기상환 조건
int ParseV6011(const double& timestamp, const char* in_buff, DF_ETP_IDX_COMP* out);	// ETP지수구성
int ParseA4011(const double& timestamp, const char* in_buff, DF_KOSPI_BASE_PRC_DCS* out);	// 코스피_기준가결정
int ParseA6011(const double& timestamp, const char* in_buff, DF_KOSPI_STK_CLSG* out);	// 코스피_종목마감
int ParseA7011(const double& timestamp, const char* in_buff, DF_KOSPI_MKT_OPR_TS* out);	// 코스피_장운영TS
int ParseA3011(const double& timestamp, const char* in_buff, DF_KOSPI_CCLS* out);	// 코스피_체결
int ParseC4011(const double& timestamp, const char* in_buff, DF_KOSPI_MSV_CCLS* out);	// 코스피_대량체결
int ParseO6011(const double& timestamp, const char* in_buff, DF_KOSPI_ALLC_INFO* out);	// 코스피_배분정보
int ParseA3021(const double& timestamp, const char* in_buff, DF_ELW_CCLS* out);	// ELW_체결
int ParseA6021(const double& timestamp, const char* in_buff, DF_ELW_STK_CLSG* out);	// ELW_종목마감
int ParseA7021(const double& timestamp, const char* in_buff, DF_ELW_MKT_OPR_TS* out);	// ELW_장운영TS
int ParseA8011(const double& timestamp, const char* in_buff, DF_KOSPI_STK_INFO_DCLS* out);	// 코스피_주식종목정보공개
int ParseM4011(const double& timestamp, const char* in_buff, DF_KOSPI_MKT_OPR_DCLS* out);	// 코스피_장운영스케줄공개
int ParseI5011(const double& timestamp, const char* in_buff, DF_KOSPI_STGD_INFO* out);	// 코스피_결산일 정보
int ParseI7011(const double& timestamp, const char* in_buff, DF_KOSPI_LP_INFO* out);	// 코스피_LP 정보
int ParseB5011(const double& timestamp, const char* in_buff, DF_KOSPI_CUR_FLCT* out);	// 코스피_현재등락
int ParseB4011(const double& timestamp, const char* in_buff, DF_KOSPI_OFH_RCVR* out);	// 코스피_시간외단일가_리커버리
int ParseB3011(const double& timestamp, const char* in_buff, DF_KOSPI_OFH_RCVR_FINAL* out);	// 코스피_시간외단일가_리커버리_최종
int ParseB6011(const double& timestamp, const char* in_buff, DF_KOSPI_ASK_RSD_WOLP* out);	// 코스피_호가잔량_LP호가_제외
int ParseB7011(const double& timestamp, const char* in_buff, DF_KOSPI_ASK_RSD_WLP* out);	// 코스피_호가잔량_LP호가_포함
int ParseB8011(const double& timestamp, const char* in_buff, DF_KOSPI_BOPEN_ASK_RSD* out);	// 코스피_장개시전_호가잔량
int ParseC0011(const double& timestamp, const char* in_buff, DF_KOSPI_BYIND_BYINV* out);	// 코스피_업종별투자자별
int ParseC3011(const double& timestamp, const char* in_buff, DF_KOSPI_PRGTRD_ASK* out);	// 코스피_프로그램매매 호가
int ParseJ0011(const double& timestamp, const char* in_buff, DF_KOSPI_PRGTRD_TOT* out);	// 코스피_프로그램매매 전체집계
int ParseC5011(const double& timestamp, const char* in_buff, DF_KOSPI_PRGTRD_DCLS* out);	// 코스피_프로그램매매 사전공시
int ParseP0011(const double& timestamp, const char* in_buff, DF_PRGTRD_BYINV_STAT* out);	// 유가 프로그램매매 투자자별 매매현황
int ParseI8011(const double& timestamp, const char* in_buff, DF_KOSPI_SHORT* out);	// 코스피_공매도
int ParseO4011(const double& timestamp, const char* in_buff, DF_KOSPI_BIN_EXCQ* out);	// 코스피_Buy-in_실행수량
int ParseO4012(const double& timestamp, const char* in_buff, DF_KOSDQ_BIN_EXCQ* out);	// 코스닥_Buy-in_실행수량
int ParseO4018(const double& timestamp, const char* in_buff, DF_KONEX_BIN_EXCQ* out);	// 코넥스_Buy-in_실행수량
int ParseB1011(const double& timestamp, const char* in_buff, DF_KOSPI_MKT_PRC_CLS* out);	// 코스피_시세종가
int ParseB2011(const double& timestamp, const char* in_buff, DF_KOSPI_MKT_PRC_RCVR* out);	// 코스피_시세RECOVERY
int ParseF1011(const double& timestamp, const char* in_buff, DF_KOSPI_FRGN_INV_INFO* out);	// 코스피 외국인 종목별투자정보_확정치
int ParseF2011(const double& timestamp, const char* in_buff, DF_KOSPI_FRGN_ORDL_QTY* out);	// 코스피 외국인 주문가능수량
int ParseF3011(const double& timestamp, const char* in_buff, DF_KOSPI_FRGN_RSVD_ORD_CNCL* out);	// 코스피 외국인 예비주문지정_해지
int ParseF4011(const double& timestamp, const char* in_buff, DF_KOSPI_FRGN_CFRM_DATA* out);	// 코스피 외국인 확정치데이터재전송
int ParseF5011(const double& timestamp, const char* in_buff, DF_KOSPI_FRGN_LMT_XHS* out);	// 코스피 외국인 한도소진장외매매
int ParseF6011(const double& timestamp, const char* in_buff, DF_KOSPI_FRGN_TRD_STAT* out);	// 코스피 외국인 매매_결제현황
int ParseF5012(const double& timestamp, const char* in_buff, DF_KOSDAQ_FRGN_LMT_XHS* out);	// 코스닥 외국인 한도소진장외매매
int ParseF6012(const double& timestamp, const char* in_buff, DF_KOSDAQ_FRGN_TRD_STAT* out);	// 코스닥 외국인 매매_결제현황
int ParseF3012(const double& timestamp, const char* in_buff, DF_KOSDAQ_FRGN_RSVD_ORD_CNCL* out);	// 코스닥 외국인 예비주문지정_해지
int ParseF1012(const double& timestamp, const char* in_buff, DF_KOSDAQ_FRGN_INV_INFO* out);	// 코스닥 외국인 종목별투자정보_확정치
int ParseF2012(const double& timestamp, const char* in_buff, DF_KOSDAQ_FRGN_ORDL_QTY* out);	// 코스닥 외국인 주문가능수량
int ParseF4012(const double& timestamp, const char* in_buff, DF_KOSDAQ_FRGN_CFRM_DATA* out);	// 코스닥 외국인 확정치데이터재전송
int ParseF1018(const double& timestamp, const char* in_buff, DF_KONEX_FRGN_INV_INFO* out);	// 코넥스 외국인 종목별투자정보_확정치
int ParseF2018(const double& timestamp, const char* in_buff, DF_KONEX_FRGN_ORDL_QTY* out);	// 코넥스 외국인 주문가능수량
int ParseF3018(const double& timestamp, const char* in_buff, DF_KONEX_FRGN_RSVD_ORD_CNCL* out);	// 코넥스 외국인 예비주문지정_해지
int ParseF4018(const double& timestamp, const char* in_buff, DF_KONEX_FRGN_CFRM_DATA* out);	// 코넥스 외국인 확정치데이터재전송
int ParseF5018(const double& timestamp, const char* in_buff, DF_KONEX_FRGN_LMT_XHS* out);	// 코넥스 외국인 한도소진장외매매
int ParseF6018(const double& timestamp, const char* in_buff, DF_KONEX_FRGN_TRD_STAT* out);	// 코넥스 외국인 매매_결제현황
int ParseP2011(const double& timestamp, const char* in_buff, DF_KOSPI_BYIND_DYR* out);	// 유가 업종별 배당수익률
int ParseA1011(const double& timestamp, const char* in_buff, DF_ELW_STK_ARNG* out);	// ELW 종목배치
int ParseM6011(const double& timestamp, const char* in_buff, DF_ELY_CLS_ELW_STK_ARNG* out);	// 조기종료ELW_종목배치
int ParseM5011(const double& timestamp, const char* in_buff, DF_ELY_CLS_ELW_ASSET_HLP* out);	// 조기종료ELW 평가기간 중 기초자산고저가
int ParseB2021(const double& timestamp, const char* in_buff, DF_ELW_MKT_PRC_RCVR* out);	// ELW_시세RECOVERY
int ParseC6021(const double& timestamp, const char* in_buff, DF_ELW_INV_IDX* out);	// ELW 투자지표
int ParseN3021(const double& timestamp, const char* in_buff, DF_ELW_LP_ASK_VOL* out);	// ELW LP호가 내재변동성
int ParseB1021(const double& timestamp, const char* in_buff, DF_ELW_MKT_PRC_CLS* out);	// ELW_시세종가
int ParseC0021(const double& timestamp, const char* in_buff, DF_ELW_BYINV* out);	// ELW_투자자별
int ParseB7021(const double& timestamp, const char* in_buff, DF_ELW_ASK_RSD_WLP* out);	// ELW_호가잔량_LP호가_포함
int ParseN8011(const double& timestamp, const char* in_buff, DF_ETF_TRA_INFO* out);	// ETF사무수탁배치
int ParseF8011(const double& timestamp, const char* in_buff, DF_ETF_PDF* out);	// ETF PDF
int ParseM8011(const double& timestamp, const char* in_buff, DF_ETF_OPR_INFO* out);	// ETF운영사정보
int ParseF7011(const double& timestamp, const char* in_buff, DF_ETF_NAV* out);	// ETF NAV
int ParseI3011(const double& timestamp, const char* in_buff, DF_ETF_EXP_NAV* out);	// ETF 예상NAV
int ParseP6011(const double& timestamp, const char* in_buff, DF_ETF_TER* out);	// ETF 추적오차율
int ParseC0031(const double& timestamp, const char* in_buff, DF_ETF_BYINV* out);	// ETF_투자자별
int ParseM9011(const double& timestamp, const char* in_buff, DF_MBR_INFO* out);	// 회원사정보
int ParseD0011(const double& timestamp, const char* in_buff, DF_KOSPI_IDX* out);	// KOSPI지수
int ParseD1011(const double& timestamp, const char* in_buff, DF_KOSPI_EXP_IDX* out);	// KOSPI예상지수
int ParseD2011(const double& timestamp, const char* in_buff, DF_KOSPI_200_IDX* out);	// KOSPI200지수
int ParseD3011(const double& timestamp, const char* in_buff, DF_KOSPI_200_EXP_IDX* out);	// KOSPI200예상지수
int ParseD4011(const double& timestamp, const char* in_buff, DF_KOSPI_100_50_IDX* out);	// KOSPI100/50지수
int ParseN6011(const double& timestamp, const char* in_buff, DF_KOSPI_200_STR_EXP_IDX* out);	// KOSPI200 섹터예상지수
int ParseN5011(const double& timestamp, const char* in_buff, DF_KOSPI_200_STR_IDX* out);	// KOSPI200 섹터지수
int ParseC8011(const double& timestamp, const char* in_buff, DF_KOSPI_100_IDX* out);	// KRX100지수
int ParseC9011(const double& timestamp, const char* in_buff, DF_KOSPI_100_EXP_IDX* out);	// KRX100예상지수
int ParseN9011(const double& timestamp, const char* in_buff, DF_EWIDX* out);	// 동일가중지수
int ParseO1011(const double& timestamp, const char* in_buff, DF_EWEIDX* out);	// 동일가중예상지수
int ParseG1067(const double& timestamp, const char* in_buff, DF_MARKET_IDX_GROUP_EXP_CODE* out);	// 시장지수 그룹_만기코드
int ParseP3011(const double& timestamp, const char* in_buff, DF_WISEFN_IDX* out);	// 와이즈에프엔지수
int ParseB9011(const double& timestamp, const char* in_buff, DF_KOSPI_TRS* out);	// 코스피_거래원
int ParseB9021(const double& timestamp, const char* in_buff, DF_ELW_TRS* out);	// ELW_거래원
int ParseC1011(const double& timestamp, const char* in_buff, DF_KOSPI_BYSTK_BYINV_CLS* out);	// 코스피_종목별투자자별 종가
int ParseC1021(const double& timestamp, const char* in_buff, DF_ELW_BYSTK_BYINV_CLS* out);	// ELW_종목별투자자별 종가
int ParseL5011(const double& timestamp, const char* in_buff, DF_FRIDX_ETF_NAV* out);	// 해외지수 ETF NAV
int ParseP7011(const double& timestamp, const char* in_buff, DF_FRIDX_TER* out);	// 해외ETF 추적오차율
int ParseQ4011(const double& timestamp, const char* in_buff, DF_SETF_DAY_CPTY_RISK_INFO* out);	// 합성ETF 일일 거래상대방 위험평가액 정보
int ParseE2011(const double& timestamp, const char* in_buff, DF_MKF_IDX* out);	// MKF지수
int ParseO9011(const double& timestamp, const char* in_buff, DF_MKF_IDX_WYFX* out);	// MKF지수(엔환율반영)
int ParseM3011(const double& timestamp, const char* in_buff, DF_FRIDX_ETF_IDX* out);	// 해외지수ETF대상지수
int ParseO5019(const double& timestamp, const char* in_buff, DF_FRIDX* out);	// 해외지수
int ParseQ5011(const double& timestamp, const char* in_buff, DF_SETF_BASE_IDX_COMP_STK* out);	// 합성ETF 기초지수 구성종목
int ParseF1013(const double& timestamp, const char* in_buff, DF_FBRD_FRGN_INV_INFO* out);	// 프리보드 외국인 종목별투자정보_확정치
int ParseF2013(const double& timestamp, const char* in_buff, DF_FBRD_FRGN_ORDL_QTY* out);	// 프리보드 외국인 주문가능수량
int ParseF3013(const double& timestamp, const char* in_buff, DF_FBRD_FRGN_RSVD_ORD_CNCL* out);	// 프리보드 외국인 예비주문지정_해지
int ParseF4013(const double& timestamp, const char* in_buff, DF_FBRD_FRGN_CFRM_DATA* out);	// 프리본드 외국인 확정치데이터재전송
int ParseF5013(const double& timestamp, const char* in_buff, DF_FBRD_FRGN_LMT_XHS* out);	// 프리보드 외국인 한도소진장외매매
int ParseC7021(const double& timestamp, const char* in_buff, DF_ELW_INV_IDX_SST* out);	// ELW 투자지표민감도
int ParseA9011(const double& timestamp, const char* in_buff, DF_KOSPI_TRS_STK_ARNG_INFO* out);	// 코스피_자사주 배치정보
int ParseB0011(const double& timestamp, const char* in_buff, DF_KOSPI_TRS_STK_TRD_INFO* out);	// 코스피_자사주 매매정보
int ParseK2011(const double& timestamp, const char* in_buff, DF_LVR_KOSPI200_IDX* out);	// 레버리지 KOSPI200지수
int ParseR3011(const double& timestamp, const char* in_buff, DF_KOSPI_MBR_SCT_CNCL_DCLS* out);	// 코스피_회원제재해제공개
int ParseR8011(const double& timestamp, const char* in_buff, DF_KOSPI_STK_STAT_INFO* out);	// 코스피_종목상태정보(VI)
int ParseS1011(const double& timestamp, const char* in_buff, DF_ETN_TRA_INFO* out);	// ETN 사무수탁정보
int ParseS2011(const double& timestamp, const char* in_buff, DF_ETN_BASE_IDX_COMP_STK* out);	// ETN 기초지수 구성종목
int ParseC0041(const double& timestamp, const char* in_buff, DF_ETN_BYINV* out);	// ETN_투자자별
int ParseS3011(const double& timestamp, const char* in_buff, DF_ETN_IIV* out);	// ETN IIV
int ParseA1041(const double& timestamp, const char* in_buff, DF_ETN_STK_ARNG* out);	// ETN 종목배치
int ParseT7011(const double& timestamp, const char* in_buff, DF_KTOP30_IDX* out);	// KTOP30지수
int ParseT8011(const double& timestamp, const char* in_buff, DF_KTOP30_EXP_IDX* out);	// KTOP30예상지수
