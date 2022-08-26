#include <algorithm>
#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;
const int inf = 0x3f3f3f3f;
int ans[maxn], cost[maxn], in[maxn], out[maxn];
vector<int> s, e;
vector<int> e[maxn];
int n, m;
void addedge(int u, int v)
{
    e[u].push_back(v);
}
void tuopu()
{
    queue<int> q;
    for (int i = 0; i < s.size(); i++) {
        int x = s[i];
        q.push(x);
        ans[x] = cost[x];
    }
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        for (int i = 0; i < e[now].size(); i++) {
            int v = e[now][i];
            ans[v] = max(ans[v], ans[now] + cost[v]);
            in[v]--;
            if (in[v] == 0) {
                q.push(v);
            }
        }
    }
}
void solve()
{
    for (int i = 1; i <= n; i++) {
        in[i] = 0;
        out[i] = 0;
        cost[i] = 0;
        ans[i] = -inf;
        e[i].clear();
    }
    s.clear();
    e.clear();
    for (int i = 1; i <= n; i++) {
        scanf("%d", &cost[i]);
    }
    for (int i = 1; i <= m; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        addedge(u, v);
        in[v]++;
        out[u]++;
    }
    for (int i = 1; i <= n; i++) {
        if (in[i] == 0)
            s.push_back(i);
        if (out[i] == 0)
            e.push_back(i);
    }
    tuopu();
    int tans = -inf;
    for (int i = 0; i < e.size(); i++) {
        int x = e[i];
        tans = max(tans, ans[x]);
    }
    printf("%d\n", tans);
}
int main()
{
    while (~scanf("%d%d", &n, &m)) {
        solve();
    }
    return 0;
}
