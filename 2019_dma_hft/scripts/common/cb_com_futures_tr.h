// cb_com_futures_tr.h
// ��ǰ���� �ǽð� TR

#pragma once
// �ּ��� \n�� ���� ���߿� �̻ڰ� �ٲ����


// ��ǰ����_����+�����ջ�
typedef struct _COM_FUT_COMP_BLOCK {
	char data_clsf[2];	// DATA����,C4
	char info_clsf[2];	// ��������,01:��ǰ����
	char mkt_clsf[1];	// ���屸��,6
	char isin_clsf[12];	// �����ڵ�,*���߰��̵� ���� : �ű�ä���� �߰�\n 2010.10.25
	char stk_snr[7];	// �����Ϸù�ȣ
	char cpt_block_trd_vol[12];	// ����+�����ջ� �ŷ���,����Ÿ�, ���Ǵ뷮�ŷ�, EFP, FLEX �ŷ��� �ջ��� �ŷ���
	char cpt_block_trd_amt[22];	// ����+�����ջ� �ŷ����,����Ÿ�, ���Ǵ뷮�ŷ�, EFP, FLEX �ŷ��� �ջ��� �ŷ����\n(���� : ��)
	char ff[1];	// End of Text,0xFF
} COM_FUT_COMP_BLOCK;


// ��ǰ����_ü��
typedef struct _COM_FUT_EXEC {
	char data_clsf[2];	// DATA����,A3
	char info_clsf[2];	// ��������,01:��ǰ����
	char mkt_clsf[1];	// ���屸��,6
	char isin_clsf[12];	// �����ڵ�,*���߰��̵� ���� : �ű�ä���� �߰�\n 2010.10.25
	char stk_snr[3];	// �����Ϸù�ȣ
	char brd_id[2];	// ����ID,�ڵ尪��������
	char cur_prc_sign[1];	// ���簡�ݺ�ȣ
	char cur_prc[8];	// ���簡��,��) 999999.99
	char exe_q[6];	// ü�����
	char ss_id[2];	// ����ID,�ڵ尪��������
	char exe_t[8];	// ü��ð�
	char rct_prd_prc[8];	// �ֱٿ���������������,��) 999999.99
	char nxt_prd_prc[8];	// ������������������,��) 999999.99
	char init_prc_sign[1];	// �ð���ȣ
	char init_prc[8];	// �ð�,��) 999999.99
	char high_prc_sign[1];	// ����ȣ
	char high_prc[8];	// ��,��) 999999.99
	char low_prc_sign[1];	// ������ȣ
	char low_prc[8];	// ����,��) 999999.99
	char pri_prc_sign[1];	// �������ݺ�ȣ
	char pri_prc[8];	// ��������,��) 999999.99
	char accm_exe_q[7];	// ����ü�����
	char accm_trd_amt[15];	// �����ŷ����(����:��)
	char accm_block_trd_exe_q[7];	// ���Ǵ뷮����ü�����,������(Filler)
	char efp_accm_exe_q[7];	// EFP����ü�����,������(Filler)
	char l_or_s[1];	// �����ŵ��ż������ڵ�,1:�ŵ�,2:�ż�(�������� ���� ȣ���� �ŵ��ż����а�)
	char real_t_high_prc_sign[1];	// �ǽð����Ѱ���ȣ
	char real_t_high_prc[8];	// �ǽð����Ѱ�,��) 999999.99 ���߰��̵�����
	char real_t_low_prc_sign[1];	// �ǽð����Ѱ���ȣ
	char real_t_low_prc[8];	// �ǽð����Ѱ�,��) 999999.99 ���߰��̵�����
	char ff[1];	// End of Text,0xFF
} COM_FUT_EXEC;


// ��ǰ����_�켱ȣ��
typedef struct _COM_FUT_LIMIT_ORD {
	char data_clsf[2];	// DATA����,B6
	char info_clsf[2];	// ��������,01:��ǰ����
	char mkt_clsf[1];	// ���屸��,6
	char isin_clsf[12];	// �����ڵ�,*���߰��̵� ���� : �ű�ä���� �߰�\n 2010.10.25
	char stk_snr[3];	// �����Ϸù�ȣ
	char brd_id[2];	// ����ID,�ڵ尪��������
	char ss_id[2];	// ����ID,�ڵ尪��������
	char total_l_limit_ord_q[7];	// �ż���ȣ���ܷ�
	char l_lvl_1_sign[1];	// �ż�1�ܰ��ȣ
	char l_lvl_1_prc[8];	// �ż�1�ܰ�켱ȣ������,��) 999999.99
	char l_lvl_1_q[6];	// �ż�1�ܰ�켱ȣ���ܷ�
	char l_lvl_2_sign[1];	// �ż�2�ܰ��ȣ
	char l_lvl_2_prc[8];	// �ż�2�ܰ�켱ȣ������,��) 999999.99
	char l_lvl_2_q[6];	// �ż�2�ܰ�켱ȣ���ܷ�
	char l_lvl_3_sign[1];	// �ż�3�ܰ��ȣ
	char l_lvl_3_prc[8];	// �ż�3�ܰ�켱ȣ������,��) 999999.99
	char l_lvl_3_q[6];	// �ż�3�ܰ�켱ȣ���ܷ�
	char l_lvl_4_sign[1];	// �ż�4�ܰ��ȣ
	char l_lvl_4_prc[8];	// �ż�4�ܰ�켱ȣ������,��) 999999.99
	char l_lvl_4_q[6];	// �ż�4�ܰ�켱ȣ���ܷ�
	char l_lvl_5_sign[1];	// �ż�5�ܰ��ȣ
	char l_lvl_5_prc[8];	// �ż�5�ܰ�켱ȣ������,��) 999999.99
	char l_lvl_5_q[6];	// �ż�5�ܰ�켱ȣ���ܷ�
	char total_s_limit_ord_q[7];	// �ŵ���ȣ���ܷ�
	char s_lvl_1_sign[1];	// �ŵ�1�ܰ��ȣ
	char s_lvl_1_prc[8];	// �ŵ�1�ܰ�켱ȣ������,��) 999999.99
	char s_lvl_1_q[6];	// �ŵ�1�ܰ�켱ȣ���ܷ�
	char s_lvl_2_sign[1];	// �ŵ�2�ܰ��ȣ
	char s_lvl_2_prc[8];	// �ŵ�2�ܰ�켱ȣ������,��) 999999.99
	char s_lvl_2_q[6];	// �ŵ�2�ܰ�켱ȣ���ܷ�
	char s_lvl_3_sign[1];	// �ŵ�3�ܰ��ȣ
	char s_lvl_3_prc[8];	// �ŵ�3�ܰ�켱ȣ������,��) 999999.99
	char s_lvl_3_q[6];	// �ŵ�3�ܰ�켱ȣ���ܷ�
	char s_lvl_4_sign[1];	// �ŵ�4�ܰ��ȣ
	char s_lvl_4_prc[8];	// �ŵ�4�ܰ�켱ȣ������,��) 999999.99
	char s_lvl_4_q[6];	// �ŵ�4�ܰ�켱ȣ���ܷ�
	char s_lvl_5_sign[1];	// �ŵ�5�ܰ��ȣ
	char s_lvl_5_prc[8];	// �ŵ�5�ܰ�켱ȣ������,��) 999999.99
	char s_lvl_5_q[6];	// �ŵ�5�ܰ�켱ȣ���ܷ�
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
	char exp_prc_sign[1];	// ����ü�ᰡ�ݺ�ȣ,999.99 ���ϰ��ŸŽø� ����\n (����±����ڵ�:10,20,30,80)
	char exp_prc[8];	// ����ü�ᰡ��,��) 999999.99 ���ϰ��ŸŽø� ����\n (����±����ڵ�:10,20,30,80)
	char ff[1];	// End of Text,0xFF
} COM_FUT_LIMIT_ORD;


