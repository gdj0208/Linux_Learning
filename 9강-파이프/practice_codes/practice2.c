/*
1. popen(), pclose() 사용
2. 부모 프로세스가 보낸 파일의 내용을 자식 프로세스가 페이지 단위로 출력
3. 출력할 파일명은 명령행 인자로 받는다.

ls -al > test.txt 등으로 파일 미리 생성
popen("more", "w"), fopen(), fputs, fgets 사용
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>


int main(int argc, char *argv[]) {
    char buf[BUFSIZ];
    FILE* fp_read, *fp_write;
    int j;
    pid_t pid;

    if(argc != 2) { printf("lack of argc\n"); exit(1); }

    switch (pid = fork())
    {
    case -1:
        break;
    case 0 :
        if((fp_read = fopen(argv[1], "r") == -1)) {
            perror("fopen");
            exit(1);
        }
        while(fgets(buf, BUFSIZ, fp_read) != NULL) {
            fputs(buf, fp_write);
        }
        fclose(fp_read);
        break;
    default:
        if((fp_write = popen("more", "w")) == NULL) {
            perror("popen");
            exit(1);
        }

        wait(NULL);
        fclose(fp_write);
        break;
    }
}