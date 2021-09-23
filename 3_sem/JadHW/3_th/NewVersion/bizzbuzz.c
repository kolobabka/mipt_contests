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

    long long totlength  = 0ULL;
    long long length     = 1ULL;

    char rBuffer[RSIZE] = {0};
    char wBuffer[WSIZE] = {0};
    
    long long wBuflength = 0;

    totlength = SizeText (argv[1]);   

    while (totlength > 0 && length > 0) {

        length = read (file_1, rBuffer, RSIZE);
        if (PerrorCheck (length) == 0) 
            return;

        length = SepParsNumbers (file_1, file_2, rBuffer, length, totlength);
        totlength -= length;
        printf ("LLLLENGTH = %lld\n", length);
        printf ("totLength = %lld\n", totlength);
    }

}
//-----------------------------------------------------------
//-----------------------------------------------------------

int SepParsNumbers (int file_1, int file_2, const char* rBuffer, long long length, long long totLength) {
    
    int delMe       = 0;
    int descriptor  = 0;
    long long shift = 0;
    long long index = 0;
    int sum         = 0;
    int offset      = 0;
    int lastNum     = 0;
    char symb       = 'A';

    while (index < length) {

        if (isspace (rBuffer[index])) {

            descriptor = write (file_2, rBuffer + index, 1);
            if (PerrorCheck (descriptor) == 0) 
                return 1;
            
            
            ++index;
            continue;
        }

        if (rBuffer[index] == '-') {

            shift++;
            index++;
        

            if (index < length && isspace (rBuffer[index])) {

                descriptor = write (file_2, rBuffer + index - 1, 1);
                if (PerrorCheck (descriptor) == 0) 
                    return 1;
                shift = 0;
                continue;
            }
        }



        if (isdigit (rBuffer[index])) {

            lastNum = rBuffer[index] - '0';
            sum += lastNum;
            sum %= 3;
            ++shift;
            ++index;
        }

        if (index >= length) {
            
            long long lastShift = 0;
            symb = rBuffer[index - 1];
            lastShift = shift;
            if (symb == '-') {

                descriptor = read (file_1, &symb, 1);
                delMe++;
                if (PerrorCheck (descriptor) == 0) 
                    return 1;

                if ((isspace (symb)) || descriptor == 0) {

                    offset = lseek (file_1, -1, SEEK_CUR);
                    write (file_2, rBuffer + index - 1, 1);
                }
            }
            symb = rBuffer[index - 1];

            while (!(isspace(symb))) {
                
                descriptor = read (file_1, &symb, 1);
                delMe++;
                if (PerrorCheck (descriptor) == 0) 
                    return 1;
                
                if (descriptor > 0)
                    ++shift;

                if (isspace (symb) || descriptor == 0) {

                    offset = NumCases (rBuffer, sum, lastNum, shift, file_1, file_2);  
                    if (offset == -1) {
                        
                        lseek (file_1, -shift, SEEK_CUR);
                        for (int i = 0; i < shift; i++) {

                            descriptor = read (file_1, &symb, 1);
                            delMe++;
                            if (PerrorCheck (descriptor) == 0) 
                                return 1;

                            descriptor = write (file_2, &symb, 1);
                            if (PerrorCheck (descriptor) == 0) 
                                return 1;
                        }
                    }
                    if (offset == 0 && descriptor != 0) {

                        descriptor = write (file_2, &symb, 1);
                        if (PerrorCheck (descriptor) == 0) 
                            return 1;
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
                        delMe++;
                        shift++;
                        if (descriptor > 0)
                            descriptor = write (file_2, &symb, 1);
                        else 
                            return index + shift - lastShift;
                        
                    
                    } 
                    printf ("DelMe = %d\n", delMe);
                    return index + shift - lastShift;
                }
            }
        }

        if (index < length && isspace (rBuffer[index])) {

            offset = NumCases (rBuffer, sum, lastNum, shift, file_1, file_2);

            if (offset == 0) {

                shift = 0; 
                sum = 0;
                continue;
            }

            descriptor = write (file_2, rBuffer + index - shift, shift); 
            if (PerrorCheck (length) == 0) 
                return 1;
                
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

long long NumCases (const char* rBuffer, const int sum, const int lastNum, long long shift, int file_1, int file_2) {

    int descriptor = 0;
    int offset     = 0;
    assert (rBuffer);

    if (offset == 1L) {

        printf ("Error!\n");
        return 1;
    }

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

    return -1;
}