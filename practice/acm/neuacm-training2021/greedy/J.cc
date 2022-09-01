#include<bits/stdc++.h>
using namespace std;
#define ll long long
const double EPS = 1e-8;
const ll MAXN = 1e18;
typedef pair<ll, ll> lp;


struct
{
    bool operator() (lp p1, lp p2)
    {
        return min(p1.first * 2, p1.second) + p2.first - min(p2.first * 2, p2.second) - p1.first > 0;
    }
}comparable;

vector<lp> sales;
int main(int argc, char *argv[])
{
    std::ios::sync_with_stdio(false);
    int n, f;
    cin >> n >> f;
    ll ans = 0;
    for ( int i = 0; i < n; i++ ) {
        ll k, l;
        cin >> k >> l;
        if ( k >= l ) {
            ans += l;
        } else {
            sales.emplace_back(k, l);
        }
    }

    sort(sales.begin(), sales.end(), comparable);
    int len = sales.size();
    for ( int i = 0; i < len; i++ ) {
        if ( i < f ) {
            ans += min(sales[i].first * 2, sales[i].second);
        } else {
            ans += sales[i].first;
        }
    }
    cout << ans << "\n";

    return 0;
}
