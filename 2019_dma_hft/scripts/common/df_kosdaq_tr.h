// df_kosdaq_tr.h
// 코스닥주식 실시간 TR

#pragma once
// 주석에 \n이 들어간건 나중에 이쁘게 바꿔야함

#include "df_stock_common_tr.h"


// 코스닥 TR예상지수
typedef struct _DF_KOSDAQ_TR_EXP_IDX {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA구분, ※개발가이드 참조
	char info_clsf[3];	// 정보구분, 01:주식
	char mkt_clsf;	// 시장구분, 1:유가증권 2:코스닥 9:해외주가지수 2012.04.30 추가
	char ind_clsf[4];	// 업종코드, ※개발가이드 참조
	char time[7];	// 시간, ※개발가이드 참조   ※해외주가지수일 경우 GMT시간
	int idx;	// 지수, 9(6)V9(2)
	char sign;	// 부호, +:상승 "-":하락 " ":보합
	double crst;	// 대비, 999999V99
	int ccls_qty;	// 체결수량, 단위:천주  ※해외주가지수일 경우 FILLER처리
	int trd_val;	// 거래대금, 단위:백만원  ※해외주가지수일 경우 FILLER처리
} DF_KOSDAQ_TR_EXP_IDX;


// 코스닥 TR지수
typedef struct _DF_KOSDAQ_TR_IDX {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA구분, ※개발가이드 참조
	char info_clsf[3];	// 정보구분, 01:주식
	char mkt_clsf;	// 시장구분, 1:유가증권 2:코스닥 9:해외주가지수 2012.04.30 추가
	char ind_clsf[4];	// 업종코드, ※개발가이드 참조
	char time[7];	// 시간, ※개발가이드 참조   ※해외주가지수일 경우 GMT시간
	int idx;	// 지수, 9(6)V9(2)
	char sign;	// 부호, +:상승 "-":하락 " ":보합
	double crst;	// 대비, 999999V99
	int ccls_qty;	// 체결수량, 단위:천주  ※해외주가지수일 경우 FILLER처리
	int trd_val;	// 거래대금, 단위:백만원  ※해외주가지수일 경우 FILLER처리
} DF_KOSDAQ_TR_IDX;


// 코스닥_체결
typedef struct _DF_KOSDAQ_CCLS {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA구분, A3
	char info_clsf[3];	// 정보구분, 01:주식 02:ELW
	char mkt_clsf;	// 시장구분, 1:유가증권 2:코스닥
	char isin_code[13];	// 종목코드, 표준코드
	int stk_snr;	// 종목일련번호, 종목배치(A0)의 종목SEQ
	char brd_id[3];	// 보드ID, ※ 코드값모음 참조
	char ctrs_clsf;	// 전일대비(기준가대비) 구분, 0:판단불가 1:상한 2:상승 3:보합 4:하한 5:하락 ※ 정규시간외구분코드 값이 4인 경우 당일 종가 대비 ※ 정규시간외구분코드 값이 7,8인 경우 Buy-in기준가 대비
	int prev_ctrs;	// 전일대비, 단위:원 신주인수권 증서/증권의 신규 상장 당일 : 0
	int ccls_prc;	// 체결가격, 단위:원
	double ccls_qty;	// 체결수량, 단위:주
	char sess_id[3];	// 세션ID, ※ 코드값모음 참조
	int open;	// 시가, 단위:원 ※개발가이드 참조
	int hi;	// 고가, 단위:원 ※개발가이드 참조
	int low;	// 저가, 단위:원 ※개발가이드 참조
	double cum_ccls_qty;	// 누적체결수량, 단위:주 ※보드ID별로 누적됨
	double cum_trd_val;	// 누적거래대금, 단위:주 ※보드ID별로 누적됨
	char fin_bid_ask_clsf_code;	// 최종매도매수구분코드, 1:매도 2:매수
	char mtc_flg;	// 체결가와1호가일치여부, 0:판단불가 1:일치 2:불일치
	char ccls_time[7];	// 체결시각, HHMMSS
	double lp_hld_qty;	// LP보유수량, LP(체결기준) 집계후 LP보유수량
	int ask_1_prc;	// 매도1호가, 단위:원 ※개발가이드 참조
	int bid_1_prc;	// 매수1호가, 단위:원 ※개발가이드 참조
} DF_KOSDAQ_CCLS;


// 코스닥_기준가결정
typedef struct _DF_KOSDAQ_BASE_PRC_DCS {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA구분, A4
	char info_clsf[3];	// 정보구분, 01:주식
	char mkt_clsf;	// 시장구분, 1:유가증권 2:코스닥
	char isin_code[13];	// 종목코드, 표준코드
	int snr;	// 종목일련번호, 종목배치(A0)의 종목SEQ
	char brd_id[3];	// 보드ID, ※ 코드값모음 참조
	int base_prc;	// 기준가격, 단위:원
	int base_prc_ceil;	// 기준가격상한가, 단위:원
	int base_prc_flr;	// 기준가격하한가, 단위:원
} DF_KOSDAQ_BASE_PRC_DCS;


// 코스닥_종목마감
typedef struct _DF_KOSDAQ_STK_CLSG {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA구분, A6
	char info_clsf[3];	// 정보구분, 01:주식 02:ELW
	char mkt_clsf;	// 시장구분, 1:유가증권 2:코스닥
	char isin_code[13];	// 종목코드, 표준코드
	int snr;	// 종목일련번호, 종목배치(A0)의 종목SEQ
	char brd_id[3];	// 보드ID, ※ 코드값모음 참조
	int stk_cls_prc;	// 종목마감종가, 정규시간외구분코드가 1:정규장일때만 종목마감가격구분코드값이 SET 됨. 그 외에는 SPACE
	char stk_cls_prc_clsf_code;	// 종목마감가격구분코드, 1 체결가격 2 기세 3 거래무 4 시가기준가종목의 기세, 정규장이 아닌 경우 SPACE
	int ofhr_ceil;	// 종목마감시간외단일가상한가
	int ofhr_flr;	// 종목마감시간외단일가하한가
	int stk_cls_mwprc;	// 종목마감평균가중주가
	int dlv_base_prc;	// 매입인도기준가격
	int dlv_ceil;	// 매입인도상한가
	int dlv_flr;	// 매입인도하한가
} DF_KOSDAQ_STK_CLSG;


// 코스닥_장운영TS
typedef struct _DF_KOSDAQ_MKT_OPR_TS {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA구분, A7
	char info_clsf[3];	// 정보구분, 01:주식 02:ELW
	char mkt_clsf;	// 시장구분, 1:유가증권 2:코스닥
	char isin_code[13];	// 종목코드, 표준코드
	int stk_snr;	// 종목일련번호, 종목배치(A0)의 종목일련번호
	char brd_id[3];	// 보드ID, ※ 코드값모음 참조
	char brd_evt_id[4];	// 보드이벤트ID, ※ 코드값모음 참조
	char brd_evt_st[7];	// 보드이벤트시작시각
	int brd_evt_code;	// 보드이벤트적용군코드, ※ 코드값모음 참조
	char sess_id[3];	// 세션ID, ※ 코드값모음 참조
	char trsp_rsn_code[4];	// 거래정지사유코드, ※ 코드값모음 참조
} DF_KOSDAQ_MKT_OPR_TS;


// 코스닥_배분정보
typedef struct _DF_KOSDAQ_ALLC_INFO {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA구분, O6
	char info_clsf[3];	// 정보구분, 01:주식
	char mkt_clsf;	// 시장구분, 1:유가증권, 2:코스닥,
	char isin_code[13];	// 종목코드, 표준코드
	int stk_snr;	// 종목일련번호, 종목배치(A0)의 종목일련번호
	char brd_id[3];	// 보드ID, ※ 코드값모음 참조
	char allc_apl_clsf_code;	// 배분적용구분코드, 1 배분개시 2 배분해제
	int allc_proc_clsf_code;	// 배분처리구분코드, 1 매수상한,2 매수하한,3 매도상한,4 매도하한   ※ 배분처리구분코드는 배분개시에만 전송하고 해제시 ' ' 전송
	int allc_cncl_time;	// 배분해제시각, HHMMSS
} DF_KOSDAQ_ALLC_INFO;


