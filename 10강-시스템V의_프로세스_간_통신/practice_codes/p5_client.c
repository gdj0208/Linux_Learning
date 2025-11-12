
#include <signal.h>
#include <sys/mman.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    int shmid;
    void *shmaddr;
    char buf[BUFSIZ];
    int i;

    char *msgs[] = {
    "Tralalalero Tralalala\n",
    "Bombardillo Crocodillo\n",
    "Brr Brr Phatapim\n",
    "q"
    };


    shmid = shmget(1568, 1024, 0);
    shmaddr = shmat(shmid, NULL, 0);
    
    for (i = 0; i < 4; i++) {
        strcpy(shmaddr, msgs[i]);
        printf("Client(%d) : %s\n", getpid(), msgs[i]);
        kill(atoi(argv[1]), SIGUSR1);
        sleep(2);
    }
    system("ipcs -mo");
    shmdt(shmaddr);
}
