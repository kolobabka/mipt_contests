#include "bizzbuzz.h"
//-----------------------------------------------------------
//-----------------------------------------------------------
int main (int argc, char** argv) {

    int file_1 = 0;
    int file_2 = 0;

    if (ArgError (argc, argv) == 0) 
        return -1;

    file_1 = open (argv[1], O_RDONLY);
    PerrorCheck (file_1);
    file_2 = open (argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0777);
    PerrorCheck (file_2);
    
    BizzBuzzer (file_1, file_2, argv);


    close (file_1);
    close (file_2);

    return 0;
}