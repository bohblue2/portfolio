#ifndef _FUTDF_H_
#define _FUTDF_H_

#include "zconf.h"

//  G7014 : K200선물_체결_우선호가
typedef struct _DFK200_FUT_EXEC_LIMIT_ORD {
	char    data_clsf           [ 2+1];	//X char    data_clsf       [2];	// DATA구분,G7
	char    info_clsf           [ 2+1];	//X char    info_clsf       [2];	// 정보구분,01:KOSPI200지수선물
	char    mrk_clsf            [ 1+1];	//X char    mrk_clsf        [1];	// 시장구분,4
	char    isin_clsf           [12+1];	//X char    isin_clsf       [12];	// 종목코드
	int     seq                       ;	//9 char    seq             [2];	// 종목일련번호
	char    brd_id              [ 2+1];	//X char    brd_id          [2];	// 보드ID,코드값모음참조
	char    cur_prc_sign        [ 1+1];	//X char    cur_prc_sign    [1];	// 현재가격부호
	double  cur_price                 ;	//9 char    cur_price       [5];	// 현재가격,예) 999.99
	int     exe_q                     ;	//9 char    exe_q           [6];	// 체결수량
	char    ss_id               [ 2+1];	//X char    ss_id           [2];	// 세션ID,코드값모음참조
	char    exe_t               [ 8+1];	//X char    exe_t           [8];	// 체결시각
	double  rct_prd_prc               ;	//9 char    rct_prd_prc     [5];	// 최근월물의제약정가격,예) 999.99
	double  nxt_prd_prc               ;	//9 char    nxt_prd_prc     [5];	// 원월물의제약정가격,예) 999.99
	char    init_prc_sign       [ 1+1];	//X char    init_prc_sign   [1];	// 시가부호
	double  init_prc                  ;	//9 char    init_prc        [5];	// 시가,예) 999.99
	char    high_prc_sign       [ 1+1];	//X char    high_prc_sign   [1];	// 고가부호
	double  high_prc                  ;	//9 char    high_prc        [5];	// 고가,예) 999.99
	char    low_prc_sign        [ 1+1];	//X char    low_prc_sign    [1];	// 저가부호
	double  low_prc                   ;	//9 char    low_prc         [5];	// 저가,예) 999.99
	char    pri_prc_sign        [ 1+1];	//X char    pri_prc_sign    [1];	// 직전가격부호
	double  pri_prc                   ; //9 char    pri_prc         [5];	// 직전가격,예) 999.99
	int     accm_exe_q                ; //9 char    accm_exe_q      [7];	// 누적체결수량
	double  accm_trd_amt              ; //9 char    accm_trd_amt    [12];	// 누적거래대금,단위:천원
	int     accm_block_trd_exe_q      ; //9 char    accm_block_trd_exe_q[7];	// 협의대량누적체결수량,미제공(Filler)
	char    l_or_s              [ 1+1];	//X char    l_or_s          [1];	// 최종매도매수구분코드,1:매도,2:매수(최종으로 들어온 호가의 매도매수구분값)
	int     total_l_limit_ord_q       ;	//9 char    total_l_limit_ord_q[6];	// 매수총호가잔량
	char    l_lvl_1_sign        [ 1+1];	//X char    l_lvl_1_sign    [1];	// 매수1단계부호
	double  l_lvl_1_prc               ;	//9 char    l_lvl_1_prc     [5];	// 매수1단계우선호가가격,예) 999.99
	int     l_lvl_1_q                 ;	//9 char    l_lvl_1_q       [6];	// 매수1단계우선호가잔량
	char    l_lvl_2_sign        [ 1+1];	//X char    l_lvl_2_sign    [1];	// 매수2단계부호
	double  l_lvl_2_prc               ;	//9 char    l_lvl_2_prc     [5];	// 매수2단계우선호가가격,예) 999.99
	int     l_lvl_2_q                 ;	//9 char    l_lvl_2_q       [6];	// 매수2단계우선호가잔량
	char    l_lvl_3_sign        [ 1+1];	//X char    l_lvl_3_sign    [1];	// 매수3단계부호
	double  l_lvl_3_prc               ;	//9 char    l_lvl_3_prc     [5];	// 매수3단계우선호가가격,예) 999.99
	int     l_lvl_3_q                 ;	//9 char    l_lvl_3_q       [6];	// 매수3단계우선호가잔량
	char    l_lvl_4_sign        [ 1+1];	//X char    l_lvl_4_sign    [1];	// 매수4단계부호
	double  l_lvl_4_prc               ;	//9 char    l_lvl_4_prc     [5];	// 매수4단계우선호가가격,예) 999.99
	int     l_lvl_4_q                 ;	//9 char    l_lvl_4_q       [6];	// 매수4단계우선호가잔량
	char    l_lvl_5_sign        [ 1+1];	//X char    l_lvl_5_sign    [1];	// 매수5단계부호
	double  l_lvl_5_prc               ;	//9 char    l_lvl_5_prc     [5];	// 매수5단계우선호가가격,예) 999.99
	int     l_lvl_5_q                 ;	//9 char    l_lvl_5_q       [6];	// 매수5단계우선호가잔량
	int     total_s_limit_ord_q       ;	//9 char    total_s_limit_ord_q[6];	// 매도총호가잔량
	char    s_lvl_1_sign        [ 1+1];	//X char    s_lvl_1_sign    [1];	// 매도1단계부호
	double  s_lvl_1_prc               ;	//9 char    s_lvl_1_prc     [5];	// 매도1단계우선호가가격,예) 999.99
	int     s_lvl_1_q                 ;	//9 char    s_lvl_1_q       [6];	// 매도1단계우선호가잔량
	char    s_lvl_2_sign        [ 1+1];	//X char    s_lvl_2_sign    [1];	// 매도2단계부호
	double  s_lvl_2_prc               ;	//9 char    s_lvl_2_prc     [5];	// 매도2단계우선호가가격,예) 999.99
	int     s_lvl_2_q                 ;	//9 char    s_lvl_2_q       [6];	// 매도2단계우선호가잔량
	char    s_lvl_3_sign        [ 1+1];	//X char    s_lvl_3_sign    [1];	// 매도3단계부호
	double  s_lvl_3_prc               ;	//9 char    s_lvl_3_prc     [5];	// 매도3단계우선호가가격,예) 999.99
	int     s_lvl_3_q                 ;	//9 char    s_lvl_3_q       [6];	// 매도3단계우선호가잔량
	char    s_lvl_4_sign        [ 1+1];	//X char    s_lvl_4_sign    [1];	// 매도4단계부호
	double  s_lvl_4_prc               ;	//9 char    s_lvl_4_prc     [5];	// 매도4단계우선호가가격,예) 999.99
	int     s_lvl_4_q                 ;	//9 char    s_lvl_4_q       [6];	// 매도4단계우선호가잔량
	char    s_lvl_5_sign        [ 1+1];	//X char    s_lvl_5_sign    [1];	// 매도5단계부호
	double  s_lvl_5_prc               ;	//9 char    s_lvl_5_prc     [5];	// 매도5단계우선호가가격,예) 999.99
	int     s_lvl_5_q                 ;	//9 char    s_lvl_5_q       [6];	// 매도5단계우선호가잔량
	int     total_l_trd_cnt           ;	//9 char    total_l_trd_cnt [5];	// 매수유효호가건수
	int     l_lvl_1_trd_cnt           ;	//9 char    l_lvl_1_trd_cnt [4];	// 매수1단계우선호가건수
	int     l_lvl_2_trd_cnt           ;	//9 char    l_lvl_2_trd_cnt [4];	// 매수2단계우선호가건수
	int     l_lvl_3_trd_cnt           ;	//9 char    l_lvl_3_trd_cnt [4];	// 매수3단계우선호가건수
	int     l_lvl_4_trd_cnt           ;	//9 char    l_lvl_4_trd_cnt [4];	// 매수4단계우선호가건수
	int     l_lvl_5_trd_cnt           ;	//9 char    l_lvl_5_trd_cnt [4];	// 매수5단계우선호가건수
	int     total_s_trd_cnt           ;	//9 char    total_s_trd_cnt [5];	// 매도유효호가건수
	int     s_lvl_1_trd_cnt           ;	//9 char    s_lvl_1_trd_cnt [4];	// 매도1단계우선호가건수
	int     s_lvl_2_trd_cnt           ;	//9 char    s_lvl_2_trd_cnt [4];	// 매도2단계우선호가건수
	int     s_lvl_3_trd_cnt           ;	//9 char    s_lvl_3_trd_cnt [4];	// 매도3단계우선호가건수
	int     s_lvl_4_trd_cnt           ;	//9 char    s_lvl_4_trd_cnt [4];	// 매도4단계우선호가건수
	int     s_lvl_5_trd_cnt           ;	//9 char    s_lvl_5_trd_cnt [4];	// 매도5단계우선호가건수
	char    real_t_high_prc_sign[ 1+1];//X char    real_t_high_prc_sign[1];	// 실시간상한가부호
	double  real_t_high_prc           ;	//9 char    real_t_high_prc [5];	// 실시간상한가,예) 999.99 개발가이드 참조
	char    real_t_low_prc_sign [ 1+1];	//X char    real_t_low_prc_sign[1];	// 실시간하한가부호
	double  real_t_low_prc            ;	//9 char    real_t_low_prc  [5];	// 실시간하한가,예) 999.99 개발가이드 참조
	char    ff                  [ 1+1];	//X char    ff              [1];	// End of Text, (0xFF)
} DFK200_FUT_EXEC_LIMIT_ORD;
    
#endif
