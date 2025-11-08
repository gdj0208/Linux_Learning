#include <signal.h>
#include <stdio.h>

int main() {
    printf("SIGUSR1 시그널 보내기 전\n");
    kill(getpid(), SIGUSR1);
    printf("SIGUSR1 시그널 보내기 후\n");
}