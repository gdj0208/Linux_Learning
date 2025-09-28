# include <stdio.h>
# include <stdlib.h>

int main(int argc, char *argv[]) {

    FILE *fp;
    char buf[BUFSIZ];

    if (argc != 2) {
        fprintf(stderr, "Usage: %s filename\n", argv[0]);
        exit(1);
    }

    if ((fp = fopen(argv[1], "r")) == NULL) {
        perror("fopen");
        exit(1);
    }
    
    while (fgets(buf, sizeof(buf), fp) != NULL) {
        fputs(buf, stdout);
    }

    fclose(fp);
    return 0;

}

/*
고수준 입출력 함수를 사용하여 5개의 스트링을 받아들여 파일에 저장한 후, 화면으로 스트링 번호를  입력하면 파일에서 해당 스트링을 읽어 화면에 출력하는 부분을 for()을 사용하여 작성하기
*/