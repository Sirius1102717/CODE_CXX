#include<bits/stdc++.h>
using namespace std;
#define ll long long
const double EPS = 1e-8;
const ll MAXN = 1e18;
const ll MOD = 10007;


ll qmi(ll a, ll b, ll p)
{
    ll res = 1;
    while ( b > 0 ) {
        if ( b & 1 ) {
            res = a * res % p;
        }
        b >>= 1;
        a = a * a % p;

    }
    return res;
}

int main(int argc, char *argv[])
{
    std::ios::sync_with_stdio(false);
    int t;
    while ( cin >> t ) {
        for ( ll i = 1; i <= t; i++ ) {
            ll n, k;
            cin >> n >> k;
            ll ans = 0;
            ll len = min(n, MOD - 1);
            for ( int j = 1; j <= len; j++ ) {
                ans = (ans + qmi(j, k, MOD) * (((n - j) / MOD + 1) % MOD)) % MOD;
            }
            cout << ans << "\n";
        }

    }
    return 0;
}
