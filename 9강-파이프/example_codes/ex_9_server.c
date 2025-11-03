#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main() {
    int pd, n;
    char message[] = "Hello, Client!\n";

    printf("Server ==========\n");

    if(mkfifo("./My_Fifo", 0666) == -1) {
        perror("mkfifo");
        exit(1);
    }

    if((pd = open("./My_Fifo", O_WRONLY)) == -1) {
        perror("mkfifo");
        exit(1);
    }

    printf("To Client : ");
    printf("%s\n", message);

    if((n = write(pd, message, strlen(message))) == -1) {
        perror("write");
        exit(1);
    }

    close(pd);
}