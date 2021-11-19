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
#include <unistd.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <ctype.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>
//-----------------------------------------------------------
//-----------------------------------------------------------
typedef struct Command {

    int argc;
    char** argv;
} Command;
//-----------------------------------------------------------
//-----------------------------------------------------------
signed char ArgError (int argc, char** argv);
signed char PerrorCheck (int file);
int CaneImmitation (int file_1, char* const textName);
Command* CommandRecognizer (char* buffer, long long sizeOfFile);
long CommandCounter (char* buffer);
void SeparateCommands (Command* commands, char* buffer);
int argcCounter (char* curCommand);
int Execution (Command* commands, long numCommands);