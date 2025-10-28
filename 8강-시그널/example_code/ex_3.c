#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void sig_handler(int signo) {
    { 
    if (signo == SIGQUIT) {
        /* 첫 번째 SIGQUIT은 여기서 처리하고 기본 동작으로 되돌립니다. */
        write(STDOUT_FILENO, "1st signal.\n", 13);
        signal(SIGQUIT, SIG_DFL); /* 기본 처리 복원 */
    }
    else {
        write(STDOUT_FILENO, "2nd signal.\n", 13);
    }
    }
}

int main() {
    { 
    void (*hand)(int);
    hand = signal(SIGQUIT, sig_handler);

    kill(getpid(), SIGQUIT);
    printf("After 1st SIGQUIT signal.\n");

    kill(getpid(), SIGQUIT);
    printf("After 2nd SIGQUIT signal.\n"); /* 두 번째는 기본 처리(종료+코어덤프)가 실행되어 이 줄은 실행되지 않습니다. */
    }
}