// ��ǰ����_ü��_�켱ȣ��
typedef struct _COM_FUT_EXEC_LIMIT_ORD {
	char data_clsf[2];	// DATA����,G7
	char info_clsf[2];	// ��������,01:��ǰ����
	char mrk_clsf[1];	// ���屸��,6
	char isin_clsf[12];	// �����ڵ�,*���߰��̵� ���� : �ű�ä���� �߰�\n 2010.10.25
	char stk_snr[3];	// �����Ϸù�ȣ
	char brd_id[2];	// ����ID,�ڵ尪��������
	char cur_prc_sign[1];	// ���簡�ݺ�ȣ
	char cur_price[8];	// ���簡��,��) 999999.99
	char exe_q[6];	// ü�����
	char ss_id[2];	// ����ID,�ڵ尪��������
	char exe_t[8];	// ü��ð�
	char rct_prd_prc[8];	// �ֱٿ���������������,��) 999999.99
	char nxt_prd_prc[8];	// ������������������,��) 999999.99
	char init_prc_sign[1];	// �ð���ȣ
	char init_prc[8];	// �ð�,��) 999999.99
	char high_prc_sign[1];	// ����ȣ
	char high_prc[8];	// ��,��) 999999.99
	char low_prc_sign[1];	// ������ȣ
	char low_prc[8];	// ����,��) 999999.99
	char pri_prc_sign[1];	// �������ݺ�ȣ
	char pri_prc[8];	// ��������,��) 999999.99
	char accm_exe_q[7];	// ����ü�����
	char accm_trd_amt[15];	// �����ŷ����(����:��)
	char accm_block_trd_exe_q[7];	// ���Ǵ뷮����ü�����,������(Filler)
	char efp_accm_exe_q[7];	// EFP����ü�����,������(Filler)
	char l_or_s[1];	// �����ŵ��ż������ڵ�,1:�ŵ�,2:�ż�(�������� ���� ȣ���� �ŵ��ż����а�)
	char total_l_limit_ord_q[7];	// �ż���ȣ���ܷ�
	char l_lvl_1_sign[1];	// �ż�1�ܰ��ȣ
	char l_lvl_1_prc[8];	// �ż�1�ܰ�켱ȣ������,��) 999999.99
	char l_lvl_1_q[6];	// �ż�1�ܰ�켱ȣ���ܷ�
	char l_lvl_2_sign[1];	// �ż�2�ܰ��ȣ
	char l_lvl_2_prc[8];	// �ż�2�ܰ�켱ȣ������,��) 999999.99
	char l_lvl_2_q[6];	// �ż�2�ܰ�켱ȣ���ܷ�
	char l_lvl_3_sign[1];	// �ż�3�ܰ��ȣ
	char l_lvl_3_prc[8];	// �ż�3�ܰ�켱ȣ������,��) 999999.99
	char l_lvl_3_q[6];	// �ż�3�ܰ�켱ȣ���ܷ�
	char l_lvl_4_sign[1];	// �ż�4�ܰ��ȣ
	char l_lvl_4_prc[8];	// �ż�4�ܰ�켱ȣ������,��) 999999.99
	char l_lvl_4_q[6];	// �ż�4�ܰ�켱ȣ���ܷ�
	char l_lvl_5_sign[1];	// �ż�5�ܰ��ȣ
	char l_lvl_5_prc[8];	// �ż�5�ܰ�켱ȣ������,��) 999999.99
	char l_lvl_5_q[6];	// �ż�5�ܰ�켱ȣ���ܷ�
	char total_s_limit_ord_q[7];	// �ŵ���ȣ���ܷ�
	char s_lvl_1_sign[1];	// �ŵ�1�ܰ��ȣ
	char s_lvl_1_prc[8];	// �ŵ�1�ܰ�켱ȣ������,��) 999999.99
	char s_lvl_1_q[6];	// �ŵ�1�ܰ�켱ȣ���ܷ�
	char s_lvl_2_sign[1];	// �ŵ�2�ܰ��ȣ
	char s_lvl_2_prc[8];	// �ŵ�2�ܰ�켱ȣ������,��) 999999.99
	char s_lvl_2_q[6];	// �ŵ�2�ܰ�켱ȣ���ܷ�
	char s_lvl_3_sign[1];	// �ŵ�3�ܰ��ȣ
	char s_lvl_3_prc[8];	// �ŵ�3�ܰ�켱ȣ������,��) 999999.99
	char s_lvl_3_q[6];	// �ŵ�3�ܰ�켱ȣ���ܷ�
	char s_lvl_4_sign[1];	// �ŵ�4�ܰ��ȣ
	char s_lvl_4_prc[8];	// �ŵ�4�ܰ�켱ȣ������,��) 999999.99
	char s_lvl_4_q[6];	// �ŵ�4�ܰ�켱ȣ���ܷ�
	char s_lvl_5_sign[1];	// �ŵ�5�ܰ��ȣ
	char s_lvl_5_prc[8];	// �ŵ�5�ܰ�켱ȣ������,��) 999999.99
	char s_lvl_5_q[6];	// �ŵ�5�ܰ�켱ȣ���ܷ�
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
	char real_t_high_prc_sign[1];	// �ǽð����Ѱ���ȣ
	char real_t_high_prc[8];	// �ǽð����Ѱ�,��) 999999.99 ���߰��̵�����
	char real_t_low_prc_sign[1];	// �ǽð����Ѱ���ȣ
	char real_t_low_prc[8];	// �ǽð����Ѱ�,��) 999999.99 ���߰��̵�����
	char ff[1];	// End of Text,0xFF
} COM_FUT_EXEC_LIMIT_ORD;


// ��ǰ����_���񸶰�
typedef struct _COM_FUT_CLOSE_PRODUCT {
	char data_clsf[2];	// DATA����,A6
	char info_clsf[2];	// ��������,01:��ǰ����
	char mrk_clsf[1];	// ���屸��,6
	char isin_clsf[12];	// �����ڵ�,*���߰��̵� ���� : �ű�ä���� �߰�\n 2010.10.25
	char stk_snr[3];	// �����Ϸù�ȣ
	char brd_id[2];	// ����ID,�ڵ尪��������
	char close_prc_sign[1];	// ������ȣ
	char close_prc[8];	// ����,* �ŷ��� ������ ��� ���ذ� set, ��) 999999.99
	char close_prc_code[1];	// ���������ڵ�,1:�Ǽ�, 3:�ŷ���\n 2:�⼼ -2012.05.14 ����\n ' ':�������� �ƴ� ��� space
	char accm_exe_q[7];	// ����ü�����
	char accm_trd_amt[15];	// �����ŷ����(����:��)
	char accm_block_trd_exe_q[7];	// ���Ǵ뷮����ü�����,������(Filler)
	char efp_accm_exe_q[7];	// EFP����ü�����,������(Filler)
	char total_l_limit_ord_q[7];	// �ż���ȣ���ܷ�
	char l_lvl_1_sign[1];	// �ż�1�ܰ��ȣ
	char l_lvl_1_prc[8];	// �ż�1�ܰ�켱ȣ������,��) 999999.99
	char l_lvl_1_q[6];	// �ż�1�ܰ�켱ȣ���ܷ�
	char l_lvl_2_sign[1];	// �ż�2�ܰ��ȣ
	char l_lvl_2_prc[8];	// �ż�2�ܰ�켱ȣ������,��) 999999.99
	char l_lvl_2_q[6];	// �ż�2�ܰ�켱ȣ���ܷ�
	char l_lvl_3_sign[1];	// �ż�3�ܰ��ȣ
	char l_lvl_3_prc[8];	// �ż�3�ܰ�켱ȣ������,��) 999999.99
	char l_lvl_3_q[6];	// �ż�3�ܰ�켱ȣ���ܷ�
	char l_lvl_4_sign[1];	// �ż�4�ܰ��ȣ
	char l_lvl_4_prc[8];	// �ż�4�ܰ�켱ȣ������,��) 999999.99
	char l_lvl_4_q[6];	// �ż�4�ܰ�켱ȣ���ܷ�
	char l_lvl_5_sign[1];	// �ż�5�ܰ��ȣ
	char l_lvl_5_prc[8];	// �ż�5�ܰ�켱ȣ������,��) 999999.99
	char l_lvl_5_q[6];	// �ż�5�ܰ�켱ȣ���ܷ�
	char total_s_limit_ord_q[7];	// �ŵ���ȣ���ܷ�
	char s_lvl_1_sign[1];	// �ŵ�1�ܰ��ȣ
	char s_lvl_1_prc[8];	// �ŵ�1�ܰ�켱ȣ������,��) 999999.99
	char s_lvl_1_q[6];	// �ŵ�1�ܰ�켱ȣ���ܷ�
	char s_lvl_2_sign[1];	// �ŵ�2�ܰ��ȣ
	char s_lvl_2_prc[8];	// �ŵ�2�ܰ�켱ȣ������,��) 999999.99
	char s_lvl_2_q[6];	// �ŵ�2�ܰ�켱ȣ���ܷ�
	char s_lvl_3_sign[1];	// �ŵ�3�ܰ��ȣ
	char s_lvl_3_prc[8];	// �ŵ�3�ܰ�켱ȣ������,��) 999999.99
	char s_lvl_3_q[6];	// �ŵ�3�ܰ�켱ȣ���ܷ�
	char s_lvl_4_sign[1];	// �ŵ�4�ܰ��ȣ
	char s_lvl_4_prc[8];	// �ŵ�4�ܰ�켱ȣ������,��) 999999.99
	char s_lvl_4_q[6];	// �ŵ�4�ܰ�켱ȣ���ܷ�
	char s_lvl_5_sign[1];	// �ŵ�5�ܰ��ȣ
	char s_lvl_5_prc[8];	// �ŵ�5�ܰ�켱ȣ������,��) 999999.99
	char s_lvl_5_q[6];	// �ŵ�5�ܰ�켱ȣ���ܷ�
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
	char ff[1];	// End of Text,0xFF
} COM_FUT_CLOSE_PRODUCT;


// ��ǰ����_��TS
typedef struct _COM_FUT_MRK_OP_TS {
	char data_clsf[2];	// DATA����,A7
	char info_clsf[2];	// ��������,01:��ǰ����
	char mrk_clsf[1];	// ���屸��,6
	char isin_clsf[12];	// �����ڵ�
	char stk_snr[3];	// �����Ϸù�ȣ
	char prd_id[11];	// ��ǰID,�ڵ尪�������� : spaceó��
	char brd_id[2];	// ����ID,�ڵ尪��������
	char brd_event_id[3];	// �����̺�ƮID,�ڵ尪��������
	char brd_event_start_t[8];	// �����̺�Ʈ���۽ð�,������ �����(��:BB1(�ŸŰŷ�����)�� ��� 09000000)
	char brd_event_code[5];	// �����̺�Ʈ���뱺�ڵ�,�ڵ尪���� ����
	char ss_id[2];	// ����ID,�ڵ尪��������
	char ord_exist[1];	// ȣ������,0:ȣ������(�����׸� ����), 1:ȣ������(�����׸� ���)
	char total_l_limit_ord_q[7];	// �ż���ȣ���ܷ�
	char l_lvl_1_sign[1];	// �ż�1�ܰ��ȣ
	char l_lvl_1_prc[8];	// �ż�1�ܰ�켱ȣ������,��) 999999.99
	char l_lvl_1_q[6];	// �ż�1�ܰ�켱ȣ���ܷ�
	char l_lvl_2_sign[1];	// �ż�2�ܰ��ȣ
	char l_lvl_2_prc[8];	// �ż�2�ܰ�켱ȣ������,��) 999999.99
	char l_lvl_2_q[6];	// �ż�2�ܰ�켱ȣ���ܷ�
	char l_lvl_3_sign[1];	// �ż�3�ܰ��ȣ
	char l_lvl_3_prc[8];	// �ż�3�ܰ�켱ȣ������,��) 999999.99
	char l_lvl_3_q[6];	// �ż�3�ܰ�켱ȣ���ܷ�
	char l_lvl_4_sign[1];	// �ż�4�ܰ��ȣ
	char l_lvl_4_prc[8];	// �ż�4�ܰ�켱ȣ������,��) 999999.99
	char l_lvl_4_q[6];	// �ż�4�ܰ�켱ȣ���ܷ�
	char l_lvl_5_sign[1];	// �ż�5�ܰ��ȣ
	char l_lvl_5_prc[8];	// �ż�5�ܰ�켱ȣ������,��) 999999.99
	char l_lvl_5_q[6];	// �ż�5�ܰ�켱ȣ���ܷ�
	char total_s_limit_ord_q[7];	// �ŵ���ȣ���ܷ�
	char s_lvl_1_sign[1];	// �ŵ�1�ܰ��ȣ
	char s_lvl_1_prc[8];	// �ŵ�1�ܰ�켱ȣ������,��) 999999.99
	char s_lvl_1_q[6];	// �ŵ�1�ܰ�켱ȣ���ܷ�
	char s_lvl_2_sign[1];	// �ŵ�2�ܰ��ȣ
	char s_lvl_2_prc[8];	// �ŵ�2�ܰ�켱ȣ������,��) 999999.99
	char s_lvl_2_q[6];	// �ŵ�2�ܰ�켱ȣ���ܷ�
	char s_lvl_3_sign[1];	// �ŵ�3�ܰ��ȣ
	char s_lvl_3_prc[8];	// �ŵ�3�ܰ�켱ȣ������,��) 999999.99
	char s_lvl_3_q[6];	// �ŵ�3�ܰ�켱ȣ���ܷ�
	char s_lvl_4_sign[1];	// �ŵ�4�ܰ��ȣ
	char s_lvl_4_prc[8];	// �ŵ�4�ܰ�켱ȣ������,��) 999999.99
	char s_lvl_4_q[6];	// �ŵ�4�ܰ�켱ȣ���ܷ�
	char s_lvl_5_sign[1];	// �ŵ�5�ܰ��ȣ
	char s_lvl_5_prc[8];	// �ŵ�5�ܰ�켱ȣ������,��) 999999.99
	char s_lvl_5_q[6];	// �ŵ�5�ܰ�켱ȣ���ܷ�
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
	char real_t_high_prc_sign[1];	// �ǽð����Ѱ���ȣ
	char real_t_high_prc[8];	// �ǽð����Ѱ�,��) 999999.99 ���߰��̵�����
	char real_t_low_prc_sign[1];	// �ǽð����Ѱ���ȣ
	char real_t_low_prc[8];	// �ǽð����Ѱ�,��) 999999.99 ���߰��̵�����
	char ff[1];	// End of Text,0xFF
} COM_FUT_MRK_OP_TS;


