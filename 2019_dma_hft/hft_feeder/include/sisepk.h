/*
 * ����   : �������� Packet
 * NAME   : sisepk.h
 * DATE   : 2003-10-02 2:10����(��������)
 * By     : �輺��
 * Remark :
 */
/* -------------------------------------------------------------------------- *
   2004.11.29.
      ���� ip���� (recovery ip����)
          �峻/�ڽ���/����/�ɼ�
          -  ��ý��� : 210.108.26.63/210.108.26.158 -> 210.108.26.57
          -  ����ý��� : 210.108.26.56
          -  �׽�Ʈ�ý��� : 210.108.26.58
         �ֽĿɼ�
          -  ��ý��� : 210.108.26.158 -> 210.108.26.57
          -  ����ý��� : 210.108.26.56
          -  �׽�Ʈ�ý��� : 210.108.26.58
         ����
          -  ��ý��� : 210.108.26.63 -> 210.108.26.57
          -  ����ý��� : 210.108.26.56
          -  �׽�Ʈ�ý��� : 210.108.26.58
         ECN
          -  ��ý��� : 210.108.26.56 -> 210.108.26.57
          -  ����ý��� : 210.108.26.56
          -  �׽�Ʈ�ý��� : 210.108.26.58
     ��Ʈ����
         �ֽĿɼ� : 15195

     recovery ip/��Ʈ����
          -  �峻/�ڽ���        : 15000 ~ 15002
          -  ����/�ɼ�/�ֽĿɼ� : 16000 ~ 16002
          -  ECN  : 19000
          -  ���� : 18000


2006-10-16
	IP����
	  - 210.108.26.57 -> 210.108.26.68

	��Ʈ����
	  - �ŷ���/�ڽ���      15XX1/15XX4 -> 16XX1/16XX4
	  - ����/�ɼ�/         15XX2/15XX3 -> 16XX2/16XX3
	  - �ֽĿɼ�/��Ÿ����  15XX5/15XX6 -> 16XX5/16XX6
	  - ����               180XX       -> 181XX

 * -------------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>

#ifndef __SISEPK_H__
#define __SISEPK_H__

/* ========================================================================== */
/* ����������Ʈ */
#define  KOSPI_PORT        16191
#define  FUTURE_PORT       16192
#define  OPTION_PORT       16193
#define  KOSDAQ_PORT       16194
#define  STOPTION_PORT     16195
#define  NOTICE_PORT       18122

/* ========================================================================== */
/* ���� ��Ŀ���� Proxy ���� */
#define  RECOVER_PORT      25000         /* �峻/�ڽ���          */
#define  RECOVER_PORT_SO   26000         /* �ֽĿɼ�             */
#define  RECOVER_PORT_FU   26001         /* ����                 */
#define  RECOVER_PORT_OP   26002         /* �ɼ�                 */
#define  RECOVER_PORT_EL   7300          /* ELW                  */
#define  RECOVER_PORT_SF   7300          /* �ֽļ���             */
#define  RECOVER_PORT_MK   7300          /* �ֽļ���             */
#define  RECOVER_PORT_NT   28000         /* ����                 */

#define  RECOVER_ADDR      "10.101.32.197"


#if 0 /************************************************************************/

/* ���� ��Ŀ���� ���� */
#define  REAL_RECOVER_PORT    15000      /* �峻/�ڽ���          */
#define  REAL_RECOVER_PORT_SO 16000      /* �ֽĿɼ�             */
#define  REAL_RECOVER_PORT_FU 16001      /* ����                 */
#define  REAL_RECOVER_PORT_OP 16002      /* �ɼ�                 */
#define  REAL_RECOVER_PORT_NT 18000      /* ����                 */

#define  REAL_RECOVER_ADDR    "210.108.26.68"
#define  REAL_RECOVER_ADDR_SO "210.108.26.68"

#endif /***********************************************************************/

#define  REAL_RECOVER_PORT    7300      /* �峻/�ڽ���           */
#define  REAL_RECOVER_PORT_SO 7300      /* �ֽĿɼ�              */
#define  REAL_RECOVER_PORT_FU 7300      /* ����                  */
#define  REAL_RECOVER_PORT_OP 7300      /* �ɼ�                  */
#define  REAL_RECOVER_PORT_EL 7300      /* ELW                   */
#define  REAL_RECOVER_PORT_SF 7300      /* �ֽļ���              */
#define  REAL_RECOVER_PORT_MK 7300      /* ��ǰ����              */
#define  REAL_RECOVER_PORT_NT 7300      /* ����                  */

#define  REAL_RECOVER_ADDR    "125.209.203.66"
#define  REAL_RECOVER_ADDR_SO "125.209.203.66"

/* ========================================================================== */
/*
** ��������Ʈ �ü� ó������ "125.209.203.66~67"
*/
#define  MAKETPOINT_ADDR1      	"125.209.203.66"
#define  MAKETPOINT_ADDR2      	"10.101.32.67"

#define  MAKET_KOSPI_PORT        7301    /* �ŷ���               */
#define  MAKET_KOSDAQ_PORT       7302    /* �ڽ���               */
#define  MAKET_FUTURE_PORT       7303    /* ����                 */
#define  MAKET_OPTION_PORT       7304    /* �ɼ�                 */
#define  MAKET_STOPTION_PORT     7305    /* �ֽĿɼ�             */
#define  MAKET_ELW_PORT          7306    /* ELW                  */
#define  MAKET_STFU_PORT         7307    /* �ֽļ���             */
#define  MAKET_MKFU_PORT         7308    /* ��ǰ����             */
#define  MAKET_NOTICE_PORT       7309    /* ����                 */

/*
#define  MAKET_RECOVER_ADDR      "125.209.203.66"
#define  MAKET_RECOVER_PORT      7300
*/
#define  MAKET_RECOVER_ADDR      "10.101.32.197"
#define  MAKET_RECOVER_PORT      17300

/* ========================================================================== */
#define  HEADER_PK_ID      0x98          /* Header Packet        */
#define  FOOTER_PK_ID      0x99          /* Footer packet        */

#define  KOSPIMST_PK_ID    0x02          /* �峻   ���� ������   */
#define  KOSDAQMST_PK_ID   0x13          /* �ڽ��� ���� ������   */
#define  KOSPIUPMST_PK_ID  0x03          /* KOSPI    ���� ������ */
#define  KOSPI200MST_PK_ID 0x04          /* KOSPI200 ���� ������ */
#define  KOSPI50MST_PK_ID  0x08          /* KOSPI50  ���� ������ */
#define  KOSDAQUPMST_PK_ID 0x05          /* KOSDAQ   ���� ������ */
#define  KOSDAQ50MST_PK_ID 0x06          /* KOSDAQ50 ���� ������ */

#define  KOSPIREAL_PK_ID   'S'           /* �峻   ���� �ü�     */
#define  KOSPIREAL2_PK_ID  's'           /* �峻   ���� �ü�2    */
#define  KOSPIBASE_PK_ID   'M'           /* �峻   ���� �������� */
#define  KOSDAQREL_PK_ID   0xa1          /* �ڽ��� ���� �ü�     */
#define  KOSDAQREL2_PK_ID  'r'           /* �ڽ��� ���� �ü�2    */
#define  KOSPIUP_PK_ID     'J'           /* �峻     ��������    */
#define  KOSPI200_PK_ID    'I'           /* KOSPI200 ����        */
#define  KOSPI200UP_PK_ID  'y'           /* KOSPI200 ��������    */
#define  KOSPI50_PK_ID     'N'           /* KOSPI50  ��������    */
#define  KOSDAQUP_PK_ID    'O'           /* �ڽ���   ��������    */
#define  KOSDAQ50_PK_ID    'L'           /* KOSDAQ50 ��������    */

#define  KOSDAQSTAR_PK_ID  'j'           /* KOSTAR����           */
#define  KOSPI50_PK_ID     'N'           /* KOSPI50���� ����     */
#define  KOSPIKD_PK_ID     'K'           /* KOSPIKODI�������    */
#define  KOSPICOMP_PK_ID   'Z'           /* ���豸������������ */

#define  KOSPIUPEXP_PK_ID  'V'           /* KOSPIUP��������      */
#define  KOSPI200UPEXP_PK_ID	'W'      /* KOSPI200UP��������   */
#define  KOSPIKDEXP_PK_ID  'Y'           /* KOSPIKODI��������    */
#define  KOSDAQUPEXP_PK_ID 'X'           /* KOSDAQ������������   */
#define  KOSDAQ50EXP_PK_ID 'U'           /* KOSDAQ50������������ */

#define  KOSPIUPUD_PK_ID   'D'           /* KOSPI  ���� ���     */
#define  KOSPI200UD_PK_ID  'T'           /* KOSPI200 ���        */
#define  KOSDAQUD_PK_ID    0xd1          /* KOSDAQ   ���        */

#define  KOSPIETFNAV_PK_ID 'i'           /* ETF ����/���� NAV    */
#define  KOSPIETFPDF_PK_ID 'P'           /* ETF PDF              */
#define  KOSDAQETFNAV_PK_ID 'Q'          /* ETF ����/���� NAV    */
#define  KOSDAQETFPDF_PK_ID 'R'          /* ETF PDF              */

#define  KOSSUMJISU_PK_ID    'E'         /* ��������             */
#define  KOSSUMJISUEXP_PK_ID 'H'         /* ���տ�������         */

#define  FUTMST_PK_ID      'a'           /* ���� ������          */
#define  FUTREL_PK_ID      'b'           /* ���� �ü�            */
#define  FUTUJA_PK_ID      'g'           /* ���� ������          */

#define  OPTMST_PK_ID      'c'           /* �ɼ� ������          */
#define  OPTREL_PK_ID      'd'           /* �ɼ� �ü�            */
#define  OPTUJA_PK_ID      'h'           /* �ɼ� ������          */

#define  STOPTMST_PK_ID    'e'           /* �ֽĿɼ� ������      */
#define  STOPTREL_PK_ID    'f'           /* �ֽĿɼ� �ü�        */
#define  STOPTUJA_PK_ID    'j'           /* �ֽĿɼ� ������      */

#define  ELWMST_PK_ID      0x71          /* ELW ������           */
#define  ELWREL_PK_ID      0x74          /* ELW ü��             */
#define  ELWHOGA_PK_ID     0x75          /* ELW ȣ��(10�ܰ�)     */
#define  ELWLPHOGA_PK_ID   0x76          /* ELW lp ȣ��          */
#define  ELWKOBAMST_PK_ID  0x91          /* �������� elw������   */
#define  ELWKOBABS_PK_ID   0x92          /* �������� elw������ �����ڻ������*/
#define  ELWKOBATM_PK_ID   0x93          /* �������� elw ������*/


#define  STFUMST_PK_ID     0x81          /* �����ֽļ��� ������  */
#define  STFUREL_PK_ID     0x82          /* �����ֽļ��� ü��    */
#define  STFUHOGA_PK_ID    0x83          /* �����ֽļ��� ȣ��(10�ܰ�)*/

#define  MKFUMST_PK_ID     0x85          /* ��ǰ�ֽļ��� ������  */
#define  MKFUREL_PK_ID     0x86          /* ��ǰ�ֽļ��� ü��    */
#define  MKFUHOGA_PK_ID    0x87          /* ��ǰ�ֽļ��� ȣ��(10�ܰ�)*/
#define  MKFUFIN_PK_ID     0x88          /* ��ǰ�ֽļ��� ���񸶰�*/
#define  MKFUJUNG_PK_ID    0x89          /* ��ǰ�ֽļ��� ���갡  */
#define  MKFUMIGYUL_PK_ID  0x90          /* ��ǰ�ֽļ��� �̰�������*/

#define  REALHGDWCHG_PK_ID 0x94          /* �ǽð������Ѱ� ���������*/

#define  FUTUPDW_PK_ID     0x9a          /* ���� ������(����������Ȯ��ߵ�)         */
#define  OPTUPDW_PK_ID     0x9b          /* �ɼ� ������(����������Ȯ��ߵ�)         */
#define  STFUPDW_PK_ID     0x9c          /* �����ֽļ��� ������(����������Ȯ��ߵ�) */
#define  STOPUPDW_PK_ID    0x9d          /* �����ֽĿɼ� ������(����������Ȯ��ߵ�) */

#define  KOSPINT_PK_ID     'G'           /* �ŷ��Ұ���           */
#define  KOSDAQNT_PK_ID    'O'           /* �ڽ��ڰ���           */

#define PACKED __attribute__((packed))

/*
* ���ݱ���
* 15-bit 14- bit
*   0       1         16,000�� �̸�          1��
*   0       0         16,036.000 -    160,000     10��
*   1       0        160,000 -  1,599,999    100��
*   1       1      1,600,000 - 16,383,000   1000��
*/

/*****************************************************************************/
/* ����                                                                      */
/*****************************************************************************/

typedef struct _HEADER{
	char    id          [1]; /* DATA ID 0x98          */
	char    gubun       [1]; /* ������  Data �� ID    */
	short   version        ; /* 1 Set                 */
	long    size           ; /* ���۰Ǽ� or 1         */
	char    tail        [3]; /* 0xff, 0xod, 0x0a      */
}HEADER;
typedef struct _FOOTER{
	char    id          [1]; /* DATA ID 0x98          */
	char    gubun       [1]; /* ������  Data �� ID    */
	short   version        ; /* 1 Set                 */
	long    size           ; /* ���۰Ǽ� or 1         */
	char    tail        [3]; /* 0xff, 0xod, 0x0a      */
}FOOTER;
typedef struct _PK_HOGA{
	long    hmedo          ; /* �ŵ�ȣ��              */
	long    hmesu          ; /* �ż�ȣ��              */
	long    hmedoval       ; /* �ŵ�ȣ���ܷ�          */
	long    hmesuval       ; /* �ż�ȣ���ܷ�          */
}PK_HOGA;
typedef struct _PK_OFHOGA{
	long    hmedo          ; /* �ŵ�ȣ��              */
	long    hmesu          ; /* �ż�ȣ��              */
	long    hmedoqty       ; /* �ŵ�ȣ���ܷ�          */
	long    hmesuqty       ; /* �ż�ȣ���ܷ�          */
	long    hmedocnt       ; /* �ŵ�ȣ���Ǽ�          */
	long    hmesucnt       ; /* �ż�ȣ���Ǽ�          */
}PK_OFHOGA;
typedef struct _PK_ELWHOGA{
	long    hmedo          ; /* �ŵ�ȣ��              */
	long    hmesu          ; /* �ż�ȣ��              */
	long    hmedoqty       ; /* �ŵ�ȣ���ܷ�          */
	long    hmesuqty       ; /* �ż�ȣ���ܷ�          */
	long    lphmedoqty     ; /* LP �ŵ�ȣ���ܷ�       */
	long    lphmesuqty     ; /* LP �ż�ȣ���ܷ�       */
}PK_ELWHOGA;
typedef struct _PK_UP{
	long    jisu           ; /* ���� .99              */
	long    volume         ; /* �ŷ���:õ��           */
	long    value          ; /* �ŷ����:�鸸         */
	long    filler         ; /* filler                */
}PK_UP;
typedef struct _PK_UPQ{
	long    gb             ; /* 1~160 �ڽ�����������ǥ���� (����) */
	long    jisu           ; /* ���� .99              */
	long    volume         ; /* �ŷ���:õ��           */
	long    value          ; /* �ŷ����:�鸸         */
}PK_UPQ;


/*****************************************************************************/
/* KOSPI                                                                     */
/*****************************************************************************/

