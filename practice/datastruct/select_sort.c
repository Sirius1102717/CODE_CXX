#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long
#define new(type) (type*)malloc(sizeof(#type))
#define delete(type) free(type)
const double EPS = 1e-8;
const ll MAXN = 1e18;
const int INF = 0x3f3f3f3f;
void swap(int* a, int* b) {
    int c = *a;
    *a = *b, *b = c;
}
int max(int a, int b) {
    return a > b ? a : b;
}
int min(int a, int b) {
    return a < b ? a : b;
}

int a[100];
int main(int argc, char* argv[]) {

    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        int mini = i;
        for (int j = i; j < n; j++) {
            if (a[j] < a[mini]) {
                mini = j;
            }
        }
        swap(&a[i], &a[mini]);
        if (i != mini) {
            cnt++;
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    puts("");
    printf("%d\n", cnt);
    return 0;
}
