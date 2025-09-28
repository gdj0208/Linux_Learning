
# include <stdio.h>
# include <sys/stat.h>

void checkMode(unsigned int mode, int m, int k) {
    if ((mode & m) != 0) {
        switch(k) {
            case 0: printf("r"); break;
            case 1: printf("w"); break;
            case 2: printf("x"); break;
            default: break;
        }
    }
    else {
        printf("-");
    }
}

int main(int argc, char *argv[]) {

    struct stat buf;
    
    stat(argv[1], &buf);
    
    printf("%s %d ", argv[1], buf.st_uid);
    checkMode(buf.st_mode, S_IRUSR, 0);
    checkMode(buf.st_mode, S_IWUSR, 1);
    checkMode(buf.st_mode, S_IXUSR, 2);
    checkMode(buf.st_mode, S_IRGRP, 0);
    checkMode(buf.st_mode, S_IWGRP, 1);
    checkMode(buf.st_mode, S_IXGRP, 2);
    checkMode(buf.st_mode, S_IROTH, 0);
    checkMode(buf.st_mode, S_IWOTH, 1);
    checkMode(buf.st_mode, S_IXOTH, 2);
    printf("\n");
}

