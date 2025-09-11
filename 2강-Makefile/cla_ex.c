#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>

int main(int argc, char *argv[]) {

        int n;

        printf("argc = %d\n", argc);
        for (n=0; n<argc; n++) {
                printf("argv[%d] = %s\n", n, argv[n]);
        }

        return(0);
}

/*
실행 예시:
$ ./cla_ex arg1 arg2 arg3
argc = 4
argv[0] = ./cla_ex
argv[1] = arg1
argv[2] = arg2
argv[3] = arg3
*/