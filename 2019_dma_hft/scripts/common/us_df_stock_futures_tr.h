// us_df_stock_futures_tr.h
// �����ֽļ��� �ǽð� TR (��ȣ �ʵ� ����)

#pragma once
// �ּ��� \n�� ���� ���߿� �̻ڰ� �ٲ����


// �ֽļ���_ü��
typedef struct _DF_STOCK_FUT_EXEC {
	char data_clsf[3];	// DATA����, A3
	char info_clsf[3];	// ��������, 01:�����ֽļ���
	char mrk_clsf;	// ���屸��, 5
	char isin_clsf[13];	// �����ڵ�
	int stk_snr;	// �����Ϸù�ȣ
	char brd_id[3];	// ����ID, �ڵ尪��������
	char cur_prc_sign;	// ���簡�ݺ�ȣ
	int cur_prc;	// ���簡��
	int exe_q;	// ü�����
	char ss_id[3];	// ����ID, �ڵ尪��������
	char exe_t[9];	// ü��ð�
	int rct_prd_prc;	// �ֱٿ���������������
	int nxt_prd_prc;	// ������������������
	char init_prc_sign;	// �ð���ȣ
	int init_prc;	// �ð�
	char high_prc_sign;	// ����ȣ
	int high_prc;	// ��
	char low_prc_sign;	// ������ȣ
	int low_prc;	// ����
	char pri_prc_sign;	// �������ݺ�ȣ
	int pri_prc;	// ��������
	int accm_exe_q;	// ����ü�����
	double accm_trd_amt;	// �����ŷ����, ����:��
	char l_or_s;	// �����ŵ��ż������ڵ�, 1:�ŵ�,2:�ż�(�������� ���� ȣ���� �ŵ��ż����а�)
	char real_t_high_prc_sign;	// �ǽð����Ѱ���ȣ
	int real_t_high_prc;	// �ǽð����Ѱ�, ���߰��̵�����
	char real_t_low_prc_sign;	// �ǽð����Ѱ���ȣ
	int real_t_low_prc;	// �ǽð����Ѱ�, ���߰��̵�����
} DF_STOCK_FUT_EXEC;


// �ֽļ���_�켱ȣ��
typedef struct _DF_STOCK_FUT_LIMIT_ORD {
	char data_clsf[3];	// DATA����, B6
	char info_clsf[3];	// ��������, 01:�����ֽļ���
	char mrk_clsf;	// ���屸��, 5
	char isin_clsf[13];	// �����ڵ�
	int stk_snr;	// �����Ϸù�ȣ
	char brd_id[3];	// ����ID, �ڵ尪��������
	char ss_id[3];	// ����ID, �ڵ尪��������
	int total_l_limit_ord_q;	// �ż���ȣ���ܷ�, �ڸ��� ����(7->8)
	char l_lvl_1_sign;	// �ż�1�ܰ��ȣ
	int l_lvl_1_prc;	// �ż�1�ܰ�켱ȣ������
	int l_lvl_1_q;	// �ż�1�ܰ�켱ȣ���ܷ�, �ڸ��� ����(6->7)
	char l_lvl_2_sign;	// �ż�2�ܰ��ȣ
	int l_lvl_2_prc;	// �ż�2�ܰ�켱ȣ������
	int l_lvl_2_q;	// �ż�2�ܰ�켱ȣ���ܷ�, �ڸ��� ����(6->7)
	char l_lvl_3_sign;	// �ż�3�ܰ��ȣ
	int l_lvl_3_prc;	// �ż�3�ܰ�켱ȣ������
	int l_lvl_3_q;	// �ż�3�ܰ�켱ȣ���ܷ�, �ڸ��� ����(6->7)
	char l_lvl_4_sign;	// �ż�4�ܰ��ȣ
	int l_lvl_4_prc;	// �ż�4�ܰ�켱ȣ������
	int l_lvl_4_q;	// �ż�4�ܰ�켱ȣ���ܷ�, �ڸ��� ����(6->7)
	char l_lvl_5_sign;	// �ż�5�ܰ��ȣ
	int l_lvl_5_prc;	// �ż�5�ܰ�켱ȣ������
	int l_lvl_5_q;	// �ż�5�ܰ�켱ȣ���ܷ�, �ڸ��� ����(6->7)
	char l_lvl_6_sign;	// �ż�6�ܰ��ȣ
	int l_lvl_6_prc;	// �ż�6�ܰ�켱ȣ������
	int l_lvl_6_q;	// �ż�6�ܰ�켱ȣ���ܷ�, �ڸ��� ����(6->7)
	char l_lvl_7_sign;	// �ż�7�ܰ��ȣ
	int l_lvl_7_prc;	// �ż�7�ܰ�켱ȣ������
	int l_lvl_7_q;	// �ż�7�ܰ�켱ȣ���ܷ�, �ڸ��� ����(6->7)
	char l_lvl_8_sign;	// �ż�8�ܰ��ȣ
	int l_lvl_8_prc;	// �ż�8�ܰ�켱ȣ������
	int l_lvl_8_q;	// �ż�8�ܰ�켱ȣ���ܷ�, �ڸ��� ����(6->7)
	char l_lvl_9_sign;	// �ż�9�ܰ��ȣ
	int l_lvl_9_prc;	// �ż�9�ܰ�켱ȣ������
	int l_lvl_9_q;	// �ż�9�ܰ�켱ȣ���ܷ�, �ڸ��� ����(6->7)
	char l_lvl_10_sign;	// �ż�10�ܰ��ȣ
	int l_lvl_10_prc;	// �ż�10�ܰ�켱ȣ������
	int l_lvl_10_q;	// �ż�10�ܰ�켱ȣ���ܷ�, �ڸ��� ����(6->7)
	int total_s_limit_ord_q;	// �ŵ���ȣ���ܷ�, �ڸ��� ����(7->8)
	char s_lvl_1_sign;	// �ŵ�1�ܰ��ȣ
	int s_lvl_1_prc;	// �ŵ�1�ܰ�켱ȣ������
	int s_lvl_1_q;	// �ŵ�1�ܰ�켱ȣ���ܷ�, �ڸ��� ����(6->7)
	char s_lvl_2_sign;	// �ŵ�2�ܰ��ȣ
	int s_lvl_2_prc;	// �ŵ�2�ܰ�켱ȣ������
	int s_lvl_2_q;	// �ŵ�2�ܰ�켱ȣ���ܷ�, �ڸ��� ����(6->7)
	char s_lvl_3_sign;	// �ŵ�3�ܰ��ȣ
	int s_lvl_3_prc;	// �ŵ�3�ܰ�켱ȣ������
	int s_lvl_3_q;	// �ŵ�3�ܰ�켱ȣ���ܷ�, �ڸ��� ����(6->7)
	char s_lvl_4_sign;	// �ŵ�4�ܰ��ȣ
	int s_lvl_4_prc;	// �ŵ�4�ܰ�켱ȣ������
	int s_lvl_4_q;	// �ŵ�4�ܰ�켱ȣ���ܷ�, �ڸ��� ����(6->7)
	char s_lvl_5_sign;	// �ŵ�5�ܰ��ȣ
	int s_lvl_5_prc;	// �ŵ�5�ܰ�켱ȣ������
	int s_lvl_5_q;	// �ŵ�5�ܰ�켱ȣ���ܷ�, �ڸ��� ����(6->7)
	char s_lvl_6_sign;	// �ŵ�6�ܰ��ȣ
	int s_lvl_6_prc;	// �ŵ�6�ܰ�켱ȣ������
	int s_lvl_6_q;	// �ŵ�6�ܰ�켱ȣ���ܷ�, �ڸ��� ����(6->7)
	char s_lvl_7_sign;	// �ŵ�7�ܰ��ȣ
	int s_lvl_7_prc;	// �ŵ�7�ܰ�켱ȣ������
	int s_lvl_7_q;	// �ŵ�7�ܰ�켱ȣ���ܷ�, �ڸ��� ����(6->7)
	char s_lvl_8_sign;	// �ŵ�8�ܰ��ȣ
	int s_lvl_8_prc;	// �ŵ�8�ܰ�켱ȣ������
	int s_lvl_8_q;	// �ŵ�8�ܰ�켱ȣ���ܷ�, �ڸ��� ����(6->7)
	char s_lvl_9_sign;	// �ŵ�9�ܰ��ȣ
	int s_lvl_9_prc;	// �ŵ�9�ܰ�켱ȣ������
	int s_lvl_9_q;	// �ŵ�9�ܰ�켱ȣ���ܷ�, �ڸ��� ����(6->7)
	char s_lvl_10_sign;	// �ŵ�10�ܰ��ȣ
	int s_lvl_10_prc;	// �ŵ�10�ܰ�켱ȣ������
	int s_lvl_10_q;	// �ŵ�10�ܰ�켱ȣ���ܷ�, �ڸ��� ����(6->7)
	int total_l_trd_cnt;	// �ż���ȿȣ���Ǽ�
	int l_lvl_1_trd_cnt;	// �ż�1�ܰ�켱ȣ���Ǽ�
	int l_lvl_2_trd_cnt;	// �ż�2�ܰ�켱ȣ���Ǽ�
	int l_lvl_3_trd_cnt;	// �ż�3�ܰ�켱ȣ���Ǽ�
	int l_lvl_4_trd_cnt;	// �ż�4�ܰ�켱ȣ���Ǽ�
	int l_lvl_5_trd_cnt;	// �ż�5�ܰ�켱ȣ���Ǽ�
	int l_lvl_6_trd_cnt;	// �ż�6�ܰ�켱ȣ���Ǽ�
	int l_lvl_7_trd_cnt;	// �ż�7�ܰ�켱ȣ���Ǽ�
	int l_lvl_8_trd_cnt;	// �ż�8�ܰ�켱ȣ���Ǽ�
	int l_lvl_9_trd_cnt;	// �ż�9�ܰ�켱ȣ���Ǽ�
	int l_lvl_10_trd_cnt;	// �ż�10�ܰ�켱ȣ���Ǽ�
	int total_s_trd_cnt;	// �ŵ���ȿȣ���Ǽ�
	int s_lvl_1_trd_cnt;	// �ŵ�1�ܰ�켱ȣ���Ǽ�
	int s_lvl_2_trd_cnt;	// �ŵ�2�ܰ�켱ȣ���Ǽ�
	int s_lvl_3_trd_cnt;	// �ŵ�3�ܰ�켱ȣ���Ǽ�
	int s_lvl_4_trd_cnt;	// �ŵ�4�ܰ�켱ȣ���Ǽ�
	int s_lvl_5_trd_cnt;	// �ŵ�5�ܰ�켱ȣ���Ǽ�
	int s_lvl_6_trd_cnt;	// �ŵ�6�ܰ�켱ȣ���Ǽ�
	int s_lvl_7_trd_cnt;	// �ŵ�7�ܰ�켱ȣ���Ǽ�
	int s_lvl_8_trd_cnt;	// �ŵ�8�ܰ�켱ȣ���Ǽ�
	int s_lvl_9_trd_cnt;	// �ŵ�9�ܰ�켱ȣ���Ǽ�
	int s_lvl_10_trd_cnt;	// �ŵ�10�ܰ�켱ȣ���Ǽ�
	char ord_rcv_t[9];	// ȣ�������ð�
	int exp_prc;	// ����ü�ᰡ��, ���ϰ��ŸŽø� ����\n (����±����ڵ�:10,20,30,80)
} DF_STOCK_FUT_LIMIT_ORD;


