#ifndef __SFTCONF_H__H_
#define __SFTCONF_H__H_

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
{'A',	"233.37.54.193",	"233.37.54.193",	15594,	16594,	15595,	1300, 1, 16, "SFT", "SFT"},
{'B',	"233.37.54.193",	"233.37.54.193",	15597,	16597,	15595,	1300, 1, 16, "SFT", "SFT"},
{'C',	"233.37.54.193",	"233.37.54.193",	15598,	16598,	15595,	1300, 1, 16, "SFT", "SFT"},
{'D',	"233.37.54.193",	"233.37.54.193",	15593,	16593,	15595,	1300, 1, 16, "SFT", "SFT"},
{'E',	"233.37.54.174",	"233.37.54.174",	15592,	16592,	15595,	1300, 1, 16, "SFT", "SFT"},
{'F',	"233.37.54.193",	"233.37.54.193",	15591,	16591,	15595,	1300, 1, 16, "SFT", "SFT"},
};

#define SERVICE_INFO_CNT	( sizeof(Sinfo)/sizeof(SERVICE_INFO))

#endif
