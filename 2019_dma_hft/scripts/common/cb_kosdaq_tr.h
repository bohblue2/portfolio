// cb_kosdaq_tr.h
// �ڽ����ֽ� �ǽð� TR

#pragma once
// �ּ��� \n�� ���� ���߿� �̻ڰ� �ٲ����

#include "cb_stock_common_tr.h"


// �ڽ��� TR��������
typedef struct _KOSDAQ_TR_EXP_IDX {
	char data_clsf[2];	// DATA����, �ذ��߰��̵� ����
	char info_clsf[2];	// ��������, 01:�ֽ�
	char mkt_clsf[1];	// ���屸��, 1:�������� 2:�ڽ��� 9:�ؿ��ְ����� 2012.04.30 �߰�
	char ind_clsf[3];	// �����ڵ�, �ذ��߰��̵� ����
	char time[6];	// �ð�, �ذ��߰��̵� ����   ���ؿ��ְ������� ��� GMT�ð�
	char idx[8];	// ����, 9(6)V9(2)
	char sign[1];	// ��ȣ, +:��� "-":�϶� " ":����
	char crst[8];	// ���, 999999V99
	char ccls_qty[8];	// ü�����, ����:õ��  ���ؿ��ְ������� ��� FILLERó��
	char trd_val[8];	// �ŷ����, ����:�鸸��  ���ؿ��ְ������� ��� FILLERó��
	char filler[2];	// FILLER, SPACE
	char ff[1];	// FF, END OF TEXT (0xFF)
} KOSDAQ_TR_EXP_IDX;


// �ڽ��� TR����
typedef struct _KOSDAQ_TR_IDX {
	char data_clsf[2];	// DATA����, �ذ��߰��̵� ����
	char info_clsf[2];	// ��������, 01:�ֽ�
	char mkt_clsf[1];	// ���屸��, 1:�������� 2:�ڽ��� 9:�ؿ��ְ����� 2012.04.30 �߰�
	char ind_clsf[3];	// �����ڵ�, �ذ��߰��̵� ����
	char time[6];	// �ð�, �ذ��߰��̵� ����   ���ؿ��ְ������� ��� GMT�ð�
	char idx[8];	// ����, 9(6)V9(2)
	char sign[1];	// ��ȣ, +:��� "-":�϶� " ":����
	char crst[8];	// ���, 999999V99
	char ccls_qty[8];	// ü�����, ����:õ��  ���ؿ��ְ������� ��� FILLERó��
	char trd_val[8];	// �ŷ����, ����:�鸸��  ���ؿ��ְ������� ��� FILLERó��
	char filler[2];	// FILLER, SPACE
	char ff[1];	// FF, END OF TEXT (0xFF)
} KOSDAQ_TR_IDX;


// �ڽ���_ü��
typedef struct _KOSDAQ_CCLS {
	char data_clsf[2];	// DATA����, A3
	char info_clsf[2];	// ��������, 01:�ֽ� 02:ELW
	char mkt_clsf[1];	// ���屸��, 1:�������� 2:�ڽ���
	char isin_code[12];	// �����ڵ�, ǥ���ڵ�
	char stk_snr[5];	// �����Ϸù�ȣ, �����ġ(A0)�� ����SEQ
	char brd_id[2];	// ����ID, �� �ڵ尪���� ����
	char ctrs_clsf[1];	// ���ϴ��(���ذ����) ����, 0:�ǴܺҰ� 1:���� 2:��� 3:���� 4:���� 5:�϶� �� ���Խð��ܱ����ڵ� ���� 4�� ��� ���� ���� ��� �� ���Խð��ܱ����ڵ� ���� 7,8�� ��� Buy-in���ذ� ���
	char prev_ctrs[9];	// ���ϴ��, ����:�� �����μ��� ����/������ �ű� ���� ���� : 0
	char ccls_prc[9];	// ü�ᰡ��, ����:��
	char ccls_qty[10];	// ü�����, ����:��
	char sess_id[2];	// ����ID, �� �ڵ尪���� ����
	char open[9];	// �ð�, ����:�� �ذ��߰��̵� ����
	char hi[9];	// ��, ����:�� �ذ��߰��̵� ����
	char low[9];	// ����, ����:�� �ذ��߰��̵� ����
	char cum_ccls_qty[12];	// ����ü�����, ����:�� �غ���ID���� ������
	char cum_trd_val[18];	// �����ŷ����, ����:�� �غ���ID���� ������
	char fin_bid_ask_clsf_code[1];	// �����ŵ��ż������ڵ�, 1:�ŵ� 2:�ż�
	char mtc_flg[1];	// ü�ᰡ��1ȣ����ġ����, 0:�ǴܺҰ� 1:��ġ 2:����ġ
	char ccls_time[6];	// ü��ð�, HHMMSS
	char lp_hld_qty[15];	// LP��������, LP(ü�����) ������ LP��������
	char ask_1_prc[9];	// �ŵ�1ȣ��, ����:�� �ذ��߰��̵� ����
	char bid_1_prc[9];	// �ż�1ȣ��, ����:�� �ذ��߰��̵� ����
	char filler[6];	// FILLER, SPACE
	char ff[1];	// FF, END OF TEXT (0xFF)
} KOSDAQ_CCLS;


// �ڽ���_���ذ�����
typedef struct _KOSDAQ_BASE_PRC_DCS {
	char data_clsf[2];	// DATA����, A4
	char info_clsf[2];	// ��������, 01:�ֽ�
	char mkt_clsf[1];	// ���屸��, 1:�������� 2:�ڽ���
	char isin_code[12];	// �����ڵ�, ǥ���ڵ�
	char snr[5];	// �����Ϸù�ȣ, �����ġ(A0)�� ����SEQ
	char brd_id[2];	// ����ID, �� �ڵ尪���� ����
	char base_prc[9];	// ���ذ���, ����:��
	char base_prc_ceil[9];	// ���ذ��ݻ��Ѱ�, ����:��
	char base_prc_flr[9];	// ���ذ������Ѱ�, ����:��
	char filler[8];	// FILLER, SPACE
	char ff[1];	// FF, END OF TEXT (0xFF)
} KOSDAQ_BASE_PRC_DCS;


// �ڽ���_���񸶰�
typedef struct _KOSDAQ_STK_CLSG {
	char data_clsf[2];	// DATA����, A6
	char info_clsf[2];	// ��������, 01:�ֽ� 02:ELW
	char mkt_clsf[1];	// ���屸��, 1:�������� 2:�ڽ���
	char isin_code[12];	// �����ڵ�, ǥ���ڵ�
	char snr[5];	// �����Ϸù�ȣ, �����ġ(A0)�� ����SEQ
	char brd_id[2];	// ����ID, �� �ڵ尪���� ����
	char stk_cls_prc[9];	// ���񸶰�����, ���Խð��ܱ����ڵ尡 1:�������϶��� ���񸶰����ݱ����ڵ尪�� SET ��. �� �ܿ��� SPACE
	char stk_cls_prc_clsf_code[1];	// ���񸶰����ݱ����ڵ�, 1 ü�ᰡ�� 2 �⼼ 3 �ŷ��� 4 �ð����ذ������� �⼼, �������� �ƴ� ��� SPACE
	char ofhr_ceil[9];	// ���񸶰��ð��ܴ��ϰ����Ѱ�
	char ofhr_flr[9];	// ���񸶰��ð��ܴ��ϰ����Ѱ�
	char stk_cls_mwprc[9];	// ���񸶰���հ����ְ�
	char dlv_base_prc[9];	// �����ε����ذ���
	char dlv_ceil[9];	// �����ε����Ѱ�
	char dlv_flr[9];	// �����ε����Ѱ�
	char filler[1];	// FILLER, SPACE
	char ff[1];	// FF, END OF TEXT (0xFF)
} KOSDAQ_STK_CLSG;


// �ڽ���_��TS
typedef struct _KOSDAQ_MKT_OPR_TS {
	char data_clsf[2];	// DATA����, A7
	char info_clsf[2];	// ��������, 01:�ֽ� 02:ELW
	char mkt_clsf[1];	// ���屸��, 1:�������� 2:�ڽ���
	char isin_code[12];	// �����ڵ�, ǥ���ڵ�
	char stk_snr[5];	// �����Ϸù�ȣ, �����ġ(A0)�� �����Ϸù�ȣ
	char brd_id[2];	// ����ID, �� �ڵ尪���� ����
	char brd_evt_id[3];	// �����̺�ƮID, �� �ڵ尪���� ����
	char brd_evt_st[6];	// �����̺�Ʈ���۽ð�
	char brd_evt_code[5];	// �����̺�Ʈ���뱺�ڵ�, �� �ڵ尪���� ����
	char sess_id[2];	// ����ID, �� �ڵ尪���� ����
	char trsp_rsn_code[3];	// �ŷ����������ڵ�, �� �ڵ尪���� ����
	char filler[6];	// FILLER, SPACE
	char ff[1];	// FF, END OF TEXT (0xFF)
} KOSDAQ_MKT_OPR_TS;


// �ڽ���_�������
typedef struct _KOSDAQ_ALLC_INFO {
	char data_clsf[2];	// DATA����, O6
	char info_clsf[2];	// ��������, 01:�ֽ�
	char mkt_clsf[1];	// ���屸��, 1:��������, 2:�ڽ���,
	char isin_code[12];	// �����ڵ�, ǥ���ڵ�
	char stk_snr[5];	// �����Ϸù�ȣ, �����ġ(A0)�� �����Ϸù�ȣ
	char brd_id[2];	// ����ID, �� �ڵ尪���� ����
	char allc_apl_clsf_code[1];	// ������뱸���ڵ�, 1 ��а��� 2 �������
	char allc_proc_clsf_code[1];	// ���ó�������ڵ�, 1 �ż�����,2 �ż�����,3 �ŵ�����,4 �ŵ�����   �� ���ó�������ڵ�� ��а��ÿ��� �����ϰ� ������ ' ' ����
	char allc_cncl_time[6];	// ��������ð�, HHMMSS
	char filler[7];	// FILLER, SPACE
	char ff[1];	// FF, END OF TEXT (0xFF)
} KOSDAQ_ALLC_INFO;