// �ֽļ���_ü��_�켱ȣ��
typedef struct _DF_STOCK_FUT_EXEC_LIMIT_ORD {
	char data_clsf[3];	// DATA����, G7
	char info_clsf[3];	// ��������, 01:�����ֽļ���
	char mrk_clsf;	// ���屸��, 5
	char isin_clsf[13];	// �����ڵ�
	int stk_snr;	// �����Ϸù�ȣ
	char brd_id[3];	// ����ID, �ڵ尪��������
	char cur_prc_sign;	// ���簡�ݺ�ȣ
	int cur_prc;	// ���簡��
	int exe_q;	// ü�����
	char ss_id[3];	// ����ID, �ڵ尪��������
	char exe_t[9];	// ü��ð�
	int rct_prd_prc;	// �ֱٿ���������������
	int nxt_prd_prc;	// ������������������
	char init_prc_sign;	// �ð���ȣ
	int init_prc;	// �ð�
	char high_prc_sign;	// ����ȣ
	int high_prc;	// ��
	char low_prc_sign;	// ������ȣ
	int low_prc;	// ����
	char pri_prc_sign;	// �������ݺ�ȣ
	int pri_prc;	// ��������
	int accm_exe_q;	// ����ü�����
	double accm_trd_amt;	// �����ŷ����, ����:��
	char l_or_s;	// �����ŵ��ż������ڵ�, 1:�ŵ�,2:�ż�(�������� ���� ȣ���� �ŵ��ż����а�)
	int total_l_limit_ord_q;	// �ż���ȣ���ܷ�, �ڸ��� ����(7->8)
	char l_lvl_1_sign;	// �ż�1�ܰ��ȣ
	int l_lvl_1_prc;	// �ż�1�ܰ�켱ȣ������
	int l_lvl_1_q;	// �ż�1�ܰ�켱ȣ���ܷ�, �ڸ��� ����(6->7)
	char l_lvl_2_sign;	// �ż�2�ܰ��ȣ
	int l_lvl_2_prc;	// �ż�2�ܰ�켱ȣ������
	int l_lvl_2_q;	// �ż�2�ܰ�켱ȣ���ܷ�, �ڸ��� ����(6->7)
	char l_lvl_3_sign;	// �ż�3�ܰ��ȣ
	int l_lvl_3_prc;	// �ż�3�ܰ�켱ȣ������
	int l_lvl_3_q;	// �ż�3�ܰ�켱ȣ���ܷ�, �ڸ��� ����(6->7)
	char l_lvl_4_sign;	// �ż�4�ܰ��ȣ
	int l_lvl_4_prc;	// �ż�4�ܰ�켱ȣ������
	int l_lvl_4_q;	// �ż�4�ܰ�켱ȣ���ܷ�, �ڸ��� ����(6->7)
	char l_lvl_5_sign;	// �ż�5�ܰ��ȣ
	int l_lvl_5_prc;	// �ż�5�ܰ�켱ȣ������
	int l_lvl_5_q;	// �ż�5�ܰ�켱ȣ���ܷ�, �ڸ��� ����(6->7)
	char l_lvl_6_sign;	// �ż�6�ܰ��ȣ
	int l_lvl_6_prc;	// �ż�6�ܰ�켱ȣ������
	int l_lvl_6_q;	// �ż�6�ܰ�켱ȣ���ܷ�, �ڸ��� ����(6->7)
	char l_lvl_7_sign;	// �ż�7�ܰ��ȣ
	int l_lvl_7_prc;	// �ż�7�ܰ�켱ȣ������
	int l_lvl_7_q;	// �ż�7�ܰ�켱ȣ���ܷ�, �ڸ��� ����(6->7)
	char l_lvl_8_sign;	// �ż�8�ܰ��ȣ
	int l_lvl_8_prc;	// �ż�8�ܰ�켱ȣ������
	int l_lvl_8_q;	// �ż�8�ܰ�켱ȣ���ܷ�, �ڸ��� ����(6->7)
	char l_lvl_9_sign;	// �ż�9�ܰ��ȣ
	int l_lvl_9_prc;	// �ż�9�ܰ�켱ȣ������
	int l_lvl_9_q;	// �ż�9�ܰ�켱ȣ���ܷ�, �ڸ��� ����(6->7)
	char l_lvl_10_sign;	// �ż�10�ܰ��ȣ
	int l_lvl_10_prc;	// �ż�10�ܰ�켱ȣ������
	int l_lvl_10_q;	// �ż�10�ܰ�켱ȣ���ܷ�, �ڸ��� ����(6->7)
	int total_s_limit_ord_q;	// �ŵ���ȣ���ܷ�, �ڸ��� ����(7->8)
	char s_lvl_1_sign;	// �ŵ�1�ܰ��ȣ
	int s_lvl_1_prc;	// �ŵ�1�ܰ�켱ȣ������
	int s_lvl_1_q;	// �ŵ�1�ܰ�켱ȣ���ܷ�, �ڸ��� ����(6->7)
	char s_lvl_2_sign;	// �ŵ�2�ܰ��ȣ
	int s_lvl_2_prc;	// �ŵ�2�ܰ�켱ȣ������
	int s_lvl_2_q;	// �ŵ�2�ܰ�켱ȣ���ܷ�, �ڸ��� ����(6->7)
	char s_lvl_3_sign;	// �ŵ�3�ܰ��ȣ
	int s_lvl_3_prc;	// �ŵ�3�ܰ�켱ȣ������
	int s_lvl_3_q;	// �ŵ�3�ܰ�켱ȣ���ܷ�, �ڸ��� ����(6->7)
	char s_lvl_4_sign;	// �ŵ�4�ܰ��ȣ
	int s_lvl_4_prc;	// �ŵ�4�ܰ�켱ȣ������
	int s_lvl_4_q;	// �ŵ�4�ܰ�켱ȣ���ܷ�, �ڸ��� ����(6->7)
	char s_lvl_5_sign;	// �ŵ�5�ܰ��ȣ
	int s_lvl_5_prc;	// �ŵ�5�ܰ�켱ȣ������
	int s_lvl_5_q;	// �ŵ�5�ܰ�켱ȣ���ܷ�, �ڸ��� ����(6->7)
	char s_lvl_6_sign;	// �ŵ�6�ܰ��ȣ
	int s_lvl_6_prc;	// �ŵ�6�ܰ�켱ȣ������
	int s_lvl_6_q;	// �ŵ�6�ܰ�켱ȣ���ܷ�, �ڸ��� ����(6->7)
	char s_lvl_7_sign;	// �ŵ�7�ܰ��ȣ
	int s_lvl_7_prc;	// �ŵ�7�ܰ�켱ȣ������
	int s_lvl_7_q;	// �ŵ�7�ܰ�켱ȣ���ܷ�, �ڸ��� ����(6->7)
	char s_lvl_8_sign;	// �ŵ�8�ܰ��ȣ
	int s_lvl_8_prc;	// �ŵ�8�ܰ�켱ȣ������
	int s_lvl_8_q;	// �ŵ�8�ܰ�켱ȣ���ܷ�, �ڸ��� ����(6->7)
	char s_lvl_9_sign;	// �ŵ�9�ܰ��ȣ
	int s_lvl_9_prc;	// �ŵ�9�ܰ�켱ȣ������
	int s_lvl_9_q;	// �ŵ�9�ܰ�켱ȣ���ܷ�, �ڸ��� ����(6->7)
	char s_lvl_10_sign;	// �ŵ�10�ܰ��ȣ
	int s_lvl_10_prc;	// �ŵ�10�ܰ�켱ȣ������
	int s_lvl_10_q;	// �ŵ�10�ܰ�켱ȣ���ܷ�, �ڸ��� ����(6->7)
	int total_l_trd_cnt;	// �ż���ȿȣ���Ǽ�
	int l_lvl_1_trd_cnt;	// �ż�1�ܰ�켱ȣ���Ǽ�
	int l_lvl_2_trd_cnt;	// �ż�2�ܰ�켱ȣ���Ǽ�
	int l_lvl_3_trd_cnt;	// �ż�3�ܰ�켱ȣ���Ǽ�
	int l_lvl_4_trd_cnt;	// �ż�4�ܰ�켱ȣ���Ǽ�
	int l_lvl_5_trd_cnt;	// �ż�5�ܰ�켱ȣ���Ǽ�
	int l_lvl_6_trd_cnt;	// �ż�6�ܰ�켱ȣ���Ǽ�
	int l_lvl_7_trd_cnt;	// �ż�7�ܰ�켱ȣ���Ǽ�
	int l_lvl_8_trd_cnt;	// �ż�8�ܰ�켱ȣ���Ǽ�
	int l_lvl_9_trd_cnt;	// �ż�9�ܰ�켱ȣ���Ǽ�
	int l_lvl_10_trd_cnt;	// �ż�10�ܰ�켱ȣ���Ǽ�
	int total_s_trd_cnt;	// �ŵ���ȿȣ���Ǽ�
	int s_lvl_1_trd_cnt;	// �ŵ�1�ܰ�켱ȣ���Ǽ�
	int s_lvl_2_trd_cnt;	// �ŵ�2�ܰ�켱ȣ���Ǽ�
	int s_lvl_3_trd_cnt;	// �ŵ�3�ܰ�켱ȣ���Ǽ�
	int s_lvl_4_trd_cnt;	// �ŵ�4�ܰ�켱ȣ���Ǽ�
	int s_lvl_5_trd_cnt;	// �ŵ�5�ܰ�켱ȣ���Ǽ�
	int s_lvl_6_trd_cnt;	// �ŵ�6�ܰ�켱ȣ���Ǽ�
	int s_lvl_7_trd_cnt;	// �ŵ�7�ܰ�켱ȣ���Ǽ�
	int s_lvl_8_trd_cnt;	// �ŵ�8�ܰ�켱ȣ���Ǽ�
	int s_lvl_9_trd_cnt;	// �ŵ�9�ܰ�켱ȣ���Ǽ�
	int s_lvl_10_trd_cnt;	// �ŵ�10�ܰ�켱ȣ���Ǽ�
	char real_t_high_prc_sign;	// �ǽð����Ѱ���ȣ
	int real_t_high_prc;	// �ǽð����Ѱ�, ���߰��̵�����
	char real_t_low_prc_sign;	// �ǽð����Ѱ���ȣ
	int real_t_low_prc;	// �ǽð����Ѱ�, ���߰��̵�����
} DF_STOCK_FUT_EXEC_LIMIT_ORD;


