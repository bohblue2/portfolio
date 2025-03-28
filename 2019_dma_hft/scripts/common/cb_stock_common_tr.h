// cb_stock_common_tr.h
// �ֽ� ����

#pragma once
// �ּ��� \n�� ���� ���߿� �̻ڰ� �ٲ����


// ������ ����
typedef struct _STOCK_INV_INFO {
	char inv_code[4];	// �������ڵ�, ���ڵ尪���� ����\n*�ڵ�'7000'�� ����, ������� �׸� 0���� ���� (20181210)
	char ask_ccls_qty[12];	// �ŵ�ü�����, ����:��
	char ask_trd_val[18];	// �ŵ��ŷ����, ����:��
	char bid_ccls_qty[12];	// �ż�ü�����, ����:��
	char bid_trd_val[18];	// �ż��ŷ����, ����:��
} STOCK_INV_INFO;


// �ŷ��� ����
typedef struct _STOCK_SRC_INFO {
	char ask_src_nr[5];	// �ŵ��ŷ�����ȣ
	char ask_ccls_qty[12];	// �ŵ�ü�����, ����:��
	char ask_trd_val[18];	// �ŵ��ŷ����, ����:��
	char bid_src_nr[5];	// �ż��ŷ�����ȣ
	char bid_ccls_qty[12];	// �ż�ü�����, ����:��
	char bid_trd_val[18];	// �ż��ŷ����, ����:��
} STOCK_SRC_INFO;


// ȣ�� ���� (LP������)
typedef struct _STOCK_LOB_INFO {
	char ask_prc[9];	// �ŵ�ȣ��
	char bid_prc[9];	// �ż�ȣ��
	char ask_vol_rsd[12];	// �ŵ�ȣ�� �ܷ�
	char bid_vol_rsd[12];	// �ż�ȣ�� �ܷ�
} STOCK_LOB_INFO;


// ȣ�� ���� (LP����)
typedef struct _STOCK_LOB_INFO_WITH_LP {
	char ask_prc[9];	// �ŵ�ȣ��
	char bid_prc[9];	// �ż�ȣ��
	char ask_vol_rsd[12];	// �ŵ�ȣ�� �ܷ�
	char bid_vol_rsd[12];	// �ż�ȣ�� �ܷ�
	char lp_ask_vol_rsd[12];	// LP �ŵ�ȣ�� �ܷ�
	char lp_bid_vol_rsd[12];	// LP �ż�ȣ�� �ܷ�
} STOCK_LOB_INFO_WITH_LP;


// ����(�ǽð�_�ڽ���_�ֽ�)
typedef struct _DCLS_RT_KOSPI_STK {
	char data_clsf[2];	// DATA����, E9:���ù�ġ F0:���ýǽð�
	char info_clsf[2];	// ��������, 01:�ֽ� 90:��Ÿ
	char mkt_clsf[1];	// ���屸��, 1:�������� 2:�ڽ��� 8:�ڳؽ� 9:��Ÿ
	char isin_code[12];	// �����ڵ�, �ذ��߰��̵� ��1
	char dcls_snr[6];	// �����Ϸù�ȣ, ����� �ذ��߰��̵� ��2
	char dcls_pgnr[5];	// ���ðǴ� �� ��������
	char dcls_pg_snr[5];	// ���ðǴ� ������ �Ϸù�ȣ
	char dcls_date[8];	// ��������, YYYYMMDD
	char trsm_date[8];	// ��������, YYYYMMDD
	char dcls_mkt_clsf[1];	// ���ÿ���屸��, 1:�������� 2:�ڽ��� 3:�Ļ���ǰ 4:ä�� 5:���尨�� 6:�ڳؽ� �ذ��߰��̵� ��3
	char stk_nm[40];	// �����
	char proc_clsf[1];	// ó������, 1:���� 2:���� 3:����
	char rsn[5];	// ����, �ذ��߰��̵� ��4
	char kor_eng_clsf[1];	// ������������, 1:���� 2:����
	char dcls_title[264];	// ��������, TEXT ����
	char dcls_cntt[1000];	// ���ó���, HTML ����
	char stk_xst_flg[1];	// �������翩��, Y:�����ڵ����� N:�ش���� �ذ�����ü��� �ذ��߰��̵� ��5
	char dcls_isin_code_flg[1];	// ���ó��� �����ڵ忩��, Y:�����ڵ� N:���ó��� �ذ������������� �ذ��߰��̵� ��5
	char nr_isin_code[2];	// �����ڵ尹��, 12�ڸ� �����ڵ� ���� �ذ������������� �ذ��߰��̵� ��5
	char filler[8];	// FILLER, SPACE 2->8
	char ff[1];	// FF, END OF TEXT (0xFF)
} DCLS_RT_KOSPI_STK;


