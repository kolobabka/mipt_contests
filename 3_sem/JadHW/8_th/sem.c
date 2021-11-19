// #include <sys/types.h>
// #include <sys/ipc.h>
// #include <sys/sem.h>
// #include <sys/shm.h>

// int semget (key_t key, int nsems, int flags);
// key_t ftok (const char *pathname, int proj_id);
// int semctl (int semid, int semnum, int cmd, ...);
// struct sembuf {

//   unsigned int sem_num; // the number of sem
//   short sem_op; //operation
//   short sem_flags; // flags for the current operation 
// };
// int semop  (int semid, struct sembuf *sops, size_t nsops);
// int shmget(key_t key, size_t size, int shmflg); //IPC_CREATE
// void *shmat(int shmid, const void *shmaddr, int shmflg); 
// //shmaddr ---> NULL
// int shmdt(const void *shmaddr);
// int shmctl(int shmid, int cmd, struct shmid_ds *buf);


// //semid -- the ID of the sem, semnum -- an amount of sems, cmd -- a command \
// (f.e IPC_SET, IPC_DEL, SETVAL) \
// THE ESSENTIAL POINTS OF SYSTEM PROGRAMMING : \
//       1) 

// int main () { 


// }

#include <fcntl.h>
#include <sys/stat.h>
#include<stdio.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/types.h>
#include<string.h>
#include<errno.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include <assert.h> 

#define BUF_SIZE 100000
#define SHM_KEY 0x1234

struct shmseg {
    int cnt;
    int complete;
    char buf[BUF_SIZE];
};
int fill_buffer(const char * fileName, char * bufptr, int size);

int size_of_text (char* const text_name)
{
    assert (text_name);

    struct stat size;
    stat (text_name, &size);

    return size.st_size;
}


int main(int argc, char *argv[]) {
    int shmid, numtimes;
    struct shmseg *shmp;
    char *bufptr;
    int size;
    shmid = shmget(SHM_KEY, sizeof(struct shmseg), 0644|IPC_CREAT);
    if (shmid == -1) {
        perror("Shared memory");
        return 1;
    }

    // Attach to the segment to get a pointer to it.
    shmp = shmat(shmid, NULL, 0);
    if (shmp == (void *) -1) {
        perror("Shared memory attach");
        return 1;
    }

    /* Transfer blocks of data from buffer to shared memory */
    bufptr = shmp->buf;
    size = size_of_text (argv[1]);

    shmp->cnt = fill_buffer(argv[1], bufptr, size);
    shmp->complete = 0;
    printf("Writing Process: Shared Memory Write: Wrote %d bytes\n", shmp->cnt);
    // bufptr = shmp->buf;
    // sleep(10);

    shmp->complete = 1;

    if (shmdt(shmp) == -1) {
        perror("shmdt");
        return 1;
    }

    // if (shmctl(shmid, IPC_RMID, 0) == -1) {
    //     perror("shmctl");
    //     return 1;
    // }
    printf("Writing Process: Complete\n");
    return 0;
}

int fill_buffer(const char * fileName, char * bufptr, int size) {

    int fd;
    fd = open (fileName, O_RDONLY);

    read (fd, bufptr, size);

    write (fd, bufptr, size);

    return size;
}