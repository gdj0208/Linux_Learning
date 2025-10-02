// 명령행 인자로 입력받은 환경 변수의 값을 출력하는 프로그램을 작성하라

#include <stdio.h>

int main(int argc, char *argv[], char **envp) {
    char **env;

    env = envp;
    while(*env) {
        printf("%s\n", *env);
        env++;
    }
}