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
#define RSIZE 1000000
//-----------------------------------------------------------
//-----------------------------------------------------------
signed char PerrorCheck (int file);
signed char ArgError (int argc, char** argv);
void BizzBuzzer (int file_1, int file_2, char** argv);
long long WordWrite (int file_1, int file_2, long long shift);
long long NumCases (const int sum, const int lastNum, int file_2);
int SepParsNumbers (int file_1, int file_2, const char* rBuffer, long long length);
int ToFile (int file_1, int file_2, long long shift, long long index, const long long totlength);
long long Overflow (long long index, const char* rBuffer, int sum, int lastNum, int shift, int file_1, int file_2);
//-----------------------------------------------------------
//-----------------------------------------------------------
#define Check if(PerrorCheck (descriptor) == 0) return 1