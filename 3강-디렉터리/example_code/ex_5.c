#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
     if(rename("oldname.txt", "newname.txt") == -1) {
         perror("Error renaming file");
         exit(1);
     }
}

