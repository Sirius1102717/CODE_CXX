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

int father[N];
vector<int> e[N];

struct node {
    int u, v;
    bool operator<(const node& n1) const {
        return u < n1.u || (u == n1.u && v < n1.v);
    }
};
int low[N], dfn[N], tim, child;
bool vis[N], flag[N];

vector<node> bridge;

void tarjan(int u, int fa) {
    low[u] = dfn[u] = ++tim;
    for(auto v : e[u]) {
        if(!dfn[v]) {
            tarjan(v, u);
            low[u] = min(low[u], low[v]);
            if(low[v] > dfn[u]) {
                vis[u] = 1;
                if(u < v) bridge.emplace_back(node{ u, v });
                else bridge.emplace_back(node{v, u});
            }
        } else if(dfn[v] < dfn[u] && v != fa)
            low[u] = min(low[u], dfn[v]);
    }
}
int main(int argc, char* argv[]) {
    freopen("/home/freaver/CODE_C/practice/input.txt", "r", stdin);
    freopen("/home/freaver/CODE_C/practice/output.txt", "w", stdout);
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
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
    // tarjan(0, -1);
    sort(bridge.begin(), bridge.end());
    for(auto b : bridge) {
        cout << b.u << ' ' << b.v << '\n';
    }

    return 0;
}
