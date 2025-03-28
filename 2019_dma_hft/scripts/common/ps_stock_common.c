// ps_stock_common.c
// �ֽ� ����
// �ּ��� \n�� ���� ���߿� �̻ڰ� �ٲ����

#include "ps_stock_common.h"


extern int     Str2Int(char *str, int size);
extern double  Str2Dbl(char *str, int size, int point);
extern double  Str2SignDouble(char *str, int size, int point);


// ���� Polling data
int ParseI2000(const double& timestamp, const char* in_buff, DF_CUR_POLLING_DATA* out) {
	CUR_POLLING_DATA* data = (CUR_POLLING_DATA*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����, I2
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������, 00:�ʱⰪ
	out->mkt_clsf = data->mkt_clsf[0];	//���屸��, 0:�ʱⰪ
	memcpy(out->time, data->time, sizeof(data->time));	// �ð�, HHMM

	return 1;
}


// ����(�ǽð�_�ڽ���_�ֽ�)
int ParseF0011(const double& timestamp, const char* in_buff, DF_DCLS_RT_KOSPI_STK* out) {
	DCLS_RT_KOSPI_STK* data = (DCLS_RT_KOSPI_STK*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����, E9:���ù�ġ F0:���ýǽð�
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������, 01:�ֽ� 90:��Ÿ
	out->mkt_clsf = data->mkt_clsf[0];	//���屸��, 1:�������� 2:�ڽ��� 8:�ڳؽ� 9:��Ÿ
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// �����ڵ�, �ذ��߰��̵� ��1
	out->dcls_snr = Str2Int(data->dcls_snr, sizeof(data->dcls_snr));	// �����Ϸù�ȣ, ����� �ذ��߰��̵� ��2
	out->dcls_pgnr = Str2Int(data->dcls_pgnr, sizeof(data->dcls_pgnr));	// ���ðǴ� �� ��������
	out->dcls_pg_snr = Str2Int(data->dcls_pg_snr, sizeof(data->dcls_pg_snr));	// ���ðǴ� ������ �Ϸù�ȣ
	memcpy(out->dcls_date, data->dcls_date, sizeof(data->dcls_date));	// ��������, YYYYMMDD
	memcpy(out->trsm_date, data->trsm_date, sizeof(data->trsm_date));	// ��������, YYYYMMDD
	out->dcls_mkt_clsf = data->dcls_mkt_clsf[0];	//���ÿ���屸��, 1:�������� 2:�ڽ��� 3:�Ļ���ǰ 4:ä�� 5:���尨�� 6:�ڳؽ� �ذ��߰��̵� ��3
	memcpy(out->stk_nm, data->stk_nm, sizeof(data->stk_nm));	// �����
	out->proc_clsf = data->proc_clsf[0];	//ó������, 1:���� 2:���� 3:����
	memcpy(out->rsn, data->rsn, sizeof(data->rsn));	// ����, �ذ��߰��̵� ��4
	out->kor_eng_clsf = data->kor_eng_clsf[0];	//������������, 1:���� 2:����
	memcpy(out->dcls_title, data->dcls_title, sizeof(data->dcls_title));	// ��������, TEXT ����
	memcpy(out->dcls_cntt, data->dcls_cntt, sizeof(data->dcls_cntt));	// ���ó���, HTML ����
	out->stk_xst_flg = data->stk_xst_flg[0];	//�������翩��, Y:�����ڵ����� N:�ش���� �ذ�����ü��� �ذ��߰��̵� ��5
	out->dcls_isin_code_flg = data->dcls_isin_code_flg[0];	//���ó��� �����ڵ忩��, Y:�����ڵ� N:���ó��� �ذ������������� �ذ��߰��̵� ��5
	out->nr_isin_code = Str2Int(data->nr_isin_code, sizeof(data->nr_isin_code));	// �����ڵ尹��, 12�ڸ� �����ڵ� ���� �ذ������������� �ذ��߰��̵� ��5

	return 1;
}


// ����(�ǽð�_�ڽ���_�ֽ�)
int ParseF0012(const double& timestamp, const char* in_buff, DF_DCLS_RT_KOSDAQ_STK* out) {
	DCLS_RT_KOSDAQ_STK* data = (DCLS_RT_KOSDAQ_STK*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����, E9:���ù�ġ F0:���ýǽð�
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������, 01:�ֽ� 90:��Ÿ
	out->mkt_clsf = data->mkt_clsf[0];	//���屸��, 1:�������� 2:�ڽ��� 8:�ڳؽ� 9:��Ÿ
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// �����ڵ�, �ذ��߰��̵� ��1
	out->dcls_snr = Str2Int(data->dcls_snr, sizeof(data->dcls_snr));	// �����Ϸù�ȣ, ����� �ذ��߰��̵� ��2
	out->dcls_pgnr = Str2Int(data->dcls_pgnr, sizeof(data->dcls_pgnr));	// ���ðǴ� �� ��������
	out->dcls_pg_snr = Str2Int(data->dcls_pg_snr, sizeof(data->dcls_pg_snr));	// ���ðǴ� ������ �Ϸù�ȣ
	memcpy(out->dcls_date, data->dcls_date, sizeof(data->dcls_date));	// ��������, YYYYMMDD
	memcpy(out->trsm_date, data->trsm_date, sizeof(data->trsm_date));	// ��������, YYYYMMDD
	out->dcls_mkt_clsf = data->dcls_mkt_clsf[0];	//���ÿ���屸��, 1:�������� 2:�ڽ��� 3:�Ļ���ǰ 4:ä�� 5:���尨�� 6:�ڳؽ� �ذ��߰��̵� ��3
	memcpy(out->stk_nm, data->stk_nm, sizeof(data->stk_nm));	// �����
	out->proc_clsf = data->proc_clsf[0];	//ó������, 1:���� 2:���� 3:����
	memcpy(out->rsn, data->rsn, sizeof(data->rsn));	// ����, �ذ��߰��̵� ��4
	out->kor_eng_clsf = data->kor_eng_clsf[0];	//������������, 1:���� 2:����
	memcpy(out->dcls_title, data->dcls_title, sizeof(data->dcls_title));	// ��������, TEXT ����
	memcpy(out->dcls_cntt, data->dcls_cntt, sizeof(data->dcls_cntt));	// ���ó���, HTML ����
	out->stk_xst_flg = data->stk_xst_flg[0];	//�������翩��, Y:�����ڵ����� N:�ش���� �ذ�����ü��� �ذ��߰��̵� ��5
	out->dcls_isin_code_flg = data->dcls_isin_code_flg[0];	//���ó��� �����ڵ忩��, Y:�����ڵ� N:���ó��� �ذ������������� �ذ��߰��̵� ��5
	out->nr_isin_code = Str2Int(data->nr_isin_code, sizeof(data->nr_isin_code));	// �����ڵ尹��, 12�ڸ� �����ڵ� ���� �ذ������������� �ذ��߰��̵� ��5

	return 1;
}


// ����(�ǽð�_�ڳؽ�_�ֽ�)
int ParseF0018(const double& timestamp, const char* in_buff, DF_DCLS_RT_KONEX_STK* out) {
	DCLS_RT_KONEX_STK* data = (DCLS_RT_KONEX_STK*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����, E9:���ù�ġ F0:���ýǽð�
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������, 01:�ֽ� 90:��Ÿ
	out->mkt_clsf = data->mkt_clsf[0];	//���屸��, 1:�������� 2:�ڽ��� 8:�ڳؽ� 9:��Ÿ
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// �����ڵ�, �ذ��߰��̵� ��1
	out->dcls_snr = Str2Int(data->dcls_snr, sizeof(data->dcls_snr));	// �����Ϸù�ȣ, ����� �ذ��߰��̵� ��2
	out->dcls_pgnr = Str2Int(data->dcls_pgnr, sizeof(data->dcls_pgnr));	// ���ðǴ� �� ��������
	out->dcls_pg_snr = Str2Int(data->dcls_pg_snr, sizeof(data->dcls_pg_snr));	// ���ðǴ� ������ �Ϸù�ȣ
	memcpy(out->dcls_date, data->dcls_date, sizeof(data->dcls_date));	// ��������, YYYYMMDD
	memcpy(out->trsm_date, data->trsm_date, sizeof(data->trsm_date));	// ��������, YYYYMMDD
	out->dcls_mkt_clsf = data->dcls_mkt_clsf[0];	//���ÿ���屸��, 1:�������� 2:�ڽ��� 3:�Ļ���ǰ 4:ä�� 5:���尨�� 6:�ڳؽ� �ذ��߰��̵� ��3
	memcpy(out->stk_nm, data->stk_nm, sizeof(data->stk_nm));	// �����
	out->proc_clsf = data->proc_clsf[0];	//ó������, 1:���� 2:���� 3:����
	memcpy(out->rsn, data->rsn, sizeof(data->rsn));	// ����, �ذ��߰��̵� ��4
	out->kor_eng_clsf = data->kor_eng_clsf[0];	//������������, 1:���� 2:����
	memcpy(out->dcls_title, data->dcls_title, sizeof(data->dcls_title));	// ��������, TEXT ����
	memcpy(out->dcls_cntt, data->dcls_cntt, sizeof(data->dcls_cntt));	// ���ó���, HTML ����
	out->stk_xst_flg = data->stk_xst_flg[0];	//�������翩��, Y:�����ڵ����� N:�ش���� �ذ�����ü��� �ذ��߰��̵� ��5
	out->dcls_isin_code_flg = data->dcls_isin_code_flg[0];	//���ó��� �����ڵ忩��, Y:�����ڵ� N:���ó��� �ذ������������� �ذ��߰��̵� ��5
	out->nr_isin_code = Str2Int(data->nr_isin_code, sizeof(data->nr_isin_code));	// �����ڵ尹��, 12�ڸ� �����ڵ� ���� �ذ������������� �ذ��߰��̵� ��5

	return 1;
}


// ����(��ġ_�ڽ���_�ֽ�)
int ParseE9011(const double& timestamp, const char* in_buff, DF_DCLS_ARNG_KOSPI_STK* out) {
	DCLS_ARNG_KOSPI_STK* data = (DCLS_ARNG_KOSPI_STK*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����, E9:���ù�ġ F0:���ýǽð�
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������, 01:�ֽ� 90:��Ÿ
	out->mkt_clsf = data->mkt_clsf[0];	//���屸��, 1:�������� 2:�ڽ��� 8:�ڳؽ� 9:��Ÿ
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// �����ڵ�, �ذ��߰��̵� ��1
	out->dcls_snr = Str2Int(data->dcls_snr, sizeof(data->dcls_snr));	// �����Ϸù�ȣ, ����� �ذ��߰��̵� ��2
	out->dcls_pgnr = Str2Int(data->dcls_pgnr, sizeof(data->dcls_pgnr));	// ���ðǴ� �� ��������
	out->dcls_pg_snr = Str2Int(data->dcls_pg_snr, sizeof(data->dcls_pg_snr));	// ���ðǴ� ������ �Ϸù�ȣ
	memcpy(out->dcls_date, data->dcls_date, sizeof(data->dcls_date));	// ��������, YYYYMMDD
	memcpy(out->trsm_date, data->trsm_date, sizeof(data->trsm_date));	// ��������, YYYYMMDD
	out->dcls_mkt_clsf = data->dcls_mkt_clsf[0];	//���ÿ���屸��, 1:�������� 2:�ڽ��� 3:�Ļ���ǰ 4:ä�� 5:���尨�� 6:�ڳؽ� �ذ��߰��̵� ��3
	memcpy(out->stk_nm, data->stk_nm, sizeof(data->stk_nm));	// �����
	out->proc_clsf = data->proc_clsf[0];	//ó������, 1:���� 2:���� 3:����
	memcpy(out->rsn, data->rsn, sizeof(data->rsn));	// ����, �ذ��߰��̵� ��4
	out->kor_eng_clsf = data->kor_eng_clsf[0];	//������������, 1:���� 2:����
	memcpy(out->dcls_title, data->dcls_title, sizeof(data->dcls_title));	// ��������, TEXT ����
	memcpy(out->dcls_cntt, data->dcls_cntt, sizeof(data->dcls_cntt));	// ���ó���, HTML ����
	out->stk_xst_flg = data->stk_xst_flg[0];	//�������翩��, Y:�����ڵ����� N:�ش���� �ذ�����ü��� �ذ��߰��̵� ��5
	out->dcls_isin_code_flg = data->dcls_isin_code_flg[0];	//���ó��� �����ڵ忩��, Y:�����ڵ� N:���ó��� �ذ������������� �ذ��߰��̵� ��5
	out->nr_isin_code = Str2Int(data->nr_isin_code, sizeof(data->nr_isin_code));	// �����ڵ尹��, 12�ڸ� �����ڵ� ���� �ذ������������� �ذ��߰��̵� ��5

	return 1;
}


// ����(��ġ_�ڽ���_�ֽ�)
int ParseE9012(const double& timestamp, const char* in_buff, DF_DCLS_ARNG_KOSDAQ_STK* out) {
	DCLS_ARNG_KOSDAQ_STK* data = (DCLS_ARNG_KOSDAQ_STK*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����, E9:���ù�ġ F0:���ýǽð�
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������, 01:�ֽ� 90:��Ÿ
	out->mkt_clsf = data->mkt_clsf[0];	//���屸��, 1:�������� 2:�ڽ��� 8:�ڳؽ� 9:��Ÿ
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// �����ڵ�, �ذ��߰��̵� ��1
	out->dcls_snr = Str2Int(data->dcls_snr, sizeof(data->dcls_snr));	// �����Ϸù�ȣ, ����� �ذ��߰��̵� ��2
	out->dcls_pgnr = Str2Int(data->dcls_pgnr, sizeof(data->dcls_pgnr));	// ���ðǴ� �� ��������
	out->dcls_pg_snr = Str2Int(data->dcls_pg_snr, sizeof(data->dcls_pg_snr));	// ���ðǴ� ������ �Ϸù�ȣ
	memcpy(out->dcls_date, data->dcls_date, sizeof(data->dcls_date));	// ��������, YYYYMMDD
	memcpy(out->trsm_date, data->trsm_date, sizeof(data->trsm_date));	// ��������, YYYYMMDD
	out->dcls_mkt_clsf = data->dcls_mkt_clsf[0];	//���ÿ���屸��, 1:�������� 2:�ڽ��� 3:�Ļ���ǰ 4:ä�� 5:���尨�� 6:�ڳؽ� �ذ��߰��̵� ��3
	memcpy(out->stk_nm, data->stk_nm, sizeof(data->stk_nm));	// �����
	out->proc_clsf = data->proc_clsf[0];	//ó������, 1:���� 2:���� 3:����
	memcpy(out->rsn, data->rsn, sizeof(data->rsn));	// ����, �ذ��߰��̵� ��4
	out->kor_eng_clsf = data->kor_eng_clsf[0];	//������������, 1:���� 2:����
	memcpy(out->dcls_title, data->dcls_title, sizeof(data->dcls_title));	// ��������, TEXT ����
	memcpy(out->dcls_cntt, data->dcls_cntt, sizeof(data->dcls_cntt));	// ���ó���, HTML ����
	out->stk_xst_flg = data->stk_xst_flg[0];	//�������翩��, Y:�����ڵ����� N:�ش���� �ذ�����ü��� �ذ��߰��̵� ��5
	out->dcls_isin_code_flg = data->dcls_isin_code_flg[0];	//���ó��� �����ڵ忩��, Y:�����ڵ� N:���ó��� �ذ������������� �ذ��߰��̵� ��5
	out->nr_isin_code = Str2Int(data->nr_isin_code, sizeof(data->nr_isin_code));	// �����ڵ尹��, 12�ڸ� �����ڵ� ���� �ذ������������� �ذ��߰��̵� ��5

	return 1;
}


// ����(��ġ_�ڳؽ�_�ֽ�)
int ParseE9018(const double& timestamp, const char* in_buff, DF_DCLS_ARNG_KONEX_STK* out) {
	DCLS_ARNG_KONEX_STK* data = (DCLS_ARNG_KONEX_STK*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����, E9:���ù�ġ F0:���ýǽð�
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������, 01:�ֽ� 90:��Ÿ
	out->mkt_clsf = data->mkt_clsf[0];	//���屸��, 1:�������� 2:�ڽ��� 8:�ڳؽ� 9:��Ÿ
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// �����ڵ�, �ذ��߰��̵� ��1
	out->dcls_snr = Str2Int(data->dcls_snr, sizeof(data->dcls_snr));	// �����Ϸù�ȣ, ����� �ذ��߰��̵� ��2
	out->dcls_pgnr = Str2Int(data->dcls_pgnr, sizeof(data->dcls_pgnr));	// ���ðǴ� �� ��������
	out->dcls_pg_snr = Str2Int(data->dcls_pg_snr, sizeof(data->dcls_pg_snr));	// ���ðǴ� ������ �Ϸù�ȣ
	memcpy(out->dcls_date, data->dcls_date, sizeof(data->dcls_date));	// ��������, YYYYMMDD
	memcpy(out->trsm_date, data->trsm_date, sizeof(data->trsm_date));	// ��������, YYYYMMDD
	out->dcls_mkt_clsf = data->dcls_mkt_clsf[0];	//���ÿ���屸��, 1:�������� 2:�ڽ��� 3:�Ļ���ǰ 4:ä�� 5:���尨�� 6:�ڳؽ� �ذ��߰��̵� ��3
	memcpy(out->stk_nm, data->stk_nm, sizeof(data->stk_nm));	// �����
	out->proc_clsf = data->proc_clsf[0];	//ó������, 1:���� 2:���� 3:����
	memcpy(out->rsn, data->rsn, sizeof(data->rsn));	// ����, �ذ��߰��̵� ��4
	out->kor_eng_clsf = data->kor_eng_clsf[0];	//������������, 1:���� 2:����
	memcpy(out->dcls_title, data->dcls_title, sizeof(data->dcls_title));	// ��������, TEXT ����
	memcpy(out->dcls_cntt, data->dcls_cntt, sizeof(data->dcls_cntt));	// ���ó���, HTML ����
	out->stk_xst_flg = data->stk_xst_flg[0];	//�������翩��, Y:�����ڵ����� N:�ش���� �ذ�����ü��� �ذ��߰��̵� ��5
	out->dcls_isin_code_flg = data->dcls_isin_code_flg[0];	//���ó��� �����ڵ忩��, Y:�����ڵ� N:���ó��� �ذ������������� �ذ��߰��̵� ��5
	out->nr_isin_code = Str2Int(data->nr_isin_code, sizeof(data->nr_isin_code));	// �����ڵ尹��, 12�ڸ� �����ڵ� ���� �ذ������������� �ذ��߰��̵� ��5

	return 1;
}


// ����(��ġ_��Ÿ)
int ParseE9909(const double& timestamp, const char* in_buff, DF_DCLS_ARNG_ETC* out) {
	DCLS_ARNG_ETC* data = (DCLS_ARNG_ETC*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����, E9:���ù�ġ F0:���ýǽð�
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������, 01:�ֽ� 90:��Ÿ
	out->mkt_clsf = data->mkt_clsf[0];	//���屸��, 1:�������� 2:�ڽ��� 8:�ڳؽ� 9:��Ÿ
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// �����ڵ�, �ذ��߰��̵� ��1
	out->dcls_snr = Str2Int(data->dcls_snr, sizeof(data->dcls_snr));	// �����Ϸù�ȣ, ����� �ذ��߰��̵� ��2
	out->dcls_pgnr = Str2Int(data->dcls_pgnr, sizeof(data->dcls_pgnr));	// ���ðǴ� �� ��������
	out->dcls_pg_snr = Str2Int(data->dcls_pg_snr, sizeof(data->dcls_pg_snr));	// ���ðǴ� ������ �Ϸù�ȣ
	memcpy(out->dcls_date, data->dcls_date, sizeof(data->dcls_date));	// ��������, YYYYMMDD
	memcpy(out->trsm_date, data->trsm_date, sizeof(data->trsm_date));	// ��������, YYYYMMDD
	out->dcls_mkt_clsf = data->dcls_mkt_clsf[0];	//���ÿ���屸��, 1:�������� 2:�ڽ��� 3:�Ļ���ǰ 4:ä�� 5:���尨�� 6:�ڳؽ� 7:�Ϲݻ�ǰ E:����� �ذ��߰��̵� ��3
	memcpy(out->stk_nm, data->stk_nm, sizeof(data->stk_nm));	// �����
	out->proc_clsf = data->proc_clsf[0];	//ó������, 1:���� 2:���� 3:����
	memcpy(out->rsn, data->rsn, sizeof(data->rsn));	// ����, �ذ��߰��̵� ��4
	out->kor_eng_clsf = data->kor_eng_clsf[0];	//������������, 1:���� 2:����
	memcpy(out->dcls_title, data->dcls_title, sizeof(data->dcls_title));	// ��������, TEXT ����
	memcpy(out->dcls_cntt, data->dcls_cntt, sizeof(data->dcls_cntt));	// ���ó���, HTML ����
	out->stk_xst_flg = data->stk_xst_flg[0];	//�������翩��, Y:�����ڵ����� N:�ش���� �ذ�����ü��� �ذ��߰��̵� ��5
	out->dcls_isin_code_flg = data->dcls_isin_code_flg[0];	//���ó��� �����ڵ忩��, Y:�����ڵ� N:���ó��� �ذ������������� �ذ��߰��̵� ��5
	out->nr_isin_code = Str2Int(data->nr_isin_code, sizeof(data->nr_isin_code));	// �����ڵ尹��, 12�ڸ� �����ڵ� ���� �ذ������������� �ذ��߰��̵� ��5

	return 1;
}


// ����(�ǽð�_��Ÿ)
int ParseF0909(const double& timestamp, const char* in_buff, DF_DCLS_RT_ETC* out) {
	DCLS_RT_ETC* data = (DCLS_RT_ETC*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����, E9:���ù�ġ F0:���ýǽð�
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������, 01:�ֽ� 90:��Ÿ
	out->mkt_clsf = data->mkt_clsf[0];	//���屸��, 1:�������� 2:�ڽ��� 8:�ڳؽ� 9:��Ÿ
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// �����ڵ�, �ذ��߰��̵� ��1
	out->dcls_snr = Str2Int(data->dcls_snr, sizeof(data->dcls_snr));	// �����Ϸù�ȣ, ����� �ذ��߰��̵� ��2
	out->dcls_pgnr = Str2Int(data->dcls_pgnr, sizeof(data->dcls_pgnr));	// ���ðǴ� �� ��������
	out->dcls_pg_snr = Str2Int(data->dcls_pg_snr, sizeof(data->dcls_pg_snr));	// ���ðǴ� ������ �Ϸù�ȣ
	memcpy(out->dcls_date, data->dcls_date, sizeof(data->dcls_date));	// ��������, YYYYMMDD
	memcpy(out->trsm_date, data->trsm_date, sizeof(data->trsm_date));	// ��������, YYYYMMDD
	out->dcls_mkt_clsf = data->dcls_mkt_clsf[0];	//���ÿ���屸��, 1:�������� 2:�ڽ��� 3:�Ļ���ǰ 4:ä�� 5:���尨�� 6:�ڳؽ� 7:�Ϲݻ�ǰ E:����� �ذ��߰��̵� ��3
	memcpy(out->stk_nm, data->stk_nm, sizeof(data->stk_nm));	// �����
	out->proc_clsf = data->proc_clsf[0];	//ó������, 1:���� 2:���� 3:����
	memcpy(out->rsn, data->rsn, sizeof(data->rsn));	// ����, �ذ��߰��̵� ��4
	out->kor_eng_clsf = data->kor_eng_clsf[0];	//������������, 1:���� 2:����
	memcpy(out->dcls_title, data->dcls_title, sizeof(data->dcls_title));	// ��������, TEXT ����
	memcpy(out->dcls_cntt, data->dcls_cntt, sizeof(data->dcls_cntt));	// ���ó���, HTML ����
	out->stk_xst_flg = data->stk_xst_flg[0];	//�������翩��, Y:�����ڵ����� N:�ش���� �ذ�����ü��� �ذ��߰��̵� ��5
	out->dcls_isin_code_flg = data->dcls_isin_code_flg[0];	//���ó��� �����ڵ忩��, Y:�����ڵ� N:���ó��� �ذ������������� �ذ��߰��̵� ��5
	out->nr_isin_code = Str2Int(data->nr_isin_code, sizeof(data->nr_isin_code));	// �����ڵ尹��, 12�ڸ� �����ڵ� ���� �ذ������������� �ذ��߰��̵� ��5

	return 1;
}
