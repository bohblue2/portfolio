// cb_stock_futures_tr.h
// �����ֽļ��� �ǽð� TR

#pragma once
// �ּ��� \n�� ���� ���߿� �̻ڰ� �ٲ����


// �ֽļ���_ü��
typedef struct _STOCK_FUT_EXEC {
	char data_clsf[2];	// DATA����, A3
	char info_clsf[2];	// ��������, 01:�����ֽļ���
	char mrk_clsf[1];	// ���屸��, 5
	char isin_clsf[12];	// �����ڵ�
	char stk_snr[4];	// �����Ϸù�ȣ
	char brd_id[2];	// ����ID, �ڵ尪��������
	char cur_prc_sign[1];	// ���簡�ݺ�ȣ
	char cur_prc[7];	// ���簡��
	char exe_q[6];	// ü�����
	char ss_id[2];	// ����ID, �ڵ尪��������
	char exe_t[8];	// ü��ð�
	char rct_prd_prc[7];	// �ֱٿ���������������
	char nxt_prd_prc[7];	// ������������������
	char init_prc_sign[1];	// �ð���ȣ
	char init_prc[7];	// �ð�
	char high_prc_sign[1];	// ����ȣ
	char high_prc[7];	// ��
	char low_prc_sign[1];	// ������ȣ
	char low_prc[7];	// ����
	char pri_prc_sign[1];	// �������ݺ�ȣ
	char pri_prc[7];	// ��������
	char accm_exe_q[7];	// ����ü�����
	char accm_trd_amt[15];	// �����ŷ����, ����:��
	char l_or_s[1];	// �����ŵ��ż������ڵ�, 1:�ŵ�,2:�ż�(�������� ���� ȣ���� �ŵ��ż����а�)
	char real_t_high_prc_sign[1];	// �ǽð����Ѱ���ȣ
	char real_t_high_prc[7];	// �ǽð����Ѱ�, ���߰��̵�����
	char real_t_low_prc_sign[1];	// �ǽð����Ѱ���ȣ
	char real_t_low_prc[7];	// �ǽð����Ѱ�, ���߰��̵�����
	char ff[1];	// End of Text, (0xFF)
} STOCK_FUT_EXEC;


// �ֽļ���_�켱ȣ��
typedef struct _STOCK_FUT_LIMIT_ORD {
	char data_clsf[2];	// DATA����, B6
	char info_clsf[2];	// ��������, 01:�����ֽļ���
	char mrk_clsf[1];	// ���屸��, 5
	char isin_clsf[12];	// �����ڵ�
	char stk_snr[4];	// �����Ϸù�ȣ
	char brd_id[2];	// ����ID, �ڵ尪��������
	char ss_id[2];	// ����ID, �ڵ尪��������
	char total_l_limit_ord_q[8];	// �ż���ȣ���ܷ�, �ڸ��� ����(7->8)
	char l_lvl_1_sign[1];	// �ż�1�ܰ��ȣ
	char l_lvl_1_prc[7];	// �ż�1�ܰ�켱ȣ������
	char l_lvl_1_q[7];	// �ż�1�ܰ�켱ȣ���ܷ�, �ڸ��� ����(6->7)
	char l_lvl_2_sign[1];	// �ż�2�ܰ��ȣ
	char l_lvl_2_prc[7];	// �ż�2�ܰ�켱ȣ������
	char l_lvl_2_q[7];	// �ż�2�ܰ�켱ȣ���ܷ�, �ڸ��� ����(6->7)
	char l_lvl_3_sign[1];	// �ż�3�ܰ��ȣ
	char l_lvl_3_prc[7];	// �ż�3�ܰ�켱ȣ������
	char l_lvl_3_q[7];	// �ż�3�ܰ�켱ȣ���ܷ�, �ڸ��� ����(6->7)
	char l_lvl_4_sign[1];	// �ż�4�ܰ��ȣ
	char l_lvl_4_prc[7];	// �ż�4�ܰ�켱ȣ������
	char l_lvl_4_q[7];	// �ż�4�ܰ�켱ȣ���ܷ�, �ڸ��� ����(6->7)
	char l_lvl_5_sign[1];	// �ż�5�ܰ��ȣ
	char l_lvl_5_prc[7];	// �ż�5�ܰ�켱ȣ������
	char l_lvl_5_q[7];	// �ż�5�ܰ�켱ȣ���ܷ�, �ڸ��� ����(6->7)
	char l_lvl_6_sign[1];	// �ż�6�ܰ��ȣ
	char l_lvl_6_prc[7];	// �ż�6�ܰ�켱ȣ������
	char l_lvl_6_q[7];	// �ż�6�ܰ�켱ȣ���ܷ�, �ڸ��� ����(6->7)
	char l_lvl_7_sign[1];	// �ż�7�ܰ��ȣ
	char l_lvl_7_prc[7];	// �ż�7�ܰ�켱ȣ������
	char l_lvl_7_q[7];	// �ż�7�ܰ�켱ȣ���ܷ�, �ڸ��� ����(6->7)
	char l_lvl_8_sign[1];	// �ż�8�ܰ��ȣ
	char l_lvl_8_prc[7];	// �ż�8�ܰ�켱ȣ������
	char l_lvl_8_q[7];	// �ż�8�ܰ�켱ȣ���ܷ�, �ڸ��� ����(6->7)
	char l_lvl_9_sign[1];	// �ż�9�ܰ��ȣ
	char l_lvl_9_prc[7];	// �ż�9�ܰ�켱ȣ������
	char l_lvl_9_q[7];	// �ż�9�ܰ�켱ȣ���ܷ�, �ڸ��� ����(6->7)
	char l_lvl_10_sign[1];	// �ż�10�ܰ��ȣ
	char l_lvl_10_prc[7];	// �ż�10�ܰ�켱ȣ������
	char l_lvl_10_q[7];	// �ż�10�ܰ�켱ȣ���ܷ�, �ڸ��� ����(6->7)
	char total_s_limit_ord_q[8];	// �ŵ���ȣ���ܷ�, �ڸ��� ����(7->8)
	char s_lvl_1_sign[1];	// �ŵ�1�ܰ��ȣ
	char s_lvl_1_prc[7];	// �ŵ�1�ܰ�켱ȣ������
	char s_lvl_1_q[7];	// �ŵ�1�ܰ�켱ȣ���ܷ�, �ڸ��� ����(6->7)
	char s_lvl_2_sign[1];	// �ŵ�2�ܰ��ȣ
	char s_lvl_2_prc[7];	// �ŵ�2�ܰ�켱ȣ������
	char s_lvl_2_q[7];	// �ŵ�2�ܰ�켱ȣ���ܷ�, �ڸ��� ����(6->7)
	char s_lvl_3_sign[1];	// �ŵ�3�ܰ��ȣ
	char s_lvl_3_prc[7];	// �ŵ�3�ܰ�켱ȣ������
	char s_lvl_3_q[7];	// �ŵ�3�ܰ�켱ȣ���ܷ�, �ڸ��� ����(6->7)
	char s_lvl_4_sign[1];	// �ŵ�4�ܰ��ȣ
	char s_lvl_4_prc[7];	// �ŵ�4�ܰ�켱ȣ������
	char s_lvl_4_q[7];	// �ŵ�4�ܰ�켱ȣ���ܷ�, �ڸ��� ����(6->7)
	char s_lvl_5_sign[1];	// �ŵ�5�ܰ��ȣ
	char s_lvl_5_prc[7];	// �ŵ�5�ܰ�켱ȣ������
	char s_lvl_5_q[7];	// �ŵ�5�ܰ�켱ȣ���ܷ�, �ڸ��� ����(6->7)
	char s_lvl_6_sign[1];	// �ŵ�6�ܰ��ȣ
	char s_lvl_6_prc[7];	// �ŵ�6�ܰ�켱ȣ������
	char s_lvl_6_q[7];	// �ŵ�6�ܰ�켱ȣ���ܷ�, �ڸ��� ����(6->7)
	char s_lvl_7_sign[1];	// �ŵ�7�ܰ��ȣ
	char s_lvl_7_prc[7];	// �ŵ�7�ܰ�켱ȣ������
	char s_lvl_7_q[7];	// �ŵ�7�ܰ�켱ȣ���ܷ�, �ڸ��� ����(6->7)
	char s_lvl_8_sign[1];	// �ŵ�8�ܰ��ȣ
	char s_lvl_8_prc[7];	// �ŵ�8�ܰ�켱ȣ������
	char s_lvl_8_q[7];	// �ŵ�8�ܰ�켱ȣ���ܷ�, �ڸ��� ����(6->7)
	char s_lvl_9_sign[1];	// �ŵ�9�ܰ��ȣ
	char s_lvl_9_prc[7];	// �ŵ�9�ܰ�켱ȣ������
	char s_lvl_9_q[7];	// �ŵ�9�ܰ�켱ȣ���ܷ�, �ڸ��� ����(6->7)
	char s_lvl_10_sign[1];	// �ŵ�10�ܰ��ȣ
	char s_lvl_10_prc[7];	// �ŵ�10�ܰ�켱ȣ������
	char s_lvl_10_q[7];	// �ŵ�10�ܰ�켱ȣ���ܷ�, �ڸ��� ����(6->7)
	char total_l_trd_cnt[5];	// �ż���ȿȣ���Ǽ�
	char l_lvl_1_trd_cnt[4];	// �ż�1�ܰ�켱ȣ���Ǽ�
	char l_lvl_2_trd_cnt[4];	// �ż�2�ܰ�켱ȣ���Ǽ�
	char l_lvl_3_trd_cnt[4];	// �ż�3�ܰ�켱ȣ���Ǽ�
	char l_lvl_4_trd_cnt[4];	// �ż�4�ܰ�켱ȣ���Ǽ�
	char l_lvl_5_trd_cnt[4];	// �ż�5�ܰ�켱ȣ���Ǽ�
	char l_lvl_6_trd_cnt[4];	// �ż�6�ܰ�켱ȣ���Ǽ�
	char l_lvl_7_trd_cnt[4];	// �ż�7�ܰ�켱ȣ���Ǽ�
	char l_lvl_8_trd_cnt[4];	// �ż�8�ܰ�켱ȣ���Ǽ�
	char l_lvl_9_trd_cnt[4];	// �ż�9�ܰ�켱ȣ���Ǽ�
	char l_lvl_10_trd_cnt[4];	// �ż�10�ܰ�켱ȣ���Ǽ�
	char total_s_trd_cnt[5];	// �ŵ���ȿȣ���Ǽ�
	char s_lvl_1_trd_cnt[4];	// �ŵ�1�ܰ�켱ȣ���Ǽ�
	char s_lvl_2_trd_cnt[4];	// �ŵ�2�ܰ�켱ȣ���Ǽ�
	char s_lvl_3_trd_cnt[4];	// �ŵ�3�ܰ�켱ȣ���Ǽ�
	char s_lvl_4_trd_cnt[4];	// �ŵ�4�ܰ�켱ȣ���Ǽ�
	char s_lvl_5_trd_cnt[4];	// �ŵ�5�ܰ�켱ȣ���Ǽ�
	char s_lvl_6_trd_cnt[4];	// �ŵ�6�ܰ�켱ȣ���Ǽ�
	char s_lvl_7_trd_cnt[4];	// �ŵ�7�ܰ�켱ȣ���Ǽ�
	char s_lvl_8_trd_cnt[4];	// �ŵ�8�ܰ�켱ȣ���Ǽ�
	char s_lvl_9_trd_cnt[4];	// �ŵ�9�ܰ�켱ȣ���Ǽ�
	char s_lvl_10_trd_cnt[4];	// �ŵ�10�ܰ�켱ȣ���Ǽ�
	char ord_rcv_t[8];	// ȣ�������ð�
	char exp_prc_sign[1];	// ����ü�ᰡ�ݺ�ȣ, ���ϰ��ŸŽø� ����\n (����±����ڵ�:10,20,30,80)
	char exp_prc[7];	// ����ü�ᰡ��, ���ϰ��ŸŽø� ����\n (����±����ڵ�:10,20,30,80)
	char ff[1];	// End of Text, (0xFF)
} STOCK_FUT_LIMIT_ORD;


