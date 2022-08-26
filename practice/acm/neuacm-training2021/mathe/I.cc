#include<bits/stdc++.h>
using namespace std;
#define ll long long
const double EPS = 1e-8;
const ll MAXN = 1e18;

int main(int argc, char *argv[])
{
    std::ios::sync_with_stdio(false);
    int t;
    cin >> t;
    for ( int i = 1; i <= t; i++ ) {
        ll n;
        cin >> n;
        cout << "Case " << i << ": " << n - (ll)sqrt(n) - (ll)sqrt(n / 2) << "\n";
    }
    return 0;
}
