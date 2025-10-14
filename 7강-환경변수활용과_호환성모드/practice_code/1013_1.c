
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int match(const char* s1, const char *s2) {
    int diff = strlen(s1) - strlen(s2);
    if(strlen(s1) > strlen(s2)) { return (strcmp(&s1[diff], s2) == 0); }
    else { return 0; }
}

int main(int argc, char *argv[]) {
    char *cmd = "ls";
    char *args[] = {"ls", NULL};

    FILE *fp;
    char path[BUFSIZ];

    fp = popen("ls", "r");

    while(fgets(path, sizeof(path), fp) != NULL) {
        path[strlen(path) - 1] = '\0';
        if(match(path, ".c")) {
            printf("%s\n", path);
        }
    }
}