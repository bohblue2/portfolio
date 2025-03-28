// df_com_futures_tr.h
// ��ǰ���� �ǽð� TR

#pragma once
// �ּ��� \n�� ���� ���߿� �̻ڰ� �ٲ����


// ��ǰ����_����+�����ջ�
typedef struct _DF_COM_FUT_COMP_BLOCK {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����,C4
	char info_clsf[3];	// ��������,01:��ǰ����
	char mkt_clsf;	// ���屸��,6
	char isin_clsf[13];	// �����ڵ�,*���߰��̵� ���� : �ű�ä���� �߰�\n 2010.10.25
	int stk_snr;	// �����Ϸù�ȣ
	double cpt_block_trd_vol;	// ����+�����ջ� �ŷ���,����Ÿ�, ���Ǵ뷮�ŷ�, EFP, FLEX �ŷ��� �ջ��� �ŷ���
	double cpt_block_trd_amt;	// ����+�����ջ� �ŷ����,����Ÿ�, ���Ǵ뷮�ŷ�, EFP, FLEX �ŷ��� �ջ��� �ŷ����\n(���� : ��)
} DF_COM_FUT_COMP_BLOCK;


// ��ǰ����_ü��
typedef struct _DF_COM_FUT_EXEC {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����,A3
	char info_clsf[3];	// ��������,01:��ǰ����
	char mkt_clsf;	// ���屸��,6
	char isin_clsf[13];	// �����ڵ�,*���߰��̵� ���� : �ű�ä���� �߰�\n 2010.10.25
	int stk_snr;	// �����Ϸù�ȣ
	char brd_id[3];	// ����ID,�ڵ尪��������
	double cur_prc;	// ���簡��,��) 999999.99
	int exe_q;	// ü�����
	char ss_id[3];	// ����ID,�ڵ尪��������
	char exe_t[9];	// ü��ð�
	double rct_prd_prc;	// �ֱٿ���������������,��) 999999.99
	double nxt_prd_prc;	// ������������������,��) 999999.99
	double init_prc;	// �ð�,��) 999999.99
	double high_prc;	// ��,��) 999999.99
	double low_prc;	// ����,��) 999999.99
	double pri_prc;	// ��������,��) 999999.99
	int accm_exe_q;	// ����ü�����
	double accm_trd_amt;	// �����ŷ����(����:��)
	char l_or_s;	// �����ŵ��ż������ڵ�,1:�ŵ�,2:�ż�(�������� ���� ȣ���� �ŵ��ż����а�)
	double real_t_high_prc;	// �ǽð����Ѱ�,��) 999999.99 ���߰��̵�����
	double real_t_low_prc;	// �ǽð����Ѱ�,��) 999999.99 ���߰��̵�����
} DF_COM_FUT_EXEC;


// ��ǰ����_�켱ȣ��
typedef struct _DF_COM_FUT_LIMIT_ORD {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����,B6
	char info_clsf[3];	// ��������,01:��ǰ����
	char mkt_clsf;	// ���屸��,6
	char isin_clsf[13];	// �����ڵ�,*���߰��̵� ���� : �ű�ä���� �߰�\n 2010.10.25
	int stk_snr;	// �����Ϸù�ȣ
	char brd_id[3];	// ����ID,�ڵ尪��������
	char ss_id[3];	// ����ID,�ڵ尪��������
	int total_l_limit_ord_q;	// �ż���ȣ���ܷ�
	double l_lvl_1_prc;	// �ż�1�ܰ�켱ȣ������,��) 999999.99
	int l_lvl_1_q;	// �ż�1�ܰ�켱ȣ���ܷ�
	double l_lvl_2_prc;	// �ż�2�ܰ�켱ȣ������,��) 999999.99
	int l_lvl_2_q;	// �ż�2�ܰ�켱ȣ���ܷ�
	double l_lvl_3_prc;	// �ż�3�ܰ�켱ȣ������,��) 999999.99
	int l_lvl_3_q;	// �ż�3�ܰ�켱ȣ���ܷ�
	double l_lvl_4_prc;	// �ż�4�ܰ�켱ȣ������,��) 999999.99
	int l_lvl_4_q;	// �ż�4�ܰ�켱ȣ���ܷ�
	double l_lvl_5_prc;	// �ż�5�ܰ�켱ȣ������,��) 999999.99
	int l_lvl_5_q;	// �ż�5�ܰ�켱ȣ���ܷ�
	int total_s_limit_ord_q;	// �ŵ���ȣ���ܷ�
	double s_lvl_1_prc;	// �ŵ�1�ܰ�켱ȣ������,��) 999999.99
	int s_lvl_1_q;	// �ŵ�1�ܰ�켱ȣ���ܷ�
	double s_lvl_2_prc;	// �ŵ�2�ܰ�켱ȣ������,��) 999999.99
	int s_lvl_2_q;	// �ŵ�2�ܰ�켱ȣ���ܷ�
	double s_lvl_3_prc;	// �ŵ�3�ܰ�켱ȣ������,��) 999999.99
	int s_lvl_3_q;	// �ŵ�3�ܰ�켱ȣ���ܷ�
	double s_lvl_4_prc;	// �ŵ�4�ܰ�켱ȣ������,��) 999999.99
	int s_lvl_4_q;	// �ŵ�4�ܰ�켱ȣ���ܷ�
	double s_lvl_5_prc;	// �ŵ�5�ܰ�켱ȣ������,��) 999999.99
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
	double exp_prc;	// ����ü�ᰡ��,��) 999999.99 ���ϰ��ŸŽø� ����\n (����±����ڵ�:10,20,30,80)
} DF_COM_FUT_LIMIT_ORD;


// ��ǰ����_ü��_�켱ȣ��
typedef struct _DF_COM_FUT_EXEC_LIMIT_ORD {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����,G7
	char info_clsf[3];	// ��������,01:��ǰ����
	char mrk_clsf;	// ���屸��,6
	char isin_clsf[13];	// �����ڵ�,*���߰��̵� ���� : �ű�ä���� �߰�\n 2010.10.25
	int stk_snr;	// �����Ϸù�ȣ
	char brd_id[3];	// ����ID,�ڵ尪��������
	double cur_price;	// ���簡��,��) 999999.99
	int exe_q;	// ü�����
	char ss_id[3];	// ����ID,�ڵ尪��������
	char exe_t[9];	// ü��ð�
	double rct_prd_prc;	// �ֱٿ���������������,��) 999999.99
	double nxt_prd_prc;	// ������������������,��) 999999.99
	double init_prc;	// �ð�,��) 999999.99
	double high_prc;	// ��,��) 999999.99
	double low_prc;	// ����,��) 999999.99
	double pri_prc;	// ��������,��) 999999.99
	int accm_exe_q;	// ����ü�����
	double accm_trd_amt;	// �����ŷ����(����:��)
	char l_or_s;	// �����ŵ��ż������ڵ�,1:�ŵ�,2:�ż�(�������� ���� ȣ���� �ŵ��ż����а�)
	int total_l_limit_ord_q;	// �ż���ȣ���ܷ�
	double l_lvl_1_prc;	// �ż�1�ܰ�켱ȣ������,��) 999999.99
	int l_lvl_1_q;	// �ż�1�ܰ�켱ȣ���ܷ�
	double l_lvl_2_prc;	// �ż�2�ܰ�켱ȣ������,��) 999999.99
	int l_lvl_2_q;	// �ż�2�ܰ�켱ȣ���ܷ�
	double l_lvl_3_prc;	// �ż�3�ܰ�켱ȣ������,��) 999999.99
	int l_lvl_3_q;	// �ż�3�ܰ�켱ȣ���ܷ�
	double l_lvl_4_prc;	// �ż�4�ܰ�켱ȣ������,��) 999999.99
	int l_lvl_4_q;	// �ż�4�ܰ�켱ȣ���ܷ�
	double l_lvl_5_prc;	// �ż�5�ܰ�켱ȣ������,��) 999999.99
	int l_lvl_5_q;	// �ż�5�ܰ�켱ȣ���ܷ�
	int total_s_limit_ord_q;	// �ŵ���ȣ���ܷ�
	double s_lvl_1_prc;	// �ŵ�1�ܰ�켱ȣ������,��) 999999.99
	int s_lvl_1_q;	// �ŵ�1�ܰ�켱ȣ���ܷ�
	double s_lvl_2_prc;	// �ŵ�2�ܰ�켱ȣ������,��) 999999.99
	int s_lvl_2_q;	// �ŵ�2�ܰ�켱ȣ���ܷ�
	double s_lvl_3_prc;	// �ŵ�3�ܰ�켱ȣ������,��) 999999.99
	int s_lvl_3_q;	// �ŵ�3�ܰ�켱ȣ���ܷ�
	double s_lvl_4_prc;	// �ŵ�4�ܰ�켱ȣ������,��) 999999.99
	int s_lvl_4_q;	// �ŵ�4�ܰ�켱ȣ���ܷ�
	double s_lvl_5_prc;	// �ŵ�5�ܰ�켱ȣ������,��) 999999.99
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
	double real_t_high_prc;	// �ǽð����Ѱ�,��) 999999.99 ���߰��̵�����
	double real_t_low_prc;	// �ǽð����Ѱ�,��) 999999.99 ���߰��̵�����
} DF_COM_FUT_EXEC_LIMIT_ORD;


