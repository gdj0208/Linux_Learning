# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

int main(int argc, char *argv[])
{
    int i, fd;
    char buf;

    if (argc == 1) {
        while (read(0, &buf, 1) > 0) {
            write(1, &buf, 1);
        }
    } else {
        for (i = 1; i < argc; i++) {
            fd = open(argv[i], O_RDONLY);
            if (fd == -1) {
                perror("open");
                exit(1);
            }
            
            while (read(fd, &buf, 1) > 0) {
                write(1, &buf, 1);
            }
            close(fd);
        }
    }
    return 0;
}

/*
1. 명령행 인자가 있는지 조사하고, 만일 인자가 존재하면, 각 인자를 하나의 파일 이름으로 취급하고 각 파일의 내용을 표준 출력으로 복사하는 프로그램을 작성하시오. 만일 명령행 인자가 존재하지 않으면, 입력을 표준 입력으로부터 받아야 한다
*/