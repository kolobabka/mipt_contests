#include "../headers/bizzbuzz.h"
//-----------------------------------------------------------
//-----------------------------------------------------------
static const char bizzLen     = 4;
static const char buzzLen     = 4;
static const char bizzbuzzLen = 8;
//-----------------------------------------------------------
//-----------------------------------------------------------
static long long SizeText (char* const textName)
{

  struct stat size;
 	stat (textName, &size);

  return (long long) size.st_size;
}
//-----------------------------------------------------------
//-----------------------------------------------------------
void BizzBuzzer (int file_1, int file_2, char** argv) {

    long long totLength  = 0ULL;
    long long length     = 1ULL;

    char rBuffer[RSIZE] = {0};

    totLength = SizeText (argv[1]);

    while (totLength > 0 && length > 0) {

        length = read (file_1, rBuffer, RSIZE);
        if (PerrorCheck (length) == 0)
            return;

        length = SepParsNumbers (file_1, file_2, rBuffer, length);
        totLength -= length;
    }

}
//-----------------------------------------------------------
//-----------------------------------------------------------
int SepParsNumbers (int file_1, int file_2, const char* rBuffer, long long length) {

    long long shift = 0;
    long long index = 0;
    int sum         = 0;
    int offset      = 0;
    int lastNum     = 0;
    int descriptor  = 0;
    char symb       = 'A';

    while (index < length) {

        if (isspace (rBuffer[index])) {

            descriptor = write (file_2, rBuffer + index, 1);
            Check;

            ++index;
            continue;
        }

        if (rBuffer[index] == '-') {

            shift++;
            index++;


            if (index < length && isspace (rBuffer[index])) {

                descriptor = write (file_2, rBuffer + index - 1, 1);
                Check;

                shift = 0;
                continue;
            }
        }

        while (isdigit (rBuffer[index])) {

            lastNum = rBuffer[index] - '0';
            sum += lastNum;
            sum %= 3;
            ++shift;
            ++index;
        }

        if (index >= length) {

            return (Overflow (index, rBuffer, sum, lastNum, shift, file_1, file_2));
        }

        if (index < length && isspace (rBuffer[index])) {

            offset = NumCases (sum, lastNum, file_2);

            if (offset == 0) {

                shift = 0;
                sum = 0;
                continue;
            }

            descriptor = write (file_2, rBuffer + index - shift, shift);
            Check;

            shift = 0;
            sum = 0;
            continue;
        }


        if (!(isdigit (rBuffer[index]))) {

            descriptor = write (file_2, rBuffer + index - shift, shift + 1);
            ++index;

            while (index < length && (!(isspace (rBuffer[index]) && descriptor > 0 && rBuffer[index] != '\0'))) {

                descriptor = write (file_2, rBuffer + index, 1);

                index++;
            }
            shift = 0;
            sum = 0;

            if (index >= length) {

                while (!(isspace (symb))) {

                    descriptor = read (file_1, &symb, 1);
                    if (descriptor > 0)
                        descriptor = write (file_2, &symb, 1);
                    else
                        return index + shift;
                    shift++;

                }
                return index + shift;
            }
        }
    }

    return index;
}
//-----------------------------------------------------------
//-----------------------------------------------------------
long long NumCases (const int sum, const int lastNum, int file_2) {

    int descriptor = 0;
    int offset     = 0;

    if (offset == 1L) {

        printf ("Error!\n");
        return 1;
    }

    if (((sum % 3) == 0) && (lastNum == 5 || lastNum == 0)) {

        descriptor = write (file_2, "BizzBuzz", bizzbuzzLen);
        Check;

        return 0;
    }

    if ((lastNum == 5 || lastNum == 0)) {

        descriptor = write (file_2, "Buzz", buzzLen);
        Check;

        return 0;
    }

    if ((sum % 3) == 0) {

        descriptor = write (file_2, "Bizz", bizzLen);
        Check;

        return 0;
    }

    return -1;
}
//-----------------------------------------------------------
//-----------------------------------------------------------
long long Overflow (long long index, const char* rBuffer, int sum, int lastNum, int shift, int file_1, int file_2) {

    assert (rBuffer);
    long long lastShift = 0;
    int offset          = 0;
    int descriptor      = 0;
    char symb = rBuffer[index];

    lastShift = shift;
    if (symb == '-') {

        descriptor = read (file_1, &symb, 1);
        Check;

        if ((isspace (symb)) || descriptor == 0) {

            offset = lseek (file_1, -1, SEEK_CUR);
            write (file_2, rBuffer + index - 1, 1);
        }
    }
    symb = rBuffer[index - 1];

    while (!(isspace(symb))) {

        descriptor = read (file_1, &symb, 1);
        Check;

        if (descriptor > 0)
            ++shift;

        if (isspace (symb) || descriptor == 0) {

            offset = NumCases (sum, lastNum, file_2);
            if (offset == -1) {

                lseek (file_1, -shift, SEEK_CUR);
                for (int i = 0; i < shift; i++) {

                    descriptor = read (file_1, &symb, 1);
                    Check;

                    descriptor = write (file_2, &symb, 1);
                    Check;
                }
            }
            if (offset == 0 && descriptor != 0) {

                descriptor = write (file_2, &symb, 1);
                Check;
            }

            return index + shift - lastShift;
        }
        if (isdigit (symb)) {

            lastNum = symb - '0';
            sum += lastNum;
            sum %= 3;
        }
        if (!(isdigit (symb))) {

            lseek (file_1, -shift, SEEK_CUR);
            symb = 'A';
            shift = 0;

            while (!(isspace (symb))) {

                descriptor = read (file_1, &symb, 1);
                Check;

                shift++;
                if (descriptor > 0)
                    descriptor = write (file_2, &symb, 1);
                else
                    return index + shift - lastShift;
            }

            return index + shift - lastShift;
        }
    }
    return index;
}

// void FileGenerator () {
//
//   int file_1 = 0;
//
//   file_1 = open ("Big", O_WRONLY | O_CREAT | O_TRUNC, 0777);
//   PerrorCheck (file_1);
//
//   write (file_1, "3", 1024*1024*1024);
//
//
//   close (file_1);
// }
