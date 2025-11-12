#include <stdio.h>
#include <fcntl.h>
#include <string.h>

int main() {
    int pd[2][2];
    int n;
    char *msg, *inmsg;

    pipe(pd);

    switch (fork()) {
    case 0: /* child */
        close(pd[0][1]);
        close(pd[1][0]);

        while(1) {
            n = read(pd[0][0], msg, sizeof(msg));


            fgets(inmsg, sizeof(inmsg)-1, stdin);
            write(pd[1][1], inmsg, strlen(inmsg) + 1);
        }

        break;
    case 1: /* parent */
        close(pd[0][1]);
        close(pd[1][0]);

        while(1) {
            fgets(msg, sizeof(msg), stdin);

            
            write(pd[0][1], msg, sizeof(msg));
            read(pd[1][0], msg, sizeof(msg));
        }
        break;
    }
}