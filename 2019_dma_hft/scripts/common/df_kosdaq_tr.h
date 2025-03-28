// df_kosdaq_tr.h
// �ڽ����ֽ� �ǽð� TR

#pragma once
// �ּ��� \n�� ���� ���߿� �̻ڰ� �ٲ����

#include "df_stock_common_tr.h"


// �ڽ��� TR��������
typedef struct _DF_KOSDAQ_TR_EXP_IDX {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����, �ذ��߰��̵� ����
	char info_clsf[3];	// ��������, 01:�ֽ�
	char mkt_clsf;	// ���屸��, 1:�������� 2:�ڽ��� 9:�ؿ��ְ����� 2012.04.30 �߰�
	char ind_clsf[4];	// �����ڵ�, �ذ��߰��̵� ����
	char time[7];	// �ð�, �ذ��߰��̵� ����   ���ؿ��ְ������� ��� GMT�ð�
	int idx;	// ����, 9(6)V9(2)
	char sign;	// ��ȣ, +:��� "-":�϶� " ":����
	double crst;	// ���, 999999V99
	int ccls_qty;	// ü�����, ����:õ��  ���ؿ��ְ������� ��� FILLERó��
	int trd_val;	// �ŷ����, ����:�鸸��  ���ؿ��ְ������� ��� FILLERó��
} DF_KOSDAQ_TR_EXP_IDX;


// �ڽ��� TR����
typedef struct _DF_KOSDAQ_TR_IDX {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����, �ذ��߰��̵� ����
	char info_clsf[3];	// ��������, 01:�ֽ�
	char mkt_clsf;	// ���屸��, 1:�������� 2:�ڽ��� 9:�ؿ��ְ����� 2012.04.30 �߰�
	char ind_clsf[4];	// �����ڵ�, �ذ��߰��̵� ����
	char time[7];	// �ð�, �ذ��߰��̵� ����   ���ؿ��ְ������� ��� GMT�ð�
	int idx;	// ����, 9(6)V9(2)
	char sign;	// ��ȣ, +:��� "-":�϶� " ":����
	double crst;	// ���, 999999V99
	int ccls_qty;	// ü�����, ����:õ��  ���ؿ��ְ������� ��� FILLERó��
	int trd_val;	// �ŷ����, ����:�鸸��  ���ؿ��ְ������� ��� FILLERó��
} DF_KOSDAQ_TR_IDX;


// �ڽ���_ü��
typedef struct _DF_KOSDAQ_CCLS {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����, A3
	char info_clsf[3];	// ��������, 01:�ֽ� 02:ELW
	char mkt_clsf;	// ���屸��, 1:�������� 2:�ڽ���
	char isin_code[13];	// �����ڵ�, ǥ���ڵ�
	int stk_snr;	// �����Ϸù�ȣ, �����ġ(A0)�� ����SEQ
	char brd_id[3];	// ����ID, �� �ڵ尪���� ����
	char ctrs_clsf;	// ���ϴ��(���ذ����) ����, 0:�ǴܺҰ� 1:���� 2:��� 3:���� 4:���� 5:�϶� �� ���Խð��ܱ����ڵ� ���� 4�� ��� ���� ���� ��� �� ���Խð��ܱ����ڵ� ���� 7,8�� ��� Buy-in���ذ� ���
	int prev_ctrs;	// ���ϴ��, ����:�� �����μ��� ����/������ �ű� ���� ���� : 0
	int ccls_prc;	// ü�ᰡ��, ����:��
	double ccls_qty;	// ü�����, ����:��
	char sess_id[3];	// ����ID, �� �ڵ尪���� ����
	int open;	// �ð�, ����:�� �ذ��߰��̵� ����
	int hi;	// ��, ����:�� �ذ��߰��̵� ����
	int low;	// ����, ����:�� �ذ��߰��̵� ����
	double cum_ccls_qty;	// ����ü�����, ����:�� �غ���ID���� ������
	double cum_trd_val;	// �����ŷ����, ����:�� �غ���ID���� ������
	char fin_bid_ask_clsf_code;	// �����ŵ��ż������ڵ�, 1:�ŵ� 2:�ż�
	char mtc_flg;	// ü�ᰡ��1ȣ����ġ����, 0:�ǴܺҰ� 1:��ġ 2:����ġ
	char ccls_time[7];	// ü��ð�, HHMMSS
	double lp_hld_qty;	// LP��������, LP(ü�����) ������ LP��������
	int ask_1_prc;	// �ŵ�1ȣ��, ����:�� �ذ��߰��̵� ����
	int bid_1_prc;	// �ż�1ȣ��, ����:�� �ذ��߰��̵� ����
} DF_KOSDAQ_CCLS;


// �ڽ���_���ذ�����
typedef struct _DF_KOSDAQ_BASE_PRC_DCS {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����, A4
	char info_clsf[3];	// ��������, 01:�ֽ�
	char mkt_clsf;	// ���屸��, 1:�������� 2:�ڽ���
	char isin_code[13];	// �����ڵ�, ǥ���ڵ�
	int snr;	// �����Ϸù�ȣ, �����ġ(A0)�� ����SEQ
	char brd_id[3];	// ����ID, �� �ڵ尪���� ����
	int base_prc;	// ���ذ���, ����:��
	int base_prc_ceil;	// ���ذ��ݻ��Ѱ�, ����:��
	int base_prc_flr;	// ���ذ������Ѱ�, ����:��
} DF_KOSDAQ_BASE_PRC_DCS;


// �ڽ���_���񸶰�
typedef struct _DF_KOSDAQ_STK_CLSG {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����, A6
	char info_clsf[3];	// ��������, 01:�ֽ� 02:ELW
	char mkt_clsf;	// ���屸��, 1:�������� 2:�ڽ���
	char isin_code[13];	// �����ڵ�, ǥ���ڵ�
	int snr;	// �����Ϸù�ȣ, �����ġ(A0)�� ����SEQ
	char brd_id[3];	// ����ID, �� �ڵ尪���� ����
	int stk_cls_prc;	// ���񸶰�����, ���Խð��ܱ����ڵ尡 1:�������϶��� ���񸶰����ݱ����ڵ尪�� SET ��. �� �ܿ��� SPACE
	char stk_cls_prc_clsf_code;	// ���񸶰����ݱ����ڵ�, 1 ü�ᰡ�� 2 �⼼ 3 �ŷ��� 4 �ð����ذ������� �⼼, �������� �ƴ� ��� SPACE
	int ofhr_ceil;	// ���񸶰��ð��ܴ��ϰ����Ѱ�
	int ofhr_flr;	// ���񸶰��ð��ܴ��ϰ����Ѱ�
	int stk_cls_mwprc;	// ���񸶰���հ����ְ�
	int dlv_base_prc;	// �����ε����ذ���
	int dlv_ceil;	// �����ε����Ѱ�
	int dlv_flr;	// �����ε����Ѱ�
} DF_KOSDAQ_STK_CLSG;


// �ڽ���_��TS
typedef struct _DF_KOSDAQ_MKT_OPR_TS {
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
} DF_KOSDAQ_MKT_OPR_TS;


// �ڽ���_�������
typedef struct _DF_KOSDAQ_ALLC_INFO {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����, O6
	char info_clsf[3];	// ��������, 01:�ֽ�
	char mkt_clsf;	// ���屸��, 1:��������, 2:�ڽ���,
	char isin_code[13];	// �����ڵ�, ǥ���ڵ�
	int stk_snr;	// �����Ϸù�ȣ, �����ġ(A0)�� �����Ϸù�ȣ
	char brd_id[3];	// ����ID, �� �ڵ尪���� ����
	char allc_apl_clsf_code;	// ������뱸���ڵ�, 1 ��а��� 2 �������
	int allc_proc_clsf_code;	// ���ó�������ڵ�, 1 �ż�����,2 �ż�����,3 �ŵ�����,4 �ŵ�����   �� ���ó�������ڵ�� ��а��ÿ��� �����ϰ� ������ ' ' ����
	int allc_cncl_time;	// ��������ð�, HHMMSS
} DF_KOSDAQ_ALLC_INFO;


