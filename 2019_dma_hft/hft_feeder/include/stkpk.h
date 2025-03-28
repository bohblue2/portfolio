#ifndef _STKPK_H_
#define _STKPK_H_

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

int StkProcA3011(char *buff);
int StkProcB4011(char *buff);
int StkProcB6011(char *buff);
int StkProcB7011(char *buff);
int StkProcC0011(char *buff);

int StkProcA3021(char *buff);
int StkProcB7021(char *buff);

int StkProcF8011(char *buff);
int StkProcA6011(char *buff);
int StkProcB1011(char *buff);

int StkProcB1021(char *buff);
int StkProcA6021(char *buff);

PROC_LIST AppList[] = {
{"A3011",     StkProcA3011, "KOSPI_CCLS"            },
{"B6011",     StkProcB6011, "KOSPI_ASK_RSD_WOLP"    },
{"B7011",     StkProcB7011, "KOSPI_ASK_RSD_WLP"     },
{"C0011",     StkProcC0011, "KOSPI_BYIND_BYINV"     },
{"B4011",     StkProcB4011, "KOSPI_OFH_RCVR"        },
{"A3021",     StkProcA3021, "ELW_CCLS"              },
{"B7021",     StkProcB7021, "ELW_ASK_RSD_WLP"       },
{"F8011",     StkProcF8011, "ETF_PDF"               },
{"A6011",     StkProcA6011, "KOSPI_STK_CLSG"        },        // A6011 : �ڽ���_���񸶰�
{"B1011",     StkProcB1011, "KOSPI_MKT_PRC_CLS"     },        // B1011 : �ڽ���_�ü�����
{"B1021",     StkProcB1021, "ELW_MKT_PRC_CLS"       },        // B1021 : ELW_�ü�����
{"A6021",     StkProcA6021, "ELW_MKT_PRC_CLS"       },        // B1021 : ELW_�ü�����
};

#define AP_CNT	( sizeof(AppList)/sizeof(PROC_LIST))

#endif                    

