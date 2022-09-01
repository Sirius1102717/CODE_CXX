#include<bits/stdc++.h>
using namespace std;
const double EPS = 1e-8;

bool dp[100001] = { 0 };
int use[100001] = { 0 };

// void zeroOnePack(int v, int w)
// {
//     for ( int i = v; i >= w; i-- ) {
//         dp[i] = max(dp[i], dp[i - v] + w);
//     }
// }

// void comPack(int v, int w)
// {
//     for ( int i = w; i <= v; i++ ) {
//         dp[i] = max(dp[i], dp[i - v] + w);
//     }
// }

// void mulPack(int v, int w, int n)
// {
//     if ( w * n >= v ) {
//         zeroOnePack(v, w);
//     } else {
//         int k = 1;
//         while ( k < n ) {
//             zeroOnePack(k * v, k * w);
//             n -= k;
//             k <<= 1;
//         }
//         zeroOnePack(n * v, n * w);
//     }
// }

int main(int argc, char *argv[])
{
    ios::sync_with_stdio(false);
    int n, m;
    int a[101] = { 0 };
    int c[101] = { 0 };
    while ( cin >> n >> m ) {
        if ( n == 0 && m == 0 ) {
            break;
        }
        memset(dp, 0, sizeof dp);
        for ( int i = 1; i <= n; i++ ) {
            cin >> a[i];
        }
        for ( int i = 1; i <= n; i++ ) {
            cin >> c[i];
        }
        dp[0] = 1;
        for ( int i = 1; i <= n; i++ ) {
            memset(use, 0, sizeof use);
            for ( int j = a[i]; j <= m; j++ ) {
                if ( !dp[j] && dp[j - a[i]] && use[j - a[i]] < c[i] ) {
                    dp[j] = 1;
                    use[j] = use[j - a[i]] + 1;
                }
            }
        }
        int ans = 0;
        for ( int i = 1; i <= m; i++ ) {
            ans += dp[i];
        }
        cout << ans << "\n";
    }
    return 0;
}
