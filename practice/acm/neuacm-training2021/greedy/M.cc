#include<bits/stdc++.h>
using namespace std;
#define ll long long
const double EPS = 1e-8;
const ll MAXN = 1e18;


vector<int> a;
int main(int argc, char *argv[])
{
    std::ios::sync_with_stdio(false);
    int n, r;
    cin >> n >> r;
    int heater = 0;
    a.emplace_back(0);
    for ( int i = 0; i < n; i++ ) {
        int in;
        cin >> in;

        a.emplace_back(in);
    }
    int ans = 0;
    for ( int i = 1; i <= n; i++ ) {
        int j;
        bool flag = 1;
        for ( j = min(n, i + r - 1); j >= max(1, i - r + 1); j-- ) {
            if ( a[j] ) {
                ans++;
                flag = 0;
                break;
            }
        }
        if ( flag ) {
            cout << "-1\n";
            return 0;
        }
        i = j + r - 1;
    }
    cout << ans << "\n";

    return 0;
}
