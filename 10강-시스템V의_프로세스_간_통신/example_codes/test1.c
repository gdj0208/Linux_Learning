#include <sys/msg.h>
#include <stdlib.h>
#include <stdio.h>

int main() {
    key_t key;
    int msgid;

    key = ftok("keyfile", 1);
    msgid = msgget(key, IPC_CREAT | 0644);

    printf("IPC_RMID 실행 전\n");
    system("ipcs -q");

    // msgctl로 메시지 큐 제거
    msgctl(msgid, IPC_RMID, NULL);

    printf("IPC_RMID 실행 후\n");
    system("ipcs -q");
}