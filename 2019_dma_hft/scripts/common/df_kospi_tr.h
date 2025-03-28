// df_kospi_tr.h
// ���������ֽ� �ǽð� TR

#pragma once
// �ּ��� \n�� ���� ���߿� �̻ڰ� �ٲ����

#include "df_stock_common_tr.h"


// KRX 300 TR��������
typedef struct _DF_KRX300_TR_EXP_IDX {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����, �ذ��߰��̵� ����
	char info_clsf[3];	// ��������, 01:�ֽ�
	char mkt_clsf;	// ���屸��, 1:�������� 2:�ڽ��� 9:�ؿ��ְ����� 2012.04.30 �߰�
	char ind_clsf[4];	// �����ڵ�, �ذ��߰��̵� ����
	char time[7];	// �ð�, �ذ��߰��̵� ���� ���ؿ��ְ������� ��� GMT�ð�
	double idx;	// ����, 9(6)V9(2)
	double crst;	// ���, 999999V99
	int ccls_qty;	// ü�����, ����:õ�� ���ؿ��ְ������� ��� FILLERó��
	int trd_val;	// �ŷ����, ����:�鸸�� ���ؿ��ְ������� ��� FILLERó��
} DF_KRX300_TR_EXP_IDX;


// KRX 300 TR����
typedef struct _DF_KRX300_TR_IDX {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����, �ذ��߰��̵� ����
	char info_clsf[3];	// ��������, 01:�ֽ�
	char mkt_clsf;	// ���屸��, 1:�������� 2:�ڽ��� 9:�ؿ��ְ����� 2012.04.30 �߰�
	char ind_clsf[4];	// �����ڵ�, �ذ��߰��̵� ����
	char time[7];	// �ð�, �ذ��߰��̵� ���� ���ؿ��ְ������� ��� GMT�ð�
	double idx;	// ����, 9(6)V9(2)
	double crst;	// ���, 999999V99
	int ccls_qty;	// ü�����, ����:õ�� ���ؿ��ְ������� ��� FILLERó��
	int trd_val;	// �ŷ����, ����:�鸸�� ���ؿ��ְ������� ��� FILLERó��
} DF_KRX300_TR_IDX;


// �ڽ��� TR��������
typedef struct _DF_KOSPI_TR_EXP_IDX {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����, �ذ��߰��̵� ����
	char info_clsf[3];	// ��������, 01:�ֽ�
	char mkt_clsf;	// ���屸��, 1:�������� 2:�ڽ��� 9:�ؿ��ְ����� 2012.04.30 �߰�
	char ind_clsf[4];	// �����ڵ�, �ذ��߰��̵� ����
	char time[7];	// �ð�, �ذ��߰��̵� ���� ���ؿ��ְ������� ��� GMT�ð�
	double idx;	// ����, 9(6)V9(2)
	double crst;	// ���, 999999V99
	int ccls_qty;	// ü�����, ����:õ�� ���ؿ��ְ������� ��� FILLERó��
	int trd_val;	// �ŷ����, ����:�鸸�� ���ؿ��ְ������� ��� FILLERó��
} DF_KOSPI_TR_EXP_IDX;


// �ڽ��� TR����
typedef struct _DF_KOSPI_TR_IDX {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����, �ذ��߰��̵� ����
	char info_clsf[3];	// ��������, 01:�ֽ�
	char mkt_clsf;	// ���屸��, 1:�������� 2:�ڽ��� 9:�ؿ��ְ����� 2012.04.30 �߰�
	char ind_clsf[4];	// �����ڵ�, �ذ��߰��̵� ����
	char time[7];	// �ð�, �ذ��߰��̵� ���� ���ؿ��ְ������� ��� GMT�ð�
	double idx;	// ����, 9(6)V9(2)
	double crst;	// ���, 999999V99
	int ccls_qty;	// ü�����, ����:õ�� ���ؿ��ְ������� ��� FILLERó��
	int trd_val;	// �ŷ����, ����:�鸸�� ���ؿ��ְ������� ��� FILLERó��
} DF_KOSPI_TR_IDX;


// KRX300��������
typedef struct _DF_KRX300_EXP_IDX {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����, �ذ��߰��̵� ����
	char info_clsf[3];	// ��������, 01:�ֽ�
	char mkt_clsf;	// ���屸��, 1:�������� 2:�ڽ��� 9:�ؿ��ְ����� 2012.04.30 �߰�
	char ind_clsf[4];	// �����ڵ�, �ذ��߰��̵� ����
	char time[7];	// �ð�, �ذ��߰��̵� ���� ���ؿ��ְ������� ��� GMT�ð�
	double idx;	// ����, 9(6)V9(2)
	double crst;	// ���, 999999V99
	int ccls_qty;	// ü�����, ����:õ�� ���ؿ��ְ������� ��� FILLERó��
	int trd_val;	// �ŷ����, ����:�鸸�� ���ؿ��ְ������� ��� FILLERó��
} DF_KRX300_EXP_IDX;


// KRX300����
typedef struct _DF_KRX300_IDX {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����, �ذ��߰��̵� ����
	char info_clsf[3];	// ��������, 01:�ֽ�
	char mkt_clsf;	// ���屸��, 1:�������� 2:�ڽ��� 9:�ؿ��ְ����� 2012.04.30 �߰�
	char ind_clsf[4];	// �����ڵ�, �ذ��߰��̵� ����
	char time[7];	// �ð�, �ذ��߰��̵� ���� ���ؿ��ְ������� ��� GMT�ð�
	double idx; // ����, 9(6)V9(2)
	double crst;	// ���, 999999V99
	int ccls_qty;	// ü�����, ����:õ�� ���ؿ��ְ������� ��� FILLERó��
	int trd_val;	// �ŷ����, ����:�鸸�� ���ؿ��ְ������� ��� FILLERó��
} DF_KRX300_IDX;


// �ڽ���_���� �̺�Ʈ ����
typedef struct _DF_KOSPI_STK_EVT_INFO {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����, I6
	char info_clsf[3];	// ��������, 01:�ֽ�
	char mkt_clsf;	// ���屸��, 1:�������� 2:�ڽ���
	char isin_code[13];	// �����ڵ�, ǥ���ڵ�
	int snr;	// �Ϸù�ȣ, 1~99999999 �Ǽ�üũ��
	char evt_code[3];	// �̺�Ʈ�����ڵ�, 01:�ŷ����� \n02:�������� \n03:�Ҽ��ǰ��ù��� \n04:�����Ÿ�\n05:��ȸ���� \n06:�������ȿ������ \n07:���豸���췮���\n08:���԰��ŵ��Ұ� \n09:Regulation S \n10:���ı������\n11:��������ȯ������\n12:�ܱ�������� (2012.11.05�߰�)\n13:���� (2016.06.27�߰�)\n14:�������������� (2016.06.27�߰�)\n15:��������ä�� (2016.11.28�߰�)\n16:�̻�޵����� (2017.03.27�߰�)\n17:���ŵ��������� (2017.03.27 �߰�)\n18: LP������ (2017.06.26 �߰�)
	char evt_trgg_code[5];	// �̺�Ʈ�߻������ڵ�, �� ��÷ �ڵ尩������ �̺�Ʈ�������ڵ� ����\n�� �̺�Ʈ�����ڵ� 03,04,07,08,09,17�� ���ؼ��� '0000' SET\n�� �ڵ��� ������ ���� �ڸ����� �ٸ��ϴ�. ������ Ÿ����\nX��� �̱� ������ �������ĵ˴ϴ�. ���� �����Ͽ� �ֽʽÿ�.\n(�ŷ����������ڵ�(3�ڸ�), �����������������ڵ�(4�ڸ�),\n��ȸ���������ڵ�(1�ڸ�), �������ȿ�����������ڵ�(2�ڸ�),\n��������ȯ����������ڵ�(4�ڸ�))
	char st_date[9];	// ��������,��������,��������, YYYYMMDD
	char ed_date[9];	// ��������,��������, YYYYMMDD
} DF_KOSPI_STK_EVT_INFO;


// �ڽ���_�����ġ
typedef struct _DF_KOSPI_STK_ARNG {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����, A0
	char info_clsf[3];	// ��������, 01:�ֽ�
	char mkt_clsf;	// ���屸��, 1:�������� 2:�ڽ���
	char isin_code[13];	// �����ڵ�, ǥ���ڵ�
	int snr;	// �Ϸù�ȣ, 1~99999999 �Ǽ�üũ��
	char sh_code[10];	// �����ڵ�, �ֽ�7�ڸ�(DR����) ��������9�ڸ�
	char kor_abbr[41];	// �����ѱ۾��
	char eng_abbr[41];	// ���񿵹����
	char opr_date[9];	// ��������, YYYYMMDD
	char info_allc_nr[6];	// �����й�׷��ȣ
	char stk_gr_id[3];	// ���Ǳ׷�ID, ST:�ֱ� MF:��������ȸ�� RT:�ε�������ȸ�� \nSC:��������ȸ��\nIF:��ȸ�����ں�������ȸ�� DR:�ֽĿ�Ź���� EW:ELW EF:ETF\nSW:�����μ������� SR:�����μ������� BC:�������� \nFE:�ؿ�ETF FS:�ܱ��ֱ� \nEN:ETN 2014.11.17
	char unit_trd_ccls_flg;	// �����Ÿ�ü�Ῡ��, Y, N (�����忡�� �����ð� ����ü�Ῡ��)
	char lock_clsf_code[3];	// �������ڵ�, 00:�ش���׾���(���� �߻����� ���) \n01:�Ǹ��� \n02:����\n03:�й�� \n04:�ǹ�� \n05:�߰�(�б�)����\n(2017.11.20 ����:�߰�����->�߰�(�б�)����)\n06:�Ǹ��߰�����\n07:�Ǹ��б����\n(2017.11.20 �߰�)\n99:��Ÿ ��SW,SR,EW�� ���ش�(���ش��� ��� SPACE)
	char pval_chg_clsf_code[3];	// �׸鰡���汸���ڵ�, 00:�ش����(�׸鰡������ ������ �� �ִ� ���񱺿� ���� ����\n������ �ǹ�) 01:�׸���� 02:�׸麴�� 03:�ֽĺ��� 04:�ֽĺ��� 99:��Ÿ\n(2012.08.27)
	char open_base_prc_stk_flg;	// �ð����ذ������񿩺�, Y, N ��Y�� ���:�ű�����,�������,������,��Ⱓ�ŷ�����
	char rassm_stk_rsn_code[3];	// ������������ڵ�, 00:�ش����, 01:ȸ�����, 02:�ں�����, 03:��Ⱓ����,\n04:�ʰ��й�, 05:��Ը��� \n06: ȸ������պ�, 99:��Ÿ \n�����Ǳ׷�ID ST,FS�� �ش�(���ش��� ��� SPACE)\n2011.02.28 ���а� �߰�(04:�ʰ��й�, 05:��Ը���)\n2012.08.27 ���ǿ�������(02:�ֽĺ���->02:�ں�����) \n2017.06.26 ���а� ����(01:������� -> 01:ȸ�����)\n2017.06.26 ���а� �߰�(06:ȸ������պ�)
	char base_prc_chg_stk_flg;	// ���ذ��ݺ������񿩺�, Y, N ��Y�� ���:����,�׸麯��,���� ��
	char rndn_cls_trgg_cond_code;	// ��������ߵ������ڵ�, ���ϰ��������� ���������� �ߵ�����.���Ǻιߵ�(2)�ΰ�� ���������Ģ���� �����ϴ� ���ݿ���� �����ϴ��� �Ǵ� �� �ߵ��� ������.\n##�ڵ尪##\n0:�̹ߵ� 1:�ߵ� 2:���Ǻιߵ�(���ݿ���Ǵ�)
	char mkt_alm_warn_fcst_flg;	// ����溸�������, Y, N\n 2015.06.15:"����溸���迹����(Y,N)"->"����溸�������(Y,N)" �׸񺯰�
	char mkt_alrm_clsf_code[3];	// ����溸�����ڵ�, 00:�ش����(����溸�� ������ �� �ִ� ���� ���ؼ� ������\n�ٰ� ������ �ǹ�) 01:�������� 02:���ڰ�� 03:��������
	char cogv_hlth_flg;	// ���豸���췮����, Y, N ���ڽ��ڸ� �ش�, ST,FS,DR,MF,EF�� �ش�
	char ifam_flg;	// �������񿩺�, Y, N
	char iscnt_flg;	// �Ҽ��ǰ�����������, Y, N
	char bdlt_flg;	// ��ȸ���忩��, Y, N
	char trsp_flg;	// �ŷ���������, Y, N
	char ind_lclsf_code[4];	// ����������з��ڵ�, (����)000:�����̺з� ������������ ������� ����\n(�ڽ���)000:�����̺з�/���߾��ݵ� 008~014:�Ϲ� 015:IT\n�����Ǳ׷�ID ST,MF,RT,SC,IF�� �ش�
	char ind_mclsf_code[4];	// ���������ߺз��ڵ�, (����)000:�����̺з�\n(�ڽ���)000:�����̺з� 021~040:�Ϲ� 041~043:IT\n�����Ǳ׷�ID ST,MF,RT,SC,IF�� �ش�
	char ind_sclsf_code[4];	// ���������Һз��ڵ�, (����)000:�����̺з�\n(�ڽ���)000:�����̺з� 050~112:�Ϲ� 151~160:IT\n�����Ǳ׷�ID ST,MF,RT,SC,IF�� �ش�
	char ind_id[11];	// ����ID, ����(Type Of Industry)ID 2014.03.03\n*����Ī:ǥ�ػ���ڵ�\n6�ڸ� ǥ�ػ���ڵ�� ������Ǹ� ������ �� �־� �ؿܻ���Ʈ�� �پ��� �����ڵ� ������ �Ұ��Ͽ� 10�ڸ��� Ȯ��. ���� ǥ�ػ���ڵ�� �״�� 1:1 ���εǾ� ������ 4�ڸ��� �����̽��� ä��
	char kospi200_str_ind;	// KOSPI200���;���, (����)\n0:�����̺з�, 1:�Ǽ�, 2:�߰���,\n3:ö������,\n4:������ȭ��, 5:�������, 6:����, 7:�ʼ��Һ���,\n8: �����Һ��� 9:����� A:�ǰ����� B:Ŀ�´����̼Ǽ���\n- KOSPI200���� �� ���;��� ��������(2011.04.01)\n�����Ǳ׷�ID ST,MF,RT,SC,IF�� �ش�\n\n- �űԾ����߰�(�����,�ǰ�����) �� ����������Ī����(�Ǽ�,�߰���)(2015.07.13) \n- �űԾ����߰�(Ŀ�´����̼Ǽ���(2018.10.22)\n\n(�ڽ���) �ش���׾���.
	char mkt_cap_code;	// �ð��ѾױԸ��ڵ�, ����(0:���� 1:�� 2:�� 3:��)\n�ڽ���(0:���� 1:KOSDAQ100 2:KOSDAQmid300 3:KOSDAQsmall)\n�����Ǳ׷�ID ST,MF,RT,SC,IF�� �ش�
	char mnft_ind_flg;	// (����)����������(�ڽ���)�߼ұ������, Y, N\n�����������δ� ST,MF,RT,SC,IF�� �ش�(�����ڵ� 027)\n���߼ұ�����δ� ST,FS,DR,EF�� �ش�
	char krx100_flg;	// KRX100���񿩺�, Y, N
	char gvnm_idx_stk_flg;	// (����)���豸���������񿩺�(�ڽ���)�ҼӺα����ڵ�, (����) Y, N\n(�ڽ���)�ҼӺα����ڵ� �� ��ó������� 2011.05.02\n 1:�췮�����, 2:��ó�����, 3:�߰߱����, 4:�ż�������,\n A:�ܱ����, B:����ȸ��, C:SPAC, D:ETF E:��������,\n F:��������ȯ������, Z:��Ÿ \n�� A~Z�� �ҼӺ� ����\n2012.09.14 (���������ġ) "���豸���������񿩺�" 1 Byte FILLER ó��\n(�ڽ��������ġ) "�ҼӺα����ڵ�" ��� ���
	char inst_clsf_code[3];	// ���ڱⱸ�����ڵ�, 00:�ش���� 01:���ǰ������ڱⱸ 02:�Ļ���ǰ���ڱⱸ\n03:�ε��갣�����ڱⱸ 04:�ǹ��������ڱⱸ\n05:�ܱ�����������ڱⱸ 06:�簣�����ڱⱸ\n07:Ư���������ڱⱸ\n�����Ǳ׷�ID MF,IF,BC�� �ش�(���ش��� ��� SPACE)
	char idx_stk_flg;	// (����)KOSPI�������񿩺� (�ڽ���)KOSDAQ�������񿩺�, Y, N\n(����)KOSPI����-> (����)KOSPI�������񿩺�,(�ڽ���)KOSDAQ�������񿩺� 2018.12.10
	char kospi100_flg;	// (����)KOSPI100����(�ڽ���)FILLER, Y, N �����̾�� �߰� 2009.11.16\n(�ڽ���)�����̾�� => FILLERó�� 2016.05.23
	char kospi50_flg;	// (����)KOSPI50����, Y, N
	int base_prc;	// ���ذ���
	char prev_cls_clsf_code;	// �������������ڵ�, 1:�Ǽ� 2:�⼼ 3:�ŷ��� 4:�ð����ذ������� �⼼
	int prev_cls_prc;	// ��������
	double prev_cum_ccls_qty;	// ���ϴ���ü�����
	double prev_cum_trd_val;	// ���ϴ����ŷ����
	int ceil_prc;	// ���Ѱ�
	int flr_prc;	// ���Ѱ�
	int sub_prc;	// ��밡��, ��ST,FS,DR,MF,RT,SC,IF,ET,FE,BC,EN �� �ش�\n 2014.11.17
	double par_val;	// �׸鰡, 9(9)V9(3) �ܱ��ֱ��� ��� �Ҽ�����°�ڸ����� ǥ������\n�ڽ����� ������ �ּ�ȭ����� ǥ�ô� ������������ ����\n��ST,FS,RT,SC,BC�� �ش�
	int issue_prc;	// ���డ��, ELW, �����μ������� ����
	char listd_date[9];	// ��������, YYYYMMDD
	double stk_listd;	// �����ֽļ�(�������Ǽ�)
	char arng_trd_flg;	// �����Ÿſ���, Y, N
	int eps;	// �ִ������(EPS), ����:�� �����Ǳ׷�ID ST,MF,RT,IF,FS �� �ش�
	double per;	// �ְ�������(PER), 9(4)V9(2) �����Ǳ׷�ID ST,MF,RT,IF,FS �� �ش�
	char eps_cmpt_xclu_flg;	// �ִ�����ͻ������ܿ���, Y:�������� N:����\n�ذ��� 0, ��������, �����ǰ��� ���� �Ǵ� ���� �� ���
	int bps;	// �ִ���ڻ갡ġ(BPS), ����:�� �����Ǳ׷�ID ST,MF,RT,IF,FS �� �ش�
	double pbr;	// �ִ���ڻ����(PBR), 9(4)V9(2) �����Ǳ׷�ID ST,MF,RT,IF,FS �� �ش�
	char bps_cmpt_xclu_flg;	// �ִ���ڻ갡ġ�������ܿ���, Y:�������� N:����\n�ذ��� 0, ��������, �����ǰ��� ���� �Ǵ� ������ ���
	char loss_flg;	// ��տ���, Y, N
	int dps;	// �ִ���ݾ�, �ִ����
	char dps_cmpt_xclu_flg;	// �ִ���ݾ׻������ܿ���, Y:�������� N:����\n�ذ��� 0, ��������, �����ǰ��� ���� �Ǵ� ������ ���
	double dyr;	// ��������, 9(6)V9(1)
	char xist_open_date[9];	// ������������, �����Ǳ׷�ID MF,RT,SC,IF,BC �ش�.
	char xist_cls_date[9];	// ������������, �����Ǳ׷�ID MF,RT,SC,IF,BC �ش�. ST,FS,DR�� �켱�ָ� �ش�
	char exc_prd_open_date[9];	// ���Ⱓ��������, �����Ǳ׷�ID SW, EW �� �ش��
	char exc_prd_cls_date[9];	// ���Ⱓ��������(�Ǹ����Ⱓ��������), �����Ǳ׷�ID SW, EW �� �ش��
	double elw_wrnt_exc_prc;	// ELW�����μ������� ��簡��, 9(9)V9(3) ELW �Ǵ� �����μ��������� ��簡��
	double euity;	// �ں���, 9(18)V9(3) �ؿܿ����� ��� �Ҽ�����°�ڸ����� ǥ������\n�׸鰡*�����ֽļ�, ���ͼҰ��� ���� �κ��� ������\nMF�� �Է°�\n��ST,FS,MF,RT,SC,IF,BC�� �ش�
	char credit_ordbl_flg;	// �ſ��ֹ����ɿ���, Y, N
	int limt_prc_cond_clsf_code;	// ������ȣ�����Ǳ����ڵ�, X ->9 ��庯��, 1->5 ���̺���\nȣ���� ü�� �� �ܷ�����, Bitwise ����(*���߰��̵� ����) \n#�ڵ尪# \n1:FAS(Fill And Store) \n2:FOK(Fill Or Kill) \n4:FAK(Fill And Kill) \n*��������(FOK, Fill or Kill):�ֹ����� ��� ���� ü����� ������ ��� �ֹ��� �ڵ� ��ҵǴ� �ֹ� \n*��������(FAS, Fill and Store):�ֹ����� ��� ü�ᰡ�� ������ ü���ϰ� ��ü���ܷ��� ���� ���ߵ��� �ֹ��忡 ü�� ����Ű��, ������ ���� ��ü�� �ֹ��� ��� �ּҵ�
	int mkt_prc_cond_clsf_code;	// ���尡ȣ�����Ǳ����ڵ�, *��
	int cond_prc_cond_clsf_code;	// ���Ǻ�������ȣ�����Ǳ����ڵ�, *��
	int fvr_lmt_ord_cond_clsf_code;	// ������������ȣ�����Ǳ����ڵ�, *��
	int pfr_lmt_ord_cond_clsf_code;	// �ֿ켱������ȣ�����Ǳ����ڵ�, *��
	char cap_inc_clsf_code[3];	// ���ڱ����ڵ�, 00:�ش���� 01:�������� 02:�������� 03:���������� 99:��Ÿ
	char scrt_clsf_code;	// �����ֱǱ����ڵ�, 0:�ش����(������) 1:�����켱�� 2:�����켱�� 9:�����ֱ�(2014.03.03)\n\n�����Ǳ׷�ID ST���� �ش�\n�ر���Ī:�켱�ֱ����ڵ�
	char pbl_scrt_flg;	// �����ֿ���, Y, N ���������Ǹ� �ش�
	int asmt_prc;	// �򰡰���
	int min_ask_prc;	// ����ȣ������
	int max_ask_prc;	// �ְ�ȣ������
	int opr_time_trd_qty_unit;	// ������Ÿż�������, 1�ִ���:1 10:10�ִ��� 100:100�ִ��� 1000:1000�ִ���
	int ofhr_trd_qty_unit;	// �ð��ܸŸż�������, 1�ִ���:1 10:10�ִ��� 100:100�ִ��� 1000:1000�ִ���\n��BC,SW,SR,EW�� ����
	char ritz_code;	// ���������ڵ�, 1:�Ϲݸ��� 2:CRV����
	char obj_scrt_code[13];	// �����ֱ������ڵ�, ��SW,SR�� �ش�
	char crny_iso_code[4];	// ��ȭISO�ڵ�, AUD:ȣ�ִ޷� EUR:���� GBP:�����Ŀ�� HKD:ȫ��޷� ��\n���ڵ尪����-��ȭISO�ڵ� ����
	char nt_code[4];	// �����ڵ�, ISO 3166 �ڵ��� 3�ڸ� ���� �غ��� �ڵ�ǥ ����\n����ü ���Ǳ׷�ID�� �ش�
	char mkt_crt_flg;	// �����������ɿ���, Y, N
	char ofhr_trd_flg;	// �ð��ܸŸŰ��ɿ���, Y, N
	char preord_cls_flg;	// �尳�����ð����������ɿ���, Y, N
	char preord_msv_trd_flg;	// �尳�����ð��ܴ뷮�ŸŰ��� ����, Y, N
	char preord_bsk_flg;	// �尳�����ð��ܹٽ��ϰ��� ����, Y, N
	char fcst_ccls_flg;	// ����ü�ᰡ��������, Y, N
	char short_flg;	// ���ŵ����ɿ���, Y, N ���������� �ְų� ���� ���ŵ��� ȣ�����ɿ���
	double trkg_prf_mtp;	// �������������, �����Ǳ׷�ID EF,FE,EN �ش� 2014.11.17\n���׸���� 2014.11.17\n\n9(5)V9(6) ���� �Ǵ� ���� ���� ��� ETF ���� ���� ���\n��) �������� 2���� ��� '00002000000' 2009.07.27
	char regulation_apl_flg;	// Regulation S �������񿩺�, Y, N 2010.02.01
	char spc_flg;	// ����μ�����ȸ�翩��, Y, N 2010.03.02
	char tax_type_code;	// ���������ڵ�, 0:�ش����, \n1:"���ǰŷ���"->"�����" �ڵ尪�� ���� 2016.02.29, \n2:���ҵ漼(�����Ⱓ����), \n3:���ǰŷ���(ȸ����ETF) 2011.05.02 \n4:"���ҵ漼(�ؿ��ֽ���������ETF)" �ڵ尪 �߰� 2016.02.29(BIG33�� FILLER��)
	double sbst_prc_rate;	// ��밡�ݻ�������, 99999V999999 2010.06.28\n(BIG33�� FILLER��)\n��Exture������ ��밡�� 0�̸� ���������� 0�̾�����, Exture+������ ��밡�� 0�̾ �������� ����
	char inv_xctm_stk_flg;	// (�ڽ���)��������ȯ�����񿩺�, (�ڽ���) Y,N �������� �Ǵ� ���������� ��ȭ�� ����� �ִ�\n�ν� ����¡�� ��� ����\n(2011.05.02 �߰�)\n(BIG33�� FILLER��)
	char dlstg_date[9];	// ������������, YYYYMMDD �����Ǳ׷�ID SR �� �ش�, �ٸ� ���Ǳ׷�ID�� FILLERó�� 2011.06.27 �߰�\n(BIG33�� FILLER��)
	char short_term_oh_clsf_code;	// �ܱ�������񱸺��ڵ�, 0: �ش����\n1: ��������\n2: ����\n3: ��������(��������)\n2012.11.05 �߰�
	char etf_cpy_clsf_code;	// ETF������������ڵ�, ETF�� �����ڻ� ������������ڵ� 2013.03.18 �߰�\nP:�ǹ�����\nS:�ռ�����\nA:Active (2015.11.23 �����ڵ��߰�)
	char kospi200_hi_divd_idx_flg;	// KOSPI200������������, Y,N 2013.11.18
	char kospi200_lo_vol_idx_flg;	// KOSPI200����������������, Y,N 2013.11.18
	char mtr_date[9];	// ��������, 2014.11.17
	char divd_type_code[3];	// �й�������ڵ�, �й�����¿� ���� �����ڵ� 2014.11.17\n01:������\n02:����(��ǥ��ġ �ݿ�)\n03:����(��ǥ��ġ �̹ݿ�)\n04:����(������)\n05:����(��Ÿ)
	char mtr_rdmp_prc_st_date[9];	// �����ȯ���ݰ�����������, 2014.11.17
	char mtr_rdmp_prc_ed_date[9];	// �����ȯ���ݰ�����������, 2014.11.17
	char etp_mcdz_clsf_code;	// ETP��ǰ�����ڵ�, (2015.11.23 �߰�)\n ETP��ǰ�����ڵ�\n ## �ڵ尪 ##\n1. ETF(����ȸ����)\n2. ETF(����������)\n3. ETN\n4. �ս����� ETN\n(2017.03.27;ELS�� ETN->�ս����� ETN)
	char idx_cmpt_inst_code;	// �����������ڵ�, (2015.11.23 �߰�) \n*�ڵ尪���� ����(KRX ����)
	char idx_mkt_clsf_id[7];	// ��������з�ID, (2015.11.23 �߰�)\n *��з�(2)+�ߺз�(2)+�Һз�(2)\n ���� �����Ǵ� �з��� �ڸ��� '00'�� ǥ��\n��,�Һз� ������ ���� �з��� ���� ���� �� �� ����
	char idx_snr[4];	// �����Ϸù�ȣ, (2015.11.23 �߰�)�����Ϸù�ȣ
	char trkg_idx_lvrg_invs_clsf_code[3];	// �����������������ι��������ڵ�, (2015.11.23 �߰�)\n## �ڵ尪 ##\n P1:�Ϲ�(1)\n P2:2X ��������(2)\n N1:1X �ι���(-1)\n N2:2X �ι���(-2)
	char ref_idx_lvrg_invs_clsf_code[3];	// �����������������ι��������ڵ�, (2015.11.23 �߰�)\n## �ڵ尪 ##\n P1:�Ϲ�(1)\n P2:2X ��������(2)\n N1:1X �ι���(-1)\n N2:2X �ι���(-2)
	char idx_ast_clsf_id1[7];	// �����ڻ�з�ID1, (2015.11.23 �߰�)\n *��з�(2)+�ߺз�(2)+�Һз�(2)\n ���� �����Ǵ� �з��� �ڸ��� '00'�� ǥ��\n��,�Һз� ������ ���� �з��� ���� ���� �� �� ����
	char idx_ast_clsf_id2[7];	// �����ڻ�з�ID2, (2015.11.23 �߰�)\n *��з�(2)+�ߺз�(2)+�Һз�(2)\n ���� �����Ǵ� �з��� �ڸ��� '00'�� ǥ��\n��,�Һз� ������ ���� �з��� ���� ���� �� �� ����
	char lp_odrbl_flg;	// LP�ֹ����ɿ���, (2015.11.23 �߰�)\nY,N
	char kosdaq150_idx_stk_flg;	// KOSDAQ150�������񿩺�, (2015.11.23 �߰�)\nY,N
	char lo_vol_flg;	// ������������, (2016.06.27 �߰�)\nY,N
	char abnm_risg_flg;	// �̻�޵��, (2017.03.27 �߰�)\nY,N
	char krx300_idx_flg;	// KRX300��������, (2018.03.26 �߰�)\nY,N
	double qty_ceil;	// ���Ѽ���, (2018.09.17 �߰�)���Ѽ����� �ʰ��� ȣ���� �ź�ó�� �ʿ�
	char kospi200_comm_srvc_sct_flg;	// KOSPI200Ŀ�´����̼Ǽ��񽺼��� �ߺ�����, Y : �ٸ����Ϳ� �ߺ��� ��� KOSPI200���;����� �������;��������� �����ϰ� �� �ʵ�� Y�� ����\nN: �ٸ����Ϳ� �ߺ��� ���� ���� ��� KOSPI200���;����� 'B'���� �����ϰ� �� �ʵ�� N���� ����
} DF_KOSPI_STK_ARNG;


