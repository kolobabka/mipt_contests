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

const int size = 1024;

int main () {

    pid_t pid = 0;  
    int file = 0;
    int err = 0;
    char buf[100] = {0};
    

    file = open ("Pids", O_WRONLY | O_CREAT | O_TRUNC, 0777);
    if ((PerrorCheck (file)) == 0)
        return -1;

    for (int i = 0; i < size; i++) {

        pid_t retVal   = 0;
        int waitstatus = 0;
        int args       = 0;

        pid = fork ();
        if (pid == -1) {

            printf ("Pid error!");
            close (file);
            return -1;
        }
    

        if (pid == 0) {
            
            args = sprintf (buf, "MyPid = %d ParentPid = %d\n", getpid (), getppid ());

            err = write (file, buf, args);
            if ((PerrorCheck (err)) == 0)
                return -1;

            return 0;     
        }

        retVal = waitpid (pid, &waitstatus, 0);

        if (!WIFEXITED (waitstatus) || WEXITSTATUS(waitstatus))
        {
            close (file);
            return -1;
        }

        args = sprintf (buf, "ChildPid = %d, retVal = %d\n", retVal, waitstatus);

        err = write (file, buf, args);
        if ((PerrorCheck (err)) == 0) {

            close (file);
            return -1; 
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
