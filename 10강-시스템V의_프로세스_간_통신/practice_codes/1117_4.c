#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>


int main(int argc, char *argv[]) {
    pid_t pid;
    int pd;
    int *fp;

    pipe(pd);
    
    switch(pid = fork()) {
    case 0:
        child(argv[1], pd);
        break;
    case 1:
        break;
    default:
    }
}

void parent(int *fp, int pd[2]) {
    char *content;
    fp = open("tmp.txt", O_CREAT|O_WRONLY, 0644);

    close(pd[0]);
    read(pd[1], content, 32);

    write(1, content, strlen(content));
    write(fp, content, strlen(content));
}

void child(char *filename, int pd[2]) {
    char * content = "Tralalalero Trlalala";

    close(pd[1]);

    write(pd[0], content, strlen(content));
}