// �ڽ���_�����ġ
typedef struct _DF_KOSDAQ_STK_ARNG {
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
	char stk_gr_id[3];	// ���Ǳ׷�ID, ST:�ֱ� MF:��������ȸ�� RT:�ε�������ȸ�� SC:��������ȸ��\nIF:��ȸ�����ں�������ȸ�� DR:�ֽĿ�Ź���� EW:ELW EF:ETF\nSW:�����μ������� SR:�����μ������� BC:�������� \nFE:�ؿ�ETF FS:�ܱ��ֱ�\nEN:ETN 2014.11.17
	char unit_trd_ccls_flg;	// �����Ÿ�ü�Ῡ��, Y, N (�����忡�� �����ð� ����ü�Ῡ��)
	char lock_clsf_code[3];	// �������ڵ�, 00:�ش���׾���(���� �߻����� ���) \n01:�Ǹ��� \n02:����\n03:�й�� \n04:�ǹ�� \n05:�߰�(�б�)����\n(2017.11.20 ����:�߰�����->�߰�(�б�)����)\n06:�Ǹ��߰�����\n07:�Ǹ��б����\n(2017.11.20 �߰�)\n99:��Ÿ  ��SW,SR,EW�� ���ش�(���ش��� ��� SPACE)
	char pval_chg_clsf_code[3];	// �׸鰡���汸���ڵ�, 00:�ش����(�׸鰡������ ������ �� �ִ� ���񱺿� ���� ����\n������ �ǹ�) 01:�׸���� 02:�׸麴�� 03:�ֽĺ��� 04:�ֽĺ��� 99:��Ÿ\n(2012.08.27)
	char open_base_prc_stk_flg;	// �ð����ذ������񿩺�, Y, N ��Y�� ���:�ű�����,�������,������,��Ⱓ�ŷ�����
	char rassm_stk_rsn_code[3];	// ������������ڵ�, 00:�ش����, 01:ȸ�����, 02:�ں�����, 03:��Ⱓ����,\n04:�ʰ��й�, 05:��Ը��� \n06: ȸ������պ�, 99:��Ÿ  \n�����Ǳ׷�ID ST,FS�� �ش�(���ش��� ��� SPACE)\n2011.02.28 ���а� �߰�(04:�ʰ��й�, 05:��Ը���)\n2012.08.27 ���ǿ�������(02:�ֽĺ���->02:�ں�����) \n2017.06.26 ���а� ����(01:������� -> 01:ȸ�����)\n2017.06.26 ���а� �߰�(06:ȸ������պ�)
	char base_prc_chg_stk_flg;	// ���ذ��ݺ������񿩺�, Y, N ��Y�� ���:����,�׸麯��,���� ��
	char rndn_cls_trgg_cond_code;	// ��������ߵ������ڵ�, ���ϰ��������� ���������� �ߵ�����.���Ǻιߵ�(2)�ΰ�� ���������Ģ���� �����ϴ� ���ݿ���� �����ϴ��� �Ǵ� �� �ߵ��� ������.\n##�ڵ尪##\n0:�̹ߵ�  1:�ߵ�  2:���Ǻιߵ�(���ݿ���Ǵ�)
	char mkt_alm_warn_fcst_flg;	// ����溸�������, Y, N\n\n2015.06.15 : "����溸���迹����(Y,N)"->"����溸�������(Y,N)" �׸񺯰�
	char mkt_alrm_clsf_code[3];	// ����溸�����ڵ�, 00:�ش����(����溸�� ������ �� �ִ� ���� ���ؼ� ������\n�ٰ� ������ �ǹ�) 01:�������� 02:���ڰ�� 03:��������
	char cogv_hlth_flg;	// ���豸���췮����, Y, N ���ڽ��ڸ� �ش�, ST,FS,DR,MF,EF�� �ش�
	char ifam_flg;	// �������񿩺�, Y, N
	char iscnt_flg;	// �Ҽ��ǰ�����������, Y, N
	char bdlt_flg;	// ��ȸ���忩��, Y, N
	char trsp_flg;	// �ŷ���������, Y, N
	char ind_lclsf_code[4];	// ����������з��ڵ�, (����)000:�����̺з�  ������������ ������� ����\n(�ڽ���)000:�����̺з�/���߾��ݵ� 008~014:�Ϲ� 015:IT\n�����Ǳ׷�ID ST,MF,RT,SC,IF�� �ش�
	char ind_mclsf_code[4];	// ���������ߺз��ڵ�, (����)000:�����̺з�\n(�ڽ���)000:�����̺з� 021~040:�Ϲ� 041~043:IT\n�����Ǳ׷�ID ST,MF,RT,SC,IF�� �ش�
	char ind_sclsf_code[4];	// ���������Һз��ڵ�, (����)000:�����̺з�\n(�ڽ���)000:�����̺з� 050~112:�Ϲ� 151~160:IT\n�����Ǳ׷�ID ST,MF,RT,SC,IF�� �ش�
	char ind_id[11];	// ����ID, ����(Type Of Industry)ID 2014.03.03 \n*����Ī:ǥ�ػ���ڵ� \n6�ڸ� ǥ�ػ���ڵ�� ������Ǹ� ������ �� �־� �ؿܻ���Ʈ�� �پ��� �����ڵ� ������ �Ұ��Ͽ� 10�ڸ��� Ȯ��. ���� ǥ�ػ���ڵ�� �״�� 1:1 ���εǾ� ������ 4�ڸ��� �����̽��� ä��\n6->10 2014.03.03
	char kospi200_str_ind;	// KOSPI200���;���, �ش���׾��� (2018.10.22 : �׸񼳸���)
	char mkt_cap_code;	// �ð��ѾױԸ��ڵ�, ����(0:���� 1:�� 2:�� 3:��)\n�ڽ���(0:���� 1:KOSDAQ100 2:KOSDAQmid300 3:KOSDAQsmall)\n�����Ǳ׷�ID ST,MF,RT,SC,IF�� �ش�
	char mnft_ind_flg;	// (����)���������� (�ڽ���)�߼ұ������, Y, N\n�����������δ� ST,MF,RT,SC,IF�� �ش�(�����ڵ� 027)\n���߼ұ�����δ� ST,FS,DR,EF�� �ش�
	char krx100_flg;	// KRX100���񿩺�, Y, N
	char gvnm_idx_stk_flg;	// (����)���豸���������񿩺�(�ڽ���) �ҼӺα����ڵ�, (����) Y, N\n(�ڽ���)�ҼӺα����ڵ� �� ��ó�������  2011.05.02\n  1:�췮�����, 2:��ó�����, 3:�߰߱����, 4:�ż�������,\n  A:�ܱ����, B:����ȸ��, C:SPAC, D:ETF E:��������,\n  F:��������ȯ������, Z:��Ÿ   \n�� A~Z�� �ҼӺ� ����\n2012.09.14 (���������ġ)   "���豸���������񿩺�" 1 Byte FILLER ó��\n(�ڽ��������ġ) "�ҼӺα����ڵ�" ��� ���
	char inst_clsf_code[3];	// ���ڱⱸ�����ڵ�, 00:�ش���� 01:���ǰ������ڱⱸ 02:�Ļ���ǰ���ڱⱸ\n03:�ε��갣�����ڱⱸ 04:�ǹ��������ڱⱸ\n05:�ܱ�����������ڱⱸ 06:�簣�����ڱⱸ\n07:Ư���������ڱⱸ\n�����Ǳ׷�ID MF,IF,BC�� �ش�(���ش��� ��� SPACE)
	char idx_stk_flg;	// (����)KOSPI�������񿩺� (�ڽ���)KOSDAQ�������񿩺�, Y, N\n(����)KOSPI����-> (����)KOSPI�������񿩺�,(�ڽ���)KOSDAQ�������񿩺� 2018.12.10
	char kospi50_flg;	// (����)KOSPI50����, Y, N
	int base_prc;	// ���ذ���
	char prev_cls_clsf_code;	// �������������ڵ�, 1:�Ǽ� 2:�⼼ 3:�ŷ��� 4:�ð����ذ������� �⼼
	int prev_cls_prc;	// ��������
	double prev_cum_ccls_qty;	// ���ϴ���ü�����
	double prev_cum_trd_val;	// ���ϴ����ŷ����
	int ceil_prc;	// ���Ѱ�
	int flr_prc;	// ���Ѱ�
	int sub_prc;	// ��밡��, ��ST,FS,DR,MF,RT,SC,IF,ET,FE,BC,EN �� �ش� 2014.11.17
	double par_val;	// �׸鰡, 9(9)V9(3) �ܱ��ֱ��� ��� �Ҽ�����°�ڸ����� ǥ������\n�ڽ����� ������ �ּ�ȭ����� ǥ�ô� ������������ ����\n��ST,FS,RT,SC,BC�� �ش�
	int issue_prc;	// ���డ��, ELW, �����μ������� ����
	char listd_date[9];	// ��������, YYYYMMDD
	double stk_listd;	// �����ֽļ�(�������Ǽ�)
	char arng_trd_flg;	// �����Ÿſ���, Y, N
	char eps_sign;	// �ִ������(EPS)��ȣ, +, "-"
	int eps;	// �ִ������(EPS), ����:�� �����Ǳ׷�ID ST,MF,RT,IF,FS �� �ش�
	char per_sign;	// �ְ�������(PER)��ȣ, +, "-"
	int per;	// �ְ�������(PER), 9(4)V9(2) �����Ǳ׷�ID ST,MF,RT,IF,FS �� �ش�
	char eps_cmpt_xclu_flg;	// �ִ�����ͻ������ܿ���, Y:�������� N:����\n�ذ��� 0, ��������, �����ǰ��� ���� �Ǵ� ���� �� ���
	char bps_sign;	// "�ִ���ڻ갡ġ (BPS)��ȣ", +, "-"
	int bps;	// �ִ���ڻ갡ġ(BPS), ����:�� �����Ǳ׷�ID ST,MF,RT,IF,FS �� �ش�
	char pbr_sign;	// "�ִ���ڻ���� (PBR)��ȣ", +, "-"
	int pbr;	// �ִ���ڻ����(PBR), 9(4)V9(2) �����Ǳ׷�ID ST,MF,RT,IF,FS �� �ش�
	char bps_cmpt_xclu_flg;	// "�ִ���ڻ갡ġ���� ���ܿ���", Y:�������� N:����\n�ذ��� 0, ��������, �����ǰ��� ���� �Ǵ� ������ ���
	char loss_flg;	// ��տ���, Y, N
	int dps;	// �ִ���ݾ�, �ִ����
	char dps_cmpt_xclu_flg;	// "�ִ���ݾ׻������ܿ���", Y:�������� N:����\n�ذ��� 0, ��������, �����ǰ��� ���� �Ǵ� ������ ���
	int dyr;	// ��������, 9(6)V9(1)
	char xist_open_date[9];	// ������������, �����Ǳ׷�ID MF,RT,SC,IF,BC �ش�.
	char xist_cls_date[9];	// ������������, �����Ǳ׷�ID MF,RT,SC,IF,BC �ش�. ST,FS,DR�� �켱�ָ� �ش�
	char exc_prd_open_date[9];	// ���Ⱓ��������, �����Ǳ׷�ID SW, EW �� �ش��
	char exc_prd_cls_date[9];	// "���Ⱓ�������� (�Ǹ����Ⱓ��������)", �����Ǳ׷�ID SW, EW �� �ش��
	double elw_wrnt_exc_prc;	// "ELW�����μ�������  ��簡��", 9(9)V9(3) ELW �Ǵ� �����μ��������� ��簡��
	double euity;	// �ں���, 9(18)V9(3) �ؿܿ����� ��� �Ҽ�����°�ڸ����� ǥ������\n�׸鰡*�����ֽļ�, ���ͼҰ��� ���� �κ��� ������\nMF�� �Է°�\n��ST,FS,MF,RT,SC,IF,BC�� �ش�
	char credit_ordbl_flg;	// �ſ��ֹ����ɿ���, Y, N
	int limt_prc_cond_clsf_code;	// ������ȣ�����Ǳ����ڵ�, X ->9 ��庯��, 1->5 ���̺���\nȣ���� ü�� �� �ܷ�����, Bitwise ����(*���߰��̵� ����) \n#�ڵ尪# \n1:FAS(Fill And Store) \n2:FOK(Fill Or Kill) \n4:FAK(Fill And Kill) \n*��������(FOK, Fill or Kill):�ֹ����� ��� ���� ü����� ������ ��� �ֹ��� �ڵ� ��ҵǴ� �ֹ� \n*��������(FAS, Fill and Store):�ֹ����� ��� ü�ᰡ�� ������ ü���ϰ� ��ü���ܷ��� ���� ���ߵ��� �ֹ��忡 ü�� ����Ű��, ������ ���� ��ü�� �ֹ��� ��� �ּҵ�
	int mkt_prc_cond_clsf_code;	// ���尡ȣ�����Ǳ����ڵ�, *��
	int cond_prc_cond_clsf_code;	// ���Ǻ�������ȣ�����Ǳ����ڵ�, *��
	int fvr_lmt_ord_cond_clsf_code;	// ������������ȣ�����Ǳ����ڵ�, *��
	int pfr_lmt_ord_cond_clsf_code;	// �ֿ켱������ȣ�����Ǳ����ڵ�, *��
	char cap_inc_clsf_code[3];	// ���ڱ����ڵ�, 00:�ش���� 01:�������� 02:�������� 03:���������� 99:��Ÿ
	char scrt_clsf_code;	// �����ֱǱ����ڵ�, 0:�ش����(������) 1:�����켱�� 2:�����켱�� 9:�����ֱ�(2012.07.23)\n�����Ǳ׷�ID ST���� �ش�\n�ر���Ī:�켱�ֱ����ڵ� 2014.03.03
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
	char preord_cls_flg;	// "�尳�����ð������� ���ɿ���", Y, N
	char preord_msv_trd_flg;	// "�尳�����ð��ܴ뷮 �ŸŰ��� ����", Y, N
	char preord_bsk_flg;	// "�尳�����ð��ܹٽ��� ���� ����", Y, N
	char fcst_ccls_flg;	// ����ü�ᰡ��������, Y, N
	char short_flg;	// ���ŵ����ɿ���, Y, N ���������� �ְų� ���� ���ŵ��� ȣ�����ɿ���
	char trkg_prf_mtp_sign;	// "������������� ��ȣ", �����Ǳ׷�ID EF,FE,EN �ش� 2014.11.17\n���׸���� 2014.11.17\n\n"+","-"  ��) �ι����� ��� "-"            2009.07.27
	double trkg_prf_mtp;	// �������������, �����Ǳ׷�ID EF,FE,EN �ش� 2014.11.17\n���׸���� 2014.11.17\n\n9(5)V9(6)  ���� �Ǵ� ���� ���� ��� ETF ���� ���� ���\n��) �������� 2���� ��� '00002000000'   2009.07.27
	char regulation_apl_flg;	// "Regulation S ���� ���񿩺�", Y, N                             2010.02.01
	char spc_flg;	// ����μ�����ȸ�翩��, Y, N                             2010.03.02
	char tax_type_code;	// ���������ڵ�, 0:�ش����, \n1:"���ǰŷ���"->"�����" �ڵ尪�� ����   2016.02.29, \n2:���ҵ漼(�����Ⱓ����), \n3:���ǰŷ���(ȸ����ETF)                2011.05.02\n4:"���ҵ漼(�ؿ��ֽ���������ETF)" �ڵ尪 �߰�   2016.02.29\n(BIG33�� FILLER��)
	double sbst_prc_rate;	// ��밡�ݻ�������, 99999V999999 2010.06.28 \n(BIG33�� FILLER��) \n��Exture������ ��밡�� 0�̸� ���������� 0�̾�����, Exture+������ ��밡�� 0�̾ �������� ���� 2014.03.03
	char inv_xctm_stk_flg;	// (�ڽ���)��������ȯ�����񿩺�, (�ڽ���) Y,N �������� �Ǵ� ���������� ��ȭ�� ����� �ִ�\n      �ν� ����¡�� ��� ���� (2011.05.02 �߰�)\n(BIG33�� FILLER��)
	char dlstg_date[9];	// ������������, YYYYMMDD �����Ǳ׷�ID SR �� �ش�, �ٸ� ���Ǳ׷�ID�� FILLERó��  2011.06.27 �߰�\n(BIG33�� FILLER��)
	char short_term_oh_clsf_code;	// �ܱ�������񱸺��ڵ�, 0: �ش����\n1: ��������\n2: ����\n3: ��������(��������)\n2012.11.05 �߰�
	char etf_cpy_clsf_code;	// ETF������������ڵ�, ETF�� �����ڻ� ������������ڵ� 2013.03.18 �߰�P:�ǹ�����S:�ռ����� A:Active (2015.11.23 �����ڵ��߰�)
	char kospi200_hi_divd_idx_flg;	// KOSPI200������������, Y,N\n2013.11.18
	char kospi200_lo_vol_idx_flg;	// KOSPI200����������������, Y,N\n2013.11.18
	char mtr_date[9];	// ��������, 2014.11.17
	char divd_type_code[3];	// �й�������ڵ�, �й�����¿� ���� �����ڵ� 2014.11.17 \n01:������ \n02:����(��ǥ��ġ �ݿ�) \n03:����(��ǥ��ġ �̹ݿ�) \n04:����(������) \n05:����(��Ÿ)
	char mtr_rdmp_prc_st_date[9];	// �����ȯ���ݰ�����������, 2014.11.17
	char mtr_rdmp_prc_ed_date[9];	// �����ȯ���ݰ�����������, 2014.11.17
	char etp_mcdz_clsf_code;	// ETP��ǰ�����ڵ�, (2015.11.23 �߰�)\n ETP��ǰ�����ڵ�\n ## �ڵ尪 ##\n1. ETF(����ȸ����)\n2. ETF(����������)\n3. ETN\n4. �ս����� ETN\n(2017.03.27:ELS�� ETN->�ս����� ETN)
	char idx_cmpt_inst_code;	// �����������ڵ�, (2015.11.23 �߰�)\n*�ڵ尪���� ����(KRX ����)
	char idx_mkt_clsf_id[7];	// ��������з�ID, (2015.11.23 �߰�)\n *��з�(2)+�ߺз�(2)+�Һз�(2)\n ���� �����Ǵ� �з��� �ڸ��� '00'�� ǥ��\n��,�Һз� ������ ���� �з��� ���� ���� �� �� ����
	char idx_snr[4];	// �����Ϸù�ȣ, (2015.11.23 �߰�)�����Ϸù�ȣ
	char trkg_idx_lvrg_invs_clsf_code[3];	// �����������������ι��������ڵ�, (2015.11.23 �߰�)\n## �ڵ尪 ##\n P1:�Ϲ�(1)\n P2:2X ��������(2)\n N1:1X �ι���(-1)\n N2:2X �ι���(-2)
	char ref_idx_lvrg_invs_clsf_code[3];	// �����������������ι��������ڵ�, (2015.11.23 �߰�)\n## �ڵ尪 ##\n P1:�Ϲ�(1)\n P2:2X ��������(2)\n N1:1X �ι���(-1)\n N2:2X �ι���(-2)
	char idx_ast_clsf_id1[7];	// �����ڻ�з�ID1, (2015.11.23 �߰�)\n *��з�(2)+�ߺз�(2)+�Һз�(2)\n ���� �����Ǵ� �з��� �ڸ��� '00'�� ǥ��\n��,�Һз� ������ ���� �з��� ���� ���� �� �� ����
	char idx_ast_clsf_id2[7];	// �����ڻ�з�ID2, (2015.11.23 �߰�)\n *��з�(2)+�ߺз�(2)+�Һз�(2)\n ���� �����Ǵ� �з��� �ڸ��� '00'�� ǥ��\n��,�Һз� ������ ���� �з��� ���� ���� �� �� ����
	char lp_odrbl_flg;	// LP�ֹ����ɿ���, (2015.11.23 �߰�) Y,N
	char kosdaq150_idx_stk_flg;	// KOSDAQ150�������񿩺�, (2015.11.23 �߰�)\nY,N
	char lo_vol_flg;	// ������������, (2016.06.27 �߰�)\nY,N
	char abnm_risg_flg;	// �̻�޵��, (2017.03.27 �߰�) \nY,N
	char krx300_idx_flg;	// KRX300��������, (2018.03.26 �߰�)\nY,N
	double qty_ceil;	// ���Ѽ���, (2018.09.17 �߰�)���Ѽ����� �ʰ��� ȣ���� �ź�ó�� �ʿ�.
} DF_KOSDAQ_STK_ARNG;


