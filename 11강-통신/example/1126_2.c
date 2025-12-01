
#include <netdb.h>
#include <stdio.h>

int main() {
    struct servent *port;
    int n;

    setservent(0);
    for(n = 0; n < 5; n++) {
        port = getservent();
        printf("Name : %s\n", port->s_name);
        printf("Port : %d\n", port->s_port);
    }
    endservent();
}