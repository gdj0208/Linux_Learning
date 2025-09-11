#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main() {

    if (mkdir("testdir", 0755) == -1) {
            perror ("testdir");
            exit(1);
    }
}