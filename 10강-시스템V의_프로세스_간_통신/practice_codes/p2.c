#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
#include <errno.h>

#define MSG_SIZE 80
struct msgbuf {
    long mtype;
    char mtext[MSG_SIZE];
};

int main(void) {
    int msgid, n;
    struct msgbuf msg;
    pid_t pid;

    msgid = msgget(1658, 0644 | IPC_CREAT);
    if (msgid == -1) {
        perror("msgget");
        return 1;
    }

    switch(pid = fork()){
    case 0 :
        memset(buff.mtext, 0, MSG_SIZE);

        while((n = read(0, msg.mtext, MSG_SIZE)) > 0) {
            if(!strncmp(msg.mtext, "bye", 3)) { msg.mtype - 2; }
            else { msg.mtype = 1; }

            if(msgsnd(msgid, &msg, n, 0) < 0) {
                perror("msgsnd");
                exit(1);
            }

            if(msg.mtype == 2) { exit(0); }
            else{ memset(buff.mtext, 0, MSG_SIZE); }
        }
        break;
    case 1:
        while((n = msgrcv(msgid, &msg, MSG_SIZE, 0, 0) > 0)) {
            if (msg.mtype == 1) { write(1, msg.mtext, strlen(msg.mtext) + 1); }
            else { break; }
        }
        break;   
    }

    return 0;
}