// ����(�ǽð�_�ڽ���_�ֽ�)
typedef struct _DCLS_RT_KOSDAQ_STK {
	char data_clsf[2];	// DATA����, E9:���ù�ġ F0:���ýǽð�
	char info_clsf[2];	// ��������, 01:�ֽ� 90:��Ÿ
	char mkt_clsf[1];	// ���屸��, 1:�������� 2:�ڽ��� 8:�ڳؽ� 9:��Ÿ
	char isin_code[12];	// �����ڵ�, �ذ��߰��̵� ��1
	char dcls_snr[6];	// �����Ϸù�ȣ, ����� �ذ��߰��̵� ��2
	char dcls_pgnr[5];	// ���ðǴ� �� ��������
	char dcls_pg_snr[5];	// ���ðǴ� ������ �Ϸù�ȣ
	char dcls_date[8];	// ��������, YYYYMMDD
	char trsm_date[8];	// ��������, YYYYMMDD
	char dcls_mkt_clsf[1];	// ���ÿ���屸��, 1:�������� 2:�ڽ��� 3:�Ļ���ǰ 4:ä�� 5:���尨�� 6:�ڳؽ� �ذ��߰��̵� ��3
	char stk_nm[40];	// �����
	char proc_clsf[1];	// ó������, 1:���� 2:���� 3:����
	char rsn[5];	// ����, �ذ��߰��̵� ��4
	char kor_eng_clsf[1];	// ������������, 1:���� 2:����
	char dcls_title[264];	// ��������, TEXT ����
	char dcls_cntt[1000];	// ���ó���, HTML ����
	char stk_xst_flg[1];	// �������翩��, Y:�����ڵ����� N:�ش���� �ذ�����ü��� �ذ��߰��̵� ��5
	char dcls_isin_code_flg[1];	// ���ó��� �����ڵ忩��, Y:�����ڵ� N:���ó��� �ذ������������� �ذ��߰��̵� ��5
	char nr_isin_code[2];	// �����ڵ尹��, 12�ڸ� �����ڵ� ���� �ذ������������� �ذ��߰��̵� ��5
	char filler[8];	// FILLER, SPACE
	char ff[1];	// FF, END OF TEXT (0xFF)
} DCLS_RT_KOSDAQ_STK;


// ����(�ǽð�_�ڳؽ�_�ֽ�)
typedef struct _DCLS_RT_KONEX_STK {
	char data_clsf[2];	// DATA����, E9:���ù�ġ F0:���ýǽð�
	char info_clsf[2];	// ��������, 01:�ֽ� 90:��Ÿ
	char mkt_clsf[1];	// ���屸��, 1:�������� 2:�ڽ��� 8:�ڳؽ� 9:��Ÿ
	char isin_code[12];	// �����ڵ�, �ذ��߰��̵� ��1
	char dcls_snr[6];	// �����Ϸù�ȣ, ����� �ذ��߰��̵� ��2
	char dcls_pgnr[5];	// ���ðǴ� �� ��������
	char dcls_pg_snr[5];	// ���ðǴ� ������ �Ϸù�ȣ
	char dcls_date[8];	// ��������, YYYYMMDD
	char trsm_date[8];	// ��������, YYYYMMDD
	char dcls_mkt_clsf[1];	// ���ÿ���屸��, 1:�������� 2:�ڽ��� 3:�Ļ���ǰ 4:ä�� 5:���尨�� 6:�ڳؽ� �ذ��߰��̵� ��3
	char stk_nm[40];	// �����
	char proc_clsf[1];	// ó������, 1:���� 2:���� 3:����
	char rsn[5];	// ����, �ذ��߰��̵� ��4
	char kor_eng_clsf[1];	// ������������, 1:���� 2:����
	char dcls_title[264];	// ��������, TEXT ����
	char dcls_cntt[1000];	// ���ó���, HTML ����
	char stk_xst_flg[1];	// �������翩��, Y:�����ڵ����� N:�ش���� �ذ�����ü��� �ذ��߰��̵� ��5
	char dcls_isin_code_flg[1];	// ���ó��� �����ڵ忩��, Y:�����ڵ� N:���ó��� �ذ������������� �ذ��߰��̵� ��5
	char nr_isin_code[2];	// �����ڵ尹��, 12�ڸ� �����ڵ� ���� �ذ������������� �ذ��߰��̵� ��5
	char filler[8];	// FILLER, SPACE
	char ff[1];	// FF, END OF TEXT (0xFF)
} DCLS_RT_KONEX_STK;


