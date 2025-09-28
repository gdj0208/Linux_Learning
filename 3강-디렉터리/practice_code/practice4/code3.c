# include <stdio.h>
# include <string.h>
# include <dirent.h>

int main() {
    DIR *dp;
    struct dirent *entry;

    dp = opendir(".");
    if (dp == NULL) {
        perror("opendir");
        return 1;
    }

    while( (entry = readdir(dp)) != NULL) {
        if(strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) { continue; }
        printf("%s %d\n", entry->d_name, entry->d_ino);
    }
    
}