// ��ǰ����_����
typedef struct _COM_FUT_CLOSE {
	char data_clsf[2];	// DATA����,H0
	char info_clsf[2];	// ��������,01:��ǰ����
	char mrk_clsf[1];	// ���屸��,6
	char ff[1];	// End of Text,0xFF
} COM_FUT_CLOSE;


// ��ǰ����_�������ٰ���
typedef struct _COM_FUT_MRK_OP_SCHD {
	char data_clsf[2];	// DATA����,M4
	char info_clsf[2];	// ��������,01:��ǰ����
	char mrk_clsf[1];	// ���屸��,6
	char isin_clsf[12];	// �����ڵ�,*�������� �� ��ġ�� ���
	char stk_snr[3];	// �����Ϸù�ȣ,*�������� �� ��ġ�� ���
	char prd_id[11];	// ��ǰID,�ڵ尪�������� : spaceó��
	char mrk_prd_id[3];	// ����ǰ�׷�ID,*�ڵ尪��������
	char brd_id[2];	// ����ID,�ڵ尪��������
	char brd_event_id[3];	// �����̺�ƮID,�ڵ尪��������
	char brd_event_start_t[8];	// �����̺�Ʈ���۽ð�
	char brd_event_code[5];	// �����̺�Ʈ���뱺�ڵ�,�ڵ尪���� ����
	char ss_open_close_code[2];	// ���ǰ��������ڵ�,BS:���尳��\n BE:��������\n SS:���ǰ���\n SE:��������\n SH:��������\n SR:�����簳
	char ss_id[2];	// ����ID,�ڵ尪��������
	char adj_stage[2];	// ����ܰ�,�ش���׾���
	char under_asset_prc_chg[1];	// �������񰡰�Ȯ��߻��ڵ�,�ش���׾���
	char exp_prc_chg_t[8];	// ����Ȯ�뿹���ð�,�ش���׾���
	char ff[1];	// End of Text,0xFF
} COM_FUT_MRK_OP_SCHD;


// ��ǰ����_�������
typedef struct _COM_FUT_DIST_INFO {
	char data_clsf[2];	// DATA����,O6
	char info_clsf[2];	// ��������,01:��ǰ����
	char mrk_clsf[1];	// ���屸��,6
	char isin_clsf[12];	// �����ڵ�
	char stk_snr[3];	// �����Ϸù�ȣ
	char brd_id[2];	// ����ID,�ڵ尪��������
	char dist_adj_code[1];	// ������뱸���ڵ�,1:��а���, 2:�������
	char dist_code[1];	// ���ó�������ڵ�,1:�ż�����, 2:�ż�����,\n 3:�ŵ�����, 4:�ŵ�����\n *��������� �ڵ����(spaceó��)
	char dist_cls_t[8];	// ��������ð�
	char ff[1];	// End of Text,0xFF
} COM_FUT_DIST_INFO;


// ��ǰ����_�ǽð������Ѱ� ���������
typedef struct _COM_FUT_REAL_HIGH_LOW_LIMIT_ON_OFF {
	char data_clsf[2];	// DATA����,Q2
	char info_clsf[2];	// ��������,01:��ǰ����
	char mrk_clsf[1];	// ���屸��,6
	char isin_clsf[12];	// �����ڵ�
	char stk_snr[3];	// �����Ϸù�ȣ
	char brd_id[2];	// ����ID,�ڵ尪��������
	char cleared_t[8];	// ó���ð�
	char real_t_prc_limit_code[1];	// �ǽð��������Ѽ����ڵ�,0: ����, 1: ����, 2: �缳��
	char real_t_high_prc_sign[1];	// �ǽð����Ѱ���ȣ
	char real_t_high_prc[8];	// �ǽð����Ѱ�,��) 999999.99 ���߰��̵�����
	char real_t_low_prc_sign[1];	// �ǽð����Ѱ���ȣ
	char real_t_low_prc[8];	// �ǽð����Ѱ�,��) 999999.99 ���߰��̵�����
	char ff[1];	// End of Text,0xFF
} COM_FUT_REAL_HIGH_LOW_LIMIT_ON_OFF;


// ��ǰ����_�̰����������� ������
typedef struct _COM_FUT_OPEN_INTEREST_DATA {
	char data_clsf[2];	// DATA����,H2
	char info_clsf[2];	// ��������,01:��ǰ����
	char mrk_clsf[1];	// ���屸��,6
	char isin_clsf[12];	// �����ڵ�,���� record '999999999999' set\n*���߰��̵� ���� : �ű�ä���� �߰�
	char stk_snr[3];	// ����SEQ
	char open_interest_clsf[2];	// �̰�����������,���� Ȯ�� : "M0" (07:40�а� ����)\n���� ���� : "M1" (���� Ư���������� ��������\n         �۽�, 10��)\n���� Ȯ�� : "M2" (���� ������ �۽�,\n         ������ 1�ð��� ����)
	char traded_date[8];	// �ŷ�����
	char open_interest_q[9];	// �̰�����������,����:���
	char ff[1];	// End of Text,0xFF
} COM_FUT_OPEN_INTEREST_DATA;


// ��ǰ����_���갡�� ������
typedef struct _COM_FUT_SETT_PRC_DATA {
	char data_clsf[2];	// DATA����,H3
	char info_clsf[2];	// ��������,01:��ǰ����
	char mrk_clsf[1];	// ���屸��,6
	char isin_clsf[12];	// �����ڵ�,���� record '999999999999' set\n*���߰��̵� ���� : �ű�ä���� �߰�
	char stk_snr[3];	// ����SEQ,�������� - �����ŷ����� ���� ������ 0���� ����
	char calc_prc[16];	// ���갡��,�������� - �����ŷ����� ���� ������ 0���� ����\n��) 99999999.99999999
	char calc_prc_clsf[1];	// ���갡�ݱ���,�������� - �����ŷ����� ���� ������ �������� ����\n0 : ���갡 ����(���� �ŷ������� �⼼ ����)\n1 : ���� ����(�Ǽ�)\n2 : ���� �⼼(���� �ŷ������� �⼼) - 2010.12.20 ����\n3 : ���� ���갡(���� �ŷ������� ���� ������) - 2010.12.20 ����\n4 : ���� �̷а�(���� �ŷ������� ���� ������)\n5 : ��������ŷ��� ���� ������ ������ ���� - 2010.12.20 ����\n6 : ������ ���� ���갡 - 2010.12.20 ����\n7 : ����ڻ� ����(�̷а����»�ǰ)\n8 : ������ذ��� - 2010.12.20 �߰�
	char final_sett_prc[16];	// ������������,��) 99999999.99999999
	char final_sett_clsf[1];	// �����������ݱ���
	char ff[1];	// End of Text,0xFF
} COM_FUT_SETT_PRC_DATA;


// ��ǰ����_������ ������
typedef struct _COM_FUT_INVESTOR_DATA {
	char data_clsf[2];	// DATA����,H1
	char info_clsf[2];	// ��������,01:��ǰ����
	char mrk_clsf[1];	// ���屸��,6
	char created_date[8];	// ��������
	char created_time[6];	// �����ð�
	char inv_data_clsf[2];	// �����ͱ���,*����Ȯ�� : 00, �������� : 01, ����Ȯ�� : 02\n *E1 : ���� ������ �Ϸ�, E2 : Ȯ�� ������ �Ϸ�\n ���� record '99' set
	char prd_id[11];	// ��ǰID,�ڵ尪��������
	char inv_clsf[4];	// ����������,�ڵ尪���� ���� *�ڵ� '7000'�� ����,��������׸� 0���� ����
	char long_exe_q[9];	// �ż���������
	char short_exe_q[9];	// �ŵ���������
	char long_traded_amt[18];	// �ż��������
	char short_traded_amt[18];	// �ŵ��������
	char spread_long_exe_q[9];	// �������忡 ���� ������ �ż� ��������
	char spread_short_exe_q[9];	// �������忡 ���� ������ �ŵ� ��������
	char spread_long_traded_amt[18];	// �������忡 ���� ������ �ż� �������
	char spread_short_traded_amt[18];	// �������忡 ���� ������ �ŵ� �������
	char ff[1];	// End of Text,0xFF
} COM_FUT_INVESTOR_DATA;


