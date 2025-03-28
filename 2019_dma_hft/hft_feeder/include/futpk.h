#ifndef _FUTPK_H_
#define _FUTPK_H_

#include "zconf.h"

#define TICK_CNT    10

typedef struct _proc_list
{
    char    id[6];
    int     (*AppProc)(char *buff);
    char    tname[30];
} PROC_LIST;

/* hader file �ߺ� ���� �ذ� */
#ifdef ZAPLST

int FutProcB6014(char *buff);
int FutProcA3014(char *buff);
int FutProcG7014(char *buff);

PROC_LIST AppList[] = {
{"B6014",     FutProcB6014, "K200_FUT_LIMIT_ORD"      },
{"G7014",     FutProcG7014, "K200_FUT_EXEC_LIMIT_ORD"   },
{"A3014",     FutProcA3014, "K200_FUT_EXEC"             },
};

#define AP_CNT	( sizeof(AppList)/sizeof(PROC_LIST))

#endif                    

//K200����_ü��	A3014	������ �߻��ø��� �ǽð� ����	117
typedef struct _PK_TICK {
    char ask_prc          [9 ];	// �ŵ�ȣ��1
	char bid_prc          [9 ];	// �ż�ȣ��1
	char ask_vol_rsd      [12];	// �ŵ�ȣ�� �ܷ�1
	char bid_vol_rsd      [12];	// �ż�ȣ�� �ܷ�1    
} PK_TICK; 

typedef struct _PK_TICKLP {
    char ask_prc          [9 ];	// �ŵ�ȣ��1
	char bid_prc          [9 ];	// �ż�ȣ��1
	char ask_vol_rsd      [12];	// �ŵ�ȣ�� �ܷ�1
	char bid_vol_rsd      [12];	// �ż�ȣ�� �ܷ�1  
	char lp_ask_vol_rsd   [12];	// LP �ŵ�ȣ�� �ܷ�1
	char lp_bid_vol_rsd   [12];	// LP �ż�ȣ�� �ܷ�1  
} PK_TICKLP; 