// ETN ���ͱ��� ����
typedef struct _DF_ETN_PRF_STR {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����, X8
	char info_clsf[3];	// ��������, 01:�ֽ�
	char mkt_clsf;	// ���屸��, 1:��������
	char isin_code[13];	// �����ڵ�, ǥ���ڵ�
	char etn_profit_strt[2001];	// ETN���ͱ�������, ETN ���ͱ����� ���� ����\n�ս����� ETN���� �ַ� ����
} DF_ETN_PRF_STR;


// ETN������
typedef struct _DF_ETN_DSPR {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����, X4
	char info_clsf[3];	// ��������, 01:�ֽ�
	char mkt_clsf;	// ���屸��, 1:�������� 2:�ڽ���
	char isin_code[13];	// ETN�����ڵ�, ISIN
	int trsm_snr;	// �۽��Ϸù�ȣ, 1~99999999 �����Ϸù�ȣ, �Ǽ�üũ��
	char date[9];	// ����, YYYYMMDD:����������
	double dspr;	// ������, 9(7)V9(2), ����:%
} DF_ETN_DSPR;


// ETN �����ȯ ����
typedef struct _DF_ETN_ELY_RDMP_COND {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����, X3
	char info_clsf[3];	// ��������, 01:�ֽ�
	char mkt_clsf;	// ���屸��, 1:��������
	char isin_code[13];	// �����ڵ�, ǥ���ڵ�
	char etn_ely_rdmp_freq_code[3];	// ETN�����ȯ�ֱ��ڵ�, �ս����� ETN�� �����ȯ �ֱ� ����\nETN�����ȯ���ɿ��ΰ� Y�϶��� ���ð���\n�ˢ��ڵ尪�ˢ�\n01: ����(����)\n02: �� 3����\n03: �� 4����\n04: �� 6����\n05: �� 1�� (��缭���� ����)\n06: 3�������� �� 1���� (��缭���� ����)\n07: 6�������� �� 1���� (��缭���� ����)
	char rdmp_assm_date[9];	// �����ȯ������, �����ȯ������\n�����ȯ�ֱ��ڵ尡 01:������ ���� SPACE
	char rdmp_cond_code;	// �����ȯ���ǰ����ڵ�, �����ȯ����1������ �����ȯ����2���� ���� ���� ���� �ڵ�\n���������� ��� ����1���� < ����2���� �������� ����\n�ˢ��ڵ尪�ˢ�\n1:��������(1�����̻�)\n2:��������(1��������)\n3:��������(1��������,2�����̻�)\n4:��������(1�����̻�,2��������)
	double rdmp_crtr_base_1idx;	// �����ȯ����1����, �����ȯ����1����\n9(8)V9(2)
	double rdmp_crtr_base_2idx;	// �����ȯ����2����, �����ȯ����2����\n9(8)V9(2)
	double rdmp_prc;	// ����������������ȯ����, ����������������ȯ����\n9(21)V9(2)
	char rdmp_date[9];	// �����ȯ��������, �����ȯ��������\n�����ȯ�ֱ��ڵ尡 01:������ ���� SPACE
} DF_ETN_ELY_RDMP_COND;


// ETP��������
typedef struct _DF_ETP_IDX_COMP {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����, V6
	char info_clsf[3];	// ��������, 01:�ֽ�
	char mkt_clsf;	// ���屸��, 1:��������
	char idx_inst_code;	// �����������ڵ�, *�ڵ尪 ����(KRX����)
	char idx_mkt_clsf_id[7];	// ��������з�ID, *��з�(2)+�ߺз�(2)+�Һз�(2)\n ���� �����Ǵ� �з��� �ڸ��� '00'�� ǥ��\n��,�Һз� ������ ���� �з��� ���� ���� �� �� ����
	char idx_snr[4];	// �����Ϸù�ȣ, �����Ϸù�ȣ
	char idx_lvr_ivs_clsf_code[3];	// �������������ι��������ڵ�, ## �ڵ尪 ##\n P1:�Ϲ�(1)\n P2:2X ��������(2)\n N1:1X �ι���(-1)\n N2:2X �ι���(-2)
	char idx_nm[81];	// ������, ������
	char idx_eng_nm[81];	// ����������, ����������
	char idx_asset_clsf_id1[7];	// �����ڻ�з�ID1, *��з�(2)+�ߺз�(2)+�Һз�(2)\n ���� �����Ǵ� �з��� �ڸ��� '00'�� ǥ��\n��,�Һз� ������ ���� �з��� ���� ���� �� �� ����
	char idx_asset_clsf_id2[7];	// �����ڻ�з�ID2, *��з�(2)+�ߺз�(2)+�Һз�(2)\n ���� �����Ǵ� �з��� �ڸ��� '00'�� ǥ��\n��,�Һз� ������ ���� �з��� ���� ���� �� �� ����
	char idx_mkt_clsf_code;	// �����Ҽӽ��屸���ڵ�, ���� �Ҽӽ����� ����
	char ind_idx_code[9];	// ���������ڵ�, ���������ڵ�(8�ڸ�)�� ���������Ӹ� �ƴ϶� KOSPI100, KOSPI50, KOSTAR���� ���� ������ ����� �Ǵ� ��� �з��� �ڵ带 �ο��Ͽ� �̸� ��Ī
} DF_ETP_IDX_COMP;


// �ڽ���_���ذ�����
typedef struct _DF_KOSPI_BASE_PRC_DCS {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����, A4
	char info_clsf[3];	// ��������, 01:�ֽ�
	char mkt_clsf;	// ���屸��, 1:�������� 2:�ڽ���
	char isin_code[13];	// �����ڵ�, ǥ���ڵ�
	int snr;	// �����Ϸù�ȣ, �����ġ(A0)�� �����Ϸù�ȣ
	char brd_id[3];	// ����ID, �� �ڵ尪���� ����
	int base_prc;	// ���ذ���, ����:��
	int base_prc_ceil;	// ���ذ��ݻ��Ѱ�, ����:��
	int base_prc_flr;	// ���ذ������Ѱ�, ����:��
} DF_KOSPI_BASE_PRC_DCS;


// �ڽ���_���񸶰�
typedef struct _DF_KOSPI_STK_CLSG {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����, A6
	char info_clsf[3];	// ��������, 01:�ֽ� 02:ELW
	char mkt_clsf;	// ���屸��, 1:�������� 2:�ڽ���
	char isin_code[13];	// �����ڵ�, ǥ���ڵ�
	int snr;	// �����Ϸù�ȣ, �����ġ(A0)�� �����Ϸù�ȣ
	char brd_id[3];	// ����ID, �� �ڵ尪���� ����
	int stk_cls_prc;	// ���񸶰�����, ���Խð��ܱ����ڵ尡 \n 1:�������϶��� ���񸶰����ݱ����ڵ尪�� SET ��. \n �׿ܿ��� SPACE
	char stk_cls_prc_clsf_code;	// ���񸶰����ݱ����ڵ�, 1:ü�ᰡ \n 2:�⼼ \n 3:�ŷ��� \n 4:�ð����ذ������� �⼼\n :�������� �ƴ� ��� SPACE
	int ofhr_ceil;	// ���񸶰��ð��ܴ��ϰ� ���Ѱ�
	int ofhr_flr;	// ���񸶰��ð��ܴ��ϰ� ���Ѱ�
	int stk_cls_mwprc;	// ���񸶰���հ����ְ�
	int dlv_base_prc;	// �����ε����ذ���
	int dlv_ceil;	// �����ε����Ѱ�
	int dlv_flr;	// �����ε����Ѱ�
} DF_KOSPI_STK_CLSG;


// �ڽ���_��TS
typedef struct _DF_KOSPI_MKT_OPR_TS {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����, A7
	char info_clsf[3];	// ��������, 01:�ֽ� 02:ELW
	char mkt_clsf;	// ���屸��, 1:�������� 2:�ڽ���
	char isin_code[13];	// �����ڵ�, ǥ���ڵ�
	int stk_snr;	// �����Ϸù�ȣ, �����ġ(A0)�� �����Ϸù�ȣ
	char brd_id[3];	// ����ID, �� �ڵ尪���� ����
	char brd_evt_id[4];	// �����̺�ƮID, �� �ڵ尪���� ����
	char brd_evt_st[7];	// �����̺�Ʈ���۽ð�
	int brd_evt_code;	// �����̺�Ʈ���뱺�ڵ�, �� �ڵ尪���� ����
	char sess_id[3];	// ����ID, �� �ڵ尪���� ����
	char trsp_rsn_code[4];	// �ŷ����������ڵ�, �� �ڵ尪���� ����
} DF_KOSPI_MKT_OPR_TS;


// �ڽ���_ü��
typedef struct _DF_KOSPI_CCLS {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����, A3
	char info_clsf[3];	// ��������, 01:�ֽ� 02:ELW
	char mkt_clsf;	// ���屸��, 1:�������� 2:�ڽ���
	char isin_code[13];	// �����ڵ�, ǥ���ڵ�
	int stk_snr;	// �����Ϸù�ȣ, �����ġ(A0)�� �����Ϸù�ȣ
	char brd_id[3];	// ����ID, �� �ڵ尪���� ����
	char ctrs_clsf;	// ���ϴ��(���ذ����) ����, 0:�ǴܺҰ� 1:���� 2:��� 3:���� 4:���� 5:�϶�\n �� ���Խð��ܱ����ڵ� ���� 4�� ��� ���� ���� ���\n �� ���Խð��ܱ����ڵ� ���� 7,8�� ��� Buy-in���ذ� ���
	int prev_ctrs;	// ���ϴ��, ����:�� �����μ��� ����/������ �ű� ���� ���� : 0
	int ccls_prc;	// ü�ᰡ��, ����:��
	double ccls_qty;	// ü�����, ����:��
	char sess_id[3];	// ����ID, �� �ڵ尪���� ����
	int open;	// �ð�, ����:�� �ذ��߰��̵� ����
	int high;	// ��, ����:�� �ذ��߰��̵� ����
	int low;	// ����, ����:�� �ذ��߰��̵� ����
	double cum_ccls_qty;	// ����ü�����, ����:�� �غ���ID���� ������
	double cum_trd_val;	// �����ŷ����, ����:�� �غ���ID���� ������
	char fin_bid_ask_clsf_code;	// �����ŵ��ż������ڵ�, 1:�ŵ� 2:�ż�
	char mtc_flg;	// ü�ᰡ��1ȣ����ġ����, 0:�ǴܺҰ� 1:��ġ 2:����ġ
	char ccls_time[7];	// ü��ð�, HHMMSS
	double lp_hld_qty;	// LP��������, LP(ü�����) ������ LP��������\n�����߻� ����(ETN�� �ش�)(2018.09.17)
	int ask_1_prc;	// �ŵ�1ȣ��, ����:�� �ذ��߰��̵� ����
	int bid_1_prc;	// �ż�1ȣ��, ����:�� �ذ��߰��̵� ����
} DF_KOSPI_CCLS;


// �ڽ���_�뷮ü��
typedef struct _DF_KOSPI_MSV_CCLS {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����, C4
	char info_clsf[3];	// ��������, 01:�ֽ�
	char mkt_clsf;	// ���屸��, 1:�������� 2:�ڽ���
	char isin_code[13];	// �����ڵ�, ǥ���ڵ�
	int stk_snr;	// �����Ϸù�ȣ, �����ġ(A0)�� �����Ϸù�ȣ
	int snr;	// �Ϸù�ȣ, 1~99999999 �Ǽ�üũ��
	int bopen_rel_msv_ccls_qty;	// �尳�����ð��� ���뷮ü�����, ����:��
	int bopen_bsk_ccls_qty;	// �尳�����ð��� �ٽ���ü�����, ����:��
	int bopen_cmpt_msv_ccls_qty;	// �尳�����ð��� ����뷮ü�����, ����:��
	int rel_msv_ccls_qty;	// ���߻��뷮ü�����, ����:��
	int bsk_ccls_qty;	// ���߹ٽ���ü�����, ����:��
	int cmpt_msv_ccls_qty;	// ���߰���뷮ü�����, ����:��
	int ofhr_rel_msv_ccls_qty;	// �������Ľð��� ���뷮ü�����, ����:��
	int ofhr_bsk_ccls_qty;	// �������Ľð��� �ٽ���ü�����, ����:��
} DF_KOSPI_MSV_CCLS;


// �ڽ���_�������
typedef struct _DF_KOSPI_ALLC_INFO {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����, O6
	char info_clsf[3];	// ��������, 01:�ֽ�
	char mkt_clsf;	// ���屸��, 1:��������, 2:�ڽ���,
	char isin_code[13];	// �����ڵ�, ǥ���ڵ�
	int stk_snr;	// �����Ϸù�ȣ, �����ġ(A0)�� �����Ϸù�ȣ
	char brd_id[3];	// ����ID, �� �ڵ尪���� ����
	char allc_apl_clsf_code;	// ������뱸���ڵ�, 1 ��а���\n 2 �������
	int allc_proc_clsf_code;	// ���ó�������ڵ�, 1 �ż�����,\n 2 �ż�����,\n 3 �ŵ�����,\n 4 �ŵ����� �� ������ ' ' ����
	int allc_cncl_time;	// ��������ð�, HHMMSS
} DF_KOSPI_ALLC_INFO;


