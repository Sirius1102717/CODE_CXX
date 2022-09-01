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

vector<int> e[N];

int in[N];
int dis[N];

int dfs(int u) {
    if(dis[u] > 0) return dis[u];
    for(auto v : e[u])
        dis[u] = max(dis[u], dfs(v) + 1);
    return dis[u];
}
int main(int argc, char* argv[]) {
    freopen("/home/freaver/CODE_C/practice/input.txt", "r", stdin);
    freopen("/home/freaver/CODE_C/practice/output.txt", "w", stdout);
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, u, v;
    cin >> n >> m;
    while(m--) {
        cin >> u >> v;
        in[v]++;
        e[u].emplace_back(v);
    }
    for(int i = 1; i <= n; i++) {
        if(!in[i]) dfs(i);
    }
    int ans = 0;
    for(int i = 1; i <= n; i++)
        ans = max(ans, dis[i]);
    cout << ans << '\n';

    return 0;
}
