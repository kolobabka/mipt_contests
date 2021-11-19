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
#define MAX_HANDLE_SZ 1000
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

int read_msg (int qid, struct mymsgbuf* qbuf, long type) {

    qbuf->mtype = type;
    
    int result = 0;
    result = msgrcv (qid, (struct msgbuf*)qbuf, MAX_HANDLE_SZ, type, 0);

    return result;

}

int main (int argc, char** argv) {

    int qid     = 0;
    key_t msgKey   = ftok (".", 'm');

    if ((qid = open_queue (msgKey)) == -1) {
        perror ("open queue error");
        return errno;
    }

    struct mymsgbuf msg = {};
    read_msg (qid, &msg, 1);

    printf ("%s", msg.buf);

    return 0;

}