typedef struct _PK_KOSPIJMST{ /* �峻�ֽ� Master          */
	char    id          [1]; /* Data ID 0x02          */
	char    filler1     [1]; /* filler                */
	short   index          ; /* ���� �Ϸù�ȣ         */
	char    shcode      [9]; /* �����ڵ�              */ /* 2003-10-06 ����  5->9 */
	char	kospi200up  [1]; /* KOSPI200 �����ڵ�     */
	char    excode     [12]; /* ���ڵ�(����ǥ��)      */
	char    hname      [16]; /* �����                */
	char    upcode      [2]; /* �����ڵ�              */
	short   setmonth       ; /* ����                */
	char    sgubun      [2]; /* �Ҽӱ��� 1:1�� 6:���� */
	/* char    capgubun    [1]; *//* filler                *//* 2004-02-02 �ں��ݱ���(capgubun) -> filler *//* 2007-04-02 ���� */
	char    rakgubun    [1]; /* ������                */
	char    trgubun     [1]; /* ���������ŷ���������  */
	char    eventgubun  [1]; /* ���� �׺�/���� 1:�׺� 2:���� */
	char    reitsgubun  [1]; /* �������� 1:�Ϲݸ��� 2:CR���� 8:ETF */
	long    baseprc        ; /* ���ذ�                */
	long    bopen          ; /* ���Ͻð�              */
	long    bhigh          ; /* ���ϰ�              */
	long    blow           ; /* ��������              */
	long    bclose         ; /* ��������              */
	long    bvolume        ; /* ���� �ŷ��� (1��)     */
	long    bamt           ; /* ���� �ŷ���� (10,000��) */
	long    upprc          ; /* ���Ѱ�                */
	long    dwprc          ; /* ���Ѱ�                */
	long    max52          ; /* 52�� �ְ�           */
	long    min52          ; /* 52�� ������           */
	long    max52dt        ; /* 52�� �ְ���         */
	long    min52dt        ; /* 52�� ��������         */
	long    listcnt        ; /* �����ֽļ�            */
	long    capital        ; /* �ں��� (�鸸)         */
	long    beps           ; /* �Ⱓ�ִ�����ͱ� .99  */
	long    faceval        ; /* �׸鰡                */
	long    reitssdt       ; /* �������Ӱ����� CR������ �ش� */
	long    reitsedt       ; /* �������������� CR������ �ش� */
	char    errgubun    [1]; /* �Ҽ��ǰ��� ����       */
	char    filler3     [3]; /* filler                */
	char	filler11   [32]; /* ��������   -> filler 2007-12-14 */
	short	manuindu       ; /* ������ ���� 41:������ 50:�������� */
	char	filler4	    [2];
	short   maxyeardt      ; /* ���� �ְ��� (����)  */
	short   minyeardt      ; /* ���� �������� (����)  */
	long    maxyear        ; /* ���� �ְ�           */
	long    minyear        ; /* ���� ������           */
	char	bgise       [1]; /* ���� �⼼���� 1:�⼼  */
	char	bupdown     [1]; /* ���� �������         */
	char	filler5     [2];
	long	listdt         ; /* ������                */
	long	subprice       ; /* ��밡                */
	long	totamt         ; /* �ð��Ѿ� (���)       */
	long    max50          ; /* 50�� �ְ�           */
	long    min50          ; /* 50�� ������           */
	long    max50dt        ; /* 50�� �ְ���         */
	long    min50dt        ; /* 50�� ��������         */
	long	gamriprc       ; /* ���������������      */
	long	gamridt        ; /* �������������        */
	short	contupdt       ; /* ���� ���Ѱ� �ϼ�      */
	short	contdndt       ; /* ���� ���Ѱ� �ϼ�      */
	short	totupdt        ; /* �������� ���Ѱ� �ϼ�  */
	short	totdndt        ; /* �������� ���Ѱ� �ϼ�  */
	long	chngfacedt     ; /* �׸鰡 ������         */
	long	baedang        ; /* ����                */
	short	chngfacerate   ; /* �׸� �������         */
	short	midbaedang     ; /* �߰��������� 0:���� 1:�߰����� 2:�Ǹ����� */
	long	trdunit        ; /* �ŸŴ���              */
	long	jungridt       ; /* �����Ÿ� ������       */
	long	jungridtend    ; /* �����Ÿ� ������       */
	long	fodrable1      ; /* �ܱ����ֹ����ɼ��� ���� */
	long	fodrable2      ; /* �ܱ����ֹ����ɼ��� �� */
	long	fmaxqty1       ; /* �ܱ����ѵ����� ����   */
	long	fmaxqty2       ; /* �ܱ����ѵ����� ��     */
	long	fmaxrate       ; /* �ܱ����ѵ����� .99  */
	long	etfgb          ; /* ETF �з� 0:�Ϲ� 1:���߾��ݵ� 2:�������� */
	long	etfupjong1     ; /* ETF ��������������    */
	long	etfupjong2     ; /* ETF ��������������    */
	long	etfupjong3     ; /* ETF ��������������    */
	long	etfcuunit      ; /* ETF CU����            */
	long	etfjongcnt     ; /* ETF ���������        */
	long	etftotamt      ; /* ETF ���ڻ��Ѿ�(�鸸��)*/
	char	etfdaejugi  [2]; /* ETF ����ֱ�          */
	char	totamtgubun [2]; /* �ð��ѾױԸ𱸺� 02:�� 03:�� 04:�� 99:�������� (20030117�߰�) */
	long	etfjidaebi     ; /* ETF ������������� .99*/
	long	lastnav        ; /* ���� NAV .99          */
	char	gwangam     [1]; /* ������������ 0:�Ϲ� 1:����+���� */
	char	kospi10050  [1]; /* KOSPI100/50���� 0:�Ϲ� 1:100 2:50 */
	char	filler6     [1]; /* KOSPIIT ���� 0:�Ϲ� 1:IT *//* kospiit -> filler 2007-04-02 ����*/
	char	filler8     [1]; /* filler                */
	char	hname2     [44]; /* �����2  24->44       */
	char	mgstcom_gb  [2]; /* ���豸������������  01:�ش� 02:�ش���׾���*/ /* 2003-12-01 �߰� */
	short	invstcompgb    ; /* ����ȸ�籸��          *//* 2005-06-01 �߰� */
	short	invstjisuingb  ; /* ����ȸ�������������񿩺� 0:�����̻������� 1:������������ *//* 2005-06-01 �߰� */
	char	igritemgb   [1]; /* �����������񱸺� 0:�Ϲ� 1:������������ *//* 2005-06-01 �߰� */
	char	listgb      [1]; /* ���屸�� 1:���� 2:�ű� 3:���� 4:���ذ������İŷ��� 5:�������� 6:�ֽĺ��� 7:���ذ����� *//* 2005-06-01 �߰� */
	char	filler9     [3]; /* filler                */
	char	krxjisucargb[1]; /* 0:�Ϲ� 1: KRX�������� �ڵ��� �������   */
	char	krxjisusemgb[1]; /* 0:�Ϲ� 1: KRX�������� �ݵ�ü �������   */
	char	krxjisubiogb[1]; /* 0:�Ϲ� 1: KRX�������� ���̿� �������   */
	char	krxjisufingb[1]; /* 0:�Ϲ� 1: KRX�������� ���� �������     */
	char	krxjisucmigb[1]; /* 0:�Ϲ� 1: KRX�������� ������� ������� */
	long	vengubunstart  ; /* ���������� YYYYMMDD �ҼӺ� ������ 4,10,12�� ���� �ش�    */
	long	vengubunend    ; /* ���������� YYYYMMDD �ҼӺ� ������ 4,10,12�� ���� �ش�    */
	short	settledt       ; /* ������ MMDD �ҼӺ� ������ 4,12�� ���� �ش� */
	char	ename      [40]; /* ������                *//* 2007-12-14 */

	char	invest_gb   [2]; /* ����溸�����ڵ� 00:�ش���� 01:�������� 02:���ڰ�� 03:��������*/
	char	gwanitem_gb [1]; /* �������񿩺� Y, N*/
	char	jungri_gb   [1]; /* �����Ÿſ��� Y, N*/

	char	event_gb    [2]; /* �̺�Ʈ         *//*2011-03-11 2:10���� �߰�*/
	char	event_rt1   [8]; /* �̺�Ʈ ��������*//*2011-03-11 2:10���� �߰�*/
	char	event_rt2   [8]; /* �̺�Ʈ �����Ҽ�*//*2011-03-11 2:10���� �߰�*/
	char	filler10   [32]; /* filler                *//* 2011-03-11 2:10���� 50->32 */
	char    ff          [1]; /* 0xff                  */
	char    cr          [1]; /* 0x0d                  */
	char    lf          [1]; /* 0x0a                  */
}PK_KOSPIJMST;
typedef struct _PK_KOSPIJBASE{ /* �峻���ذ� */
	char    id          [1]; /* Data ID 'M'           */
	char    filler      [1]; /* Filler                */
	char    datagb      [3]; /* ����Ÿ�з�            */
	char    excode     [12]; /* ���ڵ�(����ǥ��)      */
	char    opendt      [8]; /* ������                */
	char    opentm      [8]; /* �����ð�              */
	char    procbf     [15]; /* ��ġ�İ�              */
	char    procaf     [15]; /* ��ġ����              */
	char    baseprc     [9]; /* ���ذ�                */
	char    upprc       [9]; /* ���Ѱ�                */
	char    dwprc       [9]; /* ���Ѱ�                */
	char    baseprcgb   [2]; /* ���ذ����⿩��   00:�̻���, 01:���� */
	char    prc         [9]; /* ����                  */
	char    qty        [10]; /* ����                  */
	char    meme_gb     [2]; /* �Ÿű���              */
	char    filler2     [6]; /* Filler2               */
	char    ff          [1]; /* 0xff                  */
	char    cr          [1]; /* 0x0d                  */
	char    lf          [1]; /* 0x0a                  */
}PK_KOSPIJBASE;

typedef struct _PK_KOSPIJONG{
	char    id          [1]; /* Data ID 'S'           */
	char    vol_gb      [1]; /* �ܷ�����  0:���� 1:�������Ľð��� 2:�尳�����ð��� 3:�ð��ܴ��ϰ�����*//* 2005-05-30 �����߰� */
	char    filler      [2]; /* Filler                *//* 2003-12-01 ���� 3-> 2*/
	short   index          ; /* �Ϸù�ȣ              */
	short   stime          ; /* �������۽ð�          */
	char    chegb       [1]; /* ü�ᱸ�� 1:���� 2:�尳�����ð��� 3:�������Ľð��� 4:�ð��ܴ��ϰ� *//* 2005-05-30 �߰� filler(1) -> chegb(1) */
	char    updown      [1]; /* �������              */
	char    ovtmunithggb[1]; /* �ð��ܴ��ϰ�ȣ������  *//* 2005-05-30 �߰� filler2(1) ->ovtmunithggb(1) */
	char    dongsigb    [1]; /* ����/�������� -> ���ñ���(2002-09-30)  0:����, 1:����, 2:���ÿ��� */
	long    daebi          ; /* ��� 0:�ʱⰪ 1:�ð��ܴ��ϰ����� 2:�ð��ܴ��ϰ����� *//* 2005-05-30 �߰� */
	long    price          ; /* ���簡                */
	long    open           ; /* �ð�                  */
	long    high           ; /* ��                  */
	long    low            ; /* ����                  */
	long    volume         ; /* �����ŷ���            */
	long    amt            ; /* �����ŷ����(�鸸)    */
	PK_HOGA hoga[10]       ; /* 10����ȣ��            */
	long    dcheprc        ; /* �Ѹŵ�ȣ���ܷ� -> ����ü�ᰡ(2002-09-30)   */
	long    dcheqty        ; /* �Ѹż�ȣ���ܷ� -> ����ü�����(2002-09-30) */
	long    otmedotot      ; /* �ð��� �� �ŵ��ܷ�    */
	long    otmesutot      ; /* �ð��� �� �ż��ܷ�    */
	long    hgmedotot      ; /* 10�ܰ� �ŵ��ܷ��հ�   */
	long    hgmesutot      ; /* 10�ܰ� �ż��ܷ��հ�   */
	long    bfjangmedotot  ; /* �尳�����ð��� �Ѹŵ��ܷ� *//* 2003-12-01 �߰� */
	long    bfjangmesutot  ; /* �尳�����ð��� �Ѹż��ܷ� *//* 2003-12-01 �߰� */
	long    ovtmunitmedotot; /* �ð��ܴ��ϰ� 10�ܰ� �Ѹŵ��ܷ� *//* 2005-05-30 �߰� */
	long    ovtmunitmesutot; /* �ð��ܴ��ϰ� 10�ܰ� �Ѹż��ܷ� *//* 2005-05-30 �߰� */
	long    wavg           ; /* ������հ�            */
	char    janggb      [2]; /* �屸��                */
	char    filler3     [1]; /*                       *//* 2005-05-30 size ���� 2->1 */
	char    gise        [1]; /* �Ǽ�/�⼼���� 1:�Ǽ� 2:�⼼ 3:�ŷ��� *//* filler3 2->1 *//* 2005-05-30 �߰� */
	long    bfcheprc       ; /* �ð��� �Ű�뷮/�ٽ��� �ŸŽ� *//* 2003-12-01 �߰� */
	long    ovtmunithigh   ; /* �ð��ܴ��ϰ����Ѱ�    *//* 2005-05-30 �߰� */
	long    ovtmunitlow    ; /* �ð��ܴ��ϰ����Ѱ�    *//* 2005-05-30 �߰� */
	long    tdclose        ; /* ��������              *//* 2005-05-30 �߰� */
	char    ff          [1]; /* 0xff                  */
	char    cr          [1]; /* 0x0d                  */
	char    lf          [1]; /* 0x0a                  */
}PK_KOSPIJONG;
typedef struct _PK_KOSPICHE{
	PK_KOSPIJONG  jp;
	char          shcode[6];
	long          dif;/* �����ŷ��� */
}PK_KOSPICHE;
typedef struct _PK_KOSPIUPMST{ /* �峻���� Master         */
	char    id          [1]; /* Data ID 0x03          */
	char    filler      [1]; /* Filler                */
	short   upcode         ; /* �����ڵ� 1~22 23~27 38~40 */
	char    hname      [16]; /* ������                */
	long    bopen          ; /* ���Ͻð�              */
	long    bhigh          ; /* ���ϰ�              */
	long    blow           ; /* ��������              */
	long    bclose         ; /* �������� ���� .99     */
	long    volume         ; /* ���ϰŷ���(õ��)      */
	char    ff          [1]; /* 0xff                  */
	char    cr          [1]; /* 0x0d                  */
	char    lf          [1]; /* 0x0a                  */
}PK_KOSPIUPMST;

typedef struct _PK_KOSPIUPMST PK_KOSPI200MST;
typedef struct _PK_KOSPIUPMST PK_KOSPI50MST;

