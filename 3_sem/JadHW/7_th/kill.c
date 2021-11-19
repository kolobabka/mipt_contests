#include <sys/types.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <sys/types.h>
#include <signal.h> 
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

// Написать программу, которая переопределяет SIGUSR1 и SIGUSR2 

typedef void (*sh) (int);
void handler (int signal);

int main () {

    printf ("Pid = %d\n", getpid ());
    // sleep (1);

    struct sigaction action;

    action.sa_handler = handler;
    sigemptyset (&action.sa_mask);

    action.sa_flags = 0;

    sigaction (SIGUSR1, &action, NULL);
    sigaction (SIGUSR2, &action, NULL);

    while (1)
        sleep (1);

    return 0;
}

void handler (int signal) {

    // printf ("Hello\n");

    // printf ("%d\n", SIGUSR1);
    // printf ("%d\n", signal);
    

    if (signal == SIGUSR2)
        printf ("is the capital of Great Britan\n");

    else if (signal == SIGUSR1)
    {
        printf ("London ");
        fflush(stdout);
    }
    
    // sleep (1);
}