// cb_kp200_option_tr.h
// KOSPI200 지수옵션 실시간 TR

#pragma once
// 주석에 \n이 들어간건 나중에 이쁘게 바꿔야함


// K200옵션_경쟁+협의합산
typedef struct _K200_OPT_COMP_BLOCK {
	char data_clsf[2];	// DATA구분, C4
	char info_clsf[2];	// 정보구분, 03:KOSPI200지수옵션
	char mkt_clsf[1];	// 시장구분, 4
	char isin_clsf[12];	// 종목코드
	char stk_snr[7];	// 종목일련번호
	char cpt_block_trd_vol[12];	// 경쟁+협의합산 거래량, 경쟁매매와 협의대량거래를 합산한 거래량
	char cpt_block_trd_amt[22];	// 경쟁+협의합산 거래대금, 경쟁매매와 협의대량거래를 합산한 거래대금\n(단위 : 원)
	char ff[1];	// End of Text, 0xFF
} K200_OPT_COMP_BLOCK;


// K200옵션_체결
typedef struct _K200_OPT_EXEC {
	char data_clsf[2];	// DATA구분, A3
	char info_clsf[2];	// 정보구분, 03:KOSPI200지수옵션
	char mrk_clsf[1];	// 시장구분, 4
	char isin_clsf[12];	// 종목코드
	char stk_snr[4];	// 종목일련번호, 종목일련번호 자리수 변경(3->4)
	char brd_id[2];	// 보드ID, 코드값모음참조
	char cur_prc[5];	// 현재가격, 예) 999.99
	char exe_q[7];	// 체결수량
	char ss_id[2];	// 세션ID, 코드값모음참조
	char exe_t[8];	// 체결시각
	char init_prc[5];	// 시가, 예) 999.99
	char high_prc[5];	// 고가, 예) 999.99
	char low_prc[5];	// 저가, 예) 999.99
	char pri_prc[5];	// 직전가격, 예) 999.99
	char accm_exe_q[8];	// 누적체결수량
	char accm_trd_amt[11];	// 누적거래대금, 단위:천원
	char filler[8];	// 협의대량누적체결수량, 미제공(Filler)
	char l_or_s[1];	// 최종매도매수구분코드, 1:매도,2:매수(최종으로 들어온 호가의 매도매수구분값)
	char real_t_high_prc[5];	// 실시간상한가, 예) 999.99 개발가이드참조
	char real_t_low_prc[5];	// 실시간하한가, 예) 999.99 개발가이드참조
	char ff[1];	// End of Text, 0xFF
} K200_OPT_EXEC;


// K200옵션_우선호가
typedef struct _K200_OPT_LIMIT_ORD {
	char data_clsf[2];	// DATA구분, B6
	char info_clsf[2];	// 정보구분, 03:KOSPI200지수옵션
	char mrk_clsf[1];	// 시장구분, 4
	char isin_clsf[12];	// 종목코드
	char stk_snr[4];	// 종목일련번호, 종목일련번호 자리수 변경(3->4)
	char brd_id[2];	// 보드ID, 코드값모음참조
	char ss_id[2];	// 세션ID, 코드값모음참조
	char total_l_limit_ord_q[7];	// 매수총호가잔량
	char l_lvl_1_prc[5];	// 매수1단계우선호가가격, 예) 999.99
	char l_lvl_1_q[7];	// 매수1단계우선호가잔량
	char l_lvl_2_prc[5];	// 매수2단계우선호가가격, 예) 999.99
	char l_lvl_2_q[7];	// 매수2단계우선호가잔량
	char l_lvl_3_prc[5];	// 매수3단계우선호가가격, 예) 999.99
	char l_lvl_3_q[7];	// 매수3단계우선호가잔량
	char l_lvl_4_prc[5];	// 매수4단계우선호가가격, 예) 999.99
	char l_lvl_4_q[7];	// 매수4단계우선호가잔량
	char l_lvl_5_prc[5];	// 매수5단계우선호가가격, 예) 999.99
	char l_lvl_5_q[7];	// 매수5단계우선호가잔량
	char total_s_limit_ord_q[7];	// 매도총호가잔량
	char s_lvl_1_prc[5];	// 매도1단계우선호가가격, 예) 999.99
	char s_lvl_1_q[7];	// 매도1단계우선호가잔량
	char s_lvl_2_prc[5];	// 매도2단계우선호가가격, 예) 999.99
	char s_lvl_2_q[7];	// 매도2단계우선호가잔량
	char s_lvl_3_prc[5];	// 매도3단계우선호가가격, 예) 999.99
	char s_lvl_3_q[7];	// 매도3단계우선호가잔량
	char s_lvl_4_prc[5];	// 매도4단계우선호가가격, 예) 999.99
	char s_lvl_4_q[7];	// 매도4단계우선호가잔량
	char s_lvl_5_prc[5];	// 매도5단계우선호가가격, 예) 999.99
	char s_lvl_5_q[7];	// 매도5단계우선호가잔량
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
	char exp_prc[5];	// 예상체결가격, 예) 999.99 단일가매매시만 제공\n (장상태구분코드:10,20,30,80)
	char ff[1];	// End of Text, 0xFF
} K200_OPT_LIMIT_ORD;


