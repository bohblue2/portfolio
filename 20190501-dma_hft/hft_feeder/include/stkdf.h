#ifndef _STKDF_H_
#define _STKDF_H_

#include "zconf.h"

#define TICK_CNT    10

//B6011 : 코스피_호가잔량_LP호가_제외 KOSPI_ASK_RSD_WOLP
//B7011 : 코스피_호가잔량_LP호가_포함 KOSPI_ASK_RSD_WLP
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

// A6021 : ELW_종목마감
typedef struct _DFELW_STK_CLSG {
	char    data_clsf             [2+1];	// X	2   DATA구분, A6
	char    info_clsf             [2+1];	// X	2   정보구분, 01:주식 02:ELW
	char    mkt_clsf              [1+1];	// X	1   시장구분, 1:유가증권 2:코스닥
	char    isin_code            [12+1];	// X	12  종목코드, 표준코드
	int     snr                        ;	// 9	5   종목일련번호, 종목배치(A0)의 종목일련번호
	char    brd_id                [2+1];	// X	2   보드ID, ※ 코드값모음 참조
	int     stk_cls_prc                ;	// 9	9   종목마감종가, 정규시간외구분코드가 \n 1:정규장일때만 종목마감가격구분코드값이 SET 됨. \n 그외에는 SPACE
	char    stk_cls_prc_clsf_code [1+1];	// X	1   종목마감가격구분코드, 1:체결가 \n 2:기세 \n 3:거래무 \n 4:시가기준가종목의 기세\n :정규장이 아닌 경우 SPACE
	int     ofhr_hi                    ;	// 9	9   "종목마감시간외단일가 상한가"
	int     ofhr_lo                    ;	// 9	9   "종목마감시간외단일가 하한가"
	int     stk_cls_mwprc              ;	// 9	9   종목마감평균가중주가
	int     dlv_base_prc               ;	// 9	9   매입인도기준가격
	int     dlv_hi                     ;	// 9	9   매입인도상한가
	int     dlv_lo                     ;	// 9	9   매입인도하한가
	char    filler                [1+1];	// X	1   FILLER, SPACE
	char    ff                    [1+1];	// X	1   FF, END OF TEXT (0xFF)
} DFELW_STK_CLSG;

