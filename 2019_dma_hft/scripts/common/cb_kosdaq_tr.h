// cb_kosdaq_tr.h
// 코스닥주식 실시간 TR

#pragma once
// 주석에 \n이 들어간건 나중에 이쁘게 바꿔야함

#include "cb_stock_common_tr.h"


// 코스닥 TR예상지수
typedef struct _KOSDAQ_TR_EXP_IDX {
	char data_clsf[2];	// DATA구분, ※개발가이드 참조
	char info_clsf[2];	// 정보구분, 01:주식
	char mkt_clsf[1];	// 시장구분, 1:유가증권 2:코스닥 9:해외주가지수 2012.04.30 추가
	char ind_clsf[3];	// 업종코드, ※개발가이드 참조
	char time[6];	// 시간, ※개발가이드 참조   ※해외주가지수일 경우 GMT시간
	char idx[8];	// 지수, 9(6)V9(2)
	char sign[1];	// 부호, +:상승 "-":하락 " ":보합
	char crst[8];	// 대비, 999999V99
	char ccls_qty[8];	// 체결수량, 단위:천주  ※해외주가지수일 경우 FILLER처리
	char trd_val[8];	// 거래대금, 단위:백만원  ※해외주가지수일 경우 FILLER처리
	char filler[2];	// FILLER, SPACE
	char ff[1];	// FF, END OF TEXT (0xFF)
} KOSDAQ_TR_EXP_IDX;


// 코스닥 TR지수
typedef struct _KOSDAQ_TR_IDX {
	char data_clsf[2];	// DATA구분, ※개발가이드 참조
	char info_clsf[2];	// 정보구분, 01:주식
	char mkt_clsf[1];	// 시장구분, 1:유가증권 2:코스닥 9:해외주가지수 2012.04.30 추가
	char ind_clsf[3];	// 업종코드, ※개발가이드 참조
	char time[6];	// 시간, ※개발가이드 참조   ※해외주가지수일 경우 GMT시간
	char idx[8];	// 지수, 9(6)V9(2)
	char sign[1];	// 부호, +:상승 "-":하락 " ":보합
	char crst[8];	// 대비, 999999V99
	char ccls_qty[8];	// 체결수량, 단위:천주  ※해외주가지수일 경우 FILLER처리
	char trd_val[8];	// 거래대금, 단위:백만원  ※해외주가지수일 경우 FILLER처리
	char filler[2];	// FILLER, SPACE
	char ff[1];	// FF, END OF TEXT (0xFF)
} KOSDAQ_TR_IDX;


// 코스닥_체결
typedef struct _KOSDAQ_CCLS {
	char data_clsf[2];	// DATA구분, A3
	char info_clsf[2];	// 정보구분, 01:주식 02:ELW
	char mkt_clsf[1];	// 시장구분, 1:유가증권 2:코스닥
	char isin_code[12];	// 종목코드, 표준코드
	char stk_snr[5];	// 종목일련번호, 종목배치(A0)의 종목SEQ
	char brd_id[2];	// 보드ID, ※ 코드값모음 참조
	char ctrs_clsf[1];	// 전일대비(기준가대비) 구분, 0:판단불가 1:상한 2:상승 3:보합 4:하한 5:하락 ※ 정규시간외구분코드 값이 4인 경우 당일 종가 대비 ※ 정규시간외구분코드 값이 7,8인 경우 Buy-in기준가 대비
	char prev_ctrs[9];	// 전일대비, 단위:원 신주인수권 증서/증권의 신규 상장 당일 : 0
	char ccls_prc[9];	// 체결가격, 단위:원
	char ccls_qty[10];	// 체결수량, 단위:주
	char sess_id[2];	// 세션ID, ※ 코드값모음 참조
	char open[9];	// 시가, 단위:원 ※개발가이드 참조
	char hi[9];	// 고가, 단위:원 ※개발가이드 참조
	char low[9];	// 저가, 단위:원 ※개발가이드 참조
	char cum_ccls_qty[12];	// 누적체결수량, 단위:주 ※보드ID별로 누적됨
	char cum_trd_val[18];	// 누적거래대금, 단위:주 ※보드ID별로 누적됨
	char fin_bid_ask_clsf_code[1];	// 최종매도매수구분코드, 1:매도 2:매수
	char mtc_flg[1];	// 체결가와1호가일치여부, 0:판단불가 1:일치 2:불일치
	char ccls_time[6];	// 체결시각, HHMMSS
	char lp_hld_qty[15];	// LP보유수량, LP(체결기준) 집계후 LP보유수량
	char ask_1_prc[9];	// 매도1호가, 단위:원 ※개발가이드 참조
	char bid_1_prc[9];	// 매수1호가, 단위:원 ※개발가이드 참조
	char filler[6];	// FILLER, SPACE
	char ff[1];	// FF, END OF TEXT (0xFF)
} KOSDAQ_CCLS;


// 코스닥_기준가결정
typedef struct _KOSDAQ_BASE_PRC_DCS {
	char data_clsf[2];	// DATA구분, A4
	char info_clsf[2];	// 정보구분, 01:주식
	char mkt_clsf[1];	// 시장구분, 1:유가증권 2:코스닥
	char isin_code[12];	// 종목코드, 표준코드
	char snr[5];	// 종목일련번호, 종목배치(A0)의 종목SEQ
	char brd_id[2];	// 보드ID, ※ 코드값모음 참조
	char base_prc[9];	// 기준가격, 단위:원
	char base_prc_ceil[9];	// 기준가격상한가, 단위:원
	char base_prc_flr[9];	// 기준가격하한가, 단위:원
	char filler[8];	// FILLER, SPACE
	char ff[1];	// FF, END OF TEXT (0xFF)
} KOSDAQ_BASE_PRC_DCS;


// 코스닥_종목마감
typedef struct _KOSDAQ_STK_CLSG {
	char data_clsf[2];	// DATA구분, A6
	char info_clsf[2];	// 정보구분, 01:주식 02:ELW
	char mkt_clsf[1];	// 시장구분, 1:유가증권 2:코스닥
	char isin_code[12];	// 종목코드, 표준코드
	char snr[5];	// 종목일련번호, 종목배치(A0)의 종목SEQ
	char brd_id[2];	// 보드ID, ※ 코드값모음 참조
	char stk_cls_prc[9];	// 종목마감종가, 정규시간외구분코드가 1:정규장일때만 종목마감가격구분코드값이 SET 됨. 그 외에는 SPACE
	char stk_cls_prc_clsf_code[1];	// 종목마감가격구분코드, 1 체결가격 2 기세 3 거래무 4 시가기준가종목의 기세, 정규장이 아닌 경우 SPACE
	char ofhr_ceil[9];	// 종목마감시간외단일가상한가
	char ofhr_flr[9];	// 종목마감시간외단일가하한가
	char stk_cls_mwprc[9];	// 종목마감평균가중주가
	char dlv_base_prc[9];	// 매입인도기준가격
	char dlv_ceil[9];	// 매입인도상한가
	char dlv_flr[9];	// 매입인도하한가
	char filler[1];	// FILLER, SPACE
	char ff[1];	// FF, END OF TEXT (0xFF)
} KOSDAQ_STK_CLSG;


// 코스닥_장운영TS
typedef struct _KOSDAQ_MKT_OPR_TS {
	char data_clsf[2];	// DATA구분, A7
	char info_clsf[2];	// 정보구분, 01:주식 02:ELW
	char mkt_clsf[1];	// 시장구분, 1:유가증권 2:코스닥
	char isin_code[12];	// 종목코드, 표준코드
	char stk_snr[5];	// 종목일련번호, 종목배치(A0)의 종목일련번호
	char brd_id[2];	// 보드ID, ※ 코드값모음 참조
	char brd_evt_id[3];	// 보드이벤트ID, ※ 코드값모음 참조
	char brd_evt_st[6];	// 보드이벤트시작시각
	char brd_evt_code[5];	// 보드이벤트적용군코드, ※ 코드값모음 참조
	char sess_id[2];	// 세션ID, ※ 코드값모음 참조
	char trsp_rsn_code[3];	// 거래정지사유코드, ※ 코드값모음 참조
	char filler[6];	// FILLER, SPACE
	char ff[1];	// FF, END OF TEXT (0xFF)
} KOSDAQ_MKT_OPR_TS;


// 코스닥_배분정보
typedef struct _KOSDAQ_ALLC_INFO {
	char data_clsf[2];	// DATA구분, O6
	char info_clsf[2];	// 정보구분, 01:주식
	char mkt_clsf[1];	// 시장구분, 1:유가증권, 2:코스닥,
	char isin_code[12];	// 종목코드, 표준코드
	char stk_snr[5];	// 종목일련번호, 종목배치(A0)의 종목일련번호
	char brd_id[2];	// 보드ID, ※ 코드값모음 참조
	char allc_apl_clsf_code[1];	// 배분적용구분코드, 1 배분개시 2 배분해제
	char allc_proc_clsf_code[1];	// 배분처리구분코드, 1 매수상한,2 매수하한,3 매도상한,4 매도하한   ※ 배분처리구분코드는 배분개시에만 전송하고 해제시 ' ' 전송
	char allc_cncl_time[6];	// 배분해제시각, HHMMSS
	char filler[7];	// FILLER, SPACE
	char ff[1];	// FF, END OF TEXT (0xFF)
} KOSDAQ_ALLC_INFO;