// K200옵션_체결_우선호가
typedef struct _K200_OPT_EXEC_LIMIT_ORD {
	char data_clsf[2];	// DATA구분, G7
	char info_clsf[2];	// 정보구분, 03:KOSPI200지수옵션
	char mrk_clsf[1];	// 시장구분, 4
	char isin_clsf[12];	// 종목코드
	char stk_snr[4];	// 종목일련번호, 종목일련번호 자리수 변경(3->4)
	char brd_id[2];	// 보드ID, 코드값모음참조
	char cur_prc[5];	// 현재가격, 예) 999.99
	char exe_q[7];	// 체결수량
	char ss_id[2];	// 세션ID, 코드값모음참조
	char exe_t[8];	// 체결시각
	char init_prc[5];	// 시가, 예) 999.99
	char high_prc[5];	// 고가, 예) 999.99
	char low_prc[5];	// 저가, 예) 999.99
	char pri_prc[5];	// 직전가격, 예) 999.99
	char accm_exe_q[8];	// 누적체결수량
	char accm_trd_amt[11];	// 누적거래대금, 단위:천원
	char accm_block_trd_exe_q[8];	// 협의대량누적체결수량, 미제공(Filler)
	char l_or_s[1];	// 최종매도매수구분코드, 1:매도,2:매수(최종으로 들어온 호가의 매도매수구분값)
	char total_l_limit_ord_q[7];	// 매수총호가잔량
	char l_lvl_1_prc[5];	// 매수1단계우선호가가격, 예) 999.99
	char l_lvl_1_q[7];	// 매수1단계우선호가잔량
	char l_lvl_2_prc[5];	// 매수2단계우선호가가격, 예) 999.99
	char l_lvl_2_q[7];	// 매수2단계우선호가잔량
	char l_lvl_3_prc[5];	// 매수3단계우선호가가격, 예) 999.99
	char l_lvl_3_q[7];	// 매수3단계우선호가잔량
	char l_lvl_4_prc[5];	// 매수4단계우선호가가격
	char l_lvl_4_q[7];	// 매수4단계우선호가잔량
	char l_lvl_5_prc[5];	// 매수5단계우선호가가격, 예) 999.99
	char l_lvl_5_q[7];	// 매수5단계우선호가잔량
	char total_s_limit_ord_q[7];	// 매도총호가잔량
	char s_lvl_1_prc[5];	// 매도1단계우선호가가격, 예) 999.99
	char s_lvl_1_q[7];	// 매도1단계우선호가잔량
	char s_lvl_2_prc[5];	// 매도2단계우선호가가격
	char s_lvl_2_q[7];	// 매도2단계우선호가잔량, 예) 999.99
	char s_lvl_3_prc[5];	// 매도3단계우선호가가격
	char s_lvl_3_q[7];	// 매도3단계우선호가잔량
	char s_lvl_4_prc[5];	// 매도4단계우선호가가격, 예) 999.99
	char s_lvl_4_q[7];	// 매도4단계우선호가잔량
	char s_lvl_5_prc[5];	// 매도5단계우선호가가격
	char s_lvl_5_q[7];	// 매도5단계우선호가잔량, 예) 999.99
	char total_l_trd_cnt[5];	// 매수유효호가건수
	char l_lvl_1_trd_cnt[4];	// 매수1단계우선호가건수
	char l_lvl_2_trd_cnt[4];	// 매수2단계우선호가건수
	char l_lvl_3_trd_cnt[4];	// 매수3단계우선호가건수, 예) 999.99
	char l_lvl_4_trd_cnt[4];	// 매수4단계우선호가건수
	char l_lvl_5_trd_cnt[4];	// 매수5단계우선호가건수
	char total_s_trd_cnt[5];	// 매도유효호가건수, 예) 999.99
	char s_lvl_1_trd_cnt[4];	// 매도1단계우선호가건수
	char s_lvl_2_trd_cnt[4];	// 매도2단계우선호가건수
	char s_lvl_3_trd_cnt[4];	// 매도3단계우선호가건수, 예) 999.99
	char s_lvl_4_trd_cnt[4];	// 매도4단계우선호가건수
	char s_lvl_5_trd_cnt[4];	// 매도5단계우선호가건수
	char real_t_high_prc[5];	// 실시간상한가, 예) 999.99 개발가이드참조
	char real_t_low_prc[5];	// 실시간하한가, 예) 999.99 개발가이드참조
	char ff[1];	// End of Text, 0xFF
} K200_OPT_EXEC_LIMIT_ORD;


// K200옵션_종목마감
typedef struct _K200_OPT_CLOSE_PRODUCT {
	char data_clsf[2];	// DATA구분, A6
	char info_clsf[2];	// 정보구분, 03:KOSPI200지수옵션
	char mrk_clsf[1];	// 시장구분, 4
	char isin_clsf[12];	// 종목코드
	char stk_snr[4];	// 종목일련번호, 종목일련번호 자리수 변경(3->4)
	char brd_id[2];	// 보드ID, 코드값모음참조
	char close_prc[5];	// 종가, *거래무 종목의 경우 기준가 set, 예) 999.99
	char close_prc_code[1];	// 종가구분코드, 1:체결가격, 3:거래무\n 2:기세 -2012.05.14 삭제\n ' ':정규장이 아닌 경우 space
	char accm_exe_q[8];	// 누적체결수량
	char accm_trd_amt[11];	// 누적거래대금, 단위:천원
	char filler[8];	// 협의대량누적체결수량, 미제공(Filler)
	char total_l_limit_ord_q[7];	// 매수총호가잔량
	char l_lvl_1_prc[5];	// 매수1단계우선호가가격, 예) 999.99
	char l_lvl_1_q[7];	// 매수1단계우선호가잔량
	char l_lvl_2_prc[5];	// 매수2단계우선호가가격, 예) 999.99
	char l_lvl_2_q[7];	// 매수2단계우선호가잔량
	char l_lvl_3_prc[5];	// 매수3단계우선호가가격, 예) 999.99
	char l_lvl_3_q[7];	// 매수3단계우선호가잔량
	char l_lvl_4_prc[5];	// 매수4단계우선호가가격, 예) 999.99
	char l_lvl_4_q[7];	// 매수4단계우선호가잔량
	char l_lvl_5_prc[5];	// 매수5단계우선호가가격, 예) 999.99
	char l_lvl_5_q[7];	// 매수5단계우선호가잔량
	char total_s_limit_ord_q[7];	// 매도총호가잔량
	char s_lvl_1_prc[5];	// 매도1단계우선호가가격, 예) 999.99
	char s_lvl_1_q[7];	// 매도1단계우선호가잔량
	char s_lvl_2_prc[5];	// 매도2단계우선호가가격, 예) 999.99
	char s_lvl_2_q[7];	// 매도2단계우선호가잔량
	char s_lvl_3_prc[5];	// 매도3단계우선호가가격, 예) 999.99
	char s_lvl_3_q[7];	// 매도3단계우선호가잔량
	char s_lvl_4_prc[5];	// 매도4단계우선호가가격, 예) 999.99
	char s_lvl_4_q[7];	// 매도4단계우선호가잔량
	char s_lvl_5_prc[5];	// 매도5단계우선호가가격, 예) 999.99
	char s_lvl_5_q[7];	// 매도5단계우선호가잔량
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
	char ff[1];	// End of Text, 0xFF
} K200_OPT_CLOSE_PRODUCT;


