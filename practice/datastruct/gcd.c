#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long
#define new(type) (type*)malloc(sizeof(#type))
#define delete(type) free(type)
const double EPS = 1e-8;
const ll MAXN = 1e18;
const int INF = 0x3f3f3f3f;

int gcd(int a, int b)
{
    if(b) {
        return gcd(b, a % b);
    } else {
        return a;
    }
}
int main(int argc, char* argv[])
{
    int a, b;
    scanf("%d%d", &a, &b);
    printf("%d\n", gcd(a, b));
    return 0;
}