// �ֽļ���_ü��_�켱ȣ��
typedef struct _STOCK_FUT_EXEC_LIMIT_ORD {
	char data_clsf[2];	// DATA����, G7
	char info_clsf[2];	// ��������, 01:�����ֽļ���
	char mrk_clsf[1];	// ���屸��, 5
	char isin_clsf[12];	// �����ڵ�
	char stk_snr[4];	// �����Ϸù�ȣ
	char brd_id[2];	// ����ID, �ڵ尪��������
	char cur_prc_sign[1];	// ���簡�ݺ�ȣ
	char cur_prc[7];	// ���簡��
	char exe_q[6];	// ü�����
	char ss_id[2];	// ����ID, �ڵ尪��������
	char exe_t[8];	// ü��ð�
	char rct_prd_prc[7];	// �ֱٿ���������������
	char nxt_prd_prc[7];	// ������������������
	char init_prc_sign[1];	// �ð���ȣ
	char init_prc[7];	// �ð�
	char high_prc_sign[1];	// ����ȣ
	char high_prc[7];	// ��
	char low_prc_sign[1];	// ������ȣ
	char low_prc[7];	// ����
	char pri_prc_sign[1];	// �������ݺ�ȣ
	char pri_prc[7];	// ��������
	char accm_exe_q[7];	// ����ü�����
	char accm_trd_amt[15];	// �����ŷ����, ����:��
	char l_or_s[1];	// �����ŵ��ż������ڵ�, 1:�ŵ�,2:�ż�(�������� ���� ȣ���� �ŵ��ż����а�)
	char total_l_limit_ord_q[8];	// �ż���ȣ���ܷ�, �ڸ��� ����(7->8)
	char l_lvl_1_sign[1];	// �ż�1�ܰ��ȣ
	char l_lvl_1_prc[7];	// �ż�1�ܰ�켱ȣ������
	char l_lvl_1_q[7];	// �ż�1�ܰ�켱ȣ���ܷ�, �ڸ��� ����(6->7)
	char l_lvl_2_sign[1];	// �ż�2�ܰ��ȣ
	char l_lvl_2_prc[7];	// �ż�2�ܰ�켱ȣ������
	char l_lvl_2_q[7];	// �ż�2�ܰ�켱ȣ���ܷ�, �ڸ��� ����(6->7)
	char l_lvl_3_sign[1];	// �ż�3�ܰ��ȣ
	char l_lvl_3_prc[7];	// �ż�3�ܰ�켱ȣ������
	char l_lvl_3_q[7];	// �ż�3�ܰ�켱ȣ���ܷ�, �ڸ��� ����(6->7)
	char l_lvl_4_sign[1];	// �ż�4�ܰ��ȣ
	char l_lvl_4_prc[7];	// �ż�4�ܰ�켱ȣ������
	char l_lvl_4_q[7];	// �ż�4�ܰ�켱ȣ���ܷ�, �ڸ��� ����(6->7)
	char l_lvl_5_sign[1];	// �ż�5�ܰ��ȣ
	char l_lvl_5_prc[7];	// �ż�5�ܰ�켱ȣ������
	char l_lvl_5_q[7];	// �ż�5�ܰ�켱ȣ���ܷ�, �ڸ��� ����(6->7)
	char l_lvl_6_sign[1];	// �ż�6�ܰ��ȣ
	char l_lvl_6_prc[7];	// �ż�6�ܰ�켱ȣ������
	char l_lvl_6_q[7];	// �ż�6�ܰ�켱ȣ���ܷ�, �ڸ��� ����(6->7)
	char l_lvl_7_sign[1];	// �ż�7�ܰ��ȣ
	char l_lvl_7_prc[7];	// �ż�7�ܰ�켱ȣ������
	char l_lvl_7_q[7];	// �ż�7�ܰ�켱ȣ���ܷ�, �ڸ��� ����(6->7)
	char l_lvl_8_sign[1];	// �ż�8�ܰ��ȣ
	char l_lvl_8_prc[7];	// �ż�8�ܰ�켱ȣ������
	char l_lvl_8_q[7];	// �ż�8�ܰ�켱ȣ���ܷ�, �ڸ��� ����(6->7)
	char l_lvl_9_sign[1];	// �ż�9�ܰ��ȣ
	char l_lvl_9_prc[7];	// �ż�9�ܰ�켱ȣ������
	char l_lvl_9_q[7];	// �ż�9�ܰ�켱ȣ���ܷ�, �ڸ��� ����(6->7)
	char l_lvl_10_sign[1];	// �ż�10�ܰ��ȣ
	char l_lvl_10_prc[7];	// �ż�10�ܰ�켱ȣ������
	char l_lvl_10_q[7];	// �ż�10�ܰ�켱ȣ���ܷ�, �ڸ��� ����(6->7)
	char total_s_limit_ord_q[8];	// �ŵ���ȣ���ܷ�, �ڸ��� ����(7->8)
	char s_lvl_1_sign[1];	// �ŵ�1�ܰ��ȣ
	char s_lvl_1_prc[7];	// �ŵ�1�ܰ�켱ȣ������
	char s_lvl_1_q[7];	// �ŵ�1�ܰ�켱ȣ���ܷ�, �ڸ��� ����(6->7)
	char s_lvl_2_sign[1];	// �ŵ�2�ܰ��ȣ
	char s_lvl_2_prc[7];	// �ŵ�2�ܰ�켱ȣ������
	char s_lvl_2_q[7];	// �ŵ�2�ܰ�켱ȣ���ܷ�, �ڸ��� ����(6->7)
	char s_lvl_3_sign[1];	// �ŵ�3�ܰ��ȣ
	char s_lvl_3_prc[7];	// �ŵ�3�ܰ�켱ȣ������
	char s_lvl_3_q[7];	// �ŵ�3�ܰ�켱ȣ���ܷ�, �ڸ��� ����(6->7)
	char s_lvl_4_sign[1];	// �ŵ�4�ܰ��ȣ
	char s_lvl_4_prc[7];	// �ŵ�4�ܰ�켱ȣ������
	char s_lvl_4_q[7];	// �ŵ�4�ܰ�켱ȣ���ܷ�, �ڸ��� ����(6->7)
	char s_lvl_5_sign[1];	// �ŵ�5�ܰ��ȣ
	char s_lvl_5_prc[7];	// �ŵ�5�ܰ�켱ȣ������
	char s_lvl_5_q[7];	// �ŵ�5�ܰ�켱ȣ���ܷ�, �ڸ��� ����(6->7)
	char s_lvl_6_sign[1];	// �ŵ�6�ܰ��ȣ
	char s_lvl_6_prc[7];	// �ŵ�6�ܰ�켱ȣ������
	char s_lvl_6_q[7];	// �ŵ�6�ܰ�켱ȣ���ܷ�, �ڸ��� ����(6->7)
	char s_lvl_7_sign[1];	// �ŵ�7�ܰ��ȣ
	char s_lvl_7_prc[7];	// �ŵ�7�ܰ�켱ȣ������
	char s_lvl_7_q[7];	// �ŵ�7�ܰ�켱ȣ���ܷ�, �ڸ��� ����(6->7)
	char s_lvl_8_sign[1];	// �ŵ�8�ܰ��ȣ
	char s_lvl_8_prc[7];	// �ŵ�8�ܰ�켱ȣ������
	char s_lvl_8_q[7];	// �ŵ�8�ܰ�켱ȣ���ܷ�, �ڸ��� ����(6->7)
	char s_lvl_9_sign[1];	// �ŵ�9�ܰ��ȣ
	char s_lvl_9_prc[7];	// �ŵ�9�ܰ�켱ȣ������
	char s_lvl_9_q[7];	// �ŵ�9�ܰ�켱ȣ���ܷ�, �ڸ��� ����(6->7)
	char s_lvl_10_sign[1];	// �ŵ�10�ܰ��ȣ
	char s_lvl_10_prc[7];	// �ŵ�10�ܰ�켱ȣ������
	char s_lvl_10_q[7];	// �ŵ�10�ܰ�켱ȣ���ܷ�, �ڸ��� ����(6->7)
	char total_l_trd_cnt[5];	// �ż���ȿȣ���Ǽ�
	char l_lvl_1_trd_cnt[4];	// �ż�1�ܰ�켱ȣ���Ǽ�
	char l_lvl_2_trd_cnt[4];	// �ż�2�ܰ�켱ȣ���Ǽ�
	char l_lvl_3_trd_cnt[4];	// �ż�3�ܰ�켱ȣ���Ǽ�
	char l_lvl_4_trd_cnt[4];	// �ż�4�ܰ�켱ȣ���Ǽ�
	char l_lvl_5_trd_cnt[4];	// �ż�5�ܰ�켱ȣ���Ǽ�
	char l_lvl_6_trd_cnt[4];	// �ż�6�ܰ�켱ȣ���Ǽ�
	char l_lvl_7_trd_cnt[4];	// �ż�7�ܰ�켱ȣ���Ǽ�
	char l_lvl_8_trd_cnt[4];	// �ż�8�ܰ�켱ȣ���Ǽ�
	char l_lvl_9_trd_cnt[4];	// �ż�9�ܰ�켱ȣ���Ǽ�
	char l_lvl_10_trd_cnt[4];	// �ż�10�ܰ�켱ȣ���Ǽ�
	char total_s_trd_cnt[5];	// �ŵ���ȿȣ���Ǽ�
	char s_lvl_1_trd_cnt[4];	// �ŵ�1�ܰ�켱ȣ���Ǽ�
	char s_lvl_2_trd_cnt[4];	// �ŵ�2�ܰ�켱ȣ���Ǽ�
	char s_lvl_3_trd_cnt[4];	// �ŵ�3�ܰ�켱ȣ���Ǽ�
	char s_lvl_4_trd_cnt[4];	// �ŵ�4�ܰ�켱ȣ���Ǽ�
	char s_lvl_5_trd_cnt[4];	// �ŵ�5�ܰ�켱ȣ���Ǽ�
	char s_lvl_6_trd_cnt[4];	// �ŵ�6�ܰ�켱ȣ���Ǽ�
	char s_lvl_7_trd_cnt[4];	// �ŵ�7�ܰ�켱ȣ���Ǽ�
	char s_lvl_8_trd_cnt[4];	// �ŵ�8�ܰ�켱ȣ���Ǽ�
	char s_lvl_9_trd_cnt[4];	// �ŵ�9�ܰ�켱ȣ���Ǽ�
	char s_lvl_10_trd_cnt[4];	// �ŵ�10�ܰ�켱ȣ���Ǽ�
	char real_t_high_prc_sign[1];	// �ǽð����Ѱ���ȣ
	char real_t_high_prc[7];	// �ǽð����Ѱ�, ���߰��̵�����
	char real_t_low_prc_sign[1];	// �ǽð����Ѱ���ȣ
	char real_t_low_prc[7];	// �ǽð����Ѱ�, ���߰��̵�����
	char ff[1];	// End of Text, (0xFF)
} STOCK_FUT_EXEC_LIMIT_ORD;


