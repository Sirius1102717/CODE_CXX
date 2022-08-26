#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main(int argc, char *argv[])
{
    std::ios::sync_with_stdio(false);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ll n;
    ll k;
    while ( cin >> n >> k ) {

        ll ans = 0;
        ll m = 1;
        while ( m < n ) {
            m += m * k;
            ans++;
        }
        cout << ans << "\n";

    }
    return 0;
}