// ELW_ü��
typedef struct _DF_ELW_CCLS {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����, A3
	char info_clsf[3];	// ��������, 01:�ֽ� 02:ELW
	char mkt_clsf;	// ���屸��, 1:�������� 2:�ڽ���
	char isin_code[13];	// �����ڵ�, ǥ���ڵ�
	int stk_snr;	// �����Ϸù�ȣ, �����ġ(A0)�� �����Ϸù�ȣ
	char brd_id[3];	// ����ID, �� �ڵ尪���� ����
	char ctrs_clsf;	// ���ϴ��(���ذ����) ����, 0:�ǴܺҰ� 1:���� 2:��� 3:���� 4:���� 5:�϶�\n �� ���Խð��ܱ����ڵ� ���� 4�� ��� ���� ���� ���\n �� ���Խð��ܱ����ڵ� ���� 7,8�� ��� Buy-in���ذ� ���
	int prev_ctrs;	// ���ϴ��, ����:�� �����μ��� ����/������ �ű� ���� ���� : 0
	int ccls_prc;	// ü�ᰡ��, ����:��
	double ccls_qty;	// ü�����, ����:��
	char sess_id[3];	// ����ID, �� �ڵ尪���� ����
	int open;	// �ð�, ����:�� �ذ��߰��̵� ����
	int high;	// ��, ����:�� �ذ��߰��̵� ����
	int low;	// ����, ����:�� �ذ��߰��̵� ����
	double cum_ccls_qty;	// ����ü�����, ����:�� �غ���ID���� ������
	double cum_trd_val;	// �����ŷ����, ����:�� �غ���ID���� ������
	char fin_bid_ask_clsf_code;	// �����ŵ��ż������ڵ�, 1:�ŵ� 2:�ż�
	char mtc_flg;	// ü�ᰡ��1ȣ����ġ����, 0:�ǴܺҰ� 1:��ġ 2:����ġ
	char ccls_time[7];	// ü��ð�, HHMMSS
	double lp_hld_qty;	// LP��������, LP(ü�����) ������ LP��������
	int ask_1_prc;	// �ŵ�1ȣ��, ����:�� �ذ��߰��̵� ����
	int bid_1_prc;	// �ż�1ȣ��, ����:�� �ذ��߰��̵� ����
} DF_ELW_CCLS;


// ELW_���񸶰�
typedef struct _DF_ELW_STK_CLSG {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����, A6
	char info_clsf[3];	// ��������, 01:�ֽ� 02:ELW
	char mkt_clsf;	// ���屸��, 1:�������� 2:�ڽ���
	char isin_code[13];	// �����ڵ�, ǥ���ڵ�
	int snr;	// �����Ϸù�ȣ, �����ġ(A0)�� �����Ϸù�ȣ
	char brd_id[3];	// ����ID, �� �ڵ尪���� ����
	int stk_cls_prc;	// ���񸶰�����, ���Խð��ܱ����ڵ尡 \n 1:�������϶��� ���񸶰����ݱ����ڵ尪�� SET ��. \n �׿ܿ��� SPACE
	char stk_cls_prc_clsf_code;	// ���񸶰����ݱ����ڵ�, 1:ü�ᰡ \n 2:�⼼ \n 3:�ŷ��� \n 4:�ð����ذ������� �⼼\n :�������� �ƴ� ��� SPACE
	int ofhr_hi;	// ���񸶰��ð��ܴ��ϰ� ���Ѱ�
	int ofhr_lo;	// ���񸶰��ð��ܴ��ϰ� ���Ѱ�
	int stk_cls_mwprc;	// ���񸶰���հ����ְ�
	int dlv_base_prc;	// �����ε����ذ���
	int dlv_hi;	// �����ε����Ѱ�
	int dlv_lo;	// �����ε����Ѱ�
} DF_ELW_STK_CLSG;


// ELW_��TS
typedef struct _DF_ELW_MKT_OPR_TS {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����, A7
	char info_clsf[3];	// ��������, 01:�ֽ� 02:ELW
	char mkt_clsf;	// ���屸��, 1:�������� 2:�ڽ���
	char isin_code[13];	// �����ڵ�, ǥ���ڵ�
	int stk_snr;	// �����Ϸù�ȣ, �����ġ(A0)�� �����Ϸù�ȣ
	char brd_id[3];	// ����ID, �� �ڵ尪���� ����
	char brd_evt_id[4];	// �����̺�ƮID, �� �ڵ尪���� ����
	char brd_evt_st[7];	// �����̺�Ʈ���۽ð�
	int brd_evt_code;	// �����̺�Ʈ���뱺�ڵ�, �� �ڵ尪���� ����
	char sess_id[3];	// ����ID, �� �ڵ尪���� ����
	char trsp_rsn_code[4];	// �ŷ����������ڵ�, �� �ڵ尪���� ����
} DF_ELW_MKT_OPR_TS;


// �ڽ���_�ֽ�������������
typedef struct _DF_KOSPI_STK_INFO_DCLS {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����, A8
	char info_clsf[3];	// ��������, 01:�ֽ�
	char mkt_clsf;	// ���屸��, 1:�������� 2:�ڽ���
	char isin_code[13];	// �����ڵ�
	int stk_snr;	// �����Ϸù�ȣ, �����ġ(A0)�� �����Ϸù�ȣ
	char open_info_clsf_code[4];	// �������������ڵ�, �� �ڵ尪���� ����
	char brd_id[3];	// ����ID, �� �ڵ尪���� ����
	int base_prc;	// ���ذ���
	int ceil_prc;	// ���Ѱ�, ������������ ���� ���� '999999999'
	int flr_prc;	// ���Ѱ�, ������������ ���� ���� '-99999999'
	int assm_prc;	// �򰡰���
	int best_ask_prc;	// �ְ�ȣ������
	int least_ask_prc;	// ����ȣ������
	char mkt_base_prc_flg;	// �ð����ذ��ݿ���, Y, N
	char lock_clsf_code[3];	// �������ڵ�, 00:�ش���׾��� 01:�Ǹ��� 02:���� 03:�й�� 04:�ǹ��\n 05:�߰�(�б�)���� 06:�Ǹ��߰����� 07:�Ǹ��б���� 99:��Ÿ
	char pval_chg_clsf_code[3];	// �׸鰡���汸���ڵ�, 00:�ش���� 01:�׸���� 02:�׸麴�� \n 03:�ֽĺ��� 04:�ֽĺ���\n 99:��Ÿ
	double trd_qty_unit;	// �Ÿż�������, 1�ִ���:1 10:10�ִ��� 100:100�ִ��� 1000:1000�ִ���
	double stk_lstd;	// �����ֽļ�
	char apnt;	// ��������, N:���� Y:����
	char bopen_ofhr_flg;	// �尳�����ð������� ���ɿ���, N:�ش���� Y:����
} DF_KOSPI_STK_INFO_DCLS;


// �ڽ���_�������ٰ���
typedef struct _DF_KOSPI_MKT_OPR_DCLS {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����, M4
	char info_clsf[3];	// ��������, 01:�ֽ�
	char mkt_clsf;	// ���屸��, 1:�������� 2:�ڽ���
	char isin_code[13];	// �����ڵ�
	int stk_snr;	// �����Ϸù�ȣ, �����ġ(A0)�� �����Ϸù�ȣ
	char brd_id[3];	// ����ID, �� �ڵ尪���� ����
	char brd_evt_id[4];	// �����̺�ƮID, �� �ڵ尪���� ����
	char brd_evt_st[7];	// �����̺�Ʈ���۽ð�
	int brd_evt_code;	// �����̺�Ʈ���뱺�ڵ�, �� �ڵ尪���� ����
	char sess_open_cls_id[3];	// ���ǰ��������ڵ�, BS: ���尳��\n BE: ��������\n SS: ���ǰ���\n SE: ��������\n SH:��������\n SR:�����簳
	char sess_id[3];	// ����ID, �� �ڵ尪���� ����
	char pbl_stk_code[13];	// ����������ڵ�, ������ġ�� ������ �Ǵ� �����ڵ�\n *�������� �����ڵ嵵 ���� �� ����
	char trsp_rsn_code[4];	// �ŷ����������ڵ�, �� �ڵ尪���� ���� *��������(KO) �� " "
	char trsp_trgg_code;	// �ŷ������߻������ڵ�, 1:�ڱ����� 2:�����μ������� 3:�����μ������� 4:�����ڻ�ELW\n 5:����ELW 6:����� 7:�����ڻ�Ҽӽ��� *��������(KO)�� "1" \n9:������(ETN) 2014.11.17
	int apl_step;	// ����ܰ�, CB �� ���������� Ȯ��� ����Ǵ� �ܰ�(�� ���� ���� "00")
} DF_KOSPI_MKT_OPR_DCLS;


// �ڽ���_����� ����
typedef struct _DF_KOSPI_STGD_INFO {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����, I5
	char info_clsf[3];	// ��������, 01:�ֽ�
	char mkt_clsf;	// ���屸��, 1:�������� 2:�ڽ���
	char isin_code[13];	// �����ڵ�, ǥ���ڵ�
	int snr;	// �Ϸù�ȣ, 1~99999999 �Ǽ�üũ��
	char clsg_date[5];	// ������, ������� ȸ�� �����(12�� 31��, 6�� 30��, 3�� 31��)\n���⳪ ������ ���� 12���� ��� '1200'�� ǥ�õ�\n���ֽ�, �ؿܿ���, DR : ����(�ִ� 1��)\n�ظ��� : ����(�Ϲ������� 2��, �ִ� 12��)\n��ETF, �ؿ�ETF : �й������(�ִ� 12��)\n����������ȸ��(MF), ������������ȸ�� : �����(�ִ� 12��)\n�ؼ�������ȸ�� : ��������(�Ϲ������� 4��, �ִ� 12��)
} DF_KOSPI_STGD_INFO;


// �ڽ���_LP ����
typedef struct _DF_KOSPI_LP_INFO {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����, I7
	char info_clsf[3];	// ��������, 01:�ֽ�
	char mkt_clsf;	// ���屸��, 1:�������� 2:�ڽ���
	char isin_code[13];	// �����ڵ�, ǥ���ڵ�
	int snr;	// �Ϸù�ȣ, 1~99999999 �Ǽ�üũ��
	char mkt_ptcp_nr[6];	// ���������ڹ�ȣ, ���������ڸ� �ĺ�/������ �� �ִ� ��ȣ\n�� ���������ڰ� ���� �ŷ����� ȸ���̸� �ŷ��Һ���\n���������ڹ�ȣ�� �޸��� ��) '00001'
	char lp_open_date[9];	// LP��������, ���������ް�������
	char lp_cls_date[9];	// LP��������, ������������������
	double min_ask_qty_mtp;	// �ּ�ȣ���������, LP/MM ȣ���� �Ÿż��������� �ּҹ��\n��) ���� 10�̰� �Ÿż��������� 10��(���)�̸� LP/MM ȣ����\n100��(���) �̻����� ȣ���ؾ���
	double max_ask_qty_mtp;	// �ִ�ȣ���������, LP/MM ȣ���� �Ÿż��������� �ִ���
	char ask_prc_sprd_unit_code;	// ȣ��������������ڵ�, R:���ݺ���\nY:���ͷ�����(ä��)\nT:ȣ�����ݴ��� ���\nA:���밪 (ä��)\n*����Ī:���Ѵ��������ڵ�
	double ask_prc_sprd_val;	// ȣ���������尪, LP/MM ȣ�� ������ �ǹ��� �߻��ϴ� �ֿ켱ȣ����������\n���� �Ǵ� ���� 9(13)V9(8)
	double off_mkt_ask_sprd_mtp;	// ����ȣ������������, �Ļ�,ELW,ETF�� �����ڻ��� �ؿܽ����� ���� �Ǵ� ������ ��� �ش� ������ ����, �尳����, ��������, ���� ���� ������ �����ڻ��� ���� ��ġ�� �Ǵ��� �� ���� �� ���� ���� ��ະ�� ������ �������� ���� Ȯ��� �������带 ����ϱ� ���� ���\n*����Ī:����ȣ���������尪\n�� ����ȣ���������尪 = ����ȣ������������ * ȣ���������尪\n(Exture���� ����ȣ���������尪�� 0�ΰ�� Exture+������ ȣ���������尪�� ��ġ��Ŵ) 2014.03.03
	int obgt_ask_sbmt_time_invl;	// �ǹ�ȣ������ð�����, ����:��(sec)\n00�� �̳��� �ֿ켱ȣ�������� ��ҽ�Ű�� �ŵ�ȣ�� �Ǵ� �ż�ȣ���� ����
	double ask_min_ask_prc_amt;	// �ŵ��ּ�ȣ���ݾ�, 9(18)V9(3) 2009.07.27
	double bid_min_ask_prc_amt;	// �ż��ּ�ȣ���ݾ�, 9(18)V9(3) 2009.07.27
	double min_ask_amt;	// �ּ�ȣ���ݾ�, 9(18)V9(3) (2015.11.23 �߰�)\nMM(����������)ȣ���� �ּұݾ�\n��LP�ּ�ȣ����������� ��Ÿ������ ���, LP�ּ�ȣ����������� ���� ������ ��� �ش� �ʵ�� ����
	double max_ask_amt;	// �ִ�ȣ���ݾ�, 9(18)V9(3) (2015.11.23 �߰�)\n�ִ�ȣ���ݾ�
} DF_KOSPI_LP_INFO;


// �ڽ���_������
typedef struct _DF_KOSPI_CUR_FLCT {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����, B5
	char info_clsf[3];	// ��������, 01:�ֽ�
	char mkt_clsf;	// ���屸��, 1:�������� 2:�ڽ���
	int tot_stk_nr;	// ��ü �����
	int trd_form_stk_nr;	// �ŷ����� �����
	int ceil_stk_nr;	// ���� �����
	int rise_stk_nr;	// ��� �����
	int stdstl_stk_nr;	// ���� �����
	int flr_stk_nr;	// ���� �����
	int fall_stk_nr;	// �϶� �����
	int trend_stk_nr;	// �⼼ �����
	int trend_rise_stk_nr;	// �⼼��� �����
	int trend_fall_stk_nr;	// �⼼�϶� �����
} DF_KOSPI_CUR_FLCT;


// �ڽ���_�ð��ܴ��ϰ�_��Ŀ����
typedef struct _DF_KOSPI_OFH_RCVR {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����, B4:�ð��ܴ��ϰ� �ü�, B3:�ð��ܴ��ϰ�����
	int info_clsf;	// ��������, 01:�ֽ�
	int mkt_clsf;	// ���屸��, 1:�������� 2:�ڽ���
	char isin_code[13];	// �����ڵ�, ǥ���ڵ�
	int stk_snr;	// �����Ϸù�ȣ, �����ġ(A0)�� �����Ϸù�ȣ 2014.03.03
	char ofhr_cnst_clsf;	// �ð��ܴ��ϰ���񱸺�, 0:�ǴܺҰ� 1:���� 2:��� 3:���� 4:���� 5:�϶�
	int ofhr_cnst;	// �ð��ܴ��ϰ����, ����:��
	int ofhr_cnst_ceil;	// �ð��ܴ��ϰ����Ѱ�
	int ofhr_cnst_flr;	// �ð��ܴ��ϰ����Ѱ�
	int ofhr_cnst_cur;	// �ð��ܴ��ϰ����簡
	int ofhr_cnst_open;	// �ð��ܴ��ϰ��ð�
	int ofhr_cnst_hi;	// �ð��ܴ��ϰ���
	int ofhr_cnst_lo;	// �ð��ܴ��ϰ�����
	int ofhr_cnst_ask;	// �ð��ܴ��ϰ��ŵ�ȣ��
	int ofhr_cnst_bid;	// �ð��ܴ��ϰ��ż�ȣ��
	double ofhr_cnst_cum_ccls_qty;	// �ð��ܴ��ϰ����� ü�����
	double ofhr_cnst_cum_trd_val;	// �ð��ܴ��ϰ����� �ŷ����
	double tot_cum_ccls_qty;	// ��ü �� ����ü�����, ����:�� �ش��� ��ü ����
	double tot_cum_trd_val;	// ��ü �� �����ŷ����, ����:�� �ش��� ��ü ����
	int ofhr_mkt_clsf;	// �ð��ܴ��ϰ��屸��, 0:�ʱⰪ 1:�ð��ܴ��ϰ����� 2:�ð��ܴ��ϰ�����
	char trsp_flg;	// �ŷ���������, Y, N
	char trend_flg;	// �Ǽ�/�⼼ ����, 0:�ʱⰪ 1:�Ǽ� 2:�⼼ 3:�ŷ��� 4:�ð����ذ������� �⼼
} DF_KOSPI_OFH_RCVR;


// �ڽ���_�ð��ܴ��ϰ�_��Ŀ����_����
typedef struct _DF_KOSPI_OFH_RCVR_FINAL {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����, B3:�ð��ܴ��ϰ����� B4:�ð��ܴ��ϰ�REC
	char info_clsf[3];	// ��������, 01:�ֽ�
	char mkt_clsf;	// ���屸��, 1:�������� 2:�ڽ���
	char isin_code[13];	// �����ڵ�, ǥ���ڵ�
	int stk_snr;	// �����Ϸù�ȣ, �����ġ(A0)�� �����Ϸù�ȣ
	char ofhr_cnst_clsf;	// �ð��ܴ��ϰ��������, 0:�ǴܺҰ� 1:���� 2:��� 3:���� 4:���� 5:�϶�
	int ofhr_cnst;	// �ð��ܴ��ϰ����, ����:��
	int ofhr_cnst_ceil;	// �ð��ܴ��ϰ����Ѱ�
	int ofhr_cnst_flr;	// �ð��ܴ��ϰ����Ѱ�
	int ofhr_cnst_cur;	// �ð��ܴ��ϰ����簡
	int ofhr_cnst_open;	// �ð��ܴ��ϰ��ð�
	int ofhr_cnst_hi;	// �ð��ܴ��ϰ���
	int ofhr_cnst_lo;	// �ð��ܴ��ϰ�����
	int ofhr_cnst_ask;	// �ð��ܴ��ϰ��ŵ�ȣ��, B3�� 0�� SET
	int ofhr_cnst_bid;	// �ð��ܴ��ϰ��ż�ȣ��, B3�� 0�� SET
	double ofhr_cnst_cum_ccls_qty;	// �ð��ܴ��ϰ����� ü�����
	double ofhr_cnst_cum_trd_val;	// �ð��ܴ��ϰ����� �ŷ����
	double tot_cum_ccls_qty;	// ��ü �� ����ü�����
	double tot_cum_trd_val;	// ��ü �� �����ŷ����
	char ofhr_mkt_clsf;	// �ð��ܴ��ϰ��屸��, 0:�ʱⰪ 1:�ð��ܴ��ϰ����� 2:�ð��ܴ��ϰ�����
	char trsp_flg;	// �ŷ���������, Y, N
	char trend_flg;	// �Ǽ�/�⼼ ����, 0:�ʱⰪ 1:�Ǽ� 2:�⼼ 3:�ŷ��� 4:�ð����ذ������� �⼼
} DF_KOSPI_OFH_RCVR_FINAL;


// �ڽ���_ȣ���ܷ�_LPȣ��_����
typedef struct _DF_KOSPI_ASK_RSD_WOLP {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����, B6
	char info_clsf[3];	// ��������, 01:�ֽ�
	char mkt_clsf;	// ���屸��, 1:�������� 2:�ڽ���
	char isin_code[13];	// �����ڵ�, ǥ���ڵ�
	int stk_snr;	// �����Ϸù�ȣ, �����ġ(A0)�� �����Ϸù�ȣ
	double cum_ccls_qty;	// ����ü�����
	DF_STOCK_LOB_INFO lob_infos[10];	// ȣ�� OCCURS 1010�� 42 = 420
	double ask_10_tot_rsd;	// 10�ܰ�ȣ���ŵ����ܷ�
	double bid_10_tot_rsd;	// 10�ܰ�ȣ���ż����ܷ�
	double ofhr_ask_tot_rsd;	// �������Ľð��� �ŵ���ȣ���ܷ�, ����ID�� "G3"�� ��� ������
	double ofhr_bid_tot_rsd;	// �������Ľð��� �ż���ȣ���ܷ�, ����ID�� "G3"�� ��� ������
	char sess_id[3];	// ����ID, �� �ڵ尪���� ����
	char brd_id[3];	// ����ID, �� �ڵ尪���� ����
	int exp_ccls_prc;	// ����ü�ᰡ��
	double exp_ccls_qty;	// ����ü�����
	int cmpt_msv_dir_clsf;	// ����뷮 ���ⱸ��, 0:�ش����, 1:�ŵ�, 2:�ż�
} DF_KOSPI_ASK_RSD_WOLP;


// �ڽ���_ȣ���ܷ�_LPȣ��_����
typedef struct _DF_KOSPI_ASK_RSD_WLP {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����, B7
	char info_clsf[3];	// ��������, 01:������������ 02:ELW
	char mkt_clsf;	// ���屸��, 1:��������
	char isin_code[13];	// �����ڵ�, ǥ���ڵ�
	int stk_snr;	// �����Ϸù�ȣ, �����ġ(A0)�� �����Ϸù�ȣ
	double cum_ccls_qty;	// ����ü�����
	DF_STOCK_LOB_INFO_WITH_LP lob_infos[10];	// ȣ�� OCCURS 1010�� 66 = 660
	double ask_10_tot_rsd;	// 10�ܰ�ȣ���ŵ����ܷ�
	double bid_10_tot_rsd;	// 10�ܰ�ȣ���ż����ܷ�
	double ofhr_ask_tot_rsd;	// �������Ľð��� �ŵ���ȣ���ܷ�, ����ID�� "G3"�� ��� ������ \n ��ELW�� �ð��ܰŷ� ����
	double ofhr_bid_tot_rsd;	// �������Ľð��� �ż���ȣ���ܷ�, ����ID�� "G3"�� ��� ������\n ��ELW�� �ð��ܰŷ� ����
	char sess_id[3];	// ����ID, �� �ڵ尪���� ����
	char brd_id[3];	// ����ID, �� �ڵ尪���� ����
	int exp_ccls_prc;	// ����ü�ᰡ��
	double exp_ccls_qty;	// ����ü�����
	int cmpt_msv_dir_clsf;	// ����뷮 ���ⱸ��, 0:�ش����, 1:�ŵ�, 2:�ż�
} DF_KOSPI_ASK_RSD_WLP;


