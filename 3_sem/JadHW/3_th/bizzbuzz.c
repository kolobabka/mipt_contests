#include "bizzbuzz.h"
//-----------------------------------------------------------
//-----------------------------------------------------------
static int SizeText (char* const textName)
{

  struct stat size;
 	stat (textName, &size);

  return size.st_size;
}
//-----------------------------------------------------------
//-----------------------------------------------------------
signed char ArgError (int argc) {

    if (argc < 3) {

        printf ("Arguments are not found!\n");
        return 0;
    }

    if (argc > 3) {

        printf ("Too many arguments!\n");
        return 0;
    }

    return 1;
} 
//-----------------------------------------------------------
//-----------------------------------------------------------
signed char PerrorCheck (int file) {

    if (file == -1) {

        perror ("File open error:");
        return 0;
    }

    return 1;
}
//-----------------------------------------------------------
//-----------------------------------------------------------
void BizzBuzzer (int file_1, int file_2, char** argv) {

    unsigned long long lenght  = 0ULL;
    char*              rBuffer = NULL;
    char*              wBuffer = NULL;

    int descriptor = 0;
    int wBufLenght = 0;

    lenght = SizeText (argv[1]);   

    if (lenght >= (INT_MAX / 4) - 1) {

        printf ("Too long text!\n");
        return;
    } 
    
    rBuffer = (char*) calloc (lenght + 1, sizeof (char));
    assert (rBuffer);

    wBuffer = (char*) calloc (lenght * 4, sizeof (char));    
    assert (wBuffer);

    descriptor = read (file_1, rBuffer, lenght);
    if (PerrorCheck (descriptor) == 0) {

        free (rBuffer);
        free (wBuffer);
        return;
    }

    for (int i = 0; i < lenght; i++) {

        printf ("%c", rBuffer[i]);
    } 

    wBufLenght = ParsNumbers (rBuffer, wBuffer, lenght);

    printf ("wBuflenght = %d\n", wBufLenght);

    descriptor = write (file_2, wBuffer, wBufLenght);
    free (rBuffer);
    free (wBuffer);
}
//-----------------------------------------------------------
//-----------------------------------------------------------
int ParsNumbers (char* rBuffer, char* wBuffer, int lenght) {

    int  wBufLenght  = 0;
    char lastNum     = 0;
    int index        = 0;
    char bizzLen     = 4;
    char buzzLen     = 4;
    char bizzbuzzLen = 8;
    

    for (index; index < lenght; ++index) {

        int sum     = 0;
        int counter = 0;

        if (isspace (rBuffer[index] != 0))
        {
            wBuffer[wBufLenght] = rBuffer[index];
            ++wBufLenght;
            continue;
        }

        while ( (index < lenght) && (isdigit (rBuffer[index]) != 0)) {

            lastNum =  rBuffer[index] - '0'; 
            sum     += lastNum;
            ++counter;
            ++index;
        }

        if (isspace (rBuffer[index] != 0)) {

            if ((sum % 3 == 0) && (lastNum == 0 || lastNum == 5)) {

                wBufLenght = WriteBizzBuzz (wBuffer, "bizzbuzz", wBufLenght, bizzbuzzLen);
                wBuffer[wBufLenght] = rBuffer[index];
                ++wBufLenght; 
                continue;
            }

            if ((lastNum == 0 || lastNum == 5)) {

                wBufLenght = WriteBizzBuzz (wBuffer, "buzz", wBufLenght, buzzLen);
                wBuffer[wBufLenght] = rBuffer[index];
                ++wBufLenght; 
                continue;
            }

            if ((sum % 3 == 0)) {

                wBufLenght = WriteBizzBuzz (wBuffer, "bizz", wBufLenght, bizzLen);
                wBuffer[wBufLenght] = rBuffer[index];
                ++wBufLenght; 
                continue;
            }
        }
        else {

            for (int i = 0; i < counter; ++i) {

                wBuffer[wBufLenght] = rBuffer[index - counter + i];
                ++wBufLenght;
            }
        }
    }

    printf ("%s\n", wBuffer);
    return wBufLenght;
}
//-----------------------------------------------------------
//-----------------------------------------------------------
int WriteBizzBuzz (char* buffer, const char* word, int wBufLenght, int lenWord) {

    assert (buffer);

    for (int index = 0; index < lenWord; ++index) {

        buffer[wBufLenght] = word[index];
        ++wBufLenght;
    }

    return wBufLenght;
}
