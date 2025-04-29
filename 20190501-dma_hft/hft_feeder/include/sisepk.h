/*
 * 설명   : 증권전산 Packet
 * NAME   : sisepk.h
 * DATE   : 2003-10-02 2:10오후(최종변경)
 * By     : 배성남
 * Remark :
 */
/* -------------------------------------------------------------------------- *
   2004.11.29.
      서비스 ip변경 (recovery ip포함)
          장내/코스닥/선물/옵션
          -  운영시스템 : 210.108.26.63/210.108.26.158 -> 210.108.26.57
          -  백업시스템 : 210.108.26.56
          -  테스트시스템 : 210.108.26.58
         주식옵션
          -  운영시스템 : 210.108.26.158 -> 210.108.26.57
          -  백업시스템 : 210.108.26.56
          -  테스트시스템 : 210.108.26.58
         공시
          -  운영시스템 : 210.108.26.63 -> 210.108.26.57
          -  백업시스템 : 210.108.26.56
          -  테스트시스템 : 210.108.26.58
         ECN
          -  운영시스템 : 210.108.26.56 -> 210.108.26.57
          -  백업시스템 : 210.108.26.56
          -  테스트시스템 : 210.108.26.58
     포트변경
         주식옵션 : 15195

     recovery ip/포트변경
          -  장내/코스닥        : 15000 ~ 15002
          -  선물/옵션/주식옵션 : 16000 ~ 16002
          -  ECN  : 19000
          -  공시 : 18000


2006-10-16
	IP변경
	  - 210.108.26.57 -> 210.108.26.68

	포트변경
	  - 거래소/코스닥      15XX1/15XX4 -> 16XX1/16XX4
	  - 선물/옵션/         15XX2/15XX3 -> 16XX2/16XX3
	  - 주식옵션/스타선물  15XX5/15XX6 -> 16XX5/16XX6
	  - 공시               180XX       -> 181XX

 * -------------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>

#ifndef __SISEPK_H__
#define __SISEPK_H__

/* ========================================================================== */
/* 증전수신포트 */
#define  KOSPI_PORT        16191
#define  FUTURE_PORT       16192
#define  OPTION_PORT       16193
#define  KOSDAQ_PORT       16194
#define  STOPTION_PORT     16195
#define  NOTICE_PORT       18122

/* ========================================================================== */
/* 로컬 리커버리 Proxy 서버 */
#define  RECOVER_PORT      25000         /* 장내/코스닥          */
#define  RECOVER_PORT_SO   26000         /* 주식옵션             */
#define  RECOVER_PORT_FU   26001         /* 선물                 */
#define  RECOVER_PORT_OP   26002         /* 옵션                 */
#define  RECOVER_PORT_EL   7300          /* ELW                  */
#define  RECOVER_PORT_SF   7300          /* 주식선물             */
#define  RECOVER_PORT_MK   7300          /* 주식선물             */
#define  RECOVER_PORT_NT   28000         /* 공시                 */

#define  RECOVER_ADDR      "10.101.32.197"


#if 0 /************************************************************************/

/* 증전 리커버리 서버 */
#define  REAL_RECOVER_PORT    15000      /* 장내/코스닥          */
#define  REAL_RECOVER_PORT_SO 16000      /* 주식옵션             */
#define  REAL_RECOVER_PORT_FU 16001      /* 선물                 */
#define  REAL_RECOVER_PORT_OP 16002      /* 옵션                 */
#define  REAL_RECOVER_PORT_NT 18000      /* 공시                 */

#define  REAL_RECOVER_ADDR    "210.108.26.68"
#define  REAL_RECOVER_ADDR_SO "210.108.26.68"

#endif /***********************************************************************/

#define  REAL_RECOVER_PORT    7300      /* 장내/코스닥           */
#define  REAL_RECOVER_PORT_SO 7300      /* 주식옵션              */
#define  REAL_RECOVER_PORT_FU 7300      /* 선물                  */
#define  REAL_RECOVER_PORT_OP 7300      /* 옵션                  */
#define  REAL_RECOVER_PORT_EL 7300      /* ELW                   */
#define  REAL_RECOVER_PORT_SF 7300      /* 주식선물              */
#define  REAL_RECOVER_PORT_MK 7300      /* 상품선물              */
#define  REAL_RECOVER_PORT_NT 7300      /* 공시                  */

#define  REAL_RECOVER_ADDR    "125.209.203.66"
#define  REAL_RECOVER_ADDR_SO "125.209.203.66"

/* ========================================================================== */
/*
** 마켓포인트 시세 처리서버 "125.209.203.66~67"
*/
#define  MAKETPOINT_ADDR1      	"125.209.203.66"
#define  MAKETPOINT_ADDR2      	"10.101.32.67"

#define  MAKET_KOSPI_PORT        7301    /* 거래소               */
#define  MAKET_KOSDAQ_PORT       7302    /* 코스닥               */
#define  MAKET_FUTURE_PORT       7303    /* 선물                 */
#define  MAKET_OPTION_PORT       7304    /* 옵션                 */
#define  MAKET_STOPTION_PORT     7305    /* 주식옵션             */
#define  MAKET_ELW_PORT          7306    /* ELW                  */
#define  MAKET_STFU_PORT         7307    /* 주식선물             */
#define  MAKET_MKFU_PORT         7308    /* 상품선물             */
#define  MAKET_NOTICE_PORT       7309    /* 공시                 */

/*
#define  MAKET_RECOVER_ADDR      "125.209.203.66"
#define  MAKET_RECOVER_PORT      7300
*/
#define  MAKET_RECOVER_ADDR      "10.101.32.197"
#define  MAKET_RECOVER_PORT      17300

/* ========================================================================== */
#define  HEADER_PK_ID      0x98          /* Header Packet        */
#define  FOOTER_PK_ID      0x99          /* Footer packet        */

#define  KOSPIMST_PK_ID    0x02          /* 장내   종목 마스터   */
#define  KOSDAQMST_PK_ID   0x13          /* 코스닥 종목 마스터   */
#define  KOSPIUPMST_PK_ID  0x03          /* KOSPI    업종 마스터 */
#define  KOSPI200MST_PK_ID 0x04          /* KOSPI200 업종 마스터 */
#define  KOSPI50MST_PK_ID  0x08          /* KOSPI50  업종 마스터 */
#define  KOSDAQUPMST_PK_ID 0x05          /* KOSDAQ   업종 마스터 */
#define  KOSDAQ50MST_PK_ID 0x06          /* KOSDAQ50 업종 마스터 */

#define  KOSPIREAL_PK_ID   'S'           /* 장내   종목 시세     */
#define  KOSPIREAL2_PK_ID  's'           /* 장내   종목 시세2    */
#define  KOSPIBASE_PK_ID   'M'           /* 장내   종목 공개정보 */
#define  KOSDAQREL_PK_ID   0xa1          /* 코스닥 종목 시세     */
#define  KOSDAQREL2_PK_ID  'r'           /* 코스닥 종목 시세2    */
#define  KOSPIUP_PK_ID     'J'           /* 장내     업종지수    */
#define  KOSPI200_PK_ID    'I'           /* KOSPI200 지수        */
#define  KOSPI200UP_PK_ID  'y'           /* KOSPI200 업종지수    */
#define  KOSPI50_PK_ID     'N'           /* KOSPI50  업종지수    */
#define  KOSDAQUP_PK_ID    'O'           /* 코스닥   업종지수    */
#define  KOSDAQ50_PK_ID    'L'           /* KOSDAQ50 업종지수    */

#define  KOSDAQSTAR_PK_ID  'j'           /* KOSTAR지수           */
#define  KOSPI50_PK_ID     'N'           /* KOSPI50업종 지수     */
#define  KOSPIKD_PK_ID     'K'           /* KOSPIKODI배당지수    */
#define  KOSPICOMP_PK_ID   'Z'           /* 지배구조우수기업지수 */

#define  KOSPIUPEXP_PK_ID  'V'           /* KOSPIUP예상지수      */
#define  KOSPI200UPEXP_PK_ID	'W'      /* KOSPI200UP예상지수   */
#define  KOSPIKDEXP_PK_ID  'Y'           /* KOSPIKODI예상지수    */
#define  KOSDAQUPEXP_PK_ID 'X'           /* KOSDAQ업종예상지수   */
#define  KOSDAQ50EXP_PK_ID 'U'           /* KOSDAQ50업종예상지수 */

#define  KOSPIUPUD_PK_ID   'D'           /* KOSPI  업종 등락     */
#define  KOSPI200UD_PK_ID  'T'           /* KOSPI200 등락        */
#define  KOSDAQUD_PK_ID    0xd1          /* KOSDAQ   등락        */

#define  KOSPIETFNAV_PK_ID 'i'           /* ETF 장중/최종 NAV    */
#define  KOSPIETFPDF_PK_ID 'P'           /* ETF PDF              */
#define  KOSDAQETFNAV_PK_ID 'Q'          /* ETF 장중/최종 NAV    */
#define  KOSDAQETFPDF_PK_ID 'R'          /* ETF PDF              */

#define  KOSSUMJISU_PK_ID    'E'         /* 통합지수             */
#define  KOSSUMJISUEXP_PK_ID 'H'         /* 통합예상지수         */

#define  FUTMST_PK_ID      'a'           /* 선물 마스터          */
#define  FUTREL_PK_ID      'b'           /* 선물 시세            */
#define  FUTUJA_PK_ID      'g'           /* 선물 투자자          */

#define  OPTMST_PK_ID      'c'           /* 옵션 마스터          */
#define  OPTREL_PK_ID      'd'           /* 옵션 시세            */
#define  OPTUJA_PK_ID      'h'           /* 옵션 투자자          */

#define  STOPTMST_PK_ID    'e'           /* 주식옵션 마스터      */
#define  STOPTREL_PK_ID    'f'           /* 주식옵션 시세        */
#define  STOPTUJA_PK_ID    'j'           /* 주식옵션 투자자      */

#define  ELWMST_PK_ID      0x71          /* ELW 마스터           */
#define  ELWREL_PK_ID      0x74          /* ELW 체결             */
#define  ELWHOGA_PK_ID     0x75          /* ELW 호가(10단계)     */
#define  ELWLPHOGA_PK_ID   0x76          /* ELW lp 호가          */
#define  ELWKOBAMST_PK_ID  0x91          /* 조기종료 elw마스터   */
#define  ELWKOBABS_PK_ID   0x92          /* 조기종료 elw마스터 기초자산고저가*/
#define  ELWKOBATM_PK_ID   0x93          /* 조기종료 elw 공개장운영*/


#define  STFUMST_PK_ID     0x81          /* 개별주식선물 마스터  */
#define  STFUREL_PK_ID     0x82          /* 개별주식선물 체결    */
#define  STFUHOGA_PK_ID    0x83          /* 개별주식선물 호가(10단계)*/

#define  MKFUMST_PK_ID     0x85          /* 상품주식선물 마스터  */
#define  MKFUREL_PK_ID     0x86          /* 상품주식선물 체결    */
#define  MKFUHOGA_PK_ID    0x87          /* 상품주식선물 호가(10단계)*/
#define  MKFUFIN_PK_ID     0x88          /* 상품주식선물 종목마감*/
#define  MKFUJUNG_PK_ID    0x89          /* 상품주식선물 정산가  */
#define  MKFUMIGYUL_PK_ID  0x90          /* 상품주식선물 미결제수량*/

#define  REALHGDWCHG_PK_ID 0x94          /* 실시간상하한가 적용및해제*/

#define  FUTUPDW_PK_ID     0x9a          /* 선물 투자자(가격제한폭확대발동)         */
#define  OPTUPDW_PK_ID     0x9b          /* 옵션 투자자(가격제한폭확대발동)         */
#define  STFUPDW_PK_ID     0x9c          /* 개별주식선물 투자자(가격제한폭확대발동) */
#define  STOPUPDW_PK_ID    0x9d          /* 개별주식옵션 투자자(가격제한폭확대발동) */

#define  KOSPINT_PK_ID     'G'           /* 거래소공시           */
#define  KOSDAQNT_PK_ID    'O'           /* 코스닥공시           */

#define PACKED __attribute__((packed))

/*
* 가격구분
* 15-bit 14- bit
*   0       1         16,000원 미만          1원
*   0       0         16,036.000 -    160,000     10원
*   1       0        160,000 -  1,599,999    100원
*   1       1      1,600,000 - 16,383,000   1000원
*/

/*****************************************************************************/
/* 공통                                                                      */
/*****************************************************************************/

typedef struct _HEADER{
	char    id          [1]; /* DATA ID 0x98          */
	char    gubun       [1]; /* 전송할  Data 의 ID    */
	short   version        ; /* 1 Set                 */
	long    size           ; /* 전송건수 or 1         */
	char    tail        [3]; /* 0xff, 0xod, 0x0a      */
}HEADER;
typedef struct _FOOTER{
	char    id          [1]; /* DATA ID 0x98          */
	char    gubun       [1]; /* 전송할  Data 의 ID    */
	short   version        ; /* 1 Set                 */
	long    size           ; /* 전송건수 or 1         */
	char    tail        [3]; /* 0xff, 0xod, 0x0a      */
}FOOTER;
typedef struct _PK_HOGA{
	long    hmedo          ; /* 매도호가              */
	long    hmesu          ; /* 매수호가              */
	long    hmedoval       ; /* 매도호가잔량          */
	long    hmesuval       ; /* 매수호가잔량          */
}PK_HOGA;
typedef struct _PK_OFHOGA{
	long    hmedo          ; /* 매도호가              */
	long    hmesu          ; /* 매수호가              */
	long    hmedoqty       ; /* 매도호가잔량          */
	long    hmesuqty       ; /* 매수호가잔량          */
	long    hmedocnt       ; /* 매도호가건수          */
	long    hmesucnt       ; /* 매수호가건수          */
}PK_OFHOGA;
typedef struct _PK_ELWHOGA{
	long    hmedo          ; /* 매도호가              */
	long    hmesu          ; /* 매수호가              */
	long    hmedoqty       ; /* 매도호가잔량          */
	long    hmesuqty       ; /* 매수호가잔량          */
	long    lphmedoqty     ; /* LP 매도호가잔량       */
	long    lphmesuqty     ; /* LP 매수호가잔량       */
}PK_ELWHOGA;
typedef struct _PK_UP{
	long    jisu           ; /* 지수 .99              */
	long    volume         ; /* 거래량:천주           */
	long    value          ; /* 거래대금:백만         */
	long    filler         ; /* filler                */
}PK_UP;
typedef struct _PK_UPQ{
	long    gb             ; /* 1~160 코스닥지수업종표참조 (가변) */
	long    jisu           ; /* 지수 .99              */
	long    volume         ; /* 거래량:천주           */
	long    value          ; /* 거래대금:백만         */
}PK_UPQ;


