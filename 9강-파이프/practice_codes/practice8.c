// 1105 1차 실습
#include <stdio.h>
#include <fcntl.h>



int main() {
    struct flock lock;
    int fd;

    fd = open("mytxt.txt", O_CREAT | O_RDONLY, 0644);

    lock.l_type = F_RDLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 5;

    if(fcntl(fd, F_SETLKW, &lock) == -1) {
        perror("parent : 1st locking");
        exit(1);
    }
    printf("parent : 1st locked!\n");

    switch(fork()) {
    case 0:
        lock.l_start = 5;
        if(fcntl(fd, F_SETLKW, &lock) == -1) {
            perror("child : 1st locking\n");
            exit(1);
        }
        printf("child : 1st locked!\n");

        if(fcntl(fd, F_SETLKW, &lock) == -1) {
            perror("child : 2nd locking\n");
            exit(1);
        }
        printf("child : 2nd locked!\n");

        exit(0);
        break;
    case 1:
        break;
    }
    
    sleep(10);
    lock.l_start = 5;
    if(fcntl(fd, F_SETLKW, &lock) == -1) {
        perror("parent : 2nd locking");
        exit(1);
    }
    printf("parent : 2nd locked!\n");

    close(fd);
}