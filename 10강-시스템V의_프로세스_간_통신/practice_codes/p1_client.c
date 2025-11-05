#include <sys/msg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct msg_buffer {
    long message_type;
    char messages[80];
};

int main() {
    key_t key;
    int msgid;
    struct msg_buffer message;
    int i = 0;
    char *msg[3] = {
        "Test Message 1\n",
        "Test Message 3-1\n",
        "Test Message 3-2\n"
    };

   //key = ftok("keyfile", 1);

    msgid = msgget(0777, 0777 | IPC_CREAT);
    if(msgid == -1) {
        perror("msgget failed\n");
        exit(1);
    }


    for(i = 0; i < 3; i++) {
        message.message_type = i+1;
        strcpy(message.messages, msg[i]);

        if(msgsnd(msgid, &message.messages, sizeof(message.messages), IPC_NOWAIT) == -1) {
            perror("msgsnd failed\n");
            exit(1);
        }
    }
    
}
//ipcrm -q <msgid>