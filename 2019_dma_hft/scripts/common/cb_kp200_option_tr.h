// cb_kp200_option_tr.h
// KOSPI200 �����ɼ� �ǽð� TR

#pragma once
// �ּ��� \n�� ���� ���߿� �̻ڰ� �ٲ����


// K200�ɼ�_����+�����ջ�
typedef struct _K200_OPT_COMP_BLOCK {
	char data_clsf[2];	// DATA����, C4
	char info_clsf[2];	// ��������, 03:KOSPI200�����ɼ�
	char mkt_clsf[1];	// ���屸��, 4
	char isin_clsf[12];	// �����ڵ�
	char stk_snr[7];	// �����Ϸù�ȣ
	char cpt_block_trd_vol[12];	// ����+�����ջ� �ŷ���, ����Ÿſ� ���Ǵ뷮�ŷ��� �ջ��� �ŷ���
	char cpt_block_trd_amt[22];	// ����+�����ջ� �ŷ����, ����Ÿſ� ���Ǵ뷮�ŷ��� �ջ��� �ŷ����\n(���� : ��)
	char ff[1];	// End of Text, 0xFF
} K200_OPT_COMP_BLOCK;


// K200�ɼ�_ü��
typedef struct _K200_OPT_EXEC {
	char data_clsf[2];	// DATA����, A3
	char info_clsf[2];	// ��������, 03:KOSPI200�����ɼ�
	char mrk_clsf[1];	// ���屸��, 4
	char isin_clsf[12];	// �����ڵ�
	char stk_snr[4];	// �����Ϸù�ȣ, �����Ϸù�ȣ �ڸ��� ����(3->4)
	char brd_id[2];	// ����ID, �ڵ尪��������
	char cur_prc[5];	// ���簡��, ��) 999.99
	char exe_q[7];	// ü�����
	char ss_id[2];	// ����ID, �ڵ尪��������
	char exe_t[8];	// ü��ð�
	char init_prc[5];	// �ð�, ��) 999.99
	char high_prc[5];	// ��, ��) 999.99
	char low_prc[5];	// ����, ��) 999.99
	char pri_prc[5];	// ��������, ��) 999.99
	char accm_exe_q[8];	// ����ü�����
	char accm_trd_amt[11];	// �����ŷ����, ����:õ��
	char filler[8];	// ���Ǵ뷮����ü�����, ������(Filler)
	char l_or_s[1];	// �����ŵ��ż������ڵ�, 1:�ŵ�,2:�ż�(�������� ���� ȣ���� �ŵ��ż����а�)
	char real_t_high_prc[5];	// �ǽð����Ѱ�, ��) 999.99 ���߰��̵�����
	char real_t_low_prc[5];	// �ǽð����Ѱ�, ��) 999.99 ���߰��̵�����
	char ff[1];	// End of Text, 0xFF
} K200_OPT_EXEC;


// K200�ɼ�_�켱ȣ��
typedef struct _K200_OPT_LIMIT_ORD {
	char data_clsf[2];	// DATA����, B6
	char info_clsf[2];	// ��������, 03:KOSPI200�����ɼ�
	char mrk_clsf[1];	// ���屸��, 4
	char isin_clsf[12];	// �����ڵ�
	char stk_snr[4];	// �����Ϸù�ȣ, �����Ϸù�ȣ �ڸ��� ����(3->4)
	char brd_id[2];	// ����ID, �ڵ尪��������
	char ss_id[2];	// ����ID, �ڵ尪��������
	char total_l_limit_ord_q[7];	// �ż���ȣ���ܷ�
	char l_lvl_1_prc[5];	// �ż�1�ܰ�켱ȣ������, ��) 999.99
	char l_lvl_1_q[7];	// �ż�1�ܰ�켱ȣ���ܷ�
	char l_lvl_2_prc[5];	// �ż�2�ܰ�켱ȣ������, ��) 999.99
	char l_lvl_2_q[7];	// �ż�2�ܰ�켱ȣ���ܷ�
	char l_lvl_3_prc[5];	// �ż�3�ܰ�켱ȣ������, ��) 999.99
	char l_lvl_3_q[7];	// �ż�3�ܰ�켱ȣ���ܷ�
	char l_lvl_4_prc[5];	// �ż�4�ܰ�켱ȣ������, ��) 999.99
	char l_lvl_4_q[7];	// �ż�4�ܰ�켱ȣ���ܷ�
	char l_lvl_5_prc[5];	// �ż�5�ܰ�켱ȣ������, ��) 999.99
	char l_lvl_5_q[7];	// �ż�5�ܰ�켱ȣ���ܷ�
	char total_s_limit_ord_q[7];	// �ŵ���ȣ���ܷ�
	char s_lvl_1_prc[5];	// �ŵ�1�ܰ�켱ȣ������, ��) 999.99
	char s_lvl_1_q[7];	// �ŵ�1�ܰ�켱ȣ���ܷ�
	char s_lvl_2_prc[5];	// �ŵ�2�ܰ�켱ȣ������, ��) 999.99
	char s_lvl_2_q[7];	// �ŵ�2�ܰ�켱ȣ���ܷ�
	char s_lvl_3_prc[5];	// �ŵ�3�ܰ�켱ȣ������, ��) 999.99
	char s_lvl_3_q[7];	// �ŵ�3�ܰ�켱ȣ���ܷ�
	char s_lvl_4_prc[5];	// �ŵ�4�ܰ�켱ȣ������, ��) 999.99
	char s_lvl_4_q[7];	// �ŵ�4�ܰ�켱ȣ���ܷ�
	char s_lvl_5_prc[5];	// �ŵ�5�ܰ�켱ȣ������, ��) 999.99
	char s_lvl_5_q[7];	// �ŵ�5�ܰ�켱ȣ���ܷ�
	char total_l_trd_cnt[5];	// �ż���ȿȣ���Ǽ�
	char l_lvl_1_trd_cnt[4];	// �ż�1�ܰ�켱ȣ���Ǽ�
	char l_lvl_2_trd_cnt[4];	// �ż�2�ܰ�켱ȣ���Ǽ�
	char l_lvl_3_trd_cnt[4];	// �ż�3�ܰ�켱ȣ���Ǽ�
	char l_lvl_4_trd_cnt[4];	// �ż�4�ܰ�켱ȣ���Ǽ�
	char l_lvl_5_trd_cnt[4];	// �ż�5�ܰ�켱ȣ���Ǽ�
	char total_s_trd_cnt[5];	// �ŵ���ȿȣ���Ǽ�
	char s_lvl_1_trd_cnt[4];	// �ŵ�1�ܰ�켱ȣ���Ǽ�
	char s_lvl_2_trd_cnt[4];	// �ŵ�2�ܰ�켱ȣ���Ǽ�
	char s_lvl_3_trd_cnt[4];	// �ŵ�3�ܰ�켱ȣ���Ǽ�
	char s_lvl_4_trd_cnt[4];	// �ŵ�4�ܰ�켱ȣ���Ǽ�
	char s_lvl_5_trd_cnt[4];	// �ŵ�5�ܰ�켱ȣ���Ǽ�
	char ord_rcv_t[8];	// ȣ�������ð�
	char exp_prc[5];	// ����ü�ᰡ��, ��) 999.99 ���ϰ��ŸŽø� ����\n (����±����ڵ�:10,20,30,80)
	char ff[1];	// End of Text, 0xFF
} K200_OPT_LIMIT_ORD;