// 코스닥_종목배치
typedef struct _KOSDAQ_STK_ARNG {
	char data_clsf[2];	// DATA구분, A0
	char info_clsf[2];	// 정보구분, 01:주식
	char mkt_clsf[1];	// 시장구분, 1:유가증권 2:코스닥
	char isin_code[12];	// 종목코드, 표준코드
	char snr[8];	// 일련번호, 1~99999999 건수체크용
	char sh_code[9];	// 단축코드, 주식7자리(DR포함) 수익증권9자리
	char kor_abbr[40];	// 종목한글약명
	char eng_abbr[40];	// 종목영문약명
	char opr_date[8];	// 영업일자, YYYYMMDD
	char info_allc_nr[5];	// 정보분배그룹번호
	char stk_gr_id[2];	// 증권그룹ID, ST:주권 MF:증권투자회사 RT:부동산투자회사 SC:선박투자회사\nIF:사회간접자본투융자회사 DR:주식예탁증서 EW:ELW EF:ETF\nSW:신주인수권증권 SR:신주인수권증서 BC:수익증권 \nFE:해외ETF FS:외국주권\nEN:ETN 2014.11.17
	char unit_trd_ccls_flg[1];	// 단위매매체결여부, Y, N (정규장에서 일정시간 단위체결여부)
	char lock_clsf_code[2];	// 락구분코드, 00:해당사항없음(락이 발생안한 경우) \n01:권리락 \n02:배당락\n03:분배락 \n04:권배락 \n05:중간(분기)배당락\n(2017.11.20 변경:중간배당락->중간(분기)배당락)\n06:권리중간배당락\n07:권리분기배당락\n(2017.11.20 추가)\n99:기타  ※SW,SR,EW는 미해당(미해당의 경우 SPACE)
	char pval_chg_clsf_code[2];	// 액면가변경구분코드, 00:해당없음(액면가변경이 취해질 수 있는 종목군에 대해 변경\n없음을 의미) 01:액면분할 02:액면병합 03:주식분할 04:주식병합 99:기타\n(2012.08.27)
	char open_base_prc_stk_flg[1];	// 시가기준가격종목여부, Y, N ※Y인 경우:신규종목,기업분할,무상감자,장기간거래정지
	char rassm_stk_rsn_code[2];	// 재평가종목사유코드, 00:해당없음, 01:회사분할, 02:자본감소, 03:장기간정지,\n04:초과분배, 05:대규모배당 \n06: 회사분할합병, 99:기타  \n※증권그룹ID ST,FS에 해당(미해당의 경우 SPACE)\n2011.02.28 구분값 추가(04:초과분배, 05:대규모배당)\n2012.08.27 정의오류수정(02:주식병합->02:자본감소) \n2017.06.26 구분값 변경(01:기업분할 -> 01:회사분할)\n2017.06.26 구분값 추가(06:회사분할합병)
	char base_prc_chg_stk_flg[1];	// 기준가격변경종목여부, Y, N ※Y인 경우:모든락,액면변경,증자 등
	char rndn_cls_trgg_cond_code[1];	// 임의종료발동조건코드, 단일가세선에서 임의종료의 발동조건.조건부발동(2)인경우 임의종료규칙에서 정의하는 가격요건을 충족하는지 판단 후 발동을 결정함.\n##코드값##\n0:미발동  1:발동  2:조건부발동(가격요건판단)
	char mkt_alm_warn_fcst_flg[1];	// 시장경보경고예고여부, Y, N\n\n2015.06.15 : "시장경보위험예고여부(Y,N)"->"시장경보경고예고여부(Y,N)" 항목변경
	char mkt_alrm_clsf_code[2];	// 시장경보구분코드, 00:해당없음(시장경보가 지정될 수 있는 종목에 대해서 지정된\n바가 없음을 의미) 01:투자주의 02:투자경고 03:투자위험
	char cogv_hlth_flg[1];	// 지배구조우량여부, Y, N ※코스닥만 해당, ST,FS,DR,MF,EF만 해당
	char ifam_flg[1];	// 관리종목여부, Y, N
	char iscnt_flg[1];	// 불성실공시지정여부, Y, N
	char bdlt_flg[1];	// 우회상장여부, Y, N
	char trsp_flg[1];	// 거래정지여부, Y, N
	char ind_lclsf_code[3];	// 지수업종대분류코드, (유가)000:업종미분류  ※유가증권은 사용하지 않음\n(코스닥)000:업종미분류/뮤추얼펀드 008~014:일반 015:IT\n※증권그룹ID ST,MF,RT,SC,IF만 해당
	char ind_mclsf_code[3];	// 지수업종중분류코드, (유가)000:업종미분류\n(코스닥)000:업종미분류 021~040:일반 041~043:IT\n※증권그룹ID ST,MF,RT,SC,IF만 해당
	char ind_sclsf_code[3];	// 지수업종소분류코드, (유가)000:업종미분류\n(코스닥)000:업종미분류 050~112:일반 151~160:IT\n※증권그룹ID ST,MF,RT,SC,IF만 해당
	char ind_id[10];	// 업종ID, 업종(Type Of Industry)ID 2014.03.03 \n*구명칭:표준산업코드 \n6자리 표준산업코드는 국내요건만 수용할 수 있어 해외사이트의 다양한 업종코드 수용이 불가하여 10자리로 확대. 현행 표준산업코드는 그대로 1:1 매핑되어 나머지 4자리는 스페이스로 채움\n6->10 2014.03.03
	char kospi200_str_ind[1];	// KOSPI200섹터업종, 해당사항없음 (2018.10.22 : 항목설명변경)
	char mkt_cap_code[1];	// 시가총액규모코드, 유가(0:제외 1:대 2:중 3:소)\n코스닥(0:제외 1:KOSDAQ100 2:KOSDAQmid300 3:KOSDAQsmall)\n※증권그룹ID ST,MF,RT,SC,IF만 해당
	char mnft_ind_flg[1];	// (유가)제조업여부 (코스닥)중소기업여부, Y, N\n※제조업여부는 ST,MF,RT,SC,IF만 해당(업종코드 027)\n※중소기업여부는 ST,FS,DR,EF만 해당
	char krx100_flg[1];	// KRX100종목여부, Y, N
	char filler1[1];	// FILLER, Y, N\n(유가)배당지수종목여부 => FILLER처리 2015.12.21\n(코스닥)KOSTAR지수종목여부 => FILLER처리 2016.05.23
	char gvnm_idx_stk_flg[1];	// (유가)지배구조지수종목여부(코스닥) 소속부구분코드, (유가) Y, N\n(코스닥)소속부구분코드 ← 벤처기업여부  2011.05.02\n  1:우량기업부, 2:벤처기업부, 3:중견기업부, 4:신성장기업부,\n  A:외국기업, B:투자회사, C:SPAC, D:ETF E:관리종목,\n  F:투자주의환기종목, Z:기타   \n※ A~Z는 소속부 없음\n2012.09.14 (유가종목배치)   "지배구조지수종목여부" 1 Byte FILLER 처리\n(코스닥종목배치) "소속부구분코드" 계속 사용
	char inst_clsf_code[2];	// 투자기구구분코드, 00:해당없음 01:증권간접투자기구 02:파생상품투자기구\n03:부동산간접투자기구 04:실물간접투자기구\n05:단기금융간접투자기구 06:재간접투자기구\n07:특별간접투자기구\n※증권그룹ID MF,IF,BC가 해당(미해당의 경우 SPACE)
	char idx_stk_flg[1];	// (유가)KOSPI지수종목여부 (코스닥)KOSDAQ지수종목여부, Y, N\n(유가)KOSPI여부-> (유가)KOSPI지수종목여부,(코스닥)KOSDAQ지수종목여부 2018.12.10
	char filler2[1];	// (유가)KOSPI100여부(코스닥)FILLER, Y, N               프리미어여부 추가   2009.11.16\n(코스닥)프리미어여부 => FILLER처리   2016.05.23
	char kospi50_flg[1];	// (유가)KOSPI50여부, Y, N
	char filler3[1];	// FILLER, Y, N\nKRX섹터지수자동차여부 => FILLER 2016.09.12
	char filler4[1];	// FILLER, Y, N\nKRX섹터지수반도체여부 => FILLER 2016.09.12
	char filler5[1];	// FILLER, Y, N\nKRX섹터지수바이오여부 => FILLER 2016.09.12
	char filler6[1];	// FILLER, Y, N\nKRX섹터지수금융여부 => FILLER 2016.09.12
	char filler7[1];	// FILLER, Y, N\nKRX섹터지수정보통신여부 => FILLER처리 2015.12.21
	char filler8[1];	// FILLER, Y, N\nKRX섹터지수에너지화학여부 => FILLER 2016.09.12
	char filler9[1];	// FILLER, Y, N\nKRX섹터지수철강여부 => FILLER 2016.09.12
	char filler10[1];	// FILLER, Y, N\nKRX섹터지수필수소비재여부 => FILLER처리 2015.12.21
	char filler11[1];	// FILLER, Y, N\nKRX섹터지수미디어통신여부 => FILLER 2016.09.12
	char filler12[1];	// FILLER, Y, N\nKRX섹터지수건설여부 => FILLER 2016.09.12
	char filler13[1];	// FILLER, Y, N\nKRX섹터지수금융서비스여부 => FILLER처리 2015.12.21
	char filler14[1];	// FILLER, Y, N\nKRX섹터지수증권여부 => FILLER 2016.09.12
	char filler15[1];	// FILLER, Y, N\nKRX섹터지수선박여부 => FILLER 2016.09.12
	char base_prc[9];	// 기준가격
	char prev_cls_clsf_code[1];	// 전일종가구분코드, 1:실세 2:기세 3:거래무 4:시가기준가종목의 기세
	char prev_cls_prc[9];	// 전일종가
	char prev_cum_ccls_qty[12];	// 전일누적체결수량
	char prev_cum_trd_val[18];	// 전일누적거래대금
	char ceil_prc[9];	// 상한가
	char flr_prc[9];	// 하한가
	char sub_prc[9];	// 대용가격, ※ST,FS,DR,MF,RT,SC,IF,ET,FE,BC,EN 만 해당 2014.11.17
	char par_val[12];	// 액면가, 9(9)V9(3) 외국주권일 경우 소숫점셋째자리까지 표현가능\n코스닥의 각국의 최소화폐단위 표시는 유가기준으로 통일\n※ST,FS,RT,SC,BC만 해당
	char issue_prc[9];	// 발행가격, ELW, 신주인수권증서 포함
	char listd_date[8];	// 상장일자, YYYYMMDD
	char stk_listd[15];	// 상장주식수(상장증권수)
	char arng_trd_flg[1];	// 정리매매여부, Y, N
	char eps_sign[1];	// 주당순이익(EPS)부호, +, "-"
	char eps[9];	// 주당순이익(EPS), 단위:원 ※증권그룹ID ST,MF,RT,IF,FS 가 해당
	char per_sign[1];	// 주가수익율(PER)부호, +, "-"
	char per[6];	// 주가수익율(PER), 9(4)V9(2) ※증권그룹ID ST,MF,RT,IF,FS 가 해당
	char eps_cmpt_xclu_flg[1];	// 주당순이익산출제외여부, Y:산출제외 N:산출\n※값이 0, 관리종목, 감사의견이 적정 또는 한정 인 경우
	char bps_sign[1];	// "주당순자산가치 (BPS)부호", +, "-"
	char bps[9];	// 주당순자산가치(BPS), 단위:원 ※증권그룹ID ST,MF,RT,IF,FS 가 해당
	char pbr_sign[1];	// "주당순자산비율 (PBR)부호", +, "-"
	char pbr[6];	// 주당순자산비율(PBR), 9(4)V9(2) ※증권그룹ID ST,MF,RT,IF,FS 가 해당
	char bps_cmpt_xclu_flg[1];	// "주당순자산가치산출 제외여부", Y:산출제외 N:산출\n※값이 0, 관리종목, 감사의견이 적정 또는 한정인 경우
	char loss_flg[1];	// 결손여부, Y, N
	char dps[8];	// 주당배당금액, 주당배당금
	char dps_cmpt_xclu_flg[1];	// "주당배당금액산출제외여부", Y:산출제외 N:산출\n※값이 0, 관리종목, 감사의견이 적정 또는 한정인 경우
	char dyr[7];	// 배당수익율, 9(6)V9(1)
	char xist_open_date[8];	// 존립개시일자, ※증권그룹ID MF,RT,SC,IF,BC 해당.
	char xist_cls_date[8];	// 존립종료일자, ※증권그룹ID MF,RT,SC,IF,BC 해당. ST,FS,DR은 우선주만 해당
	char exc_prd_open_date[8];	// 행사기간개시일자, ※증권그룹ID SW, EW 이 해당됨
	char exc_prd_cls_date[8];	// "행사기간종료일자 (권리행사기간만료일자)", ※증권그룹ID SW, EW 이 해당됨
	char elw_wrnt_exc_prc[12];	// "ELW신주인수권증권  행사가격", 9(9)V9(3) ELW 또는 신주인수권증권의 행사가격
	char euity[21];	// 자본금, 9(18)V9(3) 해외원주일 경우 소숫점셋째자리까지 표현가능\n액면가*상장주식수, 이익소각에 대한 부분은 차감함\nMF는 입력값\n※ST,FS,MF,RT,SC,IF,BC만 해당
	char credit_ordbl_flg[1];	// 신용주문가능여부, Y, N
	char limt_prc_cond_clsf_code[5];	// 지정가호가조건구분코드, X ->9 모드변경, 1->5 길이변경\n호가의 체결 및 잔류조건, Bitwise 정의(*개발가이드 참조) \n#코드값# \n1:FAS(Fill And Store) \n2:FOK(Fill Or Kill) \n4:FAK(Fill And Kill) \n*전량조건(FOK, Fill or Kill):주문전달 즉시 전량 체결되지 않으면 모든 주문이 자동 취소되는 주문 \n*당일조건(FAS, Fill and Store):주문전달 즉시 체결가능 수량은 체결하고 미체결잔량은 당일 장중동안 주문장에 체결 대기시키되, 장종료 후의 미체결 주문은 모두 최소됨
	char mkt_prc_cond_clsf_code[5];	// 시장가호가조건구분코드, *상동
	char cond_prc_cond_clsf_code[5];	// 조건부지정가호가조건구분코드, *상동
	char fvr_lmt_ord_cond_clsf_code[5];	// 최유리지정가호가조건구분코드, *상동
	char pfr_lmt_ord_cond_clsf_code[5];	// 최우선지정가호가조건구분코드, *상동
	char cap_inc_clsf_code[2];	// 증자구분코드, 00:해당없음 01:유상증자 02:무상증자 03:유무상증자 99:기타
	char scrt_clsf_code[1];	// 종류주권구분코드, 0:해당없음(보통주) 1:구형우선주 2:신형우선주 9:종류주권(2012.07.23)\n※증권그룹ID ST에만 해당\n※구명칭:우선주구분코드 2014.03.03
	char pbl_scrt_flg[1];	// 국민주여부, Y, N ※유가증권만 해당
	char asmt_prc[9];	// 평가가격
	char min_ask_prc[9];	// 최저호가가격
	char max_ask_prc[9];	// 최고호가가격
	char opr_time_trd_qty_unit[5];	// 정규장매매수량단위, 1주단위:1 10:10주단위 100:100주단위 1000:1000주단위
	char ofhr_trd_qty_unit[5];	// 시간외매매수량단위, 1주단위:1 10:10주단위 100:100주단위 1000:1000주단위\n※BC,SW,SR,EW는 제외
	char ritz_code[1];	// 리츠종류코드, 1:일반리츠 2:CRV리츠
	char obj_scrt_code[12];	// 목적주권종목코드, ※SW,SR만 해당
	char filler16[1];	// FILLER, ※증권그룹ID EF,FE,EN 해당 2014.11.17\n※항목명변경 2014.11.17\n\n1:유가증권 2:코스닥 3:섹터 4:GICS 5:동일가중지수\n8:MF(매경) 9:해외 S:S&P/KRX B:채권 C:통화 M:상품 R:부동산  \n2012.07.16 -  D:이종자산 신규추가\n2014.11.17 -  E:주식파생, W:WiseFn 신규추가\n*대상지수소속시장구분코드 -> FILLER 변경 (2015.11.23)
	char filler17[3];	// FILLER, ※증권그룹ID EF,FE,EN 해당 2014.11.17\n※항목명변경 2014.11.17\n\n※코드값모음 대상지수업종코드 참조\n※각 시장별로 지수코드를 독자적으로 가지고 있으므로 소속\n  시장구분코드와 연계하여 사용해야 함\n*대상지수업종코드 -> FILLER 변경 (2015.11.23)
	char filler18[1];	// FILLER, 0:해당없음 1:투자회사형 2:수익증권형 \n※ETF종목 이외 SPACE\n*ETF구분코드 -> FILLER 변경 (2015.11.23)
	char filler19[4];	// FILLER, 단위:종목\n*ETF구성종목수 -> FILLER 변경 (2015.11.23)
	char crny_iso_code[3];	// 통화ISO코드, AUD:호주달러 EUR:유로 GBP:영국파운드 HKD:홍콩달러 등\n※코드값모음-통화ISO코드 참조
	char nt_code[3];	// 국가코드, ISO 3166 코드중 3자리 숫자 ※별도 코드표 참조\n※전체 증권그룹ID에 해당
	char mkt_crt_flg[1];	// 시장조성가능여부, Y, N
	char ofhr_trd_flg[1];	// 시간외매매가능여부, Y, N
	char preord_cls_flg[1];	// "장개시전시간외종가 가능여부", Y, N
	char preord_msv_trd_flg[1];	// "장개시전시간외대량 매매가능 여부", Y, N
	char preord_bsk_flg[1];	// "장개시전시간외바스켓 가능 여부", Y, N
	char fcst_ccls_flg[1];	// 예상체결가공개여부, Y, N
	char short_flg[1];	// 공매도가능여부, Y, N 가격제한이 있거나 없는 공매도의 호가가능여부
	char filler20[3];	// FILLER, ETF가 추적하는 기초자산의 가격표시 단위. 지수추종 ETF는\n"PT", 가격추종 ETF는 통화ISO코드        2009.07.27\n*ETF추적기초자산단위코드 -> FILLER 변경(2015.11.23)
	char trkg_prf_mtp_sign[1];	// "추적수익율배수 부호", ※증권그룹ID EF,FE,EN 해당 2014.11.17\n※항목명변경 2014.11.17\n\n"+","-"  예) 인버스일 경우 "-"            2009.07.27
	char trkg_prf_mtp[11];	// 추적수익율배수, ※증권그룹ID EF,FE,EN 해당 2014.11.17\n※항목명변경 2014.11.17\n\n9(5)V9(6)  지수 또는 가격 변동 대비 ETF 가격 변동 배수\n예) 레버리지 2배일 경우 '00002000000'   2009.07.27
	char filler21[1];	// FILLER, ※증권그룹ID EF,FE,EN 해당 2014.11.17\n※항목명변경 2014.11.17\n\nD:국내 F:해외 C:국내+국외\n2009.07.27\n추적기초자산 국내외구분\n2012.10.10\nC:국내+국외 코드 값 추가\n*추적기초자산국내외구분코드 -> FILLER 변경(2015.11.23)
	char filler22[1];	// FILLER, Y, N                             2009.09.14\nSRI지수여부 => FILLER 2016.09.12
	char filler23[1];	// FILLER, ※증권그룹ID EF,FE,EN 해당 2014.11.17\n※항목명변경 2014.11.17\n\n1:유가증권 2:코스닥 3:섹터 4:GICS 5:동일가중지수 \n8:MF(매경) 9:해외 S:S&P/KRX B:채권 C:통화 M:상품\nR:부동산 2011.05.02\n*참고지수소속시장구분코드 -> FILLER 변경(2015.11.23)
	char filler24[3];	// FILLER, ※증권그룹ID EF,FE,EN 해당 2014.11.17\n※항목명변경 2014.11.17\n\n※구분값모음 대상지수업종코드 참조\n각 시장별로 지수코드를 독자적으로 가지고 있으므로 \n소속시장구분코드와 연계하여 사용해야 함   2009.09.14\n*참고지수업종코드 -> FILLER 변경(2015.11.23)
	char filler25[1];	// FILLER, Y, N                             2010.01.18\nKRX섹터지수보험여부 => FILLER 2016.09.12
	char filler26[1];	// FILLER, Y, N                             2010.01.18\nKRX섹터지수운송여부 => FILLER 2016.09.12
	char regulation_apl_flg[1];	// "Regulation S 적용 종목여부", Y, N                             2010.02.01
	char spc_flg[1];	// 기업인수목적회사여부, Y, N                             2010.03.02
	char tax_type_code[1];	// 과세유형코드, 0:해당없음, \n1:"증권거래세"->"비과세" 코드값명 변경   2016.02.29, \n2:배당소득세(보유기간과세), \n3:증권거래세(회사형ETF)                2011.05.02\n4:"배당소득세(해외주식투자전용ETF)" 코드값 추가   2016.02.29\n(BIG33은 FILLER임)
	char sbst_prc_rate[11];	// 대용가격사정비율, 99999V999999 2010.06.28 \n(BIG33은 FILLER임) \n※Exture에서는 대용가가 0이면 사정비율이 0이었으나, Exture+에서는 대용가가 0이어도 사정비율 제공 2014.03.03
	char filler27[1];	// FILLER, Y,N                             2010.08.30\n(BIG33은 FILLER임)\nKRX섹터지수소비자유통여부 => FILLER처리 2015.12.21
	char filler28[1];	// FILLER, Y,N                             2010.08.30\n(BIG33은 FILLER임)\nKRX섹터지수레저엔터테인먼트여부 => FILLER처리 2015.12.21
	char filler29[1];	// FILLER, Y,N                             2010.10.01\n(BIG33은 FILLER임)\n환경책임투자지수여부 => FILLER 2016.09.12
	char filler30[1];	// FILLER, Y,N                             2010.12.20\n(BIG33은 FILLER임)\n녹색산업지수여부 => FILLER처리 2015.12.21
	char inv_xctm_stk_flg[1];	// (코스닥)투자주의환기종목여부, (코스닥) Y,N 관리종목 또는 상장폐지로 악화될 우려가 있는\n      부실 위험징후 기업 여부 (2011.05.02 추가)\n(BIG33은 FILLER임)
	char dlstg_date[8];	// 상장폐지일자, YYYYMMDD ※증권그룹ID SR 만 해당, 다른 증권그룹ID는 FILLER처리  2011.06.27 추가\n(BIG33은 FILLER임)
	char filler31[1];	// FILLER, Y,N\n2012.09.14 \n지배구조책임투자지수종목여부 => FILLER 2016.09.12
	char short_term_oh_clsf_code[1];	// 단기과열종목구분코드, 0: 해당없음\n1: 지정예고\n2: 지정\n3: 지정연장(해제연기)\n2012.11.05 추가
	char etf_cpy_clsf_code[1];	// ETF복제방법구분코드, ETF의 기초자산 복제방법구분코드 2013.03.18 추가P:실물복제S:합성복제 A:Active (2015.11.23 구분코드추가)
	char filler32[1];	// FILLER, ETF상품유형에 따른 구분코드 2013.03.18 추가\n1:파생형\n2:일반형\n*ETF상품유형코드-> FILLER 변경 (2015.11.23)
	char kospi200_hi_divd_idx_flg[1];	// KOSPI200고배당지수여부, Y,N\n2013.11.18
	char kospi200_lo_vol_idx_flg[1];	// KOSPI200저변동성지수여부, Y,N\n2013.11.18
	char filler33[3];	// FILLER, 2014.11.17
	char mtr_date[8];	// 만기일자, 2014.11.17
	char filler34[3];	// FILLER, ETN상품분류에 따른 구분코드 2014.11.17 \n100:주식, 101:시장대표, \n102:업종, 103:전략, \n104:구조화, 105:테마, \n106:기타, \n200:채권, 201:국공채, \n202:회사채, 203:단기채, \n204:하이일드, 205:기타, \n300:혼합, 301:주식, \n302:채권, 303:기타, \n400:상품, 401:에너지, \n402:농축산물, 403:금속, \n404:종합, 405:기타, \n500:대체자산, 501:통화, \n502:변동성, 503:부동산, \n504:기타\n*ETN상품분류코드 -> FILLER 변경 (2015.11.23)
	char divd_type_code[2];	// 분배금형태코드, 분배금형태에 따른 구분코드 2014.11.17 \n01:미지급 \n02:지급(지표가치 반영) \n03:지급(지표가치 미반영) \n04:지급(재투자) \n05:지급(기타)
	char mtr_rdmp_prc_st_date[8];	// 만기상환가격결정시작일자, 2014.11.17
	char mtr_rdmp_prc_ed_date[8];	// 만기상환가격결정종료일자, 2014.11.17
	char etp_mcdz_clsf_code[1];	// ETP상품구분코드, (2015.11.23 추가)\n ETP상품구분코드\n ## 코드값 ##\n1. ETF(투자회사형)\n2. ETF(수익증권형)\n3. ETN\n4. 손실제한 ETN\n(2017.03.27:ELS형 ETN->손실제한 ETN)
	char idx_cmpt_inst_code[1];	// 지수산출기관코드, (2015.11.23 추가)\n*코드값모음 참조(KRX 정의)
	char idx_mkt_clsf_id[6];	// 지수시장분류ID, (2015.11.23 추가)\n *대분류(2)+중분류(2)+소분류(2)\n 값이 생략되는 분류의 자리는 '00'을 표기\n중,소분류 지정시 상위 분류의 값은 생략 할 수 없음
	char idx_snr[3];	// 지수일련번호, (2015.11.23 추가)지수일련번호
	char trkg_idx_lvrg_invs_clsf_code[2];	// 추적지수레버리지인버스구분코드, (2015.11.23 추가)\n## 코드값 ##\n P1:일반(1)\n P2:2X 레버리지(2)\n N1:1X 인버스(-1)\n N2:2X 인버스(-2)
	char ref_idx_lvrg_invs_clsf_code[2];	// 참고지수레버리지인버스구분코드, (2015.11.23 추가)\n## 코드값 ##\n P1:일반(1)\n P2:2X 레버리지(2)\n N1:1X 인버스(-1)\n N2:2X 인버스(-2)
	char idx_ast_clsf_id1[6];	// 지수자산분류ID1, (2015.11.23 추가)\n *대분류(2)+중분류(2)+소분류(2)\n 값이 생략되는 분류의 자리는 '00'을 표기\n중,소분류 지정시 상위 분류의 값은 생략 할 수 없음
	char idx_ast_clsf_id2[6];	// 지수자산분류ID2, (2015.11.23 추가)\n *대분류(2)+중분류(2)+소분류(2)\n 값이 생략되는 분류의 자리는 '00'을 표기\n중,소분류 지정시 상위 분류의 값은 생략 할 수 없음
	char lp_odrbl_flg[1];	// LP주문가능여부, (2015.11.23 추가) Y,N
	char kosdaq150_idx_stk_flg[1];	// KOSDAQ150지수종목여부, (2015.11.23 추가)\nY,N
	char lo_vol_flg[1];	// 저유동성여부, (2016.06.27 추가)\nY,N
	char abnm_risg_flg[1];	// 이상급등여부, (2017.03.27 추가) \nY,N
	char krx300_idx_flg[1];	// KRX300지수여부, (2018.03.26 추가)\nY,N
	char qty_ceil[16];	// 상한수량, (2018.09.17 추가)상한수량을 초과시 호가는 거부처리 필요.
	char filler35[132];	// FILLER, SPACE 103→95 2011.06.27 변경\nSPACE 95->94 2012.09.14 변경 \nSPACE 94->93 2012.11.05 변경\nSPACE 93->91 2013.03.18 변경 \nSPACE 91->89 2013.11.18 변경\nSPACE 89->212 2014.03.03 변경 \nSPACE 212->180 2014.11.17 변경\nSPACE 180->151 2015.11.23 변경\nSPACE 151->150 2016.06.27 변경\nSPACE 150->149 2017.03.27 변경\nSPACE 149->148 2018.03.26 변경\nSPACE 148->132 2018.09.17 변경
	char ff[1];	// FF, END OF TEXT (0xFF)  640→800     2010.03.02
} KOSDAQ_STK_ARNG;