// �ڽ���_����� ����
typedef struct _DF_KOSDAQ_STGD_INFO {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����, I5
	char info_clsf[3];	// ��������, 01:�ֽ�
	char mkt_clsf;	// ���屸��, 1:�������� 2:�ڽ���
	char isin_code[13];	// �����ڵ�, ǥ���ڵ�
	int snr;	// �Ϸù�ȣ, 1~99999999 �Ǽ�üũ��
	char clsg_date[5];	// ������, 1~99999999 �Ǽ�üũ��
} DF_KOSDAQ_STGD_INFO;


// �ڽ���_���� �̺�Ʈ ����
typedef struct _DF_KOSDAQ_STK_EVT_INFO {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����, I6
	char info_clsf[3];	// ��������, 01:�ֽ�
	char mkt_clsf;	// ���屸��, 1:�������� 2:�ڽ���
	char  isin_code[13];	// �����ڵ�, ǥ���ڵ�
	int snr;	// �Ϸù�ȣ, 1~99999999 �Ǽ�üũ��
	char evt_code[3];	// �̺�Ʈ�����ڵ�, 01:�ŷ����� \n02:�������� \n03:�Ҽ��ǰ��ù��� \n04:�����Ÿ�\n05:��ȸ���� \n06:�������ȿ������ \n07:���豸���췮���\n08:���԰��ŵ��Ұ� \n09:Regulation S \n10:���ı������\n11:��������ȯ������\n12:�ܱ�������� (2012.11.05 �߰�)\n13:���� (2016.06.27�߰�)\n14:�������������� (2016.06.27�߰�)\n15:��������ä�� (2016.11.28�߰�)\n16:�̻�޵����� (2017.03.27�߰�)\n17:���ŵ��������� (2017.03.27 �߰�)\n18: LP������ (2017.06.26 �߰�)
	char evt_trgg_code[5];	// �̺�Ʈ�߻������ڵ�, �� ��÷ �ڵ尩������ �̺�Ʈ�������ڵ� ����\n�� �̺�Ʈ�����ڵ� 03,04,07,08,09,17 �� ���ؼ��� '0000' SET\n�� �ڵ��� ������ ���� �ڸ����� �ٸ��ϴ�. ������ Ÿ����\nX��� �̱� ������ �������ĵ˴ϴ�. ���� �����Ͽ� �ֽʽÿ�.\n(�ŷ����������ڵ�(3�ڸ�), �����������������ڵ�(4�ڸ�),\n��ȸ���������ڵ�(1�ڸ�), �������ȿ�����������ڵ�(2�ڸ�),\n��������ȯ����������ڵ�(4�ڸ�))
	char st_date[9];	// "��������,��������, ��������", YYYYMMDD
	char ed_date[9];	// ��������,��������, YYYYMMDD
} DF_KOSDAQ_STK_EVT_INFO;


