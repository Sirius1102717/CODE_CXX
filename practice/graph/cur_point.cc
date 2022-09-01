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
const int N = 1e5 + 5;
int n, m;
int dfn[N], low[N], tim;
bool vis[N], flag[N];

vector<int> e[N];

void tarjan(int u, int fa) {
    vis[u] = 1;
    low[u] = dfn[u] = ++tim;
    int child = 0;
    for(auto v : e[u]) {
        if(!vis[v]) {
            child++;
            tarjan(v, u);
            low[u] = min(low[u], low[v]);
            if(fa != u && low[v] >= dfn[u]) flag[u] = 1;
        } else if(v != fa)
            low[u] = min(low[u], low[v]);
    }
    if(fa == u && child > 1) flag[u] = 1;
}

int main(int argc, char* argv[]) {
    freopen("/home/freaver/CODE_C/practice/input.txt", "r", stdin);
    freopen("/home/freaver/CODE_C/practice/output.txt", "w", stdout);
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    int u, v;
    for(int i = 0; i < m; i++) {
        cin >> u >> v;
        e[u].emplace_back(v);
        e[v].emplace_back(u);
    }
    for(int i = 0; i < n; i++) {
        if(!vis[i]) {
            tim = 0;
            tarjan(i, i);
        }
    }
    for(int i = 0; i < n; i++) {
        if(flag[i]) cout << i << '\n';
    }

    return 0;
}
