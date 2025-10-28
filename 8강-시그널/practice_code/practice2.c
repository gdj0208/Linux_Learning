#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int main() {
    sigset_t* set;
    sigfillset(set);

    if(sigismember(set, SIGBUS)) { printf("SIGBUS 존재함\n"); }
    else { printf("SIGBUS 존재하지 않음\n"); }
}