// A6021 : ELW_���񸶰�
typedef struct _ELW_STK_CLSG {
	char    data_clsf             [2];	// X	2   DATA����, A6
	char    info_clsf             [2];	// X	2   ��������, 01:�ֽ� 02:ELW
	char    mkt_clsf              [1];	// X	1   ���屸��, 1:�������� 2:�ڽ���
	char    isin_code            [12];	// X	12  �����ڵ�, ǥ���ڵ�
	char    snr                   [5];	// 9	5   �����Ϸù�ȣ, �����ġ(A0)�� �����Ϸù�ȣ
	char    brd_id                [2];	// X	2   ����ID, �� �ڵ尪���� ����
	char    stk_cls_prc           [9];	// 9	9   ���񸶰�����, ���Խð��ܱ����ڵ尡 \n 1:�������϶��� ���񸶰����ݱ����ڵ尪�� SET ��. \n �׿ܿ��� SPACE
	char    stk_cls_prc_clsf_code [1];	// X	1   ���񸶰����ݱ����ڵ�, 1:ü�ᰡ \n 2:�⼼ \n 3:�ŷ��� \n 4:�ð����ذ������� �⼼\n :�������� �ƴ� ��� SPACE
	char    ofhr_hi               [9];	// 9	9   "���񸶰��ð��ܴ��ϰ� ���Ѱ�"
	char    ofhr_lo               [9];	// 9	9   "���񸶰��ð��ܴ��ϰ� ���Ѱ�"
	char    stk_cls_mwprc         [9];	// 9	9   ���񸶰���հ����ְ�
	char    dlv_base_prc          [9];	// 9	9   �����ε����ذ���
	char    dlv_hi                [9];	// 9	9   �����ε����Ѱ�
	char    dlv_lo                [9];	// 9	9   �����ε����Ѱ�
	char    filler                [1];	// X	1   FILLER, SPACE
	char    ff                    [1];	// X	1   FF, END OF TEXT (0xFF)
} ELW_STK_CLSG;

    
// B1021 : ELW_�ü�����
typedef struct _ELW_MKT_PRC_CLS {
	char    data_clsf            [2];	// X	2  DATA����, B1:���� B2:�ü�REC
	char    info_clsf            [2];	// X	2  ��������, 01:�ֽ� 02:ELW
	char    mkt_clsf             [1];	// X	1  ���屸��, 1:�������� 2:�ڽ���
	char    isin_code           [12];	// X	12 �����ڵ�, ǥ���ڵ�
	char    stk_snr              [5];	// 9	5  �����Ϸù�ȣ, �����ġ(A0)�� �����Ϸù�ȣ
	char    flct_clsf            [1];	// X	1  �������, 0:�ǴܺҰ� 1:���� 2:��� 3:���� 4:���� 5:�϶�
	char    prev_ctrs            [9];	// 9	9  ���ϴ��, ����:��
	char    cur_prc              [9];	// 9	9  ���簡
	char    open                 [9];	// 9	9  �ð�, ������ �ð�
	char    high                 [9];	// 9	9  ��, ������ ��
	char    low                  [9];	// 9	9  ����, ������ ����
	char    ask_prc              [9];	// 9	9  �ŵ�ȣ��, B1�� 0�� SET
	char    bid_prc              [9];	// 9	9  �ż�ȣ��, B1�� 0�� SET
	char    cum_ccls_qty        [12];	// 9	12 ����ü�����, ����:�� �ؽð��ܴ��ϰ�, BUY-IN�� ������ ��� ü����� �ջ�
	char    cum_trd_val         [18];	// 9	18 �����ŷ����, ����:�� �ؽð��ܴ��ϰ�, BUY-IN�� ������ ��� �ŷ���� �ջ�
	char    trend_flg            [1];	// X	1  �Ǽ�/�⼼ ����, 0:�ʱⰪ 1:�Ǽ� 2:�⼼ 3:�ŷ��� 4:�ð����ذ������� �⼼
	char    brd_evt_id           [3];	// X	3  �����̺�ƮID, B1/B2 ������ �����̺�ƮID ������(���� ���°��� ���۵� �� ����). ����, �ش� �׸� '000' ���� ����. 2014.03.24)
	char    brd_id               [2];	// X	2  ����ID, �� �ڵ尪���� ����
	char    trsp_flg             [1];	// X	1  �ŷ���������, Y, N
	char    bopen_ofhr_ccls_qty [12];	// 9	12 "�尳�����ð������� ü�����", �뷮, �ٽ����� ����, ����:��
	char    bopen_ofhr_trd_val  [18];	// 9	18 "�尳�����ð������� �ŷ����", �뷮, �ٽ����� ����, ����:��
	char    opr_time_ccls_qty   [12];	// 9	12 ������ü�����, �뷮, �ٽ����� ����, ����:��
	char    opr_time_trd_val    [18];	// 9	18 ������ŷ����, �뷮, �ٽ����� ����, ����:��
	char    ofhr_cls_ccls_qty   [12];	// 9	12 "�������Ľð������� ü�����", �뷮, �ٽ����� ����, ����:��
	char    ofhr_cls_trd_val    [18];	// 9	18 "�������Ľð������� �ŷ����", �뷮, �ٽ����� ����, ����:��
	char    elw_ely_cls_flg      [1];	// X	1  ELW�������Ῡ��, Y,N ��������ELW �� ������ Default 'N' SET
	char    elw_ely_cls_time     [6];	// 9	6  ELW��������ð�, HHMMSS, ELW�������Ῡ�ΰ� 'Y'�� ��츸 ����
	char    cmpt_msv_dir_clsf    [1];	// 9	1  ����뷮 ���ⱸ��, 0:�ش����, 1:�ŵ�, 2:�ż�
	char    gen_bin_ccls_qty    [12];	// 9	12 �Ϲ� Buy-in ü�����, ����:��
	char    gen_bin_ccls_trd_val[18];	// 9	18 �Ϲ� Buy-in �ŷ����, ����:��
	char    day_bin_ccls_qty    [12];	// 9	12 ���� Buy-in ü�����, ����:��
	char    day_bin_ccls_trd_val[18];	// 9	18 ���� Buy-in �ŷ����, ����:��
	char    filler               [8];	// X	8  FILLER, SPACE
	char    ff                   [1];	// X	1  FF, END OF TEXT (0xFF)
} ELW_MKT_PRC_CLS;
    