// 코스닥_종목배치
typedef struct _DF_KOSDAQ_STK_ARNG {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA구분, A0
	char info_clsf[3];	// 정보구분, 01:주식
	char mkt_clsf;	// 시장구분, 1:유가증권 2:코스닥
	char isin_code[13];	// 종목코드, 표준코드
	int snr;	// 일련번호, 1~99999999 건수체크용
	char sh_code[10];	// 단축코드, 주식7자리(DR포함) 수익증권9자리
	char kor_abbr[41];	// 종목한글약명
	char eng_abbr[41];	// 종목영문약명
	char opr_date[9];	// 영업일자, YYYYMMDD
	char info_allc_nr[6];	// 정보분배그룹번호
	char stk_gr_id[3];	// 증권그룹ID, ST:주권 MF:증권투자회사 RT:부동산투자회사 SC:선박투자회사\nIF:사회간접자본투융자회사 DR:주식예탁증서 EW:ELW EF:ETF\nSW:신주인수권증권 SR:신주인수권증서 BC:수익증권 \nFE:해외ETF FS:외국주권\nEN:ETN 2014.11.17
	char unit_trd_ccls_flg;	// 단위매매체결여부, Y, N (정규장에서 일정시간 단위체결여부)
	char lock_clsf_code[3];	// 락구분코드, 00:해당사항없음(락이 발생안한 경우) \n01:권리락 \n02:배당락\n03:분배락 \n04:권배락 \n05:중간(분기)배당락\n(2017.11.20 변경:중간배당락->중간(분기)배당락)\n06:권리중간배당락\n07:권리분기배당락\n(2017.11.20 추가)\n99:기타  ※SW,SR,EW는 미해당(미해당의 경우 SPACE)
	char pval_chg_clsf_code[3];	// 액면가변경구분코드, 00:해당없음(액면가변경이 취해질 수 있는 종목군에 대해 변경\n없음을 의미) 01:액면분할 02:액면병합 03:주식분할 04:주식병합 99:기타\n(2012.08.27)
	char open_base_prc_stk_flg;	// 시가기준가격종목여부, Y, N ※Y인 경우:신규종목,기업분할,무상감자,장기간거래정지
	char rassm_stk_rsn_code[3];	// 재평가종목사유코드, 00:해당없음, 01:회사분할, 02:자본감소, 03:장기간정지,\n04:초과분배, 05:대규모배당 \n06: 회사분할합병, 99:기타  \n※증권그룹ID ST,FS에 해당(미해당의 경우 SPACE)\n2011.02.28 구분값 추가(04:초과분배, 05:대규모배당)\n2012.08.27 정의오류수정(02:주식병합->02:자본감소) \n2017.06.26 구분값 변경(01:기업분할 -> 01:회사분할)\n2017.06.26 구분값 추가(06:회사분할합병)
	char base_prc_chg_stk_flg;	// 기준가격변경종목여부, Y, N ※Y인 경우:모든락,액면변경,증자 등
	char rndn_cls_trgg_cond_code;	// 임의종료발동조건코드, 단일가세선에서 임의종료의 발동조건.조건부발동(2)인경우 임의종료규칙에서 정의하는 가격요건을 충족하는지 판단 후 발동을 결정함.\n##코드값##\n0:미발동  1:발동  2:조건부발동(가격요건판단)
	char mkt_alm_warn_fcst_flg;	// 시장경보경고예고여부, Y, N\n\n2015.06.15 : "시장경보위험예고여부(Y,N)"->"시장경보경고예고여부(Y,N)" 항목변경
	char mkt_alrm_clsf_code[3];	// 시장경보구분코드, 00:해당없음(시장경보가 지정될 수 있는 종목에 대해서 지정된\n바가 없음을 의미) 01:투자주의 02:투자경고 03:투자위험
	char cogv_hlth_flg;	// 지배구조우량여부, Y, N ※코스닥만 해당, ST,FS,DR,MF,EF만 해당
	char ifam_flg;	// 관리종목여부, Y, N
	char iscnt_flg;	// 불성실공시지정여부, Y, N
	char bdlt_flg;	// 우회상장여부, Y, N
	char trsp_flg;	// 거래정지여부, Y, N
	char ind_lclsf_code[4];	// 지수업종대분류코드, (유가)000:업종미분류  ※유가증권은 사용하지 않음\n(코스닥)000:업종미분류/뮤추얼펀드 008~014:일반 015:IT\n※증권그룹ID ST,MF,RT,SC,IF만 해당
	char ind_mclsf_code[4];	// 지수업종중분류코드, (유가)000:업종미분류\n(코스닥)000:업종미분류 021~040:일반 041~043:IT\n※증권그룹ID ST,MF,RT,SC,IF만 해당
	char ind_sclsf_code[4];	// 지수업종소분류코드, (유가)000:업종미분류\n(코스닥)000:업종미분류 050~112:일반 151~160:IT\n※증권그룹ID ST,MF,RT,SC,IF만 해당
	char ind_id[11];	// 업종ID, 업종(Type Of Industry)ID 2014.03.03 \n*구명칭:표준산업코드 \n6자리 표준산업코드는 국내요건만 수용할 수 있어 해외사이트의 다양한 업종코드 수용이 불가하여 10자리로 확대. 현행 표준산업코드는 그대로 1:1 매핑되어 나머지 4자리는 스페이스로 채움\n6->10 2014.03.03
	char kospi200_str_ind;	// KOSPI200섹터업종, 해당사항없음 (2018.10.22 : 항목설명변경)
	char mkt_cap_code;	// 시가총액규모코드, 유가(0:제외 1:대 2:중 3:소)\n코스닥(0:제외 1:KOSDAQ100 2:KOSDAQmid300 3:KOSDAQsmall)\n※증권그룹ID ST,MF,RT,SC,IF만 해당
	char mnft_ind_flg;	// (유가)제조업여부 (코스닥)중소기업여부, Y, N\n※제조업여부는 ST,MF,RT,SC,IF만 해당(업종코드 027)\n※중소기업여부는 ST,FS,DR,EF만 해당
	char krx100_flg;	// KRX100종목여부, Y, N
	char gvnm_idx_stk_flg;	// (유가)지배구조지수종목여부(코스닥) 소속부구분코드, (유가) Y, N\n(코스닥)소속부구분코드 ← 벤처기업여부  2011.05.02\n  1:우량기업부, 2:벤처기업부, 3:중견기업부, 4:신성장기업부,\n  A:외국기업, B:투자회사, C:SPAC, D:ETF E:관리종목,\n  F:투자주의환기종목, Z:기타   \n※ A~Z는 소속부 없음\n2012.09.14 (유가종목배치)   "지배구조지수종목여부" 1 Byte FILLER 처리\n(코스닥종목배치) "소속부구분코드" 계속 사용
	char inst_clsf_code[3];	// 투자기구구분코드, 00:해당없음 01:증권간접투자기구 02:파생상품투자기구\n03:부동산간접투자기구 04:실물간접투자기구\n05:단기금융간접투자기구 06:재간접투자기구\n07:특별간접투자기구\n※증권그룹ID MF,IF,BC가 해당(미해당의 경우 SPACE)
	char idx_stk_flg;	// (유가)KOSPI지수종목여부 (코스닥)KOSDAQ지수종목여부, Y, N\n(유가)KOSPI여부-> (유가)KOSPI지수종목여부,(코스닥)KOSDAQ지수종목여부 2018.12.10
	char kospi50_flg;	// (유가)KOSPI50여부, Y, N
	int base_prc;	// 기준가격
	char prev_cls_clsf_code;	// 전일종가구분코드, 1:실세 2:기세 3:거래무 4:시가기준가종목의 기세
	int prev_cls_prc;	// 전일종가
	double prev_cum_ccls_qty;	// 전일누적체결수량
	double prev_cum_trd_val;	// 전일누적거래대금
	int ceil_prc;	// 상한가
	int flr_prc;	// 하한가
	int sub_prc;	// 대용가격, ※ST,FS,DR,MF,RT,SC,IF,ET,FE,BC,EN 만 해당 2014.11.17
	double par_val;	// 액면가, 9(9)V9(3) 외국주권일 경우 소숫점셋째자리까지 표현가능\n코스닥의 각국의 최소화폐단위 표시는 유가기준으로 통일\n※ST,FS,RT,SC,BC만 해당
	int issue_prc;	// 발행가격, ELW, 신주인수권증서 포함
	char listd_date[9];	// 상장일자, YYYYMMDD
	double stk_listd;	// 상장주식수(상장증권수)
	char arng_trd_flg;	// 정리매매여부, Y, N
	char eps_sign;	// 주당순이익(EPS)부호, +, "-"
	int eps;	// 주당순이익(EPS), 단위:원 ※증권그룹ID ST,MF,RT,IF,FS 가 해당
	char per_sign;	// 주가수익율(PER)부호, +, "-"
	int per;	// 주가수익율(PER), 9(4)V9(2) ※증권그룹ID ST,MF,RT,IF,FS 가 해당
	char eps_cmpt_xclu_flg;	// 주당순이익산출제외여부, Y:산출제외 N:산출\n※값이 0, 관리종목, 감사의견이 적정 또는 한정 인 경우
	char bps_sign;	// "주당순자산가치 (BPS)부호", +, "-"
	int bps;	// 주당순자산가치(BPS), 단위:원 ※증권그룹ID ST,MF,RT,IF,FS 가 해당
	char pbr_sign;	// "주당순자산비율 (PBR)부호", +, "-"
	int pbr;	// 주당순자산비율(PBR), 9(4)V9(2) ※증권그룹ID ST,MF,RT,IF,FS 가 해당
	char bps_cmpt_xclu_flg;	// "주당순자산가치산출 제외여부", Y:산출제외 N:산출\n※값이 0, 관리종목, 감사의견이 적정 또는 한정인 경우
	char loss_flg;	// 결손여부, Y, N
	int dps;	// 주당배당금액, 주당배당금
	char dps_cmpt_xclu_flg;	// "주당배당금액산출제외여부", Y:산출제외 N:산출\n※값이 0, 관리종목, 감사의견이 적정 또는 한정인 경우
	int dyr;	// 배당수익율, 9(6)V9(1)
	char xist_open_date[9];	// 존립개시일자, ※증권그룹ID MF,RT,SC,IF,BC 해당.
	char xist_cls_date[9];	// 존립종료일자, ※증권그룹ID MF,RT,SC,IF,BC 해당. ST,FS,DR은 우선주만 해당
	char exc_prd_open_date[9];	// 행사기간개시일자, ※증권그룹ID SW, EW 이 해당됨
	char exc_prd_cls_date[9];	// "행사기간종료일자 (권리행사기간만료일자)", ※증권그룹ID SW, EW 이 해당됨
	double elw_wrnt_exc_prc;	// "ELW신주인수권증권  행사가격", 9(9)V9(3) ELW 또는 신주인수권증권의 행사가격
	double euity;	// 자본금, 9(18)V9(3) 해외원주일 경우 소숫점셋째자리까지 표현가능\n액면가*상장주식수, 이익소각에 대한 부분은 차감함\nMF는 입력값\n※ST,FS,MF,RT,SC,IF,BC만 해당
	char credit_ordbl_flg;	// 신용주문가능여부, Y, N
	int limt_prc_cond_clsf_code;	// 지정가호가조건구분코드, X ->9 모드변경, 1->5 길이변경\n호가의 체결 및 잔류조건, Bitwise 정의(*개발가이드 참조) \n#코드값# \n1:FAS(Fill And Store) \n2:FOK(Fill Or Kill) \n4:FAK(Fill And Kill) \n*전량조건(FOK, Fill or Kill):주문전달 즉시 전량 체결되지 않으면 모든 주문이 자동 취소되는 주문 \n*당일조건(FAS, Fill and Store):주문전달 즉시 체결가능 수량은 체결하고 미체결잔량은 당일 장중동안 주문장에 체결 대기시키되, 장종료 후의 미체결 주문은 모두 최소됨
	int mkt_prc_cond_clsf_code;	// 시장가호가조건구분코드, *상동
	int cond_prc_cond_clsf_code;	// 조건부지정가호가조건구분코드, *상동
	int fvr_lmt_ord_cond_clsf_code;	// 최유리지정가호가조건구분코드, *상동
	int pfr_lmt_ord_cond_clsf_code;	// 최우선지정가호가조건구분코드, *상동
	char cap_inc_clsf_code[3];	// 증자구분코드, 00:해당없음 01:유상증자 02:무상증자 03:유무상증자 99:기타
	char scrt_clsf_code;	// 종류주권구분코드, 0:해당없음(보통주) 1:구형우선주 2:신형우선주 9:종류주권(2012.07.23)\n※증권그룹ID ST에만 해당\n※구명칭:우선주구분코드 2014.03.03
	char pbl_scrt_flg;	// 국민주여부, Y, N ※유가증권만 해당
	int asmt_prc;	// 평가가격
	int min_ask_prc;	// 최저호가가격
	int max_ask_prc;	// 최고호가가격
	int opr_time_trd_qty_unit;	// 정규장매매수량단위, 1주단위:1 10:10주단위 100:100주단위 1000:1000주단위
	int ofhr_trd_qty_unit;	// 시간외매매수량단위, 1주단위:1 10:10주단위 100:100주단위 1000:1000주단위\n※BC,SW,SR,EW는 제외
	char ritz_code;	// 리츠종류코드, 1:일반리츠 2:CRV리츠
	char obj_scrt_code[13];	// 목적주권종목코드, ※SW,SR만 해당
	char crny_iso_code[4];	// 통화ISO코드, AUD:호주달러 EUR:유로 GBP:영국파운드 HKD:홍콩달러 등\n※코드값모음-통화ISO코드 참조
	char nt_code[4];	// 국가코드, ISO 3166 코드중 3자리 숫자 ※별도 코드표 참조\n※전체 증권그룹ID에 해당
	char mkt_crt_flg;	// 시장조성가능여부, Y, N
	char ofhr_trd_flg;	// 시간외매매가능여부, Y, N
	char preord_cls_flg;	// "장개시전시간외종가 가능여부", Y, N
	char preord_msv_trd_flg;	// "장개시전시간외대량 매매가능 여부", Y, N
	char preord_bsk_flg;	// "장개시전시간외바스켓 가능 여부", Y, N
	char fcst_ccls_flg;	// 예상체결가공개여부, Y, N
	char short_flg;	// 공매도가능여부, Y, N 가격제한이 있거나 없는 공매도의 호가가능여부
	char trkg_prf_mtp_sign;	// "추적수익율배수 부호", ※증권그룹ID EF,FE,EN 해당 2014.11.17\n※항목명변경 2014.11.17\n\n"+","-"  예) 인버스일 경우 "-"            2009.07.27
	double trkg_prf_mtp;	// 추적수익율배수, ※증권그룹ID EF,FE,EN 해당 2014.11.17\n※항목명변경 2014.11.17\n\n9(5)V9(6)  지수 또는 가격 변동 대비 ETF 가격 변동 배수\n예) 레버리지 2배일 경우 '00002000000'   2009.07.27
	char regulation_apl_flg;	// "Regulation S 적용 종목여부", Y, N                             2010.02.01
	char spc_flg;	// 기업인수목적회사여부, Y, N                             2010.03.02
	char tax_type_code;	// 과세유형코드, 0:해당없음, \n1:"증권거래세"->"비과세" 코드값명 변경   2016.02.29, \n2:배당소득세(보유기간과세), \n3:증권거래세(회사형ETF)                2011.05.02\n4:"배당소득세(해외주식투자전용ETF)" 코드값 추가   2016.02.29\n(BIG33은 FILLER임)
	double sbst_prc_rate;	// 대용가격사정비율, 99999V999999 2010.06.28 \n(BIG33은 FILLER임) \n※Exture에서는 대용가가 0이면 사정비율이 0이었으나, Exture+에서는 대용가가 0이어도 사정비율 제공 2014.03.03
	char inv_xctm_stk_flg;	// (코스닥)투자주의환기종목여부, (코스닥) Y,N 관리종목 또는 상장폐지로 악화될 우려가 있는\n      부실 위험징후 기업 여부 (2011.05.02 추가)\n(BIG33은 FILLER임)
	char dlstg_date[9];	// 상장폐지일자, YYYYMMDD ※증권그룹ID SR 만 해당, 다른 증권그룹ID는 FILLER처리  2011.06.27 추가\n(BIG33은 FILLER임)
	char short_term_oh_clsf_code;	// 단기과열종목구분코드, 0: 해당없음\n1: 지정예고\n2: 지정\n3: 지정연장(해제연기)\n2012.11.05 추가
	char etf_cpy_clsf_code;	// ETF복제방법구분코드, ETF의 기초자산 복제방법구분코드 2013.03.18 추가P:실물복제S:합성복제 A:Active (2015.11.23 구분코드추가)
	char kospi200_hi_divd_idx_flg;	// KOSPI200고배당지수여부, Y,N\n2013.11.18
	char kospi200_lo_vol_idx_flg;	// KOSPI200저변동성지수여부, Y,N\n2013.11.18
	char mtr_date[9];	// 만기일자, 2014.11.17
	char divd_type_code[3];	// 분배금형태코드, 분배금형태에 따른 구분코드 2014.11.17 \n01:미지급 \n02:지급(지표가치 반영) \n03:지급(지표가치 미반영) \n04:지급(재투자) \n05:지급(기타)
	char mtr_rdmp_prc_st_date[9];	// 만기상환가격결정시작일자, 2014.11.17
	char mtr_rdmp_prc_ed_date[9];	// 만기상환가격결정종료일자, 2014.11.17
	char etp_mcdz_clsf_code;	// ETP상품구분코드, (2015.11.23 추가)\n ETP상품구분코드\n ## 코드값 ##\n1. ETF(투자회사형)\n2. ETF(수익증권형)\n3. ETN\n4. 손실제한 ETN\n(2017.03.27:ELS형 ETN->손실제한 ETN)
	char idx_cmpt_inst_code;	// 지수산출기관코드, (2015.11.23 추가)\n*코드값모음 참조(KRX 정의)
	char idx_mkt_clsf_id[7];	// 지수시장분류ID, (2015.11.23 추가)\n *대분류(2)+중분류(2)+소분류(2)\n 값이 생략되는 분류의 자리는 '00'을 표기\n중,소분류 지정시 상위 분류의 값은 생략 할 수 없음
	char idx_snr[4];	// 지수일련번호, (2015.11.23 추가)지수일련번호
	char trkg_idx_lvrg_invs_clsf_code[3];	// 추적지수레버리지인버스구분코드, (2015.11.23 추가)\n## 코드값 ##\n P1:일반(1)\n P2:2X 레버리지(2)\n N1:1X 인버스(-1)\n N2:2X 인버스(-2)
	char ref_idx_lvrg_invs_clsf_code[3];	// 참고지수레버리지인버스구분코드, (2015.11.23 추가)\n## 코드값 ##\n P1:일반(1)\n P2:2X 레버리지(2)\n N1:1X 인버스(-1)\n N2:2X 인버스(-2)
	char idx_ast_clsf_id1[7];	// 지수자산분류ID1, (2015.11.23 추가)\n *대분류(2)+중분류(2)+소분류(2)\n 값이 생략되는 분류의 자리는 '00'을 표기\n중,소분류 지정시 상위 분류의 값은 생략 할 수 없음
	char idx_ast_clsf_id2[7];	// 지수자산분류ID2, (2015.11.23 추가)\n *대분류(2)+중분류(2)+소분류(2)\n 값이 생략되는 분류의 자리는 '00'을 표기\n중,소분류 지정시 상위 분류의 값은 생략 할 수 없음
	char lp_odrbl_flg;	// LP주문가능여부, (2015.11.23 추가) Y,N
	char kosdaq150_idx_stk_flg;	// KOSDAQ150지수종목여부, (2015.11.23 추가)\nY,N
	char lo_vol_flg;	// 저유동성여부, (2016.06.27 추가)\nY,N
	char abnm_risg_flg;	// 이상급등여부, (2017.03.27 추가) \nY,N
	char krx300_idx_flg;	// KRX300지수여부, (2018.03.26 추가)\nY,N
	double qty_ceil;	// 상한수량, (2018.09.17 추가)상한수량을 초과시 호가는 거부처리 필요.
} DF_KOSDAQ_STK_ARNG;


