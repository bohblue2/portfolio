#ifndef _STKPK_H_
#define _STKPK_H_

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

int StkProcA3011(char *buff);
int StkProcB4011(char *buff);
int StkProcB6011(char *buff);
int StkProcB7011(char *buff);
int StkProcC0011(char *buff);

int StkProcA3021(char *buff);
int StkProcB7021(char *buff);

int StkProcF8011(char *buff);
int StkProcA6011(char *buff);
int StkProcB1011(char *buff);

int StkProcB1021(char *buff);
int StkProcA6021(char *buff);

PROC_LIST AppList[] = {
{"A3011",     StkProcA3011, "KOSPI_CCLS"            },
{"B6011",     StkProcB6011, "KOSPI_ASK_RSD_WOLP"    },
{"B7011",     StkProcB7011, "KOSPI_ASK_RSD_WLP"     },
{"C0011",     StkProcC0011, "KOSPI_BYIND_BYINV"     },
{"B4011",     StkProcB4011, "KOSPI_OFH_RCVR"        },
{"A3021",     StkProcA3021, "ELW_CCLS"              },
{"B7021",     StkProcB7021, "ELW_ASK_RSD_WLP"       },
{"F8011",     StkProcF8011, "ETF_PDF"               },
{"A6011",     StkProcA6011, "KOSPI_STK_CLSG"        },        // A6011 : 코스피_종목마감
{"B1011",     StkProcB1011, "KOSPI_MKT_PRC_CLS"     },        // B1011 : 코스피_시세종가
{"B1021",     StkProcB1021, "ELW_MKT_PRC_CLS"       },        // B1021 : ELW_시세종가
{"A6021",     StkProcA6021, "ELW_MKT_PRC_CLS"       },        // B1021 : ELW_시세종가
};

#define AP_CNT	( sizeof(AppList)/sizeof(PROC_LIST))

#endif                    