// ����(��ġ_�ڽ���_�ֽ�)
typedef struct _DCLS_ARNG_KOSPI_STK {
	char data_clsf[2];	// DATA����, E9:���ù�ġ F0:���ýǽð�
	char info_clsf[2];	// ��������, 01:�ֽ� 90:��Ÿ
	char mkt_clsf[1];	// ���屸��, 1:�������� 2:�ڽ��� 8:�ڳؽ� 9:��Ÿ
	char isin_code[12];	// �����ڵ�, �ذ��߰��̵� ��1
	char dcls_snr[6];	// �����Ϸù�ȣ, ����� �ذ��߰��̵� ��2
	char dcls_pgnr[5];	// ���ðǴ� �� ��������
	char dcls_pg_snr[5];	// ���ðǴ� ������ �Ϸù�ȣ
	char dcls_date[8];	// ��������, YYYYMMDD
	char trsm_date[8];	// ��������, YYYYMMDD
	char dcls_mkt_clsf[1];	// ���ÿ���屸��, 1:�������� 2:�ڽ��� 3:�Ļ���ǰ 4:ä�� 5:���尨�� 6:�ڳؽ� �ذ��߰��̵� ��3
	char stk_nm[40];	// �����
	char proc_clsf[1];	// ó������, 1:���� 2:���� 3:����
	char rsn[5];	// ����, �ذ��߰��̵� ��4
	char kor_eng_clsf[1];	// ������������, 1:���� 2:����
	char dcls_title[264];	// ��������, TEXT ����
	char dcls_cntt[1000];	// ���ó���, HTML ����
	char stk_xst_flg[1];	// �������翩��, Y:�����ڵ����� N:�ش���� �ذ�����ü��� �ذ��߰��̵� ��5
	char dcls_isin_code_flg[1];	// ���ó��� �����ڵ忩��, Y:�����ڵ� N:���ó��� �ذ������������� �ذ��߰��̵� ��5
	char nr_isin_code[2];	// �����ڵ尹��, 12�ڸ� �����ڵ� ���� �ذ������������� �ذ��߰��̵� ��5
	char filler[8];	// FILLER, SPACE
	char ff[1];	// FF, END OF TEXT (0xFF)
} DCLS_ARNG_KOSPI_STK;


