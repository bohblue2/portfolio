// df_com_futures_tr.h
// 상품선물 실시간 TR

#pragma once
// 주석에 \n이 들어간건 나중에 이쁘게 바꿔야함


// 상품선물_경쟁+협의합산
typedef struct _DF_COM_FUT_COMP_BLOCK {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA구분,C4
	char info_clsf[3];	// 정보구분,01:상품선물
	char mkt_clsf;	// 시장구분,6
	char isin_clsf[13];	// 종목코드,*개발가이드 참조 : 신국채선물 추가\n 2010.10.25
	int stk_snr;	// 종목일련번호
	double cpt_block_trd_vol;	// 경쟁+협의합산 거래량,경쟁매매, 협의대량거래, EFP, FLEX 거래를 합산한 거래량
	double cpt_block_trd_amt;	// 경쟁+협의합산 거래대금,경쟁매매, 협의대량거래, EFP, FLEX 거래를 합산한 거래대금\n(단위 : 원)
} DF_COM_FUT_COMP_BLOCK;


// 상품선물_체결
typedef struct _DF_COM_FUT_EXEC {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA구분,A3
	char info_clsf[3];	// 정보구분,01:상품선물
	char mkt_clsf;	// 시장구분,6
	char isin_clsf[13];	// 종목코드,*개발가이드 참조 : 신국채선물 추가\n 2010.10.25
	int stk_snr;	// 종목일련번호
	char brd_id[3];	// 보드ID,코드값모음참조
	double cur_prc;	// 현재가격,예) 999999.99
	int exe_q;	// 체결수량
	char ss_id[3];	// 세션ID,코드값모음참조
	char exe_t[9];	// 체결시각
	double rct_prd_prc;	// 최근월물의제약정가격,예) 999999.99
	double nxt_prd_prc;	// 원월물의제약정가격,예) 999999.99
	double init_prc;	// 시가,예) 999999.99
	double high_prc;	// 고가,예) 999999.99
	double low_prc;	// 저가,예) 999999.99
	double pri_prc;	// 직전가격,예) 999999.99
	int accm_exe_q;	// 누적체결수량
	double accm_trd_amt;	// 누적거래대금(단위:원)
	char l_or_s;	// 최종매도매수구분코드,1:매도,2:매수(최종으로 들어온 호가의 매도매수구분값)
	double real_t_high_prc;	// 실시간상한가,예) 999999.99 개발가이드참조
	double real_t_low_prc;	// 실시간하한가,예) 999999.99 개발가이드참조
} DF_COM_FUT_EXEC;


// 상품선물_우선호가
typedef struct _DF_COM_FUT_LIMIT_ORD {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA구분,B6
	char info_clsf[3];	// 정보구분,01:상품선물
	char mkt_clsf;	// 시장구분,6
	char isin_clsf[13];	// 종목코드,*개발가이드 참조 : 신국채선물 추가\n 2010.10.25
	int stk_snr;	// 종목일련번호
	char brd_id[3];	// 보드ID,코드값모음참조
	char ss_id[3];	// 세션ID,코드값모음참조
	int total_l_limit_ord_q;	// 매수총호가잔량
	double l_lvl_1_prc;	// 매수1단계우선호가가격,예) 999999.99
	int l_lvl_1_q;	// 매수1단계우선호가잔량
	double l_lvl_2_prc;	// 매수2단계우선호가가격,예) 999999.99
	int l_lvl_2_q;	// 매수2단계우선호가잔량
	double l_lvl_3_prc;	// 매수3단계우선호가가격,예) 999999.99
	int l_lvl_3_q;	// 매수3단계우선호가잔량
	double l_lvl_4_prc;	// 매수4단계우선호가가격,예) 999999.99
	int l_lvl_4_q;	// 매수4단계우선호가잔량
	double l_lvl_5_prc;	// 매수5단계우선호가가격,예) 999999.99
	int l_lvl_5_q;	// 매수5단계우선호가잔량
	int total_s_limit_ord_q;	// 매도총호가잔량
	double s_lvl_1_prc;	// 매도1단계우선호가가격,예) 999999.99
	int s_lvl_1_q;	// 매도1단계우선호가잔량
	double s_lvl_2_prc;	// 매도2단계우선호가가격,예) 999999.99
	int s_lvl_2_q;	// 매도2단계우선호가잔량
	double s_lvl_3_prc;	// 매도3단계우선호가가격,예) 999999.99
	int s_lvl_3_q;	// 매도3단계우선호가잔량
	double s_lvl_4_prc;	// 매도4단계우선호가가격,예) 999999.99
	int s_lvl_4_q;	// 매도4단계우선호가잔량
	double s_lvl_5_prc;	// 매도5단계우선호가가격,예) 999999.99
	int s_lvl_5_q;	// 매도5단계우선호가잔량
	int total_l_trd_cnt;	// 매수유효호가건수
	int l_lvl_1_trd_cnt;	// 매수1단계우선호가건수
	int l_lvl_2_trd_cnt;	// 매수2단계우선호가건수
	int l_lvl_3_trd_cnt;	// 매수3단계우선호가건수
	int l_lvl_4_trd_cnt;	// 매수4단계우선호가건수
	int l_lvl_5_trd_cnt;	// 매수5단계우선호가건수
	int total_s_trd_cnt;	// 매도유효호가건수
	int s_lvl_1_trd_cnt;	// 매도1단계우선호가건수
	int s_lvl_2_trd_cnt;	// 매도2단계우선호가건수
	int s_lvl_3_trd_cnt;	// 매도3단계우선호가건수
	int s_lvl_4_trd_cnt;	// 매도4단계우선호가건수
	int s_lvl_5_trd_cnt;	// 매도5단계우선호가건수
	char ord_rcv_t[9];	// 호가접수시각
	double exp_prc;	// 예상체결가격,예) 999999.99 단일가매매시만 제공\n (장상태구분코드:10,20,30,80)
} DF_COM_FUT_LIMIT_ORD;


// 상품선물_체결_우선호가
typedef struct _DF_COM_FUT_EXEC_LIMIT_ORD {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA구분,G7
	char info_clsf[3];	// 정보구분,01:상품선물
	char mrk_clsf;	// 시장구분,6
	char isin_clsf[13];	// 종목코드,*개발가이드 참조 : 신국채선물 추가\n 2010.10.25
	int stk_snr;	// 종목일련번호
	char brd_id[3];	// 보드ID,코드값모음참조
	double cur_price;	// 현재가격,예) 999999.99
	int exe_q;	// 체결수량
	char ss_id[3];	// 세션ID,코드값모음참조
	char exe_t[9];	// 체결시각
	double rct_prd_prc;	// 최근월물의제약정가격,예) 999999.99
	double nxt_prd_prc;	// 원월물의제약정가격,예) 999999.99
	double init_prc;	// 시가,예) 999999.99
	double high_prc;	// 고가,예) 999999.99
	double low_prc;	// 저가,예) 999999.99
	double pri_prc;	// 직전가격,예) 999999.99
	int accm_exe_q;	// 누적체결수량
	double accm_trd_amt;	// 누적거래대금(단위:원)
	char l_or_s;	// 최종매도매수구분코드,1:매도,2:매수(최종으로 들어온 호가의 매도매수구분값)
	int total_l_limit_ord_q;	// 매수총호가잔량
	double l_lvl_1_prc;	// 매수1단계우선호가가격,예) 999999.99
	int l_lvl_1_q;	// 매수1단계우선호가잔량
	double l_lvl_2_prc;	// 매수2단계우선호가가격,예) 999999.99
	int l_lvl_2_q;	// 매수2단계우선호가잔량
	double l_lvl_3_prc;	// 매수3단계우선호가가격,예) 999999.99
	int l_lvl_3_q;	// 매수3단계우선호가잔량
	double l_lvl_4_prc;	// 매수4단계우선호가가격,예) 999999.99
	int l_lvl_4_q;	// 매수4단계우선호가잔량
	double l_lvl_5_prc;	// 매수5단계우선호가가격,예) 999999.99
	int l_lvl_5_q;	// 매수5단계우선호가잔량
	int total_s_limit_ord_q;	// 매도총호가잔량
	double s_lvl_1_prc;	// 매도1단계우선호가가격,예) 999999.99
	int s_lvl_1_q;	// 매도1단계우선호가잔량
	double s_lvl_2_prc;	// 매도2단계우선호가가격,예) 999999.99
	int s_lvl_2_q;	// 매도2단계우선호가잔량
	double s_lvl_3_prc;	// 매도3단계우선호가가격,예) 999999.99
	int s_lvl_3_q;	// 매도3단계우선호가잔량
	double s_lvl_4_prc;	// 매도4단계우선호가가격,예) 999999.99
	int s_lvl_4_q;	// 매도4단계우선호가잔량
	double s_lvl_5_prc;	// 매도5단계우선호가가격,예) 999999.99
	int s_lvl_5_q;	// 매도5단계우선호가잔량
	int total_l_trd_cnt;	// 매수유효호가건수
	int l_lvl_1_trd_cnt;	// 매수1단계우선호가건수
	int l_lvl_2_trd_cnt;	// 매수2단계우선호가건수
	int l_lvl_3_trd_cnt;	// 매수3단계우선호가건수
	int l_lvl_4_trd_cnt;	// 매수4단계우선호가건수
	int l_lvl_5_trd_cnt;	// 매수5단계우선호가건수
	int total_s_trd_cnt;	// 매도유효호가건수
	int s_lvl_1_trd_cnt;	// 매도1단계우선호가건수
	int s_lvl_2_trd_cnt;	// 매도2단계우선호가건수
	int s_lvl_3_trd_cnt;	// 매도3단계우선호가건수
	int s_lvl_4_trd_cnt;	// 매도4단계우선호가건수
	int s_lvl_5_trd_cnt;	// 매도5단계우선호가건수
	double real_t_high_prc;	// 실시간상한가,예) 999999.99 개발가이드참조
	double real_t_low_prc;	// 실시간하한가,예) 999999.99 개발가이드참조
} DF_COM_FUT_EXEC_LIMIT_ORD;


