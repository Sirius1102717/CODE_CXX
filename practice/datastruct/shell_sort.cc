#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long
// typedef long long ll;
const ll MAXN = 1e18;
const int INF = 0x3f3f3f3f;
int cnt;
int m;
void insert_sort(int* a, int n, int g) {
    for(int i = g; i < n; i++) {
        int key = a[i];
        int j = i - g;
        while(j >= 0 && a[j] > key) {
            a[j + g] = a[j];
            j -= g;
            cnt++;
        }
        a[j + g] = key;
    }
}

int g[105];

int a[1000000];
int b[1000000];


void shell_sort(int *a, int n) {
    cnt = 0;
    m = 0;
    int h = 1;
    g[m++] = h;
    /**
    Knuth增量法
    */
    while(h <= (n - 1) / 3) {
        h = h * 3 + 1;
        g[m++] = h;
    }
    for (int i = m - 1; i >= 0; i--) {
        insert_sort(a, n, g[i]);
    }

}



int main(int argc, char* argv[]) {
    freopen("/home/freaver/CODE_C/practice/input.txt", "r", stdin);
    freopen("/home/freaver/CODE_C/practice/output.txt", "w", stdout);
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    shell_sort(a, n);
    printf("%d\n", m);
    for (int i = m - 1; i >= 0; i--) {
        printf("%d ", g[i]);
    }
    puts("");
    printf("%d\n", cnt);
    for (int i = 0; i < n; i++) {
        printf("%d\n", a[i]);
    }
    // for (int i = 0; i < n; i++) {
        // printf("%d\n", b[i]);
    // }
    // puts("10");
    // shellSort(a, n);
    // printf("%d\n", m);
    // for(int i = 0; i < m; i++) {
        // printf("%d ", g[i]);
    // }
    // printf("\n%d\n", cnt);
    // for(int i = 0; i < n; i++) {
        // printf("%d\n", a[i]);
    // }

    return 0;
}