// 코스닥_결산일 정보
typedef struct _DF_KOSDAQ_STGD_INFO {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA구분, I5
	char info_clsf[3];	// 정보구분, 01:주식
	char mkt_clsf;	// 시장구분, 1:유가증권 2:코스닥
	char isin_code[13];	// 종목코드, 표준코드
	int snr;	// 일련번호, 1~99999999 건수체크용
	char clsg_date[5];	// 결산월일, 1~99999999 건수체크용
} DF_KOSDAQ_STGD_INFO;


// 코스닥_종목 이벤트 정보
typedef struct _DF_KOSDAQ_STK_EVT_INFO {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA구분, I6
	char info_clsf[3];	// 정보구분, 01:주식
	char mkt_clsf;	// 시장구분, 1:유가증권 2:코스닥
	char  isin_code[13];	// 종목코드, 표준코드
	int snr;	// 일련번호, 1~99999999 건수체크용
	char evt_code[3];	// 이벤트종류코드, 01:거래정지 \n02:관리종목 \n03:불성실공시법인 \n04:정리매매\n05:우회상장 \n06:대용증권효력정지 \n07:지배구조우량기업\n08:차입공매도불가 \n09:Regulation S \n10:벤쳐기업지정\n11:투자주의환기종목\n12:단기과열종목 (2012.11.05 추가)\n13:휴장 (2016.06.27추가)\n14:초저유동성종목 (2016.06.27추가)\n15:투자유의채권 (2016.11.28추가)\n16:이상급등종목 (2017.03.27추가)\n17:공매도과열종목 (2017.03.27 추가)\n18: LP선택제 (2017.06.26 추가)
	char evt_trgg_code[5];	// 이벤트발생사유코드, ※ 별첨 코드갑모음의 이벤트별사유코드 참조\n※ 이벤트종류코드 03,04,07,08,09,17 에 대해서는 '0000' SET\n※ 코드의 종류에 따라 자릿수가 다릅니다. 데이터 타입이\nX모드 이기 때문에 죄측정렬됩니다. 이점 유의하여 주십시요.\n(거래정지사유코드(3자리), 관리종목지정사유코드(4자리),\n우회상장유형코드(1자리), 대용증권효력정지사유코드(2자리),\n투자주의환기종목사유코드(4자리))
	char st_date[9];	// "개시일자,시작일자, 적용일자", YYYYMMDD
	char ed_date[9];	// 만료일자,종료일자, YYYYMMDD
} DF_KOSDAQ_STK_EVT_INFO;


// 코스닥_LP 정보
typedef struct _DF_KOSDAQ_LP_INFO {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA구분, I7
	char info_clsf[3];	// 정보구분, 01:주식
	char mkt_clsf;	// 시장구분, 1:유가증권 2:코스닥
	char isin_code[13];	// 종목코드, 표준코드
	int snr;	// 일련번호, 1~99999999 건수체크용
	char mkt_ptcp_nr[6];	// 시장참가자번호, 시장참가자를 식별/구분할 수 있는 번호\n한 시장참가자가 여러 거래소의 회원이면 거래소별로\n시장참가자번호를 달리함  예) '00001'
	char lp_open_date[9];	// LP개시일자, 유동성공급개시일자
	char lp_cls_date[9];	// LP종료일자, 유동성공급종료일자
	double min_ask_qty_mtp;	// 최소호가수량배수, LP/MM 호가시 매매수량단위의 최소배수\n예) 값이 10이고 매매수량단위가 10주(계약)이면\nLP/MM 호가는 100주(계약) 이상으로 호가해야함
	double max_ask_qty_mtp;	// 최대호가수량배수, LP/MM 호가시 매매수량단위의 최대배수
	char ask_prc_sprd_unit_code;	// 호가스프레드단위코드, R:가격비율\nY:수익률비율(채권)\nT:호가가격단위 배수\nA:절대값 (채권)\n*구명칭:제한단위구분코드 2014.03.03
	double ask_prc_sprd_val;	// 호가스프레드값, LP/MM 호가 제출할 의무가 발생하는 최우선호가스프레드\n간격 또는 비율  9(13)V9(8)
	double off_mkt_ask_sprd_mtp;	// 휴장호가스프레드배수, 파생,ELW,ETF의 기초자산이 해외시장의 지수 또는 종목인 경우 해당 시장이 휴일, 장개시전, 장종류후, 휴장 등의 사유로 추적자산의 현재 가치를 판단할 수 없을 때 시장 조성 계약별로 약정한 스프레드 보다 확대된 스프레드를 허용하기 위한 배수 \n*구명칭:휴장호가스프레드값 \n구 휴장호가스프레드값 = 휴장호가스프레드배수 * 호가스프레드값 \n(Exture에서 휴장호가스프레드값이 0인경우 Exture+에서는 호가스프레드값과 일치시킴) 2014.03.03
	int obgt_ask_sbmt_time_invl;	// 의무호가제출시간간격, 단위:초(sec) \n00초 이내에 최우선호가간격을 축소시키는 매도호가 또는 매수호가를 제출 2014.03.03
	double ask_min_ask_prc_amt;	// 매도최소호가금액, 9(18)V9(3)                           2009.07.27
	double bid_min_ask_prc_amt;	// 매수최소호가금액, 9(18)V9(3)                           2009.07.27
	double min_ask_amt;	// 최소호가금액, 9(18)V9(3) (2015.11.23 추가)\nMM(시장조성자)호가의 최소금액\n※LP최소호가수량배수와 배타적으로 사용, LP최소호가수량배수에 값이 설정된 경우 해당 필드는 무시
	double max_ask_amt;	// 최대호가금액, 9(18)V9(3) (2015.11.23 추가) \n최대호가금액
} DF_KOSDAQ_LP_INFO;


