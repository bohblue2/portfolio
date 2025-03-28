// df_stock_common_tr.h
// �ֽ� ����

#pragma once
// �ּ��� \n�� ���� ���߿� �̻ڰ� �ٲ����


// ������ ����
typedef struct _DF_STOCK_INV_INFO {
	char inv_code[4];	// �������ڵ�, ���ڵ尪���� ����\n*�ڵ�'7000'�� ����, ������� �׸� 0���� ���� (20181210)
	double ask_ccls_qty;	// �ŵ�ü�����, ����:��
	double ask_trd_val;	// �ŵ��ŷ����, ����:��
	double bid_ccls_qty;	// �ż�ü�����, ����:��
	double bid_trd_val;	// �ż��ŷ����, ����:��
} DF_STOCK_INV_INFO;


// �ŷ��� ����
typedef struct _DF_STOCK_SRC_INFO {
	int ask_src_nr;	// �ŵ��ŷ�����ȣ
	double ask_ccls_qty;	// �ŵ�ü�����, ����:��
	double ask_trd_val;	// �ŵ��ŷ����, ����:��
	int bid_src_nr;	// �ż��ŷ�����ȣ
	double bid_ccls_qty;	// �ż�ü�����, ����:��
	double bid_trd_val;	// �ż��ŷ����, ����:��
} DF_STOCK_SRC_INFO;


// ȣ�� ���� (LP������)
typedef struct _DF_STOCK_LOB_INFO {
	int ask_prc;	// �ŵ�ȣ��
	int bid_prc;	// �ż�ȣ��
	double ask_vol_rsd;	// �ŵ�ȣ�� �ܷ�
	double bid_vol_rsd;	// �ż�ȣ�� �ܷ�
} DF_STOCK_LOB_INFO;


// ȣ�� ���� (LP����)
typedef struct _DF_STOCK_LOB_INFO_WITH_LP {
	int ask_prc;	// �ŵ�ȣ��
	int bid_prc;	// �ż�ȣ��
	double ask_vol_rsd;	// �ŵ�ȣ�� �ܷ�
	double bid_vol_rsd;	// �ż�ȣ�� �ܷ�
	double lp_ask_vol_rsd;	// LP �ŵ�ȣ�� �ܷ�
	double lp_bid_vol_rsd;	// LP �ż�ȣ�� �ܷ�
} DF_STOCK_LOB_INFO_WITH_LP;


// ���� Polling data
typedef struct _DF_CUR_POLLING_DATA {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����, I2
	char info_clsf[3];	// ��������, 00:�ʱⰪ
	char mkt_clsf;	// ���屸��, 0:�ʱⰪ
	char time[5];	// �ð�, HHMM
} DF_CUR_POLLING_DATA;


// ����(�ǽð�_�ڽ���_�ֽ�)
typedef struct _DF_DCLS_RT_KOSPI_STK {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����, E9:���ù�ġ F0:���ýǽð�
	char info_clsf[3];	// ��������, 01:�ֽ� 90:��Ÿ
	char mkt_clsf;	// ���屸��, 1:�������� 2:�ڽ��� 8:�ڳؽ� 9:��Ÿ
	char isin_code[13];	// �����ڵ�, �ذ��߰��̵� ��1
	int dcls_snr;	// �����Ϸù�ȣ, ����� �ذ��߰��̵� ��2
	int dcls_pgnr;	// ���ðǴ� �� ��������
	int dcls_pg_snr;	// ���ðǴ� ������ �Ϸù�ȣ
	char dcls_date[9];	// ��������, YYYYMMDD
	char trsm_date[9];	// ��������, YYYYMMDD
	char dcls_mkt_clsf;	// ���ÿ���屸��, 1:�������� 2:�ڽ��� 3:�Ļ���ǰ 4:ä�� 5:���尨�� 6:�ڳؽ� �ذ��߰��̵� ��3
	char stk_nm[41];	// �����
	char proc_clsf;	// ó������, 1:���� 2:���� 3:����
	char rsn[6];	// ����, �ذ��߰��̵� ��4
	char kor_eng_clsf;	// ������������, 1:���� 2:����
	char dcls_title[265];	// ��������, TEXT ����
	char dcls_cntt[1001];	// ���ó���, HTML ����
	char stk_xst_flg;	// �������翩��, Y:�����ڵ����� N:�ش���� �ذ�����ü��� �ذ��߰��̵� ��5
	char dcls_isin_code_flg;	// ���ó��� �����ڵ忩��, Y:�����ڵ� N:���ó��� �ذ������������� �ذ��߰��̵� ��5
	int nr_isin_code;	// �����ڵ尹��, 12�ڸ� �����ڵ� ���� �ذ������������� �ذ��߰��̵� ��5
} DF_DCLS_RT_KOSPI_STK;


