// parsing.c
#include "parsing.h"
#include "kp200_futures_tr.h"


// char* to PyLong
PyObject* char_to_pylong(char* str, int len) {
	char* buffer = (char*)malloc(len + 1);
	memcpy(buffer, str, len);
	buffer[len] = 0x00;
	PyObject* ret = PyLong_FromString(buffer, NULL, 10);
	free(buffer);
	return ret;
}


// char* to PyFloat (char*에 '.'이 포함되지 않아야함)
PyObject* char_to_pyfloat(char* str, int tot_len, int int_part_len) {
	const int new_tot_len = tot_len + 1;
	char* buffer = (char*)malloc(new_tot_len);
	memcpy(buffer, str, int_part_len);
	buffer[int_part_len] = 0x2E;
	memcpy(&buffer[int_part_len+1], &str[int_part_len], tot_len - int_part_len);
	PyObject* ret = PyFloat_FromString(PyUnicode_DecodeASCII(buffer, new_tot_len, NULL));
	free(buffer);
	return ret;
}


// K200선물_경쟁+협의합산
PyObject* parse_k200_fut_comp_block(char* raw_data) {
	const char* error = NULL;
	K200_FUT_COMP_BLOCK* data = (K200_FUT_COMP_BLOCK*)raw_data;

	PyObject* ret_tuple = PyTuple_New(7);

	PyTuple_SetItem(ret_tuple, 0, PyUnicode_DecodeASCII(data->data_clsf, sizeof(data->data_clsf), error));	// DATA구분
	PyTuple_SetItem(ret_tuple, 1, PyUnicode_DecodeASCII(data->info_clsf, sizeof(data->info_clsf), error));	// 정보구분
	PyTuple_SetItem(ret_tuple, 2, PyUnicode_DecodeASCII(data->mkt_clsf, sizeof(data->mkt_clsf), error));	// 시장구분
	PyTuple_SetItem(ret_tuple, 3, PyUnicode_DecodeASCII(data->isin_clsf, sizeof(data->isin_clsf), error));	// 종목코드
	PyTuple_SetItem(ret_tuple, 4, char_to_pylong(data->seq, sizeof(data->seq)));	// 종목일련번호
	PyTuple_SetItem(ret_tuple, 5, char_to_pylong(data->cpt_block_trd_vol, sizeof(data->cpt_block_trd_vol)));	// 경쟁+협의합산 거래량
	PyTuple_SetItem(ret_tuple, 6, char_to_pylong(data->cpt_block_trd_amt, sizeof(data->cpt_block_trd_amt)));	// 경쟁+협의합산 거래대금

	return ret_tuple;
};


// K200선물_체결
PyObject* parse_k200_fut_exec(char* raw_data) {
	const char* error = NULL;
	K200_FUT_EXEC* data = (K200_FUT_EXEC*)raw_data;

	PyObject* ret_tuple = PyTuple_New(29);

	PyTuple_SetItem(ret_tuple, 0, PyUnicode_DecodeASCII(data->data_clsf, sizeof(data->data_clsf), error));	// DATA구분
	PyTuple_SetItem(ret_tuple, 1, PyUnicode_DecodeASCII(data->info_clsf, sizeof(data->info_clsf), error));	// 정보구분
	PyTuple_SetItem(ret_tuple, 2, PyUnicode_DecodeASCII(data->mkt_clsf, sizeof(data->mkt_clsf), error));	// 시장구분
	PyTuple_SetItem(ret_tuple, 3, PyUnicode_DecodeASCII(data->isin_clsf, sizeof(data->isin_clsf), error));	// 종목코드
	PyTuple_SetItem(ret_tuple, 4, char_to_pylong(data->seq, sizeof(data->seq)));	// 종목일련번호
	PyTuple_SetItem(ret_tuple, 5, PyUnicode_DecodeASCII(data->brd_id, sizeof(data->brd_id), error));	// 보드ID
	PyTuple_SetItem(ret_tuple, 6, PyUnicode_DecodeASCII(data->cur_prc_sign, sizeof(data->cur_prc_sign), error));	// 현재가격부호
	PyTuple_SetItem(ret_tuple, 7, char_to_pyfloat(data->cur_prc, sizeof(data->cur_prc), 3));	// 현재가격
	PyTuple_SetItem(ret_tuple, 8, char_to_pylong(data->exe_q, sizeof(data->exe_q)));	// 체결수량
	PyTuple_SetItem(ret_tuple, 9, PyUnicode_DecodeASCII(data->ss_id, sizeof(data->ss_id), error));	// 세션ID
	PyTuple_SetItem(ret_tuple, 10, PyUnicode_DecodeASCII(data->exe_t, sizeof(data->exe_t), error));	// 체결시각
	PyTuple_SetItem(ret_tuple, 11, char_to_pyfloat(data->rct_prd_prc, sizeof(data->rct_prd_prc), 3));	// 최근월물의제약정가격
	PyTuple_SetItem(ret_tuple, 12, char_to_pyfloat(data->nxt_prd_prc, sizeof(data->nxt_prd_prc), 3));	// 원월물의제약정가격
	PyTuple_SetItem(ret_tuple, 13, PyUnicode_DecodeASCII(data->init_prc_sign, sizeof(data->init_prc_sign), error));	// 시가부호
	PyTuple_SetItem(ret_tuple, 14, char_to_pyfloat(data->init_prc, sizeof(data->init_prc), 3));	// 시가
	PyTuple_SetItem(ret_tuple, 15, PyUnicode_DecodeASCII(data->high_prc_sign, sizeof(data->high_prc_sign), error));	// 고가부호
	PyTuple_SetItem(ret_tuple, 16, char_to_pyfloat(data->high_prc, sizeof(data->high_prc), 3));	// 고가
	PyTuple_SetItem(ret_tuple, 17, PyUnicode_DecodeASCII(data->low_prc_sign, sizeof(data->low_prc_sign), error));	// 저가부호
	PyTuple_SetItem(ret_tuple, 18, char_to_pyfloat(data->low_prc, sizeof(data->low_prc), 3));	// 저가
	PyTuple_SetItem(ret_tuple, 19, PyUnicode_DecodeASCII(data->pri_prc_sign, sizeof(data->pri_prc_sign), error));	// 직전가격부호
	PyTuple_SetItem(ret_tuple, 20, char_to_pyfloat(data->pri_prc, sizeof(data->pri_prc), 3));	// 직전가격
	PyTuple_SetItem(ret_tuple, 21, char_to_pylong(data->accm_exe_q, sizeof(data->accm_exe_q)));	// 누적체결수량
	PyTuple_SetItem(ret_tuple, 22, char_to_pylong(data->accm_trd_amt, sizeof(data->accm_trd_amt)));	// 누적거래대금
	PyTuple_SetItem(ret_tuple, 23, PyUnicode_DecodeASCII(data->accm_block_trd_exe_q, sizeof(data->accm_block_trd_exe_q), error));	// 협의대량누적체결수량
	PyTuple_SetItem(ret_tuple, 24, PyUnicode_DecodeASCII(data->l_or_s, sizeof(data->l_or_s), error));	// 최종매도매수구분코드
	PyTuple_SetItem(ret_tuple, 25, PyUnicode_DecodeASCII(data->real_t_high_prc_sign, sizeof(data->real_t_high_prc_sign), error));	// 실시간상한가부호
	PyTuple_SetItem(ret_tuple, 26, char_to_pyfloat(data->real_t_high_prc, sizeof(data->real_t_high_prc), 3));	// 실시간상한가
	PyTuple_SetItem(ret_tuple, 27, PyUnicode_DecodeASCII(data->real_t_low_prc_sign, sizeof(data->real_t_low_prc_sign), error));	// 실시간하한가부호
	PyTuple_SetItem(ret_tuple, 28, char_to_pyfloat(data->real_t_low_prc, sizeof(data->real_t_low_prc), 3));	// 실시간하한가

	return ret_tuple;
}


