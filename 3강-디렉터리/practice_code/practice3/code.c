# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <dirent.h>

int main() {
    DIR * dp;
    struct dirent * dir;

    dp = opendir("testdir");
    if (dp == NULL) {
        perror("Directory not exist!\b");
        exit(1);
    }

    if(rmdir("testdir") == -1) {
        perror("rmdir");
        exit(1);
    }
    printf("Directory 'testdir' removed.\n");
}