// ��ǰ����_�ü�Recovery ������
typedef struct _COM_FUT_RECOVERY_DATA {
	char data_clsf[2];	// DATA����,B2
	char info_clsf[2];	// ��������,01:��ǰ����
	char mrk_clsf[1];	// ���屸��,6
	char isin_clsf[12];	// �����ڵ�,*���߰��̵� ���� : �ű�ä���� �߰�
	char stk_snr[3];	// �����Ϸù�ȣ
	char cur_prc_sign[1];	// SIGN ��ȣ
	char cur_prc[8];	// ���簡,��) 999999.99
	char rct_prd_prc[8];	// �ֱٿ���������������,��) 999999.99
	char nxt_prd_prc[8];	// ������������������,��) 999999.99
	char init_prc_sign[1];	// �ð���ȣ
	char init_prc[8];	// �ð�,��) 999999.99
	char high_prc_sign[1];	// ����ȣ
	char high_prc[8];	// ��,��) 999999.99
	char low_prc_sign[1];	// ������ȣ
	char low_prc[8];	// ����,��) 999999.99
	char open_interest_q[9];	// �̰�����
	char accm_exe_q[7];	// ����ü�����
	char accm_trd_amt[15];	// �����ŷ����,����:��
	char accm_block_trd_exe_q[7];	// ���Ǵ뷮����ü�����,������(Filler)
	char l_or_s[1];	// �����ŵ��ż������ڵ�,1:�ŵ�,2:�ż�(�������� ���� ȣ���� �ŵ��ż����а�)
	char s_lvl_1_sign[1];	// �ŵ�1ȣ����ȣ
	char s_lvl_1_prc[8];	// �ŵ�1ȣ��,��) 999999.99
	char s_lvl_1_q[6];	// �ŵ�1ȣ������
	char s_lvl_1_trd_cnt[4];	// �ŵ�1ȣ���Ǽ�
	char l_lvl_1_sign[1];	// �ż�1ȣ����ȣ
	char l_lvl_1_prc[8];	// �ż�1ȣ��,��) 999999.99
	char l_lvl_1_q[6];	// �ż�1ȣ������
	char l_lvl_1_trd_cnt[4];	// �ż�1ȣ���Ǽ�
	char s_lvl_2_sign[1];	// �ŵ�2ȣ����ȣ
	char s_lvl_2_prc[8];	// �ŵ�2ȣ��,��) 999999.99
	char s_lvl_2_q[6];	// �ŵ�2ȣ������
	char s_lvl_2_trd_cnt[4];	// �ŵ�2ȣ���Ǽ�
	char l_lvl_2_sign[1];	// �ż�2ȣ����ȣ
	char l_lvl_2_prc[8];	// �ż�2ȣ��,��) 999999.99
	char l_lvl_2_q[6];	// �ż�2ȣ������
	char l_lvl_2_trd_cnt[4];	// �ż�2ȣ���Ǽ�
	char s_lvl_3_sign[1];	// �ŵ�3ȣ����ȣ
	char s_lvl_3_prc[8];	// �ŵ�3ȣ��,��) 999999.99
	char s_lvl_3_q[6];	// �ŵ�3ȣ������
	char s_lvl_3_trd_cnt[4];	// �ŵ�3ȣ���Ǽ�
	char l_lvl_3_sign[1];	// �ż�3ȣ����ȣ
	char l_lvl_3_prc[8];	// �ż�3ȣ��,��) 999999.99
	char l_lvl_3_q[6];	// �ż�3ȣ������
	char l_lvl_3_trd_cnt[4];	// �ż�3ȣ���Ǽ�
	char s_lvl_4_sign[1];	// �ŵ�4ȣ����ȣ
	char s_lvl_4_prc[8];	// �ŵ�4ȣ��,��) 999999.99
	char s_lvl_4_q[6];	// �ŵ�4ȣ������
	char s_lvl_4_trd_cnt[4];	// �ŵ�4ȣ���Ǽ�
	char l_lvl_4_sign[1];	// �ż�4ȣ����ȣ
	char l_lvl_4_prc[8];	// �ż�4ȣ��,��) 999999.99
	char l_lvl_4_q[6];	// �ż�4ȣ������
	char l_lvl_4_trd_cnt[4];	// �ż�4ȣ���Ǽ�
	char s_lvl_5_sign[1];	// �ŵ�5ȣ����ȣ
	char s_lvl_5_prc[8];	// �ŵ�5ȣ��,��) 999999.99
	char s_lvl_5_q[6];	// �ŵ�5ȣ������
	char s_lvl_5_trd_cnt[4];	// �ŵ�5ȣ���Ǽ�
	char l_lvl_5_sign[1];	// �ż�5ȣ����ȣ
	char l_lvl_5_prc[8];	// �ż�5ȣ��,��) 999999.99
	char l_lvl_5_q[6];	// �ż�5ȣ������
	char l_lvl_5_trd_cnt[4];	// �ż�5ȣ���Ǽ�
	char total_s_limit_ord_q[7];	// �ŵ� ��ȣ������
	char total_s_trd_cnt[5];	// �ŵ���ȿȣ���Ǽ�
	char total_l_limit_ord_q[7];	// �ż� ��ȣ������
	char total_l_trd_cnt[5];	// �ż���ȿȣ���Ǽ�
	char ss_id[2];	// ����ID,�ڵ尪��������
	char brd_id[2];	// ����ID,�ڵ尪��������
	char brd_event_id[3];	// �����̺�ƮID,B2 ������ �����̺�ƮID ������(���� ���°��� ���۵� �� ����). ����, �ش� �׸� '000' ���� ����. 2014.03.24)
	char exp_prc_sign[1];	// ����ü�ᰡ�ݺ�ȣ,���ϰ��ŸŽø� ����\n (����±����ڵ�:10,20,30,80)
	char exp_prc[8];	// ����ü�ᰡ��,��) 999999.99 ���ϰ��ŸŽø� ����\n (����±����ڵ�:10,20,30,80)
	char real_t_high_prc_sign[1];	// �ǽð����Ѱ���ȣ
	char real_t_high_prc[8];	// �ǽð����Ѱ�,��) 999999.99 ���߰��̵�����
	char real_t_low_prc_sign[1];	// �ǽð����Ѱ���ȣ
	char real_t_low_prc[8];	// �ǽð����Ѱ�,��) 999999.99 ���߰��̵�����
	char ff[1];	// End of Text,0xFF
} COM_FUT_RECOVERY_DATA;


