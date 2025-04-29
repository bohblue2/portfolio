#ifndef _OPTPK_H_
#define _OPTPK_H_

#include "zconf.h"

typedef struct _proc_list
{
    char    id[6];
    int     (*AppProc)(char *buff);
    char    tname[30];
} PROC_LIST;

/* hader file 중복 문제 해결 */
#ifdef ZAPLST

int OptProcA3034(char *buff);
int OptProcB6034(char *buff);
int OptProcG7034(char *buff);

PROC_LIST AppList[] = {
{"A3034",     OptProcA3034, "K200_OPT_EXEC"             },
{"B6034",     OptProcB6034, "K200_OPT_LIMIT_ORD"        },
{"G7034",     OptProcG7034, "K200_OPT_EXEC_LIMIT_ORD"   },
};

#define AP_CNT	( sizeof(AppList)/sizeof(PROC_LIST))

#endif                    

// C A3034 : K200옵션_체결
// I A3034 : K200옵션_체결
// I B6034 : K200옵션_우선호가
// I G7034 : K200옵션_체결_우선

// C A3034 : K200옵션_체결
typedef struct _K200_OPT_EXEC {
	char    data_clsf           [ 2];	// X	2  DATA구분, A3
	char    info_clsf           [ 2];	// X	2  정보구분, 03:KOSPI200지수옵션
	char    mrk_clsf            [ 1];	// X	1  시장구분, 4
	char    isin_clsf           [12];	// X	12 종목코드
	char    seq                 [ 4];	// 9	4  종목일련번호, 종목일련번호 자리수 변경(3->4)
	char    brd_id              [ 2];	// X	2  보드ID, 코드값모음참조
	char    cur_prc             [ 5];	// 9	5  현재가격, 예) 999.99
	char    exe_q               [ 7];	// 9	7  체결수량
	char    ss_id               [ 2];	// X	2  세션ID, 코드값모음참조
	char    exe_t               [ 8];	// X	8  체결시각
	char    init_prc            [ 5];	// 9	5  시가, 예) 999.99
	char    high_prc            [ 5];	// 9	5  고가, 예) 999.99
	char    low_prc             [ 5];	// 9	5  저가, 예) 999.99
	char    pri_prc             [ 5];	// 9	5  직전가격, 예) 999.99
	char    accm_exe_q          [ 8];	// 9	8  누적체결수량
	char    accm_trd_amt        [11];	// 9	11 누적거래대금, 단위:천원
	char    filter              [ 8];	// 9	8  협의대량누적체결수량, 미제공(Filler)
	char    l_or_s              [ 1];	// X	1  최종매도매수구분코드, 1:매도,2:매수(최종으로 들어온 호가의 매도매수구분값)
	char    real_t_high_prc     [ 5];	// 9	5  실시간상한가, 예) 999.99 개발가이드참조
	char    real_t_low_prc      [ 5];	// 9	5  실시간하한가, 예) 999.99 개발가이드참조
	char    ff                  [ 1];	// X	1  End of Text, 0xFF
} K200_OPT_EXEC;
    
