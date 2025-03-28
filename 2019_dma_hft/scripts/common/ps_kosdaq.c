// ps_kosdaq.c
// �ڽ����ֽ�
// �ּ��� \n�� ���� ���߿� �̻ڰ� �ٲ����

#include "ps_kosdaq.h"


// �ڽ��� TR��������
int ParseAZ012(const double& timestamp, const char* in_buff, DF_KOSDAQ_TR_EXP_IDX* out) {
	KOSDAQ_TR_EXP_IDX* data = (KOSDAQ_TR_EXP_IDX*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����, �ذ��߰��̵� ����
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������, 01:�ֽ�
	out->mkt_clsf = data->mkt_clsf[0];	//���屸��, 1:�������� 2:�ڽ��� 9:�ؿ��ְ����� 2012.04.30 �߰�
	memcpy(out->ind_clsf, data->ind_clsf, sizeof(data->ind_clsf));	// �����ڵ�, �ذ��߰��̵� ����
	memcpy(out->time, data->time, sizeof(data->time));	// �ð�, �ذ��߰��̵� ����   ���ؿ��ְ������� ��� GMT�ð�
	out->idx = Str2Int(data->idx, sizeof(data->idx));	// ����, 9(6)V9(2)
	out->crst = Str2SignDouble(data->sign, sizeof(data->sign) + sizeof(data->crst), 2);	// ���, 999999V99
	out->ccls_qty = Str2Int(data->ccls_qty, sizeof(data->ccls_qty));	// ü�����, ����:õ��  ���ؿ��ְ������� ��� FILLERó��
	out->trd_val = Str2Int(data->trd_val, sizeof(data->trd_val));	// �ŷ����, ����:�鸸��  ���ؿ��ְ������� ��� FILLERó��

	return 1;
}


// �ڽ��� TR����
int ParseAY012(const double& timestamp, const char* in_buff, DF_KOSDAQ_TR_IDX* out) {
	KOSDAQ_TR_IDX* data = (KOSDAQ_TR_IDX*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����, �ذ��߰��̵� ����
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������, 01:�ֽ�
	out->mkt_clsf = data->mkt_clsf[0];	//���屸��, 1:�������� 2:�ڽ��� 9:�ؿ��ְ����� 2012.04.30 �߰�
	memcpy(out->ind_clsf, data->ind_clsf, sizeof(data->ind_clsf));	// �����ڵ�, �ذ��߰��̵� ����
	memcpy(out->time, data->time, sizeof(data->time));	// �ð�, �ذ��߰��̵� ����   ���ؿ��ְ������� ��� GMT�ð�
	out->idx = Str2Int(data->idx, sizeof(data->idx));	// ����, 9(6)V9(2)
	out->crst = Str2SignDouble(data->sign, sizeof(data->sign) + sizeof(data->crst), 2);	// ���, 999999V99
	out->ccls_qty = Str2Int(data->ccls_qty, sizeof(data->ccls_qty));	// ü�����, ����:õ��  ���ؿ��ְ������� ��� FILLERó��
	out->trd_val = Str2Int(data->trd_val, sizeof(data->trd_val));	// �ŷ����, ����:�鸸��  ���ؿ��ְ������� ��� FILLERó��

	return 1;
}


// �ڽ���_ü��
int ParseA3012(const double& timestamp, const char* in_buff, DF_KOSDAQ_CCLS* out) {
	KOSDAQ_CCLS* data = (KOSDAQ_CCLS*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����, A3
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������, 01:�ֽ� 02:ELW
	out->mkt_clsf = data->mkt_clsf[0];	//���屸��, 1:�������� 2:�ڽ���
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// �����ڵ�, ǥ���ڵ�
	out->stk_snr = Str2Int(data->stk_snr, sizeof(data->stk_snr));	// �����Ϸù�ȣ, �����ġ(A0)�� ����SEQ
	memcpy(out->brd_id, data->brd_id, sizeof(data->brd_id));	// ����ID, �� �ڵ尪���� ����
	out->ctrs_clsf = data->ctrs_clsf[0];	//���ϴ��(���ذ����) ����, 0:�ǴܺҰ� 1:���� 2:��� 3:���� 4:���� 5:�϶� �� ���Խð��ܱ����ڵ� ���� 4�� ��� ���� ���� ��� �� ���Խð��ܱ����ڵ� ���� 7,8�� ��� Buy-in���ذ� ���
	out->prev_ctrs = Str2Int(data->prev_ctrs, sizeof(data->prev_ctrs));	// ���ϴ��, ����:�� �����μ��� ����/������ �ű� ���� ���� : 0
	out->ccls_prc = Str2Int(data->ccls_prc, sizeof(data->ccls_prc));	// ü�ᰡ��, ����:��
	out->ccls_qty = Str2Dbl(data->ccls_qty, sizeof(data->ccls_qty), 0);	// ü�����, ����:��
	memcpy(out->sess_id, data->sess_id, sizeof(data->sess_id));	// ����ID, �� �ڵ尪���� ����
	out->open = Str2Int(data->open, sizeof(data->open));	// �ð�, ����:�� �ذ��߰��̵� ����
	out->hi = Str2Int(data->hi, sizeof(data->hi));	// ��, ����:�� �ذ��߰��̵� ����
	out->low = Str2Int(data->low, sizeof(data->low));	// ����, ����:�� �ذ��߰��̵� ����
	out->cum_ccls_qty = Str2Dbl(data->cum_ccls_qty, sizeof(data->cum_ccls_qty), 0);	// ����ü�����, ����:�� �غ���ID���� ������
	out->cum_trd_val = Str2Dbl(data->cum_trd_val, sizeof(data->cum_trd_val), 0);	// �����ŷ����, ����:�� �غ���ID���� ������
	out->fin_bid_ask_clsf_code = data->fin_bid_ask_clsf_code[0];	//�����ŵ��ż������ڵ�, 1:�ŵ� 2:�ż�
	out->mtc_flg = data->mtc_flg[0];	//ü�ᰡ��1ȣ����ġ����, 0:�ǴܺҰ� 1:��ġ 2:����ġ
	memcpy(out->ccls_time, data->ccls_time, sizeof(data->ccls_time));	// ü��ð�, HHMMSS
	out->lp_hld_qty = Str2Dbl(data->lp_hld_qty, sizeof(data->lp_hld_qty), 0);	// LP��������, LP(ü�����) ������ LP��������
	out->ask_1_prc = Str2Int(data->ask_1_prc, sizeof(data->ask_1_prc));	// �ŵ�1ȣ��, ����:�� �ذ��߰��̵� ����
	out->bid_1_prc = Str2Int(data->bid_1_prc, sizeof(data->bid_1_prc));	// �ż�1ȣ��, ����:�� �ذ��߰��̵� ����

	return 1;
}


// �ڽ���_���ذ�����
int ParseA4012(const double& timestamp, const char* in_buff, DF_KOSDAQ_BASE_PRC_DCS* out) {
	KOSDAQ_BASE_PRC_DCS* data = (KOSDAQ_BASE_PRC_DCS*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����, A4
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������, 01:�ֽ�
	out->mkt_clsf = data->mkt_clsf[0];	//���屸��, 1:�������� 2:�ڽ���
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// �����ڵ�, ǥ���ڵ�
	out->snr = Str2Int(data->snr, sizeof(data->snr));	// �����Ϸù�ȣ, �����ġ(A0)�� ����SEQ
	memcpy(out->brd_id, data->brd_id, sizeof(data->brd_id));	// ����ID, �� �ڵ尪���� ����
	out->base_prc = Str2Int(data->base_prc, sizeof(data->base_prc));	// ���ذ���, ����:��
	out->base_prc_ceil = Str2Int(data->base_prc_ceil, sizeof(data->base_prc_ceil));	// ���ذ��ݻ��Ѱ�, ����:��
	out->base_prc_flr = Str2Int(data->base_prc_flr, sizeof(data->base_prc_flr));	// ���ذ������Ѱ�, ����:��

	return 1;
}


// �ڽ���_���񸶰�
int ParseA6012(const double& timestamp, const char* in_buff, DF_KOSDAQ_STK_CLSG* out) {
	KOSDAQ_STK_CLSG* data = (KOSDAQ_STK_CLSG*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����, A6
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������, 01:�ֽ� 02:ELW
	out->mkt_clsf = data->mkt_clsf[0];	//���屸��, 1:�������� 2:�ڽ���
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// �����ڵ�, ǥ���ڵ�
	out->snr = Str2Int(data->snr, sizeof(data->snr));	// �����Ϸù�ȣ, �����ġ(A0)�� ����SEQ
	memcpy(out->brd_id, data->brd_id, sizeof(data->brd_id));	// ����ID, �� �ڵ尪���� ����
	out->stk_cls_prc = Str2Int(data->stk_cls_prc, sizeof(data->stk_cls_prc));	// ���񸶰�����, ���Խð��ܱ����ڵ尡 1:�������϶��� ���񸶰����ݱ����ڵ尪�� SET ��. �� �ܿ��� SPACE
	out->stk_cls_prc_clsf_code = data->stk_cls_prc_clsf_code[0];	//���񸶰����ݱ����ڵ�, 1 ü�ᰡ�� 2 �⼼ 3 �ŷ��� 4 �ð����ذ������� �⼼, �������� �ƴ� ��� SPACE
	out->ofhr_ceil = Str2Int(data->ofhr_ceil, sizeof(data->ofhr_ceil));	// ���񸶰��ð��ܴ��ϰ����Ѱ�
	out->ofhr_flr = Str2Int(data->ofhr_flr, sizeof(data->ofhr_flr));	// ���񸶰��ð��ܴ��ϰ����Ѱ�
	out->stk_cls_mwprc = Str2Int(data->stk_cls_mwprc, sizeof(data->stk_cls_mwprc));	// ���񸶰���հ����ְ�
	out->dlv_base_prc = Str2Int(data->dlv_base_prc, sizeof(data->dlv_base_prc));	// �����ε����ذ���
	out->dlv_ceil = Str2Int(data->dlv_ceil, sizeof(data->dlv_ceil));	// �����ε����Ѱ�
	out->dlv_flr = Str2Int(data->dlv_flr, sizeof(data->dlv_flr));	// �����ε����Ѱ�

	return 1;
}


// �ڽ���_��TS
int ParseA7012(const double& timestamp, const char* in_buff, DF_KOSDAQ_MKT_OPR_TS* out) {
	KOSDAQ_MKT_OPR_TS* data = (KOSDAQ_MKT_OPR_TS*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����, A7
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������, 01:�ֽ� 02:ELW
	out->mkt_clsf = data->mkt_clsf[0];	//���屸��, 1:�������� 2:�ڽ���
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// �����ڵ�, ǥ���ڵ�
	out->stk_snr = Str2Int(data->stk_snr, sizeof(data->stk_snr));	// �����Ϸù�ȣ, �����ġ(A0)�� �����Ϸù�ȣ
	memcpy(out->brd_id, data->brd_id, sizeof(data->brd_id));	// ����ID, �� �ڵ尪���� ����
	memcpy(out->brd_evt_id, data->brd_evt_id, sizeof(data->brd_evt_id));	// �����̺�ƮID, �� �ڵ尪���� ����
	memcpy(out->brd_evt_st, data->brd_evt_st, sizeof(data->brd_evt_st));	// �����̺�Ʈ���۽ð�
	out->brd_evt_code = Str2Int(data->brd_evt_code, sizeof(data->brd_evt_code));	// �����̺�Ʈ���뱺�ڵ�, �� �ڵ尪���� ����
	memcpy(out->sess_id, data->sess_id, sizeof(data->sess_id));	// ����ID, �� �ڵ尪���� ����
	memcpy(out->trsp_rsn_code, data->trsp_rsn_code, sizeof(data->trsp_rsn_code));	// �ŷ����������ڵ�, �� �ڵ尪���� ����

	return 1;
}


// �ڽ���_�������
int ParseO6012(const double& timestamp, const char* in_buff, DF_KOSDAQ_ALLC_INFO* out) {
	KOSDAQ_ALLC_INFO* data = (KOSDAQ_ALLC_INFO*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����, O6
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������, 01:�ֽ�
	out->mkt_clsf = data->mkt_clsf[0];	//���屸��, 1:��������, 2:�ڽ���,
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// �����ڵ�, ǥ���ڵ�
	out->stk_snr = Str2Int(data->stk_snr, sizeof(data->stk_snr));	// �����Ϸù�ȣ, �����ġ(A0)�� �����Ϸù�ȣ
	memcpy(out->brd_id, data->brd_id, sizeof(data->brd_id));	// ����ID, �� �ڵ尪���� ����
	out->allc_apl_clsf_code = data->allc_apl_clsf_code[0];	//������뱸���ڵ�, 1 ��а��� 2 �������
	out->allc_proc_clsf_code = Str2Int(data->allc_proc_clsf_code, sizeof(data->allc_proc_clsf_code));	// ���ó�������ڵ�, 1 �ż�����,2 �ż�����,3 �ŵ�����,4 �ŵ�����   �� ���ó�������ڵ�� ��а��ÿ��� �����ϰ� ������ ' ' ����
	out->allc_cncl_time = Str2Int(data->allc_cncl_time, sizeof(data->allc_cncl_time));	// ��������ð�, HHMMSS

	return 1;
}


// �ڽ���_�����ġ
int ParseA0012(const double& timestamp, const char* in_buff, DF_KOSDAQ_STK_ARNG* out) {
	KOSDAQ_STK_ARNG* data = (KOSDAQ_STK_ARNG*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����, A0
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������, 01:�ֽ�
	out->mkt_clsf = data->mkt_clsf[0];	//���屸��, 1:�������� 2:�ڽ���
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// �����ڵ�, ǥ���ڵ�
	out->snr = Str2Int(data->snr, sizeof(data->snr));	// �Ϸù�ȣ, 1~99999999 �Ǽ�üũ��
	memcpy(out->sh_code, data->sh_code, sizeof(data->sh_code));	// �����ڵ�, �ֽ�7�ڸ�(DR����) ��������9�ڸ�
	memcpy(out->kor_abbr, data->kor_abbr, sizeof(data->kor_abbr));	// �����ѱ۾��
	memcpy(out->eng_abbr, data->eng_abbr, sizeof(data->eng_abbr));	// ���񿵹����
	memcpy(out->opr_date, data->opr_date, sizeof(data->opr_date));	// ��������, YYYYMMDD
	memcpy(out->info_allc_nr, data->info_allc_nr, sizeof(data->info_allc_nr));	// �����й�׷��ȣ
	memcpy(out->stk_gr_id, data->stk_gr_id, sizeof(data->stk_gr_id));	// ���Ǳ׷�ID, ST:�ֱ� MF:��������ȸ�� RT:�ε�������ȸ�� SC:��������ȸ��\nIF:��ȸ�����ں�������ȸ�� DR:�ֽĿ�Ź���� EW:ELW EF:ETF\nSW:�����μ������� SR:�����μ������� BC:�������� \nFE:�ؿ�ETF FS:�ܱ��ֱ�\nEN:ETN 2014.11.17
	out->unit_trd_ccls_flg = data->unit_trd_ccls_flg[0];	//�����Ÿ�ü�Ῡ��, Y, N (�����忡�� �����ð� ����ü�Ῡ��)
	memcpy(out->lock_clsf_code, data->lock_clsf_code, sizeof(data->lock_clsf_code));	// �������ڵ�, 00:�ش���׾���(���� �߻����� ���) \n01:�Ǹ��� \n02:����\n03:�й�� \n04:�ǹ�� \n05:�߰�(�б�)����\n(2017.11.20 ����:�߰�����->�߰�(�б�)����)\n06:�Ǹ��߰�����\n07:�Ǹ��б����\n(2017.11.20 �߰�)\n99:��Ÿ  ��SW,SR,EW�� ���ش�(���ش��� ��� SPACE)
	memcpy(out->pval_chg_clsf_code, data->pval_chg_clsf_code, sizeof(data->pval_chg_clsf_code));	// �׸鰡���汸���ڵ�, 00:�ش����(�׸鰡������ ������ �� �ִ� ���񱺿� ���� ����\n������ �ǹ�) 01:�׸���� 02:�׸麴�� 03:�ֽĺ��� 04:�ֽĺ��� 99:��Ÿ\n(2012.08.27)
	out->open_base_prc_stk_flg = data->open_base_prc_stk_flg[0];	//�ð����ذ������񿩺�, Y, N ��Y�� ���:�ű�����,�������,������,��Ⱓ�ŷ�����
	memcpy(out->rassm_stk_rsn_code, data->rassm_stk_rsn_code, sizeof(data->rassm_stk_rsn_code));	// ������������ڵ�, 00:�ش����, 01:ȸ�����, 02:�ں�����, 03:��Ⱓ����,\n04:�ʰ��й�, 05:��Ը��� \n06: ȸ������պ�, 99:��Ÿ  \n�����Ǳ׷�ID ST,FS�� �ش�(���ش��� ��� SPACE)\n2011.02.28 ���а� �߰�(04:�ʰ��й�, 05:��Ը���)\n2012.08.27 ���ǿ�������(02:�ֽĺ���->02:�ں�����) \n2017.06.26 ���а� ����(01:������� -> 01:ȸ�����)\n2017.06.26 ���а� �߰�(06:ȸ������պ�)
	out->base_prc_chg_stk_flg = data->base_prc_chg_stk_flg[0];	//���ذ��ݺ������񿩺�, Y, N ��Y�� ���:����,�׸麯��,���� ��
	out->rndn_cls_trgg_cond_code = data->rndn_cls_trgg_cond_code[0];	//��������ߵ������ڵ�, ���ϰ��������� ���������� �ߵ�����.���Ǻιߵ�(2)�ΰ�� ���������Ģ���� �����ϴ� ���ݿ���� �����ϴ��� �Ǵ� �� �ߵ��� ������.\n##�ڵ尪##\n0:�̹ߵ�  1:�ߵ�  2:���Ǻιߵ�(���ݿ���Ǵ�)
	out->mkt_alm_warn_fcst_flg = data->mkt_alm_warn_fcst_flg[0];	//����溸�������, Y, N\n\n2015.06.15 : "����溸���迹����(Y,N)"->"����溸�������(Y,N)" �׸񺯰�
	memcpy(out->mkt_alrm_clsf_code, data->mkt_alrm_clsf_code, sizeof(data->mkt_alrm_clsf_code));	// ����溸�����ڵ�, 00:�ش����(����溸�� ������ �� �ִ� ���� ���ؼ� ������\n�ٰ� ������ �ǹ�) 01:�������� 02:���ڰ�� 03:��������
	out->cogv_hlth_flg = data->cogv_hlth_flg[0];	//���豸���췮����, Y, N ���ڽ��ڸ� �ش�, ST,FS,DR,MF,EF�� �ش�
	out->ifam_flg = data->ifam_flg[0];	//�������񿩺�, Y, N
	out->iscnt_flg = data->iscnt_flg[0];	//�Ҽ��ǰ�����������, Y, N
	out->bdlt_flg = data->bdlt_flg[0];	//��ȸ���忩��, Y, N
	out->trsp_flg = data->trsp_flg[0];	//�ŷ���������, Y, N
	memcpy(out->ind_lclsf_code, data->ind_lclsf_code, sizeof(data->ind_lclsf_code));	// ����������з��ڵ�, (����)000:�����̺з�  ������������ ������� ����\n(�ڽ���)000:�����̺з�/���߾��ݵ� 008~014:�Ϲ� 015:IT\n�����Ǳ׷�ID ST,MF,RT,SC,IF�� �ش�
	memcpy(out->ind_mclsf_code, data->ind_mclsf_code, sizeof(data->ind_mclsf_code));	// ���������ߺз��ڵ�, (����)000:�����̺з�\n(�ڽ���)000:�����̺з� 021~040:�Ϲ� 041~043:IT\n�����Ǳ׷�ID ST,MF,RT,SC,IF�� �ش�
	memcpy(out->ind_sclsf_code, data->ind_sclsf_code, sizeof(data->ind_sclsf_code));	// ���������Һз��ڵ�, (����)000:�����̺з�\n(�ڽ���)000:�����̺з� 050~112:�Ϲ� 151~160:IT\n�����Ǳ׷�ID ST,MF,RT,SC,IF�� �ش�
	memcpy(out->ind_id, data->ind_id, sizeof(data->ind_id));	// ����ID, ����(Type Of Industry)ID 2014.03.03 \n*����Ī:ǥ�ػ���ڵ� \n6�ڸ� ǥ�ػ���ڵ�� ������Ǹ� ������ �� �־� �ؿܻ���Ʈ�� �پ��� �����ڵ� ������ �Ұ��Ͽ� 10�ڸ��� Ȯ��. ���� ǥ�ػ���ڵ�� �״�� 1:1 ���εǾ� ������ 4�ڸ��� �����̽��� ä��\n6->10 2014.03.03
	out->kospi200_str_ind = data->kospi200_str_ind[0];	//KOSPI200���;���, �ش���׾��� (2018.10.22 : �׸񼳸���)
	out->mkt_cap_code = data->mkt_cap_code[0];	//�ð��ѾױԸ��ڵ�, ����(0:���� 1:�� 2:�� 3:��)\n�ڽ���(0:���� 1:KOSDAQ100 2:KOSDAQmid300 3:KOSDAQsmall)\n�����Ǳ׷�ID ST,MF,RT,SC,IF�� �ش�
	out->mnft_ind_flg = data->mnft_ind_flg[0];	//(����)���������� (�ڽ���)�߼ұ������, Y, N\n�����������δ� ST,MF,RT,SC,IF�� �ش�(�����ڵ� 027)\n���߼ұ�����δ� ST,FS,DR,EF�� �ش�
	out->krx100_flg = data->krx100_flg[0];	//KRX100���񿩺�, Y, N
	out->gvnm_idx_stk_flg = data->gvnm_idx_stk_flg[0];	//(����)���豸���������񿩺�(�ڽ���) �ҼӺα����ڵ�, (����) Y, N\n(�ڽ���)�ҼӺα����ڵ� �� ��ó�������  2011.05.02\n  1:�췮�����, 2:��ó�����, 3:�߰߱����, 4:�ż�������,\n  A:�ܱ����, B:����ȸ��, C:SPAC, D:ETF E:��������,\n  F:��������ȯ������, Z:��Ÿ   \n�� A~Z�� �ҼӺ� ����\n2012.09.14 (���������ġ)   "���豸���������񿩺�" 1 Byte FILLER ó��\n(�ڽ��������ġ) "�ҼӺα����ڵ�" ��� ���
	memcpy(out->inst_clsf_code, data->inst_clsf_code, sizeof(data->inst_clsf_code));	// ���ڱⱸ�����ڵ�, 00:�ش���� 01:���ǰ������ڱⱸ 02:�Ļ���ǰ���ڱⱸ\n03:�ε��갣�����ڱⱸ 04:�ǹ��������ڱⱸ\n05:�ܱ�����������ڱⱸ 06:�簣�����ڱⱸ\n07:Ư���������ڱⱸ\n�����Ǳ׷�ID MF,IF,BC�� �ش�(���ش��� ��� SPACE)
	out->idx_stk_flg = data->idx_stk_flg[0];	//(����)KOSPI�������񿩺� (�ڽ���)KOSDAQ�������񿩺�, Y, N\n(����)KOSPI����-> (����)KOSPI�������񿩺�,(�ڽ���)KOSDAQ�������񿩺� 2018.12.10
	out->kospi50_flg = data->kospi50_flg[0];	//(����)KOSPI50����, Y, N
	out->base_prc = Str2Int(data->base_prc, sizeof(data->base_prc));	// ���ذ���
	out->prev_cls_clsf_code = data->prev_cls_clsf_code[0];	//�������������ڵ�, 1:�Ǽ� 2:�⼼ 3:�ŷ��� 4:�ð����ذ������� �⼼
	out->prev_cls_prc = Str2Int(data->prev_cls_prc, sizeof(data->prev_cls_prc));	// ��������
	out->prev_cum_ccls_qty = Str2Dbl(data->prev_cum_ccls_qty, sizeof(data->prev_cum_ccls_qty), 0);	// ���ϴ���ü�����
	out->prev_cum_trd_val = Str2Dbl(data->prev_cum_trd_val, sizeof(data->prev_cum_trd_val), 0);	// ���ϴ����ŷ����
	out->ceil_prc = Str2Int(data->ceil_prc, sizeof(data->ceil_prc));	// ���Ѱ�
	out->flr_prc = Str2Int(data->flr_prc, sizeof(data->flr_prc));	// ���Ѱ�
	out->sub_prc = Str2Int(data->sub_prc, sizeof(data->sub_prc));	// ��밡��, ��ST,FS,DR,MF,RT,SC,IF,ET,FE,BC,EN �� �ش� 2014.11.17
	out->par_val = Str2Dbl(data->par_val, sizeof(data->par_val), 3);	// �׸鰡, 9(9)V9(3) �ܱ��ֱ��� ��� �Ҽ�����°�ڸ����� ǥ������\n�ڽ����� ������ �ּ�ȭ����� ǥ�ô� ������������ ����\n��ST,FS,RT,SC,BC�� �ش�
	out->issue_prc = Str2Int(data->issue_prc, sizeof(data->issue_prc));	// ���డ��, ELW, �����μ������� ����
	memcpy(out->listd_date, data->listd_date, sizeof(data->listd_date));	// ��������, YYYYMMDD
	out->stk_listd = Str2Dbl(data->stk_listd, sizeof(data->stk_listd), 0);	// �����ֽļ�(�������Ǽ�)
	out->arng_trd_flg = data->arng_trd_flg[0];	//�����Ÿſ���, Y, N
	out->eps = Str2Int(data->eps, sizeof(data->eps));	// �ִ������(EPS), ����:�� �����Ǳ׷�ID ST,MF,RT,IF,FS �� �ش�
	out->per = Str2Int(data->per, sizeof(data->per));	// �ְ�������(PER), 9(4)V9(2) �����Ǳ׷�ID ST,MF,RT,IF,FS �� �ش�
	out->eps_cmpt_xclu_flg = data->eps_cmpt_xclu_flg[0];	//�ִ�����ͻ������ܿ���, Y:�������� N:����\n�ذ��� 0, ��������, �����ǰ��� ���� �Ǵ� ���� �� ���
	out->bps = Str2Int(data->bps, sizeof(data->bps));	// �ִ���ڻ갡ġ(BPS), ����:�� �����Ǳ׷�ID ST,MF,RT,IF,FS �� �ش�
	out->pbr = Str2Int(data->pbr, sizeof(data->pbr));	// �ִ���ڻ����(PBR), 9(4)V9(2) �����Ǳ׷�ID ST,MF,RT,IF,FS �� �ش�
	out->bps_cmpt_xclu_flg = data->bps_cmpt_xclu_flg[0];	//"�ִ���ڻ갡ġ���� ���ܿ���", Y:�������� N:����\n�ذ��� 0, ��������, �����ǰ��� ���� �Ǵ� ������ ���
	out->loss_flg = data->loss_flg[0];	//��տ���, Y, N
	out->dps = Str2Int(data->dps, sizeof(data->dps));	// �ִ���ݾ�, �ִ����
	out->dps_cmpt_xclu_flg = data->dps_cmpt_xclu_flg[0];	//"�ִ���ݾ׻������ܿ���", Y:�������� N:����\n�ذ��� 0, ��������, �����ǰ��� ���� �Ǵ� ������ ���
	out->dyr = Str2Int(data->dyr, sizeof(data->dyr));	// ��������, 9(6)V9(1)
	memcpy(out->xist_open_date, data->xist_open_date, sizeof(data->xist_open_date));	// ������������, �����Ǳ׷�ID MF,RT,SC,IF,BC �ش�.
	memcpy(out->xist_cls_date, data->xist_cls_date, sizeof(data->xist_cls_date));	// ������������, �����Ǳ׷�ID MF,RT,SC,IF,BC �ش�. ST,FS,DR�� �켱�ָ� �ش�
	memcpy(out->exc_prd_open_date, data->exc_prd_open_date, sizeof(data->exc_prd_open_date));	// ���Ⱓ��������, �����Ǳ׷�ID SW, EW �� �ش��
	memcpy(out->exc_prd_cls_date, data->exc_prd_cls_date, sizeof(data->exc_prd_cls_date));	// "���Ⱓ�������� (�Ǹ����Ⱓ��������)", �����Ǳ׷�ID SW, EW �� �ش��
	out->elw_wrnt_exc_prc = Str2Dbl(data->elw_wrnt_exc_prc, sizeof(data->elw_wrnt_exc_prc), 3);	// "ELW�����μ�������  ��簡��", 9(9)V9(3) ELW �Ǵ� �����μ��������� ��簡��
	out->euity = Str2Dbl(data->euity, sizeof(data->euity), 3);	// �ں���, 9(18)V9(3) �ؿܿ����� ��� �Ҽ�����°�ڸ����� ǥ������\n�׸鰡*�����ֽļ�, ���ͼҰ��� ���� �κ��� ������\nMF�� �Է°�\n��ST,FS,MF,RT,SC,IF,BC�� �ش�
	out->credit_ordbl_flg = data->credit_ordbl_flg[0];	//�ſ��ֹ����ɿ���, Y, N
	out->limt_prc_cond_clsf_code = Str2Int(data->limt_prc_cond_clsf_code, sizeof(data->limt_prc_cond_clsf_code));	// ������ȣ�����Ǳ����ڵ�, X ->9 ��庯��, 1->5 ���̺���\nȣ���� ü�� �� �ܷ�����, Bitwise ����(*���߰��̵� ����) \n#�ڵ尪# \n1:FAS(Fill And Store) \n2:FOK(Fill Or Kill) \n4:FAK(Fill And Kill) \n*��������(FOK, Fill or Kill):�ֹ����� ��� ���� ü����� ������ ��� �ֹ��� �ڵ� ��ҵǴ� �ֹ� \n*��������(FAS, Fill and Store):�ֹ����� ��� ü�ᰡ�� ������ ü���ϰ� ��ü���ܷ��� ���� ���ߵ��� �ֹ��忡 ü�� ����Ű��, ������ ���� ��ü�� �ֹ��� ��� �ּҵ�
	out->mkt_prc_cond_clsf_code = Str2Int(data->mkt_prc_cond_clsf_code, sizeof(data->mkt_prc_cond_clsf_code));	// ���尡ȣ�����Ǳ����ڵ�, *��
	out->cond_prc_cond_clsf_code = Str2Int(data->cond_prc_cond_clsf_code, sizeof(data->cond_prc_cond_clsf_code));	// ���Ǻ�������ȣ�����Ǳ����ڵ�, *��
	out->fvr_lmt_ord_cond_clsf_code = Str2Int(data->fvr_lmt_ord_cond_clsf_code, sizeof(data->fvr_lmt_ord_cond_clsf_code));	// ������������ȣ�����Ǳ����ڵ�, *��
	out->pfr_lmt_ord_cond_clsf_code = Str2Int(data->pfr_lmt_ord_cond_clsf_code, sizeof(data->pfr_lmt_ord_cond_clsf_code));	// �ֿ켱������ȣ�����Ǳ����ڵ�, *��
	memcpy(out->cap_inc_clsf_code, data->cap_inc_clsf_code, sizeof(data->cap_inc_clsf_code));	// ���ڱ����ڵ�, 00:�ش���� 01:�������� 02:�������� 03:���������� 99:��Ÿ
	out->scrt_clsf_code = data->scrt_clsf_code[0];	//�����ֱǱ����ڵ�, 0:�ش����(������) 1:�����켱�� 2:�����켱�� 9:�����ֱ�(2012.07.23)\n�����Ǳ׷�ID ST���� �ش�\n�ر���Ī:�켱�ֱ����ڵ� 2014.03.03
	out->pbl_scrt_flg = data->pbl_scrt_flg[0];	//�����ֿ���, Y, N ���������Ǹ� �ش�
	out->asmt_prc = Str2Int(data->asmt_prc, sizeof(data->asmt_prc));	// �򰡰���
	out->min_ask_prc = Str2Int(data->min_ask_prc, sizeof(data->min_ask_prc));	// ����ȣ������
	out->max_ask_prc = Str2Int(data->max_ask_prc, sizeof(data->max_ask_prc));	// �ְ�ȣ������
	out->opr_time_trd_qty_unit = Str2Int(data->opr_time_trd_qty_unit, sizeof(data->opr_time_trd_qty_unit));	// ������Ÿż�������, 1�ִ���:1 10:10�ִ��� 100:100�ִ��� 1000:1000�ִ���
	out->ofhr_trd_qty_unit = Str2Int(data->ofhr_trd_qty_unit, sizeof(data->ofhr_trd_qty_unit));	// �ð��ܸŸż�������, 1�ִ���:1 10:10�ִ��� 100:100�ִ��� 1000:1000�ִ���\n��BC,SW,SR,EW�� ����
	out->ritz_code = data->ritz_code[0];	//���������ڵ�, 1:�Ϲݸ��� 2:CRV����
	memcpy(out->obj_scrt_code, data->obj_scrt_code, sizeof(data->obj_scrt_code));	// �����ֱ������ڵ�, ��SW,SR�� �ش�
	memcpy(out->crny_iso_code, data->crny_iso_code, sizeof(data->crny_iso_code));	// ��ȭISO�ڵ�, AUD:ȣ�ִ޷� EUR:���� GBP:�����Ŀ�� HKD:ȫ��޷� ��\n���ڵ尪����-��ȭISO�ڵ� ����
	memcpy(out->nt_code, data->nt_code, sizeof(data->nt_code));	// �����ڵ�, ISO 3166 �ڵ��� 3�ڸ� ���� �غ��� �ڵ�ǥ ����\n����ü ���Ǳ׷�ID�� �ش�
	out->mkt_crt_flg = data->mkt_crt_flg[0];	//�����������ɿ���, Y, N
	out->ofhr_trd_flg = data->ofhr_trd_flg[0];	//�ð��ܸŸŰ��ɿ���, Y, N
	out->preord_cls_flg = data->preord_cls_flg[0];	//"�尳�����ð������� ���ɿ���", Y, N
	out->preord_msv_trd_flg = data->preord_msv_trd_flg[0];	//"�尳�����ð��ܴ뷮 �ŸŰ��� ����", Y, N
	out->preord_bsk_flg = data->preord_bsk_flg[0];	//"�尳�����ð��ܹٽ��� ���� ����", Y, N
	out->fcst_ccls_flg = data->fcst_ccls_flg[0];	//����ü�ᰡ��������, Y, N
	out->short_flg = data->short_flg[0];	//���ŵ����ɿ���, Y, N ���������� �ְų� ���� ���ŵ��� ȣ�����ɿ���
	out->trkg_prf_mtp = Str2SignDouble(data->trkg_prf_mtp_sign, sizeof(data->trkg_prf_mtp_sign) + sizeof(data->trkg_prf_mtp), 6);	// �������������, �����Ǳ׷�ID EF,FE,EN �ش� 2014.11.17\n���׸���� 2014.11.17\n\n9(5)V9(6)  ���� �Ǵ� ���� ���� ��� ETF ���� ���� ���\n��) �������� 2���� ��� '00002000000'   2009.07.27
	out->regulation_apl_flg = data->regulation_apl_flg[0];	//"Regulation S ���� ���񿩺�", Y, N							 2010.02.01
	out->spc_flg = data->spc_flg[0];	//����μ�����ȸ�翩��, Y, N							 2010.03.02
	out->tax_type_code = data->tax_type_code[0];	//���������ڵ�, 0:�ش����, \n1:"���ǰŷ���"->"�����" �ڵ尪�� ����   2016.02.29, \n2:���ҵ漼(�����Ⱓ����), \n3:���ǰŷ���(ȸ����ETF)				2011.05.02\n4:"���ҵ漼(�ؿ��ֽ���������ETF)" �ڵ尪 �߰�   2016.02.29\n(BIG33�� FILLER��)
	out->sbst_prc_rate = Str2Dbl(data->sbst_prc_rate, sizeof(data->sbst_prc_rate), 6);	// ��밡�ݻ�������, 99999V999999 2010.06.28 \n(BIG33�� FILLER��) \n��Exture������ ��밡�� 0�̸� ���������� 0�̾�����, Exture+������ ��밡�� 0�̾ �������� ���� 2014.03.03
	out->inv_xctm_stk_flg = data->inv_xctm_stk_flg[0];	//(�ڽ���)��������ȯ�����񿩺�, (�ڽ���) Y,N �������� �Ǵ� ���������� ��ȭ�� ����� �ִ�\n	  �ν� ����¡�� ��� ���� (2011.05.02 �߰�)\n(BIG33�� FILLER��)
	memcpy(out->dlstg_date, data->dlstg_date, sizeof(data->dlstg_date));	// ������������, YYYYMMDD �����Ǳ׷�ID SR �� �ش�, �ٸ� ���Ǳ׷�ID�� FILLERó��  2011.06.27 �߰�\n(BIG33�� FILLER��)
	out->short_term_oh_clsf_code = data->short_term_oh_clsf_code[0];	//�ܱ�������񱸺��ڵ�, 0: �ش����\n1: ��������\n2: ����\n3: ��������(��������)\n2012.11.05 �߰�
	out->etf_cpy_clsf_code = data->etf_cpy_clsf_code[0];	//ETF������������ڵ�, ETF�� �����ڻ� ������������ڵ� 2013.03.18 �߰�P:�ǹ�����S:�ռ����� A:Active (2015.11.23 �����ڵ��߰�)
	out->kospi200_hi_divd_idx_flg = data->kospi200_hi_divd_idx_flg[0];	//KOSPI200������������, Y,N\n2013.11.18
	out->kospi200_lo_vol_idx_flg = data->kospi200_lo_vol_idx_flg[0];	//KOSPI200����������������, Y,N\n2013.11.18
	memcpy(out->mtr_date, data->mtr_date, sizeof(data->mtr_date));	// ��������, 2014.11.17
	memcpy(out->divd_type_code, data->divd_type_code, sizeof(data->divd_type_code));	// �й�������ڵ�, �й�����¿� ���� �����ڵ� 2014.11.17 \n01:������ \n02:����(��ǥ��ġ �ݿ�) \n03:����(��ǥ��ġ �̹ݿ�) \n04:����(������) \n05:����(��Ÿ)
	memcpy(out->mtr_rdmp_prc_st_date, data->mtr_rdmp_prc_st_date, sizeof(data->mtr_rdmp_prc_st_date));	// �����ȯ���ݰ�����������, 2014.11.17
	memcpy(out->mtr_rdmp_prc_ed_date, data->mtr_rdmp_prc_ed_date, sizeof(data->mtr_rdmp_prc_ed_date));	// �����ȯ���ݰ�����������, 2014.11.17
	out->etp_mcdz_clsf_code = data->etp_mcdz_clsf_code[0];	//ETP��ǰ�����ڵ�, (2015.11.23 �߰�)\n ETP��ǰ�����ڵ�\n ## �ڵ尪 ##\n1. ETF(����ȸ����)\n2. ETF(����������)\n3. ETN\n4. �ս����� ETN\n(2017.03.27:ELS�� ETN->�ս����� ETN)
	out->idx_cmpt_inst_code = data->idx_cmpt_inst_code[0];	//�����������ڵ�, (2015.11.23 �߰�)\n*�ڵ尪���� ����(KRX ����)
	memcpy(out->idx_mkt_clsf_id, data->idx_mkt_clsf_id, sizeof(data->idx_mkt_clsf_id));	// ��������з�ID, (2015.11.23 �߰�)\n *��з�(2)+�ߺз�(2)+�Һз�(2)\n ���� �����Ǵ� �з��� �ڸ��� '00'�� ǥ��\n��,�Һз� ������ ���� �з��� ���� ���� �� �� ����
	memcpy(out->idx_snr, data->idx_snr, sizeof(data->idx_snr));	// �����Ϸù�ȣ, (2015.11.23 �߰�)�����Ϸù�ȣ
	memcpy(out->trkg_idx_lvrg_invs_clsf_code, data->trkg_idx_lvrg_invs_clsf_code, sizeof(data->trkg_idx_lvrg_invs_clsf_code));	// �����������������ι��������ڵ�, (2015.11.23 �߰�)\n## �ڵ尪 ##\n P1:�Ϲ�(1)\n P2:2X ��������(2)\n N1:1X �ι���(-1)\n N2:2X �ι���(-2)
	memcpy(out->ref_idx_lvrg_invs_clsf_code, data->ref_idx_lvrg_invs_clsf_code, sizeof(data->ref_idx_lvrg_invs_clsf_code));	// �����������������ι��������ڵ�, (2015.11.23 �߰�)\n## �ڵ尪 ##\n P1:�Ϲ�(1)\n P2:2X ��������(2)\n N1:1X �ι���(-1)\n N2:2X �ι���(-2)
	memcpy(out->idx_ast_clsf_id1, data->idx_ast_clsf_id1, sizeof(data->idx_ast_clsf_id1));	// �����ڻ�з�ID1, (2015.11.23 �߰�)\n *��з�(2)+�ߺз�(2)+�Һз�(2)\n ���� �����Ǵ� �з��� �ڸ��� '00'�� ǥ��\n��,�Һз� ������ ���� �з��� ���� ���� �� �� ����
	memcpy(out->idx_ast_clsf_id2, data->idx_ast_clsf_id2, sizeof(data->idx_ast_clsf_id2));	// �����ڻ�з�ID2, (2015.11.23 �߰�)\n *��з�(2)+�ߺз�(2)+�Һз�(2)\n ���� �����Ǵ� �з��� �ڸ��� '00'�� ǥ��\n��,�Һз� ������ ���� �з��� ���� ���� �� �� ����
	out->lp_odrbl_flg = data->lp_odrbl_flg[0];	//LP�ֹ����ɿ���, (2015.11.23 �߰�) Y,N
	out->kosdaq150_idx_stk_flg = data->kosdaq150_idx_stk_flg[0];	//KOSDAQ150�������񿩺�, (2015.11.23 �߰�)\nY,N
	out->lo_vol_flg = data->lo_vol_flg[0];	//������������, (2016.06.27 �߰�)\nY,N
	out->abnm_risg_flg = data->abnm_risg_flg[0];	//�̻�޵��, (2017.03.27 �߰�) \nY,N
	out->krx300_idx_flg = data->krx300_idx_flg[0];	//KRX300��������, (2018.03.26 �߰�)\nY,N
	out->qty_ceil = Str2Dbl(data->qty_ceil, sizeof(data->qty_ceil), 0);	// ���Ѽ���, (2018.09.17 �߰�)���Ѽ����� �ʰ��� ȣ���� �ź�ó�� �ʿ�.

	return 1;
}


// �ڽ���_����� ����
int ParseI5012(const double& timestamp, const char* in_buff, DF_KOSDAQ_STGD_INFO* out) {
	KOSDAQ_STGD_INFO* data = (KOSDAQ_STGD_INFO*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����, I5
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������, 01:�ֽ�
	out->mkt_clsf = data->mkt_clsf[0];	//���屸��, 1:�������� 2:�ڽ���
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// �����ڵ�, ǥ���ڵ�
	out->snr = Str2Int(data->snr, sizeof(data->snr));	// �Ϸù�ȣ, 1~99999999 �Ǽ�üũ��
	memcpy(out->clsg_date, data->clsg_date, sizeof(data->clsg_date));	// ������, 1~99999999 �Ǽ�üũ��

	return 1;
}


// �ڽ���_���� �̺�Ʈ ����
int ParseI6012(const double& timestamp, const char* in_buff, DF_KOSDAQ_STK_EVT_INFO* out) {
	KOSDAQ_STK_EVT_INFO* data = (KOSDAQ_STK_EVT_INFO*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����, I6
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������, 01:�ֽ�
	out->mkt_clsf = data->mkt_clsf[0];	//���屸��, 1:�������� 2:�ڽ���
	memcpy(out-> isin_code, data-> isin_code, sizeof(data-> isin_code));	// �����ڵ�, ǥ���ڵ�
	out->snr = Str2Int(data->snr, sizeof(data->snr));	// �Ϸù�ȣ, 1~99999999 �Ǽ�üũ��
	memcpy(out->evt_code, data->evt_code, sizeof(data->evt_code));	// �̺�Ʈ�����ڵ�, 01:�ŷ����� \n02:�������� \n03:�Ҽ��ǰ��ù��� \n04:�����Ÿ�\n05:��ȸ���� \n06:�������ȿ������ \n07:���豸���췮���\n08:���԰��ŵ��Ұ� \n09:Regulation S \n10:���ı������\n11:��������ȯ������\n12:�ܱ�������� (2012.11.05 �߰�)\n13:���� (2016.06.27�߰�)\n14:�������������� (2016.06.27�߰�)\n15:��������ä�� (2016.11.28�߰�)\n16:�̻�޵����� (2017.03.27�߰�)\n17:���ŵ��������� (2017.03.27 �߰�)\n18: LP������ (2017.06.26 �߰�)
	memcpy(out->evt_trgg_code, data->evt_trgg_code, sizeof(data->evt_trgg_code));	// �̺�Ʈ�߻������ڵ�, �� ��÷ �ڵ尩������ �̺�Ʈ�������ڵ� ����\n�� �̺�Ʈ�����ڵ� 03,04,07,08,09,17 �� ���ؼ��� '0000' SET\n�� �ڵ��� ������ ���� �ڸ����� �ٸ��ϴ�. ������ Ÿ����\nX��� �̱� ������ �������ĵ˴ϴ�. ���� �����Ͽ� �ֽʽÿ�.\n(�ŷ����������ڵ�(3�ڸ�), �����������������ڵ�(4�ڸ�),\n��ȸ���������ڵ�(1�ڸ�), �������ȿ�����������ڵ�(2�ڸ�),\n��������ȯ����������ڵ�(4�ڸ�))
	memcpy(out->st_date, data->st_date, sizeof(data->st_date));	// "��������,��������, ��������", YYYYMMDD
	memcpy(out->ed_date, data->ed_date, sizeof(data->ed_date));	// ��������,��������, YYYYMMDD

	return 1;
}


// �ڽ���_LP ����
int ParseI7012(const double& timestamp, const char* in_buff, DF_KOSDAQ_LP_INFO* out) {
	KOSDAQ_LP_INFO* data = (KOSDAQ_LP_INFO*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����, I7
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������, 01:�ֽ�
	out->mkt_clsf = data->mkt_clsf[0];	//���屸��, 1:�������� 2:�ڽ���
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// �����ڵ�, ǥ���ڵ�
	out->snr = Str2Int(data->snr, sizeof(data->snr));	// �Ϸù�ȣ, 1~99999999 �Ǽ�üũ��
	memcpy(out->mkt_ptcp_nr, data->mkt_ptcp_nr, sizeof(data->mkt_ptcp_nr));	// ���������ڹ�ȣ, ���������ڸ� �ĺ�/������ �� �ִ� ��ȣ\n�� ���������ڰ� ���� �ŷ����� ȸ���̸� �ŷ��Һ���\n���������ڹ�ȣ�� �޸���  ��) '00001'
	memcpy(out->lp_open_date, data->lp_open_date, sizeof(data->lp_open_date));	// LP��������, ���������ް�������
	memcpy(out->lp_cls_date, data->lp_cls_date, sizeof(data->lp_cls_date));	// LP��������, ������������������
	out->min_ask_qty_mtp = Str2Dbl(data->min_ask_qty_mtp, sizeof(data->min_ask_qty_mtp), 0);	// �ּ�ȣ���������, LP/MM ȣ���� �Ÿż��������� �ּҹ��\n��) ���� 10�̰� �Ÿż��������� 10��(���)�̸�\nLP/MM ȣ���� 100��(���) �̻����� ȣ���ؾ���
	out->max_ask_qty_mtp = Str2Dbl(data->max_ask_qty_mtp, sizeof(data->max_ask_qty_mtp), 0);	// �ִ�ȣ���������, LP/MM ȣ���� �Ÿż��������� �ִ���
	out->ask_prc_sprd_unit_code = data->ask_prc_sprd_unit_code[0];	//ȣ��������������ڵ�, R:���ݺ���\nY:���ͷ�����(ä��)\nT:ȣ�����ݴ��� ���\nA:���밪 (ä��)\n*����Ī:���Ѵ��������ڵ� 2014.03.03
	out->ask_prc_sprd_val = Str2Dbl(data->ask_prc_sprd_val, sizeof(data->ask_prc_sprd_val), 8);	// ȣ���������尪, LP/MM ȣ�� ������ �ǹ��� �߻��ϴ� �ֿ켱ȣ����������\n���� �Ǵ� ����  9(13)V9(8)
	out->off_mkt_ask_sprd_mtp = Str2Dbl(data->off_mkt_ask_sprd_mtp, sizeof(data->off_mkt_ask_sprd_mtp), 0);	// ����ȣ������������, �Ļ�,ELW,ETF�� �����ڻ��� �ؿܽ����� ���� �Ǵ� ������ ��� �ش� ������ ����, �尳����, ��������, ���� ���� ������ �����ڻ��� ���� ��ġ�� �Ǵ��� �� ���� �� ���� ���� ��ະ�� ������ �������� ���� Ȯ��� �������带 ����ϱ� ���� ��� \n*����Ī:����ȣ���������尪 \n�� ����ȣ���������尪 = ����ȣ������������ * ȣ���������尪 \n(Exture���� ����ȣ���������尪�� 0�ΰ�� Exture+������ ȣ���������尪�� ��ġ��Ŵ) 2014.03.03
	out->obgt_ask_sbmt_time_invl = Str2Int(data->obgt_ask_sbmt_time_invl, sizeof(data->obgt_ask_sbmt_time_invl));	// �ǹ�ȣ������ð�����, ����:��(sec) \n00�� �̳��� �ֿ켱ȣ�������� ��ҽ�Ű�� �ŵ�ȣ�� �Ǵ� �ż�ȣ���� ���� 2014.03.03
	out->ask_min_ask_prc_amt = Str2Dbl(data->ask_min_ask_prc_amt, sizeof(data->ask_min_ask_prc_amt), 3);	// �ŵ��ּ�ȣ���ݾ�, 9(18)V9(3)						   2009.07.27
	out->bid_min_ask_prc_amt = Str2Dbl(data->bid_min_ask_prc_amt, sizeof(data->bid_min_ask_prc_amt), 3);	// �ż��ּ�ȣ���ݾ�, 9(18)V9(3)						   2009.07.27
	out->min_ask_amt = Str2Dbl(data->min_ask_amt, sizeof(data->min_ask_amt), 3);	// �ּ�ȣ���ݾ�, 9(18)V9(3) (2015.11.23 �߰�)\nMM(����������)ȣ���� �ּұݾ�\n��LP�ּ�ȣ����������� ��Ÿ������ ���, LP�ּ�ȣ����������� ���� ������ ��� �ش� �ʵ�� ����
	out->max_ask_amt = Str2Dbl(data->max_ask_amt, sizeof(data->max_ask_amt), 3);	// �ִ�ȣ���ݾ�, 9(18)V9(3) (2015.11.23 �߰�) \n�ִ�ȣ���ݾ�

	return 1;
}


// �ڽ���_�뷮ü��
int ParseC4012(const double& timestamp, const char* in_buff, DF_KOSDAQ_MSV_CCLS* out) {
	KOSDAQ_MSV_CCLS* data = (KOSDAQ_MSV_CCLS*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����, C4
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������, 01:�ֽ�
	out->mkt_clsf = data->mkt_clsf[0];	//���屸��, 1:�������� 2:�ڽ���
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// �����ڵ�, ǥ���ڵ�
	out->stk_snr = Str2Int(data->stk_snr, sizeof(data->stk_snr));	// �����Ϸù�ȣ, �����ġ(A0)�� �����Ϸù�ȣ
	out->snr = Str2Int(data->snr, sizeof(data->snr));	// �Ϸù�ȣ, 1~99999999 �Ǽ�üũ��
	out->bopen_rel_msv_ccls_qty = Str2Int(data->bopen_rel_msv_ccls_qty, sizeof(data->bopen_rel_msv_ccls_qty));	// �尳�����ð��ܻ��뷮ü�����, ����:��
	out->bopen_bsk_ccls_qty = Str2Int(data->bopen_bsk_ccls_qty, sizeof(data->bopen_bsk_ccls_qty));	// �尳�����ð��ܹٽ���ü�����, ����:��
	out->bopen_cmpt_msv_ccls_qty = Str2Int(data->bopen_cmpt_msv_ccls_qty, sizeof(data->bopen_cmpt_msv_ccls_qty));	// �尳�����ð��ܰ���뷮ü�����, ����:��
	out->rel_msv_ccls_qty = Str2Int(data->rel_msv_ccls_qty, sizeof(data->rel_msv_ccls_qty));	// ���߻��뷮ü�����, ����:��
	out->bsk_ccls_qty = Str2Int(data->bsk_ccls_qty, sizeof(data->bsk_ccls_qty));	// ���߹ٽ���ü�����, ����:��
	out->cmpt_msv_ccls_qty = Str2Int(data->cmpt_msv_ccls_qty, sizeof(data->cmpt_msv_ccls_qty));	// ���߰���뷮ü�����, ����:��
	out->ofhr_rel_msv_ccls_qty = Str2Int(data->ofhr_rel_msv_ccls_qty, sizeof(data->ofhr_rel_msv_ccls_qty));	// �������Ľð��ܻ��뷮ü�����, ����:��
	out->ofhr_bsk_ccls_qty = Str2Int(data->ofhr_bsk_ccls_qty, sizeof(data->ofhr_bsk_ccls_qty));	// �������Ľð��ܹٽ���ü�����, ����:��

	return 1;
}


// �ڽ���_�ֽ�������������
int ParseA8012(const double& timestamp, const char* in_buff, DF_KOSDAQ_STK_INFO_DCLS* out) {
	KOSDAQ_STK_INFO_DCLS* data = (KOSDAQ_STK_INFO_DCLS*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����, A8
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������, 01:�ֽ�
	out->mkt_clsf = data->mkt_clsf[0];	//���屸��, 1:�������� 2:�ڽ���
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// �����ڵ�
	out->stk_snr = Str2Int(data->stk_snr, sizeof(data->stk_snr));	// �����Ϸù�ȣ, �����ġ(A0)�� �����Ϸù�ȣ
	memcpy(out->open_info_clsf_code, data->open_info_clsf_code, sizeof(data->open_info_clsf_code));	// �������������ڵ�, �� �ڵ尪���� ����
	memcpy(out->brd_id, data->brd_id, sizeof(data->brd_id));	// ����ID, �� �ڵ尪���� ����
	out->base_prc = Str2Int(data->base_prc, sizeof(data->base_prc));	// ���ذ���
	out->ceil_prc = Str2Int(data->ceil_prc, sizeof(data->ceil_prc));	// ���Ѱ�, ������������ ���� ���� '999999999'
	out->flr_prc = Str2Int(data->flr_prc, sizeof(data->flr_prc));	// ���Ѱ�, ������������ ���� ���� '-99999999'
	out->assm_prc = Str2Int(data->assm_prc, sizeof(data->assm_prc));	// �򰡰���
	out->best_ask_prc = Str2Int(data->best_ask_prc, sizeof(data->best_ask_prc));	// �ְ�ȣ������
	out->least_ask_prc = Str2Int(data->least_ask_prc, sizeof(data->least_ask_prc));	// ����ȣ������
	out->mkt_base_prc_flg = data->mkt_base_prc_flg[0];	//�ð����ذ��ݿ���, Y, N
	memcpy(out->lock_clsf_code, data->lock_clsf_code, sizeof(data->lock_clsf_code));	// �������ڵ�, 00:�ش���׾��� 01:�Ǹ��� 02:���� 03:�й�� 04:�ǹ�� 05:�߰�(�б�)���� 06:�Ǹ��߰����� 07:�Ǹ��б���� 99:��Ÿ
	memcpy(out->pval_chg_clsf_code, data->pval_chg_clsf_code, sizeof(data->pval_chg_clsf_code));	// �׸鰡���汸���ڵ�, 00:�ش���� 01:�׸���� 02:�׸麴�� 03:�ֽĺ��� 04:�ֽĺ��� 99:��Ÿ
	out->trd_qty_unit = Str2Dbl(data->trd_qty_unit, sizeof(data->trd_qty_unit), 0);	// �Ÿż�������, 1�ִ���:1 10:10�ִ��� 100:100�ִ��� 1000:1000�ִ���
	out->stk_lstd = Str2Dbl(data->stk_lstd, sizeof(data->stk_lstd), 0);	// �����ֽļ�
	out->apnt = data->apnt[0];	//��������, N:����  Y:����
	out->bopen_ofhr_flg = data->bopen_ofhr_flg[0];	//�尳�����ð����������ɿ���, N:�ش���� Y:����

	return 1;
}


// �ڽ���_ȸ��������������
int ParseR3012(const double& timestamp, const char* in_buff, DF_KOSDAQ_MBR_SCT_CNCL_DCLS* out) {
	KOSDAQ_MBR_SCT_CNCL_DCLS* data = (KOSDAQ_MBR_SCT_CNCL_DCLS*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����, R3
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������, 01:�ֽ�
	out->mkt_clsf = data->mkt_clsf[0];	//���屸��, 1:�������� 2:�ڽ���
	memcpy(out->ind_code, data->ind_code, sizeof(data->ind_code));	// �����ڵ�, **: �������ش�
	out->stk_snr = Str2Int(data->stk_snr, sizeof(data->stk_snr));	// �����Ϸù�ȣ, �����ġ(A0)�� �����Ϸù�ȣ
	memcpy(out->open_info_clsf_code, data->open_info_clsf_code, sizeof(data->open_info_clsf_code));	// �������������ڵ�, �� �ڵ尪���� ����
	memcpy(out->open_time, data->open_time, sizeof(data->open_time));	// �����ð�
	memcpy(out->mbr_nr, data->mbr_nr, sizeof(data->mbr_nr));	// ȸ����ȣ
	out->mbr_sct_rng_code = Str2Int(data->mbr_sct_rng_code, sizeof(data->mbr_sct_rng_code));	// ȸ��������������ڵ�, ȸ���� �ŷ��� ��� �Ǵ� �����ϴ� ����. Bitwise ���� 1: �ŵ�(ǲ�ż�) ��Ź 2: �ŵ�(ǲ�ż�) �ڱ� 4: �ż�(ǲ�ŵ�) ��Ź 8: �ż�(ǲ�ŵ�) �ڱ�

	return 1;
}


// �ڽ���_�������ٰ���
int ParseM4012(const double& timestamp, const char* in_buff, DF_KOSDAQ_MKT_OPR_DCLS* out) {
	KOSDAQ_MKT_OPR_DCLS* data = (KOSDAQ_MKT_OPR_DCLS*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����, M4
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������, 01:�ֽ�
	out->mkt_clsf = data->mkt_clsf[0];	//���屸��, 1:�������� 2:�ڽ���
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// �����ڵ�, �������� �� ��ġ��, ��������(KO)�� ���
	out->stk_snr = Str2Int(data->stk_snr, sizeof(data->stk_snr));	// �����Ϸù�ȣ, �����ġ(A0)�� �����Ϸù�ȣ
	memcpy(out->brd_id, data->brd_id, sizeof(data->brd_id));	// ����ID, �� �ڵ尪���� ����
	memcpy(out->brd_evt_id, data->brd_evt_id, sizeof(data->brd_evt_id));	// �����̺�ƮID, �� �ڵ尪���� ����
	memcpy(out->brd_evt_st, data->brd_evt_st, sizeof(data->brd_evt_st));	// �����̺�Ʈ���۽ð�
	out->brd_evt_code = Str2Int(data->brd_evt_code, sizeof(data->brd_evt_code));	// �����̺�Ʈ���뱺�ڵ�, �� �ڵ尪���� ����
	memcpy(out->sess_open_cls_id, data->sess_open_cls_id, sizeof(data->sess_open_cls_id));	// ���ǰ��������ڵ�, BS: ���尳�� BE: �������� SS: ���ǰ��� SE: �������� SH: �������� SR: �����簳
	memcpy(out->sess_id, data->sess_id, sizeof(data->sess_id));	// ����ID, �� �ڵ尪���� ����
	memcpy(out->pbl_stk_code, data->pbl_stk_code, sizeof(data->pbl_stk_code));	// ����������ڵ�, ������ġ�� ������ �Ǵ� �����ڵ� *�������� �����ڵ嵵 ���� �� ����
	memcpy(out->trsp_rsn_code, data->trsp_rsn_code, sizeof(data->trsp_rsn_code));	// �ŷ����������ڵ�, �� �ڵ尪���� ���� *��������(KO) �� "  "
	out->trsp_trgg_code = data->trsp_trgg_code[0];	//�ŷ������߻������ڵ�, 1:�ڱ����� 2:�����μ������� 3:�����μ������� 4:�����ڻ�ELW 5:����ELW 6:����� 7:�����ڻ�Ҽӽ��� *��������(KO)�� "1"
	out->apl_step = Str2Int(data->apl_step, sizeof(data->apl_step));	// ����ܰ�, CB �� ���������� Ȯ��� ����Ǵ� �ܰ�(�� ���� ���� "00")

	return 1;
}


// �ڽ���_�ڻ��� ��ġ����
int ParseA9012(const double& timestamp, const char* in_buff, DF_KOSDAQ_TRS_STK_ARNG_INFO* out) {
	KOSDAQ_TRS_STK_ARNG_INFO* data = (KOSDAQ_TRS_STK_ARNG_INFO*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����, A9
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������, 01:�ֽ�
	out->mkt_clsf = data->mkt_clsf[0];	//���屸��, 1:�������� 2:�ڽ���
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// �����ڵ�, ǥ���ڵ�
	out->snr = Str2Int(data->snr, sizeof(data->snr));	// �Ϸù�ȣ, 1~99999999 �Ǽ�üũ��
	memcpy(out->trs_stk_id, data->trs_stk_id, sizeof(data->trs_stk_id));	// �ڻ��ֽŰ�ID, 0:�ش���� N:�ڻ��������Ϲ� S:�ڻ�����������ɼ�\n1~99999:�ڻ��ֽ�Ź�Ϸù�ȣ	�ذ� ��������
	out->ask_bid_clsf_code = data->ask_bid_clsf_code[0];	//�ŵ��ż������ڵ�, 0:��Ź 1:�ŵ� 2:�ż�
	memcpy(out->trs_stk_date, data->trs_stk_date, sizeof(data->trs_stk_date));	// �ڻ��ֽ�û����, YYYYMMDD �ؽŰ��� ��� ��û���ڰ� ����
	memcpy(out->trs_stk_st_date, data->trs_stk_st_date, sizeof(data->trs_stk_st_date));	// �ڻ��ֽŰ�������, YYYYMMDD �Ű����� �ڻ��ָŸ� ��������
	memcpy(out->trs_stk_ed_date, data->trs_stk_ed_date, sizeof(data->trs_stk_ed_date));	// �ڻ��ֽŰ���������, YYYYMMDD �Ű����� �ڻ��ָŸ� ��������
	out->trs_stk_trd_code = data->trs_stk_trd_code[0];	//�ڻ��ָŸŹ���ڵ�, 0:�ش���� 1:�ڻ����Ϲ� 2:������ �ڻ��� 3:���ε� �ڻ���\n��2,3 : �������Ľð��ܴ뷮�ż��� ����, ���ϰŷ�(�ŸŰŷ���\n		����)���� ���\n		���Ϲ��ڻ��ִ� �ð��ܴ뷮 �ż��Ұ�(�ŵ��� ����)\n��3 : �������Ľð��ܴ뷮�ż��� ��/���Ѱ� ���Ѿ���
	out->trs_stk_ptcp_nr = Str2Int(data->trs_stk_ptcp_nr, sizeof(data->trs_stk_ptcp_nr));	// "�ڻ��ֽ�û���������� ��ȣ", ȸ����ȣ ��) '00001'
	out->open_trs_stk_qty = Str2Dbl(data->open_trs_stk_qty, sizeof(data->open_trs_stk_qty), 0);	// "�ð����ϰ��ڻ��ֽ�û ����", �Ű�Ⱓ���� ��û�� �ð����ϰ� ��û ����
	out->opr_time_trs_stk_qty = Str2Dbl(data->opr_time_trs_stk_qty, sizeof(data->opr_time_trs_stk_qty), 0);	// �����ڻ��ֽ�û����, �Ű�Ⱓ���� ��û�� ���� ��û ����
	out->ofhr_msv_trs_stk_qty = Str2Dbl(data->ofhr_msv_trs_stk_qty, sizeof(data->ofhr_msv_trs_stk_qty), 0);	// "�ð��ܴ뷮�ڻ��� ��û����", �ð���(����, ����)������ �ڻ��� �Ű����
	out->trs_stk_cum_ccls_qty = Str2Dbl(data->trs_stk_cum_ccls_qty, sizeof(data->trs_stk_cum_ccls_qty), 0);	// �ڻ��ִ���ü�����, �Ű�Ⱓ���� ������, �ð��ܽ��忡�� �ڻ��� ü����� ����
	out->trs_stk_cum_trd_val = Str2Dbl(data->trs_stk_cum_trd_val, sizeof(data->trs_stk_cum_trd_val), 0);	// �ڻ��ִ����ŷ����, �Ű�Ⱓ���� ������, �ð��ܽ��忡�� �ڻ��� �ŷ���� ����

	return 1;
}


// �ڽ���_�ڻ��� �Ÿ�����
int ParseB0012(const double& timestamp, const char* in_buff, DF_KOSDAQ_TRS_STK_TRD_INFO* out) {
	KOSDAQ_TRS_STK_TRD_INFO* data = (KOSDAQ_TRS_STK_TRD_INFO*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����, B0
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������, 01:�ֽ�
	out->mkt_clsf = data->mkt_clsf[0];	//���屸��, 1:�������� 2:�ڽ���
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// �����ڵ�, ǥ���ڵ�
	out->snr = Str2Int(data->snr, sizeof(data->snr));	// �Ϸù�ȣ, 1~99999999 �����Ϸù�ȣ 2014.03.03
	out->ccls_prc = Str2Int(data->ccls_prc, sizeof(data->ccls_prc));	// ü�ᰡ��, ����:��
	out->ccls_qty = Str2Dbl(data->ccls_qty, sizeof(data->ccls_qty), 0);	// ü�����, ����:��
	memcpy(out->sess_id, data->sess_id, sizeof(data->sess_id));	// ����ID, �ڵ尪���� ����
	memcpy(out->bid_trs_stk_id, data->bid_trs_stk_id, sizeof(data->bid_trs_stk_id));	// �ż��ڻ��ֽŰ�ID, 0:�ش���� N:�ڻ��������Ϲ� S:�ڻ���������Ź�ɼ�\n1~99999:�ڻ��ֽ�Ź(�Ű��Ϸù�ȣ)\n�ذ��� ��������  ��) "N", "1"\n���ڻ��ֽ�Ź�Ϸù�ȣ�� ���񺰷� ���������� ���� ä����\n  ������ ���� ��Ź�� �Ϸù�ȣ�� �����ϴ� ������ ����\n  ���� ���ؼ� ���� ��Źȸ�翡�� �ڻ��ָ� �Ű��� ��\n  �ֵ��� ����ϱ� ������
	memcpy(out->ask_trs_stk_id, data->ask_trs_stk_id, sizeof(data->ask_trs_stk_id));	// �ŵ��ڻ��ֽŰ�ID, �ż��ڻ��ֽŰ�ID�� ����

	return 1;
}


// �ڽ���_�ü�RECOVERY
int ParseB2012(const double& timestamp, const char* in_buff, DF_KOSDAQ_MKT_PRC_RCVR* out) {
	KOSDAQ_MKT_PRC_RCVR* data = (KOSDAQ_MKT_PRC_RCVR*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����, B1:���� B2:�ü�REC
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������, 01:�ֽ� 02:ELW
	out->mkt_clsf = data->mkt_clsf[0];	//���屸��, 1:�������� 2:�ڽ���
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// �����ڵ�, ǥ���ڵ�
	out->stk_snr = Str2Int(data->stk_snr, sizeof(data->stk_snr));	// �����Ϸù�ȣ, �����ġ(A0)�� �����Ϸù�ȣ
	out->flct_clsf = data->flct_clsf[0];	//�������, 0:�ǴܺҰ� 1:���� 2:��� 3:���� 4:���� 5:�϶�
	out->prev_ctrs = Str2Int(data->prev_ctrs, sizeof(data->prev_ctrs));	// ���ϴ��, ����:��
	out->cur_prc = Str2Int(data->cur_prc, sizeof(data->cur_prc));	// ���簡
	out->open = Str2Int(data->open, sizeof(data->open));	// �ð�, ������ �ð�
	out->hi = Str2Int(data->hi, sizeof(data->hi));	// ��, ������ ��
	out->low = Str2Int(data->low, sizeof(data->low));	// ����, ������ ����
	out->ask_prc = Str2Int(data->ask_prc, sizeof(data->ask_prc));	// �ŵ�ȣ��, B1�� 0�� SET
	out->bid_prc = Str2Int(data->bid_prc, sizeof(data->bid_prc));	// �ż�ȣ��, B1�� 0�� SET
	out->cum_ccls_qty = Str2Dbl(data->cum_ccls_qty, sizeof(data->cum_ccls_qty), 0);	// ����ü�����, ����:�� �ؽð��ܴ��ϰ�, BUY-IN�� ������ ��� ü����� �ջ�
	out->cum_trd_val = Str2Dbl(data->cum_trd_val, sizeof(data->cum_trd_val), 0);	// �����ŷ����, ����:�� �ؽð��ܴ��ϰ�, BUY-IN�� ������ ��� �ŷ���� �ջ�
	out->trend_flg = data->trend_flg[0];	//�Ǽ�/�⼼ ����, 0:�ʱⰪ 1:�Ǽ� 2:�⼼ 3:�ŷ��� 4:�ð����ذ������� �⼼
	memcpy(out->brd_evt_id, data->brd_evt_id, sizeof(data->brd_evt_id));	// �����̺�ƮID, B1/B2 ������ �����̺�ƮID ������(���� ���°��� ���۵� �� ����). ����, �ش� �׸� '000' ���� ����. 2014.03.24)
	memcpy(out->brd_id, data->brd_id, sizeof(data->brd_id));	// ����ID, �� �ڵ尪���� ����
	out->trsp_flg = data->trsp_flg[0];	//�ŷ���������, Y, N
	out->bopen_ofhr_ccls_qty = Str2Dbl(data->bopen_ofhr_ccls_qty, sizeof(data->bopen_ofhr_ccls_qty), 0);	// �尳�����ð�������ü�����, �뷮, �ٽ����� ����, ����:��
	out->bopen_ofhr_trd_val = Str2Dbl(data->bopen_ofhr_trd_val, sizeof(data->bopen_ofhr_trd_val), 0);	// �尳�����ð��������ŷ����, �뷮, �ٽ����� ����, ����:��
	out->opr_time_ccls_qty = Str2Dbl(data->opr_time_ccls_qty, sizeof(data->opr_time_ccls_qty), 0);	// ������ü�����, �뷮, �ٽ����� ����, ����:��
	out->opr_time_trd_val = Str2Dbl(data->opr_time_trd_val, sizeof(data->opr_time_trd_val), 0);	// ������ŷ����, �뷮, �ٽ����� ����, ����:��
	out->ofhr_cls_ccls_qty = Str2Dbl(data->ofhr_cls_ccls_qty, sizeof(data->ofhr_cls_ccls_qty), 0);	// �������Ľð�������ü�����, �뷮, �ٽ����� ����, ����:��
	out->ofhr_cls_trd_val = Str2Dbl(data->ofhr_cls_trd_val, sizeof(data->ofhr_cls_trd_val), 0);	// �������Ľð��������ŷ����, �뷮, �ٽ����� ����, ����:��
	out->elw_ely_cls_flg = data->elw_ely_cls_flg[0];	//ELW�������Ῡ��, Y,N ��������ELW �� ������ Default 'N' SET
	out->elw_ely_cls_time = Str2Int(data->elw_ely_cls_time, sizeof(data->elw_ely_cls_time));	// ELW��������ð�, HHMMSS, ELW�������Ῡ�ΰ� 'Y'�� ��츸 ����
	out->cmpt_msv_dir_clsf = Str2Int(data->cmpt_msv_dir_clsf, sizeof(data->cmpt_msv_dir_clsf));	// ����뷮 ���ⱸ��, 0:�ش����, 1:�ŵ�, 2:�ż�
	out->gen_bin_ccls_qty = Str2Dbl(data->gen_bin_ccls_qty, sizeof(data->gen_bin_ccls_qty), 0);	// �Ϲ� Buy-in ü�����, ����:��
	out->gen_bin_ccls_trd_val = Str2Dbl(data->gen_bin_ccls_trd_val, sizeof(data->gen_bin_ccls_trd_val), 0);	// �Ϲ� Buy-in �ŷ����, ����:��
	out->day_bin_ccls_qty = Str2Dbl(data->day_bin_ccls_qty, sizeof(data->day_bin_ccls_qty), 0);	// ���� Buy-in ü�����, ����:��
	out->day_bin_ccls_trd_val = Str2Dbl(data->day_bin_ccls_trd_val, sizeof(data->day_bin_ccls_trd_val), 0);	// ���� Buy-in �ŷ����, ����:��

	return 1;
}


// �ڽ���_�ð��ܴ��ϰ�_��Ŀ����_����
int ParseB3012(const double& timestamp, const char* in_buff, DF_KOSDAQ_OFH_RCVR_FINAL* out) {
	KOSDAQ_OFH_RCVR_FINAL* data = (KOSDAQ_OFH_RCVR_FINAL*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����, B3:�ð��ܴ��ϰ����� B4:�ð��ܴ��ϰ�REC
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������, 01:�ֽ�
	out->mkt_clsf = data->mkt_clsf[0];	//���屸��, 1:�������� 2:�ڽ���
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// �����ڵ�, ǥ���ڵ�
	out->stk_snr = Str2Int(data->stk_snr, sizeof(data->stk_snr));	// �����Ϸù�ȣ, �����ġ(A0)�� �����Ϸù�ȣ
	out->ofhr_cnst_clsf = data->ofhr_cnst_clsf[0];	//�ð��ܴ��ϰ��������, 0:�ǴܺҰ� 1:���� 2:��� 3:���� 4:���� 5:�϶�
	out->ofhr_cnst = Str2Int(data->ofhr_cnst, sizeof(data->ofhr_cnst));	// �ð��ܴ��ϰ����, ����:��
	out->ofhr_cnst_ceil = Str2Int(data->ofhr_cnst_ceil, sizeof(data->ofhr_cnst_ceil));	// �ð��ܴ��ϰ����Ѱ�
	out->ofhr_cnst_flr = Str2Int(data->ofhr_cnst_flr, sizeof(data->ofhr_cnst_flr));	// �ð��ܴ��ϰ����Ѱ�
	out->ofhr_cnst_cur = Str2Int(data->ofhr_cnst_cur, sizeof(data->ofhr_cnst_cur));	// �ð��ܴ��ϰ����簡
	out->ofhr_cnst_open = Str2Int(data->ofhr_cnst_open, sizeof(data->ofhr_cnst_open));	// �ð��ܴ��ϰ��ð�
	out->ofhr_cnst_hi = Str2Int(data->ofhr_cnst_hi, sizeof(data->ofhr_cnst_hi));	// �ð��ܴ��ϰ���
	out->ofhr_cnst_lo = Str2Int(data->ofhr_cnst_lo, sizeof(data->ofhr_cnst_lo));	// �ð��ܴ��ϰ�����
	out->ofhr_cnst_ask = Str2Int(data->ofhr_cnst_ask, sizeof(data->ofhr_cnst_ask));	// �ð��ܴ��ϰ��ŵ�ȣ��, B3�� 0�� SET
	out->ofhr_cnst_bid = Str2Int(data->ofhr_cnst_bid, sizeof(data->ofhr_cnst_bid));	// �ð��ܴ��ϰ��ż�ȣ��, B3�� 0�� SET
	out->ofhr_cnst_cum_ccls_qty = Str2Dbl(data->ofhr_cnst_cum_ccls_qty, sizeof(data->ofhr_cnst_cum_ccls_qty), 0);	// �ð��ܴ��ϰ�����ü�����
	out->ofhr_cnst_cum_trd_val = Str2Dbl(data->ofhr_cnst_cum_trd_val, sizeof(data->ofhr_cnst_cum_trd_val), 0);	// �ð��ܴ��ϰ������ŷ����
	out->tot_cum_ccls_qty = Str2Dbl(data->tot_cum_ccls_qty, sizeof(data->tot_cum_ccls_qty), 0);	// ��ü �� ����ü�����
	out->tot_cum_trd_val = Str2Dbl(data->tot_cum_trd_val, sizeof(data->tot_cum_trd_val), 0);	// ��ü �� �����ŷ����
	out->ofhr_mkt_clsf = data->ofhr_mkt_clsf[0];	//�ð��ܴ��ϰ��屸��, 0:�ʱⰪ 1:�ð��ܴ��ϰ����� 2:�ð��ܴ��ϰ�����
	out->trsp_flg = data->trsp_flg[0];	//�ŷ���������, Y, N
	out->trend_flg = data->trend_flg[0];	//�Ǽ�/�⼼ ����, 0:�ʱⰪ 1:�Ǽ� 2:�⼼ 3:�ŷ��� 4:�ð����ذ������� �⼼

	return 1;
}


// �ڽ���_�ð��ܴ��ϰ�_��Ŀ����
int ParseB4012(const double& timestamp, const char* in_buff, DF_KOSDAQ_OFH_RCVR* out) {
	KOSDAQ_OFH_RCVR* data = (KOSDAQ_OFH_RCVR*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����, B3:�ð��ܴ��ϰ����� B4:�ð��ܴ��ϰ�REC
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������, 01:�ֽ�
	out->mkt_clsf = data->mkt_clsf[0];	//���屸��, 1:�������� 2:�ڽ���
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// �����ڵ�, ǥ���ڵ�
	out->stk_snr = Str2Int(data->stk_snr, sizeof(data->stk_snr));	// �����Ϸù�ȣ, �����ġ(A0)�� �����Ϸù�ȣ
	out->ofhr_cnst_clsf = data->ofhr_cnst_clsf[0];	//�ð��ܴ��ϰ��������, 0:�ǴܺҰ� 1:���� 2:��� 3:���� 4:���� 5:�϶�
	out->ofhr_cnst = Str2Int(data->ofhr_cnst, sizeof(data->ofhr_cnst));	// �ð��ܴ��ϰ����, ����:��
	out->ofhr_cnst_ceil = Str2Int(data->ofhr_cnst_ceil, sizeof(data->ofhr_cnst_ceil));	// �ð��ܴ��ϰ����Ѱ�
	out->ofhr_cnst_flr = Str2Int(data->ofhr_cnst_flr, sizeof(data->ofhr_cnst_flr));	// �ð��ܴ��ϰ����Ѱ�
	out->ofhr_cnst_cur = Str2Int(data->ofhr_cnst_cur, sizeof(data->ofhr_cnst_cur));	// �ð��ܴ��ϰ����簡
	out->ofhr_cnst_open = Str2Int(data->ofhr_cnst_open, sizeof(data->ofhr_cnst_open));	// �ð��ܴ��ϰ��ð�
	out->ofhr_cnst_hi = Str2Int(data->ofhr_cnst_hi, sizeof(data->ofhr_cnst_hi));	// �ð��ܴ��ϰ���
	out->ofhr_cnst_lo = Str2Int(data->ofhr_cnst_lo, sizeof(data->ofhr_cnst_lo));	// �ð��ܴ��ϰ�����
	out->ofhr_cnst_ask = Str2Int(data->ofhr_cnst_ask, sizeof(data->ofhr_cnst_ask));	// �ð��ܴ��ϰ��ŵ�ȣ��, B3�� 0�� SET
	out->ofhr_cnst_bid = Str2Int(data->ofhr_cnst_bid, sizeof(data->ofhr_cnst_bid));	// �ð��ܴ��ϰ��ż�ȣ��, B3�� 0�� SET
	out->ofhr_cnst_cum_ccls_qty = Str2Dbl(data->ofhr_cnst_cum_ccls_qty, sizeof(data->ofhr_cnst_cum_ccls_qty), 0);	// �ð��ܴ��ϰ�����ü�����
	out->ofhr_cnst_cum_trd_val = Str2Dbl(data->ofhr_cnst_cum_trd_val, sizeof(data->ofhr_cnst_cum_trd_val), 0);	// �ð��ܴ��ϰ������ŷ����
	out->tot_cum_ccls_qty = Str2Dbl(data->tot_cum_ccls_qty, sizeof(data->tot_cum_ccls_qty), 0);	// ��ü �� ����ü�����
	out->tot_cum_trd_val = Str2Dbl(data->tot_cum_trd_val, sizeof(data->tot_cum_trd_val), 0);	// ��ü �� �����ŷ����
	out->ofhr_mkt_clsf = data->ofhr_mkt_clsf[0];	//�ð��ܴ��ϰ��屸��, 0:�ʱⰪ 1:�ð��ܴ��ϰ����� 2:�ð��ܴ��ϰ�����
	out->trsp_flg = data->trsp_flg[0];	//�ŷ���������, Y, N
	out->trend_flg = data->trend_flg[0];	//�Ǽ�/�⼼ ����, 0:�ʱⰪ 1:�Ǽ� 2:�⼼ 3:�ŷ��� 4:�ð����ذ������� �⼼

	return 1;
}


// �ڽ���_������
int ParseB5012(const double& timestamp, const char* in_buff, DF_KOSDAQ_CUR_FLCT* out) {
	KOSDAQ_CUR_FLCT* data = (KOSDAQ_CUR_FLCT*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����, B5
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������, 01:�ֽ�
	out->mkt_clsf = data->mkt_clsf[0];	//���屸��, 1:�������� 2:�ڽ���
	out->tot_stk_nr = Str2Int(data->tot_stk_nr, sizeof(data->tot_stk_nr));	// ��ü �����
	out->trd_form_stk_nr = Str2Int(data->trd_form_stk_nr, sizeof(data->trd_form_stk_nr));	// �ŷ����� �����
	out->ceil_stk_nr = Str2Int(data->ceil_stk_nr, sizeof(data->ceil_stk_nr));	// ���� �����
	out->rise_stk_nr = Str2Int(data->rise_stk_nr, sizeof(data->rise_stk_nr));	// ��� �����
	out->stdstl_stk_nr = Str2Int(data->stdstl_stk_nr, sizeof(data->stdstl_stk_nr));	// ���� �����
	out->flr_stk_nr = Str2Int(data->flr_stk_nr, sizeof(data->flr_stk_nr));	// ���� �����
	out->fall_stk_nr = Str2Int(data->fall_stk_nr, sizeof(data->fall_stk_nr));	// �϶� �����
	out->trend_stk_nr = Str2Int(data->trend_stk_nr, sizeof(data->trend_stk_nr));	// �⼼ �����
	out->trend_rise_stk_nr = Str2Int(data->trend_rise_stk_nr, sizeof(data->trend_rise_stk_nr));	// �⼼��� �����
	out->trend_fall_stk_nr = Str2Int(data->trend_fall_stk_nr, sizeof(data->trend_fall_stk_nr));	// �⼼�϶� �����

	return 1;
}


// �ڽ���_Buy-in_�������
int ParseO4012(const double& timestamp, const char* in_buff, DF_KOSDAQ_BIN_EXCQ* out) {
	KOSDAQ_BIN_EXCQ* data = (KOSDAQ_BIN_EXCQ*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����, O4
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������, 01:�ֽ�
	out->mkt_clsf = data->mkt_clsf[0];	//���屸��, 1:��������, 2:�ڽ���, 8:�ڳؽ�
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// �����ڵ�, ǥ���ڵ� �Ǵ� "999999999999" ���߰��̵� ����
	out->snr = Str2Int(data->snr, sizeof(data->snr));	// �Ϸù�ȣ, �� Buy-in�����ڵ庰�� �Ϸù�ȣ ����
	memcpy(out->trsm_date, data->trsm_date, sizeof(data->trsm_date));	// ��������, YYYYMMDD
	out->bin_clsf_code = data->bin_clsf_code[0];	//Buy-in�����ڵ�, 1: �Ϲ� Buy-in, 2: ���� Buy-in
	out->scrt_grp_id = Str2Int(data->scrt_grp_id, sizeof(data->scrt_grp_id));	// ���Ǳ׷�ID, ST:�ֽ�, MF:��������ȸ��, RT:����, SC:��������ȸ��,\nIF:������������ȸ��, DR:��Ź����, SW:�����μ�������,\nSR:�����μ�������, EW:�ֽĿ���Ʈ����, EF:���������ݵ�,\nBC:��������, FE:�ؿ�ETF, FS:�ؿܿ���\nEN:ETN(2014.11.17)
	out->bin_exc_qty = Str2Dbl(data->bin_exc_qty, sizeof(data->bin_exc_qty), 0);	// Buy-in �������

	return 1;
}


// �ڽ��� ������ �����ͷ�
int ParseP2012(const double& timestamp, const char* in_buff, DF_KOSDAQ_BYIND_DYR* out) {
	KOSDAQ_BYIND_DYR* data = (KOSDAQ_BYIND_DYR*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����, P2
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������, 01:�ֽ�
	out->mkt_clsf = data->mkt_clsf[0];	//���屸��, 1:�������� 2:�ڽ���
	memcpy(out->idx_ind_code, data->idx_ind_code, sizeof(data->idx_ind_code));	// ���������ڵ�, ���ڵ尪���� ����
	out->dyr = Str2Dbl(data->dyr, sizeof(data->dyr), 2);	// �����ͷ�, 99999v99

	return 1;
}


// �ڽ���_�尳����_ȣ���ܷ�
int ParseB8012(const double& timestamp, const char* in_buff, DF_KOSDAQ_BOPEN_ASK_RSD* out) {
	KOSDAQ_BOPEN_ASK_RSD* data = (KOSDAQ_BOPEN_ASK_RSD*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����, B8
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������, 01:�ֽ�
	out->mkt_clsf = data->mkt_clsf[0];	//���屸��, 1:�������� 2:�ڽ���
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// �����ڵ�, ǥ���ڵ�
	out->stk_snr = Str2Int(data->stk_snr, sizeof(data->stk_snr));	// �����Ϸù�ȣ, �����ġ(A0)�� �����Ϸù�ȣ
	out->cum_ccls_qty = Str2Dbl(data->cum_ccls_qty, sizeof(data->cum_ccls_qty), 0);	// ����ü�����
	out->tot_ask_rsd = Str2Dbl(data->tot_ask_rsd, sizeof(data->tot_ask_rsd), 0);	// �Ѹŵ�ȣ���ܷ�
	out->tot_bid_rsd = Str2Dbl(data->tot_bid_rsd, sizeof(data->tot_bid_rsd), 0);	// �Ѹż�ȣ���ܷ�

	return 1;
}


// �ڽ���_ȣ���ܷ�_LPȣ��_����
int ParseB6012(const double& timestamp, const char* in_buff, DF_KOSDAQ_ASK_RSD_WOLP* out) {
	int i=0;
	KOSDAQ_ASK_RSD_WOLP* data = (KOSDAQ_ASK_RSD_WOLP*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����, B6
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������, 01:�ֽ�
	out->mkt_clsf = data->mkt_clsf[0];	//���屸��, 1:�������� 2:�ڽ���
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// �����ڵ�, ǥ���ڵ�
	out->stk_snr = Str2Int(data->stk_snr, sizeof(data->stk_snr));	// �����Ϸù�ȣ, �����ġ(A0)�� �����Ϸù�ȣ
	out->cum_ccls_qty = Str2Dbl(data->cum_ccls_qty, sizeof(data->cum_ccls_qty), 0);	// ����ü�����

	for ( i=0 ; i<10 ; i++ ) {
		out->lob_infos[i].ask_prc = Str2Int(data->lob_infos[i].ask_prc, sizeof(data->lob_infos[i].ask_prc));	// �ŵ�ȣ��
		out->lob_infos[i].bid_prc = Str2Int(data->lob_infos[i].bid_prc, sizeof(data->lob_infos[i].bid_prc));	// �ż�ȣ��
		out->lob_infos[i].ask_vol_rsd = Str2Dbl(data->lob_infos[i].ask_vol_rsd, sizeof(data->lob_infos[i].ask_vol_rsd), 0);	// �ŵ�ȣ�� �ܷ�
		out->lob_infos[i].bid_vol_rsd = Str2Dbl(data->lob_infos[i].bid_vol_rsd, sizeof(data->lob_infos[i].bid_vol_rsd), 0);	// �ż�ȣ�� �ܷ�
	}   // ȣ��

	out->ask_10_tot_rsd = Str2Dbl(data->ask_10_tot_rsd, sizeof(data->ask_10_tot_rsd), 0);	// 10�ܰ�ȣ���ŵ����ܷ�
	out->bid_10_tot_rsd = Str2Dbl(data->bid_10_tot_rsd, sizeof(data->bid_10_tot_rsd), 0);	// 10�ܰ�ȣ���ż����ܷ�
	out->ofhr_ask_tot_rsd = Str2Dbl(data->ofhr_ask_tot_rsd, sizeof(data->ofhr_ask_tot_rsd), 0);	// �������Ľð��ܸŵ���ȣ���ܷ�, ����ID "G3"�϶� ���� ������
	out->ofhr_bid_tot_rsd = Str2Dbl(data->ofhr_bid_tot_rsd, sizeof(data->ofhr_bid_tot_rsd), 0);	// �������Ľð��ܸż���ȣ���ܷ�, ����ID "G3"�϶� ���� ������
	memcpy(out->sess_id, data->sess_id, sizeof(data->sess_id));	// ����ID, �� �ڵ尪���� ����
	memcpy(out->brd_id, data->brd_id, sizeof(data->brd_id));	// ����ID, �� �ڵ尪���� ����
	out->exp_ccls_prc = Str2Int(data->exp_ccls_prc, sizeof(data->exp_ccls_prc));	// ����ü�ᰡ��
	out->exp_ccls_qty = Str2Dbl(data->exp_ccls_qty, sizeof(data->exp_ccls_qty), 0);	// ����ü�����
	out->cmpt_msv_dir_clsf = Str2Int(data->cmpt_msv_dir_clsf, sizeof(data->cmpt_msv_dir_clsf));	// ����뷮 ���ⱸ��, 0:�ش����, 1:�ŵ�, 2:�ż�

	return 1;
}


// �ڽ���_���ŵ�
int ParseI8012(const double& timestamp, const char* in_buff, DF_KOSDAQ_SHORT* out) {
	KOSDAQ_SHORT* data = (KOSDAQ_SHORT*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����, I8
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������, 01:�ֽ�
	out->mkt_clsf = data->mkt_clsf[0];	//���屸��, 1:�������� 2:�ڽ���
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// �����ڵ�, ǥ���ڵ�
	out->snr = Str2Int(data->snr, sizeof(data->snr));	// �Ϸù�ȣ, 1~99999999 �����Ϸù�ȣ
	out->short_brwg_ask_ccls_qty = Str2Dbl(data->short_brwg_ask_ccls_qty, sizeof(data->short_brwg_ask_ccls_qty), 0);	// "���ŵ��������Ǹŵ� ü�����", ����:��
	out->short_brwg_ask_trd_val = Str2Dbl(data->short_brwg_ask_trd_val, sizeof(data->short_brwg_ask_trd_val), 0);	// "���ŵ��������Ǹŵ� �ŷ����", ����:��

	return 1;
}


// �ڽ���_�ü�����
int ParseB1012(const double& timestamp, const char* in_buff, DF_KOSDAQ_MKT_PRC_CLS* out) {
	KOSDAQ_MKT_PRC_CLS* data = (KOSDAQ_MKT_PRC_CLS*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����, B1:���� B2:�ü�REC
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������, 01:�ֽ� 02:ELW
	out->mkt_clsf = data->mkt_clsf[0];	//���屸��, 1:�������� 2:�ڽ���
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// �����ڵ�, ǥ���ڵ�
	out->stk_snr = Str2Int(data->stk_snr, sizeof(data->stk_snr));	// �����Ϸù�ȣ, �����ġ(A0)�� �����Ϸù�ȣ
	out->flct_clsf = data->flct_clsf[0];	//�������, 0:�ǴܺҰ� 1:���� 2:��� 3:���� 4:���� 5:�϶�
	out->prev_ctrs = Str2Int(data->prev_ctrs, sizeof(data->prev_ctrs));	// ���ϴ��, ����:��
	out->cur_prc = Str2Int(data->cur_prc, sizeof(data->cur_prc));	// ���簡
	out->open = Str2Int(data->open, sizeof(data->open));	// �ð�, ������ �ð�
	out->hi = Str2Int(data->hi, sizeof(data->hi));	// ��, ������ ��
	out->low = Str2Int(data->low, sizeof(data->low));	// ����, ������ ����
	out->ask_prc = Str2Int(data->ask_prc, sizeof(data->ask_prc));	// �ŵ�ȣ��, B1�� 0�� SET
	out->bid_prc = Str2Int(data->bid_prc, sizeof(data->bid_prc));	// �ż�ȣ��, B1�� 0�� SET
	out->cum_ccls_qty = Str2Dbl(data->cum_ccls_qty, sizeof(data->cum_ccls_qty), 0);	// ����ü�����, ����:�� �ؽð��ܴ��ϰ�, BUY-IN�� ������ ��� ü����� �ջ�
	out->cum_trd_val = Str2Dbl(data->cum_trd_val, sizeof(data->cum_trd_val), 0);	// �����ŷ����, ����:�� �ؽð��ܴ��ϰ�, BUY-IN�� ������ ��� �ŷ���� �ջ�
	out->trend_flg = data->trend_flg[0];	//�Ǽ�/�⼼ ����, 0:�ʱⰪ 1:�Ǽ� 2:�⼼ 3:�ŷ��� 4:�ð����ذ������� �⼼
	memcpy(out->brd_evt_id, data->brd_evt_id, sizeof(data->brd_evt_id));	// �����̺�ƮID, B1/B2 ������ �����̺�ƮID ������(���� ���°��� ���۵� �� ����). ����, �ش� �׸� '000' ���� ����. 2014.03.24)
	memcpy(out->brd_id, data->brd_id, sizeof(data->brd_id));	// ����ID, �� �ڵ尪���� ����
	out->trsp_flg = data->trsp_flg[0];	//�ŷ���������, Y, N
	out->bopen_ofhr_ccls_qty = Str2Dbl(data->bopen_ofhr_ccls_qty, sizeof(data->bopen_ofhr_ccls_qty), 0);	// �尳�����ð�������ü�����, �뷮, �ٽ����� ����, ����:��
	out->bopen_ofhr_trd_val = Str2Dbl(data->bopen_ofhr_trd_val, sizeof(data->bopen_ofhr_trd_val), 0);	// �尳�����ð��������ŷ����, �뷮, �ٽ����� ����, ����:��
	out->opr_time_ccls_qty = Str2Dbl(data->opr_time_ccls_qty, sizeof(data->opr_time_ccls_qty), 0);	// ������ü�����, �뷮, �ٽ����� ����, ����:��
	out->opr_time_trd_val = Str2Dbl(data->opr_time_trd_val, sizeof(data->opr_time_trd_val), 0);	// ������ŷ����, �뷮, �ٽ����� ����, ����:��
	out->ofhr_cls_ccls_qty = Str2Dbl(data->ofhr_cls_ccls_qty, sizeof(data->ofhr_cls_ccls_qty), 0);	// �������Ľð�������ü�����, �뷮, �ٽ����� ����, ����:��
	out->ofhr_cls_trd_val = Str2Dbl(data->ofhr_cls_trd_val, sizeof(data->ofhr_cls_trd_val), 0);	// �������Ľð��������ŷ����, �뷮, �ٽ����� ����, ����:��
	out->elw_ely_cls_flg = data->elw_ely_cls_flg[0];	//ELW�������Ῡ��, Y,N ��������ELW �� ������ Default 'N' SET
	out->elw_ely_cls_time = Str2Int(data->elw_ely_cls_time, sizeof(data->elw_ely_cls_time));	// ELW��������ð�, HHMMSS, ELW�������Ῡ�ΰ� 'Y'�� ��츸 ����
	out->cmpt_msv_dir_clsf = Str2Int(data->cmpt_msv_dir_clsf, sizeof(data->cmpt_msv_dir_clsf));	// ����뷮 ���ⱸ��, 0:�ش����, 1:�ŵ�, 2:�ż�
	out->gen_bin_ccls_qty = Str2Dbl(data->gen_bin_ccls_qty, sizeof(data->gen_bin_ccls_qty), 0);	// �Ϲ� Buy-in ü�����, ����:��
	out->gen_bin_ccls_trd_val = Str2Dbl(data->gen_bin_ccls_trd_val, sizeof(data->gen_bin_ccls_trd_val), 0);	// �Ϲ� Buy-in �ŷ����, ����:��
	out->day_bin_ccls_qty = Str2Dbl(data->day_bin_ccls_qty, sizeof(data->day_bin_ccls_qty), 0);	// ���� Buy-in ü�����, ����:��
	out->day_bin_ccls_trd_val = Str2Dbl(data->day_bin_ccls_trd_val, sizeof(data->day_bin_ccls_trd_val), 0);	// ���� Buy-in �ŷ����, ����:��

	return 1;
}


// �ڽ���_�����������ں�
int ParseC0012(const double& timestamp, const char* in_buff, DF_KOSDAQ_BYIND_BYINV* out) {
	KOSDAQ_BYIND_BYINV* data = (KOSDAQ_BYIND_BYINV*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����, C0
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������, 01:�ֽ�
	out->mkt_clsf = data->mkt_clsf[0];	//���屸��, 1:�������� 2:�ڽ���
	memcpy(out->cmpt_time, data->cmpt_time, sizeof(data->cmpt_time));	// ����ð�, 90�� �ֱ�
	memcpy(out->inv_code, data->inv_code, sizeof(data->inv_code));	// �������ڵ�, ���ڵ尪���� ����\n*�ڵ�'7000'�� ����, ������� �׸� 0���� ���� (20181210)
	memcpy(out->ind_code, data->ind_code, sizeof(data->ind_code));	// �����ڵ�, ���ڵ尪���� ���������ڵ�з� ����\n�������;�ڽ���/�ڽ�����������,�ڽ���200����
	out->ask_ccls_qty = Str2Dbl(data->ask_ccls_qty, sizeof(data->ask_ccls_qty), 0);	// �ŵ�ü�����, ����:��
	out->ask_trd_val = Str2Dbl(data->ask_trd_val, sizeof(data->ask_trd_val), 0);	// �ŵ��ŷ����, ����:��
	out->bid_ccls_qty = Str2Dbl(data->bid_ccls_qty, sizeof(data->bid_ccls_qty), 0);	// �ż�ü�����, ����:��
	out->bid_trd_val = Str2Dbl(data->bid_trd_val, sizeof(data->bid_trd_val), 0);	// �ż��ŷ����, ����:��

	return 1;
}


// K-OTC �����ġ
int ParseA0013(const double& timestamp, const char* in_buff, DF_KOTC_STK_ARNG* out) {
	int i=0;
	KOTC_STK_ARNG* data = (KOTC_STK_ARNG*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����, A0
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������, 01:�ֽ�
	out->mkt_clsf = data->mkt_clsf[0];	//���屸��, 3:K-OTC
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// �����ڵ�, ǥ���ڵ�
	out->snr = Str2Int(data->snr, sizeof(data->snr));	// �Ϸù�ȣ, 1~99999999 �Ǽ�üũ��
	memcpy(out->sh_code, data->sh_code, sizeof(data->sh_code));	// �����ڵ�, ��������((��)�ֽ� 6��7, ������ SPACE ó��)
	memcpy(out->proc_date, data->proc_date, sizeof(data->proc_date));	// ó������, �������� (YYYYMMDD)
	memcpy(out->kor_stk_nm, data->kor_stk_nm, sizeof(data->kor_stk_nm));	// �ѱ������, SIZE����(40��80) 2016.02.01
	memcpy(out->eng_abrv, data->eng_abrv, sizeof(data->eng_abrv));	// �������, SIZE����(20��40) 2016.02.01
	memcpy(out->eng_stk_nm, data->eng_stk_nm, sizeof(data->eng_stk_nm));	// ���������, SIZE����(40��80) 2016.02.01
	memcpy(out->kor_stk_abrv, data->kor_stk_abrv, sizeof(data->kor_stk_abrv));	// �����(�ѱ۾��), SIZE����(20��40) 2016.02.01
	out->stk_snr = Str2Int(data->stk_snr, sizeof(data->stk_snr));	// �����Ϸù�ȣ
	out->stk_clsf = data->stk_clsf[0];	//���񱸺�, 0:���� 1:�ű� 2:�߰�
	out->mdim_biz_flg = data->mdim_biz_flg[0];	//�߼��߰߱������, 4:�߼ұ�� 5:�߰߱�� 6�߼��߰ߺ��ش� 7:��Ȯ��
	memcpy(out->std_type_ind_code, data->std_type_ind_code, sizeof(data->std_type_ind_code));	// ǥ�ػ�������ڵ�
	out->trd_base_prc = Str2Int(data->trd_base_prc, sizeof(data->trd_base_prc));	// �Ÿű��ذ�, ��������ְ�, ���߻��� ���Ÿű��ذ��� SET\n�⼼�ô� '�⼼����' SET\nSIZE����(7��9) 2016.02.01
	out->prev_cls = Str2Int(data->prev_cls, sizeof(data->prev_cls));	// ��������, ����:��, SIZE����(7��9) 2016.02.01
	out->prev_wavg_prc = Str2Int(data->prev_wavg_prc, sizeof(data->prev_wavg_prc));	// ���ϰ�������ְ�, ����:��, SIZE����(7��9) 2016.02.01
	out->pbct_stk_nr = Str2Dbl(data->pbct_stk_nr, sizeof(data->pbct_stk_nr), 0);	// �����ֽļ�, ����:��, SIZE����(12��15) 2016.02.01
	out->pval = Str2Int(data->pval, sizeof(data->pval));	// �׸鰡, ����:��, SIZE����(7��9) 2016.02.01
	memcpy(out->clsg_mth, data->clsg_mth, sizeof(data->clsg_mth));	// ����, MM
	out->clsg_clsf = data->clsg_clsf[0];	//��걸��, 0:�����ֺ���(1-4) 5:1�켱�ֺ��� 6:2�켱�ֺ���
	out->per = Str2Dbl(data->per, sizeof(data->per), 2);	// PER, 9999V99
	out->eps = Str2Int(data->eps, sizeof(data->eps));	// EPS, ����:��, SIZE����(7��9) 2016.02.01
	out->trsp_flg = data->trsp_flg[0];	//�ŷ���������, 0:���� 1:����
	memcpy(out->trsp_rsn, data->trsp_rsn, sizeof(data->trsp_rsn));	// �ŷ���������, ���ڵ尪���� ����
	out->lock_clsf = data->lock_clsf[0];	//������, 0:���� 1:�Ǹ��� 2:�׸���� 3:�׸麴�� 4:���� 5:����\n6:����
	memcpy(out->rgst_aplc, data->rgst_aplc, sizeof(data->rgst_aplc));	// ��Ͻ�û��, �׸��(ASIS ������û��), SIZE����(30��40) 2016.02.01
	memcpy(out->trd_open_date, data->trd_open_date, sizeof(data->trd_open_date));	// �ŸŰ�����, YYYYMMDD
	out->cncl_clsf = data->cncl_clsf[0];	//��������, �׸�� ����(ASIS ��ұ���)\n0:���� 1:���ֺ��տ� ���� ����2:���� �� �������\n(ASIS 0:���� 1:�ű��ֺ��տ� ���� ��� 2:�������)
	out->whyr_hi_prc = Str2Int(data->whyr_hi_prc, sizeof(data->whyr_hi_prc));	// �����ְ�, SIZE����(7��9) 2016.02.01
	out->whyr_lo_prc = Str2Int(data->whyr_lo_prc, sizeof(data->whyr_lo_prc));	// ����������, SIZE����(7��9) 2016.02.01
	memcpy(out->whyr_hi_date, data->whyr_hi_date, sizeof(data->whyr_hi_date));	// �����ְ���, MMDD
	memcpy(out->whyr_lo_date, data->whyr_lo_date, sizeof(data->whyr_lo_date));	// ����������, MMDD
	out->yr_cum_qty = Str2Dbl(data->yr_cum_qty, sizeof(data->yr_cum_qty), 0);	// �������ŷ���, SIZE����(14��17) 2016.02.01
	out->yr_cum_trd_val = Str2Dbl(data->yr_cum_trd_val, sizeof(data->yr_cum_trd_val), 0);	// ������ �ŷ� ���, ����:��, SIZE����(17��18) 2016.02.01
	out->pbl_ofr_clsf = data->pbl_ofr_clsf[0];	//���𱸺�, 0:�����, 1:����
	out->pbl_ofr_prc = Str2Int(data->pbl_ofr_prc, sizeof(data->pbl_ofr_prc));	// ����, ����:��, SIZE����(7��9) 2016.02.01
	out->affl_clsf = data->affl_clsf[0];	//�ҼӺ� ����, 4:��ϱ����,5:���������\n(ASIS 0:�Ϲݱ����, 1:��ó�����)
	out->type_rgst_apnt = data->type_rgst_apnt[0];	//���/��������, -�׸�� ����(ASIS ��������)\n-�� �߰�\n 0:�Ϲ����� 1:�ڽ����̰� 2:���������̰� 3:�ڳؽ��̰�\n (ASIS 0:�Ϲ����� 1:�ڽ����̰� 2:�ŷ����̰�)
	out->prev_vlm = Str2Dbl(data->prev_vlm, sizeof(data->prev_vlm), 0);	// ���ϰŷ���
	out->ceil_prc = Str2Int(data->ceil_prc, sizeof(data->ceil_prc));	// ���Ѱ�, SIZE����(7��9) 2016.02.01
	out->flr_prc = Str2Int(data->flr_prc, sizeof(data->flr_prc));	// ���Ѱ�, SIZE����(7��9) 2016.02.01
	out->iscnt = data->iscnt[0];	//�Ҽ��ǰ���, 0:���� 1~5:�Ҽ��ǰ��� 1ȸ~5ȸ
	
	for ( i=0 ; i<5 ; i++ ) {
		memcpy(&out->iscnt_dates[i].iscnt_apnt_date, &data->iscnt_dates[i].iscnt_apnt_date, sizeof(data->iscnt_dates[i].iscnt_apnt_date));	// �Ҽ��ǰ��� ������, YYYYMMDD
		memcpy(&out->iscnt_dates[i].iscnt_ed_date, &data->iscnt_dates[i].iscnt_ed_date, sizeof(data->iscnt_dates[i].iscnt_ed_date));	// �Ҽ��ǰ��� ������, YYYYMMDD
	}	// �Ҽ��ǰ�����

	out->inv_atn_flg = data->inv_atn_flg[0];	//�������ǿ���, 0:���� 1:��������
	
	for ( i=0 ; i<15 ; i++ ) {
		memcpy(&out->inv_atn_infos[i].inv_atn_rsn_code, &data->inv_atn_infos[i].inv_atn_rsn_code, sizeof(data->inv_atn_infos[i].inv_atn_rsn_code));	// �������� �����ڵ�, �ذ��߰��̵� ����
		memcpy(&out->inv_atn_infos[i].inv_atn_apnt_date, &data->inv_atn_infos[i].inv_atn_apnt_date, sizeof(data->inv_atn_infos[i].inv_atn_apnt_date));	// �������� ������, YYYYMMDD
	}	// ��������

	out->mkt_cap_scale = data->mkt_cap_scale[0];	//�ð��ѾױԸ�, ���������ñ��� SPACE\n(0:���� 1:������ 2:������ 3:������)
	memcpy(out->idx_ind_l, data->idx_ind_l, sizeof(data->idx_ind_l));	// ��������(��), ���������ñ��� SPACE
	memcpy(out->idx_ind_m, data->idx_ind_m, sizeof(data->idx_ind_m));	// ��������(��), ���������ñ��� SPACE
	memcpy(out->idx_ind_s, data->idx_ind_s, sizeof(data->idx_ind_s));	// ��������(��), ���������ñ��� SPACE
	out->vtr_clsf = data->vtr_clsf[0];	//��ó����, 0:�Ϲݱ��, 1:��ó���
	out->trend_clsf = data->trend_clsf[0];	//�⼼����, 0:�Ǽ�,1:�⼼,2:���ŷ�
	out->arng_trd_flg = data->arng_trd_flg[0];	//�����Ÿſ���, 0:����,1:�����Ÿ�

	return 1;
}


// K-OTC ȣ��
int ParseA2013(const double& timestamp, const char* in_buff, DF_KOTC_ASK_PRC* out) {
	KOTC_ASK_PRC* data = (KOTC_ASK_PRC*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����, A2
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������, 01:�ֽ�
	out->mkt_clsf = data->mkt_clsf[0];	//���屸��, 3:K-OTC
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// �����ڵ�, ǥ���ڵ�
	out->data_snr = Str2Int(data->data_snr, sizeof(data->data_snr));	// ������ �Ϸù�ȣ, ȣ��, ü��, ������ġ ������ �Ϸù�ȣ
	out->proc_clsf = data->proc_clsf[0];	//ó������, 1:���� 2:���� 3:���
	out->ask_nr = Str2Int(data->ask_nr, sizeof(data->ask_nr));	// ȣ����ȣ, ���� ó���� ȣ����ȣ
	out->base_ask_nr = Str2Int(data->base_ask_nr, sizeof(data->base_ask_nr));	// ��ȣ����ȣ, ����:0, ����/��ҽ� �ش��ȣ�� ��ȣ
	out->base_ask_prc = Str2Int(data->base_ask_prc, sizeof(data->base_ask_prc));	// ��ȣ������, ����:0, ����/��ҽ� ������, SIZE����(7��9) 2016.02.01
	out->ask_bid_clsf = data->ask_bid_clsf[0];	//�ŵ�/�ż� ����, 1:�ŵ� 2:�ż�
	out->prc = Str2Int(data->prc, sizeof(data->prc));	// ����, ����:�ֹ����� ����:��������, SIZE����(7��9) 2016.02.01
	out->qty = Str2Dbl(data->qty, sizeof(data->qty), 0);	// ����, ����:�ֹ����� ����/���:������/��� ����
	memcpy(out->acpt_time, data->acpt_time, sizeof(data->acpt_time));	// �����ð�
	out->ask_tot_rsd = Str2Dbl(data->ask_tot_rsd, sizeof(data->ask_tot_rsd), 0);	// �ŵ����ܷ�
	out->bid_tot_rsd = Str2Dbl(data->bid_tot_rsd, sizeof(data->bid_tot_rsd), 0);	// �ż����ܷ�
	out->ask_prf_prc = Str2Int(data->ask_prf_prc, sizeof(data->ask_prf_prc));	// �ŵ��켱ȣ��, SIZE����(7��9) 2016.02.01
	out->ask_prf_vol_rsd = Str2Dbl(data->ask_prf_vol_rsd, sizeof(data->ask_prf_vol_rsd), 0);	// �ŵ��켱ȣ���ܷ�
	out->bid_prf_prc = Str2Int(data->bid_prf_prc, sizeof(data->bid_prf_prc));	// �ż��켱ȣ��, SIZE����(7��9) 2016.02.01
	out->bid_prf_vol_rsd = Str2Dbl(data->bid_prf_vol_rsd, sizeof(data->bid_prf_vol_rsd), 0);	// �ż��켱ȣ���ܷ�
	out->prc_band_vol_rsd = Str2Dbl(data->prc_band_vol_rsd, sizeof(data->prc_band_vol_rsd), 0);	// ���ݴ�ȣ���ܷ�, ����:�ֹ��ܷ� ����:�����ܷ�
	out->base_prc_band_vol_rsd = Str2Dbl(data->base_prc_band_vol_rsd, sizeof(data->base_prc_band_vol_rsd), 0);	// �����ݴ�ȣ���ܷ�, ����:0, ����/��ҽ� ���ܷ�
	memcpy(out->brkg_nr, data->brkg_nr, sizeof(data->brkg_nr));	// ���ǻ��ȣ, �ŷ����ڵ� ����
	memcpy(out->brch_nm, data->brch_nm, sizeof(data->brch_nm));	// ������, SPACE

	return 1;
}


// K-OTC ü��
int ParseA3013(const double& timestamp, const char* in_buff, DF_KOTC_CCLS* out) {
	KOTC_CCLS* data = (KOTC_CCLS*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����, A3
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������, 01:�ֽ�
	out->mkt_clsf = data->mkt_clsf[0];	//���屸��, 3:K-OTC
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// �����ڵ�, ǥ���ڵ�
	out->data_snr = Str2Int(data->data_snr, sizeof(data->data_snr));	// ������ �Ϸù�ȣ, ȣ��, ü��, ������ġ ������ �Ϸù�ȣ
	out->ccls_nr = Str2Int(data->ccls_nr, sizeof(data->ccls_nr));	// ü���ȣ, ���� ü���ȣ
	out->ccls_prc = Str2Int(data->ccls_prc, sizeof(data->ccls_prc));	// ü�ᰡ, SIZE����(7��9) 2016.02.01
	out->ccls_qty = Str2Dbl(data->ccls_qty, sizeof(data->ccls_qty), 0);	// ü�ᷮ
	memcpy(out->ccls_time, data->ccls_time, sizeof(data->ccls_time));	// ü��ð�
	out->ask_prc_nr = Str2Int(data->ask_prc_nr, sizeof(data->ask_prc_nr));	// �ŵ�ȣ����ȣ, ���� ȣ����ȣ��
	out->bid_prc_nr = Str2Int(data->bid_prc_nr, sizeof(data->bid_prc_nr));	// �ż�ȣ����ȣ, ���� ȣ����ȣ��
	out->open = Str2Int(data->open, sizeof(data->open));	// ��, SIZE����(7��9) 2016.02.01
	out->hi = Str2Int(data->hi, sizeof(data->hi));	// ����, SIZE����(7��9) 2016.02.01
	out->wavg_prc = Str2Int(data->wavg_prc, sizeof(data->wavg_prc));	// ��������ְ�, SIZE����(7��9) 2016.02.01
	out->tot_ccls_cum_qty = Str2Dbl(data->tot_ccls_cum_qty, sizeof(data->tot_ccls_cum_qty), 0);	// ��üü�ᴩ���ŷ���
	out->tot_ccls_cum_trd_val = Str2Dbl(data->tot_ccls_cum_trd_val, sizeof(data->tot_ccls_cum_trd_val), 0);	// ��üü�ᴩ���ŷ����
	out->ask_tot_rsd = Str2Dbl(data->ask_tot_rsd, sizeof(data->ask_tot_rsd), 0);	// �ŵ����ܷ�
	out->bid_tot_rsd = Str2Dbl(data->bid_tot_rsd, sizeof(data->bid_tot_rsd), 0);	// �ż����ܷ�
	out->ask_prf_prc = Str2Int(data->ask_prf_prc, sizeof(data->ask_prf_prc));	// �ŵ��켱ȣ��, SIZE����(7��9) 2016.02.01
	out->ask_prf_vol_rsd = Str2Dbl(data->ask_prf_vol_rsd, sizeof(data->ask_prf_vol_rsd), 0);	// �ŵ��켱ȣ���ܷ�
	out->bid_prf_prc = Str2Int(data->bid_prf_prc, sizeof(data->bid_prf_prc));	// �ż��켱ȣ��, SIZE����(7��9) 2016.02.01
	out->bid_prf_vol_rsd = Str2Dbl(data->bid_prf_vol_rsd, sizeof(data->bid_prf_vol_rsd), 0);	// �ż��켱ȣ���ܷ�
	out->prev_ctrs_clsf = data->prev_ctrs_clsf[0];	//���ϴ�񱸺�, +:��� -:�϶� SPACE:����
	out->prev_ctrs = Str2Int(data->prev_ctrs, sizeof(data->prev_ctrs));	// ���ϴ��, SIZE����(7��9) 2016.02.01
	out->ccls_prc_ask_rsd = Str2Dbl(data->ccls_prc_ask_rsd, sizeof(data->ccls_prc_ask_rsd), 0);	// ü�ᰡ��ŵ��ܷ�
	out->ccls_prc_bid_rsd = Str2Dbl(data->ccls_prc_bid_rsd, sizeof(data->ccls_prc_bid_rsd), 0);	// ü�ᰡ��ż��ܷ�

	return 1;
}


// K-OTC ���񸶰�
int ParseA6013(const double& timestamp, const char* in_buff, DF_KOTC_STK_CLSG* out) {
	KOTC_STK_CLSG* data = (KOTC_STK_CLSG*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����, A6
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������, 1
	out->mkt_clsf = data->mkt_clsf[0];	//���屸��, 3:K-OTC
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// �����ڵ�, ǥ���ڵ�
	out->data_snr = Str2Int(data->data_snr, sizeof(data->data_snr));	// ������ �Ϸù�ȣ, ȣ��,ü��,�� ������ �Ϸù�ȣ
	out->stk_cls_wght_prc = Str2Int(data->stk_cls_wght_prc, sizeof(data->stk_cls_wght_prc));	// ���񸶰� ���߰�, SIZE����(7��9) 2016.02.01
	out->trend_flg = data->trend_flg[0];	//�Ǽ�/�⼼����, 0:������հ�,1:�⼼,2:���ŷ�

	return 1;
}


// K-OTC ��
int ParseA7013(const double& timestamp, const char* in_buff, DF_KOTC_MKT_OPR* out) {
	KOTC_MKT_OPR* data = (KOTC_MKT_OPR*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����, A7
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������, 01:�ֽ�
	out->mkt_clsf = data->mkt_clsf[0];	//���屸��, 3:K-OTC
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// �����ڵ�, ǥ���ڵ�
	out->data_snr = Str2Int(data->data_snr, sizeof(data->data_snr));	// ������ �Ϸù�ȣ, ȣ��, ü��, ���� ������ �Ϸù�ȣ
	out->clsf = data->clsf[0];	//����, 1:�ŸŰŷ����� 2:�ŸŰŷ�����������
	memcpy(out->rsn, data->rsn, sizeof(data->rsn));	// ����

	return 1;
}


// K-OTC ������ġ
int ParseG5013(const double& timestamp, const char* in_buff, DF_KOTC_MKT_ACT* out) {
	KOTC_MKT_ACT* data = (KOTC_MKT_ACT*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����, G5
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������, 01:�ֽ�
	out->mkt_clsf = data->mkt_clsf[0];	//���屸��, 3:K-OTC
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// �����ڵ�, ǥ���ڵ�
	memcpy(out->data_kind, data->data_kind, sizeof(data->data_kind));	// ������ �з�, 01:���ذ� �� �����Ѱ� ���� 02:�ӽ�����\n03:�ӽ������� �簳
	memcpy(out->chg_date, data->chg_date, sizeof(data->chg_date));	// ������, YYYYMMDD(�����ͺз� 01�� �ƴϸ� "0")
	memcpy(out->chg_time, data->chg_time, sizeof(data->chg_time));	// ����ð�, HHMMSSMM(�����ͺз� 01�� �ƴϸ� "0")
	out->bact_base_prc = Str2Int(data->bact_base_prc, sizeof(data->bact_base_prc));	// ��ġ�� ���ذ�, ����:��(�����ͺз� 01�� �ƴϸ� "0"), \nSIZE����(7��9)  2016.02.01
	out->bact_ceil = Str2Int(data->bact_ceil, sizeof(data->bact_ceil));	// ��ġ�� ���Ѱ�, ����:��(�����ͺз� 01�� �ƴϸ� "0"), \nSIZE����(7��9)  2016.02.01
	out->bact_flr = Str2Int(data->bact_flr, sizeof(data->bact_flr));	// ��ġ�� ���Ѱ�, ����:��(�����ͺз� 01�� �ƴϸ� "0"), \nSIZE����(7��9)  2016.02.01
	out->aact_base_prc = Str2Int(data->aact_base_prc, sizeof(data->aact_base_prc));	// ��ġ�� ���ذ�, ����:��(�����ͺз� 01�� �ƴϸ� "0"), \nSIZE����(7��9)  2016.02.01
	out->aact_ceil = Str2Int(data->aact_ceil, sizeof(data->aact_ceil));	// ��ġ�� ���Ѱ�, ����:��(�����ͺз� 01�� �ƴϸ� "0"), \nSIZE����(7��9)  2016.02.01
	out->aact_flr = Str2Int(data->aact_flr, sizeof(data->aact_flr));	// ��ġ�� ���Ѱ�, ����:��(�����ͺз� 01�� �ƴϸ� "0"), \nSIZE����(7��9)  2016.02.01

	return 1;
}


// K-OTC ���� ��ġ/�ǽð�
int ParseE9013_F0013(const double& timestamp, const char* in_buff, DF_KOTC_DCLS_ARNG_RT* out) {
	KOTC_DCLS_ARNG_RT* data = (KOTC_DCLS_ARNG_RT*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����, E9:���ù�ġ F0:���ýǽð�
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������, 01:�ֽ�
	out->mkt_clsf = data->mkt_clsf[0];	//���屸��, 3:K-OTC
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// �����ڵ�, ��������:999999999999
	out->dcls_snr = Str2Int(data->dcls_snr, sizeof(data->dcls_snr));	// �����Ϸù�ȣ, 000001~999999\n��������:999999
	memcpy(out->rgst_date, data->rgst_date, sizeof(data->rgst_date));	// �������, YYYYMMDD
	out->proc_clsf = data->proc_clsf[0];	//ó������, 1:���� 2:���� 3:���
	memcpy(out->rsn, data->rsn, sizeof(data->rsn));	// ����, �ڵ尪���� ����
	out->line_nr = Str2Int(data->line_nr, sizeof(data->line_nr));	// ���ι�ȣ, 00:���� 01~20:���� 99:END
	memcpy(out->dcls_title, data->dcls_title, sizeof(data->dcls_title));	// ��������/����

	return 1;
}


// KOSDAQ����
int ParseE4012(const double& timestamp, const char* in_buff, DF_KOSDAQ_IDX* out) {
	KOSDAQ_IDX* data = (KOSDAQ_IDX*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����, �ذ��߰��̵� ����
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������, 01:�ֽ�
	out->mkt_clsf = data->mkt_clsf[0];	//���屸��, 1:�������� 2:�ڽ���
	memcpy(out->ind_code, data->ind_code, sizeof(data->ind_code));	// �����ڵ�, �ذ��߰��̵� ����
	memcpy(out->time, data->time, sizeof(data->time));	// �ð�, �ذ��߰��̵� ����
	out->idx = Str2Int(data->idx, sizeof(data->idx));	// ����, 9(6)V9(2)
	out->ctrs = Str2SignDouble(data->sign, sizeof(data->sign) + sizeof(data->ctrs), 2);	// ���, 999999V99
	out->ccls_qty = Str2Int(data->ccls_qty, sizeof(data->ccls_qty));	// ü�����, ����:õ��
	out->trd_val = Str2Int(data->trd_val, sizeof(data->trd_val));	// �ŷ����, ����:�鸸��

	return 1;
}


// KOSDAQ��������
int ParseE5012(const double& timestamp, const char* in_buff, DF_KOSDAQ_EXP_IDX* out) {
	KOSDAQ_EXP_IDX* data = (KOSDAQ_EXP_IDX*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����, �ذ��߰��̵� ����
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������, 01:�ֽ�
	out->mkt_clsf = data->mkt_clsf[0];	//���屸��, 1:�������� 2:�ڽ���
	memcpy(out->ind_code, data->ind_code, sizeof(data->ind_code));	// �����ڵ�, �ذ��߰��̵� ����
	memcpy(out->time, data->time, sizeof(data->time));	// �ð�, �ذ��߰��̵� ����
	out->idx = Str2Int(data->idx, sizeof(data->idx));	// ����, 9(6)V9(2)
	out->ctrs = Str2SignDouble(data->sign, sizeof(data->sign) + sizeof(data->ctrs), 2);	// ���, 999999V99
	out->ccls_qty = Str2Int(data->ccls_qty, sizeof(data->ccls_qty));	// ü�����, ����:õ��
	out->trd_val = Str2Int(data->trd_val, sizeof(data->trd_val));	// �ŷ����, ����:�鸸��

	return 1;
}


// �ڽ���_�ŷ���
int ParseB9012(const double& timestamp, const char* in_buff, DF_KOSDAQ_TRS* out) {
	int i=0;
	KOSDAQ_TRS* data = (KOSDAQ_TRS*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����, B9
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������, 01:�ֽ� 02:ELW
	out->mkt_clsf = data->mkt_clsf[0];	//���屸��, 1:�������� 2:�ڽ���
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// �����ڵ�, ǥ���ڵ�
	out->snr = Str2Int(data->snr, sizeof(data->snr));	// �Ϸù�ȣ, 1~99999999 �����Ϸù�ȣ 2014.03.03

	for ( i=0 ; i<5 ; i++ ) {
		out->src_infos[i].ask_src_nr = Str2Int(data->src_infos[i].ask_src_nr, sizeof(data->src_infos[i].ask_src_nr)); // �ŵ��ŷ�����ȣ
		out->src_infos[i].ask_ccls_qty = Str2Dbl(data->src_infos[i].ask_ccls_qty, sizeof(data->src_infos[i].ask_ccls_qty), 0);	// �ŵ�ü�����, ����:��
		out->src_infos[i].ask_trd_val = Str2Dbl(data->src_infos[i].ask_trd_val, sizeof(data->src_infos[i].ask_trd_val), 0);	// �ŵ��ŷ����, ����:��
		out->src_infos[i].bid_src_nr = Str2Int(data->src_infos[i].bid_src_nr, sizeof(data->src_infos[i].bid_src_nr));	// �ż��ŷ�����ȣ
		out->src_infos[i].bid_ccls_qty = Str2Dbl(data->src_infos[i].bid_ccls_qty, sizeof(data->src_infos[i].bid_ccls_qty), 0);	// �ż�ü�����, ����:��
		out->src_infos[i].bid_trd_val = Str2Dbl(data->src_infos[i].bid_trd_val, sizeof(data->src_infos[i].bid_trd_val), 0);	// �ż��ŷ����, ����:��
	}	// �ŷ������� OCCURS

	return 1;
}


// �ڽ���_���������ں� ����
int ParseC1012(const double& timestamp, const char* in_buff, DF_KOSDAQ_BYSTK_BYINV_CLS* out) {
	int i=0;
	KOSDAQ_BYSTK_BYINV_CLS* data = (KOSDAQ_BYSTK_BYINV_CLS*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����, C1
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������, 01:�ֽ� 02:ELW
	out->mkt_clsf = data->mkt_clsf[0];	//���屸��, 1:�������� 2:�ڽ���
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// �����ڵ�, ǥ���ڵ�
	out->snr = Str2Int(data->snr, sizeof(data->snr));	// �Ϸù�ȣ, 1~99999999 �����Ϸù�ȣ 2014.03.03

    for ( i=0 ; i<12 ; i++ ) {
		memcpy(&out->inv_infos[i].inv_code, &data->inv_infos[i].inv_code, sizeof(data->inv_infos[i].inv_code));	// �������ڵ�, ���ڵ尪���� ����\n*�ڵ�'7000'�� ����, ������� �׸� 0���� ���� (20181210)
		out->inv_infos[i].ask_ccls_qty = Str2Dbl(data->inv_infos[i].ask_ccls_qty, sizeof(data->inv_infos[i].ask_ccls_qty), 0);	// �ŵ�ü�����, ����:��
		out->inv_infos[i].ask_trd_val = Str2Dbl(data->inv_infos[i].ask_trd_val, sizeof(data->inv_infos[i].ask_trd_val), 0);	// �ŵ��ŷ����, ����:��
		out->inv_infos[i].bid_ccls_qty = Str2Dbl(data->inv_infos[i].bid_ccls_qty, sizeof(data->inv_infos[i].bid_ccls_qty), 0);	// �ż�ü�����, ����:��
		out->inv_infos[i].bid_trd_val = Str2Dbl(data->inv_infos[i].bid_trd_val, sizeof(data->inv_infos[i].bid_trd_val), 0);	// �ż��ŷ����, ����:��
	}	// ������ OCCURS 12

	return 1;
}


// �ڽ���_���α׷��Ÿ� ȣ��
int ParseC3012(const double& timestamp, const char* in_buff, DF_KOSDAQ_PRGTRD_ASK* out) {
	KOSDAQ_PRGTRD_ASK* data = (KOSDAQ_PRGTRD_ASK*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����, C3
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������, 01:�ֽ�
	out->mkt_clsf = data->mkt_clsf[0];	//���屸��, 1:�������� 2:�ڽ���
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// �����ڵ�
	out->snr = Str2Int(data->snr, sizeof(data->snr));	// �Ϸù�ȣ, 1~99999999 �����Ϸù�ȣ 2014.03.03
	out->idx_abtg_ask_rsd = Str2Dbl(data->idx_abtg_ask_rsd, sizeof(data->idx_abtg_ask_rsd), 0);	// �������͸ŵ�ȣ���ܷ�
	out->idx_abtg_bid_rsd = Str2Dbl(data->idx_abtg_bid_rsd, sizeof(data->idx_abtg_bid_rsd), 0);	// �������͸ż�ȣ���ܷ�
	out->idx_nabtg_ask_rsd = Str2Dbl(data->idx_nabtg_ask_rsd, sizeof(data->idx_nabtg_ask_rsd), 0);	// ���������͸ŵ�ȣ���ܷ�
	out->idx_nabtg_bid_rsd = Str2Dbl(data->idx_nabtg_bid_rsd, sizeof(data->idx_nabtg_bid_rsd), 0);	// ���������͸ż�ȣ���ܷ�
	out->idx_abtg_ask_qty = Str2Dbl(data->idx_abtg_ask_qty, sizeof(data->idx_abtg_ask_qty), 0);	// �������͸ŵ�ȣ������
	out->idx_abtg_bid_qty = Str2Dbl(data->idx_abtg_bid_qty, sizeof(data->idx_abtg_bid_qty), 0);	// �������͸ż�ȣ������
	out->idx_nabtg_ask_qty = Str2Dbl(data->idx_nabtg_ask_qty, sizeof(data->idx_nabtg_ask_qty), 0);	// ���������͸ŵ�ȣ������
	out->idx_nabtg_bid_qty = Str2Dbl(data->idx_nabtg_bid_qty, sizeof(data->idx_nabtg_bid_qty), 0);	// ���������͸ż�ȣ������
	out->prior_idx_abtg_ask_rsd = Str2Dbl(data->prior_idx_abtg_ask_rsd, sizeof(data->prior_idx_abtg_ask_rsd), 0);	// �������͸ŵ�ȣ���ܷ�
	out->prior_idx_abtg_bid_rsd = Str2Dbl(data->prior_idx_abtg_bid_rsd, sizeof(data->prior_idx_abtg_bid_rsd), 0);	// �������͸ż�ȣ���ܷ�
	out->prior_idx_nabtg_ask_rsd = Str2Dbl(data->prior_idx_nabtg_ask_rsd, sizeof(data->prior_idx_nabtg_ask_rsd), 0);	// ���������͸ŵ�ȣ���ܷ�
	out->prior_idx_nabtg_bid_rsd = Str2Dbl(data->prior_idx_nabtg_bid_rsd, sizeof(data->prior_idx_nabtg_bid_rsd), 0);	// ���������͸ż�ȣ���ܷ�
	out->idx_abtg_ask_ccls_qty = Str2Dbl(data->idx_abtg_ask_ccls_qty, sizeof(data->idx_abtg_ask_ccls_qty), 0);	// "�������͸ŵ���Ź ü�����"
	out->idx_abtg_ask_self_ccls_qty = Str2Dbl(data->idx_abtg_ask_self_ccls_qty, sizeof(data->idx_abtg_ask_self_ccls_qty), 0);	// "�������͸ŵ��ڱ� ü�����"
	out->idx_abtg_bid_ccls_qty = Str2Dbl(data->idx_abtg_bid_ccls_qty, sizeof(data->idx_abtg_bid_ccls_qty), 0);	// "�������͸ż���Ź ü�����"
	out->idx_abtg_bid_self_ccls_qty = Str2Dbl(data->idx_abtg_bid_self_ccls_qty, sizeof(data->idx_abtg_bid_self_ccls_qty), 0);	// "�������͸ż��ڱ� ü�����"
	out->idx_nabtg_ask_ccls_qty = Str2Dbl(data->idx_nabtg_ask_ccls_qty, sizeof(data->idx_nabtg_ask_ccls_qty), 0);	// "���������͸ŵ���Ź ü�����"
	out->idx_nabtg_ask_self_ccls_qty = Str2Dbl(data->idx_nabtg_ask_self_ccls_qty, sizeof(data->idx_nabtg_ask_self_ccls_qty), 0);	// "���������͸ŵ��ڱ� ü�����"
	out->idx_nabtg_bid_ccls_qty = Str2Dbl(data->idx_nabtg_bid_ccls_qty, sizeof(data->idx_nabtg_bid_ccls_qty), 0);	// "���������͸ż���Ź ü�����"
	out->idx_nabtg_bid_self_ccls_qty = Str2Dbl(data->idx_nabtg_bid_self_ccls_qty, sizeof(data->idx_nabtg_bid_self_ccls_qty), 0);	// "���������͸ż��ڱ� ü�����"
	out->idx_abtg_ask_ccls_val = Str2Dbl(data->idx_abtg_ask_ccls_val, sizeof(data->idx_abtg_ask_ccls_val), 0);	// "�������͸ŵ���Ź ü��ݾ�"
	out->idx_abtg_ask_self_ccls_val = Str2Dbl(data->idx_abtg_ask_self_ccls_val, sizeof(data->idx_abtg_ask_self_ccls_val), 0);	// "�������͸ŵ��ڱ� ü��ݾ�"
	out->idx_abtg_bid_ccls_val = Str2Dbl(data->idx_abtg_bid_ccls_val, sizeof(data->idx_abtg_bid_ccls_val), 0);	// "�������͸ż���Ź ü��ݾ�"
	out->idx_abtg_bid_self_ccls_val = Str2Dbl(data->idx_abtg_bid_self_ccls_val, sizeof(data->idx_abtg_bid_self_ccls_val), 0);	// "�������͸ż��ڱ� ü��ݾ�"
	out->idx_nabtg_ask_ccls_val = Str2Dbl(data->idx_nabtg_ask_ccls_val, sizeof(data->idx_nabtg_ask_ccls_val), 0);	// "���������͸ŵ���Ź ü��ݾ�"
	out->idx_nabtg_ask_self_ccls_val = Str2Dbl(data->idx_nabtg_ask_self_ccls_val, sizeof(data->idx_nabtg_ask_self_ccls_val), 0);	// "���������͸ŵ��ڱ� ü��ݾ�"
	out->idx_nabtg_bid_ccls_val = Str2Dbl(data->idx_nabtg_bid_ccls_val, sizeof(data->idx_nabtg_bid_ccls_val), 0);	// "���������͸ż���Ź ü��ݾ�"
	out->idx_nabtg_bid_self_ccls_val = Str2Dbl(data->idx_nabtg_bid_self_ccls_val, sizeof(data->idx_nabtg_bid_self_ccls_val), 0);	// "���������͸ż��ڱ� ü��ݾ�"
	out->post_idx_abtg_ask_rsd = Str2Dbl(data->post_idx_abtg_ask_rsd, sizeof(data->post_idx_abtg_ask_rsd), 0);	// �������͸ŵ�ȣ���ܷ�, 2011.05.30 �ű�
	out->post_idx_abtg_bid_rsd = Str2Dbl(data->post_idx_abtg_bid_rsd, sizeof(data->post_idx_abtg_bid_rsd), 0);	// �������͸ż�ȣ���ܷ�, 2011.05.30 �ű�
	out->post_idx_nabtg_ask_rsd = Str2Dbl(data->post_idx_nabtg_ask_rsd, sizeof(data->post_idx_nabtg_ask_rsd), 0);	// ���������͸ŵ�ȣ���ܷ�, 2011.05.30 �ű�
	out->post_idx_nabtg_bid_rsd = Str2Dbl(data->post_idx_nabtg_bid_rsd, sizeof(data->post_idx_nabtg_bid_rsd), 0);	// ���������͸ż�ȣ���ܷ�, 2011.05.30 �ű�

	return 1;
}


// �ڽ���_���α׷��Ÿ� ��ü����
int ParseJ0012(const double& timestamp, const char* in_buff, DF_KOSDAQ_PRGTRD_TOT* out) {
	KOSDAQ_PRGTRD_TOT* data = (KOSDAQ_PRGTRD_TOT*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����, J0
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������, 01:�ֽ�
	out->mkt_clsf = data->mkt_clsf[0];	//���屸��, 1:�������� 2:�ڽ���
	out->idx_abtg_ask_rsd = Str2Dbl(data->idx_abtg_ask_rsd, sizeof(data->idx_abtg_ask_rsd), 0);	// �������͸ŵ�ȣ���ܷ�
	out->idx_abtg_bid_rsd = Str2Dbl(data->idx_abtg_bid_rsd, sizeof(data->idx_abtg_bid_rsd), 0);	// �������͸ż�ȣ���ܷ�
	out->idx_nabtg_ask_rsd = Str2Dbl(data->idx_nabtg_ask_rsd, sizeof(data->idx_nabtg_ask_rsd), 0);	// ���������͸ŵ�ȣ���ܷ�
	out->idx_nabtg_bid_rsd = Str2Dbl(data->idx_nabtg_bid_rsd, sizeof(data->idx_nabtg_bid_rsd), 0);	// ���������͸ż�ȣ���ܷ�
	out->idx_abtg_ask_qty = Str2Dbl(data->idx_abtg_ask_qty, sizeof(data->idx_abtg_ask_qty), 0);	// �������͸ŵ�ȣ������
	out->idx_abtg_bid_qty = Str2Dbl(data->idx_abtg_bid_qty, sizeof(data->idx_abtg_bid_qty), 0);	// �������͸ż�ȣ������
	out->idx_nabtg_ask_qty = Str2Dbl(data->idx_nabtg_ask_qty, sizeof(data->idx_nabtg_ask_qty), 0);	// ���������͸ŵ�ȣ������
	out->idx_nabtg_bid_qty = Str2Dbl(data->idx_nabtg_bid_qty, sizeof(data->idx_nabtg_bid_qty), 0);	// ���������͸ż�ȣ������
	out->prior_idx_abtg_ask_rsd = Str2Dbl(data->prior_idx_abtg_ask_rsd, sizeof(data->prior_idx_abtg_ask_rsd), 0);	// �������͸ŵ�ȣ���ܷ�
	out->prior_idx_abtg_bid_rsd = Str2Dbl(data->prior_idx_abtg_bid_rsd, sizeof(data->prior_idx_abtg_bid_rsd), 0);	// �������͸ż�ȣ���ܷ�
	out->prior_idx_nabtg_ask_rsd = Str2Dbl(data->prior_idx_nabtg_ask_rsd, sizeof(data->prior_idx_nabtg_ask_rsd), 0);	// ���������͸ŵ�ȣ���ܷ�
	out->prior_idx_nabtg_bid_rsd = Str2Dbl(data->prior_idx_nabtg_bid_rsd, sizeof(data->prior_idx_nabtg_bid_rsd), 0);	// ���������͸ż�ȣ���ܷ�
	out->idx_abtg_ask_ccls_qty = Str2Dbl(data->idx_abtg_ask_ccls_qty, sizeof(data->idx_abtg_ask_ccls_qty), 0);	// "�������͸ŵ���Ź ü�����"
	out->idx_abtg_ask_self_ccls_qty = Str2Dbl(data->idx_abtg_ask_self_ccls_qty, sizeof(data->idx_abtg_ask_self_ccls_qty), 0);	// "�������͸ŵ��ڱ� ü�����"
	out->idx_abtg_bid_ccls_qty = Str2Dbl(data->idx_abtg_bid_ccls_qty, sizeof(data->idx_abtg_bid_ccls_qty), 0);	// "�������͸ż���Ź ü�����"
	out->idx_abtg_bid_self_ccls_qty = Str2Dbl(data->idx_abtg_bid_self_ccls_qty, sizeof(data->idx_abtg_bid_self_ccls_qty), 0);	// "�������͸ż��ڱ� ü�����"
	out->idx_nabtg_ask_ccls_qty = Str2Dbl(data->idx_nabtg_ask_ccls_qty, sizeof(data->idx_nabtg_ask_ccls_qty), 0);	// "���������͸ŵ���Ź ü�����"
	out->idx_nabtg_ask_self_ccls_qty = Str2Dbl(data->idx_nabtg_ask_self_ccls_qty, sizeof(data->idx_nabtg_ask_self_ccls_qty), 0);	// "���������͸ŵ��ڱ� ü�����"
	out->idx_nabtg_bid_ccls_qty = Str2Dbl(data->idx_nabtg_bid_ccls_qty, sizeof(data->idx_nabtg_bid_ccls_qty), 0);	// "���������͸ż���Ź ü�����"
	out->idx_nabtg_bid_self_ccls_qty = Str2Dbl(data->idx_nabtg_bid_self_ccls_qty, sizeof(data->idx_nabtg_bid_self_ccls_qty), 0);	// "���������͸ż��ڱ� ü�����"
	out->idx_abtg_ask_ccls_val = Str2Dbl(data->idx_abtg_ask_ccls_val, sizeof(data->idx_abtg_ask_ccls_val), 0);	// "�������͸ŵ���Ź ü��ݾ�"
	out->idx_abtg_ask_self_ccls_val = Str2Dbl(data->idx_abtg_ask_self_ccls_val, sizeof(data->idx_abtg_ask_self_ccls_val), 0);	// "�������͸ŵ��ڱ� ü��ݾ�"
	out->idx_abtg_bid_ccls_val = Str2Dbl(data->idx_abtg_bid_ccls_val, sizeof(data->idx_abtg_bid_ccls_val), 0);	// "�������͸ż���Ź ü��ݾ�"
	out->idx_abtg_bid_self_ccls_val = Str2Dbl(data->idx_abtg_bid_self_ccls_val, sizeof(data->idx_abtg_bid_self_ccls_val), 0);	// "�������͸ż��ڱ� ü��ݾ�"
	out->idx_nabtg_ask_ccls_val = Str2Dbl(data->idx_nabtg_ask_ccls_val, sizeof(data->idx_nabtg_ask_ccls_val), 0);	// "���������͸ŵ���Ź ü��ݾ�"
	out->idx_nabtg_ask_self_ccls_val = Str2Dbl(data->idx_nabtg_ask_self_ccls_val, sizeof(data->idx_nabtg_ask_self_ccls_val), 0);	// "���������͸ŵ��ڱ� ü��ݾ�"
	out->idx_nabtg_bid_ccls_val = Str2Dbl(data->idx_nabtg_bid_ccls_val, sizeof(data->idx_nabtg_bid_ccls_val), 0);	// "���������͸ż���Ź ü��ݾ�"
	out->idx_nabtg_bid_self_ccls_val = Str2Dbl(data->idx_nabtg_bid_self_ccls_val, sizeof(data->idx_nabtg_bid_self_ccls_val), 0);	// "���������͸ż��ڱ� ü��ݾ�"
	out->post_idx_abtg_ask_rsd = Str2Dbl(data->post_idx_abtg_ask_rsd, sizeof(data->post_idx_abtg_ask_rsd), 0);	// �������͸ŵ�ȣ���ܷ�
	out->post_idx_abtg_bid_rsd = Str2Dbl(data->post_idx_abtg_bid_rsd, sizeof(data->post_idx_abtg_bid_rsd), 0);	// �������͸ż�ȣ���ܷ�
	out->post_idx_nabtg_ask_rsd = Str2Dbl(data->post_idx_nabtg_ask_rsd, sizeof(data->post_idx_nabtg_ask_rsd), 0);	// ���������͸ŵ�ȣ���ܷ�
	out->post_idx_nabtg_bid_rsd = Str2Dbl(data->post_idx_nabtg_bid_rsd, sizeof(data->post_idx_nabtg_bid_rsd), 0);	// ���������͸ż�ȣ���ܷ�

	return 1;
}


// �ڽ���_���α׷��Ÿ� �������İ���
int ParseC5012(const double& timestamp, const char* in_buff, DF_KOSDAQ_PRGTRD_DCLS* out) {
	KOSDAQ_PRGTRD_DCLS* data = (KOSDAQ_PRGTRD_DCLS*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����, C5
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������, 01:�ֽ�
	out->mkt_clsf = data->mkt_clsf[0];	//���屸��, 1:�������� 2:�ڽ���
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// �����ڵ�
	out->snr = Str2Int(data->snr, sizeof(data->snr));	// �Ϸù�ȣ, 1~99999999 �����Ϸù�ȣ 2014.03.03
	out->prior_dcls_new_ask_qty = Str2Dbl(data->prior_dcls_new_ask_qty, sizeof(data->prior_dcls_new_ask_qty), 0);	// "�������ýű�ȣ�� �ŵ�����", ���� : ��\n�׸����:�ŵ����û�������->�������ýű�ȣ���ŵ�����
	out->prior_dcls_new_bid_qty = Str2Dbl(data->prior_dcls_new_bid_qty, sizeof(data->prior_dcls_new_bid_qty), 0);	// "�������ýű�ȣ�� �ż�����", ���� : ��\n�׸����:�ż����û�������->�������ýű�ȣ���ż�����
	out->prior_dcls_sbmt_ask_qty = Str2Dbl(data->prior_dcls_sbmt_ask_qty, sizeof(data->prior_dcls_sbmt_ask_qty), 0);	// "�������ñ�����ȣ�� �ŵ�����", ���� : ��\n�׸����:�ŵ����û�����������->�������ñ�����ȣ���ŵ�����
	out->prior_dcls_sbmt_bid_qty = Str2Dbl(data->prior_dcls_sbmt_bid_qty, sizeof(data->prior_dcls_sbmt_bid_qty), 0);	// "�������ñ�����ȣ�� �ż�����", ���� : ��\n�׸����:�ż����û�����������->�������ñ�����ȣ���ż�����
	out->post_dcls_ask_qty = Str2Dbl(data->post_dcls_ask_qty, sizeof(data->post_dcls_ask_qty), 0);	// ���İ��øŵ�����, ���� : ��,  �ű�				2011.05.03
	out->post_dcls_bid_qty = Str2Dbl(data->post_dcls_bid_qty, sizeof(data->post_dcls_bid_qty), 0);	// ���İ��øż�����, ���� : ��,  �ű�				2011.05.03

	return 1;
}


// �ڽ��� ���α׷��Ÿ� �����ں� �Ÿ���Ȳ
int ParseP0012(const double& timestamp, const char* in_buff, DF_KOSDAQ_PRGTRD_BYINV_STAT* out) {
	KOSDAQ_PRGTRD_BYINV_STAT* data = (KOSDAQ_PRGTRD_BYINV_STAT*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����, P0
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������, 01:�ֽ�
	out->mkt_clsf = data->mkt_clsf[0];	//���屸��, 1:�������� 2:�ڽ���
	memcpy(out->cmpt_time, data->cmpt_time, sizeof(data->cmpt_time));	// ����ð�, 90�� �ֱ�
	memcpy(out->inv_clsf_code, data->inv_clsf_code, sizeof(data->inv_clsf_code));	// �����ڱ����ڵ�, ���ڵ尪���� ����\n*�ڵ�'7000'�� ����, ������� �׸� 0���� ���� (20181210)
	out->ask_abtg_ccls_qty = Str2Dbl(data->ask_abtg_ccls_qty, sizeof(data->ask_abtg_ccls_qty), 0);	// �ŵ�����ü�����
	out->ask_abtg_trd_val = Str2Dbl(data->ask_abtg_trd_val, sizeof(data->ask_abtg_trd_val), 0);	// �ŵ����Ͱŷ����
	out->ask_nabtg_ccls_qty = Str2Dbl(data->ask_nabtg_ccls_qty, sizeof(data->ask_nabtg_ccls_qty), 0);	// �ŵ�������ü�����
	out->ask_nabtg_trd_val = Str2Dbl(data->ask_nabtg_trd_val, sizeof(data->ask_nabtg_trd_val), 0);	// �ŵ������Ͱŷ����
	out->bid_abtg_ccls_qty = Str2Dbl(data->bid_abtg_ccls_qty, sizeof(data->bid_abtg_ccls_qty), 0);	// �ż�����ü�����
	out->bid_abtg_trd_val = Str2Dbl(data->bid_abtg_trd_val, sizeof(data->bid_abtg_trd_val), 0);	// �ż����Ͱŷ����
	out->bid_nabtg_ccls_qty = Str2Dbl(data->bid_nabtg_ccls_qty, sizeof(data->bid_nabtg_ccls_qty), 0);	// �ż�������ü�����
	out->bid_nabtg_trd_val = Str2Dbl(data->bid_nabtg_trd_val, sizeof(data->bid_nabtg_trd_val), 0);	// �ż������Ͱŷ����

	return 1;
}


// �ڽ���_�����������(VI)
int ParseR8012(const double& timestamp, const char* in_buff, DF_KOSDAQ_STK_STAT_INFO* out) {
	KOSDAQ_STK_STAT_INFO* data = (KOSDAQ_STK_STAT_INFO*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����, R8
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������, 01:�ֽ�
	out->mkt_clsf = data->mkt_clsf[0];	//���屸��, 1:�������� 2:�ڽ���
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// �����ڵ�
	out->stk_snr = Str2Int(data->stk_snr, sizeof(data->stk_snr));	// �����Ϸù�ȣ, �����ġ(A0)�� �����Ϸù�ȣ
	memcpy(out->brd_id, data->brd_id, sizeof(data->brd_id));	// ����ID, �� �ڵ尪���� ����
	out->trd_ccls_proc_time = Str2Int(data->trd_ccls_proc_time, sizeof(data->trd_ccls_proc_time));	// �Ÿ�ü��ó���ð�, �Ÿ�ü��ó���ð�
	out->vi_cncl_time = Str2Int(data->vi_cncl_time, sizeof(data->vi_cncl_time));	// VI�����ð�
	out->vi_aply_clsf_code = data->vi_aply_clsf_code[0];	//VI���뱸���ڵ�, 1:VI-�ߵ�, 2:VI-����
	out->vi_type_code = Str2Int(data->vi_type_code, sizeof(data->vi_type_code));	// VI�����ڵ�, 1:����VI, 2:����VI, 3:����&����VI
	out->stt_vi_base_prc = Str2Int(data->stt_vi_base_prc, sizeof(data->stt_vi_base_prc));	// ����VI�ߵ����ذ���
	out->dyn_vi_base_prc = Str2Int(data->dyn_vi_base_prc, sizeof(data->dyn_vi_base_prc));	// ����VI�ߵ����ذ���
	out->vi_prc = Str2Int(data->vi_prc, sizeof(data->vi_prc));	// VI�ߵ�����
	memcpy(out->stt_vi_dspr, data->stt_vi_dspr, sizeof(data->stt_vi_dspr));	// ����VI�ߵ�������, ����VI�ߵ� ������\n��ȣ�ڸ�(���:0, ����:-) + 99999.999999(��ȿ���� 12�ڸ�)
	memcpy(out->dyn_vi_dspr, data->dyn_vi_dspr, sizeof(data->dyn_vi_dspr));	// ����VI�ߵ�������, ����VI�ߵ� ������\n��ȣ�ڸ�(���:0, ����:-) + 99999.999999(��ȿ���� 12�ڸ�)

	return 1;
}
