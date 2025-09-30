// ex_18.c

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(void) {
    FILE *fp;
    FILE *newfp;
    int newfd;
    
    int n;
    long cur;
    fpos_t fcur;
    char buf[BUFSIZ];

    if ((fp = fopen("test.dat", "r")) == NULL) {
        perror("fopen: test.dat");
        exit(1);
    }

    newfd = fileno(fp);
    printf("%d\n", newfd);

    cur = ftell(fp);
    printf("Offset cur=%d\n", (int)cur);

    n = fread(buf, sizeof(char), 5, fp);
    buf[n] = '\0';
    printf("-- Read Str=%s\n", buf);

    fseek(fp, 1, SEEK_CUR);

    cur = ftell(fp);
    printf("Offset cur=%d\n", (int)cur);

    n = fread(buf, sizeof(char), 6, fp);
    buf[n] = '\0';
    printf("-- Read Str=%s\n", buf);

    fseek(fp, 1, SEEK_CUR);

    cur = ftell(fp);
    printf("Offset cur=%d\n", (int)cur);

    n = fread(buf, sizeof(char), 11, fp);
    buf[n] = '\0';
    printf("-- Read Str=%s\n", buf);

    rewind(fp);
    cur = ftell(fp);
    printf("Rewind Offset cur=%d\n", (int)cur);

    fclose(fp);

    return 0;
}