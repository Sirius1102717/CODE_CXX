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
const ll N = 1e8 + 1;
const int INF = 0x3f3f3f3f;
ll prime[100000];
bool isPrime[100000001] = { 0 };

void ePrime()
{
    for(int i = 2; i <= sqrt(N); i++) {
        if(!isPrime[i]) {
            for(int j = 2; j * i <= N; j++) {
                isPrime[j * i] = 1;
            }
        }
    }
}

void EulerPrime()
{
    int m = 0;
    for(ll i = 2; i <= sqrt(N); i++) {
        if(!isPrime[i]) {
            prime[m++] = i;
        }
        for(int j = 0; j < m && prime[j] * i <= N; j++) {
            isPrime[prime[j] * i] = 1;
            if(i % prime[j] == 0) {
                break;
            }
        }
    }
}
int main(int argc, char* argv[])
{

    int n;
    // EulerPrime();
    // init();
    ePrime();
    scanf("%d", &n);
    int x;
    int ans = 0;
    for(int i = 0; i < n; i++) {
        scanf("%d", &x);
        if(!isPrime[x]) {
            ans++;
        }
    }
    printf("%d\n", ans);
    return 0;
}