// �ֽļ���_���񸶰�
typedef struct _STOCK_FUT_CLOSE_PRODUCT {
	char data_clsf[2];	// DATA����, A6
	char info_clsf[2];	// ��������, 01:�����ֽļ���
	char mrk_clsf[1];	// ���屸��, 5
	char isin_clsf[12];	// �����ڵ�
	char stk_snr[4];	// �����Ϸù�ȣ
	char brd_id[2];	// ����ID, �ڵ尪��������
	char close_prc_sign[1];	// ������ȣ
	char close_prc[7];	// ����, * �ŷ��� ������ ��� ���ذ� set
	char close_prc_code[1];	// ���������ڵ�, 1:�Ǽ�, 3:�ŷ���\n 2:�⼼ -2012.05.14 ����\n ' ':�������� �ƴ� ��� space
	char accm_exe_q[7];	// ����ü�����
	char accm_trd_amt[15];	// �����ŷ����, ����:��
	char total_l_limit_ord_q[8];	// �ż���ȣ���ܷ�, �ڸ��� ����(7->8)
	char l_lvl_1_sign[1];	// �ż�1�ܰ��ȣ
	char l_lvl_1_prc[7];	// �ż�1�ܰ�켱ȣ������
	char l_lvl_1_q[7];	// �ż�1�ܰ�켱ȣ���ܷ�, �ڸ��� ����(6->7)
	char l_lvl_2_sign[1];	// �ż�2�ܰ��ȣ
	char l_lvl_2_prc[7];	// �ż�2�ܰ�켱ȣ������
	char l_lvl_2_q[7];	// �ż�2�ܰ�켱ȣ���ܷ�, �ڸ��� ����(6->7)
	char l_lvl_3_sign[1];	// �ż�3�ܰ��ȣ
	char l_lvl_3_prc[7];	// �ż�3�ܰ�켱ȣ������
	char l_lvl_3_q[7];	// �ż�3�ܰ�켱ȣ���ܷ�, �ڸ��� ����(6->7)
	char l_lvl_4_sign[1];	// �ż�4�ܰ��ȣ
	char l_lvl_4_prc[7];	// �ż�4�ܰ�켱ȣ������
	char l_lvl_4_q[7];	// �ż�4�ܰ�켱ȣ���ܷ�, �ڸ��� ����(6->7)
	char l_lvl_5_sign[1];	// �ż�5�ܰ��ȣ
	char l_lvl_5_prc[7];	// �ż�5�ܰ�켱ȣ������
	char l_lvl_5_q[7];	// �ż�5�ܰ�켱ȣ���ܷ�, �ڸ��� ����(6->7)
	char l_lvl_6_sign[1];	// �ż�6�ܰ��ȣ
	char l_lvl_6_prc[7];	// �ż�6�ܰ�켱ȣ������
	char l_lvl_6_q[7];	// �ż�6�ܰ�켱ȣ���ܷ�, �ڸ��� ����(6->7)
	char l_lvl_7_sign[1];	// �ż�7�ܰ��ȣ
	char l_lvl_7_prc[7];	// �ż�7�ܰ�켱ȣ������
	char l_lvl_7_q[7];	// �ż�7�ܰ�켱ȣ���ܷ�, �ڸ��� ����(6->7)
	char l_lvl_8_sign[1];	// �ż�8�ܰ��ȣ
	char l_lvl_8_prc[7];	// �ż�8�ܰ�켱ȣ������
	char l_lvl_8_q[7];	// �ż�8�ܰ�켱ȣ���ܷ�, �ڸ��� ����(6->7)
	char l_lvl_9_sign[1];	// �ż�9�ܰ��ȣ
	char l_lvl_9_prc[7];	// �ż�9�ܰ�켱ȣ������
	char l_lvl_9_q[7];	// �ż�9�ܰ�켱ȣ���ܷ�, �ڸ��� ����(6->7)
	char l_lvl_10_sign[1];	// �ż�10�ܰ��ȣ
	char l_lvl_10_prc[7];	// �ż�10�ܰ�켱ȣ������
	char l_lvl_10_q[7];	// �ż�10�ܰ�켱ȣ���ܷ�, �ڸ��� ����(6->7)
	char total_s_limit_ord_q[8];	// �ŵ���ȣ���ܷ�, �ڸ��� ����(7->8)
	char s_lvl_1_sign[1];	// �ŵ�1�ܰ��ȣ
	char s_lvl_1_prc[7];	// �ŵ�1�ܰ�켱ȣ������
	char s_lvl_1_q[7];	// �ŵ�1�ܰ�켱ȣ���ܷ�, �ڸ��� ����(6->7)
	char s_lvl_2_sign[1];	// �ŵ�2�ܰ��ȣ
	char s_lvl_2_prc[7];	// �ŵ�2�ܰ�켱ȣ������
	char s_lvl_2_q[7];	// �ŵ�2�ܰ�켱ȣ���ܷ�, �ڸ��� ����(6->7)
	char s_lvl_3_sign[1];	// �ŵ�3�ܰ��ȣ
	char s_lvl_3_prc[7];	// �ŵ�3�ܰ�켱ȣ������
	char s_lvl_3_q[7];	// �ŵ�3�ܰ�켱ȣ���ܷ�, �ڸ��� ����(6->7)
	char s_lvl_4_sign[1];	// �ŵ�4�ܰ��ȣ
	char s_lvl_4_prc[7];	// �ŵ�4�ܰ�켱ȣ������
	char s_lvl_4_q[7];	// �ŵ�4�ܰ�켱ȣ���ܷ�, �ڸ��� ����(6->7)
	char s_lvl_5_sign[1];	// �ŵ�5�ܰ��ȣ
	char s_lvl_5_prc[7];	// �ŵ�5�ܰ�켱ȣ������
	char s_lvl_5_q[7];	// �ŵ�5�ܰ�켱ȣ���ܷ�, �ڸ��� ����(6->7)
	char s_lvl_6_sign[1];	// �ŵ�6�ܰ��ȣ
	char s_lvl_6_prc[7];	// �ŵ�6�ܰ�켱ȣ������
	char s_lvl_6_q[7];	// �ŵ�6�ܰ�켱ȣ���ܷ�, �ڸ��� ����(6->7)
	char s_lvl_7_sign[1];	// �ŵ�7�ܰ��ȣ
	char s_lvl_7_prc[7];	// �ŵ�7�ܰ�켱ȣ������
	char s_lvl_7_q[7];	// �ŵ�7�ܰ�켱ȣ���ܷ�, �ڸ��� ����(6->7)
	char s_lvl_8_sign[1];	// �ŵ�8�ܰ��ȣ
	char s_lvl_8_prc[7];	// �ŵ�8�ܰ�켱ȣ������
	char s_lvl_8_q[7];	// �ŵ�8�ܰ�켱ȣ���ܷ�, �ڸ��� ����(6->7)
	char s_lvl_9_sign[1];	// �ŵ�9�ܰ��ȣ
	char s_lvl_9_prc[7];	// �ŵ�9�ܰ�켱ȣ������
	char s_lvl_9_q[7];	// �ŵ�9�ܰ�켱ȣ���ܷ�, �ڸ��� ����(6->7)
	char s_lvl_10_sign[1];	// �ŵ�10�ܰ��ȣ
	char s_lvl_10_prc[7];	// �ŵ�10�ܰ�켱ȣ������
	char s_lvl_10_q[7];	// �ŵ�10�ܰ�켱ȣ���ܷ�, �ڸ��� ����(6->7)
	char total_l_trd_cnt[5];	// �ż���ȿȣ���Ǽ�
	char l_lvl_1_trd_cnt[4];	// �ż�1�ܰ�켱ȣ���Ǽ�
	char l_lvl_2_trd_cnt[4];	// �ż�2�ܰ�켱ȣ���Ǽ�
	char l_lvl_3_trd_cnt[4];	// �ż�3�ܰ�켱ȣ���Ǽ�
	char l_lvl_4_trd_cnt[4];	// �ż�4�ܰ�켱ȣ���Ǽ�
	char l_lvl_5_trd_cnt[4];	// �ż�5�ܰ�켱ȣ���Ǽ�
	char l_lvl_6_trd_cnt[4];	// �ż�6�ܰ�켱ȣ���Ǽ�
	char l_lvl_7_trd_cnt[4];	// �ż�7�ܰ�켱ȣ���Ǽ�
	char l_lvl_8_trd_cnt[4];	// �ż�8�ܰ�켱ȣ���Ǽ�
	char l_lvl_9_trd_cnt[4];	// �ż�9�ܰ�켱ȣ���Ǽ�
	char l_lvl_10_trd_cnt[4];	// �ż�10�ܰ�켱ȣ���Ǽ�
	char total_s_trd_cnt[5];	// �ŵ���ȿȣ���Ǽ�
	char s_lvl_1_trd_cnt[4];	// �ŵ�1�ܰ�켱ȣ���Ǽ�
	char s_lvl_2_trd_cnt[4];	// �ŵ�2�ܰ�켱ȣ���Ǽ�
	char s_lvl_3_trd_cnt[4];	// �ŵ�3�ܰ�켱ȣ���Ǽ�
	char s_lvl_4_trd_cnt[4];	// �ŵ�4�ܰ�켱ȣ���Ǽ�
	char s_lvl_5_trd_cnt[4];	// �ŵ�5�ܰ�켱ȣ���Ǽ�
	char s_lvl_6_trd_cnt[4];	// �ŵ�6�ܰ�켱ȣ���Ǽ�
	char s_lvl_7_trd_cnt[4];	// �ŵ�7�ܰ�켱ȣ���Ǽ�
	char s_lvl_8_trd_cnt[4];	// �ŵ�8�ܰ�켱ȣ���Ǽ�
	char s_lvl_9_trd_cnt[4];	// �ŵ�9�ܰ�켱ȣ���Ǽ�
	char s_lvl_10_trd_cnt[4];	// �ŵ�10�ܰ�켱ȣ���Ǽ�
	char ff[1];	// End of Text, (0xFF)
} STOCK_FUT_CLOSE_PRODUCT;


