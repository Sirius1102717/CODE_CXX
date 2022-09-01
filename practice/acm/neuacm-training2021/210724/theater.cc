#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(int argc, char *argv[])
{
    std::ios::sync_with_stdio(false);
    ll n, m, a;
    while ( cin >> n >> m >> a ) {
        ll needed;
        if ( n % a != 0 ) {
            needed = n / a + 1;
        } else {
            needed = n / a;
        }
        if ( m % a != 0 ) {
            needed *= (m / a + 1);
        } else {
            needed *= (m / a);
        }
        cout << needed << "\n";
    }
    return 0;
}

