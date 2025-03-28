#ifndef _OPTPK_H_
#define _OPTPK_H_

#include "zconf.h"

typedef struct _proc_list
{
    char    id[6];
    int     (*AppProc)(char *buff);
    char    tname[30];
} PROC_LIST;

/* hader file �ߺ� ���� �ذ� */
#ifdef ZAPLST

int OptProcA3034(char *buff);
int OptProcB6034(char *buff);
int OptProcG7034(char *buff);

PROC_LIST AppList[] = {
{"A3034",     OptProcA3034, "K200_OPT_EXEC"             },
{"B6034",     OptProcB6034, "K200_OPT_LIMIT_ORD"        },
{"G7034",     OptProcG7034, "K200_OPT_EXEC_LIMIT_ORD"   },
};

#define AP_CNT	( sizeof(AppList)/sizeof(PROC_LIST))

#endif                    

// C A3034 : K200�ɼ�_ü��
// I A3034 : K200�ɼ�_ü��
// I B6034 : K200�ɼ�_�켱ȣ��
// I G7034 : K200�ɼ�_ü��_�켱

// C A3034 : K200�ɼ�_ü��
typedef struct _K200_OPT_EXEC {
	char    data_clsf           [ 2];	// X	2  DATA����, A3
	char    info_clsf           [ 2];	// X	2  ��������, 03:KOSPI200�����ɼ�
	char    mrk_clsf            [ 1];	// X	1  ���屸��, 4
	char    isin_clsf           [12];	// X	12 �����ڵ�
	char    seq                 [ 4];	// 9	4  �����Ϸù�ȣ, �����Ϸù�ȣ �ڸ��� ����(3->4)
	char    brd_id              [ 2];	// X	2  ����ID, �ڵ尪��������
	char    cur_prc             [ 5];	// 9	5  ���簡��, ��) 999.99
	char    exe_q               [ 7];	// 9	7  ü�����
	char    ss_id               [ 2];	// X	2  ����ID, �ڵ尪��������
	char    exe_t               [ 8];	// X	8  ü��ð�
	char    init_prc            [ 5];	// 9	5  �ð�, ��) 999.99
	char    high_prc            [ 5];	// 9	5  ��, ��) 999.99
	char    low_prc             [ 5];	// 9	5  ����, ��) 999.99
	char    pri_prc             [ 5];	// 9	5  ��������, ��) 999.99
	char    accm_exe_q          [ 8];	// 9	8  ����ü�����
	char    accm_trd_amt        [11];	// 9	11 �����ŷ����, ����:õ��
	char    filter              [ 8];	// 9	8  ���Ǵ뷮����ü�����, ������(Filler)
	char    l_or_s              [ 1];	// X	1  �����ŵ��ż������ڵ�, 1:�ŵ�,2:�ż�(�������� ���� ȣ���� �ŵ��ż����а�)
	char    real_t_high_prc     [ 5];	// 9	5  �ǽð����Ѱ�, ��) 999.99 ���߰��̵�����
	char    real_t_low_prc      [ 5];	// 9	5  �ǽð����Ѱ�, ��) 999.99 ���߰��̵�����
	char    ff                  [ 1];	// X	1  End of Text, 0xFF
} K200_OPT_EXEC;
    
