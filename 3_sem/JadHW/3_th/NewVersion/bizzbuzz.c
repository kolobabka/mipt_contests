#include "bizzbuzz.h"
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
signed char ArgError (int argc, char** argv) {

    if (argc < 3) {

        printf ("Arguments are not found!\n");
        return 0;
    }

    if (argc > 3) {

        printf ("Too many arguments!\n");
        return 0;
    }

    if (strcmp (argv[1], argv[2]) == 0) {

        printf ("The identity files!\n");
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

    long long totLenght  = 0ULL;
    long long lenght     = 0ULL;

    char rBuffer[RSIZE] = {0};
    char wBuffer[WSIZE] = {0};
    
    long long wBufLenght = 0;

    totLenght = SizeText (argv[1]);   
    
    printf ("%ld\n", totLenght);

    while (totLenght > 0) {

        lenght = read (file_1, rBuffer, RSIZE);
        if (PerrorCheck (lenght) == 0) 
            return;

        lenght = SepParsNumbers (file_1, file_2, rBuffer, wBuffer, lenght, totLenght);
        totLenght -= lenght;
        printf ("totLenght = %ld\n", totLenght);
    }

}
//-----------------------------------------------------------
//-----------------------------------------------------------
long long SepParsNumbers (int file_1, int file_2, const char* rBuffer, char* wBuffer, const long long lenght, const long long totLenght) {

    long long wBufLenght = 0ULL;
    long long shift      = 0Ull;
    long long index      = 0ULL;
    int descriptor    = 0;
    int lastNum       = 0;
    int offset        = 0;
    int sum           = 0;
    
    char symbol       = 0;

    while (index < lenght) {

        if (isspace (rBuffer[index])) {

            descriptor = write (file_2, rBuffer + index, 1);
            if (PerrorCheck (descriptor) == 0) 
                return 1;
            ++index;
            
            continue;
        }

        
        if (index < lenght && isdigit (rBuffer[index])) {

            lastNum = rBuffer[index] - '0';
            sum += lastNum;
            sum %= 3;
            ++shift;
            ++index;
        }

        if (index >= lenght) {

            index = ToFile (file_1, file_2, shift, index - shift, totLenght);
            return lenght + index;
        }

        if (isspace (rBuffer[index])) {

            NumCases (rBuffer, sum, lastNum, index, shift, file_1, file_2);
            shift = 0;
            continue;
        }

        if (!(isdigit (rBuffer[index]))) {
            
            offset = lseek (file_1, -(lenght - index + shift), SEEK_CUR);

            shift = WordWrite (file_1, file_2, shift);
            index += shift;
        }

    }
    

    return index;
}
//-----------------------------------------------------------
//-----------------------------------------------------------
int ToFile (int file_1, int file_2, long long shift, long long index, const long long totLenght) {


    // RETURN CORRECT SHIFT!
    char symb         = ' ';
    int descriptor    = 0;
    int offset        = 0;
    int lastNum       = 0;
    int sum           = 0;
    int prevShift     = 0;

    prevShift = shift;

    offset = lseek (file_1, -shift, SEEK_CUR);
    if (offset == 1L) {

        printf ("Error!\n");
        return 1;
    }

    shift = -shift - 1;

    while (index < totLenght) {

        descriptor = read (file_1, &symb, 1);
        if (PerrorCheck (descriptor) == 0) 
            return 1;
        
        if (index < totLenght && isdigit (symb)) {

            lastNum = symb - '0';
            sum += lastNum;
            sum %= 3;
            ++shift;
            ++index;
        }

        if (isspace (symb)) {
            
            if (((sum % 3) == 0) && (lastNum == 5 || lastNum == 0)) {

                descriptor = write (file_2, "BizzBuzz", bizzbuzzLen);
                if (PerrorCheck (descriptor) == 0) 
                    return 1;

                return shift;
            }

            if ((lastNum == 5 || lastNum == 0)) {

                descriptor = write (file_2, "Buzz", buzzLen);
                if (PerrorCheck (descriptor) == 0) 
                    return 1;

                return shift;
            }

            if ((sum % 3) == 0) {

                descriptor = write (file_2, "Bizz", bizzLen);
                if (PerrorCheck (descriptor) == 0) 
                    return 1;

                return shift;
            }

            offset = lseek (file_1, -(shift + prevShift), SEEK_CUR);
            if (offset == 1L) {

                printf ("Error!\n");
                return 1;
            }

            for (int i = 0; i < shift + prevShift; i++) {

                descriptor = read (file_1, &symb, 1);
                if (PerrorCheck (descriptor) == 0) 
                    return 1;

                descriptor = write (file_2, &symb, 1);
                if (PerrorCheck (descriptor) == 0) 
                    return 1;
            }

            return shift;
        }
        if (!(isdigit(symb))) {
            
            offset = lseek (file_1, -(shift + prevShift + 1), SEEK_CUR);
            if (offset == 1L) {

                printf ("Error!\n");
                return 1;
            }

            shift = 0;
            while (!(isspace(symb))) {
                ++shift;
                descriptor = read (file_1, &symb, 1);
                if (PerrorCheck (descriptor) == 0) 
                    return 1;

                descriptor = write (file_2, &symb, 1);
                if (PerrorCheck (descriptor) == 0) 
                    return 1;
            }
            return (shift - prevShift); 
        }
        
    }
}

//-----------------------------------------------------------
//-----------------------------------------------------------
long long NumCases (const char* rBuffer, const int sum, const int lastNum, const long long index, long long shift, int file_1, int file_2) {

    int descriptor = 0;
    assert (rBuffer);

    if (((sum % 3) == 0) && (lastNum == 5 || lastNum == 0)) {

        descriptor = write (file_2, "BizzBuzz", bizzbuzzLen);
        if (PerrorCheck (descriptor) == 0) 
            return 1;

        return 0;
    }

    if ((lastNum == 5 || lastNum == 0)) {

        descriptor = write (file_2, "Buzz", buzzLen);
        if (PerrorCheck (descriptor) == 0) 
            return 1;

        return 0;
    }

    if ((sum % 3) == 0) {

        descriptor = write (file_2, "Bizz", bizzLen);
        if (PerrorCheck (descriptor) == 0) 
            return 1;

        return 0;
    }
    
    return (WordWrite (file_1, file_2, shift));
}
//-----------------------------------------------------------
//-----------------------------------------------------------
long long WordWrite (int file_1, int file_2, long long shift) {

    char symb = 'A';
    int index = 0;
    int descriptor = 0;

    shift = -shift;

    while (!(isspace(symb))) {
        ++shift;
        descriptor = read (file_1, &symb, 1);
        if (PerrorCheck (descriptor) == 0) 
            return 1;

        descriptor = write (file_2, &symb, 1);
        if (PerrorCheck (descriptor) == 0) 
            return 1;
    }
    return (shift); 

}