// B1011 : �ڽ���_�ü�����
typedef struct _KOSPI_MKT_PRC_CLS {
	char    data_clsf            [2];	// X	2   DATA����, B1:���� B2:�ü�REC
	char    info_clsf            [2];	// X	2   ��������, 01:�ֽ� 02:ELW
	char    mkt_clsf             [1];	// X	1   ���屸��, 1:�������� 2:�ڽ���
	char    isin_code           [12];	// X	12  �����ڵ�, ǥ���ڵ�
	char    stk_snr              [5];	// 9	5   �����Ϸù�ȣ, �����ġ(A0)�� �����Ϸù�ȣ
	char    flct_clsf            [1];	// X	1   �������, 0:�ǴܺҰ� 1:���� 2:��� 3:���� 4:���� 5:�϶�
	char    prev_ctrs            [9];	// 9	9   ���ϴ��, ����:��
	char    cur_prc              [9];	// 9	9   ���簡
	char    open                 [9];	// 9	9   �ð�, ������ �ð�
	char    high                 [9];	// 9	9   ��, ������ ��
	char    low                  [9];	// 9	9   ����, ������ ����
	char    ask_prc              [9];	// 9	9   �ŵ�ȣ��, B1�� 0�� SET
	char    bid_prc              [9];	// 9	9   �ż�ȣ��, B1�� 0�� SET
	char    cum_ccls_qty        [12];	// 9	12  ����ü�����, ����:�� �ؽð��ܴ��ϰ�, BUY-IN�� ������ ��� ü����� �ջ�
	char    cum_trd_val         [18];	// 9	18  �����ŷ����, ����:�� �ؽð��ܴ��ϰ�, BUY-IN�� ������ ��� �ŷ���� �ջ�
	char    trend_flg            [1];	// X	1   �Ǽ�/�⼼ ����, 0:�ʱⰪ 1:�Ǽ� 2:�⼼ 3:�ŷ��� 4:�ð����ذ������� �⼼
	char    brd_evt_id           [3];	// X	3   �����̺�ƮID, B1/B2 ������ �����̺�ƮID ������(���� ���°��� ���۵� �� ����). ����, �ش� �׸� '000' ���� ����. 2014.03.24)
	char    brd_id               [2];	// X	2   ����ID, �� �ڵ尪���� ����
	char    trsp_flg             [1];	// X	1   �ŷ���������, Y, N
	char    bopen_ofhr_ccls_qty [12];	// 9	12  "�尳�����ð������� ü�����", �뷮, �ٽ����� ����, ����:��
	char    bopen_ofhr_trd_val  [18];	// 9	18  "�尳�����ð������� �ŷ����", �뷮, �ٽ����� ����, ����:��
	char    opr_time_ccls_qty   [12];	// 9	12  ������ü�����, �뷮, �ٽ����� ����, ����:��
	char    opr_time_trd_val    [18];	// 9	18  ������ŷ����, �뷮, �ٽ����� ����, ����:��
	char    ofhr_cls_ccls_qty   [12];	// 9	12  "�������Ľð������� ü�����", �뷮, �ٽ����� ����, ����:��
	char    ofhr_cls_trd_val    [18];	// 9	18  "�������Ľð������� �ŷ����", �뷮, �ٽ����� ����, ����:��
	char    elw_ely_cls_flg      [1];	// X	1   ELW�������Ῡ��, Y,N ��������ELW �� ������ Default 'N' SET 2010.08.30
	char    elw_ely_cls_time     [6];	// 9	6   ELW��������ð�, HHMMSS, ELW�������Ῡ�ΰ� 'Y'�� ��츸 ����
	char    cmpt_msv_dir_clsf    [1];	// 9	1   ����뷮 ���ⱸ��, 0:�ش����, 1:�ŵ�, 2:�ż�
	char    gen_bin_ccls_qty    [12];	// 9	12  �Ϲ� Buy-in ü�����, ����:��
	char    gen_bin_ccls_trd_val[18];	// 9	18  �Ϲ� Buy-in �ŷ����, ����:��
	char    day_bin_ccls_qty    [12];	// 9	12  ���� Buy-in ü�����, ����:��
	char    day_bin_ccls_trd_val[18];	// 9	18  ���� Buy-in �ŷ����, ����:��
	char    filler               [8];	// X	8   FILLER, SPACE
	char    ff                   [1];	// X	1   FF, END OF TEXT (0xFF)
} KOSPI_MKT_PRC_CLS;