/*****************************************************************************/
/* KOSPI                                                                     */
/*****************************************************************************/

typedef struct _PK_KOSPIJMST{ /* 장내주식 Master          */
	char    id          [1]; /* Data ID 0x02          */
	char    filler1     [1]; /* filler                */
	short   index          ; /* 종목 일련번호         */
	char    shcode      [9]; /* 종목코드              */ /* 2003-10-06 변경  5->9 */
	char	kospi200up  [1]; /* KOSPI200 업종코드     */
	char    excode     [12]; /* 신코드(국제표준)      */
	char    hname      [16]; /* 종목명                */
	char    upcode      [2]; /* 업종코드              */
	short   setmonth       ; /* 결산월                */
	char    sgubun      [2]; /* 소속구분 1:1부 6:리츠 */
	/* char    capgubun    [1]; *//* filler                *//* 2004-02-02 자본금구분(capgubun) -> filler *//* 2007-04-02 삭제 */
	char    rakgubun    [1]; /* 락구분                */
	char    trgubun     [1]; /* 감리관리거래정지구분  */
	char    eventgubun  [1]; /* 당일 액분/병합 1:액분 2:병합 */
	char    reitsgubun  [1]; /* 리츠구분 1:일반리츠 2:CR리츠 8:ETF */
	long    baseprc        ; /* 기준가                */
	long    bopen          ; /* 전일시가              */
	long    bhigh          ; /* 전일고가              */
	long    blow           ; /* 전일저가              */
	long    bclose         ; /* 전일종가              */
	long    bvolume        ; /* 전일 거래량 (1주)     */
	long    bamt           ; /* 전일 거래대금 (10,000원) */
	long    upprc          ; /* 상한가                */
	long    dwprc          ; /* 하한가                */
	long    max52          ; /* 52주 최고가           */
	long    min52          ; /* 52주 최저가           */
	long    max52dt        ; /* 52주 최고가일         */
	long    min52dt        ; /* 52주 최저가일         */
	long    listcnt        ; /* 상장주식수            */
	long    capital        ; /* 자본금 (백만)         */
	long    beps           ; /* 년간주당순이익금 .99  */
	long    faceval        ; /* 액면가                */
	long    reitssdt       ; /* 리츠존속개시일 CR리츠만 해당 */
	long    reitsedt       ; /* 리츠존속종료일 CR리츠만 해당 */
	char    errgubun    [1]; /* 불성실공시 여부       */
	char    filler3     [3]; /* filler                */
	char	filler11   [32]; /* 영문축약명   -> filler 2007-12-14 */
	short	manuindu       ; /* 제조업 구분 41:제조업 50:비제조업 */
	char	filler4	    [2];
	short   maxyeardt      ; /* 연중 최고가일 (월일)  */
	short   minyeardt      ; /* 연중 최저가일 (월일)  */
	long    maxyear        ; /* 연중 최고가           */
	long    minyear        ; /* 연중 최저가           */
	char	bgise       [1]; /* 전일 기세구분 1:기세  */
	char	bupdown     [1]; /* 전일 등락구분         */
	char	filler5     [2];
	long	listdt         ; /* 상장일                */
	long	subprice       ; /* 대용가                */
	long	totamt         ; /* 시가총액 (억원)       */
	long    max50          ; /* 50일 최고가           */
	long    min50          ; /* 50일 최저가           */
	long    max50dt        ; /* 50일 최고가일         */
	long    min50dt        ; /* 50일 최저가일         */
	long	gamriprc       ; /* 감리대상지정가격      */
	long	gamridt        ; /* 감리대상지정일        */
	short	contupdt       ; /* 연속 상한가 일수      */
	short	contdndt       ; /* 연속 하한가 일수      */
	short	totupdt        ; /* 연간누적 상한가 일수  */
	short	totdndt        ; /* 연간누적 하한가 일수  */
	long	chngfacedt     ; /* 액면가 변경일         */
	long	baedang        ; /* 배당금                */
	short	chngfacerate   ; /* 액면 변경비율         */
	short	midbaedang     ; /* 중간배당락구분 0:정상 1:중간배당락 2:권리배당락 */
	long	trdunit        ; /* 매매단위              */
	long	jungridt       ; /* 정리매매 개시일       */
	long	jungridtend    ; /* 정리매매 종료일       */
	long	fodrable1      ; /* 외국인주문가능수량 억주 */
	long	fodrable2      ; /* 외국인주문가능수량 주 */
	long	fmaxqty1       ; /* 외국인한도수량 억주   */
	long	fmaxqty2       ; /* 외국인한도수량 주     */
	long	fmaxrate       ; /* 외국인한도비율 .99  */
	long	etfgb          ; /* ETF 분류 0:일반 1:뮤추얼펀드 2:수익증권 */
	long	etfupjong1     ; /* ETF 관련지수업종대    */
	long	etfupjong2     ; /* ETF 관련지수업종중    */
	long	etfupjong3     ; /* ETF 관련지수업종소    */
	long	etfcuunit      ; /* ETF CU단위            */
	long	etfjongcnt     ; /* ETF 구성종목수        */
	long	etftotamt      ; /* ETF 순자산총액(백만원)*/
	char	etfdaejugi  [2]; /* ETF 배당주기          */
	char	totamtgubun [2]; /* 시가총액규모구분 02:대 03:중 04:소 99:제외종목 (20030117추가) */
	long	etfjidaebi     ; /* ETF 관련지수대비율 .99*/
	long	lastnav        ; /* 최종 NAV .99          */
	char	gwangam     [1]; /* 관리감리구분 0:일반 1:감리+관리 */
	char	kospi10050  [1]; /* KOSPI100/50구분 0:일반 1:100 2:50 */
	char	filler6     [1]; /* KOSPIIT 구분 0:일반 1:IT *//* kospiit -> filler 2007-04-02 변경*/
	char	filler8     [1]; /* filler                */
	char	hname2     [44]; /* 종목명2  24->44       */
	char	mgstcom_gb  [2]; /* 지배구조우수기업구분  01:해당 02:해당사항없음*/ /* 2003-12-01 추가 */
	short	invstcompgb    ; /* 투자회사구분          *//* 2005-06-01 추가 */
	short	invstjisuingb  ; /* 투자회사지수산입종목여부 0:지수미산입종목 1:지수산입종목 *//* 2005-06-01 추가 */
	char	igritemgb   [1]; /* 통합지수종목구분 0:일반 1:통합지수종목 *//* 2005-06-01 추가 */
	char	listgb      [1]; /* 상장구분 1:정상 2:신규 3:신주 4:기준가산출후거래무 5:상장폐지 6:주식병합 7:기준가조정 *//* 2005-06-01 추가 */
	char	filler9     [3]; /* filler                */
	char	krxjisucargb[1]; /* 0:일반 1: KRX섹터지수 자동차 대상종목   */
	char	krxjisusemgb[1]; /* 0:일반 1: KRX섹터지수 반도체 대상종목   */
	char	krxjisubiogb[1]; /* 0:일반 1: KRX섹터지수 바이오 대상종목   */
	char	krxjisufingb[1]; /* 0:일반 1: KRX섹터지수 금융 대상종목     */
	char	krxjisucmigb[1]; /* 0:일반 1: KRX섹터지수 정보통신 대상종목 */
	long	vengubunstart  ; /* 존립시작일 YYYYMMDD 소속부 구분이 4,10,12일 때만 해당    */
	long	vengubunend    ; /* 존립종료일 YYYYMMDD 소속부 구분이 4,10,12일 때만 해당    */
	short	settledt       ; /* 결산월일 MMDD 소속부 구분이 4,12일 때만 해당 */
	char	ename      [40]; /* 영문명                *//* 2007-12-14 */

	char	invest_gb   [2]; /* 시장경보구분코드 00:해당없음 01:투자주의 02:투자경고 03:투자위험*/
	char	gwanitem_gb [1]; /* 관리종목여부 Y, N*/
	char	jungri_gb   [1]; /* 정리매매여부 Y, N*/

	char	event_gb    [2]; /* 이벤트         *//*2011-03-11 2:10오후 추가*/
	char	event_rt1   [8]; /* 이벤트 비율정수*//*2011-03-11 2:10오후 추가*/
	char	event_rt2   [8]; /* 이벤트 비율소수*//*2011-03-11 2:10오후 추가*/
	char	filler10   [32]; /* filler                *//* 2011-03-11 2:10오후 50->32 */
	char    ff          [1]; /* 0xff                  */
	char    cr          [1]; /* 0x0d                  */
	char    lf          [1]; /* 0x0a                  */
}PK_KOSPIJMST;
typedef struct _PK_KOSPIJBASE{ /* 장내기준가 */
	char    id          [1]; /* Data ID 'M'           */
	char    filler      [1]; /* Filler                */
	char    datagb      [3]; /* 데이타분류            */
	char    excode     [12]; /* 신코드(국제표준)      */
	char    opendt      [8]; /* 공개일                */
	char    opentm      [8]; /* 공개시간              */
	char    procbf     [15]; /* 조치후값              */
	char    procaf     [15]; /* 조치전값              */
	char    baseprc     [9]; /* 기준가                */
	char    upprc       [9]; /* 상한가                */
	char    dwprc       [9]; /* 하한가                */
	char    baseprcgb   [2]; /* 기준가산출여부   00:미산출, 01:산출 */
	char    prc         [9]; /* 가격                  */
	char    qty        [10]; /* 수량                  */
	char    meme_gb     [2]; /* 매매구분              */
	char    filler2     [6]; /* Filler2               */
	char    ff          [1]; /* 0xff                  */
	char    cr          [1]; /* 0x0d                  */
	char    lf          [1]; /* 0x0a                  */
}PK_KOSPIJBASE;

typedef struct _PK_KOSPIJONG{
	char    id          [1]; /* Data ID 'S'           */
	char    vol_gb      [1]; /* 잔량구분  0:장중 1:장종료후시간외 2:장개시전시간외 3:시간외단일가마감*//* 2005-05-30 구분추가 */
	char    filler      [2]; /* Filler                *//* 2003-12-01 변경 3-> 2*/
	short   index          ; /* 일련번호              */
	short   stime          ; /* 증전전송시간          */
	char    chegb       [1]; /* 체결구분 1:장중 2:장개신전시간외 3:장종료후시간외 4:시간외단일가 *//* 2005-05-30 추가 filler(1) -> chegb(1) */
	char    updown      [1]; /* 등락구분              */
	char    ovtmunithggb[1]; /* 시간외단일가호가구분  *//* 2005-05-30 추가 filler2(1) ->ovtmunithggb(1) */
	char    dongsigb    [1]; /* 관리/감리구분 -> 동시구분(2002-09-30)  0:접속, 1:동시, 2:동시연장 */
	long    daebi          ; /* 대비 0:초기값 1:시간외단일가개시 2:시간외단일가마감 *//* 2005-05-30 추가 */
	long    price          ; /* 현재가                */
	long    open           ; /* 시가                  */
	long    high           ; /* 고가                  */
	long    low            ; /* 저가                  */
	long    volume         ; /* 누적거래량            */
	long    amt            ; /* 누적거래대금(백만)    */
	PK_HOGA hoga[10]       ; /* 10차선호가            */
	long    dcheprc        ; /* 총매도호가잔량 -> 예상체결가(2002-09-30)   */
	long    dcheqty        ; /* 총매수호가잔량 -> 예상체결수량(2002-09-30) */
	long    otmedotot      ; /* 시간외 총 매도잔량    */
	long    otmesutot      ; /* 시간외 총 매수잔량    */
	long    hgmedotot      ; /* 10단계 매도잔량합계   */
	long    hgmesutot      ; /* 10단계 매수잔량합계   */
	long    bfjangmedotot  ; /* 장개시전시간외 총매도잔량 *//* 2003-12-01 추가 */
	long    bfjangmesutot  ; /* 장개시전시간외 총매수잔량 *//* 2003-12-01 추가 */
	long    ovtmunitmedotot; /* 시간외단일가 10단계 총매도잔량 *//* 2005-05-30 추가 */
	long    ovtmunitmesutot; /* 시간외단일가 10단계 총매수잔량 *//* 2005-05-30 추가 */
	long    wavg           ; /* 가중평균가            */
	char    janggb      [2]; /* 장구분                */
	char    filler3     [1]; /*                       *//* 2005-05-30 size 변경 2->1 */
	char    gise        [1]; /* 실세/기세구분 1:실세 2:기세 3:거래무 *//* filler3 2->1 *//* 2005-05-30 추가 */
	long    bfcheprc       ; /* 시간외 신고대량/바스켓 매매시 *//* 2003-12-01 추가 */
	long    ovtmunithigh   ; /* 시간외단일가상한가    *//* 2005-05-30 추가 */
	long    ovtmunitlow    ; /* 시간외단일가하한가    *//* 2005-05-30 추가 */
	long    tdclose        ; /* 당일종가              *//* 2005-05-30 추가 */
	char    ff          [1]; /* 0xff                  */
	char    cr          [1]; /* 0x0d                  */
	char    lf          [1]; /* 0x0a                  */
}PK_KOSPIJONG;
typedef struct _PK_KOSPICHE{
	PK_KOSPIJONG  jp;
	char          shcode[6];
	long          dif;/* 변동거래량 */
}PK_KOSPICHE;
typedef struct _PK_KOSPIUPMST{ /* 장내업종 Master         */
	char    id          [1]; /* Data ID 0x03          */
	char    filler      [1]; /* Filler                */
	short   upcode         ; /* 업종코드 1~22 23~27 38~40 */
	char    hname      [16]; /* 업종명                */
	long    bopen          ; /* 전일시가              */
	long    bhigh          ; /* 전일고가              */
	long    blow           ; /* 전일저가              */
	long    bclose         ; /* 전일종가 지수 .99     */
	long    volume         ; /* 전일거래량(천주)      */
	char    ff          [1]; /* 0xff                  */
	char    cr          [1]; /* 0x0d                  */
	char    lf          [1]; /* 0x0a                  */
}PK_KOSPIUPMST;

typedef struct _PK_KOSPIUPMST PK_KOSPI200MST;
typedef struct _PK_KOSPIUPMST PK_KOSPI50MST;

