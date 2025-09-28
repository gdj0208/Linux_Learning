/*
hw2.c(hw2) 명령행 인자로 받은 파일의 기존 접근 권한을 출력하고 접근 권한을 변경하는 프로그램을 작성하시오
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char * argv[]) {

    struct stat fileStat;
    int x, a;

    stat(argv[2], &fileStat);
    printf("기존 접근 권한 : %o\n", (unsigned int)fileStat.st_mode & 0777);
    fileStat.st_mode = 0;

    for (a = 0; a < 3; a++) {
        x = 0;

        switch(argv[1][a]) {
            case '7' : x |= S_IRWXU; break;
            case '6' : x |= (S_IRUSR | S_IWUSR); break;
            case '5' : x |= (S_IRUSR | S_IXUSR); break;
            case '4' : x |= S_IRUSR; break;
            case '3' : x |= (S_IWUSR | S_IXUSR); break;
            case '2' : x |= S_IWUSR; break;
            case '1' : x |= S_IXUSR; break;
        }

        if (a == 0) { fileStat.st_mode |= x; }
        else if (a == 1) { fileStat.st_mode |= (x >> 3); }
        else { fileStat.st_mode |= (x >> 6); }
    }

    chmod(argv[2], fileStat.st_mode);

    stat(argv[2], &fileStat);
    printf("변경된 접근 권한: %o\n", (unsigned int)fileStat.st_mode & 0777 );
}