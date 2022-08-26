#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define EPS 1e-8

int ans[10000][100] = { 0 };
int n[10000];
int main(int argc, char *argv[])
{
    std::ios::sync_with_stdio(false);
    int t;

    while ( cin >> t ) {
        for ( int j = 0; j < t; j++ ) {
            int  x;
            cin >> n[j] >> x;
            int w[100];
            for ( int i = 0; i < n[j]; i++ ) {
                cin >> w[i];
            }

            if ( n[j] > 1 ) {
                int m = 0;
                int sum = 0;
                int i;
                for ( i = n[j] - 1; i > -1; i-- ) {
                    sum += w[i];
                    if ( (m == 0 && w[i] != x) || (sum != x) ) {
                        ans[j][m++] = w[i];
                    } else if ( i > 0 ) {
                        ans[j][m++] = w[--i];
                        sum += w[i];
                        ans[j][m++] = w[i + 1];
                    } else if ( sum == x && i == 0 ) {
                        ans[j][0] = 0;
                    }
                }
            } else {
                if ( w[0] != x ) {
                    ans[j][0] = w[0];
                }
            }
        }
        for ( int i = 0; i < t; i++ ) {
            if ( ans[i][0] ) {
                cout << "YES" << "\n";
                for ( int j = 0; j < n[i]; j++ ) {
                    cout << ans[i][j] << " ";
                }
                cout << "\n";
            } else {
                cout << "NO" << "\n";
            }
        }

    }
    return 0;
}
