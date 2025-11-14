#include <sys/types.h>
#include <signal.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

main(int argc, char **argv) {
    key_t key;
    int shmid, a;
    void *shmaddr;
    char buf[1024];

    shmid = shmget(0777, 1024, 0);

    shmaddr = shmat(shmid, NULL, 0);

    for(a=0; a<4; a++) {
        buf[0] = '\0';
        if(a == 3)
            sprintf(buf, "q\n");
        else
            sprintf(buf, "Message %d\n", a);
        strcpy(shmaddr, buf);

        kill(atoi(argv[1]), SIGUSR1);
        sleep(1);
    }
    system("ipcs");
    shmdt(shmaddr);
}
