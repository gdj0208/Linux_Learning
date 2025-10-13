#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>

int main() {
    DIR * dp;
    struct dirent *dent;

    dp = opendir(".");
    while(dent = readdir(dp)) {
        struct stat st;
        stat(dent->d_name, &st);

        
    }
}