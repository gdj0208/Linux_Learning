/*
두개의 부프로세스를 생성하는 부분을 작성하고, 
생성된 각각의 부 프로세스들이 그 자신의 부프로세스를 하나씩 생성하는 프로그램을 작성하라
*/

#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>

void makeSub(int num, int level) {
    if(level > 1) { return; }
    
    pid_t pid1, pid2;

    pid1 = fork();
    pid2 = fork();
    
    printf("sub %d : pid %d\n", 2*num, getpid());
    printf("sub %d\n", 2*num+1, getpid());

    makeSub(2*num, level+1);
    makeSub(2*num + 1, level+1);
}

int main(int argc, char *argv[]) {
    makeSub(1, 0);
}