// 코스닥_대량체결
typedef struct _DF_KOSDAQ_MSV_CCLS {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA구분, C4
	char info_clsf[3];	// 정보구분, 01:주식
	char mkt_clsf;	// 시장구분, 1:유가증권 2:코스닥
	char isin_code[13];	// 종목코드, 표준코드
	int stk_snr;	// 종목일련번호, 종목배치(A0)의 종목일련번호
	int snr;	// 일련번호, 1~99999999 건수체크용
	int bopen_rel_msv_ccls_qty;	// 장개시전시간외상대대량체결수량, 단위:주
	int bopen_bsk_ccls_qty;	// 장개시전시간외바스켓체결수량, 단위:주
	int bopen_cmpt_msv_ccls_qty;	// 장개시전시간외경쟁대량체결수량, 단위:주
	int rel_msv_ccls_qty;	// 장중상대대량체결수량, 단위:주
	int bsk_ccls_qty;	// 장중바스켓체결수량, 단위:주
	int cmpt_msv_ccls_qty;	// 장중경쟁대량체결수량, 단위:주
	int ofhr_rel_msv_ccls_qty;	// 장종료후시간외상대대량체결수량, 단위:주
	int ofhr_bsk_ccls_qty;	// 장종료후시간외바스켓체결수량, 단위:주
} DF_KOSDAQ_MSV_CCLS;


// 코스닥_주식종목정보공개
typedef struct _DF_KOSDAQ_STK_INFO_DCLS {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA구분, A8
	char info_clsf[3];	// 정보구분, 01:주식
	char mkt_clsf;	// 시장구분, 1:유가증권 2:코스닥
	char isin_code[13];	// 종목코드
	int stk_snr;	// 종목일련번호, 종목배치(A0)의 종목일련번호
	char open_info_clsf_code[4];	// 공개정보구분코드, ※ 코드값모음 참조
	char brd_id[3];	// 보드ID, ※ 코드값모음 참조
	int base_prc;	// 기준가격
	int ceil_prc;	// 상한가, 가격제한폭이 없는 종목 '999999999'
	int flr_prc;	// 하한가, 가격제한폭이 없는 종목 '-99999999'
	int assm_prc;	// 평가가격
	int best_ask_prc;	// 최고호가가격
	int least_ask_prc;	// 최저호가가격
	char mkt_base_prc_flg;	// 시가기준가격여부, Y, N
	char lock_clsf_code[3];	// 락구분코드, 00:해당사항없음 01:권리락 02:배당락 03:분배락 04:권배락 05:중간(분기)배당락 06:권리중간배당락 07:권리분기배당락 99:기타
	char pval_chg_clsf_code[3];	// 액면가변경구분코드, 00:해당없음 01:액면분할 02:액면병합 03:주식분할 04:주식병합 99:기타
	double trd_qty_unit;	// 매매수량단위, 1주단위:1 10:10주단위 100:100주단위 1000:1000주단위
	double stk_lstd;	// 상장주식수
	char apnt;	// 지정여부, N:해제  Y:지정
	char bopen_ofhr_flg;	// 장개시전시간외종가가능여부, N:해당없음 Y:가능
} DF_KOSDAQ_STK_INFO_DCLS;


// 코스닥_회원제재해제공개
typedef struct _DF_KOSDAQ_MBR_SCT_CNCL_DCLS {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA구분, R3
	char info_clsf[3];	// 정보구분, 01:주식
	char mkt_clsf;	// 시장구분, 1:유가증권 2:코스닥
	char ind_code[13];	// 종목코드, **: 전종목해당
	int stk_snr;	// 종목일련번호, 종목배치(A0)의 종목일련번호
	char open_info_clsf_code[4];	// 공개정보구분코드, ※ 코드값모음 참조
	char open_time[7];	// 공개시각
	char mbr_nr[6];	// 회원번호
	int mbr_sct_rng_code;	// 회원제재범위구분코드, 회원의 거래를 허용 또는 제재하는 범위. Bitwise 정의 1: 매도(풋매수) 위탁 2: 매도(풋매수) 자기 4: 매수(풋매도) 위탁 8: 매수(풋매도) 자기
} DF_KOSDAQ_MBR_SCT_CNCL_DCLS;


// 코스닥_장운영스케줄공개
typedef struct _DF_KOSDAQ_MKT_OPR_DCLS {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA구분, M4
	char info_clsf[3];	// 정보구분, 01:주식
	char mkt_clsf;	// 시장구분, 1:유가증권 2:코스닥
	char isin_code[13];	// 종목코드, 개별종목 장운영 조치시, 조기종료(KO)시 등록
	int stk_snr;	// 종목일련번호, 종목배치(A0)의 종목일련번호
	char brd_id[3];	// 보드ID, ※ 코드값모음 참조
	char brd_evt_id[4];	// 보드이벤트ID, ※ 코드값모음 참조
	char brd_evt_st[7];	// 보드이벤트시작시각
	int brd_evt_code;	// 보드이벤트적용군코드, ※ 코드값모음 참조
	char sess_open_cls_id[3];	// 세션개시종료코드, BS: 보드개시 BE: 보드종료 SS: 세션개시 SE: 세션종료 SH: 세션정지 SR: 세션재개
	char sess_id[3];	// 세션ID, ※ 코드값모음 참조
	char pbl_stk_code[13];	// 상장사종목코드, 종목조치의 기준이 되는 종목코드 *비상장사의 종목코드도 사용될 수 있음
	char trsp_rsn_code[4];	// 거래정지사유코드, ※ 코드값모음 참조 *조기종료(KO) 는 "  "
	char trsp_trgg_code;	// 거래정지발생유형코드, 1:자기종목 2:신주인수권증권 3:신주인수권증서 4:기초자산ELW 5:발행ELW 6:상장사 7:기초자산소속시장 *조기종료(KO)는 "1"
	int apl_step;	// 적용단계, CB 및 가격제한폭 확대시 적용되는 단계(그 외의 경우는 "00")
} DF_KOSDAQ_MKT_OPR_DCLS;


// 코스닥_자사주 배치정보
typedef struct _DF_KOSDAQ_TRS_STK_ARNG_INFO {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA구분, A9
	char info_clsf[3];	// 정보구분, 01:주식
	char mkt_clsf;	// 시장구분, 1:유가증권 2:코스닥
	char isin_code[13];	// 종목코드, 표준코드
	int snr;	// 일련번호, 1~99999999 건수체크용
	char trs_stk_id[6];	// 자사주신고서ID, 0:해당없음 N:자사주직접일반 S:자사주직접스톡옵션\n1~99999:자사주신탁일련번호    ※값 좌측정렬
	char ask_bid_clsf_code;	// 매도매수구분코드, 0:신탁 1:매도 2:매수
	char trs_stk_date[9];	// 자사주신청일자, YYYYMMDD ※신고서의 경우 신청일자가 없음
	char trs_stk_st_date[9];	// 자사주신고개시일자, YYYYMMDD 신고서상의 자사주매매 개시일자
	char trs_stk_ed_date[9];	// 자사주신고종료일자, YYYYMMDD 신고서상의 자사주매매 종료일자
	char trs_stk_trd_code;	// 자사주매매방법코드, 0:해당없음 1:자사주일반 2:한은등 자사주 3:정부등 자사주\n※2,3 : 장종료후시간외대량매수만 가능, 당일거래(매매거래의\n        종류)관련 사용\n        →일반자사주는 시간외대량 매수불가(매도만 가능)\n※3 : 장종료후시간외대량매수시 상/하한가 제한없음
	int trs_stk_ptcp_nr;	// "자사주신청시장참가자 번호", 회원번호 예) '00001'
	double open_trs_stk_qty;	// "시가단일가자사주신청 수량", 신고기간중의 신청일 시가단일가 신청 수량
	double opr_time_trs_stk_qty;	// 장중자사주신청수량, 신고기간중의 신청일 접속 신청 수량
	double ofhr_msv_trs_stk_qty;	// "시간외대량자사주 신청수량", 시간외(오전, 오후)시장의 자사주 신고수량
	double trs_stk_cum_ccls_qty;	// 자사주누적체결수량, 신고기간중의 정규장, 시간외시장에서 자사주 체결수량 누적
	double trs_stk_cum_trd_val;	// 자사주누적거래대금, 신고기간중의 정규장, 시간외시장에서 자사주 거래대금 누적
} DF_KOSDAQ_TRS_STK_ARNG_INFO;


// 코스닥_자사주 매매정보
typedef struct _DF_KOSDAQ_TRS_STK_TRD_INFO {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA구분, B0
	char info_clsf[3];	// 정보구분, 01:주식
	char mkt_clsf;	// 시장구분, 1:유가증권 2:코스닥
	char isin_code[13];	// 종목코드, 표준코드
	int snr;	// 일련번호, 1~99999999 종목일련번호 2014.03.03
	int ccls_prc;	// 체결가격, 단위:원
	double ccls_qty;	// 체결수량, 단위:주
	char sess_id[3];	// 세션ID, 코드값모음 참조
	char bid_trs_stk_id[6];	// 매수자사주신고서ID, 0:해당없음 N:자사주직접일반 S:자사주직접스탁옵션\n1~99999:자사주신탁(신고서일련번호)\n※값은 왼쪽정렬  예) "N", "1"\n※자사주신탁일련번호는 종목별로 영구적으로 누적 채번됨\n  직접에 반해 신탁에 일련번호가 존재하는 이유는 동일\n  종목에 대해서 여러 신탁회사에서 자사주를 신고할 수\n  있도록 허용하기 위함임
	char ask_trs_stk_id[6];	// 매도자사주신고서ID, 매수자사주신고서ID와 동일
} DF_KOSDAQ_TRS_STK_TRD_INFO;


