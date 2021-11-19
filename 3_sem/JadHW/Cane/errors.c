#include "cane.h"
//-----------------------------------------------------------
//-----------------------------------------------------------
signed char ArgError (int argc, char** argv) {

    if (argc < 2) {

        printf ("Arguments are not found!\n");
        return 0;
    }

    if (argc > 2) {

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
        return 1;
    }

    return 0;
}