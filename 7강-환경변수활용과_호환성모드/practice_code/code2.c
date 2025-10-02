// Putenv() 함수를 사용해 환경 변수 SHELL의 값을 변경하는 프로그램을 작성하라. 이때 변경할 값은 명령행 인자로 받는다


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    char *val;
    char env[BUFSIZ];

    val = getenv("SHELL");
    if(val == NULL) { printf("%s not defined!\n", "SHELL"); }
    else { printf("SHELL : %s setted!\n",argv[1]); }

    sprintf(env, "SHELL=%s", argv[1]);
    putenv(env);
    val = getenv("SEHLL");
    printf("SEHLL : %s\n", val);
}