// ����(��ġ_�ڽ���_�ֽ�)
typedef struct _DCLS_ARNG_KOSDAQ_STK {
	char data_clsf[2];	// DATA����, E9:���ù�ġ F0:���ýǽð�
	char info_clsf[2];	// ��������, 01:�ֽ� 90:��Ÿ
	char mkt_clsf[1];	// ���屸��, 1:�������� 2:�ڽ��� 8:�ڳؽ� 9:��Ÿ
	char isin_code[12];	// �����ڵ�, �ذ��߰��̵� ��1
	char dcls_snr[6];	// �����Ϸù�ȣ, ����� �ذ��߰��̵� ��2
	char dcls_pgnr[5];	// ���ðǴ� �� ��������
	char dcls_pg_snr[5];	// ���ðǴ� ������ �Ϸù�ȣ
	char dcls_date[8];	// ��������, YYYYMMDD
	char trsm_date[8];	// ��������, YYYYMMDD
	char dcls_mkt_clsf[1];	// ���ÿ���屸��, 1:�������� 2:�ڽ��� 3:�Ļ���ǰ 4:ä�� 5:���尨�� 6:�ڳؽ� �ذ��߰��̵� ��3
	char stk_nm[40];	// �����
	char proc_clsf[1];	// ó������, 1:���� 2:���� 3:����
	char rsn[5];	// ����, �ذ��߰��̵� ��4
	char kor_eng_clsf[1];	// ������������, 1:���� 2:����
	char dcls_title[264];	// ��������, TEXT ����
	char dcls_cntt[1000];	// ���ó���, HTML ����
	char stk_xst_flg[1];	// �������翩��, Y:�����ڵ����� N:�ش���� �ذ�����ü��� �ذ��߰��̵� ��5
	char dcls_isin_code_flg[1];	// ���ó��� �����ڵ忩��, Y:�����ڵ� N:���ó��� �ذ������������� �ذ��߰��̵� ��5
	char nr_isin_code[2];	// �����ڵ尹��, 12�ڸ� �����ڵ� ���� �ذ������������� �ذ��߰��̵� ��5
	char filler[8];	// FILLER, SPACE
	char ff[1];	// FF, END OF TEXT (0xFF)
} DCLS_ARNG_KOSDAQ_STK;


// ����(��ġ_�ڳؽ�_�ֽ�)
typedef struct _DCLS_ARNG_KONEX_STK {
	char data_clsf[2];	// DATA����, E9:���ù�ġ F0:���ýǽð�
	char info_clsf[2];	// ��������, 01:�ֽ� 90:��Ÿ
	char mkt_clsf[1];	// ���屸��, 1:�������� 2:�ڽ��� 8:�ڳؽ� 9:��Ÿ
	char isin_code[12];	// �����ڵ�, �ذ��߰��̵� ��1
	char dcls_snr[6];	// �����Ϸù�ȣ, ����� �ذ��߰��̵� ��2
	char dcls_pgnr[5];	// ���ðǴ� �� ��������
	char dcls_pg_snr[5];	// ���ðǴ� ������ �Ϸù�ȣ
	char dcls_date[8];	// ��������, YYYYMMDD
	char trsm_date[8];	// ��������, YYYYMMDD
	char dcls_mkt_clsf[1];	// ���ÿ���屸��, 1:�������� 2:�ڽ��� 3:�Ļ���ǰ 4:ä�� 5:���尨�� 6:�ڳؽ� �ذ��߰��̵� ��3
	char stk_nm[40];	// �����
	char proc_clsf[1];	// ó������, 1:���� 2:���� 3:����
	char rsn[5];	// ����, �ذ��߰��̵� ��4
	char kor_eng_clsf[1];	// ������������, 1:���� 2:����
	char dcls_title[264];	// ��������, TEXT ����
	char dcls_cntt[1000];	// ���ó���, HTML ����
	char stk_xst_flg[1];	// �������翩��, Y:�����ڵ����� N:�ش���� �ذ�����ü��� �ذ��߰��̵� ��5
	char dcls_isin_code_flg[1];	// ���ó��� �����ڵ忩��, Y:�����ڵ� N:���ó��� �ذ������������� �ذ��߰��̵� ��5
	char nr_isin_code[2];	// �����ڵ尹��, 12�ڸ� �����ڵ� ���� �ذ������������� �ذ��߰��̵� ��5
	char filler[8];	// FILLER, SPACE
	char ff[1];	// FF, END OF TEXT (0xFF)
} DCLS_ARNG_KONEX_STK;


