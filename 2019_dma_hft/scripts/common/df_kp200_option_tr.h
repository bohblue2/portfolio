// df_kp200_option_tr.h
// KOSPI200 �����ɼ� �ǽð� TR

#pragma once
// �ּ��� \n�� ���� ���߿� �̻ڰ� �ٲ����


// K200�ɼ�_����+�����ջ�
typedef struct _DF_K200_OPT_COMP_BLOCK {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����, C4
	char info_clsf[3];	// ��������, 03:KOSPI200�����ɼ�
	char mkt_clsf;	// ���屸��, 4
	char isin_clsf[13];	// �����ڵ�
	int stk_snr;	// �����Ϸù�ȣ
	double cpt_block_trd_vol;	// ����+�����ջ� �ŷ���, ����Ÿſ� ���Ǵ뷮�ŷ��� �ջ��� �ŷ���
	double cpt_block_trd_amt;	// ����+�����ջ� �ŷ����, ����Ÿſ� ���Ǵ뷮�ŷ��� �ջ��� �ŷ����\n(���� : ��)
} DF_K200_OPT_COMP_BLOCK;


// K200�ɼ�_ü��
typedef struct _DF_K200_OPT_EXEC {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����, A3
	char info_clsf[3];	// ��������, 03:KOSPI200�����ɼ�
	char mrk_clsf;	// ���屸��, 4
	char isin_clsf[13];	// �����ڵ�
	int stk_snr;	// �����Ϸù�ȣ, �����Ϸù�ȣ �ڸ��� ����(3->4)
	char brd_id[3];	// ����ID, �ڵ尪��������
	double cur_prc;	// ���簡��, ��) 999.99
	int exe_q;	// ü�����
	char ss_id[3];	// ����ID, �ڵ尪��������
	char exe_t[9];	// ü��ð�
	double init_prc;	// �ð�, ��) 999.99
	double high_prc;	// ��, ��) 999.99
	double low_prc;	// ����, ��) 999.99
	double pri_prc;	// ��������, ��) 999.99
	int accm_exe_q;	// ����ü�����
	double accm_trd_amt;	// �����ŷ����, ����:õ��
	char l_or_s;	// �����ŵ��ż������ڵ�, 1:�ŵ�,2:�ż�(�������� ���� ȣ���� �ŵ��ż����а�)
	double real_t_high_prc;	// �ǽð����Ѱ�, ��) 999.99 ���߰��̵�����
	double real_t_low_prc;	// �ǽð����Ѱ�, ��) 999.99 ���߰��̵�����
} DF_K200_OPT_EXEC;


// K200�ɼ�_�켱ȣ��
typedef struct _DF_K200_OPT_LIMIT_ORD {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����, B6
	char info_clsf[3];	// ��������, 03:KOSPI200�����ɼ�
	char mrk_clsf;	// ���屸��, 4
	char isin_clsf[13];	// �����ڵ�
	int stk_snr;	// �����Ϸù�ȣ, �����Ϸù�ȣ �ڸ��� ����(3->4)
	char brd_id[3];	// ����ID, �ڵ尪��������
	char ss_id[3];	// ����ID, �ڵ尪��������
	int total_l_limit_ord_q;	// �ż���ȣ���ܷ�
	double l_lvl_1_prc;	// �ż�1�ܰ�켱ȣ������, ��) 999.99
	int l_lvl_1_q;	// �ż�1�ܰ�켱ȣ���ܷ�
	double l_lvl_2_prc;	// �ż�2�ܰ�켱ȣ������, ��) 999.99
	int l_lvl_2_q;	// �ż�2�ܰ�켱ȣ���ܷ�
	double l_lvl_3_prc;	// �ż�3�ܰ�켱ȣ������, ��) 999.99
	int l_lvl_3_q;	// �ż�3�ܰ�켱ȣ���ܷ�
	double l_lvl_4_prc;	// �ż�4�ܰ�켱ȣ������, ��) 999.99
	int l_lvl_4_q;	// �ż�4�ܰ�켱ȣ���ܷ�
	double l_lvl_5_prc;	// �ż�5�ܰ�켱ȣ������, ��) 999.99
	int l_lvl_5_q;	// �ż�5�ܰ�켱ȣ���ܷ�
	int total_s_limit_ord_q;	// �ŵ���ȣ���ܷ�
	double s_lvl_1_prc;	// �ŵ�1�ܰ�켱ȣ������, ��) 999.99
	int s_lvl_1_q;	// �ŵ�1�ܰ�켱ȣ���ܷ�
	double s_lvl_2_prc;	// �ŵ�2�ܰ�켱ȣ������, ��) 999.99
	int s_lvl_2_q;	// �ŵ�2�ܰ�켱ȣ���ܷ�
	double s_lvl_3_prc;	// �ŵ�3�ܰ�켱ȣ������, ��) 999.99
	int s_lvl_3_q;	// �ŵ�3�ܰ�켱ȣ���ܷ�
	double s_lvl_4_prc;	// �ŵ�4�ܰ�켱ȣ������, ��) 999.99
	int s_lvl_4_q;	// �ŵ�4�ܰ�켱ȣ���ܷ�
	double s_lvl_5_prc;	// �ŵ�5�ܰ�켱ȣ������, ��) 999.99
	int s_lvl_5_q;	// �ŵ�5�ܰ�켱ȣ���ܷ�
	int total_l_trd_cnt;	// �ż���ȿȣ���Ǽ�
	int l_lvl_1_trd_cnt;	// �ż�1�ܰ�켱ȣ���Ǽ�
	int l_lvl_2_trd_cnt;	// �ż�2�ܰ�켱ȣ���Ǽ�
	int l_lvl_3_trd_cnt;	// �ż�3�ܰ�켱ȣ���Ǽ�
	int l_lvl_4_trd_cnt;	// �ż�4�ܰ�켱ȣ���Ǽ�
	int l_lvl_5_trd_cnt;	// �ż�5�ܰ�켱ȣ���Ǽ�
	int total_s_trd_cnt;	// �ŵ���ȿȣ���Ǽ�
	int s_lvl_1_trd_cnt;	// �ŵ�1�ܰ�켱ȣ���Ǽ�
	int s_lvl_2_trd_cnt;	// �ŵ�2�ܰ�켱ȣ���Ǽ�
	int s_lvl_3_trd_cnt;	// �ŵ�3�ܰ�켱ȣ���Ǽ�
	int s_lvl_4_trd_cnt;	// �ŵ�4�ܰ�켱ȣ���Ǽ�
	int s_lvl_5_trd_cnt;	// �ŵ�5�ܰ�켱ȣ���Ǽ�
	char ord_rcv_t[9];	// ȣ�������ð�
	double exp_prc;	// ����ü�ᰡ��, ��) 999.99 ���ϰ��ŸŽø� ����\n (����±����ڵ�:10,20,30,80)
} DF_K200_OPT_LIMIT_ORD;


