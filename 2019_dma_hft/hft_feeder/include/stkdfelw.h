#ifndef _STKDFELW_H_
#define _STKDFELW_H_

#include "zconf.h"

#define TICK_CNT    10

typedef struct _DF_TICK {
    int     ask_prc             ;   //char ask_prc          [9 ];	// �ŵ�ȣ��1
	int     bid_prc             ;   //char bid_prc          [9 ];	// �ż�ȣ��1
	double  ask_vol_rsd         ;   //char ask_vol_rsd      [12];	// �ŵ�ȣ�� �ܷ�1
	double  bid_vol_rsd         ;   //char bid_vol_rsd      [12];	// �ż�ȣ�� �ܷ�1    
} DF_TICK; 

typedef struct _DF_TICKLP {
    int     ask_prc             ;   //char ask_prc          [9 ];	// �ŵ�ȣ��1
	int     bid_prc             ;   //char bid_prc          [9 ];	// �ż�ȣ��1
	double  ask_vol_rsd         ;   //char ask_vol_rsd      [12];	// �ŵ�ȣ�� �ܷ�1
	double  bid_vol_rsd         ;   //char bid_vol_rsd      [12];	// �ż�ȣ�� �ܷ�1  
	double  lp_ask_vol_rsd      ;   //char lp_ask_vol_rsd   [12];	// LP �ŵ�ȣ�� �ܷ�1
	double  lp_bid_vol_rsd      ;   //char lp_bid_vol_rsd   [12];	// LP �ż�ȣ�� �ܷ�1  
} DF_TICKLP; 

typedef struct _DFELW_ASK_RSD_WLP {
	char    data_clsf            [2+1];	// X	2   DATA����, B7
	char    info_clsf            [2+1];	// X	2   ��������, 01:������������ 02:ELW
	char    mkt_clsf             [1+1];	// X	1   ���屸��, 1:��������
	char    isin_code           [12+1];	// X	12  �����ڵ�, ǥ���ڵ�
	int     stk_snr                   ;  	// 9	5   �����Ϸù�ȣ, �����ġ(A0)�� �����Ϸù�ȣ
	double  cum_ccls_qty              ;	// 9	12  ����ü�����
	DF_TICKLP ticklp              [10];   //           ȣ�� OCCURS 1010�� 66 = 660
	double  ask_tot_rsd_10            ;	// 9	12  10�ܰ�ȣ���ŵ����ܷ�
	double  bid_tot_rsd_10            ;	// 9	12  10�ܰ�ȣ���ż����ܷ�
	char    filler1             [12+1];	// 9	12  FILLER
	char    filler2             [12+1];	// 9	12  FILLER
	double  ofhr_ask_tot_rsd          ;	// 9	12  �������Ľð��� �ŵ���ȣ���ܷ�, ����ID�� ""G3""�� ��� ������ \n ��ELW�� �ð��ܰŷ� ����
	double  ofhr_bid_tot_rsd          ;	// 9	12  �������Ľð��� �ż���ȣ���ܷ�, ����ID�� ""G3""�� ��� ������\n ��ELW�� �ð��ܰŷ� ����
	char    sess_id              [2+1];	// X	2   ����ID, �� �ڵ尪���� ����
	char    brd_id               [2+1];	// X	2   ����ID, �� �ڵ尪���� ����
	int     exp_ccls_prc              ; 	// 9	9   ����ü�ᰡ��
	double  exp_ccls_qty              ;	// 9	12  ����ü�����
	int     cmpt_msv_dir_clsf         ;	// 9	1   ����뷮 ���ⱸ��, 0:�ش����, 1:�ŵ�, 2:�ż�
	char    filler3              [7+1];	// X	7   FILLER, SPACE
	char    ff                   [1+1];	// X	1   FF, END OF TEXT (0xFF)
} DFELW_ASK_RSD_WLP;

// �ڽ���_ü�� A3011 int 9 double 10 ~
typedef struct _DFELW_CCLS {
	char    data_clsf       [ 2+1];    	    //char data_clsf[2];	        // DATA����, A3
	char    info_clsf       [ 2+1];	        //char info_clsf[2];	        // ��������, 01:�ֽ� 02:ELW
	char    mkt_clsf        [ 1+1];	        //char mkt_clsf[1];	            // ���屸��, 1:�������� 2:�ڽ���
	char    isin_code       [12+1];	        //char isin_code[12];	        // �����ڵ�, ǥ���ڵ�
	int     stk_snr             ;	        //char stk_snr[5];	            // �����Ϸù�ȣ, �����ġ(A0)�� �����Ϸù�ȣ
	char    brd_id          [ 2+1];	        //char brd_id[2];	            // ����ID, �� �ڵ尪���� ����
	char    ctrs_clsf       [ 1+1];	        //char ctrs_clsf[1];	        // "���ϴ��(���ذ����) ����", 0:�ǴܺҰ� 1:���� 2:��� 3:���� 4:���� 5:�϶�\n �� ���Խð��ܱ����ڵ� ���� 4�� ��� ���� ���� ���\n �� ���Խð��ܱ��а��̺�
	int     prev_ctrs           ;	        //char prev_ctrs[9];	        // ���ϴ��, ����:�� �����μ��� ����/������ �ű� ���� ���� : 0
	int     ccls_prc            ;	        //char ccls_prc[9];	            // ü�ᰡ��, ����:��
	double  ccls_qty            ;	        //char ccls_qty[10];	        // ü�����, ����:��
	char    sess_id         [ 2+1];	        //char sess_id[2];	            // ����ID, �� �ڵ尪���� ����
	int     open                ;	        //char open[9];	                // �ð�, ����:�� �ذ��߰��̵� ����
	int     hi                  ;	        //char hi[9];	                // ��, ����:�� �ذ��߰��̵� ����
	int     low                 ;	        //char low[9];	                // ����, ����:�� �ذ��߰��̵� ����
	double  cum_ccls_qty        ;	        //char cum_ccls_qty[12];	    // ����ü�����, ����:�� �غ���ID���� ������
	double  cum_trd_val         ;	        //char cum_trd_val[18];	        // �����ŷ����, ����:�� �غ���ID���� ������
	char    fin_bid_ask_clsf_code[ 1+1];       //char fin_bid_ask_clsf_code[1];// �����ŵ��ż������ڵ�, 1:�ŵ� 2:�ż�
	char    mtc_flg         [ 1+1];	        //char mtc_flg[1];	            // ü�ᰡ��1ȣ����ġ����, 0:�ǴܺҰ� 1:��ġ 2:����ġ
	char    ccls_time       [ 6+1];	        //char ccls_time[6];	        // ü��ð�, HHMMSS
	double  lp_hld_qty          ;	        //char lp_hld_qty[15];	        // LP��������, LP(ü�����) ������ LP��������\n�����߻� ����(ETN�� �ش�)(2018.09.17)
	int     ask_1_prc           ;	        //char ask_1_prc[9];	        // �ŵ�1ȣ��, ����:�� �ذ��߰��̵� ����
	int     bid_1_prc           ;	        //char bid_1_prc[9];	        // �ż�1ȣ��, ����:�� �ذ��߰��̵� ����
	char    filler[6];	                    //char filler[6];	            // FILLER, SPACE
	char    ff[1];	                        //char ff[1];	                // FF, END OF TEXT (0xFF)
} DFELW_CCLS;

#endif
