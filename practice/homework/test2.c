#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<stdbool.h>
#include<ctype.h>
#define min(a, b) (a) < (b) ? (a) : (b)
#define max(a, b) (a) > (b) ? (a) : (b)
#define ll long long
#define new(type) (type*)malloc(sizeof(type))
#define delete(type) free(type)
const double EPS = 1e-8;
const ll MAXN = 1e18;
const int INF = 0x3f3f3f3f;
void swap(void* a, void* b, int size) {
    void* c = new(void);
    memcpy(c, a, size), memcpy(a, b, size),memcpy(b, c, size),delete(c);
}

int (*p)(int, int);
int Max(int x, int y) {
    return x > y ? x : y;
}

int Min(int x, int y) {
    return x < y ? x : y;
}

int main(int argc, char *argv[]) {
    int a = 2, b = 1;
    p = Min;
    printf("%d\n", (*p)(a, b));
    p = Max;
    printf("%d\n", (*p)(a, b));
    
    return 0;
}