// A6021 : ELW_종목마감
typedef struct _ELW_STK_CLSG {
	char    data_clsf             [2];	// X	2   DATA구분, A6
	char    info_clsf             [2];	// X	2   정보구분, 01:주식 02:ELW
	char    mkt_clsf              [1];	// X	1   시장구분, 1:유가증권 2:코스닥
	char    isin_code            [12];	// X	12  종목코드, 표준코드
	char    snr                   [5];	// 9	5   종목일련번호, 종목배치(A0)의 종목일련번호
	char    brd_id                [2];	// X	2   보드ID, ※ 코드값모음 참조
	char    stk_cls_prc           [9];	// 9	9   종목마감종가, 정규시간외구분코드가 \n 1:정규장일때만 종목마감가격구분코드값이 SET 됨. \n 그외에는 SPACE
	char    stk_cls_prc_clsf_code [1];	// X	1   종목마감가격구분코드, 1:체결가 \n 2:기세 \n 3:거래무 \n 4:시가기준가종목의 기세\n :정규장이 아닌 경우 SPACE
	char    ofhr_hi               [9];	// 9	9   "종목마감시간외단일가 상한가"
	char    ofhr_lo               [9];	// 9	9   "종목마감시간외단일가 하한가"
	char    stk_cls_mwprc         [9];	// 9	9   종목마감평균가중주가
	char    dlv_base_prc          [9];	// 9	9   매입인도기준가격
	char    dlv_hi                [9];	// 9	9   매입인도상한가
	char    dlv_lo                [9];	// 9	9   매입인도하한가
	char    filler                [1];	// X	1   FILLER, SPACE
	char    ff                    [1];	// X	1   FF, END OF TEXT (0xFF)
} ELW_STK_CLSG;

    
// B1021 : ELW_시세종가
typedef struct _ELW_MKT_PRC_CLS {
	char    data_clsf            [2];	// X	2  DATA구분, B1:종가 B2:시세REC
	char    info_clsf            [2];	// X	2  정보구분, 01:주식 02:ELW
	char    mkt_clsf             [1];	// X	1  시장구분, 1:유가증권 2:코스닥
	char    isin_code           [12];	// X	12 종목코드, 표준코드
	char    stk_snr              [5];	// 9	5  종목일련번호, 종목배치(A0)의 종목일련번호
	char    flct_clsf            [1];	// X	1  등락구분, 0:판단불가 1:상한 2:상승 3:보합 4:하한 5:하락
	char    prev_ctrs            [9];	// 9	9  전일대비, 단위:원
	char    cur_prc              [9];	// 9	9  현재가
	char    open                 [9];	// 9	9  시가, 정규장 시가
	char    high                 [9];	// 9	9  고가, 정규장 고가
	char    low                  [9];	// 9	9  저가, 정규장 저가
	char    ask_prc              [9];	// 9	9  매도호가, B1시 0값 SET
	char    bid_prc              [9];	// 9	9  매수호가, B1시 0값 SET
	char    cum_ccls_qty        [12];	// 9	12 누적체결수량, 단위:주 ※시간외단일가, BUY-IN을 제외한 모든 체결수량 합산
	char    cum_trd_val         [18];	// 9	18 누적거래대금, 단위:원 ※시간외단일가, BUY-IN을 제외한 모든 거래대금 합산
	char    trend_flg            [1];	// X	1  실세/기세 구분, 0:초기값 1:실세 2:기세 3:거래무 4:시가기준가종목의 기세
	char    brd_evt_id           [3];	// X	3  보드이벤트ID, B1/B2 에서는 보드이벤트ID 사용금지(과거 상태값이 전송될 수 있음). 추후, 해당 항목 '000' 세팅 예정. 2014.03.24)
	char    brd_id               [2];	// X	2  보드ID, ※ 코드값모음 참조
	char    trsp_flg             [1];	// X	1  거래정지여부, Y, N
	char    bopen_ofhr_ccls_qty [12];	// 9	12 "장개시전시간외종가 체결수량", 대량, 바스켓은 제외, 단위:주
	char    bopen_ofhr_trd_val  [18];	// 9	18 "장개시전시간외종가 거래대금", 대량, 바스켓은 제외, 단위:원
	char    opr_time_ccls_qty   [12];	// 9	12 정규장체결수량, 대량, 바스켓은 제외, 단위:주
	char    opr_time_trd_val    [18];	// 9	18 정규장거래대금, 대량, 바스켓은 제외, 단위:원
	char    ofhr_cls_ccls_qty   [12];	// 9	12 "장종료후시간외종가 체결수량", 대량, 바스켓은 제외, 단위:주
	char    ofhr_cls_trd_val    [18];	// 9	18 "장종료후시간외종가 거래대금", 대량, 바스켓은 제외, 단위:원
	char    elw_ely_cls_flg      [1];	// X	1  ELW조기종료여부, Y,N 조기종료ELW 外 종목은 Default 'N' SET
	char    elw_ely_cls_time     [6];	// 9	6  ELW조기종료시간, HHMMSS, ELW조기종료여부가 'Y'인 경우만 설정
	char    cmpt_msv_dir_clsf    [1];	// 9	1  경쟁대량 방향구분, 0:해당없음, 1:매도, 2:매수
	char    gen_bin_ccls_qty    [12];	// 9	12 일반 Buy-in 체결수량, 단위:주
	char    gen_bin_ccls_trd_val[18];	// 9	18 일반 Buy-in 거래대금, 단위:원
	char    day_bin_ccls_qty    [12];	// 9	12 당일 Buy-in 체결수량, 단위:주
	char    day_bin_ccls_trd_val[18];	// 9	18 당일 Buy-in 거래대금, 단위:원
	char    filler               [8];	// X	8  FILLER, SPACE
	char    ff                   [1];	// X	1  FF, END OF TEXT (0xFF)
} ELW_MKT_PRC_CLS;
    
