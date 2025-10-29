#include <stdio.h>
#include <unistd.h>
#include <signal.h>


void handler(int signo, siginfo_t *info, void *context) {
    printf("si_code : %d\n", info->si_code);
}

int main() {
    struct sigaction act;

    sigemptyset(&act.sa_mask);
    sigaddset(&act.sa_mask, SIGINT);

    act.sa_flags = SA_SIGINFO;
    act.sa_sigaction = handler;

    sigaction(SIGINT, &act, (struct sigaction *)NULL);

    while(1) { pause(); }
}