// K200옵션_장운영TS
typedef struct _K200_OPT_MRK_OP_TS {
	char data_clsf[2];	// DATA구분, A7
	char info_clsf[2];	// 정보구분, 03:KOSPI200지수옵션
	char mrk_clsf[1];	// 시장구분, 4
	char isin_clsf[12];	// 종목코드
	char stk_snr[4];	// 종목일련번호, 종목일련번호 자리수 변경(3->4)
	char prd_id[11];	// 상품ID, 코드값모음참조 : space처리
	char brd_id[2];	// 보드ID, 코드값모음참조
	char brd_event_id[3];	// 보드이벤트ID, 코드값모음참조
	char brd_event_start_t[8];	// 보드이벤트시작시각, 고정된 상수값(예:BB1(매매거래개시)의 경우 09000000)
	char brd_event_code[5];	// 보드이벤트적용군코드, 코드값모음참조
	char ss_id[2];	// 세션ID, 코드값모음참조
	char ord_exist[1];	// 호가유무, 0:호가없음(이하항목 무시), 1:호가있음(이하항목 사용)
	char total_l_limit_ord_q[7];	// 매수총호가잔량
	char l_lvl_1_prc[5];	// 매수1단계우선호가가격, 예) 999.99
	char l_lvl_1_q[7];	// 매수1단계우선호가잔량
	char l_lvl_2_prc[5];	// 매수2단계우선호가가격, 예) 999.99
	char l_lvl_2_q[7];	// 매수2단계우선호가잔량
	char l_lvl_3_prc[5];	// 매수3단계우선호가가격, 예) 999.99
	char l_lvl_3_q[7];	// 매수3단계우선호가잔량
	char l_lvl_4_prc[5];	// 매수4단계우선호가가격, 예) 999.99
	char l_lvl_4_q[7];	// 매수4단계우선호가잔량
	char l_lvl_5_prc[5];	// 매수5단계우선호가가격, 예) 999.99
	char l_lvl_5_q[7];	// 매수5단계우선호가잔량
	char total_s_limit_ord_q[7];	// 매도총호가잔량
	char s_lvl_1_prc[5];	// 매도1단계우선호가가격, 예) 999.99
	char s_lvl_1_q[7];	// 매도1단계우선호가잔량
	char s_lvl_2_prc[5];	// 매도2단계우선호가가격, 예) 999.99
	char s_lvl_2_q[7];	// 매도2단계우선호가잔량
	char s_lvl_3_prc[5];	// 매도3단계우선호가가격, 예) 999.99
	char s_lvl_3_q[7];	// 매도3단계우선호가잔량
	char s_lvl_4_prc[5];	// 매도4단계우선호가가격, 예) 999.99
	char s_lvl_4_q[7];	// 매도4단계우선호가잔량
	char s_lvl_5_prc[5];	// 매도5단계우선호가가격, 예) 999.99
	char s_lvl_5_q[7];	// 매도5단계우선호가잔량
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
	char real_t_high_prc[5];	// 실시간상한가, 예) 999.99 개발가이드참조
	char real_t_low_prc[5];	// 실시간하한가, 예) 999.99 개발가이드참조
	char ff[1];	// End of Text, 0xFF
} K200_OPT_MRK_OP_TS;


// K200옵션_마감
typedef struct _K200_OPT_CLOSE {
	char data_clsf[2];	// DATA구분, H0
	char info_clsf[2];	// 정보구분, 03:KOSPI200지수옵션
	char mrk_clsf[1];	// 시장구분, 4
	char ff[1];	// End of Text, 0xFF
} K200_OPT_CLOSE;


// K200옵션_장운영스케줄공개
typedef struct _K200_OPT_MRK_OP_SCHD {
	char data_clsf[2];	// DATA구분, M4
	char info_clsf[2];	// 정보구분, 03:KOSPI200지수옵션
	char mrk_clsf[1];	// 시장구분, 4
	char isin_clsf[12];	// 종목코드, 개별종목 장운영조치시 등록
	char stk_snr[4];	// 종목일련번호, 종목일련번호 자리수 변경(3->4)
	char prd_id[11];	// 상품ID, 코드값모음참조 : space처리
	char mrk_prd_id[3];	// 장운영상품그룹ID, OKI : K200옵션
	char brd_id[2];	// 보드ID, 코드값모음참조
	char brd_event_id[3];	// 보드이벤트ID, 코드값모음참조
	char brd_event_start_t[8];	// 보드이벤트시작시각
	char brd_event_code[5];	// 보드이벤트적용군코드, 코드값모음참조
	char ss_open_close_code[2];	// 세션개시종료코드, BS:보드개시\n BE:보드종료\n SS:세션개시\n SE:세션종료\n SH:세션정지\n SR:세션재개
	char ss_id[2];	// 세션ID, 코드값모음참조
	char adj_stage[2];	// 적용단계, CB 및 가격제한폭 확대시 적용되는 단계 \n예)초기값 00
	char under_asset_prc_chg[1];	// 기준종목가격확대발생코드, 기준종목이 가격확대된 방향코드(U:상승, D:하락)
	char exp_prc_chg_t[8];	// 가격확대예정시각, 파생시장가격확대 예고 이벤트 발생시 사용되는 항목으로 가격확대예정시각이 기록됨
	char ff[1];	// End of Text, 0xFF
} K200_OPT_MRK_OP_SCHD;


// K200옵션_배분정보
typedef struct _K200_OPT_DIST_INFO {
	char data_clsf[2];	// DATA구분, O6
	char info_clsf[2];	// 정보구분, 03:KOSPI200지수옵션
	char mrk_clsf[1];	// 시장구분, 4
	char isin_clsf[12];	// 종목코드
	char stk_snr[4];	// 종목일련번호, 종목일련번호 자리수 변경(3->4)
	char brd_id[2];	// 보드ID, 코드값모음참조
	char dist_adj_code[1];	// 배분적용구분코드, 1:배분개시, 2:배분해제
	char dist_code[1];	// 배분처리구분코드, 1:매수상한, 2:매수하한,\n 3:매도상한, 4:매도하한\n *배분해제시 코드없음(space처리)
	char dist_cls_t[8];	// 배분해제시각
	char ff[1];	// End of Text, 0xFF
} K200_OPT_DIST_INFO;


