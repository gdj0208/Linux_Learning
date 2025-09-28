#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

int main(int argc, char *argv[]) {
    int rfd, wfd, n;
    char buf[256];
 
    if(argc != 3) {
        printf("Usage: ex1 src target\n");
        exit(1);
    }
    rfd = open(argv[1], O_RDONLY);
    if(rfd == -1) {
        perror("Open ");
        exit(1);
    }
    wfd = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if(wfd == -1) {
        perror("Create ");
        exit(1);
    }

    while((n = read(rfd, buf, 5)) > 0)
        if(write(wfd, buf, n) != n) perror("Write");

    if(n == -1) perror("Read");
    
    close(rfd);
    close(wfd);
}