// K200�ɼ�_ü��_�켱ȣ��
typedef struct _K200_OPT_EXEC_LIMIT_ORD {
	char data_clsf[2];	// DATA����, G7
	char info_clsf[2];	// ��������, 03:KOSPI200�����ɼ�
	char mrk_clsf[1];	// ���屸��, 4
	char isin_clsf[12];	// �����ڵ�
	char stk_snr[4];	// �����Ϸù�ȣ, �����Ϸù�ȣ �ڸ��� ����(3->4)
	char brd_id[2];	// ����ID, �ڵ尪��������
	char cur_prc[5];	// ���簡��, ��) 999.99
	char exe_q[7];	// ü�����
	char ss_id[2];	// ����ID, �ڵ尪��������
	char exe_t[8];	// ü��ð�
	char init_prc[5];	// �ð�, ��) 999.99
	char high_prc[5];	// ��, ��) 999.99
	char low_prc[5];	// ����, ��) 999.99
	char pri_prc[5];	// ��������, ��) 999.99
	char accm_exe_q[8];	// ����ü�����
	char accm_trd_amt[11];	// �����ŷ����, ����:õ��
	char accm_block_trd_exe_q[8];	// ���Ǵ뷮����ü�����, ������(Filler)
	char l_or_s[1];	// �����ŵ��ż������ڵ�, 1:�ŵ�,2:�ż�(�������� ���� ȣ���� �ŵ��ż����а�)
	char total_l_limit_ord_q[7];	// �ż���ȣ���ܷ�
	char l_lvl_1_prc[5];	// �ż�1�ܰ�켱ȣ������, ��) 999.99
	char l_lvl_1_q[7];	// �ż�1�ܰ�켱ȣ���ܷ�
	char l_lvl_2_prc[5];	// �ż�2�ܰ�켱ȣ������, ��) 999.99
	char l_lvl_2_q[7];	// �ż�2�ܰ�켱ȣ���ܷ�
	char l_lvl_3_prc[5];	// �ż�3�ܰ�켱ȣ������, ��) 999.99
	char l_lvl_3_q[7];	// �ż�3�ܰ�켱ȣ���ܷ�
	char l_lvl_4_prc[5];	// �ż�4�ܰ�켱ȣ������
	char l_lvl_4_q[7];	// �ż�4�ܰ�켱ȣ���ܷ�
	char l_lvl_5_prc[5];	// �ż�5�ܰ�켱ȣ������, ��) 999.99
	char l_lvl_5_q[7];	// �ż�5�ܰ�켱ȣ���ܷ�
	char total_s_limit_ord_q[7];	// �ŵ���ȣ���ܷ�
	char s_lvl_1_prc[5];	// �ŵ�1�ܰ�켱ȣ������, ��) 999.99
	char s_lvl_1_q[7];	// �ŵ�1�ܰ�켱ȣ���ܷ�
	char s_lvl_2_prc[5];	// �ŵ�2�ܰ�켱ȣ������
	char s_lvl_2_q[7];	// �ŵ�2�ܰ�켱ȣ���ܷ�, ��) 999.99
	char s_lvl_3_prc[5];	// �ŵ�3�ܰ�켱ȣ������
	char s_lvl_3_q[7];	// �ŵ�3�ܰ�켱ȣ���ܷ�
	char s_lvl_4_prc[5];	// �ŵ�4�ܰ�켱ȣ������, ��) 999.99
	char s_lvl_4_q[7];	// �ŵ�4�ܰ�켱ȣ���ܷ�
	char s_lvl_5_prc[5];	// �ŵ�5�ܰ�켱ȣ������
	char s_lvl_5_q[7];	// �ŵ�5�ܰ�켱ȣ���ܷ�, ��) 999.99
	char total_l_trd_cnt[5];	// �ż���ȿȣ���Ǽ�
	char l_lvl_1_trd_cnt[4];	// �ż�1�ܰ�켱ȣ���Ǽ�
	char l_lvl_2_trd_cnt[4];	// �ż�2�ܰ�켱ȣ���Ǽ�
	char l_lvl_3_trd_cnt[4];	// �ż�3�ܰ�켱ȣ���Ǽ�, ��) 999.99
	char l_lvl_4_trd_cnt[4];	// �ż�4�ܰ�켱ȣ���Ǽ�
	char l_lvl_5_trd_cnt[4];	// �ż�5�ܰ�켱ȣ���Ǽ�
	char total_s_trd_cnt[5];	// �ŵ���ȿȣ���Ǽ�, ��) 999.99
	char s_lvl_1_trd_cnt[4];	// �ŵ�1�ܰ�켱ȣ���Ǽ�
	char s_lvl_2_trd_cnt[4];	// �ŵ�2�ܰ�켱ȣ���Ǽ�
	char s_lvl_3_trd_cnt[4];	// �ŵ�3�ܰ�켱ȣ���Ǽ�, ��) 999.99
	char s_lvl_4_trd_cnt[4];	// �ŵ�4�ܰ�켱ȣ���Ǽ�
	char s_lvl_5_trd_cnt[4];	// �ŵ�5�ܰ�켱ȣ���Ǽ�
	char real_t_high_prc[5];	// �ǽð����Ѱ�, ��) 999.99 ���߰��̵�����
	char real_t_low_prc[5];	// �ǽð����Ѱ�, ��) 999.99 ���߰��̵�����
	char ff[1];	// End of Text, 0xFF
} K200_OPT_EXEC_LIMIT_ORD;


// K200�ɼ�_���񸶰�
typedef struct _K200_OPT_CLOSE_PRODUCT {
	char data_clsf[2];	// DATA����, A6
	char info_clsf[2];	// ��������, 03:KOSPI200�����ɼ�
	char mrk_clsf[1];	// ���屸��, 4
	char isin_clsf[12];	// �����ڵ�
	char stk_snr[4];	// �����Ϸù�ȣ, �����Ϸù�ȣ �ڸ��� ����(3->4)
	char brd_id[2];	// ����ID, �ڵ尪��������
	char close_prc[5];	// ����, *�ŷ��� ������ ��� ���ذ� set, ��) 999.99
	char close_prc_code[1];	// ���������ڵ�, 1:ü�ᰡ��, 3:�ŷ���\n 2:�⼼ -2012.05.14 ����\n ' ':�������� �ƴ� ��� space
	char accm_exe_q[8];	// ����ü�����
	char accm_trd_amt[11];	// �����ŷ����, ����:õ��
	char filler[8];	// ���Ǵ뷮����ü�����, ������(Filler)
	char total_l_limit_ord_q[7];	// �ż���ȣ���ܷ�
	char l_lvl_1_prc[5];	// �ż�1�ܰ�켱ȣ������, ��) 999.99
	char l_lvl_1_q[7];	// �ż�1�ܰ�켱ȣ���ܷ�
	char l_lvl_2_prc[5];	// �ż�2�ܰ�켱ȣ������, ��) 999.99
	char l_lvl_2_q[7];	// �ż�2�ܰ�켱ȣ���ܷ�
	char l_lvl_3_prc[5];	// �ż�3�ܰ�켱ȣ������, ��) 999.99
	char l_lvl_3_q[7];	// �ż�3�ܰ�켱ȣ���ܷ�
	char l_lvl_4_prc[5];	// �ż�4�ܰ�켱ȣ������, ��) 999.99
	char l_lvl_4_q[7];	// �ż�4�ܰ�켱ȣ���ܷ�
	char l_lvl_5_prc[5];	// �ż�5�ܰ�켱ȣ������, ��) 999.99
	char l_lvl_5_q[7];	// �ż�5�ܰ�켱ȣ���ܷ�
	char total_s_limit_ord_q[7];	// �ŵ���ȣ���ܷ�
	char s_lvl_1_prc[5];	// �ŵ�1�ܰ�켱ȣ������, ��) 999.99
	char s_lvl_1_q[7];	// �ŵ�1�ܰ�켱ȣ���ܷ�
	char s_lvl_2_prc[5];	// �ŵ�2�ܰ�켱ȣ������, ��) 999.99
	char s_lvl_2_q[7];	// �ŵ�2�ܰ�켱ȣ���ܷ�
	char s_lvl_3_prc[5];	// �ŵ�3�ܰ�켱ȣ������, ��) 999.99
	char s_lvl_3_q[7];	// �ŵ�3�ܰ�켱ȣ���ܷ�
	char s_lvl_4_prc[5];	// �ŵ�4�ܰ�켱ȣ������, ��) 999.99
	char s_lvl_4_q[7];	// �ŵ�4�ܰ�켱ȣ���ܷ�
	char s_lvl_5_prc[5];	// �ŵ�5�ܰ�켱ȣ������, ��) 999.99
	char s_lvl_5_q[7];	// �ŵ�5�ܰ�켱ȣ���ܷ�
	char total_l_trd_cnt[5];	// �ż���ȿȣ���Ǽ�
	char l_lvl_1_trd_cnt[4];	// �ż�1�ܰ�켱ȣ���Ǽ�
	char l_lvl_2_trd_cnt[4];	// �ż�2�ܰ�켱ȣ���Ǽ�
	char l_lvl_3_trd_cnt[4];	// �ż�3�ܰ�켱ȣ���Ǽ�
	char l_lvl_4_trd_cnt[4];	// �ż�4�ܰ�켱ȣ���Ǽ�
	char l_lvl_5_trd_cnt[4];	// �ż�5�ܰ�켱ȣ���Ǽ�
	char total_s_trd_cnt[5];	// �ŵ���ȿȣ���Ǽ�
	char s_lvl_1_trd_cnt[4];	// �ŵ�1�ܰ�켱ȣ���Ǽ�
	char s_lvl_2_trd_cnt[4];	// �ŵ�2�ܰ�켱ȣ���Ǽ�
	char s_lvl_3_trd_cnt[4];	// �ŵ�3�ܰ�켱ȣ���Ǽ�
	char s_lvl_4_trd_cnt[4];	// �ŵ�4�ܰ�켱ȣ���Ǽ�
	char s_lvl_5_trd_cnt[4];	// �ŵ�5�ܰ�켱ȣ���Ǽ�
	char ff[1];	// End of Text, 0xFF
} K200_OPT_CLOSE_PRODUCT;