// 코스닥_시세RECOVERY
typedef struct _DF_KOSDAQ_MKT_PRC_RCVR {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA구분, B1:종가 B2:시세REC
	char info_clsf[3];	// 정보구분, 01:주식 02:ELW
	char mkt_clsf;	// 시장구분, 1:유가증권 2:코스닥
	char isin_code[13];	// 종목코드, 표준코드
	int stk_snr;	// 종목일련번호, 종목배치(A0)의 종목일련번호
	char flct_clsf;	// 등락구분, 0:판단불가 1:상한 2:상승 3:보합 4:하한 5:하락
	int prev_ctrs;	// 전일대비, 단위:원
	int cur_prc;	// 현재가
	int open;	// 시가, 정규장 시가
	int hi;	// 고가, 정규장 고가
	int low;	// 저가, 정규장 저가
	int ask_prc;	// 매도호가, B1시 0값 SET
	int bid_prc;	// 매수호가, B1시 0값 SET
	double cum_ccls_qty;	// 누적체결수량, 단위:주 ※시간외단일가, BUY-IN을 제외한 모든 체결수량 합산
	double cum_trd_val;	// 누적거래대금, 단위:원 ※시간외단일가, BUY-IN을 제외한 모든 거래대금 합산
	char trend_flg;	// 실세/기세 구분, 0:초기값 1:실세 2:기세 3:거래무 4:시가기준가종목의 기세
	char brd_evt_id[4];	// 보드이벤트ID, B1/B2 에서는 보드이벤트ID 사용금지(과거 상태값이 전송될 수 있음). 추후, 해당 항목 '000' 세팅 예정. 2014.03.24)
	char brd_id[3];	// 보드ID, ※ 코드값모음 참조
	char trsp_flg;	// 거래정지여부, Y, N
	double bopen_ofhr_ccls_qty;	// 장개시전시간외종가체결수량, 대량, 바스켓은 제외, 단위:주
	double bopen_ofhr_trd_val;	// 장개시전시간외종가거래대금, 대량, 바스켓은 제외, 단위:원
	double opr_time_ccls_qty;	// 정규장체결수량, 대량, 바스켓은 제외, 단위:주
	double opr_time_trd_val;	// 정규장거래대금, 대량, 바스켓은 제외, 단위:원
	double ofhr_cls_ccls_qty;	// 장종료후시간외종가체결수량, 대량, 바스켓은 제외, 단위:주
	double ofhr_cls_trd_val;	// 장종료후시간외종가거래대금, 대량, 바스켓은 제외, 단위:원
	char elw_ely_cls_flg;	// ELW조기종료여부, Y,N 조기종료ELW 外 종목은 Default 'N' SET
	int elw_ely_cls_time;	// ELW조기종료시간, HHMMSS, ELW조기종료여부가 'Y'인 경우만 설정
	int cmpt_msv_dir_clsf;	// 경쟁대량 방향구분, 0:해당없음, 1:매도, 2:매수
	double gen_bin_ccls_qty;	// 일반 Buy-in 체결수량, 단위:주
	double gen_bin_ccls_trd_val;	// 일반 Buy-in 거래대금, 단위:원
	double day_bin_ccls_qty;	// 당일 Buy-in 체결수량, 단위:주
	double day_bin_ccls_trd_val;	// 당일 Buy-in 거래대금, 단위:원
} DF_KOSDAQ_MKT_PRC_RCVR;


// 코스닥_시간외단일가_리커버리_최종
typedef struct _DF_KOSDAQ_OFH_RCVR_FINAL {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA구분, B3:시간외단일가최종 B4:시간외단일가REC
	char info_clsf[3];	// 정보구분, 01:주식
	char mkt_clsf;	// 시장구분, 1:유가증권 2:코스닥
	char isin_code[13];	// 종목코드, 표준코드
	int stk_snr;	// 종목일련번호, 종목배치(A0)의 종목일련번호
	char ofhr_cnst_clsf;	// 시간외단일가등락구분, 0:판단불가 1:상한 2:상승 3:보합 4:하한 5:하락
	int ofhr_cnst;	// 시간외단일가대비, 단위:원
	int ofhr_cnst_ceil;	// 시간외단일가상한가
	int ofhr_cnst_flr;	// 시간외단일가하한가
	int ofhr_cnst_cur;	// 시간외단일가현재가
	int ofhr_cnst_open;	// 시간외단일가시가
	int ofhr_cnst_hi;	// 시간외단일가고가
	int ofhr_cnst_lo;	// 시간외단일가저가
	int ofhr_cnst_ask;	// 시간외단일가매도호가, B3시 0값 SET
	int ofhr_cnst_bid;	// 시간외단일가매수호가, B3시 0값 SET
	double ofhr_cnst_cum_ccls_qty;	// 시간외단일가누적체결수량
	double ofhr_cnst_cum_trd_val;	// 시간외단일가누적거래대금
	double tot_cum_ccls_qty;	// 전체 총 누적체결수량
	double tot_cum_trd_val;	// 전체 총 누적거래대금
	char ofhr_mkt_clsf;	// 시간외단일가장구분, 0:초기값 1:시간외단일가개시 2:시간외단일가마감
	char trsp_flg;	// 거래정지여부, Y, N
	char trend_flg;	// 실세/기세 구분, 0:초기값 1:실세 2:기세 3:거래무 4:시가기준가종목의 기세
} DF_KOSDAQ_OFH_RCVR_FINAL;


// 코스닥_시간외단일가_리커버리
typedef struct _DF_KOSDAQ_OFH_RCVR {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA구분, B3:시간외단일가최종 B4:시간외단일가REC
	char info_clsf[3];	// 정보구분, 01:주식
	char mkt_clsf;	// 시장구분, 1:유가증권 2:코스닥
	char isin_code[13];	// 종목코드, 표준코드
	int stk_snr;	// 종목일련번호, 종목배치(A0)의 종목일련번호
	char ofhr_cnst_clsf;	// 시간외단일가등락구분, 0:판단불가 1:상한 2:상승 3:보합 4:하한 5:하락
	int ofhr_cnst;	// 시간외단일가대비, 단위:원
	int ofhr_cnst_ceil;	// 시간외단일가상한가
	int ofhr_cnst_flr;	// 시간외단일가하한가
	int ofhr_cnst_cur;	// 시간외단일가현재가
	int ofhr_cnst_open;	// 시간외단일가시가
	int ofhr_cnst_hi;	// 시간외단일가고가
	int ofhr_cnst_lo;	// 시간외단일가저가
	int ofhr_cnst_ask;	// 시간외단일가매도호가, B3시 0값 SET
	int ofhr_cnst_bid;	// 시간외단일가매수호가, B3시 0값 SET
	double ofhr_cnst_cum_ccls_qty;	// 시간외단일가누적체결수량
	double ofhr_cnst_cum_trd_val;	// 시간외단일가누적거래대금
	double tot_cum_ccls_qty;	// 전체 총 누적체결수량
	double tot_cum_trd_val;	// 전체 총 누적거래대금
	char ofhr_mkt_clsf;	// 시간외단일가장구분, 0:초기값 1:시간외단일가개시 2:시간외단일가마감
	char trsp_flg;	// 거래정지여부, Y, N
	char trend_flg;	// 실세/기세 구분, 0:초기값 1:실세 2:기세 3:거래무 4:시가기준가종목의 기세
} DF_KOSDAQ_OFH_RCVR;


// 코스닥_현재등락
typedef struct _DF_KOSDAQ_CUR_FLCT {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA구분, B5
	char info_clsf[3];	// 정보구분, 01:주식
	char mkt_clsf;	// 시장구분, 1:유가증권 2:코스닥
	int tot_stk_nr;	// 전체 종목수
	int trd_form_stk_nr;	// 거래형성 종목수
	int ceil_stk_nr;	// 상한 종목수
	int rise_stk_nr;	// 상승 종목수
	int stdstl_stk_nr;	// 보합 종목수
	int flr_stk_nr;	// 하한 종목수
	int fall_stk_nr;	// 하락 종목수
	int trend_stk_nr;	// 기세 종목수
	int trend_rise_stk_nr;	// 기세상승 종목수
	int trend_fall_stk_nr;	// 기세하락 종목수
} DF_KOSDAQ_CUR_FLCT;


// 코스닥_Buy-in_실행수량
typedef struct _DF_KOSDAQ_BIN_EXCQ {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA구분, O4
	char info_clsf[3];	// 정보구분, 01:주식
	char mkt_clsf;	// 시장구분, 1:유가증권, 2:코스닥, 8:코넥스
	char isin_code[13];	// 종목코드, 표준코드 또는 "999999999999" 개발가이드 참조
	int snr;	// 일련번호, ※ Buy-in구분코드별로 일련번호 설정
	char trsm_date[9];	// 전송일자, YYYYMMDD
	char bin_clsf_code;	// Buy-in구분코드, 1: 일반 Buy-in, 2: 당일 Buy-in
	int scrt_grp_id;	// 증권그룹ID, ST:주식, MF:증권투자회사, RT:리츠, SC:선박투자회사,\nIF:인프라투융자회사, DR:예탁증서, SW:신주인수권증권,\nSR:신주인수권증서, EW:주식워런트증권, EF:상장지수펀드,\nBC:수익증권, FE:해외ETF, FS:해외원주\nEN:ETN(2014.11.17)
	double bin_exc_qty;	// Buy-in 실행수량
} DF_KOSDAQ_BIN_EXCQ;


// 코스닥 업종별 배당수익률
typedef struct _DF_KOSDAQ_BYIND_DYR {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA구분, P2
	char info_clsf[3];	// 정보구분, 01:주식
	char mkt_clsf;	// 시장구분, 1:유가증권 2:코스닥
	char idx_ind_code[4];	// 지수업종코드, ※코드값모음 참조
	double dyr;	// 배당수익률, 99999V99
} DF_KOSDAQ_BYIND_DYR;


// 코스닥_장개시전_호가잔량
typedef struct _DF_KOSDAQ_BOPEN_ASK_RSD {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA구분, B8
	char info_clsf[3];	// 정보구분, 01:주식
	char mkt_clsf;	// 시장구분, 1:유가증권 2:코스닥
	char isin_code[13];	// 종목코드, 표준코드
	int stk_snr;	// 종목일련번호, 종목배치(A0)의 종목일련번호
	double cum_ccls_qty;	// 누적체결수량
	double tot_ask_rsd;	// 총매도호가잔량
	double tot_bid_rsd;	// 총매수호가잔량
} DF_KOSDAQ_BOPEN_ASK_RSD;