// ��ǰ����_���񸶰�
typedef struct _DF_COM_FUT_CLOSE_PRODUCT {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����,A6
	char info_clsf[3];	// ��������,01:��ǰ����
	char mrk_clsf;	// ���屸��,6
	char isin_clsf[13];	// �����ڵ�,*���߰��̵� ���� : �ű�ä���� �߰�\n 2010.10.25
	int stk_snr;	// �����Ϸù�ȣ
	char brd_id[3];	// ����ID,�ڵ尪��������
	double close_prc;	// ����,* �ŷ��� ������ ��� ���ذ� set, ��) 999999.99
	char close_prc_code;	// ���������ڵ�,1:�Ǽ�, 3:�ŷ���\n 2:�⼼ -2012.05.14 ����\n ' ':�������� �ƴ� ��� space
	int accm_exe_q;	// ����ü�����
	double accm_trd_amt;	// �����ŷ����(����:��)
	int total_l_limit_ord_q;	// �ż���ȣ���ܷ�
	double l_lvl_1_prc;	// �ż�1�ܰ�켱ȣ������,��) 999999.99
	int l_lvl_1_q;	// �ż�1�ܰ�켱ȣ���ܷ�
	double l_lvl_2_prc;	// �ż�2�ܰ�켱ȣ������,��) 999999.99
	int l_lvl_2_q;	// �ż�2�ܰ�켱ȣ���ܷ�
	double l_lvl_3_prc;	// �ż�3�ܰ�켱ȣ������,��) 999999.99
	int l_lvl_3_q;	// �ż�3�ܰ�켱ȣ���ܷ�
	double l_lvl_4_prc;	// �ż�4�ܰ�켱ȣ������,��) 999999.99
	int l_lvl_4_q;	// �ż�4�ܰ�켱ȣ���ܷ�
	double l_lvl_5_prc;	// �ż�5�ܰ�켱ȣ������,��) 999999.99
	int l_lvl_5_q;	// �ż�5�ܰ�켱ȣ���ܷ�
	int total_s_limit_ord_q;	// �ŵ���ȣ���ܷ�
	double s_lvl_1_prc;	// �ŵ�1�ܰ�켱ȣ������,��) 999999.99
	int s_lvl_1_q;	// �ŵ�1�ܰ�켱ȣ���ܷ�
	double s_lvl_2_prc;	// �ŵ�2�ܰ�켱ȣ������,��) 999999.99
	int s_lvl_2_q;	// �ŵ�2�ܰ�켱ȣ���ܷ�
	double s_lvl_3_prc;	// �ŵ�3�ܰ�켱ȣ������,��) 999999.99
	int s_lvl_3_q;	// �ŵ�3�ܰ�켱ȣ���ܷ�
	double s_lvl_4_prc;	// �ŵ�4�ܰ�켱ȣ������,��) 999999.99
	int s_lvl_4_q;	// �ŵ�4�ܰ�켱ȣ���ܷ�
	double s_lvl_5_prc;	// �ŵ�5�ܰ�켱ȣ������,��) 999999.99
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
} DF_COM_FUT_CLOSE_PRODUCT;


// ��ǰ����_��TS
typedef struct _DF_COM_FUT_MRK_OP_TS {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����,A7
	char info_clsf[3];	// ��������,01:��ǰ����
	char mrk_clsf;	// ���屸��,6
	char isin_clsf[13];	// �����ڵ�
	int stk_snr;	// �����Ϸù�ȣ
	char prd_id[12];	// ��ǰID,�ڵ尪�������� : spaceó��
	char brd_id[3];	// ����ID,�ڵ尪��������
	char brd_event_id[4];	// �����̺�ƮID,�ڵ尪��������
	char brd_event_start_t[9];	// �����̺�Ʈ���۽ð�,������ �����(��:BB1(�ŸŰŷ�����)�� ��� 09000000)
	int brd_event_code;	// �����̺�Ʈ���뱺�ڵ�,�ڵ尪���� ����
	char ss_id[3];	// ����ID,�ڵ尪��������
	char ord_exist;	// ȣ������,0:ȣ������(�����׸� ����), 1:ȣ������(�����׸� ���)
	int total_l_limit_ord_q;	// �ż���ȣ���ܷ�
	double l_lvl_1_prc;	// �ż�1�ܰ�켱ȣ������,��) 999999.99
	int l_lvl_1_q;	// �ż�1�ܰ�켱ȣ���ܷ�
	double l_lvl_2_prc;	// �ż�2�ܰ�켱ȣ������,��) 999999.99
	int l_lvl_2_q;	// �ż�2�ܰ�켱ȣ���ܷ�
	double l_lvl_3_prc;	// �ż�3�ܰ�켱ȣ������,��) 999999.99
	int l_lvl_3_q;	// �ż�3�ܰ�켱ȣ���ܷ�
	double l_lvl_4_prc;	// �ż�4�ܰ�켱ȣ������,��) 999999.99
	int l_lvl_4_q;	// �ż�4�ܰ�켱ȣ���ܷ�
	double l_lvl_5_prc;	// �ż�5�ܰ�켱ȣ������,��) 999999.99
	int l_lvl_5_q;	// �ż�5�ܰ�켱ȣ���ܷ�
	int total_s_limit_ord_q;	// �ŵ���ȣ���ܷ�
	double s_lvl_1_prc;	// �ŵ�1�ܰ�켱ȣ������,��) 999999.99
	int s_lvl_1_q;	// �ŵ�1�ܰ�켱ȣ���ܷ�
	double s_lvl_2_prc;	// �ŵ�2�ܰ�켱ȣ������,��) 999999.99
	int s_lvl_2_q;	// �ŵ�2�ܰ�켱ȣ���ܷ�
	double s_lvl_3_prc;	// �ŵ�3�ܰ�켱ȣ������,��) 999999.99
	int s_lvl_3_q;	// �ŵ�3�ܰ�켱ȣ���ܷ�
	double s_lvl_4_prc;	// �ŵ�4�ܰ�켱ȣ������,��) 999999.99
	int s_lvl_4_q;	// �ŵ�4�ܰ�켱ȣ���ܷ�
	double s_lvl_5_prc;	// �ŵ�5�ܰ�켱ȣ������,��) 999999.99
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
	double real_t_high_prc;	// �ǽð����Ѱ�,��) 999999.99 ���߰��̵�����
	double real_t_low_prc;	// �ǽð����Ѱ�,��) 999999.99 ���߰��̵�����
} DF_COM_FUT_MRK_OP_TS;


// ��ǰ����_����
typedef struct _DF_COM_FUT_CLOSE {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����,H0
	char info_clsf[3];	// ��������,01:��ǰ����
	char mrk_clsf;	// ���屸��,6
} DF_COM_FUT_CLOSE;


// ��ǰ����_�������ٰ���
typedef struct _DF_COM_FUT_MRK_OP_SCHD {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����,M4
	char info_clsf[3];	// ��������,01:��ǰ����
	char mrk_clsf;	// ���屸��,6
	char isin_clsf[13];	// �����ڵ�,*�������� �� ��ġ�� ���
	char stk_snr[4];	// �����Ϸù�ȣ,*�������� �� ��ġ�� ���
	char prd_id[12];	// ��ǰID,�ڵ尪�������� : spaceó��
	char mrk_prd_id[4];	// ����ǰ�׷�ID,*�ڵ尪��������
	char brd_id[3];	// ����ID,�ڵ尪��������
	char brd_event_id[4];	// �����̺�ƮID,�ڵ尪��������
	char brd_event_start_t[9];	// �����̺�Ʈ���۽ð�
	int brd_event_code;	// �����̺�Ʈ���뱺�ڵ�,�ڵ尪���� ����
	char ss_open_close_code[3];	// ���ǰ��������ڵ�,BS:���尳��\n BE:��������\n SS:���ǰ���\n SE:��������\n SH:��������\n SR:�����簳
	char ss_id[3];	// ����ID,�ڵ尪��������
	int adj_stage;	// ����ܰ�,�ش���׾���
	char under_asset_prc_chg;	// �������񰡰�Ȯ��߻��ڵ�,�ش���׾���
	char exp_prc_chg_t[9];	// ����Ȯ�뿹���ð�,�ش���׾���
} DF_COM_FUT_MRK_OP_SCHD;


