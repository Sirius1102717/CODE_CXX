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

bool vis[N];

vector<int> e[N];

int dis[N];

queue<int> q;

void bfs() {
    q.emplace(1);
    dis[1] = 0;
    vis[1] = 1;
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto v : e[u]) {
            if (!vis[v]) {
                vis[v] = 1;
                dis[v] = dis[u] + 1;
                q.emplace(v);
            }
        }
    }
}

int main(int argc, char* argv[]) {
    freopen("/home/freaver/CODE_C/practice/input.txt", "r", stdin);
    freopen("/home/freaver/CODE_C/practice/output.txt", "w", stdout);
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, u, k, v;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        dis[i] = -1;
        cin >> u >> k;
        while(k--) {
            cin >> v;
            e[u].emplace_back(v);
        }
    }
    bfs();
    for (int i = 1; i <= n; i++) cout << i << ' ' << dis[i] << '\n';

    return 0;
}