typedef struct _PK_KOSPI1MIN{ /* 1분지수 */
	char    id          [1]; /* Data id 'J'           */
	char    jgubun      [1]; /* 장구분 1:장중 3:시간외종료 */
	short   index          ; /* 일련번호              */
	long    time           ; /* 시간  전장:1100000    */
	                         /*       후장:2100000    */
	                         /*     시간외:3100000    */
	PK_UP   item       [41];
	char    ff          [1]; /* 0xff                  */
	char    cr          [1]; /* 0x0d                  */
	char    lf          [1]; /* 0x0a                  */
}PK_KOSPI1MIN;
typedef struct _PK_KOSPI2001MIN{
	char    id          [1]; /* Data id 'I'           */
	char    jgubun      [1]; /* 장구분 미사용         */
	short   index          ; /* 일련번호              */
	long    time           ; /* 시간  전장:1100000    */
	                         /*       후장:2100000    */
	                         /*     시간외:3100000    */
	PK_UP   item        [6];
	char    ff          [1]; /* 0xff                  */
	char    cr          [1]; /* 0x0d                  */
	char    lf          [1]; /* 0x0a                  */
}PK_KOSPI2001MIN;
typedef struct _PK_KOSPI501MIN{
	char    id          [1]; /* Data id 'N'           */
	char    jgubun      [1]; /* 장구분 미사용         */
	short   index          ; /* 일련번호              */
	long    time           ; /* 시간  전장:1100000    */
	                         /*       후장:2100000    */
	                         /*     시간외:3100000    */
	PK_UP   item        [1];
	char    ff          [1]; /* 0xff                  */
	char    cr          [1]; /* 0x0d                  */
	char    lf          [1]; /* 0x0a                  */
}PK_KOSPI501MIN;
typedef struct _PK_KOSPIUPDN{
	char    id         [1]; /* Data id 'J'            */
	char    jgubun     [1]; /* 장구분 미사용          */
	short   stime         ; /* 전장:1100, 21000       */
	short   uplmcnt       ; /* 상한종목수             */
	short   upcnt         ; /* 상승종목수             */
	short   bohap         ; /* 보합종목수             */
	short   dwlmcnt       ; /* 하한 종목수            */
	short   dwcnt         ; /* 하락종목수             */
	short   giup          ; /* 기세 상승              */
	short   gidw          ; /* 기세 하락              */
	short   totcnt        ; /* 전체종목수             */
	short   trancnt       ; /* 거래종목수             */
	char    ff         [1]; /* 0xff                   */
	char    cr         [1]; /* 0x0d                   */
	char    lf         [1]; /* 0x0a                   */
}PK_KOSPIUPDN;
typedef struct _PK_KOSPIUPDN PK_KOSPI200UPDN;

/*
** 2005-05-30 신규추가
*/
typedef struct _PK_KOSPIJONG2{ /* KOSPI종목시세 2 */
	char    id          [1]; /* Data ID 's'           */
	char    vol_gb      [1]; /* 잔량구분  0:장중 1:장종료후시간외 2:장개시전시간외 3:시간외단일가마감*//* 2005-05-30 구분추가 */
	char    filler      [2]; /* Filler                *//* 2003-12-01 변경 3-> 2*/
	short   index          ; /* 일련번호              */
	short   stime          ; /* 증전전송시간          */
	char    chegb       [1]; /* 체결구분 1:장중 2:장개신전시간외 3:장종료후시간외 4:시간외단일가 *//* 2005-05-30 추가 filler(1) -> chegb(1) */
	char    updown      [1]; /* 등락구분              */
	char    ovtmunithggb[1]; /* 시간외단일가호가구분  *//* 2005-05-30 추가 filler2(1) ->ovtmunithggb(1) */
	char    dongsigb    [1]; /* 관리/감리구분 -> 동시구분(2002-09-30)  0:접속, 1:동시, 2:동시연장 */
	long    daebi          ; /* 대비 0:초기값 1:시간외단일가개시 2:시간외단일가마감 *//* 2005-05-30 추가 */
	long    price          ; /* 현재가                */
	long    open           ; /* 시가                  */
	long    high           ; /* 고가                  */
	long    low            ; /* 저가                  */
	long    volume         ; /* 누적거래량            */
	long    amt            ; /* 누적거래대금(백만)    */
	PK_HOGA hoga[10]       ; /* 10차선호가            */
	long    dcheprc        ; /* 총매도호가잔량 -> 예상체결가(2002-09-30)   */
	long    dcheqty        ; /* 총매수호가잔량 -> 예상체결수량(2002-09-30) */
	long    otmedotot      ; /* 시간외 총 매도잔량    */
	long    otmesutot      ; /* 시간외 총 매수잔량    */
	long    hgmedotot      ; /* 10단계 매도잔량합계   */
	long    hgmesutot      ; /* 10단계 매수잔량합계   */
	long    bfjangmedotot  ; /* 장개시전시간외 총매도잔량 */
	long    bfjangmesutot  ; /* 장개시전시간외 총매수잔량 */
	long    ovtmunitmedotot; /* 시간외단일가 10단계 총매도잔량 */
	long    ovtmunitmesutot; /* 시간외단일가 10단계 총매수잔량 */
	long    wavg           ; /* 가중평균가            */
	char    janggb      [2]; /* 장구분                */
	char    filler3     [1]; /*                       */
	char    gise        [1]; /* 실세/기세구분 1:실세 2:기세 3:거래무 */
	long    bfcheprc       ; /* 시간외 신고대량/바스켓 매매시 */
	long    ovtmunithigh   ; /* 시간외단일가상한가    */
	long    ovtmunitlow    ; /* 시간외단일가하한가    */
	long    tdclose        ; /* 당일종가              */

	char    filler4     [3]; /* filler                */
	char	ovtmupdown  [1]; /* 시간외단일가 등락구분  1:상한,2:상승,3:보합,4:하한,5:하락 6:기세*/
	long    ovtmdaebi      ; /* 시간외단일가 대비 0:초기값 1:시간외단일가개시 2:시간외단일가마감 */
	long    ovtmprice      ; /* 시간외단일가 현재가   */
	long    ovtmopen       ; /* 시간외단일가 시가     */
	long    ovtmhigh       ; /* 시간외단일가 고가     */
	long    ovtmlow        ; /* 시간외단일가 저가     */
	long    ovtmvolume     ; /* 시간외단일가 누적거래량            */
	long    ovtmamt        ; /* 시간외단일가 누적거래대금(백만)    */

	char    ff          [1]; /* 0xff                  */
	char    cr          [1]; /* 0x0d                  */
	char    lf          [1]; /* 0x0a                  */
}PK_KOSPIJONG2;


/*****************************************************************************/
/* KOSDAQ                                                                    */
/*****************************************************************************/

typedef struct _PK_KOSDAQJMST{   /* KOSDAQ 종목 Master    */
	char    id          [1]; /* Data ID 0x13          */
	char    filler1     [1]; /* filler                */
	short   index          ; /* 종목 일련번호         */
	char    shcode      [9]; /* 종목코드              */ /* 2003-10-06 변경  5->9 */
	char    vengubun    [1]; /* 소속부구분  2001.10.25 추가(A) */
	char    hname      [20]; /* 종목명                */
	char    upcode      [2]; /* 업종코드              */
	short   setmonth       ; /* 결산월                */
	char    capgubun    [1]; /* 자본금규모            */
	char    trgubun     [1]; /* 거래정지구분          */
	char    rakgubun    [1]; /* filler                */ /* 2005-03-07 변경 (락구분->filler) */
	char    toojagubun  [1]; /* 투자유의 구분         */
	char    mkprcjugb   [1]; /* 시장가주문가능 여부   */
	char    kosdaq50gb  [1]; /* Kosdaq50 종목 여부    */
	long    baseprc        ; /* 기준가                */
	long    bopen          ; /* 전일시가              */
	long    bhigh          ; /* 전일고가              */
	long    blow           ; /* 전일저가              */
	long    bclose         ; /* 전일종가              */
	long    bvolume        ; /* 전일 거래량           */
	long    upprc          ; /* 상한가                */
	long    dwprc          ; /* 하한가                */
	long    beps           ; /* 년간주당순이익금 .99  */
	long    listdt         ; /* 승인일                */
	long    listcnt        ; /* 상장주식수            */
	long    faceval        ; /* 액면가                */
	long    memedt         ; /* 매매개시일(상장일)    */
	char    updcode     [2]; /* 업종대분류코드 2001.10.25 추가(A) */
	char    upmcode     [3]; /* 업종중분류코드 2001.10.25 추가(A) */
	char	bepssign    [1]; /* eps 부호 '+','-', '#':eps없음 */
	char    filler3     [2]; /* filler                */
	char    excode     [12]; /* 표준코드              */
	char    ename      [30]; /* 영문명                */
	char    filler4     [1]; /* filler                */
	char    brakgb      [1]; /* 전일락구분  0:정상,1:권리락,3:배당락,4:신규상장,6:신주상장 */
	long    bamt           ; /* 전일 거래대금 (10,000원) */
	char	gwangb      [1]; /* 관리구분 0:정상 1:관리*/
	char    errgubun    [1]; /* 불성실공시 여부 0:정상 1:지정      */
	char    errsau      [1]; /* 불성실공시 사유 1:공시불이행, 2:공시번복, 3:공시변경 */
	char	bgise       [1]; /* 전일 기세구분 0:정상 1:기세  */
	long	bper           ; /* 전기PER  .99          */
	char	bupdown     [1]; /* 전일 등락구분  1:상한,2:상승,3:보합,4:하한,5:하락 */
	char    trsaugb     [1]; /* 거래정지사유구분      */
	char    toojasaugb  [1]; /* 투자유의지정사유 구분 */
	char    listgubun   [1]; /* 상장구분 0:정상 1:신규 2:추가 */
	long    toojadt        ; /* 투자유의지정일(년월일)*/
	long    maxyear        ; /* 연중 최고가           */
	long    minyear        ; /* 연중 최저가           */
	short   maxyeardt      ; /* 연중 최고가일 (월일)  */
	short   minyeardt      ; /* 연중 최저가일 (월일)  */
	short	contupdt       ; /* 연속 상한가 일수      */
	short	contdndt       ; /* 연속 하한가 일수      */
	short	totupdt        ; /* 연간누적 상한가 일수  */
	short	totdndt        ; /* 연간누적 하한가 일수  */
	long	chngfacedt     ; /* 액면가 변경일         */
	short	chngfacerate   ; /* 액면 변경비율         */
	char	gwanshcodegb[1]; /* 이상급등종목구분 0:정상 1:이상급등종목 */
	char	filler6     [1]; /* IT50구분  filler      *//* it50 -> filler 변경 2007-04-02 */
	long    max52          ; /* 52주 최고가           */
	long    min52          ; /* 52주 최저가           */
	long    max52dt        ; /* 52주 최고가일         */
	long    min52dt        ; /* 52주 최저가일         */
	long    errdt          ; /* 불성실공시 지정일     */
	long    max52volume    ; /* 52주 최고거래량(주)   */
	long	fodrable2      ; /* 외국인주문가능수량 주 */
	long	fmaxqty2       ; /* 외국인한도수량 주     */
	long	fmaxrate       ; /* 외국인한도비율 .99    */
	long	etfgb          ; /* ETF 분류 0:일반 1:뮤추얼펀드 2:수익증권 */
	long	etfobjgb       ; /* ETF 대상자 구분 0:일반 1:KOSDAQ50       */
	long	etfcuunit      ; /* ETF CU 단위  단위:증권*/
	long	etfjongcnt     ; /* ETF 구성종목수 단위:종목 */
	long	etftotamt      ; /* ETF 순자산총액 단위:백만원 */
	char	etfdaejugi  [2]; /* ETF 배당주기   단위:개월 */
	char	outrakinfo  [2]; /* 외부공개락정보        */ /* 2005-03-07 변경 (filler5->outrakinfo) */
	long	etfjidaebi     ; /* ETF 관련지수대비율 소수점이하2자리   */
	long	lastnav        ; /* 최종 NAV           소수점이하2자리   */
	char	sichogb     [1]; /* 시초가산출구분        */ /* 2005-03-07 변경 (filler7->sichogb)     */
	char	randomendgb [1]; /* Random End 구분       */ /* 2005-03-07 변경 (filler7->randomendgb) */
	char	filler7     [2]; /* filler                */ /* 2005-03-07 변경 (filler7->filler6)     */
	long	jungridt       ; /* 정리매매 개시일       */ /* 2005-03-07 변경 (filler7->jungridt)    */
	long	jungridtend    ; /* 정리매매 종료일       */ /* 2005-03-07 변경 (filler7->jungridtend) */
	char	igritemgb   [1]; /* 통합지수종목구분 0:일반 1:통합지수종목 *//* 2005-06-01 추가 */
	char	filler8     [3]; /* filler                */
	char	krxjisucargb[1]; /* 0:일반 1: KRX섹터지수 자동차 대상종목   */
	char	krxjisusemgb[1]; /* 0:일반 1: KRX섹터지수 반도체 대상종목   */
	char	krxjisubiogb[1]; /* 0:일반 1: KRX섹터지수 바이오 대상종목   */
	char	krxjisufingb[1]; /* 0:일반 1: KRX섹터지수 금융 대상종목     */
	char	krxjisucmigb[1]; /* 0:일반 1: KRX섹터지수 정보통신 대상종목 */
	char	lpjuablegb  [1]; /* LP 주문가능여부 0:불가 1:가능 */
	char	lpminqty   [10]; /* LP허용 최소호가수량 */
	char	backdoorlist[1]; /* 우회상장구분 0:정상 1:우회상장 */
	char	tujaexcite  [1]; /* 투자환기구분          *//* 2011-07-04 추가 */
	char	filler9     [2]; /* filler                */
	long	rprc           ; /* 대용가                */
	long	capital        ; /* 자본금 (백만원)       */

	char	filler10   [14]; /* filler                */
	char	invest_gb   [2]; /* 시장경보구분코드 00:해당없음 01:투자주의 02:투자경고 03:투자위험*/
	char	gwanitem_gb [1]; /* 관리종목여부 Y, N*/
	char	jungri_gb   [1]; /* 정리매매여부 Y, N*/
	char	filler11    [2]; /* filler                */
	char    ff          [1]; /* 0xff                  */
	char    cr          [1]; /* 0x0d                  */
	char    lf          [1]; /* 0x0a                  */

}PK_KOSDAQJMST;