typedef struct _PK_KOSPI1MIN{ /* 1������ */
	char    id          [1]; /* Data id 'J'           */
	char    jgubun      [1]; /* �屸�� 1:���� 3:�ð������� */
	short   index          ; /* �Ϸù�ȣ              */
	long    time           ; /* �ð�  ����:1100000    */
	                         /*       ����:2100000    */
	                         /*     �ð���:3100000    */
	PK_UP   item       [41];
	char    ff          [1]; /* 0xff                  */
	char    cr          [1]; /* 0x0d                  */
	char    lf          [1]; /* 0x0a                  */
}PK_KOSPI1MIN;
typedef struct _PK_KOSPI2001MIN{
	char    id          [1]; /* Data id 'I'           */
	char    jgubun      [1]; /* �屸�� �̻��         */
	short   index          ; /* �Ϸù�ȣ              */
	long    time           ; /* �ð�  ����:1100000    */
	                         /*       ����:2100000    */
	                         /*     �ð���:3100000    */
	PK_UP   item        [6];
	char    ff          [1]; /* 0xff                  */
	char    cr          [1]; /* 0x0d                  */
	char    lf          [1]; /* 0x0a                  */
}PK_KOSPI2001MIN;
typedef struct _PK_KOSPI501MIN{
	char    id          [1]; /* Data id 'N'           */
	char    jgubun      [1]; /* �屸�� �̻��         */
	short   index          ; /* �Ϸù�ȣ              */
	long    time           ; /* �ð�  ����:1100000    */
	                         /*       ����:2100000    */
	                         /*     �ð���:3100000    */
	PK_UP   item        [1];
	char    ff          [1]; /* 0xff                  */
	char    cr          [1]; /* 0x0d                  */
	char    lf          [1]; /* 0x0a                  */
}PK_KOSPI501MIN;
typedef struct _PK_KOSPIUPDN{
	char    id         [1]; /* Data id 'J'            */
	char    jgubun     [1]; /* �屸�� �̻��          */
	short   stime         ; /* ����:1100, 21000       */
	short   uplmcnt       ; /* ���������             */
	short   upcnt         ; /* ��������             */
	short   bohap         ; /* ���������             */
	short   dwlmcnt       ; /* ���� �����            */
	short   dwcnt         ; /* �϶������             */
	short   giup          ; /* �⼼ ���              */
	short   gidw          ; /* �⼼ �϶�              */
	short   totcnt        ; /* ��ü�����             */
	short   trancnt       ; /* �ŷ������             */
	char    ff         [1]; /* 0xff                   */
	char    cr         [1]; /* 0x0d                   */
	char    lf         [1]; /* 0x0a                   */
}PK_KOSPIUPDN;
typedef struct _PK_KOSPIUPDN PK_KOSPI200UPDN;

/*
** 2005-05-30 �ű��߰�
*/
typedef struct _PK_KOSPIJONG2{ /* KOSPI����ü� 2 */
	char    id          [1]; /* Data ID 's'           */
	char    vol_gb      [1]; /* �ܷ�����  0:���� 1:�������Ľð��� 2:�尳�����ð��� 3:�ð��ܴ��ϰ�����*//* 2005-05-30 �����߰� */
	char    filler      [2]; /* Filler                *//* 2003-12-01 ���� 3-> 2*/
	short   index          ; /* �Ϸù�ȣ              */
	short   stime          ; /* �������۽ð�          */
	char    chegb       [1]; /* ü�ᱸ�� 1:���� 2:�尳�����ð��� 3:�������Ľð��� 4:�ð��ܴ��ϰ� *//* 2005-05-30 �߰� filler(1) -> chegb(1) */
	char    updown      [1]; /* �������              */
	char    ovtmunithggb[1]; /* �ð��ܴ��ϰ�ȣ������  *//* 2005-05-30 �߰� filler2(1) ->ovtmunithggb(1) */
	char    dongsigb    [1]; /* ����/�������� -> ���ñ���(2002-09-30)  0:����, 1:����, 2:���ÿ��� */
	long    daebi          ; /* ��� 0:�ʱⰪ 1:�ð��ܴ��ϰ����� 2:�ð��ܴ��ϰ����� *//* 2005-05-30 �߰� */
	long    price          ; /* ���簡                */
	long    open           ; /* �ð�                  */
	long    high           ; /* ��                  */
	long    low            ; /* ����                  */
	long    volume         ; /* �����ŷ���            */
	long    amt            ; /* �����ŷ����(�鸸)    */
	PK_HOGA hoga[10]       ; /* 10����ȣ��            */
	long    dcheprc        ; /* �Ѹŵ�ȣ���ܷ� -> ����ü�ᰡ(2002-09-30)   */
	long    dcheqty        ; /* �Ѹż�ȣ���ܷ� -> ����ü�����(2002-09-30) */
	long    otmedotot      ; /* �ð��� �� �ŵ��ܷ�    */
	long    otmesutot      ; /* �ð��� �� �ż��ܷ�    */
	long    hgmedotot      ; /* 10�ܰ� �ŵ��ܷ��հ�   */
	long    hgmesutot      ; /* 10�ܰ� �ż��ܷ��հ�   */
	long    bfjangmedotot  ; /* �尳�����ð��� �Ѹŵ��ܷ� */
	long    bfjangmesutot  ; /* �尳�����ð��� �Ѹż��ܷ� */
	long    ovtmunitmedotot; /* �ð��ܴ��ϰ� 10�ܰ� �Ѹŵ��ܷ� */
	long    ovtmunitmesutot; /* �ð��ܴ��ϰ� 10�ܰ� �Ѹż��ܷ� */
	long    wavg           ; /* ������հ�            */
	char    janggb      [2]; /* �屸��                */
	char    filler3     [1]; /*                       */
	char    gise        [1]; /* �Ǽ�/�⼼���� 1:�Ǽ� 2:�⼼ 3:�ŷ��� */
	long    bfcheprc       ; /* �ð��� �Ű�뷮/�ٽ��� �ŸŽ� */
	long    ovtmunithigh   ; /* �ð��ܴ��ϰ����Ѱ�    */
	long    ovtmunitlow    ; /* �ð��ܴ��ϰ����Ѱ�    */
	long    tdclose        ; /* ��������              */

	char    filler4     [3]; /* filler                */
	char	ovtmupdown  [1]; /* �ð��ܴ��ϰ� �������  1:����,2:���,3:����,4:����,5:�϶� 6:�⼼*/
	long    ovtmdaebi      ; /* �ð��ܴ��ϰ� ��� 0:�ʱⰪ 1:�ð��ܴ��ϰ����� 2:�ð��ܴ��ϰ����� */
	long    ovtmprice      ; /* �ð��ܴ��ϰ� ���簡   */
	long    ovtmopen       ; /* �ð��ܴ��ϰ� �ð�     */
	long    ovtmhigh       ; /* �ð��ܴ��ϰ� ��     */
	long    ovtmlow        ; /* �ð��ܴ��ϰ� ����     */
	long    ovtmvolume     ; /* �ð��ܴ��ϰ� �����ŷ���            */
	long    ovtmamt        ; /* �ð��ܴ��ϰ� �����ŷ����(�鸸)    */

	char    ff          [1]; /* 0xff                  */
	char    cr          [1]; /* 0x0d                  */
	char    lf          [1]; /* 0x0a                  */
}PK_KOSPIJONG2;


/*****************************************************************************/
/* KOSDAQ                                                                    */
/*****************************************************************************/

typedef struct _PK_KOSDAQJMST{   /* KOSDAQ ���� Master    */
	char    id          [1]; /* Data ID 0x13          */
	char    filler1     [1]; /* filler                */
	short   index          ; /* ���� �Ϸù�ȣ         */
	char    shcode      [9]; /* �����ڵ�              */ /* 2003-10-06 ����  5->9 */
	char    vengubun    [1]; /* �ҼӺα���  2001.10.25 �߰�(A) */
	char    hname      [20]; /* �����                */
	char    upcode      [2]; /* �����ڵ�              */
	short   setmonth       ; /* ����                */
	char    capgubun    [1]; /* �ں��ݱԸ�            */
	char    trgubun     [1]; /* �ŷ���������          */
	char    rakgubun    [1]; /* filler                */ /* 2005-03-07 ���� (������->filler) */
	char    toojagubun  [1]; /* �������� ����         */
	char    mkprcjugb   [1]; /* ���尡�ֹ����� ����   */
	char    kosdaq50gb  [1]; /* Kosdaq50 ���� ����    */
	long    baseprc        ; /* ���ذ�                */
	long    bopen          ; /* ���Ͻð�              */
	long    bhigh          ; /* ���ϰ�              */
	long    blow           ; /* ��������              */
	long    bclose         ; /* ��������              */
	long    bvolume        ; /* ���� �ŷ���           */
	long    upprc          ; /* ���Ѱ�                */
	long    dwprc          ; /* ���Ѱ�                */
	long    beps           ; /* �Ⱓ�ִ�����ͱ� .99  */
	long    listdt         ; /* ������                */
	long    listcnt        ; /* �����ֽļ�            */
	long    faceval        ; /* �׸鰡                */
	long    memedt         ; /* �ŸŰ�����(������)    */
	char    updcode     [2]; /* ������з��ڵ� 2001.10.25 �߰�(A) */
	char    upmcode     [3]; /* �����ߺз��ڵ� 2001.10.25 �߰�(A) */
	char	bepssign    [1]; /* eps ��ȣ '+','-', '#':eps���� */
	char    filler3     [2]; /* filler                */
	char    excode     [12]; /* ǥ���ڵ�              */
	char    ename      [30]; /* ������                */
	char    filler4     [1]; /* filler                */
	char    brakgb      [1]; /* ���϶�����  0:����,1:�Ǹ���,3:����,4:�űԻ���,6:���ֻ��� */
	long    bamt           ; /* ���� �ŷ���� (10,000��) */
	char	gwangb      [1]; /* �������� 0:���� 1:����*/
	char    errgubun    [1]; /* �Ҽ��ǰ��� ���� 0:���� 1:����      */
	char    errsau      [1]; /* �Ҽ��ǰ��� ���� 1:���ú�����, 2:���ù���, 3:���ú��� */
	char	bgise       [1]; /* ���� �⼼���� 0:���� 1:�⼼  */
	long	bper           ; /* ����PER  .99          */
	char	bupdown     [1]; /* ���� �������  1:����,2:���,3:����,4:����,5:�϶� */
	char    trsaugb     [1]; /* �ŷ�������������      */
	char    toojasaugb  [1]; /* ���������������� ���� */
	char    listgubun   [1]; /* ���屸�� 0:���� 1:�ű� 2:�߰� */
	long    toojadt        ; /* ��������������(�����)*/
	long    maxyear        ; /* ���� �ְ�           */
	long    minyear        ; /* ���� ������           */
	short   maxyeardt      ; /* ���� �ְ��� (����)  */
	short   minyeardt      ; /* ���� �������� (����)  */
	short	contupdt       ; /* ���� ���Ѱ� �ϼ�      */
	short	contdndt       ; /* ���� ���Ѱ� �ϼ�      */
	short	totupdt        ; /* �������� ���Ѱ� �ϼ�  */
	short	totdndt        ; /* �������� ���Ѱ� �ϼ�  */
	long	chngfacedt     ; /* �׸鰡 ������         */
	short	chngfacerate   ; /* �׸� �������         */
	char	gwanshcodegb[1]; /* �̻�޵����񱸺� 0:���� 1:�̻�޵����� */
	char	filler6     [1]; /* IT50����  filler      *//* it50 -> filler ���� 2007-04-02 */
	long    max52          ; /* 52�� �ְ�           */
	long    min52          ; /* 52�� ������           */
	long    max52dt        ; /* 52�� �ְ���         */
	long    min52dt        ; /* 52�� ��������         */
	long    errdt          ; /* �Ҽ��ǰ��� ������     */
	long    max52volume    ; /* 52�� �ְ�ŷ���(��)   */
	long	fodrable2      ; /* �ܱ����ֹ����ɼ��� �� */
	long	fmaxqty2       ; /* �ܱ����ѵ����� ��     */
	long	fmaxrate       ; /* �ܱ����ѵ����� .99    */
	long	etfgb          ; /* ETF �з� 0:�Ϲ� 1:���߾��ݵ� 2:�������� */
	long	etfobjgb       ; /* ETF ����� ���� 0:�Ϲ� 1:KOSDAQ50       */
	long	etfcuunit      ; /* ETF CU ����  ����:����*/
	long	etfjongcnt     ; /* ETF ��������� ����:���� */
	long	etftotamt      ; /* ETF ���ڻ��Ѿ� ����:�鸸�� */
	char	etfdaejugi  [2]; /* ETF ����ֱ�   ����:���� */
	char	outrakinfo  [2]; /* �ܺΰ���������        */ /* 2005-03-07 ���� (filler5->outrakinfo) */
	long	etfjidaebi     ; /* ETF ������������� �Ҽ�������2�ڸ�   */
	long	lastnav        ; /* ���� NAV           �Ҽ�������2�ڸ�   */
	char	sichogb     [1]; /* ���ʰ����ⱸ��        */ /* 2005-03-07 ���� (filler7->sichogb)     */
	char	randomendgb [1]; /* Random End ����       */ /* 2005-03-07 ���� (filler7->randomendgb) */
	char	filler7     [2]; /* filler                */ /* 2005-03-07 ���� (filler7->filler6)     */
	long	jungridt       ; /* �����Ÿ� ������       */ /* 2005-03-07 ���� (filler7->jungridt)    */
	long	jungridtend    ; /* �����Ÿ� ������       */ /* 2005-03-07 ���� (filler7->jungridtend) */
	char	igritemgb   [1]; /* �����������񱸺� 0:�Ϲ� 1:������������ *//* 2005-06-01 �߰� */
	char	filler8     [3]; /* filler                */
	char	krxjisucargb[1]; /* 0:�Ϲ� 1: KRX�������� �ڵ��� �������   */
	char	krxjisusemgb[1]; /* 0:�Ϲ� 1: KRX�������� �ݵ�ü �������   */
	char	krxjisubiogb[1]; /* 0:�Ϲ� 1: KRX�������� ���̿� �������   */
	char	krxjisufingb[1]; /* 0:�Ϲ� 1: KRX�������� ���� �������     */
	char	krxjisucmigb[1]; /* 0:�Ϲ� 1: KRX�������� ������� ������� */
	char	lpjuablegb  [1]; /* LP �ֹ����ɿ��� 0:�Ұ� 1:���� */
	char	lpminqty   [10]; /* LP��� �ּ�ȣ������ */
	char	backdoorlist[1]; /* ��ȸ���屸�� 0:���� 1:��ȸ���� */
	char	tujaexcite  [1]; /* ����ȯ�ⱸ��          *//* 2011-07-04 �߰� */
	char	filler9     [2]; /* filler                */
	long	rprc           ; /* ��밡                */
	long	capital        ; /* �ں��� (�鸸��)       */

	char	filler10   [14]; /* filler                */
	char	invest_gb   [2]; /* ����溸�����ڵ� 00:�ش���� 01:�������� 02:���ڰ�� 03:��������*/
	char	gwanitem_gb [1]; /* �������񿩺� Y, N*/
	char	jungri_gb   [1]; /* �����Ÿſ��� Y, N*/
	char	filler11    [2]; /* filler                */
	char    ff          [1]; /* 0xff                  */
	char    cr          [1]; /* 0x0d                  */
	char    lf          [1]; /* 0x0a                  */

}PK_KOSDAQJMST;


