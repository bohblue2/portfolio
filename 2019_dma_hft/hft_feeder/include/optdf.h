#ifndef _OPTDF_H_
#define _OPTDF_H_

#include "zconf.h"

// C A3034 : K200�ɼ�_ü��
typedef struct _DFK200_OPT_EXEC {
	char    data_clsf              [ 2+1];	// X	2  DATA����, A3
	char    info_clsf              [ 2+1];	// X	2  ��������, 03:KOSPI200�����ɼ�
	char    mrk_clsf               [ 1+1];	// X	1  ���屸��, 4
	char    isin_clsf              [12+1];	// X	12 �����ڵ�
	int     seq                          ;	// 9	4  �����Ϸù�ȣ, �����Ϸù�ȣ �ڸ��� ����(3->4)
	char    brd_id                 [ 2+1];	// X	2  ����ID, �ڵ尪��������
	double  cur_prc                      ;	// 9	5  ���簡��, ��) 999.99
	int     exe_q                        ;	// 9	7  ü�����
	char    ss_id                  [ 2+1];	// X	2  ����ID, �ڵ尪��������
	char    exe_t                  [ 8+1];	// X	8  ü��ð�
	double  init_prc                     ;	// 9	5  �ð�, ��) 999.99
	double  high_prc                     ;	// 9	5  ��, ��) 999.99
	double  low_prc                      ;	// 9	5  ����, ��) 999.99
	double  pri_prc                      ;	// 9	5  ��������, ��) 999.99
	int     accm_exe_q                   ;	// 9	8  ����ü�����
	double  accm_trd_amt                 ;	// 9	11 �����ŷ����, ����:õ��
	int     filter                       ;	// 9	8  ���Ǵ뷮����ü�����, ������(Filler)
	char    l_or_s                 [ 1+1];	// X	1  �����ŵ��ż������ڵ�, 1:�ŵ�,2:�ż�(�������� ���� ȣ���� �ŵ��ż����а�)
	double  real_t_high_prc              ;	// 9	5  �ǽð����Ѱ�, ��) 999.99 ���߰��̵�����
	double  real_t_low_prc               ;	// 9	5  �ǽð����Ѱ�, ��) 999.99 ���߰��̵�����
	char    ff                     [ 1+1];	// X	1  End of Text, 0xFF
} DFK200_OPT_EXEC;
    