// A6011 : �ڽ���_���񸶰�
typedef struct _KOSPI_STK_CLSG {
	char    data_clsf               [ 2];	// X	2   DATA����, A6
	char    info_clsf               [ 2];	// X	2   ��������, 01:�ֽ� 02:ELW
	char    mkt_clsf                [ 1];	// X	1   ���屸��, 1:�������� 2:�ڽ���
	char    isin_code               [12];	// X	12  �����ڵ�, ǥ���ڵ�
	char    snr                     [ 5];	// 9	5   �����Ϸù�ȣ, �����ġ(A0)�� �����Ϸù�ȣ
	char    brd_id                  [ 2];	// X	2   ����ID, �� �ڵ尪���� ����
	char    stk_cls_prc             [ 9];	// 9	9   ���񸶰�����, ���Խð��ܱ����ڵ尡 \n 1:�������϶��� ���񸶰����ݱ����ڵ尪�� SET ��. \n �׿ܿ��� SPACE
	char    stk_cls_prc_clsf_code   [ 1];	// X	1   ���񸶰����ݱ����ڵ�, 1:ü�ᰡ \n 2:�⼼ \n 3:�ŷ��� \n 4:�ð����ذ������� �⼼\n :�������� �ƴ� ��� SPACE
	char    ofhr_ceil               [ 9];	// 9	9   ���񸶰��ð��ܴ��ϰ� ���Ѱ�
	char    ofhr_flr                [ 9];	// 9	9   ���񸶰��ð��ܴ��ϰ� ���Ѱ�
	char    stk_cls_mwprc           [ 9];	// 9	9   ���񸶰���հ����ְ�
	char    dlv_base_prc            [ 9];	// 9	9   �����ε����ذ���
	char    dlv_ceil                [ 9];	// 9	9   �����ε����Ѱ�
	char    dlv_flr                 [ 9];	// 9	9   �����ε����Ѱ�
	char    filler                  [ 1];	// X	1   FILLER, SPACE
	char    ff                      [ 1];	// X	1   FF, END OF TEXT (0xFF)
} KOSPI_STK_CLSG;

