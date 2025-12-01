
#include <netdb.h>
#include <stdio.h>

int main() {
    struct hostent *ent;

    sethostent(0);

    while((ent = gethostent()) != NULL) {
        printf("Name = %s\n", ent->h_name);
    }

    endhostent();
}