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

struct node {
    int b;
    int e;
    node() {
        b = e = 0;
    }
    vector<int> nex;
} e[N];

bool vis[N];
bool vvis[N];
int cur = 1;
int n;

void dfs(int u) {
    if(!vis[u]) {
        e[u].b = cur++;
        vis[u] = 1;
        for(auto a : e[u].nex) {
            dfs(a);
        }
        e[u].e = cur++;
        // } else if(!vvis[u]) {
        // e[u].e = cur;
        // vvis[u] = 1;
    }
}

int main(int argc, char* argv[]) {
    freopen("/home/freaver/CODE_C/practice/input.txt", "r", stdin);
    freopen("/home/freaver/CODE_C/practice/output.txt", "w", stdout);
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int u, k, v;
    cin >> n;
    memset(vis, 0, sizeof vis);
    memset(vvis, 0, sizeof vvis);
    for(int i = 1; i <= n; i++) {
        cin >> u >> k;
        while(k--) {
            cin >> v;
            e[u].nex.emplace_back(v);
        }
    }
    for(int i = 1; i <= n; i++) {
        if(!vis[i]) dfs(i);
    }
    for(int i = 1; i <= n; i++) {
        cout << i << ' ' << e[i].b << ' ' << e[i].e << '\n';
    }

    return 0;
}