// �ֽļ���_��TS
typedef struct _STOCK_FUTURE_MRK_OP_TS {
	char data_clsf[2];	// DATA����, A7
	char info_clsf[2];	// ��������, 01:�����ֽļ���
	char mrk_clsf[1];	// ���屸��, 5
	char isin_clsf[12];	// �����ڵ�
	char stk_snr[4];	// �����Ϸù�ȣ
	char prd_id[11];	// ��ǰID, �ڵ尪�������� - spaceó��
	char brd_id[2];	// ����ID, �ڵ尪��������
	char brd_event_id[3];	// �����̺�ƮID, �ڵ尪��������
	char brd_event_start_t[8];	// �����̺�Ʈ���۽ð�, ������ �����(��:BB1(�ŸŰŷ�����)�� ��� 09000000)
	char brd_event_code[5];	// �����̺�Ʈ���뱺�ڵ�, �ڵ尪��������
	char ss_id[2];	// ����ID, �ڵ尪��������
	char ord_exist[1];	// ȣ������, 0:ȣ������(�����׸� ����), 1:ȣ������(�����׸� ���)
	char total_l_limit_ord_q[8];	// �ż���ȣ���ܷ�, �ڸ��� ����(7->8)
	char l_lvl_1_sign[1];	// �ż�1�ܰ��ȣ
	char l_lvl_1_prc[7];	// �ż�1�ܰ�켱ȣ������
	char l_lvl_1_q[7];	// �ż�1�ܰ�켱ȣ���ܷ�, �ڸ��� ����(6->7)
	char l_lvl_2_sign[1];	// �ż�2�ܰ��ȣ
	char l_lvl_2_prc[7];	// �ż�2�ܰ�켱ȣ������
	char l_lvl_2_q[7];	// �ż�2�ܰ�켱ȣ���ܷ�, �ڸ��� ����(6->7)
	char l_lvl_3_sign[1];	// �ż�3�ܰ��ȣ
	char l_lvl_3_prc[7];	// �ż�3�ܰ�켱ȣ������
	char l_lvl_3_q[7];	// �ż�3�ܰ�켱ȣ���ܷ�, �ڸ��� ����(6->7)
	char l_lvl_4_sign[1];	// �ż�4�ܰ��ȣ
	char l_lvl_4_prc[7];	// �ż�4�ܰ�켱ȣ������
	char l_lvl_4_q[7];	// �ż�4�ܰ�켱ȣ���ܷ�, �ڸ��� ����(6->7)
	char l_lvl_5_sign[1];	// �ż�5�ܰ��ȣ
	char l_lvl_5_prc[7];	// �ż�5�ܰ�켱ȣ������
	char l_lvl_5_q[7];	// �ż�5�ܰ�켱ȣ���ܷ�, �ڸ��� ����(6->7)
	char l_lvl_6_sign[1];	// �ż�6�ܰ��ȣ
	char l_lvl_6_prc[7];	// �ż�6�ܰ�켱ȣ������
	char l_lvl_6_q[7];	// �ż�6�ܰ�켱ȣ���ܷ�, �ڸ��� ����(6->7)
	char l_lvl_7_sign[1];	// �ż�7�ܰ��ȣ
	char l_lvl_7_prc[7];	// �ż�7�ܰ�켱ȣ������
	char l_lvl_7_q[7];	// �ż�7�ܰ�켱ȣ���ܷ�, �ڸ��� ����(6->7)
	char l_lvl_8_sign[1];	// �ż�8�ܰ��ȣ
	char l_lvl_8_prc[7];	// �ż�8�ܰ�켱ȣ������
	char l_lvl_8_q[7];	// �ż�8�ܰ�켱ȣ���ܷ�, �ڸ��� ����(6->7)
	char l_lvl_9_sign[1];	// �ż�9�ܰ��ȣ
	char l_lvl_9_prc[7];	// �ż�9�ܰ�켱ȣ������
	char l_lvl_9_q[7];	// �ż�9�ܰ�켱ȣ���ܷ�, �ڸ��� ����(6->7)
	char l_lvl_10_sign[1];	// �ż�10�ܰ��ȣ
	char l_lvl_10_prc[7];	// �ż�10�ܰ�켱ȣ������
	char l_lvl_10_q[7];	// �ż�10�ܰ�켱ȣ���ܷ�, �ڸ��� ����(6->7)
	char total_s_limit_ord_q[8];	// �ŵ���ȣ���ܷ�, �ڸ��� ����(7->8)
	char s_lvl_1_sign[1];	// �ŵ�1�ܰ��ȣ
	char s_lvl_1_prc[7];	// �ŵ�1�ܰ�켱ȣ������
	char s_lvl_1_q[7];	// �ŵ�1�ܰ�켱ȣ���ܷ�, �ڸ��� ����(6->7)
	char s_lvl_2_sign[1];	// �ŵ�2�ܰ��ȣ
	char s_lvl_2_prc[7];	// �ŵ�2�ܰ�켱ȣ������
	char s_lvl_2_q[7];	// �ŵ�2�ܰ�켱ȣ���ܷ�, �ڸ��� ����(6->7)
	char s_lvl_3_sign[1];	// �ŵ�3�ܰ��ȣ
	char s_lvl_3_prc[7];	// �ŵ�3�ܰ�켱ȣ������
	char s_lvl_3_q[7];	// �ŵ�3�ܰ�켱ȣ���ܷ�, �ڸ��� ����(6->7)
	char s_lvl_4_sign[1];	// �ŵ�4�ܰ��ȣ
	char s_lvl_4_prc[7];	// �ŵ�4�ܰ�켱ȣ������
	char s_lvl_4_q[7];	// �ŵ�4�ܰ�켱ȣ���ܷ�, �ڸ��� ����(6->7)
	char s_lvl_5_sign[1];	// �ŵ�5�ܰ��ȣ
	char s_lvl_5_prc[7];	// �ŵ�5�ܰ�켱ȣ������
	char s_lvl_5_q[7];	// �ŵ�5�ܰ�켱ȣ���ܷ�, �ڸ��� ����(6->7)
	char s_lvl_6_sign[1];	// �ŵ�6�ܰ��ȣ
	char s_lvl_6_prc[7];	// �ŵ�6�ܰ�켱ȣ������
	char s_lvl_6_q[7];	// �ŵ�6�ܰ�켱ȣ���ܷ�, �ڸ��� ����(6->7)
	char s_lvl_7_sign[1];	// �ŵ�7�ܰ��ȣ
	char s_lvl_7_prc[7];	// �ŵ�7�ܰ�켱ȣ������
	char s_lvl_7_q[7];	// �ŵ�7�ܰ�켱ȣ���ܷ�, �ڸ��� ����(6->7)
	char s_lvl_8_sign[1];	// �ŵ�8�ܰ��ȣ
	char s_lvl_8_prc[7];	// �ŵ�8�ܰ�켱ȣ������
	char s_lvl_8_q[7];	// �ŵ�8�ܰ�켱ȣ���ܷ�, �ڸ��� ����(6->7)
	char s_lvl_9_sign[1];	// �ŵ�9�ܰ��ȣ
	char s_lvl_9_prc[7];	// �ŵ�9�ܰ�켱ȣ������
	char s_lvl_9_q[7];	// �ŵ�9�ܰ�켱ȣ���ܷ�, �ڸ��� ����(6->7)
	char s_lvl_10_sign[1];	// �ŵ�10�ܰ��ȣ
	char s_lvl_10_prc[7];	// �ŵ�10�ܰ�켱ȣ������
	char s_lvl_10_q[7];	// �ŵ�10�ܰ�켱ȣ���ܷ�, �ڸ��� ����(6->7)
	char total_l_trd_cnt[5];	// �ż���ȿȣ���Ǽ�
	char l_lvl_1_trd_cnt[4];	// �ż�1�ܰ�켱ȣ���Ǽ�
	char l_lvl_2_trd_cnt[4];	// �ż�2�ܰ�켱ȣ���Ǽ�
	char l_lvl_3_trd_cnt[4];	// �ż�3�ܰ�켱ȣ���Ǽ�
	char l_lvl_4_trd_cnt[4];	// �ż�4�ܰ�켱ȣ���Ǽ�
	char l_lvl_5_trd_cnt[4];	// �ż�5�ܰ�켱ȣ���Ǽ�
	char l_lvl_6_trd_cnt[4];	// �ż�6�ܰ�켱ȣ���Ǽ�
	char l_lvl_7_trd_cnt[4];	// �ż�7�ܰ�켱ȣ���Ǽ�
	char l_lvl_8_trd_cnt[4];	// �ż�8�ܰ�켱ȣ���Ǽ�
	char l_lvl_9_trd_cnt[4];	// �ż�9�ܰ�켱ȣ���Ǽ�
	char l_lvl_10_trd_cnt[4];	// �ż�10�ܰ�켱ȣ���Ǽ�
	char total_s_trd_cnt[5];	// �ŵ���ȿȣ���Ǽ�
	char s_lvl_1_trd_cnt[4];	// �ŵ�1�ܰ�켱ȣ���Ǽ�
	char s_lvl_2_trd_cnt[4];	// �ŵ�2�ܰ�켱ȣ���Ǽ�
	char s_lvl_3_trd_cnt[4];	// �ŵ�3�ܰ�켱ȣ���Ǽ�
	char s_lvl_4_trd_cnt[4];	// �ŵ�4�ܰ�켱ȣ���Ǽ�
	char s_lvl_5_trd_cnt[4];	// �ŵ�5�ܰ�켱ȣ���Ǽ�
	char s_lvl_6_trd_cnt[4];	// �ŵ�6�ܰ�켱ȣ���Ǽ�
	char s_lvl_7_trd_cnt[4];	// �ŵ�7�ܰ�켱ȣ���Ǽ�
	char s_lvl_8_trd_cnt[4];	// �ŵ�8�ܰ�켱ȣ���Ǽ�
	char s_lvl_9_trd_cnt[4];	// �ŵ�9�ܰ�켱ȣ���Ǽ�
	char s_lvl_10_trd_cnt[4];	// �ŵ�10�ܰ�켱ȣ���Ǽ�
	char real_t_high_prc_sign[1];	// �ǽð����Ѱ���ȣ
	char real_t_high_prc[7];	// �ǽð����Ѱ�, ���߰��̵�����
	char real_t_low_prc_sign[1];	// �ǽð����Ѱ���ȣ
	char real_t_low_prc[7];	// �ǽð����Ѱ�, ���߰��̵�����
	char ff[1];	// End of Text, (0xFF)
} STOCK_FUTURE_MRK_OP_TS;


