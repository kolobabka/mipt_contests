#include "signals.h"
//-----------------------------------------------------------
//-----------------------------------------------------------
static off_t textSize     = 0;
static pid_t sendPid      = 0;
static char buffer[4]     = {};
static int file           = 0;
//-----------------------------------------------------------
//-----------------------------------------------------------

static void GetText (int sig, siginfo_t* sigInfo, void* uContest) {


    int state = 4;
    if (uContest == NULL) {

        printf ("Zero uContest\n");
        return;
    }
    if (sigInfo == NULL) {

        printf ("Zero sigInfo\n");
        return;
    }

    pid_t pidToSend = sigInfo->si_pid;

    for (int i = 0; i < 4; ++i) {
        
        char curSigElem = (char) (sigInfo->si_value.sival_int >> 8 * (sizeof (int) - i - 1));
        if (curSigElem == (char) 0xFF) {

            state = i;
            break;
        }
        buffer[i] = curSigElem;
        --textSize;
        if (textSize == 0) {

            if (PerrorCheck (write (file, buffer, i + 1)))
                return;
            if (PerrorCheck (kill (pidToSend, SIGUSR1))) 
                return;

            return;
        }
    }

    if (PerrorCheck (write (file, buffer, state)))
        return;

    if (PerrorCheck (kill (pidToSend, SIGUSR1))) 
        return;
}

static void GetSize (int sig, siginfo_t* sigInfo, void* uContest) {

    if (uContest == NULL) {

        printf ("Zero uContest\n");
        return;
    }
    if (sigInfo == NULL) {

        printf ("Zero sigInfo\n");
        return;
    }
    textSize = (off_t) sigInfo->si_value.sival_int;
    sendPid = sigInfo->si_pid;
   
    if (PerrorCheck (kill (sigInfo->si_pid, SIGUSR1))) 
        return;
}

static char StartRecieve () {

    printf ("Recieving process pid = %d\n", getpid ());

    struct sigaction recieveSizeSig = {};
    recieveSizeSig.sa_sigaction = GetSize;
    sigemptyset (&(recieveSizeSig.sa_mask));
    recieveSizeSig.sa_flags = SA_SIGINFO;

    sigaction (SIGUSR2, &recieveSizeSig, NULL);

    while (textSize == 0)  {
        
        nanosleep (&tw, NULL);
    }
    
    struct sigaction recieveTextSig = {};
    recieveTextSig.sa_sigaction = GetText;
    sigemptyset (&recieveTextSig.sa_mask);
    recieveTextSig.sa_flags = SA_SIGINFO;

    sigaction(SIGUSR1, &recieveTextSig, NULL);

    while (textSize) {
        
        
        if (PerrorCheck (kill (sendPid, 0)))
            return SEND_ERR;

        nanosleep (&tw, NULL);
    }
    

    return NO_ERR;
}
//-----------------------------------------------------------
//-----------------------------------------------------------
int main (int argc, char** argv) {

    if (ArgError (argc, 2))
        return ARG_ERR;

    file = open (argv[1], O_WRONLY | O_CREAT | O_TRUNC, 0666);
    if (PerrorCheck (file))
        return FILE_ERR;
    
    if (StartRecieve (file)) {

        if (PerrorCheck (close (file)))
            return FILE_ERR | RECIEVE_ERR;

        return RECIEVE_ERR;
    }

    return NO_ERR;
}