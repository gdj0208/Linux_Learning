#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    uid_t uid, eid;
    char *name;

    uid = getuid();
    eid = geteuid();
    name = getlogin();

    printf("Login name : %s\n", name);
    printf("UID name : %d\n", (int)uid);
    printf("EID name : %d\n", (int)eid);
}