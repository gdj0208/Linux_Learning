#include <time.h>
#include <stdio.h>

int main() {
    struct tm *tm;
    time_t timep;

    time(&timep);
    tm = localtime(&timep);

    printf("Time(sec) : %d\n", (int)timep);
    printf("Time(date) : %s\n", asctime(tm));
}
/*
실행 결과 : 
Time(sec) : 1759210931
Time(date) : Tue Sep 30 14:42:11 2025
*/