// K200�ɼ�_ü��_�켱ȣ��
typedef struct _DF_K200_OPT_EXEC_LIMIT_ORD {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����, G7
	char info_clsf[3];	// ��������, 03:KOSPI200�����ɼ�
	char mrk_clsf;	// ���屸��, 4
	char isin_clsf[13];	// �����ڵ�
	int stk_snr;	// �����Ϸù�ȣ, �����Ϸù�ȣ �ڸ��� ����(3->4)
	char brd_id[3];	// ����ID, �ڵ尪��������
	double cur_prc;	// ���簡��, ��) 999.99
	int exe_q;	// ü�����
	char ss_id[3];	// ����ID, �ڵ尪��������
	char exe_t[9];	// ü��ð�
	double init_prc;	// �ð�, ��) 999.99
	double high_prc;	// ��, ��) 999.99
	double low_prc;	// ����, ��) 999.99
	double pri_prc;	// ��������, ��) 999.99
	int accm_exe_q;	// ����ü�����
	double accm_trd_amt;	// �����ŷ����, ����:õ��
	char l_or_s;	// �����ŵ��ż������ڵ�, 1:�ŵ�,2:�ż�(�������� ���� ȣ���� �ŵ��ż����а�)
	int total_l_limit_ord_q;	// �ż���ȣ���ܷ�
	double l_lvl_1_prc;	// �ż�1�ܰ�켱ȣ������, ��) 999.99
	int l_lvl_1_q;	// �ż�1�ܰ�켱ȣ���ܷ�
	double l_lvl_2_prc;	// �ż�2�ܰ�켱ȣ������, ��) 999.99
	int l_lvl_2_q;	// �ż�2�ܰ�켱ȣ���ܷ�
	double l_lvl_3_prc;	// �ż�3�ܰ�켱ȣ������, ��) 999.99
	int l_lvl_3_q;	// �ż�3�ܰ�켱ȣ���ܷ�
	int l_lvl_4_prc;	// �ż�4�ܰ�켱ȣ������
	int l_lvl_4_q;	// �ż�4�ܰ�켱ȣ���ܷ�
	double l_lvl_5_prc;	// �ż�5�ܰ�켱ȣ������, ��) 999.99
	int l_lvl_5_q;	// �ż�5�ܰ�켱ȣ���ܷ�
	int total_s_limit_ord_q;	// �ŵ���ȣ���ܷ�
	double s_lvl_1_prc;	// �ŵ�1�ܰ�켱ȣ������, ��) 999.99
	int s_lvl_1_q;	// �ŵ�1�ܰ�켱ȣ���ܷ�
	int s_lvl_2_prc;	// �ŵ�2�ܰ�켱ȣ������
	double s_lvl_2_q;	// �ŵ�2�ܰ�켱ȣ���ܷ�, ��) 999.99
	int s_lvl_3_prc;	// �ŵ�3�ܰ�켱ȣ������
	int s_lvl_3_q;	// �ŵ�3�ܰ�켱ȣ���ܷ�
	double s_lvl_4_prc;	// �ŵ�4�ܰ�켱ȣ������, ��) 999.99
	int s_lvl_4_q;	// �ŵ�4�ܰ�켱ȣ���ܷ�
	int s_lvl_5_prc;	// �ŵ�5�ܰ�켱ȣ������
	double s_lvl_5_q;	// �ŵ�5�ܰ�켱ȣ���ܷ�, ��) 999.99
	int total_l_trd_cnt;	// �ż���ȿȣ���Ǽ�
	int l_lvl_1_trd_cnt;	// �ż�1�ܰ�켱ȣ���Ǽ�
	int l_lvl_2_trd_cnt;	// �ż�2�ܰ�켱ȣ���Ǽ�
	double l_lvl_3_trd_cnt;	// �ż�3�ܰ�켱ȣ���Ǽ�, ��) 999.99
	int l_lvl_4_trd_cnt;	// �ż�4�ܰ�켱ȣ���Ǽ�
	int l_lvl_5_trd_cnt;	// �ż�5�ܰ�켱ȣ���Ǽ�
	double total_s_trd_cnt;	// �ŵ���ȿȣ���Ǽ�, ��) 999.99
	int s_lvl_1_trd_cnt;	// �ŵ�1�ܰ�켱ȣ���Ǽ�
	int s_lvl_2_trd_cnt;	// �ŵ�2�ܰ�켱ȣ���Ǽ�
	double s_lvl_3_trd_cnt;	// �ŵ�3�ܰ�켱ȣ���Ǽ�, ��) 999.99
	int s_lvl_4_trd_cnt;	// �ŵ�4�ܰ�켱ȣ���Ǽ�
	int s_lvl_5_trd_cnt;	// �ŵ�5�ܰ�켱ȣ���Ǽ�
	double real_t_high_prc;	// �ǽð����Ѱ�, ��) 999.99 ���߰��̵�����
	double real_t_low_prc;	// �ǽð����Ѱ�, ��) 999.99 ���߰��̵�����
} DF_K200_OPT_EXEC_LIMIT_ORD;