// �ֽļ���_���񸶰�
typedef struct _DF_STOCK_FUT_CLOSE_PRODUCT {
	char data_clsf[3];	// DATA����, A6
	char info_clsf[3];	// ��������, 01:�����ֽļ���
	char mrk_clsf;	// ���屸��, 5
	char isin_clsf[13];	// �����ڵ�
	int stk_snr;	// �����Ϸù�ȣ
	char brd_id[3];	// ����ID, �ڵ尪��������
	char close_prc_sign;	// ������ȣ
	int close_prc;	// ����, * �ŷ��� ������ ��� ���ذ� set
	char close_prc_code;	// ���������ڵ�, 1:�Ǽ�, 3:�ŷ���\n 2:�⼼ -2012.05.14 ����\n ' ':�������� �ƴ� ��� space
	int accm_exe_q;	// ����ü�����
	double accm_trd_amt;	// �����ŷ����, ����:��
	int total_l_limit_ord_q;	// �ż���ȣ���ܷ�, �ڸ��� ����(7->8)
	char l_lvl_1_sign;	// �ż�1�ܰ��ȣ
	int l_lvl_1_prc;	// �ż�1�ܰ�켱ȣ������
	int l_lvl_1_q;	// �ż�1�ܰ�켱ȣ���ܷ�, �ڸ��� ����(6->7)
	char l_lvl_2_sign;	// �ż�2�ܰ��ȣ
	int l_lvl_2_prc;	// �ż�2�ܰ�켱ȣ������
	int l_lvl_2_q;	// �ż�2�ܰ�켱ȣ���ܷ�, �ڸ��� ����(6->7)
	char l_lvl_3_sign;	// �ż�3�ܰ��ȣ
	int l_lvl_3_prc;	// �ż�3�ܰ�켱ȣ������
	int l_lvl_3_q;	// �ż�3�ܰ�켱ȣ���ܷ�, �ڸ��� ����(6->7)
	char l_lvl_4_sign;	// �ż�4�ܰ��ȣ
	int l_lvl_4_prc;	// �ż�4�ܰ�켱ȣ������
	int l_lvl_4_q;	// �ż�4�ܰ�켱ȣ���ܷ�, �ڸ��� ����(6->7)
	char l_lvl_5_sign;	// �ż�5�ܰ��ȣ
	int l_lvl_5_prc;	// �ż�5�ܰ�켱ȣ������
	int l_lvl_5_q;	// �ż�5�ܰ�켱ȣ���ܷ�, �ڸ��� ����(6->7)
	char l_lvl_6_sign;	// �ż�6�ܰ��ȣ
	int l_lvl_6_prc;	// �ż�6�ܰ�켱ȣ������
	int l_lvl_6_q;	// �ż�6�ܰ�켱ȣ���ܷ�, �ڸ��� ����(6->7)
	char l_lvl_7_sign;	// �ż�7�ܰ��ȣ
	int l_lvl_7_prc;	// �ż�7�ܰ�켱ȣ������
	int l_lvl_7_q;	// �ż�7�ܰ�켱ȣ���ܷ�, �ڸ��� ����(6->7)
	char l_lvl_8_sign;	// �ż�8�ܰ��ȣ
	int l_lvl_8_prc;	// �ż�8�ܰ�켱ȣ������
	int l_lvl_8_q;	// �ż�8�ܰ�켱ȣ���ܷ�, �ڸ��� ����(6->7)
	char l_lvl_9_sign;	// �ż�9�ܰ��ȣ
	int l_lvl_9_prc;	// �ż�9�ܰ�켱ȣ������
	int l_lvl_9_q;	// �ż�9�ܰ�켱ȣ���ܷ�, �ڸ��� ����(6->7)
	char l_lvl_10_sign;	// �ż�10�ܰ��ȣ
	int l_lvl_10_prc;	// �ż�10�ܰ�켱ȣ������
	int l_lvl_10_q;	// �ż�10�ܰ�켱ȣ���ܷ�, �ڸ��� ����(6->7)
	int total_s_limit_ord_q;	// �ŵ���ȣ���ܷ�, �ڸ��� ����(7->8)
	char s_lvl_1_sign;	// �ŵ�1�ܰ��ȣ
	int s_lvl_1_prc;	// �ŵ�1�ܰ�켱ȣ������
	int s_lvl_1_q;	// �ŵ�1�ܰ�켱ȣ���ܷ�, �ڸ��� ����(6->7)
	char s_lvl_2_sign;	// �ŵ�2�ܰ��ȣ
	int s_lvl_2_prc;	// �ŵ�2�ܰ�켱ȣ������
	int s_lvl_2_q;	// �ŵ�2�ܰ�켱ȣ���ܷ�, �ڸ��� ����(6->7)
	char s_lvl_3_sign;	// �ŵ�3�ܰ��ȣ
	int s_lvl_3_prc;	// �ŵ�3�ܰ�켱ȣ������
	int s_lvl_3_q;	// �ŵ�3�ܰ�켱ȣ���ܷ�, �ڸ��� ����(6->7)
	char s_lvl_4_sign;	// �ŵ�4�ܰ��ȣ
	int s_lvl_4_prc;	// �ŵ�4�ܰ�켱ȣ������
	int s_lvl_4_q;	// �ŵ�4�ܰ�켱ȣ���ܷ�, �ڸ��� ����(6->7)
	char s_lvl_5_sign;	// �ŵ�5�ܰ��ȣ
	int s_lvl_5_prc;	// �ŵ�5�ܰ�켱ȣ������
	int s_lvl_5_q;	// �ŵ�5�ܰ�켱ȣ���ܷ�, �ڸ��� ����(6->7)
	char s_lvl_6_sign;	// �ŵ�6�ܰ��ȣ
	int s_lvl_6_prc;	// �ŵ�6�ܰ�켱ȣ������
	int s_lvl_6_q;	// �ŵ�6�ܰ�켱ȣ���ܷ�, �ڸ��� ����(6->7)
	char s_lvl_7_sign;	// �ŵ�7�ܰ��ȣ
	int s_lvl_7_prc;	// �ŵ�7�ܰ�켱ȣ������
	int s_lvl_7_q;	// �ŵ�7�ܰ�켱ȣ���ܷ�, �ڸ��� ����(6->7)
	char s_lvl_8_sign;	// �ŵ�8�ܰ��ȣ
	int s_lvl_8_prc;	// �ŵ�8�ܰ�켱ȣ������
	int s_lvl_8_q;	// �ŵ�8�ܰ�켱ȣ���ܷ�, �ڸ��� ����(6->7)
	char s_lvl_9_sign;	// �ŵ�9�ܰ��ȣ
	int s_lvl_9_prc;	// �ŵ�9�ܰ�켱ȣ������
	int s_lvl_9_q;	// �ŵ�9�ܰ�켱ȣ���ܷ�, �ڸ��� ����(6->7)
	char s_lvl_10_sign;	// �ŵ�10�ܰ��ȣ
	int s_lvl_10_prc;	// �ŵ�10�ܰ�켱ȣ������
	int s_lvl_10_q;	// �ŵ�10�ܰ�켱ȣ���ܷ�, �ڸ��� ����(6->7)
	int total_l_trd_cnt;	// �ż���ȿȣ���Ǽ�
	int l_lvl_1_trd_cnt;	// �ż�1�ܰ�켱ȣ���Ǽ�
	int l_lvl_2_trd_cnt;	// �ż�2�ܰ�켱ȣ���Ǽ�
	int l_lvl_3_trd_cnt;	// �ż�3�ܰ�켱ȣ���Ǽ�
	int l_lvl_4_trd_cnt;	// �ż�4�ܰ�켱ȣ���Ǽ�
	int l_lvl_5_trd_cnt;	// �ż�5�ܰ�켱ȣ���Ǽ�
	int l_lvl_6_trd_cnt;	// �ż�6�ܰ�켱ȣ���Ǽ�
	int l_lvl_7_trd_cnt;	// �ż�7�ܰ�켱ȣ���Ǽ�
	int l_lvl_8_trd_cnt;	// �ż�8�ܰ�켱ȣ���Ǽ�
	int l_lvl_9_trd_cnt;	// �ż�9�ܰ�켱ȣ���Ǽ�
	int l_lvl_10_trd_cnt;	// �ż�10�ܰ�켱ȣ���Ǽ�
	int total_s_trd_cnt;	// �ŵ���ȿȣ���Ǽ�
	int s_lvl_1_trd_cnt;	// �ŵ�1�ܰ�켱ȣ���Ǽ�
	int s_lvl_2_trd_cnt;	// �ŵ�2�ܰ�켱ȣ���Ǽ�
	int s_lvl_3_trd_cnt;	// �ŵ�3�ܰ�켱ȣ���Ǽ�
	int s_lvl_4_trd_cnt;	// �ŵ�4�ܰ�켱ȣ���Ǽ�
	int s_lvl_5_trd_cnt;	// �ŵ�5�ܰ�켱ȣ���Ǽ�
	int s_lvl_6_trd_cnt;	// �ŵ�6�ܰ�켱ȣ���Ǽ�
	int s_lvl_7_trd_cnt;	// �ŵ�7�ܰ�켱ȣ���Ǽ�
	int s_lvl_8_trd_cnt;	// �ŵ�8�ܰ�켱ȣ���Ǽ�
	int s_lvl_9_trd_cnt;	// �ŵ�9�ܰ�켱ȣ���Ǽ�
	int s_lvl_10_trd_cnt;	// �ŵ�10�ܰ�켱ȣ���Ǽ�
} DF_STOCK_FUT_CLOSE_PRODUCT;