// 상품선물_종목마감
typedef struct _DF_COM_FUT_CLOSE_PRODUCT {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA구분,A6
	char info_clsf[3];	// 정보구분,01:상품선물
	char mrk_clsf;	// 시장구분,6
	char isin_clsf[13];	// 종목코드,*개발가이드 참조 : 신국채선물 추가\n 2010.10.25
	int stk_snr;	// 종목일련번호
	char brd_id[3];	// 보드ID,코드값모음참조
	double close_prc;	// 종가,* 거래무 종목의 경우 기준가 set, 예) 999999.99
	char close_prc_code;	// 종가구분코드,1:실세, 3:거래무\n 2:기세 -2012.05.14 삭제\n ' ':정규장이 아닌 경우 space
	int accm_exe_q;	// 누적체결수량
	double accm_trd_amt;	// 누적거래대금(단위:원)
	int total_l_limit_ord_q;	// 매수총호가잔량
	double l_lvl_1_prc;	// 매수1단계우선호가가격,예) 999999.99
	int l_lvl_1_q;	// 매수1단계우선호가잔량
	double l_lvl_2_prc;	// 매수2단계우선호가가격,예) 999999.99
	int l_lvl_2_q;	// 매수2단계우선호가잔량
	double l_lvl_3_prc;	// 매수3단계우선호가가격,예) 999999.99
	int l_lvl_3_q;	// 매수3단계우선호가잔량
	double l_lvl_4_prc;	// 매수4단계우선호가가격,예) 999999.99
	int l_lvl_4_q;	// 매수4단계우선호가잔량
	double l_lvl_5_prc;	// 매수5단계우선호가가격,예) 999999.99
	int l_lvl_5_q;	// 매수5단계우선호가잔량
	int total_s_limit_ord_q;	// 매도총호가잔량
	double s_lvl_1_prc;	// 매도1단계우선호가가격,예) 999999.99
	int s_lvl_1_q;	// 매도1단계우선호가잔량
	double s_lvl_2_prc;	// 매도2단계우선호가가격,예) 999999.99
	int s_lvl_2_q;	// 매도2단계우선호가잔량
	double s_lvl_3_prc;	// 매도3단계우선호가가격,예) 999999.99
	int s_lvl_3_q;	// 매도3단계우선호가잔량
	double s_lvl_4_prc;	// 매도4단계우선호가가격,예) 999999.99
	int s_lvl_4_q;	// 매도4단계우선호가잔량
	double s_lvl_5_prc;	// 매도5단계우선호가가격,예) 999999.99
	int s_lvl_5_q;	// 매도5단계우선호가잔량
	int total_l_trd_cnt;	// 매수유효호가건수
	int l_lvl_1_trd_cnt;	// 매수1단계우선호가건수
	int l_lvl_2_trd_cnt;	// 매수2단계우선호가건수
	int l_lvl_3_trd_cnt;	// 매수3단계우선호가건수
	int l_lvl_4_trd_cnt;	// 매수4단계우선호가건수
	int l_lvl_5_trd_cnt;	// 매수5단계우선호가건수
	int total_s_trd_cnt;	// 매도유효호가건수
	int s_lvl_1_trd_cnt;	// 매도1단계우선호가건수
	int s_lvl_2_trd_cnt;	// 매도2단계우선호가건수
	int s_lvl_3_trd_cnt;	// 매도3단계우선호가건수
	int s_lvl_4_trd_cnt;	// 매도4단계우선호가건수
	int s_lvl_5_trd_cnt;	// 매도5단계우선호가건수
} DF_COM_FUT_CLOSE_PRODUCT;


// 상품선물_장운영TS
typedef struct _DF_COM_FUT_MRK_OP_TS {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA구분,A7
	char info_clsf[3];	// 정보구분,01:상품선물
	char mrk_clsf;	// 시장구분,6
	char isin_clsf[13];	// 종목코드
	int stk_snr;	// 종목일련번호
	char prd_id[12];	// 상품ID,코드값모음참조 : space처리
	char brd_id[3];	// 보드ID,코드값모음참조
	char brd_event_id[4];	// 보드이벤트ID,코드값모음참조
	char brd_event_start_t[9];	// 보드이벤트시작시각,고정된 상수값(예:BB1(매매거래개시)의 경우 09000000)
	int brd_event_code;	// 보드이벤트적용군코드,코드값모음 참조
	char ss_id[3];	// 세션ID,코드값모음참조
	char ord_exist;	// 호가유무,0:호가없음(이하항목 무시), 1:호가있음(이하항목 사용)
	int total_l_limit_ord_q;	// 매수총호가잔량
	double l_lvl_1_prc;	// 매수1단계우선호가가격,예) 999999.99
	int l_lvl_1_q;	// 매수1단계우선호가잔량
	double l_lvl_2_prc;	// 매수2단계우선호가가격,예) 999999.99
	int l_lvl_2_q;	// 매수2단계우선호가잔량
	double l_lvl_3_prc;	// 매수3단계우선호가가격,예) 999999.99
	int l_lvl_3_q;	// 매수3단계우선호가잔량
	double l_lvl_4_prc;	// 매수4단계우선호가가격,예) 999999.99
	int l_lvl_4_q;	// 매수4단계우선호가잔량
	double l_lvl_5_prc;	// 매수5단계우선호가가격,예) 999999.99
	int l_lvl_5_q;	// 매수5단계우선호가잔량
	int total_s_limit_ord_q;	// 매도총호가잔량
	double s_lvl_1_prc;	// 매도1단계우선호가가격,예) 999999.99
	int s_lvl_1_q;	// 매도1단계우선호가잔량
	double s_lvl_2_prc;	// 매도2단계우선호가가격,예) 999999.99
	int s_lvl_2_q;	// 매도2단계우선호가잔량
	double s_lvl_3_prc;	// 매도3단계우선호가가격,예) 999999.99
	int s_lvl_3_q;	// 매도3단계우선호가잔량
	double s_lvl_4_prc;	// 매도4단계우선호가가격,예) 999999.99
	int s_lvl_4_q;	// 매도4단계우선호가잔량
	double s_lvl_5_prc;	// 매도5단계우선호가가격,예) 999999.99
	int s_lvl_5_q;	// 매도5단계우선호가잔량
	int total_l_trd_cnt;	// 매수유효호가건수
	int l_lvl_1_trd_cnt;	// 매수1단계우선호가건수
	int l_lvl_2_trd_cnt;	// 매수2단계우선호가건수
	int l_lvl_3_trd_cnt;	// 매수3단계우선호가건수
	int l_lvl_4_trd_cnt;	// 매수4단계우선호가건수
	int l_lvl_5_trd_cnt;	// 매수5단계우선호가건수
	int total_s_trd_cnt;	// 매도유효호가건수
	int s_lvl_1_trd_cnt;	// 매도1단계우선호가건수
	int s_lvl_2_trd_cnt;	// 매도2단계우선호가건수
	int s_lvl_3_trd_cnt;	// 매도3단계우선호가건수
	int s_lvl_4_trd_cnt;	// 매도4단계우선호가건수
	int s_lvl_5_trd_cnt;	// 매도5단계우선호가건수
	double real_t_high_prc;	// 실시간상한가,예) 999999.99 개발가이드참조
	double real_t_low_prc;	// 실시간하한가,예) 999999.99 개발가이드참조
} DF_COM_FUT_MRK_OP_TS;