// K200�ɼ�_�켱ȣ��
typedef struct _DFK200_OPT_LIMIT_ORD {
	char    data_clsf              [ 2+1];	// X	2  DATA����, B6
	char    info_clsf              [ 2+1];	// X	2  ��������, 03:KOSPI200�����ɼ�
	char    mrk_clsf               [ 1+1];	// X	1  ���屸��, 4
	char    isin_clsf              [12+1];	// X	12 �����ڵ�
	int     seq                          ;	// 9	4  �����Ϸù�ȣ, �����Ϸù�ȣ �ڸ��� ����(3->4)
	char    brd_id                 [ 2+1];	// X	2  ����ID, �ڵ尪��������
	char    ss_id                  [ 2+1];	// X	2  ����ID, �ڵ尪��������
	int     total_l_limit_ord_q          ;	// 9	7  �ż���ȣ���ܷ�
	double  l_lvl_1_prc                  ;	// 9	5  �ż�1�ܰ�켱ȣ������, ��) 999.99
	int     l_lvl_1_q                    ;	// 9	7  �ż�1�ܰ�켱ȣ���ܷ�
	double  l_lvl_2_prc                  ;	// 9	5  �ż�2�ܰ�켱ȣ������, ��) 999.99
	int     l_lvl_2_q                    ;	// 9	7  �ż�2�ܰ�켱ȣ���ܷ�
	double  l_lvl_3_prc                  ;	// 9	5  �ż�3�ܰ�켱ȣ������, ��) 999.99
	int     l_lvl_3_q                    ;	// 9	7  �ż�3�ܰ�켱ȣ���ܷ�
	double  l_lvl_4_prc                  ;	// 9	5  �ż�4�ܰ�켱ȣ������, ��) 999.99
	int     l_lvl_4_q                    ;	// 9	7  �ż�4�ܰ�켱ȣ���ܷ�
	double  l_lvl_5_prc                  ;	// 9	5  �ż�5�ܰ�켱ȣ������, ��) 999.99
	int     l_lvl_5_q                    ;	// 9	7  �ż�5�ܰ�켱ȣ���ܷ�
	int     total_s_limit_ord_q          ;	// 9	7  �ŵ���ȣ���ܷ�
	double  s_lvl_1_prc                  ;	// 9	5  �ŵ�1�ܰ�켱ȣ������, ��) 999.99
	int     s_lvl_1_q                    ;	// 9	7  �ŵ�1�ܰ�켱ȣ���ܷ�
	double  s_lvl_2_prc                  ;	// 9	5  �ŵ�2�ܰ�켱ȣ������, ��) 999.99
	int     s_lvl_2_q                    ;	// 9	7  �ŵ�2�ܰ�켱ȣ���ܷ�
	double  s_lvl_3_prc                  ;	// 9	5  �ŵ�3�ܰ�켱ȣ������, ��) 999.99
	int     s_lvl_3_q                    ;	// 9	7  �ŵ�3�ܰ�켱ȣ���ܷ�
	double  s_lvl_4_prc                  ;	// 9	5  �ŵ�4�ܰ�켱ȣ������, ��) 999.99
	int     s_lvl_4_q                    ;	// 9	7  �ŵ�4�ܰ�켱ȣ���ܷ�
	double  s_lvl_5_prc                  ;	// 9	5  �ŵ�5�ܰ�켱ȣ������, ��) 999.99
	int     s_lvl_5_q                    ;	// 9	7  �ŵ�5�ܰ�켱ȣ���ܷ�
	int     total_l_trd_cnt              ;	// 9	5  �ż���ȿȣ���Ǽ�
	int     l_lvl_1_trd_cnt              ;	// 9	4  �ż�1�ܰ�켱ȣ���Ǽ�
	int     l_lvl_2_trd_cnt              ;	// 9	4  �ż�2�ܰ�켱ȣ���Ǽ�
	int     l_lvl_3_trd_cnt              ;	// 9	4  �ż�3�ܰ�켱ȣ���Ǽ�
	int     l_lvl_4_trd_cnt              ;	// 9	4  �ż�4�ܰ�켱ȣ���Ǽ�
	int     l_lvl_5_trd_cnt              ;	// 9	4  �ż�5�ܰ�켱ȣ���Ǽ�
	int     total_s_trd_cnt              ;	// 9	5  �ŵ���ȿȣ���Ǽ�
	int     s_lvl_1_trd_cnt              ;	// 9	4  �ŵ�1�ܰ�켱ȣ���Ǽ�
	int     s_lvl_2_trd_cnt              ;	// 9	4  �ŵ�2�ܰ�켱ȣ���Ǽ�
	int     s_lvl_3_trd_cnt              ;	// 9	4  �ŵ�3�ܰ�켱ȣ���Ǽ�
	int     s_lvl_4_trd_cnt              ;	// 9	4  �ŵ�4�ܰ�켱ȣ���Ǽ�
	int     s_lvl_5_trd_cnt              ;	// 9	4  �ŵ�5�ܰ�켱ȣ���Ǽ�
	char    ord_rcv_t                [ 8];	// X	8  ȣ�������ð�
	double  exp_prc                      ;	// 9	5  ����ü�ᰡ��, ��) 999.99 ���ϰ��ŸŽø� ����\n (����±����ڵ�:10,20,30,80)
	char    ff                     [ 1+1];	// X	1  End of Text, 0xFF
} DFK200_OPT_LIMIT_ORD;


