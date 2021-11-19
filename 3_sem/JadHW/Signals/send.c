#include "signals.h"
//-----------------------------------------------------------
//-----------------------------------------------------------
static char blockSend = 1;
//-----------------------------------------------------------
//-----------------------------------------------------------
static off_t SizeText (const char* textName) {

    struct stat size;
 	stat (textName, &size);

    return size.st_size;
}
//-----------------------------------------------------------
//-----------------------------------------------------------
static char SendSize (pid_t recievePid, off_t textSize) {

    union sigval value = {};
    value.sival_int = (int) textSize;

    if (PerrorCheck (sigqueue (recievePid, SIGUSR2, value))) 
        return SIGQUEUE_ERR;
    
    return NO_ERR;
}
//-----------------------------------------------------------
//-----------------------------------------------------------
static void UnblockSend (int sig) {

    if (sig == SIGUSR1)
        blockSend = 0;
}
//-----------------------------------------------------------
//-----------------------------------------------------------
static char SendText (pid_t recievePid, const char* buffer, int readenSize) {

    ZeroPointer (buffer);
    union sigval value = {};

    while (readenSize) {
        
        blockSend = 1;
        struct timespec tw = {0, 1000000};

        if (readenSize >= 4) {

            for (int i = 0; i < 4; ++i) {

                value.sival_int |= ((int) buffer[i]) << 8 * (sizeof (int) - i - 1);

            }

            if (PerrorCheck (!sigqueue (recievePid, SIGUSR1, value)))
                return SIGQUEUE_ERR;
            value.sival_int = 0;
            readenSize -= 4;

            buffer += 4;
        }
        else {

            for (int i = 0; i < readenSize; ++i) {

                value.sival_int |= ((int) buffer[i]) << 8 * (sizeof (int) - i - 1);
            }

            for (int i = readenSize; i < 4; ++i) {

                value.sival_int |= ((int)0xFF) << 8 * (sizeof (int) - i - 1);
            }
            
            if (PerrorCheck (!sigqueue (recievePid, SIGUSR1, value)))
                return SIGQUEUE_ERR;

            while (blockSend) {
                if (PerrorCheck (kill (recievePid, 0)))
                    return RECIEVE_ERR;
                nanosleep (&tw, NULL);

            }
            
            return NO_ERR;
        }

        while (blockSend) {
            if (PerrorCheck (kill (recievePid, 0)))
                return RECIEVE_ERR;
            nanosleep (&tw, NULL);
        }
    }

    return NO_ERR;
}
//-----------------------------------------------------------
//-----------------------------------------------------------
static char StartSend (int file, char** argv, off_t textSize) {

    ZeroPointer (argv[1]);
    struct sigaction sendSizeSig = {};
    sendSizeSig.sa_handler = UnblockSend;
    sigemptyset (&(sendSizeSig.sa_mask));

    sigaction (SIGUSR1, &sendSizeSig, NULL);

    pid_t recievePid = (pid_t) atoi (argv[2]);


    if (SendSize (recievePid, textSize))
        return SIGQUEUE_ERR;
    
    while (blockSend) 
        nanosleep (&tw, NULL);
    

    char buffer[SIZE_OF_BUF] = {};

    int readenSize = read (file, buffer, SIZE_OF_BUF);

    printf ("\n");
    if (PerrorCheck (readenSize))
        return FILE_ERR;
    
    while (textSize) {

        if (SendText (recievePid, buffer, readenSize))
            return SEND_ERR;

        textSize -= readenSize;

        readenSize = read (file, buffer, SIZE_OF_BUF);
    }

    return NO_ERR;
}
//-----------------------------------------------------------
//-----------------------------------------------------------
int main (int argc, char** argv) {
    
    clock_t begin = clock ();
    if (ArgError (argc, 3)) 
        return ARG_ERR;

    int file = open (argv[1], O_RDONLY);
    if (PerrorCheck (file))
        return FILE_ERR;
    
    off_t textSize = SizeText (argv[1]);  

    if (StartSend (file, argv, textSize)) {

        printf ("Sending error\n");
        if (PerrorCheck (close (file)))
            return FILE_ERR | SEND_ERR;

        return SEND_ERR;
    }

    if (PerrorCheck (close (file)))
        return FILE_ERR;

    clock_t end = clock ();

    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf ("Speed: %f MB / s\n", (textSize / time_spent) / 1e6);

    return NO_ERR;
}
//-----------------------------------------------------------
//-----------------------------------------------------------