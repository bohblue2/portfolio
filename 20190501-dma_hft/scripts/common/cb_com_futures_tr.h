// cb_com_futures_tr.h
// 상품선물 실시간 TR

#pragma once
// 주석에 \n이 들어간건 나중에 이쁘게 바꿔야함


// 상품선물_경쟁+협의합산
typedef struct _COM_FUT_COMP_BLOCK {
	char data_clsf[2];	// DATA구분,C4
	char info_clsf[2];	// 정보구분,01:상품선물
	char mkt_clsf[1];	// 시장구분,6
	char isin_clsf[12];	// 종목코드,*개발가이드 참조 : 신국채선물 추가\n 2010.10.25
	char stk_snr[7];	// 종목일련번호
	char cpt_block_trd_vol[12];	// 경쟁+협의합산 거래량,경쟁매매, 협의대량거래, EFP, FLEX 거래를 합산한 거래량
	char cpt_block_trd_amt[22];	// 경쟁+협의합산 거래대금,경쟁매매, 협의대량거래, EFP, FLEX 거래를 합산한 거래대금\n(단위 : 원)
	char ff[1];	// End of Text,0xFF
} COM_FUT_COMP_BLOCK;


// 상품선물_체결
typedef struct _COM_FUT_EXEC {
	char data_clsf[2];	// DATA구분,A3
	char info_clsf[2];	// 정보구분,01:상품선물
	char mkt_clsf[1];	// 시장구분,6
	char isin_clsf[12];	// 종목코드,*개발가이드 참조 : 신국채선물 추가\n 2010.10.25
	char stk_snr[3];	// 종목일련번호
	char brd_id[2];	// 보드ID,코드값모음참조
	char cur_prc_sign[1];	// 현재가격부호
	char cur_prc[8];	// 현재가격,예) 999999.99
	char exe_q[6];	// 체결수량
	char ss_id[2];	// 세션ID,코드값모음참조
	char exe_t[8];	// 체결시각
	char rct_prd_prc[8];	// 최근월물의제약정가격,예) 999999.99
	char nxt_prd_prc[8];	// 원월물의제약정가격,예) 999999.99
	char init_prc_sign[1];	// 시가부호
	char init_prc[8];	// 시가,예) 999999.99
	char high_prc_sign[1];	// 고가부호
	char high_prc[8];	// 고가,예) 999999.99
	char low_prc_sign[1];	// 저가부호
	char low_prc[8];	// 저가,예) 999999.99
	char pri_prc_sign[1];	// 직전가격부호
	char pri_prc[8];	// 직전가격,예) 999999.99
	char accm_exe_q[7];	// 누적체결수량
	char accm_trd_amt[15];	// 누적거래대금(단위:원)
	char accm_block_trd_exe_q[7];	// 협의대량누적체결수량,미제공(Filler)
	char efp_accm_exe_q[7];	// EFP누적체결수량,미제공(Filler)
	char l_or_s[1];	// 최종매도매수구분코드,1:매도,2:매수(최종으로 들어온 호가의 매도매수구분값)
	char real_t_high_prc_sign[1];	// 실시간상한가부호
	char real_t_high_prc[8];	// 실시간상한가,예) 999999.99 개발가이드참조
	char real_t_low_prc_sign[1];	// 실시간하한가부호
	char real_t_low_prc[8];	// 실시간하한가,예) 999999.99 개발가이드참조
	char ff[1];	// End of Text,0xFF
} COM_FUT_EXEC;


// 상품선물_우선호가
typedef struct _COM_FUT_LIMIT_ORD {
	char data_clsf[2];	// DATA구분,B6
	char info_clsf[2];	// 정보구분,01:상품선물
	char mkt_clsf[1];	// 시장구분,6
	char isin_clsf[12];	// 종목코드,*개발가이드 참조 : 신국채선물 추가\n 2010.10.25
	char stk_snr[3];	// 종목일련번호
	char brd_id[2];	// 보드ID,코드값모음참조
	char ss_id[2];	// 세션ID,코드값모음참조
	char total_l_limit_ord_q[7];	// 매수총호가잔량
	char l_lvl_1_sign[1];	// 매수1단계부호
	char l_lvl_1_prc[8];	// 매수1단계우선호가가격,예) 999999.99
	char l_lvl_1_q[6];	// 매수1단계우선호가잔량
	char l_lvl_2_sign[1];	// 매수2단계부호
	char l_lvl_2_prc[8];	// 매수2단계우선호가가격,예) 999999.99
	char l_lvl_2_q[6];	// 매수2단계우선호가잔량
	char l_lvl_3_sign[1];	// 매수3단계부호
	char l_lvl_3_prc[8];	// 매수3단계우선호가가격,예) 999999.99
	char l_lvl_3_q[6];	// 매수3단계우선호가잔량
	char l_lvl_4_sign[1];	// 매수4단계부호
	char l_lvl_4_prc[8];	// 매수4단계우선호가가격,예) 999999.99
	char l_lvl_4_q[6];	// 매수4단계우선호가잔량
	char l_lvl_5_sign[1];	// 매수5단계부호
	char l_lvl_5_prc[8];	// 매수5단계우선호가가격,예) 999999.99
	char l_lvl_5_q[6];	// 매수5단계우선호가잔량
	char total_s_limit_ord_q[7];	// 매도총호가잔량
	char s_lvl_1_sign[1];	// 매도1단계부호
	char s_lvl_1_prc[8];	// 매도1단계우선호가가격,예) 999999.99
	char s_lvl_1_q[6];	// 매도1단계우선호가잔량
	char s_lvl_2_sign[1];	// 매도2단계부호
	char s_lvl_2_prc[8];	// 매도2단계우선호가가격,예) 999999.99
	char s_lvl_2_q[6];	// 매도2단계우선호가잔량
	char s_lvl_3_sign[1];	// 매도3단계부호
	char s_lvl_3_prc[8];	// 매도3단계우선호가가격,예) 999999.99
	char s_lvl_3_q[6];	// 매도3단계우선호가잔량
	char s_lvl_4_sign[1];	// 매도4단계부호
	char s_lvl_4_prc[8];	// 매도4단계우선호가가격,예) 999999.99
	char s_lvl_4_q[6];	// 매도4단계우선호가잔량
	char s_lvl_5_sign[1];	// 매도5단계부호
	char s_lvl_5_prc[8];	// 매도5단계우선호가가격,예) 999999.99
	char s_lvl_5_q[6];	// 매도5단계우선호가잔량
	char total_l_trd_cnt[5];	// 매수유효호가건수
	char l_lvl_1_trd_cnt[4];	// 매수1단계우선호가건수
	char l_lvl_2_trd_cnt[4];	// 매수2단계우선호가건수
	char l_lvl_3_trd_cnt[4];	// 매수3단계우선호가건수
	char l_lvl_4_trd_cnt[4];	// 매수4단계우선호가건수
	char l_lvl_5_trd_cnt[4];	// 매수5단계우선호가건수
	char total_s_trd_cnt[5];	// 매도유효호가건수
	char s_lvl_1_trd_cnt[4];	// 매도1단계우선호가건수
	char s_lvl_2_trd_cnt[4];	// 매도2단계우선호가건수
	char s_lvl_3_trd_cnt[4];	// 매도3단계우선호가건수
	char s_lvl_4_trd_cnt[4];	// 매도4단계우선호가건수
	char s_lvl_5_trd_cnt[4];	// 매도5단계우선호가건수
	char ord_rcv_t[8];	// 호가접수시각
	char exp_prc_sign[1];	// 예상체결가격부호,999.99 단일가매매시만 제공\n (장상태구분코드:10,20,30,80)
	char exp_prc[8];	// 예상체결가격,예) 999999.99 단일가매매시만 제공\n (장상태구분코드:10,20,30,80)
	char ff[1];	// End of Text,0xFF
} COM_FUT_LIMIT_ORD;