// ��ǰ����_�������� ������
typedef struct _COM_FUTRE_PRD_INFO_DATA {
	char data_clsf[2];	// DATA����,A0
	char info_clsf[2];	// ��������,01:��ǰ����
	char mrk_clsf[1];	// ���屸��,6
	char prd_cnt[5];	// �����
	char trd_date[8];	// ��������(��ȸ����)
	char isin_clsf[12];	// �����ڵ�,���� record '999999999999' set\n*���߰��̵� ���� : �ű�ä���� �߰�
	char stk_snr[6];	// ����SEQ
	char prd_id[11];	// ��ǰID,* �ڵ尪 ������ ����\n* ����Ī: �Ļ���ǰID\n10 => 11, 20140303
	char sh_prd_code[9];	// ��������ڵ�,��) KR4101C90009 �� K101C9000
	char prd_name_kor[80];	// �����ѱ۸�
	char sh_prd_name_kor[40];	// �����ѱ۾��
	char prd_name_eng[80];	// ���񿵹���
	char sh_prd_name_eng[40];	// ���񿵹����
	char listing_date[8];	// ��������,*���߰��̵� �����߰�    2009.08.31
	char de_listing_date[8];	// ������������
	char spread_clsf_code[1];	// ��������������񱸺��ڵ�,���������� ������ �Ǵ� ������ ISIN ǥ���ڵ�\n--�ڵ尪--\nF: ������(�ð���������)\nN: �ٿ���(�ð���������)\n20140303
	char final_sett_code[1];	// ������������ڵ�,���ݰ���, �ǹ��μ������� �� �Ļ���ǰ�� �������� ���\n--�ڵ尪--\nC: ���ݰ���\nD: �ǹ��μ�������\nA: ����+�ǹ��μ�������\n0: �ش����\n20140303
	char prc_limit_exp_dir[1];	// ��������Ȯ����������ڵ�,���������� �ٴܰ�� ���ǵǴ� ��� ���� �ܰ�� Ȯ��Ǵ� ����� ������ �� Ȯ�븦 �����ϴ� ����\n## �ڵ尪##\nX:������\nF:������\nB:������\nT:�����
	char prc_limit_final_stg[3];	// �������������ܰ�,���������� �ٴܰ�� ���ǵǴ� ��� ������ �����ܰ��ȣ
	char prc_limit_stg_1_hgh_sign[1];	// ��������1�ܰ�SIGN��ȣ
	char prc_limit_stg_1_high_prc[12];	// ��������1�ܰ���Ѱ�,��) 9999999999.99
	char prc_limit_stg_1_low_sign[1];	// ��������1�ܰ�SIGN��ȣ
	char prc_limit_stg_1_low_prc[12];	// ��������1�ܰ����Ѱ�,��) 9999999999.99
	char prc_limit_stg_2_high_sign[1];	// ��������2�ܰ�SIGN��ȣ
	char prc_limit_stg_2_high_prc[12];	// ��������2�ܰ���Ѱ�,��) 9999999999.99
	char prc_limit_stg_2_low_sign[1];	// ��������2�ܰ�SIGN��ȣ
	char prc_limit_stg_2_low_prc[12];	// ��������2�ܰ����Ѱ�,��) 9999999999.99
	char prc_limit_stg_3_high_sign[1];	// ��������3�ܰ�SIGN��ȣ
	char prc_limit_stg_3_high_prc[12];	// ��������3�ܰ���Ѱ�,��) 9999999999.99
	char prc_limit_stg_3_low_sign[1];	// ��������3�ܰ�SIGN��ȣ
	char prc_limit_stg_3_low_prc[12];	// ��������3�ܰ����Ѱ�,��) 9999999999.99
	char stand_prc[12];	// ���ذ�,��) 9999999999.99
	char under_asset_id[3];	// �����ڻ�ID,��) K2I:KOSPI200����, KQI:�ڽ���150����,\n   Sxx:�����ֽ�, BM3:��3�ⱹä,\n   BM5:��5�ⱹä, BMA:��10�ⱹä, \n   CDR:CD, USD:�̱��޷�, JPY:�Ϻ���,\n   EUR:��������,\n   GLD:��, LHG:����\n20140303
	char opt_type_code[1];	// �Ǹ���������ڵ�,A:�̱���,E:������,B:���´���,Z:��Ÿ\n20140303
	char spread_str_code[2];	// �������屸���ڵ�,Combination ȣ���� ��ü�� �������幰�� ���񱸼�.\n--�ڵ尪--\n- T1: �ֱٿ���+2°����\n      > T2, T3, T4, ...\n*����Ī: �������������ڵ�\n20140303
	char spread_prd_code_1[12];	// �������屸�������ڵ�1,* ����Ī: ��������ٿ��� �����ڵ�\n�ٿ��� ǥ���ڵ�\n20140303
	char spread_prd_code_2[12];	// �������屸�������ڵ�2,* ����Ī : ������������� �����ڵ�\n������ ǥ���ڵ�\n20140303
	char last_trading_date[8];	// �����ŷ�����
	char final_sett_date[8];	// ������������
	char cont_month_nbr[3];	// ��������ȣ,* ����Ī: ���������ڵ�\n1:�ֱٿ���,������������\n2:2°����\n3:3°����\n4:4°����\n5:5°����\n6:6°����\n7:7°����      �� �ֱٿ������� ��ġ\nX => 9, 1 => 3, 20140303
	char maturity_date[8];	// ��������,�Ǹ���� ������ ��������
	char exe_prc[17];	// ��簡��,��) 999999999.99999999
	char adjust_clsf_code[1];	// ���������ڵ�,�����ڻ��� ���ذ��� ������ ����� ����(�̰�������)���� ������� ����(�ŷ��¼�����)������ ����\n--�ڵ尪--\nN: ����\nO: �̰�������\nC: �ŷ��¼�����\n20140303
	char prd_unit[17];	// �ŷ�����,1��࿡ �ش��ϴ� �����ڻ����\n��) 999999999.99999999
	char multiplier[21];	// �ŷ��¼�,������� �� ������ ����ϴ� ���¼�\n��) 9999999999999.99999999
	char mrk_cnst_code[1];	// �������������ڵ�,0:�̽�����������\n1:���Ͻ�����������\n2:���Ž�����������
	char listing_type_code[1];	// ���������ڵ�,1:�űԻ���\n2:�߰�����\n3:��������\n4:���ʻ���\n5:��������\n6:Ư������
	char atm_prc[12];	// ���,�����ڻ���ذ��ݿ� ���� ����� ��簡��\n��) 9999999999.99
	char adj_reason_code[2];	// ���������ڵ�,00:�ش���׾���, 01:�Ǹ���, 02:����,\n03:�й��, 04:�ǹ��, 05:�߰�����,\n06:�Ǹ��߰�����, 99:��Ÿ
	char under_asset_prd_code[12];	// �����ڻ������ڵ�
	char under_asset_close_prc[12];	// �����ڻ�����,��) 9999999999.99
	char left_until_maturity[7];	// �����ϼ�
	char adj_std_prc[17];	// �������ذ���,�ֽ��Ļ���ǰ�� �����ֱ� �������ذ���\n��) 999999999.99999999
	char std_prc_clsf_code[2];	// ���ذ��ݱ����ڵ�,*����\nspcace:���ذ� ����(���� ������������)\n11:�������갡\n12:���ϱ��ذ�(�ŷ������� ����������)\n13:�����̷а�(�ŷ������� ����������)\n14:���ϱ⼼(�ŷ������� �⼼����)\n  -2012.05.14 ����\n15:�����̷а�(�ŷ������� �⼼����)-\n  -2012.05.14 ����\n16:������ �������갡\n17:������ ���ϱ��ذ�\n  (�ŷ������� ����������)\n18:������ ���ϱ⼼(�ŷ������� �⼼����)\n  -2012.05.14 ����\n19:���� ����ڻ� ����(�̷а����� ��ǰ)\n*�ɼ�\n21:�������űݱ��ذ�\n22:���ϱ��ذ�(�ŷ������� ����������)\n23:�����̷а�(�ŷ������� ����������)\n24:���ϱ⼼(�ŷ������� �⼼����)\n  -2012.05.14 ����\n25:������ �������űݱ��ذ�\n26:������ ���ϱ��ذ�\n  (�ŷ������� ����������)\n27:������ ���ϱ⼼(�ŷ������� �⼼����)\n  -2012.05.14 ����
	char trd_std_prc_clsf_code[1];	// �Ÿſ���ذ��ݱ����ڵ�,0:�ش����\n1:�Ǽ�\n2:�⼼\n3:�̷а�\n4:����ڻ�����\n*���߰��̵� �����߰�    2009.08.31
	char yest_adj_close_prc_sign[1];	// SIGN��ȣ
	char yest_adj_close_prc[17];	// ������������,�ֽ��Ļ���ǰ�� ��������\n��) 999999999.99999999
	char block_trd_clsf[1];	// ���Ǵ뷮�ŸŴ�󿩺�,Y:���ǸŸŻ�ǰ, N:���ƴ�\n����ǰ��:3�⹰��ä����, �̱��޷�����,\n      ���μ���, ������
	char yest_mrg_std_prc[17];	// �������űݱ��ذ���,��) 999999999.99999999
	char yest_mrg_std_prc_clsf_code[2];	// �������űݱ��ذ��ݱ����ڵ�,*�ɼ�\n20:���ű� ���ذ� ����\n21:��������(�Ǽ�)\n22:���ϱ⼼(�ŷ������ı⼼)\n  -2012.05.14 ����\n23:�������űݱ��ذ�\n  (�ŷ������� ����������)\n  -2012.05.14 ����\n24:�����̷а�(�ŷ������� ����������)\n25:�����������űݱ��ذ�\n  (�ŷ������� ����������)\n  -2012.05.14 ����
	char sett_theory_prc[15];	// �����̷а���,�ؿɼ��� ��� ���űݱ��ذ��� \n��) 999999999.999999
	char std_theory_prc[15];	// �����̷а���,��) 999999999.999999
	char yest_sett_prc[17];	// �������갡��,��) 999999999.99999999
	char halt_trd_clsf[1];	// �ŷ���������,Y, N
	char ft_cb_high_prc[12];	// ����Circuit_Breakers���Ѱ�,���� CB �ߵ������� �Ǵ��ϱ� ���� ����\n����(���ذ���� +/-5%�� CB �ߵ�\n������ ��� +5%�� ����� ����)\n��) 99+F31499999999.99
	char ft_cb_low_prc[12];	// ����Circuit_Breakers���Ѱ�,���� CB �ߵ������� �Ǵ��ϱ� ���� ����\n����(���ذ���� +/-5%�� CB �ߵ�\n������ ��� -5%�� ����� ����)\n��) 9999999999.99
	char check_exe_prc[17];	// ��ȸ����簡��,��) 999999999.99999999
	char atm_clsf[1];	// ATM�����ڵ�,0:����, 1:ATM, 2:ITM, 3:OTM
	char last_trading_clsf[1];	// �����ŷ��Ͽ���,Y, N
	char ex_divid_aft_value[15];	// �����Ĺ�簡ġ,�ֽ� �� �ְ����� ��ǰ���� �����\n- ���� : �����Ĺ̷���ġ\n- �ɼ� : ���������簡ġ\n��) 999999999.999999
	char yest_close_prc_sign[1];	// SIGN��ȣ
	char yest_close_prc[12];	// ��������,��) 9999999999.99
	char yest_close_prc_clsf[1];	// �������������ڵ�,1:�Ǽ�, 3:�ŷ���\n2:�⼼ -2012.05.14 ����
	char yest_init_prc_sign[1];	// SIGN��ȣ
	char yest_init_prc[12];	// ���Ͻð�,��) 9999999999.99
	char yest_high_prc_sign[1];	// SIGN��ȣ
	char yest_high_pric[12];	// ���ϰ�,��) 9999999999.99
	char yest_low_prc_sign[1];	// SIGN��ȣ
	char yest_low_prc[12];	// ��������,��) 9999999999.99
	char yest_first_exe_date[8];	// ����ü������
	char yest_last_exe_time[8];	// ��������ü��ð�
	char yest_sett_prc_clsf[2];	// �������갡�ݱ���,*����\n 10:���갡����\n 11:��������(�Ǽ�)\n 12:���ϱ⼼(�ŷ������ı⼼) - 2010.12.20 ����\n 13:�������갡(�ŷ������� ����������) - 2010.12.20 ����\n 14:�����̷а�(�ŷ������� ����������)\n 15:��������� ���� - 2010.12.20 ����\n 16:������ ���� ���갡 - 2010.12.20 ����\n 17:����ڻ� ����(�̷а����� ��ǰ)\n 18:������ذ��� - 2010.12.20 �߰�
	char sett_prc_theory_prc_diff_pctg_sign[1];	// SIGN��ȣ
	char sett_prc_theory_prc_diff_pctg[12];	// ���갡���̷а��ݱ�����,��) 999999.999999
	char yest_open_interest_q[10];	// ���Ϲ̰�����������
	char yest_s_limit_ord_prc_sign[1];	// SIGN��ȣ
	char yest_s_limit_ord_prc[12];	// ���ϸŵ��켱ȣ������,��) 9999999999.99
	char yest_l_limit_ord_prc_sign[1];	// SIGN��ȣ
	char yest_l_limit_ord_prc[12];	// ���ϸż��켱ȣ������,��) 9999999999.99
	char implied_vol[10];	// ���纯����,��) 999999.9999
	char listed_high_prc_sign[1];	// SIGN��ȣ
	char listed_high_prc[12];	// �������ְ�,��) 9999999999.99
	char listed_low_prc_sign[1];	// SIGN��ȣ
	char listed_low_prc[12];	// ������������,��) 9999999999.99
	char year_high_prc_sign[1];	// SIGN��ȣ
	char year_high_prc[12];	// �����ְ�,��) 9999999999.99
	char year_low_prc_sign[1];	// SIGN��ȣ
	char year_low_prc[12];	// ����������,��) 9999999999.99
	char listed_high_prc_date[8];	// �������ְ�����
	char listed_low_prc_date[8];	// ����������������
	char year_high_prc_date[8];	// �����ְ�����
	char year_low_prc_date[8];	// ��������������
	char year_std_date[8];	// ���������ϼ�
	char month_trd_date[8];	// �����ŷ��ϼ�
	char year_trd_date[8];	// �����ŷ��ϼ�
	char yest_exe_trd_cnt [16];	// ����ü��Ǽ�
	char yest_exe_q[12];	// ����ü�����,�������Ǵ뷮�Ÿ�ü������� ���Ե��� ����
	char yest_trd_amt[22];	// ���ϰŷ����,�������Ǵ뷮�ŸŰŷ������ ���Ե��� ����
	char yest_block_trd_exe_q[12];	// �������Ǵ뷮�ջ�ü�����,�������Ǵ뷮�Ÿ�ü����� => �������Ǵ뷮�ջ�ü����� [����ü�����+�������Ǵ뷮�Ÿ�ü�����(���Ǵ뷮+FLEX)] 2016.03.28 ����
	char yest_block_trd_total_amt[22];	// �������Ǵ뷮�ջ�ŷ����,�������Ǵ뷮�ŸŰŷ���� => �������Ǵ뷮�ջ�ŷ���� [���ϰŷ����+�������Ǵ뷮�ŸŰŷ����(���Ǵ뷮+FLEX)] 2016.03.28 ����
	char cd_rate[6];	// CD�ݸ�,��) 999.999
	char open_interest_q[15];	// �̰����ѵ�����,*�����Ͽ� ����Ǵ� ��ǰ�� ���º�\n �̰��� �ѵ� ����. �̰��� �ѵ���\n ������� ���� ��ǰ�� 0\n*�ֽļ������� �ش�\n8 => 15, 20140303
	char product_cat[4];	// �Ҽ� ��ǰ��,*�ֽļ���/�ɼǿ��� �ش�
	char product_cat_off_pctg[9];	// ��ǰ�� �ɼ���,*������� ǥ��\n*�ֽļ���/�ɼǿ��� �ش翹) 9999999.99\n5 => 9, 20140303
	char limit_ord_clsf_code[5];	// ������ȣ�����Ǳ����ڵ�,ȣ���� ü�� �� �ܷ�����. Bitwise ����\n--�ڵ尪--\n1: FAS (Fill And Store)\n2: FOK (Fill Or Kill)\n3: FAK (Fill And Kill)\n\n* ������ȣ�����Ǳ����ڵ� BITWISE ����\n���� Ȯ�强�� ���� �ش� 10�������� 2������ ��ȯ�Ͽ� ó�����(�ִ� 16bit���� ��밡��)\n�� ) ������ȣ�����Ǳ����ڵ� ���� 6�̸�\n    (������ 6 -> ������ 00000110)\n0��° bit 0 -> 0 : FAS\n1��° bit 1 -> 2 : FOK\n2��° bit 1 -> 4 : FAK\n��, FOK�̸鼭 FAK�� �����Ѵٴ� �ǹ� (FOK & FAK)\nX => 9, 1 => 5, 20140303
	char mrk_ord_clsf_code[5];	// ���尡ȣ�����Ǳ����ڵ�,* ��
	char cond_limit_ord_clsf_code[5];	// ���Ǻ�������ȣ�����Ǳ����ڵ�,* ��
	char best_limit_ord_clsf_code[5];	// ������������ȣ�����Ǳ����ڵ�,* ��
	char efp_clsf[1];	// EFP�ŷ���󿩺�,Y, N, ��ǰ������ �ش�  2009.08.31
	char flex_clsf[1];	// FLEX�ŷ���󿩺�,Y, N, ��ǰ������ �ش�  2009.08.31
	char yest_efp_exe_q[12];	// ����EFPü�����,��ǰ������ �ش�       2009.08.31
	char yest_efp_trd_amount[22];	// ����EFP�ŷ����,��ǰ������ �ش�       2009.08.31
	char mkr_close_clsf[1];	// ���忩��,���忩�� (Y,N), 20121217
	char real_t_prc_limit_clsf[1];	// �ǽð��������ѿ���,���� ü�ᰡ�� ��� Ư�� ������ �ʰ��ϴ� ȣ���� �ź��ϵ��� �������� ����(Y/N) 20140901
	char real_t_high_price_gap_sign[1];	// SIGN��ȣ,20140901
	char real_t_high_price_gap[12];	// �ǽð����Ѱ�����,���� ü�ᰡ�ݰ� �ǽð����Ѱ����� ����\n�ǽð����Ѱ� = ����ü�ᰡ�� + �ǽð����Ѱ�����\nex) 9999999999.99 20140901
	char real_t_low_price_gap_sign[1];	// SIGN��ȣ,20140901
	char real_t_low_price_gap[12];	// �ǽð����Ѱ�����,���� ü�ᰡ�ݰ� �ǽð����Ѱ����� ����\n�ǽð����Ѱ� = ����ü�ᰡ�� + �ǽð����Ѱ�����(����)\nex) 9999999999.99 20140901
	char under_ass_mrk_id[3];	// �����ڻ����ID,�����ڻ����ID�� �����ڻ��� KRX�� ����� ��쿡�� ä����.\nK200�����ɼ�:STK\n�ڽ���150����:KSQ\n�ֽļ����ɼ�:STK/KSQ\n��ǰ�����ɼ�:SPACE\n��������������:STK\n������������:STK\n�̴�K200�����ɼ�:STK
	char filler[24];	// Filler,170 => 134        2009.08.31\n134 => 133        2012.12.17\n133 => 110,       2014.03.03\n110 => 83,        2014.09.01\n83   => 27,       2015.06.15\n27   => 24,       2015.07.20
	char ff[1];	// End of Text,0xFF
} COM_FUTRE_PRD_INFO_DATA;