//  G7014 : K200����_ü��_�켱ȣ��
typedef struct _K200_FUT_EXEC_LIMIT_ORD {
	char data_clsf[2];	// DATA����,G7
	char info_clsf[2];	// ��������,01:KOSPI200��������
	char mrk_clsf[1];	// ���屸��,4
	char isin_clsf[12];	// �����ڵ�
	char seq[2];	// �����Ϸù�ȣ
	char brd_id[2];	// ����ID,�ڵ尪��������
	char cur_prc_sign[1];	// ���簡�ݺ�ȣ
	char cur_price[5];	// ���簡��,��) 999.99
	char exe_q[6];	// ü�����
	char ss_id[2];	// ����ID,�ڵ尪��������
	char exe_t[8];	// ü��ð�
	char rct_prd_prc[5];	// �ֱٿ���������������,��) 999.99
	char nxt_prd_prc[5];	// ������������������,��) 999.99
	char init_prc_sign[1];	// �ð���ȣ
	char init_prc[5];	// �ð�,��) 999.99
	char high_prc_sign[1];	// ����ȣ
	char high_prc[5];	// ��,��) 999.99
	char low_prc_sign[1];	// ������ȣ
	char low_prc[5];	// ����,��) 999.99
	char pri_prc_sign[1];	// �������ݺ�ȣ
	char pri_prc[5];	// ��������,��) 999.99
	char accm_exe_q[7];	// ����ü�����
	char accm_trd_amt[12];	// �����ŷ����,����:õ��
	char accm_block_trd_exe_q[7];	// ���Ǵ뷮����ü�����,������(Filler)
	char l_or_s[1];	// �����ŵ��ż������ڵ�,1:�ŵ�,2:�ż�(�������� ���� ȣ���� �ŵ��ż����а�)
	char total_l_limit_ord_q[6];	// �ż���ȣ���ܷ�
	char l_lvl_1_sign[1];	// �ż�1�ܰ��ȣ
	char l_lvl_1_prc[5];	// �ż�1�ܰ�켱ȣ������,��) 999.99
	char l_lvl_1_q[6];	// �ż�1�ܰ�켱ȣ���ܷ�
	char l_lvl_2_sign[1];	// �ż�2�ܰ��ȣ
	char l_lvl_2_prc[5];	// �ż�2�ܰ�켱ȣ������,��) 999.99
	char l_lvl_2_q[6];	// �ż�2�ܰ�켱ȣ���ܷ�
	char l_lvl_3_sign[1];	// �ż�3�ܰ��ȣ
	char l_lvl_3_prc[5];	// �ż�3�ܰ�켱ȣ������,��) 999.99
	char l_lvl_3_q[6];	// �ż�3�ܰ�켱ȣ���ܷ�
	char l_lvl_4_sign[1];	// �ż�4�ܰ��ȣ
	char l_lvl_4_prc[5];	// �ż�4�ܰ�켱ȣ������,��) 999.99
	char l_lvl_4_q[6];	// �ż�4�ܰ�켱ȣ���ܷ�
	char l_lvl_5_sign[1];	// �ż�5�ܰ��ȣ
	char l_lvl_5_prc[5];	// �ż�5�ܰ�켱ȣ������,��) 999.99
	char l_lvl_5_q[6];	// �ż�5�ܰ�켱ȣ���ܷ�
	char total_s_limit_ord_q[6];	// �ŵ���ȣ���ܷ�
	char s_lvl_1_sign[1];	// �ŵ�1�ܰ��ȣ
	char s_lvl_1_prc[5];	// �ŵ�1�ܰ�켱ȣ������,��) 999.99
	char s_lvl_1_q[6];	// �ŵ�1�ܰ�켱ȣ���ܷ�
	char s_lvl_2_sign[1];	// �ŵ�2�ܰ��ȣ
	char s_lvl_2_prc[5];	// �ŵ�2�ܰ�켱ȣ������,��) 999.99
	char s_lvl_2_q[6];	// �ŵ�2�ܰ�켱ȣ���ܷ�
	char s_lvl_3_sign[1];	// �ŵ�3�ܰ��ȣ
	char s_lvl_3_prc[5];	// �ŵ�3�ܰ�켱ȣ������,��) 999.99
	char s_lvl_3_q[6];	// �ŵ�3�ܰ�켱ȣ���ܷ�
	char s_lvl_4_sign[1];	// �ŵ�4�ܰ��ȣ
	char s_lvl_4_prc[5];	// �ŵ�4�ܰ�켱ȣ������,��) 999.99
	char s_lvl_4_q[6];	// �ŵ�4�ܰ�켱ȣ���ܷ�
	char s_lvl_5_sign[1];	// �ŵ�5�ܰ��ȣ
	char s_lvl_5_prc[5];	// �ŵ�5�ܰ�켱ȣ������,��) 999.99
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
	char real_t_high_prc[5];	// �ǽð����Ѱ�,��) 999.99 ���߰��̵� ����
	char real_t_low_prc_sign[1];	// �ǽð����Ѱ���ȣ
	char real_t_low_prc[5];	// �ǽð����Ѱ�,��) 999.99 ���߰��̵� ����
	char ff[1];	// End of Text, (0xFF)
} K200_FUT_EXEC_LIMIT_ORD;
    

