#include<iostream>
using namespace std;
const double EPS = 1e-8;

int dp[1001][31] = { 0 };


int apple[1001] = { 0 };
int main(int argc, char *argv[])
{
    std::ios::sync_with_stdio(false);
    int t, w;
    cin >> t >> w;
    for ( int i = 1; i <= t; i++ ) {
        cin >> apple[i];
        dp[i][0] = dp[i - 1][0] + apple[i] % 2;
    }
    if ( apple[1] == 1 ) {
        dp[1][0] = 1;
    } else {
        dp[1][1] = 1;
    }
    int ans = dp[1][w];
    for ( int i = 2; i <= t; i++ ) {
        for ( int j = 1; j <= w; j++ ) {
            dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]);
            if ( apple[i] - 1 == j % 2 ) {
                dp[i][j]++;
            }
        }
        ans = max(dp[i][w], ans);
    }
    cout << ans << "\n";
    return 0;
}
