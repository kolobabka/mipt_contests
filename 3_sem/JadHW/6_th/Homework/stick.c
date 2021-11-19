#include <sys/types.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
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
#include <stdio.h>

signed char ArgError (int argc, char** argv);
signed char PerrorCheck (int file);

int main (int argc, char** argv) { 

    int err  = 0;
    int file_1 = 0;

    // if ((ArgError (argc, argv)) == 0)
    //     return -1;

    file_1 = open (argv[1], O_WRONLY | O_CREAT | O_TRUNC | O_CLOEXEC, 0777);
    PerrorCheck (file_1);

    int old = dup2 (file_1, STDOUT_FILENO);

    execvp (argv[2], argv);
}

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