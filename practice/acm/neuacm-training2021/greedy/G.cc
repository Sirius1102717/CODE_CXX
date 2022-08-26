#include<bits/stdc++.h>
using namespace std;
#define ll long long
const double EPS = 1e-8;
const ll MAXN = 1e18;


vector<int> cows;

int main(int argc, char *argv[])
{
    std::ios::sync_with_stdio(false);
    int n, m, d, l;
    cin >> n >> m >> d >> l;
    for ( int i = 0; i < n; i++ ) {
        int si;
        cin >> si;
        cows.emplace_back(si);
    }
    sort(cows.begin(), cows.end());
    int ans = 0;
    for ( int i = 0; i < n; i++ ) {
        if ( cows[i] - d * (ans / m) >= l ) {
            ans++;
        }
    }
    cout << ans << "\n";


    return 0;
}