// K200옵션_실시간상하한가 적용및해제
typedef struct _K200_OPT_REAL_HIGH_LOW_LIMIT_ON_OFF {
	char data_clsf[2];	// DATA구분, Q2
	char info_clsf[2];	// 정보구분, 03:KOSPI200지수옵션
	char mrk_clsf[1];	// 시장구분, 4
	char isin_clsf[12];	// 종목코드
	char stk_snr[4];	// 종목일련번호, 종목일련번호 자리수 변경(3->4)
	char brd_id[2];	// 보드ID, 코드값모음참조
	char cleared_t[8];	// 처리시각
	char real_t_prc_limit_code[1];	// 실시간가격제한설정코드, 0: 해제, 1: 설정, 2: 재설정
	char real_t_high_prc[5];	// 실시간상한가, 예)999.99 개발가이드참조
	char real_t_low_prc[5];	// 실시간하한가, 예)999.99 개발가이드참조
	char ff[1];	// End of Text, 0xFF
} K200_OPT_REAL_HIGH_LOW_LIMIT_ON_OFF;


// K200옵션_가격제한폭확대발동
typedef struct _K200_OPT_PRC_LIMIT_ON {
	char data_clsf[2];	// DATA구분, V1
	char info_clsf[2];	// 정보구분, 03:KOSPI200지수옵션
	char mrk_clsf[1];	// 시장구분, 4
	char code_clsf[12];	// 종목코드
	char stk_snr[4];	// 종목일련번호, 종목일련번호 자리수 변경(3->4)
	char prd_id[11];	// 상품ID, 코드값모음참조 : space처리
	char brd_id[2];	// 보드ID, 코드값모음참조
	char prc_limit_start_t[8];	// 가격확대시각, 가격이 확대된 시각
	char prc_limit_high[2];	// 가격제한확대상한단계, 적용된 상한단계
	char prc_limit_low[2];	// 가격제한확대하한단계, 적용된 하한단계
	char high_prc[5];	// 상한가, 적용된 상한가\n예)999.99
	char low_prc[5];	// 하한가, 적용된 하한가\n예)999.99
	char ff[1];	// End of Text, 0xFF
} K200_OPT_PRC_LIMIT_ON;


// K200옵션_SPACE
typedef struct _K200_OPT_SPACE {
	char data_clsf[2];	// DATA구분, G9
	char info_clsf[2];	// 정보구분, 03:KOSPI200지수옵션
	char mrk_clsf[1];	// 시장구분, 4
	char ff[1];	// End of Text, 0xFF
} K200_OPT_SPACE;


// K200옵션_미결제약정수량 데이터
typedef struct _K200_OPT_OPEN_INTEREST_DATA {
	char data_clsf[2];	// DATA구분, H2
	char info_clsf[2];	// 정보구분, 03:KOSPI200지수옵션
	char mrk_clsf[1];	// 시장구분, 4
	char isin_clsf[12];	// 종목코드, 최종 record '999999999999' set
	char stk_snr[4];	// 종목SEQ, 종목SEQ 자리수 변경(3->4)
	char open_interest_clsf[2];	// 미결제약정구분, 전일 확정 : "M0" (07:40분경 제공)\n당일 잠정 : "M1" (장중 특정간격으로 변동종목\n         송신, 10초)\n당일 확정 : "M2" (당일 전종목 송신,\n         장종료 1시간후 제공)\n*당일잠정 첫번째 데이터는 장개시전협의거래분 누적
	char traded_date[8];	// 거래일자
	char open_interest_q[9];	// 미결제약정수량, 단위:계약
	char ff[1];	// End of Text, 0xFF
} K200_OPT_OPEN_INTEREST_DATA;


// K200옵션_매매증거금기준가 데이터
typedef struct _K200_OPT_TRD_MRG_STD_PRC_DATA {
	char data_clsf[2];	// DATA구분, H3
	char info_clsf[2];	// 정보구분, 03:KOSPI200지수옵션
	char mrk_clsf[1];	// 시장구분, 4
	char isin_clsf[12];	// 종목코드, 최종 record '999999999999' set
	char stk_snr[4];	// 종목SEQ, 종목SEQ 자리수 변경(3->4)
	char trd_mrg_std_prc[16];	// 매매증거금기준가, 예) 99999999.99999999
	char trd_mrg_std_prc_clsf[1];	// 매매증거금기준가구분, 0 : 증거금 기준가 없슴(최초 거래성립전 기세 포함)\n1 : 당일 종가(실세)\n2 : 당일 기세(최초 거래성립후 기세)\n -2012.05.14 삭제\n3 : 전일 증거금 기준가(거래성립후 종가 미형성)\n -2012.05.14 삭제\n4 : 당일 이론가(거래성립후 종가 미형성)\n5 : 조정전일증거금기준가(거래성립후 종가 미형성)\n -2012.05.14 삭제
	char opt_exec_right_set_prc[16];	// 옵션권리행사결제가격, 예) 99999999.99999999
	char opt_exec_right_set_prc_clsf[1];	// 옵션권리행사결제가격구분
	char ff[1];	// End of Text, 0xFF
} K200_OPT_TRD_MRG_STD_PRC_DATA;