// B1021 : ELW_시세종가
typedef struct _DFELW_MKT_PRC_CLS {
	char    data_clsf            [2+1];	// X	2  DATA구분, B1:종가 B2:시세REC
	char    info_clsf            [2+1];	// X	2  정보구분, 01:주식 02:ELW
	char    mkt_clsf             [1+1];	// X	1  시장구분, 1:유가증권 2:코스닥
	char    isin_code           [12+1];	// X	12 종목코드, 표준코드
	int     stk_snr                   ;	// 9	5  종목일련번호, 종목배치(A0)의 종목일련번호
	char    flct_clsf            [1+1];	// X	1  등락구분, 0:판단불가 1:상한 2:상승 3:보합 4:하한 5:하락
	int     prev_ctrs                 ;	// 9	9  전일대비, 단위:원
	int     cur_prc                   ;	// 9	9  현재가
	int     open                      ;	// 9	9  시가, 정규장 시가
	int     high                      ;	// 9	9  고가, 정규장 고가
	int     low                       ;	// 9	9  저가, 정규장 저가
	int     ask_prc                   ;	// 9	9  매도호가, B1시 0값 SET
	int     bid_prc                   ;	// 9	9  매수호가, B1시 0값 SET
	double  cum_ccls_qty              ;	// 9	12 누적체결수량, 단위:주 ※시간외단일가, BUY-IN을 제외한 모든 체결수량 합산
	double  cum_trd_val               ;	// 9	18 누적거래대금, 단위:원 ※시간외단일가, BUY-IN을 제외한 모든 거래대금 합산
	char    trend_flg            [1+1];	// X	1  실세/기세 구분, 0:초기값 1:실세 2:기세 3:거래무 4:시가기준가종목의 기세
	char    brd_evt_id           [3+1];	// X	3  보드이벤트ID, B1/B2 에서는 보드이벤트ID 사용금지(과거 상태값이 전송될 수 있음). 추후, 해당 항목 '000' 세팅 예정. 2014.03.24)
	char    brd_id               [2+1];	// X	2  보드ID, ※ 코드값모음 참조
	char    trsp_flg             [1+1];	// X	1  거래정지여부, Y, N
	double  bopen_ofhr_ccls_qty       ;	// 9	12 "장개시전시간외종가 체결수량", 대량, 바스켓은 제외, 단위:주
	double  bopen_ofhr_trd_val        ;	// 9	18 "장개시전시간외종가 거래대금", 대량, 바스켓은 제외, 단위:원
	double  opr_time_ccls_qty         ;	// 9	12 정규장체결수량, 대량, 바스켓은 제외, 단위:주
	double  opr_time_trd_val          ;	// 9	18 정규장거래대금, 대량, 바스켓은 제외, 단위:원
	double  ofhr_cls_ccls_qty         ;	// 9	12 "장종료후시간외종가 체결수량", 대량, 바스켓은 제외, 단위:주
	double  ofhr_cls_trd_val          ;	// 9	18 "장종료후시간외종가 거래대금", 대량, 바스켓은 제외, 단위:원
	char    elw_ely_cls_flg      [1+1];	// X	1  ELW조기종료여부, Y,N 조기종료ELW 外 종목은 Default 'N' SET
	int     elw_ely_cls_time          ;	// 9	6  ELW조기종료시간, HHMMSS, ELW조기종료여부가 'Y'인 경우만 설정
	int     cmpt_msv_dir_clsf         ;	// 9	1  경쟁대량 방향구분, 0:해당없음, 1:매도, 2:매수
	double  gen_bin_ccls_qty          ;	// 9	12 일반 Buy-in 체결수량, 단위:주
	double  gen_bin_ccls_trd_val      ;	// 9	18 일반 Buy-in 거래대금, 단위:원
	double  day_bin_ccls_qty          ;	// 9	12 당일 Buy-in 체결수량, 단위:주
	double  day_bin_ccls_trd_val      ;	// 9	18 당일 Buy-in 거래대금, 단위:원
	char    filler               [8+1];	// X	8  FILLER, SPACE
	char    ff                   [1+1];	// X	1  FF, END OF TEXT (0xFF)
} DFELW_MKT_PRC_CLS;

