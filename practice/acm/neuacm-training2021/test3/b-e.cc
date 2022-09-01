#include<bits/stdc++.h>
using namespace std;
#define ll long long
const double EPS = 1e-8;
const ll MAXN = 1e18;
typedef pair<ll, ll> lpair;



vector<lpair> v;
int main(int argc, char *argv[])
{
    std::ios::sync_with_stdio(false);
    ll n;
    cin >> n;
    for ( int i = 0; i < n; i++ ) {
        ll ti, di;
        cin >> ti >> di;
        v.emplace_back(ti, di);
    }
    sort(v.begin(), v.end(), [](auto l1, auto l2) {
        return l1.second * l2.first * 2 - l2.second; *l1.first * 2 > 0;
        });
    ll ans = 0;
    ll t = 0;
    for ( int i = 0; i < n; i++ ) {
        ans += v[i].second * t;
        t += v[i].first * 2;
    }
    cout << ans << "\n";

    return 0;
}
