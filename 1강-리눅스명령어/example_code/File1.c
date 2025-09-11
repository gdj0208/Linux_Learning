// File1.c

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

// 외부 파일에 정의된 addnum() 함수를 사용함을 선언
extern int addnum(int a, int b);

int main() {
    int sum;

    sum = addnum(1, 5); 
    printf("Sum  = %d\n", sum);

    return(0);
}