// K200옵션_종목정보 데이터
typedef struct _K200_OPT_PRD_INFO_DATA {
	char data_clsf[2];	// DATA구분, AO
	char info_clsf[2];	// 정보구분, 03:KOSPI200지수옵션
	char mrk_clsf[1];	// 시장구분, 4
	char prd_cnt[5];	// 종목수
	char trd_date[8];	// 영업일자(입회일자)
	char isin_clsf[12];	// 종목코드, 최종 record '999999999999' set
	char stk_snr[6];	// 종목SEQ
	char prd_id[11];	// 상품ID, * 코드값 모음집 참조* 구명칭: 파생상품ID10 => 11, 20140303
	char sh_prd_code[9];	// 종목단축코드, 에) KR4101C90009 → K101C9000
	char prd_name_kor[80];	// 종목한글명
	char sh_prd_name_kor[40];	// 종목한글약명
	char prd_name_eng[80];	// 종목영문명
	char sh_prd_name_eng[40];	// 종목영문약명
	char listing_date[8];	// 상장일자
	char de_listing_date[8];	// 상장폐지일자
	char spread_clsf_code[1];	// 스프레드기준종목구분코드, 스프레드의 기준이 되는 종목의 ISIN 표준코드--코드값--F: 원월물(시간스프레드)N: 근월물(시간스프레드)20140303
	char final_sett_code[1];	// 최종결제방법코드, 현금결제, 실물인수도결제 등 파생상품의 최종결제 방법--코드값--C: 현금결제D: 실물인수도결제A: 현금+실물인수도결제0: 해당없음\n20140303
	char prc_limit_exp_dir[1];	// 가격제한확대적용방향코드, 가격제한이 다단계로 정의되는 경우 다음 단계로 확대되는 요건을 충족할 때 확대를 수행하는 방향## 코드값##X:미적용F:정방향B:역방향T:양방향
	char prc_limit_final_stg[3];	// 가격제한최종단계, 가격제한이 다단계로 정의되는 경우 제한의 최종단계번호
	char prc_limit_stg_1_hgh_sign[1];	// 가격제한1단계SIGN부호
	char prc_limit_stg_1_high_prc[12];	// 가격제한1단계상한가, 예) 9999999999.99
	char prc_limit_stg_1_low_sign[1];	// 가격제한1단계SIGN부호
	char prc_limit_stg_1_low_prc[12];	// 가격제한1단계하한가, 예) 9999999999.99
	char prc_limit_stg_2_high_sign[1];	// 가격제한2단계SIGN부호
	char prc_limit_stg_2_high_prc[12];	// 가격제한2단계상한가, 예) 9999999999.99
	char prc_limit_stg_2_low_sign[1];	// 가격제한2단계SIGN부호
	char prc_limit_stg_2_low_prc[12];	// 가격제한2단계하한가, 예) 9999999999.99
	char prc_limit_stg_3_high_sign[1];	// 가격제한3단계SIGN부호
	char prc_limit_stg_3_high_prc[12];	// 가격제한3단계상한가, 예) 9999999999.99
	char prc_limit_stg_3_low_sign[1];	// 가격제한3단계SIGN부호
	char prc_limit_stg_3_low_prc[12];	// 가격제한3단계하한가, 예) 9999999999.99
	char stand_prc[12];	// 기준가, 예) 9999999999.99
	char under_asset_id[3];	// 기초자산ID, 예) K2I:KOSPI200지수, KQI:코스닥150, Sxx:개별주식, BM3:신3년국채, BM5:신5년국채, BMA:신10년국채, CDR:CD, USD:미국달러, JPY:일본엔, EUR:유럽유로, GLD:금, LHG:돈육20140303
	char opt_type_code[1];	// 권리행사유형코드, A:미국형,E:유럽형,Z:기타
	char spread_str_code[2];	// 스프레드구성코드, Combination 호가를 대체할 스프레드물의 종목구성.--코드값--- T1: 최근월물+2째월물      > T2, T3, T4, ...\n*구명칭: 스프레드유형코드20140303
	char spread_prd_code_1[12];	// 스프레드구성종목코드1, * 구명칭: 스프레드근월물 종목코드근월물 표준코드20140303
	char spread_prd_code_2[12];	// 스프레드구성종목코드2, * 구명칭: 스프레드근월물 종목코드근월물 표준코드20140303
	char last_trading_date[8];	// 최종거래일자
	char final_sett_date[8];	// 최종결제일자
	char cont_month_nbr[3];	// 결제월번호, * 구명칭: 월물구분코드1:최근월물,선물스프레드2:2째월물3:3째월물4:4째월물5:5째월물6:6째월물7:7째월물      구 최근월물여부 대치\nX => 9, 1 => 3, 20140303
	char maturity_date[8];	// 만기일자, 권리행사 가능한 최종일자
	char exe_prc[17];	// 행사가격, 예) 999999999.99999999
	char adjust_clsf_code[1];	// 조정구분코드, 기초자산의 기준가격 조정이 정배수 조정(미결제조정)인지 비정배수 조정(거래승수조정)인지의 구분--코드값--N: 정상O: 미결제조정\nC: 거래승수조정20140303
	char prd_unit[17];	// 거래단위, 1계약에 해당하는 기초자산수량예) 999999999.99999999=> Exture에서는 1이었으나, Exture+에서는 500000임\n20140303
	char multiplier[21];	// 거래승수, 약정대금 및 결제시 사용하는 계산승수예) 9999999999999.99999999
	char mrk_cnst_code[1];	// 시장조성구분코드, 0:미시장조성종목1:당일시장조성종목2:과거시장조성종목
	char listing_type_code[1];	// 상장유형코드, 1:신규상장2:추가상장3:기존종목4:최초상장5:종목조정6:특별설정
	char atm_prc[12];	// 등가격, 기초자산기준가격에 가장 가까운 행사가격예) 9999999999.99
	char adj_reason_code[2];	// 조정사유코드, 00:해당사항없음, 01:권리락, 02:배당락,03:분배락, 04:권배락, 05:중간배당락,06:권리중간배당락, 99:기타
	char under_asset_prd_code[12];	// 기초자산종목코드
	char under_asset_close_prc[12];	// 기초자산종가, 예) 9999999999.99
	char left_until_maturity[7];	// 잔존일수
	char adj_std_prc[17];	// 조정기준가격, 주식파생상품의 기초주권 조정기준가격예) 999999999.99999999
	char std_prc_clsf_code[2];	// 기준가격구분코드, *선물spcace:기준가 없음(선물 스프레드종목)11:전일정산가12:전일기준가(거래성립전 종가미형성)13:당일이론가(거래성립전 종가미형성)\n14:전일기세(거래성립전 기세형성)  -2012.05.14 삭제15:당일이론가(거래성립전 기세형성)-  -2012.05.14 삭제\n16:조정된 전일정산가17:조정된 전일기준가  (거래성립전 종가미형성)18:조정된 전일기세(거래성립전 기세형성)  -2012.05.14 삭제\n19:전일 대상자산 종가(이론가없는 상품)*옵션21:전일증거금기준가22:전일기준가(거래성립전 종가미형성)23:당일이론가(거래성립전 종가미형성)\n24:전일기세(거래성립전 기세형성)  -2012.05.14 삭제25:조정된 전일증거금기준가26:조정된 전일기준가  (거래성립전 종가미형성)\n27:조정된 전일기세(거래성립전 기세형성)  -2012.05.14 삭제
	char trd_std_prc_clsf_code[1];	// 매매용기준가격구분코드, 0:해당없음1:실세2:기세3:이론가4:대상자산종가
	char yest_adj_close_prc_sign[1];	// SIGN부호
	char yest_adj_close_prc[17];	// 전일조정종가, 주식파생상품의 조정종가예) 999999999.99999999
	char block_trd_clsf[1];	// 협의대량매매대상여부, Y:협의매매상품, N:대상아님가능품목:3년물국채선물, 미국달러선물,      유로선물, 엔선물
	char yest_mrg_std_prc[17];	// 전일증거금기준가격, 예) 999999999.99999999
	char yest_mrg_std_prc_clsf_code[2];	// 전일증거금기준가격구분코드, *옵션20:증거금 기준가 없음21:당일종가(실세)22:당일기세(거래성립후기세)  -2012.05.14 삭제23:전일증거금기준가\n  (거래성립후 종가미형성)  -2012.05.14 삭제24:당일이론가(거래성립후 종가미형성)25:조정전일증거금기준가  (거래성립후 종가미형성)\n  -2012.05.14 삭제
	char sett_theory_prc[15];	// 정산이론가격, ※옵션의 경우 증거금기준가용 예) 999999999.999999
	char std_theory_prc[15];	// 기준이론가격, 예) 999999999.999999
	char yest_sett_prc[17];	// 전일정산가격, 예) 999999999.99999999
	char halt_trd_clsf[1];	// 거래정지여부, Y, N
	char ft_cb_high_prc[12];	// 선물Circuit_Breakers상한가, 선물 CB 발동조건을 판단하기 위한 상한가격(기준가대비 +/-5%가 CB 발동조건인 경우 +5%를 계산한 가격)예) 9999999999.99
	char ft_cb_low_prc[12];	// 선물Circuit_Breakers하한가, 선물 CB 발동조건을 판단하기 위한 상한가격(기준가대비 +/-5%가 CB 발동조건인 경우 -5%를 계산한 가격)예) 9999999999.99
	char check_exe_prc[17];	// 조회용행사가격, 예) 999999999.99999999
	char atm_clsf[1];	// ATM구분코드, 0:선물, 1:ATM, 2:ITM, 3:OTM
	char last_trading_clsf[1];	// 최종거래일여부, Y, N
	char ex_divid_aft_value[15];	// 배당락후배당가치, 주식 및 주가지수 상품에만 적용됨- 선물 : 배당락후미래가치- 옵션 : 배당락후현재가치예) 999999999.999999
	char yest_close_prc_sign[1];	// SIGN부호
	char yest_close_prc[12];	// 전일종가, 예) 9999999999.99
	char yest_close_prc_clsf[1];	// 전일종가구분코드, 1:실세, 3:거래무2:기세 -2012.05.14 삭제
	char yest_init_prc_sign[1];	// SIGN부호
	char yest_init_prc[12];	// 전일시가, 예) 9999999999.99
	char yest_high_prc_sign[1];	// SIGN부호
	char yest_high_pric[12];	// 전일고가, 예) 9999999999.99
	char yest_low_prc_sign[1];	// SIGN부호
	char yest_low_prc[12];	// 전일저가, 예) 9999999999.99
	char yest_first_exe_date[8];	// 최초체결일자
	char yest_last_exe_time[8];	// 전일최종체결시각
	char yest_sett_prc_clsf[2];	// 전일정산가격구분코드, *선물 10:정산가없음 11:당일종가(실세) 12:당일기세(거래성립후기세) 13:전일정산가(거래성립후 종가미형성)\n 14:당일이론가(거래성립후 종가미형성) 15:스프레드분 종가 16:조정된 전일 정산가 17:대상자산 종가(이론가없는 상품)
	char sett_prc_theory_prc_diff_pctg_sign[1];	// SIGN부호
	char sett_prc_theory_prc_diff_pctg[12];	// 정산가격이론가격괴리율, 에) 999999.999999
	char yest_open_interest_q[10];	// 전일미결제약정수량
	char yest_s_limit_ord_prc_sign[1];	// SIGN부호
	char yest_s_limit_ord_prc[12];	// 전일매도우선호가가격, 예) 9999999999.99
	char yest_l_limit_ord_prc_sign[1];	// SIGN부호
	char yest_l_limit_ord_prc[12];	// 전일매수우선호가가격, 예) 9999999999.99
	char implied_vol[10];	// 내재변동성, 예) 999999.9999
	char listed_high_prc_sign[1];	// SIGN부호
	char listed_high_prc[12];	// 상장중최고가, 예) 9999999999.99
	char listed_low_prc_sign[1];	// SIGN부호
	char listed_low_prc[12];	// 상장중최저가, 예) 9999999999.99
	char year_high_prc_sign[1];	// SIGN부호
	char year_high_prc[12];	// 연중최고가, 예) 9999999999.99
	char year_low_prc_sign[1];	// SIGN부호
	char year_low_prc[12];	// 연중최저가, 예) 9999999999.99
	char listed_high_prc_date[8];	// 상장중최고가일자
	char listed_low_prc_date[8];	// 상장중최저가일자
	char year_high_prc_date[8];	// 연중최고가일자
	char year_low_prc_date[8];	// 연중최저가일자
	char year_std_date[8];	// 연간기준일수
	char month_trd_date[8];	// 월간거래일수
	char year_trd_date[8];	// 연간거래일수
	char yest_exe_trd_cnt [16];	// 전일체결건수
	char yest_exe_q[12];	// 전일체결수량, 전일협의대량매매체결수량이 포함되지 않음
	char yest_trd_amt[22];	// 전일거래대금, 전일협의대량매매거래대금이 포함되지 않음
	char yest_block_trd_exe_q[12];	// 전일협의대량합산체결수량, 전일협의대량매매체결수량 => 전일협의대량합산체결수량 [전일체결수량+전일협의대량매매체결수량(협의대량+FLEX)];\n 2016.03.28 변경
	char yest_block_trd_total_amt[22];	// 전일협의대량합산거래대금, 전일협의대량매매거래대금 => 전일협의대량합산거래대금 [전일거래대금+전일협의대량매매거래대금(협의대량+FLEX)]; 2016.03.28 변경
	char cd_rate[6];	// CD금리, 예) 999.999
	char open_interest_q[15];	// 미결제한도수량, *적용일에 적용되는 상품의 계좌별 미결제 한도 계약수. 미결제 한도가 적용되지 않은 상품은 0*주식선물에만 해당\n8 => 15, 20140303
	char product_cat[4];	// 소속 상품군, *주식선물/옵션에만 해당
	char product_cat_off_pctg[9];	// 상품군 옵셋율, *백분율로 표시*주식선물/옵션에만 해당예) 9999999.995 => 9, 20140303
	char limit_ord_clsf_code[5];	// 지정가호가조건구분코드, 호가의 체결 및 잔류조건. Bitwise 정의--코드값--1: FAS (Fill And Store)2: FOK (Fill Or Kill)\n3: FAK (Fill And Kill)* 지정가호가조건구분코드 BITWISE 정의\n향후 확장성을 위해 해당 10진수값을 2진수로 변환하여 처리요망(최대 16bit까지 사용가능)예 ) 지정가호가조건구분코드 값이 6이면\n    (십진수 6 -> 이진수 00000110)0번째 bit 0 -> 0 : FAS1번째 bit 1 -> 2 : FOK\n2번째 bit 1 -> 4 : FAK즉, FOK이면서 FAK를 수용한다는 의미 (FOK & FAK)\nX => 9, 1 => 5, 20140303
	char mrk_ord_clsf_code[5];	// 시장가호가조건구분코드, * 상동
	char cond_limit_ord_clsf_code[5];	// 조건부지정가호가조건구분코드, * 상동
	char best_limit_ord_clsf_code[5];	// 최유리지정가호가조건구분코드, * 상동
	char efp_clsf[1];	// EFP거래대상여부, Y, N, 상품선물만 해당
	char flex_clsf[1];	// FLEX거래대상여부, Y, N, 상품선물만 해당
	char yest_efp_exe_q[12];	// 전일EFP체결수량, 상품선물만 해당
	char yest_efp_trd_amount[22];	// 전일EFP거래대금, 상품선물만 해당
	char mkr_close_clsf[1];	// 휴장여부, 휴장여부 (Y,N), 20121217
	char real_t_prc_limit_clsf[1];	// 실시간가격제한여부, 직전 체결가격 대비 특정 범위를 초과하는 호가는 거부하도록 제한할지 여부(Y/N) 20140901
	char real_t_high_price_gap_sign[1];	// SIGN부호, 20140901
	char real_t_high_price_gap[12];	// 실시간상한가간격, 직전 체결가격과 실시간상한가와의 간격 실시간상한가 = 직전체결가격 + 실시간상한가간격 ex) 9999999999.99 20140901
	char real_t_low_price_gap_sign[1];	// SIGN부호, 20140901
	char real_t_low_price_gap[12];	// 실시간하한가간격, 직전 체결가격과 실시간하한가와의 간격 실시간하한가 = 직전체결가격 + 실시간하한가간격(음수) ex) 9999999999.99 20140901
	char under_ass_mrk_id[3];	// 기초자산시장ID, 기초자산시장ID는 기초자산이 KRX에 상장된 경우에만 채워짐.K200선물옵션:STK코스닥150선물:KSQ주식선물옵션:STK/KSQ 상품선물옵션:SPACE변동성지수선물:STK섹터지수선물:STK미니K200선물옵션:STK
	char upper_limit_ord_q[16];	// 상한수량, 호가상한수량 (20181210 항목추가)
	char lower_limit_ord_q[16];	// 하한수량, 호가하한수량 (20181210 항목추가)
	char block_trd_upper_limit_ord_q[16];	// 협의대량매매상한수량, 협의대량매매호가상한수량 (20181210 항목추가)
	char block_trd_lower_limit_ord_q[16];	// 협의대량매매하한수량, 협의대량매매호가하한수량 (20181210 항목추가)
	char filler[60];	// Filler, 170 => 134, 20090831134 => 133, 20121217133 => 110, 20140303\n110 => 83, 2014090183  => 27, 2015061527  => 24, 20150720\n24 => 60 , 20181210 (스펙사이즈 변경 1200->1300)
	char ff[1];	// End of Text, 0xFF
} K200_OPT_PRD_INFO_DATA;