// K200�ɼ�_��TS
typedef struct _K200_OPT_MRK_OP_TS {
	char data_clsf[2];	// DATA����, A7
	char info_clsf[2];	// ��������, 03:KOSPI200�����ɼ�
	char mrk_clsf[1];	// ���屸��, 4
	char isin_clsf[12];	// �����ڵ�
	char stk_snr[4];	// �����Ϸù�ȣ, �����Ϸù�ȣ �ڸ��� ����(3->4)
	char prd_id[11];	// ��ǰID, �ڵ尪�������� : spaceó��
	char brd_id[2];	// ����ID, �ڵ尪��������
	char brd_event_id[3];	// �����̺�ƮID, �ڵ尪��������
	char brd_event_start_t[8];	// �����̺�Ʈ���۽ð�, ������ �����(��:BB1(�ŸŰŷ�����)�� ��� 09000000)
	char brd_event_code[5];	// �����̺�Ʈ���뱺�ڵ�, �ڵ尪��������
	char ss_id[2];	// ����ID, �ڵ尪��������
	char ord_exist[1];	// ȣ������, 0:ȣ������(�����׸� ����), 1:ȣ������(�����׸� ���)
	char total_l_limit_ord_q[7];	// �ż���ȣ���ܷ�
	char l_lvl_1_prc[5];	// �ż�1�ܰ�켱ȣ������, ��) 999.99
	char l_lvl_1_q[7];	// �ż�1�ܰ�켱ȣ���ܷ�
	char l_lvl_2_prc[5];	// �ż�2�ܰ�켱ȣ������, ��) 999.99
	char l_lvl_2_q[7];	// �ż�2�ܰ�켱ȣ���ܷ�
	char l_lvl_3_prc[5];	// �ż�3�ܰ�켱ȣ������, ��) 999.99
	char l_lvl_3_q[7];	// �ż�3�ܰ�켱ȣ���ܷ�
	char l_lvl_4_prc[5];	// �ż�4�ܰ�켱ȣ������, ��) 999.99
	char l_lvl_4_q[7];	// �ż�4�ܰ�켱ȣ���ܷ�
	char l_lvl_5_prc[5];	// �ż�5�ܰ�켱ȣ������, ��) 999.99
	char l_lvl_5_q[7];	// �ż�5�ܰ�켱ȣ���ܷ�
	char total_s_limit_ord_q[7];	// �ŵ���ȣ���ܷ�
	char s_lvl_1_prc[5];	// �ŵ�1�ܰ�켱ȣ������, ��) 999.99
	char s_lvl_1_q[7];	// �ŵ�1�ܰ�켱ȣ���ܷ�
	char s_lvl_2_prc[5];	// �ŵ�2�ܰ�켱ȣ������, ��) 999.99
	char s_lvl_2_q[7];	// �ŵ�2�ܰ�켱ȣ���ܷ�
	char s_lvl_3_prc[5];	// �ŵ�3�ܰ�켱ȣ������, ��) 999.99
	char s_lvl_3_q[7];	// �ŵ�3�ܰ�켱ȣ���ܷ�
	char s_lvl_4_prc[5];	// �ŵ�4�ܰ�켱ȣ������, ��) 999.99
	char s_lvl_4_q[7];	// �ŵ�4�ܰ�켱ȣ���ܷ�
	char s_lvl_5_prc[5];	// �ŵ�5�ܰ�켱ȣ������, ��) 999.99
	char s_lvl_5_q[7];	// �ŵ�5�ܰ�켱ȣ���ܷ�
	char total_l_trd_cnt[5];	// �ż���ȿȣ���Ǽ�
	char l_lvl_1_trd_cnt[4];	// �ż�1�ܰ�켱ȣ���Ǽ�
	char l_lvl_2_trd_cnt[4];	// �ż�2�ܰ�켱ȣ���Ǽ�
	char l_lvl_3_trd_cnt[4];	// �ż�3�ܰ�켱ȣ���Ǽ�
	char l_lvl_4_trd_cnt[4];	// �ż�4�ܰ�켱ȣ���Ǽ�
	char l_lvl_5_trd_cnt[4];	// �ż�5�ܰ�켱ȣ���Ǽ�
	char total_s_trd_cnt[5];	// �ŵ���ȿȣ���Ǽ�
	char s_lvl_1_trd_cnt[4];	// �ŵ�1�ܰ�켱ȣ���Ǽ�
	char s_lvl_2_trd_cnt[4];	// �ŵ�2�ܰ�켱ȣ���Ǽ�
	char s_lvl_3_trd_cnt[4];	// �ŵ�3�ܰ�켱ȣ���Ǽ�
	char s_lvl_4_trd_cnt[4];	// �ŵ�4�ܰ�켱ȣ���Ǽ�
	char s_lvl_5_trd_cnt[4];	// �ŵ�5�ܰ�켱ȣ���Ǽ�
	char real_t_high_prc[5];	// �ǽð����Ѱ�, ��) 999.99 ���߰��̵�����
	char real_t_low_prc[5];	// �ǽð����Ѱ�, ��) 999.99 ���߰��̵�����
	char ff[1];	// End of Text, 0xFF
} K200_OPT_MRK_OP_TS;


// K200�ɼ�_����
typedef struct _K200_OPT_CLOSE {
	char data_clsf[2];	// DATA����, H0
	char info_clsf[2];	// ��������, 03:KOSPI200�����ɼ�
	char mrk_clsf[1];	// ���屸��, 4
	char ff[1];	// End of Text, 0xFF
} K200_OPT_CLOSE;


