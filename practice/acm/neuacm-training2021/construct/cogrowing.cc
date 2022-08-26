#include<bits/stdc++.h>
using namespace std;
#define ll long long
const double EPS = 1e-8;
const ll MAXN = 1e18;
ll x[200000];
int main(int argc, char *argv[])
{
    std::ios::sync_with_stdio(false);
    int t;
    while ( cin >> t ) {
        int n;
        for ( int j = 0; j < t; j++ ) {
            cin >> n;
            for ( int i = 0; i < n; i++ ) {
                cin >> x[i];
            }
            cout << 0 << " ";
            int preAns = 0;
            for ( int i = 1; i < n; i++ ) {
                int ans = 0;
                int index = 0;
                int temp = x[i];
                int pre = x[i - 1] ^ preAns;
                while ( pre ) {
                    if ( pre & 1 ) {
                        if ( !(temp & 1) ) {
                            ans += pow(2, index);
                        }
                    }
                    pre >>= 1;
                    temp >>= 1;
                    index++;
                }
                preAns = ans;
                cout << ans << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}
