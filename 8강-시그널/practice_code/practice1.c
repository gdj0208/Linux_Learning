#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>


void sig_handler(int signo) {
    psignal(signo, "Received Signal");
    printf("In Signal Handler, After Sleep\n");
}

int main() {
    struct sigaction act;

    sigemptyset(&act.sa_mask);
    sigaddset(&act.sa_mask, SIGQUIT);
    act.sa_flags = SA_RESETHAND;
    act.sa_handler = sig_handler;

    kill(getpid(), SIGQUIT);

    fpintf(stderr, "Input SIGINIT : ");
    pause();
    fprintf(stderr, "After Signal Handler\n");
}