#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    char *argv[3];

    printf("Before exec function\n");

    argv[0] = "ls";
    argv[1] = "-l";
    argv[2] = NULL;

    if(execv("/bin/ls", argv) == -1) {
        perror("execv failed");
        exit(1);
    }

    printf("After exec function\n"); 
    // This line will not be executed if execv is successful
}