// 상품선물_마감
typedef struct _DF_COM_FUT_CLOSE {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA구분,H0
	char info_clsf[3];	// 정보구분,01:상품선물
	char mrk_clsf;	// 시장구분,6
} DF_COM_FUT_CLOSE;


// 상품선물_장운영스케줄공개
typedef struct _DF_COM_FUT_MRK_OP_SCHD {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA구분,M4
	char info_clsf[3];	// 정보구분,01:상품선물
	char mrk_clsf;	// 시장구분,6
	char isin_clsf[13];	// 종목코드,*개별종목 장운영 조치시 등록
	char stk_snr[4];	// 종목일련번호,*개별종목 장운영 조치시 등록
	char prd_id[12];	// 상품ID,코드값모음참조 : space처리
	char mrk_prd_id[4];	// 장운영상품그룹ID,*코드값모음참조
	char brd_id[3];	// 보드ID,코드값모음참조
	char brd_event_id[4];	// 보드이벤트ID,코드값모음참조
	char brd_event_start_t[9];	// 보드이벤트시작시각
	int brd_event_code;	// 보드이벤트적용군코드,코드값모음 참조
	char ss_open_close_code[3];	// 세션개시종료코드,BS:보드개시\n BE:보드종료\n SS:세션개시\n SE:세션종료\n SH:세션정지\n SR:세션재개
	char ss_id[3];	// 세션ID,코드값모음참조
	int adj_stage;	// 적용단계,해당사항없음
	char under_asset_prc_chg;	// 기준종목가격확대발생코드,해당사항없음
	char exp_prc_chg_t[9];	// 가격확대예정시각,해당사항없음
} DF_COM_FUT_MRK_OP_SCHD;


// 상품선물_배분정보
typedef struct _DF_COM_FUT_DIST_INFO {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA구분,O6
	char info_clsf[3];	// 정보구분,01:상품선물
	char mrk_clsf;	// 시장구분,6
	char isin_clsf[13];	// 종목코드
	int stk_snr;	// 종목일련번호
	char brd_id[3];	// 보드ID,코드값모음참조
	char dist_adj_code;	// 배분적용구분코드,1:배분개시, 2:배분해제
	char dist_code;	// 배분처리구분코드,1:매수상한, 2:매수하한,\n 3:매도상한, 4:매도하한\n *배분해제시 코드없음(space처리)
	char dist_cls_t[9];	// 배분해제시각
} DF_COM_FUT_DIST_INFO;


// 상품선물_실시간상하한가 적용및해제
typedef struct _DF_COM_FUT_REAL_HIGH_LOW_LIMIT_ON_OFF {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA구분,Q2
	char info_clsf[3];	// 정보구분,01:상품선물
	char mrk_clsf;	// 시장구분,6
	char isin_clsf[13];	// 종목코드
	int stk_snr;	// 종목일련번호
	char brd_id[3];	// 보드ID,코드값모음참조
	char cleared_t[9];	// 처리시각
	char real_t_prc_limit_code;	// 실시간가격제한설정코드,0: 해제, 1: 설정, 2: 재설정
	double real_t_high_prc;	// 실시간상한가,예) 999999.99 개발가이드참조
	double real_t_low_prc;	// 실시간하한가,예) 999999.99 개발가이드참조
} DF_COM_FUT_REAL_HIGH_LOW_LIMIT_ON_OFF;


// 상품선물_미결제약정수량 데이터
typedef struct _DF_COM_FUT_OPEN_INTEREST_DATA {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA구분,H2
	char info_clsf[3];	// 정보구분,01:상품선물
	char mrk_clsf;	// 시장구분,6
	char isin_clsf[13];	// 종목코드,최종 record '999999999999' set\n*개발가이드 참조 : 신국채선물 추가
	int stk_snr;	// 종목SEQ
	char open_interest_clsf[3];	// 미결제약정구분,전일 확정 : "M0" (07:40분경 제공)\n당일 잠정 : "M1" (장중 특정간격으로 변동종목\n         송신, 10초)\n당일 확정 : "M2" (당일 전종목 송신,\n         장종료 1시간후 제공)
	char traded_date[9];	// 거래일자
	int open_interest_q;	// 미결제약정수량,단위:계약
} DF_COM_FUT_OPEN_INTEREST_DATA;


// 상품선물_정산가격 데이터
typedef struct _DF_COM_FUT_SETT_PRC_DATA {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA구분,H3
	char info_clsf[3];	// 정보구분,01:상품선물
	char mrk_clsf;	// 시장구분,6
	char isin_clsf[13];	// 종목코드,최종 record '999999999999' set\n*개발가이드 참조 : 신국채선물 추가
	int stk_snr;	// 종목SEQ,돈육선물 - 최종거래일이 지난 종목은 0으로 전송
	double calc_prc;	// 정산가격,돈육선물 - 최종거래일이 지난 종목은 0으로 전송\n예) 99999999.99999999
	char calc_prc_clsf;	// 정산가격구분,돈육선물 - 최종거래일이 지난 종목은 공백으로 전송\n0 : 정산가 없슴(최초 거래성립전 기세 포함)\n1 : 당일 종가(실세)\n2 : 당일 기세(최초 거래성립후 기세) - 2010.12.20 삭제\n3 : 전일 정산가(최초 거래성립후 종가 미형성) - 2010.12.20 삭제\n4 : 당일 이론가(최초 거래성립후 종가 미형성)\n5 : 스프레드거래에 의해 생성된 월물의 종가 - 2010.12.20 삭제\n6 : 조정된 전일 정산가 - 2010.12.20 삭제\n7 : 대상자산 종가(이론가없는상품)\n8 : 정산기준가격 - 2010.12.20 추가
	double final_sett_prc;	// 최종결제가격,예) 99999999.99999999
	char final_sett_clsf;	// 최종결제가격구분
} DF_COM_FUT_SETT_PRC_DATA;


// 상품선물_투자자 데이터
typedef struct _DF_COM_FUT_INVESTOR_DATA {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA구분,H1
	char info_clsf[3];	// 정보구분,01:상품선물
	char mrk_clsf;	// 시장구분,6
	char created_date[9];	// 생성일자
	char created_time[7];	// 생성시각
	char inv_data_clsf[3];	// 데이터구분,*전일확정 : 00, 당일잠정 : 01, 당일확정 : 02\n *E1 : 장중 데이터 완료, E2 : 확정 데이터 완료\n 최종 record '99' set
	char prd_id[12];	// 상품ID,코드값모음참조
	char inv_clsf[5];	// 투자자유형,코드값모음 참조 *코드 '7000'시 수량,대금정보항목 0으로 전송
	int long_exe_q;	// 매수약정수량
	int short_exe_q;	// 매도약정수량
	double long_traded_amt;	// 매수약정대금
	double short_traded_amt;	// 매도약정대금
	int spread_long_exe_q;	// 스프레드에 의해 생성된 매수 약정수량
	int spread_short_exe_q;	// 스프레드에 의해 생성된 매도 약정수량
	double spread_long_traded_amt;	// 스프레드에 의해 생성된 매수 약정대금
	double spread_short_traded_amt;	// 스프레드에 의해 생성된 매도 약정대금
} DF_COM_FUT_INVESTOR_DATA;


