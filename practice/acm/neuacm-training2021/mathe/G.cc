#include<bits/stdc++.h>
using namespace std;
#define ll long long
const double EPS = 1e-8;
const ll MAXN = 1e18;
const ll MOD = 1000;

int last3(ll base, ll power)
{
    int ans = 1;
    while ( power > 0 ) {
        if ( power & 1 ) {
            ans = ans * base % MOD;
        }
        base = base * base % MOD;
        power >>= 1;
    }
    return ans;
}

int pre3(ll n, ll k)
{
    double p = k * log10(double(n));
    ll x = (ll)p;
    double y = p - x;

    int ans = (int)(pow(10.0, y) * 100);
    return ans;

}


int main(int argc, char *argv[])
{
    std::ios::sync_with_stdio(false);
    int t;
    cin >> t;
    int res = 0;
    while ( t-- ) {
        ll n, k;
        cin >> n >> k;
        printf("Case %d: %03d %03d\n", ++res, pre3(n, k), last3(n, k));
    }
    return 0;
}
