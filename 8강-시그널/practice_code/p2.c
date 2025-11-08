#include <signal.h>
#include <stdio.h>

int main() {
    printf("SIGILL 시그널 보내기 전\n");
    kill(getpid(), SIGILL);
    printf("SIGILL 시그널 보낸 후\n");
}