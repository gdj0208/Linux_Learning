#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main() {
     char *cwd;
     char wd1[BUFSIZ];
     char wd2[64];

     getcwd(wd1, BUFSIZ);
     printf("wd1 = %s\n", wd1);

     cwd = getcwd(NULL, BUFSIZ);
     printf("cwd1 = %s\n", cwd);
     free(cwd);

     cwd = getcwd(NULL, 0);
     printf("cwd2 = %s\n", cwd);
     free(cwd);

     if(getcwd(wd2, 10) == NULL) {
         perror("getcwd");
         exit(1);
     }
}
/*
실행 결과 : 
wd1 = /home/jw/src/ch2
cwd1 = /home/jw/src/ch2
cwd2 = /home/jw/src/ch2
getcwd: Numerical result out of range
*/