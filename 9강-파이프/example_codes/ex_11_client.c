#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main() {
    int pd, n;
    char message[BUFSIZ];

    if((pd = open("./My_Fifo", O_RDONLY)) == -1) {
        perror("open");
        exit(1);
    }

    printf("Client ==========\n");
    write(1, "From Server : ", 13);

    while((n = read(pd, message, 1)) > 0) {
        write(1, message, n);
    }
    if(n == -1) {
        perror("read");
        exit(1);
    }

    write(1,"\n",1);
    close(pd);
}