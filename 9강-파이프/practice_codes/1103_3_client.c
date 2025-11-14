#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    int pd, n;
    char messages[BUFSIZ];
    char *GET = "To Server :";

    printf("Client ==========\n");

    if(pd = open("./My_Fifo", O_WRONLY) == -1) {
        perror("open");
        exit(1);
    }

    printf("To Server : \n");
    while(n = write(pd, argv[1], 1) > 1) {}
    
    close(pd);
}