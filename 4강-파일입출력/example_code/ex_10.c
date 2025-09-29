# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

int main() {
    int rfd, wfd, n;
    char buf[BUFSIZ];

    rfd = open("test.txt", O_RDONLY);
    if (rfd == -1) {
        perror("open");
        exit(1);
    }
    
    wfd = open("test_back.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if (wfd == -1) {
        perror("open");
        exit(1);
    }

    while ((n = read(rfd, buf, sizeof(buf))) > 0) {
        if (write(wfd, buf, n) != n) {
            perror("write");
            exit(1);
        }
    }

    if (n == -1) { perror("read"); }
    
    close(rfd);
    close(wfd);
}