// �ڽ���_�����ġ
typedef struct _KOSDAQ_STK_ARNG {
	char data_clsf[2];	// DATA����, A0
	char info_clsf[2];	// ��������, 01:�ֽ�
	char mkt_clsf[1];	// ���屸��, 1:�������� 2:�ڽ���
	char isin_code[12];	// �����ڵ�, ǥ���ڵ�
	char snr[8];	// �Ϸù�ȣ, 1~99999999 �Ǽ�üũ��
	char sh_code[9];	// �����ڵ�, �ֽ�7�ڸ�(DR����) ��������9�ڸ�
	char kor_abbr[40];	// �����ѱ۾��
	char eng_abbr[40];	// ���񿵹����
	char opr_date[8];	// ��������, YYYYMMDD
	char info_allc_nr[5];	// �����й�׷��ȣ
	char stk_gr_id[2];	// ���Ǳ׷�ID, ST:�ֱ� MF:��������ȸ�� RT:�ε�������ȸ�� SC:��������ȸ��\nIF:��ȸ�����ں�������ȸ�� DR:�ֽĿ�Ź���� EW:ELW EF:ETF\nSW:�����μ������� SR:�����μ������� BC:�������� \nFE:�ؿ�ETF FS:�ܱ��ֱ�\nEN:ETN 2014.11.17
	char unit_trd_ccls_flg[1];	// �����Ÿ�ü�Ῡ��, Y, N (�����忡�� �����ð� ����ü�Ῡ��)
	char lock_clsf_code[2];	// �������ڵ�, 00:�ش���׾���(���� �߻����� ���) \n01:�Ǹ��� \n02:����\n03:�й�� \n04:�ǹ�� \n05:�߰�(�б�)����\n(2017.11.20 ����:�߰�����->�߰�(�б�)����)\n06:�Ǹ��߰�����\n07:�Ǹ��б����\n(2017.11.20 �߰�)\n99:��Ÿ  ��SW,SR,EW�� ���ش�(���ش��� ��� SPACE)
	char pval_chg_clsf_code[2];	// �׸鰡���汸���ڵ�, 00:�ش����(�׸鰡������ ������ �� �ִ� ���񱺿� ���� ����\n������ �ǹ�) 01:�׸���� 02:�׸麴�� 03:�ֽĺ��� 04:�ֽĺ��� 99:��Ÿ\n(2012.08.27)
	char open_base_prc_stk_flg[1];	// �ð����ذ������񿩺�, Y, N ��Y�� ���:�ű�����,�������,������,��Ⱓ�ŷ�����
	char rassm_stk_rsn_code[2];	// ������������ڵ�, 00:�ش����, 01:ȸ�����, 02:�ں�����, 03:��Ⱓ����,\n04:�ʰ��й�, 05:��Ը��� \n06: ȸ������պ�, 99:��Ÿ  \n�����Ǳ׷�ID ST,FS�� �ش�(���ش��� ��� SPACE)\n2011.02.28 ���а� �߰�(04:�ʰ��й�, 05:��Ը���)\n2012.08.27 ���ǿ�������(02:�ֽĺ���->02:�ں�����) \n2017.06.26 ���а� ����(01:������� -> 01:ȸ�����)\n2017.06.26 ���а� �߰�(06:ȸ������պ�)
	char base_prc_chg_stk_flg[1];	// ���ذ��ݺ������񿩺�, Y, N ��Y�� ���:����,�׸麯��,���� ��
	char rndn_cls_trgg_cond_code[1];	// ��������ߵ������ڵ�, ���ϰ��������� ���������� �ߵ�����.���Ǻιߵ�(2)�ΰ�� ���������Ģ���� �����ϴ� ���ݿ���� �����ϴ��� �Ǵ� �� �ߵ��� ������.\n##�ڵ尪##\n0:�̹ߵ�  1:�ߵ�  2:���Ǻιߵ�(���ݿ���Ǵ�)
	char mkt_alm_warn_fcst_flg[1];	// ����溸�������, Y, N\n\n2015.06.15 : "����溸���迹����(Y,N)"->"����溸�������(Y,N)" �׸񺯰�
	char mkt_alrm_clsf_code[2];	// ����溸�����ڵ�, 00:�ش����(����溸�� ������ �� �ִ� ���� ���ؼ� ������\n�ٰ� ������ �ǹ�) 01:�������� 02:���ڰ�� 03:��������
	char cogv_hlth_flg[1];	// ���豸���췮����, Y, N ���ڽ��ڸ� �ش�, ST,FS,DR,MF,EF�� �ش�
	char ifam_flg[1];	// �������񿩺�, Y, N
	char iscnt_flg[1];	// �Ҽ��ǰ�����������, Y, N
	char bdlt_flg[1];	// ��ȸ���忩��, Y, N
	char trsp_flg[1];	// �ŷ���������, Y, N
	char ind_lclsf_code[3];	// ����������з��ڵ�, (����)000:�����̺з�  ������������ ������� ����\n(�ڽ���)000:�����̺з�/���߾��ݵ� 008~014:�Ϲ� 015:IT\n�����Ǳ׷�ID ST,MF,RT,SC,IF�� �ش�
	char ind_mclsf_code[3];	// ���������ߺз��ڵ�, (����)000:�����̺з�\n(�ڽ���)000:�����̺з� 021~040:�Ϲ� 041~043:IT\n�����Ǳ׷�ID ST,MF,RT,SC,IF�� �ش�
	char ind_sclsf_code[3];	// ���������Һз��ڵ�, (����)000:�����̺з�\n(�ڽ���)000:�����̺з� 050~112:�Ϲ� 151~160:IT\n�����Ǳ׷�ID ST,MF,RT,SC,IF�� �ش�
	char ind_id[10];	// ����ID, ����(Type Of Industry)ID 2014.03.03 \n*����Ī:ǥ�ػ���ڵ� \n6�ڸ� ǥ�ػ���ڵ�� ������Ǹ� ������ �� �־� �ؿܻ���Ʈ�� �پ��� �����ڵ� ������ �Ұ��Ͽ� 10�ڸ��� Ȯ��. ���� ǥ�ػ���ڵ�� �״�� 1:1 ���εǾ� ������ 4�ڸ��� �����̽��� ä��\n6->10 2014.03.03
	char kospi200_str_ind[1];	// KOSPI200���;���, �ش���׾��� (2018.10.22 : �׸񼳸���)
	char mkt_cap_code[1];	// �ð��ѾױԸ��ڵ�, ����(0:���� 1:�� 2:�� 3:��)\n�ڽ���(0:���� 1:KOSDAQ100 2:KOSDAQmid300 3:KOSDAQsmall)\n�����Ǳ׷�ID ST,MF,RT,SC,IF�� �ش�
	char mnft_ind_flg[1];	// (����)���������� (�ڽ���)�߼ұ������, Y, N\n�����������δ� ST,MF,RT,SC,IF�� �ش�(�����ڵ� 027)\n���߼ұ�����δ� ST,FS,DR,EF�� �ش�
	char krx100_flg[1];	// KRX100���񿩺�, Y, N
	char filler1[1];	// FILLER, Y, N\n(����)����������񿩺� => FILLERó�� 2015.12.21\n(�ڽ���)KOSTAR�������񿩺� => FILLERó�� 2016.05.23
	char gvnm_idx_stk_flg[1];	// (����)���豸���������񿩺�(�ڽ���) �ҼӺα����ڵ�, (����) Y, N\n(�ڽ���)�ҼӺα����ڵ� �� ��ó�������  2011.05.02\n  1:�췮�����, 2:��ó�����, 3:�߰߱����, 4:�ż�������,\n  A:�ܱ����, B:����ȸ��, C:SPAC, D:ETF E:��������,\n  F:��������ȯ������, Z:��Ÿ   \n�� A~Z�� �ҼӺ� ����\n2012.09.14 (���������ġ)   "���豸���������񿩺�" 1 Byte FILLER ó��\n(�ڽ��������ġ) "�ҼӺα����ڵ�" ��� ���
	char inst_clsf_code[2];	// ���ڱⱸ�����ڵ�, 00:�ش���� 01:���ǰ������ڱⱸ 02:�Ļ���ǰ���ڱⱸ\n03:�ε��갣�����ڱⱸ 04:�ǹ��������ڱⱸ\n05:�ܱ�����������ڱⱸ 06:�簣�����ڱⱸ\n07:Ư���������ڱⱸ\n�����Ǳ׷�ID MF,IF,BC�� �ش�(���ش��� ��� SPACE)
	char idx_stk_flg[1];	// (����)KOSPI�������񿩺� (�ڽ���)KOSDAQ�������񿩺�, Y, N\n(����)KOSPI����-> (����)KOSPI�������񿩺�,(�ڽ���)KOSDAQ�������񿩺� 2018.12.10
	char filler2[1];	// (����)KOSPI100����(�ڽ���)FILLER, Y, N               �����̾�� �߰�   2009.11.16\n(�ڽ���)�����̾�� => FILLERó��   2016.05.23
	char kospi50_flg[1];	// (����)KOSPI50����, Y, N
	char filler3[1];	// FILLER, Y, N\nKRX���������ڵ������� => FILLER 2016.09.12
	char filler4[1];	// FILLER, Y, N\nKRX���������ݵ�ü���� => FILLER 2016.09.12
	char filler5[1];	// FILLER, Y, N\nKRX�����������̿����� => FILLER 2016.09.12
	char filler6[1];	// FILLER, Y, N\nKRX���������������� => FILLER 2016.09.12
	char filler7[1];	// FILLER, Y, N\nKRX��������������ſ��� => FILLERó�� 2015.12.21
	char filler8[1];	// FILLER, Y, N\nKRX��������������ȭ�п��� => FILLER 2016.09.12
	char filler9[1];	// FILLER, Y, N\nKRX��������ö������ => FILLER 2016.09.12
	char filler10[1];	// FILLER, Y, N\nKRX���������ʼ��Һ��翩�� => FILLERó�� 2015.12.21
	char filler11[1];	// FILLER, Y, N\nKRX���������̵����ſ��� => FILLER 2016.09.12
	char filler12[1];	// FILLER, Y, N\nKRX���������Ǽ����� => FILLER 2016.09.12
	char filler13[1];	// FILLER, Y, N\nKRX���������������񽺿��� => FILLERó�� 2015.12.21
	char filler14[1];	// FILLER, Y, N\nKRX�����������ǿ��� => FILLER 2016.09.12
	char filler15[1];	// FILLER, Y, N\nKRX�����������ڿ��� => FILLER 2016.09.12
	char base_prc[9];	// ���ذ���
	char prev_cls_clsf_code[1];	// �������������ڵ�, 1:�Ǽ� 2:�⼼ 3:�ŷ��� 4:�ð����ذ������� �⼼
	char prev_cls_prc[9];	// ��������
	char prev_cum_ccls_qty[12];	// ���ϴ���ü�����
	char prev_cum_trd_val[18];	// ���ϴ����ŷ����
	char ceil_prc[9];	// ���Ѱ�
	char flr_prc[9];	// ���Ѱ�
	char sub_prc[9];	// ��밡��, ��ST,FS,DR,MF,RT,SC,IF,ET,FE,BC,EN �� �ش� 2014.11.17
	char par_val[12];	// �׸鰡, 9(9)V9(3) �ܱ��ֱ��� ��� �Ҽ�����°�ڸ����� ǥ������\n�ڽ����� ������ �ּ�ȭ����� ǥ�ô� ������������ ����\n��ST,FS,RT,SC,BC�� �ش�
	char issue_prc[9];	// ���డ��, ELW, �����μ������� ����
	char listd_date[8];	// ��������, YYYYMMDD
	char stk_listd[15];	// �����ֽļ�(�������Ǽ�)
	char arng_trd_flg[1];	// �����Ÿſ���, Y, N
	char eps_sign[1];	// �ִ������(EPS)��ȣ, +, "-"
	char eps[9];	// �ִ������(EPS), ����:�� �����Ǳ׷�ID ST,MF,RT,IF,FS �� �ش�
	char per_sign[1];	// �ְ�������(PER)��ȣ, +, "-"
	char per[6];	// �ְ�������(PER), 9(4)V9(2) �����Ǳ׷�ID ST,MF,RT,IF,FS �� �ش�
	char eps_cmpt_xclu_flg[1];	// �ִ�����ͻ������ܿ���, Y:�������� N:����\n�ذ��� 0, ��������, �����ǰ��� ���� �Ǵ� ���� �� ���
	char bps_sign[1];	// "�ִ���ڻ갡ġ (BPS)��ȣ", +, "-"
	char bps[9];	// �ִ���ڻ갡ġ(BPS), ����:�� �����Ǳ׷�ID ST,MF,RT,IF,FS �� �ش�
	char pbr_sign[1];	// "�ִ���ڻ���� (PBR)��ȣ", +, "-"
	char pbr[6];	// �ִ���ڻ����(PBR), 9(4)V9(2) �����Ǳ׷�ID ST,MF,RT,IF,FS �� �ش�
	char bps_cmpt_xclu_flg[1];	// "�ִ���ڻ갡ġ���� ���ܿ���", Y:�������� N:����\n�ذ��� 0, ��������, �����ǰ��� ���� �Ǵ� ������ ���
	char loss_flg[1];	// ��տ���, Y, N
	char dps[8];	// �ִ���ݾ�, �ִ����
	char dps_cmpt_xclu_flg[1];	// "�ִ���ݾ׻������ܿ���", Y:�������� N:����\n�ذ��� 0, ��������, �����ǰ��� ���� �Ǵ� ������ ���
	char dyr[7];	// ��������, 9(6)V9(1)
	char xist_open_date[8];	// ������������, �����Ǳ׷�ID MF,RT,SC,IF,BC �ش�.
	char xist_cls_date[8];	// ������������, �����Ǳ׷�ID MF,RT,SC,IF,BC �ش�. ST,FS,DR�� �켱�ָ� �ش�
	char exc_prd_open_date[8];	// ���Ⱓ��������, �����Ǳ׷�ID SW, EW �� �ش��
	char exc_prd_cls_date[8];	// "���Ⱓ�������� (�Ǹ����Ⱓ��������)", �����Ǳ׷�ID SW, EW �� �ش��
	char elw_wrnt_exc_prc[12];	// "ELW�����μ�������  ��簡��", 9(9)V9(3) ELW �Ǵ� �����μ��������� ��簡��
	char euity[21];	// �ں���, 9(18)V9(3) �ؿܿ����� ��� �Ҽ�����°�ڸ����� ǥ������\n�׸鰡*�����ֽļ�, ���ͼҰ��� ���� �κ��� ������\nMF�� �Է°�\n��ST,FS,MF,RT,SC,IF,BC�� �ش�
	char credit_ordbl_flg[1];	// �ſ��ֹ����ɿ���, Y, N
	char limt_prc_cond_clsf_code[5];	// ������ȣ�����Ǳ����ڵ�, X ->9 ��庯��, 1->5 ���̺���\nȣ���� ü�� �� �ܷ�����, Bitwise ����(*���߰��̵� ����) \n#�ڵ尪# \n1:FAS(Fill And Store) \n2:FOK(Fill Or Kill) \n4:FAK(Fill And Kill) \n*��������(FOK, Fill or Kill):�ֹ����� ��� ���� ü����� ������ ��� �ֹ��� �ڵ� ��ҵǴ� �ֹ� \n*��������(FAS, Fill and Store):�ֹ����� ��� ü�ᰡ�� ������ ü���ϰ� ��ü���ܷ��� ���� ���ߵ��� �ֹ��忡 ü�� ����Ű��, ������ ���� ��ü�� �ֹ��� ��� �ּҵ�
	char mkt_prc_cond_clsf_code[5];	// ���尡ȣ�����Ǳ����ڵ�, *��
	char cond_prc_cond_clsf_code[5];	// ���Ǻ�������ȣ�����Ǳ����ڵ�, *��
	char fvr_lmt_ord_cond_clsf_code[5];	// ������������ȣ�����Ǳ����ڵ�, *��
	char pfr_lmt_ord_cond_clsf_code[5];	// �ֿ켱������ȣ�����Ǳ����ڵ�, *��
	char cap_inc_clsf_code[2];	// ���ڱ����ڵ�, 00:�ش���� 01:�������� 02:�������� 03:���������� 99:��Ÿ
	char scrt_clsf_code[1];	// �����ֱǱ����ڵ�, 0:�ش����(������) 1:�����켱�� 2:�����켱�� 9:�����ֱ�(2012.07.23)\n�����Ǳ׷�ID ST���� �ش�\n�ر���Ī:�켱�ֱ����ڵ� 2014.03.03
	char pbl_scrt_flg[1];	// �����ֿ���, Y, N ���������Ǹ� �ش�
	char asmt_prc[9];	// �򰡰���
	char min_ask_prc[9];	// ����ȣ������
	char max_ask_prc[9];	// �ְ�ȣ������
	char opr_time_trd_qty_unit[5];	// ������Ÿż�������, 1�ִ���:1 10:10�ִ��� 100:100�ִ��� 1000:1000�ִ���
	char ofhr_trd_qty_unit[5];	// �ð��ܸŸż�������, 1�ִ���:1 10:10�ִ��� 100:100�ִ��� 1000:1000�ִ���\n��BC,SW,SR,EW�� ����
	char ritz_code[1];	// ���������ڵ�, 1:�Ϲݸ��� 2:CRV����
	char obj_scrt_code[12];	// �����ֱ������ڵ�, ��SW,SR�� �ش�
	char filler16[1];	// FILLER, �����Ǳ׷�ID EF,FE,EN �ش� 2014.11.17\n���׸���� 2014.11.17\n\n1:�������� 2:�ڽ��� 3:���� 4:GICS 5:���ϰ�������\n8:MF(�Ű�) 9:�ؿ� S:S&P/KRX B:ä�� C:��ȭ M:��ǰ R:�ε���  \n2012.07.16 -  D:�����ڻ� �ű��߰�\n2014.11.17 -  E:�ֽ��Ļ�, W:WiseFn �ű��߰�\n*��������Ҽӽ��屸���ڵ� -> FILLER ���� (2015.11.23)
	char filler17[3];	// FILLER, �����Ǳ׷�ID EF,FE,EN �ش� 2014.11.17\n���׸���� 2014.11.17\n\n���ڵ尪���� ������������ڵ� ����\n�ذ� ���庰�� �����ڵ带 ���������� ������ �����Ƿ� �Ҽ�\n  ���屸���ڵ�� �����Ͽ� ����ؾ� ��\n*������������ڵ� -> FILLER ���� (2015.11.23)
	char filler18[1];	// FILLER, 0:�ش���� 1:����ȸ���� 2:���������� \n��ETF���� �̿� SPACE\n*ETF�����ڵ� -> FILLER ���� (2015.11.23)
	char filler19[4];	// FILLER, ����:����\n*ETF��������� -> FILLER ���� (2015.11.23)
	char crny_iso_code[3];	// ��ȭISO�ڵ�, AUD:ȣ�ִ޷� EUR:���� GBP:�����Ŀ�� HKD:ȫ��޷� ��\n���ڵ尪����-��ȭISO�ڵ� ����
	char nt_code[3];	// �����ڵ�, ISO 3166 �ڵ��� 3�ڸ� ���� �غ��� �ڵ�ǥ ����\n����ü ���Ǳ׷�ID�� �ش�
	char mkt_crt_flg[1];	// �����������ɿ���, Y, N
	char ofhr_trd_flg[1];	// �ð��ܸŸŰ��ɿ���, Y, N
	char preord_cls_flg[1];	// "�尳�����ð������� ���ɿ���", Y, N
	char preord_msv_trd_flg[1];	// "�尳�����ð��ܴ뷮 �ŸŰ��� ����", Y, N
	char preord_bsk_flg[1];	// "�尳�����ð��ܹٽ��� ���� ����", Y, N
	char fcst_ccls_flg[1];	// ����ü�ᰡ��������, Y, N
	char short_flg[1];	// ���ŵ����ɿ���, Y, N ���������� �ְų� ���� ���ŵ��� ȣ�����ɿ���
	char filler20[3];	// FILLER, ETF�� �����ϴ� �����ڻ��� ����ǥ�� ����. �������� ETF��\n"PT", �������� ETF�� ��ȭISO�ڵ�        2009.07.27\n*ETF���������ڻ�����ڵ� -> FILLER ����(2015.11.23)
	char trkg_prf_mtp_sign[1];	// "������������� ��ȣ", �����Ǳ׷�ID EF,FE,EN �ش� 2014.11.17\n���׸���� 2014.11.17\n\n"+","-"  ��) �ι����� ��� "-"            2009.07.27
	char trkg_prf_mtp[11];	// �������������, �����Ǳ׷�ID EF,FE,EN �ش� 2014.11.17\n���׸���� 2014.11.17\n\n9(5)V9(6)  ���� �Ǵ� ���� ���� ��� ETF ���� ���� ���\n��) �������� 2���� ��� '00002000000'   2009.07.27
	char filler21[1];	// FILLER, �����Ǳ׷�ID EF,FE,EN �ش� 2014.11.17\n���׸���� 2014.11.17\n\nD:���� F:�ؿ� C:����+����\n2009.07.27\n���������ڻ� �����ܱ���\n2012.10.10\nC:����+���� �ڵ� �� �߰�\n*���������ڻ걹���ܱ����ڵ� -> FILLER ����(2015.11.23)
	char filler22[1];	// FILLER, Y, N                             2009.09.14\nSRI�������� => FILLER 2016.09.12
	char filler23[1];	// FILLER, �����Ǳ׷�ID EF,FE,EN �ش� 2014.11.17\n���׸���� 2014.11.17\n\n1:�������� 2:�ڽ��� 3:���� 4:GICS 5:���ϰ������� \n8:MF(�Ű�) 9:�ؿ� S:S&P/KRX B:ä�� C:��ȭ M:��ǰ\nR:�ε��� 2011.05.02\n*���������Ҽӽ��屸���ڵ� -> FILLER ����(2015.11.23)
	char filler24[3];	// FILLER, �����Ǳ׷�ID EF,FE,EN �ش� 2014.11.17\n���׸���� 2014.11.17\n\n�ر��а����� ������������ڵ� ����\n�� ���庰�� �����ڵ带 ���������� ������ �����Ƿ� \n�Ҽӽ��屸���ڵ�� �����Ͽ� ����ؾ� ��   2009.09.14\n*�������������ڵ� -> FILLER ����(2015.11.23)
	char filler25[1];	// FILLER, Y, N                             2010.01.18\nKRX�����������迩�� => FILLER 2016.09.12
	char filler26[1];	// FILLER, Y, N                             2010.01.18\nKRX����������ۿ��� => FILLER 2016.09.12
	char regulation_apl_flg[1];	// "Regulation S ���� ���񿩺�", Y, N                             2010.02.01
	char spc_flg[1];	// ����μ�����ȸ�翩��, Y, N                             2010.03.02
	char tax_type_code[1];	// ���������ڵ�, 0:�ش����, \n1:"���ǰŷ���"->"�����" �ڵ尪�� ����   2016.02.29, \n2:���ҵ漼(�����Ⱓ����), \n3:���ǰŷ���(ȸ����ETF)                2011.05.02\n4:"���ҵ漼(�ؿ��ֽ���������ETF)" �ڵ尪 �߰�   2016.02.29\n(BIG33�� FILLER��)
	char sbst_prc_rate[11];	// ��밡�ݻ�������, 99999V999999 2010.06.28 \n(BIG33�� FILLER��) \n��Exture������ ��밡�� 0�̸� ���������� 0�̾�����, Exture+������ ��밡�� 0�̾ �������� ���� 2014.03.03
	char filler27[1];	// FILLER, Y,N                             2010.08.30\n(BIG33�� FILLER��)\nKRX���������Һ������뿩�� => FILLERó�� 2015.12.21
	char filler28[1];	// FILLER, Y,N                             2010.08.30\n(BIG33�� FILLER��)\nKRX�������������������θ�Ʈ���� => FILLERó�� 2015.12.21
	char filler29[1];	// FILLER, Y,N                             2010.10.01\n(BIG33�� FILLER��)\nȯ��å�������������� => FILLER 2016.09.12
	char filler30[1];	// FILLER, Y,N                             2010.12.20\n(BIG33�� FILLER��)\n�������������� => FILLERó�� 2015.12.21
	char inv_xctm_stk_flg[1];	// (�ڽ���)��������ȯ�����񿩺�, (�ڽ���) Y,N �������� �Ǵ� ���������� ��ȭ�� ����� �ִ�\n      �ν� ����¡�� ��� ���� (2011.05.02 �߰�)\n(BIG33�� FILLER��)
	char dlstg_date[8];	// ������������, YYYYMMDD �����Ǳ׷�ID SR �� �ش�, �ٸ� ���Ǳ׷�ID�� FILLERó��  2011.06.27 �߰�\n(BIG33�� FILLER��)
	char filler31[1];	// FILLER, Y,N\n2012.09.14 \n���豸��å�������������񿩺� => FILLER 2016.09.12
	char short_term_oh_clsf_code[1];	// �ܱ�������񱸺��ڵ�, 0: �ش����\n1: ��������\n2: ����\n3: ��������(��������)\n2012.11.05 �߰�
	char etf_cpy_clsf_code[1];	// ETF������������ڵ�, ETF�� �����ڻ� ������������ڵ� 2013.03.18 �߰�P:�ǹ�����S:�ռ����� A:Active (2015.11.23 �����ڵ��߰�)
	char filler32[1];	// FILLER, ETF��ǰ������ ���� �����ڵ� 2013.03.18 �߰�\n1:�Ļ���\n2:�Ϲ���\n*ETF��ǰ�����ڵ�-> FILLER ���� (2015.11.23)
	char kospi200_hi_divd_idx_flg[1];	// KOSPI200������������, Y,N\n2013.11.18
	char kospi200_lo_vol_idx_flg[1];	// KOSPI200����������������, Y,N\n2013.11.18
	char filler33[3];	// FILLER, 2014.11.17
	char mtr_date[8];	// ��������, 2014.11.17
	char filler34[3];	// FILLER, ETN��ǰ�з��� ���� �����ڵ� 2014.11.17 \n100:�ֽ�, 101:�����ǥ, \n102:����, 103:����, \n104:����ȭ, 105:�׸�, \n106:��Ÿ, \n200:ä��, 201:����ä, \n202:ȸ��ä, 203:�ܱ�ä, \n204:�����ϵ�, 205:��Ÿ, \n300:ȥ��, 301:�ֽ�, \n302:ä��, 303:��Ÿ, \n400:��ǰ, 401:������, \n402:����깰, 403:�ݼ�, \n404:����, 405:��Ÿ, \n500:��ü�ڻ�, 501:��ȭ, \n502:������, 503:�ε���, \n504:��Ÿ\n*ETN��ǰ�з��ڵ� -> FILLER ���� (2015.11.23)
	char divd_type_code[2];	// �й�������ڵ�, �й�����¿� ���� �����ڵ� 2014.11.17 \n01:������ \n02:����(��ǥ��ġ �ݿ�) \n03:����(��ǥ��ġ �̹ݿ�) \n04:����(������) \n05:����(��Ÿ)
	char mtr_rdmp_prc_st_date[8];	// �����ȯ���ݰ�����������, 2014.11.17
	char mtr_rdmp_prc_ed_date[8];	// �����ȯ���ݰ�����������, 2014.11.17
	char etp_mcdz_clsf_code[1];	// ETP��ǰ�����ڵ�, (2015.11.23 �߰�)\n ETP��ǰ�����ڵ�\n ## �ڵ尪 ##\n1. ETF(����ȸ����)\n2. ETF(����������)\n3. ETN\n4. �ս����� ETN\n(2017.03.27:ELS�� ETN->�ս����� ETN)
	char idx_cmpt_inst_code[1];	// �����������ڵ�, (2015.11.23 �߰�)\n*�ڵ尪���� ����(KRX ����)
	char idx_mkt_clsf_id[6];	// ��������з�ID, (2015.11.23 �߰�)\n *��з�(2)+�ߺз�(2)+�Һз�(2)\n ���� �����Ǵ� �з��� �ڸ��� '00'�� ǥ��\n��,�Һз� ������ ���� �з��� ���� ���� �� �� ����
	char idx_snr[3];	// �����Ϸù�ȣ, (2015.11.23 �߰�)�����Ϸù�ȣ
	char trkg_idx_lvrg_invs_clsf_code[2];	// �����������������ι��������ڵ�, (2015.11.23 �߰�)\n## �ڵ尪 ##\n P1:�Ϲ�(1)\n P2:2X ��������(2)\n N1:1X �ι���(-1)\n N2:2X �ι���(-2)
	char ref_idx_lvrg_invs_clsf_code[2];	// �����������������ι��������ڵ�, (2015.11.23 �߰�)\n## �ڵ尪 ##\n P1:�Ϲ�(1)\n P2:2X ��������(2)\n N1:1X �ι���(-1)\n N2:2X �ι���(-2)
	char idx_ast_clsf_id1[6];	// �����ڻ�з�ID1, (2015.11.23 �߰�)\n *��з�(2)+�ߺз�(2)+�Һз�(2)\n ���� �����Ǵ� �з��� �ڸ��� '00'�� ǥ��\n��,�Һз� ������ ���� �з��� ���� ���� �� �� ����
	char idx_ast_clsf_id2[6];	// �����ڻ�з�ID2, (2015.11.23 �߰�)\n *��з�(2)+�ߺз�(2)+�Һз�(2)\n ���� �����Ǵ� �з��� �ڸ��� '00'�� ǥ��\n��,�Һз� ������ ���� �з��� ���� ���� �� �� ����
	char lp_odrbl_flg[1];	// LP�ֹ����ɿ���, (2015.11.23 �߰�) Y,N
	char kosdaq150_idx_stk_flg[1];	// KOSDAQ150�������񿩺�, (2015.11.23 �߰�)\nY,N
	char lo_vol_flg[1];	// ������������, (2016.06.27 �߰�)\nY,N
	char abnm_risg_flg[1];	// �̻�޵��, (2017.03.27 �߰�) \nY,N
	char krx300_idx_flg[1];	// KRX300��������, (2018.03.26 �߰�)\nY,N
	char qty_ceil[16];	// ���Ѽ���, (2018.09.17 �߰�)���Ѽ����� �ʰ��� ȣ���� �ź�ó�� �ʿ�.
	char filler35[132];	// FILLER, SPACE 103��95 2011.06.27 ����\nSPACE 95->94 2012.09.14 ���� \nSPACE 94->93 2012.11.05 ����\nSPACE 93->91 2013.03.18 ���� \nSPACE 91->89 2013.11.18 ����\nSPACE 89->212 2014.03.03 ���� \nSPACE 212->180 2014.11.17 ����\nSPACE 180->151 2015.11.23 ����\nSPACE 151->150 2016.06.27 ����\nSPACE 150->149 2017.03.27 ����\nSPACE 149->148 2018.03.26 ����\nSPACE 148->132 2018.09.17 ����
	char ff[1];	// FF, END OF TEXT (0xFF)  640��800     2010.03.02
} KOSDAQ_STK_ARNG;