// K200�ɼ�_���񸶰�
typedef struct _DF_K200_OPT_CLOSE_PRODUCT {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����, A6
	char info_clsf[3];	// ��������, 03:KOSPI200�����ɼ�
	char mrk_clsf;	// ���屸��, 4
	char isin_clsf[13];	// �����ڵ�
	int stk_snr;	// �����Ϸù�ȣ, �����Ϸù�ȣ �ڸ��� ����(3->4)
	char brd_id[3];	// ����ID, �ڵ尪��������
	double close_prc;	// ����, *�ŷ��� ������ ��� ���ذ� set, ��) 999.99
	char close_prc_code;	// ���������ڵ�, 1:ü�ᰡ��, 3:�ŷ���\n 2:�⼼ -2012.05.14 ����\n ' ':�������� �ƴ� ��� space
	int accm_exe_q;	// ����ü�����
	double accm_trd_amt;	// �����ŷ����, ����:õ��
	int total_l_limit_ord_q;	// �ż���ȣ���ܷ�
	double l_lvl_1_prc;	// �ż�1�ܰ�켱ȣ������, ��) 999.99
	int l_lvl_1_q;	// �ż�1�ܰ�켱ȣ���ܷ�
	double l_lvl_2_prc;	// �ż�2�ܰ�켱ȣ������, ��) 999.99
	int l_lvl_2_q;	// �ż�2�ܰ�켱ȣ���ܷ�
	double l_lvl_3_prc;	// �ż�3�ܰ�켱ȣ������, ��) 999.99
	int l_lvl_3_q;	// �ż�3�ܰ�켱ȣ���ܷ�
	double l_lvl_4_prc;	// �ż�4�ܰ�켱ȣ������, ��) 999.99
	int l_lvl_4_q;	// �ż�4�ܰ�켱ȣ���ܷ�
	double l_lvl_5_prc;	// �ż�5�ܰ�켱ȣ������, ��) 999.99
	int l_lvl_5_q;	// �ż�5�ܰ�켱ȣ���ܷ�
	int total_s_limit_ord_q;	// �ŵ���ȣ���ܷ�
	double s_lvl_1_prc;	// �ŵ�1�ܰ�켱ȣ������, ��) 999.99
	int s_lvl_1_q;	// �ŵ�1�ܰ�켱ȣ���ܷ�
	double s_lvl_2_prc;	// �ŵ�2�ܰ�켱ȣ������, ��) 999.99
	int s_lvl_2_q;	// �ŵ�2�ܰ�켱ȣ���ܷ�
	double s_lvl_3_prc;	// �ŵ�3�ܰ�켱ȣ������, ��) 999.99
	int s_lvl_3_q;	// �ŵ�3�ܰ�켱ȣ���ܷ�
	double s_lvl_4_prc;	// �ŵ�4�ܰ�켱ȣ������, ��) 999.99
	int s_lvl_4_q;	// �ŵ�4�ܰ�켱ȣ���ܷ�
	double s_lvl_5_prc;	// �ŵ�5�ܰ�켱ȣ������, ��) 999.99
	int s_lvl_5_q;	// �ŵ�5�ܰ�켱ȣ���ܷ�
	int total_l_trd_cnt;	// �ż���ȿȣ���Ǽ�
	int l_lvl_1_trd_cnt;	// �ż�1�ܰ�켱ȣ���Ǽ�
	int l_lvl_2_trd_cnt;	// �ż�2�ܰ�켱ȣ���Ǽ�
	int l_lvl_3_trd_cnt;	// �ż�3�ܰ�켱ȣ���Ǽ�
	int l_lvl_4_trd_cnt;	// �ż�4�ܰ�켱ȣ���Ǽ�
	int l_lvl_5_trd_cnt;	// �ż�5�ܰ�켱ȣ���Ǽ�
	int total_s_trd_cnt;	// �ŵ���ȿȣ���Ǽ�
	int s_lvl_1_trd_cnt;	// �ŵ�1�ܰ�켱ȣ���Ǽ�
	int s_lvl_2_trd_cnt;	// �ŵ�2�ܰ�켱ȣ���Ǽ�
	int s_lvl_3_trd_cnt;	// �ŵ�3�ܰ�켱ȣ���Ǽ�
	int s_lvl_4_trd_cnt;	// �ŵ�4�ܰ�켱ȣ���Ǽ�
	int s_lvl_5_trd_cnt;	// �ŵ�5�ܰ�켱ȣ���Ǽ�
} DF_K200_OPT_CLOSE_PRODUCT;


// K200�ɼ�_��TS
typedef struct _DF_K200_OPT_MRK_OP_TS {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����, A7
	char info_clsf[3];	// ��������, 03:KOSPI200�����ɼ�
	char mrk_clsf;	// ���屸��, 4
	char isin_clsf[13];	// �����ڵ�
	int stk_snr;	// �����Ϸù�ȣ, �����Ϸù�ȣ �ڸ��� ����(3->4)
	char prd_id[12];	// ��ǰID, �ڵ尪�������� : spaceó��
	char brd_id[3];	// ����ID, �ڵ尪��������
	char brd_event_id[4];	// �����̺�ƮID, �ڵ尪��������
	char brd_event_start_t[9];	// �����̺�Ʈ���۽ð�, ������ �����(��:BB1(�ŸŰŷ�����)�� ��� 09000000)
	int brd_event_code;	// �����̺�Ʈ���뱺�ڵ�, �ڵ尪��������
	char ss_id[3];	// ����ID, �ڵ尪��������
	char ord_exist;	// ȣ������, 0:ȣ������(�����׸� ����), 1:ȣ������(�����׸� ���)
	int total_l_limit_ord_q;	// �ż���ȣ���ܷ�
	double l_lvl_1_prc;	// �ż�1�ܰ�켱ȣ������, ��) 999.99
	int l_lvl_1_q;	// �ż�1�ܰ�켱ȣ���ܷ�
	double l_lvl_2_prc;	// �ż�2�ܰ�켱ȣ������, ��) 999.99
	int l_lvl_2_q;	// �ż�2�ܰ�켱ȣ���ܷ�
	double l_lvl_3_prc;	// �ż�3�ܰ�켱ȣ������, ��) 999.99
	int l_lvl_3_q;	// �ż�3�ܰ�켱ȣ���ܷ�
	double l_lvl_4_prc;	// �ż�4�ܰ�켱ȣ������, ��) 999.99
	int l_lvl_4_q;	// �ż�4�ܰ�켱ȣ���ܷ�
	double l_lvl_5_prc;	// �ż�5�ܰ�켱ȣ������, ��) 999.99
	int l_lvl_5_q;	// �ż�5�ܰ�켱ȣ���ܷ�
	int total_s_limit_ord_q;	// �ŵ���ȣ���ܷ�
	double s_lvl_1_prc;	// �ŵ�1�ܰ�켱ȣ������, ��) 999.99
	int s_lvl_1_q;	// �ŵ�1�ܰ�켱ȣ���ܷ�
	double s_lvl_2_prc;	// �ŵ�2�ܰ�켱ȣ������, ��) 999.99
	int s_lvl_2_q;	// �ŵ�2�ܰ�켱ȣ���ܷ�
	double s_lvl_3_prc;	// �ŵ�3�ܰ�켱ȣ������, ��) 999.99
	int s_lvl_3_q;	// �ŵ�3�ܰ�켱ȣ���ܷ�
	double s_lvl_4_prc;	// �ŵ�4�ܰ�켱ȣ������, ��) 999.99
	int s_lvl_4_q;	// �ŵ�4�ܰ�켱ȣ���ܷ�
	double s_lvl_5_prc;	// �ŵ�5�ܰ�켱ȣ������, ��) 999.99
	int s_lvl_5_q;	// �ŵ�5�ܰ�켱ȣ���ܷ�
	int total_l_trd_cnt;	// �ż���ȿȣ���Ǽ�
	int l_lvl_1_trd_cnt;	// �ż�1�ܰ�켱ȣ���Ǽ�
	int l_lvl_2_trd_cnt;	// �ż�2�ܰ�켱ȣ���Ǽ�
	int l_lvl_3_trd_cnt;	// �ż�3�ܰ�켱ȣ���Ǽ�
	int l_lvl_4_trd_cnt;	// �ż�4�ܰ�켱ȣ���Ǽ�
	int l_lvl_5_trd_cnt;	// �ż�5�ܰ�켱ȣ���Ǽ�
	int total_s_trd_cnt;	// �ŵ���ȿȣ���Ǽ�
	int s_lvl_1_trd_cnt;	// �ŵ�1�ܰ�켱ȣ���Ǽ�
	int s_lvl_2_trd_cnt;	// �ŵ�2�ܰ�켱ȣ���Ǽ�
	int s_lvl_3_trd_cnt;	// �ŵ�3�ܰ�켱ȣ���Ǽ�
	int s_lvl_4_trd_cnt;	// �ŵ�4�ܰ�켱ȣ���Ǽ�
	int s_lvl_5_trd_cnt;	// �ŵ�5�ܰ�켱ȣ���Ǽ�
	double real_t_high_prc;	// �ǽð����Ѱ�, ��) 999.99 ���߰��̵�����
	double real_t_low_prc;	// �ǽð����Ѱ�, ��) 999.99 ���߰��̵�����
} DF_K200_OPT_MRK_OP_TS;