// K200�ɼ�_�켱ȣ��
typedef struct _K200_OPT_LIMIT_ORD {
	char data_clsf              [ 2];	// X	2  DATA����, B6
	char info_clsf              [ 2];	// X	2  ��������, 03:KOSPI200�����ɼ�
	char mrk_clsf               [ 1];	// X	1  ���屸��, 4
	char isin_clsf              [12];	// X	12 �����ڵ�
	char seq                    [ 4];	// 9	4  �����Ϸù�ȣ, �����Ϸù�ȣ �ڸ��� ����(3->4)
	char brd_id                 [ 2];	// X	2  ����ID, �ڵ尪��������
	char ss_id                  [ 2];	// X	2  ����ID, �ڵ尪��������
	char total_l_limit_ord_q    [ 7];	// 9	7  �ż���ȣ���ܷ�
	char l_lvl_1_prc            [ 5];	// 9	5  �ż�1�ܰ�켱ȣ������, ��) 999.99
	char l_lvl_1_q              [ 7];	// 9	7  �ż�1�ܰ�켱ȣ���ܷ�
	char l_lvl_2_prc            [ 5];	// 9	5  �ż�2�ܰ�켱ȣ������, ��) 999.99
	char l_lvl_2_q              [ 7];	// 9	7  �ż�2�ܰ�켱ȣ���ܷ�
	char l_lvl_3_prc            [ 5];	// 9	5  �ż�3�ܰ�켱ȣ������, ��) 999.99
	char l_lvl_3_q              [ 7];	// 9	7  �ż�3�ܰ�켱ȣ���ܷ�
	char l_lvl_4_prc            [ 5];	// 9	5  �ż�4�ܰ�켱ȣ������, ��) 999.99
	char l_lvl_4_q              [ 7];	// 9	7  �ż�4�ܰ�켱ȣ���ܷ�
	char l_lvl_5_prc            [ 5];	// 9	5  �ż�5�ܰ�켱ȣ������, ��) 999.99
	char l_lvl_5_q              [ 7];	// 9	7  �ż�5�ܰ�켱ȣ���ܷ�
	char total_s_limit_ord_q    [ 7];	// 9	7  �ŵ���ȣ���ܷ�
	char s_lvl_1_prc            [ 5];	// 9	5  �ŵ�1�ܰ�켱ȣ������, ��) 999.99
	char s_lvl_1_q              [ 7];	// 9	7  �ŵ�1�ܰ�켱ȣ���ܷ�
	char s_lvl_2_prc            [ 5];	// 9	5  �ŵ�2�ܰ�켱ȣ������, ��) 999.99
	char s_lvl_2_q              [ 7];	// 9	7  �ŵ�2�ܰ�켱ȣ���ܷ�
	char s_lvl_3_prc            [ 5];	// 9	5  �ŵ�3�ܰ�켱ȣ������, ��) 999.99
	char s_lvl_3_q              [ 7];	// 9	7  �ŵ�3�ܰ�켱ȣ���ܷ�
	char s_lvl_4_prc            [ 5];	// 9	5  �ŵ�4�ܰ�켱ȣ������, ��) 999.99
	char s_lvl_4_q              [ 7];	// 9	7  �ŵ�4�ܰ�켱ȣ���ܷ�
	char s_lvl_5_prc            [ 5];	// 9	5  �ŵ�5�ܰ�켱ȣ������, ��) 999.99
	char s_lvl_5_q              [ 7];	// 9	7  �ŵ�5�ܰ�켱ȣ���ܷ�
	char total_l_trd_cnt        [ 5];	// 9	5  �ż���ȿȣ���Ǽ�
	char l_lvl_1_trd_cnt        [ 4];	// 9	4  �ż�1�ܰ�켱ȣ���Ǽ�
	char l_lvl_2_trd_cnt        [ 4];	// 9	4  �ż�2�ܰ�켱ȣ���Ǽ�
	char l_lvl_3_trd_cnt        [ 4];	// 9	4  �ż�3�ܰ�켱ȣ���Ǽ�
	char l_lvl_4_trd_cnt        [ 4];	// 9	4  �ż�4�ܰ�켱ȣ���Ǽ�
	char l_lvl_5_trd_cnt        [ 4];	// 9	4  �ż�5�ܰ�켱ȣ���Ǽ�
	char total_s_trd_cnt        [ 5];	// 9	5  �ŵ���ȿȣ���Ǽ�
	char s_lvl_1_trd_cnt        [ 4];	// 9	4  �ŵ�1�ܰ�켱ȣ���Ǽ�
	char s_lvl_2_trd_cnt        [ 4];	// 9	4  �ŵ�2�ܰ�켱ȣ���Ǽ�
	char s_lvl_3_trd_cnt        [ 4];	// 9	4  �ŵ�3�ܰ�켱ȣ���Ǽ�
	char s_lvl_4_trd_cnt        [ 4];	// 9	4  �ŵ�4�ܰ�켱ȣ���Ǽ�
	char s_lvl_5_trd_cnt        [ 4];	// 9	4  �ŵ�5�ܰ�켱ȣ���Ǽ�
	char ord_rcv_t              [ 8];	// X	8  ȣ�������ð�
	char exp_prc                [ 5];	// 9	5  ����ü�ᰡ��, ��) 999.99 ���ϰ��ŸŽø� ����\n (����±����ڵ�:10,20,30,80)
	char ff                     [ 1];	// X	1  End of Text, 0xFF
} K200_OPT_LIMIT_ORD;


