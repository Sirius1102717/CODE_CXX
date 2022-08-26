#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<stdbool.h>
#define ll long long
#define new(type) (type*)malloc(sizeof(#type))
#define delete(type) free(type)
const double EPS = 1e-8;
const ll MAXN = 1e18;
const int INF = 0x3f3f3f3f;
int a[100];

void swap(int *a, int *b) {
    int c = *a;
    *a = *b;
    *b = c;
}

int main(int argc, char *argv[])
{
    int n;
    scanf("%d", &n); 
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = n - 1; j > i; j--) {
            if (a[j] < a[j - 1]) {
                swap(&a[j], &a[j - 1]);
                cnt++;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    puts("");
    printf("%d\n", cnt);
    return 0;
}
