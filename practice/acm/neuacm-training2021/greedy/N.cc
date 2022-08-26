#include<bits/stdc++.h>
using namespace std;
#define ll long long
const double EPS = 1e-8;
const ll MAXN = 1e18;


vector<ll> c;
int main(int argc, char *argv[])
{
    std::ios::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    for (int i= 0; i < n; i++) {
        ll in;
        cin >> in;
        c.emplace_back(in);
    }
    sort(c.begin(), c.end(), greater<ll>());
    ll ans = 0;
    for (int i = 0; i <= n; i++) {
        ans += (1 + i / k) * c[i];
    }
    cout << ans << "\n";
    return 0;
}