// 코스닥_결산일 정보
typedef struct _KOSDAQ_STGD_INFO {
	char data_clsf[2];	// DATA구분, I5
	char info_clsf[2];	// 정보구분, 01:주식
	char mkt_clsf[1];	// 시장구분, 1:유가증권 2:코스닥
	char isin_code[12];	// 종목코드, 표준코드
	char snr[8];	// 일련번호, 1~99999999 건수체크용
	char clsg_date[4];	// 결산월일, 1~99999999 건수체크용
	char ff[1];	// FF, END OF TEXT (0xFF)
} KOSDAQ_STGD_INFO;


// 코스닥_종목 이벤트 정보
typedef struct _KOSDAQ_STK_EVT_INFO {
	char data_clsf[2];	// DATA구분, I6
	char info_clsf[2];	// 정보구분, 01:주식
	char mkt_clsf[1];	// 시장구분, 1:유가증권 2:코스닥
	char  isin_code[12];	// 종목코드, 표준코드
	char snr[8];	// 일련번호, 1~99999999 건수체크용
	char evt_code[2];	// 이벤트종류코드, 01:거래정지 \n02:관리종목 \n03:불성실공시법인 \n04:정리매매\n05:우회상장 \n06:대용증권효력정지 \n07:지배구조우량기업\n08:차입공매도불가 \n09:Regulation S \n10:벤쳐기업지정\n11:투자주의환기종목\n12:단기과열종목 (2012.11.05 추가)\n13:휴장 (2016.06.27추가)\n14:초저유동성종목 (2016.06.27추가)\n15:투자유의채권 (2016.11.28추가)\n16:이상급등종목 (2017.03.27추가)\n17:공매도과열종목 (2017.03.27 추가)\n18: LP선택제 (2017.06.26 추가)
	char evt_trgg_code[4];	// 이벤트발생사유코드, ※ 별첨 코드갑모음의 이벤트별사유코드 참조\n※ 이벤트종류코드 03,04,07,08,09,17 에 대해서는 '0000' SET\n※ 코드의 종류에 따라 자릿수가 다릅니다. 데이터 타입이\nX모드 이기 때문에 죄측정렬됩니다. 이점 유의하여 주십시요.\n(거래정지사유코드(3자리), 관리종목지정사유코드(4자리),\n우회상장유형코드(1자리), 대용증권효력정지사유코드(2자리),\n투자주의환기종목사유코드(4자리))
	char st_date[8];	// "개시일자,시작일자, 적용일자", YYYYMMDD
	char ed_date[8];	// 만료일자,종료일자, YYYYMMDD
	char filler[2];	// FILLER, SPACE
	char ff[1];	// FF, END OF TEXT (0xFF)
} KOSDAQ_STK_EVT_INFO;