typedef struct _PK_KOSDAQJONG{ /* KOSDAQ 종목시세     */
	char    id          [1]; /* Data ID 0xa1          */
	char    jgubun      [1]; /* filler                */ /* 2005-03-07 변경 (jgubun->filler) */
	short   index          ; /* 일련번호              */
	short   stime          ; /* 시간(HHMM) 21000:종료 */
	char    trgubun     [1]; /* 거래정지구분          */
	char    toojagubun  [1]; /* 투자유의 구분         */
	/* char    rakgubun    [1]; *//* filler                */ /* 2005-03-07 변경 (jgubun->filler) */
	char    chegb       [1]; /* 체결구분 1:보통 2;장료종료후 시간외종가매매 3:장종료후시간외 대량매매 4:장개시전시간외종가매매 5:장개시전시간외대량매매 6:시간외 단일가매매 *//* 2005-05-30 추가 filler(1) -> chegb(1) */
	char    updown      [1]; /* 등락구분              */
	char    gise        [1]; /* 실세/기세구분 0:초기값 1:기세 2:기세아님 */ /* 2005-03-07 변경 */
	char    dongsigb    [1]; /* 동시호가구분 1:시초동시 2:접속 3:마감동시 4:시간외종가 5:장중동시  */
	long    baseprc        ; /* 기준가                */
	long    upprc          ; /* 상한가                */
	long    dwprc          ; /* 하한가                */
	long    daebi          ; /* 대비 0:초기값 1:시간외단일가개시 2:시간외단일가마감 *//* 2005-05-30 추가 */
	long    price          ; /* 현재가                */
	long    open           ; /* 시가                  */
	long    high           ; /* 고가                  */
	long    low            ; /* 저가                  */
	long    volume         ; /* 거래량                */
	long    amt            ; /* 누적거래대금(천원)    */
	PK_HOGA hoga[10]       ; /* 10차선호가            */
	long    dcheprc        ; /* 총매도호가잔량 -> 예상체결가(2002-09-30)   */
	long    dcheqty        ; /* 총매수호가잔량 -> 예상체결수량(2002-09-30) */
	long    otmedotot      ; /* 시간외 총 매도잔량    */
	long    otmesutot      ; /* 시간외 총 매도잔량    */
	long    hgmedotot      ; /* 10단계 매도잔량합계   */
	long    hgmesutot      ; /* 10단계 매수잔량합계   */
	long    bfhgmedotot    ; /* 장개시전시간외매도총잔량 *//* 2004-02-16 추가*/
	long    bfhgmesutot    ; /* 장개시전시간외매수총잔량 *//* 2004-02-16 추가*/
	long    ovtmunitmedotot; /* 시간외단일가 10단계 총매도잔량 *//* 2005-05-30 추가 */
	long    ovtmunitmesutot; /* 시간외단일가 10단계 총매수잔량 *//* 2005-05-30 추가 */
	/* char    baseprccg   [1]; *//* filler                */ /* 2005-03-07 변경 (baseprccg->filler) */
	char    ovtmunithggb[1]; /* 시간외단일가호가구분  *//* 2005-05-30 추가 filler2(1) ->ovtmunithggb(1) */
	char	upprcgb     [1]; /* 상한가변경여부        */
	char    dwprcgb     [1]; /* 하한가변경여부        */
	char    vol_gb      [1]; /* 잔량구분  0:초기값 1:장중 4:장종료후 시간외 5:장시작전 시간외 *//* 2004-02-16 추가 */
	long    bfcheprc       ; /* 장중에는 0, 시간외 거래에만 체결가가존재 *//* 2004-02-16 추가*/
	char    datagb      [2]; /* DATA분류              */ /* 2005-03-07 추가 *//* 01:예상체결가 공개중단 02:예상체결가 공개재개 03:기준가결정공시 04:시초동시RANDOM END 지정 05:시초동시RANDOM END 해제 06:마감동시RANDOM END 지정 07:마감동시RANDOM END 해제 08:동시연장 지정 09:동시연장 해제 10:시간외종가 매매 개시 11:시간외종가 매매 종료 12:장개시전 시간외 종료 13:정규장 종료  */
	char    filler1     [2]; /* filler                */ /* 2005-03-07 추가 */
	long    ovtmunithigh   ; /* 시간외단일가상한가    */ /* 2005-05-30 추가 */
	long    ovtmunitlow    ; /* 시간외단일가하한가    */ /* 2005-05-30 추가 */
	long    tdclose        ; /* 당일종가              */ /* 2005-05-30 추가 */
	char    ff          [1]; /* 0xff                  */
	char    cr          [1]; /* 0x0d                  */
	char    lf          [1]; /* 0x0a                  */
}PK_KOSDAQJONG;


typedef struct _PK_KOSDAQCHE{
	PK_KOSDAQJONG   jp;
	char            shcode[6];
	long            dif;
}PK_KOSDAQCHE;
typedef struct _PK_KOSPIUPMST PK_KOSDAQ50MST;
typedef struct _PK_KOSDAQUPMST{ /* KOSDAQ Master          */
	char    id          [1]; /* Data ID 0x05          */
	char    filler1     [1]; /* Filler                */
	short   upcode         ; /* 업종코드 1 ~ 160      */
	char    hname      [42]; /* 업종명                */
	char    filler2     [2]; /* Filler                */
	long    bopen          ; /* 전일시가              */
	long    bhigh          ; /* 전일고가              */
	long    blow           ; /* 전일저가              */
	long    bclose         ; /* 전일종가 지수 .99     */
	long    volume         ; /* 전일거래량(천주)      */
	char    ff          [1]; /* 0xff                  */
	char    cr          [1]; /* 0x0d                  */
	char    lf          [1]; /* 0x0a                  */
}PK_KOSDAQUPMST;
typedef struct _PK_KOSDAQ1MIN{ /* 1분지수 */
	char    id          [1]; /* Data id 'O'           */
	char    jgubun      [1]; /* 장구분 1:장중 3:시간외종료 */
	short   index          ; /* 일련번호              */
	long    time           ; /* 시간  전장:1100000    */
	PK_UPQ  item       [50];
	char    ff          [1]; /* 0xff                  */
	char    cr          [1]; /* 0x0d                  */
	char    lf          [1]; /* 0x0a                  */
}PK_KOSDAQ1MIN;
typedef struct _PK_KOSDAQ501MIN{
	char    id          [1]; /* Data id 'L'           */
	char    jgubun      [1]; /* 장구분 1:장중         */
	short   index          ; /* 일련번호              */
	long    time           ; /* 시간  전장:1100000    */
	                         /*       후장:2100000    */
	                         /*     시간외:3100000    */
	PK_UP   item        [1];
	char    ff          [1]; /* 0xff                  */
	char    cr          [1]; /* 0x0d                  */
	char    lf          [1]; /* 0x0a                  */
}PK_KOSDAQ501MIN;


/*
** 2005-05-30 신규추가
*/
typedef struct _PK_KOSDAQJONG2{ /* KOSDAQ 종목시세2     */
	char    id          [1]; /* Data ID 'r'           */
	char    jgubun      [1]; /* filler                */ /* 2005-03-07 변경 (jgubun->filler) */
	short   index          ; /* 일련번호              */
	short   stime          ; /* 시간(HHMM) 21000:종료 */
	char    trgubun     [1]; /* 거래정지구분          */
	char    toojagubun  [1]; /* 투자유의 구분         */
	/* char    rakgubun    [1]; *//* filler                */ /* 2005-03-07 변경 (jgubun->filler) */
	char    chegb       [1]; /* 체결구분 1:장중 2:장개신전시간외 3:장종료후시간외 4:시간외단일가 *//* 2005-05-30 추가 filler(1) -> chegb(1) */
	char    updown      [1]; /* 등락구분              */
	char    gise        [1]; /* 실세/기세구분 0:초기값 1:기세 2:기세아님 */ /* 2005-03-07 변경 */
	char    dongsigb    [1]; /* 동시호가구분 1:시초동시 2:접속 3:마감동시 4:시간외종가 5:장중동시  */
	long    baseprc        ; /* 기준가                */
	long    upprc          ; /* 상한가                */
	long    dwprc          ; /* 하한가                */
	long    daebi          ; /* 대비 0:초기값 1:시간외단일가개시 2:시간외단일가마감 *//* 2005-05-30 추가 */
	long    price          ; /* 현재가                */
	long    open           ; /* 시가                  */
	long    high           ; /* 고가                  */
	long    low            ; /* 저가                  */
	long    volume         ; /* 거래량                */
	long    amt            ; /* 누적거래대금(천원)    */
	PK_HOGA hoga[10]       ; /* 10차선호가            */
	long    dcheprc        ; /* 총매도호가잔량 -> 예상체결가(2002-09-30)   */
	long    dcheqty        ; /* 총매수호가잔량 -> 예상체결수량(2002-09-30) */
	long    otmedotot      ; /* 시간외 총 매도잔량    */
	long    otmesutot      ; /* 시간외 총 매도잔량    */
	long    hgmedotot      ; /* 10단계 매도잔량합계   */
	long    hgmesutot      ; /* 10단계 매수잔량합계   */
	long    bfhgmedotot    ; /* 장개시전시간외매도총잔량 *//* 2004-02-16 추가*/
	long    bfhgmesutot    ; /* 장개시전시간외매수총잔량 *//* 2004-02-16 추가*/
	long    ovtmunitmedotot; /* 시간외단일가 10단계 총매도잔량 *//* 2005-05-30 추가 */
	long    ovtmunitmesutot; /* 시간외단일가 10단계 총매수잔량 *//* 2005-05-30 추가 */
	/* char    baseprccg   [1]; *//* filler                */ /* 2005-03-07 변경 (baseprccg->filler) */
	char    ovtmunithggb[1]; /* 시간외단일가호가구분  *//* 2005-05-30 추가 filler2(1) ->ovtmunithggb(1) */
	char	upprcgb     [1]; /* 상한가변경여부        */
	char    dwprcgb     [1]; /* 하한가변경여부        */
	char    vol_gb      [1]; /* 잔량구분  0:초기값 1:장중 4:장종료후 시간외 5:장시작전 시간외 *//* 2004-02-16 추가 */
	long    bfcheprc       ; /* 장중에는 0, 시간외 거래에만 체결가가존재 *//* 2004-02-16 추가*/
	char    datagb      [2]; /* DATA분류              */ /* 2005-03-07 추가 *//* 01:예상체결가 공개중단 02:예상체결가 공개재개 03:기준가결정공시 04:시초동시RANDOM END 지정 05:시초동시RANDOM END 해제 06:마감동시RANDOM END 지정 07:마감동시RANDOM END 해제 08:동시연장 지정 09:동시연장 해제 10:시간외종가 매매 개시 11:시간외종가 매매 종료 12:장개시전 시간외 종료 13:정규장 종료  */
	char    filler1     [2]; /* filler                */ /* 2005-03-07 추가 */
	long    ovtmunithigh   ; /* 시간외단일가상한가    */ /* 2005-05-30 추가 */
	long    ovtmunitlow    ; /* 시간외단일가하한가    */ /* 2005-05-30 추가 */
	long    tdclose        ; /* 당일종가              */ /* 2005-05-30 추가 */

	char    filler4     [3]; /* filler                */
	char	ovtmupdown  [1]; /* 시간외단일가 등락구분  1:상한,2:상승,3:보합,4:하한,5:하락 6:기세*/
	long    ovtmdaebi      ; /* 시간외단일가 대비 0:초기값 1:시간외단일가개시 2:시간외단일가마감 */
	long    ovtmprice      ; /* 시간외단일가 현재가   */
	long    ovtmopen       ; /* 시간외단일가 시가     */
	long    ovtmhigh       ; /* 시간외단일가 고가     */
	long    ovtmlow        ; /* 시간외단일가 저가     */
	long    ovtmvolume     ; /* 시간외단일가 누적거래량            */
	long    ovtmamt        ; /* 시간외단일가 누적거래대금(백만)    */

	char    ff          [1]; /* 0xff                  */
	char    cr          [1]; /* 0x0d                  */
	char    lf          [1]; /* 0x0a                  */
}PK_KOSDAQJONG2;


/*****************************************************************************/
/* 선물                                                                      */
/*****************************************************************************/

typedef struct _PK_FUTMST{  /* 선물종목 Master */
	char    id          [1]; /* Data ID 'a'           */
	char    filler      [3]; /* Filler                */
	long    index          ; /* 일련번호              */
	char    expcode    [12]; /* 국제표준코드          */
	char    hname      [30]; /* 종목명                */

	char    lastdtgb    [1]; /* 최종거래일여부 1:해당 2:비해당 */
	char    baseprcgb   [1]; /* 기준가구분 1:전일정산가 2:전일기준가 3:당일기준가용이론가 4:전일기세 5:당일기준가용이론가 */

	long    listdt         ; /* 상장일                */
	long    lastdt         ; /* 최종거래일            */
	long    baseprc        ; /* 기준가                */
	long    upprc          ; /* 상한가                */
	long    dwprc          ; /* 하한가                */
	long    bclose         ; /* 전일종가              */
	long    bvolume        ; /* 전일거래량  (계약)    */
	long    bnvolume       ; /* 전일근월물(near)거래량*/
	long    bfvolume       ; /* 전일원월물(far)거래량 */
	long    bvalue1        ; /* 전일거래대금 1(백만)  */
	long    bvalue2        ; /* 전일거래대금 2(원)    */
	long    bnvalue1       ; /* 전일근월물거래대금 1(백만)  */
	long    bnvalue2       ; /* 전일근월물거래대금 2(원)    */
	long    bfvalue1       ; /* 전일원월물거래대금 1(백만)  */
	long    bfvalue2       ; /* 전일원월물거래대금 2(원)    */
	long    bmigyulqty     ; /* 전일미결제약정(확정치)*/
	long    bspreadnjong   ; /* 전일스프레드근월물종가*/
	long    bspreadfjong   ; /* 전일스프레드원월물종가*/
	char    nearexpcode[12]; /* 근월물종목코드        */
	char    farexpcode [12]; /* 원월물종목코드        */

	char    ename      [30]; /* 영문종목명            */
	char    shcode      [8]; /* 종목코드              */
	char    noname      [4]; /* 종목명(숫자종목명)    */
	char    shname     [15]; /* 단축종목명            */
	char    filler1     [3]; /* filler                */
	short   listdtcnt      ; /* 상장일수              */
	short   remaindtcnt    ; /* 잔존일수              */
	long    futdivid       ; /* 배당액지수미래가치    */
	long    theoryprc1     ; /* 이론가(정산가)        */
	long    theoryprc2     ; /* 이론가(기준가)        */
	long    cdrate         ; /* cd금리 단위:%, 전일 11시경 호가수익률 */
	char    bjungprcgb  [1]; /* 전일정산가격구분      */
	char    bclosegb    [1]; /* 전일종가구분 1:실세 2:기세 3:무거래 */
	char    filler2     [2]; /* filler                */
	long    bjungprc       ; /* 정산가격              */
	long    listinghighdt  ; /* 상장중 최고일자       */
	long    listinghighprc ; /* 상장중 최고가격       */
	long    listinglowdt   ; /* 상장중 최저일자       */
	long    listinglowprc  ; /* 상장중 최저가격       */
	long    listdt2        ; /* 입회일                */
	char    markryn     [1]; /* 시장가 허용구분 [Y:허용  N:제한] */
	char    condjiryn   [1]; /* 조건부지정가 허용구분 [Y:허용  N:제한] */
	char    choiyoujiryn[1]; /* 최유리지정가 허용구분 [Y:허용  N:제한] */
	char    lastprcgb   [1]; /* 최종결제가구분        */
	long    lastprc        ; /* 최종결제가            */
	long    cbup           ; /* C.B. 상한가           */
	long    cblow          ; /* C.B. 하한가           */
	long    bstime         ; /* 전일최종매매시간      */
	long    dealamt        ; /* 거래승수              *//* 신규추가 2012-02-10 */
	long    realupprc      ; /* 실시간상한가간격      *//* 추가 2014-09-01 */
	long    realdwprc      ; /* 실시간하한가간격      *//* 추가 2014-09-01 */
	char    realupdwgb[1]  ; /* 실시간가격제한여부    *//* 추가 2014-09-01 */
	char    prclimtcd[1]   ; /* 가격제한확대적용방향코드*//* 2015-06-15 추가 */
	short   prclimtlast    ; /* 가격제한최종단계      *//* 2015-06-15 추가 */
	long    prclimt1upprc  ; /* 가격제한1단계상한가   *//* 2015-06-15 추가 */
	long    prclimt1dwprc  ; /* 가격제한1단계하한가   *//* 2015-06-15 추가 */
	long    prclimt2upprc  ; /* 가격제한2단계상한가   *//* 2015-06-15 추가 */
	long    prclimt2dwprc  ; /* 가격제한2단계하한가   *//* 2015-06-15 추가 */
	long    prclimt3upprc  ; /* 가격제한3단계상한가   *//* 2015-06-15 추가 */
	long    prclimt3dwprc  ; /* 가격제한3단계하한가   *//* 2015-06-15 추가 */
	char    filler3[31]    ; /* filler                *//* 변경 2015-06-15 [27->31]*/
	char    ff          [1]; /* 0xff                  */
	char    cr          [1]; /* 0x0d                  */
	char    lf          [1]; /* 0x0a                  */
}PK_FUTMST;