// �ֽļ���_����
typedef struct _STOCK_FUTURE_CLOSE {
	char data_clsf[2];	// DATA����, H0
	char info_clsf[2];	// ��������, 01:�����ֽļ���
	char mrk_clsf[1];	// ���屸��, 5
	char ff[1];	// End of Text, (0xFF)
} STOCK_FUTURE_CLOSE;


// �ֽļ���_�������ٰ���
typedef struct _STOCK_FUT_MRK_OP_SCHD {
	char data_clsf[2];	// DATA����, M4
	char info_clsf[2];	// ��������, 01:�����ֽļ���
	char mrk_clsf[1];	// ���屸��, 5
	char isin_clsf[12];	// �����ڵ�, *�������� �� ��ġ�� ���
	char stk_snr[3];	// �����Ϸù�ȣ, *�������� �� ��ġ�� ���
	char prd_id[11];	// ��ǰID, �ڵ尪�������� - �ֽļ��� ��ü�忡 ���ؼ��� spaceó��\n �����ڻ꺰 �̺�Ʈ �߻��� ��ǰID�Է�
	char mrk_prd_id[3];	// ����ǰ�׷�ID, FST : �ڽ��� �ֽļ���\nFKQ : �ڽ��� �ֽļ���
	char brd_id[2];	// ����ID, �ڵ尪��������
	char brd_event_id[3];	// �����̺�ƮID, �ڵ尪��������
	char brd_event_start_t[8];	// �����̺�Ʈ���۽ð�
	char brd_event_code[5];	// �����̺�Ʈ���뱺�ڵ�, �ڵ尪���� ����
	char ss_open_close_code[2];	// ���ǰ��������ڵ�, BS:���尳��\n BE:��������\n SS:���ǰ���\n SE:��������\n SH:��������\n SR:�����簳
	char ss_id[2];	// ����ID, �ڵ尪��������
	char adj_stage[2];	// ����ܰ�, CB �� ���������� Ȯ��� ����Ǵ� �ܰ� \n��)�ʱⰪ 00
	char under_asset_prc_chg[1];	// �������񰡰�Ȯ��߻��ڵ�, ���������� ����Ȯ��� �����ڵ�(U:���, D:�϶�)
	char exp_prc_chg_t[8];	// ����Ȯ�뿹���ð�, �Ļ����尡��Ȯ�� ���� �̺�Ʈ �߻��� ���Ǵ� �׸����� ����Ȯ�뿹���ð��� ��ϵ�
	char ff[1];	// End of Text, (0xFF)
} STOCK_FUT_MRK_OP_SCHD;


// �ֽļ���_�������
typedef struct _STOCK_FUT_DIST_INFO {
	char data_clsf[2];	// DATA����, O6
	char info_clsf[2];	// ��������, 01:�����ֽļ���
	char mrk_clsf[1];	// ���屸��, 5
	char isin_clsf[12];	// �����ڵ�
	char stk_snr[4];	// �����Ϸù�ȣ
	char brd_id[2];	// ����ID, �ڵ尪��������
	char dist_adj_code[1];	// ������뱸���ڵ�, 1:��а���, 2:�������
	char dist_code[1];	// ���ó�������ڵ�, 1:�ż�����, 2:�ż�����,\n 3:�ŵ�����, 4:�ŵ�����\n *��������� �ڵ����(spaceó��)
	char dist_cls_t[8];	// ��������ð�
	char ff[1];	// End of Text, (0xFF)
} STOCK_FUT_DIST_INFO;


// �ֽļ���_�ǽð������Ѱ� ���������
typedef struct _STOCK_FUT_REAL_HIGH_LOW_LIMIT_ON_OFF {
	char data_clsf[2];	// DATA����, Q2
	char info_clsf[2];	// ��������, 01:�����ֽļ���
	char mrk_clsf[1];	// ���屸��, 5
	char isin_clsf[12];	// �����ڵ�
	char stk_snr[4];	// �����Ϸù�ȣ
	char brd_id[2];	// ����ID, �ڵ尪��������
	char cleared_t[8];	// ó���ð�
	char real_t_prc_limit_code[1];	// �ǽð��������Ѽ����ڵ�, 0: ����, 1: ����, 2: �缳��
	char real_t_high_prc_sign[1];	// �ǽð����Ѱ���ȣ
	char real_t_high_prc[7];	// �ǽð����Ѱ�, ���߰��̵�����
	char real_t_low_prc_sign[1];	// �ǽð����Ѱ���ȣ
	char real_t_low_prc[7];	// �ǽð����Ѱ�, ���߰��̵�����
	char ff[1];	// End of Text, (0xFF)
} STOCK_FUT_REAL_HIGH_LOW_LIMIT_ON_OFF;


// �ֽļ���_����������Ȯ��ߵ�
typedef struct _STOCK_FUT_PRC_LIMIT_ON {
	char data_clsf[2];	// DATA����, V1
	char info_clsf[2];	// ��������, 01:�ֽļ���
	char mrk_clsf[1];	// ���屸��, 5
	char code_clsf[12];	// �����ڵ�
	char stk_snr[4];	// �����Ϸù�ȣ
	char prd_id[11];	// ��ǰID, �ڵ尪�������� : spaceó��
	char brd_id[2];	// ����ID, �ڵ尪��������
	char prc_limit_start_t[8];	// ����Ȯ��ð�, ������ Ȯ��� �ð�
	char prc_limit_high[2];	// ��������Ȯ����Ѵܰ�, ����� ���Ѵܰ�
	char prc_limit_low[2];	// ��������Ȯ�����Ѵܰ�, ����� ���Ѵܰ�
	char high_prc_sign[1];	// ���Ѱ���ȣ
	char high_prc[7];	// ���Ѱ�, ����� ���Ѱ�\n��)9999999
	char low_prc_sign[1];	// ���Ѱ���ȣ
	char low_prc[7];	// ���Ѱ�, ����� ���Ѱ�\n��)9999999
	char ff[1];	// End of Text, (0xFF)
} STOCK_FUT_PRC_LIMIT_ON;


// �ֽļ���_�̰����������� ������
typedef struct _STOCK_FUT_OPEN_INTEREST_DATA {
	char data_clsf[2];	// DATA����, H2
	char info_clsf[2];	// ��������, 01:�����ֽļ���
	char mrk_clsf[1];	// ���屸��, 5
	char isin_clsf[12];	// �����ڵ�, ���� record '999999999999' set
	char stk_snr[4];	// ����SEQ
	char open_interest_clsf[2];	// �̰�����������, ���� Ȯ�� : "M0" (07:40�а� ����)\n���� ���� : "M1" (���� Ư���������� ��������\n         �۽�, 10��)\n���� Ȯ�� : "M2" (���� ������ �۽�,\n         ������ 1�ð��� ����)
	char traded_date[8];	// �ŷ�����
	char open_interest_q[9];	// �̰�����������, ����:���
	char ff[1];	// End of Text, (0xFF)
} STOCK_FUT_OPEN_INTEREST_DATA;


