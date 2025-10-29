
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/time.h>


void sig_handler(int signo) {
    printf("Wake up\n");
    alarm(1);
}

int main() {

    struct sigaction sa;
    sigset_t set;

    sigfillset(&set);
    sigdelset(&set, SIGINT);

    sa.sa_handler = sig_handler;
    sa.sa_flags = 0;
    sa.sa_mask = set;

    sigaction(SIGALRM, &sa, NULL);
    alarm(1);

    while(1) { pause(); }
}