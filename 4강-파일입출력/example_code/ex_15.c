#include <stdlib.h>
#include <stdio.h>

int main() {
    FILE *rfp, *wfp;
    int c;

    rfp = fopen("test.txt", "r");
    if(rfp == NULL) { perror("fopen"); exit(1); }

    wfp = fopen("test_cpy.txt", "w");
    if(wfp == NULL) { perror("fopen"); exit(1); }

    whlie((c = fgetc(rfp)) != EOF) { fputc(c, wfp); }

    fclose(rfp);
    fclose(wfp);
}