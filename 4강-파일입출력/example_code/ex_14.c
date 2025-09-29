# include <stdlib.h>
# include <stdio.h>

int main() {
    int ret;

    ret = remove("test.txt");
    if (ret == -1) {
        perror("file not exist!");
        exit(1);
    }

    printf("File successfully removed!\n");
}