// 상품선물_체결_우선호가
typedef struct _COM_FUT_EXEC_LIMIT_ORD {
	char data_clsf[2];	// DATA구분,G7
	char info_clsf[2];	// 정보구분,01:상품선물
	char mrk_clsf[1];	// 시장구분,6
	char isin_clsf[12];	// 종목코드,*개발가이드 참조 : 신국채선물 추가\n 2010.10.25
	char stk_snr[3];	// 종목일련번호
	char brd_id[2];	// 보드ID,코드값모음참조
	char cur_prc_sign[1];	// 현재가격부호
	char cur_price[8];	// 현재가격,예) 999999.99
	char exe_q[6];	// 체결수량
	char ss_id[2];	// 세션ID,코드값모음참조
	char exe_t[8];	// 체결시각
	char rct_prd_prc[8];	// 최근월물의제약정가격,예) 999999.99
	char nxt_prd_prc[8];	// 원월물의제약정가격,예) 999999.99
	char init_prc_sign[1];	// 시가부호
	char init_prc[8];	// 시가,예) 999999.99
	char high_prc_sign[1];	// 고가부호
	char high_prc[8];	// 고가,예) 999999.99
	char low_prc_sign[1];	// 저가부호
	char low_prc[8];	// 저가,예) 999999.99
	char pri_prc_sign[1];	// 직전가격부호
	char pri_prc[8];	// 직전가격,예) 999999.99
	char accm_exe_q[7];	// 누적체결수량
	char accm_trd_amt[15];	// 누적거래대금(단위:원)
	char accm_block_trd_exe_q[7];	// 협의대량누적체결수량,미제공(Filler)
	char efp_accm_exe_q[7];	// EFP누적체결수량,미제공(Filler)
	char l_or_s[1];	// 최종매도매수구분코드,1:매도,2:매수(최종으로 들어온 호가의 매도매수구분값)
	char total_l_limit_ord_q[7];	// 매수총호가잔량
	char l_lvl_1_sign[1];	// 매수1단계부호
	char l_lvl_1_prc[8];	// 매수1단계우선호가가격,예) 999999.99
	char l_lvl_1_q[6];	// 매수1단계우선호가잔량
	char l_lvl_2_sign[1];	// 매수2단계부호
	char l_lvl_2_prc[8];	// 매수2단계우선호가가격,예) 999999.99
	char l_lvl_2_q[6];	// 매수2단계우선호가잔량
	char l_lvl_3_sign[1];	// 매수3단계부호
	char l_lvl_3_prc[8];	// 매수3단계우선호가가격,예) 999999.99
	char l_lvl_3_q[6];	// 매수3단계우선호가잔량
	char l_lvl_4_sign[1];	// 매수4단계부호
	char l_lvl_4_prc[8];	// 매수4단계우선호가가격,예) 999999.99
	char l_lvl_4_q[6];	// 매수4단계우선호가잔량
	char l_lvl_5_sign[1];	// 매수5단계부호
	char l_lvl_5_prc[8];	// 매수5단계우선호가가격,예) 999999.99
	char l_lvl_5_q[6];	// 매수5단계우선호가잔량
	char total_s_limit_ord_q[7];	// 매도총호가잔량
	char s_lvl_1_sign[1];	// 매도1단계부호
	char s_lvl_1_prc[8];	// 매도1단계우선호가가격,예) 999999.99
	char s_lvl_1_q[6];	// 매도1단계우선호가잔량
	char s_lvl_2_sign[1];	// 매도2단계부호
	char s_lvl_2_prc[8];	// 매도2단계우선호가가격,예) 999999.99
	char s_lvl_2_q[6];	// 매도2단계우선호가잔량
	char s_lvl_3_sign[1];	// 매도3단계부호
	char s_lvl_3_prc[8];	// 매도3단계우선호가가격,예) 999999.99
	char s_lvl_3_q[6];	// 매도3단계우선호가잔량
	char s_lvl_4_sign[1];	// 매도4단계부호
	char s_lvl_4_prc[8];	// 매도4단계우선호가가격,예) 999999.99
	char s_lvl_4_q[6];	// 매도4단계우선호가잔량
	char s_lvl_5_sign[1];	// 매도5단계부호
	char s_lvl_5_prc[8];	// 매도5단계우선호가가격,예) 999999.99
	char s_lvl_5_q[6];	// 매도5단계우선호가잔량
	char total_l_trd_cnt[5];	// 매수유효호가건수
	char l_lvl_1_trd_cnt[4];	// 매수1단계우선호가건수
	char l_lvl_2_trd_cnt[4];	// 매수2단계우선호가건수
	char l_lvl_3_trd_cnt[4];	// 매수3단계우선호가건수
	char l_lvl_4_trd_cnt[4];	// 매수4단계우선호가건수
	char l_lvl_5_trd_cnt[4];	// 매수5단계우선호가건수
	char total_s_trd_cnt[5];	// 매도유효호가건수
	char s_lvl_1_trd_cnt[4];	// 매도1단계우선호가건수
	char s_lvl_2_trd_cnt[4];	// 매도2단계우선호가건수
	char s_lvl_3_trd_cnt[4];	// 매도3단계우선호가건수
	char s_lvl_4_trd_cnt[4];	// 매도4단계우선호가건수
	char s_lvl_5_trd_cnt[4];	// 매도5단계우선호가건수
	char real_t_high_prc_sign[1];	// 실시간상한가부호
	char real_t_high_prc[8];	// 실시간상한가,예) 999999.99 개발가이드참조
	char real_t_low_prc_sign[1];	// 실시간하한가부호
	char real_t_low_prc[8];	// 실시간하한가,예) 999999.99 개발가이드참조
	char ff[1];	// End of Text,0xFF
} COM_FUT_EXEC_LIMIT_ORD;


// 상품선물_종목마감
typedef struct _COM_FUT_CLOSE_PRODUCT {
	char data_clsf[2];	// DATA구분,A6
	char info_clsf[2];	// 정보구분,01:상품선물
	char mrk_clsf[1];	// 시장구분,6
	char isin_clsf[12];	// 종목코드,*개발가이드 참조 : 신국채선물 추가\n 2010.10.25
	char stk_snr[3];	// 종목일련번호
	char brd_id[2];	// 보드ID,코드값모음참조
	char close_prc_sign[1];	// 종가부호
	char close_prc[8];	// 종가,* 거래무 종목의 경우 기준가 set, 예) 999999.99
	char close_prc_code[1];	// 종가구분코드,1:실세, 3:거래무\n 2:기세 -2012.05.14 삭제\n ' ':정규장이 아닌 경우 space
	char accm_exe_q[7];	// 누적체결수량
	char accm_trd_amt[15];	// 누적거래대금(단위:원)
	char accm_block_trd_exe_q[7];	// 협의대량누적체결수량,미제공(Filler)
	char efp_accm_exe_q[7];	// EFP누적체결수량,미제공(Filler)
	char total_l_limit_ord_q[7];	// 매수총호가잔량
	char l_lvl_1_sign[1];	// 매수1단계부호
	char l_lvl_1_prc[8];	// 매수1단계우선호가가격,예) 999999.99
	char l_lvl_1_q[6];	// 매수1단계우선호가잔량
	char l_lvl_2_sign[1];	// 매수2단계부호
	char l_lvl_2_prc[8];	// 매수2단계우선호가가격,예) 999999.99
	char l_lvl_2_q[6];	// 매수2단계우선호가잔량
	char l_lvl_3_sign[1];	// 매수3단계부호
	char l_lvl_3_prc[8];	// 매수3단계우선호가가격,예) 999999.99
	char l_lvl_3_q[6];	// 매수3단계우선호가잔량
	char l_lvl_4_sign[1];	// 매수4단계부호
	char l_lvl_4_prc[8];	// 매수4단계우선호가가격,예) 999999.99
	char l_lvl_4_q[6];	// 매수4단계우선호가잔량
	char l_lvl_5_sign[1];	// 매수5단계부호
	char l_lvl_5_prc[8];	// 매수5단계우선호가가격,예) 999999.99
	char l_lvl_5_q[6];	// 매수5단계우선호가잔량
	char total_s_limit_ord_q[7];	// 매도총호가잔량
	char s_lvl_1_sign[1];	// 매도1단계부호
	char s_lvl_1_prc[8];	// 매도1단계우선호가가격,예) 999999.99
	char s_lvl_1_q[6];	// 매도1단계우선호가잔량
	char s_lvl_2_sign[1];	// 매도2단계부호
	char s_lvl_2_prc[8];	// 매도2단계우선호가가격,예) 999999.99
	char s_lvl_2_q[6];	// 매도2단계우선호가잔량
	char s_lvl_3_sign[1];	// 매도3단계부호
	char s_lvl_3_prc[8];	// 매도3단계우선호가가격,예) 999999.99
	char s_lvl_3_q[6];	// 매도3단계우선호가잔량
	char s_lvl_4_sign[1];	// 매도4단계부호
	char s_lvl_4_prc[8];	// 매도4단계우선호가가격,예) 999999.99
	char s_lvl_4_q[6];	// 매도4단계우선호가잔량
	char s_lvl_5_sign[1];	// 매도5단계부호
	char s_lvl_5_prc[8];	// 매도5단계우선호가가격,예) 999999.99
	char s_lvl_5_q[6];	// 매도5단계우선호가잔량
	char total_l_trd_cnt[5];	// 매수유효호가건수
	char l_lvl_1_trd_cnt[4];	// 매수1단계우선호가건수
	char l_lvl_2_trd_cnt[4];	// 매수2단계우선호가건수
	char l_lvl_3_trd_cnt[4];	// 매수3단계우선호가건수
	char l_lvl_4_trd_cnt[4];	// 매수4단계우선호가건수
	char l_lvl_5_trd_cnt[4];	// 매수5단계우선호가건수
	char total_s_trd_cnt[5];	// 매도유효호가건수
	char s_lvl_1_trd_cnt[4];	// 매도1단계우선호가건수
	char s_lvl_2_trd_cnt[4];	// 매도2단계우선호가건수
	char s_lvl_3_trd_cnt[4];	// 매도3단계우선호가건수
	char s_lvl_4_trd_cnt[4];	// 매도4단계우선호가건수
	char s_lvl_5_trd_cnt[4];	// 매도5단계우선호가건수
	char ff[1];	// End of Text,0xFF
} COM_FUT_CLOSE_PRODUCT;