// �ڽ���_����� ����
typedef struct _KOSDAQ_STGD_INFO {
	char data_clsf[2];	// DATA����, I5
	char info_clsf[2];	// ��������, 01:�ֽ�
	char mkt_clsf[1];	// ���屸��, 1:�������� 2:�ڽ���
	char isin_code[12];	// �����ڵ�, ǥ���ڵ�
	char snr[8];	// �Ϸù�ȣ, 1~99999999 �Ǽ�üũ��
	char clsg_date[4];	// ������, 1~99999999 �Ǽ�üũ��
	char ff[1];	// FF, END OF TEXT (0xFF)
} KOSDAQ_STGD_INFO;


// �ڽ���_���� �̺�Ʈ ����
typedef struct _KOSDAQ_STK_EVT_INFO {
	char data_clsf[2];	// DATA����, I6
	char info_clsf[2];	// ��������, 01:�ֽ�
	char mkt_clsf[1];	// ���屸��, 1:�������� 2:�ڽ���
	char  isin_code[12];	// �����ڵ�, ǥ���ڵ�
	char snr[8];	// �Ϸù�ȣ, 1~99999999 �Ǽ�üũ��
	char evt_code[2];	// �̺�Ʈ�����ڵ�, 01:�ŷ����� \n02:�������� \n03:�Ҽ��ǰ��ù��� \n04:�����Ÿ�\n05:��ȸ���� \n06:�������ȿ������ \n07:���豸���췮���\n08:���԰��ŵ��Ұ� \n09:Regulation S \n10:���ı������\n11:��������ȯ������\n12:�ܱ�������� (2012.11.05 �߰�)\n13:���� (2016.06.27�߰�)\n14:�������������� (2016.06.27�߰�)\n15:��������ä�� (2016.11.28�߰�)\n16:�̻�޵����� (2017.03.27�߰�)\n17:���ŵ��������� (2017.03.27 �߰�)\n18: LP������ (2017.06.26 �߰�)
	char evt_trgg_code[4];	// �̺�Ʈ�߻������ڵ�, �� ��÷ �ڵ尩������ �̺�Ʈ�������ڵ� ����\n�� �̺�Ʈ�����ڵ� 03,04,07,08,09,17 �� ���ؼ��� '0000' SET\n�� �ڵ��� ������ ���� �ڸ����� �ٸ��ϴ�. ������ Ÿ����\nX��� �̱� ������ �������ĵ˴ϴ�. ���� �����Ͽ� �ֽʽÿ�.\n(�ŷ����������ڵ�(3�ڸ�), �����������������ڵ�(4�ڸ�),\n��ȸ���������ڵ�(1�ڸ�), �������ȿ�����������ڵ�(2�ڸ�),\n��������ȯ����������ڵ�(4�ڸ�))
	char st_date[8];	// "��������,��������, ��������", YYYYMMDD
	char ed_date[8];	// ��������,��������, YYYYMMDD
	char filler[2];	// FILLER, SPACE
	char ff[1];	// FF, END OF TEXT (0xFF)
} KOSDAQ_STK_EVT_INFO;