typedef struct _PK_KOSDAQJONG{ /* KOSDAQ ����ü�     */
	char    id          [1]; /* Data ID 0xa1          */
	char    jgubun      [1]; /* filler                */ /* 2005-03-07 ���� (jgubun->filler) */
	short   index          ; /* �Ϸù�ȣ              */
	short   stime          ; /* �ð�(HHMM) 21000:���� */
	char    trgubun     [1]; /* �ŷ���������          */
	char    toojagubun  [1]; /* �������� ����         */
	/* char    rakgubun    [1]; *//* filler                */ /* 2005-03-07 ���� (jgubun->filler) */
	char    chegb       [1]; /* ü�ᱸ�� 1:���� 2;��������� �ð��������Ÿ� 3:�������Ľð��� �뷮�Ÿ� 4:�尳�����ð��������Ÿ� 5:�尳�����ð��ܴ뷮�Ÿ� 6:�ð��� ���ϰ��Ÿ� *//* 2005-05-30 �߰� filler(1) -> chegb(1) */
	char    updown      [1]; /* �������              */
	char    gise        [1]; /* �Ǽ�/�⼼���� 0:�ʱⰪ 1:�⼼ 2:�⼼�ƴ� */ /* 2005-03-07 ���� */
	char    dongsigb    [1]; /* ����ȣ������ 1:���ʵ��� 2:���� 3:�������� 4:�ð������� 5:���ߵ���  */
	long    baseprc        ; /* ���ذ�                */
	long    upprc          ; /* ���Ѱ�                */
	long    dwprc          ; /* ���Ѱ�                */
	long    daebi          ; /* ��� 0:�ʱⰪ 1:�ð��ܴ��ϰ����� 2:�ð��ܴ��ϰ����� *//* 2005-05-30 �߰� */
	long    price          ; /* ���簡                */
	long    open           ; /* �ð�                  */
	long    high           ; /* ��                  */
	long    low            ; /* ����                  */
	long    volume         ; /* �ŷ���                */
	long    amt            ; /* �����ŷ����(õ��)    */
	PK_HOGA hoga[10]       ; /* 10����ȣ��            */
	long    dcheprc        ; /* �Ѹŵ�ȣ���ܷ� -> ����ü�ᰡ(2002-09-30)   */
	long    dcheqty        ; /* �Ѹż�ȣ���ܷ� -> ����ü�����(2002-09-30) */
	long    otmedotot      ; /* �ð��� �� �ŵ��ܷ�    */
	long    otmesutot      ; /* �ð��� �� �ŵ��ܷ�    */
	long    hgmedotot      ; /* 10�ܰ� �ŵ��ܷ��հ�   */
	long    hgmesutot      ; /* 10�ܰ� �ż��ܷ��հ�   */
	long    bfhgmedotot    ; /* �尳�����ð��ܸŵ����ܷ� *//* 2004-02-16 �߰�*/
	long    bfhgmesutot    ; /* �尳�����ð��ܸż����ܷ� *//* 2004-02-16 �߰�*/
	long    ovtmunitmedotot; /* �ð��ܴ��ϰ� 10�ܰ� �Ѹŵ��ܷ� *//* 2005-05-30 �߰� */
	long    ovtmunitmesutot; /* �ð��ܴ��ϰ� 10�ܰ� �Ѹż��ܷ� *//* 2005-05-30 �߰� */
	/* char    baseprccg   [1]; *//* filler                */ /* 2005-03-07 ���� (baseprccg->filler) */
	char    ovtmunithggb[1]; /* �ð��ܴ��ϰ�ȣ������  *//* 2005-05-30 �߰� filler2(1) ->ovtmunithggb(1) */
	char	upprcgb     [1]; /* ���Ѱ����濩��        */
	char    dwprcgb     [1]; /* ���Ѱ����濩��        */
	char    vol_gb      [1]; /* �ܷ�����  0:�ʱⰪ 1:���� 4:�������� �ð��� 5:������� �ð��� *//* 2004-02-16 �߰� */
	long    bfcheprc       ; /* ���߿��� 0, �ð��� �ŷ����� ü�ᰡ������ *//* 2004-02-16 �߰�*/
	char    datagb      [2]; /* DATA�з�              */ /* 2005-03-07 �߰� *//* 01:����ü�ᰡ �����ߴ� 02:����ü�ᰡ �����簳 03:���ذ��������� 04:���ʵ���RANDOM END ���� 05:���ʵ���RANDOM END ���� 06:��������RANDOM END ���� 07:��������RANDOM END ���� 08:���ÿ��� ���� 09:���ÿ��� ���� 10:�ð������� �Ÿ� ���� 11:�ð������� �Ÿ� ���� 12:�尳���� �ð��� ���� 13:������ ����  */
	char    filler1     [2]; /* filler                */ /* 2005-03-07 �߰� */
	long    ovtmunithigh   ; /* �ð��ܴ��ϰ����Ѱ�    */ /* 2005-05-30 �߰� */
	long    ovtmunitlow    ; /* �ð��ܴ��ϰ����Ѱ�    */ /* 2005-05-30 �߰� */
	long    tdclose        ; /* ��������              */ /* 2005-05-30 �߰� */
	char    ff          [1]; /* 0xff                  */
	char    cr          [1]; /* 0x0d                  */
	char    lf          [1]; /* 0x0a                  */
}PK_KOSDAQJONG;


typedef struct _PK_KOSDAQCHE{
	PK_KOSDAQJONG   jp;
	char            shcode[6];
	long            dif;
}PK_KOSDAQCHE;
typedef struct _PK_KOSPIUPMST PK_KOSDAQ50MST;
typedef struct _PK_KOSDAQUPMST{ /* KOSDAQ Master          */
	char    id          [1]; /* Data ID 0x05          */
	char    filler1     [1]; /* Filler                */
	short   upcode         ; /* �����ڵ� 1 ~ 160      */
	char    hname      [42]; /* ������                */
	char    filler2     [2]; /* Filler                */
	long    bopen          ; /* ���Ͻð�              */
	long    bhigh          ; /* ���ϰ�              */
	long    blow           ; /* ��������              */
	long    bclose         ; /* �������� ���� .99     */
	long    volume         ; /* ���ϰŷ���(õ��)      */
	char    ff          [1]; /* 0xff                  */
	char    cr          [1]; /* 0x0d                  */
	char    lf          [1]; /* 0x0a                  */
}PK_KOSDAQUPMST;
typedef struct _PK_KOSDAQ1MIN{ /* 1������ */
	char    id          [1]; /* Data id 'O'           */
	char    jgubun      [1]; /* �屸�� 1:���� 3:�ð������� */
	short   index          ; /* �Ϸù�ȣ              */
	long    time           ; /* �ð�  ����:1100000    */
	PK_UPQ  item       [50];
	char    ff          [1]; /* 0xff                  */
	char    cr          [1]; /* 0x0d                  */
	char    lf          [1]; /* 0x0a                  */
}PK_KOSDAQ1MIN;
typedef struct _PK_KOSDAQ501MIN{
	char    id          [1]; /* Data id 'L'           */
	char    jgubun      [1]; /* �屸�� 1:����         */
	short   index          ; /* �Ϸù�ȣ              */
	long    time           ; /* �ð�  ����:1100000    */
	                         /*       ����:2100000    */
	                         /*     �ð���:3100000    */
	PK_UP   item        [1];
	char    ff          [1]; /* 0xff                  */
	char    cr          [1]; /* 0x0d                  */
	char    lf          [1]; /* 0x0a                  */
}PK_KOSDAQ501MIN;


/*
** 2005-05-30 �ű��߰�
*/
typedef struct _PK_KOSDAQJONG2{ /* KOSDAQ ����ü�2     */
	char    id          [1]; /* Data ID 'r'           */
	char    jgubun      [1]; /* filler                */ /* 2005-03-07 ���� (jgubun->filler) */
	short   index          ; /* �Ϸù�ȣ              */
	short   stime          ; /* �ð�(HHMM) 21000:���� */
	char    trgubun     [1]; /* �ŷ���������          */
	char    toojagubun  [1]; /* �������� ����         */
	/* char    rakgubun    [1]; *//* filler                */ /* 2005-03-07 ���� (jgubun->filler) */
	char    chegb       [1]; /* ü�ᱸ�� 1:���� 2:�尳�����ð��� 3:�������Ľð��� 4:�ð��ܴ��ϰ� *//* 2005-05-30 �߰� filler(1) -> chegb(1) */
	char    updown      [1]; /* �������              */
	char    gise        [1]; /* �Ǽ�/�⼼���� 0:�ʱⰪ 1:�⼼ 2:�⼼�ƴ� */ /* 2005-03-07 ���� */
	char    dongsigb    [1]; /* ����ȣ������ 1:���ʵ��� 2:���� 3:�������� 4:�ð������� 5:���ߵ���  */
	long    baseprc        ; /* ���ذ�                */
	long    upprc          ; /* ���Ѱ�                */
	long    dwprc          ; /* ���Ѱ�                */
	long    daebi          ; /* ��� 0:�ʱⰪ 1:�ð��ܴ��ϰ����� 2:�ð��ܴ��ϰ����� *//* 2005-05-30 �߰� */
	long    price          ; /* ���簡                */
	long    open           ; /* �ð�                  */
	long    high           ; /* ��                  */
	long    low            ; /* ����                  */
	long    volume         ; /* �ŷ���                */
	long    amt            ; /* �����ŷ����(õ��)    */
	PK_HOGA hoga[10]       ; /* 10����ȣ��            */
	long    dcheprc        ; /* �Ѹŵ�ȣ���ܷ� -> ����ü�ᰡ(2002-09-30)   */
	long    dcheqty        ; /* �Ѹż�ȣ���ܷ� -> ����ü�����(2002-09-30) */
	long    otmedotot      ; /* �ð��� �� �ŵ��ܷ�    */
	long    otmesutot      ; /* �ð��� �� �ŵ��ܷ�    */
	long    hgmedotot      ; /* 10�ܰ� �ŵ��ܷ��հ�   */
	long    hgmesutot      ; /* 10�ܰ� �ż��ܷ��հ�   */
	long    bfhgmedotot    ; /* �尳�����ð��ܸŵ����ܷ� *//* 2004-02-16 �߰�*/
	long    bfhgmesutot    ; /* �尳�����ð��ܸż����ܷ� *//* 2004-02-16 �߰�*/
	long    ovtmunitmedotot; /* �ð��ܴ��ϰ� 10�ܰ� �Ѹŵ��ܷ� *//* 2005-05-30 �߰� */
	long    ovtmunitmesutot; /* �ð��ܴ��ϰ� 10�ܰ� �Ѹż��ܷ� *//* 2005-05-30 �߰� */
	/* char    baseprccg   [1]; *//* filler                */ /* 2005-03-07 ���� (baseprccg->filler) */
	char    ovtmunithggb[1]; /* �ð��ܴ��ϰ�ȣ������  *//* 2005-05-30 �߰� filler2(1) ->ovtmunithggb(1) */
	char	upprcgb     [1]; /* ���Ѱ����濩��        */
	char    dwprcgb     [1]; /* ���Ѱ����濩��        */
	char    vol_gb      [1]; /* �ܷ�����  0:�ʱⰪ 1:���� 4:�������� �ð��� 5:������� �ð��� *//* 2004-02-16 �߰� */
	long    bfcheprc       ; /* ���߿��� 0, �ð��� �ŷ����� ü�ᰡ������ *//* 2004-02-16 �߰�*/
	char    datagb      [2]; /* DATA�з�              */ /* 2005-03-07 �߰� *//* 01:����ü�ᰡ �����ߴ� 02:����ü�ᰡ �����簳 03:���ذ��������� 04:���ʵ���RANDOM END ���� 05:���ʵ���RANDOM END ���� 06:��������RANDOM END ���� 07:��������RANDOM END ���� 08:���ÿ��� ���� 09:���ÿ��� ���� 10:�ð������� �Ÿ� ���� 11:�ð������� �Ÿ� ���� 12:�尳���� �ð��� ���� 13:������ ����  */
	char    filler1     [2]; /* filler                */ /* 2005-03-07 �߰� */
	long    ovtmunithigh   ; /* �ð��ܴ��ϰ����Ѱ�    */ /* 2005-05-30 �߰� */
	long    ovtmunitlow    ; /* �ð��ܴ��ϰ����Ѱ�    */ /* 2005-05-30 �߰� */
	long    tdclose        ; /* ��������              */ /* 2005-05-30 �߰� */

	char    filler4     [3]; /* filler                */
	char	ovtmupdown  [1]; /* �ð��ܴ��ϰ� �������  1:����,2:���,3:����,4:����,5:�϶� 6:�⼼*/
	long    ovtmdaebi      ; /* �ð��ܴ��ϰ� ��� 0:�ʱⰪ 1:�ð��ܴ��ϰ����� 2:�ð��ܴ��ϰ����� */
	long    ovtmprice      ; /* �ð��ܴ��ϰ� ���簡   */
	long    ovtmopen       ; /* �ð��ܴ��ϰ� �ð�     */
	long    ovtmhigh       ; /* �ð��ܴ��ϰ� ��     */
	long    ovtmlow        ; /* �ð��ܴ��ϰ� ����     */
	long    ovtmvolume     ; /* �ð��ܴ��ϰ� �����ŷ���            */
	long    ovtmamt        ; /* �ð��ܴ��ϰ� �����ŷ����(�鸸)    */

	char    ff          [1]; /* 0xff                  */
	char    cr          [1]; /* 0x0d                  */
	char    lf          [1]; /* 0x0a                  */
}PK_KOSDAQJONG2;


/*****************************************************************************/
/* ����                                                                      */
/*****************************************************************************/

typedef struct _PK_FUTMST{  /* �������� Master */
	char    id          [1]; /* Data ID 'a'           */
	char    filler      [3]; /* Filler                */
	long    index          ; /* �Ϸù�ȣ              */
	char    expcode    [12]; /* ����ǥ���ڵ�          */
	char    hname      [30]; /* �����                */

	char    lastdtgb    [1]; /* �����ŷ��Ͽ��� 1:�ش� 2:���ش� */
	char    baseprcgb   [1]; /* ���ذ����� 1:�������갡 2:���ϱ��ذ� 3:���ϱ��ذ����̷а� 4:���ϱ⼼ 5:���ϱ��ذ����̷а� */

	long    listdt         ; /* ������                */
	long    lastdt         ; /* �����ŷ���            */
	long    baseprc        ; /* ���ذ�                */
	long    upprc          ; /* ���Ѱ�                */
	long    dwprc          ; /* ���Ѱ�                */
	long    bclose         ; /* ��������              */
	long    bvolume        ; /* ���ϰŷ���  (���)    */
	long    bnvolume       ; /* ���ϱٿ���(near)�ŷ���*/
	long    bfvolume       ; /* ���Ͽ�����(far)�ŷ��� */
	long    bvalue1        ; /* ���ϰŷ���� 1(�鸸)  */
	long    bvalue2        ; /* ���ϰŷ���� 2(��)    */
	long    bnvalue1       ; /* ���ϱٿ����ŷ���� 1(�鸸)  */
	long    bnvalue2       ; /* ���ϱٿ����ŷ���� 2(��)    */
	long    bfvalue1       ; /* ���Ͽ������ŷ���� 1(�鸸)  */
	long    bfvalue2       ; /* ���Ͽ������ŷ���� 2(��)    */
	long    bmigyulqty     ; /* ���Ϲ̰�������(Ȯ��ġ)*/
	long    bspreadnjong   ; /* ���Ͻ�������ٿ�������*/
	long    bspreadfjong   ; /* ���Ͻ����������������*/
	char    nearexpcode[12]; /* �ٿ��������ڵ�        */
	char    farexpcode [12]; /* �����������ڵ�        */

	char    ename      [30]; /* ���������            */
	char    shcode      [8]; /* �����ڵ�              */
	char    noname      [4]; /* �����(���������)    */
	char    shname     [15]; /* ���������            */
	char    filler1     [3]; /* filler                */
	short   listdtcnt      ; /* �����ϼ�              */
	short   remaindtcnt    ; /* �����ϼ�              */
	long    futdivid       ; /* ���������̷���ġ    */
	long    theoryprc1     ; /* �̷а�(���갡)        */
	long    theoryprc2     ; /* �̷а�(���ذ�)        */
	long    cdrate         ; /* cd�ݸ� ����:%, ���� 11�ð� ȣ�����ͷ� */
	char    bjungprcgb  [1]; /* �������갡�ݱ���      */
	char    bclosegb    [1]; /* ������������ 1:�Ǽ� 2:�⼼ 3:���ŷ� */
	char    filler2     [2]; /* filler                */
	long    bjungprc       ; /* ���갡��              */
	long    listinghighdt  ; /* ������ �ְ�����       */
	long    listinghighprc ; /* ������ �ְ���       */
	long    listinglowdt   ; /* ������ ��������       */
	long    listinglowprc  ; /* ������ ��������       */
	long    listdt2        ; /* ��ȸ��                */
	char    markryn     [1]; /* ���尡 ��뱸�� [Y:���  N:����] */
	char    condjiryn   [1]; /* ���Ǻ������� ��뱸�� [Y:���  N:����] */
	char    choiyoujiryn[1]; /* ������������ ��뱸�� [Y:���  N:����] */
	char    lastprcgb   [1]; /* ��������������        */
	long    lastprc        ; /* ����������            */
	long    cbup           ; /* C.B. ���Ѱ�           */
	long    cblow          ; /* C.B. ���Ѱ�           */
	long    bstime         ; /* ���������ŸŽð�      */
	long    dealamt        ; /* �ŷ��¼�              *//* �ű��߰� 2012-02-10 */
	long    realupprc      ; /* �ǽð����Ѱ�����      *//* �߰� 2014-09-01 */
	long    realdwprc      ; /* �ǽð����Ѱ�����      *//* �߰� 2014-09-01 */
	char    realupdwgb[1]  ; /* �ǽð��������ѿ���    *//* �߰� 2014-09-01 */
	char    prclimtcd[1]   ; /* ��������Ȯ����������ڵ�*//* 2015-06-15 �߰� */
	short   prclimtlast    ; /* �������������ܰ�      *//* 2015-06-15 �߰� */
	long    prclimt1upprc  ; /* ��������1�ܰ���Ѱ�   *//* 2015-06-15 �߰� */
	long    prclimt1dwprc  ; /* ��������1�ܰ����Ѱ�   *//* 2015-06-15 �߰� */
	long    prclimt2upprc  ; /* ��������2�ܰ���Ѱ�   *//* 2015-06-15 �߰� */
	long    prclimt2dwprc  ; /* ��������2�ܰ����Ѱ�   *//* 2015-06-15 �߰� */
	long    prclimt3upprc  ; /* ��������3�ܰ���Ѱ�   *//* 2015-06-15 �߰� */
	long    prclimt3dwprc  ; /* ��������3�ܰ����Ѱ�   *//* 2015-06-15 �߰� */
	char    filler3[31]    ; /* filler                *//* ���� 2015-06-15 [27->31]*/
	char    ff          [1]; /* 0xff                  */
	char    cr          [1]; /* 0x0d                  */
	char    lf          [1]; /* 0x0a                  */
}PK_FUTMST;