// 상품선물_장운영TS
typedef struct _COM_FUT_MRK_OP_TS {
	char data_clsf[2];	// DATA구분,A7
	char info_clsf[2];	// 정보구분,01:상품선물
	char mrk_clsf[1];	// 시장구분,6
	char isin_clsf[12];	// 종목코드
	char stk_snr[3];	// 종목일련번호
	char prd_id[11];	// 상품ID,코드값모음참조 : space처리
	char brd_id[2];	// 보드ID,코드값모음참조
	char brd_event_id[3];	// 보드이벤트ID,코드값모음참조
	char brd_event_start_t[8];	// 보드이벤트시작시각,고정된 상수값(예:BB1(매매거래개시)의 경우 09000000)
	char brd_event_code[5];	// 보드이벤트적용군코드,코드값모음 참조
	char ss_id[2];	// 세션ID,코드값모음참조
	char ord_exist[1];	// 호가유무,0:호가없음(이하항목 무시), 1:호가있음(이하항목 사용)
	char total_l_limit_ord_q[7];	// 매수총호가잔량
	char l_lvl_1_sign[1];	// 매수1단계부호
	char l_lvl_1_prc[8];	// 매수1단계우선호가가격,예) 999999.99
	char l_lvl_1_q[6];	// 매수1단계우선호가잔량
	char l_lvl_2_sign[1];	// 매수2단계부호
	char l_lvl_2_prc[8];	// 매수2단계우선호가가격,예) 999999.99
	char l_lvl_2_q[6];	// 매수2단계우선호가잔량
	char l_lvl_3_sign[1];	// 매수3단계부호
	char l_lvl_3_prc[8];	// 매수3단계우선호가가격,예) 999999.99
	char l_lvl_3_q[6];	// 매수3단계우선호가잔량
	char l_lvl_4_sign[1];	// 매수4단계부호
	char l_lvl_4_prc[8];	// 매수4단계우선호가가격,예) 999999.99
	char l_lvl_4_q[6];	// 매수4단계우선호가잔량
	char l_lvl_5_sign[1];	// 매수5단계부호
	char l_lvl_5_prc[8];	// 매수5단계우선호가가격,예) 999999.99
	char l_lvl_5_q[6];	// 매수5단계우선호가잔량
	char total_s_limit_ord_q[7];	// 매도총호가잔량
	char s_lvl_1_sign[1];	// 매도1단계부호
	char s_lvl_1_prc[8];	// 매도1단계우선호가가격,예) 999999.99
	char s_lvl_1_q[6];	// 매도1단계우선호가잔량
	char s_lvl_2_sign[1];	// 매도2단계부호
	char s_lvl_2_prc[8];	// 매도2단계우선호가가격,예) 999999.99
	char s_lvl_2_q[6];	// 매도2단계우선호가잔량
	char s_lvl_3_sign[1];	// 매도3단계부호
	char s_lvl_3_prc[8];	// 매도3단계우선호가가격,예) 999999.99
	char s_lvl_3_q[6];	// 매도3단계우선호가잔량
	char s_lvl_4_sign[1];	// 매도4단계부호
	char s_lvl_4_prc[8];	// 매도4단계우선호가가격,예) 999999.99
	char s_lvl_4_q[6];	// 매도4단계우선호가잔량
	char s_lvl_5_sign[1];	// 매도5단계부호
	char s_lvl_5_prc[8];	// 매도5단계우선호가가격,예) 999999.99
	char s_lvl_5_q[6];	// 매도5단계우선호가잔량
	char total_l_trd_cnt[5];	// 매수유효호가건수
	char l_lvl_1_trd_cnt[4];	// 매수1단계우선호가건수
	char l_lvl_2_trd_cnt[4];	// 매수2단계우선호가건수
	char l_lvl_3_trd_cnt[4];	// 매수3단계우선호가건수
	char l_lvl_4_trd_cnt[4];	// 매수4단계우선호가건수
	char l_lvl_5_trd_cnt[4];	// 매수5단계우선호가건수
	char total_s_trd_cnt[5];	// 매도유효호가건수
	char s_lvl_1_trd_cnt[4];	// 매도1단계우선호가건수
	char s_lvl_2_trd_cnt[4];	// 매도2단계우선호가건수
	char s_lvl_3_trd_cnt[4];	// 매도3단계우선호가건수
	char s_lvl_4_trd_cnt[4];	// 매도4단계우선호가건수
	char s_lvl_5_trd_cnt[4];	// 매도5단계우선호가건수
	char real_t_high_prc_sign[1];	// 실시간상한가부호
	char real_t_high_prc[8];	// 실시간상한가,예) 999999.99 개발가이드참조
	char real_t_low_prc_sign[1];	// 실시간하한가부호
	char real_t_low_prc[8];	// 실시간하한가,예) 999999.99 개발가이드참조
	char ff[1];	// End of Text,0xFF
} COM_FUT_MRK_OP_TS;


// 상품선물_마감
typedef struct _COM_FUT_CLOSE {
	char data_clsf[2];	// DATA구분,H0
	char info_clsf[2];	// 정보구분,01:상품선물
	char mrk_clsf[1];	// 시장구분,6
	char ff[1];	// End of Text,0xFF
} COM_FUT_CLOSE;


// 상품선물_장운영스케줄공개
typedef struct _COM_FUT_MRK_OP_SCHD {
	char data_clsf[2];	// DATA구분,M4
	char info_clsf[2];	// 정보구분,01:상품선물
	char mrk_clsf[1];	// 시장구분,6
	char isin_clsf[12];	// 종목코드,*개별종목 장운영 조치시 등록
	char stk_snr[3];	// 종목일련번호,*개별종목 장운영 조치시 등록
	char prd_id[11];	// 상품ID,코드값모음참조 : space처리
	char mrk_prd_id[3];	// 장운영상품그룹ID,*코드값모음참조
	char brd_id[2];	// 보드ID,코드값모음참조
	char brd_event_id[3];	// 보드이벤트ID,코드값모음참조
	char brd_event_start_t[8];	// 보드이벤트시작시각
	char brd_event_code[5];	// 보드이벤트적용군코드,코드값모음 참조
	char ss_open_close_code[2];	// 세션개시종료코드,BS:보드개시\n BE:보드종료\n SS:세션개시\n SE:세션종료\n SH:세션정지\n SR:세션재개
	char ss_id[2];	// 세션ID,코드값모음참조
	char adj_stage[2];	// 적용단계,해당사항없음
	char under_asset_prc_chg[1];	// 기준종목가격확대발생코드,해당사항없음
	char exp_prc_chg_t[8];	// 가격확대예정시각,해당사항없음
	char ff[1];	// End of Text,0xFF
} COM_FUT_MRK_OP_SCHD;


// 상품선물_배분정보
typedef struct _COM_FUT_DIST_INFO {
	char data_clsf[2];	// DATA구분,O6
	char info_clsf[2];	// 정보구분,01:상품선물
	char mrk_clsf[1];	// 시장구분,6
	char isin_clsf[12];	// 종목코드
	char stk_snr[3];	// 종목일련번호
	char brd_id[2];	// 보드ID,코드값모음참조
	char dist_adj_code[1];	// 배분적용구분코드,1:배분개시, 2:배분해제
	char dist_code[1];	// 배분처리구분코드,1:매수상한, 2:매수하한,\n 3:매도상한, 4:매도하한\n *배분해제시 코드없음(space처리)
	char dist_cls_t[8];	// 배분해제시각
	char ff[1];	// End of Text,0xFF
} COM_FUT_DIST_INFO;


// 상품선물_실시간상하한가 적용및해제
typedef struct _COM_FUT_REAL_HIGH_LOW_LIMIT_ON_OFF {
	char data_clsf[2];	// DATA구분,Q2
	char info_clsf[2];	// 정보구분,01:상품선물
	char mrk_clsf[1];	// 시장구분,6
	char isin_clsf[12];	// 종목코드
	char stk_snr[3];	// 종목일련번호
	char brd_id[2];	// 보드ID,코드값모음참조
	char cleared_t[8];	// 처리시각
	char real_t_prc_limit_code[1];	// 실시간가격제한설정코드,0: 해제, 1: 설정, 2: 재설정
	char real_t_high_prc_sign[1];	// 실시간상한가부호
	char real_t_high_prc[8];	// 실시간상한가,예) 999999.99 개발가이드참조
	char real_t_low_prc_sign[1];	// 실시간하한가부호
	char real_t_low_prc[8];	// 실시간하한가,예) 999999.99 개발가이드참조
	char ff[1];	// End of Text,0xFF
} COM_FUT_REAL_HIGH_LOW_LIMIT_ON_OFF;


// 상품선물_미결제약정수량 데이터
typedef struct _COM_FUT_OPEN_INTEREST_DATA {
	char data_clsf[2];	// DATA구분,H2
	char info_clsf[2];	// 정보구분,01:상품선물
	char mrk_clsf[1];	// 시장구분,6
	char isin_clsf[12];	// 종목코드,최종 record '999999999999' set\n*개발가이드 참조 : 신국채선물 추가
	char stk_snr[3];	// 종목SEQ
	char open_interest_clsf[2];	// 미결제약정구분,전일 확정 : "M0" (07:40분경 제공)\n당일 잠정 : "M1" (장중 특정간격으로 변동종목\n         송신, 10초)\n당일 확정 : "M2" (당일 전종목 송신,\n         장종료 1시간후 제공)
	char traded_date[8];	// 거래일자
	char open_interest_q[9];	// 미결제약정수량,단위:계약
	char ff[1];	// End of Text,0xFF
} COM_FUT_OPEN_INTEREST_DATA;


// 상품선물_정산가격 데이터
typedef struct _COM_FUT_SETT_PRC_DATA {
	char data_clsf[2];	// DATA구분,H3
	char info_clsf[2];	// 정보구분,01:상품선물
	char mrk_clsf[1];	// 시장구분,6
	char isin_clsf[12];	// 종목코드,최종 record '999999999999' set\n*개발가이드 참조 : 신국채선물 추가
	char stk_snr[3];	// 종목SEQ,돈육선물 - 최종거래일이 지난 종목은 0으로 전송
	char calc_prc[16];	// 정산가격,돈육선물 - 최종거래일이 지난 종목은 0으로 전송\n예) 99999999.99999999
	char calc_prc_clsf[1];	// 정산가격구분,돈육선물 - 최종거래일이 지난 종목은 공백으로 전송\n0 : 정산가 없슴(최초 거래성립전 기세 포함)\n1 : 당일 종가(실세)\n2 : 당일 기세(최초 거래성립후 기세) - 2010.12.20 삭제\n3 : 전일 정산가(최초 거래성립후 종가 미형성) - 2010.12.20 삭제\n4 : 당일 이론가(최초 거래성립후 종가 미형성)\n5 : 스프레드거래에 의해 생성된 월물의 종가 - 2010.12.20 삭제\n6 : 조정된 전일 정산가 - 2010.12.20 삭제\n7 : 대상자산 종가(이론가없는상품)\n8 : 정산기준가격 - 2010.12.20 추가
	char final_sett_prc[16];	// 최종결제가격,예) 99999999.99999999
	char final_sett_clsf[1];	// 최종결제가격구분
	char ff[1];	// End of Text,0xFF
} COM_FUT_SETT_PRC_DATA;