// 코스닥_LP 정보
typedef struct _KOSDAQ_LP_INFO {
	char data_clsf[2];	// DATA구분, I7
	char info_clsf[2];	// 정보구분, 01:주식
	char mkt_clsf[1];	// 시장구분, 1:유가증권 2:코스닥
	char isin_code[12];	// 종목코드, 표준코드
	char snr[8];	// 일련번호, 1~99999999 건수체크용
	char mkt_ptcp_nr[5];	// 시장참가자번호, 시장참가자를 식별/구분할 수 있는 번호\n한 시장참가자가 여러 거래소의 회원이면 거래소별로\n시장참가자번호를 달리함  예) '00001'
	char lp_open_date[8];	// LP개시일자, 유동성공급개시일자
	char lp_cls_date[8];	// LP종료일자, 유동성공급종료일자
	char min_ask_qty_mtp[11];	// 최소호가수량배수, LP/MM 호가시 매매수량단위의 최소배수\n예) 값이 10이고 매매수량단위가 10주(계약)이면\nLP/MM 호가는 100주(계약) 이상으로 호가해야함
	char max_ask_qty_mtp[11];	// 최대호가수량배수, LP/MM 호가시 매매수량단위의 최대배수
	char ask_prc_sprd_unit_code[1];	// 호가스프레드단위코드, R:가격비율\nY:수익률비율(채권)\nT:호가가격단위 배수\nA:절대값 (채권)\n*구명칭:제한단위구분코드 2014.03.03
	char ask_prc_sprd_val[21];	// 호가스프레드값, LP/MM 호가 제출할 의무가 발생하는 최우선호가스프레드\n간격 또는 비율  9(13)V9(8)
	char off_mkt_ask_sprd_mtp[11];	// 휴장호가스프레드배수, 파생,ELW,ETF의 기초자산이 해외시장의 지수 또는 종목인 경우 해당 시장이 휴일, 장개시전, 장종류후, 휴장 등의 사유로 추적자산의 현재 가치를 판단할 수 없을 때 시장 조성 계약별로 약정한 스프레드 보다 확대된 스프레드를 허용하기 위한 배수 \n*구명칭:휴장호가스프레드값 \n구 휴장호가스프레드값 = 휴장호가스프레드배수 * 호가스프레드값 \n(Exture에서 휴장호가스프레드값이 0인경우 Exture+에서는 호가스프레드값과 일치시킴) 2014.03.03
	char obgt_ask_sbmt_time_invl[6];	// 의무호가제출시간간격, 단위:초(sec) \n00초 이내에 최우선호가간격을 축소시키는 매도호가 또는 매수호가를 제출 2014.03.03
	char ask_min_ask_prc_amt[21];	// 매도최소호가금액, 9(18)V9(3)                           2009.07.27
	char bid_min_ask_prc_amt[21];	// 매수최소호가금액, 9(18)V9(3)                           2009.07.27
	char min_ask_amt[21];	// 최소호가금액, 9(18)V9(3) (2015.11.23 추가)\nMM(시장조성자)호가의 최소금액\n※LP최소호가수량배수와 배타적으로 사용, LP최소호가수량배수에 값이 설정된 경우 해당 필드는 무시
	char max_ask_amt[21];	// 최대호가금액, 9(18)V9(3) (2015.11.23 추가) \n최대호가금액
	char filler[58];	// FILLER, SPACE 2014.03.03\n10 -> 58 2015.11.23
	char ff[1];	// FF, END OF TEXT (0xFF) 120->160 2009.07.27160->250 2015.11.23
} KOSDAQ_LP_INFO;


// 코스닥_대량체결
typedef struct _KOSDAQ_MSV_CCLS {
	char data_clsf[2];	// DATA구분, C4
	char info_clsf[2];	// 정보구분, 01:주식
	char mkt_clsf[1];	// 시장구분, 1:유가증권 2:코스닥
	char isin_code[12];	// 종목코드, 표준코드
	char stk_snr[5];	// 종목일련번호, 종목배치(A0)의 종목일련번호
	char snr[8];	// 일련번호, 1~99999999 건수체크용
	char bopen_rel_msv_ccls_qty[9];	// 장개시전시간외상대대량체결수량, 단위:주
	char bopen_bsk_ccls_qty[9];	// 장개시전시간외바스켓체결수량, 단위:주
	char bopen_cmpt_msv_ccls_qty[9];	// 장개시전시간외경쟁대량체결수량, 단위:주
	char rel_msv_ccls_qty[9];	// 장중상대대량체결수량, 단위:주
	char bsk_ccls_qty[9];	// 장중바스켓체결수량, 단위:주
	char cmpt_msv_ccls_qty[9];	// 장중경쟁대량체결수량, 단위:주
	char ofhr_rel_msv_ccls_qty[9];	// 장종료후시간외상대대량체결수량, 단위:주
	char ofhr_bsk_ccls_qty[9];	// 장종료후시간외바스켓체결수량, 단위:주
	char filler[7];	// FILLER, SPACE
	char ff[1];	// FF, END OF TEXT (0xFF)
} KOSDAQ_MSV_CCLS;


// 코스닥_주식종목정보공개
typedef struct _KOSDAQ_STK_INFO_DCLS {
	char data_clsf[2];	// DATA구분, A8
	char info_clsf[2];	// 정보구분, 01:주식
	char mkt_clsf[1];	// 시장구분, 1:유가증권 2:코스닥
	char isin_code[12];	// 종목코드
	char stk_snr[5];	// 종목일련번호, 종목배치(A0)의 종목일련번호
	char open_info_clsf_code[3];	// 공개정보구분코드, ※ 코드값모음 참조
	char brd_id[2];	// 보드ID, ※ 코드값모음 참조
	char base_prc[9];	// 기준가격
	char ceil_prc[9];	// 상한가, 가격제한폭이 없는 종목 '999999999'
	char flr_prc[9];	// 하한가, 가격제한폭이 없는 종목 '-99999999'
	char assm_prc[9];	// 평가가격
	char best_ask_prc[9];	// 최고호가가격
	char least_ask_prc[9];	// 최저호가가격
	char mkt_base_prc_flg[1];	// 시가기준가격여부, Y, N
	char lock_clsf_code[2];	// 락구분코드, 00:해당사항없음 01:권리락 02:배당락 03:분배락 04:권배락 05:중간(분기)배당락 06:권리중간배당락 07:권리분기배당락 99:기타
	char pval_chg_clsf_code[2];	// 액면가변경구분코드, 00:해당없음 01:액면분할 02:액면병합 03:주식분할 04:주식병합 99:기타
	char trd_qty_unit[11];	// 매매수량단위, 1주단위:1 10:10주단위 100:100주단위 1000:1000주단위
	char stk_lstd[16];	// 상장주식수
	char apnt[1];	// 지정여부, N:해제  Y:지정
	char bopen_ofhr_flg[1];	// 장개시전시간외종가가능여부, N:해당없음 Y:가능
	char filler[4];	// FILLER, SPACE
	char ff[1];	// FF, END OF TEXT (0xFF)
} KOSDAQ_STK_INFO_DCLS;


// 코스닥_회원제재해제공개
typedef struct _KOSDAQ_MBR_SCT_CNCL_DCLS {
	char data_clsf[2];	// DATA구분, R3
	char info_clsf[2];	// 정보구분, 01:주식
	char mkt_clsf[1];	// 시장구분, 1:유가증권 2:코스닥
	char ind_code[12];	// 종목코드, **: 전종목해당
	char stk_snr[5];	// 종목일련번호, 종목배치(A0)의 종목일련번호
	char open_info_clsf_code[3];	// 공개정보구분코드, ※ 코드값모음 참조
	char open_time[6];	// 공개시각
	char mbr_nr[5];	// 회원번호
	char mbr_sct_rng_code[5];	// 회원제재범위구분코드, 회원의 거래를 허용 또는 제재하는 범위. Bitwise 정의 1: 매도(풋매수) 위탁 2: 매도(풋매수) 자기 4: 매수(풋매도) 위탁 8: 매수(풋매도) 자기
	char filler[8];	// FILLER, SPACE
	char ff[1];	// FF, END OF TEXT (0xFF)
} KOSDAQ_MBR_SCT_CNCL_DCLS;


// 코스닥_장운영스케줄공개
typedef struct _KOSDAQ_MKT_OPR_DCLS {
	char data_clsf[2];	// DATA구분, M4
	char info_clsf[2];	// 정보구분, 01:주식
	char mkt_clsf[1];	// 시장구분, 1:유가증권 2:코스닥
	char isin_code[12];	// 종목코드, 개별종목 장운영 조치시, 조기종료(KO)시 등록
	char stk_snr[5];	// 종목일련번호, 종목배치(A0)의 종목일련번호
	char brd_id[2];	// 보드ID, ※ 코드값모음 참조
	char brd_evt_id[3];	// 보드이벤트ID, ※ 코드값모음 참조
	char brd_evt_st[6];	// 보드이벤트시작시각
	char brd_evt_code[5];	// 보드이벤트적용군코드, ※ 코드값모음 참조
	char sess_open_cls_id[2];	// 세션개시종료코드, BS: 보드개시 BE: 보드종료 SS: 세션개시 SE: 세션종료 SH: 세션정지 SR: 세션재개
	char sess_id[2];	// 세션ID, ※ 코드값모음 참조
	char pbl_stk_code[12];	// 상장사종목코드, 종목조치의 기준이 되는 종목코드 *비상장사의 종목코드도 사용될 수 있음
	char trsp_rsn_code[3];	// 거래정지사유코드, ※ 코드값모음 참조 *조기종료(KO) 는 "  "
	char trsp_trgg_code[1];	// 거래정지발생유형코드, 1:자기종목 2:신주인수권증권 3:신주인수권증서 4:기초자산ELW 5:발행ELW 6:상장사 7:기초자산소속시장 *조기종료(KO)는 "1"
	char apl_step[2];	// 적용단계, CB 및 가격제한폭 확대시 적용되는 단계(그 외의 경우는 "00")
	char filler[9];	// FILLER, SPACE
	char ff[1];	// FF, END OF TEXT (0xFF)
} KOSDAQ_MKT_OPR_DCLS;


// 코스닥_자사주 배치정보
typedef struct _KOSDAQ_TRS_STK_ARNG_INFO {
	char data_clsf[2];	// DATA구분, A9
	char info_clsf[2];	// 정보구분, 01:주식
	char mkt_clsf[1];	// 시장구분, 1:유가증권 2:코스닥
	char isin_code[12];	// 종목코드, 표준코드
	char snr[8];	// 일련번호, 1~99999999 건수체크용
	char trs_stk_id[5];	// 자사주신고서ID, 0:해당없음 N:자사주직접일반 S:자사주직접스톡옵션\n1~99999:자사주신탁일련번호    ※값 좌측정렬
	char ask_bid_clsf_code[1];	// 매도매수구분코드, 0:신탁 1:매도 2:매수
	char trs_stk_date[8];	// 자사주신청일자, YYYYMMDD ※신고서의 경우 신청일자가 없음
	char trs_stk_st_date[8];	// 자사주신고개시일자, YYYYMMDD 신고서상의 자사주매매 개시일자
	char trs_stk_ed_date[8];	// 자사주신고종료일자, YYYYMMDD 신고서상의 자사주매매 종료일자
	char trs_stk_trd_code[1];	// 자사주매매방법코드, 0:해당없음 1:자사주일반 2:한은등 자사주 3:정부등 자사주\n※2,3 : 장종료후시간외대량매수만 가능, 당일거래(매매거래의\n        종류)관련 사용\n        →일반자사주는 시간외대량 매수불가(매도만 가능)\n※3 : 장종료후시간외대량매수시 상/하한가 제한없음
	char trs_stk_ptcp_nr[5];	// "자사주신청시장참가자 번호", 회원번호 예) '00001'
	char open_trs_stk_qty[12];	// "시가단일가자사주신청 수량", 신고기간중의 신청일 시가단일가 신청 수량
	char opr_time_trs_stk_qty[12];	// 장중자사주신청수량, 신고기간중의 신청일 접속 신청 수량
	char ofhr_msv_trs_stk_qty[12];	// "시간외대량자사주 신청수량", 시간외(오전, 오후)시장의 자사주 신고수량
	char trs_stk_cum_ccls_qty[12];	// 자사주누적체결수량, 신고기간중의 정규장, 시간외시장에서 자사주 체결수량 누적
	char trs_stk_cum_trd_val[18];	// 자사주누적거래대금, 신고기간중의 정규장, 시간외시장에서 자사주 거래대금 누적
	char filler[2];	// FILLER, SPACE
	char ff[1];	// FF, END OF TEXT (0xFF)
} KOSDAQ_TRS_STK_ARNG_INFO;