// S F8011 : ETF PDF
typedef struct _ETF_PDF {
	char    data_clsf               [ 2];	// X	2   DATA����, F8
	char    info_clsf               [ 2];	// X	2   ��������, 01:�ֽ�
	char    mkt_clsf                [ 1];	// X	1   ���屸��, 1:��������
	char    isin_code               [12];	// X	12  ETF�ڵ�
	char    data_snr                [ 8];	// 9	8   ������ �Ϸù�ȣ, �����Ϸù�ȣ
	char    date                    [ 8];	// X	8   ����, YYYYMMDD(��������)
	char    trb_nr                  [ 3];	// X	3   �繫��Źȸ���ȣ, '903'�ѱ���Ź������,'049'�̷������ݵ弭��
	char    comp_stk_nr             [ 4];	// 9	4   ���������, ����:����(������ ����)
	char    comp_stk_code           [12];	// X	12  ���������ڵ�, ���߰��̵� ����(CP �߰�) 2015.03.03
	char    cu1_unit_scrt_nr        [18];	// 9	18  "1CU�������Ǽ�/����/��ȭ����", ���߰��̵� ����(�ܱ�ȯ������ �߰�) 2014.06.16 \nǥ������:9999999999999999v99
	char    comp_stk_mkt_clsf       [ 1];	// 9	1   ����������屸��, 0:��������(����,KSP200T00001,FKSP200T0001����)\n1:�ڽ��� 2:��Ÿ 3:ä�� 4:���� �� �ɼ� 2018.02.05
	char    comp_stk_nm             [40];	// X	40  ���������, �ؿ������� ��� �����, �� �ܴ� '0' �Ǵ� SPACE
	char    par_val                 [18];	// 9	18  �׸�ݾ�/�������ݾ�, ���߰��̵� ����(�ܱ�ȯ������ �߰�) 2014.06.16
	char    profit_allc_base_date   [ 8];	// X	8   ���ͺй������, ���߰��̵� ���� 2009.07.27
	char    assm_val                [18];	// 9	18  �򰡱ݾ�, PDF�� ���� ���� ���� ����data �ű� 2011.08.29
	char    filler                  [ 4];	// X	4   FILLER, ���� 2��4 2011.08.29
	char    ff                      [ 1];	// X	1   FF, END OF TEXT (0xFF)
} ETF_PDF;


// Y �ڽ���_�����������ں�	C0011	�����������ں�
typedef struct _KOSPI_BYIND_BYINV {
	char    data_clsf       [2 ];	// X	2   DATA����, C0
	char    info_clsf       [2 ];	// X	2   ��������, 01:�ֽ�
	char    mkt_clsf        [1 ];	// X	1   ���屸��, 1:�������� 2:�ڽ���
	char    cmpt_time       [6 ];	// X	6   ����ð�, 90�� �ֱ�
	char    inv_code        [4 ];	// X	4   �������ڵ�, �ڵ尪���� ����\n*�ڵ�'7000'�� ����, ������� �׸� 0���� ���� (20181210)
	char    ind_code        [3 ];	// X	3   �����ڵ�, �ڵ尪������ ���������ڵ�з� ����\n�������;�ڽ�����������, �ڽ�����������, �ڽ���200����
	char    ask_ccls_qty    [12];	// 9	12  �ŵ�ü�����, ����:��
	char    ask_trd_val     [18];	// 9	18  �ŵ��ŷ����, ����:��
	char    bid_ccls_qty    [12];	// 9	12  �ż�ü�����, ����:��
	char    bid_trd_val     [18];	// 9	18  �ż��ŷ����, ����:��
	char    filler          [7 ];	// X	7   FILLER, SPACE
	char    ff              [1 ];	// X	1   FF, END OF TEXT (0xFF)
} KOSPI_BYIND_BYINV;


//B6011 : �ڽ���_ȣ���ܷ�_LPȣ��_���� KOSPI_ASK_RSD_WOLP
//B7011 : �ڽ���_ȣ���ܷ�_LPȣ��_���� KOSPI_ASK_RSD_WLP

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

//B6011 : �ڽ���_ȣ���ܷ�_LPȣ��_���� KOSPI_ASK_RSD_WOLP
typedef struct _KOSPI_ASK_RSD_WOLP {
	char data_clsf          [2 ];	// DATA����, B6
	char info_clsf          [2 ];	// ��������, 01:�ֽ�
	char mkt_clsf           [1 ];	// ���屸��, 1:�������� 2:�ڽ���
	char isin_code          [12];	// �����ڵ�, ǥ���ڵ�
	char stk_snr            [5 ];	// �����Ϸù�ȣ, �����ġ(A0)�� �����Ϸù�ȣ
	char cum_ccls_qty       [12];	// ����ü�����
	PK_TICK tick            [10];   // ȣ�� OCCURS 1010�� 42 = 420
	char ask_tot_rsd_10[12];	// 10�ܰ�ȣ���ŵ����ܷ�
	char bid_tot_rsd_10[12];	// 10�ܰ�ȣ���ż����ܷ�
	char filler1[12];	// FILLER
	char filler2[12];	// FILLER
	char ofhr_ask_tot_rsd[12];	// �������Ľð��� �ŵ���ȣ���ܷ�, ����ID�� ""G3""�� ��� ������
	char ofhr_bid_tot_rsd[12];	// �������Ľð��� �ż���ȣ���ܷ�, ����ID�� ""G3""�� ��� ������
	char sess_id[2];	// ����ID,  �ڵ尪���� ����
	char brd_id[2];	// ����ID,  �ڵ尪���� ����
	char exp_ccls_prc[9];	// ����ü�ᰡ��
	char exp_ccls_qty[12];	// ����ü�����
	char cmpt_msv_dir_clsf[1];	// ����뷮 ���ⱸ��, 0:�ش����, 1:�ŵ�, 2:�ż�
	char filler3[7];	// FILLER, SPACE
	char ff[1];	// FF, END OF TEXT (0xFF)
} KOSPI_ASK_RSD_WOLP;