// �ֽļ���_���갡�� ������
typedef struct _STOCK_FUT_SETT_PRC_DATA {
	char data_clsf[2];	// DATA����, H3
	char info_clsf[2];	// ��������, 01:�����ֽļ���
	char mrk_clsf[1];	// ���屸��, 5
	char isin_clsf[12];	// �����ڵ�, ���� record '999999999999' set
	char stk_snr[4];	// ����SEQ
	char calc_prc[16];	// ���갡��, ��) 99999999.99999999
	char calc_prc_clsf[1];	// ���갡�ݱ���, 0 : ���갡 ����(���� �ŷ������� �⼼ ����)\n1 : ���� ����(�Ǽ�)\n2 : ���� �⼼(���� �ŷ������� �⼼) - 2010.12.20 ����\n3 : ���� ���갡(���� �ŷ������� ���� ������) - 2010.12.20 ����\n4 : ���� �̷а�(���� �ŷ������� ���� ������)\n5 : ��������ŷ��� ���� ������ ������ ���� - 2010.12.20 ����\n6 : ������ ���� ���갡 - 2010.12.20 ����\n7 : ����ڻ� ����(�̷а����»�ǰ)\n8 : ������ذ��� - 2010.12.20 �߰�
	char final_sett_prc[16];	// ������������, ��) 99999999.99999999
	char final_sett_clsf[1];	// �����������ݱ���
	char ff[1];	// End of Text, (0xFF)
} STOCK_FUT_SETT_PRC_DATA;


// �ֽļ���_�����ü�Recovery ������
typedef struct _STOCK_FUT_RECOVERY_DATA {
	char data_clsf[2];	// DATA����, B2
	char info_clsf[2];	// ��������, 01:�����ֽļ���
	char mrk_clsf[1];	// ���屸��, 5
	char isin_clsf[12];	// �����ڵ�
	char stk_snr[4];	// �����Ϸù�ȣ
	char cur_prc_sign[1];	// ���簡��ȣ
	char cur_prc[7];	// ���簡
	char rct_prd_prc[7];	// �ֱٿ��� ������������
	char nxt_prd_prc[7];	// ������ ������������
	char init_prc_sign[1];	// �ð���ȣ
	char init_prc[7];	// �ð�
	char high_prc_sign[1];	// ����ȣ
	char high_prc[7];	// ��
	char low_prc_sign[1];	// ������ȣ
	char low_prc[7];	// ����
	char open_interest_q[9];	// �̰�����
	char accm_exe_q[7];	// ����ü�����
	char accm_trd_amt[15];	// �����ŷ����, ����:��
	char l_or_s[1];	// �����ŵ��ż������ڵ�, 1:�ŵ�,2:�ż�(�������� ���� ȣ���� �ŵ��ż����а�)
	char s_lvl_1_sign[1];	// SIGN��ȣ
	char s_lvl_1_prc[7];	// �ŵ�1ȣ��
	char s_lvl_1_q[7];	// �ŵ�1ȣ������, �ڸ��� ����(6->7)
	char s_lvl_1_trd_cnt[4];	// �ŵ�1ȣ���Ǽ�
	char l_lvl_1_sign[1];	// SIGN��ȣ
	char l_lvl_1_prc[7];	// �ż�1ȣ��
	char l_lvl_1_q[7];	// �ż�1ȣ������, �ڸ��� ����(6->7)
	char l_lvl_1_trd_cnt[4];	// �ż�1ȣ���Ǽ�
	char s_lvl_2_sign[1];	// SIGN��ȣ
	char s_lvl_2_prc[7];	// �ŵ�2ȣ��
	char s_lvl_2_q[7];	// �ŵ�2ȣ������, �ڸ��� ����(6->7)
	char s_lvl_2_trd_cnt[4];	// �ŵ�2ȣ���Ǽ�
	char l_lvl_2_sign[1];	// SIGN��ȣ
	char l_lvl_2_prc[7];	// �ż�2ȣ��
	char l_lvl_2_q[7];	// �ż�2ȣ������, �ڸ��� ����(6->7)
	char l_lvl_2_trd_cnt[4];	// �ż�2ȣ���Ǽ�
	char s_lvl_3_sign[1];	// SIGN��ȣ
	char s_lvl_3_prc[7];	// �ŵ�3ȣ��
	char s_lvl_3_q[7];	// �ŵ�3ȣ������, �ڸ��� ����(6->7)
	char s_lvl_3_trd_cnt[4];	// �ŵ�3ȣ���Ǽ�
	char l_lvl_3_sign[1];	// SIGN��ȣ
	char l_lvl_3_prc[7];	// �ż�3ȣ��
	char l_lvl_3_q[7];	// �ż�3ȣ������, �ڸ��� ����(6->7)
	char l_lvl_3_trd_cnt[4];	// �ż�3ȣ���Ǽ�
	char s_lvl_4_sign[1];	// SIGN��ȣ
	char s_lvl_4_prc[7];	// �ŵ�4ȣ��
	char s_lvl_4_q[7];	// �ŵ�4ȣ������, �ڸ��� ����(6->7)
	char s_lvl_4_trd_cnt[4];	// �ŵ�4ȣ���Ǽ�
	char l_lvl_4_sign[1];	// SIGN��ȣ
	char l_lvl_4_prc[7];	// �ż�4ȣ��
	char l_lvl_4_q[7];	// �ż�4ȣ������, �ڸ��� ����(6->7)
	char l_lvl_4_trd_cnt[4];	// �ż�4ȣ���Ǽ�
	char s_lvl_5_sign[1];	// SIGN��ȣ
	char s_lvl_5_prc[7];	// �ŵ�5ȣ��
	char s_lvl_5_q[7];	// �ŵ�5ȣ������, �ڸ��� ����(6->7)
	char s_lvl_5_trd_cnt[4];	// �ŵ�5ȣ���Ǽ�
	char l_lvl_5_sign[1];	// SIGN��ȣ
	char l_lvl_5_prc[7];	// �ż�5ȣ��
	char l_lvl_5_q[7];	// �ż�5ȣ������, �ڸ��� ����(6->7)
	char l_lvl_5_trd_cnt[4];	// �ż�5ȣ���Ǽ�
	char s_lvl_6_sign[1];	// SIGN��ȣ
	char s_lvl_6_prc[7];	// �ŵ�6ȣ��
	char s_lvl_6_q[7];	// �ŵ�6ȣ������, �ڸ��� ����(6->7)
	char s_lvl_6_trd_cnt[4];	// �ŵ�6ȣ���Ǽ�
	char l_lvl_6_sign[1];	// SIGN��ȣ
	char l_lvl_6_prc[7];	// �ż�6ȣ��
	char l_lvl_6_q[7];	// �ż�6ȣ������, �ڸ��� ����(6->7)
	char l_lvl_6_trd_cnt[4];	// �ż�6ȣ���Ǽ�
	char s_lvl_7_sign[1];	// SIGN��ȣ
	char s_lvl_7_prc[7];	// �ŵ�7ȣ��
	char s_lvl_7_q[7];	// �ŵ�7ȣ������, �ڸ��� ����(6->7)
	char s_lvl_7_trd_cnt[4];	// �ŵ�7ȣ���Ǽ�
	char l_lvl_7_sign[1];	// SIGN��ȣ
	char l_lvl_7_prc[7];	// �ż�7ȣ��
	char l_lvl_7_q[7];	// �ż�7ȣ������, �ڸ��� ����(6->7)
	char l_lvl_7_trd_cnt[4];	// �ż�7ȣ���Ǽ�
	char s_lvl_8_sign[1];	// SIGN��ȣ
	char s_lvl_8_prc[7];	// �ŵ�8ȣ��
	char s_lvl_8_q[7];	// �ŵ�8ȣ������, �ڸ��� ����(6->7)
	char s_lvl_8_trd_cnt[4];	// �ŵ�8ȣ���Ǽ�
	char l_lvl_8_sign[1];	// SIGN��ȣ
	char l_lvl_8_prc[7];	// �ż�8ȣ��
	char l_lvl_8_q[7];	// �ż�8ȣ������, �ڸ��� ����(6->7)
	char l_lvl_8_trd_cnt[4];	// �ż�8ȣ���Ǽ�
	char s_lvl_9_sign[1];	// SIGN��ȣ
	char s_lvl_9_prc[7];	// �ŵ�9ȣ��
	char s_lvl_9_q[7];	// �ŵ�9ȣ������, �ڸ��� ����(6->7)
	char s_lvl_9_trd_cnt[4];	// �ŵ�9ȣ���Ǽ�
	char l_lvl_9_sign[1];	// SIGN��ȣ
	char l_lvl_9_prc[7];	// �ż�9ȣ��
	char l_lvl_9_q[7];	// �ż�9ȣ������, �ڸ��� ����(6->7)
	char l_lvl_9_trd_cnt[4];	// �ż�9ȣ���Ǽ�
	char s_lvl_10_sign[1];	// SIGN��ȣ
	char s_lvl_10_prc[7];	// �ŵ�10ȣ��
	char s_lvl_10_q[7];	// �ŵ�10ȣ������, �ڸ��� ����(6->7)
	char s_lvl_10_trd_cnt[4];	// �ŵ�10ȣ���Ǽ�
	char l_lvl_10_sign[1];	// SIGN��ȣ
	char l_lvl_10_prc[7];	// �ż�10ȣ��
	char l_lvl_10_q[7];	// �ż�10ȣ������, �ڸ��� ����(6->7)
	char l_lvl_10_trd_cnt[4];	// �ż�10ȣ���Ǽ�
	char total_s_limit_ord_q[8];	// �ŵ� ��ȣ������, �ڸ��� ����(7->8)
	char total_s_trd_cnt[5];	// �ŵ���ȿȣ���Ǽ�
	char total_l_limit_ord_q[8];	// �ż� ��ȣ������, �ڸ��� ����(7->8)
	char total_l_trd_cnt[5];	// �ż���ȿȣ���Ǽ�
	char ss_id[2];	// ����ID, �ڵ尪��������
	char brd_id[2];	// ����ID, �ڵ尪��������
	char brd_event_id[3];	// �����̺�ƮID, B2 ������ �����̺�ƮID ������(���� ���°��� ���۵� �� ����). ����, �ش� �׸� '000' ���� ����. 2014.03.24)
	char exp_prc_sign[1];	// ����ü�ᰡ�ݺ�ȣ, ���ϰ��ŸŽø� ����\n (����±����ڵ�:10,20,30,80)
	char exp_prc[7];	// ����ü�ᰡ��, ���ϰ��ŸŽø� ����\n (����±����ڵ�:10,20,30,80)
	char real_t_high_prc_sign[1];	// �ǽð����Ѱ���ȣ
	char real_t_high_prc[7];	// �ǽð����Ѱ�, ���߰��̵�����
	char real_t_low_prc_sign[1];	// �ǽð����Ѱ���ȣ
	char real_t_low_prc[7];	// �ǽð����Ѱ�, ���߰��̵�����
	char ff[1];	// End of Text, (0xFF)
} STOCK_FUT_RECOVERY_DATA;


