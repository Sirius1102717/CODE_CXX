#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<time.h>
#define min(a, b) (a) < (b) ? (a) : (b)
#define max(a, b) (a) > (b) ? (a) : (b)
#define ll long long
#define new(type) (type*)malloc(sizeof(#type))
#define delete(type) free(type)
const double EPS = 1e-8;
const ll MAXN = 1e18;
const int INF = 0x3f3f3f3f;
void swap(void* a, void* b, int size) {
    void* c = new(void);
    memcpy(c, a, size), memcpy(a, b, size), memcpy(b, c, size), delete(c);
}

bool visH[9], visC[9], visD[9], visS[9];

void print(char c, bool* vis) {
    printf("%c", c);
    int a = 1;
    do {
        a = rand() % 9;
        a++;
    } while(vis[a]);
    vis[a] = 1;
    printf("%d ", a);
}
int main(int argc, char* argv[]) {
    memset(visH, 0, sizeof visH);
    memset(visC, 0, sizeof visC);
    memset(visD, 0, sizeof visD);
    memset(visS, 0, sizeof visS);
    printf("36\n");
    for(int i = 0; i < 9; i++) {
        print('H', visH);
        print('S', visS);
        print('C', visC);
        print('D', visD);
    }

    return 0;
}
