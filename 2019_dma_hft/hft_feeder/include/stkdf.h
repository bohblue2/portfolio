#ifndef _STKDF_H_
#define _STKDF_H_

#include "zconf.h"

#define TICK_CNT    10

//B6011 : �ڽ���_ȣ���ܷ�_LPȣ��_���� KOSPI_ASK_RSD_WOLP
//B7011 : �ڽ���_ȣ���ܷ�_LPȣ��_���� KOSPI_ASK_RSD_WLP
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

// A6021 : ELW_���񸶰�
typedef struct _DFELW_STK_CLSG {
	char    data_clsf             [2+1];	// X	2   DATA����, A6
	char    info_clsf             [2+1];	// X	2   ��������, 01:�ֽ� 02:ELW
	char    mkt_clsf              [1+1];	// X	1   ���屸��, 1:�������� 2:�ڽ���
	char    isin_code            [12+1];	// X	12  �����ڵ�, ǥ���ڵ�
	int     snr                        ;	// 9	5   �����Ϸù�ȣ, �����ġ(A0)�� �����Ϸù�ȣ
	char    brd_id                [2+1];	// X	2   ����ID, �� �ڵ尪���� ����
	int     stk_cls_prc                ;	// 9	9   ���񸶰�����, ���Խð��ܱ����ڵ尡 \n 1:�������϶��� ���񸶰����ݱ����ڵ尪�� SET ��. \n �׿ܿ��� SPACE
	char    stk_cls_prc_clsf_code [1+1];	// X	1   ���񸶰����ݱ����ڵ�, 1:ü�ᰡ \n 2:�⼼ \n 3:�ŷ��� \n 4:�ð����ذ������� �⼼\n :�������� �ƴ� ��� SPACE
	int     ofhr_hi                    ;	// 9	9   "���񸶰��ð��ܴ��ϰ� ���Ѱ�"
	int     ofhr_lo                    ;	// 9	9   "���񸶰��ð��ܴ��ϰ� ���Ѱ�"
	int     stk_cls_mwprc              ;	// 9	9   ���񸶰���հ����ְ�
	int     dlv_base_prc               ;	// 9	9   �����ε����ذ���
	int     dlv_hi                     ;	// 9	9   �����ε����Ѱ�
	int     dlv_lo                     ;	// 9	9   �����ε����Ѱ�
	char    filler                [1+1];	// X	1   FILLER, SPACE
	char    ff                    [1+1];	// X	1   FF, END OF TEXT (0xFF)
} DFELW_STK_CLSG;

