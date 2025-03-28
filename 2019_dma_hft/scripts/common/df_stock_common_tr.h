// df_stock_common_tr.h
// 주식 공통

#pragma once
// 주석에 \n이 들어간건 나중에 이쁘게 바꿔야함


// 투자자 정보
typedef struct _DF_STOCK_INV_INFO {
	char inv_code[4];	// 투자자코드, ※코드값모음 참조\n*코드'7000'시 수량, 대금정보 항목 0으로 전송 (20181210)
	double ask_ccls_qty;	// 매도체결수량, 단위:주
	double ask_trd_val;	// 매도거래대금, 단위:원
	double bid_ccls_qty;	// 매수체결수량, 단위:주
	double bid_trd_val;	// 매수거래대금, 단위:원
} DF_STOCK_INV_INFO;


// 거래원 정보
typedef struct _DF_STOCK_SRC_INFO {
	int ask_src_nr;	// 매도거래원번호
	double ask_ccls_qty;	// 매도체결수량, 단위:주
	double ask_trd_val;	// 매도거래대금, 단위:원
	int bid_src_nr;	// 매수거래원번호
	double bid_ccls_qty;	// 매수체결수량, 단위:주
	double bid_trd_val;	// 매수거래대금, 단위:원
} DF_STOCK_SRC_INFO;


// 호가 정보 (LP미포함)
typedef struct _DF_STOCK_LOB_INFO {
	int ask_prc;	// 매도호가
	int bid_prc;	// 매수호가
	double ask_vol_rsd;	// 매도호가 잔량
	double bid_vol_rsd;	// 매수호가 잔량
} DF_STOCK_LOB_INFO;


// 호가 정보 (LP포함)
typedef struct _DF_STOCK_LOB_INFO_WITH_LP {
	int ask_prc;	// 매도호가
	int bid_prc;	// 매수호가
	double ask_vol_rsd;	// 매도호가 잔량
	double bid_vol_rsd;	// 매수호가 잔량
	double lp_ask_vol_rsd;	// LP 매도호가 잔량
	double lp_bid_vol_rsd;	// LP 매수호가 잔량
} DF_STOCK_LOB_INFO_WITH_LP;


// 현물 Polling data
typedef struct _DF_CUR_POLLING_DATA {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA구분, I2
	char info_clsf[3];	// 정보구분, 00:초기값
	char mkt_clsf;	// 시장구분, 0:초기값
	char time[5];	// 시간, HHMM
} DF_CUR_POLLING_DATA;


// 공시(실시간_코스피_주식)
typedef struct _DF_DCLS_RT_KOSPI_STK {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA구분, E9:공시배치 F0:공시실시간
	char info_clsf[3];	// 정보구분, 01:주식 90:기타
	char mkt_clsf;	// 시장구분, 1:유가증권 2:코스닥 8:코넥스 9:기타
	char isin_code[13];	// 종목코드, ※개발가이드 주1
	int dcls_snr;	// 공시일련번호, 년단위 ※개발가이드 주2
	int dcls_pgnr;	// 공시건당 총 페이지수
	int dcls_pg_snr;	// 공시건당 페이지 일련번호
	char dcls_date[9];	// 공시일자, YYYYMMDD
	char trsm_date[9];	// 전송일자, YYYYMMDD
	char dcls_mkt_clsf;	// 공시용시장구분, 1:유가증권 2:코스닥 3:파생상품 4:채권 5:시장감시 6:코넥스 ※개발가이드 주3
	char stk_nm[41];	// 종목명
	char proc_clsf;	// 처리구분, 1:정상 2:수정 3:삭제
	char rsn[6];	// 사유, ※개발가이드 주4
	char kor_eng_clsf;	// 국문영문구분, 1:국문 2:영문
	char dcls_title[265];	// 공시제목, TEXT 형식
	char dcls_cntt[1001];	// 공시내용, HTML 형식
	char stk_xst_flg;	// 종목존재여부, Y:종목코드존재 N:해당없음 ※공시전체대상 ※개발가이드 주5
	char dcls_isin_code_flg;	// 공시내용 종목코드여부, Y:종목코드 N:공시내용 ※공시페이지단위 ※개발가이드 주5
	int nr_isin_code;	// 종목코드갯수, 12자리 종목코드 개수 ※공시페이지단위 ※개발가이드 주5
} DF_DCLS_RT_KOSPI_STK;


