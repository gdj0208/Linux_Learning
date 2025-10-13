#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>

main() {

        DIR *dp;
        struct dirent *dent;

        if ((dp = opendir(".")) == NULL) {
        //if ((dp = opendir("testdir")) == NULL) {
                perror ("opendir : han");
                exit(1);
        }

        while ((dent = readdir(dp))) {
                printf("Name : %s ", dent->d_name);
                printf("Inode : %d\n", (int)dent->d_ino);
        }

        closedir(dp);
}

// 하위 디렉토리들의 이름과 inode 번호를 출력