// K200�ɼ�_����
typedef struct _DF_K200_OPT_CLOSE {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����, H0
	char info_clsf[3];	// ��������, 03:KOSPI200�����ɼ�
	char mrk_clsf;	// ���屸��, 4
} DF_K200_OPT_CLOSE;


// K200�ɼ�_�������ٰ���
typedef struct _DF_K200_OPT_MRK_OP_SCHD {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����, M4
	char info_clsf[3];	// ��������, 03:KOSPI200�����ɼ�
	char mrk_clsf;	// ���屸��, 4
	char isin_clsf[13];	// �����ڵ�, �������� ����ġ�� ���
	int stk_snr;	// �����Ϸù�ȣ, �����Ϸù�ȣ �ڸ��� ����(3->4)
	char prd_id[12];	// ��ǰID, �ڵ尪�������� : spaceó��
	char mrk_prd_id[4];	// ����ǰ�׷�ID, OKI : K200�ɼ�
	char brd_id[3];	// ����ID, �ڵ尪��������
	char brd_event_id[4];	// �����̺�ƮID, �ڵ尪��������
	char brd_event_start_t[9];	// �����̺�Ʈ���۽ð�
	int brd_event_code;	// �����̺�Ʈ���뱺�ڵ�, �ڵ尪��������
	char ss_open_close_code[3];	// ���ǰ��������ڵ�, BS:���尳��\n BE:��������\n SS:���ǰ���\n SE:��������\n SH:��������\n SR:�����簳
	char ss_id[3];	// ����ID, �ڵ尪��������
	int adj_stage;	// ����ܰ�, CB �� ���������� Ȯ��� ����Ǵ� �ܰ� \n��)�ʱⰪ 00
	char under_asset_prc_chg;	// �������񰡰�Ȯ��߻��ڵ�, ���������� ����Ȯ��� �����ڵ�(U:���, D:�϶�)
	char exp_prc_chg_t[9];	// ����Ȯ�뿹���ð�, �Ļ����尡��Ȯ�� ���� �̺�Ʈ �߻��� ���Ǵ� �׸����� ����Ȯ�뿹���ð��� ��ϵ�
} DF_K200_OPT_MRK_OP_SCHD;


// K200�ɼ�_�������
typedef struct _DF_K200_OPT_DIST_INFO {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����, O6
	char info_clsf[3];	// ��������, 03:KOSPI200�����ɼ�
	char mrk_clsf;	// ���屸��, 4
	char isin_clsf[13];	// �����ڵ�
	int stk_snr;	// �����Ϸù�ȣ, �����Ϸù�ȣ �ڸ��� ����(3->4)
	char brd_id[3];	// ����ID, �ڵ尪��������
	char dist_adj_code;	// ������뱸���ڵ�, 1:��а���, 2:�������
	char dist_code;	// ���ó�������ڵ�, 1:�ż�����, 2:�ż�����,\n 3:�ŵ�����, 4:�ŵ�����\n *��������� �ڵ����(spaceó��)
	char dist_cls_t[9];	// ��������ð�
} DF_K200_OPT_DIST_INFO;


// K200�ɼ�_�ǽð������Ѱ� ���������
typedef struct _DF_K200_OPT_REAL_HIGH_LOW_LIMIT_ON_OFF {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����, Q2
	char info_clsf[3];	// ��������, 03:KOSPI200�����ɼ�
	char mrk_clsf;	// ���屸��, 4
	char isin_clsf[13];	// �����ڵ�
	int stk_snr;	// �����Ϸù�ȣ, �����Ϸù�ȣ �ڸ��� ����(3->4)
	char brd_id[3];	// ����ID, �ڵ尪��������
	char cleared_t[9];	// ó���ð�
	char real_t_prc_limit_code;	// �ǽð��������Ѽ����ڵ�, 0: ����, 1: ����, 2: �缳��
	double real_t_high_prc;	// �ǽð����Ѱ�, ��)999.99 ���߰��̵�����
	double real_t_low_prc;	// �ǽð����Ѱ�, ��)999.99 ���߰��̵�����
} DF_K200_OPT_REAL_HIGH_LOW_LIMIT_ON_OFF;


// K200�ɼ�_����������Ȯ��ߵ�
typedef struct _DF_K200_OPT_PRC_LIMIT_ON {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����, V1
	char info_clsf[3];	// ��������, 03:KOSPI200�����ɼ�
	char mrk_clsf;	// ���屸��, 4
	char code_clsf[13];	// �����ڵ�
	int stk_snr;	// �����Ϸù�ȣ, �����Ϸù�ȣ �ڸ��� ����(3->4)
	char prd_id[12];	// ��ǰID, �ڵ尪�������� : spaceó��
	char brd_id[3];	// ����ID, �ڵ尪��������
	char prc_limit_start_t[9];	// ����Ȯ��ð�, ������ Ȯ��� �ð�
	int prc_limit_high;	// ��������Ȯ����Ѵܰ�, ����� ���Ѵܰ�
	int prc_limit_low;	// ��������Ȯ�����Ѵܰ�, ����� ���Ѵܰ�
	double high_prc;	// ���Ѱ�, ����� ���Ѱ�\n��)999.99
	double low_prc;	// ���Ѱ�, ����� ���Ѱ�\n��)999.99
} DF_K200_OPT_PRC_LIMIT_ON;


// K200�ɼ�_SPACE
typedef struct _DF_K200_OPT_SPACE {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����, G9
	char info_clsf[3];	// ��������, 03:KOSPI200�����ɼ�
	char mrk_clsf;	// ���屸��, 4
} DF_K200_OPT_SPACE;


// K200�ɼ�_�̰����������� ������
typedef struct _DF_K200_OPT_OPEN_INTEREST_DATA {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����, H2
	char info_clsf[3];	// ��������, 03:KOSPI200�����ɼ�
	char mrk_clsf;	// ���屸��, 4
	char isin_clsf[13];	// �����ڵ�, ���� record '999999999999' set
	int stk_snr;	// ����SEQ, ����SEQ �ڸ��� ����(3->4)
	char open_interest_clsf[3];	// �̰�����������, ���� Ȯ�� : "M0" (07:40�а� ����)\n���� ���� : "M1" (���� Ư���������� ��������\n         �۽�, 10��)\n���� Ȯ�� : "M2" (���� ������ �۽�,\n         ������ 1�ð��� ����)\n*�������� ù��° �����ʹ� �尳�������ǰŷ��� ����
	char traded_date[9];	// �ŷ�����
	int open_interest_q;	// �̰�����������, ����:���
} DF_K200_OPT_OPEN_INTEREST_DATA;


