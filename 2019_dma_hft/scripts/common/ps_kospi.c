// ps_kospi.c
// ���������ֽ�
// �ּ��� \n�� ���� ���߿� �̻ڰ� �ٲ����

#include "ps_kospi.h"


// KRX 300 TR��������
int ParseBD011(const double& timestamp, const char* in_buff, DF_KRX300_TR_EXP_IDX* out) {
	KRX300_TR_EXP_IDX* data = (KRX300_TR_EXP_IDX*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����, �ذ��߰��̵� ����
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������, 01:�ֽ�
	out->mkt_clsf = data->mkt_clsf[0];	//���屸��, 1:�������� 2:�ڽ��� 9:�ؿ��ְ����� 2012.04.30 �߰�
	memcpy(out->ind_clsf, data->ind_clsf, sizeof(data->ind_clsf));	// �����ڵ�, �ذ��߰��̵� ����
	memcpy(out->time, data->time, sizeof(data->time));	// �ð�, �ذ��߰��̵� ���� ���ؿ��ְ������� ��� GMT�ð�
	out->idx = Str2Dbl(data->idx, sizeof(data->idx), 2);	// ����, 9(6)V9(2)
	out->crst = Str2SignDouble(data->sign, sizeof(data->sign) + sizeof(data->crst), 2);	// ���, 999999V99
	out->ccls_qty = Str2Int(data->ccls_qty, sizeof(data->ccls_qty));	// ü�����, ����:õ�� ���ؿ��ְ������� ��� FILLERó��
	out->trd_val = Str2Int(data->trd_val, sizeof(data->trd_val));	// �ŷ����, ����:�鸸�� ���ؿ��ְ������� ��� FILLERó��

	return 1;
}


// KRX 300 TR����
int ParseBC011(const double& timestamp, const char* in_buff, DF_KRX300_TR_IDX* out) {
	KRX300_TR_IDX* data = (KRX300_TR_IDX*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����, �ذ��߰��̵� ����
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������, 01:�ֽ�
	out->mkt_clsf = data->mkt_clsf[0];	//���屸��, 1:�������� 2:�ڽ��� 9:�ؿ��ְ����� 2012.04.30 �߰�
	memcpy(out->ind_clsf, data->ind_clsf, sizeof(data->ind_clsf));	// �����ڵ�, �ذ��߰��̵� ����
	memcpy(out->time, data->time, sizeof(data->time));	// �ð�, �ذ��߰��̵� ���� ���ؿ��ְ������� ��� GMT�ð�
	out->idx = Str2Dbl(data->idx, sizeof(data->idx), 2);	// ����, 9(6)V9(2)
	out->crst = Str2SignDouble(data->sign, sizeof(data->sign) + sizeof(data->crst), 2);	// ���, 999999V99
	out->ccls_qty = Str2Int(data->ccls_qty, sizeof(data->ccls_qty));	// ü�����, ����:õ�� ���ؿ��ְ������� ��� FILLERó��
	out->trd_val = Str2Int(data->trd_val, sizeof(data->trd_val));	// �ŷ����, ����:�鸸�� ���ؿ��ְ������� ��� FILLERó��

	return 1;
}


// �ڽ��� TR��������
int ParseAX011(const double& timestamp, const char* in_buff, DF_KOSPI_TR_EXP_IDX* out) {
	KOSPI_TR_EXP_IDX* data = (KOSPI_TR_EXP_IDX*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����, �ذ��߰��̵� ����
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������, 01:�ֽ�
	out->mkt_clsf = data->mkt_clsf[0];	//���屸��, 1:�������� 2:�ڽ��� 9:�ؿ��ְ����� 2012.04.30 �߰�
	memcpy(out->ind_clsf, data->ind_clsf, sizeof(data->ind_clsf));	// �����ڵ�, �ذ��߰��̵� ����
	memcpy(out->time, data->time, sizeof(data->time));	// �ð�, �ذ��߰��̵� ���� ���ؿ��ְ������� ��� GMT�ð�
	out->idx = Str2Dbl(data->idx, sizeof(data->idx), 2);	// ����, 9(6)V9(2)
	out->crst = Str2SignDouble(data->sign, sizeof(data->sign) + sizeof(data->crst), 2);	// ���, 999999V99
	out->ccls_qty = Str2Int(data->ccls_qty, sizeof(data->ccls_qty));	// ü�����, ����:õ�� ���ؿ��ְ������� ��� FILLERó��
	out->trd_val = Str2Int(data->trd_val, sizeof(data->trd_val));	// �ŷ����, ����:�鸸�� ���ؿ��ְ������� ��� FILLERó��

	return 1;
}


// �ڽ��� TR����
int ParseAW011(const double& timestamp, const char* in_buff, DF_KOSPI_TR_IDX* out) {
	KOSPI_TR_IDX* data = (KOSPI_TR_IDX*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����, �ذ��߰��̵� ����
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������, 01:�ֽ�
	out->mkt_clsf = data->mkt_clsf[0];	//���屸��, 1:�������� 2:�ڽ��� 9:�ؿ��ְ����� 2012.04.30 �߰�
	memcpy(out->ind_clsf, data->ind_clsf, sizeof(data->ind_clsf));	// �����ڵ�, �ذ��߰��̵� ����
	memcpy(out->time, data->time, sizeof(data->time));	// �ð�, �ذ��߰��̵� ���� ���ؿ��ְ������� ��� GMT�ð�
	out->idx = Str2Dbl(data->idx, sizeof(data->idx), 2);	// ����, 9(6)V9(2)
	out->crst = Str2SignDouble(data->sign, sizeof(data->sign) + sizeof(data->crst), 2);	// ���, 999999V99
	out->ccls_qty = Str2Int(data->ccls_qty, sizeof(data->ccls_qty));	// ü�����, ����:õ�� ���ؿ��ְ������� ��� FILLERó��
	out->trd_val = Str2Int(data->trd_val, sizeof(data->trd_val));	// �ŷ����, ����:�鸸�� ���ؿ��ְ������� ��� FILLERó��

	return 1;
}


// KRX300��������
int ParseAB011(const double& timestamp, const char* in_buff, DF_KRX300_EXP_IDX* out) {
	KRX300_EXP_IDX* data = (KRX300_EXP_IDX*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����, �ذ��߰��̵� ����
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������, 01:�ֽ�
	out->mkt_clsf = data->mkt_clsf[0];	//���屸��, 1:�������� 2:�ڽ��� 9:�ؿ��ְ����� 2012.04.30 �߰�
	memcpy(out->ind_clsf, data->ind_clsf, sizeof(data->ind_clsf));	// �����ڵ�, �ذ��߰��̵� ����
	memcpy(out->time, data->time, sizeof(data->time));	// �ð�, �ذ��߰��̵� ���� ���ؿ��ְ������� ��� GMT�ð�
	out->idx = Str2Dbl(data->idx, sizeof(data->idx), 2);	// ����, 9(6)V9(2)
	out->crst = Str2SignDouble(data->sign, sizeof(data->sign) + sizeof(data->crst), 2);	// ���, 999999V99
	out->ccls_qty = Str2Int(data->ccls_qty, sizeof(data->ccls_qty));	// ü�����, ����:õ�� ���ؿ��ְ������� ��� FILLERó��
	out->trd_val = Str2Int(data->trd_val, sizeof(data->trd_val));	// �ŷ����, ����:�鸸�� ���ؿ��ְ������� ��� FILLERó��

	return 1;
}


// KRX300����
int ParseAA011(const double& timestamp, const char* in_buff, DF_KRX300_IDX* out) {
	KRX300_IDX* data = (KRX300_IDX*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����, �ذ��߰��̵� ����
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������, 01:�ֽ�
	out->mkt_clsf = data->mkt_clsf[0];	//���屸��, 1:�������� 2:�ڽ��� 9:�ؿ��ְ����� 2012.04.30 �߰�
	memcpy(out->ind_clsf, data->ind_clsf, sizeof(data->ind_clsf));	// �����ڵ�, �ذ��߰��̵� ����
	memcpy(out->time, data->time, sizeof(data->time));	// �ð�, �ذ��߰��̵� ���� ���ؿ��ְ������� ��� GMT�ð�
	out->idx = Str2Dbl(data->idx, sizeof(data->idx), 2);	// ����, 9(6)V9(2)
	out->crst = Str2SignDouble(data->sign, sizeof(data->sign) + sizeof(data->crst), 2);	// ���, 999999V99
	out->ccls_qty = Str2Int(data->ccls_qty, sizeof(data->ccls_qty));	// ü�����, ����:õ�� ���ؿ��ְ������� ��� FILLERó��
	out->trd_val = Str2Int(data->trd_val, sizeof(data->trd_val));	// �ŷ����, ����:�鸸�� ���ؿ��ְ������� ��� FILLERó��

	return 1;
}


// �ڽ���_���� �̺�Ʈ ����
int ParseI6011(const double& timestamp, const char* in_buff, DF_KOSPI_STK_EVT_INFO* out) {
	KOSPI_STK_EVT_INFO* data = (KOSPI_STK_EVT_INFO*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����, I6
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������, 01:�ֽ�
	out->mkt_clsf = data->mkt_clsf[0];	//���屸��, 1:�������� 2:�ڽ���
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// �����ڵ�, ǥ���ڵ�
	out->snr = Str2Int(data->snr, sizeof(data->snr));	// �Ϸù�ȣ, 1~99999999 �Ǽ�üũ��
	memcpy(out->evt_code, data->evt_code, sizeof(data->evt_code));	// �̺�Ʈ�����ڵ�, 01:�ŷ����� \n02:�������� \n03:�Ҽ��ǰ��ù��� \n04:�����Ÿ�\n05:��ȸ���� \n06:�������ȿ������ \n07:���豸���췮���\n08:���԰��ŵ��Ұ� \n09:Regulation S \n10:���ı������\n11:��������ȯ������\n12:�ܱ�������� (2012.11.05�߰�)\n13:���� (2016.06.27�߰�)\n14:�������������� (2016.06.27�߰�)\n15:��������ä�� (2016.11.28�߰�)\n16:�̻�޵����� (2017.03.27�߰�)\n17:���ŵ��������� (2017.03.27 �߰�)\n18: LP������ (2017.06.26 �߰�)
	memcpy(out->evt_trgg_code, data->evt_trgg_code, sizeof(data->evt_trgg_code));	// �̺�Ʈ�߻������ڵ�, �� ��÷ �ڵ尩������ �̺�Ʈ�������ڵ� ����\n�� �̺�Ʈ�����ڵ� 03,04,07,08,09,17�� ���ؼ��� '0000' SET\n�� �ڵ��� ������ ���� �ڸ����� �ٸ��ϴ�. ������ Ÿ����\nX��� �̱� ������ �������ĵ˴ϴ�. ���� �����Ͽ� �ֽʽÿ�.\n(�ŷ����������ڵ�(3�ڸ�), �����������������ڵ�(4�ڸ�),\n��ȸ���������ڵ�(1�ڸ�), �������ȿ�����������ڵ�(2�ڸ�),\n��������ȯ����������ڵ�(4�ڸ�))
	memcpy(out->st_date, data->st_date, sizeof(data->st_date));	// ��������,��������,��������, YYYYMMDD
	memcpy(out->ed_date, data->ed_date, sizeof(data->ed_date));	// ��������,��������, YYYYMMDD

	return 1;
}


// �ڽ���_�����ġ
int ParseA0011(const double& timestamp, const char* in_buff, DF_KOSPI_STK_ARNG* out) {
	KOSPI_STK_ARNG* data = (KOSPI_STK_ARNG*)in_buff;

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
	memcpy(out->stk_gr_id, data->stk_gr_id, sizeof(data->stk_gr_id));	// ���Ǳ׷�ID, ST:�ֱ� MF:��������ȸ�� RT:�ε�������ȸ�� \nSC:��������ȸ��\nIF:��ȸ�����ں�������ȸ�� DR:�ֽĿ�Ź���� EW:ELW EF:ETF\nSW:�����μ������� SR:�����μ������� BC:�������� \nFE:�ؿ�ETF FS:�ܱ��ֱ� \nEN:ETN 2014.11.17
	out->unit_trd_ccls_flg = data->unit_trd_ccls_flg[0];	//�����Ÿ�ü�Ῡ��, Y, N (�����忡�� �����ð� ����ü�Ῡ��)
	memcpy(out->lock_clsf_code, data->lock_clsf_code, sizeof(data->lock_clsf_code));	// �������ڵ�, 00:�ش���׾���(���� �߻����� ���) \n01:�Ǹ��� \n02:����\n03:�й�� \n04:�ǹ�� \n05:�߰�(�б�)����\n(2017.11.20 ����:�߰�����->�߰�(�б�)����)\n06:�Ǹ��߰�����\n07:�Ǹ��б����\n(2017.11.20 �߰�)\n99:��Ÿ ��SW,SR,EW�� ���ش�(���ش��� ��� SPACE)
	memcpy(out->pval_chg_clsf_code, data->pval_chg_clsf_code, sizeof(data->pval_chg_clsf_code));	// �׸鰡���汸���ڵ�, 00:�ش����(�׸鰡������ ������ �� �ִ� ���񱺿� ���� ����\n������ �ǹ�) 01:�׸���� 02:�׸麴�� 03:�ֽĺ��� 04:�ֽĺ��� 99:��Ÿ\n(2012.08.27)
	out->open_base_prc_stk_flg = data->open_base_prc_stk_flg[0];	//�ð����ذ������񿩺�, Y, N ��Y�� ���:�ű�����,�������,������,��Ⱓ�ŷ�����
	memcpy(out->rassm_stk_rsn_code, data->rassm_stk_rsn_code, sizeof(data->rassm_stk_rsn_code));	// ������������ڵ�, 00:�ش����, 01:ȸ�����, 02:�ں�����, 03:��Ⱓ����,\n04:�ʰ��й�, 05:��Ը��� \n06: ȸ������պ�, 99:��Ÿ \n�����Ǳ׷�ID ST,FS�� �ش�(���ش��� ��� SPACE)\n2011.02.28 ���а� �߰�(04:�ʰ��й�, 05:��Ը���)\n2012.08.27 ���ǿ�������(02:�ֽĺ���->02:�ں�����) \n2017.06.26 ���а� ����(01:������� -> 01:ȸ�����)\n2017.06.26 ���а� �߰�(06:ȸ������պ�)
	out->base_prc_chg_stk_flg = data->base_prc_chg_stk_flg[0];	//���ذ��ݺ������񿩺�, Y, N ��Y�� ���:����,�׸麯��,���� ��
	out->rndn_cls_trgg_cond_code = data->rndn_cls_trgg_cond_code[0];	//��������ߵ������ڵ�, ���ϰ��������� ���������� �ߵ�����.���Ǻιߵ�(2)�ΰ�� ���������Ģ���� �����ϴ� ���ݿ���� �����ϴ��� �Ǵ� �� �ߵ��� ������.\n##�ڵ尪##\n0:�̹ߵ� 1:�ߵ� 2:���Ǻιߵ�(���ݿ���Ǵ�)
	out->mkt_alm_warn_fcst_flg = data->mkt_alm_warn_fcst_flg[0];	//����溸�������, Y, N\n 2015.06.15:"����溸���迹����(Y,N)"->"����溸�������(Y,N)" �׸񺯰�
	memcpy(out->mkt_alrm_clsf_code, data->mkt_alrm_clsf_code, sizeof(data->mkt_alrm_clsf_code));	// ����溸�����ڵ�, 00:�ش����(����溸�� ������ �� �ִ� ���� ���ؼ� ������\n�ٰ� ������ �ǹ�) 01:�������� 02:���ڰ�� 03:��������
	out->cogv_hlth_flg = data->cogv_hlth_flg[0];	//���豸���췮����, Y, N ���ڽ��ڸ� �ش�, ST,FS,DR,MF,EF�� �ش�
	out->ifam_flg = data->ifam_flg[0];	//�������񿩺�, Y, N
	out->iscnt_flg = data->iscnt_flg[0];	//�Ҽ��ǰ�����������, Y, N
	out->bdlt_flg = data->bdlt_flg[0];	//��ȸ���忩��, Y, N
	out->trsp_flg = data->trsp_flg[0];	//�ŷ���������, Y, N
	memcpy(out->ind_lclsf_code, data->ind_lclsf_code, sizeof(data->ind_lclsf_code));	// ����������з��ڵ�, (����)000:�����̺з� ������������ ������� ����\n(�ڽ���)000:�����̺з�/���߾��ݵ� 008~014:�Ϲ� 015:IT\n�����Ǳ׷�ID ST,MF,RT,SC,IF�� �ش�
	memcpy(out->ind_mclsf_code, data->ind_mclsf_code, sizeof(data->ind_mclsf_code));	// ���������ߺз��ڵ�, (����)000:�����̺з�\n(�ڽ���)000:�����̺з� 021~040:�Ϲ� 041~043:IT\n�����Ǳ׷�ID ST,MF,RT,SC,IF�� �ش�
	memcpy(out->ind_sclsf_code, data->ind_sclsf_code, sizeof(data->ind_sclsf_code));	// ���������Һз��ڵ�, (����)000:�����̺з�\n(�ڽ���)000:�����̺з� 050~112:�Ϲ� 151~160:IT\n�����Ǳ׷�ID ST,MF,RT,SC,IF�� �ش�
	memcpy(out->ind_id, data->ind_id, sizeof(data->ind_id));	// ����ID, ����(Type Of Industry)ID 2014.03.03\n*����Ī:ǥ�ػ���ڵ�\n6�ڸ� ǥ�ػ���ڵ�� ������Ǹ� ������ �� �־� �ؿܻ���Ʈ�� �پ��� �����ڵ� ������ �Ұ��Ͽ� 10�ڸ��� Ȯ��. ���� ǥ�ػ���ڵ�� �״�� 1:1 ���εǾ� ������ 4�ڸ��� �����̽��� ä��
	out->kospi200_str_ind = data->kospi200_str_ind[0];	//KOSPI200���;���, (����)\n0:�����̺з�, 1:�Ǽ�, 2:�߰���,\n3:ö������,\n4:������ȭ��, 5:�������, 6:����, 7:�ʼ��Һ���,\n8: �����Һ��� 9:����� A:�ǰ����� B:Ŀ�´����̼Ǽ���\n- KOSPI200���� �� ���;��� ��������(2011.04.01)\n�����Ǳ׷�ID ST,MF,RT,SC,IF�� �ش�\n\n- �űԾ����߰�(�����,�ǰ�����) �� ����������Ī����(�Ǽ�,�߰���)(2015.07.13) \n- �űԾ����߰�(Ŀ�´����̼Ǽ���(2018.10.22)\n\n(�ڽ���) �ش���׾���.
	out->mkt_cap_code = data->mkt_cap_code[0];	//�ð��ѾױԸ��ڵ�, ����(0:���� 1:�� 2:�� 3:��)\n�ڽ���(0:���� 1:KOSDAQ100 2:KOSDAQmid300 3:KOSDAQsmall)\n�����Ǳ׷�ID ST,MF,RT,SC,IF�� �ش�
	out->mnft_ind_flg = data->mnft_ind_flg[0];	//(����)����������(�ڽ���)�߼ұ������, Y, N\n�����������δ� ST,MF,RT,SC,IF�� �ش�(�����ڵ� 027)\n���߼ұ�����δ� ST,FS,DR,EF�� �ش�
	out->krx100_flg = data->krx100_flg[0];	//KRX100���񿩺�, Y, N
	out->gvnm_idx_stk_flg = data->gvnm_idx_stk_flg[0];	//(����)���豸���������񿩺�(�ڽ���)�ҼӺα����ڵ�, (����) Y, N\n(�ڽ���)�ҼӺα����ڵ� �� ��ó������� 2011.05.02\n 1:�췮�����, 2:��ó�����, 3:�߰߱����, 4:�ż�������,\n A:�ܱ����, B:����ȸ��, C:SPAC, D:ETF E:��������,\n F:��������ȯ������, Z:��Ÿ \n�� A~Z�� �ҼӺ� ����\n2012.09.14 (���������ġ) "���豸���������񿩺�" 1 Byte FILLER ó��\n(�ڽ��������ġ) "�ҼӺα����ڵ�" ��� ���
	memcpy(out->inst_clsf_code, data->inst_clsf_code, sizeof(data->inst_clsf_code));	// ���ڱⱸ�����ڵ�, 00:�ش���� 01:���ǰ������ڱⱸ 02:�Ļ���ǰ���ڱⱸ\n03:�ε��갣�����ڱⱸ 04:�ǹ��������ڱⱸ\n05:�ܱ�����������ڱⱸ 06:�簣�����ڱⱸ\n07:Ư���������ڱⱸ\n�����Ǳ׷�ID MF,IF,BC�� �ش�(���ش��� ��� SPACE)
	out->idx_stk_flg = data->idx_stk_flg[0];	//(����)KOSPI�������񿩺� (�ڽ���)KOSDAQ�������񿩺�, Y, N\n(����)KOSPI����-> (����)KOSPI�������񿩺�,(�ڽ���)KOSDAQ�������񿩺� 2018.12.10
	out->kospi100_flg = data->kospi100_flg[0];	//(����)KOSPI100����(�ڽ���)FILLER, Y, N �����̾�� �߰� 2009.11.16\n(�ڽ���)�����̾�� => FILLERó�� 2016.05.23
	out->kospi50_flg = data->kospi50_flg[0];	//(����)KOSPI50����, Y, N
	out->base_prc = Str2Int(data->base_prc, sizeof(data->base_prc));	// ���ذ���
	out->prev_cls_clsf_code = data->prev_cls_clsf_code[0];	//�������������ڵ�, 1:�Ǽ� 2:�⼼ 3:�ŷ��� 4:�ð����ذ������� �⼼
	out->prev_cls_prc = Str2Int(data->prev_cls_prc, sizeof(data->prev_cls_prc));	// ��������
	out->prev_cum_ccls_qty = Str2Dbl(data->prev_cum_ccls_qty, sizeof(data->prev_cum_ccls_qty), 0);	// ���ϴ���ü�����
	out->prev_cum_trd_val = Str2Dbl(data->prev_cum_trd_val, sizeof(data->prev_cum_trd_val), 0);	// ���ϴ����ŷ����
	out->ceil_prc = Str2Int(data->ceil_prc, sizeof(data->ceil_prc));	// ���Ѱ�
	out->flr_prc = Str2Int(data->flr_prc, sizeof(data->flr_prc));	// ���Ѱ�
	out->sub_prc = Str2Int(data->sub_prc, sizeof(data->sub_prc));	// ��밡��, ��ST,FS,DR,MF,RT,SC,IF,ET,FE,BC,EN �� �ش�\n 2014.11.17
	out->par_val = Str2Dbl(data->par_val, sizeof(data->par_val), 3);	// �׸鰡, 9(9)V9(3) �ܱ��ֱ��� ��� �Ҽ�����°�ڸ����� ǥ������\n�ڽ����� ������ �ּ�ȭ����� ǥ�ô� ������������ ����\n��ST,FS,RT,SC,BC�� �ش�
	out->issue_prc = Str2Int(data->issue_prc, sizeof(data->issue_prc));	// ���డ��, ELW, �����μ������� ����
	memcpy(out->listd_date, data->listd_date, sizeof(data->listd_date));	// ��������, YYYYMMDD
	out->stk_listd = Str2Dbl(data->stk_listd, sizeof(data->stk_listd), 0);	// �����ֽļ�(�������Ǽ�)
	out->arng_trd_flg = data->arng_trd_flg[0];	//�����Ÿſ���, Y, N
	out->eps = Str2Int(data->eps, sizeof(data->eps));	// �ִ������(EPS), ����:�� �����Ǳ׷�ID ST,MF,RT,IF,FS �� �ش�
	out->per = Str2SignDouble(data->per_sign, sizeof(data->per_sign) + sizeof(data->per), 2);	// �ְ�������(PER), 9(4)V9(2) �����Ǳ׷�ID ST,MF,RT,IF,FS �� �ش�
	out->eps_cmpt_xclu_flg = data->eps_cmpt_xclu_flg[0];	//�ִ�����ͻ������ܿ���, Y:�������� N:����\n�ذ��� 0, ��������, �����ǰ��� ���� �Ǵ� ���� �� ���
	out->bps = Str2Int(data->bps, sizeof(data->bps));	// �ִ���ڻ갡ġ(BPS), ����:�� �����Ǳ׷�ID ST,MF,RT,IF,FS �� �ش�
	out->pbr = Str2SignDouble(data->pbr_sign, sizeof(data->pbr_sign) + sizeof(data->pbr), 2);	// �ִ���ڻ����(PBR), 9(4)V9(2) �����Ǳ׷�ID ST,MF,RT,IF,FS �� �ش�
	out->bps_cmpt_xclu_flg = data->bps_cmpt_xclu_flg[0];	//�ִ���ڻ갡ġ�������ܿ���, Y:�������� N:����\n�ذ��� 0, ��������, �����ǰ��� ���� �Ǵ� ������ ���
	out->loss_flg = data->loss_flg[0];	//��տ���, Y, N
	out->dps = Str2Int(data->dps, sizeof(data->dps));	// �ִ���ݾ�, �ִ����
	out->dps_cmpt_xclu_flg = data->dps_cmpt_xclu_flg[0];	//�ִ���ݾ׻������ܿ���, Y:�������� N:����\n�ذ��� 0, ��������, �����ǰ��� ���� �Ǵ� ������ ���
	out->dyr = Str2Dbl(data->dyr, sizeof(data->dyr), 1);	// ��������, 9(6)V9(1)
	memcpy(out->xist_open_date, data->xist_open_date, sizeof(data->xist_open_date));	// ������������, �����Ǳ׷�ID MF,RT,SC,IF,BC �ش�.
	memcpy(out->xist_cls_date, data->xist_cls_date, sizeof(data->xist_cls_date));	// ������������, �����Ǳ׷�ID MF,RT,SC,IF,BC �ش�. ST,FS,DR�� �켱�ָ� �ش�
	memcpy(out->exc_prd_open_date, data->exc_prd_open_date, sizeof(data->exc_prd_open_date));	// ���Ⱓ��������, �����Ǳ׷�ID SW, EW �� �ش��
	memcpy(out->exc_prd_cls_date, data->exc_prd_cls_date, sizeof(data->exc_prd_cls_date));	// ���Ⱓ��������(�Ǹ����Ⱓ��������), �����Ǳ׷�ID SW, EW �� �ش��
	out->elw_wrnt_exc_prc = Str2Dbl(data->elw_wrnt_exc_prc, sizeof(data->elw_wrnt_exc_prc), 3);	// ELW�����μ������� ��簡��, 9(9)V9(3) ELW �Ǵ� �����μ��������� ��簡��
	out->euity = Str2Dbl(data->euity, sizeof(data->euity), 3);	// �ں���, 9(18)V9(3) �ؿܿ����� ��� �Ҽ�����°�ڸ����� ǥ������\n�׸鰡*�����ֽļ�, ���ͼҰ��� ���� �κ��� ������\nMF�� �Է°�\n��ST,FS,MF,RT,SC,IF,BC�� �ش�
	out->credit_ordbl_flg = data->credit_ordbl_flg[0];	//�ſ��ֹ����ɿ���, Y, N
	out->limt_prc_cond_clsf_code = Str2Int(data->limt_prc_cond_clsf_code, sizeof(data->limt_prc_cond_clsf_code));	// ������ȣ�����Ǳ����ڵ�, X ->9 ��庯��, 1->5 ���̺���\nȣ���� ü�� �� �ܷ�����, Bitwise ����(*���߰��̵� ����) \n#�ڵ尪# \n1:FAS(Fill And Store) \n2:FOK(Fill Or Kill) \n4:FAK(Fill And Kill) \n*��������(FOK, Fill or Kill):�ֹ����� ��� ���� ü����� ������ ��� �ֹ��� �ڵ� ��ҵǴ� �ֹ� \n*��������(FAS, Fill and Store):�ֹ����� ��� ü�ᰡ�� ������ ü���ϰ� ��ü���ܷ��� ���� ���ߵ��� �ֹ��忡 ü�� ����Ű��, ������ ���� ��ü�� �ֹ��� ��� �ּҵ�
	out->mkt_prc_cond_clsf_code = Str2Int(data->mkt_prc_cond_clsf_code, sizeof(data->mkt_prc_cond_clsf_code));	// ���尡ȣ�����Ǳ����ڵ�, *��
	out->cond_prc_cond_clsf_code = Str2Int(data->cond_prc_cond_clsf_code, sizeof(data->cond_prc_cond_clsf_code));	// ���Ǻ�������ȣ�����Ǳ����ڵ�, *��
	out->fvr_lmt_ord_cond_clsf_code = Str2Int(data->fvr_lmt_ord_cond_clsf_code, sizeof(data->fvr_lmt_ord_cond_clsf_code));	// ������������ȣ�����Ǳ����ڵ�, *��
	out->pfr_lmt_ord_cond_clsf_code = Str2Int(data->pfr_lmt_ord_cond_clsf_code, sizeof(data->pfr_lmt_ord_cond_clsf_code));	// �ֿ켱������ȣ�����Ǳ����ڵ�, *��
	memcpy(out->cap_inc_clsf_code, data->cap_inc_clsf_code, sizeof(data->cap_inc_clsf_code));	// ���ڱ����ڵ�, 00:�ش���� 01:�������� 02:�������� 03:���������� 99:��Ÿ
	out->scrt_clsf_code = data->scrt_clsf_code[0];	//�����ֱǱ����ڵ�, 0:�ش����(������) 1:�����켱�� 2:�����켱�� 9:�����ֱ�(2014.03.03)\n\n�����Ǳ׷�ID ST���� �ش�\n�ر���Ī:�켱�ֱ����ڵ�
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
	out->preord_cls_flg = data->preord_cls_flg[0];	//�尳�����ð����������ɿ���, Y, N
	out->preord_msv_trd_flg = data->preord_msv_trd_flg[0];	//�尳�����ð��ܴ뷮�ŸŰ��� ����, Y, N
	out->preord_bsk_flg = data->preord_bsk_flg[0];	//�尳�����ð��ܹٽ��ϰ��� ����, Y, N
	out->fcst_ccls_flg = data->fcst_ccls_flg[0];	//����ü�ᰡ��������, Y, N
	out->short_flg = data->short_flg[0];	//���ŵ����ɿ���, Y, N ���������� �ְų� ���� ���ŵ��� ȣ�����ɿ���
	out->trkg_prf_mtp = Str2SignDouble(data->trkg_prf_mtp_sign, sizeof(data->trkg_prf_mtp_sign) + sizeof(data->trkg_prf_mtp), 6);	// �������������, �����Ǳ׷�ID EF,FE,EN �ش� 2014.11.17\n���׸���� 2014.11.17\n\n9(5)V9(6) ���� �Ǵ� ���� ���� ��� ETF ���� ���� ���\n��) �������� 2���� ��� '00002000000' 2009.07.27
	out->regulation_apl_flg = data->regulation_apl_flg[0];	//Regulation S �������񿩺�, Y, N 2010.02.01
	out->spc_flg = data->spc_flg[0];	//����μ�����ȸ�翩��, Y, N 2010.03.02
	out->tax_type_code = data->tax_type_code[0];	//���������ڵ�, 0:�ش����, \n1:"���ǰŷ���"->"�����" �ڵ尪�� ���� 2016.02.29, \n2:���ҵ漼(�����Ⱓ����), \n3:���ǰŷ���(ȸ����ETF) 2011.05.02 \n4:"���ҵ漼(�ؿ��ֽ���������ETF)" �ڵ尪 �߰� 2016.02.29(BIG33�� FILLER��)
	out->sbst_prc_rate = Str2Dbl(data->sbst_prc_rate, sizeof(data->sbst_prc_rate), 6);	// ��밡�ݻ�������, 99999V999999 2010.06.28\n(BIG33�� FILLER��)\n��Exture������ ��밡�� 0�̸� ���������� 0�̾�����, Exture+������ ��밡�� 0�̾ �������� ����
	out->inv_xctm_stk_flg = data->inv_xctm_stk_flg[0];	//(�ڽ���)��������ȯ�����񿩺�, (�ڽ���) Y,N �������� �Ǵ� ���������� ��ȭ�� ����� �ִ�\n�ν� ����¡�� ��� ����\n(2011.05.02 �߰�)\n(BIG33�� FILLER��)
	memcpy(out->dlstg_date, data->dlstg_date, sizeof(data->dlstg_date));	// ������������, YYYYMMDD �����Ǳ׷�ID SR �� �ش�, �ٸ� ���Ǳ׷�ID�� FILLERó�� 2011.06.27 �߰�\n(BIG33�� FILLER��)
	out->short_term_oh_clsf_code = data->short_term_oh_clsf_code[0];	//�ܱ�������񱸺��ڵ�, 0: �ش����\n1: ��������\n2: ����\n3: ��������(��������)\n2012.11.05 �߰�
	out->etf_cpy_clsf_code = data->etf_cpy_clsf_code[0];	//ETF������������ڵ�, ETF�� �����ڻ� ������������ڵ� 2013.03.18 �߰�\nP:�ǹ�����\nS:�ռ�����\nA:Active (2015.11.23 �����ڵ��߰�)
	out->kospi200_hi_divd_idx_flg = data->kospi200_hi_divd_idx_flg[0];	//KOSPI200������������, Y,N 2013.11.18
	out->kospi200_lo_vol_idx_flg = data->kospi200_lo_vol_idx_flg[0];	//KOSPI200����������������, Y,N 2013.11.18
	memcpy(out->mtr_date, data->mtr_date, sizeof(data->mtr_date));	// ��������, 2014.11.17
	memcpy(out->divd_type_code, data->divd_type_code, sizeof(data->divd_type_code));	// �й�������ڵ�, �й�����¿� ���� �����ڵ� 2014.11.17\n01:������\n02:����(��ǥ��ġ �ݿ�)\n03:����(��ǥ��ġ �̹ݿ�)\n04:����(������)\n05:����(��Ÿ)
	memcpy(out->mtr_rdmp_prc_st_date, data->mtr_rdmp_prc_st_date, sizeof(data->mtr_rdmp_prc_st_date));	// �����ȯ���ݰ�����������, 2014.11.17
	memcpy(out->mtr_rdmp_prc_ed_date, data->mtr_rdmp_prc_ed_date, sizeof(data->mtr_rdmp_prc_ed_date));	// �����ȯ���ݰ�����������, 2014.11.17
	out->etp_mcdz_clsf_code = data->etp_mcdz_clsf_code[0];	//ETP��ǰ�����ڵ�, (2015.11.23 �߰�)\n ETP��ǰ�����ڵ�\n ## �ڵ尪 ##\n1. ETF(����ȸ����)\n2. ETF(����������)\n3. ETN\n4. �ս����� ETN\n(2017.03.27;ELS�� ETN->�ս����� ETN)
	out->idx_cmpt_inst_code = data->idx_cmpt_inst_code[0];	//�����������ڵ�, (2015.11.23 �߰�) \n*�ڵ尪���� ����(KRX ����)
	memcpy(out->idx_mkt_clsf_id, data->idx_mkt_clsf_id, sizeof(data->idx_mkt_clsf_id));	// ��������з�ID, (2015.11.23 �߰�)\n *��з�(2)+�ߺз�(2)+�Һз�(2)\n ���� �����Ǵ� �з��� �ڸ��� '00'�� ǥ��\n��,�Һз� ������ ���� �з��� ���� ���� �� �� ����
	memcpy(out->idx_snr, data->idx_snr, sizeof(data->idx_snr));	// �����Ϸù�ȣ, (2015.11.23 �߰�)�����Ϸù�ȣ
	memcpy(out->trkg_idx_lvrg_invs_clsf_code, data->trkg_idx_lvrg_invs_clsf_code, sizeof(data->trkg_idx_lvrg_invs_clsf_code));	// �����������������ι��������ڵ�, (2015.11.23 �߰�)\n## �ڵ尪 ##\n P1:�Ϲ�(1)\n P2:2X ��������(2)\n N1:1X �ι���(-1)\n N2:2X �ι���(-2)
	memcpy(out->ref_idx_lvrg_invs_clsf_code, data->ref_idx_lvrg_invs_clsf_code, sizeof(data->ref_idx_lvrg_invs_clsf_code));	// �����������������ι��������ڵ�, (2015.11.23 �߰�)\n## �ڵ尪 ##\n P1:�Ϲ�(1)\n P2:2X ��������(2)\n N1:1X �ι���(-1)\n N2:2X �ι���(-2)
	memcpy(out->idx_ast_clsf_id1, data->idx_ast_clsf_id1, sizeof(data->idx_ast_clsf_id1));	// �����ڻ�з�ID1, (2015.11.23 �߰�)\n *��з�(2)+�ߺз�(2)+�Һз�(2)\n ���� �����Ǵ� �з��� �ڸ��� '00'�� ǥ��\n��,�Һз� ������ ���� �з��� ���� ���� �� �� ����
	memcpy(out->idx_ast_clsf_id2, data->idx_ast_clsf_id2, sizeof(data->idx_ast_clsf_id2));	// �����ڻ�з�ID2, (2015.11.23 �߰�)\n *��з�(2)+�ߺз�(2)+�Һз�(2)\n ���� �����Ǵ� �з��� �ڸ��� '00'�� ǥ��\n��,�Һз� ������ ���� �з��� ���� ���� �� �� ����
	out->lp_odrbl_flg = data->lp_odrbl_flg[0];	//LP�ֹ����ɿ���, (2015.11.23 �߰�)\nY,N
	out->kosdaq150_idx_stk_flg = data->kosdaq150_idx_stk_flg[0];	//KOSDAQ150�������񿩺�, (2015.11.23 �߰�)\nY,N
	out->lo_vol_flg = data->lo_vol_flg[0];	//������������, (2016.06.27 �߰�)\nY,N
	out->abnm_risg_flg = data->abnm_risg_flg[0];	//�̻�޵��, (2017.03.27 �߰�)\nY,N
	out->krx300_idx_flg = data->krx300_idx_flg[0];	//KRX300��������, (2018.03.26 �߰�)\nY,N
	out->qty_ceil = Str2Dbl(data->qty_ceil, sizeof(data->qty_ceil), 0);	// ���Ѽ���, (2018.09.17 �߰�)���Ѽ����� �ʰ��� ȣ���� �ź�ó�� �ʿ�
	out->kospi200_comm_srvc_sct_flg = data->kospi200_comm_srvc_sct_flg[0];	//KOSPI200Ŀ�´����̼Ǽ��񽺼��� �ߺ�����, Y : �ٸ����Ϳ� �ߺ��� ��� KOSPI200���;����� �������;��������� �����ϰ� �� �ʵ�� Y�� ����\nN: �ٸ����Ϳ� �ߺ��� ���� ���� ��� KOSPI200���;����� 'B'���� �����ϰ� �� �ʵ�� N���� ����

	return 1;
}


// ETN ���ͱ��� ����
int ParseX8011(const double& timestamp, const char* in_buff, DF_ETN_PRF_STR* out) {
	ETN_PRF_STR* data = (ETN_PRF_STR*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����, X8
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������, 01:�ֽ�
	out->mkt_clsf = data->mkt_clsf[0];	//���屸��, 1:��������
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// �����ڵ�, ǥ���ڵ�
	memcpy(out->etn_profit_strt, data->etn_profit_strt, sizeof(data->etn_profit_strt));	// ETN���ͱ�������, ETN ���ͱ����� ���� ����\n�ս����� ETN���� �ַ� ����

	return 1;
}


// ETN������
int ParseX4011(const double& timestamp, const char* in_buff, DF_ETN_DSPR* out) {
	ETN_DSPR* data = (ETN_DSPR*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����, X4
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������, 01:�ֽ�
	out->mkt_clsf = data->mkt_clsf[0];	//���屸��, 1:�������� 2:�ڽ���
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// ETN�����ڵ�, ISIN
	out->trsm_snr = Str2Int(data->trsm_snr, sizeof(data->trsm_snr));	// �۽��Ϸù�ȣ, 1~99999999 �����Ϸù�ȣ, �Ǽ�üũ��
	memcpy(out->date, data->date, sizeof(data->date));	// ����, YYYYMMDD:����������
	out->dspr = Str2SignDouble(data->dspr_sign, sizeof(data->dspr_sign) + sizeof(data->dspr), 2);	// ������, 9(7)V9(2), ����:%

	return 1;
}


// ETN �����ȯ ����
int ParseX3011(const double& timestamp, const char* in_buff, DF_ETN_ELY_RDMP_COND* out) {
	ETN_ELY_RDMP_COND* data = (ETN_ELY_RDMP_COND*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����, X3
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������, 01:�ֽ�
	out->mkt_clsf = data->mkt_clsf[0];	//���屸��, 1:��������
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// �����ڵ�, ǥ���ڵ�
	memcpy(out->etn_ely_rdmp_freq_code, data->etn_ely_rdmp_freq_code, sizeof(data->etn_ely_rdmp_freq_code));	// ETN�����ȯ�ֱ��ڵ�, �ս����� ETN�� �����ȯ �ֱ� ����\nETN�����ȯ���ɿ��ΰ� Y�϶��� ���ð���\n�ˢ��ڵ尪�ˢ�\n01: ����(����)\n02: �� 3����\n03: �� 4����\n04: �� 6����\n05: �� 1�� (��缭���� ����)\n06: 3�������� �� 1���� (��缭���� ����)\n07: 6�������� �� 1���� (��缭���� ����)
	memcpy(out->rdmp_assm_date, data->rdmp_assm_date, sizeof(data->rdmp_assm_date));	// �����ȯ������, �����ȯ������\n�����ȯ�ֱ��ڵ尡 01:������ ���� SPACE
	out->rdmp_cond_code = data->rdmp_cond_code[0];	//�����ȯ���ǰ����ڵ�, �����ȯ����1������ �����ȯ����2���� ���� ���� ���� �ڵ�\n���������� ��� ����1���� < ����2���� �������� ����\n�ˢ��ڵ尪�ˢ�\n1:��������(1�����̻�)\n2:��������(1��������)\n3:��������(1��������,2�����̻�)\n4:��������(1�����̻�,2��������)
	out->rdmp_crtr_base_1idx = Str2Dbl(data->rdmp_crtr_base_1idx, sizeof(data->rdmp_crtr_base_1idx), 2);	// �����ȯ����1����, �����ȯ����1����\n9(8)V9(2)
	out->rdmp_crtr_base_2idx = Str2Dbl(data->rdmp_crtr_base_2idx, sizeof(data->rdmp_crtr_base_2idx), 2);	// �����ȯ����2����, �����ȯ����2����\n9(8)V9(2)
	out->rdmp_prc = Str2Dbl(data->rdmp_prc, sizeof(data->rdmp_prc), 2);	// ����������������ȯ����, ����������������ȯ����\n9(21)V9(2)
	memcpy(out->rdmp_date, data->rdmp_date, sizeof(data->rdmp_date));	// �����ȯ��������, �����ȯ��������\n�����ȯ�ֱ��ڵ尡 01:������ ���� SPACE

	return 1;
}


// ETP��������
int ParseV6011(const double& timestamp, const char* in_buff, DF_ETP_IDX_COMP* out) {
	ETP_IDX_COMP* data = (ETP_IDX_COMP*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����, V6
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������, 01:�ֽ�
	out->mkt_clsf = data->mkt_clsf[0];	//���屸��, 1:��������
	out->idx_inst_code = data->idx_inst_code[0];	//�����������ڵ�, *�ڵ尪 ����(KRX����)
	memcpy(out->idx_mkt_clsf_id, data->idx_mkt_clsf_id, sizeof(data->idx_mkt_clsf_id));	// ��������з�ID, *��з�(2)+�ߺз�(2)+�Һз�(2)\n ���� �����Ǵ� �з��� �ڸ��� '00'�� ǥ��\n��,�Һз� ������ ���� �з��� ���� ���� �� �� ����
	memcpy(out->idx_snr, data->idx_snr, sizeof(data->idx_snr));	// �����Ϸù�ȣ, �����Ϸù�ȣ
	memcpy(out->idx_lvr_ivs_clsf_code, data->idx_lvr_ivs_clsf_code, sizeof(data->idx_lvr_ivs_clsf_code));	// �������������ι��������ڵ�, ## �ڵ尪 ##\n P1:�Ϲ�(1)\n P2:2X ��������(2)\n N1:1X �ι���(-1)\n N2:2X �ι���(-2)
	memcpy(out->idx_nm, data->idx_nm, sizeof(data->idx_nm));	// ������, ������
	memcpy(out->idx_eng_nm, data->idx_eng_nm, sizeof(data->idx_eng_nm));	// ����������, ����������
	memcpy(out->idx_asset_clsf_id1, data->idx_asset_clsf_id1, sizeof(data->idx_asset_clsf_id1));	// �����ڻ�з�ID1, *��з�(2)+�ߺз�(2)+�Һз�(2)\n ���� �����Ǵ� �з��� �ڸ��� '00'�� ǥ��\n��,�Һз� ������ ���� �з��� ���� ���� �� �� ����
	memcpy(out->idx_asset_clsf_id2, data->idx_asset_clsf_id2, sizeof(data->idx_asset_clsf_id2));	// �����ڻ�з�ID2, *��з�(2)+�ߺз�(2)+�Һз�(2)\n ���� �����Ǵ� �з��� �ڸ��� '00'�� ǥ��\n��,�Һз� ������ ���� �з��� ���� ���� �� �� ����
	out->idx_mkt_clsf_code = data->idx_mkt_clsf_code[0];	//�����Ҽӽ��屸���ڵ�, ���� �Ҽӽ����� ����
	memcpy(out->ind_idx_code, data->ind_idx_code, sizeof(data->ind_idx_code));	// ���������ڵ�, ���������ڵ�(8�ڸ�)�� ���������Ӹ� �ƴ϶� KOSPI100, KOSPI50, KOSTAR���� ���� ������ ����� �Ǵ� ��� �з��� �ڵ带 �ο��Ͽ� �̸� ��Ī

	return 1;
}


// �ڽ���_���ذ�����
int ParseA4011(const double& timestamp, const char* in_buff, DF_KOSPI_BASE_PRC_DCS* out) {
	KOSPI_BASE_PRC_DCS* data = (KOSPI_BASE_PRC_DCS*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����, A4
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������, 01:�ֽ�
	out->mkt_clsf = data->mkt_clsf[0];	//���屸��, 1:�������� 2:�ڽ���
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// �����ڵ�, ǥ���ڵ�
	out->snr = Str2Int(data->snr, sizeof(data->snr));	// �����Ϸù�ȣ, �����ġ(A0)�� �����Ϸù�ȣ
	memcpy(out->brd_id, data->brd_id, sizeof(data->brd_id));	// ����ID, �� �ڵ尪���� ����
	out->base_prc = Str2Int(data->base_prc, sizeof(data->base_prc));	// ���ذ���, ����:��
	out->base_prc_ceil = Str2Int(data->base_prc_ceil, sizeof(data->base_prc_ceil));	// ���ذ��ݻ��Ѱ�, ����:��
	out->base_prc_flr = Str2Int(data->base_prc_flr, sizeof(data->base_prc_flr));	// ���ذ������Ѱ�, ����:��

	return 1;
}


// �ڽ���_���񸶰�
int ParseA6011(const double& timestamp, const char* in_buff, DF_KOSPI_STK_CLSG* out) {
	KOSPI_STK_CLSG* data = (KOSPI_STK_CLSG*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����, A6
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������, 01:�ֽ� 02:ELW
	out->mkt_clsf = data->mkt_clsf[0];	//���屸��, 1:�������� 2:�ڽ���
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// �����ڵ�, ǥ���ڵ�
	out->snr = Str2Int(data->snr, sizeof(data->snr));	// �����Ϸù�ȣ, �����ġ(A0)�� �����Ϸù�ȣ
	memcpy(out->brd_id, data->brd_id, sizeof(data->brd_id));	// ����ID, �� �ڵ尪���� ����
	out->stk_cls_prc = Str2Int(data->stk_cls_prc, sizeof(data->stk_cls_prc));	// ���񸶰�����, ���Խð��ܱ����ڵ尡 \n 1:�������϶��� ���񸶰����ݱ����ڵ尪�� SET ��. \n �׿ܿ��� SPACE
	out->stk_cls_prc_clsf_code = data->stk_cls_prc_clsf_code[0];	//���񸶰����ݱ����ڵ�, 1:ü�ᰡ \n 2:�⼼ \n 3:�ŷ��� \n 4:�ð����ذ������� �⼼\n :�������� �ƴ� ��� SPACE
	out->ofhr_ceil = Str2Int(data->ofhr_ceil, sizeof(data->ofhr_ceil));	// ���񸶰��ð��ܴ��ϰ� ���Ѱ�
	out->ofhr_flr = Str2Int(data->ofhr_flr, sizeof(data->ofhr_flr));	// ���񸶰��ð��ܴ��ϰ� ���Ѱ�
	out->stk_cls_mwprc = Str2Int(data->stk_cls_mwprc, sizeof(data->stk_cls_mwprc));	// ���񸶰���հ����ְ�
	out->dlv_base_prc = Str2Int(data->dlv_base_prc, sizeof(data->dlv_base_prc));	// �����ε����ذ���
	out->dlv_ceil = Str2Int(data->dlv_ceil, sizeof(data->dlv_ceil));	// �����ε����Ѱ�
	out->dlv_flr = Str2Int(data->dlv_flr, sizeof(data->dlv_flr));	// �����ε����Ѱ�

	return 1;
}


// �ڽ���_��TS
int ParseA7011(const double& timestamp, const char* in_buff, DF_KOSPI_MKT_OPR_TS* out) {
	KOSPI_MKT_OPR_TS* data = (KOSPI_MKT_OPR_TS*)in_buff;

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


// �ڽ���_ü��
int ParseA3011(const double& timestamp, const char* in_buff, DF_KOSPI_CCLS* out) {
	KOSPI_CCLS* data = (KOSPI_CCLS*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����, A3
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������, 01:�ֽ� 02:ELW
	out->mkt_clsf = data->mkt_clsf[0];	//���屸��, 1:�������� 2:�ڽ���
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// �����ڵ�, ǥ���ڵ�
	out->stk_snr = Str2Int(data->stk_snr, sizeof(data->stk_snr));	// �����Ϸù�ȣ, �����ġ(A0)�� �����Ϸù�ȣ
	memcpy(out->brd_id, data->brd_id, sizeof(data->brd_id));	// ����ID, �� �ڵ尪���� ����
	out->ctrs_clsf = data->ctrs_clsf[0];	//���ϴ��(���ذ����) ����, 0:�ǴܺҰ� 1:���� 2:��� 3:���� 4:���� 5:�϶�\n �� ���Խð��ܱ����ڵ� ���� 4�� ��� ���� ���� ���\n �� ���Խð��ܱ����ڵ� ���� 7,8�� ��� Buy-in���ذ� ���
	out->prev_ctrs = Str2Int(data->prev_ctrs, sizeof(data->prev_ctrs));	// ���ϴ��, ����:�� �����μ��� ����/������ �ű� ���� ���� : 0
	out->ccls_prc = Str2Int(data->ccls_prc, sizeof(data->ccls_prc));	// ü�ᰡ��, ����:��
	out->ccls_qty = Str2Dbl(data->ccls_qty, sizeof(data->ccls_qty), 0);	// ü�����, ����:��
	memcpy(out->sess_id, data->sess_id, sizeof(data->sess_id));	// ����ID, �� �ڵ尪���� ����
	out->open = Str2Int(data->open, sizeof(data->open));	// �ð�, ����:�� �ذ��߰��̵� ����
	out->high = Str2Int(data->high, sizeof(data->high));	// ��, ����:�� �ذ��߰��̵� ����
	out->low = Str2Int(data->low, sizeof(data->low));	// ����, ����:�� �ذ��߰��̵� ����
	out->cum_ccls_qty = Str2Dbl(data->cum_ccls_qty, sizeof(data->cum_ccls_qty), 0);	// ����ü�����, ����:�� �غ���ID���� ������
	out->cum_trd_val = Str2Dbl(data->cum_trd_val, sizeof(data->cum_trd_val), 0);	// �����ŷ����, ����:�� �غ���ID���� ������
	out->fin_bid_ask_clsf_code = data->fin_bid_ask_clsf_code[0];	//�����ŵ��ż������ڵ�, 1:�ŵ� 2:�ż�
	out->mtc_flg = data->mtc_flg[0];	//ü�ᰡ��1ȣ����ġ����, 0:�ǴܺҰ� 1:��ġ 2:����ġ
	memcpy(out->ccls_time, data->ccls_time, sizeof(data->ccls_time));	// ü��ð�, HHMMSS
	out->lp_hld_qty = Str2Dbl(data->lp_hld_qty, sizeof(data->lp_hld_qty), 0);	// LP��������, LP(ü�����) ������ LP��������\n�����߻� ����(ETN�� �ش�)(2018.09.17)
	out->ask_1_prc = Str2Int(data->ask_1_prc, sizeof(data->ask_1_prc));	// �ŵ�1ȣ��, ����:�� �ذ��߰��̵� ����
	out->bid_1_prc = Str2Int(data->bid_1_prc, sizeof(data->bid_1_prc));	// �ż�1ȣ��, ����:�� �ذ��߰��̵� ����

	return 1;
}


// �ڽ���_�뷮ü��
int ParseC4011(const double& timestamp, const char* in_buff, DF_KOSPI_MSV_CCLS* out) {
	KOSPI_MSV_CCLS* data = (KOSPI_MSV_CCLS*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����, C4
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������, 01:�ֽ�
	out->mkt_clsf = data->mkt_clsf[0];	//���屸��, 1:�������� 2:�ڽ���
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// �����ڵ�, ǥ���ڵ�
	out->stk_snr = Str2Int(data->stk_snr, sizeof(data->stk_snr));	// �����Ϸù�ȣ, �����ġ(A0)�� �����Ϸù�ȣ
	out->snr = Str2Int(data->snr, sizeof(data->snr));	// �Ϸù�ȣ, 1~99999999 �Ǽ�üũ��
	out->bopen_rel_msv_ccls_qty = Str2Int(data->bopen_rel_msv_ccls_qty, sizeof(data->bopen_rel_msv_ccls_qty));	// �尳�����ð��� ���뷮ü�����, ����:��
	out->bopen_bsk_ccls_qty = Str2Int(data->bopen_bsk_ccls_qty, sizeof(data->bopen_bsk_ccls_qty));	// �尳�����ð��� �ٽ���ü�����, ����:��
	out->bopen_cmpt_msv_ccls_qty = Str2Int(data->bopen_cmpt_msv_ccls_qty, sizeof(data->bopen_cmpt_msv_ccls_qty));	// �尳�����ð��� ����뷮ü�����, ����:��
	out->rel_msv_ccls_qty = Str2Int(data->rel_msv_ccls_qty, sizeof(data->rel_msv_ccls_qty));	// ���߻��뷮ü�����, ����:��
	out->bsk_ccls_qty = Str2Int(data->bsk_ccls_qty, sizeof(data->bsk_ccls_qty));	// ���߹ٽ���ü�����, ����:��
	out->cmpt_msv_ccls_qty = Str2Int(data->cmpt_msv_ccls_qty, sizeof(data->cmpt_msv_ccls_qty));	// ���߰���뷮ü�����, ����:��
	out->ofhr_rel_msv_ccls_qty = Str2Int(data->ofhr_rel_msv_ccls_qty, sizeof(data->ofhr_rel_msv_ccls_qty));	// �������Ľð��� ���뷮ü�����, ����:��
	out->ofhr_bsk_ccls_qty = Str2Int(data->ofhr_bsk_ccls_qty, sizeof(data->ofhr_bsk_ccls_qty));	// �������Ľð��� �ٽ���ü�����, ����:��

	return 1;
}


// �ڽ���_�������
int ParseO6011(const double& timestamp, const char* in_buff, DF_KOSPI_ALLC_INFO* out) {
	KOSPI_ALLC_INFO* data = (KOSPI_ALLC_INFO*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����, O6
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������, 01:�ֽ�
	out->mkt_clsf = data->mkt_clsf[0];	//���屸��, 1:��������, 2:�ڽ���,
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// �����ڵ�, ǥ���ڵ�
	out->stk_snr = Str2Int(data->stk_snr, sizeof(data->stk_snr));	// �����Ϸù�ȣ, �����ġ(A0)�� �����Ϸù�ȣ
	memcpy(out->brd_id, data->brd_id, sizeof(data->brd_id));	// ����ID, �� �ڵ尪���� ����
	out->allc_apl_clsf_code = data->allc_apl_clsf_code[0];	//������뱸���ڵ�, 1 ��а���\n 2 �������
	out->allc_proc_clsf_code = Str2Int(data->allc_proc_clsf_code, sizeof(data->allc_proc_clsf_code));	// ���ó�������ڵ�, 1 �ż�����,\n 2 �ż�����,\n 3 �ŵ�����,\n 4 �ŵ����� �� ������ ' ' ����
	out->allc_cncl_time = Str2Int(data->allc_cncl_time, sizeof(data->allc_cncl_time));	// ��������ð�, HHMMSS

	return 1;
}


// ELW_ü��
int ParseA3021(const double& timestamp, const char* in_buff, DF_ELW_CCLS* out) {
	ELW_CCLS* data = (ELW_CCLS*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����, A3
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������, 01:�ֽ� 02:ELW
	out->mkt_clsf = data->mkt_clsf[0];	//���屸��, 1:�������� 2:�ڽ���
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// �����ڵ�, ǥ���ڵ�
	out->stk_snr = Str2Int(data->stk_snr, sizeof(data->stk_snr));	// �����Ϸù�ȣ, �����ġ(A0)�� �����Ϸù�ȣ
	memcpy(out->brd_id, data->brd_id, sizeof(data->brd_id));	// ����ID, �� �ڵ尪���� ����
	out->ctrs_clsf = data->ctrs_clsf[0];	//���ϴ��(���ذ����) ����, 0:�ǴܺҰ� 1:���� 2:��� 3:���� 4:���� 5:�϶�\n �� ���Խð��ܱ����ڵ� ���� 4�� ��� ���� ���� ���\n �� ���Խð��ܱ����ڵ� ���� 7,8�� ��� Buy-in���ذ� ���
	out->prev_ctrs = Str2Int(data->prev_ctrs, sizeof(data->prev_ctrs));	// ���ϴ��, ����:�� �����μ��� ����/������ �ű� ���� ���� : 0
	out->ccls_prc = Str2Int(data->ccls_prc, sizeof(data->ccls_prc));	// ü�ᰡ��, ����:��
	out->ccls_qty = Str2Dbl(data->ccls_qty, sizeof(data->ccls_qty), 0);	// ü�����, ����:��
	memcpy(out->sess_id, data->sess_id, sizeof(data->sess_id));	// ����ID, �� �ڵ尪���� ����
	out->open = Str2Int(data->open, sizeof(data->open));	// �ð�, ����:�� �ذ��߰��̵� ����
	out->high = Str2Int(data->high, sizeof(data->high));	// ��, ����:�� �ذ��߰��̵� ����
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


// ELW_���񸶰�
int ParseA6021(const double& timestamp, const char* in_buff, DF_ELW_STK_CLSG* out) {
	ELW_STK_CLSG* data = (ELW_STK_CLSG*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����, A6
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������, 01:�ֽ� 02:ELW
	out->mkt_clsf = data->mkt_clsf[0];	//���屸��, 1:�������� 2:�ڽ���
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// �����ڵ�, ǥ���ڵ�
	out->snr = Str2Int(data->snr, sizeof(data->snr));	// �����Ϸù�ȣ, �����ġ(A0)�� �����Ϸù�ȣ
	memcpy(out->brd_id, data->brd_id, sizeof(data->brd_id));	// ����ID, �� �ڵ尪���� ����
	out->stk_cls_prc = Str2Int(data->stk_cls_prc, sizeof(data->stk_cls_prc));	// ���񸶰�����, ���Խð��ܱ����ڵ尡 \n 1:�������϶��� ���񸶰����ݱ����ڵ尪�� SET ��. \n �׿ܿ��� SPACE
	out->stk_cls_prc_clsf_code = data->stk_cls_prc_clsf_code[0];	//���񸶰����ݱ����ڵ�, 1:ü�ᰡ \n 2:�⼼ \n 3:�ŷ��� \n 4:�ð����ذ������� �⼼\n :�������� �ƴ� ��� SPACE
	out->ofhr_hi = Str2Int(data->ofhr_hi, sizeof(data->ofhr_hi));	// ���񸶰��ð��ܴ��ϰ� ���Ѱ�
	out->ofhr_lo = Str2Int(data->ofhr_lo, sizeof(data->ofhr_lo));	// ���񸶰��ð��ܴ��ϰ� ���Ѱ�
	out->stk_cls_mwprc = Str2Int(data->stk_cls_mwprc, sizeof(data->stk_cls_mwprc));	// ���񸶰���հ����ְ�
	out->dlv_base_prc = Str2Int(data->dlv_base_prc, sizeof(data->dlv_base_prc));	// �����ε����ذ���
	out->dlv_hi = Str2Int(data->dlv_hi, sizeof(data->dlv_hi));	// �����ε����Ѱ�
	out->dlv_lo = Str2Int(data->dlv_lo, sizeof(data->dlv_lo));	// �����ε����Ѱ�

	return 1;
}


// ELW_��TS
int ParseA7021(const double& timestamp, const char* in_buff, DF_ELW_MKT_OPR_TS* out) {
	ELW_MKT_OPR_TS* data = (ELW_MKT_OPR_TS*)in_buff;

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


// �ڽ���_�ֽ�������������
int ParseA8011(const double& timestamp, const char* in_buff, DF_KOSPI_STK_INFO_DCLS* out) {
	KOSPI_STK_INFO_DCLS* data = (KOSPI_STK_INFO_DCLS*)in_buff;

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
	memcpy(out->lock_clsf_code, data->lock_clsf_code, sizeof(data->lock_clsf_code));	// �������ڵ�, 00:�ش���׾��� 01:�Ǹ��� 02:���� 03:�й�� 04:�ǹ��\n 05:�߰�(�б�)���� 06:�Ǹ��߰����� 07:�Ǹ��б���� 99:��Ÿ
	memcpy(out->pval_chg_clsf_code, data->pval_chg_clsf_code, sizeof(data->pval_chg_clsf_code));	// �׸鰡���汸���ڵ�, 00:�ش���� 01:�׸���� 02:�׸麴�� \n 03:�ֽĺ��� 04:�ֽĺ���\n 99:��Ÿ
	out->trd_qty_unit = Str2Dbl(data->trd_qty_unit, sizeof(data->trd_qty_unit), 0);	// �Ÿż�������, 1�ִ���:1 10:10�ִ��� 100:100�ִ��� 1000:1000�ִ���
	out->stk_lstd = Str2Dbl(data->stk_lstd, sizeof(data->stk_lstd), 0);	// �����ֽļ�
	out->apnt = data->apnt[0];	//��������, N:���� Y:����
	out->bopen_ofhr_flg = data->bopen_ofhr_flg[0];	//�尳�����ð������� ���ɿ���, N:�ش���� Y:����

	return 1;
}


// �ڽ���_�������ٰ���
int ParseM4011(const double& timestamp, const char* in_buff, DF_KOSPI_MKT_OPR_DCLS* out) {
	KOSPI_MKT_OPR_DCLS* data = (KOSPI_MKT_OPR_DCLS*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����, M4
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������, 01:�ֽ�
	out->mkt_clsf = data->mkt_clsf[0];	//���屸��, 1:�������� 2:�ڽ���
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// �����ڵ�
	out->stk_snr = Str2Int(data->stk_snr, sizeof(data->stk_snr));	// �����Ϸù�ȣ, �����ġ(A0)�� �����Ϸù�ȣ
	memcpy(out->brd_id, data->brd_id, sizeof(data->brd_id));	// ����ID, �� �ڵ尪���� ����
	memcpy(out->brd_evt_id, data->brd_evt_id, sizeof(data->brd_evt_id));	// �����̺�ƮID, �� �ڵ尪���� ����
	memcpy(out->brd_evt_st, data->brd_evt_st, sizeof(data->brd_evt_st));	// �����̺�Ʈ���۽ð�
	out->brd_evt_code = Str2Int(data->brd_evt_code, sizeof(data->brd_evt_code));	// �����̺�Ʈ���뱺�ڵ�, �� �ڵ尪���� ����
	memcpy(out->sess_open_cls_id, data->sess_open_cls_id, sizeof(data->sess_open_cls_id));	// ���ǰ��������ڵ�, BS: ���尳��\n BE: ��������\n SS: ���ǰ���\n SE: ��������\n SH:��������\n SR:�����簳
	memcpy(out->sess_id, data->sess_id, sizeof(data->sess_id));	// ����ID, �� �ڵ尪���� ����
	memcpy(out->pbl_stk_code, data->pbl_stk_code, sizeof(data->pbl_stk_code));	// ����������ڵ�, ������ġ�� ������ �Ǵ� �����ڵ�\n *�������� �����ڵ嵵 ���� �� ����
	memcpy(out->trsp_rsn_code, data->trsp_rsn_code, sizeof(data->trsp_rsn_code));	// �ŷ����������ڵ�, �� �ڵ尪���� ���� *��������(KO) �� " "
	out->trsp_trgg_code = data->trsp_trgg_code[0];	//�ŷ������߻������ڵ�, 1:�ڱ����� 2:�����μ������� 3:�����μ������� 4:�����ڻ�ELW\n 5:����ELW 6:����� 7:�����ڻ�Ҽӽ��� *��������(KO)�� "1" \n9:������(ETN) 2014.11.17
	out->apl_step = Str2Int(data->apl_step, sizeof(data->apl_step));	// ����ܰ�, CB �� ���������� Ȯ��� ����Ǵ� �ܰ�(�� ���� ���� "00")

	return 1;
}


// �ڽ���_����� ����
int ParseI5011(const double& timestamp, const char* in_buff, DF_KOSPI_STGD_INFO* out) {
	KOSPI_STGD_INFO* data = (KOSPI_STGD_INFO*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����, I5
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������, 01:�ֽ�
	out->mkt_clsf = data->mkt_clsf[0];	//���屸��, 1:�������� 2:�ڽ���
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// �����ڵ�, ǥ���ڵ�
	out->snr = Str2Int(data->snr, sizeof(data->snr));	// �Ϸù�ȣ, 1~99999999 �Ǽ�üũ��
	memcpy(out->clsg_date, data->clsg_date, sizeof(data->clsg_date));	// ������, ������� ȸ�� �����(12�� 31��, 6�� 30��, 3�� 31��)\n���⳪ ������ ���� 12���� ��� '1200'�� ǥ�õ�\n���ֽ�, �ؿܿ���, DR : ����(�ִ� 1��)\n�ظ��� : ����(�Ϲ������� 2��, �ִ� 12��)\n��ETF, �ؿ�ETF : �й������(�ִ� 12��)\n����������ȸ��(MF), ������������ȸ�� : �����(�ִ� 12��)\n�ؼ�������ȸ�� : ��������(�Ϲ������� 4��, �ִ� 12��)

	return 1;
}


// �ڽ���_LP ����
int ParseI7011(const double& timestamp, const char* in_buff, DF_KOSPI_LP_INFO* out) {
	KOSPI_LP_INFO* data = (KOSPI_LP_INFO*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����, I7
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������, 01:�ֽ�
	out->mkt_clsf = data->mkt_clsf[0];	//���屸��, 1:�������� 2:�ڽ���
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// �����ڵ�, ǥ���ڵ�
	out->snr = Str2Int(data->snr, sizeof(data->snr));	// �Ϸù�ȣ, 1~99999999 �Ǽ�üũ��
	memcpy(out->mkt_ptcp_nr, data->mkt_ptcp_nr, sizeof(data->mkt_ptcp_nr));	// ���������ڹ�ȣ, ���������ڸ� �ĺ�/������ �� �ִ� ��ȣ\n�� ���������ڰ� ���� �ŷ����� ȸ���̸� �ŷ��Һ���\n���������ڹ�ȣ�� �޸��� ��) '00001'
	memcpy(out->lp_open_date, data->lp_open_date, sizeof(data->lp_open_date));	// LP��������, ���������ް�������
	memcpy(out->lp_cls_date, data->lp_cls_date, sizeof(data->lp_cls_date));	// LP��������, ������������������
	out->min_ask_qty_mtp = Str2Dbl(data->min_ask_qty_mtp, sizeof(data->min_ask_qty_mtp), 0);	// �ּ�ȣ���������, LP/MM ȣ���� �Ÿż��������� �ּҹ��\n��) ���� 10�̰� �Ÿż��������� 10��(���)�̸� LP/MM ȣ����\n100��(���) �̻����� ȣ���ؾ���
	out->max_ask_qty_mtp = Str2Dbl(data->max_ask_qty_mtp, sizeof(data->max_ask_qty_mtp), 0);	// �ִ�ȣ���������, LP/MM ȣ���� �Ÿż��������� �ִ���
	out->ask_prc_sprd_unit_code = data->ask_prc_sprd_unit_code[0];	//ȣ��������������ڵ�, R:���ݺ���\nY:���ͷ�����(ä��)\nT:ȣ�����ݴ��� ���\nA:���밪 (ä��)\n*����Ī:���Ѵ��������ڵ�
	out->ask_prc_sprd_val = Str2Dbl(data->ask_prc_sprd_val, sizeof(data->ask_prc_sprd_val), 8);	// ȣ���������尪, LP/MM ȣ�� ������ �ǹ��� �߻��ϴ� �ֿ켱ȣ����������\n���� �Ǵ� ���� 9(13)V9(8)
	out->off_mkt_ask_sprd_mtp = Str2Dbl(data->off_mkt_ask_sprd_mtp, sizeof(data->off_mkt_ask_sprd_mtp), 0);	// ����ȣ������������, �Ļ�,ELW,ETF�� �����ڻ��� �ؿܽ����� ���� �Ǵ� ������ ��� �ش� ������ ����, �尳����, ��������, ���� ���� ������ �����ڻ��� ���� ��ġ�� �Ǵ��� �� ���� �� ���� ���� ��ະ�� ������ �������� ���� Ȯ��� �������带 ����ϱ� ���� ���\n*����Ī:����ȣ���������尪\n�� ����ȣ���������尪 = ����ȣ������������ * ȣ���������尪\n(Exture���� ����ȣ���������尪�� 0�ΰ�� Exture+������ ȣ���������尪�� ��ġ��Ŵ) 2014.03.03
	out->obgt_ask_sbmt_time_invl = Str2Int(data->obgt_ask_sbmt_time_invl, sizeof(data->obgt_ask_sbmt_time_invl));	// �ǹ�ȣ������ð�����, ����:��(sec)\n00�� �̳��� �ֿ켱ȣ�������� ��ҽ�Ű�� �ŵ�ȣ�� �Ǵ� �ż�ȣ���� ����
	out->ask_min_ask_prc_amt = Str2Dbl(data->ask_min_ask_prc_amt, sizeof(data->ask_min_ask_prc_amt), 3);	// �ŵ��ּ�ȣ���ݾ�, 9(18)V9(3) 2009.07.27
	out->bid_min_ask_prc_amt = Str2Dbl(data->bid_min_ask_prc_amt, sizeof(data->bid_min_ask_prc_amt), 3);	// �ż��ּ�ȣ���ݾ�, 9(18)V9(3) 2009.07.27
	out->min_ask_amt = Str2Dbl(data->min_ask_amt, sizeof(data->min_ask_amt), 3);	// �ּ�ȣ���ݾ�, 9(18)V9(3) (2015.11.23 �߰�)\nMM(����������)ȣ���� �ּұݾ�\n��LP�ּ�ȣ����������� ��Ÿ������ ���, LP�ּ�ȣ����������� ���� ������ ��� �ش� �ʵ�� ����
	out->max_ask_amt = Str2Dbl(data->max_ask_amt, sizeof(data->max_ask_amt), 3);	// �ִ�ȣ���ݾ�, 9(18)V9(3) (2015.11.23 �߰�)\n�ִ�ȣ���ݾ�

	return 1;
}


// �ڽ���_������
int ParseB5011(const double& timestamp, const char* in_buff, DF_KOSPI_CUR_FLCT* out) {
	KOSPI_CUR_FLCT* data = (KOSPI_CUR_FLCT*)in_buff;

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


// �ڽ���_�ð��ܴ��ϰ�_��Ŀ����
int ParseB4011(const double& timestamp, const char* in_buff, DF_KOSPI_OFH_RCVR* out) {
	KOSPI_OFH_RCVR* data = (KOSPI_OFH_RCVR*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����, B4:�ð��ܴ��ϰ� �ü�, B3:�ð��ܴ��ϰ�����
	out->info_clsf = Str2Int(data->info_clsf, sizeof(data->info_clsf));	// ��������, 01:�ֽ�
	out->mkt_clsf = Str2Int(data->mkt_clsf, sizeof(data->mkt_clsf));	// ���屸��, 1:�������� 2:�ڽ���
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// �����ڵ�, ǥ���ڵ�
	out->stk_snr = Str2Int(data->stk_snr, sizeof(data->stk_snr));	// �����Ϸù�ȣ, �����ġ(A0)�� �����Ϸù�ȣ 2014.03.03
	out->ofhr_cnst_clsf = data->ofhr_cnst_clsf[0];	//�ð��ܴ��ϰ���񱸺�, 0:�ǴܺҰ� 1:���� 2:��� 3:���� 4:���� 5:�϶�
	out->ofhr_cnst = Str2Int(data->ofhr_cnst, sizeof(data->ofhr_cnst));	// �ð��ܴ��ϰ����, ����:��
	out->ofhr_cnst_ceil = Str2Int(data->ofhr_cnst_ceil, sizeof(data->ofhr_cnst_ceil));	// �ð��ܴ��ϰ����Ѱ�
	out->ofhr_cnst_flr = Str2Int(data->ofhr_cnst_flr, sizeof(data->ofhr_cnst_flr));	// �ð��ܴ��ϰ����Ѱ�
	out->ofhr_cnst_cur = Str2Int(data->ofhr_cnst_cur, sizeof(data->ofhr_cnst_cur));	// �ð��ܴ��ϰ����簡
	out->ofhr_cnst_open = Str2Int(data->ofhr_cnst_open, sizeof(data->ofhr_cnst_open));	// �ð��ܴ��ϰ��ð�
	out->ofhr_cnst_hi = Str2Int(data->ofhr_cnst_hi, sizeof(data->ofhr_cnst_hi));	// �ð��ܴ��ϰ���
	out->ofhr_cnst_lo = Str2Int(data->ofhr_cnst_lo, sizeof(data->ofhr_cnst_lo));	// �ð��ܴ��ϰ�����
	out->ofhr_cnst_ask = Str2Int(data->ofhr_cnst_ask, sizeof(data->ofhr_cnst_ask));	// �ð��ܴ��ϰ��ŵ�ȣ��
	out->ofhr_cnst_bid = Str2Int(data->ofhr_cnst_bid, sizeof(data->ofhr_cnst_bid));	// �ð��ܴ��ϰ��ż�ȣ��
	out->ofhr_cnst_cum_ccls_qty = Str2Dbl(data->ofhr_cnst_cum_ccls_qty, sizeof(data->ofhr_cnst_cum_ccls_qty), 0);	// �ð��ܴ��ϰ����� ü�����
	out->ofhr_cnst_cum_trd_val = Str2Dbl(data->ofhr_cnst_cum_trd_val, sizeof(data->ofhr_cnst_cum_trd_val), 0);	// �ð��ܴ��ϰ����� �ŷ����
	out->tot_cum_ccls_qty = Str2Dbl(data->tot_cum_ccls_qty, sizeof(data->tot_cum_ccls_qty), 0);	// ��ü �� ����ü�����, ����:�� �ش��� ��ü ����
	out->tot_cum_trd_val = Str2Dbl(data->tot_cum_trd_val, sizeof(data->tot_cum_trd_val), 0);	// ��ü �� �����ŷ����, ����:�� �ش��� ��ü ����
	out->ofhr_mkt_clsf = Str2Int(data->ofhr_mkt_clsf, sizeof(data->ofhr_mkt_clsf));	// �ð��ܴ��ϰ��屸��, 0:�ʱⰪ 1:�ð��ܴ��ϰ����� 2:�ð��ܴ��ϰ�����
	out->trsp_flg = data->trsp_flg[0];	//�ŷ���������, Y, N
	out->trend_flg = data->trend_flg[0];	//�Ǽ�/�⼼ ����, 0:�ʱⰪ 1:�Ǽ� 2:�⼼ 3:�ŷ��� 4:�ð����ذ������� �⼼

	return 1;
}


// �ڽ���_�ð��ܴ��ϰ�_��Ŀ����_����
int ParseB3011(const double& timestamp, const char* in_buff, DF_KOSPI_OFH_RCVR_FINAL* out) {
	KOSPI_OFH_RCVR_FINAL* data = (KOSPI_OFH_RCVR_FINAL*)in_buff;

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
	out->ofhr_cnst_cum_ccls_qty = Str2Dbl(data->ofhr_cnst_cum_ccls_qty, sizeof(data->ofhr_cnst_cum_ccls_qty), 0);	// �ð��ܴ��ϰ����� ü�����
	out->ofhr_cnst_cum_trd_val = Str2Dbl(data->ofhr_cnst_cum_trd_val, sizeof(data->ofhr_cnst_cum_trd_val), 0);	// �ð��ܴ��ϰ����� �ŷ����
	out->tot_cum_ccls_qty = Str2Dbl(data->tot_cum_ccls_qty, sizeof(data->tot_cum_ccls_qty), 0);	// ��ü �� ����ü�����
	out->tot_cum_trd_val = Str2Dbl(data->tot_cum_trd_val, sizeof(data->tot_cum_trd_val), 0);	// ��ü �� �����ŷ����
	out->ofhr_mkt_clsf = data->ofhr_mkt_clsf[0];	//�ð��ܴ��ϰ��屸��, 0:�ʱⰪ 1:�ð��ܴ��ϰ����� 2:�ð��ܴ��ϰ�����
	out->trsp_flg = data->trsp_flg[0];	//�ŷ���������, Y, N
	out->trend_flg = data->trend_flg[0];	//�Ǽ�/�⼼ ����, 0:�ʱⰪ 1:�Ǽ� 2:�⼼ 3:�ŷ��� 4:�ð����ذ������� �⼼

	return 1;
}


// �ڽ���_ȣ���ܷ�_LPȣ��_����
int ParseB6011(const double& timestamp, const char* in_buff, DF_KOSPI_ASK_RSD_WOLP* out) {
	int i=0;
	KOSPI_ASK_RSD_WOLP* data = (KOSPI_ASK_RSD_WOLP*)in_buff;

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
	out->ofhr_ask_tot_rsd = Str2Dbl(data->ofhr_ask_tot_rsd, sizeof(data->ofhr_ask_tot_rsd), 0);	// �������Ľð��� �ŵ���ȣ���ܷ�, ����ID�� "G3"�� ��� ������
	out->ofhr_bid_tot_rsd = Str2Dbl(data->ofhr_bid_tot_rsd, sizeof(data->ofhr_bid_tot_rsd), 0);	// �������Ľð��� �ż���ȣ���ܷ�, ����ID�� "G3"�� ��� ������
	memcpy(out->sess_id, data->sess_id, sizeof(data->sess_id));	// ����ID, �� �ڵ尪���� ����
	memcpy(out->brd_id, data->brd_id, sizeof(data->brd_id));	// ����ID, �� �ڵ尪���� ����
	out->exp_ccls_prc = Str2Int(data->exp_ccls_prc, sizeof(data->exp_ccls_prc));	// ����ü�ᰡ��
	out->exp_ccls_qty = Str2Dbl(data->exp_ccls_qty, sizeof(data->exp_ccls_qty), 0);	// ����ü�����
	out->cmpt_msv_dir_clsf = Str2Int(data->cmpt_msv_dir_clsf, sizeof(data->cmpt_msv_dir_clsf));	// ����뷮 ���ⱸ��, 0:�ش����, 1:�ŵ�, 2:�ż�

	return 1;
}


// �ڽ���_ȣ���ܷ�_LPȣ��_����
int ParseB7011(const double& timestamp, const char* in_buff, DF_KOSPI_ASK_RSD_WLP* out) {
	int i=0;
	KOSPI_ASK_RSD_WLP* data = (KOSPI_ASK_RSD_WLP*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����, B7
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������, 01:������������ 02:ELW
	out->mkt_clsf = data->mkt_clsf[0];	//���屸��, 1:��������
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// �����ڵ�, ǥ���ڵ�
	out->stk_snr = Str2Int(data->stk_snr, sizeof(data->stk_snr));	// �����Ϸù�ȣ, �����ġ(A0)�� �����Ϸù�ȣ
	out->cum_ccls_qty = Str2Dbl(data->cum_ccls_qty, sizeof(data->cum_ccls_qty), 0);	// ����ü�����

	for ( i=0 ; i<10 ; i++ ) {
		out->lob_infos[i].ask_prc = Str2Int(data->lob_infos[i].ask_prc, sizeof(data->lob_infos[i].ask_prc));	// �ŵ�ȣ��
		out->lob_infos[i].bid_prc = Str2Int(data->lob_infos[i].bid_prc, sizeof(data->lob_infos[i].bid_prc));	// �ż�ȣ��
		out->lob_infos[i].ask_vol_rsd = Str2Dbl(data->lob_infos[i].ask_vol_rsd, sizeof(data->lob_infos[i].ask_vol_rsd), 0);	// �ŵ�ȣ�� �ܷ�
		out->lob_infos[i].bid_vol_rsd = Str2Dbl(data->lob_infos[i].bid_vol_rsd, sizeof(data->lob_infos[i].bid_vol_rsd), 0);	// �ż�ȣ�� �ܷ�
		out->lob_infos[i].lp_ask_vol_rsd = Str2Dbl(data->lob_infos[i].lp_ask_vol_rsd, sizeof(data->lob_infos[i].lp_ask_vol_rsd), 0);	// LP �ŵ�ȣ�� �ܷ�
		out->lob_infos[i].lp_bid_vol_rsd = Str2Dbl(data->lob_infos[i].lp_bid_vol_rsd, sizeof(data->lob_infos[i].lp_bid_vol_rsd), 0);	// LP �ż�ȣ�� �ܷ�
	}   // ȣ��

	out->ask_10_tot_rsd = Str2Dbl(data->ask_10_tot_rsd, sizeof(data->ask_10_tot_rsd), 0);	// 10�ܰ�ȣ���ŵ����ܷ�
	out->bid_10_tot_rsd = Str2Dbl(data->bid_10_tot_rsd, sizeof(data->bid_10_tot_rsd), 0);	// 10�ܰ�ȣ���ż����ܷ�
	out->ofhr_ask_tot_rsd = Str2Dbl(data->ofhr_ask_tot_rsd, sizeof(data->ofhr_ask_tot_rsd), 0);	// �������Ľð��� �ŵ���ȣ���ܷ�, ����ID�� "G3"�� ��� ������ \n ��ELW�� �ð��ܰŷ� ����
	out->ofhr_bid_tot_rsd = Str2Dbl(data->ofhr_bid_tot_rsd, sizeof(data->ofhr_bid_tot_rsd), 0);	// �������Ľð��� �ż���ȣ���ܷ�, ����ID�� "G3"�� ��� ������\n ��ELW�� �ð��ܰŷ� ����
	memcpy(out->sess_id, data->sess_id, sizeof(data->sess_id));	// ����ID, �� �ڵ尪���� ����
	memcpy(out->brd_id, data->brd_id, sizeof(data->brd_id));	// ����ID, �� �ڵ尪���� ����
	out->exp_ccls_prc = Str2Int(data->exp_ccls_prc, sizeof(data->exp_ccls_prc));	// ����ü�ᰡ��
	out->exp_ccls_qty = Str2Dbl(data->exp_ccls_qty, sizeof(data->exp_ccls_qty), 0);	// ����ü�����
	out->cmpt_msv_dir_clsf = Str2Int(data->cmpt_msv_dir_clsf, sizeof(data->cmpt_msv_dir_clsf));	// ����뷮 ���ⱸ��, 0:�ش����, 1:�ŵ�, 2:�ż�

	return 1;
}


// �ڽ���_�尳����_ȣ���ܷ�
int ParseB8011(const double& timestamp, const char* in_buff, DF_KOSPI_BOPEN_ASK_RSD* out) {
	KOSPI_BOPEN_ASK_RSD* data = (KOSPI_BOPEN_ASK_RSD*)in_buff;

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


// �ڽ���_�����������ں�
int ParseC0011(const double& timestamp, const char* in_buff, DF_KOSPI_BYIND_BYINV* out) {
	KOSPI_BYIND_BYINV* data = (KOSPI_BYIND_BYINV*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����, C0
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������, 01:�ֽ�
	out->mkt_clsf = data->mkt_clsf[0];	//���屸��, 1:�������� 2:�ڽ���
	memcpy(out->cmpt_time, data->cmpt_time, sizeof(data->cmpt_time));	// ����ð�, 90�� �ֱ�
	memcpy(out->inv_code, data->inv_code, sizeof(data->inv_code));	// �������ڵ�, ���ڵ尪���� ����\n*�ڵ�'7000'�� ����, ������� �׸� 0���� ���� (20181210)
	memcpy(out->ind_code, data->ind_code, sizeof(data->ind_code));	// �����ڵ�, ���ڵ尪������ ���������ڵ�з� ����\n�������;�ڽ�����������, �ڽ�����������, �ڽ���200����
	out->ask_ccls_qty = Str2Dbl(data->ask_ccls_qty, sizeof(data->ask_ccls_qty), 0);	// �ŵ�ü�����, ����:��
	out->ask_trd_val = Str2Dbl(data->ask_trd_val, sizeof(data->ask_trd_val), 0);	// �ŵ��ŷ����, ����:��
	out->bid_ccls_qty = Str2Dbl(data->bid_ccls_qty, sizeof(data->bid_ccls_qty), 0);	// �ż�ü�����, ����:��
	out->bid_trd_val = Str2Dbl(data->bid_trd_val, sizeof(data->bid_trd_val), 0);	// �ż��ŷ����, ����:��

	return 1;
}


// �ڽ���_���α׷��Ÿ� ȣ��
int ParseC3011(const double& timestamp, const char* in_buff, DF_KOSPI_PRGTRD_ASK* out) {
	KOSPI_PRGTRD_ASK* data = (KOSPI_PRGTRD_ASK*)in_buff;

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
	out->idx_abtg_ask_ccls_qty = Str2Dbl(data->idx_abtg_ask_ccls_qty, sizeof(data->idx_abtg_ask_ccls_qty), 0);	// �������͸ŵ���Ź ü�����
	out->idx_abtg_ask_self_ccls_qty = Str2Dbl(data->idx_abtg_ask_self_ccls_qty, sizeof(data->idx_abtg_ask_self_ccls_qty), 0);	// �������͸ŵ��ڱ� ü�����
	out->idx_abtg_bid_ccls_qty = Str2Dbl(data->idx_abtg_bid_ccls_qty, sizeof(data->idx_abtg_bid_ccls_qty), 0);	// �������͸ż���Ź ü�����
	out->idx_abtg_bid_self_ccls_qty = Str2Dbl(data->idx_abtg_bid_self_ccls_qty, sizeof(data->idx_abtg_bid_self_ccls_qty), 0);	// �������͸ż��ڱ� ü�����
	out->idx_nabtg_ask_ccls_qty = Str2Dbl(data->idx_nabtg_ask_ccls_qty, sizeof(data->idx_nabtg_ask_ccls_qty), 0);	// ���������͸ŵ���Ź ü�����
	out->idx_nabtg_ask_self_ccls_qty = Str2Dbl(data->idx_nabtg_ask_self_ccls_qty, sizeof(data->idx_nabtg_ask_self_ccls_qty), 0);	// ���������͸ŵ��ڱ� ü�����
	out->idx_nabtg_bid_ccls_qty = Str2Dbl(data->idx_nabtg_bid_ccls_qty, sizeof(data->idx_nabtg_bid_ccls_qty), 0);	// ���������͸ż���Ź ü�����
	out->idx_nabtg_bid_self_ccls_qty = Str2Dbl(data->idx_nabtg_bid_self_ccls_qty, sizeof(data->idx_nabtg_bid_self_ccls_qty), 0);	// ���������͸ż��ڱ� ü�����
	out->idx_abtg_ask_ccls_val = Str2Dbl(data->idx_abtg_ask_ccls_val, sizeof(data->idx_abtg_ask_ccls_val), 0);	// �������͸ŵ���Ź ü��ݾ�
	out->idx_abtg_ask_self_ccls_val = Str2Dbl(data->idx_abtg_ask_self_ccls_val, sizeof(data->idx_abtg_ask_self_ccls_val), 0);	// �������͸ŵ��ڱ� ü��ݾ�
	out->idx_abtg_bid_ccls_val = Str2Dbl(data->idx_abtg_bid_ccls_val, sizeof(data->idx_abtg_bid_ccls_val), 0);	// �������͸ż���Ź ü��ݾ�
	out->idx_abtg_bid_self_ccls_val = Str2Dbl(data->idx_abtg_bid_self_ccls_val, sizeof(data->idx_abtg_bid_self_ccls_val), 0);	// �������͸ż��ڱ� ü��ݾ�
	out->idx_nabtg_ask_ccls_val = Str2Dbl(data->idx_nabtg_ask_ccls_val, sizeof(data->idx_nabtg_ask_ccls_val), 0);	// ���������͸ŵ���Ź ü��ݾ�
	out->idx_nabtg_ask_self_ccls_val = Str2Dbl(data->idx_nabtg_ask_self_ccls_val, sizeof(data->idx_nabtg_ask_self_ccls_val), 0);	// ���������͸ŵ��ڱ� ü��ݾ�
	out->idx_nabtg_bid_ccls_val = Str2Dbl(data->idx_nabtg_bid_ccls_val, sizeof(data->idx_nabtg_bid_ccls_val), 0);	// ���������͸ż���Ź ü��ݾ�
	out->idx_nabtg_bid_self_ccls_val = Str2Dbl(data->idx_nabtg_bid_self_ccls_val, sizeof(data->idx_nabtg_bid_self_ccls_val), 0);	// ���������͸ż��ڱ� ü��ݾ�
	out->post_idx_abtg_ask_rsd = Str2Dbl(data->post_idx_abtg_ask_rsd, sizeof(data->post_idx_abtg_ask_rsd), 0);	// �������͸ŵ�ȣ���ܷ�, 2011.05.30 �ű�
	out->post_idx_abtg_bid_rsd = Str2Dbl(data->post_idx_abtg_bid_rsd, sizeof(data->post_idx_abtg_bid_rsd), 0);	// �������͸ż�ȣ���ܷ�, 2011.05.30 �ű�
	out->post_idx_nabtg_ask_rsd = Str2Dbl(data->post_idx_nabtg_ask_rsd, sizeof(data->post_idx_nabtg_ask_rsd), 0);	// ���������͸ŵ�ȣ���ܷ�, 2011.05.30 �ű�
	out->post_idx_nabtg_bid_rsd = Str2Dbl(data->post_idx_nabtg_bid_rsd, sizeof(data->post_idx_nabtg_bid_rsd), 0);	// ���������͸ż�ȣ���ܷ�, 2011.05.30 �ű�

	return 1;
}


// �ڽ���_���α׷��Ÿ� ��ü����
int ParseJ0011(const double& timestamp, const char* in_buff, DF_KOSPI_PRGTRD_TOT* out) {
	KOSPI_PRGTRD_TOT* data = (KOSPI_PRGTRD_TOT*)in_buff;

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
	out->idx_abtg_ask_ccls_qty = Str2Dbl(data->idx_abtg_ask_ccls_qty, sizeof(data->idx_abtg_ask_ccls_qty), 0);	// �������͸ŵ���Ź ü�����
	out->idx_abtg_ask_self_ccls_qty = Str2Dbl(data->idx_abtg_ask_self_ccls_qty, sizeof(data->idx_abtg_ask_self_ccls_qty), 0);	// �������͸ŵ��ڱ� ü�����
	out->idx_abtg_bid_ccls_qty = Str2Dbl(data->idx_abtg_bid_ccls_qty, sizeof(data->idx_abtg_bid_ccls_qty), 0);	// �������͸ż���Ź ü�����
	out->idx_abtg_bid_self_ccls_qty = Str2Dbl(data->idx_abtg_bid_self_ccls_qty, sizeof(data->idx_abtg_bid_self_ccls_qty), 0);	// �������͸ż��ڱ� ü�����
	out->idx_nabtg_ask_ccls_qty = Str2Dbl(data->idx_nabtg_ask_ccls_qty, sizeof(data->idx_nabtg_ask_ccls_qty), 0);	// ���������͸ŵ���Ź ü�����
	out->idx_nabtg_ask_self_ccls_qty = Str2Dbl(data->idx_nabtg_ask_self_ccls_qty, sizeof(data->idx_nabtg_ask_self_ccls_qty), 0);	// ���������͸ŵ��ڱ� ü�����
	out->idx_nabtg_bid_ccls_qty = Str2Dbl(data->idx_nabtg_bid_ccls_qty, sizeof(data->idx_nabtg_bid_ccls_qty), 0);	// ���������͸ż���Ź ü�����
	out->idx_nabtg_bid_self_ccls_qty = Str2Dbl(data->idx_nabtg_bid_self_ccls_qty, sizeof(data->idx_nabtg_bid_self_ccls_qty), 0);	// ���������͸ż��ڱ� ü�����
	out->idx_abtg_ask_ccls_val = Str2Dbl(data->idx_abtg_ask_ccls_val, sizeof(data->idx_abtg_ask_ccls_val), 0);	// �������͸ŵ���Ź ü��ݾ�
	out->idx_abtg_ask_self_ccls_val = Str2Dbl(data->idx_abtg_ask_self_ccls_val, sizeof(data->idx_abtg_ask_self_ccls_val), 0);	// �������͸ŵ��ڱ� ü��ݾ�
	out->idx_abtg_bid_ccls_val = Str2Dbl(data->idx_abtg_bid_ccls_val, sizeof(data->idx_abtg_bid_ccls_val), 0);	// �������͸ż���Ź ü��ݾ�
	out->idx_abtg_bid_self_ccls_val = Str2Dbl(data->idx_abtg_bid_self_ccls_val, sizeof(data->idx_abtg_bid_self_ccls_val), 0);	// �������͸ż��ڱ� ü��ݾ�
	out->idx_nabtg_ask_ccls_val = Str2Dbl(data->idx_nabtg_ask_ccls_val, sizeof(data->idx_nabtg_ask_ccls_val), 0);	// ���������͸ŵ���Ź ü��ݾ�
	out->idx_nabtg_ask_self_ccls_val = Str2Dbl(data->idx_nabtg_ask_self_ccls_val, sizeof(data->idx_nabtg_ask_self_ccls_val), 0);	// ���������͸ŵ��ڱ� ü��ݾ�
	out->idx_nabtg_bid_ccls_val = Str2Dbl(data->idx_nabtg_bid_ccls_val, sizeof(data->idx_nabtg_bid_ccls_val), 0);	// ���������͸ż���Ź ü��ݾ�
	out->idx_nabtg_bid_self_ccls_val = Str2Dbl(data->idx_nabtg_bid_self_ccls_val, sizeof(data->idx_nabtg_bid_self_ccls_val), 0);	// ���������͸ż��ڱ� ü��ݾ�
	out->post_idx_abtg_ask_rsd = Str2Dbl(data->post_idx_abtg_ask_rsd, sizeof(data->post_idx_abtg_ask_rsd), 0);	// �������͸ŵ�ȣ���ܷ�
	out->post_idx_abtg_bid_rsd = Str2Dbl(data->post_idx_abtg_bid_rsd, sizeof(data->post_idx_abtg_bid_rsd), 0);	// �������͸ż�ȣ���ܷ�
	out->post_idx_nabtg_ask_rsd = Str2Dbl(data->post_idx_nabtg_ask_rsd, sizeof(data->post_idx_nabtg_ask_rsd), 0);	// ���������͸ŵ�ȣ���ܷ�
	out->post_idx_nabtg_bid_rsd = Str2Dbl(data->post_idx_nabtg_bid_rsd, sizeof(data->post_idx_nabtg_bid_rsd), 0);	// ���������͸ż�ȣ���ܷ�

	return 1;
}


// �ڽ���_���α׷��Ÿ� ��������
int ParseC5011(const double& timestamp, const char* in_buff, DF_KOSPI_PRGTRD_DCLS* out) {
	KOSPI_PRGTRD_DCLS* data = (KOSPI_PRGTRD_DCLS*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����, C5
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������, 01:�ֽ�
	out->mkt_clsf = data->mkt_clsf[0];	//���屸��, 1:�������� 2:�ڽ���
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// �����ڵ�
	out->snr = Str2Int(data->snr, sizeof(data->snr));	// �Ϸù�ȣ, 1~99999999 �����Ϸù�ȣ 2014.03.03
	out->prior_dcls_new_ask_qty = Str2Dbl(data->prior_dcls_new_ask_qty, sizeof(data->prior_dcls_new_ask_qty), 0);	// �������ýű�ȣ�� �ŵ�����, ���� : ��\n�׸����:�ŵ����û�������->�������ýű�ȣ���ŵ�����
	out->prior_dcls_new_bid_qty = Str2Dbl(data->prior_dcls_new_bid_qty, sizeof(data->prior_dcls_new_bid_qty), 0);	// �������ýű�ȣ�� �ż�����, ���� : ��\n�׸����:�ż����û�������->�������ýű�ȣ���ż�����
	out->prior_dcls_sbmt_ask_qty = Str2Dbl(data->prior_dcls_sbmt_ask_qty, sizeof(data->prior_dcls_sbmt_ask_qty), 0);	// �������ñ�����ȣ�� �ŵ�����, ���� : ��\n�׸����:�ŵ����û�����������->�������ñ�����ȣ���ŵ�����
	out->prior_dcls_sbmt_bid_qty = Str2Dbl(data->prior_dcls_sbmt_bid_qty, sizeof(data->prior_dcls_sbmt_bid_qty), 0);	// �������ñ�����ȣ�� �ż�����, ���� : ��\n�׸����:�ż����û�����������->�������ñ�����ȣ���ż�����
	out->post_dcls_ask_qty = Str2Dbl(data->post_dcls_ask_qty, sizeof(data->post_dcls_ask_qty), 0);	// ���İ��øŵ�����, ���� : ��, �ű� 2011.05.03
	out->post_dcls_bid_qty = Str2Dbl(data->post_dcls_bid_qty, sizeof(data->post_dcls_bid_qty), 0);	// ���İ��øż�����, ���� : ��, �ű� 2011.05.03

	return 1;
}


// ���� ���α׷��Ÿ� �����ں� �Ÿ���Ȳ
int ParseP0011(const double& timestamp, const char* in_buff, DF_PRGTRD_BYINV_STAT* out) {
	PRGTRD_BYINV_STAT* data = (PRGTRD_BYINV_STAT*)in_buff;

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


// �ڽ���_���ŵ�
int ParseI8011(const double& timestamp, const char* in_buff, DF_KOSPI_SHORT* out) {
	KOSPI_SHORT* data = (KOSPI_SHORT*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����, I8
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������, 01:�ֽ�
	out->mkt_clsf = data->mkt_clsf[0];	//���屸��, 1:�������� 2:�ڽ���
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// �����ڵ�, ǥ���ڵ�
	out->snr = Str2Int(data->snr, sizeof(data->snr));	// �Ϸù�ȣ, 1~99999999 �����Ϸù�ȣ 2014.03.03
	out->short_brwg_ask_ccls_qty = Str2Dbl(data->short_brwg_ask_ccls_qty, sizeof(data->short_brwg_ask_ccls_qty), 0);	// ���ŵ��������Ǹŵ� ü�����, ����:��
	out->short_brwg_ask_trd_val = Str2Dbl(data->short_brwg_ask_trd_val, sizeof(data->short_brwg_ask_trd_val), 0);	// ���ŵ��������Ǹŵ� �ŷ����, ����:��

	return 1;
}


// �ڽ���_Buy-in_�������
int ParseO4011(const double& timestamp, const char* in_buff, DF_KOSPI_BIN_EXCQ* out) {
	KOSPI_BIN_EXCQ* data = (KOSPI_BIN_EXCQ*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����, O4
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������, 01:�ֽ�
	out->mkt_clsf = data->mkt_clsf[0];	//���屸��, 1:��������, 2:�ڽ���, 8:�ڳؽ�
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// �����ڵ�, ǥ���ڵ� �Ǵ� "999999999999" ���߰��̵� ����
	out->snr = Str2Int(data->snr, sizeof(data->snr));	// �Ϸù�ȣ, �� Buy-in�����ڵ庰�� �Ϸù�ȣ ����
	memcpy(out->trsm_date, data->trsm_date, sizeof(data->trsm_date));	// ��������, YYYYMMDD
	out->bin_clsf_code = data->bin_clsf_code[0];	//Buy-in�����ڵ�, 1: �Ϲ� Buy-in, 2: ���� Buy-in
	out->scrt_grp_id = Str2Int(data->scrt_grp_id, sizeof(data->scrt_grp_id));	// ���Ǳ׷�ID, ST:�ֽ�, MF:��������ȸ��, RT:����, SC:��������ȸ��,\nIF:������������ȸ��, DR:��Ź����, SW:�����μ�������,\nSR:�����μ�������, EW:�ֽĿ���Ʈ����, EF:���������ݵ�,\nBC:��������, FE:�ؿ�ETF, FS:�ؿܿ���,\nEN:ETN(2014.11.17)
	out->bin_exc_qty = Str2Dbl(data->bin_exc_qty, sizeof(data->bin_exc_qty), 0);	// Buy-in �������

	return 1;
}


// �ڽ���_Buy-in_�������
int ParseO4012(const double& timestamp, const char* in_buff, DF_KOSDQ_BIN_EXCQ* out) {
	KOSDQ_BIN_EXCQ* data = (KOSDQ_BIN_EXCQ*)in_buff;

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


// �ڳؽ�_Buy-in_�������
int ParseO4018(const double& timestamp, const char* in_buff, DF_KONEX_BIN_EXCQ* out) {
	KONEX_BIN_EXCQ* data = (KONEX_BIN_EXCQ*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����, O4
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������, 01:�ֽ�
	out->mkt_clsf = data->mkt_clsf[0];	//���屸��, 8:�ڳؽ�
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// �����ڵ�, ǥ���ڵ� �Ǵ� "999999999999" ���߰��̵� ����
	out->snr = Str2Int(data->snr, sizeof(data->snr));	// �Ϸù�ȣ, �� Buy-in�����ڵ庰�� �Ϸù�ȣ ����
	memcpy(out->trsm_date, data->trsm_date, sizeof(data->trsm_date));	// ��������, YYYYMMDD
	out->bin_clsf_code = data->bin_clsf_code[0];	//Buy-in�����ڵ�, 1: �Ϲ� Buy-in, 2: ���� Buy-in
	out->scrt_grp_id = Str2Int(data->scrt_grp_id, sizeof(data->scrt_grp_id));	// ���Ǳ׷�ID, ST:�ֽ�, MF:��������ȸ��, RT:����, SC:��������ȸ��,\nIF:������������ȸ��, DR:��Ź����, SW:�����μ�������,\nSR:�����μ�������, EW:�ֽĿ���Ʈ����, EF:���������ݵ�,\nBC:��������, FE:�ؿ�ETF, FS:�ؿܿ���
	out->bin_exc_qty = Str2Dbl(data->bin_exc_qty, sizeof(data->bin_exc_qty), 0);	// Buy-in �������

	return 1;
}


// �ڽ���_�ü�����
int ParseB1011(const double& timestamp, const char* in_buff, DF_KOSPI_MKT_PRC_CLS* out) {
	KOSPI_MKT_PRC_CLS* data = (KOSPI_MKT_PRC_CLS*)in_buff;

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
	out->high = Str2Int(data->high, sizeof(data->high));	// ��, ������ ��
	out->low = Str2Int(data->low, sizeof(data->low));	// ����, ������ ����
	out->ask_prc = Str2Int(data->ask_prc, sizeof(data->ask_prc));	// �ŵ�ȣ��, B1�� 0�� SET
	out->bid_prc = Str2Int(data->bid_prc, sizeof(data->bid_prc));	// �ż�ȣ��, B1�� 0�� SET
	out->cum_ccls_qty = Str2Dbl(data->cum_ccls_qty, sizeof(data->cum_ccls_qty), 0);	// ����ü�����, ����:�� �ؽð��ܴ��ϰ�, BUY-IN�� ������ ��� ü����� �ջ�
	out->cum_trd_val = Str2Dbl(data->cum_trd_val, sizeof(data->cum_trd_val), 0);	// �����ŷ����, ����:�� �ؽð��ܴ��ϰ�, BUY-IN�� ������ ��� �ŷ���� �ջ�
	out->trend_flg = data->trend_flg[0];	//�Ǽ�/�⼼ ����, 0:�ʱⰪ 1:�Ǽ� 2:�⼼ 3:�ŷ��� 4:�ð����ذ������� �⼼
	memcpy(out->brd_evt_id, data->brd_evt_id, sizeof(data->brd_evt_id));	// �����̺�ƮID, B1/B2 ������ �����̺�ƮID ������(���� ���°��� ���۵� �� ����). ����, �ش� �׸� '000' ���� ����. 2014.03.24)
	memcpy(out->brd_id, data->brd_id, sizeof(data->brd_id));	// ����ID, �� �ڵ尪���� ����
	out->trsp_flg = data->trsp_flg[0];	//�ŷ���������, Y, N
	out->bopen_ofhr_ccls_qty = Str2Dbl(data->bopen_ofhr_ccls_qty, sizeof(data->bopen_ofhr_ccls_qty), 0);	// �尳�����ð������� ü�����, �뷮, �ٽ����� ����, ����:��
	out->bopen_ofhr_trd_val = Str2Dbl(data->bopen_ofhr_trd_val, sizeof(data->bopen_ofhr_trd_val), 0);	// �尳�����ð������� �ŷ����, �뷮, �ٽ����� ����, ����:��
	out->opr_time_ccls_qty = Str2Dbl(data->opr_time_ccls_qty, sizeof(data->opr_time_ccls_qty), 0);	// ������ü�����, �뷮, �ٽ����� ����, ����:��
	out->opr_time_trd_val = Str2Dbl(data->opr_time_trd_val, sizeof(data->opr_time_trd_val), 0);	// ������ŷ����, �뷮, �ٽ����� ����, ����:��
	out->ofhr_cls_ccls_qty = Str2Dbl(data->ofhr_cls_ccls_qty, sizeof(data->ofhr_cls_ccls_qty), 0);	// �������Ľð������� ü�����, �뷮, �ٽ����� ����, ����:��
	out->ofhr_cls_trd_val = Str2Dbl(data->ofhr_cls_trd_val, sizeof(data->ofhr_cls_trd_val), 0);	// �������Ľð������� �ŷ����, �뷮, �ٽ����� ����, ����:��
	out->elw_ely_cls_flg = data->elw_ely_cls_flg[0];	//ELW�������Ῡ��, Y,N ��������ELW �� ������ Default 'N' SET 2010.08.30
	out->elw_ely_cls_time = Str2Int(data->elw_ely_cls_time, sizeof(data->elw_ely_cls_time));	// ELW��������ð�, HHMMSS, ELW�������Ῡ�ΰ� 'Y'�� ��츸 ����
	out->cmpt_msv_dir_clsf = Str2Int(data->cmpt_msv_dir_clsf, sizeof(data->cmpt_msv_dir_clsf));	// ����뷮 ���ⱸ��, 0:�ش����, 1:�ŵ�, 2:�ż�
	out->gen_bin_ccls_qty = Str2Dbl(data->gen_bin_ccls_qty, sizeof(data->gen_bin_ccls_qty), 0);	// �Ϲ� Buy-in ü�����, ����:��
	out->gen_bin_ccls_trd_val = Str2Dbl(data->gen_bin_ccls_trd_val, sizeof(data->gen_bin_ccls_trd_val), 0);	// �Ϲ� Buy-in �ŷ����, ����:��
	out->day_bin_ccls_qty = Str2Dbl(data->day_bin_ccls_qty, sizeof(data->day_bin_ccls_qty), 0);	// ���� Buy-in ü�����, ����:��
	out->day_bin_ccls_trd_val = Str2Dbl(data->day_bin_ccls_trd_val, sizeof(data->day_bin_ccls_trd_val), 0);	// ���� Buy-in �ŷ����, ����:��

	return 1;
}


// �ڽ���_�ü�RECOVERY
int ParseB2011(const double& timestamp, const char* in_buff, DF_KOSPI_MKT_PRC_RCVR* out) {
	KOSPI_MKT_PRC_RCVR* data = (KOSPI_MKT_PRC_RCVR*)in_buff;

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
	out->high = Str2Int(data->high, sizeof(data->high));	// ��, ������ ��
	out->low = Str2Int(data->low, sizeof(data->low));	// ����, ������ ����
	out->ask_prc = Str2Int(data->ask_prc, sizeof(data->ask_prc));	// �ŵ�ȣ��, B1�� 0�� SET
	out->bid_prc = Str2Int(data->bid_prc, sizeof(data->bid_prc));	// �ż�ȣ��, B1�� 0�� SET
	out->cum_ccls_qty = Str2Dbl(data->cum_ccls_qty, sizeof(data->cum_ccls_qty), 0);	// ����ü�����, ����:�� �ؽð��ܴ��ϰ�, BUY-IN�� ������ ��� ü����� �ջ�
	out->cum_trd_val = Str2Dbl(data->cum_trd_val, sizeof(data->cum_trd_val), 0);	// �����ŷ����, ����:�� �ؽð��ܴ��ϰ�, BUY-IN�� ������ ��� �ŷ���� �ջ�
	out->trend_flg = data->trend_flg[0];	//�Ǽ�/�⼼ ����, 0:�ʱⰪ 1:�Ǽ� 2:�⼼ 3:�ŷ��� 4:�ð����ذ������� �⼼
	memcpy(out->brd_evt_id, data->brd_evt_id, sizeof(data->brd_evt_id));	// �����̺�ƮID, B1/B2 ������ �����̺�ƮID ������(���� ���°��� ���۵� �� ����). ����, �ش� �׸� '000' ���� ����. 2014.03.24)
	memcpy(out->brd_id, data->brd_id, sizeof(data->brd_id));	// ����ID, �� �ڵ尪���� ����
	out->trsp_flg = data->trsp_flg[0];	//�ŷ���������, Y, N
	out->bopen_ofhr_ccls_qty = Str2Dbl(data->bopen_ofhr_ccls_qty, sizeof(data->bopen_ofhr_ccls_qty), 0);	// �尳�����ð������� ü�����, �뷮, �ٽ����� ����, ����:��
	out->bopen_ofhr_trd_val = Str2Dbl(data->bopen_ofhr_trd_val, sizeof(data->bopen_ofhr_trd_val), 0);	// �尳�����ð������� �ŷ����, �뷮, �ٽ����� ����, ����:��
	out->opr_time_ccls_qty = Str2Dbl(data->opr_time_ccls_qty, sizeof(data->opr_time_ccls_qty), 0);	// ������ü�����, �뷮, �ٽ����� ����, ����:��
	out->opr_time_trd_val = Str2Dbl(data->opr_time_trd_val, sizeof(data->opr_time_trd_val), 0);	// ������ŷ����, �뷮, �ٽ����� ����, ����:��
	out->ofhr_cls_ccls_qty = Str2Dbl(data->ofhr_cls_ccls_qty, sizeof(data->ofhr_cls_ccls_qty), 0);	// �������Ľð������� ü�����, �뷮, �ٽ����� ����, ����:��
	out->ofhr_cls_trd_val = Str2Dbl(data->ofhr_cls_trd_val, sizeof(data->ofhr_cls_trd_val), 0);	// �������Ľð������� �ŷ����, �뷮, �ٽ����� ����, ����:��
	out->elw_ely_cls_flg = data->elw_ely_cls_flg[0];	//ELW�������Ῡ��, Y,N ��������ELW �� ������ Default 'N' SET
	out->elw_ely_cls_time = Str2Int(data->elw_ely_cls_time, sizeof(data->elw_ely_cls_time));	// ELW��������ð�, HHMMSS, ELW�������Ῡ�ΰ� 'Y'�� ��츸 ����
	out->cmpt_msv_dir_clsf = Str2Int(data->cmpt_msv_dir_clsf, sizeof(data->cmpt_msv_dir_clsf));	// ����뷮 ���ⱸ��, 0:�ش����, 1:�ŵ�, 2:�ż�
	out->gen_bin_ccls_qty = Str2Dbl(data->gen_bin_ccls_qty, sizeof(data->gen_bin_ccls_qty), 0);	// �Ϲ� Buy-in ü�����, ����:��
	out->gen_bin_ccls_trd_val = Str2Dbl(data->gen_bin_ccls_trd_val, sizeof(data->gen_bin_ccls_trd_val), 0);	// �Ϲ� Buy-in �ŷ����, ����:��
	out->day_bin_ccls_qty = Str2Dbl(data->day_bin_ccls_qty, sizeof(data->day_bin_ccls_qty), 0);	// ���� Buy-in ü�����, ����:��
	out->day_bin_ccls_trd_val = Str2Dbl(data->day_bin_ccls_trd_val, sizeof(data->day_bin_ccls_trd_val), 0);	// ���� Buy-in �ŷ����, ����:��

	return 1;
}


// �ڽ��� �ܱ��� ������������_Ȯ��ġ
int ParseF1011(const double& timestamp, const char* in_buff, DF_KOSPI_FRGN_INV_INFO* out) {
	KOSPI_FRGN_INV_INFO* data = (KOSPI_FRGN_INV_INFO*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����, F1
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������, 01:�ֽ� 90:��Ÿ
	out->mkt_clsf = data->mkt_clsf[0];	//���屸��, 1:�������� 2:�ڽ��� 3:�������� 7:ä��
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// �����ڵ�, ǥ���ڵ�
	out->snr = Str2Int(data->snr, sizeof(data->snr));	// �Ϸù�ȣ, 1~99999999 �Ǽ�üũ��
	memcpy(out->trd_date, data->trd_date, sizeof(data->trd_date));	// �Ÿ�����, YYYYMMDD
	out->stk_lim_ratio = Str2Dbl(data->stk_lim_ratio, sizeof(data->stk_lim_ratio), 4);	// �����ѵ�����, 9V9999 (��:15%�϶� �� 01500���� ����)
	out->psn_lim_ratio = Str2Dbl(data->psn_lim_ratio, sizeof(data->psn_lim_ratio), 4);	// �����ѵ�����, 9V9999 (��:15%�϶� �� 01500���� ����)
	out->stk_lstd = Str2Dbl(data->stk_lstd, sizeof(data->stk_lstd), 0);	// �����ֽļ�, ����:��
	out->ordbl_qty = Str2Dbl(data->ordbl_qty, sizeof(data->ordbl_qty), 0);	// �ֹ����ɼ���, ����:��
	out->lim_xhs_clsf = data->lim_xhs_clsf[0];	//�ѵ���������, 0:���� 1:�ѵ����� 2:�ѵ�����ű����� 3:�ѵ���������

	return 1;
}


// �ڽ��� �ܱ��� �ֹ����ɼ���
int ParseF2011(const double& timestamp, const char* in_buff, DF_KOSPI_FRGN_ORDL_QTY* out) {
	KOSPI_FRGN_ORDL_QTY* data = (KOSPI_FRGN_ORDL_QTY*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����, F2
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������, 01:�ֽ� 90:��Ÿ
	out->mkt_clsf = data->mkt_clsf[0];	//���屸��, 1:�������� 2:�ڽ��� 3:�������� 7:ä��
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// �����ڵ�, ǥ���ڵ�
	out->ordbl_qty = Str2Dbl(data->ordbl_qty, sizeof(data->ordbl_qty), 0);	// �ֹ����ɼ���, ����:��(����� ����)
	memcpy(out->data_type, data->data_type, sizeof(data->data_type));	// ����������, 01:�ֹ����ɼ���(�ǽð�) 07:����ġ�ֹ����ɼ���(����)

	return 1;
}


// �ڽ��� �ܱ��� �����ֹ�����_����
int ParseF3011(const double& timestamp, const char* in_buff, DF_KOSPI_FRGN_RSVD_ORD_CNCL* out) {
	KOSPI_FRGN_RSVD_ORD_CNCL* data = (KOSPI_FRGN_RSVD_ORD_CNCL*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����, F3
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������, 01:�ֽ�
	out->mkt_clsf = data->mkt_clsf[0];	//���屸��, 1:�������� 2:�ڽ��� 3:��������
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// �����ڵ�, ǥ���ڵ�
	memcpy(out->data_type, data->data_type, sizeof(data->data_type));	// ����������, 01:�����ֹ����� 02:�����ֹ�����
	out->proc_clsf = data->proc_clsf[0];	//ó������, 1:���� 2:���
	memcpy(out->rsvd_ord_date, data->rsvd_ord_date, sizeof(data->rsvd_ord_date));	// �����ֹ�����, YYYYMMDD
	memcpy(out->rsvd_ord_st_time, data->rsvd_ord_st_time, sizeof(data->rsvd_ord_st_time));	// �����ֹ����۽ð�, HHMM
	memcpy(out->rsvd_ord_ed_time, data->rsvd_ord_ed_time, sizeof(data->rsvd_ord_ed_time));	// �����ֹ�����ð�, HHMM

	return 1;
}


// �ڽ��� �ܱ��� Ȯ��ġ������������
int ParseF4011(const double& timestamp, const char* in_buff, DF_KOSPI_FRGN_CFRM_DATA* out) {
	KOSPI_FRGN_CFRM_DATA* data = (KOSPI_FRGN_CFRM_DATA*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����, F4
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������, 01:�ֽ� 90:��Ÿ
	out->mkt_clsf = data->mkt_clsf[0];	//���屸��, 1:�������� 2:�ڽ��� 3:�������� 7:ä��
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// �����ڵ�, ǥ���ڵ�
	out->stk_lim_ratio = Str2Dbl(data->stk_lim_ratio, sizeof(data->stk_lim_ratio), 4);	// �����ѵ�����, 9V9999 (��:15%�϶� �� 01500���� ����)
	out->psn_lim_ratio = Str2Dbl(data->psn_lim_ratio, sizeof(data->psn_lim_ratio), 4);	// �����ѵ�����, 9V9999 (��:15%�϶� �� 01500���� ����)
	out->stk_lstd = Str2Dbl(data->stk_lstd, sizeof(data->stk_lstd), 0);	// �����ֽļ�, ����:��
	out->ordbl_qty = Str2Dbl(data->ordbl_qty, sizeof(data->ordbl_qty), 0);	// �ֹ����ɼ���, ����:��
	out->lim_xhs_clsf = data->lim_xhs_clsf[0];	//�ѵ���������, 0:���� 1:�ѵ��ʰ� 2:�߰� 3:����

	return 1;
}


// �ڽ��� �ܱ��� �ѵ�������ܸŸ�
int ParseF5011(const double& timestamp, const char* in_buff, DF_KOSPI_FRGN_LMT_XHS* out) {
	KOSPI_FRGN_LMT_XHS* data = (KOSPI_FRGN_LMT_XHS*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����, F5
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������, 01:�ֽ�
	out->mkt_clsf = data->mkt_clsf[0];	//���屸��, 1:�������� 2:�ڽ��� 3:��������
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// �����ڵ�, ǥ���ڵ�
	out->clsf = data->clsf[0];	//����, 1:�ܰ��Է� 2:�ܰ����
	out->qty = Str2Int(data->qty, sizeof(data->qty));	// ����, ����:��
	out->prc = Str2Int(data->prc, sizeof(data->prc));	// ����, ����:��
	memcpy(out->proc_time, data->proc_time, sizeof(data->proc_time));	// ó���ð�, HHMMSSMM

	return 1;
}


// �ڽ��� �ܱ��� �Ÿ�_������Ȳ
int ParseF6011(const double& timestamp, const char* in_buff, DF_KOSPI_FRGN_TRD_STAT* out) {
	KOSPI_FRGN_TRD_STAT* data = (KOSPI_FRGN_TRD_STAT*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����, F6
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������, 01:�ֽ�
	out->mkt_clsf = data->mkt_clsf[0];	//���屸��, 1:�������� 2:�ڽ���
	out->snr = Str2Int(data->snr, sizeof(data->snr));	// �Ϸù�ȣ, 1~99999999 �Ǽ�üũ��
	out->clsf = data->clsf[0];	//����, 2:�ŷ��ҸŸ���Ȳ 3:�ŷ��Ұ�����Ȳ \n9:�ڽ��ڸŸ���Ȳ 0:�ڽ��ڰ�����Ȳ
	out->tot_bid_qty = Str2Dbl(data->tot_bid_qty, sizeof(data->tot_bid_qty), 0);	// �Ѹż�����, ����:��
	out->tot_bid_val = Str2Dbl(data->tot_bid_val, sizeof(data->tot_bid_val), 0);	// �Ѹż��ݾ�, ����:��
	out->tot_ask_qty = Str2Dbl(data->tot_ask_qty, sizeof(data->tot_ask_qty), 0);	// �Ѹŵ�����, ����:��
	out->tot_ask_val = Str2Dbl(data->tot_ask_val, sizeof(data->tot_ask_val), 0);	// �Ѹŵ��ݾ�, ����:��
	out->net_bid_qty = Str2SignDouble(data->net_bid_qty_sign, sizeof(data->net_bid_qty_sign) + sizeof(data->net_bid_qty), 0);	// ���ż�����, ����:��
	out->net_val_qty = Str2SignDouble(data->net_bid_val_sign, sizeof(data->net_bid_val_sign) + sizeof(data->net_val_qty), 0);	// ���ż��ݾ�, ����:��

	return 1;
}


// �ڽ��� �ܱ��� �ѵ�������ܸŸ�
int ParseF5012(const double& timestamp, const char* in_buff, DF_KOSDAQ_FRGN_LMT_XHS* out) {
	KOSDAQ_FRGN_LMT_XHS* data = (KOSDAQ_FRGN_LMT_XHS*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����, F5
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������, 01:�ֽ�
	out->mkt_clsf = data->mkt_clsf[0];	//���屸��, 1:�������� 2:�ڽ��� 3:��������
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// �����ڵ�, ǥ���ڵ�
	out->clsf = data->clsf[0];	//����, 1:�ܰ��Է� 2:�ܰ����
	out->qty = Str2Int(data->qty, sizeof(data->qty));	// ����, ����:��
	out->prc = Str2Int(data->prc, sizeof(data->prc));	// ����, ����:��
	memcpy(out->proc_time, data->proc_time, sizeof(data->proc_time));	// ó���ð�, HHMMSSMM

	return 1;
}


// �ڽ��� �ܱ��� �Ÿ�_������Ȳ
int ParseF6012(const double& timestamp, const char* in_buff, DF_KOSDAQ_FRGN_TRD_STAT* out) {
	KOSDAQ_FRGN_TRD_STAT* data = (KOSDAQ_FRGN_TRD_STAT*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����, F6
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������, 01:�ֽ�
	out->mkt_clsf = data->mkt_clsf[0];	//���屸��, 1:�������� 2:�ڽ��� 8:�ڳؽ�
	out->snr = Str2Int(data->snr, sizeof(data->snr));	// �Ϸù�ȣ, 1~99999999 �Ǽ�üũ��
	out->clsf = data->clsf[0];	//����, 2:�ŷ��ҸŸ���Ȳ 3:�ŷ��Ұ�����Ȳ \n9:�ڽ��ڸŸ���Ȳ 0:�ڽ��ڰ�����Ȳ\n5:�ڳؽ��Ÿ���Ȳ 6:�ڳؽ�������Ȳ
	out->tot_bid_qty = Str2Dbl(data->tot_bid_qty, sizeof(data->tot_bid_qty), 0);	// �Ѹż�����, ����:��
	out->tot_bid_val = Str2Dbl(data->tot_bid_val, sizeof(data->tot_bid_val), 0);	// �Ѹż��ݾ�, ����:��
	out->tot_ask_qty = Str2Dbl(data->tot_ask_qty, sizeof(data->tot_ask_qty), 0);	// �Ѹŵ�����, ����:��
	out->tot_ask_val = Str2Dbl(data->tot_ask_val, sizeof(data->tot_ask_val), 0);	// �Ѹŵ��ݾ�, ����:��
	out->net_bid_qty = Str2SignDouble(data->net_bid_qty_sign, sizeof(data->net_bid_qty_sign) + sizeof(data->net_bid_qty), 0);	// ���ż�����, ����:��
	out->net_val_qty = Str2SignDouble(data->net_bid_val_sign, sizeof(data->net_bid_val_sign) + sizeof(data->net_val_qty), 0);	// ���ż��ݾ�, ����:��

	return 1;
}


// �ڽ��� �ܱ��� �����ֹ�����_����
int ParseF3012(const double& timestamp, const char* in_buff, DF_KOSDAQ_FRGN_RSVD_ORD_CNCL* out) {
	KOSDAQ_FRGN_RSVD_ORD_CNCL* data = (KOSDAQ_FRGN_RSVD_ORD_CNCL*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����, F3
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������, 01:�ֽ�
	out->mkt_clsf = data->mkt_clsf[0];	//���屸��, 1:�������� 2:�ڽ��� 3:��������
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// �����ڵ�, ǥ���ڵ�
	memcpy(out->data_type, data->data_type, sizeof(data->data_type));	// ����������, 01:�����ֹ����� 02:�����ֹ�����
	out->proc_clsf = data->proc_clsf[0];	//ó������, 1:���� 2:���
	memcpy(out->rsvd_ord_date, data->rsvd_ord_date, sizeof(data->rsvd_ord_date));	// �����ֹ�����, YYYYMMDD
	memcpy(out->rsvd_ord_st_time, data->rsvd_ord_st_time, sizeof(data->rsvd_ord_st_time));	// �����ֹ����۽ð�, HHMM
	memcpy(out->rsvd_ord_ed_time, data->rsvd_ord_ed_time, sizeof(data->rsvd_ord_ed_time));	// �����ֹ�����ð�, HHMM

	return 1;
}


// �ڽ��� �ܱ��� ������������_Ȯ��ġ
int ParseF1012(const double& timestamp, const char* in_buff, DF_KOSDAQ_FRGN_INV_INFO* out) {
	KOSDAQ_FRGN_INV_INFO* data = (KOSDAQ_FRGN_INV_INFO*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����, F1
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������, 01:�ֽ� 90:��Ÿ
	out->mkt_clsf = data->mkt_clsf[0];	//���屸��, 1:�������� 2:�ڽ��� 3:�������� 7:ä��
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// �����ڵ�, ǥ���ڵ�
	out->snr = Str2Int(data->snr, sizeof(data->snr));	// �Ϸù�ȣ, 1~99999999 �Ǽ�üũ��
	memcpy(out->trd_date, data->trd_date, sizeof(data->trd_date));	// �Ÿ�����, YYYYMMDD
	out->stk_lim_ratio = Str2Dbl(data->stk_lim_ratio, sizeof(data->stk_lim_ratio), 4);	// �����ѵ�����, 9V9999 (��:15%�϶� �� 01500���� ����)
	out->psn_lim_ratio = Str2Dbl(data->psn_lim_ratio, sizeof(data->psn_lim_ratio), 4);	// �����ѵ�����, 9V9999 (��:15%�϶� �� 01500���� ����)
	out->stk_lstd = Str2Dbl(data->stk_lstd, sizeof(data->stk_lstd), 0);	// �����ֽļ�, ����:��
	out->ordbl_qty = Str2Dbl(data->ordbl_qty, sizeof(data->ordbl_qty), 0);	// �ֹ����ɼ���, ����:��
	out->lim_xhs_clsf = data->lim_xhs_clsf[0];	//�ѵ���������, 0:���� 1:�ѵ����� 2:�ѵ�����ű����� 3:�ѵ���������

	return 1;
}


// �ڽ��� �ܱ��� �ֹ����ɼ���
int ParseF2012(const double& timestamp, const char* in_buff, DF_KOSDAQ_FRGN_ORDL_QTY* out) {
	KOSDAQ_FRGN_ORDL_QTY* data = (KOSDAQ_FRGN_ORDL_QTY*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����, F2
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������, 01:�ֽ� 90:��Ÿ
	out->mkt_clsf = data->mkt_clsf[0];	//���屸��, 1:�������� 2:�ڽ��� 3:�������� 7:ä��
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// �����ڵ�, ǥ���ڵ�
	out->ordbl_qty = Str2Dbl(data->ordbl_qty, sizeof(data->ordbl_qty), 0);	// �ֹ����ɼ���, ����:��(����� ����)
	memcpy(out->proc_clsf, data->proc_clsf, sizeof(data->proc_clsf));	// ����������, 01:�ֹ����ɼ���(�ǽð�) 07:����ġ�ֹ����ɼ���(����)

	return 1;
}


// �ڽ��� �ܱ��� Ȯ��ġ������������
int ParseF4012(const double& timestamp, const char* in_buff, DF_KOSDAQ_FRGN_CFRM_DATA* out) {
	KOSDAQ_FRGN_CFRM_DATA* data = (KOSDAQ_FRGN_CFRM_DATA*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����, F4
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������, 01:�ֽ� 90:��Ÿ
	out->mkt_clsf = data->mkt_clsf[0];	//���屸��, 1:�������� 2:�ڽ��� 3:�������� 7:ä��
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// �����ڵ�, ǥ���ڵ�
	out->stk_lim_ratio = Str2Dbl(data->stk_lim_ratio, sizeof(data->stk_lim_ratio), 4);	// �����ѵ�����, 9V9999 (��:15%�϶� �� 01500���� ����)
	out->psn_lim_ratio = Str2Dbl(data->psn_lim_ratio, sizeof(data->psn_lim_ratio), 4);	// �����ѵ�����, 9V9999 (��:15%�϶� �� 01500���� ����)
	out->stk_lstd = Str2Dbl(data->stk_lstd, sizeof(data->stk_lstd), 0);	// �����ֽļ�, ����:��
	out->ordbl_qty = Str2Dbl(data->ordbl_qty, sizeof(data->ordbl_qty), 0);	// �ֹ����ɼ���, ����:��
	out->lim_xhs_clsf = data->lim_xhs_clsf[0];	//�ѵ���������, 0:���� 1:�ѵ��ʰ� 2:�߰� 3:����

	return 1;
}


// �ڳؽ� �ܱ��� ������������_Ȯ��ġ
int ParseF1018(const double& timestamp, const char* in_buff, DF_KONEX_FRGN_INV_INFO* out) {
	KONEX_FRGN_INV_INFO* data = (KONEX_FRGN_INV_INFO*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����, F1
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������, 01:�ֽ� 90:��Ÿ
	out->mkt_clsf = data->mkt_clsf[0];	//���屸��, 1:�������� 2:�ڽ��� 3:�������� 7:ä�� 8:�ڳؽ�
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// �����ڵ�, ǥ���ڵ�
	out->snr = Str2Int(data->snr, sizeof(data->snr));	// �Ϸù�ȣ, 1~99999999 �Ǽ�üũ��
	memcpy(out->trd_date, data->trd_date, sizeof(data->trd_date));	// �Ÿ�����, YYYYMMDD
	out->stk_lim_ratio = Str2Dbl(data->stk_lim_ratio, sizeof(data->stk_lim_ratio), 4);	// �����ѵ�����, 9V9999 (��:15%�϶� �� 01500���� ����)
	out->psn_lim_ratio = Str2Dbl(data->psn_lim_ratio, sizeof(data->psn_lim_ratio), 4);	// �����ѵ�����, 9V9999 (��:15%�϶� �� 01500���� ����)
	out->stk_lstd = Str2Dbl(data->stk_lstd, sizeof(data->stk_lstd), 0);	// �����ֽļ�, ����:��
	out->ordbl_qty = Str2Dbl(data->ordbl_qty, sizeof(data->ordbl_qty), 0);	// �ֹ����ɼ���, ����:��
	out->lim_xhs_clsf = data->lim_xhs_clsf[0];	//�ѵ���������, 0:���� 1:�ѵ����� 2:�ѵ�����ű����� 3:�ѵ���������

	return 1;
}


// �ڳؽ� �ܱ��� �ֹ����ɼ���
int ParseF2018(const double& timestamp, const char* in_buff, DF_KONEX_FRGN_ORDL_QTY* out) {
	KONEX_FRGN_ORDL_QTY* data = (KONEX_FRGN_ORDL_QTY*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����, F2
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������, 01:�ֽ� 90:��Ÿ
	out->mkt_clsf = data->mkt_clsf[0];	//���屸��, 1:�������� 2:�ڽ��� 3:�������� 7:ä�� 8:�ڳؽ�
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// �����ڵ�, ǥ���ڵ�
	out->ordbl_qty = Str2Dbl(data->ordbl_qty, sizeof(data->ordbl_qty), 0);	// �ֹ����ɼ���, ����:��(����� ����)
	memcpy(out->data_type, data->data_type, sizeof(data->data_type));	// ����������, 01:�ֹ����ɼ���(�ǽð�) 07:����ġ�ֹ����ɼ���(����)

	return 1;
}


// �ڳؽ� �ܱ��� �����ֹ�����_����
int ParseF3018(const double& timestamp, const char* in_buff, DF_KONEX_FRGN_RSVD_ORD_CNCL* out) {
	KONEX_FRGN_RSVD_ORD_CNCL* data = (KONEX_FRGN_RSVD_ORD_CNCL*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����, F3
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������, 01:�ֽ�
	out->mkt_clsf = data->mkt_clsf[0];	//���屸��, 1:�������� 2:�ڽ��� 3:�������� 8:�ڳؽ�
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// �����ڵ�, ǥ���ڵ�
	memcpy(out->data_type, data->data_type, sizeof(data->data_type));	// ����������, 01:�����ֹ����� 02:�����ֹ�����
	out->proc_clsf = data->proc_clsf[0];	//ó������, 1:���� 2:���
	memcpy(out->rsvd_ord_date, data->rsvd_ord_date, sizeof(data->rsvd_ord_date));	// �����ֹ�����, YYYYMMDD
	memcpy(out->rsvd_ord_st_time, data->rsvd_ord_st_time, sizeof(data->rsvd_ord_st_time));	// �����ֹ����۽ð�, HHMM
	memcpy(out->rsvd_ord_ed_time, data->rsvd_ord_ed_time, sizeof(data->rsvd_ord_ed_time));	// �����ֹ�����ð�, HHMM

	return 1;
}


// �ڳؽ� �ܱ��� Ȯ��ġ������������
int ParseF4018(const double& timestamp, const char* in_buff, DF_KONEX_FRGN_CFRM_DATA* out) {
	KONEX_FRGN_CFRM_DATA* data = (KONEX_FRGN_CFRM_DATA*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����, F4
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������, 01:�ֽ� 90:��Ÿ
	out->mkt_clsf = data->mkt_clsf[0];	//���屸��, 1:�������� 2:�ڽ��� 3:�������� 7:ä�� 8:�ڳؽ�
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// �����ڵ�, ǥ���ڵ�
	out->stk_lim_ratio = Str2Dbl(data->stk_lim_ratio, sizeof(data->stk_lim_ratio), 4);	// �����ѵ�����, 9V9999 (��:15%�϶� �� 01500���� ����)
	out->psn_lim_ratio = Str2Dbl(data->psn_lim_ratio, sizeof(data->psn_lim_ratio), 4);	// �����ѵ�����, 9V9999 (��:15%�϶� �� 01500���� ����)
	out->stk_lstd = Str2Dbl(data->stk_lstd, sizeof(data->stk_lstd), 0);	// �����ֽļ�, ����:��
	out->ordbl_qty = Str2Dbl(data->ordbl_qty, sizeof(data->ordbl_qty), 0);	// �ֹ����ɼ���, ����:��
	out->lim_xhs_clsf = data->lim_xhs_clsf[0];	//�ѵ���������, 0:���� 1:�ѵ��ʰ� 2:�߰� 3:����

	return 1;
}


// �ڳؽ� �ܱ��� �ѵ�������ܸŸ�
int ParseF5018(const double& timestamp, const char* in_buff, DF_KONEX_FRGN_LMT_XHS* out) {
	KONEX_FRGN_LMT_XHS* data = (KONEX_FRGN_LMT_XHS*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����, F5
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������, 01:�ֽ�
	out->mkt_clsf = data->mkt_clsf[0];	//���屸��, 1:�������� 2:�ڽ��� 3:�������� 8:�ڳؽ�
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// �����ڵ�, ǥ���ڵ�
	out->clsf = data->clsf[0];	//����, 1:�ܰ��Է� 2:�ܰ����
	out->qty = Str2Int(data->qty, sizeof(data->qty));	// ����, ����:��
	out->prc = Str2Int(data->prc, sizeof(data->prc));	// ����, ����:��
	memcpy(out->proc_time, data->proc_time, sizeof(data->proc_time));	// ó���ð�, HHMMSSMM

	return 1;
}


// �ڳؽ� �ܱ��� �Ÿ�_������Ȳ
int ParseF6018(const double& timestamp, const char* in_buff, DF_KONEX_FRGN_TRD_STAT* out) {
	KONEX_FRGN_TRD_STAT* data = (KONEX_FRGN_TRD_STAT*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����, F6
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������, 01:�ֽ�
	out->mkt_clsf = data->mkt_clsf[0];	//���屸��, 1:�������� 2:�ڽ��� 8:�ڳؽ�
	out->snr = Str2Int(data->snr, sizeof(data->snr));	// �Ϸù�ȣ, 1~99999999 �Ǽ�üũ��
	out->clsf = data->clsf[0];	//����, 2:�ŷ��ҸŸ���Ȳ 3:�ŷ��Ұ�����Ȳ \n9:�ڽ��ڸŸ���Ȳ 0:�ڽ��ڰ�����Ȳ\n5:�ڳؽ��Ÿ���Ȳ 6:�ڳؽ�������Ȳ
	out->tot_bid_qty = Str2Dbl(data->tot_bid_qty, sizeof(data->tot_bid_qty), 0);	// �Ѹż�����, ����:��
	out->tot_bid_val = Str2Dbl(data->tot_bid_val, sizeof(data->tot_bid_val), 0);	// �Ѹż��ݾ�, ����:��
	out->tot_ask_qty = Str2Dbl(data->tot_ask_qty, sizeof(data->tot_ask_qty), 0);	// �Ѹŵ�����, ����:��
	out->tot_ask_val = Str2Dbl(data->tot_ask_val, sizeof(data->tot_ask_val), 0);	// �Ѹŵ��ݾ�, ����:��
	out->net_bid_qty = Str2SignDouble(data->net_bid_qty_sign, sizeof(data->net_bid_qty_sign) + sizeof(data->net_bid_qty), 0);	// ���ż�����, ����:��
	out->net_val_qty = Str2SignDouble(data->net_bid_val_sign, sizeof(data->net_bid_val_sign) + sizeof(data->net_val_qty), 0);	// ���ż��ݾ�, ����:��

	return 1;
}


// ���� ������ �����ͷ�
int ParseP2011(const double& timestamp, const char* in_buff, DF_KOSPI_BYIND_DYR* out) {
	KOSPI_BYIND_DYR* data = (KOSPI_BYIND_DYR*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����, P2
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������, 01:�ֽ�
	out->mkt_clsf = data->mkt_clsf[0];	//���屸��, 1:�������� 2:�ڽ���
	memcpy(out->idx_ind_code, data->idx_ind_code, sizeof(data->idx_ind_code));	// ���������ڵ�, ���ڵ尪���� ����
	out->dyr = Str2Dbl(data->dyr, sizeof(data->dyr), 2);	// �����ͷ�, 99999v99

	return 1;
}


// ELW �����ġ
int ParseA1011(const double& timestamp, const char* in_buff, DF_ELW_STK_ARNG* out) {
	ELW_STK_ARNG* data = (ELW_STK_ARNG*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����, A1
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������, 01:�ֽ�
	out->mkt_clsf = data->mkt_clsf[0];	//���屸��, 1:��������
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// �����ڵ�, ǥ���ڵ�
	out->snr = Str2Int(data->snr, sizeof(data->snr));	// �Ϸù�ȣ, 1~99999999 �Ǽ�üũ��
	memcpy(out->elw_ptcp_kor_nm, data->elw_ptcp_kor_nm, sizeof(data->elw_ptcp_kor_nm));	// ELW������������� �ѱ۸�
	memcpy(out->elw_ptcp_eng_nm, data->elw_ptcp_eng_nm, sizeof(data->elw_ptcp_eng_nm));	// ELW������������� ������
	memcpy(out->elw_ptcp_nr, data->elw_ptcp_nr, sizeof(data->elw_ptcp_nr));	// ELW������������� ��ȣ, ELW����ȸ������ ��ȣ(�����, ������ ���о���)\n��) ��00001��
	memcpy(out->elw_comp_stk_mtk_id1, data->elw_comp_stk_mtk_id1, sizeof(data->elw_comp_stk_mtk_id1));	// ELW�����������ID1, ���������� �Ҽӵ� ����ID(��:����:STK,�ڽ���:KSQ)\n*�����ڻ��� ������ ��츸 �ش�
	memcpy(out->elw_comp_stk_mtk_id2, data->elw_comp_stk_mtk_id2, sizeof(data->elw_comp_stk_mtk_id2));	// ELW�����������ID2, ���������� �Ҽӵ� ����ID(��:����:STK,�ڽ���:KSQ)\n*�����ڻ��� ������ ��츸 �ش�
	memcpy(out->elw_comp_stk_mtk_id3, data->elw_comp_stk_mtk_id3, sizeof(data->elw_comp_stk_mtk_id3));	// ELW�����������ID3, ���������� �Ҽӵ� ����ID(��:����:STK,�ڽ���:KSQ)\n*�����ڻ��� ������ ��츸 �ش�
	memcpy(out->elw_comp_stk_mtk_id4, data->elw_comp_stk_mtk_id4, sizeof(data->elw_comp_stk_mtk_id4));	// ELW�����������ID4, ���������� �Ҽӵ� ����ID(��:����:STK,�ڽ���:KSQ)\n*�����ڻ��� ������ ��츸 �ش�
	memcpy(out->elw_comp_stk_mtk_id5, data->elw_comp_stk_mtk_id5, sizeof(data->elw_comp_stk_mtk_id5));	// ELW�����������ID5, ���������� �Ҽӵ� ����ID(��:����:STK,�ڽ���:KSQ)\n*�����ڻ��� ������ ��츸 �ش�
	memcpy(out->elw_base_ast1, data->elw_base_ast1, sizeof(data->elw_base_ast1));	// ELW�����ڻ�1, �����ڻ��� ������ ��� SPACE. ELW���������ڵ� ����
	memcpy(out->elw_base_ast2, data->elw_base_ast2, sizeof(data->elw_base_ast2));	// ELW�����ڻ�2, �����ڻ��� ������ ��� SPACE. ELW���������ڵ� ����
	memcpy(out->elw_base_ast3, data->elw_base_ast3, sizeof(data->elw_base_ast3));	// ELW�����ڻ�3, �����ڻ��� ������ ��� SPACE. ELW���������ڵ� ����
	memcpy(out->elw_base_ast4, data->elw_base_ast4, sizeof(data->elw_base_ast4));	// ELW�����ڻ�4, �����ڻ��� ������ ��� SPACE. ELW���������ڵ� ����
	memcpy(out->elw_base_ast5, data->elw_base_ast5, sizeof(data->elw_base_ast5));	// ELW�����ڻ�5, �����ڻ��� ������ ��� SPACE. ELW���������ڵ� ����
	out->elw_base_ast_rate1 = Str2Dbl(data->elw_base_ast_rate1, sizeof(data->elw_base_ast_rate1), 6);	// ELW�����ڻ걸����1, 9(6)V9(6)
	out->elw_base_ast_rate2 = Str2Dbl(data->elw_base_ast_rate2, sizeof(data->elw_base_ast_rate2), 6);	// ELW�����ڻ걸����2, 9(6)V9(6)
	out->elw_base_ast_rate3 = Str2Dbl(data->elw_base_ast_rate3, sizeof(data->elw_base_ast_rate3), 6);	// ELW�����ڻ걸����3, 9(6)V9(6)
	out->elw_base_ast_rate4 = Str2Dbl(data->elw_base_ast_rate4, sizeof(data->elw_base_ast_rate4), 6);	// ELW�����ڻ걸����4, 9(6)V9(6)
	out->elw_base_ast_rate5 = Str2Dbl(data->elw_base_ast_rate5, sizeof(data->elw_base_ast_rate5), 6);	// ELW�����ڻ걸����5, 9(6)V9(6)
	out->idx_mkt_clsf_code = data->idx_mkt_clsf_code[0];	//�����Ҽӽ��屸���ڵ�, 1:�������� 2:�ڽ��� 3:���� 4:GICS 8:MF(�Ű�) 9:�ؿ�\nS:S&P/KRX B:ä�� C:��ȭ M:��ǰ R:�ε��� 2009.07.27\n*�����ڻ��� ������ ��츸 �ش�\n*����Ī:ELW�����ڻ���屸���ڵ�
	memcpy(out->elw_idx_ind_code, data->elw_idx_ind_code, sizeof(data->elw_idx_ind_code));	// ELW���������ڵ�, ELW�����ڻ���屸���ڵ尡 ���������� ���� ����������\n���������ڵ�, �ڽ����� ���� �ڽ����� �����ڵ�,\n�ؿܽ����� ���� �ؿ������� ���� ������ �ڵ�����\n���ڵ尪���� - ������������ڵ�ǥ ����
	out->elw_rgt_type_code = data->elw_rgt_type_code[0];	//ELW�Ǹ������ڵ�, C:�� P:ǲ Z:��Ÿ
	out->elw_rgt_exc_type_code = data->elw_rgt_exc_type_code[0];	//ELW�Ǹ���������ڵ�, A:�̱��� E:������ Z:�ش����
	out->elw_fin_pymt_code = data->elw_fin_pymt_code[0];	//ELW������������ڵ�, A:����+�ǹ��μ������� C:���ݰ��� D:�ǹ��μ�������
	memcpy(out->elw_fin_trd_date, data->elw_fin_trd_date, sizeof(data->elw_fin_trd_date));	// ELW�����ŷ�����, YYYYMMDD
	memcpy(out->elw_pymt_date, data->elw_pymt_date, sizeof(data->elw_pymt_date));	// ELW��������, YYYYMMDD
	out->elw_base_ast_prc = Str2Dbl(data->elw_base_ast_prc, sizeof(data->elw_base_ast_prc), 3);	// ELW�����ڻ���ʰ���, 9(9)V9(3) �ذ��߰��̵� ����
	memcpy(out->elw_mtr_rgt_exc_cntt, data->elw_mtr_rgt_exc_cntt, sizeof(data->elw_mtr_rgt_exc_cntt));	// ELW����Ǹ���系��, ELW�Ǹ���系��->ELW����Ǹ���系�� 2010.08.30
	out->elw_cnvr = Str2Dbl(data->elw_cnvr, sizeof(data->elw_cnvr), 6);	// ELW��ȯ����, 9(6)V9(6)
	out->elw_rise_ptcp_rate = Str2Dbl(data->elw_rise_ptcp_rate, sizeof(data->elw_rise_ptcp_rate), 2);	// ELW���ݻ��������, 9(6)V9(2)
	out->elw_min_pymt_rate = Str2Dbl(data->elw_min_pymt_rate, sizeof(data->elw_min_pymt_rate), 2);	// ELW�ּ����޺���, 9(6)V9(2) ELW������->ELW�ּ����޺��� 2010.08.30
	out->elw_cfrm_pymt_val = Str2Dbl(data->elw_cfrm_pymt_val, sizeof(data->elw_cfrm_pymt_val), 3);	// ELWȮ�����޾�, 9(18)V9(3)
	memcpy(out->elw_pymt_prx_nm, data->elw_pymt_prx_nm, sizeof(data->elw_pymt_prx_nm));	// ELW���޴븮�θ�
	memcpy(out->elw_mtr_assm_type, data->elw_mtr_assm_type, sizeof(data->elw_mtr_assm_type));	// ELW�����򰡰��ݹ��
	out->elw_rgt_type = data->elw_rgt_type[0];	//ELW�Ǹ�����, ELW�̻��ɼǱ����ڵ� -> ELW�Ǹ�����\n0:ǥ�ؿɼ� 1:�����пɼ� 2:��������ɼ�(2010.08.30)
	out->elw_lp_hld_qty = Str2Dbl(data->elw_lp_hld_qty, sizeof(data->elw_lp_hld_qty), 0);	// ELW LP��������, 15 -> 12 2014.03.03

	return 1;
}


// ��������ELW_�����ġ
int ParseM6011(const double& timestamp, const char* in_buff, DF_ELY_CLS_ELW_STK_ARNG* out) {
	ELY_CLS_ELW_STK_ARNG* data = (ELY_CLS_ELW_STK_ARNG*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����, M6
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������, 01:�ֽ�
	out->mkt_clsf = data->mkt_clsf[0];	//���屸��, 1:��������
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// �����ڵ�, ǥ���ڵ�
	out->snr = Str2Int(data->snr, sizeof(data->snr));	// �Ϸù�ȣ, 1~99999999 �Ǽ�üũ��
	out->elw_ely_cls_base_prc = Str2Dbl(data->elw_ely_cls_base_prc, sizeof(data->elw_ely_cls_base_prc), 3);	// ELW��������߻� ���ذ���, 9(9)V9(3), �����������Ʈ�� �������� �̺�Ʈ �߻��� \n������ �Ǵ� ����(2010.08.30)
	memcpy(out->elw_ely_cls_rgt_exe_cntt, data->elw_ely_cls_rgt_exe_cntt, sizeof(data->elw_ely_cls_rgt_exe_cntt));	// ELW��������Ǹ���� ����, ELW��������Ǹ���系��(2010.08.30)
	memcpy(out->elw_ely_cls_assm_type, data->elw_ely_cls_assm_type, sizeof(data->elw_ely_cls_assm_type));	// ELW���������� ���ݹ��, ��������� �ش� ������ �򰡰����� �����ϴ� ����� \n��� (2010.08.30)

	return 1;
}


// ��������ELW �򰡱Ⱓ �� �����ڻ������
int ParseM5011(const double& timestamp, const char* in_buff, DF_ELY_CLS_ELW_ASSET_HLP* out) {
	ELY_CLS_ELW_ASSET_HLP* data = (ELY_CLS_ELW_ASSET_HLP*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����, M5
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������, 01:�ֽ�
	out->mkt_clsf = data->mkt_clsf[0];	//���屸��, 1:��������
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// �����ڵ�, Knockout �߻��� ELW�� �����ڵ�
	out->snr = Str2Int(data->snr, sizeof(data->snr));	// �Ϸù�ȣ, 1~99999999 �Ǽ�üũ��
	memcpy(out->trsm_date, data->trsm_date, sizeof(data->trsm_date));	// ��������
	memcpy(out->base_ast_trd_date, data->base_ast_trd_date, sizeof(data->base_ast_trd_date));	// �����ڻ�Ÿ�����
	memcpy(out->ko_trgg_date, data->ko_trgg_date, sizeof(data->ko_trgg_date));	// KO�߻�����, Knockout �߻�����
	out->noon_clsf_code = data->noon_clsf_code[0];	//�������ı����ڵ�, Knockout �����߻��� ��� �� ���߰��̵� ����\n A : KO�������� 12��\n P: 12�ú��� �����帶��\nKnockout ���� �߻��� ���\n P: KO�������� �����帶��\nKnockout �߻� �� �� �������� ��� \n A: �尳�ú��� 12��\n P: 12�ú��� ������ ����
	memcpy(out->comp_stk_code, data->comp_stk_code, sizeof(data->comp_stk_code));	// ���������ڵ�, ELW�� �����ϴ� �����ڻ��� �����ڵ�(ISIN�����ڵ�)
	out->elw_idx_mkt_clsf_code = data->elw_idx_mkt_clsf_code[0];	//ELW�����Ҽӽ��屸���ڵ�, 1:��������, 2:�ڽ���
	memcpy(out->idx_ind_code, data->idx_ind_code, sizeof(data->idx_ind_code));	// ���������ڵ�, ELW�����ڻ���屸���ڵ尡 ���������� ���� ����������\n���������ڵ�, �ڽ����� ���� �ڽ����� �����ڵ�,\n�ؿܽ����� ���� �ؿ������� ���� ������ �ڵ�����\n���ڵ尪���� - ������������ڵ�ǥ ����
	memcpy(out->high, data->high, sizeof(data->high));	// ��, 9(9)V9(2) ����ð����� �����ڻ��� ��\nKO�߻��ð��� ������ �����̸� "00000000000"
	memcpy(out->low, data->low, sizeof(data->low));	// ����, 9(9)V9(2) ����ð����� �����ڻ��� ����\nKO�߻��ð��� ������ �����̸� "00000000000"

	return 1;
}


// ELW_�ü�RECOVERY
int ParseB2021(const double& timestamp, const char* in_buff, DF_ELW_MKT_PRC_RCVR* out) {
	ELW_MKT_PRC_RCVR* data = (ELW_MKT_PRC_RCVR*)in_buff;

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
	out->high = Str2Int(data->high, sizeof(data->high));	// ��, ������ ��
	out->low = Str2Int(data->low, sizeof(data->low));	// ����, ������ ����
	out->ask_prc = Str2Int(data->ask_prc, sizeof(data->ask_prc));	// �ŵ�ȣ��, B1�� 0�� SET
	out->bid_prc = Str2Int(data->bid_prc, sizeof(data->bid_prc));	// �ż�ȣ��, B1�� 0�� SET
	out->cum_ccls_qty = Str2Dbl(data->cum_ccls_qty, sizeof(data->cum_ccls_qty), 0);	// ����ü�����, ����:�� �ؽð��ܴ��ϰ�, BUY-IN�� ������ ��� ü����� �ջ�
	out->cum_trd_val = Str2Dbl(data->cum_trd_val, sizeof(data->cum_trd_val), 0);	// �����ŷ����, ����:�� �ؽð��ܴ��ϰ�, BUY-IN�� ������ ��� �ŷ���� �ջ�
	out->trend_flg = data->trend_flg[0];	//�Ǽ�/�⼼ ����, 0:�ʱⰪ 1:�Ǽ� 2:�⼼ 3:�ŷ��� 4:�ð����ذ������� �⼼
	memcpy(out->brd_evt_id, data->brd_evt_id, sizeof(data->brd_evt_id));	// �����̺�ƮID, B1/B2 ������ �����̺�ƮID ������(���� ���°��� ���۵� �� ����). ����, �ش� �׸� '000' ���� ����. 2014.03.24)
	memcpy(out->brd_id, data->brd_id, sizeof(data->brd_id));	// ����ID, �� �ڵ尪���� ����
	out->trsp_flg = data->trsp_flg[0];	//�ŷ���������, Y, N
	out->bopen_ofhr_ccls_qty = Str2Dbl(data->bopen_ofhr_ccls_qty, sizeof(data->bopen_ofhr_ccls_qty), 0);	// �尳�����ð������� ü�����, �뷮, �ٽ����� ����, ����:��
	out->bopen_ofhr_trd_val = Str2Dbl(data->bopen_ofhr_trd_val, sizeof(data->bopen_ofhr_trd_val), 0);	// �尳�����ð������� �ŷ����, �뷮, �ٽ����� ����, ����:��
	out->opr_time_ccls_qty = Str2Dbl(data->opr_time_ccls_qty, sizeof(data->opr_time_ccls_qty), 0);	// ������ü�����, �뷮, �ٽ����� ����, ����:��
	out->opr_time_trd_val = Str2Dbl(data->opr_time_trd_val, sizeof(data->opr_time_trd_val), 0);	// ������ŷ����, �뷮, �ٽ����� ����, ����:��
	out->ofhr_cls_ccls_qty = Str2Dbl(data->ofhr_cls_ccls_qty, sizeof(data->ofhr_cls_ccls_qty), 0);	// �������Ľð������� ü�����, �뷮, �ٽ����� ����, ����:��
	out->ofhr_cls_trd_val = Str2Dbl(data->ofhr_cls_trd_val, sizeof(data->ofhr_cls_trd_val), 0);	// �������Ľð������� �ŷ����, �뷮, �ٽ����� ����, ����:��
	out->elw_ely_cls_flg = data->elw_ely_cls_flg[0];	//ELW�������Ῡ��, Y,N ��������ELW �� ������ Default 'N' SET
	out->elw_ely_cls_time = Str2Int(data->elw_ely_cls_time, sizeof(data->elw_ely_cls_time));	// ELW��������ð�, HHMMSS, ELW�������Ῡ�ΰ� 'Y'�� ��츸 ����
	out->cmpt_msv_dir_clsf = Str2Int(data->cmpt_msv_dir_clsf, sizeof(data->cmpt_msv_dir_clsf));	// ����뷮 ���ⱸ��, 0:�ش����, 1:�ŵ�, 2:�ż�
	out->gen_bin_ccls_qty = Str2Dbl(data->gen_bin_ccls_qty, sizeof(data->gen_bin_ccls_qty), 0);	// �Ϲ� Buy-in ü�����, ����:��
	out->gen_bin_ccls_trd_val = Str2Dbl(data->gen_bin_ccls_trd_val, sizeof(data->gen_bin_ccls_trd_val), 0);	// �Ϲ� Buy-in �ŷ����, ����:��
	out->day_bin_ccls_qty = Str2Dbl(data->day_bin_ccls_qty, sizeof(data->day_bin_ccls_qty), 0);	// ���� Buy-in ü�����, ����:��
	out->day_bin_ccls_trd_val = Str2Dbl(data->day_bin_ccls_trd_val, sizeof(data->day_bin_ccls_trd_val), 0);	// ���� Buy-in �ŷ����, ����:��

	return 1;
}


// ELW ������ǥ
int ParseC6021(const double& timestamp, const char* in_buff, DF_ELW_INV_IDX* out) {
	ELW_INV_IDX* data = (ELW_INV_IDX*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����, C6
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������, 02:ELW
	out->mkt_clsf = data->mkt_clsf[0];	//���屸��, 1:��������
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// �����ڵ�, ǥ���ڵ�
	out->snr = Str2Int(data->snr, sizeof(data->snr));	// �Ϸù�ȣ, 1~99999999 �����Ϸù�ȣ 2014.03.03
	memcpy(out->buy_time, data->buy_time, sizeof(data->buy_time));	// �� �ð�, ����:HHMMSS(�ð�:��:��) 090000 ~ ������:JUNJJJ
	out->parity = Str2Dbl(data->parity, sizeof(data->parity), 2);	// �и�Ƽ, 9(6)V9(2)
	out->gear_rate = Str2Dbl(data->gear_rate, sizeof(data->gear_rate), 2);	// ������, 9(6)V9(2)
	out->brk_evn_rate = Str2SignDouble(data->brk_evn_rate_sign, sizeof(data->brk_evn_rate_sign) + sizeof(data->brk_evn_rate), 2);	// ���ͺб���, 9(5)V9(2)
	out->cpt_sprt = Str2SignDouble(data->cpt_sprt_sign, sizeof(data->cpt_sprt_sign) + sizeof(data->cpt_sprt), 2);	// �ں�������, 9(5)V9(2) ������ ����� �ѹ��� �����. �� �ܴ� "0"\n����Ŀ��� �� < 0 �̸� "0"���� SET
	out->bsk_prc = Str2Dbl(data->bsk_prc, sizeof(data->bsk_prc), 2);	// �ٽ����ְ�, 9(9)V9(2)

	return 1;
}


// ELW LPȣ�� ���纯����
int ParseN3021(const double& timestamp, const char* in_buff, DF_ELW_LP_ASK_VOL* out) {
	int i=0;
	ELW_LP_ASK_VOL* data = (ELW_LP_ASK_VOL*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����, N3
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������, 02:ELW
	out->mkt_clsf = data->mkt_clsf[0];	//���屸��, 1:��������
	out->calc_time = Str2Int(data->calc_time, sizeof(data->calc_time));	// ����ð�, ����:HHMMSS(�ð�:��:��) 090000 ~ ������:JUNJJJ

	for ( i=0 ; i<50 ; i++ ) {
		memcpy(&out->elw_iv_infos[i].isin_code, &data->elw_iv_infos[i].isin_code, sizeof(data->elw_iv_infos[i].isin_code));	// �����ڵ�, ǥ���ڵ� 12 ����Ʈ
		out->elw_iv_infos[i].itnl_vol = Str2Dbl(data->elw_iv_infos[i].itnl_vol, sizeof(data->elw_iv_infos[i].itnl_vol), 2);	// ���纯����, 9(3)V9(2). 5����Ʈ
	}

	return 1;
}


// ELW_�ü�����
int ParseB1021(const double& timestamp, const char* in_buff, DF_ELW_MKT_PRC_CLS* out) {
	ELW_MKT_PRC_CLS* data = (ELW_MKT_PRC_CLS*)in_buff;

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
	out->high = Str2Int(data->high, sizeof(data->high));	// ��, ������ ��
	out->low = Str2Int(data->low, sizeof(data->low));	// ����, ������ ����
	out->ask_prc = Str2Int(data->ask_prc, sizeof(data->ask_prc));	// �ŵ�ȣ��, B1�� 0�� SET
	out->bid_prc = Str2Int(data->bid_prc, sizeof(data->bid_prc));	// �ż�ȣ��, B1�� 0�� SET
	out->cum_ccls_qty = Str2Dbl(data->cum_ccls_qty, sizeof(data->cum_ccls_qty), 0);	// ����ü�����, ����:�� �ؽð��ܴ��ϰ�, BUY-IN�� ������ ��� ü����� �ջ�
	out->cum_trd_val = Str2Dbl(data->cum_trd_val, sizeof(data->cum_trd_val), 0);	// �����ŷ����, ����:�� �ؽð��ܴ��ϰ�, BUY-IN�� ������ ��� �ŷ���� �ջ�
	out->trend_flg = data->trend_flg[0];	//�Ǽ�/�⼼ ����, 0:�ʱⰪ 1:�Ǽ� 2:�⼼ 3:�ŷ��� 4:�ð����ذ������� �⼼
	memcpy(out->brd_evt_id, data->brd_evt_id, sizeof(data->brd_evt_id));	// �����̺�ƮID, B1/B2 ������ �����̺�ƮID ������(���� ���°��� ���۵� �� ����). ����, �ش� �׸� '000' ���� ����. 2014.03.24)
	memcpy(out->brd_id, data->brd_id, sizeof(data->brd_id));	// ����ID, �� �ڵ尪���� ����
	out->trsp_flg = data->trsp_flg[0];	//�ŷ���������, Y, N
	out->bopen_ofhr_ccls_qty = Str2Dbl(data->bopen_ofhr_ccls_qty, sizeof(data->bopen_ofhr_ccls_qty), 0);	// �尳�����ð������� ü�����, �뷮, �ٽ����� ����, ����:��
	out->bopen_ofhr_trd_val = Str2Dbl(data->bopen_ofhr_trd_val, sizeof(data->bopen_ofhr_trd_val), 0);	// �尳�����ð������� �ŷ����, �뷮, �ٽ����� ����, ����:��
	out->opr_time_ccls_qty = Str2Dbl(data->opr_time_ccls_qty, sizeof(data->opr_time_ccls_qty), 0);	// ������ü�����, �뷮, �ٽ����� ����, ����:��
	out->opr_time_trd_val = Str2Dbl(data->opr_time_trd_val, sizeof(data->opr_time_trd_val), 0);	// ������ŷ����, �뷮, �ٽ����� ����, ����:��
	out->ofhr_cls_ccls_qty = Str2Dbl(data->ofhr_cls_ccls_qty, sizeof(data->ofhr_cls_ccls_qty), 0);	// �������Ľð������� ü�����, �뷮, �ٽ����� ����, ����:��
	out->ofhr_cls_trd_val = Str2Dbl(data->ofhr_cls_trd_val, sizeof(data->ofhr_cls_trd_val), 0);	// �������Ľð������� �ŷ����, �뷮, �ٽ����� ����, ����:��
	out->elw_ely_cls_flg = data->elw_ely_cls_flg[0];	//ELW�������Ῡ��, Y,N ��������ELW �� ������ Default 'N' SET
	out->elw_ely_cls_time = Str2Int(data->elw_ely_cls_time, sizeof(data->elw_ely_cls_time));	// ELW��������ð�, HHMMSS, ELW�������Ῡ�ΰ� 'Y'�� ��츸 ����
	out->cmpt_msv_dir_clsf = Str2Int(data->cmpt_msv_dir_clsf, sizeof(data->cmpt_msv_dir_clsf));	// ����뷮 ���ⱸ��, 0:�ش����, 1:�ŵ�, 2:�ż�
	out->gen_bin_ccls_qty = Str2Dbl(data->gen_bin_ccls_qty, sizeof(data->gen_bin_ccls_qty), 0);	// �Ϲ� Buy-in ü�����, ����:��
	out->gen_bin_ccls_trd_val = Str2Dbl(data->gen_bin_ccls_trd_val, sizeof(data->gen_bin_ccls_trd_val), 0);	// �Ϲ� Buy-in �ŷ����, ����:��
	out->day_bin_ccls_qty = Str2Dbl(data->day_bin_ccls_qty, sizeof(data->day_bin_ccls_qty), 0);	// ���� Buy-in ü�����, ����:��
	out->day_bin_ccls_trd_val = Str2Dbl(data->day_bin_ccls_trd_val, sizeof(data->day_bin_ccls_trd_val), 0);	// ���� Buy-in �ŷ����, ����:��

	return 1;
}


// ELW_�����ں�
int ParseC0021(const double& timestamp, const char* in_buff, DF_ELW_BYINV* out) {
	ELW_BYINV* data = (ELW_BYINV*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����, C0
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������, 01:�ֽ�, 02:ELW, 03:ETF
	out->mkt_clsf = data->mkt_clsf[0];	//���屸��, 1:�������� 2:�ڽ���
	memcpy(out->cmpt_time, data->cmpt_time, sizeof(data->cmpt_time));	// ����ð�, 90�� �ֱ�
	memcpy(out->inv_code, data->inv_code, sizeof(data->inv_code));	// �������ڵ�, ���ڵ尪���� ����\n*�ڵ�'7000'�� ����, ������� �׸� 0���� ���� (20181210)
	memcpy(out->ind_code, data->ind_code, sizeof(data->ind_code));	// �����ڵ�, 0
	out->ask_ccls_qty = Str2Dbl(data->ask_ccls_qty, sizeof(data->ask_ccls_qty), 0);	// �ŵ�ü�����, ����:��
	out->ask_trd_val = Str2Dbl(data->ask_trd_val, sizeof(data->ask_trd_val), 0);	// �ŵ��ŷ����, ����:��
	out->bid_ccls_qty = Str2Dbl(data->bid_ccls_qty, sizeof(data->bid_ccls_qty), 0);	// �ż�ü�����, ����:��
	out->bid_trd_val = Str2Dbl(data->bid_trd_val, sizeof(data->bid_trd_val), 0);	// �ż��ŷ����, ����:��

	return 1;
}


// ELW_ȣ���ܷ�_LPȣ��_����
int ParseB7021(const double& timestamp, const char* in_buff, DF_ELW_ASK_RSD_WLP* out) {
	int i=0;
	ELW_ASK_RSD_WLP* data = (ELW_ASK_RSD_WLP*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����, B7
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������, 01:������������ 02:ELW
	out->mkt_clsf = data->mkt_clsf[0];	//���屸��, 1:��������
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// �����ڵ�, ǥ���ڵ�
	out->stk_snr = Str2Int(data->stk_snr, sizeof(data->stk_snr));	// �����Ϸù�ȣ, �����ġ(A0)�� �����Ϸù�ȣ
	out->cum_ccls_qty = Str2Dbl(data->cum_ccls_qty, sizeof(data->cum_ccls_qty), 0);	// ����ü�����
	
	for ( i=0 ; i<10 ; i++ ) {
		out->lob_infos[i].ask_prc = Str2Int(data->lob_infos[i].ask_prc, sizeof(data->lob_infos[i].ask_prc));	// �ŵ�ȣ��
		out->lob_infos[i].bid_prc = Str2Int(data->lob_infos[i].bid_prc, sizeof(data->lob_infos[i].bid_prc));	// �ż�ȣ��
		out->lob_infos[i].ask_vol_rsd = Str2Dbl(data->lob_infos[i].ask_vol_rsd, sizeof(data->lob_infos[i].ask_vol_rsd), 0);	// �ŵ�ȣ�� �ܷ�
		out->lob_infos[i].bid_vol_rsd = Str2Dbl(data->lob_infos[i].bid_vol_rsd, sizeof(data->lob_infos[i].bid_vol_rsd), 0);	// �ż�ȣ�� �ܷ�
		out->lob_infos[i].lp_ask_vol_rsd = Str2Dbl(data->lob_infos[i].lp_ask_vol_rsd, sizeof(data->lob_infos[i].lp_ask_vol_rsd), 0);	// LP �ŵ�ȣ�� �ܷ�
		out->lob_infos[i].lp_bid_vol_rsd = Str2Dbl(data->lob_infos[i].lp_bid_vol_rsd, sizeof(data->lob_infos[i].lp_bid_vol_rsd), 0);	// LP �ż�ȣ�� �ܷ�
	}   // ȣ��

	out->ask_10_tot_rsd = Str2Dbl(data->ask_10_tot_rsd, sizeof(data->ask_10_tot_rsd), 0);	// 10�ܰ�ȣ���ŵ����ܷ�
	out->bid_10_tot_rsd = Str2Dbl(data->bid_10_tot_rsd, sizeof(data->bid_10_tot_rsd), 0);	// 10�ܰ�ȣ���ż����ܷ�
	out->ofhr_ask_tot_rsd = Str2Dbl(data->ofhr_ask_tot_rsd, sizeof(data->ofhr_ask_tot_rsd), 0);	// �������Ľð��� �ŵ���ȣ���ܷ�, ����ID�� "G3"�� ��� ������ \n ��ELW�� �ð��ܰŷ� ����
	out->ofhr_bid_tot_rsd = Str2Dbl(data->ofhr_bid_tot_rsd, sizeof(data->ofhr_bid_tot_rsd), 0);	// �������Ľð��� �ż���ȣ���ܷ�, ����ID�� "G3"�� ��� ������ \n ��ELW�� �ð��ܰŷ� ����
	memcpy(out->sess_id, data->sess_id, sizeof(data->sess_id));	// ����ID, �� �ڵ尪���� ����
	memcpy(out->brd_id, data->brd_id, sizeof(data->brd_id));	// ����ID, �� �ڵ尪���� ����
	out->exp_ccls_prc = Str2Int(data->exp_ccls_prc, sizeof(data->exp_ccls_prc));	// ����ü�ᰡ��
	out->exp_ccls_qty = Str2Dbl(data->exp_ccls_qty, sizeof(data->exp_ccls_qty), 0);	// ����ü�����
	out->cmpt_msv_dir_clsf = Str2Int(data->cmpt_msv_dir_clsf, sizeof(data->cmpt_msv_dir_clsf));	// ����뷮 ���ⱸ��, 0:�ش����, 1:�ŵ�, 2:�ż�

	return 1;
}


// ETF�繫��Ź��ġ
int ParseN8011(const double& timestamp, const char* in_buff, DF_ETF_TRA_INFO* out) {
	ETF_TRA_INFO* data = (ETF_TRA_INFO*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����, N8
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������, 01:�ֽ�
	out->mkt_clsf = data->mkt_clsf[0];	//���屸��, 1:��������
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// �����ڵ�, ǥ���ڵ�
	out->snr = Str2Int(data->snr, sizeof(data->snr));	// �Ϸù�ȣ, 1~99999999 �Ǽ�üũ��
	out->etf_nr_shr_rtt = Str2Dbl(data->etf_nr_shr_rtt, sizeof(data->etf_nr_shr_rtt), 0);	// ETF�����ֽļ�
	out->etf_nav_rtt = Str2Dbl(data->etf_nav_rtt, sizeof(data->etf_nav_rtt), 0);	// ETF������ڻ��Ѿ�
	out->etf_nav_tot_val = Str2Dbl(data->etf_nav_tot_val, sizeof(data->etf_nav_tot_val), 0);	// ETF���ڻ��Ѿ�, ����:��
	out->etf_fin_nav_val = Str2Dbl(data->etf_fin_nav_val, sizeof(data->etf_fin_nav_val), 2);	// ETF�������ڻ갡ġ, 9(7)V9(2) �������������� ����NAV
	out->etf_fx_nav_rtt = Str2Dbl(data->etf_fx_nav_rtt, sizeof(data->etf_fx_nav_rtt), 0);	// ETF��ȭ������ڻ��Ѿ�
	out->etf_fx_nav_tot_val = Str2Dbl(data->etf_fx_nav_tot_val, sizeof(data->etf_fx_nav_tot_val), 0);	// ETF��ȭ���ڻ��Ѿ�
	out->etf_fx_fin_nav_val = Str2Dbl(data->etf_fx_fin_nav_val, sizeof(data->etf_fx_fin_nav_val), 2);	// ETF��ȭ�������ڻ갡ġ, 9(7)V9(2)
	out->etf_cu_qty = Str2Int(data->etf_cu_qty, sizeof(data->etf_cu_qty));	// ETF CU����, ����:����
	out->prev_base_prc = Str2Dbl(data->prev_base_prc, sizeof(data->prev_base_prc), 2);	// ���ϰ�ǥ���ذ���, 9999999V99
	out->prev_bdiv_base_prc = Str2Dbl(data->prev_bdiv_base_prc, sizeof(data->prev_bdiv_base_prc), 2);	// ���Ϲ������ǥ���ذ���, 9999999V99
	out->prev_cash_div_val = Str2Dbl(data->prev_cash_div_val, sizeof(data->prev_cash_div_val), 2);	// �������ݹ��ݾ�, 9999999999V99
	out->pprev_base_prc = Str2Dbl(data->pprev_base_prc, sizeof(data->pprev_base_prc), 2);	// �����ϰ�ǥ���ذ���, 9999999V99
	out->frgn_stk_prev_base_prc = Str2Dbl(data->frgn_stk_prev_base_prc, sizeof(data->frgn_stk_prev_base_prc), 2);	// �ؿ��ֽ����Ϻ������ǥ���ذ�, 9999999V99 2016.02.29 �ű�
	out->frgn_stk_prev_bdiv_base_prc = Str2Dbl(data->frgn_stk_prev_bdiv_base_prc, sizeof(data->frgn_stk_prev_bdiv_base_prc), 2);	// �ؿ��ֽ����Ϻ�����������ǥ���ذ�, 9999999V99 2016.02.29 �ű�
	out->frgn_stk_pprev_bdiv_base_prc = Str2Dbl(data->frgn_stk_pprev_bdiv_base_prc, sizeof(data->frgn_stk_pprev_bdiv_base_prc), 2);	// �ؿ��ֽĺ���������ϰ�ǥ���ذ�, 9999999V99 2016.02.29 �ű�

	return 1;
}


// ETF PDF
int ParseF8011(const double& timestamp, const char* in_buff, DF_ETF_PDF* out) {
	ETF_PDF* data = (ETF_PDF*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����, F8
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������, 01:�ֽ�
	out->mkt_clsf = data->mkt_clsf[0];	//���屸��, 1:��������
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// ETF�ڵ�
	out->data_snr = Str2Int(data->data_snr, sizeof(data->data_snr));	// ������ �Ϸù�ȣ, �����Ϸù�ȣ
	memcpy(out->date, data->date, sizeof(data->date));	// ����, YYYYMMDD(��������)
	out->trb_nr = Str2Int(data->trb_nr, sizeof(data->trb_nr));	// �繫��Źȸ���ȣ, '903'�ѱ���Ź������,'049'�̷������ݵ弭��
	out->comp_stk_nr = Str2Int(data->comp_stk_nr, sizeof(data->comp_stk_nr));	// ���������, ����:����(������ ����)
	memcpy(out->comp_stk_code, data->comp_stk_code, sizeof(data->comp_stk_code));	// ���������ڵ�, �ذ��߰��̵� ����(CP �߰�) 2015.03.03
	out->one_cu_unit_scrt_nr = Str2Dbl(data->one_cu_unit_scrt_nr, sizeof(data->one_cu_unit_scrt_nr), 2);	// 1CU�������Ǽ�/����/��ȭ����, �ذ��߰��̵� ����(�ܱ�ȯ������ �߰�) 2014.06.16 \nǥ������:9999999999999999v99
	out->comp_stk_mkt_clsf = Str2Int(data->comp_stk_mkt_clsf, sizeof(data->comp_stk_mkt_clsf));	// ����������屸��, 0:��������(����,KSP200T00001,FKSP200T0001����)\n1:�ڽ��� 2:��Ÿ 3:ä�� 4:���� �� �ɼ� 2018.02.05
	memcpy(out->comp_stk_nm, data->comp_stk_nm, sizeof(data->comp_stk_nm));	// ���������, �ؿ������� ��� �����, �� �ܴ� '0' �Ǵ� SPACE
	out->par_val = Str2Dbl(data->par_val, sizeof(data->par_val), 0);	// �׸�ݾ�/�������ݾ�, �ذ��߰��̵� ����(�ܱ�ȯ������ �߰�) 2014.06.16
	memcpy(out->profit_allc_base_date, data->profit_allc_base_date, sizeof(data->profit_allc_base_date));	// ���ͺй������, �ذ��߰��̵� ���� 2009.07.27
	out->assm_val = Str2Dbl(data->assm_val, sizeof(data->assm_val), 0);	// �򰡱ݾ�, PDF�� ���� ���� ���� ����data �ű� 2011.08.29

	return 1;
}


// ETF�������
int ParseM8011(const double& timestamp, const char* in_buff, DF_ETF_OPR_INFO* out) {
	ETF_OPR_INFO* data = (ETF_OPR_INFO*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����, M8
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������, 01:�ֽ�
	out->mkt_clsf = data->mkt_clsf[0];	//���屸��, 1:��������
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// ETF �ڵ�, ǥ���ڵ�
	out->snr = Str2Int(data->snr, sizeof(data->snr));	// �Ϸù�ȣ, 00000001~99999999 �Ǽ�üũ��
	out->trb_nr = Str2Int(data->trb_nr, sizeof(data->trb_nr));	// �繫��Ź ȸ���ȣ, '903'�ѱ���Ź������,'049'�̷������ݵ弭��
	out->mngt_code = Str2Int(data->mngt_code, sizeof(data->mngt_code));	// �����ڵ�
	memcpy(out->mngt_kor_abrv, data->mngt_kor_abrv, sizeof(data->mngt_kor_abrv));	// ���� �ѱ۾��
	memcpy(out->mngt_eng_abrv, data->mngt_eng_abrv, sizeof(data->mngt_eng_abrv));	// ���� �������

	return 1;
}


// ETF NAV
int ParseF7011(const double& timestamp, const char* in_buff, DF_ETF_NAV* out) {
	ETF_NAV* data = (ETF_NAV*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����, F7
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������, 01:�ֽ�
	out->mkt_clsf = data->mkt_clsf[0];	//���屸��, 1:�������� 2:�ڽ���
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// ETF �����ڵ�, ETF �����ڵ�
	memcpy(out->time, data->time, sizeof(data->time));	// �ð�, HHMMSS:���� JSAM00:������
	out->prev_nav = Str2Dbl(data->prev_nav, sizeof(data->prev_nav), 2);	// ���� NAV, 9(7)V9(2)
	out->opr_time_fin_nav = Str2Dbl(data->opr_time_fin_nav, sizeof(data->opr_time_fin_nav), 2);	// ����/���� NAV, 9(7)V9(2)

	return 1;
}


// ETF ����NAV
int ParseI3011(const double& timestamp, const char* in_buff, DF_ETF_EXP_NAV* out) {
	ETF_EXP_NAV* data = (ETF_EXP_NAV*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����, I3
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������, 01:�ֽ�
	out->mkt_clsf = data->mkt_clsf[0];	//���屸��, 1:�������� 2:�ڽ���
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// ETF �����ڵ�, ETF �����ڵ�
	memcpy(out->time, data->time, sizeof(data->time));	// �ð�, HHMMSS:08:30~09:00(PREJJJ) 14:50~15:00(JUNJJJ)
	out->prev_nav = Str2Dbl(data->prev_nav, sizeof(data->prev_nav), 2);	// ���� NAV, 9999999V99
	out->opr_time_fin_nav = Str2Dbl(data->opr_time_fin_nav, sizeof(data->opr_time_fin_nav), 2);	// ����/���� NAV, 9999999V99

	return 1;
}


// ETF ����������
int ParseP6011(const double& timestamp, const char* in_buff, DF_ETF_TER* out) {
	ETF_TER* data = (ETF_TER*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����, P6
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������, 01:�ֽ�
	out->mkt_clsf = data->mkt_clsf[0];	//���屸��, 1:�������� 2:�ڽ���
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// ETF �����ڵ�, ETF �����ڵ�
	out->snr = Str2Int(data->snr, sizeof(data->snr));	// �Ϸù�ȣ, 1~99999999 �����Ϸù�ȣ,�Ǽ�üũ��
	memcpy(out->date, data->date, sizeof(data->date));	// ����, YYYYMMDD:����������
	out->trkg_err_rate = Str2Dbl(data->trkg_err_rate, sizeof(data->trkg_err_rate), 2);	// ����������, 9(7)V9(2), ����:% �� ���߰��̵� ����
	out->dspr = Str2SignDouble(data->dspr_sign, sizeof(data->dspr_sign) + sizeof(data->dspr), 2);	// ������, 9(7)V9(2), ����:%

	return 1;
}


// ETF_�����ں�
int ParseC0031(const double& timestamp, const char* in_buff, DF_ETF_BYINV* out) {
	ETF_BYINV* data = (ETF_BYINV*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����, C0
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������, 01:�ֽ�, 02:ELW, 03:ETF
	out->mkt_clsf = data->mkt_clsf[0];	//���屸��, 1:�������� 2:�ڽ���
	memcpy(out->cmpt_time, data->cmpt_time, sizeof(data->cmpt_time));	// ����ð�, 90�� �ֱ�
	memcpy(out->inv_code, data->inv_code, sizeof(data->inv_code));	// �������ڵ�, ���ڵ尪���� ����\n*�ڵ�'7000'�� ����, ������� �׸� 0���� ���� (20181210)
	memcpy(out->ind_code, data->ind_code, sizeof(data->ind_code));	// �����ڵ�, 0
	out->ask_ccls_qty = Str2Dbl(data->ask_ccls_qty, sizeof(data->ask_ccls_qty), 0);	// �ŵ�ü�����, ����:��
	out->ask_trd_val = Str2Dbl(data->ask_trd_val, sizeof(data->ask_trd_val), 0);	// �ŵ��ŷ����, ����:��
	out->bid_ccls_qty = Str2Dbl(data->bid_ccls_qty, sizeof(data->bid_ccls_qty), 0);	// �ż�ü�����, ����:��
	out->bid_trd_val = Str2Dbl(data->bid_trd_val, sizeof(data->bid_trd_val), 0);	// �ż��ŷ����, ����:��

	return 1;
}


// ȸ��������
int ParseM9011(const double& timestamp, const char* in_buff, DF_MBR_INFO* out) {
	MBR_INFO* data = (MBR_INFO*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����, M9
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������, 01:�ֽ�
	out->mkt_clsf = data->mkt_clsf[0];	//���屸��, 1:��������
	out->snr = Str2Int(data->snr, sizeof(data->snr));	// �Ϸù�ȣ, 00000001~99999999 �Ǽ�üũ��
	memcpy(out->opr_date, data->opr_date, sizeof(data->opr_date));	// ��������
	memcpy(out->mkt_ptcp_nr, data->mkt_ptcp_nr, sizeof(data->mkt_ptcp_nr));	// ���������ڹ�ȣ
	memcpy(out->mkt_ptcp_kor_nm, data->mkt_ptcp_kor_nm, sizeof(data->mkt_ptcp_kor_nm));	// �����������ѱ۸�
	memcpy(out->mkt_ptcp_eng_nm, data->mkt_ptcp_eng_nm, sizeof(data->mkt_ptcp_eng_nm));	// ���������ڿ�����
	memcpy(out->mkt_ptcp_kor_abrv, data->mkt_ptcp_kor_abrv, sizeof(data->mkt_ptcp_kor_abrv));	// �����������ѱ۾��

	return 1;
}


// KOSPI����
int ParseD0011(const double& timestamp, const char* in_buff, DF_KOSPI_IDX* out) {
	KOSPI_IDX* data = (KOSPI_IDX*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����, �ذ��߰��̵� ����
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������, 01:�ֽ�
	out->mkt_clsf = data->mkt_clsf[0];	//���屸��, 1:�������� 2:�ڽ���
	memcpy(out->ind_code, data->ind_code, sizeof(data->ind_code));	// �����ڵ�, �ذ��߰��̵� ����
	memcpy(out->time, data->time, sizeof(data->time));	// �ð�, �ذ��߰��̵� ����
	out->idx = Str2Dbl(data->idx, sizeof(data->idx), 2);	// ����, 9(6)V9(2)
	out->ctrs = Str2SignDouble(data->sign, sizeof(data->sign) + sizeof(data->ctrs), 2);	// ���, 999999V99
	out->ccls_qty = Str2Int(data->ccls_qty, sizeof(data->ccls_qty));	// ü�����, ����:õ��
	out->trd_val = Str2Int(data->trd_val, sizeof(data->trd_val));	// �ŷ����, ����:�鸸��

	return 1;
}


// KOSPI��������
int ParseD1011(const double& timestamp, const char* in_buff, DF_KOSPI_EXP_IDX* out) {
	KOSPI_EXP_IDX* data = (KOSPI_EXP_IDX*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����, �ذ��߰��̵� ����
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������, 01:�ֽ�
	out->mkt_clsf = data->mkt_clsf[0];	//���屸��, 1:�������� 2:�ڽ���
	memcpy(out->ind_code, data->ind_code, sizeof(data->ind_code));	// �����ڵ�, �ذ��߰��̵� ����
	memcpy(out->time, data->time, sizeof(data->time));	// �ð�, �ذ��߰��̵� ����
	out->idx = Str2Dbl(data->idx, sizeof(data->idx), 2);	// ����, 9(6)V9(2)
	out->ctrs = Str2SignDouble(data->sign, sizeof(data->sign) + sizeof(data->ctrs), 2);	// ���, 999999V99
	out->ccls_qty = Str2Int(data->ccls_qty, sizeof(data->ccls_qty));	// ü�����, ����:õ��
	out->trd_val = Str2Int(data->trd_val, sizeof(data->trd_val));	// �ŷ����, ����:�鸸��

	return 1;
}


// KOSPI200����
int ParseD2011(const double& timestamp, const char* in_buff, DF_KOSPI_200_IDX* out) {
	KOSPI_200_IDX* data = (KOSPI_200_IDX*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����, �ذ��߰��̵� ����
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������, 01:�ֽ�
	out->mkt_clsf = data->mkt_clsf[0];	//���屸��, 1:�������� 2:�ڽ���
	memcpy(out->ind_code, data->ind_code, sizeof(data->ind_code));	// �����ڵ�, �ذ��߰��̵� ����
	memcpy(out->time, data->time, sizeof(data->time));	// �ð�, �ذ��߰��̵� ����
	out->idx = Str2Dbl(data->idx, sizeof(data->idx), 2);	// ����, 9(6)V9(2)
	out->ctrs = Str2SignDouble(data->sign, sizeof(data->sign) + sizeof(data->ctrs), 2);	// ���, 999999V99
	out->ccls_qty = Str2Int(data->ccls_qty, sizeof(data->ccls_qty));	// ü�����, ����:õ��
	out->trd_val = Str2Int(data->trd_val, sizeof(data->trd_val));	// �ŷ����, ����:�鸸��

	return 1;
}


// KOSPI200��������
int ParseD3011(const double& timestamp, const char* in_buff, DF_KOSPI_200_EXP_IDX* out) {
	KOSPI_200_EXP_IDX* data = (KOSPI_200_EXP_IDX*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����, �ذ��߰��̵� ����
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������, 01:�ֽ�
	out->mkt_clsf = data->mkt_clsf[0];	//���屸��, 1:�������� 2:�ڽ���
	memcpy(out->ind_code, data->ind_code, sizeof(data->ind_code));	// �����ڵ�, �ذ��߰��̵� ����
	memcpy(out->time, data->time, sizeof(data->time));	// �ð�, �ذ��߰��̵� ����
	out->idx = Str2Dbl(data->idx, sizeof(data->idx), 2);	// ����, 9(6)V9(2)
	out->ctrs = Str2SignDouble(data->sign, sizeof(data->sign) + sizeof(data->ctrs), 2);	// ���, 999999V99
	out->ccls_qty = Str2Int(data->ccls_qty, sizeof(data->ccls_qty));	// ü�����, ����:õ��
	out->trd_val = Str2Int(data->trd_val, sizeof(data->trd_val));	// �ŷ����, ����:�鸸��

	return 1;
}


// KOSPI100/50����
int ParseD4011(const double& timestamp, const char* in_buff, DF_KOSPI_100_50_IDX* out) {
	KOSPI_100_50_IDX* data = (KOSPI_100_50_IDX*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����, �ذ��߰��̵� ����
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������, 01:�ֽ�
	out->mkt_clsf = data->mkt_clsf[0];	//���屸��, 1:�������� 2:�ڽ���
	memcpy(out->ind_code, data->ind_code, sizeof(data->ind_code));	// �����ڵ�, �ذ��߰��̵� ����
	memcpy(out->time, data->time, sizeof(data->time));	// �ð�, �ذ��߰��̵� ����
	out->idx = Str2Dbl(data->idx, sizeof(data->idx), 2);	// ����, 9(6)V9(2)
	out->ctrs = Str2SignDouble(data->sign, sizeof(data->sign) + sizeof(data->ctrs), 2);	// ���, 999999V99
	out->ccls_qty = Str2Int(data->ccls_qty, sizeof(data->ccls_qty));	// ü�����, ����:õ��
	out->trd_val = Str2Int(data->trd_val, sizeof(data->trd_val));	// �ŷ����, ����:�鸸��

	return 1;
}


// KOSPI200 ���Ϳ�������
int ParseN6011(const double& timestamp, const char* in_buff, DF_KOSPI_200_STR_EXP_IDX* out) {
	KOSPI_200_STR_EXP_IDX* data = (KOSPI_200_STR_EXP_IDX*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����, �ذ��߰��̵� ����
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������, 01:�ֽ�
	out->mkt_clsf = data->mkt_clsf[0];	//���屸��, 1:�������� 2:�ڽ���
	memcpy(out->ind_code, data->ind_code, sizeof(data->ind_code));	// �����ڵ�, �ذ��߰��̵� ����
	memcpy(out->time, data->time, sizeof(data->time));	// �ð�, �ذ��߰��̵� ����
	out->idx = Str2Dbl(data->idx, sizeof(data->idx), 2);	// ����, 9(6)V9(2)
	out->ctrs = Str2SignDouble(data->sign, sizeof(data->sign) + sizeof(data->ctrs), 2);	// ���, 999999V99
	out->ccls_qty = Str2Int(data->ccls_qty, sizeof(data->ccls_qty));	// ü�����, ����:õ��
	out->trd_val = Str2Int(data->trd_val, sizeof(data->trd_val));	// �ŷ����, ����:�鸸��

	return 1;
}


// KOSPI200 ��������
int ParseN5011(const double& timestamp, const char* in_buff, DF_KOSPI_200_STR_IDX* out) {
	KOSPI_200_STR_IDX* data = (KOSPI_200_STR_IDX*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����, �ذ��߰��̵� ����
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������, 01:�ֽ�
	out->mkt_clsf = data->mkt_clsf[0];	//���屸��, 1:�������� 2:�ڽ���
	memcpy(out->ind_code, data->ind_code, sizeof(data->ind_code));	// �����ڵ�, �ذ��߰��̵� ����
	memcpy(out->time, data->time, sizeof(data->time));	// �ð�, �ذ��߰��̵� ����
	out->idx = Str2Dbl(data->idx, sizeof(data->idx), 2);	// ����, 9(6)V9(2)
	out->ctrs = Str2SignDouble(data->sign, sizeof(data->sign) + sizeof(data->ctrs), 2);	// ���, 999999V99
	out->ccls_qty = Str2Int(data->ccls_qty, sizeof(data->ccls_qty));	// ü�����, ����:õ��
	out->trd_val = Str2Int(data->trd_val, sizeof(data->trd_val));	// �ŷ����, ����:�鸸��

	return 1;
}


// KRX100����
int ParseC8011(const double& timestamp, const char* in_buff, DF_KOSPI_100_IDX* out) {
	KOSPI_100_IDX* data = (KOSPI_100_IDX*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����, �ذ��߰��̵� ����
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������, 01:�ֽ�
	out->mkt_clsf = data->mkt_clsf[0];	//���屸��, 1:�������� 2:�ڽ��� 9:�ؿ��ְ����� 2012.04.30 �߰�
	memcpy(out->ind_code, data->ind_code, sizeof(data->ind_code));	// �����ڵ�, �ذ��߰��̵� ����
	memcpy(out->time, data->time, sizeof(data->time));	// �ð�, �ذ��߰��̵� ���� ���ؿ��ְ������� ��� GMT�ð�
	out->idx = Str2Dbl(data->idx, sizeof(data->idx), 2);	// ����, 9(6)V9(2)
	out->ctrs = Str2SignDouble(data->sign, sizeof(data->sign) + sizeof(data->ctrs), 2);	// ���, 999999V99
	out->ccls_qty = Str2Int(data->ccls_qty, sizeof(data->ccls_qty));	// ü�����, ����:õ�� ���ؿ��ְ������� ��� FILLERó��
	out->trd_val = Str2Int(data->trd_val, sizeof(data->trd_val));	// �ŷ����, ����:�鸸�� ���ؿ��ְ������� ��� FILLERó��

	return 1;
}


// KRX100��������
int ParseC9011(const double& timestamp, const char* in_buff, DF_KOSPI_100_EXP_IDX* out) {
	KOSPI_100_EXP_IDX* data = (KOSPI_100_EXP_IDX*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����, �ذ��߰��̵� ����
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������, 01:�ֽ�
	out->mkt_clsf = data->mkt_clsf[0];	//���屸��, 1:�������� 2:�ڽ��� 9:�ؿ��ְ����� 2012.04.30 �߰�
	memcpy(out->ind_code, data->ind_code, sizeof(data->ind_code));	// �����ڵ�, �ذ��߰��̵� ����
	memcpy(out->time, data->time, sizeof(data->time));	// �ð�, �ذ��߰��̵� ���� ���ؿ��ְ������� ��� GMT�ð�
	out->idx = Str2Dbl(data->idx, sizeof(data->idx), 2);	// ����, 9(6)V9(2)
	out->ctrs = Str2SignDouble(data->sign, sizeof(data->sign) + sizeof(data->ctrs), 2);	// ���, 999999V99
	out->ccls_qty = Str2Int(data->ccls_qty, sizeof(data->ccls_qty));	// ü�����, ����:õ�� ���ؿ��ְ������� ��� FILLERó��
	out->trd_val = Str2Int(data->trd_val, sizeof(data->trd_val));	// �ŷ����, ����:�鸸�� ���ؿ��ְ������� ��� FILLERó��

	return 1;
}


// ���ϰ�������
int ParseN9011(const double& timestamp, const char* in_buff, DF_EWIDX* out) {
	EWIDX* data = (EWIDX*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����, �ذ��߰��̵� ����
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������, 01:�ֽ�
	out->mkt_clsf = data->mkt_clsf[0];	//���屸��, 1:�������� 2:�ڽ���
	memcpy(out->ind_code, data->ind_code, sizeof(data->ind_code));	// �����ڵ�, �ذ��߰��̵� ����
	memcpy(out->time, data->time, sizeof(data->time));	// �ð�, �ذ��߰��̵� ����
	out->idx = Str2Dbl(data->idx, sizeof(data->idx), 2);	// ����, 9(6)V9(2)
	out->ctrs = Str2SignDouble(data->sign, sizeof(data->sign) + sizeof(data->ctrs), 2);	// ���, 999999V99
	out->ccls_qty = Str2Int(data->ccls_qty, sizeof(data->ccls_qty));	// ü�����, ����:õ��
	out->trd_val = Str2Int(data->trd_val, sizeof(data->trd_val));	// �ŷ����, ����:�鸸��

	return 1;
}


// ���ϰ��߿�������
int ParseO1011(const double& timestamp, const char* in_buff, DF_EWEIDX* out) {
	EWEIDX* data = (EWEIDX*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����, �ذ��߰��̵� ����
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������, 01:�ֽ�
	out->mkt_clsf = data->mkt_clsf[0];	//���屸��, 1:�������� 2:�ڽ���
	memcpy(out->ind_code, data->ind_code, sizeof(data->ind_code));	// �����ڵ�, �ذ��߰��̵� ����
	memcpy(out->time, data->time, sizeof(data->time));	// �ð�, �ذ��߰��̵� ����
	out->idx = Str2Dbl(data->idx, sizeof(data->idx), 2);	// ����, 9(6)V9(2)
	out->ctrs = Str2SignDouble(data->sign, sizeof(data->sign) + sizeof(data->ctrs), 2);	// ���, 999999V99
	out->ccls_qty = Str2Int(data->ccls_qty, sizeof(data->ccls_qty));	// ü�����, ����:õ��
	out->trd_val = Str2Int(data->trd_val, sizeof(data->trd_val));	// �ŷ����, ����:�鸸��

	return 1;
}


// �������� �׷�_�����ڵ�
int ParseG1067(const double& timestamp, const char* in_buff, DF_MARKET_IDX_GROUP_EXP_CODE* out) {
	MARKET_IDX_GROUP_EXP_CODE* data = (MARKET_IDX_GROUP_EXP_CODE*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����, G1
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������, 06:�峻�Ϲ�ä��
	out->mkt_clsf = data->mkt_clsf[0];	//���屸��, 7:ä��
	out->snr = Str2Int(data->snr, sizeof(data->snr));	// �Ϸù�ȣ, 1~99999999 �Ǽ�üũ��
	out->code_clsf = data->code_clsf[0];	//�ڵ� ����, 1:�׷��ڵ� 2:�����ڵ�
	memcpy(out->apl_date, data->apl_date, sizeof(data->apl_date));	// ������, YYYYMMDD
	memcpy(out->grp_mtr_code, data->grp_mtr_code, sizeof(data->grp_mtr_code));	// �׷�/�����ڵ�, �׷��ڵ�:"XXXXX", �����ڵ�:"XXX "
	memcpy(out->grp_mtr_code_nm, data->grp_mtr_code_nm, sizeof(data->grp_mtr_code_nm));	// �׷�/�����ڵ��
	out->grp_mtr_code_stg = data->grp_mtr_code_stg[0];	//�׷�/�����ڵ�ܰ�, �׷��ڵ�:0,1,2,3,4 �����ڵ�:0,1,2,3

	return 1;
}


// �������������
int ParseP3011(const double& timestamp, const char* in_buff, DF_WISEFN_IDX* out) {
	WISEFN_IDX* data = (WISEFN_IDX*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����, P3
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������, 01:�ֽ�
	out->mkt_clsf = data->mkt_clsf[0];	//���屸��, 1:��������
	memcpy(out->ind_code, data->ind_code, sizeof(data->ind_code));	// �����ڵ�, �ڵ尪���� ����\nWISEFn�ű�����4���߰�(2015.03.23)
	memcpy(out->time, data->time, sizeof(data->time));	// �ð�, �ذ��߰��̵� ����
	out->idx = Str2Dbl(data->idx, sizeof(data->idx), 2);	// ����, 9(6)V9(2)
	out->ctrs = Str2SignDouble(data->sign, sizeof(data->sign) + sizeof(data->ctrs), 2);	// ���, 999999V99
	out->ccls_qty = Str2Int(data->ccls_qty, sizeof(data->ccls_qty));	// ü�����, ����:õ��
	out->trd_val = Str2Int(data->trd_val, sizeof(data->trd_val));	// �ŷ����, ����:�鸸��

	return 1;
}


// �ڽ���_�ŷ���
int ParseB9011(const double& timestamp, const char* in_buff, DF_KOSPI_TRS* out) {
	int i=0;
	KOSPI_TRS* data = (KOSPI_TRS*)in_buff;

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


// ELW_�ŷ���
int ParseB9021(const double& timestamp, const char* in_buff, DF_ELW_TRS* out) {
	int i=0;
	ELW_TRS* data = (ELW_TRS*)in_buff;

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
int ParseC1011(const double& timestamp, const char* in_buff, DF_KOSPI_BYSTK_BYINV_CLS* out) {
	int i=0;
	KOSPI_BYSTK_BYINV_CLS* data = (KOSPI_BYSTK_BYINV_CLS*)in_buff;

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


// ELW_���������ں� ����
int ParseC1021(const double& timestamp, const char* in_buff, DF_ELW_BYSTK_BYINV_CLS* out) {
	int i=0;
	ELW_BYSTK_BYINV_CLS* data = (ELW_BYSTK_BYINV_CLS*)in_buff;

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


// �ؿ����� ETF NAV
int ParseL5011(const double& timestamp, const char* in_buff, DF_FRIDX_ETF_NAV* out) {
	FRIDX_ETF_NAV* data = (FRIDX_ETF_NAV*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����, F7(��������), L5(�ؿ�����) ��Ƽĳ��Ʈ ���� �� ����
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������, 01:�ֽ�
	out->mkt_clsf = data->mkt_clsf[0];	//���屸��, 1:��������
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// ETF �����ڵ�, ETF �����ڵ�
	memcpy(out->time, data->time, sizeof(data->time));	// �ð�, �ذ��߰��̵� ����
	out->prev_nav = Str2Dbl(data->prev_nav, sizeof(data->prev_nav), 2);	// ���� NAV, 9(7)V9(2)
	out->opr_time_fin_nav = Str2Dbl(data->opr_time_fin_nav, sizeof(data->opr_time_fin_nav), 2);	// ����/���� NAV, 9(7)V9(2)

	return 1;
}


// �ؿ�ETF ����������
int ParseP7011(const double& timestamp, const char* in_buff, DF_FRIDX_TER* out) {
	FRIDX_TER* data = (FRIDX_TER*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����, P7
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������, 01:�ֽ�
	out->mkt_clsf = data->mkt_clsf[0];	//���屸��, 1:�������� 2:�ڽ���
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// ETF �����ڵ�, ETF �����ڵ�
	out->snr = Str2Int(data->snr, sizeof(data->snr));	// �Ϸù�ȣ, 1~99999999 �����Ϸù�ȣ,�Ǽ�üũ��
	memcpy(out->date, data->date, sizeof(data->date));	// ����, YYYYMMDD:����������
	out->trkg_err_rate = Str2Dbl(data->trkg_err_rate, sizeof(data->trkg_err_rate), 2);	// ����������, 9(7)V9(2), ����:%
	out->dspr = Str2SignDouble(data->dspr_sign, sizeof(data->dspr_sign) + sizeof(data->dspr), 2);	// ������, 9(7)V9(2), ����:%

	return 1;
}


// �ռ�ETF ���� �ŷ����� �����򰡾� ����
int ParseQ4011(const double& timestamp, const char* in_buff, DF_SETF_DAY_CPTY_RISK_INFO* out) {
	SETF_DAY_CPTY_RISK_INFO* data = (SETF_DAY_CPTY_RISK_INFO*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����, Q4
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������, 01:�ֽ�
	out->mkt_clsf = data->mkt_clsf[0];	//���屸��, 1:�������� 2:�ڽ���
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// ETF�ڵ�, ǥ���ڵ�
	out->data_snr = Str2Int(data->data_snr, sizeof(data->data_snr));	// ������ �Ϸù�ȣ, 1~99999999 �����Ϸù�ȣ, �Ǽ�üũ��
	out->date = Str2Int(data->date, sizeof(data->date));	// ����, YYYYMMDD
	out->trb_nr = Str2Int(data->trb_nr, sizeof(data->trb_nr));	// �繫��Źȸ���ȣ, '903'�ѱ���Ź������,'049'�̷������ݵ弭��
	memcpy(out->cntr_pty_nm, data->cntr_pty_nm, sizeof(data->cntr_pty_nm));	// �ŷ������, �ŷ������
	out->ofmkt_drvt_type = Str2Int(data->ofmkt_drvt_type, sizeof(data->ofmkt_drvt_type));	// ����Ļ���ǰ����, 0:�ڱݰ����� 1:�ڱݺ������ �ذ��߰��̵� ����
	out->nav_tot_val = Str2Dbl(data->nav_tot_val, sizeof(data->nav_tot_val), 0);	// ���ڻ��Ѿ�, ����:��
	out->tot_risk_xps_val = Str2Dbl(data->tot_risk_xps_val, sizeof(data->tot_risk_xps_val), 0);	// ����������, ����:�� �ذ��߰��̵� ����
	out->cltr_assm_val = Str2Dbl(data->cltr_assm_val, sizeof(data->cltr_assm_val), 0);	// �㺸�򰡾�, ����:�� �ذ��߰��̵� ����
	out->cltr_rate = Str2Dbl(data->cltr_rate, sizeof(data->cltr_rate), 2);	// �㺸����, 99999V99 ����:% �ذ��߰��̵� ����
	out->risk_assm_val = Str2Dbl(data->risk_assm_val, sizeof(data->risk_assm_val), 0);	// �����򰡾�, ����:�� �ذ��߰��̵� ����
	out->risk_assm_rate = Str2Dbl(data->risk_assm_rate, sizeof(data->risk_assm_rate), 2);	// �����򰡾׺���, 99999V99 ����:% �ذ��߰��̵� ����

	return 1;
}


// MKF����
int ParseE2011(const double& timestamp, const char* in_buff, DF_MKF_IDX* out) {
	MKF_IDX* data = (MKF_IDX*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����, E2
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������, 01:�ֽ�
	out->mkt_clsf = data->mkt_clsf[0];	//���屸��, 1:�������� 2:�ڽ��� 2012.05.21 �߰�
	memcpy(out->ind_code, data->ind_code, sizeof(data->ind_code));	// �����ڵ�, �ذ��߰��̵� ����
	memcpy(out->time, data->time, sizeof(data->time));	// �ð�, �ذ��߰��̵� ����
	out->idx = Str2Dbl(data->idx, sizeof(data->idx), 2);	// ����, 9(6)V9(2)
	out->ctrs = Str2SignDouble(data->sign, sizeof(data->sign) + sizeof(data->ctrs), 2);	// ���, 999999V99
	out->ccls_qty = Str2Int(data->ccls_qty, sizeof(data->ccls_qty));	// ü�����, ����:õ��
	out->trd_val = Str2Int(data->trd_val, sizeof(data->trd_val));	// �ŷ����, ����:�鸸��

	return 1;
}


// MKF����(��ȯ���ݿ�)
int ParseO9011(const double& timestamp, const char* in_buff, DF_MKF_IDX_WYFX* out) {
	MKF_IDX_WYFX* data = (MKF_IDX_WYFX*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����, O9
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������, 01:�ֽ�
	out->mkt_clsf = data->mkt_clsf[0];	//���屸��, 1:�������� 2:�ڽ��� 2012.05.21 �߰�
	memcpy(out->ind_code, data->ind_code, sizeof(data->ind_code));	// �����ڵ�, �ذ��߰��̵� ����
	memcpy(out->time, data->time, sizeof(data->time));	// �ð�, �ذ��߰��̵� ����
	out->idx = Str2Dbl(data->idx, sizeof(data->idx), 2);	// ����, 9(6)V9(2)
	out->ctrs = Str2SignDouble(data->sign, sizeof(data->sign) + sizeof(data->ctrs), 2);	// ���, 999999V99
	out->ccls_qty = Str2Int(data->ccls_qty, sizeof(data->ccls_qty));	// ü�����, ����:õ��
	out->trd_val = Str2Int(data->trd_val, sizeof(data->trd_val));	// �ŷ����, ����:�鸸��

	return 1;
}


// �ؿ�����ETF�������
int ParseM3011(const double& timestamp, const char* in_buff, DF_FRIDX_ETF_IDX* out) {
	FRIDX_ETF_IDX* data = (FRIDX_ETF_IDX*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����, M3
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������, 01:�ֽ�
	out->mkt_clsf = data->mkt_clsf[0];	//���屸��, 1:��������
	memcpy(out->date, data->date, sizeof(data->date));	// ����, ���������� ������ ���ŵ����� ����, ���� �����Ϳ� �ߺ�����
	memcpy(out->smbl_code, data->smbl_code, sizeof(data->smbl_code));	// �ɺ��ڵ�, �ذ��߰��̵� ����
	memcpy(out->idx, data->idx, sizeof(data->idx));	// ����, 9999999V999, Excess Return(ER)
	memcpy(out->tot_profit_idx, data->tot_profit_idx, sizeof(data->tot_profit_idx));	// �Ѽ�������, 9999999V999, Total Retrun(TR) 2011.04.01 �ű�
	memcpy(out->cls_prc, data->cls_prc, sizeof(data->cls_prc));	// ����, 9999999V999, Close Price(Spot) 2011.04.01 �ű�

	return 1;
}


// �ؿ�����
int ParseO5019(const double& timestamp, const char* in_buff, DF_FRIDX* out) {
	FRIDX* data = (FRIDX*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����, �ش��� PAGE �������� ���� ����
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������, 01:�ֽ�
	out->mkt_clsf = data->mkt_clsf[0];	//���屸��, 1:�������� 2:�ڽ��� 9: �ؿ��ְ����� 2012.4.30 �߰�
	memcpy(out->ind_code, data->ind_code, sizeof(data->ind_code));	// �����ڵ�, �ذ��߰��̵� ����
	memcpy(out->time, data->time, sizeof(data->time));	// �ð�, �ذ��߰��̵� ���� ��MSCI����:EST(����ð�) 2013.02.18 ����
	out->idx = Str2Dbl(data->idx, sizeof(data->idx), 2);	// ����, 9(6)V9(2)
	out->ctrs = Str2SignDouble(data->sign, sizeof(data->sign) + sizeof(data->ctrs), 2);	// ���, 999999V99
	out->ccls_qty = Str2Int(data->ccls_qty, sizeof(data->ccls_qty));	// ü�����, ����:õ�� ���ؿ��ְ������� ��� FILLERó��
	out->trd_val = Str2Int(data->trd_val, sizeof(data->trd_val));	// �ŷ����, ����:�鸸�� ���ؿ��ְ������� ��� FILLERó��

	return 1;
}


// �ռ�ETF �������� ��������
int ParseQ5011(const double& timestamp, const char* in_buff, DF_SETF_BASE_IDX_COMP_STK* out) {
	SETF_BASE_IDX_COMP_STK* data = (SETF_BASE_IDX_COMP_STK*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����, Q5
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������, 01:�ֽ�
	out->mkt_clsf = data->mkt_clsf[0];	//���屸��, 1:�������� 2:�ڽ���
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// ETF�ڵ�, ǥ���ڵ�
	out->data_snr = Str2Int(data->data_snr, sizeof(data->data_snr));	// ������ �Ϸù�ȣ, 1~99999999 �����Ϸù�ȣ, �Ǽ�üũ��
	out->date = Str2Int(data->date, sizeof(data->date));	// ����, YYYYMMDD
	out->trb_nr = Str2Int(data->trb_nr, sizeof(data->trb_nr));	// �繫��Źȸ���ȣ, '903'�ѱ���Ź������,'049'�̷������ݵ弭��
	out->comp_stk_nr = Str2Int(data->comp_stk_nr, sizeof(data->comp_stk_nr));	// ���������, ����:����(��������)
	memcpy(out->comp_stk_code, data->comp_stk_code, sizeof(data->comp_stk_code));	// ���������ڵ�, ǥ���ڵ�\n�ؿ������� ��� '0' �Ǵ� SPACE�� Setting�� �� ����
	memcpy(out->comp_stk_nm, data->comp_stk_nm, sizeof(data->comp_stk_nm));	// ���������, �����
	out->comp_rate = Str2Dbl(data->comp_rate, sizeof(data->comp_rate), 2);	// ������, ������ ������\n99999V99 ����:%

	return 1;
}


// �������� �ܱ��� ������������_Ȯ��ġ
int ParseF1013(const double& timestamp, const char* in_buff, DF_FBRD_FRGN_INV_INFO* out) {
	FBRD_FRGN_INV_INFO* data = (FBRD_FRGN_INV_INFO*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����, F1
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������, 01:�ֽ� 90:��Ÿ
	out->mkt_clsf = data->mkt_clsf[0];	//���屸��, 1:�������� 2:�ڽ��� 3:�������� 7:ä��
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// �����ڵ�, ǥ���ڵ�
	out->snr = Str2Int(data->snr, sizeof(data->snr));	// �Ϸù�ȣ, 1~99999999 �Ǽ�üũ��
	memcpy(out->trd_date, data->trd_date, sizeof(data->trd_date));	// �Ÿ�����, YYYYMMDD
	out->stk_lim_ratio = Str2Dbl(data->stk_lim_ratio, sizeof(data->stk_lim_ratio), 4);	// �����ѵ�����, 9V9999 (��:15%�϶� �� 01500���� ����)
	out->psn_lim_ratio = Str2Dbl(data->psn_lim_ratio, sizeof(data->psn_lim_ratio), 4);	// �����ѵ�����, 9V9999 (��:15%�϶� �� 01500���� ����)
	out->stk_lstd = Str2Dbl(data->stk_lstd, sizeof(data->stk_lstd), 0);	// �����ֽļ�, ����:��
	out->ordbl_qty = Str2Dbl(data->ordbl_qty, sizeof(data->ordbl_qty), 0);	// �ֹ����ɼ���, ����:��
	out->lim_xhs_clsf = data->lim_xhs_clsf[0];	//�ѵ���������, 0:���� 1:�ѵ����� 2:�ѵ�����ű����� 3:�ѵ���������

	return 1;
}


// �������� �ܱ��� �ֹ����ɼ���
int ParseF2013(const double& timestamp, const char* in_buff, DF_FBRD_FRGN_ORDL_QTY* out) {
	FBRD_FRGN_ORDL_QTY* data = (FBRD_FRGN_ORDL_QTY*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����, F2
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������, 01:�ֽ� 90:��Ÿ
	out->mkt_clsf = data->mkt_clsf[0];	//���屸��, 1:�������� 2:�ڽ��� 3:�������� 7:ä��
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// �����ڵ�, ǥ���ڵ�
	out->ordbl_qty = Str2Dbl(data->ordbl_qty, sizeof(data->ordbl_qty), 0);	// �ֹ����ɼ���, ����:��(����� ����)
	memcpy(out->data_type, data->data_type, sizeof(data->data_type));	// ����������, 01:�ֹ����ɼ���(�ǽð�) 07:����ġ�ֹ����ɼ���(����)

	return 1;
}


// �������� �ܱ��� �����ֹ�����_����
int ParseF3013(const double& timestamp, const char* in_buff, DF_FBRD_FRGN_RSVD_ORD_CNCL* out) {
	FBRD_FRGN_RSVD_ORD_CNCL* data = (FBRD_FRGN_RSVD_ORD_CNCL*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����, F3
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������, 01:�ֽ�
	out->mkt_clsf = data->mkt_clsf[0];	//���屸��, 1:�������� 2:�ڽ��� 3:��������
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// �����ڵ�, ǥ���ڵ�
	memcpy(out->data_type, data->data_type, sizeof(data->data_type));	// ����������, 01:�����ֹ����� 02:�����ֹ�����
	out->proc_clsf = data->proc_clsf[0];	//ó������, 1:���� 2:���
	memcpy(out->rsvd_ord_date, data->rsvd_ord_date, sizeof(data->rsvd_ord_date));	// �����ֹ�����, YYYYMMDD
	memcpy(out->rsvd_ord_st_time, data->rsvd_ord_st_time, sizeof(data->rsvd_ord_st_time));	// �����ֹ����۽ð�, HHMM
	memcpy(out->rsvd_ord_ed_time, data->rsvd_ord_ed_time, sizeof(data->rsvd_ord_ed_time));	// �����ֹ�����ð�, HHMM

	return 1;
}


// �������� �ܱ��� Ȯ��ġ������������
int ParseF4013(const double& timestamp, const char* in_buff, DF_FBRD_FRGN_CFRM_DATA* out) {
	FBRD_FRGN_CFRM_DATA* data = (FBRD_FRGN_CFRM_DATA*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����, F4
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������, 01:�ֽ� 90:��Ÿ
	out->mkt_clsf = data->mkt_clsf[0];	//���屸��, 1:�������� 2:�ڽ��� 3:�������� 7:ä��
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// �����ڵ�, ǥ���ڵ�
	out->stk_lim_ratio = Str2Dbl(data->stk_lim_ratio, sizeof(data->stk_lim_ratio), 4);	// �����ѵ�����, 9V9999 (��:15%�϶� �� 01500���� ����)
	out->psn_lim_ratio = Str2Dbl(data->psn_lim_ratio, sizeof(data->psn_lim_ratio), 4);	// �����ѵ�����, 9V9999 (��:15%�϶� �� 01500���� ����)
	out->stk_lstd = Str2Dbl(data->stk_lstd, sizeof(data->stk_lstd), 0);	// �����ֽļ�, ����:��
	out->ordbl_qty = Str2Dbl(data->ordbl_qty, sizeof(data->ordbl_qty), 0);	// �ֹ����ɼ���, ����:��
	out->lim_xhs_clsf = data->lim_xhs_clsf[0];	//�ѵ���������, 0:���� 1:�ѵ��ʰ� 2:�߰� 3:����

	return 1;
}


// �������� �ܱ��� �ѵ�������ܸŸ�
int ParseF5013(const double& timestamp, const char* in_buff, DF_FBRD_FRGN_LMT_XHS* out) {
	FBRD_FRGN_LMT_XHS* data = (FBRD_FRGN_LMT_XHS*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����, F5
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������, 01:�ֽ�
	out->mkt_clsf = data->mkt_clsf[0];	//���屸��, 1:�������� 2:�ڽ��� 3:��������
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// �����ڵ�, ǥ���ڵ�
	out->clsf = data->clsf[0];	//����, 1:�ܰ��Է� 2:�ܰ����
	out->qty = Str2Int(data->qty, sizeof(data->qty));	// ����, ����:��
	out->prc = Str2Int(data->prc, sizeof(data->prc));	// ����, ����:��
	memcpy(out->proc_time, data->proc_time, sizeof(data->proc_time));	// ó���ð�, HHMMSSMM

	return 1;
}


// ELW ������ǥ�ΰ���
int ParseC7021(const double& timestamp, const char* in_buff, DF_ELW_INV_IDX_SST* out) {
	ELW_INV_IDX_SST* data = (ELW_INV_IDX_SST*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����, C7
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������, 02:ELW
	out->mkt_clsf = data->mkt_clsf[0];	//���屸��, 1:��������
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// �����ڵ�, ǥ���ڵ�
	memcpy(out->calc_time, data->calc_time, sizeof(data->calc_time));	// ����ð�, ����:HHMMSS(�ð�:��:��) 090000 ~ ������:JUNJJJ
	out->std_thr_val = Str2Dbl(data->std_thr_val, sizeof(data->std_thr_val), 2);	// ǥ���̷а�, 9(8)9V9(2) ��Ī���� 2010.06.14
	out->sst_delta = Str2SignDouble(data->sst_delta_sign, sizeof(data->sst_delta_sign) + sizeof(data->sst_delta), 6);	// �ΰ��� - ��Ÿ, 9V9(6)
	out->sst_gamma = Str2SignDouble(data->sst_gamma_sign, sizeof(data->sst_gamma_sign) + sizeof(data->sst_gamma), 6);	// �ΰ��� - ����, 9V9(6)
	out->sst_theta = Str2SignDouble(data->sst_theta_sign, sizeof(data->sst_theta_sign) + sizeof(data->sst_theta), 6);	// �ΰ��� - ��Ÿ, 9(6)V9(6)
	out->sst_vega = Str2SignDouble(data->sst_vega_sign, sizeof(data->sst_vega_sign) + sizeof(data->sst_vega), 6);	// �ΰ��� - ����, 9(6)V9(6)
	out->sst_ro = Str2SignDouble(data->sst_ro_sign, sizeof(data->sst_ro_sign) + sizeof(data->sst_ro), 6);	// �ΰ��� - ��, 9(6)V9(6)
	out->itnl_vol = Str2Dbl(data->itnl_vol, sizeof(data->itnl_vol), 2);	// ���纯����, 9(3)V9(2) ��������ELW�� ��� 0 (2010.08.30)
	out->tot_cost = Str2Dbl(data->tot_cost, sizeof(data->tot_cost), 2);	// ���ݺ��, 9(8)V9(2) ǥ��ELW�� ��� 0 (2010.08.30)

	return 1;
}


// �ڽ���_�ڻ��� ��ġ����
int ParseA9011(const double& timestamp, const char* in_buff, DF_KOSPI_TRS_STK_ARNG_INFO* out) {
	KOSPI_TRS_STK_ARNG_INFO* data = (KOSPI_TRS_STK_ARNG_INFO*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����, A9
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������, 01:�ֽ�
	out->mkt_clsf = data->mkt_clsf[0];	//���屸��, 1:�������� 2:�ڽ���
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// �����ڵ�, ǥ���ڵ�
	out->snr = Str2Int(data->snr, sizeof(data->snr));	// �Ϸù�ȣ, 1~99999999 �Ǽ�üũ��
	memcpy(out->trs_stk_id, data->trs_stk_id, sizeof(data->trs_stk_id));	// �ڻ��ֽŰ�ID, 0:�ش���� N:�ڻ��������Ϲ� S:�ڻ�����������ɼ�\n1~99999:�ڻ��ֽ�Ź�Ϸù�ȣ �ذ� ��������
	out->ask_bid_clsf_code = data->ask_bid_clsf_code[0];	//�ŵ��ż������ڵ�, 0:��Ź 1:�ŵ� 2:�ż�
	memcpy(out->trs_stk_date, data->trs_stk_date, sizeof(data->trs_stk_date));	// �ڻ��ֽ�û����, YYYYMMDD �ؽŰ��� ��� ��û���ڰ� ����
	memcpy(out->trs_stk_st_date, data->trs_stk_st_date, sizeof(data->trs_stk_st_date));	// �ڻ��ֽŰ�������, YYYYMMDD �Ű����� �ڻ��ָŸ� ��������
	memcpy(out->trs_stk_ed_date, data->trs_stk_ed_date, sizeof(data->trs_stk_ed_date));	// �ڻ��ֽŰ���������, YYYYMMDD �Ű����� �ڻ��ָŸ� ��������
	out->trs_stk_trd_code = data->trs_stk_trd_code[0];	//�ڻ��ָŸŹ���ڵ�, 0:�ش���� 1:�ڻ����Ϲ� 2:������ �ڻ��� 3:���ε� �ڻ���\n��2,3 : �������Ľð��ܴ뷮�ż��� ����, ���ϰŷ�(�ŸŰŷ���\n ����)���� ���\n ���Ϲ��ڻ��ִ� �ð��ܴ뷮 �ż��Ұ�(�ŵ��� ����)\n��3 : �������Ľð��ܴ뷮�ż��� ��/���Ѱ� ���Ѿ���
	out->trs_stk_ptcp_nr = Str2Int(data->trs_stk_ptcp_nr, sizeof(data->trs_stk_ptcp_nr));	// �ڻ��ֽ�û���������� ��ȣ, ȸ����ȣ ��) '00001'
	out->open_trs_stk_qty = Str2Dbl(data->open_trs_stk_qty, sizeof(data->open_trs_stk_qty), 0);	// �ð����ϰ��ڻ��ֽ�û ����, �Ű�Ⱓ���� ��û�� �ð����ϰ� ��û ����
	out->opr_time_trs_stk_qty = Str2Dbl(data->opr_time_trs_stk_qty, sizeof(data->opr_time_trs_stk_qty), 0);	// �����ڻ��ֽ�û����, �Ű�Ⱓ���� ��û�� ���� ��û ����
	out->ofhr_msv_trs_stk_qty = Str2Dbl(data->ofhr_msv_trs_stk_qty, sizeof(data->ofhr_msv_trs_stk_qty), 0);	// �ð��ܴ뷮�ڻ��� ��û����, �ð���(����, ����)������ �ڻ��� �Ű����
	out->trs_stk_cum_ccls_qty = Str2Dbl(data->trs_stk_cum_ccls_qty, sizeof(data->trs_stk_cum_ccls_qty), 0);	// �ڻ��ִ���ü�����, �Ű�Ⱓ���� ������, �ð��ܽ��忡�� �ڻ��� ü����� ����
	out->trs_stk_cum_trd_val = Str2Dbl(data->trs_stk_cum_trd_val, sizeof(data->trs_stk_cum_trd_val), 0);	// �ڻ��ִ����ŷ����, �Ű�Ⱓ���� ������, �ð��ܽ��忡�� �ڻ��� �ŷ���� ����

	return 1;
}


// �ڽ���_�ڻ��� �Ÿ�����
int ParseB0011(const double& timestamp, const char* in_buff, DF_KOSPI_TRS_STK_TRD_INFO* out) {
	KOSPI_TRS_STK_TRD_INFO* data = (KOSPI_TRS_STK_TRD_INFO*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����, B0
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������, 01:�ֽ�
	out->mkt_clsf = data->mkt_clsf[0];	//���屸��, 1:�������� 2:�ڽ���
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// �����ڵ�, ǥ���ڵ�
	out->snr = Str2Int(data->snr, sizeof(data->snr));	// �Ϸù�ȣ, 1~99999999 �����Ϸù�ȣ 2014.03.03
	out->ccls_prc = Str2Int(data->ccls_prc, sizeof(data->ccls_prc));	// ü�ᰡ��, ����:��
	out->ccls_qty = Str2Dbl(data->ccls_qty, sizeof(data->ccls_qty), 0);	// ü�����, ����:��
	memcpy(out->sess_id, data->sess_id, sizeof(data->sess_id));	// ����ID, �ڵ尪���� ����
	memcpy(out->bid_trs_stk_id, data->bid_trs_stk_id, sizeof(data->bid_trs_stk_id));	// �ż��ڻ��ֽŰ�ID, 0:�ش���� N:�ڻ��������Ϲ� S:�ڻ���������Ź�ɼ�\n1~99999:�ڻ��ֽ�Ź(�Ű��Ϸù�ȣ)\n�ذ��� �������� ��) "N", "1"\n���ڻ��ֽ�Ź�Ϸù�ȣ�� ���񺰷� ���������� ���� ä����\n ������ ���� ��Ź�� �Ϸù�ȣ�� �����ϴ� ������ ����\n ���� ���ؼ� ���� ��Źȸ�翡�� �ڻ��ָ� �Ű��� ��\n �ֵ��� ����ϱ� ������
	memcpy(out->ask_trs_stk_id, data->ask_trs_stk_id, sizeof(data->ask_trs_stk_id));	// �ŵ��ڻ��ֽŰ�ID, �ż��ڻ��ֽŰ�ID�� ����

	return 1;
}


// �������� KOSPI200����
int ParseK2011(const double& timestamp, const char* in_buff, DF_LVR_KOSPI200_IDX* out) {
	LVR_KOSPI200_IDX* data = (LVR_KOSPI200_IDX*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����, �ذ��߰��̵� ����
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������, 01:�ֽ�
	out->mkt_clsf = data->mkt_clsf[0];	//���屸��, 1:�������� 2:�ڽ���
	memcpy(out->ind_code, data->ind_code, sizeof(data->ind_code));	// �����ڵ�, �ذ��߰��̵� ����
	memcpy(out->time, data->time, sizeof(data->time));	// �ð�, �ذ��߰��̵� ����
	out->idx = Str2Dbl(data->idx, sizeof(data->idx), 2);	// ����, 9(6)V9(2)
	out->ctrs = Str2SignDouble(data->sign, sizeof(data->sign) + sizeof(data->ctrs), 2);	// ���, 999999V99
	out->ccls_qty = Str2Int(data->ccls_qty, sizeof(data->ccls_qty));	// ü�����, ����:õ��
	out->trd_val = Str2Int(data->trd_val, sizeof(data->trd_val));	// �ŷ����, ����:�鸸��

	return 1;
}


// �ڽ���_ȸ��������������
int ParseR3011(const double& timestamp, const char* in_buff, DF_KOSPI_MBR_SCT_CNCL_DCLS* out) {
	KOSPI_MBR_SCT_CNCL_DCLS* data = (KOSPI_MBR_SCT_CNCL_DCLS*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����, R3
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������, 01:�ֽ�
	out->mkt_clsf = data->mkt_clsf[0];	//���屸��, 1:�������� 2:�ڽ���
	memcpy(out->ind_code, data->ind_code, sizeof(data->ind_code));	// �����ڵ�, **: �������ش�
	out->stk_snr = Str2Int(data->stk_snr, sizeof(data->stk_snr));	// �����Ϸù�ȣ, �����ġ(A0)�� �����Ϸù�ȣ
	memcpy(out->open_info_clsf_code, data->open_info_clsf_code, sizeof(data->open_info_clsf_code));	// �������������ڵ�, �ڵ尪���� ����
	memcpy(out->open_time, data->open_time, sizeof(data->open_time));	// �����ð�
	memcpy(out->mbr_nr, data->mbr_nr, sizeof(data->mbr_nr));	// ȸ����ȣ
	out->mbr_sct_rng_code = Str2Int(data->mbr_sct_rng_code, sizeof(data->mbr_sct_rng_code));	// ȸ����������ڵ�, ȸ���� �ŷ��� ��� �Ǵ� �����ϴ� ����. Bitwise ����\n 1: �ŵ�(ǲ�ż�) ��Ź\n 2: �ŵ�(ǲ�ż�) �ڱ�\n 4: �ż�(ǲ�ŵ�) ��Ź\n 8: �ż�(ǲ�ŵ�) �ڱ�

	return 1;
}


// �ڽ���_�����������(VI)
int ParseR8011(const double& timestamp, const char* in_buff, DF_KOSPI_STK_STAT_INFO* out) {
	KOSPI_STK_STAT_INFO* data = (KOSPI_STK_STAT_INFO*)in_buff;

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
	memcpy(out->stt_vi_dspr, data->stt_vi_dspr, sizeof(data->stt_vi_dspr));	// ����VI�ߵ����ݱ�����, ����VI�ߵ� ������\n��ȣ�ڸ�(���:0, ����:-) + 99999.999999(��ȿ���� 12�ڸ�)
	memcpy(out->dyn_vi_dspr, data->dyn_vi_dspr, sizeof(data->dyn_vi_dspr));	// ����VI�ߵ����ݱ�����, ����VI�ߵ� ������\n��ȣ�ڸ�(���:0, ����:-) + 99999.999999(��ȿ���� 12�ڸ�)

	return 1;
}


// ETN �繫��Ź����
int ParseS1011(const double& timestamp, const char* in_buff, DF_ETN_TRA_INFO* out) {
	ETN_TRA_INFO* data = (ETN_TRA_INFO*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����, S1
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������, 01:�ֽ�
	out->mkt_clsf = data->mkt_clsf[0];	//���屸��, 1:��������
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// �����ڵ�, ǥ���ڵ�
	out->snr = Str2Int(data->snr, sizeof(data->snr));	// �Ϸù�ȣ, 1~99999999 �Ǽ�üũ��
	out->fin_idx_val = Str2Dbl(data->fin_idx_val, sizeof(data->fin_idx_val), 2);	// ������ǥ��ġ, 9999999V99 �������������� ���� IV,����:��
	out->idx_val = Str2Dbl(data->idx_val, sizeof(data->idx_val), 0);	// ��ǥ��ġ�ݾ�
	out->prev_base_prc = Str2Dbl(data->prev_base_prc, sizeof(data->prev_base_prc), 2);	// ���ϰ�ǥ���ذ���, 9999999V99
	out->prev_bdiv_base_prc = Str2Dbl(data->prev_bdiv_base_prc, sizeof(data->prev_bdiv_base_prc), 2);	// ���Ϲ������ǥ���ذ���, 9999999V99
	out->prev_cash_div_val = Str2Dbl(data->prev_cash_div_val, sizeof(data->prev_cash_div_val), 2);	// �������ݹ��ݾ�, 9999999999V99
	out->pprev_base_prc = Str2Dbl(data->pprev_base_prc, sizeof(data->pprev_base_prc), 2);	// �����ϰ��ݰ�ǥ���ذ���, 9999999V99
	out->vol_fut_clsf = Str2Int(data->vol_fut_clsf, sizeof(data->vol_fut_clsf));	// ��������������, 0:����������ETN 1:��Ÿ
	out->ely_rdmp_min_qty = Str2Dbl(data->ely_rdmp_min_qty, sizeof(data->ely_rdmp_min_qty), 0);	// �ߵ���ȯû���ּҼ���, ����:����
	out->ely_rdmp_fee_rate = Str2Dbl(data->ely_rdmp_fee_rate, sizeof(data->ely_rdmp_fee_rate), 8);	// �ߵ���ȯ��������, 99V99999999 ����:%
	out->tot_cost = Str2Dbl(data->tot_cost, sizeof(data->tot_cost), 2);	// �����, 9999999V99 ����:��

	return 1;
}


// ETN �������� ��������
int ParseS2011(const double& timestamp, const char* in_buff, DF_ETN_BASE_IDX_COMP_STK* out) {
	ETN_BASE_IDX_COMP_STK* data = (ETN_BASE_IDX_COMP_STK*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����, S2
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������, 01:�ֽ�
	out->mkt_clsf = data->mkt_clsf[0];	//���屸��, 1:��������
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// ETN �����ڵ�, ǥ���ڵ�(ETN�ڵ�)
	out->data_snr = Str2Int(data->data_snr, sizeof(data->data_snr));	// ������ �Ϸù�ȣ, 1~99999999 �����Ϸù�ȣ,�Ǽ�üũ��
	out->date = Str2Int(data->date, sizeof(data->date));	// ����, YYYYMMDD
	out->trb_nr = Str2Int(data->trb_nr, sizeof(data->trb_nr));	// �繫��Źȸ���ȣ, �繫��Źȸ���ȣ
	out->comp_stk_nr = Str2Int(data->comp_stk_nr, sizeof(data->comp_stk_nr));	// ���������, ����:����(��������)
	memcpy(out->comp_stk_code, data->comp_stk_code, sizeof(data->comp_stk_code));	// ���������ڵ�, ǥ���ڵ�\n�ؿ������� ��� '0' �Ǵ� SPACE�� Setting�� �� ����
	memcpy(out->comp_stk_nm, data->comp_stk_nm, sizeof(data->comp_stk_nm));	// ���������, �����
	out->comp_rate = Str2Dbl(data->comp_rate, sizeof(data->comp_rate), 2);	// ������, ������ ������\n99999V99 ����:%

	return 1;
}


// ETN_�����ں�
int ParseC0041(const double& timestamp, const char* in_buff, DF_ETN_BYINV* out) {
	ETN_BYINV* data = (ETN_BYINV*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����, C0
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������, 01:�ֽ�, 02:ELW, 03:ETF, 04:ETN
	out->mkt_clsf = data->mkt_clsf[0];	//���屸��, 1:�������� 2:�ڽ���
	memcpy(out->cmpt_time, data->cmpt_time, sizeof(data->cmpt_time));	// ����ð�, 90�� �ֱ�
	memcpy(out->inv_code, data->inv_code, sizeof(data->inv_code));	// �������ڵ�, ���ڵ尪���� ����\n*�ڵ�'7000'�� ����, ������� �׸� 0���� ���� (20181210)
	memcpy(out->ind_code, data->ind_code, sizeof(data->ind_code));	// �����ڵ�, 0
	out->ask_ccls_qty = Str2Dbl(data->ask_ccls_qty, sizeof(data->ask_ccls_qty), 0);	// �ŵ�ü�����, ����:��
	out->ask_trd_val = Str2Dbl(data->ask_trd_val, sizeof(data->ask_trd_val), 0);	// �ŵ��ŷ����, ����:��
	out->bid_ccls_qty = Str2Dbl(data->bid_ccls_qty, sizeof(data->bid_ccls_qty), 0);	// �ż�ü�����, ����:��
	out->bid_trd_val = Str2Dbl(data->bid_trd_val, sizeof(data->bid_trd_val), 0);	// �ż��ŷ����, ����:��

	return 1;
}


// ETN IIV
int ParseS3011(const double& timestamp, const char* in_buff, DF_ETN_IIV* out) {
	ETN_IIV* data = (ETN_IIV*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����, S3
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������, 01:�ֽ�
	out->mkt_clsf = data->mkt_clsf[0];	//���屸��, 1:��������
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// ETN �����ڵ�, ETN �����ڵ�
	memcpy(out->time, data->time, sizeof(data->time));	// �ð�, HHMMSS:���� JUNJJJ:�帶��
	out->prev_iv = Str2Dbl(data->prev_iv, sizeof(data->prev_iv), 2);	// ���� IV, 9(7)V9(2)
	out->opr_time_fin_iv = Str2Dbl(data->opr_time_fin_iv, sizeof(data->opr_time_fin_iv), 2);	// ����/���� IV, 9(7)V9(2)

	return 1;
}


// ETN �����ġ
int ParseA1041(const double& timestamp, const char* in_buff, DF_ETN_STK_ARNG* out) {
	ETN_STK_ARNG* data = (ETN_STK_ARNG*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����, A1
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������, 04:ETN
	out->mkt_clsf = data->mkt_clsf[0];	//���屸��, 1:��������
	memcpy(out->isin_code, data->isin_code, sizeof(data->isin_code));	// �����ڵ�, ǥ���ڵ�
	out->snr = Str2Int(data->snr, sizeof(data->snr));	// �Ϸù�ȣ, 1~99999999 �Ǽ�üũ��
	memcpy(out->etn_ptcp_kor_nm, data->etn_ptcp_kor_nm, sizeof(data->etn_ptcp_kor_nm));	// ETN��������������ѱ۸�
	memcpy(out->etn_ptcp_eng_nm, data->etn_ptcp_eng_nm, sizeof(data->etn_ptcp_eng_nm));	// ETN������������ڿ�����
	memcpy(out->etn_ptcp_nr, data->etn_ptcp_nr, sizeof(data->etn_ptcp_nr));	// ETN������������ڹ�ȣ, ETN����ȸ������ ��ȣ(�����, ������ ���о���)\n��) ��00001��
	out->etn_fin_pymt_code = data->etn_fin_pymt_code[0];	//ETN������������ڵ�, A:����+�ǹ��μ������� C:���ݰ��� D:�ǹ��μ�������
	memcpy(out->etn_fin_trd_date, data->etn_fin_trd_date, sizeof(data->etn_fin_trd_date));	// ETN�����ŷ�����, YYYYMMDD
	memcpy(out->etn_pymt_date, data->etn_pymt_date, sizeof(data->etn_pymt_date));	// ETN��������, YYYYMMDD
	out->etn_lp_hld_qty = Str2Dbl(data->etn_lp_hld_qty, sizeof(data->etn_lp_hld_qty), 0);	// ETN LP��������
	memcpy(out->loss_cut_etn_profit_strt_code, data->loss_cut_etn_profit_strt_code, sizeof(data->loss_cut_etn_profit_strt_code));	// �ս�����ETN���ͱ����ڵ�, �ս�����ETN���ͱ����ڵ�\n�ˢ��ڵ尪�ˢ�\n 01: ��\n 02: ǲ\n 03: �ݽ�������\n 04: ǲ��������\n 05: �����ȯ �ݽ�������\n 06: �����ȯ ���ƿ���\n 07: ������ ������\n 08: �����ö���\n 09: �ܵ���\n 10: �����ȯ ǲ��������\n 11: �����ȯ ���ƿ�ǲ\n(2017.03.27 �׸��߰�)
	out->etn_max_rdm_prc = Str2Dbl(data->etn_max_rdm_prc, sizeof(data->etn_max_rdm_prc), 3);	// ETN�ִ��ȯ����, ETN���� ���Ǵ� ����� ������ �ִ� ��ȯ���� \n9(9)V9(3)\n(2017.03.27 �׸��߰�)
	out->etn_min_rdm_prc = Str2Dbl(data->etn_min_rdm_prc, sizeof(data->etn_min_rdm_prc), 3);	// ETN�ּһ�ȯ����, ETN���� ���Ǵ� ����� ������ �ּ� ��ȯ����\n9(9)V9(3)\n(2017.03.27 �׸��߰�)
	out->etn_ely_rdm_flg = data->etn_ely_rdm_flg[0];	//ETN�����ȯ���ɿ���, �ս����� ETN�� �����ȯ ���� ���� ����\n(2017.03.27 �׸��߰�)
	memcpy(out->etn_ely_rdm_frq_code, data->etn_ely_rdm_frq_code, sizeof(data->etn_ely_rdm_frq_code));	// ETN�����ȯ�ֱ��ڵ�, �ս����� ETN�� �����ȯ �ֱ� ����\nETN�����ȯ���ɿ��ΰ� Y�϶��� ���ð���\n�ˢ��ڵ尪�ˢ�\n01: ����(����)\n02: �� 3����\n03: �� 4����\n04: �� 6����\n05: �� 1�� (��缭���� ����)\n06: 3�������� �� 1���� (��缭���� ����)\n07: 6�������� �� 1���� (��缭���� ����)\n(2017.03.27 �׸��߰�)
	memcpy(out->assm_prc_cmpt_inst_code1, data->assm_prc_cmpt_inst_code1, sizeof(data->assm_prc_cmpt_inst_code1));	// �򰡰��ݻ������ڵ�1, ETN�� �򰡰����� �����ϴ� ����ڵ� 1\n�ˢ��ڵ尪�ˢ�\n01:�ѱ��ڻ���\n02:NICE P&I\n03:KISä����\n04:Fn�ڻ���\n(2017.03.27 �׸��߰�)
	memcpy(out->assm_prc_cmpt_inst_code2, data->assm_prc_cmpt_inst_code2, sizeof(data->assm_prc_cmpt_inst_code2));	// �򰡰��ݻ������ڵ�2, ETN�� �򰡰����� �����ϴ� ����ڵ� 2\n�ˢ��ڵ尪�ˢ�\n01:�ѱ��ڻ���\n02:NICE P&I\n03:KISä����\n04:Fn�ڻ���\n(2017.03.27 �׸��߰�)

	return 1;
}


// KTOP30����
int ParseT7011(const double& timestamp, const char* in_buff, DF_KTOP30_IDX* out) {
	KTOP30_IDX* data = (KTOP30_IDX*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����, �ذ��߰��̵� ����
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������, 01:�ֽ�
	out->mkt_clsf = data->mkt_clsf[0];	//���屸��, 1:�������� 2:�ڽ��� 9:�ؿ��ְ�����
	memcpy(out->ind_clsf, data->ind_clsf, sizeof(data->ind_clsf));	// �����ڵ�, �ذ��߰��̵� ����
	memcpy(out->time, data->time, sizeof(data->time));	// �ð�
	out->idx = Str2Dbl(data->idx, sizeof(data->idx), 2);	// ����, 9(6)V9(2)
	out->crst = Str2SignDouble(data->sign, sizeof(data->sign) + sizeof(data->crst), 2);	// ���, 999999.99
	out->ccls_qty = Str2Int(data->ccls_qty, sizeof(data->ccls_qty));	// ü�����, ����:õ�� ���ؿ��ְ������� ��� FILLERó��
	out->trd_val = Str2Int(data->trd_val, sizeof(data->trd_val));	// �ŷ����, ����:�鸸�� ���ؿ��ְ������� ��� FILLERó��

	return 1;
}


// KTOP30��������
int ParseT8011(const double& timestamp, const char* in_buff, DF_KTOP30_EXP_IDX* out) {
	KTOP30_EXP_IDX* data = (KTOP30_EXP_IDX*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����, �ذ��߰��̵� ����
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������, 01:�ֽ�
	out->mkt_clsf = data->mkt_clsf[0];	//���屸��, 1:�������� 2:�ڽ��� 9:�ؿ��ְ�����
	memcpy(out->ind_clsf, data->ind_clsf, sizeof(data->ind_clsf));	// �����ڵ�, �ذ��߰��̵� ����
	memcpy(out->time, data->time, sizeof(data->time));	// �ð�
	out->idx = Str2Dbl(data->idx, sizeof(data->idx), 2);	// ����, 9(6)V9(2)
	out->crst = Str2SignDouble(data->sign, sizeof(data->sign) + sizeof(data->crst), 2);	// ���, 999999.99
	out->ccls_qty = Str2Int(data->ccls_qty, sizeof(data->ccls_qty));	// ü�����, ����:õ�� ���ؿ��ְ������� ��� FILLERó��
	out->trd_val = Str2Int(data->trd_val, sizeof(data->trd_val));	// �ŷ����, ����:�鸸�� ���ؿ��ְ������� ��� FILLERó��

	return 1;
}
