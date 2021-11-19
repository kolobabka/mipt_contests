#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h>
#include <fcntl.h>

#include <errno.h>

struct mymsgbuf {

    long mtype;
    int request;
    char buf [100];

} msg;

int send_msg (int qid, struct mymsgbuf* qbuf) {

    int result = 0;
    int length = 0;

    length = sizeof (struct mymsgbuf) - sizeof (long);

    if ((result = msgsnd (qid, qbuf, length, 0)) == -1)
        return -1;
    
    return result;

}

int open_queue(key_t key) {
	int qid = 0;

	if ((qid = msgget (key, IPC_CREAT | 0660)) == -1)
		return -1;
    
	return (qid);
}

int main (int argc, char** argv) {

    int qid = 0;
    key_t msgKey = 0;
    
    char buf[100] = {};
    int c;
    int index = 0;
    
    while ( (c = getchar()) != '\n')
    {
    	buf[index] = c;
    	index++;
    }
    

    msgKey = ftok (".", 'm');
    
    if ((qid = open_queue (msgKey)) == -1) {
        perror ("open queue error");
        return errno;
    }

    msg.mtype   = 1;
    msg.request = 1;
    
    
    
        sprintf (msg.buf, "%s", buf);
       

    printf ("%s\n", msg.buf);

    int resSnd = 0;
    if ((resSnd = send_msg (qid, &msg)) == -1) {
        perror ("send message error");
        return resSnd;
    }

    return 0;

}