// B1011 : 코스피_시세종가
typedef struct _KOSPI_MKT_PRC_CLS {
	char    data_clsf            [2];	// X	2   DATA구분, B1:종가 B2:시세REC
	char    info_clsf            [2];	// X	2   정보구분, 01:주식 02:ELW
	char    mkt_clsf             [1];	// X	1   시장구분, 1:유가증권 2:코스닥
	char    isin_code           [12];	// X	12  종목코드, 표준코드
	char    stk_snr              [5];	// 9	5   종목일련번호, 종목배치(A0)의 종목일련번호
	char    flct_clsf            [1];	// X	1   등락구분, 0:판단불가 1:상한 2:상승 3:보합 4:하한 5:하락
	char    prev_ctrs            [9];	// 9	9   전일대비, 단위:원
	char    cur_prc              [9];	// 9	9   현재가
	char    open                 [9];	// 9	9   시가, 정규장 시가
	char    high                 [9];	// 9	9   고가, 정규장 고가
	char    low                  [9];	// 9	9   저가, 정규장 저가
	char    ask_prc              [9];	// 9	9   매도호가, B1시 0값 SET
	char    bid_prc              [9];	// 9	9   매수호가, B1시 0값 SET
	char    cum_ccls_qty        [12];	// 9	12  누적체결수량, 단위:주 ※시간외단일가, BUY-IN을 제외한 모든 체결수량 합산
	char    cum_trd_val         [18];	// 9	18  누적거래대금, 단위:원 ※시간외단일가, BUY-IN을 제외한 모든 거래대금 합산
	char    trend_flg            [1];	// X	1   실세/기세 구분, 0:초기값 1:실세 2:기세 3:거래무 4:시가기준가종목의 기세
	char    brd_evt_id           [3];	// X	3   보드이벤트ID, B1/B2 에서는 보드이벤트ID 사용금지(과거 상태값이 전송될 수 있음). 추후, 해당 항목 '000' 세팅 예정. 2014.03.24)
	char    brd_id               [2];	// X	2   보드ID, ※ 코드값모음 참조
	char    trsp_flg             [1];	// X	1   거래정지여부, Y, N
	char    bopen_ofhr_ccls_qty [12];	// 9	12  "장개시전시간외종가 체결수량", 대량, 바스켓은 제외, 단위:주
	char    bopen_ofhr_trd_val  [18];	// 9	18  "장개시전시간외종가 거래대금", 대량, 바스켓은 제외, 단위:원
	char    opr_time_ccls_qty   [12];	// 9	12  정규장체결수량, 대량, 바스켓은 제외, 단위:주
	char    opr_time_trd_val    [18];	// 9	18  정규장거래대금, 대량, 바스켓은 제외, 단위:원
	char    ofhr_cls_ccls_qty   [12];	// 9	12  "장종료후시간외종가 체결수량", 대량, 바스켓은 제외, 단위:주
	char    ofhr_cls_trd_val    [18];	// 9	18  "장종료후시간외종가 거래대금", 대량, 바스켓은 제외, 단위:원
	char    elw_ely_cls_flg      [1];	// X	1   ELW조기종료여부, Y,N 조기종료ELW 外 종목은 Default 'N' SET 2010.08.30
	char    elw_ely_cls_time     [6];	// 9	6   ELW조기종료시간, HHMMSS, ELW조기종료여부가 'Y'인 경우만 설정
	char    cmpt_msv_dir_clsf    [1];	// 9	1   경쟁대량 방향구분, 0:해당없음, 1:매도, 2:매수
	char    gen_bin_ccls_qty    [12];	// 9	12  일반 Buy-in 체결수량, 단위:주
	char    gen_bin_ccls_trd_val[18];	// 9	18  일반 Buy-in 거래대금, 단위:원
	char    day_bin_ccls_qty    [12];	// 9	12  당일 Buy-in 체결수량, 단위:주
	char    day_bin_ccls_trd_val[18];	// 9	18  당일 Buy-in 거래대금, 단위:원
	char    filler               [8];	// X	8   FILLER, SPACE
	char    ff                   [1];	// X	1   FF, END OF TEXT (0xFF)
} KOSPI_MKT_PRC_CLS;