// K200옵션_우선호가
typedef struct _K200_OPT_LIMIT_ORD {
	char data_clsf              [ 2];	// X	2  DATA구분, B6
	char info_clsf              [ 2];	// X	2  정보구분, 03:KOSPI200지수옵션
	char mrk_clsf               [ 1];	// X	1  시장구분, 4
	char isin_clsf              [12];	// X	12 종목코드
	char seq                    [ 4];	// 9	4  종목일련번호, 종목일련번호 자리수 변경(3->4)
	char brd_id                 [ 2];	// X	2  보드ID, 코드값모음참조
	char ss_id                  [ 2];	// X	2  세션ID, 코드값모음참조
	char total_l_limit_ord_q    [ 7];	// 9	7  매수총호가잔량
	char l_lvl_1_prc            [ 5];	// 9	5  매수1단계우선호가가격, 예) 999.99
	char l_lvl_1_q              [ 7];	// 9	7  매수1단계우선호가잔량
	char l_lvl_2_prc            [ 5];	// 9	5  매수2단계우선호가가격, 예) 999.99
	char l_lvl_2_q              [ 7];	// 9	7  매수2단계우선호가잔량
	char l_lvl_3_prc            [ 5];	// 9	5  매수3단계우선호가가격, 예) 999.99
	char l_lvl_3_q              [ 7];	// 9	7  매수3단계우선호가잔량
	char l_lvl_4_prc            [ 5];	// 9	5  매수4단계우선호가가격, 예) 999.99
	char l_lvl_4_q              [ 7];	// 9	7  매수4단계우선호가잔량
	char l_lvl_5_prc            [ 5];	// 9	5  매수5단계우선호가가격, 예) 999.99
	char l_lvl_5_q              [ 7];	// 9	7  매수5단계우선호가잔량
	char total_s_limit_ord_q    [ 7];	// 9	7  매도총호가잔량
	char s_lvl_1_prc            [ 5];	// 9	5  매도1단계우선호가가격, 예) 999.99
	char s_lvl_1_q              [ 7];	// 9	7  매도1단계우선호가잔량
	char s_lvl_2_prc            [ 5];	// 9	5  매도2단계우선호가가격, 예) 999.99
	char s_lvl_2_q              [ 7];	// 9	7  매도2단계우선호가잔량
	char s_lvl_3_prc            [ 5];	// 9	5  매도3단계우선호가가격, 예) 999.99
	char s_lvl_3_q              [ 7];	// 9	7  매도3단계우선호가잔량
	char s_lvl_4_prc            [ 5];	// 9	5  매도4단계우선호가가격, 예) 999.99
	char s_lvl_4_q              [ 7];	// 9	7  매도4단계우선호가잔량
	char s_lvl_5_prc            [ 5];	// 9	5  매도5단계우선호가가격, 예) 999.99
	char s_lvl_5_q              [ 7];	// 9	7  매도5단계우선호가잔량
	char total_l_trd_cnt        [ 5];	// 9	5  매수유효호가건수
	char l_lvl_1_trd_cnt        [ 4];	// 9	4  매수1단계우선호가건수
	char l_lvl_2_trd_cnt        [ 4];	// 9	4  매수2단계우선호가건수
	char l_lvl_3_trd_cnt        [ 4];	// 9	4  매수3단계우선호가건수
	char l_lvl_4_trd_cnt        [ 4];	// 9	4  매수4단계우선호가건수
	char l_lvl_5_trd_cnt        [ 4];	// 9	4  매수5단계우선호가건수
	char total_s_trd_cnt        [ 5];	// 9	5  매도유효호가건수
	char s_lvl_1_trd_cnt        [ 4];	// 9	4  매도1단계우선호가건수
	char s_lvl_2_trd_cnt        [ 4];	// 9	4  매도2단계우선호가건수
	char s_lvl_3_trd_cnt        [ 4];	// 9	4  매도3단계우선호가건수
	char s_lvl_4_trd_cnt        [ 4];	// 9	4  매도4단계우선호가건수
	char s_lvl_5_trd_cnt        [ 4];	// 9	4  매도5단계우선호가건수
	char ord_rcv_t              [ 8];	// X	8  호가접수시각
	char exp_prc                [ 5];	// 9	5  예상체결가격, 예) 999.99 단일가매매시만 제공\n (장상태구분코드:10,20,30,80)
	char ff                     [ 1];	// X	1  End of Text, 0xFF
} K200_OPT_LIMIT_ORD;


