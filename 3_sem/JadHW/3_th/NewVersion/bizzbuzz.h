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
#define RSIZE 4
#define WSIZE 800
//-----------------------------------------------------------
//-----------------------------------------------------------
signed char ArgError (int argc, char** argv);
signed char PerrorCheck (int file);
void BizzBuzzer (int file_1, int file_2, char** argv);
// long long ParsNumbers (char* rBuffer, char* wBuffer, long long length, int* wholeWord);
int SepParsNumbers (int file_1, int file_2, const char* rBuffer, long long length, long long totLength);
// RBUFFER???? FILE_1??????
long long NumCases (const char* rBuffer, const int sum, const int lastNum, long long shift, int file_1, int file_2);
int ToFile (int file_1, int file_2, long long shift, long long index, const long long totlength);
long long WordWrite (int file_1, int file_2, long long shift);
//-----------------------------------------------------------
//-----------------------------------------------------------
