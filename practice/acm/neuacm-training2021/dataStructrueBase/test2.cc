#include<bits/stdc++.h>
using namespace std;
const double EPS = 1e-8;
const int MAXN = 1e6 + 1;

int dp[MAXN];
int main(int argc, char *argv[])
{
    int T;
    cin >> T;
    while ( T-- ) {
        int x, k, t;
        cin >> x >> k >> t;
        memset(dp, MAXN, sizeof dp);
        dp[1] = 0;
        for ( int i = 2; i <= x; i++ ) {

            if ( i % k == 0 ) {
                dp[i] = min(dp[i / k] + 1, dp[i]);
            }
            int lim = min(i, t);
            for ( int j = 1; j <= lim; j++ ) {
                dp[i] = min(dp[i], dp[i - j] + 1);
            }
        }
        cout << dp[x] << "\n";
    }

    return 0;
}


dp[next] = 1;        //next节点自身先算上
int maxs = 0;
for ( int i = head[next]; ~i; i = edges[i].next ) {
    int to = edges[i].to;
    if ( to != father ) {
        dfs(to, next);
        dp[next] += dp[to];
        maxs = max(maxs, dp[to]);   //求最大的节点数量
    }
}
maxs = max(maxs, n - dp[next]);
if ( maxs < mins ) {
    mins = maxs;
    id = next;
}