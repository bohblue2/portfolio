#ifndef _FUTCONF_H_
#define _FUTCONF_H_

#include "zconf.h"

typedef struct _SERVICE_INFO{
    char    id    ;    /* */
    char    *hgh_ip;    /* */	
    char    *low_ip;	/* */
    int     mport  ;	/* */
    int     tport  ;	/* */
    int     rport  ;	/* */
    int     msglen ;    /* receive len*/
    int     thd_cnt;
    int     que_len;
    char    *data_tp;	/* */
    char    *io_tp  ;    /* */
} SERVICE_INFO;

/* 서비스 정의 */
SERVICE_INFO	Sinfo[] = {
{'A',	"233.37.54.171",	"233.37.54.181",	15572,	16572,	15575,  300, 1, 16, "FUT", "FUT"}, 
{'B',	"233.37.54.191",	"233.37.54.191",	15574,	16574,	15575,  300, 1, 16, "FUT", "FUT"},
{'C',	"233.37.54.191",	"233.37.54.191",	15577,	16577,	15575,  300, 1, 16, "FUT", "FUT"},
{'D',	"233.37.54.191",	"233.37.54.191",	15578,	16578,	15575,  300, 1, 16, "FUT", "FUT"},
{'E',	"233.37.54.191",	"233.37.54.191",	15573,	16573,	15575,  300, 1, 16, "FUT", "FUT"},
{'F',	"233.37.54.191",	"233.37.54.191",	15571,	16571,	15575, 1300, 1, 16, "FUT", "FUT"},
};

#define SERVICE_INFO_CNT	( sizeof(Sinfo)/sizeof(SERVICE_INFO))

#endif
