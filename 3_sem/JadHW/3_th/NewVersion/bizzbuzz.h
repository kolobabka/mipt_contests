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
#define RSIZE 10000
#define WSIZE 80
//-----------------------------------------------------------
//-----------------------------------------------------------
signed char ArgError (int argc, char** argv);
signed char PerrorCheck (int file);
void BizzBuzzer (int file_1, int file_2, char** argv);
// long long ParsNumbers (char* rBuffer, char* wBuffer, long long lenght, int* wholeWord);
long long SepParsNumbers (int file_1, int file_2, const char* rBuffer, char* wBuffer, const long long lenght, const long long totLenght);
//long long WordWrite (char* wBuffer, char* wordPtr, long long wBufLenght, long long* index, int* wholeWord, long long shift);
long long NumCases (const char* rBuffer, int sum, int lastNum, const long long index, long long shift, int file_1, int file_2);
int ToFile (int file_1, int file_2, long long shift, long long index, const long long totLenght);
long long WordWrite (int file_1, int file_2, long long shift);
//-----------------------------------------------------------
//-----------------------------------------------------------
