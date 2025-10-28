#include <stdio.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>

int main() {
    printf("Is printing available?\n");
    kill(getppid(), SIGUSR1);
    printf("Is printing available?\n");
}