// K200선물_우선호가
PyObject* parse_k200_fut_limit_ord(char* raw_data) {
	const char* error = NULL;
	K200_FUT_LIMIT_ORD* data = (K200_FUT_LIMIT_ORD*)raw_data;

	PyObject* ret_tuple = PyTuple_New(54);

	PyTuple_SetItem(ret_tuple, 0, PyUnicode_DecodeASCII(data->data_clsf, sizeof(data->data_clsf), error));	// DATA구분
	PyTuple_SetItem(ret_tuple, 1, PyUnicode_DecodeASCII(data->info_clsf, sizeof(data->info_clsf), error));	// 정보구분
	PyTuple_SetItem(ret_tuple, 2, PyUnicode_DecodeASCII(data->mkt_clsf, sizeof(data->mkt_clsf), error));	// 시장구분
	PyTuple_SetItem(ret_tuple, 3, PyUnicode_DecodeASCII(data->isin_clsf, sizeof(data->isin_clsf), error));	// 종목코드
	PyTuple_SetItem(ret_tuple, 4, char_to_pylong(data->seq, sizeof(data->seq)));	// 종목일련번호
	PyTuple_SetItem(ret_tuple, 5, PyUnicode_DecodeASCII(data->brd_id, sizeof(data->brd_id), error));	// 보드ID
	PyTuple_SetItem(ret_tuple, 6, PyUnicode_DecodeASCII(data->ss_id, sizeof(data->ss_id), error));	// 세션ID
	PyTuple_SetItem(ret_tuple, 7, char_to_pylong(data->total_l_limit_ord_q, sizeof(data->total_l_limit_ord_q)));	// 매수총호가잔량
	PyTuple_SetItem(ret_tuple, 8, PyUnicode_DecodeASCII(data->l_lvl_1_sign, sizeof(data->l_lvl_1_sign), error));	// 매수1단계부호
	PyTuple_SetItem(ret_tuple, 9, char_to_pyfloat(data->l_lvl_1_prc, sizeof(data->l_lvl_1_prc), 3));	// 매수1단계우선호가가격
	PyTuple_SetItem(ret_tuple, 10, char_to_pylong(data->l_lvl_1_q, sizeof(data->l_lvl_1_q)));	// 매수1단계우선호가잔량
	PyTuple_SetItem(ret_tuple, 11, PyUnicode_DecodeASCII(data->l_lvl_2_sign, sizeof(data->l_lvl_2_sign), error));	// 매수2단계부호
	PyTuple_SetItem(ret_tuple, 12, char_to_pyfloat(data->l_lvl_2_prc, sizeof(data->l_lvl_2_prc), 3));	// 매수2단계우선호가가격
	PyTuple_SetItem(ret_tuple, 13, char_to_pylong(data->l_lvl_2_q, sizeof(data->l_lvl_2_q)));	// 매수2단계우선호가잔량
	PyTuple_SetItem(ret_tuple, 14, PyUnicode_DecodeASCII(data->l_lvl_3_sign, sizeof(data->l_lvl_3_sign), error));	// 매수3단계부호
	PyTuple_SetItem(ret_tuple, 15, char_to_pyfloat(data->l_lvl_3_prc, sizeof(data->l_lvl_3_prc), 3));	// 매수3단계우선호가가격
	PyTuple_SetItem(ret_tuple, 16, char_to_pylong(data->l_lvl_3_q, sizeof(data->l_lvl_3_q)));	// 매수3단계우선호가잔량
	PyTuple_SetItem(ret_tuple, 17, PyUnicode_DecodeASCII(data->l_lvl_4_sign, sizeof(data->l_lvl_4_sign), error));	// 매수4단계부호
	PyTuple_SetItem(ret_tuple, 18, char_to_pyfloat(data->l_lvl_4_prc, sizeof(data->l_lvl_4_prc), 3));	// 매수4단계우선호가가격
	PyTuple_SetItem(ret_tuple, 19, char_to_pylong(data->l_lvl_4_q, sizeof(data->l_lvl_4_q)));	// 매수4단계우선호가잔량
	PyTuple_SetItem(ret_tuple, 20, PyUnicode_DecodeASCII(data->l_lvl_5_sign, sizeof(data->l_lvl_5_sign), error));	// 매수5단계부호
	PyTuple_SetItem(ret_tuple, 21, char_to_pyfloat(data->l_lvl_5_prc, sizeof(data->l_lvl_5_prc), 3));	// 매수5단계우선호가가격
	PyTuple_SetItem(ret_tuple, 22, char_to_pylong(data->l_lvl_5_q, sizeof(data->l_lvl_5_q)));	// 매수5단계우선호가잔량
	PyTuple_SetItem(ret_tuple, 23, char_to_pylong(data->total_s_limit_ord_q, sizeof(data->total_s_limit_ord_q)));	// 매도총호가잔량
	PyTuple_SetItem(ret_tuple, 24, PyUnicode_DecodeASCII(data->s_lvl_1_sign, sizeof(data->s_lvl_1_sign), error));	// 매도1단계부호
	PyTuple_SetItem(ret_tuple, 25, char_to_pyfloat(data->s_lvl_1_prc, sizeof(data->s_lvl_1_prc), 3));	// 매도1단계우선호가가격
	PyTuple_SetItem(ret_tuple, 26, char_to_pylong(data->s_lvl_1_q, sizeof(data->s_lvl_1_q)));	// 매도1단계우선호가잔량
	PyTuple_SetItem(ret_tuple, 27, PyUnicode_DecodeASCII(data->s_lvl_2_sign, sizeof(data->s_lvl_2_sign), error));	// 매도2단계부호
	PyTuple_SetItem(ret_tuple, 28, char_to_pyfloat(data->s_lvl_2_prc, sizeof(data->s_lvl_2_prc), 3));	// 매도2단계우선호가가격
	PyTuple_SetItem(ret_tuple, 29, char_to_pylong(data->s_lvl_2_q, sizeof(data->s_lvl_2_q)));	// 매도2단계우선호가잔량
	PyTuple_SetItem(ret_tuple, 30, PyUnicode_DecodeASCII(data->s_lvl_3_sign, sizeof(data->s_lvl_3_sign), error));	// 매도3단계부호
	PyTuple_SetItem(ret_tuple, 31, char_to_pyfloat(data->s_lvl_3_prc, sizeof(data->s_lvl_3_prc), 3));	// 매도3단계우선호가가격
	PyTuple_SetItem(ret_tuple, 32, char_to_pylong(data->s_lvl_3_q, sizeof(data->s_lvl_3_q)));	// 매도3단계우선호가잔량
	PyTuple_SetItem(ret_tuple, 33, PyUnicode_DecodeASCII(data->s_lvl_4_sign, sizeof(data->s_lvl_4_sign), error));	// 매도4단계부호
	PyTuple_SetItem(ret_tuple, 34, char_to_pyfloat(data->s_lvl_4_prc, sizeof(data->s_lvl_4_prc), 3));	// 매도4단계우선호가가격
	PyTuple_SetItem(ret_tuple, 35, char_to_pylong(data->s_lvl_4_q, sizeof(data->s_lvl_4_q)));	// 매도4단계우선호가잔량
	PyTuple_SetItem(ret_tuple, 36, PyUnicode_DecodeASCII(data->s_lvl_5_sign, sizeof(data->s_lvl_5_sign), error));	// 매도5단계부호
	PyTuple_SetItem(ret_tuple, 37, char_to_pyfloat(data->s_lvl_5_prc, sizeof(data->s_lvl_5_prc), 3));	// 매도5단계우선호가가격
	PyTuple_SetItem(ret_tuple, 38, char_to_pylong(data->s_lvl_5_q, sizeof(data->s_lvl_5_q)));	// 매도5단계우선호가잔량
	PyTuple_SetItem(ret_tuple, 39, char_to_pylong(data->total_l_trd_cnt, sizeof(data->total_l_trd_cnt)));	// 매수유효호가건수
	PyTuple_SetItem(ret_tuple, 40, char_to_pylong(data->l_lvl_1_trd_cnt, sizeof(data->l_lvl_1_trd_cnt)));	// 매수1단계우선호가건수
	PyTuple_SetItem(ret_tuple, 41, char_to_pylong(data->l_lvl_2_trd_cnt, sizeof(data->l_lvl_2_trd_cnt)));	// 매수2단계우선호가건수
	PyTuple_SetItem(ret_tuple, 42, char_to_pylong(data->l_lvl_3_trd_cnt, sizeof(data->l_lvl_3_trd_cnt)));	// 매수3단계우선호가건수
	PyTuple_SetItem(ret_tuple, 43, char_to_pylong(data->l_lvl_4_trd_cnt, sizeof(data->l_lvl_4_trd_cnt)));	// 매수4단계우선호가건수
	PyTuple_SetItem(ret_tuple, 44, char_to_pylong(data->l_lvl_5_trd_cnt, sizeof(data->l_lvl_5_trd_cnt)));	// 매수5단계우선호가건수
	PyTuple_SetItem(ret_tuple, 45, char_to_pylong(data->total_s_trd_cnt, sizeof(data->total_s_trd_cnt)));	// 매도유효호가건수
	PyTuple_SetItem(ret_tuple, 46, char_to_pylong(data->s_lvl_1_trd_cnt, sizeof(data->s_lvl_1_trd_cnt)));	// 매도1단계우선호가건수
	PyTuple_SetItem(ret_tuple, 47, char_to_pylong(data->s_lvl_2_trd_cnt, sizeof(data->s_lvl_2_trd_cnt)));	// 매도2단계우선호가건수
	PyTuple_SetItem(ret_tuple, 48, char_to_pylong(data->s_lvl_3_trd_cnt, sizeof(data->s_lvl_3_trd_cnt)));	// 매도3단계우선호가건수
	PyTuple_SetItem(ret_tuple, 49, char_to_pylong(data->s_lvl_4_trd_cnt, sizeof(data->s_lvl_4_trd_cnt)));	// 매도4단계우선호가건수
	PyTuple_SetItem(ret_tuple, 50, char_to_pylong(data->s_lvl_5_trd_cnt, sizeof(data->s_lvl_5_trd_cnt)));	// 매도5단계우선호가건수
	PyTuple_SetItem(ret_tuple, 51, PyUnicode_DecodeASCII(data->ord_rcv_t, sizeof(data->ord_rcv_t), error));	// 호가접수시각
	PyTuple_SetItem(ret_tuple, 52, PyUnicode_DecodeASCII(data->exp_prc_sign, sizeof(data->exp_prc_sign), error));	// 예상체결가격부호
	PyTuple_SetItem(ret_tuple, 53, char_to_pyfloat(data->exp_prc, sizeof(data->exp_prc), 3));	// 예상체결가격

	return ret_tuple;
}