// �ڽ���_LP ����
typedef struct _KOSDAQ_LP_INFO {
	char data_clsf[2];	// DATA����, I7
	char info_clsf[2];	// ��������, 01:�ֽ�
	char mkt_clsf[1];	// ���屸��, 1:�������� 2:�ڽ���
	char isin_code[12];	// �����ڵ�, ǥ���ڵ�
	char snr[8];	// �Ϸù�ȣ, 1~99999999 �Ǽ�üũ��
	char mkt_ptcp_nr[5];	// ���������ڹ�ȣ, ���������ڸ� �ĺ�/������ �� �ִ� ��ȣ\n�� ���������ڰ� ���� �ŷ����� ȸ���̸� �ŷ��Һ���\n���������ڹ�ȣ�� �޸���  ��) '00001'
	char lp_open_date[8];	// LP��������, ���������ް�������
	char lp_cls_date[8];	// LP��������, ������������������
	char min_ask_qty_mtp[11];	// �ּ�ȣ���������, LP/MM ȣ���� �Ÿż��������� �ּҹ��\n��) ���� 10�̰� �Ÿż��������� 10��(���)�̸�\nLP/MM ȣ���� 100��(���) �̻����� ȣ���ؾ���
	char max_ask_qty_mtp[11];	// �ִ�ȣ���������, LP/MM ȣ���� �Ÿż��������� �ִ���
	char ask_prc_sprd_unit_code[1];	// ȣ��������������ڵ�, R:���ݺ���\nY:���ͷ�����(ä��)\nT:ȣ�����ݴ��� ���\nA:���밪 (ä��)\n*����Ī:���Ѵ��������ڵ� 2014.03.03
	char ask_prc_sprd_val[21];	// ȣ���������尪, LP/MM ȣ�� ������ �ǹ��� �߻��ϴ� �ֿ켱ȣ����������\n���� �Ǵ� ����  9(13)V9(8)
	char off_mkt_ask_sprd_mtp[11];	// ����ȣ������������, �Ļ�,ELW,ETF�� �����ڻ��� �ؿܽ����� ���� �Ǵ� ������ ��� �ش� ������ ����, �尳����, ��������, ���� ���� ������ �����ڻ��� ���� ��ġ�� �Ǵ��� �� ���� �� ���� ���� ��ະ�� ������ �������� ���� Ȯ��� �������带 ����ϱ� ���� ��� \n*����Ī:����ȣ���������尪 \n�� ����ȣ���������尪 = ����ȣ������������ * ȣ���������尪 \n(Exture���� ����ȣ���������尪�� 0�ΰ�� Exture+������ ȣ���������尪�� ��ġ��Ŵ) 2014.03.03
	char obgt_ask_sbmt_time_invl[6];	// �ǹ�ȣ������ð�����, ����:��(sec) \n00�� �̳��� �ֿ켱ȣ�������� ��ҽ�Ű�� �ŵ�ȣ�� �Ǵ� �ż�ȣ���� ���� 2014.03.03
	char ask_min_ask_prc_amt[21];	// �ŵ��ּ�ȣ���ݾ�, 9(18)V9(3)                           2009.07.27
	char bid_min_ask_prc_amt[21];	// �ż��ּ�ȣ���ݾ�, 9(18)V9(3)                           2009.07.27
	char min_ask_amt[21];	// �ּ�ȣ���ݾ�, 9(18)V9(3) (2015.11.23 �߰�)\nMM(����������)ȣ���� �ּұݾ�\n��LP�ּ�ȣ����������� ��Ÿ������ ���, LP�ּ�ȣ����������� ���� ������ ��� �ش� �ʵ�� ����
	char max_ask_amt[21];	// �ִ�ȣ���ݾ�, 9(18)V9(3) (2015.11.23 �߰�) \n�ִ�ȣ���ݾ�
	char filler[58];	// FILLER, SPACE 2014.03.03\n10 -> 58 2015.11.23
	char ff[1];	// FF, END OF TEXT (0xFF) 120->160 2009.07.27160->250 2015.11.23
} KOSDAQ_LP_INFO;


// �ڽ���_�뷮ü��
typedef struct _KOSDAQ_MSV_CCLS {
	char data_clsf[2];	// DATA����, C4
	char info_clsf[2];	// ��������, 01:�ֽ�
	char mkt_clsf[1];	// ���屸��, 1:�������� 2:�ڽ���
	char isin_code[12];	// �����ڵ�, ǥ���ڵ�
	char stk_snr[5];	// �����Ϸù�ȣ, �����ġ(A0)�� �����Ϸù�ȣ
	char snr[8];	// �Ϸù�ȣ, 1~99999999 �Ǽ�üũ��
	char bopen_rel_msv_ccls_qty[9];	// �尳�����ð��ܻ��뷮ü�����, ����:��
	char bopen_bsk_ccls_qty[9];	// �尳�����ð��ܹٽ���ü�����, ����:��
	char bopen_cmpt_msv_ccls_qty[9];	// �尳�����ð��ܰ���뷮ü�����, ����:��
	char rel_msv_ccls_qty[9];	// ���߻��뷮ü�����, ����:��
	char bsk_ccls_qty[9];	// ���߹ٽ���ü�����, ����:��
	char cmpt_msv_ccls_qty[9];	// ���߰���뷮ü�����, ����:��
	char ofhr_rel_msv_ccls_qty[9];	// �������Ľð��ܻ��뷮ü�����, ����:��
	char ofhr_bsk_ccls_qty[9];	// �������Ľð��ܹٽ���ü�����, ����:��
	char filler[7];	// FILLER, SPACE
	char ff[1];	// FF, END OF TEXT (0xFF)
} KOSDAQ_MSV_CCLS;


// �ڽ���_�ֽ�������������
typedef struct _KOSDAQ_STK_INFO_DCLS {
	char data_clsf[2];	// DATA����, A8
	char info_clsf[2];	// ��������, 01:�ֽ�
	char mkt_clsf[1];	// ���屸��, 1:�������� 2:�ڽ���
	char isin_code[12];	// �����ڵ�
	char stk_snr[5];	// �����Ϸù�ȣ, �����ġ(A0)�� �����Ϸù�ȣ
	char open_info_clsf_code[3];	// �������������ڵ�, �� �ڵ尪���� ����
	char brd_id[2];	// ����ID, �� �ڵ尪���� ����
	char base_prc[9];	// ���ذ���
	char ceil_prc[9];	// ���Ѱ�, ������������ ���� ���� '999999999'
	char flr_prc[9];	// ���Ѱ�, ������������ ���� ���� '-99999999'
	char assm_prc[9];	// �򰡰���
	char best_ask_prc[9];	// �ְ�ȣ������
	char least_ask_prc[9];	// ����ȣ������
	char mkt_base_prc_flg[1];	// �ð����ذ��ݿ���, Y, N
	char lock_clsf_code[2];	// �������ڵ�, 00:�ش���׾��� 01:�Ǹ��� 02:���� 03:�й�� 04:�ǹ�� 05:�߰�(�б�)���� 06:�Ǹ��߰����� 07:�Ǹ��б���� 99:��Ÿ
	char pval_chg_clsf_code[2];	// �׸鰡���汸���ڵ�, 00:�ش���� 01:�׸���� 02:�׸麴�� 03:�ֽĺ��� 04:�ֽĺ��� 99:��Ÿ
	char trd_qty_unit[11];	// �Ÿż�������, 1�ִ���:1 10:10�ִ��� 100:100�ִ��� 1000:1000�ִ���
	char stk_lstd[16];	// �����ֽļ�
	char apnt[1];	// ��������, N:����  Y:����
	char bopen_ofhr_flg[1];	// �尳�����ð����������ɿ���, N:�ش���� Y:����
	char filler[4];	// FILLER, SPACE
	char ff[1];	// FF, END OF TEXT (0xFF)
} KOSDAQ_STK_INFO_DCLS;


// �ڽ���_ȸ��������������
typedef struct _KOSDAQ_MBR_SCT_CNCL_DCLS {
	char data_clsf[2];	// DATA����, R3
	char info_clsf[2];	// ��������, 01:�ֽ�
	char mkt_clsf[1];	// ���屸��, 1:�������� 2:�ڽ���
	char ind_code[12];	// �����ڵ�, **: �������ش�
	char stk_snr[5];	// �����Ϸù�ȣ, �����ġ(A0)�� �����Ϸù�ȣ
	char open_info_clsf_code[3];	// �������������ڵ�, �� �ڵ尪���� ����
	char open_time[6];	// �����ð�
	char mbr_nr[5];	// ȸ����ȣ
	char mbr_sct_rng_code[5];	// ȸ��������������ڵ�, ȸ���� �ŷ��� ��� �Ǵ� �����ϴ� ����. Bitwise ���� 1: �ŵ�(ǲ�ż�) ��Ź 2: �ŵ�(ǲ�ż�) �ڱ� 4: �ż�(ǲ�ŵ�) ��Ź 8: �ż�(ǲ�ŵ�) �ڱ�
	char filler[8];	// FILLER, SPACE
	char ff[1];	// FF, END OF TEXT (0xFF)
} KOSDAQ_MBR_SCT_CNCL_DCLS;


// �ڽ���_�������ٰ���
typedef struct _KOSDAQ_MKT_OPR_DCLS {
	char data_clsf[2];	// DATA����, M4
	char info_clsf[2];	// ��������, 01:�ֽ�
	char mkt_clsf[1];	// ���屸��, 1:�������� 2:�ڽ���
	char isin_code[12];	// �����ڵ�, �������� �� ��ġ��, ��������(KO)�� ���
	char stk_snr[5];	// �����Ϸù�ȣ, �����ġ(A0)�� �����Ϸù�ȣ
	char brd_id[2];	// ����ID, �� �ڵ尪���� ����
	char brd_evt_id[3];	// �����̺�ƮID, �� �ڵ尪���� ����
	char brd_evt_st[6];	// �����̺�Ʈ���۽ð�
	char brd_evt_code[5];	// �����̺�Ʈ���뱺�ڵ�, �� �ڵ尪���� ����
	char sess_open_cls_id[2];	// ���ǰ��������ڵ�, BS: ���尳�� BE: �������� SS: ���ǰ��� SE: �������� SH: �������� SR: �����簳
	char sess_id[2];	// ����ID, �� �ڵ尪���� ����
	char pbl_stk_code[12];	// ����������ڵ�, ������ġ�� ������ �Ǵ� �����ڵ� *�������� �����ڵ嵵 ���� �� ����
	char trsp_rsn_code[3];	// �ŷ����������ڵ�, �� �ڵ尪���� ���� *��������(KO) �� "  "
	char trsp_trgg_code[1];	// �ŷ������߻������ڵ�, 1:�ڱ����� 2:�����μ������� 3:�����μ������� 4:�����ڻ�ELW 5:����ELW 6:����� 7:�����ڻ�Ҽӽ��� *��������(KO)�� "1"
	char apl_step[2];	// ����ܰ�, CB �� ���������� Ȯ��� ����Ǵ� �ܰ�(�� ���� ���� "00")
	char filler[9];	// FILLER, SPACE
	char ff[1];	// FF, END OF TEXT (0xFF)
} KOSDAQ_MKT_OPR_DCLS;


// �ڽ���_�ڻ��� ��ġ����
typedef struct _KOSDAQ_TRS_STK_ARNG_INFO {
	char data_clsf[2];	// DATA����, A9
	char info_clsf[2];	// ��������, 01:�ֽ�
	char mkt_clsf[1];	// ���屸��, 1:�������� 2:�ڽ���
	char isin_code[12];	// �����ڵ�, ǥ���ڵ�
	char snr[8];	// �Ϸù�ȣ, 1~99999999 �Ǽ�üũ��
	char trs_stk_id[5];	// �ڻ��ֽŰ�ID, 0:�ش���� N:�ڻ��������Ϲ� S:�ڻ�����������ɼ�\n1~99999:�ڻ��ֽ�Ź�Ϸù�ȣ    �ذ� ��������
	char ask_bid_clsf_code[1];	// �ŵ��ż������ڵ�, 0:��Ź 1:�ŵ� 2:�ż�
	char trs_stk_date[8];	// �ڻ��ֽ�û����, YYYYMMDD �ؽŰ��� ��� ��û���ڰ� ����
	char trs_stk_st_date[8];	// �ڻ��ֽŰ�������, YYYYMMDD �Ű����� �ڻ��ָŸ� ��������
	char trs_stk_ed_date[8];	// �ڻ��ֽŰ���������, YYYYMMDD �Ű����� �ڻ��ָŸ� ��������
	char trs_stk_trd_code[1];	// �ڻ��ָŸŹ���ڵ�, 0:�ش���� 1:�ڻ����Ϲ� 2:������ �ڻ��� 3:���ε� �ڻ���\n��2,3 : �������Ľð��ܴ뷮�ż��� ����, ���ϰŷ�(�ŸŰŷ���\n        ����)���� ���\n        ���Ϲ��ڻ��ִ� �ð��ܴ뷮 �ż��Ұ�(�ŵ��� ����)\n��3 : �������Ľð��ܴ뷮�ż��� ��/���Ѱ� ���Ѿ���
	char trs_stk_ptcp_nr[5];	// "�ڻ��ֽ�û���������� ��ȣ", ȸ����ȣ ��) '00001'
	char open_trs_stk_qty[12];	// "�ð����ϰ��ڻ��ֽ�û ����", �Ű�Ⱓ���� ��û�� �ð����ϰ� ��û ����
	char opr_time_trs_stk_qty[12];	// �����ڻ��ֽ�û����, �Ű�Ⱓ���� ��û�� ���� ��û ����
	char ofhr_msv_trs_stk_qty[12];	// "�ð��ܴ뷮�ڻ��� ��û����", �ð���(����, ����)������ �ڻ��� �Ű����
	char trs_stk_cum_ccls_qty[12];	// �ڻ��ִ���ü�����, �Ű�Ⱓ���� ������, �ð��ܽ��忡�� �ڻ��� ü����� ����
	char trs_stk_cum_trd_val[18];	// �ڻ��ִ����ŷ����, �Ű�Ⱓ���� ������, �ð��ܽ��忡�� �ڻ��� �ŷ���� ����
	char filler[2];	// FILLER, SPACE
	char ff[1];	// FF, END OF TEXT (0xFF)
} KOSDAQ_TRS_STK_ARNG_INFO;


