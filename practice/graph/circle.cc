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
const int N = 1e2 + 5;

vector<int> e[N];

bool vis[N];

bool flag = 1;

void dfs(int b, int u) {
    for(auto v : e[u]) {
        if(v == b) {
            cout << "1\n";
            flag = 0;
            return;
        }
        if(!vis[v]) dfs(b, v);
    }
}

int main(int argc, char* argv[]) {
    freopen("/home/freaver/CODE_C/practice/input.txt", "r", stdin);
    freopen("/home/freaver/CODE_C/practice/output.txt", "w", stdout);
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, u, v;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        cin >> u >> v;
        e[u].emplace_back(v);
    }
    for(int i = 0; i < n; i++) {
        memset(vis, 0, sizeof vis);
        if(flag)
            dfs(i, i);
        else
            break;
    }
    if(flag) cout << "0\n";
    return 0;
}
