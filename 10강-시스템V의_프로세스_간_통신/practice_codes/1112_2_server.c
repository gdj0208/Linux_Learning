#include <sys/types.h>
#include <signal.h>
#include <sys/shm.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

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
    shmaddr = shmat(shmid, NULL, 0);

    sigfillset(&mask);
    sigdelset(&mask, SIGUSR1);
    sigdelset(&mask, SIGINT);
    sigset(SIGUSR1, handler);
    printf("Server wait for Client's PID\n");
    printf("Server PID : %d\n", getpid());
    sigsuspend(&mask);

    strcpy(buf, shmaddr);
    pid = atoi(buf);
    printf("Client's PID : %d\n", pid);
    strcpy(shmaddr, "Received PID\n");
    kill(pid, SIGUSR1);

    while(1) {
        sigsuspend(&mask);
        strcpy(buf, shmaddr);
        printf("Server received : %s\n", buf);
        if(buf[0] == 'q') {
            strcpy(shmaddr, "q");
            kill(pid, SIGUSR1);
            break;
        }
        printf("Server send : \n");
        fgets(buf, sizeof(buf), stdin);
        strcpy(shmaddr, buf);
        kill(pid, SIGUSR1);
    }

    shmdt(shmaddr);
    shmctl(shmid, IPC_RMID, NULL);
}
