#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#define ll long long
ll a[105];
ll dp[2][105];
using namespace std;
int main(void)
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    ll ans = 0;
    ll len = 0;
    for (int i = 0; i < n; i++) {
        dp[1][i] = 1;
        dp[0][i] = 1;
        for (int j = 0; j < i; j++) {
            if (a[i] > a[j]) {
                if (dp[1][j] + 1 > dp[1][i]) {
                    dp[1][i] = dp[1][j] + 1;
                    dp[0][i] = dp[0][j];
                } else if (dp[1][j] + 1== dp[1][i]) {
                    dp[0][i] += dp[0][j];
                }
            }
        }
        if (dp[1][i] > len) {
            len = dp[1][i];
            ans = dp[0][i];
        } else if (len == dp[1][i]) {
            ans += dp[0][i];
        }
    }
    cout << ans << endl;
}