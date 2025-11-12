

#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    int shmid, i;
    char *shmaddr;

    
    shmid = shmget(1658, 1024, IPC_CREAT | 0644);

    for(i = 0; i < 10; i++) {
        
        shmaddr = shmat(shmid, NULL, 0);
        printf("%s\n", shmaddr);

        
        if(strcmp(argv[1], "1") == 0) { strcpy(shmaddr, "Unix"); }
        else { strcpy(shmaddr, "Programming"); }
        shmdt(shmaddr);

        sleep(1);
    }
    shmdt(shmaddr);
    shmctl(shmid, IPC_RMID, NULL);
    
}