// 공시(실시간_코스닥_주식)
typedef struct _DF_DCLS_RT_KOSDAQ_STK {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA구분, E9:공시배치 F0:공시실시간
	char info_clsf[3];	// 정보구분, 01:주식 90:기타
	char mkt_clsf;	// 시장구분, 1:유가증권 2:코스닥 8:코넥스 9:기타
	char isin_code[13];	// 종목코드, ※개발가이드 주1
	int dcls_snr;	// 공시일련번호, 년단위 ※개발가이드 주2
	int dcls_pgnr;	// 공시건당 총 페이지수
	int dcls_pg_snr;	// 공시건당 페이지 일련번호
	char dcls_date[9];	// 공시일자, YYYYMMDD
	char trsm_date[9];	// 전송일자, YYYYMMDD
	char dcls_mkt_clsf;	// 공시용시장구분, 1:유가증권 2:코스닥 3:파생상품 4:채권 5:시장감시 6:코넥스 ※개발가이드 주3
	char stk_nm[41];	// 종목명
	char proc_clsf;	// 처리구분, 1:정상 2:수정 3:삭제
	char rsn[6];	// 사유, ※개발가이드 주4
	char kor_eng_clsf;	// 국문영문구분, 1:국문 2:영문
	char dcls_title[265];	// 공시제목, TEXT 형식
	char dcls_cntt[1001];	// 공시내용, HTML 형식
	char stk_xst_flg;	// 종목존재여부, Y:종목코드존재 N:해당없음 ※공시전체대상 ※개발가이드 주5
	char dcls_isin_code_flg;	// 공시내용 종목코드여부, Y:종목코드 N:공시내용 ※공시페이지단위 ※개발가이드 주5
	int nr_isin_code;	// 종목코드갯수, 12자리 종목코드 개수 ※공시페이지단위 ※개발가이드 주5
} DF_DCLS_RT_KOSDAQ_STK;


// 공시(실시간_코넥스_주식)
typedef struct _DF_DCLS_RT_KONEX_STK {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA구분, E9:공시배치 F0:공시실시간
	char info_clsf[3];	// 정보구분, 01:주식 90:기타
	char mkt_clsf;	// 시장구분, 1:유가증권 2:코스닥 8:코넥스 9:기타
	char isin_code[13];	// 종목코드, ※개발가이드 주1
	int dcls_snr;	// 공시일련번호, 년단위 ※개발가이드 주2
	int dcls_pgnr;	// 공시건당 총 페이지수
	int dcls_pg_snr;	// 공시건당 페이지 일련번호
	char dcls_date[9];	// 공시일자, YYYYMMDD
	char trsm_date[9];	// 전송일자, YYYYMMDD
	char dcls_mkt_clsf;	// 공시용시장구분, 1:유가증권 2:코스닥 3:파생상품 4:채권 5:시장감시 6:코넥스 ※개발가이드 주3
	char stk_nm[41];	// 종목명
	char proc_clsf;	// 처리구분, 1:정상 2:수정 3:삭제
	char rsn[6];	// 사유, ※개발가이드 주4
	char kor_eng_clsf;	// 국문영문구분, 1:국문 2:영문
	char dcls_title[265];	// 공시제목, TEXT 형식
	char dcls_cntt[1001];	// 공시내용, HTML 형식
	char stk_xst_flg;	// 종목존재여부, Y:종목코드존재 N:해당없음 ※공시전체대상 ※개발가이드 주5
	char dcls_isin_code_flg;	// 공시내용 종목코드여부, Y:종목코드 N:공시내용 ※공시페이지단위 ※개발가이드 주5
	int nr_isin_code;	// 종목코드갯수, 12자리 종목코드 개수 ※공시페이지단위 ※개발가이드 주5
} DF_DCLS_RT_KONEX_STK;


