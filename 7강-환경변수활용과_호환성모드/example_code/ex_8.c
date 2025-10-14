#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    char *argv[3];
    char *envp[2];

    printf("Before exec function\n");

    argv[0] = "ex_9.c";

    printf("After exec function\n"); 
    // This line will not be executed if execv is successful
}