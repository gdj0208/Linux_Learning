#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/times.h>
#include <time.h>

int main() {
    time_t t;
    struct tms buf;
    clock_t t1, t2, ct;

    ct = sysconf(_SC_CLK_TCK);
    printf("Clock tick : %ld\n", ct);

    if((t1 = times(&buf)) == -1) { perror("t1"); exit(1); }

    sleep(5);

    if((t2 = times(&buf)) == -1) { perror("t2"); exit(1); }

    printf("Real time : %.2f sec\n", (double)(t2 - t1) / ct);
    printf("User time : %.2f sec\n", (double)buf.tms_utime);
    printf("System time : %.2f sec\n", (double)buf.tms_stime);
} 