// 상품선물_투자자 데이터
typedef struct _COM_FUT_INVESTOR_DATA {
	char data_clsf[2];	// DATA구분,H1
	char info_clsf[2];	// 정보구분,01:상품선물
	char mrk_clsf[1];	// 시장구분,6
	char created_date[8];	// 생성일자
	char created_time[6];	// 생성시각
	char inv_data_clsf[2];	// 데이터구분,*전일확정 : 00, 당일잠정 : 01, 당일확정 : 02\n *E1 : 장중 데이터 완료, E2 : 확정 데이터 완료\n 최종 record '99' set
	char prd_id[11];	// 상품ID,코드값모음참조
	char inv_clsf[4];	// 투자자유형,코드값모음 참조 *코드 '7000'시 수량,대금정보항목 0으로 전송
	char long_exe_q[9];	// 매수약정수량
	char short_exe_q[9];	// 매도약정수량
	char long_traded_amt[18];	// 매수약정대금
	char short_traded_amt[18];	// 매도약정대금
	char spread_long_exe_q[9];	// 스프레드에 의해 생성된 매수 약정수량
	char spread_short_exe_q[9];	// 스프레드에 의해 생성된 매도 약정수량
	char spread_long_traded_amt[18];	// 스프레드에 의해 생성된 매수 약정대금
	char spread_short_traded_amt[18];	// 스프레드에 의해 생성된 매도 약정대금
	char ff[1];	// End of Text,0xFF
} COM_FUT_INVESTOR_DATA;


// 상품선물_시세Recovery 데이터
typedef struct _COM_FUT_RECOVERY_DATA {
	char data_clsf[2];	// DATA구분,B2
	char info_clsf[2];	// 정보구분,01:상품선물
	char mrk_clsf[1];	// 시장구분,6
	char isin_clsf[12];	// 종목코드,*개발가이드 참조 : 신국채선물 추가
	char stk_snr[3];	// 종목일련번호
	char cur_prc_sign[1];	// SIGN 부호
	char cur_prc[8];	// 현재가,예) 999999.99
	char rct_prd_prc[8];	// 최근월물의제약정가격,예) 999999.99
	char nxt_prd_prc[8];	// 원월물의제약정가격,예) 999999.99
	char init_prc_sign[1];	// 시가부호
	char init_prc[8];	// 시가,예) 999999.99
	char high_prc_sign[1];	// 고가부호
	char high_prc[8];	// 고가,예) 999999.99
	char low_prc_sign[1];	// 저가부호
	char low_prc[8];	// 저가,예) 999999.99
	char open_interest_q[9];	// 미결제량
	char accm_exe_q[7];	// 누적체결수량
	char accm_trd_amt[15];	// 누적거래대금,단위:원
	char accm_block_trd_exe_q[7];	// 협의대량누적체결수량,미제공(Filler)
	char l_or_s[1];	// 최종매도매수구분코드,1:매도,2:매수(최종으로 들어온 호가의 매도매수구분값)
	char s_lvl_1_sign[1];	// 매도1호가부호
	char s_lvl_1_prc[8];	// 매도1호가,예) 999999.99
	char s_lvl_1_q[6];	// 매도1호가수량
	char s_lvl_1_trd_cnt[4];	// 매도1호가건수
	char l_lvl_1_sign[1];	// 매수1호가부호
	char l_lvl_1_prc[8];	// 매수1호가,예) 999999.99
	char l_lvl_1_q[6];	// 매수1호가수량
	char l_lvl_1_trd_cnt[4];	// 매수1호가건수
	char s_lvl_2_sign[1];	// 매도2호가부호
	char s_lvl_2_prc[8];	// 매도2호가,예) 999999.99
	char s_lvl_2_q[6];	// 매도2호가수량
	char s_lvl_2_trd_cnt[4];	// 매도2호가건수
	char l_lvl_2_sign[1];	// 매수2호가부호
	char l_lvl_2_prc[8];	// 매수2호가,예) 999999.99
	char l_lvl_2_q[6];	// 매수2호가수량
	char l_lvl_2_trd_cnt[4];	// 매수2호가건수
	char s_lvl_3_sign[1];	// 매도3호가부호
	char s_lvl_3_prc[8];	// 매도3호가,예) 999999.99
	char s_lvl_3_q[6];	// 매도3호가수량
	char s_lvl_3_trd_cnt[4];	// 매도3호가건수
	char l_lvl_3_sign[1];	// 매수3호가부호
	char l_lvl_3_prc[8];	// 매수3호가,예) 999999.99
	char l_lvl_3_q[6];	// 매수3호가수량
	char l_lvl_3_trd_cnt[4];	// 매수3호가건수
	char s_lvl_4_sign[1];	// 매도4호가부호
	char s_lvl_4_prc[8];	// 매도4호가,예) 999999.99
	char s_lvl_4_q[6];	// 매도4호가수량
	char s_lvl_4_trd_cnt[4];	// 매도4호가건수
	char l_lvl_4_sign[1];	// 매수4호가부호
	char l_lvl_4_prc[8];	// 매수4호가,예) 999999.99
	char l_lvl_4_q[6];	// 매수4호가수량
	char l_lvl_4_trd_cnt[4];	// 매수4호가건수
	char s_lvl_5_sign[1];	// 매도5호가부호
	char s_lvl_5_prc[8];	// 매도5호가,예) 999999.99
	char s_lvl_5_q[6];	// 매도5호가수량
	char s_lvl_5_trd_cnt[4];	// 매도5호가건수
	char l_lvl_5_sign[1];	// 매수5호가부호
	char l_lvl_5_prc[8];	// 매수5호가,예) 999999.99
	char l_lvl_5_q[6];	// 매수5호가수량
	char l_lvl_5_trd_cnt[4];	// 매수5호가건수
	char total_s_limit_ord_q[7];	// 매도 총호가수량
	char total_s_trd_cnt[5];	// 매도유효호가건수
	char total_l_limit_ord_q[7];	// 매수 총호가수량
	char total_l_trd_cnt[5];	// 매수유효호가건수
	char ss_id[2];	// 세션ID,코드값모음참조
	char brd_id[2];	// 보드ID,코드값모음참조
	char brd_event_id[3];	// 보드이벤트ID,B2 에서는 보드이벤트ID 사용금지(과거 상태값이 전송될 수 있음). 추후, 해당 항목 '000' 세팅 예정. 2014.03.24)
	char exp_prc_sign[1];	// 예상체결가격부호,단일가매매시만 제공\n (장상태구분코드:10,20,30,80)
	char exp_prc[8];	// 예상체결가격,예) 999999.99 단일가매매시만 제공\n (장상태구분코드:10,20,30,80)
	char real_t_high_prc_sign[1];	// 실시간상한가부호
	char real_t_high_prc[8];	// 실시간상한가,예) 999999.99 개발가이드참조
	char real_t_low_prc_sign[1];	// 실시간하한가부호
	char real_t_low_prc[8];	// 실시간하한가,예) 999999.99 개발가이드참조
	char ff[1];	// End of Text,0xFF
} COM_FUT_RECOVERY_DATA;