// 공시(배치_코스피_주식)
typedef struct _DF_DCLS_ARNG_KOSPI_STK {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA구분, E9:공시배치 F0:공시실시간
	char info_clsf[3];	// 정보구분, 01:주식 90:기타
	char mkt_clsf;	// 시장구분, 1:유가증권 2:코스닥 8:코넥스 9:기타
	char isin_code[13];	// 종목코드, ※개발가이드 주1
	int dcls_snr;	// 공시일련번호, 년단위 ※개발가이드 주2
	int dcls_pgnr;	// 공시건당 총 페이지수
	int dcls_pg_snr;	// 공시건당 페이지 일련번호
	char dcls_date[9];	// 공시일자, YYYYMMDD
	char trsm_date[9];	// 전송일자, YYYYMMDD
	char dcls_mkt_clsf;	// 공시용시장구분, 1:유가증권 2:코스닥 3:파생상품 4:채권 5:시장감시 6:코넥스 ※개발가이드 주3
	char stk_nm[41];	// 종목명
	char proc_clsf;	// 처리구분, 1:정상 2:수정 3:삭제
	char rsn[6];	// 사유, ※개발가이드 주4
	char kor_eng_clsf;	// 국문영문구분, 1:국문 2:영문
	char dcls_title[265];	// 공시제목, TEXT 형식
	char dcls_cntt[1001];	// 공시내용, HTML 형식
	char stk_xst_flg;	// 종목존재여부, Y:종목코드존재 N:해당없음 ※공시전체대상 ※개발가이드 주5
	char dcls_isin_code_flg;	// 공시내용 종목코드여부, Y:종목코드 N:공시내용 ※공시페이지단위 ※개발가이드 주5
	int nr_isin_code;	// 종목코드갯수, 12자리 종목코드 개수 ※공시페이지단위 ※개발가이드 주5
} DF_DCLS_ARNG_KOSPI_STK;


// 공시(배치_코스닥_주식)
typedef struct _DF_DCLS_ARNG_KOSDAQ_STK {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA구분, E9:공시배치 F0:공시실시간
	char info_clsf[3];	// 정보구분, 01:주식 90:기타
	char mkt_clsf;	// 시장구분, 1:유가증권 2:코스닥 8:코넥스 9:기타
	char isin_code[13];	// 종목코드, ※개발가이드 주1
	int dcls_snr;	// 공시일련번호, 년단위 ※개발가이드 주2
	int dcls_pgnr;	// 공시건당 총 페이지수
	int dcls_pg_snr;	// 공시건당 페이지 일련번호
	char dcls_date[9];	// 공시일자, YYYYMMDD
	char trsm_date[9];	// 전송일자, YYYYMMDD
	char dcls_mkt_clsf;	// 공시용시장구분, 1:유가증권 2:코스닥 3:파생상품 4:채권 5:시장감시 6:코넥스 ※개발가이드 주3
	char stk_nm[41];	// 종목명
	char proc_clsf;	// 처리구분, 1:정상 2:수정 3:삭제
	char rsn[6];	// 사유, ※개발가이드 주4
	char kor_eng_clsf;	// 국문영문구분, 1:국문 2:영문
	char dcls_title[265];	// 공시제목, TEXT 형식
	char dcls_cntt[1001];	// 공시내용, HTML 형식
	char stk_xst_flg;	// 종목존재여부, Y:종목코드존재 N:해당없음 ※공시전체대상 ※개발가이드 주5
	char dcls_isin_code_flg;	// 공시내용 종목코드여부, Y:종목코드 N:공시내용 ※공시페이지단위 ※개발가이드 주5
	int nr_isin_code;	// 종목코드갯수, 12자리 종목코드 개수 ※공시페이지단위 ※개발가이드 주5
} DF_DCLS_ARNG_KOSDAQ_STK;


// 공시(배치_코넥스_주식)
typedef struct _DF_DCLS_ARNG_KONEX_STK {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA구분, E9:공시배치 F0:공시실시간
	char info_clsf[3];	// 정보구분, 01:주식 90:기타
	char mkt_clsf;	// 시장구분, 1:유가증권 2:코스닥 8:코넥스 9:기타
	char isin_code[13];	// 종목코드, ※개발가이드 주1
	int dcls_snr;	// 공시일련번호, 년단위 ※개발가이드 주2
	int dcls_pgnr;	// 공시건당 총 페이지수
	int dcls_pg_snr;	// 공시건당 페이지 일련번호
	char dcls_date[9];	// 공시일자, YYYYMMDD
	char trsm_date[9];	// 전송일자, YYYYMMDD
	char dcls_mkt_clsf;	// 공시용시장구분, 1:유가증권 2:코스닥 3:파생상품 4:채권 5:시장감시 6:코넥스 ※개발가이드 주3
	char stk_nm[41];	// 종목명
	char proc_clsf;	// 처리구분, 1:정상 2:수정 3:삭제
	char rsn[6];	// 사유, ※개발가이드 주4
	char kor_eng_clsf;	// 국문영문구분, 1:국문 2:영문
	char dcls_title[265];	// 공시제목, TEXT 형식
	char dcls_cntt[1001];	// 공시내용, HTML 형식
	char stk_xst_flg;	// 종목존재여부, Y:종목코드존재 N:해당없음 ※공시전체대상 ※개발가이드 주5
	char dcls_isin_code_flg;	// 공시내용 종목코드여부, Y:종목코드 N:공시내용 ※공시페이지단위 ※개발가이드 주5
	int nr_isin_code;	// 종목코드갯수, 12자리 종목코드 개수 ※공시페이지단위 ※개발가이드 주5
} DF_DCLS_ARNG_KONEX_STK;