// K200�ɼ�_�Ÿ����űݱ��ذ� ������
typedef struct _DF_K200_OPT_TRD_MRG_STD_PRC_DATA {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����, H3
	char info_clsf[3];	// ��������, 03:KOSPI200�����ɼ�
	char mrk_clsf;	// ���屸��, 4
	char isin_clsf[13];	// �����ڵ�, ���� record '999999999999' set
	int stk_snr;	// ����SEQ, ����SEQ �ڸ��� ����(3->4)
	double trd_mrg_std_prc;	// �Ÿ����űݱ��ذ�, ��) 99999999.99999999
	char trd_mrg_std_prc_clsf;	// �Ÿ����űݱ��ذ�����, 0 : ���ű� ���ذ� ����(���� �ŷ������� �⼼ ����)\n1 : ���� ����(�Ǽ�)\n2 : ���� �⼼(���� �ŷ������� �⼼)\n -2012.05.14 ����\n3 : ���� ���ű� ���ذ�(�ŷ������� ���� ������)\n -2012.05.14 ����\n4 : ���� �̷а�(�ŷ������� ���� ������)\n5 : �����������űݱ��ذ�(�ŷ������� ���� ������)\n -2012.05.14 ����
	double opt_exec_right_set_prc;	// �ɼǱǸ�����������, ��) 99999999.99999999
	char opt_exec_right_set_prc_clsf;	// �ɼǱǸ����������ݱ���
} DF_K200_OPT_TRD_MRG_STD_PRC_DATA;


