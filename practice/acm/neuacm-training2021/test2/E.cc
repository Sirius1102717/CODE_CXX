#include<bits/stdc++.h>
using namespace std;
#define ll long long
const double EPS = 1e-8;
const ll MAXN = 1e18;

int main(int argc, char *argv[])
{
    std::ios::sync_with_stdio(false);
    for ( ll i = 3; i <= 1000; i++ ) {
        for ( ll j = 1; j < i; j ++ ) {
            if ( i * (i + 1) == 2 * j * (j + 1) ) {
                cout << i << " " << j << "\n";
                break;
            }
        }
    }
    return 0;
}