// �ڽ���_LP ����
typedef struct _DF_KOSDAQ_LP_INFO {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����, I7
	char info_clsf[3];	// ��������, 01:�ֽ�
	char mkt_clsf;	// ���屸��, 1:�������� 2:�ڽ���
	char isin_code[13];	// �����ڵ�, ǥ���ڵ�
	int snr;	// �Ϸù�ȣ, 1~99999999 �Ǽ�üũ��
	char mkt_ptcp_nr[6];	// ���������ڹ�ȣ, ���������ڸ� �ĺ�/������ �� �ִ� ��ȣ\n�� ���������ڰ� ���� �ŷ����� ȸ���̸� �ŷ��Һ���\n���������ڹ�ȣ�� �޸���  ��) '00001'
	char lp_open_date[9];	// LP��������, ���������ް�������
	char lp_cls_date[9];	// LP��������, ������������������
	double min_ask_qty_mtp;	// �ּ�ȣ���������, LP/MM ȣ���� �Ÿż��������� �ּҹ��\n��) ���� 10�̰� �Ÿż��������� 10��(���)�̸�\nLP/MM ȣ���� 100��(���) �̻����� ȣ���ؾ���
	double max_ask_qty_mtp;	// �ִ�ȣ���������, LP/MM ȣ���� �Ÿż��������� �ִ���
	char ask_prc_sprd_unit_code;	// ȣ��������������ڵ�, R:���ݺ���\nY:���ͷ�����(ä��)\nT:ȣ�����ݴ��� ���\nA:���밪 (ä��)\n*����Ī:���Ѵ��������ڵ� 2014.03.03
	double ask_prc_sprd_val;	// ȣ���������尪, LP/MM ȣ�� ������ �ǹ��� �߻��ϴ� �ֿ켱ȣ����������\n���� �Ǵ� ����  9(13)V9(8)
	double off_mkt_ask_sprd_mtp;	// ����ȣ������������, �Ļ�,ELW,ETF�� �����ڻ��� �ؿܽ����� ���� �Ǵ� ������ ��� �ش� ������ ����, �尳����, ��������, ���� ���� ������ �����ڻ��� ���� ��ġ�� �Ǵ��� �� ���� �� ���� ���� ��ະ�� ������ �������� ���� Ȯ��� �������带 ����ϱ� ���� ��� \n*����Ī:����ȣ���������尪 \n�� ����ȣ���������尪 = ����ȣ������������ * ȣ���������尪 \n(Exture���� ����ȣ���������尪�� 0�ΰ�� Exture+������ ȣ���������尪�� ��ġ��Ŵ) 2014.03.03
	int obgt_ask_sbmt_time_invl;	// �ǹ�ȣ������ð�����, ����:��(sec) \n00�� �̳��� �ֿ켱ȣ�������� ��ҽ�Ű�� �ŵ�ȣ�� �Ǵ� �ż�ȣ���� ���� 2014.03.03
	double ask_min_ask_prc_amt;	// �ŵ��ּ�ȣ���ݾ�, 9(18)V9(3)                           2009.07.27
	double bid_min_ask_prc_amt;	// �ż��ּ�ȣ���ݾ�, 9(18)V9(3)                           2009.07.27
	double min_ask_amt;	// �ּ�ȣ���ݾ�, 9(18)V9(3) (2015.11.23 �߰�)\nMM(����������)ȣ���� �ּұݾ�\n��LP�ּ�ȣ����������� ��Ÿ������ ���, LP�ּ�ȣ����������� ���� ������ ��� �ش� �ʵ�� ����
	double max_ask_amt;	// �ִ�ȣ���ݾ�, 9(18)V9(3) (2015.11.23 �߰�) \n�ִ�ȣ���ݾ�
} DF_KOSDAQ_LP_INFO;


// �ڽ���_�뷮ü��
typedef struct _DF_KOSDAQ_MSV_CCLS {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����, C4
	char info_clsf[3];	// ��������, 01:�ֽ�
	char mkt_clsf;	// ���屸��, 1:�������� 2:�ڽ���
	char isin_code[13];	// �����ڵ�, ǥ���ڵ�
	int stk_snr;	// �����Ϸù�ȣ, �����ġ(A0)�� �����Ϸù�ȣ
	int snr;	// �Ϸù�ȣ, 1~99999999 �Ǽ�üũ��
	int bopen_rel_msv_ccls_qty;	// �尳�����ð��ܻ��뷮ü�����, ����:��
	int bopen_bsk_ccls_qty;	// �尳�����ð��ܹٽ���ü�����, ����:��
	int bopen_cmpt_msv_ccls_qty;	// �尳�����ð��ܰ���뷮ü�����, ����:��
	int rel_msv_ccls_qty;	// ���߻��뷮ü�����, ����:��
	int bsk_ccls_qty;	// ���߹ٽ���ü�����, ����:��
	int cmpt_msv_ccls_qty;	// ���߰���뷮ü�����, ����:��
	int ofhr_rel_msv_ccls_qty;	// �������Ľð��ܻ��뷮ü�����, ����:��
	int ofhr_bsk_ccls_qty;	// �������Ľð��ܹٽ���ü�����, ����:��
} DF_KOSDAQ_MSV_CCLS;


// �ڽ���_�ֽ�������������
typedef struct _DF_KOSDAQ_STK_INFO_DCLS {
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
	char lock_clsf_code[3];	// �������ڵ�, 00:�ش���׾��� 01:�Ǹ��� 02:���� 03:�й�� 04:�ǹ�� 05:�߰�(�б�)���� 06:�Ǹ��߰����� 07:�Ǹ��б���� 99:��Ÿ
	char pval_chg_clsf_code[3];	// �׸鰡���汸���ڵ�, 00:�ش���� 01:�׸���� 02:�׸麴�� 03:�ֽĺ��� 04:�ֽĺ��� 99:��Ÿ
	double trd_qty_unit;	// �Ÿż�������, 1�ִ���:1 10:10�ִ��� 100:100�ִ��� 1000:1000�ִ���
	double stk_lstd;	// �����ֽļ�
	char apnt;	// ��������, N:����  Y:����
	char bopen_ofhr_flg;	// �尳�����ð����������ɿ���, N:�ش���� Y:����
} DF_KOSDAQ_STK_INFO_DCLS;


// �ڽ���_ȸ��������������
typedef struct _DF_KOSDAQ_MBR_SCT_CNCL_DCLS {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����, R3
	char info_clsf[3];	// ��������, 01:�ֽ�
	char mkt_clsf;	// ���屸��, 1:�������� 2:�ڽ���
	char ind_code[13];	// �����ڵ�, **: �������ش�
	int stk_snr;	// �����Ϸù�ȣ, �����ġ(A0)�� �����Ϸù�ȣ
	char open_info_clsf_code[4];	// �������������ڵ�, �� �ڵ尪���� ����
	char open_time[7];	// �����ð�
	char mbr_nr[6];	// ȸ����ȣ
	int mbr_sct_rng_code;	// ȸ��������������ڵ�, ȸ���� �ŷ��� ��� �Ǵ� �����ϴ� ����. Bitwise ���� 1: �ŵ�(ǲ�ż�) ��Ź 2: �ŵ�(ǲ�ż�) �ڱ� 4: �ż�(ǲ�ŵ�) ��Ź 8: �ż�(ǲ�ŵ�) �ڱ�
} DF_KOSDAQ_MBR_SCT_CNCL_DCLS;


// �ڽ���_�������ٰ���
typedef struct _DF_KOSDAQ_MKT_OPR_DCLS {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����, M4
	char info_clsf[3];	// ��������, 01:�ֽ�
	char mkt_clsf;	// ���屸��, 1:�������� 2:�ڽ���
	char isin_code[13];	// �����ڵ�, �������� �� ��ġ��, ��������(KO)�� ���
	int stk_snr;	// �����Ϸù�ȣ, �����ġ(A0)�� �����Ϸù�ȣ
	char brd_id[3];	// ����ID, �� �ڵ尪���� ����
	char brd_evt_id[4];	// �����̺�ƮID, �� �ڵ尪���� ����
	char brd_evt_st[7];	// �����̺�Ʈ���۽ð�
	int brd_evt_code;	// �����̺�Ʈ���뱺�ڵ�, �� �ڵ尪���� ����
	char sess_open_cls_id[3];	// ���ǰ��������ڵ�, BS: ���尳�� BE: �������� SS: ���ǰ��� SE: �������� SH: �������� SR: �����簳
	char sess_id[3];	// ����ID, �� �ڵ尪���� ����
	char pbl_stk_code[13];	// ����������ڵ�, ������ġ�� ������ �Ǵ� �����ڵ� *�������� �����ڵ嵵 ���� �� ����
	char trsp_rsn_code[4];	// �ŷ����������ڵ�, �� �ڵ尪���� ���� *��������(KO) �� "  "
	char trsp_trgg_code;	// �ŷ������߻������ڵ�, 1:�ڱ����� 2:�����μ������� 3:�����μ������� 4:�����ڻ�ELW 5:����ELW 6:����� 7:�����ڻ�Ҽӽ��� *��������(KO)�� "1"
	int apl_step;	// ����ܰ�, CB �� ���������� Ȯ��� ����Ǵ� �ܰ�(�� ���� ���� "00")
} DF_KOSDAQ_MKT_OPR_DCLS;


// �ڽ���_�ڻ��� ��ġ����
typedef struct _DF_KOSDAQ_TRS_STK_ARNG_INFO {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����, A9
	char info_clsf[3];	// ��������, 01:�ֽ�
	char mkt_clsf;	// ���屸��, 1:�������� 2:�ڽ���
	char isin_code[13];	// �����ڵ�, ǥ���ڵ�
	int snr;	// �Ϸù�ȣ, 1~99999999 �Ǽ�üũ��
	char trs_stk_id[6];	// �ڻ��ֽŰ�ID, 0:�ش���� N:�ڻ��������Ϲ� S:�ڻ�����������ɼ�\n1~99999:�ڻ��ֽ�Ź�Ϸù�ȣ    �ذ� ��������
	char ask_bid_clsf_code;	// �ŵ��ż������ڵ�, 0:��Ź 1:�ŵ� 2:�ż�
	char trs_stk_date[9];	// �ڻ��ֽ�û����, YYYYMMDD �ؽŰ��� ��� ��û���ڰ� ����
	char trs_stk_st_date[9];	// �ڻ��ֽŰ�������, YYYYMMDD �Ű����� �ڻ��ָŸ� ��������
	char trs_stk_ed_date[9];	// �ڻ��ֽŰ���������, YYYYMMDD �Ű����� �ڻ��ָŸ� ��������
	char trs_stk_trd_code;	// �ڻ��ָŸŹ���ڵ�, 0:�ش���� 1:�ڻ����Ϲ� 2:������ �ڻ��� 3:���ε� �ڻ���\n��2,3 : �������Ľð��ܴ뷮�ż��� ����, ���ϰŷ�(�ŸŰŷ���\n        ����)���� ���\n        ���Ϲ��ڻ��ִ� �ð��ܴ뷮 �ż��Ұ�(�ŵ��� ����)\n��3 : �������Ľð��ܴ뷮�ż��� ��/���Ѱ� ���Ѿ���
	int trs_stk_ptcp_nr;	// "�ڻ��ֽ�û���������� ��ȣ", ȸ����ȣ ��) '00001'
	double open_trs_stk_qty;	// "�ð����ϰ��ڻ��ֽ�û ����", �Ű�Ⱓ���� ��û�� �ð����ϰ� ��û ����
	double opr_time_trs_stk_qty;	// �����ڻ��ֽ�û����, �Ű�Ⱓ���� ��û�� ���� ��û ����
	double ofhr_msv_trs_stk_qty;	// "�ð��ܴ뷮�ڻ��� ��û����", �ð���(����, ����)������ �ڻ��� �Ű����
	double trs_stk_cum_ccls_qty;	// �ڻ��ִ���ü�����, �Ű�Ⱓ���� ������, �ð��ܽ��忡�� �ڻ��� ü����� ����
	double trs_stk_cum_trd_val;	// �ڻ��ִ����ŷ����, �Ű�Ⱓ���� ������, �ð��ܽ��忡�� �ڻ��� �ŷ���� ����
} DF_KOSDAQ_TRS_STK_ARNG_INFO;


