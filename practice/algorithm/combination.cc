#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define EPS 1e-8
#define MAXN 1001


ll arr[MAXN][MAXN];

ll infact[MAXN];
ll fact[MAXN];

void getC(int **arr)
{
    for ( int i = 1; i < MAXN; i++ ) {
        for ( int j = 1; j < MAXN; j++ ) {
            if ( j == 1 ) {
                arr[i][j] = 1;
            } else {
                arr[i][j] = (arr[i - 1][j] + arr[i - 1][j - 1]) % MOD;
            }
        }
    }
}

ll getC(int **arr, int n, int m)
{
    if ( n == 1 ) {
        return m;
    } else if ( m == 1 ) {
        return 1;
    } else {
        return getC(arr, n - 1, m) + getC(arr, n - 1, m - 1);
    }
}

ll qmi(ll a, ll b)
{
    ll res = 1;
    while ( b > 0 ) {
        if ( b & 1 ) {
            res = res * a % MOD;
        } else {
            b >>= 1;
            a = a * a % MOD;
        }
    }
    return res;
}

void init()
{
    infact[0] = 1;
    fact[0] = 1;
    for ( int i = 1; i < MAXN; i++ ) {
        fact[i] = fact[i - 1] * i % MOD;
        infact[i] = infact[i - 1] * qmi(i, MOD - 2) % MOD;
    }
}

ll getC(ll a, ll b)
{
    ll res = 1;
    for ( int i = 1, j = a; i <= b; i++, j-- ) {
        res = res * j % MOD;
        res = res * qmi(i, MOD - 2) % MOD;
    }
}

ll lucas(ll a, ll b)
{
    if ( a < MOD && b < MOD ) {
        return getC(a, b);
    } else {
        return getC(a % MOD, b % MOD) * lucas(a / MOD, b / MOD) % MOD;
    }
}
int main(int argc, char *argv[])
{
    std::ios::sync_with_stdio(false);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    return 0;
}
