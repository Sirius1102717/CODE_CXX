#include<bits/stdc++.h>
using namespace std;
#define ll long long


int main(int argc, char *argv[])
{
    std::ios::sync_with_stdio(false);
    const ll MAXN = 1e18;
    ll a;
    ll b = 9;
    while ( cin >> a ) {
        ll mod = a - (9 * ((9 * MAXN) % a) % a) % a;
        cout << mod << " " << MAXN - 1 + mod << "\n";
    }
    return 0;
}