// �ֽļ���_��TS
typedef struct _DF_STOCK_FUTURE_MRK_OP_TS {
	char data_clsf[3];	// DATA����, A7
	char info_clsf[3];	// ��������, 01:�����ֽļ���
	char mrk_clsf;	// ���屸��, 5
	char isin_clsf[13];	// �����ڵ�
	int stk_snr;	// �����Ϸù�ȣ
	char prd_id[12];	// ��ǰID, �ڵ尪�������� - spaceó��
	char brd_id[3];	// ����ID, �ڵ尪��������
	char brd_event_id[4];	// �����̺�ƮID, �ڵ尪��������
	char brd_event_start_t[9];	// �����̺�Ʈ���۽ð�, ������ �����(��:BB1(�ŸŰŷ�����)�� ��� 09000000)
	int brd_event_code;	// �����̺�Ʈ���뱺�ڵ�, �ڵ尪��������
	char ss_id[3];	// ����ID, �ڵ尪��������
	char ord_exist;	// ȣ������, 0:ȣ������(�����׸� ����), 1:ȣ������(�����׸� ���)
	int total_l_limit_ord_q;	// �ż���ȣ���ܷ�, �ڸ��� ����(7->8)
	char l_lvl_1_sign;	// �ż�1�ܰ��ȣ
	int l_lvl_1_prc;	// �ż�1�ܰ�켱ȣ������
	int l_lvl_1_q;	// �ż�1�ܰ�켱ȣ���ܷ�, �ڸ��� ����(6->7)
	char l_lvl_2_sign;	// �ż�2�ܰ��ȣ
	int l_lvl_2_prc;	// �ż�2�ܰ�켱ȣ������
	int l_lvl_2_q;	// �ż�2�ܰ�켱ȣ���ܷ�, �ڸ��� ����(6->7)
	char l_lvl_3_sign;	// �ż�3�ܰ��ȣ
	int l_lvl_3_prc;	// �ż�3�ܰ�켱ȣ������
	int l_lvl_3_q;	// �ż�3�ܰ�켱ȣ���ܷ�, �ڸ��� ����(6->7)
	char l_lvl_4_sign;	// �ż�4�ܰ��ȣ
	int l_lvl_4_prc;	// �ż�4�ܰ�켱ȣ������
	int l_lvl_4_q;	// �ż�4�ܰ�켱ȣ���ܷ�, �ڸ��� ����(6->7)
	char l_lvl_5_sign;	// �ż�5�ܰ��ȣ
	int l_lvl_5_prc;	// �ż�5�ܰ�켱ȣ������
	int l_lvl_5_q;	// �ż�5�ܰ�켱ȣ���ܷ�, �ڸ��� ����(6->7)
	char l_lvl_6_sign;	// �ż�6�ܰ��ȣ
	int l_lvl_6_prc;	// �ż�6�ܰ�켱ȣ������
	int l_lvl_6_q;	// �ż�6�ܰ�켱ȣ���ܷ�, �ڸ��� ����(6->7)
	char l_lvl_7_sign;	// �ż�7�ܰ��ȣ
	int l_lvl_7_prc;	// �ż�7�ܰ�켱ȣ������
	int l_lvl_7_q;	// �ż�7�ܰ�켱ȣ���ܷ�, �ڸ��� ����(6->7)
	char l_lvl_8_sign;	// �ż�8�ܰ��ȣ
	int l_lvl_8_prc;	// �ż�8�ܰ�켱ȣ������
	int l_lvl_8_q;	// �ż�8�ܰ�켱ȣ���ܷ�, �ڸ��� ����(6->7)
	char l_lvl_9_sign;	// �ż�9�ܰ��ȣ
	int l_lvl_9_prc;	// �ż�9�ܰ�켱ȣ������
	int l_lvl_9_q;	// �ż�9�ܰ�켱ȣ���ܷ�, �ڸ��� ����(6->7)
	char l_lvl_10_sign;	// �ż�10�ܰ��ȣ
	int l_lvl_10_prc;	// �ż�10�ܰ�켱ȣ������
	int l_lvl_10_q;	// �ż�10�ܰ�켱ȣ���ܷ�, �ڸ��� ����(6->7)
	int total_s_limit_ord_q;	// �ŵ���ȣ���ܷ�, �ڸ��� ����(7->8)
	char s_lvl_1_sign;	// �ŵ�1�ܰ��ȣ
	int s_lvl_1_prc;	// �ŵ�1�ܰ�켱ȣ������
	int s_lvl_1_q;	// �ŵ�1�ܰ�켱ȣ���ܷ�, �ڸ��� ����(6->7)
	char s_lvl_2_sign;	// �ŵ�2�ܰ��ȣ
	int s_lvl_2_prc;	// �ŵ�2�ܰ�켱ȣ������
	int s_lvl_2_q;	// �ŵ�2�ܰ�켱ȣ���ܷ�, �ڸ��� ����(6->7)
	char s_lvl_3_sign;	// �ŵ�3�ܰ��ȣ
	int s_lvl_3_prc;	// �ŵ�3�ܰ�켱ȣ������
	int s_lvl_3_q;	// �ŵ�3�ܰ�켱ȣ���ܷ�, �ڸ��� ����(6->7)
	char s_lvl_4_sign;	// �ŵ�4�ܰ��ȣ
	int s_lvl_4_prc;	// �ŵ�4�ܰ�켱ȣ������
	int s_lvl_4_q;	// �ŵ�4�ܰ�켱ȣ���ܷ�, �ڸ��� ����(6->7)
	char s_lvl_5_sign;	// �ŵ�5�ܰ��ȣ
	int s_lvl_5_prc;	// �ŵ�5�ܰ�켱ȣ������
	int s_lvl_5_q;	// �ŵ�5�ܰ�켱ȣ���ܷ�, �ڸ��� ����(6->7)
	char s_lvl_6_sign;	// �ŵ�6�ܰ��ȣ
	int s_lvl_6_prc;	// �ŵ�6�ܰ�켱ȣ������
	int s_lvl_6_q;	// �ŵ�6�ܰ�켱ȣ���ܷ�, �ڸ��� ����(6->7)
	char s_lvl_7_sign;	// �ŵ�7�ܰ��ȣ
	int s_lvl_7_prc;	// �ŵ�7�ܰ�켱ȣ������
	int s_lvl_7_q;	// �ŵ�7�ܰ�켱ȣ���ܷ�, �ڸ��� ����(6->7)
	char s_lvl_8_sign;	// �ŵ�8�ܰ��ȣ
	int s_lvl_8_prc;	// �ŵ�8�ܰ�켱ȣ������
	int s_lvl_8_q;	// �ŵ�8�ܰ�켱ȣ���ܷ�, �ڸ��� ����(6->7)
	char s_lvl_9_sign;	// �ŵ�9�ܰ��ȣ
	int s_lvl_9_prc;	// �ŵ�9�ܰ�켱ȣ������
	int s_lvl_9_q;	// �ŵ�9�ܰ�켱ȣ���ܷ�, �ڸ��� ����(6->7)
	char s_lvl_10_sign;	// �ŵ�10�ܰ��ȣ
	int s_lvl_10_prc;	// �ŵ�10�ܰ�켱ȣ������
	int s_lvl_10_q;	// �ŵ�10�ܰ�켱ȣ���ܷ�, �ڸ��� ����(6->7)
	int total_l_trd_cnt;	// �ż���ȿȣ���Ǽ�
	int l_lvl_1_trd_cnt;	// �ż�1�ܰ�켱ȣ���Ǽ�
	int l_lvl_2_trd_cnt;	// �ż�2�ܰ�켱ȣ���Ǽ�
	int l_lvl_3_trd_cnt;	// �ż�3�ܰ�켱ȣ���Ǽ�
	int l_lvl_4_trd_cnt;	// �ż�4�ܰ�켱ȣ���Ǽ�
	int l_lvl_5_trd_cnt;	// �ż�5�ܰ�켱ȣ���Ǽ�
	int l_lvl_6_trd_cnt;	// �ż�6�ܰ�켱ȣ���Ǽ�
	int l_lvl_7_trd_cnt;	// �ż�7�ܰ�켱ȣ���Ǽ�
	int l_lvl_8_trd_cnt;	// �ż�8�ܰ�켱ȣ���Ǽ�
	int l_lvl_9_trd_cnt;	// �ż�9�ܰ�켱ȣ���Ǽ�
	int l_lvl_10_trd_cnt;	// �ż�10�ܰ�켱ȣ���Ǽ�
	int total_s_trd_cnt;	// �ŵ���ȿȣ���Ǽ�
	int s_lvl_1_trd_cnt;	// �ŵ�1�ܰ�켱ȣ���Ǽ�
	int s_lvl_2_trd_cnt;	// �ŵ�2�ܰ�켱ȣ���Ǽ�
	int s_lvl_3_trd_cnt;	// �ŵ�3�ܰ�켱ȣ���Ǽ�
	int s_lvl_4_trd_cnt;	// �ŵ�4�ܰ�켱ȣ���Ǽ�
	int s_lvl_5_trd_cnt;	// �ŵ�5�ܰ�켱ȣ���Ǽ�
	int s_lvl_6_trd_cnt;	// �ŵ�6�ܰ�켱ȣ���Ǽ�
	int s_lvl_7_trd_cnt;	// �ŵ�7�ܰ�켱ȣ���Ǽ�
	int s_lvl_8_trd_cnt;	// �ŵ�8�ܰ�켱ȣ���Ǽ�
	int s_lvl_9_trd_cnt;	// �ŵ�9�ܰ�켱ȣ���Ǽ�
	int s_lvl_10_trd_cnt;	// �ŵ�10�ܰ�켱ȣ���Ǽ�
	char real_t_high_prc_sign;	// �ǽð����Ѱ���ȣ
	int real_t_high_prc;	// �ǽð����Ѱ�, ���߰��̵�����
	char real_t_low_prc_sign;	// �ǽð����Ѱ���ȣ
	int real_t_low_prc;	// �ǽð����Ѱ�, ���߰��̵�����
} DF_STOCK_FUTURE_MRK_OP_TS;


