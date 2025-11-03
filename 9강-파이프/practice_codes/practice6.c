// 1103 실습 2번 문제

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int fd[2];
    pid_t pid;

    pipe(fd);

    switch (pid = fork())
    {
    case 0:
        close(fd[1]);
        
        execlp("wc", "wc", "-l", NULL);
        break;
    case 1:
        break;
    }

}