// �ڽ���_�尳����_ȣ���ܷ�
typedef struct _DF_KOSPI_BOPEN_ASK_RSD {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����, B8
	char info_clsf[3];	// ��������, 01:�ֽ�
	char mkt_clsf;	// ���屸��, 1:�������� 2:�ڽ���
	char isin_code[13];	// �����ڵ�, ǥ���ڵ�
	int stk_snr;	// �����Ϸù�ȣ, �����ġ(A0)�� �����Ϸù�ȣ
	double cum_ccls_qty;	// ����ü�����
	double tot_ask_rsd;	// �Ѹŵ�ȣ���ܷ�
	double tot_bid_rsd;	// �Ѹż�ȣ���ܷ�
} DF_KOSPI_BOPEN_ASK_RSD;


// �ڽ���_�����������ں�
typedef struct _DF_KOSPI_BYIND_BYINV {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����, C0
	char info_clsf[3];	// ��������, 01:�ֽ�
	char mkt_clsf;	// ���屸��, 1:�������� 2:�ڽ���
	char cmpt_time[7];	// ����ð�, 90�� �ֱ�
	char inv_code[5];	// �������ڵ�, ���ڵ尪���� ����\n*�ڵ�'7000'�� ����, ������� �׸� 0���� ���� (20181210)
	char ind_code[4];	// �����ڵ�, ���ڵ尪������ ���������ڵ�з� ����\n�������;�ڽ�����������, �ڽ�����������, �ڽ���200����
	double ask_ccls_qty;	// �ŵ�ü�����, ����:��
	double ask_trd_val;	// �ŵ��ŷ����, ����:��
	double bid_ccls_qty;	// �ż�ü�����, ����:��
	double bid_trd_val;	// �ż��ŷ����, ����:��
} DF_KOSPI_BYIND_BYINV;


// �ڽ���_���α׷��Ÿ� ȣ��
typedef struct _DF_KOSPI_PRGTRD_ASK {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����, C3
	char info_clsf[3];	// ��������, 01:�ֽ�
	char mkt_clsf;	// ���屸��, 1:�������� 2:�ڽ���
	char isin_code[13];	// �����ڵ�
	int snr;	// �Ϸù�ȣ, 1~99999999 �����Ϸù�ȣ 2014.03.03
	//���α׷��Ÿ�ȣ���ܷ�	
	double idx_abtg_ask_rsd;	// �������͸ŵ�ȣ���ܷ�
	double idx_abtg_bid_rsd;	// �������͸ż�ȣ���ܷ�
	double idx_nabtg_ask_rsd;	// ���������͸ŵ�ȣ���ܷ�
	double idx_nabtg_bid_rsd;	// ���������͸ż�ȣ���ܷ�
	// ���α׷��Ÿ�ȣ������	
	double idx_abtg_ask_qty;	// �������͸ŵ�ȣ������
	double idx_abtg_bid_qty;	// �������͸ż�ȣ������
	double idx_nabtg_ask_qty;	// ���������͸ŵ�ȣ������
	double idx_nabtg_bid_qty;	// ���������͸ż�ȣ������
	// ���α׷��Ÿ� �������ÿ��ܷ�, ������:���α׷��Ÿ�ȣ���ܷ��� �����ϳ� 14:50������ Update\n������:���α׷��ŸŻ������ÿ��ܷ� ����, 14:50���� Update\n(2011.05.30)	
	double prior_idx_abtg_ask_rsd;	// �������͸ŵ�ȣ���ܷ�
	double prior_idx_abtg_bid_rsd;	// �������͸ż�ȣ���ܷ�
	double prior_idx_nabtg_ask_rsd;	// ���������͸ŵ�ȣ���ܷ�
	double prior_idx_nabtg_bid_rsd;	// ���������͸ż�ȣ���ܷ�
	//���α׷��Ÿ�ü�᳻��	
	double idx_abtg_ask_ccls_qty;	// �������͸ŵ���Ź ü�����
	double idx_abtg_ask_self_ccls_qty;	// �������͸ŵ��ڱ� ü�����
	double idx_abtg_bid_ccls_qty;	// �������͸ż���Ź ü�����
	double idx_abtg_bid_self_ccls_qty;	// �������͸ż��ڱ� ü�����
	double idx_nabtg_ask_ccls_qty;	// ���������͸ŵ���Ź ü�����
	double idx_nabtg_ask_self_ccls_qty;	// ���������͸ŵ��ڱ� ü�����
	double idx_nabtg_bid_ccls_qty;	// ���������͸ż���Ź ü�����
	double idx_nabtg_bid_self_ccls_qty;	// ���������͸ż��ڱ� ü�����
	double idx_abtg_ask_ccls_val;	// �������͸ŵ���Ź ü��ݾ�
	double idx_abtg_ask_self_ccls_val;	// �������͸ŵ��ڱ� ü��ݾ�
	double idx_abtg_bid_ccls_val;	// �������͸ż���Ź ü��ݾ�
	double idx_abtg_bid_self_ccls_val;	// �������͸ż��ڱ� ü��ݾ�
	double idx_nabtg_ask_ccls_val;	// ���������͸ŵ���Ź ü��ݾ�
	double idx_nabtg_ask_self_ccls_val;	// ���������͸ŵ��ڱ� ü��ݾ�
	double idx_nabtg_bid_ccls_val;	// ���������͸ż���Ź ü��ݾ�
	double idx_nabtg_bid_self_ccls_val;	// ���������͸ż��ڱ� ü��ݾ�
	// ���α׷��Ÿ� ���İ��ÿ��ܷ�	
	double post_idx_abtg_ask_rsd;	// �������͸ŵ�ȣ���ܷ�, 2011.05.30 �ű�
	double post_idx_abtg_bid_rsd;	// �������͸ż�ȣ���ܷ�, 2011.05.30 �ű�
	double post_idx_nabtg_ask_rsd;	// ���������͸ŵ�ȣ���ܷ�, 2011.05.30 �ű�
	double post_idx_nabtg_bid_rsd;	// ���������͸ż�ȣ���ܷ�, 2011.05.30 �ű�
} DF_KOSPI_PRGTRD_ASK;


// �ڽ���_���α׷��Ÿ� ��ü����
typedef struct _DF_KOSPI_PRGTRD_TOT {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����, J0
	char info_clsf[3];	// ��������, 01:�ֽ�
	char mkt_clsf;	// ���屸��, 1:�������� 2:�ڽ���
	//���α׷��Ÿ�ȣ���ܷ�	
	double idx_abtg_ask_rsd;	// �������͸ŵ�ȣ���ܷ�
	double idx_abtg_bid_rsd;	// �������͸ż�ȣ���ܷ�
	double idx_nabtg_ask_rsd;	// ���������͸ŵ�ȣ���ܷ�
	double idx_nabtg_bid_rsd;	// ���������͸ż�ȣ���ܷ�
	// ���α׷��Ÿ�ȣ������=============================================	
	double idx_abtg_ask_qty;	// �������͸ŵ�ȣ������
	double idx_abtg_bid_qty;	// �������͸ż�ȣ������
	double idx_nabtg_ask_qty;	// ���������͸ŵ�ȣ������
	double idx_nabtg_bid_qty;	// ���������͸ż�ȣ������
	// ���α׷��Ÿ� �������ÿ��ܷ�============================================ \n������:�������ϰ�����(14:50) ������ ���α׷��Ÿ�ȣ���ܷ� ���� \n������:���α׷��ŸŻ������ÿ��ܷ� ����(2011.05.30)	
	double prior_idx_abtg_ask_rsd;	// �������͸ŵ�ȣ���ܷ�
	double prior_idx_abtg_bid_rsd;	// �������͸ż�ȣ���ܷ�
	double prior_idx_nabtg_ask_rsd;	// ���������͸ŵ�ȣ���ܷ�
	double prior_idx_nabtg_bid_rsd;	// ���������͸ż�ȣ���ܷ�
	//���α׷��Ÿ�ü�᳻��	
	double idx_abtg_ask_ccls_qty;	// �������͸ŵ���Ź ü�����
	double idx_abtg_ask_self_ccls_qty;	// �������͸ŵ��ڱ� ü�����
	double idx_abtg_bid_ccls_qty;	// �������͸ż���Ź ü�����
	double idx_abtg_bid_self_ccls_qty;	// �������͸ż��ڱ� ü�����
	double idx_nabtg_ask_ccls_qty;	// ���������͸ŵ���Ź ü�����
	double idx_nabtg_ask_self_ccls_qty;	// ���������͸ŵ��ڱ� ü�����
	double idx_nabtg_bid_ccls_qty;	// ���������͸ż���Ź ü�����
	double idx_nabtg_bid_self_ccls_qty;	// ���������͸ż��ڱ� ü�����
	double idx_abtg_ask_ccls_val;	// �������͸ŵ���Ź ü��ݾ�
	double idx_abtg_ask_self_ccls_val;	// �������͸ŵ��ڱ� ü��ݾ�
	double idx_abtg_bid_ccls_val;	// �������͸ż���Ź ü��ݾ�
	double idx_abtg_bid_self_ccls_val;	// �������͸ż��ڱ� ü��ݾ�
	double idx_nabtg_ask_ccls_val;	// ���������͸ŵ���Ź ü��ݾ�
	double idx_nabtg_ask_self_ccls_val;	// ���������͸ŵ��ڱ� ü��ݾ�
	double idx_nabtg_bid_ccls_val;	// ���������͸ż���Ź ü��ݾ�
	double idx_nabtg_bid_self_ccls_val;	// ���������͸ż��ڱ� ü��ݾ�
	//���α׷��Ÿ� ���İ��ÿ��ܷ�	
	double post_idx_abtg_ask_rsd;	// �������͸ŵ�ȣ���ܷ�
	double post_idx_abtg_bid_rsd;	// �������͸ż�ȣ���ܷ�
	double post_idx_nabtg_ask_rsd;	// ���������͸ŵ�ȣ���ܷ�
	double post_idx_nabtg_bid_rsd;	// ���������͸ż�ȣ���ܷ�
} DF_KOSPI_PRGTRD_TOT;


// �ڽ���_���α׷��Ÿ� ��������
typedef struct _DF_KOSPI_PRGTRD_DCLS {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����, C5
	char info_clsf[3];	// ��������, 01:�ֽ�
	char mkt_clsf;	// ���屸��, 1:�������� 2:�ڽ���
	char isin_code[13];	// �����ڵ�
	int snr;	// �Ϸù�ȣ, 1~99999999 �����Ϸù�ȣ 2014.03.03
	double prior_dcls_new_ask_qty;	// �������ýű�ȣ�� �ŵ�����, ���� : ��\n�׸����:�ŵ����û�������->�������ýű�ȣ���ŵ�����
	double prior_dcls_new_bid_qty;	// �������ýű�ȣ�� �ż�����, ���� : ��\n�׸����:�ż����û�������->�������ýű�ȣ���ż�����
	double prior_dcls_sbmt_ask_qty;	// �������ñ�����ȣ�� �ŵ�����, ���� : ��\n�׸����:�ŵ����û�����������->�������ñ�����ȣ���ŵ�����
	double prior_dcls_sbmt_bid_qty;	// �������ñ�����ȣ�� �ż�����, ���� : ��\n�׸����:�ż����û�����������->�������ñ�����ȣ���ż�����
	double post_dcls_ask_qty;	// ���İ��øŵ�����, ���� : ��, �ű� 2011.05.03
	double post_dcls_bid_qty;	// ���İ��øż�����, ���� : ��, �ű� 2011.05.03
} DF_KOSPI_PRGTRD_DCLS;


// ���� ���α׷��Ÿ� �����ں� �Ÿ���Ȳ
typedef struct _DF_PRGTRD_BYINV_STAT {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����, P0
	char info_clsf[3];	// ��������, 01:�ֽ�
	char mkt_clsf;	// ���屸��, 1:�������� 2:�ڽ���
	char cmpt_time[7];	// ����ð�, 90�� �ֱ�
	char inv_clsf_code[5];	// �����ڱ����ڵ�, ���ڵ尪���� ����\n*�ڵ�'7000'�� ����, ������� �׸� 0���� ���� (20181210)
	double ask_abtg_ccls_qty;	// �ŵ�����ü�����
	double ask_abtg_trd_val;	// �ŵ����Ͱŷ����
	double ask_nabtg_ccls_qty;	// �ŵ�������ü�����
	double ask_nabtg_trd_val;	// �ŵ������Ͱŷ����
	double bid_abtg_ccls_qty;	// �ż�����ü�����
	double bid_abtg_trd_val;	// �ż����Ͱŷ����
	double bid_nabtg_ccls_qty;	// �ż�������ü�����
	double bid_nabtg_trd_val;	// �ż������Ͱŷ����
} DF_PRGTRD_BYINV_STAT;


// �ڽ���_���ŵ�
typedef struct _DF_KOSPI_SHORT {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����, I8
	char info_clsf[3];	// ��������, 01:�ֽ�
	char mkt_clsf;	// ���屸��, 1:�������� 2:�ڽ���
	char isin_code[13];	// �����ڵ�, ǥ���ڵ�
	int snr;	// �Ϸù�ȣ, 1~99999999 �����Ϸù�ȣ 2014.03.03
	double short_brwg_ask_ccls_qty;	// ���ŵ��������Ǹŵ� ü�����, ����:��
	double short_brwg_ask_trd_val;	// ���ŵ��������Ǹŵ� �ŷ����, ����:��
} DF_KOSPI_SHORT;


// �ڽ���_Buy-in_�������
typedef struct _DF_KOSPI_BIN_EXCQ {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����, O4
	char info_clsf[3];	// ��������, 01:�ֽ�
	char mkt_clsf;	// ���屸��, 1:��������, 2:�ڽ���, 8:�ڳؽ�
	char isin_code[13];	// �����ڵ�, ǥ���ڵ� �Ǵ� "999999999999" ���߰��̵� ����
	int snr;	// �Ϸù�ȣ, �� Buy-in�����ڵ庰�� �Ϸù�ȣ ����
	char trsm_date[9];	// ��������, YYYYMMDD
	char bin_clsf_code;	// Buy-in�����ڵ�, 1: �Ϲ� Buy-in, 2: ���� Buy-in
	int scrt_grp_id;	// ���Ǳ׷�ID, ST:�ֽ�, MF:��������ȸ��, RT:����, SC:��������ȸ��,\nIF:������������ȸ��, DR:��Ź����, SW:�����μ�������,\nSR:�����μ�������, EW:�ֽĿ���Ʈ����, EF:���������ݵ�,\nBC:��������, FE:�ؿ�ETF, FS:�ؿܿ���,\nEN:ETN(2014.11.17)
	double bin_exc_qty;	// Buy-in �������
} DF_KOSPI_BIN_EXCQ;


// �ڽ���_Buy-in_�������
typedef struct _DF_KOSDQ_BIN_EXCQ {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����, O4
	char info_clsf[3];	// ��������, 01:�ֽ�
	char mkt_clsf;	// ���屸��, 1:��������, 2:�ڽ���, 8:�ڳؽ�
	char isin_code[13];	// �����ڵ�, ǥ���ڵ� �Ǵ� "999999999999" ���߰��̵� ����
	int snr;	// �Ϸù�ȣ, �� Buy-in�����ڵ庰�� �Ϸù�ȣ ����
	char trsm_date[9];	// ��������, YYYYMMDD
	char bin_clsf_code;	// Buy-in�����ڵ�, 1: �Ϲ� Buy-in, 2: ���� Buy-in
	int scrt_grp_id;	// ���Ǳ׷�ID, ST:�ֽ�, MF:��������ȸ��, RT:����, SC:��������ȸ��,\nIF:������������ȸ��, DR:��Ź����, SW:�����μ�������,\nSR:�����μ�������, EW:�ֽĿ���Ʈ����, EF:���������ݵ�,\nBC:��������, FE:�ؿ�ETF, FS:�ؿܿ���\nEN:ETN(2014.11.17)
	double bin_exc_qty;	// Buy-in �������
} DF_KOSDQ_BIN_EXCQ;


// �ڳؽ�_Buy-in_�������
typedef struct _DF_KONEX_BIN_EXCQ {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����, O4
	char info_clsf[3];	// ��������, 01:�ֽ�
	char mkt_clsf;	// ���屸��, 8:�ڳؽ�
	char isin_code[13];	// �����ڵ�, ǥ���ڵ� �Ǵ� "999999999999" ���߰��̵� ����
	int snr;	// �Ϸù�ȣ, �� Buy-in�����ڵ庰�� �Ϸù�ȣ ����
	char trsm_date[9];	// ��������, YYYYMMDD
	char bin_clsf_code;	// Buy-in�����ڵ�, 1: �Ϲ� Buy-in, 2: ���� Buy-in
	int scrt_grp_id;	// ���Ǳ׷�ID, ST:�ֽ�, MF:��������ȸ��, RT:����, SC:��������ȸ��,\nIF:������������ȸ��, DR:��Ź����, SW:�����μ�������,\nSR:�����μ�������, EW:�ֽĿ���Ʈ����, EF:���������ݵ�,\nBC:��������, FE:�ؿ�ETF, FS:�ؿܿ���
	double bin_exc_qty;	// Buy-in �������
} DF_KONEX_BIN_EXCQ;


// �ڽ���_�ü�����
typedef struct _DF_KOSPI_MKT_PRC_CLS {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����, B1:���� B2:�ü�REC
	char info_clsf[3];	// ��������, 01:�ֽ� 02:ELW
	char mkt_clsf;	// ���屸��, 1:�������� 2:�ڽ���
	char isin_code[13];	// �����ڵ�, ǥ���ڵ�
	int stk_snr;	// �����Ϸù�ȣ, �����ġ(A0)�� �����Ϸù�ȣ
	char flct_clsf;	// �������, 0:�ǴܺҰ� 1:���� 2:��� 3:���� 4:���� 5:�϶�
	int prev_ctrs;	// ���ϴ��, ����:��
	int cur_prc;	// ���簡
	int open;	// �ð�, ������ �ð�
	int high;	// ��, ������ ��
	int low;	// ����, ������ ����
	int ask_prc;	// �ŵ�ȣ��, B1�� 0�� SET
	int bid_prc;	// �ż�ȣ��, B1�� 0�� SET
	double cum_ccls_qty;	// ����ü�����, ����:�� �ؽð��ܴ��ϰ�, BUY-IN�� ������ ��� ü����� �ջ�
	double cum_trd_val;	// �����ŷ����, ����:�� �ؽð��ܴ��ϰ�, BUY-IN�� ������ ��� �ŷ���� �ջ�
	char trend_flg;	// �Ǽ�/�⼼ ����, 0:�ʱⰪ 1:�Ǽ� 2:�⼼ 3:�ŷ��� 4:�ð����ذ������� �⼼
	char brd_evt_id[4];	// �����̺�ƮID, B1/B2 ������ �����̺�ƮID ������(���� ���°��� ���۵� �� ����). ����, �ش� �׸� '000' ���� ����. 2014.03.24)
	char brd_id[3];	// ����ID, �� �ڵ尪���� ����
	char trsp_flg;	// �ŷ���������, Y, N
	double bopen_ofhr_ccls_qty;	// �尳�����ð������� ü�����, �뷮, �ٽ����� ����, ����:��
	double bopen_ofhr_trd_val;	// �尳�����ð������� �ŷ����, �뷮, �ٽ����� ����, ����:��
	double opr_time_ccls_qty;	// ������ü�����, �뷮, �ٽ����� ����, ����:��
	double opr_time_trd_val;	// ������ŷ����, �뷮, �ٽ����� ����, ����:��
	double ofhr_cls_ccls_qty;	// �������Ľð������� ü�����, �뷮, �ٽ����� ����, ����:��
	double ofhr_cls_trd_val;	// �������Ľð������� �ŷ����, �뷮, �ٽ����� ����, ����:��
	char elw_ely_cls_flg;	// ELW�������Ῡ��, Y,N ��������ELW �� ������ Default 'N' SET 2010.08.30
	int elw_ely_cls_time;	// ELW��������ð�, HHMMSS, ELW�������Ῡ�ΰ� 'Y'�� ��츸 ����
	int cmpt_msv_dir_clsf;	// ����뷮 ���ⱸ��, 0:�ش����, 1:�ŵ�, 2:�ż�
	double gen_bin_ccls_qty;	// �Ϲ� Buy-in ü�����, ����:��
	double gen_bin_ccls_trd_val;	// �Ϲ� Buy-in �ŷ����, ����:��
	double day_bin_ccls_qty;	// ���� Buy-in ü�����, ����:��
	double day_bin_ccls_trd_val;	// ���� Buy-in �ŷ����, ����:��
} DF_KOSPI_MKT_PRC_CLS;


