#include<stdio.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/types.h>
#include<string.h>
#include<errno.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include <fcntl.h>

// #define BUF_SIZE 100000
// #define SHM_KEY 0x1234

// struct shmseg {
//    int cnt;
//    int complete;
//    char buf[BUF_SIZE];
// };

// int main(int argc, char *argv[]) {
//    int shmid;
//    struct shmseg *shmp;
//    int fd;
//    shmid = shmget(SHM_KEY, sizeof(struct shmseg), 0644|IPC_CREAT);
//    if (shmid == -1) {
//       perror("Shared memory");
//       return 1;
//    }

//   char* buffer = "answer"; 
//   fd = open (buffer, O_WRONLY | O_TRUNC);

  
//    // Attach to the segment to get a pointer to it.
//    shmp = shmat(shmid, NULL, 0);
//    if (shmp == (void *) -1) {
//       perror("Shared memory attach");
//       return 1;
//    }
   
//    /* Transfer blocks of data from shared memory to stdout*/
//    while (shmp->complete != 1) {
//       write (fd, shmp->buf, shmp->cnt);

//       if (shmp->cnt == -1) {
//          perror("read");
//          return 1;
//       }
//       printf("Reading Process: Shared Memory: Read %d bytes\n", shmp->cnt);
//       sleep(10);
//    }
//    printf("Reading Process: Reading Done, Detaching Shared Memory\n");
//    if (shmdt(shmp) == -1) {
//       perror("shmdt");
//       return 1;
//    }
//    printf("Reading Process: Complete\n");
//    return 0;
// }

#define BUF_SIZE 100000
#define SHM_KEY 0x1234

struct shmseg {
   int cnt;
   int complete;
   char buf[BUF_SIZE];
};

int main(int argc, char *argv[]) {
   int shmid;
   struct shmseg *shmp;
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

   int fd = open ("answer", O_RDWR | O_TRUNC | O_CREAT);
   
   /* Transfer blocks of data from shared memory to stdout*/
   
  write (fd, shmp->buf, shmp->cnt);
  if (shmp->cnt == -1) {
    perror("read");
    return 1;
  }
  printf("Reading Process: Shared Memory: Read %d bytes\n", shmp->cnt);
  // sleep(6);
  
   printf("Reading Process: Reading Done, Detaching Shared Memory\n");
   if (shmdt(shmp) == -1) {
      perror("shmdt");
      return 1;
   }
   printf("Reading Process: Complete\n");
   return 0;
}