typedef struct _PK_FUTJONG{ /* ���� �ü� */
	char    id          [1]; /* Data ID 'b'               */
	char    filler      [1]; /* Filler                    */
	short   jgubun         ; /* �屸�� 9:Mst��, 1,2,3,4,5 */
	long    index          ; /* ���� �Ϸù�ȣ             */
	long    stime          ; /* �ü��߻��ð�              */
	short   trgubun        ; /* �ŷ�����                  */
	short   gisegb         ; /* �⼼����                  */
	long    cbtime         ; /* C.B �߻��ð�              */
	long    price          ; /* ���簡                    */
	long    nearprice      ; /* �ٿ��� ���� ��������      */
	long    farprice       ; /* ������ ���� ��������      */
	long    open           ; /* �ð�                      */
	long    high           ; /* ��                      */
	long    low            ; /* ����                      */
	long    volume         ; /* �����ŷ���                */
	long    value1         ; /* �����ŷ����1(�鸸)       */
	long    value2         ; /* �����ŷ����2(õ��)       */
	long    nearvolume     ; /* �ٿ��������ŷ���          */
	long    nearvalue1     ; /* �ٿ��������ŷ����1(�鸸) */
	long    nearvalue2     ; /* �ٿ��������ŷ����2(õ��) */
	long    farvolume      ; /* �����������ŷ���          */
	long    farvalue1      ; /* �����������ŷ����1(�鸸) */
	long    farvalue2      ; /* �����������ŷ����2(õ��) */
	PK_OFHOGA hoga[5]      ; /* 5����ȣ��          */
	long    hmedotot       ; /* �ŵ�ȣ�� �� ����          */
	long    hmesutot       ; /* �ż�ȣ�� �� ����          */
	long    hmedototcnt    ; /* �ŵ�ȣ�� �� �Ǽ�          */
	long    hmesutotcnt    ; /* �ż�ȣ�� �� �Ǽ�          */
	long    migyul1        ; /* �̰�����������(��������)  */
	long    migyul2        ; /* �̰�����������(����Ȯ��)  */
	long    realupprc      ; /* �ǽð����Ѱ�              *//* �߰� 2014-09-01 */
	long    realdwprc      ; /* �ǽð����Ѱ�              *//* �߰� 2014-09-01 */
	char    filler3[65]    ; /* filler                    *//* �߰� 2014-09-01 */
	char    ff          [1]; /* 0xff               */
	char    cr          [1]; /* 0x0d               */
	char    lf          [1]; /* 0x0a               */
}PK_FUTJONG;

typedef struct _PK_FUTUPDW{ /* ���� ����������Ȯ��ߵ� */
	char    id         [ 1]; /* Data ID 0x9A              */
	char    infogb     [ 2]; /* ��������                  */
	char    markgb     [ 1]; /* ���屸��                  */
	char    item       [12]; /* �����ڵ�                  */
	char    itmidx     [ 4]; /* �����Ϸù�ȣ              */
	char    stm        [ 8]; /* ����Ȯ��ð�              */
	char    upprstp    [ 2]; /* ��������Ȯ����Ѵܰ�      */
	char    dwprstp    [ 2]; /* ��������Ȯ�����Ѵܰ�      */
	char    upprc      [12]; /* ���Ѱ� X99999999.99       */
	char    dwprc      [12]; /* ���Ѱ� X99999999.99       */
	char    filler     [21]; /* filler                    */
	char    ff          [1]; /* 0xff               */
	char    cr          [1]; /* 0x0d               */
	char    lf          [1]; /* 0x0a               */
}PK_FUTUPDW;


/*****************************************************************************/
/* �ɼ�                                                                      */
/*****************************************************************************/

typedef struct _PK_OPTMST{ /* �ɼ� Master  */
	char    id          [1]; /* Data ID 'c'           */
	char    filler      [3]; /* Filler                */
	long    index          ; /* �Ϸù�ȣ              */
	char    expcode    [12]; /* ����ǥ���ڵ�          */
	char    hname      [30]; /* �����                */
	char    optkind     [1]; /* �ɼ����� 2:CALL, 3:PUT */
	char    hangsagb    [1]; /* �Ǹ�������� 1:���� 2:�̱� 3:��Ÿ */
	long    mangi          ; /* ������              */
	long    actprc         ; /* ��簡��              */
	long    listdt         ; /* ������                */
	long    lastdt         ; /* �����ŷ���            */
	long    baseprc        ; /* ���ذ�                */
	long    upprc          ; /* ���Ѱ�                */
	long    dwprc          ; /* ���Ѱ�                */
	long    bclose         ; /* ��������              */
	long    bmigyulqty     ; /* ���Ϲ̰�������        */
	long    bvolume        ; /* ���ϰŷ���  (���)    */
	long    bvalue1        ; /* ���ϰŷ���� 1(�鸸)  */
	long    bvalue2        ; /* ���ϰŷ���� 2(��)    */
	long    listdt2        ; /* ��ȸ����              */
	char    trstobj     [2]; /* �ŷ�������� '01' kospi200 */
	char    ename      [30]; /* ������                */
	char    shname     [14]; /* ����                */
	short   basisdtcnt     ; /* �����ϼ�              */
	short   remaindtcnt    ; /* �����ϼ�              */
	char    offsetgb    [1]; /* �ٿ������� 1:�ֱٿ��� 2:���ش� 3:�ֿ����� */
	char    atmgb       [1]; /* ATM���� 1:ATM 2:ITM 3:OTM */
	long    startmemedt    ; /* ���ʰŷ���            */
	char    lastmemedtgb[1]; /* �����ŷ��ϱ��� 1:���� 2:�ŷ������� */
	char    newitemgb   [1]; /* �ű�/�߰�/��������    */
	char    bclosegb    [1]; /* ������������ 1:�������� 2:���ϱ⼼ 3:�ŷ����� */
	char    trmarginprcgb[1]; /* �Ÿ����űݱ��ذ����� 1:�������� 2:���ϱ⼼ 3:�������ű� 4:�������ű��̷а� ' ':���ذ�����*/
	long    newitemdt      ; /* �ű�/�߰�/������      */
	long    nowdivid       ; /* �����������簡ġ    */
	long    theoryprc      ; /* �̷а�                */
	long    bopen          ; /* ���Ͻð�              */
	long    bhigh          ; /* ���ϰ�              */
	long    blow           ; /* ��������              */
	long    trmarginprc    ; /* �Ÿ����űݱ��ذ�      */
	long    prcunit        ; /* ���ݴ��� ���ذ� 3.00  */
	short   hogaunit1      ; /* ȣ������ 0.01         */
	short   hogaunit2      ; /* ȣ������ 0.05         */
	long    cdrate         ; /* cd�ݸ� ����:%, ���� 11�ð� ȣ�����ͷ� */
	long    yearhighdt     ; /* ���� �ְ�����         */
	long    yearhighprc    ; /* ���� �ְ���         */
	long    yearlowdt      ; /* ���� ��������         */
	long    yearlowprc     ; /* ���� ��������         */
	long    listinghighdt  ; /* ������ �ְ�����       */
	long    listinghighprc ; /* ������ �ְ���       */
	long    listinglowdt   ; /* ������ ��������       */
	long    listinglowprc  ; /* ������ ��������       */
	char    markryn     [1]; /* ���尡 ��뱸�� [Y:���  N:����] */
	char    condjiryn   [1]; /* ���Ǻ������� ��뱸�� [Y:���  N:����] */
	char    choiyoujiryn[1]; /* ������������ ��뱸�� [Y:���  N:����] */
	char    baseprcgb   [1]; /* ���ذ����� 1:�������ű� 2:���� 3:���� 4:���ϱ⼼ */
	long    interchange    ; /* ���纯���� �Ҽ�3�ڸ�  */
	long    dealamt        ; /* �ŷ��¼�              *//* �ű��߰� 2012-02-10 */
	long    realupprc      ; /* �ǽð����Ѱ�����      *//* �߰� 2014-09-01 */
	long    realdwprc      ; /* �ǽð����Ѱ�����      *//* �߰� 2014-09-01 */
	char    realupdwgb[1]  ; /* �ǽð��������ѿ���    *//* �߰� 2014-09-01 */
	char    prclimtcd[1]   ; /* ��������Ȯ����������ڵ�*//* 2015-06-15 �߰� */
	short   prclimtlast    ; /* �������������ܰ�      *//* 2015-06-15 �߰� */
	long    prclimt1upprc  ; /* ��������1�ܰ���Ѱ�   *//* 2015-06-15 �߰� */
	long    prclimt1dwprc  ; /* ��������1�ܰ����Ѱ�   *//* 2015-06-15 �߰� */
	long    prclimt2upprc  ; /* ��������2�ܰ���Ѱ�   *//* 2015-06-15 �߰� */
	long    prclimt2dwprc  ; /* ��������2�ܰ����Ѱ�   *//* 2015-06-15 �߰� */
	long    prclimt3upprc  ; /* ��������3�ܰ���Ѱ�   *//* 2015-06-15 �߰� */
	long    prclimt3dwprc  ; /* ��������3�ܰ����Ѱ�   *//* 2015-06-15 �߰� */
	char    filler3[13]    ; /* filler                *//* ���� 2015-06-15 [27->13]*/
	char    ff          [1]; /* 0xff               */
	char    cr          [1]; /* 0x0d               */
	char    lf          [1]; /* 0x0a               */
}PK_OPTMST;

typedef struct _PK_OPTJONG{ /* �ɼ� �ü� */
	char    id          [1]; /* Data ID 'd'               */
	char    filler      [1]; /* Filler                    */
	short   jgubun         ; /* �屸�� 9:Mst��, 1,2,3,4,5 */
	long    index          ; /* ���� �Ϸù�ȣ             */
	long    stime          ; /* �ü��߻��ð�              */
	short   trgubun        ; /* �ŷ�����                  */
	short   gisegb         ; /* �⼼����                  */
	long    cbtime         ; /* C.B �߻��ð�              */
	long    price          ; /* ���簡                    */
	long    open           ; /* �ð�                      */
	long    high           ; /* ��                      */
	long    low            ; /* ����                      */
	long    volume         ; /* �����ŷ���                */
	long    value1         ; /* �����ŷ����1(�鸸)       */
	long    value2         ; /* �����ŷ����2(õ��)       */
	PK_OFHOGA hoga[5]      ; /* 5����ȣ��          */
	long    hmedotot       ; /* �ŵ�ȣ�� �� ����          */
	long    hmesutot       ; /* �ż�ȣ�� �� ����          */
	long    hmedototcnt    ; /* �ŵ�ȣ�� �� �Ǽ�          */
	long    hmesutotcnt    ; /* �ż�ȣ�� �� �Ǽ�          */
	long    migyul1        ; /* �̰�����������(��������)  */
	long    migyul2        ; /* �̰�����������(����Ȯ��)  */
	long    realupprc      ; /* �ǽð����Ѱ�����      *//* �߰� 2014-09-01 */
	long    realdwprc      ; /* �ǽð����Ѱ�����      *//* �߰� 2014-09-01 */
	char    filler3[47]    ; /* filler                *//* �߰� 2014-09-01 */
	char    ff          [1]; /* 0xff               */
	char    cr          [1]; /* 0x0d               */
	char    lf          [1]; /* 0x0a               */
}PK_OPTJONG;

typedef struct _PK_OPTUPDW{ /* �ɼ� ����������Ȯ��ߵ� */
	char    id         [ 1]; /* Data ID 0x9B              */
	char    infogb     [ 2]; /* ��������                  */
	char    markgb     [ 1]; /* ���屸��                  */
	char    item       [12]; /* �����ڵ�                  */
	char    itmidx     [ 4]; /* �����Ϸù�ȣ              */
	char    stm        [ 8]; /* ����Ȯ��ð�              */
	char    upprstp    [ 2]; /* ��������Ȯ����Ѵܰ�      */
	char    dwprstp    [ 2]; /* ��������Ȯ�����Ѵܰ�      */
	char    upprc      [12]; /* ���Ѱ� X99999999.99       */
	char    dwprc      [12]; /* ���Ѱ� X99999999.99       */
	char    filler     [21]; /* filler                    */
	char    ff          [1]; /* 0xff               */
	char    cr          [1]; /* 0x0d               */
	char    lf          [1]; /* 0x0a               */
}PK_OPTUPDW;