// K200�ɼ�_�������� ������
typedef struct _DF_K200_OPT_PRD_INFO_DATA {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����, AO
	char info_clsf[3];	// ��������, 03:KOSPI200�����ɼ�
	char mrk_clsf;	// ���屸��, 4
	int prd_cnt;	// �����
	char trd_date[9];	// ��������(��ȸ����)
	char isin_clsf[13];	// �����ڵ�, ���� record '999999999999' set
	int stk_snr;	// ����SEQ
	char prd_id[12];	// ��ǰID, * �ڵ尪 ������ ����* ����Ī: �Ļ���ǰID10 => 11, 20140303
	char sh_prd_code[10];	// ��������ڵ�, ��) KR4101C90009 �� K101C9000
	char prd_name_kor[81];	// �����ѱ۸�
	char sh_prd_name_kor[41];	// �����ѱ۾��
	char prd_name_eng[81];	// ���񿵹���
	char sh_prd_name_eng[41];	// ���񿵹����
	char listing_date[9];	// ��������
	char de_listing_date[9];	// ������������
	char spread_clsf_code;	// ��������������񱸺��ڵ�, ���������� ������ �Ǵ� ������ ISIN ǥ���ڵ�--�ڵ尪--F: ������(�ð���������)N: �ٿ���(�ð���������)20140303
	char final_sett_code;	// ������������ڵ�, ���ݰ���, �ǹ��μ������� �� �Ļ���ǰ�� �������� ���--�ڵ尪--C: ���ݰ���D: �ǹ��μ�������A: ����+�ǹ��μ�������0: �ش����\n20140303
	char prc_limit_exp_dir;	// ��������Ȯ����������ڵ�, ���������� �ٴܰ�� ���ǵǴ� ��� ���� �ܰ�� Ȯ��Ǵ� ����� ������ �� Ȯ�븦 �����ϴ� ����## �ڵ尪##X:������F:������B:������T:�����
	int prc_limit_final_stg;	// �������������ܰ�, ���������� �ٴܰ�� ���ǵǴ� ��� ������ �����ܰ��ȣ
	double prc_limit_stg_1_high_prc;	// ��������1�ܰ���Ѱ�, ��) 9999999999.99
	double prc_limit_stg_1_low_prc;	// ��������1�ܰ����Ѱ�, ��) 9999999999.99
	double prc_limit_stg_2_high_prc;	// ��������2�ܰ���Ѱ�, ��) 9999999999.99
	double prc_limit_stg_2_low_prc;	// ��������2�ܰ����Ѱ�, ��) 9999999999.99
	double prc_limit_stg_3_high_prc;	// ��������3�ܰ���Ѱ�, ��) 9999999999.99
	double prc_limit_stg_3_low_prc;	// ��������3�ܰ����Ѱ�, ��) 9999999999.99
	double stand_prc;	// ���ذ�, ��) 9999999999.99
	char under_asset_id[4];	// �����ڻ�ID, ��) K2I:KOSPI200����, KQI:�ڽ���150, Sxx:�����ֽ�, BM3:��3�ⱹä, BM5:��5�ⱹä, BMA:��10�ⱹä, CDR:CD, USD:�̱��޷�, JPY:�Ϻ���, EUR:��������, GLD:��, LHG:����20140303
	char opt_type_code;	// �Ǹ���������ڵ�, A:�̱���,E:������,Z:��Ÿ
	char spread_str_code[3];	// �������屸���ڵ�, Combination ȣ���� ��ü�� �������幰�� ���񱸼�.--�ڵ尪--- T1: �ֱٿ���+2°����      > T2, T3, T4, ...\n*����Ī: �������������ڵ�20140303
	char spread_prd_code_1[13];	// �������屸�������ڵ�1, * ����Ī: ��������ٿ��� �����ڵ�ٿ��� ǥ���ڵ�20140303
	char spread_prd_code_2[13];	// �������屸�������ڵ�2, * ����Ī: ��������ٿ��� �����ڵ�ٿ��� ǥ���ڵ�20140303
	char last_trading_date[9];	// �����ŷ�����
	char final_sett_date[9];	// ������������
	int cont_month_nbr;	// ��������ȣ, * ����Ī: ���������ڵ�1:�ֱٿ���,������������2:2°����3:3°����4:4°����5:5°����6:6°����7:7°����      �� �ֱٿ������� ��ġ\nX => 9, 1 => 3, 20140303
	char maturity_date[9];	// ��������, �Ǹ���� ������ ��������
	double exe_prc;	// ��簡��, ��) 999999999.99999999
	char adjust_clsf_code;	// ���������ڵ�, �����ڻ��� ���ذ��� ������ ����� ����(�̰�������)���� ������� ����(�ŷ��¼�����)������ ����--�ڵ尪--N: ����O: �̰�������\nC: �ŷ��¼�����20140303
	double prd_unit;	// �ŷ�����, 1��࿡ �ش��ϴ� �����ڻ������) 999999999.99999999=> Exture������ 1�̾�����, Exture+������ 500000��\n20140303
	double multiplier;	// �ŷ��¼�, ������� �� ������ ����ϴ� ���¼���) 9999999999999.99999999
	char mrk_cnst_code;	// �������������ڵ�, 0:�̽�����������1:���Ͻ�����������2:���Ž�����������
	char listing_type_code;	// ���������ڵ�, 1:�űԻ���2:�߰�����3:��������4:���ʻ���5:��������6:Ư������
	double atm_prc;	// ���, �����ڻ���ذ��ݿ� ���� ����� ��簡�ݿ�) 9999999999.99
	char adj_reason_code[3];	// ���������ڵ�, 00:�ش���׾���, 01:�Ǹ���, 02:����,03:�й��, 04:�ǹ��, 05:�߰�����,06:�Ǹ��߰�����, 99:��Ÿ
	char under_asset_prd_code[13];	// �����ڻ������ڵ�
	double under_asset_close_prc;	// �����ڻ�����, ��) 9999999999.99
	int left_until_maturity;	// �����ϼ�
	double adj_std_prc;	// �������ذ���, �ֽ��Ļ���ǰ�� �����ֱ� �������ذ��ݿ�) 999999999.99999999
	char std_prc_clsf_code[3];	// ���ذ��ݱ����ڵ�, *����spcace:���ذ� ����(���� ������������)11:�������갡12:���ϱ��ذ�(�ŷ������� ����������)13:�����̷а�(�ŷ������� ����������)\n14:���ϱ⼼(�ŷ������� �⼼����)  -2012.05.14 ����15:�����̷а�(�ŷ������� �⼼����)-  -2012.05.14 ����\n16:������ �������갡17:������ ���ϱ��ذ�  (�ŷ������� ����������)18:������ ���ϱ⼼(�ŷ������� �⼼����)  -2012.05.14 ����\n19:���� ����ڻ� ����(�̷а����� ��ǰ)*�ɼ�21:�������űݱ��ذ�22:���ϱ��ذ�(�ŷ������� ����������)23:�����̷а�(�ŷ������� ����������)\n24:���ϱ⼼(�ŷ������� �⼼����)  -2012.05.14 ����25:������ �������űݱ��ذ�26:������ ���ϱ��ذ�  (�ŷ������� ����������)\n27:������ ���ϱ⼼(�ŷ������� �⼼����)  -2012.05.14 ����
	char trd_std_prc_clsf_code;	// �Ÿſ���ذ��ݱ����ڵ�, 0:�ش����1:�Ǽ�2:�⼼3:�̷а�4:����ڻ�����
	double yest_adj_close_prc;	// ������������, �ֽ��Ļ���ǰ�� ����������) 999999999.99999999
	char block_trd_clsf;	// ���Ǵ뷮�ŸŴ�󿩺�, Y:���ǸŸŻ�ǰ, N:���ƴ԰���ǰ��:3�⹰��ä����, �̱��޷�����,      ���μ���, ������
	double yest_mrg_std_prc;	// �������űݱ��ذ���, ��) 999999999.99999999
	char yest_mrg_std_prc_clsf_code[3];	// �������űݱ��ذ��ݱ����ڵ�, *�ɼ�20:���ű� ���ذ� ����21:��������(�Ǽ�)22:���ϱ⼼(�ŷ������ı⼼)  -2012.05.14 ����23:�������űݱ��ذ�\n  (�ŷ������� ����������)  -2012.05.14 ����24:�����̷а�(�ŷ������� ����������)25:�����������űݱ��ذ�  (�ŷ������� ����������)\n  -2012.05.14 ����
	double sett_theory_prc;	// �����̷а���, �ؿɼ��� ��� ���űݱ��ذ��� ��) 999999999.999999
	double std_theory_prc;	// �����̷а���, ��) 999999999.999999
	double yest_sett_prc;	// �������갡��, ��) 999999999.99999999
	char halt_trd_clsf;	// �ŷ���������, Y, N
	double ft_cb_high_prc;	// ����Circuit_Breakers���Ѱ�, ���� CB �ߵ������� �Ǵ��ϱ� ���� ���Ѱ���(���ذ���� +/-5%�� CB �ߵ������� ��� +5%�� ����� ����)��) 9999999999.99
	double ft_cb_low_prc;	// ����Circuit_Breakers���Ѱ�, ���� CB �ߵ������� �Ǵ��ϱ� ���� ���Ѱ���(���ذ���� +/-5%�� CB �ߵ������� ��� -5%�� ����� ����)��) 9999999999.99
	double check_exe_prc;	// ��ȸ����簡��, ��) 999999999.99999999
	char atm_clsf;	// ATM�����ڵ�, 0:����, 1:ATM, 2:ITM, 3:OTM
	char last_trading_clsf;	// �����ŷ��Ͽ���, Y, N
	double ex_divid_aft_value;	// �����Ĺ�簡ġ, �ֽ� �� �ְ����� ��ǰ���� �����- ���� : �����Ĺ̷���ġ- �ɼ� : ���������簡ġ��) 999999999.999999
	double yest_close_prc;	// ��������, ��) 9999999999.99
	char yest_close_prc_clsf;	// �������������ڵ�, 1:�Ǽ�, 3:�ŷ���2:�⼼ -2012.05.14 ����
	double yest_init_prc;	// ���Ͻð�, ��) 9999999999.99
	double yest_high_pric;	// ���ϰ�, ��) 9999999999.99
	double yest_low_prc;	// ��������, ��) 9999999999.99
	char yest_first_exe_date[9];	// ����ü������
	char yest_last_exe_time[9];	// ��������ü��ð�
	char yest_sett_prc_clsf[3];	// �������갡�ݱ����ڵ�, *���� 10:���갡���� 11:��������(�Ǽ�) 12:���ϱ⼼(�ŷ������ı⼼) 13:�������갡(�ŷ������� ����������)\n 14:�����̷а�(�ŷ������� ����������) 15:��������� ���� 16:������ ���� ���갡 17:����ڻ� ����(�̷а����� ��ǰ)
	double sett_prc_theory_prc_diff_pctg;	// ���갡���̷а��ݱ�����, ��) 999999.999999
	double yest_open_interest_q;	// ���Ϲ̰�����������
	double yest_s_limit_ord_prc;	// ���ϸŵ��켱ȣ������, ��) 9999999999.99
	double yest_l_limit_ord_prc;	// ���ϸż��켱ȣ������, ��) 9999999999.99
	double implied_vol;	// ���纯����, ��) 999999.9999
	double listed_high_prc;	// �������ְ�, ��) 9999999999.99
	double listed_low_prc;	// ������������, ��) 9999999999.99
	double year_high_prc;	// �����ְ�, ��) 9999999999.99
	double year_low_prc;	// ����������, ��) 9999999999.99
	char listed_high_prc_date[9];	// �������ְ�����
	char listed_low_prc_date[9];	// ����������������
	char year_high_prc_date[9];	// �����ְ�����
	char year_low_prc_date[9];	// ��������������
	int year_std_date;	// ���������ϼ�
	int month_trd_date;	// �����ŷ��ϼ�
	int year_trd_date;	// �����ŷ��ϼ�
	double yest_exe_trd_cnt ;	// ����ü��Ǽ�
	double yest_exe_q;	// ����ü�����, �������Ǵ뷮�Ÿ�ü������� ���Ե��� ����
	double yest_trd_amt;	// ���ϰŷ����, �������Ǵ뷮�ŸŰŷ������ ���Ե��� ����
	double yest_block_trd_exe_q;	// �������Ǵ뷮�ջ�ü�����, �������Ǵ뷮�Ÿ�ü����� => �������Ǵ뷮�ջ�ü����� [����ü�����+�������Ǵ뷮�Ÿ�ü�����(���Ǵ뷮+FLEX)];\n 2016.03.28 ����
	double yest_block_trd_total_amt;	// �������Ǵ뷮�ջ�ŷ����, �������Ǵ뷮�ŸŰŷ���� => �������Ǵ뷮�ջ�ŷ���� [���ϰŷ����+�������Ǵ뷮�ŸŰŷ����(���Ǵ뷮+FLEX)]; 2016.03.28 ����
	double cd_rate;	// CD�ݸ�, ��) 999.999
	double open_interest_q;	// �̰����ѵ�����, *�����Ͽ� ����Ǵ� ��ǰ�� ���º� �̰��� �ѵ� ����. �̰��� �ѵ��� ������� ���� ��ǰ�� 0*�ֽļ������� �ش�\n8 => 15, 20140303
	char product_cat[5];	// �Ҽ� ��ǰ��, *�ֽļ���/�ɼǿ��� �ش�
	double product_cat_off_pctg;	// ��ǰ�� �ɼ���, *������� ǥ��*�ֽļ���/�ɼǿ��� �ش翹) 9999999.995 => 9, 20140303
	int limit_ord_clsf_code;	// ������ȣ�����Ǳ����ڵ�, ȣ���� ü�� �� �ܷ�����. Bitwise ����--�ڵ尪--1: FAS (Fill And Store)2: FOK (Fill Or Kill)\n3: FAK (Fill And Kill)* ������ȣ�����Ǳ����ڵ� BITWISE ����\n���� Ȯ�强�� ���� �ش� 10�������� 2������ ��ȯ�Ͽ� ó�����(�ִ� 16bit���� ��밡��)�� ) ������ȣ�����Ǳ����ڵ� ���� 6�̸�\n    (������ 6 -> ������ 00000110)0��° bit 0 -> 0 : FAS1��° bit 1 -> 2 : FOK\n2��° bit 1 -> 4 : FAK��, FOK�̸鼭 FAK�� �����Ѵٴ� �ǹ� (FOK & FAK)\nX => 9, 1 => 5, 20140303
	int mrk_ord_clsf_code;	// ���尡ȣ�����Ǳ����ڵ�, * ��
	int cond_limit_ord_clsf_code;	// ���Ǻ�������ȣ�����Ǳ����ڵ�, * ��
	int best_limit_ord_clsf_code;	// ������������ȣ�����Ǳ����ڵ�, * ��
	char efp_clsf;	// EFP�ŷ���󿩺�, Y, N, ��ǰ������ �ش�
	char flex_clsf;	// FLEX�ŷ���󿩺�, Y, N, ��ǰ������ �ش�
	double yest_efp_exe_q;	// ����EFPü�����, ��ǰ������ �ش�
	double yest_efp_trd_amount;	// ����EFP�ŷ����, ��ǰ������ �ش�
	char mkr_close_clsf;	// ���忩��, ���忩�� (Y,N), 20121217
	char real_t_prc_limit_clsf;	// �ǽð��������ѿ���, ���� ü�ᰡ�� ��� Ư�� ������ �ʰ��ϴ� ȣ���� �ź��ϵ��� �������� ����(Y/N) 20140901
	double real_t_high_price_gap;	// �ǽð����Ѱ�����, ���� ü�ᰡ�ݰ� �ǽð����Ѱ����� ���� �ǽð����Ѱ� = ����ü�ᰡ�� + �ǽð����Ѱ����� ex) 9999999999.99 20140901
	double real_t_low_price_gap;	// �ǽð����Ѱ�����, ���� ü�ᰡ�ݰ� �ǽð����Ѱ����� ���� �ǽð����Ѱ� = ����ü�ᰡ�� + �ǽð����Ѱ�����(����) ex) 9999999999.99 20140901
	char under_ass_mrk_id[4];	// �����ڻ����ID, �����ڻ����ID�� �����ڻ��� KRX�� ����� ��쿡�� ä����.K200�����ɼ�:STK�ڽ���150����:KSQ�ֽļ����ɼ�:STK/KSQ ��ǰ�����ɼ�:SPACE��������������:STK������������:STK�̴�K200�����ɼ�:STK
	double upper_limit_ord_q;	// ���Ѽ���, ȣ�����Ѽ��� (20181210 �׸��߰�)
	double lower_limit_ord_q;	// ���Ѽ���, ȣ�����Ѽ��� (20181210 �׸��߰�)
	double block_trd_upper_limit_ord_q;	// ���Ǵ뷮�ŸŻ��Ѽ���, ���Ǵ뷮�Ÿ�ȣ�����Ѽ��� (20181210 �׸��߰�)
	double block_trd_lower_limit_ord_q;	// ���Ǵ뷮�Ÿ����Ѽ���, ���Ǵ뷮�Ÿ�ȣ�����Ѽ��� (20181210 �׸��߰�)
} DF_K200_OPT_PRD_INFO_DATA;


