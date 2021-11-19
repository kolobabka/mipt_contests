#pragma once
//-----------------------------------------------------------
//-----------------------------------------------------------
#include <sys/types.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <ctype.h>
#include <time.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>
//-----------------------------------------------------------
//-----------------------------------------------------------
static const struct timespec tw = {0, 10000};
//-----------------------------------------------------------
//-----------------------------------------------------------
#define SIZE_OF_BUF 500000 //think about the size  
//-----------------------------------------------------------
//-----------------------------------------------------------
enum Errors {

    NO_ERR,
    ARG_ERR,
    FILE_ERR,
    NULL_PTR_ERR,
    RECIEVE_ERR,
    SEND_ERR,
    SIGQUEUE_ERR,
    WRITE_ERR,
};
//-----------------------------------------------------------
//-----------------------------------------------------------
signed char ArgError    (int argc, int expectedNum);
signed char PerrorCheck (int file);

#define ZeroPointer(pointer) if (!pointer) { \
                                printf ("Zero pointer!\n"); \
                                return NULL_PTR_ERR; \
                             }
            