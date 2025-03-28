#ifndef _FUTPK_H_
#define _FUTPK_H_

#include "zconf.h"

#define TICK_CNT    10

typedef struct _proc_list
{
    char    id[6];
    int     (*AppProc)(char *buff);
    char    tname[30];
} PROC_LIST;

/* hader file 중복 문제 해결 */
#ifdef ZAPLST

int FutProcB6014(char *buff);
int FutProcA3014(char *buff);
int FutProcG7014(char *buff);

PROC_LIST AppList[] = {
{"B6014",     FutProcB6014, "K200_FUT_LIMIT_ORD"      },
{"G7014",     FutProcG7014, "K200_FUT_EXEC_LIMIT_ORD"   },
{"A3014",     FutProcA3014, "K200_FUT_EXEC"             },
};

#define AP_CNT	( sizeof(AppList)/sizeof(PROC_LIST))

#endif                    

//K200선물_체결	A3014	데이터 발생시마다 실시간 제공	117
typedef struct _PK_TICK {
    char ask_prc          [9 ];	// 매도호가1
	char bid_prc          [9 ];	// 매수호가1
	char ask_vol_rsd      [12];	// 매도호가 잔량1
	char bid_vol_rsd      [12];	// 매수호가 잔량1    
} PK_TICK; 

typedef struct _PK_TICKLP {
    char ask_prc          [9 ];	// 매도호가1
	char bid_prc          [9 ];	// 매수호가1
	char ask_vol_rsd      [12];	// 매도호가 잔량1
	char bid_vol_rsd      [12];	// 매수호가 잔량1  
	char lp_ask_vol_rsd   [12];	// LP 매도호가 잔량1
	char lp_bid_vol_rsd   [12];	// LP 매수호가 잔량1  
} PK_TICKLP; 

