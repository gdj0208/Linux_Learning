#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    char buf[256];
    char symname[1024];
    int n;

    if (argc == 1) {
        printf("Usage: mysym filename\n");
        exit(1);
    }

    n = 0;
    while(argv[1][n] != '.') {
        buf[n] = argv[1][n];
        n++;
    }
    buf[n] = '\0';

    printf("buf: %s\n", buf);
    sprintf(symname, "%s.sym", buf);
    printf("symname: %s\n", symname);

    symlink(argv[1], symname);

    n = readlink(symname, buf, sizeof(buf));
    if (n == -1) {
        perror("readlink");
        exit(1);
    }
    buf[n] = '\0';
    printf("%s: READLINK = %s\n", symname,  buf);

    realpath(symname, buf);
    printf("%s: REALPATH = %s\n", symname,  buf);
}