// �ڽ���_�ڻ��� �Ÿ�����
typedef struct _KOSDAQ_TRS_STK_TRD_INFO {
	char data_clsf[2];	// DATA����, B0
	char info_clsf[2];	// ��������, 01:�ֽ�
	char mkt_clsf[1];	// ���屸��, 1:�������� 2:�ڽ���
	char isin_code[12];	// �����ڵ�, ǥ���ڵ�
	char snr[8];	// �Ϸù�ȣ, 1~99999999 �����Ϸù�ȣ 2014.03.03
	char ccls_prc[9];	// ü�ᰡ��, ����:��
	char ccls_qty[10];	// ü�����, ����:��
	char sess_id[2];	// ����ID, �ڵ尪���� ����
	char bid_trs_stk_id[5];	// �ż��ڻ��ֽŰ�ID, 0:�ش���� N:�ڻ��������Ϲ� S:�ڻ���������Ź�ɼ�\n1~99999:�ڻ��ֽ�Ź(�Ű��Ϸù�ȣ)\n�ذ��� ��������  ��) "N", "1"\n���ڻ��ֽ�Ź�Ϸù�ȣ�� ���񺰷� ���������� ���� ä����\n  ������ ���� ��Ź�� �Ϸù�ȣ�� �����ϴ� ������ ����\n  ���� ���ؼ� ���� ��Źȸ�翡�� �ڻ��ָ� �Ű��� ��\n  �ֵ��� ����ϱ� ������
	char ask_trs_stk_id[5];	// �ŵ��ڻ��ֽŰ�ID, �ż��ڻ��ֽŰ�ID�� ����
	char filler[3];	// FILLER, SPACE 1->3 2014.03.03
	char ff[1];	// FF, END OF TEXT (0xFF)
} KOSDAQ_TRS_STK_TRD_INFO;


// �ڽ���_�ü�RECOVERY
typedef struct _KOSDAQ_MKT_PRC_RCVR {
	char data_clsf[2];	// DATA����, B1:���� B2:�ü�REC
	char info_clsf[2];	// ��������, 01:�ֽ� 02:ELW
	char mkt_clsf[1];	// ���屸��, 1:�������� 2:�ڽ���
	char isin_code[12];	// �����ڵ�, ǥ���ڵ�
	char stk_snr[5];	// �����Ϸù�ȣ, �����ġ(A0)�� �����Ϸù�ȣ
	char flct_clsf[1];	// �������, 0:�ǴܺҰ� 1:���� 2:��� 3:���� 4:���� 5:�϶�
	char prev_ctrs[9];	// ���ϴ��, ����:��
	char cur_prc[9];	// ���簡
	char open[9];	// �ð�, ������ �ð�
	char hi[9];	// ��, ������ ��
	char low[9];	// ����, ������ ����
	char ask_prc[9];	// �ŵ�ȣ��, B1�� 0�� SET
	char bid_prc[9];	// �ż�ȣ��, B1�� 0�� SET
	char cum_ccls_qty[12];	// ����ü�����, ����:�� �ؽð��ܴ��ϰ�, BUY-IN�� ������ ��� ü����� �ջ�
	char cum_trd_val[18];	// �����ŷ����, ����:�� �ؽð��ܴ��ϰ�, BUY-IN�� ������ ��� �ŷ���� �ջ�
	char trend_flg[1];	// �Ǽ�/�⼼ ����, 0:�ʱⰪ 1:�Ǽ� 2:�⼼ 3:�ŷ��� 4:�ð����ذ������� �⼼
	char brd_evt_id[3];	// �����̺�ƮID, B1/B2 ������ �����̺�ƮID ������(���� ���°��� ���۵� �� ����). ����, �ش� �׸� '000' ���� ����. 2014.03.24)
	char brd_id[2];	// ����ID, �� �ڵ尪���� ����
	char trsp_flg[1];	// �ŷ���������, Y, N
	char bopen_ofhr_ccls_qty[12];	// �尳�����ð�������ü�����, �뷮, �ٽ����� ����, ����:��
	char bopen_ofhr_trd_val[18];	// �尳�����ð��������ŷ����, �뷮, �ٽ����� ����, ����:��
	char opr_time_ccls_qty[12];	// ������ü�����, �뷮, �ٽ����� ����, ����:��
	char opr_time_trd_val[18];	// ������ŷ����, �뷮, �ٽ����� ����, ����:��
	char ofhr_cls_ccls_qty[12];	// �������Ľð�������ü�����, �뷮, �ٽ����� ����, ����:��
	char ofhr_cls_trd_val[18];	// �������Ľð��������ŷ����, �뷮, �ٽ����� ����, ����:��
	char elw_ely_cls_flg[1];	// ELW�������Ῡ��, Y,N ��������ELW �� ������ Default 'N' SET
	char elw_ely_cls_time[6];	// ELW��������ð�, HHMMSS, ELW�������Ῡ�ΰ� 'Y'�� ��츸 ����
	char cmpt_msv_dir_clsf[1];	// ����뷮 ���ⱸ��, 0:�ش����, 1:�ŵ�, 2:�ż�
	char gen_bin_ccls_qty[12];	// �Ϲ� Buy-in ü�����, ����:��
	char gen_bin_ccls_trd_val[18];	// �Ϲ� Buy-in �ŷ����, ����:��
	char day_bin_ccls_qty[12];	// ���� Buy-in ü�����, ����:��
	char day_bin_ccls_trd_val[18];	// ���� Buy-in �ŷ����, ����:��
	char filler[8];	// FILLER, SPACE
	char ff[1];	// FF, END OF TEXT (0xFF)
} KOSDAQ_MKT_PRC_RCVR;


// �ڽ���_�ð��ܴ��ϰ�_��Ŀ����_����
typedef struct _KOSDAQ_OFH_RCVR_FINAL {
	char data_clsf[2];	// DATA����, B3:�ð��ܴ��ϰ����� B4:�ð��ܴ��ϰ�REC
	char info_clsf[2];	// ��������, 01:�ֽ�
	char mkt_clsf[1];	// ���屸��, 1:�������� 2:�ڽ���
	char isin_code[12];	// �����ڵ�, ǥ���ڵ�
	char stk_snr[5];	// �����Ϸù�ȣ, �����ġ(A0)�� �����Ϸù�ȣ
	char ofhr_cnst_clsf[1];	// �ð��ܴ��ϰ��������, 0:�ǴܺҰ� 1:���� 2:��� 3:���� 4:���� 5:�϶�
	char ofhr_cnst[9];	// �ð��ܴ��ϰ����, ����:��
	char ofhr_cnst_ceil[9];	// �ð��ܴ��ϰ����Ѱ�
	char ofhr_cnst_flr[9];	// �ð��ܴ��ϰ����Ѱ�
	char ofhr_cnst_cur[9];	// �ð��ܴ��ϰ����簡
	char ofhr_cnst_open[9];	// �ð��ܴ��ϰ��ð�
	char ofhr_cnst_hi[9];	// �ð��ܴ��ϰ���
	char ofhr_cnst_lo[9];	// �ð��ܴ��ϰ�����
	char ofhr_cnst_ask[9];	// �ð��ܴ��ϰ��ŵ�ȣ��, B3�� 0�� SET
	char ofhr_cnst_bid[9];	// �ð��ܴ��ϰ��ż�ȣ��, B3�� 0�� SET
	char ofhr_cnst_cum_ccls_qty[12];	// �ð��ܴ��ϰ�����ü�����
	char ofhr_cnst_cum_trd_val[18];	// �ð��ܴ��ϰ������ŷ����
	char tot_cum_ccls_qty[12];	// ��ü �� ����ü�����
	char tot_cum_trd_val[18];	// ��ü �� �����ŷ����
	char ofhr_mkt_clsf[1];	// �ð��ܴ��ϰ��屸��, 0:�ʱⰪ 1:�ð��ܴ��ϰ����� 2:�ð��ܴ��ϰ�����
	char trsp_flg[1];	// �ŷ���������, Y, N
	char trend_flg[1];	// �Ǽ�/�⼼ ����, 0:�ʱⰪ 1:�Ǽ� 2:�⼼ 3:�ŷ��� 4:�ð����ذ������� �⼼
	char filler[2];	// FILLER, SPACE
	char ff[1];	// FF, END OF TEXT (0xFF)
} KOSDAQ_OFH_RCVR_FINAL;


// �ڽ���_�ð��ܴ��ϰ�_��Ŀ����
typedef struct _KOSDAQ_OFH_RCVR {
	char data_clsf[2];	// DATA����, B3:�ð��ܴ��ϰ����� B4:�ð��ܴ��ϰ�REC
	char info_clsf[2];	// ��������, 01:�ֽ�
	char mkt_clsf[1];	// ���屸��, 1:�������� 2:�ڽ���
	char isin_code[12];	// �����ڵ�, ǥ���ڵ�
	char stk_snr[5];	// �����Ϸù�ȣ, �����ġ(A0)�� �����Ϸù�ȣ
	char ofhr_cnst_clsf[1];	// �ð��ܴ��ϰ��������, 0:�ǴܺҰ� 1:���� 2:��� 3:���� 4:���� 5:�϶�
	char ofhr_cnst[9];	// �ð��ܴ��ϰ����, ����:��
	char ofhr_cnst_ceil[9];	// �ð��ܴ��ϰ����Ѱ�
	char ofhr_cnst_flr[9];	// �ð��ܴ��ϰ����Ѱ�
	char ofhr_cnst_cur[9];	// �ð��ܴ��ϰ����簡
	char ofhr_cnst_open[9];	// �ð��ܴ��ϰ��ð�
	char ofhr_cnst_hi[9];	// �ð��ܴ��ϰ���
	char ofhr_cnst_lo[9];	// �ð��ܴ��ϰ�����
	char ofhr_cnst_ask[9];	// �ð��ܴ��ϰ��ŵ�ȣ��, B3�� 0�� SET
	char ofhr_cnst_bid[9];	// �ð��ܴ��ϰ��ż�ȣ��, B3�� 0�� SET
	char ofhr_cnst_cum_ccls_qty[12];	// �ð��ܴ��ϰ�����ü�����
	char ofhr_cnst_cum_trd_val[18];	// �ð��ܴ��ϰ������ŷ����
	char tot_cum_ccls_qty[12];	// ��ü �� ����ü�����
	char tot_cum_trd_val[18];	// ��ü �� �����ŷ����
	char ofhr_mkt_clsf[1];	// �ð��ܴ��ϰ��屸��, 0:�ʱⰪ 1:�ð��ܴ��ϰ����� 2:�ð��ܴ��ϰ�����
	char trsp_flg[1];	// �ŷ���������, Y, N
	char trend_flg[1];	// �Ǽ�/�⼼ ����, 0:�ʱⰪ 1:�Ǽ� 2:�⼼ 3:�ŷ��� 4:�ð����ذ������� �⼼
	char filler[2];	// FILLER, SPACE
	char ff[1];	// FF, END OF TEXT (0xFF)
} KOSDAQ_OFH_RCVR;


// �ڽ���_������
typedef struct _KOSDAQ_CUR_FLCT {
	char data_clsf[2];	// DATA����, B5
	char info_clsf[2];	// ��������, 01:�ֽ�
	char mkt_clsf[1];	// ���屸��, 1:�������� 2:�ڽ���
	char tot_stk_nr[5];	// ��ü �����
	char trd_form_stk_nr[5];	// �ŷ����� �����
	char ceil_stk_nr[5];	// ���� �����
	char rise_stk_nr[5];	// ��� �����
	char stdstl_stk_nr[5];	// ���� �����
	char flr_stk_nr[5];	// ���� �����
	char fall_stk_nr[5];	// �϶� �����
	char trend_stk_nr[5];	// �⼼ �����
	char trend_rise_stk_nr[5];	// �⼼��� �����
	char trend_fall_stk_nr[5];	// �⼼�϶� �����
	char filler[4];	// FILLER, SPACE
	char ff[1];	// FF, END OF TEXT (0xFF)
} KOSDAQ_CUR_FLCT;


// �ڽ���_Buy-in_�������
typedef struct _KOSDAQ_BIN_EXCQ {
	char data_clsf[2];	// DATA����, O4
	char info_clsf[2];	// ��������, 01:�ֽ�
	char mkt_clsf[1];	// ���屸��, 1:��������, 2:�ڽ���, 8:�ڳؽ�
	char isin_code[12];	// �����ڵ�, ǥ���ڵ� �Ǵ� "999999999999" ���߰��̵� ����
	char snr[8];	// �Ϸù�ȣ, �� Buy-in�����ڵ庰�� �Ϸù�ȣ ����
	char trsm_date[8];	// ��������, YYYYMMDD
	char bin_clsf_code[1];	// Buy-in�����ڵ�, 1: �Ϲ� Buy-in, 2: ���� Buy-in
	char scrt_grp_id[2];	// ���Ǳ׷�ID, ST:�ֽ�, MF:��������ȸ��, RT:����, SC:��������ȸ��,\nIF:������������ȸ��, DR:��Ź����, SW:�����μ�������,\nSR:�����μ�������, EW:�ֽĿ���Ʈ����, EF:���������ݵ�,\nBC:��������, FE:�ؿ�ETF, FS:�ؿܿ���\nEN:ETN(2014.11.17)
	char bin_exc_qty[15];	// Buy-in �������
	char filler[8];	// FILLER
	char ff[1];	// FF, END OF TEXT (0xFF)
} KOSDAQ_BIN_EXCQ;


