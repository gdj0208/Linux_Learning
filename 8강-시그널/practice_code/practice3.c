#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/time.h>

void sig_handler() {}

int main() {
    sigset_t set;
    
    sigemptyset(&set);
    sigaddset(&set, SIGINT);
    sigprocmask(SIG_BLOCK, &set, (sigset_t*)NULL);

    while(1) {
        printf("UNIX programming!\n");
        sleep(1);
    }
}