// 상품선물_종목정보 데이터
typedef struct _COM_FUTRE_PRD_INFO_DATA {
	char data_clsf[2];	// DATA구분,A0
	char info_clsf[2];	// 정보구분,01:상품선물
	char mrk_clsf[1];	// 시장구분,6
	char prd_cnt[5];	// 종목수
	char trd_date[8];	// 영업일자(입회일자)
	char isin_clsf[12];	// 종목코드,최종 record '999999999999' set\n*개발가이드 참조 : 신국채선물 추가
	char stk_snr[6];	// 종목SEQ
	char prd_id[11];	// 상품ID,* 코드값 모음집 참조\n* 구명칭: 파생상품ID\n10 => 11, 20140303
	char sh_prd_code[9];	// 종목단축코드,에) KR4101C90009 → K101C9000
	char prd_name_kor[80];	// 종목한글명
	char sh_prd_name_kor[40];	// 종목한글약명
	char prd_name_eng[80];	// 종목영문명
	char sh_prd_name_eng[40];	// 종목영문약명
	char listing_date[8];	// 상장일자,*개발가이드 내용추가    2009.08.31
	char de_listing_date[8];	// 상장폐지일자
	char spread_clsf_code[1];	// 스프레드기준종목구분코드,스프레드의 기준이 되는 종목의 ISIN 표준코드\n--코드값--\nF: 원월물(시간스프레드)\nN: 근월물(시간스프레드)\n20140303
	char final_sett_code[1];	// 최종결제방법코드,현금결제, 실물인수도결제 등 파생상품의 최종결제 방법\n--코드값--\nC: 현금결제\nD: 실물인수도결제\nA: 현금+실물인수도결제\n0: 해당없음\n20140303
	char prc_limit_exp_dir[1];	// 가격제한확대적용방향코드,가격제한이 다단계로 정의되는 경우 다음 단계로 확대되는 요건을 충족할 때 확대를 수행하는 방향\n## 코드값##\nX:미적용\nF:정방향\nB:역방향\nT:양방향
	char prc_limit_final_stg[3];	// 가격제한최종단계,가격제한이 다단계로 정의되는 경우 제한의 최종단계번호
	char prc_limit_stg_1_hgh_sign[1];	// 가격제한1단계SIGN부호
	char prc_limit_stg_1_high_prc[12];	// 가격제한1단계상한가,예) 9999999999.99
	char prc_limit_stg_1_low_sign[1];	// 가격제한1단계SIGN부호
	char prc_limit_stg_1_low_prc[12];	// 가격제한1단계하한가,예) 9999999999.99
	char prc_limit_stg_2_high_sign[1];	// 가격제한2단계SIGN부호
	char prc_limit_stg_2_high_prc[12];	// 가격제한2단계상한가,예) 9999999999.99
	char prc_limit_stg_2_low_sign[1];	// 가격제한2단계SIGN부호
	char prc_limit_stg_2_low_prc[12];	// 가격제한2단계하한가,예) 9999999999.99
	char prc_limit_stg_3_high_sign[1];	// 가격제한3단계SIGN부호
	char prc_limit_stg_3_high_prc[12];	// 가격제한3단계상한가,예) 9999999999.99
	char prc_limit_stg_3_low_sign[1];	// 가격제한3단계SIGN부호
	char prc_limit_stg_3_low_prc[12];	// 가격제한3단계하한가,예) 9999999999.99
	char stand_prc[12];	// 기준가,예) 9999999999.99
	char under_asset_id[3];	// 기초자산ID,예) K2I:KOSPI200지수, KQI:코스닥150지수,\n   Sxx:개별주식, BM3:신3년국채,\n   BM5:신5년국채, BMA:신10년국채, \n   CDR:CD, USD:미국달러, JPY:일본엔,\n   EUR:유럽유로,\n   GLD:금, LHG:돈육\n20140303
	char opt_type_code[1];	// 권리행사유형코드,A:미국형,E:유럽형,B:버뮤다형,Z:기타\n20140303
	char spread_str_code[2];	// 스프레드구성코드,Combination 호가를 대체할 스프레드물의 종목구성.\n--코드값--\n- T1: 최근월물+2째월물\n      > T2, T3, T4, ...\n*구명칭: 스프레드유형코드\n20140303
	char spread_prd_code_1[12];	// 스프레드구성종목코드1,* 구명칭: 스프레드근월물 종목코드\n근월물 표준코드\n20140303
	char spread_prd_code_2[12];	// 스프레드구성종목코드2,* 구명칭 : 스프레드원월물 종목코드\n원월물 표준코드\n20140303
	char last_trading_date[8];	// 최종거래일자
	char final_sett_date[8];	// 최종결제일자
	char cont_month_nbr[3];	// 결제월번호,* 구명칭: 월물구분코드\n1:최근월물,선물스프레드\n2:2째월물\n3:3째월물\n4:4째월물\n5:5째월물\n6:6째월물\n7:7째월물      구 최근월물여부 대치\nX => 9, 1 => 3, 20140303
	char maturity_date[8];	// 만기일자,권리행사 가능한 최종일자
	char exe_prc[17];	// 행사가격,예) 999999999.99999999
	char adjust_clsf_code[1];	// 조정구분코드,기초자산의 기준가격 조정이 정배수 조정(미결제조정)인지 비정배수 조정(거래승수조정)인지의 구분\n--코드값--\nN: 정상\nO: 미결제조정\nC: 거래승수조정\n20140303
	char prd_unit[17];	// 거래단위,1계약에 해당하는 기초자산수량\n예) 999999999.99999999
	char multiplier[21];	// 거래승수,약정대금 및 결제시 사용하는 계산승수\n예) 9999999999999.99999999
	char mrk_cnst_code[1];	// 시장조성구분코드,0:미시장조성종목\n1:당일시장조성종목\n2:과거시장조성종목
	char listing_type_code[1];	// 상장유형코드,1:신규상장\n2:추가상장\n3:기존종목\n4:최초상장\n5:종목조정\n6:특별설정
	char atm_prc[12];	// 등가격,기초자산기준가격에 가장 가까운 행사가격\n예) 9999999999.99
	char adj_reason_code[2];	// 조정사유코드,00:해당사항없음, 01:권리락, 02:배당락,\n03:분배락, 04:권배락, 05:중간배당락,\n06:권리중간배당락, 99:기타
	char under_asset_prd_code[12];	// 기초자산종목코드
	char under_asset_close_prc[12];	// 기초자산종가,예) 9999999999.99
	char left_until_maturity[7];	// 잔존일수
	char adj_std_prc[17];	// 조정기준가격,주식파생상품의 기초주권 조정기준가격\n예) 999999999.99999999
	char std_prc_clsf_code[2];	// 기준가격구분코드,*선물\nspcace:기준가 없음(선물 스프레드종목)\n11:전일정산가\n12:전일기준가(거래성립전 종가미형성)\n13:당일이론가(거래성립전 종가미형성)\n14:전일기세(거래성립전 기세형성)\n  -2012.05.14 삭제\n15:당일이론가(거래성립전 기세형성)-\n  -2012.05.14 삭제\n16:조정된 전일정산가\n17:조정된 전일기준가\n  (거래성립전 종가미형성)\n18:조정된 전일기세(거래성립전 기세형성)\n  -2012.05.14 삭제\n19:전일 대상자산 종가(이론가없는 상품)\n*옵션\n21:전일증거금기준가\n22:전일기준가(거래성립전 종가미형성)\n23:당일이론가(거래성립전 종가미형성)\n24:전일기세(거래성립전 기세형성)\n  -2012.05.14 삭제\n25:조정된 전일증거금기준가\n26:조정된 전일기준가\n  (거래성립전 종가미형성)\n27:조정된 전일기세(거래성립전 기세형성)\n  -2012.05.14 삭제
	char trd_std_prc_clsf_code[1];	// 매매용기준가격구분코드,0:해당없음\n1:실세\n2:기세\n3:이론가\n4:대상자산종가\n*개발가이드 내용추가    2009.08.31
	char yest_adj_close_prc_sign[1];	// SIGN부호
	char yest_adj_close_prc[17];	// 전일조정종가,주식파생상품의 조정종가\n예) 999999999.99999999
	char block_trd_clsf[1];	// 협의대량매매대상여부,Y:협의매매상품, N:대상아님\n가능품목:3년물국채선물, 미국달러선물,\n      유로선물, 엔선물
	char yest_mrg_std_prc[17];	// 전일증거금기준가격,예) 999999999.99999999
	char yest_mrg_std_prc_clsf_code[2];	// 전일증거금기준가격구분코드,*옵션\n20:증거금 기준가 없음\n21:당일종가(실세)\n22:당일기세(거래성립후기세)\n  -2012.05.14 삭제\n23:전일증거금기준가\n  (거래성립후 종가미형성)\n  -2012.05.14 삭제\n24:당일이론가(거래성립후 종가미형성)\n25:조정전일증거금기준가\n  (거래성립후 종가미형성)\n  -2012.05.14 삭제
	char sett_theory_prc[15];	// 정산이론가격,※옵션의 경우 증거금기준가용 \n예) 999999999.999999
	char std_theory_prc[15];	// 기준이론가격,예) 999999999.999999
	char yest_sett_prc[17];	// 전일정산가격,예) 999999999.99999999
	char halt_trd_clsf[1];	// 거래정지여부,Y, N
	char ft_cb_high_prc[12];	// 선물Circuit_Breakers상한가,선물 CB 발동조건을 판단하기 위한 상한\n가격(기준가대비 +/-5%가 CB 발동\n조건인 경우 +5%를 계산한 가격)\n예) 99+F31499999999.99
	char ft_cb_low_prc[12];	// 선물Circuit_Breakers하한가,선물 CB 발동조건을 판단하기 위한 상한\n가격(기준가대비 +/-5%가 CB 발동\n조건인 경우 -5%를 계산한 가격)\n예) 9999999999.99
	char check_exe_prc[17];	// 조회용행사가격,예) 999999999.99999999
	char atm_clsf[1];	// ATM구분코드,0:선물, 1:ATM, 2:ITM, 3:OTM
	char last_trading_clsf[1];	// 최종거래일여부,Y, N
	char ex_divid_aft_value[15];	// 배당락후배당가치,주식 및 주가지수 상품에만 적용됨\n- 선물 : 배당락후미래가치\n- 옵션 : 배당락후현재가치\n예) 999999999.999999
	char yest_close_prc_sign[1];	// SIGN부호
	char yest_close_prc[12];	// 전일종가,예) 9999999999.99
	char yest_close_prc_clsf[1];	// 전일종가구분코드,1:실세, 3:거래무\n2:기세 -2012.05.14 삭제
	char yest_init_prc_sign[1];	// SIGN부호
	char yest_init_prc[12];	// 전일시가,예) 9999999999.99
	char yest_high_prc_sign[1];	// SIGN부호
	char yest_high_pric[12];	// 전일고가,예) 9999999999.99
	char yest_low_prc_sign[1];	// SIGN부호
	char yest_low_prc[12];	// 전일저가,예) 9999999999.99
	char yest_first_exe_date[8];	// 최초체결일자
	char yest_last_exe_time[8];	// 전일최종체결시각
	char yest_sett_prc_clsf[2];	// 전일정산가격구분,*선물\n 10:정산가없음\n 11:당일종가(실세)\n 12:당일기세(거래성립후기세) - 2010.12.20 삭제\n 13:전일정산가(거래성립후 종가미형성) - 2010.12.20 삭제\n 14:당일이론가(거래성립후 종가미형성)\n 15:스프레드분 종가 - 2010.12.20 삭제\n 16:조정된 전일 정산가 - 2010.12.20 삭제\n 17:대상자산 종가(이론가없는 상품)\n 18:정산기준가격 - 2010.12.20 추가
	char sett_prc_theory_prc_diff_pctg_sign[1];	// SIGN부호
	char sett_prc_theory_prc_diff_pctg[12];	// 정산가격이론가격괴리율,에) 999999.999999
	char yest_open_interest_q[10];	// 전일미결제약정수량
	char yest_s_limit_ord_prc_sign[1];	// SIGN부호
	char yest_s_limit_ord_prc[12];	// 전일매도우선호가가격,예) 9999999999.99
	char yest_l_limit_ord_prc_sign[1];	// SIGN부호
	char yest_l_limit_ord_prc[12];	// 전일매수우선호가가격,예) 9999999999.99
	char implied_vol[10];	// 내재변동성,예) 999999.9999
	char listed_high_prc_sign[1];	// SIGN부호
	char listed_high_prc[12];	// 상장중최고가,예) 9999999999.99
	char listed_low_prc_sign[1];	// SIGN부호
	char listed_low_prc[12];	// 상장중최저가,예) 9999999999.99
	char year_high_prc_sign[1];	// SIGN부호
	char year_high_prc[12];	// 연중최고가,예) 9999999999.99
	char year_low_prc_sign[1];	// SIGN부호
	char year_low_prc[12];	// 연중최저가,예) 9999999999.99
	char listed_high_prc_date[8];	// 상장중최고가일자
	char listed_low_prc_date[8];	// 상장중최저가일자
	char year_high_prc_date[8];	// 연중최고가일자
	char year_low_prc_date[8];	// 연중최저가일자
	char year_std_date[8];	// 연간기준일수
	char month_trd_date[8];	// 월간거래일수
	char year_trd_date[8];	// 연간거래일수
	char yest_exe_trd_cnt [16];	// 전일체결건수
	char yest_exe_q[12];	// 전일체결수량,전일협의대량매매체결수량이 포함되지 않음
	char yest_trd_amt[22];	// 전일거래대금,전일협의대량매매거래대금이 포함되지 않음
	char yest_block_trd_exe_q[12];	// 전일협의대량합산체결수량,전일협의대량매매체결수량 => 전일협의대량합산체결수량 [전일체결수량+전일협의대량매매체결수량(협의대량+FLEX)] 2016.03.28 변경
	char yest_block_trd_total_amt[22];	// 전일협의대량합산거래대금,전일협의대량매매거래대금 => 전일협의대량합산거래대금 [전일거래대금+전일협의대량매매거래대금(협의대량+FLEX)] 2016.03.28 변경
	char cd_rate[6];	// CD금리,예) 999.999
	char open_interest_q[15];	// 미결제한도수량,*적용일에 적용되는 상품의 계좌별\n 미결제 한도 계약수. 미결제 한도가\n 적용되지 않은 상품은 0\n*주식선물에만 해당\n8 => 15, 20140303
	char product_cat[4];	// 소속 상품군,*주식선물/옵션에만 해당
	char product_cat_off_pctg[9];	// 상품군 옵셋율,*백분율로 표시\n*주식선물/옵션에만 해당예) 9999999.99\n5 => 9, 20140303
	char limit_ord_clsf_code[5];	// 지정가호가조건구분코드,호가의 체결 및 잔류조건. Bitwise 정의\n--코드값--\n1: FAS (Fill And Store)\n2: FOK (Fill Or Kill)\n3: FAK (Fill And Kill)\n\n* 지정가호가조건구분코드 BITWISE 정의\n향후 확장성을 위해 해당 10진수값을 2진수로 변환하여 처리요망(최대 16bit까지 사용가능)\n예 ) 지정가호가조건구분코드 값이 6이면\n    (십진수 6 -> 이진수 00000110)\n0번째 bit 0 -> 0 : FAS\n1번째 bit 1 -> 2 : FOK\n2번째 bit 1 -> 4 : FAK\n즉, FOK이면서 FAK를 수용한다는 의미 (FOK & FAK)\nX => 9, 1 => 5, 20140303
	char mrk_ord_clsf_code[5];	// 시장가호가조건구분코드,* 상동
	char cond_limit_ord_clsf_code[5];	// 조건부지정가호가조건구분코드,* 상동
	char best_limit_ord_clsf_code[5];	// 최유리지정가호가조건구분코드,* 상동
	char efp_clsf[1];	// EFP거래대상여부,Y, N, 상품선물만 해당  2009.08.31
	char flex_clsf[1];	// FLEX거래대상여부,Y, N, 상품선물만 해당  2009.08.31
	char yest_efp_exe_q[12];	// 전일EFP체결수량,상품선물만 해당       2009.08.31
	char yest_efp_trd_amount[22];	// 전일EFP거래대금,상품선물만 해당       2009.08.31
	char mkr_close_clsf[1];	// 휴장여부,휴장여부 (Y,N), 20121217
	char real_t_prc_limit_clsf[1];	// 실시간가격제한여부,직전 체결가격 대비 특정 범위를 초과하는 호가는 거부하도록 제한할지 여부(Y/N) 20140901
	char real_t_high_price_gap_sign[1];	// SIGN부호,20140901
	char real_t_high_price_gap[12];	// 실시간상한가간격,직전 체결가격과 실시간상한가와의 간격\n실시간상한가 = 직전체결가격 + 실시간상한가간격\nex) 9999999999.99 20140901
	char real_t_low_price_gap_sign[1];	// SIGN부호,20140901
	char real_t_low_price_gap[12];	// 실시간하한가간격,직전 체결가격과 실시간하한가와의 간격\n실시간하한가 = 직전체결가격 + 실시간하한가간격(음수)\nex) 9999999999.99 20140901
	char under_ass_mrk_id[3];	// 기초자산시장ID,기초자산시장ID는 기초자산이 KRX에 상장된 경우에만 채워짐.\nK200선물옵션:STK\n코스닥150선물:KSQ\n주식선물옵션:STK/KSQ\n상품선물옵션:SPACE\n변동성지수선물:STK\n섹터지수선물:STK\n미니K200선물옵션:STK
	char filler[24];	// Filler,170 => 134        2009.08.31\n134 => 133        2012.12.17\n133 => 110,       2014.03.03\n110 => 83,        2014.09.01\n83   => 27,       2015.06.15\n27   => 24,       2015.07.20
	char ff[1];	// End of Text,0xFF
} COM_FUTRE_PRD_INFO_DATA;