// �ֽļ���_����
typedef struct _DF_STOCK_FUTURE_CLOSE {
	char data_clsf[3];	// DATA����, H0
	char info_clsf[3];	// ��������, 01:�����ֽļ���
	char mrk_clsf;	// ���屸��, 5
} DF_STOCK_FUTURE_CLOSE;


// �ֽļ���_�������ٰ���
typedef struct _DF_STOCK_FUT_MRK_OP_SCHD {
	char data_clsf[3];	// DATA����, M4
	char info_clsf[3];	// ��������, 01:�����ֽļ���
	char mrk_clsf;	// ���屸��, 5
	char isin_clsf[13];	// �����ڵ�, *�������� �� ��ġ�� ���
	int stk_snr;	// �����Ϸù�ȣ, *�������� �� ��ġ�� ���
	char prd_id[12];	// ��ǰID, �ڵ尪�������� - �ֽļ��� ��ü�忡 ���ؼ��� spaceó��\n �����ڻ꺰 �̺�Ʈ �߻��� ��ǰID�Է�
	char mrk_prd_id[4];	// ����ǰ�׷�ID, FST : �ڽ��� �ֽļ���\nFKQ : �ڽ��� �ֽļ���
	char brd_id[3];	// ����ID, �ڵ尪��������
	char brd_event_id[4];	// �����̺�ƮID, �ڵ尪��������
	char brd_event_start_t[9];	// �����̺�Ʈ���۽ð�
	int brd_event_code;	// �����̺�Ʈ���뱺�ڵ�, �ڵ尪���� ����
	char ss_open_close_code[3];	// ���ǰ��������ڵ�, BS:���尳��\n BE:��������\n SS:���ǰ���\n SE:��������\n SH:��������\n SR:�����簳
	char ss_id[3];	// ����ID, �ڵ尪��������
	int adj_stage;	// ����ܰ�, CB �� ���������� Ȯ��� ����Ǵ� �ܰ� \n��)�ʱⰪ 00
	char under_asset_prc_chg;	// �������񰡰�Ȯ��߻��ڵ�, ���������� ����Ȯ��� �����ڵ�(U:���, D:�϶�)
	char exp_prc_chg_t[9];	// ����Ȯ�뿹���ð�, �Ļ����尡��Ȯ�� ���� �̺�Ʈ �߻��� ���Ǵ� �׸����� ����Ȯ�뿹���ð��� ��ϵ�
} DF_STOCK_FUT_MRK_OP_SCHD;


// �ֽļ���_�������
typedef struct _DF_STOCK_FUT_DIST_INFO {
	char data_clsf[3];	// DATA����, O6
	char info_clsf[3];	// ��������, 01:�����ֽļ���
	char mrk_clsf;	// ���屸��, 5
	char isin_clsf[13];	// �����ڵ�
	int stk_snr;	// �����Ϸù�ȣ
	char brd_id[3];	// ����ID, �ڵ尪��������
	char dist_adj_code;	// ������뱸���ڵ�, 1:��а���, 2:�������
	char dist_code;	// ���ó�������ڵ�, 1:�ż�����, 2:�ż�����,\n 3:�ŵ�����, 4:�ŵ�����\n *��������� �ڵ����(spaceó��)
	char dist_cls_t[9];	// ��������ð�
} DF_STOCK_FUT_DIST_INFO;


// �ֽļ���_�ǽð������Ѱ� ���������
typedef struct _DF_STOCK_FUT_REAL_HIGH_LOW_LIMIT_ON_OFF {
	char data_clsf[3];	// DATA����, Q2
	char info_clsf[3];	// ��������, 01:�����ֽļ���
	char mrk_clsf;	// ���屸��, 5
	char isin_clsf[13];	// �����ڵ�
	int stk_snr;	// �����Ϸù�ȣ
	char brd_id[3];	// ����ID, �ڵ尪��������
	char cleared_t[9];	// ó���ð�
	char real_t_prc_limit_code;	// �ǽð��������Ѽ����ڵ�, 0: ����, 1: ����, 2: �缳��
	char real_t_high_prc_sign;	// �ǽð����Ѱ���ȣ
	int real_t_high_prc;	// �ǽð����Ѱ�, ���߰��̵�����
	char real_t_low_prc_sign;	// �ǽð����Ѱ���ȣ
	int real_t_low_prc;	// �ǽð����Ѱ�, ���߰��̵�����
} DF_STOCK_FUT_REAL_HIGH_LOW_LIMIT_ON_OFF;


// �ֽļ���_����������Ȯ��ߵ�
typedef struct _DF_STOCK_FUT_PRC_LIMIT_ON {
	char data_clsf[3];	// DATA����, V1
	char info_clsf[3];	// ��������, 01:�ֽļ���
	char mrk_clsf;	// ���屸��, 5
	char code_clsf[13];	// �����ڵ�
	int stk_snr;	// �����Ϸù�ȣ
	char prd_id[12];	// ��ǰID, �ڵ尪�������� : spaceó��
	char brd_id[3];	// ����ID, �ڵ尪��������
	char prc_limit_start_t[9];	// ����Ȯ��ð�, ������ Ȯ��� �ð�
	int prc_limit_high;	// ��������Ȯ����Ѵܰ�, ����� ���Ѵܰ�
	int prc_limit_low;	// ��������Ȯ�����Ѵܰ�, ����� ���Ѵܰ�
	char high_prc_sign;	// ���Ѱ���ȣ
	int high_prc;	// ���Ѱ�, ����� ���Ѱ�\n��)9999999
	char low_prc_sign;	// ���Ѱ���ȣ
	int low_prc;	// ���Ѱ�, ����� ���Ѱ�\n��)9999999
} DF_STOCK_FUT_PRC_LIMIT_ON;


// �ֽļ���_�̰����������� ������
typedef struct _DF_STOCK_FUT_OPEN_INTEREST_DATA {
	char data_clsf[3];	// DATA����, H2
	char info_clsf[3];	// ��������, 01:�����ֽļ���
	char mrk_clsf;	// ���屸��, 5
	char isin_clsf[13];	// �����ڵ�, ���� record '999999999999' set
	int stk_snr;	// ����SEQ
	char open_interest_clsf[3];	// �̰�����������, ���� Ȯ�� : "M0" (07:40�а� ����)\n���� ���� : "M1" (���� Ư���������� ��������\n         �۽�, 10��)\n���� Ȯ�� : "M2" (���� ������ �۽�,\n         ������ 1�ð��� ����)
	char traded_date[9];	// �ŷ�����
	int open_interest_q;	// �̰�����������, ����:���
} DF_STOCK_FUT_OPEN_INTEREST_DATA;


// �ֽļ���_���갡�� ������
typedef struct _DF_STOCK_FUT_SETT_PRC_DATA {
	char data_clsf[3];	// DATA����, H3
	char info_clsf[3];	// ��������, 01:�����ֽļ���
	char mrk_clsf;	// ���屸��, 5
	char isin_clsf[13];	// �����ڵ�, ���� record '999999999999' set
	int stk_snr;	// ����SEQ
	double calc_prc;	// ���갡��, ��) 99999999.99999999
	char calc_prc_clsf;	// ���갡�ݱ���, 0 : ���갡 ����(���� �ŷ������� �⼼ ����)\n1 : ���� ����(�Ǽ�)\n2 : ���� �⼼(���� �ŷ������� �⼼) - 2010.12.20 ����\n3 : ���� ���갡(���� �ŷ������� ���� ������) - 2010.12.20 ����\n4 : ���� �̷а�(���� �ŷ������� ���� ������)\n5 : ��������ŷ��� ���� ������ ������ ���� - 2010.12.20 ����\n6 : ������ ���� ���갡 - 2010.12.20 ����\n7 : ����ڻ� ����(�̷а����»�ǰ)\n8 : ������ذ��� - 2010.12.20 �߰�
	double final_sett_prc;	// ������������, ��) 99999999.99999999
	char final_sett_clsf;	// �����������ݱ���
} DF_STOCK_FUT_SETT_PRC_DATA;


