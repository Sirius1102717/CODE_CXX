#include <algorithm>
#include <bitset>
#include <cstdio>
#include <cstring>
#include <deque>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <vector>
using namespace std;
using ll = long long;
ll x[55];
bool vis[55];
int n, a;

// void dfs(int num, int sum, int j)
// {
// if (num >= n) {
// return;
// }
// if (!sum && num) {
// ans++;
// }
// for (int i = j; i < n; i++) {
// if (!vis[i]) {
// vis[i] = 1;
// dfs(num + 1, sum + x[i], i + 1);
// vis[i] = 0;
// } else {
// dfs(num + 1, sum, i + 1);
//    }
// }
// }
ll dp[3][55][51 * 50];
ll ans[55];

int main(int argc, char* argv[])
{
    freopen("/home/freaver/CODE_C/input.txt", "r", stdin);
    freopen("/home/freaver/CODE_C/output.txt", "w", stdout);
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    while (~scanf("%d%d", &n, &a)) {
        int index;
        memset(dp, 0, sizeof dp);
        for (int i = 1; i <= n; i++) {
            scanf("%lld", &x[i]);
        }
        ll out = 0;
        dp[0][0][0] = dp[1][0][0] = 1;
        int now = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                for (int k = 0; k <= 2500; k++) {
                    dp[now][j][k] = dp[now ^ 1][j][k];
                    dp[now][j][k] += k >= x[i] ? dp[now ^ 1][j - 1][k - x[i]] : 0;
                }
            }
            now ^= 1;
        }

        for (int i = 1; i <= n; i++) {
            out += dp[now ^ 1][i][a * i];
        }

        printf("%lld\n", out);
    }

    return 0;
}