// A6011 : 코스피_종목마감
typedef struct _KOSPI_STK_CLSG {
	char    data_clsf               [ 2];	// X	2   DATA구분, A6
	char    info_clsf               [ 2];	// X	2   정보구분, 01:주식 02:ELW
	char    mkt_clsf                [ 1];	// X	1   시장구분, 1:유가증권 2:코스닥
	char    isin_code               [12];	// X	12  종목코드, 표준코드
	char    snr                     [ 5];	// 9	5   종목일련번호, 종목배치(A0)의 종목일련번호
	char    brd_id                  [ 2];	// X	2   보드ID, ※ 코드값모음 참조
	char    stk_cls_prc             [ 9];	// 9	9   종목마감종가, 정규시간외구분코드가 \n 1:정규장일때만 종목마감가격구분코드값이 SET 됨. \n 그외에는 SPACE
	char    stk_cls_prc_clsf_code   [ 1];	// X	1   종목마감가격구분코드, 1:체결가 \n 2:기세 \n 3:거래무 \n 4:시가기준가종목의 기세\n :정규장이 아닌 경우 SPACE
	char    ofhr_ceil               [ 9];	// 9	9   종목마감시간외단일가 상한가
	char    ofhr_flr                [ 9];	// 9	9   종목마감시간외단일가 하한가
	char    stk_cls_mwprc           [ 9];	// 9	9   종목마감평균가중주가
	char    dlv_base_prc            [ 9];	// 9	9   매입인도기준가격
	char    dlv_ceil                [ 9];	// 9	9   매입인도상한가
	char    dlv_flr                 [ 9];	// 9	9   매입인도하한가
	char    filler                  [ 1];	// X	1   FILLER, SPACE
	char    ff                      [ 1];	// X	1   FF, END OF TEXT (0xFF)
} KOSPI_STK_CLSG;

// S F8011 : ETF PDF
typedef struct _ETF_PDF {
	char    data_clsf               [ 2];	// X	2   DATA구분, F8
	char    info_clsf               [ 2];	// X	2   정보구분, 01:주식
	char    mkt_clsf                [ 1];	// X	1   시장구분, 1:유가증권
	char    isin_code               [12];	// X	12  ETF코드
	char    data_snr                [ 8];	// 9	8   데이터 일련번호, 전송일련번호
	char    date                    [ 8];	// X	8   일자, YYYYMMDD(적용일자)
	char    trb_nr                  [ 3];	// X	3   사무수탁회사번호, '903'한국예탁결제원,'049'미래에셋펀드서비스
	char    comp_stk_nr             [ 4];	// 9	4   구성종목수, 단위:종목(현금을 포함)
	char    comp_stk_code           [12];	// X	12  구성종목코드, 개발가이드 참조(CP 추가) 2015.03.03
	char    cu1_unit_scrt_nr        [18];	// 9	18  "1CU단위증권수/계약수/원화현금", 개발가이드 참조(외국환포워드 추가) 2014.06.16 \n표시형식:9999999999999999v99
	char    comp_stk_mkt_clsf       [ 1];	// 9	1   구성종목시장구분, 0:유가증권(현금,KSP200T00001,FKSP200T0001포함)\n1:코스닥 2:기타 3:채권 4:선물 및 옵션 2018.02.05
	char    comp_stk_nm             [40];	// X	40  구성종목명, 해외종목일 경우 종목명, 그 외는 '0' 또는 SPACE
	char    par_val                 [18];	// 9	18  액면금액/설정현금액, 개발가이드 참조(외국환포워드 추가) 2014.06.16
	char    profit_allc_base_date   [ 8];	// X	8   이익분배기준일, 개발가이드 참조 2009.07.27
	char    assm_val                [18];	// 9	18  평가금액, PDF내 종목별 비중 산출 기초data 신규 2011.08.29
	char    filler                  [ 4];	// X	4   FILLER, 변경 2→4 2011.08.29
	char    ff                      [ 1];	// X	1   FF, END OF TEXT (0xFF)
} ETF_PDF;


// Y 코스피_업종별투자자별	C0011	업종별투자자별
typedef struct _KOSPI_BYIND_BYINV {
	char    data_clsf       [2 ];	// X	2   DATA구분, C0
	char    info_clsf       [2 ];	// X	2   정보구분, 01:주식
	char    mkt_clsf        [1 ];	// X	1   시장구분, 1:유가증권 2:코스닥
	char    cmpt_time       [6 ];	// X	6   산출시각, 90초 주기
	char    inv_code        [4 ];	// X	4   투자자코드, 코드값모음 참조\n*코드'7000'시 수량, 대금정보 항목 0으로 전송 (20181210)
	char    ind_code        [3 ];	// X	3   업종코드, 코드값모음의 업종지수코드분류 참조\n산출업종;코스피종합지수, 코스닥종합지수, 코스피200지수
	char    ask_ccls_qty    [12];	// 9	12  매도체결수량, 단위:주
	char    ask_trd_val     [18];	// 9	18  매도거래대금, 단위:원
	char    bid_ccls_qty    [12];	// 9	12  매수체결수량, 단위:주
	char    bid_trd_val     [18];	// 9	18  매수거래대금, 단위:원
	char    filler          [7 ];	// X	7   FILLER, SPACE
	char    ff              [1 ];	// X	1   FF, END OF TEXT (0xFF)
} KOSPI_BYIND_BYINV;