// ��ǰ����_�������
typedef struct _DF_COM_FUT_DIST_INFO {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����,O6
	char info_clsf[3];	// ��������,01:��ǰ����
	char mrk_clsf;	// ���屸��,6
	char isin_clsf[13];	// �����ڵ�
	int stk_snr;	// �����Ϸù�ȣ
	char brd_id[3];	// ����ID,�ڵ尪��������
	char dist_adj_code;	// ������뱸���ڵ�,1:��а���, 2:�������
	char dist_code;	// ���ó�������ڵ�,1:�ż�����, 2:�ż�����,\n 3:�ŵ�����, 4:�ŵ�����\n *��������� �ڵ����(spaceó��)
	char dist_cls_t[9];	// ��������ð�
} DF_COM_FUT_DIST_INFO;


// ��ǰ����_�ǽð������Ѱ� ���������
typedef struct _DF_COM_FUT_REAL_HIGH_LOW_LIMIT_ON_OFF {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����,Q2
	char info_clsf[3];	// ��������,01:��ǰ����
	char mrk_clsf;	// ���屸��,6
	char isin_clsf[13];	// �����ڵ�
	int stk_snr;	// �����Ϸù�ȣ
	char brd_id[3];	// ����ID,�ڵ尪��������
	char cleared_t[9];	// ó���ð�
	char real_t_prc_limit_code;	// �ǽð��������Ѽ����ڵ�,0: ����, 1: ����, 2: �缳��
	double real_t_high_prc;	// �ǽð����Ѱ�,��) 999999.99 ���߰��̵�����
	double real_t_low_prc;	// �ǽð����Ѱ�,��) 999999.99 ���߰��̵�����
} DF_COM_FUT_REAL_HIGH_LOW_LIMIT_ON_OFF;


// ��ǰ����_�̰����������� ������
typedef struct _DF_COM_FUT_OPEN_INTEREST_DATA {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����,H2
	char info_clsf[3];	// ��������,01:��ǰ����
	char mrk_clsf;	// ���屸��,6
	char isin_clsf[13];	// �����ڵ�,���� record '999999999999' set\n*���߰��̵� ���� : �ű�ä���� �߰�
	int stk_snr;	// ����SEQ
	char open_interest_clsf[3];	// �̰�����������,���� Ȯ�� : "M0" (07:40�а� ����)\n���� ���� : "M1" (���� Ư���������� ��������\n         �۽�, 10��)\n���� Ȯ�� : "M2" (���� ������ �۽�,\n         ������ 1�ð��� ����)
	char traded_date[9];	// �ŷ�����
	int open_interest_q;	// �̰�����������,����:���
} DF_COM_FUT_OPEN_INTEREST_DATA;


// ��ǰ����_���갡�� ������
typedef struct _DF_COM_FUT_SETT_PRC_DATA {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����,H3
	char info_clsf[3];	// ��������,01:��ǰ����
	char mrk_clsf;	// ���屸��,6
	char isin_clsf[13];	// �����ڵ�,���� record '999999999999' set\n*���߰��̵� ���� : �ű�ä���� �߰�
	int stk_snr;	// ����SEQ,�������� - �����ŷ����� ���� ������ 0���� ����
	double calc_prc;	// ���갡��,�������� - �����ŷ����� ���� ������ 0���� ����\n��) 99999999.99999999
	char calc_prc_clsf;	// ���갡�ݱ���,�������� - �����ŷ����� ���� ������ �������� ����\n0 : ���갡 ����(���� �ŷ������� �⼼ ����)\n1 : ���� ����(�Ǽ�)\n2 : ���� �⼼(���� �ŷ������� �⼼) - 2010.12.20 ����\n3 : ���� ���갡(���� �ŷ������� ���� ������) - 2010.12.20 ����\n4 : ���� �̷а�(���� �ŷ������� ���� ������)\n5 : ��������ŷ��� ���� ������ ������ ���� - 2010.12.20 ����\n6 : ������ ���� ���갡 - 2010.12.20 ����\n7 : ����ڻ� ����(�̷а����»�ǰ)\n8 : ������ذ��� - 2010.12.20 �߰�
	double final_sett_prc;	// ������������,��) 99999999.99999999
	char final_sett_clsf;	// �����������ݱ���
} DF_COM_FUT_SETT_PRC_DATA;


// ��ǰ����_������ ������
typedef struct _DF_COM_FUT_INVESTOR_DATA {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����,H1
	char info_clsf[3];	// ��������,01:��ǰ����
	char mrk_clsf;	// ���屸��,6
	char created_date[9];	// ��������
	char created_time[7];	// �����ð�
	char inv_data_clsf[3];	// �����ͱ���,*����Ȯ�� : 00, �������� : 01, ����Ȯ�� : 02\n *E1 : ���� ������ �Ϸ�, E2 : Ȯ�� ������ �Ϸ�\n ���� record '99' set
	char prd_id[12];	// ��ǰID,�ڵ尪��������
	char inv_clsf[5];	// ����������,�ڵ尪���� ���� *�ڵ� '7000'�� ����,��������׸� 0���� ����
	int long_exe_q;	// �ż���������
	int short_exe_q;	// �ŵ���������
	double long_traded_amt;	// �ż��������
	double short_traded_amt;	// �ŵ��������
	int spread_long_exe_q;	// �������忡 ���� ������ �ż� ��������
	int spread_short_exe_q;	// �������忡 ���� ������ �ŵ� ��������
	double spread_long_traded_amt;	// �������忡 ���� ������ �ż� �������
	double spread_short_traded_amt;	// �������忡 ���� ������ �ŵ� �������
} DF_COM_FUT_INVESTOR_DATA;


// ��ǰ����_�ü�Recovery ������
typedef struct _DF_COM_FUT_RECOVERY_DATA {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����,B2
	char info_clsf[3];	// ��������,01:��ǰ����
	char mrk_clsf;	// ���屸��,6
	char isin_clsf[13];	// �����ڵ�,*���߰��̵� ���� : �ű�ä���� �߰�
	int stk_snr;	// �����Ϸù�ȣ
	double cur_prc;	// ���簡,��) 999999.99
	double rct_prd_prc;	// �ֱٿ���������������,��) 999999.99
	double nxt_prd_prc;	// ������������������,��) 999999.99
	double init_prc;	// �ð�,��) 999999.99
	double high_prc;	// ��,��) 999999.99
	double low_prc;	// ����,��) 999999.99
	int open_interest_q;	// �̰�����
	int accm_exe_q;	// ����ü�����
	double accm_trd_amt;	// �����ŷ����,����:��
	char l_or_s;	// �����ŵ��ż������ڵ�,1:�ŵ�,2:�ż�(�������� ���� ȣ���� �ŵ��ż����а�)
	double s_lvl_1_prc;	// �ŵ�1ȣ��,��) 999999.99
	int s_lvl_1_q;	// �ŵ�1ȣ������
	int s_lvl_1_trd_cnt;	// �ŵ�1ȣ���Ǽ�
	double l_lvl_1_prc;	// �ż�1ȣ��,��) 999999.99
	int l_lvl_1_q;	// �ż�1ȣ������
	int l_lvl_1_trd_cnt;	// �ż�1ȣ���Ǽ�
	double s_lvl_2_prc;	// �ŵ�2ȣ��,��) 999999.99
	int s_lvl_2_q;	// �ŵ�2ȣ������
	int s_lvl_2_trd_cnt;	// �ŵ�2ȣ���Ǽ�
	double l_lvl_2_prc;	// �ż�2ȣ��,��) 999999.99
	int l_lvl_2_q;	// �ż�2ȣ������
	int l_lvl_2_trd_cnt;	// �ż�2ȣ���Ǽ�
	double s_lvl_3_prc;	// �ŵ�3ȣ��,��) 999999.99
	int s_lvl_3_q;	// �ŵ�3ȣ������
	int s_lvl_3_trd_cnt;	// �ŵ�3ȣ���Ǽ�
	double l_lvl_3_prc;	// �ż�3ȣ��,��) 999999.99
	int l_lvl_3_q;	// �ż�3ȣ������
	int l_lvl_3_trd_cnt;	// �ż�3ȣ���Ǽ�
	double s_lvl_4_prc;	// �ŵ�4ȣ��,��) 999999.99
	int s_lvl_4_q;	// �ŵ�4ȣ������
	int s_lvl_4_trd_cnt;	// �ŵ�4ȣ���Ǽ�
	double l_lvl_4_prc;	// �ż�4ȣ��,��) 999999.99
	int l_lvl_4_q;	// �ż�4ȣ������
	int l_lvl_4_trd_cnt;	// �ż�4ȣ���Ǽ�
	double s_lvl_5_prc;	// �ŵ�5ȣ��,��) 999999.99
	int s_lvl_5_q;	// �ŵ�5ȣ������
	int s_lvl_5_trd_cnt;	// �ŵ�5ȣ���Ǽ�
	double l_lvl_5_prc;	// �ż�5ȣ��,��) 999999.99
	int l_lvl_5_q;	// �ż�5ȣ������
	int l_lvl_5_trd_cnt;	// �ż�5ȣ���Ǽ�
	int total_s_limit_ord_q;	// �ŵ� ��ȣ������
	int total_s_trd_cnt;	// �ŵ���ȿȣ���Ǽ�
	int total_l_limit_ord_q;	// �ż� ��ȣ������
	int total_l_trd_cnt;	// �ż���ȿȣ���Ǽ�
	char ss_id[3];	// ����ID,�ڵ尪��������
	char brd_id[3];	// ����ID,�ڵ尪��������
	char brd_event_id[4];	// �����̺�ƮID,B2 ������ �����̺�ƮID ������(���� ���°��� ���۵� �� ����). ����, �ش� �׸� '000' ���� ����. 2014.03.24)
	double exp_prc;	// ����ü�ᰡ��,��) 999999.99 ���ϰ��ŸŽø� ����\n (����±����ڵ�:10,20,30,80)
	double real_t_high_prc;	// �ǽð����Ѱ�,��) 999999.99 ���߰��̵�����
	double real_t_low_prc;	// �ǽð����Ѱ�,��) 999999.99 ���߰��̵�����
} DF_COM_FUT_RECOVERY_DATA;


