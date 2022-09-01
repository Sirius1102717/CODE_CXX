#include<iostream>
#include<string>
#include<cstring>
#include<vector>
#include<algorithm>
#include<deque>
#include<queue>
#include<stack>
using namespace std;
using ll = long long;
const double EPS = 1e-8;
const ll MAXN = 1e18;
const int INF = 0x3f3f3f3f;
const int N = 1e5 + 5;
vector<int> g[N];
vector<int> g2[N];
int n, m, u, v;

bool vis[N];
int color[N];
int cnt;

vector<int> s;

void dfs1(int u) {
    vis[u] = 1;
    for (int v : g[u]) 
        if (!vis[v]) dfs1(v);
    s.emplace_back(u);
}


void dfs2(int u) {
    color[u] = cnt;
    for (int v : g2[u]) 
        if(!color[v]) dfs2(v);
}

void kosaraju() {
    memset(vis, 0, sizeof vis);
    memset(color, 0, sizeof color);
    cnt = 0;
    for (int i = 0; i < n; i++)  
        if (!vis[i]) dfs1(i);
    for (int i = n - 1; i >= 0; i--) {
        if (!color[s[i]]) {
            cnt++;
            dfs2(s[i]);
        }
    }
}
int main(int argc, char *argv[]) {
    freopen("/home/freaver/CODE_C/practice/input.txt", "r", stdin);
    freopen("/home/freaver/CODE_C/practice/output.txt", "w", stdout);
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        g[u].emplace_back(v);
        g2[v].emplace_back(u);
    }
    int q;
    cin >> q;
    kosaraju();
    while(q--) {
        cin >> u >> v;
        if (color[u] == color[v]) cout << "1\n";
        else cout << "0\n";
    }

    return 0;
}