// 상품선물_시세Recovery 데이터
typedef struct _DF_COM_FUT_RECOVERY_DATA {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA구분,B2
	char info_clsf[3];	// 정보구분,01:상품선물
	char mrk_clsf;	// 시장구분,6
	char isin_clsf[13];	// 종목코드,*개발가이드 참조 : 신국채선물 추가
	int stk_snr;	// 종목일련번호
	double cur_prc;	// 현재가,예) 999999.99
	double rct_prd_prc;	// 최근월물의제약정가격,예) 999999.99
	double nxt_prd_prc;	// 원월물의제약정가격,예) 999999.99
	double init_prc;	// 시가,예) 999999.99
	double high_prc;	// 고가,예) 999999.99
	double low_prc;	// 저가,예) 999999.99
	int open_interest_q;	// 미결제량
	int accm_exe_q;	// 누적체결수량
	double accm_trd_amt;	// 누적거래대금,단위:원
	char l_or_s;	// 최종매도매수구분코드,1:매도,2:매수(최종으로 들어온 호가의 매도매수구분값)
	double s_lvl_1_prc;	// 매도1호가,예) 999999.99
	int s_lvl_1_q;	// 매도1호가수량
	int s_lvl_1_trd_cnt;	// 매도1호가건수
	double l_lvl_1_prc;	// 매수1호가,예) 999999.99
	int l_lvl_1_q;	// 매수1호가수량
	int l_lvl_1_trd_cnt;	// 매수1호가건수
	double s_lvl_2_prc;	// 매도2호가,예) 999999.99
	int s_lvl_2_q;	// 매도2호가수량
	int s_lvl_2_trd_cnt;	// 매도2호가건수
	double l_lvl_2_prc;	// 매수2호가,예) 999999.99
	int l_lvl_2_q;	// 매수2호가수량
	int l_lvl_2_trd_cnt;	// 매수2호가건수
	double s_lvl_3_prc;	// 매도3호가,예) 999999.99
	int s_lvl_3_q;	// 매도3호가수량
	int s_lvl_3_trd_cnt;	// 매도3호가건수
	double l_lvl_3_prc;	// 매수3호가,예) 999999.99
	int l_lvl_3_q;	// 매수3호가수량
	int l_lvl_3_trd_cnt;	// 매수3호가건수
	double s_lvl_4_prc;	// 매도4호가,예) 999999.99
	int s_lvl_4_q;	// 매도4호가수량
	int s_lvl_4_trd_cnt;	// 매도4호가건수
	double l_lvl_4_prc;	// 매수4호가,예) 999999.99
	int l_lvl_4_q;	// 매수4호가수량
	int l_lvl_4_trd_cnt;	// 매수4호가건수
	double s_lvl_5_prc;	// 매도5호가,예) 999999.99
	int s_lvl_5_q;	// 매도5호가수량
	int s_lvl_5_trd_cnt;	// 매도5호가건수
	double l_lvl_5_prc;	// 매수5호가,예) 999999.99
	int l_lvl_5_q;	// 매수5호가수량
	int l_lvl_5_trd_cnt;	// 매수5호가건수
	int total_s_limit_ord_q;	// 매도 총호가수량
	int total_s_trd_cnt;	// 매도유효호가건수
	int total_l_limit_ord_q;	// 매수 총호가수량
	int total_l_trd_cnt;	// 매수유효호가건수
	char ss_id[3];	// 세션ID,코드값모음참조
	char brd_id[3];	// 보드ID,코드값모음참조
	char brd_event_id[4];	// 보드이벤트ID,B2 에서는 보드이벤트ID 사용금지(과거 상태값이 전송될 수 있음). 추후, 해당 항목 '000' 세팅 예정. 2014.03.24)
	double exp_prc;	// 예상체결가격,예) 999999.99 단일가매매시만 제공\n (장상태구분코드:10,20,30,80)
	double real_t_high_prc;	// 실시간상한가,예) 999999.99 개발가이드참조
	double real_t_low_prc;	// 실시간하한가,예) 999999.99 개발가이드참조
} DF_COM_FUT_RECOVERY_DATA;