// �ڽ���_�ڻ��� �Ÿ�����
typedef struct _DF_KOSDAQ_TRS_STK_TRD_INFO {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����, B0
	char info_clsf[3];	// ��������, 01:�ֽ�
	char mkt_clsf;	// ���屸��, 1:�������� 2:�ڽ���
	char isin_code[13];	// �����ڵ�, ǥ���ڵ�
	int snr;	// �Ϸù�ȣ, 1~99999999 �����Ϸù�ȣ 2014.03.03
	int ccls_prc;	// ü�ᰡ��, ����:��
	double ccls_qty;	// ü�����, ����:��
	char sess_id[3];	// ����ID, �ڵ尪���� ����
	char bid_trs_stk_id[6];	// �ż��ڻ��ֽŰ�ID, 0:�ش���� N:�ڻ��������Ϲ� S:�ڻ���������Ź�ɼ�\n1~99999:�ڻ��ֽ�Ź(�Ű��Ϸù�ȣ)\n�ذ��� ��������  ��) "N", "1"\n���ڻ��ֽ�Ź�Ϸù�ȣ�� ���񺰷� ���������� ���� ä����\n  ������ ���� ��Ź�� �Ϸù�ȣ�� �����ϴ� ������ ����\n  ���� ���ؼ� ���� ��Źȸ�翡�� �ڻ��ָ� �Ű��� ��\n  �ֵ��� ����ϱ� ������
	char ask_trs_stk_id[6];	// �ŵ��ڻ��ֽŰ�ID, �ż��ڻ��ֽŰ�ID�� ����
} DF_KOSDAQ_TRS_STK_TRD_INFO;


// �ڽ���_�ü�RECOVERY
typedef struct _DF_KOSDAQ_MKT_PRC_RCVR {
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
	int hi;	// ��, ������ ��
	int low;	// ����, ������ ����
	int ask_prc;	// �ŵ�ȣ��, B1�� 0�� SET
	int bid_prc;	// �ż�ȣ��, B1�� 0�� SET
	double cum_ccls_qty;	// ����ü�����, ����:�� �ؽð��ܴ��ϰ�, BUY-IN�� ������ ��� ü����� �ջ�
	double cum_trd_val;	// �����ŷ����, ����:�� �ؽð��ܴ��ϰ�, BUY-IN�� ������ ��� �ŷ���� �ջ�
	char trend_flg;	// �Ǽ�/�⼼ ����, 0:�ʱⰪ 1:�Ǽ� 2:�⼼ 3:�ŷ��� 4:�ð����ذ������� �⼼
	char brd_evt_id[4];	// �����̺�ƮID, B1/B2 ������ �����̺�ƮID ������(���� ���°��� ���۵� �� ����). ����, �ش� �׸� '000' ���� ����. 2014.03.24)
	char brd_id[3];	// ����ID, �� �ڵ尪���� ����
	char trsp_flg;	// �ŷ���������, Y, N
	double bopen_ofhr_ccls_qty;	// �尳�����ð�������ü�����, �뷮, �ٽ����� ����, ����:��
	double bopen_ofhr_trd_val;	// �尳�����ð��������ŷ����, �뷮, �ٽ����� ����, ����:��
	double opr_time_ccls_qty;	// ������ü�����, �뷮, �ٽ����� ����, ����:��
	double opr_time_trd_val;	// ������ŷ����, �뷮, �ٽ����� ����, ����:��
	double ofhr_cls_ccls_qty;	// �������Ľð�������ü�����, �뷮, �ٽ����� ����, ����:��
	double ofhr_cls_trd_val;	// �������Ľð��������ŷ����, �뷮, �ٽ����� ����, ����:��
	char elw_ely_cls_flg;	// ELW�������Ῡ��, Y,N ��������ELW �� ������ Default 'N' SET
	int elw_ely_cls_time;	// ELW��������ð�, HHMMSS, ELW�������Ῡ�ΰ� 'Y'�� ��츸 ����
	int cmpt_msv_dir_clsf;	// ����뷮 ���ⱸ��, 0:�ش����, 1:�ŵ�, 2:�ż�
	double gen_bin_ccls_qty;	// �Ϲ� Buy-in ü�����, ����:��
	double gen_bin_ccls_trd_val;	// �Ϲ� Buy-in �ŷ����, ����:��
	double day_bin_ccls_qty;	// ���� Buy-in ü�����, ����:��
	double day_bin_ccls_trd_val;	// ���� Buy-in �ŷ����, ����:��
} DF_KOSDAQ_MKT_PRC_RCVR;


// �ڽ���_�ð��ܴ��ϰ�_��Ŀ����_����
typedef struct _DF_KOSDAQ_OFH_RCVR_FINAL {
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
	double ofhr_cnst_cum_ccls_qty;	// �ð��ܴ��ϰ�����ü�����
	double ofhr_cnst_cum_trd_val;	// �ð��ܴ��ϰ������ŷ����
	double tot_cum_ccls_qty;	// ��ü �� ����ü�����
	double tot_cum_trd_val;	// ��ü �� �����ŷ����
	char ofhr_mkt_clsf;	// �ð��ܴ��ϰ��屸��, 0:�ʱⰪ 1:�ð��ܴ��ϰ����� 2:�ð��ܴ��ϰ�����
	char trsp_flg;	// �ŷ���������, Y, N
	char trend_flg;	// �Ǽ�/�⼼ ����, 0:�ʱⰪ 1:�Ǽ� 2:�⼼ 3:�ŷ��� 4:�ð����ذ������� �⼼
} DF_KOSDAQ_OFH_RCVR_FINAL;


// �ڽ���_�ð��ܴ��ϰ�_��Ŀ����
typedef struct _DF_KOSDAQ_OFH_RCVR {
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
	double ofhr_cnst_cum_ccls_qty;	// �ð��ܴ��ϰ�����ü�����
	double ofhr_cnst_cum_trd_val;	// �ð��ܴ��ϰ������ŷ����
	double tot_cum_ccls_qty;	// ��ü �� ����ü�����
	double tot_cum_trd_val;	// ��ü �� �����ŷ����
	char ofhr_mkt_clsf;	// �ð��ܴ��ϰ��屸��, 0:�ʱⰪ 1:�ð��ܴ��ϰ����� 2:�ð��ܴ��ϰ�����
	char trsp_flg;	// �ŷ���������, Y, N
	char trend_flg;	// �Ǽ�/�⼼ ����, 0:�ʱⰪ 1:�Ǽ� 2:�⼼ 3:�ŷ��� 4:�ð����ذ������� �⼼
} DF_KOSDAQ_OFH_RCVR;


// �ڽ���_������
typedef struct _DF_KOSDAQ_CUR_FLCT {
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
} DF_KOSDAQ_CUR_FLCT;


// �ڽ���_Buy-in_�������
typedef struct _DF_KOSDAQ_BIN_EXCQ {
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
} DF_KOSDAQ_BIN_EXCQ;


// �ڽ��� ������ �����ͷ�
typedef struct _DF_KOSDAQ_BYIND_DYR {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����, P2
	char info_clsf[3];	// ��������, 01:�ֽ�
	char mkt_clsf;	// ���屸��, 1:�������� 2:�ڽ���
	char idx_ind_code[4];	// ���������ڵ�, ���ڵ尪���� ����
	double dyr;	// �����ͷ�, 99999V99
} DF_KOSDAQ_BYIND_DYR;


// �ڽ���_�尳����_ȣ���ܷ�
typedef struct _DF_KOSDAQ_BOPEN_ASK_RSD {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����, B8
	char info_clsf[3];	// ��������, 01:�ֽ�
	char mkt_clsf;	// ���屸��, 1:�������� 2:�ڽ���
	char isin_code[13];	// �����ڵ�, ǥ���ڵ�
	int stk_snr;	// �����Ϸù�ȣ, �����ġ(A0)�� �����Ϸù�ȣ
	double cum_ccls_qty;	// ����ü�����
	double tot_ask_rsd;	// �Ѹŵ�ȣ���ܷ�
	double tot_bid_rsd;	// �Ѹż�ȣ���ܷ�
} DF_KOSDAQ_BOPEN_ASK_RSD;


// �ڽ���_ȣ���ܷ�_LPȣ��_����
typedef struct _DF_KOSDAQ_ASK_RSD_WOLP {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����, B6
	char info_clsf[3];	// ��������, 01:�ֽ�
	char mkt_clsf;	// ���屸��, 1:�������� 2:�ڽ���
	char isin_code[13];	// �����ڵ�, ǥ���ڵ�
	int stk_snr;	// �����Ϸù�ȣ, �����ġ(A0)�� �����Ϸù�ȣ
	double cum_ccls_qty;	// ����ü�����
	DF_STOCK_LOB_INFO lob_infos[10];	// ȣ��
	double ask_10_tot_rsd;	// 10�ܰ�ȣ���ŵ����ܷ�
	double bid_10_tot_rsd;	// 10�ܰ�ȣ���ż����ܷ�
	double ofhr_ask_tot_rsd;	// �������Ľð��ܸŵ���ȣ���ܷ�, ����ID "G3"�϶� ���� ������
	double ofhr_bid_tot_rsd;	// �������Ľð��ܸż���ȣ���ܷ�, ����ID "G3"�϶� ���� ������
	char sess_id[3];	// ����ID, �� �ڵ尪���� ����
	char brd_id[3];	// ����ID, �� �ڵ尪���� ����
	int exp_ccls_prc;	// ����ü�ᰡ��
	double exp_ccls_qty;	// ����ü�����
	int cmpt_msv_dir_clsf;	// ����뷮 ���ⱸ��, 0:�ش����, 1:�ŵ�, 2:�ż�
} DF_KOSDAQ_ASK_RSD_WOLP;