// �ڽ��� ������ �����ͷ�
typedef struct _KOSDAQ_BYIND_DYR {
	char data_clsf[2];	// DATA����, P2
	char info_clsf[2];	// ��������, 01:�ֽ�
	char mkt_clsf[1];	// ���屸��, 1:�������� 2:�ڽ���
	char idx_ind_code[3];	// ���������ڵ�, ���ڵ尪���� ����
	char dyr[7];	// �����ͷ�, 99999v99
	char ff[1];	// FF, END OF TEXT (0xFF)
} KOSDAQ_BYIND_DYR;


// �ڽ���_�尳����_ȣ���ܷ�
typedef struct _KOSDAQ_BOPEN_ASK_RSD {
	char data_clsf[2];	// DATA����, B8
	char info_clsf[2];	// ��������, 01:�ֽ�
	char mkt_clsf[1];	// ���屸��, 1:�������� 2:�ڽ���
	char isin_code[12];	// �����ڵ�, ǥ���ڵ�
	char stk_snr[5];	// �����Ϸù�ȣ, �����ġ(A0)�� �����Ϸù�ȣ
	char cum_ccls_qty[12];	// ����ü�����
	char tot_ask_rsd[12];	// �Ѹŵ�ȣ���ܷ�
	char tot_bid_rsd[12];	// �Ѹż�ȣ���ܷ�
	char filler[1];	// FILLER, SPACE
	char ff[1];	// FF, END OF TEXT (0xFF)
} KOSDAQ_BOPEN_ASK_RSD;


// �ڽ���_ȣ���ܷ�_LPȣ��_����
typedef struct _KOSDAQ_ASK_RSD_WOLP {
	char data_clsf[2];	// DATA����, B6
	char info_clsf[2];	// ��������, 01:�ֽ�
	char mkt_clsf[1];	// ���屸��, 1:�������� 2:�ڽ���
	char isin_code[12];	// �����ڵ�, ǥ���ڵ�
	char stk_snr[5];	// �����Ϸù�ȣ, �����ġ(A0)�� �����Ϸù�ȣ
	char cum_ccls_qty[12];	// ����ü�����
	STOCK_LOB_INFO lob_infos[10];	// ȣ��
	char ask_10_tot_rsd[12];	// 10�ܰ�ȣ���ŵ����ܷ�
	char bid_10_tot_rsd[12];	// 10�ܰ�ȣ���ż����ܷ�
	char filler1[12];	// FILLER
	char filler2[12];	// FILLER
	char ofhr_ask_tot_rsd[12];	// �������Ľð��ܸŵ���ȣ���ܷ�, ����ID "G3"�϶� ���� ������
	char ofhr_bid_tot_rsd[12];	// �������Ľð��ܸż���ȣ���ܷ�, ����ID "G3"�϶� ���� ������
	char sess_id[2];	// ����ID, �� �ڵ尪���� ����
	char brd_id[2];	// ����ID, �� �ڵ尪���� ����
	char exp_ccls_prc[9];	// ����ü�ᰡ��
	char exp_ccls_qty[12];	// ����ü�����
	char cmpt_msv_dir_clsf[1];	// ����뷮 ���ⱸ��, 0:�ش����, 1:�ŵ�, 2:�ż�
	char filler3[7];	// FILLER, SPACE
	char ff[1];	// FF, END OF TEXT (0xFF)
} KOSDAQ_ASK_RSD_WOLP;


// �ڽ���_���ŵ�
typedef struct _KOSDAQ_SHORT {
	char data_clsf[2];	// DATA����, I8
	char info_clsf[2];	// ��������, 01:�ֽ�
	char mkt_clsf[1];	// ���屸��, 1:�������� 2:�ڽ���
	char isin_code[12];	// �����ڵ�, ǥ���ڵ�
	char snr[8];	// �Ϸù�ȣ, 1~99999999 �����Ϸù�ȣ
	char short_brwg_ask_ccls_qty[12];	// "���ŵ��������Ǹŵ� ü�����", ����:��
	char short_brwg_ask_trd_val[18];	// "���ŵ��������Ǹŵ� �ŷ����", ����:��
	char filler[4];	// FILLER, SPACE 2->4 2014.03.03
	char ff[1];	// FF, END OF TEXT (0xFF)
} KOSDAQ_SHORT;


// �ڽ���_�ü�����
typedef struct _KOSDAQ_MKT_PRC_CLS {
	char data_clsf[2];	// DATA����, B1:���� B2:�ü�REC
	char info_clsf[2];	// ��������, 01:�ֽ� 02:ELW
	char mkt_clsf[1];	// ���屸��, 1:�������� 2:�ڽ���
	char isin_code[12];	// �����ڵ�, ǥ���ڵ�
	char stk_snr[5];	// �����Ϸù�ȣ, �����ġ(A0)�� �����Ϸù�ȣ
	char flct_clsf[1];	// �������, 0:�ǴܺҰ� 1:���� 2:��� 3:���� 4:���� 5:�϶�
	char prev_ctrs[9];	// ���ϴ��, ����:��
	char cur_prc[9];	// ���簡
	char open[9];	// �ð�, ������ �ð�
	char hi[9];	// ��, ������ ��
	char low[9];	// ����, ������ ����
	char ask_prc[9];	// �ŵ�ȣ��, B1�� 0�� SET
	char bid_prc[9];	// �ż�ȣ��, B1�� 0�� SET
	char cum_ccls_qty[12];	// ����ü�����, ����:�� �ؽð��ܴ��ϰ�, BUY-IN�� ������ ��� ü����� �ջ�
	char cum_trd_val[18];	// �����ŷ����, ����:�� �ؽð��ܴ��ϰ�, BUY-IN�� ������ ��� �ŷ���� �ջ�
	char trend_flg[1];	// �Ǽ�/�⼼ ����, 0:�ʱⰪ 1:�Ǽ� 2:�⼼ 3:�ŷ��� 4:�ð����ذ������� �⼼
	char brd_evt_id[3];	// �����̺�ƮID, B1/B2 ������ �����̺�ƮID ������(���� ���°��� ���۵� �� ����). ����, �ش� �׸� '000' ���� ����. 2014.03.24)
	char brd_id[2];	// ����ID, �� �ڵ尪���� ����
	char trsp_flg[1];	// �ŷ���������, Y, N
	char bopen_ofhr_ccls_qty[12];	// �尳�����ð�������ü�����, �뷮, �ٽ����� ����, ����:��
	char bopen_ofhr_trd_val[18];	// �尳�����ð��������ŷ����, �뷮, �ٽ����� ����, ����:��
	char opr_time_ccls_qty[12];	// ������ü�����, �뷮, �ٽ����� ����, ����:��
	char opr_time_trd_val[18];	// ������ŷ����, �뷮, �ٽ����� ����, ����:��
	char ofhr_cls_ccls_qty[12];	// �������Ľð�������ü�����, �뷮, �ٽ����� ����, ����:��
	char ofhr_cls_trd_val[18];	// �������Ľð��������ŷ����, �뷮, �ٽ����� ����, ����:��
	char elw_ely_cls_flg[1];	// ELW�������Ῡ��, Y,N ��������ELW �� ������ Default 'N' SET
	char elw_ely_cls_time[6];	// ELW��������ð�, HHMMSS, ELW�������Ῡ�ΰ� 'Y'�� ��츸 ����
	char cmpt_msv_dir_clsf[1];	// ����뷮 ���ⱸ��, 0:�ش����, 1:�ŵ�, 2:�ż�
	char gen_bin_ccls_qty[12];	// �Ϲ� Buy-in ü�����, ����:��
	char gen_bin_ccls_trd_val[18];	// �Ϲ� Buy-in �ŷ����, ����:��
	char day_bin_ccls_qty[12];	// ���� Buy-in ü�����, ����:��
	char day_bin_ccls_trd_val[18];	// ���� Buy-in �ŷ����, ����:��
	char filler[8];	// FILLER, SPACE
	char ff[1];	// FF, END OF TEXT (0xFF)
} KOSDAQ_MKT_PRC_CLS;


// �ڽ���_�����������ں�
typedef struct _KOSDAQ_BYIND_BYINV {
	char data_clsf[2];	// DATA����, C0
	char info_clsf[2];	// ��������, 01:�ֽ�
	char mkt_clsf[1];	// ���屸��, 1:�������� 2:�ڽ���
	char cmpt_time[6];	// ����ð�, 90�� �ֱ�
	char inv_code[4];	// �������ڵ�, ���ڵ尪���� ����\n*�ڵ�'7000'�� ����, ������� �׸� 0���� ���� (20181210)
	char ind_code[3];	// �����ڵ�, ���ڵ尪���� ���������ڵ�з� ����\n�������;�ڽ���/�ڽ�����������,�ڽ���200����
	char ask_ccls_qty[12];	// �ŵ�ü�����, ����:��
	char ask_trd_val[18];	// �ŵ��ŷ����, ����:��
	char bid_ccls_qty[12];	// �ż�ü�����, ����:��
	char bid_trd_val[18];	// �ż��ŷ����, ����:��
	char filler[7];	// FILLER, SPACE
	char ff[1];	// FF, END OF TEXT (0xFF)
} KOSDAQ_BYIND_BYINV;


// K-OTC �Ҽ��ǰ��� ������, ������
typedef struct _KOTC_ISCNT_DATE_INFO {
	char iscnt_apnt_date[8];	// �Ҽ��ǰ��� ������, YYYYMMDD
	char iscnt_ed_date[8];	// �Ҽ��ǰ��� ������, YYYYMMDD
} KOTC_ISCNT_DATE_INFO;


// K-OTC �������� ����
typedef struct _KOTC_INV_ATN_INFO {
	char inv_atn_rsn_code[2];	// �������� �����ڵ�, �ذ��߰��̵� ����
	char inv_atn_apnt_date[8];	// �������� ������, YYYYMMDD
} KOTC_INV_ATN_INFO;


// K-OTC �����ġ
typedef struct _KOTC_STK_ARNG {
	char data_clsf[2];	// DATA����, A0
	char info_clsf[2];	// ��������, 01:�ֽ�
	char mkt_clsf[1];	// ���屸��, 3:K-OTC
	char isin_code[12];	// �����ڵ�, ǥ���ڵ�
	char snr[8];	// �Ϸù�ȣ, 1~99999999 �Ǽ�üũ��
	char sh_code[9];	// �����ڵ�, ��������((��)�ֽ� 6��7, ������ SPACE ó��)
	char proc_date[8];	// ó������, �������� (YYYYMMDD)
	char kor_stk_nm[80];	// �ѱ������, SIZE����(40��80) 2016.02.01
	char eng_abrv[40];	// �������, SIZE����(20��40) 2016.02.01
	char eng_stk_nm[80];	// ���������, SIZE����(40��80) 2016.02.01
	char kor_stk_abrv[40];	// �����(�ѱ۾��), SIZE����(20��40) 2016.02.01
	char stk_snr[5];	// �����Ϸù�ȣ
	char stk_clsf[1];	// ���񱸺�, 0:���� 1:�ű� 2:�߰�
	char mdim_biz_flg[1];	// �߼��߰߱������, 4:�߼ұ�� 5:�߰߱�� 6�߼��߰ߺ��ش� 7:��Ȯ��
	char std_type_ind_code[7];	// ǥ�ػ�������ڵ�
	char trd_base_prc[9];	// �Ÿű��ذ�, ��������ְ�, ���߻��� ���Ÿű��ذ��� SET\n�⼼�ô� '�⼼����' SET\nSIZE����(7��9) 2016.02.01
	char prev_cls[9];	// ��������, ����:��, SIZE����(7��9) 2016.02.01
	char prev_wavg_prc[9];	// ���ϰ�������ְ�, ����:��, SIZE����(7��9) 2016.02.01
	char pbct_stk_nr[15];	// �����ֽļ�, ����:��, SIZE����(12��15) 2016.02.01
	char pval[9];	// �׸鰡, ����:��, SIZE����(7��9) 2016.02.01
	char clsg_mth[2];	// ����, MM
	char clsg_clsf[1];	// ��걸��, 0:�����ֺ���(1-4) 5:1�켱�ֺ��� 6:2�켱�ֺ���
	char per[6];	// PER, 9999V99
	char eps[9];	// EPS, ����:��, SIZE����(7��9) 2016.02.01
	char trsp_flg[1];	// �ŷ���������, 0:���� 1:����
	char trsp_rsn[2];	// �ŷ���������, ���ڵ尪���� ����
	char lock_clsf[1];	// ������, 0:���� 1:�Ǹ��� 2:�׸���� 3:�׸麴�� 4:���� 5:����\n6:����
	char rgst_aplc[40];	// ��Ͻ�û��, �׸��(ASIS ������û��), SIZE����(30��40) 2016.02.01
	char trd_open_date[8];	// �ŸŰ�����, YYYYMMDD
	char cncl_clsf[1];	// ��������, �׸�� ����(ASIS ��ұ���)\n0:���� 1:���ֺ��տ� ���� ����2:���� �� �������\n(ASIS 0:���� 1:�ű��ֺ��տ� ���� ��� 2:�������)
	char whyr_hi_prc[9];	// �����ְ�, SIZE����(7��9) 2016.02.01
	char whyr_lo_prc[9];	// ����������, SIZE����(7��9) 2016.02.01
	char whyr_hi_date[4];	// �����ְ���, MMDD
	char whyr_lo_date[4];	// ����������, MMDD
	char yr_cum_qty[17];	// �������ŷ���, SIZE����(14��17) 2016.02.01
	char yr_cum_trd_val[18];	// ������ �ŷ� ���, ����:��, SIZE����(17��18) 2016.02.01
	char pbl_ofr_clsf[1];	// ���𱸺�, 0:�����, 1:����
	char pbl_ofr_prc[9];	// ����, ����:��, SIZE����(7��9) 2016.02.01
	char affl_clsf[1];	// �ҼӺ� ����, 4:��ϱ����,5:���������\n(ASIS 0:�Ϲݱ����, 1:��ó�����)
	char type_rgst_apnt[1];	// ���/��������, -�׸�� ����(ASIS ��������)\n-�� �߰�\n 0:�Ϲ����� 1:�ڽ����̰� 2:���������̰� 3:�ڳؽ��̰�\n (ASIS 0:�Ϲ����� 1:�ڽ����̰� 2:�ŷ����̰�)
	char prev_vlm[14];	// ���ϰŷ���
	char ceil_prc[9];	// ���Ѱ�, SIZE����(7��9) 2016.02.01
	char flr_prc[9];	// ���Ѱ�, SIZE����(7��9) 2016.02.01
	char iscnt[1];	// �Ҽ��ǰ���, 0:���� 1~5:�Ҽ��ǰ��� 1ȸ~5ȸ
	KOTC_ISCNT_DATE_INFO iscnt_dates[5];	// �Ҽ��ǰ�����
	char inv_atn_flg[1];	// �������ǿ���, 0:���� 1:��������
	KOTC_INV_ATN_INFO inv_atn_infos[15];	// ��������
	char filler1[1];	// FILLER, ASIS: ������ó�������
	char mkt_cap_scale[1];	// �ð��ѾױԸ�, ���������ñ��� SPACE\n(0:���� 1:������ 2:������ 3:������)
	char idx_ind_l[2];	// ��������(��), ���������ñ��� SPACE
	char idx_ind_m[2];	// ��������(��), ���������ñ��� SPACE
	char idx_ind_s[3];	// ��������(��), ���������ñ��� SPACE
	char vtr_clsf[1];	// ��ó����, 0:�Ϲݱ��, 1:��ó���
	char trend_clsf[1];	// �⼼����, 0:�Ǽ�,1:�⼼,2:���ŷ�
	char arng_trd_flg[1];	// �����Ÿſ���, 0:����,1:�����Ÿ�
	char filler2[132];	// FILLER, SPACE\nSIZE����(9��132)  2016.02.01
	char ff[1];	// FF, END OF TEXT (0xFF)
} KOTC_STK_ARNG;