// K200�ɼ�_�������ٰ���
typedef struct _K200_OPT_MRK_OP_SCHD {
	char data_clsf[2];	// DATA����, M4
	char info_clsf[2];	// ��������, 03:KOSPI200�����ɼ�
	char mrk_clsf[1];	// ���屸��, 4
	char isin_clsf[12];	// �����ڵ�, �������� ����ġ�� ���
	char stk_snr[4];	// �����Ϸù�ȣ, �����Ϸù�ȣ �ڸ��� ����(3->4)
	char prd_id[11];	// ��ǰID, �ڵ尪�������� : spaceó��
	char mrk_prd_id[3];	// ����ǰ�׷�ID, OKI : K200�ɼ�
	char brd_id[2];	// ����ID, �ڵ尪��������
	char brd_event_id[3];	// �����̺�ƮID, �ڵ尪��������
	char brd_event_start_t[8];	// �����̺�Ʈ���۽ð�
	char brd_event_code[5];	// �����̺�Ʈ���뱺�ڵ�, �ڵ尪��������
	char ss_open_close_code[2];	// ���ǰ��������ڵ�, BS:���尳��\n BE:��������\n SS:���ǰ���\n SE:��������\n SH:��������\n SR:�����簳
	char ss_id[2];	// ����ID, �ڵ尪��������
	char adj_stage[2];	// ����ܰ�, CB �� ���������� Ȯ��� ����Ǵ� �ܰ� \n��)�ʱⰪ 00
	char under_asset_prc_chg[1];	// �������񰡰�Ȯ��߻��ڵ�, ���������� ����Ȯ��� �����ڵ�(U:���, D:�϶�)
	char exp_prc_chg_t[8];	// ����Ȯ�뿹���ð�, �Ļ����尡��Ȯ�� ���� �̺�Ʈ �߻��� ���Ǵ� �׸����� ����Ȯ�뿹���ð��� ��ϵ�
	char ff[1];	// End of Text, 0xFF
} K200_OPT_MRK_OP_SCHD;


// K200�ɼ�_�������
typedef struct _K200_OPT_DIST_INFO {
	char data_clsf[2];	// DATA����, O6
	char info_clsf[2];	// ��������, 03:KOSPI200�����ɼ�
	char mrk_clsf[1];	// ���屸��, 4
	char isin_clsf[12];	// �����ڵ�
	char stk_snr[4];	// �����Ϸù�ȣ, �����Ϸù�ȣ �ڸ��� ����(3->4)
	char brd_id[2];	// ����ID, �ڵ尪��������
	char dist_adj_code[1];	// ������뱸���ڵ�, 1:��а���, 2:�������
	char dist_code[1];	// ���ó�������ڵ�, 1:�ż�����, 2:�ż�����,\n 3:�ŵ�����, 4:�ŵ�����\n *��������� �ڵ����(spaceó��)
	char dist_cls_t[8];	// ��������ð�
	char ff[1];	// End of Text, 0xFF
} K200_OPT_DIST_INFO;


// K200�ɼ�_�ǽð������Ѱ� ���������
typedef struct _K200_OPT_REAL_HIGH_LOW_LIMIT_ON_OFF {
	char data_clsf[2];	// DATA����, Q2
	char info_clsf[2];	// ��������, 03:KOSPI200�����ɼ�
	char mrk_clsf[1];	// ���屸��, 4
	char isin_clsf[12];	// �����ڵ�
	char stk_snr[4];	// �����Ϸù�ȣ, �����Ϸù�ȣ �ڸ��� ����(3->4)
	char brd_id[2];	// ����ID, �ڵ尪��������
	char cleared_t[8];	// ó���ð�
	char real_t_prc_limit_code[1];	// �ǽð��������Ѽ����ڵ�, 0: ����, 1: ����, 2: �缳��
	char real_t_high_prc[5];	// �ǽð����Ѱ�, ��)999.99 ���߰��̵�����
	char real_t_low_prc[5];	// �ǽð����Ѱ�, ��)999.99 ���߰��̵�����
	char ff[1];	// End of Text, 0xFF
} K200_OPT_REAL_HIGH_LOW_LIMIT_ON_OFF;


// K200�ɼ�_����������Ȯ��ߵ�
typedef struct _K200_OPT_PRC_LIMIT_ON {
	char data_clsf[2];	// DATA����, V1
	char info_clsf[2];	// ��������, 03:KOSPI200�����ɼ�
	char mrk_clsf[1];	// ���屸��, 4
	char code_clsf[12];	// �����ڵ�
	char stk_snr[4];	// �����Ϸù�ȣ, �����Ϸù�ȣ �ڸ��� ����(3->4)
	char prd_id[11];	// ��ǰID, �ڵ尪�������� : spaceó��
	char brd_id[2];	// ����ID, �ڵ尪��������
	char prc_limit_start_t[8];	// ����Ȯ��ð�, ������ Ȯ��� �ð�
	char prc_limit_high[2];	// ��������Ȯ����Ѵܰ�, ����� ���Ѵܰ�
	char prc_limit_low[2];	// ��������Ȯ�����Ѵܰ�, ����� ���Ѵܰ�
	char high_prc[5];	// ���Ѱ�, ����� ���Ѱ�\n��)999.99
	char low_prc[5];	// ���Ѱ�, ����� ���Ѱ�\n��)999.99
	char ff[1];	// End of Text, 0xFF
} K200_OPT_PRC_LIMIT_ON;


// K200�ɼ�_SPACE
typedef struct _K200_OPT_SPACE {
	char data_clsf[2];	// DATA����, G9
	char info_clsf[2];	// ��������, 03:KOSPI200�����ɼ�
	char mrk_clsf[1];	// ���屸��, 4
	char ff[1];	// End of Text, 0xFF
} K200_OPT_SPACE;


// K200�ɼ�_�̰����������� ������
typedef struct _K200_OPT_OPEN_INTEREST_DATA {
	char data_clsf[2];	// DATA����, H2
	char info_clsf[2];	// ��������, 03:KOSPI200�����ɼ�
	char mrk_clsf[1];	// ���屸��, 4
	char isin_clsf[12];	// �����ڵ�, ���� record '999999999999' set
	char stk_snr[4];	// ����SEQ, ����SEQ �ڸ��� ����(3->4)
	char open_interest_clsf[2];	// �̰�����������, ���� Ȯ�� : "M0" (07:40�а� ����)\n���� ���� : "M1" (���� Ư���������� ��������\n         �۽�, 10��)\n���� Ȯ�� : "M2" (���� ������ �۽�,\n         ������ 1�ð��� ����)\n*�������� ù��° �����ʹ� �尳�������ǰŷ��� ����
	char traded_date[8];	// �ŷ�����
	char open_interest_q[9];	// �̰�����������, ����:���
	char ff[1];	// End of Text, 0xFF
} K200_OPT_OPEN_INTEREST_DATA;


// K200�ɼ�_�Ÿ����űݱ��ذ� ������
typedef struct _K200_OPT_TRD_MRG_STD_PRC_DATA {
	char data_clsf[2];	// DATA����, H3
	char info_clsf[2];	// ��������, 03:KOSPI200�����ɼ�
	char mrk_clsf[1];	// ���屸��, 4
	char isin_clsf[12];	// �����ڵ�, ���� record '999999999999' set
	char stk_snr[4];	// ����SEQ, ����SEQ �ڸ��� ����(3->4)
	char trd_mrg_std_prc[16];	// �Ÿ����űݱ��ذ�, ��) 99999999.99999999
	char trd_mrg_std_prc_clsf[1];	// �Ÿ����űݱ��ذ�����, 0 : ���ű� ���ذ� ����(���� �ŷ������� �⼼ ����)\n1 : ���� ����(�Ǽ�)\n2 : ���� �⼼(���� �ŷ������� �⼼)\n -2012.05.14 ����\n3 : ���� ���ű� ���ذ�(�ŷ������� ���� ������)\n -2012.05.14 ����\n4 : ���� �̷а�(�ŷ������� ���� ������)\n5 : �����������űݱ��ذ�(�ŷ������� ���� ������)\n -2012.05.14 ����
	char opt_exec_right_set_prc[16];	// �ɼǱǸ�����������, ��) 99999999.99999999
	char opt_exec_right_set_prc_clsf[1];	// �ɼǱǸ����������ݱ���
	char ff[1];	// End of Text, 0xFF
} K200_OPT_TRD_MRG_STD_PRC_DATA;


