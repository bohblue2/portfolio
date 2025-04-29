#ifndef _ZCONF_H_
#define _ZCONF_H_

#include "event.h"
#include "tpool.h"
#include "mdb.h"

#define PATH_LOG "/home/dat/log"
#define PATH_CFG "/conf"
#define HEX_DUMP_WIDTH 16


#define LOG_DAYS    2000
#define ETIME_OUT   86400

#define STK_PREFIX  "STK"
#define KDQ_PREFIX  "KDQ"
#define FUT_PREFIX  "FUT"
#define OPT_PREFIX  "OPT"
#define SFT_PREFIX  "SFT"

/////////////////////////////////////////////////////////////////////
// chaos monitor
#define ZNETSPY_PORT    16101
#define ZCHAOS_PORT     16102

#define BUFF_LEN            131072
#define PACKET_LEN            2048
#define PACKET_LEN_DEBUG       512 
#define PACKET_SIZE              5        
#define SOCK_TIMEOUT             5
#define TONG_TIMEOUT             1



/* Thread pool Configuration */
#define TPOOL_THREAD_CNT    64       /* Worker Thread 갯수   */        
#define TPOOL_QUEUE_LEN     64      /* job Queue 크기       */
#define TPOOL_TIMEOUT       0

/*
typedef struct _SERVICE_INFO{
    unsigned char	id;
    unsigned char	debug_mode;
    int			    port;
    char		    name[32];
    int			    Dinfo_cnt;
    DATA_INFO		*Dinfo;
    DATA_INFO		*Dinfo_cache;
} SERVICE_INFO;
*/

typedef struct _FD_QUEUE{               /* FD QUEUE(원형)   */
    unsigned char   Queue[BUFF_LEN];        /* fd data buffer   */
    int             fd;                     /* fd 번호          */
    char            addr[16];               /* fd ip addr       */
    int             sttime;                 /* conn time        */
    int             Pos;                    /* 큐의 끝          */
    int             PkCurr;                 /* 큐의 시작        */
    int             cnt;                    /* fd패킷 만든 횟수 */
    int             gubun;                  /* 접속유형 0:R/S분리 1:R/S공통 */
} FD_QUEUE;

typedef struct _FD_PACKET{              /* FD PACKET       */
    unsigned char   Packet[PACKET_LEN];     /* packet          */
    unsigned char   OutPacket[PACKET_LEN];  /* packet          */
    int             len;                    /* packet 길이     */
    int             fd;                     /* 해당 fd         */
    char            addr[16];               /* fd ip addr       */
    int             sttime;                 /* fd의 체크       */
} FD_PACKET;

#ifndef RB_ENTRY
        #define RB_ENTRY(type)                                                  \
        struct {                                                                \
                struct type *rbe_left;          /* left element */              \
                struct type *rbe_right;         /* right element */             \
                struct type *rbe_parent;        /* parent element */            \
                int rbe_color;                  /* node color */                \
        }
#endif /* !RB_ENTRY */

struct FD_TREE {
    RB_ENTRY(FD_TREE) fd_tree_node;         /* red-black tree entry */
    int             fd;                     /* fd 번호          */
    char            addr[16];               /* fd ip addr       */
    int             sttime;                 /* conn time        */
};

/////////////////////////////////////////////////////////////////////
//./logctl/logctl.c:
int InitDebugLog(char *pathname, char *filename, int gdate);
void Log(char *format, ...);

static int InitNetspy();
void Debug(char *format, ...);
void NetspyClose();

int Makeshm(key_t shmkey, long nbyte);
char *Attachshm(int shmid, char *shmaddr, int flag);
int InitSemaphore(key_t key);
int Detachshm(char *vaddr);

int OpenInetMultiServer(int port, char *group);

int OpenInetStreamServer(int port);
int WriteStream2(int fd, char *buff, int sz);
int ReadStream2(int fd, char *buff);
int WaitConnect(int fd, char *buff);

int OpenInetStreamClient(char *host, int port);
int ReadUnixDgram(int fd, char *data, int len);
int OpenUnixDgramServer(char *unistr_path);

int GetWindowSize(int fd, int *x, int *y); // term/winsise.cvi 

// tpool
int tpool_destroy(tpool_t tpool, int finish);
int tpool_add_work(tpool_t tpool, void (*routine)(), void *arg);
void tpool_init(tpool_t *tpoolp, int num_worker_threads, int max_queue_size, int do_not_block_when_full);
    
int ReadConfig(char *pathname, char *category, char *keyword, char *val);
/////////////////////////////////////////////////////////////////////

#endif
