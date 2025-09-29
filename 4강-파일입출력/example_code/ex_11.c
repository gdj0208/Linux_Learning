# include <sys/types.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

int main() {
    int fd, n;
    off_t start, cur;
    char buf[BUFSIZ];

    fd = open("test.txt", O_RDONLY);
    if (fd == -1) { perror("open"); exit(1); }

    start = lseek(fd, 0, SEEK_SET);
    n = read(fd, buf, sizeof(buf)-1);
    buf[n] = '\0';
    
    printf("Offset start = %d\n", (int)start);
    printf("read %d bytes : %s\n", n, buf);

    cur = lseek(fd, 5, SEEK_CUR);
    n = read(fd, buf, sizeof(buf)-1);
    buf[n] = '\0';
    printf("Offset cur = %d\n", (int)cur);
    printf("read %d bytes : %s\n", n, buf);

    close(fd);
}