// K200선물_체결_우선호가
PyObject* parse_k200_fut_exec_limit_ord(char* raw_data) {
	const char* error = NULL;
	K200_FUT_EXEC_LIMIT_ORD* data = (K200_FUT_EXEC_LIMIT_ORD*)raw_data;

	PyObject* ret_tuple = PyTuple_New(73);

	PyTuple_SetItem(ret_tuple, 0, PyUnicode_DecodeASCII(data->data_clsf, sizeof(data->data_clsf), error));	// DATA구분
	PyTuple_SetItem(ret_tuple, 1, PyUnicode_DecodeASCII(data->info_clsf, sizeof(data->info_clsf), error));	// 정보구분
	PyTuple_SetItem(ret_tuple, 2, PyUnicode_DecodeASCII(data->mrk_clsf, sizeof(data->mrk_clsf), error));	// 시장구분
	PyTuple_SetItem(ret_tuple, 3, PyUnicode_DecodeASCII(data->isin_clsf, sizeof(data->isin_clsf), error));	// 종목코드
	PyTuple_SetItem(ret_tuple, 4, char_to_pylong(data->seq, sizeof(data->seq)));	// 종목일련번호
	PyTuple_SetItem(ret_tuple, 5, PyUnicode_DecodeASCII(data->brd_id, sizeof(data->brd_id), error));	// 보드ID
	PyTuple_SetItem(ret_tuple, 6, PyUnicode_DecodeASCII(data->cur_prc_sign, sizeof(data->cur_prc_sign), error));	// 현재가격부호
	PyTuple_SetItem(ret_tuple, 7, char_to_pyfloat(data->cur_price, sizeof(data->cur_price), 3));	// 현재가격
	PyTuple_SetItem(ret_tuple, 8, char_to_pylong(data->exe_q, sizeof(data->exe_q)));	// 체결수량
	PyTuple_SetItem(ret_tuple, 9, PyUnicode_DecodeASCII(data->ss_id, sizeof(data->ss_id), error));	// 세션ID
	PyTuple_SetItem(ret_tuple, 10, PyUnicode_DecodeASCII(data->exe_t, sizeof(data->exe_t), error));	// 체결시각
	PyTuple_SetItem(ret_tuple, 11, char_to_pyfloat(data->rct_prd_prc, sizeof(data->rct_prd_prc), 3));	// 최근월물의제약정가격
	PyTuple_SetItem(ret_tuple, 12, char_to_pyfloat(data->nxt_prd_prc, sizeof(data->nxt_prd_prc), 3));	// 원월물의제약정가격
	PyTuple_SetItem(ret_tuple, 13, PyUnicode_DecodeASCII(data->init_prc_sign, sizeof(data->init_prc_sign), error));	// 시가부호
	PyTuple_SetItem(ret_tuple, 14, char_to_pyfloat(data->init_prc, sizeof(data->init_prc), 3));	// 시가
	PyTuple_SetItem(ret_tuple, 15, PyUnicode_DecodeASCII(data->high_prc_sign, sizeof(data->high_prc_sign), error));	// 고가부호
	PyTuple_SetItem(ret_tuple, 16, char_to_pyfloat(data->high_prc, sizeof(data->high_prc), 3));	// 고가
	PyTuple_SetItem(ret_tuple, 17, PyUnicode_DecodeASCII(data->low_prc_sign, sizeof(data->low_prc_sign), error));	// 저가부호
	PyTuple_SetItem(ret_tuple, 18, char_to_pyfloat(data->low_prc, sizeof(data->low_prc), 3));	// 저가
	PyTuple_SetItem(ret_tuple, 19, PyUnicode_DecodeASCII(data->pri_prc_sign, sizeof(data->pri_prc_sign), error));	// 직전가격부호
	PyTuple_SetItem(ret_tuple, 20, char_to_pyfloat(data->pri_prc, sizeof(data->pri_prc), 3));	// 직전가격
	PyTuple_SetItem(ret_tuple, 21, char_to_pylong(data->accm_exe_q, sizeof(data->accm_exe_q)));	// 누적체결수량
	PyTuple_SetItem(ret_tuple, 22, char_to_pylong(data->accm_trd_amt, sizeof(data->accm_trd_amt)));	// 누적거래대금
	PyTuple_SetItem(ret_tuple, 23, PyUnicode_DecodeASCII(data->accm_block_trd_exe_q, sizeof(data->accm_block_trd_exe_q), error));	// 협의대량누적체결수량
	PyTuple_SetItem(ret_tuple, 24, PyUnicode_DecodeASCII(data->l_or_s, sizeof(data->l_or_s), error));	// 최종매도매수구분코드
	PyTuple_SetItem(ret_tuple, 25, char_to_pylong(data->total_l_limit_ord_q, sizeof(data->total_l_limit_ord_q)));	// 매수총호가잔량
	PyTuple_SetItem(ret_tuple, 26, PyUnicode_DecodeASCII(data->l_lvl_1_sign, sizeof(data->l_lvl_1_sign), error));	// 매수1단계부호
	PyTuple_SetItem(ret_tuple, 27, char_to_pyfloat(data->l_lvl_1_prc, sizeof(data->l_lvl_1_prc), 3));	// 매수1단계우선호가가격
	PyTuple_SetItem(ret_tuple, 28, char_to_pylong(data->l_lvl_1_q, sizeof(data->l_lvl_1_q)));	// 매수1단계우선호가잔량
	PyTuple_SetItem(ret_tuple, 29, PyUnicode_DecodeASCII(data->l_lvl_2_sign, sizeof(data->l_lvl_2_sign), error));	// 매수2단계부호
	PyTuple_SetItem(ret_tuple, 30, char_to_pyfloat(data->l_lvl_2_prc, sizeof(data->l_lvl_2_prc), 3));	// 매수2단계우선호가가격
	PyTuple_SetItem(ret_tuple, 31, char_to_pylong(data->l_lvl_2_q, sizeof(data->l_lvl_2_q)));	// 매수2단계우선호가잔량
	PyTuple_SetItem(ret_tuple, 32, PyUnicode_DecodeASCII(data->l_lvl_3_sign, sizeof(data->l_lvl_3_sign), error));	// 매수3단계부호
	PyTuple_SetItem(ret_tuple, 33, char_to_pyfloat(data->l_lvl_3_prc, sizeof(data->l_lvl_3_prc), 3));	// 매수3단계우선호가가격
	PyTuple_SetItem(ret_tuple, 34, char_to_pylong(data->l_lvl_3_q, sizeof(data->l_lvl_3_q)));	// 매수3단계우선호가잔량
	PyTuple_SetItem(ret_tuple, 35, PyUnicode_DecodeASCII(data->l_lvl_4_sign, sizeof(data->l_lvl_4_sign), error));	// 매수4단계부호
	PyTuple_SetItem(ret_tuple, 36, char_to_pyfloat(data->l_lvl_4_prc, sizeof(data->l_lvl_4_prc), 3));	// 매수4단계우선호가가격
	PyTuple_SetItem(ret_tuple, 37, char_to_pylong(data->l_lvl_4_q, sizeof(data->l_lvl_4_q)));	// 매수4단계우선호가잔량
	PyTuple_SetItem(ret_tuple, 38, PyUnicode_DecodeASCII(data->l_lvl_5_sign, sizeof(data->l_lvl_5_sign), error));	// 매수5단계부호
	PyTuple_SetItem(ret_tuple, 39, char_to_pyfloat(data->l_lvl_5_prc, sizeof(data->l_lvl_5_prc), 3));	// 매수5단계우선호가가격
	PyTuple_SetItem(ret_tuple, 40, char_to_pylong(data->l_lvl_5_q, sizeof(data->l_lvl_5_q)));	// 매수5단계우선호가잔량
	PyTuple_SetItem(ret_tuple, 41, char_to_pylong(data->total_s_limit_ord_q, sizeof(data->total_s_limit_ord_q)));	// 매도총호가잔량
	PyTuple_SetItem(ret_tuple, 42, PyUnicode_DecodeASCII(data->s_lvl_1_sign, sizeof(data->s_lvl_1_sign), error));	// 매도1단계부호
	PyTuple_SetItem(ret_tuple, 43, char_to_pyfloat(data->s_lvl_1_prc, sizeof(data->s_lvl_1_prc), 3));	// 매도1단계우선호가가격
	PyTuple_SetItem(ret_tuple, 44, char_to_pylong(data->s_lvl_1_q, sizeof(data->s_lvl_1_q)));	// 매도1단계우선호가잔량
	PyTuple_SetItem(ret_tuple, 45, PyUnicode_DecodeASCII(data->s_lvl_2_sign, sizeof(data->s_lvl_2_sign), error));	// 매도2단계부호
	PyTuple_SetItem(ret_tuple, 46, char_to_pyfloat(data->s_lvl_2_prc, sizeof(data->s_lvl_2_prc), 3));	// 매도2단계우선호가가격
	PyTuple_SetItem(ret_tuple, 47, char_to_pylong(data->s_lvl_2_q, sizeof(data->s_lvl_2_q)));	// 매도2단계우선호가잔량
	PyTuple_SetItem(ret_tuple, 48, PyUnicode_DecodeASCII(data->s_lvl_3_sign, sizeof(data->s_lvl_3_sign), error));	// 매도3단계부호
	PyTuple_SetItem(ret_tuple, 49, char_to_pyfloat(data->s_lvl_3_prc, sizeof(data->s_lvl_3_prc), 3));	// 매도3단계우선호가가격
	PyTuple_SetItem(ret_tuple, 50, char_to_pylong(data->s_lvl_3_q, sizeof(data->s_lvl_3_q)));	// 매도3단계우선호가잔량
	PyTuple_SetItem(ret_tuple, 51, PyUnicode_DecodeASCII(data->s_lvl_4_sign, sizeof(data->s_lvl_4_sign), error));	// 매도4단계부호
	PyTuple_SetItem(ret_tuple, 52, char_to_pyfloat(data->s_lvl_4_prc, sizeof(data->s_lvl_4_prc), 3));	// 매도4단계우선호가가격
	PyTuple_SetItem(ret_tuple, 53, char_to_pylong(data->s_lvl_4_q, sizeof(data->s_lvl_4_q)));	// 매도4단계우선호가잔량
	PyTuple_SetItem(ret_tuple, 54, PyUnicode_DecodeASCII(data->s_lvl_5_sign, sizeof(data->s_lvl_5_sign), error));	// 매도5단계부호
	PyTuple_SetItem(ret_tuple, 55, char_to_pyfloat(data->s_lvl_5_prc, sizeof(data->s_lvl_5_prc), 3));	// 매도5단계우선호가가격
	PyTuple_SetItem(ret_tuple, 56, char_to_pylong(data->s_lvl_5_q, sizeof(data->s_lvl_5_q)));	// 매도5단계우선호가잔량
	PyTuple_SetItem(ret_tuple, 57, char_to_pylong(data->total_l_trd_cnt, sizeof(data->total_l_trd_cnt)));	// 매수유효호가건수
	PyTuple_SetItem(ret_tuple, 58, char_to_pylong(data->l_lvl_1_trd_cnt, sizeof(data->l_lvl_1_trd_cnt)));	// 매수1단계우선호가건수
	PyTuple_SetItem(ret_tuple, 59, char_to_pylong(data->l_lvl_2_trd_cnt, sizeof(data->l_lvl_2_trd_cnt)));	// 매수2단계우선호가건수
	PyTuple_SetItem(ret_tuple, 60, char_to_pylong(data->l_lvl_3_trd_cnt, sizeof(data->l_lvl_3_trd_cnt)));	// 매수3단계우선호가건수
	PyTuple_SetItem(ret_tuple, 61, char_to_pylong(data->l_lvl_4_trd_cnt, sizeof(data->l_lvl_4_trd_cnt)));	// 매수4단계우선호가건수
	PyTuple_SetItem(ret_tuple, 62, char_to_pylong(data->l_lvl_5_trd_cnt, sizeof(data->l_lvl_5_trd_cnt)));	// 매수5단계우선호가건수
	PyTuple_SetItem(ret_tuple, 63, char_to_pylong(data->total_s_trd_cnt, sizeof(data->total_s_trd_cnt)));	// 매도유효호가건수
	PyTuple_SetItem(ret_tuple, 64, char_to_pylong(data->s_lvl_1_trd_cnt, sizeof(data->s_lvl_1_trd_cnt)));	// 매도1단계우선호가건수
	PyTuple_SetItem(ret_tuple, 65, char_to_pylong(data->s_lvl_2_trd_cnt, sizeof(data->s_lvl_2_trd_cnt)));	// 매도2단계우선호가건수
	PyTuple_SetItem(ret_tuple, 66, char_to_pylong(data->s_lvl_3_trd_cnt, sizeof(data->s_lvl_3_trd_cnt)));	// 매도3단계우선호가건수
	PyTuple_SetItem(ret_tuple, 67, char_to_pylong(data->s_lvl_4_trd_cnt, sizeof(data->s_lvl_4_trd_cnt)));	// 매도4단계우선호가건수
	PyTuple_SetItem(ret_tuple, 68, char_to_pylong(data->s_lvl_5_trd_cnt, sizeof(data->s_lvl_5_trd_cnt)));	// 매도5단계우선호가건수
	PyTuple_SetItem(ret_tuple, 69, PyUnicode_DecodeASCII(data->real_t_high_prc_sign, sizeof(data->real_t_high_prc_sign), error));	// 실시간상한가부호
	PyTuple_SetItem(ret_tuple, 70, char_to_pyfloat(data->real_t_high_prc, sizeof(data->real_t_high_prc), 3));	// 실시간상한가
	PyTuple_SetItem(ret_tuple, 71, PyUnicode_DecodeASCII(data->real_t_low_prc_sign, sizeof(data->real_t_low_prc_sign), error));	// 실시간하한가부호
	PyTuple_SetItem(ret_tuple, 72, char_to_pyfloat(data->real_t_low_prc, sizeof(data->real_t_low_prc), 3));	// 실시간하한가

	return ret_tuple;
}