// K200�ɼ�_ü��_�켱ȣ��
typedef struct _K200_OPT_EXEC_LIMIT_ORD {
	char data_clsf              [ 2];	// X	2  DATA����, G7
	char info_clsf              [ 2];	// X	2  ��������, 03:KOSPI200�����ɼ�
	char mrk_clsf               [ 1];	// X	1  ���屸��, 4
	char isin_clsf              [12];	// X	12 �����ڵ�
	char seq                    [ 4];	// 9	4  �����Ϸù�ȣ, �����Ϸù�ȣ �ڸ��� ����(3->4)
	char brd_id                 [ 2];	// X	2  ����ID, �ڵ尪��������
	char cur_prc                [ 5];	// 9	5  ���簡��, ��) 999.99
	char exe_q                  [ 7];	// 9	7  ü�����
	char ss_id                  [ 2];	// X	2  ����ID, �ڵ尪��������
	char exe_t                  [ 8];	// X	8  ü��ð�
	char init_prc               [ 5];	// 9	5  �ð�, ��) 999.99
	char high_prc               [ 5];	// 9	5  ��, ��) 999.99
	char low_prc                [ 5];	// 9	5  ����, ��) 999.99
	char pri_prc                [ 5];	// 9	5  ��������, ��) 999.99
	char accm_exe_q             [ 8];	// 9	8  ����ü�����
	char accm_trd_amt           [11];	// 9	11 �����ŷ����, ����:õ��
	char accm_block_trd_exe_q   [ 8];	// 9	8  ���Ǵ뷮����ü�����, ������(Filler)
	char l_or_s                 [ 1];	// X	1  �����ŵ��ż������ڵ�, 1:�ŵ�,2:�ż�(�������� ���� ȣ���� �ŵ��ż����а�)
	char total_l_limit_ord_q    [ 7];	// 9	7  �ż���ȣ���ܷ�
	char l_lvl_1_prc            [ 5];	// 9	5  �ż�1�ܰ�켱ȣ������, ��) 999.99
	char l_lvl_1_q              [ 7];	// 9	7  �ż�1�ܰ�켱ȣ���ܷ�
	char l_lvl_2_prc            [ 5];	// 9	5  �ż�2�ܰ�켱ȣ������, ��) 999.99
	char l_lvl_2_q              [ 7];	// 9	7  �ż�2�ܰ�켱ȣ���ܷ�
	char l_lvl_3_prc            [ 5];	// 9	5  �ż�3�ܰ�켱ȣ������, ��) 999.99
	char l_lvl_3_q              [ 7];	// 9	7  �ż�3�ܰ�켱ȣ���ܷ�
	char l_lvl_4_prc            [ 5];	// 9	5  �ż�4�ܰ�켱ȣ������
	char l_lvl_4_q              [ 7];	// 9	7  �ż�4�ܰ�켱ȣ���ܷ�
	char l_lvl_5_prc            [ 5];	// 9	5  �ż�5�ܰ�켱ȣ������, ��) 999.99
	char l_lvl_5_q              [ 7];	// 9	7  �ż�5�ܰ�켱ȣ���ܷ�
	char total_s_limit_ord_q    [ 7];	// 9	7  �ŵ���ȣ���ܷ�
	char s_lvl_1_prc            [ 5];	// 9	5  �ŵ�1�ܰ�켱ȣ������, ��) 999.99
	char s_lvl_1_q              [ 7];	// 9	7  �ŵ�1�ܰ�켱ȣ���ܷ�
	char s_lvl_2_prc            [ 5];	// 9	5  �ŵ�2�ܰ�켱ȣ������
	char s_lvl_2_q              [ 7];	// 9	7  �ŵ�2�ܰ�켱ȣ���ܷ�, ��) 999.99
	char s_lvl_3_prc            [ 5];	// 9	5  �ŵ�3�ܰ�켱ȣ������
	char s_lvl_3_q              [ 7];	// 9	7  �ŵ�3�ܰ�켱ȣ���ܷ�
	char s_lvl_4_prc            [ 5];	// 9	5  �ŵ�4�ܰ�켱ȣ������, ��) 999.99
	char s_lvl_4_q              [ 7];	// 9	7  �ŵ�4�ܰ�켱ȣ���ܷ�
	char s_lvl_5_prc            [ 5];	// 9	5  �ŵ�5�ܰ�켱ȣ������
	char s_lvl_5_q              [ 7];	// 9	7  �ŵ�5�ܰ�켱ȣ���ܷ�, ��) 999.99
	char total_l_trd_cnt        [ 5];	// 9	5  �ż���ȿȣ���Ǽ�
	char l_lvl_1_trd_cnt        [ 4];	// 9	4  �ż�1�ܰ�켱ȣ���Ǽ�
	char l_lvl_2_trd_cnt        [ 4];	// 9	4  �ż�2�ܰ�켱ȣ���Ǽ�
	char l_lvl_3_trd_cnt        [ 4];	// 9	4  �ż�3�ܰ�켱ȣ���Ǽ�, ��) 999.99
	char l_lvl_4_trd_cnt        [ 4];	// 9	4  �ż�4�ܰ�켱ȣ���Ǽ�
	char l_lvl_5_trd_cnt        [ 4];	// 9	4  �ż�5�ܰ�켱ȣ���Ǽ�
	char total_s_trd_cnt        [ 5];	// 9	5  �ŵ���ȿȣ���Ǽ�, ��) 999.99
	char s_lvl_1_trd_cnt        [ 4];	// 9	4  �ŵ�1�ܰ�켱ȣ���Ǽ�
	char s_lvl_2_trd_cnt        [ 4];	// 9	4  �ŵ�2�ܰ�켱ȣ���Ǽ�
	char s_lvl_3_trd_cnt        [ 4];	// 9	4  �ŵ�3�ܰ�켱ȣ���Ǽ�, ��) 999.99
	char s_lvl_4_trd_cnt        [ 4];	// 9	4  �ŵ�4�ܰ�켱ȣ���Ǽ�
	char s_lvl_5_trd_cnt        [ 4];	// 9	4  �ŵ�5�ܰ�켱ȣ���Ǽ�
	char real_t_high_prc        [ 5];	// 9	5  �ǽð����Ѱ�, ��) 999.99 ���߰��̵�����
	char real_t_low_prc         [ 5];	// 9	5  �ǽð����Ѱ�, ��) 999.99 ���߰��̵�����
	char ff                     [ 1];	// X	1  End of Text, 0xFF
} K200_OPT_EXEC_LIMIT_ORD;

#endif