// 상품선물_종목정보 데이터
typedef struct _DF_COM_FUTRE_PRD_INFO_DATA {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA구분,A0
	char info_clsf[3];	// 정보구분,01:상품선물
	char mrk_clsf;	// 시장구분,6
	int prd_cnt;	// 종목수
	char trd_date[9];	// 영업일자(입회일자)
	char isin_clsf[13];	// 종목코드,최종 record '999999999999' set\n*개발가이드 참조 : 신국채선물 추가
	int stk_snr;	// 종목SEQ
	char prd_id[12];	// 상품ID,* 코드값 모음집 참조\n* 구명칭: 파생상품ID\n10 => 11, 20140303
	char sh_prd_code[10];	// 종목단축코드,에) KR4101C90009 → K101C9000
	char prd_name_kor[81];	// 종목한글명
	char sh_prd_name_kor[41];	// 종목한글약명
	char prd_name_eng[81];	// 종목영문명
	char sh_prd_name_eng[41];	// 종목영문약명
	char listing_date[9];	// 상장일자,*개발가이드 내용추가    2009.08.31
	char de_listing_date[9];	// 상장폐지일자
	char spread_clsf_code;	// 스프레드기준종목구분코드,스프레드의 기준이 되는 종목의 ISIN 표준코드\n--코드값--\nF: 원월물(시간스프레드)\nN: 근월물(시간스프레드)\n20140303
	char final_sett_code;	// 최종결제방법코드,현금결제, 실물인수도결제 등 파생상품의 최종결제 방법\n--코드값--\nC: 현금결제\nD: 실물인수도결제\nA: 현금+실물인수도결제\n0: 해당없음\n20140303
	char prc_limit_exp_dir;	// 가격제한확대적용방향코드,가격제한이 다단계로 정의되는 경우 다음 단계로 확대되는 요건을 충족할 때 확대를 수행하는 방향\n## 코드값##\nX:미적용\nF:정방향\nB:역방향\nT:양방향
	int prc_limit_final_stg;	// 가격제한최종단계,가격제한이 다단계로 정의되는 경우 제한의 최종단계번호
	double prc_limit_stg_1_high_prc;	// 가격제한1단계상한가,예) 9999999999.99
	double prc_limit_stg_1_low_prc;	// 가격제한1단계하한가,예) 9999999999.99
	double prc_limit_stg_2_high_prc;	// 가격제한2단계상한가,예) 9999999999.99
	double prc_limit_stg_2_low_prc;	// 가격제한2단계하한가,예) 9999999999.99
	double prc_limit_stg_3_high_prc;	// 가격제한3단계상한가,예) 9999999999.99
	double prc_limit_stg_3_low_prc;	// 가격제한3단계하한가,예) 9999999999.99
	double stand_prc;	// 기준가,예) 9999999999.99
	char under_asset_id[4];	// 기초자산ID,예) K2I:KOSPI200지수, KQI:코스닥150지수,\n   Sxx:개별주식, BM3:신3년국채,\n   BM5:신5년국채, BMA:신10년국채, \n   CDR:CD, USD:미국달러, JPY:일본엔,\n   EUR:유럽유로,\n   GLD:금, LHG:돈육\n20140303
	char opt_type_code;	// 권리행사유형코드,A:미국형,E:유럽형,B:버뮤다형,Z:기타\n20140303
	char spread_str_code[3];	// 스프레드구성코드,Combination 호가를 대체할 스프레드물의 종목구성.\n--코드값--\n- T1: 최근월물+2째월물\n      > T2, T3, T4, ...\n*구명칭: 스프레드유형코드\n20140303
	char spread_prd_code_1[13];	// 스프레드구성종목코드1,* 구명칭: 스프레드근월물 종목코드\n근월물 표준코드\n20140303
	char spread_prd_code_2[13];	// 스프레드구성종목코드2,* 구명칭 : 스프레드원월물 종목코드\n원월물 표준코드\n20140303
	char last_trading_date[9];	// 최종거래일자
	char final_sett_date[9];	// 최종결제일자
	int cont_month_nbr;	// 결제월번호,* 구명칭: 월물구분코드\n1:최근월물,선물스프레드\n2:2째월물\n3:3째월물\n4:4째월물\n5:5째월물\n6:6째월물\n7:7째월물      구 최근월물여부 대치\nX => 9, 1 => 3, 20140303
	char maturity_date[9];	// 만기일자,권리행사 가능한 최종일자
	double exe_prc;	// 행사가격,예) 999999999.99999999
	char adjust_clsf_code;	// 조정구분코드,기초자산의 기준가격 조정이 정배수 조정(미결제조정)인지 비정배수 조정(거래승수조정)인지의 구분\n--코드값--\nN: 정상\nO: 미결제조정\nC: 거래승수조정\n20140303
	double prd_unit;	// 거래단위,1계약에 해당하는 기초자산수량\n예) 999999999.99999999
	double multiplier;	// 거래승수,약정대금 및 결제시 사용하는 계산승수\n예) 9999999999999.99999999
	char mrk_cnst_code;	// 시장조성구분코드,0:미시장조성종목\n1:당일시장조성종목\n2:과거시장조성종목
	char listing_type_code;	// 상장유형코드,1:신규상장\n2:추가상장\n3:기존종목\n4:최초상장\n5:종목조정\n6:특별설정
	double atm_prc;	// 등가격,기초자산기준가격에 가장 가까운 행사가격\n예) 9999999999.99
	char adj_reason_code[3];	// 조정사유코드,00:해당사항없음, 01:권리락, 02:배당락,\n03:분배락, 04:권배락, 05:중간배당락,\n06:권리중간배당락, 99:기타
	char under_asset_prd_code[13];	// 기초자산종목코드
	double under_asset_close_prc;	// 기초자산종가,예) 9999999999.99
	int left_until_maturity;	// 잔존일수
	double adj_std_prc;	// 조정기준가격,주식파생상품의 기초주권 조정기준가격\n예) 999999999.99999999
	char std_prc_clsf_code[3];	// 기준가격구분코드,*선물\nspcace:기준가 없음(선물 스프레드종목)\n11:전일정산가\n12:전일기준가(거래성립전 종가미형성)\n13:당일이론가(거래성립전 종가미형성)\n14:전일기세(거래성립전 기세형성)\n  -2012.05.14 삭제\n15:당일이론가(거래성립전 기세형성)-\n  -2012.05.14 삭제\n16:조정된 전일정산가\n17:조정된 전일기준가\n  (거래성립전 종가미형성)\n18:조정된 전일기세(거래성립전 기세형성)\n  -2012.05.14 삭제\n19:전일 대상자산 종가(이론가없는 상품)\n*옵션\n21:전일증거금기준가\n22:전일기준가(거래성립전 종가미형성)\n23:당일이론가(거래성립전 종가미형성)\n24:전일기세(거래성립전 기세형성)\n  -2012.05.14 삭제\n25:조정된 전일증거금기준가\n26:조정된 전일기준가\n  (거래성립전 종가미형성)\n27:조정된 전일기세(거래성립전 기세형성)\n  -2012.05.14 삭제
	char trd_std_prc_clsf_code;	// 매매용기준가격구분코드,0:해당없음\n1:실세\n2:기세\n3:이론가\n4:대상자산종가\n*개발가이드 내용추가    2009.08.31
	double yest_adj_close_prc;	// 전일조정종가,주식파생상품의 조정종가\n예) 999999999.99999999
	char block_trd_clsf;	// 협의대량매매대상여부,Y:협의매매상품, N:대상아님\n가능품목:3년물국채선물, 미국달러선물,\n      유로선물, 엔선물
	double yest_mrg_std_prc;	// 전일증거금기준가격,예) 999999999.99999999
	char yest_mrg_std_prc_clsf_code[3];	// 전일증거금기준가격구분코드,*옵션\n20:증거금 기준가 없음\n21:당일종가(실세)\n22:당일기세(거래성립후기세)\n  -2012.05.14 삭제\n23:전일증거금기준가\n  (거래성립후 종가미형성)\n  -2012.05.14 삭제\n24:당일이론가(거래성립후 종가미형성)\n25:조정전일증거금기준가\n  (거래성립후 종가미형성)\n  -2012.05.14 삭제
	double sett_theory_prc;	// 정산이론가격,※옵션의 경우 증거금기준가용 \n예) 999999999.999999
	double std_theory_prc;	// 기준이론가격,예) 999999999.999999
	double yest_sett_prc;	// 전일정산가격,예) 999999999.99999999
	char halt_trd_clsf;	// 거래정지여부,Y, N
	double ft_cb_high_prc;	// 선물Circuit_Breakers상한가,선물 CB 발동조건을 판단하기 위한 상한\n가격(기준가대비 +/-5%가 CB 발동\n조건인 경우 +5%를 계산한 가격)\n예) 99+F31499999999.99
	double ft_cb_low_prc;	// 선물Circuit_Breakers하한가,선물 CB 발동조건을 판단하기 위한 상한\n가격(기준가대비 +/-5%가 CB 발동\n조건인 경우 -5%를 계산한 가격)\n예) 9999999999.99
	double check_exe_prc;	// 조회용행사가격,예) 999999999.99999999
	char atm_clsf;	// ATM구분코드,0:선물, 1:ATM, 2:ITM, 3:OTM
	char last_trading_clsf;	// 최종거래일여부,Y, N
	double ex_divid_aft_value;	// 배당락후배당가치,주식 및 주가지수 상품에만 적용됨\n- 선물 : 배당락후미래가치\n- 옵션 : 배당락후현재가치\n예) 999999999.999999
	double yest_close_prc;	// 전일종가,예) 9999999999.99
	char yest_close_prc_clsf;	// 전일종가구분코드,1:실세, 3:거래무\n2:기세 -2012.05.14 삭제
	double yest_init_prc;	// 전일시가,예) 9999999999.99
	double yest_high_pric;	// 전일고가,예) 9999999999.99
	double yest_low_prc;	// 전일저가,예) 9999999999.99
	char yest_first_exe_date[9];	// 최초체결일자
	char yest_last_exe_time[9];	// 전일최종체결시각
	char yest_sett_prc_clsf[3];	// 전일정산가격구분,*선물\n 10:정산가없음\n 11:당일종가(실세)\n 12:당일기세(거래성립후기세) - 2010.12.20 삭제\n 13:전일정산가(거래성립후 종가미형성) - 2010.12.20 삭제\n 14:당일이론가(거래성립후 종가미형성)\n 15:스프레드분 종가 - 2010.12.20 삭제\n 16:조정된 전일 정산가 - 2010.12.20 삭제\n 17:대상자산 종가(이론가없는 상품)\n 18:정산기준가격 - 2010.12.20 추가
	double sett_prc_theory_prc_diff_pctg;	// 정산가격이론가격괴리율,에) 999999.999999
	double yest_open_interest_q;	// 전일미결제약정수량
	double yest_s_limit_ord_prc;	// 전일매도우선호가가격,예) 9999999999.99
	double yest_l_limit_ord_prc;	// 전일매수우선호가가격,예) 9999999999.99
	double implied_vol;	// 내재변동성,예) 999999.9999
	double listed_high_prc;	// 상장중최고가,예) 9999999999.99
	double listed_low_prc;	// 상장중최저가,예) 9999999999.99
	double year_high_prc;	// 연중최고가,예) 9999999999.99
	double year_low_prc;	// 연중최저가,예) 9999999999.99
	char listed_high_prc_date[9];	// 상장중최고가일자
	char listed_low_prc_date[9];	// 상장중최저가일자
	char year_high_prc_date[9];	// 연중최고가일자
	char year_low_prc_date[9];	// 연중최저가일자
	int year_std_date;	// 연간기준일수
	int month_trd_date;	// 월간거래일수
	int year_trd_date;	// 연간거래일수
	double yest_exe_trd_cnt ;	// 전일체결건수
	double yest_exe_q;	// 전일체결수량,전일협의대량매매체결수량이 포함되지 않음
	double yest_trd_amt;	// 전일거래대금,전일협의대량매매거래대금이 포함되지 않음
	double yest_block_trd_exe_q;	// 전일협의대량합산체결수량,전일협의대량매매체결수량 => 전일협의대량합산체결수량 [전일체결수량+전일협의대량매매체결수량(협의대량+FLEX)] 2016.03.28 변경
	double yest_block_trd_total_amt;	// 전일협의대량합산거래대금,전일협의대량매매거래대금 => 전일협의대량합산거래대금 [전일거래대금+전일협의대량매매거래대금(협의대량+FLEX)] 2016.03.28 변경
	double cd_rate;	// CD금리,예) 999.999
	double open_interest_q;	// 미결제한도수량,*적용일에 적용되는 상품의 계좌별\n 미결제 한도 계약수. 미결제 한도가\n 적용되지 않은 상품은 0\n*주식선물에만 해당\n8 => 15, 20140303
	char product_cat[5];	// 소속 상품군,*주식선물/옵션에만 해당
	double product_cat_off_pctg;	// 상품군 옵셋율,*백분율로 표시\n*주식선물/옵션에만 해당예) 9999999.99\n5 => 9, 20140303
	int limit_ord_clsf_code;	// 지정가호가조건구분코드,호가의 체결 및 잔류조건. Bitwise 정의\n--코드값--\n1: FAS (Fill And Store)\n2: FOK (Fill Or Kill)\n3: FAK (Fill And Kill)\n\n* 지정가호가조건구분코드 BITWISE 정의\n향후 확장성을 위해 해당 10진수값을 2진수로 변환하여 처리요망(최대 16bit까지 사용가능)\n예 ) 지정가호가조건구분코드 값이 6이면\n    (십진수 6 -> 이진수 00000110)\n0번째 bit 0 -> 0 : FAS\n1번째 bit 1 -> 2 : FOK\n2번째 bit 1 -> 4 : FAK\n즉, FOK이면서 FAK를 수용한다는 의미 (FOK & FAK)\nX => 9, 1 => 5, 20140303
	int mrk_ord_clsf_code;	// 시장가호가조건구분코드,* 상동
	int cond_limit_ord_clsf_code;	// 조건부지정가호가조건구분코드,* 상동
	int best_limit_ord_clsf_code;	// 최유리지정가호가조건구분코드,* 상동
	char efp_clsf;	// EFP거래대상여부,Y, N, 상품선물만 해당  2009.08.31
	char flex_clsf;	// FLEX거래대상여부,Y, N, 상품선물만 해당  2009.08.31
	double yest_efp_exe_q;	// 전일EFP체결수량,상품선물만 해당       2009.08.31
	double yest_efp_trd_amount;	// 전일EFP거래대금,상품선물만 해당       2009.08.31
	char mkr_close_clsf;	// 휴장여부,휴장여부 (Y,N), 20121217
	char real_t_prc_limit_clsf;	// 실시간가격제한여부,직전 체결가격 대비 특정 범위를 초과하는 호가는 거부하도록 제한할지 여부(Y/N) 20140901
	double real_t_high_price_gap;	// 실시간상한가간격,직전 체결가격과 실시간상한가와의 간격\n실시간상한가 = 직전체결가격 + 실시간상한가간격\nex) 9999999999.99 20140901
	double real_t_low_price_gap;	// 실시간하한가간격,직전 체결가격과 실시간하한가와의 간격\n실시간하한가 = 직전체결가격 + 실시간하한가간격(음수)\nex) 9999999999.99 20140901
	char under_ass_mrk_id[4];	// 기초자산시장ID,기초자산시장ID는 기초자산이 KRX에 상장된 경우에만 채워짐.\nK200선물옵션:STK\n코스닥150선물:KSQ\n주식선물옵션:STK/KSQ\n상품선물옵션:SPACE\n변동성지수선물:STK\n섹터지수선물:STK\n미니K200선물옵션:STK
} DF_COM_FUTRE_PRD_INFO_DATA;