/*****************************************************************************/
/* _PK_STOPTIONMST (�ֽĿɼ� �⺻ ����Ÿ ����)                               */
/*****************************************************************************/
typedef struct _PK_STOPTIONMST{
	char    id          [1]; /* 01. Data ID 'e'         */
	char    filler      [3]; /* 02. Filler              */
	long    ymd            ; /* 03. ��ȸ����            */
	long    index          ; /* 04. ���� SEQ ��ȣ       */
	char    expcode    [12]; /* 05. �����ڵ� 10:������ 11:������ö 12:�Ｚ���� 13:�ѱ����� 14:SK�ڷ��� 15:�ѱ���� 16: ��������*/
	char    optkind     [1]; /* 06. �ɼ����� 2:CALL, 3:PUT */
	char    trstobj     [2]; /* 07. �ŷ�����ֽ�        */
	char    filler2     [1]; /* 08. Filler              */
	long    mangi          ; /* 09. ������  [yyyymm]  */
	long    actprc1        ; /* 10. ��簡�� �����ι�(8�ڸ�) */
	long    actprc2        ; /* 11. ��簡�� �Ҽ����κ�(8�ڸ�) */
	long    trunit1        ; /* 12. �ŷ����� �����ι�(8�ڸ�) */
	long    trunit2        ; /* 13. �ŷ����� �Ҽ����κ�(8�ڸ�) */
	long    seaseqno       ; /* 14. ��ȸ SEQ NO         */
	char    hname      [50]; /* 15. �ѱ������          */
	char    ename      [50]; /* 16. ���������          */
	char    shname     [25]; /* 17. ��������          */
	char    rigtygb     [1]; /* 18. �Ǹ������������ [1:������ 2:�̱���]*/
	short   listdtcnt      ; /* 19. �����ϼ�            */
	short   surdtcnt       ; /* 20. �����ϼ�            */
	char    nearmonthgb [1]; /* 21. �ֱٿ�������[1:�ֱٿ��� 2:��Ÿ] */
	char    atmgb       [1]; /* 22. ATM ���� [1:ATM 2:ITM 3:OTM]*/
	long    listdt         ; /* 23. ������              */
	long    fristtrdt      ; /* 24. ���ʰŷ���          */
	long    finaltrdt      ; /* 25. �����ŷ���          */
	char    finaltrdtgb [1]; /* 26. �����ŷ��� ���� [1:�ű� 2:�߰� 3:���� 4:���� 5:���� 6:Ư��]*/
	char    shcodelistgb[1]; /* 27. ������屸��        */
	char    filler3     [2]; /* 28. Filler              */
	long    shcodelistdt   ; /* 29. ��������۾���      */
	long    divjisuprc1    ; /* 30. �������� ���簡ġ ���� */
	long    divjisuprc2    ; /* 31. �������� ���簡ġ �Ҽ���(6�ڸ�) */
	long    theprc1        ; /* 32. �̷а� ����         */
	long    theprc2        ; /* 33. �̷а� �Ҽ���(6�ڸ�)*/
	long    bopen          ; /* 34. ���Ͻð�            */
	long    bhigh          ; /* 35. ���ϰ�            */
	long    blow           ; /* 36. ��������            */
	long    bclose         ; /* 37. ��������            */
	long    memgnbprc      ; /* 38. �Ÿ����űݱ��ذ�    */
	char    bclosegb    [1]; /* 39. ������������ [1:�Ǽ� 2:�⼼ 3:�ŷ�����]*/
	char    memgnbprcgb [1]; /* 40. �Ÿ����űݱ��ذ� ���� [1:��������(�Ǽ�) 2:���ϱ⼼(����������) 3:�������űݱ��ذ�(����������) 4:�������ű��̷а�(����������) 5:�����������űݱ��ذ�(����������)]*/
	char    filler4     [2]; /* 41. Filler              */
	long    uplmhgrange    ; /* 42. ����ȣ�� ����(����ġ) */
	long    dnlmhgrange    ; /* 43. ����ȣ�� ����(����ġ) */
	long    cdrate         ; /* 44. CD �ݸ� (�Ҽ��� 3�ڸ�)*/
	long    bmigyulqty     ; /* 45. ���Ϲ̰�����������  */
	long    btrqty         ; /* 46. ���ϰŷ���          */
	long    btrprc1        ; /* 47. ���ϰŷ���� (����: �鸸��) */
	long    btrprc2        ; /* 48. ���ϰŷ���� (����: ��) */
	long    yearhighdt     ; /* 49. ���� �ְ�����       */
	long    yearhighprc    ; /* 50. ���� �ְ���       */
	long    yearlowdt      ; /* 51. ���� ��������       */
	long    yearlowprc     ; /* 52. ���� ��������       */
	long    listinghighdt  ; /* 53. ������ �ְ�����     */
	long    listinghighprc ; /* 54. ������ �ְ���     */
	long    listinglowdt   ; /* 55. ������ ��������     */
	long    listinglowprc  ; /* 56. ������ ��������     */
	char    markryn     [1]; /* 57. ���尡 ��뱸�� [Y:���  N:����] */
	char    condjiryn   [1]; /* 58. ���Ǻ������� ��뱸�� [Y:���  N:����] */
	char    choiyoujiryn[1]; /* 59. ������������ ��뱸�� [Y:���  N:����] */
	char    baseprcgb   [1]; /* 60. ���ذ� ���� [1:���ϱ��ذ����ű� 2:���ϱ��ذ� 3:�����̷а� 4:���ϱ⼼ 5:�����������űݱ��ذ� 6:�������ϱ��ذ� 7:�������ϱ⼼]*/
	long    baseprc        ; /* 61. ���ذ�              */
	long    immanmov       ; /* 62. ���纯���� (�Ҽ��� 3�ڸ�) */
	char    jojunggb    [1]; /* 63. �������� [SPACE :���� 0: �̰������� C: �ŷ��������� */
	char    trstopyn    [1]; /* 64. �ŷ��������� [Y:���  N:����]*/
	char    mechenu     [1]; /* 65. �Ÿ�ü���� [N:����  U:���ϰ�ü��]*/
	char    bassetshcode[12];/* 66. �����ڻ������ڵ�    */
	long    vwactprc        ;/* 67. ��󰡰���ȸ��      */
	char    filler5    [1 ]; /* 67. Filler              */
	char    prclimtcd[1]   ; /* ��������Ȯ����������ڵ�*//* 2015-06-15 �߰� */
	short   prclimtlast    ; /* �������������ܰ�      *//* 2015-06-15 �߰� */
	long    prclimt1upprc  ; /* ��������1�ܰ���Ѱ�   *//* 2015-06-15 �߰� */
	long    prclimt1dwprc  ; /* ��������1�ܰ����Ѱ�   *//* 2015-06-15 �߰� */
	long    prclimt2upprc  ; /* ��������2�ܰ���Ѱ�   *//* 2015-06-15 �߰� */
	long    prclimt2dwprc  ; /* ��������2�ܰ����Ѱ�   *//* 2015-06-15 �߰� */
	long    prclimt3upprc  ; /* ��������3�ܰ���Ѱ�   *//* 2015-06-15 �߰� */
	long    prclimt3dwprc  ; /* ��������3�ܰ����Ѱ�   *//* 2015-06-15 �߰� */
	char    filler6    [34]; /* 67. Filler              */
	char    ff          [1]; /* 0xff                    */
	char    cr          [1]; /* 0x0d                    */
	char    lf          [1]; /* 0x0a                    */
}PK_STOPTIONMST;

/*****************************************************************************/
/* _PK_STOPTIONJONG (�ֽĿɼ� �ü�)                                          */
/*****************************************************************************/
typedef struct _PK_STOPTIONJONG{
	char    id          [1]; /* Data ID 'f'               */
	char    filler      [1]; /* Filler                    */
	short   jgubun         ; /* �屸�� 9:Mst��, 1,5 �帶��*/
	long    index          ; /* ���� �Ϸù�ȣ             */
	long    stime          ; /* �ü��߻��ð�              */
	short   trgubun        ; /* �ŷ�����                  */
	short   gisegb         ; /* �⼼����                  */
	long    cbtime         ; /* C.B �߻��ð�              */
	long    price          ; /* ���簡                    */
	long    open           ; /* �ð�                      */
	long    high           ; /* ��                      */
	long    low            ; /* ����                      */
	long    volume         ; /* �����ŷ���                */
	long    value1         ; /* �����ŷ����1(�鸸)       */
	long    value2         ; /* �����ŷ����2(õ��)       */
	PK_OFHOGA hoga[5]      ; /* 5����ȣ��          */
	long    hmedotot       ; /* �ŵ�ȣ�� �� ����          */
	long    hmesutot       ; /* �ż�ȣ�� �� ����          */
	long    hmedototcnt    ; /* �ŵ�ȣ�� �� �Ǽ�          */
	long    hmesutotcnt    ; /* �ż�ȣ�� �� �Ǽ�          */
	long    migyul1        ; /* �̰�����������(��������)  */
	long    migyul2        ; /* �̰�����������(����Ȯ��)  */
	long    memgnbprc      ; /* �Ÿ����űݱ��ذ�          */
	long    actgyulprc1    ; /* ���������� �����ι�(8�ڸ�) */
	long    actgyulprc2    ; /* ���������� �Ҽ����κ�(8�ڸ�) */
	char    memgnbprcgb [1]; /* �Ÿ����űݱ��ذ� ���� [1:��������(�Ǽ�) 2:���ϱ⼼(����������) 3:�������űݱ��ذ�(����������) 4:�������ű��̷а�(����������) 5:�����������űݱ��ذ�(����������)]*/
	char    actgyulgb   [1]; /* ���������� ����     [1:����ڻ��Ѱ� 2:����ڻ��������� 3:SQ 4:�������� 5:�ֱ��������� 6:�ֱ����� ��������] */
	char    ff          [1]; /* 0xff               */
	char    cr          [1]; /* 0x0d               */
	char    lf          [1]; /* 0x0a               */
}PK_STOPTIONJONG;

typedef struct _PK_STOPUPDW{ /* �����ֽĿɼ� ����������Ȯ��ߵ� */
	char    id         [ 1]; /* Data ID 0x9D              */
	char    infogb     [ 2]; /* ��������                  */
	char    markgb     [ 1]; /* ���屸��                  */
	char    item       [12]; /* �����ڵ�                  */
	char    itmidx     [ 4]; /* �����Ϸù�ȣ              */
	char    stm        [ 8]; /* ����Ȯ��ð�              */
	char    upprstp    [ 2]; /* ��������Ȯ����Ѵܰ�      */
	char    dwprstp    [ 2]; /* ��������Ȯ�����Ѵܰ�      */
	char    upprc      [12]; /* ���Ѱ� X99999999.99       */
	char    dwprc      [12]; /* ���Ѱ� X99999999.99       */
	char    filler     [21]; /* filler                    */
	char    ff          [1]; /* 0xff               */
	char    cr          [1]; /* 0x0d               */
	char    lf          [1]; /* 0x0a               */
}PK_STOPUPDW;

/*****************************************************************************/
/* ����                                                                      */
/*****************************************************************************/
typedef struct _HEADERNOTICE{
	char    id          [1]; /* DATA ID 0x98          */
	char    gubun       [2]; /* ������  Data �� ID    */
	char	filler      [1];
	long    size           ; /* ���۰Ǽ� or 1         */
	char    tail        [3]; /* 0xff, 0xod, 0x0a      */
}HEADERNOTICE;
typedef struct _FOOTERNOTICE{
	char    id          [1]; /* DATA ID 0x98          */
	char    gubun       [2]; /* ������  Data �� ID    */
	char	filler      [1];
	long    size           ; /* ����                  */
	char    tail        [3]; /* 0xff, 0xod, 0x0a      */
}FOOTERNOTICE;

/*****************************************************************************/
/* _PK_KOSPINOTICE (�峻����)                                                */
/*****************************************************************************/
typedef struct _PK_KOSPINOTICE{
	char    id          [2]; /* Data ID ����REAL("G1") ���ù�ġ("G2") */
	char    ymd         [8]; /* ���� YYYYMMDD      */
	char    seq         [4]; /* �Ϸù�ȣ           */
	char    category    [2]; /* �з�               */
	                         /* ����(01) ����(02) ����ȳ�(03) ������ġ(04) */
	                         /* ������������(05) ����������������(06)       */
	                         /* ��Ÿ�ȳ�(07) ��ܰ���(08) �������� ����(09) */
	char    procgb      [1]; /* ó������ ����(1) ����(2) ���(3) */
	char    code       [12]; /* �����ڵ�           */
	char    gb1         [2]; /* ��з�             */
	char    gb2         [2]; /* �ߺз�             */
	char    gb3         [3]; /* �Һз�             */
	char    page        [3]; /* ��������ȣ         */
	char    line        [2]; /* �������           */
	char    text      [132]; /* ���� TITLE(00) ����(01-29) END(99) */
	char    ff          [1]; /* 0xff               */
	char    cr          [1]; /* 0x0d               */
	char    lf          [1]; /* 0x0a               */
}PK_KOSPINOTICE;

/*****************************************************************************/
/* PK_KOSDAQNOTICE (�ڽ��ڰ���)                                              */
/*****************************************************************************/
typedef struct _PK_KOSDAQNOTICE{
	char    id          [2]; /* Data ID ����REAL("OG") ���ù�ġ("ON") */
	char    seq         [6]; /* �Ϸù�ȣ           */
	char    ymd         [8]; /* ���� YYYYMMDD      */
	char    code       [12]; /* �����ڵ�           */
	char    procgb      [1]; /* ó������ ����(1) ����(2) ���(3) */
	char    gb          [3]; /* ����               */
	char    lang        [1]; /* ������������ ����(1) ����(2) */
	char    page        [3]; /* ��������ȣ         */
	char    line        [2]; /* �������           */
	char    text      [132]; /* ���� TITLE(00) ����(01-29) END(99) */
	char    ff          [1]; /* 0xff               */
	char    cr          [1]; /* 0x0d               */
	char    lf          [1]; /* 0x0a               */
}PK_KOSDAQNOTICE;


/*****************************************************************************/
/* PK_KOSDAQETFNAV (�ڽ��� ETF-NAV)     [2003-04-28 �߰�]                    */
/*****************************************************************************/
typedef struct _PK_KOSDAQETFNAV{
	char    id          [1]; /* 'Q'                */
	char    filler1     [1]; /* filler             */
	char    code       [12]; /* ETF �����ڵ�       */
	char    time        [6]; /* �ð�(HHMMSS) �������:"JSAMOO", ����NAV��:"ENDNAV" */
	char    filler2     [1]; /* filler             */
	char    bnav        [9]; /* ����NAV  9999999V99   */
	char    nav         [9]; /* ����/���� NAV  9999999V99   */
	char    erryulper   [1]; /* ������������ȣ     */
	char    erryul      [9]; /* ����������         */
	char    disyulper   [1]; /* ��������ȣ         */
	char    disyul      [9]; /* ������             */
	char    ff          [1]; /* 0xff               */
	char    cr          [1]; /* 0x0d               */
	char    lf          [1]; /* 0x0a               */
}PK_KOSDAQETFNAV;


/*****************************************************************************/
/* PK_KOSDAQETFPDF (�ڽ��� ETF-PDF)       [2003-04-28 �߰�]                  */
/*****************************************************************************/
typedef struct _PK_KOSDAQETFPDF{
	char    id          [1]; /* 'R'                */
	char    filler1     [1]; /* filler             */
	char    index       [6]; /* �����Ϸù�ȣ       */
	char    ymd         [8]; /* �������� (YYYYMMDD)*/
	char    sutakno     [3]; /* �繫��Źȸ��ȣ     */
	char    code       [12]; /* ETF �ڵ�           */
	char    etfjongcnt  [4]; /* ���������         */
	char    etfjongcode[12]; /* ���������ڵ�       */
	char    icuunitcnt [10]; /* ICU���� ���ǻ�     */
	char    filler2    [62]; /* filler             */
	char    ff          [1]; /* 0xff               */
	char    cr          [1]; /* 0x0d               */
	char    lf          [1]; /* 0x0a               */
}PK_KOSDAQETFPDF;


