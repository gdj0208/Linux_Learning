#include <signal.h>
#include <stdio.h>

void sig_handler(int signo) {
    psignal(signo, "핸들러에서 시그널 처리\n");

    // 시그널 처리 후 기본 동작으로 복원(SIG_DFL)
    signal(SIGQUIT, SIG_DFL);           
}

int main() {
    void (*hand)(int);
    if((hand = signal(SIGQUIT, sig_handler)) == SIG_ERR) {
        perror("signal");
        exit(1);
    }

    printf("첫 번째 kill() 호출 \n");
    kill(getpid(), SIGQUIT);

    printf("두 번째 kill() 호출 \n");
    kill(getpid(), SIGQUIT);
}