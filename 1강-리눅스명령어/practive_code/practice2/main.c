
# include <stdio.h>
# include <string.h>

int main(int argc, char *argv[]) {
    
    if (argc == 1) { printf("Usable Options : -p -n -h\n"); return 0;}

    if(!strcmp(argv[1], "-p")) { printf("Welcome to Linux System Programming World!\n"); }
    else if(!strcmp(argv[1], "-n")) { printf("Nice to meet %s\n", argv[1]); }
    else if(!strcmp(argv[1], "-h")) { printf("Usable Options : -p -n -h\n"); }
}