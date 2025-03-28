// ps_stock_futures.c
// 개별주식선물
// 주석에 \n이 들어간건 나중에 이쁘게 바꿔야함

#include "ps_stock_futures.h"


extern int     Str2Int(char *str, int size);
extern double  Str2Dbl(char *str, int size, int point);
extern double  Str2SignDouble(char *str, int size, int point);


// 주식선물_체결
int ParseA3015(const double& timestamp, const char* in_buff, DF_STOCK_FUT_EXEC* out) {
	STOCK_FUT_EXEC* data = (STOCK_FUT_EXEC*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA구분, A3
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// 정보구분, 01:개별주식선물
	out->mrk_clsf = data->mrk_clsf[0];	//시장구분, 5
	memcpy(out->isin_clsf, data->isin_clsf, sizeof(data->isin_clsf));	// 종목코드
	out->stk_snr = Str2Int(data->stk_snr, sizeof(data->stk_snr));	// 종목일련번호
	memcpy(out->brd_id, data->brd_id, sizeof(data->brd_id));	// 보드ID, 코드값모음참조
	out->cur_prc = Str2Int(data->cur_prc, sizeof(data->cur_prc));	// 현재가격
	out->exe_q = Str2Int(data->exe_q, sizeof(data->exe_q));	// 체결수량
	memcpy(out->ss_id, data->ss_id, sizeof(data->ss_id));	// 세션ID, 코드값모음참조
	memcpy(out->exe_t, data->exe_t, sizeof(data->exe_t));	// 체결시각
	out->rct_prd_prc = Str2Int(data->rct_prd_prc, sizeof(data->rct_prd_prc));	// 최근월물의제약정가격
	out->nxt_prd_prc = Str2Int(data->nxt_prd_prc, sizeof(data->nxt_prd_prc));	// 원월물의제약정가격
	out->init_prc = Str2Int(data->init_prc, sizeof(data->init_prc));	// 시가
	out->high_prc = Str2Int(data->high_prc, sizeof(data->high_prc));	// 고가
	out->low_prc = Str2Int(data->low_prc, sizeof(data->low_prc));	// 저가
	out->pri_prc = Str2Int(data->pri_prc, sizeof(data->pri_prc));	// 직전가격
	out->accm_exe_q = Str2Int(data->accm_exe_q, sizeof(data->accm_exe_q));	// 누적체결수량
	out->accm_trd_amt = Str2Dbl(data->accm_trd_amt, sizeof(data->accm_trd_amt), 0);	// 누적거래대금, 단위:원
	out->l_or_s = data->l_or_s[0];	//최종매도매수구분코드, 1:매도,2:매수(최종으로 들어온 호가의 매도매수구분값)
	out->real_t_high_prc = Str2Int(data->real_t_high_prc, sizeof(data->real_t_high_prc));	// 실시간상한가, 개발가이드참조
	out->real_t_low_prc = Str2Int(data->real_t_low_prc, sizeof(data->real_t_low_prc));	// 실시간하한가, 개발가이드참조

	return 1;
}


// 주식선물_우선호가
int ParseB6015(const double& timestamp, const char* in_buff, DF_STOCK_FUT_LIMIT_ORD* out) {
	STOCK_FUT_LIMIT_ORD* data = (STOCK_FUT_LIMIT_ORD*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA구분, B6
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// 정보구분, 01:개별주식선물
	out->mrk_clsf = data->mrk_clsf[0];	//시장구분, 5
	memcpy(out->isin_clsf, data->isin_clsf, sizeof(data->isin_clsf));	// 종목코드
	out->stk_snr = Str2Int(data->stk_snr, sizeof(data->stk_snr));	// 종목일련번호
	memcpy(out->brd_id, data->brd_id, sizeof(data->brd_id));	// 보드ID, 코드값모음참조
	memcpy(out->ss_id, data->ss_id, sizeof(data->ss_id));	// 세션ID, 코드값모음참조
	out->total_l_limit_ord_q = Str2Int(data->total_l_limit_ord_q, sizeof(data->total_l_limit_ord_q));	// 매수총호가잔량, 자리수 변경(7->8)
	out->l_lvl_1_prc = Str2Int(data->l_lvl_1_prc, sizeof(data->l_lvl_1_prc));	// 매수1단계우선호가가격
	out->l_lvl_1_q = Str2Int(data->l_lvl_1_q, sizeof(data->l_lvl_1_q));	// 매수1단계우선호가잔량, 자리수 변경(6->7)
	out->l_lvl_2_prc = Str2Int(data->l_lvl_2_prc, sizeof(data->l_lvl_2_prc));	// 매수2단계우선호가가격
	out->l_lvl_2_q = Str2Int(data->l_lvl_2_q, sizeof(data->l_lvl_2_q));	// 매수2단계우선호가잔량, 자리수 변경(6->7)
	out->l_lvl_3_prc = Str2Int(data->l_lvl_3_prc, sizeof(data->l_lvl_3_prc));	// 매수3단계우선호가가격
	out->l_lvl_3_q = Str2Int(data->l_lvl_3_q, sizeof(data->l_lvl_3_q));	// 매수3단계우선호가잔량, 자리수 변경(6->7)
	out->l_lvl_4_prc = Str2Int(data->l_lvl_4_prc, sizeof(data->l_lvl_4_prc));	// 매수4단계우선호가가격
	out->l_lvl_4_q = Str2Int(data->l_lvl_4_q, sizeof(data->l_lvl_4_q));	// 매수4단계우선호가잔량, 자리수 변경(6->7)
	out->l_lvl_5_prc = Str2Int(data->l_lvl_5_prc, sizeof(data->l_lvl_5_prc));	// 매수5단계우선호가가격
	out->l_lvl_5_q = Str2Int(data->l_lvl_5_q, sizeof(data->l_lvl_5_q));	// 매수5단계우선호가잔량, 자리수 변경(6->7)
	out->l_lvl_6_prc = Str2Int(data->l_lvl_6_prc, sizeof(data->l_lvl_6_prc));	// 매수6단계우선호가가격
	out->l_lvl_6_q = Str2Int(data->l_lvl_6_q, sizeof(data->l_lvl_6_q));	// 매수6단계우선호가잔량, 자리수 변경(6->7)
	out->l_lvl_7_prc = Str2Int(data->l_lvl_7_prc, sizeof(data->l_lvl_7_prc));	// 매수7단계우선호가가격
	out->l_lvl_7_q = Str2Int(data->l_lvl_7_q, sizeof(data->l_lvl_7_q));	// 매수7단계우선호가잔량, 자리수 변경(6->7)
	out->l_lvl_8_prc = Str2Int(data->l_lvl_8_prc, sizeof(data->l_lvl_8_prc));	// 매수8단계우선호가가격
	out->l_lvl_8_q = Str2Int(data->l_lvl_8_q, sizeof(data->l_lvl_8_q));	// 매수8단계우선호가잔량, 자리수 변경(6->7)
	out->l_lvl_9_prc = Str2Int(data->l_lvl_9_prc, sizeof(data->l_lvl_9_prc));	// 매수9단계우선호가가격
	out->l_lvl_9_q = Str2Int(data->l_lvl_9_q, sizeof(data->l_lvl_9_q));	// 매수9단계우선호가잔량, 자리수 변경(6->7)
	out->l_lvl_10_prc = Str2Int(data->l_lvl_10_prc, sizeof(data->l_lvl_10_prc));	// 매수10단계우선호가가격
	out->l_lvl_10_q = Str2Int(data->l_lvl_10_q, sizeof(data->l_lvl_10_q));	// 매수10단계우선호가잔량, 자리수 변경(6->7)
	out->total_s_limit_ord_q = Str2Int(data->total_s_limit_ord_q, sizeof(data->total_s_limit_ord_q));	// 매도총호가잔량, 자리수 변경(7->8)
	out->s_lvl_1_prc = Str2Int(data->s_lvl_1_prc, sizeof(data->s_lvl_1_prc));	// 매도1단계우선호가가격
	out->s_lvl_1_q = Str2Int(data->s_lvl_1_q, sizeof(data->s_lvl_1_q));	// 매도1단계우선호가잔량, 자리수 변경(6->7)
	out->s_lvl_2_prc = Str2Int(data->s_lvl_2_prc, sizeof(data->s_lvl_2_prc));	// 매도2단계우선호가가격
	out->s_lvl_2_q = Str2Int(data->s_lvl_2_q, sizeof(data->s_lvl_2_q));	// 매도2단계우선호가잔량, 자리수 변경(6->7)
	out->s_lvl_3_prc = Str2Int(data->s_lvl_3_prc, sizeof(data->s_lvl_3_prc));	// 매도3단계우선호가가격
	out->s_lvl_3_q = Str2Int(data->s_lvl_3_q, sizeof(data->s_lvl_3_q));	// 매도3단계우선호가잔량, 자리수 변경(6->7)
	out->s_lvl_4_prc = Str2Int(data->s_lvl_4_prc, sizeof(data->s_lvl_4_prc));	// 매도4단계우선호가가격
	out->s_lvl_4_q = Str2Int(data->s_lvl_4_q, sizeof(data->s_lvl_4_q));	// 매도4단계우선호가잔량, 자리수 변경(6->7)
	out->s_lvl_5_prc = Str2Int(data->s_lvl_5_prc, sizeof(data->s_lvl_5_prc));	// 매도5단계우선호가가격
	out->s_lvl_5_q = Str2Int(data->s_lvl_5_q, sizeof(data->s_lvl_5_q));	// 매도5단계우선호가잔량, 자리수 변경(6->7)
	out->s_lvl_6_prc = Str2Int(data->s_lvl_6_prc, sizeof(data->s_lvl_6_prc));	// 매도6단계우선호가가격
	out->s_lvl_6_q = Str2Int(data->s_lvl_6_q, sizeof(data->s_lvl_6_q));	// 매도6단계우선호가잔량, 자리수 변경(6->7)
	out->s_lvl_7_prc = Str2Int(data->s_lvl_7_prc, sizeof(data->s_lvl_7_prc));	// 매도7단계우선호가가격
	out->s_lvl_7_q = Str2Int(data->s_lvl_7_q, sizeof(data->s_lvl_7_q));	// 매도7단계우선호가잔량, 자리수 변경(6->7)
	out->s_lvl_8_prc = Str2Int(data->s_lvl_8_prc, sizeof(data->s_lvl_8_prc));	// 매도8단계우선호가가격
	out->s_lvl_8_q = Str2Int(data->s_lvl_8_q, sizeof(data->s_lvl_8_q));	// 매도8단계우선호가잔량, 자리수 변경(6->7)
	out->s_lvl_9_prc = Str2Int(data->s_lvl_9_prc, sizeof(data->s_lvl_9_prc));	// 매도9단계우선호가가격
	out->s_lvl_9_q = Str2Int(data->s_lvl_9_q, sizeof(data->s_lvl_9_q));	// 매도9단계우선호가잔량, 자리수 변경(6->7)
	out->s_lvl_10_prc = Str2Int(data->s_lvl_10_prc, sizeof(data->s_lvl_10_prc));	// 매도10단계우선호가가격
	out->s_lvl_10_q = Str2Int(data->s_lvl_10_q, sizeof(data->s_lvl_10_q));	// 매도10단계우선호가잔량, 자리수 변경(6->7)
	out->total_l_trd_cnt = Str2Int(data->total_l_trd_cnt, sizeof(data->total_l_trd_cnt));	// 매수유효호가건수
	out->l_lvl_1_trd_cnt = Str2Int(data->l_lvl_1_trd_cnt, sizeof(data->l_lvl_1_trd_cnt));	// 매수1단계우선호가건수
	out->l_lvl_2_trd_cnt = Str2Int(data->l_lvl_2_trd_cnt, sizeof(data->l_lvl_2_trd_cnt));	// 매수2단계우선호가건수
	out->l_lvl_3_trd_cnt = Str2Int(data->l_lvl_3_trd_cnt, sizeof(data->l_lvl_3_trd_cnt));	// 매수3단계우선호가건수
	out->l_lvl_4_trd_cnt = Str2Int(data->l_lvl_4_trd_cnt, sizeof(data->l_lvl_4_trd_cnt));	// 매수4단계우선호가건수
	out->l_lvl_5_trd_cnt = Str2Int(data->l_lvl_5_trd_cnt, sizeof(data->l_lvl_5_trd_cnt));	// 매수5단계우선호가건수
	out->l_lvl_6_trd_cnt = Str2Int(data->l_lvl_6_trd_cnt, sizeof(data->l_lvl_6_trd_cnt));	// 매수6단계우선호가건수
	out->l_lvl_7_trd_cnt = Str2Int(data->l_lvl_7_trd_cnt, sizeof(data->l_lvl_7_trd_cnt));	// 매수7단계우선호가건수
	out->l_lvl_8_trd_cnt = Str2Int(data->l_lvl_8_trd_cnt, sizeof(data->l_lvl_8_trd_cnt));	// 매수8단계우선호가건수
	out->l_lvl_9_trd_cnt = Str2Int(data->l_lvl_9_trd_cnt, sizeof(data->l_lvl_9_trd_cnt));	// 매수9단계우선호가건수
	out->l_lvl_10_trd_cnt = Str2Int(data->l_lvl_10_trd_cnt, sizeof(data->l_lvl_10_trd_cnt));	// 매수10단계우선호가건수
	out->total_s_trd_cnt = Str2Int(data->total_s_trd_cnt, sizeof(data->total_s_trd_cnt));	// 매도유효호가건수
	out->s_lvl_1_trd_cnt = Str2Int(data->s_lvl_1_trd_cnt, sizeof(data->s_lvl_1_trd_cnt));	// 매도1단계우선호가건수
	out->s_lvl_2_trd_cnt = Str2Int(data->s_lvl_2_trd_cnt, sizeof(data->s_lvl_2_trd_cnt));	// 매도2단계우선호가건수
	out->s_lvl_3_trd_cnt = Str2Int(data->s_lvl_3_trd_cnt, sizeof(data->s_lvl_3_trd_cnt));	// 매도3단계우선호가건수
	out->s_lvl_4_trd_cnt = Str2Int(data->s_lvl_4_trd_cnt, sizeof(data->s_lvl_4_trd_cnt));	// 매도4단계우선호가건수
	out->s_lvl_5_trd_cnt = Str2Int(data->s_lvl_5_trd_cnt, sizeof(data->s_lvl_5_trd_cnt));	// 매도5단계우선호가건수
	out->s_lvl_6_trd_cnt = Str2Int(data->s_lvl_6_trd_cnt, sizeof(data->s_lvl_6_trd_cnt));	// 매도6단계우선호가건수
	out->s_lvl_7_trd_cnt = Str2Int(data->s_lvl_7_trd_cnt, sizeof(data->s_lvl_7_trd_cnt));	// 매도7단계우선호가건수
	out->s_lvl_8_trd_cnt = Str2Int(data->s_lvl_8_trd_cnt, sizeof(data->s_lvl_8_trd_cnt));	// 매도8단계우선호가건수
	out->s_lvl_9_trd_cnt = Str2Int(data->s_lvl_9_trd_cnt, sizeof(data->s_lvl_9_trd_cnt));	// 매도9단계우선호가건수
	out->s_lvl_10_trd_cnt = Str2Int(data->s_lvl_10_trd_cnt, sizeof(data->s_lvl_10_trd_cnt));	// 매도10단계우선호가건수
	memcpy(out->ord_rcv_t, data->ord_rcv_t, sizeof(data->ord_rcv_t));	// 호가접수시각
	out->exp_prc = Str2Int(data->exp_prc, sizeof(data->exp_prc));	// 예상체결가격, 단일가매매시만 제공\n (장상태구분코드:10,20,30,80)

	return 1;
}


// 주식선물_체결_우선호가
int ParseG7015(const double& timestamp, const char* in_buff, DF_STOCK_FUT_EXEC_LIMIT_ORD* out) {
	STOCK_FUT_EXEC_LIMIT_ORD* data = (STOCK_FUT_EXEC_LIMIT_ORD*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA구분, G7
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// 정보구분, 01:개별주식선물
	out->mrk_clsf = data->mrk_clsf[0];	//시장구분, 5
	memcpy(out->isin_clsf, data->isin_clsf, sizeof(data->isin_clsf));	// 종목코드
	out->stk_snr = Str2Int(data->stk_snr, sizeof(data->stk_snr));	// 종목일련번호
	memcpy(out->brd_id, data->brd_id, sizeof(data->brd_id));	// 보드ID, 코드값모음참조
	out->cur_prc = Str2Int(data->cur_prc, sizeof(data->cur_prc));	// 현재가격
	out->exe_q = Str2Int(data->exe_q, sizeof(data->exe_q));	// 체결수량
	memcpy(out->ss_id, data->ss_id, sizeof(data->ss_id));	// 세션ID, 코드값모음참조
	memcpy(out->exe_t, data->exe_t, sizeof(data->exe_t));	// 체결시각
	out->rct_prd_prc = Str2Int(data->rct_prd_prc, sizeof(data->rct_prd_prc));	// 최근월물의제약정가격
	out->nxt_prd_prc = Str2Int(data->nxt_prd_prc, sizeof(data->nxt_prd_prc));	// 원월물의제약정가격
	out->init_prc = Str2Int(data->init_prc, sizeof(data->init_prc));	// 시가
	out->high_prc = Str2Int(data->high_prc, sizeof(data->high_prc));	// 고가
	out->low_prc = Str2Int(data->low_prc, sizeof(data->low_prc));	// 저가
	out->pri_prc = Str2Int(data->pri_prc, sizeof(data->pri_prc));	// 직전가격
	out->accm_exe_q = Str2Int(data->accm_exe_q, sizeof(data->accm_exe_q));	// 누적체결수량
	out->accm_trd_amt = Str2Dbl(data->accm_trd_amt, sizeof(data->accm_trd_amt), 0);	// 누적거래대금, 단위:원
	out->l_or_s = data->l_or_s[0];	//최종매도매수구분코드, 1:매도,2:매수(최종으로 들어온 호가의 매도매수구분값)
	out->total_l_limit_ord_q = Str2Int(data->total_l_limit_ord_q, sizeof(data->total_l_limit_ord_q));	// 매수총호가잔량, 자리수 변경(7->8)
	out->l_lvl_1_prc = Str2Int(data->l_lvl_1_prc, sizeof(data->l_lvl_1_prc));	// 매수1단계우선호가가격
	out->l_lvl_1_q = Str2Int(data->l_lvl_1_q, sizeof(data->l_lvl_1_q));	// 매수1단계우선호가잔량, 자리수 변경(6->7)
	out->l_lvl_2_prc = Str2Int(data->l_lvl_2_prc, sizeof(data->l_lvl_2_prc));	// 매수2단계우선호가가격
	out->l_lvl_2_q = Str2Int(data->l_lvl_2_q, sizeof(data->l_lvl_2_q));	// 매수2단계우선호가잔량, 자리수 변경(6->7)
	out->l_lvl_3_prc = Str2Int(data->l_lvl_3_prc, sizeof(data->l_lvl_3_prc));	// 매수3단계우선호가가격
	out->l_lvl_3_q = Str2Int(data->l_lvl_3_q, sizeof(data->l_lvl_3_q));	// 매수3단계우선호가잔량, 자리수 변경(6->7)
	out->l_lvl_4_prc = Str2Int(data->l_lvl_4_prc, sizeof(data->l_lvl_4_prc));	// 매수4단계우선호가가격
	out->l_lvl_4_q = Str2Int(data->l_lvl_4_q, sizeof(data->l_lvl_4_q));	// 매수4단계우선호가잔량, 자리수 변경(6->7)
	out->l_lvl_5_prc = Str2Int(data->l_lvl_5_prc, sizeof(data->l_lvl_5_prc));	// 매수5단계우선호가가격
	out->l_lvl_5_q = Str2Int(data->l_lvl_5_q, sizeof(data->l_lvl_5_q));	// 매수5단계우선호가잔량, 자리수 변경(6->7)
	out->l_lvl_6_prc = Str2Int(data->l_lvl_6_prc, sizeof(data->l_lvl_6_prc));	// 매수6단계우선호가가격
	out->l_lvl_6_q = Str2Int(data->l_lvl_6_q, sizeof(data->l_lvl_6_q));	// 매수6단계우선호가잔량, 자리수 변경(6->7)
	out->l_lvl_7_prc = Str2Int(data->l_lvl_7_prc, sizeof(data->l_lvl_7_prc));	// 매수7단계우선호가가격
	out->l_lvl_7_q = Str2Int(data->l_lvl_7_q, sizeof(data->l_lvl_7_q));	// 매수7단계우선호가잔량, 자리수 변경(6->7)
	out->l_lvl_8_prc = Str2Int(data->l_lvl_8_prc, sizeof(data->l_lvl_8_prc));	// 매수8단계우선호가가격
	out->l_lvl_8_q = Str2Int(data->l_lvl_8_q, sizeof(data->l_lvl_8_q));	// 매수8단계우선호가잔량, 자리수 변경(6->7)
	out->l_lvl_9_prc = Str2Int(data->l_lvl_9_prc, sizeof(data->l_lvl_9_prc));	// 매수9단계우선호가가격
	out->l_lvl_9_q = Str2Int(data->l_lvl_9_q, sizeof(data->l_lvl_9_q));	// 매수9단계우선호가잔량, 자리수 변경(6->7)
	out->l_lvl_10_prc = Str2Int(data->l_lvl_10_prc, sizeof(data->l_lvl_10_prc));	// 매수10단계우선호가가격
	out->l_lvl_10_q = Str2Int(data->l_lvl_10_q, sizeof(data->l_lvl_10_q));	// 매수10단계우선호가잔량, 자리수 변경(6->7)
	out->total_s_limit_ord_q = Str2Int(data->total_s_limit_ord_q, sizeof(data->total_s_limit_ord_q));	// 매도총호가잔량, 자리수 변경(7->8)
	out->s_lvl_1_prc = Str2Int(data->s_lvl_1_prc, sizeof(data->s_lvl_1_prc));	// 매도1단계우선호가가격
	out->s_lvl_1_q = Str2Int(data->s_lvl_1_q, sizeof(data->s_lvl_1_q));	// 매도1단계우선호가잔량, 자리수 변경(6->7)
	out->s_lvl_2_prc = Str2Int(data->s_lvl_2_prc, sizeof(data->s_lvl_2_prc));	// 매도2단계우선호가가격
	out->s_lvl_2_q = Str2Int(data->s_lvl_2_q, sizeof(data->s_lvl_2_q));	// 매도2단계우선호가잔량, 자리수 변경(6->7)
	out->s_lvl_3_prc = Str2Int(data->s_lvl_3_prc, sizeof(data->s_lvl_3_prc));	// 매도3단계우선호가가격
	out->s_lvl_3_q = Str2Int(data->s_lvl_3_q, sizeof(data->s_lvl_3_q));	// 매도3단계우선호가잔량, 자리수 변경(6->7)
	out->s_lvl_4_prc = Str2Int(data->s_lvl_4_prc, sizeof(data->s_lvl_4_prc));	// 매도4단계우선호가가격
	out->s_lvl_4_q = Str2Int(data->s_lvl_4_q, sizeof(data->s_lvl_4_q));	// 매도4단계우선호가잔량, 자리수 변경(6->7)
	out->s_lvl_5_prc = Str2Int(data->s_lvl_5_prc, sizeof(data->s_lvl_5_prc));	// 매도5단계우선호가가격
	out->s_lvl_5_q = Str2Int(data->s_lvl_5_q, sizeof(data->s_lvl_5_q));	// 매도5단계우선호가잔량, 자리수 변경(6->7)
	out->s_lvl_6_prc = Str2Int(data->s_lvl_6_prc, sizeof(data->s_lvl_6_prc));	// 매도6단계우선호가가격
	out->s_lvl_6_q = Str2Int(data->s_lvl_6_q, sizeof(data->s_lvl_6_q));	// 매도6단계우선호가잔량, 자리수 변경(6->7)
	out->s_lvl_7_prc = Str2Int(data->s_lvl_7_prc, sizeof(data->s_lvl_7_prc));	// 매도7단계우선호가가격
	out->s_lvl_7_q = Str2Int(data->s_lvl_7_q, sizeof(data->s_lvl_7_q));	// 매도7단계우선호가잔량, 자리수 변경(6->7)
	out->s_lvl_8_prc = Str2Int(data->s_lvl_8_prc, sizeof(data->s_lvl_8_prc));	// 매도8단계우선호가가격
	out->s_lvl_8_q = Str2Int(data->s_lvl_8_q, sizeof(data->s_lvl_8_q));	// 매도8단계우선호가잔량, 자리수 변경(6->7)
	out->s_lvl_9_prc = Str2Int(data->s_lvl_9_prc, sizeof(data->s_lvl_9_prc));	// 매도9단계우선호가가격
	out->s_lvl_9_q = Str2Int(data->s_lvl_9_q, sizeof(data->s_lvl_9_q));	// 매도9단계우선호가잔량, 자리수 변경(6->7)
	out->s_lvl_10_prc = Str2Int(data->s_lvl_10_prc, sizeof(data->s_lvl_10_prc));	// 매도10단계우선호가가격
	out->s_lvl_10_q = Str2Int(data->s_lvl_10_q, sizeof(data->s_lvl_10_q));	// 매도10단계우선호가잔량, 자리수 변경(6->7)
	out->total_l_trd_cnt = Str2Int(data->total_l_trd_cnt, sizeof(data->total_l_trd_cnt));	// 매수유효호가건수
	out->l_lvl_1_trd_cnt = Str2Int(data->l_lvl_1_trd_cnt, sizeof(data->l_lvl_1_trd_cnt));	// 매수1단계우선호가건수
	out->l_lvl_2_trd_cnt = Str2Int(data->l_lvl_2_trd_cnt, sizeof(data->l_lvl_2_trd_cnt));	// 매수2단계우선호가건수
	out->l_lvl_3_trd_cnt = Str2Int(data->l_lvl_3_trd_cnt, sizeof(data->l_lvl_3_trd_cnt));	// 매수3단계우선호가건수
	out->l_lvl_4_trd_cnt = Str2Int(data->l_lvl_4_trd_cnt, sizeof(data->l_lvl_4_trd_cnt));	// 매수4단계우선호가건수
	out->l_lvl_5_trd_cnt = Str2Int(data->l_lvl_5_trd_cnt, sizeof(data->l_lvl_5_trd_cnt));	// 매수5단계우선호가건수
	out->l_lvl_6_trd_cnt = Str2Int(data->l_lvl_6_trd_cnt, sizeof(data->l_lvl_6_trd_cnt));	// 매수6단계우선호가건수
	out->l_lvl_7_trd_cnt = Str2Int(data->l_lvl_7_trd_cnt, sizeof(data->l_lvl_7_trd_cnt));	// 매수7단계우선호가건수
	out->l_lvl_8_trd_cnt = Str2Int(data->l_lvl_8_trd_cnt, sizeof(data->l_lvl_8_trd_cnt));	// 매수8단계우선호가건수
	out->l_lvl_9_trd_cnt = Str2Int(data->l_lvl_9_trd_cnt, sizeof(data->l_lvl_9_trd_cnt));	// 매수9단계우선호가건수
	out->l_lvl_10_trd_cnt = Str2Int(data->l_lvl_10_trd_cnt, sizeof(data->l_lvl_10_trd_cnt));	// 매수10단계우선호가건수
	out->total_s_trd_cnt = Str2Int(data->total_s_trd_cnt, sizeof(data->total_s_trd_cnt));	// 매도유효호가건수
	out->s_lvl_1_trd_cnt = Str2Int(data->s_lvl_1_trd_cnt, sizeof(data->s_lvl_1_trd_cnt));	// 매도1단계우선호가건수
	out->s_lvl_2_trd_cnt = Str2Int(data->s_lvl_2_trd_cnt, sizeof(data->s_lvl_2_trd_cnt));	// 매도2단계우선호가건수
	out->s_lvl_3_trd_cnt = Str2Int(data->s_lvl_3_trd_cnt, sizeof(data->s_lvl_3_trd_cnt));	// 매도3단계우선호가건수
	out->s_lvl_4_trd_cnt = Str2Int(data->s_lvl_4_trd_cnt, sizeof(data->s_lvl_4_trd_cnt));	// 매도4단계우선호가건수
	out->s_lvl_5_trd_cnt = Str2Int(data->s_lvl_5_trd_cnt, sizeof(data->s_lvl_5_trd_cnt));	// 매도5단계우선호가건수
	out->s_lvl_6_trd_cnt = Str2Int(data->s_lvl_6_trd_cnt, sizeof(data->s_lvl_6_trd_cnt));	// 매도6단계우선호가건수
	out->s_lvl_7_trd_cnt = Str2Int(data->s_lvl_7_trd_cnt, sizeof(data->s_lvl_7_trd_cnt));	// 매도7단계우선호가건수
	out->s_lvl_8_trd_cnt = Str2Int(data->s_lvl_8_trd_cnt, sizeof(data->s_lvl_8_trd_cnt));	// 매도8단계우선호가건수
	out->s_lvl_9_trd_cnt = Str2Int(data->s_lvl_9_trd_cnt, sizeof(data->s_lvl_9_trd_cnt));	// 매도9단계우선호가건수
	out->s_lvl_10_trd_cnt = Str2Int(data->s_lvl_10_trd_cnt, sizeof(data->s_lvl_10_trd_cnt));	// 매도10단계우선호가건수
	out->real_t_high_prc = Str2Int(data->real_t_high_prc, sizeof(data->real_t_high_prc));	// 실시간상한가, 개발가이드참조
	out->real_t_low_prc = Str2Int(data->real_t_low_prc, sizeof(data->real_t_low_prc));	// 실시간하한가, 개발가이드참조

	return 1;
}


// 주식선물_종목마감
int ParseA6015(const double& timestamp, const char* in_buff, DF_STOCK_FUT_CLOSE_PRODUCT* out) {
	STOCK_FUT_CLOSE_PRODUCT* data = (STOCK_FUT_CLOSE_PRODUCT*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA구분, A6
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// 정보구분, 01:개별주식선물
	out->mrk_clsf = data->mrk_clsf[0];	//시장구분, 5
	memcpy(out->isin_clsf, data->isin_clsf, sizeof(data->isin_clsf));	// 종목코드
	out->stk_snr = Str2Int(data->stk_snr, sizeof(data->stk_snr));	// 종목일련번호
	memcpy(out->brd_id, data->brd_id, sizeof(data->brd_id));	// 보드ID, 코드값모음참조
	out->close_prc = Str2Int(data->close_prc, sizeof(data->close_prc));	// 종가, * 거래무 종목의 경우 기준가 set
	out->close_prc_code = data->close_prc_code[0];	//종가구분코드, 1:실세, 3:거래무\n 2:기세 -2012.05.14 삭제\n ' ':정규장이 아닌 경우 space
	out->accm_exe_q = Str2Int(data->accm_exe_q, sizeof(data->accm_exe_q));	// 누적체결수량
	out->accm_trd_amt = Str2Dbl(data->accm_trd_amt, sizeof(data->accm_trd_amt), 0);	// 누적거래대금, 단위:원
	out->total_l_limit_ord_q = Str2Int(data->total_l_limit_ord_q, sizeof(data->total_l_limit_ord_q));	// 매수총호가잔량, 자리수 변경(7->8)
	out->l_lvl_1_prc = Str2Int(data->l_lvl_1_prc, sizeof(data->l_lvl_1_prc));	// 매수1단계우선호가가격
	out->l_lvl_1_q = Str2Int(data->l_lvl_1_q, sizeof(data->l_lvl_1_q));	// 매수1단계우선호가잔량, 자리수 변경(6->7)
	out->l_lvl_2_prc = Str2Int(data->l_lvl_2_prc, sizeof(data->l_lvl_2_prc));	// 매수2단계우선호가가격
	out->l_lvl_2_q = Str2Int(data->l_lvl_2_q, sizeof(data->l_lvl_2_q));	// 매수2단계우선호가잔량, 자리수 변경(6->7)
	out->l_lvl_3_prc = Str2Int(data->l_lvl_3_prc, sizeof(data->l_lvl_3_prc));	// 매수3단계우선호가가격
	out->l_lvl_3_q = Str2Int(data->l_lvl_3_q, sizeof(data->l_lvl_3_q));	// 매수3단계우선호가잔량, 자리수 변경(6->7)
	out->l_lvl_4_prc = Str2Int(data->l_lvl_4_prc, sizeof(data->l_lvl_4_prc));	// 매수4단계우선호가가격
	out->l_lvl_4_q = Str2Int(data->l_lvl_4_q, sizeof(data->l_lvl_4_q));	// 매수4단계우선호가잔량, 자리수 변경(6->7)
	out->l_lvl_5_prc = Str2Int(data->l_lvl_5_prc, sizeof(data->l_lvl_5_prc));	// 매수5단계우선호가가격
	out->l_lvl_5_q = Str2Int(data->l_lvl_5_q, sizeof(data->l_lvl_5_q));	// 매수5단계우선호가잔량, 자리수 변경(6->7)
	out->l_lvl_6_prc = Str2Int(data->l_lvl_6_prc, sizeof(data->l_lvl_6_prc));	// 매수6단계우선호가가격
	out->l_lvl_6_q = Str2Int(data->l_lvl_6_q, sizeof(data->l_lvl_6_q));	// 매수6단계우선호가잔량, 자리수 변경(6->7)
	out->l_lvl_7_prc = Str2Int(data->l_lvl_7_prc, sizeof(data->l_lvl_7_prc));	// 매수7단계우선호가가격
	out->l_lvl_7_q = Str2Int(data->l_lvl_7_q, sizeof(data->l_lvl_7_q));	// 매수7단계우선호가잔량, 자리수 변경(6->7)
	out->l_lvl_8_prc = Str2Int(data->l_lvl_8_prc, sizeof(data->l_lvl_8_prc));	// 매수8단계우선호가가격
	out->l_lvl_8_q = Str2Int(data->l_lvl_8_q, sizeof(data->l_lvl_8_q));	// 매수8단계우선호가잔량, 자리수 변경(6->7)
	out->l_lvl_9_prc = Str2Int(data->l_lvl_9_prc, sizeof(data->l_lvl_9_prc));	// 매수9단계우선호가가격
	out->l_lvl_9_q = Str2Int(data->l_lvl_9_q, sizeof(data->l_lvl_9_q));	// 매수9단계우선호가잔량, 자리수 변경(6->7)
	out->l_lvl_10_prc = Str2Int(data->l_lvl_10_prc, sizeof(data->l_lvl_10_prc));	// 매수10단계우선호가가격
	out->l_lvl_10_q = Str2Int(data->l_lvl_10_q, sizeof(data->l_lvl_10_q));	// 매수10단계우선호가잔량, 자리수 변경(6->7)
	out->total_s_limit_ord_q = Str2Int(data->total_s_limit_ord_q, sizeof(data->total_s_limit_ord_q));	// 매도총호가잔량, 자리수 변경(7->8)
	out->s_lvl_1_prc = Str2Int(data->s_lvl_1_prc, sizeof(data->s_lvl_1_prc));	// 매도1단계우선호가가격
	out->s_lvl_1_q = Str2Int(data->s_lvl_1_q, sizeof(data->s_lvl_1_q));	// 매도1단계우선호가잔량, 자리수 변경(6->7)
	out->s_lvl_2_prc = Str2Int(data->s_lvl_2_prc, sizeof(data->s_lvl_2_prc));	// 매도2단계우선호가가격
	out->s_lvl_2_q = Str2Int(data->s_lvl_2_q, sizeof(data->s_lvl_2_q));	// 매도2단계우선호가잔량, 자리수 변경(6->7)
	out->s_lvl_3_prc = Str2Int(data->s_lvl_3_prc, sizeof(data->s_lvl_3_prc));	// 매도3단계우선호가가격
	out->s_lvl_3_q = Str2Int(data->s_lvl_3_q, sizeof(data->s_lvl_3_q));	// 매도3단계우선호가잔량, 자리수 변경(6->7)
	out->s_lvl_4_prc = Str2Int(data->s_lvl_4_prc, sizeof(data->s_lvl_4_prc));	// 매도4단계우선호가가격
	out->s_lvl_4_q = Str2Int(data->s_lvl_4_q, sizeof(data->s_lvl_4_q));	// 매도4단계우선호가잔량, 자리수 변경(6->7)
	out->s_lvl_5_prc = Str2Int(data->s_lvl_5_prc, sizeof(data->s_lvl_5_prc));	// 매도5단계우선호가가격
	out->s_lvl_5_q = Str2Int(data->s_lvl_5_q, sizeof(data->s_lvl_5_q));	// 매도5단계우선호가잔량, 자리수 변경(6->7)
	out->s_lvl_6_prc = Str2Int(data->s_lvl_6_prc, sizeof(data->s_lvl_6_prc));	// 매도6단계우선호가가격
	out->s_lvl_6_q = Str2Int(data->s_lvl_6_q, sizeof(data->s_lvl_6_q));	// 매도6단계우선호가잔량, 자리수 변경(6->7)
	out->s_lvl_7_prc = Str2Int(data->s_lvl_7_prc, sizeof(data->s_lvl_7_prc));	// 매도7단계우선호가가격
	out->s_lvl_7_q = Str2Int(data->s_lvl_7_q, sizeof(data->s_lvl_7_q));	// 매도7단계우선호가잔량, 자리수 변경(6->7)
	out->s_lvl_8_prc = Str2Int(data->s_lvl_8_prc, sizeof(data->s_lvl_8_prc));	// 매도8단계우선호가가격
	out->s_lvl_8_q = Str2Int(data->s_lvl_8_q, sizeof(data->s_lvl_8_q));	// 매도8단계우선호가잔량, 자리수 변경(6->7)
	out->s_lvl_9_prc = Str2Int(data->s_lvl_9_prc, sizeof(data->s_lvl_9_prc));	// 매도9단계우선호가가격
	out->s_lvl_9_q = Str2Int(data->s_lvl_9_q, sizeof(data->s_lvl_9_q));	// 매도9단계우선호가잔량, 자리수 변경(6->7)
	out->s_lvl_10_prc = Str2Int(data->s_lvl_10_prc, sizeof(data->s_lvl_10_prc));	// 매도10단계우선호가가격
	out->s_lvl_10_q = Str2Int(data->s_lvl_10_q, sizeof(data->s_lvl_10_q));	// 매도10단계우선호가잔량, 자리수 변경(6->7)
	out->total_l_trd_cnt = Str2Int(data->total_l_trd_cnt, sizeof(data->total_l_trd_cnt));	// 매수유효호가건수
	out->l_lvl_1_trd_cnt = Str2Int(data->l_lvl_1_trd_cnt, sizeof(data->l_lvl_1_trd_cnt));	// 매수1단계우선호가건수
	out->l_lvl_2_trd_cnt = Str2Int(data->l_lvl_2_trd_cnt, sizeof(data->l_lvl_2_trd_cnt));	// 매수2단계우선호가건수
	out->l_lvl_3_trd_cnt = Str2Int(data->l_lvl_3_trd_cnt, sizeof(data->l_lvl_3_trd_cnt));	// 매수3단계우선호가건수
	out->l_lvl_4_trd_cnt = Str2Int(data->l_lvl_4_trd_cnt, sizeof(data->l_lvl_4_trd_cnt));	// 매수4단계우선호가건수
	out->l_lvl_5_trd_cnt = Str2Int(data->l_lvl_5_trd_cnt, sizeof(data->l_lvl_5_trd_cnt));	// 매수5단계우선호가건수
	out->l_lvl_6_trd_cnt = Str2Int(data->l_lvl_6_trd_cnt, sizeof(data->l_lvl_6_trd_cnt));	// 매수6단계우선호가건수
	out->l_lvl_7_trd_cnt = Str2Int(data->l_lvl_7_trd_cnt, sizeof(data->l_lvl_7_trd_cnt));	// 매수7단계우선호가건수
	out->l_lvl_8_trd_cnt = Str2Int(data->l_lvl_8_trd_cnt, sizeof(data->l_lvl_8_trd_cnt));	// 매수8단계우선호가건수
	out->l_lvl_9_trd_cnt = Str2Int(data->l_lvl_9_trd_cnt, sizeof(data->l_lvl_9_trd_cnt));	// 매수9단계우선호가건수
	out->l_lvl_10_trd_cnt = Str2Int(data->l_lvl_10_trd_cnt, sizeof(data->l_lvl_10_trd_cnt));	// 매수10단계우선호가건수
	out->total_s_trd_cnt = Str2Int(data->total_s_trd_cnt, sizeof(data->total_s_trd_cnt));	// 매도유효호가건수
	out->s_lvl_1_trd_cnt = Str2Int(data->s_lvl_1_trd_cnt, sizeof(data->s_lvl_1_trd_cnt));	// 매도1단계우선호가건수
	out->s_lvl_2_trd_cnt = Str2Int(data->s_lvl_2_trd_cnt, sizeof(data->s_lvl_2_trd_cnt));	// 매도2단계우선호가건수
	out->s_lvl_3_trd_cnt = Str2Int(data->s_lvl_3_trd_cnt, sizeof(data->s_lvl_3_trd_cnt));	// 매도3단계우선호가건수
	out->s_lvl_4_trd_cnt = Str2Int(data->s_lvl_4_trd_cnt, sizeof(data->s_lvl_4_trd_cnt));	// 매도4단계우선호가건수
	out->s_lvl_5_trd_cnt = Str2Int(data->s_lvl_5_trd_cnt, sizeof(data->s_lvl_5_trd_cnt));	// 매도5단계우선호가건수
	out->s_lvl_6_trd_cnt = Str2Int(data->s_lvl_6_trd_cnt, sizeof(data->s_lvl_6_trd_cnt));	// 매도6단계우선호가건수
	out->s_lvl_7_trd_cnt = Str2Int(data->s_lvl_7_trd_cnt, sizeof(data->s_lvl_7_trd_cnt));	// 매도7단계우선호가건수
	out->s_lvl_8_trd_cnt = Str2Int(data->s_lvl_8_trd_cnt, sizeof(data->s_lvl_8_trd_cnt));	// 매도8단계우선호가건수
	out->s_lvl_9_trd_cnt = Str2Int(data->s_lvl_9_trd_cnt, sizeof(data->s_lvl_9_trd_cnt));	// 매도9단계우선호가건수
	out->s_lvl_10_trd_cnt = Str2Int(data->s_lvl_10_trd_cnt, sizeof(data->s_lvl_10_trd_cnt));	// 매도10단계우선호가건수

	return 1;
}


// 주식선물_장운영TS
int ParseA7015(const double& timestamp, const char* in_buff, DF_STOCK_FUTURE_MRK_OP_TS* out) {
	STOCK_FUTURE_MRK_OP_TS* data = (STOCK_FUTURE_MRK_OP_TS*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA구분, A7
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// 정보구분, 01:개별주식선물
	out->mrk_clsf = data->mrk_clsf[0];	//시장구분, 5
	memcpy(out->isin_clsf, data->isin_clsf, sizeof(data->isin_clsf));	// 종목코드
	out->stk_snr = Str2Int(data->stk_snr, sizeof(data->stk_snr));	// 종목일련번호
	memcpy(out->prd_id, data->prd_id, sizeof(data->prd_id));	// 상품ID, 코드값모음참조 - space처리
	memcpy(out->brd_id, data->brd_id, sizeof(data->brd_id));	// 보드ID, 코드값모음참조
	memcpy(out->brd_event_id, data->brd_event_id, sizeof(data->brd_event_id));	// 보드이벤트ID, 코드값모음참조
	memcpy(out->brd_event_start_t, data->brd_event_start_t, sizeof(data->brd_event_start_t));	// 보드이벤트시작시각, 고정된 상수값(예:BB1(매매거래개시)의 경우 09000000)
	out->brd_event_code = Str2Int(data->brd_event_code, sizeof(data->brd_event_code));	// 보드이벤트적용군코드, 코드값모음참조
	memcpy(out->ss_id, data->ss_id, sizeof(data->ss_id));	// 세션ID, 코드값모음참조
	out->ord_exist = data->ord_exist[0];	//호가유무, 0:호가없음(이하항목 무시), 1:호가있음(이하항목 사용)
	out->total_l_limit_ord_q = Str2Int(data->total_l_limit_ord_q, sizeof(data->total_l_limit_ord_q));	// 매수총호가잔량, 자리수 변경(7->8)
	out->l_lvl_1_prc = Str2Int(data->l_lvl_1_prc, sizeof(data->l_lvl_1_prc));	// 매수1단계우선호가가격
	out->l_lvl_1_q = Str2Int(data->l_lvl_1_q, sizeof(data->l_lvl_1_q));	// 매수1단계우선호가잔량, 자리수 변경(6->7)
	out->l_lvl_2_prc = Str2Int(data->l_lvl_2_prc, sizeof(data->l_lvl_2_prc));	// 매수2단계우선호가가격
	out->l_lvl_2_q = Str2Int(data->l_lvl_2_q, sizeof(data->l_lvl_2_q));	// 매수2단계우선호가잔량, 자리수 변경(6->7)
	out->l_lvl_3_prc = Str2Int(data->l_lvl_3_prc, sizeof(data->l_lvl_3_prc));	// 매수3단계우선호가가격
	out->l_lvl_3_q = Str2Int(data->l_lvl_3_q, sizeof(data->l_lvl_3_q));	// 매수3단계우선호가잔량, 자리수 변경(6->7)
	out->l_lvl_4_prc = Str2Int(data->l_lvl_4_prc, sizeof(data->l_lvl_4_prc));	// 매수4단계우선호가가격
	out->l_lvl_4_q = Str2Int(data->l_lvl_4_q, sizeof(data->l_lvl_4_q));	// 매수4단계우선호가잔량, 자리수 변경(6->7)
	out->l_lvl_5_prc = Str2Int(data->l_lvl_5_prc, sizeof(data->l_lvl_5_prc));	// 매수5단계우선호가가격
	out->l_lvl_5_q = Str2Int(data->l_lvl_5_q, sizeof(data->l_lvl_5_q));	// 매수5단계우선호가잔량, 자리수 변경(6->7)
	out->l_lvl_6_prc = Str2Int(data->l_lvl_6_prc, sizeof(data->l_lvl_6_prc));	// 매수6단계우선호가가격
	out->l_lvl_6_q = Str2Int(data->l_lvl_6_q, sizeof(data->l_lvl_6_q));	// 매수6단계우선호가잔량, 자리수 변경(6->7)
	out->l_lvl_7_prc = Str2Int(data->l_lvl_7_prc, sizeof(data->l_lvl_7_prc));	// 매수7단계우선호가가격
	out->l_lvl_7_q = Str2Int(data->l_lvl_7_q, sizeof(data->l_lvl_7_q));	// 매수7단계우선호가잔량, 자리수 변경(6->7)
	out->l_lvl_8_prc = Str2Int(data->l_lvl_8_prc, sizeof(data->l_lvl_8_prc));	// 매수8단계우선호가가격
	out->l_lvl_8_q = Str2Int(data->l_lvl_8_q, sizeof(data->l_lvl_8_q));	// 매수8단계우선호가잔량, 자리수 변경(6->7)
	out->l_lvl_9_prc = Str2Int(data->l_lvl_9_prc, sizeof(data->l_lvl_9_prc));	// 매수9단계우선호가가격
	out->l_lvl_9_q = Str2Int(data->l_lvl_9_q, sizeof(data->l_lvl_9_q));	// 매수9단계우선호가잔량, 자리수 변경(6->7)
	out->l_lvl_10_prc = Str2Int(data->l_lvl_10_prc, sizeof(data->l_lvl_10_prc));	// 매수10단계우선호가가격
	out->l_lvl_10_q = Str2Int(data->l_lvl_10_q, sizeof(data->l_lvl_10_q));	// 매수10단계우선호가잔량, 자리수 변경(6->7)
	out->total_s_limit_ord_q = Str2Int(data->total_s_limit_ord_q, sizeof(data->total_s_limit_ord_q));	// 매도총호가잔량, 자리수 변경(7->8)
	out->s_lvl_1_prc = Str2Int(data->s_lvl_1_prc, sizeof(data->s_lvl_1_prc));	// 매도1단계우선호가가격
	out->s_lvl_1_q = Str2Int(data->s_lvl_1_q, sizeof(data->s_lvl_1_q));	// 매도1단계우선호가잔량, 자리수 변경(6->7)
	out->s_lvl_2_prc = Str2Int(data->s_lvl_2_prc, sizeof(data->s_lvl_2_prc));	// 매도2단계우선호가가격
	out->s_lvl_2_q = Str2Int(data->s_lvl_2_q, sizeof(data->s_lvl_2_q));	// 매도2단계우선호가잔량, 자리수 변경(6->7)
	out->s_lvl_3_prc = Str2Int(data->s_lvl_3_prc, sizeof(data->s_lvl_3_prc));	// 매도3단계우선호가가격
	out->s_lvl_3_q = Str2Int(data->s_lvl_3_q, sizeof(data->s_lvl_3_q));	// 매도3단계우선호가잔량, 자리수 변경(6->7)
	out->s_lvl_4_prc = Str2Int(data->s_lvl_4_prc, sizeof(data->s_lvl_4_prc));	// 매도4단계우선호가가격
	out->s_lvl_4_q = Str2Int(data->s_lvl_4_q, sizeof(data->s_lvl_4_q));	// 매도4단계우선호가잔량, 자리수 변경(6->7)
	out->s_lvl_5_prc = Str2Int(data->s_lvl_5_prc, sizeof(data->s_lvl_5_prc));	// 매도5단계우선호가가격
	out->s_lvl_5_q = Str2Int(data->s_lvl_5_q, sizeof(data->s_lvl_5_q));	// 매도5단계우선호가잔량, 자리수 변경(6->7)
	out->s_lvl_6_prc = Str2Int(data->s_lvl_6_prc, sizeof(data->s_lvl_6_prc));	// 매도6단계우선호가가격
	out->s_lvl_6_q = Str2Int(data->s_lvl_6_q, sizeof(data->s_lvl_6_q));	// 매도6단계우선호가잔량, 자리수 변경(6->7)
	out->s_lvl_7_prc = Str2Int(data->s_lvl_7_prc, sizeof(data->s_lvl_7_prc));	// 매도7단계우선호가가격
	out->s_lvl_7_q = Str2Int(data->s_lvl_7_q, sizeof(data->s_lvl_7_q));	// 매도7단계우선호가잔량, 자리수 변경(6->7)
	out->s_lvl_8_prc = Str2Int(data->s_lvl_8_prc, sizeof(data->s_lvl_8_prc));	// 매도8단계우선호가가격
	out->s_lvl_8_q = Str2Int(data->s_lvl_8_q, sizeof(data->s_lvl_8_q));	// 매도8단계우선호가잔량, 자리수 변경(6->7)
	out->s_lvl_9_prc = Str2Int(data->s_lvl_9_prc, sizeof(data->s_lvl_9_prc));	// 매도9단계우선호가가격
	out->s_lvl_9_q = Str2Int(data->s_lvl_9_q, sizeof(data->s_lvl_9_q));	// 매도9단계우선호가잔량, 자리수 변경(6->7)
	out->s_lvl_10_prc = Str2Int(data->s_lvl_10_prc, sizeof(data->s_lvl_10_prc));	// 매도10단계우선호가가격
	out->s_lvl_10_q = Str2Int(data->s_lvl_10_q, sizeof(data->s_lvl_10_q));	// 매도10단계우선호가잔량, 자리수 변경(6->7)
	out->total_l_trd_cnt = Str2Int(data->total_l_trd_cnt, sizeof(data->total_l_trd_cnt));	// 매수유효호가건수
	out->l_lvl_1_trd_cnt = Str2Int(data->l_lvl_1_trd_cnt, sizeof(data->l_lvl_1_trd_cnt));	// 매수1단계우선호가건수
	out->l_lvl_2_trd_cnt = Str2Int(data->l_lvl_2_trd_cnt, sizeof(data->l_lvl_2_trd_cnt));	// 매수2단계우선호가건수
	out->l_lvl_3_trd_cnt = Str2Int(data->l_lvl_3_trd_cnt, sizeof(data->l_lvl_3_trd_cnt));	// 매수3단계우선호가건수
	out->l_lvl_4_trd_cnt = Str2Int(data->l_lvl_4_trd_cnt, sizeof(data->l_lvl_4_trd_cnt));	// 매수4단계우선호가건수
	out->l_lvl_5_trd_cnt = Str2Int(data->l_lvl_5_trd_cnt, sizeof(data->l_lvl_5_trd_cnt));	// 매수5단계우선호가건수
	out->l_lvl_6_trd_cnt = Str2Int(data->l_lvl_6_trd_cnt, sizeof(data->l_lvl_6_trd_cnt));	// 매수6단계우선호가건수
	out->l_lvl_7_trd_cnt = Str2Int(data->l_lvl_7_trd_cnt, sizeof(data->l_lvl_7_trd_cnt));	// 매수7단계우선호가건수
	out->l_lvl_8_trd_cnt = Str2Int(data->l_lvl_8_trd_cnt, sizeof(data->l_lvl_8_trd_cnt));	// 매수8단계우선호가건수
	out->l_lvl_9_trd_cnt = Str2Int(data->l_lvl_9_trd_cnt, sizeof(data->l_lvl_9_trd_cnt));	// 매수9단계우선호가건수
	out->l_lvl_10_trd_cnt = Str2Int(data->l_lvl_10_trd_cnt, sizeof(data->l_lvl_10_trd_cnt));	// 매수10단계우선호가건수
	out->total_s_trd_cnt = Str2Int(data->total_s_trd_cnt, sizeof(data->total_s_trd_cnt));	// 매도유효호가건수
	out->s_lvl_1_trd_cnt = Str2Int(data->s_lvl_1_trd_cnt, sizeof(data->s_lvl_1_trd_cnt));	// 매도1단계우선호가건수
	out->s_lvl_2_trd_cnt = Str2Int(data->s_lvl_2_trd_cnt, sizeof(data->s_lvl_2_trd_cnt));	// 매도2단계우선호가건수
	out->s_lvl_3_trd_cnt = Str2Int(data->s_lvl_3_trd_cnt, sizeof(data->s_lvl_3_trd_cnt));	// 매도3단계우선호가건수
	out->s_lvl_4_trd_cnt = Str2Int(data->s_lvl_4_trd_cnt, sizeof(data->s_lvl_4_trd_cnt));	// 매도4단계우선호가건수
	out->s_lvl_5_trd_cnt = Str2Int(data->s_lvl_5_trd_cnt, sizeof(data->s_lvl_5_trd_cnt));	// 매도5단계우선호가건수
	out->s_lvl_6_trd_cnt = Str2Int(data->s_lvl_6_trd_cnt, sizeof(data->s_lvl_6_trd_cnt));	// 매도6단계우선호가건수
	out->s_lvl_7_trd_cnt = Str2Int(data->s_lvl_7_trd_cnt, sizeof(data->s_lvl_7_trd_cnt));	// 매도7단계우선호가건수
	out->s_lvl_8_trd_cnt = Str2Int(data->s_lvl_8_trd_cnt, sizeof(data->s_lvl_8_trd_cnt));	// 매도8단계우선호가건수
	out->s_lvl_9_trd_cnt = Str2Int(data->s_lvl_9_trd_cnt, sizeof(data->s_lvl_9_trd_cnt));	// 매도9단계우선호가건수
	out->s_lvl_10_trd_cnt = Str2Int(data->s_lvl_10_trd_cnt, sizeof(data->s_lvl_10_trd_cnt));	// 매도10단계우선호가건수
	out->real_t_high_prc = Str2Int(data->real_t_high_prc, sizeof(data->real_t_high_prc));	// 실시간상한가, 개발가이드참조
	out->real_t_low_prc = Str2Int(data->real_t_low_prc, sizeof(data->real_t_low_prc));	// 실시간하한가, 개발가이드참조

	return 1;
}


// 주식선물_마감
int ParseH0015(const double& timestamp, const char* in_buff, DF_STOCK_FUTURE_CLOSE* out) {
	STOCK_FUTURE_CLOSE* data = (STOCK_FUTURE_CLOSE*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA구분, H0
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// 정보구분, 01:개별주식선물
	out->mrk_clsf = data->mrk_clsf[0];	//시장구분, 5

	return 1;
}


// 주식선물_장운영스케줄공개
int ParseM4015(const double& timestamp, const char* in_buff, DF_STOCK_FUT_MRK_OP_SCHD* out) {
	STOCK_FUT_MRK_OP_SCHD* data = (STOCK_FUT_MRK_OP_SCHD*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA구분, M4
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// 정보구분, 01:개별주식선물
	out->mrk_clsf = data->mrk_clsf[0];	//시장구분, 5
	memcpy(out->isin_clsf, data->isin_clsf, sizeof(data->isin_clsf));	// 종목코드, *개별종목 장운영 조치시 등록
	out->stk_snr = Str2Int(data->stk_snr, sizeof(data->stk_snr));	// 종목일련번호, *개별종목 장운영 조치시 등록
	memcpy(out->prd_id, data->prd_id, sizeof(data->prd_id));	// 상품ID, 코드값모음참조 - 주식선물 전체장에 대해서는 space처리\n 기초자산별 이벤트 발생시 상품ID입력
	memcpy(out->mrk_prd_id, data->mrk_prd_id, sizeof(data->mrk_prd_id));	// 장운영상품그룹ID, FST : 코스피 주식선물\nFKQ : 코스닥 주식선물
	memcpy(out->brd_id, data->brd_id, sizeof(data->brd_id));	// 보드ID, 코드값모음참조
	memcpy(out->brd_event_id, data->brd_event_id, sizeof(data->brd_event_id));	// 보드이벤트ID, 코드값모음참조
	memcpy(out->brd_event_start_t, data->brd_event_start_t, sizeof(data->brd_event_start_t));	// 보드이벤트시작시각
	out->brd_event_code = Str2Int(data->brd_event_code, sizeof(data->brd_event_code));	// 보드이벤트적용군코드, 코드값모음 참조
	memcpy(out->ss_open_close_code, data->ss_open_close_code, sizeof(data->ss_open_close_code));	// 세션개시종료코드, BS:보드개시\n BE:보드종료\n SS:세션개시\n SE:세션종료\n SH:세션정지\n SR:세션재개
	memcpy(out->ss_id, data->ss_id, sizeof(data->ss_id));	// 세션ID, 코드값모음참조
	out->adj_stage = Str2Int(data->adj_stage, sizeof(data->adj_stage));	// 적용단계, CB 및 가격제한폭 확대시 적용되는 단계 \n예)초기값 00
	out->under_asset_prc_chg = data->under_asset_prc_chg[0];	//기준종목가격확대발생코드, 기준종목이 가격확대된 방향코드(U:상승, D:하락)
	memcpy(out->exp_prc_chg_t, data->exp_prc_chg_t, sizeof(data->exp_prc_chg_t));	// 가격확대예정시각, 파생시장가격확대 예고 이벤트 발생시 사용되는 항목으로 가격확대예정시각이 기록됨

	return 1;
}


// 주식선물_배분정보
int ParseO6015(const double& timestamp, const char* in_buff, DF_STOCK_FUT_DIST_INFO* out) {
	STOCK_FUT_DIST_INFO* data = (STOCK_FUT_DIST_INFO*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA구분, O6
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// 정보구분, 01:개별주식선물
	out->mrk_clsf = data->mrk_clsf[0];	//시장구분, 5
	memcpy(out->isin_clsf, data->isin_clsf, sizeof(data->isin_clsf));	// 종목코드
	out->stk_snr = Str2Int(data->stk_snr, sizeof(data->stk_snr));	// 종목일련번호
	memcpy(out->brd_id, data->brd_id, sizeof(data->brd_id));	// 보드ID, 코드값모음참조
	out->dist_adj_code = data->dist_adj_code[0];	//배분적용구분코드, 1:배분개시, 2:배분해제
	out->dist_code = data->dist_code[0];	//배분처리구분코드, 1:매수상한, 2:매수하한,\n 3:매도상한, 4:매도하한\n *배분해제시 코드없음(space처리)
	memcpy(out->dist_cls_t, data->dist_cls_t, sizeof(data->dist_cls_t));	// 배분해제시각

	return 1;
}


// 주식선물_실시간상하한가 적용및해제
int ParseQ2015(const double& timestamp, const char* in_buff, DF_STOCK_FUT_REAL_HIGH_LOW_LIMIT_ON_OFF* out) {
	STOCK_FUT_REAL_HIGH_LOW_LIMIT_ON_OFF* data = (STOCK_FUT_REAL_HIGH_LOW_LIMIT_ON_OFF*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA구분, Q2
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// 정보구분, 01:개별주식선물
	out->mrk_clsf = data->mrk_clsf[0];	//시장구분, 5
	memcpy(out->isin_clsf, data->isin_clsf, sizeof(data->isin_clsf));	// 종목코드
	out->stk_snr = Str2Int(data->stk_snr, sizeof(data->stk_snr));	// 종목일련번호
	memcpy(out->brd_id, data->brd_id, sizeof(data->brd_id));	// 보드ID, 코드값모음참조
	memcpy(out->cleared_t, data->cleared_t, sizeof(data->cleared_t));	// 처리시각
	out->real_t_prc_limit_code = data->real_t_prc_limit_code[0];	//실시간가격제한설정코드, 0: 해제, 1: 설정, 2: 재설정
	out->real_t_high_prc = Str2Int(data->real_t_high_prc, sizeof(data->real_t_high_prc));	// 실시간상한가, 개발가이드참조
	out->real_t_low_prc = Str2Int(data->real_t_low_prc, sizeof(data->real_t_low_prc));	// 실시간하한가, 개발가이드참조

	return 1;
}


// 주식선물_가격제한폭확대발동
int ParseV1015(const double& timestamp, const char* in_buff, DF_STOCK_FUT_PRC_LIMIT_ON* out) {
	STOCK_FUT_PRC_LIMIT_ON* data = (STOCK_FUT_PRC_LIMIT_ON*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA구분, V1
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// 정보구분, 01:주식선물
	out->mrk_clsf = data->mrk_clsf[0];	//시장구분, 5
	memcpy(out->code_clsf, data->code_clsf, sizeof(data->code_clsf));	// 종목코드
	out->stk_snr = Str2Int(data->stk_snr, sizeof(data->stk_snr));	// 종목일련번호
	memcpy(out->prd_id, data->prd_id, sizeof(data->prd_id));	// 상품ID, 코드값모음참조 : space처리
	memcpy(out->brd_id, data->brd_id, sizeof(data->brd_id));	// 보드ID, 코드값모음참조
	memcpy(out->prc_limit_start_t, data->prc_limit_start_t, sizeof(data->prc_limit_start_t));	// 가격확대시각, 가격이 확대된 시각
	out->prc_limit_high = Str2Int(data->prc_limit_high, sizeof(data->prc_limit_high));	// 가격제한확대상한단계, 적용된 상한단계
	out->prc_limit_low = Str2Int(data->prc_limit_low, sizeof(data->prc_limit_low));	// 가격제한확대하한단계, 적용된 하한단계
	out->high_prc = Str2Int(data->high_prc, sizeof(data->high_prc));	// 상한가, 적용된 상한가\n예)9999999
	out->low_prc = Str2Int(data->low_prc, sizeof(data->low_prc));	// 하한가, 적용된 하한가\n예)9999999

	return 1;
}


// 주식선물_미결제약정수량 데이터
int ParseH2015(const double& timestamp, const char* in_buff, DF_STOCK_FUT_OPEN_INTEREST_DATA* out) {
	STOCK_FUT_OPEN_INTEREST_DATA* data = (STOCK_FUT_OPEN_INTEREST_DATA*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA구분, H2
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// 정보구분, 01:개별주식선물
	out->mrk_clsf = data->mrk_clsf[0];	//시장구분, 5
	memcpy(out->isin_clsf, data->isin_clsf, sizeof(data->isin_clsf));	// 종목코드, 최종 record '999999999999' set
	out->stk_snr = Str2Int(data->stk_snr, sizeof(data->stk_snr));	// 종목SEQ
	memcpy(out->open_interest_clsf, data->open_interest_clsf, sizeof(data->open_interest_clsf));	// 미결제약정구분, 전일 확정 : "M0" (07:40분경 제공)\n당일 잠정 : "M1" (장중 특정간격으로 변동종목\n		 송신, 10초)\n당일 확정 : "M2" (당일 전종목 송신,\n		 장종료 1시간후 제공)
	memcpy(out->traded_date, data->traded_date, sizeof(data->traded_date));	// 거래일자
	out->open_interest_q = Str2Int(data->open_interest_q, sizeof(data->open_interest_q));	// 미결제약정수량, 단위:계약

	return 1;
}


// 주식선물_정산가격 데이터
int ParseH3015(const double& timestamp, const char* in_buff, DF_STOCK_FUT_SETT_PRC_DATA* out) {
	STOCK_FUT_SETT_PRC_DATA* data = (STOCK_FUT_SETT_PRC_DATA*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA구분, H3
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// 정보구분, 01:개별주식선물
	out->mrk_clsf = data->mrk_clsf[0];	//시장구분, 5
	memcpy(out->isin_clsf, data->isin_clsf, sizeof(data->isin_clsf));	// 종목코드, 최종 record '999999999999' set
	out->stk_snr = Str2Int(data->stk_snr, sizeof(data->stk_snr));	// 종목SEQ
	out->calc_prc = Str2Dbl(data->calc_prc, sizeof(data->calc_prc), 8);	// 정산가격, 예) 99999999.99999999
	out->calc_prc_clsf = data->calc_prc_clsf[0];	//정산가격구분, 0 : 정산가 없슴(최초 거래성립전 기세 포함)\n1 : 당일 종가(실세)\n2 : 당일 기세(최초 거래성립후 기세) - 2010.12.20 삭제\n3 : 전일 정산가(최초 거래성립후 종가 미형성) - 2010.12.20 삭제\n4 : 당일 이론가(최초 거래성립후 종가 미형성)\n5 : 스프레드거래에 의해 생성된 월물의 종가 - 2010.12.20 삭제\n6 : 조정된 전일 정산가 - 2010.12.20 삭제\n7 : 대상자산 종가(이론가없는상품)\n8 : 정산기준가격 - 2010.12.20 추가
	out->final_sett_prc = Str2Dbl(data->final_sett_prc, sizeof(data->final_sett_prc), 8);	// 최종결제가격, 예) 99999999.99999999
	out->final_sett_clsf = data->final_sett_clsf[0];	//최종결제가격구분

	return 1;
}


// 주식선물_선물시세Recovery 데이터
int ParseB2015(const double& timestamp, const char* in_buff, DF_STOCK_FUT_RECOVERY_DATA* out) {
	STOCK_FUT_RECOVERY_DATA* data = (STOCK_FUT_RECOVERY_DATA*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA구분, B2
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// 정보구분, 01:개별주식선물
	out->mrk_clsf = data->mrk_clsf[0];	//시장구분, 5
	memcpy(out->isin_clsf, data->isin_clsf, sizeof(data->isin_clsf));	// 종목코드
	out->stk_snr = Str2Int(data->stk_snr, sizeof(data->stk_snr));	// 종목일련번호
	out->cur_prc = Str2Int(data->cur_prc, sizeof(data->cur_prc));	// 현재가
	out->rct_prd_prc = Str2Int(data->rct_prd_prc, sizeof(data->rct_prd_prc));	// 최근월물 의제약정가격
	out->nxt_prd_prc = Str2Int(data->nxt_prd_prc, sizeof(data->nxt_prd_prc));	// 원월물 의제약정가격
	out->init_prc = Str2Int(data->init_prc, sizeof(data->init_prc));	// 시가
	out->high_prc = Str2Int(data->high_prc, sizeof(data->high_prc));	// 고가
	out->low_prc = Str2Int(data->low_prc, sizeof(data->low_prc));	// 저가
	out->open_interest_q = Str2Int(data->open_interest_q, sizeof(data->open_interest_q));	// 미결제량
	out->accm_exe_q = Str2Int(data->accm_exe_q, sizeof(data->accm_exe_q));	// 누적체결수량
	out->accm_trd_amt = Str2Dbl(data->accm_trd_amt, sizeof(data->accm_trd_amt), 0);	// 누적거래대금, 단위:원
	out->l_or_s = data->l_or_s[0];	//최종매도매수구분코드, 1:매도,2:매수(최종으로 들어온 호가의 매도매수구분값)
	out->s_lvl_1_prc = Str2Int(data->s_lvl_1_prc, sizeof(data->s_lvl_1_prc));	// 매도1호가
	out->s_lvl_1_q = Str2Int(data->s_lvl_1_q, sizeof(data->s_lvl_1_q));	// 매도1호가수량, 자리수 변경(6->7)
	out->s_lvl_1_trd_cnt = Str2Int(data->s_lvl_1_trd_cnt, sizeof(data->s_lvl_1_trd_cnt));	// 매도1호가건수
	out->l_lvl_1_prc = Str2Int(data->l_lvl_1_prc, sizeof(data->l_lvl_1_prc));	// 매수1호가
	out->l_lvl_1_q = Str2Int(data->l_lvl_1_q, sizeof(data->l_lvl_1_q));	// 매수1호가수량, 자리수 변경(6->7)
	out->l_lvl_1_trd_cnt = Str2Int(data->l_lvl_1_trd_cnt, sizeof(data->l_lvl_1_trd_cnt));	// 매수1호가건수
	out->s_lvl_2_prc = Str2Int(data->s_lvl_2_prc, sizeof(data->s_lvl_2_prc));	// 매도2호가
	out->s_lvl_2_q = Str2Int(data->s_lvl_2_q, sizeof(data->s_lvl_2_q));	// 매도2호가수량, 자리수 변경(6->7)
	out->s_lvl_2_trd_cnt = Str2Int(data->s_lvl_2_trd_cnt, sizeof(data->s_lvl_2_trd_cnt));	// 매도2호가건수
	out->l_lvl_2_prc = Str2Int(data->l_lvl_2_prc, sizeof(data->l_lvl_2_prc));	// 매수2호가
	out->l_lvl_2_q = Str2Int(data->l_lvl_2_q, sizeof(data->l_lvl_2_q));	// 매수2호가수량, 자리수 변경(6->7)
	out->l_lvl_2_trd_cnt = Str2Int(data->l_lvl_2_trd_cnt, sizeof(data->l_lvl_2_trd_cnt));	// 매수2호가건수
	out->s_lvl_3_prc = Str2Int(data->s_lvl_3_prc, sizeof(data->s_lvl_3_prc));	// 매도3호가
	out->s_lvl_3_q = Str2Int(data->s_lvl_3_q, sizeof(data->s_lvl_3_q));	// 매도3호가수량, 자리수 변경(6->7)
	out->s_lvl_3_trd_cnt = Str2Int(data->s_lvl_3_trd_cnt, sizeof(data->s_lvl_3_trd_cnt));	// 매도3호가건수
	out->l_lvl_3_prc = Str2Int(data->l_lvl_3_prc, sizeof(data->l_lvl_3_prc));	// 매수3호가
	out->l_lvl_3_q = Str2Int(data->l_lvl_3_q, sizeof(data->l_lvl_3_q));	// 매수3호가수량, 자리수 변경(6->7)
	out->l_lvl_3_trd_cnt = Str2Int(data->l_lvl_3_trd_cnt, sizeof(data->l_lvl_3_trd_cnt));	// 매수3호가건수
	out->s_lvl_4_prc = Str2Int(data->s_lvl_4_prc, sizeof(data->s_lvl_4_prc));	// 매도4호가
	out->s_lvl_4_q = Str2Int(data->s_lvl_4_q, sizeof(data->s_lvl_4_q));	// 매도4호가수량, 자리수 변경(6->7)
	out->s_lvl_4_trd_cnt = Str2Int(data->s_lvl_4_trd_cnt, sizeof(data->s_lvl_4_trd_cnt));	// 매도4호가건수
	out->l_lvl_4_prc = Str2Int(data->l_lvl_4_prc, sizeof(data->l_lvl_4_prc));	// 매수4호가
	out->l_lvl_4_q = Str2Int(data->l_lvl_4_q, sizeof(data->l_lvl_4_q));	// 매수4호가수량, 자리수 변경(6->7)
	out->l_lvl_4_trd_cnt = Str2Int(data->l_lvl_4_trd_cnt, sizeof(data->l_lvl_4_trd_cnt));	// 매수4호가건수
	out->s_lvl_5_prc = Str2Int(data->s_lvl_5_prc, sizeof(data->s_lvl_5_prc));	// 매도5호가
	out->s_lvl_5_q = Str2Int(data->s_lvl_5_q, sizeof(data->s_lvl_5_q));	// 매도5호가수량, 자리수 변경(6->7)
	out->s_lvl_5_trd_cnt = Str2Int(data->s_lvl_5_trd_cnt, sizeof(data->s_lvl_5_trd_cnt));	// 매도5호가건수
	out->l_lvl_5_prc = Str2Int(data->l_lvl_5_prc, sizeof(data->l_lvl_5_prc));	// 매수5호가
	out->l_lvl_5_q = Str2Int(data->l_lvl_5_q, sizeof(data->l_lvl_5_q));	// 매수5호가수량, 자리수 변경(6->7)
	out->l_lvl_5_trd_cnt = Str2Int(data->l_lvl_5_trd_cnt, sizeof(data->l_lvl_5_trd_cnt));	// 매수5호가건수
	out->s_lvl_6_prc = Str2Int(data->s_lvl_6_prc, sizeof(data->s_lvl_6_prc));	// 매도6호가
	out->s_lvl_6_q = Str2Int(data->s_lvl_6_q, sizeof(data->s_lvl_6_q));	// 매도6호가수량, 자리수 변경(6->7)
	out->s_lvl_6_trd_cnt = Str2Int(data->s_lvl_6_trd_cnt, sizeof(data->s_lvl_6_trd_cnt));	// 매도6호가건수
	out->l_lvl_6_prc = Str2Int(data->l_lvl_6_prc, sizeof(data->l_lvl_6_prc));	// 매수6호가
	out->l_lvl_6_q = Str2Int(data->l_lvl_6_q, sizeof(data->l_lvl_6_q));	// 매수6호가수량, 자리수 변경(6->7)
	out->l_lvl_6_trd_cnt = Str2Int(data->l_lvl_6_trd_cnt, sizeof(data->l_lvl_6_trd_cnt));	// 매수6호가건수
	out->s_lvl_7_prc = Str2Int(data->s_lvl_7_prc, sizeof(data->s_lvl_7_prc));	// 매도7호가
	out->s_lvl_7_q = Str2Int(data->s_lvl_7_q, sizeof(data->s_lvl_7_q));	// 매도7호가수량, 자리수 변경(6->7)
	out->s_lvl_7_trd_cnt = Str2Int(data->s_lvl_7_trd_cnt, sizeof(data->s_lvl_7_trd_cnt));	// 매도7호가건수
	out->l_lvl_7_prc = Str2Int(data->l_lvl_7_prc, sizeof(data->l_lvl_7_prc));	// 매수7호가
	out->l_lvl_7_q = Str2Int(data->l_lvl_7_q, sizeof(data->l_lvl_7_q));	// 매수7호가수량, 자리수 변경(6->7)
	out->l_lvl_7_trd_cnt = Str2Int(data->l_lvl_7_trd_cnt, sizeof(data->l_lvl_7_trd_cnt));	// 매수7호가건수
	out->s_lvl_8_prc = Str2Int(data->s_lvl_8_prc, sizeof(data->s_lvl_8_prc));	// 매도8호가
	out->s_lvl_8_q = Str2Int(data->s_lvl_8_q, sizeof(data->s_lvl_8_q));	// 매도8호가수량, 자리수 변경(6->7)
	out->s_lvl_8_trd_cnt = Str2Int(data->s_lvl_8_trd_cnt, sizeof(data->s_lvl_8_trd_cnt));	// 매도8호가건수
	out->l_lvl_8_prc = Str2Int(data->l_lvl_8_prc, sizeof(data->l_lvl_8_prc));	// 매수8호가
	out->l_lvl_8_q = Str2Int(data->l_lvl_8_q, sizeof(data->l_lvl_8_q));	// 매수8호가수량, 자리수 변경(6->7)
	out->l_lvl_8_trd_cnt = Str2Int(data->l_lvl_8_trd_cnt, sizeof(data->l_lvl_8_trd_cnt));	// 매수8호가건수
	out->s_lvl_9_prc = Str2Int(data->s_lvl_9_prc, sizeof(data->s_lvl_9_prc));	// 매도9호가
	out->s_lvl_9_q = Str2Int(data->s_lvl_9_q, sizeof(data->s_lvl_9_q));	// 매도9호가수량, 자리수 변경(6->7)
	out->s_lvl_9_trd_cnt = Str2Int(data->s_lvl_9_trd_cnt, sizeof(data->s_lvl_9_trd_cnt));	// 매도9호가건수
	out->l_lvl_9_prc = Str2Int(data->l_lvl_9_prc, sizeof(data->l_lvl_9_prc));	// 매수9호가
	out->l_lvl_9_q = Str2Int(data->l_lvl_9_q, sizeof(data->l_lvl_9_q));	// 매수9호가수량, 자리수 변경(6->7)
	out->l_lvl_9_trd_cnt = Str2Int(data->l_lvl_9_trd_cnt, sizeof(data->l_lvl_9_trd_cnt));	// 매수9호가건수
	out->s_lvl_10_prc = Str2Int(data->s_lvl_10_prc, sizeof(data->s_lvl_10_prc));	// 매도10호가
	out->s_lvl_10_q = Str2Int(data->s_lvl_10_q, sizeof(data->s_lvl_10_q));	// 매도10호가수량, 자리수 변경(6->7)
	out->s_lvl_10_trd_cnt = Str2Int(data->s_lvl_10_trd_cnt, sizeof(data->s_lvl_10_trd_cnt));	// 매도10호가건수
	out->l_lvl_10_prc = Str2Int(data->l_lvl_10_prc, sizeof(data->l_lvl_10_prc));	// 매수10호가
	out->l_lvl_10_q = Str2Int(data->l_lvl_10_q, sizeof(data->l_lvl_10_q));	// 매수10호가수량, 자리수 변경(6->7)
	out->l_lvl_10_trd_cnt = Str2Int(data->l_lvl_10_trd_cnt, sizeof(data->l_lvl_10_trd_cnt));	// 매수10호가건수
	out->total_s_limit_ord_q = Str2Int(data->total_s_limit_ord_q, sizeof(data->total_s_limit_ord_q));	// 매도 총호가수량, 자리수 변경(7->8)
	out->total_s_trd_cnt = Str2Int(data->total_s_trd_cnt, sizeof(data->total_s_trd_cnt));	// 매도유효호가건수
	out->total_l_limit_ord_q = Str2Int(data->total_l_limit_ord_q, sizeof(data->total_l_limit_ord_q));	// 매수 총호가수량, 자리수 변경(7->8)
	out->total_l_trd_cnt = Str2Int(data->total_l_trd_cnt, sizeof(data->total_l_trd_cnt));	// 매수유효호가건수
	memcpy(out->ss_id, data->ss_id, sizeof(data->ss_id));	// 세션ID, 코드값모음참조
	memcpy(out->brd_id, data->brd_id, sizeof(data->brd_id));	// 보드ID, 코드값모음참조
	memcpy(out->brd_event_id, data->brd_event_id, sizeof(data->brd_event_id));	// 보드이벤트ID, B2 에서는 보드이벤트ID 사용금지(과거 상태값이 전송될 수 있음). 추후, 해당 항목 '000' 세팅 예정. 2014.03.24)
	out->exp_prc = Str2Int(data->exp_prc, sizeof(data->exp_prc));	// 예상체결가격, 단일가매매시만 제공\n (장상태구분코드:10,20,30,80)
	out->real_t_high_prc = Str2Int(data->real_t_high_prc, sizeof(data->real_t_high_prc));	// 실시간상한가, 개발가이드참조
	out->real_t_low_prc = Str2Int(data->real_t_low_prc, sizeof(data->real_t_low_prc));	// 실시간하한가, 개발가이드참조

	return 1;
}


// 주식선물_투자자 데이터
int ParseH1015(const double& timestamp, const char* in_buff, DF_STOCK_FUT_INVESTOR_DATA* out) {
	STOCK_FUT_INVESTOR_DATA* data = (STOCK_FUT_INVESTOR_DATA*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA구분, H1
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// 정보구분, 01:개별주식선물
	out->mrk_clsf = data->mrk_clsf[0];	//시장구분, 5
	memcpy(out->created_date, data->created_date, sizeof(data->created_date));	// 생성일자
	memcpy(out->created_time, data->created_time, sizeof(data->created_time));	// 생성시각
	memcpy(out->inv_data_clsf, data->inv_data_clsf, sizeof(data->inv_data_clsf));	// 데이터구분, *전일확정 : 00, 당일잠정 : 01, 당일확정 : 02\n *E1 : 장중 데이터 완료, E2 : 확정 데이터 완료\n 최종 record '99' set
	memcpy(out->prd_id, data->prd_id, sizeof(data->prd_id));	// 상품ID, 코드값모음참조 - 시장전체(KRDRVFU999 )
	memcpy(out->inv_clsf, data->inv_clsf, sizeof(data->inv_clsf));	// 투자자유형, 코드값모음 참조 *코드 '7000'시 수량,대금정보항목 0으로 전송
	out->long_exe_q = Str2Int(data->long_exe_q, sizeof(data->long_exe_q));	// 매수약정수량
	out->short_exe_q = Str2Int(data->short_exe_q, sizeof(data->short_exe_q));	// 매도약정수량
	out->long_traded_amt = Str2Dbl(data->long_traded_amt, sizeof(data->long_traded_amt), 0);	// 매수약정대금
	out->short_traded_amt = Str2Dbl(data->short_traded_amt, sizeof(data->short_traded_amt), 0);	// 매도약정대금
	out->spread_long_exe_q = Str2Int(data->spread_long_exe_q, sizeof(data->spread_long_exe_q));	// 스프레드에 의해 생성된 매수 약정수량
	out->spread_short_exe_q = Str2Int(data->spread_short_exe_q, sizeof(data->spread_short_exe_q));	// 스프레드에 의해 생성된 매도 약정수량
	out->spread_long_traded_amt = Str2Dbl(data->spread_long_traded_amt, sizeof(data->spread_long_traded_amt), 0);	// 스프레드에 의해 생성된 매수 약정대금
	out->spread_short_traded_amt = Str2Dbl(data->spread_short_traded_amt, sizeof(data->spread_short_traded_amt), 0);	// 스프레드에 의해 생성된 매도 약정대금

	return 1;
}


// 주식선물_경쟁+협의합산
int ParseC4015(const double& timestamp, const char* in_buff, DF_STOCK_FUT_COMP_BLOCK* out) {
	STOCK_FUT_COMP_BLOCK* data = (STOCK_FUT_COMP_BLOCK*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA구분, C4
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// 정보구분, 01:개별주식선물
	out->mkt_clsf = data->mkt_clsf[0];	//시장구분, 5
	memcpy(out->isin_clsf, data->isin_clsf, sizeof(data->isin_clsf));	// 종목코드
	out->stk_snr = Str2Int(data->stk_snr, sizeof(data->stk_snr));	// 종목일련번호
	out->cpt_block_trd_vol = Str2Dbl(data->cpt_block_trd_vol, sizeof(data->cpt_block_trd_vol), 0);	// 경쟁+협의합산 거래량, 경쟁매매와 협의대량거래를 합산한 거래량
	out->cpt_block_trd_amt = Str2Dbl(data->cpt_block_trd_amt, sizeof(data->cpt_block_trd_amt), 0);	// 경쟁+협의합산 거래대금, 경쟁매매와 협의대량거래를 합산한 거래대금\n(단위 : 원)

	return 1;
}


// 주식선물_종목정보 데이터
int ParseA0015(const double& timestamp, const char* in_buff, DF_STOCK_FUT_PRD_INFO_DATA* out) {
	STOCK_FUT_PRD_INFO_DATA* data = (STOCK_FUT_PRD_INFO_DATA*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA구분, A0
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// 정보구분, 01:개별주식선물
	out->mrk_clsf = data->mrk_clsf[0];	//시장구분, 5
	out->prd_cnt = Str2Int(data->prd_cnt, sizeof(data->prd_cnt));	// 종목수
	memcpy(out->trd_date, data->trd_date, sizeof(data->trd_date));	// 영업일자(입회일자)
	memcpy(out->isin_clsf, data->isin_clsf, sizeof(data->isin_clsf));	// 종목코드, 최종 record '999999999999' set
	out->stk_snr = Str2Int(data->stk_snr, sizeof(data->stk_snr));	// 종목SEQ
	memcpy(out->prd_id, data->prd_id, sizeof(data->prd_id));	// 상품ID, * 코드값 모음집 참조\n* 구명칭: 파생상품ID\n10 => 11, 20140303
	memcpy(out->sh_prd_code, data->sh_prd_code, sizeof(data->sh_prd_code));	// 종목단축코드, 에) KR4101C90009 → K101C9000
	memcpy(out->prd_name_kor, data->prd_name_kor, sizeof(data->prd_name_kor));	// 종목한글명
	memcpy(out->sh_prd_name_kor, data->sh_prd_name_kor, sizeof(data->sh_prd_name_kor));	// 종목한글약명
	memcpy(out->prd_name_eng, data->prd_name_eng, sizeof(data->prd_name_eng));	// 종목영문명
	memcpy(out->sh_prd_name_eng, data->sh_prd_name_eng, sizeof(data->sh_prd_name_eng));	// 종목영문약명
	memcpy(out->listing_date, data->listing_date, sizeof(data->listing_date));	// 상장일자
	memcpy(out->de_listing_date, data->de_listing_date, sizeof(data->de_listing_date));	// 상장폐지일자
	out->spread_clsf_code = data->spread_clsf_code[0];	//스프레드기준종목구분코드, 스프레드의 기준이 되는 종목의 ISIN 표준코드\n--코드값--\nF: 원월물(시간스프레드)\nN: 근월물(시간스프레드)\n20140303
	out->final_sett_code = data->final_sett_code[0];	//최종결제방법코드, 현금결제, 실물인수도결제 등 파생상품의 최종결제 방법\n--코드값--\nC: 현금결제\nD: 실물인수도결제\nA: 현금+실물인수도결제\n0: 해당없음\n20140303
	out->prc_limit_exp_dir = data->prc_limit_exp_dir[0];	//가격제한확대방향코드, 가격제한이 다단계로 정의되는 경우 다음 단계로 확대되는 요건을 충족할 때 확대를 수행하는 방향\n## 코드값##\nX:미적용\nF:정방향\nB:역방향\nT:양방향
	out->prc_limit_final_stg = Str2Int(data->prc_limit_final_stg, sizeof(data->prc_limit_final_stg));	// 가격제한확대적용방향코드, 가격제한이 다단계로 정의되는 경우 제한의 최종단계번호
	out->prc_limit_stg_1_high_prc = Str2SignDouble(data->prc_limit_stg_1_hgh_sign, sizeof(data->prc_limit_stg_1_hgh_sign) + sizeof(data->prc_limit_stg_1_high_prc), 2);	// 가격제한1단계상한가, 예) 9999999999.99
	out->prc_limit_stg_1_low_prc = Str2SignDouble(data->prc_limit_stg_1_low_sign, sizeof(data->prc_limit_stg_1_low_sign) + sizeof(data->prc_limit_stg_1_low_prc), 2);	// 가격제한1단계하한가, 예) 9999999999.99
	out->prc_limit_stg_2_high_prc = Str2SignDouble(data->prc_limit_stg_2_high_sign, sizeof(data->prc_limit_stg_2_high_sign) + sizeof(data->prc_limit_stg_2_high_prc), 2);	// 가격제한2단계상한가, 예) 9999999999.99
	out->prc_limit_stg_2_low_prc = Str2SignDouble(data->prc_limit_stg_2_low_sign, sizeof(data->prc_limit_stg_2_low_sign) + sizeof(data->prc_limit_stg_2_low_prc), 2);	// 가격제한2단계하한가, 예) 9999999999.99
	out->prc_limit_stg_3_high_prc = Str2SignDouble(data->prc_limit_stg_3_high_sign, sizeof(data->prc_limit_stg_3_high_sign) + sizeof(data->prc_limit_stg_3_high_prc), 2);	// 가격제한3단계상한가, 예) 9999999999.99
	out->prc_limit_stg_3_low_prc = Str2SignDouble(data->prc_limit_stg_3_low_sign, sizeof(data->prc_limit_stg_3_low_sign) + sizeof(data->prc_limit_stg_3_low_prc), 2);	// 가격제한3단계하한가, 예) 9999999999.99
	out->stand_prc = Str2Dbl(data->stand_prc, sizeof(data->stand_prc), 2);	// 기준가, 예) 9999999999.99
	memcpy(out->under_asset_id, data->under_asset_id, sizeof(data->under_asset_id));	// 기초자산ID, 예) K2I:KOSPI200지수, KQI:코스닥150지수,\n   Sxx:개별주식, BM3:신3년국채,\n   BM5:신5년국채, BMA:신10년국채, \n   CDR:CD, USD:미국달러, JPY:일본엔,\n   EUR:유럽유로,\n   GLD:금, LHG:돈육\n20140303
	out->opt_type_code = data->opt_type_code[0];	//권리행사유형코드, A:미국형,E:유럽형,B:버뮤다형,Z:기타\n20140303
	memcpy(out->spread_str_code, data->spread_str_code, sizeof(data->spread_str_code));	// 스프레드구성코드, Combination 호가를 대체할 스프레드물의 종목구성.\n--코드값--\n- T1: 최근월물+2째월물\n	  > T2, T3, T4, ...\n*구명칭: 스프레드유형코드\n20140303
	memcpy(out->spread_prd_code_1, data->spread_prd_code_1, sizeof(data->spread_prd_code_1));	// 스프레드구성종목코드1, * 구명칭: 스프레드근월물 종목코드\n근월물 표준코드\n20140303
	memcpy(out->spread_prd_code_2, data->spread_prd_code_2, sizeof(data->spread_prd_code_2));	// 스프레드구성종목코드2, * 구명칭 : 스프레드원월물 종목코드\n원월물 표준코드\n20140303
	memcpy(out->last_trading_date, data->last_trading_date, sizeof(data->last_trading_date));	// 최종거래일자
	memcpy(out->final_sett_date, data->final_sett_date, sizeof(data->final_sett_date));	// 최종결제일자
	out->cont_month_nbr = Str2Int(data->cont_month_nbr, sizeof(data->cont_month_nbr));	// 결제월번호, * 구명칭: 월물구분코드\n1:최근월물,선물스프레드\n2:2째월물\n3:3째월물\n4:4째월물\n5:5째월물\n6:6째월물\n7:7째월물	  구 최근월물여부 대치\nX => 9, 1 => 3, 20140303
	memcpy(out->maturity_date, data->maturity_date, sizeof(data->maturity_date));	// 만기일자, 권리행사 가능한 최종일자
	out->exe_prc = Str2Dbl(data->exe_prc, sizeof(data->exe_prc), 8);	// 행사가격, 예) 999999999.99999999
	out->adjust_clsf_code = data->adjust_clsf_code[0];	//조정구분코드, 기초자산의 기준가격 조정이 정배수 조정(미결제조정)인지 비정배수 조정(거래승수조정)인지의 구분\n--코드값--\nN: 정상\nO: 미결제조정\nC: 거래승수조정\n20140303
	out->prd_unit = Str2Dbl(data->prd_unit, sizeof(data->prd_unit), 8);	// 거래단위, 1계약에 해당하는 기초자산수량\n예) 999999999.99999999
	out->multiplier = Str2Dbl(data->multiplier, sizeof(data->multiplier), 8);	// 거래승수, 약정대금 및 결제시 사용하는 계산승수\n예) 9999999999999.99999999
	out->mrk_cnst_code = data->mrk_cnst_code[0];	//시장조성구분코드, 0:미시장조성종목\n1:당일시장조성종목\n2:과거시장조성종목
	out->listing_type_code = data->listing_type_code[0];	//상장유형코드, 1:신규상장\n2:추가상장\n3:기존종목\n4:최초상장\n5:종목조정\n6:특별설정
	out->atm_prc = Str2Dbl(data->atm_prc, sizeof(data->atm_prc), 2);	// 등가격, 기초자산기준가격에 가장 가까운 행사가격\n예) 9999999999.99
	memcpy(out->adj_reason_code, data->adj_reason_code, sizeof(data->adj_reason_code));	// 조정사유코드, 00:해당사항없음, 01:권리락, 02:배당락,\n03:분배락, 04:권배락, 05:중간배당락,\n06:권리중간배당락, 99:기타
	memcpy(out->under_asset_prd_code, data->under_asset_prd_code, sizeof(data->under_asset_prd_code));	// 기초자산종목코드
	out->under_asset_close_prc = Str2Dbl(data->under_asset_close_prc, sizeof(data->under_asset_close_prc), 2);	// 기초자산종가, 예) 9999999999.99
	out->left_until_maturity = Str2Int(data->left_until_maturity, sizeof(data->left_until_maturity));	// 잔존일수
	out->adj_std_prc = Str2Dbl(data->adj_std_prc, sizeof(data->adj_std_prc), 8);	// 조정기준가격, 주식파생상품의 기초주권 조정기준가격\n예) 999999999.99999999
	memcpy(out->std_prc_clsf_code, data->std_prc_clsf_code, sizeof(data->std_prc_clsf_code));	// 기준가격구분코드, *선물\nspcace:기준가 없음(선물 스프레드종목)\n11:전일정산가\n12:전일기준가(거래성립전 종가미형성)\n13:당일이론가(거래성립전 종가미형성)\n14:전일기세(거래성립전 기세형성)\n  -2012.05.14 삭제\n15:당일이론가(거래성립전 기세형성)-\n  -2012.05.14 삭제\n16:조정된 전일정산가\n17:조정된 전일기준가\n  (거래성립전 종가미형성)\n18:조정된 전일기세(거래성립전 기세형성)\n  -2012.05.14 삭제\n19:전일 대상자산 종가(이론가없는 상품)\n*옵션\n21:전일증거금기준가\n22:전일기준가(거래성립전 종가미형성)\n23:당일이론가(거래성립전 종가미형성)\n24:전일기세(거래성립전 기세형성)\n  -2012.05.14 삭제\n25:조정된 전일증거금기준가\n26:조정된 전일기준가\n  (거래성립전 종가미형성)\n27:조정된 전일기세(거래성립전 기세형성)\n  -2012.05.14 삭제
	out->trd_std_prc_clsf_code = data->trd_std_prc_clsf_code[0];	//매매용기준가격구분코드, 0:해당없음\n1:실세\n2:기세\n3:이론가\n4:대상자산종가
	out->yest_adj_close_prc = Str2SignDouble(data->yest_adj_close_prc_sign, sizeof(data->yest_adj_close_prc_sign) + sizeof(data->yest_adj_close_prc), 8);	// 전일조정종가, 주식파생상품의 조정종가\n예) 999999999.99999999
	out->block_trd_clsf = data->block_trd_clsf[0];	//협의대량매매대상여부, Y:협의매매상품, N:대상아님\n가능품목:3년물국채선물, 미국달러선물,\n	  유로선물, 엔선물
	out->yest_mrg_std_prc = Str2Dbl(data->yest_mrg_std_prc, sizeof(data->yest_mrg_std_prc), 8);	// 전일증거금기준가격, 예) 999999999.99999999
	memcpy(out->yest_mrg_std_prc_clsf_code, data->yest_mrg_std_prc_clsf_code, sizeof(data->yest_mrg_std_prc_clsf_code));	// 전일증거금기준가격구분코드, *옵션\n20:증거금 기준가 없음\n21:당일종가(실세)\n22:당일기세(거래성립후기세)\n  -2012.05.14 삭제\n23:전일증거금기준가\n  (거래성립후 종가미형성)\n  -2012.05.14 삭제\n24:당일이론가(거래성립후 종가미형성)\n25:조정전일증거금기준가\n  (거래성립후 종가미형성)\n  -2012.05.14 삭제
	out->sett_theory_prc = Str2Dbl(data->sett_theory_prc, sizeof(data->sett_theory_prc), 6);	// 정산이론가격, ※옵션의 경우 증거금기준가용 \n예) 999999999.999999
	out->std_theory_prc = Str2Dbl(data->std_theory_prc, sizeof(data->std_theory_prc), 6);	// 기준이론가격, 예) 999999999.999999
	out->yest_sett_prc = Str2Dbl(data->yest_sett_prc, sizeof(data->yest_sett_prc), 8);	// 전일정산가격, 예) 999999999.99999999
	out->halt_trd_clsf = data->halt_trd_clsf[0];	//거래정지여부, Y, N
	out->ft_cb_high_prc = Str2Dbl(data->ft_cb_high_prc, sizeof(data->ft_cb_high_prc), 2);	// 선물Circuit_Breakers상한가, 선물 CB 발동조건을 판단하기 위한 상한\n가격(기준가대비 +/-5%가 CB 발동\n조건인 경우 +5%를 계산한 가격)\n예) 99+F31499999999.99
	out->ft_cb_low_prc = Str2Dbl(data->ft_cb_low_prc, sizeof(data->ft_cb_low_prc), 2);	// 선물Circuit_Breakers하한가, 선물 CB 발동조건을 판단하기 위한 상한\n가격(기준가대비 +/-5%가 CB 발동\n조건인 경우 -5%를 계산한 가격)\n예) 9999999999.99
	out->check_exe_prc = Str2Dbl(data->check_exe_prc, sizeof(data->check_exe_prc), 8);	// 조회용행사가격, 예) 999999999.99999999
	out->atm_clsf = data->atm_clsf[0];	//ATM구분코드, 0:선물, 1:ATM, 2:ITM, 3:OTM
	out->last_trading_clsf = data->last_trading_clsf[0];	//최종거래일여부, Y, N
	out->ex_divid_aft_value = Str2Dbl(data->ex_divid_aft_value, sizeof(data->ex_divid_aft_value), 6);	// 배당락후배당가치, 주식 및 주가지수 상품에만 적용됨\n- 선물 : 배당락후미래가치\n- 옵션 : 배당락후현재가치\n예) 999999999.999999
	out->yest_close_prc = Str2SignDouble(data->yest_close_prc_sign, sizeof(data->yest_close_prc_sign) + sizeof(data->yest_close_prc), 2);	// 전일종가, 예) 9999999999.99
	out->yest_close_prc_clsf = data->yest_close_prc_clsf[0];	//전일종가구분코드, 1:실세, 3:거래무\n2:기세 -2012.05.14 삭제
	out->yest_init_prc = Str2SignDouble(data->yest_init_prc_sign, sizeof(data->yest_init_prc_sign) + sizeof(data->yest_init_prc), 2);	// 전일시가, 예) 9999999999.99
	out->yest_high_pric = Str2SignDouble(data->yest_high_prc_sign, sizeof(data->yest_high_prc_sign) + sizeof(data->yest_high_pric), 2);	// 전일고가, 예) 9999999999.99
	out->yest_low_prc = Str2SignDouble(data->yest_low_prc_sign, sizeof(data->yest_low_prc_sign) + sizeof(data->yest_low_prc), 2);	// 전일저가, 예) 9999999999.99
	memcpy(out->yest_first_exe_date, data->yest_first_exe_date, sizeof(data->yest_first_exe_date));	// 최초체결일자
	memcpy(out->yest_last_exe_time, data->yest_last_exe_time, sizeof(data->yest_last_exe_time));	// 전일최종체결시각
	memcpy(out->yest_sett_prc_clsf, data->yest_sett_prc_clsf, sizeof(data->yest_sett_prc_clsf));	// 전일정산가격구분, *선물\n 10:정산가없음\n 11:당일종가(실세)\n 12:당일기세(거래성립후기세) - 2010.12.20 삭제\n 13:전일정산가(거래성립후 종가미형성) - 2010.12.20 삭제\n 14:당일이론가(거래성립후 종가미형성)\n 15:스프레드분 종가 - 2010.12.20 삭제\n 16:조정된 전일 정산가 - 2010.12.20 삭제\n 17:대상자산 종가(이론가없는 상품)\n 18:정산기준가격 - 2010.12.20 추가
	out->sett_prc_theory_prc_diff_pctg = Str2SignDouble(data->sett_prc_theory_prc_diff_pctg_sign, sizeof(data->sett_prc_theory_prc_diff_pctg_sign) + sizeof(data->sett_prc_theory_prc_diff_pctg), 6);	// 정산가격이론가격괴리율, 에) 999999.999999
	out->yest_open_interest_q = Str2Dbl(data->yest_open_interest_q, sizeof(data->yest_open_interest_q), 0);	// 전일미결제약정수량
	out->yest_s_limit_ord_prc = Str2SignDouble(data->yest_s_limit_ord_prc_sign, sizeof(data->yest_s_limit_ord_prc_sign) + sizeof(data->yest_s_limit_ord_prc), 2);	// 전일매도우선호가가격, 예) 9999999999.99
	out->yest_l_limit_ord_prc = Str2SignDouble(data->yest_l_limit_ord_prc_sign, sizeof(data->yest_l_limit_ord_prc_sign) + sizeof(data->yest_l_limit_ord_prc), 2);	// 전일매수우선호가가격, 예) 9999999999.99
	out->implied_vol = Str2Dbl(data->implied_vol, sizeof(data->implied_vol), 4);	// 내재변동성, 예) 999999.9999
	out->listed_high_prc = Str2SignDouble(data->listed_high_prc_sign, sizeof(data->listed_high_prc_sign) + sizeof(data->listed_high_prc), 2);	// 상장중최고가, 예) 9999999999.99
	out->listed_low_prc = Str2SignDouble(data->listed_low_prc_sign, sizeof(data->listed_low_prc_sign) + sizeof(data->listed_low_prc), 2);	// 상장중최저가, 예) 9999999999.99
	out->year_high_prc = Str2SignDouble(data->year_high_prc_sign, sizeof(data->year_high_prc_sign) + sizeof(data->year_high_prc), 2);	// 연중최고가, 예) 9999999999.99
	out->year_low_prc = Str2SignDouble(data->year_low_prc_sign, sizeof(data->year_low_prc_sign) + sizeof(data->year_low_prc), 2);	// 연중최저가, 예) 9999999999.99
	memcpy(out->listed_high_prc_date, data->listed_high_prc_date, sizeof(data->listed_high_prc_date));	// 상장중최고가일자
	memcpy(out->listed_low_prc_date, data->listed_low_prc_date, sizeof(data->listed_low_prc_date));	// 상장중최저가일자
	memcpy(out->year_high_prc_date, data->year_high_prc_date, sizeof(data->year_high_prc_date));	// 연중최고가일자
	memcpy(out->year_low_prc_date, data->year_low_prc_date, sizeof(data->year_low_prc_date));	// 연중최저가일자
	out->year_std_date = Str2Int(data->year_std_date, sizeof(data->year_std_date));	// 연간기준일수
	out->month_trd_date = Str2Int(data->month_trd_date, sizeof(data->month_trd_date));	// 월간거래일수
	out->year_trd_date = Str2Int(data->year_trd_date, sizeof(data->year_trd_date));	// 연간거래일수
	out->yest_exe_trd_cnt  = Str2Dbl(data->yest_exe_trd_cnt , sizeof(data->yest_exe_trd_cnt ), 0);	// 전일체결건수
	out->yest_exe_q = Str2Dbl(data->yest_exe_q, sizeof(data->yest_exe_q), 0);	// 전일체결수량, 전일협의대량매매체결수량이 포함되지 않음
	out->yest_trd_amt = Str2Dbl(data->yest_trd_amt, sizeof(data->yest_trd_amt), 0);	// 전일거래대금, 전일협의대량매매거래대금이 포함되지 않음
	out->yest_block_trd_exe_q = Str2Dbl(data->yest_block_trd_exe_q, sizeof(data->yest_block_trd_exe_q), 0);	// 전일협의대량합산체결수량, 전일협의대량매매체결수량 => 전일협의대량합산체결수량 [전일체결수량+전일협의대량매매체결수량(협의대량+FLEX)] 2016.03.28 변경
	out->yest_block_trd_total_amt = Str2Dbl(data->yest_block_trd_total_amt, sizeof(data->yest_block_trd_total_amt), 0);	// 전일협의대량합산거래대금, 전일협의대량매매거래대금 => 전일협의대량합산거래대금 [전일거래대금+전일협의대량매매거래대금(협의대량+FLEX)] 2016.03.28 변경
	out->cd_rate = Str2Dbl(data->cd_rate, sizeof(data->cd_rate), 3);	// CD금리, 예) 999.999
	out->open_interest_q = Str2Dbl(data->open_interest_q, sizeof(data->open_interest_q), 0);	// 미결제한도수량, *적용일에 적용되는 상품의 계좌별\n 미결제 한도 계약수. 미결제 한도가\n 적용되지 않은 상품은 0\n*주식선물에만 해당\n8 => 15, 20140303
	memcpy(out->product_cat, data->product_cat, sizeof(data->product_cat));	// 소속 상품군, *주식선물/옵션에만 해당
	out->product_cat_off_pctg = Str2Dbl(data->product_cat_off_pctg, sizeof(data->product_cat_off_pctg), 2);	// 상품군 옵셋율, *백분율로 표시\n*주식선물/옵션에만 해당예) 9999999.99\n5 => 9, 20140303
	out->limit_ord_clsf_code = Str2Int(data->limit_ord_clsf_code, sizeof(data->limit_ord_clsf_code));	// 지정가호가조건구분코드, 호가의 체결 및 잔류조건. Bitwise 정의\n--코드값--\n1: FAS (Fill And Store)\n2: FOK (Fill Or Kill)\n3: FAK (Fill And Kill)\n\n* 지정가호가조건구분코드 BITWISE 정의\n향후 확장성을 위해 해당 10진수값을 2진수로 변환하여 처리요망(최대 16bit까지 사용가능)\n예 ) 지정가호가조건구분코드 값이 6이면\n	(십진수 6 -> 이진수 00000110)\n0번째 bit 0 -> 0 : FAS\n1번째 bit 1 -> 2 : FOK\n2번째 bit 1 -> 4 : FAK\n즉, FOK이면서 FAK를 수용한다는 의미 (FOK & FAK)\nX => 9, 1 => 5, 20140303
	out->mrk_ord_clsf_code = Str2Int(data->mrk_ord_clsf_code, sizeof(data->mrk_ord_clsf_code));	// 시장가호가조건구분코드, * 상동
	out->cond_limit_ord_clsf_code = Str2Int(data->cond_limit_ord_clsf_code, sizeof(data->cond_limit_ord_clsf_code));	// 조건부지정가호가조건구분코드, * 상동
	out->best_limit_ord_clsf_code = Str2Int(data->best_limit_ord_clsf_code, sizeof(data->best_limit_ord_clsf_code));	// 최유리지정가호가조건구분코드, * 상동
	out->efp_clsf = data->efp_clsf[0];	//EFP거래대상여부, Y, N, 상품선물만 해당
	out->flex_clsf = data->flex_clsf[0];	//FLEX거래대상여부, Y, N, 상품선물만 해당
	out->yest_efp_exe_q = Str2Dbl(data->yest_efp_exe_q, sizeof(data->yest_efp_exe_q), 0);	// 전일EFP체결수량, 상품선물만 해당
	out->yest_efp_trd_amount = Str2Dbl(data->yest_efp_trd_amount, sizeof(data->yest_efp_trd_amount), 0);	// 전일EFP거래대금, 상품선물만 해당
	out->mkr_close_clsf = data->mkr_close_clsf[0];	//휴장여부, 휴장여부 (Y,N), 20121217
	out->real_t_prc_limit_clsf = data->real_t_prc_limit_clsf[0];	//실시간가격제한여부, 직전 체결가격 대비 특정 범위를 초과하는 호가는 거부하도록 제한할지 여부(Y/N) 20140901
	out->real_t_high_price_gap = Str2SignDouble(data->real_t_high_price_gap_sign, sizeof(data->real_t_high_price_gap_sign) + sizeof(data->real_t_high_price_gap), 2);	// 실시간상한가간격, 직전 체결가격과 실시간상한가와의 간격\n실시간상한가 = 직전체결가격 + 실시간상한가간격\nex) 9999999999.99  20140901
	out->real_t_low_price_gap = Str2SignDouble(data->real_t_low_price_gap_sign, sizeof(data->real_t_low_price_gap_sign) + sizeof(data->real_t_low_price_gap), 2);	// 실시간하한가간격, 직전 체결가격과 실시간하한가와의 간격\n실시간하한가 = 직전체결가격 + 실시간하한가간격(음수)\nex) 9999999999.99 20140901
	memcpy(out->under_ass_mrk_id, data->under_ass_mrk_id, sizeof(data->under_ass_mrk_id));	// 기초자산시장ID, 기초자산시장ID는 기초자산이 KRX에 상장된 경우에만 채워짐.\nK200선물옵션:STK\n코스닥150선물:KSQ\n주식선물옵션:STK/KSQ\n상품선물옵션:SPACE\n변동성지수선물:STK\n섹터지수선물:STK\n미니K200선물옵션:STK
	out->limit_ord_upper_limit_q = Str2Dbl(data->limit_ord_upper_limit_q, sizeof(data->limit_ord_upper_limit_q), 0);	// 상한수량, 호가상한수량 (20181210 항목추가)
	out->limit_ord_lower_limit_q = Str2Dbl(data->limit_ord_lower_limit_q, sizeof(data->limit_ord_lower_limit_q), 0);	// 하한수량, 호가하한수량 (20181210 항목추가)
	out->block_trd_ord_upper_limit_q = Str2Dbl(data->block_trd_ord_upper_limit_q, sizeof(data->block_trd_ord_upper_limit_q), 0);	// 협의대량매매상한수량, 협의대량매매호가상한수량 (20181210 항목추가)
	out->block_trd_ord_lower_limit_q = Str2Dbl(data->block_trd_ord_lower_limit_q, sizeof(data->block_trd_ord_lower_limit_q), 0);	// 협의대량매매하한수량, 협의대량매매호가하한수량 (20181210 항목추가)

	return 1;
}


// 주식선물_조정내역 데이터
int ParseH4015(const double& timestamp, const char* in_buff, DF_STOCK_FUT_ADJ_INFO_DATA* out) {
	STOCK_FUT_ADJ_INFO_DATA* data = (STOCK_FUT_ADJ_INFO_DATA*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA구분, H4
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// 정보구분, 01:개별주식선물
	out->mrk_clsf = data->mrk_clsf[0];	//시장구분, 5
	memcpy(out->trd_date, data->trd_date, sizeof(data->trd_date));	// 영업일자
	memcpy(out->isin_clsf, data->isin_clsf, sizeof(data->isin_clsf));	// 종목코드, 최종 record '999999999999' set
	out->adj_coef_denominator = Str2Dbl(data->adj_coef_denominator, sizeof(data->adj_coef_denominator), 8);	// 조정계수분모, 예) 999999999999.99999999
	out->adj_coef_numerator = Str2Dbl(data->adj_coef_numerator, sizeof(data->adj_coef_numerator), 8);	// 조정계수분자, 예) 999999999999.99999999
	out->bef_adj_unit_size = Str2Dbl(data->bef_adj_unit_size, sizeof(data->bef_adj_unit_size), 8);	// 조정전 거래단위(계약크기), 예) 999999999999.99999999
	out->aft_adj_unit_size = Str2Dbl(data->aft_adj_unit_size, sizeof(data->aft_adj_unit_size), 8);	// 조정후 거래단위(계약크기), 예) 999999999999.99999999
	out->bef_adj_exercise_prc = Str2Dbl(data->bef_adj_exercise_prc, sizeof(data->bef_adj_exercise_prc), 8);	// 조정전 행사가격, 예) 999999999999.99999999
	out->aft_adj_exercise_prc = Str2Dbl(data->aft_adj_exercise_prc, sizeof(data->aft_adj_exercise_prc), 8);	// 조정후 행사가격, 예) 999999999999.99999999
	out->aft_adj_open_interest_adj_coef = Str2Int(data->aft_adj_open_interest_adj_coef, sizeof(data->aft_adj_open_interest_adj_coef));	// 조정후 미결제수량 조정계수

	return 1;
}


// 주식선물_Polling 데이터
int ParseI2015(const double& timestamp, const char* in_buff, DF_STOCK_FUT_POLLING_DATA* out) {
	STOCK_FUT_POLLING_DATA* data = (STOCK_FUT_POLLING_DATA*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA구분, I2
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// 정보구분, 01:개별주식선물
	out->mrk_cslf = data->mrk_cslf[0];	//시장구분, 5
	memcpy(out->send_t, data->send_t, sizeof(data->send_t));	// 전송시간, HHSS
	memcpy(out->main_backup_clsf, data->main_backup_clsf, sizeof(data->main_backup_clsf));	// Main Backup구분, space

	return 1;
}


// 주식선물_SPACE
int ParseG9015(const double& timestamp, const char* in_buff, DF_STOCK_FUT_SPACE* out) {
	STOCK_FUT_SPACE* data = (STOCK_FUT_SPACE*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA구분, G9
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// 정보구분, 01:개별주식선물
	out->mrk_clsf = data->mrk_clsf[0];	//시장구분, 5

	return 1;
}