//  G7014 : K200선물_체결_우선호가
typedef struct _K200_FUT_EXEC_LIMIT_ORD {
	char data_clsf[2];	// DATA구분,G7
	char info_clsf[2];	// 정보구분,01:KOSPI200지수선물
	char mrk_clsf[1];	// 시장구분,4
	char isin_clsf[12];	// 종목코드
	char seq[2];	// 종목일련번호
	char brd_id[2];	// 보드ID,코드값모음참조
	char cur_prc_sign[1];	// 현재가격부호
	char cur_price[5];	// 현재가격,예) 999.99
	char exe_q[6];	// 체결수량
	char ss_id[2];	// 세션ID,코드값모음참조
	char exe_t[8];	// 체결시각
	char rct_prd_prc[5];	// 최근월물의제약정가격,예) 999.99
	char nxt_prd_prc[5];	// 원월물의제약정가격,예) 999.99
	char init_prc_sign[1];	// 시가부호
	char init_prc[5];	// 시가,예) 999.99
	char high_prc_sign[1];	// 고가부호
	char high_prc[5];	// 고가,예) 999.99
	char low_prc_sign[1];	// 저가부호
	char low_prc[5];	// 저가,예) 999.99
	char pri_prc_sign[1];	// 직전가격부호
	char pri_prc[5];	// 직전가격,예) 999.99
	char accm_exe_q[7];	// 누적체결수량
	char accm_trd_amt[12];	// 누적거래대금,단위:천원
	char accm_block_trd_exe_q[7];	// 협의대량누적체결수량,미제공(Filler)
	char l_or_s[1];	// 최종매도매수구분코드,1:매도,2:매수(최종으로 들어온 호가의 매도매수구분값)
	char total_l_limit_ord_q[6];	// 매수총호가잔량
	char l_lvl_1_sign[1];	// 매수1단계부호
	char l_lvl_1_prc[5];	// 매수1단계우선호가가격,예) 999.99
	char l_lvl_1_q[6];	// 매수1단계우선호가잔량
	char l_lvl_2_sign[1];	// 매수2단계부호
	char l_lvl_2_prc[5];	// 매수2단계우선호가가격,예) 999.99
	char l_lvl_2_q[6];	// 매수2단계우선호가잔량
	char l_lvl_3_sign[1];	// 매수3단계부호
	char l_lvl_3_prc[5];	// 매수3단계우선호가가격,예) 999.99
	char l_lvl_3_q[6];	// 매수3단계우선호가잔량
	char l_lvl_4_sign[1];	// 매수4단계부호
	char l_lvl_4_prc[5];	// 매수4단계우선호가가격,예) 999.99
	char l_lvl_4_q[6];	// 매수4단계우선호가잔량
	char l_lvl_5_sign[1];	// 매수5단계부호
	char l_lvl_5_prc[5];	// 매수5단계우선호가가격,예) 999.99
	char l_lvl_5_q[6];	// 매수5단계우선호가잔량
	char total_s_limit_ord_q[6];	// 매도총호가잔량
	char s_lvl_1_sign[1];	// 매도1단계부호
	char s_lvl_1_prc[5];	// 매도1단계우선호가가격,예) 999.99
	char s_lvl_1_q[6];	// 매도1단계우선호가잔량
	char s_lvl_2_sign[1];	// 매도2단계부호
	char s_lvl_2_prc[5];	// 매도2단계우선호가가격,예) 999.99
	char s_lvl_2_q[6];	// 매도2단계우선호가잔량
	char s_lvl_3_sign[1];	// 매도3단계부호
	char s_lvl_3_prc[5];	// 매도3단계우선호가가격,예) 999.99
	char s_lvl_3_q[6];	// 매도3단계우선호가잔량
	char s_lvl_4_sign[1];	// 매도4단계부호
	char s_lvl_4_prc[5];	// 매도4단계우선호가가격,예) 999.99
	char s_lvl_4_q[6];	// 매도4단계우선호가잔량
	char s_lvl_5_sign[1];	// 매도5단계부호
	char s_lvl_5_prc[5];	// 매도5단계우선호가가격,예) 999.99
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
	char real_t_high_prc[5];	// 실시간상한가,예) 999.99 개발가이드 참조
	char real_t_low_prc_sign[1];	// 실시간하한가부호
	char real_t_low_prc[5];	// 실시간하한가,예) 999.99 개발가이드 참조
	char ff[1];	// End of Text, (0xFF)
} K200_FUT_EXEC_LIMIT_ORD;
    