// ��������_��ä_CD_������
typedef struct _GOV_BOND_CD_DATA {
	char data_clsf[2];	// DATA����,H5
	char info_clsf[2];	// ��������,01:��ǰ����,\n���� record '99' set
	char mrk_clsf[1];	// ���屸��,6
	char send_date[8];	// ��������,YYYYMMDD
	char send_time[6];	// ���۽ð�,HHMMSS
	char uder_asset_clsf[6];	// �����ڻ걸��,BM3,BM5,BMA,CD,MSB   2010.10.25\n*�׸�� ����\n �����ڻ�ID->�����ڻ걸��  2009.08.31\n*MSB�����ߴ�          2011.05.02
	char final_ord_return_pctg[8];	// ����ȣ�����ͷ�,999.99999\nCD(91��),��ä(3��,5��,10��)\n*MSB�����ߴ�          2011.05.02
	char gov_bond_code[12];	// ��ä�ڵ�,��ä������ �������ä���ڵ�
	char gov_bond_prd_code[12];	// ��ä���������ڵ�
	char data_created_t[6];	// ������ �߻��ð�,HHMMSS
	char ff[1];	// End of Text,0xFF
} GOV_BOND_CD_DATA;


// ��������_��������ä��_������
typedef struct _STD_GOV_BOND_DATA {
	char data_clsf[2];	// DATA����,H6
	char info_clsf[2];	// ��������,01:��ǰ����,\n���� record '99' set
	char mrk_clsf[1];	// ���屸��,6
	char adj_date[8];	// ������,�����ڷ� ���۵�
	char prd[4];	// ��ǰ,BM3,BM5,BMA   2010.10.25
	char fut_prd_code[12];	// ���������ڵ�,���� �ŷ� ����� ����
	char under_asset_bond_code[12];	// ä���ڵ�,��ä������ �������ä���ڵ�
	char conv_coef[8];	// ��ȯ���,�μ������� ��ä������ ��츸 �ش��\n��) 99.999999\n'00000000' ó��   2010.10.25
	char filler[25];	// filler
	char ff[1];	// End of Text,0xFF
} STD_GOV_BOND_DATA;


// ��������_USD_������
typedef struct _USD_DATA {
	char data_clsf[2];	// DATA����,H9
	char info_clsf[2];	// ��������,01:��ǰ����,\n���� record '99' set
	char mrk_clsf[1];	// ���屸��,6
	char send_date[8];	// ��������,YYYYMMDD
	char send_time[6];	// ���۽ð�,HHMMSS
	char under_asset_id[6];	// �����ڻ�ID,USD
	char s_limit_ord_prc[6];	// �ŵ�ȣ��,��) 9999.99
	char l_limit_ord_prc[6];	// �ż�ȣ��
	char yest_close_prc[6];	// ��������
	char init_prc[6];	// �ð�
	char low_prc[6];	// ����
	char high_prc[6];	// ��
	char exe_prc[6];	// ü�ᰡ
	char data_created_t[6];	// ������ �߻��ð�,HHMMSS
	char ff[1];	// End of Text,0xFF
} USD_DATA;


// ��������_USD��ġ_������1
typedef struct _USD_BATCH_DATA_1 {
	char data_clsf[2];	// DATA����,I0
	char info_clsf[2];	// ��������,01:��ǰ����,\n���� record '99' set
	char mrk_clsf[1];	// ���屸��,6
	char job_clsf_code[4];	// ���������ڵ�,FBB1(��/�޷� ���Ͻð��뺰 �ŷ���Ȳ)
	char trd_date[8];	// �ŷ���
	char trd_hour[9];	// �ð���,HHMM-HHMM
	char spread_low_rate[6];	// LOW RATE(SP),9999.9
	char spread_high_rate[6];	// HIGH RATE(SP),9999.9
	char spread_vol[6];	// VOLUME(SP),9999.9
	char filler[42];	// filler
	char ff[1];	// End of Text,0xFF
} USD_BATCH_DATA_1;


// ��������_USD��ġ_������2
typedef struct _USD_BATCH_DATA_2 {
	char data_clsf[2];	// DATA����,I0
	char info_clsf[2];	// ��������,01:��ǰ����,\n���� record '99' set
	char mrk_clsf[1];	// ���屸��,6
	char job_clsf_code[4];	// ���������ڵ�,FBC1(��/�޷� ���� ���Ϲ��� ü����Ȳ1)
	char trd_date[8];	// �ŷ���,YYYYMMDD
	char fixed_date_clsf[2];	// ���Ϲ�����,*���Ϲ����� ����
	char maturity_date[8];	// ������(������),YYYYMMDD
	char low_rate[6];	// LOW RATE,9999.99
	char high_rate[6];	// HIGH RATE,9999.99
	char open_rate[6];	// OPEN RATE,9999.99
	char close_rate[6];	// CLOSE RATE,9999.99
	char filler[35];	// filler
	char ff[1];	// End of Text,0xFF
} USD_BATCH_DATA_2;


// ��������_USD��ġ_������3
typedef struct _USD_BATCH_DATA_3 {
	char data_clsf[2];	// DATA����,I0
	char info_clsf[2];	// ��������,01:��ǰ����,\n���� record '99' set
	char mrk_clsf[1];	// ���屸��,6
	char job_clsf_code[4];	// ���������ڵ�,FBC2(��/�޷� ���� ���Ϲ��� ü����Ȳ2)
	char trd_date[8];	// �ŷ���,YYYYMMDD
	char fixed_date_clsf[2];	// ���Ϲ�����,*���Ϲ����� ����
	char maturity_date[8];	// ������(������),YYYYMMDD
	char vol[6];	// VOLUME,9999.9
	char avg_rate[7];	// AVERAGE RATE,9999.99
	char mar[6];	// MAR,9999.9
	char filler[40];	// filler
	char ff[1];	// End of Text,0xFF
} USD_BATCH_DATA_3;


