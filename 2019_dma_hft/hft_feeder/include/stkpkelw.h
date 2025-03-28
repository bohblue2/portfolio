#ifndef _STKPKELW_H_
#define _STKPKELW_H_

#include "zconf.h"

#define TICK_CNT    10

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

//  B7021 : ELW_ȣ���ܷ�_LPȣ��_����
typedef struct _ELW_ASK_RSD_WLP {
	char    data_clsf   [2];	    // DATA����, B7
	char    info_clsf   [2];	    // ��������, 01:������������ 02:ELW
	char    mkt_clsf    [1];	    // ���屸��, 1:��������
	char    isin_code   [12];	    // �����ڵ�, ǥ���ڵ�
	char    stk_snr     [5];	    // �����Ϸù�ȣ, �����ġ(A0)�� �����Ϸù�ȣ
	char    cum_ccls_qty[12];	    // ����ü�����
	PK_TICKLP ticklp    [10];       // ȣ�� OCCURS 1010�� 66 = 660
	char    ask_tot_rsd_10[12];	    // 10�ܰ�ȣ���ŵ����ܷ�
	char    bid_tot_rsd_10[12];	    // 10�ܰ�ȣ���ż����ܷ�
	char    filler1[12];	        // FILLER
	char    filler2[12];	        // FILLER
	char    ofhr_ask_tot_rsd[12];	// �������Ľð��� �ŵ���ȣ���ܷ�, ����ID�� ""G3""�� ��� ������ \n ��ELW�� �ð��ܰŷ� ����
	char    ofhr_bid_tot_rsd[12];	// �������Ľð��� �ż���ȣ���ܷ�, ����ID�� ""G3""�� ��� ������\n ��ELW�� �ð��ܰŷ� ����
	char    sess_id[2];	            // ����ID, �� �ڵ尪���� ����
	char    brd_id[2];	            // ����ID, �� �ڵ尪���� ����
	char    exp_ccls_prc[9];	    // ����ü�ᰡ��
	char    exp_ccls_qty[12];	    // ����ü�����
	char    cmpt_msv_dir_clsf[1];	// ����뷮 ���ⱸ��, 0:�ش����, 1:�ŵ�, 2:�ż�
	char    filler3[7];	            // FILLER, SPACE
	char    ff[1];	                // FF, END OF TEXT (0xFF)
} ELW_ASK_RSD_WLP;

//  A3021 : ELW_ü��
typedef struct _ELW_CCLS {
	char    data_clsf[2];	            // DATA����, A3
	char    info_clsf[2];	            // ��������, 01:�ֽ� 02:ELW
	char    mkt_clsf[1];	            // ���屸��, 1:�������� 2:�ڽ���
	char    isin_code[12];	            // �����ڵ�, ǥ���ڵ�
	char    stk_snr[5];	                // �����Ϸù�ȣ, �����ġ(A0)�� �����Ϸù�ȣ
	char    brd_id[2];	                // ����ID, �� �ڵ尪���� ����
	char    ctrs_clsf[1];	            // "���ϴ��(���ذ����) ����", 0:�ǴܺҰ� 1:���� 2:��� 3:���� 4:���� 5:�϶�\n �� ���Խð��ܱ����ڵ� ���� 4�� ��� ���� ���� ���\n �� ���Խð��ܱ����ڵ� ���� 7,8�� ��� Buy-in���ذ� ���
	char    prev_ctrs[9];	            // ���ϴ��, ����:�� �����μ��� ����/������ �ű� ���� ���� : 0
	char    ccls_prc[9];	            // ü�ᰡ��, ����:��
	char    ccls_qty[10];	            // ü�����, ����:��
	char    sess_id[2];	                // ����ID, �� �ڵ尪���� ����
	char    open[9];	                // �ð�, ����:�� �ذ��߰��̵� ����
	char    hi[9];	                    // ��, ����:�� �ذ��߰��̵� ����
	char    low[9];	                    // ����, ����:�� �ذ��߰��̵� ����
	char    cum_ccls_qty[12];	        // ����ü�����, ����:�� �غ���ID���� ������
	char    cum_trd_val[18];	        // �����ŷ����, ����:�� �غ���ID���� ������
	char    fin_bid_ask_clsf_code[1];	// �����ŵ��ż������ڵ�, 1:�ŵ� 2:�ż�
	char    mtc_flg[1];	                // ü�ᰡ��1ȣ����ġ����, 0:�ǴܺҰ� 1:��ġ 2:����ġ
	char    ccls_time[6];	            // ü��ð�, HHMMSS
	char    lp_hld_qty[15];	            // LP��������, LP(ü�����) ������ LP��������
	char    ask_1_prc[9];	            // �ŵ�1ȣ��, ����:�� �ذ��߰��̵� ����
	char    bid_1_prc[9];	            // �ż�1ȣ��, ����:�� �ذ��߰��̵� ����
	char    filler[6];	                // FILLER, SPACE
	char    ff[1];	                    // FF, END OF TEXT (0xFF)
} ELW_CCLS;

#endif