// K-OTC ȣ��
typedef struct _KOTC_ASK_PRC {
	char data_clsf[2];	// DATA����, A2
	char info_clsf[2];	// ��������, 01:�ֽ�
	char mkt_clsf[1];	// ���屸��, 3:K-OTC
	char isin_code[12];	// �����ڵ�, ǥ���ڵ�
	char data_snr[8];	// ������ �Ϸù�ȣ, ȣ��, ü��, ������ġ ������ �Ϸù�ȣ
	char proc_clsf[1];	// ó������, 1:���� 2:���� 3:���
	char ask_nr[6];	// ȣ����ȣ, ���� ó���� ȣ����ȣ
	char base_ask_nr[6];	// ��ȣ����ȣ, ����:0, ����/��ҽ� �ش��ȣ�� ��ȣ
	char base_ask_prc[9];	// ��ȣ������, ����:0, ����/��ҽ� ������, SIZE����(7��9) 2016.02.01
	char ask_bid_clsf[1];	// �ŵ�/�ż� ����, 1:�ŵ� 2:�ż�
	char prc[9];	// ����, ����:�ֹ����� ����:��������, SIZE����(7��9) 2016.02.01
	char qty[10];	// ����, ����:�ֹ����� ����/���:������/��� ����
	char acpt_time[6];	// �����ð�
	char ask_tot_rsd[10];	// �ŵ����ܷ�
	char bid_tot_rsd[10];	// �ż����ܷ�
	char ask_prf_prc[9];	// �ŵ��켱ȣ��, SIZE����(7��9) 2016.02.01
	char ask_prf_vol_rsd[10];	// �ŵ��켱ȣ���ܷ�
	char bid_prf_prc[9];	// �ż��켱ȣ��, SIZE����(7��9) 2016.02.01
	char bid_prf_vol_rsd[10];	// �ż��켱ȣ���ܷ�
	char prc_band_vol_rsd[10];	// ���ݴ�ȣ���ܷ�, ����:�ֹ��ܷ� ����:�����ܷ�
	char base_prc_band_vol_rsd[10];	// �����ݴ�ȣ���ܷ�, ����:0, ����/��ҽ� ���ܷ�
	char brkg_nr[3];	// ���ǻ��ȣ, �ŷ����ڵ� ����
	char brch_nm[12];	// ������, SPACE
	char filler[33];	// FILLER, SPACE, SIZE����(1��33) 2016.02.01
	char ff[1];	// FF, END OF TEXT (0xFF)
} KOTC_ASK_PRC;


// K-OTC ü��
typedef struct _KOTC_CCLS {
	char data_clsf[2];	// DATA����, A3
	char info_clsf[2];	// ��������, 01:�ֽ�
	char mkt_clsf[1];	// ���屸��, 3:K-OTC
	char isin_code[12];	// �����ڵ�, ǥ���ڵ�
	char data_snr[8];	// ������ �Ϸù�ȣ, ȣ��, ü��, ������ġ ������ �Ϸù�ȣ
	char ccls_nr[6];	// ü���ȣ, ���� ü���ȣ
	char ccls_prc[9];	// ü�ᰡ, SIZE����(7��9) 2016.02.01
	char ccls_qty[10];	// ü�ᷮ
	char ccls_time[6];	// ü��ð�
	char ask_prc_nr[6];	// �ŵ�ȣ����ȣ, ���� ȣ����ȣ��
	char bid_prc_nr[6];	// �ż�ȣ����ȣ, ���� ȣ����ȣ��
	char open[9];	// ��, SIZE����(7��9) 2016.02.01
	char hi[9];	// ����, SIZE����(7��9) 2016.02.01
	char wavg_prc[9];	// ��������ְ�, SIZE����(7��9) 2016.02.01
	char tot_ccls_cum_qty[12];	// ��üü�ᴩ���ŷ���
	char tot_ccls_cum_trd_val[14];	// ��üü�ᴩ���ŷ����
	char ask_tot_rsd[10];	// �ŵ����ܷ�
	char bid_tot_rsd[10];	// �ż����ܷ�
	char ask_prf_prc[9];	// �ŵ��켱ȣ��, SIZE����(7��9) 2016.02.01
	char ask_prf_vol_rsd[10];	// �ŵ��켱ȣ���ܷ�
	char bid_prf_prc[9];	// �ż��켱ȣ��, SIZE����(7��9) 2016.02.01
	char bid_prf_vol_rsd[10];	// �ż��켱ȣ���ܷ�
	char prev_ctrs_clsf[1];	// ���ϴ�񱸺�, +:��� -:�϶� SPACE:����
	char prev_ctrs[9];	// ���ϴ��, SIZE����(7��9) 2016.02.01
	char ccls_prc_ask_rsd[10];	// ü�ᰡ��ŵ��ܷ�
	char ccls_prc_bid_rsd[10];	// ü�ᰡ��ż��ܷ�
	char filler[40];	// FILLER, SPACE, SIZE����(4��40  2016.02.01
	char ff[1];	// FF, END OF TEXT (0xFF)
} KOTC_CCLS;


// K-OTC ���񸶰�
typedef struct _KOTC_STK_CLSG {
	char data_clsf[2];	// DATA����, A6
	char info_clsf[2];	// ��������, 1
	char mkt_clsf[1];	// ���屸��, 3:K-OTC
	char isin_code[12];	// �����ڵ�, ǥ���ڵ�
	char data_snr[8];	// ������ �Ϸù�ȣ, ȣ��,ü��,�� ������ �Ϸù�ȣ
	char stk_cls_wght_prc[9];	// ���񸶰� ���߰�, SIZE����(7��9) 2016.02.01
	char trend_flg[1];	// �Ǽ�/�⼼����, 0:������հ�,1:�⼼,2:���ŷ�
	char filler[4];	// FILLER, SPACE, SIZE����(6��4) 2016.02.01
	char ff[1];	// FF, END OF TEXT(0xFF)
} KOTC_STK_CLSG;


// K-OTC ��
typedef struct _KOTC_MKT_OPR {
	char data_clsf[2];	// DATA����, A7
	char info_clsf[2];	// ��������, 01:�ֽ�
	char mkt_clsf[1];	// ���屸��, 3:K-OTC
	char isin_code[12];	// �����ڵ�, ǥ���ڵ�
	char data_snr[8];	// ������ �Ϸù�ȣ, ȣ��, ü��, ���� ������ �Ϸù�ȣ
	char clsf[1];	// ����, 1:�ŸŰŷ����� 2:�ŸŰŷ�����������
	char rsn[2];	// ����
	char filler[1];	// FILLER, SPACE
	char ff[1];	// FF, END OF TEXT (0xFF)
} KOTC_MKT_OPR;


// K-OTC ������ġ
typedef struct _KOTC_MKT_ACT {
	char data_clsf[2];	// DATA����, G5
	char info_clsf[2];	// ��������, 01:�ֽ�
	char mkt_clsf[1];	// ���屸��, 3:K-OTC
	char isin_code[12];	// �����ڵ�, ǥ���ڵ�
	char data_kind[2];	// ������ �з�, 01:���ذ� �� �����Ѱ� ���� 02:�ӽ�����\n03:�ӽ������� �簳
	char chg_date[8];	// ������, YYYYMMDD(�����ͺз� 01�� �ƴϸ� "0")
	char chg_time[8];	// ����ð�, HHMMSSMM(�����ͺз� 01�� �ƴϸ� "0")
	char bact_base_prc[9];	// ��ġ�� ���ذ�, ����:��(�����ͺз� 01�� �ƴϸ� "0"), \nSIZE����(7��9)  2016.02.01
	char bact_ceil[9];	// ��ġ�� ���Ѱ�, ����:��(�����ͺз� 01�� �ƴϸ� "0"), \nSIZE����(7��9)  2016.02.01
	char bact_flr[9];	// ��ġ�� ���Ѱ�, ����:��(�����ͺз� 01�� �ƴϸ� "0"), \nSIZE����(7��9)  2016.02.01
	char aact_base_prc[9];	// ��ġ�� ���ذ�, ����:��(�����ͺз� 01�� �ƴϸ� "0"), \nSIZE����(7��9)  2016.02.01
	char aact_ceil[9];	// ��ġ�� ���Ѱ�, ����:��(�����ͺз� 01�� �ƴϸ� "0"), \nSIZE����(7��9)  2016.02.01
	char aact_flr[9];	// ��ġ�� ���Ѱ�, ����:��(�����ͺз� 01�� �ƴϸ� "0"), \nSIZE����(7��9)  2016.02.01
	char filler[10];	// FILLER, SPACE, SIZE����(2��10)  2016.02.01
	char ff[1];	// FF, END OF TEXT (0xFF)
} KOTC_MKT_ACT;


// K-OTC ���� ��ġ/�ǽð�
typedef struct _KOTC_DCLS_ARNG_RT {
	char data_clsf[2];	// DATA����, E9:���ù�ġ F0:���ýǽð�
	char info_clsf[2];	// ��������, 01:�ֽ�
	char mkt_clsf[1];	// ���屸��, 3:K-OTC
	char isin_code[12];	// �����ڵ�, ��������:999999999999
	char dcls_snr[6];	// �����Ϸù�ȣ, 000001~999999\n��������:999999
	char rgst_date[8];	// �������, YYYYMMDD
	char proc_clsf[1];	// ó������, 1:���� 2:���� 3:���
	char rsn[2];	// ����, �ڵ尪���� ����
	char line_nr[2];	// ���ι�ȣ, 00:���� 01~20:���� 99:END
	char dcls_title[75];	// ��������/����
	char filler[8];	// FILLER, SPACE
	char ff[1];	// FF, END OF TEXT (0xFF)
} KOTC_DCLS_ARNG_RT;


// KOSDAQ����
typedef struct _KOSDAQ_IDX {
	char data_clsf[2];	// DATA����, �ذ��߰��̵� ����
	char info_clsf[2];	// ��������, 01:�ֽ�
	char mkt_clsf[1];	// ���屸��, 1:�������� 2:�ڽ���
	char ind_code[3];	// �����ڵ�, �ذ��߰��̵� ����
	char time[6];	// �ð�, �ذ��߰��̵� ����
	char idx[8];	// ����, 9(6)V9(2)
	char sign[1];	// ��ȣ, +:��� "-":�϶� " ":����
	char ctrs[8];	// ���, 999999V99
	char ccls_qty[8];	// ü�����, ����:õ��
	char trd_val[8];	// �ŷ����, ����:�鸸��
	char filler[2];	// FILLER, SPACE
	char ff[1];	// FF, END OF TEXT (0xFF)
} KOSDAQ_IDX;


// KOSDAQ��������
typedef struct _KOSDAQ_EXP_IDX {
	char data_clsf[2];	// DATA����, �ذ��߰��̵� ����
	char info_clsf[2];	// ��������, 01:�ֽ�
	char mkt_clsf[1];	// ���屸��, 1:�������� 2:�ڽ���
	char ind_code[3];	// �����ڵ�, �ذ��߰��̵� ����
	char time[6];	// �ð�, �ذ��߰��̵� ����
	char idx[8];	// ����, 9(6)V9(2)
	char sign[1];	// ��ȣ, +:��� "-":�϶� " ":����
	char ctrs[8];	// ���, 999999V99
	char ccls_qty[8];	// ü�����, ����:õ��
	char trd_val[8];	// �ŷ����, ����:�鸸��
	char filler[2];	// FILLER, SPACE
	char ff[1];	// FF, END OF TEXT (0xFF)
} KOSDAQ_EXP_IDX;


// �ڽ���_�ŷ���
typedef struct _KOSDAQ_TRS {
	char data_clsf[2];	// DATA����, B9
	char info_clsf[2];	// ��������, 01:�ֽ� 02:ELW
	char mkt_clsf[1];	// ���屸��, 1:�������� 2:�ڽ���
	char isin_code[12];	// �����ڵ�, ǥ���ڵ�
	char snr[8];	// �Ϸù�ȣ, 1~99999999 �����Ϸù�ȣ 2014.03.03
	STOCK_SRC_INFO src_infos[5];	// �ŷ������� OCCURS
	char filler[4];	// FILLER, SPACE 2->4 2014.03.03
	char ff[1];	// FF, END OF TEXT (0xFF)
} KOSDAQ_TRS;


// �ڽ���_���������ں� ����
typedef struct _KOSDAQ_BYSTK_BYINV_CLS {
	char data_clsf[2];	// DATA����, C1
	char info_clsf[2];	// ��������, 01:�ֽ� 02:ELW
	char mkt_clsf[1];	// ���屸��, 1:�������� 2:�ڽ���
	char isin_code[12];	// �����ڵ�, ǥ���ڵ�
	char snr[8];	// �Ϸù�ȣ, 1~99999999 �����Ϸù�ȣ 2014.03.03
	STOCK_INV_INFO inv_infos[12];	// ������ OCCURS 12
	char filler[6];	// FILLER, SPACE  8��4   2010.10.11\nSPACE  4��6   2014.03.03
	char ff[1];	// FF, END OF TEXT (0xFF)
} KOSDAQ_BYSTK_BYINV_CLS;


