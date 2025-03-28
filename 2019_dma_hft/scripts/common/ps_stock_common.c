// ps_stock_common.c
// 주식 공통
// 주석에 \n이 들어간건 나중에 이쁘게 바꿔야함

#include "ps_stock_common.h"


extern int     Str2Int(char *str, int size);
extern double  Str2Dbl(char *str, int size, int point);
extern double  Str2SignDouble(char *str, int size, int point);


// 현물 Polling data
int ParseI2000(const double& timestamp, const char* in_buff, DF_CUR_POLLING_DATA* out) {
	CUR_POLLING_DATA* data = (CUR_POLLING_DATA*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA구분, I2
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// 정보구분, 00:초기값
	out->mkt_clsf = data->mkt_clsf[0];	//시장구분, 0:초기값
	memcpy(out->time, data->time, sizeof(data->time));	// 시간, HHMM

	return 1;
}


// 공시(실시간_코스피_주식)
int ParseF0011(const double& timestamp, const char* in_buff, DF_DCLS_RT_KOSPI_STK* out) {
	DCLS_RT_KOSPI_STK* data = (DCLS_RT_KOSPI_STK*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA구분, E9:공시배치 F0:공시실시간
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// 정보구분, 01:주식 90:기타
	out->mkt_clsf = data->mkt_clsf[0];	//시장구분, 1:유가증권 2:코스닥 8:코넥스 9:기타
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// 종목코드, ※개발가이드 주1
	out->dcls_snr = Str2Int(data->dcls_snr, sizeof(data->dcls_snr));	// 공시일련번호, 년단위 ※개발가이드 주2
	out->dcls_pgnr = Str2Int(data->dcls_pgnr, sizeof(data->dcls_pgnr));	// 공시건당 총 페이지수
	out->dcls_pg_snr = Str2Int(data->dcls_pg_snr, sizeof(data->dcls_pg_snr));	// 공시건당 페이지 일련번호
	memcpy(out->dcls_date, data->dcls_date, sizeof(data->dcls_date));	// 공시일자, YYYYMMDD
	memcpy(out->trsm_date, data->trsm_date, sizeof(data->trsm_date));	// 전송일자, YYYYMMDD
	out->dcls_mkt_clsf = data->dcls_mkt_clsf[0];	//공시용시장구분, 1:유가증권 2:코스닥 3:파생상품 4:채권 5:시장감시 6:코넥스 ※개발가이드 주3
	memcpy(out->stk_nm, data->stk_nm, sizeof(data->stk_nm));	// 종목명
	out->proc_clsf = data->proc_clsf[0];	//처리구분, 1:정상 2:수정 3:삭제
	memcpy(out->rsn, data->rsn, sizeof(data->rsn));	// 사유, ※개발가이드 주4
	out->kor_eng_clsf = data->kor_eng_clsf[0];	//국문영문구분, 1:국문 2:영문
	memcpy(out->dcls_title, data->dcls_title, sizeof(data->dcls_title));	// 공시제목, TEXT 형식
	memcpy(out->dcls_cntt, data->dcls_cntt, sizeof(data->dcls_cntt));	// 공시내용, HTML 형식
	out->stk_xst_flg = data->stk_xst_flg[0];	//종목존재여부, Y:종목코드존재 N:해당없음 ※공시전체대상 ※개발가이드 주5
	out->dcls_isin_code_flg = data->dcls_isin_code_flg[0];	//공시내용 종목코드여부, Y:종목코드 N:공시내용 ※공시페이지단위 ※개발가이드 주5
	out->nr_isin_code = Str2Int(data->nr_isin_code, sizeof(data->nr_isin_code));	// 종목코드갯수, 12자리 종목코드 개수 ※공시페이지단위 ※개발가이드 주5

	return 1;
}


// 공시(실시간_코스닥_주식)
int ParseF0012(const double& timestamp, const char* in_buff, DF_DCLS_RT_KOSDAQ_STK* out) {
	DCLS_RT_KOSDAQ_STK* data = (DCLS_RT_KOSDAQ_STK*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA구분, E9:공시배치 F0:공시실시간
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// 정보구분, 01:주식 90:기타
	out->mkt_clsf = data->mkt_clsf[0];	//시장구분, 1:유가증권 2:코스닥 8:코넥스 9:기타
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// 종목코드, ※개발가이드 주1
	out->dcls_snr = Str2Int(data->dcls_snr, sizeof(data->dcls_snr));	// 공시일련번호, 년단위 ※개발가이드 주2
	out->dcls_pgnr = Str2Int(data->dcls_pgnr, sizeof(data->dcls_pgnr));	// 공시건당 총 페이지수
	out->dcls_pg_snr = Str2Int(data->dcls_pg_snr, sizeof(data->dcls_pg_snr));	// 공시건당 페이지 일련번호
	memcpy(out->dcls_date, data->dcls_date, sizeof(data->dcls_date));	// 공시일자, YYYYMMDD
	memcpy(out->trsm_date, data->trsm_date, sizeof(data->trsm_date));	// 전송일자, YYYYMMDD
	out->dcls_mkt_clsf = data->dcls_mkt_clsf[0];	//공시용시장구분, 1:유가증권 2:코스닥 3:파생상품 4:채권 5:시장감시 6:코넥스 ※개발가이드 주3
	memcpy(out->stk_nm, data->stk_nm, sizeof(data->stk_nm));	// 종목명
	out->proc_clsf = data->proc_clsf[0];	//처리구분, 1:정상 2:수정 3:삭제
	memcpy(out->rsn, data->rsn, sizeof(data->rsn));	// 사유, ※개발가이드 주4
	out->kor_eng_clsf = data->kor_eng_clsf[0];	//국문영문구분, 1:국문 2:영문
	memcpy(out->dcls_title, data->dcls_title, sizeof(data->dcls_title));	// 공시제목, TEXT 형식
	memcpy(out->dcls_cntt, data->dcls_cntt, sizeof(data->dcls_cntt));	// 공시내용, HTML 형식
	out->stk_xst_flg = data->stk_xst_flg[0];	//종목존재여부, Y:종목코드존재 N:해당없음 ※공시전체대상 ※개발가이드 주5
	out->dcls_isin_code_flg = data->dcls_isin_code_flg[0];	//공시내용 종목코드여부, Y:종목코드 N:공시내용 ※공시페이지단위 ※개발가이드 주5
	out->nr_isin_code = Str2Int(data->nr_isin_code, sizeof(data->nr_isin_code));	// 종목코드갯수, 12자리 종목코드 개수 ※공시페이지단위 ※개발가이드 주5

	return 1;
}


// 공시(실시간_코넥스_주식)
int ParseF0018(const double& timestamp, const char* in_buff, DF_DCLS_RT_KONEX_STK* out) {
	DCLS_RT_KONEX_STK* data = (DCLS_RT_KONEX_STK*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA구분, E9:공시배치 F0:공시실시간
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// 정보구분, 01:주식 90:기타
	out->mkt_clsf = data->mkt_clsf[0];	//시장구분, 1:유가증권 2:코스닥 8:코넥스 9:기타
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// 종목코드, ※개발가이드 주1
	out->dcls_snr = Str2Int(data->dcls_snr, sizeof(data->dcls_snr));	// 공시일련번호, 년단위 ※개발가이드 주2
	out->dcls_pgnr = Str2Int(data->dcls_pgnr, sizeof(data->dcls_pgnr));	// 공시건당 총 페이지수
	out->dcls_pg_snr = Str2Int(data->dcls_pg_snr, sizeof(data->dcls_pg_snr));	// 공시건당 페이지 일련번호
	memcpy(out->dcls_date, data->dcls_date, sizeof(data->dcls_date));	// 공시일자, YYYYMMDD
	memcpy(out->trsm_date, data->trsm_date, sizeof(data->trsm_date));	// 전송일자, YYYYMMDD
	out->dcls_mkt_clsf = data->dcls_mkt_clsf[0];	//공시용시장구분, 1:유가증권 2:코스닥 3:파생상품 4:채권 5:시장감시 6:코넥스 ※개발가이드 주3
	memcpy(out->stk_nm, data->stk_nm, sizeof(data->stk_nm));	// 종목명
	out->proc_clsf = data->proc_clsf[0];	//처리구분, 1:정상 2:수정 3:삭제
	memcpy(out->rsn, data->rsn, sizeof(data->rsn));	// 사유, ※개발가이드 주4
	out->kor_eng_clsf = data->kor_eng_clsf[0];	//국문영문구분, 1:국문 2:영문
	memcpy(out->dcls_title, data->dcls_title, sizeof(data->dcls_title));	// 공시제목, TEXT 형식
	memcpy(out->dcls_cntt, data->dcls_cntt, sizeof(data->dcls_cntt));	// 공시내용, HTML 형식
	out->stk_xst_flg = data->stk_xst_flg[0];	//종목존재여부, Y:종목코드존재 N:해당없음 ※공시전체대상 ※개발가이드 주5
	out->dcls_isin_code_flg = data->dcls_isin_code_flg[0];	//공시내용 종목코드여부, Y:종목코드 N:공시내용 ※공시페이지단위 ※개발가이드 주5
	out->nr_isin_code = Str2Int(data->nr_isin_code, sizeof(data->nr_isin_code));	// 종목코드갯수, 12자리 종목코드 개수 ※공시페이지단위 ※개발가이드 주5

	return 1;
}


// 공시(배치_코스피_주식)
int ParseE9011(const double& timestamp, const char* in_buff, DF_DCLS_ARNG_KOSPI_STK* out) {
	DCLS_ARNG_KOSPI_STK* data = (DCLS_ARNG_KOSPI_STK*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA구분, E9:공시배치 F0:공시실시간
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// 정보구분, 01:주식 90:기타
	out->mkt_clsf = data->mkt_clsf[0];	//시장구분, 1:유가증권 2:코스닥 8:코넥스 9:기타
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// 종목코드, ※개발가이드 주1
	out->dcls_snr = Str2Int(data->dcls_snr, sizeof(data->dcls_snr));	// 공시일련번호, 년단위 ※개발가이드 주2
	out->dcls_pgnr = Str2Int(data->dcls_pgnr, sizeof(data->dcls_pgnr));	// 공시건당 총 페이지수
	out->dcls_pg_snr = Str2Int(data->dcls_pg_snr, sizeof(data->dcls_pg_snr));	// 공시건당 페이지 일련번호
	memcpy(out->dcls_date, data->dcls_date, sizeof(data->dcls_date));	// 공시일자, YYYYMMDD
	memcpy(out->trsm_date, data->trsm_date, sizeof(data->trsm_date));	// 전송일자, YYYYMMDD
	out->dcls_mkt_clsf = data->dcls_mkt_clsf[0];	//공시용시장구분, 1:유가증권 2:코스닥 3:파생상품 4:채권 5:시장감시 6:코넥스 ※개발가이드 주3
	memcpy(out->stk_nm, data->stk_nm, sizeof(data->stk_nm));	// 종목명
	out->proc_clsf = data->proc_clsf[0];	//처리구분, 1:정상 2:수정 3:삭제
	memcpy(out->rsn, data->rsn, sizeof(data->rsn));	// 사유, ※개발가이드 주4
	out->kor_eng_clsf = data->kor_eng_clsf[0];	//국문영문구분, 1:국문 2:영문
	memcpy(out->dcls_title, data->dcls_title, sizeof(data->dcls_title));	// 공시제목, TEXT 형식
	memcpy(out->dcls_cntt, data->dcls_cntt, sizeof(data->dcls_cntt));	// 공시내용, HTML 형식
	out->stk_xst_flg = data->stk_xst_flg[0];	//종목존재여부, Y:종목코드존재 N:해당없음 ※공시전체대상 ※개발가이드 주5
	out->dcls_isin_code_flg = data->dcls_isin_code_flg[0];	//공시내용 종목코드여부, Y:종목코드 N:공시내용 ※공시페이지단위 ※개발가이드 주5
	out->nr_isin_code = Str2Int(data->nr_isin_code, sizeof(data->nr_isin_code));	// 종목코드갯수, 12자리 종목코드 개수 ※공시페이지단위 ※개발가이드 주5

	return 1;
}


// 공시(배치_코스닥_주식)
int ParseE9012(const double& timestamp, const char* in_buff, DF_DCLS_ARNG_KOSDAQ_STK* out) {
	DCLS_ARNG_KOSDAQ_STK* data = (DCLS_ARNG_KOSDAQ_STK*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA구분, E9:공시배치 F0:공시실시간
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// 정보구분, 01:주식 90:기타
	out->mkt_clsf = data->mkt_clsf[0];	//시장구분, 1:유가증권 2:코스닥 8:코넥스 9:기타
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// 종목코드, ※개발가이드 주1
	out->dcls_snr = Str2Int(data->dcls_snr, sizeof(data->dcls_snr));	// 공시일련번호, 년단위 ※개발가이드 주2
	out->dcls_pgnr = Str2Int(data->dcls_pgnr, sizeof(data->dcls_pgnr));	// 공시건당 총 페이지수
	out->dcls_pg_snr = Str2Int(data->dcls_pg_snr, sizeof(data->dcls_pg_snr));	// 공시건당 페이지 일련번호
	memcpy(out->dcls_date, data->dcls_date, sizeof(data->dcls_date));	// 공시일자, YYYYMMDD
	memcpy(out->trsm_date, data->trsm_date, sizeof(data->trsm_date));	// 전송일자, YYYYMMDD
	out->dcls_mkt_clsf = data->dcls_mkt_clsf[0];	//공시용시장구분, 1:유가증권 2:코스닥 3:파생상품 4:채권 5:시장감시 6:코넥스 ※개발가이드 주3
	memcpy(out->stk_nm, data->stk_nm, sizeof(data->stk_nm));	// 종목명
	out->proc_clsf = data->proc_clsf[0];	//처리구분, 1:정상 2:수정 3:삭제
	memcpy(out->rsn, data->rsn, sizeof(data->rsn));	// 사유, ※개발가이드 주4
	out->kor_eng_clsf = data->kor_eng_clsf[0];	//국문영문구분, 1:국문 2:영문
	memcpy(out->dcls_title, data->dcls_title, sizeof(data->dcls_title));	// 공시제목, TEXT 형식
	memcpy(out->dcls_cntt, data->dcls_cntt, sizeof(data->dcls_cntt));	// 공시내용, HTML 형식
	out->stk_xst_flg = data->stk_xst_flg[0];	//종목존재여부, Y:종목코드존재 N:해당없음 ※공시전체대상 ※개발가이드 주5
	out->dcls_isin_code_flg = data->dcls_isin_code_flg[0];	//공시내용 종목코드여부, Y:종목코드 N:공시내용 ※공시페이지단위 ※개발가이드 주5
	out->nr_isin_code = Str2Int(data->nr_isin_code, sizeof(data->nr_isin_code));	// 종목코드갯수, 12자리 종목코드 개수 ※공시페이지단위 ※개발가이드 주5

	return 1;
}


// 공시(배치_코넥스_주식)
int ParseE9018(const double& timestamp, const char* in_buff, DF_DCLS_ARNG_KONEX_STK* out) {
	DCLS_ARNG_KONEX_STK* data = (DCLS_ARNG_KONEX_STK*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA구분, E9:공시배치 F0:공시실시간
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// 정보구분, 01:주식 90:기타
	out->mkt_clsf = data->mkt_clsf[0];	//시장구분, 1:유가증권 2:코스닥 8:코넥스 9:기타
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// 종목코드, ※개발가이드 주1
	out->dcls_snr = Str2Int(data->dcls_snr, sizeof(data->dcls_snr));	// 공시일련번호, 년단위 ※개발가이드 주2
	out->dcls_pgnr = Str2Int(data->dcls_pgnr, sizeof(data->dcls_pgnr));	// 공시건당 총 페이지수
	out->dcls_pg_snr = Str2Int(data->dcls_pg_snr, sizeof(data->dcls_pg_snr));	// 공시건당 페이지 일련번호
	memcpy(out->dcls_date, data->dcls_date, sizeof(data->dcls_date));	// 공시일자, YYYYMMDD
	memcpy(out->trsm_date, data->trsm_date, sizeof(data->trsm_date));	// 전송일자, YYYYMMDD
	out->dcls_mkt_clsf = data->dcls_mkt_clsf[0];	//공시용시장구분, 1:유가증권 2:코스닥 3:파생상품 4:채권 5:시장감시 6:코넥스 ※개발가이드 주3
	memcpy(out->stk_nm, data->stk_nm, sizeof(data->stk_nm));	// 종목명
	out->proc_clsf = data->proc_clsf[0];	//처리구분, 1:정상 2:수정 3:삭제
	memcpy(out->rsn, data->rsn, sizeof(data->rsn));	// 사유, ※개발가이드 주4
	out->kor_eng_clsf = data->kor_eng_clsf[0];	//국문영문구분, 1:국문 2:영문
	memcpy(out->dcls_title, data->dcls_title, sizeof(data->dcls_title));	// 공시제목, TEXT 형식
	memcpy(out->dcls_cntt, data->dcls_cntt, sizeof(data->dcls_cntt));	// 공시내용, HTML 형식
	out->stk_xst_flg = data->stk_xst_flg[0];	//종목존재여부, Y:종목코드존재 N:해당없음 ※공시전체대상 ※개발가이드 주5
	out->dcls_isin_code_flg = data->dcls_isin_code_flg[0];	//공시내용 종목코드여부, Y:종목코드 N:공시내용 ※공시페이지단위 ※개발가이드 주5
	out->nr_isin_code = Str2Int(data->nr_isin_code, sizeof(data->nr_isin_code));	// 종목코드갯수, 12자리 종목코드 개수 ※공시페이지단위 ※개발가이드 주5

	return 1;
}


// 공시(배치_기타)
int ParseE9909(const double& timestamp, const char* in_buff, DF_DCLS_ARNG_ETC* out) {
	DCLS_ARNG_ETC* data = (DCLS_ARNG_ETC*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA구분, E9:공시배치 F0:공시실시간
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// 정보구분, 01:주식 90:기타
	out->mkt_clsf = data->mkt_clsf[0];	//시장구분, 1:유가증권 2:코스닥 8:코넥스 9:기타
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// 종목코드, ※개발가이드 주1
	out->dcls_snr = Str2Int(data->dcls_snr, sizeof(data->dcls_snr));	// 공시일련번호, 년단위 ※개발가이드 주2
	out->dcls_pgnr = Str2Int(data->dcls_pgnr, sizeof(data->dcls_pgnr));	// 공시건당 총 페이지수
	out->dcls_pg_snr = Str2Int(data->dcls_pg_snr, sizeof(data->dcls_pg_snr));	// 공시건당 페이지 일련번호
	memcpy(out->dcls_date, data->dcls_date, sizeof(data->dcls_date));	// 공시일자, YYYYMMDD
	memcpy(out->trsm_date, data->trsm_date, sizeof(data->trsm_date));	// 전송일자, YYYYMMDD
	out->dcls_mkt_clsf = data->dcls_mkt_clsf[0];	//공시용시장구분, 1:유가증권 2:코스닥 3:파생상품 4:채권 5:시장감시 6:코넥스 7:일반상품 E:배출권 ※개발가이드 주3
	memcpy(out->stk_nm, data->stk_nm, sizeof(data->stk_nm));	// 종목명
	out->proc_clsf = data->proc_clsf[0];	//처리구분, 1:정상 2:수정 3:삭제
	memcpy(out->rsn, data->rsn, sizeof(data->rsn));	// 사유, ※개발가이드 주4
	out->kor_eng_clsf = data->kor_eng_clsf[0];	//국문영문구분, 1:국문 2:영문
	memcpy(out->dcls_title, data->dcls_title, sizeof(data->dcls_title));	// 공시제목, TEXT 형식
	memcpy(out->dcls_cntt, data->dcls_cntt, sizeof(data->dcls_cntt));	// 공시내용, HTML 형식
	out->stk_xst_flg = data->stk_xst_flg[0];	//종목존재여부, Y:종목코드존재 N:해당없음 ※공시전체대상 ※개발가이드 주5
	out->dcls_isin_code_flg = data->dcls_isin_code_flg[0];	//공시내용 종목코드여부, Y:종목코드 N:공시내용 ※공시페이지단위 ※개발가이드 주5
	out->nr_isin_code = Str2Int(data->nr_isin_code, sizeof(data->nr_isin_code));	// 종목코드갯수, 12자리 종목코드 개수 ※공시페이지단위 ※개발가이드 주5

	return 1;
}


// 공시(실시간_기타)
int ParseF0909(const double& timestamp, const char* in_buff, DF_DCLS_RT_ETC* out) {
	DCLS_RT_ETC* data = (DCLS_RT_ETC*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA구분, E9:공시배치 F0:공시실시간
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// 정보구분, 01:주식 90:기타
	out->mkt_clsf = data->mkt_clsf[0];	//시장구분, 1:유가증권 2:코스닥 8:코넥스 9:기타
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// 종목코드, ※개발가이드 주1
	out->dcls_snr = Str2Int(data->dcls_snr, sizeof(data->dcls_snr));	// 공시일련번호, 년단위 ※개발가이드 주2
	out->dcls_pgnr = Str2Int(data->dcls_pgnr, sizeof(data->dcls_pgnr));	// 공시건당 총 페이지수
	out->dcls_pg_snr = Str2Int(data->dcls_pg_snr, sizeof(data->dcls_pg_snr));	// 공시건당 페이지 일련번호
	memcpy(out->dcls_date, data->dcls_date, sizeof(data->dcls_date));	// 공시일자, YYYYMMDD
	memcpy(out->trsm_date, data->trsm_date, sizeof(data->trsm_date));	// 전송일자, YYYYMMDD
	out->dcls_mkt_clsf = data->dcls_mkt_clsf[0];	//공시용시장구분, 1:유가증권 2:코스닥 3:파생상품 4:채권 5:시장감시 6:코넥스 7:일반상품 E:배출권 ※개발가이드 주3
	memcpy(out->stk_nm, data->stk_nm, sizeof(data->stk_nm));	// 종목명
	out->proc_clsf = data->proc_clsf[0];	//처리구분, 1:정상 2:수정 3:삭제
	memcpy(out->rsn, data->rsn, sizeof(data->rsn));	// 사유, ※개발가이드 주4
	out->kor_eng_clsf = data->kor_eng_clsf[0];	//국문영문구분, 1:국문 2:영문
	memcpy(out->dcls_title, data->dcls_title, sizeof(data->dcls_title));	// 공시제목, TEXT 형식
	memcpy(out->dcls_cntt, data->dcls_cntt, sizeof(data->dcls_cntt));	// 공시내용, HTML 형식
	out->stk_xst_flg = data->stk_xst_flg[0];	//종목존재여부, Y:종목코드존재 N:해당없음 ※공시전체대상 ※개발가이드 주5
	out->dcls_isin_code_flg = data->dcls_isin_code_flg[0];	//공시내용 종목코드여부, Y:종목코드 N:공시내용 ※공시페이지단위 ※개발가이드 주5
	out->nr_isin_code = Str2Int(data->nr_isin_code, sizeof(data->nr_isin_code));	// 종목코드갯수, 12자리 종목코드 개수 ※공시페이지단위 ※개발가이드 주5

	return 1;
}