typedef struct _PK_FUTJONG{ /* 선물 시세 */
	char    id          [1]; /* Data ID 'b'               */
	char    filler      [1]; /* Filler                    */
	short   jgubun         ; /* 장구분 9:Mst후, 1,2,3,4,5 */
	long    index          ; /* 종목 일련번호             */
	long    stime          ; /* 시세발생시간              */
	short   trgubun        ; /* 거래구분                  */
	short   gisegb         ; /* 기세구분                  */
	long    cbtime         ; /* C.B 발생시간              */
	long    price          ; /* 현재가                    */
	long    nearprice      ; /* 근월물 의제 약정가격      */
	long    farprice       ; /* 원월물 의제 약정가격      */
	long    open           ; /* 시가                      */
	long    high           ; /* 고가                      */
	long    low            ; /* 저가                      */
	long    volume         ; /* 누적거래량                */
	long    value1         ; /* 누적거래대금1(백만)       */
	long    value2         ; /* 누적거래대금2(천원)       */
	long    nearvolume     ; /* 근월물누적거래량          */
	long    nearvalue1     ; /* 근월물누적거래대금1(백만) */
	long    nearvalue2     ; /* 근월물누적거래대금2(천원) */
	long    farvolume      ; /* 원월물누적거래량          */
	long    farvalue1      ; /* 원월물누적거래대금1(백만) */
	long    farvalue2      ; /* 원월물누적거래대금2(천원) */
	PK_OFHOGA hoga[5]      ; /* 5차선호가          */
	long    hmedotot       ; /* 매도호가 총 수량          */
	long    hmesutot       ; /* 매수호가 총 수량          */
	long    hmedototcnt    ; /* 매도호가 총 건수          */
	long    hmesutotcnt    ; /* 매수호가 총 건수          */
	long    migyul1        ; /* 미결제약정수량(당일잠정)  */
	long    migyul2        ; /* 미결제약정수량(당일확정)  */
	long    realupprc      ; /* 실시간상한가              *//* 추가 2014-09-01 */
	long    realdwprc      ; /* 실시간하한가              *//* 추가 2014-09-01 */
	char    filler3[65]    ; /* filler                    *//* 추가 2014-09-01 */
	char    ff          [1]; /* 0xff               */
	char    cr          [1]; /* 0x0d               */
	char    lf          [1]; /* 0x0a               */
}PK_FUTJONG;

typedef struct _PK_FUTUPDW{ /* 선물 가격제한폭확대발동 */
	char    id         [ 1]; /* Data ID 0x9A              */
	char    infogb     [ 2]; /* 정보구분                  */
	char    markgb     [ 1]; /* 시장구분                  */
	char    item       [12]; /* 종목코드                  */
	char    itmidx     [ 4]; /* 종목일련번호              */
	char    stm        [ 8]; /* 가격확대시각              */
	char    upprstp    [ 2]; /* 가격제한확대상한단계      */
	char    dwprstp    [ 2]; /* 가격제한확대하한단계      */
	char    upprc      [12]; /* 상한가 X99999999.99       */
	char    dwprc      [12]; /* 하한가 X99999999.99       */
	char    filler     [21]; /* filler                    */
	char    ff          [1]; /* 0xff               */
	char    cr          [1]; /* 0x0d               */
	char    lf          [1]; /* 0x0a               */
}PK_FUTUPDW;


/*****************************************************************************/
/* 옵션                                                                      */
/*****************************************************************************/

typedef struct _PK_OPTMST{ /* 옵션 Master  */
	char    id          [1]; /* Data ID 'c'           */
	char    filler      [3]; /* Filler                */
	long    index          ; /* 일련번호              */
	char    expcode    [12]; /* 국제표준코드          */
	char    hname      [30]; /* 종목명                */
	char    optkind     [1]; /* 옵션종류 2:CALL, 3:PUT */
	char    hangsagb    [1]; /* 권리행사유형 1:유럽 2:미국 3:기타 */
	long    mangi          ; /* 만기년월              */
	long    actprc         ; /* 행사가격              */
	long    listdt         ; /* 상장일                */
	long    lastdt         ; /* 최종거래일            */
	long    baseprc        ; /* 기준가                */
	long    upprc          ; /* 상한가                */
	long    dwprc          ; /* 하한가                */
	long    bclose         ; /* 전일종가              */
	long    bmigyulqty     ; /* 전일미결제약정        */
	long    bvolume        ; /* 전일거래량  (계약)    */
	long    bvalue1        ; /* 전일거래대금 1(백만)  */
	long    bvalue2        ; /* 전일거래대금 2(원)    */
	long    listdt2        ; /* 입회일자              */
	char    trstobj     [2]; /* 거래대상종목 '01' kospi200 */
	char    ename      [30]; /* 영문명                */
	char    shname     [14]; /* 축약명                */
	short   basisdtcnt     ; /* 기준일수              */
	short   remaindtcnt    ; /* 잔존일수              */
	char    offsetgb    [1]; /* 근월물구분 1:최근월물 2:비해당 3:최원월물 */
	char    atmgb       [1]; /* ATM구분 1:ATM 2:ITM 3:OTM */
	long    startmemedt    ; /* 최초거래일            */
	char    lastmemedtgb[1]; /* 최종거래일구분 1:평일 2:거래최종일 */
	char    newitemgb   [1]; /* 신규/추가/기존구분    */
	char    bclosegb    [1]; /* 전일종가구분 1:당일종가 2:당일기세 3:거래없음 */
	char    trmarginprcgb[1]; /* 매매증거금기준가구분 1:당일종가 2:당일기세 3:전일증거금 4:당일증거금이론가 ' ':기준가없음*/
	long    newitemdt      ; /* 신규/추가/기존일      */
	long    nowdivid       ; /* 배당액지수현재가치    */
	long    theoryprc      ; /* 이론가                */
	long    bopen          ; /* 전일시가              */
	long    bhigh          ; /* 전일고가              */
	long    blow           ; /* 전일저가              */
	long    trmarginprc    ; /* 매매증거금기준가      */
	long    prcunit        ; /* 가격단위 기준값 3.00  */
	short   hogaunit1      ; /* 호가단위 0.01         */
	short   hogaunit2      ; /* 호가단위 0.05         */
	long    cdrate         ; /* cd금리 단위:%, 전일 11시경 호가수익률 */
	long    yearhighdt     ; /* 연중 최고일자         */
	long    yearhighprc    ; /* 연중 최고가격         */
	long    yearlowdt      ; /* 연중 최저일자         */
	long    yearlowprc     ; /* 연중 최저가격         */
	long    listinghighdt  ; /* 상장중 최고일자       */
	long    listinghighprc ; /* 상장중 최고가격       */
	long    listinglowdt   ; /* 상장중 최저일자       */
	long    listinglowprc  ; /* 상장중 최저가격       */
	char    markryn     [1]; /* 시장가 허용구분 [Y:허용  N:제한] */
	char    condjiryn   [1]; /* 조건부지정가 허용구분 [Y:허용  N:제한] */
	char    choiyoujiryn[1]; /* 최유리지정가 허용구분 [Y:허용  N:제한] */
	char    baseprcgb   [1]; /* 기준가구분 1:전일증거금 2:전일 3:당일 4:전일기세 */
	long    interchange    ; /* 내재변동성 소수3자리  */
	long    dealamt        ; /* 거래승수              *//* 신규추가 2012-02-10 */
	long    realupprc      ; /* 실시간상한가간격      *//* 추가 2014-09-01 */
	long    realdwprc      ; /* 실시간하한가간격      *//* 추가 2014-09-01 */
	char    realupdwgb[1]  ; /* 실시간가격제한여부    *//* 추가 2014-09-01 */
	char    prclimtcd[1]   ; /* 가격제한확대적용방향코드*//* 2015-06-15 추가 */
	short   prclimtlast    ; /* 가격제한최종단계      *//* 2015-06-15 추가 */
	long    prclimt1upprc  ; /* 가격제한1단계상한가   *//* 2015-06-15 추가 */
	long    prclimt1dwprc  ; /* 가격제한1단계하한가   *//* 2015-06-15 추가 */
	long    prclimt2upprc  ; /* 가격제한2단계상한가   *//* 2015-06-15 추가 */
	long    prclimt2dwprc  ; /* 가격제한2단계하한가   *//* 2015-06-15 추가 */
	long    prclimt3upprc  ; /* 가격제한3단계상한가   *//* 2015-06-15 추가 */
	long    prclimt3dwprc  ; /* 가격제한3단계하한가   *//* 2015-06-15 추가 */
	char    filler3[13]    ; /* filler                *//* 변경 2015-06-15 [27->13]*/
	char    ff          [1]; /* 0xff               */
	char    cr          [1]; /* 0x0d               */
	char    lf          [1]; /* 0x0a               */
}PK_OPTMST;

typedef struct _PK_OPTJONG{ /* 옵션 시세 */
	char    id          [1]; /* Data ID 'd'               */
	char    filler      [1]; /* Filler                    */
	short   jgubun         ; /* 장구분 9:Mst후, 1,2,3,4,5 */
	long    index          ; /* 종목 일련번호             */
	long    stime          ; /* 시세발생시간              */
	short   trgubun        ; /* 거래구분                  */
	short   gisegb         ; /* 기세구분                  */
	long    cbtime         ; /* C.B 발생시간              */
	long    price          ; /* 현재가                    */
	long    open           ; /* 시가                      */
	long    high           ; /* 고가                      */
	long    low            ; /* 저가                      */
	long    volume         ; /* 누적거래량                */
	long    value1         ; /* 누적거래대금1(백만)       */
	long    value2         ; /* 누적거래대금2(천원)       */
	PK_OFHOGA hoga[5]      ; /* 5차선호가          */
	long    hmedotot       ; /* 매도호가 총 수량          */
	long    hmesutot       ; /* 매수호가 총 수량          */
	long    hmedototcnt    ; /* 매도호가 총 건수          */
	long    hmesutotcnt    ; /* 매수호가 총 건수          */
	long    migyul1        ; /* 미결제약정수량(당일잠정)  */
	long    migyul2        ; /* 미결제약정수량(당일확정)  */
	long    realupprc      ; /* 실시간상한가간격      *//* 추가 2014-09-01 */
	long    realdwprc      ; /* 실시간하한가간격      *//* 추가 2014-09-01 */
	char    filler3[47]    ; /* filler                *//* 추가 2014-09-01 */
	char    ff          [1]; /* 0xff               */
	char    cr          [1]; /* 0x0d               */
	char    lf          [1]; /* 0x0a               */
}PK_OPTJONG;

typedef struct _PK_OPTUPDW{ /* 옵션 가격제한폭확대발동 */
	char    id         [ 1]; /* Data ID 0x9B              */
	char    infogb     [ 2]; /* 정보구분                  */
	char    markgb     [ 1]; /* 시장구분                  */
	char    item       [12]; /* 종목코드                  */
	char    itmidx     [ 4]; /* 종목일련번호              */
	char    stm        [ 8]; /* 가격확대시각              */
	char    upprstp    [ 2]; /* 가격제한확대상한단계      */
	char    dwprstp    [ 2]; /* 가격제한확대하한단계      */
	char    upprc      [12]; /* 상한가 X99999999.99       */
	char    dwprc      [12]; /* 하한가 X99999999.99       */
	char    filler     [21]; /* filler                    */
	char    ff          [1]; /* 0xff               */
	char    cr          [1]; /* 0x0d               */
	char    lf          [1]; /* 0x0a               */
}PK_OPTUPDW;


