// setenv() 함수를 사용해 환경 변수 TESTENV를 새로 정의하고 그 값을 ubuntu로 설정, getenv() 함수로 검색해 출력하는 프로그램을 작성하라

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    char *val;

    val = getenv("TERM");
    if(val == NULL) { printf("TERM not defined!\n"); }
    else { printf("TERM : %s\n", val); }

    setenv("TERM", "ubuntu", 1);
    val = getenv("TERM");
    printf("TERM = %s\n", val);
}