#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    FILE *fp;
    int p[2];
    char buf[BUFSIZ];
    pid_t pid;

    switch (pid = fork())
    {
    case 0:
        fp = popen("man", "r");
        break;
    case 1:
        sprintf(buf, "man %s", argv[1]);
        break;
    default:
        break;
    }

    if(fp == NULL) { perror("popen error!\n"); exit(0); }

    while(fgets(buf, BUFSIZ, fp) != NULL) { puts(buf); }

    pclose(fp);
}