// K200선물_종목마감
PyObject* parse_k200_fut_close_product(char* raw_data) {
	const char* error = NULL;
	K200_FUT_CLOSE_PRODUCT* data = (K200_FUT_CLOSE_PRODUCT*)raw_data;

	PyObject* ret_tuple = PyTuple_New(56);

	PyTuple_SetItem(ret_tuple, 0, PyUnicode_DecodeASCII(data->data_clsf, sizeof(data->data_clsf), error));	// DATA구분
	PyTuple_SetItem(ret_tuple, 1, PyUnicode_DecodeASCII(data->info_clsf, sizeof(data->info_clsf), error));	// 정보구분
	PyTuple_SetItem(ret_tuple, 2, PyUnicode_DecodeASCII(data->mrk_clsf, sizeof(data->mrk_clsf), error));	// 시장구분
	PyTuple_SetItem(ret_tuple, 3, PyUnicode_DecodeASCII(data->isin_clsf, sizeof(data->isin_clsf), error));	// 종목코드
	PyTuple_SetItem(ret_tuple, 4, char_to_pylong(data->seq, sizeof(data->seq)));	// 종목일련번호
	PyTuple_SetItem(ret_tuple, 5, PyUnicode_DecodeASCII(data->brd_id, sizeof(data->brd_id), error));	// 보드ID
	PyTuple_SetItem(ret_tuple, 6, PyUnicode_DecodeASCII(data->close_prc_sign, sizeof(data->close_prc_sign), error));	// 종가부호
	PyTuple_SetItem(ret_tuple, 7, char_to_pyfloat(data->close_prc, sizeof(data->close_prc), 3));	// 종가
	PyTuple_SetItem(ret_tuple, 8, PyUnicode_DecodeASCII(data->close_prc_code, sizeof(data->close_prc_code), error));	// 종가구분코드
	PyTuple_SetItem(ret_tuple, 9, char_to_pylong(data->accm_exe_q, sizeof(data->accm_exe_q)));	// 누적체결수량
	PyTuple_SetItem(ret_tuple, 10, char_to_pylong(data->accm_trd_amt, sizeof(data->accm_trd_amt)));	// 누적거래대금
	PyTuple_SetItem(ret_tuple, 11, PyUnicode_DecodeASCII(data->accm_block_trd_exe_q, sizeof(data->accm_block_trd_exe_q), error));	// 협의대량누적체결수량
	PyTuple_SetItem(ret_tuple, 12, char_to_pylong(data->total_l_limit_ord_q, sizeof(data->total_l_limit_ord_q)));	// 매수총호가잔량
	PyTuple_SetItem(ret_tuple, 13, PyUnicode_DecodeASCII(data->l_lvl_1_sign, sizeof(data->l_lvl_1_sign), error));	// 매수1단계부호
	PyTuple_SetItem(ret_tuple, 14, char_to_pyfloat(data->l_lvl_1_prc, sizeof(data->l_lvl_1_prc), 3));	// 매수1단계우선호가가격
	PyTuple_SetItem(ret_tuple, 15, char_to_pylong(data->l_lvl_1_q, sizeof(data->l_lvl_1_q)));	// 매수1단계우선호가잔량
	PyTuple_SetItem(ret_tuple, 16, PyUnicode_DecodeASCII(data->l_lvl_2_sign, sizeof(data->l_lvl_2_sign), error));	// 매수2단계부호
	PyTuple_SetItem(ret_tuple, 17, char_to_pyfloat(data->l_lvl_2_prc, sizeof(data->l_lvl_2_prc), 3));	// 매수2단계우선호가가격
	PyTuple_SetItem(ret_tuple, 18, char_to_pylong(data->l_lvl_2_q, sizeof(data->l_lvl_2_q)));	// 매수2단계우선호가잔량
	PyTuple_SetItem(ret_tuple, 19, PyUnicode_DecodeASCII(data->l_lvl_3_sign, sizeof(data->l_lvl_3_sign), error));	// 매수3단계부호
	PyTuple_SetItem(ret_tuple, 20, char_to_pyfloat(data->l_lvl_3_prc, sizeof(data->l_lvl_3_prc), 3));	// 매수3단계우선호가가격
	PyTuple_SetItem(ret_tuple, 21, char_to_pylong(data->l_lvl_3_q, sizeof(data->l_lvl_3_q)));	// 매수3단계우선호가잔량
	PyTuple_SetItem(ret_tuple, 22, PyUnicode_DecodeASCII(data->l_lvl_4_sign, sizeof(data->l_lvl_4_sign), error));	// 매수4단계부호
	PyTuple_SetItem(ret_tuple, 23, char_to_pyfloat(data->l_lvl_4_prc, sizeof(data->l_lvl_4_prc), 3));	// 매수4단계우선호가가격
	PyTuple_SetItem(ret_tuple, 24, char_to_pylong(data->l_lvl_4_q, sizeof(data->l_lvl_4_q)));	// 매수4단계우선호가잔량
	PyTuple_SetItem(ret_tuple, 25, PyUnicode_DecodeASCII(data->l_lvl_5_sign, sizeof(data->l_lvl_5_sign), error));	// 매수5단계부호
	PyTuple_SetItem(ret_tuple, 26, char_to_pyfloat(data->l_lvl_5_prc, sizeof(data->l_lvl_5_prc), 3));	// 매수5단계우선호가가격
	PyTuple_SetItem(ret_tuple, 27, char_to_pylong(data->l_lvl_5_q, sizeof(data->l_lvl_5_q)));	// 매수5단계우선호가잔량
	PyTuple_SetItem(ret_tuple, 28, char_to_pylong(data->total_s_limit_ord_q, sizeof(data->total_s_limit_ord_q)));	// 매도총호가잔량
	PyTuple_SetItem(ret_tuple, 29, PyUnicode_DecodeASCII(data->s_lvl_1_sign, sizeof(data->s_lvl_1_sign), error));	// 매도1단계부호
	PyTuple_SetItem(ret_tuple, 30, char_to_pyfloat(data->s_lvl_1_prc, sizeof(data->s_lvl_1_prc), 3));	// 매도1단계우선호가가격
	PyTuple_SetItem(ret_tuple, 31, char_to_pylong(data->s_lvl_1_q, sizeof(data->s_lvl_1_q)));	// 매도1단계우선호가잔량
	PyTuple_SetItem(ret_tuple, 32, PyUnicode_DecodeASCII(data->s_lvl_2_sign, sizeof(data->s_lvl_2_sign), error));	// 매도2단계부호
	PyTuple_SetItem(ret_tuple, 33, char_to_pyfloat(data->s_lvl_2_prc, sizeof(data->s_lvl_2_prc), 3));	// 매도2단계우선호가가격
	PyTuple_SetItem(ret_tuple, 34, char_to_pylong(data->s_lvl_2_q, sizeof(data->s_lvl_2_q)));	// 매도2단계우선호가잔량
	PyTuple_SetItem(ret_tuple, 35, PyUnicode_DecodeASCII(data->s_lvl_3_sign, sizeof(data->s_lvl_3_sign), error));	// 매도3단계부호
	PyTuple_SetItem(ret_tuple, 36, char_to_pyfloat(data->s_lvl_3_prc, sizeof(data->s_lvl_3_prc), 3));	// 매도3단계우선호가가격
	PyTuple_SetItem(ret_tuple, 37, char_to_pylong(data->s_lvl_3_q, sizeof(data->s_lvl_3_q)));	// 매도3단계우선호가잔량
	PyTuple_SetItem(ret_tuple, 38, PyUnicode_DecodeASCII(data->s_lvl_4_sign, sizeof(data->s_lvl_4_sign), error));	// 매도4단계부호
	PyTuple_SetItem(ret_tuple, 39, char_to_pyfloat(data->s_lvl_4_prc, sizeof(data->s_lvl_4_prc), 3));	// 매도4단계우선호가가격
	PyTuple_SetItem(ret_tuple, 40, char_to_pylong(data->s_lvl_4_q, sizeof(data->s_lvl_4_q)));	// 매도4단계우선호가잔량
	PyTuple_SetItem(ret_tuple, 41, PyUnicode_DecodeASCII(data->s_lvl_5_sign, sizeof(data->s_lvl_5_sign), error));	// 매도5단계부호
	PyTuple_SetItem(ret_tuple, 42, char_to_pyfloat(data->s_lvl_5_prc, sizeof(data->s_lvl_5_prc), 3));	// 매도5단계우선호가가격
	PyTuple_SetItem(ret_tuple, 43, char_to_pylong(data->s_lvl_5_q, sizeof(data->s_lvl_5_q)));	// 매도5단계우선호가잔량
	PyTuple_SetItem(ret_tuple, 44, char_to_pylong(data->total_l_trd_cnt, sizeof(data->total_l_trd_cnt)));	// 매수유효호가건수
	PyTuple_SetItem(ret_tuple, 45, char_to_pylong(data->l_lvl_1_trd_cnt, sizeof(data->l_lvl_1_trd_cnt)));	// 매수1단계우선호가건수
	PyTuple_SetItem(ret_tuple, 46, char_to_pylong(data->l_lvl_2_trd_cnt, sizeof(data->l_lvl_2_trd_cnt)));	// 매수2단계우선호가건수
	PyTuple_SetItem(ret_tuple, 47, char_to_pylong(data->l_lvl_3_trd_cnt, sizeof(data->l_lvl_3_trd_cnt)));	// 매수3단계우선호가건수
	PyTuple_SetItem(ret_tuple, 48, char_to_pylong(data->l_lvl_4_trd_cnt, sizeof(data->l_lvl_4_trd_cnt)));	// 매수4단계우선호가건수
	PyTuple_SetItem(ret_tuple, 49, char_to_pylong(data->l_lvl_5_trd_cnt, sizeof(data->l_lvl_5_trd_cnt)));	// 매수5단계우선호가건수
	PyTuple_SetItem(ret_tuple, 50, char_to_pylong(data->total_s_trd_cnt, sizeof(data->total_s_trd_cnt)));	// 매도유효호가건수
	PyTuple_SetItem(ret_tuple, 51, char_to_pylong(data->s_lvl_1_trd_cnt, sizeof(data->s_lvl_1_trd_cnt)));	// 매도1단계우선호가건수
	PyTuple_SetItem(ret_tuple, 52, char_to_pylong(data->s_lvl_2_trd_cnt, sizeof(data->s_lvl_2_trd_cnt)));	// 매도2단계우선호가건수
	PyTuple_SetItem(ret_tuple, 53, char_to_pylong(data->s_lvl_3_trd_cnt, sizeof(data->s_lvl_3_trd_cnt)));	// 매도3단계우선호가건수
	PyTuple_SetItem(ret_tuple, 54, char_to_pylong(data->s_lvl_4_trd_cnt, sizeof(data->s_lvl_4_trd_cnt)));	// 매도4단계우선호가건수
	PyTuple_SetItem(ret_tuple, 55, char_to_pylong(data->s_lvl_5_trd_cnt, sizeof(data->s_lvl_5_trd_cnt)));	// 매도5단계우선호가건수

	return ret_tuple;
}


