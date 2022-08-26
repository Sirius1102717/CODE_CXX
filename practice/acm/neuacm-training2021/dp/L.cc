#include<iostream>
using namespace std;



int dp[1000][1000] = { 0 };
int main(int argc, char *argv[])
{
    std::ios::sync_with_stdio(false);
    int n;
    cin >> n;
    for ( int i = 0; i < n; i++ ) {
        for ( int j = 0; j <= i; j++ ) {
            cin >> dp[i][j];
        }
        if ( i > 0 ) {
            dp[i][0] += dp[i -1][0];
            dp[i][i] += dp[i - 1][i - 1];
        }
    }

    for ( int i = 1; i < n; i++ ) {
        for ( int j = 1; j < i; j++ ) {
            dp[i][j] += max(dp[i - 1][j - 1], dp[i - 1][j]);
        }
    }

    int ans = 0;
    for ( int i = 0; i < n; i++ ) {
        ans = max(dp[n - 1][i], ans);
    }

    cout << ans << "\n";

    return 0;
}
