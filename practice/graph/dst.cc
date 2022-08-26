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
const int N = 1e3 + 5;
int n, m, root;
int u, v, w;
int g[N][N], inCost[N], pre[N];
int id[N], vis[N];

struct tree {
    int u;
    int v;
    int w;
} e[N];

int zhuliu() {
    int res = 0;
    while(1) {
        for(int i = 0; i < n; i++)
            inCost[i] = INF, id[i] = vis[i] = -1;
        for(int i = 0; i < m; i++) {
            u = e[i].u, v = e[i].v, w = e[i].w;
            if(u != v && w < inCost[v]) {
                inCost[v] = w;
                pre[v] = u;
            }
        }
        for(int i = 0; i < n; i++) {
            if(i != root && inCost[i] == INF) return -1;
        }

        inCost[root] = 0;
        int tn = 0;
        for(int i = 0; i < n; i++) {
            res += inCost[i];
            v = i;
            while(vis[v] != i && id[v] == -1 && v != root) {
                vis[v] = i;
                v = pre[v];
            }
            if(v != root && id[v] == -1) {
                for(u = pre[v]; u != v; u = pre[u])
                    id[u] = tn;
                id[v] = tn++;
            }
        }
        if(!tn) break;
        for(int i = 0; i < n; i++) {
            if(id[i] == -1) id[i] = tn++;
        }
        for (int i = 0; i < m; i++) {
            u = e[i].u, v = e[i].v;
            e[i].u = id[u], e[i].v = id[v];
            if (e[i].u != e[i].v) e[i].w -= inCost[v];
        }
        n = tn;
        root = id[root];
    }
    return res;
}
int main(int argc, char* argv[]) {
    freopen("/home/freaver/CODE_C/practice/input.txt", "r", stdin);
    freopen("/home/freaver/CODE_C/practice/output.txt", "w", stdout);
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> root;
    memset(g, INF, sizeof g);
    for (int i = 0; i < m; i++) {
        cin >> u >> v >> w;
        if (u != v) g[u][v] = min(g[u][v], w) ;
        // cin >> e[i].u >> e[i].v >> e[i].w;
    }
    m = 0;
    for (int i = 0; i < n; i++) {
        for (int j =0 ; j < n; j++) {
            if (g[i][j] != INF) e[m].u = i, e[m].v = j, e[m++].w = g[i][j];
        }
    }
    cout << zhuliu() << '\n';
    return 0;
}