// �ڽ���_�ü�RECOVERY
typedef struct _DF_KOSPI_MKT_PRC_RCVR {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����, B1:���� B2:�ü�REC
	char info_clsf[3];	// ��������, 01:�ֽ� 02:ELW
	char mkt_clsf;	// ���屸��, 1:�������� 2:�ڽ���
	char isin_code[13];	// �����ڵ�, ǥ���ڵ�
	int stk_snr;	// �����Ϸù�ȣ, �����ġ(A0)�� �����Ϸù�ȣ
	char flct_clsf;	// �������, 0:�ǴܺҰ� 1:���� 2:��� 3:���� 4:���� 5:�϶�
	int prev_ctrs;	// ���ϴ��, ����:��
	int cur_prc;	// ���簡
	int open;	// �ð�, ������ �ð�
	int high;	// ��, ������ ��
	int low;	// ����, ������ ����
	int ask_prc;	// �ŵ�ȣ��, B1�� 0�� SET
	int bid_prc;	// �ż�ȣ��, B1�� 0�� SET
	double cum_ccls_qty;	// ����ü�����, ����:�� �ؽð��ܴ��ϰ�, BUY-IN�� ������ ��� ü����� �ջ�
	double cum_trd_val;	// �����ŷ����, ����:�� �ؽð��ܴ��ϰ�, BUY-IN�� ������ ��� �ŷ���� �ջ�
	char trend_flg;	// �Ǽ�/�⼼ ����, 0:�ʱⰪ 1:�Ǽ� 2:�⼼ 3:�ŷ��� 4:�ð����ذ������� �⼼
	char brd_evt_id[4];	// �����̺�ƮID, B1/B2 ������ �����̺�ƮID ������(���� ���°��� ���۵� �� ����). ����, �ش� �׸� '000' ���� ����. 2014.03.24)
	char brd_id[3];	// ����ID, �� �ڵ尪���� ����
	char trsp_flg;	// �ŷ���������, Y, N
	double bopen_ofhr_ccls_qty;	// �尳�����ð������� ü�����, �뷮, �ٽ����� ����, ����:��
	double bopen_ofhr_trd_val;	// �尳�����ð������� �ŷ����, �뷮, �ٽ����� ����, ����:��
	double opr_time_ccls_qty;	// ������ü�����, �뷮, �ٽ����� ����, ����:��
	double opr_time_trd_val;	// ������ŷ����, �뷮, �ٽ����� ����, ����:��
	double ofhr_cls_ccls_qty;	// �������Ľð������� ü�����, �뷮, �ٽ����� ����, ����:��
	double ofhr_cls_trd_val;	// �������Ľð������� �ŷ����, �뷮, �ٽ����� ����, ����:��
	char elw_ely_cls_flg;	// ELW�������Ῡ��, Y,N ��������ELW �� ������ Default 'N' SET
	int elw_ely_cls_time;	// ELW��������ð�, HHMMSS, ELW�������Ῡ�ΰ� 'Y'�� ��츸 ����
	int cmpt_msv_dir_clsf;	// ����뷮 ���ⱸ��, 0:�ش����, 1:�ŵ�, 2:�ż�
	double gen_bin_ccls_qty;	// �Ϲ� Buy-in ü�����, ����:��
	double gen_bin_ccls_trd_val;	// �Ϲ� Buy-in �ŷ����, ����:��
	double day_bin_ccls_qty;	// ���� Buy-in ü�����, ����:��
	double day_bin_ccls_trd_val;	// ���� Buy-in �ŷ����, ����:��
} DF_KOSPI_MKT_PRC_RCVR;


// �ڽ��� �ܱ��� ������������_Ȯ��ġ
typedef struct _DF_KOSPI_FRGN_INV_INFO {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����, F1
	char info_clsf[3];	// ��������, 01:�ֽ� 90:��Ÿ
	char mkt_clsf;	// ���屸��, 1:�������� 2:�ڽ��� 3:�������� 7:ä��
	char isin_code[13];	// �����ڵ�, ǥ���ڵ�
	int snr;	// �Ϸù�ȣ, 1~99999999 �Ǽ�üũ��
	char trd_date[9];	// �Ÿ�����, YYYYMMDD
	double stk_lim_ratio;	// �����ѵ�����, 9V9999 (��:15%�϶� �� 01500���� ����)
	double psn_lim_ratio;	// �����ѵ�����, 9V9999 (��:15%�϶� �� 01500���� ����)
	double stk_lstd;	// �����ֽļ�, ����:��
	double ordbl_qty;	// �ֹ����ɼ���, ����:��
	char lim_xhs_clsf;	// �ѵ���������, 0:���� 1:�ѵ����� 2:�ѵ�����ű����� 3:�ѵ���������
} DF_KOSPI_FRGN_INV_INFO;


// �ڽ��� �ܱ��� �ֹ����ɼ���
typedef struct _DF_KOSPI_FRGN_ORDL_QTY {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����, F2
	char info_clsf[3];	// ��������, 01:�ֽ� 90:��Ÿ
	char mkt_clsf;	// ���屸��, 1:�������� 2:�ڽ��� 3:�������� 7:ä��
	char isin_code[13];	// �����ڵ�, ǥ���ڵ�
	double ordbl_qty;	// �ֹ����ɼ���, ����:��(����� ����)
	char data_type[3];	// ����������, 01:�ֹ����ɼ���(�ǽð�) 07:����ġ�ֹ����ɼ���(����)
} DF_KOSPI_FRGN_ORDL_QTY;


// �ڽ��� �ܱ��� �����ֹ�����_����
typedef struct _DF_KOSPI_FRGN_RSVD_ORD_CNCL {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����, F3
	char info_clsf[3];	// ��������, 01:�ֽ�
	char mkt_clsf;	// ���屸��, 1:�������� 2:�ڽ��� 3:��������
	char isin_code[13];	// �����ڵ�, ǥ���ڵ�
	char data_type[3];	// ����������, 01:�����ֹ����� 02:�����ֹ�����
	char proc_clsf;	// ó������, 1:���� 2:���
	char rsvd_ord_date[9];	// �����ֹ�����, YYYYMMDD
	char rsvd_ord_st_time[5];	// �����ֹ����۽ð�, HHMM
	char rsvd_ord_ed_time[5];	// �����ֹ�����ð�, HHMM
} DF_KOSPI_FRGN_RSVD_ORD_CNCL;


// �ڽ��� �ܱ��� Ȯ��ġ������������
typedef struct _DF_KOSPI_FRGN_CFRM_DATA {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����, F4
	char info_clsf[3];	// ��������, 01:�ֽ� 90:��Ÿ
	char mkt_clsf;	// ���屸��, 1:�������� 2:�ڽ��� 3:�������� 7:ä��
	char isin_code[13];	// �����ڵ�, ǥ���ڵ�
	double stk_lim_ratio;	// �����ѵ�����, 9V9999 (��:15%�϶� �� 01500���� ����)
	double psn_lim_ratio;	// �����ѵ�����, 9V9999 (��:15%�϶� �� 01500���� ����)
	double stk_lstd;	// �����ֽļ�, ����:��
	double ordbl_qty;	// �ֹ����ɼ���, ����:��
	char lim_xhs_clsf;	// �ѵ���������, 0:���� 1:�ѵ��ʰ� 2:�߰� 3:����
} DF_KOSPI_FRGN_CFRM_DATA;


// �ڽ��� �ܱ��� �ѵ�������ܸŸ�
typedef struct _DF_KOSPI_FRGN_LMT_XHS {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����, F5
	char info_clsf[3];	// ��������, 01:�ֽ�
	char mkt_clsf;	// ���屸��, 1:�������� 2:�ڽ��� 3:��������
	char isin_code[13];	// �����ڵ�, ǥ���ڵ�
	char clsf;	// ����, 1:�ܰ��Է� 2:�ܰ����
	int qty;	// ����, ����:��
	int prc;	// ����, ����:��
	char proc_time[9];	// ó���ð�, HHMMSSMM
} DF_KOSPI_FRGN_LMT_XHS;


// �ڽ��� �ܱ��� �Ÿ�_������Ȳ
typedef struct _DF_KOSPI_FRGN_TRD_STAT {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����, F6
	char info_clsf[3];	// ��������, 01:�ֽ�
	char mkt_clsf;	// ���屸��, 1:�������� 2:�ڽ���
	int snr;	// �Ϸù�ȣ, 1~99999999 �Ǽ�üũ��
	char clsf;	// ����, 2:�ŷ��ҸŸ���Ȳ 3:�ŷ��Ұ�����Ȳ \n9:�ڽ��ڸŸ���Ȳ 0:�ڽ��ڰ�����Ȳ
	double tot_bid_qty;	// �Ѹż�����, ����:��
	double tot_bid_val;	// �Ѹż��ݾ�, ����:��
	double tot_ask_qty;	// �Ѹŵ�����, ����:��
	double tot_ask_val;	// �Ѹŵ��ݾ�, ����:��
	double net_bid_qty;	// ���ż�����, ����:��
	double net_val_qty;	// ���ż��ݾ�, ����:��
} DF_KOSPI_FRGN_TRD_STAT;


// �ڽ��� �ܱ��� �ѵ�������ܸŸ�
typedef struct _DF_KOSDAQ_FRGN_LMT_XHS {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����, F5
	char info_clsf[3];	// ��������, 01:�ֽ�
	char mkt_clsf;	// ���屸��, 1:�������� 2:�ڽ��� 3:��������
	char isin_code[13];	// �����ڵ�, ǥ���ڵ�
	char clsf;	// ����, 1:�ܰ��Է� 2:�ܰ����
	int qty;	// ����, ����:��
	int prc;	// ����, ����:��
	char proc_time[9];	// ó���ð�, HHMMSSMM
} DF_KOSDAQ_FRGN_LMT_XHS;


// �ڽ��� �ܱ��� �Ÿ�_������Ȳ
typedef struct _DF_KOSDAQ_FRGN_TRD_STAT {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����, F6
	char info_clsf[3];	// ��������, 01:�ֽ�
	char mkt_clsf;	// ���屸��, 1:�������� 2:�ڽ��� 8:�ڳؽ�
	int snr;	// �Ϸù�ȣ, 1~99999999 �Ǽ�üũ��
	char clsf;	// ����, 2:�ŷ��ҸŸ���Ȳ 3:�ŷ��Ұ�����Ȳ \n9:�ڽ��ڸŸ���Ȳ 0:�ڽ��ڰ�����Ȳ\n5:�ڳؽ��Ÿ���Ȳ 6:�ڳؽ�������Ȳ
	double tot_bid_qty;	// �Ѹż�����, ����:��
	double tot_bid_val;	// �Ѹż��ݾ�, ����:��
	double tot_ask_qty;	// �Ѹŵ�����, ����:��
	double tot_ask_val;	// �Ѹŵ��ݾ�, ����:��
	double net_bid_qty;	// ���ż�����, ����:��
	double net_val_qty;	// ���ż��ݾ�, ����:��
} DF_KOSDAQ_FRGN_TRD_STAT;


// �ڽ��� �ܱ��� �����ֹ�����_����
typedef struct _DF_KOSDAQ_FRGN_RSVD_ORD_CNCL {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����, F3
	char info_clsf[3];	// ��������, 01:�ֽ�
	char mkt_clsf;	// ���屸��, 1:�������� 2:�ڽ��� 3:��������
	char isin_code[13];	// �����ڵ�, ǥ���ڵ�
	char data_type[3];	// ����������, 01:�����ֹ����� 02:�����ֹ�����
	char proc_clsf;	// ó������, 1:���� 2:���
	char rsvd_ord_date[9];	// �����ֹ�����, YYYYMMDD
	char rsvd_ord_st_time[5];	// �����ֹ����۽ð�, HHMM
	char rsvd_ord_ed_time[5];	// �����ֹ�����ð�, HHMM
} DF_KOSDAQ_FRGN_RSVD_ORD_CNCL;


// �ڽ��� �ܱ��� ������������_Ȯ��ġ
typedef struct _DF_KOSDAQ_FRGN_INV_INFO {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����, F1
	char info_clsf[3];	// ��������, 01:�ֽ� 90:��Ÿ
	char mkt_clsf;	// ���屸��, 1:�������� 2:�ڽ��� 3:�������� 7:ä��
	char isin_code[13];	// �����ڵ�, ǥ���ڵ�
	int snr;	// �Ϸù�ȣ, 1~99999999 �Ǽ�üũ��
	char trd_date[9];	// �Ÿ�����, YYYYMMDD
	double stk_lim_ratio;	// �����ѵ�����, 9V9999 (��:15%�϶� �� 01500���� ����)
	double psn_lim_ratio;	// �����ѵ�����, 9V9999 (��:15%�϶� �� 01500���� ����)
	double stk_lstd;	// �����ֽļ�, ����:��
	double ordbl_qty;	// �ֹ����ɼ���, ����:��
	char lim_xhs_clsf;	// �ѵ���������, 0:���� 1:�ѵ����� 2:�ѵ�����ű����� 3:�ѵ���������
} DF_KOSDAQ_FRGN_INV_INFO;


// �ڽ��� �ܱ��� �ֹ����ɼ���
typedef struct _DF_KOSDAQ_FRGN_ORDL_QTY {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����, F2
	char info_clsf[3];	// ��������, 01:�ֽ� 90:��Ÿ
	char mkt_clsf;	// ���屸��, 1:�������� 2:�ڽ��� 3:�������� 7:ä��
	char isin_code[13];	// �����ڵ�, ǥ���ڵ�
	double ordbl_qty;	// �ֹ����ɼ���, ����:��(����� ����)
	char proc_clsf[3];	// ����������, 01:�ֹ����ɼ���(�ǽð�) 07:����ġ�ֹ����ɼ���(����)
} DF_KOSDAQ_FRGN_ORDL_QTY;


// �ڽ��� �ܱ��� Ȯ��ġ������������
typedef struct _DF_KOSDAQ_FRGN_CFRM_DATA {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����, F4
	char info_clsf[3];	// ��������, 01:�ֽ� 90:��Ÿ
	char mkt_clsf;	// ���屸��, 1:�������� 2:�ڽ��� 3:�������� 7:ä��
	char isin_code[13];	// �����ڵ�, ǥ���ڵ�
	double stk_lim_ratio;	// �����ѵ�����, 9V9999 (��:15%�϶� �� 01500���� ����)
	double psn_lim_ratio;	// �����ѵ�����, 9V9999 (��:15%�϶� �� 01500���� ����)
	double stk_lstd;	// �����ֽļ�, ����:��
	double ordbl_qty;	// �ֹ����ɼ���, ����:��
	char lim_xhs_clsf;	// �ѵ���������, 0:���� 1:�ѵ��ʰ� 2:�߰� 3:����
} DF_KOSDAQ_FRGN_CFRM_DATA;


// �ڳؽ� �ܱ��� ������������_Ȯ��ġ
typedef struct _DF_KONEX_FRGN_INV_INFO {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����, F1
	char info_clsf[3];	// ��������, 01:�ֽ� 90:��Ÿ
	char mkt_clsf;	// ���屸��, 1:�������� 2:�ڽ��� 3:�������� 7:ä�� 8:�ڳؽ�
	char isin_code[13];	// �����ڵ�, ǥ���ڵ�
	int snr;	// �Ϸù�ȣ, 1~99999999 �Ǽ�üũ��
	char trd_date[9];	// �Ÿ�����, YYYYMMDD
	double stk_lim_ratio;	// �����ѵ�����, 9V9999 (��:15%�϶� �� 01500���� ����)
	double psn_lim_ratio;	// �����ѵ�����, 9V9999 (��:15%�϶� �� 01500���� ����)
	double stk_lstd;	// �����ֽļ�, ����:��
	double ordbl_qty;	// �ֹ����ɼ���, ����:��
	char lim_xhs_clsf;	// �ѵ���������, 0:���� 1:�ѵ����� 2:�ѵ�����ű����� 3:�ѵ���������
} DF_KONEX_FRGN_INV_INFO;


// �ڳؽ� �ܱ��� �ֹ����ɼ���
typedef struct _DF_KONEX_FRGN_ORDL_QTY {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����, F2
	char info_clsf[3];	// ��������, 01:�ֽ� 90:��Ÿ
	char mkt_clsf;	// ���屸��, 1:�������� 2:�ڽ��� 3:�������� 7:ä�� 8:�ڳؽ�
	char isin_code[13];	// �����ڵ�, ǥ���ڵ�
	double ordbl_qty;	// �ֹ����ɼ���, ����:��(����� ����)
	char data_type[3];	// ����������, 01:�ֹ����ɼ���(�ǽð�) 07:����ġ�ֹ����ɼ���(����)
} DF_KONEX_FRGN_ORDL_QTY;


// �ڳؽ� �ܱ��� �����ֹ�����_����
typedef struct _DF_KONEX_FRGN_RSVD_ORD_CNCL {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����, F3
	char info_clsf[3];	// ��������, 01:�ֽ�
	char mkt_clsf;	// ���屸��, 1:�������� 2:�ڽ��� 3:�������� 8:�ڳؽ�
	char isin_code[13];	// �����ڵ�, ǥ���ڵ�
	char data_type[3];	// ����������, 01:�����ֹ����� 02:�����ֹ�����
	char proc_clsf;	// ó������, 1:���� 2:���
	char rsvd_ord_date[9];	// �����ֹ�����, YYYYMMDD
	char rsvd_ord_st_time[5];	// �����ֹ����۽ð�, HHMM
	char rsvd_ord_ed_time[5];	// �����ֹ�����ð�, HHMM
} DF_KONEX_FRGN_RSVD_ORD_CNCL;


// �ڳؽ� �ܱ��� Ȯ��ġ������������
typedef struct _DF_KONEX_FRGN_CFRM_DATA {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����, F4
	char info_clsf[3];	// ��������, 01:�ֽ� 90:��Ÿ
	char mkt_clsf;	// ���屸��, 1:�������� 2:�ڽ��� 3:�������� 7:ä�� 8:�ڳؽ�
	char isin_code[13];	// �����ڵ�, ǥ���ڵ�
	double stk_lim_ratio;	// �����ѵ�����, 9V9999 (��:15%�϶� �� 01500���� ����)
	double psn_lim_ratio;	// �����ѵ�����, 9V9999 (��:15%�϶� �� 01500���� ����)
	double stk_lstd;	// �����ֽļ�, ����:��
	double ordbl_qty;	// �ֹ����ɼ���, ����:��
	char lim_xhs_clsf;	// �ѵ���������, 0:���� 1:�ѵ��ʰ� 2:�߰� 3:����
} DF_KONEX_FRGN_CFRM_DATA;


// �ڳؽ� �ܱ��� �ѵ�������ܸŸ�
typedef struct _DF_KONEX_FRGN_LMT_XHS {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����, F5
	char info_clsf[3];	// ��������, 01:�ֽ�
	char mkt_clsf;	// ���屸��, 1:�������� 2:�ڽ��� 3:�������� 8:�ڳؽ�
	char isin_code[13];	// �����ڵ�, ǥ���ڵ�
	char clsf;	// ����, 1:�ܰ��Է� 2:�ܰ����
	int qty;	// ����, ����:��
	int prc;	// ����, ����:��
	char proc_time[9];	// ó���ð�, HHMMSSMM
} DF_KONEX_FRGN_LMT_XHS;


// �ڳؽ� �ܱ��� �Ÿ�_������Ȳ
typedef struct _DF_KONEX_FRGN_TRD_STAT {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����, F6
	char info_clsf[3];	// ��������, 01:�ֽ�
	char mkt_clsf;	// ���屸��, 1:�������� 2:�ڽ��� 8:�ڳؽ�
	int snr;	// �Ϸù�ȣ, 1~99999999 �Ǽ�üũ��
	char clsf;	// ����, 2:�ŷ��ҸŸ���Ȳ 3:�ŷ��Ұ�����Ȳ \n9:�ڽ��ڸŸ���Ȳ 0:�ڽ��ڰ�����Ȳ\n5:�ڳؽ��Ÿ���Ȳ 6:�ڳؽ�������Ȳ
	double tot_bid_qty;	// �Ѹż�����, ����:��
	double tot_bid_val;	// �Ѹż��ݾ�, ����:��
	double tot_ask_qty;	// �Ѹŵ�����, ����:��
	double tot_ask_val;	// �Ѹŵ��ݾ�, ����:��
	double net_bid_qty;	// ���ż�����, ����:��
	double net_val_qty;	// ���ż��ݾ�, ����:��
} DF_KONEX_FRGN_TRD_STAT;





// ���� ������ �����ͷ�
typedef struct _DF_KOSPI_BYIND_DYR {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����, P2
	char info_clsf[3];	// ��������, 01:�ֽ�
	char mkt_clsf;	// ���屸��, 1:�������� 2:�ڽ���
	char idx_ind_code[4];	// ���������ڵ�, ���ڵ尪���� ����
	double dyr;	// �����ͷ�, 99999V99
} DF_KOSPI_BYIND_DYR;


// ELW �����ġ
typedef struct _DF_ELW_STK_ARNG {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����, A1
	char info_clsf[3];	// ��������, 01:�ֽ�
	char mkt_clsf;	// ���屸��, 1:��������
	char isin_code[13];	// �����ڵ�, ǥ���ڵ�
	int snr;	// �Ϸù�ȣ, 1~99999999 �Ǽ�üũ��
	char elw_ptcp_kor_nm[81];	// ELW������������� �ѱ۸�
	char elw_ptcp_eng_nm[81];	// ELW������������� ������
	char elw_ptcp_nr[6];	// ELW������������� ��ȣ, ELW����ȸ������ ��ȣ(�����, ������ ���о���)\n��) ��00001��
	// ELW�����������ID OCCURS 55*3 = 15	
	char elw_comp_stk_mtk_id1[4];	// ELW�����������ID1, ���������� �Ҽӵ� ����ID(��:����:STK,�ڽ���:KSQ)\n*�����ڻ��� ������ ��츸 �ش�
	char elw_comp_stk_mtk_id2[4];	// ELW�����������ID2, ���������� �Ҽӵ� ����ID(��:����:STK,�ڽ���:KSQ)\n*�����ڻ��� ������ ��츸 �ش�
	char elw_comp_stk_mtk_id3[4];	// ELW�����������ID3, ���������� �Ҽӵ� ����ID(��:����:STK,�ڽ���:KSQ)\n*�����ڻ��� ������ ��츸 �ش�
	char elw_comp_stk_mtk_id4[4];	// ELW�����������ID4, ���������� �Ҽӵ� ����ID(��:����:STK,�ڽ���:KSQ)\n*�����ڻ��� ������ ��츸 �ش�
	char elw_comp_stk_mtk_id5[4];	// ELW�����������ID5, ���������� �Ҽӵ� ����ID(��:����:STK,�ڽ���:KSQ)\n*�����ڻ��� ������ ��츸 �ش�
	// ELW�����ڻ� OCCURS 55��12 = 60	
	char elw_base_ast1[13];	// ELW�����ڻ�1, �����ڻ��� ������ ��� SPACE. ELW���������ڵ� ����
	char elw_base_ast2[13];	// ELW�����ڻ�2, �����ڻ��� ������ ��� SPACE. ELW���������ڵ� ����
	char elw_base_ast3[13];	// ELW�����ڻ�3, �����ڻ��� ������ ��� SPACE. ELW���������ڵ� ����
	char elw_base_ast4[13];	// ELW�����ڻ�4, �����ڻ��� ������ ��� SPACE. ELW���������ڵ� ����
	char elw_base_ast5[13];	// ELW�����ڻ�5, �����ڻ��� ������ ��� SPACE. ELW���������ڵ� ����
	// ELW�����ڻ걸����OCCUR 55��12 = 60	
	double elw_base_ast_rate1;	// ELW�����ڻ걸����1, 9(6)V9(6)
	double elw_base_ast_rate2;	// ELW�����ڻ걸����2, 9(6)V9(6)
	double elw_base_ast_rate3;	// ELW�����ڻ걸����3, 9(6)V9(6)
	double elw_base_ast_rate4;	// ELW�����ڻ걸����4, 9(6)V9(6)
	double elw_base_ast_rate5;	// ELW�����ڻ걸����5, 9(6)V9(6)
	char idx_mkt_clsf_code;	// �����Ҽӽ��屸���ڵ�, 1:�������� 2:�ڽ��� 3:���� 4:GICS 8:MF(�Ű�) 9:�ؿ�\nS:S&P/KRX B:ä�� C:��ȭ M:��ǰ R:�ε��� 2009.07.27\n*�����ڻ��� ������ ��츸 �ش�\n*����Ī:ELW�����ڻ���屸���ڵ�
	char elw_idx_ind_code[4];	// ELW���������ڵ�, ELW�����ڻ���屸���ڵ尡 ���������� ���� ����������\n���������ڵ�, �ڽ����� ���� �ڽ����� �����ڵ�,\n�ؿܽ����� ���� �ؿ������� ���� ������ �ڵ�����\n���ڵ尪���� - ������������ڵ�ǥ ����
	char elw_rgt_type_code;	// ELW�Ǹ������ڵ�, C:�� P:ǲ Z:��Ÿ
	char elw_rgt_exc_type_code;	// ELW�Ǹ���������ڵ�, A:�̱��� E:������ Z:�ش����
	char elw_fin_pymt_code;	// ELW������������ڵ�, A:����+�ǹ��μ������� C:���ݰ��� D:�ǹ��μ�������
	char elw_fin_trd_date[9];	// ELW�����ŷ�����, YYYYMMDD
	char elw_pymt_date[9];	// ELW��������, YYYYMMDD
	double elw_base_ast_prc;	// ELW�����ڻ���ʰ���, 9(9)V9(3) �ذ��߰��̵� ����
	char elw_mtr_rgt_exc_cntt[201];	// ELW����Ǹ���系��, ELW�Ǹ���系��->ELW����Ǹ���系�� 2010.08.30
	double elw_cnvr;	// ELW��ȯ����, 9(6)V9(6)
	double elw_rise_ptcp_rate;	// ELW���ݻ��������, 9(6)V9(2)
	double elw_min_pymt_rate;	// ELW�ּ����޺���, 9(6)V9(2) ELW������->ELW�ּ����޺��� 2010.08.30
	double elw_cfrm_pymt_val;	// ELWȮ�����޾�, 9(18)V9(3)
	char elw_pymt_prx_nm[81];	// ELW���޴븮�θ�
	char elw_mtr_assm_type[201];	// ELW�����򰡰��ݹ��
	char elw_rgt_type;	// ELW�Ǹ�����, ELW�̻��ɼǱ����ڵ� -> ELW�Ǹ�����\n0:ǥ�ؿɼ� 1:�����пɼ� 2:��������ɼ�(2010.08.30)
	double elw_lp_hld_qty;	// ELW LP��������, 15 -> 12 2014.03.03
} DF_ELW_STK_ARNG;


