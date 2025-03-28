#ifndef _STKDFELW_H_
#define _STKDFELW_H_

#include "zconf.h"

#define TICK_CNT    10

typedef struct _DF_TICK {
    int     ask_prc             ;   //char ask_prc          [9 ];	// 매도호가1
	int     bid_prc             ;   //char bid_prc          [9 ];	// 매수호가1
	double  ask_vol_rsd         ;   //char ask_vol_rsd      [12];	// 매도호가 잔량1
	double  bid_vol_rsd         ;   //char bid_vol_rsd      [12];	// 매수호가 잔량1    
} DF_TICK; 

typedef struct _DF_TICKLP {
    int     ask_prc             ;   //char ask_prc          [9 ];	// 매도호가1
	int     bid_prc             ;   //char bid_prc          [9 ];	// 매수호가1
	double  ask_vol_rsd         ;   //char ask_vol_rsd      [12];	// 매도호가 잔량1
	double  bid_vol_rsd         ;   //char bid_vol_rsd      [12];	// 매수호가 잔량1  
	double  lp_ask_vol_rsd      ;   //char lp_ask_vol_rsd   [12];	// LP 매도호가 잔량1
	double  lp_bid_vol_rsd      ;   //char lp_bid_vol_rsd   [12];	// LP 매수호가 잔량1  
} DF_TICKLP; 

typedef struct _DFELW_ASK_RSD_WLP {
	char    data_clsf            [2+1];	// X	2   DATA구분, B7
	char    info_clsf            [2+1];	// X	2   정보구분, 01:유가증권종목 02:ELW
	char    mkt_clsf             [1+1];	// X	1   시장구분, 1:유가증권
	char    isin_code           [12+1];	// X	12  종목코드, 표준코드
	int     stk_snr                   ;  	// 9	5   종목일련번호, 종목배치(A0)의 종목일련번호
	double  cum_ccls_qty              ;	// 9	12  누적체결수량
	DF_TICKLP ticklp              [10];   //           호가 OCCURS 1010× 66 = 660
	double  ask_tot_rsd_10            ;	// 9	12  10단계호가매도총잔량
	double  bid_tot_rsd_10            ;	// 9	12  10단계호가매수총잔량
	char    filler1             [12+1];	// 9	12  FILLER
	char    filler2             [12+1];	// 9	12  FILLER
	double  ofhr_ask_tot_rsd          ;	// 9	12  장종료후시간외 매도총호가잔량, 보드ID가 ""G3""일 경우 설정됨 \n ※ELW는 시간외거래 없음
	double  ofhr_bid_tot_rsd          ;	// 9	12  장종료후시간외 매수총호가잔량, 보드ID가 ""G3""일 경우 설정됨\n ※ELW는 시간외거래 없음
	char    sess_id              [2+1];	// X	2   세션ID, ※ 코드값모음 참조
	char    brd_id               [2+1];	// X	2   보드ID, ※ 코드값모음 참조
	int     exp_ccls_prc              ; 	// 9	9   예상체결가격
	double  exp_ccls_qty              ;	// 9	12  예상체결수량
	int     cmpt_msv_dir_clsf         ;	// 9	1   경쟁대량 방향구분, 0:해당없음, 1:매도, 2:매수
	char    filler3              [7+1];	// X	7   FILLER, SPACE
	char    ff                   [1+1];	// X	1   FF, END OF TEXT (0xFF)
} DFELW_ASK_RSD_WLP;

// 코스피_체결 A3011 int 9 double 10 ~
typedef struct _DFELW_CCLS {
	char    data_clsf       [ 2+1];    	    //char data_clsf[2];	        // DATA구분, A3
	char    info_clsf       [ 2+1];	        //char info_clsf[2];	        // 정보구분, 01:주식 02:ELW
	char    mkt_clsf        [ 1+1];	        //char mkt_clsf[1];	            // 시장구분, 1:유가증권 2:코스닥
	char    isin_code       [12+1];	        //char isin_code[12];	        // 종목코드, 표준코드
	int     stk_snr             ;	        //char stk_snr[5];	            // 종목일련번호, 종목배치(A0)의 종목일련번호
	char    brd_id          [ 2+1];	        //char brd_id[2];	            // 보드ID, ※ 코드값모음 참조
	char    ctrs_clsf       [ 1+1];	        //char ctrs_clsf[1];	        // "전일대비(기준가대비) 구분", 0:판단불가 1:상한 2:상승 3:보합 4:하한 5:하락\n ※ 정규시간외구분코드 값이 4인 경우 당일 종가 대비\n ※ 정규시간외구분값이비
	int     prev_ctrs           ;	        //char prev_ctrs[9];	        // 전일대비, 단위:원 신주인수권 증서/증권의 신규 상장 당일 : 0
	int     ccls_prc            ;	        //char ccls_prc[9];	            // 체결가격, 단위:원
	double  ccls_qty            ;	        //char ccls_qty[10];	        // 체결수량, 단위:주
	char    sess_id         [ 2+1];	        //char sess_id[2];	            // 세션ID, ※ 코드값모음 참조
	int     open                ;	        //char open[9];	                // 시가, 단위:원 ※개발가이드 참조
	int     hi                  ;	        //char hi[9];	                // 고가, 단위:원 ※개발가이드 참조
	int     low                 ;	        //char low[9];	                // 저가, 단위:원 ※개발가이드 참조
	double  cum_ccls_qty        ;	        //char cum_ccls_qty[12];	    // 누적체결수량, 단위:주 ※보드ID별로 누적됨
	double  cum_trd_val         ;	        //char cum_trd_val[18];	        // 누적거래대금, 단위:원 ※보드ID별로 누적됨
	char    fin_bid_ask_clsf_code[ 1+1];       //char fin_bid_ask_clsf_code[1];// 최종매도매수구분코드, 1:매도 2:매수
	char    mtc_flg         [ 1+1];	        //char mtc_flg[1];	            // 체결가와1호가일치여부, 0:판단불가 1:일치 2:불일치
	char    ccls_time       [ 6+1];	        //char ccls_time[6];	        // 체결시각, HHMMSS
	double  lp_hld_qty          ;	        //char lp_hld_qty[15];	        // LP보유수량, LP(체결기준) 집계후 LP보유수량\n음수발생 가능(ETN만 해당)(2018.09.17)
	int     ask_1_prc           ;	        //char ask_1_prc[9];	        // 매도1호가, 단위:원 ※개발가이드 참조
	int     bid_1_prc           ;	        //char bid_1_prc[9];	        // 매수1호가, 단위:원 ※개발가이드 참조
	char    filler[6];	                    //char filler[6];	            // FILLER, SPACE
	char    ff[1];	                        //char ff[1];	                // FF, END OF TEXT (0xFF)
} DFELW_CCLS;

#endif
