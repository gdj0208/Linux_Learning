#include <sys/stat.h>
#include <ftw.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int make_sub_dir(const char *name, const struct stat *status, int level) {

    if((mkdir("subdir", 0644)) == -1) {
        perror("mkdir");
        exit(1);
    }


    if(link("subdir", "linkfile1") == -1) {
        perror("link1");
        exit(1);
    }
    if(link("subdir", "linkfile2") == -1) {
        perror("link2");
        exit(1);
    }

    if(symlink("subdir", "symlinkFile1") == -1) {
        perror("symlink1");
        exit(1);
    }
    if(symlink("subdir", "symlinkFile2") == -1) {
        perror("symlink2");
        exit(1);
    }

    chdir("subdir");
    if((mkdir("subsubdir", 0644)) == -1) {
        perror("mkdir");
        exit(1);
    }

    return (0);
}

int main(int argc, char *argv[]) {
    int make_sub_dir(const char *, const struct stat *, int);
    ftw(".", make_sub_dir, 1);
}