// K200�ɼ�_ü��_�켱ȣ��
typedef struct _DFK200_OPT_EXEC_LIMIT_ORD {
	char    data_clsf              [ 2+1];	// X	2  DATA����, G7
	char    info_clsf              [ 2+1];	// X	2  ��������, 03:KOSPI200�����ɼ�
	char    mrk_clsf               [ 1+1];	// X	1  ���屸��, 4
	char    isin_clsf              [12+1];	// X	12 �����ڵ�
	int     seq                          ;	// 9	4  �����Ϸù�ȣ, �����Ϸù�ȣ �ڸ��� ����(3->4)
	char    brd_id                 [ 2+1];	// X	2  ����ID, �ڵ尪��������
	double  cur_prc                      ;	// 9	5  ���簡��, ��) 999.99
	int     exe_q                        ;	// 9	7  ü�����
	char    ss_id                  [ 2+1];	// X	2  ����ID, �ڵ尪��������
	char    exe_t                  [ 8+1];	// X	8  ü��ð�
	double  init_prc                     ;	// 9	5  �ð�, ��) 999.99
	double  high_prc                     ;	// 9	5  ��, ��) 999.99
	double  low_prc                      ;	// 9	5  ����, ��) 999.99
	double  pri_prc                      ;	// 9	5  ��������, ��) 999.99
	int     accm_exe_q                   ;	// 9	8  ����ü�����
	double  accm_trd_amt                 ;	// 9	11 �����ŷ����, ����:õ��
	int     accm_block_trd_exe_q         ;	// 9	8  ���Ǵ뷮����ü�����, ������(Filler)
	char    l_or_s                 [ 1+1];	// X	1  �����ŵ��ż������ڵ�, 1:�ŵ�,2:�ż�(�������� ���� ȣ���� �ŵ��ż����а�)
	int     total_l_limit_ord_q          ;	// 9	7  �ż���ȣ���ܷ�
	double  l_lvl_1_prc                  ;	// 9	5  �ż�1�ܰ�켱ȣ������, ��) 999.99
	int     l_lvl_1_q                    ;	// 9	7  �ż�1�ܰ�켱ȣ���ܷ�
	double  l_lvl_2_prc                  ;	// 9	5  �ż�2�ܰ�켱ȣ������, ��) 999.99
	int     l_lvl_2_q                    ;	// 9	7  �ż�2�ܰ�켱ȣ���ܷ�
	double  l_lvl_3_prc                  ;	// 9	5  �ż�3�ܰ�켱ȣ������, ��) 999.99
	int     l_lvl_3_q                    ;	// 9	7  �ż�3�ܰ�켱ȣ���ܷ�
	double  l_lvl_4_prc                  ;	// 9	5  �ż�4�ܰ�켱ȣ������
	int     l_lvl_4_q                    ;	// 9	7  �ż�4�ܰ�켱ȣ���ܷ�
	double  l_lvl_5_prc                  ;	// 9	5  �ż�5�ܰ�켱ȣ������, ��) 999.99
	int     l_lvl_5_q                    ;	// 9	7  �ż�5�ܰ�켱ȣ���ܷ�
	int     total_s_limit_ord_q          ;	// 9	7  �ŵ���ȣ���ܷ�
	double  s_lvl_1_prc                  ;	// 9	5  �ŵ�1�ܰ�켱ȣ������, ��) 999.99
	int     s_lvl_1_q                    ;	// 9	7  �ŵ�1�ܰ�켱ȣ���ܷ�
	double  s_lvl_2_prc                  ;	// 9	5  �ŵ�2�ܰ�켱ȣ������
	int     s_lvl_2_q                    ;	// 9	7  �ŵ�2�ܰ�켱ȣ���ܷ�, ��) 999.99
	double  s_lvl_3_prc                  ;	// 9	5  �ŵ�3�ܰ�켱ȣ������
	int     s_lvl_3_q                    ;	// 9	7  �ŵ�3�ܰ�켱ȣ���ܷ�
	double  s_lvl_4_prc                  ;	// 9	5  �ŵ�4�ܰ�켱ȣ������, ��) 999.99
	int     s_lvl_4_q                    ;	// 9	7  �ŵ�4�ܰ�켱ȣ���ܷ�
	double  s_lvl_5_prc                  ;	// 9	5  �ŵ�5�ܰ�켱ȣ������
	int     s_lvl_5_q                    ;	// 9	7  �ŵ�5�ܰ�켱ȣ���ܷ�, ��) 999.99
	int     total_l_trd_cnt              ;	// 9	5  �ż���ȿȣ���Ǽ�
	int     l_lvl_1_trd_cnt              ;	// 9	4  �ż�1�ܰ�켱ȣ���Ǽ�
	int     l_lvl_2_trd_cnt              ;	// 9	4  �ż�2�ܰ�켱ȣ���Ǽ�
	int     l_lvl_3_trd_cnt              ;	// 9	4  �ż�3�ܰ�켱ȣ���Ǽ�, ��) 999.99
	int     l_lvl_4_trd_cnt              ;	// 9	4  �ż�4�ܰ�켱ȣ���Ǽ�
	int     l_lvl_5_trd_cnt              ;	// 9	4  �ż�5�ܰ�켱ȣ���Ǽ�
	int     total_s_trd_cnt              ;	// 9	5  �ŵ���ȿȣ���Ǽ�, ��) 999.99
	int     s_lvl_1_trd_cnt              ;	// 9	4  �ŵ�1�ܰ�켱ȣ���Ǽ�
	int     s_lvl_2_trd_cnt              ;	// 9	4  �ŵ�2�ܰ�켱ȣ���Ǽ�
	int     s_lvl_3_trd_cnt              ;	// 9	4  �ŵ�3�ܰ�켱ȣ���Ǽ�, ��) 999.99
	int     s_lvl_4_trd_cnt              ;	// 9	4  �ŵ�4�ܰ�켱ȣ���Ǽ�
	int     s_lvl_5_trd_cnt              ;	// 9	4  �ŵ�5�ܰ�켱ȣ���Ǽ�
	double  real_t_high_prc              ;	// 9	5  �ǽð����Ѱ�, ��) 999.99 ���߰��̵�����
	double  real_t_low_prc               ;	// 9	5  �ǽð����Ѱ�, ��) 999.99 ���߰��̵�����
	char    ff                     [ 1+1];	// X	1  End of Text, 0xFF
} DFK200_OPT_EXEC_LIMIT_ORD;
    
#endif
