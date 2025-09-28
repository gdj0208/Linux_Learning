/* 
hw1.c(hw1)명령행 인자로 받은 파일의 기존 접근 권한을 출력하고 접근 권한을 변경하는 프로그램을 작성하시오
./hw1 g+w test.txt  
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[]) {

    struct stat fileStat;
    int x;

    // 인자로 받은 파일의 기존 접근 권한 출력
    stat(argv[2], &fileStat);
    printf("기존 접근 권한 : %o\n", (unsigned int)fileStat.st_mode & 0777);

    // 접근 권한 변경
    switch(argv[1][0]) {
        case 'u':
            switch (argv[1][2])
            {
            case 'r': x = S_IRUSR; break;
            case 'w': x = S_IWUSR; break;
            case 'x': x = S_IXUSR; break;
            default: break;
            }
            break;
        case 'g':
            switch (argv[1][2])
            {
            case 'r': x = S_IRGRP; break;
            case 'w': x = S_IWGRP; break;
            case 'x': x = S_IXGRP; break;
            default: break;
            }
            break;
        case 'o':
            switch (argv[1][2])
            {
            case 'r': x = S_IROTH; break;
            case 'w': x = S_IWOTH; break;
            case 'x': x = S_IXOTH; break;
            default: break;
            }
            break;
        default: break;
    }

    if (argv[1][1] == '+') {
        fileStat.st_mode |= x;
    }
    else if (argv[1][1] == '-') {
        fileStat.st_mode &= ~(x);
    }
    chmod(argv[2], fileStat.st_mode);

    // 변경된 접근 권한 출력
    stat(argv[2], &fileStat);
    printf("변경된 접근 권한: %o\n", (unsigned int)fileStat.st_mode & 0777 );
}