#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD = 1000000007;
const double EPS = 1e-8;


ll fact[201] = { 0 };
ll infact[201] = { 0 };

ll qmi(ll a, ll b, ll mod)
{
    ll ans = 1;
    while ( b ) {
        if ( b & 1 ) {
            ans = ans * a % mod;
        }
        b >>= 1;
        a = a * a % mod;
    }
    return ans;
}

void init(ll mod)
{
    fact[1] = 1;
    infact[1] = 1;
    infact[0] = 1;
    for ( int i = 2; i <= 200; i++ ) {
        fact[i] = fact[i - 1] * i % mod;
        infact[i] = infact[i - 1] * qmi(i, mod - 2, mod) % mod;
    }
}

int main(int argc, char *argv[])
{
    std::ios::sync_with_stdio(false);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ll n, m;
    init(MOD);
    while ( cin >> n >> m ) {
        if ( m < n ) {
            cout << 0 << "\n";
        } else {
            cout << (fact[m] * infact[n] % MOD * infact[m - n] % MOD) % MOD << "\n";
        }
    }
    return 0;
}