// 코스닥_자사주 매매정보
typedef struct _KOSDAQ_TRS_STK_TRD_INFO {
	char data_clsf[2];	// DATA구분, B0
	char info_clsf[2];	// 정보구분, 01:주식
	char mkt_clsf[1];	// 시장구분, 1:유가증권 2:코스닥
	char isin_code[12];	// 종목코드, 표준코드
	char snr[8];	// 일련번호, 1~99999999 종목일련번호 2014.03.03
	char ccls_prc[9];	// 체결가격, 단위:원
	char ccls_qty[10];	// 체결수량, 단위:주
	char sess_id[2];	// 세션ID, 코드값모음 참조
	char bid_trs_stk_id[5];	// 매수자사주신고서ID, 0:해당없음 N:자사주직접일반 S:자사주직접스탁옵션\n1~99999:자사주신탁(신고서일련번호)\n※값은 왼쪽정렬  예) "N", "1"\n※자사주신탁일련번호는 종목별로 영구적으로 누적 채번됨\n  직접에 반해 신탁에 일련번호가 존재하는 이유는 동일\n  종목에 대해서 여러 신탁회사에서 자사주를 신고할 수\n  있도록 허용하기 위함임
	char ask_trs_stk_id[5];	// 매도자사주신고서ID, 매수자사주신고서ID와 동일
	char filler[3];	// FILLER, SPACE 1->3 2014.03.03
	char ff[1];	// FF, END OF TEXT (0xFF)
} KOSDAQ_TRS_STK_TRD_INFO;


// 코스닥_시세RECOVERY
typedef struct _KOSDAQ_MKT_PRC_RCVR {
	char data_clsf[2];	// DATA구분, B1:종가 B2:시세REC
	char info_clsf[2];	// 정보구분, 01:주식 02:ELW
	char mkt_clsf[1];	// 시장구분, 1:유가증권 2:코스닥
	char isin_code[12];	// 종목코드, 표준코드
	char stk_snr[5];	// 종목일련번호, 종목배치(A0)의 종목일련번호
	char flct_clsf[1];	// 등락구분, 0:판단불가 1:상한 2:상승 3:보합 4:하한 5:하락
	char prev_ctrs[9];	// 전일대비, 단위:원
	char cur_prc[9];	// 현재가
	char open[9];	// 시가, 정규장 시가
	char hi[9];	// 고가, 정규장 고가
	char low[9];	// 저가, 정규장 저가
	char ask_prc[9];	// 매도호가, B1시 0값 SET
	char bid_prc[9];	// 매수호가, B1시 0값 SET
	char cum_ccls_qty[12];	// 누적체결수량, 단위:주 ※시간외단일가, BUY-IN을 제외한 모든 체결수량 합산
	char cum_trd_val[18];	// 누적거래대금, 단위:원 ※시간외단일가, BUY-IN을 제외한 모든 거래대금 합산
	char trend_flg[1];	// 실세/기세 구분, 0:초기값 1:실세 2:기세 3:거래무 4:시가기준가종목의 기세
	char brd_evt_id[3];	// 보드이벤트ID, B1/B2 에서는 보드이벤트ID 사용금지(과거 상태값이 전송될 수 있음). 추후, 해당 항목 '000' 세팅 예정. 2014.03.24)
	char brd_id[2];	// 보드ID, ※ 코드값모음 참조
	char trsp_flg[1];	// 거래정지여부, Y, N
	char bopen_ofhr_ccls_qty[12];	// 장개시전시간외종가체결수량, 대량, 바스켓은 제외, 단위:주
	char bopen_ofhr_trd_val[18];	// 장개시전시간외종가거래대금, 대량, 바스켓은 제외, 단위:원
	char opr_time_ccls_qty[12];	// 정규장체결수량, 대량, 바스켓은 제외, 단위:주
	char opr_time_trd_val[18];	// 정규장거래대금, 대량, 바스켓은 제외, 단위:원
	char ofhr_cls_ccls_qty[12];	// 장종료후시간외종가체결수량, 대량, 바스켓은 제외, 단위:주
	char ofhr_cls_trd_val[18];	// 장종료후시간외종가거래대금, 대량, 바스켓은 제외, 단위:원
	char elw_ely_cls_flg[1];	// ELW조기종료여부, Y,N 조기종료ELW 外 종목은 Default 'N' SET
	char elw_ely_cls_time[6];	// ELW조기종료시간, HHMMSS, ELW조기종료여부가 'Y'인 경우만 설정
	char cmpt_msv_dir_clsf[1];	// 경쟁대량 방향구분, 0:해당없음, 1:매도, 2:매수
	char gen_bin_ccls_qty[12];	// 일반 Buy-in 체결수량, 단위:주
	char gen_bin_ccls_trd_val[18];	// 일반 Buy-in 거래대금, 단위:원
	char day_bin_ccls_qty[12];	// 당일 Buy-in 체결수량, 단위:주
	char day_bin_ccls_trd_val[18];	// 당일 Buy-in 거래대금, 단위:원
	char filler[8];	// FILLER, SPACE
	char ff[1];	// FF, END OF TEXT (0xFF)
} KOSDAQ_MKT_PRC_RCVR;


// 코스닥_시간외단일가_리커버리_최종
typedef struct _KOSDAQ_OFH_RCVR_FINAL {
	char data_clsf[2];	// DATA구분, B3:시간외단일가최종 B4:시간외단일가REC
	char info_clsf[2];	// 정보구분, 01:주식
	char mkt_clsf[1];	// 시장구분, 1:유가증권 2:코스닥
	char isin_code[12];	// 종목코드, 표준코드
	char stk_snr[5];	// 종목일련번호, 종목배치(A0)의 종목일련번호
	char ofhr_cnst_clsf[1];	// 시간외단일가등락구분, 0:판단불가 1:상한 2:상승 3:보합 4:하한 5:하락
	char ofhr_cnst[9];	// 시간외단일가대비, 단위:원
	char ofhr_cnst_ceil[9];	// 시간외단일가상한가
	char ofhr_cnst_flr[9];	// 시간외단일가하한가
	char ofhr_cnst_cur[9];	// 시간외단일가현재가
	char ofhr_cnst_open[9];	// 시간외단일가시가
	char ofhr_cnst_hi[9];	// 시간외단일가고가
	char ofhr_cnst_lo[9];	// 시간외단일가저가
	char ofhr_cnst_ask[9];	// 시간외단일가매도호가, B3시 0값 SET
	char ofhr_cnst_bid[9];	// 시간외단일가매수호가, B3시 0값 SET
	char ofhr_cnst_cum_ccls_qty[12];	// 시간외단일가누적체결수량
	char ofhr_cnst_cum_trd_val[18];	// 시간외단일가누적거래대금
	char tot_cum_ccls_qty[12];	// 전체 총 누적체결수량
	char tot_cum_trd_val[18];	// 전체 총 누적거래대금
	char ofhr_mkt_clsf[1];	// 시간외단일가장구분, 0:초기값 1:시간외단일가개시 2:시간외단일가마감
	char trsp_flg[1];	// 거래정지여부, Y, N
	char trend_flg[1];	// 실세/기세 구분, 0:초기값 1:실세 2:기세 3:거래무 4:시가기준가종목의 기세
	char filler[2];	// FILLER, SPACE
	char ff[1];	// FF, END OF TEXT (0xFF)
} KOSDAQ_OFH_RCVR_FINAL;


// 코스닥_시간외단일가_리커버리
typedef struct _KOSDAQ_OFH_RCVR {
	char data_clsf[2];	// DATA구분, B3:시간외단일가최종 B4:시간외단일가REC
	char info_clsf[2];	// 정보구분, 01:주식
	char mkt_clsf[1];	// 시장구분, 1:유가증권 2:코스닥
	char isin_code[12];	// 종목코드, 표준코드
	char stk_snr[5];	// 종목일련번호, 종목배치(A0)의 종목일련번호
	char ofhr_cnst_clsf[1];	// 시간외단일가등락구분, 0:판단불가 1:상한 2:상승 3:보합 4:하한 5:하락
	char ofhr_cnst[9];	// 시간외단일가대비, 단위:원
	char ofhr_cnst_ceil[9];	// 시간외단일가상한가
	char ofhr_cnst_flr[9];	// 시간외단일가하한가
	char ofhr_cnst_cur[9];	// 시간외단일가현재가
	char ofhr_cnst_open[9];	// 시간외단일가시가
	char ofhr_cnst_hi[9];	// 시간외단일가고가
	char ofhr_cnst_lo[9];	// 시간외단일가저가
	char ofhr_cnst_ask[9];	// 시간외단일가매도호가, B3시 0값 SET
	char ofhr_cnst_bid[9];	// 시간외단일가매수호가, B3시 0값 SET
	char ofhr_cnst_cum_ccls_qty[12];	// 시간외단일가누적체결수량
	char ofhr_cnst_cum_trd_val[18];	// 시간외단일가누적거래대금
	char tot_cum_ccls_qty[12];	// 전체 총 누적체결수량
	char tot_cum_trd_val[18];	// 전체 총 누적거래대금
	char ofhr_mkt_clsf[1];	// 시간외단일가장구분, 0:초기값 1:시간외단일가개시 2:시간외단일가마감
	char trsp_flg[1];	// 거래정지여부, Y, N
	char trend_flg[1];	// 실세/기세 구분, 0:초기값 1:실세 2:기세 3:거래무 4:시가기준가종목의 기세
	char filler[2];	// FILLER, SPACE
	char ff[1];	// FF, END OF TEXT (0xFF)
} KOSDAQ_OFH_RCVR;


// 코스닥_현재등락
typedef struct _KOSDAQ_CUR_FLCT {
	char data_clsf[2];	// DATA구분, B5
	char info_clsf[2];	// 정보구분, 01:주식
	char mkt_clsf[1];	// 시장구분, 1:유가증권 2:코스닥
	char tot_stk_nr[5];	// 전체 종목수
	char trd_form_stk_nr[5];	// 거래형성 종목수
	char ceil_stk_nr[5];	// 상한 종목수
	char rise_stk_nr[5];	// 상승 종목수
	char stdstl_stk_nr[5];	// 보합 종목수
	char flr_stk_nr[5];	// 하한 종목수
	char fall_stk_nr[5];	// 하락 종목수
	char trend_stk_nr[5];	// 기세 종목수
	char trend_rise_stk_nr[5];	// 기세상승 종목수
	char trend_fall_stk_nr[5];	// 기세하락 종목수
	char filler[4];	// FILLER, SPACE
	char ff[1];	// FF, END OF TEXT (0xFF)
} KOSDAQ_CUR_FLCT;


// 코스닥_Buy-in_실행수량
typedef struct _KOSDAQ_BIN_EXCQ {
	char data_clsf[2];	// DATA구분, O4
	char info_clsf[2];	// 정보구분, 01:주식
	char mkt_clsf[1];	// 시장구분, 1:유가증권, 2:코스닥, 8:코넥스
	char isin_code[12];	// 종목코드, 표준코드 또는 "999999999999" 개발가이드 참조
	char snr[8];	// 일련번호, ※ Buy-in구분코드별로 일련번호 설정
	char trsm_date[8];	// 전송일자, YYYYMMDD
	char bin_clsf_code[1];	// Buy-in구분코드, 1: 일반 Buy-in, 2: 당일 Buy-in
	char scrt_grp_id[2];	// 증권그룹ID, ST:주식, MF:증권투자회사, RT:리츠, SC:선박투자회사,\nIF:인프라투융자회사, DR:예탁증서, SW:신주인수권증권,\nSR:신주인수권증서, EW:주식워런트증권, EF:상장지수펀드,\nBC:수익증권, FE:해외ETF, FS:해외원주\nEN:ETN(2014.11.17)
	char bin_exc_qty[15];	// Buy-in 실행수량
	char filler[8];	// FILLER
	char ff[1];	// FF, END OF TEXT (0xFF)
} KOSDAQ_BIN_EXCQ;


// 코스닥 업종별 배당수익률
typedef struct _KOSDAQ_BYIND_DYR {
	char data_clsf[2];	// DATA구분, P2
	char info_clsf[2];	// 정보구분, 01:주식
	char mkt_clsf[1];	// 시장구분, 1:유가증권 2:코스닥
	char idx_ind_code[3];	// 지수업종코드, ※코드값모음 참조
	char dyr[7];	// 배당수익률, 99999v99
	char ff[1];	// FF, END OF TEXT (0xFF)
} KOSDAQ_BYIND_DYR;


