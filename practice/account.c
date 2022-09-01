#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DATASIZE 200000000

int main() {
    int i;
    int tmp;
    FILE* fp;

    srand((unsigned)123456789);

    if((fp = fopen("account.csv", "w")) == NULL) {
        perror("cannot generate the account file");
        exit(1);
    }

    for(i = 0; i < DATASIZE; i++) {
        tmp = rand();
        if(tmp < 1000000000) tmp += 1000000000;
        fprintf(fp, "%d,%d\n", tmp, rand() >> 13);
    }

    fclose(fp);
}