// 코스닥_호가잔량_LP호가_제외
typedef struct _DF_KOSDAQ_ASK_RSD_WOLP {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA구분, B6
	char info_clsf[3];	// 정보구분, 01:주식
	char mkt_clsf;	// 시장구분, 1:유가증권 2:코스닥
	char isin_code[13];	// 종목코드, 표준코드
	int stk_snr;	// 종목일련번호, 종목배치(A0)의 종목일련번호
	double cum_ccls_qty;	// 누적체결수량
	DF_STOCK_LOB_INFO lob_infos[10];	// 호가
	double ask_10_tot_rsd;	// 10단계호가매도총잔량
	double bid_10_tot_rsd;	// 10단계호가매수총잔량
	double ofhr_ask_tot_rsd;	// 장종료후시간외매도총호가잔량, 보드ID "G3"일때 값이 설정됨
	double ofhr_bid_tot_rsd;	// 장종료후시간외매수총호가잔량, 보드ID "G3"일때 값이 설정됨
	char sess_id[3];	// 세션ID, ※ 코드값모음 참조
	char brd_id[3];	// 보드ID, ※ 코드값모음 참조
	int exp_ccls_prc;	// 예상체결가격
	double exp_ccls_qty;	// 예상체결수량
	int cmpt_msv_dir_clsf;	// 경쟁대량 방향구분, 0:해당없음, 1:매도, 2:매수
} DF_KOSDAQ_ASK_RSD_WOLP;


// 코스닥_공매도
typedef struct _DF_KOSDAQ_SHORT {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA구분, I8
	char info_clsf[3];	// 정보구분, 01:주식
	char mkt_clsf;	// 시장구분, 1:유가증권 2:코스닥
	char isin_code[13];	// 종목코드, 표준코드
	int snr;	// 일련번호, 1~99999999 종목일련번호
	double short_brwg_ask_ccls_qty;	// "공매도차입증권매도 체결수량", 단위:주
	double short_brwg_ask_trd_val;	// "공매도차입증권매도 거래대금", 단위:원
} DF_KOSDAQ_SHORT;


// 코스닥_시세종가
typedef struct _DF_KOSDAQ_MKT_PRC_CLS {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA구분, B1:종가 B2:시세REC
	char info_clsf[3];	// 정보구분, 01:주식 02:ELW
	char mkt_clsf;	// 시장구분, 1:유가증권 2:코스닥
	char isin_code[13];	// 종목코드, 표준코드
	int stk_snr;	// 종목일련번호, 종목배치(A0)의 종목일련번호
	char flct_clsf;	// 등락구분, 0:판단불가 1:상한 2:상승 3:보합 4:하한 5:하락
	int prev_ctrs;	// 전일대비, 단위:원
	int cur_prc;	// 현재가
	int open;	// 시가, 정규장 시가
	int hi;	// 고가, 정규장 고가
	int low;	// 저가, 정규장 저가
	int ask_prc;	// 매도호가, B1시 0값 SET
	int bid_prc;	// 매수호가, B1시 0값 SET
	double cum_ccls_qty;	// 누적체결수량, 단위:주 ※시간외단일가, BUY-IN을 제외한 모든 체결수량 합산
	double cum_trd_val;	// 누적거래대금, 단위:원 ※시간외단일가, BUY-IN을 제외한 모든 거래대금 합산
	char trend_flg;	// 실세/기세 구분, 0:초기값 1:실세 2:기세 3:거래무 4:시가기준가종목의 기세
	char brd_evt_id[4];	// 보드이벤트ID, B1/B2 에서는 보드이벤트ID 사용금지(과거 상태값이 전송될 수 있음). 추후, 해당 항목 '000' 세팅 예정. 2014.03.24)
	char brd_id[3];	// 보드ID, ※ 코드값모음 참조
	char trsp_flg;	// 거래정지여부, Y, N
	double bopen_ofhr_ccls_qty;	// 장개시전시간외종가체결수량, 대량, 바스켓은 제외, 단위:주
	double bopen_ofhr_trd_val;	// 장개시전시간외종가거래대금, 대량, 바스켓은 제외, 단위:원
	double opr_time_ccls_qty;	// 정규장체결수량, 대량, 바스켓은 제외, 단위:주
	double opr_time_trd_val;	// 정규장거래대금, 대량, 바스켓은 제외, 단위:원
	double ofhr_cls_ccls_qty;	// 장종료후시간외종가체결수량, 대량, 바스켓은 제외, 단위:주
	double ofhr_cls_trd_val;	// 장종료후시간외종가거래대금, 대량, 바스켓은 제외, 단위:원
	char elw_ely_cls_flg;	// ELW조기종료여부, Y,N 조기종료ELW 外 종목은 Default 'N' SET
	int elw_ely_cls_time;	// ELW조기종료시간, HHMMSS, ELW조기종료여부가 'Y'인 경우만 설정
	int cmpt_msv_dir_clsf;	// 경쟁대량 방향구분, 0:해당없음, 1:매도, 2:매수
	double gen_bin_ccls_qty;	// 일반 Buy-in 체결수량, 단위:주
	double gen_bin_ccls_trd_val;	// 일반 Buy-in 거래대금, 단위:원
	double day_bin_ccls_qty;	// 당일 Buy-in 체결수량, 단위:주
	double day_bin_ccls_trd_val;	// 당일 Buy-in 거래대금, 단위:원
} DF_KOSDAQ_MKT_PRC_CLS;


// 코스닥_업종별투자자별
typedef struct _DF_KOSDAQ_BYIND_BYINV {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA구분, C0
	char info_clsf[3];	// 정보구분, 01:주식
	char mkt_clsf;	// 시장구분, 1:유가증권 2:코스닥
	char cmpt_time[7];	// 산출시각, 90초 주기
	char inv_code[5];	// 투자자코드, ※코드값모음 참조\n*코드'7000'시 수량, 대금정보 항목 0으로 전송 (20181210)
	char ind_code[4];	// 업종코드, ※코드값모음 업종지수코드분류 참조\n산출업종;코스피/코스닥종합지수,코스피200지수
	double ask_ccls_qty;	// 매도체결수량, 단위:주
	double ask_trd_val;	// 매도거래대금, 단위:원
	double bid_ccls_qty;	// 매수체결수량, 단위:주
	double bid_trd_val;	// 매수거래대금, 단위:원
} DF_KOSDAQ_BYIND_BYINV;


// K-OTC 불성실공시 지정일, 만료일
typedef struct _DF_KOTC_ISCNT_DATE_INFO {
	char iscnt_apnt_date[9];	// 불성실공시 지정일, YYYYMMDD
	char iscnt_ed_date[9];	// 불성실공시 만료일, YYYYMMDD
} DF_KOTC_ISCNT_DATE_INFO;


// K-OTC 투자유의 정보
typedef struct _DF_KOTC_INV_ATN_INFO {
	char inv_atn_rsn_code[3];	// 투자유의 사유코드, ※개발가이드 참조
	char inv_atn_apnt_date[9];	// 투자유의 지정일, YYYYMMDD
} DF_KOTC_INV_ATN_INFO;


// K-OTC 종목배치
typedef struct _DF_KOTC_STK_ARNG {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA구분, A0
	char info_clsf[3];	// 정보구분, 01:주식
	char mkt_clsf;	// 시장구분, 3:K-OTC
	char isin_code[13];	// 종목코드, 표준코드
	int snr;	// 일련번호, 1~99999999 건수체크용
	char sh_code[10];	// 단축코드, 왼쪽정렬((예)주식 6→7, 나머지 SPACE 처리)
	char proc_date[9];	// 처리일자, 영업일자 (YYYYMMDD)
	char kor_stk_nm[81];	// 한글종목명, SIZE변경(40→80) 2016.02.01
	char eng_abrv[41];	// 영문약명, SIZE변경(20→40) 2016.02.01
	char eng_stk_nm[81];	// 영문종목명, SIZE변경(40→80) 2016.02.01
	char kor_stk_abrv[41];	// 종목명(한글약명), SIZE변경(20→40) 2016.02.01
	int stk_snr;	// 종목일련번호
	char stk_clsf;	// 종목구분, 0:정상 1:신규 2:추가
	char mdim_biz_flg;	// 중소중견기업여부, 4:중소기업 5:중견기업 6중소중견비해당 7:미확인
	char std_type_ind_code[8];	// 표준산업업종코드
	int trd_base_prc;	// 매매기준가, 가중평균주가, 락발생시 ‘매매기준가’ SET\n기세시는 '기세가격' SET\nSIZE변경(7→9) 2016.02.01
	int prev_cls;	// 전일종가, 단위:원, SIZE변경(7→9) 2016.02.01
	int prev_wavg_prc;	// 전일가중평균주가, 단위:원, SIZE변경(7→9) 2016.02.01
	double pbct_stk_nr;	// 발행주식수, 단위:주, SIZE변경(12→15) 2016.02.01
	int pval;	// 액면가, 단위:원, SIZE변경(7→9) 2016.02.01
	char clsg_mth[3];	// 결산월, MM
	char clsg_clsf;	// 결산구분, 0:보통주병합(1-4) 5:1우선주병합 6:2우선주병합
	double per;	// PER, 9999V99
	int eps;	// EPS, 단위:원, SIZE변경(7→9) 2016.02.01
	char trsp_flg;	// 거래정지여부, 0:정상 1:정지
	char trsp_rsn[3];	// 거래정지사유, ※코드값모음 참조
	char lock_clsf;	// 락구분, 0:정상 1:권리락 2:액면분할 3:액면병합 4:감자 5:병합\n6:배당락
	char rgst_aplc[41];	// 등록신청사, 항목명(ASIS 지정신청사), SIZE변경(30→40) 2016.02.01
	char trd_open_date[9];	// 매매개시일, YYYYMMDD
	char cncl_clsf;	// 해제구분, 항목명 변경(ASIS 취소구분)\n0:정상 1:구주병합에 의한 해제2:지정 및 등록해제\n(ASIS 0:정상 1:신구주병합에 의한 취소 2:지정취소)
	int whyr_hi_prc;	// 연중최고가, SIZE변경(7→9) 2016.02.01
	int whyr_lo_prc;	// 연중최저가, SIZE변경(7→9) 2016.02.01
	char whyr_hi_date[5];	// 연중최고일, MMDD
	char whyr_lo_date[5];	// 연중최저일, MMDD
	double yr_cum_qty;	// 연누적거래량, SIZE변경(14→17) 2016.02.01
	double yr_cum_trd_val;	// 연누적 거래 대금, 단위:원, SIZE변경(17→18) 2016.02.01
	char pbl_ofr_clsf;	// 공모구분, 0:비공모, 1:공모
	int pbl_ofr_prc;	// 공모가, 단위:원, SIZE변경(7→9) 2016.02.01
	char affl_clsf;	// 소속부 구분, 4:등록기업부,5:지정기업부\n(ASIS 0:일반기업부, 1:벤처기업부)
	char type_rgst_apnt;	// 등록/지정유형, -항목명 변경(ASIS 지정유형)\n-값 추가\n 0:일반지정 1:코스닥이관 2:유가시장이관 3:코넥스이관\n (ASIS 0:일반지정 1:코스닥이관 2:거래소이관)
	double prev_vlm;	// 전일거래량
	int ceil_prc;	// 상한가, SIZE변경(7→9) 2016.02.01
	int flr_prc;	// 하한가, SIZE변경(7→9) 2016.02.01
	char iscnt;	// 불성실공시, 0:정상 1~5:불성실공시 1회~5회
	DF_KOTC_ISCNT_DATE_INFO iscnt_dates[5];	// 불성실공시일
	char inv_atn_flg;	// 투자유의여부, 0:정상 1:투자유의
	DF_KOTC_INV_ATN_INFO inv_atn_infos[15];	// 투자유의
	char mkt_cap_scale;	// 시가총액규모, 지수제공시까지 SPACE\n(0:제외 1:대형주 2:중형주 3:소형주)
	char idx_ind_l[3];	// 지수업종(대), 지수제공시까지 SPACE
	char idx_ind_m[3];	// 지수업종(중), 지수제공시까지 SPACE
	char idx_ind_s[4];	// 지수업종(소), 지수제공시까지 SPACE
	char vtr_clsf;	// 벤처구분, 0:일반기업, 1:벤처기업
	char trend_clsf;	// 기세구분, 0:실세,1:기세,2:무거래
	char arng_trd_flg;	// 정리매매여부, 0:정상,1:정리매매
} DF_KOTC_STK_ARNG;