// ��ǰ����_�������� ������
typedef struct _DF_COM_FUTRE_PRD_INFO_DATA {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����,A0
	char info_clsf[3];	// ��������,01:��ǰ����
	char mrk_clsf;	// ���屸��,6
	int prd_cnt;	// �����
	char trd_date[9];	// ��������(��ȸ����)
	char isin_clsf[13];	// �����ڵ�,���� record '999999999999' set\n*���߰��̵� ���� : �ű�ä���� �߰�
	int stk_snr;	// ����SEQ
	char prd_id[12];	// ��ǰID,* �ڵ尪 ������ ����\n* ����Ī: �Ļ���ǰID\n10 => 11, 20140303
	char sh_prd_code[10];	// ��������ڵ�,��) KR4101C90009 �� K101C9000
	char prd_name_kor[81];	// �����ѱ۸�
	char sh_prd_name_kor[41];	// �����ѱ۾��
	char prd_name_eng[81];	// ���񿵹���
	char sh_prd_name_eng[41];	// ���񿵹����
	char listing_date[9];	// ��������,*���߰��̵� �����߰�    2009.08.31
	char de_listing_date[9];	// ������������
	char spread_clsf_code;	// ��������������񱸺��ڵ�,���������� ������ �Ǵ� ������ ISIN ǥ���ڵ�\n--�ڵ尪--\nF: ������(�ð���������)\nN: �ٿ���(�ð���������)\n20140303
	char final_sett_code;	// ������������ڵ�,���ݰ���, �ǹ��μ������� �� �Ļ���ǰ�� �������� ���\n--�ڵ尪--\nC: ���ݰ���\nD: �ǹ��μ�������\nA: ����+�ǹ��μ�������\n0: �ش����\n20140303
	char prc_limit_exp_dir;	// ��������Ȯ����������ڵ�,���������� �ٴܰ�� ���ǵǴ� ��� ���� �ܰ�� Ȯ��Ǵ� ����� ������ �� Ȯ�븦 �����ϴ� ����\n## �ڵ尪##\nX:������\nF:������\nB:������\nT:�����
	int prc_limit_final_stg;	// �������������ܰ�,���������� �ٴܰ�� ���ǵǴ� ��� ������ �����ܰ��ȣ
	double prc_limit_stg_1_high_prc;	// ��������1�ܰ���Ѱ�,��) 9999999999.99
	double prc_limit_stg_1_low_prc;	// ��������1�ܰ����Ѱ�,��) 9999999999.99
	double prc_limit_stg_2_high_prc;	// ��������2�ܰ���Ѱ�,��) 9999999999.99
	double prc_limit_stg_2_low_prc;	// ��������2�ܰ����Ѱ�,��) 9999999999.99
	double prc_limit_stg_3_high_prc;	// ��������3�ܰ���Ѱ�,��) 9999999999.99
	double prc_limit_stg_3_low_prc;	// ��������3�ܰ����Ѱ�,��) 9999999999.99
	double stand_prc;	// ���ذ�,��) 9999999999.99
	char under_asset_id[4];	// �����ڻ�ID,��) K2I:KOSPI200����, KQI:�ڽ���150����,\n   Sxx:�����ֽ�, BM3:��3�ⱹä,\n   BM5:��5�ⱹä, BMA:��10�ⱹä, \n   CDR:CD, USD:�̱��޷�, JPY:�Ϻ���,\n   EUR:��������,\n   GLD:��, LHG:����\n20140303
	char opt_type_code;	// �Ǹ���������ڵ�,A:�̱���,E:������,B:���´���,Z:��Ÿ\n20140303
	char spread_str_code[3];	// �������屸���ڵ�,Combination ȣ���� ��ü�� �������幰�� ���񱸼�.\n--�ڵ尪--\n- T1: �ֱٿ���+2°����\n      > T2, T3, T4, ...\n*����Ī: �������������ڵ�\n20140303
	char spread_prd_code_1[13];	// �������屸�������ڵ�1,* ����Ī: ��������ٿ��� �����ڵ�\n�ٿ��� ǥ���ڵ�\n20140303
	char spread_prd_code_2[13];	// �������屸�������ڵ�2,* ����Ī : ������������� �����ڵ�\n������ ǥ���ڵ�\n20140303
	char last_trading_date[9];	// �����ŷ�����
	char final_sett_date[9];	// ������������
	int cont_month_nbr;	// ��������ȣ,* ����Ī: ���������ڵ�\n1:�ֱٿ���,������������\n2:2°����\n3:3°����\n4:4°����\n5:5°����\n6:6°����\n7:7°����      �� �ֱٿ������� ��ġ\nX => 9, 1 => 3, 20140303
	char maturity_date[9];	// ��������,�Ǹ���� ������ ��������
	double exe_prc;	// ��簡��,��) 999999999.99999999
	char adjust_clsf_code;	// ���������ڵ�,�����ڻ��� ���ذ��� ������ ����� ����(�̰�������)���� ������� ����(�ŷ��¼�����)������ ����\n--�ڵ尪--\nN: ����\nO: �̰�������\nC: �ŷ��¼�����\n20140303
	double prd_unit;	// �ŷ�����,1��࿡ �ش��ϴ� �����ڻ����\n��) 999999999.99999999
	double multiplier;	// �ŷ��¼�,������� �� ������ ����ϴ� ���¼�\n��) 9999999999999.99999999
	char mrk_cnst_code;	// �������������ڵ�,0:�̽�����������\n1:���Ͻ�����������\n2:���Ž�����������
	char listing_type_code;	// ���������ڵ�,1:�űԻ���\n2:�߰�����\n3:��������\n4:���ʻ���\n5:��������\n6:Ư������
	double atm_prc;	// ���,�����ڻ���ذ��ݿ� ���� ����� ��簡��\n��) 9999999999.99
	char adj_reason_code[3];	// ���������ڵ�,00:�ش���׾���, 01:�Ǹ���, 02:����,\n03:�й��, 04:�ǹ��, 05:�߰�����,\n06:�Ǹ��߰�����, 99:��Ÿ
	char under_asset_prd_code[13];	// �����ڻ������ڵ�
	double under_asset_close_prc;	// �����ڻ�����,��) 9999999999.99
	int left_until_maturity;	// �����ϼ�
	double adj_std_prc;	// �������ذ���,�ֽ��Ļ���ǰ�� �����ֱ� �������ذ���\n��) 999999999.99999999
	char std_prc_clsf_code[3];	// ���ذ��ݱ����ڵ�,*����\nspcace:���ذ� ����(���� ������������)\n11:�������갡\n12:���ϱ��ذ�(�ŷ������� ����������)\n13:�����̷а�(�ŷ������� ����������)\n14:���ϱ⼼(�ŷ������� �⼼����)\n  -2012.05.14 ����\n15:�����̷а�(�ŷ������� �⼼����)-\n  -2012.05.14 ����\n16:������ �������갡\n17:������ ���ϱ��ذ�\n  (�ŷ������� ����������)\n18:������ ���ϱ⼼(�ŷ������� �⼼����)\n  -2012.05.14 ����\n19:���� ����ڻ� ����(�̷а����� ��ǰ)\n*�ɼ�\n21:�������űݱ��ذ�\n22:���ϱ��ذ�(�ŷ������� ����������)\n23:�����̷а�(�ŷ������� ����������)\n24:���ϱ⼼(�ŷ������� �⼼����)\n  -2012.05.14 ����\n25:������ �������űݱ��ذ�\n26:������ ���ϱ��ذ�\n  (�ŷ������� ����������)\n27:������ ���ϱ⼼(�ŷ������� �⼼����)\n  -2012.05.14 ����
	char trd_std_prc_clsf_code;	// �Ÿſ���ذ��ݱ����ڵ�,0:�ش����\n1:�Ǽ�\n2:�⼼\n3:�̷а�\n4:����ڻ�����\n*���߰��̵� �����߰�    2009.08.31
	double yest_adj_close_prc;	// ������������,�ֽ��Ļ���ǰ�� ��������\n��) 999999999.99999999
	char block_trd_clsf;	// ���Ǵ뷮�ŸŴ�󿩺�,Y:���ǸŸŻ�ǰ, N:���ƴ�\n����ǰ��:3�⹰��ä����, �̱��޷�����,\n      ���μ���, ������
	double yest_mrg_std_prc;	// �������űݱ��ذ���,��) 999999999.99999999
	char yest_mrg_std_prc_clsf_code[3];	// �������űݱ��ذ��ݱ����ڵ�,*�ɼ�\n20:���ű� ���ذ� ����\n21:��������(�Ǽ�)\n22:���ϱ⼼(�ŷ������ı⼼)\n  -2012.05.14 ����\n23:�������űݱ��ذ�\n  (�ŷ������� ����������)\n  -2012.05.14 ����\n24:�����̷а�(�ŷ������� ����������)\n25:�����������űݱ��ذ�\n  (�ŷ������� ����������)\n  -2012.05.14 ����
	double sett_theory_prc;	// �����̷а���,�ؿɼ��� ��� ���űݱ��ذ��� \n��) 999999999.999999
	double std_theory_prc;	// �����̷а���,��) 999999999.999999
	double yest_sett_prc;	// �������갡��,��) 999999999.99999999
	char halt_trd_clsf;	// �ŷ���������,Y, N
	double ft_cb_high_prc;	// ����Circuit_Breakers���Ѱ�,���� CB �ߵ������� �Ǵ��ϱ� ���� ����\n����(���ذ���� +/-5%�� CB �ߵ�\n������ ��� +5%�� ����� ����)\n��) 99+F31499999999.99
	double ft_cb_low_prc;	// ����Circuit_Breakers���Ѱ�,���� CB �ߵ������� �Ǵ��ϱ� ���� ����\n����(���ذ���� +/-5%�� CB �ߵ�\n������ ��� -5%�� ����� ����)\n��) 9999999999.99
	double check_exe_prc;	// ��ȸ����簡��,��) 999999999.99999999
	char atm_clsf;	// ATM�����ڵ�,0:����, 1:ATM, 2:ITM, 3:OTM
	char last_trading_clsf;	// �����ŷ��Ͽ���,Y, N
	double ex_divid_aft_value;	// �����Ĺ�簡ġ,�ֽ� �� �ְ����� ��ǰ���� �����\n- ���� : �����Ĺ̷���ġ\n- �ɼ� : ���������簡ġ\n��) 999999999.999999
	double yest_close_prc;	// ��������,��) 9999999999.99
	char yest_close_prc_clsf;	// �������������ڵ�,1:�Ǽ�, 3:�ŷ���\n2:�⼼ -2012.05.14 ����
	double yest_init_prc;	// ���Ͻð�,��) 9999999999.99
	double yest_high_pric;	// ���ϰ�,��) 9999999999.99
	double yest_low_prc;	// ��������,��) 9999999999.99
	char yest_first_exe_date[9];	// ����ü������
	char yest_last_exe_time[9];	// ��������ü��ð�
	char yest_sett_prc_clsf[3];	// �������갡�ݱ���,*����\n 10:���갡����\n 11:��������(�Ǽ�)\n 12:���ϱ⼼(�ŷ������ı⼼) - 2010.12.20 ����\n 13:�������갡(�ŷ������� ����������) - 2010.12.20 ����\n 14:�����̷а�(�ŷ������� ����������)\n 15:��������� ���� - 2010.12.20 ����\n 16:������ ���� ���갡 - 2010.12.20 ����\n 17:����ڻ� ����(�̷а����� ��ǰ)\n 18:������ذ��� - 2010.12.20 �߰�
	double sett_prc_theory_prc_diff_pctg;	// ���갡���̷а��ݱ�����,��) 999999.999999
	double yest_open_interest_q;	// ���Ϲ̰�����������
	double yest_s_limit_ord_prc;	// ���ϸŵ��켱ȣ������,��) 9999999999.99
	double yest_l_limit_ord_prc;	// ���ϸż��켱ȣ������,��) 9999999999.99
	double implied_vol;	// ���纯����,��) 999999.9999
	double listed_high_prc;	// �������ְ�,��) 9999999999.99
	double listed_low_prc;	// ������������,��) 9999999999.99
	double year_high_prc;	// �����ְ�,��) 9999999999.99
	double year_low_prc;	// ����������,��) 9999999999.99
	char listed_high_prc_date[9];	// �������ְ�����
	char listed_low_prc_date[9];	// ����������������
	char year_high_prc_date[9];	// �����ְ�����
	char year_low_prc_date[9];	// ��������������
	int year_std_date;	// ���������ϼ�
	int month_trd_date;	// �����ŷ��ϼ�
	int year_trd_date;	// �����ŷ��ϼ�
	double yest_exe_trd_cnt ;	// ����ü��Ǽ�
	double yest_exe_q;	// ����ü�����,�������Ǵ뷮�Ÿ�ü������� ���Ե��� ����
	double yest_trd_amt;	// ���ϰŷ����,�������Ǵ뷮�ŸŰŷ������ ���Ե��� ����
	double yest_block_trd_exe_q;	// �������Ǵ뷮�ջ�ü�����,�������Ǵ뷮�Ÿ�ü����� => �������Ǵ뷮�ջ�ü����� [����ü�����+�������Ǵ뷮�Ÿ�ü�����(���Ǵ뷮+FLEX)] 2016.03.28 ����
	double yest_block_trd_total_amt;	// �������Ǵ뷮�ջ�ŷ����,�������Ǵ뷮�ŸŰŷ���� => �������Ǵ뷮�ջ�ŷ���� [���ϰŷ����+�������Ǵ뷮�ŸŰŷ����(���Ǵ뷮+FLEX)] 2016.03.28 ����
	double cd_rate;	// CD�ݸ�,��) 999.999
	double open_interest_q;	// �̰����ѵ�����,*�����Ͽ� ����Ǵ� ��ǰ�� ���º�\n �̰��� �ѵ� ����. �̰��� �ѵ���\n ������� ���� ��ǰ�� 0\n*�ֽļ������� �ش�\n8 => 15, 20140303
	char product_cat[5];	// �Ҽ� ��ǰ��,*�ֽļ���/�ɼǿ��� �ش�
	double product_cat_off_pctg;	// ��ǰ�� �ɼ���,*������� ǥ��\n*�ֽļ���/�ɼǿ��� �ش翹) 9999999.99\n5 => 9, 20140303
	int limit_ord_clsf_code;	// ������ȣ�����Ǳ����ڵ�,ȣ���� ü�� �� �ܷ�����. Bitwise ����\n--�ڵ尪--\n1: FAS (Fill And Store)\n2: FOK (Fill Or Kill)\n3: FAK (Fill And Kill)\n\n* ������ȣ�����Ǳ����ڵ� BITWISE ����\n���� Ȯ�强�� ���� �ش� 10�������� 2������ ��ȯ�Ͽ� ó�����(�ִ� 16bit���� ��밡��)\n�� ) ������ȣ�����Ǳ����ڵ� ���� 6�̸�\n    (������ 6 -> ������ 00000110)\n0��° bit 0 -> 0 : FAS\n1��° bit 1 -> 2 : FOK\n2��° bit 1 -> 4 : FAK\n��, FOK�̸鼭 FAK�� �����Ѵٴ� �ǹ� (FOK & FAK)\nX => 9, 1 => 5, 20140303
	int mrk_ord_clsf_code;	// ���尡ȣ�����Ǳ����ڵ�,* ��
	int cond_limit_ord_clsf_code;	// ���Ǻ�������ȣ�����Ǳ����ڵ�,* ��
	int best_limit_ord_clsf_code;	// ������������ȣ�����Ǳ����ڵ�,* ��
	char efp_clsf;	// EFP�ŷ���󿩺�,Y, N, ��ǰ������ �ش�  2009.08.31
	char flex_clsf;	// FLEX�ŷ���󿩺�,Y, N, ��ǰ������ �ش�  2009.08.31
	double yest_efp_exe_q;	// ����EFPü�����,��ǰ������ �ش�       2009.08.31
	double yest_efp_trd_amount;	// ����EFP�ŷ����,��ǰ������ �ش�       2009.08.31
	char mkr_close_clsf;	// ���忩��,���忩�� (Y,N), 20121217
	char real_t_prc_limit_clsf;	// �ǽð��������ѿ���,���� ü�ᰡ�� ��� Ư�� ������ �ʰ��ϴ� ȣ���� �ź��ϵ��� �������� ����(Y/N) 20140901
	double real_t_high_price_gap;	// �ǽð����Ѱ�����,���� ü�ᰡ�ݰ� �ǽð����Ѱ����� ����\n�ǽð����Ѱ� = ����ü�ᰡ�� + �ǽð����Ѱ�����\nex) 9999999999.99 20140901
	double real_t_low_price_gap;	// �ǽð����Ѱ�����,���� ü�ᰡ�ݰ� �ǽð����Ѱ����� ����\n�ǽð����Ѱ� = ����ü�ᰡ�� + �ǽð����Ѱ�����(����)\nex) 9999999999.99 20140901
	char under_ass_mrk_id[4];	// �����ڻ����ID,�����ڻ����ID�� �����ڻ��� KRX�� ����� ��쿡�� ä����.\nK200�����ɼ�:STK\n�ڽ���150����:KSQ\n�ֽļ����ɼ�:STK/KSQ\n��ǰ�����ɼ�:SPACE\n��������������:STK\n������������:STK\n�̴�K200�����ɼ�:STK
} DF_COM_FUTRE_PRD_INFO_DATA;