// K200옵션_민감도
typedef struct _K200_OPT_SENSITIVITY_DATA {
	char data_clsf[2];	// DATA구분, N7
	char info_clsf[2];	// 정보구분, 03:KOSPI200지수옵션
	char mrk_clsf[1];	// 시장구분, 4
	char isin_clsf[12];	// 종목코드
	char stk_snr[7];	// 종목SEQ
	char created_date[8];	// 생성일자
	char created_time[8];	// 생성시각
	char clsf_code[1];	// 구분코드, 1:전일확정,2:장중산출,E:장중완료,3:당일확정
	char under_asset_id[3];	// 기초자산ID, K2I:KOSPI200
	char sensitivity_delta_sign[1];	// SIGN부호
	char sensitivity_delta[18];	// 민감도 델타, 9(12)V9(6)
	char sensitivity_theta_sign[1];	// SIGN부호
	char sensitivity_theta[18];	// 민감도 쎄타, 9(12)V9(6)
	char sensitivity_vega_sign[1];	// SIGN부호
	char sensitivity_vega[18];	// 민감도 베가, 9(12)V9(6)
	char sensitivity_gamma_sign[1];	// SIGN부호
	char sensitivity_gamma[18];	// 민감도 감마, 9(12)V9(6)
	char sensitivity_rho_sign[1];	// SIGN부호
	char sensitivity_rho[18];	// 민감도 로, 9(12)V9(6)
	char ff[1];	// End of Text, 0xFF
} K200_OPT_SENSITIVITY_DATA;


