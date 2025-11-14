#include <sys/types.h>
#include <signal.h>
#include <sys/shm.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void handler(int dummy) {
    ;
}

main() {
    key_t key;
    int shmid, pid;
    void *shmaddr;
    char buf[1024];
    sigset_t mask;

    shmid = shmget(0777, 1024, IPC_CREAT|0666);

    sigfillset(&mask);
    sigdelset(&mask, SIGUSR1);
    sigset(SIGUSR1, handler);
    printf("Server wait for Client %d\n", getpid());

while(1) {
    sigsuspend(&mask);
    shmaddr = shmat(shmid, NULL, 0);
    strcpy(buf, shmaddr);
    printf("Server received : %s\n", buf);
    if(buf[0] == 'q') break;
}

    shmdt(shmaddr);
    shmctl(shmid, IPC_RMID, NULL);
}