// 현물정보_국채_CD_데이터
typedef struct _DF_GOV_BOND_CD_DATA {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA구분,H5
	char info_clsf[3];	// 정보구분,01:상품선물,\n최종 record '99' set
	char mrk_clsf;	// 시장구분,6
	char send_date[9];	// 전송일자,YYYYMMDD
	char send_time[7];	// 전송시간,HHMMSS
	char uder_asset_clsf[7];	// 기초자산구분,BM3,BM5,BMA,CD,MSB   2010.10.25\n*항목명 변경\n 기초자산ID->기초자산구분  2009.08.31\n*MSB제공중단          2011.05.02
	double final_ord_return_pctg;	// 최종호가수익률,999.99999\nCD(91일),국채(3년,5년,10년)\n*MSB제공중단          2011.05.02
	char gov_bond_code[13];	// 국채코드,국채선물의 결재기준채권코드
	char gov_bond_prd_code[13];	// 국채선물종목코드
	char data_created_t[7];	// 데이터 발생시간,HHMMSS
} DF_GOV_BOND_CD_DATA;


// 현물정보_결제기준채권_데이터
typedef struct _DF_STD_GOV_BOND_DATA {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA구분,H6
	char info_clsf[3];	// 정보구분,01:상품선물,\n최종 record '99' set
	char mrk_clsf;	// 시장구분,6
	char adj_date[9];	// 적용일,익일자로 전송됨
	char prd[5];	// 상품,BM3,BM5,BMA   2010.10.25
	char fut_prd_code[13];	// 선물종목코드,익일 거래 대상인 종목
	char under_asset_bond_code[13];	// 채권코드,국채선물의 결재기준채권코드
	double conv_coef;	// 전환계수,인수도결제 국채선물인 경우만 해당됨\n예) 99.999999\n'00000000' 처리   2010.10.25
} DF_STD_GOV_BOND_DATA;


// 현물정보_USD_데이터
typedef struct _DF_USD_DATA {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA구분,H9
	char info_clsf[3];	// 정보구분,01:상품선물,\n최종 record '99' set
	char mrk_clsf;	// 시장구분,6
	char send_date[9];	// 전송일자,YYYYMMDD
	char send_time[7];	// 전송시간,HHMMSS
	char under_asset_id[7];	// 기초자산ID,USD
	double s_limit_ord_prc;	// 매도호가,예) 9999.99
	int l_limit_ord_prc;	// 매수호가
	int yest_close_prc;	// 전일종가
	int init_prc;	// 시가
	int low_prc;	// 저가
	int high_prc;	// 고가
	int exe_prc;	// 체결가
	char data_created_t[7];	// 데이터 발생시간,HHMMSS
} DF_USD_DATA;


// 현물정보_USD배치_데이터1
typedef struct _DF_USD_BATCH_DATA_1 {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA구분,I0
	char info_clsf[3];	// 정보구분,01:상품선물,\n최종 record '99' set
	char mrk_clsf;	// 시장구분,6
	char job_clsf_code[5];	// 업무구분코드,FBB1(원/달러 전일시간대별 거래현황)
	int trd_date;	// 거래일
	char trd_hour[10];	// 시간대,HHMM-HHMM
	double spread_low_rate;	// LOW RATE(SP),9999.9
	double spread_high_rate;	// HIGH RATE(SP),9999.9
	double spread_vol;	// VOLUME(SP),9999.9
} DF_USD_BATCH_DATA_1;


// 현물정보_USD배치_데이터2
typedef struct _DF_USD_BATCH_DATA_2 {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA구분,I0
	char info_clsf[3];	// 정보구분,01:상품선물,\n최종 record '99' set
	char mrk_clsf;	// 시장구분,6
	char job_clsf_code[5];	// 업무구분코드,FBC1(원/달러 전일 기일물별 체결현황1)
	int trd_date;	// 거래일,YYYYMMDD
	char fixed_date_clsf[3];	// 기일물구분,*기일물구분 참조
	int maturity_date;	// 만기일(결제일),YYYYMMDD
	double low_rate;	// LOW RATE,9999.99
	double high_rate;	// HIGH RATE,9999.99
	double open_rate;	// OPEN RATE,9999.99
	double close_rate;	// CLOSE RATE,9999.99
} DF_USD_BATCH_DATA_2;


// 현물정보_USD배치_데이터3
typedef struct _DF_USD_BATCH_DATA_3 {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA구분,I0
	char info_clsf[3];	// 정보구분,01:상품선물,\n최종 record '99' set
	char mrk_clsf;	// 시장구분,6
	char job_clsf_code[5];	// 업무구분코드,FBC2(원/달러 전일 기일물별 체결현황2)
	int trd_date;	// 거래일,YYYYMMDD
	char fixed_date_clsf[3];	// 기일물구분,*기일물구분 참조
	int maturity_date;	// 만기일(결제일),YYYYMMDD
	double vol;	// VOLUME,9999.9
	double avg_rate;	// AVERAGE RATE,9999.99
	double mar;	// MAR,9999.9
} DF_USD_BATCH_DATA_3;


// 현물정보_USD배치_데이터4
typedef struct _DF_USD_BATCH_DATA_4 {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA구분,I0
	char info_clsf[3];	// 정보구분,01:상품선물,\n최종 record '99' set
	char mrk_clsf;	// 시장구분,6
	char job_clsf_code[5];	// 업무구분코드,FBD1(환율고시 재정환율 현황)
	int informed_date;	// 고시일,YYYYMMDD
	char currency_name[4];	// 통화명,주)통화명 참조
	double cross_rate;	// CROSS RATE,9999.99999
	double fx_rate;	// 환율,9999.99
} DF_USD_BATCH_DATA_4;