// �ֽļ���_������ ������
typedef struct _STOCK_FUT_INVESTOR_DATA {
	char data_clsf[2];	// DATA����, H1
	char info_clsf[2];	// ��������, 01:�����ֽļ���
	char mrk_clsf[1];	// ���屸��, 5
	char created_date[8];	// ��������
	char created_time[6];	// �����ð�
	char inv_data_clsf[2];	// �����ͱ���, *����Ȯ�� : 00, �������� : 01, ����Ȯ�� : 02\n *E1 : ���� ������ �Ϸ�, E2 : Ȯ�� ������ �Ϸ�\n ���� record '99' set
	char prd_id[11];	// ��ǰID, �ڵ尪�������� - ������ü(KRDRVFU999 )
	char inv_clsf[4];	// ����������, �ڵ尪���� ���� *�ڵ� '7000'�� ����,��������׸� 0���� ����
	char long_exe_q[9];	// �ż���������
	char short_exe_q[9];	// �ŵ���������
	char long_traded_amt[18];	// �ż��������
	char short_traded_amt[18];	// �ŵ��������
	char spread_long_exe_q[9];	// �������忡 ���� ������ �ż� ��������
	char spread_short_exe_q[9];	// �������忡 ���� ������ �ŵ� ��������
	char spread_long_traded_amt[18];	// �������忡 ���� ������ �ż� �������
	char spread_short_traded_amt[18];	// �������忡 ���� ������ �ŵ� �������
	char ff[1];	// End of Text, (0xFF)
} STOCK_FUT_INVESTOR_DATA;


// �ֽļ���_����+�����ջ�
typedef struct _STOCK_FUT_COMP_BLOCK {
	char data_clsf[2];	// DATA����, C4
	char info_clsf[2];	// ��������, 01:�����ֽļ���
	char mkt_clsf[1];	// ���屸��, 5
	char isin_clsf[12];	// �����ڵ�
	char stk_snr[7];	// �����Ϸù�ȣ
	char cpt_block_trd_vol[12];	// ����+�����ջ� �ŷ���, ����Ÿſ� ���Ǵ뷮�ŷ��� �ջ��� �ŷ���
	char cpt_block_trd_amt[22];	// ����+�����ջ� �ŷ����, ����Ÿſ� ���Ǵ뷮�ŷ��� �ջ��� �ŷ����\n(���� : ��)
	char ff[1];	// End of Text, (0xFF)
} STOCK_FUT_COMP_BLOCK;


