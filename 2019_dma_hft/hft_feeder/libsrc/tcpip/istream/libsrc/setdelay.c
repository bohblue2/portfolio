/***********************************************************************/
/* Set Delay mode                                                      */
/* NAME    : setdelay.c                                                */
/* CREATE  : 2002.10.15                                                */
/* REMARKS :                                                           */
/***********************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/ioctl.h>
/******************************************************************************/
/* Set Nodelay mode                                                           */
/* Prototype  : int SetNodelay(fd)                                            */
/* Arguments  : int fd;                                                       */
/* Return     : int                                                           */
/******************************************************************************/
int SetNodelay(fd)
int fd;
{
int on;
        /* Set NO_DELAY mode */
        on = fcntl(fd, F_GETFL);
        on |= O_NDELAY;
        return fcntl(fd, F_SETFL, on);
}

/******************************************************************************/
/* Set Delay mode                                                             */
/* Prototype  : int SetDelay(fd)                                              */
/* Arguments  : int fd;                                                       */
/* Return     : int                                                           */
/******************************************************************************/
int SetDelay(fd)
int fd;
{
int on;
        /* Set NO_DELAY mode */
        on  = fcntl(fd, F_GETFL);
        on  &= ~O_NDELAY;
        return fcntl(fd, F_SETFL, on);
}