// ��������ELW_�����ġ
typedef struct _DF_ELY_CLS_ELW_STK_ARNG {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����, M6
	char info_clsf[3];	// ��������, 01:�ֽ�
	char mkt_clsf;	// ���屸��, 1:��������
	char isin_code[13];	// �����ڵ�, ǥ���ڵ�
	int snr;	// �Ϸù�ȣ, 1~99999999 �Ǽ�üũ��
	double elw_ely_cls_base_prc;	// ELW��������߻� ���ذ���, 9(9)V9(3), �����������Ʈ�� �������� �̺�Ʈ �߻��� \n������ �Ǵ� ����(2010.08.30)
	char elw_ely_cls_rgt_exe_cntt[201];	// ELW��������Ǹ���� ����, ELW��������Ǹ���系��(2010.08.30)
	char elw_ely_cls_assm_type[301];	// ELW���������� ���ݹ��, ��������� �ش� ������ �򰡰����� �����ϴ� ����� \n��� (2010.08.30)
} DF_ELY_CLS_ELW_STK_ARNG;


// ��������ELW �򰡱Ⱓ �� �����ڻ������
typedef struct _DF_ELY_CLS_ELW_ASSET_HLP {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����, M5
	char info_clsf[3];	// ��������, 01:�ֽ�
	char mkt_clsf;	// ���屸��, 1:��������
	char isin_code[13];	// �����ڵ�, Knockout �߻��� ELW�� �����ڵ�
	int snr;	// �Ϸù�ȣ, 1~99999999 �Ǽ�üũ��
	char trsm_date[9];	// ��������
	char base_ast_trd_date[9];	// �����ڻ�Ÿ�����
	char ko_trgg_date[9];	// KO�߻�����, Knockout �߻�����
	char noon_clsf_code;	// �������ı����ڵ�, Knockout �����߻��� ��� �� ���߰��̵� ����\n A : KO�������� 12��\n P: 12�ú��� �����帶��\nKnockout ���� �߻��� ���\n P: KO�������� �����帶��\nKnockout �߻� �� �� �������� ��� \n A: �尳�ú��� 12��\n P: 12�ú��� ������ ����
	char comp_stk_code[13];	// ���������ڵ�, ELW�� �����ϴ� �����ڻ��� �����ڵ�(ISIN�����ڵ�)
	char elw_idx_mkt_clsf_code;	// ELW�����Ҽӽ��屸���ڵ�, 1:��������, 2:�ڽ���
	char idx_ind_code[4];	// ���������ڵ�, ELW�����ڻ���屸���ڵ尡 ���������� ���� ����������\n���������ڵ�, �ڽ����� ���� �ڽ����� �����ڵ�,\n�ؿܽ����� ���� �ؿ������� ���� ������ �ڵ�����\n���ڵ尪���� - ������������ڵ�ǥ ����
	char high[12];	// ��, 9(9)V9(2) ����ð����� �����ڻ��� ��\nKO�߻��ð��� ������ �����̸� "00000000000"
	char low[12];	// ����, 9(9)V9(2) ����ð����� �����ڻ��� ����\nKO�߻��ð��� ������ �����̸� "00000000000"
} DF_ELY_CLS_ELW_ASSET_HLP;


// ELW_�ü�RECOVERY
typedef struct _DF_ELW_MKT_PRC_RCVR {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����, B1:���� B2:�ü�REC
	char info_clsf[3];	// ��������, 01:�ֽ� 02:ELW
	char mkt_clsf;	// ���屸��, 1:�������� 2:�ڽ���
	char isin_code[13];	// �����ڵ�, ǥ���ڵ�
	int stk_snr;	// �����Ϸù�ȣ, �����ġ(A0)�� �����Ϸù�ȣ
	char flct_clsf;	// �������, 0:�ǴܺҰ� 1:���� 2:��� 3:���� 4:���� 5:�϶�
	int prev_ctrs;	// ���ϴ��, ����:��
	int cur_prc;	// ���簡
	int open;	// �ð�, ������ �ð�
	int high;	// ��, ������ ��
	int low;	// ����, ������ ����
	int ask_prc;	// �ŵ�ȣ��, B1�� 0�� SET
	int bid_prc;	// �ż�ȣ��, B1�� 0�� SET
	double cum_ccls_qty;	// ����ü�����, ����:�� �ؽð��ܴ��ϰ�, BUY-IN�� ������ ��� ü����� �ջ�
	double cum_trd_val;	// �����ŷ����, ����:�� �ؽð��ܴ��ϰ�, BUY-IN�� ������ ��� �ŷ���� �ջ�
	char trend_flg;	// �Ǽ�/�⼼ ����, 0:�ʱⰪ 1:�Ǽ� 2:�⼼ 3:�ŷ��� 4:�ð����ذ������� �⼼
	char brd_evt_id[4];	// �����̺�ƮID, B1/B2 ������ �����̺�ƮID ������(���� ���°��� ���۵� �� ����). ����, �ش� �׸� '000' ���� ����. 2014.03.24)
	char brd_id[3];	// ����ID, �� �ڵ尪���� ����
	char trsp_flg;	// �ŷ���������, Y, N
	double bopen_ofhr_ccls_qty;	// �尳�����ð������� ü�����, �뷮, �ٽ����� ����, ����:��
	double bopen_ofhr_trd_val;	// �尳�����ð������� �ŷ����, �뷮, �ٽ����� ����, ����:��
	double opr_time_ccls_qty;	// ������ü�����, �뷮, �ٽ����� ����, ����:��
	double opr_time_trd_val;	// ������ŷ����, �뷮, �ٽ����� ����, ����:��
	double ofhr_cls_ccls_qty;	// �������Ľð������� ü�����, �뷮, �ٽ����� ����, ����:��
	double ofhr_cls_trd_val;	// �������Ľð������� �ŷ����, �뷮, �ٽ����� ����, ����:��
	char elw_ely_cls_flg;	// ELW�������Ῡ��, Y,N ��������ELW �� ������ Default 'N' SET
	int elw_ely_cls_time;	// ELW��������ð�, HHMMSS, ELW�������Ῡ�ΰ� 'Y'�� ��츸 ����
	int cmpt_msv_dir_clsf;	// ����뷮 ���ⱸ��, 0:�ش����, 1:�ŵ�, 2:�ż�
	double gen_bin_ccls_qty;	// �Ϲ� Buy-in ü�����, ����:��
	double gen_bin_ccls_trd_val;	// �Ϲ� Buy-in �ŷ����, ����:��
	double day_bin_ccls_qty;	// ���� Buy-in ü�����, ����:��
	double day_bin_ccls_trd_val;	// ���� Buy-in �ŷ����, ����:��
} DF_ELW_MKT_PRC_RCVR;


// ELW ������ǥ
typedef struct _DF_ELW_INV_IDX {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����, C6
	char info_clsf[3];	// ��������, 02:ELW
	char mkt_clsf;	// ���屸��, 1:��������
	char isin_code[13];	// �����ڵ�, ǥ���ڵ�
	int snr;	// �Ϸù�ȣ, 1~99999999 �����Ϸù�ȣ 2014.03.03
	char buy_time[7];	// �� �ð�, ����:HHMMSS(�ð�:��:��) 090000 ~ ������:JUNJJJ
	double parity;	// �и�Ƽ, 9(6)V9(2)
	double gear_rate;	// ������, 9(6)V9(2)
	double brk_evn_rate;	// ���ͺб���, 9(5)V9(2)
	double cpt_sprt;	// �ں�������, 9(5)V9(2) ������ ����� �ѹ��� �����. �� �ܴ� "0"\n����Ŀ��� �� < 0 �̸� "0"���� SET
	double bsk_prc;	// �ٽ����ְ�, 9(9)V9(2)
} DF_ELW_INV_IDX;


// ELW ���纯���� ����
typedef struct _DF_ELW_IV_INFO {
	char isin_code[13];	// �����ڵ�, ǥ���ڵ� 12 ����Ʈ
	double itnl_vol;	// ���纯����, 9(3)V9(2). 5����Ʈ
} DF_ELW_IV_INFO;


// ELW LPȣ�� ���纯����
typedef struct _DF_ELW_LP_ASK_VOL {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����, N3
	char info_clsf[3];	// ��������, 02:ELW
	char mkt_clsf;	// ���屸��, 1:��������
	int calc_time;	// ����ð�, ����:HHMMSS(�ð�:��:��) 090000 ~ ������:JUNJJJ
	DF_ELW_IV_INFO elw_iv_infos[50];	// ���纯���� OCCURS 50, (12+5)*50 OCCURS 50
} DF_ELW_LP_ASK_VOL;


// ELW_�ü�����
typedef struct _DF_ELW_MKT_PRC_CLS {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����, B1:���� B2:�ü�REC
	char info_clsf[3];	// ��������, 01:�ֽ� 02:ELW
	char mkt_clsf;	// ���屸��, 1:�������� 2:�ڽ���
	char isin_code[13];	// �����ڵ�, ǥ���ڵ�
	int stk_snr;	// �����Ϸù�ȣ, �����ġ(A0)�� �����Ϸù�ȣ
	char flct_clsf;	// �������, 0:�ǴܺҰ� 1:���� 2:��� 3:���� 4:���� 5:�϶�
	int prev_ctrs;	// ���ϴ��, ����:��
	int cur_prc;	// ���簡
	int open;	// �ð�, ������ �ð�
	int high;	// ��, ������ ��
	int low;	// ����, ������ ����
	int ask_prc;	// �ŵ�ȣ��, B1�� 0�� SET
	int bid_prc;	// �ż�ȣ��, B1�� 0�� SET
	double cum_ccls_qty;	// ����ü�����, ����:�� �ؽð��ܴ��ϰ�, BUY-IN�� ������ ��� ü����� �ջ�
	double cum_trd_val;	// �����ŷ����, ����:�� �ؽð��ܴ��ϰ�, BUY-IN�� ������ ��� �ŷ���� �ջ�
	char trend_flg;	// �Ǽ�/�⼼ ����, 0:�ʱⰪ 1:�Ǽ� 2:�⼼ 3:�ŷ��� 4:�ð����ذ������� �⼼
	char brd_evt_id[4];	// �����̺�ƮID, B1/B2 ������ �����̺�ƮID ������(���� ���°��� ���۵� �� ����). ����, �ش� �׸� '000' ���� ����. 2014.03.24)
	char brd_id[3];	// ����ID, �� �ڵ尪���� ����
	char trsp_flg;	// �ŷ���������, Y, N
	double bopen_ofhr_ccls_qty;	// �尳�����ð������� ü�����, �뷮, �ٽ����� ����, ����:��
	double bopen_ofhr_trd_val;	// �尳�����ð������� �ŷ����, �뷮, �ٽ����� ����, ����:��
	double opr_time_ccls_qty;	// ������ü�����, �뷮, �ٽ����� ����, ����:��
	double opr_time_trd_val;	// ������ŷ����, �뷮, �ٽ����� ����, ����:��
	double ofhr_cls_ccls_qty;	// �������Ľð������� ü�����, �뷮, �ٽ����� ����, ����:��
	double ofhr_cls_trd_val;	// �������Ľð������� �ŷ����, �뷮, �ٽ����� ����, ����:��
	char elw_ely_cls_flg;	// ELW�������Ῡ��, Y,N ��������ELW �� ������ Default 'N' SET
	int elw_ely_cls_time;	// ELW��������ð�, HHMMSS, ELW�������Ῡ�ΰ� 'Y'�� ��츸 ����
	int cmpt_msv_dir_clsf;	// ����뷮 ���ⱸ��, 0:�ش����, 1:�ŵ�, 2:�ż�
	double gen_bin_ccls_qty;	// �Ϲ� Buy-in ü�����, ����:��
	double gen_bin_ccls_trd_val;	// �Ϲ� Buy-in �ŷ����, ����:��
	double day_bin_ccls_qty;	// ���� Buy-in ü�����, ����:��
	double day_bin_ccls_trd_val;	// ���� Buy-in �ŷ����, ����:��
} DF_ELW_MKT_PRC_CLS;


// ELW_�����ں�
typedef struct _DF_ELW_BYINV {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����, C0
	char info_clsf[3];	// ��������, 01:�ֽ�, 02:ELW, 03:ETF
	char mkt_clsf;	// ���屸��, 1:�������� 2:�ڽ���
	char cmpt_time[7];	// ����ð�, 90�� �ֱ�
	char inv_code[5];	// �������ڵ�, ���ڵ尪���� ����\n*�ڵ�'7000'�� ����, ������� �׸� 0���� ���� (20181210)
	char ind_code[4];	// �����ڵ�, 0
	double ask_ccls_qty;	// �ŵ�ü�����, ����:��
	double ask_trd_val;	// �ŵ��ŷ����, ����:��
	double bid_ccls_qty;	// �ż�ü�����, ����:��
	double bid_trd_val;	// �ż��ŷ����, ����:��
} DF_ELW_BYINV;


// ELW_ȣ���ܷ�_LPȣ��_����
typedef struct _DF_ELW_ASK_RSD_WLP {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����, B7
	char info_clsf[3];	// ��������, 01:������������ 02:ELW
	char mkt_clsf;	// ���屸��, 1:��������
	char isin_code[13];	// �����ڵ�, ǥ���ڵ�
	int stk_snr;	// �����Ϸù�ȣ, �����ġ(A0)�� �����Ϸù�ȣ
	double cum_ccls_qty;	// ����ü�����
	DF_STOCK_LOB_INFO_WITH_LP lob_infos[10];	// ȣ�� OCCURS 1010�� 66 = 660
	double ask_10_tot_rsd;	// 10�ܰ�ȣ���ŵ����ܷ�
	double bid_10_tot_rsd;	// 10�ܰ�ȣ���ż����ܷ�
	double ofhr_ask_tot_rsd;	// �������Ľð��� �ŵ���ȣ���ܷ�, ����ID�� "G3"�� ��� ������ \n ��ELW�� �ð��ܰŷ� ����
	double ofhr_bid_tot_rsd;	// �������Ľð��� �ż���ȣ���ܷ�, ����ID�� "G3"�� ��� ������ \n ��ELW�� �ð��ܰŷ� ����
	char sess_id[3];	// ����ID, �� �ڵ尪���� ����
	char brd_id[3];	// ����ID, �� �ڵ尪���� ����
	int exp_ccls_prc;	// ����ü�ᰡ��
	double exp_ccls_qty;	// ����ü�����
	int cmpt_msv_dir_clsf;	// ����뷮 ���ⱸ��, 0:�ش����, 1:�ŵ�, 2:�ż�
} DF_ELW_ASK_RSD_WLP;


// ETF�繫��Ź��ġ
typedef struct _DF_ETF_TRA_INFO {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����, N8
	char info_clsf[3];	// ��������, 01:�ֽ�
	char mkt_clsf;	// ���屸��, 1:��������
	char isin_code[13];	// �����ڵ�, ǥ���ڵ�
	int snr;	// �Ϸù�ȣ, 1~99999999 �Ǽ�üũ��
	double etf_nr_shr_rtt;	// ETF�����ֽļ�
	double etf_nav_rtt;	// ETF������ڻ��Ѿ�
	double etf_nav_tot_val;	// ETF���ڻ��Ѿ�, ����:��
	double etf_fin_nav_val;	// ETF�������ڻ갡ġ, 9(7)V9(2) �������������� ����NAV
	double etf_fx_nav_rtt;	// ETF��ȭ������ڻ��Ѿ�
	double etf_fx_nav_tot_val;	// ETF��ȭ���ڻ��Ѿ�
	double etf_fx_fin_nav_val;	// ETF��ȭ�������ڻ갡ġ, 9(7)V9(2)
	int etf_cu_qty;	// ETF CU����, ����:����
	double prev_base_prc;	// ���ϰ�ǥ���ذ���, 9999999V99
	double prev_bdiv_base_prc;	// ���Ϲ������ǥ���ذ���, 9999999V99
	double prev_cash_div_val;	// �������ݹ��ݾ�, 9999999999V99
	double pprev_base_prc;	// �����ϰ�ǥ���ذ���, 9999999V99
	double frgn_stk_prev_base_prc;	// �ؿ��ֽ����Ϻ������ǥ���ذ�, 9999999V99 2016.02.29 �ű�
	double frgn_stk_prev_bdiv_base_prc;	// �ؿ��ֽ����Ϻ�����������ǥ���ذ�, 9999999V99 2016.02.29 �ű�
	double frgn_stk_pprev_bdiv_base_prc;	// �ؿ��ֽĺ���������ϰ�ǥ���ذ�, 9999999V99 2016.02.29 �ű�
} DF_ETF_TRA_INFO;


// ETF PDF
typedef struct _DF_ETF_PDF {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����, F8
	char info_clsf[3];	// ��������, 01:�ֽ�
	char mkt_clsf;	// ���屸��, 1:��������
	char isin_code[13];	// ETF�ڵ�
	int data_snr;	// ������ �Ϸù�ȣ, �����Ϸù�ȣ
	char date[9];	// ����, YYYYMMDD(��������)
	int trb_nr;	// �繫��Źȸ���ȣ, '903'�ѱ���Ź������,'049'�̷������ݵ弭��
	int comp_stk_nr;	// ���������, ����:����(������ ����)
	char comp_stk_code[13];	// ���������ڵ�, �ذ��߰��̵� ����(CP �߰�) 2015.03.03
	double one_cu_unit_scrt_nr;	// 1CU�������Ǽ�/����/��ȭ����, �ذ��߰��̵� ����(�ܱ�ȯ������ �߰�) 2014.06.16 \nǥ������:9999999999999999V99
	int comp_stk_mkt_clsf;	// ����������屸��, 0:��������(����,KSP200T00001,FKSP200T0001����)\n1:�ڽ��� 2:��Ÿ 3:ä�� 4:���� �� �ɼ� 2018.02.05
	char comp_stk_nm[41];	// ���������, �ؿ������� ��� �����, �� �ܴ� '0' �Ǵ� SPACE
	double par_val;	// �׸�ݾ�/�������ݾ�, �ذ��߰��̵� ����(�ܱ�ȯ������ �߰�) 2014.06.16
	char profit_allc_base_date[9];	// ���ͺй������, �ذ��߰��̵� ���� 2009.07.27
	double assm_val;	// �򰡱ݾ�, PDF�� ���� ���� ���� ����data �ű� 2011.08.29
} DF_ETF_PDF;


// ETF�������
typedef struct _DF_ETF_OPR_INFO {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����, M8
	char info_clsf[3];	// ��������, 01:�ֽ�
	char mkt_clsf;	// ���屸��, 1:��������
	char isin_code[13];	// ETF �ڵ�, ǥ���ڵ�
	int snr;	// �Ϸù�ȣ, 00000001~99999999 �Ǽ�üũ��
	int trb_nr;	// �繫��Ź ȸ���ȣ, '903'�ѱ���Ź������,'049'�̷������ݵ弭��
	int mngt_code;	// �����ڵ�
	char mngt_kor_abrv[51];	// ���� �ѱ۾��
	char mngt_eng_abrv[41];	// ���� �������
} DF_ETF_OPR_INFO;


// ETF NAV
typedef struct _DF_ETF_NAV {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����, F7
	char info_clsf[3];	// ��������, 01:�ֽ�
	char mkt_clsf;	// ���屸��, 1:�������� 2:�ڽ���
	char isin_code[13];	// ETF �����ڵ�, ETF �����ڵ�
	char time[7];	// �ð�, HHMMSS:���� JSAM00:������
	double prev_nav;	// ���� NAV, 9(7)V9(2)
	double opr_time_fin_nav;	// ����/���� NAV, 9(7)V9(2)
} DF_ETF_NAV;


