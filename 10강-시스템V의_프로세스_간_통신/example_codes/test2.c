#include <sys/msg.h>
#include <sys/shm.h>
#include <stdlib.h>
#include <stdio.h>

int main() {
    key_t key;
    int shmid;

    printf("공유 메모리 생성 전 : \n");
    system("ipcs -m");
    
    key = ftok("keyfile", 1);
    shmid = shmget(key, 1024, IPC_CREAT | 0644);

    printf("공유 메모리 생성 후 : \n");
    system("ipcs -m");
}