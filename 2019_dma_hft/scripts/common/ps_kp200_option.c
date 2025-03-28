// ps_kp200_option.c
// KOSPI200 �����ɼ�
// �ּ��� \n�� ���� ���߿� �̻ڰ� �ٲ����

#include "ps_kp200_option.h"


extern int     Str2Int(char *str, int size);
extern double  Str2Dbl(char *str, int size, int point);
extern double  Str2SignDouble(char *str, int size, int point);


// K200�ɼ�_����+�����ջ�
int ParseC4034(const double& timestamp, const char* in_buff, DF_K200_OPT_COMP_BLOCK* out) {
	K200_OPT_COMP_BLOCK* data = (K200_OPT_COMP_BLOCK*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����, C4
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������, 03:KOSPI200�����ɼ�
	out->mkt_clsf = data->mkt_clsf[0];	//���屸��, 4
	memcpy(out->isin_clsf, data->isin_clsf, sizeof(data->isin_clsf));	// �����ڵ�
	out->stk_snr = Str2Int(data->stk_snr, sizeof(data->stk_snr));	// �����Ϸù�ȣ
	out->cpt_block_trd_vol = Str2Dbl(data->cpt_block_trd_vol, sizeof(data->cpt_block_trd_vol), 0);	// ����+�����ջ� �ŷ���, ����Ÿſ� ���Ǵ뷮�ŷ��� �ջ��� �ŷ���
	out->cpt_block_trd_amt = Str2Dbl(data->cpt_block_trd_amt, sizeof(data->cpt_block_trd_amt), 0);	// ����+�����ջ� �ŷ����, ����Ÿſ� ���Ǵ뷮�ŷ��� �ջ��� �ŷ����\n(���� : ��)

	return 1;
}


// K200�ɼ�_ü��
int ParseA3034(const double& timestamp, const char* in_buff, DF_K200_OPT_EXEC* out) {
	K200_OPT_EXEC* data = (K200_OPT_EXEC*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����, A3
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������, 03:KOSPI200�����ɼ�
	out->mrk_clsf = data->mrk_clsf[0];	//���屸��, 4
	memcpy(out->isin_clsf, data->isin_clsf, sizeof(data->isin_clsf));	// �����ڵ�
	out->stk_snr = Str2Int(data->stk_snr, sizeof(data->stk_snr));	// �����Ϸù�ȣ, �����Ϸù�ȣ �ڸ��� ����(3->4)
	memcpy(out->brd_id, data->brd_id, sizeof(data->brd_id));	// ����ID, �ڵ尪��������
	out->cur_prc = Str2Dbl(data->cur_prc, sizeof(data->cur_prc), 2);	// ���簡��, ��) 999.99
	out->exe_q = Str2Int(data->exe_q, sizeof(data->exe_q));	// ü�����
	memcpy(out->ss_id, data->ss_id, sizeof(data->ss_id));	// ����ID, �ڵ尪��������
	memcpy(out->exe_t, data->exe_t, sizeof(data->exe_t));	// ü��ð�
	out->init_prc = Str2Dbl(data->init_prc, sizeof(data->init_prc), 2);	// �ð�, ��) 999.99
	out->high_prc = Str2Dbl(data->high_prc, sizeof(data->high_prc), 2);	// ��, ��) 999.99
	out->low_prc = Str2Dbl(data->low_prc, sizeof(data->low_prc), 2);	// ����, ��) 999.99
	out->pri_prc = Str2Dbl(data->pri_prc, sizeof(data->pri_prc), 2);	// ��������, ��) 999.99
	out->accm_exe_q = Str2Int(data->accm_exe_q, sizeof(data->accm_exe_q));	// ����ü�����
	out->accm_trd_amt = Str2Dbl(data->accm_trd_amt, sizeof(data->accm_trd_amt), 0);	// �����ŷ����, ����:õ��
	out->l_or_s = data->l_or_s[0];	//�����ŵ��ż������ڵ�, 1:�ŵ�,2:�ż�(�������� ���� ȣ���� �ŵ��ż����а�)
	out->real_t_high_prc = Str2Dbl(data->real_t_high_prc, sizeof(data->real_t_high_prc), 2);	// �ǽð����Ѱ�, ��) 999.99 ���߰��̵�����
	out->real_t_low_prc = Str2Dbl(data->real_t_low_prc, sizeof(data->real_t_low_prc), 2);	// �ǽð����Ѱ�, ��) 999.99 ���߰��̵�����

	return 1;
}


// K200�ɼ�_�켱ȣ��
int ParseB6034(const double& timestamp, const char* in_buff, DF_K200_OPT_LIMIT_ORD* out) {
	K200_OPT_LIMIT_ORD* data = (K200_OPT_LIMIT_ORD*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����, B6
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������, 03:KOSPI200�����ɼ�
	out->mrk_clsf = data->mrk_clsf[0];	//���屸��, 4
	memcpy(out->isin_clsf, data->isin_clsf, sizeof(data->isin_clsf));	// �����ڵ�
	out->stk_snr = Str2Int(data->stk_snr, sizeof(data->stk_snr));	// �����Ϸù�ȣ, �����Ϸù�ȣ �ڸ��� ����(3->4)
	memcpy(out->brd_id, data->brd_id, sizeof(data->brd_id));	// ����ID, �ڵ尪��������
	memcpy(out->ss_id, data->ss_id, sizeof(data->ss_id));	// ����ID, �ڵ尪��������
	out->total_l_limit_ord_q = Str2Int(data->total_l_limit_ord_q, sizeof(data->total_l_limit_ord_q));	// �ż���ȣ���ܷ�
	out->l_lvl_1_prc = Str2Dbl(data->l_lvl_1_prc, sizeof(data->l_lvl_1_prc), 2);	// �ż�1�ܰ�켱ȣ������, ��) 999.99
	out->l_lvl_1_q = Str2Int(data->l_lvl_1_q, sizeof(data->l_lvl_1_q));	// �ż�1�ܰ�켱ȣ���ܷ�
	out->l_lvl_2_prc = Str2Dbl(data->l_lvl_2_prc, sizeof(data->l_lvl_2_prc), 2);	// �ż�2�ܰ�켱ȣ������, ��) 999.99
	out->l_lvl_2_q = Str2Int(data->l_lvl_2_q, sizeof(data->l_lvl_2_q));	// �ż�2�ܰ�켱ȣ���ܷ�
	out->l_lvl_3_prc = Str2Dbl(data->l_lvl_3_prc, sizeof(data->l_lvl_3_prc), 2);	// �ż�3�ܰ�켱ȣ������, ��) 999.99
	out->l_lvl_3_q = Str2Int(data->l_lvl_3_q, sizeof(data->l_lvl_3_q));	// �ż�3�ܰ�켱ȣ���ܷ�
	out->l_lvl_4_prc = Str2Dbl(data->l_lvl_4_prc, sizeof(data->l_lvl_4_prc), 2);	// �ż�4�ܰ�켱ȣ������, ��) 999.99
	out->l_lvl_4_q = Str2Int(data->l_lvl_4_q, sizeof(data->l_lvl_4_q));	// �ż�4�ܰ�켱ȣ���ܷ�
	out->l_lvl_5_prc = Str2Dbl(data->l_lvl_5_prc, sizeof(data->l_lvl_5_prc), 2);	// �ż�5�ܰ�켱ȣ������, ��) 999.99
	out->l_lvl_5_q = Str2Int(data->l_lvl_5_q, sizeof(data->l_lvl_5_q));	// �ż�5�ܰ�켱ȣ���ܷ�
	out->total_s_limit_ord_q = Str2Int(data->total_s_limit_ord_q, sizeof(data->total_s_limit_ord_q));	// �ŵ���ȣ���ܷ�
	out->s_lvl_1_prc = Str2Dbl(data->s_lvl_1_prc, sizeof(data->s_lvl_1_prc), 2);	// �ŵ�1�ܰ�켱ȣ������, ��) 999.99
	out->s_lvl_1_q = Str2Int(data->s_lvl_1_q, sizeof(data->s_lvl_1_q));	// �ŵ�1�ܰ�켱ȣ���ܷ�
	out->s_lvl_2_prc = Str2Dbl(data->s_lvl_2_prc, sizeof(data->s_lvl_2_prc), 2);	// �ŵ�2�ܰ�켱ȣ������, ��) 999.99
	out->s_lvl_2_q = Str2Int(data->s_lvl_2_q, sizeof(data->s_lvl_2_q));	// �ŵ�2�ܰ�켱ȣ���ܷ�
	out->s_lvl_3_prc = Str2Dbl(data->s_lvl_3_prc, sizeof(data->s_lvl_3_prc), 2);	// �ŵ�3�ܰ�켱ȣ������, ��) 999.99
	out->s_lvl_3_q = Str2Int(data->s_lvl_3_q, sizeof(data->s_lvl_3_q));	// �ŵ�3�ܰ�켱ȣ���ܷ�
	out->s_lvl_4_prc = Str2Dbl(data->s_lvl_4_prc, sizeof(data->s_lvl_4_prc), 2);	// �ŵ�4�ܰ�켱ȣ������, ��) 999.99
	out->s_lvl_4_q = Str2Int(data->s_lvl_4_q, sizeof(data->s_lvl_4_q));	// �ŵ�4�ܰ�켱ȣ���ܷ�
	out->s_lvl_5_prc = Str2Dbl(data->s_lvl_5_prc, sizeof(data->s_lvl_5_prc), 2);	// �ŵ�5�ܰ�켱ȣ������, ��) 999.99
	out->s_lvl_5_q = Str2Int(data->s_lvl_5_q, sizeof(data->s_lvl_5_q));	// �ŵ�5�ܰ�켱ȣ���ܷ�
	out->total_l_trd_cnt = Str2Int(data->total_l_trd_cnt, sizeof(data->total_l_trd_cnt));	// �ż���ȿȣ���Ǽ�
	out->l_lvl_1_trd_cnt = Str2Int(data->l_lvl_1_trd_cnt, sizeof(data->l_lvl_1_trd_cnt));	// �ż�1�ܰ�켱ȣ���Ǽ�
	out->l_lvl_2_trd_cnt = Str2Int(data->l_lvl_2_trd_cnt, sizeof(data->l_lvl_2_trd_cnt));	// �ż�2�ܰ�켱ȣ���Ǽ�
	out->l_lvl_3_trd_cnt = Str2Int(data->l_lvl_3_trd_cnt, sizeof(data->l_lvl_3_trd_cnt));	// �ż�3�ܰ�켱ȣ���Ǽ�
	out->l_lvl_4_trd_cnt = Str2Int(data->l_lvl_4_trd_cnt, sizeof(data->l_lvl_4_trd_cnt));	// �ż�4�ܰ�켱ȣ���Ǽ�
	out->l_lvl_5_trd_cnt = Str2Int(data->l_lvl_5_trd_cnt, sizeof(data->l_lvl_5_trd_cnt));	// �ż�5�ܰ�켱ȣ���Ǽ�
	out->total_s_trd_cnt = Str2Int(data->total_s_trd_cnt, sizeof(data->total_s_trd_cnt));	// �ŵ���ȿȣ���Ǽ�
	out->s_lvl_1_trd_cnt = Str2Int(data->s_lvl_1_trd_cnt, sizeof(data->s_lvl_1_trd_cnt));	// �ŵ�1�ܰ�켱ȣ���Ǽ�
	out->s_lvl_2_trd_cnt = Str2Int(data->s_lvl_2_trd_cnt, sizeof(data->s_lvl_2_trd_cnt));	// �ŵ�2�ܰ�켱ȣ���Ǽ�
	out->s_lvl_3_trd_cnt = Str2Int(data->s_lvl_3_trd_cnt, sizeof(data->s_lvl_3_trd_cnt));	// �ŵ�3�ܰ�켱ȣ���Ǽ�
	out->s_lvl_4_trd_cnt = Str2Int(data->s_lvl_4_trd_cnt, sizeof(data->s_lvl_4_trd_cnt));	// �ŵ�4�ܰ�켱ȣ���Ǽ�
	out->s_lvl_5_trd_cnt = Str2Int(data->s_lvl_5_trd_cnt, sizeof(data->s_lvl_5_trd_cnt));	// �ŵ�5�ܰ�켱ȣ���Ǽ�
	memcpy(out->ord_rcv_t, data->ord_rcv_t, sizeof(data->ord_rcv_t));	// ȣ�������ð�
	out->exp_prc = Str2Dbl(data->exp_prc, sizeof(data->exp_prc), 2);	// ����ü�ᰡ��, ��) 999.99 ���ϰ��ŸŽø� ����\n (����±����ڵ�:10,20,30,80)

	return 1;
}


// K200�ɼ�_ü��_�켱ȣ��
int ParseG7034(const double& timestamp, const char* in_buff, DF_K200_OPT_EXEC_LIMIT_ORD* out) {
	K200_OPT_EXEC_LIMIT_ORD* data = (K200_OPT_EXEC_LIMIT_ORD*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����, G7
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������, 03:KOSPI200�����ɼ�
	out->mrk_clsf = data->mrk_clsf[0];	//���屸��, 4
	memcpy(out->isin_clsf, data->isin_clsf, sizeof(data->isin_clsf));	// �����ڵ�
	out->stk_snr = Str2Int(data->stk_snr, sizeof(data->stk_snr));	// �����Ϸù�ȣ, �����Ϸù�ȣ �ڸ��� ����(3->4)
	memcpy(out->brd_id, data->brd_id, sizeof(data->brd_id));	// ����ID, �ڵ尪��������
	out->cur_prc = Str2Dbl(data->cur_prc, sizeof(data->cur_prc), 2);	// ���簡��, ��) 999.99
	out->exe_q = Str2Int(data->exe_q, sizeof(data->exe_q));	// ü�����
	memcpy(out->ss_id, data->ss_id, sizeof(data->ss_id));	// ����ID, �ڵ尪��������
	memcpy(out->exe_t, data->exe_t, sizeof(data->exe_t));	// ü��ð�
	out->init_prc = Str2Dbl(data->init_prc, sizeof(data->init_prc), 2);	// �ð�, ��) 999.99
	out->high_prc = Str2Dbl(data->high_prc, sizeof(data->high_prc), 2);	// ��, ��) 999.99
	out->low_prc = Str2Dbl(data->low_prc, sizeof(data->low_prc), 2);	// ����, ��) 999.99
	out->pri_prc = Str2Dbl(data->pri_prc, sizeof(data->pri_prc), 2);	// ��������, ��) 999.99
	out->accm_exe_q = Str2Int(data->accm_exe_q, sizeof(data->accm_exe_q));	// ����ü�����
	out->accm_trd_amt = Str2Dbl(data->accm_trd_amt, sizeof(data->accm_trd_amt), 0);	// �����ŷ����, ����:õ��
	out->l_or_s = data->l_or_s[0];	//�����ŵ��ż������ڵ�, 1:�ŵ�,2:�ż�(�������� ���� ȣ���� �ŵ��ż����а�)
	out->total_l_limit_ord_q = Str2Int(data->total_l_limit_ord_q, sizeof(data->total_l_limit_ord_q));	// �ż���ȣ���ܷ�
	out->l_lvl_1_prc = Str2Dbl(data->l_lvl_1_prc, sizeof(data->l_lvl_1_prc), 2);	// �ż�1�ܰ�켱ȣ������, ��) 999.99
	out->l_lvl_1_q = Str2Int(data->l_lvl_1_q, sizeof(data->l_lvl_1_q));	// �ż�1�ܰ�켱ȣ���ܷ�
	out->l_lvl_2_prc = Str2Dbl(data->l_lvl_2_prc, sizeof(data->l_lvl_2_prc), 2);	// �ż�2�ܰ�켱ȣ������, ��) 999.99
	out->l_lvl_2_q = Str2Int(data->l_lvl_2_q, sizeof(data->l_lvl_2_q));	// �ż�2�ܰ�켱ȣ���ܷ�
	out->l_lvl_3_prc = Str2Dbl(data->l_lvl_3_prc, sizeof(data->l_lvl_3_prc), 2);	// �ż�3�ܰ�켱ȣ������, ��) 999.99
	out->l_lvl_3_q = Str2Int(data->l_lvl_3_q, sizeof(data->l_lvl_3_q));	// �ż�3�ܰ�켱ȣ���ܷ�
	out->l_lvl_4_prc = Str2Int(data->l_lvl_4_prc, sizeof(data->l_lvl_4_prc));	// �ż�4�ܰ�켱ȣ������
	out->l_lvl_4_q = Str2Int(data->l_lvl_4_q, sizeof(data->l_lvl_4_q));	// �ż�4�ܰ�켱ȣ���ܷ�
	out->l_lvl_5_prc = Str2Dbl(data->l_lvl_5_prc, sizeof(data->l_lvl_5_prc), 2);	// �ż�5�ܰ�켱ȣ������, ��) 999.99
	out->l_lvl_5_q = Str2Int(data->l_lvl_5_q, sizeof(data->l_lvl_5_q));	// �ż�5�ܰ�켱ȣ���ܷ�
	out->total_s_limit_ord_q = Str2Int(data->total_s_limit_ord_q, sizeof(data->total_s_limit_ord_q));	// �ŵ���ȣ���ܷ�
	out->s_lvl_1_prc = Str2Dbl(data->s_lvl_1_prc, sizeof(data->s_lvl_1_prc), 2);	// �ŵ�1�ܰ�켱ȣ������, ��) 999.99
	out->s_lvl_1_q = Str2Int(data->s_lvl_1_q, sizeof(data->s_lvl_1_q));	// �ŵ�1�ܰ�켱ȣ���ܷ�
	out->s_lvl_2_prc = Str2Int(data->s_lvl_2_prc, sizeof(data->s_lvl_2_prc));	// �ŵ�2�ܰ�켱ȣ������
	out->s_lvl_2_q = Str2Dbl(data->s_lvl_2_q, sizeof(data->s_lvl_2_q), 2);	// �ŵ�2�ܰ�켱ȣ���ܷ�, ��) 999.99
	out->s_lvl_3_prc = Str2Int(data->s_lvl_3_prc, sizeof(data->s_lvl_3_prc));	// �ŵ�3�ܰ�켱ȣ������
	out->s_lvl_3_q = Str2Int(data->s_lvl_3_q, sizeof(data->s_lvl_3_q));	// �ŵ�3�ܰ�켱ȣ���ܷ�
	out->s_lvl_4_prc = Str2Dbl(data->s_lvl_4_prc, sizeof(data->s_lvl_4_prc), 2);	// �ŵ�4�ܰ�켱ȣ������, ��) 999.99
	out->s_lvl_4_q = Str2Int(data->s_lvl_4_q, sizeof(data->s_lvl_4_q));	// �ŵ�4�ܰ�켱ȣ���ܷ�
	out->s_lvl_5_prc = Str2Int(data->s_lvl_5_prc, sizeof(data->s_lvl_5_prc));	// �ŵ�5�ܰ�켱ȣ������
	out->s_lvl_5_q = Str2Dbl(data->s_lvl_5_q, sizeof(data->s_lvl_5_q), 2);	// �ŵ�5�ܰ�켱ȣ���ܷ�, ��) 999.99
	out->total_l_trd_cnt = Str2Int(data->total_l_trd_cnt, sizeof(data->total_l_trd_cnt));	// �ż���ȿȣ���Ǽ�
	out->l_lvl_1_trd_cnt = Str2Int(data->l_lvl_1_trd_cnt, sizeof(data->l_lvl_1_trd_cnt));	// �ż�1�ܰ�켱ȣ���Ǽ�
	out->l_lvl_2_trd_cnt = Str2Int(data->l_lvl_2_trd_cnt, sizeof(data->l_lvl_2_trd_cnt));	// �ż�2�ܰ�켱ȣ���Ǽ�
	out->l_lvl_3_trd_cnt = Str2Dbl(data->l_lvl_3_trd_cnt, sizeof(data->l_lvl_3_trd_cnt), 2);	// �ż�3�ܰ�켱ȣ���Ǽ�, ��) 999.99
	out->l_lvl_4_trd_cnt = Str2Int(data->l_lvl_4_trd_cnt, sizeof(data->l_lvl_4_trd_cnt));	// �ż�4�ܰ�켱ȣ���Ǽ�
	out->l_lvl_5_trd_cnt = Str2Int(data->l_lvl_5_trd_cnt, sizeof(data->l_lvl_5_trd_cnt));	// �ż�5�ܰ�켱ȣ���Ǽ�
	out->total_s_trd_cnt = Str2Dbl(data->total_s_trd_cnt, sizeof(data->total_s_trd_cnt), 2);	// �ŵ���ȿȣ���Ǽ�, ��) 999.99
	out->s_lvl_1_trd_cnt = Str2Int(data->s_lvl_1_trd_cnt, sizeof(data->s_lvl_1_trd_cnt));	// �ŵ�1�ܰ�켱ȣ���Ǽ�
	out->s_lvl_2_trd_cnt = Str2Int(data->s_lvl_2_trd_cnt, sizeof(data->s_lvl_2_trd_cnt));	// �ŵ�2�ܰ�켱ȣ���Ǽ�
	out->s_lvl_3_trd_cnt = Str2Dbl(data->s_lvl_3_trd_cnt, sizeof(data->s_lvl_3_trd_cnt), 2);	// �ŵ�3�ܰ�켱ȣ���Ǽ�, ��) 999.99
	out->s_lvl_4_trd_cnt = Str2Int(data->s_lvl_4_trd_cnt, sizeof(data->s_lvl_4_trd_cnt));	// �ŵ�4�ܰ�켱ȣ���Ǽ�
	out->s_lvl_5_trd_cnt = Str2Int(data->s_lvl_5_trd_cnt, sizeof(data->s_lvl_5_trd_cnt));	// �ŵ�5�ܰ�켱ȣ���Ǽ�
	out->real_t_high_prc = Str2Dbl(data->real_t_high_prc, sizeof(data->real_t_high_prc), 2);	// �ǽð����Ѱ�, ��) 999.99 ���߰��̵�����
	out->real_t_low_prc = Str2Dbl(data->real_t_low_prc, sizeof(data->real_t_low_prc), 2);	// �ǽð����Ѱ�, ��) 999.99 ���߰��̵�����

	return 1;
}


// K200�ɼ�_���񸶰�
int ParseA6034(const double& timestamp, const char* in_buff, DF_K200_OPT_CLOSE_PRODUCT* out) {
	K200_OPT_CLOSE_PRODUCT* data = (K200_OPT_CLOSE_PRODUCT*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����, A6
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������, 03:KOSPI200�����ɼ�
	out->mrk_clsf = data->mrk_clsf[0];	//���屸��, 4
	memcpy(out->isin_clsf, data->isin_clsf, sizeof(data->isin_clsf));	// �����ڵ�
	out->stk_snr = Str2Int(data->stk_snr, sizeof(data->stk_snr));	// �����Ϸù�ȣ, �����Ϸù�ȣ �ڸ��� ����(3->4)
	memcpy(out->brd_id, data->brd_id, sizeof(data->brd_id));	// ����ID, �ڵ尪��������
	out->close_prc = Str2Dbl(data->close_prc, sizeof(data->close_prc), 2);	// ����, *�ŷ��� ������ ��� ���ذ� set, ��) 999.99
	out->close_prc_code = data->close_prc_code[0];	//���������ڵ�, 1:ü�ᰡ��, 3:�ŷ���\n 2:�⼼ -2012.05.14 ����\n ' ':�������� �ƴ� ��� space
	out->accm_exe_q = Str2Int(data->accm_exe_q, sizeof(data->accm_exe_q));	// ����ü�����
	out->accm_trd_amt = Str2Dbl(data->accm_trd_amt, sizeof(data->accm_trd_amt), 0);	// �����ŷ����, ����:õ��
	out->total_l_limit_ord_q = Str2Int(data->total_l_limit_ord_q, sizeof(data->total_l_limit_ord_q));	// �ż���ȣ���ܷ�
	out->l_lvl_1_prc = Str2Dbl(data->l_lvl_1_prc, sizeof(data->l_lvl_1_prc), 2);	// �ż�1�ܰ�켱ȣ������, ��) 999.99
	out->l_lvl_1_q = Str2Int(data->l_lvl_1_q, sizeof(data->l_lvl_1_q));	// �ż�1�ܰ�켱ȣ���ܷ�
	out->l_lvl_2_prc = Str2Dbl(data->l_lvl_2_prc, sizeof(data->l_lvl_2_prc), 2);	// �ż�2�ܰ�켱ȣ������, ��) 999.99
	out->l_lvl_2_q = Str2Int(data->l_lvl_2_q, sizeof(data->l_lvl_2_q));	// �ż�2�ܰ�켱ȣ���ܷ�
	out->l_lvl_3_prc = Str2Dbl(data->l_lvl_3_prc, sizeof(data->l_lvl_3_prc), 2);	// �ż�3�ܰ�켱ȣ������, ��) 999.99
	out->l_lvl_3_q = Str2Int(data->l_lvl_3_q, sizeof(data->l_lvl_3_q));	// �ż�3�ܰ�켱ȣ���ܷ�
	out->l_lvl_4_prc = Str2Dbl(data->l_lvl_4_prc, sizeof(data->l_lvl_4_prc), 2);	// �ż�4�ܰ�켱ȣ������, ��) 999.99
	out->l_lvl_4_q = Str2Int(data->l_lvl_4_q, sizeof(data->l_lvl_4_q));	// �ż�4�ܰ�켱ȣ���ܷ�
	out->l_lvl_5_prc = Str2Dbl(data->l_lvl_5_prc, sizeof(data->l_lvl_5_prc), 2);	// �ż�5�ܰ�켱ȣ������, ��) 999.99
	out->l_lvl_5_q = Str2Int(data->l_lvl_5_q, sizeof(data->l_lvl_5_q));	// �ż�5�ܰ�켱ȣ���ܷ�
	out->total_s_limit_ord_q = Str2Int(data->total_s_limit_ord_q, sizeof(data->total_s_limit_ord_q));	// �ŵ���ȣ���ܷ�
	out->s_lvl_1_prc = Str2Dbl(data->s_lvl_1_prc, sizeof(data->s_lvl_1_prc), 2);	// �ŵ�1�ܰ�켱ȣ������, ��) 999.99
	out->s_lvl_1_q = Str2Int(data->s_lvl_1_q, sizeof(data->s_lvl_1_q));	// �ŵ�1�ܰ�켱ȣ���ܷ�
	out->s_lvl_2_prc = Str2Dbl(data->s_lvl_2_prc, sizeof(data->s_lvl_2_prc), 2);	// �ŵ�2�ܰ�켱ȣ������, ��) 999.99
	out->s_lvl_2_q = Str2Int(data->s_lvl_2_q, sizeof(data->s_lvl_2_q));	// �ŵ�2�ܰ�켱ȣ���ܷ�
	out->s_lvl_3_prc = Str2Dbl(data->s_lvl_3_prc, sizeof(data->s_lvl_3_prc), 2);	// �ŵ�3�ܰ�켱ȣ������, ��) 999.99
	out->s_lvl_3_q = Str2Int(data->s_lvl_3_q, sizeof(data->s_lvl_3_q));	// �ŵ�3�ܰ�켱ȣ���ܷ�
	out->s_lvl_4_prc = Str2Dbl(data->s_lvl_4_prc, sizeof(data->s_lvl_4_prc), 2);	// �ŵ�4�ܰ�켱ȣ������, ��) 999.99
	out->s_lvl_4_q = Str2Int(data->s_lvl_4_q, sizeof(data->s_lvl_4_q));	// �ŵ�4�ܰ�켱ȣ���ܷ�
	out->s_lvl_5_prc = Str2Dbl(data->s_lvl_5_prc, sizeof(data->s_lvl_5_prc), 2);	// �ŵ�5�ܰ�켱ȣ������, ��) 999.99
	out->s_lvl_5_q = Str2Int(data->s_lvl_5_q, sizeof(data->s_lvl_5_q));	// �ŵ�5�ܰ�켱ȣ���ܷ�
	out->total_l_trd_cnt = Str2Int(data->total_l_trd_cnt, sizeof(data->total_l_trd_cnt));	// �ż���ȿȣ���Ǽ�
	out->l_lvl_1_trd_cnt = Str2Int(data->l_lvl_1_trd_cnt, sizeof(data->l_lvl_1_trd_cnt));	// �ż�1�ܰ�켱ȣ���Ǽ�
	out->l_lvl_2_trd_cnt = Str2Int(data->l_lvl_2_trd_cnt, sizeof(data->l_lvl_2_trd_cnt));	// �ż�2�ܰ�켱ȣ���Ǽ�
	out->l_lvl_3_trd_cnt = Str2Int(data->l_lvl_3_trd_cnt, sizeof(data->l_lvl_3_trd_cnt));	// �ż�3�ܰ�켱ȣ���Ǽ�
	out->l_lvl_4_trd_cnt = Str2Int(data->l_lvl_4_trd_cnt, sizeof(data->l_lvl_4_trd_cnt));	// �ż�4�ܰ�켱ȣ���Ǽ�
	out->l_lvl_5_trd_cnt = Str2Int(data->l_lvl_5_trd_cnt, sizeof(data->l_lvl_5_trd_cnt));	// �ż�5�ܰ�켱ȣ���Ǽ�
	out->total_s_trd_cnt = Str2Int(data->total_s_trd_cnt, sizeof(data->total_s_trd_cnt));	// �ŵ���ȿȣ���Ǽ�
	out->s_lvl_1_trd_cnt = Str2Int(data->s_lvl_1_trd_cnt, sizeof(data->s_lvl_1_trd_cnt));	// �ŵ�1�ܰ�켱ȣ���Ǽ�
	out->s_lvl_2_trd_cnt = Str2Int(data->s_lvl_2_trd_cnt, sizeof(data->s_lvl_2_trd_cnt));	// �ŵ�2�ܰ�켱ȣ���Ǽ�
	out->s_lvl_3_trd_cnt = Str2Int(data->s_lvl_3_trd_cnt, sizeof(data->s_lvl_3_trd_cnt));	// �ŵ�3�ܰ�켱ȣ���Ǽ�
	out->s_lvl_4_trd_cnt = Str2Int(data->s_lvl_4_trd_cnt, sizeof(data->s_lvl_4_trd_cnt));	// �ŵ�4�ܰ�켱ȣ���Ǽ�
	out->s_lvl_5_trd_cnt = Str2Int(data->s_lvl_5_trd_cnt, sizeof(data->s_lvl_5_trd_cnt));	// �ŵ�5�ܰ�켱ȣ���Ǽ�

	return 1;
}


// K200�ɼ�_��TS
int ParseA7034(const double& timestamp, const char* in_buff, DF_K200_OPT_MRK_OP_TS* out) {
	K200_OPT_MRK_OP_TS* data = (K200_OPT_MRK_OP_TS*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����, A7
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������, 03:KOSPI200�����ɼ�
	out->mrk_clsf = data->mrk_clsf[0];	//���屸��, 4
	memcpy(out->isin_clsf, data->isin_clsf, sizeof(data->isin_clsf));	// �����ڵ�
	out->stk_snr = Str2Int(data->stk_snr, sizeof(data->stk_snr));	// �����Ϸù�ȣ, �����Ϸù�ȣ �ڸ��� ����(3->4)
	memcpy(out->prd_id, data->prd_id, sizeof(data->prd_id));	// ��ǰID, �ڵ尪�������� : spaceó��
	memcpy(out->brd_id, data->brd_id, sizeof(data->brd_id));	// ����ID, �ڵ尪��������
	memcpy(out->brd_event_id, data->brd_event_id, sizeof(data->brd_event_id));	// �����̺�ƮID, �ڵ尪��������
	memcpy(out->brd_event_start_t, data->brd_event_start_t, sizeof(data->brd_event_start_t));	// �����̺�Ʈ���۽ð�, ������ �����(��:BB1(�ŸŰŷ�����)�� ��� 09000000)
	out->brd_event_code = Str2Int(data->brd_event_code, sizeof(data->brd_event_code));	// �����̺�Ʈ���뱺�ڵ�, �ڵ尪��������
	memcpy(out->ss_id, data->ss_id, sizeof(data->ss_id));	// ����ID, �ڵ尪��������
	out->ord_exist = data->ord_exist[0];	//ȣ������, 0:ȣ������(�����׸� ����), 1:ȣ������(�����׸� ���)
	out->total_l_limit_ord_q = Str2Int(data->total_l_limit_ord_q, sizeof(data->total_l_limit_ord_q));	// �ż���ȣ���ܷ�
	out->l_lvl_1_prc = Str2Dbl(data->l_lvl_1_prc, sizeof(data->l_lvl_1_prc), 2);	// �ż�1�ܰ�켱ȣ������, ��) 999.99
	out->l_lvl_1_q = Str2Int(data->l_lvl_1_q, sizeof(data->l_lvl_1_q));	// �ż�1�ܰ�켱ȣ���ܷ�
	out->l_lvl_2_prc = Str2Dbl(data->l_lvl_2_prc, sizeof(data->l_lvl_2_prc), 2);	// �ż�2�ܰ�켱ȣ������, ��) 999.99
	out->l_lvl_2_q = Str2Int(data->l_lvl_2_q, sizeof(data->l_lvl_2_q));	// �ż�2�ܰ�켱ȣ���ܷ�
	out->l_lvl_3_prc = Str2Dbl(data->l_lvl_3_prc, sizeof(data->l_lvl_3_prc), 2);	// �ż�3�ܰ�켱ȣ������, ��) 999.99
	out->l_lvl_3_q = Str2Int(data->l_lvl_3_q, sizeof(data->l_lvl_3_q));	// �ż�3�ܰ�켱ȣ���ܷ�
	out->l_lvl_4_prc = Str2Dbl(data->l_lvl_4_prc, sizeof(data->l_lvl_4_prc), 2);	// �ż�4�ܰ�켱ȣ������, ��) 999.99
	out->l_lvl_4_q = Str2Int(data->l_lvl_4_q, sizeof(data->l_lvl_4_q));	// �ż�4�ܰ�켱ȣ���ܷ�
	out->l_lvl_5_prc = Str2Dbl(data->l_lvl_5_prc, sizeof(data->l_lvl_5_prc), 2);	// �ż�5�ܰ�켱ȣ������, ��) 999.99
	out->l_lvl_5_q = Str2Int(data->l_lvl_5_q, sizeof(data->l_lvl_5_q));	// �ż�5�ܰ�켱ȣ���ܷ�
	out->total_s_limit_ord_q = Str2Int(data->total_s_limit_ord_q, sizeof(data->total_s_limit_ord_q));	// �ŵ���ȣ���ܷ�
	out->s_lvl_1_prc = Str2Dbl(data->s_lvl_1_prc, sizeof(data->s_lvl_1_prc), 2);	// �ŵ�1�ܰ�켱ȣ������, ��) 999.99
	out->s_lvl_1_q = Str2Int(data->s_lvl_1_q, sizeof(data->s_lvl_1_q));	// �ŵ�1�ܰ�켱ȣ���ܷ�
	out->s_lvl_2_prc = Str2Dbl(data->s_lvl_2_prc, sizeof(data->s_lvl_2_prc), 2);	// �ŵ�2�ܰ�켱ȣ������, ��) 999.99
	out->s_lvl_2_q = Str2Int(data->s_lvl_2_q, sizeof(data->s_lvl_2_q));	// �ŵ�2�ܰ�켱ȣ���ܷ�
	out->s_lvl_3_prc = Str2Dbl(data->s_lvl_3_prc, sizeof(data->s_lvl_3_prc), 2);	// �ŵ�3�ܰ�켱ȣ������, ��) 999.99
	out->s_lvl_3_q = Str2Int(data->s_lvl_3_q, sizeof(data->s_lvl_3_q));	// �ŵ�3�ܰ�켱ȣ���ܷ�
	out->s_lvl_4_prc = Str2Dbl(data->s_lvl_4_prc, sizeof(data->s_lvl_4_prc), 2);	// �ŵ�4�ܰ�켱ȣ������, ��) 999.99
	out->s_lvl_4_q = Str2Int(data->s_lvl_4_q, sizeof(data->s_lvl_4_q));	// �ŵ�4�ܰ�켱ȣ���ܷ�
	out->s_lvl_5_prc = Str2Dbl(data->s_lvl_5_prc, sizeof(data->s_lvl_5_prc), 2);	// �ŵ�5�ܰ�켱ȣ������, ��) 999.99
	out->s_lvl_5_q = Str2Int(data->s_lvl_5_q, sizeof(data->s_lvl_5_q));	// �ŵ�5�ܰ�켱ȣ���ܷ�
	out->total_l_trd_cnt = Str2Int(data->total_l_trd_cnt, sizeof(data->total_l_trd_cnt));	// �ż���ȿȣ���Ǽ�
	out->l_lvl_1_trd_cnt = Str2Int(data->l_lvl_1_trd_cnt, sizeof(data->l_lvl_1_trd_cnt));	// �ż�1�ܰ�켱ȣ���Ǽ�
	out->l_lvl_2_trd_cnt = Str2Int(data->l_lvl_2_trd_cnt, sizeof(data->l_lvl_2_trd_cnt));	// �ż�2�ܰ�켱ȣ���Ǽ�
	out->l_lvl_3_trd_cnt = Str2Int(data->l_lvl_3_trd_cnt, sizeof(data->l_lvl_3_trd_cnt));	// �ż�3�ܰ�켱ȣ���Ǽ�
	out->l_lvl_4_trd_cnt = Str2Int(data->l_lvl_4_trd_cnt, sizeof(data->l_lvl_4_trd_cnt));	// �ż�4�ܰ�켱ȣ���Ǽ�
	out->l_lvl_5_trd_cnt = Str2Int(data->l_lvl_5_trd_cnt, sizeof(data->l_lvl_5_trd_cnt));	// �ż�5�ܰ�켱ȣ���Ǽ�
	out->total_s_trd_cnt = Str2Int(data->total_s_trd_cnt, sizeof(data->total_s_trd_cnt));	// �ŵ���ȿȣ���Ǽ�
	out->s_lvl_1_trd_cnt = Str2Int(data->s_lvl_1_trd_cnt, sizeof(data->s_lvl_1_trd_cnt));	// �ŵ�1�ܰ�켱ȣ���Ǽ�
	out->s_lvl_2_trd_cnt = Str2Int(data->s_lvl_2_trd_cnt, sizeof(data->s_lvl_2_trd_cnt));	// �ŵ�2�ܰ�켱ȣ���Ǽ�
	out->s_lvl_3_trd_cnt = Str2Int(data->s_lvl_3_trd_cnt, sizeof(data->s_lvl_3_trd_cnt));	// �ŵ�3�ܰ�켱ȣ���Ǽ�
	out->s_lvl_4_trd_cnt = Str2Int(data->s_lvl_4_trd_cnt, sizeof(data->s_lvl_4_trd_cnt));	// �ŵ�4�ܰ�켱ȣ���Ǽ�
	out->s_lvl_5_trd_cnt = Str2Int(data->s_lvl_5_trd_cnt, sizeof(data->s_lvl_5_trd_cnt));	// �ŵ�5�ܰ�켱ȣ���Ǽ�
	out->real_t_high_prc = Str2Dbl(data->real_t_high_prc, sizeof(data->real_t_high_prc), 2);	// �ǽð����Ѱ�, ��) 999.99 ���߰��̵�����
	out->real_t_low_prc = Str2Dbl(data->real_t_low_prc, sizeof(data->real_t_low_prc), 2);	// �ǽð����Ѱ�, ��) 999.99 ���߰��̵�����

	return 1;
}


// K200�ɼ�_����
int ParseH0034(const double& timestamp, const char* in_buff, DF_K200_OPT_CLOSE* out) {
	K200_OPT_CLOSE* data = (K200_OPT_CLOSE*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����, H0
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������, 03:KOSPI200�����ɼ�
	out->mrk_clsf = data->mrk_clsf[0];	//���屸��, 4

	return 1;
}


// K200�ɼ�_�������ٰ���
int ParseM4034(const double& timestamp, const char* in_buff, DF_K200_OPT_MRK_OP_SCHD* out) {
	K200_OPT_MRK_OP_SCHD* data = (K200_OPT_MRK_OP_SCHD*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����, M4
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������, 03:KOSPI200�����ɼ�
	out->mrk_clsf = data->mrk_clsf[0];	//���屸��, 4
	memcpy(out->isin_clsf, data->isin_clsf, sizeof(data->isin_clsf));	// �����ڵ�, �������� ����ġ�� ���
	out->stk_snr = Str2Int(data->stk_snr, sizeof(data->stk_snr));	// �����Ϸù�ȣ, �����Ϸù�ȣ �ڸ��� ����(3->4)
	memcpy(out->prd_id, data->prd_id, sizeof(data->prd_id));	// ��ǰID, �ڵ尪�������� : spaceó��
	memcpy(out->mrk_prd_id, data->mrk_prd_id, sizeof(data->mrk_prd_id));	// ����ǰ�׷�ID, OKI : K200�ɼ�
	memcpy(out->brd_id, data->brd_id, sizeof(data->brd_id));	// ����ID, �ڵ尪��������
	memcpy(out->brd_event_id, data->brd_event_id, sizeof(data->brd_event_id));	// �����̺�ƮID, �ڵ尪��������
	memcpy(out->brd_event_start_t, data->brd_event_start_t, sizeof(data->brd_event_start_t));	// �����̺�Ʈ���۽ð�
	out->brd_event_code = Str2Int(data->brd_event_code, sizeof(data->brd_event_code));	// �����̺�Ʈ���뱺�ڵ�, �ڵ尪��������
	memcpy(out->ss_open_close_code, data->ss_open_close_code, sizeof(data->ss_open_close_code));	// ���ǰ��������ڵ�, BS:���尳��\n BE:��������\n SS:���ǰ���\n SE:��������\n SH:��������\n SR:�����簳
	memcpy(out->ss_id, data->ss_id, sizeof(data->ss_id));	// ����ID, �ڵ尪��������
	out->adj_stage = Str2Int(data->adj_stage, sizeof(data->adj_stage));	// ����ܰ�, CB �� ���������� Ȯ��� ����Ǵ� �ܰ� \n��)�ʱⰪ 00
	out->under_asset_prc_chg = data->under_asset_prc_chg[0];	//�������񰡰�Ȯ��߻��ڵ�, ���������� ����Ȯ��� �����ڵ�(U:���, D:�϶�)
	memcpy(out->exp_prc_chg_t, data->exp_prc_chg_t, sizeof(data->exp_prc_chg_t));	// ����Ȯ�뿹���ð�, �Ļ����尡��Ȯ�� ���� �̺�Ʈ �߻��� ���Ǵ� �׸����� ����Ȯ�뿹���ð��� ��ϵ�

	return 1;
}


// K200�ɼ�_�������
int ParseO6034(const double& timestamp, const char* in_buff, DF_K200_OPT_DIST_INFO* out) {
	K200_OPT_DIST_INFO* data = (K200_OPT_DIST_INFO*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����, O6
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������, 03:KOSPI200�����ɼ�
	out->mrk_clsf = data->mrk_clsf[0];	//���屸��, 4
	memcpy(out->isin_clsf, data->isin_clsf, sizeof(data->isin_clsf));	// �����ڵ�
	out->stk_snr = Str2Int(data->stk_snr, sizeof(data->stk_snr));	// �����Ϸù�ȣ, �����Ϸù�ȣ �ڸ��� ����(3->4)
	memcpy(out->brd_id, data->brd_id, sizeof(data->brd_id));	// ����ID, �ڵ尪��������
	out->dist_adj_code = data->dist_adj_code[0];	//������뱸���ڵ�, 1:��а���, 2:�������
	out->dist_code = data->dist_code[0];	//���ó�������ڵ�, 1:�ż�����, 2:�ż�����,\n 3:�ŵ�����, 4:�ŵ�����\n *��������� �ڵ����(spaceó��)
	memcpy(out->dist_cls_t, data->dist_cls_t, sizeof(data->dist_cls_t));	// ��������ð�

	return 1;
}


// K200�ɼ�_�ǽð������Ѱ� ���������
int ParseQ2034(const double& timestamp, const char* in_buff, DF_K200_OPT_REAL_HIGH_LOW_LIMIT_ON_OFF* out) {
	K200_OPT_REAL_HIGH_LOW_LIMIT_ON_OFF* data = (K200_OPT_REAL_HIGH_LOW_LIMIT_ON_OFF*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����, Q2
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������, 03:KOSPI200�����ɼ�
	out->mrk_clsf = data->mrk_clsf[0];	//���屸��, 4
	memcpy(out->isin_clsf, data->isin_clsf, sizeof(data->isin_clsf));	// �����ڵ�
	out->stk_snr = Str2Int(data->stk_snr, sizeof(data->stk_snr));	// �����Ϸù�ȣ, �����Ϸù�ȣ �ڸ��� ����(3->4)
	memcpy(out->brd_id, data->brd_id, sizeof(data->brd_id));	// ����ID, �ڵ尪��������
	memcpy(out->cleared_t, data->cleared_t, sizeof(data->cleared_t));	// ó���ð�
	out->real_t_prc_limit_code = data->real_t_prc_limit_code[0];	//�ǽð��������Ѽ����ڵ�, 0: ����, 1: ����, 2: �缳��
	out->real_t_high_prc = Str2Dbl(data->real_t_high_prc, sizeof(data->real_t_high_prc), 2);	// �ǽð����Ѱ�, ��)999.99 ���߰��̵�����
	out->real_t_low_prc = Str2Dbl(data->real_t_low_prc, sizeof(data->real_t_low_prc), 2);	// �ǽð����Ѱ�, ��)999.99 ���߰��̵�����

	return 1;
}


// K200�ɼ�_����������Ȯ��ߵ�
int ParseV1034(const double& timestamp, const char* in_buff, DF_K200_OPT_PRC_LIMIT_ON* out) {
	K200_OPT_PRC_LIMIT_ON* data = (K200_OPT_PRC_LIMIT_ON*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����, V1
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������, 03:KOSPI200�����ɼ�
	out->mrk_clsf = data->mrk_clsf[0];	//���屸��, 4
	memcpy(out->code_clsf, data->code_clsf, sizeof(data->code_clsf));	// �����ڵ�
	out->stk_snr = Str2Int(data->stk_snr, sizeof(data->stk_snr));	// �����Ϸù�ȣ, �����Ϸù�ȣ �ڸ��� ����(3->4)
	memcpy(out->prd_id, data->prd_id, sizeof(data->prd_id));	// ��ǰID, �ڵ尪�������� : spaceó��
	memcpy(out->brd_id, data->brd_id, sizeof(data->brd_id));	// ����ID, �ڵ尪��������
	memcpy(out->prc_limit_start_t, data->prc_limit_start_t, sizeof(data->prc_limit_start_t));	// ����Ȯ��ð�, ������ Ȯ��� �ð�
	out->prc_limit_high = Str2Int(data->prc_limit_high, sizeof(data->prc_limit_high));	// ��������Ȯ����Ѵܰ�, ����� ���Ѵܰ�
	out->prc_limit_low = Str2Int(data->prc_limit_low, sizeof(data->prc_limit_low));	// ��������Ȯ�����Ѵܰ�, ����� ���Ѵܰ�
	out->high_prc = Str2Dbl(data->high_prc, sizeof(data->high_prc), 2);	// ���Ѱ�, ����� ���Ѱ�\n��)999.99
	out->low_prc = Str2Dbl(data->low_prc, sizeof(data->low_prc), 2);	// ���Ѱ�, ����� ���Ѱ�\n��)999.99

	return 1;
}


// K200�ɼ�_SPACE
int ParseG9034(const double& timestamp, const char* in_buff, DF_K200_OPT_SPACE* out) {
	K200_OPT_SPACE* data = (K200_OPT_SPACE*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����, G9
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������, 03:KOSPI200�����ɼ�
	out->mrk_clsf = data->mrk_clsf[0];	//���屸��, 4

	return 1;
}


// K200�ɼ�_�̰����������� ������
int ParseH2034(const double& timestamp, const char* in_buff, DF_K200_OPT_OPEN_INTEREST_DATA* out) {
	K200_OPT_OPEN_INTEREST_DATA* data = (K200_OPT_OPEN_INTEREST_DATA*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����, H2
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������, 03:KOSPI200�����ɼ�
	out->mrk_clsf = data->mrk_clsf[0];	//���屸��, 4
	memcpy(out->isin_clsf, data->isin_clsf, sizeof(data->isin_clsf));	// �����ڵ�, ���� record '999999999999' set
	out->stk_snr = Str2Int(data->stk_snr, sizeof(data->stk_snr));	// ����SEQ, ����SEQ �ڸ��� ����(3->4)
	memcpy(out->open_interest_clsf, data->open_interest_clsf, sizeof(data->open_interest_clsf));	// �̰�����������, ���� Ȯ�� : "M0" (07:40�а� ����)\n���� ���� : "M1" (���� Ư���������� ��������\n		 �۽�, 10��)\n���� Ȯ�� : "M2" (���� ������ �۽�,\n		 ������ 1�ð��� ����)\n*�������� ù��° �����ʹ� �尳�������ǰŷ��� ����
	memcpy(out->traded_date, data->traded_date, sizeof(data->traded_date));	// �ŷ�����
	out->open_interest_q = Str2Int(data->open_interest_q, sizeof(data->open_interest_q));	// �̰�����������, ����:���

	return 1;
}


// K200�ɼ�_�Ÿ����űݱ��ذ� ������
int ParseH3034(const double& timestamp, const char* in_buff, DF_K200_OPT_TRD_MRG_STD_PRC_DATA* out) {
	K200_OPT_TRD_MRG_STD_PRC_DATA* data = (K200_OPT_TRD_MRG_STD_PRC_DATA*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����, H3
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������, 03:KOSPI200�����ɼ�
	out->mrk_clsf = data->mrk_clsf[0];	//���屸��, 4
	memcpy(out->isin_clsf, data->isin_clsf, sizeof(data->isin_clsf));	// �����ڵ�, ���� record '999999999999' set
	out->stk_snr = Str2Int(data->stk_snr, sizeof(data->stk_snr));	// ����SEQ, ����SEQ �ڸ��� ����(3->4)
	out->trd_mrg_std_prc = Str2Dbl(data->trd_mrg_std_prc, sizeof(data->trd_mrg_std_prc), 8);	// �Ÿ����űݱ��ذ�, ��) 99999999.99999999
	out->trd_mrg_std_prc_clsf = data->trd_mrg_std_prc_clsf[0];	//�Ÿ����űݱ��ذ�����, 0 : ���ű� ���ذ� ����(���� �ŷ������� �⼼ ����)\n1 : ���� ����(�Ǽ�)\n2 : ���� �⼼(���� �ŷ������� �⼼)\n -2012.05.14 ����\n3 : ���� ���ű� ���ذ�(�ŷ������� ���� ������)\n -2012.05.14 ����\n4 : ���� �̷а�(�ŷ������� ���� ������)\n5 : �����������űݱ��ذ�(�ŷ������� ���� ������)\n -2012.05.14 ����
	out->opt_exec_right_set_prc = Str2Dbl(data->opt_exec_right_set_prc, sizeof(data->opt_exec_right_set_prc), 8);	// �ɼǱǸ�����������, ��) 99999999.99999999
	out->opt_exec_right_set_prc_clsf = data->opt_exec_right_set_prc_clsf[0];	//�ɼǱǸ����������ݱ���

	return 1;
}


// K200�ɼ�_�������� ������
int ParseA0034(const double& timestamp, const char* in_buff, DF_K200_OPT_PRD_INFO_DATA* out) {
	K200_OPT_PRD_INFO_DATA* data = (K200_OPT_PRD_INFO_DATA*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����, AO
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������, 03:KOSPI200�����ɼ�
	out->mrk_clsf = data->mrk_clsf[0];	//���屸��, 4
	out->prd_cnt = Str2Int(data->prd_cnt, sizeof(data->prd_cnt));	// �����
	memcpy(out->trd_date, data->trd_date, sizeof(data->trd_date));	// ��������(��ȸ����)
	memcpy(out->isin_clsf, data->isin_clsf, sizeof(data->isin_clsf));	// �����ڵ�, ���� record '999999999999' set
	out->stk_snr = Str2Int(data->stk_snr, sizeof(data->stk_snr));	// ����SEQ
	memcpy(out->prd_id, data->prd_id, sizeof(data->prd_id));	// ��ǰID, * �ڵ尪 ������ ����* ����Ī: �Ļ���ǰID10 => 11, 20140303
	memcpy(out->sh_prd_code, data->sh_prd_code, sizeof(data->sh_prd_code));	// ��������ڵ�, ��) KR4101C90009 �� K101C9000
	memcpy(out->prd_name_kor, data->prd_name_kor, sizeof(data->prd_name_kor));	// �����ѱ۸�
	memcpy(out->sh_prd_name_kor, data->sh_prd_name_kor, sizeof(data->sh_prd_name_kor));	// �����ѱ۾��
	memcpy(out->prd_name_eng, data->prd_name_eng, sizeof(data->prd_name_eng));	// ���񿵹���
	memcpy(out->sh_prd_name_eng, data->sh_prd_name_eng, sizeof(data->sh_prd_name_eng));	// ���񿵹����
	memcpy(out->listing_date, data->listing_date, sizeof(data->listing_date));	// ��������
	memcpy(out->de_listing_date, data->de_listing_date, sizeof(data->de_listing_date));	// ������������
	out->spread_clsf_code = data->spread_clsf_code[0];	//��������������񱸺��ڵ�, ���������� ������ �Ǵ� ������ ISIN ǥ���ڵ�--�ڵ尪--F: ������(�ð���������)N: �ٿ���(�ð���������)20140303
	out->final_sett_code = data->final_sett_code[0];	//������������ڵ�, ���ݰ���, �ǹ��μ������� �� �Ļ���ǰ�� �������� ���--�ڵ尪--C: ���ݰ���D: �ǹ��μ�������A: ����+�ǹ��μ�������0: �ش����\n20140303
	out->prc_limit_exp_dir = data->prc_limit_exp_dir[0];	//��������Ȯ����������ڵ�, ���������� �ٴܰ�� ���ǵǴ� ��� ���� �ܰ�� Ȯ��Ǵ� ����� ������ �� Ȯ�븦 �����ϴ� ����## �ڵ尪##X:������F:������B:������T:�����
	out->prc_limit_final_stg = Str2Int(data->prc_limit_final_stg, sizeof(data->prc_limit_final_stg));	// �������������ܰ�, ���������� �ٴܰ�� ���ǵǴ� ��� ������ �����ܰ��ȣ
	out->prc_limit_stg_1_high_prc = Str2SignDouble(data->prc_limit_stg_1_hgh_sign, sizeof(data->prc_limit_stg_1_hgh_sign) + sizeof(data->prc_limit_stg_1_high_prc), 2);	// ��������1�ܰ���Ѱ�, ��) 9999999999.99
	out->prc_limit_stg_1_low_prc = Str2SignDouble(data->prc_limit_stg_1_low_sign, sizeof(data->prc_limit_stg_1_low_sign) + sizeof(data->prc_limit_stg_1_low_prc), 2);	// ��������1�ܰ����Ѱ�, ��) 9999999999.99
	out->prc_limit_stg_2_high_prc = Str2SignDouble(data->prc_limit_stg_2_high_sign, sizeof(data->prc_limit_stg_2_high_sign) + sizeof(data->prc_limit_stg_2_high_prc), 2);	// ��������2�ܰ���Ѱ�, ��) 9999999999.99
	out->prc_limit_stg_2_low_prc = Str2SignDouble(data->prc_limit_stg_2_low_sign, sizeof(data->prc_limit_stg_2_low_sign) + sizeof(data->prc_limit_stg_2_low_prc), 2);	// ��������2�ܰ����Ѱ�, ��) 9999999999.99
	out->prc_limit_stg_3_high_prc = Str2SignDouble(data->prc_limit_stg_3_high_sign, sizeof(data->prc_limit_stg_3_high_sign) + sizeof(data->prc_limit_stg_3_high_prc), 2);	// ��������3�ܰ���Ѱ�, ��) 9999999999.99
	out->prc_limit_stg_3_low_prc = Str2SignDouble(data->prc_limit_stg_3_low_sign, sizeof(data->prc_limit_stg_3_low_sign) + sizeof(data->prc_limit_stg_3_low_prc), 2);	// ��������3�ܰ����Ѱ�, ��) 9999999999.99
	out->stand_prc = Str2Dbl(data->stand_prc, sizeof(data->stand_prc), 2);	// ���ذ�, ��) 9999999999.99
	memcpy(out->under_asset_id, data->under_asset_id, sizeof(data->under_asset_id));	// �����ڻ�ID, ��) K2I:KOSPI200����, KQI:�ڽ���150, Sxx:�����ֽ�, BM3:��3�ⱹä, BM5:��5�ⱹä, BMA:��10�ⱹä, CDR:CD, USD:�̱��޷�, JPY:�Ϻ���, EUR:��������, GLD:��, LHG:����20140303
	out->opt_type_code = data->opt_type_code[0];	//�Ǹ���������ڵ�, A:�̱���,E:������,Z:��Ÿ
	memcpy(out->spread_str_code, data->spread_str_code, sizeof(data->spread_str_code));	// �������屸���ڵ�, Combination ȣ���� ��ü�� �������幰�� ���񱸼�.--�ڵ尪--- T1: �ֱٿ���+2°����	  > T2, T3, T4, ...\n*����Ī: �������������ڵ�20140303
	memcpy(out->spread_prd_code_1, data->spread_prd_code_1, sizeof(data->spread_prd_code_1));	// �������屸�������ڵ�1, * ����Ī: ��������ٿ��� �����ڵ�ٿ��� ǥ���ڵ�20140303
	memcpy(out->spread_prd_code_2, data->spread_prd_code_2, sizeof(data->spread_prd_code_2));	// �������屸�������ڵ�2, * ����Ī: ��������ٿ��� �����ڵ�ٿ��� ǥ���ڵ�20140303
	memcpy(out->last_trading_date, data->last_trading_date, sizeof(data->last_trading_date));	// �����ŷ�����
	memcpy(out->final_sett_date, data->final_sett_date, sizeof(data->final_sett_date));	// ������������
	out->cont_month_nbr = Str2Int(data->cont_month_nbr, sizeof(data->cont_month_nbr));	// ��������ȣ, * ����Ī: ���������ڵ�1:�ֱٿ���,������������2:2°����3:3°����4:4°����5:5°����6:6°����7:7°����	  �� �ֱٿ������� ��ġ\nX => 9, 1 => 3, 20140303
	memcpy(out->maturity_date, data->maturity_date, sizeof(data->maturity_date));	// ��������, �Ǹ���� ������ ��������
	out->exe_prc = Str2Dbl(data->exe_prc, sizeof(data->exe_prc), 8);	// ��簡��, ��) 999999999.99999999
	out->adjust_clsf_code = data->adjust_clsf_code[0];	//���������ڵ�, �����ڻ��� ���ذ��� ������ ����� ����(�̰�������)���� ������� ����(�ŷ��¼�����)������ ����--�ڵ尪--N: ����O: �̰�������\nC: �ŷ��¼�����20140303
	out->prd_unit = Str2Dbl(data->prd_unit, sizeof(data->prd_unit), 8);	// �ŷ�����, 1��࿡ �ش��ϴ� �����ڻ������) 999999999.99999999=> Exture������ 1�̾�����, Exture+������ 500000��\n20140303
	out->multiplier = Str2Dbl(data->multiplier, sizeof(data->multiplier), 8);	// �ŷ��¼�, ������� �� ������ ����ϴ� ���¼���) 9999999999999.99999999
	out->mrk_cnst_code = data->mrk_cnst_code[0];	//�������������ڵ�, 0:�̽�����������1:���Ͻ�����������2:���Ž�����������
	out->listing_type_code = data->listing_type_code[0];	//���������ڵ�, 1:�űԻ���2:�߰�����3:��������4:���ʻ���5:��������6:Ư������
	out->atm_prc = Str2Dbl(data->atm_prc, sizeof(data->atm_prc), 2);	// ���, �����ڻ���ذ��ݿ� ���� ����� ��簡�ݿ�) 9999999999.99
	memcpy(out->adj_reason_code, data->adj_reason_code, sizeof(data->adj_reason_code));	// ���������ڵ�, 00:�ش���׾���, 01:�Ǹ���, 02:����,03:�й��, 04:�ǹ��, 05:�߰�����,06:�Ǹ��߰�����, 99:��Ÿ
	memcpy(out->under_asset_prd_code, data->under_asset_prd_code, sizeof(data->under_asset_prd_code));	// �����ڻ������ڵ�
	out->under_asset_close_prc = Str2Dbl(data->under_asset_close_prc, sizeof(data->under_asset_close_prc), 2);	// �����ڻ�����, ��) 9999999999.99
	out->left_until_maturity = Str2Int(data->left_until_maturity, sizeof(data->left_until_maturity));	// �����ϼ�
	out->adj_std_prc = Str2Dbl(data->adj_std_prc, sizeof(data->adj_std_prc), 8);	// �������ذ���, �ֽ��Ļ���ǰ�� �����ֱ� �������ذ��ݿ�) 999999999.99999999
	memcpy(out->std_prc_clsf_code, data->std_prc_clsf_code, sizeof(data->std_prc_clsf_code));	// ���ذ��ݱ����ڵ�, *����spcace:���ذ� ����(���� ������������)11:�������갡12:���ϱ��ذ�(�ŷ������� ����������)13:�����̷а�(�ŷ������� ����������)\n14:���ϱ⼼(�ŷ������� �⼼����)  -2012.05.14 ����15:�����̷а�(�ŷ������� �⼼����)-  -2012.05.14 ����\n16:������ �������갡17:������ ���ϱ��ذ�  (�ŷ������� ����������)18:������ ���ϱ⼼(�ŷ������� �⼼����)  -2012.05.14 ����\n19:���� ����ڻ� ����(�̷а����� ��ǰ)*�ɼ�21:�������űݱ��ذ�22:���ϱ��ذ�(�ŷ������� ����������)23:�����̷а�(�ŷ������� ����������)\n24:���ϱ⼼(�ŷ������� �⼼����)  -2012.05.14 ����25:������ �������űݱ��ذ�26:������ ���ϱ��ذ�  (�ŷ������� ����������)\n27:������ ���ϱ⼼(�ŷ������� �⼼����)  -2012.05.14 ����
	out->trd_std_prc_clsf_code = data->trd_std_prc_clsf_code[0];	//�Ÿſ���ذ��ݱ����ڵ�, 0:�ش����1:�Ǽ�2:�⼼3:�̷а�4:����ڻ�����
	out->yest_adj_close_prc = Str2SignDouble(data->yest_adj_close_prc_sign, sizeof(data->yest_adj_close_prc_sign) + sizeof(data->yest_adj_close_prc), 8);	// ������������, �ֽ��Ļ���ǰ�� ����������) 999999999.99999999
	out->block_trd_clsf = data->block_trd_clsf[0];	//���Ǵ뷮�ŸŴ�󿩺�, Y:���ǸŸŻ�ǰ, N:���ƴ԰���ǰ��:3�⹰��ä����, �̱��޷�����,	  ���μ���, ������
	out->yest_mrg_std_prc = Str2Dbl(data->yest_mrg_std_prc, sizeof(data->yest_mrg_std_prc), 8);	// �������űݱ��ذ���, ��) 999999999.99999999
	memcpy(out->yest_mrg_std_prc_clsf_code, data->yest_mrg_std_prc_clsf_code, sizeof(data->yest_mrg_std_prc_clsf_code));	// �������űݱ��ذ��ݱ����ڵ�, *�ɼ�20:���ű� ���ذ� ����21:��������(�Ǽ�)22:���ϱ⼼(�ŷ������ı⼼)  -2012.05.14 ����23:�������űݱ��ذ�\n  (�ŷ������� ����������)  -2012.05.14 ����24:�����̷а�(�ŷ������� ����������)25:�����������űݱ��ذ�  (�ŷ������� ����������)\n  -2012.05.14 ����
	out->sett_theory_prc = Str2Dbl(data->sett_theory_prc, sizeof(data->sett_theory_prc), 6);	// �����̷а���, �ؿɼ��� ��� ���űݱ��ذ��� ��) 999999999.999999
	out->std_theory_prc = Str2Dbl(data->std_theory_prc, sizeof(data->std_theory_prc), 6);	// �����̷а���, ��) 999999999.999999
	out->yest_sett_prc = Str2Dbl(data->yest_sett_prc, sizeof(data->yest_sett_prc), 8);	// �������갡��, ��) 999999999.99999999
	out->halt_trd_clsf = data->halt_trd_clsf[0];	//�ŷ���������, Y, N
	out->ft_cb_high_prc = Str2Dbl(data->ft_cb_high_prc, sizeof(data->ft_cb_high_prc), 2);	// ����Circuit_Breakers���Ѱ�, ���� CB �ߵ������� �Ǵ��ϱ� ���� ���Ѱ���(���ذ���� +/-5%�� CB �ߵ������� ��� +5%�� ����� ����)��) 9999999999.99
	out->ft_cb_low_prc = Str2Dbl(data->ft_cb_low_prc, sizeof(data->ft_cb_low_prc), 2);	// ����Circuit_Breakers���Ѱ�, ���� CB �ߵ������� �Ǵ��ϱ� ���� ���Ѱ���(���ذ���� +/-5%�� CB �ߵ������� ��� -5%�� ����� ����)��) 9999999999.99
	out->check_exe_prc = Str2Dbl(data->check_exe_prc, sizeof(data->check_exe_prc), 8);	// ��ȸ����簡��, ��) 999999999.99999999
	out->atm_clsf = data->atm_clsf[0];	//ATM�����ڵ�, 0:����, 1:ATM, 2:ITM, 3:OTM
	out->last_trading_clsf = data->last_trading_clsf[0];	//�����ŷ��Ͽ���, Y, N
	out->ex_divid_aft_value = Str2Dbl(data->ex_divid_aft_value, sizeof(data->ex_divid_aft_value), 6);	// �����Ĺ�簡ġ, �ֽ� �� �ְ����� ��ǰ���� �����- ���� : �����Ĺ̷���ġ- �ɼ� : ���������簡ġ��) 999999999.999999
	out->yest_close_prc = Str2SignDouble(data->yest_close_prc_sign, sizeof(data->yest_close_prc_sign) + sizeof(data->yest_close_prc), 2);	// ��������, ��) 9999999999.99
	out->yest_close_prc_clsf = data->yest_close_prc_clsf[0];	//�������������ڵ�, 1:�Ǽ�, 3:�ŷ���2:�⼼ -2012.05.14 ����
	out->yest_init_prc = Str2SignDouble(data->yest_init_prc_sign, sizeof(data->yest_init_prc_sign) + sizeof(data->yest_init_prc), 2);	// ���Ͻð�, ��) 9999999999.99
	out->yest_high_pric = Str2SignDouble(data->yest_high_prc_sign, sizeof(data->yest_high_prc_sign) + sizeof(data->yest_high_pric), 2);	// ���ϰ�, ��) 9999999999.99
	out->yest_low_prc = Str2SignDouble(data->yest_low_prc_sign, sizeof(data->yest_low_prc_sign) + sizeof(data->yest_low_prc), 2);	// ��������, ��) 9999999999.99
	memcpy(out->yest_first_exe_date, data->yest_first_exe_date, sizeof(data->yest_first_exe_date));	// ����ü������
	memcpy(out->yest_last_exe_time, data->yest_last_exe_time, sizeof(data->yest_last_exe_time));	// ��������ü��ð�
	memcpy(out->yest_sett_prc_clsf, data->yest_sett_prc_clsf, sizeof(data->yest_sett_prc_clsf));	// �������갡�ݱ����ڵ�, *���� 10:���갡���� 11:��������(�Ǽ�) 12:���ϱ⼼(�ŷ������ı⼼) 13:�������갡(�ŷ������� ����������)\n 14:�����̷а�(�ŷ������� ����������) 15:��������� ���� 16:������ ���� ���갡 17:����ڻ� ����(�̷а����� ��ǰ)
	out->sett_prc_theory_prc_diff_pctg = Str2SignDouble(data->sett_prc_theory_prc_diff_pctg_sign, sizeof(data->sett_prc_theory_prc_diff_pctg_sign) + sizeof(data->sett_prc_theory_prc_diff_pctg), 6);	// ���갡���̷а��ݱ�����, ��) 999999.999999
	out->yest_open_interest_q = Str2Dbl(data->yest_open_interest_q, sizeof(data->yest_open_interest_q), 0);	// ���Ϲ̰�����������
	out->yest_s_limit_ord_prc = Str2SignDouble(data->yest_s_limit_ord_prc_sign, sizeof(data->yest_s_limit_ord_prc_sign) + sizeof(data->yest_s_limit_ord_prc), 2);	// ���ϸŵ��켱ȣ������, ��) 9999999999.99
	out->yest_l_limit_ord_prc = Str2SignDouble(data->yest_l_limit_ord_prc_sign, sizeof(data->yest_l_limit_ord_prc_sign) + sizeof(data->yest_l_limit_ord_prc), 2);	// ���ϸż��켱ȣ������, ��) 9999999999.99
	out->implied_vol = Str2Dbl(data->implied_vol, sizeof(data->implied_vol), 4);	// ���纯����, ��) 999999.9999
	out->listed_high_prc = Str2SignDouble(data->listed_high_prc_sign, sizeof(data->listed_high_prc_sign) + sizeof(data->listed_high_prc), 2);	// �������ְ�, ��) 9999999999.99
	out->listed_low_prc = Str2SignDouble(data->listed_low_prc_sign, sizeof(data->listed_low_prc_sign) + sizeof(data->listed_low_prc), 2);	// ������������, ��) 9999999999.99
	out->year_high_prc = Str2SignDouble(data->year_high_prc_sign, sizeof(data->year_high_prc_sign) + sizeof(data->year_high_prc), 2);	// �����ְ�, ��) 9999999999.99
	out->year_low_prc = Str2SignDouble(data->year_low_prc_sign, sizeof(data->year_low_prc_sign) + sizeof(data->year_low_prc), 2);	// ����������, ��) 9999999999.99
	memcpy(out->listed_high_prc_date, data->listed_high_prc_date, sizeof(data->listed_high_prc_date));	// �������ְ�����
	memcpy(out->listed_low_prc_date, data->listed_low_prc_date, sizeof(data->listed_low_prc_date));	// ����������������
	memcpy(out->year_high_prc_date, data->year_high_prc_date, sizeof(data->year_high_prc_date));	// �����ְ�����
	memcpy(out->year_low_prc_date, data->year_low_prc_date, sizeof(data->year_low_prc_date));	// ��������������
	out->year_std_date = Str2Int(data->year_std_date, sizeof(data->year_std_date));	// ���������ϼ�
	out->month_trd_date = Str2Int(data->month_trd_date, sizeof(data->month_trd_date));	// �����ŷ��ϼ�
	out->year_trd_date = Str2Int(data->year_trd_date, sizeof(data->year_trd_date));	// �����ŷ��ϼ�
	out->yest_exe_trd_cnt  = Str2Dbl(data->yest_exe_trd_cnt , sizeof(data->yest_exe_trd_cnt ), 0);	// ����ü��Ǽ�
	out->yest_exe_q = Str2Dbl(data->yest_exe_q, sizeof(data->yest_exe_q), 0);	// ����ü�����, �������Ǵ뷮�Ÿ�ü������� ���Ե��� ����
	out->yest_trd_amt = Str2Dbl(data->yest_trd_amt, sizeof(data->yest_trd_amt), 0);	// ���ϰŷ����, �������Ǵ뷮�ŸŰŷ������ ���Ե��� ����
	out->yest_block_trd_exe_q = Str2Dbl(data->yest_block_trd_exe_q, sizeof(data->yest_block_trd_exe_q), 0);	// �������Ǵ뷮�ջ�ü�����, �������Ǵ뷮�Ÿ�ü����� => �������Ǵ뷮�ջ�ü����� [����ü�����+�������Ǵ뷮�Ÿ�ü�����(���Ǵ뷮+FLEX)];\n 2016.03.28 ����
	out->yest_block_trd_total_amt = Str2Dbl(data->yest_block_trd_total_amt, sizeof(data->yest_block_trd_total_amt), 0);	// �������Ǵ뷮�ջ�ŷ����, �������Ǵ뷮�ŸŰŷ���� => �������Ǵ뷮�ջ�ŷ���� [���ϰŷ����+�������Ǵ뷮�ŸŰŷ����(���Ǵ뷮+FLEX)]; 2016.03.28 ����
	out->cd_rate = Str2Dbl(data->cd_rate, sizeof(data->cd_rate), 3);	// CD�ݸ�, ��) 999.999
	out->open_interest_q = Str2Dbl(data->open_interest_q, sizeof(data->open_interest_q), 0);	// �̰����ѵ�����, *�����Ͽ� ����Ǵ� ��ǰ�� ���º� �̰��� �ѵ� ����. �̰��� �ѵ��� ������� ���� ��ǰ�� 0*�ֽļ������� �ش�\n8 => 15, 20140303
	memcpy(out->product_cat, data->product_cat, sizeof(data->product_cat));	// �Ҽ� ��ǰ��, *�ֽļ���/�ɼǿ��� �ش�
	out->product_cat_off_pctg = Str2Dbl(data->product_cat_off_pctg, sizeof(data->product_cat_off_pctg), 3);	// ��ǰ�� �ɼ���, *������� ǥ��*�ֽļ���/�ɼǿ��� �ش翹) 9999999.995 => 9, 20140303
	out->limit_ord_clsf_code = Str2Int(data->limit_ord_clsf_code, sizeof(data->limit_ord_clsf_code));	// ������ȣ�����Ǳ����ڵ�, ȣ���� ü�� �� �ܷ�����. Bitwise ����--�ڵ尪--1: FAS (Fill And Store)2: FOK (Fill Or Kill)\n3: FAK (Fill And Kill)* ������ȣ�����Ǳ����ڵ� BITWISE ����\n���� Ȯ�强�� ���� �ش� 10�������� 2������ ��ȯ�Ͽ� ó�����(�ִ� 16bit���� ��밡��)�� ) ������ȣ�����Ǳ����ڵ� ���� 6�̸�\n	(������ 6 -> ������ 00000110)0��° bit 0 -> 0 : FAS1��° bit 1 -> 2 : FOK\n2��° bit 1 -> 4 : FAK��, FOK�̸鼭 FAK�� �����Ѵٴ� �ǹ� (FOK & FAK)\nX => 9, 1 => 5, 20140303
	out->mrk_ord_clsf_code = Str2Int(data->mrk_ord_clsf_code, sizeof(data->mrk_ord_clsf_code));	// ���尡ȣ�����Ǳ����ڵ�, * ��
	out->cond_limit_ord_clsf_code = Str2Int(data->cond_limit_ord_clsf_code, sizeof(data->cond_limit_ord_clsf_code));	// ���Ǻ�������ȣ�����Ǳ����ڵ�, * ��
	out->best_limit_ord_clsf_code = Str2Int(data->best_limit_ord_clsf_code, sizeof(data->best_limit_ord_clsf_code));	// ������������ȣ�����Ǳ����ڵ�, * ��
	out->efp_clsf = data->efp_clsf[0];	//EFP�ŷ���󿩺�, Y, N, ��ǰ������ �ش�
	out->flex_clsf = data->flex_clsf[0];	//FLEX�ŷ���󿩺�, Y, N, ��ǰ������ �ش�
	out->yest_efp_exe_q = Str2Dbl(data->yest_efp_exe_q, sizeof(data->yest_efp_exe_q), 0);	// ����EFPü�����, ��ǰ������ �ش�
	out->yest_efp_trd_amount = Str2Dbl(data->yest_efp_trd_amount, sizeof(data->yest_efp_trd_amount), 0);	// ����EFP�ŷ����, ��ǰ������ �ش�
	out->mkr_close_clsf = data->mkr_close_clsf[0];	//���忩��, ���忩�� (Y,N), 20121217
	out->real_t_prc_limit_clsf = data->real_t_prc_limit_clsf[0];	//�ǽð��������ѿ���, ���� ü�ᰡ�� ��� Ư�� ������ �ʰ��ϴ� ȣ���� �ź��ϵ��� �������� ����(Y/N) 20140901
	out->real_t_high_price_gap = Str2SignDouble(data->real_t_high_price_gap_sign, sizeof(data->real_t_high_price_gap_sign) + sizeof(data->real_t_high_price_gap), 2);	// �ǽð����Ѱ�����, ���� ü�ᰡ�ݰ� �ǽð����Ѱ����� ���� �ǽð����Ѱ� = ����ü�ᰡ�� + �ǽð����Ѱ����� ex) 9999999999.99 20140901
	out->real_t_low_price_gap = Str2SignDouble(data->real_t_low_price_gap_sign, sizeof(data->real_t_low_price_gap_sign) + sizeof(data->real_t_low_price_gap), 2);	// �ǽð����Ѱ�����, ���� ü�ᰡ�ݰ� �ǽð����Ѱ����� ���� �ǽð����Ѱ� = ����ü�ᰡ�� + �ǽð����Ѱ�����(����) ex) 9999999999.99 20140901
	memcpy(out->under_ass_mrk_id, data->under_ass_mrk_id, sizeof(data->under_ass_mrk_id));	// �����ڻ����ID, �����ڻ����ID�� �����ڻ��� KRX�� ����� ��쿡�� ä����.K200�����ɼ�:STK�ڽ���150����:KSQ�ֽļ����ɼ�:STK/KSQ ��ǰ�����ɼ�:SPACE��������������:STK������������:STK�̴�K200�����ɼ�:STK
	out->upper_limit_ord_q = Str2Dbl(data->upper_limit_ord_q, sizeof(data->upper_limit_ord_q), 0);	// ���Ѽ���, ȣ�����Ѽ��� (20181210 �׸��߰�)
	out->lower_limit_ord_q = Str2Dbl(data->lower_limit_ord_q, sizeof(data->lower_limit_ord_q), 0);	// ���Ѽ���, ȣ�����Ѽ��� (20181210 �׸��߰�)
	out->block_trd_upper_limit_ord_q = Str2Dbl(data->block_trd_upper_limit_ord_q, sizeof(data->block_trd_upper_limit_ord_q), 0);	// ���Ǵ뷮�ŸŻ��Ѽ���, ���Ǵ뷮�Ÿ�ȣ�����Ѽ��� (20181210 �׸��߰�)
	out->block_trd_lower_limit_ord_q = Str2Dbl(data->block_trd_lower_limit_ord_q, sizeof(data->block_trd_lower_limit_ord_q), 0);	// ���Ǵ뷮�Ÿ����Ѽ���, ���Ǵ뷮�Ÿ�ȣ�����Ѽ��� (20181210 �׸��߰�)

	return 1;
}


// K200�ɼ�_�ΰ���
int ParseN7034(const double& timestamp, const char* in_buff, DF_K200_OPT_SENSITIVITY_DATA* out) {
	K200_OPT_SENSITIVITY_DATA* data = (K200_OPT_SENSITIVITY_DATA*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����, N7
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������, 03:KOSPI200�����ɼ�
	out->mrk_clsf = data->mrk_clsf[0];	//���屸��, 4
	memcpy(out->isin_clsf, data->isin_clsf, sizeof(data->isin_clsf));	// �����ڵ�
	memcpy(out->stk_snr, data->stk_snr, sizeof(data->stk_snr));	// ����SEQ
	memcpy(out->created_date, data->created_date, sizeof(data->created_date));	// ��������
	memcpy(out->created_time, data->created_time, sizeof(data->created_time));	// �����ð�
	out->clsf_code = data->clsf_code[0];	//�����ڵ�, 1:����Ȯ��,2:���߻���,E:���߿Ϸ�,3:����Ȯ��
	memcpy(out->under_asset_id, data->under_asset_id, sizeof(data->under_asset_id));	// �����ڻ�ID, K2I:KOSPI200
	out->sensitivity_delta = Str2SignDouble(data->sensitivity_delta_sign, sizeof(data->sensitivity_delta_sign) + sizeof(data->sensitivity_delta), 6);	// �ΰ��� ��Ÿ, 9(12)V9(6)
	out->sensitivity_theta = Str2SignDouble(data->sensitivity_theta_sign, sizeof(data->sensitivity_theta_sign) + sizeof(data->sensitivity_theta), 6);	// �ΰ��� ��Ÿ, 9(12)V9(6)
	out->sensitivity_vega = Str2SignDouble(data->sensitivity_vega_sign, sizeof(data->sensitivity_vega_sign) + sizeof(data->sensitivity_vega), 6);	// �ΰ��� ����, 9(12)V9(6)
	out->sensitivity_gamma = Str2SignDouble(data->sensitivity_gamma_sign, sizeof(data->sensitivity_gamma_sign) + sizeof(data->sensitivity_gamma), 6);	// �ΰ��� ����, 9(12)V9(6)
	out->sensitivity_rho = Str2SignDouble(data->sensitivity_rho_sign, sizeof(data->sensitivity_rho_sign) + sizeof(data->sensitivity_rho), 6);	// �ΰ��� ��, 9(12)V9(6)

	return 1;
}


// KOSPI200�ɼ� ���纯����
int ParseP1034(const double& timestamp, const char* in_buff, DF_K200_OPT_IMPLIED_VOL_DATA* out) {
	K200_OPT_IMPLIED_VOL_DATA* data = (K200_OPT_IMPLIED_VOL_DATA*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����, P1
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������, 03:KOSPI200�����ɼ�
	out->mrk_clsf = data->mrk_clsf[0];	//���屸��, 4
	out->call_ave_implied_vol = Str2Dbl(data->call_ave_implied_vol, sizeof(data->call_ave_implied_vol), 4);	// ����ճ��纯����, 999999v9999
	out->put_ave_implied_vol = Str2Dbl(data->put_ave_implied_vol, sizeof(data->put_ave_implied_vol), 4);	// ǲ��ճ��纯����, 999999v9999
	out->rep_implied_vol = Str2Dbl(data->rep_implied_vol, sizeof(data->rep_implied_vol), 4);	// ��ǥ���纯����, 999999v9999
	out->hist_vol_90_days = Str2Dbl(data->hist_vol_90_days, sizeof(data->hist_vol_90_days), 4);	// ������������(90��), 999999v9999

	return 1;
}


// K200�ɼ�_������ ������
int ParseH1034(const double& timestamp, const char* in_buff, DF_K200_OPT_INVESTOR_DATA* out) {
	K200_OPT_INVESTOR_DATA* data = (K200_OPT_INVESTOR_DATA*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����, H1
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������, 03:KOSPI200�����ɼ�
	out->mrk_clsf = data->mrk_clsf[0];	//���屸��, 4
	memcpy(out->created_date, data->created_date, sizeof(data->created_date));	// ��������
	memcpy(out->created_time, data->created_time, sizeof(data->created_time));	// �����ð�
	memcpy(out->inv_data_clsf, data->inv_data_clsf, sizeof(data->inv_data_clsf));	// �����ͱ���, *����Ȯ�� : 00, �������� : 01, ����Ȯ�� : 02\n *E1 : ���� ������ �Ϸ�, E2 : Ȯ�� ������ �Ϸ�\n ���� record '99' set\n *�������� ù��° �����ʹ� �尳�������ǰŷ��� ����
	memcpy(out->prd_id, data->prd_id, sizeof(data->prd_id));	// ��ǰID, �ڵ尪�������� - KRDRVOPK2I
	out->opt_clsf = data->opt_clsf[0];	//�ɼǱ���, C:�ݿɼ�, P:ǲ�ɼ�
	memcpy(out->inv_clsf, data->inv_clsf, sizeof(data->inv_clsf));	// ����������, �ڵ尪���� ���� *�ڵ� '7000'�� ����,��������׸� 0���� ����
	out->long_exe_q = Str2Int(data->long_exe_q, sizeof(data->long_exe_q));	// �ż� ��������
	out->short_exe_q = Str2Int(data->short_exe_q, sizeof(data->short_exe_q));	// �ŵ� ��������
	out->long_traded_amt = Str2Dbl(data->long_traded_amt, sizeof(data->long_traded_amt), 0);	// �ż� �������
	out->short_traded_amt = Str2Dbl(data->short_traded_amt, sizeof(data->short_traded_amt), 0);	// �ŵ� �������

	return 1;
}


// K200�ɼ�_�ü�Recovery ������
int ParseB2034(const double& timestamp, const char* in_buff, DF_K200_OPT_RECOVERY_DATA* out) {
	K200_OPT_RECOVERY_DATA* data = (K200_OPT_RECOVERY_DATA*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����, B2
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������, 03:KOSPI200�����ɼ�
	out->mrk_clsf = data->mrk_clsf[0];	//���屸��, 4
	memcpy(out->isin_clsf, data->isin_clsf, sizeof(data->isin_clsf));	// �����ڵ�
	out->stk_snr = Str2Int(data->stk_snr, sizeof(data->stk_snr));	// �����Ϸù�ȣ, �����Ϸù�ȣ �ڸ��� ����(3->4)
	out->cur_prc = Str2Dbl(data->cur_prc, sizeof(data->cur_prc), 2);	// ���簡, ��) 999.99
	out->init_prc = Str2Dbl(data->init_prc, sizeof(data->init_prc), 2);	// �ð�, ��) 999.99
	out->high_prc = Str2Dbl(data->high_prc, sizeof(data->high_prc), 2);	// ��, ��) 999.99
	out->low_prc = Str2Dbl(data->low_prc, sizeof(data->low_prc), 2);	// ����, ��) 999.99
	out->open_interest_q = Str2Int(data->open_interest_q, sizeof(data->open_interest_q));	// �̰�����
	out->accm_exe_q = Str2Int(data->accm_exe_q, sizeof(data->accm_exe_q));	// ����ü�����
	out->accm_trd_amt = Str2Dbl(data->accm_trd_amt, sizeof(data->accm_trd_amt), 0);	// �����ŷ����, ����:õ��
	out->l_or_s = data->l_or_s[0];	//�����ŵ��ż������ڵ�, 1:�ŵ�,2:�ż�(�������� ���� ȣ���� �ŵ��ż����а�)
	out->s_lvl_1_prc = Str2Dbl(data->s_lvl_1_prc, sizeof(data->s_lvl_1_prc), 2);	// �ŵ�1ȣ��, ��) 999.99
	out->s_lvl_1_q = Str2Int(data->s_lvl_1_q, sizeof(data->s_lvl_1_q));	// �ŵ�1ȣ������
	out->s_lvl_1_trd_cnt = Str2Int(data->s_lvl_1_trd_cnt, sizeof(data->s_lvl_1_trd_cnt));	// �ŵ�1ȣ���Ǽ�
	out->l_lvl_1_prc = Str2Dbl(data->l_lvl_1_prc, sizeof(data->l_lvl_1_prc), 2);	// �ż�1ȣ��, ��) 999.99
	out->l_lvl_1_q = Str2Int(data->l_lvl_1_q, sizeof(data->l_lvl_1_q));	// �ż�1ȣ������
	out->l_lvl_1_trd_cnt = Str2Int(data->l_lvl_1_trd_cnt, sizeof(data->l_lvl_1_trd_cnt));	// �ż�1ȣ���Ǽ�
	out->s_lvl_2_prc = Str2Dbl(data->s_lvl_2_prc, sizeof(data->s_lvl_2_prc), 2);	// �ŵ�2ȣ��, ��) 999.99
	out->s_lvl_2_q = Str2Int(data->s_lvl_2_q, sizeof(data->s_lvl_2_q));	// �ŵ�2ȣ������
	out->s_lvl_2_trd_cnt = Str2Int(data->s_lvl_2_trd_cnt, sizeof(data->s_lvl_2_trd_cnt));	// �ŵ�2ȣ���Ǽ�
	out->l_lvl_2_prc = Str2Dbl(data->l_lvl_2_prc, sizeof(data->l_lvl_2_prc), 2);	// �ż�2ȣ��, ��) 999.99
	out->l_lvl_2_q = Str2Int(data->l_lvl_2_q, sizeof(data->l_lvl_2_q));	// �ż�2ȣ������
	out->l_lvl_2_trd_cnt = Str2Int(data->l_lvl_2_trd_cnt, sizeof(data->l_lvl_2_trd_cnt));	// �ż�2ȣ���Ǽ�
	out->s_lvl_3_prc = Str2Dbl(data->s_lvl_3_prc, sizeof(data->s_lvl_3_prc), 2);	// �ŵ�3ȣ��, ��) 999.99
	out->s_lvl_3_q = Str2Int(data->s_lvl_3_q, sizeof(data->s_lvl_3_q));	// �ŵ�3ȣ������
	out->s_lvl_3_trd_cnt = Str2Int(data->s_lvl_3_trd_cnt, sizeof(data->s_lvl_3_trd_cnt));	// �ŵ�3ȣ���Ǽ�
	out->l_lvl_3_prc = Str2Dbl(data->l_lvl_3_prc, sizeof(data->l_lvl_3_prc), 2);	// �ż�3ȣ��, ��) 999.99
	out->l_lvl_3_q = Str2Int(data->l_lvl_3_q, sizeof(data->l_lvl_3_q));	// �ż�3ȣ������
	out->l_lvl_3_trd_cnt = Str2Int(data->l_lvl_3_trd_cnt, sizeof(data->l_lvl_3_trd_cnt));	// �ż�3ȣ���Ǽ�
	out->s_lvl_4_prc = Str2Dbl(data->s_lvl_4_prc, sizeof(data->s_lvl_4_prc), 2);	// �ŵ�4ȣ��, ��) 999.99
	out->s_lvl_4_q = Str2Int(data->s_lvl_4_q, sizeof(data->s_lvl_4_q));	// �ŵ�4ȣ������
	out->s_lvl_4_trd_cnt = Str2Int(data->s_lvl_4_trd_cnt, sizeof(data->s_lvl_4_trd_cnt));	// �ŵ�4ȣ���Ǽ�
	out->l_lvl_4_prc = Str2Dbl(data->l_lvl_4_prc, sizeof(data->l_lvl_4_prc), 2);	// �ż�4ȣ��, ��) 999.99
	out->l_lvl_4_q = Str2Int(data->l_lvl_4_q, sizeof(data->l_lvl_4_q));	// �ż�4ȣ������
	out->l_lvl_4_trd_cnt = Str2Int(data->l_lvl_4_trd_cnt, sizeof(data->l_lvl_4_trd_cnt));	// �ż�4ȣ���Ǽ�
	out->s_lvl_5_prc = Str2Dbl(data->s_lvl_5_prc, sizeof(data->s_lvl_5_prc), 2);	// �ŵ�5ȣ��, ��) 999.99
	out->s_lvl_5_q = Str2Int(data->s_lvl_5_q, sizeof(data->s_lvl_5_q));	// �ŵ�5ȣ������
	out->s_lvl_5_trd_cnt = Str2Int(data->s_lvl_5_trd_cnt, sizeof(data->s_lvl_5_trd_cnt));	// �ŵ�5ȣ���Ǽ�
	out->l_lvl_5_prc = Str2Dbl(data->l_lvl_5_prc, sizeof(data->l_lvl_5_prc), 2);	// �ż�5ȣ��, ��) 999.99
	out->l_lvl_5_q = Str2Int(data->l_lvl_5_q, sizeof(data->l_lvl_5_q));	// �ż�5ȣ������
	out->l_lvl_5_trd_cnt = Str2Int(data->l_lvl_5_trd_cnt, sizeof(data->l_lvl_5_trd_cnt));	// �ż�5ȣ���Ǽ�
	out->total_s_limit_ord_q = Str2Int(data->total_s_limit_ord_q, sizeof(data->total_s_limit_ord_q));	// �ŵ� ��ȣ������
	out->total_s_trd_cnt = Str2Int(data->total_s_trd_cnt, sizeof(data->total_s_trd_cnt));	// �ŵ���ȿȣ���Ǽ�
	out->total_l_limit_ord_q = Str2Int(data->total_l_limit_ord_q, sizeof(data->total_l_limit_ord_q));	// �ż� ��ȣ������
	out->total_l_trd_cnt = Str2Int(data->total_l_trd_cnt, sizeof(data->total_l_trd_cnt));	// �ż���ȿȣ���Ǽ�
	memcpy(out->ss_id, data->ss_id, sizeof(data->ss_id));	// ����ID, �ڵ尪��������
	memcpy(out->brd_id, data->brd_id, sizeof(data->brd_id));	// ����ID, �ڵ尪��������
	memcpy(out->brd_event_id, data->brd_event_id, sizeof(data->brd_event_id));	// �����̺�ƮID, B2 ������ �����̺�ƮID ������(���� ���°��� ���۵� �� ����). ����, �ش� �׸� '000' ���� ����. 2014.03.24)
	out->exp_prc = Str2Dbl(data->exp_prc, sizeof(data->exp_prc), 2);	// ����ü�ᰡ��, ��) 999.99 ���ϰ��ŸŽø� ����\n (����±����ڵ�:10,20,30,80)
	out->real_t_high_prc = Str2Dbl(data->real_t_high_prc, sizeof(data->real_t_high_prc), 2);	// �ǽð����Ѱ�, ��) 999.99 ���߰��̵�����
	out->real_t_low_prc = Str2Dbl(data->real_t_low_prc, sizeof(data->real_t_low_prc), 2);	// �ǽð����Ѱ�, ��) 999.99 ���߰��̵�����

	return 1;
}


// K200�ɼ�_Polling ������
int ParseI2034(const double& timestamp, const char* in_buff, DF_K200_OPT_POLLING_DATA* out) {
	K200_OPT_POLLING_DATA* data = (K200_OPT_POLLING_DATA*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����, I2
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������, 03:KOSPI200�����ɼ�
	out->mrk_clsf = data->mrk_clsf[0];	//���屸��, 4
	memcpy(out->send_t, data->send_t, sizeof(data->send_t));	// ���۽ð�, HHSS
	memcpy(out->main_backup_clsf, data->main_backup_clsf, sizeof(data->main_backup_clsf));	// Main Backup����, space

	return 1;
}


// K200�ɼ�_�尳�������ǰŷ�
int ParseM7034(const double& timestamp, const char* in_buff, DF_K200_OPT_BLOCK_TRD_BEF_MRK_OPEN* out) {
	K200_OPT_BLOCK_TRD_BEF_MRK_OPEN* data = (K200_OPT_BLOCK_TRD_BEF_MRK_OPEN*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����, M7
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������, 03:KOSPI200�����ɼ�
	out->mrk_clsf = data->mrk_clsf[0];	//���屸��, 4
	memcpy(out->isin_clsf, data->isin_clsf, sizeof(data->isin_clsf));	// �����ڵ�, ���� record '999999999999' set
	out->stk_snr = Str2Int(data->stk_snr, sizeof(data->stk_snr));	// ����SEQ, ����SEQ �ڸ��� ����(3->4)
	out->exe_prc = Str2Dbl(data->exe_prc, sizeof(data->exe_prc), 2);	// ü�ᰡ��, ��) 999.99 (���۴��� ���� ���ذ���)
	out->exe_q = Str2Int(data->exe_q, sizeof(data->exe_q));	// ü�����, �尳�������ǰŷ� ü�� ������ ��� �ջ��� ����
	memcpy(out->exe_clsf_code, data->exe_clsf_code, sizeof(data->exe_clsf_code));	// ü�������ڵ�, ���ǰŷ�\n 46 : EUREX

	return 1;
}