// ����(�ǽð�_�ڽ���_�ֽ�)
typedef struct _DF_DCLS_RT_KOSDAQ_STK {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����, E9:���ù�ġ F0:���ýǽð�
	char info_clsf[3];	// ��������, 01:�ֽ� 90:��Ÿ
	char mkt_clsf;	// ���屸��, 1:�������� 2:�ڽ��� 8:�ڳؽ� 9:��Ÿ
	char isin_code[13];	// �����ڵ�, �ذ��߰��̵� ��1
	int dcls_snr;	// �����Ϸù�ȣ, ����� �ذ��߰��̵� ��2
	int dcls_pgnr;	// ���ðǴ� �� ��������
	int dcls_pg_snr;	// ���ðǴ� ������ �Ϸù�ȣ
	char dcls_date[9];	// ��������, YYYYMMDD
	char trsm_date[9];	// ��������, YYYYMMDD
	char dcls_mkt_clsf;	// ���ÿ���屸��, 1:�������� 2:�ڽ��� 3:�Ļ���ǰ 4:ä�� 5:���尨�� 6:�ڳؽ� �ذ��߰��̵� ��3
	char stk_nm[41];	// �����
	char proc_clsf;	// ó������, 1:���� 2:���� 3:����
	char rsn[6];	// ����, �ذ��߰��̵� ��4
	char kor_eng_clsf;	// ������������, 1:���� 2:����
	char dcls_title[265];	// ��������, TEXT ����
	char dcls_cntt[1001];	// ���ó���, HTML ����
	char stk_xst_flg;	// �������翩��, Y:�����ڵ����� N:�ش���� �ذ�����ü��� �ذ��߰��̵� ��5
	char dcls_isin_code_flg;	// ���ó��� �����ڵ忩��, Y:�����ڵ� N:���ó��� �ذ������������� �ذ��߰��̵� ��5
	int nr_isin_code;	// �����ڵ尹��, 12�ڸ� �����ڵ� ���� �ذ������������� �ذ��߰��̵� ��5
} DF_DCLS_RT_KOSDAQ_STK;


// ����(�ǽð�_�ڳؽ�_�ֽ�)
typedef struct _DF_DCLS_RT_KONEX_STK {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����, E9:���ù�ġ F0:���ýǽð�
	char info_clsf[3];	// ��������, 01:�ֽ� 90:��Ÿ
	char mkt_clsf;	// ���屸��, 1:�������� 2:�ڽ��� 8:�ڳؽ� 9:��Ÿ
	char isin_code[13];	// �����ڵ�, �ذ��߰��̵� ��1
	int dcls_snr;	// �����Ϸù�ȣ, ����� �ذ��߰��̵� ��2
	int dcls_pgnr;	// ���ðǴ� �� ��������
	int dcls_pg_snr;	// ���ðǴ� ������ �Ϸù�ȣ
	char dcls_date[9];	// ��������, YYYYMMDD
	char trsm_date[9];	// ��������, YYYYMMDD
	char dcls_mkt_clsf;	// ���ÿ���屸��, 1:�������� 2:�ڽ��� 3:�Ļ���ǰ 4:ä�� 5:���尨�� 6:�ڳؽ� �ذ��߰��̵� ��3
	char stk_nm[41];	// �����
	char proc_clsf;	// ó������, 1:���� 2:���� 3:����
	char rsn[6];	// ����, �ذ��߰��̵� ��4
	char kor_eng_clsf;	// ������������, 1:���� 2:����
	char dcls_title[265];	// ��������, TEXT ����
	char dcls_cntt[1001];	// ���ó���, HTML ����
	char stk_xst_flg;	// �������翩��, Y:�����ڵ����� N:�ش���� �ذ�����ü��� �ذ��߰��̵� ��5
	char dcls_isin_code_flg;	// ���ó��� �����ڵ忩��, Y:�����ڵ� N:���ó��� �ذ������������� �ذ��߰��̵� ��5
	int nr_isin_code;	// �����ڵ尹��, 12�ڸ� �����ڵ� ���� �ذ������������� �ذ��߰��̵� ��5
} DF_DCLS_RT_KONEX_STK;