// K200�ɼ�_�ΰ���
typedef struct _DF_K200_OPT_SENSITIVITY_DATA {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����, N7
	char info_clsf[3];	// ��������, 03:KOSPI200�����ɼ�
	char mrk_clsf;	// ���屸��, 4
	char isin_clsf[13];	// �����ڵ�
	char stk_snr[8];	// ����SEQ
	char created_date[9];	// ��������
	char created_time[9];	// �����ð�
	char clsf_code;	// �����ڵ�, 1:����Ȯ��,2:���߻���,E:���߿Ϸ�,3:����Ȯ��
	char under_asset_id[4];	// �����ڻ�ID, K2I:KOSPI200
	double sensitivity_delta;	// �ΰ��� ��Ÿ, 9(12)V9(6)
	double sensitivity_theta;	// �ΰ��� ��Ÿ, 9(12)V9(6)
	double sensitivity_vega;	// �ΰ��� ����, 9(12)V9(6)
	double sensitivity_gamma;	// �ΰ��� ����, 9(12)V9(6)
	double sensitivity_rho;	// �ΰ��� ��, 9(12)V9(6)
} DF_K200_OPT_SENSITIVITY_DATA;


// KOSPI200�ɼ� ���纯����
typedef struct _DF_K200_OPT_IMPLIED_VOL_DATA {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����, P1
	char info_clsf[3];	// ��������, 03:KOSPI200�����ɼ�
	char mrk_clsf;	// ���屸��, 4
	double call_ave_implied_vol;	// ����ճ��纯����, 999999V9999
	double put_ave_implied_vol;	// ǲ��ճ��纯����, 999999V9999
	double rep_implied_vol;	// ��ǥ���纯����, 999999V9999
	double hist_vol_90_days;	// ������������(90��), 999999V9999
} DF_K200_OPT_IMPLIED_VOL_DATA;