// ETF ����NAV
typedef struct _DF_ETF_EXP_NAV {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����, I3
	char info_clsf[3];	// ��������, 01:�ֽ�
	char mkt_clsf;	// ���屸��, 1:�������� 2:�ڽ���
	char isin_code[13];	// ETF �����ڵ�, ETF �����ڵ�
	char time[7];	// �ð�, HHMMSS:08:30~09:00(PREJJJ) 14:50~15:00(JUNJJJ)
	double prev_nav;	// ���� NAV, 9999999V99
	double opr_time_fin_nav;	// ����/���� NAV, 9999999V99
} DF_ETF_EXP_NAV;


// ETF ����������
typedef struct _DF_ETF_TER {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����, P6
	char info_clsf[3];	// ��������, 01:�ֽ�
	char mkt_clsf;	// ���屸��, 1:�������� 2:�ڽ���
	char isin_code[13];	// ETF �����ڵ�, ETF �����ڵ�
	int snr;	// �Ϸù�ȣ, 1~99999999 �����Ϸù�ȣ,�Ǽ�üũ��
	char date[9];	// ����, YYYYMMDD:����������
	double trkg_err_rate;	// ����������, 9(7)V9(2), ����:% �� ���߰��̵� ����
	double dspr;	// ������, 9(7)V9(2), ����:%
} DF_ETF_TER;


// ETF_�����ں�
typedef struct _DF_ETF_BYINV {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����, C0
	char info_clsf[3];	// ��������, 01:�ֽ�, 02:ELW, 03:ETF
	char mkt_clsf;	// ���屸��, 1:�������� 2:�ڽ���
	char cmpt_time[7];	// ����ð�, 90�� �ֱ�
	char inv_code[5];	// �������ڵ�, ���ڵ尪���� ����\n*�ڵ�'7000'�� ����, ������� �׸� 0���� ���� (20181210)
	char ind_code[4];	// �����ڵ�, 0
	double ask_ccls_qty;	// �ŵ�ü�����, ����:��
	double ask_trd_val;	// �ŵ��ŷ����, ����:��
	double bid_ccls_qty;	// �ż�ü�����, ����:��
	double bid_trd_val;	// �ż��ŷ����, ����:��
} DF_ETF_BYINV;


// ȸ��������
typedef struct _DF_MBR_INFO {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����, M9
	char info_clsf[3];	// ��������, 01:�ֽ�
	char mkt_clsf;	// ���屸��, 1:��������
	int snr;	// �Ϸù�ȣ, 00000001~99999999 �Ǽ�üũ��
	char opr_date[9];	// ��������
	char mkt_ptcp_nr[6];	// ���������ڹ�ȣ
	char mkt_ptcp_kor_nm[81];	// �����������ѱ۸�
	char mkt_ptcp_eng_nm[81];	// ���������ڿ�����
	char mkt_ptcp_kor_abrv[21];	// �����������ѱ۾��
} DF_MBR_INFO;


// KOSPI����
typedef struct _DF_KOSPI_IDX {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����, �ذ��߰��̵� ����
	char info_clsf[3];	// ��������, 01:�ֽ�
	char mkt_clsf;	// ���屸��, 1:�������� 2:�ڽ���
	char ind_code[4];	// �����ڵ�, �ذ��߰��̵� ����
	char time[7];	// �ð�, �ذ��߰��̵� ����
	double idx;	// ����, 9(6)V9(2)
	double ctrs;	// ���, 999999V99
	int ccls_qty;	// ü�����, ����:õ��
	int trd_val;	// �ŷ����, ����:�鸸��
} DF_KOSPI_IDX;


// KOSPI��������
typedef struct _DF_KOSPI_EXP_IDX {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����, �ذ��߰��̵� ����
	char info_clsf[3];	// ��������, 01:�ֽ�
	char mkt_clsf;	// ���屸��, 1:�������� 2:�ڽ���
	char ind_code[4];	// �����ڵ�, �ذ��߰��̵� ����
	char time[7];	// �ð�, �ذ��߰��̵� ����
	double idx;	// ����, 9(6)V9(2)
	double ctrs;	// ���, 999999V99
	int ccls_qty;	// ü�����, ����:õ��
	int trd_val;	// �ŷ����, ����:�鸸��
} DF_KOSPI_EXP_IDX;


// KOSPI200����
typedef struct _DF_KOSPI_200_IDX {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����, �ذ��߰��̵� ����
	char info_clsf[3];	// ��������, 01:�ֽ�
	char mkt_clsf;	// ���屸��, 1:�������� 2:�ڽ���
	char ind_code[4];	// �����ڵ�, �ذ��߰��̵� ����
	char time[7];	// �ð�, �ذ��߰��̵� ����
	double idx;	// ����, 9(6)V9(2)
	double ctrs;	// ���, 999999V99
	int ccls_qty;	// ü�����, ����:õ��
	int trd_val;	// �ŷ����, ����:�鸸��
} DF_KOSPI_200_IDX;


// KOSPI200��������
typedef struct _DF_KOSPI_200_EXP_IDX {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����, �ذ��߰��̵� ����
	char info_clsf[3];	// ��������, 01:�ֽ�
	char mkt_clsf;	// ���屸��, 1:�������� 2:�ڽ���
	char ind_code[4];	// �����ڵ�, �ذ��߰��̵� ����
	char time[7];	// �ð�, �ذ��߰��̵� ����
	double idx;	// ����, 9(6)V9(2)
	double ctrs;	// ���, 999999V99
	int ccls_qty;	// ü�����, ����:õ��
	int trd_val;	// �ŷ����, ����:�鸸��
} DF_KOSPI_200_EXP_IDX;


// KOSPI100/50����
typedef struct _DF_KOSPI_100_50_IDX {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����, �ذ��߰��̵� ����
	char info_clsf[3];	// ��������, 01:�ֽ�
	char mkt_clsf;	// ���屸��, 1:�������� 2:�ڽ���
	char ind_code[4];	// �����ڵ�, �ذ��߰��̵� ����
	char time[7];	// �ð�, �ذ��߰��̵� ����
	double idx;	// ����, 9(6)V9(2)
	double ctrs;	// ���, 999999V99
	int ccls_qty;	// ü�����, ����:õ��
	int trd_val;	// �ŷ����, ����:�鸸��
} DF_KOSPI_100_50_IDX;


// KOSPI200 ���Ϳ�������
typedef struct _DF_KOSPI_200_STR_EXP_IDX {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����, �ذ��߰��̵� ����
	char info_clsf[3];	// ��������, 01:�ֽ�
	char mkt_clsf;	// ���屸��, 1:�������� 2:�ڽ���
	char ind_code[4];	// �����ڵ�, �ذ��߰��̵� ����
	char time[7];	// �ð�, �ذ��߰��̵� ����
	double idx;	// ����, 9(6)V9(2)
	double ctrs;	// ���, 999999V99
	int ccls_qty;	// ü�����, ����:õ��
	int trd_val;	// �ŷ����, ����:�鸸��
} DF_KOSPI_200_STR_EXP_IDX;


// KOSPI200 ��������
typedef struct _DF_KOSPI_200_STR_IDX {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����, �ذ��߰��̵� ����
	char info_clsf[3];	// ��������, 01:�ֽ�
	char mkt_clsf;	// ���屸��, 1:�������� 2:�ڽ���
	char ind_code[4];	// �����ڵ�, �ذ��߰��̵� ����
	char time[7];	// �ð�, �ذ��߰��̵� ����
	double idx;	// ����, 9(6)V9(2)
	double ctrs;	// ���, 999999V99
	int ccls_qty;	// ü�����, ����:õ��
	int trd_val;	// �ŷ����, ����:�鸸��
} DF_KOSPI_200_STR_IDX;


// KRX100����
typedef struct _DF_KOSPI_100_IDX {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����, �ذ��߰��̵� ����
	char info_clsf[3];	// ��������, 01:�ֽ�
	char mkt_clsf;	// ���屸��, 1:�������� 2:�ڽ��� 9:�ؿ��ְ����� 2012.04.30 �߰�
	char ind_code[4];	// �����ڵ�, �ذ��߰��̵� ����
	char time[7];	// �ð�, �ذ��߰��̵� ���� ���ؿ��ְ������� ��� GMT�ð�
	double idx;	// ����, 9(6)V9(2)
	double ctrs;	// ���, 999999V99
	int ccls_qty;	// ü�����, ����:õ�� ���ؿ��ְ������� ��� FILLERó��
	int trd_val;	// �ŷ����, ����:�鸸�� ���ؿ��ְ������� ��� FILLERó��
} DF_KOSPI_100_IDX;


// KRX100��������
typedef struct _DF_KOSPI_100_EXP_IDX {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����, �ذ��߰��̵� ����
	char info_clsf[3];	// ��������, 01:�ֽ�
	char mkt_clsf;	// ���屸��, 1:�������� 2:�ڽ��� 9:�ؿ��ְ����� 2012.04.30 �߰�
	char ind_code[4];	// �����ڵ�, �ذ��߰��̵� ����
	char time[7];	// �ð�, �ذ��߰��̵� ���� ���ؿ��ְ������� ��� GMT�ð�
	double idx;	// ����, 9(6)V9(2)
	double ctrs;	// ���, 999999V99
	int ccls_qty;	// ü�����, ����:õ�� ���ؿ��ְ������� ��� FILLERó��
	int trd_val;	// �ŷ����, ����:�鸸�� ���ؿ��ְ������� ��� FILLERó��
} DF_KOSPI_100_EXP_IDX;


// ���ϰ�������
typedef struct _DF_EWIDX {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����, �ذ��߰��̵� ����
	char info_clsf[3];	// ��������, 01:�ֽ�
	char mkt_clsf;	// ���屸��, 1:�������� 2:�ڽ���
	char ind_code[4];	// �����ڵ�, �ذ��߰��̵� ����
	char time[7];	// �ð�, �ذ��߰��̵� ����
	double idx;	// ����, 9(6)V9(2)
	double ctrs;	// ���, 999999V99
	int ccls_qty;	// ü�����, ����:õ��
	int trd_val;	// �ŷ����, ����:�鸸��
} DF_EWIDX;


// ���ϰ��߿�������
typedef struct _DF_EWEIDX {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����, �ذ��߰��̵� ����
	char info_clsf[3];	// ��������, 01:�ֽ�
	char mkt_clsf;	// ���屸��, 1:�������� 2:�ڽ���
	char ind_code[4];	// �����ڵ�, �ذ��߰��̵� ����
	char time[7];	// �ð�, �ذ��߰��̵� ����
	double idx;	// ����, 9(6)V9(2)
	double ctrs;	// ���, 999999V99
	int ccls_qty;	// ü�����, ����:õ��
	int trd_val;	// �ŷ����, ����:�鸸��
} DF_EWEIDX;


// �������� �׷�_�����ڵ�
typedef struct _DF_MARKET_IDX_GROUP_EXP_CODE {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����, G1
	char info_clsf[3];	// ��������, 06:�峻�Ϲ�ä��
	char mkt_clsf;	// ���屸��, 7:ä��
	int snr;	// �Ϸù�ȣ, 1~99999999 �Ǽ�üũ��
	char code_clsf;	// �ڵ� ����, 1:�׷��ڵ� 2:�����ڵ�
	char apl_date[9];	// ������, YYYYMMDD
	char grp_mtr_code[6];	// �׷�/�����ڵ�, �׷��ڵ�:"XXXXX", �����ڵ�:"XXX "
	char grp_mtr_code_nm[31];	// �׷�/�����ڵ��
	char grp_mtr_code_stg;	// �׷�/�����ڵ�ܰ�, �׷��ڵ�:0,1,2,3,4 �����ڵ�:0,1,2,3
} DF_MARKET_IDX_GROUP_EXP_CODE;


// �������������
typedef struct _DF_WISEFN_IDX {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����, P3
	char info_clsf[3];	// ��������, 01:�ֽ�
	char mkt_clsf;	// ���屸��, 1:��������
	char ind_code[4];	// �����ڵ�, �ڵ尪���� ����\nWISEFn�ű�����4���߰�(2015.03.23)
	char time[7];	// �ð�, �ذ��߰��̵� ����
	double idx;	// ����, 9(6)V9(2)
	double ctrs;	// ���, 999999V99
	int ccls_qty;	// ü�����, ����:õ��
	int trd_val;	// �ŷ����, ����:�鸸��
} DF_WISEFN_IDX;


// �ڽ���_�ŷ���
typedef struct _DF_KOSPI_TRS {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����, B9
	char info_clsf[3];	// ��������, 01:�ֽ� 02:ELW
	char mkt_clsf;	// ���屸��, 1:�������� 2:�ڽ���
	char isin_code[13];	// �����ڵ�, ǥ���ڵ�
	int snr;	// �Ϸù�ȣ, 1~99999999 �����Ϸù�ȣ 2014.03.03
	DF_STOCK_SRC_INFO src_infos[5];	// �ŷ������� OCCURS
} DF_KOSPI_TRS;


// ELW_�ŷ���
typedef struct _DF_ELW_TRS {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����, B9
	char info_clsf[3];	// ��������, 01:�ֽ� 02:ELW
	char mkt_clsf;	// ���屸��, 1:�������� 2:�ڽ���
	char isin_code[13];	// �����ڵ�, ǥ���ڵ�
	int snr;	// �Ϸù�ȣ, 1~99999999 �����Ϸù�ȣ 2014.03.03
	DF_STOCK_SRC_INFO src_infos[5];	// �ŷ������� OCCURS
} DF_ELW_TRS;


// �ڽ���_���������ں� ����
typedef struct _DF_KOSPI_BYSTK_BYINV_CLS {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����, C1
	char info_clsf[3];	// ��������, 01:�ֽ� 02:ELW
	char mkt_clsf;	// ���屸��, 1:�������� 2:�ڽ���
	char isin_code[13];	// �����ڵ�, ǥ���ڵ�
	int snr;	// �Ϸù�ȣ, 1~99999999 �����Ϸù�ȣ 2014.03.03
	DF_STOCK_INV_INFO inv_infos[12];	// ������ OCCURS 12
} DF_KOSPI_BYSTK_BYINV_CLS;


// ELW_���������ں� ����
typedef struct _DF_ELW_BYSTK_BYINV_CLS {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����, C1
	char info_clsf[3];	// ��������, 01:�ֽ� 02:ELW
	char mkt_clsf;	// ���屸��, 1:�������� 2:�ڽ���
	char isin_code[13];	// �����ڵ�, ǥ���ڵ�
	int snr;	// �Ϸù�ȣ, 1~99999999 �����Ϸù�ȣ 2014.03.03
	DF_STOCK_INV_INFO inv_infos[12];	// ������ OCCURS 12
} DF_ELW_BYSTK_BYINV_CLS;


// �ؿ����� ETF NAV
typedef struct _DF_FRIDX_ETF_NAV {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����, F7(��������), L5(�ؿ�����) ��Ƽĳ��Ʈ ���� �� ����
	char info_clsf[3];	// ��������, 01:�ֽ�
	char mkt_clsf;	// ���屸��, 1:��������
	char isin_code[13];	// ETF �����ڵ�, ETF �����ڵ�
	char time[7];	// �ð�, �ذ��߰��̵� ����
	double prev_nav;	// ���� NAV, 9(7)V9(2)
	double opr_time_fin_nav;	// ����/���� NAV, 9(7)V9(2)
} DF_FRIDX_ETF_NAV;


// �ؿ�ETF ����������
typedef struct _DF_FRIDX_TER {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����, P7
	char info_clsf[3];	// ��������, 01:�ֽ�
	char mkt_clsf;	// ���屸��, 1:�������� 2:�ڽ���
	char isin_code[13];	// ETF �����ڵ�, ETF �����ڵ�
	int snr;	// �Ϸù�ȣ, 1~99999999 �����Ϸù�ȣ,�Ǽ�üũ��
	char date[9];	// ����, YYYYMMDD:����������
	double trkg_err_rate;	// ����������, 9(7)V9(2), ����:%
	double dspr;	// ������, 9(7)V9(2), ����:%
} DF_FRIDX_TER;


// �ռ�ETF ���� �ŷ����� �����򰡾� ����
typedef struct _DF_SETF_DAY_CPTY_RISK_INFO {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����, Q4
	char info_clsf[3];	// ��������, 01:�ֽ�
	char mkt_clsf;	// ���屸��, 1:�������� 2:�ڽ���
	char isin_code[13];	// ETF�ڵ�, ǥ���ڵ�
	int data_snr;	// ������ �Ϸù�ȣ, 1~99999999 �����Ϸù�ȣ, �Ǽ�üũ��
	int date;	// ����, YYYYMMDD
	int trb_nr;	// �繫��Źȸ���ȣ, '903'�ѱ���Ź������,'049'�̷������ݵ弭��
	char cntr_pty_nm[51];	// �ŷ������, �ŷ������
	int ofmkt_drvt_type;	// ����Ļ���ǰ����, 0:�ڱݰ����� 1:�ڱݺ������ �ذ��߰��̵� ����
	double nav_tot_val;	// ���ڻ��Ѿ�, ����:��
	double tot_risk_xps_val;	// ����������, ����:�� �ذ��߰��̵� ����
	double cltr_assm_val;	// �㺸�򰡾�, ����:�� �ذ��߰��̵� ����
	double cltr_rate;	// �㺸����, 99999V99 ����:% �ذ��߰��̵� ����
	double risk_assm_val;	// �����򰡾�, ����:�� �ذ��߰��̵� ����
	double risk_assm_rate;	// �����򰡾׺���, 99999V99 ����:% �ذ��߰��̵� ����
} DF_SETF_DAY_CPTY_RISK_INFO;


// MKF����
typedef struct _DF_MKF_IDX {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����, E2
	char info_clsf[3];	// ��������, 01:�ֽ�
	char mkt_clsf;	// ���屸��, 1:�������� 2:�ڽ��� 2012.05.21 �߰�
	char ind_code[4];	// �����ڵ�, �ذ��߰��̵� ����
	char time[7];	// �ð�, �ذ��߰��̵� ����
	double idx;	// ����, 9(6)V9(2)
	double ctrs;	// ���, 999999V99
	int ccls_qty;	// ü�����, ����:õ��
	int trd_val;	// �ŷ����, ����:�鸸��
} DF_MKF_IDX;


// MKF����(��ȯ���ݿ�)
typedef struct _DF_MKF_IDX_WYFX {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����, O9
	char info_clsf[3];	// ��������, 01:�ֽ�
	char mkt_clsf;	// ���屸��, 1:�������� 2:�ڽ��� 2012.05.21 �߰�
	char ind_code[4];	// �����ڵ�, �ذ��߰��̵� ����
	char time[7];	// �ð�, �ذ��߰��̵� ����
	double idx;	// ����, 9(6)V9(2)
	double ctrs;	// ���, 999999V99
	int ccls_qty;	// ü�����, ����:õ��
	int trd_val;	// �ŷ����, ����:�鸸��
} DF_MKF_IDX_WYFX;


// �ؿ�����ETF�������
typedef struct _DF_FRIDX_ETF_IDX {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����, M3
	char info_clsf[3];	// ��������, 01:�ֽ�
	char mkt_clsf;	// ���屸��, 1:��������
	char date[9];	// ����, ���������� ������ ���ŵ����� ����, ���� �����Ϳ� �ߺ�����
	char smbl_code[17];	// �ɺ��ڵ�, �ذ��߰��̵� ����
	char idx[11];	// ����, 9999999V999, Excess Return(ER)
	char tot_profit_idx[11];	// �Ѽ�������, 9999999V999, Total Retrun(TR) 2011.04.01 �ű�
	char cls_prc[11];	// ����, 9999999V999, Close Price(Spot) 2011.04.01 �ű�
} DF_FRIDX_ETF_IDX;


// �ؿ�����
typedef struct _DF_FRIDX {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����, �ش��� PAGE �������� ���� ����
	char info_clsf[3];	// ��������, 01:�ֽ�
	char mkt_clsf;	// ���屸��, 1:�������� 2:�ڽ��� 9: �ؿ��ְ����� 2012.4.30 �߰�
	char ind_code[4];	// �����ڵ�, �ذ��߰��̵� ����
	char time[7];	// �ð�, �ذ��߰��̵� ���� ��MSCI����:EST(����ð�) 2013.02.18 ����
	double idx;	// ����, 9(6)V9(2)
	double ctrs;	// ���, 999999V99
	int ccls_qty;	// ü�����, ����:õ�� ���ؿ��ְ������� ��� FILLERó��
	int trd_val;	// �ŷ����, ����:�鸸�� ���ؿ��ְ������� ��� FILLERó��
} DF_FRIDX;


// �ռ�ETF �������� ��������
typedef struct _DF_SETF_BASE_IDX_COMP_STK {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����, Q5
	char info_clsf[3];	// ��������, 01:�ֽ�
	char mkt_clsf;	// ���屸��, 1:�������� 2:�ڽ���
	char isin_code[13];	// ETF�ڵ�, ǥ���ڵ�
	int data_snr;	// ������ �Ϸù�ȣ, 1~99999999 �����Ϸù�ȣ, �Ǽ�üũ��
	int date;	// ����, YYYYMMDD
	int trb_nr;	// �繫��Źȸ���ȣ, '903'�ѱ���Ź������,'049'�̷������ݵ弭��
	int comp_stk_nr;	// ���������, ����:����(��������)
	char comp_stk_code[13];	// ���������ڵ�, ǥ���ڵ�\n�ؿ������� ��� '0' �Ǵ� SPACE�� Setting�� �� ����
	char comp_stk_nm[81];	// ���������, �����
	double comp_rate;	// ������, ������ ������\n99999V99 ����:%
} DF_SETF_BASE_IDX_COMP_STK;