// K-OTC 호가
typedef struct _DF_KOTC_ASK_PRC {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA구분, A2
	char info_clsf[3];	// 정보구분, 01:주식
	char mkt_clsf;	// 시장구분, 3:K-OTC
	char isin_code[13];	// 종목코드, 표준코드
	int data_snr;	// 데이터 일련번호, 호가, 체결, 시장조치 포함한 일련번호
	char proc_clsf;	// 처리구분, 1:정상 2:정정 3:취소
	int ask_nr;	// 호가번호, 정상 처리시 호가번호
	int base_ask_nr;	// 원호가번호, 정상:0, 정정/취소시 해당원호가 번호
	int base_ask_prc;	// 원호가가격, 정상:0, 정정/취소시 원가격, SIZE변경(7→9) 2016.02.01
	char ask_bid_clsf;	// 매도/매수 구분, 1:매도 2:매수
	int prc;	// 가격, 정상:주문가격 정정:정정가격, SIZE변경(7→9) 2016.02.01
	double qty;	// 수량, 정상:주문수량 정정/취소:실정정/취소 수량
	char acpt_time[7];	// 접수시각
	double ask_tot_rsd;	// 매도총잔량
	double bid_tot_rsd;	// 매수총잔량
	int ask_prf_prc;	// 매도우선호가, SIZE변경(7→9) 2016.02.01
	double ask_prf_vol_rsd;	// 매도우선호가잔량
	int bid_prf_prc;	// 매수우선호가, SIZE변경(7→9) 2016.02.01
	double bid_prf_vol_rsd;	// 매수우선호가잔량
	double prc_band_vol_rsd;	// 가격대호가잔량, 정상:주문잔량 정정:정정잔량
	double base_prc_band_vol_rsd;	// 원가격대호가잔량, 정상:0, 정정/취소시 원잔량
	char brkg_nr[4];	// 증권사번호, 거래원코드 참조
	char brch_nm[13];	// 지점명, SPACE
} DF_KOTC_ASK_PRC;


// K-OTC 체결
typedef struct _DF_KOTC_CCLS {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA구분, A3
	char info_clsf[3];	// 정보구분, 01:주식
	char mkt_clsf;	// 시장구분, 3:K-OTC
	char isin_code[13];	// 종목코드, 표준코드
	int data_snr;	// 데이터 일련번호, 호가, 체결, 시장조치 포함한 일련번호
	int ccls_nr;	// 체결번호, 종목별 체결번호
	int ccls_prc;	// 체결가, SIZE변경(7→9) 2016.02.01
	double ccls_qty;	// 체결량
	char ccls_time[7];	// 체결시각
	int ask_prc_nr;	// 매도호가번호, 종목별 호가번호임
	int bid_prc_nr;	// 매수호가번호, 종목별 호가번호임
	int open;	// 고가, SIZE변경(7→9) 2016.02.01
	int hi;	// 저가, SIZE변경(7→9) 2016.02.01
	int wavg_prc;	// 가중평균주가, SIZE변경(7→9) 2016.02.01
	double tot_ccls_cum_qty;	// 전체체결누적거래량
	double tot_ccls_cum_trd_val;	// 전체체결누적거래대금
	double ask_tot_rsd;	// 매도총잔량
	double bid_tot_rsd;	// 매수총잔량
	int ask_prf_prc;	// 매도우선호가, SIZE변경(7→9) 2016.02.01
	double ask_prf_vol_rsd;	// 매도우선호가잔량
	int bid_prf_prc;	// 매수우선호가, SIZE변경(7→9) 2016.02.01
	double bid_prf_vol_rsd;	// 매수우선호가잔량
	char prev_ctrs_clsf;	// 전일대비구분, +:상승 -:하락 SPACE:보합
	int prev_ctrs;	// 전일대비, SIZE변경(7→9) 2016.02.01
	double ccls_prc_ask_rsd;	// 체결가대매도잔량
	double ccls_prc_bid_rsd;	// 체결가대매수잔량
} DF_KOTC_CCLS;


// K-OTC 종목마감
typedef struct _DF_KOTC_STK_CLSG {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA구분, A6
	char info_clsf[3];	// 정보구분, 1
	char mkt_clsf;	// 시장구분, 3:K-OTC
	char isin_code[13];	// 종목코드, 표준코드
	int data_snr;	// 데이터 일련번호, 호가,체결,장운영 포함한 일련번호
	int stk_cls_wght_prc;	// 종목마감 가중가, SIZE변경(7→9) 2016.02.01
	char trend_flg;	// 실세/기세구분, 0:가중평균가,1:기세,2:무거래
} DF_KOTC_STK_CLSG;


// K-OTC 장운영
typedef struct _DF_KOTC_MKT_OPR {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA구분, A7
	char info_clsf[3];	// 정보구분, 01:주식
	char mkt_clsf;	// 시장구분, 3:K-OTC
	char isin_code[13];	// 종목코드, 표준코드
	int data_snr;	// 데이터 일련번호, 호가, 체결, 장운용 포함한 일련번호
	char clsf;	// 구분, 1:매매거래정지 2:매매거래정지후해제
	char rsn[3];	// 사유
} DF_KOTC_MKT_OPR;


// K-OTC 시장조치
typedef struct _DF_KOTC_MKT_ACT {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA구분, G5
	char info_clsf[3];	// 정보구분, 01:주식
	char mkt_clsf;	// 시장구분, 3:K-OTC
	char isin_code[13];	// 종목코드, 표준코드
	char data_kind[3];	// 데이터 분류, 01:기준가 및 상하한가 변경 02:임시정지\n03:임시정지후 재개
	char chg_date[9];	// 변경일, YYYYMMDD(데이터분류 01이 아니면 "0")
	char chg_time[9];	// 변경시각, HHMMSSMM(데이터분류 01이 아니면 "0")
	int bact_base_prc;	// 조치전 기준가, 단위:원(데이터분류 01이 아니면 "0"), \nSIZE변경(7→9)  2016.02.01
	int bact_ceil;	// 조치전 상한가, 단위:원(데이터분류 01이 아니면 "0"), \nSIZE변경(7→9)  2016.02.01
	int bact_flr;	// 조치전 하한가, 단위:원(데이터분류 01이 아니면 "0"), \nSIZE변경(7→9)  2016.02.01
	int aact_base_prc;	// 조치후 기준가, 단위:원(데이터분류 01이 아니면 "0"), \nSIZE변경(7→9)  2016.02.01
	int aact_ceil;	// 조치후 상한가, 단위:원(데이터분류 01이 아니면 "0"), \nSIZE변경(7→9)  2016.02.01
	int aact_flr;	// 조치후 하한가, 단위:원(데이터분류 01이 아니면 "0"), \nSIZE변경(7→9)  2016.02.01
} DF_KOTC_MKT_ACT;


// K-OTC 공시 배치/실시간
typedef struct _DF_KOTC_DCLS_ARNG_RT {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA구분, E9:공시배치 F0:공시실시간
	char info_clsf[3];	// 정보구분, 01:주식
	char mkt_clsf;	// 시장구분, 3:K-OTC
	char isin_code[13];	// 종목코드, 업무마감:999999999999
	int dcls_snr;	// 공시일련번호, 000001~999999\n업무마감:999999
	char rgst_date[9];	// 등록일자, YYYYMMDD
	char proc_clsf;	// 처리구분, 1:정상 2:정정 3:취소
	char rsn[3];	// 사유, 코드값모음 참조
	int line_nr;	// 라인번호, 00:제목 01~20:내용 99:END
	char dcls_title[76];	// 공시제목/내용
} DF_KOTC_DCLS_ARNG_RT;


// KOSDAQ지수
typedef struct _DF_KOSDAQ_IDX {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA구분, ※개발가이드 참조
	char info_clsf[3];	// 정보구분, 01:주식
	char mkt_clsf;	// 시장구분, 1:유가증권 2:코스닥
	char ind_code[4];	// 업종코드, ※개발가이드 참조
	char time[7];	// 시간, ※개발가이드 참조
	int idx;	// 지수, 9(6)V9(2)
	char sign;	// 부호, +:상승 "-":하락 " ":보합
	double ctrs;	// 대비, 999999V99
	int ccls_qty;	// 체결수량, 단위:천주
	int trd_val;	// 거래대금, 단위:백만원
} DF_KOSDAQ_IDX;


// KOSDAQ예상지수
typedef struct _DF_KOSDAQ_EXP_IDX {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA구분, ※개발가이드 참조
	char info_clsf[3];	// 정보구분, 01:주식
	char mkt_clsf;	// 시장구분, 1:유가증권 2:코스닥
	char ind_code[4];	// 업종코드, ※개발가이드 참조
	char time[7];	// 시간, ※개발가이드 참조
	int idx;	// 지수, 9(6)V9(2)
	char sign;	// 부호, +:상승 "-":하락 " ":보합
	double ctrs;	// 대비, 999999V99
	int ccls_qty;	// 체결수량, 단위:천주
	int trd_val;	// 거래대금, 단위:백만원
} DF_KOSDAQ_EXP_IDX;


// 코스닥_거래원
typedef struct _DF_KOSDAQ_TRS {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA구분, B9
	char info_clsf[3];	// 정보구분, 01:주식 02:ELW
	char mkt_clsf;	// 시장구분, 1:유가증권 2:코스닥
	char isin_code[13];	// 종목코드, 표준코드
	int snr;	// 일련번호, 1~99999999 종목일련번호 2014.03.03
	DF_STOCK_SRC_INFO src_infos[5];	// 거래원정보 OCCURS
} DF_KOSDAQ_TRS;


// 코스닥_종목별투자자별 종가
typedef struct _DF_KOSDAQ_BYSTK_BYINV_CLS {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA구분, C1
	char info_clsf[3];	// 정보구분, 01:주식 02:ELW
	char mkt_clsf;	// 시장구분, 1:유가증권 2:코스닥
	char isin_code[13];	// 종목코드, 표준코드
	int snr;	// 일련번호, 1~99999999 종목일련번호 2014.03.03
	DF_STOCK_INV_INFO inv_infos[12];	// 투자자 OCCURS 12
} DF_KOSDAQ_BYSTK_BYINV_CLS;


