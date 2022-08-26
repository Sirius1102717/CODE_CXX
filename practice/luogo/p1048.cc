#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const double EPS = 1e-8;
const int MAXN = 1e7 + 1;

template <class T>
size_t getHash(T s)
{
    return hash<T>{}(s);
}
ll dp[MAXN] = { 0 };

typedef struct
{
    ll a;
    ll b;
}Grass;

Grass grass[10001] = { 0 };

void zeroOnePack(int w, int v, int t)
{
    for ( int i = t; i >= w; i-- ) {
        dp[i] = max(dp[i], dp[i - w] + v);
    }
}


int main(int argc, char *argv[])
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t, m;
    cin >> t >> m;
    for ( int i = 1; i <= m; i++ ) {
        cin >> grass[i].a >> grass[i].b;
    }

    for ( int i = 1; i <= m; i++ ) {
        zeroOnePack(grass[i].a, grass[i].b, t);
    }
    cout << dp[t] << "\n";
    return 0;
}
