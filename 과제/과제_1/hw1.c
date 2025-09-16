#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/*
1. 디렉토리명을 명령행 인자로 입력받아 생성
2. 작업 디렉토리를 새로 생성한 디렉토리로 이동
*/

int main(int argc, char *argv[]) {

    char * newdir;
    char * curdir;
    
    // 1. 디렉토리명을 명령행 인자로 입력받아 생성
    newdir = argv[1];
    if (mkdir(newdir, 0755) == -1) {
        perror("failed to make directory\n");
        exit(1);
    }
    printf("make directory: %s\n", newdir);

    // 2. 작업 디렉토리를 새로 생성한 디렉토리로 이동
    curdir = getcwd(NULL, BUFSIZ);
    printf("current directory: %s\n", curdir);

    if (chdir(newdir) == -1) {
        perror("failed to change directory\n");
        exit(1);
    }

    curdir = getcwd(NULL, BUFSIZ);
    printf("change directory to: %s\n", curdir);

    free(curdir);
}