// ��������_��ä_CD_������
typedef struct _DF_GOV_BOND_CD_DATA {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����,H5
	char info_clsf[3];	// ��������,01:��ǰ����,\n���� record '99' set
	char mrk_clsf;	// ���屸��,6
	char send_date[9];	// ��������,YYYYMMDD
	char send_time[7];	// ���۽ð�,HHMMSS
	char uder_asset_clsf[7];	// �����ڻ걸��,BM3,BM5,BMA,CD,MSB   2010.10.25\n*�׸�� ����\n �����ڻ�ID->�����ڻ걸��  2009.08.31\n*MSB�����ߴ�          2011.05.02
	double final_ord_return_pctg;	// ����ȣ�����ͷ�,999.99999\nCD(91��),��ä(3��,5��,10��)\n*MSB�����ߴ�          2011.05.02
	char gov_bond_code[13];	// ��ä�ڵ�,��ä������ �������ä���ڵ�
	char gov_bond_prd_code[13];	// ��ä���������ڵ�
	char data_created_t[7];	// ������ �߻��ð�,HHMMSS
} DF_GOV_BOND_CD_DATA;


// ��������_��������ä��_������
typedef struct _DF_STD_GOV_BOND_DATA {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����,H6
	char info_clsf[3];	// ��������,01:��ǰ����,\n���� record '99' set
	char mrk_clsf;	// ���屸��,6
	char adj_date[9];	// ������,�����ڷ� ���۵�
	char prd[5];	// ��ǰ,BM3,BM5,BMA   2010.10.25
	char fut_prd_code[13];	// ���������ڵ�,���� �ŷ� ����� ����
	char under_asset_bond_code[13];	// ä���ڵ�,��ä������ �������ä���ڵ�
	double conv_coef;	// ��ȯ���,�μ������� ��ä������ ��츸 �ش��\n��) 99.999999\n'00000000' ó��   2010.10.25
} DF_STD_GOV_BOND_DATA;