// �ڽ���_���ŵ�
typedef struct _DF_KOSDAQ_SHORT {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����, I8
	char info_clsf[3];	// ��������, 01:�ֽ�
	char mkt_clsf;	// ���屸��, 1:�������� 2:�ڽ���
	char isin_code[13];	// �����ڵ�, ǥ���ڵ�
	int snr;	// �Ϸù�ȣ, 1~99999999 �����Ϸù�ȣ
	double short_brwg_ask_ccls_qty;	// "���ŵ��������Ǹŵ� ü�����", ����:��
	double short_brwg_ask_trd_val;	// "���ŵ��������Ǹŵ� �ŷ����", ����:��
} DF_KOSDAQ_SHORT;


// �ڽ���_�ü�����
typedef struct _DF_KOSDAQ_MKT_PRC_CLS {
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
	int hi;	// ��, ������ ��
	int low;	// ����, ������ ����
	int ask_prc;	// �ŵ�ȣ��, B1�� 0�� SET
	int bid_prc;	// �ż�ȣ��, B1�� 0�� SET
	double cum_ccls_qty;	// ����ü�����, ����:�� �ؽð��ܴ��ϰ�, BUY-IN�� ������ ��� ü����� �ջ�
	double cum_trd_val;	// �����ŷ����, ����:�� �ؽð��ܴ��ϰ�, BUY-IN�� ������ ��� �ŷ���� �ջ�
	char trend_flg;	// �Ǽ�/�⼼ ����, 0:�ʱⰪ 1:�Ǽ� 2:�⼼ 3:�ŷ��� 4:�ð����ذ������� �⼼
	char brd_evt_id[4];	// �����̺�ƮID, B1/B2 ������ �����̺�ƮID ������(���� ���°��� ���۵� �� ����). ����, �ش� �׸� '000' ���� ����. 2014.03.24)
	char brd_id[3];	// ����ID, �� �ڵ尪���� ����
	char trsp_flg;	// �ŷ���������, Y, N
	double bopen_ofhr_ccls_qty;	// �尳�����ð�������ü�����, �뷮, �ٽ����� ����, ����:��
	double bopen_ofhr_trd_val;	// �尳�����ð��������ŷ����, �뷮, �ٽ����� ����, ����:��
	double opr_time_ccls_qty;	// ������ü�����, �뷮, �ٽ����� ����, ����:��
	double opr_time_trd_val;	// ������ŷ����, �뷮, �ٽ����� ����, ����:��
	double ofhr_cls_ccls_qty;	// �������Ľð�������ü�����, �뷮, �ٽ����� ����, ����:��
	double ofhr_cls_trd_val;	// �������Ľð��������ŷ����, �뷮, �ٽ����� ����, ����:��
	char elw_ely_cls_flg;	// ELW�������Ῡ��, Y,N ��������ELW �� ������ Default 'N' SET
	int elw_ely_cls_time;	// ELW��������ð�, HHMMSS, ELW�������Ῡ�ΰ� 'Y'�� ��츸 ����
	int cmpt_msv_dir_clsf;	// ����뷮 ���ⱸ��, 0:�ش����, 1:�ŵ�, 2:�ż�
	double gen_bin_ccls_qty;	// �Ϲ� Buy-in ü�����, ����:��
	double gen_bin_ccls_trd_val;	// �Ϲ� Buy-in �ŷ����, ����:��
	double day_bin_ccls_qty;	// ���� Buy-in ü�����, ����:��
	double day_bin_ccls_trd_val;	// ���� Buy-in �ŷ����, ����:��
} DF_KOSDAQ_MKT_PRC_CLS;


// �ڽ���_�����������ں�
typedef struct _DF_KOSDAQ_BYIND_BYINV {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����, C0
	char info_clsf[3];	// ��������, 01:�ֽ�
	char mkt_clsf;	// ���屸��, 1:�������� 2:�ڽ���
	char cmpt_time[7];	// ����ð�, 90�� �ֱ�
	char inv_code[5];	// �������ڵ�, ���ڵ尪���� ����\n*�ڵ�'7000'�� ����, ������� �׸� 0���� ���� (20181210)
	char ind_code[4];	// �����ڵ�, ���ڵ尪���� ���������ڵ�з� ����\n�������;�ڽ���/�ڽ�����������,�ڽ���200����
	double ask_ccls_qty;	// �ŵ�ü�����, ����:��
	double ask_trd_val;	// �ŵ��ŷ����, ����:��
	double bid_ccls_qty;	// �ż�ü�����, ����:��
	double bid_trd_val;	// �ż��ŷ����, ����:��
} DF_KOSDAQ_BYIND_BYINV;


// K-OTC �Ҽ��ǰ��� ������, ������
typedef struct _DF_KOTC_ISCNT_DATE_INFO {
	char iscnt_apnt_date[9];	// �Ҽ��ǰ��� ������, YYYYMMDD
	char iscnt_ed_date[9];	// �Ҽ��ǰ��� ������, YYYYMMDD
} DF_KOTC_ISCNT_DATE_INFO;


// K-OTC �������� ����
typedef struct _DF_KOTC_INV_ATN_INFO {
	char inv_atn_rsn_code[3];	// �������� �����ڵ�, �ذ��߰��̵� ����
	char inv_atn_apnt_date[9];	// �������� ������, YYYYMMDD
} DF_KOTC_INV_ATN_INFO;


// K-OTC �����ġ
typedef struct _DF_KOTC_STK_ARNG {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����, A0
	char info_clsf[3];	// ��������, 01:�ֽ�
	char mkt_clsf;	// ���屸��, 3:K-OTC
	char isin_code[13];	// �����ڵ�, ǥ���ڵ�
	int snr;	// �Ϸù�ȣ, 1~99999999 �Ǽ�üũ��
	char sh_code[10];	// �����ڵ�, ��������((��)�ֽ� 6��7, ������ SPACE ó��)
	char proc_date[9];	// ó������, �������� (YYYYMMDD)
	char kor_stk_nm[81];	// �ѱ������, SIZE����(40��80) 2016.02.01
	char eng_abrv[41];	// �������, SIZE����(20��40) 2016.02.01
	char eng_stk_nm[81];	// ���������, SIZE����(40��80) 2016.02.01
	char kor_stk_abrv[41];	// �����(�ѱ۾��), SIZE����(20��40) 2016.02.01
	int stk_snr;	// �����Ϸù�ȣ
	char stk_clsf;	// ���񱸺�, 0:���� 1:�ű� 2:�߰�
	char mdim_biz_flg;	// �߼��߰߱������, 4:�߼ұ�� 5:�߰߱�� 6�߼��߰ߺ��ش� 7:��Ȯ��
	char std_type_ind_code[8];	// ǥ�ػ�������ڵ�
	int trd_base_prc;	// �Ÿű��ذ�, ��������ְ�, ���߻��� ���Ÿű��ذ��� SET\n�⼼�ô� '�⼼����' SET\nSIZE����(7��9) 2016.02.01
	int prev_cls;	// ��������, ����:��, SIZE����(7��9) 2016.02.01
	int prev_wavg_prc;	// ���ϰ�������ְ�, ����:��, SIZE����(7��9) 2016.02.01
	double pbct_stk_nr;	// �����ֽļ�, ����:��, SIZE����(12��15) 2016.02.01
	int pval;	// �׸鰡, ����:��, SIZE����(7��9) 2016.02.01
	char clsg_mth[3];	// ����, MM
	char clsg_clsf;	// ��걸��, 0:�����ֺ���(1-4) 5:1�켱�ֺ��� 6:2�켱�ֺ���
	double per;	// PER, 9999V99
	int eps;	// EPS, ����:��, SIZE����(7��9) 2016.02.01
	char trsp_flg;	// �ŷ���������, 0:���� 1:����
	char trsp_rsn[3];	// �ŷ���������, ���ڵ尪���� ����
	char lock_clsf;	// ������, 0:���� 1:�Ǹ��� 2:�׸���� 3:�׸麴�� 4:���� 5:����\n6:����
	char rgst_aplc[41];	// ��Ͻ�û��, �׸��(ASIS ������û��), SIZE����(30��40) 2016.02.01
	char trd_open_date[9];	// �ŸŰ�����, YYYYMMDD
	char cncl_clsf;	// ��������, �׸�� ����(ASIS ��ұ���)\n0:���� 1:���ֺ��տ� ���� ����2:���� �� �������\n(ASIS 0:���� 1:�ű��ֺ��տ� ���� ��� 2:�������)
	int whyr_hi_prc;	// �����ְ�, SIZE����(7��9) 2016.02.01
	int whyr_lo_prc;	// ����������, SIZE����(7��9) 2016.02.01
	char whyr_hi_date[5];	// �����ְ���, MMDD
	char whyr_lo_date[5];	// ����������, MMDD
	double yr_cum_qty;	// �������ŷ���, SIZE����(14��17) 2016.02.01
	double yr_cum_trd_val;	// ������ �ŷ� ���, ����:��, SIZE����(17��18) 2016.02.01
	char pbl_ofr_clsf;	// ���𱸺�, 0:�����, 1:����
	int pbl_ofr_prc;	// ����, ����:��, SIZE����(7��9) 2016.02.01
	char affl_clsf;	// �ҼӺ� ����, 4:��ϱ����,5:���������\n(ASIS 0:�Ϲݱ����, 1:��ó�����)
	char type_rgst_apnt;	// ���/��������, -�׸�� ����(ASIS ��������)\n-�� �߰�\n 0:�Ϲ����� 1:�ڽ����̰� 2:���������̰� 3:�ڳؽ��̰�\n (ASIS 0:�Ϲ����� 1:�ڽ����̰� 2:�ŷ����̰�)
	double prev_vlm;	// ���ϰŷ���
	int ceil_prc;	// ���Ѱ�, SIZE����(7��9) 2016.02.01
	int flr_prc;	// ���Ѱ�, SIZE����(7��9) 2016.02.01
	char iscnt;	// �Ҽ��ǰ���, 0:���� 1~5:�Ҽ��ǰ��� 1ȸ~5ȸ
	DF_KOTC_ISCNT_DATE_INFO iscnt_dates[5];	// �Ҽ��ǰ�����
	char inv_atn_flg;	// �������ǿ���, 0:���� 1:��������
	DF_KOTC_INV_ATN_INFO inv_atn_infos[15];	// ��������
	char mkt_cap_scale;	// �ð��ѾױԸ�, ���������ñ��� SPACE\n(0:���� 1:������ 2:������ 3:������)
	char idx_ind_l[3];	// ��������(��), ���������ñ��� SPACE
	char idx_ind_m[3];	// ��������(��), ���������ñ��� SPACE
	char idx_ind_s[4];	// ��������(��), ���������ñ��� SPACE
	char vtr_clsf;	// ��ó����, 0:�Ϲݱ��, 1:��ó���
	char trend_clsf;	// �⼼����, 0:�Ǽ�,1:�⼼,2:���ŷ�
	char arng_trd_flg;	// �����Ÿſ���, 0:����,1:�����Ÿ�
} DF_KOTC_STK_ARNG;


