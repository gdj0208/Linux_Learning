
# include <stdio.h>

extern int subnum(int a, int b);

int main(int argc, char * argv[]) {

    int num = subnum(10, 5);
    printf("%d\n", num);
}
