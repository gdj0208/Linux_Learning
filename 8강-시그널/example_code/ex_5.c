#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

void handler(int signo) {
    psignal(signo, "Received Signal:");
    sleep(5);
    printf("In Signal Handler, After Sleep\n");
}


int main(void) {

    struct sigaction act;

    sigemptyset(&act.sa_mask);
    sigaddset(&act.sa_mask, SIGQUIT);    // 이 줄을 주석처리하면 ^C 입력 후 ^\ 를 입력하면 sigquit이 바로 처리된다.

    act.sa_flags = 0;
    act.sa_handler = handler;
    if (sigaction(SIGINT, &act, (struct sigaction *)NULL) < 0) {
        perror("sigaction");
        exit(1);
    }

    fprintf(stderr, "Input SIGINT: ");
    pause();
    fprintf(stderr, "After Signal Handler\n");

    return 0;
}

