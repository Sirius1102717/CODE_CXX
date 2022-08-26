#include<bits/stdc++.h>
using namespace std;
#define ll long long
const double EPS = 1e-8;
const ll MAXN = 1e18;


vector<ll> v;
int main(int argc, char *argv[])
{
    std::ios::sync_with_stdio(false);
    // freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    for ( int i = 0; i < n; i++ ) {
        ll in;
        cin >> in;
        v.emplace_back(in);
    }
    ll ans = 0;
    int j = 0;
    ll sh = 0;
    for ( int i = 0; i < n; i++ ) {
        ll temp = min(sh, v[i] / 2);
        sh -= temp;
        v[i] -= temp * 2;
        ans += temp;
        ans += v[i] / 3;
        sh += v[i] % 3;
    }

    cout << ans << "\n";
    return 0;
}
