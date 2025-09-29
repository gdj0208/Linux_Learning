# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

int main() {
    int fd, n;
    char buf[BUFSIZ];

    fd = open("test.txt", O_RDONLY);
    if (fd == -1) {
        perror("Open");
        exit(1);
    }

    n = read(fd, buf, sizeof(buf));
    if(n == -1) {
        perror("Read");
        exit(1);
    }

    buf[n] = '\0';
    printf("n = %d\n", n);
    printf("buf : \n%s", buf);
    close(fd);
}