/*****************************************************************************/
/* _PK_STOPTIONMST (주식옵션 기본 데이타 구성)                               */
/*****************************************************************************/
typedef struct _PK_STOPTIONMST{
	char    id          [1]; /* 01. Data ID 'e'         */
	char    filler      [3]; /* 02. Filler              */
	long    ymd            ; /* 03. 입회일자            */
	long    index          ; /* 04. 종목 SEQ 번호       */
	char    expcode    [12]; /* 05. 종목코드 10:현대차 11:포항제철 12:삼성전자 13:한국전력 14:SK텔레콤 15:한국통신 16: 국민은행*/
	char    optkind     [1]; /* 06. 옵션종류 2:CALL, 3:PUT */
	char    trstobj     [2]; /* 07. 거래대상주식        */
	char    filler2     [1]; /* 08. Filler              */
	long    mangi          ; /* 09. 만기년월  [yyyymm]  */
	long    actprc1        ; /* 10. 행사가격 정수부문(8자리) */
	long    actprc2        ; /* 11. 행사가격 소수점부분(8자리) */
	long    trunit1        ; /* 12. 거래단위 정수부문(8자리) */
	long    trunit2        ; /* 13. 거래단위 소수점부분(8자리) */
	long    seaseqno       ; /* 14. 조회 SEQ NO         */
	char    hname      [50]; /* 15. 한글종목명          */
	char    ename      [50]; /* 16. 영문종목명          */
	char    shname     [25]; /* 17. 종목축약명          */
	char    rigtygb     [1]; /* 18. 권리행사유형구분 [1:유럽형 2:미국형]*/
	short   listdtcnt      ; /* 19. 상장일수            */
	short   surdtcnt       ; /* 20. 잔존일수            */
	char    nearmonthgb [1]; /* 21. 최근월물구분[1:최근월물 2:기타] */
	char    atmgb       [1]; /* 22. ATM 구분 [1:ATM 2:ITM 3:OTM]*/
	long    listdt         ; /* 23. 상장일              */
	long    fristtrdt      ; /* 24. 최초거래일          */
	long    finaltrdt      ; /* 25. 최종거래일          */
	char    finaltrdtgb [1]; /* 26. 최종거래일 구분 [1:신규 2:추가 3:기존 4:최초 5:조정 6:특별]*/
	char    shcodelistgb[1]; /* 27. 종목상장구분        */
	char    filler3     [2]; /* 28. Filler              */
	long    shcodelistdt   ; /* 29. 종목상장작업일      */
	long    divjisuprc1    ; /* 30. 배당액지수 현재가치 정수 */
	long    divjisuprc2    ; /* 31. 배당액지수 현재가치 소수점(6자리) */
	long    theprc1        ; /* 32. 이론가 정수         */
	long    theprc2        ; /* 33. 이론가 소수점(6자리)*/
	long    bopen          ; /* 34. 전일시가            */
	long    bhigh          ; /* 35. 전일고가            */
	long    blow           ; /* 36. 전일저가            */
	long    bclose         ; /* 37. 전일종가            */
	long    memgnbprc      ; /* 38. 매매증거금기준가    */
	char    bclosegb    [1]; /* 39. 전일종가구분 [1:실세 2:기세 3:거래없음]*/
	char    memgnbprcgb [1]; /* 40. 매매증거금기준가 구분 [1:당일종가(실세) 2:당일기세(종가미형성) 3:전일증거금기준가(종가미형성) 4:당일증거금이론가(종가미형성) 5:조정전일증거금기준가(종가미형성)]*/
	char    filler4     [2]; /* 41. Filler              */
	long    uplmhgrange    ; /* 42. 정상호가 범위(상한치) */
	long    dnlmhgrange    ; /* 43. 정상호가 범위(하한치) */
	long    cdrate         ; /* 44. CD 금리 (소수점 3자리)*/
	long    bmigyulqty     ; /* 45. 전일미결제약정수량  */
	long    btrqty         ; /* 46. 전일거래량          */
	long    btrprc1        ; /* 47. 전일거래대금 (단위: 백만원) */
	long    btrprc2        ; /* 48. 전일거래대금 (단위: 원) */
	long    yearhighdt     ; /* 49. 연중 최고일자       */
	long    yearhighprc    ; /* 50. 연중 최고가격       */
	long    yearlowdt      ; /* 51. 연중 최저일자       */
	long    yearlowprc     ; /* 52. 연중 최저가격       */
	long    listinghighdt  ; /* 53. 상장중 최고일자     */
	long    listinghighprc ; /* 54. 상장중 최고가격     */
	long    listinglowdt   ; /* 55. 상장중 최저일자     */
	long    listinglowprc  ; /* 56. 상장중 최저가격     */
	char    markryn     [1]; /* 57. 시장가 허용구분 [Y:허용  N:제한] */
	char    condjiryn   [1]; /* 58. 조건부지정가 허용구분 [Y:허용  N:제한] */
	char    choiyoujiryn[1]; /* 59. 최유리지정가 허용구분 [Y:허용  N:제한] */
	char    baseprcgb   [1]; /* 60. 기준가 구분 [1:전일기준가증거금 2:전일기준가 3:당일이론가 4:전일기세 5:조정전일증거금기준가 6:조정전일기준가 7:조정전일기세]*/
	long    baseprc        ; /* 61. 기준가              */
	long    immanmov       ; /* 62. 내재변동성 (소수점 3자리) */
	char    jojunggb    [1]; /* 63. 조정구분 [SPACE :정상 0: 미결제조정 C: 거래단위조정 */
	char    trstopyn    [1]; /* 64. 거래정지여부 [Y:허용  N:제한]*/
	char    mechenu     [1]; /* 65. 매매체결방법 [N:정상  U:단일가체결]*/
	char    bassetshcode[12];/* 66. 기초자산종목코드    */
	long    vwactprc        ;/* 67. 행상가격조회용      */
	char    filler5    [1 ]; /* 67. Filler              */
	char    prclimtcd[1]   ; /* 가격제한확대적용방향코드*//* 2015-06-15 추가 */
	short   prclimtlast    ; /* 가격제한최종단계      *//* 2015-06-15 추가 */
	long    prclimt1upprc  ; /* 가격제한1단계상한가   *//* 2015-06-15 추가 */
	long    prclimt1dwprc  ; /* 가격제한1단계하한가   *//* 2015-06-15 추가 */
	long    prclimt2upprc  ; /* 가격제한2단계상한가   *//* 2015-06-15 추가 */
	long    prclimt2dwprc  ; /* 가격제한2단계하한가   *//* 2015-06-15 추가 */
	long    prclimt3upprc  ; /* 가격제한3단계상한가   *//* 2015-06-15 추가 */
	long    prclimt3dwprc  ; /* 가격제한3단계하한가   *//* 2015-06-15 추가 */
	char    filler6    [34]; /* 67. Filler              */
	char    ff          [1]; /* 0xff                    */
	char    cr          [1]; /* 0x0d                    */
	char    lf          [1]; /* 0x0a                    */
}PK_STOPTIONMST;

/*****************************************************************************/
/* _PK_STOPTIONJONG (주식옵션 시세)                                          */
/*****************************************************************************/
typedef struct _PK_STOPTIONJONG{
	char    id          [1]; /* Data ID 'f'               */
	char    filler      [1]; /* Filler                    */
	short   jgubun         ; /* 장구분 9:Mst후, 1,5 장마감*/
	long    index          ; /* 종목 일련번호             */
	long    stime          ; /* 시세발생시간              */
	short   trgubun        ; /* 거래구분                  */
	short   gisegb         ; /* 기세구분                  */
	long    cbtime         ; /* C.B 발생시간              */
	long    price          ; /* 현재가                    */
	long    open           ; /* 시가                      */
	long    high           ; /* 고가                      */
	long    low            ; /* 저가                      */
	long    volume         ; /* 누적거래량                */
	long    value1         ; /* 누적거래대금1(백만)       */
	long    value2         ; /* 누적거래대금2(천원)       */
	PK_OFHOGA hoga[5]      ; /* 5차선호가          */
	long    hmedotot       ; /* 매도호가 총 수량          */
	long    hmesutot       ; /* 매수호가 총 수량          */
	long    hmedototcnt    ; /* 매도호가 총 건수          */
	long    hmesutotcnt    ; /* 매수호가 총 건수          */
	long    migyul1        ; /* 미결제약정수량(당일잠정)  */
	long    migyul2        ; /* 미결제약정수량(당일확정)  */
	long    memgnbprc      ; /* 매매증거금기준가          */
	long    actgyulprc1    ; /* 행사결제가격 정수부문(8자리) */
	long    actgyulprc2    ; /* 행사결제가격 소수점부분(8자리) */
	char    memgnbprcgb [1]; /* 매매증거금기준가 구분 [1:당일종가(실세) 2:당일기세(종가미형성) 3:전일증거금기준가(종가미형성) 4:당일증거금이론가(종가미형성) 5:조정전일증거금기준가(종가미형성)]*/
	char    actgyulgb   [1]; /* 행사결제가격 구분     [1:대상자산총가 2:대상자산종가없음 3:SQ 4:조정종가 5:최근일의종가 6:최근일의 조정종가] */
	char    ff          [1]; /* 0xff               */
	char    cr          [1]; /* 0x0d               */
	char    lf          [1]; /* 0x0a               */
}PK_STOPTIONJONG;

typedef struct _PK_STOPUPDW{ /* 개별주식옵션 가격제한폭확대발동 */
	char    id         [ 1]; /* Data ID 0x9D              */
	char    infogb     [ 2]; /* 정보구분                  */
	char    markgb     [ 1]; /* 시장구분                  */
	char    item       [12]; /* 종목코드                  */
	char    itmidx     [ 4]; /* 종목일련번호              */
	char    stm        [ 8]; /* 가격확대시각              */
	char    upprstp    [ 2]; /* 가격제한확대상한단계      */
	char    dwprstp    [ 2]; /* 가격제한확대하한단계      */
	char    upprc      [12]; /* 상한가 X99999999.99       */
	char    dwprc      [12]; /* 하한가 X99999999.99       */
	char    filler     [21]; /* filler                    */
	char    ff          [1]; /* 0xff               */
	char    cr          [1]; /* 0x0d               */
	char    lf          [1]; /* 0x0a               */
}PK_STOPUPDW;

/*****************************************************************************/
/* 공통                                                                      */
/*****************************************************************************/
typedef struct _HEADERNOTICE{
	char    id          [1]; /* DATA ID 0x98          */
	char    gubun       [2]; /* 전송할  Data 의 ID    */
	char	filler      [1];
	long    size           ; /* 전송건수 or 1         */
	char    tail        [3]; /* 0xff, 0xod, 0x0a      */
}HEADERNOTICE;
typedef struct _FOOTERNOTICE{
	char    id          [1]; /* DATA ID 0x98          */
	char    gubun       [2]; /* 전송할  Data 의 ID    */
	char	filler      [1];
	long    size           ; /* 일자                  */
	char    tail        [3]; /* 0xff, 0xod, 0x0a      */
}FOOTERNOTICE;

/*****************************************************************************/
/* _PK_KOSPINOTICE (장내공시)                                                */
/*****************************************************************************/
typedef struct _PK_KOSPINOTICE{
	char    id          [2]; /* Data ID 공시REAL("G1") 공시배치("G2") */
	char    ymd         [8]; /* 일자 YYYYMMDD      */
	char    seq         [4]; /* 일련번호           */
	char    category    [2]; /* 분류               */
	                         /* 당일(01) 익일(02) 상장안내(03) 시장조치(04) */
	                         /* 관리지정예고(05) 상장폐지유예예고(06)       */
	                         /* 기타안내(07) 장외공시(08) 지배주주 공시(09) */
	char    procgb      [1]; /* 처리구분 정상(1) 정정(2) 취소(3) */
	char    code       [12]; /* 종목코드           */
	char    gb1         [2]; /* 대분류             */
	char    gb2         [2]; /* 중분류             */
	char    gb3         [3]; /* 소분류             */
	char    page        [3]; /* 페이지번호         */
	char    line        [2]; /* 내용순번           */
	char    text      [132]; /* 내용 TITLE(00) 내용(01-29) END(99) */
	char    ff          [1]; /* 0xff               */
	char    cr          [1]; /* 0x0d               */
	char    lf          [1]; /* 0x0a               */
}PK_KOSPINOTICE;

/*****************************************************************************/
/* PK_KOSDAQNOTICE (코스닥공시)                                              */
/*****************************************************************************/
typedef struct _PK_KOSDAQNOTICE{
	char    id          [2]; /* Data ID 공시REAL("OG") 공시배치("ON") */
	char    seq         [6]; /* 일련번호           */
	char    ymd         [8]; /* 일자 YYYYMMDD      */
	char    code       [12]; /* 종목코드           */
	char    procgb      [1]; /* 처리구분 정상(1) 정정(2) 취소(3) */
	char    gb          [3]; /* 사유               */
	char    lang        [1]; /* 국문영문구분 국문(1) 영문(2) */
	char    page        [3]; /* 페이지번호         */
	char    line        [2]; /* 내용순번           */
	char    text      [132]; /* 내용 TITLE(00) 내용(01-29) END(99) */
	char    ff          [1]; /* 0xff               */
	char    cr          [1]; /* 0x0d               */
	char    lf          [1]; /* 0x0a               */
}PK_KOSDAQNOTICE;


/*****************************************************************************/
/* PK_KOSDAQETFNAV (코스닥 ETF-NAV)     [2003-04-28 추가]                    */
/*****************************************************************************/
typedef struct _PK_KOSDAQETFNAV{
	char    id          [1]; /* 'Q'                */
	char    filler1     [1]; /* filler             */
	char    code       [12]; /* ETF 종목코드       */
	char    time        [6]; /* 시간(HHMMSS) 장종료시:"JSAMOO", 최종NAV시:"ENDNAV" */
	char    filler2     [1]; /* filler             */
	char    bnav        [9]; /* 전일NAV  9999999V99   */
	char    nav         [9]; /* 장중/최종 NAV  9999999V99   */
	char    erryulper   [1]; /* 추적오차율부호     */
	char    erryul      [9]; /* 추적오차율         */
	char    disyulper   [1]; /* 괴리율부호         */
	char    disyul      [9]; /* 괴리율             */
	char    ff          [1]; /* 0xff               */
	char    cr          [1]; /* 0x0d               */
	char    lf          [1]; /* 0x0a               */
}PK_KOSDAQETFNAV;


/*****************************************************************************/
/* PK_KOSDAQETFPDF (코스닥 ETF-PDF)       [2003-04-28 추가]                  */
/*****************************************************************************/
typedef struct _PK_KOSDAQETFPDF{
	char    id          [1]; /* 'R'                */
	char    filler1     [1]; /* filler             */
	char    index       [6]; /* 전송일련번호       */
	char    ymd         [8]; /* 적용일자 (YYYYMMDD)*/
	char    sutakno     [3]; /* 사무수탁회번호     */
	char    code       [12]; /* ETF 코드           */
	char    etfjongcnt  [4]; /* 구성종목수         */
	char    etfjongcode[12]; /* 구성종목코드       */
	char    icuunitcnt [10]; /* ICU단위 증권사     */
	char    filler2    [62]; /* filler             */
	char    ff          [1]; /* 0xff               */
	char    cr          [1]; /* 0x0d               */
	char    lf          [1]; /* 0x0a               */
}PK_KOSDAQETFPDF;