// KOSPI200옵션 내재변동성
typedef struct _K200_OPT_IMPLIED_VOL_DATA {
	char data_clsf[2];	// DATA구분, P1
	char info_clsf[2];	// 정보구분, 03:KOSPI200지수옵션
	char mrk_clsf[1];	// 시장구분, 4
	char call_ave_implied_vol[10];	// 콜평균내재변동성, 999999v9999
	char put_ave_implied_vol[10];	// 풋평균내재변동성, 999999v9999
	char rep_implied_vol[10];	// 대표내재변동성, 999999v9999
	char hist_vol_90_days[10];	// 역사적변동성(90일), 999999v9999
	char ff[1];	// FF, END OF TEXT (0xFF)
} K200_OPT_IMPLIED_VOL_DATA;


// K200옵션_투자자 데이터
typedef struct _K200_OPT_INVESTOR_DATA {
	char data_clsf[2];	// DATA구분, H1
	char info_clsf[2];	// 정보구분, 03:KOSPI200지수옵션
	char mrk_clsf[1];	// 시장구분, 4
	char created_date[8];	// 생성일자
	char created_time[6];	// 생성시각
	char inv_data_clsf[2];	// 데이터구분, *전일확정 : 00, 당일잠정 : 01, 당일확정 : 02\n *E1 : 장중 데이터 완료, E2 : 확정 데이터 완료\n 최종 record '99' set\n *당일잠정 첫번째 데이터는 장개시전협의거래분 누적
	char prd_id[11];	// 상품ID, 코드값모음참조 - KRDRVOPK2I
	char opt_clsf[1];	// 옵션구분, C:콜옵션, P:풋옵션
	char inv_clsf[4];	// 투자자유형, 코드값모음 참조 *코드 '7000'시 수량,대금정보항목 0으로 전송
	char long_exe_q[9];	// 매수 약정수량
	char short_exe_q[9];	// 매도 약정수량
	char long_traded_amt[18];	// 매수 약정대금
	char short_traded_amt[18];	// 매도 약정대금
	char ff[1];	// End of Text, 0xFF
} K200_OPT_INVESTOR_DATA;


