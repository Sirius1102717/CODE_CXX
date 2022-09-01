#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define EPS 1e-8

// int ans[101][101];
int main(int argc, char *argv[])
{
    std::ios::sync_with_stdio(false);
    // for (int i = 1; i < 101; i++) {
    //     init[i] = i;
    // }
    int t;
    int len[101];
    while ( cin >> t ) {
        for ( int i = 1; i <= t; i++ ) {
            cin >> len[i];
            // ans[i][1] = len[i];
            // for (int j = 2; j <= len[i]; j++) {
            //     ans[i][j] = j - 1;
            // }
        }

        for ( int i = 1; i <= t; i++ ) {
            int plen = len[i];
            if ( plen % 2 == 0 ) {
                for ( int j = 1, k = 2; j <= plen; j += 2, k += 2 ) {
                    cout << k << " " << j << " ";
                }
            } else {
                for ( int j = 1, k = 2; j <= plen - 3; j += 2, k += 2 ) {
                    cout << k << " " << j << " ";
                }
                cout << plen - 1 << " " << plen << " " << plen - 2;
            }
            cout << "\n";
        }
    }
    return 0;
}