// K200�ɼ�_�������� ������
typedef struct _K200_OPT_PRD_INFO_DATA {
	char data_clsf[2];	// DATA����, AO
	char info_clsf[2];	// ��������, 03:KOSPI200�����ɼ�
	char mrk_clsf[1];	// ���屸��, 4
	char prd_cnt[5];	// �����
	char trd_date[8];	// ��������(��ȸ����)
	char isin_clsf[12];	// �����ڵ�, ���� record '999999999999' set
	char stk_snr[6];	// ����SEQ
	char prd_id[11];	// ��ǰID, * �ڵ尪 ������ ����* ����Ī: �Ļ���ǰID10 => 11, 20140303
	char sh_prd_code[9];	// ��������ڵ�, ��) KR4101C90009 �� K101C9000
	char prd_name_kor[80];	// �����ѱ۸�
	char sh_prd_name_kor[40];	// �����ѱ۾��
	char prd_name_eng[80];	// ���񿵹���
	char sh_prd_name_eng[40];	// ���񿵹����
	char listing_date[8];	// ��������
	char de_listing_date[8];	// ������������
	char spread_clsf_code[1];	// ��������������񱸺��ڵ�, ���������� ������ �Ǵ� ������ ISIN ǥ���ڵ�--�ڵ尪--F: ������(�ð���������)N: �ٿ���(�ð���������)20140303
	char final_sett_code[1];	// ������������ڵ�, ���ݰ���, �ǹ��μ������� �� �Ļ���ǰ�� �������� ���--�ڵ尪--C: ���ݰ���D: �ǹ��μ�������A: ����+�ǹ��μ�������0: �ش����\n20140303
	char prc_limit_exp_dir[1];	// ��������Ȯ����������ڵ�, ���������� �ٴܰ�� ���ǵǴ� ��� ���� �ܰ�� Ȯ��Ǵ� ����� ������ �� Ȯ�븦 �����ϴ� ����## �ڵ尪##X:������F:������B:������T:�����
	char prc_limit_final_stg[3];	// �������������ܰ�, ���������� �ٴܰ�� ���ǵǴ� ��� ������ �����ܰ��ȣ
	char prc_limit_stg_1_hgh_sign[1];	// ��������1�ܰ�SIGN��ȣ
	char prc_limit_stg_1_high_prc[12];	// ��������1�ܰ���Ѱ�, ��) 9999999999.99
	char prc_limit_stg_1_low_sign[1];	// ��������1�ܰ�SIGN��ȣ
	char prc_limit_stg_1_low_prc[12];	// ��������1�ܰ����Ѱ�, ��) 9999999999.99
	char prc_limit_stg_2_high_sign[1];	// ��������2�ܰ�SIGN��ȣ
	char prc_limit_stg_2_high_prc[12];	// ��������2�ܰ���Ѱ�, ��) 9999999999.99
	char prc_limit_stg_2_low_sign[1];	// ��������2�ܰ�SIGN��ȣ
	char prc_limit_stg_2_low_prc[12];	// ��������2�ܰ����Ѱ�, ��) 9999999999.99
	char prc_limit_stg_3_high_sign[1];	// ��������3�ܰ�SIGN��ȣ
	char prc_limit_stg_3_high_prc[12];	// ��������3�ܰ���Ѱ�, ��) 9999999999.99
	char prc_limit_stg_3_low_sign[1];	// ��������3�ܰ�SIGN��ȣ
	char prc_limit_stg_3_low_prc[12];	// ��������3�ܰ����Ѱ�, ��) 9999999999.99
	char stand_prc[12];	// ���ذ�, ��) 9999999999.99
	char under_asset_id[3];	// �����ڻ�ID, ��) K2I:KOSPI200����, KQI:�ڽ���150, Sxx:�����ֽ�, BM3:��3�ⱹä, BM5:��5�ⱹä, BMA:��10�ⱹä, CDR:CD, USD:�̱��޷�, JPY:�Ϻ���, EUR:��������, GLD:��, LHG:����20140303
	char opt_type_code[1];	// �Ǹ���������ڵ�, A:�̱���,E:������,Z:��Ÿ
	char spread_str_code[2];	// �������屸���ڵ�, Combination ȣ���� ��ü�� �������幰�� ���񱸼�.--�ڵ尪--- T1: �ֱٿ���+2°����      > T2, T3, T4, ...\n*����Ī: �������������ڵ�20140303
	char spread_prd_code_1[12];	// �������屸�������ڵ�1, * ����Ī: ��������ٿ��� �����ڵ�ٿ��� ǥ���ڵ�20140303
	char spread_prd_code_2[12];	// �������屸�������ڵ�2, * ����Ī: ��������ٿ��� �����ڵ�ٿ��� ǥ���ڵ�20140303
	char last_trading_date[8];	// �����ŷ�����
	char final_sett_date[8];	// ������������
	char cont_month_nbr[3];	// ��������ȣ, * ����Ī: ���������ڵ�1:�ֱٿ���,������������2:2°����3:3°����4:4°����5:5°����6:6°����7:7°����      �� �ֱٿ������� ��ġ\nX => 9, 1 => 3, 20140303
	char maturity_date[8];	// ��������, �Ǹ���� ������ ��������
	char exe_prc[17];	// ��簡��, ��) 999999999.99999999
	char adjust_clsf_code[1];	// ���������ڵ�, �����ڻ��� ���ذ��� ������ ����� ����(�̰�������)���� ������� ����(�ŷ��¼�����)������ ����--�ڵ尪--N: ����O: �̰�������\nC: �ŷ��¼�����20140303
	char prd_unit[17];	// �ŷ�����, 1��࿡ �ش��ϴ� �����ڻ������) 999999999.99999999=> Exture������ 1�̾�����, Exture+������ 500000��\n20140303
	char multiplier[21];	// �ŷ��¼�, ������� �� ������ ����ϴ� ���¼���) 9999999999999.99999999
	char mrk_cnst_code[1];	// �������������ڵ�, 0:�̽�����������1:���Ͻ�����������2:���Ž�����������
	char listing_type_code[1];	// ���������ڵ�, 1:�űԻ���2:�߰�����3:��������4:���ʻ���5:��������6:Ư������
	char atm_prc[12];	// ���, �����ڻ���ذ��ݿ� ���� ����� ��簡�ݿ�) 9999999999.99
	char adj_reason_code[2];	// ���������ڵ�, 00:�ش���׾���, 01:�Ǹ���, 02:����,03:�й��, 04:�ǹ��, 05:�߰�����,06:�Ǹ��߰�����, 99:��Ÿ
	char under_asset_prd_code[12];	// �����ڻ������ڵ�
	char under_asset_close_prc[12];	// �����ڻ�����, ��) 9999999999.99
	char left_until_maturity[7];	// �����ϼ�
	char adj_std_prc[17];	// �������ذ���, �ֽ��Ļ���ǰ�� �����ֱ� �������ذ��ݿ�) 999999999.99999999
	char std_prc_clsf_code[2];	// ���ذ��ݱ����ڵ�, *����spcace:���ذ� ����(���� ������������)11:�������갡12:���ϱ��ذ�(�ŷ������� ����������)13:�����̷а�(�ŷ������� ����������)\n14:���ϱ⼼(�ŷ������� �⼼����)  -2012.05.14 ����15:�����̷а�(�ŷ������� �⼼����)-  -2012.05.14 ����\n16:������ �������갡17:������ ���ϱ��ذ�  (�ŷ������� ����������)18:������ ���ϱ⼼(�ŷ������� �⼼����)  -2012.05.14 ����\n19:���� ����ڻ� ����(�̷а����� ��ǰ)*�ɼ�21:�������űݱ��ذ�22:���ϱ��ذ�(�ŷ������� ����������)23:�����̷а�(�ŷ������� ����������)\n24:���ϱ⼼(�ŷ������� �⼼����)  -2012.05.14 ����25:������ �������űݱ��ذ�26:������ ���ϱ��ذ�  (�ŷ������� ����������)\n27:������ ���ϱ⼼(�ŷ������� �⼼����)  -2012.05.14 ����
	char trd_std_prc_clsf_code[1];	// �Ÿſ���ذ��ݱ����ڵ�, 0:�ش����1:�Ǽ�2:�⼼3:�̷а�4:����ڻ�����
	char yest_adj_close_prc_sign[1];	// SIGN��ȣ
	char yest_adj_close_prc[17];	// ������������, �ֽ��Ļ���ǰ�� ����������) 999999999.99999999
	char block_trd_clsf[1];	// ���Ǵ뷮�ŸŴ�󿩺�, Y:���ǸŸŻ�ǰ, N:���ƴ԰���ǰ��:3�⹰��ä����, �̱��޷�����,      ���μ���, ������
	char yest_mrg_std_prc[17];	// �������űݱ��ذ���, ��) 999999999.99999999
	char yest_mrg_std_prc_clsf_code[2];	// �������űݱ��ذ��ݱ����ڵ�, *�ɼ�20:���ű� ���ذ� ����21:��������(�Ǽ�)22:���ϱ⼼(�ŷ������ı⼼)  -2012.05.14 ����23:�������űݱ��ذ�\n  (�ŷ������� ����������)  -2012.05.14 ����24:�����̷а�(�ŷ������� ����������)25:�����������űݱ��ذ�  (�ŷ������� ����������)\n  -2012.05.14 ����
	char sett_theory_prc[15];	// �����̷а���, �ؿɼ��� ��� ���űݱ��ذ��� ��) 999999999.999999
	char std_theory_prc[15];	// �����̷а���, ��) 999999999.999999
	char yest_sett_prc[17];	// �������갡��, ��) 999999999.99999999
	char halt_trd_clsf[1];	// �ŷ���������, Y, N
	char ft_cb_high_prc[12];	// ����Circuit_Breakers���Ѱ�, ���� CB �ߵ������� �Ǵ��ϱ� ���� ���Ѱ���(���ذ���� +/-5%�� CB �ߵ������� ��� +5%�� ����� ����)��) 9999999999.99
	char ft_cb_low_prc[12];	// ����Circuit_Breakers���Ѱ�, ���� CB �ߵ������� �Ǵ��ϱ� ���� ���Ѱ���(���ذ���� +/-5%�� CB �ߵ������� ��� -5%�� ����� ����)��) 9999999999.99
	char check_exe_prc[17];	// ��ȸ����簡��, ��) 999999999.99999999
	char atm_clsf[1];	// ATM�����ڵ�, 0:����, 1:ATM, 2:ITM, 3:OTM
	char last_trading_clsf[1];	// �����ŷ��Ͽ���, Y, N
	char ex_divid_aft_value[15];	// �����Ĺ�簡ġ, �ֽ� �� �ְ����� ��ǰ���� �����- ���� : �����Ĺ̷���ġ- �ɼ� : ���������簡ġ��) 999999999.999999
	char yest_close_prc_sign[1];	// SIGN��ȣ
	char yest_close_prc[12];	// ��������, ��) 9999999999.99
	char yest_close_prc_clsf[1];	// �������������ڵ�, 1:�Ǽ�, 3:�ŷ���2:�⼼ -2012.05.14 ����
	char yest_init_prc_sign[1];	// SIGN��ȣ
	char yest_init_prc[12];	// ���Ͻð�, ��) 9999999999.99
	char yest_high_prc_sign[1];	// SIGN��ȣ
	char yest_high_pric[12];	// ���ϰ�, ��) 9999999999.99
	char yest_low_prc_sign[1];	// SIGN��ȣ
	char yest_low_prc[12];	// ��������, ��) 9999999999.99
	char yest_first_exe_date[8];	// ����ü������
	char yest_last_exe_time[8];	// ��������ü��ð�
	char yest_sett_prc_clsf[2];	// �������갡�ݱ����ڵ�, *���� 10:���갡���� 11:��������(�Ǽ�) 12:���ϱ⼼(�ŷ������ı⼼) 13:�������갡(�ŷ������� ����������)\n 14:�����̷а�(�ŷ������� ����������) 15:��������� ���� 16:������ ���� ���갡 17:����ڻ� ����(�̷а����� ��ǰ)
	char sett_prc_theory_prc_diff_pctg_sign[1];	// SIGN��ȣ
	char sett_prc_theory_prc_diff_pctg[12];	// ���갡���̷а��ݱ�����, ��) 999999.999999
	char yest_open_interest_q[10];	// ���Ϲ̰�����������
	char yest_s_limit_ord_prc_sign[1];	// SIGN��ȣ
	char yest_s_limit_ord_prc[12];	// ���ϸŵ��켱ȣ������, ��) 9999999999.99
	char yest_l_limit_ord_prc_sign[1];	// SIGN��ȣ
	char yest_l_limit_ord_prc[12];	// ���ϸż��켱ȣ������, ��) 9999999999.99
	char implied_vol[10];	// ���纯����, ��) 999999.9999
	char listed_high_prc_sign[1];	// SIGN��ȣ
	char listed_high_prc[12];	// �������ְ�, ��) 9999999999.99
	char listed_low_prc_sign[1];	// SIGN��ȣ
	char listed_low_prc[12];	// ������������, ��) 9999999999.99
	char year_high_prc_sign[1];	// SIGN��ȣ
	char year_high_prc[12];	// �����ְ�, ��) 9999999999.99
	char year_low_prc_sign[1];	// SIGN��ȣ
	char year_low_prc[12];	// ����������, ��) 9999999999.99
	char listed_high_prc_date[8];	// �������ְ�����
	char listed_low_prc_date[8];	// ����������������
	char year_high_prc_date[8];	// �����ְ�����
	char year_low_prc_date[8];	// ��������������
	char year_std_date[8];	// ���������ϼ�
	char month_trd_date[8];	// �����ŷ��ϼ�
	char year_trd_date[8];	// �����ŷ��ϼ�
	char yest_exe_trd_cnt [16];	// ����ü��Ǽ�
	char yest_exe_q[12];	// ����ü�����, �������Ǵ뷮�Ÿ�ü������� ���Ե��� ����
	char yest_trd_amt[22];	// ���ϰŷ����, �������Ǵ뷮�ŸŰŷ������ ���Ե��� ����
	char yest_block_trd_exe_q[12];	// �������Ǵ뷮�ջ�ü�����, �������Ǵ뷮�Ÿ�ü����� => �������Ǵ뷮�ջ�ü����� [����ü�����+�������Ǵ뷮�Ÿ�ü�����(���Ǵ뷮+FLEX)];\n 2016.03.28 ����
	char yest_block_trd_total_amt[22];	// �������Ǵ뷮�ջ�ŷ����, �������Ǵ뷮�ŸŰŷ���� => �������Ǵ뷮�ջ�ŷ���� [���ϰŷ����+�������Ǵ뷮�ŸŰŷ����(���Ǵ뷮+FLEX)]; 2016.03.28 ����
	char cd_rate[6];	// CD�ݸ�, ��) 999.999
	char open_interest_q[15];	// �̰����ѵ�����, *�����Ͽ� ����Ǵ� ��ǰ�� ���º� �̰��� �ѵ� ����. �̰��� �ѵ��� ������� ���� ��ǰ�� 0*�ֽļ������� �ش�\n8 => 15, 20140303
	char product_cat[4];	// �Ҽ� ��ǰ��, *�ֽļ���/�ɼǿ��� �ش�
	char product_cat_off_pctg[9];	// ��ǰ�� �ɼ���, *������� ǥ��*�ֽļ���/�ɼǿ��� �ش翹) 9999999.995 => 9, 20140303
	char limit_ord_clsf_code[5];	// ������ȣ�����Ǳ����ڵ�, ȣ���� ü�� �� �ܷ�����. Bitwise ����--�ڵ尪--1: FAS (Fill And Store)2: FOK (Fill Or Kill)\n3: FAK (Fill And Kill)* ������ȣ�����Ǳ����ڵ� BITWISE ����\n���� Ȯ�强�� ���� �ش� 10�������� 2������ ��ȯ�Ͽ� ó�����(�ִ� 16bit���� ��밡��)�� ) ������ȣ�����Ǳ����ڵ� ���� 6�̸�\n    (������ 6 -> ������ 00000110)0��° bit 0 -> 0 : FAS1��° bit 1 -> 2 : FOK\n2��° bit 1 -> 4 : FAK��, FOK�̸鼭 FAK�� �����Ѵٴ� �ǹ� (FOK & FAK)\nX => 9, 1 => 5, 20140303
	char mrk_ord_clsf_code[5];	// ���尡ȣ�����Ǳ����ڵ�, * ��
	char cond_limit_ord_clsf_code[5];	// ���Ǻ�������ȣ�����Ǳ����ڵ�, * ��
	char best_limit_ord_clsf_code[5];	// ������������ȣ�����Ǳ����ڵ�, * ��
	char efp_clsf[1];	// EFP�ŷ���󿩺�, Y, N, ��ǰ������ �ش�
	char flex_clsf[1];	// FLEX�ŷ���󿩺�, Y, N, ��ǰ������ �ش�
	char yest_efp_exe_q[12];	// ����EFPü�����, ��ǰ������ �ش�
	char yest_efp_trd_amount[22];	// ����EFP�ŷ����, ��ǰ������ �ش�
	char mkr_close_clsf[1];	// ���忩��, ���忩�� (Y,N), 20121217
	char real_t_prc_limit_clsf[1];	// �ǽð��������ѿ���, ���� ü�ᰡ�� ��� Ư�� ������ �ʰ��ϴ� ȣ���� �ź��ϵ��� �������� ����(Y/N) 20140901
	char real_t_high_price_gap_sign[1];	// SIGN��ȣ, 20140901
	char real_t_high_price_gap[12];	// �ǽð����Ѱ�����, ���� ü�ᰡ�ݰ� �ǽð����Ѱ����� ���� �ǽð����Ѱ� = ����ü�ᰡ�� + �ǽð����Ѱ����� ex) 9999999999.99 20140901
	char real_t_low_price_gap_sign[1];	// SIGN��ȣ, 20140901
	char real_t_low_price_gap[12];	// �ǽð����Ѱ�����, ���� ü�ᰡ�ݰ� �ǽð����Ѱ����� ���� �ǽð����Ѱ� = ����ü�ᰡ�� + �ǽð����Ѱ�����(����) ex) 9999999999.99 20140901
	char under_ass_mrk_id[3];	// �����ڻ����ID, �����ڻ����ID�� �����ڻ��� KRX�� ����� ��쿡�� ä����.K200�����ɼ�:STK�ڽ���150����:KSQ�ֽļ����ɼ�:STK/KSQ ��ǰ�����ɼ�:SPACE��������������:STK������������:STK�̴�K200�����ɼ�:STK
	char upper_limit_ord_q[16];	// ���Ѽ���, ȣ�����Ѽ��� (20181210 �׸��߰�)
	char lower_limit_ord_q[16];	// ���Ѽ���, ȣ�����Ѽ��� (20181210 �׸��߰�)
	char block_trd_upper_limit_ord_q[16];	// ���Ǵ뷮�ŸŻ��Ѽ���, ���Ǵ뷮�Ÿ�ȣ�����Ѽ��� (20181210 �׸��߰�)
	char block_trd_lower_limit_ord_q[16];	// ���Ǵ뷮�Ÿ����Ѽ���, ���Ǵ뷮�Ÿ�ȣ�����Ѽ��� (20181210 �׸��߰�)
	char filler[60];	// Filler, 170 => 134, 20090831134 => 133, 20121217133 => 110, 20140303\n110 => 83, 2014090183  => 27, 2015061527  => 24, 20150720\n24 => 60 , 20181210 (��������� ���� 1200->1300)
	char ff[1];	// End of Text, 0xFF
} K200_OPT_PRD_INFO_DATA;