/*****************************************************************************/
/* PK_ELWMST ELW 종목마스터                                                  */
/*****************************************************************************/
typedef struct _PK_ELWMST{
	char    id             [1 ]; /*A FRAME_ID '0x71'         */
	char    filler1        [3 ]; /*A FILLER                  */
	long    index              ; /*B 코드일련번호            */
	char    shcode         [10]; /*A 종목코드                */
	char    expcode        [12]; /*A 신코드                  */
	char    hname          [40]; /*A 종목명                  */
	char    ename          [40]; /*A 종목명(영문)            */
	char    cpygb          [2 ]; /*A 소속부 구분             */
	long    faceval            ; /*B 액면가                  */
	long    baseprc            ; /*B 기준가                  */
	long    bopen              ; /*B 전일 시가               */
	long    bhigh              ; /*B 전일 고가               */
	long    blow               ; /*B 전일 저가               */
	long    bclose             ; /*B 전일 종가               */
	long    bvolume            ; /*B 전일 거래량             */
	long    bamt               ; /*B 전일 거래대금           */
	long    upprc              ; /*B 상한가                  */
	long    dwprc              ; /*B 하한가                  */
	long    trdunit            ; /*B 매매수량단위            */
	long    capital            ; /*B 자본금                  */
	long    listcnt            ; /*B 상장주식수              */
	short   elw_lp1            ; /*B LP-회원번호-1           */
	short   elw_lp2            ; /*B LP-회원번호-2           */
	short   elw_lp3            ; /*B LP-회원번호-3           */
	short   elw_lp4            ; /*B LP-회원번호-4           */
	short   elw_lp5            ; /*B LP-회원번호-5           */
	short   elw_lp6            ; /*B LP-회원번호-6           */
	short   elw_lp7            ; /*B LP-회원번호-7           */
	short   elw_lp8            ; /*B LP-회원번호-8           */
	short   elw_lp9            ; /*B LP-회원번호-9           */
	short   elw_lp10           ; /*B LP-회원번호-10          */
	char    elw_isshnm     [40]; /*A ELW 한글발행기관명      */
	char    elw_issenm     [40]; /*A ELW 영문발행기관명      */
	char    elw_cd         [12]; /*A ELW 발행기관코드        */
	char    elw_baseamt1   [12]; /*A ELW 기초자산1           */
	char    elw_baseamt2   [12]; /*A ELW 기초자산2           */
	char    elw_baseamt3   [12]; /*A ELW 기초자산3           */
	char    elw_baseamt4   [12]; /*A ELW 기초자산4           */
	char    elw_baseamt5   [12]; /*A ELW 기초자산5           */
	long    elw_baseamtrt1     ; /*B ELW 기초자산구성비율-1  */
	long    elw_baseamtrt2     ; /*B ELW 기초자산구성비율-2  */
	long    elw_baseamtrt3     ; /*B ELW 기초자산구성비율-3  */
	long    elw_baseamtrt4     ; /*B ELW 기초자산구성비율-4  */
	long    elw_baseamtrt5     ; /*B ELW 기초자산구성비율-5  */
	long    elw_baseamtprc1    ; /*B ELW 기초가격(정수부)    */
	long    elw_baseamtprc2    ; /*B ELW 기초가격(소수부)    */
	long    elw_actprc1        ; /*B ELW 행사가격(정수부)    */
	long    elw_actprc2        ; /*B ELW 행사가격(소수부)    */
	char    elw_hangsagb   [2 ]; /*A ELW 권리유형            */
	char    elw_hangsagb1  [2 ]; /*A ELW 권리행사방식        */
	char    elw_hangsainfo[100]; /*A ELW 권리내용            */
	char    elw_settle     [2 ]; /*A ELW 결제방법            */
	char    filler2        [2 ]; /*A filler                  */
	long    elw_fintrddt       ; /*B ELW 최종거래일          */
	long    elw_chgrt1         ; /*B ELW 전환비율(정수부)    */
	long    elw_chgrt2         ; /*B ELW 전환비율(소수부)    */
	long    elw_prcuprt        ; /*B ELW 가격상승참여율      */
	long    elw_remrt          ; /*B ELW 보상율              */
	long    elw_supdt          ; /*B ELW 지급일              */
	char    elw_suppro     [20]; /*A ELW 지급대리인          */
	char    elw_mangiprc  [100]; /*A ELW 만기평가가격방식    */
	char    elw_tujajigb   [2 ]; /*A ELW 투자지표산출여부    */
	char    elw_lpposgb    [2 ]; /*A LP주문가능여부          */
	long    listdt             ; /*B 상장일                  */
	long    lpminhogaqty       ; /*B LP최소호가수량배수      */
	long    lpposqty           ; /*B LP 보유수량             */
	char    kospi_gb       [2 ]; /*A KOSPI여부               */
	char    trgubun2       [2 ]; /*A 거래정지사유            */
	char    basetrswh      [3 ]; /*A 자산기준통화            */
	char    filler3        [1 ]; /*A filler                  */
	long    elw_sp             ; /*B 스프레드                */
	char    filler4        [ 5]; /*A filler                  */
	char    ff             [ 1]; /* 0xff                     */
	char    cr             [ 1]; /* 0x0d                     */
	char    lf             [ 1]; /* 0x0a                     */
}PK_ELWMST;

typedef struct _PK_ELWJONG{
	char    id          [1]; /* 체결‘0x74’, 호가‘0x75‘ lp 호가’0x76‘ */
	char    filler1     [2]; /*A FILLER                  */
	char    vol_gb      [1]; /* 잔량구분  0:장중 1:장종료후시간외 2:장개시전시간외 3:시간외단일가마감*//* 2005-05-30 구분추가 */
	long    index          ; /* 일련번호              */
	char    stime       [6]; /* 증전전송시간          */
	char    updown      [1]; /* 등락구분              */
	char    dongsigb    [1]; /* 동시구분  0:접속, 1:동시, 2:동시연장 */
	long    daebi          ; /* 대비                  */
	long    price          ; /* 현재가                */
	long    cheqty         ; /* 거래량                */
	long    open           ; /* 시가                  */
	long    high           ; /* 고가                  */
	long    low            ; /* 저가                  */
	long    volume         ; /* 누적거래량            */
	long    amt            ; /* 누적거래대금(백만)    */
	PK_ELWHOGA hoga[10]    ; /* 10차선호가            */
	long    hgmedotot      ; /* 10단계 매도잔량합계   */
	long    hgmesutot      ; /* 10단계 매수잔량합계   */
	long    lphgmedotot    ; /* LP 매도잔량합계       */
	long    lphgmesutot    ; /* LP 매수잔량합계       */
	char    finmemegb   [1]; /* 최종매도매수구분코드 1:매도 2:매수 */
	char    ff          [1]; /* 0xff                  */
	char    cr          [1]; /* 0x0d                  */
	char    lf          [1]; /* 0x0a                  */
}PK_ELWJONG;

typedef struct _PK_ELWCHE{
	PK_ELWJONG   jp;
	char            shcode[6];
	long            dif;
}PK_ELWCHE;

/*****************************************************************************/
/* PK_STFUMST 개별주식선물 종목마스터                                        */
/*****************************************************************************/
typedef struct _PK_STFUMST{
	char    id             [1 ]; /*A[1 ] FRAME_ID                 */
	char    filler         [3 ]; /*A[1 ] FILLER                   */
	long    index              ; /*B[4 ] 코드일련번호             */
	char    shcode         [8 ]; /*A[8 ] 종목코드(단축코드)       */
	char    expcode        [12]; /*A[12] 신코드                   */
	char    hname          [50]; /*A[50] 종목명                   */
	char    ename          [50]; /*A[50] 종목명(영문)             */
	char    sht_hname      [25]; /*A[25] 축약종목명               */
	char    sht_shcode     [4 ]; /*A[4 ] 선물종목 단축코드        */
	char    offsetgb       [1 ]; /*A[1 ] 최근 월물 여부           */
	char    filler2        [2 ]; /*A[1 ] filler                   */
	long    listdt             ; /*B[4 ] 상장일                   */
	short   listdtcnt          ; /*B[2 ] 상장일수                 */
	short   remaindtcnt        ; /*B[2 ] 잔존일수                 */
	long    finaltrdt          ; /*B[4 ] 최종거래일               */
	char    finaltrdtgb    [1 ]; /*A[1 ] 최종거래일여부           */
	char    trmarginprcgb  [1 ]; /*A[1 ] 기준가격구분             */
	char    bjungprcgb     [1 ]; /*A[1 ] 전일정산가격구분         */
	char    bclosegb       [1 ]; /*A[1 ] 전일종가구분             */
	long    futdivid1          ; /*B[4 ] 배당액지수미래가치1      */
	long    futdivid2          ; /*B[4 ] 배당액지수미래가치2      */
	long    baseprc            ; /*B[4 ] 기준가격                 */
	long    jungsanprc1        ; /*B[4 ] 이론가격(정산가)1        */
	long    jungsanprc2        ; /*B[4 ] 이론가격(정산가)2        */
	long    theoryprc1         ; /*B[4 ] 이론가격(기준가)1        */
	long    theoryprc2         ; /*B[4 ] 이론가격(기준가)2        */
	long    cdrate             ; /*B[4 ] CD금리                   */
	long    upprc              ; /*B[4 ] 상한가                   */
	long    dwprc              ; /*B[4 ] 하한가                   */
	long    bfjungsanprc1      ; /*B[4 ] 전일정산가격1            */
	long    bfjungsanprc2      ; /*B[4 ] 전일정산가격2            */
	long    bclose             ; /*B[4 ] 전일종가                 */
	long    bvolume            ; /*B[4 ] 전일체결수량             */
	long    lst_nearby_volume  ; /*B[4 ] 전일 근월물 체결수량     */
	long    lst_far_volume     ; /*B[4 ] 전일 원월물 체결수량     */
	long    bvalue             ; /*B[4 ] 전일체결대금             */
	long    lst_nearby_value   ; /*B[4 ] 전일 근월물 체결대금     */
	long    lst_far_value      ; /*B[4 ] 전일 원월물 체결대금     */
	long    bmigyulqty         ; /*B[4 ] 전일미결제약정수량       */
	long    listinghighdt      ; /*B[4 ] 상장중최고가일자         */
	long    listinghighprc     ; /*B[4 ] 상장중최고가             */
	long    listinglowdt       ; /*B[4 ] 상장중최저가일자         */
	long    listinglowprc      ; /*B[4 ] 상장중최저가             */
	char    markryn        [1 ]; /*A[1 ] 시장가허용구분           */
	char    condjiryn      [1 ]; /*A[1 ] 조건부 지정가 허용 구분  */
	char    choiyoujiryn   [1 ]; /*A[1 ] 최유리 지정가 허용 구분  */
	char    lastprcgb      [1 ]; /*A[1 ] 최종결제가구분           */
	long    lastprc1           ; /*B[4 ] 최종결제가격1            */
	long    lastprc2           ; /*B[4 ] 최종결제가격2            */
	long    cbup               ; /*B[4 ] C.B 적용 상한가          */
	long    cblow              ; /*B[4 ] C.B 적용 하한가          */
	long    bspreadnjong       ; /*B[4 ] 전일 스프레드 근월물 종가*/
	long    bspreadfjong       ; /*B[4 ] 전일 스프레드 원월물 종가*/
	char    bspreadnshcode [12]; /*A[12] 스프레드 근월물 표준코드 */
	char    bspreadfshcode [12]; /*A[12] 스프레드 원울물 표준코드 */
	long    trunit1            ; /*B[4 ] 거래단위1(결제승수)      */
	long    trunit2            ; /*B[4 ] 거래단위2(결제승수)      */
	char    market_code_gb [1 ]; /*A[1 ] 시장조성종목여부         */
	char    adj_gb         [1 ]; /*A[1 ] 조정구분                 */
	char    stop_gb        [1 ]; /*A[1 ] 거래정지여부             */
	char    index_method   [1 ]; /*A[1 ] 결제방법                 */
	char    maemae         [1 ]; /*A[1 ] 매매체결방법             */
	char    bassetshcode   [12]; /*A[12] 기초자산 종목코드        */
	char    prd_gb         [2 ]; /*A[2 ] 상품군                   */
	char    filler3        [1 ]; /*A[4 ] filler                   */
	long    offset_rate        ; /*B[4 ] offset_rate              */
	long    realupprc          ; /* 실시간상한가간격              *//* 추가 2014-09-01 */
	long    realdwprc          ; /* 실시간하한가간격              *//* 추가 2014-09-01 */
	char    realupdwgb     [1 ]; /* 실시간가격제한여부            *//* 추가 2014-09-01 */
	char    prclimtcd[1]   ; /* 가격제한확대적용방향코드*//* 2015-06-15 추가 */
	short   prclimtlast    ; /* 가격제한최종단계      *//* 2015-06-15 추가 */
	long    prclimt1upprc  ; /* 가격제한1단계상한가   *//* 2015-06-15 추가 */
	long    prclimt1dwprc  ; /* 가격제한1단계하한가   *//* 2015-06-15 추가 */
	long    prclimt2upprc  ; /* 가격제한2단계상한가   *//* 2015-06-15 추가 */
	long    prclimt2dwprc  ; /* 가격제한2단계하한가   *//* 2015-06-15 추가 */
	long    prclimt3upprc  ; /* 가격제한3단계상한가   *//* 2015-06-15 추가 */
	long    prclimt3dwprc  ; /* 가격제한3단계하한가   *//* 2015-06-15 추가 */
	char    filler4        [5 ];  /*A[1 ] filler                   */
	char    ff             [1 ]; /*A[1 ] FF                       */
	char    cr             [1 ]; /*A[1 ] CR                       */
	char    lf             [1 ]; /*A[1 ] LF                       */
}PK_STFUMST;

typedef struct _PK_STFUJONG{
	char    id              [1]; /* 체결'0x82' 호가‘0x83’       */
	char    filler          [1]; /* Filler                        */
	short   jgubun             ; /* 장구분 9:Mst후, 1,2,3,4,5     */
	long    index              ; /* 종목 일련번호                 */
	long    stime              ; /* 시세발생시간                  */
	long    gisegb             ; /* 기세구분                      */
	long    cbtime             ; /* C.B 발생시간                  */
	long    price              ; /* 현재가                        */
	long    nearprice          ; /* 근월물 의제 약정가격          */
	long    farprice           ; /* 원월물 의제 약정가격          */
	long    open               ; /* 시가                          */
	long    high               ; /* 고가                          */
	long    low                ; /* 저가                          */
	long    volume             ; /* 누적거래량                    */
	long    value1             ; /* 누적거래대금1(백만)           */
	long    value2             ; /* 누적거래대금2(천원)           */
	long    nearvolume         ; /* 근월물누적거래량              */
	long    nearvalue1         ; /* 근월물누적거래대금1(백만)     */
	long    nearvalue2         ; /* 근월물누적거래대금2(천원)     */
	long    farvolume          ; /* 원월물누적거래량              */
	long    farvalue1          ; /* 원월물누적거래대금1(백만)     */
	long    farvalue2          ; /* 원월물누적거래대금2(천원)     */
	PK_OFHOGA hoga[5]          ; /* 5차선호가                     */
	long    hmedotot           ; /* 매도호가 총 수량              */
	long    hmesutot           ; /* 매수호가 총 수량              */
	long    hmedototcnt        ; /* 매도호가 총 건수              */
	long    hmesutotcnt        ; /* 매수호가 총 건수              */
	long    migyul1            ; /* 미결제약정수량(당일잠정)      */
	long    migyul2            ; /* 미결제약정수량(당일확정)      */
	long    realupprc          ; /* 실시간상한가                  *//* 추가 2014-09-01 */
	long    realdwprc          ; /* 실시간하한가                  *//* 추가 2014-09-01 */
	char    filler9        [65]; /*A[65] filler                   */
	char    ff              [1]; /* 0xff                          */
	char    cr              [1]; /* 0x0d                          */
	char    lf              [1]; /* 0x0a                          */
}PK_STFUJONG;

