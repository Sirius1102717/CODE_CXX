#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long
#define new(type) (type*)malloc(sizeof(#type))
#define delete(type) free(type)
#define ffor(i, n) for(int i = 0; i < n; i++)
const double EPS = 1e-8;
const ll MAXN = 1e18;
const int INF = 0x3f3f3f3f;

int main(int argc, char* argv[])
{
    int n;
    int a[100];
    scanf("%d", &n);
    ffor(i, n)
    {
        scanf("%d", &a[i]);
    }
    ffor(i, n) {
        printf("%d ", a[i]);
    }
    puts("");
    for(int i = 1; i < n; i++) {
        int key = a[i];
        int j = i - 1;
        while(j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
        ffor(j, n)
        {
            printf("%d ", a[j]);
        }
        puts("");
    }

    return 0;
}