// K200�ɼ�_�ΰ���
typedef struct _K200_OPT_SENSITIVITY_DATA {
	char data_clsf[2];	// DATA����, N7
	char info_clsf[2];	// ��������, 03:KOSPI200�����ɼ�
	char mrk_clsf[1];	// ���屸��, 4
	char isin_clsf[12];	// �����ڵ�
	char stk_snr[7];	// ����SEQ
	char created_date[8];	// ��������
	char created_time[8];	// �����ð�
	char clsf_code[1];	// �����ڵ�, 1:����Ȯ��,2:���߻���,E:���߿Ϸ�,3:����Ȯ��
	char under_asset_id[3];	// �����ڻ�ID, K2I:KOSPI200
	char sensitivity_delta_sign[1];	// SIGN��ȣ
	char sensitivity_delta[18];	// �ΰ��� ��Ÿ, 9(12)V9(6)
	char sensitivity_theta_sign[1];	// SIGN��ȣ
	char sensitivity_theta[18];	// �ΰ��� ��Ÿ, 9(12)V9(6)
	char sensitivity_vega_sign[1];	// SIGN��ȣ
	char sensitivity_vega[18];	// �ΰ��� ����, 9(12)V9(6)
	char sensitivity_gamma_sign[1];	// SIGN��ȣ
	char sensitivity_gamma[18];	// �ΰ��� ����, 9(12)V9(6)
	char sensitivity_rho_sign[1];	// SIGN��ȣ
	char sensitivity_rho[18];	// �ΰ��� ��, 9(12)V9(6)
	char ff[1];	// End of Text, 0xFF
} K200_OPT_SENSITIVITY_DATA;