typedef struct _PK_STFUPDW{ /* 개별주식선물 가격제한폭확대발동 */
	char    id         [ 1]; /* Data ID 0x9C              */
	char    infogb     [ 2]; /* 정보구분                  */
	char    markgb     [ 1]; /* 시장구분                  */
	char    item       [12]; /* 종목코드                  */
	char    itmidx     [ 4]; /* 종목일련번호              */
	char    stm        [ 8]; /* 가격확대시각              */
	char    upprstp    [ 2]; /* 가격제한확대상한단계      */
	char    dwprstp    [ 2]; /* 가격제한확대하한단계      */
	char    upprc      [12]; /* 상한가 X99999999.99       */
	char    dwprc      [12]; /* 하한가 X99999999.99       */
	char    filler     [21]; /* filler                    */
	char    ff          [1]; /* 0xff               */
	char    cr          [1]; /* 0x0d               */
	char    lf          [1]; /* 0x0a               */
}PK_STFUPDW;

/*****************************************************************************/
/* PK_MKFUMST 상품선물 종목마스터                                            */
/*****************************************************************************/
typedef struct _PK_MKFUMST{
	char    id             [1 ]; /*A[1 ] FRAME_ID                 */
	char    filler         [3 ]; /*A[1 ] FILLER                   */
	long    index              ; /*B[4 ] 코드일련번호             */
	char    shcode         [8 ]; /*A[8 ] 종목코드(단축코드)       */
	char    expcode        [12]; /*A[12] 신코드                   */
	char    hname          [80]; /*A[80] 종목명                   */
	char    sht_hname      [40]; /*A[40] 축약종목명               */
	char    ename          [80]; /*A[80] 종목명(영문)             */
	char    sht_ename      [40]; /*A[40] 축약종목명(영문)         */
	long    listdt             ; /*B[4 ] 상장일                   */
	long    lastdt             ; /*B[4 ] 페지일                   */
	long    upprc              ; /*B[4 ] 상한가                   */
	long    dwprc              ; /*B[4 ] 하한가                   */
	long    baseprc            ; /*B[4 ] 기준가격                 */
	char    bspreadnshcode [12]; /*A[12] 스프레드 근월물 표준코드 */
	char    bspreadfshcode [12]; /*A[12] 스프레드 원울물 표준코드 */
	long    finaltrdt          ; /*B[4 ] 최종거래일자             */
	long    settledt           ; /*B[4 ] 최종결제일자             */
	char    offsetgb       [1 ]; /*A[1 ] 근월물구분               *//*0:해당없음, 1:최근월물 */
	char    trmarginprcgb  [1 ]; /*A[1 ] 기준가격구분             *//*0:해당없음, 1:실세, 2:기세, 3:이론가, 4:대상자산종가*/
	char    finaltrdtgb    [1 ]; /*A[1 ] 최종거래일여부           */
	char    filler2        [1 ]; /*A[1 ] filler                   */
	long    trunit1            ; /*B[4 ] 거래단위1(정수부)        */
	long    trunit2            ; /*B[4 ] 거래단위2(소수부)        */
	long    dealamt1           ; /*B[4 ] 거래승수1(정수부)        */
	long    dealamt2           ; /*B[4 ] 거래승수2(소수부)        */
	long    remaindtcnt        ; /*B[4 ] 잔존일수                 */
	long    theoryprc1         ; /*B[4 ] 정산이론가격             */
	long    theoryprc2         ; /*B[4 ] 기준이론가격             */
	long    bfjungsanprc       ; /*B[4 ] 전일정산가격             */
	long    bclose             ; /*B[4 ] 전일종가                 */
	long    bopen              ; /*B[4 ] 전일시가                 */
	long    bhigh              ; /*B[4 ] 전일고가                 */
	long    blow               ; /*B[4 ] 전일저가                 */
	long    bmigyulqty         ; /*B[4 ] 전일미결제약정수량       */
	long    interchange        ; /*B[4 ] 내재변동성               */
	long    listinghighprc     ; /*B[4 ] 상장중최고가             */
	long    listinglowprc      ; /*B[4 ] 상장중최저가             */
	long    yearhighprc        ; /*B[4 ] 연중최고가               */
	long    yearlowprc         ; /*B[4 ] 연중최저가               */
	long    listinghighdt      ; /*B[4 ] 상장중최고가일자         */
	long    listinglowdt       ; /*B[4 ] 상장중최저가일자         */
	long    yearhighdt         ; /*B[4 ] 연중최고가일자           */
	long    yearlowdt          ; /*B[4 ] 연중최저가일자           */
	long    bvolume            ; /*B[4 ] 전일체결수량             */
	long    bvalue             ; /*B[4 ] 전일체결대금             */
	long    cdrate             ; /*B[4 ] CD금리                   */
	long    realupprc          ; /* 실시간상한가간격              *//* 추가 2014-09-01 */
	long    realdwprc          ; /* 실시간하한가간격              *//* 추가 2014-09-01 */
	char    realupdwgb[1]      ; /* 실시간가격제한여부            *//* 추가 2014-09-01 */
	char    filler9        [64]; /*A[69] filler                   */
	char    ff             [1 ]; /*A[1 ] FF                       */
	char    cr             [1 ]; /*A[1 ] CR                       */
	char    lf             [1 ]; /*A[1 ] LF                       */
}PK_MKFUMST;

typedef struct _PK_MKFUJONG{
	char    id              [1]; /* 체결'0x86' 호가‘0x87’장마감'0x88' */
	char    filler          [1]; /* Filler                        */
	short   jgubun             ; /* 장구분                        *//* 0:장중, 5:장종료, 9:장마감(종목마감) */
	long    index              ; /* 종목 일련번호                 */
	char    expcode        [12]; /* 표준코드                      */
	long    stime              ; /* 시세발생시간                  */
	long    gisegb             ; /* 기세구분                      */
	long    price              ; /* 현재가                        */
	long    cheqty             ; /* 체결수량                      */
	long    nearprice          ; /* 근월물 의제 약정가격          */
	long    farprice           ; /* 원월물 의제 약정가격          */
	long    open               ; /* 시가                          */
	long    high               ; /* 고가                          */
	long    low                ; /* 저가                          */
	long    volume             ; /* 누적거래량                    */
	long    value1             ; /* 누적거래대금                  */
	long    value2             ; /* 누적거래대금                  */
	long    nearvolume         ; /* 근월물누적거래량              */
	long    nearvalue1         ; /* 근월물누적거래대금1(백만)     */
	long    nearvalue2         ; /* 근월물누적거래대금2(천원)     */
	long    farvolume          ; /* 원월물누적거래량              */
	long    farvalue1          ; /* 원월물누적거래대금1(백만)     */
	long    farvalue2          ; /* 원월물누적거래대금2(천원)     */
	PK_OFHOGA hoga[5]          ; /* 5차선호가                     */
	long    hmedotot           ; /* 매도호가 총 수량              */
	long    hmesutot           ; /* 매수호가 총 수량              */
	long    hmedototcnt        ; /* 매도호가 총 건수              */
	long    hmesutotcnt        ; /* 매수호가 총 건수              */
	long    migyul             ; /* 미결제약정수량(당일잠정)      */
	long    realupprc          ; /* 실시간상한가                  *//* 추가 2014-09-01 */
	long    realdwprc          ; /* 실시간하한가                  *//* 추가 2014-09-01 */
	char    filler9        [57]; /*A[5] filler                    */
	char    ff              [1]; /* 0xff                          */
	char    cr              [1]; /* 0x0d                          */
	char    lf              [1]; /* 0x0a                          */
}PK_MKFUJONG;


typedef struct _PK_MKFUJUNGPRC{
	char    id              [1]; /* FRAME_ID '0x89'               */
	char    filler          [3]; /* Filler                        */
	long    index              ; /* 종목 일련번호                 */
	char    expcode        [12]; /* 표준코드                      */
	long    jungprc            ; /*B[4 ] 정산가격(정수부)         */
	long    settleprc          ; /*B[4 ] 최종결제가격(정수부)     */
	char    jungprcgb       [1]; /*B[4 ] 정산가격구분             */
	char    settleprcgb     [1]; /*B[4 ] 최종결제가격구분         */
	char    filler9         [3]; /* filler                        */
	char    ff              [1]; /* 0xff                          */
	char    cr              [1]; /* 0x0d                          */
	char    lf              [1]; /* 0x0a                          */
}PK_MKFUJUNGPRC;


typedef struct _PK_MKFUMIGYUL{
	char    id              [1]; /* FRAME_ID '0x90'               */
	char    filler          [3]; /* Filler                        */
	long    index              ; /* 종목 일련번호                 */
	char    migyulgb        [1]; /* 미결제 약정구분               */
	char    trddt           [8]; /* 거래일자                      */
	long    migyul             ; /* 미결제약정수량(당일잠정)      */
	char    ff              [1]; /* 0xff                          */
	char    cr              [1]; /* 0x0d                          */
	char    lf              [1]; /* 0x0a                          */
}PK_MKFUMIGYUL;


typedef struct _PK_ELWKOBAMST{
	char    id             [1 ]; /*A[1 ] FRAME_ID                 */
	char    filler         [3 ]; /*A[3 ] FILLER                   */
	long    index              ; /*B[4 ] 코드일련번호             */
	char    expcode        [12]; /*A[12] 신코드                   */
	long    endbaseprc1        ; /*B[4 ] ELW조기종료발생기준가격  */
	long    endbaseprc2        ; /*B[4 ] ELW조기종료발생기준가격  */
	char    hangsainfo     [200];/*A[200]ELW조기종료권리행사내용  */
	char    endpynginfo    [300];/*A[300]ELW조기종료평가가격방식  */
	char    filler1        [9 ]; /*A[9 ] filler                   */
	char    ff             [1 ]; /*A[1 ] FF                       */
	char    cr             [1 ]; /*A[1 ] CR                       */
	char    lf             [1 ]; /*A[1 ] LF                       */
}PK_ELWKOBAMST;

typedef struct _PK_ELWKOBABASE{
	char    id             [1 ]; /*A[1 ] FRAME_ID                 */
	char    filler         [3 ]; /*A[3 ] FILLER                   */
	long    index              ; /*B[4 ] 코드일련번호             */
	char    expcode        [12]; /*A[12] 신코드                   */
	char    tnsdate        [8 ]; /*A[8 ] 전송일자                 */
	char    basememedt     [8 ]; /*A[8 ] 기초자산매매일자         */
	char    kobadt         [8 ]; /*A[8 ] KO발생일자               */
	char    fritem         [12]; /*A[12] 구성종목코드             */
	char    elwjimk        [1 ]; /*A[1 ] ELW지수소속시장구분코드  */
	char    upjigb         [3 ]; /*A[3 ] 지수업종코드             */
	char    ampmgb         [1 ]; /*A[1 ] 오전오후구분코드         */
	char    filler1        [3 ]; /*A[3 ] filler                   */
	long    high               ; /*B[4 ] 고가                     */
	long    low                ; /*B[4 ] 저가                     */
	char    filler2        [5 ]; /*A[9 ] filler                   */
	char    ff             [1 ]; /*A[1 ] FF                       */
	char    cr             [1 ]; /*A[1 ] CR                       */
	char    lf             [1 ]; /*A[1 ] LF                       */
}PK_ELWKOBABASE;


typedef struct _PK_ELWKOBATIME{
	char    id             [1 ]; /*A[1 ] FRAME_ID                 */
	char    filler         [3 ]; /*A[3 ] FILLER                   */
	char    expcode        [12]; /*A[12] 신코드                   */
	char    kobadt         [8 ]; /*A[8 ] KO발생일자               */
	char    kotime         [8 ]; /*A[8 ] KO발생일자 TIME          */
	char    filler1        [5 ]; /*A[5 ] filler                   */
	char    ff             [1 ]; /*A[1 ] FF                       */
	char    cr             [1 ]; /*A[1 ] CR                       */
	char    lf             [1 ]; /*A[1 ] LF                       */
}PK_ELWKOBATIME;


typedef struct _FILE_ELWKOBAMST{
	char    id             [1 ]; /*A[1 ] FRAME_ID                 */
	char    filler         [3 ]; /*A[3 ] FILLER                   */
	char    index          [8 ]; /*B[4 ] 코드일련번호             */
	char    expcode        [12]; /*A[12] 신코드                   */
	char    endbaseprc1    [32]; /*B[4 ] ELW조기종료발생기준가격  */
	char    endbaseprc2    [32]; /*B[4 ] ELW조기종료발생기준가격  */
	char    hangsainfo     [200];/*A[200]ELW조기종료권리행사내용  */
	char    endpynginfo    [300];/*A[300]ELW조기종료평가가격방식  */
	char    filler1        [9 ]; /*A[9 ] filler                   */
	char    ff             [1 ]; /*A[1 ] FF                       */
	char    cr             [1 ]; /*A[1 ] CR                       */
	char    lf             [1 ]; /*A[1 ] LF                       */
}FILE_ELWKOBAMST;


typedef struct _FILE_ELWKOBABASE{
	char    id             [1 ]; /*A[1 ] FRAME_ID                 */
	char    filler         [3 ]; /*A[3 ] FILLER                   */
	char    index          [8 ]; /*B[4 ] 코드일련번호             */
	char    expcode        [12]; /*A[12] 신코드                   */
	char    tnsdate        [8 ]; /*A[8 ] 전송일자                 */
	char    basememedt     [8 ]; /*A[8 ] 기초자산매매일자         */
	char    kobadt         [8 ]; /*A[8 ] KO발생일자               */
	char    fritem         [12]; /*A[12] 구성종목코드             */
	char    elwjimk        [1 ]; /*A[12] ELW지수소속시장구분코드  */
	char    upjigb         [3 ]; /*A[3 ] 지수업종코드             */
	char    ampmgb         [1 ]; /*A[1 ] 오전오후구분코드         */
	char    filler1        [3 ]; /*A[3 ] filler                   */
	char    high           [32]; /*B[4 ] 고가                     */
	char    low            [32]; /*B[4 ] 저가                     */
	char    filler2        [9 ]; /*A[5 ] filler                   */
	char    ff             [1 ]; /*A[1 ] FF                       */
	char    cr             [1 ]; /*A[1 ] CR                       */
	char    lf             [1 ]; /*A[1 ] LF                       */
}FILE_ELWKOBABASE;


typedef struct _FILE_ELWKOBATIME{
	char    expcode        [12]; /*A[12] 신코드                   */
	char    kobadt         [8 ]; /*A[8 ] KO발생일자               */
	char    kotime         [8 ]; /*A[8 ] KO발생일자 TIME          */
}FILE_ELWKOBATIME;

#endif  /* __SISEPK_H__ */
/*****************************************************************************/