// 코스닥_장개시전_호가잔량
typedef struct _KOSDAQ_BOPEN_ASK_RSD {
	char data_clsf[2];	// DATA구분, B8
	char info_clsf[2];	// 정보구분, 01:주식
	char mkt_clsf[1];	// 시장구분, 1:유가증권 2:코스닥
	char isin_code[12];	// 종목코드, 표준코드
	char stk_snr[5];	// 종목일련번호, 종목배치(A0)의 종목일련번호
	char cum_ccls_qty[12];	// 누적체결수량
	char tot_ask_rsd[12];	// 총매도호가잔량
	char tot_bid_rsd[12];	// 총매수호가잔량
	char filler[1];	// FILLER, SPACE
	char ff[1];	// FF, END OF TEXT (0xFF)
} KOSDAQ_BOPEN_ASK_RSD;


// 코스닥_호가잔량_LP호가_제외
typedef struct _KOSDAQ_ASK_RSD_WOLP {
	char data_clsf[2];	// DATA구분, B6
	char info_clsf[2];	// 정보구분, 01:주식
	char mkt_clsf[1];	// 시장구분, 1:유가증권 2:코스닥
	char isin_code[12];	// 종목코드, 표준코드
	char stk_snr[5];	// 종목일련번호, 종목배치(A0)의 종목일련번호
	char cum_ccls_qty[12];	// 누적체결수량
	STOCK_LOB_INFO lob_infos[10];	// 호가
	char ask_10_tot_rsd[12];	// 10단계호가매도총잔량
	char bid_10_tot_rsd[12];	// 10단계호가매수총잔량
	char filler1[12];	// FILLER
	char filler2[12];	// FILLER
	char ofhr_ask_tot_rsd[12];	// 장종료후시간외매도총호가잔량, 보드ID "G3"일때 값이 설정됨
	char ofhr_bid_tot_rsd[12];	// 장종료후시간외매수총호가잔량, 보드ID "G3"일때 값이 설정됨
	char sess_id[2];	// 세션ID, ※ 코드값모음 참조
	char brd_id[2];	// 보드ID, ※ 코드값모음 참조
	char exp_ccls_prc[9];	// 예상체결가격
	char exp_ccls_qty[12];	// 예상체결수량
	char cmpt_msv_dir_clsf[1];	// 경쟁대량 방향구분, 0:해당없음, 1:매도, 2:매수
	char filler3[7];	// FILLER, SPACE
	char ff[1];	// FF, END OF TEXT (0xFF)
} KOSDAQ_ASK_RSD_WOLP;


// 코스닥_공매도
typedef struct _KOSDAQ_SHORT {
	char data_clsf[2];	// DATA구분, I8
	char info_clsf[2];	// 정보구분, 01:주식
	char mkt_clsf[1];	// 시장구분, 1:유가증권 2:코스닥
	char isin_code[12];	// 종목코드, 표준코드
	char snr[8];	// 일련번호, 1~99999999 종목일련번호
	char short_brwg_ask_ccls_qty[12];	// "공매도차입증권매도 체결수량", 단위:주
	char short_brwg_ask_trd_val[18];	// "공매도차입증권매도 거래대금", 단위:원
	char filler[4];	// FILLER, SPACE 2->4 2014.03.03
	char ff[1];	// FF, END OF TEXT (0xFF)
} KOSDAQ_SHORT;


// 코스닥_시세종가
typedef struct _KOSDAQ_MKT_PRC_CLS {
	char data_clsf[2];	// DATA구분, B1:종가 B2:시세REC
	char info_clsf[2];	// 정보구분, 01:주식 02:ELW
	char mkt_clsf[1];	// 시장구분, 1:유가증권 2:코스닥
	char isin_code[12];	// 종목코드, 표준코드
	char stk_snr[5];	// 종목일련번호, 종목배치(A0)의 종목일련번호
	char flct_clsf[1];	// 등락구분, 0:판단불가 1:상한 2:상승 3:보합 4:하한 5:하락
	char prev_ctrs[9];	// 전일대비, 단위:원
	char cur_prc[9];	// 현재가
	char open[9];	// 시가, 정규장 시가
	char hi[9];	// 고가, 정규장 고가
	char low[9];	// 저가, 정규장 저가
	char ask_prc[9];	// 매도호가, B1시 0값 SET
	char bid_prc[9];	// 매수호가, B1시 0값 SET
	char cum_ccls_qty[12];	// 누적체결수량, 단위:주 ※시간외단일가, BUY-IN을 제외한 모든 체결수량 합산
	char cum_trd_val[18];	// 누적거래대금, 단위:원 ※시간외단일가, BUY-IN을 제외한 모든 거래대금 합산
	char trend_flg[1];	// 실세/기세 구분, 0:초기값 1:실세 2:기세 3:거래무 4:시가기준가종목의 기세
	char brd_evt_id[3];	// 보드이벤트ID, B1/B2 에서는 보드이벤트ID 사용금지(과거 상태값이 전송될 수 있음). 추후, 해당 항목 '000' 세팅 예정. 2014.03.24)
	char brd_id[2];	// 보드ID, ※ 코드값모음 참조
	char trsp_flg[1];	// 거래정지여부, Y, N
	char bopen_ofhr_ccls_qty[12];	// 장개시전시간외종가체결수량, 대량, 바스켓은 제외, 단위:주
	char bopen_ofhr_trd_val[18];	// 장개시전시간외종가거래대금, 대량, 바스켓은 제외, 단위:원
	char opr_time_ccls_qty[12];	// 정규장체결수량, 대량, 바스켓은 제외, 단위:주
	char opr_time_trd_val[18];	// 정규장거래대금, 대량, 바스켓은 제외, 단위:원
	char ofhr_cls_ccls_qty[12];	// 장종료후시간외종가체결수량, 대량, 바스켓은 제외, 단위:주
	char ofhr_cls_trd_val[18];	// 장종료후시간외종가거래대금, 대량, 바스켓은 제외, 단위:원
	char elw_ely_cls_flg[1];	// ELW조기종료여부, Y,N 조기종료ELW 外 종목은 Default 'N' SET
	char elw_ely_cls_time[6];	// ELW조기종료시간, HHMMSS, ELW조기종료여부가 'Y'인 경우만 설정
	char cmpt_msv_dir_clsf[1];	// 경쟁대량 방향구분, 0:해당없음, 1:매도, 2:매수
	char gen_bin_ccls_qty[12];	// 일반 Buy-in 체결수량, 단위:주
	char gen_bin_ccls_trd_val[18];	// 일반 Buy-in 거래대금, 단위:원
	char day_bin_ccls_qty[12];	// 당일 Buy-in 체결수량, 단위:주
	char day_bin_ccls_trd_val[18];	// 당일 Buy-in 거래대금, 단위:원
	char filler[8];	// FILLER, SPACE
	char ff[1];	// FF, END OF TEXT (0xFF)
} KOSDAQ_MKT_PRC_CLS;


// 코스닥_업종별투자자별
typedef struct _KOSDAQ_BYIND_BYINV {
	char data_clsf[2];	// DATA구분, C0
	char info_clsf[2];	// 정보구분, 01:주식
	char mkt_clsf[1];	// 시장구분, 1:유가증권 2:코스닥
	char cmpt_time[6];	// 산출시각, 90초 주기
	char inv_code[4];	// 투자자코드, ※코드값모음 참조\n*코드'7000'시 수량, 대금정보 항목 0으로 전송 (20181210)
	char ind_code[3];	// 업종코드, ※코드값모음 업종지수코드분류 참조\n산출업종;코스피/코스닥종합지수,코스피200지수
	char ask_ccls_qty[12];	// 매도체결수량, 단위:주
	char ask_trd_val[18];	// 매도거래대금, 단위:원
	char bid_ccls_qty[12];	// 매수체결수량, 단위:주
	char bid_trd_val[18];	// 매수거래대금, 단위:원
	char filler[7];	// FILLER, SPACE
	char ff[1];	// FF, END OF TEXT (0xFF)
} KOSDAQ_BYIND_BYINV;


// K-OTC 불성실공시 지정일, 만료일
typedef struct _KOTC_ISCNT_DATE_INFO {
	char iscnt_apnt_date[8];	// 불성실공시 지정일, YYYYMMDD
	char iscnt_ed_date[8];	// 불성실공시 만료일, YYYYMMDD
} KOTC_ISCNT_DATE_INFO;


// K-OTC 투자유의 정보
typedef struct _KOTC_INV_ATN_INFO {
	char inv_atn_rsn_code[2];	// 투자유의 사유코드, ※개발가이드 참조
	char inv_atn_apnt_date[8];	// 투자유의 지정일, YYYYMMDD
} KOTC_INV_ATN_INFO;


// K-OTC 종목배치
typedef struct _KOTC_STK_ARNG {
	char data_clsf[2];	// DATA구분, A0
	char info_clsf[2];	// 정보구분, 01:주식
	char mkt_clsf[1];	// 시장구분, 3:K-OTC
	char isin_code[12];	// 종목코드, 표준코드
	char snr[8];	// 일련번호, 1~99999999 건수체크용
	char sh_code[9];	// 단축코드, 왼쪽정렬((예)주식 6→7, 나머지 SPACE 처리)
	char proc_date[8];	// 처리일자, 영업일자 (YYYYMMDD)
	char kor_stk_nm[80];	// 한글종목명, SIZE변경(40→80) 2016.02.01
	char eng_abrv[40];	// 영문약명, SIZE변경(20→40) 2016.02.01
	char eng_stk_nm[80];	// 영문종목명, SIZE변경(40→80) 2016.02.01
	char kor_stk_abrv[40];	// 종목명(한글약명), SIZE변경(20→40) 2016.02.01
	char stk_snr[5];	// 종목일련번호
	char stk_clsf[1];	// 종목구분, 0:정상 1:신규 2:추가
	char mdim_biz_flg[1];	// 중소중견기업여부, 4:중소기업 5:중견기업 6중소중견비해당 7:미확인
	char std_type_ind_code[7];	// 표준산업업종코드
	char trd_base_prc[9];	// 매매기준가, 가중평균주가, 락발생시 ‘매매기준가’ SET\n기세시는 '기세가격' SET\nSIZE변경(7→9) 2016.02.01
	char prev_cls[9];	// 전일종가, 단위:원, SIZE변경(7→9) 2016.02.01
	char prev_wavg_prc[9];	// 전일가중평균주가, 단위:원, SIZE변경(7→9) 2016.02.01
	char pbct_stk_nr[15];	// 발행주식수, 단위:주, SIZE변경(12→15) 2016.02.01
	char pval[9];	// 액면가, 단위:원, SIZE변경(7→9) 2016.02.01
	char clsg_mth[2];	// 결산월, MM
	char clsg_clsf[1];	// 결산구분, 0:보통주병합(1-4) 5:1우선주병합 6:2우선주병합
	char per[6];	// PER, 9999V99
	char eps[9];	// EPS, 단위:원, SIZE변경(7→9) 2016.02.01
	char trsp_flg[1];	// 거래정지여부, 0:정상 1:정지
	char trsp_rsn[2];	// 거래정지사유, ※코드값모음 참조
	char lock_clsf[1];	// 락구분, 0:정상 1:권리락 2:액면분할 3:액면병합 4:감자 5:병합\n6:배당락
	char rgst_aplc[40];	// 등록신청사, 항목명(ASIS 지정신청사), SIZE변경(30→40) 2016.02.01
	char trd_open_date[8];	// 매매개시일, YYYYMMDD
	char cncl_clsf[1];	// 해제구분, 항목명 변경(ASIS 취소구분)\n0:정상 1:구주병합에 의한 해제2:지정 및 등록해제\n(ASIS 0:정상 1:신구주병합에 의한 취소 2:지정취소)
	char whyr_hi_prc[9];	// 연중최고가, SIZE변경(7→9) 2016.02.01
	char whyr_lo_prc[9];	// 연중최저가, SIZE변경(7→9) 2016.02.01
	char whyr_hi_date[4];	// 연중최고일, MMDD
	char whyr_lo_date[4];	// 연중최저일, MMDD
	char yr_cum_qty[17];	// 연누적거래량, SIZE변경(14→17) 2016.02.01
	char yr_cum_trd_val[18];	// 연누적 거래 대금, 단위:원, SIZE변경(17→18) 2016.02.01
	char pbl_ofr_clsf[1];	// 공모구분, 0:비공모, 1:공모
	char pbl_ofr_prc[9];	// 공모가, 단위:원, SIZE변경(7→9) 2016.02.01
	char affl_clsf[1];	// 소속부 구분, 4:등록기업부,5:지정기업부\n(ASIS 0:일반기업부, 1:벤처기업부)
	char type_rgst_apnt[1];	// 등록/지정유형, -항목명 변경(ASIS 지정유형)\n-값 추가\n 0:일반지정 1:코스닥이관 2:유가시장이관 3:코넥스이관\n (ASIS 0:일반지정 1:코스닥이관 2:거래소이관)
	char prev_vlm[14];	// 전일거래량
	char ceil_prc[9];	// 상한가, SIZE변경(7→9) 2016.02.01
	char flr_prc[9];	// 하한가, SIZE변경(7→9) 2016.02.01
	char iscnt[1];	// 불성실공시, 0:정상 1~5:불성실공시 1회~5회
	KOTC_ISCNT_DATE_INFO iscnt_dates[5];	// 불성실공시일
	char inv_atn_flg[1];	// 투자유의여부, 0:정상 1:투자유의
	KOTC_INV_ATN_INFO inv_atn_infos[15];	// 투자유의
	char filler1[1];	// FILLER, ASIS: 지수벤처기업구분
	char mkt_cap_scale[1];	// 시가총액규모, 지수제공시까지 SPACE\n(0:제외 1:대형주 2:중형주 3:소형주)
	char idx_ind_l[2];	// 지수업종(대), 지수제공시까지 SPACE
	char idx_ind_m[2];	// 지수업종(중), 지수제공시까지 SPACE
	char idx_ind_s[3];	// 지수업종(소), 지수제공시까지 SPACE
	char vtr_clsf[1];	// 벤처구분, 0:일반기업, 1:벤처기업
	char trend_clsf[1];	// 기세구분, 0:실세,1:기세,2:무거래
	char arng_trd_flg[1];	// 정리매매여부, 0:정상,1:정리매매
	char filler2[132];	// FILLER, SPACE\nSIZE변경(9→132)  2016.02.01
	char ff[1];	// FF, END OF TEXT (0xFF)
} KOTC_STK_ARNG;


