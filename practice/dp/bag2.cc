#include <algorithm>
#include <cstring>
#include <deque>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <vector>
using namespace std;
using ll = long long;
const double EPS = 1e-8;
const ll MAXN = 1e18;
const int INF = 0x3f3f3f3f;
const int N = 105;
const int V = 1e5;
int w[N], v[N];
int dp[V + 5];

int main(int argc, char* argv[]) {
    freopen("/home/freaver/CODE_C/practice/input.txt", "r", stdin);
    freopen("/home/freaver/CODE_C/practice/output.txt", "w", stdout);
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, tot;
    cin >> n >> tot;
    memset(dp, INF, sizeof dp);
    dp[0] = 0;
    for(int i = 0; i < n; i++)
        cin >> v[i] >> w[i];
    for(int i = 0; i < n; i++)
        for(int j = V; j >= v[i]; j--)
            dp[j] = min(dp[j], dp[j - v[i]] + w[i]);
    int ans = 0;
    for(int i = 0; i <= V; i++)
        if(dp[i] <= tot) ans = max(i, ans);
    cout << ans << '\n';

    return 0;
}
