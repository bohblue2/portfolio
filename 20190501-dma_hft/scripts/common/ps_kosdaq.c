// ps_kosdaq.c
// 코스닥주식
// 주석에 \n이 들어간건 나중에 이쁘게 바꿔야함

#include "ps_kosdaq.h"


// 코스닥 TR예상지수
int ParseAZ012(const double& timestamp, const char* in_buff, DF_KOSDAQ_TR_EXP_IDX* out) {
	KOSDAQ_TR_EXP_IDX* data = (KOSDAQ_TR_EXP_IDX*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA구분, ※개발가이드 참조
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// 정보구분, 01:주식
	out->mkt_clsf = data->mkt_clsf[0];	//시장구분, 1:유가증권 2:코스닥 9:해외주가지수 2012.04.30 추가
	memcpy(out->ind_clsf, data->ind_clsf, sizeof(data->ind_clsf));	// 업종코드, ※개발가이드 참조
	memcpy(out->time, data->time, sizeof(data->time));	// 시간, ※개발가이드 참조   ※해외주가지수일 경우 GMT시간
	out->idx = Str2Int(data->idx, sizeof(data->idx));	// 지수, 9(6)V9(2)
	out->crst = Str2SignDouble(data->sign, sizeof(data->sign) + sizeof(data->crst), 2);	// 대비, 999999V99
	out->ccls_qty = Str2Int(data->ccls_qty, sizeof(data->ccls_qty));	// 체결수량, 단위:천주  ※해외주가지수일 경우 FILLER처리
	out->trd_val = Str2Int(data->trd_val, sizeof(data->trd_val));	// 거래대금, 단위:백만원  ※해외주가지수일 경우 FILLER처리

	return 1;
}


// 코스닥 TR지수
int ParseAY012(const double& timestamp, const char* in_buff, DF_KOSDAQ_TR_IDX* out) {
	KOSDAQ_TR_IDX* data = (KOSDAQ_TR_IDX*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA구분, ※개발가이드 참조
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// 정보구분, 01:주식
	out->mkt_clsf = data->mkt_clsf[0];	//시장구분, 1:유가증권 2:코스닥 9:해외주가지수 2012.04.30 추가
	memcpy(out->ind_clsf, data->ind_clsf, sizeof(data->ind_clsf));	// 업종코드, ※개발가이드 참조
	memcpy(out->time, data->time, sizeof(data->time));	// 시간, ※개발가이드 참조   ※해외주가지수일 경우 GMT시간
	out->idx = Str2Int(data->idx, sizeof(data->idx));	// 지수, 9(6)V9(2)
	out->crst = Str2SignDouble(data->sign, sizeof(data->sign) + sizeof(data->crst), 2);	// 대비, 999999V99
	out->ccls_qty = Str2Int(data->ccls_qty, sizeof(data->ccls_qty));	// 체결수량, 단위:천주  ※해외주가지수일 경우 FILLER처리
	out->trd_val = Str2Int(data->trd_val, sizeof(data->trd_val));	// 거래대금, 단위:백만원  ※해외주가지수일 경우 FILLER처리

	return 1;
}


// 코스닥_체결
int ParseA3012(const double& timestamp, const char* in_buff, DF_KOSDAQ_CCLS* out) {
	KOSDAQ_CCLS* data = (KOSDAQ_CCLS*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA구분, A3
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// 정보구분, 01:주식 02:ELW
	out->mkt_clsf = data->mkt_clsf[0];	//시장구분, 1:유가증권 2:코스닥
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// 종목코드, 표준코드
	out->stk_snr = Str2Int(data->stk_snr, sizeof(data->stk_snr));	// 종목일련번호, 종목배치(A0)의 종목SEQ
	memcpy(out->brd_id, data->brd_id, sizeof(data->brd_id));	// 보드ID, ※ 코드값모음 참조
	out->ctrs_clsf = data->ctrs_clsf[0];	//전일대비(기준가대비) 구분, 0:판단불가 1:상한 2:상승 3:보합 4:하한 5:하락 ※ 정규시간외구분코드 값이 4인 경우 당일 종가 대비 ※ 정규시간외구분코드 값이 7,8인 경우 Buy-in기준가 대비
	out->prev_ctrs = Str2Int(data->prev_ctrs, sizeof(data->prev_ctrs));	// 전일대비, 단위:원 신주인수권 증서/증권의 신규 상장 당일 : 0
	out->ccls_prc = Str2Int(data->ccls_prc, sizeof(data->ccls_prc));	// 체결가격, 단위:원
	out->ccls_qty = Str2Dbl(data->ccls_qty, sizeof(data->ccls_qty), 0);	// 체결수량, 단위:주
	memcpy(out->sess_id, data->sess_id, sizeof(data->sess_id));	// 세션ID, ※ 코드값모음 참조
	out->open = Str2Int(data->open, sizeof(data->open));	// 시가, 단위:원 ※개발가이드 참조
	out->hi = Str2Int(data->hi, sizeof(data->hi));	// 고가, 단위:원 ※개발가이드 참조
	out->low = Str2Int(data->low, sizeof(data->low));	// 저가, 단위:원 ※개발가이드 참조
	out->cum_ccls_qty = Str2Dbl(data->cum_ccls_qty, sizeof(data->cum_ccls_qty), 0);	// 누적체결수량, 단위:주 ※보드ID별로 누적됨
	out->cum_trd_val = Str2Dbl(data->cum_trd_val, sizeof(data->cum_trd_val), 0);	// 누적거래대금, 단위:주 ※보드ID별로 누적됨
	out->fin_bid_ask_clsf_code = data->fin_bid_ask_clsf_code[0];	//최종매도매수구분코드, 1:매도 2:매수
	out->mtc_flg = data->mtc_flg[0];	//체결가와1호가일치여부, 0:판단불가 1:일치 2:불일치
	memcpy(out->ccls_time, data->ccls_time, sizeof(data->ccls_time));	// 체결시각, HHMMSS
	out->lp_hld_qty = Str2Dbl(data->lp_hld_qty, sizeof(data->lp_hld_qty), 0);	// LP보유수량, LP(체결기준) 집계후 LP보유수량
	out->ask_1_prc = Str2Int(data->ask_1_prc, sizeof(data->ask_1_prc));	// 매도1호가, 단위:원 ※개발가이드 참조
	out->bid_1_prc = Str2Int(data->bid_1_prc, sizeof(data->bid_1_prc));	// 매수1호가, 단위:원 ※개발가이드 참조

	return 1;
}


// 코스닥_기준가결정
int ParseA4012(const double& timestamp, const char* in_buff, DF_KOSDAQ_BASE_PRC_DCS* out) {
	KOSDAQ_BASE_PRC_DCS* data = (KOSDAQ_BASE_PRC_DCS*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA구분, A4
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// 정보구분, 01:주식
	out->mkt_clsf = data->mkt_clsf[0];	//시장구분, 1:유가증권 2:코스닥
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// 종목코드, 표준코드
	out->snr = Str2Int(data->snr, sizeof(data->snr));	// 종목일련번호, 종목배치(A0)의 종목SEQ
	memcpy(out->brd_id, data->brd_id, sizeof(data->brd_id));	// 보드ID, ※ 코드값모음 참조
	out->base_prc = Str2Int(data->base_prc, sizeof(data->base_prc));	// 기준가격, 단위:원
	out->base_prc_ceil = Str2Int(data->base_prc_ceil, sizeof(data->base_prc_ceil));	// 기준가격상한가, 단위:원
	out->base_prc_flr = Str2Int(data->base_prc_flr, sizeof(data->base_prc_flr));	// 기준가격하한가, 단위:원

	return 1;
}


// 코스닥_종목마감
int ParseA6012(const double& timestamp, const char* in_buff, DF_KOSDAQ_STK_CLSG* out) {
	KOSDAQ_STK_CLSG* data = (KOSDAQ_STK_CLSG*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA구분, A6
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// 정보구분, 01:주식 02:ELW
	out->mkt_clsf = data->mkt_clsf[0];	//시장구분, 1:유가증권 2:코스닥
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// 종목코드, 표준코드
	out->snr = Str2Int(data->snr, sizeof(data->snr));	// 종목일련번호, 종목배치(A0)의 종목SEQ
	memcpy(out->brd_id, data->brd_id, sizeof(data->brd_id));	// 보드ID, ※ 코드값모음 참조
	out->stk_cls_prc = Str2Int(data->stk_cls_prc, sizeof(data->stk_cls_prc));	// 종목마감종가, 정규시간외구분코드가 1:정규장일때만 종목마감가격구분코드값이 SET 됨. 그 외에는 SPACE
	out->stk_cls_prc_clsf_code = data->stk_cls_prc_clsf_code[0];	//종목마감가격구분코드, 1 체결가격 2 기세 3 거래무 4 시가기준가종목의 기세, 정규장이 아닌 경우 SPACE
	out->ofhr_ceil = Str2Int(data->ofhr_ceil, sizeof(data->ofhr_ceil));	// 종목마감시간외단일가상한가
	out->ofhr_flr = Str2Int(data->ofhr_flr, sizeof(data->ofhr_flr));	// 종목마감시간외단일가하한가
	out->stk_cls_mwprc = Str2Int(data->stk_cls_mwprc, sizeof(data->stk_cls_mwprc));	// 종목마감평균가중주가
	out->dlv_base_prc = Str2Int(data->dlv_base_prc, sizeof(data->dlv_base_prc));	// 매입인도기준가격
	out->dlv_ceil = Str2Int(data->dlv_ceil, sizeof(data->dlv_ceil));	// 매입인도상한가
	out->dlv_flr = Str2Int(data->dlv_flr, sizeof(data->dlv_flr));	// 매입인도하한가

	return 1;
}


// 코스닥_장운영TS
int ParseA7012(const double& timestamp, const char* in_buff, DF_KOSDAQ_MKT_OPR_TS* out) {
	KOSDAQ_MKT_OPR_TS* data = (KOSDAQ_MKT_OPR_TS*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA구분, A7
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// 정보구분, 01:주식 02:ELW
	out->mkt_clsf = data->mkt_clsf[0];	//시장구분, 1:유가증권 2:코스닥
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// 종목코드, 표준코드
	out->stk_snr = Str2Int(data->stk_snr, sizeof(data->stk_snr));	// 종목일련번호, 종목배치(A0)의 종목일련번호
	memcpy(out->brd_id, data->brd_id, sizeof(data->brd_id));	// 보드ID, ※ 코드값모음 참조
	memcpy(out->brd_evt_id, data->brd_evt_id, sizeof(data->brd_evt_id));	// 보드이벤트ID, ※ 코드값모음 참조
	memcpy(out->brd_evt_st, data->brd_evt_st, sizeof(data->brd_evt_st));	// 보드이벤트시작시각
	out->brd_evt_code = Str2Int(data->brd_evt_code, sizeof(data->brd_evt_code));	// 보드이벤트적용군코드, ※ 코드값모음 참조
	memcpy(out->sess_id, data->sess_id, sizeof(data->sess_id));	// 세션ID, ※ 코드값모음 참조
	memcpy(out->trsp_rsn_code, data->trsp_rsn_code, sizeof(data->trsp_rsn_code));	// 거래정지사유코드, ※ 코드값모음 참조

	return 1;
}


// 코스닥_배분정보
int ParseO6012(const double& timestamp, const char* in_buff, DF_KOSDAQ_ALLC_INFO* out) {
	KOSDAQ_ALLC_INFO* data = (KOSDAQ_ALLC_INFO*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA구분, O6
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// 정보구분, 01:주식
	out->mkt_clsf = data->mkt_clsf[0];	//시장구분, 1:유가증권, 2:코스닥,
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// 종목코드, 표준코드
	out->stk_snr = Str2Int(data->stk_snr, sizeof(data->stk_snr));	// 종목일련번호, 종목배치(A0)의 종목일련번호
	memcpy(out->brd_id, data->brd_id, sizeof(data->brd_id));	// 보드ID, ※ 코드값모음 참조
	out->allc_apl_clsf_code = data->allc_apl_clsf_code[0];	//배분적용구분코드, 1 배분개시 2 배분해제
	out->allc_proc_clsf_code = Str2Int(data->allc_proc_clsf_code, sizeof(data->allc_proc_clsf_code));	// 배분처리구분코드, 1 매수상한,2 매수하한,3 매도상한,4 매도하한   ※ 배분처리구분코드는 배분개시에만 전송하고 해제시 ' ' 전송
	out->allc_cncl_time = Str2Int(data->allc_cncl_time, sizeof(data->allc_cncl_time));	// 배분해제시각, HHMMSS

	return 1;
}


// 코스닥_종목배치
int ParseA0012(const double& timestamp, const char* in_buff, DF_KOSDAQ_STK_ARNG* out) {
	KOSDAQ_STK_ARNG* data = (KOSDAQ_STK_ARNG*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA구분, A0
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// 정보구분, 01:주식
	out->mkt_clsf = data->mkt_clsf[0];	//시장구분, 1:유가증권 2:코스닥
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// 종목코드, 표준코드
	out->snr = Str2Int(data->snr, sizeof(data->snr));	// 일련번호, 1~99999999 건수체크용
	memcpy(out->sh_code, data->sh_code, sizeof(data->sh_code));	// 단축코드, 주식7자리(DR포함) 수익증권9자리
	memcpy(out->kor_abbr, data->kor_abbr, sizeof(data->kor_abbr));	// 종목한글약명
	memcpy(out->eng_abbr, data->eng_abbr, sizeof(data->eng_abbr));	// 종목영문약명
	memcpy(out->opr_date, data->opr_date, sizeof(data->opr_date));	// 영업일자, YYYYMMDD
	memcpy(out->info_allc_nr, data->info_allc_nr, sizeof(data->info_allc_nr));	// 정보분배그룹번호
	memcpy(out->stk_gr_id, data->stk_gr_id, sizeof(data->stk_gr_id));	// 증권그룹ID, ST:주권 MF:증권투자회사 RT:부동산투자회사 SC:선박투자회사\nIF:사회간접자본투융자회사 DR:주식예탁증서 EW:ELW EF:ETF\nSW:신주인수권증권 SR:신주인수권증서 BC:수익증권 \nFE:해외ETF FS:외국주권\nEN:ETN 2014.11.17
	out->unit_trd_ccls_flg = data->unit_trd_ccls_flg[0];	//단위매매체결여부, Y, N (정규장에서 일정시간 단위체결여부)
	memcpy(out->lock_clsf_code, data->lock_clsf_code, sizeof(data->lock_clsf_code));	// 락구분코드, 00:해당사항없음(락이 발생안한 경우) \n01:권리락 \n02:배당락\n03:분배락 \n04:권배락 \n05:중간(분기)배당락\n(2017.11.20 변경:중간배당락->중간(분기)배당락)\n06:권리중간배당락\n07:권리분기배당락\n(2017.11.20 추가)\n99:기타  ※SW,SR,EW는 미해당(미해당의 경우 SPACE)
	memcpy(out->pval_chg_clsf_code, data->pval_chg_clsf_code, sizeof(data->pval_chg_clsf_code));	// 액면가변경구분코드, 00:해당없음(액면가변경이 취해질 수 있는 종목군에 대해 변경\n없음을 의미) 01:액면분할 02:액면병합 03:주식분할 04:주식병합 99:기타\n(2012.08.27)
	out->open_base_prc_stk_flg = data->open_base_prc_stk_flg[0];	//시가기준가격종목여부, Y, N ※Y인 경우:신규종목,기업분할,무상감자,장기간거래정지
	memcpy(out->rassm_stk_rsn_code, data->rassm_stk_rsn_code, sizeof(data->rassm_stk_rsn_code));	// 재평가종목사유코드, 00:해당없음, 01:회사분할, 02:자본감소, 03:장기간정지,\n04:초과분배, 05:대규모배당 \n06: 회사분할합병, 99:기타  \n※증권그룹ID ST,FS에 해당(미해당의 경우 SPACE)\n2011.02.28 구분값 추가(04:초과분배, 05:대규모배당)\n2012.08.27 정의오류수정(02:주식병합->02:자본감소) \n2017.06.26 구분값 변경(01:기업분할 -> 01:회사분할)\n2017.06.26 구분값 추가(06:회사분할합병)
	out->base_prc_chg_stk_flg = data->base_prc_chg_stk_flg[0];	//기준가격변경종목여부, Y, N ※Y인 경우:모든락,액면변경,증자 등
	out->rndn_cls_trgg_cond_code = data->rndn_cls_trgg_cond_code[0];	//임의종료발동조건코드, 단일가세선에서 임의종료의 발동조건.조건부발동(2)인경우 임의종료규칙에서 정의하는 가격요건을 충족하는지 판단 후 발동을 결정함.\n##코드값##\n0:미발동  1:발동  2:조건부발동(가격요건판단)
	out->mkt_alm_warn_fcst_flg = data->mkt_alm_warn_fcst_flg[0];	//시장경보경고예고여부, Y, N\n\n2015.06.15 : "시장경보위험예고여부(Y,N)"->"시장경보경고예고여부(Y,N)" 항목변경
	memcpy(out->mkt_alrm_clsf_code, data->mkt_alrm_clsf_code, sizeof(data->mkt_alrm_clsf_code));	// 시장경보구분코드, 00:해당없음(시장경보가 지정될 수 있는 종목에 대해서 지정된\n바가 없음을 의미) 01:투자주의 02:투자경고 03:투자위험
	out->cogv_hlth_flg = data->cogv_hlth_flg[0];	//지배구조우량여부, Y, N ※코스닥만 해당, ST,FS,DR,MF,EF만 해당
	out->ifam_flg = data->ifam_flg[0];	//관리종목여부, Y, N
	out->iscnt_flg = data->iscnt_flg[0];	//불성실공시지정여부, Y, N
	out->bdlt_flg = data->bdlt_flg[0];	//우회상장여부, Y, N
	out->trsp_flg = data->trsp_flg[0];	//거래정지여부, Y, N
	memcpy(out->ind_lclsf_code, data->ind_lclsf_code, sizeof(data->ind_lclsf_code));	// 지수업종대분류코드, (유가)000:업종미분류  ※유가증권은 사용하지 않음\n(코스닥)000:업종미분류/뮤추얼펀드 008~014:일반 015:IT\n※증권그룹ID ST,MF,RT,SC,IF만 해당
	memcpy(out->ind_mclsf_code, data->ind_mclsf_code, sizeof(data->ind_mclsf_code));	// 지수업종중분류코드, (유가)000:업종미분류\n(코스닥)000:업종미분류 021~040:일반 041~043:IT\n※증권그룹ID ST,MF,RT,SC,IF만 해당
	memcpy(out->ind_sclsf_code, data->ind_sclsf_code, sizeof(data->ind_sclsf_code));	// 지수업종소분류코드, (유가)000:업종미분류\n(코스닥)000:업종미분류 050~112:일반 151~160:IT\n※증권그룹ID ST,MF,RT,SC,IF만 해당
	memcpy(out->ind_id, data->ind_id, sizeof(data->ind_id));	// 업종ID, 업종(Type Of Industry)ID 2014.03.03 \n*구명칭:표준산업코드 \n6자리 표준산업코드는 국내요건만 수용할 수 있어 해외사이트의 다양한 업종코드 수용이 불가하여 10자리로 확대. 현행 표준산업코드는 그대로 1:1 매핑되어 나머지 4자리는 스페이스로 채움\n6->10 2014.03.03
	out->kospi200_str_ind = data->kospi200_str_ind[0];	//KOSPI200섹터업종, 해당사항없음 (2018.10.22 : 항목설명변경)
	out->mkt_cap_code = data->mkt_cap_code[0];	//시가총액규모코드, 유가(0:제외 1:대 2:중 3:소)\n코스닥(0:제외 1:KOSDAQ100 2:KOSDAQmid300 3:KOSDAQsmall)\n※증권그룹ID ST,MF,RT,SC,IF만 해당
	out->mnft_ind_flg = data->mnft_ind_flg[0];	//(유가)제조업여부 (코스닥)중소기업여부, Y, N\n※제조업여부는 ST,MF,RT,SC,IF만 해당(업종코드 027)\n※중소기업여부는 ST,FS,DR,EF만 해당
	out->krx100_flg = data->krx100_flg[0];	//KRX100종목여부, Y, N
	out->gvnm_idx_stk_flg = data->gvnm_idx_stk_flg[0];	//(유가)지배구조지수종목여부(코스닥) 소속부구분코드, (유가) Y, N\n(코스닥)소속부구분코드 ← 벤처기업여부  2011.05.02\n  1:우량기업부, 2:벤처기업부, 3:중견기업부, 4:신성장기업부,\n  A:외국기업, B:투자회사, C:SPAC, D:ETF E:관리종목,\n  F:투자주의환기종목, Z:기타   \n※ A~Z는 소속부 없음\n2012.09.14 (유가종목배치)   "지배구조지수종목여부" 1 Byte FILLER 처리\n(코스닥종목배치) "소속부구분코드" 계속 사용
	memcpy(out->inst_clsf_code, data->inst_clsf_code, sizeof(data->inst_clsf_code));	// 투자기구구분코드, 00:해당없음 01:증권간접투자기구 02:파생상품투자기구\n03:부동산간접투자기구 04:실물간접투자기구\n05:단기금융간접투자기구 06:재간접투자기구\n07:특별간접투자기구\n※증권그룹ID MF,IF,BC가 해당(미해당의 경우 SPACE)
	out->idx_stk_flg = data->idx_stk_flg[0];	//(유가)KOSPI지수종목여부 (코스닥)KOSDAQ지수종목여부, Y, N\n(유가)KOSPI여부-> (유가)KOSPI지수종목여부,(코스닥)KOSDAQ지수종목여부 2018.12.10
	out->kospi50_flg = data->kospi50_flg[0];	//(유가)KOSPI50여부, Y, N
	out->base_prc = Str2Int(data->base_prc, sizeof(data->base_prc));	// 기준가격
	out->prev_cls_clsf_code = data->prev_cls_clsf_code[0];	//전일종가구분코드, 1:실세 2:기세 3:거래무 4:시가기준가종목의 기세
	out->prev_cls_prc = Str2Int(data->prev_cls_prc, sizeof(data->prev_cls_prc));	// 전일종가
	out->prev_cum_ccls_qty = Str2Dbl(data->prev_cum_ccls_qty, sizeof(data->prev_cum_ccls_qty), 0);	// 전일누적체결수량
	out->prev_cum_trd_val = Str2Dbl(data->prev_cum_trd_val, sizeof(data->prev_cum_trd_val), 0);	// 전일누적거래대금
	out->ceil_prc = Str2Int(data->ceil_prc, sizeof(data->ceil_prc));	// 상한가
	out->flr_prc = Str2Int(data->flr_prc, sizeof(data->flr_prc));	// 하한가
	out->sub_prc = Str2Int(data->sub_prc, sizeof(data->sub_prc));	// 대용가격, ※ST,FS,DR,MF,RT,SC,IF,ET,FE,BC,EN 만 해당 2014.11.17
	out->par_val = Str2Dbl(data->par_val, sizeof(data->par_val), 3);	// 액면가, 9(9)V9(3) 외국주권일 경우 소숫점셋째자리까지 표현가능\n코스닥의 각국의 최소화폐단위 표시는 유가기준으로 통일\n※ST,FS,RT,SC,BC만 해당
	out->issue_prc = Str2Int(data->issue_prc, sizeof(data->issue_prc));	// 발행가격, ELW, 신주인수권증서 포함
	memcpy(out->listd_date, data->listd_date, sizeof(data->listd_date));	// 상장일자, YYYYMMDD
	out->stk_listd = Str2Dbl(data->stk_listd, sizeof(data->stk_listd), 0);	// 상장주식수(상장증권수)
	out->arng_trd_flg = data->arng_trd_flg[0];	//정리매매여부, Y, N
	out->eps = Str2Int(data->eps, sizeof(data->eps));	// 주당순이익(EPS), 단위:원 ※증권그룹ID ST,MF,RT,IF,FS 가 해당
	out->per = Str2Int(data->per, sizeof(data->per));	// 주가수익율(PER), 9(4)V9(2) ※증권그룹ID ST,MF,RT,IF,FS 가 해당
	out->eps_cmpt_xclu_flg = data->eps_cmpt_xclu_flg[0];	//주당순이익산출제외여부, Y:산출제외 N:산출\n※값이 0, 관리종목, 감사의견이 적정 또는 한정 인 경우
	out->bps = Str2Int(data->bps, sizeof(data->bps));	// 주당순자산가치(BPS), 단위:원 ※증권그룹ID ST,MF,RT,IF,FS 가 해당
	out->pbr = Str2Int(data->pbr, sizeof(data->pbr));	// 주당순자산비율(PBR), 9(4)V9(2) ※증권그룹ID ST,MF,RT,IF,FS 가 해당
	out->bps_cmpt_xclu_flg = data->bps_cmpt_xclu_flg[0];	//"주당순자산가치산출 제외여부", Y:산출제외 N:산출\n※값이 0, 관리종목, 감사의견이 적정 또는 한정인 경우
	out->loss_flg = data->loss_flg[0];	//결손여부, Y, N
	out->dps = Str2Int(data->dps, sizeof(data->dps));	// 주당배당금액, 주당배당금
	out->dps_cmpt_xclu_flg = data->dps_cmpt_xclu_flg[0];	//"주당배당금액산출제외여부", Y:산출제외 N:산출\n※값이 0, 관리종목, 감사의견이 적정 또는 한정인 경우
	out->dyr = Str2Int(data->dyr, sizeof(data->dyr));	// 배당수익율, 9(6)V9(1)
	memcpy(out->xist_open_date, data->xist_open_date, sizeof(data->xist_open_date));	// 존립개시일자, ※증권그룹ID MF,RT,SC,IF,BC 해당.
	memcpy(out->xist_cls_date, data->xist_cls_date, sizeof(data->xist_cls_date));	// 존립종료일자, ※증권그룹ID MF,RT,SC,IF,BC 해당. ST,FS,DR은 우선주만 해당
	memcpy(out->exc_prd_open_date, data->exc_prd_open_date, sizeof(data->exc_prd_open_date));	// 행사기간개시일자, ※증권그룹ID SW, EW 이 해당됨
	memcpy(out->exc_prd_cls_date, data->exc_prd_cls_date, sizeof(data->exc_prd_cls_date));	// "행사기간종료일자 (권리행사기간만료일자)", ※증권그룹ID SW, EW 이 해당됨
	out->elw_wrnt_exc_prc = Str2Dbl(data->elw_wrnt_exc_prc, sizeof(data->elw_wrnt_exc_prc), 3);	// "ELW신주인수권증권  행사가격", 9(9)V9(3) ELW 또는 신주인수권증권의 행사가격
	out->euity = Str2Dbl(data->euity, sizeof(data->euity), 3);	// 자본금, 9(18)V9(3) 해외원주일 경우 소숫점셋째자리까지 표현가능\n액면가*상장주식수, 이익소각에 대한 부분은 차감함\nMF는 입력값\n※ST,FS,MF,RT,SC,IF,BC만 해당
	out->credit_ordbl_flg = data->credit_ordbl_flg[0];	//신용주문가능여부, Y, N
	out->limt_prc_cond_clsf_code = Str2Int(data->limt_prc_cond_clsf_code, sizeof(data->limt_prc_cond_clsf_code));	// 지정가호가조건구분코드, X ->9 모드변경, 1->5 길이변경\n호가의 체결 및 잔류조건, Bitwise 정의(*개발가이드 참조) \n#코드값# \n1:FAS(Fill And Store) \n2:FOK(Fill Or Kill) \n4:FAK(Fill And Kill) \n*전량조건(FOK, Fill or Kill):주문전달 즉시 전량 체결되지 않으면 모든 주문이 자동 취소되는 주문 \n*당일조건(FAS, Fill and Store):주문전달 즉시 체결가능 수량은 체결하고 미체결잔량은 당일 장중동안 주문장에 체결 대기시키되, 장종료 후의 미체결 주문은 모두 최소됨
	out->mkt_prc_cond_clsf_code = Str2Int(data->mkt_prc_cond_clsf_code, sizeof(data->mkt_prc_cond_clsf_code));	// 시장가호가조건구분코드, *상동
	out->cond_prc_cond_clsf_code = Str2Int(data->cond_prc_cond_clsf_code, sizeof(data->cond_prc_cond_clsf_code));	// 조건부지정가호가조건구분코드, *상동
	out->fvr_lmt_ord_cond_clsf_code = Str2Int(data->fvr_lmt_ord_cond_clsf_code, sizeof(data->fvr_lmt_ord_cond_clsf_code));	// 최유리지정가호가조건구분코드, *상동
	out->pfr_lmt_ord_cond_clsf_code = Str2Int(data->pfr_lmt_ord_cond_clsf_code, sizeof(data->pfr_lmt_ord_cond_clsf_code));	// 최우선지정가호가조건구분코드, *상동
	memcpy(out->cap_inc_clsf_code, data->cap_inc_clsf_code, sizeof(data->cap_inc_clsf_code));	// 증자구분코드, 00:해당없음 01:유상증자 02:무상증자 03:유무상증자 99:기타
	out->scrt_clsf_code = data->scrt_clsf_code[0];	//종류주권구분코드, 0:해당없음(보통주) 1:구형우선주 2:신형우선주 9:종류주권(2012.07.23)\n※증권그룹ID ST에만 해당\n※구명칭:우선주구분코드 2014.03.03
	out->pbl_scrt_flg = data->pbl_scrt_flg[0];	//국민주여부, Y, N ※유가증권만 해당
	out->asmt_prc = Str2Int(data->asmt_prc, sizeof(data->asmt_prc));	// 평가가격
	out->min_ask_prc = Str2Int(data->min_ask_prc, sizeof(data->min_ask_prc));	// 최저호가가격
	out->max_ask_prc = Str2Int(data->max_ask_prc, sizeof(data->max_ask_prc));	// 최고호가가격
	out->opr_time_trd_qty_unit = Str2Int(data->opr_time_trd_qty_unit, sizeof(data->opr_time_trd_qty_unit));	// 정규장매매수량단위, 1주단위:1 10:10주단위 100:100주단위 1000:1000주단위
	out->ofhr_trd_qty_unit = Str2Int(data->ofhr_trd_qty_unit, sizeof(data->ofhr_trd_qty_unit));	// 시간외매매수량단위, 1주단위:1 10:10주단위 100:100주단위 1000:1000주단위\n※BC,SW,SR,EW는 제외
	out->ritz_code = data->ritz_code[0];	//리츠종류코드, 1:일반리츠 2:CRV리츠
	memcpy(out->obj_scrt_code, data->obj_scrt_code, sizeof(data->obj_scrt_code));	// 목적주권종목코드, ※SW,SR만 해당
	memcpy(out->crny_iso_code, data->crny_iso_code, sizeof(data->crny_iso_code));	// 통화ISO코드, AUD:호주달러 EUR:유로 GBP:영국파운드 HKD:홍콩달러 등\n※코드값모음-통화ISO코드 참조
	memcpy(out->nt_code, data->nt_code, sizeof(data->nt_code));	// 국가코드, ISO 3166 코드중 3자리 숫자 ※별도 코드표 참조\n※전체 증권그룹ID에 해당
	out->mkt_crt_flg = data->mkt_crt_flg[0];	//시장조성가능여부, Y, N
	out->ofhr_trd_flg = data->ofhr_trd_flg[0];	//시간외매매가능여부, Y, N
	out->preord_cls_flg = data->preord_cls_flg[0];	//"장개시전시간외종가 가능여부", Y, N
	out->preord_msv_trd_flg = data->preord_msv_trd_flg[0];	//"장개시전시간외대량 매매가능 여부", Y, N
	out->preord_bsk_flg = data->preord_bsk_flg[0];	//"장개시전시간외바스켓 가능 여부", Y, N
	out->fcst_ccls_flg = data->fcst_ccls_flg[0];	//예상체결가공개여부, Y, N
	out->short_flg = data->short_flg[0];	//공매도가능여부, Y, N 가격제한이 있거나 없는 공매도의 호가가능여부
	out->trkg_prf_mtp = Str2SignDouble(data->trkg_prf_mtp_sign, sizeof(data->trkg_prf_mtp_sign) + sizeof(data->trkg_prf_mtp), 6);	// 추적수익율배수, ※증권그룹ID EF,FE,EN 해당 2014.11.17\n※항목명변경 2014.11.17\n\n9(5)V9(6)  지수 또는 가격 변동 대비 ETF 가격 변동 배수\n예) 레버리지 2배일 경우 '00002000000'   2009.07.27
	out->regulation_apl_flg = data->regulation_apl_flg[0];	//"Regulation S 적용 종목여부", Y, N							 2010.02.01
	out->spc_flg = data->spc_flg[0];	//기업인수목적회사여부, Y, N							 2010.03.02
	out->tax_type_code = data->tax_type_code[0];	//과세유형코드, 0:해당없음, \n1:"증권거래세"->"비과세" 코드값명 변경   2016.02.29, \n2:배당소득세(보유기간과세), \n3:증권거래세(회사형ETF)				2011.05.02\n4:"배당소득세(해외주식투자전용ETF)" 코드값 추가   2016.02.29\n(BIG33은 FILLER임)
	out->sbst_prc_rate = Str2Dbl(data->sbst_prc_rate, sizeof(data->sbst_prc_rate), 6);	// 대용가격사정비율, 99999V999999 2010.06.28 \n(BIG33은 FILLER임) \n※Exture에서는 대용가가 0이면 사정비율이 0이었으나, Exture+에서는 대용가가 0이어도 사정비율 제공 2014.03.03
	out->inv_xctm_stk_flg = data->inv_xctm_stk_flg[0];	//(코스닥)투자주의환기종목여부, (코스닥) Y,N 관리종목 또는 상장폐지로 악화될 우려가 있는\n	  부실 위험징후 기업 여부 (2011.05.02 추가)\n(BIG33은 FILLER임)
	memcpy(out->dlstg_date, data->dlstg_date, sizeof(data->dlstg_date));	// 상장폐지일자, YYYYMMDD ※증권그룹ID SR 만 해당, 다른 증권그룹ID는 FILLER처리  2011.06.27 추가\n(BIG33은 FILLER임)
	out->short_term_oh_clsf_code = data->short_term_oh_clsf_code[0];	//단기과열종목구분코드, 0: 해당없음\n1: 지정예고\n2: 지정\n3: 지정연장(해제연기)\n2012.11.05 추가
	out->etf_cpy_clsf_code = data->etf_cpy_clsf_code[0];	//ETF복제방법구분코드, ETF의 기초자산 복제방법구분코드 2013.03.18 추가P:실물복제S:합성복제 A:Active (2015.11.23 구분코드추가)
	out->kospi200_hi_divd_idx_flg = data->kospi200_hi_divd_idx_flg[0];	//KOSPI200고배당지수여부, Y,N\n2013.11.18
	out->kospi200_lo_vol_idx_flg = data->kospi200_lo_vol_idx_flg[0];	//KOSPI200저변동성지수여부, Y,N\n2013.11.18
	memcpy(out->mtr_date, data->mtr_date, sizeof(data->mtr_date));	// 만기일자, 2014.11.17
	memcpy(out->divd_type_code, data->divd_type_code, sizeof(data->divd_type_code));	// 분배금형태코드, 분배금형태에 따른 구분코드 2014.11.17 \n01:미지급 \n02:지급(지표가치 반영) \n03:지급(지표가치 미반영) \n04:지급(재투자) \n05:지급(기타)
	memcpy(out->mtr_rdmp_prc_st_date, data->mtr_rdmp_prc_st_date, sizeof(data->mtr_rdmp_prc_st_date));	// 만기상환가격결정시작일자, 2014.11.17
	memcpy(out->mtr_rdmp_prc_ed_date, data->mtr_rdmp_prc_ed_date, sizeof(data->mtr_rdmp_prc_ed_date));	// 만기상환가격결정종료일자, 2014.11.17
	out->etp_mcdz_clsf_code = data->etp_mcdz_clsf_code[0];	//ETP상품구분코드, (2015.11.23 추가)\n ETP상품구분코드\n ## 코드값 ##\n1. ETF(투자회사형)\n2. ETF(수익증권형)\n3. ETN\n4. 손실제한 ETN\n(2017.03.27:ELS형 ETN->손실제한 ETN)
	out->idx_cmpt_inst_code = data->idx_cmpt_inst_code[0];	//지수산출기관코드, (2015.11.23 추가)\n*코드값모음 참조(KRX 정의)
	memcpy(out->idx_mkt_clsf_id, data->idx_mkt_clsf_id, sizeof(data->idx_mkt_clsf_id));	// 지수시장분류ID, (2015.11.23 추가)\n *대분류(2)+중분류(2)+소분류(2)\n 값이 생략되는 분류의 자리는 '00'을 표기\n중,소분류 지정시 상위 분류의 값은 생략 할 수 없음
	memcpy(out->idx_snr, data->idx_snr, sizeof(data->idx_snr));	// 지수일련번호, (2015.11.23 추가)지수일련번호
	memcpy(out->trkg_idx_lvrg_invs_clsf_code, data->trkg_idx_lvrg_invs_clsf_code, sizeof(data->trkg_idx_lvrg_invs_clsf_code));	// 추적지수레버리지인버스구분코드, (2015.11.23 추가)\n## 코드값 ##\n P1:일반(1)\n P2:2X 레버리지(2)\n N1:1X 인버스(-1)\n N2:2X 인버스(-2)
	memcpy(out->ref_idx_lvrg_invs_clsf_code, data->ref_idx_lvrg_invs_clsf_code, sizeof(data->ref_idx_lvrg_invs_clsf_code));	// 참고지수레버리지인버스구분코드, (2015.11.23 추가)\n## 코드값 ##\n P1:일반(1)\n P2:2X 레버리지(2)\n N1:1X 인버스(-1)\n N2:2X 인버스(-2)
	memcpy(out->idx_ast_clsf_id1, data->idx_ast_clsf_id1, sizeof(data->idx_ast_clsf_id1));	// 지수자산분류ID1, (2015.11.23 추가)\n *대분류(2)+중분류(2)+소분류(2)\n 값이 생략되는 분류의 자리는 '00'을 표기\n중,소분류 지정시 상위 분류의 값은 생략 할 수 없음
	memcpy(out->idx_ast_clsf_id2, data->idx_ast_clsf_id2, sizeof(data->idx_ast_clsf_id2));	// 지수자산분류ID2, (2015.11.23 추가)\n *대분류(2)+중분류(2)+소분류(2)\n 값이 생략되는 분류의 자리는 '00'을 표기\n중,소분류 지정시 상위 분류의 값은 생략 할 수 없음
	out->lp_odrbl_flg = data->lp_odrbl_flg[0];	//LP주문가능여부, (2015.11.23 추가) Y,N
	out->kosdaq150_idx_stk_flg = data->kosdaq150_idx_stk_flg[0];	//KOSDAQ150지수종목여부, (2015.11.23 추가)\nY,N
	out->lo_vol_flg = data->lo_vol_flg[0];	//저유동성여부, (2016.06.27 추가)\nY,N
	out->abnm_risg_flg = data->abnm_risg_flg[0];	//이상급등여부, (2017.03.27 추가) \nY,N
	out->krx300_idx_flg = data->krx300_idx_flg[0];	//KRX300지수여부, (2018.03.26 추가)\nY,N
	out->qty_ceil = Str2Dbl(data->qty_ceil, sizeof(data->qty_ceil), 0);	// 상한수량, (2018.09.17 추가)상한수량을 초과시 호가는 거부처리 필요.

	return 1;
}


// 코스닥_결산일 정보
int ParseI5012(const double& timestamp, const char* in_buff, DF_KOSDAQ_STGD_INFO* out) {
	KOSDAQ_STGD_INFO* data = (KOSDAQ_STGD_INFO*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA구분, I5
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// 정보구분, 01:주식
	out->mkt_clsf = data->mkt_clsf[0];	//시장구분, 1:유가증권 2:코스닥
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// 종목코드, 표준코드
	out->snr = Str2Int(data->snr, sizeof(data->snr));	// 일련번호, 1~99999999 건수체크용
	memcpy(out->clsg_date, data->clsg_date, sizeof(data->clsg_date));	// 결산월일, 1~99999999 건수체크용

	return 1;
}


// 코스닥_종목 이벤트 정보
int ParseI6012(const double& timestamp, const char* in_buff, DF_KOSDAQ_STK_EVT_INFO* out) {
	KOSDAQ_STK_EVT_INFO* data = (KOSDAQ_STK_EVT_INFO*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA구분, I6
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// 정보구분, 01:주식
	out->mkt_clsf = data->mkt_clsf[0];	//시장구분, 1:유가증권 2:코스닥
	memcpy(out-> isin_code, data-> isin_code, sizeof(data-> isin_code));	// 종목코드, 표준코드
	out->snr = Str2Int(data->snr, sizeof(data->snr));	// 일련번호, 1~99999999 건수체크용
	memcpy(out->evt_code, data->evt_code, sizeof(data->evt_code));	// 이벤트종류코드, 01:거래정지 \n02:관리종목 \n03:불성실공시법인 \n04:정리매매\n05:우회상장 \n06:대용증권효력정지 \n07:지배구조우량기업\n08:차입공매도불가 \n09:Regulation S \n10:벤쳐기업지정\n11:투자주의환기종목\n12:단기과열종목 (2012.11.05 추가)\n13:휴장 (2016.06.27추가)\n14:초저유동성종목 (2016.06.27추가)\n15:투자유의채권 (2016.11.28추가)\n16:이상급등종목 (2017.03.27추가)\n17:공매도과열종목 (2017.03.27 추가)\n18: LP선택제 (2017.06.26 추가)
	memcpy(out->evt_trgg_code, data->evt_trgg_code, sizeof(data->evt_trgg_code));	// 이벤트발생사유코드, ※ 별첨 코드갑모음의 이벤트별사유코드 참조\n※ 이벤트종류코드 03,04,07,08,09,17 에 대해서는 '0000' SET\n※ 코드의 종류에 따라 자릿수가 다릅니다. 데이터 타입이\nX모드 이기 때문에 죄측정렬됩니다. 이점 유의하여 주십시요.\n(거래정지사유코드(3자리), 관리종목지정사유코드(4자리),\n우회상장유형코드(1자리), 대용증권효력정지사유코드(2자리),\n투자주의환기종목사유코드(4자리))
	memcpy(out->st_date, data->st_date, sizeof(data->st_date));	// "개시일자,시작일자, 적용일자", YYYYMMDD
	memcpy(out->ed_date, data->ed_date, sizeof(data->ed_date));	// 만료일자,종료일자, YYYYMMDD

	return 1;
}


// 코스닥_LP 정보
int ParseI7012(const double& timestamp, const char* in_buff, DF_KOSDAQ_LP_INFO* out) {
	KOSDAQ_LP_INFO* data = (KOSDAQ_LP_INFO*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA구분, I7
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// 정보구분, 01:주식
	out->mkt_clsf = data->mkt_clsf[0];	//시장구분, 1:유가증권 2:코스닥
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// 종목코드, 표준코드
	out->snr = Str2Int(data->snr, sizeof(data->snr));	// 일련번호, 1~99999999 건수체크용
	memcpy(out->mkt_ptcp_nr, data->mkt_ptcp_nr, sizeof(data->mkt_ptcp_nr));	// 시장참가자번호, 시장참가자를 식별/구분할 수 있는 번호\n한 시장참가자가 여러 거래소의 회원이면 거래소별로\n시장참가자번호를 달리함  예) '00001'
	memcpy(out->lp_open_date, data->lp_open_date, sizeof(data->lp_open_date));	// LP개시일자, 유동성공급개시일자
	memcpy(out->lp_cls_date, data->lp_cls_date, sizeof(data->lp_cls_date));	// LP종료일자, 유동성공급종료일자
	out->min_ask_qty_mtp = Str2Dbl(data->min_ask_qty_mtp, sizeof(data->min_ask_qty_mtp), 0);	// 최소호가수량배수, LP/MM 호가시 매매수량단위의 최소배수\n예) 값이 10이고 매매수량단위가 10주(계약)이면\nLP/MM 호가는 100주(계약) 이상으로 호가해야함
	out->max_ask_qty_mtp = Str2Dbl(data->max_ask_qty_mtp, sizeof(data->max_ask_qty_mtp), 0);	// 최대호가수량배수, LP/MM 호가시 매매수량단위의 최대배수
	out->ask_prc_sprd_unit_code = data->ask_prc_sprd_unit_code[0];	//호가스프레드단위코드, R:가격비율\nY:수익률비율(채권)\nT:호가가격단위 배수\nA:절대값 (채권)\n*구명칭:제한단위구분코드 2014.03.03
	out->ask_prc_sprd_val = Str2Dbl(data->ask_prc_sprd_val, sizeof(data->ask_prc_sprd_val), 8);	// 호가스프레드값, LP/MM 호가 제출할 의무가 발생하는 최우선호가스프레드\n간격 또는 비율  9(13)V9(8)
	out->off_mkt_ask_sprd_mtp = Str2Dbl(data->off_mkt_ask_sprd_mtp, sizeof(data->off_mkt_ask_sprd_mtp), 0);	// 휴장호가스프레드배수, 파생,ELW,ETF의 기초자산이 해외시장의 지수 또는 종목인 경우 해당 시장이 휴일, 장개시전, 장종류후, 휴장 등의 사유로 추적자산의 현재 가치를 판단할 수 없을 때 시장 조성 계약별로 약정한 스프레드 보다 확대된 스프레드를 허용하기 위한 배수 \n*구명칭:휴장호가스프레드값 \n구 휴장호가스프레드값 = 휴장호가스프레드배수 * 호가스프레드값 \n(Exture에서 휴장호가스프레드값이 0인경우 Exture+에서는 호가스프레드값과 일치시킴) 2014.03.03
	out->obgt_ask_sbmt_time_invl = Str2Int(data->obgt_ask_sbmt_time_invl, sizeof(data->obgt_ask_sbmt_time_invl));	// 의무호가제출시간간격, 단위:초(sec) \n00초 이내에 최우선호가간격을 축소시키는 매도호가 또는 매수호가를 제출 2014.03.03
	out->ask_min_ask_prc_amt = Str2Dbl(data->ask_min_ask_prc_amt, sizeof(data->ask_min_ask_prc_amt), 3);	// 매도최소호가금액, 9(18)V9(3)						   2009.07.27
	out->bid_min_ask_prc_amt = Str2Dbl(data->bid_min_ask_prc_amt, sizeof(data->bid_min_ask_prc_amt), 3);	// 매수최소호가금액, 9(18)V9(3)						   2009.07.27
	out->min_ask_amt = Str2Dbl(data->min_ask_amt, sizeof(data->min_ask_amt), 3);	// 최소호가금액, 9(18)V9(3) (2015.11.23 추가)\nMM(시장조성자)호가의 최소금액\n※LP최소호가수량배수와 배타적으로 사용, LP최소호가수량배수에 값이 설정된 경우 해당 필드는 무시
	out->max_ask_amt = Str2Dbl(data->max_ask_amt, sizeof(data->max_ask_amt), 3);	// 최대호가금액, 9(18)V9(3) (2015.11.23 추가) \n최대호가금액

	return 1;
}


// 코스닥_대량체결
int ParseC4012(const double& timestamp, const char* in_buff, DF_KOSDAQ_MSV_CCLS* out) {
	KOSDAQ_MSV_CCLS* data = (KOSDAQ_MSV_CCLS*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA구분, C4
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// 정보구분, 01:주식
	out->mkt_clsf = data->mkt_clsf[0];	//시장구분, 1:유가증권 2:코스닥
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// 종목코드, 표준코드
	out->stk_snr = Str2Int(data->stk_snr, sizeof(data->stk_snr));	// 종목일련번호, 종목배치(A0)의 종목일련번호
	out->snr = Str2Int(data->snr, sizeof(data->snr));	// 일련번호, 1~99999999 건수체크용
	out->bopen_rel_msv_ccls_qty = Str2Int(data->bopen_rel_msv_ccls_qty, sizeof(data->bopen_rel_msv_ccls_qty));	// 장개시전시간외상대대량체결수량, 단위:주
	out->bopen_bsk_ccls_qty = Str2Int(data->bopen_bsk_ccls_qty, sizeof(data->bopen_bsk_ccls_qty));	// 장개시전시간외바스켓체결수량, 단위:주
	out->bopen_cmpt_msv_ccls_qty = Str2Int(data->bopen_cmpt_msv_ccls_qty, sizeof(data->bopen_cmpt_msv_ccls_qty));	// 장개시전시간외경쟁대량체결수량, 단위:주
	out->rel_msv_ccls_qty = Str2Int(data->rel_msv_ccls_qty, sizeof(data->rel_msv_ccls_qty));	// 장중상대대량체결수량, 단위:주
	out->bsk_ccls_qty = Str2Int(data->bsk_ccls_qty, sizeof(data->bsk_ccls_qty));	// 장중바스켓체결수량, 단위:주
	out->cmpt_msv_ccls_qty = Str2Int(data->cmpt_msv_ccls_qty, sizeof(data->cmpt_msv_ccls_qty));	// 장중경쟁대량체결수량, 단위:주
	out->ofhr_rel_msv_ccls_qty = Str2Int(data->ofhr_rel_msv_ccls_qty, sizeof(data->ofhr_rel_msv_ccls_qty));	// 장종료후시간외상대대량체결수량, 단위:주
	out->ofhr_bsk_ccls_qty = Str2Int(data->ofhr_bsk_ccls_qty, sizeof(data->ofhr_bsk_ccls_qty));	// 장종료후시간외바스켓체결수량, 단위:주

	return 1;
}


// 코스닥_주식종목정보공개
int ParseA8012(const double& timestamp, const char* in_buff, DF_KOSDAQ_STK_INFO_DCLS* out) {
	KOSDAQ_STK_INFO_DCLS* data = (KOSDAQ_STK_INFO_DCLS*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA구분, A8
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// 정보구분, 01:주식
	out->mkt_clsf = data->mkt_clsf[0];	//시장구분, 1:유가증권 2:코스닥
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// 종목코드
	out->stk_snr = Str2Int(data->stk_snr, sizeof(data->stk_snr));	// 종목일련번호, 종목배치(A0)의 종목일련번호
	memcpy(out->open_info_clsf_code, data->open_info_clsf_code, sizeof(data->open_info_clsf_code));	// 공개정보구분코드, ※ 코드값모음 참조
	memcpy(out->brd_id, data->brd_id, sizeof(data->brd_id));	// 보드ID, ※ 코드값모음 참조
	out->base_prc = Str2Int(data->base_prc, sizeof(data->base_prc));	// 기준가격
	out->ceil_prc = Str2Int(data->ceil_prc, sizeof(data->ceil_prc));	// 상한가, 가격제한폭이 없는 종목 '999999999'
	out->flr_prc = Str2Int(data->flr_prc, sizeof(data->flr_prc));	// 하한가, 가격제한폭이 없는 종목 '-99999999'
	out->assm_prc = Str2Int(data->assm_prc, sizeof(data->assm_prc));	// 평가가격
	out->best_ask_prc = Str2Int(data->best_ask_prc, sizeof(data->best_ask_prc));	// 최고호가가격
	out->least_ask_prc = Str2Int(data->least_ask_prc, sizeof(data->least_ask_prc));	// 최저호가가격
	out->mkt_base_prc_flg = data->mkt_base_prc_flg[0];	//시가기준가격여부, Y, N
	memcpy(out->lock_clsf_code, data->lock_clsf_code, sizeof(data->lock_clsf_code));	// 락구분코드, 00:해당사항없음 01:권리락 02:배당락 03:분배락 04:권배락 05:중간(분기)배당락 06:권리중간배당락 07:권리분기배당락 99:기타
	memcpy(out->pval_chg_clsf_code, data->pval_chg_clsf_code, sizeof(data->pval_chg_clsf_code));	// 액면가변경구분코드, 00:해당없음 01:액면분할 02:액면병합 03:주식분할 04:주식병합 99:기타
	out->trd_qty_unit = Str2Dbl(data->trd_qty_unit, sizeof(data->trd_qty_unit), 0);	// 매매수량단위, 1주단위:1 10:10주단위 100:100주단위 1000:1000주단위
	out->stk_lstd = Str2Dbl(data->stk_lstd, sizeof(data->stk_lstd), 0);	// 상장주식수
	out->apnt = data->apnt[0];	//지정여부, N:해제  Y:지정
	out->bopen_ofhr_flg = data->bopen_ofhr_flg[0];	//장개시전시간외종가가능여부, N:해당없음 Y:가능

	return 1;
}


// 코스닥_회원제재해제공개
int ParseR3012(const double& timestamp, const char* in_buff, DF_KOSDAQ_MBR_SCT_CNCL_DCLS* out) {
	KOSDAQ_MBR_SCT_CNCL_DCLS* data = (KOSDAQ_MBR_SCT_CNCL_DCLS*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA구분, R3
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// 정보구분, 01:주식
	out->mkt_clsf = data->mkt_clsf[0];	//시장구분, 1:유가증권 2:코스닥
	memcpy(out->ind_code, data->ind_code, sizeof(data->ind_code));	// 종목코드, **: 전종목해당
	out->stk_snr = Str2Int(data->stk_snr, sizeof(data->stk_snr));	// 종목일련번호, 종목배치(A0)의 종목일련번호
	memcpy(out->open_info_clsf_code, data->open_info_clsf_code, sizeof(data->open_info_clsf_code));	// 공개정보구분코드, ※ 코드값모음 참조
	memcpy(out->open_time, data->open_time, sizeof(data->open_time));	// 공개시각
	memcpy(out->mbr_nr, data->mbr_nr, sizeof(data->mbr_nr));	// 회원번호
	out->mbr_sct_rng_code = Str2Int(data->mbr_sct_rng_code, sizeof(data->mbr_sct_rng_code));	// 회원제재범위구분코드, 회원의 거래를 허용 또는 제재하는 범위. Bitwise 정의 1: 매도(풋매수) 위탁 2: 매도(풋매수) 자기 4: 매수(풋매도) 위탁 8: 매수(풋매도) 자기

	return 1;
}


// 코스닥_장운영스케줄공개
int ParseM4012(const double& timestamp, const char* in_buff, DF_KOSDAQ_MKT_OPR_DCLS* out) {
	KOSDAQ_MKT_OPR_DCLS* data = (KOSDAQ_MKT_OPR_DCLS*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA구분, M4
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// 정보구분, 01:주식
	out->mkt_clsf = data->mkt_clsf[0];	//시장구분, 1:유가증권 2:코스닥
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// 종목코드, 개별종목 장운영 조치시, 조기종료(KO)시 등록
	out->stk_snr = Str2Int(data->stk_snr, sizeof(data->stk_snr));	// 종목일련번호, 종목배치(A0)의 종목일련번호
	memcpy(out->brd_id, data->brd_id, sizeof(data->brd_id));	// 보드ID, ※ 코드값모음 참조
	memcpy(out->brd_evt_id, data->brd_evt_id, sizeof(data->brd_evt_id));	// 보드이벤트ID, ※ 코드값모음 참조
	memcpy(out->brd_evt_st, data->brd_evt_st, sizeof(data->brd_evt_st));	// 보드이벤트시작시각
	out->brd_evt_code = Str2Int(data->brd_evt_code, sizeof(data->brd_evt_code));	// 보드이벤트적용군코드, ※ 코드값모음 참조
	memcpy(out->sess_open_cls_id, data->sess_open_cls_id, sizeof(data->sess_open_cls_id));	// 세션개시종료코드, BS: 보드개시 BE: 보드종료 SS: 세션개시 SE: 세션종료 SH: 세션정지 SR: 세션재개
	memcpy(out->sess_id, data->sess_id, sizeof(data->sess_id));	// 세션ID, ※ 코드값모음 참조
	memcpy(out->pbl_stk_code, data->pbl_stk_code, sizeof(data->pbl_stk_code));	// 상장사종목코드, 종목조치의 기준이 되는 종목코드 *비상장사의 종목코드도 사용될 수 있음
	memcpy(out->trsp_rsn_code, data->trsp_rsn_code, sizeof(data->trsp_rsn_code));	// 거래정지사유코드, ※ 코드값모음 참조 *조기종료(KO) 는 "  "
	out->trsp_trgg_code = data->trsp_trgg_code[0];	//거래정지발생유형코드, 1:자기종목 2:신주인수권증권 3:신주인수권증서 4:기초자산ELW 5:발행ELW 6:상장사 7:기초자산소속시장 *조기종료(KO)는 "1"
	out->apl_step = Str2Int(data->apl_step, sizeof(data->apl_step));	// 적용단계, CB 및 가격제한폭 확대시 적용되는 단계(그 외의 경우는 "00")

	return 1;
}


// 코스닥_자사주 배치정보
int ParseA9012(const double& timestamp, const char* in_buff, DF_KOSDAQ_TRS_STK_ARNG_INFO* out) {
	KOSDAQ_TRS_STK_ARNG_INFO* data = (KOSDAQ_TRS_STK_ARNG_INFO*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA구분, A9
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// 정보구분, 01:주식
	out->mkt_clsf = data->mkt_clsf[0];	//시장구분, 1:유가증권 2:코스닥
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// 종목코드, 표준코드
	out->snr = Str2Int(data->snr, sizeof(data->snr));	// 일련번호, 1~99999999 건수체크용
	memcpy(out->trs_stk_id, data->trs_stk_id, sizeof(data->trs_stk_id));	// 자사주신고서ID, 0:해당없음 N:자사주직접일반 S:자사주직접스톡옵션\n1~99999:자사주신탁일련번호	※값 좌측정렬
	out->ask_bid_clsf_code = data->ask_bid_clsf_code[0];	//매도매수구분코드, 0:신탁 1:매도 2:매수
	memcpy(out->trs_stk_date, data->trs_stk_date, sizeof(data->trs_stk_date));	// 자사주신청일자, YYYYMMDD ※신고서의 경우 신청일자가 없음
	memcpy(out->trs_stk_st_date, data->trs_stk_st_date, sizeof(data->trs_stk_st_date));	// 자사주신고개시일자, YYYYMMDD 신고서상의 자사주매매 개시일자
	memcpy(out->trs_stk_ed_date, data->trs_stk_ed_date, sizeof(data->trs_stk_ed_date));	// 자사주신고종료일자, YYYYMMDD 신고서상의 자사주매매 종료일자
	out->trs_stk_trd_code = data->trs_stk_trd_code[0];	//자사주매매방법코드, 0:해당없음 1:자사주일반 2:한은등 자사주 3:정부등 자사주\n※2,3 : 장종료후시간외대량매수만 가능, 당일거래(매매거래의\n		종류)관련 사용\n		→일반자사주는 시간외대량 매수불가(매도만 가능)\n※3 : 장종료후시간외대량매수시 상/하한가 제한없음
	out->trs_stk_ptcp_nr = Str2Int(data->trs_stk_ptcp_nr, sizeof(data->trs_stk_ptcp_nr));	// "자사주신청시장참가자 번호", 회원번호 예) '00001'
	out->open_trs_stk_qty = Str2Dbl(data->open_trs_stk_qty, sizeof(data->open_trs_stk_qty), 0);	// "시가단일가자사주신청 수량", 신고기간중의 신청일 시가단일가 신청 수량
	out->opr_time_trs_stk_qty = Str2Dbl(data->opr_time_trs_stk_qty, sizeof(data->opr_time_trs_stk_qty), 0);	// 장중자사주신청수량, 신고기간중의 신청일 접속 신청 수량
	out->ofhr_msv_trs_stk_qty = Str2Dbl(data->ofhr_msv_trs_stk_qty, sizeof(data->ofhr_msv_trs_stk_qty), 0);	// "시간외대량자사주 신청수량", 시간외(오전, 오후)시장의 자사주 신고수량
	out->trs_stk_cum_ccls_qty = Str2Dbl(data->trs_stk_cum_ccls_qty, sizeof(data->trs_stk_cum_ccls_qty), 0);	// 자사주누적체결수량, 신고기간중의 정규장, 시간외시장에서 자사주 체결수량 누적
	out->trs_stk_cum_trd_val = Str2Dbl(data->trs_stk_cum_trd_val, sizeof(data->trs_stk_cum_trd_val), 0);	// 자사주누적거래대금, 신고기간중의 정규장, 시간외시장에서 자사주 거래대금 누적

	return 1;
}


// 코스닥_자사주 매매정보
int ParseB0012(const double& timestamp, const char* in_buff, DF_KOSDAQ_TRS_STK_TRD_INFO* out) {
	KOSDAQ_TRS_STK_TRD_INFO* data = (KOSDAQ_TRS_STK_TRD_INFO*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA구분, B0
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// 정보구분, 01:주식
	out->mkt_clsf = data->mkt_clsf[0];	//시장구분, 1:유가증권 2:코스닥
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// 종목코드, 표준코드
	out->snr = Str2Int(data->snr, sizeof(data->snr));	// 일련번호, 1~99999999 종목일련번호 2014.03.03
	out->ccls_prc = Str2Int(data->ccls_prc, sizeof(data->ccls_prc));	// 체결가격, 단위:원
	out->ccls_qty = Str2Dbl(data->ccls_qty, sizeof(data->ccls_qty), 0);	// 체결수량, 단위:주
	memcpy(out->sess_id, data->sess_id, sizeof(data->sess_id));	// 세션ID, 코드값모음 참조
	memcpy(out->bid_trs_stk_id, data->bid_trs_stk_id, sizeof(data->bid_trs_stk_id));	// 매수자사주신고서ID, 0:해당없음 N:자사주직접일반 S:자사주직접스탁옵션\n1~99999:자사주신탁(신고서일련번호)\n※값은 왼쪽정렬  예) "N", "1"\n※자사주신탁일련번호는 종목별로 영구적으로 누적 채번됨\n  직접에 반해 신탁에 일련번호가 존재하는 이유는 동일\n  종목에 대해서 여러 신탁회사에서 자사주를 신고할 수\n  있도록 허용하기 위함임
	memcpy(out->ask_trs_stk_id, data->ask_trs_stk_id, sizeof(data->ask_trs_stk_id));	// 매도자사주신고서ID, 매수자사주신고서ID와 동일

	return 1;
}


// 코스닥_시세RECOVERY
int ParseB2012(const double& timestamp, const char* in_buff, DF_KOSDAQ_MKT_PRC_RCVR* out) {
	KOSDAQ_MKT_PRC_RCVR* data = (KOSDAQ_MKT_PRC_RCVR*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA구분, B1:종가 B2:시세REC
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// 정보구분, 01:주식 02:ELW
	out->mkt_clsf = data->mkt_clsf[0];	//시장구분, 1:유가증권 2:코스닥
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// 종목코드, 표준코드
	out->stk_snr = Str2Int(data->stk_snr, sizeof(data->stk_snr));	// 종목일련번호, 종목배치(A0)의 종목일련번호
	out->flct_clsf = data->flct_clsf[0];	//등락구분, 0:판단불가 1:상한 2:상승 3:보합 4:하한 5:하락
	out->prev_ctrs = Str2Int(data->prev_ctrs, sizeof(data->prev_ctrs));	// 전일대비, 단위:원
	out->cur_prc = Str2Int(data->cur_prc, sizeof(data->cur_prc));	// 현재가
	out->open = Str2Int(data->open, sizeof(data->open));	// 시가, 정규장 시가
	out->hi = Str2Int(data->hi, sizeof(data->hi));	// 고가, 정규장 고가
	out->low = Str2Int(data->low, sizeof(data->low));	// 저가, 정규장 저가
	out->ask_prc = Str2Int(data->ask_prc, sizeof(data->ask_prc));	// 매도호가, B1시 0값 SET
	out->bid_prc = Str2Int(data->bid_prc, sizeof(data->bid_prc));	// 매수호가, B1시 0값 SET
	out->cum_ccls_qty = Str2Dbl(data->cum_ccls_qty, sizeof(data->cum_ccls_qty), 0);	// 누적체결수량, 단위:주 ※시간외단일가, BUY-IN을 제외한 모든 체결수량 합산
	out->cum_trd_val = Str2Dbl(data->cum_trd_val, sizeof(data->cum_trd_val), 0);	// 누적거래대금, 단위:원 ※시간외단일가, BUY-IN을 제외한 모든 거래대금 합산
	out->trend_flg = data->trend_flg[0];	//실세/기세 구분, 0:초기값 1:실세 2:기세 3:거래무 4:시가기준가종목의 기세
	memcpy(out->brd_evt_id, data->brd_evt_id, sizeof(data->brd_evt_id));	// 보드이벤트ID, B1/B2 에서는 보드이벤트ID 사용금지(과거 상태값이 전송될 수 있음). 추후, 해당 항목 '000' 세팅 예정. 2014.03.24)
	memcpy(out->brd_id, data->brd_id, sizeof(data->brd_id));	// 보드ID, ※ 코드값모음 참조
	out->trsp_flg = data->trsp_flg[0];	//거래정지여부, Y, N
	out->bopen_ofhr_ccls_qty = Str2Dbl(data->bopen_ofhr_ccls_qty, sizeof(data->bopen_ofhr_ccls_qty), 0);	// 장개시전시간외종가체결수량, 대량, 바스켓은 제외, 단위:주
	out->bopen_ofhr_trd_val = Str2Dbl(data->bopen_ofhr_trd_val, sizeof(data->bopen_ofhr_trd_val), 0);	// 장개시전시간외종가거래대금, 대량, 바스켓은 제외, 단위:원
	out->opr_time_ccls_qty = Str2Dbl(data->opr_time_ccls_qty, sizeof(data->opr_time_ccls_qty), 0);	// 정규장체결수량, 대량, 바스켓은 제외, 단위:주
	out->opr_time_trd_val = Str2Dbl(data->opr_time_trd_val, sizeof(data->opr_time_trd_val), 0);	// 정규장거래대금, 대량, 바스켓은 제외, 단위:원
	out->ofhr_cls_ccls_qty = Str2Dbl(data->ofhr_cls_ccls_qty, sizeof(data->ofhr_cls_ccls_qty), 0);	// 장종료후시간외종가체결수량, 대량, 바스켓은 제외, 단위:주
	out->ofhr_cls_trd_val = Str2Dbl(data->ofhr_cls_trd_val, sizeof(data->ofhr_cls_trd_val), 0);	// 장종료후시간외종가거래대금, 대량, 바스켓은 제외, 단위:원
	out->elw_ely_cls_flg = data->elw_ely_cls_flg[0];	//ELW조기종료여부, Y,N 조기종료ELW 外 종목은 Default 'N' SET
	out->elw_ely_cls_time = Str2Int(data->elw_ely_cls_time, sizeof(data->elw_ely_cls_time));	// ELW조기종료시간, HHMMSS, ELW조기종료여부가 'Y'인 경우만 설정
	out->cmpt_msv_dir_clsf = Str2Int(data->cmpt_msv_dir_clsf, sizeof(data->cmpt_msv_dir_clsf));	// 경쟁대량 방향구분, 0:해당없음, 1:매도, 2:매수
	out->gen_bin_ccls_qty = Str2Dbl(data->gen_bin_ccls_qty, sizeof(data->gen_bin_ccls_qty), 0);	// 일반 Buy-in 체결수량, 단위:주
	out->gen_bin_ccls_trd_val = Str2Dbl(data->gen_bin_ccls_trd_val, sizeof(data->gen_bin_ccls_trd_val), 0);	// 일반 Buy-in 거래대금, 단위:원
	out->day_bin_ccls_qty = Str2Dbl(data->day_bin_ccls_qty, sizeof(data->day_bin_ccls_qty), 0);	// 당일 Buy-in 체결수량, 단위:주
	out->day_bin_ccls_trd_val = Str2Dbl(data->day_bin_ccls_trd_val, sizeof(data->day_bin_ccls_trd_val), 0);	// 당일 Buy-in 거래대금, 단위:원

	return 1;
}


// 코스닥_시간외단일가_리커버리_최종
int ParseB3012(const double& timestamp, const char* in_buff, DF_KOSDAQ_OFH_RCVR_FINAL* out) {
	KOSDAQ_OFH_RCVR_FINAL* data = (KOSDAQ_OFH_RCVR_FINAL*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA구분, B3:시간외단일가최종 B4:시간외단일가REC
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// 정보구분, 01:주식
	out->mkt_clsf = data->mkt_clsf[0];	//시장구분, 1:유가증권 2:코스닥
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// 종목코드, 표준코드
	out->stk_snr = Str2Int(data->stk_snr, sizeof(data->stk_snr));	// 종목일련번호, 종목배치(A0)의 종목일련번호
	out->ofhr_cnst_clsf = data->ofhr_cnst_clsf[0];	//시간외단일가등락구분, 0:판단불가 1:상한 2:상승 3:보합 4:하한 5:하락
	out->ofhr_cnst = Str2Int(data->ofhr_cnst, sizeof(data->ofhr_cnst));	// 시간외단일가대비, 단위:원
	out->ofhr_cnst_ceil = Str2Int(data->ofhr_cnst_ceil, sizeof(data->ofhr_cnst_ceil));	// 시간외단일가상한가
	out->ofhr_cnst_flr = Str2Int(data->ofhr_cnst_flr, sizeof(data->ofhr_cnst_flr));	// 시간외단일가하한가
	out->ofhr_cnst_cur = Str2Int(data->ofhr_cnst_cur, sizeof(data->ofhr_cnst_cur));	// 시간외단일가현재가
	out->ofhr_cnst_open = Str2Int(data->ofhr_cnst_open, sizeof(data->ofhr_cnst_open));	// 시간외단일가시가
	out->ofhr_cnst_hi = Str2Int(data->ofhr_cnst_hi, sizeof(data->ofhr_cnst_hi));	// 시간외단일가고가
	out->ofhr_cnst_lo = Str2Int(data->ofhr_cnst_lo, sizeof(data->ofhr_cnst_lo));	// 시간외단일가저가
	out->ofhr_cnst_ask = Str2Int(data->ofhr_cnst_ask, sizeof(data->ofhr_cnst_ask));	// 시간외단일가매도호가, B3시 0값 SET
	out->ofhr_cnst_bid = Str2Int(data->ofhr_cnst_bid, sizeof(data->ofhr_cnst_bid));	// 시간외단일가매수호가, B3시 0값 SET
	out->ofhr_cnst_cum_ccls_qty = Str2Dbl(data->ofhr_cnst_cum_ccls_qty, sizeof(data->ofhr_cnst_cum_ccls_qty), 0);	// 시간외단일가누적체결수량
	out->ofhr_cnst_cum_trd_val = Str2Dbl(data->ofhr_cnst_cum_trd_val, sizeof(data->ofhr_cnst_cum_trd_val), 0);	// 시간외단일가누적거래대금
	out->tot_cum_ccls_qty = Str2Dbl(data->tot_cum_ccls_qty, sizeof(data->tot_cum_ccls_qty), 0);	// 전체 총 누적체결수량
	out->tot_cum_trd_val = Str2Dbl(data->tot_cum_trd_val, sizeof(data->tot_cum_trd_val), 0);	// 전체 총 누적거래대금
	out->ofhr_mkt_clsf = data->ofhr_mkt_clsf[0];	//시간외단일가장구분, 0:초기값 1:시간외단일가개시 2:시간외단일가마감
	out->trsp_flg = data->trsp_flg[0];	//거래정지여부, Y, N
	out->trend_flg = data->trend_flg[0];	//실세/기세 구분, 0:초기값 1:실세 2:기세 3:거래무 4:시가기준가종목의 기세

	return 1;
}


// 코스닥_시간외단일가_리커버리
int ParseB4012(const double& timestamp, const char* in_buff, DF_KOSDAQ_OFH_RCVR* out) {
	KOSDAQ_OFH_RCVR* data = (KOSDAQ_OFH_RCVR*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA구분, B3:시간외단일가최종 B4:시간외단일가REC
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// 정보구분, 01:주식
	out->mkt_clsf = data->mkt_clsf[0];	//시장구분, 1:유가증권 2:코스닥
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// 종목코드, 표준코드
	out->stk_snr = Str2Int(data->stk_snr, sizeof(data->stk_snr));	// 종목일련번호, 종목배치(A0)의 종목일련번호
	out->ofhr_cnst_clsf = data->ofhr_cnst_clsf[0];	//시간외단일가등락구분, 0:판단불가 1:상한 2:상승 3:보합 4:하한 5:하락
	out->ofhr_cnst = Str2Int(data->ofhr_cnst, sizeof(data->ofhr_cnst));	// 시간외단일가대비, 단위:원
	out->ofhr_cnst_ceil = Str2Int(data->ofhr_cnst_ceil, sizeof(data->ofhr_cnst_ceil));	// 시간외단일가상한가
	out->ofhr_cnst_flr = Str2Int(data->ofhr_cnst_flr, sizeof(data->ofhr_cnst_flr));	// 시간외단일가하한가
	out->ofhr_cnst_cur = Str2Int(data->ofhr_cnst_cur, sizeof(data->ofhr_cnst_cur));	// 시간외단일가현재가
	out->ofhr_cnst_open = Str2Int(data->ofhr_cnst_open, sizeof(data->ofhr_cnst_open));	// 시간외단일가시가
	out->ofhr_cnst_hi = Str2Int(data->ofhr_cnst_hi, sizeof(data->ofhr_cnst_hi));	// 시간외단일가고가
	out->ofhr_cnst_lo = Str2Int(data->ofhr_cnst_lo, sizeof(data->ofhr_cnst_lo));	// 시간외단일가저가
	out->ofhr_cnst_ask = Str2Int(data->ofhr_cnst_ask, sizeof(data->ofhr_cnst_ask));	// 시간외단일가매도호가, B3시 0값 SET
	out->ofhr_cnst_bid = Str2Int(data->ofhr_cnst_bid, sizeof(data->ofhr_cnst_bid));	// 시간외단일가매수호가, B3시 0값 SET
	out->ofhr_cnst_cum_ccls_qty = Str2Dbl(data->ofhr_cnst_cum_ccls_qty, sizeof(data->ofhr_cnst_cum_ccls_qty), 0);	// 시간외단일가누적체결수량
	out->ofhr_cnst_cum_trd_val = Str2Dbl(data->ofhr_cnst_cum_trd_val, sizeof(data->ofhr_cnst_cum_trd_val), 0);	// 시간외단일가누적거래대금
	out->tot_cum_ccls_qty = Str2Dbl(data->tot_cum_ccls_qty, sizeof(data->tot_cum_ccls_qty), 0);	// 전체 총 누적체결수량
	out->tot_cum_trd_val = Str2Dbl(data->tot_cum_trd_val, sizeof(data->tot_cum_trd_val), 0);	// 전체 총 누적거래대금
	out->ofhr_mkt_clsf = data->ofhr_mkt_clsf[0];	//시간외단일가장구분, 0:초기값 1:시간외단일가개시 2:시간외단일가마감
	out->trsp_flg = data->trsp_flg[0];	//거래정지여부, Y, N
	out->trend_flg = data->trend_flg[0];	//실세/기세 구분, 0:초기값 1:실세 2:기세 3:거래무 4:시가기준가종목의 기세

	return 1;
}


// 코스닥_현재등락
int ParseB5012(const double& timestamp, const char* in_buff, DF_KOSDAQ_CUR_FLCT* out) {
	KOSDAQ_CUR_FLCT* data = (KOSDAQ_CUR_FLCT*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA구분, B5
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// 정보구분, 01:주식
	out->mkt_clsf = data->mkt_clsf[0];	//시장구분, 1:유가증권 2:코스닥
	out->tot_stk_nr = Str2Int(data->tot_stk_nr, sizeof(data->tot_stk_nr));	// 전체 종목수
	out->trd_form_stk_nr = Str2Int(data->trd_form_stk_nr, sizeof(data->trd_form_stk_nr));	// 거래형성 종목수
	out->ceil_stk_nr = Str2Int(data->ceil_stk_nr, sizeof(data->ceil_stk_nr));	// 상한 종목수
	out->rise_stk_nr = Str2Int(data->rise_stk_nr, sizeof(data->rise_stk_nr));	// 상승 종목수
	out->stdstl_stk_nr = Str2Int(data->stdstl_stk_nr, sizeof(data->stdstl_stk_nr));	// 보합 종목수
	out->flr_stk_nr = Str2Int(data->flr_stk_nr, sizeof(data->flr_stk_nr));	// 하한 종목수
	out->fall_stk_nr = Str2Int(data->fall_stk_nr, sizeof(data->fall_stk_nr));	// 하락 종목수
	out->trend_stk_nr = Str2Int(data->trend_stk_nr, sizeof(data->trend_stk_nr));	// 기세 종목수
	out->trend_rise_stk_nr = Str2Int(data->trend_rise_stk_nr, sizeof(data->trend_rise_stk_nr));	// 기세상승 종목수
	out->trend_fall_stk_nr = Str2Int(data->trend_fall_stk_nr, sizeof(data->trend_fall_stk_nr));	// 기세하락 종목수

	return 1;
}


// 코스닥_Buy-in_실행수량
int ParseO4012(const double& timestamp, const char* in_buff, DF_KOSDAQ_BIN_EXCQ* out) {
	KOSDAQ_BIN_EXCQ* data = (KOSDAQ_BIN_EXCQ*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA구분, O4
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// 정보구분, 01:주식
	out->mkt_clsf = data->mkt_clsf[0];	//시장구분, 1:유가증권, 2:코스닥, 8:코넥스
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// 종목코드, 표준코드 또는 "999999999999" 개발가이드 참조
	out->snr = Str2Int(data->snr, sizeof(data->snr));	// 일련번호, ※ Buy-in구분코드별로 일련번호 설정
	memcpy(out->trsm_date, data->trsm_date, sizeof(data->trsm_date));	// 전송일자, YYYYMMDD
	out->bin_clsf_code = data->bin_clsf_code[0];	//Buy-in구분코드, 1: 일반 Buy-in, 2: 당일 Buy-in
	out->scrt_grp_id = Str2Int(data->scrt_grp_id, sizeof(data->scrt_grp_id));	// 증권그룹ID, ST:주식, MF:증권투자회사, RT:리츠, SC:선박투자회사,\nIF:인프라투융자회사, DR:예탁증서, SW:신주인수권증권,\nSR:신주인수권증서, EW:주식워런트증권, EF:상장지수펀드,\nBC:수익증권, FE:해외ETF, FS:해외원주\nEN:ETN(2014.11.17)
	out->bin_exc_qty = Str2Dbl(data->bin_exc_qty, sizeof(data->bin_exc_qty), 0);	// Buy-in 실행수량

	return 1;
}


// 코스닥 업종별 배당수익률
int ParseP2012(const double& timestamp, const char* in_buff, DF_KOSDAQ_BYIND_DYR* out) {
	KOSDAQ_BYIND_DYR* data = (KOSDAQ_BYIND_DYR*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA구분, P2
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// 정보구분, 01:주식
	out->mkt_clsf = data->mkt_clsf[0];	//시장구분, 1:유가증권 2:코스닥
	memcpy(out->idx_ind_code, data->idx_ind_code, sizeof(data->idx_ind_code));	// 지수업종코드, ※코드값모음 참조
	out->dyr = Str2Dbl(data->dyr, sizeof(data->dyr), 2);	// 배당수익률, 99999v99

	return 1;
}


// 코스닥_장개시전_호가잔량
int ParseB8012(const double& timestamp, const char* in_buff, DF_KOSDAQ_BOPEN_ASK_RSD* out) {
	KOSDAQ_BOPEN_ASK_RSD* data = (KOSDAQ_BOPEN_ASK_RSD*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA구분, B8
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// 정보구분, 01:주식
	out->mkt_clsf = data->mkt_clsf[0];	//시장구분, 1:유가증권 2:코스닥
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// 종목코드, 표준코드
	out->stk_snr = Str2Int(data->stk_snr, sizeof(data->stk_snr));	// 종목일련번호, 종목배치(A0)의 종목일련번호
	out->cum_ccls_qty = Str2Dbl(data->cum_ccls_qty, sizeof(data->cum_ccls_qty), 0);	// 누적체결수량
	out->tot_ask_rsd = Str2Dbl(data->tot_ask_rsd, sizeof(data->tot_ask_rsd), 0);	// 총매도호가잔량
	out->tot_bid_rsd = Str2Dbl(data->tot_bid_rsd, sizeof(data->tot_bid_rsd), 0);	// 총매수호가잔량

	return 1;
}


// 코스닥_호가잔량_LP호가_제외
int ParseB6012(const double& timestamp, const char* in_buff, DF_KOSDAQ_ASK_RSD_WOLP* out) {
	int i=0;
	KOSDAQ_ASK_RSD_WOLP* data = (KOSDAQ_ASK_RSD_WOLP*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA구분, B6
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// 정보구분, 01:주식
	out->mkt_clsf = data->mkt_clsf[0];	//시장구분, 1:유가증권 2:코스닥
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// 종목코드, 표준코드
	out->stk_snr = Str2Int(data->stk_snr, sizeof(data->stk_snr));	// 종목일련번호, 종목배치(A0)의 종목일련번호
	out->cum_ccls_qty = Str2Dbl(data->cum_ccls_qty, sizeof(data->cum_ccls_qty), 0);	// 누적체결수량

	for ( i=0 ; i<10 ; i++ ) {
		out->lob_infos[i].ask_prc = Str2Int(data->lob_infos[i].ask_prc, sizeof(data->lob_infos[i].ask_prc));	// 매도호가
		out->lob_infos[i].bid_prc = Str2Int(data->lob_infos[i].bid_prc, sizeof(data->lob_infos[i].bid_prc));	// 매수호가
		out->lob_infos[i].ask_vol_rsd = Str2Dbl(data->lob_infos[i].ask_vol_rsd, sizeof(data->lob_infos[i].ask_vol_rsd), 0);	// 매도호가 잔량
		out->lob_infos[i].bid_vol_rsd = Str2Dbl(data->lob_infos[i].bid_vol_rsd, sizeof(data->lob_infos[i].bid_vol_rsd), 0);	// 매수호가 잔량
	}   // 호가

	out->ask_10_tot_rsd = Str2Dbl(data->ask_10_tot_rsd, sizeof(data->ask_10_tot_rsd), 0);	// 10단계호가매도총잔량
	out->bid_10_tot_rsd = Str2Dbl(data->bid_10_tot_rsd, sizeof(data->bid_10_tot_rsd), 0);	// 10단계호가매수총잔량
	out->ofhr_ask_tot_rsd = Str2Dbl(data->ofhr_ask_tot_rsd, sizeof(data->ofhr_ask_tot_rsd), 0);	// 장종료후시간외매도총호가잔량, 보드ID "G3"일때 값이 설정됨
	out->ofhr_bid_tot_rsd = Str2Dbl(data->ofhr_bid_tot_rsd, sizeof(data->ofhr_bid_tot_rsd), 0);	// 장종료후시간외매수총호가잔량, 보드ID "G3"일때 값이 설정됨
	memcpy(out->sess_id, data->sess_id, sizeof(data->sess_id));	// 세션ID, ※ 코드값모음 참조
	memcpy(out->brd_id, data->brd_id, sizeof(data->brd_id));	// 보드ID, ※ 코드값모음 참조
	out->exp_ccls_prc = Str2Int(data->exp_ccls_prc, sizeof(data->exp_ccls_prc));	// 예상체결가격
	out->exp_ccls_qty = Str2Dbl(data->exp_ccls_qty, sizeof(data->exp_ccls_qty), 0);	// 예상체결수량
	out->cmpt_msv_dir_clsf = Str2Int(data->cmpt_msv_dir_clsf, sizeof(data->cmpt_msv_dir_clsf));	// 경쟁대량 방향구분, 0:해당없음, 1:매도, 2:매수

	return 1;
}


// 코스닥_공매도
int ParseI8012(const double& timestamp, const char* in_buff, DF_KOSDAQ_SHORT* out) {
	KOSDAQ_SHORT* data = (KOSDAQ_SHORT*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA구분, I8
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// 정보구분, 01:주식
	out->mkt_clsf = data->mkt_clsf[0];	//시장구분, 1:유가증권 2:코스닥
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// 종목코드, 표준코드
	out->snr = Str2Int(data->snr, sizeof(data->snr));	// 일련번호, 1~99999999 종목일련번호
	out->short_brwg_ask_ccls_qty = Str2Dbl(data->short_brwg_ask_ccls_qty, sizeof(data->short_brwg_ask_ccls_qty), 0);	// "공매도차입증권매도 체결수량", 단위:주
	out->short_brwg_ask_trd_val = Str2Dbl(data->short_brwg_ask_trd_val, sizeof(data->short_brwg_ask_trd_val), 0);	// "공매도차입증권매도 거래대금", 단위:원

	return 1;
}


// 코스닥_시세종가
int ParseB1012(const double& timestamp, const char* in_buff, DF_KOSDAQ_MKT_PRC_CLS* out) {
	KOSDAQ_MKT_PRC_CLS* data = (KOSDAQ_MKT_PRC_CLS*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA구분, B1:종가 B2:시세REC
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// 정보구분, 01:주식 02:ELW
	out->mkt_clsf = data->mkt_clsf[0];	//시장구분, 1:유가증권 2:코스닥
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// 종목코드, 표준코드
	out->stk_snr = Str2Int(data->stk_snr, sizeof(data->stk_snr));	// 종목일련번호, 종목배치(A0)의 종목일련번호
	out->flct_clsf = data->flct_clsf[0];	//등락구분, 0:판단불가 1:상한 2:상승 3:보합 4:하한 5:하락
	out->prev_ctrs = Str2Int(data->prev_ctrs, sizeof(data->prev_ctrs));	// 전일대비, 단위:원
	out->cur_prc = Str2Int(data->cur_prc, sizeof(data->cur_prc));	// 현재가
	out->open = Str2Int(data->open, sizeof(data->open));	// 시가, 정규장 시가
	out->hi = Str2Int(data->hi, sizeof(data->hi));	// 고가, 정규장 고가
	out->low = Str2Int(data->low, sizeof(data->low));	// 저가, 정규장 저가
	out->ask_prc = Str2Int(data->ask_prc, sizeof(data->ask_prc));	// 매도호가, B1시 0값 SET
	out->bid_prc = Str2Int(data->bid_prc, sizeof(data->bid_prc));	// 매수호가, B1시 0값 SET
	out->cum_ccls_qty = Str2Dbl(data->cum_ccls_qty, sizeof(data->cum_ccls_qty), 0);	// 누적체결수량, 단위:주 ※시간외단일가, BUY-IN을 제외한 모든 체결수량 합산
	out->cum_trd_val = Str2Dbl(data->cum_trd_val, sizeof(data->cum_trd_val), 0);	// 누적거래대금, 단위:원 ※시간외단일가, BUY-IN을 제외한 모든 거래대금 합산
	out->trend_flg = data->trend_flg[0];	//실세/기세 구분, 0:초기값 1:실세 2:기세 3:거래무 4:시가기준가종목의 기세
	memcpy(out->brd_evt_id, data->brd_evt_id, sizeof(data->brd_evt_id));	// 보드이벤트ID, B1/B2 에서는 보드이벤트ID 사용금지(과거 상태값이 전송될 수 있음). 추후, 해당 항목 '000' 세팅 예정. 2014.03.24)
	memcpy(out->brd_id, data->brd_id, sizeof(data->brd_id));	// 보드ID, ※ 코드값모음 참조
	out->trsp_flg = data->trsp_flg[0];	//거래정지여부, Y, N
	out->bopen_ofhr_ccls_qty = Str2Dbl(data->bopen_ofhr_ccls_qty, sizeof(data->bopen_ofhr_ccls_qty), 0);	// 장개시전시간외종가체결수량, 대량, 바스켓은 제외, 단위:주
	out->bopen_ofhr_trd_val = Str2Dbl(data->bopen_ofhr_trd_val, sizeof(data->bopen_ofhr_trd_val), 0);	// 장개시전시간외종가거래대금, 대량, 바스켓은 제외, 단위:원
	out->opr_time_ccls_qty = Str2Dbl(data->opr_time_ccls_qty, sizeof(data->opr_time_ccls_qty), 0);	// 정규장체결수량, 대량, 바스켓은 제외, 단위:주
	out->opr_time_trd_val = Str2Dbl(data->opr_time_trd_val, sizeof(data->opr_time_trd_val), 0);	// 정규장거래대금, 대량, 바스켓은 제외, 단위:원
	out->ofhr_cls_ccls_qty = Str2Dbl(data->ofhr_cls_ccls_qty, sizeof(data->ofhr_cls_ccls_qty), 0);	// 장종료후시간외종가체결수량, 대량, 바스켓은 제외, 단위:주
	out->ofhr_cls_trd_val = Str2Dbl(data->ofhr_cls_trd_val, sizeof(data->ofhr_cls_trd_val), 0);	// 장종료후시간외종가거래대금, 대량, 바스켓은 제외, 단위:원
	out->elw_ely_cls_flg = data->elw_ely_cls_flg[0];	//ELW조기종료여부, Y,N 조기종료ELW 外 종목은 Default 'N' SET
	out->elw_ely_cls_time = Str2Int(data->elw_ely_cls_time, sizeof(data->elw_ely_cls_time));	// ELW조기종료시간, HHMMSS, ELW조기종료여부가 'Y'인 경우만 설정
	out->cmpt_msv_dir_clsf = Str2Int(data->cmpt_msv_dir_clsf, sizeof(data->cmpt_msv_dir_clsf));	// 경쟁대량 방향구분, 0:해당없음, 1:매도, 2:매수
	out->gen_bin_ccls_qty = Str2Dbl(data->gen_bin_ccls_qty, sizeof(data->gen_bin_ccls_qty), 0);	// 일반 Buy-in 체결수량, 단위:주
	out->gen_bin_ccls_trd_val = Str2Dbl(data->gen_bin_ccls_trd_val, sizeof(data->gen_bin_ccls_trd_val), 0);	// 일반 Buy-in 거래대금, 단위:원
	out->day_bin_ccls_qty = Str2Dbl(data->day_bin_ccls_qty, sizeof(data->day_bin_ccls_qty), 0);	// 당일 Buy-in 체결수량, 단위:주
	out->day_bin_ccls_trd_val = Str2Dbl(data->day_bin_ccls_trd_val, sizeof(data->day_bin_ccls_trd_val), 0);	// 당일 Buy-in 거래대금, 단위:원

	return 1;
}


// 코스닥_업종별투자자별
int ParseC0012(const double& timestamp, const char* in_buff, DF_KOSDAQ_BYIND_BYINV* out) {
	KOSDAQ_BYIND_BYINV* data = (KOSDAQ_BYIND_BYINV*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA구분, C0
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// 정보구분, 01:주식
	out->mkt_clsf = data->mkt_clsf[0];	//시장구분, 1:유가증권 2:코스닥
	memcpy(out->cmpt_time, data->cmpt_time, sizeof(data->cmpt_time));	// 산출시각, 90초 주기
	memcpy(out->inv_code, data->inv_code, sizeof(data->inv_code));	// 투자자코드, ※코드값모음 참조\n*코드'7000'시 수량, 대금정보 항목 0으로 전송 (20181210)
	memcpy(out->ind_code, data->ind_code, sizeof(data->ind_code));	// 업종코드, ※코드값모음 업종지수코드분류 참조\n산출업종;코스피/코스닥종합지수,코스피200지수
	out->ask_ccls_qty = Str2Dbl(data->ask_ccls_qty, sizeof(data->ask_ccls_qty), 0);	// 매도체결수량, 단위:주
	out->ask_trd_val = Str2Dbl(data->ask_trd_val, sizeof(data->ask_trd_val), 0);	// 매도거래대금, 단위:원
	out->bid_ccls_qty = Str2Dbl(data->bid_ccls_qty, sizeof(data->bid_ccls_qty), 0);	// 매수체결수량, 단위:주
	out->bid_trd_val = Str2Dbl(data->bid_trd_val, sizeof(data->bid_trd_val), 0);	// 매수거래대금, 단위:원

	return 1;
}


// K-OTC 종목배치
int ParseA0013(const double& timestamp, const char* in_buff, DF_KOTC_STK_ARNG* out) {
	int i=0;
	KOTC_STK_ARNG* data = (KOTC_STK_ARNG*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA구분, A0
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// 정보구분, 01:주식
	out->mkt_clsf = data->mkt_clsf[0];	//시장구분, 3:K-OTC
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// 종목코드, 표준코드
	out->snr = Str2Int(data->snr, sizeof(data->snr));	// 일련번호, 1~99999999 건수체크용
	memcpy(out->sh_code, data->sh_code, sizeof(data->sh_code));	// 단축코드, 왼쪽정렬((예)주식 6→7, 나머지 SPACE 처리)
	memcpy(out->proc_date, data->proc_date, sizeof(data->proc_date));	// 처리일자, 영업일자 (YYYYMMDD)
	memcpy(out->kor_stk_nm, data->kor_stk_nm, sizeof(data->kor_stk_nm));	// 한글종목명, SIZE변경(40→80) 2016.02.01
	memcpy(out->eng_abrv, data->eng_abrv, sizeof(data->eng_abrv));	// 영문약명, SIZE변경(20→40) 2016.02.01
	memcpy(out->eng_stk_nm, data->eng_stk_nm, sizeof(data->eng_stk_nm));	// 영문종목명, SIZE변경(40→80) 2016.02.01
	memcpy(out->kor_stk_abrv, data->kor_stk_abrv, sizeof(data->kor_stk_abrv));	// 종목명(한글약명), SIZE변경(20→40) 2016.02.01
	out->stk_snr = Str2Int(data->stk_snr, sizeof(data->stk_snr));	// 종목일련번호
	out->stk_clsf = data->stk_clsf[0];	//종목구분, 0:정상 1:신규 2:추가
	out->mdim_biz_flg = data->mdim_biz_flg[0];	//중소중견기업여부, 4:중소기업 5:중견기업 6중소중견비해당 7:미확인
	memcpy(out->std_type_ind_code, data->std_type_ind_code, sizeof(data->std_type_ind_code));	// 표준산업업종코드
	out->trd_base_prc = Str2Int(data->trd_base_prc, sizeof(data->trd_base_prc));	// 매매기준가, 가중평균주가, 락발생시 ‘매매기준가’ SET\n기세시는 '기세가격' SET\nSIZE변경(7→9) 2016.02.01
	out->prev_cls = Str2Int(data->prev_cls, sizeof(data->prev_cls));	// 전일종가, 단위:원, SIZE변경(7→9) 2016.02.01
	out->prev_wavg_prc = Str2Int(data->prev_wavg_prc, sizeof(data->prev_wavg_prc));	// 전일가중평균주가, 단위:원, SIZE변경(7→9) 2016.02.01
	out->pbct_stk_nr = Str2Dbl(data->pbct_stk_nr, sizeof(data->pbct_stk_nr), 0);	// 발행주식수, 단위:주, SIZE변경(12→15) 2016.02.01
	out->pval = Str2Int(data->pval, sizeof(data->pval));	// 액면가, 단위:원, SIZE변경(7→9) 2016.02.01
	memcpy(out->clsg_mth, data->clsg_mth, sizeof(data->clsg_mth));	// 결산월, MM
	out->clsg_clsf = data->clsg_clsf[0];	//결산구분, 0:보통주병합(1-4) 5:1우선주병합 6:2우선주병합
	out->per = Str2Dbl(data->per, sizeof(data->per), 2);	// PER, 9999V99
	out->eps = Str2Int(data->eps, sizeof(data->eps));	// EPS, 단위:원, SIZE변경(7→9) 2016.02.01
	out->trsp_flg = data->trsp_flg[0];	//거래정지여부, 0:정상 1:정지
	memcpy(out->trsp_rsn, data->trsp_rsn, sizeof(data->trsp_rsn));	// 거래정지사유, ※코드값모음 참조
	out->lock_clsf = data->lock_clsf[0];	//락구분, 0:정상 1:권리락 2:액면분할 3:액면병합 4:감자 5:병합\n6:배당락
	memcpy(out->rgst_aplc, data->rgst_aplc, sizeof(data->rgst_aplc));	// 등록신청사, 항목명(ASIS 지정신청사), SIZE변경(30→40) 2016.02.01
	memcpy(out->trd_open_date, data->trd_open_date, sizeof(data->trd_open_date));	// 매매개시일, YYYYMMDD
	out->cncl_clsf = data->cncl_clsf[0];	//해제구분, 항목명 변경(ASIS 취소구분)\n0:정상 1:구주병합에 의한 해제2:지정 및 등록해제\n(ASIS 0:정상 1:신구주병합에 의한 취소 2:지정취소)
	out->whyr_hi_prc = Str2Int(data->whyr_hi_prc, sizeof(data->whyr_hi_prc));	// 연중최고가, SIZE변경(7→9) 2016.02.01
	out->whyr_lo_prc = Str2Int(data->whyr_lo_prc, sizeof(data->whyr_lo_prc));	// 연중최저가, SIZE변경(7→9) 2016.02.01
	memcpy(out->whyr_hi_date, data->whyr_hi_date, sizeof(data->whyr_hi_date));	// 연중최고일, MMDD
	memcpy(out->whyr_lo_date, data->whyr_lo_date, sizeof(data->whyr_lo_date));	// 연중최저일, MMDD
	out->yr_cum_qty = Str2Dbl(data->yr_cum_qty, sizeof(data->yr_cum_qty), 0);	// 연누적거래량, SIZE변경(14→17) 2016.02.01
	out->yr_cum_trd_val = Str2Dbl(data->yr_cum_trd_val, sizeof(data->yr_cum_trd_val), 0);	// 연누적 거래 대금, 단위:원, SIZE변경(17→18) 2016.02.01
	out->pbl_ofr_clsf = data->pbl_ofr_clsf[0];	//공모구분, 0:비공모, 1:공모
	out->pbl_ofr_prc = Str2Int(data->pbl_ofr_prc, sizeof(data->pbl_ofr_prc));	// 공모가, 단위:원, SIZE변경(7→9) 2016.02.01
	out->affl_clsf = data->affl_clsf[0];	//소속부 구분, 4:등록기업부,5:지정기업부\n(ASIS 0:일반기업부, 1:벤처기업부)
	out->type_rgst_apnt = data->type_rgst_apnt[0];	//등록/지정유형, -항목명 변경(ASIS 지정유형)\n-값 추가\n 0:일반지정 1:코스닥이관 2:유가시장이관 3:코넥스이관\n (ASIS 0:일반지정 1:코스닥이관 2:거래소이관)
	out->prev_vlm = Str2Dbl(data->prev_vlm, sizeof(data->prev_vlm), 0);	// 전일거래량
	out->ceil_prc = Str2Int(data->ceil_prc, sizeof(data->ceil_prc));	// 상한가, SIZE변경(7→9) 2016.02.01
	out->flr_prc = Str2Int(data->flr_prc, sizeof(data->flr_prc));	// 하한가, SIZE변경(7→9) 2016.02.01
	out->iscnt = data->iscnt[0];	//불성실공시, 0:정상 1~5:불성실공시 1회~5회
	
	for ( i=0 ; i<5 ; i++ ) {
		memcpy(&out->iscnt_dates[i].iscnt_apnt_date, &data->iscnt_dates[i].iscnt_apnt_date, sizeof(data->iscnt_dates[i].iscnt_apnt_date));	// 불성실공시 지정일, YYYYMMDD
		memcpy(&out->iscnt_dates[i].iscnt_ed_date, &data->iscnt_dates[i].iscnt_ed_date, sizeof(data->iscnt_dates[i].iscnt_ed_date));	// 불성실공시 만료일, YYYYMMDD
	}	// 불성실공시일

	out->inv_atn_flg = data->inv_atn_flg[0];	//투자유의여부, 0:정상 1:투자유의
	
	for ( i=0 ; i<15 ; i++ ) {
		memcpy(&out->inv_atn_infos[i].inv_atn_rsn_code, &data->inv_atn_infos[i].inv_atn_rsn_code, sizeof(data->inv_atn_infos[i].inv_atn_rsn_code));	// 투자유의 사유코드, ※개발가이드 참조
		memcpy(&out->inv_atn_infos[i].inv_atn_apnt_date, &data->inv_atn_infos[i].inv_atn_apnt_date, sizeof(data->inv_atn_infos[i].inv_atn_apnt_date));	// 투자유의 지정일, YYYYMMDD
	}	// 투자유의

	out->mkt_cap_scale = data->mkt_cap_scale[0];	//시가총액규모, 지수제공시까지 SPACE\n(0:제외 1:대형주 2:중형주 3:소형주)
	memcpy(out->idx_ind_l, data->idx_ind_l, sizeof(data->idx_ind_l));	// 지수업종(대), 지수제공시까지 SPACE
	memcpy(out->idx_ind_m, data->idx_ind_m, sizeof(data->idx_ind_m));	// 지수업종(중), 지수제공시까지 SPACE
	memcpy(out->idx_ind_s, data->idx_ind_s, sizeof(data->idx_ind_s));	// 지수업종(소), 지수제공시까지 SPACE
	out->vtr_clsf = data->vtr_clsf[0];	//벤처구분, 0:일반기업, 1:벤처기업
	out->trend_clsf = data->trend_clsf[0];	//기세구분, 0:실세,1:기세,2:무거래
	out->arng_trd_flg = data->arng_trd_flg[0];	//정리매매여부, 0:정상,1:정리매매

	return 1;
}


// K-OTC 호가
int ParseA2013(const double& timestamp, const char* in_buff, DF_KOTC_ASK_PRC* out) {
	KOTC_ASK_PRC* data = (KOTC_ASK_PRC*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA구분, A2
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// 정보구분, 01:주식
	out->mkt_clsf = data->mkt_clsf[0];	//시장구분, 3:K-OTC
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// 종목코드, 표준코드
	out->data_snr = Str2Int(data->data_snr, sizeof(data->data_snr));	// 데이터 일련번호, 호가, 체결, 시장조치 포함한 일련번호
	out->proc_clsf = data->proc_clsf[0];	//처리구분, 1:정상 2:정정 3:취소
	out->ask_nr = Str2Int(data->ask_nr, sizeof(data->ask_nr));	// 호가번호, 정상 처리시 호가번호
	out->base_ask_nr = Str2Int(data->base_ask_nr, sizeof(data->base_ask_nr));	// 원호가번호, 정상:0, 정정/취소시 해당원호가 번호
	out->base_ask_prc = Str2Int(data->base_ask_prc, sizeof(data->base_ask_prc));	// 원호가가격, 정상:0, 정정/취소시 원가격, SIZE변경(7→9) 2016.02.01
	out->ask_bid_clsf = data->ask_bid_clsf[0];	//매도/매수 구분, 1:매도 2:매수
	out->prc = Str2Int(data->prc, sizeof(data->prc));	// 가격, 정상:주문가격 정정:정정가격, SIZE변경(7→9) 2016.02.01
	out->qty = Str2Dbl(data->qty, sizeof(data->qty), 0);	// 수량, 정상:주문수량 정정/취소:실정정/취소 수량
	memcpy(out->acpt_time, data->acpt_time, sizeof(data->acpt_time));	// 접수시각
	out->ask_tot_rsd = Str2Dbl(data->ask_tot_rsd, sizeof(data->ask_tot_rsd), 0);	// 매도총잔량
	out->bid_tot_rsd = Str2Dbl(data->bid_tot_rsd, sizeof(data->bid_tot_rsd), 0);	// 매수총잔량
	out->ask_prf_prc = Str2Int(data->ask_prf_prc, sizeof(data->ask_prf_prc));	// 매도우선호가, SIZE변경(7→9) 2016.02.01
	out->ask_prf_vol_rsd = Str2Dbl(data->ask_prf_vol_rsd, sizeof(data->ask_prf_vol_rsd), 0);	// 매도우선호가잔량
	out->bid_prf_prc = Str2Int(data->bid_prf_prc, sizeof(data->bid_prf_prc));	// 매수우선호가, SIZE변경(7→9) 2016.02.01
	out->bid_prf_vol_rsd = Str2Dbl(data->bid_prf_vol_rsd, sizeof(data->bid_prf_vol_rsd), 0);	// 매수우선호가잔량
	out->prc_band_vol_rsd = Str2Dbl(data->prc_band_vol_rsd, sizeof(data->prc_band_vol_rsd), 0);	// 가격대호가잔량, 정상:주문잔량 정정:정정잔량
	out->base_prc_band_vol_rsd = Str2Dbl(data->base_prc_band_vol_rsd, sizeof(data->base_prc_band_vol_rsd), 0);	// 원가격대호가잔량, 정상:0, 정정/취소시 원잔량
	memcpy(out->brkg_nr, data->brkg_nr, sizeof(data->brkg_nr));	// 증권사번호, 거래원코드 참조
	memcpy(out->brch_nm, data->brch_nm, sizeof(data->brch_nm));	// 지점명, SPACE

	return 1;
}


// K-OTC 체결
int ParseA3013(const double& timestamp, const char* in_buff, DF_KOTC_CCLS* out) {
	KOTC_CCLS* data = (KOTC_CCLS*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA구분, A3
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// 정보구분, 01:주식
	out->mkt_clsf = data->mkt_clsf[0];	//시장구분, 3:K-OTC
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// 종목코드, 표준코드
	out->data_snr = Str2Int(data->data_snr, sizeof(data->data_snr));	// 데이터 일련번호, 호가, 체결, 시장조치 포함한 일련번호
	out->ccls_nr = Str2Int(data->ccls_nr, sizeof(data->ccls_nr));	// 체결번호, 종목별 체결번호
	out->ccls_prc = Str2Int(data->ccls_prc, sizeof(data->ccls_prc));	// 체결가, SIZE변경(7→9) 2016.02.01
	out->ccls_qty = Str2Dbl(data->ccls_qty, sizeof(data->ccls_qty), 0);	// 체결량
	memcpy(out->ccls_time, data->ccls_time, sizeof(data->ccls_time));	// 체결시각
	out->ask_prc_nr = Str2Int(data->ask_prc_nr, sizeof(data->ask_prc_nr));	// 매도호가번호, 종목별 호가번호임
	out->bid_prc_nr = Str2Int(data->bid_prc_nr, sizeof(data->bid_prc_nr));	// 매수호가번호, 종목별 호가번호임
	out->open = Str2Int(data->open, sizeof(data->open));	// 고가, SIZE변경(7→9) 2016.02.01
	out->hi = Str2Int(data->hi, sizeof(data->hi));	// 저가, SIZE변경(7→9) 2016.02.01
	out->wavg_prc = Str2Int(data->wavg_prc, sizeof(data->wavg_prc));	// 가중평균주가, SIZE변경(7→9) 2016.02.01
	out->tot_ccls_cum_qty = Str2Dbl(data->tot_ccls_cum_qty, sizeof(data->tot_ccls_cum_qty), 0);	// 전체체결누적거래량
	out->tot_ccls_cum_trd_val = Str2Dbl(data->tot_ccls_cum_trd_val, sizeof(data->tot_ccls_cum_trd_val), 0);	// 전체체결누적거래대금
	out->ask_tot_rsd = Str2Dbl(data->ask_tot_rsd, sizeof(data->ask_tot_rsd), 0);	// 매도총잔량
	out->bid_tot_rsd = Str2Dbl(data->bid_tot_rsd, sizeof(data->bid_tot_rsd), 0);	// 매수총잔량
	out->ask_prf_prc = Str2Int(data->ask_prf_prc, sizeof(data->ask_prf_prc));	// 매도우선호가, SIZE변경(7→9) 2016.02.01
	out->ask_prf_vol_rsd = Str2Dbl(data->ask_prf_vol_rsd, sizeof(data->ask_prf_vol_rsd), 0);	// 매도우선호가잔량
	out->bid_prf_prc = Str2Int(data->bid_prf_prc, sizeof(data->bid_prf_prc));	// 매수우선호가, SIZE변경(7→9) 2016.02.01
	out->bid_prf_vol_rsd = Str2Dbl(data->bid_prf_vol_rsd, sizeof(data->bid_prf_vol_rsd), 0);	// 매수우선호가잔량
	out->prev_ctrs_clsf = data->prev_ctrs_clsf[0];	//전일대비구분, +:상승 -:하락 SPACE:보합
	out->prev_ctrs = Str2Int(data->prev_ctrs, sizeof(data->prev_ctrs));	// 전일대비, SIZE변경(7→9) 2016.02.01
	out->ccls_prc_ask_rsd = Str2Dbl(data->ccls_prc_ask_rsd, sizeof(data->ccls_prc_ask_rsd), 0);	// 체결가대매도잔량
	out->ccls_prc_bid_rsd = Str2Dbl(data->ccls_prc_bid_rsd, sizeof(data->ccls_prc_bid_rsd), 0);	// 체결가대매수잔량

	return 1;
}


// K-OTC 종목마감
int ParseA6013(const double& timestamp, const char* in_buff, DF_KOTC_STK_CLSG* out) {
	KOTC_STK_CLSG* data = (KOTC_STK_CLSG*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA구분, A6
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// 정보구분, 1
	out->mkt_clsf = data->mkt_clsf[0];	//시장구분, 3:K-OTC
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// 종목코드, 표준코드
	out->data_snr = Str2Int(data->data_snr, sizeof(data->data_snr));	// 데이터 일련번호, 호가,체결,장운영 포함한 일련번호
	out->stk_cls_wght_prc = Str2Int(data->stk_cls_wght_prc, sizeof(data->stk_cls_wght_prc));	// 종목마감 가중가, SIZE변경(7→9) 2016.02.01
	out->trend_flg = data->trend_flg[0];	//실세/기세구분, 0:가중평균가,1:기세,2:무거래

	return 1;
}


// K-OTC 장운영
int ParseA7013(const double& timestamp, const char* in_buff, DF_KOTC_MKT_OPR* out) {
	KOTC_MKT_OPR* data = (KOTC_MKT_OPR*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA구분, A7
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// 정보구분, 01:주식
	out->mkt_clsf = data->mkt_clsf[0];	//시장구분, 3:K-OTC
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// 종목코드, 표준코드
	out->data_snr = Str2Int(data->data_snr, sizeof(data->data_snr));	// 데이터 일련번호, 호가, 체결, 장운용 포함한 일련번호
	out->clsf = data->clsf[0];	//구분, 1:매매거래정지 2:매매거래정지후해제
	memcpy(out->rsn, data->rsn, sizeof(data->rsn));	// 사유

	return 1;
}


// K-OTC 시장조치
int ParseG5013(const double& timestamp, const char* in_buff, DF_KOTC_MKT_ACT* out) {
	KOTC_MKT_ACT* data = (KOTC_MKT_ACT*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA구분, G5
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// 정보구분, 01:주식
	out->mkt_clsf = data->mkt_clsf[0];	//시장구분, 3:K-OTC
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// 종목코드, 표준코드
	memcpy(out->data_kind, data->data_kind, sizeof(data->data_kind));	// 데이터 분류, 01:기준가 및 상하한가 변경 02:임시정지\n03:임시정지후 재개
	memcpy(out->chg_date, data->chg_date, sizeof(data->chg_date));	// 변경일, YYYYMMDD(데이터분류 01이 아니면 "0")
	memcpy(out->chg_time, data->chg_time, sizeof(data->chg_time));	// 변경시각, HHMMSSMM(데이터분류 01이 아니면 "0")
	out->bact_base_prc = Str2Int(data->bact_base_prc, sizeof(data->bact_base_prc));	// 조치전 기준가, 단위:원(데이터분류 01이 아니면 "0"), \nSIZE변경(7→9)  2016.02.01
	out->bact_ceil = Str2Int(data->bact_ceil, sizeof(data->bact_ceil));	// 조치전 상한가, 단위:원(데이터분류 01이 아니면 "0"), \nSIZE변경(7→9)  2016.02.01
	out->bact_flr = Str2Int(data->bact_flr, sizeof(data->bact_flr));	// 조치전 하한가, 단위:원(데이터분류 01이 아니면 "0"), \nSIZE변경(7→9)  2016.02.01
	out->aact_base_prc = Str2Int(data->aact_base_prc, sizeof(data->aact_base_prc));	// 조치후 기준가, 단위:원(데이터분류 01이 아니면 "0"), \nSIZE변경(7→9)  2016.02.01
	out->aact_ceil = Str2Int(data->aact_ceil, sizeof(data->aact_ceil));	// 조치후 상한가, 단위:원(데이터분류 01이 아니면 "0"), \nSIZE변경(7→9)  2016.02.01
	out->aact_flr = Str2Int(data->aact_flr, sizeof(data->aact_flr));	// 조치후 하한가, 단위:원(데이터분류 01이 아니면 "0"), \nSIZE변경(7→9)  2016.02.01

	return 1;
}


// K-OTC 공시 배치/실시간
int ParseE9013_F0013(const double& timestamp, const char* in_buff, DF_KOTC_DCLS_ARNG_RT* out) {
	KOTC_DCLS_ARNG_RT* data = (KOTC_DCLS_ARNG_RT*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA구분, E9:공시배치 F0:공시실시간
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// 정보구분, 01:주식
	out->mkt_clsf = data->mkt_clsf[0];	//시장구분, 3:K-OTC
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// 종목코드, 업무마감:999999999999
	out->dcls_snr = Str2Int(data->dcls_snr, sizeof(data->dcls_snr));	// 공시일련번호, 000001~999999\n업무마감:999999
	memcpy(out->rgst_date, data->rgst_date, sizeof(data->rgst_date));	// 등록일자, YYYYMMDD
	out->proc_clsf = data->proc_clsf[0];	//처리구분, 1:정상 2:정정 3:취소
	memcpy(out->rsn, data->rsn, sizeof(data->rsn));	// 사유, 코드값모음 참조
	out->line_nr = Str2Int(data->line_nr, sizeof(data->line_nr));	// 라인번호, 00:제목 01~20:내용 99:END
	memcpy(out->dcls_title, data->dcls_title, sizeof(data->dcls_title));	// 공시제목/내용

	return 1;
}


// KOSDAQ지수
int ParseE4012(const double& timestamp, const char* in_buff, DF_KOSDAQ_IDX* out) {
	KOSDAQ_IDX* data = (KOSDAQ_IDX*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA구분, ※개발가이드 참조
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// 정보구분, 01:주식
	out->mkt_clsf = data->mkt_clsf[0];	//시장구분, 1:유가증권 2:코스닥
	memcpy(out->ind_code, data->ind_code, sizeof(data->ind_code));	// 업종코드, ※개발가이드 참조
	memcpy(out->time, data->time, sizeof(data->time));	// 시간, ※개발가이드 참조
	out->idx = Str2Int(data->idx, sizeof(data->idx));	// 지수, 9(6)V9(2)
	out->ctrs = Str2SignDouble(data->sign, sizeof(data->sign) + sizeof(data->ctrs), 2);	// 대비, 999999V99
	out->ccls_qty = Str2Int(data->ccls_qty, sizeof(data->ccls_qty));	// 체결수량, 단위:천주
	out->trd_val = Str2Int(data->trd_val, sizeof(data->trd_val));	// 거래대금, 단위:백만원

	return 1;
}


// KOSDAQ예상지수
int ParseE5012(const double& timestamp, const char* in_buff, DF_KOSDAQ_EXP_IDX* out) {
	KOSDAQ_EXP_IDX* data = (KOSDAQ_EXP_IDX*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA구분, ※개발가이드 참조
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// 정보구분, 01:주식
	out->mkt_clsf = data->mkt_clsf[0];	//시장구분, 1:유가증권 2:코스닥
	memcpy(out->ind_code, data->ind_code, sizeof(data->ind_code));	// 업종코드, ※개발가이드 참조
	memcpy(out->time, data->time, sizeof(data->time));	// 시간, ※개발가이드 참조
	out->idx = Str2Int(data->idx, sizeof(data->idx));	// 지수, 9(6)V9(2)
	out->ctrs = Str2SignDouble(data->sign, sizeof(data->sign) + sizeof(data->ctrs), 2);	// 대비, 999999V99
	out->ccls_qty = Str2Int(data->ccls_qty, sizeof(data->ccls_qty));	// 체결수량, 단위:천주
	out->trd_val = Str2Int(data->trd_val, sizeof(data->trd_val));	// 거래대금, 단위:백만원

	return 1;
}


// 코스닥_거래원
int ParseB9012(const double& timestamp, const char* in_buff, DF_KOSDAQ_TRS* out) {
	int i=0;
	KOSDAQ_TRS* data = (KOSDAQ_TRS*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA구분, B9
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// 정보구분, 01:주식 02:ELW
	out->mkt_clsf = data->mkt_clsf[0];	//시장구분, 1:유가증권 2:코스닥
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// 종목코드, 표준코드
	out->snr = Str2Int(data->snr, sizeof(data->snr));	// 일련번호, 1~99999999 종목일련번호 2014.03.03

	for ( i=0 ; i<5 ; i++ ) {
		out->src_infos[i].ask_src_nr = Str2Int(data->src_infos[i].ask_src_nr, sizeof(data->src_infos[i].ask_src_nr)); // 매도거래원번호
		out->src_infos[i].ask_ccls_qty = Str2Dbl(data->src_infos[i].ask_ccls_qty, sizeof(data->src_infos[i].ask_ccls_qty), 0);	// 매도체결수량, 단위:주
		out->src_infos[i].ask_trd_val = Str2Dbl(data->src_infos[i].ask_trd_val, sizeof(data->src_infos[i].ask_trd_val), 0);	// 매도거래대금, 단위:원
		out->src_infos[i].bid_src_nr = Str2Int(data->src_infos[i].bid_src_nr, sizeof(data->src_infos[i].bid_src_nr));	// 매수거래원번호
		out->src_infos[i].bid_ccls_qty = Str2Dbl(data->src_infos[i].bid_ccls_qty, sizeof(data->src_infos[i].bid_ccls_qty), 0);	// 매수체결수량, 단위:주
		out->src_infos[i].bid_trd_val = Str2Dbl(data->src_infos[i].bid_trd_val, sizeof(data->src_infos[i].bid_trd_val), 0);	// 매수거래대금, 단위:원
	}	// 거래원정보 OCCURS

	return 1;
}


// 코스닥_종목별투자자별 종가
int ParseC1012(const double& timestamp, const char* in_buff, DF_KOSDAQ_BYSTK_BYINV_CLS* out) {
	int i=0;
	KOSDAQ_BYSTK_BYINV_CLS* data = (KOSDAQ_BYSTK_BYINV_CLS*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA구분, C1
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// 정보구분, 01:주식 02:ELW
	out->mkt_clsf = data->mkt_clsf[0];	//시장구분, 1:유가증권 2:코스닥
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// 종목코드, 표준코드
	out->snr = Str2Int(data->snr, sizeof(data->snr));	// 일련번호, 1~99999999 종목일련번호 2014.03.03

    for ( i=0 ; i<12 ; i++ ) {
		memcpy(&out->inv_infos[i].inv_code, &data->inv_infos[i].inv_code, sizeof(data->inv_infos[i].inv_code));	// 투자자코드, ※코드값모음 참조\n*코드'7000'시 수량, 대금정보 항목 0으로 전송 (20181210)
		out->inv_infos[i].ask_ccls_qty = Str2Dbl(data->inv_infos[i].ask_ccls_qty, sizeof(data->inv_infos[i].ask_ccls_qty), 0);	// 매도체결수량, 단위:주
		out->inv_infos[i].ask_trd_val = Str2Dbl(data->inv_infos[i].ask_trd_val, sizeof(data->inv_infos[i].ask_trd_val), 0);	// 매도거래대금, 단위:원
		out->inv_infos[i].bid_ccls_qty = Str2Dbl(data->inv_infos[i].bid_ccls_qty, sizeof(data->inv_infos[i].bid_ccls_qty), 0);	// 매수체결수량, 단위:주
		out->inv_infos[i].bid_trd_val = Str2Dbl(data->inv_infos[i].bid_trd_val, sizeof(data->inv_infos[i].bid_trd_val), 0);	// 매수거래대금, 단위:원
	}	// 투자자 OCCURS 12

	return 1;
}


// 코스닥_프로그램매매 호가
int ParseC3012(const double& timestamp, const char* in_buff, DF_KOSDAQ_PRGTRD_ASK* out) {
	KOSDAQ_PRGTRD_ASK* data = (KOSDAQ_PRGTRD_ASK*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA구분, C3
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// 정보구분, 01:주식
	out->mkt_clsf = data->mkt_clsf[0];	//시장구분, 1:유가증권 2:코스닥
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// 종목코드
	out->snr = Str2Int(data->snr, sizeof(data->snr));	// 일련번호, 1~99999999 종목일련번호 2014.03.03
	out->idx_abtg_ask_rsd = Str2Dbl(data->idx_abtg_ask_rsd, sizeof(data->idx_abtg_ask_rsd), 0);	// 지수차익매도호가잔량
	out->idx_abtg_bid_rsd = Str2Dbl(data->idx_abtg_bid_rsd, sizeof(data->idx_abtg_bid_rsd), 0);	// 지수차익매수호가잔량
	out->idx_nabtg_ask_rsd = Str2Dbl(data->idx_nabtg_ask_rsd, sizeof(data->idx_nabtg_ask_rsd), 0);	// 지수비차익매도호가잔량
	out->idx_nabtg_bid_rsd = Str2Dbl(data->idx_nabtg_bid_rsd, sizeof(data->idx_nabtg_bid_rsd), 0);	// 지수비차익매수호가잔량
	out->idx_abtg_ask_qty = Str2Dbl(data->idx_abtg_ask_qty, sizeof(data->idx_abtg_ask_qty), 0);	// 지수차익매도호가수량
	out->idx_abtg_bid_qty = Str2Dbl(data->idx_abtg_bid_qty, sizeof(data->idx_abtg_bid_qty), 0);	// 지수차익매수호가수량
	out->idx_nabtg_ask_qty = Str2Dbl(data->idx_nabtg_ask_qty, sizeof(data->idx_nabtg_ask_qty), 0);	// 지수비차익매도호가수량
	out->idx_nabtg_bid_qty = Str2Dbl(data->idx_nabtg_bid_qty, sizeof(data->idx_nabtg_bid_qty), 0);	// 지수비차익매수호가수량
	out->prior_idx_abtg_ask_rsd = Str2Dbl(data->prior_idx_abtg_ask_rsd, sizeof(data->prior_idx_abtg_ask_rsd), 0);	// 지수차익매도호가잔량
	out->prior_idx_abtg_bid_rsd = Str2Dbl(data->prior_idx_abtg_bid_rsd, sizeof(data->prior_idx_abtg_bid_rsd), 0);	// 지수차익매수호가잔량
	out->prior_idx_nabtg_ask_rsd = Str2Dbl(data->prior_idx_nabtg_ask_rsd, sizeof(data->prior_idx_nabtg_ask_rsd), 0);	// 지수비차익매도호가잔량
	out->prior_idx_nabtg_bid_rsd = Str2Dbl(data->prior_idx_nabtg_bid_rsd, sizeof(data->prior_idx_nabtg_bid_rsd), 0);	// 지수비차익매수호가잔량
	out->idx_abtg_ask_ccls_qty = Str2Dbl(data->idx_abtg_ask_ccls_qty, sizeof(data->idx_abtg_ask_ccls_qty), 0);	// "지수차익매도위탁 체결수량"
	out->idx_abtg_ask_self_ccls_qty = Str2Dbl(data->idx_abtg_ask_self_ccls_qty, sizeof(data->idx_abtg_ask_self_ccls_qty), 0);	// "지수차익매도자기 체결수량"
	out->idx_abtg_bid_ccls_qty = Str2Dbl(data->idx_abtg_bid_ccls_qty, sizeof(data->idx_abtg_bid_ccls_qty), 0);	// "지수차익매수위탁 체결수량"
	out->idx_abtg_bid_self_ccls_qty = Str2Dbl(data->idx_abtg_bid_self_ccls_qty, sizeof(data->idx_abtg_bid_self_ccls_qty), 0);	// "지수차익매수자기 체결수량"
	out->idx_nabtg_ask_ccls_qty = Str2Dbl(data->idx_nabtg_ask_ccls_qty, sizeof(data->idx_nabtg_ask_ccls_qty), 0);	// "지수비차익매도위탁 체결수량"
	out->idx_nabtg_ask_self_ccls_qty = Str2Dbl(data->idx_nabtg_ask_self_ccls_qty, sizeof(data->idx_nabtg_ask_self_ccls_qty), 0);	// "지수비차익매도자기 체결수량"
	out->idx_nabtg_bid_ccls_qty = Str2Dbl(data->idx_nabtg_bid_ccls_qty, sizeof(data->idx_nabtg_bid_ccls_qty), 0);	// "지수비차익매수위탁 체결수량"
	out->idx_nabtg_bid_self_ccls_qty = Str2Dbl(data->idx_nabtg_bid_self_ccls_qty, sizeof(data->idx_nabtg_bid_self_ccls_qty), 0);	// "지수비차익매수자기 체결수량"
	out->idx_abtg_ask_ccls_val = Str2Dbl(data->idx_abtg_ask_ccls_val, sizeof(data->idx_abtg_ask_ccls_val), 0);	// "지수차익매도위탁 체결금액"
	out->idx_abtg_ask_self_ccls_val = Str2Dbl(data->idx_abtg_ask_self_ccls_val, sizeof(data->idx_abtg_ask_self_ccls_val), 0);	// "지수차익매도자기 체결금액"
	out->idx_abtg_bid_ccls_val = Str2Dbl(data->idx_abtg_bid_ccls_val, sizeof(data->idx_abtg_bid_ccls_val), 0);	// "지수차익매수위탁 체결금액"
	out->idx_abtg_bid_self_ccls_val = Str2Dbl(data->idx_abtg_bid_self_ccls_val, sizeof(data->idx_abtg_bid_self_ccls_val), 0);	// "지수차익매수자기 체결금액"
	out->idx_nabtg_ask_ccls_val = Str2Dbl(data->idx_nabtg_ask_ccls_val, sizeof(data->idx_nabtg_ask_ccls_val), 0);	// "지수비차익매도위탁 체결금액"
	out->idx_nabtg_ask_self_ccls_val = Str2Dbl(data->idx_nabtg_ask_self_ccls_val, sizeof(data->idx_nabtg_ask_self_ccls_val), 0);	// "지수비차익매도자기 체결금액"
	out->idx_nabtg_bid_ccls_val = Str2Dbl(data->idx_nabtg_bid_ccls_val, sizeof(data->idx_nabtg_bid_ccls_val), 0);	// "지수비차익매수위탁 체결금액"
	out->idx_nabtg_bid_self_ccls_val = Str2Dbl(data->idx_nabtg_bid_self_ccls_val, sizeof(data->idx_nabtg_bid_self_ccls_val), 0);	// "지수비차익매수자기 체결금액"
	out->post_idx_abtg_ask_rsd = Str2Dbl(data->post_idx_abtg_ask_rsd, sizeof(data->post_idx_abtg_ask_rsd), 0);	// 지수차익매도호가잔량, 2011.05.30 신규
	out->post_idx_abtg_bid_rsd = Str2Dbl(data->post_idx_abtg_bid_rsd, sizeof(data->post_idx_abtg_bid_rsd), 0);	// 지수차익매수호가잔량, 2011.05.30 신규
	out->post_idx_nabtg_ask_rsd = Str2Dbl(data->post_idx_nabtg_ask_rsd, sizeof(data->post_idx_nabtg_ask_rsd), 0);	// 지수비차익매도호가잔량, 2011.05.30 신규
	out->post_idx_nabtg_bid_rsd = Str2Dbl(data->post_idx_nabtg_bid_rsd, sizeof(data->post_idx_nabtg_bid_rsd), 0);	// 지수비차익매수호가잔량, 2011.05.30 신규

	return 1;
}


// 코스닥_프로그램매매 전체집계
int ParseJ0012(const double& timestamp, const char* in_buff, DF_KOSDAQ_PRGTRD_TOT* out) {
	KOSDAQ_PRGTRD_TOT* data = (KOSDAQ_PRGTRD_TOT*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA구분, J0
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// 정보구분, 01:주식
	out->mkt_clsf = data->mkt_clsf[0];	//시장구분, 1:유가증권 2:코스닥
	out->idx_abtg_ask_rsd = Str2Dbl(data->idx_abtg_ask_rsd, sizeof(data->idx_abtg_ask_rsd), 0);	// 지수차익매도호가잔량
	out->idx_abtg_bid_rsd = Str2Dbl(data->idx_abtg_bid_rsd, sizeof(data->idx_abtg_bid_rsd), 0);	// 지수차익매수호가잔량
	out->idx_nabtg_ask_rsd = Str2Dbl(data->idx_nabtg_ask_rsd, sizeof(data->idx_nabtg_ask_rsd), 0);	// 지수비차익매도호가잔량
	out->idx_nabtg_bid_rsd = Str2Dbl(data->idx_nabtg_bid_rsd, sizeof(data->idx_nabtg_bid_rsd), 0);	// 지수비차익매수호가잔량
	out->idx_abtg_ask_qty = Str2Dbl(data->idx_abtg_ask_qty, sizeof(data->idx_abtg_ask_qty), 0);	// 지수차익매도호가수량
	out->idx_abtg_bid_qty = Str2Dbl(data->idx_abtg_bid_qty, sizeof(data->idx_abtg_bid_qty), 0);	// 지수차익매수호가수량
	out->idx_nabtg_ask_qty = Str2Dbl(data->idx_nabtg_ask_qty, sizeof(data->idx_nabtg_ask_qty), 0);	// 지수비차익매도호가수량
	out->idx_nabtg_bid_qty = Str2Dbl(data->idx_nabtg_bid_qty, sizeof(data->idx_nabtg_bid_qty), 0);	// 지수비차익매수호가수량
	out->prior_idx_abtg_ask_rsd = Str2Dbl(data->prior_idx_abtg_ask_rsd, sizeof(data->prior_idx_abtg_ask_rsd), 0);	// 지수차익매도호가잔량
	out->prior_idx_abtg_bid_rsd = Str2Dbl(data->prior_idx_abtg_bid_rsd, sizeof(data->prior_idx_abtg_bid_rsd), 0);	// 지수차익매수호가잔량
	out->prior_idx_nabtg_ask_rsd = Str2Dbl(data->prior_idx_nabtg_ask_rsd, sizeof(data->prior_idx_nabtg_ask_rsd), 0);	// 지수비차익매도호가잔량
	out->prior_idx_nabtg_bid_rsd = Str2Dbl(data->prior_idx_nabtg_bid_rsd, sizeof(data->prior_idx_nabtg_bid_rsd), 0);	// 지수비차익매수호가잔량
	out->idx_abtg_ask_ccls_qty = Str2Dbl(data->idx_abtg_ask_ccls_qty, sizeof(data->idx_abtg_ask_ccls_qty), 0);	// "지수차익매도위탁 체결수량"
	out->idx_abtg_ask_self_ccls_qty = Str2Dbl(data->idx_abtg_ask_self_ccls_qty, sizeof(data->idx_abtg_ask_self_ccls_qty), 0);	// "지수차익매도자기 체결수량"
	out->idx_abtg_bid_ccls_qty = Str2Dbl(data->idx_abtg_bid_ccls_qty, sizeof(data->idx_abtg_bid_ccls_qty), 0);	// "지수차익매수위탁 체결수량"
	out->idx_abtg_bid_self_ccls_qty = Str2Dbl(data->idx_abtg_bid_self_ccls_qty, sizeof(data->idx_abtg_bid_self_ccls_qty), 0);	// "지수차익매수자기 체결수량"
	out->idx_nabtg_ask_ccls_qty = Str2Dbl(data->idx_nabtg_ask_ccls_qty, sizeof(data->idx_nabtg_ask_ccls_qty), 0);	// "지수비차익매도위탁 체결수량"
	out->idx_nabtg_ask_self_ccls_qty = Str2Dbl(data->idx_nabtg_ask_self_ccls_qty, sizeof(data->idx_nabtg_ask_self_ccls_qty), 0);	// "지수비차익매도자기 체결수량"
	out->idx_nabtg_bid_ccls_qty = Str2Dbl(data->idx_nabtg_bid_ccls_qty, sizeof(data->idx_nabtg_bid_ccls_qty), 0);	// "지수비차익매수위탁 체결수량"
	out->idx_nabtg_bid_self_ccls_qty = Str2Dbl(data->idx_nabtg_bid_self_ccls_qty, sizeof(data->idx_nabtg_bid_self_ccls_qty), 0);	// "지수비차익매수자기 체결수량"
	out->idx_abtg_ask_ccls_val = Str2Dbl(data->idx_abtg_ask_ccls_val, sizeof(data->idx_abtg_ask_ccls_val), 0);	// "지수차익매도위탁 체결금액"
	out->idx_abtg_ask_self_ccls_val = Str2Dbl(data->idx_abtg_ask_self_ccls_val, sizeof(data->idx_abtg_ask_self_ccls_val), 0);	// "지수차익매도자기 체결금액"
	out->idx_abtg_bid_ccls_val = Str2Dbl(data->idx_abtg_bid_ccls_val, sizeof(data->idx_abtg_bid_ccls_val), 0);	// "지수차익매수위탁 체결금액"
	out->idx_abtg_bid_self_ccls_val = Str2Dbl(data->idx_abtg_bid_self_ccls_val, sizeof(data->idx_abtg_bid_self_ccls_val), 0);	// "지수차익매수자기 체결금액"
	out->idx_nabtg_ask_ccls_val = Str2Dbl(data->idx_nabtg_ask_ccls_val, sizeof(data->idx_nabtg_ask_ccls_val), 0);	// "지수비차익매도위탁 체결금액"
	out->idx_nabtg_ask_self_ccls_val = Str2Dbl(data->idx_nabtg_ask_self_ccls_val, sizeof(data->idx_nabtg_ask_self_ccls_val), 0);	// "지수비차익매도자기 체결금액"
	out->idx_nabtg_bid_ccls_val = Str2Dbl(data->idx_nabtg_bid_ccls_val, sizeof(data->idx_nabtg_bid_ccls_val), 0);	// "지수비차익매수위탁 체결금액"
	out->idx_nabtg_bid_self_ccls_val = Str2Dbl(data->idx_nabtg_bid_self_ccls_val, sizeof(data->idx_nabtg_bid_self_ccls_val), 0);	// "지수비차익매수자기 체결금액"
	out->post_idx_abtg_ask_rsd = Str2Dbl(data->post_idx_abtg_ask_rsd, sizeof(data->post_idx_abtg_ask_rsd), 0);	// 지수차익매도호가잔량
	out->post_idx_abtg_bid_rsd = Str2Dbl(data->post_idx_abtg_bid_rsd, sizeof(data->post_idx_abtg_bid_rsd), 0);	// 지수차익매수호가잔량
	out->post_idx_nabtg_ask_rsd = Str2Dbl(data->post_idx_nabtg_ask_rsd, sizeof(data->post_idx_nabtg_ask_rsd), 0);	// 지수비차익매도호가잔량
	out->post_idx_nabtg_bid_rsd = Str2Dbl(data->post_idx_nabtg_bid_rsd, sizeof(data->post_idx_nabtg_bid_rsd), 0);	// 지수비차익매수호가잔량

	return 1;
}


// 코스닥_프로그램매매 사전사후공시
int ParseC5012(const double& timestamp, const char* in_buff, DF_KOSDAQ_PRGTRD_DCLS* out) {
	KOSDAQ_PRGTRD_DCLS* data = (KOSDAQ_PRGTRD_DCLS*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA구분, C5
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// 정보구분, 01:주식
	out->mkt_clsf = data->mkt_clsf[0];	//시장구분, 1:유가증권 2:코스닥
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// 종목코드
	out->snr = Str2Int(data->snr, sizeof(data->snr));	// 일련번호, 1~99999999 종목일련번호 2014.03.03
	out->prior_dcls_new_ask_qty = Str2Dbl(data->prior_dcls_new_ask_qty, sizeof(data->prior_dcls_new_ask_qty), 0);	// "사전공시신규호가 매도수량", 단위 : 주\n항목명변경:매도공시사전수량->사전공시신규호가매도수량
	out->prior_dcls_new_bid_qty = Str2Dbl(data->prior_dcls_new_bid_qty, sizeof(data->prior_dcls_new_bid_qty), 0);	// "사전공시신규호가 매수수량", 단위 : 주\n항목명변경:매수공시사전수량->사전공시신규호가매수수량
	out->prior_dcls_sbmt_ask_qty = Str2Dbl(data->prior_dcls_sbmt_ask_qty, sizeof(data->prior_dcls_sbmt_ask_qty), 0);	// "사전공시기제출호가 매도수량", 단위 : 주\n항목명변경:매도공시사전정정수량->사전공시기제출호가매도수량
	out->prior_dcls_sbmt_bid_qty = Str2Dbl(data->prior_dcls_sbmt_bid_qty, sizeof(data->prior_dcls_sbmt_bid_qty), 0);	// "사전공시기제출호가 매수수량", 단위 : 주\n항목명변경:매수공시사전정정수량->사전공시기제출호가매수수량
	out->post_dcls_ask_qty = Str2Dbl(data->post_dcls_ask_qty, sizeof(data->post_dcls_ask_qty), 0);	// 사후공시매도수량, 단위 : 주,  신규				2011.05.03
	out->post_dcls_bid_qty = Str2Dbl(data->post_dcls_bid_qty, sizeof(data->post_dcls_bid_qty), 0);	// 사후공시매수수량, 단위 : 주,  신규				2011.05.03

	return 1;
}


// 코스닥 프로그램매매 투자자별 매매현황
int ParseP0012(const double& timestamp, const char* in_buff, DF_KOSDAQ_PRGTRD_BYINV_STAT* out) {
	KOSDAQ_PRGTRD_BYINV_STAT* data = (KOSDAQ_PRGTRD_BYINV_STAT*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA구분, P0
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// 정보구분, 01:주식
	out->mkt_clsf = data->mkt_clsf[0];	//시장구분, 1:유가증권 2:코스닥
	memcpy(out->cmpt_time, data->cmpt_time, sizeof(data->cmpt_time));	// 산출시각, 90초 주기
	memcpy(out->inv_clsf_code, data->inv_clsf_code, sizeof(data->inv_clsf_code));	// 투자자구분코드, ※코드값모음 참조\n*코드'7000'시 수량, 대금정보 항목 0으로 전송 (20181210)
	out->ask_abtg_ccls_qty = Str2Dbl(data->ask_abtg_ccls_qty, sizeof(data->ask_abtg_ccls_qty), 0);	// 매도차익체결수량
	out->ask_abtg_trd_val = Str2Dbl(data->ask_abtg_trd_val, sizeof(data->ask_abtg_trd_val), 0);	// 매도차익거래대금
	out->ask_nabtg_ccls_qty = Str2Dbl(data->ask_nabtg_ccls_qty, sizeof(data->ask_nabtg_ccls_qty), 0);	// 매도비차익체결수량
	out->ask_nabtg_trd_val = Str2Dbl(data->ask_nabtg_trd_val, sizeof(data->ask_nabtg_trd_val), 0);	// 매도비차익거래대금
	out->bid_abtg_ccls_qty = Str2Dbl(data->bid_abtg_ccls_qty, sizeof(data->bid_abtg_ccls_qty), 0);	// 매수차익체결수량
	out->bid_abtg_trd_val = Str2Dbl(data->bid_abtg_trd_val, sizeof(data->bid_abtg_trd_val), 0);	// 매수차익거래대금
	out->bid_nabtg_ccls_qty = Str2Dbl(data->bid_nabtg_ccls_qty, sizeof(data->bid_nabtg_ccls_qty), 0);	// 매수비차익체결수량
	out->bid_nabtg_trd_val = Str2Dbl(data->bid_nabtg_trd_val, sizeof(data->bid_nabtg_trd_val), 0);	// 매수비차익거래대금

	return 1;
}


// 코스닥_종목상태정보(VI)
int ParseR8012(const double& timestamp, const char* in_buff, DF_KOSDAQ_STK_STAT_INFO* out) {
	KOSDAQ_STK_STAT_INFO* data = (KOSDAQ_STK_STAT_INFO*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA구분, R8
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// 정보구분, 01:주식
	out->mkt_clsf = data->mkt_clsf[0];	//시장구분, 1:유가증권 2:코스닥
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// 종목코드
	out->stk_snr = Str2Int(data->stk_snr, sizeof(data->stk_snr));	// 종목일련번호, 종목배치(A0)의 종목일련번호
	memcpy(out->brd_id, data->brd_id, sizeof(data->brd_id));	// 보드ID, ※ 코드값모음 참조
	out->trd_ccls_proc_time = Str2Int(data->trd_ccls_proc_time, sizeof(data->trd_ccls_proc_time));	// 매매체결처리시각, 매매체결처리시각
	out->vi_cncl_time = Str2Int(data->vi_cncl_time, sizeof(data->vi_cncl_time));	// VI해제시각
	out->vi_aply_clsf_code = data->vi_aply_clsf_code[0];	//VI적용구분코드, 1:VI-발동, 2:VI-해제
	out->vi_type_code = Str2Int(data->vi_type_code, sizeof(data->vi_type_code));	// VI종류코드, 1:정적VI, 2:동적VI, 3:정적&동적VI
	out->stt_vi_base_prc = Str2Int(data->stt_vi_base_prc, sizeof(data->stt_vi_base_prc));	// 정적VI발동기준가격
	out->dyn_vi_base_prc = Str2Int(data->dyn_vi_base_prc, sizeof(data->dyn_vi_base_prc));	// 동적VI발동기준가격
	out->vi_prc = Str2Int(data->vi_prc, sizeof(data->vi_prc));	// VI발동가격
	memcpy(out->stt_vi_dspr, data->stt_vi_dspr, sizeof(data->stt_vi_dspr));	// 정적VI발동괴리율, 정적VI발동 괴리율\n부호자리(양수:0, 음수:-) + 99999.999999(유효숫자 12자리)
	memcpy(out->dyn_vi_dspr, data->dyn_vi_dspr, sizeof(data->dyn_vi_dspr));	// 동적VI발동괴리율, 동적VI발동 괴리율\n부호자리(양수:0, 음수:-) + 99999.999999(유효숫자 12자리)

	return 1;
}