// �ֽļ���_�������� ������
typedef struct _STOCK_FUT_PRD_INFO_DATA {
	char data_clsf[2];	// DATA����, A0
	char info_clsf[2];	// ��������, 01:�����ֽļ���
	char mrk_clsf[1];	// ���屸��, 5
	char prd_cnt[5];	// �����
	char trd_date[8];	// ��������(��ȸ����)
	char isin_clsf[12];	// �����ڵ�, ���� record '999999999999' set
	char stk_snr[6];	// ����SEQ
	char prd_id[11];	// ��ǰID, * �ڵ尪 ������ ����\n* ����Ī: �Ļ���ǰID\n10 => 11, 20140303
	char sh_prd_code[9];	// ��������ڵ�, ��) KR4101C90009 �� K101C9000
	char prd_name_kor[80];	// �����ѱ۸�
	char sh_prd_name_kor[40];	// �����ѱ۾��
	char prd_name_eng[80];	// ���񿵹���
	char sh_prd_name_eng[40];	// ���񿵹����
	char listing_date[8];	// ��������
	char de_listing_date[8];	// ������������
	char spread_clsf_code[1];	// ��������������񱸺��ڵ�, ���������� ������ �Ǵ� ������ ISIN ǥ���ڵ�\n--�ڵ尪--\nF: ������(�ð���������)\nN: �ٿ���(�ð���������)\n20140303
	char final_sett_code[1];	// ������������ڵ�, ���ݰ���, �ǹ��μ������� �� �Ļ���ǰ�� �������� ���\n--�ڵ尪--\nC: ���ݰ���\nD: �ǹ��μ�������\nA: ����+�ǹ��μ�������\n0: �ش����\n20140303
	char prc_limit_exp_dir[1];	// ��������Ȯ������ڵ�, ���������� �ٴܰ�� ���ǵǴ� ��� ���� �ܰ�� Ȯ��Ǵ� ����� ������ �� Ȯ�븦 �����ϴ� ����\n## �ڵ尪##\nX:������\nF:������\nB:������\nT:�����
	char prc_limit_final_stg[3];	// ��������Ȯ����������ڵ�, ���������� �ٴܰ�� ���ǵǴ� ��� ������ �����ܰ��ȣ
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
	char under_asset_id[3];	// �����ڻ�ID, ��) K2I:KOSPI200����, KQI:�ڽ���150����,\n   Sxx:�����ֽ�, BM3:��3�ⱹä,\n   BM5:��5�ⱹä, BMA:��10�ⱹä, \n   CDR:CD, USD:�̱��޷�, JPY:�Ϻ���,\n   EUR:��������,\n   GLD:��, LHG:����\n20140303
	char opt_type_code[1];	// �Ǹ���������ڵ�, A:�̱���,E:������,B:���´���,Z:��Ÿ\n20140303
	char spread_str_code[2];	// �������屸���ڵ�, Combination ȣ���� ��ü�� �������幰�� ���񱸼�.\n--�ڵ尪--\n- T1: �ֱٿ���+2°����\n      > T2, T3, T4, ...\n*����Ī: �������������ڵ�\n20140303
	char spread_prd_code_1[12];	// �������屸�������ڵ�1, * ����Ī: ��������ٿ��� �����ڵ�\n�ٿ��� ǥ���ڵ�\n20140303
	char spread_prd_code_2[12];	// �������屸�������ڵ�2, * ����Ī : ������������� �����ڵ�\n������ ǥ���ڵ�\n20140303
	char last_trading_date[8];	// �����ŷ�����
	char final_sett_date[8];	// ������������
	char cont_month_nbr[3];	// ��������ȣ, * ����Ī: ���������ڵ�\n1:�ֱٿ���,������������\n2:2°����\n3:3°����\n4:4°����\n5:5°����\n6:6°����\n7:7°����      �� �ֱٿ������� ��ġ\nX => 9, 1 => 3, 20140303
	char maturity_date[8];	// ��������, �Ǹ���� ������ ��������
	char exe_prc[17];	// ��簡��, ��) 999999999.99999999
	char adjust_clsf_code[1];	// ���������ڵ�, �����ڻ��� ���ذ��� ������ ����� ����(�̰�������)���� ������� ����(�ŷ��¼�����)������ ����\n--�ڵ尪--\nN: ����\nO: �̰�������\nC: �ŷ��¼�����\n20140303
	char prd_unit[17];	// �ŷ�����, 1��࿡ �ش��ϴ� �����ڻ����\n��) 999999999.99999999
	char multiplier[21];	// �ŷ��¼�, ������� �� ������ ����ϴ� ���¼�\n��) 9999999999999.99999999
	char mrk_cnst_code[1];	// �������������ڵ�, 0:�̽�����������\n1:���Ͻ�����������\n2:���Ž�����������
	char listing_type_code[1];	// ���������ڵ�, 1:�űԻ���\n2:�߰�����\n3:��������\n4:���ʻ���\n5:��������\n6:Ư������
	char atm_prc[12];	// ���, �����ڻ���ذ��ݿ� ���� ����� ��簡��\n��) 9999999999.99
	char adj_reason_code[2];	// ���������ڵ�, 00:�ش���׾���, 01:�Ǹ���, 02:����,\n03:�й��, 04:�ǹ��, 05:�߰�����,\n06:�Ǹ��߰�����, 99:��Ÿ
	char under_asset_prd_code[12];	// �����ڻ������ڵ�
	char under_asset_close_prc[12];	// �����ڻ�����, ��) 9999999999.99
	char left_until_maturity[7];	// �����ϼ�
	char adj_std_prc[17];	// �������ذ���, �ֽ��Ļ���ǰ�� �����ֱ� �������ذ���\n��) 999999999.99999999
	char std_prc_clsf_code[2];	// ���ذ��ݱ����ڵ�, *����\nspcace:���ذ� ����(���� ������������)\n11:�������갡\n12:���ϱ��ذ�(�ŷ������� ����������)\n13:�����̷а�(�ŷ������� ����������)\n14:���ϱ⼼(�ŷ������� �⼼����)\n  -2012.05.14 ����\n15:�����̷а�(�ŷ������� �⼼����)-\n  -2012.05.14 ����\n16:������ �������갡\n17:������ ���ϱ��ذ�\n  (�ŷ������� ����������)\n18:������ ���ϱ⼼(�ŷ������� �⼼����)\n  -2012.05.14 ����\n19:���� ����ڻ� ����(�̷а����� ��ǰ)\n*�ɼ�\n21:�������űݱ��ذ�\n22:���ϱ��ذ�(�ŷ������� ����������)\n23:�����̷а�(�ŷ������� ����������)\n24:���ϱ⼼(�ŷ������� �⼼����)\n  -2012.05.14 ����\n25:������ �������űݱ��ذ�\n26:������ ���ϱ��ذ�\n  (�ŷ������� ����������)\n27:������ ���ϱ⼼(�ŷ������� �⼼����)\n  -2012.05.14 ����
	char trd_std_prc_clsf_code[1];	// �Ÿſ���ذ��ݱ����ڵ�, 0:�ش����\n1:�Ǽ�\n2:�⼼\n3:�̷а�\n4:����ڻ�����
	char yest_adj_close_prc_sign[1];	// SIGN��ȣ
	char yest_adj_close_prc[17];	// ������������, �ֽ��Ļ���ǰ�� ��������\n��) 999999999.99999999
	char block_trd_clsf[1];	// ���Ǵ뷮�ŸŴ�󿩺�, Y:���ǸŸŻ�ǰ, N:���ƴ�\n����ǰ��:3�⹰��ä����, �̱��޷�����,\n      ���μ���, ������
	char yest_mrg_std_prc[17];	// �������űݱ��ذ���, ��) 999999999.99999999
	char yest_mrg_std_prc_clsf_code[2];	// �������űݱ��ذ��ݱ����ڵ�, *�ɼ�\n20:���ű� ���ذ� ����\n21:��������(�Ǽ�)\n22:���ϱ⼼(�ŷ������ı⼼)\n  -2012.05.14 ����\n23:�������űݱ��ذ�\n  (�ŷ������� ����������)\n  -2012.05.14 ����\n24:�����̷а�(�ŷ������� ����������)\n25:�����������űݱ��ذ�\n  (�ŷ������� ����������)\n  -2012.05.14 ����
	char sett_theory_prc[15];	// �����̷а���, �ؿɼ��� ��� ���űݱ��ذ��� \n��) 999999999.999999
	char std_theory_prc[15];	// �����̷а���, ��) 999999999.999999
	char yest_sett_prc[17];	// �������갡��, ��) 999999999.99999999
	char halt_trd_clsf[1];	// �ŷ���������, Y, N
	char ft_cb_high_prc[12];	// ����Circuit_Breakers���Ѱ�, ���� CB �ߵ������� �Ǵ��ϱ� ���� ����\n����(���ذ���� +/-5%�� CB �ߵ�\n������ ��� +5%�� ����� ����)\n��) 99+F31499999999.99
	char ft_cb_low_prc[12];	// ����Circuit_Breakers���Ѱ�, ���� CB �ߵ������� �Ǵ��ϱ� ���� ����\n����(���ذ���� +/-5%�� CB �ߵ�\n������ ��� -5%�� ����� ����)\n��) 9999999999.99
	char check_exe_prc[17];	// ��ȸ����簡��, ��) 999999999.99999999
	char atm_clsf[1];	// ATM�����ڵ�, 0:����, 1:ATM, 2:ITM, 3:OTM
	char last_trading_clsf[1];	// �����ŷ��Ͽ���, Y, N
	char ex_divid_aft_value[15];	// �����Ĺ�簡ġ, �ֽ� �� �ְ����� ��ǰ���� �����\n- ���� : �����Ĺ̷���ġ\n- �ɼ� : ���������簡ġ\n��) 999999999.999999
	char yest_close_prc_sign[1];	// SIGN��ȣ
	char yest_close_prc[12];	// ��������, ��) 9999999999.99
	char yest_close_prc_clsf[1];	// �������������ڵ�, 1:�Ǽ�, 3:�ŷ���\n2:�⼼ -2012.05.14 ����
	char yest_init_prc_sign[1];	// SIGN��ȣ
	char yest_init_prc[12];	// ���Ͻð�, ��) 9999999999.99
	char yest_high_prc_sign[1];	// SIGN��ȣ
	char yest_high_pric[12];	// ���ϰ�, ��) 9999999999.99
	char yest_low_prc_sign[1];	// SIGN��ȣ
	char yest_low_prc[12];	// ��������, ��) 9999999999.99
	char yest_first_exe_date[8];	// ����ü������
	char yest_last_exe_time[8];	// ��������ü��ð�
	char yest_sett_prc_clsf[2];	// �������갡�ݱ���, *����\n 10:���갡����\n 11:��������(�Ǽ�)\n 12:���ϱ⼼(�ŷ������ı⼼) - 2010.12.20 ����\n 13:�������갡(�ŷ������� ����������) - 2010.12.20 ����\n 14:�����̷а�(�ŷ������� ����������)\n 15:��������� ���� - 2010.12.20 ����\n 16:������ ���� ���갡 - 2010.12.20 ����\n 17:����ڻ� ����(�̷а����� ��ǰ)\n 18:������ذ��� - 2010.12.20 �߰�
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
	char yest_block_trd_exe_q[12];	// �������Ǵ뷮�ջ�ü�����, �������Ǵ뷮�Ÿ�ü����� => �������Ǵ뷮�ջ�ü����� [����ü�����+�������Ǵ뷮�Ÿ�ü�����(���Ǵ뷮+FLEX)] 2016.03.28 ����
	char yest_block_trd_total_amt[22];	// �������Ǵ뷮�ջ�ŷ����, �������Ǵ뷮�ŸŰŷ���� => �������Ǵ뷮�ջ�ŷ���� [���ϰŷ����+�������Ǵ뷮�ŸŰŷ����(���Ǵ뷮+FLEX)] 2016.03.28 ����
	char cd_rate[6];	// CD�ݸ�, ��) 999.999
	char open_interest_q[15];	// �̰����ѵ�����, *�����Ͽ� ����Ǵ� ��ǰ�� ���º�\n �̰��� �ѵ� ����. �̰��� �ѵ���\n ������� ���� ��ǰ�� 0\n*�ֽļ������� �ش�\n8 => 15, 20140303
	char product_cat[4];	// �Ҽ� ��ǰ��, *�ֽļ���/�ɼǿ��� �ش�
	char product_cat_off_pctg[9];	// ��ǰ�� �ɼ���, *������� ǥ��\n*�ֽļ���/�ɼǿ��� �ش翹) 9999999.99\n5 => 9, 20140303
	char limit_ord_clsf_code[5];	// ������ȣ�����Ǳ����ڵ�, ȣ���� ü�� �� �ܷ�����. Bitwise ����\n--�ڵ尪--\n1: FAS (Fill And Store)\n2: FOK (Fill Or Kill)\n3: FAK (Fill And Kill)\n\n* ������ȣ�����Ǳ����ڵ� BITWISE ����\n���� Ȯ�强�� ���� �ش� 10�������� 2������ ��ȯ�Ͽ� ó�����(�ִ� 16bit���� ��밡��)\n�� ) ������ȣ�����Ǳ����ڵ� ���� 6�̸�\n    (������ 6 -> ������ 00000110)\n0��° bit 0 -> 0 : FAS\n1��° bit 1 -> 2 : FOK\n2��° bit 1 -> 4 : FAK\n��, FOK�̸鼭 FAK�� �����Ѵٴ� �ǹ� (FOK & FAK)\nX => 9, 1 => 5, 20140303
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
	char real_t_high_price_gap[12];	// �ǽð����Ѱ�����, ���� ü�ᰡ�ݰ� �ǽð����Ѱ����� ����\n�ǽð����Ѱ� = ����ü�ᰡ�� + �ǽð����Ѱ�����\nex) 9999999999.99  20140901
	char real_t_low_price_gap_sign[1];	// SIGN��ȣ, 20140901
	char real_t_low_price_gap[12];	// �ǽð����Ѱ�����, ���� ü�ᰡ�ݰ� �ǽð����Ѱ����� ����\n�ǽð����Ѱ� = ����ü�ᰡ�� + �ǽð����Ѱ�����(����)\nex) 9999999999.99 20140901
	char under_ass_mrk_id[3];	// �����ڻ����ID, �����ڻ����ID�� �����ڻ��� KRX�� ����� ��쿡�� ä����.\nK200�����ɼ�:STK\n�ڽ���150����:KSQ\n�ֽļ����ɼ�:STK/KSQ\n��ǰ�����ɼ�:SPACE\n��������������:STK\n������������:STK\n�̴�K200�����ɼ�:STK
	char limit_ord_upper_limit_q[16];	// ���Ѽ���, ȣ�����Ѽ��� (20181210 �׸��߰�)
	char limit_ord_lower_limit_q[16];	// ���Ѽ���, ȣ�����Ѽ��� (20181210 �׸��߰�)
	char block_trd_ord_upper_limit_q[16];	// ���Ǵ뷮�ŸŻ��Ѽ���, ���Ǵ뷮�Ÿ�ȣ�����Ѽ��� (20181210 �׸��߰�)
	char block_trd_ord_lower_limit_q[16];	// ���Ǵ뷮�Ÿ����Ѽ���, ���Ǵ뷮�Ÿ�ȣ�����Ѽ��� (20181210 �׸��߰�)
	char filler[60];	// FILLER, 170 => 134, 20090831\n134 => 133, 20121217\n133 => 110, 20140303\n110 => 83,  20140901\n83  => 27,  20150615\n27  => 24,  20150720\n24 => 60 , 20181210 (��������� ���� 1200->1300)
	char ff[1];	// End of Text, (0xFF)
} STOCK_FUT_PRD_INFO_DATA;


// �ֽļ���_�������� ������
typedef struct _STOCK_FUT_ADJ_INFO_DATA {
	char data_clsf[2];	// DATA����, H4
	char info_clsf[2];	// ��������, 01:�����ֽļ���
	char mrk_clsf[1];	// ���屸��, 5
	char trd_date[8];	// ��������
	char isin_clsf[12];	// �����ڵ�, ���� record '999999999999' set
	char adj_coef_denominator[20];	// ��������и�, ��) 999999999999.99999999
	char adj_coef_numerator[20];	// �����������, ��) 999999999999.99999999
	char bef_adj_unit_size[20];	// ������ �ŷ�����(���ũ��), ��) 999999999999.99999999
	char aft_adj_unit_size[20];	// ������ �ŷ�����(���ũ��), ��) 999999999999.99999999
	char bef_adj_exercise_prc[20];	// ������ ��簡��, ��) 999999999999.99999999
	char aft_adj_exercise_prc[20];	// ������ ��簡��, ��) 999999999999.99999999
	char aft_adj_open_interest_adj_coef[5];	// ������ �̰������� �������
	char filler[27];	// FILLER
	char ff[1];	// End of Text, (0xFF)
} STOCK_FUT_ADJ_INFO_DATA;


// �ֽļ���_Polling ������
typedef struct _STOCK_FUT_POLLING_DATA {
	char data_clsf[2];	// DATA����, I2
	char info_clsf[2];	// ��������, 01:�����ֽļ���
	char mrk_cslf[1];	// ���屸��, 5
	char send_t[4];	// ���۽ð�, HHSS
	char main_backup_clsf[2];	// Main Backup����, space
	char filler[8];	// Filler
	char ff[1];	// End of Text, (0xFF)
} STOCK_FUT_POLLING_DATA;


// �ֽļ���_SPACE
typedef struct _STOCK_FUT_SPACE {
	char data_clsf[2];	// DATA����, G9
	char info_clsf[2];	// ��������, 01:�����ֽļ���
	char mrk_clsf[1];	// ���屸��, 5
	char ff[1];	// End of Text, (0xFF)
} STOCK_FUT_SPACE;