/*****************************************************************************/
/* PK_ELWMST ELW ���񸶽���                                                  */
/*****************************************************************************/
typedef struct _PK_ELWMST{
	char    id             [1 ]; /*A FRAME_ID '0x71'         */
	char    filler1        [3 ]; /*A FILLER                  */
	long    index              ; /*B �ڵ��Ϸù�ȣ            */
	char    shcode         [10]; /*A �����ڵ�                */
	char    expcode        [12]; /*A ���ڵ�                  */
	char    hname          [40]; /*A �����                  */
	char    ename          [40]; /*A �����(����)            */
	char    cpygb          [2 ]; /*A �ҼӺ� ����             */
	long    faceval            ; /*B �׸鰡                  */
	long    baseprc            ; /*B ���ذ�                  */
	long    bopen              ; /*B ���� �ð�               */
	long    bhigh              ; /*B ���� ��               */
	long    blow               ; /*B ���� ����               */
	long    bclose             ; /*B ���� ����               */
	long    bvolume            ; /*B ���� �ŷ���             */
	long    bamt               ; /*B ���� �ŷ����           */
	long    upprc              ; /*B ���Ѱ�                  */
	long    dwprc              ; /*B ���Ѱ�                  */
	long    trdunit            ; /*B �Ÿż�������            */
	long    capital            ; /*B �ں���                  */
	long    listcnt            ; /*B �����ֽļ�              */
	short   elw_lp1            ; /*B LP-ȸ����ȣ-1           */
	short   elw_lp2            ; /*B LP-ȸ����ȣ-2           */
	short   elw_lp3            ; /*B LP-ȸ����ȣ-3           */
	short   elw_lp4            ; /*B LP-ȸ����ȣ-4           */
	short   elw_lp5            ; /*B LP-ȸ����ȣ-5           */
	short   elw_lp6            ; /*B LP-ȸ����ȣ-6           */
	short   elw_lp7            ; /*B LP-ȸ����ȣ-7           */
	short   elw_lp8            ; /*B LP-ȸ����ȣ-8           */
	short   elw_lp9            ; /*B LP-ȸ����ȣ-9           */
	short   elw_lp10           ; /*B LP-ȸ����ȣ-10          */
	char    elw_isshnm     [40]; /*A ELW �ѱ۹�������      */
	char    elw_issenm     [40]; /*A ELW ������������      */
	char    elw_cd         [12]; /*A ELW �������ڵ�        */
	char    elw_baseamt1   [12]; /*A ELW �����ڻ�1           */
	char    elw_baseamt2   [12]; /*A ELW �����ڻ�2           */
	char    elw_baseamt3   [12]; /*A ELW �����ڻ�3           */
	char    elw_baseamt4   [12]; /*A ELW �����ڻ�4           */
	char    elw_baseamt5   [12]; /*A ELW �����ڻ�5           */
	long    elw_baseamtrt1     ; /*B ELW �����ڻ걸������-1  */
	long    elw_baseamtrt2     ; /*B ELW �����ڻ걸������-2  */
	long    elw_baseamtrt3     ; /*B ELW �����ڻ걸������-3  */
	long    elw_baseamtrt4     ; /*B ELW �����ڻ걸������-4  */
	long    elw_baseamtrt5     ; /*B ELW �����ڻ걸������-5  */
	long    elw_baseamtprc1    ; /*B ELW ���ʰ���(������)    */
	long    elw_baseamtprc2    ; /*B ELW ���ʰ���(�Ҽ���)    */
	long    elw_actprc1        ; /*B ELW ��簡��(������)    */
	long    elw_actprc2        ; /*B ELW ��簡��(�Ҽ���)    */
	char    elw_hangsagb   [2 ]; /*A ELW �Ǹ�����            */
	char    elw_hangsagb1  [2 ]; /*A ELW �Ǹ������        */
	char    elw_hangsainfo[100]; /*A ELW �Ǹ�����            */
	char    elw_settle     [2 ]; /*A ELW �������            */
	char    filler2        [2 ]; /*A filler                  */
	long    elw_fintrddt       ; /*B ELW �����ŷ���          */
	long    elw_chgrt1         ; /*B ELW ��ȯ����(������)    */
	long    elw_chgrt2         ; /*B ELW ��ȯ����(�Ҽ���)    */
	long    elw_prcuprt        ; /*B ELW ���ݻ��������      */
	long    elw_remrt          ; /*B ELW ������              */
	long    elw_supdt          ; /*B ELW ������              */
	char    elw_suppro     [20]; /*A ELW ���޴븮��          */
	char    elw_mangiprc  [100]; /*A ELW �����򰡰��ݹ��    */
	char    elw_tujajigb   [2 ]; /*A ELW ������ǥ���⿩��    */
	char    elw_lpposgb    [2 ]; /*A LP�ֹ����ɿ���          */
	long    listdt             ; /*B ������                  */
	long    lpminhogaqty       ; /*B LP�ּ�ȣ���������      */
	long    lpposqty           ; /*B LP ��������             */
	char    kospi_gb       [2 ]; /*A KOSPI����               */
	char    trgubun2       [2 ]; /*A �ŷ���������            */
	char    basetrswh      [3 ]; /*A �ڻ������ȭ            */
	char    filler3        [1 ]; /*A filler                  */
	long    elw_sp             ; /*B ��������                */
	char    filler4        [ 5]; /*A filler                  */
	char    ff             [ 1]; /* 0xff                     */
	char    cr             [ 1]; /* 0x0d                     */
	char    lf             [ 1]; /* 0x0a                     */
}PK_ELWMST;

typedef struct _PK_ELWJONG{
	char    id          [1]; /* ü�ᡮ0x74��, ȣ����0x75�� lp ȣ����0x76�� */
	char    filler1     [2]; /*A FILLER                  */
	char    vol_gb      [1]; /* �ܷ�����  0:���� 1:�������Ľð��� 2:�尳�����ð��� 3:�ð��ܴ��ϰ�����*//* 2005-05-30 �����߰� */
	long    index          ; /* �Ϸù�ȣ              */
	char    stime       [6]; /* �������۽ð�          */
	char    updown      [1]; /* �������              */
	char    dongsigb    [1]; /* ���ñ���  0:����, 1:����, 2:���ÿ��� */
	long    daebi          ; /* ���                  */
	long    price          ; /* ���簡                */
	long    cheqty         ; /* �ŷ���                */
	long    open           ; /* �ð�                  */
	long    high           ; /* ��                  */
	long    low            ; /* ����                  */
	long    volume         ; /* �����ŷ���            */
	long    amt            ; /* �����ŷ����(�鸸)    */
	PK_ELWHOGA hoga[10]    ; /* 10����ȣ��            */
	long    hgmedotot      ; /* 10�ܰ� �ŵ��ܷ��հ�   */
	long    hgmesutot      ; /* 10�ܰ� �ż��ܷ��հ�   */
	long    lphgmedotot    ; /* LP �ŵ��ܷ��հ�       */
	long    lphgmesutot    ; /* LP �ż��ܷ��հ�       */
	char    finmemegb   [1]; /* �����ŵ��ż������ڵ� 1:�ŵ� 2:�ż� */
	char    ff          [1]; /* 0xff                  */
	char    cr          [1]; /* 0x0d                  */
	char    lf          [1]; /* 0x0a                  */
}PK_ELWJONG;

typedef struct _PK_ELWCHE{
	PK_ELWJONG   jp;
	char            shcode[6];
	long            dif;
}PK_ELWCHE;

/*****************************************************************************/
/* PK_STFUMST �����ֽļ��� ���񸶽���                                        */
/*****************************************************************************/
typedef struct _PK_STFUMST{
	char    id             [1 ]; /*A[1 ] FRAME_ID                 */
	char    filler         [3 ]; /*A[1 ] FILLER                   */
	long    index              ; /*B[4 ] �ڵ��Ϸù�ȣ             */
	char    shcode         [8 ]; /*A[8 ] �����ڵ�(�����ڵ�)       */
	char    expcode        [12]; /*A[12] ���ڵ�                   */
	char    hname          [50]; /*A[50] �����                   */
	char    ename          [50]; /*A[50] �����(����)             */
	char    sht_hname      [25]; /*A[25] ��������               */
	char    sht_shcode     [4 ]; /*A[4 ] �������� �����ڵ�        */
	char    offsetgb       [1 ]; /*A[1 ] �ֱ� ���� ����           */
	char    filler2        [2 ]; /*A[1 ] filler                   */
	long    listdt             ; /*B[4 ] ������                   */
	short   listdtcnt          ; /*B[2 ] �����ϼ�                 */
	short   remaindtcnt        ; /*B[2 ] �����ϼ�                 */
	long    finaltrdt          ; /*B[4 ] �����ŷ���               */
	char    finaltrdtgb    [1 ]; /*A[1 ] �����ŷ��Ͽ���           */
	char    trmarginprcgb  [1 ]; /*A[1 ] ���ذ��ݱ���             */
	char    bjungprcgb     [1 ]; /*A[1 ] �������갡�ݱ���         */
	char    bclosegb       [1 ]; /*A[1 ] ������������             */
	long    futdivid1          ; /*B[4 ] ���������̷���ġ1      */
	long    futdivid2          ; /*B[4 ] ���������̷���ġ2      */
	long    baseprc            ; /*B[4 ] ���ذ���                 */
	long    jungsanprc1        ; /*B[4 ] �̷а���(���갡)1        */
	long    jungsanprc2        ; /*B[4 ] �̷а���(���갡)2        */
	long    theoryprc1         ; /*B[4 ] �̷а���(���ذ�)1        */
	long    theoryprc2         ; /*B[4 ] �̷а���(���ذ�)2        */
	long    cdrate             ; /*B[4 ] CD�ݸ�                   */
	long    upprc              ; /*B[4 ] ���Ѱ�                   */
	long    dwprc              ; /*B[4 ] ���Ѱ�                   */
	long    bfjungsanprc1      ; /*B[4 ] �������갡��1            */
	long    bfjungsanprc2      ; /*B[4 ] �������갡��2            */
	long    bclose             ; /*B[4 ] ��������                 */
	long    bvolume            ; /*B[4 ] ����ü�����             */
	long    lst_nearby_volume  ; /*B[4 ] ���� �ٿ��� ü�����     */
	long    lst_far_volume     ; /*B[4 ] ���� ������ ü�����     */
	long    bvalue             ; /*B[4 ] ����ü����             */
	long    lst_nearby_value   ; /*B[4 ] ���� �ٿ��� ü����     */
	long    lst_far_value      ; /*B[4 ] ���� ������ ü����     */
	long    bmigyulqty         ; /*B[4 ] ���Ϲ̰�����������       */
	long    listinghighdt      ; /*B[4 ] �������ְ�����         */
	long    listinghighprc     ; /*B[4 ] �������ְ�             */
	long    listinglowdt       ; /*B[4 ] ����������������         */
	long    listinglowprc      ; /*B[4 ] ������������             */
	char    markryn        [1 ]; /*A[1 ] ���尡��뱸��           */
	char    condjiryn      [1 ]; /*A[1 ] ���Ǻ� ������ ��� ����  */
	char    choiyoujiryn   [1 ]; /*A[1 ] ������ ������ ��� ����  */
	char    lastprcgb      [1 ]; /*A[1 ] ��������������           */
	long    lastprc1           ; /*B[4 ] ������������1            */
	long    lastprc2           ; /*B[4 ] ������������2            */
	long    cbup               ; /*B[4 ] C.B ���� ���Ѱ�          */
	long    cblow              ; /*B[4 ] C.B ���� ���Ѱ�          */
	long    bspreadnjong       ; /*B[4 ] ���� �������� �ٿ��� ����*/
	long    bspreadfjong       ; /*B[4 ] ���� �������� ������ ����*/
	char    bspreadnshcode [12]; /*A[12] �������� �ٿ��� ǥ���ڵ� */
	char    bspreadfshcode [12]; /*A[12] �������� ���ﹰ ǥ���ڵ� */
	long    trunit1            ; /*B[4 ] �ŷ�����1(�����¼�)      */
	long    trunit2            ; /*B[4 ] �ŷ�����2(�����¼�)      */
	char    market_code_gb [1 ]; /*A[1 ] �����������񿩺�         */
	char    adj_gb         [1 ]; /*A[1 ] ��������                 */
	char    stop_gb        [1 ]; /*A[1 ] �ŷ���������             */
	char    index_method   [1 ]; /*A[1 ] �������                 */
	char    maemae         [1 ]; /*A[1 ] �Ÿ�ü����             */
	char    bassetshcode   [12]; /*A[12] �����ڻ� �����ڵ�        */
	char    prd_gb         [2 ]; /*A[2 ] ��ǰ��                   */
	char    filler3        [1 ]; /*A[4 ] filler                   */
	long    offset_rate        ; /*B[4 ] offset_rate              */
	long    realupprc          ; /* �ǽð����Ѱ�����              *//* �߰� 2014-09-01 */
	long    realdwprc          ; /* �ǽð����Ѱ�����              *//* �߰� 2014-09-01 */
	char    realupdwgb     [1 ]; /* �ǽð��������ѿ���            *//* �߰� 2014-09-01 */
	char    prclimtcd[1]   ; /* ��������Ȯ����������ڵ�*//* 2015-06-15 �߰� */
	short   prclimtlast    ; /* �������������ܰ�      *//* 2015-06-15 �߰� */
	long    prclimt1upprc  ; /* ��������1�ܰ���Ѱ�   *//* 2015-06-15 �߰� */
	long    prclimt1dwprc  ; /* ��������1�ܰ����Ѱ�   *//* 2015-06-15 �߰� */
	long    prclimt2upprc  ; /* ��������2�ܰ���Ѱ�   *//* 2015-06-15 �߰� */
	long    prclimt2dwprc  ; /* ��������2�ܰ����Ѱ�   *//* 2015-06-15 �߰� */
	long    prclimt3upprc  ; /* ��������3�ܰ���Ѱ�   *//* 2015-06-15 �߰� */
	long    prclimt3dwprc  ; /* ��������3�ܰ����Ѱ�   *//* 2015-06-15 �߰� */
	char    filler4        [5 ];  /*A[1 ] filler                   */
	char    ff             [1 ]; /*A[1 ] FF                       */
	char    cr             [1 ]; /*A[1 ] CR                       */
	char    lf             [1 ]; /*A[1 ] LF                       */
}PK_STFUMST;

typedef struct _PK_STFUJONG{
	char    id              [1]; /* ü��'0x82' ȣ����0x83��       */
	char    filler          [1]; /* Filler                        */
	short   jgubun             ; /* �屸�� 9:Mst��, 1,2,3,4,5     */
	long    index              ; /* ���� �Ϸù�ȣ                 */
	long    stime              ; /* �ü��߻��ð�                  */
	long    gisegb             ; /* �⼼����                      */
	long    cbtime             ; /* C.B �߻��ð�                  */
	long    price              ; /* ���簡                        */
	long    nearprice          ; /* �ٿ��� ���� ��������          */
	long    farprice           ; /* ������ ���� ��������          */
	long    open               ; /* �ð�                          */
	long    high               ; /* ��                          */
	long    low                ; /* ����                          */
	long    volume             ; /* �����ŷ���                    */
	long    value1             ; /* �����ŷ����1(�鸸)           */
	long    value2             ; /* �����ŷ����2(õ��)           */
	long    nearvolume         ; /* �ٿ��������ŷ���              */
	long    nearvalue1         ; /* �ٿ��������ŷ����1(�鸸)     */
	long    nearvalue2         ; /* �ٿ��������ŷ����2(õ��)     */
	long    farvolume          ; /* �����������ŷ���              */
	long    farvalue1          ; /* �����������ŷ����1(�鸸)     */
	long    farvalue2          ; /* �����������ŷ����2(õ��)     */
	PK_OFHOGA hoga[5]          ; /* 5����ȣ��                     */
	long    hmedotot           ; /* �ŵ�ȣ�� �� ����              */
	long    hmesutot           ; /* �ż�ȣ�� �� ����              */
	long    hmedototcnt        ; /* �ŵ�ȣ�� �� �Ǽ�              */
	long    hmesutotcnt        ; /* �ż�ȣ�� �� �Ǽ�              */
	long    migyul1            ; /* �̰�����������(��������)      */
	long    migyul2            ; /* �̰�����������(����Ȯ��)      */
	long    realupprc          ; /* �ǽð����Ѱ�                  *//* �߰� 2014-09-01 */
	long    realdwprc          ; /* �ǽð����Ѱ�                  *//* �߰� 2014-09-01 */
	char    filler9        [65]; /*A[65] filler                   */
	char    ff              [1]; /* 0xff                          */
	char    cr              [1]; /* 0x0d                          */
	char    lf              [1]; /* 0x0a                          */
}PK_STFUJONG;