//B7011 : �ڽ���_ȣ���ܷ�_LPȣ��_���� KOSPI_ASK_RSD_WLP
typedef struct _KOSPI_ASK_RSD_WLP {
	char data_clsf[2];	// DATA����, B7
	char info_clsf[2];	// ��������, 01:������������ 02:ELW
	char mkt_clsf[1];	// ���屸��, 1:��������
	char isin_code[12];	// �����ڵ�, ǥ���ڵ�
	char stk_snr[5];	// �����Ϸù�ȣ, �����ġ(A0)�� �����Ϸù�ȣ
	char cum_ccls_qty[12];	// ����ü�����
	PK_TICKLP ticklp[10];  // ȣ�� OCCURS 1010�� 66 = 660
	char ask_tot_rsd_10[12];	// 10�ܰ�ȣ���ŵ����ܷ�
	char bid_tot_rsd_10[12];	// 10�ܰ�ȣ���ż����ܷ�
	char filler1[12];	// FILLER
	char filler2[12];	// FILLER
	char ofhr_ask_tot_rsd[12];	// �������Ľð��� �ŵ���ȣ���ܷ�, ����ID�� ""G3""�� ��� ������ \n ELW�� �ð��ܰŷ� ����
	char ofhr_bid_tot_rsd[12];	// �������Ľð��� �ż���ȣ���ܷ�, ����ID�� ""G3""�� ��� ������\n ELW�� �ð��ܰŷ� ����
	char sess_id[2];	// ����ID,  �ڵ尪���� ����
	char brd_id[2];	// ����ID,  �ڵ尪���� ����
	char exp_ccls_prc[9];	// ����ü�ᰡ��
	char exp_ccls_qty[12];	// ����ü�����
	char cmpt_msv_dir_clsf[1];	// ����뷮 ���ⱸ��, 0:�ش����, 1:�ŵ�, 2:�ż�
	char filler3[7];	// FILLER, SPACE
	char ff[1];	// FF, END OF TEXT (0xFF)
} KOSPI_ASK_RSD_WLP;

    
// �ڽ���_ü�� A3011
typedef struct _KOSPI_CCLS {
	char data_clsf[2];	            // DATA����, A3
	char info_clsf[2];	            // ��������, 01:�ֽ� 02:ELW
	char mkt_clsf[1];	            // ���屸��, 1:�������� 2:�ڽ���
	char isin_code[12];	            // �����ڵ�, ǥ���ڵ�
	char stk_snr[5];	            // �����Ϸù�ȣ, �����ġ(A0)�� �����Ϸù�ȣ
	char brd_id[2];	                // ����ID, �ڵ尪���� ����
	char ctrs_clsf[1];	            // 
	char prev_ctrs[9];	            // ���ϴ��, ����:�� �����μ��� ����/������ �ű� ���� ���� : 0
	char ccls_prc[9];	            // ü�ᰡ��, ����:��
	char ccls_qty[10];	            // ü�����, ����:��
	char sess_id[2];	            // ����ID, �ڵ尪���� ����
	char open[9];	                // �ð�, ����:�� ���߰��̵� ����
	char high[9];                   // ��, ����:�� ���߰��̵� ����
	char low[9];	                // ����, ����:�� ���߰��̵� ����
	char cum_ccls_qty[12];	        // ����ü�����, ����:�� ����ID���� ������
	char cum_trd_val[18];	        // �����ŷ����, ����:�� ����ID���� ������
	char fin_bid_ask_clsf_code[1];	// �����ŵ��ż������ڵ�, 1:�ŵ� 2:�ż�
	char mtc_flg[1];	            // ü�ᰡ��1ȣ����ġ����, 0:�ǴܺҰ� 1:��ġ 2:����ġ
	char ccls_time[6];	            // ü��ð�, HHMMSS
	char lp_hld_qty[15];	        // LP��������, LP(ü�����) ������ LP��������\n�����߻� ����(ETN�� �ش�)(2018.09.17)
	char ask_1_prc[9];	            // �ŵ�1ȣ��, ����:�� ���߰��̵� ����
	char bid_1_prc[9];	            // �ż�1ȣ��, ����:�� ���߰��̵� ����
	char filler[6];	                // FILLER, SPACE
	char ff[1];	                    // FF, END OF TEXT (0xFF)
} KOSPI_CCLS;