// ����(��ġ_�ڽ���_�ֽ�)
typedef struct _DF_DCLS_ARNG_KOSPI_STK {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����, E9:���ù�ġ F0:���ýǽð�
	char info_clsf[3];	// ��������, 01:�ֽ� 90:��Ÿ
	char mkt_clsf;	// ���屸��, 1:�������� 2:�ڽ��� 8:�ڳؽ� 9:��Ÿ
	char isin_code[13];	// �����ڵ�, �ذ��߰��̵� ��1
	int dcls_snr;	// �����Ϸù�ȣ, ����� �ذ��߰��̵� ��2
	int dcls_pgnr;	// ���ðǴ� �� ��������
	int dcls_pg_snr;	// ���ðǴ� ������ �Ϸù�ȣ
	char dcls_date[9];	// ��������, YYYYMMDD
	char trsm_date[9];	// ��������, YYYYMMDD
	char dcls_mkt_clsf;	// ���ÿ���屸��, 1:�������� 2:�ڽ��� 3:�Ļ���ǰ 4:ä�� 5:���尨�� 6:�ڳؽ� �ذ��߰��̵� ��3
	char stk_nm[41];	// �����
	char proc_clsf;	// ó������, 1:���� 2:���� 3:����
	char rsn[6];	// ����, �ذ��߰��̵� ��4
	char kor_eng_clsf;	// ������������, 1:���� 2:����
	char dcls_title[265];	// ��������, TEXT ����
	char dcls_cntt[1001];	// ���ó���, HTML ����
	char stk_xst_flg;	// �������翩��, Y:�����ڵ����� N:�ش���� �ذ�����ü��� �ذ��߰��̵� ��5
	char dcls_isin_code_flg;	// ���ó��� �����ڵ忩��, Y:�����ڵ� N:���ó��� �ذ������������� �ذ��߰��̵� ��5
	int nr_isin_code;	// �����ڵ尹��, 12�ڸ� �����ڵ� ���� �ذ������������� �ذ��߰��̵� ��5
} DF_DCLS_ARNG_KOSPI_STK;


// ����(��ġ_�ڽ���_�ֽ�)
typedef struct _DF_DCLS_ARNG_KOSDAQ_STK {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����, E9:���ù�ġ F0:���ýǽð�
	char info_clsf[3];	// ��������, 01:�ֽ� 90:��Ÿ
	char mkt_clsf;	// ���屸��, 1:�������� 2:�ڽ��� 8:�ڳؽ� 9:��Ÿ
	char isin_code[13];	// �����ڵ�, �ذ��߰��̵� ��1
	int dcls_snr;	// �����Ϸù�ȣ, ����� �ذ��߰��̵� ��2
	int dcls_pgnr;	// ���ðǴ� �� ��������
	int dcls_pg_snr;	// ���ðǴ� ������ �Ϸù�ȣ
	char dcls_date[9];	// ��������, YYYYMMDD
	char trsm_date[9];	// ��������, YYYYMMDD
	char dcls_mkt_clsf;	// ���ÿ���屸��, 1:�������� 2:�ڽ��� 3:�Ļ���ǰ 4:ä�� 5:���尨�� 6:�ڳؽ� �ذ��߰��̵� ��3
	char stk_nm[41];	// �����
	char proc_clsf;	// ó������, 1:���� 2:���� 3:����
	char rsn[6];	// ����, �ذ��߰��̵� ��4
	char kor_eng_clsf;	// ������������, 1:���� 2:����
	char dcls_title[265];	// ��������, TEXT ����
	char dcls_cntt[1001];	// ���ó���, HTML ����
	char stk_xst_flg;	// �������翩��, Y:�����ڵ����� N:�ش���� �ذ�����ü��� �ذ��߰��̵� ��5
	char dcls_isin_code_flg;	// ���ó��� �����ڵ忩��, Y:�����ڵ� N:���ó��� �ذ������������� �ذ��߰��̵� ��5
	int nr_isin_code;	// �����ڵ尹��, 12�ڸ� �����ڵ� ���� �ذ������������� �ذ��߰��̵� ��5
} DF_DCLS_ARNG_KOSDAQ_STK;


// ����(��ġ_�ڳؽ�_�ֽ�)
typedef struct _DF_DCLS_ARNG_KONEX_STK {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����, E9:���ù�ġ F0:���ýǽð�
	char info_clsf[3];	// ��������, 01:�ֽ� 90:��Ÿ
	char mkt_clsf;	// ���屸��, 1:�������� 2:�ڽ��� 8:�ڳؽ� 9:��Ÿ
	char isin_code[13];	// �����ڵ�, �ذ��߰��̵� ��1
	int dcls_snr;	// �����Ϸù�ȣ, ����� �ذ��߰��̵� ��2
	int dcls_pgnr;	// ���ðǴ� �� ��������
	int dcls_pg_snr;	// ���ðǴ� ������ �Ϸù�ȣ
	char dcls_date[9];	// ��������, YYYYMMDD
	char trsm_date[9];	// ��������, YYYYMMDD
	char dcls_mkt_clsf;	// ���ÿ���屸��, 1:�������� 2:�ڽ��� 3:�Ļ���ǰ 4:ä�� 5:���尨�� 6:�ڳؽ� �ذ��߰��̵� ��3
	char stk_nm[41];	// �����
	char proc_clsf;	// ó������, 1:���� 2:���� 3:����
	char rsn[6];	// ����, �ذ��߰��̵� ��4
	char kor_eng_clsf;	// ������������, 1:���� 2:����
	char dcls_title[265];	// ��������, TEXT ����
	char dcls_cntt[1001];	// ���ó���, HTML ����
	char stk_xst_flg;	// �������翩��, Y:�����ڵ����� N:�ش���� �ذ�����ü��� �ذ��߰��̵� ��5
	char dcls_isin_code_flg;	// ���ó��� �����ڵ忩��, Y:�����ڵ� N:���ó��� �ذ������������� �ذ��߰��̵� ��5
	int nr_isin_code;	// �����ڵ尹��, 12�ڸ� �����ڵ� ���� �ذ������������� �ذ��߰��̵� ��5
} DF_DCLS_ARNG_KONEX_STK;