// ��������_USD_������
typedef struct _DF_USD_DATA {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����,H9
	char info_clsf[3];	// ��������,01:��ǰ����,\n���� record '99' set
	char mrk_clsf;	// ���屸��,6
	char send_date[9];	// ��������,YYYYMMDD
	char send_time[7];	// ���۽ð�,HHMMSS
	char under_asset_id[7];	// �����ڻ�ID,USD
	double s_limit_ord_prc;	// �ŵ�ȣ��,��) 9999.99
	int l_limit_ord_prc;	// �ż�ȣ��
	int yest_close_prc;	// ��������
	int init_prc;	// �ð�
	int low_prc;	// ����
	int high_prc;	// ��
	int exe_prc;	// ü�ᰡ
	char data_created_t[7];	// ������ �߻��ð�,HHMMSS
} DF_USD_DATA;


// ��������_USD��ġ_������1
typedef struct _DF_USD_BATCH_DATA_1 {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����,I0
	char info_clsf[3];	// ��������,01:��ǰ����,\n���� record '99' set
	char mrk_clsf;	// ���屸��,6
	char job_clsf_code[5];	// ���������ڵ�,FBB1(��/�޷� ���Ͻð��뺰 �ŷ���Ȳ)
	int trd_date;	// �ŷ���
	char trd_hour[10];	// �ð���,HHMM-HHMM
	double spread_low_rate;	// LOW RATE(SP),9999.9
	double spread_high_rate;	// HIGH RATE(SP),9999.9
	double spread_vol;	// VOLUME(SP),9999.9
} DF_USD_BATCH_DATA_1;


// ��������_USD��ġ_������2
typedef struct _DF_USD_BATCH_DATA_2 {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����,I0
	char info_clsf[3];	// ��������,01:��ǰ����,\n���� record '99' set
	char mrk_clsf;	// ���屸��,6
	char job_clsf_code[5];	// ���������ڵ�,FBC1(��/�޷� ���� ���Ϲ��� ü����Ȳ1)
	int trd_date;	// �ŷ���,YYYYMMDD
	char fixed_date_clsf[3];	// ���Ϲ�����,*���Ϲ����� ����
	int maturity_date;	// ������(������),YYYYMMDD
	double low_rate;	// LOW RATE,9999.99
	double high_rate;	// HIGH RATE,9999.99
	double open_rate;	// OPEN RATE,9999.99
	double close_rate;	// CLOSE RATE,9999.99
} DF_USD_BATCH_DATA_2;


// ��������_USD��ġ_������3
typedef struct _DF_USD_BATCH_DATA_3 {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����,I0
	char info_clsf[3];	// ��������,01:��ǰ����,\n���� record '99' set
	char mrk_clsf;	// ���屸��,6
	char job_clsf_code[5];	// ���������ڵ�,FBC2(��/�޷� ���� ���Ϲ��� ü����Ȳ2)
	int trd_date;	// �ŷ���,YYYYMMDD
	char fixed_date_clsf[3];	// ���Ϲ�����,*���Ϲ����� ����
	int maturity_date;	// ������(������),YYYYMMDD
	double vol;	// VOLUME,9999.9
	double avg_rate;	// AVERAGE RATE,9999.99
	double mar;	// MAR,9999.9
} DF_USD_BATCH_DATA_3;


// ��������_USD��ġ_������4
typedef struct _DF_USD_BATCH_DATA_4 {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����,I0
	char info_clsf[3];	// ��������,01:��ǰ����,\n���� record '99' set
	char mrk_clsf;	// ���屸��,6
	char job_clsf_code[5];	// ���������ڵ�,FBD1(ȯ����� ����ȯ�� ��Ȳ)
	int informed_date;	// �����,YYYYMMDD
	char currency_name[4];	// ��ȭ��,��)��ȭ�� ����
	double cross_rate;	// CROSS RATE,9999.99999
	double fx_rate;	// ȯ��,9999.99
} DF_USD_BATCH_DATA_4;