// KOSPI200�ɼ� ���纯����
typedef struct _K200_OPT_IMPLIED_VOL_DATA {
	char data_clsf[2];	// DATA����, P1
	char info_clsf[2];	// ��������, 03:KOSPI200�����ɼ�
	char mrk_clsf[1];	// ���屸��, 4
	char call_ave_implied_vol[10];	// ����ճ��纯����, 999999v9999
	char put_ave_implied_vol[10];	// ǲ��ճ��纯����, 999999v9999
	char rep_implied_vol[10];	// ��ǥ���纯����, 999999v9999
	char hist_vol_90_days[10];	// ������������(90��), 999999v9999
	char ff[1];	// FF, END OF TEXT (0xFF)
} K200_OPT_IMPLIED_VOL_DATA;


// K200�ɼ�_������ ������
typedef struct _K200_OPT_INVESTOR_DATA {
	char data_clsf[2];	// DATA����, H1
	char info_clsf[2];	// ��������, 03:KOSPI200�����ɼ�
	char mrk_clsf[1];	// ���屸��, 4
	char created_date[8];	// ��������
	char created_time[6];	// �����ð�
	char inv_data_clsf[2];	// �����ͱ���, *����Ȯ�� : 00, �������� : 01, ����Ȯ�� : 02\n *E1 : ���� ������ �Ϸ�, E2 : Ȯ�� ������ �Ϸ�\n ���� record '99' set\n *�������� ù��° �����ʹ� �尳�������ǰŷ��� ����
	char prd_id[11];	// ��ǰID, �ڵ尪�������� - KRDRVOPK2I
	char opt_clsf[1];	// �ɼǱ���, C:�ݿɼ�, P:ǲ�ɼ�
	char inv_clsf[4];	// ����������, �ڵ尪���� ���� *�ڵ� '7000'�� ����,��������׸� 0���� ����
	char long_exe_q[9];	// �ż� ��������
	char short_exe_q[9];	// �ŵ� ��������
	char long_traded_amt[18];	// �ż� �������
	char short_traded_amt[18];	// �ŵ� �������
	char ff[1];	// End of Text, 0xFF
} K200_OPT_INVESTOR_DATA;


