#include "signals.h"
//-----------------------------------------------------------
//-----------------------------------------------------------
signed char ArgError (int argc, int expectedNum) {

    if (argc < expectedNum) {

        printf ("Arguments are not found!\n");
        if (expectedNum == 3)
            printf ("Please point also input file or pid of the recieving process\n");
        else
            printf ("Please point input file\n");
        return ARG_ERR;
    }

    if (argc > expectedNum) {

        printf ("Too many arguments!\n");
        return ARG_ERR;
    }

    return NO_ERR;
}

//-----------------------------------------------------------
//-----------------------------------------------------------
signed char PerrorCheck (int file) {

    if (file == -1) {

        perror ("Error:");
        return FILE_ERR;
    }

    return NO_ERR;
}