// ��������_USD��ġ_������5
typedef struct _DF_USD_BATCH_DATA_5 {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����,I0
	char info_clsf[3];	// ��������,01:��ǰ����,\n���� record '99' set
	char mrk_clsf;	// ���屸��,6
	char job_clsf_code[5];	// ���������ڵ�,FBE1(SWAP ������ ���Ϲ��� ü����Ȳ)
	int trd_date;	// �ŷ���,YYYYMMDD
	char fixed_date_clsf[3];	// ���Ϲ�����,��)���Ϲ����� ����
	int maturity_date;	// ������(������),YYYYMMDD
	int low_rate;	// LOW RATE,��9999
	int high_rate;	// HIGH RATE,��9999
	int open_rate;	// OPEN RATE,��9999
	int close_rate;	// CLOSE RATE,��9999
	int avg_rate;	// AVERAGE RATE,��9999
	double vol;	// VOLUME,9999.9
} DF_USD_BATCH_DATA_5;


// ��������_USD��ġ_������6
typedef struct _DF_USD_BATCH_DATA_6 {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����,I0
	char info_clsf[3];	// ��������,01:��ǰ����,\n���� record '99' set
	char mrk_clsf;	// ���屸��,6
	char job_clsf_code[5];	// ���������ڵ�,FBF1(��/�޷� ����ȯ�� : ��ȭ����ȯ�����)
	int std_date;	// ������,YYYYMMDD
	char fixed_date_clsf_0[3];	// ���Ϲ�����,��)����ȯ�����Ϲ����� ����
	double rate_0;	// RATE,9999.99
	char fixed_date_clsf_1[3];	// ���Ϲ�����,��)����ȯ�����Ϲ����� ����
	double rate_1;	// RATE,9999.99
	char fixed_date_clsf_2[3];	// ���Ϲ�����,��)����ȯ�����Ϲ����� ����
	double rate_2;	// RATE,9999.99
	char fixed_date_clsf_3[3];	// ���Ϲ�����,��)����ȯ�����Ϲ����� ����
	double rate_3;	// RATE,9999.99
} DF_USD_BATCH_DATA_6;


// ��������_USD��ġ_������7
typedef struct _DF_USD_BATCH_DATA_7 {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����,I0
	char info_clsf[3];	// ��������,01:��ǰ����,\n���� record '99' set
	char mrk_clsf;	// ���屸��,6
	char job_clsf_code[5];	// ���������ڵ�,FBF2(��/�޷� ���� ȯ�� : ��������Ʈ ���))
	int std_date;	// ������,YYYYMMDD
	char fixed_date_clsf_0[3];	// ���Ϲ�����,��)����ȯ�����Ϲ����� ����
	double rate_0;	// RATE,9999.99
	char fixed_date_clsf_1[3];	// ���Ϲ�����,��)����ȯ�����Ϲ����� ����
	double rate_1;	// RATE,9999.99
	char fixed_date_clsf_2[3];	// ���Ϲ�����,��)����ȯ�����Ϲ����� ����
	double rate_2;	// RATE,9999.99
	char fixed_date_clsf_3[3];	// ���Ϲ�����,��)����ȯ�����Ϲ����� ����
	double rate_3;	// RATE,9999.99
} DF_USD_BATCH_DATA_7;


// ��������_USD��ġ_������8
typedef struct _DF_USD_BATCH_DATA_8 {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����,I0
	char info_clsf[3];	// ��������,01:��ǰ����,\n���� record '99' set
	char mrk_clsf;	// ���屸��,6
	char job_clsf_code[5];	// ���������ڵ�,FBG1(����� ����ȯ��)
	char informed_date[9];	// �����,YYYYMMDD
	double std_year_month;	// ���س��,9999.99
	double avg_fx_rate;	// ��ձ���ȯ��,9999.99
} DF_USD_BATCH_DATA_8;


// ��������_USD��ġ_������9
typedef struct _DF_USD_BATCH_DATA_9 {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����,I0
	char info_clsf[3];	// ��������,01:��ǰ����,\n���� record '99' set
	char mrk_clsf;	// ���屸��,6
	char job_clsf_code[5];	// ���������ڵ�,CBA1(��ȭ ���� �ŷ����1)
	char trd_date[9];	// �ŷ���,YYYYMMDD
	char currency_name[4];	// ��ȭ��,��)��ȭ�� ����
	double open_rate;	// OPEN RATE,99.99999
	double high_rate;	// HIGH RATE,99.99999
	double low_rate;	// LOW RATE,99.99999
	double close_rate;	// CLOSE RATE,99.99999
} DF_USD_BATCH_DATA_9;


// ��������_USD��ġ_������10
typedef struct _DF_USD_BATCH_DATA_10 {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����,I0
	char info_clsf[3];	// ��������,01:��ǰ����,\n���� record '99' set
	char mrk_clsf;	// ���屸��,6
	char job_clsf_code[5];	// ���������ڵ�,CBA2(��ȭ ���� �ŷ����2)
	char trd_date[9];	// �ŷ���,YYYYMMDD
	char currency_name[4];	// ��ȭ��,��)��ȭ�� ����
	double ave_rate;	// AVERAGE RATE,99.9999
	double o_n_vol;	// O/N VOLUME,9999.99
	double total_vol;	// TOTAL VOLUME,9999.99
	double libor_rate;	// LIBOR,9.99999
	double sibor_rate;	// SIBOR,9.99999
} DF_USD_BATCH_DATA_10;


// ��������_USD�ǽð�����_������1
typedef struct _DF_USD_REAL_TIME_DATA_1 {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����,I1
	char info_clsf[3];	// ��������,01:��ǰ����,\n���� record '99' set
	char mrk_clsf;	// ���屸��,6
	char job_clsf_code[5];	// ���������ڵ�,FOC1(��/�޷� �ð��뺰 �ŷ���Ȳ)
	int trd_date;	// �ŷ���,YYYYMMDD
	char trd_hour[10];	// �ð���,HHMM-HHMM
	double spread_low_rate;	// LOW RATE(SP),9999.99
	double spread_high_rate;	// HIGH RATE(SP),9999.99
} DF_USD_REAL_TIME_DATA_1;


// ��������_USD�ǽð�����_������2
typedef struct _DF_USD_REAL_TIME_DATA_2 {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����,I1
	char info_clsf[3];	// ��������,01:��ǰ����
	char mrk_clsf;	// ���屸��,6
	char job_clsf_code[5];	// ���������ڵ�,FOD1(��/�޷� ���Ϲ��� ������Ȳ)
	int trd_date;	// �ŷ���,YYYYMMDD
	char fixed_date_clsf[3];	// ���Ϲ�����,��)���Ϲ���������
	int maturity_date;	// ������(������),YYYYMMDD
	double bid_best;	// BID BEST,9999.9
	double offer_best;	// OFFER BEST,9999.9
	double bid_vol;	// BID VOLUME,9999.9
	double offer_vol;	// OFFER VOLUME,9999.9
	double prev_rate;	// PREV RATE,9999.9
} DF_USD_REAL_TIME_DATA_2;


// ��������_USD�ǽð�����_������3
typedef struct _DF_USD_REAL_TIME_DATA_3 {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����,I1
	char info_clsf[3];	// ��������,01:��ǰ����
	char mrk_clsf;	// ���屸��,6
	char job_clsf_code[5];	// ���������ڵ�,FOE1(��/�޷� ���Ϲ��� ü����Ȳ) (����->ü��)����
	int trd_date;	// �ŷ���,YYYYMMDD
	char fixed_date_clsf[3];	// ���Ϲ�����,��)���Ϲ���������
	int maturity_date;	// ������(������),YYYYMMDD
	double low_rate;	// LOW RATE,9999.9
	double high_rate;	// HIGH RATE,9999.9
	double open_rate;	// OPEN RATE,9999.9
	double close_rate;	// CLOSE RATE,9999.9
} DF_USD_REAL_TIME_DATA_3;


// ��������_CNH�ǽð�����_������
typedef struct _DF_CNH_REAL_TIME_DATA {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����,I1
	char info_clsf[3];	// ��������,01:��ǰ����
	char mrk_clsf;	// ���屸��,6
	char job_clsf_code[5];	// ���������ڵ�,HOE1(��/���� ���Ϲ��� ü����Ȳ)
	int trd_date;	// �ŷ���,YYYYMMDD
	char fixed_date_clsf[3];	// ���Ϲ�����,��)���Ϲ���������
	int maturity_date;	// ������(������),YYYYMMDD
	double low_rate;	// LOW RATE,9999.9
	double high_rate;	// HIGH RATE,9999.9
	double open_rate;	// OPEN RATE,9999.9
	double close_rate;	// CLOSE RATE,9999.9
} DF_CNH_REAL_TIME_DATA;