// K200옵션_시세Recovery 데이터
typedef struct _K200_OPT_RECOVERY_DATA {
	char data_clsf[2];	// DATA구분, B2
	char info_clsf[2];	// 정보구분, 03:KOSPI200지수옵션
	char mrk_clsf[1];	// 시장구분, 4
	char isin_clsf[12];	// 종목코드
	char stk_snr[4];	// 종목일련번호, 종목일련번호 자리수 변경(3->4)
	char cur_prc[5];	// 현재가, 예) 999.99
	char init_prc[5];	// 시가, 예) 999.99
	char high_prc[5];	// 고가, 예) 999.99
	char low_prc[5];	// 저가, 예) 999.99
	char open_interest_q[9];	// 미결제량
	char accm_exe_q[8];	// 누적체결수량
	char accm_trd_amt[11];	// 누적거래대금, 단위:천원
	char accm_block_trd_exe_q[8];	// 협의대량누적체결수량, 미제공(Filler)
	char l_or_s[1];	// 최종매도매수구분코드, 1:매도,2:매수(최종으로 들어온 호가의 매도매수구분값)
	char s_lvl_1_prc[5];	// 매도1호가, 예) 999.99
	char s_lvl_1_q[7];	// 매도1호가수량
	char s_lvl_1_trd_cnt[4];	// 매도1호가건수
	char l_lvl_1_prc[5];	// 매수1호가, 예) 999.99
	char l_lvl_1_q[7];	// 매수1호가수량
	char l_lvl_1_trd_cnt[4];	// 매수1호가건수
	char s_lvl_2_prc[5];	// 매도2호가, 예) 999.99
	char s_lvl_2_q[7];	// 매도2호가수량
	char s_lvl_2_trd_cnt[4];	// 매도2호가건수
	char l_lvl_2_prc[5];	// 매수2호가, 예) 999.99
	char l_lvl_2_q[7];	// 매수2호가수량
	char l_lvl_2_trd_cnt[4];	// 매수2호가건수
	char s_lvl_3_prc[5];	// 매도3호가, 예) 999.99
	char s_lvl_3_q[7];	// 매도3호가수량
	char s_lvl_3_trd_cnt[4];	// 매도3호가건수
	char l_lvl_3_prc[5];	// 매수3호가, 예) 999.99
	char l_lvl_3_q[7];	// 매수3호가수량
	char l_lvl_3_trd_cnt[4];	// 매수3호가건수
	char s_lvl_4_prc[5];	// 매도4호가, 예) 999.99
	char s_lvl_4_q[7];	// 매도4호가수량
	char s_lvl_4_trd_cnt[4];	// 매도4호가건수
	char l_lvl_4_prc[5];	// 매수4호가, 예) 999.99
	char l_lvl_4_q[7];	// 매수4호가수량
	char l_lvl_4_trd_cnt[4];	// 매수4호가건수
	char s_lvl_5_prc[5];	// 매도5호가, 예) 999.99
	char s_lvl_5_q[7];	// 매도5호가수량
	char s_lvl_5_trd_cnt[4];	// 매도5호가건수
	char l_lvl_5_prc[5];	// 매수5호가, 예) 999.99
	char l_lvl_5_q[7];	// 매수5호가수량
	char l_lvl_5_trd_cnt[4];	// 매수5호가건수
	char total_s_limit_ord_q[7];	// 매도 총호가수량
	char total_s_trd_cnt[5];	// 매도유효호가건수
	char total_l_limit_ord_q[7];	// 매수 총호가수량
	char total_l_trd_cnt[5];	// 매수유효호가건수
	char ss_id[2];	// 세션ID, 코드값모음참조
	char brd_id[2];	// 보드ID, 코드값모음참조
	char brd_event_id[3];	// 보드이벤트ID, B2 에서는 보드이벤트ID 사용금지(과거 상태값이 전송될 수 있음). 추후, 해당 항목 '000' 세팅 예정. 2014.03.24)
	char exp_prc[5];	// 예상체결가격, 예) 999.99 단일가매매시만 제공\n (장상태구분코드:10,20,30,80)
	char real_t_high_prc[5];	// 실시간상한가, 예) 999.99 개발가이드참조
	char real_t_low_prc[5];	// 실시간하한가, 예) 999.99 개발가이드참조
	char ff[1];	// End of Text, 0xFF
} K200_OPT_RECOVERY_DATA;


// K200옵션_Polling 데이터
typedef struct _K200_OPT_POLLING_DATA {
	char data_clsf[2];	// DATA구분, I2
	char info_clsf[2];	// 정보구분, 03:KOSPI200지수옵션
	char mrk_clsf[1];	// 시장구분, 4
	char send_t[4];	// 전송시간, HHSS
	char main_backup_clsf[2];	// Main Backup구분, space
	char filler[8];	// Filler
	char ff[1];	// End of Text, 0xFF
} K200_OPT_POLLING_DATA;


// K200옵션_장개시전협의거래
typedef struct _K200_OPT_BLOCK_TRD_BEF_MRK_OPEN {
	char data_clsf[2];	// DATA구분, M7
	char info_clsf[2];	// 정보구분, 03:KOSPI200지수옵션
	char mrk_clsf[1];	// 시장구분, 4
	char isin_clsf[12];	// 종목코드, 최종 record '999999999999' set
	char stk_snr[4];	// 종목SEQ, 종목SEQ 자리수 변경(3->4)
	char exe_prc[5];	// 체결가격, 예) 999.99 (전송당일 종목별 기준가격)
	char exe_q[7];	// 체결수량, 장개시전협의거래 체결 수량을 모두 합산한 수량
	char exe_clsf_code[2];	// 체결유형코드, 협의거래\n 46 : EUREX
	char filler[15];	// Filler
	char ff[1];	// End of Text, 0xFF
} K200_OPT_BLOCK_TRD_BEF_MRK_OPEN;
