# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

int main(int argc, char *argv[])
{
    int fd, i;
    char buf;

    fd = open("temp.txt", O_RDWR | O_CREAT | O_TRUNC, 0644);
    if (fd == -1) {
        perror("open");
        exit(1);  
    }

    write(fd, "abcdefghijklmnopqrstuvwxyz", 26);
    lseek(fd, 0, SEEK_SET);

    for (int i = 0; i < 26; i += 2)
    {
        read(fd, &buf, 1);
        printf("%c", buf);
        lseek(fd, 1, SEEK_CUR);
    }
    printf("\n");
    close(fd);
    return 0;

}

/*
1. lseek 함수를 이용해 다음 데이터 파일을 읽어 출력 형태와 같이 출력하는 프로그램을 작성하라
데이터 파일 : abcdefghijklmnopqrstuvwxyz
출력 형태 : acegikmoqsuwv
*/