// B1021 : ELW_�ü�����
typedef struct _DFELW_MKT_PRC_CLS {
	char    data_clsf            [2+1];	// X	2  DATA����, B1:���� B2:�ü�REC
	char    info_clsf            [2+1];	// X	2  ��������, 01:�ֽ� 02:ELW
	char    mkt_clsf             [1+1];	// X	1  ���屸��, 1:�������� 2:�ڽ���
	char    isin_code           [12+1];	// X	12 �����ڵ�, ǥ���ڵ�
	int     stk_snr                   ;	// 9	5  �����Ϸù�ȣ, �����ġ(A0)�� �����Ϸù�ȣ
	char    flct_clsf            [1+1];	// X	1  �������, 0:�ǴܺҰ� 1:���� 2:��� 3:���� 4:���� 5:�϶�
	int     prev_ctrs                 ;	// 9	9  ���ϴ��, ����:��
	int     cur_prc                   ;	// 9	9  ���簡
	int     open                      ;	// 9	9  �ð�, ������ �ð�
	int     high                      ;	// 9	9  ��, ������ ��
	int     low                       ;	// 9	9  ����, ������ ����
	int     ask_prc                   ;	// 9	9  �ŵ�ȣ��, B1�� 0�� SET
	int     bid_prc                   ;	// 9	9  �ż�ȣ��, B1�� 0�� SET
	double  cum_ccls_qty              ;	// 9	12 ����ü�����, ����:�� �ؽð��ܴ��ϰ�, BUY-IN�� ������ ��� ü����� �ջ�
	double  cum_trd_val               ;	// 9	18 �����ŷ����, ����:�� �ؽð��ܴ��ϰ�, BUY-IN�� ������ ��� �ŷ���� �ջ�
	char    trend_flg            [1+1];	// X	1  �Ǽ�/�⼼ ����, 0:�ʱⰪ 1:�Ǽ� 2:�⼼ 3:�ŷ��� 4:�ð����ذ������� �⼼
	char    brd_evt_id           [3+1];	// X	3  �����̺�ƮID, B1/B2 ������ �����̺�ƮID ������(���� ���°��� ���۵� �� ����). ����, �ش� �׸� '000' ���� ����. 2014.03.24)
	char    brd_id               [2+1];	// X	2  ����ID, �� �ڵ尪���� ����
	char    trsp_flg             [1+1];	// X	1  �ŷ���������, Y, N
	double  bopen_ofhr_ccls_qty       ;	// 9	12 "�尳�����ð������� ü�����", �뷮, �ٽ����� ����, ����:��
	double  bopen_ofhr_trd_val        ;	// 9	18 "�尳�����ð������� �ŷ����", �뷮, �ٽ����� ����, ����:��
	double  opr_time_ccls_qty         ;	// 9	12 ������ü�����, �뷮, �ٽ����� ����, ����:��
	double  opr_time_trd_val          ;	// 9	18 ������ŷ����, �뷮, �ٽ����� ����, ����:��
	double  ofhr_cls_ccls_qty         ;	// 9	12 "�������Ľð������� ü�����", �뷮, �ٽ����� ����, ����:��
	double  ofhr_cls_trd_val          ;	// 9	18 "�������Ľð������� �ŷ����", �뷮, �ٽ����� ����, ����:��
	char    elw_ely_cls_flg      [1+1];	// X	1  ELW�������Ῡ��, Y,N ��������ELW �� ������ Default 'N' SET
	int     elw_ely_cls_time          ;	// 9	6  ELW��������ð�, HHMMSS, ELW�������Ῡ�ΰ� 'Y'�� ��츸 ����
	int     cmpt_msv_dir_clsf         ;	// 9	1  ����뷮 ���ⱸ��, 0:�ش����, 1:�ŵ�, 2:�ż�
	double  gen_bin_ccls_qty          ;	// 9	12 �Ϲ� Buy-in ü�����, ����:��
	double  gen_bin_ccls_trd_val      ;	// 9	18 �Ϲ� Buy-in �ŷ����, ����:��
	double  day_bin_ccls_qty          ;	// 9	12 ���� Buy-in ü�����, ����:��
	double  day_bin_ccls_trd_val      ;	// 9	18 ���� Buy-in �ŷ����, ����:��
	char    filler               [8+1];	// X	8  FILLER, SPACE
	char    ff                   [1+1];	// X	1  FF, END OF TEXT (0xFF)
} DFELW_MKT_PRC_CLS;