// 코스닥_프로그램매매 호가
typedef struct _DF_KOSDAQ_PRGTRD_ASK {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA구분, C3
	char info_clsf[3];	// 정보구분, 01:주식
	char mkt_clsf;	// 시장구분, 1:유가증권 2:코스닥
	char isin_code[13];	// 종목코드
	int snr;	// 일련번호, 1~99999999 종목일련번호 2014.03.03
	// 프로그램매매호가잔량, =============================================
	double idx_abtg_ask_rsd;	// 지수차익매도호가잔량
	double idx_abtg_bid_rsd;	// 지수차익매수호가잔량
	double idx_nabtg_ask_rsd;	// 지수비차익매도호가잔량
	double idx_nabtg_bid_rsd;	// 지수비차익매수호가잔량
	// 프로그램매매호가수량, =============================================
	double idx_abtg_ask_qty;	// 지수차익매도호가수량
	double idx_abtg_bid_qty;	// 지수차익매수호가수량
	double idx_nabtg_ask_qty;	// 지수비차익매도호가수량
	double idx_nabtg_bid_qty;	// 지수비차익매수호가수량
	// 프로그램매매 사전공시용잔량
	double prior_idx_abtg_ask_rsd;	// 지수차익매도호가잔량
	double prior_idx_abtg_bid_rsd;	// 지수차익매수호가잔량
	double prior_idx_nabtg_ask_rsd;	// 지수비차익매도호가잔량
	double prior_idx_nabtg_bid_rsd;	// 지수비차익매수호가잔량
	// 프로그램매매체결내용, =============================================
	double idx_abtg_ask_ccls_qty;	// "지수차익매도위탁 체결수량"
	double idx_abtg_ask_self_ccls_qty;	// "지수차익매도자기 체결수량"
	double idx_abtg_bid_ccls_qty;	// "지수차익매수위탁 체결수량"
	double idx_abtg_bid_self_ccls_qty;	// "지수차익매수자기 체결수량"
	double idx_nabtg_ask_ccls_qty;	// "지수비차익매도위탁 체결수량"
	double idx_nabtg_ask_self_ccls_qty;	// "지수비차익매도자기 체결수량"
	double idx_nabtg_bid_ccls_qty;	// "지수비차익매수위탁 체결수량"
	double idx_nabtg_bid_self_ccls_qty;	// "지수비차익매수자기 체결수량"
	double idx_abtg_ask_ccls_val;	// "지수차익매도위탁 체결금액"
	double idx_abtg_ask_self_ccls_val;	// "지수차익매도자기 체결금액"
	double idx_abtg_bid_ccls_val;	// "지수차익매수위탁 체결금액"
	double idx_abtg_bid_self_ccls_val;	// "지수차익매수자기 체결금액"
	double idx_nabtg_ask_ccls_val;	// "지수비차익매도위탁 체결금액"
	double idx_nabtg_ask_self_ccls_val;	// "지수비차익매도자기 체결금액"
	double idx_nabtg_bid_ccls_val;	// "지수비차익매수위탁 체결금액"
	double idx_nabtg_bid_self_ccls_val;	// "지수비차익매수자기 체결금액"
	// 프로그램매매 사후공시용잔량", =============================================
	double post_idx_abtg_ask_rsd;	// 지수차익매도호가잔량, 2011.05.30 신규
	double post_idx_abtg_bid_rsd;	// 지수차익매수호가잔량, 2011.05.30 신규
	double post_idx_nabtg_ask_rsd;	// 지수비차익매도호가잔량, 2011.05.30 신규
	double post_idx_nabtg_bid_rsd;	// 지수비차익매수호가잔량, 2011.05.30 신규
} DF_KOSDAQ_PRGTRD_ASK;


// 코스닥_프로그램매매 전체집계
typedef struct _DF_KOSDAQ_PRGTRD_TOT {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA구분, J0
	char info_clsf[3];	// 정보구분, 01:주식
	char mkt_clsf;	// 시장구분, 1:유가증권 2:코스닥
	// 프로그램매매호가잔량
	double idx_abtg_ask_rsd;	// 지수차익매도호가잔량
	double idx_abtg_bid_rsd;	// 지수차익매수호가잔량
	double idx_nabtg_ask_rsd;	// 지수비차익매도호가잔량
	double idx_nabtg_bid_rsd;	// 지수비차익매수호가잔량
	// 프로그램매매호가수량
	double idx_abtg_ask_qty;	// 지수차익매도호가수량
	double idx_abtg_bid_qty;	// 지수차익매수호가수량
	double idx_nabtg_ask_qty;	// 지수비차익매도호가수량
	double idx_nabtg_bid_qty;	// 지수비차익매수호가수량
	// 프로그램매매 사전공시용잔량
	double prior_idx_abtg_ask_rsd;	// 지수차익매도호가잔량
	double prior_idx_abtg_bid_rsd;	// 지수차익매수호가잔량
	double prior_idx_nabtg_ask_rsd;	// 지수비차익매도호가잔량
	double prior_idx_nabtg_bid_rsd;	// 지수비차익매수호가잔량
	// 프로그램매매체결내용
	double idx_abtg_ask_ccls_qty;	// "지수차익매도위탁 체결수량"
	double idx_abtg_ask_self_ccls_qty;	// "지수차익매도자기 체결수량"
	double idx_abtg_bid_ccls_qty;	// "지수차익매수위탁 체결수량"
	double idx_abtg_bid_self_ccls_qty;	// "지수차익매수자기 체결수량"
	double idx_nabtg_ask_ccls_qty;	// "지수비차익매도위탁 체결수량"
	double idx_nabtg_ask_self_ccls_qty;	// "지수비차익매도자기 체결수량"
	double idx_nabtg_bid_ccls_qty;	// "지수비차익매수위탁 체결수량"
	double idx_nabtg_bid_self_ccls_qty;	// "지수비차익매수자기 체결수량"
	double idx_abtg_ask_ccls_val;	// "지수차익매도위탁 체결금액"
	double idx_abtg_ask_self_ccls_val;	// "지수차익매도자기 체결금액"
	double idx_abtg_bid_ccls_val;	// "지수차익매수위탁 체결금액"
	double idx_abtg_bid_self_ccls_val;	// "지수차익매수자기 체결금액"
	double idx_nabtg_ask_ccls_val;	// "지수비차익매도위탁 체결금액"
	double idx_nabtg_ask_self_ccls_val;	// "지수비차익매도자기 체결금액"
	double idx_nabtg_bid_ccls_val;	// "지수비차익매수위탁 체결금액"
	double idx_nabtg_bid_self_ccls_val;	// "지수비차익매수자기 체결금액"
	// 프로그램매매 사후공시용잔량
	double post_idx_abtg_ask_rsd;	// 지수차익매도호가잔량
	double post_idx_abtg_bid_rsd;	// 지수차익매수호가잔량
	double post_idx_nabtg_ask_rsd;	// 지수비차익매도호가잔량
	double post_idx_nabtg_bid_rsd;	// 지수비차익매수호가잔량
} DF_KOSDAQ_PRGTRD_TOT;


// 코스닥_프로그램매매 사전사후공시
typedef struct _DF_KOSDAQ_PRGTRD_DCLS {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA구분, C5
	char info_clsf[3];	// 정보구분, 01:주식
	char mkt_clsf;	// 시장구분, 1:유가증권 2:코스닥
	char isin_code[13];	// 종목코드
	int snr;	// 일련번호, 1~99999999 종목일련번호 2014.03.03
	double prior_dcls_new_ask_qty;	// "사전공시신규호가 매도수량", 단위 : 주\n항목명변경:매도공시사전수량->사전공시신규호가매도수량
	double prior_dcls_new_bid_qty;	// "사전공시신규호가 매수수량", 단위 : 주\n항목명변경:매수공시사전수량->사전공시신규호가매수수량
	double prior_dcls_sbmt_ask_qty;	// "사전공시기제출호가 매도수량", 단위 : 주\n항목명변경:매도공시사전정정수량->사전공시기제출호가매도수량
	double prior_dcls_sbmt_bid_qty;	// "사전공시기제출호가 매수수량", 단위 : 주\n항목명변경:매수공시사전정정수량->사전공시기제출호가매수수량
	double post_dcls_ask_qty;	// 사후공시매도수량, 단위 : 주,  신규                2011.05.03
	double post_dcls_bid_qty;	// 사후공시매수수량, 단위 : 주,  신규                2011.05.03
} DF_KOSDAQ_PRGTRD_DCLS;


// 코스닥 프로그램매매 투자자별 매매현황
typedef struct _DF_KOSDAQ_PRGTRD_BYINV_STAT {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA구분, P0
	char info_clsf[3];	// 정보구분, 01:주식
	char mkt_clsf;	// 시장구분, 1:유가증권 2:코스닥
	char cmpt_time[7];	// 산출시각, 90초 주기
	char inv_clsf_code[5];	// 투자자구분코드, ※코드값모음 참조\n*코드'7000'시 수량, 대금정보 항목 0으로 전송 (20181210)
	double ask_abtg_ccls_qty;	// 매도차익체결수량
	double ask_abtg_trd_val;	// 매도차익거래대금
	double ask_nabtg_ccls_qty;	// 매도비차익체결수량
	double ask_nabtg_trd_val;	// 매도비차익거래대금
	double bid_abtg_ccls_qty;	// 매수차익체결수량
	double bid_abtg_trd_val;	// 매수차익거래대금
	double bid_nabtg_ccls_qty;	// 매수비차익체결수량
	double bid_nabtg_trd_val;	// 매수비차익거래대금
} DF_KOSDAQ_PRGTRD_BYINV_STAT;


// 코스닥_종목상태정보(VI)
typedef struct _DF_KOSDAQ_STK_STAT_INFO {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA구분, R8
	char info_clsf[3];	// 정보구분, 01:주식
	char mkt_clsf;	// 시장구분, 1:유가증권 2:코스닥
	char isin_code[13];	// 종목코드
	int stk_snr;	// 종목일련번호, 종목배치(A0)의 종목일련번호
	char brd_id[3];	// 보드ID, ※ 코드값모음 참조
	int trd_ccls_proc_time;	// 매매체결처리시각, 매매체결처리시각
	int vi_cncl_time;	// VI해제시각
	char vi_aply_clsf_code;	// VI적용구분코드, 1:VI-발동, 2:VI-해제
	int vi_type_code;	// VI종류코드, 1:정적VI, 2:동적VI, 3:정적&동적VI
	int stt_vi_base_prc;	// 정적VI발동기준가격
	int dyn_vi_base_prc;	// 동적VI발동기준가격
	int vi_prc;	// VI발동가격
	char stt_vi_dspr[14];	// 정적VI발동괴리율, 정적VI발동 괴리율\n부호자리(양수:0, 음수:-) + 99999.999999(유효숫자 12자리)
	char dyn_vi_dspr[14];	// 동적VI발동괴리율, 동적VI발동 괴리율\n부호자리(양수:0, 음수:-) + 99999.999999(유효숫자 12자리)
} DF_KOSDAQ_STK_STAT_INFO;
