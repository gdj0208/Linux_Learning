#include <sys/types.h>
#include <time.h>
#include <stdio.h>

int main() {
    time_t loc;

    time(&loc);
    printf("Time : %d\n", (int)loc);
}