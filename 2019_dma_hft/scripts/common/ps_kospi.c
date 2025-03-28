// ps_kospi.c
// 유가증권주식
// 주석에 \n이 들어간건 나중에 이쁘게 바꿔야함

#include "ps_kospi.h"


// KRX 300 TR예상지수
int ParseBD011(const double& timestamp, const char* in_buff, DF_KRX300_TR_EXP_IDX* out) {
	KRX300_TR_EXP_IDX* data = (KRX300_TR_EXP_IDX*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA구분, ※개발가이드 참조
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// 정보구분, 01:주식
	out->mkt_clsf = data->mkt_clsf[0];	//시장구분, 1:유가증권 2:코스닥 9:해외주가지수 2012.04.30 추가
	memcpy(out->ind_clsf, data->ind_clsf, sizeof(data->ind_clsf));	// 업종코드, ※개발가이드 참조
	memcpy(out->time, data->time, sizeof(data->time));	// 시간, ※개발가이드 참조 ※해외주가지수일 경우 GMT시간
	out->idx = Str2Dbl(data->idx, sizeof(data->idx), 2);	// 지수, 9(6)V9(2)
	out->crst = Str2SignDouble(data->sign, sizeof(data->sign) + sizeof(data->crst), 2);	// 대비, 999999V99
	out->ccls_qty = Str2Int(data->ccls_qty, sizeof(data->ccls_qty));	// 체결수량, 단위:천주 ※해외주가지수일 경우 FILLER처리
	out->trd_val = Str2Int(data->trd_val, sizeof(data->trd_val));	// 거래대금, 단위:백만원 ※해외주가지수일 경우 FILLER처리

	return 1;
}


// KRX 300 TR지수
int ParseBC011(const double& timestamp, const char* in_buff, DF_KRX300_TR_IDX* out) {
	KRX300_TR_IDX* data = (KRX300_TR_IDX*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA구분, ※개발가이드 참조
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// 정보구분, 01:주식
	out->mkt_clsf = data->mkt_clsf[0];	//시장구분, 1:유가증권 2:코스닥 9:해외주가지수 2012.04.30 추가
	memcpy(out->ind_clsf, data->ind_clsf, sizeof(data->ind_clsf));	// 업종코드, ※개발가이드 참조
	memcpy(out->time, data->time, sizeof(data->time));	// 시간, ※개발가이드 참조 ※해외주가지수일 경우 GMT시간
	out->idx = Str2Dbl(data->idx, sizeof(data->idx), 2);	// 지수, 9(6)V9(2)
	out->crst = Str2SignDouble(data->sign, sizeof(data->sign) + sizeof(data->crst), 2);	// 대비, 999999V99
	out->ccls_qty = Str2Int(data->ccls_qty, sizeof(data->ccls_qty));	// 체결수량, 단위:천주 ※해외주가지수일 경우 FILLER처리
	out->trd_val = Str2Int(data->trd_val, sizeof(data->trd_val));	// 거래대금, 단위:백만원 ※해외주가지수일 경우 FILLER처리

	return 1;
}


// 코스피 TR예상지수
int ParseAX011(const double& timestamp, const char* in_buff, DF_KOSPI_TR_EXP_IDX* out) {
	KOSPI_TR_EXP_IDX* data = (KOSPI_TR_EXP_IDX*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA구분, ※개발가이드 참조
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// 정보구분, 01:주식
	out->mkt_clsf = data->mkt_clsf[0];	//시장구분, 1:유가증권 2:코스닥 9:해외주가지수 2012.04.30 추가
	memcpy(out->ind_clsf, data->ind_clsf, sizeof(data->ind_clsf));	// 업종코드, ※개발가이드 참조
	memcpy(out->time, data->time, sizeof(data->time));	// 시간, ※개발가이드 참조 ※해외주가지수일 경우 GMT시간
	out->idx = Str2Dbl(data->idx, sizeof(data->idx), 2);	// 지수, 9(6)V9(2)
	out->crst = Str2SignDouble(data->sign, sizeof(data->sign) + sizeof(data->crst), 2);	// 대비, 999999V99
	out->ccls_qty = Str2Int(data->ccls_qty, sizeof(data->ccls_qty));	// 체결수량, 단위:천주 ※해외주가지수일 경우 FILLER처리
	out->trd_val = Str2Int(data->trd_val, sizeof(data->trd_val));	// 거래대금, 단위:백만원 ※해외주가지수일 경우 FILLER처리

	return 1;
}


// 코스피 TR지수
int ParseAW011(const double& timestamp, const char* in_buff, DF_KOSPI_TR_IDX* out) {
	KOSPI_TR_IDX* data = (KOSPI_TR_IDX*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA구분, ※개발가이드 참조
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// 정보구분, 01:주식
	out->mkt_clsf = data->mkt_clsf[0];	//시장구분, 1:유가증권 2:코스닥 9:해외주가지수 2012.04.30 추가
	memcpy(out->ind_clsf, data->ind_clsf, sizeof(data->ind_clsf));	// 업종코드, ※개발가이드 참조
	memcpy(out->time, data->time, sizeof(data->time));	// 시간, ※개발가이드 참조 ※해외주가지수일 경우 GMT시간
	out->idx = Str2Dbl(data->idx, sizeof(data->idx), 2);	// 지수, 9(6)V9(2)
	out->crst = Str2SignDouble(data->sign, sizeof(data->sign) + sizeof(data->crst), 2);	// 대비, 999999V99
	out->ccls_qty = Str2Int(data->ccls_qty, sizeof(data->ccls_qty));	// 체결수량, 단위:천주 ※해외주가지수일 경우 FILLER처리
	out->trd_val = Str2Int(data->trd_val, sizeof(data->trd_val));	// 거래대금, 단위:백만원 ※해외주가지수일 경우 FILLER처리

	return 1;
}


// KRX300예상지수
int ParseAB011(const double& timestamp, const char* in_buff, DF_KRX300_EXP_IDX* out) {
	KRX300_EXP_IDX* data = (KRX300_EXP_IDX*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA구분, ※개발가이드 참조
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// 정보구분, 01:주식
	out->mkt_clsf = data->mkt_clsf[0];	//시장구분, 1:유가증권 2:코스닥 9:해외주가지수 2012.04.30 추가
	memcpy(out->ind_clsf, data->ind_clsf, sizeof(data->ind_clsf));	// 업종코드, ※개발가이드 참조
	memcpy(out->time, data->time, sizeof(data->time));	// 시간, ※개발가이드 참조 ※해외주가지수일 경우 GMT시간
	out->idx = Str2Dbl(data->idx, sizeof(data->idx), 2);	// 지수, 9(6)V9(2)
	out->crst = Str2SignDouble(data->sign, sizeof(data->sign) + sizeof(data->crst), 2);	// 대비, 999999V99
	out->ccls_qty = Str2Int(data->ccls_qty, sizeof(data->ccls_qty));	// 체결수량, 단위:천주 ※해외주가지수일 경우 FILLER처리
	out->trd_val = Str2Int(data->trd_val, sizeof(data->trd_val));	// 거래대금, 단위:백만원 ※해외주가지수일 경우 FILLER처리

	return 1;
}


// KRX300지수
int ParseAA011(const double& timestamp, const char* in_buff, DF_KRX300_IDX* out) {
	KRX300_IDX* data = (KRX300_IDX*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA구분, ※개발가이드 참조
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// 정보구분, 01:주식
	out->mkt_clsf = data->mkt_clsf[0];	//시장구분, 1:유가증권 2:코스닥 9:해외주가지수 2012.04.30 추가
	memcpy(out->ind_clsf, data->ind_clsf, sizeof(data->ind_clsf));	// 업종코드, ※개발가이드 참조
	memcpy(out->time, data->time, sizeof(data->time));	// 시간, ※개발가이드 참조 ※해외주가지수일 경우 GMT시간
	out->idx = Str2Dbl(data->idx, sizeof(data->idx), 2);	// 지수, 9(6)V9(2)
	out->crst = Str2SignDouble(data->sign, sizeof(data->sign) + sizeof(data->crst), 2);	// 대비, 999999V99
	out->ccls_qty = Str2Int(data->ccls_qty, sizeof(data->ccls_qty));	// 체결수량, 단위:천주 ※해외주가지수일 경우 FILLER처리
	out->trd_val = Str2Int(data->trd_val, sizeof(data->trd_val));	// 거래대금, 단위:백만원 ※해외주가지수일 경우 FILLER처리

	return 1;
}


// 코스피_종목 이벤트 정보
int ParseI6011(const double& timestamp, const char* in_buff, DF_KOSPI_STK_EVT_INFO* out) {
	KOSPI_STK_EVT_INFO* data = (KOSPI_STK_EVT_INFO*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA구분, I6
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// 정보구분, 01:주식
	out->mkt_clsf = data->mkt_clsf[0];	//시장구분, 1:유가증권 2:코스닥
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// 종목코드, 표준코드
	out->snr = Str2Int(data->snr, sizeof(data->snr));	// 일련번호, 1~99999999 건수체크용
	memcpy(out->evt_code, data->evt_code, sizeof(data->evt_code));	// 이벤트종류코드, 01:거래정지 \n02:관리종목 \n03:불성실공시법인 \n04:정리매매\n05:우회상장 \n06:대용증권효력정지 \n07:지배구조우량기업\n08:차입공매도불가 \n09:Regulation S \n10:벤쳐기업지정\n11:투자주의환기종목\n12:단기과열종목 (2012.11.05추가)\n13:휴장 (2016.06.27추가)\n14:초저유동성종목 (2016.06.27추가)\n15:투자유의채권 (2016.11.28추가)\n16:이상급등종목 (2017.03.27추가)\n17:공매도과열종목 (2017.03.27 추가)\n18: LP선택제 (2017.06.26 추가)
	memcpy(out->evt_trgg_code, data->evt_trgg_code, sizeof(data->evt_trgg_code));	// 이벤트발생사유코드, ※ 별첨 코드갑모음의 이벤트별사유코드 참조\n※ 이벤트종류코드 03,04,07,08,09,17에 대해서는 '0000' SET\n※ 코드의 종류에 따라 자릿수가 다릅니다. 데이터 타입이\nX모드 이기 때문에 죄측정렬됩니다. 이점 유의하여 주십시요.\n(거래정지사유코드(3자리), 관리종목지정사유코드(4자리),\n우회상장유형코드(1자리), 대용증권효력정지사유코드(2자리),\n투자주의환기종목사유코드(4자리))
	memcpy(out->st_date, data->st_date, sizeof(data->st_date));	// 개시일자,시작일자,적용일자, YYYYMMDD
	memcpy(out->ed_date, data->ed_date, sizeof(data->ed_date));	// 만료일자,종료일자, YYYYMMDD

	return 1;
}


// 코스피_종목배치
int ParseA0011(const double& timestamp, const char* in_buff, DF_KOSPI_STK_ARNG* out) {
	KOSPI_STK_ARNG* data = (KOSPI_STK_ARNG*)in_buff;

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
	memcpy(out->stk_gr_id, data->stk_gr_id, sizeof(data->stk_gr_id));	// 증권그룹ID, ST:주권 MF:증권투자회사 RT:부동산투자회사 \nSC:선박투자회사\nIF:사회간접자본투융자회사 DR:주식예탁증서 EW:ELW EF:ETF\nSW:신주인수권증권 SR:신주인수권증서 BC:수익증권 \nFE:해외ETF FS:외국주권 \nEN:ETN 2014.11.17
	out->unit_trd_ccls_flg = data->unit_trd_ccls_flg[0];	//단위매매체결여부, Y, N (정규장에서 일정시간 단위체결여부)
	memcpy(out->lock_clsf_code, data->lock_clsf_code, sizeof(data->lock_clsf_code));	// 락구분코드, 00:해당사항없음(락이 발생안한 경우) \n01:권리락 \n02:배당락\n03:분배락 \n04:권배락 \n05:중간(분기)배당락\n(2017.11.20 변경:중간배당락->중간(분기)배당락)\n06:권리중간배당락\n07:권리분기배당락\n(2017.11.20 추가)\n99:기타 ※SW,SR,EW는 미해당(미해당의 경우 SPACE)
	memcpy(out->pval_chg_clsf_code, data->pval_chg_clsf_code, sizeof(data->pval_chg_clsf_code));	// 액면가변경구분코드, 00:해당없음(액면가변경이 취해질 수 있는 종목군에 대해 변경\n없음을 의미) 01:액면분할 02:액면병합 03:주식분할 04:주식병합 99:기타\n(2012.08.27)
	out->open_base_prc_stk_flg = data->open_base_prc_stk_flg[0];	//시가기준가격종목여부, Y, N ※Y인 경우:신규종목,기업분할,무상감자,장기간거래정지
	memcpy(out->rassm_stk_rsn_code, data->rassm_stk_rsn_code, sizeof(data->rassm_stk_rsn_code));	// 재평가종목사유코드, 00:해당없음, 01:회사분할, 02:자본감소, 03:장기간정지,\n04:초과분배, 05:대규모배당 \n06: 회사분할합병, 99:기타 \n※증권그룹ID ST,FS에 해당(미해당의 경우 SPACE)\n2011.02.28 구분값 추가(04:초과분배, 05:대규모배당)\n2012.08.27 정의오류수정(02:주식병합->02:자본감소) \n2017.06.26 구분값 변경(01:기업분할 -> 01:회사분할)\n2017.06.26 구분값 추가(06:회사분할합병)
	out->base_prc_chg_stk_flg = data->base_prc_chg_stk_flg[0];	//기준가격변경종목여부, Y, N ※Y인 경우:모든락,액면변경,증자 등
	out->rndn_cls_trgg_cond_code = data->rndn_cls_trgg_cond_code[0];	//임의종료발동조건코드, 단일가세선에서 임의종료의 발동조건.조건부발동(2)인경우 임의종료규칙에서 정의하는 가격요건을 충족하는지 판단 후 발동을 결정함.\n##코드값##\n0:미발동 1:발동 2:조건부발동(가격요건판단)
	out->mkt_alm_warn_fcst_flg = data->mkt_alm_warn_fcst_flg[0];	//시장경보경고예고여부, Y, N\n 2015.06.15:"시장경보위험예고여부(Y,N)"->"시장경보경고예고여부(Y,N)" 항목변경
	memcpy(out->mkt_alrm_clsf_code, data->mkt_alrm_clsf_code, sizeof(data->mkt_alrm_clsf_code));	// 시장경보구분코드, 00:해당없음(시장경보가 지정될 수 있는 종목에 대해서 지정된\n바가 없음을 의미) 01:투자주의 02:투자경고 03:투자위험
	out->cogv_hlth_flg = data->cogv_hlth_flg[0];	//지배구조우량여부, Y, N ※코스닥만 해당, ST,FS,DR,MF,EF만 해당
	out->ifam_flg = data->ifam_flg[0];	//관리종목여부, Y, N
	out->iscnt_flg = data->iscnt_flg[0];	//불성실공시지정여부, Y, N
	out->bdlt_flg = data->bdlt_flg[0];	//우회상장여부, Y, N
	out->trsp_flg = data->trsp_flg[0];	//거래정지여부, Y, N
	memcpy(out->ind_lclsf_code, data->ind_lclsf_code, sizeof(data->ind_lclsf_code));	// 지수업종대분류코드, (유가)000:업종미분류 ※유가증권은 사용하지 않음\n(코스닥)000:업종미분류/뮤추얼펀드 008~014:일반 015:IT\n※증권그룹ID ST,MF,RT,SC,IF만 해당
	memcpy(out->ind_mclsf_code, data->ind_mclsf_code, sizeof(data->ind_mclsf_code));	// 지수업종중분류코드, (유가)000:업종미분류\n(코스닥)000:업종미분류 021~040:일반 041~043:IT\n※증권그룹ID ST,MF,RT,SC,IF만 해당
	memcpy(out->ind_sclsf_code, data->ind_sclsf_code, sizeof(data->ind_sclsf_code));	// 지수업종소분류코드, (유가)000:업종미분류\n(코스닥)000:업종미분류 050~112:일반 151~160:IT\n※증권그룹ID ST,MF,RT,SC,IF만 해당
	memcpy(out->ind_id, data->ind_id, sizeof(data->ind_id));	// 업종ID, 업종(Type Of Industry)ID 2014.03.03\n*구명칭:표준산업코드\n6자리 표준산업코드는 국내요건만 수용할 수 있어 해외사이트의 다양한 업종코드 수용이 불가하여 10자리로 확대. 현행 표준산업코드는 그대로 1:1 매핑되어 나머지 4자리는 스페이스로 채움
	out->kospi200_str_ind = data->kospi200_str_ind[0];	//KOSPI200섹터업종, (유가)\n0:업종미분류, 1:건설, 2:중공업,\n3:철강소재,\n4:에너지화학, 5:정보통신, 6:금융, 7:필수소비재,\n8: 자유소비재 9:산업재 A:건강관리 B:커뮤니케이션서비스\n- KOSPI200구분 및 섹터업종 통합정리(2011.04.01)\n※증권그룹ID ST,MF,RT,SC,IF만 해당\n\n- 신규업종추가(산업재,건강관리) 및 기존업종명칭변경(건설,중공업)(2015.07.13) \n- 신규업종추가(커뮤니케이션서비스(2018.10.22)\n\n(코스닥) 해당사항없음.
	out->mkt_cap_code = data->mkt_cap_code[0];	//시가총액규모코드, 유가(0:제외 1:대 2:중 3:소)\n코스닥(0:제외 1:KOSDAQ100 2:KOSDAQmid300 3:KOSDAQsmall)\n※증권그룹ID ST,MF,RT,SC,IF만 해당
	out->mnft_ind_flg = data->mnft_ind_flg[0];	//(유가)제조업여부(코스닥)중소기업여부, Y, N\n※제조업여부는 ST,MF,RT,SC,IF만 해당(업종코드 027)\n※중소기업여부는 ST,FS,DR,EF만 해당
	out->krx100_flg = data->krx100_flg[0];	//KRX100종목여부, Y, N
	out->gvnm_idx_stk_flg = data->gvnm_idx_stk_flg[0];	//(유가)지배구조지수종목여부(코스닥)소속부구분코드, (유가) Y, N\n(코스닥)소속부구분코드 ← 벤처기업여부 2011.05.02\n 1:우량기업부, 2:벤처기업부, 3:중견기업부, 4:신성장기업부,\n A:외국기업, B:투자회사, C:SPAC, D:ETF E:관리종목,\n F:투자주의환기종목, Z:기타 \n※ A~Z는 소속부 없음\n2012.09.14 (유가종목배치) "지배구조지수종목여부" 1 Byte FILLER 처리\n(코스닥종목배치) "소속부구분코드" 계속 사용
	memcpy(out->inst_clsf_code, data->inst_clsf_code, sizeof(data->inst_clsf_code));	// 투자기구구분코드, 00:해당없음 01:증권간접투자기구 02:파생상품투자기구\n03:부동산간접투자기구 04:실물간접투자기구\n05:단기금융간접투자기구 06:재간접투자기구\n07:특별간접투자기구\n※증권그룹ID MF,IF,BC가 해당(미해당의 경우 SPACE)
	out->idx_stk_flg = data->idx_stk_flg[0];	//(유가)KOSPI지수종목여부 (코스닥)KOSDAQ지수종목여부, Y, N\n(유가)KOSPI여부-> (유가)KOSPI지수종목여부,(코스닥)KOSDAQ지수종목여부 2018.12.10
	out->kospi100_flg = data->kospi100_flg[0];	//(유가)KOSPI100여부(코스닥)FILLER, Y, N 프리미어여부 추가 2009.11.16\n(코스닥)프리미어여부 => FILLER처리 2016.05.23
	out->kospi50_flg = data->kospi50_flg[0];	//(유가)KOSPI50여부, Y, N
	out->base_prc = Str2Int(data->base_prc, sizeof(data->base_prc));	// 기준가격
	out->prev_cls_clsf_code = data->prev_cls_clsf_code[0];	//전일종가구분코드, 1:실세 2:기세 3:거래무 4:시가기준가종목의 기세
	out->prev_cls_prc = Str2Int(data->prev_cls_prc, sizeof(data->prev_cls_prc));	// 전일종가
	out->prev_cum_ccls_qty = Str2Dbl(data->prev_cum_ccls_qty, sizeof(data->prev_cum_ccls_qty), 0);	// 전일누적체결수량
	out->prev_cum_trd_val = Str2Dbl(data->prev_cum_trd_val, sizeof(data->prev_cum_trd_val), 0);	// 전일누적거래대금
	out->ceil_prc = Str2Int(data->ceil_prc, sizeof(data->ceil_prc));	// 상한가
	out->flr_prc = Str2Int(data->flr_prc, sizeof(data->flr_prc));	// 하한가
	out->sub_prc = Str2Int(data->sub_prc, sizeof(data->sub_prc));	// 대용가격, ※ST,FS,DR,MF,RT,SC,IF,ET,FE,BC,EN 만 해당\n 2014.11.17
	out->par_val = Str2Dbl(data->par_val, sizeof(data->par_val), 3);	// 액면가, 9(9)V9(3) 외국주권일 경우 소숫점셋째자리까지 표현가능\n코스닥의 각국의 최소화폐단위 표시는 유가기준으로 통일\n※ST,FS,RT,SC,BC만 해당
	out->issue_prc = Str2Int(data->issue_prc, sizeof(data->issue_prc));	// 발행가격, ELW, 신주인수권증서 포함
	memcpy(out->listd_date, data->listd_date, sizeof(data->listd_date));	// 상장일자, YYYYMMDD
	out->stk_listd = Str2Dbl(data->stk_listd, sizeof(data->stk_listd), 0);	// 상장주식수(상장증권수)
	out->arng_trd_flg = data->arng_trd_flg[0];	//정리매매여부, Y, N
	out->eps = Str2Int(data->eps, sizeof(data->eps));	// 주당순이익(EPS), 단위:원 ※증권그룹ID ST,MF,RT,IF,FS 가 해당
	out->per = Str2SignDouble(data->per_sign, sizeof(data->per_sign) + sizeof(data->per), 2);	// 주가수익율(PER), 9(4)V9(2) ※증권그룹ID ST,MF,RT,IF,FS 가 해당
	out->eps_cmpt_xclu_flg = data->eps_cmpt_xclu_flg[0];	//주당순이익산출제외여부, Y:산출제외 N:산출\n※값이 0, 관리종목, 감사의견이 적정 또는 한정 인 경우
	out->bps = Str2Int(data->bps, sizeof(data->bps));	// 주당순자산가치(BPS), 단위:원 ※증권그룹ID ST,MF,RT,IF,FS 가 해당
	out->pbr = Str2SignDouble(data->pbr_sign, sizeof(data->pbr_sign) + sizeof(data->pbr), 2);	// 주당순자산비율(PBR), 9(4)V9(2) ※증권그룹ID ST,MF,RT,IF,FS 가 해당
	out->bps_cmpt_xclu_flg = data->bps_cmpt_xclu_flg[0];	//주당순자산가치산출제외여부, Y:산출제외 N:산출\n※값이 0, 관리종목, 감사의견이 적정 또는 한정인 경우
	out->loss_flg = data->loss_flg[0];	//결손여부, Y, N
	out->dps = Str2Int(data->dps, sizeof(data->dps));	// 주당배당금액, 주당배당금
	out->dps_cmpt_xclu_flg = data->dps_cmpt_xclu_flg[0];	//주당배당금액산출제외여부, Y:산출제외 N:산출\n※값이 0, 관리종목, 감사의견이 적정 또는 한정인 경우
	out->dyr = Str2Dbl(data->dyr, sizeof(data->dyr), 1);	// 배당수익율, 9(6)V9(1)
	memcpy(out->xist_open_date, data->xist_open_date, sizeof(data->xist_open_date));	// 존립개시일자, ※증권그룹ID MF,RT,SC,IF,BC 해당.
	memcpy(out->xist_cls_date, data->xist_cls_date, sizeof(data->xist_cls_date));	// 존립종료일자, ※증권그룹ID MF,RT,SC,IF,BC 해당. ST,FS,DR은 우선주만 해당
	memcpy(out->exc_prd_open_date, data->exc_prd_open_date, sizeof(data->exc_prd_open_date));	// 행사기간개시일자, ※증권그룹ID SW, EW 이 해당됨
	memcpy(out->exc_prd_cls_date, data->exc_prd_cls_date, sizeof(data->exc_prd_cls_date));	// 행사기간종료일자(권리행사기간만료일자), ※증권그룹ID SW, EW 이 해당됨
	out->elw_wrnt_exc_prc = Str2Dbl(data->elw_wrnt_exc_prc, sizeof(data->elw_wrnt_exc_prc), 3);	// ELW신주인수권증권 행사가격, 9(9)V9(3) ELW 또는 신주인수권증권의 행사가격
	out->euity = Str2Dbl(data->euity, sizeof(data->euity), 3);	// 자본금, 9(18)V9(3) 해외원주일 경우 소숫점셋째자리까지 표현가능\n액면가*상장주식수, 이익소각에 대한 부분은 차감함\nMF는 입력값\n※ST,FS,MF,RT,SC,IF,BC만 해당
	out->credit_ordbl_flg = data->credit_ordbl_flg[0];	//신용주문가능여부, Y, N
	out->limt_prc_cond_clsf_code = Str2Int(data->limt_prc_cond_clsf_code, sizeof(data->limt_prc_cond_clsf_code));	// 지정가호가조건구분코드, X ->9 모드변경, 1->5 길이변경\n호가의 체결 및 잔류조건, Bitwise 정의(*개발가이드 참조) \n#코드값# \n1:FAS(Fill And Store) \n2:FOK(Fill Or Kill) \n4:FAK(Fill And Kill) \n*전량조건(FOK, Fill or Kill):주문전달 즉시 전량 체결되지 않으면 모든 주문이 자동 취소되는 주문 \n*당일조건(FAS, Fill and Store):주문전달 즉시 체결가능 수량은 체결하고 미체결잔량은 당일 장중동안 주문장에 체결 대기시키되, 장종료 후의 미체결 주문은 모두 최소됨
	out->mkt_prc_cond_clsf_code = Str2Int(data->mkt_prc_cond_clsf_code, sizeof(data->mkt_prc_cond_clsf_code));	// 시장가호가조건구분코드, *상동
	out->cond_prc_cond_clsf_code = Str2Int(data->cond_prc_cond_clsf_code, sizeof(data->cond_prc_cond_clsf_code));	// 조건부지정가호가조건구분코드, *상동
	out->fvr_lmt_ord_cond_clsf_code = Str2Int(data->fvr_lmt_ord_cond_clsf_code, sizeof(data->fvr_lmt_ord_cond_clsf_code));	// 최유리지정가호가조건구분코드, *상동
	out->pfr_lmt_ord_cond_clsf_code = Str2Int(data->pfr_lmt_ord_cond_clsf_code, sizeof(data->pfr_lmt_ord_cond_clsf_code));	// 최우선지정가호가조건구분코드, *상동
	memcpy(out->cap_inc_clsf_code, data->cap_inc_clsf_code, sizeof(data->cap_inc_clsf_code));	// 증자구분코드, 00:해당없음 01:유상증자 02:무상증자 03:유무상증자 99:기타
	out->scrt_clsf_code = data->scrt_clsf_code[0];	//종류주권구분코드, 0:해당없음(보통주) 1:구형우선주 2:신형우선주 9:종류주권(2014.03.03)\n\n※증권그룹ID ST에만 해당\n※구명칭:우선주구분코드
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
	out->preord_cls_flg = data->preord_cls_flg[0];	//장개시전시간외종가가능여부, Y, N
	out->preord_msv_trd_flg = data->preord_msv_trd_flg[0];	//장개시전시간외대량매매가능 여부, Y, N
	out->preord_bsk_flg = data->preord_bsk_flg[0];	//장개시전시간외바스켓가능 여부, Y, N
	out->fcst_ccls_flg = data->fcst_ccls_flg[0];	//예상체결가공개여부, Y, N
	out->short_flg = data->short_flg[0];	//공매도가능여부, Y, N 가격제한이 있거나 없는 공매도의 호가가능여부
	out->trkg_prf_mtp = Str2SignDouble(data->trkg_prf_mtp_sign, sizeof(data->trkg_prf_mtp_sign) + sizeof(data->trkg_prf_mtp), 6);	// 추적수익율배수, ※증권그룹ID EF,FE,EN 해당 2014.11.17\n※항목명변경 2014.11.17\n\n9(5)V9(6) 지수 또는 가격 변동 대비 ETF 가격 변동 배수\n예) 레버리지 2배일 경우 '00002000000' 2009.07.27
	out->regulation_apl_flg = data->regulation_apl_flg[0];	//Regulation S 적용종목여부, Y, N 2010.02.01
	out->spc_flg = data->spc_flg[0];	//기업인수목적회사여부, Y, N 2010.03.02
	out->tax_type_code = data->tax_type_code[0];	//과세유형코드, 0:해당없음, \n1:"증권거래세"->"비과세" 코드값명 변경 2016.02.29, \n2:배당소득세(보유기간과세), \n3:증권거래세(회사형ETF) 2011.05.02 \n4:"배당소득세(해외주식투자전용ETF)" 코드값 추가 2016.02.29(BIG33은 FILLER임)
	out->sbst_prc_rate = Str2Dbl(data->sbst_prc_rate, sizeof(data->sbst_prc_rate), 6);	// 대용가격사정비율, 99999V999999 2010.06.28\n(BIG33은 FILLER임)\n※Exture에서는 대용가가 0이면 사정비율이 0이었으나, Exture+에서는 대용가가 0이어도 사정비율 제공
	out->inv_xctm_stk_flg = data->inv_xctm_stk_flg[0];	//(코스닥)투자주의환기종목여부, (코스닥) Y,N 관리종목 또는 상장폐지로 악화될 우려가 있는\n부실 위험징후 기업 여부\n(2011.05.02 추가)\n(BIG33은 FILLER임)
	memcpy(out->dlstg_date, data->dlstg_date, sizeof(data->dlstg_date));	// 상장폐지일자, YYYYMMDD ※증권그룹ID SR 만 해당, 다른 증권그룹ID는 FILLER처리 2011.06.27 추가\n(BIG33은 FILLER임)
	out->short_term_oh_clsf_code = data->short_term_oh_clsf_code[0];	//단기과열종목구분코드, 0: 해당없음\n1: 지정예고\n2: 지정\n3: 지정연장(해제연기)\n2012.11.05 추가
	out->etf_cpy_clsf_code = data->etf_cpy_clsf_code[0];	//ETF복제방법구분코드, ETF의 기초자산 복제방법구분코드 2013.03.18 추가\nP:실물복제\nS:합성복제\nA:Active (2015.11.23 구분코드추가)
	out->kospi200_hi_divd_idx_flg = data->kospi200_hi_divd_idx_flg[0];	//KOSPI200고배당지수여부, Y,N 2013.11.18
	out->kospi200_lo_vol_idx_flg = data->kospi200_lo_vol_idx_flg[0];	//KOSPI200저변동성지수여부, Y,N 2013.11.18
	memcpy(out->mtr_date, data->mtr_date, sizeof(data->mtr_date));	// 만기일자, 2014.11.17
	memcpy(out->divd_type_code, data->divd_type_code, sizeof(data->divd_type_code));	// 분배금형태코드, 분배금형태에 따른 구분코드 2014.11.17\n01:미지급\n02:지급(지표가치 반영)\n03:지급(지표가치 미반영)\n04:지급(재투자)\n05:지급(기타)
	memcpy(out->mtr_rdmp_prc_st_date, data->mtr_rdmp_prc_st_date, sizeof(data->mtr_rdmp_prc_st_date));	// 만기상환가격결정시작일자, 2014.11.17
	memcpy(out->mtr_rdmp_prc_ed_date, data->mtr_rdmp_prc_ed_date, sizeof(data->mtr_rdmp_prc_ed_date));	// 만기상환가격결정종료일자, 2014.11.17
	out->etp_mcdz_clsf_code = data->etp_mcdz_clsf_code[0];	//ETP상품구분코드, (2015.11.23 추가)\n ETP상품구분코드\n ## 코드값 ##\n1. ETF(투자회사형)\n2. ETF(수익증권형)\n3. ETN\n4. 손실제한 ETN\n(2017.03.27;ELS형 ETN->손실제한 ETN)
	out->idx_cmpt_inst_code = data->idx_cmpt_inst_code[0];	//지수산출기관코드, (2015.11.23 추가) \n*코드값모음 참조(KRX 정의)
	memcpy(out->idx_mkt_clsf_id, data->idx_mkt_clsf_id, sizeof(data->idx_mkt_clsf_id));	// 지수시장분류ID, (2015.11.23 추가)\n *대분류(2)+중분류(2)+소분류(2)\n 값이 생략되는 분류의 자리는 '00'을 표기\n중,소분류 지정시 상위 분류의 값은 생략 할 수 없음
	memcpy(out->idx_snr, data->idx_snr, sizeof(data->idx_snr));	// 지수일련번호, (2015.11.23 추가)지수일련번호
	memcpy(out->trkg_idx_lvrg_invs_clsf_code, data->trkg_idx_lvrg_invs_clsf_code, sizeof(data->trkg_idx_lvrg_invs_clsf_code));	// 추적지수레버리지인버스구분코드, (2015.11.23 추가)\n## 코드값 ##\n P1:일반(1)\n P2:2X 레버리지(2)\n N1:1X 인버스(-1)\n N2:2X 인버스(-2)
	memcpy(out->ref_idx_lvrg_invs_clsf_code, data->ref_idx_lvrg_invs_clsf_code, sizeof(data->ref_idx_lvrg_invs_clsf_code));	// 참고지수레버리지인버스구분코드, (2015.11.23 추가)\n## 코드값 ##\n P1:일반(1)\n P2:2X 레버리지(2)\n N1:1X 인버스(-1)\n N2:2X 인버스(-2)
	memcpy(out->idx_ast_clsf_id1, data->idx_ast_clsf_id1, sizeof(data->idx_ast_clsf_id1));	// 지수자산분류ID1, (2015.11.23 추가)\n *대분류(2)+중분류(2)+소분류(2)\n 값이 생략되는 분류의 자리는 '00'을 표기\n중,소분류 지정시 상위 분류의 값은 생략 할 수 없음
	memcpy(out->idx_ast_clsf_id2, data->idx_ast_clsf_id2, sizeof(data->idx_ast_clsf_id2));	// 지수자산분류ID2, (2015.11.23 추가)\n *대분류(2)+중분류(2)+소분류(2)\n 값이 생략되는 분류의 자리는 '00'을 표기\n중,소분류 지정시 상위 분류의 값은 생략 할 수 없음
	out->lp_odrbl_flg = data->lp_odrbl_flg[0];	//LP주문가능여부, (2015.11.23 추가)\nY,N
	out->kosdaq150_idx_stk_flg = data->kosdaq150_idx_stk_flg[0];	//KOSDAQ150지수종목여부, (2015.11.23 추가)\nY,N
	out->lo_vol_flg = data->lo_vol_flg[0];	//저유동성여부, (2016.06.27 추가)\nY,N
	out->abnm_risg_flg = data->abnm_risg_flg[0];	//이상급등여부, (2017.03.27 추가)\nY,N
	out->krx300_idx_flg = data->krx300_idx_flg[0];	//KRX300지수여부, (2018.03.26 추가)\nY,N
	out->qty_ceil = Str2Dbl(data->qty_ceil, sizeof(data->qty_ceil), 0);	// 상한수량, (2018.09.17 추가)상한수량을 초과시 호가는 거부처리 필요
	out->kospi200_comm_srvc_sct_flg = data->kospi200_comm_srvc_sct_flg[0];	//KOSPI200커뮤니케이션서비스섹터 중복여부, Y : 다른섹터와 중복인 경우 KOSPI200섹터업종에 기존섹터업종정보를 설정하고 이 필드는 Y로 설정\nN: 다른섹터와 중복이 되지 않은 경우 KOSPI200섹터업종에 'B'값을 설정하고 이 필드는 N으로 설정

	return 1;
}


// ETN 수익구조 내용
int ParseX8011(const double& timestamp, const char* in_buff, DF_ETN_PRF_STR* out) {
	ETN_PRF_STR* data = (ETN_PRF_STR*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA구분, X8
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// 정보구분, 01:주식
	out->mkt_clsf = data->mkt_clsf[0];	//시장구분, 1:유가증권
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// 종목코드, 표준코드
	memcpy(out->etn_profit_strt, data->etn_profit_strt, sizeof(data->etn_profit_strt));	// ETN수익구조내용, ETN 수익구조에 대한 설명\n손실제한 ETN에서 주로 사용됨

	return 1;
}


// ETN괴리율
int ParseX4011(const double& timestamp, const char* in_buff, DF_ETN_DSPR* out) {
	ETN_DSPR* data = (ETN_DSPR*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA구분, X4
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// 정보구분, 01:주식
	out->mkt_clsf = data->mkt_clsf[0];	//시장구분, 1:유가증권 2:코스닥
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// ETN종목코드, ISIN
	out->trsm_snr = Str2Int(data->trsm_snr, sizeof(data->trsm_snr));	// 송신일련번호, 1~99999999 전송일련번호, 건수체크용
	memcpy(out->date, data->date, sizeof(data->date));	// 일자, YYYYMMDD:전영업일자
	out->dspr = Str2SignDouble(data->dspr_sign, sizeof(data->dspr_sign) + sizeof(data->dspr), 2);	// 괴리율, 9(7)V9(2), 단위:%

	return 1;
}


// ETN 조기상환 조건
int ParseX3011(const double& timestamp, const char* in_buff, DF_ETN_ELY_RDMP_COND* out) {
	ETN_ELY_RDMP_COND* data = (ETN_ELY_RDMP_COND*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA구분, X3
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// 정보구분, 01:주식
	out->mkt_clsf = data->mkt_clsf[0];	//시장구분, 1:유가증권
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// 종목코드, 표준코드
	memcpy(out->etn_ely_rdmp_freq_code, data->etn_ely_rdmp_freq_code, sizeof(data->etn_ely_rdmp_freq_code));	// ETN조기상환주기코드, 손실제한 ETN의 조기상환 주기 구분\nETN조기상환가능여부가 Y일때만 선택가능\n▦▦코드값▦▦\n01: 수시(매일)\n02: 매 3개월\n03: 매 4개월\n04: 매 6개월\n05: 매 1년 (사양서에는 없음)\n06: 3개월부터 매 1개월 (사양서에는 없음)\n07: 6개월부터 매 1개월 (사양서에는 없음)
	memcpy(out->rdmp_assm_date, data->rdmp_assm_date, sizeof(data->rdmp_assm_date));	// 조기상환평가일자, 조기상환평가일자\n조기상환주기코드가 01:수시일 경우는 SPACE
	out->rdmp_cond_code = data->rdmp_cond_code[0];	//조기상환조건관계코드, 조기상환기준1지수와 조기상환기준2지수 간의 관계 조건 코드\n복수조건일 경우 기준1지수 < 기준2지수 조건으로 제약\n▦▦코드값▦▦\n1:단일조건(1지수이상)\n2:단일조건(1지수이하)\n3:복수조건(1지수이하,2지수이상)\n4:복수조건(1지수이상,2지수이하)
	out->rdmp_crtr_base_1idx = Str2Dbl(data->rdmp_crtr_base_1idx, sizeof(data->rdmp_crtr_base_1idx), 2);	// 조기상환기준1지수, 조기상환기준1지수\n9(8)V9(2)
	out->rdmp_crtr_base_2idx = Str2Dbl(data->rdmp_crtr_base_2idx, sizeof(data->rdmp_crtr_base_2idx), 2);	// 조기상환기준2지수, 조기상환기준2지수\n9(8)V9(2)
	out->rdmp_prc = Str2Dbl(data->rdmp_prc, sizeof(data->rdmp_prc), 2);	// 제비용차감전조기상환가격, 제비용차감전조기상환가격\n9(21)V9(2)
	memcpy(out->rdmp_date, data->rdmp_date, sizeof(data->rdmp_date));	// 조기상환지급일자, 조기상환지급일자\n조기상환주기코드가 01:수시일 경우는 SPACE

	return 1;
}


// ETP지수구성
int ParseV6011(const double& timestamp, const char* in_buff, DF_ETP_IDX_COMP* out) {
	ETP_IDX_COMP* data = (ETP_IDX_COMP*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA구분, V6
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// 정보구분, 01:주식
	out->mkt_clsf = data->mkt_clsf[0];	//시장구분, 1:유가증권
	out->idx_inst_code = data->idx_inst_code[0];	//지수산출기관코드, *코드값 참조(KRX정의)
	memcpy(out->idx_mkt_clsf_id, data->idx_mkt_clsf_id, sizeof(data->idx_mkt_clsf_id));	// 지수시장분류ID, *대분류(2)+중분류(2)+소분류(2)\n 값이 생략되는 분류의 자리는 '00'을 표기\n중,소분류 지정시 상위 분류의 값은 생략 할 수 없음
	memcpy(out->idx_snr, data->idx_snr, sizeof(data->idx_snr));	// 지수일련번호, 지수일련번호
	memcpy(out->idx_lvr_ivs_clsf_code, data->idx_lvr_ivs_clsf_code, sizeof(data->idx_lvr_ivs_clsf_code));	// 지수레버리지인버스구분코드, ## 코드값 ##\n P1:일반(1)\n P2:2X 레버리지(2)\n N1:1X 인버스(-1)\n N2:2X 인버스(-2)
	memcpy(out->idx_nm, data->idx_nm, sizeof(data->idx_nm));	// 지수명, 지수명
	memcpy(out->idx_eng_nm, data->idx_eng_nm, sizeof(data->idx_eng_nm));	// 지수영문명, 지수영문명
	memcpy(out->idx_asset_clsf_id1, data->idx_asset_clsf_id1, sizeof(data->idx_asset_clsf_id1));	// 지수자산분류ID1, *대분류(2)+중분류(2)+소분류(2)\n 값이 생략되는 분류의 자리는 '00'을 표기\n중,소분류 지정시 상위 분류의 값은 생략 할 수 없음
	memcpy(out->idx_asset_clsf_id2, data->idx_asset_clsf_id2, sizeof(data->idx_asset_clsf_id2));	// 지수자산분류ID2, *대분류(2)+중분류(2)+소분류(2)\n 값이 생략되는 분류의 자리는 '00'을 표기\n중,소분류 지정시 상위 분류의 값은 생략 할 수 없음
	out->idx_mkt_clsf_code = data->idx_mkt_clsf_code[0];	//지수소속시장구분코드, 지수 소속시장의 구분
	memcpy(out->ind_idx_code, data->ind_idx_code, sizeof(data->ind_idx_code));	// 업종지수코드, 업종지수코드(8자리)는 지수업종뿐만 아니라 KOSPI100, KOSPI50, KOSTAR등의 지수 산출의 대상이 되는 모든 분류에 코드를 부여하여 이를 지칭

	return 1;
}


// 코스피_기준가결정
int ParseA4011(const double& timestamp, const char* in_buff, DF_KOSPI_BASE_PRC_DCS* out) {
	KOSPI_BASE_PRC_DCS* data = (KOSPI_BASE_PRC_DCS*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA구분, A4
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// 정보구분, 01:주식
	out->mkt_clsf = data->mkt_clsf[0];	//시장구분, 1:유가증권 2:코스닥
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// 종목코드, 표준코드
	out->snr = Str2Int(data->snr, sizeof(data->snr));	// 종목일련번호, 종목배치(A0)의 종목일련번호
	memcpy(out->brd_id, data->brd_id, sizeof(data->brd_id));	// 보드ID, ※ 코드값모음 참조
	out->base_prc = Str2Int(data->base_prc, sizeof(data->base_prc));	// 기준가격, 단위:원
	out->base_prc_ceil = Str2Int(data->base_prc_ceil, sizeof(data->base_prc_ceil));	// 기준가격상한가, 단위:원
	out->base_prc_flr = Str2Int(data->base_prc_flr, sizeof(data->base_prc_flr));	// 기준가격하한가, 단위:원

	return 1;
}


// 코스피_종목마감
int ParseA6011(const double& timestamp, const char* in_buff, DF_KOSPI_STK_CLSG* out) {
	KOSPI_STK_CLSG* data = (KOSPI_STK_CLSG*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA구분, A6
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// 정보구분, 01:주식 02:ELW
	out->mkt_clsf = data->mkt_clsf[0];	//시장구분, 1:유가증권 2:코스닥
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// 종목코드, 표준코드
	out->snr = Str2Int(data->snr, sizeof(data->snr));	// 종목일련번호, 종목배치(A0)의 종목일련번호
	memcpy(out->brd_id, data->brd_id, sizeof(data->brd_id));	// 보드ID, ※ 코드값모음 참조
	out->stk_cls_prc = Str2Int(data->stk_cls_prc, sizeof(data->stk_cls_prc));	// 종목마감종가, 정규시간외구분코드가 \n 1:정규장일때만 종목마감가격구분코드값이 SET 됨. \n 그외에는 SPACE
	out->stk_cls_prc_clsf_code = data->stk_cls_prc_clsf_code[0];	//종목마감가격구분코드, 1:체결가 \n 2:기세 \n 3:거래무 \n 4:시가기준가종목의 기세\n :정규장이 아닌 경우 SPACE
	out->ofhr_ceil = Str2Int(data->ofhr_ceil, sizeof(data->ofhr_ceil));	// 종목마감시간외단일가 상한가
	out->ofhr_flr = Str2Int(data->ofhr_flr, sizeof(data->ofhr_flr));	// 종목마감시간외단일가 하한가
	out->stk_cls_mwprc = Str2Int(data->stk_cls_mwprc, sizeof(data->stk_cls_mwprc));	// 종목마감평균가중주가
	out->dlv_base_prc = Str2Int(data->dlv_base_prc, sizeof(data->dlv_base_prc));	// 매입인도기준가격
	out->dlv_ceil = Str2Int(data->dlv_ceil, sizeof(data->dlv_ceil));	// 매입인도상한가
	out->dlv_flr = Str2Int(data->dlv_flr, sizeof(data->dlv_flr));	// 매입인도하한가

	return 1;
}


// 코스피_장운영TS
int ParseA7011(const double& timestamp, const char* in_buff, DF_KOSPI_MKT_OPR_TS* out) {
	KOSPI_MKT_OPR_TS* data = (KOSPI_MKT_OPR_TS*)in_buff;

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


// 코스피_체결
int ParseA3011(const double& timestamp, const char* in_buff, DF_KOSPI_CCLS* out) {
	KOSPI_CCLS* data = (KOSPI_CCLS*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA구분, A3
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// 정보구분, 01:주식 02:ELW
	out->mkt_clsf = data->mkt_clsf[0];	//시장구분, 1:유가증권 2:코스닥
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// 종목코드, 표준코드
	out->stk_snr = Str2Int(data->stk_snr, sizeof(data->stk_snr));	// 종목일련번호, 종목배치(A0)의 종목일련번호
	memcpy(out->brd_id, data->brd_id, sizeof(data->brd_id));	// 보드ID, ※ 코드값모음 참조
	out->ctrs_clsf = data->ctrs_clsf[0];	//전일대비(기준가대비) 구분, 0:판단불가 1:상한 2:상승 3:보합 4:하한 5:하락\n ※ 정규시간외구분코드 값이 4인 경우 당일 종가 대비\n ※ 정규시간외구분코드 값이 7,8인 경우 Buy-in기준가 대비
	out->prev_ctrs = Str2Int(data->prev_ctrs, sizeof(data->prev_ctrs));	// 전일대비, 단위:원 신주인수권 증서/증권의 신규 상장 당일 : 0
	out->ccls_prc = Str2Int(data->ccls_prc, sizeof(data->ccls_prc));	// 체결가격, 단위:원
	out->ccls_qty = Str2Dbl(data->ccls_qty, sizeof(data->ccls_qty), 0);	// 체결수량, 단위:주
	memcpy(out->sess_id, data->sess_id, sizeof(data->sess_id));	// 세션ID, ※ 코드값모음 참조
	out->open = Str2Int(data->open, sizeof(data->open));	// 시가, 단위:원 ※개발가이드 참조
	out->high = Str2Int(data->high, sizeof(data->high));	// 고가, 단위:원 ※개발가이드 참조
	out->low = Str2Int(data->low, sizeof(data->low));	// 저가, 단위:원 ※개발가이드 참조
	out->cum_ccls_qty = Str2Dbl(data->cum_ccls_qty, sizeof(data->cum_ccls_qty), 0);	// 누적체결수량, 단위:주 ※보드ID별로 누적됨
	out->cum_trd_val = Str2Dbl(data->cum_trd_val, sizeof(data->cum_trd_val), 0);	// 누적거래대금, 단위:원 ※보드ID별로 누적됨
	out->fin_bid_ask_clsf_code = data->fin_bid_ask_clsf_code[0];	//최종매도매수구분코드, 1:매도 2:매수
	out->mtc_flg = data->mtc_flg[0];	//체결가와1호가일치여부, 0:판단불가 1:일치 2:불일치
	memcpy(out->ccls_time, data->ccls_time, sizeof(data->ccls_time));	// 체결시각, HHMMSS
	out->lp_hld_qty = Str2Dbl(data->lp_hld_qty, sizeof(data->lp_hld_qty), 0);	// LP보유수량, LP(체결기준) 집계후 LP보유수량\n음수발생 가능(ETN만 해당)(2018.09.17)
	out->ask_1_prc = Str2Int(data->ask_1_prc, sizeof(data->ask_1_prc));	// 매도1호가, 단위:원 ※개발가이드 참조
	out->bid_1_prc = Str2Int(data->bid_1_prc, sizeof(data->bid_1_prc));	// 매수1호가, 단위:원 ※개발가이드 참조

	return 1;
}


// 코스피_대량체결
int ParseC4011(const double& timestamp, const char* in_buff, DF_KOSPI_MSV_CCLS* out) {
	KOSPI_MSV_CCLS* data = (KOSPI_MSV_CCLS*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA구분, C4
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// 정보구분, 01:주식
	out->mkt_clsf = data->mkt_clsf[0];	//시장구분, 1:유가증권 2:코스닥
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// 종목코드, 표준코드
	out->stk_snr = Str2Int(data->stk_snr, sizeof(data->stk_snr));	// 종목일련번호, 종목배치(A0)의 종목일련번호
	out->snr = Str2Int(data->snr, sizeof(data->snr));	// 일련번호, 1~99999999 건수체크용
	out->bopen_rel_msv_ccls_qty = Str2Int(data->bopen_rel_msv_ccls_qty, sizeof(data->bopen_rel_msv_ccls_qty));	// 장개시전시간외 상대대량체결수량, 단위:주
	out->bopen_bsk_ccls_qty = Str2Int(data->bopen_bsk_ccls_qty, sizeof(data->bopen_bsk_ccls_qty));	// 장개시전시간외 바스켓체결수량, 단위:주
	out->bopen_cmpt_msv_ccls_qty = Str2Int(data->bopen_cmpt_msv_ccls_qty, sizeof(data->bopen_cmpt_msv_ccls_qty));	// 장개시전시간외 경쟁대량체결수량, 단위:주
	out->rel_msv_ccls_qty = Str2Int(data->rel_msv_ccls_qty, sizeof(data->rel_msv_ccls_qty));	// 장중상대대량체결수량, 단위:주
	out->bsk_ccls_qty = Str2Int(data->bsk_ccls_qty, sizeof(data->bsk_ccls_qty));	// 장중바스켓체결수량, 단위:주
	out->cmpt_msv_ccls_qty = Str2Int(data->cmpt_msv_ccls_qty, sizeof(data->cmpt_msv_ccls_qty));	// 장중경쟁대량체결수량, 단위:주
	out->ofhr_rel_msv_ccls_qty = Str2Int(data->ofhr_rel_msv_ccls_qty, sizeof(data->ofhr_rel_msv_ccls_qty));	// 장종료후시간외 상대대량체결수량, 단위:주
	out->ofhr_bsk_ccls_qty = Str2Int(data->ofhr_bsk_ccls_qty, sizeof(data->ofhr_bsk_ccls_qty));	// 장종료후시간외 바스켓체결수량, 단위:주

	return 1;
}


// 코스피_배분정보
int ParseO6011(const double& timestamp, const char* in_buff, DF_KOSPI_ALLC_INFO* out) {
	KOSPI_ALLC_INFO* data = (KOSPI_ALLC_INFO*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA구분, O6
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// 정보구분, 01:주식
	out->mkt_clsf = data->mkt_clsf[0];	//시장구분, 1:유가증권, 2:코스닥,
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// 종목코드, 표준코드
	out->stk_snr = Str2Int(data->stk_snr, sizeof(data->stk_snr));	// 종목일련번호, 종목배치(A0)의 종목일련번호
	memcpy(out->brd_id, data->brd_id, sizeof(data->brd_id));	// 보드ID, ※ 코드값모음 참조
	out->allc_apl_clsf_code = data->allc_apl_clsf_code[0];	//배분적용구분코드, 1 배분개시\n 2 배분해제
	out->allc_proc_clsf_code = Str2Int(data->allc_proc_clsf_code, sizeof(data->allc_proc_clsf_code));	// 배분처리구분코드, 1 매수상한,\n 2 매수하한,\n 3 매도상한,\n 4 매도하한 ※ 해제시 ' ' 전송
	out->allc_cncl_time = Str2Int(data->allc_cncl_time, sizeof(data->allc_cncl_time));	// 배분해제시각, HHMMSS

	return 1;
}


// ELW_체결
int ParseA3021(const double& timestamp, const char* in_buff, DF_ELW_CCLS* out) {
	ELW_CCLS* data = (ELW_CCLS*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA구분, A3
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// 정보구분, 01:주식 02:ELW
	out->mkt_clsf = data->mkt_clsf[0];	//시장구분, 1:유가증권 2:코스닥
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// 종목코드, 표준코드
	out->stk_snr = Str2Int(data->stk_snr, sizeof(data->stk_snr));	// 종목일련번호, 종목배치(A0)의 종목일련번호
	memcpy(out->brd_id, data->brd_id, sizeof(data->brd_id));	// 보드ID, ※ 코드값모음 참조
	out->ctrs_clsf = data->ctrs_clsf[0];	//전일대비(기준가대비) 구분, 0:판단불가 1:상한 2:상승 3:보합 4:하한 5:하락\n ※ 정규시간외구분코드 값이 4인 경우 당일 종가 대비\n ※ 정규시간외구분코드 값이 7,8인 경우 Buy-in기준가 대비
	out->prev_ctrs = Str2Int(data->prev_ctrs, sizeof(data->prev_ctrs));	// 전일대비, 단위:원 신주인수권 증서/증권의 신규 상장 당일 : 0
	out->ccls_prc = Str2Int(data->ccls_prc, sizeof(data->ccls_prc));	// 체결가격, 단위:원
	out->ccls_qty = Str2Dbl(data->ccls_qty, sizeof(data->ccls_qty), 0);	// 체결수량, 단위:주
	memcpy(out->sess_id, data->sess_id, sizeof(data->sess_id));	// 세션ID, ※ 코드값모음 참조
	out->open = Str2Int(data->open, sizeof(data->open));	// 시가, 단위:원 ※개발가이드 참조
	out->high = Str2Int(data->high, sizeof(data->high));	// 고가, 단위:원 ※개발가이드 참조
	out->low = Str2Int(data->low, sizeof(data->low));	// 저가, 단위:원 ※개발가이드 참조
	out->cum_ccls_qty = Str2Dbl(data->cum_ccls_qty, sizeof(data->cum_ccls_qty), 0);	// 누적체결수량, 단위:주 ※보드ID별로 누적됨
	out->cum_trd_val = Str2Dbl(data->cum_trd_val, sizeof(data->cum_trd_val), 0);	// 누적거래대금, 단위:원 ※보드ID별로 누적됨
	out->fin_bid_ask_clsf_code = data->fin_bid_ask_clsf_code[0];	//최종매도매수구분코드, 1:매도 2:매수
	out->mtc_flg = data->mtc_flg[0];	//체결가와1호가일치여부, 0:판단불가 1:일치 2:불일치
	memcpy(out->ccls_time, data->ccls_time, sizeof(data->ccls_time));	// 체결시각, HHMMSS
	out->lp_hld_qty = Str2Dbl(data->lp_hld_qty, sizeof(data->lp_hld_qty), 0);	// LP보유수량, LP(체결기준) 집계후 LP보유수량
	out->ask_1_prc = Str2Int(data->ask_1_prc, sizeof(data->ask_1_prc));	// 매도1호가, 단위:원 ※개발가이드 참조
	out->bid_1_prc = Str2Int(data->bid_1_prc, sizeof(data->bid_1_prc));	// 매수1호가, 단위:원 ※개발가이드 참조

	return 1;
}


// ELW_종목마감
int ParseA6021(const double& timestamp, const char* in_buff, DF_ELW_STK_CLSG* out) {
	ELW_STK_CLSG* data = (ELW_STK_CLSG*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA구분, A6
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// 정보구분, 01:주식 02:ELW
	out->mkt_clsf = data->mkt_clsf[0];	//시장구분, 1:유가증권 2:코스닥
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// 종목코드, 표준코드
	out->snr = Str2Int(data->snr, sizeof(data->snr));	// 종목일련번호, 종목배치(A0)의 종목일련번호
	memcpy(out->brd_id, data->brd_id, sizeof(data->brd_id));	// 보드ID, ※ 코드값모음 참조
	out->stk_cls_prc = Str2Int(data->stk_cls_prc, sizeof(data->stk_cls_prc));	// 종목마감종가, 정규시간외구분코드가 \n 1:정규장일때만 종목마감가격구분코드값이 SET 됨. \n 그외에는 SPACE
	out->stk_cls_prc_clsf_code = data->stk_cls_prc_clsf_code[0];	//종목마감가격구분코드, 1:체결가 \n 2:기세 \n 3:거래무 \n 4:시가기준가종목의 기세\n :정규장이 아닌 경우 SPACE
	out->ofhr_hi = Str2Int(data->ofhr_hi, sizeof(data->ofhr_hi));	// 종목마감시간외단일가 상한가
	out->ofhr_lo = Str2Int(data->ofhr_lo, sizeof(data->ofhr_lo));	// 종목마감시간외단일가 하한가
	out->stk_cls_mwprc = Str2Int(data->stk_cls_mwprc, sizeof(data->stk_cls_mwprc));	// 종목마감평균가중주가
	out->dlv_base_prc = Str2Int(data->dlv_base_prc, sizeof(data->dlv_base_prc));	// 매입인도기준가격
	out->dlv_hi = Str2Int(data->dlv_hi, sizeof(data->dlv_hi));	// 매입인도상한가
	out->dlv_lo = Str2Int(data->dlv_lo, sizeof(data->dlv_lo));	// 매입인도하한가

	return 1;
}


// ELW_장운영TS
int ParseA7021(const double& timestamp, const char* in_buff, DF_ELW_MKT_OPR_TS* out) {
	ELW_MKT_OPR_TS* data = (ELW_MKT_OPR_TS*)in_buff;

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


// 코스피_주식종목정보공개
int ParseA8011(const double& timestamp, const char* in_buff, DF_KOSPI_STK_INFO_DCLS* out) {
	KOSPI_STK_INFO_DCLS* data = (KOSPI_STK_INFO_DCLS*)in_buff;

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
	memcpy(out->lock_clsf_code, data->lock_clsf_code, sizeof(data->lock_clsf_code));	// 락구분코드, 00:해당사항없음 01:권리락 02:배당락 03:분배락 04:권배락\n 05:중간(분기)배당락 06:권리중간배당락 07:권리분기배당락 99:기타
	memcpy(out->pval_chg_clsf_code, data->pval_chg_clsf_code, sizeof(data->pval_chg_clsf_code));	// 액면가변경구분코드, 00:해당없음 01:액면분할 02:액면병합 \n 03:주식분할 04:주식병합\n 99:기타
	out->trd_qty_unit = Str2Dbl(data->trd_qty_unit, sizeof(data->trd_qty_unit), 0);	// 매매수량단위, 1주단위:1 10:10주단위 100:100주단위 1000:1000주단위
	out->stk_lstd = Str2Dbl(data->stk_lstd, sizeof(data->stk_lstd), 0);	// 상장주식수
	out->apnt = data->apnt[0];	//지정여부, N:해제 Y:지정
	out->bopen_ofhr_flg = data->bopen_ofhr_flg[0];	//장개시전시간외종가 가능여부, N:해당없음 Y:가능

	return 1;
}


// 코스피_장운영스케줄공개
int ParseM4011(const double& timestamp, const char* in_buff, DF_KOSPI_MKT_OPR_DCLS* out) {
	KOSPI_MKT_OPR_DCLS* data = (KOSPI_MKT_OPR_DCLS*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA구분, M4
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// 정보구분, 01:주식
	out->mkt_clsf = data->mkt_clsf[0];	//시장구분, 1:유가증권 2:코스닥
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// 종목코드
	out->stk_snr = Str2Int(data->stk_snr, sizeof(data->stk_snr));	// 종목일련번호, 종목배치(A0)의 종목일련번호
	memcpy(out->brd_id, data->brd_id, sizeof(data->brd_id));	// 보드ID, ※ 코드값모음 참조
	memcpy(out->brd_evt_id, data->brd_evt_id, sizeof(data->brd_evt_id));	// 보드이벤트ID, ※ 코드값모음 참조
	memcpy(out->brd_evt_st, data->brd_evt_st, sizeof(data->brd_evt_st));	// 보드이벤트시작시각
	out->brd_evt_code = Str2Int(data->brd_evt_code, sizeof(data->brd_evt_code));	// 보드이벤트적용군코드, ※ 코드값모음 참조
	memcpy(out->sess_open_cls_id, data->sess_open_cls_id, sizeof(data->sess_open_cls_id));	// 세션개시종료코드, BS: 보드개시\n BE: 보드종료\n SS: 세션개시\n SE: 세션종료\n SH:세션정지\n SR:세션재개
	memcpy(out->sess_id, data->sess_id, sizeof(data->sess_id));	// 세션ID, ※ 코드값모음 참조
	memcpy(out->pbl_stk_code, data->pbl_stk_code, sizeof(data->pbl_stk_code));	// 상장사종목코드, 종목조치의 기준이 되는 종목코드\n *비상장사의 종목코드도 사용될 수 있음
	memcpy(out->trsp_rsn_code, data->trsp_rsn_code, sizeof(data->trsp_rsn_code));	// 거래정지사유코드, ※ 코드값모음 참조 *조기종료(KO) 는 " "
	out->trsp_trgg_code = data->trsp_trgg_code[0];	//거래정지발생유형코드, 1:자기종목 2:신주인수권증권 3:신주인수권증서 4:기초자산ELW\n 5:발행ELW 6:상장사 7:기초자산소속시장 *조기종료(KO)는 "1" \n9:발행자(ETN) 2014.11.17
	out->apl_step = Str2Int(data->apl_step, sizeof(data->apl_step));	// 적용단계, CB 및 가격제한폭 확대시 적용되는 단계(그 외의 경우는 "00")

	return 1;
}


// 코스피_결산일 정보
int ParseI5011(const double& timestamp, const char* in_buff, DF_KOSPI_STGD_INFO* out) {
	KOSPI_STGD_INFO* data = (KOSPI_STGD_INFO*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA구분, I5
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// 정보구분, 01:주식
	out->mkt_clsf = data->mkt_clsf[0];	//시장구분, 1:유가증권 2:코스닥
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// 종목코드, 표준코드
	out->snr = Str2Int(data->snr, sizeof(data->snr));	// 일련번호, 1~99999999 건수체크용
	memcpy(out->clsg_date, data->clsg_date, sizeof(data->clsg_date));	// 결산월일, 상장사의 회계 결산일(12월 31일, 6월 30일, 3월 31일)\n결산기나 결산월일 경우는 12월일 경우 '1200'로 표시됨\n※주식, 해외원주, DR : 결산월(최대 1개)\n※리츠 : 결산월(일반적으로 2개, 최대 12개)\n※ETF, 해외ETF : 분배기준일(최대 12개)\n※증권투자회사(MF), 인프라투융자회사 : 결산일(최대 12개)\n※선박투자회사 : 배당기준일(일반적으로 4개, 최대 12개)

	return 1;
}


// 코스피_LP 정보
int ParseI7011(const double& timestamp, const char* in_buff, DF_KOSPI_LP_INFO* out) {
	KOSPI_LP_INFO* data = (KOSPI_LP_INFO*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA구분, I7
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// 정보구분, 01:주식
	out->mkt_clsf = data->mkt_clsf[0];	//시장구분, 1:유가증권 2:코스닥
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// 종목코드, 표준코드
	out->snr = Str2Int(data->snr, sizeof(data->snr));	// 일련번호, 1~99999999 건수체크용
	memcpy(out->mkt_ptcp_nr, data->mkt_ptcp_nr, sizeof(data->mkt_ptcp_nr));	// 시장참가자번호, 시장참가자를 식별/구분할 수 있는 번호\n한 시장참가자가 여러 거래소의 회원이면 거래소별로\n시장참가자번호를 달리함 예) '00001'
	memcpy(out->lp_open_date, data->lp_open_date, sizeof(data->lp_open_date));	// LP개시일자, 유동성공급개시일자
	memcpy(out->lp_cls_date, data->lp_cls_date, sizeof(data->lp_cls_date));	// LP종료일자, 유동성공급종료일자
	out->min_ask_qty_mtp = Str2Dbl(data->min_ask_qty_mtp, sizeof(data->min_ask_qty_mtp), 0);	// 최소호가수량배수, LP/MM 호가시 매매수량단위의 최소배수\n예) 값이 10이고 매매수량단위가 10주(계약)이면 LP/MM 호가는\n100주(계약) 이상으로 호가해야함
	out->max_ask_qty_mtp = Str2Dbl(data->max_ask_qty_mtp, sizeof(data->max_ask_qty_mtp), 0);	// 최대호가수량배수, LP/MM 호가시 매매수량단위의 최대배수
	out->ask_prc_sprd_unit_code = data->ask_prc_sprd_unit_code[0];	//호가스프레드단위코드, R:가격비율\nY:수익률비율(채권)\nT:호가가격단위 배수\nA:절대값 (채권)\n*구명칭:제한단위구분코드
	out->ask_prc_sprd_val = Str2Dbl(data->ask_prc_sprd_val, sizeof(data->ask_prc_sprd_val), 8);	// 호가스프레드값, LP/MM 호가 제출할 의무가 발생하는 최우선호가스프레드\n간격 또는 비율 9(13)V9(8)
	out->off_mkt_ask_sprd_mtp = Str2Dbl(data->off_mkt_ask_sprd_mtp, sizeof(data->off_mkt_ask_sprd_mtp), 0);	// 휴장호가스프레드배수, 파생,ELW,ETF의 기초자산이 해외시장의 지수 또는 종목인 경우 해당 시장이 휴일, 장개시전, 장종류후, 휴장 등의 사유로 추적자산의 현재 가치를 판단할 수 없을 때 시장 조성 계약별로 약정한 스프레드 보다 확대된 스프레드를 허용하기 위한 배수\n*구명칭:휴장호가스프레드값\n구 휴장호가스프레드값 = 휴장호가스프레드배수 * 호가스프레드값\n(Exture에서 휴장호가스프레드값이 0인경우 Exture+에서는 호가스프레드값과 일치시킴) 2014.03.03
	out->obgt_ask_sbmt_time_invl = Str2Int(data->obgt_ask_sbmt_time_invl, sizeof(data->obgt_ask_sbmt_time_invl));	// 의무호가제출시간간격, 단위:초(sec)\n00초 이내에 최우선호가간격을 축소시키는 매도호가 또는 매수호가를 제출
	out->ask_min_ask_prc_amt = Str2Dbl(data->ask_min_ask_prc_amt, sizeof(data->ask_min_ask_prc_amt), 3);	// 매도최소호가금액, 9(18)V9(3) 2009.07.27
	out->bid_min_ask_prc_amt = Str2Dbl(data->bid_min_ask_prc_amt, sizeof(data->bid_min_ask_prc_amt), 3);	// 매수최소호가금액, 9(18)V9(3) 2009.07.27
	out->min_ask_amt = Str2Dbl(data->min_ask_amt, sizeof(data->min_ask_amt), 3);	// 최소호가금액, 9(18)V9(3) (2015.11.23 추가)\nMM(시장조성자)호가의 최소금액\n※LP최소호가수량배수와 배타적으로 사용, LP최소호가수량배수에 값이 설정된 경우 해당 필드는 무시
	out->max_ask_amt = Str2Dbl(data->max_ask_amt, sizeof(data->max_ask_amt), 3);	// 최대호가금액, 9(18)V9(3) (2015.11.23 추가)\n최대호가금액

	return 1;
}


// 코스피_현재등락
int ParseB5011(const double& timestamp, const char* in_buff, DF_KOSPI_CUR_FLCT* out) {
	KOSPI_CUR_FLCT* data = (KOSPI_CUR_FLCT*)in_buff;

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


// 코스피_시간외단일가_리커버리
int ParseB4011(const double& timestamp, const char* in_buff, DF_KOSPI_OFH_RCVR* out) {
	KOSPI_OFH_RCVR* data = (KOSPI_OFH_RCVR*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA구분, B4:시간외단일가 시세, B3:시간외단일가최종
	out->info_clsf = Str2Int(data->info_clsf, sizeof(data->info_clsf));	// 정보구분, 01:주식
	out->mkt_clsf = Str2Int(data->mkt_clsf, sizeof(data->mkt_clsf));	// 시장구분, 1:유가증권 2:코스닥
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// 종목코드, 표준코드
	out->stk_snr = Str2Int(data->stk_snr, sizeof(data->stk_snr));	// 종목일련번호, 종목배치(A0)의 종목일련번호 2014.03.03
	out->ofhr_cnst_clsf = data->ofhr_cnst_clsf[0];	//시간외단일가대비구분, 0:판단불가 1:상한 2:상승 3:보합 4:하한 5:하락
	out->ofhr_cnst = Str2Int(data->ofhr_cnst, sizeof(data->ofhr_cnst));	// 시간외단일가대비, 단위:원
	out->ofhr_cnst_ceil = Str2Int(data->ofhr_cnst_ceil, sizeof(data->ofhr_cnst_ceil));	// 시간외단일가상한가
	out->ofhr_cnst_flr = Str2Int(data->ofhr_cnst_flr, sizeof(data->ofhr_cnst_flr));	// 시간외단일가하한가
	out->ofhr_cnst_cur = Str2Int(data->ofhr_cnst_cur, sizeof(data->ofhr_cnst_cur));	// 시간외단일가현재가
	out->ofhr_cnst_open = Str2Int(data->ofhr_cnst_open, sizeof(data->ofhr_cnst_open));	// 시간외단일가시가
	out->ofhr_cnst_hi = Str2Int(data->ofhr_cnst_hi, sizeof(data->ofhr_cnst_hi));	// 시간외단일가고가
	out->ofhr_cnst_lo = Str2Int(data->ofhr_cnst_lo, sizeof(data->ofhr_cnst_lo));	// 시간외단일가저가
	out->ofhr_cnst_ask = Str2Int(data->ofhr_cnst_ask, sizeof(data->ofhr_cnst_ask));	// 시간외단일가매도호가
	out->ofhr_cnst_bid = Str2Int(data->ofhr_cnst_bid, sizeof(data->ofhr_cnst_bid));	// 시간외단일가매수호가
	out->ofhr_cnst_cum_ccls_qty = Str2Dbl(data->ofhr_cnst_cum_ccls_qty, sizeof(data->ofhr_cnst_cum_ccls_qty), 0);	// 시간외단일가누적 체결수량
	out->ofhr_cnst_cum_trd_val = Str2Dbl(data->ofhr_cnst_cum_trd_val, sizeof(data->ofhr_cnst_cum_trd_val), 0);	// 시간외단일가누적 거래대금
	out->tot_cum_ccls_qty = Str2Dbl(data->tot_cum_ccls_qty, sizeof(data->tot_cum_ccls_qty), 0);	// 전체 총 누적체결수량, 단위:주 ※당일 전체 누적
	out->tot_cum_trd_val = Str2Dbl(data->tot_cum_trd_val, sizeof(data->tot_cum_trd_val), 0);	// 전체 총 누적거래대금, 단위:원 ※당일 전체 누적
	out->ofhr_mkt_clsf = Str2Int(data->ofhr_mkt_clsf, sizeof(data->ofhr_mkt_clsf));	// 시간외단일가장구분, 0:초기값 1:시간외단일가개시 2:시간외단일가마감
	out->trsp_flg = data->trsp_flg[0];	//거래정지여부, Y, N
	out->trend_flg = data->trend_flg[0];	//실세/기세 구분, 0:초기값 1:실세 2:기세 3:거래무 4:시가기준가종목의 기세

	return 1;
}


// 코스피_시간외단일가_리커버리_최종
int ParseB3011(const double& timestamp, const char* in_buff, DF_KOSPI_OFH_RCVR_FINAL* out) {
	KOSPI_OFH_RCVR_FINAL* data = (KOSPI_OFH_RCVR_FINAL*)in_buff;

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
	out->ofhr_cnst_cum_ccls_qty = Str2Dbl(data->ofhr_cnst_cum_ccls_qty, sizeof(data->ofhr_cnst_cum_ccls_qty), 0);	// 시간외단일가누적 체결수량
	out->ofhr_cnst_cum_trd_val = Str2Dbl(data->ofhr_cnst_cum_trd_val, sizeof(data->ofhr_cnst_cum_trd_val), 0);	// 시간외단일가누적 거래대금
	out->tot_cum_ccls_qty = Str2Dbl(data->tot_cum_ccls_qty, sizeof(data->tot_cum_ccls_qty), 0);	// 전체 총 누적체결수량
	out->tot_cum_trd_val = Str2Dbl(data->tot_cum_trd_val, sizeof(data->tot_cum_trd_val), 0);	// 전체 총 누적거래대금
	out->ofhr_mkt_clsf = data->ofhr_mkt_clsf[0];	//시간외단일가장구분, 0:초기값 1:시간외단일가개시 2:시간외단일가마감
	out->trsp_flg = data->trsp_flg[0];	//거래정지여부, Y, N
	out->trend_flg = data->trend_flg[0];	//실세/기세 구분, 0:초기값 1:실세 2:기세 3:거래무 4:시가기준가종목의 기세

	return 1;
}


// 코스피_호가잔량_LP호가_제외
int ParseB6011(const double& timestamp, const char* in_buff, DF_KOSPI_ASK_RSD_WOLP* out) {
	int i=0;
	KOSPI_ASK_RSD_WOLP* data = (KOSPI_ASK_RSD_WOLP*)in_buff;

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
	out->ofhr_ask_tot_rsd = Str2Dbl(data->ofhr_ask_tot_rsd, sizeof(data->ofhr_ask_tot_rsd), 0);	// 장종료후시간외 매도총호가잔량, 보드ID가 "G3"일 경우 설정됨
	out->ofhr_bid_tot_rsd = Str2Dbl(data->ofhr_bid_tot_rsd, sizeof(data->ofhr_bid_tot_rsd), 0);	// 장종료후시간외 매수총호가잔량, 보드ID가 "G3"일 경우 설정됨
	memcpy(out->sess_id, data->sess_id, sizeof(data->sess_id));	// 세션ID, ※ 코드값모음 참조
	memcpy(out->brd_id, data->brd_id, sizeof(data->brd_id));	// 보드ID, ※ 코드값모음 참조
	out->exp_ccls_prc = Str2Int(data->exp_ccls_prc, sizeof(data->exp_ccls_prc));	// 예상체결가격
	out->exp_ccls_qty = Str2Dbl(data->exp_ccls_qty, sizeof(data->exp_ccls_qty), 0);	// 예상체결수량
	out->cmpt_msv_dir_clsf = Str2Int(data->cmpt_msv_dir_clsf, sizeof(data->cmpt_msv_dir_clsf));	// 경쟁대량 방향구분, 0:해당없음, 1:매도, 2:매수

	return 1;
}


// 코스피_호가잔량_LP호가_포함
int ParseB7011(const double& timestamp, const char* in_buff, DF_KOSPI_ASK_RSD_WLP* out) {
	int i=0;
	KOSPI_ASK_RSD_WLP* data = (KOSPI_ASK_RSD_WLP*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA구분, B7
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// 정보구분, 01:유가증권종목 02:ELW
	out->mkt_clsf = data->mkt_clsf[0];	//시장구분, 1:유가증권
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// 종목코드, 표준코드
	out->stk_snr = Str2Int(data->stk_snr, sizeof(data->stk_snr));	// 종목일련번호, 종목배치(A0)의 종목일련번호
	out->cum_ccls_qty = Str2Dbl(data->cum_ccls_qty, sizeof(data->cum_ccls_qty), 0);	// 누적체결수량

	for ( i=0 ; i<10 ; i++ ) {
		out->lob_infos[i].ask_prc = Str2Int(data->lob_infos[i].ask_prc, sizeof(data->lob_infos[i].ask_prc));	// 매도호가
		out->lob_infos[i].bid_prc = Str2Int(data->lob_infos[i].bid_prc, sizeof(data->lob_infos[i].bid_prc));	// 매수호가
		out->lob_infos[i].ask_vol_rsd = Str2Dbl(data->lob_infos[i].ask_vol_rsd, sizeof(data->lob_infos[i].ask_vol_rsd), 0);	// 매도호가 잔량
		out->lob_infos[i].bid_vol_rsd = Str2Dbl(data->lob_infos[i].bid_vol_rsd, sizeof(data->lob_infos[i].bid_vol_rsd), 0);	// 매수호가 잔량
		out->lob_infos[i].lp_ask_vol_rsd = Str2Dbl(data->lob_infos[i].lp_ask_vol_rsd, sizeof(data->lob_infos[i].lp_ask_vol_rsd), 0);	// LP 매도호가 잔량
		out->lob_infos[i].lp_bid_vol_rsd = Str2Dbl(data->lob_infos[i].lp_bid_vol_rsd, sizeof(data->lob_infos[i].lp_bid_vol_rsd), 0);	// LP 매수호가 잔량
	}   // 호가

	out->ask_10_tot_rsd = Str2Dbl(data->ask_10_tot_rsd, sizeof(data->ask_10_tot_rsd), 0);	// 10단계호가매도총잔량
	out->bid_10_tot_rsd = Str2Dbl(data->bid_10_tot_rsd, sizeof(data->bid_10_tot_rsd), 0);	// 10단계호가매수총잔량
	out->ofhr_ask_tot_rsd = Str2Dbl(data->ofhr_ask_tot_rsd, sizeof(data->ofhr_ask_tot_rsd), 0);	// 장종료후시간외 매도총호가잔량, 보드ID가 "G3"일 경우 설정됨 \n ※ELW는 시간외거래 없음
	out->ofhr_bid_tot_rsd = Str2Dbl(data->ofhr_bid_tot_rsd, sizeof(data->ofhr_bid_tot_rsd), 0);	// 장종료후시간외 매수총호가잔량, 보드ID가 "G3"일 경우 설정됨\n ※ELW는 시간외거래 없음
	memcpy(out->sess_id, data->sess_id, sizeof(data->sess_id));	// 세션ID, ※ 코드값모음 참조
	memcpy(out->brd_id, data->brd_id, sizeof(data->brd_id));	// 보드ID, ※ 코드값모음 참조
	out->exp_ccls_prc = Str2Int(data->exp_ccls_prc, sizeof(data->exp_ccls_prc));	// 예상체결가격
	out->exp_ccls_qty = Str2Dbl(data->exp_ccls_qty, sizeof(data->exp_ccls_qty), 0);	// 예상체결수량
	out->cmpt_msv_dir_clsf = Str2Int(data->cmpt_msv_dir_clsf, sizeof(data->cmpt_msv_dir_clsf));	// 경쟁대량 방향구분, 0:해당없음, 1:매도, 2:매수

	return 1;
}


// 코스피_장개시전_호가잔량
int ParseB8011(const double& timestamp, const char* in_buff, DF_KOSPI_BOPEN_ASK_RSD* out) {
	KOSPI_BOPEN_ASK_RSD* data = (KOSPI_BOPEN_ASK_RSD*)in_buff;

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


// 코스피_업종별투자자별
int ParseC0011(const double& timestamp, const char* in_buff, DF_KOSPI_BYIND_BYINV* out) {
	KOSPI_BYIND_BYINV* data = (KOSPI_BYIND_BYINV*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA구분, C0
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// 정보구분, 01:주식
	out->mkt_clsf = data->mkt_clsf[0];	//시장구분, 1:유가증권 2:코스닥
	memcpy(out->cmpt_time, data->cmpt_time, sizeof(data->cmpt_time));	// 산출시각, 90초 주기
	memcpy(out->inv_code, data->inv_code, sizeof(data->inv_code));	// 투자자코드, ※코드값모음 참조\n*코드'7000'시 수량, 대금정보 항목 0으로 전송 (20181210)
	memcpy(out->ind_code, data->ind_code, sizeof(data->ind_code));	// 업종코드, ※코드값모음의 업종지수코드분류 참조\n산출업종;코스피종합지수, 코스닥종합지수, 코스피200지수
	out->ask_ccls_qty = Str2Dbl(data->ask_ccls_qty, sizeof(data->ask_ccls_qty), 0);	// 매도체결수량, 단위:주
	out->ask_trd_val = Str2Dbl(data->ask_trd_val, sizeof(data->ask_trd_val), 0);	// 매도거래대금, 단위:원
	out->bid_ccls_qty = Str2Dbl(data->bid_ccls_qty, sizeof(data->bid_ccls_qty), 0);	// 매수체결수량, 단위:주
	out->bid_trd_val = Str2Dbl(data->bid_trd_val, sizeof(data->bid_trd_val), 0);	// 매수거래대금, 단위:원

	return 1;
}


// 코스피_프로그램매매 호가
int ParseC3011(const double& timestamp, const char* in_buff, DF_KOSPI_PRGTRD_ASK* out) {
	KOSPI_PRGTRD_ASK* data = (KOSPI_PRGTRD_ASK*)in_buff;

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
	out->idx_abtg_ask_ccls_qty = Str2Dbl(data->idx_abtg_ask_ccls_qty, sizeof(data->idx_abtg_ask_ccls_qty), 0);	// 지수차익매도위탁 체결수량
	out->idx_abtg_ask_self_ccls_qty = Str2Dbl(data->idx_abtg_ask_self_ccls_qty, sizeof(data->idx_abtg_ask_self_ccls_qty), 0);	// 지수차익매도자기 체결수량
	out->idx_abtg_bid_ccls_qty = Str2Dbl(data->idx_abtg_bid_ccls_qty, sizeof(data->idx_abtg_bid_ccls_qty), 0);	// 지수차익매수위탁 체결수량
	out->idx_abtg_bid_self_ccls_qty = Str2Dbl(data->idx_abtg_bid_self_ccls_qty, sizeof(data->idx_abtg_bid_self_ccls_qty), 0);	// 지수차익매수자기 체결수량
	out->idx_nabtg_ask_ccls_qty = Str2Dbl(data->idx_nabtg_ask_ccls_qty, sizeof(data->idx_nabtg_ask_ccls_qty), 0);	// 지수비차익매도위탁 체결수량
	out->idx_nabtg_ask_self_ccls_qty = Str2Dbl(data->idx_nabtg_ask_self_ccls_qty, sizeof(data->idx_nabtg_ask_self_ccls_qty), 0);	// 지수비차익매도자기 체결수량
	out->idx_nabtg_bid_ccls_qty = Str2Dbl(data->idx_nabtg_bid_ccls_qty, sizeof(data->idx_nabtg_bid_ccls_qty), 0);	// 지수비차익매수위탁 체결수량
	out->idx_nabtg_bid_self_ccls_qty = Str2Dbl(data->idx_nabtg_bid_self_ccls_qty, sizeof(data->idx_nabtg_bid_self_ccls_qty), 0);	// 지수비차익매수자기 체결수량
	out->idx_abtg_ask_ccls_val = Str2Dbl(data->idx_abtg_ask_ccls_val, sizeof(data->idx_abtg_ask_ccls_val), 0);	// 지수차익매도위탁 체결금액
	out->idx_abtg_ask_self_ccls_val = Str2Dbl(data->idx_abtg_ask_self_ccls_val, sizeof(data->idx_abtg_ask_self_ccls_val), 0);	// 지수차익매도자기 체결금액
	out->idx_abtg_bid_ccls_val = Str2Dbl(data->idx_abtg_bid_ccls_val, sizeof(data->idx_abtg_bid_ccls_val), 0);	// 지수차익매수위탁 체결금액
	out->idx_abtg_bid_self_ccls_val = Str2Dbl(data->idx_abtg_bid_self_ccls_val, sizeof(data->idx_abtg_bid_self_ccls_val), 0);	// 지수차익매수자기 체결금액
	out->idx_nabtg_ask_ccls_val = Str2Dbl(data->idx_nabtg_ask_ccls_val, sizeof(data->idx_nabtg_ask_ccls_val), 0);	// 지수비차익매도위탁 체결금액
	out->idx_nabtg_ask_self_ccls_val = Str2Dbl(data->idx_nabtg_ask_self_ccls_val, sizeof(data->idx_nabtg_ask_self_ccls_val), 0);	// 지수비차익매도자기 체결금액
	out->idx_nabtg_bid_ccls_val = Str2Dbl(data->idx_nabtg_bid_ccls_val, sizeof(data->idx_nabtg_bid_ccls_val), 0);	// 지수비차익매수위탁 체결금액
	out->idx_nabtg_bid_self_ccls_val = Str2Dbl(data->idx_nabtg_bid_self_ccls_val, sizeof(data->idx_nabtg_bid_self_ccls_val), 0);	// 지수비차익매수자기 체결금액
	out->post_idx_abtg_ask_rsd = Str2Dbl(data->post_idx_abtg_ask_rsd, sizeof(data->post_idx_abtg_ask_rsd), 0);	// 지수차익매도호가잔량, 2011.05.30 신규
	out->post_idx_abtg_bid_rsd = Str2Dbl(data->post_idx_abtg_bid_rsd, sizeof(data->post_idx_abtg_bid_rsd), 0);	// 지수차익매수호가잔량, 2011.05.30 신규
	out->post_idx_nabtg_ask_rsd = Str2Dbl(data->post_idx_nabtg_ask_rsd, sizeof(data->post_idx_nabtg_ask_rsd), 0);	// 지수비차익매도호가잔량, 2011.05.30 신규
	out->post_idx_nabtg_bid_rsd = Str2Dbl(data->post_idx_nabtg_bid_rsd, sizeof(data->post_idx_nabtg_bid_rsd), 0);	// 지수비차익매수호가잔량, 2011.05.30 신규

	return 1;
}


// 코스피_프로그램매매 전체집계
int ParseJ0011(const double& timestamp, const char* in_buff, DF_KOSPI_PRGTRD_TOT* out) {
	KOSPI_PRGTRD_TOT* data = (KOSPI_PRGTRD_TOT*)in_buff;

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
	out->idx_abtg_ask_ccls_qty = Str2Dbl(data->idx_abtg_ask_ccls_qty, sizeof(data->idx_abtg_ask_ccls_qty), 0);	// 지수차익매도위탁 체결수량
	out->idx_abtg_ask_self_ccls_qty = Str2Dbl(data->idx_abtg_ask_self_ccls_qty, sizeof(data->idx_abtg_ask_self_ccls_qty), 0);	// 지수차익매도자기 체결수량
	out->idx_abtg_bid_ccls_qty = Str2Dbl(data->idx_abtg_bid_ccls_qty, sizeof(data->idx_abtg_bid_ccls_qty), 0);	// 지수차익매수위탁 체결수량
	out->idx_abtg_bid_self_ccls_qty = Str2Dbl(data->idx_abtg_bid_self_ccls_qty, sizeof(data->idx_abtg_bid_self_ccls_qty), 0);	// 지수차익매수자기 체결수량
	out->idx_nabtg_ask_ccls_qty = Str2Dbl(data->idx_nabtg_ask_ccls_qty, sizeof(data->idx_nabtg_ask_ccls_qty), 0);	// 지수비차익매도위탁 체결수량
	out->idx_nabtg_ask_self_ccls_qty = Str2Dbl(data->idx_nabtg_ask_self_ccls_qty, sizeof(data->idx_nabtg_ask_self_ccls_qty), 0);	// 지수비차익매도자기 체결수량
	out->idx_nabtg_bid_ccls_qty = Str2Dbl(data->idx_nabtg_bid_ccls_qty, sizeof(data->idx_nabtg_bid_ccls_qty), 0);	// 지수비차익매수위탁 체결수량
	out->idx_nabtg_bid_self_ccls_qty = Str2Dbl(data->idx_nabtg_bid_self_ccls_qty, sizeof(data->idx_nabtg_bid_self_ccls_qty), 0);	// 지수비차익매수자기 체결수량
	out->idx_abtg_ask_ccls_val = Str2Dbl(data->idx_abtg_ask_ccls_val, sizeof(data->idx_abtg_ask_ccls_val), 0);	// 지수차익매도위탁 체결금액
	out->idx_abtg_ask_self_ccls_val = Str2Dbl(data->idx_abtg_ask_self_ccls_val, sizeof(data->idx_abtg_ask_self_ccls_val), 0);	// 지수차익매도자기 체결금액
	out->idx_abtg_bid_ccls_val = Str2Dbl(data->idx_abtg_bid_ccls_val, sizeof(data->idx_abtg_bid_ccls_val), 0);	// 지수차익매수위탁 체결금액
	out->idx_abtg_bid_self_ccls_val = Str2Dbl(data->idx_abtg_bid_self_ccls_val, sizeof(data->idx_abtg_bid_self_ccls_val), 0);	// 지수차익매수자기 체결금액
	out->idx_nabtg_ask_ccls_val = Str2Dbl(data->idx_nabtg_ask_ccls_val, sizeof(data->idx_nabtg_ask_ccls_val), 0);	// 지수비차익매도위탁 체결금액
	out->idx_nabtg_ask_self_ccls_val = Str2Dbl(data->idx_nabtg_ask_self_ccls_val, sizeof(data->idx_nabtg_ask_self_ccls_val), 0);	// 지수비차익매도자기 체결금액
	out->idx_nabtg_bid_ccls_val = Str2Dbl(data->idx_nabtg_bid_ccls_val, sizeof(data->idx_nabtg_bid_ccls_val), 0);	// 지수비차익매수위탁 체결금액
	out->idx_nabtg_bid_self_ccls_val = Str2Dbl(data->idx_nabtg_bid_self_ccls_val, sizeof(data->idx_nabtg_bid_self_ccls_val), 0);	// 지수비차익매수자기 체결금액
	out->post_idx_abtg_ask_rsd = Str2Dbl(data->post_idx_abtg_ask_rsd, sizeof(data->post_idx_abtg_ask_rsd), 0);	// 지수차익매도호가잔량
	out->post_idx_abtg_bid_rsd = Str2Dbl(data->post_idx_abtg_bid_rsd, sizeof(data->post_idx_abtg_bid_rsd), 0);	// 지수차익매수호가잔량
	out->post_idx_nabtg_ask_rsd = Str2Dbl(data->post_idx_nabtg_ask_rsd, sizeof(data->post_idx_nabtg_ask_rsd), 0);	// 지수비차익매도호가잔량
	out->post_idx_nabtg_bid_rsd = Str2Dbl(data->post_idx_nabtg_bid_rsd, sizeof(data->post_idx_nabtg_bid_rsd), 0);	// 지수비차익매수호가잔량

	return 1;
}


// 코스피_프로그램매매 사전공시
int ParseC5011(const double& timestamp, const char* in_buff, DF_KOSPI_PRGTRD_DCLS* out) {
	KOSPI_PRGTRD_DCLS* data = (KOSPI_PRGTRD_DCLS*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA구분, C5
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// 정보구분, 01:주식
	out->mkt_clsf = data->mkt_clsf[0];	//시장구분, 1:유가증권 2:코스닥
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// 종목코드
	out->snr = Str2Int(data->snr, sizeof(data->snr));	// 일련번호, 1~99999999 종목일련번호 2014.03.03
	out->prior_dcls_new_ask_qty = Str2Dbl(data->prior_dcls_new_ask_qty, sizeof(data->prior_dcls_new_ask_qty), 0);	// 사전공시신규호가 매도수량, 단위 : 주\n항목명변경:매도공시사전수량->사전공시신규호가매도수량
	out->prior_dcls_new_bid_qty = Str2Dbl(data->prior_dcls_new_bid_qty, sizeof(data->prior_dcls_new_bid_qty), 0);	// 사전공시신규호가 매수수량, 단위 : 주\n항목명변경:매수공시사전수량->사전공시신규호가매수수량
	out->prior_dcls_sbmt_ask_qty = Str2Dbl(data->prior_dcls_sbmt_ask_qty, sizeof(data->prior_dcls_sbmt_ask_qty), 0);	// 사전공시기제출호가 매도수량, 단위 : 주\n항목명변경:매도공시사전정정수량->사전공시기제출호가매도수량
	out->prior_dcls_sbmt_bid_qty = Str2Dbl(data->prior_dcls_sbmt_bid_qty, sizeof(data->prior_dcls_sbmt_bid_qty), 0);	// 사전공시기제출호가 매수수량, 단위 : 주\n항목명변경:매수공시사전정정수량->사전공시기제출호가매수수량
	out->post_dcls_ask_qty = Str2Dbl(data->post_dcls_ask_qty, sizeof(data->post_dcls_ask_qty), 0);	// 사후공시매도수량, 단위 : 주, 신규 2011.05.03
	out->post_dcls_bid_qty = Str2Dbl(data->post_dcls_bid_qty, sizeof(data->post_dcls_bid_qty), 0);	// 사후공시매수수량, 단위 : 주, 신규 2011.05.03

	return 1;
}


// 유가 프로그램매매 투자자별 매매현황
int ParseP0011(const double& timestamp, const char* in_buff, DF_PRGTRD_BYINV_STAT* out) {
	PRGTRD_BYINV_STAT* data = (PRGTRD_BYINV_STAT*)in_buff;

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


// 코스피_공매도
int ParseI8011(const double& timestamp, const char* in_buff, DF_KOSPI_SHORT* out) {
	KOSPI_SHORT* data = (KOSPI_SHORT*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA구분, I8
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// 정보구분, 01:주식
	out->mkt_clsf = data->mkt_clsf[0];	//시장구분, 1:유가증권 2:코스닥
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// 종목코드, 표준코드
	out->snr = Str2Int(data->snr, sizeof(data->snr));	// 일련번호, 1~99999999 종목일련번호 2014.03.03
	out->short_brwg_ask_ccls_qty = Str2Dbl(data->short_brwg_ask_ccls_qty, sizeof(data->short_brwg_ask_ccls_qty), 0);	// 공매도차입증권매도 체결수량, 단위:주
	out->short_brwg_ask_trd_val = Str2Dbl(data->short_brwg_ask_trd_val, sizeof(data->short_brwg_ask_trd_val), 0);	// 공매도차입증권매도 거래대금, 단위:원

	return 1;
}


// 코스피_Buy-in_실행수량
int ParseO4011(const double& timestamp, const char* in_buff, DF_KOSPI_BIN_EXCQ* out) {
	KOSPI_BIN_EXCQ* data = (KOSPI_BIN_EXCQ*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA구분, O4
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// 정보구분, 01:주식
	out->mkt_clsf = data->mkt_clsf[0];	//시장구분, 1:유가증권, 2:코스닥, 8:코넥스
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// 종목코드, 표준코드 또는 "999999999999" 개발가이드 참조
	out->snr = Str2Int(data->snr, sizeof(data->snr));	// 일련번호, ※ Buy-in구분코드별로 일련번호 설정
	memcpy(out->trsm_date, data->trsm_date, sizeof(data->trsm_date));	// 전송일자, YYYYMMDD
	out->bin_clsf_code = data->bin_clsf_code[0];	//Buy-in구분코드, 1: 일반 Buy-in, 2: 당일 Buy-in
	out->scrt_grp_id = Str2Int(data->scrt_grp_id, sizeof(data->scrt_grp_id));	// 증권그룹ID, ST:주식, MF:증권투자회사, RT:리츠, SC:선박투자회사,\nIF:인프라투융자회사, DR:예탁증서, SW:신주인수권증권,\nSR:신주인수권증서, EW:주식워런트증권, EF:상장지수펀드,\nBC:수익증권, FE:해외ETF, FS:해외원주,\nEN:ETN(2014.11.17)
	out->bin_exc_qty = Str2Dbl(data->bin_exc_qty, sizeof(data->bin_exc_qty), 0);	// Buy-in 실행수량

	return 1;
}


// 코스닥_Buy-in_실행수량
int ParseO4012(const double& timestamp, const char* in_buff, DF_KOSDQ_BIN_EXCQ* out) {
	KOSDQ_BIN_EXCQ* data = (KOSDQ_BIN_EXCQ*)in_buff;

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


// 코넥스_Buy-in_실행수량
int ParseO4018(const double& timestamp, const char* in_buff, DF_KONEX_BIN_EXCQ* out) {
	KONEX_BIN_EXCQ* data = (KONEX_BIN_EXCQ*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA구분, O4
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// 정보구분, 01:주식
	out->mkt_clsf = data->mkt_clsf[0];	//시장구분, 8:코넥스
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// 종목코드, 표준코드 또는 "999999999999" 개발가이드 참조
	out->snr = Str2Int(data->snr, sizeof(data->snr));	// 일련번호, ※ Buy-in구분코드별로 일련번호 설정
	memcpy(out->trsm_date, data->trsm_date, sizeof(data->trsm_date));	// 전송일자, YYYYMMDD
	out->bin_clsf_code = data->bin_clsf_code[0];	//Buy-in구분코드, 1: 일반 Buy-in, 2: 당일 Buy-in
	out->scrt_grp_id = Str2Int(data->scrt_grp_id, sizeof(data->scrt_grp_id));	// 증권그룹ID, ST:주식, MF:증권투자회사, RT:리츠, SC:선박투자회사,\nIF:인프라투융자회사, DR:예탁증서, SW:신주인수권증권,\nSR:신주인수권증서, EW:주식워런트증권, EF:상장지수펀드,\nBC:수익증권, FE:해외ETF, FS:해외원주
	out->bin_exc_qty = Str2Dbl(data->bin_exc_qty, sizeof(data->bin_exc_qty), 0);	// Buy-in 실행수량

	return 1;
}


// 코스피_시세종가
int ParseB1011(const double& timestamp, const char* in_buff, DF_KOSPI_MKT_PRC_CLS* out) {
	KOSPI_MKT_PRC_CLS* data = (KOSPI_MKT_PRC_CLS*)in_buff;

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
	out->high = Str2Int(data->high, sizeof(data->high));	// 고가, 정규장 고가
	out->low = Str2Int(data->low, sizeof(data->low));	// 저가, 정규장 저가
	out->ask_prc = Str2Int(data->ask_prc, sizeof(data->ask_prc));	// 매도호가, B1시 0값 SET
	out->bid_prc = Str2Int(data->bid_prc, sizeof(data->bid_prc));	// 매수호가, B1시 0값 SET
	out->cum_ccls_qty = Str2Dbl(data->cum_ccls_qty, sizeof(data->cum_ccls_qty), 0);	// 누적체결수량, 단위:주 ※시간외단일가, BUY-IN을 제외한 모든 체결수량 합산
	out->cum_trd_val = Str2Dbl(data->cum_trd_val, sizeof(data->cum_trd_val), 0);	// 누적거래대금, 단위:원 ※시간외단일가, BUY-IN을 제외한 모든 거래대금 합산
	out->trend_flg = data->trend_flg[0];	//실세/기세 구분, 0:초기값 1:실세 2:기세 3:거래무 4:시가기준가종목의 기세
	memcpy(out->brd_evt_id, data->brd_evt_id, sizeof(data->brd_evt_id));	// 보드이벤트ID, B1/B2 에서는 보드이벤트ID 사용금지(과거 상태값이 전송될 수 있음). 추후, 해당 항목 '000' 세팅 예정. 2014.03.24)
	memcpy(out->brd_id, data->brd_id, sizeof(data->brd_id));	// 보드ID, ※ 코드값모음 참조
	out->trsp_flg = data->trsp_flg[0];	//거래정지여부, Y, N
	out->bopen_ofhr_ccls_qty = Str2Dbl(data->bopen_ofhr_ccls_qty, sizeof(data->bopen_ofhr_ccls_qty), 0);	// 장개시전시간외종가 체결수량, 대량, 바스켓은 제외, 단위:주
	out->bopen_ofhr_trd_val = Str2Dbl(data->bopen_ofhr_trd_val, sizeof(data->bopen_ofhr_trd_val), 0);	// 장개시전시간외종가 거래대금, 대량, 바스켓은 제외, 단위:원
	out->opr_time_ccls_qty = Str2Dbl(data->opr_time_ccls_qty, sizeof(data->opr_time_ccls_qty), 0);	// 정규장체결수량, 대량, 바스켓은 제외, 단위:주
	out->opr_time_trd_val = Str2Dbl(data->opr_time_trd_val, sizeof(data->opr_time_trd_val), 0);	// 정규장거래대금, 대량, 바스켓은 제외, 단위:원
	out->ofhr_cls_ccls_qty = Str2Dbl(data->ofhr_cls_ccls_qty, sizeof(data->ofhr_cls_ccls_qty), 0);	// 장종료후시간외종가 체결수량, 대량, 바스켓은 제외, 단위:주
	out->ofhr_cls_trd_val = Str2Dbl(data->ofhr_cls_trd_val, sizeof(data->ofhr_cls_trd_val), 0);	// 장종료후시간외종가 거래대금, 대량, 바스켓은 제외, 단위:원
	out->elw_ely_cls_flg = data->elw_ely_cls_flg[0];	//ELW조기종료여부, Y,N 조기종료ELW 外 종목은 Default 'N' SET 2010.08.30
	out->elw_ely_cls_time = Str2Int(data->elw_ely_cls_time, sizeof(data->elw_ely_cls_time));	// ELW조기종료시간, HHMMSS, ELW조기종료여부가 'Y'인 경우만 설정
	out->cmpt_msv_dir_clsf = Str2Int(data->cmpt_msv_dir_clsf, sizeof(data->cmpt_msv_dir_clsf));	// 경쟁대량 방향구분, 0:해당없음, 1:매도, 2:매수
	out->gen_bin_ccls_qty = Str2Dbl(data->gen_bin_ccls_qty, sizeof(data->gen_bin_ccls_qty), 0);	// 일반 Buy-in 체결수량, 단위:주
	out->gen_bin_ccls_trd_val = Str2Dbl(data->gen_bin_ccls_trd_val, sizeof(data->gen_bin_ccls_trd_val), 0);	// 일반 Buy-in 거래대금, 단위:원
	out->day_bin_ccls_qty = Str2Dbl(data->day_bin_ccls_qty, sizeof(data->day_bin_ccls_qty), 0);	// 당일 Buy-in 체결수량, 단위:주
	out->day_bin_ccls_trd_val = Str2Dbl(data->day_bin_ccls_trd_val, sizeof(data->day_bin_ccls_trd_val), 0);	// 당일 Buy-in 거래대금, 단위:원

	return 1;
}


// 코스피_시세RECOVERY
int ParseB2011(const double& timestamp, const char* in_buff, DF_KOSPI_MKT_PRC_RCVR* out) {
	KOSPI_MKT_PRC_RCVR* data = (KOSPI_MKT_PRC_RCVR*)in_buff;

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
	out->high = Str2Int(data->high, sizeof(data->high));	// 고가, 정규장 고가
	out->low = Str2Int(data->low, sizeof(data->low));	// 저가, 정규장 저가
	out->ask_prc = Str2Int(data->ask_prc, sizeof(data->ask_prc));	// 매도호가, B1시 0값 SET
	out->bid_prc = Str2Int(data->bid_prc, sizeof(data->bid_prc));	// 매수호가, B1시 0값 SET
	out->cum_ccls_qty = Str2Dbl(data->cum_ccls_qty, sizeof(data->cum_ccls_qty), 0);	// 누적체결수량, 단위:주 ※시간외단일가, BUY-IN을 제외한 모든 체결수량 합산
	out->cum_trd_val = Str2Dbl(data->cum_trd_val, sizeof(data->cum_trd_val), 0);	// 누적거래대금, 단위:원 ※시간외단일가, BUY-IN을 제외한 모든 거래대금 합산
	out->trend_flg = data->trend_flg[0];	//실세/기세 구분, 0:초기값 1:실세 2:기세 3:거래무 4:시가기준가종목의 기세
	memcpy(out->brd_evt_id, data->brd_evt_id, sizeof(data->brd_evt_id));	// 보드이벤트ID, B1/B2 에서는 보드이벤트ID 사용금지(과거 상태값이 전송될 수 있음). 추후, 해당 항목 '000' 세팅 예정. 2014.03.24)
	memcpy(out->brd_id, data->brd_id, sizeof(data->brd_id));	// 보드ID, ※ 코드값모음 참조
	out->trsp_flg = data->trsp_flg[0];	//거래정지여부, Y, N
	out->bopen_ofhr_ccls_qty = Str2Dbl(data->bopen_ofhr_ccls_qty, sizeof(data->bopen_ofhr_ccls_qty), 0);	// 장개시전시간외종가 체결수량, 대량, 바스켓은 제외, 단위:주
	out->bopen_ofhr_trd_val = Str2Dbl(data->bopen_ofhr_trd_val, sizeof(data->bopen_ofhr_trd_val), 0);	// 장개시전시간외종가 거래대금, 대량, 바스켓은 제외, 단위:원
	out->opr_time_ccls_qty = Str2Dbl(data->opr_time_ccls_qty, sizeof(data->opr_time_ccls_qty), 0);	// 정규장체결수량, 대량, 바스켓은 제외, 단위:주
	out->opr_time_trd_val = Str2Dbl(data->opr_time_trd_val, sizeof(data->opr_time_trd_val), 0);	// 정규장거래대금, 대량, 바스켓은 제외, 단위:원
	out->ofhr_cls_ccls_qty = Str2Dbl(data->ofhr_cls_ccls_qty, sizeof(data->ofhr_cls_ccls_qty), 0);	// 장종료후시간외종가 체결수량, 대량, 바스켓은 제외, 단위:주
	out->ofhr_cls_trd_val = Str2Dbl(data->ofhr_cls_trd_val, sizeof(data->ofhr_cls_trd_val), 0);	// 장종료후시간외종가 거래대금, 대량, 바스켓은 제외, 단위:원
	out->elw_ely_cls_flg = data->elw_ely_cls_flg[0];	//ELW조기종료여부, Y,N 조기종료ELW 外 종목은 Default 'N' SET
	out->elw_ely_cls_time = Str2Int(data->elw_ely_cls_time, sizeof(data->elw_ely_cls_time));	// ELW조기종료시간, HHMMSS, ELW조기종료여부가 'Y'인 경우만 설정
	out->cmpt_msv_dir_clsf = Str2Int(data->cmpt_msv_dir_clsf, sizeof(data->cmpt_msv_dir_clsf));	// 경쟁대량 방향구분, 0:해당없음, 1:매도, 2:매수
	out->gen_bin_ccls_qty = Str2Dbl(data->gen_bin_ccls_qty, sizeof(data->gen_bin_ccls_qty), 0);	// 일반 Buy-in 체결수량, 단위:주
	out->gen_bin_ccls_trd_val = Str2Dbl(data->gen_bin_ccls_trd_val, sizeof(data->gen_bin_ccls_trd_val), 0);	// 일반 Buy-in 거래대금, 단위:원
	out->day_bin_ccls_qty = Str2Dbl(data->day_bin_ccls_qty, sizeof(data->day_bin_ccls_qty), 0);	// 당일 Buy-in 체결수량, 단위:주
	out->day_bin_ccls_trd_val = Str2Dbl(data->day_bin_ccls_trd_val, sizeof(data->day_bin_ccls_trd_val), 0);	// 당일 Buy-in 거래대금, 단위:원

	return 1;
}


// 코스피 외국인 종목별투자정보_확정치
int ParseF1011(const double& timestamp, const char* in_buff, DF_KOSPI_FRGN_INV_INFO* out) {
	KOSPI_FRGN_INV_INFO* data = (KOSPI_FRGN_INV_INFO*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA구분, F1
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// 정보구분, 01:주식 90:기타
	out->mkt_clsf = data->mkt_clsf[0];	//시장구분, 1:유가증권 2:코스닥 3:프리보드 7:채권
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// 종목코드, 표준코드
	out->snr = Str2Int(data->snr, sizeof(data->snr));	// 일련번호, 1~99999999 건수체크용
	memcpy(out->trd_date, data->trd_date, sizeof(data->trd_date));	// 매매일자, YYYYMMDD
	out->stk_lim_ratio = Str2Dbl(data->stk_lim_ratio, sizeof(data->stk_lim_ratio), 4);	// 종목한도비율, 9V9999 (예:15%일때 → 01500으로 전송)
	out->psn_lim_ratio = Str2Dbl(data->psn_lim_ratio, sizeof(data->psn_lim_ratio), 4);	// 개인한도비율, 9V9999 (예:15%일때 → 01500으로 전송)
	out->stk_lstd = Str2Dbl(data->stk_lstd, sizeof(data->stk_lstd), 0);	// 상장주식수, 단위:주
	out->ordbl_qty = Str2Dbl(data->ordbl_qty, sizeof(data->ordbl_qty), 0);	// 주문가능수량, 단위:주
	out->lim_xhs_clsf = data->lim_xhs_clsf[0];	//한도소진구분, 0:정상 1:한도소진 2:한도종목신규지정 3:한도종목해지

	return 1;
}


// 코스피 외국인 주문가능수량
int ParseF2011(const double& timestamp, const char* in_buff, DF_KOSPI_FRGN_ORDL_QTY* out) {
	KOSPI_FRGN_ORDL_QTY* data = (KOSPI_FRGN_ORDL_QTY*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA구분, F2
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// 정보구분, 01:주식 90:기타
	out->mkt_clsf = data->mkt_clsf[0];	//시장구분, 1:유가증권 2:코스닥 3:프리보드 7:채권
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// 종목코드, 표준코드
	out->ordbl_qty = Str2Dbl(data->ordbl_qty, sizeof(data->ordbl_qty), 0);	// 주문가능수량, 단위:주(양수만 존재)
	memcpy(out->data_type, data->data_type, sizeof(data->data_type));	// 데이터종류, 01:주문가능수량(실시간) 07:잠정치주문가능수량(종가)

	return 1;
}


// 코스피 외국인 예비주문지정_해지
int ParseF3011(const double& timestamp, const char* in_buff, DF_KOSPI_FRGN_RSVD_ORD_CNCL* out) {
	KOSPI_FRGN_RSVD_ORD_CNCL* data = (KOSPI_FRGN_RSVD_ORD_CNCL*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA구분, F3
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// 정보구분, 01:주식
	out->mkt_clsf = data->mkt_clsf[0];	//시장구분, 1:유가증권 2:코스닥 3:프리보드
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// 종목코드, 표준코드
	memcpy(out->data_type, data->data_type, sizeof(data->data_type));	// 데이터종류, 01:예비주문지정 02:예비주문해지
	out->proc_clsf = data->proc_clsf[0];	//처리구분, 1:정상 2:취소
	memcpy(out->rsvd_ord_date, data->rsvd_ord_date, sizeof(data->rsvd_ord_date));	// 예비주문일자, YYYYMMDD
	memcpy(out->rsvd_ord_st_time, data->rsvd_ord_st_time, sizeof(data->rsvd_ord_st_time));	// 예비주문시작시간, HHMM
	memcpy(out->rsvd_ord_ed_time, data->rsvd_ord_ed_time, sizeof(data->rsvd_ord_ed_time));	// 예비주문종료시간, HHMM

	return 1;
}


// 코스피 외국인 확정치데이터재전송
int ParseF4011(const double& timestamp, const char* in_buff, DF_KOSPI_FRGN_CFRM_DATA* out) {
	KOSPI_FRGN_CFRM_DATA* data = (KOSPI_FRGN_CFRM_DATA*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA구분, F4
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// 정보구분, 01:주식 90:기타
	out->mkt_clsf = data->mkt_clsf[0];	//시장구분, 1:유가증권 2:코스닥 3:프리보드 7:채권
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// 종목코드, 표준코드
	out->stk_lim_ratio = Str2Dbl(data->stk_lim_ratio, sizeof(data->stk_lim_ratio), 4);	// 종목한도비율, 9V9999 (예:15%일때 → 01500으로 전송)
	out->psn_lim_ratio = Str2Dbl(data->psn_lim_ratio, sizeof(data->psn_lim_ratio), 4);	// 개인한도비율, 9V9999 (예:15%일때 → 01500으로 전송)
	out->stk_lstd = Str2Dbl(data->stk_lstd, sizeof(data->stk_lstd), 0);	// 상장주식수, 단위:주
	out->ordbl_qty = Str2Dbl(data->ordbl_qty, sizeof(data->ordbl_qty), 0);	// 주문가능수량, 단위:주
	out->lim_xhs_clsf = data->lim_xhs_clsf[0];	//한도소진구분, 0:정상 1:한도초과 2:추가 3:삭제

	return 1;
}


// 코스피 외국인 한도소진장외매매
int ParseF5011(const double& timestamp, const char* in_buff, DF_KOSPI_FRGN_LMT_XHS* out) {
	KOSPI_FRGN_LMT_XHS* data = (KOSPI_FRGN_LMT_XHS*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA구분, F5
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// 정보구분, 01:주식
	out->mkt_clsf = data->mkt_clsf[0];	//시장구분, 1:유가증권 2:코스닥 3:프리보드
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// 종목코드, 표준코드
	out->clsf = data->clsf[0];	//구분, 1:단가입력 2:단가취소
	out->qty = Str2Int(data->qty, sizeof(data->qty));	// 수량, 단위:주
	out->prc = Str2Int(data->prc, sizeof(data->prc));	// 가격, 단위:원
	memcpy(out->proc_time, data->proc_time, sizeof(data->proc_time));	// 처리시간, HHMMSSMM

	return 1;
}


// 코스피 외국인 매매_결제현황
int ParseF6011(const double& timestamp, const char* in_buff, DF_KOSPI_FRGN_TRD_STAT* out) {
	KOSPI_FRGN_TRD_STAT* data = (KOSPI_FRGN_TRD_STAT*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA구분, F6
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// 정보구분, 01:주식
	out->mkt_clsf = data->mkt_clsf[0];	//시장구분, 1:유가증권 2:코스닥
	out->snr = Str2Int(data->snr, sizeof(data->snr));	// 일련번호, 1~99999999 건수체크용
	out->clsf = data->clsf[0];	//구분, 2:거래소매매현황 3:거래소결제현황 \n9:코스닥매매현황 0:코스닥결제현황
	out->tot_bid_qty = Str2Dbl(data->tot_bid_qty, sizeof(data->tot_bid_qty), 0);	// 총매수수량, 단위:주
	out->tot_bid_val = Str2Dbl(data->tot_bid_val, sizeof(data->tot_bid_val), 0);	// 총매수금액, 단위:원
	out->tot_ask_qty = Str2Dbl(data->tot_ask_qty, sizeof(data->tot_ask_qty), 0);	// 총매도수량, 단위:주
	out->tot_ask_val = Str2Dbl(data->tot_ask_val, sizeof(data->tot_ask_val), 0);	// 총매도금액, 단위:원
	out->net_bid_qty = Str2SignDouble(data->net_bid_qty_sign, sizeof(data->net_bid_qty_sign) + sizeof(data->net_bid_qty), 0);	// 순매수수량, 단위:주
	out->net_val_qty = Str2SignDouble(data->net_bid_val_sign, sizeof(data->net_bid_val_sign) + sizeof(data->net_val_qty), 0);	// 순매수금액, 단위:원

	return 1;
}


// 코스닥 외국인 한도소진장외매매
int ParseF5012(const double& timestamp, const char* in_buff, DF_KOSDAQ_FRGN_LMT_XHS* out) {
	KOSDAQ_FRGN_LMT_XHS* data = (KOSDAQ_FRGN_LMT_XHS*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA구분, F5
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// 정보구분, 01:주식
	out->mkt_clsf = data->mkt_clsf[0];	//시장구분, 1:유가증권 2:코스닥 3:프리보드
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// 종목코드, 표준코드
	out->clsf = data->clsf[0];	//구분, 1:단가입력 2:단가취소
	out->qty = Str2Int(data->qty, sizeof(data->qty));	// 수량, 단위:주
	out->prc = Str2Int(data->prc, sizeof(data->prc));	// 가격, 단위:원
	memcpy(out->proc_time, data->proc_time, sizeof(data->proc_time));	// 처리시간, HHMMSSMM

	return 1;
}


// 코스닥 외국인 매매_결제현황
int ParseF6012(const double& timestamp, const char* in_buff, DF_KOSDAQ_FRGN_TRD_STAT* out) {
	KOSDAQ_FRGN_TRD_STAT* data = (KOSDAQ_FRGN_TRD_STAT*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA구분, F6
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// 정보구분, 01:주식
	out->mkt_clsf = data->mkt_clsf[0];	//시장구분, 1:유가증권 2:코스닥 8:코넥스
	out->snr = Str2Int(data->snr, sizeof(data->snr));	// 일련번호, 1~99999999 건수체크용
	out->clsf = data->clsf[0];	//구분, 2:거래소매매현황 3:거래소결제현황 \n9:코스닥매매현황 0:코스닥결제현황\n5:코넥스매매현황 6:코넥스결제현황
	out->tot_bid_qty = Str2Dbl(data->tot_bid_qty, sizeof(data->tot_bid_qty), 0);	// 총매수수량, 단위:주
	out->tot_bid_val = Str2Dbl(data->tot_bid_val, sizeof(data->tot_bid_val), 0);	// 총매수금액, 단위:원
	out->tot_ask_qty = Str2Dbl(data->tot_ask_qty, sizeof(data->tot_ask_qty), 0);	// 총매도수량, 단위:주
	out->tot_ask_val = Str2Dbl(data->tot_ask_val, sizeof(data->tot_ask_val), 0);	// 총매도금액, 단위:원
	out->net_bid_qty = Str2SignDouble(data->net_bid_qty_sign, sizeof(data->net_bid_qty_sign) + sizeof(data->net_bid_qty), 0);	// 순매수수량, 단위:주
	out->net_val_qty = Str2SignDouble(data->net_bid_val_sign, sizeof(data->net_bid_val_sign) + sizeof(data->net_val_qty), 0);	// 순매수금액, 단위:원

	return 1;
}


// 코스닥 외국인 예비주문지정_해지
int ParseF3012(const double& timestamp, const char* in_buff, DF_KOSDAQ_FRGN_RSVD_ORD_CNCL* out) {
	KOSDAQ_FRGN_RSVD_ORD_CNCL* data = (KOSDAQ_FRGN_RSVD_ORD_CNCL*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA구분, F3
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// 정보구분, 01:주식
	out->mkt_clsf = data->mkt_clsf[0];	//시장구분, 1:유가증권 2:코스닥 3:프리보드
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// 종목코드, 표준코드
	memcpy(out->data_type, data->data_type, sizeof(data->data_type));	// 데이터종류, 01:예비주문지정 02:예비주문해지
	out->proc_clsf = data->proc_clsf[0];	//처리구분, 1:정상 2:취소
	memcpy(out->rsvd_ord_date, data->rsvd_ord_date, sizeof(data->rsvd_ord_date));	// 예비주문일자, YYYYMMDD
	memcpy(out->rsvd_ord_st_time, data->rsvd_ord_st_time, sizeof(data->rsvd_ord_st_time));	// 예비주문시작시간, HHMM
	memcpy(out->rsvd_ord_ed_time, data->rsvd_ord_ed_time, sizeof(data->rsvd_ord_ed_time));	// 예비주문종료시간, HHMM

	return 1;
}


// 코스닥 외국인 종목별투자정보_확정치
int ParseF1012(const double& timestamp, const char* in_buff, DF_KOSDAQ_FRGN_INV_INFO* out) {
	KOSDAQ_FRGN_INV_INFO* data = (KOSDAQ_FRGN_INV_INFO*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA구분, F1
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// 정보구분, 01:주식 90:기타
	out->mkt_clsf = data->mkt_clsf[0];	//시장구분, 1:유가증권 2:코스닥 3:프리보드 7:채권
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// 종목코드, 표준코드
	out->snr = Str2Int(data->snr, sizeof(data->snr));	// 일련번호, 1~99999999 건수체크용
	memcpy(out->trd_date, data->trd_date, sizeof(data->trd_date));	// 매매일자, YYYYMMDD
	out->stk_lim_ratio = Str2Dbl(data->stk_lim_ratio, sizeof(data->stk_lim_ratio), 4);	// 종목한도비율, 9V9999 (예:15%일때 → 01500으로 전송)
	out->psn_lim_ratio = Str2Dbl(data->psn_lim_ratio, sizeof(data->psn_lim_ratio), 4);	// 개인한도비율, 9V9999 (예:15%일때 → 01500으로 전송)
	out->stk_lstd = Str2Dbl(data->stk_lstd, sizeof(data->stk_lstd), 0);	// 상장주식수, 단위:주
	out->ordbl_qty = Str2Dbl(data->ordbl_qty, sizeof(data->ordbl_qty), 0);	// 주문가능수량, 단위:주
	out->lim_xhs_clsf = data->lim_xhs_clsf[0];	//한도소진구분, 0:정상 1:한도소진 2:한도종목신규지정 3:한도종목해지

	return 1;
}


// 코스닥 외국인 주문가능수량
int ParseF2012(const double& timestamp, const char* in_buff, DF_KOSDAQ_FRGN_ORDL_QTY* out) {
	KOSDAQ_FRGN_ORDL_QTY* data = (KOSDAQ_FRGN_ORDL_QTY*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA구분, F2
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// 정보구분, 01:주식 90:기타
	out->mkt_clsf = data->mkt_clsf[0];	//시장구분, 1:유가증권 2:코스닥 3:프리보드 7:채권
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// 종목코드, 표준코드
	out->ordbl_qty = Str2Dbl(data->ordbl_qty, sizeof(data->ordbl_qty), 0);	// 주문가능수량, 단위:주(양수만 존재)
	memcpy(out->proc_clsf, data->proc_clsf, sizeof(data->proc_clsf));	// 데이터종류, 01:주문가능수량(실시간) 07:잠정치주문가능수량(종가)

	return 1;
}


// 코스닥 외국인 확정치데이터재전송
int ParseF4012(const double& timestamp, const char* in_buff, DF_KOSDAQ_FRGN_CFRM_DATA* out) {
	KOSDAQ_FRGN_CFRM_DATA* data = (KOSDAQ_FRGN_CFRM_DATA*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA구분, F4
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// 정보구분, 01:주식 90:기타
	out->mkt_clsf = data->mkt_clsf[0];	//시장구분, 1:유가증권 2:코스닥 3:프리보드 7:채권
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// 종목코드, 표준코드
	out->stk_lim_ratio = Str2Dbl(data->stk_lim_ratio, sizeof(data->stk_lim_ratio), 4);	// 종목한도비율, 9V9999 (예:15%일때 → 01500으로 전송)
	out->psn_lim_ratio = Str2Dbl(data->psn_lim_ratio, sizeof(data->psn_lim_ratio), 4);	// 개인한도비율, 9V9999 (예:15%일때 → 01500으로 전송)
	out->stk_lstd = Str2Dbl(data->stk_lstd, sizeof(data->stk_lstd), 0);	// 상장주식수, 단위:주
	out->ordbl_qty = Str2Dbl(data->ordbl_qty, sizeof(data->ordbl_qty), 0);	// 주문가능수량, 단위:주
	out->lim_xhs_clsf = data->lim_xhs_clsf[0];	//한도소진구분, 0:정상 1:한도초과 2:추가 3:삭제

	return 1;
}


// 코넥스 외국인 종목별투자정보_확정치
int ParseF1018(const double& timestamp, const char* in_buff, DF_KONEX_FRGN_INV_INFO* out) {
	KONEX_FRGN_INV_INFO* data = (KONEX_FRGN_INV_INFO*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA구분, F1
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// 정보구분, 01:주식 90:기타
	out->mkt_clsf = data->mkt_clsf[0];	//시장구분, 1:유가증권 2:코스닥 3:프리보드 7:채권 8:코넥스
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// 종목코드, 표준코드
	out->snr = Str2Int(data->snr, sizeof(data->snr));	// 일련번호, 1~99999999 건수체크용
	memcpy(out->trd_date, data->trd_date, sizeof(data->trd_date));	// 매매일자, YYYYMMDD
	out->stk_lim_ratio = Str2Dbl(data->stk_lim_ratio, sizeof(data->stk_lim_ratio), 4);	// 종목한도비율, 9V9999 (예:15%일때 → 01500으로 전송)
	out->psn_lim_ratio = Str2Dbl(data->psn_lim_ratio, sizeof(data->psn_lim_ratio), 4);	// 개인한도비율, 9V9999 (예:15%일때 → 01500으로 전송)
	out->stk_lstd = Str2Dbl(data->stk_lstd, sizeof(data->stk_lstd), 0);	// 상장주식수, 단위:주
	out->ordbl_qty = Str2Dbl(data->ordbl_qty, sizeof(data->ordbl_qty), 0);	// 주문가능수량, 단위:주
	out->lim_xhs_clsf = data->lim_xhs_clsf[0];	//한도소진구분, 0:정상 1:한도소진 2:한도종목신규지정 3:한도종목해지

	return 1;
}


// 코넥스 외국인 주문가능수량
int ParseF2018(const double& timestamp, const char* in_buff, DF_KONEX_FRGN_ORDL_QTY* out) {
	KONEX_FRGN_ORDL_QTY* data = (KONEX_FRGN_ORDL_QTY*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA구분, F2
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// 정보구분, 01:주식 90:기타
	out->mkt_clsf = data->mkt_clsf[0];	//시장구분, 1:유가증권 2:코스닥 3:프리보드 7:채권 8:코넥스
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// 종목코드, 표준코드
	out->ordbl_qty = Str2Dbl(data->ordbl_qty, sizeof(data->ordbl_qty), 0);	// 주문가능수량, 단위:주(양수만 존재)
	memcpy(out->data_type, data->data_type, sizeof(data->data_type));	// 데이터종류, 01:주문가능수량(실시간) 07:잠정치주문가능수량(종가)

	return 1;
}


// 코넥스 외국인 예비주문지정_해지
int ParseF3018(const double& timestamp, const char* in_buff, DF_KONEX_FRGN_RSVD_ORD_CNCL* out) {
	KONEX_FRGN_RSVD_ORD_CNCL* data = (KONEX_FRGN_RSVD_ORD_CNCL*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA구분, F3
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// 정보구분, 01:주식
	out->mkt_clsf = data->mkt_clsf[0];	//시장구분, 1:유가증권 2:코스닥 3:프리보드 8:코넥스
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// 종목코드, 표준코드
	memcpy(out->data_type, data->data_type, sizeof(data->data_type));	// 데이터종류, 01:예비주문지정 02:예비주문해지
	out->proc_clsf = data->proc_clsf[0];	//처리구분, 1:정상 2:취소
	memcpy(out->rsvd_ord_date, data->rsvd_ord_date, sizeof(data->rsvd_ord_date));	// 예비주문일자, YYYYMMDD
	memcpy(out->rsvd_ord_st_time, data->rsvd_ord_st_time, sizeof(data->rsvd_ord_st_time));	// 예비주문시작시간, HHMM
	memcpy(out->rsvd_ord_ed_time, data->rsvd_ord_ed_time, sizeof(data->rsvd_ord_ed_time));	// 예비주문종료시간, HHMM

	return 1;
}


// 코넥스 외국인 확정치데이터재전송
int ParseF4018(const double& timestamp, const char* in_buff, DF_KONEX_FRGN_CFRM_DATA* out) {
	KONEX_FRGN_CFRM_DATA* data = (KONEX_FRGN_CFRM_DATA*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA구분, F4
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// 정보구분, 01:주식 90:기타
	out->mkt_clsf = data->mkt_clsf[0];	//시장구분, 1:유가증권 2:코스닥 3:프리보드 7:채권 8:코넥스
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// 종목코드, 표준코드
	out->stk_lim_ratio = Str2Dbl(data->stk_lim_ratio, sizeof(data->stk_lim_ratio), 4);	// 종목한도비율, 9V9999 (예:15%일때 → 01500으로 전송)
	out->psn_lim_ratio = Str2Dbl(data->psn_lim_ratio, sizeof(data->psn_lim_ratio), 4);	// 개인한도비율, 9V9999 (예:15%일때 → 01500으로 전송)
	out->stk_lstd = Str2Dbl(data->stk_lstd, sizeof(data->stk_lstd), 0);	// 상장주식수, 단위:주
	out->ordbl_qty = Str2Dbl(data->ordbl_qty, sizeof(data->ordbl_qty), 0);	// 주문가능수량, 단위:주
	out->lim_xhs_clsf = data->lim_xhs_clsf[0];	//한도소진구분, 0:정상 1:한도초과 2:추가 3:삭제

	return 1;
}


// 코넥스 외국인 한도소진장외매매
int ParseF5018(const double& timestamp, const char* in_buff, DF_KONEX_FRGN_LMT_XHS* out) {
	KONEX_FRGN_LMT_XHS* data = (KONEX_FRGN_LMT_XHS*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA구분, F5
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// 정보구분, 01:주식
	out->mkt_clsf = data->mkt_clsf[0];	//시장구분, 1:유가증권 2:코스닥 3:프리보드 8:코넥스
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// 종목코드, 표준코드
	out->clsf = data->clsf[0];	//구분, 1:단가입력 2:단가취소
	out->qty = Str2Int(data->qty, sizeof(data->qty));	// 수량, 단위:주
	out->prc = Str2Int(data->prc, sizeof(data->prc));	// 가격, 단위:원
	memcpy(out->proc_time, data->proc_time, sizeof(data->proc_time));	// 처리시간, HHMMSSMM

	return 1;
}


// 코넥스 외국인 매매_결제현황
int ParseF6018(const double& timestamp, const char* in_buff, DF_KONEX_FRGN_TRD_STAT* out) {
	KONEX_FRGN_TRD_STAT* data = (KONEX_FRGN_TRD_STAT*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA구분, F6
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// 정보구분, 01:주식
	out->mkt_clsf = data->mkt_clsf[0];	//시장구분, 1:유가증권 2:코스닥 8:코넥스
	out->snr = Str2Int(data->snr, sizeof(data->snr));	// 일련번호, 1~99999999 건수체크용
	out->clsf = data->clsf[0];	//구분, 2:거래소매매현황 3:거래소결제현황 \n9:코스닥매매현황 0:코스닥결제현황\n5:코넥스매매현황 6:코넥스결제현황
	out->tot_bid_qty = Str2Dbl(data->tot_bid_qty, sizeof(data->tot_bid_qty), 0);	// 총매수수량, 단위:주
	out->tot_bid_val = Str2Dbl(data->tot_bid_val, sizeof(data->tot_bid_val), 0);	// 총매수금액, 단위:원
	out->tot_ask_qty = Str2Dbl(data->tot_ask_qty, sizeof(data->tot_ask_qty), 0);	// 총매도수량, 단위:주
	out->tot_ask_val = Str2Dbl(data->tot_ask_val, sizeof(data->tot_ask_val), 0);	// 총매도금액, 단위:원
	out->net_bid_qty = Str2SignDouble(data->net_bid_qty_sign, sizeof(data->net_bid_qty_sign) + sizeof(data->net_bid_qty), 0);	// 순매수수량, 단위:주
	out->net_val_qty = Str2SignDouble(data->net_bid_val_sign, sizeof(data->net_bid_val_sign) + sizeof(data->net_val_qty), 0);	// 순매수금액, 단위:원

	return 1;
}


// 유가 업종별 배당수익률
int ParseP2011(const double& timestamp, const char* in_buff, DF_KOSPI_BYIND_DYR* out) {
	KOSPI_BYIND_DYR* data = (KOSPI_BYIND_DYR*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA구분, P2
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// 정보구분, 01:주식
	out->mkt_clsf = data->mkt_clsf[0];	//시장구분, 1:유가증권 2:코스닥
	memcpy(out->idx_ind_code, data->idx_ind_code, sizeof(data->idx_ind_code));	// 지수업종코드, ※코드값모음 참조
	out->dyr = Str2Dbl(data->dyr, sizeof(data->dyr), 2);	// 배당수익률, 99999v99

	return 1;
}


// ELW 종목배치
int ParseA1011(const double& timestamp, const char* in_buff, DF_ELW_STK_ARNG* out) {
	ELW_STK_ARNG* data = (ELW_STK_ARNG*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA구분, A1
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// 정보구분, 01:주식
	out->mkt_clsf = data->mkt_clsf[0];	//시장구분, 1:유가증권
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// 종목코드, 표준코드
	out->snr = Str2Int(data->snr, sizeof(data->snr));	// 일련번호, 1~99999999 건수체크용
	memcpy(out->elw_ptcp_kor_nm, data->elw_ptcp_kor_nm, sizeof(data->elw_ptcp_kor_nm));	// ELW발행시장참가자 한글명
	memcpy(out->elw_ptcp_eng_nm, data->elw_ptcp_eng_nm, sizeof(data->elw_ptcp_eng_nm));	// ELW발행시장참가자 영문명
	memcpy(out->elw_ptcp_nr, data->elw_ptcp_nr, sizeof(data->elw_ptcp_nr));	// ELW발행시장참가자 번호, ELW발행회원사의 번호(상장사, 비상장사 구분없음)\n예) ‘00001’
	memcpy(out->elw_comp_stk_mtk_id1, data->elw_comp_stk_mtk_id1, sizeof(data->elw_comp_stk_mtk_id1));	// ELW구성종목시장ID1, 구성종목이 소속된 시장ID(예:유가:STK,코스닥:KSQ)\n*기초자산이 종목인 경우만 해당
	memcpy(out->elw_comp_stk_mtk_id2, data->elw_comp_stk_mtk_id2, sizeof(data->elw_comp_stk_mtk_id2));	// ELW구성종목시장ID2, 구성종목이 소속된 시장ID(예:유가:STK,코스닥:KSQ)\n*기초자산이 종목인 경우만 해당
	memcpy(out->elw_comp_stk_mtk_id3, data->elw_comp_stk_mtk_id3, sizeof(data->elw_comp_stk_mtk_id3));	// ELW구성종목시장ID3, 구성종목이 소속된 시장ID(예:유가:STK,코스닥:KSQ)\n*기초자산이 종목인 경우만 해당
	memcpy(out->elw_comp_stk_mtk_id4, data->elw_comp_stk_mtk_id4, sizeof(data->elw_comp_stk_mtk_id4));	// ELW구성종목시장ID4, 구성종목이 소속된 시장ID(예:유가:STK,코스닥:KSQ)\n*기초자산이 종목인 경우만 해당
	memcpy(out->elw_comp_stk_mtk_id5, data->elw_comp_stk_mtk_id5, sizeof(data->elw_comp_stk_mtk_id5));	// ELW구성종목시장ID5, 구성종목이 소속된 시장ID(예:유가:STK,코스닥:KSQ)\n*기초자산이 종목인 경우만 해당
	memcpy(out->elw_base_ast1, data->elw_base_ast1, sizeof(data->elw_base_ast1));	// ELW기초자산1, 기초자산이 지수인 경우 SPACE. ELW지수업종코드 참조
	memcpy(out->elw_base_ast2, data->elw_base_ast2, sizeof(data->elw_base_ast2));	// ELW기초자산2, 기초자산이 지수인 경우 SPACE. ELW지수업종코드 참조
	memcpy(out->elw_base_ast3, data->elw_base_ast3, sizeof(data->elw_base_ast3));	// ELW기초자산3, 기초자산이 지수인 경우 SPACE. ELW지수업종코드 참조
	memcpy(out->elw_base_ast4, data->elw_base_ast4, sizeof(data->elw_base_ast4));	// ELW기초자산4, 기초자산이 지수인 경우 SPACE. ELW지수업종코드 참조
	memcpy(out->elw_base_ast5, data->elw_base_ast5, sizeof(data->elw_base_ast5));	// ELW기초자산5, 기초자산이 지수인 경우 SPACE. ELW지수업종코드 참조
	out->elw_base_ast_rate1 = Str2Dbl(data->elw_base_ast_rate1, sizeof(data->elw_base_ast_rate1), 6);	// ELW기초자산구성비1, 9(6)V9(6)
	out->elw_base_ast_rate2 = Str2Dbl(data->elw_base_ast_rate2, sizeof(data->elw_base_ast_rate2), 6);	// ELW기초자산구성비2, 9(6)V9(6)
	out->elw_base_ast_rate3 = Str2Dbl(data->elw_base_ast_rate3, sizeof(data->elw_base_ast_rate3), 6);	// ELW기초자산구성비3, 9(6)V9(6)
	out->elw_base_ast_rate4 = Str2Dbl(data->elw_base_ast_rate4, sizeof(data->elw_base_ast_rate4), 6);	// ELW기초자산구성비4, 9(6)V9(6)
	out->elw_base_ast_rate5 = Str2Dbl(data->elw_base_ast_rate5, sizeof(data->elw_base_ast_rate5), 6);	// ELW기초자산구성비5, 9(6)V9(6)
	out->idx_mkt_clsf_code = data->idx_mkt_clsf_code[0];	//지수소속시장구분코드, 1:유가증권 2:코스닥 3:섹터 4:GICS 8:MF(매경) 9:해외\nS:S&P/KRX B:채권 C:통화 M:상품 R:부동산 2009.07.27\n*기초자산이 지수일 경우만 해당\n*구명칭:ELW기초자산시장구분코드
	memcpy(out->elw_idx_ind_code, data->elw_idx_ind_code, sizeof(data->elw_idx_ind_code));	// ELW지수업종코드, ELW기초자산시장구분코드가 유가증권일 경우는 유가증권의\n지수업종코드, 코스닥일 경우는 코스닥의 업종코드,\n해외시장일 경우는 해외지수에 대한 별도의 코드정보\n※코드값모음 - 대상지수업종코드표 참조
	out->elw_rgt_type_code = data->elw_rgt_type_code[0];	//ELW권리유형코드, C:콜 P:풋 Z:기타
	out->elw_rgt_exc_type_code = data->elw_rgt_exc_type_code[0];	//ELW권리행사유형코드, A:미국형 E:유럽형 Z:해당없음
	out->elw_fin_pymt_code = data->elw_fin_pymt_code[0];	//ELW최종결제방법코드, A:현금+실물인수도결제 C:현금결제 D:실물인수도결제
	memcpy(out->elw_fin_trd_date, data->elw_fin_trd_date, sizeof(data->elw_fin_trd_date));	// ELW최종거래일자, YYYYMMDD
	memcpy(out->elw_pymt_date, data->elw_pymt_date, sizeof(data->elw_pymt_date));	// ELW지급일자, YYYYMMDD
	out->elw_base_ast_prc = Str2Dbl(data->elw_base_ast_prc, sizeof(data->elw_base_ast_prc), 3);	// ELW기초자산기초가격, 9(9)V9(3) ※개발가이드 참조
	memcpy(out->elw_mtr_rgt_exc_cntt, data->elw_mtr_rgt_exc_cntt, sizeof(data->elw_mtr_rgt_exc_cntt));	// ELW만기권리행사내용, ELW권리행사내용->ELW만기권리행사내용 2010.08.30
	out->elw_cnvr = Str2Dbl(data->elw_cnvr, sizeof(data->elw_cnvr), 6);	// ELW전환비율, 9(6)V9(6)
	out->elw_rise_ptcp_rate = Str2Dbl(data->elw_rise_ptcp_rate, sizeof(data->elw_rise_ptcp_rate), 2);	// ELW가격상승참가율, 9(6)V9(2)
	out->elw_min_pymt_rate = Str2Dbl(data->elw_min_pymt_rate, sizeof(data->elw_min_pymt_rate), 2);	// ELW최소지급비율, 9(6)V9(2) ELW보상율->ELW최소지급비율 2010.08.30
	out->elw_cfrm_pymt_val = Str2Dbl(data->elw_cfrm_pymt_val, sizeof(data->elw_cfrm_pymt_val), 3);	// ELW확정지급액, 9(18)V9(3)
	memcpy(out->elw_pymt_prx_nm, data->elw_pymt_prx_nm, sizeof(data->elw_pymt_prx_nm));	// ELW지급대리인명
	memcpy(out->elw_mtr_assm_type, data->elw_mtr_assm_type, sizeof(data->elw_mtr_assm_type));	// ELW만기평가가격방식
	out->elw_rgt_type = data->elw_rgt_type[0];	//ELW권리형태, ELW이색옵션구분코드 -> ELW권리형태\n0:표준옵션 1:디지털옵션 2:조기종료옵션(2010.08.30)
	out->elw_lp_hld_qty = Str2Dbl(data->elw_lp_hld_qty, sizeof(data->elw_lp_hld_qty), 0);	// ELW LP보유수량, 15 -> 12 2014.03.03

	return 1;
}


// 조기종료ELW_종목배치
int ParseM6011(const double& timestamp, const char* in_buff, DF_ELY_CLS_ELW_STK_ARNG* out) {
	ELY_CLS_ELW_STK_ARNG* data = (ELY_CLS_ELW_STK_ARNG*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA구분, M6
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// 정보구분, 01:주식
	out->mkt_clsf = data->mkt_clsf[0];	//시장구분, 1:유가증권
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// 종목코드, 표준코드
	out->snr = Str2Int(data->snr, sizeof(data->snr));	// 일련번호, 1~99999999 건수체크용
	out->elw_ely_cls_base_prc = Str2Dbl(data->elw_ely_cls_base_prc, sizeof(data->elw_ely_cls_base_prc), 3);	// ELW조기종료발생 기준가격, 9(9)V9(3), 조기종료워런트의 조기종료 이벤트 발생의 \n기준이 되는 가격(2010.08.30)
	memcpy(out->elw_ely_cls_rgt_exe_cntt, data->elw_ely_cls_rgt_exe_cntt, sizeof(data->elw_ely_cls_rgt_exe_cntt));	// ELW조기종료권리행사 내용, ELW조기종료권리행사내용(2010.08.30)
	memcpy(out->elw_ely_cls_assm_type, data->elw_ely_cls_assm_type, sizeof(data->elw_ely_cls_assm_type));	// ELW조기종료평가 가격방식, 조기종료시 해당 종목의 평가가격을 결정하는 방식을 \n기술 (2010.08.30)

	return 1;
}


// 조기종료ELW 평가기간 중 기초자산고저가
int ParseM5011(const double& timestamp, const char* in_buff, DF_ELY_CLS_ELW_ASSET_HLP* out) {
	ELY_CLS_ELW_ASSET_HLP* data = (ELY_CLS_ELW_ASSET_HLP*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA구분, M5
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// 정보구분, 01:주식
	out->mkt_clsf = data->mkt_clsf[0];	//시장구분, 1:유가증권
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// 종목코드, Knockout 발생한 ELW의 종목코드
	out->snr = Str2Int(data->snr, sizeof(data->snr));	// 일련번호, 1~99999999 건수체크용
	memcpy(out->trsm_date, data->trsm_date, sizeof(data->trsm_date));	// 전송일자
	memcpy(out->base_ast_trd_date, data->base_ast_trd_date, sizeof(data->base_ast_trd_date));	// 기초자산매매일자
	memcpy(out->ko_trgg_date, data->ko_trgg_date, sizeof(data->ko_trgg_date));	// KO발생일자, Knockout 발생일자
	out->noon_clsf_code = data->noon_clsf_code[0];	//오전오후구분코드, Knockout 오전발생의 경우 ※ 개발가이드 참조\n A : KO시점부터 12시\n P: 12시부터 정규장마감\nKnockout 오후 발생의 경우\n P: KO시점부터 정규장마감\nKnockout 발생 후 익 영업일의 경우 \n A: 장개시부터 12시\n P: 12시부터 정규장 마감
	memcpy(out->comp_stk_code, data->comp_stk_code, sizeof(data->comp_stk_code));	// 구성종목코드, ELW를 구성하는 기초자산의 종목코드(ISIN종목코드)
	out->elw_idx_mkt_clsf_code = data->elw_idx_mkt_clsf_code[0];	//ELW지수소속시장구분코드, 1:유가증권, 2:코스닥
	memcpy(out->idx_ind_code, data->idx_ind_code, sizeof(data->idx_ind_code));	// 지수업종코드, ELW기초자산시장구분코드가 유가증권일 경우는 유가증권의\n지수업종코드, 코스닥일 경우는 코스닥의 업종코드,\n해외시장일 경우는 해외지수에 대한 별도의 코드정보\n※코드값모음 - 대상지수업종코드표 참조
	memcpy(out->high, data->high, sizeof(data->high));	// 고가, 9(9)V9(2) 산출시간내의 기초자산의 고가\nKO발생시각이 장종료 이후이면 "00000000000"
	memcpy(out->low, data->low, sizeof(data->low));	// 저가, 9(9)V9(2) 산출시간내의 기초자산의 저가\nKO발생시각이 장종료 이후이면 "00000000000"

	return 1;
}


// ELW_시세RECOVERY
int ParseB2021(const double& timestamp, const char* in_buff, DF_ELW_MKT_PRC_RCVR* out) {
	ELW_MKT_PRC_RCVR* data = (ELW_MKT_PRC_RCVR*)in_buff;

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
	out->high = Str2Int(data->high, sizeof(data->high));	// 고가, 정규장 고가
	out->low = Str2Int(data->low, sizeof(data->low));	// 저가, 정규장 저가
	out->ask_prc = Str2Int(data->ask_prc, sizeof(data->ask_prc));	// 매도호가, B1시 0값 SET
	out->bid_prc = Str2Int(data->bid_prc, sizeof(data->bid_prc));	// 매수호가, B1시 0값 SET
	out->cum_ccls_qty = Str2Dbl(data->cum_ccls_qty, sizeof(data->cum_ccls_qty), 0);	// 누적체결수량, 단위:주 ※시간외단일가, BUY-IN을 제외한 모든 체결수량 합산
	out->cum_trd_val = Str2Dbl(data->cum_trd_val, sizeof(data->cum_trd_val), 0);	// 누적거래대금, 단위:원 ※시간외단일가, BUY-IN을 제외한 모든 거래대금 합산
	out->trend_flg = data->trend_flg[0];	//실세/기세 구분, 0:초기값 1:실세 2:기세 3:거래무 4:시가기준가종목의 기세
	memcpy(out->brd_evt_id, data->brd_evt_id, sizeof(data->brd_evt_id));	// 보드이벤트ID, B1/B2 에서는 보드이벤트ID 사용금지(과거 상태값이 전송될 수 있음). 추후, 해당 항목 '000' 세팅 예정. 2014.03.24)
	memcpy(out->brd_id, data->brd_id, sizeof(data->brd_id));	// 보드ID, ※ 코드값모음 참조
	out->trsp_flg = data->trsp_flg[0];	//거래정지여부, Y, N
	out->bopen_ofhr_ccls_qty = Str2Dbl(data->bopen_ofhr_ccls_qty, sizeof(data->bopen_ofhr_ccls_qty), 0);	// 장개시전시간외종가 체결수량, 대량, 바스켓은 제외, 단위:주
	out->bopen_ofhr_trd_val = Str2Dbl(data->bopen_ofhr_trd_val, sizeof(data->bopen_ofhr_trd_val), 0);	// 장개시전시간외종가 거래대금, 대량, 바스켓은 제외, 단위:원
	out->opr_time_ccls_qty = Str2Dbl(data->opr_time_ccls_qty, sizeof(data->opr_time_ccls_qty), 0);	// 정규장체결수량, 대량, 바스켓은 제외, 단위:주
	out->opr_time_trd_val = Str2Dbl(data->opr_time_trd_val, sizeof(data->opr_time_trd_val), 0);	// 정규장거래대금, 대량, 바스켓은 제외, 단위:원
	out->ofhr_cls_ccls_qty = Str2Dbl(data->ofhr_cls_ccls_qty, sizeof(data->ofhr_cls_ccls_qty), 0);	// 장종료후시간외종가 체결수량, 대량, 바스켓은 제외, 단위:주
	out->ofhr_cls_trd_val = Str2Dbl(data->ofhr_cls_trd_val, sizeof(data->ofhr_cls_trd_val), 0);	// 장종료후시간외종가 거래대금, 대량, 바스켓은 제외, 단위:원
	out->elw_ely_cls_flg = data->elw_ely_cls_flg[0];	//ELW조기종료여부, Y,N 조기종료ELW 外 종목은 Default 'N' SET
	out->elw_ely_cls_time = Str2Int(data->elw_ely_cls_time, sizeof(data->elw_ely_cls_time));	// ELW조기종료시간, HHMMSS, ELW조기종료여부가 'Y'인 경우만 설정
	out->cmpt_msv_dir_clsf = Str2Int(data->cmpt_msv_dir_clsf, sizeof(data->cmpt_msv_dir_clsf));	// 경쟁대량 방향구분, 0:해당없음, 1:매도, 2:매수
	out->gen_bin_ccls_qty = Str2Dbl(data->gen_bin_ccls_qty, sizeof(data->gen_bin_ccls_qty), 0);	// 일반 Buy-in 체결수량, 단위:주
	out->gen_bin_ccls_trd_val = Str2Dbl(data->gen_bin_ccls_trd_val, sizeof(data->gen_bin_ccls_trd_val), 0);	// 일반 Buy-in 거래대금, 단위:원
	out->day_bin_ccls_qty = Str2Dbl(data->day_bin_ccls_qty, sizeof(data->day_bin_ccls_qty), 0);	// 당일 Buy-in 체결수량, 단위:주
	out->day_bin_ccls_trd_val = Str2Dbl(data->day_bin_ccls_trd_val, sizeof(data->day_bin_ccls_trd_val), 0);	// 당일 Buy-in 거래대금, 단위:원

	return 1;
}


// ELW 투자지표
int ParseC6021(const double& timestamp, const char* in_buff, DF_ELW_INV_IDX* out) {
	ELW_INV_IDX* data = (ELW_INV_IDX*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA구분, C6
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// 정보구분, 02:ELW
	out->mkt_clsf = data->mkt_clsf[0];	//시장구분, 1:유가증권
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// 종목코드, 표준코드
	out->snr = Str2Int(data->snr, sizeof(data->snr));	// 일련번호, 1~99999999 종목일련번호 2014.03.03
	memcpy(out->buy_time, data->buy_time, sizeof(data->buy_time));	// 산 시간, 장중:HHMMSS(시간:분:초) 090000 ~ 장종료:JUNJJJ
	out->parity = Str2Dbl(data->parity, sizeof(data->parity), 2);	// 패리티, 9(6)V9(2)
	out->gear_rate = Str2Dbl(data->gear_rate, sizeof(data->gear_rate), 2);	// 기어링비율, 9(6)V9(2)
	out->brk_evn_rate = Str2SignDouble(data->brk_evn_rate_sign, sizeof(data->brk_evn_rate_sign) + sizeof(data->brk_evn_rate), 2);	// 손익분기율, 9(5)V9(2)
	out->cpt_sprt = Str2SignDouble(data->cpt_sprt_sign, sizeof(data->cpt_sprt_sign) + sizeof(data->cpt_sprt), 2);	// 자본지지점, 9(5)V9(2) 정규장 종료시 한번만 산출됨. 그 외는 "0"\n산술식에서 값 < 0 이면 "0"으로 SET
	out->bsk_prc = Str2Dbl(data->bsk_prc, sizeof(data->bsk_prc), 2);	// 바스켓주가, 9(9)V9(2)

	return 1;
}


// ELW LP호가 내재변동성
int ParseN3021(const double& timestamp, const char* in_buff, DF_ELW_LP_ASK_VOL* out) {
	int i=0;
	ELW_LP_ASK_VOL* data = (ELW_LP_ASK_VOL*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA구분, N3
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// 정보구분, 02:ELW
	out->mkt_clsf = data->mkt_clsf[0];	//시장구분, 1:유가증권
	out->calc_time = Str2Int(data->calc_time, sizeof(data->calc_time));	// 산출시간, 장중:HHMMSS(시간:분:초) 090000 ~ 장종료:JUNJJJ

	for ( i=0 ; i<50 ; i++ ) {
		memcpy(&out->elw_iv_infos[i].isin_code, &data->elw_iv_infos[i].isin_code, sizeof(data->elw_iv_infos[i].isin_code));	// 종목코드, 표준코드 12 바이트
		out->elw_iv_infos[i].itnl_vol = Str2Dbl(data->elw_iv_infos[i].itnl_vol, sizeof(data->elw_iv_infos[i].itnl_vol), 2);	// 내재변동성, 9(3)V9(2). 5바이트
	}

	return 1;
}


// ELW_시세종가
int ParseB1021(const double& timestamp, const char* in_buff, DF_ELW_MKT_PRC_CLS* out) {
	ELW_MKT_PRC_CLS* data = (ELW_MKT_PRC_CLS*)in_buff;

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
	out->high = Str2Int(data->high, sizeof(data->high));	// 고가, 정규장 고가
	out->low = Str2Int(data->low, sizeof(data->low));	// 저가, 정규장 저가
	out->ask_prc = Str2Int(data->ask_prc, sizeof(data->ask_prc));	// 매도호가, B1시 0값 SET
	out->bid_prc = Str2Int(data->bid_prc, sizeof(data->bid_prc));	// 매수호가, B1시 0값 SET
	out->cum_ccls_qty = Str2Dbl(data->cum_ccls_qty, sizeof(data->cum_ccls_qty), 0);	// 누적체결수량, 단위:주 ※시간외단일가, BUY-IN을 제외한 모든 체결수량 합산
	out->cum_trd_val = Str2Dbl(data->cum_trd_val, sizeof(data->cum_trd_val), 0);	// 누적거래대금, 단위:원 ※시간외단일가, BUY-IN을 제외한 모든 거래대금 합산
	out->trend_flg = data->trend_flg[0];	//실세/기세 구분, 0:초기값 1:실세 2:기세 3:거래무 4:시가기준가종목의 기세
	memcpy(out->brd_evt_id, data->brd_evt_id, sizeof(data->brd_evt_id));	// 보드이벤트ID, B1/B2 에서는 보드이벤트ID 사용금지(과거 상태값이 전송될 수 있음). 추후, 해당 항목 '000' 세팅 예정. 2014.03.24)
	memcpy(out->brd_id, data->brd_id, sizeof(data->brd_id));	// 보드ID, ※ 코드값모음 참조
	out->trsp_flg = data->trsp_flg[0];	//거래정지여부, Y, N
	out->bopen_ofhr_ccls_qty = Str2Dbl(data->bopen_ofhr_ccls_qty, sizeof(data->bopen_ofhr_ccls_qty), 0);	// 장개시전시간외종가 체결수량, 대량, 바스켓은 제외, 단위:주
	out->bopen_ofhr_trd_val = Str2Dbl(data->bopen_ofhr_trd_val, sizeof(data->bopen_ofhr_trd_val), 0);	// 장개시전시간외종가 거래대금, 대량, 바스켓은 제외, 단위:원
	out->opr_time_ccls_qty = Str2Dbl(data->opr_time_ccls_qty, sizeof(data->opr_time_ccls_qty), 0);	// 정규장체결수량, 대량, 바스켓은 제외, 단위:주
	out->opr_time_trd_val = Str2Dbl(data->opr_time_trd_val, sizeof(data->opr_time_trd_val), 0);	// 정규장거래대금, 대량, 바스켓은 제외, 단위:원
	out->ofhr_cls_ccls_qty = Str2Dbl(data->ofhr_cls_ccls_qty, sizeof(data->ofhr_cls_ccls_qty), 0);	// 장종료후시간외종가 체결수량, 대량, 바스켓은 제외, 단위:주
	out->ofhr_cls_trd_val = Str2Dbl(data->ofhr_cls_trd_val, sizeof(data->ofhr_cls_trd_val), 0);	// 장종료후시간외종가 거래대금, 대량, 바스켓은 제외, 단위:원
	out->elw_ely_cls_flg = data->elw_ely_cls_flg[0];	//ELW조기종료여부, Y,N 조기종료ELW 外 종목은 Default 'N' SET
	out->elw_ely_cls_time = Str2Int(data->elw_ely_cls_time, sizeof(data->elw_ely_cls_time));	// ELW조기종료시간, HHMMSS, ELW조기종료여부가 'Y'인 경우만 설정
	out->cmpt_msv_dir_clsf = Str2Int(data->cmpt_msv_dir_clsf, sizeof(data->cmpt_msv_dir_clsf));	// 경쟁대량 방향구분, 0:해당없음, 1:매도, 2:매수
	out->gen_bin_ccls_qty = Str2Dbl(data->gen_bin_ccls_qty, sizeof(data->gen_bin_ccls_qty), 0);	// 일반 Buy-in 체결수량, 단위:주
	out->gen_bin_ccls_trd_val = Str2Dbl(data->gen_bin_ccls_trd_val, sizeof(data->gen_bin_ccls_trd_val), 0);	// 일반 Buy-in 거래대금, 단위:원
	out->day_bin_ccls_qty = Str2Dbl(data->day_bin_ccls_qty, sizeof(data->day_bin_ccls_qty), 0);	// 당일 Buy-in 체결수량, 단위:주
	out->day_bin_ccls_trd_val = Str2Dbl(data->day_bin_ccls_trd_val, sizeof(data->day_bin_ccls_trd_val), 0);	// 당일 Buy-in 거래대금, 단위:원

	return 1;
}


// ELW_투자자별
int ParseC0021(const double& timestamp, const char* in_buff, DF_ELW_BYINV* out) {
	ELW_BYINV* data = (ELW_BYINV*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA구분, C0
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// 정보구분, 01:주식, 02:ELW, 03:ETF
	out->mkt_clsf = data->mkt_clsf[0];	//시장구분, 1:유가증권 2:코스닥
	memcpy(out->cmpt_time, data->cmpt_time, sizeof(data->cmpt_time));	// 산출시각, 90초 주기
	memcpy(out->inv_code, data->inv_code, sizeof(data->inv_code));	// 투자자코드, ※코드값모음 참조\n*코드'7000'시 수량, 대금정보 항목 0으로 전송 (20181210)
	memcpy(out->ind_code, data->ind_code, sizeof(data->ind_code));	// 업종코드, 0
	out->ask_ccls_qty = Str2Dbl(data->ask_ccls_qty, sizeof(data->ask_ccls_qty), 0);	// 매도체결수량, 단위:주
	out->ask_trd_val = Str2Dbl(data->ask_trd_val, sizeof(data->ask_trd_val), 0);	// 매도거래대금, 단위:원
	out->bid_ccls_qty = Str2Dbl(data->bid_ccls_qty, sizeof(data->bid_ccls_qty), 0);	// 매수체결수량, 단위:주
	out->bid_trd_val = Str2Dbl(data->bid_trd_val, sizeof(data->bid_trd_val), 0);	// 매수거래대금, 단위:원

	return 1;
}


// ELW_호가잔량_LP호가_포함
int ParseB7021(const double& timestamp, const char* in_buff, DF_ELW_ASK_RSD_WLP* out) {
	int i=0;
	ELW_ASK_RSD_WLP* data = (ELW_ASK_RSD_WLP*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA구분, B7
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// 정보구분, 01:유가증권종목 02:ELW
	out->mkt_clsf = data->mkt_clsf[0];	//시장구분, 1:유가증권
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// 종목코드, 표준코드
	out->stk_snr = Str2Int(data->stk_snr, sizeof(data->stk_snr));	// 종목일련번호, 종목배치(A0)의 종목일련번호
	out->cum_ccls_qty = Str2Dbl(data->cum_ccls_qty, sizeof(data->cum_ccls_qty), 0);	// 누적체결수량
	
	for ( i=0 ; i<10 ; i++ ) {
		out->lob_infos[i].ask_prc = Str2Int(data->lob_infos[i].ask_prc, sizeof(data->lob_infos[i].ask_prc));	// 매도호가
		out->lob_infos[i].bid_prc = Str2Int(data->lob_infos[i].bid_prc, sizeof(data->lob_infos[i].bid_prc));	// 매수호가
		out->lob_infos[i].ask_vol_rsd = Str2Dbl(data->lob_infos[i].ask_vol_rsd, sizeof(data->lob_infos[i].ask_vol_rsd), 0);	// 매도호가 잔량
		out->lob_infos[i].bid_vol_rsd = Str2Dbl(data->lob_infos[i].bid_vol_rsd, sizeof(data->lob_infos[i].bid_vol_rsd), 0);	// 매수호가 잔량
		out->lob_infos[i].lp_ask_vol_rsd = Str2Dbl(data->lob_infos[i].lp_ask_vol_rsd, sizeof(data->lob_infos[i].lp_ask_vol_rsd), 0);	// LP 매도호가 잔량
		out->lob_infos[i].lp_bid_vol_rsd = Str2Dbl(data->lob_infos[i].lp_bid_vol_rsd, sizeof(data->lob_infos[i].lp_bid_vol_rsd), 0);	// LP 매수호가 잔량
	}   // 호가

	out->ask_10_tot_rsd = Str2Dbl(data->ask_10_tot_rsd, sizeof(data->ask_10_tot_rsd), 0);	// 10단계호가매도총잔량
	out->bid_10_tot_rsd = Str2Dbl(data->bid_10_tot_rsd, sizeof(data->bid_10_tot_rsd), 0);	// 10단계호가매수총잔량
	out->ofhr_ask_tot_rsd = Str2Dbl(data->ofhr_ask_tot_rsd, sizeof(data->ofhr_ask_tot_rsd), 0);	// 장종료후시간외 매도총호가잔량, 보드ID가 "G3"일 경우 설정됨 \n ※ELW는 시간외거래 없음
	out->ofhr_bid_tot_rsd = Str2Dbl(data->ofhr_bid_tot_rsd, sizeof(data->ofhr_bid_tot_rsd), 0);	// 장종료후시간외 매수총호가잔량, 보드ID가 "G3"일 경우 설정됨 \n ※ELW는 시간외거래 없음
	memcpy(out->sess_id, data->sess_id, sizeof(data->sess_id));	// 세션ID, ※ 코드값모음 참조
	memcpy(out->brd_id, data->brd_id, sizeof(data->brd_id));	// 보드ID, ※ 코드값모음 참조
	out->exp_ccls_prc = Str2Int(data->exp_ccls_prc, sizeof(data->exp_ccls_prc));	// 예상체결가격
	out->exp_ccls_qty = Str2Dbl(data->exp_ccls_qty, sizeof(data->exp_ccls_qty), 0);	// 예상체결수량
	out->cmpt_msv_dir_clsf = Str2Int(data->cmpt_msv_dir_clsf, sizeof(data->cmpt_msv_dir_clsf));	// 경쟁대량 방향구분, 0:해당없음, 1:매도, 2:매수

	return 1;
}


// ETF사무수탁배치
int ParseN8011(const double& timestamp, const char* in_buff, DF_ETF_TRA_INFO* out) {
	ETF_TRA_INFO* data = (ETF_TRA_INFO*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA구분, N8
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// 정보구분, 01:주식
	out->mkt_clsf = data->mkt_clsf[0];	//시장구분, 1:유가증권
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// 종목코드, 표준코드
	out->snr = Str2Int(data->snr, sizeof(data->snr));	// 일련번호, 1~99999999 건수체크용
	out->etf_nr_shr_rtt = Str2Dbl(data->etf_nr_shr_rtt, sizeof(data->etf_nr_shr_rtt), 0);	// ETF유통주식수
	out->etf_nav_rtt = Str2Dbl(data->etf_nav_rtt, sizeof(data->etf_nav_rtt), 0);	// ETF유통순자산총액
	out->etf_nav_tot_val = Str2Dbl(data->etf_nav_tot_val, sizeof(data->etf_nav_tot_val), 0);	// ETF순자산총액, 단위:원
	out->etf_fin_nav_val = Str2Dbl(data->etf_fin_nav_val, sizeof(data->etf_fin_nav_val), 2);	// ETF최종순자산가치, 9(7)V9(2) 직전영업일자의 최종NAV
	out->etf_fx_nav_rtt = Str2Dbl(data->etf_fx_nav_rtt, sizeof(data->etf_fx_nav_rtt), 0);	// ETF외화유통순자산총액
	out->etf_fx_nav_tot_val = Str2Dbl(data->etf_fx_nav_tot_val, sizeof(data->etf_fx_nav_tot_val), 0);	// ETF외화순자산총액
	out->etf_fx_fin_nav_val = Str2Dbl(data->etf_fx_fin_nav_val, sizeof(data->etf_fx_fin_nav_val), 2);	// ETF외화최종순자산가치, 9(7)V9(2)
	out->etf_cu_qty = Str2Int(data->etf_cu_qty, sizeof(data->etf_cu_qty));	// ETF CU수량, 단위:증권
	out->prev_base_prc = Str2Dbl(data->prev_base_prc, sizeof(data->prev_base_prc), 2);	// 전일과표기준가격, 9999999V99
	out->prev_bdiv_base_prc = Str2Dbl(data->prev_bdiv_base_prc, sizeof(data->prev_bdiv_base_prc), 2);	// 전일배당전과표기준가격, 9999999V99
	out->prev_cash_div_val = Str2Dbl(data->prev_cash_div_val, sizeof(data->prev_cash_div_val), 2);	// 전일현금배당금액, 9999999999V99
	out->pprev_base_prc = Str2Dbl(data->pprev_base_prc, sizeof(data->pprev_base_prc), 2);	// 전전일과표기준가격, 9999999V99
	out->frgn_stk_prev_base_prc = Str2Dbl(data->frgn_stk_prev_base_prc, sizeof(data->frgn_stk_prev_base_prc), 2);	// 해외주식전일비과세과표기준가, 9999999V99 2016.02.29 신규
	out->frgn_stk_prev_bdiv_base_prc = Str2Dbl(data->frgn_stk_prev_bdiv_base_prc, sizeof(data->frgn_stk_prev_bdiv_base_prc), 2);	// 해외주식전일비과세배당전과표기준가, 9999999V99 2016.02.29 신규
	out->frgn_stk_pprev_bdiv_base_prc = Str2Dbl(data->frgn_stk_pprev_bdiv_base_prc, sizeof(data->frgn_stk_pprev_bdiv_base_prc), 2);	// 해외주식비과세전전일과표기준가, 9999999V99 2016.02.29 신규

	return 1;
}


// ETF PDF
int ParseF8011(const double& timestamp, const char* in_buff, DF_ETF_PDF* out) {
	ETF_PDF* data = (ETF_PDF*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA구분, F8
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// 정보구분, 01:주식
	out->mkt_clsf = data->mkt_clsf[0];	//시장구분, 1:유가증권
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// ETF코드
	out->data_snr = Str2Int(data->data_snr, sizeof(data->data_snr));	// 데이터 일련번호, 전송일련번호
	memcpy(out->date, data->date, sizeof(data->date));	// 일자, YYYYMMDD(적용일자)
	out->trb_nr = Str2Int(data->trb_nr, sizeof(data->trb_nr));	// 사무수탁회사번호, '903'한국예탁결제원,'049'미래에셋펀드서비스
	out->comp_stk_nr = Str2Int(data->comp_stk_nr, sizeof(data->comp_stk_nr));	// 구성종목수, 단위:종목(현금을 포함)
	memcpy(out->comp_stk_code, data->comp_stk_code, sizeof(data->comp_stk_code));	// 구성종목코드, ※개발가이드 참조(CP 추가) 2015.03.03
	out->one_cu_unit_scrt_nr = Str2Dbl(data->one_cu_unit_scrt_nr, sizeof(data->one_cu_unit_scrt_nr), 2);	// 1CU단위증권수/계약수/원화현금, ※개발가이드 참조(외국환포워드 추가) 2014.06.16 \n표시형식:9999999999999999v99
	out->comp_stk_mkt_clsf = Str2Int(data->comp_stk_mkt_clsf, sizeof(data->comp_stk_mkt_clsf));	// 구성종목시장구분, 0:유가증권(현금,KSP200T00001,FKSP200T0001포함)\n1:코스닥 2:기타 3:채권 4:선물 및 옵션 2018.02.05
	memcpy(out->comp_stk_nm, data->comp_stk_nm, sizeof(data->comp_stk_nm));	// 구성종목명, 해외종목일 경우 종목명, 그 외는 '0' 또는 SPACE
	out->par_val = Str2Dbl(data->par_val, sizeof(data->par_val), 0);	// 액면금액/설정현금액, ※개발가이드 참조(외국환포워드 추가) 2014.06.16
	memcpy(out->profit_allc_base_date, data->profit_allc_base_date, sizeof(data->profit_allc_base_date));	// 이익분배기준일, ※개발가이드 참조 2009.07.27
	out->assm_val = Str2Dbl(data->assm_val, sizeof(data->assm_val), 0);	// 평가금액, PDF내 종목별 비중 산출 기초data 신규 2011.08.29

	return 1;
}


// ETF운영사정보
int ParseM8011(const double& timestamp, const char* in_buff, DF_ETF_OPR_INFO* out) {
	ETF_OPR_INFO* data = (ETF_OPR_INFO*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA구분, M8
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// 정보구분, 01:주식
	out->mkt_clsf = data->mkt_clsf[0];	//시장구분, 1:유가증권
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// ETF 코드, 표준코드
	out->snr = Str2Int(data->snr, sizeof(data->snr));	// 일련번호, 00000001~99999999 건수체크용
	out->trb_nr = Str2Int(data->trb_nr, sizeof(data->trb_nr));	// 사무수탁 회사번호, '903'한국예탁결제원,'049'미래에셋펀드서비스
	out->mngt_code = Str2Int(data->mngt_code, sizeof(data->mngt_code));	// 운용사코드
	memcpy(out->mngt_kor_abrv, data->mngt_kor_abrv, sizeof(data->mngt_kor_abrv));	// 운용사 한글약명
	memcpy(out->mngt_eng_abrv, data->mngt_eng_abrv, sizeof(data->mngt_eng_abrv));	// 운용사 영문약명

	return 1;
}


// ETF NAV
int ParseF7011(const double& timestamp, const char* in_buff, DF_ETF_NAV* out) {
	ETF_NAV* data = (ETF_NAV*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA구분, F7
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// 정보구분, 01:주식
	out->mkt_clsf = data->mkt_clsf[0];	//시장구분, 1:유가증권 2:코스닥
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// ETF 종목코드, ETF 종목코드
	memcpy(out->time, data->time, sizeof(data->time));	// 시간, HHMMSS:장중 JSAM00:장종료
	out->prev_nav = Str2Dbl(data->prev_nav, sizeof(data->prev_nav), 2);	// 전일 NAV, 9(7)V9(2)
	out->opr_time_fin_nav = Str2Dbl(data->opr_time_fin_nav, sizeof(data->opr_time_fin_nav), 2);	// 장중/최종 NAV, 9(7)V9(2)

	return 1;
}


// ETF 예상NAV
int ParseI3011(const double& timestamp, const char* in_buff, DF_ETF_EXP_NAV* out) {
	ETF_EXP_NAV* data = (ETF_EXP_NAV*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA구분, I3
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// 정보구분, 01:주식
	out->mkt_clsf = data->mkt_clsf[0];	//시장구분, 1:유가증권 2:코스닥
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// ETF 종목코드, ETF 종목코드
	memcpy(out->time, data->time, sizeof(data->time));	// 시간, HHMMSS:08:30~09:00(PREJJJ) 14:50~15:00(JUNJJJ)
	out->prev_nav = Str2Dbl(data->prev_nav, sizeof(data->prev_nav), 2);	// 전일 NAV, 9999999V99
	out->opr_time_fin_nav = Str2Dbl(data->opr_time_fin_nav, sizeof(data->opr_time_fin_nav), 2);	// 장중/최종 NAV, 9999999V99

	return 1;
}


// ETF 추적오차율
int ParseP6011(const double& timestamp, const char* in_buff, DF_ETF_TER* out) {
	ETF_TER* data = (ETF_TER*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA구분, P6
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// 정보구분, 01:주식
	out->mkt_clsf = data->mkt_clsf[0];	//시장구분, 1:유가증권 2:코스닥
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// ETF 종목코드, ETF 종목코드
	out->snr = Str2Int(data->snr, sizeof(data->snr));	// 일련번호, 1~99999999 전송일련번호,건수체크용
	memcpy(out->date, data->date, sizeof(data->date));	// 일자, YYYYMMDD:전영업일자
	out->trkg_err_rate = Str2Dbl(data->trkg_err_rate, sizeof(data->trkg_err_rate), 2);	// 추적오차율, 9(7)V9(2), 단위:% ※ 개발가이드 참조
	out->dspr = Str2SignDouble(data->dspr_sign, sizeof(data->dspr_sign) + sizeof(data->dspr), 2);	// 괴리율, 9(7)V9(2), 단위:%

	return 1;
}


// ETF_투자자별
int ParseC0031(const double& timestamp, const char* in_buff, DF_ETF_BYINV* out) {
	ETF_BYINV* data = (ETF_BYINV*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA구분, C0
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// 정보구분, 01:주식, 02:ELW, 03:ETF
	out->mkt_clsf = data->mkt_clsf[0];	//시장구분, 1:유가증권 2:코스닥
	memcpy(out->cmpt_time, data->cmpt_time, sizeof(data->cmpt_time));	// 산출시각, 90초 주기
	memcpy(out->inv_code, data->inv_code, sizeof(data->inv_code));	// 투자자코드, ※코드값모음 참조\n*코드'7000'시 수량, 대금정보 항목 0으로 전송 (20181210)
	memcpy(out->ind_code, data->ind_code, sizeof(data->ind_code));	// 업종코드, 0
	out->ask_ccls_qty = Str2Dbl(data->ask_ccls_qty, sizeof(data->ask_ccls_qty), 0);	// 매도체결수량, 단위:주
	out->ask_trd_val = Str2Dbl(data->ask_trd_val, sizeof(data->ask_trd_val), 0);	// 매도거래대금, 단위:원
	out->bid_ccls_qty = Str2Dbl(data->bid_ccls_qty, sizeof(data->bid_ccls_qty), 0);	// 매수체결수량, 단위:주
	out->bid_trd_val = Str2Dbl(data->bid_trd_val, sizeof(data->bid_trd_val), 0);	// 매수거래대금, 단위:원

	return 1;
}


// 회원사정보
int ParseM9011(const double& timestamp, const char* in_buff, DF_MBR_INFO* out) {
	MBR_INFO* data = (MBR_INFO*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA구분, M9
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// 정보구분, 01:주식
	out->mkt_clsf = data->mkt_clsf[0];	//시장구분, 1:유가증권
	out->snr = Str2Int(data->snr, sizeof(data->snr));	// 일련번호, 00000001~99999999 건수체크용
	memcpy(out->opr_date, data->opr_date, sizeof(data->opr_date));	// 영업일자
	memcpy(out->mkt_ptcp_nr, data->mkt_ptcp_nr, sizeof(data->mkt_ptcp_nr));	// 시장참가자번호
	memcpy(out->mkt_ptcp_kor_nm, data->mkt_ptcp_kor_nm, sizeof(data->mkt_ptcp_kor_nm));	// 시장참가자한글명
	memcpy(out->mkt_ptcp_eng_nm, data->mkt_ptcp_eng_nm, sizeof(data->mkt_ptcp_eng_nm));	// 시장참가자영문명
	memcpy(out->mkt_ptcp_kor_abrv, data->mkt_ptcp_kor_abrv, sizeof(data->mkt_ptcp_kor_abrv));	// 시장참가자한글약명

	return 1;
}


// KOSPI지수
int ParseD0011(const double& timestamp, const char* in_buff, DF_KOSPI_IDX* out) {
	KOSPI_IDX* data = (KOSPI_IDX*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA구분, ※개발가이드 참조
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// 정보구분, 01:주식
	out->mkt_clsf = data->mkt_clsf[0];	//시장구분, 1:유가증권 2:코스닥
	memcpy(out->ind_code, data->ind_code, sizeof(data->ind_code));	// 업종코드, ※개발가이드 참조
	memcpy(out->time, data->time, sizeof(data->time));	// 시간, ※개발가이드 참조
	out->idx = Str2Dbl(data->idx, sizeof(data->idx), 2);	// 지수, 9(6)V9(2)
	out->ctrs = Str2SignDouble(data->sign, sizeof(data->sign) + sizeof(data->ctrs), 2);	// 대비, 999999V99
	out->ccls_qty = Str2Int(data->ccls_qty, sizeof(data->ccls_qty));	// 체결수량, 단위:천주
	out->trd_val = Str2Int(data->trd_val, sizeof(data->trd_val));	// 거래대금, 단위:백만원

	return 1;
}


// KOSPI예상지수
int ParseD1011(const double& timestamp, const char* in_buff, DF_KOSPI_EXP_IDX* out) {
	KOSPI_EXP_IDX* data = (KOSPI_EXP_IDX*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA구분, ※개발가이드 참조
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// 정보구분, 01:주식
	out->mkt_clsf = data->mkt_clsf[0];	//시장구분, 1:유가증권 2:코스닥
	memcpy(out->ind_code, data->ind_code, sizeof(data->ind_code));	// 업종코드, ※개발가이드 참조
	memcpy(out->time, data->time, sizeof(data->time));	// 시간, ※개발가이드 참조
	out->idx = Str2Dbl(data->idx, sizeof(data->idx), 2);	// 지수, 9(6)V9(2)
	out->ctrs = Str2SignDouble(data->sign, sizeof(data->sign) + sizeof(data->ctrs), 2);	// 대비, 999999V99
	out->ccls_qty = Str2Int(data->ccls_qty, sizeof(data->ccls_qty));	// 체결수량, 단위:천주
	out->trd_val = Str2Int(data->trd_val, sizeof(data->trd_val));	// 거래대금, 단위:백만원

	return 1;
}


// KOSPI200지수
int ParseD2011(const double& timestamp, const char* in_buff, DF_KOSPI_200_IDX* out) {
	KOSPI_200_IDX* data = (KOSPI_200_IDX*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA구분, ※개발가이드 참조
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// 정보구분, 01:주식
	out->mkt_clsf = data->mkt_clsf[0];	//시장구분, 1:유가증권 2:코스닥
	memcpy(out->ind_code, data->ind_code, sizeof(data->ind_code));	// 업종코드, ※개발가이드 참조
	memcpy(out->time, data->time, sizeof(data->time));	// 시간, ※개발가이드 참조
	out->idx = Str2Dbl(data->idx, sizeof(data->idx), 2);	// 지수, 9(6)V9(2)
	out->ctrs = Str2SignDouble(data->sign, sizeof(data->sign) + sizeof(data->ctrs), 2);	// 대비, 999999V99
	out->ccls_qty = Str2Int(data->ccls_qty, sizeof(data->ccls_qty));	// 체결수량, 단위:천주
	out->trd_val = Str2Int(data->trd_val, sizeof(data->trd_val));	// 거래대금, 단위:백만원

	return 1;
}


// KOSPI200예상지수
int ParseD3011(const double& timestamp, const char* in_buff, DF_KOSPI_200_EXP_IDX* out) {
	KOSPI_200_EXP_IDX* data = (KOSPI_200_EXP_IDX*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA구분, ※개발가이드 참조
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// 정보구분, 01:주식
	out->mkt_clsf = data->mkt_clsf[0];	//시장구분, 1:유가증권 2:코스닥
	memcpy(out->ind_code, data->ind_code, sizeof(data->ind_code));	// 업종코드, ※개발가이드 참조
	memcpy(out->time, data->time, sizeof(data->time));	// 시간, ※개발가이드 참조
	out->idx = Str2Dbl(data->idx, sizeof(data->idx), 2);	// 지수, 9(6)V9(2)
	out->ctrs = Str2SignDouble(data->sign, sizeof(data->sign) + sizeof(data->ctrs), 2);	// 대비, 999999V99
	out->ccls_qty = Str2Int(data->ccls_qty, sizeof(data->ccls_qty));	// 체결수량, 단위:천주
	out->trd_val = Str2Int(data->trd_val, sizeof(data->trd_val));	// 거래대금, 단위:백만원

	return 1;
}


// KOSPI100/50지수
int ParseD4011(const double& timestamp, const char* in_buff, DF_KOSPI_100_50_IDX* out) {
	KOSPI_100_50_IDX* data = (KOSPI_100_50_IDX*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA구분, ※개발가이드 참조
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// 정보구분, 01:주식
	out->mkt_clsf = data->mkt_clsf[0];	//시장구분, 1:유가증권 2:코스닥
	memcpy(out->ind_code, data->ind_code, sizeof(data->ind_code));	// 업종코드, ※개발가이드 참조
	memcpy(out->time, data->time, sizeof(data->time));	// 시간, ※개발가이드 참조
	out->idx = Str2Dbl(data->idx, sizeof(data->idx), 2);	// 지수, 9(6)V9(2)
	out->ctrs = Str2SignDouble(data->sign, sizeof(data->sign) + sizeof(data->ctrs), 2);	// 대비, 999999V99
	out->ccls_qty = Str2Int(data->ccls_qty, sizeof(data->ccls_qty));	// 체결수량, 단위:천주
	out->trd_val = Str2Int(data->trd_val, sizeof(data->trd_val));	// 거래대금, 단위:백만원

	return 1;
}


// KOSPI200 섹터예상지수
int ParseN6011(const double& timestamp, const char* in_buff, DF_KOSPI_200_STR_EXP_IDX* out) {
	KOSPI_200_STR_EXP_IDX* data = (KOSPI_200_STR_EXP_IDX*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA구분, ※개발가이드 참조
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// 정보구분, 01:주식
	out->mkt_clsf = data->mkt_clsf[0];	//시장구분, 1:유가증권 2:코스닥
	memcpy(out->ind_code, data->ind_code, sizeof(data->ind_code));	// 업종코드, ※개발가이드 참조
	memcpy(out->time, data->time, sizeof(data->time));	// 시간, ※개발가이드 참조
	out->idx = Str2Dbl(data->idx, sizeof(data->idx), 2);	// 지수, 9(6)V9(2)
	out->ctrs = Str2SignDouble(data->sign, sizeof(data->sign) + sizeof(data->ctrs), 2);	// 대비, 999999V99
	out->ccls_qty = Str2Int(data->ccls_qty, sizeof(data->ccls_qty));	// 체결수량, 단위:천주
	out->trd_val = Str2Int(data->trd_val, sizeof(data->trd_val));	// 거래대금, 단위:백만원

	return 1;
}


// KOSPI200 섹터지수
int ParseN5011(const double& timestamp, const char* in_buff, DF_KOSPI_200_STR_IDX* out) {
	KOSPI_200_STR_IDX* data = (KOSPI_200_STR_IDX*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA구분, ※개발가이드 참조
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// 정보구분, 01:주식
	out->mkt_clsf = data->mkt_clsf[0];	//시장구분, 1:유가증권 2:코스닥
	memcpy(out->ind_code, data->ind_code, sizeof(data->ind_code));	// 업종코드, ※개발가이드 참조
	memcpy(out->time, data->time, sizeof(data->time));	// 시간, ※개발가이드 참조
	out->idx = Str2Dbl(data->idx, sizeof(data->idx), 2);	// 지수, 9(6)V9(2)
	out->ctrs = Str2SignDouble(data->sign, sizeof(data->sign) + sizeof(data->ctrs), 2);	// 대비, 999999V99
	out->ccls_qty = Str2Int(data->ccls_qty, sizeof(data->ccls_qty));	// 체결수량, 단위:천주
	out->trd_val = Str2Int(data->trd_val, sizeof(data->trd_val));	// 거래대금, 단위:백만원

	return 1;
}


// KRX100지수
int ParseC8011(const double& timestamp, const char* in_buff, DF_KOSPI_100_IDX* out) {
	KOSPI_100_IDX* data = (KOSPI_100_IDX*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA구분, ※개발가이드 참조
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// 정보구분, 01:주식
	out->mkt_clsf = data->mkt_clsf[0];	//시장구분, 1:유가증권 2:코스닥 9:해외주가지수 2012.04.30 추가
	memcpy(out->ind_code, data->ind_code, sizeof(data->ind_code));	// 업종코드, ※개발가이드 참조
	memcpy(out->time, data->time, sizeof(data->time));	// 시간, ※개발가이드 참조 ※해외주가지수일 경우 GMT시간
	out->idx = Str2Dbl(data->idx, sizeof(data->idx), 2);	// 지수, 9(6)V9(2)
	out->ctrs = Str2SignDouble(data->sign, sizeof(data->sign) + sizeof(data->ctrs), 2);	// 대비, 999999V99
	out->ccls_qty = Str2Int(data->ccls_qty, sizeof(data->ccls_qty));	// 체결수량, 단위:천주 ※해외주가지수일 경우 FILLER처리
	out->trd_val = Str2Int(data->trd_val, sizeof(data->trd_val));	// 거래대금, 단위:백만원 ※해외주가지수일 경우 FILLER처리

	return 1;
}


// KRX100예상지수
int ParseC9011(const double& timestamp, const char* in_buff, DF_KOSPI_100_EXP_IDX* out) {
	KOSPI_100_EXP_IDX* data = (KOSPI_100_EXP_IDX*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA구분, ※개발가이드 참조
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// 정보구분, 01:주식
	out->mkt_clsf = data->mkt_clsf[0];	//시장구분, 1:유가증권 2:코스닥 9:해외주가지수 2012.04.30 추가
	memcpy(out->ind_code, data->ind_code, sizeof(data->ind_code));	// 업종코드, ※개발가이드 참조
	memcpy(out->time, data->time, sizeof(data->time));	// 시간, ※개발가이드 참조 ※해외주가지수일 경우 GMT시간
	out->idx = Str2Dbl(data->idx, sizeof(data->idx), 2);	// 지수, 9(6)V9(2)
	out->ctrs = Str2SignDouble(data->sign, sizeof(data->sign) + sizeof(data->ctrs), 2);	// 대비, 999999V99
	out->ccls_qty = Str2Int(data->ccls_qty, sizeof(data->ccls_qty));	// 체결수량, 단위:천주 ※해외주가지수일 경우 FILLER처리
	out->trd_val = Str2Int(data->trd_val, sizeof(data->trd_val));	// 거래대금, 단위:백만원 ※해외주가지수일 경우 FILLER처리

	return 1;
}


// 동일가중지수
int ParseN9011(const double& timestamp, const char* in_buff, DF_EWIDX* out) {
	EWIDX* data = (EWIDX*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA구분, ※개발가이드 참조
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// 정보구분, 01:주식
	out->mkt_clsf = data->mkt_clsf[0];	//시장구분, 1:유가증권 2:코스닥
	memcpy(out->ind_code, data->ind_code, sizeof(data->ind_code));	// 업종코드, ※개발가이드 참조
	memcpy(out->time, data->time, sizeof(data->time));	// 시간, ※개발가이드 참조
	out->idx = Str2Dbl(data->idx, sizeof(data->idx), 2);	// 지수, 9(6)V9(2)
	out->ctrs = Str2SignDouble(data->sign, sizeof(data->sign) + sizeof(data->ctrs), 2);	// 대비, 999999V99
	out->ccls_qty = Str2Int(data->ccls_qty, sizeof(data->ccls_qty));	// 체결수량, 단위:천주
	out->trd_val = Str2Int(data->trd_val, sizeof(data->trd_val));	// 거래대금, 단위:백만원

	return 1;
}


// 동일가중예상지수
int ParseO1011(const double& timestamp, const char* in_buff, DF_EWEIDX* out) {
	EWEIDX* data = (EWEIDX*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA구분, ※개발가이드 참조
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// 정보구분, 01:주식
	out->mkt_clsf = data->mkt_clsf[0];	//시장구분, 1:유가증권 2:코스닥
	memcpy(out->ind_code, data->ind_code, sizeof(data->ind_code));	// 업종코드, ※개발가이드 참조
	memcpy(out->time, data->time, sizeof(data->time));	// 시간, ※개발가이드 참조
	out->idx = Str2Dbl(data->idx, sizeof(data->idx), 2);	// 지수, 9(6)V9(2)
	out->ctrs = Str2SignDouble(data->sign, sizeof(data->sign) + sizeof(data->ctrs), 2);	// 대비, 999999V99
	out->ccls_qty = Str2Int(data->ccls_qty, sizeof(data->ccls_qty));	// 체결수량, 단위:천주
	out->trd_val = Str2Int(data->trd_val, sizeof(data->trd_val));	// 거래대금, 단위:백만원

	return 1;
}


// 시장지수 그룹_만기코드
int ParseG1067(const double& timestamp, const char* in_buff, DF_MARKET_IDX_GROUP_EXP_CODE* out) {
	MARKET_IDX_GROUP_EXP_CODE* data = (MARKET_IDX_GROUP_EXP_CODE*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA구분, G1
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// 정보구분, 06:장내일반채권
	out->mkt_clsf = data->mkt_clsf[0];	//시장구분, 7:채권
	out->snr = Str2Int(data->snr, sizeof(data->snr));	// 일련번호, 1~99999999 건수체크용
	out->code_clsf = data->code_clsf[0];	//코드 구분, 1:그룹코드 2:만기코드
	memcpy(out->apl_date, data->apl_date, sizeof(data->apl_date));	// 적용일, YYYYMMDD
	memcpy(out->grp_mtr_code, data->grp_mtr_code, sizeof(data->grp_mtr_code));	// 그룹/만기코드, 그룹코드:"XXXXX", 만기코드:"XXX "
	memcpy(out->grp_mtr_code_nm, data->grp_mtr_code_nm, sizeof(data->grp_mtr_code_nm));	// 그룹/만기코드명
	out->grp_mtr_code_stg = data->grp_mtr_code_stg[0];	//그룹/만기코드단계, 그룹코드:0,1,2,3,4 만기코드:0,1,2,3

	return 1;
}


// 와이즈에프엔지수
int ParseP3011(const double& timestamp, const char* in_buff, DF_WISEFN_IDX* out) {
	WISEFN_IDX* data = (WISEFN_IDX*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA구분, P3
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// 정보구분, 01:주식
	out->mkt_clsf = data->mkt_clsf[0];	//시장구분, 1:유가증권
	memcpy(out->ind_code, data->ind_code, sizeof(data->ind_code));	// 업종코드, 코드값모음 참고\nWISEFn신규지수4종추가(2015.03.23)
	memcpy(out->time, data->time, sizeof(data->time));	// 시간, ※개발가이드 참조
	out->idx = Str2Dbl(data->idx, sizeof(data->idx), 2);	// 지수, 9(6)V9(2)
	out->ctrs = Str2SignDouble(data->sign, sizeof(data->sign) + sizeof(data->ctrs), 2);	// 대비, 999999V99
	out->ccls_qty = Str2Int(data->ccls_qty, sizeof(data->ccls_qty));	// 체결수량, 단위:천주
	out->trd_val = Str2Int(data->trd_val, sizeof(data->trd_val));	// 거래대금, 단위:백만원

	return 1;
}


// 코스피_거래원
int ParseB9011(const double& timestamp, const char* in_buff, DF_KOSPI_TRS* out) {
	int i=0;
	KOSPI_TRS* data = (KOSPI_TRS*)in_buff;

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


// ELW_거래원
int ParseB9021(const double& timestamp, const char* in_buff, DF_ELW_TRS* out) {
	int i=0;
	ELW_TRS* data = (ELW_TRS*)in_buff;

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


// 코스피_종목별투자자별 종가
int ParseC1011(const double& timestamp, const char* in_buff, DF_KOSPI_BYSTK_BYINV_CLS* out) {
	int i=0;
	KOSPI_BYSTK_BYINV_CLS* data = (KOSPI_BYSTK_BYINV_CLS*)in_buff;

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


// ELW_종목별투자자별 종가
int ParseC1021(const double& timestamp, const char* in_buff, DF_ELW_BYSTK_BYINV_CLS* out) {
	int i=0;
	ELW_BYSTK_BYINV_CLS* data = (ELW_BYSTK_BYINV_CLS*)in_buff;

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


// 해외지수 ETF NAV
int ParseL5011(const double& timestamp, const char* in_buff, DF_FRIDX_ETF_NAV* out) {
	FRIDX_ETF_NAV* data = (FRIDX_ETF_NAV*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA구분, F7(국내지수), L5(해외지수) 멀티캐스트 적용 후 변경
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// 정보구분, 01:주식
	out->mkt_clsf = data->mkt_clsf[0];	//시장구분, 1:유가증권
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// ETF 종목코드, ETF 종목코드
	memcpy(out->time, data->time, sizeof(data->time));	// 시간, ※개발가이드 참조
	out->prev_nav = Str2Dbl(data->prev_nav, sizeof(data->prev_nav), 2);	// 전일 NAV, 9(7)V9(2)
	out->opr_time_fin_nav = Str2Dbl(data->opr_time_fin_nav, sizeof(data->opr_time_fin_nav), 2);	// 장중/최종 NAV, 9(7)V9(2)

	return 1;
}


// 해외ETF 추적오차율
int ParseP7011(const double& timestamp, const char* in_buff, DF_FRIDX_TER* out) {
	FRIDX_TER* data = (FRIDX_TER*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA구분, P7
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// 정보구분, 01:주식
	out->mkt_clsf = data->mkt_clsf[0];	//시장구분, 1:유가증권 2:코스닥
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// ETF 종목코드, ETF 종목코드
	out->snr = Str2Int(data->snr, sizeof(data->snr));	// 일련번호, 1~99999999 전송일련번호,건수체크용
	memcpy(out->date, data->date, sizeof(data->date));	// 일자, YYYYMMDD:전영업일자
	out->trkg_err_rate = Str2Dbl(data->trkg_err_rate, sizeof(data->trkg_err_rate), 2);	// 추적오차율, 9(7)V9(2), 단위:%
	out->dspr = Str2SignDouble(data->dspr_sign, sizeof(data->dspr_sign) + sizeof(data->dspr), 2);	// 괴리율, 9(7)V9(2), 단위:%

	return 1;
}


// 합성ETF 일일 거래상대방 위험평가액 정보
int ParseQ4011(const double& timestamp, const char* in_buff, DF_SETF_DAY_CPTY_RISK_INFO* out) {
	SETF_DAY_CPTY_RISK_INFO* data = (SETF_DAY_CPTY_RISK_INFO*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA구분, Q4
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// 정보구분, 01:주식
	out->mkt_clsf = data->mkt_clsf[0];	//시장구분, 1:유가증권 2:코스닥
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// ETF코드, 표준코드
	out->data_snr = Str2Int(data->data_snr, sizeof(data->data_snr));	// 데이터 일련번호, 1~99999999 전송일련번호, 건수체크용
	out->date = Str2Int(data->date, sizeof(data->date));	// 일자, YYYYMMDD
	out->trb_nr = Str2Int(data->trb_nr, sizeof(data->trb_nr));	// 사무수탁회사번호, '903'한국예탁결제원,'049'미래에셋펀드서비스
	memcpy(out->cntr_pty_nm, data->cntr_pty_nm, sizeof(data->cntr_pty_nm));	// 거래상대방명, 거래상대방명
	out->ofmkt_drvt_type = Str2Int(data->ofmkt_drvt_type, sizeof(data->ofmkt_drvt_type));	// 장외파생상품유형, 0:자금공여형 1:자금비공여형 ※개발가이드 참조
	out->nav_tot_val = Str2Dbl(data->nav_tot_val, sizeof(data->nav_tot_val), 0);	// 순자산총액, 단위:원
	out->tot_risk_xps_val = Str2Dbl(data->tot_risk_xps_val, sizeof(data->tot_risk_xps_val), 0);	// 총위험노출액, 단위:원 ※개발가이드 참조
	out->cltr_assm_val = Str2Dbl(data->cltr_assm_val, sizeof(data->cltr_assm_val), 0);	// 담보평가액, 단위:원 ※개발가이드 참조
	out->cltr_rate = Str2Dbl(data->cltr_rate, sizeof(data->cltr_rate), 2);	// 담보비율, 99999V99 단위:% ※개발가이드 참조
	out->risk_assm_val = Str2Dbl(data->risk_assm_val, sizeof(data->risk_assm_val), 0);	// 위험평가액, 단위:원 ※개발가이드 참조
	out->risk_assm_rate = Str2Dbl(data->risk_assm_rate, sizeof(data->risk_assm_rate), 2);	// 위험평가액비율, 99999V99 단위:% ※개발가이드 참조

	return 1;
}


// MKF지수
int ParseE2011(const double& timestamp, const char* in_buff, DF_MKF_IDX* out) {
	MKF_IDX* data = (MKF_IDX*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA구분, E2
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// 정보구분, 01:주식
	out->mkt_clsf = data->mkt_clsf[0];	//시장구분, 1:유가증권 2:코스닥 2012.05.21 추가
	memcpy(out->ind_code, data->ind_code, sizeof(data->ind_code));	// 업종코드, ※개발가이드 참조
	memcpy(out->time, data->time, sizeof(data->time));	// 시간, ※개발가이드 참조
	out->idx = Str2Dbl(data->idx, sizeof(data->idx), 2);	// 지수, 9(6)V9(2)
	out->ctrs = Str2SignDouble(data->sign, sizeof(data->sign) + sizeof(data->ctrs), 2);	// 대비, 999999V99
	out->ccls_qty = Str2Int(data->ccls_qty, sizeof(data->ccls_qty));	// 체결수량, 단위:천주
	out->trd_val = Str2Int(data->trd_val, sizeof(data->trd_val));	// 거래대금, 단위:백만원

	return 1;
}


// MKF지수(엔환율반영)
int ParseO9011(const double& timestamp, const char* in_buff, DF_MKF_IDX_WYFX* out) {
	MKF_IDX_WYFX* data = (MKF_IDX_WYFX*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA구분, O9
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// 정보구분, 01:주식
	out->mkt_clsf = data->mkt_clsf[0];	//시장구분, 1:유가증권 2:코스닥 2012.05.21 추가
	memcpy(out->ind_code, data->ind_code, sizeof(data->ind_code));	// 업종코드, ※개발가이드 참조
	memcpy(out->time, data->time, sizeof(data->time));	// 시간, ※개발가이드 참조
	out->idx = Str2Dbl(data->idx, sizeof(data->idx), 2);	// 지수, 9(6)V9(2)
	out->ctrs = Str2SignDouble(data->sign, sizeof(data->sign) + sizeof(data->ctrs), 2);	// 대비, 999999V99
	out->ccls_qty = Str2Int(data->ccls_qty, sizeof(data->ccls_qty));	// 체결수량, 단위:천주
	out->trd_val = Str2Int(data->trd_val, sizeof(data->trd_val));	// 거래대금, 단위:백만원

	return 1;
}


// 해외지수ETF대상지수
int ParseM3011(const double& timestamp, const char* in_buff, DF_FRIDX_ETF_IDX* out) {
	FRIDX_ETF_IDX* data = (FRIDX_ETF_IDX*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA구분, M3
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// 정보구분, 01:주식
	out->mkt_clsf = data->mkt_clsf[0];	//시장구분, 1:유가증권
	memcpy(out->date, data->date, sizeof(data->date));	// 일자, 현지영업일 ※최종 수신데이터 전송, 전일 데이터와 중복가능
	memcpy(out->smbl_code, data->smbl_code, sizeof(data->smbl_code));	// 심볼코드, ※개발가이드 참조
	memcpy(out->idx, data->idx, sizeof(data->idx));	// 지수, 9999999V999, Excess Return(ER)
	memcpy(out->tot_profit_idx, data->tot_profit_idx, sizeof(data->tot_profit_idx));	// 총수익지수, 9999999V999, Total Retrun(TR) 2011.04.01 신규
	memcpy(out->cls_prc, data->cls_prc, sizeof(data->cls_prc));	// 종가, 9999999V999, Close Price(Spot) 2011.04.01 신규

	return 1;
}


// 해외지수
int ParseO5019(const double& timestamp, const char* in_buff, DF_FRIDX* out) {
	FRIDX* data = (FRIDX*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA구분, ※다음 PAGE 지수관련 설명 참조
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// 정보구분, 01:주식
	out->mkt_clsf = data->mkt_clsf[0];	//시장구분, 1:유가증권 2:코스닥 9: 해외주가지수 2012.4.30 추가
	memcpy(out->ind_code, data->ind_code, sizeof(data->ind_code));	// 업종코드, ※개발가이드 참조
	memcpy(out->time, data->time, sizeof(data->time));	// 시간, ※개발가이드 참조 ※MSCI지수:EST(뉴욕시간) 2013.02.18 변경
	out->idx = Str2Dbl(data->idx, sizeof(data->idx), 2);	// 지수, 9(6)V9(2)
	out->ctrs = Str2SignDouble(data->sign, sizeof(data->sign) + sizeof(data->ctrs), 2);	// 대비, 999999V99
	out->ccls_qty = Str2Int(data->ccls_qty, sizeof(data->ccls_qty));	// 체결수량, 단위:천주 ※해외주가지수일 경우 FILLER처리
	out->trd_val = Str2Int(data->trd_val, sizeof(data->trd_val));	// 거래대금, 단위:백만원 ※해외주가지수일 경우 FILLER처리

	return 1;
}


// 합성ETF 기초지수 구성종목
int ParseQ5011(const double& timestamp, const char* in_buff, DF_SETF_BASE_IDX_COMP_STK* out) {
	SETF_BASE_IDX_COMP_STK* data = (SETF_BASE_IDX_COMP_STK*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA구분, Q5
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// 정보구분, 01:주식
	out->mkt_clsf = data->mkt_clsf[0];	//시장구분, 1:유가증권 2:코스닥
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// ETF코드, 표준코드
	out->data_snr = Str2Int(data->data_snr, sizeof(data->data_snr));	// 데이터 일련번호, 1~99999999 전송일련번호, 건수체크용
	out->date = Str2Int(data->date, sizeof(data->date));	// 일자, YYYYMMDD
	out->trb_nr = Str2Int(data->trb_nr, sizeof(data->trb_nr));	// 사무수탁회사번호, '903'한국예탁결제원,'049'미래에셋펀드서비스
	out->comp_stk_nr = Str2Int(data->comp_stk_nr, sizeof(data->comp_stk_nr));	// 구성종목수, 단위:종목(현금포함)
	memcpy(out->comp_stk_code, data->comp_stk_code, sizeof(data->comp_stk_code));	// 구성종목코드, 표준코드\n해외종목일 경우 '0' 또는 SPACE로 Setting될 수 있음
	memcpy(out->comp_stk_nm, data->comp_stk_nm, sizeof(data->comp_stk_nm));	// 구성종목명, 종목명
	out->comp_rate = Str2Dbl(data->comp_rate, sizeof(data->comp_rate), 2);	// 구성비, 지수내 구성비\n99999V99 단위:%

	return 1;
}


// 프리보드 외국인 종목별투자정보_확정치
int ParseF1013(const double& timestamp, const char* in_buff, DF_FBRD_FRGN_INV_INFO* out) {
	FBRD_FRGN_INV_INFO* data = (FBRD_FRGN_INV_INFO*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA구분, F1
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// 정보구분, 01:주식 90:기타
	out->mkt_clsf = data->mkt_clsf[0];	//시장구분, 1:유가증권 2:코스닥 3:프리보드 7:채권
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// 종목코드, 표준코드
	out->snr = Str2Int(data->snr, sizeof(data->snr));	// 일련번호, 1~99999999 건수체크용
	memcpy(out->trd_date, data->trd_date, sizeof(data->trd_date));	// 매매일자, YYYYMMDD
	out->stk_lim_ratio = Str2Dbl(data->stk_lim_ratio, sizeof(data->stk_lim_ratio), 4);	// 종목한도비율, 9V9999 (예:15%일때 → 01500으로 전송)
	out->psn_lim_ratio = Str2Dbl(data->psn_lim_ratio, sizeof(data->psn_lim_ratio), 4);	// 개인한도비율, 9V9999 (예:15%일때 → 01500으로 전송)
	out->stk_lstd = Str2Dbl(data->stk_lstd, sizeof(data->stk_lstd), 0);	// 상장주식수, 단위:주
	out->ordbl_qty = Str2Dbl(data->ordbl_qty, sizeof(data->ordbl_qty), 0);	// 주문가능수량, 단위:주
	out->lim_xhs_clsf = data->lim_xhs_clsf[0];	//한도소진구분, 0:정상 1:한도소진 2:한도종목신규지정 3:한도종목해지

	return 1;
}


// 프리보드 외국인 주문가능수량
int ParseF2013(const double& timestamp, const char* in_buff, DF_FBRD_FRGN_ORDL_QTY* out) {
	FBRD_FRGN_ORDL_QTY* data = (FBRD_FRGN_ORDL_QTY*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA구분, F2
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// 정보구분, 01:주식 90:기타
	out->mkt_clsf = data->mkt_clsf[0];	//시장구분, 1:유가증권 2:코스닥 3:프리보드 7:채권
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// 종목코드, 표준코드
	out->ordbl_qty = Str2Dbl(data->ordbl_qty, sizeof(data->ordbl_qty), 0);	// 주문가능수량, 단위:주(양수만 존재)
	memcpy(out->data_type, data->data_type, sizeof(data->data_type));	// 데이터종류, 01:주문가능수량(실시간) 07:잠정치주문가능수량(종가)

	return 1;
}


// 프리보드 외국인 예비주문지정_해지
int ParseF3013(const double& timestamp, const char* in_buff, DF_FBRD_FRGN_RSVD_ORD_CNCL* out) {
	FBRD_FRGN_RSVD_ORD_CNCL* data = (FBRD_FRGN_RSVD_ORD_CNCL*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA구분, F3
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// 정보구분, 01:주식
	out->mkt_clsf = data->mkt_clsf[0];	//시장구분, 1:유가증권 2:코스닥 3:프리보드
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// 종목코드, 표준코드
	memcpy(out->data_type, data->data_type, sizeof(data->data_type));	// 데이터종류, 01:예비주문지정 02:예비주문해지
	out->proc_clsf = data->proc_clsf[0];	//처리구분, 1:정상 2:취소
	memcpy(out->rsvd_ord_date, data->rsvd_ord_date, sizeof(data->rsvd_ord_date));	// 예비주문일자, YYYYMMDD
	memcpy(out->rsvd_ord_st_time, data->rsvd_ord_st_time, sizeof(data->rsvd_ord_st_time));	// 예비주문시작시간, HHMM
	memcpy(out->rsvd_ord_ed_time, data->rsvd_ord_ed_time, sizeof(data->rsvd_ord_ed_time));	// 예비주문종료시간, HHMM

	return 1;
}


// 프리본드 외국인 확정치데이터재전송
int ParseF4013(const double& timestamp, const char* in_buff, DF_FBRD_FRGN_CFRM_DATA* out) {
	FBRD_FRGN_CFRM_DATA* data = (FBRD_FRGN_CFRM_DATA*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA구분, F4
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// 정보구분, 01:주식 90:기타
	out->mkt_clsf = data->mkt_clsf[0];	//시장구분, 1:유가증권 2:코스닥 3:프리보드 7:채권
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// 종목코드, 표준코드
	out->stk_lim_ratio = Str2Dbl(data->stk_lim_ratio, sizeof(data->stk_lim_ratio), 4);	// 종목한도비율, 9V9999 (예:15%일때 → 01500으로 전송)
	out->psn_lim_ratio = Str2Dbl(data->psn_lim_ratio, sizeof(data->psn_lim_ratio), 4);	// 개인한도비율, 9V9999 (예:15%일때 → 01500으로 전송)
	out->stk_lstd = Str2Dbl(data->stk_lstd, sizeof(data->stk_lstd), 0);	// 상장주식수, 단위:주
	out->ordbl_qty = Str2Dbl(data->ordbl_qty, sizeof(data->ordbl_qty), 0);	// 주문가능수량, 단위:주
	out->lim_xhs_clsf = data->lim_xhs_clsf[0];	//한도소진구분, 0:정상 1:한도초과 2:추가 3:삭제

	return 1;
}


// 프리보드 외국인 한도소진장외매매
int ParseF5013(const double& timestamp, const char* in_buff, DF_FBRD_FRGN_LMT_XHS* out) {
	FBRD_FRGN_LMT_XHS* data = (FBRD_FRGN_LMT_XHS*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA구분, F5
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// 정보구분, 01:주식
	out->mkt_clsf = data->mkt_clsf[0];	//시장구분, 1:유가증권 2:코스닥 3:프리보드
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// 종목코드, 표준코드
	out->clsf = data->clsf[0];	//구분, 1:단가입력 2:단가취소
	out->qty = Str2Int(data->qty, sizeof(data->qty));	// 수량, 단위:주
	out->prc = Str2Int(data->prc, sizeof(data->prc));	// 가격, 단위:원
	memcpy(out->proc_time, data->proc_time, sizeof(data->proc_time));	// 처리시간, HHMMSSMM

	return 1;
}


// ELW 투자지표민감도
int ParseC7021(const double& timestamp, const char* in_buff, DF_ELW_INV_IDX_SST* out) {
	ELW_INV_IDX_SST* data = (ELW_INV_IDX_SST*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA구분, C7
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// 정보구분, 02:ELW
	out->mkt_clsf = data->mkt_clsf[0];	//시장구분, 1:유가증권
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// 종목코드, 표준코드
	memcpy(out->calc_time, data->calc_time, sizeof(data->calc_time));	// 산출시간, 장중:HHMMSS(시간:분:초) 090000 ~ 장종료:JUNJJJ
	out->std_thr_val = Str2Dbl(data->std_thr_val, sizeof(data->std_thr_val), 2);	// 표준이론가, 9(8)9V9(2) 명칭변경 2010.06.14
	out->sst_delta = Str2SignDouble(data->sst_delta_sign, sizeof(data->sst_delta_sign) + sizeof(data->sst_delta), 6);	// 민감도 - 델타, 9V9(6)
	out->sst_gamma = Str2SignDouble(data->sst_gamma_sign, sizeof(data->sst_gamma_sign) + sizeof(data->sst_gamma), 6);	// 민감도 - 감마, 9V9(6)
	out->sst_theta = Str2SignDouble(data->sst_theta_sign, sizeof(data->sst_theta_sign) + sizeof(data->sst_theta), 6);	// 민감도 - 세타, 9(6)V9(6)
	out->sst_vega = Str2SignDouble(data->sst_vega_sign, sizeof(data->sst_vega_sign) + sizeof(data->sst_vega), 6);	// 민감도 - 베가, 9(6)V9(6)
	out->sst_ro = Str2SignDouble(data->sst_ro_sign, sizeof(data->sst_ro_sign) + sizeof(data->sst_ro), 6);	// 민감도 - 로, 9(6)V9(6)
	out->itnl_vol = Str2Dbl(data->itnl_vol, sizeof(data->itnl_vol), 2);	// 내재변동성, 9(3)V9(2) 조기종료ELW의 경우 0 (2010.08.30)
	out->tot_cost = Str2Dbl(data->tot_cost, sizeof(data->tot_cost), 2);	// 제반비용, 9(8)V9(2) 표준ELW의 경우 0 (2010.08.30)

	return 1;
}


// 코스피_자사주 배치정보
int ParseA9011(const double& timestamp, const char* in_buff, DF_KOSPI_TRS_STK_ARNG_INFO* out) {
	KOSPI_TRS_STK_ARNG_INFO* data = (KOSPI_TRS_STK_ARNG_INFO*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA구분, A9
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// 정보구분, 01:주식
	out->mkt_clsf = data->mkt_clsf[0];	//시장구분, 1:유가증권 2:코스닥
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// 종목코드, 표준코드
	out->snr = Str2Int(data->snr, sizeof(data->snr));	// 일련번호, 1~99999999 건수체크용
	memcpy(out->trs_stk_id, data->trs_stk_id, sizeof(data->trs_stk_id));	// 자사주신고서ID, 0:해당없음 N:자사주직접일반 S:자사주직접스톡옵션\n1~99999:자사주신탁일련번호 ※값 좌측정렬
	out->ask_bid_clsf_code = data->ask_bid_clsf_code[0];	//매도매수구분코드, 0:신탁 1:매도 2:매수
	memcpy(out->trs_stk_date, data->trs_stk_date, sizeof(data->trs_stk_date));	// 자사주신청일자, YYYYMMDD ※신고서의 경우 신청일자가 없음
	memcpy(out->trs_stk_st_date, data->trs_stk_st_date, sizeof(data->trs_stk_st_date));	// 자사주신고개시일자, YYYYMMDD 신고서상의 자사주매매 개시일자
	memcpy(out->trs_stk_ed_date, data->trs_stk_ed_date, sizeof(data->trs_stk_ed_date));	// 자사주신고종료일자, YYYYMMDD 신고서상의 자사주매매 종료일자
	out->trs_stk_trd_code = data->trs_stk_trd_code[0];	//자사주매매방법코드, 0:해당없음 1:자사주일반 2:한은등 자사주 3:정부등 자사주\n※2,3 : 장종료후시간외대량매수만 가능, 당일거래(매매거래의\n 종류)관련 사용\n →일반자사주는 시간외대량 매수불가(매도만 가능)\n※3 : 장종료후시간외대량매수시 상/하한가 제한없음
	out->trs_stk_ptcp_nr = Str2Int(data->trs_stk_ptcp_nr, sizeof(data->trs_stk_ptcp_nr));	// 자사주신청시장참가자 번호, 회원번호 예) '00001'
	out->open_trs_stk_qty = Str2Dbl(data->open_trs_stk_qty, sizeof(data->open_trs_stk_qty), 0);	// 시가단일가자사주신청 수량, 신고기간중의 신청일 시가단일가 신청 수량
	out->opr_time_trs_stk_qty = Str2Dbl(data->opr_time_trs_stk_qty, sizeof(data->opr_time_trs_stk_qty), 0);	// 장중자사주신청수량, 신고기간중의 신청일 접속 신청 수량
	out->ofhr_msv_trs_stk_qty = Str2Dbl(data->ofhr_msv_trs_stk_qty, sizeof(data->ofhr_msv_trs_stk_qty), 0);	// 시간외대량자사주 신청수량, 시간외(오전, 오후)시장의 자사주 신고수량
	out->trs_stk_cum_ccls_qty = Str2Dbl(data->trs_stk_cum_ccls_qty, sizeof(data->trs_stk_cum_ccls_qty), 0);	// 자사주누적체결수량, 신고기간중의 정규장, 시간외시장에서 자사주 체결수량 누적
	out->trs_stk_cum_trd_val = Str2Dbl(data->trs_stk_cum_trd_val, sizeof(data->trs_stk_cum_trd_val), 0);	// 자사주누적거래대금, 신고기간중의 정규장, 시간외시장에서 자사주 거래대금 누적

	return 1;
}


// 코스피_자사주 매매정보
int ParseB0011(const double& timestamp, const char* in_buff, DF_KOSPI_TRS_STK_TRD_INFO* out) {
	KOSPI_TRS_STK_TRD_INFO* data = (KOSPI_TRS_STK_TRD_INFO*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA구분, B0
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// 정보구분, 01:주식
	out->mkt_clsf = data->mkt_clsf[0];	//시장구분, 1:유가증권 2:코스닥
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// 종목코드, 표준코드
	out->snr = Str2Int(data->snr, sizeof(data->snr));	// 일련번호, 1~99999999 종목일련번호 2014.03.03
	out->ccls_prc = Str2Int(data->ccls_prc, sizeof(data->ccls_prc));	// 체결가격, 단위:원
	out->ccls_qty = Str2Dbl(data->ccls_qty, sizeof(data->ccls_qty), 0);	// 체결수량, 단위:주
	memcpy(out->sess_id, data->sess_id, sizeof(data->sess_id));	// 세션ID, 코드값모음 참조
	memcpy(out->bid_trs_stk_id, data->bid_trs_stk_id, sizeof(data->bid_trs_stk_id));	// 매수자사주신고서ID, 0:해당없음 N:자사주직접일반 S:자사주직접스탁옵션\n1~99999:자사주신탁(신고서일련번호)\n※값은 왼쪽정렬 예) "N", "1"\n※자사주신탁일련번호는 종목별로 영구적으로 누적 채번됨\n 직접에 반해 신탁에 일련번호가 존재하는 이유는 동일\n 종목에 대해서 여러 신탁회사에서 자사주를 신고할 수\n 있도록 허용하기 위함임
	memcpy(out->ask_trs_stk_id, data->ask_trs_stk_id, sizeof(data->ask_trs_stk_id));	// 매도자사주신고서ID, 매수자사주신고서ID와 동일

	return 1;
}


// 레버리지 KOSPI200지수
int ParseK2011(const double& timestamp, const char* in_buff, DF_LVR_KOSPI200_IDX* out) {
	LVR_KOSPI200_IDX* data = (LVR_KOSPI200_IDX*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA구분, ※개발가이드 참조
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// 정보구분, 01:주식
	out->mkt_clsf = data->mkt_clsf[0];	//시장구분, 1:유가증권 2:코스닥
	memcpy(out->ind_code, data->ind_code, sizeof(data->ind_code));	// 업종코드, ※개발가이드 참조
	memcpy(out->time, data->time, sizeof(data->time));	// 시간, ※개발가이드 참조
	out->idx = Str2Dbl(data->idx, sizeof(data->idx), 2);	// 지수, 9(6)V9(2)
	out->ctrs = Str2SignDouble(data->sign, sizeof(data->sign) + sizeof(data->ctrs), 2);	// 대비, 999999V99
	out->ccls_qty = Str2Int(data->ccls_qty, sizeof(data->ccls_qty));	// 체결수량, 단위:천주
	out->trd_val = Str2Int(data->trd_val, sizeof(data->trd_val));	// 거래대금, 단위:백만원

	return 1;
}


// 코스피_회원제재해제공개
int ParseR3011(const double& timestamp, const char* in_buff, DF_KOSPI_MBR_SCT_CNCL_DCLS* out) {
	KOSPI_MBR_SCT_CNCL_DCLS* data = (KOSPI_MBR_SCT_CNCL_DCLS*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA구분, R3
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// 정보구분, 01:주식
	out->mkt_clsf = data->mkt_clsf[0];	//시장구분, 1:유가증권 2:코스닥
	memcpy(out->ind_code, data->ind_code, sizeof(data->ind_code));	// 종목코드, **: 전종목해당
	out->stk_snr = Str2Int(data->stk_snr, sizeof(data->stk_snr));	// 종목일련번호, 종목배치(A0)의 종목일련번호
	memcpy(out->open_info_clsf_code, data->open_info_clsf_code, sizeof(data->open_info_clsf_code));	// 공개정보구분코드, 코드값모음 참조
	memcpy(out->open_time, data->open_time, sizeof(data->open_time));	// 공개시각
	memcpy(out->mbr_nr, data->mbr_nr, sizeof(data->mbr_nr));	// 회원번호
	out->mbr_sct_rng_code = Str2Int(data->mbr_sct_rng_code, sizeof(data->mbr_sct_rng_code));	// 회원제재범위코드, 회원의 거래를 허용 또는 제재하는 범위. Bitwise 정의\n 1: 매도(풋매수) 위탁\n 2: 매도(풋매수) 자기\n 4: 매수(풋매도) 위탁\n 8: 매수(풋매도) 자기

	return 1;
}


// 코스피_종목상태정보(VI)
int ParseR8011(const double& timestamp, const char* in_buff, DF_KOSPI_STK_STAT_INFO* out) {
	KOSPI_STK_STAT_INFO* data = (KOSPI_STK_STAT_INFO*)in_buff;

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
	memcpy(out->stt_vi_dspr, data->stt_vi_dspr, sizeof(data->stt_vi_dspr));	// 정적VI발동가격괴리율, 정적VI발동 괴리율\n부호자리(양수:0, 음수:-) + 99999.999999(유효숫자 12자리)
	memcpy(out->dyn_vi_dspr, data->dyn_vi_dspr, sizeof(data->dyn_vi_dspr));	// 동적VI발동가격괴리율, 동적VI발동 괴리율\n부호자리(양수:0, 음수:-) + 99999.999999(유효숫자 12자리)

	return 1;
}


// ETN 사무수탁정보
int ParseS1011(const double& timestamp, const char* in_buff, DF_ETN_TRA_INFO* out) {
	ETN_TRA_INFO* data = (ETN_TRA_INFO*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA구분, S1
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// 정보구분, 01:주식
	out->mkt_clsf = data->mkt_clsf[0];	//시장구분, 1:유가증권
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// 종목코드, 표준코드
	out->snr = Str2Int(data->snr, sizeof(data->snr));	// 일련번호, 1~99999999 건수체크용
	out->fin_idx_val = Str2Dbl(data->fin_idx_val, sizeof(data->fin_idx_val), 2);	// 최종지표가치, 9999999V99 직전영업일자의 최종 IV,단위:원
	out->idx_val = Str2Dbl(data->idx_val, sizeof(data->idx_val), 0);	// 지표가치금액
	out->prev_base_prc = Str2Dbl(data->prev_base_prc, sizeof(data->prev_base_prc), 2);	// 전일과표기준가격, 9999999V99
	out->prev_bdiv_base_prc = Str2Dbl(data->prev_bdiv_base_prc, sizeof(data->prev_bdiv_base_prc), 2);	// 전일배당전과표기준가격, 9999999V99
	out->prev_cash_div_val = Str2Dbl(data->prev_cash_div_val, sizeof(data->prev_cash_div_val), 2);	// 전일현금배당금액, 9999999999V99
	out->pprev_base_prc = Str2Dbl(data->pprev_base_prc, sizeof(data->pprev_base_prc), 2);	// 전전일가격과표기준가격, 9999999V99
	out->vol_fut_clsf = Str2Int(data->vol_fut_clsf, sizeof(data->vol_fut_clsf));	// 변동성선물구분, 0:변동성선물ETN 1:기타
	out->ely_rdmp_min_qty = Str2Dbl(data->ely_rdmp_min_qty, sizeof(data->ely_rdmp_min_qty), 0);	// 중도상환청구최소수량, 단위:증권
	out->ely_rdmp_fee_rate = Str2Dbl(data->ely_rdmp_fee_rate, sizeof(data->ely_rdmp_fee_rate), 8);	// 중도상환수수료율, 99V99999999 단위:%
	out->tot_cost = Str2Dbl(data->tot_cost, sizeof(data->tot_cost), 2);	// 제비용, 9999999V99 단위:원

	return 1;
}


// ETN 기초지수 구성종목
int ParseS2011(const double& timestamp, const char* in_buff, DF_ETN_BASE_IDX_COMP_STK* out) {
	ETN_BASE_IDX_COMP_STK* data = (ETN_BASE_IDX_COMP_STK*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA구분, S2
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// 정보구분, 01:주식
	out->mkt_clsf = data->mkt_clsf[0];	//시장구분, 1:유가증권
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// ETN 종목코드, 표준코드(ETN코드)
	out->data_snr = Str2Int(data->data_snr, sizeof(data->data_snr));	// 데이터 일련번호, 1~99999999 전송일련번호,건수체크용
	out->date = Str2Int(data->date, sizeof(data->date));	// 일자, YYYYMMDD
	out->trb_nr = Str2Int(data->trb_nr, sizeof(data->trb_nr));	// 사무수탁회사번호, 사무수탁회사번호
	out->comp_stk_nr = Str2Int(data->comp_stk_nr, sizeof(data->comp_stk_nr));	// 구성종목수, 단위:종목(현금포함)
	memcpy(out->comp_stk_code, data->comp_stk_code, sizeof(data->comp_stk_code));	// 구성종목코드, 표준코드\n해외종목일 경우 '0' 또는 SPACE로 Setting될 수 있음
	memcpy(out->comp_stk_nm, data->comp_stk_nm, sizeof(data->comp_stk_nm));	// 구성종목명, 종목명
	out->comp_rate = Str2Dbl(data->comp_rate, sizeof(data->comp_rate), 2);	// 구성비, 지수내 구성비\n99999V99 단위:%

	return 1;
}


// ETN_투자자별
int ParseC0041(const double& timestamp, const char* in_buff, DF_ETN_BYINV* out) {
	ETN_BYINV* data = (ETN_BYINV*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA구분, C0
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// 정보구분, 01:주식, 02:ELW, 03:ETF, 04:ETN
	out->mkt_clsf = data->mkt_clsf[0];	//시장구분, 1:유가증권 2:코스닥
	memcpy(out->cmpt_time, data->cmpt_time, sizeof(data->cmpt_time));	// 산출시각, 90초 주기
	memcpy(out->inv_code, data->inv_code, sizeof(data->inv_code));	// 투자자코드, ※코드값모음 참조\n*코드'7000'시 수량, 대금정보 항목 0으로 전송 (20181210)
	memcpy(out->ind_code, data->ind_code, sizeof(data->ind_code));	// 업종코드, 0
	out->ask_ccls_qty = Str2Dbl(data->ask_ccls_qty, sizeof(data->ask_ccls_qty), 0);	// 매도체결수량, 단위:주
	out->ask_trd_val = Str2Dbl(data->ask_trd_val, sizeof(data->ask_trd_val), 0);	// 매도거래대금, 단위:원
	out->bid_ccls_qty = Str2Dbl(data->bid_ccls_qty, sizeof(data->bid_ccls_qty), 0);	// 매수체결수량, 단위:주
	out->bid_trd_val = Str2Dbl(data->bid_trd_val, sizeof(data->bid_trd_val), 0);	// 매수거래대금, 단위:원

	return 1;
}


// ETN IIV
int ParseS3011(const double& timestamp, const char* in_buff, DF_ETN_IIV* out) {
	ETN_IIV* data = (ETN_IIV*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA구분, S3
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// 정보구분, 01:주식
	out->mkt_clsf = data->mkt_clsf[0];	//시장구분, 1:유가증권
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// ETN 종목코드, ETN 종목코드
	memcpy(out->time, data->time, sizeof(data->time));	// 시간, HHMMSS:장중 JUNJJJ:장마감
	out->prev_iv = Str2Dbl(data->prev_iv, sizeof(data->prev_iv), 2);	// 전일 IV, 9(7)V9(2)
	out->opr_time_fin_iv = Str2Dbl(data->opr_time_fin_iv, sizeof(data->opr_time_fin_iv), 2);	// 장중/최종 IV, 9(7)V9(2)

	return 1;
}


// ETN 종목배치
int ParseA1041(const double& timestamp, const char* in_buff, DF_ETN_STK_ARNG* out) {
	ETN_STK_ARNG* data = (ETN_STK_ARNG*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA구분, A1
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// 정보구분, 04:ETN
	out->mkt_clsf = data->mkt_clsf[0];	//시장구분, 1:유가증권
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// 종목코드, 표준코드
	out->snr = Str2Int(data->snr, sizeof(data->snr));	// 일련번호, 1~99999999 건수체크용
	memcpy(out->etn_ptcp_kor_nm, data->etn_ptcp_kor_nm, sizeof(data->etn_ptcp_kor_nm));	// ETN발행시장참가자한글명
	memcpy(out->etn_ptcp_eng_nm, data->etn_ptcp_eng_nm, sizeof(data->etn_ptcp_eng_nm));	// ETN발행시장참가자영문명
	memcpy(out->etn_ptcp_nr, data->etn_ptcp_nr, sizeof(data->etn_ptcp_nr));	// ETN발행시장참가자번호, ETN발행회원사의 번호(상장사, 비상장사 구분없음)\n예) ‘00001’
	out->etn_fin_pymt_code = data->etn_fin_pymt_code[0];	//ETN최종결제방법코드, A:현금+실물인수도결제 C:현금결제 D:실물인수도결제
	memcpy(out->etn_fin_trd_date, data->etn_fin_trd_date, sizeof(data->etn_fin_trd_date));	// ETN최종거래일자, YYYYMMDD
	memcpy(out->etn_pymt_date, data->etn_pymt_date, sizeof(data->etn_pymt_date));	// ETN지급일자, YYYYMMDD
	out->etn_lp_hld_qty = Str2Dbl(data->etn_lp_hld_qty, sizeof(data->etn_lp_hld_qty), 0);	// ETN LP보유수량
	memcpy(out->loss_cut_etn_profit_strt_code, data->loss_cut_etn_profit_strt_code, sizeof(data->loss_cut_etn_profit_strt_code));	// 손실제한ETN수익구조코드, 손실제한ETN수익구조코드\n▦▦코드값▦▦\n 01: 콜\n 02: 풋\n 03: 콜스프레드\n 04: 풋스프레드\n 05: 조기상환 콜스프레드\n 06: 조기상환 낙아웃콜\n 07: 레인지 어쿠루얼\n 08: 버터플라이\n 09: 콘도르\n 10: 조기상환 풋스프레드\n 11: 조기상환 낙아웃풋\n(2017.03.27 항목추가)
	out->etn_max_rdm_prc = Str2Dbl(data->etn_max_rdm_prc, sizeof(data->etn_max_rdm_prc), 3);	// ETN최대상환가격, ETN에서 사용되는 제비용 차감전 최대 상환가격 \n9(9)V9(3)\n(2017.03.27 항목추가)
	out->etn_min_rdm_prc = Str2Dbl(data->etn_min_rdm_prc, sizeof(data->etn_min_rdm_prc), 3);	// ETN최소상환가격, ETN에서 사용되는 제비용 차감전 최소 상환가격\n9(9)V9(3)\n(2017.03.27 항목추가)
	out->etn_ely_rdm_flg = data->etn_ely_rdm_flg[0];	//ETN조기상환가능여부, 손실제한 ETN의 조기상환 조건 가능 여부\n(2017.03.27 항목추가)
	memcpy(out->etn_ely_rdm_frq_code, data->etn_ely_rdm_frq_code, sizeof(data->etn_ely_rdm_frq_code));	// ETN조기상환주기코드, 손실제한 ETN의 조기상환 주기 구분\nETN조기상환가능여부가 Y일때만 선택가능\n▦▦코드값▦▦\n01: 수시(매일)\n02: 매 3개월\n03: 매 4개월\n04: 매 6개월\n05: 매 1년 (사양서에는 없음)\n06: 3개월부터 매 1개월 (사양서에는 없음)\n07: 6개월부터 매 1개월 (사양서에는 없음)\n(2017.03.27 항목추가)
	memcpy(out->assm_prc_cmpt_inst_code1, data->assm_prc_cmpt_inst_code1, sizeof(data->assm_prc_cmpt_inst_code1));	// 평가가격산출기관코드1, ETN의 평가가격을 산출하는 기관코드 1\n▦▦코드값▦▦\n01:한국자산평가\n02:NICE P&I\n03:KIS채권평가\n04:Fn자산평가\n(2017.03.27 항목추가)
	memcpy(out->assm_prc_cmpt_inst_code2, data->assm_prc_cmpt_inst_code2, sizeof(data->assm_prc_cmpt_inst_code2));	// 평가가격산출기관코드2, ETN의 평가가격을 산출하는 기관코드 2\n▦▦코드값▦▦\n01:한국자산평가\n02:NICE P&I\n03:KIS채권평가\n04:Fn자산평가\n(2017.03.27 항목추가)

	return 1;
}


// KTOP30지수
int ParseT7011(const double& timestamp, const char* in_buff, DF_KTOP30_IDX* out) {
	KTOP30_IDX* data = (KTOP30_IDX*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA구분, ※개발가이드 참조
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// 정보구분, 01:주식
	out->mkt_clsf = data->mkt_clsf[0];	//시장구분, 1:유가증권 2:코스닥 9:해외주가지수
	memcpy(out->ind_clsf, data->ind_clsf, sizeof(data->ind_clsf));	// 업종코드, ※개발가이드 참조
	memcpy(out->time, data->time, sizeof(data->time));	// 시간
	out->idx = Str2Dbl(data->idx, sizeof(data->idx), 2);	// 지수, 9(6)V9(2)
	out->crst = Str2SignDouble(data->sign, sizeof(data->sign) + sizeof(data->crst), 2);	// 대비, 999999.99
	out->ccls_qty = Str2Int(data->ccls_qty, sizeof(data->ccls_qty));	// 체결수량, 단위:천주 ※해외주가지수일 경우 FILLER처리
	out->trd_val = Str2Int(data->trd_val, sizeof(data->trd_val));	// 거래대금, 단위:백만원 ※해외주가지수일 경우 FILLER처리

	return 1;
}


// KTOP30예상지수
int ParseT8011(const double& timestamp, const char* in_buff, DF_KTOP30_EXP_IDX* out) {
	KTOP30_EXP_IDX* data = (KTOP30_EXP_IDX*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA구분, ※개발가이드 참조
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// 정보구분, 01:주식
	out->mkt_clsf = data->mkt_clsf[0];	//시장구분, 1:유가증권 2:코스닥 9:해외주가지수
	memcpy(out->ind_clsf, data->ind_clsf, sizeof(data->ind_clsf));	// 업종코드, ※개발가이드 참조
	memcpy(out->time, data->time, sizeof(data->time));	// 시간
	out->idx = Str2Dbl(data->idx, sizeof(data->idx), 2);	// 지수, 9(6)V9(2)
	out->crst = Str2SignDouble(data->sign, sizeof(data->sign) + sizeof(data->crst), 2);	// 대비, 999999.99
	out->ccls_qty = Str2Int(data->ccls_qty, sizeof(data->ccls_qty));	// 체결수량, 단위:천주 ※해외주가지수일 경우 FILLER처리
	out->trd_val = Str2Int(data->trd_val, sizeof(data->trd_val));	// 거래대금, 단위:백만원 ※해외주가지수일 경우 FILLER처리

	return 1;
}
