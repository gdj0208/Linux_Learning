#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Before exec function\n");

    if(execlp("ls", "ls", "-l", (char *)NULL) == -1) {
        perror("execlp failed");
        exit(1);
    }
    printf("After exec function\n"); 
    // This line will not be executed if execlp is successful
}