// K-OTC ȣ��
typedef struct _DF_KOTC_ASK_PRC {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����, A2
	char info_clsf[3];	// ��������, 01:�ֽ�
	char mkt_clsf;	// ���屸��, 3:K-OTC
	char isin_code[13];	// �����ڵ�, ǥ���ڵ�
	int data_snr;	// ������ �Ϸù�ȣ, ȣ��, ü��, ������ġ ������ �Ϸù�ȣ
	char proc_clsf;	// ó������, 1:���� 2:���� 3:���
	int ask_nr;	// ȣ����ȣ, ���� ó���� ȣ����ȣ
	int base_ask_nr;	// ��ȣ����ȣ, ����:0, ����/��ҽ� �ش��ȣ�� ��ȣ
	int base_ask_prc;	// ��ȣ������, ����:0, ����/��ҽ� ������, SIZE����(7��9) 2016.02.01
	char ask_bid_clsf;	// �ŵ�/�ż� ����, 1:�ŵ� 2:�ż�
	int prc;	// ����, ����:�ֹ����� ����:��������, SIZE����(7��9) 2016.02.01
	double qty;	// ����, ����:�ֹ����� ����/���:������/��� ����
	char acpt_time[7];	// �����ð�
	double ask_tot_rsd;	// �ŵ����ܷ�
	double bid_tot_rsd;	// �ż����ܷ�
	int ask_prf_prc;	// �ŵ��켱ȣ��, SIZE����(7��9) 2016.02.01
	double ask_prf_vol_rsd;	// �ŵ��켱ȣ���ܷ�
	int bid_prf_prc;	// �ż��켱ȣ��, SIZE����(7��9) 2016.02.01
	double bid_prf_vol_rsd;	// �ż��켱ȣ���ܷ�
	double prc_band_vol_rsd;	// ���ݴ�ȣ���ܷ�, ����:�ֹ��ܷ� ����:�����ܷ�
	double base_prc_band_vol_rsd;	// �����ݴ�ȣ���ܷ�, ����:0, ����/��ҽ� ���ܷ�
	char brkg_nr[4];	// ���ǻ��ȣ, �ŷ����ڵ� ����
	char brch_nm[13];	// ������, SPACE
} DF_KOTC_ASK_PRC;


// K-OTC ü��
typedef struct _DF_KOTC_CCLS {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����, A3
	char info_clsf[3];	// ��������, 01:�ֽ�
	char mkt_clsf;	// ���屸��, 3:K-OTC
	char isin_code[13];	// �����ڵ�, ǥ���ڵ�
	int data_snr;	// ������ �Ϸù�ȣ, ȣ��, ü��, ������ġ ������ �Ϸù�ȣ
	int ccls_nr;	// ü���ȣ, ���� ü���ȣ
	int ccls_prc;	// ü�ᰡ, SIZE����(7��9) 2016.02.01
	double ccls_qty;	// ü�ᷮ
	char ccls_time[7];	// ü��ð�
	int ask_prc_nr;	// �ŵ�ȣ����ȣ, ���� ȣ����ȣ��
	int bid_prc_nr;	// �ż�ȣ����ȣ, ���� ȣ����ȣ��
	int open;	// ��, SIZE����(7��9) 2016.02.01
	int hi;	// ����, SIZE����(7��9) 2016.02.01
	int wavg_prc;	// ��������ְ�, SIZE����(7��9) 2016.02.01
	double tot_ccls_cum_qty;	// ��üü�ᴩ���ŷ���
	double tot_ccls_cum_trd_val;	// ��üü�ᴩ���ŷ����
	double ask_tot_rsd;	// �ŵ����ܷ�
	double bid_tot_rsd;	// �ż����ܷ�
	int ask_prf_prc;	// �ŵ��켱ȣ��, SIZE����(7��9) 2016.02.01
	double ask_prf_vol_rsd;	// �ŵ��켱ȣ���ܷ�
	int bid_prf_prc;	// �ż��켱ȣ��, SIZE����(7��9) 2016.02.01
	double bid_prf_vol_rsd;	// �ż��켱ȣ���ܷ�
	char prev_ctrs_clsf;	// ���ϴ�񱸺�, +:��� -:�϶� SPACE:����
	int prev_ctrs;	// ���ϴ��, SIZE����(7��9) 2016.02.01
	double ccls_prc_ask_rsd;	// ü�ᰡ��ŵ��ܷ�
	double ccls_prc_bid_rsd;	// ü�ᰡ��ż��ܷ�
} DF_KOTC_CCLS;


// K-OTC ���񸶰�
typedef struct _DF_KOTC_STK_CLSG {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����, A6
	char info_clsf[3];	// ��������, 1
	char mkt_clsf;	// ���屸��, 3:K-OTC
	char isin_code[13];	// �����ڵ�, ǥ���ڵ�
	int data_snr;	// ������ �Ϸù�ȣ, ȣ��,ü��,�� ������ �Ϸù�ȣ
	int stk_cls_wght_prc;	// ���񸶰� ���߰�, SIZE����(7��9) 2016.02.01
	char trend_flg;	// �Ǽ�/�⼼����, 0:������հ�,1:�⼼,2:���ŷ�
} DF_KOTC_STK_CLSG;


// K-OTC ��
typedef struct _DF_KOTC_MKT_OPR {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����, A7
	char info_clsf[3];	// ��������, 01:�ֽ�
	char mkt_clsf;	// ���屸��, 3:K-OTC
	char isin_code[13];	// �����ڵ�, ǥ���ڵ�
	int data_snr;	// ������ �Ϸù�ȣ, ȣ��, ü��, ���� ������ �Ϸù�ȣ
	char clsf;	// ����, 1:�ŸŰŷ����� 2:�ŸŰŷ�����������
	char rsn[3];	// ����
} DF_KOTC_MKT_OPR;


// K-OTC ������ġ
typedef struct _DF_KOTC_MKT_ACT {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����, G5
	char info_clsf[3];	// ��������, 01:�ֽ�
	char mkt_clsf;	// ���屸��, 3:K-OTC
	char isin_code[13];	// �����ڵ�, ǥ���ڵ�
	char data_kind[3];	// ������ �з�, 01:���ذ� �� �����Ѱ� ���� 02:�ӽ�����\n03:�ӽ������� �簳
	char chg_date[9];	// ������, YYYYMMDD(�����ͺз� 01�� �ƴϸ� "0")
	char chg_time[9];	// ����ð�, HHMMSSMM(�����ͺз� 01�� �ƴϸ� "0")
	int bact_base_prc;	// ��ġ�� ���ذ�, ����:��(�����ͺз� 01�� �ƴϸ� "0"), \nSIZE����(7��9)  2016.02.01
	int bact_ceil;	// ��ġ�� ���Ѱ�, ����:��(�����ͺз� 01�� �ƴϸ� "0"), \nSIZE����(7��9)  2016.02.01
	int bact_flr;	// ��ġ�� ���Ѱ�, ����:��(�����ͺз� 01�� �ƴϸ� "0"), \nSIZE����(7��9)  2016.02.01
	int aact_base_prc;	// ��ġ�� ���ذ�, ����:��(�����ͺз� 01�� �ƴϸ� "0"), \nSIZE����(7��9)  2016.02.01
	int aact_ceil;	// ��ġ�� ���Ѱ�, ����:��(�����ͺз� 01�� �ƴϸ� "0"), \nSIZE����(7��9)  2016.02.01
	int aact_flr;	// ��ġ�� ���Ѱ�, ����:��(�����ͺз� 01�� �ƴϸ� "0"), \nSIZE����(7��9)  2016.02.01
} DF_KOTC_MKT_ACT;


// K-OTC ���� ��ġ/�ǽð�
typedef struct _DF_KOTC_DCLS_ARNG_RT {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����, E9:���ù�ġ F0:���ýǽð�
	char info_clsf[3];	// ��������, 01:�ֽ�
	char mkt_clsf;	// ���屸��, 3:K-OTC
	char isin_code[13];	// �����ڵ�, ��������:999999999999
	int dcls_snr;	// �����Ϸù�ȣ, 000001~999999\n��������:999999
	char rgst_date[9];	// �������, YYYYMMDD
	char proc_clsf;	// ó������, 1:���� 2:���� 3:���
	char rsn[3];	// ����, �ڵ尪���� ����
	int line_nr;	// ���ι�ȣ, 00:���� 01~20:���� 99:END
	char dcls_title[76];	// ��������/����
} DF_KOTC_DCLS_ARNG_RT;


// KOSDAQ����
typedef struct _DF_KOSDAQ_IDX {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����, �ذ��߰��̵� ����
	char info_clsf[3];	// ��������, 01:�ֽ�
	char mkt_clsf;	// ���屸��, 1:�������� 2:�ڽ���
	char ind_code[4];	// �����ڵ�, �ذ��߰��̵� ����
	char time[7];	// �ð�, �ذ��߰��̵� ����
	int idx;	// ����, 9(6)V9(2)
	char sign;	// ��ȣ, +:��� "-":�϶� " ":����
	double ctrs;	// ���, 999999V99
	int ccls_qty;	// ü�����, ����:õ��
	int trd_val;	// �ŷ����, ����:�鸸��
} DF_KOSDAQ_IDX;


// KOSDAQ��������
typedef struct _DF_KOSDAQ_EXP_IDX {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����, �ذ��߰��̵� ����
	char info_clsf[3];	// ��������, 01:�ֽ�
	char mkt_clsf;	// ���屸��, 1:�������� 2:�ڽ���
	char ind_code[4];	// �����ڵ�, �ذ��߰��̵� ����
	char time[7];	// �ð�, �ذ��߰��̵� ����
	int idx;	// ����, 9(6)V9(2)
	char sign;	// ��ȣ, +:��� "-":�϶� " ":����
	double ctrs;	// ���, 999999V99
	int ccls_qty;	// ü�����, ����:õ��
	int trd_val;	// �ŷ����, ����:�鸸��
} DF_KOSDAQ_EXP_IDX;


// �ڽ���_�ŷ���
typedef struct _DF_KOSDAQ_TRS {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����, B9
	char info_clsf[3];	// ��������, 01:�ֽ� 02:ELW
	char mkt_clsf;	// ���屸��, 1:�������� 2:�ڽ���
	char isin_code[13];	// �����ڵ�, ǥ���ڵ�
	int snr;	// �Ϸù�ȣ, 1~99999999 �����Ϸù�ȣ 2014.03.03
	DF_STOCK_SRC_INFO src_infos[5];	// �ŷ������� OCCURS
} DF_KOSDAQ_TRS;


