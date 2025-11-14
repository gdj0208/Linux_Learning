#include <sys/types.h>
#include <signal.h>
#include <sys/shm.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char cpid[6];
void handler(int dummy) {
    ;
}

main(int argc, char **argv) {
    key_t key;
    int shmid, pid;
    void *shmaddr;
    char buf[1024];
    sigset_t mask;

    if(argc != 2) {
        printf("Usage: ex3_client pid\n");
        exit(1);
    }
    shmid = shmget(0777, 1024, IPC_CREAT|0666);
    shmaddr = shmat(shmid, NULL, 0);

    sigfillset(&mask);
    sigdelset(&mask, SIGUSR1);
    sigdelset(&mask, SIGINT);
    sigset(SIGUSR1, handler);

    printf("Send Client's PID to Server\n");
    sprintf(shmaddr, "%d\0", getpid());
    kill(atoi(argv[1]), SIGUSR1);

    while(1) {
        sigsuspend(&mask);
        strcpy(buf, shmaddr);
        printf("Client received : %s\n", buf);
        if(buf[0] == 'q'){
        strcpy(shmaddr, "q");
        kill(atoi(argv[1]), SIGUSR1);
        break;
        }
        printf("Client send : ");
        fgets(buf, sizeof(buf), stdin);
        strcpy(shmaddr, buf);
        kill(atoi(argv[1]), SIGUSR1);
    }

    shmdt(shmaddr);
    shmctl(shmid, IPC_RMID, NULL);
}
