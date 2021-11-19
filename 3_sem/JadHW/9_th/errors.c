#include "message.h"
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