// K-OTC 호가
typedef struct _KOTC_ASK_PRC {
	char data_clsf[2];	// DATA구분, A2
	char info_clsf[2];	// 정보구분, 01:주식
	char mkt_clsf[1];	// 시장구분, 3:K-OTC
	char isin_code[12];	// 종목코드, 표준코드
	char data_snr[8];	// 데이터 일련번호, 호가, 체결, 시장조치 포함한 일련번호
	char proc_clsf[1];	// 처리구분, 1:정상 2:정정 3:취소
	char ask_nr[6];	// 호가번호, 정상 처리시 호가번호
	char base_ask_nr[6];	// 원호가번호, 정상:0, 정정/취소시 해당원호가 번호
	char base_ask_prc[9];	// 원호가가격, 정상:0, 정정/취소시 원가격, SIZE변경(7→9) 2016.02.01
	char ask_bid_clsf[1];	// 매도/매수 구분, 1:매도 2:매수
	char prc[9];	// 가격, 정상:주문가격 정정:정정가격, SIZE변경(7→9) 2016.02.01
	char qty[10];	// 수량, 정상:주문수량 정정/취소:실정정/취소 수량
	char acpt_time[6];	// 접수시각
	char ask_tot_rsd[10];	// 매도총잔량
	char bid_tot_rsd[10];	// 매수총잔량
	char ask_prf_prc[9];	// 매도우선호가, SIZE변경(7→9) 2016.02.01
	char ask_prf_vol_rsd[10];	// 매도우선호가잔량
	char bid_prf_prc[9];	// 매수우선호가, SIZE변경(7→9) 2016.02.01
	char bid_prf_vol_rsd[10];	// 매수우선호가잔량
	char prc_band_vol_rsd[10];	// 가격대호가잔량, 정상:주문잔량 정정:정정잔량
	char base_prc_band_vol_rsd[10];	// 원가격대호가잔량, 정상:0, 정정/취소시 원잔량
	char brkg_nr[3];	// 증권사번호, 거래원코드 참조
	char brch_nm[12];	// 지점명, SPACE
	char filler[33];	// FILLER, SPACE, SIZE변경(1→33) 2016.02.01
	char ff[1];	// FF, END OF TEXT (0xFF)
} KOTC_ASK_PRC;


// K-OTC 체결
typedef struct _KOTC_CCLS {
	char data_clsf[2];	// DATA구분, A3
	char info_clsf[2];	// 정보구분, 01:주식
	char mkt_clsf[1];	// 시장구분, 3:K-OTC
	char isin_code[12];	// 종목코드, 표준코드
	char data_snr[8];	// 데이터 일련번호, 호가, 체결, 시장조치 포함한 일련번호
	char ccls_nr[6];	// 체결번호, 종목별 체결번호
	char ccls_prc[9];	// 체결가, SIZE변경(7→9) 2016.02.01
	char ccls_qty[10];	// 체결량
	char ccls_time[6];	// 체결시각
	char ask_prc_nr[6];	// 매도호가번호, 종목별 호가번호임
	char bid_prc_nr[6];	// 매수호가번호, 종목별 호가번호임
	char open[9];	// 고가, SIZE변경(7→9) 2016.02.01
	char hi[9];	// 저가, SIZE변경(7→9) 2016.02.01
	char wavg_prc[9];	// 가중평균주가, SIZE변경(7→9) 2016.02.01
	char tot_ccls_cum_qty[12];	// 전체체결누적거래량
	char tot_ccls_cum_trd_val[14];	// 전체체결누적거래대금
	char ask_tot_rsd[10];	// 매도총잔량
	char bid_tot_rsd[10];	// 매수총잔량
	char ask_prf_prc[9];	// 매도우선호가, SIZE변경(7→9) 2016.02.01
	char ask_prf_vol_rsd[10];	// 매도우선호가잔량
	char bid_prf_prc[9];	// 매수우선호가, SIZE변경(7→9) 2016.02.01
	char bid_prf_vol_rsd[10];	// 매수우선호가잔량
	char prev_ctrs_clsf[1];	// 전일대비구분, +:상승 -:하락 SPACE:보합
	char prev_ctrs[9];	// 전일대비, SIZE변경(7→9) 2016.02.01
	char ccls_prc_ask_rsd[10];	// 체결가대매도잔량
	char ccls_prc_bid_rsd[10];	// 체결가대매수잔량
	char filler[40];	// FILLER, SPACE, SIZE변경(4→40  2016.02.01
	char ff[1];	// FF, END OF TEXT (0xFF)
} KOTC_CCLS;


// K-OTC 종목마감
typedef struct _KOTC_STK_CLSG {
	char data_clsf[2];	// DATA구분, A6
	char info_clsf[2];	// 정보구분, 1
	char mkt_clsf[1];	// 시장구분, 3:K-OTC
	char isin_code[12];	// 종목코드, 표준코드
	char data_snr[8];	// 데이터 일련번호, 호가,체결,장운영 포함한 일련번호
	char stk_cls_wght_prc[9];	// 종목마감 가중가, SIZE변경(7→9) 2016.02.01
	char trend_flg[1];	// 실세/기세구분, 0:가중평균가,1:기세,2:무거래
	char filler[4];	// FILLER, SPACE, SIZE변경(6→4) 2016.02.01
	char ff[1];	// FF, END OF TEXT(0xFF)
} KOTC_STK_CLSG;


// K-OTC 장운영
typedef struct _KOTC_MKT_OPR {
	char data_clsf[2];	// DATA구분, A7
	char info_clsf[2];	// 정보구분, 01:주식
	char mkt_clsf[1];	// 시장구분, 3:K-OTC
	char isin_code[12];	// 종목코드, 표준코드
	char data_snr[8];	// 데이터 일련번호, 호가, 체결, 장운용 포함한 일련번호
	char clsf[1];	// 구분, 1:매매거래정지 2:매매거래정지후해제
	char rsn[2];	// 사유
	char filler[1];	// FILLER, SPACE
	char ff[1];	// FF, END OF TEXT (0xFF)
} KOTC_MKT_OPR;


// K-OTC 시장조치
typedef struct _KOTC_MKT_ACT {
	char data_clsf[2];	// DATA구분, G5
	char info_clsf[2];	// 정보구분, 01:주식
	char mkt_clsf[1];	// 시장구분, 3:K-OTC
	char isin_code[12];	// 종목코드, 표준코드
	char data_kind[2];	// 데이터 분류, 01:기준가 및 상하한가 변경 02:임시정지\n03:임시정지후 재개
	char chg_date[8];	// 변경일, YYYYMMDD(데이터분류 01이 아니면 "0")
	char chg_time[8];	// 변경시각, HHMMSSMM(데이터분류 01이 아니면 "0")
	char bact_base_prc[9];	// 조치전 기준가, 단위:원(데이터분류 01이 아니면 "0"), \nSIZE변경(7→9)  2016.02.01
	char bact_ceil[9];	// 조치전 상한가, 단위:원(데이터분류 01이 아니면 "0"), \nSIZE변경(7→9)  2016.02.01
	char bact_flr[9];	// 조치전 하한가, 단위:원(데이터분류 01이 아니면 "0"), \nSIZE변경(7→9)  2016.02.01
	char aact_base_prc[9];	// 조치후 기준가, 단위:원(데이터분류 01이 아니면 "0"), \nSIZE변경(7→9)  2016.02.01
	char aact_ceil[9];	// 조치후 상한가, 단위:원(데이터분류 01이 아니면 "0"), \nSIZE변경(7→9)  2016.02.01
	char aact_flr[9];	// 조치후 하한가, 단위:원(데이터분류 01이 아니면 "0"), \nSIZE변경(7→9)  2016.02.01
	char filler[10];	// FILLER, SPACE, SIZE변경(2→10)  2016.02.01
	char ff[1];	// FF, END OF TEXT (0xFF)
} KOTC_MKT_ACT;


// K-OTC 공시 배치/실시간
typedef struct _KOTC_DCLS_ARNG_RT {
	char data_clsf[2];	// DATA구분, E9:공시배치 F0:공시실시간
	char info_clsf[2];	// 정보구분, 01:주식
	char mkt_clsf[1];	// 시장구분, 3:K-OTC
	char isin_code[12];	// 종목코드, 업무마감:999999999999
	char dcls_snr[6];	// 공시일련번호, 000001~999999\n업무마감:999999
	char rgst_date[8];	// 등록일자, YYYYMMDD
	char proc_clsf[1];	// 처리구분, 1:정상 2:정정 3:취소
	char rsn[2];	// 사유, 코드값모음 참조
	char line_nr[2];	// 라인번호, 00:제목 01~20:내용 99:END
	char dcls_title[75];	// 공시제목/내용
	char filler[8];	// FILLER, SPACE
	char ff[1];	// FF, END OF TEXT (0xFF)
} KOTC_DCLS_ARNG_RT;


// KOSDAQ지수
typedef struct _KOSDAQ_IDX {
	char data_clsf[2];	// DATA구분, ※개발가이드 참조
	char info_clsf[2];	// 정보구분, 01:주식
	char mkt_clsf[1];	// 시장구분, 1:유가증권 2:코스닥
	char ind_code[3];	// 업종코드, ※개발가이드 참조
	char time[6];	// 시간, ※개발가이드 참조
	char idx[8];	// 지수, 9(6)V9(2)
	char sign[1];	// 부호, +:상승 "-":하락 " ":보합
	char ctrs[8];	// 대비, 999999V99
	char ccls_qty[8];	// 체결수량, 단위:천주
	char trd_val[8];	// 거래대금, 단위:백만원
	char filler[2];	// FILLER, SPACE
	char ff[1];	// FF, END OF TEXT (0xFF)
} KOSDAQ_IDX;


// KOSDAQ예상지수
typedef struct _KOSDAQ_EXP_IDX {
	char data_clsf[2];	// DATA구분, ※개발가이드 참조
	char info_clsf[2];	// 정보구분, 01:주식
	char mkt_clsf[1];	// 시장구분, 1:유가증권 2:코스닥
	char ind_code[3];	// 업종코드, ※개발가이드 참조
	char time[6];	// 시간, ※개발가이드 참조
	char idx[8];	// 지수, 9(6)V9(2)
	char sign[1];	// 부호, +:상승 "-":하락 " ":보합
	char ctrs[8];	// 대비, 999999V99
	char ccls_qty[8];	// 체결수량, 단위:천주
	char trd_val[8];	// 거래대금, 단위:백만원
	char filler[2];	// FILLER, SPACE
	char ff[1];	// FF, END OF TEXT (0xFF)
} KOSDAQ_EXP_IDX;


// 코스닥_거래원
typedef struct _KOSDAQ_TRS {
	char data_clsf[2];	// DATA구분, B9
	char info_clsf[2];	// 정보구분, 01:주식 02:ELW
	char mkt_clsf[1];	// 시장구분, 1:유가증권 2:코스닥
	char isin_code[12];	// 종목코드, 표준코드
	char snr[8];	// 일련번호, 1~99999999 종목일련번호 2014.03.03
	STOCK_SRC_INFO src_infos[5];	// 거래원정보 OCCURS
	char filler[4];	// FILLER, SPACE 2->4 2014.03.03
	char ff[1];	// FF, END OF TEXT (0xFF)
} KOSDAQ_TRS;


// 코스닥_종목별투자자별 종가
typedef struct _KOSDAQ_BYSTK_BYINV_CLS {
	char data_clsf[2];	// DATA구분, C1
	char info_clsf[2];	// 정보구분, 01:주식 02:ELW
	char mkt_clsf[1];	// 시장구분, 1:유가증권 2:코스닥
	char isin_code[12];	// 종목코드, 표준코드
	char snr[8];	// 일련번호, 1~99999999 종목일련번호 2014.03.03
	STOCK_INV_INFO inv_infos[12];	// 투자자 OCCURS 12
	char filler[6];	// FILLER, SPACE  8→4   2010.10.11\nSPACE  4→6   2014.03.03
	char ff[1];	// FF, END OF TEXT (0xFF)
} KOSDAQ_BYSTK_BYINV_CLS;