// �ֽļ���_�����ü�Recovery ������
typedef struct _DF_STOCK_FUT_RECOVERY_DATA {
	char data_clsf[3];	// DATA����, B2
	char info_clsf[3];	// ��������, 01:�����ֽļ���
	char mrk_clsf;	// ���屸��, 5
	char isin_clsf[13];	// �����ڵ�
	int stk_snr;	// �����Ϸù�ȣ
	char cur_prc_sign;	// ���簡��ȣ
	int cur_prc;	// ���簡
	int rct_prd_prc;	// �ֱٿ��� ������������
	int nxt_prd_prc;	// ������ ������������
	char init_prc_sign;	// �ð���ȣ
	int init_prc;	// �ð�
	char high_prc_sign;	// ����ȣ
	int high_prc;	// ��
	char low_prc_sign;	// ������ȣ
	int low_prc;	// ����
	int open_interest_q;	// �̰�����
	int accm_exe_q;	// ����ü�����
	double accm_trd_amt;	// �����ŷ����, ����:��
	char l_or_s;	// �����ŵ��ż������ڵ�, 1:�ŵ�,2:�ż�(�������� ���� ȣ���� �ŵ��ż����а�)
	char s_lvl_1_sign;	// SIGN��ȣ
	int s_lvl_1_prc;	// �ŵ�1ȣ��
	int s_lvl_1_q;	// �ŵ�1ȣ������, �ڸ��� ����(6->7)
	int s_lvl_1_trd_cnt;	// �ŵ�1ȣ���Ǽ�
	char l_lvl_1_sign;	// SIGN��ȣ
	int l_lvl_1_prc;	// �ż�1ȣ��
	int l_lvl_1_q;	// �ż�1ȣ������, �ڸ��� ����(6->7)
	int l_lvl_1_trd_cnt;	// �ż�1ȣ���Ǽ�
	char s_lvl_2_sign;	// SIGN��ȣ
	int s_lvl_2_prc;	// �ŵ�2ȣ��
	int s_lvl_2_q;	// �ŵ�2ȣ������, �ڸ��� ����(6->7)
	int s_lvl_2_trd_cnt;	// �ŵ�2ȣ���Ǽ�
	char l_lvl_2_sign;	// SIGN��ȣ
	int l_lvl_2_prc;	// �ż�2ȣ��
	int l_lvl_2_q;	// �ż�2ȣ������, �ڸ��� ����(6->7)
	int l_lvl_2_trd_cnt;	// �ż�2ȣ���Ǽ�
	char s_lvl_3_sign;	// SIGN��ȣ
	int s_lvl_3_prc;	// �ŵ�3ȣ��
	int s_lvl_3_q;	// �ŵ�3ȣ������, �ڸ��� ����(6->7)
	int s_lvl_3_trd_cnt;	// �ŵ�3ȣ���Ǽ�
	char l_lvl_3_sign;	// SIGN��ȣ
	int l_lvl_3_prc;	// �ż�3ȣ��
	int l_lvl_3_q;	// �ż�3ȣ������, �ڸ��� ����(6->7)
	int l_lvl_3_trd_cnt;	// �ż�3ȣ���Ǽ�
	char s_lvl_4_sign;	// SIGN��ȣ
	int s_lvl_4_prc;	// �ŵ�4ȣ��
	int s_lvl_4_q;	// �ŵ�4ȣ������, �ڸ��� ����(6->7)
	int s_lvl_4_trd_cnt;	// �ŵ�4ȣ���Ǽ�
	char l_lvl_4_sign;	// SIGN��ȣ
	int l_lvl_4_prc;	// �ż�4ȣ��
	int l_lvl_4_q;	// �ż�4ȣ������, �ڸ��� ����(6->7)
	int l_lvl_4_trd_cnt;	// �ż�4ȣ���Ǽ�
	char s_lvl_5_sign;	// SIGN��ȣ
	int s_lvl_5_prc;	// �ŵ�5ȣ��
	int s_lvl_5_q;	// �ŵ�5ȣ������, �ڸ��� ����(6->7)
	int s_lvl_5_trd_cnt;	// �ŵ�5ȣ���Ǽ�
	char l_lvl_5_sign;	// SIGN��ȣ
	int l_lvl_5_prc;	// �ż�5ȣ��
	int l_lvl_5_q;	// �ż�5ȣ������, �ڸ��� ����(6->7)
	int l_lvl_5_trd_cnt;	// �ż�5ȣ���Ǽ�
	char s_lvl_6_sign;	// SIGN��ȣ
	int s_lvl_6_prc;	// �ŵ�6ȣ��
	int s_lvl_6_q;	// �ŵ�6ȣ������, �ڸ��� ����(6->7)
	int s_lvl_6_trd_cnt;	// �ŵ�6ȣ���Ǽ�
	char l_lvl_6_sign;	// SIGN��ȣ
	int l_lvl_6_prc;	// �ż�6ȣ��
	int l_lvl_6_q;	// �ż�6ȣ������, �ڸ��� ����(6->7)
	int l_lvl_6_trd_cnt;	// �ż�6ȣ���Ǽ�
	char s_lvl_7_sign;	// SIGN��ȣ
	int s_lvl_7_prc;	// �ŵ�7ȣ��
	int s_lvl_7_q;	// �ŵ�7ȣ������, �ڸ��� ����(6->7)
	int s_lvl_7_trd_cnt;	// �ŵ�7ȣ���Ǽ�
	char l_lvl_7_sign;	// SIGN��ȣ
	int l_lvl_7_prc;	// �ż�7ȣ��
	int l_lvl_7_q;	// �ż�7ȣ������, �ڸ��� ����(6->7)
	int l_lvl_7_trd_cnt;	// �ż�7ȣ���Ǽ�
	char s_lvl_8_sign;	// SIGN��ȣ
	int s_lvl_8_prc;	// �ŵ�8ȣ��
	int s_lvl_8_q;	// �ŵ�8ȣ������, �ڸ��� ����(6->7)
	int s_lvl_8_trd_cnt;	// �ŵ�8ȣ���Ǽ�
	char l_lvl_8_sign;	// SIGN��ȣ
	int l_lvl_8_prc;	// �ż�8ȣ��
	int l_lvl_8_q;	// �ż�8ȣ������, �ڸ��� ����(6->7)
	int l_lvl_8_trd_cnt;	// �ż�8ȣ���Ǽ�
	char s_lvl_9_sign;	// SIGN��ȣ
	int s_lvl_9_prc;	// �ŵ�9ȣ��
	int s_lvl_9_q;	// �ŵ�9ȣ������, �ڸ��� ����(6->7)
	int s_lvl_9_trd_cnt;	// �ŵ�9ȣ���Ǽ�
	char l_lvl_9_sign;	// SIGN��ȣ
	int l_lvl_9_prc;	// �ż�9ȣ��
	int l_lvl_9_q;	// �ż�9ȣ������, �ڸ��� ����(6->7)
	int l_lvl_9_trd_cnt;	// �ż�9ȣ���Ǽ�
	char s_lvl_10_sign;	// SIGN��ȣ
	int s_lvl_10_prc;	// �ŵ�10ȣ��
	int s_lvl_10_q;	// �ŵ�10ȣ������, �ڸ��� ����(6->7)
	int s_lvl_10_trd_cnt;	// �ŵ�10ȣ���Ǽ�
	char l_lvl_10_sign;	// SIGN��ȣ
	int l_lvl_10_prc;	// �ż�10ȣ��
	int l_lvl_10_q;	// �ż�10ȣ������, �ڸ��� ����(6->7)
	int l_lvl_10_trd_cnt;	// �ż�10ȣ���Ǽ�
	int total_s_limit_ord_q;	// �ŵ� ��ȣ������, �ڸ��� ����(7->8)
	int total_s_trd_cnt;	// �ŵ���ȿȣ���Ǽ�
	int total_l_limit_ord_q;	// �ż� ��ȣ������, �ڸ��� ����(7->8)
	int total_l_trd_cnt;	// �ż���ȿȣ���Ǽ�
	char ss_id[3];	// ����ID, �ڵ尪��������
	char brd_id[3];	// ����ID, �ڵ尪��������
	char brd_event_id[4];	// �����̺�ƮID, B2 ������ �����̺�ƮID ������(���� ���°��� ���۵� �� ����). ����, �ش� �׸� '000' ���� ����. 2014.03.24)
	int exp_prc;	// ����ü�ᰡ��, ���ϰ��ŸŽø� ����\n (����±����ڵ�:10,20,30,80)
	char real_t_high_prc_sign;	// �ǽð����Ѱ���ȣ
	int real_t_high_prc;	// �ǽð����Ѱ�, ���߰��̵�����
	char real_t_low_prc_sign;	// �ǽð����Ѱ���ȣ
	int real_t_low_prc;	// �ǽð����Ѱ�, ���߰��̵�����
} DF_STOCK_FUT_RECOVERY_DATA;


// �ֽļ���_������ ������
typedef struct _DF_STOCK_FUT_INVESTOR_DATA {
	char data_clsf[3];	// DATA����, H1
	char info_clsf[3];	// ��������, 01:�����ֽļ���
	char mrk_clsf;	// ���屸��, 5
	char created_date[9];	// ��������
	char created_time[7];	// �����ð�
	char inv_data_clsf[3];	// �����ͱ���, *����Ȯ�� : 00, �������� : 01, ����Ȯ�� : 02\n *E1 : ���� ������ �Ϸ�, E2 : Ȯ�� ������ �Ϸ�\n ���� record '99' set
	char prd_id[12];	// ��ǰID, �ڵ尪�������� - ������ü(KRDRVFU999 )
	char inv_clsf[5];	// ����������, �ڵ尪���� ���� *�ڵ� '7000'�� ����,��������׸� 0���� ����
	int long_exe_q;	// �ż���������
	int short_exe_q;	// �ŵ���������
	double long_traded_amt;	// �ż��������
	double short_traded_amt;	// �ŵ��������
	int spread_long_exe_q;	// �������忡 ���� ������ �ż� ��������
	int spread_short_exe_q;	// �������忡 ���� ������ �ŵ� ��������
	double spread_long_traded_amt;	// �������忡 ���� ������ �ż� �������
	double spread_short_traded_amt;	// �������忡 ���� ������ �ŵ� �������
} DF_STOCK_FUT_INVESTOR_DATA;


// �ֽļ���_����+�����ջ�
typedef struct _DF_STOCK_FUT_COMP_BLOCK {
	char data_clsf[3];	// DATA����, C4
	char info_clsf[3];	// ��������, 01:�����ֽļ���
	char mkt_clsf;	// ���屸��, 5
	char isin_clsf[13];	// �����ڵ�
	int stk_snr;	// �����Ϸù�ȣ
	double cpt_block_trd_vol;	// ����+�����ջ� �ŷ���, ����Ÿſ� ���Ǵ뷮�ŷ��� �ջ��� �ŷ���
	double cpt_block_trd_amt;	// ����+�����ջ� �ŷ����, ����Ÿſ� ���Ǵ뷮�ŷ��� �ջ��� �ŷ����\n(���� : ��)
} DF_STOCK_FUT_COMP_BLOCK;


