#ifndef _FUTDF_H_
#define _FUTDF_H_

#include "zconf.h"

//  G7014 : K200����_ü��_�켱ȣ��
typedef struct _DFK200_FUT_EXEC_LIMIT_ORD {
	char    data_clsf           [ 2+1];	//X char    data_clsf       [2];	// DATA����,G7
	char    info_clsf           [ 2+1];	//X char    info_clsf       [2];	// ��������,01:KOSPI200��������
	char    mrk_clsf            [ 1+1];	//X char    mrk_clsf        [1];	// ���屸��,4
	char    isin_clsf           [12+1];	//X char    isin_clsf       [12];	// �����ڵ�
	int     seq                       ;	//9 char    seq             [2];	// �����Ϸù�ȣ
	char    brd_id              [ 2+1];	//X char    brd_id          [2];	// ����ID,�ڵ尪��������
	char    cur_prc_sign        [ 1+1];	//X char    cur_prc_sign    [1];	// ���簡�ݺ�ȣ
	double  cur_price                 ;	//9 char    cur_price       [5];	// ���簡��,��) 999.99
	int     exe_q                     ;	//9 char    exe_q           [6];	// ü�����
	char    ss_id               [ 2+1];	//X char    ss_id           [2];	// ����ID,�ڵ尪��������
	char    exe_t               [ 8+1];	//X char    exe_t           [8];	// ü��ð�
	double  rct_prd_prc               ;	//9 char    rct_prd_prc     [5];	// �ֱٿ���������������,��) 999.99
	double  nxt_prd_prc               ;	//9 char    nxt_prd_prc     [5];	// ������������������,��) 999.99
	char    init_prc_sign       [ 1+1];	//X char    init_prc_sign   [1];	// �ð���ȣ
	double  init_prc                  ;	//9 char    init_prc        [5];	// �ð�,��) 999.99
	char    high_prc_sign       [ 1+1];	//X char    high_prc_sign   [1];	// ����ȣ
	double  high_prc                  ;	//9 char    high_prc        [5];	// ��,��) 999.99
	char    low_prc_sign        [ 1+1];	//X char    low_prc_sign    [1];	// ������ȣ
	double  low_prc                   ;	//9 char    low_prc         [5];	// ����,��) 999.99
	char    pri_prc_sign        [ 1+1];	//X char    pri_prc_sign    [1];	// �������ݺ�ȣ
	double  pri_prc                   ; //9 char    pri_prc         [5];	// ��������,��) 999.99
	int     accm_exe_q                ; //9 char    accm_exe_q      [7];	// ����ü�����
	double  accm_trd_amt              ; //9 char    accm_trd_amt    [12];	// �����ŷ����,����:õ��
	int     accm_block_trd_exe_q      ; //9 char    accm_block_trd_exe_q[7];	// ���Ǵ뷮����ü�����,������(Filler)
	char    l_or_s              [ 1+1];	//X char    l_or_s          [1];	// �����ŵ��ż������ڵ�,1:�ŵ�,2:�ż�(�������� ���� ȣ���� �ŵ��ż����а�)
	int     total_l_limit_ord_q       ;	//9 char    total_l_limit_ord_q[6];	// �ż���ȣ���ܷ�
	char    l_lvl_1_sign        [ 1+1];	//X char    l_lvl_1_sign    [1];	// �ż�1�ܰ��ȣ
	double  l_lvl_1_prc               ;	//9 char    l_lvl_1_prc     [5];	// �ż�1�ܰ�켱ȣ������,��) 999.99
	int     l_lvl_1_q                 ;	//9 char    l_lvl_1_q       [6];	// �ż�1�ܰ�켱ȣ���ܷ�
	char    l_lvl_2_sign        [ 1+1];	//X char    l_lvl_2_sign    [1];	// �ż�2�ܰ��ȣ
	double  l_lvl_2_prc               ;	//9 char    l_lvl_2_prc     [5];	// �ż�2�ܰ�켱ȣ������,��) 999.99
	int     l_lvl_2_q                 ;	//9 char    l_lvl_2_q       [6];	// �ż�2�ܰ�켱ȣ���ܷ�
	char    l_lvl_3_sign        [ 1+1];	//X char    l_lvl_3_sign    [1];	// �ż�3�ܰ��ȣ
	double  l_lvl_3_prc               ;	//9 char    l_lvl_3_prc     [5];	// �ż�3�ܰ�켱ȣ������,��) 999.99
	int     l_lvl_3_q                 ;	//9 char    l_lvl_3_q       [6];	// �ż�3�ܰ�켱ȣ���ܷ�
	char    l_lvl_4_sign        [ 1+1];	//X char    l_lvl_4_sign    [1];	// �ż�4�ܰ��ȣ
	double  l_lvl_4_prc               ;	//9 char    l_lvl_4_prc     [5];	// �ż�4�ܰ�켱ȣ������,��) 999.99
	int     l_lvl_4_q                 ;	//9 char    l_lvl_4_q       [6];	// �ż�4�ܰ�켱ȣ���ܷ�
	char    l_lvl_5_sign        [ 1+1];	//X char    l_lvl_5_sign    [1];	// �ż�5�ܰ��ȣ
	double  l_lvl_5_prc               ;	//9 char    l_lvl_5_prc     [5];	// �ż�5�ܰ�켱ȣ������,��) 999.99
	int     l_lvl_5_q                 ;	//9 char    l_lvl_5_q       [6];	// �ż�5�ܰ�켱ȣ���ܷ�
	int     total_s_limit_ord_q       ;	//9 char    total_s_limit_ord_q[6];	// �ŵ���ȣ���ܷ�
	char    s_lvl_1_sign        [ 1+1];	//X char    s_lvl_1_sign    [1];	// �ŵ�1�ܰ��ȣ
	double  s_lvl_1_prc               ;	//9 char    s_lvl_1_prc     [5];	// �ŵ�1�ܰ�켱ȣ������,��) 999.99
	int     s_lvl_1_q                 ;	//9 char    s_lvl_1_q       [6];	// �ŵ�1�ܰ�켱ȣ���ܷ�
	char    s_lvl_2_sign        [ 1+1];	//X char    s_lvl_2_sign    [1];	// �ŵ�2�ܰ��ȣ
	double  s_lvl_2_prc               ;	//9 char    s_lvl_2_prc     [5];	// �ŵ�2�ܰ�켱ȣ������,��) 999.99
	int     s_lvl_2_q                 ;	//9 char    s_lvl_2_q       [6];	// �ŵ�2�ܰ�켱ȣ���ܷ�
	char    s_lvl_3_sign        [ 1+1];	//X char    s_lvl_3_sign    [1];	// �ŵ�3�ܰ��ȣ
	double  s_lvl_3_prc               ;	//9 char    s_lvl_3_prc     [5];	// �ŵ�3�ܰ�켱ȣ������,��) 999.99
	int     s_lvl_3_q                 ;	//9 char    s_lvl_3_q       [6];	// �ŵ�3�ܰ�켱ȣ���ܷ�
	char    s_lvl_4_sign        [ 1+1];	//X char    s_lvl_4_sign    [1];	// �ŵ�4�ܰ��ȣ
	double  s_lvl_4_prc               ;	//9 char    s_lvl_4_prc     [5];	// �ŵ�4�ܰ�켱ȣ������,��) 999.99
	int     s_lvl_4_q                 ;	//9 char    s_lvl_4_q       [6];	// �ŵ�4�ܰ�켱ȣ���ܷ�
	char    s_lvl_5_sign        [ 1+1];	//X char    s_lvl_5_sign    [1];	// �ŵ�5�ܰ��ȣ
	double  s_lvl_5_prc               ;	//9 char    s_lvl_5_prc     [5];	// �ŵ�5�ܰ�켱ȣ������,��) 999.99
	int     s_lvl_5_q                 ;	//9 char    s_lvl_5_q       [6];	// �ŵ�5�ܰ�켱ȣ���ܷ�
	int     total_l_trd_cnt           ;	//9 char    total_l_trd_cnt [5];	// �ż���ȿȣ���Ǽ�
	int     l_lvl_1_trd_cnt           ;	//9 char    l_lvl_1_trd_cnt [4];	// �ż�1�ܰ�켱ȣ���Ǽ�
	int     l_lvl_2_trd_cnt           ;	//9 char    l_lvl_2_trd_cnt [4];	// �ż�2�ܰ�켱ȣ���Ǽ�
	int     l_lvl_3_trd_cnt           ;	//9 char    l_lvl_3_trd_cnt [4];	// �ż�3�ܰ�켱ȣ���Ǽ�
	int     l_lvl_4_trd_cnt           ;	//9 char    l_lvl_4_trd_cnt [4];	// �ż�4�ܰ�켱ȣ���Ǽ�
	int     l_lvl_5_trd_cnt           ;	//9 char    l_lvl_5_trd_cnt [4];	// �ż�5�ܰ�켱ȣ���Ǽ�
	int     total_s_trd_cnt           ;	//9 char    total_s_trd_cnt [5];	// �ŵ���ȿȣ���Ǽ�
	int     s_lvl_1_trd_cnt           ;	//9 char    s_lvl_1_trd_cnt [4];	// �ŵ�1�ܰ�켱ȣ���Ǽ�
	int     s_lvl_2_trd_cnt           ;	//9 char    s_lvl_2_trd_cnt [4];	// �ŵ�2�ܰ�켱ȣ���Ǽ�
	int     s_lvl_3_trd_cnt           ;	//9 char    s_lvl_3_trd_cnt [4];	// �ŵ�3�ܰ�켱ȣ���Ǽ�
	int     s_lvl_4_trd_cnt           ;	//9 char    s_lvl_4_trd_cnt [4];	// �ŵ�4�ܰ�켱ȣ���Ǽ�
	int     s_lvl_5_trd_cnt           ;	//9 char    s_lvl_5_trd_cnt [4];	// �ŵ�5�ܰ�켱ȣ���Ǽ�
	char    real_t_high_prc_sign[ 1+1];//X char    real_t_high_prc_sign[1];	// �ǽð����Ѱ���ȣ
	double  real_t_high_prc           ;	//9 char    real_t_high_prc [5];	// �ǽð����Ѱ�,��) 999.99 ���߰��̵� ����
	char    real_t_low_prc_sign [ 1+1];	//X char    real_t_low_prc_sign[1];	// �ǽð����Ѱ���ȣ
	double  real_t_low_prc            ;	//9 char    real_t_low_prc  [5];	// �ǽð����Ѱ�,��) 999.99 ���߰��̵� ����
	char    ff                  [ 1+1];	//X char    ff              [1];	// End of Text, (0xFF)
} DFK200_FUT_EXEC_LIMIT_ORD;
    
#endif