// 현물정보_국채_CD_데이터
typedef struct _GOV_BOND_CD_DATA {
	char data_clsf[2];	// DATA구분,H5
	char info_clsf[2];	// 정보구분,01:상품선물,\n최종 record '99' set
	char mrk_clsf[1];	// 시장구분,6
	char send_date[8];	// 전송일자,YYYYMMDD
	char send_time[6];	// 전송시간,HHMMSS
	char uder_asset_clsf[6];	// 기초자산구분,BM3,BM5,BMA,CD,MSB   2010.10.25\n*항목명 변경\n 기초자산ID->기초자산구분  2009.08.31\n*MSB제공중단          2011.05.02
	char final_ord_return_pctg[8];	// 최종호가수익률,999.99999\nCD(91일),국채(3년,5년,10년)\n*MSB제공중단          2011.05.02
	char gov_bond_code[12];	// 국채코드,국채선물의 결재기준채권코드
	char gov_bond_prd_code[12];	// 국채선물종목코드
	char data_created_t[6];	// 데이터 발생시간,HHMMSS
	char ff[1];	// End of Text,0xFF
} GOV_BOND_CD_DATA;


// 현물정보_결제기준채권_데이터
typedef struct _STD_GOV_BOND_DATA {
	char data_clsf[2];	// DATA구분,H6
	char info_clsf[2];	// 정보구분,01:상품선물,\n최종 record '99' set
	char mrk_clsf[1];	// 시장구분,6
	char adj_date[8];	// 적용일,익일자로 전송됨
	char prd[4];	// 상품,BM3,BM5,BMA   2010.10.25
	char fut_prd_code[12];	// 선물종목코드,익일 거래 대상인 종목
	char under_asset_bond_code[12];	// 채권코드,국채선물의 결재기준채권코드
	char conv_coef[8];	// 전환계수,인수도결제 국채선물인 경우만 해당됨\n예) 99.999999\n'00000000' 처리   2010.10.25
	char filler[25];	// filler
	char ff[1];	// End of Text,0xFF
} STD_GOV_BOND_DATA;


// 현물정보_USD_데이터
typedef struct _USD_DATA {
	char data_clsf[2];	// DATA구분,H9
	char info_clsf[2];	// 정보구분,01:상품선물,\n최종 record '99' set
	char mrk_clsf[1];	// 시장구분,6
	char send_date[8];	// 전송일자,YYYYMMDD
	char send_time[6];	// 전송시간,HHMMSS
	char under_asset_id[6];	// 기초자산ID,USD
	char s_limit_ord_prc[6];	// 매도호가,예) 9999.99
	char l_limit_ord_prc[6];	// 매수호가
	char yest_close_prc[6];	// 전일종가
	char init_prc[6];	// 시가
	char low_prc[6];	// 저가
	char high_prc[6];	// 고가
	char exe_prc[6];	// 체결가
	char data_created_t[6];	// 데이터 발생시간,HHMMSS
	char ff[1];	// End of Text,0xFF
} USD_DATA;


// 현물정보_USD배치_데이터1
typedef struct _USD_BATCH_DATA_1 {
	char data_clsf[2];	// DATA구분,I0
	char info_clsf[2];	// 정보구분,01:상품선물,\n최종 record '99' set
	char mrk_clsf[1];	// 시장구분,6
	char job_clsf_code[4];	// 업무구분코드,FBB1(원/달러 전일시간대별 거래현황)
	char trd_date[8];	// 거래일
	char trd_hour[9];	// 시간대,HHMM-HHMM
	char spread_low_rate[6];	// LOW RATE(SP),9999.9
	char spread_high_rate[6];	// HIGH RATE(SP),9999.9
	char spread_vol[6];	// VOLUME(SP),9999.9
	char filler[42];	// filler
	char ff[1];	// End of Text,0xFF
} USD_BATCH_DATA_1;


// 현물정보_USD배치_데이터2
typedef struct _USD_BATCH_DATA_2 {
	char data_clsf[2];	// DATA구분,I0
	char info_clsf[2];	// 정보구분,01:상품선물,\n최종 record '99' set
	char mrk_clsf[1];	// 시장구분,6
	char job_clsf_code[4];	// 업무구분코드,FBC1(원/달러 전일 기일물별 체결현황1)
	char trd_date[8];	// 거래일,YYYYMMDD
	char fixed_date_clsf[2];	// 기일물구분,*기일물구분 참조
	char maturity_date[8];	// 만기일(결제일),YYYYMMDD
	char low_rate[6];	// LOW RATE,9999.99
	char high_rate[6];	// HIGH RATE,9999.99
	char open_rate[6];	// OPEN RATE,9999.99
	char close_rate[6];	// CLOSE RATE,9999.99
	char filler[35];	// filler
	char ff[1];	// End of Text,0xFF
} USD_BATCH_DATA_2;


// 현물정보_USD배치_데이터3
typedef struct _USD_BATCH_DATA_3 {
	char data_clsf[2];	// DATA구분,I0
	char info_clsf[2];	// 정보구분,01:상품선물,\n최종 record '99' set
	char mrk_clsf[1];	// 시장구분,6
	char job_clsf_code[4];	// 업무구분코드,FBC2(원/달러 전일 기일물별 체결현황2)
	char trd_date[8];	// 거래일,YYYYMMDD
	char fixed_date_clsf[2];	// 기일물구분,*기일물구분 참조
	char maturity_date[8];	// 만기일(결제일),YYYYMMDD
	char vol[6];	// VOLUME,9999.9
	char avg_rate[7];	// AVERAGE RATE,9999.99
	char mar[6];	// MAR,9999.9
	char filler[40];	// filler
	char ff[1];	// End of Text,0xFF
} USD_BATCH_DATA_3;


