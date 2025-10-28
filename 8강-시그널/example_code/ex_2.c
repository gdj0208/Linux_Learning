#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void sig_handler(int signo) {
    printf("Is printing available?\n");
}

int main() {
    void (*hand)(int);
    hand = signal(SIGILL, sig_handler);

    kill(getpid(), SIGILL);
    printf("After SIGILL signal.\n");
}