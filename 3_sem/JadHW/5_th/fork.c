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

signed char PerrorCheck (int file);
void Inverse (char* buf, int index);

int main () {

    pid_t pid = 0;  
    int file = 0;
    int err = 0;
    char buf[100] = {0};
    char pBuf[100] = {0};
    

    file = open ("Pids", O_WRONLY | O_CREAT | O_TRUNC, 0777);
    if ((PerrorCheck (file)) == 0)
        return -1;

    for (int i = 0; i < 1024; i++) {

        pid = fork ();
        
    

        if (pid == 0) {

            pid_t gottenPid = 0;
            pid_t pPid = 0;
            gottenPid = getpid ();
             
            
            printf ("PPID = %d\n", pPid);
            int index = 0;
            int pIndex = 0;

            index = sprintf (buf, "%d", gottenPid);

            buf[index] = '\n';

            err = write (file, "pid ", strlen ("pid "));
            err = write (file, buf, index + 1);

            pIndex = sprintf (pBuf, "%d", pPid);

            

            err = write (file, "ppid ", strlen ("ppid "));

            pBuf[pIndex] = '\n';

            err = write (file, pBuf, pIndex + 1);
            err = write (file, " ", 1);

            return 0;
        }

        else {
            
            
        }
        
    }


        
    return 0;
}

signed char PerrorCheck (int file) {

    if (file == -1) {

        perror ("File open error:");
        return 0;
    }

    return 1;
}

void Inverse (char* buf, int index) {

    char* tmp = NULL;

    tmp = (char*) calloc (index, sizeof (char));

    for (int i = 0; i < index; i++) {

        tmp[i] = buf[index - i]; 
    }

    for (int i = 0; i < index; i++) {

        buf[i] = buf[i]; 
    }

    free (tmp);
}