// ���� Polling data
typedef struct _CUR_POLG_DATA {
	char data_clsf[2];	// DATA����, I2
	char info_clsf[2];	// ��������, 00:�ʱⰪ
	char mkt_clsf[1];	// ���屸��, 0:�ʱⰪ
	char time[4];	// �ð�, HHMM
	char ff[1];	// FF, END OF TEXT (0xFF)
} CUR_POLG_DATA;


// �ڽ���_���α׷��Ÿ� ȣ��
typedef struct _KOSDAQ_PRGTRD_ASK {
	char data_clsf[2];	// DATA����, C3
	char info_clsf[2];	// ��������, 01:�ֽ�
	char mkt_clsf[1];	// ���屸��, 1:�������� 2:�ڽ���
	char isin_code[12];	// �����ڵ�
	char snr[8];	// �Ϸù�ȣ, 1~99999999 �����Ϸù�ȣ 2014.03.03
	// ���α׷��Ÿ�ȣ���ܷ�, =============================================
	char idx_abtg_ask_rsd[12];	// �������͸ŵ�ȣ���ܷ�
	char idx_abtg_bid_rsd[12];	// �������͸ż�ȣ���ܷ�
	char idx_nabtg_ask_rsd[12];	// ���������͸ŵ�ȣ���ܷ�
	char idx_nabtg_bid_rsd[12];	// ���������͸ż�ȣ���ܷ�
	// ���α׷��Ÿ�ȣ������, =============================================
	char idx_abtg_ask_qty[12];	// �������͸ŵ�ȣ������
	char idx_abtg_bid_qty[12];	// �������͸ż�ȣ������
	char idx_nabtg_ask_qty[12];	// ���������͸ŵ�ȣ������
	char idx_nabtg_bid_qty[12];	// ���������͸ż�ȣ������
	// ���α׷��Ÿ� �������ÿ��ܷ�
	char prior_idx_abtg_ask_rsd[12];	// �������͸ŵ�ȣ���ܷ�
	char prior_idx_abtg_bid_rsd[12];	// �������͸ż�ȣ���ܷ�
	char prior_idx_nabtg_ask_rsd[12];	// ���������͸ŵ�ȣ���ܷ�
	char prior_idx_nabtg_bid_rsd[12];	// ���������͸ż�ȣ���ܷ�
	// ���α׷��Ÿ�ü�᳻��, =============================================
	char idx_abtg_ask_ccls_qty[12];	// "�������͸ŵ���Ź ü�����"
	char idx_abtg_ask_self_ccls_qty[12];	// "�������͸ŵ��ڱ� ü�����"
	char idx_abtg_bid_ccls_qty[12];	// "�������͸ż���Ź ü�����"
	char idx_abtg_bid_self_ccls_qty[12];	// "�������͸ż��ڱ� ü�����"
	char idx_nabtg_ask_ccls_qty[12];	// "���������͸ŵ���Ź ü�����"
	char idx_nabtg_ask_self_ccls_qty[12];	// "���������͸ŵ��ڱ� ü�����"
	char idx_nabtg_bid_ccls_qty[12];	// "���������͸ż���Ź ü�����"
	char idx_nabtg_bid_self_ccls_qty[12];	// "���������͸ż��ڱ� ü�����"
	char idx_abtg_ask_ccls_val[18];	// "�������͸ŵ���Ź ü��ݾ�"
	char idx_abtg_ask_self_ccls_val[18];	// "�������͸ŵ��ڱ� ü��ݾ�"
	char idx_abtg_bid_ccls_val[18];	// "�������͸ż���Ź ü��ݾ�"
	char idx_abtg_bid_self_ccls_val[18];	// "�������͸ż��ڱ� ü��ݾ�"
	char idx_nabtg_ask_ccls_val[18];	// "���������͸ŵ���Ź ü��ݾ�"
	char idx_nabtg_ask_self_ccls_val[18];	// "���������͸ŵ��ڱ� ü��ݾ�"
	char idx_nabtg_bid_ccls_val[18];	// "���������͸ż���Ź ü��ݾ�"
	char idx_nabtg_bid_self_ccls_val[18];	// "���������͸ż��ڱ� ü��ݾ�"
	// ���α׷��Ÿ� ���İ��ÿ��ܷ�", =============================================
	char post_idx_abtg_ask_rsd[12];	// �������͸ŵ�ȣ���ܷ�, 2011.05.30 �ű�
	char post_idx_abtg_bid_rsd[12];	// �������͸ż�ȣ���ܷ�, 2011.05.30 �ű�
	char post_idx_nabtg_ask_rsd[12];	// ���������͸ŵ�ȣ���ܷ�, 2011.05.30 �ű�
	char post_idx_nabtg_bid_rsd[12];	// ���������͸ż�ȣ���ܷ�, 2011.05.30 �ű�
	char filler[2];	// FILLER, SPACE  8��10    2011.05.30  ����\nSPACE  10��2    2014.03.03  ����
	char ff[1];	// FF, END OF TEXT (0xFF)  410��460  2011.05.30  ����
} KOSDAQ_PRGTRD_ASK;


// �ڽ���_���α׷��Ÿ� ��ü����
typedef struct _KOSDAQ_PRGTRD_TOT {
	char data_clsf[2];	// DATA����, J0
	char info_clsf[2];	// ��������, 01:�ֽ�
	char mkt_clsf[1];	// ���屸��, 1:�������� 2:�ڽ���
	// ���α׷��Ÿ�ȣ���ܷ�
	char idx_abtg_ask_rsd[12];	// �������͸ŵ�ȣ���ܷ�
	char idx_abtg_bid_rsd[12];	// �������͸ż�ȣ���ܷ�
	char idx_nabtg_ask_rsd[12];	// ���������͸ŵ�ȣ���ܷ�
	char idx_nabtg_bid_rsd[12];	// ���������͸ż�ȣ���ܷ�
	// ���α׷��Ÿ�ȣ������
	char idx_abtg_ask_qty[12];	// �������͸ŵ�ȣ������
	char idx_abtg_bid_qty[12];	// �������͸ż�ȣ������
	char idx_nabtg_ask_qty[12];	// ���������͸ŵ�ȣ������
	char idx_nabtg_bid_qty[12];	// ���������͸ż�ȣ������
	// ���α׷��Ÿ� �������ÿ��ܷ�
	char prior_idx_abtg_ask_rsd[12];	// �������͸ŵ�ȣ���ܷ�
	char prior_idx_abtg_bid_rsd[12];	// �������͸ż�ȣ���ܷ�
	char prior_idx_nabtg_ask_rsd[12];	// ���������͸ŵ�ȣ���ܷ�
	char prior_idx_nabtg_bid_rsd[12];	// ���������͸ż�ȣ���ܷ�
	// ���α׷��Ÿ�ü�᳻��
	char idx_abtg_ask_ccls_qty[12];	// "�������͸ŵ���Ź ü�����"
	char idx_abtg_ask_self_ccls_qty[12];	// "�������͸ŵ��ڱ� ü�����"
	char idx_abtg_bid_ccls_qty[12];	// "�������͸ż���Ź ü�����"
	char idx_abtg_bid_self_ccls_qty[12];	// "�������͸ż��ڱ� ü�����"
	char idx_nabtg_ask_ccls_qty[12];	// "���������͸ŵ���Ź ü�����"
	char idx_nabtg_ask_self_ccls_qty[12];	// "���������͸ŵ��ڱ� ü�����"
	char idx_nabtg_bid_ccls_qty[12];	// "���������͸ż���Ź ü�����"
	char idx_nabtg_bid_self_ccls_qty[12];	// "���������͸ż��ڱ� ü�����"
	char idx_abtg_ask_ccls_val[18];	// "�������͸ŵ���Ź ü��ݾ�"
	char idx_abtg_ask_self_ccls_val[18];	// "�������͸ŵ��ڱ� ü��ݾ�"
	char idx_abtg_bid_ccls_val[18];	// "�������͸ż���Ź ü��ݾ�"
	char idx_abtg_bid_self_ccls_val[18];	// "�������͸ż��ڱ� ü��ݾ�"
	char idx_nabtg_ask_ccls_val[18];	// "���������͸ŵ���Ź ü��ݾ�"
	char idx_nabtg_ask_self_ccls_val[18];	// "���������͸ŵ��ڱ� ü��ݾ�"
	char idx_nabtg_bid_ccls_val[18];	// "���������͸ż���Ź ü��ݾ�"
	char idx_nabtg_bid_self_ccls_val[18];	// "���������͸ż��ڱ� ü��ݾ�"
	// ���α׷��Ÿ� ���İ��ÿ��ܷ�
	char post_idx_abtg_ask_rsd[12];	// �������͸ŵ�ȣ���ܷ�
	char post_idx_abtg_bid_rsd[12];	// �������͸ż�ȣ���ܷ�
	char post_idx_nabtg_ask_rsd[12];	// ���������͸ŵ�ȣ���ܷ�
	char post_idx_nabtg_bid_rsd[12];	// ���������͸ż�ȣ���ܷ�
	char filler[2];	// FILLER, 2011.05.30 �ű�
	char ff[1];	// FF, END OF TEXT (0xFF)     390��440 2011.05.30 ����
} KOSDAQ_PRGTRD_TOT;


// �ڽ���_���α׷��Ÿ� �������İ���
typedef struct _KOSDAQ_PRGTRD_DCLS {
	char data_clsf[2];	// DATA����, C5
	char info_clsf[2];	// ��������, 01:�ֽ�
	char mkt_clsf[1];	// ���屸��, 1:�������� 2:�ڽ���
	char isin_code[12];	// �����ڵ�
	char snr[8];	// �Ϸù�ȣ, 1~99999999 �����Ϸù�ȣ 2014.03.03
	char prior_dcls_new_ask_qty[12];	// "�������ýű�ȣ�� �ŵ�����", ���� : ��\n�׸����:�ŵ����û�������->�������ýű�ȣ���ŵ�����
	char prior_dcls_new_bid_qty[12];	// "�������ýű�ȣ�� �ż�����", ���� : ��\n�׸����:�ż����û�������->�������ýű�ȣ���ż�����
	char prior_dcls_sbmt_ask_qty[12];	// "�������ñ�����ȣ�� �ŵ�����", ���� : ��\n�׸����:�ŵ����û�����������->�������ñ�����ȣ���ŵ�����
	char prior_dcls_sbmt_bid_qty[12];	// "�������ñ�����ȣ�� �ż�����", ���� : ��\n�׸����:�ż����û�����������->�������ñ�����ȣ���ż�����
	char post_dcls_ask_qty[12];	// ���İ��øŵ�����, ���� : ��,  �ű�                2011.05.03
	char post_dcls_bid_qty[12];	// ���İ��øż�����, ���� : ��,  �ű�                2011.05.03
	char filler[2];	// FILLER, SPACE  4��10  2011.05.30\nSPACE  10��2  2014.03.03
	char ff[1];	// FF, END OF TEXT (0xFF)  70��100 2011.05.30
} KOSDAQ_PRGTRD_DCLS;


// �ڽ��� ���α׷��Ÿ� �����ں� �Ÿ���Ȳ
typedef struct _KOSDAQ_PRGTRD_BYINV_STAT {
	char data_clsf[2];	// DATA����, P0
	char info_clsf[2];	// ��������, 01:�ֽ�
	char mkt_clsf[1];	// ���屸��, 1:�������� 2:�ڽ���
	char cmpt_time[6];	// ����ð�, 90�� �ֱ�
	char inv_clsf_code[4];	// �����ڱ����ڵ�, ���ڵ尪���� ����\n*�ڵ�'7000'�� ����, ������� �׸� 0���� ���� (20181210)
	char ask_abtg_ccls_qty[12];	// �ŵ�����ü�����
	char ask_abtg_trd_val[18];	// �ŵ����Ͱŷ����
	char ask_nabtg_ccls_qty[12];	// �ŵ�������ü�����
	char ask_nabtg_trd_val[18];	// �ŵ������Ͱŷ����
	char bid_abtg_ccls_qty[12];	// �ż�����ü�����
	char bid_abtg_trd_val[18];	// �ż����Ͱŷ����
	char bid_nabtg_ccls_qty[12];	// �ż�������ü�����
	char bid_nabtg_trd_val[18];	// �ż������Ͱŷ����
	char ff[1];	// FF, END OF TEXT (0xFF)
} KOSDAQ_PRGTRD_BYINV_STAT;


// �ڽ���_�����������(VI)
typedef struct _KOSDAQ_STK_STAT_INFO {
	char data_clsf[2];	// DATA����, R8
	char info_clsf[2];	// ��������, 01:�ֽ�
	char mkt_clsf[1];	// ���屸��, 1:�������� 2:�ڽ���
	char isin_code[12];	// �����ڵ�
	char stk_snr[5];	// �����Ϸù�ȣ, �����ġ(A0)�� �����Ϸù�ȣ
	char brd_id[2];	// ����ID, �� �ڵ尪���� ����
	char trd_ccls_proc_time[9];	// �Ÿ�ü��ó���ð�, �Ÿ�ü��ó���ð�
	char vi_cncl_time[9];	// VI�����ð�
	char vi_aply_clsf_code[1];	// VI���뱸���ڵ�, 1:VI-�ߵ�, 2:VI-����
	char vi_type_code[1];	// VI�����ڵ�, 1:����VI, 2:����VI, 3:����&����VI
	char stt_vi_base_prc[9];	// ����VI�ߵ����ذ���
	char dyn_vi_base_prc[9];	// ����VI�ߵ����ذ���
	char vi_prc[9];	// VI�ߵ�����
	char stt_vi_dspr[13];	// ����VI�ߵ�������, ����VI�ߵ� ������\n��ȣ�ڸ�(���:0, ����:-) + 99999.999999(��ȿ���� 12�ڸ�)
	char dyn_vi_dspr[13];	// ����VI�ߵ�������, ����VI�ߵ� ������\n��ȣ�ڸ�(���:0, ����:-) + 99999.999999(��ȿ���� 12�ڸ�)
	char filler[2];	// FILLER, SPACE
	char ff[1];	// FF, END OF TEXT (0xFF)
} KOSDAQ_STK_STAT_INFO;
