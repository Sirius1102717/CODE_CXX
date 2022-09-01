#include<bits/stdc++.h>
using namespace std;
#define ll long long
const double EPS = 1e-8;
const ll MAXN = 1e18;

typedef pair<ll, ll> lpair;


struct comparable
{
    bool operator() (lpair l1, lpair l2)
    {
        return l1.first * l2.first > l1.second * l2.second;
    }
};

vector<lpair> v;

int main(int argc, char *argv[])
{
    std::ios::sync_with_stdio(false);
    int n;
    cin >> n;
    ll a, b;
    cin >> a >> b;
    for ( int i = 0; i < n; i++ ) {
        int t1, t2;
        cin >> t1 >> t2;
        v.emplace_back(t1, t2);
    }
    sort(v.begin(), v.end(), comparable());
    ll ans = a / v[0].second;
    ll mul = a;
    for ( int i = 1; i < n; i++ ) {
        mul *= v[i - 1].first;
        ans = max(ans, mul / v[i].second);
    }
    cout << ans << "\n";
    return 0;
}