//B6011 : 코스피_호가잔량_LP호가_제외 KOSPI_ASK_RSD_WOLP
//B7011 : 코스피_호가잔량_LP호가_포함 KOSPI_ASK_RSD_WLP

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

//B6011 : 코스피_호가잔량_LP호가_제외 KOSPI_ASK_RSD_WOLP
typedef struct _KOSPI_ASK_RSD_WOLP {
	char data_clsf          [2 ];	// DATA구분, B6
	char info_clsf          [2 ];	// 정보구분, 01:주식
	char mkt_clsf           [1 ];	// 시장구분, 1:유가증권 2:코스닥
	char isin_code          [12];	// 종목코드, 표준코드
	char stk_snr            [5 ];	// 종목일련번호, 종목배치(A0)의 종목일련번호
	char cum_ccls_qty       [12];	// 누적체결수량
	PK_TICK tick            [10];   // 호가 OCCURS 1010× 42 = 420
	char ask_tot_rsd_10[12];	// 10단계호가매도총잔량
	char bid_tot_rsd_10[12];	// 10단계호가매수총잔량
	char filler1[12];	// FILLER
	char filler2[12];	// FILLER
	char ofhr_ask_tot_rsd[12];	// 장종료후시간외 매도총호가잔량, 보드ID가 ""G3""일 경우 설정됨
	char ofhr_bid_tot_rsd[12];	// 장종료후시간외 매수총호가잔량, 보드ID가 ""G3""일 경우 설정됨
	char sess_id[2];	// 세션ID,  코드값모음 참조
	char brd_id[2];	// 보드ID,  코드값모음 참조
	char exp_ccls_prc[9];	// 예상체결가격
	char exp_ccls_qty[12];	// 예상체결수량
	char cmpt_msv_dir_clsf[1];	// 경쟁대량 방향구분, 0:해당없음, 1:매도, 2:매수
	char filler3[7];	// FILLER, SPACE
	char ff[1];	// FF, END OF TEXT (0xFF)
} KOSPI_ASK_RSD_WOLP;


//B7011 : 코스피_호가잔량_LP호가_포함 KOSPI_ASK_RSD_WLP
typedef struct _KOSPI_ASK_RSD_WLP {
	char data_clsf[2];	// DATA구분, B7
	char info_clsf[2];	// 정보구분, 01:유가증권종목 02:ELW
	char mkt_clsf[1];	// 시장구분, 1:유가증권
	char isin_code[12];	// 종목코드, 표준코드
	char stk_snr[5];	// 종목일련번호, 종목배치(A0)의 종목일련번호
	char cum_ccls_qty[12];	// 누적체결수량
	PK_TICKLP ticklp[10];  // 호가 OCCURS 1010× 66 = 660
	char ask_tot_rsd_10[12];	// 10단계호가매도총잔량
	char bid_tot_rsd_10[12];	// 10단계호가매수총잔량
	char filler1[12];	// FILLER
	char filler2[12];	// FILLER
	char ofhr_ask_tot_rsd[12];	// 장종료후시간외 매도총호가잔량, 보드ID가 ""G3""일 경우 설정됨 \n ELW는 시간외거래 없음
	char ofhr_bid_tot_rsd[12];	// 장종료후시간외 매수총호가잔량, 보드ID가 ""G3""일 경우 설정됨\n ELW는 시간외거래 없음
	char sess_id[2];	// 세션ID,  코드값모음 참조
	char brd_id[2];	// 보드ID,  코드값모음 참조
	char exp_ccls_prc[9];	// 예상체결가격
	char exp_ccls_qty[12];	// 예상체결수량
	char cmpt_msv_dir_clsf[1];	// 경쟁대량 방향구분, 0:해당없음, 1:매도, 2:매수
	char filler3[7];	// FILLER, SPACE
	char ff[1];	// FF, END OF TEXT (0xFF)
} KOSPI_ASK_RSD_WLP;

    
// 코스피_체결 A3011
typedef struct _KOSPI_CCLS {
	char data_clsf[2];	            // DATA구분, A3
	char info_clsf[2];	            // 정보구분, 01:주식 02:ELW
	char mkt_clsf[1];	            // 시장구분, 1:유가증권 2:코스닥
	char isin_code[12];	            // 종목코드, 표준코드
	char stk_snr[5];	            // 종목일련번호, 종목배치(A0)의 종목일련번호
	char brd_id[2];	                // 보드ID, 코드값모음 참조
	char ctrs_clsf[1];	            // 
	char prev_ctrs[9];	            // 전일대비, 단위:원 신주인수권 증서/증권의 신규 상장 당일 : 0
	char ccls_prc[9];	            // 체결가격, 단위:원
	char ccls_qty[10];	            // 체결수량, 단위:주
	char sess_id[2];	            // 세션ID, 코드값모음 참조
	char open[9];	                // 시가, 단위:원 개발가이드 참조
	char high[9];                   // 고가, 단위:원 개발가이드 참조
	char low[9];	                // 저가, 단위:원 개발가이드 참조
	char cum_ccls_qty[12];	        // 누적체결수량, 단위:주 보드ID별로 누적됨
	char cum_trd_val[18];	        // 누적거래대금, 단위:원 보드ID별로 누적됨
	char fin_bid_ask_clsf_code[1];	// 최종매도매수구분코드, 1:매도 2:매수
	char mtc_flg[1];	            // 체결가와1호가일치여부, 0:판단불가 1:일치 2:불일치
	char ccls_time[6];	            // 체결시각, HHMMSS
	char lp_hld_qty[15];	        // LP보유수량, LP(체결기준) 집계후 LP보유수량\n음수발생 가능(ETN만 해당)(2018.09.17)
	char ask_1_prc[9];	            // 매도1호가, 단위:원 개발가이드 참조
	char bid_1_prc[9];	            // 매수1호가, 단위:원 개발가이드 참조
	char filler[6];	                // FILLER, SPACE
	char ff[1];	                    // FF, END OF TEXT (0xFF)
} KOSPI_CCLS;