// K200�ɼ�_�ü�Recovery ������
typedef struct _K200_OPT_RECOVERY_DATA {
	char data_clsf[2];	// DATA����, B2
	char info_clsf[2];	// ��������, 03:KOSPI200�����ɼ�
	char mrk_clsf[1];	// ���屸��, 4
	char isin_clsf[12];	// �����ڵ�
	char stk_snr[4];	// �����Ϸù�ȣ, �����Ϸù�ȣ �ڸ��� ����(3->4)
	char cur_prc[5];	// ���簡, ��) 999.99
	char init_prc[5];	// �ð�, ��) 999.99
	char high_prc[5];	// ��, ��) 999.99
	char low_prc[5];	// ����, ��) 999.99
	char open_interest_q[9];	// �̰�����
	char accm_exe_q[8];	// ����ü�����
	char accm_trd_amt[11];	// �����ŷ����, ����:õ��
	char accm_block_trd_exe_q[8];	// ���Ǵ뷮����ü�����, ������(Filler)
	char l_or_s[1];	// �����ŵ��ż������ڵ�, 1:�ŵ�,2:�ż�(�������� ���� ȣ���� �ŵ��ż����а�)
	char s_lvl_1_prc[5];	// �ŵ�1ȣ��, ��) 999.99
	char s_lvl_1_q[7];	// �ŵ�1ȣ������
	char s_lvl_1_trd_cnt[4];	// �ŵ�1ȣ���Ǽ�
	char l_lvl_1_prc[5];	// �ż�1ȣ��, ��) 999.99
	char l_lvl_1_q[7];	// �ż�1ȣ������
	char l_lvl_1_trd_cnt[4];	// �ż�1ȣ���Ǽ�
	char s_lvl_2_prc[5];	// �ŵ�2ȣ��, ��) 999.99
	char s_lvl_2_q[7];	// �ŵ�2ȣ������
	char s_lvl_2_trd_cnt[4];	// �ŵ�2ȣ���Ǽ�
	char l_lvl_2_prc[5];	// �ż�2ȣ��, ��) 999.99
	char l_lvl_2_q[7];	// �ż�2ȣ������
	char l_lvl_2_trd_cnt[4];	// �ż�2ȣ���Ǽ�
	char s_lvl_3_prc[5];	// �ŵ�3ȣ��, ��) 999.99
	char s_lvl_3_q[7];	// �ŵ�3ȣ������
	char s_lvl_3_trd_cnt[4];	// �ŵ�3ȣ���Ǽ�
	char l_lvl_3_prc[5];	// �ż�3ȣ��, ��) 999.99
	char l_lvl_3_q[7];	// �ż�3ȣ������
	char l_lvl_3_trd_cnt[4];	// �ż�3ȣ���Ǽ�
	char s_lvl_4_prc[5];	// �ŵ�4ȣ��, ��) 999.99
	char s_lvl_4_q[7];	// �ŵ�4ȣ������
	char s_lvl_4_trd_cnt[4];	// �ŵ�4ȣ���Ǽ�
	char l_lvl_4_prc[5];	// �ż�4ȣ��, ��) 999.99
	char l_lvl_4_q[7];	// �ż�4ȣ������
	char l_lvl_4_trd_cnt[4];	// �ż�4ȣ���Ǽ�
	char s_lvl_5_prc[5];	// �ŵ�5ȣ��, ��) 999.99
	char s_lvl_5_q[7];	// �ŵ�5ȣ������
	char s_lvl_5_trd_cnt[4];	// �ŵ�5ȣ���Ǽ�
	char l_lvl_5_prc[5];	// �ż�5ȣ��, ��) 999.99
	char l_lvl_5_q[7];	// �ż�5ȣ������
	char l_lvl_5_trd_cnt[4];	// �ż�5ȣ���Ǽ�
	char total_s_limit_ord_q[7];	// �ŵ� ��ȣ������
	char total_s_trd_cnt[5];	// �ŵ���ȿȣ���Ǽ�
	char total_l_limit_ord_q[7];	// �ż� ��ȣ������
	char total_l_trd_cnt[5];	// �ż���ȿȣ���Ǽ�
	char ss_id[2];	// ����ID, �ڵ尪��������
	char brd_id[2];	// ����ID, �ڵ尪��������
	char brd_event_id[3];	// �����̺�ƮID, B2 ������ �����̺�ƮID ������(���� ���°��� ���۵� �� ����). ����, �ش� �׸� '000' ���� ����. 2014.03.24)
	char exp_prc[5];	// ����ü�ᰡ��, ��) 999.99 ���ϰ��ŸŽø� ����\n (����±����ڵ�:10,20,30,80)
	char real_t_high_prc[5];	// �ǽð����Ѱ�, ��) 999.99 ���߰��̵�����
	char real_t_low_prc[5];	// �ǽð����Ѱ�, ��) 999.99 ���߰��̵�����
	char ff[1];	// End of Text, 0xFF
} K200_OPT_RECOVERY_DATA;


// K200�ɼ�_Polling ������
typedef struct _K200_OPT_POLLING_DATA {
	char data_clsf[2];	// DATA����, I2
	char info_clsf[2];	// ��������, 03:KOSPI200�����ɼ�
	char mrk_clsf[1];	// ���屸��, 4
	char send_t[4];	// ���۽ð�, HHSS
	char main_backup_clsf[2];	// Main Backup����, space
	char filler[8];	// Filler
	char ff[1];	// End of Text, 0xFF
} K200_OPT_POLLING_DATA;


// K200�ɼ�_�尳�������ǰŷ�
typedef struct _K200_OPT_BLOCK_TRD_BEF_MRK_OPEN {
	char data_clsf[2];	// DATA����, M7
	char info_clsf[2];	// ��������, 03:KOSPI200�����ɼ�
	char mrk_clsf[1];	// ���屸��, 4
	char isin_clsf[12];	// �����ڵ�, ���� record '999999999999' set
	char stk_snr[4];	// ����SEQ, ����SEQ �ڸ��� ����(3->4)
	char exe_prc[5];	// ü�ᰡ��, ��) 999.99 (���۴��� ���� ���ذ���)
	char exe_q[7];	// ü�����, �尳�������ǰŷ� ü�� ������ ��� �ջ��� ����
	char exe_clsf_code[2];	// ü�������ڵ�, ���ǰŷ�\n 46 : EUREX
	char filler[15];	// Filler
	char ff[1];	// End of Text, 0xFF
} K200_OPT_BLOCK_TRD_BEF_MRK_OPEN;