// B1011 : 코스피_시세종가
typedef struct _DFKOSPI_MKT_PRC_CLS {
	char    data_clsf            [2+1];	// X	2   DATA구분, B1:종가 B2:시세REC
	char    info_clsf            [2+1];	// X	2   정보구분, 01:주식 02:ELW
	char    mkt_clsf             [1+1];	// X	1   시장구분, 1:유가증권 2:코스닥
	char    isin_code           [12+1];	// X	12  종목코드, 표준코드
	int     stk_snr                   ;	// 9	5   종목일련번호, 종목배치(A0)의 종목일련번호
	char    flct_clsf            [1+1];	// X	1   등락구분, 0:판단불가 1:상한 2:상승 3:보합 4:하한 5:하락
	int     prev_ctrs                 ;	// 9	9   전일대비, 단위:원
	int     cur_prc                   ;	// 9	9   현재가
	int     open                      ;	// 9	9   시가, 정규장 시가
	int     high                      ;	// 9	9   고가, 정규장 고가
	int     low                       ;	// 9	9   저가, 정규장 저가
	int     ask_prc                   ;	// 9	9   매도호가, B1시 0값 SET
	int     bid_prc                   ;	// 9	9   매수호가, B1시 0값 SET
	double  cum_ccls_qty              ;	// 9	12  누적체결수량, 단위:주 ※시간외단일가, BUY-IN을 제외한 모든 체결수량 합산
	double  cum_trd_val               ;	// 9	18  누적거래대금, 단위:원 ※시간외단일가, BUY-IN을 제외한 모든 거래대금 합산
	char    trend_flg            [1+1];	// X	1   실세/기세 구분, 0:초기값 1:실세 2:기세 3:거래무 4:시가기준가종목의 기세
	char    brd_evt_id           [3+1];	// X	3   보드이벤트ID, B1/B2 에서는 보드이벤트ID 사용금지(과거 상태값이 전송될 수 있음). 추후, 해당 항목 '000' 세팅 예정. 2014.03.24)
	char    brd_id               [2+1];	// X	2   보드ID, ※ 코드값모음 참조
	char    trsp_flg             [1+1];	// X	1   거래정지여부, Y, N
	double  bopen_ofhr_ccls_qty       ;	// 9	12  "장개시전시간외종가 체결수량", 대량, 바스켓은 제외, 단위:주
	double  bopen_ofhr_trd_val        ;	// 9	18  "장개시전시간외종가 거래대금", 대량, 바스켓은 제외, 단위:원
	double  opr_time_ccls_qty         ;	// 9	12  정규장체결수량, 대량, 바스켓은 제외, 단위:주
	double  opr_time_trd_val          ;	// 9	18  정규장거래대금, 대량, 바스켓은 제외, 단위:원
	double  ofhr_cls_ccls_qty         ;	// 9	12  "장종료후시간외종가 체결수량", 대량, 바스켓은 제외, 단위:주
	double  ofhr_cls_trd_val          ;	// 9	18  "장종료후시간외종가 거래대금", 대량, 바스켓은 제외, 단위:원
	char    elw_ely_cls_flg      [1+1];	// X	1   ELW조기종료여부, Y,N 조기종료ELW 外 종목은 Default 'N' SET 2010.08.30
	int     elw_ely_cls_time          ;	// 9	6   ELW조기종료시간, HHMMSS, ELW조기종료여부가 'Y'인 경우만 설정
	int     cmpt_msv_dir_clsf         ;	// 9	1   경쟁대량 방향구분, 0:해당없음, 1:매도, 2:매수
	double  gen_bin_ccls_qty          ;	// 9	12  일반 Buy-in 체결수량, 단위:주
	double  gen_bin_ccls_trd_val      ;	// 9	18  일반 Buy-in 거래대금, 단위:원
	double  day_bin_ccls_qty          ;	// 9	12  당일 Buy-in 체결수량, 단위:주
	double  day_bin_ccls_trd_val      ;	// 9	18  당일 Buy-in 거래대금, 단위:원
	char    filler               [8+1];	// X	8   FILLER, SPACE
	char    ff                   [1+1];	// X	1   FF, END OF TEXT (0xFF)
} DFKOSPI_MKT_PRC_CLS;

// A6011 : 코스피_종목마감
typedef struct _DFKOSPI_STK_CLSG {
	char    data_clsf               [ 2+1];	// X	2   DATA구분, A6
	char    info_clsf               [ 2+1];	// X	2   정보구분, 01:주식 02:ELW
	char    mkt_clsf                [ 1+1];	// X	1   시장구분, 1:유가증권 2:코스닥
	char    isin_code               [12+1];	// X	12  종목코드, 표준코드
	int     snr                           ;	// 9	5   종목일련번호, 종목배치(A0)의 종목일련번호
	char    brd_id                  [ 2+1];	// X	2   보드ID, ※ 코드값모음 참조
	int     stk_cls_prc                   ;	// 9	9   종목마감종가, 정규시간외구분코드가 \n 1:정규장일때만 종목마감가격구분코드값이 SET 됨. \n 그외에는 SPACE
	char    stk_cls_prc_clsf_code   [ 1+1];	// X	1   종목마감가격구분코드, 1:체결가 \n 2:기세 \n 3:거래무 \n 4:시가기준가종목의 기세\n :정규장이 아닌 경우 SPACE
	int     ofhr_ceil                     ;	// 9	9   종목마감시간외단일가 상한가
	int     ofhr_flr                      ;	// 9	9   종목마감시간외단일가 하한가
	int     stk_cls_mwprc                 ;	// 9	9   종목마감평균가중주가
	int     dlv_base_prc                  ;	// 9	9   매입인도기준가격
	int     dlv_ceil                      ;	// 9	9   매입인도상한가
	int     dlv_flr                       ;	// 9	9   매입인도하한가
	char    filler                  [ 1+1];	// X	1   FILLER, SPACE
	char    ff                      [ 1+1];	// X	1   FF, END OF TEXT (0xFF)
} DFKOSPI_STK_CLSG;