// �ڽ���_�ð��ܴ��ϰ�_��Ŀ���� B4011
typedef struct _KOSPI_OFH_RCVR {
	char data_clsf[2];	// DATA����, B4:�ð��ܴ��ϰ� �ü�, B3:�ð��ܴ��ϰ�����
	char info_clsf[2];	// ��������, 01:�ֽ�
	char mkt_clsf[1];	// ���屸��, 1:�������� 2:�ڽ���
	char isin_code[12];	// �����ڵ�, ǥ���ڵ�
	char stk_snr[5];	// �����Ϸù�ȣ, �����ġ(A0)�� �����Ϸù�ȣ 2014.03.03
	char ofhr_cnst_clsf[1];	// �ð��ܴ��ϰ���񱸺�, 0:�ǴܺҰ� 1:���� 2:��� 3:���� 4:���� 5:�϶�
	char ofhr_cnst[9];	// �ð��ܴ��ϰ����, ����:��
	char ofhr_cnst_ceil[9];	// �ð��ܴ��ϰ����Ѱ�
	char ofhr_cnst_flr[9];	// �ð��ܴ��ϰ����Ѱ�
	char ofhr_cnst_cur[9];	// �ð��ܴ��ϰ����簡
	char ofhr_cnst_open[9];	// �ð��ܴ��ϰ��ð�
	char ofhr_cnst_hi[9];	// �ð��ܴ��ϰ���
	char ofhr_cnst_lo[9];	// �ð��ܴ��ϰ�����
	char ofhr_cnst_ask[9];	// �ð��ܴ��ϰ��ŵ�ȣ��
	char ofhr_cnst_bid[9];	// �ð��ܴ��ϰ��ż�ȣ��
	char ofhr_cnst_cum_ccls_qty[12];	// "�ð��ܴ��ϰ����� ü�����"
	char ofhr_cnst_cum_trd_val[18];	// "�ð��ܴ��ϰ����� �ŷ����"
	char tot_cum_ccls_qty[12];	// ��ü �� ����ü�����, ����:�� ���� ��ü ����
	char tot_cum_trd_val[18];	// ��ü �� �����ŷ����, ����:�� ���� ��ü ����
	char ofhr_mkt_clsf[1];	// �ð��ܴ��ϰ��屸��, 0:�ʱⰪ 1:�ð��ܴ��ϰ����� 2:�ð��ܴ��ϰ�����
	char trsp_flg[1];	// �ŷ���������, Y, N
	char trend_flg[1];	// �Ǽ�/�⼼ ����, 0:�ʱⰪ 1:�Ǽ� 2:�⼼ 3:�ŷ��� 4:�ð����ذ������� �⼼
	char filler[2];	// FILLER, SPACE
	char ff[1];	// FF, END OF TEXT (0xFF)
} KOSPI_OFH_RCVR;

#endif
