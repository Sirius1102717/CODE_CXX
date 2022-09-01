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

int a[200000];

int s[200000];

int max(int a, int b) {
    return a > b ? a : b;
}

int min(int a, int b) {
    return a < b ? a : b;
}

int main(int argc, char* argv[]) {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    int m = -1;
    int ans = -INF;
    int mmin = a[0];
    for(int i = 1; i < n; i++) {
        ans = max(ans, a[i] - mmin);
        mmin = min(mmin, a[i]);
    }
    printf("%d\n", ans);
    // for(int i = 0; i < n; i++) {
        // if(m == -1 || a[i] >= s[m]) {
            // s[++m] = a[i];
        // } else {
            // ans = max(a[i] - s[0], ans);
            // while(m > -1 && s[m] > a[i]) {
                // ans = max(ans, s[m] - s[0]);
                // m--;
            // }
            // s[++m] = a[i];
        // }
    // }
    // printf("%d\n", ans);
    return 0;
}
