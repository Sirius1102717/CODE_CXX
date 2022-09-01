#include<bits/stdc++.h>
using namespace std;
#define ll long long
const double EPS = 1e-8;
const ll MAXN = 1e18;

int ans[101][4] = { 0 };
int main(int argc, char *argv[])
{
    std::ios::sync_with_stdio(false);
    int t;
    while ( cin >> t ) {
        for ( int j = 0; j < t; j++ ) {

            int n;
            cin >> n;
            // int a[101] = { 0 };
            // int b[101] = { 0 };
            // int c[101] = { 0 };
            for ( int i = 1; i <= n; i++ ) {
                cin >> ans[i][1];
            }
            for ( int i = 1; i <= n; i++ ) {
                cin >> ans[i][2];
            }
            for ( int i = 1; i <= n; i++ ) {
                cin >> ans[i][3];
            }
            for ( int i = 1; i <= n; i++ ) {
                sort(ans[i], ans[i] + 3);
            }
            int temp = 1;
            int pre = 1;
            cout << ans[1][1] << " ";
            for ( int i = 2; i < n; i++ ) {
                
                while(1) {
                    if (ans[i][temp] != ans[i - 1][pre]) {
                        cout << ans[i][temp] << " ";
                        pre = temp;
                        break;
                    } 
                    (temp %= 3) += 1;
                    
                }

            }
            for ( int i = 1; i <= 4; i++ ) {
                if ( ans[n][i] != ans[1][1] && ans[n][i] != ans[n -1][pre] ) {
                    cout << ans[n][i] << "\n";
                    break;
                }
            }
        }
    }
    return 0;
}