// K200�ɼ�_������ ������
typedef struct _DF_K200_OPT_INVESTOR_DATA {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����, H1
	char info_clsf[3];	// ��������, 03:KOSPI200�����ɼ�
	char mrk_clsf;	// ���屸��, 4
	char created_date[9];	// ��������
	char created_time[7];	// �����ð�
	char inv_data_clsf[3];	// �����ͱ���, *����Ȯ�� : 00, �������� : 01, ����Ȯ�� : 02\n *E1 : ���� ������ �Ϸ�, E2 : Ȯ�� ������ �Ϸ�\n ���� record '99' set\n *�������� ù��° �����ʹ� �尳�������ǰŷ��� ����
	char prd_id[12];	// ��ǰID, �ڵ尪�������� - KRDRVOPK2I
	char opt_clsf;	// �ɼǱ���, C:�ݿɼ�, P:ǲ�ɼ�
	char inv_clsf[5];	// ����������, �ڵ尪���� ���� *�ڵ� '7000'�� ����,��������׸� 0���� ����
	int long_exe_q;	// �ż� ��������
	int short_exe_q;	// �ŵ� ��������
	double long_traded_amt;	// �ż� �������
	double short_traded_amt;	// �ŵ� �������
} DF_K200_OPT_INVESTOR_DATA;


// K200�ɼ�_�ü�Recovery ������
typedef struct _DF_K200_OPT_RECOVERY_DATA {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����, B2
	char info_clsf[3];	// ��������, 03:KOSPI200�����ɼ�
	char mrk_clsf;	// ���屸��, 4
	char isin_clsf[13];	// �����ڵ�
	int stk_snr;	// �����Ϸù�ȣ, �����Ϸù�ȣ �ڸ��� ����(3->4)
	double cur_prc;	// ���簡, ��) 999.99
	double init_prc;	// �ð�, ��) 999.99
	double high_prc;	// ��, ��) 999.99
	double low_prc;	// ����, ��) 999.99
	int open_interest_q;	// �̰�����
	int accm_exe_q;	// ����ü�����
	double accm_trd_amt;	// �����ŷ����, ����:õ��
	char l_or_s;	// �����ŵ��ż������ڵ�, 1:�ŵ�,2:�ż�(�������� ���� ȣ���� �ŵ��ż����а�)
	double s_lvl_1_prc;	// �ŵ�1ȣ��, ��) 999.99
	int s_lvl_1_q;	// �ŵ�1ȣ������
	int s_lvl_1_trd_cnt;	// �ŵ�1ȣ���Ǽ�
	double l_lvl_1_prc;	// �ż�1ȣ��, ��) 999.99
	int l_lvl_1_q;	// �ż�1ȣ������
	int l_lvl_1_trd_cnt;	// �ż�1ȣ���Ǽ�
	double s_lvl_2_prc;	// �ŵ�2ȣ��, ��) 999.99
	int s_lvl_2_q;	// �ŵ�2ȣ������
	int s_lvl_2_trd_cnt;	// �ŵ�2ȣ���Ǽ�
	double l_lvl_2_prc;	// �ż�2ȣ��, ��) 999.99
	int l_lvl_2_q;	// �ż�2ȣ������
	int l_lvl_2_trd_cnt;	// �ż�2ȣ���Ǽ�
	double s_lvl_3_prc;	// �ŵ�3ȣ��, ��) 999.99
	int s_lvl_3_q;	// �ŵ�3ȣ������
	int s_lvl_3_trd_cnt;	// �ŵ�3ȣ���Ǽ�
	double l_lvl_3_prc;	// �ż�3ȣ��, ��) 999.99
	int l_lvl_3_q;	// �ż�3ȣ������
	int l_lvl_3_trd_cnt;	// �ż�3ȣ���Ǽ�
	double s_lvl_4_prc;	// �ŵ�4ȣ��, ��) 999.99
	int s_lvl_4_q;	// �ŵ�4ȣ������
	int s_lvl_4_trd_cnt;	// �ŵ�4ȣ���Ǽ�
	double l_lvl_4_prc;	// �ż�4ȣ��, ��) 999.99
	int l_lvl_4_q;	// �ż�4ȣ������
	int l_lvl_4_trd_cnt;	// �ż�4ȣ���Ǽ�
	double s_lvl_5_prc;	// �ŵ�5ȣ��, ��) 999.99
	int s_lvl_5_q;	// �ŵ�5ȣ������
	int s_lvl_5_trd_cnt;	// �ŵ�5ȣ���Ǽ�
	double l_lvl_5_prc;	// �ż�5ȣ��, ��) 999.99
	int l_lvl_5_q;	// �ż�5ȣ������
	int l_lvl_5_trd_cnt;	// �ż�5ȣ���Ǽ�
	int total_s_limit_ord_q;	// �ŵ� ��ȣ������
	int total_s_trd_cnt;	// �ŵ���ȿȣ���Ǽ�
	int total_l_limit_ord_q;	// �ż� ��ȣ������
	int total_l_trd_cnt;	// �ż���ȿȣ���Ǽ�
	char ss_id[3];	// ����ID, �ڵ尪��������
	char brd_id[3];	// ����ID, �ڵ尪��������
	char brd_event_id[4];	// �����̺�ƮID, B2 ������ �����̺�ƮID ������(���� ���°��� ���۵� �� ����). ����, �ش� �׸� '000' ���� ����. 2014.03.24)
	double exp_prc;	// ����ü�ᰡ��, ��) 999.99 ���ϰ��ŸŽø� ����\n (����±����ڵ�:10,20,30,80)
	double real_t_high_prc;	// �ǽð����Ѱ�, ��) 999.99 ���߰��̵�����
	double real_t_low_prc;	// �ǽð����Ѱ�, ��) 999.99 ���߰��̵�����
} DF_K200_OPT_RECOVERY_DATA;


// K200�ɼ�_Polling ������
typedef struct _DF_K200_OPT_POLLING_DATA {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����, I2
	char info_clsf[3];	// ��������, 03:KOSPI200�����ɼ�
	char mrk_clsf;	// ���屸��, 4
	char send_t[5];	// ���۽ð�, HHSS
	char main_backup_clsf[3];	// Main Backup����, space
} DF_K200_OPT_POLLING_DATA;


// K200�ɼ�_�尳�������ǰŷ�
typedef struct _DF_K200_OPT_BLOCK_TRD_BEF_MRK_OPEN {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����, M7
	char info_clsf[3];	// ��������, 03:KOSPI200�����ɼ�
	char mrk_clsf;	// ���屸��, 4
	char isin_clsf[13];	// �����ڵ�, ���� record '999999999999' set
	int stk_snr;	// ����SEQ, ����SEQ �ڸ��� ����(3->4)
	double exe_prc;	// ü�ᰡ��, ��) 999.99 (���۴��� ���� ���ذ���)
	int exe_q;	// ü�����, �尳�������ǰŷ� ü�� ������ ��� �ջ��� ����
	char exe_clsf_code[3];	// ü�������ڵ�, ���ǰŷ�\n 46 : EUREX
} DF_K200_OPT_BLOCK_TRD_BEF_MRK_OPEN;