// ��������_USD��ġ_������4
typedef struct _USD_BATCH_DATA_4 {
	char data_clsf[2];	// DATA����,I0
	char info_clsf[2];	// ��������,01:��ǰ����,\n���� record '99' set
	char mrk_clsf[1];	// ���屸��,6
	char job_clsf_code[4];	// ���������ڵ�,FBD1(ȯ����� ����ȯ�� ��Ȳ)
	char informed_date[8];	// �����,YYYYMMDD
	char currency_name[3];	// ��ȭ��,��)��ȭ�� ����
	char cross_rate[10];	// CROSS RATE,9999.99999
	char fx_rate[7];	// ȯ��,9999.99
	char filler[49];	// filler
	char ff[1];	// End of Text,0xFF
} USD_BATCH_DATA_4;


// ��������_USD��ġ_������5
typedef struct _USD_BATCH_DATA_5 {
	char data_clsf[2];	// DATA����,I0
	char info_clsf[2];	// ��������,01:��ǰ����,\n���� record '99' set
	char mrk_clsf[1];	// ���屸��,6
	char job_clsf_code[4];	// ���������ڵ�,FBE1(SWAP ������ ���Ϲ��� ü����Ȳ)
	char trd_date[8];	// �ŷ���,YYYYMMDD
	char fixed_date_clsf[2];	// ���Ϲ�����,��)���Ϲ����� ����
	char maturity_date[8];	// ������(������),YYYYMMDD
	char low_rate[5];	// LOW RATE,��9999
	char high_rate[5];	// HIGH RATE,��9999
	char open_rate[5];	// OPEN RATE,��9999
	char close_rate[5];	// CLOSE RATE,��9999
	char avg_rate[5];	// AVERAGE RATE,��9999
	char vol[6];	// VOLUME,9999.9
	char filler[28];	// filler
	char ff[1];	// End of Text,0xFF
} USD_BATCH_DATA_5;


// ��������_USD��ġ_������6
typedef struct _USD_BATCH_DATA_6 {
	char data_clsf[2];	// DATA����,I0
	char info_clsf[2];	// ��������,01:��ǰ����,\n���� record '99' set
	char mrk_clsf[1];	// ���屸��,6
	char job_clsf_code[4];	// ���������ڵ�,FBF1(��/�޷� ����ȯ�� : ��ȭ����ȯ�����)
	char std_date[8];	// ������,YYYYMMDD
	char fixed_date_clsf_0[2];	// ���Ϲ�����,��)����ȯ�����Ϲ����� ����
	char rate_0[7];	// RATE,9999.99
	char fixed_date_clsf_1[2];	// ���Ϲ�����,��)����ȯ�����Ϲ����� ����
	char rate_1[7];	// RATE,9999.99
	char fixed_date_clsf_2[2];	// ���Ϲ�����,��)����ȯ�����Ϲ����� ����
	char rate_2[7];	// RATE,9999.99
	char fixed_date_clsf_3[2];	// ���Ϲ�����,��)����ȯ�����Ϲ����� ����
	char rate_3[7];	// RATE,9999.99
	char filler[33];	// filler
	char ff[1];	// End of Text,0xFF
} USD_BATCH_DATA_6;


// ��������_USD��ġ_������7
typedef struct _USD_BATCH_DATA_7 {
	char data_clsf[2];	// DATA����,I0
	char info_clsf[2];	// ��������,01:��ǰ����,\n���� record '99' set
	char mrk_clsf[1];	// ���屸��,6
	char job_clsf_code[4];	// ���������ڵ�,FBF2(��/�޷� ���� ȯ�� : ��������Ʈ ���))
	char std_date[8];	// ������,YYYYMMDD
	char fixed_date_clsf_0[2];	// ���Ϲ�����,��)����ȯ�����Ϲ����� ����
	char rate_0[7];	// RATE,9999.99
	char fixed_date_clsf_1[2];	// ���Ϲ�����,��)����ȯ�����Ϲ����� ����
	char rate_1[7];	// RATE,9999.99
	char fixed_date_clsf_2[2];	// ���Ϲ�����,��)����ȯ�����Ϲ����� ����
	char rate_2[7];	// RATE,9999.99
	char fixed_date_clsf_3[2];	// ���Ϲ�����,��)����ȯ�����Ϲ����� ����
	char rate_3[7];	// RATE,9999.99
	char filler[33];	// filler
	char ff[1];	// End of Text,0xFF
} USD_BATCH_DATA_7;


// ��������_USD��ġ_������8
typedef struct _USD_BATCH_DATA_8 {
	char data_clsf[2];	// DATA����,I0
	char info_clsf[2];	// ��������,01:��ǰ����,\n���� record '99' set
	char mrk_clsf[1];	// ���屸��,6
	char job_clsf_code[4];	// ���������ڵ�,FBG1(����� ����ȯ��)
	char informed_date[8];	// �����,YYYYMMDD
	char std_year_month[7];	// ���س��,9999.99
	char avg_fx_rate[7];	// ��ձ���ȯ��,9999.99
	char filler[55];	// filler
	char ff[1];	// End of Text,0xFF
} USD_BATCH_DATA_8;


// ��������_USD��ġ_������9
typedef struct _USD_BATCH_DATA_9 {
	char data_clsf[2];	// DATA����,I0
	char info_clsf[2];	// ��������,01:��ǰ����,\n���� record '99' set
	char mrk_clsf[1];	// ���屸��,6
	char job_clsf_code[4];	// ���������ڵ�,CBA1(��ȭ ���� �ŷ����1)
	char trd_date[8];	// �ŷ���,YYYYMMDD
	char currency_name[3];	// ��ȭ��,��)��ȭ�� ����
	char open_rate[8];	// OPEN RATE,99.99999
	char high_rate[8];	// HIGH RATE,99.99999
	char low_rate[8];	// LOW RATE,99.99999
	char close_rate[8];	// CLOSE RATE,99.99999
	char filler[34];	// filler
	char ff[1];	// End of Text,0xFF
} USD_BATCH_DATA_9;


// ��������_USD��ġ_������10
typedef struct _USD_BATCH_DATA_10 {
	char data_clsf[2];	// DATA����,I0
	char info_clsf[2];	// ��������,01:��ǰ����,\n���� record '99' set
	char mrk_clsf[1];	// ���屸��,6
	char job_clsf_code[4];	// ���������ڵ�,CBA2(��ȭ ���� �ŷ����2)
	char trd_date[8];	// �ŷ���,YYYYMMDD
	char currency_name[3];	// ��ȭ��,��)��ȭ�� ����
	char ave_rate[7];	// AVERAGE RATE,99.9999
	char o_n_vol[7];	// O/N VOLUME,9999.99
	char total_vol[7];	// TOTAL VOLUME,9999.99
	char libor_rate[7];	// LIBOR,9.99999
	char sibor_rate[7];	// SIBOR,9.99999
	char filler[31];	// filler
	char ff[1];	// End of Text,0xFF
} USD_BATCH_DATA_10;


// ��������_USD�ǽð�����_������1
typedef struct _USD_REAL_TIME_DATA_1 {
	char data_clsf[2];	// DATA����,I1
	char info_clsf[2];	// ��������,01:��ǰ����,\n���� record '99' set
	char mrk_clsf[1];	// ���屸��,6
	char job_clsf_code[4];	// ���������ڵ�,FOC1(��/�޷� �ð��뺰 �ŷ���Ȳ)
	char trd_date[8];	// �ŷ���,YYYYMMDD
	char trd_hour[9];	// �ð���,HHMM-HHMM
	char spread_low_rate[6];	// LOW RATE(SP),9999.99
	char spread_high_rate[6];	// HIGH RATE(SP),9999.99
	char filler[48];	// filler
	char ff[1];	// End of Text,0xFF
} USD_REAL_TIME_DATA_1;


// ��������_USD�ǽð�����_������2
typedef struct _USD_REAL_TIME_DATA_2 {
	char data_clsf[2];	// DATA����,I1
	char info_clsf[2];	// ��������,01:��ǰ����
	char mrk_clsf[1];	// ���屸��,6
	char job_clsf_code[4];	// ���������ڵ�,FOD1(��/�޷� ���Ϲ��� ������Ȳ)
	char trd_date[8];	// �ŷ���,YYYYMMDD
	char fixed_date_clsf[2];	// ���Ϲ�����,��)���Ϲ���������
	char maturity_date[8];	// ������(������),YYYYMMDD
	char bid_best[6];	// BID BEST,9999.9
	char offer_best[6];	// OFFER BEST,9999.9
	char bid_vol[6];	// BID VOLUME,9999.9
	char offer_vol[6];	// OFFER VOLUME,9999.9
	char prev_rate[6];	// PREV RATE,9999.9
	char filler[29];	// filler
	char ff[1];	// End of Text,0xFF
} USD_REAL_TIME_DATA_2;


// ��������_USD�ǽð�����_������3
typedef struct _USD_REAL_TIME_DATA_3 {
	char data_clsf[2];	// DATA����,I1
	char info_clsf[2];	// ��������,01:��ǰ����
	char mrk_clsf[1];	// ���屸��,6
	char job_clsf_code[4];	// ���������ڵ�,FOE1(��/�޷� ���Ϲ��� ü����Ȳ) (����->ü��)����
	char trd_date[8];	// �ŷ���,YYYYMMDD
	char fixed_date_clsf[2];	// ���Ϲ�����,��)���Ϲ���������
	char maturity_date[8];	// ������(������),YYYYMMDD
	char low_rate[6];	// LOW RATE,9999.9
	char high_rate[6];	// HIGH RATE,9999.9
	char open_rate[6];	// OPEN RATE,9999.9
	char close_rate[6];	// CLOSE RATE,9999.9
	char filler[35];	// filler
	char ff[1];	// End of Text,0xFF
} USD_REAL_TIME_DATA_3;


