#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const double EPS = 1e-8;
const ll MAXN = 1e18;


typedef struct
{
    ll lose;
    ll win;
    int use;
}Node;


Node nodes[1001] = { 0 };

template <class T>
size_t getHash(T s)
{
    return hash<T>{}(s);
}

ll dp[1001] = { 0 };

void zeroOnePack(ll win, ll use, ll lose, ll x)
{
    for ( int i = x; i >= use; i-- ) {
        dp[i] = max(dp[i] + lose, dp[i - use] + win);
    }
}


int main(int argc, char *argv[])
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, x;
    cin >> n >> x;
    ll ans = 0;
    for ( int i = 1; i <= n; i++ ) {
        cin >> nodes[i].lose >> nodes[i].win >> nodes[i].use;
    }

    for ( int i = 1; i <= n; i++ ) {
        for ( int j = x; j >= nodes[i].use; j-- ) {
            dp[j] = max(dp[j] + nodes[i].lose, dp[j - nodes[i].use] + nodes[i].win);
        }
        for ( int j = nodes[i].use - 1; j >= 0; j-- ) {
            dp[j] += nodes[i].lose;
        }
    }
    cout << dp[x] * 5;
    return 0;
}
