
#include <stdio.h>
#include <stdlib.h>

#include <netdb.h>

int main() {
    struct servent * port;
    int n;
    
    setservent(0);

    port = getservent();
    printf("Name : %s\n", port->s_name);
    printf("Port : %d\n", port->s_port);
    printf("Type : %d\n", port->s_proto);
}