// 현물정보_USD배치_데이터4
typedef struct _USD_BATCH_DATA_4 {
	char data_clsf[2];	// DATA구분,I0
	char info_clsf[2];	// 정보구분,01:상품선물,\n최종 record '99' set
	char mrk_clsf[1];	// 시장구분,6
	char job_clsf_code[4];	// 업무구분코드,FBD1(환율고시 재정환율 현황)
	char informed_date[8];	// 고시일,YYYYMMDD
	char currency_name[3];	// 통화명,주)통화명 참조
	char cross_rate[10];	// CROSS RATE,9999.99999
	char fx_rate[7];	// 환율,9999.99
	char filler[49];	// filler
	char ff[1];	// End of Text,0xFF
} USD_BATCH_DATA_4;


// 현물정보_USD배치_데이터5
typedef struct _USD_BATCH_DATA_5 {
	char data_clsf[2];	// DATA구분,I0
	char info_clsf[2];	// 정보구분,01:상품선물,\n최종 record '99' set
	char mrk_clsf[1];	// 시장구분,6
	char job_clsf_code[4];	// 업무구분코드,FBE1(SWAP 전일자 기일물별 체결현황)
	char trd_date[8];	// 거래일,YYYYMMDD
	char fixed_date_clsf[2];	// 기일물구분,주)기일물구분 참조
	char maturity_date[8];	// 만기일(결제일),YYYYMMDD
	char low_rate[5];	// LOW RATE,±9999
	char high_rate[5];	// HIGH RATE,±9999
	char open_rate[5];	// OPEN RATE,±9999
	char close_rate[5];	// CLOSE RATE,±9999
	char avg_rate[5];	// AVERAGE RATE,±9999
	char vol[6];	// VOLUME,9999.9
	char filler[28];	// filler
	char ff[1];	// End of Text,0xFF
} USD_BATCH_DATA_5;


// 현물정보_USD배치_데이터6
typedef struct _USD_BATCH_DATA_6 {
	char data_clsf[2];	// DATA구분,I0
	char info_clsf[2];	// 정보구분,01:상품선물,\n최종 record '99' set
	char mrk_clsf[1];	// 시장구분,6
	char job_clsf_code[4];	// 업무구분코드,FBF1(원/달러 선도환율 : 통화선도환율방식)
	char std_date[8];	// 기준일,YYYYMMDD
	char fixed_date_clsf_0[2];	// 기일물구분,주)선도환율기일물구분 참조
	char rate_0[7];	// RATE,9999.99
	char fixed_date_clsf_1[2];	// 기일물구분,주)선도환율기일물구분 참조
	char rate_1[7];	// RATE,9999.99
	char fixed_date_clsf_2[2];	// 기일물구분,주)선도환율기일물구분 참조
	char rate_2[7];	// RATE,9999.99
	char fixed_date_clsf_3[2];	// 기일물구분,주)선도환율기일물구분 참조
	char rate_3[7];	// RATE,9999.99
	char filler[33];	// filler
	char ff[1];	// End of Text,0xFF
} USD_BATCH_DATA_6;


// 현물정보_USD배치_데이터7
typedef struct _USD_BATCH_DATA_7 {
	char data_clsf[2];	// DATA구분,I0
	char info_clsf[2];	// 정보구분,01:상품선물,\n최종 record '99' set
	char mrk_clsf[1];	// 시장구분,6
	char job_clsf_code[4];	// 업무구분코드,FBF2(원/달러 선도 환율 : 스왑포인트 방식))
	char std_date[8];	// 기준일,YYYYMMDD
	char fixed_date_clsf_0[2];	// 기일물구분,주)선도환율기일물구분 참조
	char rate_0[7];	// RATE,9999.99
	char fixed_date_clsf_1[2];	// 기일물구분,주)선도환율기일물구분 참조
	char rate_1[7];	// RATE,9999.99
	char fixed_date_clsf_2[2];	// 기일물구분,주)선도환율기일물구분 참조
	char rate_2[7];	// RATE,9999.99
	char fixed_date_clsf_3[2];	// 기일물구분,주)선도환율기일물구분 참조
	char rate_3[7];	// RATE,9999.99
	char filler[33];	// filler
	char ff[1];	// End of Text,0xFF
} USD_BATCH_DATA_7;


// 현물정보_USD배치_데이터8
typedef struct _USD_BATCH_DATA_8 {
	char data_clsf[2];	// DATA구분,I0
	char info_clsf[2];	// 정보구분,01:상품선물,\n최종 record '99' set
	char mrk_clsf[1];	// 시장구분,6
	char job_clsf_code[4];	// 업무구분코드,FBG1(월평균 기준환율)
	char informed_date[8];	// 고시일,YYYYMMDD
	char std_year_month[7];	// 기준년월,9999.99
	char avg_fx_rate[7];	// 평균기준환율,9999.99
	char filler[55];	// filler
	char ff[1];	// End of Text,0xFF
} USD_BATCH_DATA_8;


// 현물정보_USD배치_데이터9
typedef struct _USD_BATCH_DATA_9 {
	char data_clsf[2];	// DATA구분,I0
	char info_clsf[2];	// 정보구분,01:상품선물,\n최종 record '99' set
	char mrk_clsf[1];	// 시장구분,6
	char job_clsf_code[4];	// 업무구분코드,CBA1(외화 전일 거래요약1)
	char trd_date[8];	// 거래일,YYYYMMDD
	char currency_name[3];	// 통화명,주)통화명 참조
	char open_rate[8];	// OPEN RATE,99.99999
	char high_rate[8];	// HIGH RATE,99.99999
	char low_rate[8];	// LOW RATE,99.99999
	char close_rate[8];	// CLOSE RATE,99.99999
	char filler[34];	// filler
	char ff[1];	// End of Text,0xFF
} USD_BATCH_DATA_9;


// 현물정보_USD배치_데이터10
typedef struct _USD_BATCH_DATA_10 {
	char data_clsf[2];	// DATA구분,I0
	char info_clsf[2];	// 정보구분,01:상품선물,\n최종 record '99' set
	char mrk_clsf[1];	// 시장구분,6
	char job_clsf_code[4];	// 업무구분코드,CBA2(외화 전일 거래요약2)
	char trd_date[8];	// 거래일,YYYYMMDD
	char currency_name[3];	// 통화명,주)통화명 참조
	char ave_rate[7];	// AVERAGE RATE,99.9999
	char o_n_vol[7];	// O/N VOLUME,9999.99
	char total_vol[7];	// TOTAL VOLUME,9999.99
	char libor_rate[7];	// LIBOR,9.99999
	char sibor_rate[7];	// SIBOR,9.99999
	char filler[31];	// filler
	char ff[1];	// End of Text,0xFF
} USD_BATCH_DATA_10;


// 현물정보_USD실시간정보_데이터1
typedef struct _USD_REAL_TIME_DATA_1 {
	char data_clsf[2];	// DATA구분,I1
	char info_clsf[2];	// 정보구분,01:상품선물,\n최종 record '99' set
	char mrk_clsf[1];	// 시장구분,6
	char job_clsf_code[4];	// 업무구분코드,FOC1(원/달러 시간대별 거래현황)
	char trd_date[8];	// 거래일,YYYYMMDD
	char trd_hour[9];	// 시간대,HHMM-HHMM
	char spread_low_rate[6];	// LOW RATE(SP),9999.99
	char spread_high_rate[6];	// HIGH RATE(SP),9999.99
	char filler[48];	// filler
	char ff[1];	// End of Text,0xFF
} USD_REAL_TIME_DATA_1;


// 현물정보_USD실시간정보_데이터2
typedef struct _USD_REAL_TIME_DATA_2 {
	char data_clsf[2];	// DATA구분,I1
	char info_clsf[2];	// 정보구분,01:상품선물
	char mrk_clsf[1];	// 시장구분,6
	char job_clsf_code[4];	// 업무구분코드,FOD1(원/달러 기일물별 접수현황)
	char trd_date[8];	// 거래일,YYYYMMDD
	char fixed_date_clsf[2];	// 기일물구분,주)기일물구분참조
	char maturity_date[8];	// 만기일(결제일),YYYYMMDD
	char bid_best[6];	// BID BEST,9999.9
	char offer_best[6];	// OFFER BEST,9999.9
	char bid_vol[6];	// BID VOLUME,9999.9
	char offer_vol[6];	// OFFER VOLUME,9999.9
	char prev_rate[6];	// PREV RATE,9999.9
	char filler[29];	// filler
	char ff[1];	// End of Text,0xFF
} USD_REAL_TIME_DATA_2;


// 현물정보_USD실시간정보_데이터3
typedef struct _USD_REAL_TIME_DATA_3 {
	char data_clsf[2];	// DATA구분,I1
	char info_clsf[2];	// 정보구분,01:상품선물
	char mrk_clsf[1];	// 시장구분,6
	char job_clsf_code[4];	// 업무구분코드,FOE1(원/달러 기일물별 체결현황) (접수->체결)변경
	char trd_date[8];	// 거래일,YYYYMMDD
	char fixed_date_clsf[2];	// 기일물구분,주)기일물구분참조
	char maturity_date[8];	// 만기일(결제일),YYYYMMDD
	char low_rate[6];	// LOW RATE,9999.9
	char high_rate[6];	// HIGH RATE,9999.9
	char open_rate[6];	// OPEN RATE,9999.9
	char close_rate[6];	// CLOSE RATE,9999.9
	char filler[35];	// filler
	char ff[1];	// End of Text,0xFF
} USD_REAL_TIME_DATA_3;


// 현물정보_CNH실시간정보_데이터
typedef struct _CNH_REAL_TIME_DATA {
	char data_clsf[2];	// DATA구분,I1
	char info_clsf[2];	// 정보구분,01:상품선물
	char mrk_clsf[1];	// 시장구분,6
	char job_clsf_code[4];	// 업무구분코드,HOE1(원/위안 기일물별 체결현황)
	char trd_date[8];	// 거래일,YYYYMMDD
	char fixed_date_clsf[2];	// 기일물구분,주)기일물구분참조
	char maturity_date[8];	// 만기일(결제일),YYYYMMDD
	char low_rate[6];	// LOW RATE,9999.9
	char high_rate[6];	// HIGH RATE,9999.9
	char open_rate[6];	// OPEN RATE,9999.9
	char close_rate[6];	// CLOSE RATE,9999.9
	char filler[35];	// filler
	char ff[1];	// End of Text,0xFF
} CNH_REAL_TIME_DATA;


