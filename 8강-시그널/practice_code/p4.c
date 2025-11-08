#include <signal.h>
#include <stdio.h>

int main() {
    sigset_t st;

    sigemptyset(&st);
    sigaddset(&st, SIGQUIT);
    sigaddset(&st, SIGILL);
    sigaddset(&st, SIGTRAP);
    
    if(sigismember(&st, SIGILL)) { printf("SIGILL 설정됨\n"); }
    else { printf("SIGILL 설정 안되있음\n"); }
}