// �ڽ���_���������ں� ����
typedef struct _DF_KOSDAQ_BYSTK_BYINV_CLS {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����, C1
	char info_clsf[3];	// ��������, 01:�ֽ� 02:ELW
	char mkt_clsf;	// ���屸��, 1:�������� 2:�ڽ���
	char isin_code[13];	// �����ڵ�, ǥ���ڵ�
	int snr;	// �Ϸù�ȣ, 1~99999999 �����Ϸù�ȣ 2014.03.03
	DF_STOCK_INV_INFO inv_infos[12];	// ������ OCCURS 12
} DF_KOSDAQ_BYSTK_BYINV_CLS;


// �ڽ���_���α׷��Ÿ� ȣ��
typedef struct _DF_KOSDAQ_PRGTRD_ASK {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����, C3
	char info_clsf[3];	// ��������, 01:�ֽ�
	char mkt_clsf;	// ���屸��, 1:�������� 2:�ڽ���
	char isin_code[13];	// �����ڵ�
	int snr;	// �Ϸù�ȣ, 1~99999999 �����Ϸù�ȣ 2014.03.03
	// ���α׷��Ÿ�ȣ���ܷ�, =============================================
	double idx_abtg_ask_rsd;	// �������͸ŵ�ȣ���ܷ�
	double idx_abtg_bid_rsd;	// �������͸ż�ȣ���ܷ�
	double idx_nabtg_ask_rsd;	// ���������͸ŵ�ȣ���ܷ�
	double idx_nabtg_bid_rsd;	// ���������͸ż�ȣ���ܷ�
	// ���α׷��Ÿ�ȣ������, =============================================
	double idx_abtg_ask_qty;	// �������͸ŵ�ȣ������
	double idx_abtg_bid_qty;	// �������͸ż�ȣ������
	double idx_nabtg_ask_qty;	// ���������͸ŵ�ȣ������
	double idx_nabtg_bid_qty;	// ���������͸ż�ȣ������
	// ���α׷��Ÿ� �������ÿ��ܷ�
	double prior_idx_abtg_ask_rsd;	// �������͸ŵ�ȣ���ܷ�
	double prior_idx_abtg_bid_rsd;	// �������͸ż�ȣ���ܷ�
	double prior_idx_nabtg_ask_rsd;	// ���������͸ŵ�ȣ���ܷ�
	double prior_idx_nabtg_bid_rsd;	// ���������͸ż�ȣ���ܷ�
	// ���α׷��Ÿ�ü�᳻��, =============================================
	double idx_abtg_ask_ccls_qty;	// "�������͸ŵ���Ź ü�����"
	double idx_abtg_ask_self_ccls_qty;	// "�������͸ŵ��ڱ� ü�����"
	double idx_abtg_bid_ccls_qty;	// "�������͸ż���Ź ü�����"
	double idx_abtg_bid_self_ccls_qty;	// "�������͸ż��ڱ� ü�����"
	double idx_nabtg_ask_ccls_qty;	// "���������͸ŵ���Ź ü�����"
	double idx_nabtg_ask_self_ccls_qty;	// "���������͸ŵ��ڱ� ü�����"
	double idx_nabtg_bid_ccls_qty;	// "���������͸ż���Ź ü�����"
	double idx_nabtg_bid_self_ccls_qty;	// "���������͸ż��ڱ� ü�����"
	double idx_abtg_ask_ccls_val;	// "�������͸ŵ���Ź ü��ݾ�"
	double idx_abtg_ask_self_ccls_val;	// "�������͸ŵ��ڱ� ü��ݾ�"
	double idx_abtg_bid_ccls_val;	// "�������͸ż���Ź ü��ݾ�"
	double idx_abtg_bid_self_ccls_val;	// "�������͸ż��ڱ� ü��ݾ�"
	double idx_nabtg_ask_ccls_val;	// "���������͸ŵ���Ź ü��ݾ�"
	double idx_nabtg_ask_self_ccls_val;	// "���������͸ŵ��ڱ� ü��ݾ�"
	double idx_nabtg_bid_ccls_val;	// "���������͸ż���Ź ü��ݾ�"
	double idx_nabtg_bid_self_ccls_val;	// "���������͸ż��ڱ� ü��ݾ�"
	// ���α׷��Ÿ� ���İ��ÿ��ܷ�", =============================================
	double post_idx_abtg_ask_rsd;	// �������͸ŵ�ȣ���ܷ�, 2011.05.30 �ű�
	double post_idx_abtg_bid_rsd;	// �������͸ż�ȣ���ܷ�, 2011.05.30 �ű�
	double post_idx_nabtg_ask_rsd;	// ���������͸ŵ�ȣ���ܷ�, 2011.05.30 �ű�
	double post_idx_nabtg_bid_rsd;	// ���������͸ż�ȣ���ܷ�, 2011.05.30 �ű�
} DF_KOSDAQ_PRGTRD_ASK;


// �ڽ���_���α׷��Ÿ� ��ü����
typedef struct _DF_KOSDAQ_PRGTRD_TOT {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����, J0
	char info_clsf[3];	// ��������, 01:�ֽ�
	char mkt_clsf;	// ���屸��, 1:�������� 2:�ڽ���
	// ���α׷��Ÿ�ȣ���ܷ�
	double idx_abtg_ask_rsd;	// �������͸ŵ�ȣ���ܷ�
	double idx_abtg_bid_rsd;	// �������͸ż�ȣ���ܷ�
	double idx_nabtg_ask_rsd;	// ���������͸ŵ�ȣ���ܷ�
	double idx_nabtg_bid_rsd;	// ���������͸ż�ȣ���ܷ�
	// ���α׷��Ÿ�ȣ������
	double idx_abtg_ask_qty;	// �������͸ŵ�ȣ������
	double idx_abtg_bid_qty;	// �������͸ż�ȣ������
	double idx_nabtg_ask_qty;	// ���������͸ŵ�ȣ������
	double idx_nabtg_bid_qty;	// ���������͸ż�ȣ������
	// ���α׷��Ÿ� �������ÿ��ܷ�
	double prior_idx_abtg_ask_rsd;	// �������͸ŵ�ȣ���ܷ�
	double prior_idx_abtg_bid_rsd;	// �������͸ż�ȣ���ܷ�
	double prior_idx_nabtg_ask_rsd;	// ���������͸ŵ�ȣ���ܷ�
	double prior_idx_nabtg_bid_rsd;	// ���������͸ż�ȣ���ܷ�
	// ���α׷��Ÿ�ü�᳻��
	double idx_abtg_ask_ccls_qty;	// "�������͸ŵ���Ź ü�����"
	double idx_abtg_ask_self_ccls_qty;	// "�������͸ŵ��ڱ� ü�����"
	double idx_abtg_bid_ccls_qty;	// "�������͸ż���Ź ü�����"
	double idx_abtg_bid_self_ccls_qty;	// "�������͸ż��ڱ� ü�����"
	double idx_nabtg_ask_ccls_qty;	// "���������͸ŵ���Ź ü�����"
	double idx_nabtg_ask_self_ccls_qty;	// "���������͸ŵ��ڱ� ü�����"
	double idx_nabtg_bid_ccls_qty;	// "���������͸ż���Ź ü�����"
	double idx_nabtg_bid_self_ccls_qty;	// "���������͸ż��ڱ� ü�����"
	double idx_abtg_ask_ccls_val;	// "�������͸ŵ���Ź ü��ݾ�"
	double idx_abtg_ask_self_ccls_val;	// "�������͸ŵ��ڱ� ü��ݾ�"
	double idx_abtg_bid_ccls_val;	// "�������͸ż���Ź ü��ݾ�"
	double idx_abtg_bid_self_ccls_val;	// "�������͸ż��ڱ� ü��ݾ�"
	double idx_nabtg_ask_ccls_val;	// "���������͸ŵ���Ź ü��ݾ�"
	double idx_nabtg_ask_self_ccls_val;	// "���������͸ŵ��ڱ� ü��ݾ�"
	double idx_nabtg_bid_ccls_val;	// "���������͸ż���Ź ü��ݾ�"
	double idx_nabtg_bid_self_ccls_val;	// "���������͸ż��ڱ� ü��ݾ�"
	// ���α׷��Ÿ� ���İ��ÿ��ܷ�
	double post_idx_abtg_ask_rsd;	// �������͸ŵ�ȣ���ܷ�
	double post_idx_abtg_bid_rsd;	// �������͸ż�ȣ���ܷ�
	double post_idx_nabtg_ask_rsd;	// ���������͸ŵ�ȣ���ܷ�
	double post_idx_nabtg_bid_rsd;	// ���������͸ż�ȣ���ܷ�
} DF_KOSDAQ_PRGTRD_TOT;


// �ڽ���_���α׷��Ÿ� �������İ���
typedef struct _DF_KOSDAQ_PRGTRD_DCLS {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����, C5
	char info_clsf[3];	// ��������, 01:�ֽ�
	char mkt_clsf;	// ���屸��, 1:�������� 2:�ڽ���
	char isin_code[13];	// �����ڵ�
	int snr;	// �Ϸù�ȣ, 1~99999999 �����Ϸù�ȣ 2014.03.03
	double prior_dcls_new_ask_qty;	// "�������ýű�ȣ�� �ŵ�����", ���� : ��\n�׸����:�ŵ����û�������->�������ýű�ȣ���ŵ�����
	double prior_dcls_new_bid_qty;	// "�������ýű�ȣ�� �ż�����", ���� : ��\n�׸����:�ż����û�������->�������ýű�ȣ���ż�����
	double prior_dcls_sbmt_ask_qty;	// "�������ñ�����ȣ�� �ŵ�����", ���� : ��\n�׸����:�ŵ����û�����������->�������ñ�����ȣ���ŵ�����
	double prior_dcls_sbmt_bid_qty;	// "�������ñ�����ȣ�� �ż�����", ���� : ��\n�׸����:�ż����û�����������->�������ñ�����ȣ���ż�����
	double post_dcls_ask_qty;	// ���İ��øŵ�����, ���� : ��,  �ű�                2011.05.03
	double post_dcls_bid_qty;	// ���İ��øż�����, ���� : ��,  �ű�                2011.05.03
} DF_KOSDAQ_PRGTRD_DCLS;


// �ڽ��� ���α׷��Ÿ� �����ں� �Ÿ���Ȳ
typedef struct _DF_KOSDAQ_PRGTRD_BYINV_STAT {
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
} DF_KOSDAQ_PRGTRD_BYINV_STAT;


// �ڽ���_�����������(VI)
typedef struct _DF_KOSDAQ_STK_STAT_INFO {
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
	char stt_vi_dspr[14];	// ����VI�ߵ�������, ����VI�ߵ� ������\n��ȣ�ڸ�(���:0, ����:-) + 99999.999999(��ȿ���� 12�ڸ�)
	char dyn_vi_dspr[14];	// ����VI�ߵ�������, ����VI�ߵ� ������\n��ȣ�ڸ�(���:0, ����:-) + 99999.999999(��ȿ���� 12�ڸ�)
} DF_KOSDAQ_STK_STAT_INFO;
