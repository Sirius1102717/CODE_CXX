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
    int temp = 1;
    while ( t-- ) {
        int a, b;
        cin >> a >> b;
        int ans = 0;
        while ( a % 3 != 1 ) {
            ans++;
            a++;
        }
        while ( b % 3 != 1 ) {
            ans++;
            b--;
        }

        ans += (b - a) / 3 * 2;

        cout << "Case " << temp++ << ": " << ans << "\n";
    }
    return 0;
}