// 공시(배치_기타)
typedef struct _DF_DCLS_ARNG_ETC {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA구분, E9:공시배치 F0:공시실시간
	char info_clsf[3];	// 정보구분, 01:주식 90:기타
	char mkt_clsf;	// 시장구분, 1:유가증권 2:코스닥 8:코넥스 9:기타
	char isin_code[13];	// 종목코드, ※개발가이드 주1
	int dcls_snr;	// 공시일련번호, 년단위 ※개발가이드 주2
	int dcls_pgnr;	// 공시건당 총 페이지수
	int dcls_pg_snr;	// 공시건당 페이지 일련번호
	char dcls_date[9];	// 공시일자, YYYYMMDD
	char trsm_date[9];	// 전송일자, YYYYMMDD
	char dcls_mkt_clsf;	// 공시용시장구분, 1:유가증권 2:코스닥 3:파생상품 4:채권 5:시장감시 6:코넥스 7:일반상품 E:배출권 ※개발가이드 주3
	char stk_nm[41];	// 종목명
	char proc_clsf;	// 처리구분, 1:정상 2:수정 3:삭제
	char rsn[6];	// 사유, ※개발가이드 주4
	char kor_eng_clsf;	// 국문영문구분, 1:국문 2:영문
	char dcls_title[265];	// 공시제목, TEXT 형식
	char dcls_cntt[1001];	// 공시내용, HTML 형식
	char stk_xst_flg;	// 종목존재여부, Y:종목코드존재 N:해당없음 ※공시전체대상 ※개발가이드 주5
	char dcls_isin_code_flg;	// 공시내용 종목코드여부, Y:종목코드 N:공시내용 ※공시페이지단위 ※개발가이드 주5
	int nr_isin_code;	// 종목코드갯수, 12자리 종목코드 개수 ※공시페이지단위 ※개발가이드 주5
} DF_DCLS_ARNG_ETC;


// 공시(실시간_기타)
typedef struct _DF_DCLS_RT_ETC {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA구분, E9:공시배치 F0:공시실시간
	char info_clsf[3];	// 정보구분, 01:주식 90:기타
	char mkt_clsf;	// 시장구분, 1:유가증권 2:코스닥 8:코넥스 9:기타
	char isin_code[13];	// 종목코드, ※개발가이드 주1
	int dcls_snr;	// 공시일련번호, 년단위 ※개발가이드 주2
	int dcls_pgnr;	// 공시건당 총 페이지수
	int dcls_pg_snr;	// 공시건당 페이지 일련번호
	char dcls_date[9];	// 공시일자, YYYYMMDD
	char trsm_date[9];	// 전송일자, YYYYMMDD
	char dcls_mkt_clsf;	// 공시용시장구분, 1:유가증권 2:코스닥 3:파생상품 4:채권 5:시장감시 6:코넥스 7:일반상품 E:배출권 ※개발가이드 주3
	char stk_nm[41];	// 종목명
	char proc_clsf;	// 처리구분, 1:정상 2:수정 3:삭제
	char rsn[6];	// 사유, ※개발가이드 주4
	char kor_eng_clsf;	// 국문영문구분, 1:국문 2:영문
	char dcls_title[265];	// 공시제목, TEXT 형식
	char dcls_cntt[1001];	// 공시내용, HTML 형식
	char stk_xst_flg;	// 종목존재여부, Y:종목코드존재 N:해당없음 ※공시전체대상 ※개발가이드 주5
	char dcls_isin_code_flg;	// 공시내용 종목코드여부, Y:종목코드 N:공시내용 ※공시페이지단위 ※개발가이드 주5
	int nr_isin_code;	// 종목코드갯수, 12자리 종목코드 개수 ※공시페이지단위 ※개발가이드 주5
} DF_DCLS_RT_ETC;