// 현물정보_USD배치_데이터5
typedef struct _DF_USD_BATCH_DATA_5 {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA구분,I0
	char info_clsf[3];	// 정보구분,01:상품선물,\n최종 record '99' set
	char mrk_clsf;	// 시장구분,6
	char job_clsf_code[5];	// 업무구분코드,FBE1(SWAP 전일자 기일물별 체결현황)
	int trd_date;	// 거래일,YYYYMMDD
	char fixed_date_clsf[3];	// 기일물구분,주)기일물구분 참조
	int maturity_date;	// 만기일(결제일),YYYYMMDD
	int low_rate;	// LOW RATE,±9999
	int high_rate;	// HIGH RATE,±9999
	int open_rate;	// OPEN RATE,±9999
	int close_rate;	// CLOSE RATE,±9999
	int avg_rate;	// AVERAGE RATE,±9999
	double vol;	// VOLUME,9999.9
} DF_USD_BATCH_DATA_5;


// 현물정보_USD배치_데이터6
typedef struct _DF_USD_BATCH_DATA_6 {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA구분,I0
	char info_clsf[3];	// 정보구분,01:상품선물,\n최종 record '99' set
	char mrk_clsf;	// 시장구분,6
	char job_clsf_code[5];	// 업무구분코드,FBF1(원/달러 선도환율 : 통화선도환율방식)
	int std_date;	// 기준일,YYYYMMDD
	char fixed_date_clsf_0[3];	// 기일물구분,주)선도환율기일물구분 참조
	double rate_0;	// RATE,9999.99
	char fixed_date_clsf_1[3];	// 기일물구분,주)선도환율기일물구분 참조
	double rate_1;	// RATE,9999.99
	char fixed_date_clsf_2[3];	// 기일물구분,주)선도환율기일물구분 참조
	double rate_2;	// RATE,9999.99
	char fixed_date_clsf_3[3];	// 기일물구분,주)선도환율기일물구분 참조
	double rate_3;	// RATE,9999.99
} DF_USD_BATCH_DATA_6;


// 현물정보_USD배치_데이터7
typedef struct _DF_USD_BATCH_DATA_7 {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA구분,I0
	char info_clsf[3];	// 정보구분,01:상품선물,\n최종 record '99' set
	char mrk_clsf;	// 시장구분,6
	char job_clsf_code[5];	// 업무구분코드,FBF2(원/달러 선도 환율 : 스왑포인트 방식))
	int std_date;	// 기준일,YYYYMMDD
	char fixed_date_clsf_0[3];	// 기일물구분,주)선도환율기일물구분 참조
	double rate_0;	// RATE,9999.99
	char fixed_date_clsf_1[3];	// 기일물구분,주)선도환율기일물구분 참조
	double rate_1;	// RATE,9999.99
	char fixed_date_clsf_2[3];	// 기일물구분,주)선도환율기일물구분 참조
	double rate_2;	// RATE,9999.99
	char fixed_date_clsf_3[3];	// 기일물구분,주)선도환율기일물구분 참조
	double rate_3;	// RATE,9999.99
} DF_USD_BATCH_DATA_7;


// 현물정보_USD배치_데이터8
typedef struct _DF_USD_BATCH_DATA_8 {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA구분,I0
	char info_clsf[3];	// 정보구분,01:상품선물,\n최종 record '99' set
	char mrk_clsf;	// 시장구분,6
	char job_clsf_code[5];	// 업무구분코드,FBG1(월평균 기준환율)
	char informed_date[9];	// 고시일,YYYYMMDD
	double std_year_month;	// 기준년월,9999.99
	double avg_fx_rate;	// 평균기준환율,9999.99
} DF_USD_BATCH_DATA_8;


// 현물정보_USD배치_데이터9
typedef struct _DF_USD_BATCH_DATA_9 {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA구분,I0
	char info_clsf[3];	// 정보구분,01:상품선물,\n최종 record '99' set
	char mrk_clsf;	// 시장구분,6
	char job_clsf_code[5];	// 업무구분코드,CBA1(외화 전일 거래요약1)
	char trd_date[9];	// 거래일,YYYYMMDD
	char currency_name[4];	// 통화명,주)통화명 참조
	double open_rate;	// OPEN RATE,99.99999
	double high_rate;	// HIGH RATE,99.99999
	double low_rate;	// LOW RATE,99.99999
	double close_rate;	// CLOSE RATE,99.99999
} DF_USD_BATCH_DATA_9;


// 현물정보_USD배치_데이터10
typedef struct _DF_USD_BATCH_DATA_10 {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA구분,I0
	char info_clsf[3];	// 정보구분,01:상품선물,\n최종 record '99' set
	char mrk_clsf;	// 시장구분,6
	char job_clsf_code[5];	// 업무구분코드,CBA2(외화 전일 거래요약2)
	char trd_date[9];	// 거래일,YYYYMMDD
	char currency_name[4];	// 통화명,주)통화명 참조
	double ave_rate;	// AVERAGE RATE,99.9999
	double o_n_vol;	// O/N VOLUME,9999.99
	double total_vol;	// TOTAL VOLUME,9999.99
	double libor_rate;	// LIBOR,9.99999
	double sibor_rate;	// SIBOR,9.99999
} DF_USD_BATCH_DATA_10;


// 현물정보_USD실시간정보_데이터1
typedef struct _DF_USD_REAL_TIME_DATA_1 {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA구분,I1
	char info_clsf[3];	// 정보구분,01:상품선물,\n최종 record '99' set
	char mrk_clsf;	// 시장구분,6
	char job_clsf_code[5];	// 업무구분코드,FOC1(원/달러 시간대별 거래현황)
	int trd_date;	// 거래일,YYYYMMDD
	char trd_hour[10];	// 시간대,HHMM-HHMM
	double spread_low_rate;	// LOW RATE(SP),9999.99
	double spread_high_rate;	// HIGH RATE(SP),9999.99
} DF_USD_REAL_TIME_DATA_1;


// 현물정보_USD실시간정보_데이터2
typedef struct _DF_USD_REAL_TIME_DATA_2 {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA구분,I1
	char info_clsf[3];	// 정보구분,01:상품선물
	char mrk_clsf;	// 시장구분,6
	char job_clsf_code[5];	// 업무구분코드,FOD1(원/달러 기일물별 접수현황)
	int trd_date;	// 거래일,YYYYMMDD
	char fixed_date_clsf[3];	// 기일물구분,주)기일물구분참조
	int maturity_date;	// 만기일(결제일),YYYYMMDD
	double bid_best;	// BID BEST,9999.9
	double offer_best;	// OFFER BEST,9999.9
	double bid_vol;	// BID VOLUME,9999.9
	double offer_vol;	// OFFER VOLUME,9999.9
	double prev_rate;	// PREV RATE,9999.9
} DF_USD_REAL_TIME_DATA_2;


// 현물정보_USD실시간정보_데이터3
typedef struct _DF_USD_REAL_TIME_DATA_3 {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA구분,I1
	char info_clsf[3];	// 정보구분,01:상품선물
	char mrk_clsf;	// 시장구분,6
	char job_clsf_code[5];	// 업무구분코드,FOE1(원/달러 기일물별 체결현황) (접수->체결)변경
	int trd_date;	// 거래일,YYYYMMDD
	char fixed_date_clsf[3];	// 기일물구분,주)기일물구분참조
	int maturity_date;	// 만기일(결제일),YYYYMMDD
	double low_rate;	// LOW RATE,9999.9
	double high_rate;	// HIGH RATE,9999.9
	double open_rate;	// OPEN RATE,9999.9
	double close_rate;	// CLOSE RATE,9999.9
} DF_USD_REAL_TIME_DATA_3;


// 현물정보_CNH실시간정보_데이터
typedef struct _DF_CNH_REAL_TIME_DATA {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA구분,I1
	char info_clsf[3];	// 정보구분,01:상품선물
	char mrk_clsf;	// 시장구분,6
	char job_clsf_code[5];	// 업무구분코드,HOE1(원/위안 기일물별 체결현황)
	int trd_date;	// 거래일,YYYYMMDD
	char fixed_date_clsf[3];	// 기일물구분,주)기일물구분참조
	int maturity_date;	// 만기일(결제일),YYYYMMDD
	double low_rate;	// LOW RATE,9999.9
	double high_rate;	// HIGH RATE,9999.9
	double open_rate;	// OPEN RATE,9999.9
	double close_rate;	// CLOSE RATE,9999.9
} DF_CNH_REAL_TIME_DATA;