// K200옵션_체결_우선호가
typedef struct _K200_OPT_EXEC_LIMIT_ORD {
	char data_clsf              [ 2];	// X	2  DATA구분, G7
	char info_clsf              [ 2];	// X	2  정보구분, 03:KOSPI200지수옵션
	char mrk_clsf               [ 1];	// X	1  시장구분, 4
	char isin_clsf              [12];	// X	12 종목코드
	char seq                    [ 4];	// 9	4  종목일련번호, 종목일련번호 자리수 변경(3->4)
	char brd_id                 [ 2];	// X	2  보드ID, 코드값모음참조
	char cur_prc                [ 5];	// 9	5  현재가격, 예) 999.99
	char exe_q                  [ 7];	// 9	7  체결수량
	char ss_id                  [ 2];	// X	2  세션ID, 코드값모음참조
	char exe_t                  [ 8];	// X	8  체결시각
	char init_prc               [ 5];	// 9	5  시가, 예) 999.99
	char high_prc               [ 5];	// 9	5  고가, 예) 999.99
	char low_prc                [ 5];	// 9	5  저가, 예) 999.99
	char pri_prc                [ 5];	// 9	5  직전가격, 예) 999.99
	char accm_exe_q             [ 8];	// 9	8  누적체결수량
	char accm_trd_amt           [11];	// 9	11 누적거래대금, 단위:천원
	char accm_block_trd_exe_q   [ 8];	// 9	8  협의대량누적체결수량, 미제공(Filler)
	char l_or_s                 [ 1];	// X	1  최종매도매수구분코드, 1:매도,2:매수(최종으로 들어온 호가의 매도매수구분값)
	char total_l_limit_ord_q    [ 7];	// 9	7  매수총호가잔량
	char l_lvl_1_prc            [ 5];	// 9	5  매수1단계우선호가가격, 예) 999.99
	char l_lvl_1_q              [ 7];	// 9	7  매수1단계우선호가잔량
	char l_lvl_2_prc            [ 5];	// 9	5  매수2단계우선호가가격, 예) 999.99
	char l_lvl_2_q              [ 7];	// 9	7  매수2단계우선호가잔량
	char l_lvl_3_prc            [ 5];	// 9	5  매수3단계우선호가가격, 예) 999.99
	char l_lvl_3_q              [ 7];	// 9	7  매수3단계우선호가잔량
	char l_lvl_4_prc            [ 5];	// 9	5  매수4단계우선호가가격
	char l_lvl_4_q              [ 7];	// 9	7  매수4단계우선호가잔량
	char l_lvl_5_prc            [ 5];	// 9	5  매수5단계우선호가가격, 예) 999.99
	char l_lvl_5_q              [ 7];	// 9	7  매수5단계우선호가잔량
	char total_s_limit_ord_q    [ 7];	// 9	7  매도총호가잔량
	char s_lvl_1_prc            [ 5];	// 9	5  매도1단계우선호가가격, 예) 999.99
	char s_lvl_1_q              [ 7];	// 9	7  매도1단계우선호가잔량
	char s_lvl_2_prc            [ 5];	// 9	5  매도2단계우선호가가격
	char s_lvl_2_q              [ 7];	// 9	7  매도2단계우선호가잔량, 예) 999.99
	char s_lvl_3_prc            [ 5];	// 9	5  매도3단계우선호가가격
	char s_lvl_3_q              [ 7];	// 9	7  매도3단계우선호가잔량
	char s_lvl_4_prc            [ 5];	// 9	5  매도4단계우선호가가격, 예) 999.99
	char s_lvl_4_q              [ 7];	// 9	7  매도4단계우선호가잔량
	char s_lvl_5_prc            [ 5];	// 9	5  매도5단계우선호가가격
	char s_lvl_5_q              [ 7];	// 9	7  매도5단계우선호가잔량, 예) 999.99
	char total_l_trd_cnt        [ 5];	// 9	5  매수유효호가건수
	char l_lvl_1_trd_cnt        [ 4];	// 9	4  매수1단계우선호가건수
	char l_lvl_2_trd_cnt        [ 4];	// 9	4  매수2단계우선호가건수
	char l_lvl_3_trd_cnt        [ 4];	// 9	4  매수3단계우선호가건수, 예) 999.99
	char l_lvl_4_trd_cnt        [ 4];	// 9	4  매수4단계우선호가건수
	char l_lvl_5_trd_cnt        [ 4];	// 9	4  매수5단계우선호가건수
	char total_s_trd_cnt        [ 5];	// 9	5  매도유효호가건수, 예) 999.99
	char s_lvl_1_trd_cnt        [ 4];	// 9	4  매도1단계우선호가건수
	char s_lvl_2_trd_cnt        [ 4];	// 9	4  매도2단계우선호가건수
	char s_lvl_3_trd_cnt        [ 4];	// 9	4  매도3단계우선호가건수, 예) 999.99
	char s_lvl_4_trd_cnt        [ 4];	// 9	4  매도4단계우선호가건수
	char s_lvl_5_trd_cnt        [ 4];	// 9	4  매도5단계우선호가건수
	char real_t_high_prc        [ 5];	// 9	5  실시간상한가, 예) 999.99 개발가이드참조
	char real_t_low_prc         [ 5];	// 9	5  실시간하한가, 예) 999.99 개발가이드참조
	char ff                     [ 1];	// X	1  End of Text, 0xFF
} K200_OPT_EXEC_LIMIT_ORD;

#endif
