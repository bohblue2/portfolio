/*
 * Chaos Header file 
 * Name : chaos.h
 * Date : 1997.06.27
 * By   : PentaSoft Co.,Ltd. Sagittarius
 */
#if !defined (_CHAOS_H_)
#define _CHAOS_H_

#define ONCE_MODE    0
#define FOREVER_MODE 1
#define CONTROL_TYPE 1000
#define TIME_OUT     1

#define CHAOS_PORT   16102      /* lgchaos/tcp port */ 
#define MAX_PROC_CNT  1024       /* ���� ������ �ִ� process�� */

#define BASE_EVENT_TYPE 3000

#define CMD_KILL     "KILL"
#define CMD_START    "STAT"
#define CMD_SHUTDOWN "DOWN"
#define CMD_RESTART  "REST"
#define CMD_RELOAD   "RELO"
#define CMD_END      "END "
#define CMD_LIST_REQ "LREQ"
#define CMD_CH_DATE  "DATE"
#define CMD_KILL_ID  "KIID"
#define CMD_START_ID "STID"
#define CMD_NULL     ""

#define SHM_ZCHAOS_KEY  0x40010000
#define SEMA_ZCHAOS_KEY 0x40020000

/* FetchXXXX()���� �ʿ��� ���� */
typedef enum{GE=1, GT,LE,LT,EQ}QMODE;
typedef enum{
    KEY_INDEX = 1, 
    KEY_NAME,
    KEY_PID
}QKEY;

/* Shared memory Header */
typedef struct _SHM_HEADER{
        char   infor[16]; /* ������ yyyymmdd:HHMMSS */
        int    cnt      ; /* Item ����              */
}SHM_HEADER;

typedef struct _PROC_STRUCT{
	char   id       [12]; /* Process ID                  */
	char   name     [20]; /* Process name                */
	char   magic        ; /* magic value (reload�� ���) */
	int    mode         ; /* ���� MODE FOREVER:1, ONCE:0 */
	int    pid          ; /* Process id                  */
	int    start        ; /* Proc ���ýð�               */
	int    end          ; /* Proc ����ð�               */
	int    stime        ; /* Proc �����⵿ �ð�          */
	int    stcnt        ; /* �⵿ Ƚ��                   */
	char   path    [255]; /* Default�� ���� ��� PATH    */
	char   *Argv   [255]; /* �⵿�� Arguments            */

	/* tr ������� */
	/* ī������ ��� ������ */
	int    chkcnt       ; /* ī���� üũ Ƚ��            */
	int    chktime      ; /* ī���� üũ Ÿ��            */
	
	/* ap���μ����� ��� ������ */
	int    trpid        ; /* tr�� �������� ap thread id  */
	int    trcnt        ; /* tr�� �Ѿ Ƚ��            */
	int    trsttime       ; /* tr�� �Ѿ �ֱٽð�        */
	int    trrttime    ; /* tr�� �Ѿ �ֱٽð�        */
	int    errcnt       ; /* ������ �߻��� tr�Ǽ�        */
	int    errtime      ; /* ���� tr�� �߻��� �ֱٽð�   */
}PROC_STRUCT;

typedef struct _LIST_CTL_PK{
	char   type  [4];
	char   total [4];
	char   cnt   [4];
}LIST_CTL_PK;

/* ���¿䱸 Client�� �����ϴ� format */
typedef struct _PROC_LIST_PK{
	char   index [4];    /* PROCESS INDEX   */ 
	char   id    [12];    /* Process uniq id */
	char   name  [20];   /* Process name    */
	char   mode  [1];    /* Running mode    */
	char   pid   [6];    /* Process id      */
	char   start [6];    /* Start time      */
	char   end   [6];    /* End time        */
	char   stime [6];    /* ���� Start time */
	char   stcnt [4];    /* Start count     */
}PROC_LIST_PK;
typedef struct _PROC_CTL_PK{
	char    type [4];
	char    index[6];
}PROC_CTL_PK;
typedef struct _PROC_CTLID_PK{
	char    type [4];
	char    id[20];
}PROC_CTLID_PK;
typedef struct _REQ_LIST_PK{
	char     type[4];
	char     from[4];
	char     cnt [4];
}REQ_LIST_PK;
typedef union _CHAOS_CMD_PK{
	char         index[4]     ; /* Process index               */
	PROC_LIST_PK list         ;
	LIST_CTL_PK  lctl         ;
	PROC_CTL_PK  pctl         ;
	REQ_LIST_PK  rlst         ;
	PROC_CTLID_PK pctlid      ;
}CHAOS_CMD_PK;

typedef struct _CONTROL_LIST{
	char    type[4];
	int     (*fun)();
}CONTROL_LIST;
#endif