// ��������_USD�ǽð�����_������4
typedef struct _DF_USD_REAL_TIME_DATA_4 {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����,I1
	char info_clsf[3];	// ��������,01:��ǰ����
	char mrk_clsf;	// ���屸��,6
	char job_clsf_code[5];	// ���������ڵ�,FOF1(SWAP ���Ϲ��� ������Ȳ)
	int trd_date;	// �ŷ���,YYYYMMDD
	char fixed_date_clsf[3];	// ���Ϲ�����,��)���Ϲ���������
	int maturity_date;	// ������(������),YYYYMMDD
	int bid_best;	// BID BEST,��9999
	int offer_best;	// OFFER BEST,��9999
	double bid_vol;	// BID VOLUME,9999.9
	double offer_vol;	// OFFER VOLUME,9999.9
	int prev_rate;	// PREV RATE,��9999
} DF_USD_REAL_TIME_DATA_4;


// ��������_USD�ǽð�����_������5
typedef struct _DF_USD_REAL_TIME_DATA_5 {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����,I1
	char info_clsf[3];	// ��������,01:��ǰ����
	char mrk_clsf;	// ���屸��,6
	char job_clsf_code[5];	// ���������ڵ�,FOG1(SWAP ���Ϲ��� ü����Ȳ)
	int trd_date;	// �ŷ���,YYYYMMDD
	char fixed_date_clsf[3];	// ���Ϲ�����,��)���Ϲ���������
	int maturity_date;	// ������(������),YYYYMMDD
	int low_rate;	// LOW RATE,��9999
	int high_rate;	// HIGH RATE,��9999
	int open_rate;	// OPEN RATE,��9999
	int close_rate;	// CLOSE RATE,��9999
} DF_USD_REAL_TIME_DATA_5;


// ��������_USD�ǽð�����_������8
typedef struct _DF_USD_REAL_TIME_DATA_8 {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����,I1
	char info_clsf[3];	// ��������,01:��ǰ����
	char mrk_clsf;	// ���屸��,6
	char job_clsf_code[5];	// ���������ڵ�,UOD1(���޷� SPOT ��� ȯ��ȣ��)
	int trd_date;	// �ŷ���,YYYYMMDD
	char fixed_date_clsf[3];	// ���Ϲ�����,��)���Ϲ� ����
	int maturity_date;	// ������(������),YYYYMMDD
	char bank_name[11];	// �����,���������
	double bid_best;	// BID BEST,9999.9
	double offer_best;	// OFFER BEST,9999.9
	double low_rate;	// LOW RATE,9999.9
	double high_rate;	// HIGH RATE,9999.9
	double open_rate;	// OPEN RATE,9999.9
	double mar;	// MAR,9999.9
} DF_USD_REAL_TIME_DATA_8;


// ��������_USD�ǽð�����_������7
typedef struct _DF_USD_REAL_TIME_DATA_7 {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����,I1
	char info_clsf[3];	// ��������,01:��ǰ����
	char mrk_clsf;	// ���屸��,6
	char job_clsf_code[5];	// ���������ڵ�,COA1(��ȭ ���Ϲ��� ������Ȳ)
	int trd_date;	// �ŷ���,YYYYMMDD
	char currency_name[4];	// ��ȭ��,��)��ȭ�� ����
	char fixed_date_clsf[3];	// ���Ϲ� ����,��)���Ϲ� ����
	double bid_rate;	// BID RATE,99999.99
	double offer_rate;	// OFFER RATE,99999.99
	double bid_vol;	// BID VOLUME,9999.99
	double offer_vol;	// OFFER VOLUME,9999.99
} DF_USD_REAL_TIME_DATA_7;


// ��������_USD�ǽð�����_������6
typedef struct _DF_USD_REAL_TIME_DATA_6 {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����,I1
	char info_clsf[3];	// ��������,01:��ǰ����
	char mrk_clsf;	// ���屸��,6
	char job_clsf_code[5];	// ���������ڵ�,FOQ1(����ȯ �ð��뺰 BID-OFFER ȣ�� ��Ȳ)
	int trd_date;	// �ŷ���,YYYYMMDD
	char td_hour[5];	// �ð���,HHMM
	double spread_bid_prc;	// BID ȣ��(SP),9999.9
	double spread_ask_prc;	// OFFER ȣ��(SP),9999.9
} DF_USD_REAL_TIME_DATA_6;


// ��ǰ����_Polling ������
typedef struct _DF_COM_FUT_POLLING_DATA {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����,I2
	char info_clsf[3];	// ��������,01:��ǰ����
	char mrk_clsf;	// ���屸��,6
	char send_time[5];	// ���۽ð�,HHSS
	char main_backup_clsf[3];	// Main Backup����,space
} DF_COM_FUT_POLLING_DATA;


// ��������_USD�ǽð�����_������9
typedef struct _DF_USD_REAL_TIME_DATA_9 {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����,I1
	char info_clsf[3];	// ��������,01:��ǰ����
	char mrk_clsf;	// ���屸��,6
	char job_clsf_code[5];	// ���������ڵ�,UOE1(���޷� SPOT 30�д��� �ణ ȯ��ü�ᰡ)
	int trd_date;	// �ŷ���,YYYYMMDD
	char fixed_date_clsf[3];	// ���Ϲ�����,SP
	int maturity_date;	// ������(������),YYYYMMDD
	int exe_t;	// ü��ð�,HHMM(0930, 1000,1030,1100,1130,1200,1230,\n1300,1330,1400, 1430, 1500)
	double exe_prc;	// ü�ᰡ,9999.9
} DF_USD_REAL_TIME_DATA_9;


// ��������_������ǥ��������_������
typedef struct _DF_LEAN_HOG_REP_PRC_INDEX_DATA {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����,H8
	char info_clsf[3];	// ��������,01:��ǰ����
	char mrk_clsf;	// ���屸��,6
	char data_type;	// ������ Ÿ��,D:���� ��ǥ���� ����
	char inform_date_yest[9];	// ��������-����
	char inform_date_close_yest[9];	// ��������-������
	int accum_mrk_nbr;	// ���赵�Ž����,����
	int accum_prd_nbr;	// ����μ�,��
	double trd_weight_total;	// �ŷ� ��ü�� �հ�,kg
	double trd_prc_total;	// �ŷ� ���� �հ�,��
	int rep_prc;	// ��ǥ ����,��/kg
} DF_LEAN_HOG_REP_PRC_INDEX_DATA;


// ��������_�����ǽð���������_������
typedef struct _DF_LEAN_HOG_REAL_TIME_PRC_INDEX_DATA {
	double timestamp;	// timestamp
	char data_cslf[3];	// DATA����,H8
	char info_clsf[3];	// ��������,01:��ǰ����
	char mrk_clsf;	// ���屸��,6
	char data_type;	// ������ Ÿ��,L:�ǽð� �������� ����
	char inform_time[5];	// ���ýð�
	char inform_date_yest[9];	// ��������-����
	char inform_date_today[9];	// ��������-����
	int accum_mrk_nbr;	// ���� ���Ž��� ��,����
	int accum_prd_nbr;	// ����μ�,��
	double trd_weight_total;	// �ŷ� ��ü�� �հ�,kg
	double trd_prc_total;	// �ŷ� ���� �հ�,��
	int under_asset_prc;	// ���� ����,��/kg
} DF_LEAN_HOG_REAL_TIME_PRC_INDEX_DATA;


// ��������_����������������_������
typedef struct _DF_LEAN_HOG_CLOSE_PRICE_INDEX_DATA {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����,H8
	char info_clsf[3];	// ��������,01:��ǰ����,\n���� record '99' set
	char mrk_clsf;	// ���屸��,6
	char data_type;	// ������ Ÿ��,E:�ǽð� �������� ��������
	char inform_date_today[9];	// �������� ����
	char inform_date_yest[9];	// �������� ����
	int accum_mrk_nbr;	// ���� ���Ž��� ��
	int accum_prd_nbr;	// ���� �μ�,����
	double trd_weight_total;	// �ŷ� ��ü�� �հ�,��
	double trd_prc_total;	// �ŷ� ���� �հ�,kg
	int init_prc;	// ���� ����,��
	int high_prc;	// �ְ� ����,��/kg
	int low_prc;	// ���� ����
	int close_prc;	// ���� ����
} DF_LEAN_HOG_CLOSE_PRICE_INDEX_DATA;


// ��ǰ����_SPACE
typedef struct _DF_COM_FUT_SPACE {
	double timestamp;	// timestamp
	char data_clsf[3];	// DATA����,G9
	char info_clsf[3];	// ��������,01:��ǰ����
	char mrk_clsf;	// ���屸��,6
} DF_COM_FUT_SPACE;
