#include <ftw.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <dirent.h>
#include <fcntl.h>
#include <string.h>
#include <sys/types.h>
#include <sys/utsname.h>
#include <sys/stat.h>
#include <sys/unistd.h>
#include <sys/time.h>
#include <sys/times.h>
#include <pwd.h>
#include <time.h>


int main(int argc, char *argv[]) {
    
    int fd, n;
    char buf[BUFSIZ];

    fd = open("test.txt", O_RDONLY);
    
    while((n = read(fd, buf, 1)) > 0) {
        write(1, buf, 1);
        lseek(fd, 1, SEEK_CUR);
    }
}