// ����(��ġ_��Ÿ)
typedef struct _DCLS_ARNG_ETC {
	char data_clsf[2];	// DATA����, E9:���ù�ġ F0:���ýǽð�
	char info_clsf[2];	// ��������, 01:�ֽ� 90:��Ÿ
	char mkt_clsf[1];	// ���屸��, 1:�������� 2:�ڽ��� 8:�ڳؽ� 9:��Ÿ
	char isin_code[12];	// �����ڵ�, �ذ��߰��̵� ��1
	char dcls_snr[6];	// �����Ϸù�ȣ, ����� �ذ��߰��̵� ��2
	char dcls_pgnr[5];	// ���ðǴ� �� ��������
	char dcls_pg_snr[5];	// ���ðǴ� ������ �Ϸù�ȣ
	char dcls_date[8];	// ��������, YYYYMMDD
	char trsm_date[8];	// ��������, YYYYMMDD
	char dcls_mkt_clsf[1];	// ���ÿ���屸��, 1:�������� 2:�ڽ��� 3:�Ļ���ǰ 4:ä�� 5:���尨�� 6:�ڳؽ� 7:�Ϲݻ�ǰ E:����� �ذ��߰��̵� ��3
	char stk_nm[40];	// �����
	char proc_clsf[1];	// ó������, 1:���� 2:���� 3:����
	char rsn[5];	// ����, �ذ��߰��̵� ��4
	char kor_eng_clsf[1];	// ������������, 1:���� 2:����
	char dcls_title[264];	// ��������, TEXT ����
	char dcls_cntt[1000];	// ���ó���, HTML ����
	char stk_xst_flg[1];	// �������翩��, Y:�����ڵ����� N:�ش���� �ذ�����ü��� �ذ��߰��̵� ��5
	char dcls_isin_code_flg[1];	// ���ó��� �����ڵ忩��, Y:�����ڵ� N:���ó��� �ذ������������� �ذ��߰��̵� ��5
	char nr_isin_code[2];	// �����ڵ尹��, 12�ڸ� �����ڵ� ���� �ذ������������� �ذ��߰��̵� ��5
	char filler[8];	// FILLER, SPACE
	char ff[1];	// FF, END OF TEXT (0xFF)
} DCLS_ARNG_ETC;


// ����(�ǽð�_��Ÿ)
typedef struct _DCLS_RT_ETC {
	char data_clsf[2];	// DATA����, E9:���ù�ġ F0:���ýǽð�
	char info_clsf[2];	// ��������, 01:�ֽ� 90:��Ÿ
	char mkt_clsf[1];	// ���屸��, 1:�������� 2:�ڽ��� 8:�ڳؽ� 9:��Ÿ
	char isin_code[12];	// �����ڵ�, �ذ��߰��̵� ��1
	char dcls_snr[6];	// �����Ϸù�ȣ, ����� �ذ��߰��̵� ��2
	char dcls_pgnr[5];	// ���ðǴ� �� ��������
	char dcls_pg_snr[5];	// ���ðǴ� ������ �Ϸù�ȣ
	char dcls_date[8];	// ��������, YYYYMMDD
	char trsm_date[8];	// ��������, YYYYMMDD
	char dcls_mkt_clsf[1];	// ���ÿ���屸��, 1:�������� 2:�ڽ��� 3:�Ļ���ǰ 4:ä�� 5:���尨�� 6:�ڳؽ� 7:�Ϲݻ�ǰ E:����� �ذ��߰��̵� ��3
	char stk_nm[40];	// �����
	char proc_clsf[1];	// ó������, 1:���� 2:���� 3:����
	char rsn[5];	// ����, �ذ��߰��̵� ��4
	char kor_eng_clsf[1];	// ������������, 1:���� 2:����
	char dcls_title[264];	// ��������, TEXT ����
	char dcls_cntt[1000];	// ���ó���, HTML ����
	char stk_xst_flg[1];	// �������翩��, Y:�����ڵ����� N:�ش���� �ذ�����ü��� �ذ��߰��̵� ��5
	char dcls_isin_code_flg[1];	// ���ó��� �����ڵ忩��, Y:�����ڵ� N:���ó��� �ذ������������� �ذ��߰��̵� ��5
	char nr_isin_code[2];	// �����ڵ尹��, 12�ڸ� �����ڵ� ���� �ذ������������� �ذ��߰��̵� ��5
	char filler[8];	// FILLER, SPACE
	char ff[1];	// FF, END OF TEXT (0xFF)
} DCLS_RT_ETC;
