#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/time.h>

void sig_handler() {
    printf("Handler executed!\n");
}

int main() {
    struct itimerval it;
    printf("PID : %d\n", getpid());

    signal(SIGVTALRM, sig_handler);
    it.it_value.tv_sec = 0;
    it.it_value.tv_usec = 100000;
    it.it_interval.tv_sec = 1;
    it.it_interval.tv_usec = 0;

    while(1) { }
}