// ��������_CNH�ǽð�����_������
typedef struct _CNH_REAL_TIME_DATA {
	char data_clsf[2];	// DATA����,I1
	char info_clsf[2];	// ��������,01:��ǰ����
	char mrk_clsf[1];	// ���屸��,6
	char job_clsf_code[4];	// ���������ڵ�,HOE1(��/���� ���Ϲ��� ü����Ȳ)
	char trd_date[8];	// �ŷ���,YYYYMMDD
	char fixed_date_clsf[2];	// ���Ϲ�����,��)���Ϲ���������
	char maturity_date[8];	// ������(������),YYYYMMDD
	char low_rate[6];	// LOW RATE,9999.9
	char high_rate[6];	// HIGH RATE,9999.9
	char open_rate[6];	// OPEN RATE,9999.9
	char close_rate[6];	// CLOSE RATE,9999.9
	char filler[35];	// filler
	char ff[1];	// End of Text,0xFF
} CNH_REAL_TIME_DATA;


// ��������_USD�ǽð�����_������4
typedef struct _USD_REAL_TIME_DATA_4 {
	char data_clsf[2];	// DATA����,I1
	char info_clsf[2];	// ��������,01:��ǰ����
	char mrk_clsf[1];	// ���屸��,6
	char job_clsf_code[4];	// ���������ڵ�,FOF1(SWAP ���Ϲ��� ������Ȳ)
	char trd_date[8];	// �ŷ���,YYYYMMDD
	char fixed_date_clsf[2];	// ���Ϲ�����,��)���Ϲ���������
	char maturity_date[8];	// ������(������),YYYYMMDD
	char bid_best[5];	// BID BEST,��9999
	char offer_best[5];	// OFFER BEST,��9999
	char bid_vol[6];	// BID VOLUME,9999.9
	char offer_vol[6];	// OFFER VOLUME,9999.9
	char prev_rate[5];	// PREV RATE,��9999
	char filler[32];	// filler
	char ff[1];	// End of Text,0xFF
} USD_REAL_TIME_DATA_4;


// ��������_USD�ǽð�����_������5
typedef struct _USD_REAL_TIME_DATA_5 {
	char data_clsf[2];	// DATA����,I1
	char info_clsf[2];	// ��������,01:��ǰ����
	char mrk_clsf[1];	// ���屸��,6
	char job_clsf_code[4];	// ���������ڵ�,FOG1(SWAP ���Ϲ��� ü����Ȳ)
	char trd_date[8];	// �ŷ���,YYYYMMDD
	char fixed_date_clsf[2];	// ���Ϲ�����,��)���Ϲ���������
	char maturity_date[8];	// ������(������),YYYYMMDD
	char low_rate[5];	// LOW RATE,��9999
	char high_rate[5];	// HIGH RATE,��9999
	char open_rate[5];	// OPEN RATE,��9999
	char close_rate[5];	// CLOSE RATE,��9999
	char filler[39];	// filler
	char ff[1];	// End of Text,0xFF
} USD_REAL_TIME_DATA_5;


// ��������_USD�ǽð�����_������8
typedef struct _USD_REAL_TIME_DATA_8 {
	char data_clsf[2];	// DATA����,I1
	char info_clsf[2];	// ��������,01:��ǰ����
	char mrk_clsf[1];	// ���屸��,6
	char job_clsf_code[4];	// ���������ڵ�,UOD1(���޷� SPOT ��� ȯ��ȣ��)
	char trd_date[8];	// �ŷ���,YYYYMMDD
	char fixed_date_clsf[2];	// ���Ϲ�����,��)���Ϲ� ����
	char maturity_date[8];	// ������(������),YYYYMMDD
	char bank_name[10];	// �����,���������
	char bid_best[6];	// BID BEST,9999.9
	char offer_best[6];	// OFFER BEST,9999.9
	char low_rate[6];	// LOW RATE,9999.9
	char high_rate[6];	// HIGH RATE,9999.9
	char open_rate[6];	// OPEN RATE,9999.9
	char mar[6];	// MAR,9999.9
	char filler[13];	// filler
	char ff[1];	// End of Text,0xFF
} USD_REAL_TIME_DATA_8;


// ��������_USD�ǽð�����_������7
typedef struct _USD_REAL_TIME_DATA_7 {
	char data_clsf[2];	// DATA����,I1
	char info_clsf[2];	// ��������,01:��ǰ����
	char mrk_clsf[1];	// ���屸��,6
	char job_clsf_code[4];	// ���������ڵ�,COA1(��ȭ ���Ϲ��� ������Ȳ)
	char trd_date[8];	// �ŷ���,YYYYMMDD
	char currency_name[3];	// ��ȭ��,��)��ȭ�� ����
	char fixed_date_clsf[2];	// ���Ϲ� ����,��)���Ϲ� ����
	char bid_rate[8];	// BID RATE,99999.99
	char offer_rate[8];	// OFFER RATE,99999.99
	char bid_vol[7];	// BID VOLUME,9999.99
	char offer_vol[7];	// OFFER VOLUME,9999.99
	char filler[34];	// filler
	char ff[1];	// End of Text,0xFF
} USD_REAL_TIME_DATA_7;


// ��������_USD�ǽð�����_������6
typedef struct _USD_REAL_TIME_DATA_6 {
	char data_clsf[2];	// DATA����,I1
	char info_clsf[2];	// ��������,01:��ǰ����
	char mrk_clsf[1];	// ���屸��,6
	char job_clsf_code[4];	// ���������ڵ�,FOQ1(����ȯ �ð��뺰 BID-OFFER ȣ�� ��Ȳ)
	char trd_date[8];	// �ŷ���,YYYYMMDD
	char td_hour[4];	// �ð���,HHMM
	char spread_bid_prc[6];	// BID ȣ��(SP),9999.9
	char spread_ask_prc[6];	// OFFER ȣ��(SP),9999.9
	char filler[53];	// filler
	char ff[1];	// End of Text,0xFF
} USD_REAL_TIME_DATA_6;


// ��ǰ����_Polling ������
typedef struct _COM_FUT_POLLING_DATA {
	char data_clsf[2];	// DATA����,I2
	char info_clsf[2];	// ��������,01:��ǰ����
	char mrk_clsf[1];	// ���屸��,6
	char send_time[4];	// ���۽ð�,HHSS
	char main_backup_clsf[2];	// Main Backup����,space
	char filler[8];	// Filler
	char ff[1];	// End of Text,0xFF
} COM_FUT_POLLING_DATA;


// ��������_USD�ǽð�����_������9
typedef struct _USD_REAL_TIME_DATA_9 {
	char data_clsf[2];	// DATA����,I1
	char info_clsf[2];	// ��������,01:��ǰ����
	char mrk_clsf[1];	// ���屸��,6
	char job_clsf_code[4];	// ���������ڵ�,UOE1(���޷� SPOT 30�д��� �ణ ȯ��ü�ᰡ)
	char trd_date[8];	// �ŷ���,YYYYMMDD
	char fixed_date_clsf[2];	// ���Ϲ�����,SP
	char maturity_date[8];	// ������(������),YYYYMMDD
	char exe_t[4];	// ü��ð�,HHMM(0930, 1000,1030,1100,1130,1200,1230,\n1300,1330,1400, 1430, 1500)
	char exe_prc[6];	// ü�ᰡ,9999.9
	char filler[49];	// filler
	char ff[1];	// End of Text,0xFF
} USD_REAL_TIME_DATA_9;


// ��������_������ǥ��������_������
typedef struct _LEAN_HOG_REP_PRC_INDEX_DATA {
	char data_clsf[2];	// DATA����,H8
	char info_clsf[2];	// ��������,01:��ǰ����
	char mrk_clsf[1];	// ���屸��,6
	char data_type[1];	// ������ Ÿ��,D:���� ��ǥ���� ����
	char inform_date_yest[8];	// ��������-����
	char inform_date_close_yest[8];	// ��������-������
	char accum_mrk_nbr[2];	// ���赵�Ž����,����
	char accum_prd_nbr[5];	// ����μ�,��
	char trd_weight_total[10];	// �ŷ� ��ü�� �հ�,kg
	char trd_prc_total[15];	// �ŷ� ���� �հ�,��
	char rep_prc[4];	// ��ǥ ����,��/kg
	char filler[42];	// filler
	char ff[1];	// End of Text,0xFF
} LEAN_HOG_REP_PRC_INDEX_DATA;


// ��������_�����ǽð���������_������
typedef struct _LEAN_HOG_REAL_TIME_PRC_INDEX_DATA {
	char data_cslf[2];	// DATA����,H8
	char info_clsf[2];	// ��������,01:��ǰ����
	char mrk_clsf[1];	// ���屸��,6
	char data_type[1];	// ������ Ÿ��,L:�ǽð� �������� ����
	char inform_time[4];	// ���ýð�
	char inform_date_yest[8];	// ��������-����
	char inform_date_today[8];	// ��������-����
	char accum_mrk_nbr[2];	// ���� ���Ž��� ��,����
	char accum_prd_nbr[5];	// ����μ�,��
	char trd_weight_total[10];	// �ŷ� ��ü�� �հ�,kg
	char trd_prc_total[15];	// �ŷ� ���� �հ�,��
	char under_asset_prc[4];	// ���� ����,��/kg
	char filler[38];	// filler
	char ff[1];	// End of Text,0xFF
} LEAN_HOG_REAL_TIME_PRC_INDEX_DATA;


// ��������_����������������_������
typedef struct _LEAN_HOG_CLOSE_PRICE_INDEX_DATA {
	char data_clsf[2];	// DATA����,H8
	char info_clsf[2];	// ��������,01:��ǰ����,\n���� record '99' set
	char mrk_clsf[1];	// ���屸��,6
	char data_type[1];	// ������ Ÿ��,E:�ǽð� �������� ��������
	char inform_date_today[8];	// �������� ����
	char inform_date_yest[8];	// �������� ����
	char accum_mrk_nbr[2];	// ���� ���Ž��� ��
	char accum_prd_nbr[5];	// ���� �μ�,����
	char trd_weight_total[10];	// �ŷ� ��ü�� �հ�,��
	char trd_prc_total[15];	// �ŷ� ���� �հ�,kg
	char init_prc[4];	// ���� ����,��
	char high_prc[4];	// �ְ� ����,��/kg
	char low_prc[4];	// ���� ����
	char close_prc[4];	// ���� ����
	char filler[30];	// filler
	char ff[1];	// End of Text,0xFF
} LEAN_HOG_CLOSE_PRICE_INDEX_DATA;


// ��ǰ����_SPACE
typedef struct _COM_FUT_SPACE {
	char data_clsf[2];	// DATA����,G9
	char info_clsf[2];	// ��������,01:��ǰ����
	char mrk_clsf[1];	// ���屸��,6
	char ff[1];	// End of Text,0xFF
} COM_FUT_SPACE;
