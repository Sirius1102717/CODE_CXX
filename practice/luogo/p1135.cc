#include <algorithm>
#include <cstring>
#include <deque>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;
using ll = long long;
const double EPS = 1e-8;
const ll MAXN = 1e18;
const int INF = 0x3f3f3f3f;
int dp[205], vis[205];
int n, a, b;
int k[205];

bool in(int x)
{
    return x > 0 && x <= n && !vis[x];
}

void bfs(int a, int b)
{
    queue<int> q;
    q.push(a);
    vis[a] = 1;
    dp[a] = 0;
    while (!q.empty()) {
        int pre = q.front();
        if (pre == b) {
            return;
        }
        q.pop();
        int add = pre + k[pre];
        int sub = pre - k[pre];
        if (in(add)) {
            q.push(add);
            dp[add] = dp[pre] + 1;
            vis[add] = 1;
        }
        if (in(sub)) {
            q.push(sub);
            dp[sub] = dp[pre] + 1;
            vis[sub] = 1;
        }
    }
}
int main(int argc, char* argv[])
{
    freopen("/home/freaver/CODE_C/input.txt", "r", stdin);
    freopen("/home/freaver/CODE_C/output.txt", "w", stdout);
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> a >> b;
    memset(vis, 0, sizeof vis);
    memset(dp, -1, sizeof dp);
    for (int i = 1; i <= n; i++) {
        cin >> k[i];
    }
    bfs(a, b);
    cout << dp[b] << endl;
    return 0;
}
