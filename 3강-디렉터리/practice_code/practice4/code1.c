# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>

int main(int argc, char *argv[]) {
    struct stat buf;

    stat(argv[1], &buf);

    printf("File name :%s\n", argv[1]);
    printf("Inode number : %d\n", buf.st_ino);
    printf("File type : %o\n", buf.st_mode);
    printf("File size : %d\n", buf.st_size);
    printf("File UID : %d\n", buf.st_uid);
}