// 현물 Polling data
typedef struct _CUR_POLG_DATA {
	char data_clsf[2];	// DATA구분, I2
	char info_clsf[2];	// 정보구분, 00:초기값
	char mkt_clsf[1];	// 시장구분, 0:초기값
	char time[4];	// 시간, HHMM
	char ff[1];	// FF, END OF TEXT (0xFF)
} CUR_POLG_DATA;


// 코스닥_프로그램매매 호가
typedef struct _KOSDAQ_PRGTRD_ASK {
	char data_clsf[2];	// DATA구분, C3
	char info_clsf[2];	// 정보구분, 01:주식
	char mkt_clsf[1];	// 시장구분, 1:유가증권 2:코스닥
	char isin_code[12];	// 종목코드
	char snr[8];	// 일련번호, 1~99999999 종목일련번호 2014.03.03
	// 프로그램매매호가잔량, =============================================
	char idx_abtg_ask_rsd[12];	// 지수차익매도호가잔량
	char idx_abtg_bid_rsd[12];	// 지수차익매수호가잔량
	char idx_nabtg_ask_rsd[12];	// 지수비차익매도호가잔량
	char idx_nabtg_bid_rsd[12];	// 지수비차익매수호가잔량
	// 프로그램매매호가수량, =============================================
	char idx_abtg_ask_qty[12];	// 지수차익매도호가수량
	char idx_abtg_bid_qty[12];	// 지수차익매수호가수량
	char idx_nabtg_ask_qty[12];	// 지수비차익매도호가수량
	char idx_nabtg_bid_qty[12];	// 지수비차익매수호가수량
	// 프로그램매매 사전공시용잔량
	char prior_idx_abtg_ask_rsd[12];	// 지수차익매도호가잔량
	char prior_idx_abtg_bid_rsd[12];	// 지수차익매수호가잔량
	char prior_idx_nabtg_ask_rsd[12];	// 지수비차익매도호가잔량
	char prior_idx_nabtg_bid_rsd[12];	// 지수비차익매수호가잔량
	// 프로그램매매체결내용, =============================================
	char idx_abtg_ask_ccls_qty[12];	// "지수차익매도위탁 체결수량"
	char idx_abtg_ask_self_ccls_qty[12];	// "지수차익매도자기 체결수량"
	char idx_abtg_bid_ccls_qty[12];	// "지수차익매수위탁 체결수량"
	char idx_abtg_bid_self_ccls_qty[12];	// "지수차익매수자기 체결수량"
	char idx_nabtg_ask_ccls_qty[12];	// "지수비차익매도위탁 체결수량"
	char idx_nabtg_ask_self_ccls_qty[12];	// "지수비차익매도자기 체결수량"
	char idx_nabtg_bid_ccls_qty[12];	// "지수비차익매수위탁 체결수량"
	char idx_nabtg_bid_self_ccls_qty[12];	// "지수비차익매수자기 체결수량"
	char idx_abtg_ask_ccls_val[18];	// "지수차익매도위탁 체결금액"
	char idx_abtg_ask_self_ccls_val[18];	// "지수차익매도자기 체결금액"
	char idx_abtg_bid_ccls_val[18];	// "지수차익매수위탁 체결금액"
	char idx_abtg_bid_self_ccls_val[18];	// "지수차익매수자기 체결금액"
	char idx_nabtg_ask_ccls_val[18];	// "지수비차익매도위탁 체결금액"
	char idx_nabtg_ask_self_ccls_val[18];	// "지수비차익매도자기 체결금액"
	char idx_nabtg_bid_ccls_val[18];	// "지수비차익매수위탁 체결금액"
	char idx_nabtg_bid_self_ccls_val[18];	// "지수비차익매수자기 체결금액"
	// 프로그램매매 사후공시용잔량", =============================================
	char post_idx_abtg_ask_rsd[12];	// 지수차익매도호가잔량, 2011.05.30 신규
	char post_idx_abtg_bid_rsd[12];	// 지수차익매수호가잔량, 2011.05.30 신규
	char post_idx_nabtg_ask_rsd[12];	// 지수비차익매도호가잔량, 2011.05.30 신규
	char post_idx_nabtg_bid_rsd[12];	// 지수비차익매수호가잔량, 2011.05.30 신규
	char filler[2];	// FILLER, SPACE  8→10    2011.05.30  변경\nSPACE  10→2    2014.03.03  변경
	char ff[1];	// FF, END OF TEXT (0xFF)  410→460  2011.05.30  변경
} KOSDAQ_PRGTRD_ASK;


// 코스닥_프로그램매매 전체집계
typedef struct _KOSDAQ_PRGTRD_TOT {
	char data_clsf[2];	// DATA구분, J0
	char info_clsf[2];	// 정보구분, 01:주식
	char mkt_clsf[1];	// 시장구분, 1:유가증권 2:코스닥
	// 프로그램매매호가잔량
	char idx_abtg_ask_rsd[12];	// 지수차익매도호가잔량
	char idx_abtg_bid_rsd[12];	// 지수차익매수호가잔량
	char idx_nabtg_ask_rsd[12];	// 지수비차익매도호가잔량
	char idx_nabtg_bid_rsd[12];	// 지수비차익매수호가잔량
	// 프로그램매매호가수량
	char idx_abtg_ask_qty[12];	// 지수차익매도호가수량
	char idx_abtg_bid_qty[12];	// 지수차익매수호가수량
	char idx_nabtg_ask_qty[12];	// 지수비차익매도호가수량
	char idx_nabtg_bid_qty[12];	// 지수비차익매수호가수량
	// 프로그램매매 사전공시용잔량
	char prior_idx_abtg_ask_rsd[12];	// 지수차익매도호가잔량
	char prior_idx_abtg_bid_rsd[12];	// 지수차익매수호가잔량
	char prior_idx_nabtg_ask_rsd[12];	// 지수비차익매도호가잔량
	char prior_idx_nabtg_bid_rsd[12];	// 지수비차익매수호가잔량
	// 프로그램매매체결내용
	char idx_abtg_ask_ccls_qty[12];	// "지수차익매도위탁 체결수량"
	char idx_abtg_ask_self_ccls_qty[12];	// "지수차익매도자기 체결수량"
	char idx_abtg_bid_ccls_qty[12];	// "지수차익매수위탁 체결수량"
	char idx_abtg_bid_self_ccls_qty[12];	// "지수차익매수자기 체결수량"
	char idx_nabtg_ask_ccls_qty[12];	// "지수비차익매도위탁 체결수량"
	char idx_nabtg_ask_self_ccls_qty[12];	// "지수비차익매도자기 체결수량"
	char idx_nabtg_bid_ccls_qty[12];	// "지수비차익매수위탁 체결수량"
	char idx_nabtg_bid_self_ccls_qty[12];	// "지수비차익매수자기 체결수량"
	char idx_abtg_ask_ccls_val[18];	// "지수차익매도위탁 체결금액"
	char idx_abtg_ask_self_ccls_val[18];	// "지수차익매도자기 체결금액"
	char idx_abtg_bid_ccls_val[18];	// "지수차익매수위탁 체결금액"
	char idx_abtg_bid_self_ccls_val[18];	// "지수차익매수자기 체결금액"
	char idx_nabtg_ask_ccls_val[18];	// "지수비차익매도위탁 체결금액"
	char idx_nabtg_ask_self_ccls_val[18];	// "지수비차익매도자기 체결금액"
	char idx_nabtg_bid_ccls_val[18];	// "지수비차익매수위탁 체결금액"
	char idx_nabtg_bid_self_ccls_val[18];	// "지수비차익매수자기 체결금액"
	// 프로그램매매 사후공시용잔량
	char post_idx_abtg_ask_rsd[12];	// 지수차익매도호가잔량
	char post_idx_abtg_bid_rsd[12];	// 지수차익매수호가잔량
	char post_idx_nabtg_ask_rsd[12];	// 지수비차익매도호가잔량
	char post_idx_nabtg_bid_rsd[12];	// 지수비차익매수호가잔량
	char filler[2];	// FILLER, 2011.05.30 신규
	char ff[1];	// FF, END OF TEXT (0xFF)     390→440 2011.05.30 변경
} KOSDAQ_PRGTRD_TOT;


// 코스닥_프로그램매매 사전사후공시
typedef struct _KOSDAQ_PRGTRD_DCLS {
	char data_clsf[2];	// DATA구분, C5
	char info_clsf[2];	// 정보구분, 01:주식
	char mkt_clsf[1];	// 시장구분, 1:유가증권 2:코스닥
	char isin_code[12];	// 종목코드
	char snr[8];	// 일련번호, 1~99999999 종목일련번호 2014.03.03
	char prior_dcls_new_ask_qty[12];	// "사전공시신규호가 매도수량", 단위 : 주\n항목명변경:매도공시사전수량->사전공시신규호가매도수량
	char prior_dcls_new_bid_qty[12];	// "사전공시신규호가 매수수량", 단위 : 주\n항목명변경:매수공시사전수량->사전공시신규호가매수수량
	char prior_dcls_sbmt_ask_qty[12];	// "사전공시기제출호가 매도수량", 단위 : 주\n항목명변경:매도공시사전정정수량->사전공시기제출호가매도수량
	char prior_dcls_sbmt_bid_qty[12];	// "사전공시기제출호가 매수수량", 단위 : 주\n항목명변경:매수공시사전정정수량->사전공시기제출호가매수수량
	char post_dcls_ask_qty[12];	// 사후공시매도수량, 단위 : 주,  신규                2011.05.03
	char post_dcls_bid_qty[12];	// 사후공시매수수량, 단위 : 주,  신규                2011.05.03
	char filler[2];	// FILLER, SPACE  4→10  2011.05.30\nSPACE  10→2  2014.03.03
	char ff[1];	// FF, END OF TEXT (0xFF)  70→100 2011.05.30
} KOSDAQ_PRGTRD_DCLS;


// 코스닥 프로그램매매 투자자별 매매현황
typedef struct _KOSDAQ_PRGTRD_BYINV_STAT {
	char data_clsf[2];	// DATA구분, P0
	char info_clsf[2];	// 정보구분, 01:주식
	char mkt_clsf[1];	// 시장구분, 1:유가증권 2:코스닥
	char cmpt_time[6];	// 산출시각, 90초 주기
	char inv_clsf_code[4];	// 투자자구분코드, ※코드값모음 참조\n*코드'7000'시 수량, 대금정보 항목 0으로 전송 (20181210)
	char ask_abtg_ccls_qty[12];	// 매도차익체결수량
	char ask_abtg_trd_val[18];	// 매도차익거래대금
	char ask_nabtg_ccls_qty[12];	// 매도비차익체결수량
	char ask_nabtg_trd_val[18];	// 매도비차익거래대금
	char bid_abtg_ccls_qty[12];	// 매수차익체결수량
	char bid_abtg_trd_val[18];	// 매수차익거래대금
	char bid_nabtg_ccls_qty[12];	// 매수비차익체결수량
	char bid_nabtg_trd_val[18];	// 매수비차익거래대금
	char ff[1];	// FF, END OF TEXT (0xFF)
} KOSDAQ_PRGTRD_BYINV_STAT;


// 코스닥_종목상태정보(VI)
typedef struct _KOSDAQ_STK_STAT_INFO {
	char data_clsf[2];	// DATA구분, R8
	char info_clsf[2];	// 정보구분, 01:주식
	char mkt_clsf[1];	// 시장구분, 1:유가증권 2:코스닥
	char isin_code[12];	// 종목코드
	char stk_snr[5];	// 종목일련번호, 종목배치(A0)의 종목일련번호
	char brd_id[2];	// 보드ID, ※ 코드값모음 참조
	char trd_ccls_proc_time[9];	// 매매체결처리시각, 매매체결처리시각
	char vi_cncl_time[9];	// VI해제시각
	char vi_aply_clsf_code[1];	// VI적용구분코드, 1:VI-발동, 2:VI-해제
	char vi_type_code[1];	// VI종류코드, 1:정적VI, 2:동적VI, 3:정적&동적VI
	char stt_vi_base_prc[9];	// 정적VI발동기준가격
	char dyn_vi_base_prc[9];	// 동적VI발동기준가격
	char vi_prc[9];	// VI발동가격
	char stt_vi_dspr[13];	// 정적VI발동괴리율, 정적VI발동 괴리율\n부호자리(양수:0, 음수:-) + 99999.999999(유효숫자 12자리)
	char dyn_vi_dspr[13];	// 동적VI발동괴리율, 동적VI발동 괴리율\n부호자리(양수:0, 음수:-) + 99999.999999(유효숫자 12자리)
	char filler[2];	// FILLER, SPACE
	char ff[1];	// FF, END OF TEXT (0xFF)
} KOSDAQ_STK_STAT_INFO;
