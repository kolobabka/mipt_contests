#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <ctype.h>
//-----------------------------------------------------------
//-----------------------------------------------------------
signed char ArgError (int argc);
signed char PerrorCheck (int file);
void BizzBuzzer (int file_1, int file_2, char** argv);
int ParsNumbers (char* rBuffer, char* wBuffer, int lenght);
int WriteBizzBuzz (char* buffer, const char* word, int wBufLenght, int lenWord);