#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <poll.h>
#include <fcntl.h>   

signed char ArgError (int argc);
int OpenFunction (int argc, char** argv, struct pollfd* files);
signed char PerrorCheck (int error, struct pollfd* file);