// �ֽļ���_�������� ������
typedef struct _DF_STOCK_FUT_PRD_INFO_DATA {
	char data_clsf[3];	// DATA����, A0
	char info_clsf[3];	// ��������, 01:�����ֽļ���
	char mrk_clsf;	// ���屸��, 5
	int prd_cnt;	// �����
	char trd_date[9];	// ��������(��ȸ����)
	char isin_clsf[13];	// �����ڵ�, ���� record '999999999999' set
	int stk_snr;	// ����SEQ
	char prd_id[12];	// ��ǰID, * �ڵ尪 ������ ����\n* ����Ī: �Ļ���ǰID\n10 => 11, 20140303
	char sh_prd_code[10];	// ��������ڵ�, ��) KR4101C90009 �� K101C9000
	char prd_name_kor[81];	// �����ѱ۸�
	char sh_prd_name_kor[41];	// �����ѱ۾��
	char prd_name_eng[81];	// ���񿵹���
	char sh_prd_name_eng[41];	// ���񿵹����
	char listing_date[9];	// ��������
	char de_listing_date[9];	// ������������
	char spread_clsf_code;	// ��������������񱸺��ڵ�, ���������� ������ �Ǵ� ������ ISIN ǥ���ڵ�\n--�ڵ尪--\nF: ������(�ð���������)\nN: �ٿ���(�ð���������)\n20140303
	char final_sett_code;	// ������������ڵ�, ���ݰ���, �ǹ��μ������� �� �Ļ���ǰ�� �������� ���\n--�ڵ尪--\nC: ���ݰ���\nD: �ǹ��μ�������\nA: ����+�ǹ��μ�������\n0: �ش����\n20140303
	char prc_limit_exp_dir;	// ��������Ȯ������ڵ�, ���������� �ٴܰ�� ���ǵǴ� ��� ���� �ܰ�� Ȯ��Ǵ� ����� ������ �� Ȯ�븦 �����ϴ� ����\n## �ڵ尪##\nX:������\nF:������\nB:������\nT:�����
	int prc_limit_final_stg;	// ��������Ȯ����������ڵ�, ���������� �ٴܰ�� ���ǵǴ� ��� ������ �����ܰ��ȣ
	char prc_limit_stg_1_hgh_sign;	// ��������1�ܰ�SIGN��ȣ
	double prc_limit_stg_1_high_prc;	// ��������1�ܰ���Ѱ�, ��) 9999999999.99
	char prc_limit_stg_1_low_sign;	// ��������1�ܰ�SIGN��ȣ
	double prc_limit_stg_1_low_prc;	// ��������1�ܰ����Ѱ�, ��) 9999999999.99
	char prc_limit_stg_2_high_sign;	// ��������2�ܰ�SIGN��ȣ
	double prc_limit_stg_2_high_prc;	// ��������2�ܰ���Ѱ�, ��) 9999999999.99
	char prc_limit_stg_2_low_sign;	// ��������2�ܰ�SIGN��ȣ
	double prc_limit_stg_2_low_prc;	// ��������2�ܰ����Ѱ�, ��) 9999999999.99
	char prc_limit_stg_3_high_sign;	// ��������3�ܰ�SIGN��ȣ
	double prc_limit_stg_3_high_prc;	// ��������3�ܰ���Ѱ�, ��) 9999999999.99
	char prc_limit_stg_3_low_sign;	// ��������3�ܰ�SIGN��ȣ
	double prc_limit_stg_3_low_prc;	// ��������3�ܰ����Ѱ�, ��) 9999999999.99
	double stand_prc;	// ���ذ�, ��) 9999999999.99
	char under_asset_id[4];	// �����ڻ�ID, ��) K2I:KOSPI200����, KQI:�ڽ���150����,\n   Sxx:�����ֽ�, BM3:��3�ⱹä,\n   BM5:��5�ⱹä, BMA:��10�ⱹä, \n   CDR:CD, USD:�̱��޷�, JPY:�Ϻ���,\n   EUR:��������,\n   GLD:��, LHG:����\n20140303
	char opt_type_code;	// �Ǹ���������ڵ�, A:�̱���,E:������,B:���´���,Z:��Ÿ\n20140303
	char spread_str_code[3];	// �������屸���ڵ�, Combination ȣ���� ��ü�� �������幰�� ���񱸼�.\n--�ڵ尪--\n- T1: �ֱٿ���+2°����\n      > T2, T3, T4, ...\n*����Ī: �������������ڵ�\n20140303
	char spread_prd_code_1[13];	// �������屸�������ڵ�1, * ����Ī: ��������ٿ��� �����ڵ�\n�ٿ��� ǥ���ڵ�\n20140303
	char spread_prd_code_2[13];	// �������屸�������ڵ�2, * ����Ī : ������������� �����ڵ�\n������ ǥ���ڵ�\n20140303
	char last_trading_date[9];	// �����ŷ�����
	char final_sett_date[9];	// ������������
	int cont_month_nbr;	// ��������ȣ, * ����Ī: ���������ڵ�\n1:�ֱٿ���,������������\n2:2°����\n3:3°����\n4:4°����\n5:5°����\n6:6°����\n7:7°����      �� �ֱٿ������� ��ġ\nX => 9, 1 => 3, 20140303
	char maturity_date[9];	// ��������, �Ǹ���� ������ ��������
	double exe_prc;	// ��簡��, ��) 999999999.99999999
	char adjust_clsf_code;	// ���������ڵ�, �����ڻ��� ���ذ��� ������ ����� ����(�̰�������)���� ������� ����(�ŷ��¼�����)������ ����\n--�ڵ尪--\nN: ����\nO: �̰�������\nC: �ŷ��¼�����\n20140303
	double prd_unit;	// �ŷ�����, 1��࿡ �ش��ϴ� �����ڻ����\n��) 999999999.99999999
	double multiplier;	// �ŷ��¼�, ������� �� ������ ����ϴ� ���¼�\n��) 9999999999999.99999999
	char mrk_cnst_code;	// �������������ڵ�, 0:�̽�����������\n1:���Ͻ�����������\n2:���Ž�����������
	char listing_type_code;	// ���������ڵ�, 1:�űԻ���\n2:�߰�����\n3:��������\n4:���ʻ���\n5:��������\n6:Ư������
	double atm_prc;	// ���, �����ڻ���ذ��ݿ� ���� ����� ��簡��\n��) 9999999999.99
	char adj_reason_code[3];	// ���������ڵ�, 00:�ش���׾���, 01:�Ǹ���, 02:����,\n03:�й��, 04:�ǹ��, 05:�߰�����,\n06:�Ǹ��߰�����, 99:��Ÿ
	char under_asset_prd_code[13];	// �����ڻ������ڵ�
	double under_asset_close_prc;	// �����ڻ�����, ��) 9999999999.99
	int left_until_maturity;	// �����ϼ�
	double adj_std_prc;	// �������ذ���, �ֽ��Ļ���ǰ�� �����ֱ� �������ذ���\n��) 999999999.99999999
	char std_prc_clsf_code[3];	// ���ذ��ݱ����ڵ�, *����\nspcace:���ذ� ����(���� ������������)\n11:�������갡\n12:���ϱ��ذ�(�ŷ������� ����������)\n13:�����̷а�(�ŷ������� ����������)\n14:���ϱ⼼(�ŷ������� �⼼����)\n  -2012.05.14 ����\n15:�����̷а�(�ŷ������� �⼼����)-\n  -2012.05.14 ����\n16:������ �������갡\n17:������ ���ϱ��ذ�\n  (�ŷ������� ����������)\n18:������ ���ϱ⼼(�ŷ������� �⼼����)\n  -2012.05.14 ����\n19:���� ����ڻ� ����(�̷а����� ��ǰ)\n*�ɼ�\n21:�������űݱ��ذ�\n22:���ϱ��ذ�(�ŷ������� ����������)\n23:�����̷а�(�ŷ������� ����������)\n24:���ϱ⼼(�ŷ������� �⼼����)\n  -2012.05.14 ����\n25:������ �������űݱ��ذ�\n26:������ ���ϱ��ذ�\n  (�ŷ������� ����������)\n27:������ ���ϱ⼼(�ŷ������� �⼼����)\n  -2012.05.14 ����
	char trd_std_prc_clsf_code;	// �Ÿſ���ذ��ݱ����ڵ�, 0:�ش����\n1:�Ǽ�\n2:�⼼\n3:�̷а�\n4:����ڻ�����
	char yest_adj_close_prc_sign;	// SIGN��ȣ
	double yest_adj_close_prc;	// ������������, �ֽ��Ļ���ǰ�� ��������\n��) 999999999.99999999
	char block_trd_clsf;	// ���Ǵ뷮�ŸŴ�󿩺�, Y:���ǸŸŻ�ǰ, N:���ƴ�\n����ǰ��:3�⹰��ä����, �̱��޷�����,\n      ���μ���, ������
	double yest_mrg_std_prc;	// �������űݱ��ذ���, ��) 999999999.99999999
	char yest_mrg_std_prc_clsf_code[3];	// �������űݱ��ذ��ݱ����ڵ�, *�ɼ�\n20:���ű� ���ذ� ����\n21:��������(�Ǽ�)\n22:���ϱ⼼(�ŷ������ı⼼)\n  -2012.05.14 ����\n23:�������űݱ��ذ�\n  (�ŷ������� ����������)\n  -2012.05.14 ����\n24:�����̷а�(�ŷ������� ����������)\n25:�����������űݱ��ذ�\n  (�ŷ������� ����������)\n  -2012.05.14 ����
	double sett_theory_prc;	// �����̷а���, �ؿɼ��� ��� ���űݱ��ذ��� \n��) 999999999.999999
	double std_theory_prc;	// �����̷а���, ��) 999999999.999999
	double yest_sett_prc;	// �������갡��, ��) 999999999.99999999
	char halt_trd_clsf;	// �ŷ���������, Y, N
	double ft_cb_high_prc;	// ����Circuit_Breakers���Ѱ�, ���� CB �ߵ������� �Ǵ��ϱ� ���� ����\n����(���ذ���� +/-5%�� CB �ߵ�\n������ ��� +5%�� ����� ����)\n��) 99+F31499999999.99
	double ft_cb_low_prc;	// ����Circuit_Breakers���Ѱ�, ���� CB �ߵ������� �Ǵ��ϱ� ���� ����\n����(���ذ���� +/-5%�� CB �ߵ�\n������ ��� -5%�� ����� ����)\n��) 9999999999.99
	double check_exe_prc;	// ��ȸ����簡��, ��) 999999999.99999999
	char atm_clsf;	// ATM�����ڵ�, 0:����, 1:ATM, 2:ITM, 3:OTM
	char last_trading_clsf;	// �����ŷ��Ͽ���, Y, N
	double ex_divid_aft_value;	// �����Ĺ�簡ġ, �ֽ� �� �ְ����� ��ǰ���� �����\n- ���� : �����Ĺ̷���ġ\n- �ɼ� : ���������簡ġ\n��) 999999999.999999
	char yest_close_prc_sign;	// SIGN��ȣ
	double yest_close_prc;	// ��������, ��) 9999999999.99
	char yest_close_prc_clsf;	// �������������ڵ�, 1:�Ǽ�, 3:�ŷ���\n2:�⼼ -2012.05.14 ����
	char yest_init_prc_sign;	// SIGN��ȣ
	double yest_init_prc;	// ���Ͻð�, ��) 9999999999.99
	char yest_high_prc_sign;	// SIGN��ȣ
	double yest_high_pric;	// ���ϰ�, ��) 9999999999.99
	char yest_low_prc_sign;	// SIGN��ȣ
	double yest_low_prc;	// ��������, ��) 9999999999.99
	char yest_first_exe_date[9];	// ����ü������
	char yest_last_exe_time[9];	// ��������ü��ð�
	char yest_sett_prc_clsf[3];	// �������갡�ݱ���, *����\n 10:���갡����\n 11:��������(�Ǽ�)\n 12:���ϱ⼼(�ŷ������ı⼼) - 2010.12.20 ����\n 13:�������갡(�ŷ������� ����������) - 2010.12.20 ����\n 14:�����̷а�(�ŷ������� ����������)\n 15:��������� ���� - 2010.12.20 ����\n 16:������ ���� ���갡 - 2010.12.20 ����\n 17:����ڻ� ����(�̷а����� ��ǰ)\n 18:������ذ��� - 2010.12.20 �߰�
	char sett_prc_theory_prc_diff_pctg_sign;	// SIGN��ȣ
	double sett_prc_theory_prc_diff_pctg;	// ���갡���̷а��ݱ�����, ��) 999999.999999
	double yest_open_interest_q;	// ���Ϲ̰�����������
	char yest_s_limit_ord_prc_sign;	// SIGN��ȣ
	double yest_s_limit_ord_prc;	// ���ϸŵ��켱ȣ������, ��) 9999999999.99
	char yest_l_limit_ord_prc_sign;	// SIGN��ȣ
	double yest_l_limit_ord_prc;	// ���ϸż��켱ȣ������, ��) 9999999999.99
	double implied_vol;	// ���纯����, ��) 999999.9999
	char listed_high_prc_sign;	// SIGN��ȣ
	double listed_high_prc;	// �������ְ�, ��) 9999999999.99
	char listed_low_prc_sign;	// SIGN��ȣ
	double listed_low_prc;	// ������������, ��) 9999999999.99
	char year_high_prc_sign;	// SIGN��ȣ
	double year_high_prc;	// �����ְ�, ��) 9999999999.99
	char year_low_prc_sign;	// SIGN��ȣ
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
	double yest_block_trd_exe_q;	// �������Ǵ뷮�ջ�ü�����, �������Ǵ뷮�Ÿ�ü����� => �������Ǵ뷮�ջ�ü����� [����ü�����+�������Ǵ뷮�Ÿ�ü�����(���Ǵ뷮+FLEX)] 2016.03.28 ����
	double yest_block_trd_total_amt;	// �������Ǵ뷮�ջ�ŷ����, �������Ǵ뷮�ŸŰŷ���� => �������Ǵ뷮�ջ�ŷ���� [���ϰŷ����+�������Ǵ뷮�ŸŰŷ����(���Ǵ뷮+FLEX)] 2016.03.28 ����
	double cd_rate;	// CD�ݸ�, ��) 999.999
	double open_interest_q;	// �̰����ѵ�����, *�����Ͽ� ����Ǵ� ��ǰ�� ���º�\n �̰��� �ѵ� ����. �̰��� �ѵ���\n ������� ���� ��ǰ�� 0\n*�ֽļ������� �ش�\n8 => 15, 20140303
	char product_cat[5];	// �Ҽ� ��ǰ��, *�ֽļ���/�ɼǿ��� �ش�
	double product_cat_off_pctg;	// ��ǰ�� �ɼ���, *������� ǥ��\n*�ֽļ���/�ɼǿ��� �ش翹) 9999999.99\n5 => 9, 20140303
	int limit_ord_clsf_code;	// ������ȣ�����Ǳ����ڵ�, ȣ���� ü�� �� �ܷ�����. Bitwise ����\n--�ڵ尪--\n1: FAS (Fill And Store)\n2: FOK (Fill Or Kill)\n3: FAK (Fill And Kill)\n\n* ������ȣ�����Ǳ����ڵ� BITWISE ����\n���� Ȯ�强�� ���� �ش� 10�������� 2������ ��ȯ�Ͽ� ó�����(�ִ� 16bit���� ��밡��)\n�� ) ������ȣ�����Ǳ����ڵ� ���� 6�̸�\n    (������ 6 -> ������ 00000110)\n0��° bit 0 -> 0 : FAS\n1��° bit 1 -> 2 : FOK\n2��° bit 1 -> 4 : FAK\n��, FOK�̸鼭 FAK�� �����Ѵٴ� �ǹ� (FOK & FAK)\nX => 9, 1 => 5, 20140303
	int mrk_ord_clsf_code;	// ���尡ȣ�����Ǳ����ڵ�, * ��
	int cond_limit_ord_clsf_code;	// ���Ǻ�������ȣ�����Ǳ����ڵ�, * ��
	int best_limit_ord_clsf_code;	// ������������ȣ�����Ǳ����ڵ�, * ��
	char efp_clsf;	// EFP�ŷ���󿩺�, Y, N, ��ǰ������ �ش�
	char flex_clsf;	// FLEX�ŷ���󿩺�, Y, N, ��ǰ������ �ش�
	double yest_efp_exe_q;	// ����EFPü�����, ��ǰ������ �ش�
	double yest_efp_trd_amount;	// ����EFP�ŷ����, ��ǰ������ �ش�
	char mkr_close_clsf;	// ���忩��, ���忩�� (Y,N), 20121217
	char real_t_prc_limit_clsf;	// �ǽð��������ѿ���, ���� ü�ᰡ�� ��� Ư�� ������ �ʰ��ϴ� ȣ���� �ź��ϵ��� �������� ����(Y/N) 20140901
	double real_t_high_price_gap;	// �ǽð����Ѱ�����, ���� ü�ᰡ�ݰ� �ǽð����Ѱ����� ����\n�ǽð����Ѱ� = ����ü�ᰡ�� + �ǽð����Ѱ�����\nex) 9999999999.99  20140901
	double real_t_low_price_gap;	// �ǽð����Ѱ�����, ���� ü�ᰡ�ݰ� �ǽð����Ѱ����� ����\n�ǽð����Ѱ� = ����ü�ᰡ�� + �ǽð����Ѱ�����(����)\nex) 9999999999.99 20140901
	char under_ass_mrk_id[4];	// �����ڻ����ID, �����ڻ����ID�� �����ڻ��� KRX�� ����� ��쿡�� ä����.\nK200�����ɼ�:STK\n�ڽ���150����:KSQ\n�ֽļ����ɼ�:STK/KSQ\n��ǰ�����ɼ�:SPACE\n��������������:STK\n������������:STK\n�̴�K200�����ɼ�:STK
	double limit_ord_upper_limit_q;	// ���Ѽ���, ȣ�����Ѽ��� (20181210 �׸��߰�)
	double limit_ord_lower_limit_q;	// ���Ѽ���, ȣ�����Ѽ��� (20181210 �׸��߰�)
	double block_trd_ord_upper_limit_q;	// ���Ǵ뷮�ŸŻ��Ѽ���, ���Ǵ뷮�Ÿ�ȣ�����Ѽ��� (20181210 �׸��߰�)
	double block_trd_ord_lower_limit_q;	// ���Ǵ뷮�Ÿ����Ѽ���, ���Ǵ뷮�Ÿ�ȣ�����Ѽ��� (20181210 �׸��߰�)
} DF_STOCK_FUT_PRD_INFO_DATA;