// K200선물_종목정보 데이터
PyObject* parse_k200_fut_prd_info_data(char* raw_data) {
	const char* ENCODING_EUCKR = "euc-kr";
	const char* error = NULL;
	K200_FUT_PRD_INFO_DATA* data = (K200_FUT_PRD_INFO_DATA*)raw_data;

	PyObject* ret_tuple = PyTuple_New(130);

	PyTuple_SetItem(ret_tuple, 0, PyUnicode_DecodeASCII(data->data_clsf, sizeof(data->data_clsf), error));	// DATA구분
	PyTuple_SetItem(ret_tuple, 1, PyUnicode_DecodeASCII(data->info_clsf, sizeof(data->info_clsf), error));	// 정보구분
	PyTuple_SetItem(ret_tuple, 2, PyUnicode_DecodeASCII(data->mrk_clsf, sizeof(data->mrk_clsf), error));	// 시장구분
	PyTuple_SetItem(ret_tuple, 3, char_to_pylong(data->prd_cnt, sizeof(data->prd_cnt)));	// 종목수
	PyTuple_SetItem(ret_tuple, 4, PyUnicode_DecodeASCII(data->trd_date, sizeof(data->trd_date), error));	// 영업일자(입회일자)
	PyTuple_SetItem(ret_tuple, 5, PyUnicode_DecodeASCII(data->isin_clsf, sizeof(data->isin_clsf), error));	// 종목코드
	PyTuple_SetItem(ret_tuple, 6, char_to_pylong(data->seq, sizeof(data->seq)));	// 종목SEQ
	PyTuple_SetItem(ret_tuple, 7, PyUnicode_DecodeASCII(data->prd_id, sizeof(data->prd_id), error));	// 상품ID
	PyTuple_SetItem(ret_tuple, 8, PyUnicode_DecodeASCII(data->sh_prd_code, sizeof(data->sh_prd_code), error));	// 종목단축코드
	PyTuple_SetItem(ret_tuple, 9, PyUnicode_Decode(data->prd_name_kor, sizeof(data->prd_name_kor), ENCODING_EUCKR, error));	// 종목한글명
	PyTuple_SetItem(ret_tuple, 10, PyUnicode_Decode(data->sh_prd_name_kor, sizeof(data->sh_prd_name_kor), ENCODING_EUCKR, error));	// 종목한글약명
	PyTuple_SetItem(ret_tuple, 11, PyUnicode_DecodeASCII(data->prd_name_eng, sizeof(data->prd_name_eng), error));	// 종목영문명
	PyTuple_SetItem(ret_tuple, 12, PyUnicode_DecodeASCII(data->sh_prd_name_eng, sizeof(data->sh_prd_name_eng), error));	// 종목영문약명
	PyTuple_SetItem(ret_tuple, 13, PyUnicode_DecodeASCII(data->listing_date, sizeof(data->listing_date), error));	// 상장일자
	PyTuple_SetItem(ret_tuple, 14, PyUnicode_DecodeASCII(data->de_listing_date, sizeof(data->de_listing_date), error));	// 상장폐지일자
	PyTuple_SetItem(ret_tuple, 15, PyUnicode_DecodeASCII(data->spread_clsf_code, sizeof(data->spread_clsf_code), error));	// 스프레드기준종목구분코드
	PyTuple_SetItem(ret_tuple, 16, PyUnicode_DecodeASCII(data->final_sett_code, sizeof(data->final_sett_code), error));	// 최종결제방법코드
	PyTuple_SetItem(ret_tuple, 17, PyUnicode_DecodeASCII(data->prc_limit_exp_dir, sizeof(data->prc_limit_exp_dir), error));	// 가격제한확대적용방향코드
	PyTuple_SetItem(ret_tuple, 18, char_to_pylong(data->prc_limit_final_stg, sizeof(data->prc_limit_final_stg)));	// 가격제한최종단계
	PyTuple_SetItem(ret_tuple, 19, PyUnicode_DecodeASCII(data->prc_limit_stg_1_hgh_sign, sizeof(data->prc_limit_stg_1_hgh_sign), error));	// 가격제한1단계SIGN부호
	PyTuple_SetItem(ret_tuple, 20, char_to_pyfloat(data->prc_limit_stg_1_high_prc, sizeof(data->prc_limit_stg_1_high_prc), 10));	// 가격제한1단계상한가
	PyTuple_SetItem(ret_tuple, 21, PyUnicode_DecodeASCII(data->prc_limit_stg_1_low_sign, sizeof(data->prc_limit_stg_1_low_sign), error));	// 가격제한1단계SIGN부호
	PyTuple_SetItem(ret_tuple, 22, char_to_pyfloat(data->prc_limit_stg_1_low_prc, sizeof(data->prc_limit_stg_1_low_prc), 10));	// 가격제한1단계하한가
	PyTuple_SetItem(ret_tuple, 23, PyUnicode_DecodeASCII(data->prc_limit_stg_2_high_sign, sizeof(data->prc_limit_stg_2_high_sign), error));	// 가격제한2단계SIGN부호
	PyTuple_SetItem(ret_tuple, 24, char_to_pyfloat(data->prc_limit_stg_2_high_prc, sizeof(data->prc_limit_stg_2_high_prc), 10));	// 가격제한2단계상한가
	PyTuple_SetItem(ret_tuple, 25, PyUnicode_DecodeASCII(data->prc_limit_stg_2_low_sign, sizeof(data->prc_limit_stg_2_low_sign), error));	// 가격제한2단계SIGN부호
	PyTuple_SetItem(ret_tuple, 26, char_to_pyfloat(data->prc_limit_stg_2_low_prc, sizeof(data->prc_limit_stg_2_low_prc), 10));	// 가격제한2단계하한가
	PyTuple_SetItem(ret_tuple, 27, PyUnicode_DecodeASCII(data->prc_limit_stg_3_high_sign, sizeof(data->prc_limit_stg_3_high_sign), error));	// 가격제한3단계SIGN부호
	PyTuple_SetItem(ret_tuple, 28, char_to_pyfloat(data->prc_limit_stg_3_high_prc, sizeof(data->prc_limit_stg_3_high_prc), 10));	// 가격제한3단계상한가
	PyTuple_SetItem(ret_tuple, 29, PyUnicode_DecodeASCII(data->prc_limit_stg_3_low_sign, sizeof(data->prc_limit_stg_3_low_sign), error));	// 가격제한3단계SIGN부호
	PyTuple_SetItem(ret_tuple, 30, char_to_pyfloat(data->prc_limit_stg_3_low_prc, sizeof(data->prc_limit_stg_3_low_prc), 10));	// 가격제한3단계하한가
	PyTuple_SetItem(ret_tuple, 31, char_to_pyfloat(data->stand_prc, sizeof(data->stand_prc), 10));	// 기준가
	PyTuple_SetItem(ret_tuple, 32, PyUnicode_DecodeASCII(data->under_asset_id, sizeof(data->under_asset_id), error));	// 기초자산ID
	PyTuple_SetItem(ret_tuple, 33, PyUnicode_DecodeASCII(data->opt_type_code, sizeof(data->opt_type_code), error));	// 권리행사유형코드
	PyTuple_SetItem(ret_tuple, 34, PyUnicode_DecodeASCII(data->spread_str_code, sizeof(data->spread_str_code), error));	// 스프레드구성코드
	PyTuple_SetItem(ret_tuple, 35, PyUnicode_DecodeASCII(data->spread_prd_code_1, sizeof(data->spread_prd_code_1), error));	// 스프레드구성종목코드1
	PyTuple_SetItem(ret_tuple, 36, PyUnicode_DecodeASCII(data->spread_prd_code_2, sizeof(data->spread_prd_code_2), error));	// 스프레드구성종목코드2
	PyTuple_SetItem(ret_tuple, 37, PyUnicode_DecodeASCII(data->last_trading_date, sizeof(data->last_trading_date), error));	// 최종거래일자
	PyTuple_SetItem(ret_tuple, 38, PyUnicode_DecodeASCII(data->final_sett_date, sizeof(data->final_sett_date), error));	// 최종결제일자
	PyTuple_SetItem(ret_tuple, 39, char_to_pylong(data->cont_month_nbr, sizeof(data->cont_month_nbr)));	// 결제월번호
	PyTuple_SetItem(ret_tuple, 40, PyUnicode_DecodeASCII(data->maturity_date, sizeof(data->maturity_date), error));	// 만기일자
	PyTuple_SetItem(ret_tuple, 41, char_to_pyfloat(data->exe_prc, sizeof(data->exe_prc), 9));	// 행사가격
	PyTuple_SetItem(ret_tuple, 42, PyUnicode_DecodeASCII(data->adjust_clsf_code, sizeof(data->adjust_clsf_code), error));	// 조정구분코드
	PyTuple_SetItem(ret_tuple, 43, char_to_pyfloat(data->prd_unit, sizeof(data->prd_unit), 9));	// 거래단위
	PyTuple_SetItem(ret_tuple, 44, char_to_pyfloat(data->multiplier, sizeof(data->multiplier), 13));	// 거래승수
	PyTuple_SetItem(ret_tuple, 45, PyUnicode_DecodeASCII(data->mrk_cnst_code, sizeof(data->mrk_cnst_code), error));	// 시장조성구분코드
	PyTuple_SetItem(ret_tuple, 46, PyUnicode_DecodeASCII(data->listing_type_code, sizeof(data->listing_type_code), error));	// 상장유형코드
	PyTuple_SetItem(ret_tuple, 47, char_to_pyfloat(data->atm_prc, sizeof(data->atm_prc), 10));	// 등가격
	PyTuple_SetItem(ret_tuple, 48, PyUnicode_DecodeASCII(data->adj_reason_code, sizeof(data->adj_reason_code), error));	// 조정사유코드
	PyTuple_SetItem(ret_tuple, 49, PyUnicode_DecodeASCII(data->under_asset_prd_code, sizeof(data->under_asset_prd_code), error));	// 기초자산종목코드
	PyTuple_SetItem(ret_tuple, 50, char_to_pyfloat(data->under_asset_close_prc, sizeof(data->under_asset_close_prc), 10));	// 기초자산종가
	PyTuple_SetItem(ret_tuple, 51, char_to_pylong(data->left_until_maturity, sizeof(data->left_until_maturity)));	// 잔존일수
	PyTuple_SetItem(ret_tuple, 52, char_to_pyfloat(data->adj_std_prc, sizeof(data->adj_std_prc), 9));	// 조정기준가격
	PyTuple_SetItem(ret_tuple, 53, PyUnicode_DecodeASCII(data->std_prc_clsf_code, sizeof(data->std_prc_clsf_code), error));	// 기준가격구분코드
	PyTuple_SetItem(ret_tuple, 54, PyUnicode_DecodeASCII(data->trd_std_prc_clsf_code, sizeof(data->trd_std_prc_clsf_code), error));	// 매매용기준가격구분코드
	PyTuple_SetItem(ret_tuple, 55, PyUnicode_DecodeASCII(data->yest_adj_close_prc_sign, sizeof(data->yest_adj_close_prc_sign), error));	// SIGN부호
	PyTuple_SetItem(ret_tuple, 56, char_to_pyfloat(data->yest_adj_close_prc, sizeof(data->yest_adj_close_prc), 9));	// 전일조정종가
	PyTuple_SetItem(ret_tuple, 57, PyUnicode_DecodeASCII(data->block_trd_clsf, sizeof(data->block_trd_clsf), error));	// 협의대량매매대상여부
	PyTuple_SetItem(ret_tuple, 58, char_to_pyfloat(data->yest_mrg_std_prc, sizeof(data->yest_mrg_std_prc), 9));	// 전일증거금기준가격
	PyTuple_SetItem(ret_tuple, 59, PyUnicode_DecodeASCII(data->yest_mrg_std_prc_clsf_code, sizeof(data->yest_mrg_std_prc_clsf_code), error));	// 전일증거금기준가격구분코드
	PyTuple_SetItem(ret_tuple, 60, char_to_pyfloat(data->sett_theory_prc, sizeof(data->sett_theory_prc), 9));	// 정산이론가격
	PyTuple_SetItem(ret_tuple, 61, char_to_pyfloat(data->std_theory_prc, sizeof(data->std_theory_prc), 9));	// 기준이론가격
	PyTuple_SetItem(ret_tuple, 62, char_to_pyfloat(data->yest_sett_prc, sizeof(data->yest_sett_prc), 9));	// 전일정산가격
	PyTuple_SetItem(ret_tuple, 63, PyUnicode_DecodeASCII(data->halt_trd_clsf, sizeof(data->halt_trd_clsf), error));	// 거래정지여부
	PyTuple_SetItem(ret_tuple, 64, char_to_pyfloat(data->ft_cb_high_prc, sizeof(data->ft_cb_high_prc), 10));	// 선물Circuit_Breakers상한가
	PyTuple_SetItem(ret_tuple, 65, char_to_pyfloat(data->ft_cb_low_prc, sizeof(data->ft_cb_low_prc), 10));	// 선물Circuit_Breakers하한가
	PyTuple_SetItem(ret_tuple, 66, char_to_pyfloat(data->check_exe_prc, sizeof(data->check_exe_prc), 9));	// 조회용행사가격
	PyTuple_SetItem(ret_tuple, 67, PyUnicode_DecodeASCII(data->atm_clsf, sizeof(data->atm_clsf), error));	// ATM구분코드
	PyTuple_SetItem(ret_tuple, 68, PyUnicode_DecodeASCII(data->last_trading_clsf, sizeof(data->last_trading_clsf), error));	// 최종거래일여부
	PyTuple_SetItem(ret_tuple, 69, char_to_pyfloat(data->ex_divid_aft_value, sizeof(data->ex_divid_aft_value), 9));	// 배당락후배당가치
	PyTuple_SetItem(ret_tuple, 70, PyUnicode_DecodeASCII(data->yest_close_prc_sign, sizeof(data->yest_close_prc_sign), error));	// SIGN부호
	PyTuple_SetItem(ret_tuple, 71, char_to_pyfloat(data->yest_close_prc, sizeof(data->yest_close_prc), 10));	// 전일종가
	PyTuple_SetItem(ret_tuple, 72, PyUnicode_DecodeASCII(data->yest_close_prc_clsf, sizeof(data->yest_close_prc_clsf), error));	// 전일종가구분코드
	PyTuple_SetItem(ret_tuple, 73, PyUnicode_DecodeASCII(data->yest_init_prc_sign, sizeof(data->yest_init_prc_sign), error));	// SIGN부호
	PyTuple_SetItem(ret_tuple, 74, char_to_pyfloat(data->yest_init_prc, sizeof(data->yest_init_prc), 10));	// 전일시가
	PyTuple_SetItem(ret_tuple, 75, PyUnicode_DecodeASCII(data->yest_high_prc_sign, sizeof(data->yest_high_prc_sign), error));	// SIGN부호
	PyTuple_SetItem(ret_tuple, 76, char_to_pyfloat(data->yest_high_pric, sizeof(data->yest_high_pric), 10));	// 전일고가
	PyTuple_SetItem(ret_tuple, 77, PyUnicode_DecodeASCII(data->yest_low_prc_sign, sizeof(data->yest_low_prc_sign), error));	// SIGN부호
	PyTuple_SetItem(ret_tuple, 78, char_to_pyfloat(data->yest_low_prc, sizeof(data->yest_low_prc), 10));	// 전일저가
	PyTuple_SetItem(ret_tuple, 79, PyUnicode_DecodeASCII(data->yest_first_exe_date, sizeof(data->yest_first_exe_date), error));	// 최초체결일자
	PyTuple_SetItem(ret_tuple, 80, PyUnicode_DecodeASCII(data->yest_last_exe_time, sizeof(data->yest_last_exe_time), error));	// 전일최종체결시각
	PyTuple_SetItem(ret_tuple, 81, PyUnicode_DecodeASCII(data->yest_sett_prc_clsf, sizeof(data->yest_sett_prc_clsf), error));	// 전일정산가격구분
	PyTuple_SetItem(ret_tuple, 82, PyUnicode_DecodeASCII(data->sett_prc_theory_prc_diff_pctg_sign, sizeof(data->sett_prc_theory_prc_diff_pctg_sign), error));	// SIGN부호
	PyTuple_SetItem(ret_tuple, 83, char_to_pyfloat(data->sett_prc_theory_prc_diff_pctg, sizeof(data->sett_prc_theory_prc_diff_pctg), 6));	// 정산가격이론가격괴리율
	PyTuple_SetItem(ret_tuple, 84, char_to_pylong(data->yest_open_interest_q, sizeof(data->yest_open_interest_q)));	// 전일미결제약정수량
	PyTuple_SetItem(ret_tuple, 85, PyUnicode_DecodeASCII(data->yest_s_limit_ord_prc_sign, sizeof(data->yest_s_limit_ord_prc_sign), error));	// SIGN부호
	PyTuple_SetItem(ret_tuple, 86, char_to_pyfloat(data->yest_s_limit_ord_prc, sizeof(data->yest_s_limit_ord_prc), 10));	// 전일매도우선호가가격
	PyTuple_SetItem(ret_tuple, 87, PyUnicode_DecodeASCII(data->yest_l_limit_ord_prc_sign, sizeof(data->yest_l_limit_ord_prc_sign), error));	// SIGN부호
	PyTuple_SetItem(ret_tuple, 88, char_to_pyfloat(data->yest_l_limit_ord_prc, sizeof(data->yest_l_limit_ord_prc), 10));	// 전일매수우선호가가격
	PyTuple_SetItem(ret_tuple, 89, char_to_pyfloat(data->implied_vol, sizeof(data->implied_vol), 6));	// 내재변동성
	PyTuple_SetItem(ret_tuple, 90, PyUnicode_DecodeASCII(data->listed_high_prc_sign, sizeof(data->listed_high_prc_sign), error));	// SIGN부호
	PyTuple_SetItem(ret_tuple, 91, char_to_pyfloat(data->listed_high_prc, sizeof(data->listed_high_prc), 10));	// 상장중최고가
	PyTuple_SetItem(ret_tuple, 92, PyUnicode_DecodeASCII(data->listed_low_prc_sign, sizeof(data->listed_low_prc_sign), error));	// SIGN부호
	PyTuple_SetItem(ret_tuple, 93, char_to_pyfloat(data->listed_low_prc, sizeof(data->listed_low_prc), 10));	// 상장중최저가
	PyTuple_SetItem(ret_tuple, 94, PyUnicode_DecodeASCII(data->year_high_prc_sign, sizeof(data->year_high_prc_sign), error));	// SIGN부호
	PyTuple_SetItem(ret_tuple, 95, char_to_pyfloat(data->year_high_prc, sizeof(data->year_high_prc), 10));	// 연중최고가
	PyTuple_SetItem(ret_tuple, 96, PyUnicode_DecodeASCII(data->year_low_prc_sign, sizeof(data->year_low_prc_sign), error));	// SIGN부호
	PyTuple_SetItem(ret_tuple, 97, char_to_pyfloat(data->year_low_prc, sizeof(data->year_low_prc), 10));	// 연중최저가
	PyTuple_SetItem(ret_tuple, 98, PyUnicode_DecodeASCII(data->listed_high_prc_date, sizeof(data->listed_high_prc_date), error));	// 상장중최고가일자
	PyTuple_SetItem(ret_tuple, 99, PyUnicode_DecodeASCII(data->listed_low_prc_date, sizeof(data->listed_low_prc_date), error));	// 상장중최저가일자
	PyTuple_SetItem(ret_tuple, 100, PyUnicode_DecodeASCII(data->year_high_prc_date, sizeof(data->year_high_prc_date), error));	// 연중최고가일자
	PyTuple_SetItem(ret_tuple, 101, PyUnicode_DecodeASCII(data->year_low_prc_date, sizeof(data->year_low_prc_date), error));	// 연중최저가일자
	PyTuple_SetItem(ret_tuple, 102, char_to_pylong(data->year_std_date, sizeof(data->year_std_date)));	// 연간기준일수
	PyTuple_SetItem(ret_tuple, 103, char_to_pylong(data->month_trd_date, sizeof(data->month_trd_date)));	// 월간거래일수
	PyTuple_SetItem(ret_tuple, 104, char_to_pylong(data->year_trd_date, sizeof(data->year_trd_date)));	// 연간거래일수
	PyTuple_SetItem(ret_tuple, 105, char_to_pylong(data->yest_exe_trd_cnt , sizeof(data->yest_exe_trd_cnt )));	// 전일체결건수
	PyTuple_SetItem(ret_tuple, 106, char_to_pylong(data->yest_exe_q, sizeof(data->yest_exe_q)));	// 전일체결수량
	PyTuple_SetItem(ret_tuple, 107, char_to_pylong(data->yest_trd_amt, sizeof(data->yest_trd_amt)));	// 전일거래대금
	PyTuple_SetItem(ret_tuple, 108, char_to_pylong(data->yest_block_trd_exe_q, sizeof(data->yest_block_trd_exe_q)));	// 전일협의대량합산체결수량
	PyTuple_SetItem(ret_tuple, 109, char_to_pylong(data->yest_block_trd_total_amt, sizeof(data->yest_block_trd_total_amt)));	// 전일협의대량합산거래대금
	PyTuple_SetItem(ret_tuple, 110, char_to_pyfloat(data->cd_rate, sizeof(data->cd_rate), 3));	// CD금리
	PyTuple_SetItem(ret_tuple, 111, char_to_pylong(data->open_interest_q, sizeof(data->open_interest_q)));	// 미결제한도수량
	PyTuple_SetItem(ret_tuple, 112, PyUnicode_DecodeASCII(data->product_cat, sizeof(data->product_cat), error));	// 소속 상품군
	PyTuple_SetItem(ret_tuple, 113, char_to_pyfloat(data->product_cat_off_pctg, sizeof(data->product_cat_off_pctg), 7));	// 상품군 옵셋율
	PyTuple_SetItem(ret_tuple, 114, char_to_pylong(data->limit_ord_clsf_code, sizeof(data->limit_ord_clsf_code)));	// 지정가호가조건구분코드
	PyTuple_SetItem(ret_tuple, 115, char_to_pylong(data->mrk_ord_clsf_code, sizeof(data->mrk_ord_clsf_code)));	// 시장가호가조건구분코드
	PyTuple_SetItem(ret_tuple, 116, char_to_pylong(data->cond_limit_ord_clsf_code, sizeof(data->cond_limit_ord_clsf_code)));	// 조건부지정가호가조건구분코드
	PyTuple_SetItem(ret_tuple, 117, char_to_pylong(data->best_limit_ord_clsf_code, sizeof(data->best_limit_ord_clsf_code)));	// 최유리지정가호가조건구분코드
	PyTuple_SetItem(ret_tuple, 118, PyUnicode_DecodeASCII(data->efp_clsf, sizeof(data->efp_clsf), error));	// EFP거래대상여부
	PyTuple_SetItem(ret_tuple, 119, PyUnicode_DecodeASCII(data->flex_clsf, sizeof(data->flex_clsf), error));	// FLEX거래대상여부
	PyTuple_SetItem(ret_tuple, 120, char_to_pylong(data->yest_efp_exe_q, sizeof(data->yest_efp_exe_q)));	// 전일EFP체결수량
	PyTuple_SetItem(ret_tuple, 121, char_to_pylong(data->yest_efp_trd_amount, sizeof(data->yest_efp_trd_amount)));	// 전일EFP거래대금
	PyTuple_SetItem(ret_tuple, 122, PyUnicode_DecodeASCII(data->mkr_close_clsf, sizeof(data->mkr_close_clsf), error));	// 휴장여부
	PyTuple_SetItem(ret_tuple, 123, PyUnicode_DecodeASCII(data->real_t_prc_limit_clsf, sizeof(data->real_t_prc_limit_clsf), error));	// 실시간가격제한여부
	PyTuple_SetItem(ret_tuple, 124, PyUnicode_DecodeASCII(data->real_t_high_price_gap_sign, sizeof(data->real_t_high_price_gap_sign), error));	// SIGN부호
	PyTuple_SetItem(ret_tuple, 125, char_to_pyfloat(data->real_t_high_price_gap, sizeof(data->real_t_high_price_gap), 10));	// 실시간상한가간격
	PyTuple_SetItem(ret_tuple, 126, PyUnicode_DecodeASCII(data->real_t_low_price_gap_sign, sizeof(data->real_t_low_price_gap_sign), error));	// SIGN부호
	PyTuple_SetItem(ret_tuple, 127, char_to_pyfloat(data->real_t_low_price_gap, sizeof(data->real_t_low_price_gap), 10));	// 실시간하한가간격
	PyTuple_SetItem(ret_tuple, 128, PyUnicode_DecodeASCII(data->under_ass_mrk_id, sizeof(data->under_ass_mrk_id), error));	// 기초자산시장ID
	PyTuple_SetItem(ret_tuple, 129, PyUnicode_DecodeASCII(data->filter, sizeof(data->filter), error));	// Filler

	return ret_tuple;
}
