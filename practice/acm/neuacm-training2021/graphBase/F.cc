#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;
const int N = 1e5 + 1;
const int INF = 0x3f3f3f3f;
int n, m, u, v;
int val[N], in[N], out[N], dp[N];

vector<int> e[N];

void topSort()
{
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (!in[i]) {
            q.push(i);
            dp[i] = val[i];
        } else {
            dp[i] = -INF;
        }
    }
    while (q.size()) {
        u = q.front();
        q.pop();
        for (int i = 0; i < e[u].size(); i++) {
            v = e[u][i];
            dp[v] = max(dp[v], dp[u] + val[v]);
            in[v]--;
            if (!in[v]) {
                q.push(v);
            }
        }
    }
}

int main(int argc, char* argv[])
{
    while (~scanf("%d%d", &n, &m) ) {
        for (int i = 1;i <= n; i++) {
            scanf("%d", &val[i]);
            in[i] = out[i] = 0;
            e[i].clear();

        }
        while (m--) {
            scanf("%d%d", &u, &v);
            e[u].push_back(v);
            in[v]++, out[u]++;
        }
        topSort();
        int ans = -INF;
        for (int i = 1; i <= n; i++) {
            if (!out[i] && dp[i] > ans) {
                ans = dp[i];
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
