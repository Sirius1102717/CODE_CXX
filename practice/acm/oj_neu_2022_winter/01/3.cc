#include <algorithm>
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
const double EPS = 1e-8;
const ll MAXN = 1e18;
const int INF = 0x3f3f3f3f;
const int M = 2e5 + 5;
const int N = 1e5 + 5;

int n, m;
// ll p[M], q[M], c[M];
int p, q, c;

struct edge {
    int v, w;
    edge(int v, int w) : v(v), w(w) {}
};

struct node {
    int u, c;
    node(int u, int c) : u(u), c(c) {}
};

vector<edge> e[N];

queue<node> qq;

int cnt[M];
int dis[M];
bool vis[M];
int ans = INF;
bool flag = 0;

bool spfa(int n, int r, int w) {
    memset(cnt, 0, sizeof cnt);
    memset(dis, 63, sizeof cnt);
    memset(vis, 0, sizeof vis);
    dis[r] = 0, vis[r] = 1;
    dis[1] = 0, vis[1] = 1;
    qq.emplace(r, w);
    while(!qq.empty()) {
        int u = qq.front().u;
        int c = qq.front().c;
        qq.pop();
        vis[u] = 0;
        for(auto a : e[u]) {
            int v = a.v, w = a.w;
            if(dis[v] > dis[u] + w != c) {
                // dis[v] = min(dis[u] + (w != c), dis[v]);
                dis[v] = dis[u] + w != c;
                cnt[v] = cnt[u] + 1;
                if(cnt[v] >= n) return 0;
                if(!vis[v]) {
                    qq.emplace(v, w);
                    vis[v] = 1;
                }
            }
        }
    }
    return 1;
}

int dp[M];

int main(int argc, char* argv[]) {
    freopen("/home/freaver/CODE_C/practice/input.txt", "r", stdin);
    freopen("/home/freaver/CODE_C/practice/output.txt", "w", stdout);
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; i++) {
        // scanf("%lld%lld%lld", &p[i], &q[i], &c[i]);
        // e[p[i]].emplace_back(q[i], c[i]);
        // e[q[i]].emplace_back(p[i], c[i]);
        scanf("%d%d%d", &p, &q, &c);
        e[p].emplace_back(q, c);
        e[q].emplace_back(p, c);
    }
    for(auto a : e[1]) {
        flag ? spfa(n, a.v, a.w) : flag = spfa(n, a.v, a.w);
        ans = min(ans, dis[n]);
    }
    if(!flag || ans == INF) {
        printf("-1\n");
    } else {
        printf("%d\n", ans);
    }

    return 0;
}