// ����(��ġ_��Ÿ)
typedef struct _DF_DCLS_ARNG_ETC {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����, E9:���ù�ġ F0:���ýǽð�
	char info_clsf[3];	// ��������, 01:�ֽ� 90:��Ÿ
	char mkt_clsf;	// ���屸��, 1:�������� 2:�ڽ��� 8:�ڳؽ� 9:��Ÿ
	char isin_code[13];	// �����ڵ�, �ذ��߰��̵� ��1
	int dcls_snr;	// �����Ϸù�ȣ, ����� �ذ��߰��̵� ��2
	int dcls_pgnr;	// ���ðǴ� �� ��������
	int dcls_pg_snr;	// ���ðǴ� ������ �Ϸù�ȣ
	char dcls_date[9];	// ��������, YYYYMMDD
	char trsm_date[9];	// ��������, YYYYMMDD
	char dcls_mkt_clsf;	// ���ÿ���屸��, 1:�������� 2:�ڽ��� 3:�Ļ���ǰ 4:ä�� 5:���尨�� 6:�ڳؽ� 7:�Ϲݻ�ǰ E:����� �ذ��߰��̵� ��3
	char stk_nm[41];	// �����
	char proc_clsf;	// ó������, 1:���� 2:���� 3:����
	char rsn[6];	// ����, �ذ��߰��̵� ��4
	char kor_eng_clsf;	// ������������, 1:���� 2:����
	char dcls_title[265];	// ��������, TEXT ����
	char dcls_cntt[1001];	// ���ó���, HTML ����
	char stk_xst_flg;	// �������翩��, Y:�����ڵ����� N:�ش���� �ذ�����ü��� �ذ��߰��̵� ��5
	char dcls_isin_code_flg;	// ���ó��� �����ڵ忩��, Y:�����ڵ� N:���ó��� �ذ������������� �ذ��߰��̵� ��5
	int nr_isin_code;	// �����ڵ尹��, 12�ڸ� �����ڵ� ���� �ذ������������� �ذ��߰��̵� ��5
} DF_DCLS_ARNG_ETC;


// ����(�ǽð�_��Ÿ)
typedef struct _DF_DCLS_RT_ETC {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����, E9:���ù�ġ F0:���ýǽð�
	char info_clsf[3];	// ��������, 01:�ֽ� 90:��Ÿ
	char mkt_clsf;	// ���屸��, 1:�������� 2:�ڽ��� 8:�ڳؽ� 9:��Ÿ
	char isin_code[13];	// �����ڵ�, �ذ��߰��̵� ��1
	int dcls_snr;	// �����Ϸù�ȣ, ����� �ذ��߰��̵� ��2
	int dcls_pgnr;	// ���ðǴ� �� ��������
	int dcls_pg_snr;	// ���ðǴ� ������ �Ϸù�ȣ
	char dcls_date[9];	// ��������, YYYYMMDD
	char trsm_date[9];	// ��������, YYYYMMDD
	char dcls_mkt_clsf;	// ���ÿ���屸��, 1:�������� 2:�ڽ��� 3:�Ļ���ǰ 4:ä�� 5:���尨�� 6:�ڳؽ� 7:�Ϲݻ�ǰ E:����� �ذ��߰��̵� ��3
	char stk_nm[41];	// �����
	char proc_clsf;	// ó������, 1:���� 2:���� 3:����
	char rsn[6];	// ����, �ذ��߰��̵� ��4
	char kor_eng_clsf;	// ������������, 1:���� 2:����
	char dcls_title[265];	// ��������, TEXT ����
	char dcls_cntt[1001];	// ���ó���, HTML ����
	char stk_xst_flg;	// �������翩��, Y:�����ڵ����� N:�ش���� �ذ�����ü��� �ذ��߰��̵� ��5
	char dcls_isin_code_flg;	// ���ó��� �����ڵ忩��, Y:�����ڵ� N:���ó��� �ذ������������� �ذ��߰��̵� ��5
	int nr_isin_code;	// �����ڵ尹��, 12�ڸ� �����ڵ� ���� �ذ������������� �ذ��߰��̵� ��5
} DF_DCLS_RT_ETC;
