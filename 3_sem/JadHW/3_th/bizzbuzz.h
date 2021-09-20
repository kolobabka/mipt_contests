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
//-----------------------------------------------------------
//-----------------------------------------------------------
signed char ArgError (int argc, char** argv);
signed char PerrorCheck (int file);
void BizzBuzzer (int file_1, int file_2, char** argv);
int ParsNumbers (char* rBuffer, char* wBuffer, int lenght);
int WordWrite (char* wBuffer, char* wordPtr, int wBufLenght, int* index);
int NumCases (char* wBuffer, char* wordPtr, int wBufLenght, int sum, int lastNum);
int WriteBizzBuzz (char* buffer, const char* word, int wBufLenght, const int lenWord);