// B6014 : K200선물_우선호가
typedef struct _K200_FUT_LIMIT_ORD {
	char data_clsf[2];	// DATA구분,B6
	char info_clsf[2];	// 정보구분,01:KOSPI200지수선물
	char mkt_clsf[1];	// 시장구분,4
	char isin_clsf[12];	// 종목코드
	char seq[2];	// 종목일련번호
	char brd_id[2];	// 보드ID,코드값모음참조
	char ss_id[2];	// 세션ID,코드값모음참조
	char total_l_limit_ord_q[6];	// 매수총호가잔량
	char l_lvl_1_sign[1];	// 매수1단계부호
	char l_lvl_1_prc[5];	// 매수1단계우선호가가격,예) 999.99
	char l_lvl_1_q[6];	// 매수1단계우선호가잔량
	char l_lvl_2_sign[1];	// 매수2단계부호
	char l_lvl_2_prc[5];	// 매수2단계우선호가가격,예) 999.99
	char l_lvl_2_q[6];	// 매수2단계우선호가잔량
	char l_lvl_3_sign[1];	// 매수3단계부호
	char l_lvl_3_prc[5];	// 매수3단계우선호가가격,예) 999.99
	char l_lvl_3_q[6];	// 매수3단계우선호가잔량
	char l_lvl_4_sign[1];	// 매수4단계부호
	char l_lvl_4_prc[5];	// 매수4단계우선호가가격,예) 999.99
	char l_lvl_4_q[6];	// 매수4단계우선호가잔량
	char l_lvl_5_sign[1];	// 매수5단계부호
	char l_lvl_5_prc[5];	// 매수5단계우선호가가격,예) 999.99
	char l_lvl_5_q[6];	// 매수5단계우선호가잔량
	char total_s_limit_ord_q[6];	// 매도총호가잔량
	char s_lvl_1_sign[1];	// 매도1단계부호
	char s_lvl_1_prc[5];	// 매도1단계우선호가가격,예) 999.99
	char s_lvl_1_q[6];	// 매도1단계우선호가잔량
	char s_lvl_2_sign[1];	// 매도2단계부호
	char s_lvl_2_prc[5];	// 매도2단계우선호가가격,예) 999.99
	char s_lvl_2_q[6];	// 매도2단계우선호가잔량
	char s_lvl_3_sign[1];	// 매도3단계부호
	char s_lvl_3_prc[5];	// 매도3단계우선호가가격,예) 999.99
	char s_lvl_3_q[6];	// 매도3단계우선호가잔량
	char s_lvl_4_sign[1];	// 매도4단계부호
	char s_lvl_4_prc[5];	// 매도4단계우선호가가격,예) 999.99
	char s_lvl_4_q[6];	// 매도4단계우선호가잔량
	char s_lvl_5_sign[1];	// 매도5단계부호
	char s_lvl_5_prc[5];	// 매도5단계우선호가가격,예) 999.99
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
	char exp_prc_sign[1];	// 예상체결가격부호,단일가매매시만 제공\n (장상태구분코드:10,20,30,80)
	char exp_prc[5];	// 예상체결가격,예) 999.99\n 단일가매매시만 제공\n (장상태구분코드:10,20,30,80)
	char ff[1];	// End of Text, (0xFF)
} K200_FUT_LIMIT_ORD;

// A3014 : K200선물_체결
typedef struct _K200_FUT_EXEC {
	char data_clsf        [2 ];	// DATA구분,A3
	char info_clsf        [2 ];	// 정보구분,01:KOSPI200지수선물
	char mkt_clsf         [1 ];	// 시장구분,4
	char isin_clsf        [12];	// 종목코드
	char seq              [2 ];	// 종목일련번호
	char brd_id           [2 ];	// 보드ID,코드값모음참조
	char cur_prc_sign     [1 ];	// 현재가격부호
	char cur_prc          [5 ];	// 현재가격,예) 999.99
	char exe_q            [6 ];	// 체결수량
	char ss_id            [2 ];	// 세션ID,코드값모음참조
	char exe_t            [8 ];	// 체결시각
	char rct_prd_prc      [5 ];	// 최근월물의제약정가격,예) 999.99
	char nxt_prd_prc      [5 ];	// 원월물의제약정가격,예) 999.99
	char init_prc_sign[1];	// 시가부호
	char init_prc[5];	// 시가,예) 999.99
	char high_prc_sign[1];	// 고가부호
	char high_prc[5];	// 고가,예) 999.99
	char low_prc_sign[1];	// 저가부호
	char low_prc[5];	// 저가,예) 999.99
	char pri_prc_sign[1];	// 직전가격부호
	char pri_prc[5];	// 직전가격,예) 999.99
	char accm_exe_q[7];	// 누적체결수량
	char accm_trd_amt[12];	// 누적거래대금,단위:천원
	char accm_block_trd_exe_q[7];	// 협의대량누적체결수량,미제공(Filler)
	char l_or_s[1];	// 최종매도매수구분코드,1:매도,2:매수(최종으로 들어온 호가의 매도매수구분값)
	char real_t_high_prc_sign[1];	// 실시간상한가부호
	char real_t_high_prc[5];	// 실시간상한가,예) 999.99 개발가이드 참조
	char real_t_low_prc_sign[1];	// 실시간하한가부호
	char real_t_low_prc[5];	// 실시간하한가,예) 999.99 개발가이드 참조
	char ff[1];	// End of Text, (0xFF)
} K200_FUT_EXEC;

#endif