// B1011 : �ڽ���_�ü�����
typedef struct _DFKOSPI_MKT_PRC_CLS {
	char    data_clsf            [2+1];	// X	2   DATA����, B1:���� B2:�ü�REC
	char    info_clsf            [2+1];	// X	2   ��������, 01:�ֽ� 02:ELW
	char    mkt_clsf             [1+1];	// X	1   ���屸��, 1:�������� 2:�ڽ���
	char    isin_code           [12+1];	// X	12  �����ڵ�, ǥ���ڵ�
	int     stk_snr                   ;	// 9	5   �����Ϸù�ȣ, �����ġ(A0)�� �����Ϸù�ȣ
	char    flct_clsf            [1+1];	// X	1   �������, 0:�ǴܺҰ� 1:���� 2:��� 3:���� 4:���� 5:�϶�
	int     prev_ctrs                 ;	// 9	9   ���ϴ��, ����:��
	int     cur_prc                   ;	// 9	9   ���簡
	int     open                      ;	// 9	9   �ð�, ������ �ð�
	int     high                      ;	// 9	9   ��, ������ ��
	int     low                       ;	// 9	9   ����, ������ ����
	int     ask_prc                   ;	// 9	9   �ŵ�ȣ��, B1�� 0�� SET
	int     bid_prc                   ;	// 9	9   �ż�ȣ��, B1�� 0�� SET
	double  cum_ccls_qty              ;	// 9	12  ����ü�����, ����:�� �ؽð��ܴ��ϰ�, BUY-IN�� ������ ��� ü����� �ջ�
	double  cum_trd_val               ;	// 9	18  �����ŷ����, ����:�� �ؽð��ܴ��ϰ�, BUY-IN�� ������ ��� �ŷ���� �ջ�
	char    trend_flg            [1+1];	// X	1   �Ǽ�/�⼼ ����, 0:�ʱⰪ 1:�Ǽ� 2:�⼼ 3:�ŷ��� 4:�ð����ذ������� �⼼
	char    brd_evt_id           [3+1];	// X	3   �����̺�ƮID, B1/B2 ������ �����̺�ƮID ������(���� ���°��� ���۵� �� ����). ����, �ش� �׸� '000' ���� ����. 2014.03.24)
	char    brd_id               [2+1];	// X	2   ����ID, �� �ڵ尪���� ����
	char    trsp_flg             [1+1];	// X	1   �ŷ���������, Y, N
	double  bopen_ofhr_ccls_qty       ;	// 9	12  "�尳�����ð������� ü�����", �뷮, �ٽ����� ����, ����:��
	double  bopen_ofhr_trd_val        ;	// 9	18  "�尳�����ð������� �ŷ����", �뷮, �ٽ����� ����, ����:��
	double  opr_time_ccls_qty         ;	// 9	12  ������ü�����, �뷮, �ٽ����� ����, ����:��
	double  opr_time_trd_val          ;	// 9	18  ������ŷ����, �뷮, �ٽ����� ����, ����:��
	double  ofhr_cls_ccls_qty         ;	// 9	12  "�������Ľð������� ü�����", �뷮, �ٽ����� ����, ����:��
	double  ofhr_cls_trd_val          ;	// 9	18  "�������Ľð������� �ŷ����", �뷮, �ٽ����� ����, ����:��
	char    elw_ely_cls_flg      [1+1];	// X	1   ELW�������Ῡ��, Y,N ��������ELW �� ������ Default 'N' SET 2010.08.30
	int     elw_ely_cls_time          ;	// 9	6   ELW��������ð�, HHMMSS, ELW�������Ῡ�ΰ� 'Y'�� ��츸 ����
	int     cmpt_msv_dir_clsf         ;	// 9	1   ����뷮 ���ⱸ��, 0:�ش����, 1:�ŵ�, 2:�ż�
	double  gen_bin_ccls_qty          ;	// 9	12  �Ϲ� Buy-in ü�����, ����:��
	double  gen_bin_ccls_trd_val      ;	// 9	18  �Ϲ� Buy-in �ŷ����, ����:��
	double  day_bin_ccls_qty          ;	// 9	12  ���� Buy-in ü�����, ����:��
	double  day_bin_ccls_trd_val      ;	// 9	18  ���� Buy-in �ŷ����, ����:��
	char    filler               [8+1];	// X	8   FILLER, SPACE
	char    ff                   [1+1];	// X	1   FF, END OF TEXT (0xFF)
} DFKOSPI_MKT_PRC_CLS;

// A6011 : �ڽ���_���񸶰�
typedef struct _DFKOSPI_STK_CLSG {
	char    data_clsf               [ 2+1];	// X	2   DATA����, A6
	char    info_clsf               [ 2+1];	// X	2   ��������, 01:�ֽ� 02:ELW
	char    mkt_clsf                [ 1+1];	// X	1   ���屸��, 1:�������� 2:�ڽ���
	char    isin_code               [12+1];	// X	12  �����ڵ�, ǥ���ڵ�
	int     snr                           ;	// 9	5   �����Ϸù�ȣ, �����ġ(A0)�� �����Ϸù�ȣ
	char    brd_id                  [ 2+1];	// X	2   ����ID, �� �ڵ尪���� ����
	int     stk_cls_prc                   ;	// 9	9   ���񸶰�����, ���Խð��ܱ����ڵ尡 \n 1:�������϶��� ���񸶰����ݱ����ڵ尪�� SET ��. \n �׿ܿ��� SPACE
	char    stk_cls_prc_clsf_code   [ 1+1];	// X	1   ���񸶰����ݱ����ڵ�, 1:ü�ᰡ \n 2:�⼼ \n 3:�ŷ��� \n 4:�ð����ذ������� �⼼\n :�������� �ƴ� ��� SPACE
	int     ofhr_ceil                     ;	// 9	9   ���񸶰��ð��ܴ��ϰ� ���Ѱ�
	int     ofhr_flr                      ;	// 9	9   ���񸶰��ð��ܴ��ϰ� ���Ѱ�
	int     stk_cls_mwprc                 ;	// 9	9   ���񸶰���հ����ְ�
	int     dlv_base_prc                  ;	// 9	9   �����ε����ذ���
	int     dlv_ceil                      ;	// 9	9   �����ε����Ѱ�
	int     dlv_flr                       ;	// 9	9   �����ε����Ѱ�
	char    filler                  [ 1+1];	// X	1   FILLER, SPACE
	char    ff                      [ 1+1];	// X	1   FF, END OF TEXT (0xFF)
} DFKOSPI_STK_CLSG;