// �������� �ܱ��� ������������_Ȯ��ġ
typedef struct _DF_FBRD_FRGN_INV_INFO {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����, F1
	char info_clsf[3];	// ��������, 01:�ֽ� 90:��Ÿ
	char mkt_clsf;	// ���屸��, 1:�������� 2:�ڽ��� 3:�������� 7:ä��
	char isin_code[13];	// �����ڵ�, ǥ���ڵ�
	int snr;	// �Ϸù�ȣ, 1~99999999 �Ǽ�üũ��
	char trd_date[9];	// �Ÿ�����, YYYYMMDD
	double stk_lim_ratio;	// �����ѵ�����, 9V9999 (��:15%�϶� �� 01500���� ����)
	double psn_lim_ratio;	// �����ѵ�����, 9V9999 (��:15%�϶� �� 01500���� ����)
	double stk_lstd;	// �����ֽļ�, ����:��
	double ordbl_qty;	// �ֹ����ɼ���, ����:��
	char lim_xhs_clsf;	// �ѵ���������, 0:���� 1:�ѵ����� 2:�ѵ�����ű����� 3:�ѵ���������
} DF_FBRD_FRGN_INV_INFO;


// �������� �ܱ��� �ֹ����ɼ���
typedef struct _DF_FBRD_FRGN_ORDL_QTY {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����, F2
	char info_clsf[3];	// ��������, 01:�ֽ� 90:��Ÿ
	char mkt_clsf;	// ���屸��, 1:�������� 2:�ڽ��� 3:�������� 7:ä��
	char isin_code[13];	// �����ڵ�, ǥ���ڵ�
	double ordbl_qty;	// �ֹ����ɼ���, ����:��(����� ����)
	char data_type[3];	// ����������, 01:�ֹ����ɼ���(�ǽð�) 07:����ġ�ֹ����ɼ���(����)
} DF_FBRD_FRGN_ORDL_QTY;


// �������� �ܱ��� �����ֹ�����_����
typedef struct _DF_FBRD_FRGN_RSVD_ORD_CNCL {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����, F3
	char info_clsf[3];	// ��������, 01:�ֽ�
	char mkt_clsf;	// ���屸��, 1:�������� 2:�ڽ��� 3:��������
	char isin_code[13];	// �����ڵ�, ǥ���ڵ�
	char data_type[3];	// ����������, 01:�����ֹ����� 02:�����ֹ�����
	char proc_clsf;	// ó������, 1:���� 2:���
	char rsvd_ord_date[9];	// �����ֹ�����, YYYYMMDD
	char rsvd_ord_st_time[5];	// �����ֹ����۽ð�, HHMM
	char rsvd_ord_ed_time[5];	// �����ֹ�����ð�, HHMM
} DF_FBRD_FRGN_RSVD_ORD_CNCL;


// �������� �ܱ��� Ȯ��ġ������������
typedef struct _DF_FBRD_FRGN_CFRM_DATA {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����, F4
	char info_clsf[3];	// ��������, 01:�ֽ� 90:��Ÿ
	char mkt_clsf;	// ���屸��, 1:�������� 2:�ڽ��� 3:�������� 7:ä��
	char isin_code[13];	// �����ڵ�, ǥ���ڵ�
	double stk_lim_ratio;	// �����ѵ�����, 9V9999 (��:15%�϶� �� 01500���� ����)
	double psn_lim_ratio;	// �����ѵ�����, 9V9999 (��:15%�϶� �� 01500���� ����)
	double stk_lstd;	// �����ֽļ�, ����:��
	double ordbl_qty;	// �ֹ����ɼ���, ����:��
	char lim_xhs_clsf;	// �ѵ���������, 0:���� 1:�ѵ��ʰ� 2:�߰� 3:����
} DF_FBRD_FRGN_CFRM_DATA;


// �������� �ܱ��� �ѵ�������ܸŸ�
typedef struct _DF_FBRD_FRGN_LMT_XHS {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����, F5
	char info_clsf[3];	// ��������, 01:�ֽ�
	char mkt_clsf;	// ���屸��, 1:�������� 2:�ڽ��� 3:��������
	char isin_code[13];	// �����ڵ�, ǥ���ڵ�
	char clsf;	// ����, 1:�ܰ��Է� 2:�ܰ����
	int qty;	// ����, ����:��
	int prc;	// ����, ����:��
	char proc_time[9];	// ó���ð�, HHMMSSMM
} DF_FBRD_FRGN_LMT_XHS;


// ELW ������ǥ�ΰ���
typedef struct _DF_ELW_INV_IDX_SST {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����, C7
	char info_clsf[3];	// ��������, 02:ELW
	char mkt_clsf;	// ���屸��, 1:��������
	char isin_code[13];	// �����ڵ�, ǥ���ڵ�
	char calc_time[7];	// ����ð�, ����:HHMMSS(�ð�:��:��) 090000 ~ ������:JUNJJJ
	double std_thr_val;	// ǥ���̷а�, 9(8)9V9(2) ��Ī���� 2010.06.14
	double sst_delta;	// �ΰ��� - ��Ÿ, 9V9(6)
	double sst_gamma;	// �ΰ��� - ����, 9V9(6)
	double sst_theta;	// �ΰ��� - ��Ÿ, 9(6)V9(6)
	double sst_vega;	// �ΰ��� - ����, 9(6)V9(6)
	double sst_ro;	// �ΰ��� - ��, 9(6)V9(6)
	double itnl_vol;	// ���纯����, 9(3)V9(2) ��������ELW�� ��� 0 (2010.08.30)
	double tot_cost;	// ���ݺ��, 9(8)V9(2) ǥ��ELW�� ��� 0 (2010.08.30)
} DF_ELW_INV_IDX_SST;


// �ڽ���_�ڻ��� ��ġ����
typedef struct _DF_KOSPI_TRS_STK_ARNG_INFO {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����, A9
	char info_clsf[3];	// ��������, 01:�ֽ�
	char mkt_clsf;	// ���屸��, 1:�������� 2:�ڽ���
	char isin_code[13];	// �����ڵ�, ǥ���ڵ�
	int snr;	// �Ϸù�ȣ, 1~99999999 �Ǽ�üũ��
	char trs_stk_id[6];	// �ڻ��ֽŰ�ID, 0:�ش���� N:�ڻ��������Ϲ� S:�ڻ�����������ɼ�\n1~99999:�ڻ��ֽ�Ź�Ϸù�ȣ �ذ� ��������
	char ask_bid_clsf_code;	// �ŵ��ż������ڵ�, 0:��Ź 1:�ŵ� 2:�ż�
	char trs_stk_date[9];	// �ڻ��ֽ�û����, YYYYMMDD �ؽŰ��� ��� ��û���ڰ� ����
	char trs_stk_st_date[9];	// �ڻ��ֽŰ�������, YYYYMMDD �Ű����� �ڻ��ָŸ� ��������
	char trs_stk_ed_date[9];	// �ڻ��ֽŰ���������, YYYYMMDD �Ű����� �ڻ��ָŸ� ��������
	char trs_stk_trd_code;	// �ڻ��ָŸŹ���ڵ�, 0:�ش���� 1:�ڻ����Ϲ� 2:������ �ڻ��� 3:���ε� �ڻ���\n��2,3 : �������Ľð��ܴ뷮�ż��� ����, ���ϰŷ�(�ŸŰŷ���\n ����)���� ���\n ���Ϲ��ڻ��ִ� �ð��ܴ뷮 �ż��Ұ�(�ŵ��� ����)\n��3 : �������Ľð��ܴ뷮�ż��� ��/���Ѱ� ���Ѿ���
	int trs_stk_ptcp_nr;	// �ڻ��ֽ�û���������� ��ȣ, ȸ����ȣ ��) '00001'
	double open_trs_stk_qty;	// �ð����ϰ��ڻ��ֽ�û ����, �Ű�Ⱓ���� ��û�� �ð����ϰ� ��û ����
	double opr_time_trs_stk_qty;	// �����ڻ��ֽ�û����, �Ű�Ⱓ���� ��û�� ���� ��û ����
	double ofhr_msv_trs_stk_qty;	// �ð��ܴ뷮�ڻ��� ��û����, �ð���(����, ����)������ �ڻ��� �Ű����
	double trs_stk_cum_ccls_qty;	// �ڻ��ִ���ü�����, �Ű�Ⱓ���� ������, �ð��ܽ��忡�� �ڻ��� ü����� ����
	double trs_stk_cum_trd_val;	// �ڻ��ִ����ŷ����, �Ű�Ⱓ���� ������, �ð��ܽ��忡�� �ڻ��� �ŷ���� ����
} DF_KOSPI_TRS_STK_ARNG_INFO;


// �ڽ���_�ڻ��� �Ÿ�����
typedef struct _DF_KOSPI_TRS_STK_TRD_INFO {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����, B0
	char info_clsf[3];	// ��������, 01:�ֽ�
	char mkt_clsf;	// ���屸��, 1:�������� 2:�ڽ���
	char isin_code[13];	// �����ڵ�, ǥ���ڵ�
	int snr;	// �Ϸù�ȣ, 1~99999999 �����Ϸù�ȣ 2014.03.03
	int ccls_prc;	// ü�ᰡ��, ����:��
	double ccls_qty;	// ü�����, ����:��
	char sess_id[3];	// ����ID, �ڵ尪���� ����
	char bid_trs_stk_id[6];	// �ż��ڻ��ֽŰ�ID, 0:�ش���� N:�ڻ��������Ϲ� S:�ڻ���������Ź�ɼ�\n1~99999:�ڻ��ֽ�Ź(�Ű��Ϸù�ȣ)\n�ذ��� �������� ��) "N", "1"\n���ڻ��ֽ�Ź�Ϸù�ȣ�� ���񺰷� ���������� ���� ä����\n ������ ���� ��Ź�� �Ϸù�ȣ�� �����ϴ� ������ ����\n ���� ���ؼ� ���� ��Źȸ�翡�� �ڻ��ָ� �Ű��� ��\n �ֵ��� ����ϱ� ������
	char ask_trs_stk_id[6];	// �ŵ��ڻ��ֽŰ�ID, �ż��ڻ��ֽŰ�ID�� ����
} DF_KOSPI_TRS_STK_TRD_INFO;


// �������� KOSPI200����
typedef struct _DF_LVR_KOSPI200_IDX {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����, �ذ��߰��̵� ����
	char info_clsf[3];	// ��������, 01:�ֽ�
	char mkt_clsf;	// ���屸��, 1:�������� 2:�ڽ���
	char ind_code[4];	// �����ڵ�, �ذ��߰��̵� ����
	char time[7];	// �ð�, �ذ��߰��̵� ����
	double idx;	// ����, 9(6)V9(2)
	double ctrs;	// ���, 999999V99
	int ccls_qty;	// ü�����, ����:õ��
	int trd_val;	// �ŷ����, ����:�鸸��
} DF_LVR_KOSPI200_IDX;


// �ڽ���_ȸ��������������
typedef struct _DF_KOSPI_MBR_SCT_CNCL_DCLS {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����, R3
	char info_clsf[3];	// ��������, 01:�ֽ�
	char mkt_clsf;	// ���屸��, 1:�������� 2:�ڽ���
	char ind_code[13];	// �����ڵ�, **: �������ش�
	int stk_snr;	// �����Ϸù�ȣ, �����ġ(A0)�� �����Ϸù�ȣ
	char open_info_clsf_code[4];	// �������������ڵ�, �ڵ尪���� ����
	char open_time[7];	// �����ð�
	char mbr_nr[6];	// ȸ����ȣ
	int mbr_sct_rng_code;	// ȸ����������ڵ�, ȸ���� �ŷ��� ��� �Ǵ� �����ϴ� ����. Bitwise ����\n 1: �ŵ�(ǲ�ż�) ��Ź\n 2: �ŵ�(ǲ�ż�) �ڱ�\n 4: �ż�(ǲ�ŵ�) ��Ź\n 8: �ż�(ǲ�ŵ�) �ڱ�
} DF_KOSPI_MBR_SCT_CNCL_DCLS;


// �ڽ���_�����������(VI)
typedef struct _DF_KOSPI_STK_STAT_INFO {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����, R8
	char info_clsf[3];	// ��������, 01:�ֽ�
	char mkt_clsf;	// ���屸��, 1:�������� 2:�ڽ���
	char isin_code[13];	// �����ڵ�
	int stk_snr;	// �����Ϸù�ȣ, �����ġ(A0)�� �����Ϸù�ȣ
	char brd_id[3];	// ����ID, �� �ڵ尪���� ����
	int trd_ccls_proc_time;	// �Ÿ�ü��ó���ð�, �Ÿ�ü��ó���ð�
	int vi_cncl_time;	// VI�����ð�
	char vi_aply_clsf_code;	// VI���뱸���ڵ�, 1:VI-�ߵ�, 2:VI-����
	int vi_type_code;	// VI�����ڵ�, 1:����VI, 2:����VI, 3:����&����VI
	int stt_vi_base_prc;	// ����VI�ߵ����ذ���
	int dyn_vi_base_prc;	// ����VI�ߵ����ذ���
	int vi_prc;	// VI�ߵ�����
	char stt_vi_dspr[14];	// ����VI�ߵ����ݱ�����, ����VI�ߵ� ������\n��ȣ�ڸ�(���:0, ����:-) + 99999.999999(��ȿ���� 12�ڸ�)
	char dyn_vi_dspr[14];	// ����VI�ߵ����ݱ�����, ����VI�ߵ� ������\n��ȣ�ڸ�(���:0, ����:-) + 99999.999999(��ȿ���� 12�ڸ�)
} DF_KOSPI_STK_STAT_INFO;


// ETN �繫��Ź����
typedef struct _DF_ETN_TRA_INFO {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����, S1
	char info_clsf[3];	// ��������, 01:�ֽ�
	char mkt_clsf;	// ���屸��, 1:��������
	char isin_code[13];	// �����ڵ�, ǥ���ڵ�
	int snr;	// �Ϸù�ȣ, 1~99999999 �Ǽ�üũ��
	double fin_idx_val;	// ������ǥ��ġ, 9999999V99 �������������� ���� IV,����:��
	double idx_val;	// ��ǥ��ġ�ݾ�
	double prev_base_prc;	// ���ϰ�ǥ���ذ���, 9999999V99
	double prev_bdiv_base_prc;	// ���Ϲ������ǥ���ذ���, 9999999V99
	double prev_cash_div_val;	// �������ݹ��ݾ�, 9999999999V99
	double pprev_base_prc;	// �����ϰ��ݰ�ǥ���ذ���, 9999999V99
	int vol_fut_clsf;	// ��������������, 0:����������ETN 1:��Ÿ
	double ely_rdmp_min_qty;	// �ߵ���ȯû���ּҼ���, ����:����
	double ely_rdmp_fee_rate;	// �ߵ���ȯ��������, 99V99999999 ����:%
	double tot_cost;	// �����, 9999999V99 ����:��
} DF_ETN_TRA_INFO;


// ETN �������� ��������
typedef struct _DF_ETN_BASE_IDX_COMP_STK {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����, S2
	char info_clsf[3];	// ��������, 01:�ֽ�
	char mkt_clsf;	// ���屸��, 1:��������
	char isin_code[13];	// ETN �����ڵ�, ǥ���ڵ�(ETN�ڵ�)
	int data_snr;	// ������ �Ϸù�ȣ, 1~99999999 �����Ϸù�ȣ,�Ǽ�üũ��
	int date;	// ����, YYYYMMDD
	int trb_nr;	// �繫��Źȸ���ȣ, �繫��Źȸ���ȣ
	int comp_stk_nr;	// ���������, ����:����(��������)
	char comp_stk_code[13];	// ���������ڵ�, ǥ���ڵ�\n�ؿ������� ��� '0' �Ǵ� SPACE�� Setting�� �� ����
	char comp_stk_nm[81];	// ���������, �����
	double comp_rate;	// ������, ������ ������\n99999V99 ����:%
} DF_ETN_BASE_IDX_COMP_STK;


// ETN_�����ں�
typedef struct _DF_ETN_BYINV {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����, C0
	char info_clsf[3];	// ��������, 01:�ֽ�, 02:ELW, 03:ETF, 04:ETN
	char mkt_clsf;	// ���屸��, 1:�������� 2:�ڽ���
	char cmpt_time[7];	// ����ð�, 90�� �ֱ�
	char inv_code[5];	// �������ڵ�, ���ڵ尪���� ����\n*�ڵ�'7000'�� ����, ������� �׸� 0���� ���� (20181210)
	char ind_code[4];	// �����ڵ�, 0
	double ask_ccls_qty;	// �ŵ�ü�����, ����:��
	double ask_trd_val;	// �ŵ��ŷ����, ����:��
	double bid_ccls_qty;	// �ż�ü�����, ����:��
	double bid_trd_val;	// �ż��ŷ����, ����:��
} DF_ETN_BYINV;


// ETN IIV
typedef struct _DF_ETN_IIV {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����, S3
	char info_clsf[3];	// ��������, 01:�ֽ�
	char mkt_clsf;	// ���屸��, 1:��������
	char isin_code[13];	// ETN �����ڵ�, ETN �����ڵ�
	char time[7];	// �ð�, HHMMSS:���� JUNJJJ:�帶��
	double prev_iv;	// ���� IV, 9(7)V9(2)
	double opr_time_fin_iv;	// ����/���� IV, 9(7)V9(2)
} DF_ETN_IIV;


// ETN �����ġ
typedef struct _DF_ETN_STK_ARNG {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����, A1
	char info_clsf[3];	// ��������, 04:ETN
	char mkt_clsf;	// ���屸��, 1:��������
	char isin_code[13];	// �����ڵ�, ǥ���ڵ�
	int snr;	// �Ϸù�ȣ, 1~99999999 �Ǽ�üũ��
	char etn_ptcp_kor_nm[81];	// ETN��������������ѱ۸�
	char etn_ptcp_eng_nm[81];	// ETN������������ڿ�����
	char etn_ptcp_nr[6];	// ETN������������ڹ�ȣ, ETN����ȸ������ ��ȣ(�����, ������ ���о���)\n��) ��00001��
	char etn_fin_pymt_code;	// ETN������������ڵ�, A:����+�ǹ��μ������� C:���ݰ��� D:�ǹ��μ�������
	char etn_fin_trd_date[9];	// ETN�����ŷ�����, YYYYMMDD
	char etn_pymt_date[9];	// ETN��������, YYYYMMDD
	double etn_lp_hld_qty;	// ETN LP��������
	char loss_cut_etn_profit_strt_code[3];	// �ս�����ETN���ͱ����ڵ�, �ս�����ETN���ͱ����ڵ�\n�ˢ��ڵ尪�ˢ�\n 01: ��\n 02: ǲ\n 03: �ݽ�������\n 04: ǲ��������\n 05: �����ȯ �ݽ�������\n 06: �����ȯ ���ƿ���\n 07: ������ ������\n 08: �����ö���\n 09: �ܵ���\n 10: �����ȯ ǲ��������\n 11: �����ȯ ���ƿ�ǲ\n(2017.03.27 �׸��߰�)
	double etn_max_rdm_prc;	// ETN�ִ��ȯ����, ETN���� ���Ǵ� ����� ������ �ִ� ��ȯ���� \n9(9)V9(3)\n(2017.03.27 �׸��߰�)
	double etn_min_rdm_prc;	// ETN�ּһ�ȯ����, ETN���� ���Ǵ� ����� ������ �ּ� ��ȯ����\n9(9)V9(3)\n(2017.03.27 �׸��߰�)
	char etn_ely_rdm_flg;	// ETN�����ȯ���ɿ���, �ս����� ETN�� �����ȯ ���� ���� ����\n(2017.03.27 �׸��߰�)
	char etn_ely_rdm_frq_code[3];	// ETN�����ȯ�ֱ��ڵ�, �ս����� ETN�� �����ȯ �ֱ� ����\nETN�����ȯ���ɿ��ΰ� Y�϶��� ���ð���\n�ˢ��ڵ尪�ˢ�\n01: ����(����)\n02: �� 3����\n03: �� 4����\n04: �� 6����\n05: �� 1�� (��缭���� ����)\n06: 3�������� �� 1���� (��缭���� ����)\n07: 6�������� �� 1���� (��缭���� ����)\n(2017.03.27 �׸��߰�)
	char assm_prc_cmpt_inst_code1[3];	// �򰡰��ݻ������ڵ�1, ETN�� �򰡰����� �����ϴ� ����ڵ� 1\n�ˢ��ڵ尪�ˢ�\n01:�ѱ��ڻ���\n02:NICE P&I\n03:KISä����\n04:Fn�ڻ���\n(2017.03.27 �׸��߰�)
	char assm_prc_cmpt_inst_code2[3];	// �򰡰��ݻ������ڵ�2, ETN�� �򰡰����� �����ϴ� ����ڵ� 2\n�ˢ��ڵ尪�ˢ�\n01:�ѱ��ڻ���\n02:NICE P&I\n03:KISä����\n04:Fn�ڻ���\n(2017.03.27 �׸��߰�)
} DF_ETN_STK_ARNG;


// KTOP30����
typedef struct _DF_KTOP30_IDX {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����, �ذ��߰��̵� ����
	char info_clsf[3];	// ��������, 01:�ֽ�
	char mkt_clsf;	// ���屸��, 1:�������� 2:�ڽ��� 9:�ؿ��ְ�����
	char ind_clsf[4];	// �����ڵ�, �ذ��߰��̵� ����
	char time[7];	// �ð�
	double idx;	// ����, 9(6)V9(2)
	double crst;	// ���, 999999.99
	int ccls_qty;	// ü�����, ����:õ�� ���ؿ��ְ������� ��� FILLERó��
	int trd_val;	// �ŷ����, ����:�鸸�� ���ؿ��ְ������� ��� FILLERó��
} DF_KTOP30_IDX;


// KTOP30��������
typedef struct _DF_KTOP30_EXP_IDX {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����, �ذ��߰��̵� ����
	char info_clsf[3];	// ��������, 01:�ֽ�
	char mkt_clsf;	// ���屸��, 1:�������� 2:�ڽ��� 9:�ؿ��ְ�����
	char ind_clsf[4];	// �����ڵ�, �ذ��߰��̵� ����
	char time[7];	// �ð�
	double idx;	// ����, 9(6)V9(2)
	double crst;	// ���, 999999.99
	int ccls_qty;	// ü�����, ����:õ�� ���ؿ��ְ������� ��� FILLERó��
	int trd_val;	// �ŷ����, ����:�鸸�� ���ؿ��ְ������� ��� FILLERó��
} DF_KTOP30_EXP_IDX;
