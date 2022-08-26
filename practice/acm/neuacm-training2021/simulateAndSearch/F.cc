#include<stdio.h>
#include<algorithm>
using namespace std;

char s[5];
int a[10005];

bool cmp(int a, int b)
{
    printf("1 %d %d\n", a, b);
    fflush(stdout);
    scanf("%s", s);
    return s[0] == 'Y';
}

int main(int argc, char *argv[])
{
    int n;
    scanf("%d", &n);
    for ( int i = 1; i <= n; i++ ) {
        a[i] = i;
    }
    stable_sort(a + 1, a + 1 + n, cmp);
    for ( int i = 0; i <= n; i++ ) {
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}
