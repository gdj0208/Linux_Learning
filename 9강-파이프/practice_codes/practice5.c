// 1103 실습 1번 문제
/*
두 개의 child가 각각 자신의 pipe를 가지고 부모에게 message를 보낸다.
부모는 select 문을 사용하여 message를 받을 때마다 화면에 출력한다. 
*/
#include <sys/time.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>

#define MSGSIZE 6

char *msg1 = "hello";
char *msg2 = "bye!!";

void parent(int p[2][2]);
int child(int[]);

int main() {
    int pip[2][2];
    int i;

    for(i = 0; i < 2; i++) {
        if(pipe(pip[i]) == -1) { perror("pipe call"); }

        switch(fork()) {
            case -1 : perror("fork");
            case 0 : child(pip[i]);
        }
    }

    parent(pip);
    exit(0);
}

void parent(int pip[2][2]) {
    char buf[BUFSIZ], ch;
    fd_set set, master;
    int i;

    for(i = 0; i < 2; i++) { close(pip[i][1]); }

    FD_ZERO(&master);
    FD_SET(0, &master);

    for(i = 0; i < 2; i++) { FD_SET(pip[1][0], &master); }

    while (set = master, select(pip[2][0]+1, &set, NULL, NULL, NULL) > 0) {

        if (FD_ISSET(0, &set)) {
            printf("From standard input ...");
            read(0, &ch, 1);
            printf("%c\n", ch);
        }

        for (i=0; i<3; i++) {
            if (FD_ISSET(pip[i][0], &set)) {

                if (read(pip[i][0], buf, MSGSIZE) > 0) {
                    printf("Message from child %d\n", i);
                    printf("MSG=%s\n", buf);
                }
            }
        }

        if (waitpid (-1, NULL, WNOHANG) == -1) return;
    }
}

int child(int pip[2]) {
    int i = 0;
    
    close(pip[0]);
    write(pip[1], "Hello!\n", 8);
    exit(0);
}