// S F8011 : ETF PDF
typedef struct _DFETF_PDF {
	char    data_clsf               [ 2+1];	// X	2   DATA구분, F8
	char    info_clsf               [ 2+1];	// X	2   정보구분, 01:주식
	char    mkt_clsf                [ 1+1];	// X	1   시장구분, 1:유가증권
	char    isin_code               [12+1];	// X	12  ETF코드
	int     data_snr                      ;	// 9	8   데이터 일련번호, 전송일련번호
	char    date                    [ 8+1];	// X	8   일자, YYYYMMDD(적용일자)
	char    trb_nr                  [ 3+1];	// X	3   사무수탁회사번호, '903'한국예탁결제원,'049'미래에셋펀드서비스
	int     comp_stk_nr                   ; // 9	4   구성종목수, 단위:종목(현금을 포함)
	char    comp_stk_code           [12+1];	// X	12  구성종목코드, ※개발가이드 참조(CP 추가) 2015.03.03
	double  cu1_unit_scrt_nr              ;	// 9	18  "1CU단위증권수/계약수/원화현금", ※개발가이드 참조(외국환포워드 추가) 2014.06.16 \n표시형식:9999999999999999v99
	int     comp_stk_mkt_clsf             ;	// 9	1   구성종목시장구분, 0:유가증권(현금,KSP200T00001,FKSP200T0001포함)\n1:코스닥 2:기타 3:채권 4:선물 및 옵션 2018.02.05
	char    comp_stk_nm             [40+1];	// X	40  구성종목명, 해외종목일 경우 종목명, 그 외는 '0' 또는 SPACE
	double  par_val                       ;  	// 9	18  액면금액/설정현금액, ※개발가이드 참조(외국환포워드 추가) 2014.06.16
	char    profit_allc_base_date   [ 8+1];	// X	8   이익분배기준일, ※개발가이드 참조 2009.07.27
	double  assm_val                      ;	// 9	18  평가금액, PDF내 종목별 비중 산출 기초data 신규 2011.08.29
	char    filler                  [ 4+1];	// X	4   FILLER, 변경 2→4 2011.08.29
	char    ff                      [ 1+1];	// X	1   FF, END OF TEXT (0xFF)
} DFETF_PDF;

//Y 코스피_업종별투자자별	C0011	업종별투자자별
typedef struct _DFKOSPI_BYIND_BYINV {
	char    data_clsf       [2+1];	// X	2   DATA구분, C0
	char    info_clsf       [2+1];	// X	2   정보구분, 01:주식
	char    mkt_clsf        [1+1];	// X	1   시장구분, 1:유가증권 2:코스닥
	char    cmpt_time       [6+1];	// X	6   산출시각, 90초 주기
	char    inv_code        [4+1];	// X	4   투자자코드, ※코드값모음 참조\n*코드'7000'시 수량, 대금정보 항목 0으로 전송 (20181210)
	char    ind_code        [3+1];	// X	3   업종코드, ※코드값모음의 업종지수코드분류 참조\n산출업종;코스피종합지수, 코스닥종합지수, 코스피200지수
	double  ask_ccls_qty         ;	// 9	12  매도체결수량, 단위:주
	double  ask_trd_val          ;	// 9	18  매도거래대금, 단위:원
	double  bid_ccls_qty         ;	// 9	12  매수체결수량, 단위:주
	double  bid_trd_val          ;	// 9	18  매수거래대금, 단위:원
	char    filler          [7+1];	// X	7   FILLER, SPACE
	char    ff              [1+1];	// X	1   FF, END OF TEXT (0xFF)
} DFKOSPI_BYIND_BYINV;