// S F8011 : ETF PDF
typedef struct _DFETF_PDF {
	char    data_clsf               [ 2+1];	// X	2   DATA����, F8
	char    info_clsf               [ 2+1];	// X	2   ��������, 01:�ֽ�
	char    mkt_clsf                [ 1+1];	// X	1   ���屸��, 1:��������
	char    isin_code               [12+1];	// X	12  ETF�ڵ�
	int     data_snr                      ;	// 9	8   ������ �Ϸù�ȣ, �����Ϸù�ȣ
	char    date                    [ 8+1];	// X	8   ����, YYYYMMDD(��������)
	char    trb_nr                  [ 3+1];	// X	3   �繫��Źȸ���ȣ, '903'�ѱ���Ź������,'049'�̷������ݵ弭��
	int     comp_stk_nr                   ; // 9	4   ���������, ����:����(������ ����)
	char    comp_stk_code           [12+1];	// X	12  ���������ڵ�, �ذ��߰��̵� ����(CP �߰�) 2015.03.03
	double  cu1_unit_scrt_nr              ;	// 9	18  "1CU�������Ǽ�/����/��ȭ����", �ذ��߰��̵� ����(�ܱ�ȯ������ �߰�) 2014.06.16 \nǥ������:9999999999999999v99
	int     comp_stk_mkt_clsf             ;	// 9	1   ����������屸��, 0:��������(����,KSP200T00001,FKSP200T0001����)\n1:�ڽ��� 2:��Ÿ 3:ä�� 4:���� �� �ɼ� 2018.02.05
	char    comp_stk_nm             [40+1];	// X	40  ���������, �ؿ������� ��� �����, �� �ܴ� '0' �Ǵ� SPACE
	double  par_val                       ;  	// 9	18  �׸�ݾ�/�������ݾ�, �ذ��߰��̵� ����(�ܱ�ȯ������ �߰�) 2014.06.16
	char    profit_allc_base_date   [ 8+1];	// X	8   ���ͺй������, �ذ��߰��̵� ���� 2009.07.27
	double  assm_val                      ;	// 9	18  �򰡱ݾ�, PDF�� ���� ���� ���� ����data �ű� 2011.08.29
	char    filler                  [ 4+1];	// X	4   FILLER, ���� 2��4 2011.08.29
	char    ff                      [ 1+1];	// X	1   FF, END OF TEXT (0xFF)
} DFETF_PDF;

//Y �ڽ���_�����������ں�	C0011	�����������ں�
typedef struct _DFKOSPI_BYIND_BYINV {
	char    data_clsf       [2+1];	// X	2   DATA����, C0
	char    info_clsf       [2+1];	// X	2   ��������, 01:�ֽ�
	char    mkt_clsf        [1+1];	// X	1   ���屸��, 1:�������� 2:�ڽ���
	char    cmpt_time       [6+1];	// X	6   ����ð�, 90�� �ֱ�
	char    inv_code        [4+1];	// X	4   �������ڵ�, ���ڵ尪���� ����\n*�ڵ�'7000'�� ����, ������� �׸� 0���� ���� (20181210)
	char    ind_code        [3+1];	// X	3   �����ڵ�, ���ڵ尪������ ���������ڵ�з� ����\n�������;�ڽ�����������, �ڽ�����������, �ڽ���200����
	double  ask_ccls_qty         ;	// 9	12  �ŵ�ü�����, ����:��
	double  ask_trd_val          ;	// 9	18  �ŵ��ŷ����, ����:��
	double  bid_ccls_qty         ;	// 9	12  �ż�ü�����, ����:��
	double  bid_trd_val          ;	// 9	18  �ż��ŷ����, ����:��
	char    filler          [7+1];	// X	7   FILLER, SPACE
	char    ff              [1+1];	// X	1   FF, END OF TEXT (0xFF)
} DFKOSPI_BYIND_BYINV;