// 코스피_시간외단일가_리커버리 B4011
typedef struct _KOSPI_OFH_RCVR {
	char data_clsf[2];	// DATA구분, B4:시간외단일가 시세, B3:시간외단일가최종
	char info_clsf[2];	// 정보구분, 01:주식
	char mkt_clsf[1];	// 시장구분, 1:유가증권 2:코스닥
	char isin_code[12];	// 종목코드, 표준코드
	char stk_snr[5];	// 종목일련번호, 종목배치(A0)의 종목일련번호 2014.03.03
	char ofhr_cnst_clsf[1];	// 시간외단일가대비구분, 0:판단불가 1:상한 2:상승 3:보합 4:하한 5:하락
	char ofhr_cnst[9];	// 시간외단일가대비, 단위:원
	char ofhr_cnst_ceil[9];	// 시간외단일가상한가
	char ofhr_cnst_flr[9];	// 시간외단일가하한가
	char ofhr_cnst_cur[9];	// 시간외단일가현재가
	char ofhr_cnst_open[9];	// 시간외단일가시가
	char ofhr_cnst_hi[9];	// 시간외단일가고가
	char ofhr_cnst_lo[9];	// 시간외단일가저가
	char ofhr_cnst_ask[9];	// 시간외단일가매도호가
	char ofhr_cnst_bid[9];	// 시간외단일가매수호가
	char ofhr_cnst_cum_ccls_qty[12];	// "시간외단일가누적 체결수량"
	char ofhr_cnst_cum_trd_val[18];	// "시간외단일가누적 거래대금"
	char tot_cum_ccls_qty[12];	// 전체 총 누적체결수량, 단위:주 당일 전체 누적
	char tot_cum_trd_val[18];	// 전체 총 누적거래대금, 단위:원 당일 전체 누적
	char ofhr_mkt_clsf[1];	// 시간외단일가장구분, 0:초기값 1:시간외단일가개시 2:시간외단일가마감
	char trsp_flg[1];	// 거래정지여부, Y, N
	char trend_flg[1];	// 실세/기세 구분, 0:초기값 1:실세 2:기세 3:거래무 4:시가기준가종목의 기세
	char filler[2];	// FILLER, SPACE
	char ff[1];	// FF, END OF TEXT (0xFF)
} KOSPI_OFH_RCVR;

#endif