//B6011 : 코스피_호가잔량_LP호가_제외 KOSPI_ASK_RSD_WOLP
typedef struct _DFKOSPI_ASK_RSD_WOLP {
	char    data_clsf           [2 +1];	// X	2   DATA구분, B6
	char    info_clsf           [2 +1];	// X	2   정보구분, 01:주식
	char    mkt_clsf            [1 +1];	// X	1   시장구분, 1:유가증권 2:코스닥
	char    isin_code           [12+1];	// X	12  종목코드, 표준코드
	int     stk_snr                   ;	// 9	5   5 종목일련번호, 종목배치(A0)의 종목일련번호
	double  cum_ccls_qty              ;	// 9	12  12 누적체결수량
	DF_TICK tick                [10  ];   //          호가 OCCURS 1010× 42 = 420
	double  ask_tot_rsd_10            ;	// 9	12  10단계호가매도총잔량
	double  bid_tot_rsd_10            ;	// 9	12  10단계호가매수총잔량
	char    filler1             [12+1];	// 9	12  FILLER
	char    filler2             [12+1];	// 9	12  FILLER
	double  ofhr_ask_tot_rsd          ;	// 9	12  장종료후시간외 매도총호가잔량, 보드ID가 ""G3""일 경우 설정됨
	double  ofhr_bid_tot_rsd          ;	// 9	12  장종료후시간외 매수총호가잔량, 보드ID가 ""G3""일 경우 설정됨
	char    sess_id             [2 +1];	// X	2   세션ID, ※ 코드값모음 참조
	char    brd_id              [2 +1];	// X	2   보드ID, ※ 코드값모음 참조
	int     exp_ccls_prc              ;   // 9	9   예상체결가격
	double  exp_ccls_qty              ;	// 9	12  예상체결수량
	int     cmpt_msv_dir_clsf         ;	// 9	1   경쟁대량 방향구분, 0:해당없음, 1:매도, 2:매수
	char    filler3             [7 +1];	// X	7   FILLER, SPACE
	char    ff                  [1 +1];	// X	1   FF,      END OF TEXT (0xFF)
} DFKOSPI_ASK_RSD_WOLP;


//B7011 : 코스피_호가잔량_LP호가_포함 KOSPI_ASK_RSD_WLP
typedef struct _DFKOSPI_ASK_RSD_WLP {
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
} DFKOSPI_ASK_RSD_WLP;

    
// 코스피_체결 A3011 int 9 double 10 ~
typedef struct _DFKOSPI_CCLS {
	char    data_clsf        [2+1];    	    // DATA구분, A3
	char    info_clsf        [2+1];	        // 정보구분, 01:주식 02:ELW
	char    mkt_clsf         [1+1];	        // 시장구분, 1:유가증권 2:코스닥
	char    isin_code       [12+1];	        // 종목코드, 표준코드
	int     stk_snr               ;	        // 종목일련번호, 종목배치(A0)의 종목일련번호
	char    brd_id          [ 2+1];	        // 보드ID, ※ 코드값모음 참조
	char    ctrs_clsf       [ 1+1];	        // "전일대비(기준가대비) 구분", 0:판단불가 1:상한 2:상승 3:보합 4:하한 5:하락\n ※ 정규시간외구분코드 값이 4인 경우 당일 종가 대비\n ※ 정규시간외구분값이비
	int     prev_ctrs             ;	        // 전일대비, 단위:원 신주인수권 증서/증권의 신규 상장 당일 : 0
	int     ccls_prc              ;	        // 체결가격, 단위:원
	double  ccls_qty              ;	        // 체결수량, 단위:주
	char    sess_id         [ 2+1];	        // 세션ID, ※ 코드값모음 참조
	int     open                  ;	        // 시가, 단위:원 ※개발가이드 참조
	int     high                  ;	        // 고가, 단위:원 ※개발가이드 참조
	int     low                   ;	        // 저가, 단위:원 ※개발가이드 참조
	double  cum_ccls_qty          ;	        // 누적체결수량, 단위:주 ※보드ID별로 누적됨
	double  cum_trd_val           ;	        // 누적거래대금, 단위:원 ※보드ID별로 누적됨
	char    fin_bid_ask_clsf_code[1+1];     // 최종매도매수구분코드, 1:매도 2:매수
	char    mtc_flg         [ 1+1];	        // 체결가와1호가일치여부, 0:판단불가 1:일치 2:불일치
	char    ccls_time       [ 6+1];	        // 체결시각, HHMMSS
	double  lp_hld_qty          ;	        // LP보유수량, LP(체결기준) 집계후 LP보유수량\n음수발생 가능(ETN만 해당)(2018.09.17)
	int     ask_1_prc           ;	        // 매도1호가, 단위:원 ※개발가이드 참조
	int     bid_1_prc           ;	        // 매수1호가, 단위:원 ※개발가이드 참조
	char    filler[6]           ;	        // FILLER, SPACE
	char    ff[1]               ;	            // FF, END OF TEXT (0xFF)
} DFKOSPI_CCLS;

#endif