//B6011 : �ڽ���_ȣ���ܷ�_LPȣ��_���� KOSPI_ASK_RSD_WOLP
typedef struct _DFKOSPI_ASK_RSD_WOLP {
	char    data_clsf           [2 +1];	// X	2   DATA����, B6
	char    info_clsf           [2 +1];	// X	2   ��������, 01:�ֽ�
	char    mkt_clsf            [1 +1];	// X	1   ���屸��, 1:�������� 2:�ڽ���
	char    isin_code           [12+1];	// X	12  �����ڵ�, ǥ���ڵ�
	int     stk_snr                   ;	// 9	5   5 �����Ϸù�ȣ, �����ġ(A0)�� �����Ϸù�ȣ
	double  cum_ccls_qty              ;	// 9	12  12 ����ü�����
	DF_TICK tick                [10  ];   //          ȣ�� OCCURS 1010�� 42 = 420
	double  ask_tot_rsd_10            ;	// 9	12  10�ܰ�ȣ���ŵ����ܷ�
	double  bid_tot_rsd_10            ;	// 9	12  10�ܰ�ȣ���ż����ܷ�
	char    filler1             [12+1];	// 9	12  FILLER
	char    filler2             [12+1];	// 9	12  FILLER
	double  ofhr_ask_tot_rsd          ;	// 9	12  �������Ľð��� �ŵ���ȣ���ܷ�, ����ID�� ""G3""�� ��� ������
	double  ofhr_bid_tot_rsd          ;	// 9	12  �������Ľð��� �ż���ȣ���ܷ�, ����ID�� ""G3""�� ��� ������
	char    sess_id             [2 +1];	// X	2   ����ID, �� �ڵ尪���� ����
	char    brd_id              [2 +1];	// X	2   ����ID, �� �ڵ尪���� ����
	int     exp_ccls_prc              ;   // 9	9   ����ü�ᰡ��
	double  exp_ccls_qty              ;	// 9	12  ����ü�����
	int     cmpt_msv_dir_clsf         ;	// 9	1   ����뷮 ���ⱸ��, 0:�ش����, 1:�ŵ�, 2:�ż�
	char    filler3             [7 +1];	// X	7   FILLER, SPACE
	char    ff                  [1 +1];	// X	1   FF,      END OF TEXT (0xFF)
} DFKOSPI_ASK_RSD_WOLP;


//B7011 : �ڽ���_ȣ���ܷ�_LPȣ��_���� KOSPI_ASK_RSD_WLP
typedef struct _DFKOSPI_ASK_RSD_WLP {
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
} DFKOSPI_ASK_RSD_WLP;

    
// �ڽ���_ü�� A3011 int 9 double 10 ~
typedef struct _DFKOSPI_CCLS {
	char    data_clsf        [2+1];    	    // DATA����, A3
	char    info_clsf        [2+1];	        // ��������, 01:�ֽ� 02:ELW
	char    mkt_clsf         [1+1];	        // ���屸��, 1:�������� 2:�ڽ���
	char    isin_code       [12+1];	        // �����ڵ�, ǥ���ڵ�
	int     stk_snr               ;	        // �����Ϸù�ȣ, �����ġ(A0)�� �����Ϸù�ȣ
	char    brd_id          [ 2+1];	        // ����ID, �� �ڵ尪���� ����
	char    ctrs_clsf       [ 1+1];	        // "���ϴ��(���ذ����) ����", 0:�ǴܺҰ� 1:���� 2:��� 3:���� 4:���� 5:�϶�\n �� ���Խð��ܱ����ڵ� ���� 4�� ��� ���� ���� ���\n �� ���Խð��ܱ��а��̺�
	int     prev_ctrs             ;	        // ���ϴ��, ����:�� �����μ��� ����/������ �ű� ���� ���� : 0
	int     ccls_prc              ;	        // ü�ᰡ��, ����:��
	double  ccls_qty              ;	        // ü�����, ����:��
	char    sess_id         [ 2+1];	        // ����ID, �� �ڵ尪���� ����
	int     open                  ;	        // �ð�, ����:�� �ذ��߰��̵� ����
	int     high                  ;	        // ��, ����:�� �ذ��߰��̵� ����
	int     low                   ;	        // ����, ����:�� �ذ��߰��̵� ����
	double  cum_ccls_qty          ;	        // ����ü�����, ����:�� �غ���ID���� ������
	double  cum_trd_val           ;	        // �����ŷ����, ����:�� �غ���ID���� ������
	char    fin_bid_ask_clsf_code[1+1];     // �����ŵ��ż������ڵ�, 1:�ŵ� 2:�ż�
	char    mtc_flg         [ 1+1];	        // ü�ᰡ��1ȣ����ġ����, 0:�ǴܺҰ� 1:��ġ 2:����ġ
	char    ccls_time       [ 6+1];	        // ü��ð�, HHMMSS
	double  lp_hld_qty          ;	        // LP��������, LP(ü�����) ������ LP��������\n�����߻� ����(ETN�� �ش�)(2018.09.17)
	int     ask_1_prc           ;	        // �ŵ�1ȣ��, ����:�� �ذ��߰��̵� ����
	int     bid_1_prc           ;	        // �ż�1ȣ��, ����:�� �ذ��߰��̵� ����
	char    filler[6]           ;	        // FILLER, SPACE
	char    ff[1]               ;	            // FF, END OF TEXT (0xFF)
} DFKOSPI_CCLS;

#endif
