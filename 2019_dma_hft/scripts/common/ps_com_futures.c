// ps_com_futures.c
// ��ǰ���� �ǽð�
// �ּ��� \n�� ���� ���߿� �̻ڰ� �ٲ����

#include "ps_com_futures.h"


extern int     Str2Int(char *str, int size);
extern double  Str2Dbl(char *str, int size, int point);
extern double  Str2SignDouble(char *str, int size, int point);


// ��ǰ����_����+�����ջ�
int ParseC4016(const double& timestamp, const char* in_buff, DF_COM_FUT_COMP_BLOCK* out) {
	COM_FUT_COMP_BLOCK* data = (COM_FUT_COMP_BLOCK*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����,C4
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������,01:��ǰ����
	out->mkt_clsf = data->mkt_clsf[0];	//���屸��,6
	memcpy(out->isin_clsf, data->isin_clsf, sizeof(data->isin_clsf));	// �����ڵ�,*���߰��̵� ���� : �ű�ä���� �߰�\n 2010.10.25
	out->stk_snr = Str2Int(data->stk_snr, sizeof(data->stk_snr));	// �����Ϸù�ȣ
	out->cpt_block_trd_vol = Str2Dbl(data->cpt_block_trd_vol, sizeof(data->cpt_block_trd_vol), 0);	// ����+�����ջ� �ŷ���,����Ÿ�, ���Ǵ뷮�ŷ�, EFP, FLEX �ŷ��� �ջ��� �ŷ���
	out->cpt_block_trd_amt = Str2Dbl(data->cpt_block_trd_amt, sizeof(data->cpt_block_trd_amt), 0);	// ����+�����ջ� �ŷ����,����Ÿ�, ���Ǵ뷮�ŷ�, EFP, FLEX �ŷ��� �ջ��� �ŷ����\n(���� : ��)

	return 1;
}


// ��ǰ����_ü��
int ParseA3016(const double& timestamp, const char* in_buff, DF_COM_FUT_EXEC* out) {
	COM_FUT_EXEC* data = (COM_FUT_EXEC*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����,A3
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������,01:��ǰ����
	out->mkt_clsf = data->mkt_clsf[0];	//���屸��,6
	memcpy(out->isin_clsf, data->isin_clsf, sizeof(data->isin_clsf));	// �����ڵ�,*���߰��̵� ���� : �ű�ä���� �߰�\n 2010.10.25
	out->stk_snr = Str2Int(data->stk_snr, sizeof(data->stk_snr));	// �����Ϸù�ȣ
	memcpy(out->brd_id, data->brd_id, sizeof(data->brd_id));	// ����ID,�ڵ尪��������
	out->cur_prc = Str2SignDouble(data->cur_prc_sign, sizeof(data->cur_prc_sign) + sizeof(data->cur_prc), 2);	// ���簡��,��) 999999.99
	out->exe_q = Str2Int(data->exe_q, sizeof(data->exe_q));	// ü�����
	memcpy(out->ss_id, data->ss_id, sizeof(data->ss_id));	// ����ID,�ڵ尪��������
	memcpy(out->exe_t, data->exe_t, sizeof(data->exe_t));	// ü��ð�
	out->rct_prd_prc = Str2Dbl(data->rct_prd_prc, sizeof(data->rct_prd_prc), 2);	// �ֱٿ���������������,��) 999999.99
	out->nxt_prd_prc = Str2Dbl(data->nxt_prd_prc, sizeof(data->nxt_prd_prc), 2);	// ������������������,��) 999999.99
	out->init_prc = Str2SignDouble(data->init_prc_sign, sizeof(data->init_prc_sign) + sizeof(data->init_prc), 2);	// �ð�,��) 999999.99
	out->high_prc = Str2SignDouble(data->high_prc_sign, sizeof(data->high_prc_sign) + sizeof(data->high_prc), 2);	// ��,��) 999999.99
	out->low_prc = Str2SignDouble(data->low_prc_sign, sizeof(data->low_prc_sign) + sizeof(data->low_prc), 2);	// ����,��) 999999.99
	out->pri_prc = Str2SignDouble(data->pri_prc_sign, sizeof(data->pri_prc_sign) + sizeof(data->pri_prc), 2);	// ��������,��) 999999.99
	out->accm_exe_q = Str2Int(data->accm_exe_q, sizeof(data->accm_exe_q));	// ����ü�����
	out->accm_trd_amt = Str2Dbl(data->accm_trd_amt, sizeof(data->accm_trd_amt), 0);	// �����ŷ����(����:��)
	out->l_or_s = data->l_or_s[0];	//�����ŵ��ż������ڵ�,1:�ŵ�,2:�ż�(�������� ���� ȣ���� �ŵ��ż����а�)
	out->real_t_high_prc = Str2SignDouble(data->real_t_high_prc_sign, sizeof(data->real_t_high_prc_sign) + sizeof(data->real_t_high_prc), 2);	// �ǽð����Ѱ�,��) 999999.99 ���߰��̵�����
	out->real_t_low_prc = Str2SignDouble(data->real_t_low_prc_sign, sizeof(data->real_t_low_prc_sign) + sizeof(data->real_t_low_prc), 2);	// �ǽð����Ѱ�,��) 999999.99 ���߰��̵�����

	return 1;
}


// ��ǰ����_�켱ȣ��
int ParseB6016(const double& timestamp, const char* in_buff, DF_COM_FUT_LIMIT_ORD* out) {
	COM_FUT_LIMIT_ORD* data = (COM_FUT_LIMIT_ORD*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����,B6
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������,01:��ǰ����
	out->mkt_clsf = data->mkt_clsf[0];	//���屸��,6
	memcpy(out->isin_clsf, data->isin_clsf, sizeof(data->isin_clsf));	// �����ڵ�,*���߰��̵� ���� : �ű�ä���� �߰�\n 2010.10.25
	out->stk_snr = Str2Int(data->stk_snr, sizeof(data->stk_snr));	// �����Ϸù�ȣ
	memcpy(out->brd_id, data->brd_id, sizeof(data->brd_id));	// ����ID,�ڵ尪��������
	memcpy(out->ss_id, data->ss_id, sizeof(data->ss_id));	// ����ID,�ڵ尪��������
	out->total_l_limit_ord_q = Str2Int(data->total_l_limit_ord_q, sizeof(data->total_l_limit_ord_q));	// �ż���ȣ���ܷ�
	out->l_lvl_1_prc = Str2SignDouble(data->l_lvl_1_sign, sizeof(data->l_lvl_1_sign) + sizeof(data->l_lvl_1_prc), 2);	// �ż�1�ܰ�켱ȣ������,��) 999999.99
	out->l_lvl_1_q = Str2Int(data->l_lvl_1_q, sizeof(data->l_lvl_1_q));	// �ż�1�ܰ�켱ȣ���ܷ�
	out->l_lvl_2_prc = Str2SignDouble(data->l_lvl_2_sign, sizeof(data->l_lvl_2_sign) + sizeof(data->l_lvl_2_prc), 2);	// �ż�2�ܰ�켱ȣ������,��) 999999.99
	out->l_lvl_2_q = Str2Int(data->l_lvl_2_q, sizeof(data->l_lvl_2_q));	// �ż�2�ܰ�켱ȣ���ܷ�
	out->l_lvl_3_prc = Str2SignDouble(data->l_lvl_3_sign, sizeof(data->l_lvl_3_sign) + sizeof(data->l_lvl_3_prc), 2);	// �ż�3�ܰ�켱ȣ������,��) 999999.99
	out->l_lvl_3_q = Str2Int(data->l_lvl_3_q, sizeof(data->l_lvl_3_q));	// �ż�3�ܰ�켱ȣ���ܷ�
	out->l_lvl_4_prc = Str2SignDouble(data->l_lvl_4_sign, sizeof(data->l_lvl_4_sign) + sizeof(data->l_lvl_4_prc), 2);	// �ż�4�ܰ�켱ȣ������,��) 999999.99
	out->l_lvl_4_q = Str2Int(data->l_lvl_4_q, sizeof(data->l_lvl_4_q));	// �ż�4�ܰ�켱ȣ���ܷ�
	out->l_lvl_5_prc = Str2SignDouble(data->l_lvl_5_sign, sizeof(data->l_lvl_5_sign) + sizeof(data->l_lvl_5_prc), 2);	// �ż�5�ܰ�켱ȣ������,��) 999999.99
	out->l_lvl_5_q = Str2Int(data->l_lvl_5_q, sizeof(data->l_lvl_5_q));	// �ż�5�ܰ�켱ȣ���ܷ�
	out->total_s_limit_ord_q = Str2Int(data->total_s_limit_ord_q, sizeof(data->total_s_limit_ord_q));	// �ŵ���ȣ���ܷ�
	out->s_lvl_1_prc = Str2SignDouble(data->s_lvl_1_sign, sizeof(data->s_lvl_1_sign) + sizeof(data->s_lvl_1_prc), 2);	// �ŵ�1�ܰ�켱ȣ������,��) 999999.99
	out->s_lvl_1_q = Str2Int(data->s_lvl_1_q, sizeof(data->s_lvl_1_q));	// �ŵ�1�ܰ�켱ȣ���ܷ�
	out->s_lvl_2_prc = Str2SignDouble(data->s_lvl_2_sign, sizeof(data->s_lvl_2_sign) + sizeof(data->s_lvl_2_prc), 2);	// �ŵ�2�ܰ�켱ȣ������,��) 999999.99
	out->s_lvl_2_q = Str2Int(data->s_lvl_2_q, sizeof(data->s_lvl_2_q));	// �ŵ�2�ܰ�켱ȣ���ܷ�
	out->s_lvl_3_prc = Str2SignDouble(data->s_lvl_3_sign, sizeof(data->s_lvl_3_sign) + sizeof(data->s_lvl_3_prc), 2);	// �ŵ�3�ܰ�켱ȣ������,��) 999999.99
	out->s_lvl_3_q = Str2Int(data->s_lvl_3_q, sizeof(data->s_lvl_3_q));	// �ŵ�3�ܰ�켱ȣ���ܷ�
	out->s_lvl_4_prc = Str2SignDouble(data->s_lvl_4_sign, sizeof(data->s_lvl_4_sign) + sizeof(data->s_lvl_4_prc), 2);	// �ŵ�4�ܰ�켱ȣ������,��) 999999.99
	out->s_lvl_4_q = Str2Int(data->s_lvl_4_q, sizeof(data->s_lvl_4_q));	// �ŵ�4�ܰ�켱ȣ���ܷ�
	out->s_lvl_5_prc = Str2SignDouble(data->s_lvl_5_sign, sizeof(data->s_lvl_5_sign) + sizeof(data->s_lvl_5_prc), 2);	// �ŵ�5�ܰ�켱ȣ������,��) 999999.99
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
	out->exp_prc = Str2SignDouble(data->exp_prc_sign, sizeof(data->exp_prc_sign) + sizeof(data->exp_prc), 2);	// ����ü�ᰡ��,��) 999999.99 ���ϰ��ŸŽø� ����\n (����±����ڵ�:10,20,30,80)

	return 1;
}


// ��ǰ����_ü��_�켱ȣ��
int ParseG7016(const double& timestamp, const char* in_buff, DF_COM_FUT_EXEC_LIMIT_ORD* out) {
	COM_FUT_EXEC_LIMIT_ORD* data = (COM_FUT_EXEC_LIMIT_ORD*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����,G7
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������,01:��ǰ����
	out->mrk_clsf = data->mrk_clsf[0];	//���屸��,6
	memcpy(out->isin_clsf, data->isin_clsf, sizeof(data->isin_clsf));	// �����ڵ�,*���߰��̵� ���� : �ű�ä���� �߰�\n 2010.10.25
	out->stk_snr = Str2Int(data->stk_snr, sizeof(data->stk_snr));	// �����Ϸù�ȣ
	memcpy(out->brd_id, data->brd_id, sizeof(data->brd_id));	// ����ID,�ڵ尪��������
	out->cur_price = Str2SignDouble(data->cur_prc_sign, sizeof(data->cur_prc_sign) + sizeof(data->cur_price), 2);	// ���簡��,��) 999999.99
	out->exe_q = Str2Int(data->exe_q, sizeof(data->exe_q));	// ü�����
	memcpy(out->ss_id, data->ss_id, sizeof(data->ss_id));	// ����ID,�ڵ尪��������
	memcpy(out->exe_t, data->exe_t, sizeof(data->exe_t));	// ü��ð�
	out->rct_prd_prc = Str2Dbl(data->rct_prd_prc, sizeof(data->rct_prd_prc), 2);	// �ֱٿ���������������,��) 999999.99
	out->nxt_prd_prc = Str2Dbl(data->nxt_prd_prc, sizeof(data->nxt_prd_prc), 2);	// ������������������,��) 999999.99
	out->init_prc = Str2SignDouble(data->init_prc_sign, sizeof(data->init_prc_sign) + sizeof(data->init_prc), 2);	// �ð�,��) 999999.99
	out->high_prc = Str2SignDouble(data->high_prc_sign, sizeof(data->high_prc_sign) + sizeof(data->high_prc), 2);	// ��,��) 999999.99
	out->low_prc = Str2SignDouble(data->low_prc_sign, sizeof(data->low_prc_sign) + sizeof(data->low_prc), 2);	// ����,��) 999999.99
	out->pri_prc = Str2SignDouble(data->pri_prc_sign, sizeof(data->pri_prc_sign) + sizeof(data->pri_prc), 2);	// ��������,��) 999999.99
	out->accm_exe_q = Str2Int(data->accm_exe_q, sizeof(data->accm_exe_q));	// ����ü�����
	out->accm_trd_amt = Str2Dbl(data->accm_trd_amt, sizeof(data->accm_trd_amt), 0);	// �����ŷ����(����:��)
	out->l_or_s = data->l_or_s[0];	//�����ŵ��ż������ڵ�,1:�ŵ�,2:�ż�(�������� ���� ȣ���� �ŵ��ż����а�)
	out->total_l_limit_ord_q = Str2Int(data->total_l_limit_ord_q, sizeof(data->total_l_limit_ord_q));	// �ż���ȣ���ܷ�
	out->l_lvl_1_prc = Str2SignDouble(data->l_lvl_1_sign, sizeof(data->l_lvl_1_sign) + sizeof(data->l_lvl_1_prc), 2);	// �ż�1�ܰ�켱ȣ������,��) 999999.99
	out->l_lvl_1_q = Str2Int(data->l_lvl_1_q, sizeof(data->l_lvl_1_q));	// �ż�1�ܰ�켱ȣ���ܷ�
	out->l_lvl_2_prc = Str2SignDouble(data->l_lvl_2_sign, sizeof(data->l_lvl_2_sign) + sizeof(data->l_lvl_2_prc), 2);	// �ż�2�ܰ�켱ȣ������,��) 999999.99
	out->l_lvl_2_q = Str2Int(data->l_lvl_2_q, sizeof(data->l_lvl_2_q));	// �ż�2�ܰ�켱ȣ���ܷ�
	out->l_lvl_3_prc = Str2SignDouble(data->l_lvl_3_sign, sizeof(data->l_lvl_3_sign) + sizeof(data->l_lvl_3_prc), 2);	// �ż�3�ܰ�켱ȣ������,��) 999999.99
	out->l_lvl_3_q = Str2Int(data->l_lvl_3_q, sizeof(data->l_lvl_3_q));	// �ż�3�ܰ�켱ȣ���ܷ�
	out->l_lvl_4_prc = Str2SignDouble(data->l_lvl_4_sign, sizeof(data->l_lvl_4_sign) + sizeof(data->l_lvl_4_prc), 2);	// �ż�4�ܰ�켱ȣ������,��) 999999.99
	out->l_lvl_4_q = Str2Int(data->l_lvl_4_q, sizeof(data->l_lvl_4_q));	// �ż�4�ܰ�켱ȣ���ܷ�
	out->l_lvl_5_prc = Str2SignDouble(data->l_lvl_5_sign, sizeof(data->l_lvl_5_sign) + sizeof(data->l_lvl_5_prc), 2);	// �ż�5�ܰ�켱ȣ������,��) 999999.99
	out->l_lvl_5_q = Str2Int(data->l_lvl_5_q, sizeof(data->l_lvl_5_q));	// �ż�5�ܰ�켱ȣ���ܷ�
	out->total_s_limit_ord_q = Str2Int(data->total_s_limit_ord_q, sizeof(data->total_s_limit_ord_q));	// �ŵ���ȣ���ܷ�
	out->s_lvl_1_prc = Str2SignDouble(data->s_lvl_1_sign, sizeof(data->s_lvl_1_sign) + sizeof(data->s_lvl_1_prc), 2);	// �ŵ�1�ܰ�켱ȣ������,��) 999999.99
	out->s_lvl_1_q = Str2Int(data->s_lvl_1_q, sizeof(data->s_lvl_1_q));	// �ŵ�1�ܰ�켱ȣ���ܷ�
	out->s_lvl_2_prc = Str2SignDouble(data->s_lvl_2_sign, sizeof(data->s_lvl_2_sign) + sizeof(data->s_lvl_2_prc), 2);	// �ŵ�2�ܰ�켱ȣ������,��) 999999.99
	out->s_lvl_2_q = Str2Int(data->s_lvl_2_q, sizeof(data->s_lvl_2_q));	// �ŵ�2�ܰ�켱ȣ���ܷ�
	out->s_lvl_3_prc = Str2SignDouble(data->s_lvl_3_sign, sizeof(data->s_lvl_3_sign) + sizeof(data->s_lvl_3_prc), 2);	// �ŵ�3�ܰ�켱ȣ������,��) 999999.99
	out->s_lvl_3_q = Str2Int(data->s_lvl_3_q, sizeof(data->s_lvl_3_q));	// �ŵ�3�ܰ�켱ȣ���ܷ�
	out->s_lvl_4_prc = Str2SignDouble(data->s_lvl_4_sign, sizeof(data->s_lvl_4_sign) + sizeof(data->s_lvl_4_prc), 2);	// �ŵ�4�ܰ�켱ȣ������,��) 999999.99
	out->s_lvl_4_q = Str2Int(data->s_lvl_4_q, sizeof(data->s_lvl_4_q));	// �ŵ�4�ܰ�켱ȣ���ܷ�
	out->s_lvl_5_prc = Str2SignDouble(data->s_lvl_5_sign, sizeof(data->s_lvl_5_sign) + sizeof(data->s_lvl_5_prc), 2);	// �ŵ�5�ܰ�켱ȣ������,��) 999999.99
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
	out->real_t_high_prc = Str2SignDouble(data->real_t_high_prc_sign, sizeof(data->real_t_high_prc_sign) + sizeof(data->real_t_high_prc), 2);	// �ǽð����Ѱ�,��) 999999.99 ���߰��̵�����
	out->real_t_low_prc = Str2SignDouble(data->real_t_low_prc_sign, sizeof(data->real_t_low_prc_sign) + sizeof(data->real_t_low_prc), 2);	// �ǽð����Ѱ�,��) 999999.99 ���߰��̵�����

	return 1;
}


// ��ǰ����_���񸶰�
int ParseA6016(const double& timestamp, const char* in_buff, DF_COM_FUT_CLOSE_PRODUCT* out) {
	COM_FUT_CLOSE_PRODUCT* data = (COM_FUT_CLOSE_PRODUCT*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����,A6
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������,01:��ǰ����
	out->mrk_clsf = data->mrk_clsf[0];	//���屸��,6
	memcpy(out->isin_clsf, data->isin_clsf, sizeof(data->isin_clsf));	// �����ڵ�,*���߰��̵� ���� : �ű�ä���� �߰�\n 2010.10.25
	out->stk_snr = Str2Int(data->stk_snr, sizeof(data->stk_snr));	// �����Ϸù�ȣ
	memcpy(out->brd_id, data->brd_id, sizeof(data->brd_id));	// ����ID,�ڵ尪��������
	out->close_prc = Str2SignDouble(data->close_prc_sign, sizeof(data->close_prc_sign) + sizeof(data->close_prc), 2);	// ����,* �ŷ��� ������ ��� ���ذ� set, ��) 999999.99
	out->close_prc_code = data->close_prc_code[0];	//���������ڵ�,1:�Ǽ�, 3:�ŷ���\n 2:�⼼ -2012.05.14 ����\n ' ':�������� �ƴ� ��� space
	out->accm_exe_q = Str2Int(data->accm_exe_q, sizeof(data->accm_exe_q));	// ����ü�����
	out->accm_trd_amt = Str2Dbl(data->accm_trd_amt, sizeof(data->accm_trd_amt), 0);	// �����ŷ����(����:��)
	out->total_l_limit_ord_q = Str2Int(data->total_l_limit_ord_q, sizeof(data->total_l_limit_ord_q));	// �ż���ȣ���ܷ�
	out->l_lvl_1_prc = Str2SignDouble(data->l_lvl_1_sign, sizeof(data->l_lvl_1_sign) + sizeof(data->l_lvl_1_prc), 2);	// �ż�1�ܰ�켱ȣ������,��) 999999.99
	out->l_lvl_1_q = Str2Int(data->l_lvl_1_q, sizeof(data->l_lvl_1_q));	// �ż�1�ܰ�켱ȣ���ܷ�
	out->l_lvl_2_prc = Str2SignDouble(data->l_lvl_2_sign, sizeof(data->l_lvl_2_sign) + sizeof(data->l_lvl_2_prc), 2);	// �ż�2�ܰ�켱ȣ������,��) 999999.99
	out->l_lvl_2_q = Str2Int(data->l_lvl_2_q, sizeof(data->l_lvl_2_q));	// �ż�2�ܰ�켱ȣ���ܷ�
	out->l_lvl_3_prc = Str2SignDouble(data->l_lvl_3_sign, sizeof(data->l_lvl_3_sign) + sizeof(data->l_lvl_3_prc), 2);	// �ż�3�ܰ�켱ȣ������,��) 999999.99
	out->l_lvl_3_q = Str2Int(data->l_lvl_3_q, sizeof(data->l_lvl_3_q));	// �ż�3�ܰ�켱ȣ���ܷ�
	out->l_lvl_4_prc = Str2SignDouble(data->l_lvl_4_sign, sizeof(data->l_lvl_4_sign) + sizeof(data->l_lvl_4_prc), 2);	// �ż�4�ܰ�켱ȣ������,��) 999999.99
	out->l_lvl_4_q = Str2Int(data->l_lvl_4_q, sizeof(data->l_lvl_4_q));	// �ż�4�ܰ�켱ȣ���ܷ�
	out->l_lvl_5_prc = Str2SignDouble(data->l_lvl_5_sign, sizeof(data->l_lvl_5_sign) + sizeof(data->l_lvl_5_prc), 2);	// �ż�5�ܰ�켱ȣ������,��) 999999.99
	out->l_lvl_5_q = Str2Int(data->l_lvl_5_q, sizeof(data->l_lvl_5_q));	// �ż�5�ܰ�켱ȣ���ܷ�
	out->total_s_limit_ord_q = Str2Int(data->total_s_limit_ord_q, sizeof(data->total_s_limit_ord_q));	// �ŵ���ȣ���ܷ�
	out->s_lvl_1_prc = Str2SignDouble(data->s_lvl_1_sign, sizeof(data->s_lvl_1_sign) + sizeof(data->s_lvl_1_prc), 2);	// �ŵ�1�ܰ�켱ȣ������,��) 999999.99
	out->s_lvl_1_q = Str2Int(data->s_lvl_1_q, sizeof(data->s_lvl_1_q));	// �ŵ�1�ܰ�켱ȣ���ܷ�
	out->s_lvl_2_prc = Str2SignDouble(data->s_lvl_2_sign, sizeof(data->s_lvl_2_sign) + sizeof(data->s_lvl_2_prc), 2);	// �ŵ�2�ܰ�켱ȣ������,��) 999999.99
	out->s_lvl_2_q = Str2Int(data->s_lvl_2_q, sizeof(data->s_lvl_2_q));	// �ŵ�2�ܰ�켱ȣ���ܷ�
	out->s_lvl_3_prc = Str2SignDouble(data->s_lvl_3_sign, sizeof(data->s_lvl_3_sign) + sizeof(data->s_lvl_3_prc), 2);	// �ŵ�3�ܰ�켱ȣ������,��) 999999.99
	out->s_lvl_3_q = Str2Int(data->s_lvl_3_q, sizeof(data->s_lvl_3_q));	// �ŵ�3�ܰ�켱ȣ���ܷ�
	out->s_lvl_4_prc = Str2SignDouble(data->s_lvl_4_sign, sizeof(data->s_lvl_4_sign) + sizeof(data->s_lvl_4_prc), 2);	// �ŵ�4�ܰ�켱ȣ������,��) 999999.99
	out->s_lvl_4_q = Str2Int(data->s_lvl_4_q, sizeof(data->s_lvl_4_q));	// �ŵ�4�ܰ�켱ȣ���ܷ�
	out->s_lvl_5_prc = Str2SignDouble(data->s_lvl_5_sign, sizeof(data->s_lvl_5_sign) + sizeof(data->s_lvl_5_prc), 2);	// �ŵ�5�ܰ�켱ȣ������,��) 999999.99
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


// ��ǰ����_��TS
int ParseA7016(const double& timestamp, const char* in_buff, DF_COM_FUT_MRK_OP_TS* out) {
	COM_FUT_MRK_OP_TS* data = (COM_FUT_MRK_OP_TS*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����,A7
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������,01:��ǰ����
	out->mrk_clsf = data->mrk_clsf[0];	//���屸��,6
	memcpy(out->isin_clsf, data->isin_clsf, sizeof(data->isin_clsf));	// �����ڵ�
	out->stk_snr = Str2Int(data->stk_snr, sizeof(data->stk_snr));	// �����Ϸù�ȣ
	memcpy(out->prd_id, data->prd_id, sizeof(data->prd_id));	// ��ǰID,�ڵ尪�������� : spaceó��
	memcpy(out->brd_id, data->brd_id, sizeof(data->brd_id));	// ����ID,�ڵ尪��������
	memcpy(out->brd_event_id, data->brd_event_id, sizeof(data->brd_event_id));	// �����̺�ƮID,�ڵ尪��������
	memcpy(out->brd_event_start_t, data->brd_event_start_t, sizeof(data->brd_event_start_t));	// �����̺�Ʈ���۽ð�,������ �����(��:BB1(�ŸŰŷ�����)�� ��� 09000000)
	out->brd_event_code = Str2Int(data->brd_event_code, sizeof(data->brd_event_code));	// �����̺�Ʈ���뱺�ڵ�,�ڵ尪���� ����
	memcpy(out->ss_id, data->ss_id, sizeof(data->ss_id));	// ����ID,�ڵ尪��������
	out->ord_exist = data->ord_exist[0];	//ȣ������,0:ȣ������(�����׸� ����), 1:ȣ������(�����׸� ���)
	out->total_l_limit_ord_q = Str2Int(data->total_l_limit_ord_q, sizeof(data->total_l_limit_ord_q));	// �ż���ȣ���ܷ�
	out->l_lvl_1_prc = Str2SignDouble(data->l_lvl_1_sign, sizeof(data->l_lvl_1_sign) + sizeof(data->l_lvl_1_prc), 2);	// �ż�1�ܰ�켱ȣ������,��) 999999.99
	out->l_lvl_1_q = Str2Int(data->l_lvl_1_q, sizeof(data->l_lvl_1_q));	// �ż�1�ܰ�켱ȣ���ܷ�
	out->l_lvl_2_prc = Str2SignDouble(data->l_lvl_2_sign, sizeof(data->l_lvl_2_sign) + sizeof(data->l_lvl_2_prc), 2);	// �ż�2�ܰ�켱ȣ������,��) 999999.99
	out->l_lvl_2_q = Str2Int(data->l_lvl_2_q, sizeof(data->l_lvl_2_q));	// �ż�2�ܰ�켱ȣ���ܷ�
	out->l_lvl_3_prc = Str2SignDouble(data->l_lvl_3_sign, sizeof(data->l_lvl_3_sign) + sizeof(data->l_lvl_3_prc), 2);	// �ż�3�ܰ�켱ȣ������,��) 999999.99
	out->l_lvl_3_q = Str2Int(data->l_lvl_3_q, sizeof(data->l_lvl_3_q));	// �ż�3�ܰ�켱ȣ���ܷ�
	out->l_lvl_4_prc = Str2SignDouble(data->l_lvl_4_sign, sizeof(data->l_lvl_4_sign) + sizeof(data->l_lvl_4_prc), 2);	// �ż�4�ܰ�켱ȣ������,��) 999999.99
	out->l_lvl_4_q = Str2Int(data->l_lvl_4_q, sizeof(data->l_lvl_4_q));	// �ż�4�ܰ�켱ȣ���ܷ�
	out->l_lvl_5_prc = Str2SignDouble(data->l_lvl_5_sign, sizeof(data->l_lvl_5_sign) + sizeof(data->l_lvl_5_prc), 2);	// �ż�5�ܰ�켱ȣ������,��) 999999.99
	out->l_lvl_5_q = Str2Int(data->l_lvl_5_q, sizeof(data->l_lvl_5_q));	// �ż�5�ܰ�켱ȣ���ܷ�
	out->total_s_limit_ord_q = Str2Int(data->total_s_limit_ord_q, sizeof(data->total_s_limit_ord_q));	// �ŵ���ȣ���ܷ�
	out->s_lvl_1_prc = Str2SignDouble(data->s_lvl_1_sign, sizeof(data->s_lvl_1_sign) + sizeof(data->s_lvl_1_prc), 2);	// �ŵ�1�ܰ�켱ȣ������,��) 999999.99
	out->s_lvl_1_q = Str2Int(data->s_lvl_1_q, sizeof(data->s_lvl_1_q));	// �ŵ�1�ܰ�켱ȣ���ܷ�
	out->s_lvl_2_prc = Str2SignDouble(data->s_lvl_2_sign, sizeof(data->s_lvl_2_sign) + sizeof(data->s_lvl_2_prc), 2);	// �ŵ�2�ܰ�켱ȣ������,��) 999999.99
	out->s_lvl_2_q = Str2Int(data->s_lvl_2_q, sizeof(data->s_lvl_2_q));	// �ŵ�2�ܰ�켱ȣ���ܷ�
	out->s_lvl_3_prc = Str2SignDouble(data->s_lvl_3_sign, sizeof(data->s_lvl_3_sign) + sizeof(data->s_lvl_3_prc), 2);	// �ŵ�3�ܰ�켱ȣ������,��) 999999.99
	out->s_lvl_3_q = Str2Int(data->s_lvl_3_q, sizeof(data->s_lvl_3_q));	// �ŵ�3�ܰ�켱ȣ���ܷ�
	out->s_lvl_4_prc = Str2SignDouble(data->s_lvl_4_sign, sizeof(data->s_lvl_4_sign) + sizeof(data->s_lvl_4_prc), 2);	// �ŵ�4�ܰ�켱ȣ������,��) 999999.99
	out->s_lvl_4_q = Str2Int(data->s_lvl_4_q, sizeof(data->s_lvl_4_q));	// �ŵ�4�ܰ�켱ȣ���ܷ�
	out->s_lvl_5_prc = Str2SignDouble(data->s_lvl_5_sign, sizeof(data->s_lvl_5_sign) + sizeof(data->s_lvl_5_prc), 2);	// �ŵ�5�ܰ�켱ȣ������,��) 999999.99
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
	out->real_t_high_prc = Str2SignDouble(data->real_t_high_prc_sign, sizeof(data->real_t_high_prc_sign) + sizeof(data->real_t_high_prc), 2);	// �ǽð����Ѱ�,��) 999999.99 ���߰��̵�����
	out->real_t_low_prc = Str2SignDouble(data->real_t_low_prc_sign, sizeof(data->real_t_low_prc_sign) + sizeof(data->real_t_low_prc), 2);	// �ǽð����Ѱ�,��) 999999.99 ���߰��̵�����

	return 1;
}


// ��ǰ����_����
int ParseH0016(const double& timestamp, const char* in_buff, DF_COM_FUT_CLOSE* out) {
	COM_FUT_CLOSE* data = (COM_FUT_CLOSE*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����,H0
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������,01:��ǰ����
	out->mrk_clsf = data->mrk_clsf[0];	//���屸��,6

	return 1;
}


// ��ǰ����_�������ٰ���
int ParseM4016(const double& timestamp, const char* in_buff, DF_COM_FUT_MRK_OP_SCHD* out) {
	COM_FUT_MRK_OP_SCHD* data = (COM_FUT_MRK_OP_SCHD*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����,M4
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������,01:��ǰ����
	out->mrk_clsf = data->mrk_clsf[0];	//���屸��,6
	memcpy(out->isin_clsf, data->isin_clsf, sizeof(data->isin_clsf));	// �����ڵ�,*�������� �� ��ġ�� ���
	memcpy(out->stk_snr, data->stk_snr, sizeof(data->stk_snr));	// �����Ϸù�ȣ,*�������� �� ��ġ�� ���
	memcpy(out->prd_id, data->prd_id, sizeof(data->prd_id));	// ��ǰID,�ڵ尪�������� : spaceó��
	memcpy(out->mrk_prd_id, data->mrk_prd_id, sizeof(data->mrk_prd_id));	// ����ǰ�׷�ID,*�ڵ尪��������
	memcpy(out->brd_id, data->brd_id, sizeof(data->brd_id));	// ����ID,�ڵ尪��������
	memcpy(out->brd_event_id, data->brd_event_id, sizeof(data->brd_event_id));	// �����̺�ƮID,�ڵ尪��������
	memcpy(out->brd_event_start_t, data->brd_event_start_t, sizeof(data->brd_event_start_t));	// �����̺�Ʈ���۽ð�
	out->brd_event_code = Str2Int(data->brd_event_code, sizeof(data->brd_event_code));	// �����̺�Ʈ���뱺�ڵ�,�ڵ尪���� ����
	memcpy(out->ss_open_close_code, data->ss_open_close_code, sizeof(data->ss_open_close_code));	// ���ǰ��������ڵ�,BS:���尳��\n BE:��������\n SS:���ǰ���\n SE:��������\n SH:��������\n SR:�����簳
	memcpy(out->ss_id, data->ss_id, sizeof(data->ss_id));	// ����ID,�ڵ尪��������
	out->adj_stage = Str2Int(data->adj_stage, sizeof(data->adj_stage));	// ����ܰ�,�ش���׾���
	out->under_asset_prc_chg = data->under_asset_prc_chg[0];	//�������񰡰�Ȯ��߻��ڵ�,�ش���׾���
	memcpy(out->exp_prc_chg_t, data->exp_prc_chg_t, sizeof(data->exp_prc_chg_t));	// ����Ȯ�뿹���ð�,�ش���׾���

	return 1;
}


// ��ǰ����_�������
int ParseO6016(const double& timestamp, const char* in_buff, DF_COM_FUT_DIST_INFO* out) {
	COM_FUT_DIST_INFO* data = (COM_FUT_DIST_INFO*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����,O6
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������,01:��ǰ����
	out->mrk_clsf = data->mrk_clsf[0];	//���屸��,6
	memcpy(out->isin_clsf, data->isin_clsf, sizeof(data->isin_clsf));	// �����ڵ�
	out->stk_snr = Str2Int(data->stk_snr, sizeof(data->stk_snr));	// �����Ϸù�ȣ
	memcpy(out->brd_id, data->brd_id, sizeof(data->brd_id));	// ����ID,�ڵ尪��������
	out->dist_adj_code = data->dist_adj_code[0];	//������뱸���ڵ�,1:��а���, 2:�������
	out->dist_code = data->dist_code[0];	//���ó�������ڵ�,1:�ż�����, 2:�ż�����,\n 3:�ŵ�����, 4:�ŵ�����\n *��������� �ڵ����(spaceó��)
	memcpy(out->dist_cls_t, data->dist_cls_t, sizeof(data->dist_cls_t));	// ��������ð�

	return 1;
}


// ��ǰ����_�ǽð������Ѱ� ���������
int ParseQ2016(const double& timestamp, const char* in_buff, DF_COM_FUT_REAL_HIGH_LOW_LIMIT_ON_OFF* out) {
	COM_FUT_REAL_HIGH_LOW_LIMIT_ON_OFF* data = (COM_FUT_REAL_HIGH_LOW_LIMIT_ON_OFF*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����,Q2
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������,01:��ǰ����
	out->mrk_clsf = data->mrk_clsf[0];	//���屸��,6
	memcpy(out->isin_clsf, data->isin_clsf, sizeof(data->isin_clsf));	// �����ڵ�
	out->stk_snr = Str2Int(data->stk_snr, sizeof(data->stk_snr));	// �����Ϸù�ȣ
	memcpy(out->brd_id, data->brd_id, sizeof(data->brd_id));	// ����ID,�ڵ尪��������
	memcpy(out->cleared_t, data->cleared_t, sizeof(data->cleared_t));	// ó���ð�
	out->real_t_prc_limit_code = data->real_t_prc_limit_code[0];	//�ǽð��������Ѽ����ڵ�,0: ����, 1: ����, 2: �缳��
	out->real_t_high_prc = Str2SignDouble(data->real_t_high_prc_sign, sizeof(data->real_t_high_prc_sign) + sizeof(data->real_t_high_prc), 2);	// �ǽð����Ѱ�,��) 999999.99 ���߰��̵�����
	out->real_t_low_prc = Str2SignDouble(data->real_t_low_prc_sign, sizeof(data->real_t_low_prc_sign) + sizeof(data->real_t_low_prc), 2);	// �ǽð����Ѱ�,��) 999999.99 ���߰��̵�����

	return 1;
}


// ��ǰ����_�̰����������� ������
int ParseH2016(const double& timestamp, const char* in_buff, DF_COM_FUT_OPEN_INTEREST_DATA* out) {
	COM_FUT_OPEN_INTEREST_DATA* data = (COM_FUT_OPEN_INTEREST_DATA*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����,H2
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������,01:��ǰ����
	out->mrk_clsf = data->mrk_clsf[0];	//���屸��,6
	memcpy(out->isin_clsf, data->isin_clsf, sizeof(data->isin_clsf));	// �����ڵ�,���� record '999999999999' set\n*���߰��̵� ���� : �ű�ä���� �߰�
	out->stk_snr = Str2Int(data->stk_snr, sizeof(data->stk_snr));	// ����SEQ
	memcpy(out->open_interest_clsf, data->open_interest_clsf, sizeof(data->open_interest_clsf));	// �̰�����������,���� Ȯ�� : "M0" (07:40�а� ����)\n���� ���� : "M1" (���� Ư���������� ��������\n		 �۽�, 10��)\n���� Ȯ�� : "M2" (���� ������ �۽�,\n		 ������ 1�ð��� ����)
	memcpy(out->traded_date, data->traded_date, sizeof(data->traded_date));	// �ŷ�����
	out->open_interest_q = Str2Int(data->open_interest_q, sizeof(data->open_interest_q));	// �̰�����������,����:���

	return 1;
}


// ��ǰ����_���갡�� ������
int ParseH3016(const double& timestamp, const char* in_buff, DF_COM_FUT_SETT_PRC_DATA* out) {
	COM_FUT_SETT_PRC_DATA* data = (COM_FUT_SETT_PRC_DATA*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����,H3
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������,01:��ǰ����
	out->mrk_clsf = data->mrk_clsf[0];	//���屸��,6
	memcpy(out->isin_clsf, data->isin_clsf, sizeof(data->isin_clsf));	// �����ڵ�,���� record '999999999999' set\n*���߰��̵� ���� : �ű�ä���� �߰�
	out->stk_snr = Str2Int(data->stk_snr, sizeof(data->stk_snr));	// ����SEQ,�������� - �����ŷ����� ���� ������ 0���� ����
	out->calc_prc = Str2Dbl(data->calc_prc, sizeof(data->calc_prc), 8);	// ���갡��,�������� - �����ŷ����� ���� ������ 0���� ����\n��) 99999999.99999999
	out->calc_prc_clsf = data->calc_prc_clsf[0];	//���갡�ݱ���,�������� - �����ŷ����� ���� ������ �������� ����\n0 : ���갡 ����(���� �ŷ������� �⼼ ����)\n1 : ���� ����(�Ǽ�)\n2 : ���� �⼼(���� �ŷ������� �⼼) - 2010.12.20 ����\n3 : ���� ���갡(���� �ŷ������� ���� ������) - 2010.12.20 ����\n4 : ���� �̷а�(���� �ŷ������� ���� ������)\n5 : ��������ŷ��� ���� ������ ������ ���� - 2010.12.20 ����\n6 : ������ ���� ���갡 - 2010.12.20 ����\n7 : ����ڻ� ����(�̷а����»�ǰ)\n8 : ������ذ��� - 2010.12.20 �߰�
	out->final_sett_prc = Str2Dbl(data->final_sett_prc, sizeof(data->final_sett_prc), 8);	// ������������,��) 99999999.99999999
	out->final_sett_clsf = data->final_sett_clsf[0];	//�����������ݱ���

	return 1;
}


// ��ǰ����_������ ������
int ParseH1016(const double& timestamp, const char* in_buff, DF_COM_FUT_INVESTOR_DATA* out) {
	COM_FUT_INVESTOR_DATA* data = (COM_FUT_INVESTOR_DATA*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����,H1
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������,01:��ǰ����
	out->mrk_clsf = data->mrk_clsf[0];	//���屸��,6
	memcpy(out->created_date, data->created_date, sizeof(data->created_date));	// ��������
	memcpy(out->created_time, data->created_time, sizeof(data->created_time));	// �����ð�
	memcpy(out->inv_data_clsf, data->inv_data_clsf, sizeof(data->inv_data_clsf));	// �����ͱ���,*����Ȯ�� : 00, �������� : 01, ����Ȯ�� : 02\n *E1 : ���� ������ �Ϸ�, E2 : Ȯ�� ������ �Ϸ�\n ���� record '99' set
	memcpy(out->prd_id, data->prd_id, sizeof(data->prd_id));	// ��ǰID,�ڵ尪��������
	memcpy(out->inv_clsf, data->inv_clsf, sizeof(data->inv_clsf));	// ����������,�ڵ尪���� ���� *�ڵ� '7000'�� ����,��������׸� 0���� ����
	out->long_exe_q = Str2Int(data->long_exe_q, sizeof(data->long_exe_q));	// �ż���������
	out->short_exe_q = Str2Int(data->short_exe_q, sizeof(data->short_exe_q));	// �ŵ���������
	out->long_traded_amt = Str2Dbl(data->long_traded_amt, sizeof(data->long_traded_amt), 0);	// �ż��������
	out->short_traded_amt = Str2Dbl(data->short_traded_amt, sizeof(data->short_traded_amt), 0);	// �ŵ��������
	out->spread_long_exe_q = Str2Int(data->spread_long_exe_q, sizeof(data->spread_long_exe_q));	// �������忡 ���� ������ �ż� ��������
	out->spread_short_exe_q = Str2Int(data->spread_short_exe_q, sizeof(data->spread_short_exe_q));	// �������忡 ���� ������ �ŵ� ��������
	out->spread_long_traded_amt = Str2Dbl(data->spread_long_traded_amt, sizeof(data->spread_long_traded_amt), 0);	// �������忡 ���� ������ �ż� �������
	out->spread_short_traded_amt = Str2Dbl(data->spread_short_traded_amt, sizeof(data->spread_short_traded_amt), 0);	// �������忡 ���� ������ �ŵ� �������

	return 1;
}


// ��ǰ����_�ü�Recovery ������
int ParseB2016(const double& timestamp, const char* in_buff, DF_COM_FUT_RECOVERY_DATA* out) {
	COM_FUT_RECOVERY_DATA* data = (COM_FUT_RECOVERY_DATA*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����,B2
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������,01:��ǰ����
	out->mrk_clsf = data->mrk_clsf[0];	//���屸��,6
	memcpy(out->isin_clsf, data->isin_clsf, sizeof(data->isin_clsf));	// �����ڵ�,*���߰��̵� ���� : �ű�ä���� �߰�
	out->stk_snr = Str2Int(data->stk_snr, sizeof(data->stk_snr));	// �����Ϸù�ȣ
	out->cur_prc = Str2SignDouble(data->cur_prc_sign, sizeof(data->cur_prc_sign) + sizeof(data->cur_prc), 2);	// ���簡,��) 999999.99
	out->rct_prd_prc = Str2Dbl(data->rct_prd_prc, sizeof(data->rct_prd_prc), 2);	// �ֱٿ���������������,��) 999999.99
	out->nxt_prd_prc = Str2Dbl(data->nxt_prd_prc, sizeof(data->nxt_prd_prc), 2);	// ������������������,��) 999999.99
	out->init_prc = Str2SignDouble(data->init_prc_sign, sizeof(data->init_prc_sign) + sizeof(data->init_prc), 2);	// �ð�,��) 999999.99
	out->high_prc = Str2SignDouble(data->high_prc_sign, sizeof(data->high_prc_sign) + sizeof(data->high_prc), 2);	// ��,��) 999999.99
	out->low_prc = Str2SignDouble(data->low_prc_sign, sizeof(data->low_prc_sign) + sizeof(data->low_prc), 2);	// ����,��) 999999.99
	out->open_interest_q = Str2Int(data->open_interest_q, sizeof(data->open_interest_q));	// �̰�����
	out->accm_exe_q = Str2Int(data->accm_exe_q, sizeof(data->accm_exe_q));	// ����ü�����
	out->accm_trd_amt = Str2Dbl(data->accm_trd_amt, sizeof(data->accm_trd_amt), 0);	// �����ŷ����,����:��
	out->l_or_s = data->l_or_s[0];	//�����ŵ��ż������ڵ�,1:�ŵ�,2:�ż�(�������� ���� ȣ���� �ŵ��ż����а�)
	out->s_lvl_1_prc = Str2SignDouble(data->s_lvl_1_sign, sizeof(data->s_lvl_1_sign) + sizeof(data->s_lvl_1_prc), 2);	// �ŵ�1ȣ��,��) 999999.99
	out->s_lvl_1_q = Str2Int(data->s_lvl_1_q, sizeof(data->s_lvl_1_q));	// �ŵ�1ȣ������
	out->s_lvl_1_trd_cnt = Str2Int(data->s_lvl_1_trd_cnt, sizeof(data->s_lvl_1_trd_cnt));	// �ŵ�1ȣ���Ǽ�
	out->l_lvl_1_prc = Str2SignDouble(data->l_lvl_1_sign, sizeof(data->l_lvl_1_sign) + sizeof(data->l_lvl_1_prc), 2);	// �ż�1ȣ��,��) 999999.99
	out->l_lvl_1_q = Str2Int(data->l_lvl_1_q, sizeof(data->l_lvl_1_q));	// �ż�1ȣ������
	out->l_lvl_1_trd_cnt = Str2Int(data->l_lvl_1_trd_cnt, sizeof(data->l_lvl_1_trd_cnt));	// �ż�1ȣ���Ǽ�
	out->s_lvl_2_prc = Str2SignDouble(data->s_lvl_2_sign, sizeof(data->s_lvl_2_sign) + sizeof(data->s_lvl_2_prc), 2);	// �ŵ�2ȣ��,��) 999999.99
	out->s_lvl_2_q = Str2Int(data->s_lvl_2_q, sizeof(data->s_lvl_2_q));	// �ŵ�2ȣ������
	out->s_lvl_2_trd_cnt = Str2Int(data->s_lvl_2_trd_cnt, sizeof(data->s_lvl_2_trd_cnt));	// �ŵ�2ȣ���Ǽ�
	out->l_lvl_2_prc = Str2SignDouble(data->l_lvl_2_sign, sizeof(data->l_lvl_2_sign) + sizeof(data->l_lvl_2_prc), 2);	// �ż�2ȣ��,��) 999999.99
	out->l_lvl_2_q = Str2Int(data->l_lvl_2_q, sizeof(data->l_lvl_2_q));	// �ż�2ȣ������
	out->l_lvl_2_trd_cnt = Str2Int(data->l_lvl_2_trd_cnt, sizeof(data->l_lvl_2_trd_cnt));	// �ż�2ȣ���Ǽ�
	out->s_lvl_3_prc = Str2SignDouble(data->s_lvl_3_sign, sizeof(data->s_lvl_3_sign) + sizeof(data->s_lvl_3_prc), 2);	// �ŵ�3ȣ��,��) 999999.99
	out->s_lvl_3_q = Str2Int(data->s_lvl_3_q, sizeof(data->s_lvl_3_q));	// �ŵ�3ȣ������
	out->s_lvl_3_trd_cnt = Str2Int(data->s_lvl_3_trd_cnt, sizeof(data->s_lvl_3_trd_cnt));	// �ŵ�3ȣ���Ǽ�
	out->l_lvl_3_prc = Str2SignDouble(data->l_lvl_3_sign, sizeof(data->l_lvl_3_sign) + sizeof(data->l_lvl_3_prc), 2);	// �ż�3ȣ��,��) 999999.99
	out->l_lvl_3_q = Str2Int(data->l_lvl_3_q, sizeof(data->l_lvl_3_q));	// �ż�3ȣ������
	out->l_lvl_3_trd_cnt = Str2Int(data->l_lvl_3_trd_cnt, sizeof(data->l_lvl_3_trd_cnt));	// �ż�3ȣ���Ǽ�
	out->s_lvl_4_prc = Str2SignDouble(data->s_lvl_4_sign, sizeof(data->s_lvl_4_sign) + sizeof(data->s_lvl_4_prc), 2);	// �ŵ�4ȣ��,��) 999999.99
	out->s_lvl_4_q = Str2Int(data->s_lvl_4_q, sizeof(data->s_lvl_4_q));	// �ŵ�4ȣ������
	out->s_lvl_4_trd_cnt = Str2Int(data->s_lvl_4_trd_cnt, sizeof(data->s_lvl_4_trd_cnt));	// �ŵ�4ȣ���Ǽ�
	out->l_lvl_4_prc = Str2SignDouble(data->l_lvl_4_sign, sizeof(data->l_lvl_4_sign) + sizeof(data->l_lvl_4_prc), 2);	// �ż�4ȣ��,��) 999999.99
	out->l_lvl_4_q = Str2Int(data->l_lvl_4_q, sizeof(data->l_lvl_4_q));	// �ż�4ȣ������
	out->l_lvl_4_trd_cnt = Str2Int(data->l_lvl_4_trd_cnt, sizeof(data->l_lvl_4_trd_cnt));	// �ż�4ȣ���Ǽ�
	out->s_lvl_5_prc = Str2SignDouble(data->s_lvl_5_sign, sizeof(data->s_lvl_5_sign) + sizeof(data->s_lvl_5_prc), 2);	// �ŵ�5ȣ��,��) 999999.99
	out->s_lvl_5_q = Str2Int(data->s_lvl_5_q, sizeof(data->s_lvl_5_q));	// �ŵ�5ȣ������
	out->s_lvl_5_trd_cnt = Str2Int(data->s_lvl_5_trd_cnt, sizeof(data->s_lvl_5_trd_cnt));	// �ŵ�5ȣ���Ǽ�
	out->l_lvl_5_prc = Str2SignDouble(data->l_lvl_5_sign, sizeof(data->l_lvl_5_sign) + sizeof(data->l_lvl_5_prc), 2);	// �ż�5ȣ��,��) 999999.99
	out->l_lvl_5_q = Str2Int(data->l_lvl_5_q, sizeof(data->l_lvl_5_q));	// �ż�5ȣ������
	out->l_lvl_5_trd_cnt = Str2Int(data->l_lvl_5_trd_cnt, sizeof(data->l_lvl_5_trd_cnt));	// �ż�5ȣ���Ǽ�
	out->total_s_limit_ord_q = Str2Int(data->total_s_limit_ord_q, sizeof(data->total_s_limit_ord_q));	// �ŵ� ��ȣ������
	out->total_s_trd_cnt = Str2Int(data->total_s_trd_cnt, sizeof(data->total_s_trd_cnt));	// �ŵ���ȿȣ���Ǽ�
	out->total_l_limit_ord_q = Str2Int(data->total_l_limit_ord_q, sizeof(data->total_l_limit_ord_q));	// �ż� ��ȣ������
	out->total_l_trd_cnt = Str2Int(data->total_l_trd_cnt, sizeof(data->total_l_trd_cnt));	// �ż���ȿȣ���Ǽ�
	memcpy(out->ss_id, data->ss_id, sizeof(data->ss_id));	// ����ID,�ڵ尪��������
	memcpy(out->brd_id, data->brd_id, sizeof(data->brd_id));	// ����ID,�ڵ尪��������
	memcpy(out->brd_event_id, data->brd_event_id, sizeof(data->brd_event_id));	// �����̺�ƮID,B2 ������ �����̺�ƮID ������(���� ���°��� ���۵� �� ����). ����, �ش� �׸� '000' ���� ����. 2014.03.24)
	out->exp_prc = Str2SignDouble(data->exp_prc_sign, sizeof(data->exp_prc_sign) + sizeof(data->exp_prc), 2);	// ����ü�ᰡ��,��) 999999.99 ���ϰ��ŸŽø� ����\n (����±����ڵ�:10,20,30,80)
	out->real_t_high_prc = Str2SignDouble(data->real_t_high_prc_sign, sizeof(data->real_t_high_prc_sign) + sizeof(data->real_t_high_prc), 2);	// �ǽð����Ѱ�,��) 999999.99 ���߰��̵�����
	out->real_t_low_prc = Str2SignDouble(data->real_t_low_prc_sign, sizeof(data->real_t_low_prc_sign) + sizeof(data->real_t_low_prc), 2);	// �ǽð����Ѱ�,��) 999999.99 ���߰��̵�����

	return 1;
}


// ��ǰ����_�������� ������
int ParseA0016(const double& timestamp, const char* in_buff, DF_COM_FUTRE_PRD_INFO_DATA* out) {
	COM_FUTRE_PRD_INFO_DATA* data = (COM_FUTRE_PRD_INFO_DATA*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����,A0
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������,01:��ǰ����
	out->mrk_clsf = data->mrk_clsf[0];	//���屸��,6
	out->prd_cnt = Str2Int(data->prd_cnt, sizeof(data->prd_cnt));	// �����
	memcpy(out->trd_date, data->trd_date, sizeof(data->trd_date));	// ��������(��ȸ����)
	memcpy(out->isin_clsf, data->isin_clsf, sizeof(data->isin_clsf));	// �����ڵ�,���� record '999999999999' set\n*���߰��̵� ���� : �ű�ä���� �߰�
	out->stk_snr = Str2Int(data->stk_snr, sizeof(data->stk_snr));	// ����SEQ
	memcpy(out->prd_id, data->prd_id, sizeof(data->prd_id));	// ��ǰID,* �ڵ尪 ������ ����\n* ����Ī: �Ļ���ǰID\n10 => 11, 20140303
	memcpy(out->sh_prd_code, data->sh_prd_code, sizeof(data->sh_prd_code));	// ��������ڵ�,��) KR4101C90009 �� K101C9000
	memcpy(out->prd_name_kor, data->prd_name_kor, sizeof(data->prd_name_kor));	// �����ѱ۸�
	memcpy(out->sh_prd_name_kor, data->sh_prd_name_kor, sizeof(data->sh_prd_name_kor));	// �����ѱ۾��
	memcpy(out->prd_name_eng, data->prd_name_eng, sizeof(data->prd_name_eng));	// ���񿵹���
	memcpy(out->sh_prd_name_eng, data->sh_prd_name_eng, sizeof(data->sh_prd_name_eng));	// ���񿵹����
	memcpy(out->listing_date, data->listing_date, sizeof(data->listing_date));	// ��������,*���߰��̵� �����߰�	2009.08.31
	memcpy(out->de_listing_date, data->de_listing_date, sizeof(data->de_listing_date));	// ������������
	out->spread_clsf_code = data->spread_clsf_code[0];	//��������������񱸺��ڵ�,���������� ������ �Ǵ� ������ ISIN ǥ���ڵ�\n--�ڵ尪--\nF: ������(�ð���������)\nN: �ٿ���(�ð���������)\n20140303
	out->final_sett_code = data->final_sett_code[0];	//������������ڵ�,���ݰ���, �ǹ��μ������� �� �Ļ���ǰ�� �������� ���\n--�ڵ尪--\nC: ���ݰ���\nD: �ǹ��μ�������\nA: ����+�ǹ��μ�������\n0: �ش����\n20140303
	out->prc_limit_exp_dir = data->prc_limit_exp_dir[0];	//��������Ȯ����������ڵ�,���������� �ٴܰ�� ���ǵǴ� ��� ���� �ܰ�� Ȯ��Ǵ� ����� ������ �� Ȯ�븦 �����ϴ� ����\n## �ڵ尪##\nX:������\nF:������\nB:������\nT:�����
	out->prc_limit_final_stg = Str2Int(data->prc_limit_final_stg, sizeof(data->prc_limit_final_stg));	// �������������ܰ�,���������� �ٴܰ�� ���ǵǴ� ��� ������ �����ܰ��ȣ
	out->prc_limit_stg_1_high_prc = Str2SignDouble(data->prc_limit_stg_1_hgh_sign, sizeof(data->prc_limit_stg_1_hgh_sign) + sizeof(data->prc_limit_stg_1_high_prc), 2);	// ��������1�ܰ���Ѱ�,��) 9999999999.99
	out->prc_limit_stg_1_low_prc = Str2SignDouble(data->prc_limit_stg_1_low_sign, sizeof(data->prc_limit_stg_1_low_sign) + sizeof(data->prc_limit_stg_1_low_prc), 2);	// ��������1�ܰ����Ѱ�,��) 9999999999.99
	out->prc_limit_stg_2_high_prc = Str2SignDouble(data->prc_limit_stg_2_high_sign, sizeof(data->prc_limit_stg_2_high_sign) + sizeof(data->prc_limit_stg_2_high_prc), 2);	// ��������2�ܰ���Ѱ�,��) 9999999999.99
	out->prc_limit_stg_2_low_prc = Str2SignDouble(data->prc_limit_stg_2_low_sign, sizeof(data->prc_limit_stg_2_low_sign) + sizeof(data->prc_limit_stg_2_low_prc), 2);	// ��������2�ܰ����Ѱ�,��) 9999999999.99
	out->prc_limit_stg_3_high_prc = Str2SignDouble(data->prc_limit_stg_3_high_sign, sizeof(data->prc_limit_stg_3_high_sign) + sizeof(data->prc_limit_stg_3_high_prc), 2);	// ��������3�ܰ���Ѱ�,��) 9999999999.99
	out->prc_limit_stg_3_low_prc = Str2SignDouble(data->prc_limit_stg_3_low_sign, sizeof(data->prc_limit_stg_3_low_sign) + sizeof(data->prc_limit_stg_3_low_prc), 2);	// ��������3�ܰ����Ѱ�,��) 9999999999.99
	out->stand_prc = Str2Dbl(data->stand_prc, sizeof(data->stand_prc), 2);	// ���ذ�,��) 9999999999.99
	memcpy(out->under_asset_id, data->under_asset_id, sizeof(data->under_asset_id));	// �����ڻ�ID,��) K2I:KOSPI200����, KQI:�ڽ���150����,\n   Sxx:�����ֽ�, BM3:��3�ⱹä,\n   BM5:��5�ⱹä, BMA:��10�ⱹä, \n   CDR:CD, USD:�̱��޷�, JPY:�Ϻ���,\n   EUR:��������,\n   GLD:��, LHG:����\n20140303
	out->opt_type_code = data->opt_type_code[0];	//�Ǹ���������ڵ�,A:�̱���,E:������,B:���´���,Z:��Ÿ\n20140303
	memcpy(out->spread_str_code, data->spread_str_code, sizeof(data->spread_str_code));	// �������屸���ڵ�,Combination ȣ���� ��ü�� �������幰�� ���񱸼�.\n--�ڵ尪--\n- T1: �ֱٿ���+2°����\n	  > T2, T3, T4, ...\n*����Ī: �������������ڵ�\n20140303
	memcpy(out->spread_prd_code_1, data->spread_prd_code_1, sizeof(data->spread_prd_code_1));	// �������屸�������ڵ�1,* ����Ī: ��������ٿ��� �����ڵ�\n�ٿ��� ǥ���ڵ�\n20140303
	memcpy(out->spread_prd_code_2, data->spread_prd_code_2, sizeof(data->spread_prd_code_2));	// �������屸�������ڵ�2,* ����Ī : ������������� �����ڵ�\n������ ǥ���ڵ�\n20140303
	memcpy(out->last_trading_date, data->last_trading_date, sizeof(data->last_trading_date));	// �����ŷ�����
	memcpy(out->final_sett_date, data->final_sett_date, sizeof(data->final_sett_date));	// ������������
	out->cont_month_nbr = Str2Int(data->cont_month_nbr, sizeof(data->cont_month_nbr));	// ��������ȣ,* ����Ī: ���������ڵ�\n1:�ֱٿ���,������������\n2:2°����\n3:3°����\n4:4°����\n5:5°����\n6:6°����\n7:7°����	  �� �ֱٿ������� ��ġ\nX => 9, 1 => 3, 20140303
	memcpy(out->maturity_date, data->maturity_date, sizeof(data->maturity_date));	// ��������,�Ǹ���� ������ ��������
	out->exe_prc = Str2Dbl(data->exe_prc, sizeof(data->exe_prc), 8);	// ��簡��,��) 999999999.99999999
	out->adjust_clsf_code = data->adjust_clsf_code[0];	//���������ڵ�,�����ڻ��� ���ذ��� ������ ����� ����(�̰�������)���� ������� ����(�ŷ��¼�����)������ ����\n--�ڵ尪--\nN: ����\nO: �̰�������\nC: �ŷ��¼�����\n20140303
	out->prd_unit = Str2Dbl(data->prd_unit, sizeof(data->prd_unit), 8);	// �ŷ�����,1��࿡ �ش��ϴ� �����ڻ����\n��) 999999999.99999999
	out->multiplier = Str2Dbl(data->multiplier, sizeof(data->multiplier), 8);	// �ŷ��¼�,������� �� ������ ����ϴ� ���¼�\n��) 9999999999999.99999999
	out->mrk_cnst_code = data->mrk_cnst_code[0];	//�������������ڵ�,0:�̽�����������\n1:���Ͻ�����������\n2:���Ž�����������
	out->listing_type_code = data->listing_type_code[0];	//���������ڵ�,1:�űԻ���\n2:�߰�����\n3:��������\n4:���ʻ���\n5:��������\n6:Ư������
	out->atm_prc = Str2Dbl(data->atm_prc, sizeof(data->atm_prc), 2);	// ���,�����ڻ���ذ��ݿ� ���� ����� ��簡��\n��) 9999999999.99
	memcpy(out->adj_reason_code, data->adj_reason_code, sizeof(data->adj_reason_code));	// ���������ڵ�,00:�ش���׾���, 01:�Ǹ���, 02:����,\n03:�й��, 04:�ǹ��, 05:�߰�����,\n06:�Ǹ��߰�����, 99:��Ÿ
	memcpy(out->under_asset_prd_code, data->under_asset_prd_code, sizeof(data->under_asset_prd_code));	// �����ڻ������ڵ�
	out->under_asset_close_prc = Str2Dbl(data->under_asset_close_prc, sizeof(data->under_asset_close_prc), 2);	// �����ڻ�����,��) 9999999999.99
	out->left_until_maturity = Str2Int(data->left_until_maturity, sizeof(data->left_until_maturity));	// �����ϼ�
	out->adj_std_prc = Str2Dbl(data->adj_std_prc, sizeof(data->adj_std_prc), 8);	// �������ذ���,�ֽ��Ļ���ǰ�� �����ֱ� �������ذ���\n��) 999999999.99999999
	memcpy(out->std_prc_clsf_code, data->std_prc_clsf_code, sizeof(data->std_prc_clsf_code));	// ���ذ��ݱ����ڵ�,*����\nspcace:���ذ� ����(���� ������������)\n11:�������갡\n12:���ϱ��ذ�(�ŷ������� ����������)\n13:�����̷а�(�ŷ������� ����������)\n14:���ϱ⼼(�ŷ������� �⼼����)\n  -2012.05.14 ����\n15:�����̷а�(�ŷ������� �⼼����)-\n  -2012.05.14 ����\n16:������ �������갡\n17:������ ���ϱ��ذ�\n  (�ŷ������� ����������)\n18:������ ���ϱ⼼(�ŷ������� �⼼����)\n  -2012.05.14 ����\n19:���� ����ڻ� ����(�̷а����� ��ǰ)\n*�ɼ�\n21:�������űݱ��ذ�\n22:���ϱ��ذ�(�ŷ������� ����������)\n23:�����̷а�(�ŷ������� ����������)\n24:���ϱ⼼(�ŷ������� �⼼����)\n  -2012.05.14 ����\n25:������ �������űݱ��ذ�\n26:������ ���ϱ��ذ�\n  (�ŷ������� ����������)\n27:������ ���ϱ⼼(�ŷ������� �⼼����)\n  -2012.05.14 ����
	out->trd_std_prc_clsf_code = data->trd_std_prc_clsf_code[0];	//�Ÿſ���ذ��ݱ����ڵ�,0:�ش����\n1:�Ǽ�\n2:�⼼\n3:�̷а�\n4:����ڻ�����\n*���߰��̵� �����߰�	2009.08.31
	out->yest_adj_close_prc = Str2SignDouble(data->yest_adj_close_prc_sign, sizeof(data->yest_adj_close_prc_sign) + sizeof(data->yest_adj_close_prc), 8);	// ������������,�ֽ��Ļ���ǰ�� ��������\n��) 999999999.99999999
	out->block_trd_clsf = data->block_trd_clsf[0];	//���Ǵ뷮�ŸŴ�󿩺�,Y:���ǸŸŻ�ǰ, N:���ƴ�\n����ǰ��:3�⹰��ä����, �̱��޷�����,\n	  ���μ���, ������
	out->yest_mrg_std_prc = Str2Dbl(data->yest_mrg_std_prc, sizeof(data->yest_mrg_std_prc), 8);	// �������űݱ��ذ���,��) 999999999.99999999
	memcpy(out->yest_mrg_std_prc_clsf_code, data->yest_mrg_std_prc_clsf_code, sizeof(data->yest_mrg_std_prc_clsf_code));	// �������űݱ��ذ��ݱ����ڵ�,*�ɼ�\n20:���ű� ���ذ� ����\n21:��������(�Ǽ�)\n22:���ϱ⼼(�ŷ������ı⼼)\n  -2012.05.14 ����\n23:�������űݱ��ذ�\n  (�ŷ������� ����������)\n  -2012.05.14 ����\n24:�����̷а�(�ŷ������� ����������)\n25:�����������űݱ��ذ�\n  (�ŷ������� ����������)\n  -2012.05.14 ����
	out->sett_theory_prc = Str2Dbl(data->sett_theory_prc, sizeof(data->sett_theory_prc), 6);	// �����̷а���,�ؿɼ��� ��� ���űݱ��ذ��� \n��) 999999999.999999
	out->std_theory_prc = Str2Dbl(data->std_theory_prc, sizeof(data->std_theory_prc), 6);	// �����̷а���,��) 999999999.999999
	out->yest_sett_prc = Str2Dbl(data->yest_sett_prc, sizeof(data->yest_sett_prc), 8);	// �������갡��,��) 999999999.99999999
	out->halt_trd_clsf = data->halt_trd_clsf[0];	//�ŷ���������,Y, N
	out->ft_cb_high_prc = Str2Dbl(data->ft_cb_high_prc, sizeof(data->ft_cb_high_prc), 2);	// ����Circuit_Breakers���Ѱ�,���� CB �ߵ������� �Ǵ��ϱ� ���� ����\n����(���ذ���� +/-5%�� CB �ߵ�\n������ ��� +5%�� ����� ����)\n��) 99+F31499999999.99
	out->ft_cb_low_prc = Str2Dbl(data->ft_cb_low_prc, sizeof(data->ft_cb_low_prc), 2);	// ����Circuit_Breakers���Ѱ�,���� CB �ߵ������� �Ǵ��ϱ� ���� ����\n����(���ذ���� +/-5%�� CB �ߵ�\n������ ��� -5%�� ����� ����)\n��) 9999999999.99
	out->check_exe_prc = Str2Dbl(data->check_exe_prc, sizeof(data->check_exe_prc), 8);	// ��ȸ����簡��,��) 999999999.99999999
	out->atm_clsf = data->atm_clsf[0];	//ATM�����ڵ�,0:����, 1:ATM, 2:ITM, 3:OTM
	out->last_trading_clsf = data->last_trading_clsf[0];	//�����ŷ��Ͽ���,Y, N
	out->ex_divid_aft_value = Str2Dbl(data->ex_divid_aft_value, sizeof(data->ex_divid_aft_value), 6);	// �����Ĺ�簡ġ,�ֽ� �� �ְ����� ��ǰ���� �����\n- ���� : �����Ĺ̷���ġ\n- �ɼ� : ���������簡ġ\n��) 999999999.999999
	out->yest_close_prc = Str2SignDouble(data->yest_close_prc_sign, sizeof(data->yest_close_prc_sign) + sizeof(data->yest_close_prc), 2);	// ��������,��) 9999999999.99
	out->yest_close_prc_clsf = data->yest_close_prc_clsf[0];	//�������������ڵ�,1:�Ǽ�, 3:�ŷ���\n2:�⼼ -2012.05.14 ����
	out->yest_init_prc = Str2SignDouble(data->yest_init_prc_sign, sizeof(data->yest_init_prc_sign) + sizeof(data->yest_init_prc), 2);	// ���Ͻð�,��) 9999999999.99
	out->yest_high_pric = Str2SignDouble(data->yest_high_prc_sign, sizeof(data->yest_high_prc_sign) + sizeof(data->yest_high_pric), 2);	// ���ϰ�,��) 9999999999.99
	out->yest_low_prc = Str2SignDouble(data->yest_low_prc_sign, sizeof(data->yest_low_prc_sign) + sizeof(data->yest_low_prc), 2);	// ��������,��) 9999999999.99
	memcpy(out->yest_first_exe_date, data->yest_first_exe_date, sizeof(data->yest_first_exe_date));	// ����ü������
	memcpy(out->yest_last_exe_time, data->yest_last_exe_time, sizeof(data->yest_last_exe_time));	// ��������ü��ð�
	memcpy(out->yest_sett_prc_clsf, data->yest_sett_prc_clsf, sizeof(data->yest_sett_prc_clsf));	// �������갡�ݱ���,*����\n 10:���갡����\n 11:��������(�Ǽ�)\n 12:���ϱ⼼(�ŷ������ı⼼) - 2010.12.20 ����\n 13:�������갡(�ŷ������� ����������) - 2010.12.20 ����\n 14:�����̷а�(�ŷ������� ����������)\n 15:��������� ���� - 2010.12.20 ����\n 16:������ ���� ���갡 - 2010.12.20 ����\n 17:����ڻ� ����(�̷а����� ��ǰ)\n 18:������ذ��� - 2010.12.20 �߰�
	out->sett_prc_theory_prc_diff_pctg = Str2SignDouble(data->sett_prc_theory_prc_diff_pctg_sign, sizeof(data->sett_prc_theory_prc_diff_pctg_sign) + sizeof(data->sett_prc_theory_prc_diff_pctg), 6);	// ���갡���̷а��ݱ�����,��) 999999.999999
	out->yest_open_interest_q = Str2Dbl(data->yest_open_interest_q, sizeof(data->yest_open_interest_q), 0);	// ���Ϲ̰�����������
	out->yest_s_limit_ord_prc = Str2SignDouble(data->yest_s_limit_ord_prc_sign, sizeof(data->yest_s_limit_ord_prc_sign) + sizeof(data->yest_s_limit_ord_prc), 2);	// ���ϸŵ��켱ȣ������,��) 9999999999.99
	out->yest_l_limit_ord_prc = Str2SignDouble(data->yest_l_limit_ord_prc_sign, sizeof(data->yest_l_limit_ord_prc_sign) + sizeof(data->yest_l_limit_ord_prc), 2);	// ���ϸż��켱ȣ������,��) 9999999999.99
	out->implied_vol = Str2Dbl(data->implied_vol, sizeof(data->implied_vol), 4);	// ���纯����,��) 999999.9999
	out->listed_high_prc = Str2SignDouble(data->listed_high_prc_sign, sizeof(data->listed_high_prc_sign) + sizeof(data->listed_high_prc), 2);	// �������ְ�,��) 9999999999.99
	out->listed_low_prc = Str2SignDouble(data->listed_low_prc_sign, sizeof(data->listed_low_prc_sign) + sizeof(data->listed_low_prc), 2);	// ������������,��) 9999999999.99
	out->year_high_prc = Str2SignDouble(data->year_high_prc_sign, sizeof(data->year_high_prc_sign) + sizeof(data->year_high_prc), 2);	// �����ְ�,��) 9999999999.99
	out->year_low_prc = Str2SignDouble(data->year_low_prc_sign, sizeof(data->year_low_prc_sign) + sizeof(data->year_low_prc), 2);	// ����������,��) 9999999999.99
	memcpy(out->listed_high_prc_date, data->listed_high_prc_date, sizeof(data->listed_high_prc_date));	// �������ְ�����
	memcpy(out->listed_low_prc_date, data->listed_low_prc_date, sizeof(data->listed_low_prc_date));	// ����������������
	memcpy(out->year_high_prc_date, data->year_high_prc_date, sizeof(data->year_high_prc_date));	// �����ְ�����
	memcpy(out->year_low_prc_date, data->year_low_prc_date, sizeof(data->year_low_prc_date));	// ��������������
	out->year_std_date = Str2Int(data->year_std_date, sizeof(data->year_std_date));	// ���������ϼ�
	out->month_trd_date = Str2Int(data->month_trd_date, sizeof(data->month_trd_date));	// �����ŷ��ϼ�
	out->year_trd_date = Str2Int(data->year_trd_date, sizeof(data->year_trd_date));	// �����ŷ��ϼ�
	out->yest_exe_trd_cnt  = Str2Dbl(data->yest_exe_trd_cnt , sizeof(data->yest_exe_trd_cnt ), 0);	// ����ü��Ǽ�
	out->yest_exe_q = Str2Dbl(data->yest_exe_q, sizeof(data->yest_exe_q), 0);	// ����ü�����,�������Ǵ뷮�Ÿ�ü������� ���Ե��� ����
	out->yest_trd_amt = Str2Dbl(data->yest_trd_amt, sizeof(data->yest_trd_amt), 0);	// ���ϰŷ����,�������Ǵ뷮�ŸŰŷ������ ���Ե��� ����
	out->yest_block_trd_exe_q = Str2Dbl(data->yest_block_trd_exe_q, sizeof(data->yest_block_trd_exe_q), 0);	// �������Ǵ뷮�ջ�ü�����,�������Ǵ뷮�Ÿ�ü����� => �������Ǵ뷮�ջ�ü����� [����ü�����+�������Ǵ뷮�Ÿ�ü�����(���Ǵ뷮+FLEX)] 2016.03.28 ����
	out->yest_block_trd_total_amt = Str2Dbl(data->yest_block_trd_total_amt, sizeof(data->yest_block_trd_total_amt), 0);	// �������Ǵ뷮�ջ�ŷ����,�������Ǵ뷮�ŸŰŷ���� => �������Ǵ뷮�ջ�ŷ���� [���ϰŷ����+�������Ǵ뷮�ŸŰŷ����(���Ǵ뷮+FLEX)] 2016.03.28 ����
	out->cd_rate = Str2Dbl(data->cd_rate, sizeof(data->cd_rate), 3);	// CD�ݸ�,��) 999.999
	out->open_interest_q = Str2Dbl(data->open_interest_q, sizeof(data->open_interest_q), 0);	// �̰����ѵ�����,*�����Ͽ� ����Ǵ� ��ǰ�� ���º�\n �̰��� �ѵ� ����. �̰��� �ѵ���\n ������� ���� ��ǰ�� 0\n*�ֽļ������� �ش�\n8 => 15, 20140303
	memcpy(out->product_cat, data->product_cat, sizeof(data->product_cat));	// �Ҽ� ��ǰ��,*�ֽļ���/�ɼǿ��� �ش�
	out->product_cat_off_pctg = Str2Dbl(data->product_cat_off_pctg, sizeof(data->product_cat_off_pctg), 2);	// ��ǰ�� �ɼ���,*������� ǥ��\n*�ֽļ���/�ɼǿ��� �ش翹) 9999999.99\n5 => 9, 20140303
	out->limit_ord_clsf_code = Str2Int(data->limit_ord_clsf_code, sizeof(data->limit_ord_clsf_code));	// ������ȣ�����Ǳ����ڵ�,ȣ���� ü�� �� �ܷ�����. Bitwise ����\n--�ڵ尪--\n1: FAS (Fill And Store)\n2: FOK (Fill Or Kill)\n3: FAK (Fill And Kill)\n\n* ������ȣ�����Ǳ����ڵ� BITWISE ����\n���� Ȯ�强�� ���� �ش� 10�������� 2������ ��ȯ�Ͽ� ó�����(�ִ� 16bit���� ��밡��)\n�� ) ������ȣ�����Ǳ����ڵ� ���� 6�̸�\n	(������ 6 -> ������ 00000110)\n0��° bit 0 -> 0 : FAS\n1��° bit 1 -> 2 : FOK\n2��° bit 1 -> 4 : FAK\n��, FOK�̸鼭 FAK�� �����Ѵٴ� �ǹ� (FOK & FAK)\nX => 9, 1 => 5, 20140303
	out->mrk_ord_clsf_code = Str2Int(data->mrk_ord_clsf_code, sizeof(data->mrk_ord_clsf_code));	// ���尡ȣ�����Ǳ����ڵ�,* ��
	out->cond_limit_ord_clsf_code = Str2Int(data->cond_limit_ord_clsf_code, sizeof(data->cond_limit_ord_clsf_code));	// ���Ǻ�������ȣ�����Ǳ����ڵ�,* ��
	out->best_limit_ord_clsf_code = Str2Int(data->best_limit_ord_clsf_code, sizeof(data->best_limit_ord_clsf_code));	// ������������ȣ�����Ǳ����ڵ�,* ��
	out->efp_clsf = data->efp_clsf[0];	//EFP�ŷ���󿩺�,Y, N, ��ǰ������ �ش�  2009.08.31
	out->flex_clsf = data->flex_clsf[0];	//FLEX�ŷ���󿩺�,Y, N, ��ǰ������ �ش�  2009.08.31
	out->yest_efp_exe_q = Str2Dbl(data->yest_efp_exe_q, sizeof(data->yest_efp_exe_q), 0);	// ����EFPü�����,��ǰ������ �ش�	   2009.08.31
	out->yest_efp_trd_amount = Str2Dbl(data->yest_efp_trd_amount, sizeof(data->yest_efp_trd_amount), 0);	// ����EFP�ŷ����,��ǰ������ �ش�	   2009.08.31
	out->mkr_close_clsf = data->mkr_close_clsf[0];	//���忩��,���忩�� (Y,N), 20121217
	out->real_t_prc_limit_clsf = data->real_t_prc_limit_clsf[0];	//�ǽð��������ѿ���,���� ü�ᰡ�� ��� Ư�� ������ �ʰ��ϴ� ȣ���� �ź��ϵ��� �������� ����(Y/N) 20140901
	out->real_t_high_price_gap = Str2SignDouble(data->real_t_high_price_gap_sign, sizeof(data->real_t_high_price_gap_sign) + sizeof(data->real_t_high_price_gap), 2);	// �ǽð����Ѱ�����,���� ü�ᰡ�ݰ� �ǽð����Ѱ����� ����\n�ǽð����Ѱ� = ����ü�ᰡ�� + �ǽð����Ѱ�����\nex) 9999999999.99 20140901
	out->real_t_low_price_gap = Str2SignDouble(data->real_t_low_price_gap_sign, sizeof(data->real_t_low_price_gap_sign) + sizeof(data->real_t_low_price_gap), 2);	// �ǽð����Ѱ�����,���� ü�ᰡ�ݰ� �ǽð����Ѱ����� ����\n�ǽð����Ѱ� = ����ü�ᰡ�� + �ǽð����Ѱ�����(����)\nex) 9999999999.99 20140901
	memcpy(out->under_ass_mrk_id, data->under_ass_mrk_id, sizeof(data->under_ass_mrk_id));	// �����ڻ����ID,�����ڻ����ID�� �����ڻ��� KRX�� ����� ��쿡�� ä����.\nK200�����ɼ�:STK\n�ڽ���150����:KSQ\n�ֽļ����ɼ�:STK/KSQ\n��ǰ�����ɼ�:SPACE\n��������������:STK\n������������:STK\n�̴�K200�����ɼ�:STK

	return 1;
}


// ��������_��ä_CD_������
int ParseH5016(const double& timestamp, const char* in_buff, DF_GOV_BOND_CD_DATA* out) {
	GOV_BOND_CD_DATA* data = (GOV_BOND_CD_DATA*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����,H5
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������,01:��ǰ����,\n���� record '99' set
	out->mrk_clsf = data->mrk_clsf[0];	//���屸��,6
	memcpy(out->send_date, data->send_date, sizeof(data->send_date));	// ��������,YYYYMMDD
	memcpy(out->send_time, data->send_time, sizeof(data->send_time));	// ���۽ð�,HHMMSS
	memcpy(out->uder_asset_clsf, data->uder_asset_clsf, sizeof(data->uder_asset_clsf));	// �����ڻ걸��,BM3,BM5,BMA,CD,MSB   2010.10.25\n*�׸�� ����\n �����ڻ�ID->�����ڻ걸��  2009.08.31\n*MSB�����ߴ�		  2011.05.02
	out->final_ord_return_pctg = Str2Dbl(data->final_ord_return_pctg, sizeof(data->final_ord_return_pctg), 5);	// ����ȣ�����ͷ�,999.99999\nCD(91��),��ä(3��,5��,10��)\n*MSB�����ߴ�		  2011.05.02
	memcpy(out->gov_bond_code, data->gov_bond_code, sizeof(data->gov_bond_code));	// ��ä�ڵ�,��ä������ �������ä���ڵ�
	memcpy(out->gov_bond_prd_code, data->gov_bond_prd_code, sizeof(data->gov_bond_prd_code));	// ��ä���������ڵ�
	memcpy(out->data_created_t, data->data_created_t, sizeof(data->data_created_t));	// ������ �߻��ð�,HHMMSS

	return 1;
}


// ��������_��������ä��_������
int ParseH6016(const double& timestamp, const char* in_buff, DF_STD_GOV_BOND_DATA* out) {
	STD_GOV_BOND_DATA* data = (STD_GOV_BOND_DATA*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����,H6
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������,01:��ǰ����,\n���� record '99' set
	out->mrk_clsf = data->mrk_clsf[0];	//���屸��,6
	memcpy(out->adj_date, data->adj_date, sizeof(data->adj_date));	// ������,�����ڷ� ���۵�
	memcpy(out->prd, data->prd, sizeof(data->prd));	// ��ǰ,BM3,BM5,BMA   2010.10.25
	memcpy(out->fut_prd_code, data->fut_prd_code, sizeof(data->fut_prd_code));	// ���������ڵ�,���� �ŷ� ����� ����
	memcpy(out->under_asset_bond_code, data->under_asset_bond_code, sizeof(data->under_asset_bond_code));	// ä���ڵ�,��ä������ �������ä���ڵ�
	out->conv_coef = Str2Dbl(data->conv_coef, sizeof(data->conv_coef), 6);	// ��ȯ���,�μ������� ��ä������ ��츸 �ش��\n��) 99.999999\n'00000000' ó��   2010.10.25

	return 1;
}


// ��������_USD_������
int ParseH9016(const double& timestamp, const char* in_buff, DF_USD_DATA* out) {
	USD_DATA* data = (USD_DATA*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����,H9
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������,01:��ǰ����,\n���� record '99' set
	out->mrk_clsf = data->mrk_clsf[0];	//���屸��,6
	memcpy(out->send_date, data->send_date, sizeof(data->send_date));	// ��������,YYYYMMDD
	memcpy(out->send_time, data->send_time, sizeof(data->send_time));	// ���۽ð�,HHMMSS
	memcpy(out->under_asset_id, data->under_asset_id, sizeof(data->under_asset_id));	// �����ڻ�ID,USD
	out->s_limit_ord_prc = Str2Dbl(data->s_limit_ord_prc, sizeof(data->s_limit_ord_prc), 2);	// �ŵ�ȣ��,��) 9999.99
	out->l_limit_ord_prc = Str2Int(data->l_limit_ord_prc, sizeof(data->l_limit_ord_prc));	// �ż�ȣ��
	out->yest_close_prc = Str2Int(data->yest_close_prc, sizeof(data->yest_close_prc));	// ��������
	out->init_prc = Str2Int(data->init_prc, sizeof(data->init_prc));	// �ð�
	out->low_prc = Str2Int(data->low_prc, sizeof(data->low_prc));	// ����
	out->high_prc = Str2Int(data->high_prc, sizeof(data->high_prc));	// ��
	out->exe_prc = Str2Int(data->exe_prc, sizeof(data->exe_prc));	// ü�ᰡ
	memcpy(out->data_created_t, data->data_created_t, sizeof(data->data_created_t));	// ������ �߻��ð�,HHMMSS

	return 1;
}


// ��������_USD��ġ_������1
int ParseI0016_FBB1(const double& timestamp, const char* in_buff, DF_USD_BATCH_DATA_1* out) {
	USD_BATCH_DATA_1* data = (USD_BATCH_DATA_1*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����,I0
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������,01:��ǰ����,\n���� record '99' set
	out->mrk_clsf = data->mrk_clsf[0];	//���屸��,6
	memcpy(out->job_clsf_code, data->job_clsf_code, sizeof(data->job_clsf_code));	// ���������ڵ�,FBB1(��/�޷� ���Ͻð��뺰 �ŷ���Ȳ)
	out->trd_date = Str2Int(data->trd_date, sizeof(data->trd_date));	// �ŷ���
	memcpy(out->trd_hour, data->trd_hour, sizeof(data->trd_hour));	// �ð���,HHMM-HHMM
	out->spread_low_rate = Str2Dbl(data->spread_low_rate, sizeof(data->spread_low_rate), 1);	// LOW RATE(SP),9999.9
	out->spread_high_rate = Str2Dbl(data->spread_high_rate, sizeof(data->spread_high_rate), 1);	// HIGH RATE(SP),9999.9
	out->spread_vol = Str2Dbl(data->spread_vol, sizeof(data->spread_vol), 1);	// VOLUME(SP),9999.9

	return 1;
}


// ��������_USD��ġ_������2
int ParseI0016_FBC1(const double& timestamp, const char* in_buff, DF_USD_BATCH_DATA_2* out) {
	USD_BATCH_DATA_2* data = (USD_BATCH_DATA_2*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����,I0
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������,01:��ǰ����,\n���� record '99' set
	out->mrk_clsf = data->mrk_clsf[0];	//���屸��,6
	memcpy(out->job_clsf_code, data->job_clsf_code, sizeof(data->job_clsf_code));	// ���������ڵ�,FBC1(��/�޷� ���� ���Ϲ��� ü����Ȳ1)
	out->trd_date = Str2Int(data->trd_date, sizeof(data->trd_date));	// �ŷ���,YYYYMMDD
	memcpy(out->fixed_date_clsf, data->fixed_date_clsf, sizeof(data->fixed_date_clsf));	// ���Ϲ�����,*���Ϲ����� ����
	out->maturity_date = Str2Int(data->maturity_date, sizeof(data->maturity_date));	// ������(������),YYYYMMDD
	out->low_rate = Str2Dbl(data->low_rate, sizeof(data->low_rate), 2);	// LOW RATE,9999.99
	out->high_rate = Str2Dbl(data->high_rate, sizeof(data->high_rate), 2);	// HIGH RATE,9999.99
	out->open_rate = Str2Dbl(data->open_rate, sizeof(data->open_rate), 2);	// OPEN RATE,9999.99
	out->close_rate = Str2Dbl(data->close_rate, sizeof(data->close_rate), 2);	// CLOSE RATE,9999.99

	return 1;
}


// ��������_USD��ġ_������3
int ParseI0016_FBC2(const double& timestamp, const char* in_buff, DF_USD_BATCH_DATA_3* out) {
	USD_BATCH_DATA_3* data = (USD_BATCH_DATA_3*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����,I0
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������,01:��ǰ����,\n���� record '99' set
	out->mrk_clsf = data->mrk_clsf[0];	//���屸��,6
	memcpy(out->job_clsf_code, data->job_clsf_code, sizeof(data->job_clsf_code));	// ���������ڵ�,FBC2(��/�޷� ���� ���Ϲ��� ü����Ȳ2)
	out->trd_date = Str2Int(data->trd_date, sizeof(data->trd_date));	// �ŷ���,YYYYMMDD
	memcpy(out->fixed_date_clsf, data->fixed_date_clsf, sizeof(data->fixed_date_clsf));	// ���Ϲ�����,*���Ϲ����� ����
	out->maturity_date = Str2Int(data->maturity_date, sizeof(data->maturity_date));	// ������(������),YYYYMMDD
	out->vol = Str2Dbl(data->vol, sizeof(data->vol), 1);	// VOLUME,9999.9
	out->avg_rate = Str2Dbl(data->avg_rate, sizeof(data->avg_rate), 2);	// AVERAGE RATE,9999.99
	out->mar = Str2Dbl(data->mar, sizeof(data->mar), 1);	// MAR,9999.9

	return 1;
}


// ��������_USD��ġ_������4
int ParseI0016_FBD1(const double& timestamp, const char* in_buff, DF_USD_BATCH_DATA_4* out) {
	USD_BATCH_DATA_4* data = (USD_BATCH_DATA_4*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����,I0
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������,01:��ǰ����,\n���� record '99' set
	out->mrk_clsf = data->mrk_clsf[0];	//���屸��,6
	memcpy(out->job_clsf_code, data->job_clsf_code, sizeof(data->job_clsf_code));	// ���������ڵ�,FBD1(ȯ����� ����ȯ�� ��Ȳ)
	out->informed_date = Str2Int(data->informed_date, sizeof(data->informed_date));	// �����,YYYYMMDD
	memcpy(out->currency_name, data->currency_name, sizeof(data->currency_name));	// ��ȭ��,��)��ȭ�� ����
	out->cross_rate = Str2Dbl(data->cross_rate, sizeof(data->cross_rate), 5);	// CROSS RATE,9999.99999
	out->fx_rate = Str2Dbl(data->fx_rate, sizeof(data->fx_rate), 2);	// ȯ��,9999.99

	return 1;
}


// ��������_USD��ġ_������5
int ParseI0016_FBE1(const double& timestamp, const char* in_buff, DF_USD_BATCH_DATA_5* out) {
	USD_BATCH_DATA_5* data = (USD_BATCH_DATA_5*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����,I0
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������,01:��ǰ����,\n���� record '99' set
	out->mrk_clsf = data->mrk_clsf[0];	//���屸��,6
	memcpy(out->job_clsf_code, data->job_clsf_code, sizeof(data->job_clsf_code));	// ���������ڵ�,FBE1(SWAP ������ ���Ϲ��� ü����Ȳ)
	out->trd_date = Str2Int(data->trd_date, sizeof(data->trd_date));	// �ŷ���,YYYYMMDD
	memcpy(out->fixed_date_clsf, data->fixed_date_clsf, sizeof(data->fixed_date_clsf));	// ���Ϲ�����,��)���Ϲ����� ����
	out->maturity_date = Str2Int(data->maturity_date, sizeof(data->maturity_date));	// ������(������),YYYYMMDD
	out->low_rate = Str2Int(data->low_rate, sizeof(data->low_rate));	// LOW RATE,��9999
	out->high_rate = Str2Int(data->high_rate, sizeof(data->high_rate));	// HIGH RATE,��9999
	out->open_rate = Str2Int(data->open_rate, sizeof(data->open_rate));	// OPEN RATE,��9999
	out->close_rate = Str2Int(data->close_rate, sizeof(data->close_rate));	// CLOSE RATE,��9999
	out->avg_rate = Str2Int(data->avg_rate, sizeof(data->avg_rate));	// AVERAGE RATE,��9999
	out->vol = Str2Dbl(data->vol, sizeof(data->vol), 1);	// VOLUME,9999.9

	return 1;
}


// ��������_USD��ġ_������6
int ParseI0016_FBF1(const double& timestamp, const char* in_buff, DF_USD_BATCH_DATA_6* out) {
	USD_BATCH_DATA_6* data = (USD_BATCH_DATA_6*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����,I0
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������,01:��ǰ����,\n���� record '99' set
	out->mrk_clsf = data->mrk_clsf[0];	//���屸��,6
	memcpy(out->job_clsf_code, data->job_clsf_code, sizeof(data->job_clsf_code));	// ���������ڵ�,FBF1(��/�޷� ����ȯ�� : ��ȭ����ȯ�����)
	out->std_date = Str2Int(data->std_date, sizeof(data->std_date));	// ������,YYYYMMDD
	memcpy(out->fixed_date_clsf_0, data->fixed_date_clsf_0, sizeof(data->fixed_date_clsf_0));	// ���Ϲ�����,��)����ȯ�����Ϲ����� ����
	out->rate_0 = Str2Dbl(data->rate_0, sizeof(data->rate_0), 2);	// RATE,9999.99
	memcpy(out->fixed_date_clsf_1, data->fixed_date_clsf_1, sizeof(data->fixed_date_clsf_1));	// ���Ϲ�����,��)����ȯ�����Ϲ����� ����
	out->rate_1 = Str2Dbl(data->rate_1, sizeof(data->rate_1), 2);	// RATE,9999.99
	memcpy(out->fixed_date_clsf_2, data->fixed_date_clsf_2, sizeof(data->fixed_date_clsf_2));	// ���Ϲ�����,��)����ȯ�����Ϲ����� ����
	out->rate_2 = Str2Dbl(data->rate_2, sizeof(data->rate_2), 2);	// RATE,9999.99
	memcpy(out->fixed_date_clsf_3, data->fixed_date_clsf_3, sizeof(data->fixed_date_clsf_3));	// ���Ϲ�����,��)����ȯ�����Ϲ����� ����
	out->rate_3 = Str2Dbl(data->rate_3, sizeof(data->rate_3), 2);	// RATE,9999.99

	return 1;
}


// ��������_USD��ġ_������7
int ParseI0016_FBF2(const double& timestamp, const char* in_buff, DF_USD_BATCH_DATA_7* out) {
	USD_BATCH_DATA_7* data = (USD_BATCH_DATA_7*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����,I0
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������,01:��ǰ����,\n���� record '99' set
	out->mrk_clsf = data->mrk_clsf[0];	//���屸��,6
	memcpy(out->job_clsf_code, data->job_clsf_code, sizeof(data->job_clsf_code));	// ���������ڵ�,FBF2(��/�޷� ���� ȯ�� : ��������Ʈ ���))
	out->std_date = Str2Int(data->std_date, sizeof(data->std_date));	// ������,YYYYMMDD
	memcpy(out->fixed_date_clsf_0, data->fixed_date_clsf_0, sizeof(data->fixed_date_clsf_0));	// ���Ϲ�����,��)����ȯ�����Ϲ����� ����
	out->rate_0 = Str2Dbl(data->rate_0, sizeof(data->rate_0), 2);	// RATE,9999.99
	memcpy(out->fixed_date_clsf_1, data->fixed_date_clsf_1, sizeof(data->fixed_date_clsf_1));	// ���Ϲ�����,��)����ȯ�����Ϲ����� ����
	out->rate_1 = Str2Dbl(data->rate_1, sizeof(data->rate_1), 2);	// RATE,9999.99
	memcpy(out->fixed_date_clsf_2, data->fixed_date_clsf_2, sizeof(data->fixed_date_clsf_2));	// ���Ϲ�����,��)����ȯ�����Ϲ����� ����
	out->rate_2 = Str2Dbl(data->rate_2, sizeof(data->rate_2), 2);	// RATE,9999.99
	memcpy(out->fixed_date_clsf_3, data->fixed_date_clsf_3, sizeof(data->fixed_date_clsf_3));	// ���Ϲ�����,��)����ȯ�����Ϲ����� ����
	out->rate_3 = Str2Dbl(data->rate_3, sizeof(data->rate_3), 2);	// RATE,9999.99

	return 1;
}


// ��������_USD��ġ_������8
int ParseI0016_FBG1(const double& timestamp, const char* in_buff, DF_USD_BATCH_DATA_8* out) {
	USD_BATCH_DATA_8* data = (USD_BATCH_DATA_8*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����,I0
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������,01:��ǰ����,\n���� record '99' set
	out->mrk_clsf = data->mrk_clsf[0];	//���屸��,6
	memcpy(out->job_clsf_code, data->job_clsf_code, sizeof(data->job_clsf_code));	// ���������ڵ�,FBG1(����� ����ȯ��)
	memcpy(out->informed_date, data->informed_date, sizeof(data->informed_date));	// �����,YYYYMMDD
	out->std_year_month = Str2Dbl(data->std_year_month, sizeof(data->std_year_month), 2);	// ���س��,9999.99
	out->avg_fx_rate = Str2Dbl(data->avg_fx_rate, sizeof(data->avg_fx_rate), 2);	// ��ձ���ȯ��,9999.99

	return 1;
}


// ��������_USD��ġ_������9
int ParseI0016_CBA1(const double& timestamp, const char* in_buff, DF_USD_BATCH_DATA_9* out) {
	USD_BATCH_DATA_9* data = (USD_BATCH_DATA_9*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����,I0
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������,01:��ǰ����,\n���� record '99' set
	out->mrk_clsf = data->mrk_clsf[0];	//���屸��,6
	memcpy(out->job_clsf_code, data->job_clsf_code, sizeof(data->job_clsf_code));	// ���������ڵ�,CBA1(��ȭ ���� �ŷ����1)
	memcpy(out->trd_date, data->trd_date, sizeof(data->trd_date));	// �ŷ���,YYYYMMDD
	memcpy(out->currency_name, data->currency_name, sizeof(data->currency_name));	// ��ȭ��,��)��ȭ�� ����
	out->open_rate = Str2Dbl(data->open_rate, sizeof(data->open_rate), 5);	// OPEN RATE,99.99999
	out->high_rate = Str2Dbl(data->high_rate, sizeof(data->high_rate), 5);	// HIGH RATE,99.99999
	out->low_rate = Str2Dbl(data->low_rate, sizeof(data->low_rate), 5);	// LOW RATE,99.99999
	out->close_rate = Str2Dbl(data->close_rate, sizeof(data->close_rate), 5);	// CLOSE RATE,99.99999

	return 1;
}


// ��������_USD��ġ_������10
int ParseI0016_CBA2(const double& timestamp, const char* in_buff, DF_USD_BATCH_DATA_10* out) {
	USD_BATCH_DATA_10* data = (USD_BATCH_DATA_10*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����,I0
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������,01:��ǰ����,\n���� record '99' set
	out->mrk_clsf = data->mrk_clsf[0];	//���屸��,6
	memcpy(out->job_clsf_code, data->job_clsf_code, sizeof(data->job_clsf_code));	// ���������ڵ�,CBA2(��ȭ ���� �ŷ����2)
	memcpy(out->trd_date, data->trd_date, sizeof(data->trd_date));	// �ŷ���,YYYYMMDD
	memcpy(out->currency_name, data->currency_name, sizeof(data->currency_name));	// ��ȭ��,��)��ȭ�� ����
	out->ave_rate = Str2Dbl(data->ave_rate, sizeof(data->ave_rate), 4);	// AVERAGE RATE,99.9999
	out->o_n_vol = Str2Dbl(data->o_n_vol, sizeof(data->o_n_vol), 2);	// O/N VOLUME,9999.99
	out->total_vol = Str2Dbl(data->total_vol, sizeof(data->total_vol), 2);	// TOTAL VOLUME,9999.99
	out->libor_rate = Str2Dbl(data->libor_rate, sizeof(data->libor_rate), 5);	// LIBOR,9.99999
	out->sibor_rate = Str2Dbl(data->sibor_rate, sizeof(data->sibor_rate), 5);	// SIBOR,9.99999

	return 1;
}


// ��������_USD�ǽð�����_������1
int ParseI1016_FOC1(const double& timestamp, const char* in_buff, DF_USD_REAL_TIME_DATA_1* out) {
	USD_REAL_TIME_DATA_1* data = (USD_REAL_TIME_DATA_1*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����,I1
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������,01:��ǰ����,\n���� record '99' set
	out->mrk_clsf = data->mrk_clsf[0];	//���屸��,6
	memcpy(out->job_clsf_code, data->job_clsf_code, sizeof(data->job_clsf_code));	// ���������ڵ�,FOC1(��/�޷� �ð��뺰 �ŷ���Ȳ)
	out->trd_date = Str2Int(data->trd_date, sizeof(data->trd_date));	// �ŷ���,YYYYMMDD
	memcpy(out->trd_hour, data->trd_hour, sizeof(data->trd_hour));	// �ð���,HHMM-HHMM
	out->spread_low_rate = Str2Dbl(data->spread_low_rate, sizeof(data->spread_low_rate), 2);	// LOW RATE(SP),9999.99
	out->spread_high_rate = Str2Dbl(data->spread_high_rate, sizeof(data->spread_high_rate), 2);	// HIGH RATE(SP),9999.99

	return 1;
}


// ��������_USD�ǽð�����_������2
int ParseI1016_FOD1(const double& timestamp, const char* in_buff, DF_USD_REAL_TIME_DATA_2* out) {
	USD_REAL_TIME_DATA_2* data = (USD_REAL_TIME_DATA_2*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����,I1
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������,01:��ǰ����
	out->mrk_clsf = data->mrk_clsf[0];	//���屸��,6
	memcpy(out->job_clsf_code, data->job_clsf_code, sizeof(data->job_clsf_code));	// ���������ڵ�,FOD1(��/�޷� ���Ϲ��� ������Ȳ)
	out->trd_date = Str2Int(data->trd_date, sizeof(data->trd_date));	// �ŷ���,YYYYMMDD
	memcpy(out->fixed_date_clsf, data->fixed_date_clsf, sizeof(data->fixed_date_clsf));	// ���Ϲ�����,��)���Ϲ���������
	out->maturity_date = Str2Int(data->maturity_date, sizeof(data->maturity_date));	// ������(������),YYYYMMDD
	out->bid_best = Str2Dbl(data->bid_best, sizeof(data->bid_best), 1);	// BID BEST,9999.9
	out->offer_best = Str2Dbl(data->offer_best, sizeof(data->offer_best), 1);	// OFFER BEST,9999.9
	out->bid_vol = Str2Dbl(data->bid_vol, sizeof(data->bid_vol), 1);	// BID VOLUME,9999.9
	out->offer_vol = Str2Dbl(data->offer_vol, sizeof(data->offer_vol), 1);	// OFFER VOLUME,9999.9
	out->prev_rate = Str2Dbl(data->prev_rate, sizeof(data->prev_rate), 1);	// PREV RATE,9999.9

	return 1;
}


// ��������_USD�ǽð�����_������3
int ParseI1016_FOE1(const double& timestamp, const char* in_buff, DF_USD_REAL_TIME_DATA_3* out) {
	USD_REAL_TIME_DATA_3* data = (USD_REAL_TIME_DATA_3*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����,I1
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������,01:��ǰ����
	out->mrk_clsf = data->mrk_clsf[0];	//���屸��,6
	memcpy(out->job_clsf_code, data->job_clsf_code, sizeof(data->job_clsf_code));	// ���������ڵ�,FOE1(��/�޷� ���Ϲ��� ü����Ȳ) (����->ü��)����
	out->trd_date = Str2Int(data->trd_date, sizeof(data->trd_date));	// �ŷ���,YYYYMMDD
	memcpy(out->fixed_date_clsf, data->fixed_date_clsf, sizeof(data->fixed_date_clsf));	// ���Ϲ�����,��)���Ϲ���������
	out->maturity_date = Str2Int(data->maturity_date, sizeof(data->maturity_date));	// ������(������),YYYYMMDD
	out->low_rate = Str2Dbl(data->low_rate, sizeof(data->low_rate), 1);	// LOW RATE,9999.9
	out->high_rate = Str2Dbl(data->high_rate, sizeof(data->high_rate), 1);	// HIGH RATE,9999.9
	out->open_rate = Str2Dbl(data->open_rate, sizeof(data->open_rate), 1);	// OPEN RATE,9999.9
	out->close_rate = Str2Dbl(data->close_rate, sizeof(data->close_rate), 1);	// CLOSE RATE,9999.9

	return 1;
}


// ��������_CNH�ǽð�����_������
int ParseI1016_HOE1(const double& timestamp, const char* in_buff, DF_CNH_REAL_TIME_DATA* out) {
	CNH_REAL_TIME_DATA* data = (CNH_REAL_TIME_DATA*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����,I1
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������,01:��ǰ����
	out->mrk_clsf = data->mrk_clsf[0];	//���屸��,6
	memcpy(out->job_clsf_code, data->job_clsf_code, sizeof(data->job_clsf_code));	// ���������ڵ�,HOE1(��/���� ���Ϲ��� ü����Ȳ)
	out->trd_date = Str2Int(data->trd_date, sizeof(data->trd_date));	// �ŷ���,YYYYMMDD
	memcpy(out->fixed_date_clsf, data->fixed_date_clsf, sizeof(data->fixed_date_clsf));	// ���Ϲ�����,��)���Ϲ���������
	out->maturity_date = Str2Int(data->maturity_date, sizeof(data->maturity_date));	// ������(������),YYYYMMDD
	out->low_rate = Str2Dbl(data->low_rate, sizeof(data->low_rate), 1);	// LOW RATE,9999.9
	out->high_rate = Str2Dbl(data->high_rate, sizeof(data->high_rate), 1);	// HIGH RATE,9999.9
	out->open_rate = Str2Dbl(data->open_rate, sizeof(data->open_rate), 1);	// OPEN RATE,9999.9
	out->close_rate = Str2Dbl(data->close_rate, sizeof(data->close_rate), 1);	// CLOSE RATE,9999.9

	return 1;
}


// ��������_USD�ǽð�����_������4
int ParseI1016_FOF1(const double& timestamp, const char* in_buff, DF_USD_REAL_TIME_DATA_4* out) {
	USD_REAL_TIME_DATA_4* data = (USD_REAL_TIME_DATA_4*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����,I1
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������,01:��ǰ����
	out->mrk_clsf = data->mrk_clsf[0];	//���屸��,6
	memcpy(out->job_clsf_code, data->job_clsf_code, sizeof(data->job_clsf_code));	// ���������ڵ�,FOF1(SWAP ���Ϲ��� ������Ȳ)
	out->trd_date = Str2Int(data->trd_date, sizeof(data->trd_date));	// �ŷ���,YYYYMMDD
	memcpy(out->fixed_date_clsf, data->fixed_date_clsf, sizeof(data->fixed_date_clsf));	// ���Ϲ�����,��)���Ϲ���������
	out->maturity_date = Str2Int(data->maturity_date, sizeof(data->maturity_date));	// ������(������),YYYYMMDD
	out->bid_best = Str2Int(data->bid_best, sizeof(data->bid_best));	// BID BEST,��9999
	out->offer_best = Str2Int(data->offer_best, sizeof(data->offer_best));	// OFFER BEST,��9999
	out->bid_vol = Str2Dbl(data->bid_vol, sizeof(data->bid_vol), 1);	// BID VOLUME,9999.9
	out->offer_vol = Str2Dbl(data->offer_vol, sizeof(data->offer_vol), 1);	// OFFER VOLUME,9999.9
	out->prev_rate = Str2Int(data->prev_rate, sizeof(data->prev_rate));	// PREV RATE,��9999

	return 1;
}


// ��������_USD�ǽð�����_������5
int ParseI1016_FOG1(const double& timestamp, const char* in_buff, DF_USD_REAL_TIME_DATA_5* out) {
	USD_REAL_TIME_DATA_5* data = (USD_REAL_TIME_DATA_5*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����,I1
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������,01:��ǰ����
	out->mrk_clsf = data->mrk_clsf[0];	//���屸��,6
	memcpy(out->job_clsf_code, data->job_clsf_code, sizeof(data->job_clsf_code));	// ���������ڵ�,FOG1(SWAP ���Ϲ��� ü����Ȳ)
	out->trd_date = Str2Int(data->trd_date, sizeof(data->trd_date));	// �ŷ���,YYYYMMDD
	memcpy(out->fixed_date_clsf, data->fixed_date_clsf, sizeof(data->fixed_date_clsf));	// ���Ϲ�����,��)���Ϲ���������
	out->maturity_date = Str2Int(data->maturity_date, sizeof(data->maturity_date));	// ������(������),YYYYMMDD
	out->low_rate = Str2Int(data->low_rate, sizeof(data->low_rate));	// LOW RATE,��9999
	out->high_rate = Str2Int(data->high_rate, sizeof(data->high_rate));	// HIGH RATE,��9999
	out->open_rate = Str2Int(data->open_rate, sizeof(data->open_rate));	// OPEN RATE,��9999
	out->close_rate = Str2Int(data->close_rate, sizeof(data->close_rate));	// CLOSE RATE,��9999

	return 1;
}


// ��������_USD�ǽð�����_������8
int ParseI1016_UOD1(const double& timestamp, const char* in_buff, DF_USD_REAL_TIME_DATA_8* out) {
	USD_REAL_TIME_DATA_8* data = (USD_REAL_TIME_DATA_8*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����,I1
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������,01:��ǰ����
	out->mrk_clsf = data->mrk_clsf[0];	//���屸��,6
	memcpy(out->job_clsf_code, data->job_clsf_code, sizeof(data->job_clsf_code));	// ���������ڵ�,UOD1(���޷� SPOT ��� ȯ��ȣ��)
	out->trd_date = Str2Int(data->trd_date, sizeof(data->trd_date));	// �ŷ���,YYYYMMDD
	memcpy(out->fixed_date_clsf, data->fixed_date_clsf, sizeof(data->fixed_date_clsf));	// ���Ϲ�����,��)���Ϲ� ����
	out->maturity_date = Str2Int(data->maturity_date, sizeof(data->maturity_date));	// ������(������),YYYYMMDD
	memcpy(out->bank_name, data->bank_name, sizeof(data->bank_name));	// �����,���������
	out->bid_best = Str2Dbl(data->bid_best, sizeof(data->bid_best), 1);	// BID BEST,9999.9
	out->offer_best = Str2Dbl(data->offer_best, sizeof(data->offer_best), 1);	// OFFER BEST,9999.9
	out->low_rate = Str2Dbl(data->low_rate, sizeof(data->low_rate), 1);	// LOW RATE,9999.9
	out->high_rate = Str2Dbl(data->high_rate, sizeof(data->high_rate), 1);	// HIGH RATE,9999.9
	out->open_rate = Str2Dbl(data->open_rate, sizeof(data->open_rate), 1);	// OPEN RATE,9999.9
	out->mar = Str2Dbl(data->mar, sizeof(data->mar), 1);	// MAR,9999.9

	return 1;
}


// ��������_USD�ǽð�����_������7
int ParseI1016_COA1(const double& timestamp, const char* in_buff, DF_USD_REAL_TIME_DATA_7* out) {
	USD_REAL_TIME_DATA_7* data = (USD_REAL_TIME_DATA_7*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����,I1
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������,01:��ǰ����
	out->mrk_clsf = data->mrk_clsf[0];	//���屸��,6
	memcpy(out->job_clsf_code, data->job_clsf_code, sizeof(data->job_clsf_code));	// ���������ڵ�,COA1(��ȭ ���Ϲ��� ������Ȳ)
	out->trd_date = Str2Int(data->trd_date, sizeof(data->trd_date));	// �ŷ���,YYYYMMDD
	memcpy(out->currency_name, data->currency_name, sizeof(data->currency_name));	// ��ȭ��,��)��ȭ�� ����
	memcpy(out->fixed_date_clsf, data->fixed_date_clsf, sizeof(data->fixed_date_clsf));	// ���Ϲ� ����,��)���Ϲ� ����
	out->bid_rate = Str2Dbl(data->bid_rate, sizeof(data->bid_rate), 2);	// BID RATE,99999.99
	out->offer_rate = Str2Dbl(data->offer_rate, sizeof(data->offer_rate), 2);	// OFFER RATE,99999.99
	out->bid_vol = Str2Dbl(data->bid_vol, sizeof(data->bid_vol), 2);	// BID VOLUME,9999.99
	out->offer_vol = Str2Dbl(data->offer_vol, sizeof(data->offer_vol), 2);	// OFFER VOLUME,9999.99

	return 1;
}


// ��������_USD�ǽð�����_������6
int ParseI1016_FOQ1(const double& timestamp, const char* in_buff, DF_USD_REAL_TIME_DATA_6* out) {
	USD_REAL_TIME_DATA_6* data = (USD_REAL_TIME_DATA_6*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����,I1
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������,01:��ǰ����
	out->mrk_clsf = data->mrk_clsf[0];	//���屸��,6
	memcpy(out->job_clsf_code, data->job_clsf_code, sizeof(data->job_clsf_code));	// ���������ڵ�,FOQ1(����ȯ �ð��뺰 BID-OFFER ȣ�� ��Ȳ)
	out->trd_date = Str2Int(data->trd_date, sizeof(data->trd_date));	// �ŷ���,YYYYMMDD
	memcpy(out->td_hour, data->td_hour, sizeof(data->td_hour));	// �ð���,HHMM
	out->spread_bid_prc = Str2Dbl(data->spread_bid_prc, sizeof(data->spread_bid_prc), 1);	// BID ȣ��(SP),9999.9
	out->spread_ask_prc = Str2Dbl(data->spread_ask_prc, sizeof(data->spread_ask_prc), 1);	// OFFER ȣ��(SP),9999.9

	return 1;
}


// ��ǰ����_Polling ������
int ParseI2016(const double& timestamp, const char* in_buff, DF_COM_FUT_POLLING_DATA* out) {
	COM_FUT_POLLING_DATA* data = (COM_FUT_POLLING_DATA*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����,I2
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������,01:��ǰ����
	out->mrk_clsf = data->mrk_clsf[0];	//���屸��,6
	memcpy(out->send_time, data->send_time, sizeof(data->send_time));	// ���۽ð�,HHSS
	memcpy(out->main_backup_clsf, data->main_backup_clsf, sizeof(data->main_backup_clsf));	// Main Backup����,space

	return 1;
}


// ��������_USD�ǽð�����_������9
int ParseI1016_UOE1(const double& timestamp, const char* in_buff, DF_USD_REAL_TIME_DATA_9* out) {
	USD_REAL_TIME_DATA_9* data = (USD_REAL_TIME_DATA_9*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����,I1
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������,01:��ǰ����
	out->mrk_clsf = data->mrk_clsf[0];	//���屸��,6
	memcpy(out->job_clsf_code, data->job_clsf_code, sizeof(data->job_clsf_code));	// ���������ڵ�,UOE1(���޷� SPOT 30�д��� �ణ ȯ��ü�ᰡ)
	out->trd_date = Str2Int(data->trd_date, sizeof(data->trd_date));	// �ŷ���,YYYYMMDD
	memcpy(out->fixed_date_clsf, data->fixed_date_clsf, sizeof(data->fixed_date_clsf));	// ���Ϲ�����,SP
	out->maturity_date = Str2Int(data->maturity_date, sizeof(data->maturity_date));	// ������(������),YYYYMMDD
	out->exe_t = Str2Int(data->exe_t, sizeof(data->exe_t));	// ü��ð�,HHMM(0930, 1000,1030,1100,1130,1200,1230,\n1300,1330,1400, 1430, 1500)
	out->exe_prc = Str2Dbl(data->exe_prc, sizeof(data->exe_prc), 1);	// ü�ᰡ,9999.9

	return 1;
}


// ��������_������ǥ��������_������
int H8016_1000(const double& timestamp, const char* in_buff, DF_LEAN_HOG_REP_PRC_INDEX_DATA* out) {
	LEAN_HOG_REP_PRC_INDEX_DATA* data = (LEAN_HOG_REP_PRC_INDEX_DATA*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����,H8
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������,01:��ǰ����
	out->mrk_clsf = data->mrk_clsf[0];	//���屸��,6
	out->data_type = data->data_type[0];	//������ Ÿ��,D:���� ��ǥ���� ����
	memcpy(out->inform_date_yest, data->inform_date_yest, sizeof(data->inform_date_yest));	// ��������-����
	memcpy(out->inform_date_close_yest, data->inform_date_close_yest, sizeof(data->inform_date_close_yest));	// ��������-������
	out->accum_mrk_nbr = Str2Int(data->accum_mrk_nbr, sizeof(data->accum_mrk_nbr));	// ���赵�Ž����,����
	out->accum_prd_nbr = Str2Int(data->accum_prd_nbr, sizeof(data->accum_prd_nbr));	// ����μ�,��
	out->trd_weight_total = Str2Dbl(data->trd_weight_total, sizeof(data->trd_weight_total), 0);	// �ŷ� ��ü�� �հ�,kg
	out->trd_prc_total = Str2Dbl(data->trd_prc_total, sizeof(data->trd_prc_total), 0);	// �ŷ� ���� �հ�,��
	out->rep_prc = Str2Int(data->rep_prc, sizeof(data->rep_prc));	// ��ǥ ����,��/kg

	return 1;
}


// ��������_�����ǽð���������_������
int H8016_REAL(const double& timestamp, const char* in_buff, DF_LEAN_HOG_REAL_TIME_PRC_INDEX_DATA* out) {
	LEAN_HOG_REAL_TIME_PRC_INDEX_DATA* data = (LEAN_HOG_REAL_TIME_PRC_INDEX_DATA*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_cslf, data->data_cslf, sizeof(data->data_cslf));	// DATA����,H8
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������,01:��ǰ����
	out->mrk_clsf = data->mrk_clsf[0];	//���屸��,6
	out->data_type = data->data_type[0];	//������ Ÿ��,L:�ǽð� �������� ����
	memcpy(out->inform_time, data->inform_time, sizeof(data->inform_time));	// ���ýð�
	memcpy(out->inform_date_yest, data->inform_date_yest, sizeof(data->inform_date_yest));	// ��������-����
	memcpy(out->inform_date_today, data->inform_date_today, sizeof(data->inform_date_today));	// ��������-����
	out->accum_mrk_nbr = Str2Int(data->accum_mrk_nbr, sizeof(data->accum_mrk_nbr));	// ���� ���Ž��� ��,����
	out->accum_prd_nbr = Str2Int(data->accum_prd_nbr, sizeof(data->accum_prd_nbr));	// ����μ�,��
	out->trd_weight_total = Str2Dbl(data->trd_weight_total, sizeof(data->trd_weight_total), 0);	// �ŷ� ��ü�� �հ�,kg
	out->trd_prc_total = Str2Dbl(data->trd_prc_total, sizeof(data->trd_prc_total), 0);	// �ŷ� ���� �հ�,��
	out->under_asset_prc = Str2Int(data->under_asset_prc, sizeof(data->under_asset_prc));	// ���� ����,��/kg

	return 1;
}


// ��������_����������������_������
int H8016_1800(const double& timestamp, const char* in_buff, DF_LEAN_HOG_CLOSE_PRICE_INDEX_DATA* out) {
	LEAN_HOG_CLOSE_PRICE_INDEX_DATA* data = (LEAN_HOG_CLOSE_PRICE_INDEX_DATA*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����,H8
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������,01:��ǰ����,\n���� record '99' set
	out->mrk_clsf = data->mrk_clsf[0];	//���屸��,6
	out->data_type = data->data_type[0];	//������ Ÿ��,E:�ǽð� �������� ��������
	memcpy(out->inform_date_today, data->inform_date_today, sizeof(data->inform_date_today));	// �������� ����
	memcpy(out->inform_date_yest, data->inform_date_yest, sizeof(data->inform_date_yest));	// �������� ����
	out->accum_mrk_nbr = Str2Int(data->accum_mrk_nbr, sizeof(data->accum_mrk_nbr));	// ���� ���Ž��� ��
	out->accum_prd_nbr = Str2Int(data->accum_prd_nbr, sizeof(data->accum_prd_nbr));	// ���� �μ�,����
	out->trd_weight_total = Str2Dbl(data->trd_weight_total, sizeof(data->trd_weight_total), 0);	// �ŷ� ��ü�� �հ�,��
	out->trd_prc_total = Str2Dbl(data->trd_prc_total, sizeof(data->trd_prc_total), 0);	// �ŷ� ���� �հ�,kg
	out->init_prc = Str2Int(data->init_prc, sizeof(data->init_prc));	// ���� ����,��
	out->high_prc = Str2Int(data->high_prc, sizeof(data->high_prc));	// �ְ� ����,��/kg
	out->low_prc = Str2Int(data->low_prc, sizeof(data->low_prc));	// ���� ����
	out->close_prc = Str2Int(data->close_prc, sizeof(data->close_prc));	// ���� ����

	return 1;
}


// ��ǰ����_SPACE
int ParseG9016(const double& timestamp, const char* in_buff, DF_COM_FUT_SPACE* out) {
	COM_FUT_SPACE* data = (COM_FUT_SPACE*)in_buff;

	out->timestamp = timestamp;
	memcpy(out->data_clsf, data->data_clsf, sizeof(data->data_clsf));	// DATA����,G9
	memcpy(out->info_clsf, data->info_clsf, sizeof(data->info_clsf));	// ��������,01:��ǰ����
	out->mrk_clsf = data->mrk_clsf[0];	//���屸��,6

	return 1;
}
