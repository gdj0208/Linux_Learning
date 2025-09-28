#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main() {

    if (rmdir("subtestdir") == -1) {
        perror("subtestdir");
        exit(1);
    }
}