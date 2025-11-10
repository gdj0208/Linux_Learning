/*
메시지 큐의 큐상 메시지수(msq_qnum), 
마지막으로 msgsnd수행한 프로세스의 식별번호 및 시간, 
마지막으로 msgrcv를 수행한 프로세스의 식별번호 및 시간을 출력하라
*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>




int main() {

    struct msqid_ds *mstat;
    key_t key;
    int msgid;

    struct msgbuf {
        long mtype;
        char mtext[80];
    }buff;

    
    if(msgid = msgget(1658, 0644 | IPC_CREAT) == -1) {
        perror("msgget");
        return 1;
    }
    if(msgctl(msgid, IPC_STAT, mstat) == -1) {
        perror("msgctl");
        return 1;
    }

    printf("Last send by proc %d at %s\n", mstat->msg_lspid, ctime(&mstat->msg_stime));

}