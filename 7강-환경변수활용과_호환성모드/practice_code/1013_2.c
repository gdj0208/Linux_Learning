
#include <stdio.h>
#include <unistd.h>
#include <dirent.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid;
    int fd;
    
    fd = open("1013_2.c", O_RDONLY);
    if (fd == -1) { perror("open"); return 1; }

    printf("Cur loc : %ld\n", lseek(fd, 10, SEEK_CUR));
    pid = fork();
    if (pid == -1) { }

    switch (pid)
    {
    case -1:
        perror("fork"); return 1; 
        break;
    case 0:
        printf("Child loc : %ld\n", lseek(fd, 10, SEEK_CUR));
        break;
    default:
        while(wait(NULL) != pid) { continue; }
        printf("Parent loc : %ld\n", lseek(fd, 10, SEEK_CUR));
        break;
    }

    return 0;
}