// 현물정보_USD실시간정보_데이터4
typedef struct _DF_USD_REAL_TIME_DATA_4 {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA구분,I1
	char info_clsf[3];	// 정보구분,01:상품선물
	char mrk_clsf;	// 시장구분,6
	char job_clsf_code[5];	// 업무구분코드,FOF1(SWAP 기일물별 접수현황)
	int trd_date;	// 거래일,YYYYMMDD
	char fixed_date_clsf[3];	// 기일물구분,주)기일물구분참조
	int maturity_date;	// 만기일(결제일),YYYYMMDD
	int bid_best;	// BID BEST,±9999
	int offer_best;	// OFFER BEST,±9999
	double bid_vol;	// BID VOLUME,9999.9
	double offer_vol;	// OFFER VOLUME,9999.9
	int prev_rate;	// PREV RATE,±9999
} DF_USD_REAL_TIME_DATA_4;


// 현물정보_USD실시간정보_데이터5
typedef struct _DF_USD_REAL_TIME_DATA_5 {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA구분,I1
	char info_clsf[3];	// 정보구분,01:상품선물
	char mrk_clsf;	// 시장구분,6
	char job_clsf_code[5];	// 업무구분코드,FOG1(SWAP 기일물별 체결현황)
	int trd_date;	// 거래일,YYYYMMDD
	char fixed_date_clsf[3];	// 기일물구분,주)기일물구분참조
	int maturity_date;	// 만기일(결제일),YYYYMMDD
	int low_rate;	// LOW RATE,±9999
	int high_rate;	// HIGH RATE,±9999
	int open_rate;	// OPEN RATE,±9999
	int close_rate;	// CLOSE RATE,±9999
} DF_USD_REAL_TIME_DATA_5;


// 현물정보_USD실시간정보_데이터8
typedef struct _DF_USD_REAL_TIME_DATA_8 {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA구분,I1
	char info_clsf[3];	// 정보구분,01:상품선물
	char mrk_clsf;	// 시장구분,6
	char job_clsf_code[5];	// 업무구분코드,UOD1(원달러 SPOT 대고객 환율호가)
	int trd_date;	// 거래일,YYYYMMDD
	char fixed_date_clsf[3];	// 기일물구분,주)기일물 구분
	int maturity_date;	// 만기일(결제일),YYYYMMDD
	char bank_name[11];	// 은행명,영문은행명
	double bid_best;	// BID BEST,9999.9
	double offer_best;	// OFFER BEST,9999.9
	double low_rate;	// LOW RATE,9999.9
	double high_rate;	// HIGH RATE,9999.9
	double open_rate;	// OPEN RATE,9999.9
	double mar;	// MAR,9999.9
} DF_USD_REAL_TIME_DATA_8;


// 현물정보_USD실시간정보_데이터7
typedef struct _DF_USD_REAL_TIME_DATA_7 {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA구분,I1
	char info_clsf[3];	// 정보구분,01:상품선물
	char mrk_clsf;	// 시장구분,6
	char job_clsf_code[5];	// 업무구분코드,COA1(외화 기일물별 접수현황)
	int trd_date;	// 거래일,YYYYMMDD
	char currency_name[4];	// 통화명,주)통화명 참조
	char fixed_date_clsf[3];	// 기일물 구분,주)기일물 구분
	double bid_rate;	// BID RATE,99999.99
	double offer_rate;	// OFFER RATE,99999.99
	double bid_vol;	// BID VOLUME,9999.99
	double offer_vol;	// OFFER VOLUME,9999.99
} DF_USD_REAL_TIME_DATA_7;


// 현물정보_USD실시간정보_데이터6
typedef struct _DF_USD_REAL_TIME_DATA_6 {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA구분,I1
	char info_clsf[3];	// 정보구분,01:상품선물
	char mrk_clsf;	// 시장구분,6
	char job_clsf_code[5];	// 업무구분코드,FOQ1(현물환 시간대별 BID-OFFER 호가 현황)
	int trd_date;	// 거래일,YYYYMMDD
	char td_hour[5];	// 시간대,HHMM
	double spread_bid_prc;	// BID 호가(SP),9999.9
	double spread_ask_prc;	// OFFER 호가(SP),9999.9
} DF_USD_REAL_TIME_DATA_6;


// 상품선물_Polling 데이터
typedef struct _DF_COM_FUT_POLLING_DATA {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA구분,I2
	char info_clsf[3];	// 정보구분,01:상품선물
	char mrk_clsf;	// 시장구분,6
	char send_time[5];	// 전송시간,HHSS
	char main_backup_clsf[3];	// Main Backup구분,space
} DF_COM_FUT_POLLING_DATA;


// 현물정보_USD실시간정보_데이터9
typedef struct _DF_USD_REAL_TIME_DATA_9 {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA구분,I1
	char info_clsf[3];	// 정보구분,01:상품선물
	char mrk_clsf;	// 시장구분,6
	char job_clsf_code[5];	// 업무구분코드,UOE1(원달러 SPOT 30분단위 행간 환율체결가)
	int trd_date;	// 거래일,YYYYMMDD
	char fixed_date_clsf[3];	// 기일물구분,SP
	int maturity_date;	// 만기일(결제일),YYYYMMDD
	int exe_t;	// 체결시간,HHMM(0930, 1000,1030,1100,1130,1200,1230,\n1300,1330,1400, 1430, 1500)
	double exe_prc;	// 체결가,9999.9
} DF_USD_REAL_TIME_DATA_9;


// 현물정보_돈육대표가격지수_데이터
typedef struct _DF_LEAN_HOG_REP_PRC_INDEX_DATA {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA구분,H8
	char info_clsf[3];	// 정보구분,01:상품선물
	char mrk_clsf;	// 시장구분,6
	char data_type;	// 데이터 타입,D:돈육 대표가격 지수
	char inform_date_yest[9];	// 공시일자-전일
	char inform_date_close_yest[9];	// 공시일자-직전일
	int accum_mrk_nbr;	// 집계도매시장수,개수
	int accum_prd_nbr;	// 집계두수,두
	double trd_weight_total;	// 거래 도체중 합계,kg
	double trd_prc_total;	// 거래 가격 합계,원
	int rep_prc;	// 대표 가격,원/kg
} DF_LEAN_HOG_REP_PRC_INDEX_DATA;


// 현물정보_돈육실시간가격지수_데이터
typedef struct _DF_LEAN_HOG_REAL_TIME_PRC_INDEX_DATA {
	double timestamp;	// timestamp
	char data_cslf[3];	// DATA구분,H8
	char info_clsf[3];	// 정보구분,01:상품선물
	char mrk_clsf;	// 시장구분,6
	char data_type;	// 데이터 타입,L:실시간 현물가격 지수
	char inform_time[5];	// 공시시간
	char inform_date_yest[9];	// 공시일자-전일
	char inform_date_today[9];	// 공시일자-당일
	int accum_mrk_nbr;	// 집계 도매시장 수,개수
	int accum_prd_nbr;	// 경락두수,두
	double trd_weight_total;	// 거래 도체중 합계,kg
	double trd_prc_total;	// 거래 가격 합계,원
	int under_asset_prc;	// 현물 가격,원/kg
} DF_LEAN_HOG_REAL_TIME_PRC_INDEX_DATA;


// 현물정보_돈육마감가격지수_데이터
typedef struct _DF_LEAN_HOG_CLOSE_PRICE_INDEX_DATA {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA구분,H8
	char info_clsf[3];	// 정보구분,01:상품선물,\n최종 record '99' set
	char mrk_clsf;	// 시장구분,6
	char data_type;	// 데이터 타입,E:실시간 현물가격 마감지수
	char inform_date_today[9];	// 공시일자 당일
	char inform_date_yest[9];	// 공시일자 전일
	int accum_mrk_nbr;	// 집계 도매시장 수
	int accum_prd_nbr;	// 집계 두수,개수
	double trd_weight_total;	// 거래 도체중 합계,두
	double trd_prc_total;	// 거래 가격 합계,kg
	int init_prc;	// 시작 가격,원
	int high_prc;	// 최고 가격,원/kg
	int low_prc;	// 최저 가격
	int close_prc;	// 최종 가격
} DF_LEAN_HOG_CLOSE_PRICE_INDEX_DATA;


// 상품선물_SPACE
typedef struct _DF_COM_FUT_SPACE {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA구분,G9
	char info_clsf[3];	// 정보구분,01:상품선물
	char mrk_clsf;	// 시장구분,6
} DF_COM_FUT_SPACE;
