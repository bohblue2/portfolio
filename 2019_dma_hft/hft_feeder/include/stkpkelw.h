#ifndef _STKPKELW_H_
#define _STKPKELW_H_

#include "zconf.h"

#define TICK_CNT    10

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

//  B7021 : ELW_호가잔량_LP호가_포함
typedef struct _ELW_ASK_RSD_WLP {
	char    data_clsf   [2];	    // DATA구분, B7
	char    info_clsf   [2];	    // 정보구분, 01:유가증권종목 02:ELW
	char    mkt_clsf    [1];	    // 시장구분, 1:유가증권
	char    isin_code   [12];	    // 종목코드, 표준코드
	char    stk_snr     [5];	    // 종목일련번호, 종목배치(A0)의 종목일련번호
	char    cum_ccls_qty[12];	    // 누적체결수량
	PK_TICKLP ticklp    [10];       // 호가 OCCURS 1010× 66 = 660
	char    ask_tot_rsd_10[12];	    // 10단계호가매도총잔량
	char    bid_tot_rsd_10[12];	    // 10단계호가매수총잔량
	char    filler1[12];	        // FILLER
	char    filler2[12];	        // FILLER
	char    ofhr_ask_tot_rsd[12];	// 장종료후시간외 매도총호가잔량, 보드ID가 ""G3""일 경우 설정됨 \n ※ELW는 시간외거래 없음
	char    ofhr_bid_tot_rsd[12];	// 장종료후시간외 매수총호가잔량, 보드ID가 ""G3""일 경우 설정됨\n ※ELW는 시간외거래 없음
	char    sess_id[2];	            // 세션ID, ※ 코드값모음 참조
	char    brd_id[2];	            // 보드ID, ※ 코드값모음 참조
	char    exp_ccls_prc[9];	    // 예상체결가격
	char    exp_ccls_qty[12];	    // 예상체결수량
	char    cmpt_msv_dir_clsf[1];	// 경쟁대량 방향구분, 0:해당없음, 1:매도, 2:매수
	char    filler3[7];	            // FILLER, SPACE
	char    ff[1];	                // FF, END OF TEXT (0xFF)
} ELW_ASK_RSD_WLP;

//  A3021 : ELW_체결
typedef struct _ELW_CCLS {
	char    data_clsf[2];	            // DATA구분, A3
	char    info_clsf[2];	            // 정보구분, 01:주식 02:ELW
	char    mkt_clsf[1];	            // 시장구분, 1:유가증권 2:코스닥
	char    isin_code[12];	            // 종목코드, 표준코드
	char    stk_snr[5];	                // 종목일련번호, 종목배치(A0)의 종목일련번호
	char    brd_id[2];	                // 보드ID, ※ 코드값모음 참조
	char    ctrs_clsf[1];	            // "전일대비(기준가대비) 구분", 0:판단불가 1:상한 2:상승 3:보합 4:하한 5:하락\n ※ 정규시간외구분코드 값이 4인 경우 당일 종가 대비\n ※ 정규시간외구분코드 값이 7,8인 경우 Buy-in기준가 대비
	char    prev_ctrs[9];	            // 전일대비, 단위:원 신주인수권 증서/증권의 신규 상장 당일 : 0
	char    ccls_prc[9];	            // 체결가격, 단위:원
	char    ccls_qty[10];	            // 체결수량, 단위:주
	char    sess_id[2];	                // 세션ID, ※ 코드값모음 참조
	char    open[9];	                // 시가, 단위:원 ※개발가이드 참조
	char    hi[9];	                    // 고가, 단위:원 ※개발가이드 참조
	char    low[9];	                    // 저가, 단위:원 ※개발가이드 참조
	char    cum_ccls_qty[12];	        // 누적체결수량, 단위:주 ※보드ID별로 누적됨
	char    cum_trd_val[18];	        // 누적거래대금, 단위:원 ※보드ID별로 누적됨
	char    fin_bid_ask_clsf_code[1];	// 최종매도매수구분코드, 1:매도 2:매수
	char    mtc_flg[1];	                // 체결가와1호가일치여부, 0:판단불가 1:일치 2:불일치
	char    ccls_time[6];	            // 체결시각, HHMMSS
	char    lp_hld_qty[15];	            // LP보유수량, LP(체결기준) 집계후 LP보유수량
	char    ask_1_prc[9];	            // 매도1호가, 단위:원 ※개발가이드 참조
	char    bid_1_prc[9];	            // 매수1호가, 단위:원 ※개발가이드 참조
	char    filler[6];	                // FILLER, SPACE
	char    ff[1];	                    // FF, END OF TEXT (0xFF)
} ELW_CCLS;

#endif
