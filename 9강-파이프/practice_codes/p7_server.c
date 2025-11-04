#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int pd, n;
    char messages[BUFSIZ];
    char *GET = "From Server :";

    printf("Server ==========\n");

    if(mkfifo("./My_Fifo", 0666) == -1) {
        perror("mkfifo");
        exit(1);
    }

    if(pd = open("./My_Fifo", O_RDONLY) == -1) {
        perror("open");
        exit(1);
    }

    write(1, GET, strlen(GET));
    while((n = read(pd, messages, BUFSIZ)) > 0) {
        write(1, messages, n);
    }
    if(n == -1) {
        perror("read");
        exit(1);
    }
    write(1, "\n", 1);
    close(pd);
}