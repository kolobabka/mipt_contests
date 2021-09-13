#include "bizzbuzz.h"
//-----------------------------------------------------------
//-----------------------------------------------------------
static const char bizzLen     = 4;
static const char buzzLen     = 4;
static const char bizzbuzzLen = 8;
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
    
    if (lenght >= (INT_MAX / 5) - 1) {

        printf ("Too long text!\n");
        return;
    } 
    
    rBuffer = (char*) calloc (lenght + 1, sizeof (char));
    assert (rBuffer);

    wBuffer = (char*) calloc (lenght * 5, sizeof (char));    
    assert (wBuffer);

    descriptor = read (file_1, rBuffer, lenght);
    if (PerrorCheck (descriptor) == 0) {

        free (rBuffer);
        free (wBuffer);
        return;
    }

    wBufLenght = ParsNumbers (rBuffer, wBuffer, lenght);

    printf ("wBuflenght = %d\n", wBufLenght);

    descriptor = write (file_2, wBuffer, wBufLenght);
    if (PerrorCheck (descriptor) == 0) {

        free (rBuffer);
        free (wBuffer);
        return;
    }   

    free (rBuffer);
    free (wBuffer);
}
//-----------------------------------------------------------
//-----------------------------------------------------------
int ParsNumbers (char* rBuffer, char* wBuffer, int lenght) {

    int  wBufLenght  = 0;
    int lastIndex    = 0;
    char lastNum     = 0;
    int index        = 0;
    int sum          = 0;
    
    char*      wordPtr     = NULL;
    
    while (index <= lenght && rBuffer[index] != '\0') {

        
        if (index <= lenght && isspace (rBuffer[index])) {

            wBuffer[wBufLenght] = rBuffer[index];
            wBufLenght++; 
            ++index;
            continue;
        }
        wordPtr = rBuffer + index;
        lastIndex = index;

        while (index <= lenght && rBuffer[index] && isdigit (rBuffer[index])) {

            lastNum = rBuffer[index] - '0';
            sum += lastNum;
            index++;
            continue;
        }

        if (index <= lenght && isspace (rBuffer[index])) {
            
            wBufLenght = NumCases (wBuffer, wordPtr, wBufLenght, sum, lastNum);
            wBuffer[wBufLenght] = rBuffer[index];
            continue;
        }

        if (index <= lenght && (rBuffer[index] == '.' || rBuffer[index] == ',')) {
            
            ++index;
            while (index <= lenght && rBuffer[index] && rBuffer[index] == '0') 
                index++;

            
            if (index <= lenght && isspace (rBuffer[index])) {

                wBufLenght = NumCases (wBuffer, wordPtr, wBufLenght, sum, lastNum);
                wBuffer[wBufLenght] = rBuffer[index]; 
                continue;
            }
        }

        index = lastIndex;
        wBufLenght = WordWrite (wBuffer, wordPtr, wBufLenght, &index);
        
    }

    return wBufLenght;

    // for (index; index < lenght; ++index) {

    //     int sum     = 0;
    //     int counter = 0;

    //     printf ("index = %d\n", index);
    //     if (isspace (rBuffer[index]) != 0)
    //     {
    //         wBuffer[wBufLenght] = rBuffer[index];
    //         ++wBufLenght;
    //         continue;
    //     }

    //     while ( (index < lenght) && (isdigit (rBuffer[index]) != 0)) {

    //         lastNum =  rBuffer[index] - '0';            
    //         sum     += lastNum;

    //         ++counter;
    //         ++index;
    //     }
    //     printf ("index = %d\n", index);

    //     if (rBuffer[index] == '\0') {

    //         printf ("wdffwf\n");
    //         lastNum = rBuffer[index - 1];
    //     }


    //     if (isspace (rBuffer[index]) != 0 || rBuffer[index] == '\0') {
            
    //         if ((sum % 3 == 0) && (lastNum == 0 || lastNum == 5)) {

    //             wBufLenght = WriteBizzBuzz (wBuffer, "bizzbuzz", wBufLenght, bizzbuzzLen);
                
    //             wBuffer[wBufLenght] = rBuffer[index];
    //             ++wBufLenght; 
    //             continue;
    //         }

    //         if ((lastNum == 0 || lastNum == 5)) {

    //             wBufLenght = WriteBizzBuzz (wBuffer, "buzz", wBufLenght, buzzLen);

    //             wBuffer[wBufLenght] = rBuffer[index];
    //             ++wBufLenght; 
    //             continue;
    //         }

    //         if ((sum % 3 == 0)) {

    //             wBufLenght = WriteBizzBuzz (wBuffer, "bizz", wBufLenght, bizzLen);

    //             wBuffer[wBufLenght] = rBuffer[index];
    //             ++wBufLenght; 
    //             continue;
    //         }
    //     }
    //     else {

            
    //         while ((index - counter < lenght)) {

                
    //             wBuffer[wBufLenght] = rBuffer[index - counter];
    //             ++wBufLenght;
    //             index++;
    //         }
    //         index--; 
    //         continue;
    //     }

    // }

    // printf ("%s\n", wBuffer);
    // return wBufLenght;
}
//-----------------------------------------------------------
//-----------------------------------------------------------
int WriteBizzBuzz (char* buffer, const char* word, int wBufLenght, const int lenWord) {

    assert (buffer);

    for (int index = 0; index < lenWord; ++index) {

        buffer[wBufLenght] = word[index];
        ++wBufLenght;
    }

    return wBufLenght;
}
//-----------------------------------------------------------
//-----------------------------------------------------------
int NumCases (char* wBuffer, char* wordPtr, int wBufLenght, int sum, int lastNum) {

    int index = 0;
    assert (wordPtr);
    int left_tmp = 0;

    if (((sum % 3) == 0) && (lastNum == 5 || lastNum == 0)) {

        wBufLenght = WriteBizzBuzz (wBuffer, "BizzBuzz", wBufLenght, bizzbuzzLen);
        return wBufLenght;
    }

    if ( (lastNum == 5 || lastNum == 0)) {

        wBufLenght = WriteBizzBuzz (wBuffer, "Buzz", wBufLenght, buzzLen);
        return wBufLenght;
    }

    if ( (sum % 3) == 0) {

        wBufLenght = WriteBizzBuzz (wBuffer, "Bizz", wBufLenght, bizzLen);
        return wBufLenght;
    }
    
    return (WordWrite (wBuffer, wordPtr, wBufLenght, &left_tmp));
}
//-----------------------------------------------------------
//-----------------------------------------------------------
int WordWrite (char* wBuffer, char* wordPtr, int wBufLenght, int* index) {

    int counter = 0;
    assert (wordPtr);

    while (wordPtr[counter] && !(isspace (wordPtr[counter]))) {

        wBuffer[wBufLenght] = wordPtr[counter];
        ++(*index);
        ++counter;
        ++wBufLenght;
    }
    return wBufLenght;
}