#include <stdio.h>
#include <signal.h>


void sig_handler(int signo, siginfo_t *info, void *ucontext) {
    printf("SI_CODE : %d\n", info->si_code);
}

int main(int argc, char *argv[]) {
    
    struct sigaction act;


    act.sa_flags = SA_SIGINFO|SA_RESETHAND;
    act.sa_handler = sig_handler;


    sigemptyset(&act.sa_mask);
    sigaction(SIGQUIT, &act, NULL);

    pause();
    pause();
} 