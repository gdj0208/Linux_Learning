/*
1. practice1을 변형해 명령행 인자로 받은 명령을 자식 프로세스가 부모 프로세스에게 보냄
2. 부모 프로세스가 man 명령을 수행하도록 pipe() 사용해 구현

execlp("man", "man", buf, (char*)null) 사용
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[]) {
    FILE *fp;
    int fd[2];
    char buf[BUFSIZ];
    pid_t pid;

    sprintf(buf, "man %s", argv[1]);

    fp = popen(buf, "r");
    if(fp == NULL) { perror("popen error!\n"); exit(0); }

    if(pipe(fd) == -1) { perror("pipe"); exit(1); }

    switch (pid = fork())
    {
    case 0:
        read(fd[1], buf, BUFSIZ);
        printf("%s\n", buf);
        break;
    case 1:
        execlp("man", "man", buf, (char*)NULL);
        break;
    default:
        perror("fork");
        exit(1);
    }

    while(fgets(buf, BUFSIZ, fp) != NULL) { puts(buf); }

    pclose(fp);
}