// 현물정보_USD실시간정보_데이터4
typedef struct _USD_REAL_TIME_DATA_4 {
	char data_clsf[2];	// DATA구분,I1
	char info_clsf[2];	// 정보구분,01:상품선물
	char mrk_clsf[1];	// 시장구분,6
	char job_clsf_code[4];	// 업무구분코드,FOF1(SWAP 기일물별 접수현황)
	char trd_date[8];	// 거래일,YYYYMMDD
	char fixed_date_clsf[2];	// 기일물구분,주)기일물구분참조
	char maturity_date[8];	// 만기일(결제일),YYYYMMDD
	char bid_best[5];	// BID BEST,±9999
	char offer_best[5];	// OFFER BEST,±9999
	char bid_vol[6];	// BID VOLUME,9999.9
	char offer_vol[6];	// OFFER VOLUME,9999.9
	char prev_rate[5];	// PREV RATE,±9999
	char filler[32];	// filler
	char ff[1];	// End of Text,0xFF
} USD_REAL_TIME_DATA_4;


// 현물정보_USD실시간정보_데이터5
typedef struct _USD_REAL_TIME_DATA_5 {
	char data_clsf[2];	// DATA구분,I1
	char info_clsf[2];	// 정보구분,01:상품선물
	char mrk_clsf[1];	// 시장구분,6
	char job_clsf_code[4];	// 업무구분코드,FOG1(SWAP 기일물별 체결현황)
	char trd_date[8];	// 거래일,YYYYMMDD
	char fixed_date_clsf[2];	// 기일물구분,주)기일물구분참조
	char maturity_date[8];	// 만기일(결제일),YYYYMMDD
	char low_rate[5];	// LOW RATE,±9999
	char high_rate[5];	// HIGH RATE,±9999
	char open_rate[5];	// OPEN RATE,±9999
	char close_rate[5];	// CLOSE RATE,±9999
	char filler[39];	// filler
	char ff[1];	// End of Text,0xFF
} USD_REAL_TIME_DATA_5;


// 현물정보_USD실시간정보_데이터8
typedef struct _USD_REAL_TIME_DATA_8 {
	char data_clsf[2];	// DATA구분,I1
	char info_clsf[2];	// 정보구분,01:상품선물
	char mrk_clsf[1];	// 시장구분,6
	char job_clsf_code[4];	// 업무구분코드,UOD1(원달러 SPOT 대고객 환율호가)
	char trd_date[8];	// 거래일,YYYYMMDD
	char fixed_date_clsf[2];	// 기일물구분,주)기일물 구분
	char maturity_date[8];	// 만기일(결제일),YYYYMMDD
	char bank_name[10];	// 은행명,영문은행명
	char bid_best[6];	// BID BEST,9999.9
	char offer_best[6];	// OFFER BEST,9999.9
	char low_rate[6];	// LOW RATE,9999.9
	char high_rate[6];	// HIGH RATE,9999.9
	char open_rate[6];	// OPEN RATE,9999.9
	char mar[6];	// MAR,9999.9
	char filler[13];	// filler
	char ff[1];	// End of Text,0xFF
} USD_REAL_TIME_DATA_8;


// 현물정보_USD실시간정보_데이터7
typedef struct _USD_REAL_TIME_DATA_7 {
	char data_clsf[2];	// DATA구분,I1
	char info_clsf[2];	// 정보구분,01:상품선물
	char mrk_clsf[1];	// 시장구분,6
	char job_clsf_code[4];	// 업무구분코드,COA1(외화 기일물별 접수현황)
	char trd_date[8];	// 거래일,YYYYMMDD
	char currency_name[3];	// 통화명,주)통화명 참조
	char fixed_date_clsf[2];	// 기일물 구분,주)기일물 구분
	char bid_rate[8];	// BID RATE,99999.99
	char offer_rate[8];	// OFFER RATE,99999.99
	char bid_vol[7];	// BID VOLUME,9999.99
	char offer_vol[7];	// OFFER VOLUME,9999.99
	char filler[34];	// filler
	char ff[1];	// End of Text,0xFF
} USD_REAL_TIME_DATA_7;


// 현물정보_USD실시간정보_데이터6
typedef struct _USD_REAL_TIME_DATA_6 {
	char data_clsf[2];	// DATA구분,I1
	char info_clsf[2];	// 정보구분,01:상품선물
	char mrk_clsf[1];	// 시장구분,6
	char job_clsf_code[4];	// 업무구분코드,FOQ1(현물환 시간대별 BID-OFFER 호가 현황)
	char trd_date[8];	// 거래일,YYYYMMDD
	char td_hour[4];	// 시간대,HHMM
	char spread_bid_prc[6];	// BID 호가(SP),9999.9
	char spread_ask_prc[6];	// OFFER 호가(SP),9999.9
	char filler[53];	// filler
	char ff[1];	// End of Text,0xFF
} USD_REAL_TIME_DATA_6;


// 상품선물_Polling 데이터
typedef struct _COM_FUT_POLLING_DATA {
	char data_clsf[2];	// DATA구분,I2
	char info_clsf[2];	// 정보구분,01:상품선물
	char mrk_clsf[1];	// 시장구분,6
	char send_time[4];	// 전송시간,HHSS
	char main_backup_clsf[2];	// Main Backup구분,space
	char filler[8];	// Filler
	char ff[1];	// End of Text,0xFF
} COM_FUT_POLLING_DATA;


// 현물정보_USD실시간정보_데이터9
typedef struct _USD_REAL_TIME_DATA_9 {
	char data_clsf[2];	// DATA구분,I1
	char info_clsf[2];	// 정보구분,01:상품선물
	char mrk_clsf[1];	// 시장구분,6
	char job_clsf_code[4];	// 업무구분코드,UOE1(원달러 SPOT 30분단위 행간 환율체결가)
	char trd_date[8];	// 거래일,YYYYMMDD
	char fixed_date_clsf[2];	// 기일물구분,SP
	char maturity_date[8];	// 만기일(결제일),YYYYMMDD
	char exe_t[4];	// 체결시간,HHMM(0930, 1000,1030,1100,1130,1200,1230,\n1300,1330,1400, 1430, 1500)
	char exe_prc[6];	// 체결가,9999.9
	char filler[49];	// filler
	char ff[1];	// End of Text,0xFF
} USD_REAL_TIME_DATA_9;


// 현물정보_돈육대표가격지수_데이터
typedef struct _LEAN_HOG_REP_PRC_INDEX_DATA {
	char data_clsf[2];	// DATA구분,H8
	char info_clsf[2];	// 정보구분,01:상품선물
	char mrk_clsf[1];	// 시장구분,6
	char data_type[1];	// 데이터 타입,D:돈육 대표가격 지수
	char inform_date_yest[8];	// 공시일자-전일
	char inform_date_close_yest[8];	// 공시일자-직전일
	char accum_mrk_nbr[2];	// 집계도매시장수,개수
	char accum_prd_nbr[5];	// 집계두수,두
	char trd_weight_total[10];	// 거래 도체중 합계,kg
	char trd_prc_total[15];	// 거래 가격 합계,원
	char rep_prc[4];	// 대표 가격,원/kg
	char filler[42];	// filler
	char ff[1];	// End of Text,0xFF
} LEAN_HOG_REP_PRC_INDEX_DATA;


// 현물정보_돈육실시간가격지수_데이터
typedef struct _LEAN_HOG_REAL_TIME_PRC_INDEX_DATA {
	char data_cslf[2];	// DATA구분,H8
	char info_clsf[2];	// 정보구분,01:상품선물
	char mrk_clsf[1];	// 시장구분,6
	char data_type[1];	// 데이터 타입,L:실시간 현물가격 지수
	char inform_time[4];	// 공시시간
	char inform_date_yest[8];	// 공시일자-전일
	char inform_date_today[8];	// 공시일자-당일
	char accum_mrk_nbr[2];	// 집계 도매시장 수,개수
	char accum_prd_nbr[5];	// 경락두수,두
	char trd_weight_total[10];	// 거래 도체중 합계,kg
	char trd_prc_total[15];	// 거래 가격 합계,원
	char under_asset_prc[4];	// 현물 가격,원/kg
	char filler[38];	// filler
	char ff[1];	// End of Text,0xFF
} LEAN_HOG_REAL_TIME_PRC_INDEX_DATA;


// 현물정보_돈육마감가격지수_데이터
typedef struct _LEAN_HOG_CLOSE_PRICE_INDEX_DATA {
	char data_clsf[2];	// DATA구분,H8
	char info_clsf[2];	// 정보구분,01:상품선물,\n최종 record '99' set
	char mrk_clsf[1];	// 시장구분,6
	char data_type[1];	// 데이터 타입,E:실시간 현물가격 마감지수
	char inform_date_today[8];	// 공시일자 당일
	char inform_date_yest[8];	// 공시일자 전일
	char accum_mrk_nbr[2];	// 집계 도매시장 수
	char accum_prd_nbr[5];	// 집계 두수,개수
	char trd_weight_total[10];	// 거래 도체중 합계,두
	char trd_prc_total[15];	// 거래 가격 합계,kg
	char init_prc[4];	// 시작 가격,원
	char high_prc[4];	// 최고 가격,원/kg
	char low_prc[4];	// 최저 가격
	char close_prc[4];	// 최종 가격
	char filler[30];	// filler
	char ff[1];	// End of Text,0xFF
} LEAN_HOG_CLOSE_PRICE_INDEX_DATA;


// 상품선물_SPACE
typedef struct _COM_FUT_SPACE {
	char data_clsf[2];	// DATA구분,G9
	char info_clsf[2];	// 정보구분,01:상품선물
	char mrk_clsf[1];	// 시장구분,6
	char ff[1];	// End of Text,0xFF
} COM_FUT_SPACE;
