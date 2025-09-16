#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

int main(int argc, char *argv[]) {
    
    DIR *dp;
    struct dirent *entry;

    dp = opendir(".");

    while ((entry = readdir(dp)) != NULL) {
        if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            printf("%s\n", entry->d_name);
        }
    }
}