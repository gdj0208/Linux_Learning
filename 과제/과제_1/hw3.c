# include <stdio.h>

int main(int argc, char *argv[]) {
    char * findDir; 
    findDir = argv[1];
    
    if (chdir(findDir) == -1) { printf("not found\n"); }
    else { printf("found\n"); }
}