// �ֽļ���_�������� ������
typedef struct _DF_STOCK_FUT_ADJ_INFO_DATA {
	char data_clsf[3];	// DATA����, H4
	char info_clsf[3];	// ��������, 01:�����ֽļ���
	char mrk_clsf;	// ���屸��, 5
	char trd_date[9];	// ��������
	char isin_clsf[13];	// �����ڵ�, ���� record '999999999999' set
	double adj_coef_denominator;	// ��������и�, ��) 999999999999.99999999
	double adj_coef_numerator;	// �����������, ��) 999999999999.99999999
	double bef_adj_unit_size;	// ������ �ŷ�����(���ũ��), ��) 999999999999.99999999
	double aft_adj_unit_size;	// ������ �ŷ�����(���ũ��), ��) 999999999999.99999999
	double bef_adj_exercise_prc;	// ������ ��簡��, ��) 999999999999.99999999
	double aft_adj_exercise_prc;	// ������ ��簡��, ��) 999999999999.99999999
	int aft_adj_open_interest_adj_coef;	// ������ �̰������� �������
} DF_STOCK_FUT_ADJ_INFO_DATA;


// �ֽļ���_Polling ������
typedef struct _DF_STOCK_FUT_POLLING_DATA {
	char data_clsf[3];	// DATA����, I2
	char info_clsf[3];	// ��������, 01:�����ֽļ���
	char mrk_cslf;	// ���屸��, 5
	char send_t[5];	// ���۽ð�, HHSS
	char main_backup_clsf[3];	// Main Backup����, space
} DF_STOCK_FUT_POLLING_DATA;


// �ֽļ���_SPACE
typedef struct _DF_STOCK_FUT_SPACE {
	char data_clsf[3];	// DATA����, G9
	char info_clsf[3];	// ��������, 01:�����ֽļ���
	char mrk_clsf;	// ���屸��, 5
} DF_STOCK_FUT_SPACE;
