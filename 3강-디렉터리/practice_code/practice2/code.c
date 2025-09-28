#define _GNU_SOURCE
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void make_dir() {
    if (mkdir("testdir", 0755) == -1) {
        perror("testdir");
        exit(1);
    }
    printf("Directory 'testdir' created.\n");
}

int main() {
    char *cwd;
    char *new_dir;

    cwd = get_current_dir_name();
    printf("current dir = %s\n", cwd);


    make_dir();
    chdir("testdir");
    new_dir = get_current_dir_name();
    printf("moved to new dir = %s\n", new_dir);

    chdir(cwd);
    printf("moved to old dir = %s\n", cwd);

    rmdir("testdir");
    free(cwd);
    free(new_dir);
}

