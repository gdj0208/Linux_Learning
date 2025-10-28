#include <stdio.h>
#include <unistd.h>
#include <signal.h>

int main() {
    sigset_t st;

    sigemptyset(&st);

    sigaddset(&st, SIGQUIT);
    sigaddset(&st, SIGILL);
    sigaddset(&st, SIGTRAP);

    if(sigismember(&st, SIGILL)) { printf("SIGILL is in member!\n"); }
}