// B6014 : K200����_�켱ȣ��
typedef struct _K200_FUT_LIMIT_ORD {
	char data_clsf[2];	// DATA����,B6
	char info_clsf[2];	// ��������,01:KOSPI200��������
	char mkt_clsf[1];	// ���屸��,4
	char isin_clsf[12];	// �����ڵ�
	char seq[2];	// �����Ϸù�ȣ
	char brd_id[2];	// ����ID,�ڵ尪��������
	char ss_id[2];	// ����ID,�ڵ尪��������
	char total_l_limit_ord_q[6];	// �ż���ȣ���ܷ�
	char l_lvl_1_sign[1];	// �ż�1�ܰ��ȣ
	char l_lvl_1_prc[5];	// �ż�1�ܰ�켱ȣ������,��) 999.99
	char l_lvl_1_q[6];	// �ż�1�ܰ�켱ȣ���ܷ�
	char l_lvl_2_sign[1];	// �ż�2�ܰ��ȣ
	char l_lvl_2_prc[5];	// �ż�2�ܰ�켱ȣ������,��) 999.99
	char l_lvl_2_q[6];	// �ż�2�ܰ�켱ȣ���ܷ�
	char l_lvl_3_sign[1];	// �ż�3�ܰ��ȣ
	char l_lvl_3_prc[5];	// �ż�3�ܰ�켱ȣ������,��) 999.99
	char l_lvl_3_q[6];	// �ż�3�ܰ�켱ȣ���ܷ�
	char l_lvl_4_sign[1];	// �ż�4�ܰ��ȣ
	char l_lvl_4_prc[5];	// �ż�4�ܰ�켱ȣ������,��) 999.99
	char l_lvl_4_q[6];	// �ż�4�ܰ�켱ȣ���ܷ�
	char l_lvl_5_sign[1];	// �ż�5�ܰ��ȣ
	char l_lvl_5_prc[5];	// �ż�5�ܰ�켱ȣ������,��) 999.99
	char l_lvl_5_q[6];	// �ż�5�ܰ�켱ȣ���ܷ�
	char total_s_limit_ord_q[6];	// �ŵ���ȣ���ܷ�
	char s_lvl_1_sign[1];	// �ŵ�1�ܰ��ȣ
	char s_lvl_1_prc[5];	// �ŵ�1�ܰ�켱ȣ������,��) 999.99
	char s_lvl_1_q[6];	// �ŵ�1�ܰ�켱ȣ���ܷ�
	char s_lvl_2_sign[1];	// �ŵ�2�ܰ��ȣ
	char s_lvl_2_prc[5];	// �ŵ�2�ܰ�켱ȣ������,��) 999.99
	char s_lvl_2_q[6];	// �ŵ�2�ܰ�켱ȣ���ܷ�
	char s_lvl_3_sign[1];	// �ŵ�3�ܰ��ȣ
	char s_lvl_3_prc[5];	// �ŵ�3�ܰ�켱ȣ������,��) 999.99
	char s_lvl_3_q[6];	// �ŵ�3�ܰ�켱ȣ���ܷ�
	char s_lvl_4_sign[1];	// �ŵ�4�ܰ��ȣ
	char s_lvl_4_prc[5];	// �ŵ�4�ܰ�켱ȣ������,��) 999.99
	char s_lvl_4_q[6];	// �ŵ�4�ܰ�켱ȣ���ܷ�
	char s_lvl_5_sign[1];	// �ŵ�5�ܰ��ȣ
	char s_lvl_5_prc[5];	// �ŵ�5�ܰ�켱ȣ������,��) 999.99
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
	char exp_prc_sign[1];	// ����ü�ᰡ�ݺ�ȣ,���ϰ��ŸŽø� ����\n (����±����ڵ�:10,20,30,80)
	char exp_prc[5];	// ����ü�ᰡ��,��) 999.99\n ���ϰ��ŸŽø� ����\n (����±����ڵ�:10,20,30,80)
	char ff[1];	// End of Text, (0xFF)
} K200_FUT_LIMIT_ORD;

// A3014 : K200����_ü��
typedef struct _K200_FUT_EXEC {
	char data_clsf        [2 ];	// DATA����,A3
	char info_clsf        [2 ];	// ��������,01:KOSPI200��������
	char mkt_clsf         [1 ];	// ���屸��,4
	char isin_clsf        [12];	// �����ڵ�
	char seq              [2 ];	// �����Ϸù�ȣ
	char brd_id           [2 ];	// ����ID,�ڵ尪��������
	char cur_prc_sign     [1 ];	// ���簡�ݺ�ȣ
	char cur_prc          [5 ];	// ���簡��,��) 999.99
	char exe_q            [6 ];	// ü�����
	char ss_id            [2 ];	// ����ID,�ڵ尪��������
	char exe_t            [8 ];	// ü��ð�
	char rct_prd_prc      [5 ];	// �ֱٿ���������������,��) 999.99
	char nxt_prd_prc      [5 ];	// ������������������,��) 999.99
	char init_prc_sign[1];	// �ð���ȣ
	char init_prc[5];	// �ð�,��) 999.99
	char high_prc_sign[1];	// ����ȣ
	char high_prc[5];	// ��,��) 999.99
	char low_prc_sign[1];	// ������ȣ
	char low_prc[5];	// ����,��) 999.99
	char pri_prc_sign[1];	// �������ݺ�ȣ
	char pri_prc[5];	// ��������,��) 999.99
	char accm_exe_q[7];	// ����ü�����
	char accm_trd_amt[12];	// �����ŷ����,����:õ��
	char accm_block_trd_exe_q[7];	// ���Ǵ뷮����ü�����,������(Filler)
	char l_or_s[1];	// �����ŵ��ż������ڵ�,1:�ŵ�,2:�ż�(�������� ���� ȣ���� �ŵ��ż����а�)
	char real_t_high_prc_sign[1];	// �ǽð����Ѱ���ȣ
	char real_t_high_prc[5];	// �ǽð����Ѱ�,��) 999.99 ���߰��̵� ����
	char real_t_low_prc_sign[1];	// �ǽð����Ѱ���ȣ
	char real_t_low_prc[5];	// �ǽð����Ѱ�,��) 999.99 ���߰��̵� ����
	char ff[1];	// End of Text, (0xFF)
} K200_FUT_EXEC;

#endif
