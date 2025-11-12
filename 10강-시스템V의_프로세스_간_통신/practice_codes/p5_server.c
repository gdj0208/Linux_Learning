
#include <signal.h>
#include <sys/mman.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

void handler(int signo) {

}

int main() {
    int shmid;
    void *shmaddr;
    char buf[BUFSIZ];
    sigset_t mask;

    shmid = shmget(1568, 1024, IPC_CREAT | 0644);

    sigfillset(&mask);
    sigdelset(&mask, SIGUSR1);
    sigset(SIGUSR1, handler);

    printf("Server(%d) : \n", getpid());
    while(1) {
        sigsuspend(&mask);
        shmaddr = shmat(shmid, NULL, 0);
        strcpy(buf, shmaddr);
        if (strcmp(buf, "q") == 0) { break; }

        printf("%s\n", buf);
        sleep(1);
    }

    shmdt(shmaddr);
    shmctl(shmid, IPC_RMID, NULL);
}