typedef struct _PK_STFUPDW{ /* �����ֽļ��� ����������Ȯ��ߵ� */
	char    id         [ 1]; /* Data ID 0x9C              */
	char    infogb     [ 2]; /* ��������                  */
	char    markgb     [ 1]; /* ���屸��                  */
	char    item       [12]; /* �����ڵ�                  */
	char    itmidx     [ 4]; /* �����Ϸù�ȣ              */
	char    stm        [ 8]; /* ����Ȯ��ð�              */
	char    upprstp    [ 2]; /* ��������Ȯ����Ѵܰ�      */
	char    dwprstp    [ 2]; /* ��������Ȯ�����Ѵܰ�      */
	char    upprc      [12]; /* ���Ѱ� X99999999.99       */
	char    dwprc      [12]; /* ���Ѱ� X99999999.99       */
	char    filler     [21]; /* filler                    */
	char    ff          [1]; /* 0xff               */
	char    cr          [1]; /* 0x0d               */
	char    lf          [1]; /* 0x0a               */
}PK_STFUPDW;

/*****************************************************************************/
/* PK_MKFUMST ��ǰ���� ���񸶽���                                            */
/*****************************************************************************/
typedef struct _PK_MKFUMST{
	char    id             [1 ]; /*A[1 ] FRAME_ID                 */
	char    filler         [3 ]; /*A[1 ] FILLER                   */
	long    index              ; /*B[4 ] �ڵ��Ϸù�ȣ             */
	char    shcode         [8 ]; /*A[8 ] �����ڵ�(�����ڵ�)       */
	char    expcode        [12]; /*A[12] ���ڵ�                   */
	char    hname          [80]; /*A[80] �����                   */
	char    sht_hname      [40]; /*A[40] ��������               */
	char    ename          [80]; /*A[80] �����(����)             */
	char    sht_ename      [40]; /*A[40] ��������(����)         */
	long    listdt             ; /*B[4 ] ������                   */
	long    lastdt             ; /*B[4 ] ������                   */
	long    upprc              ; /*B[4 ] ���Ѱ�                   */
	long    dwprc              ; /*B[4 ] ���Ѱ�                   */
	long    baseprc            ; /*B[4 ] ���ذ���                 */
	char    bspreadnshcode [12]; /*A[12] �������� �ٿ��� ǥ���ڵ� */
	char    bspreadfshcode [12]; /*A[12] �������� ���ﹰ ǥ���ڵ� */
	long    finaltrdt          ; /*B[4 ] �����ŷ�����             */
	long    settledt           ; /*B[4 ] ������������             */
	char    offsetgb       [1 ]; /*A[1 ] �ٿ�������               *//*0:�ش����, 1:�ֱٿ��� */
	char    trmarginprcgb  [1 ]; /*A[1 ] ���ذ��ݱ���             *//*0:�ش����, 1:�Ǽ�, 2:�⼼, 3:�̷а�, 4:����ڻ�����*/
	char    finaltrdtgb    [1 ]; /*A[1 ] �����ŷ��Ͽ���           */
	char    filler2        [1 ]; /*A[1 ] filler                   */
	long    trunit1            ; /*B[4 ] �ŷ�����1(������)        */
	long    trunit2            ; /*B[4 ] �ŷ�����2(�Ҽ���)        */
	long    dealamt1           ; /*B[4 ] �ŷ��¼�1(������)        */
	long    dealamt2           ; /*B[4 ] �ŷ��¼�2(�Ҽ���)        */
	long    remaindtcnt        ; /*B[4 ] �����ϼ�                 */
	long    theoryprc1         ; /*B[4 ] �����̷а���             */
	long    theoryprc2         ; /*B[4 ] �����̷а���             */
	long    bfjungsanprc       ; /*B[4 ] �������갡��             */
	long    bclose             ; /*B[4 ] ��������                 */
	long    bopen              ; /*B[4 ] ���Ͻð�                 */
	long    bhigh              ; /*B[4 ] ���ϰ�                 */
	long    blow               ; /*B[4 ] ��������                 */
	long    bmigyulqty         ; /*B[4 ] ���Ϲ̰�����������       */
	long    interchange        ; /*B[4 ] ���纯����               */
	long    listinghighprc     ; /*B[4 ] �������ְ�             */
	long    listinglowprc      ; /*B[4 ] ������������             */
	long    yearhighprc        ; /*B[4 ] �����ְ�               */
	long    yearlowprc         ; /*B[4 ] ����������               */
	long    listinghighdt      ; /*B[4 ] �������ְ�����         */
	long    listinglowdt       ; /*B[4 ] ����������������         */
	long    yearhighdt         ; /*B[4 ] �����ְ�����           */
	long    yearlowdt          ; /*B[4 ] ��������������           */
	long    bvolume            ; /*B[4 ] ����ü�����             */
	long    bvalue             ; /*B[4 ] ����ü����             */
	long    cdrate             ; /*B[4 ] CD�ݸ�                   */
	long    realupprc          ; /* �ǽð����Ѱ�����              *//* �߰� 2014-09-01 */
	long    realdwprc          ; /* �ǽð����Ѱ�����              *//* �߰� 2014-09-01 */
	char    realupdwgb[1]      ; /* �ǽð��������ѿ���            *//* �߰� 2014-09-01 */
	char    filler9        [64]; /*A[69] filler                   */
	char    ff             [1 ]; /*A[1 ] FF                       */
	char    cr             [1 ]; /*A[1 ] CR                       */
	char    lf             [1 ]; /*A[1 ] LF                       */
}PK_MKFUMST;

typedef struct _PK_MKFUJONG{
	char    id              [1]; /* ü��'0x86' ȣ����0x87���帶��'0x88' */
	char    filler          [1]; /* Filler                        */
	short   jgubun             ; /* �屸��                        *//* 0:����, 5:������, 9:�帶��(���񸶰�) */
	long    index              ; /* ���� �Ϸù�ȣ                 */
	char    expcode        [12]; /* ǥ���ڵ�                      */
	long    stime              ; /* �ü��߻��ð�                  */
	long    gisegb             ; /* �⼼����                      */
	long    price              ; /* ���簡                        */
	long    cheqty             ; /* ü�����                      */
	long    nearprice          ; /* �ٿ��� ���� ��������          */
	long    farprice           ; /* ������ ���� ��������          */
	long    open               ; /* �ð�                          */
	long    high               ; /* ��                          */
	long    low                ; /* ����                          */
	long    volume             ; /* �����ŷ���                    */
	long    value1             ; /* �����ŷ����                  */
	long    value2             ; /* �����ŷ����                  */
	long    nearvolume         ; /* �ٿ��������ŷ���              */
	long    nearvalue1         ; /* �ٿ��������ŷ����1(�鸸)     */
	long    nearvalue2         ; /* �ٿ��������ŷ����2(õ��)     */
	long    farvolume          ; /* �����������ŷ���              */
	long    farvalue1          ; /* �����������ŷ����1(�鸸)     */
	long    farvalue2          ; /* �����������ŷ����2(õ��)     */
	PK_OFHOGA hoga[5]          ; /* 5����ȣ��                     */
	long    hmedotot           ; /* �ŵ�ȣ�� �� ����              */
	long    hmesutot           ; /* �ż�ȣ�� �� ����              */
	long    hmedototcnt        ; /* �ŵ�ȣ�� �� �Ǽ�              */
	long    hmesutotcnt        ; /* �ż�ȣ�� �� �Ǽ�              */
	long    migyul             ; /* �̰�����������(��������)      */
	long    realupprc          ; /* �ǽð����Ѱ�                  *//* �߰� 2014-09-01 */
	long    realdwprc          ; /* �ǽð����Ѱ�                  *//* �߰� 2014-09-01 */
	char    filler9        [57]; /*A[5] filler                    */
	char    ff              [1]; /* 0xff                          */
	char    cr              [1]; /* 0x0d                          */
	char    lf              [1]; /* 0x0a                          */
}PK_MKFUJONG;


typedef struct _PK_MKFUJUNGPRC{
	char    id              [1]; /* FRAME_ID '0x89'               */
	char    filler          [3]; /* Filler                        */
	long    index              ; /* ���� �Ϸù�ȣ                 */
	char    expcode        [12]; /* ǥ���ڵ�                      */
	long    jungprc            ; /*B[4 ] ���갡��(������)         */
	long    settleprc          ; /*B[4 ] ������������(������)     */
	char    jungprcgb       [1]; /*B[4 ] ���갡�ݱ���             */
	char    settleprcgb     [1]; /*B[4 ] �����������ݱ���         */
	char    filler9         [3]; /* filler                        */
	char    ff              [1]; /* 0xff                          */
	char    cr              [1]; /* 0x0d                          */
	char    lf              [1]; /* 0x0a                          */
}PK_MKFUJUNGPRC;


typedef struct _PK_MKFUMIGYUL{
	char    id              [1]; /* FRAME_ID '0x90'               */
	char    filler          [3]; /* Filler                        */
	long    index              ; /* ���� �Ϸù�ȣ                 */
	char    migyulgb        [1]; /* �̰��� ��������               */
	char    trddt           [8]; /* �ŷ�����                      */
	long    migyul             ; /* �̰�����������(��������)      */
	char    ff              [1]; /* 0xff                          */
	char    cr              [1]; /* 0x0d                          */
	char    lf              [1]; /* 0x0a                          */
}PK_MKFUMIGYUL;


typedef struct _PK_ELWKOBAMST{
	char    id             [1 ]; /*A[1 ] FRAME_ID                 */
	char    filler         [3 ]; /*A[3 ] FILLER                   */
	long    index              ; /*B[4 ] �ڵ��Ϸù�ȣ             */
	char    expcode        [12]; /*A[12] ���ڵ�                   */
	long    endbaseprc1        ; /*B[4 ] ELW��������߻����ذ���  */
	long    endbaseprc2        ; /*B[4 ] ELW��������߻����ذ���  */
	char    hangsainfo     [200];/*A[200]ELW��������Ǹ���系��  */
	char    endpynginfo    [300];/*A[300]ELW���������򰡰��ݹ��  */
	char    filler1        [9 ]; /*A[9 ] filler                   */
	char    ff             [1 ]; /*A[1 ] FF                       */
	char    cr             [1 ]; /*A[1 ] CR                       */
	char    lf             [1 ]; /*A[1 ] LF                       */
}PK_ELWKOBAMST;

typedef struct _PK_ELWKOBABASE{
	char    id             [1 ]; /*A[1 ] FRAME_ID                 */
	char    filler         [3 ]; /*A[3 ] FILLER                   */
	long    index              ; /*B[4 ] �ڵ��Ϸù�ȣ             */
	char    expcode        [12]; /*A[12] ���ڵ�                   */
	char    tnsdate        [8 ]; /*A[8 ] ��������                 */
	char    basememedt     [8 ]; /*A[8 ] �����ڻ�Ÿ�����         */
	char    kobadt         [8 ]; /*A[8 ] KO�߻�����               */
	char    fritem         [12]; /*A[12] ���������ڵ�             */
	char    elwjimk        [1 ]; /*A[1 ] ELW�����Ҽӽ��屸���ڵ�  */
	char    upjigb         [3 ]; /*A[3 ] ���������ڵ�             */
	char    ampmgb         [1 ]; /*A[1 ] �������ı����ڵ�         */
	char    filler1        [3 ]; /*A[3 ] filler                   */
	long    high               ; /*B[4 ] ��                     */
	long    low                ; /*B[4 ] ����                     */
	char    filler2        [5 ]; /*A[9 ] filler                   */
	char    ff             [1 ]; /*A[1 ] FF                       */
	char    cr             [1 ]; /*A[1 ] CR                       */
	char    lf             [1 ]; /*A[1 ] LF                       */
}PK_ELWKOBABASE;


typedef struct _PK_ELWKOBATIME{
	char    id             [1 ]; /*A[1 ] FRAME_ID                 */
	char    filler         [3 ]; /*A[3 ] FILLER                   */
	char    expcode        [12]; /*A[12] ���ڵ�                   */
	char    kobadt         [8 ]; /*A[8 ] KO�߻�����               */
	char    kotime         [8 ]; /*A[8 ] KO�߻����� TIME          */
	char    filler1        [5 ]; /*A[5 ] filler                   */
	char    ff             [1 ]; /*A[1 ] FF                       */
	char    cr             [1 ]; /*A[1 ] CR                       */
	char    lf             [1 ]; /*A[1 ] LF                       */
}PK_ELWKOBATIME;


typedef struct _FILE_ELWKOBAMST{
	char    id             [1 ]; /*A[1 ] FRAME_ID                 */
	char    filler         [3 ]; /*A[3 ] FILLER                   */
	char    index          [8 ]; /*B[4 ] �ڵ��Ϸù�ȣ             */
	char    expcode        [12]; /*A[12] ���ڵ�                   */
	char    endbaseprc1    [32]; /*B[4 ] ELW��������߻����ذ���  */
	char    endbaseprc2    [32]; /*B[4 ] ELW��������߻����ذ���  */
	char    hangsainfo     [200];/*A[200]ELW��������Ǹ���系��  */
	char    endpynginfo    [300];/*A[300]ELW���������򰡰��ݹ��  */
	char    filler1        [9 ]; /*A[9 ] filler                   */
	char    ff             [1 ]; /*A[1 ] FF                       */
	char    cr             [1 ]; /*A[1 ] CR                       */
	char    lf             [1 ]; /*A[1 ] LF                       */
}FILE_ELWKOBAMST;


typedef struct _FILE_ELWKOBABASE{
	char    id             [1 ]; /*A[1 ] FRAME_ID                 */
	char    filler         [3 ]; /*A[3 ] FILLER                   */
	char    index          [8 ]; /*B[4 ] �ڵ��Ϸù�ȣ             */
	char    expcode        [12]; /*A[12] ���ڵ�                   */
	char    tnsdate        [8 ]; /*A[8 ] ��������                 */
	char    basememedt     [8 ]; /*A[8 ] �����ڻ�Ÿ�����         */
	char    kobadt         [8 ]; /*A[8 ] KO�߻�����               */
	char    fritem         [12]; /*A[12] ���������ڵ�             */
	char    elwjimk        [1 ]; /*A[12] ELW�����Ҽӽ��屸���ڵ�  */
	char    upjigb         [3 ]; /*A[3 ] ���������ڵ�             */
	char    ampmgb         [1 ]; /*A[1 ] �������ı����ڵ�         */
	char    filler1        [3 ]; /*A[3 ] filler                   */
	char    high           [32]; /*B[4 ] ��                     */
	char    low            [32]; /*B[4 ] ����                     */
	char    filler2        [9 ]; /*A[5 ] filler                   */
	char    ff             [1 ]; /*A[1 ] FF                       */
	char    cr             [1 ]; /*A[1 ] CR                       */
	char    lf             [1 ]; /*A[1 ] LF                       */
}FILE_ELWKOBABASE;


typedef struct _FILE_ELWKOBATIME{
	char    expcode        [12]; /*A[12] ���ڵ�                   */
	char    kobadt         [8 ]; /*A[8 ] KO�߻�����               */
	char    kotime         [8 ]; /*A[8 ] KO�߻����� TIME          */
}FILE_ELWKOBATIME;

#endif  /* __SISEPK_H__ */
/*****************************************************************************/
