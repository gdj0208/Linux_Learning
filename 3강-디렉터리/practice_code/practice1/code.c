# include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>

int main() {
    
    // dir1, dir2 생성
    if(mkdir("dir1", 0644) == -1) {
        perror("mkdir");
        return -1;
    }
    else { printf("Dir1 Successfully created!\n"); }

    if(mkdir("dir2", 0644) == -1) {
        perror("mkdir");
        return -1;
    }
    else { printf("Dir2 Successfully created!\n"); }

    
    // dir1 삭제
    if(rmdir("dir1") == -1) {
        perror("rmdir");
        return -1;
    }
    else { printf("Dir1 Successfully removed!\n"); }

    // dir2 -> testdir로 이름 변경
    if (rename("dir2", "testdir") == 1) {
        perror("rename");
        return -1;
    }
    else { printf("Dir2 Successfully renamed to testdir!\n"); }
}