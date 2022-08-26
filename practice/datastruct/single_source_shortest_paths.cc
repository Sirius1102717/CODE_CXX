#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <functional>
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

const int N = 5e5 + 5;

struct edge {
    int v;
    int w;
    edge(int v, int w) : v(v), w(w) {}
};

struct node {
    int dis, u;
    node(int dis, int u) : dis(dis), u(u) {}
    bool operator>(const node& a) const {
        return dis > a.dis;
    }
};

vector<edge> e[N];

int dis[N], cnt[N], vis[N];

// queue<int> q;

priority_queue<node, vector<node>, greater<node>> q;

// bool spfa(int n, int s) {
// memset(dis, INF, sizeof dis);
// memset(vis, 0, sizeof vis);
// memset(cnt, 0, sizeof cnt);
// dis[s] = 0, vis[s] = 0;
// q.emplace(s);
// while(!q.empty()) {
// int u = q.front();
// q.pop();
// vis[u] = 0;
// for(auto a : e[u]) {
// int v = a.v, w = a.w;
// if(dis[v] > dis[u] + w) {
// dis[v] = dis[u] + w;
// cnt[v] = cnt[u] + 1;
// if(cnt[v] >= n) return 0;
// if(!vis[v]) q.emplace(v), vis[v] = 1;
// }
// }
// }
// return 1;
// }

void dijkstra(int n, int s) {
    memset(dis, INF, sizeof dis);
    memset(vis, 0, sizeof vis);
    dis[s] = 0;
    q.emplace(0, s);
    while(!q.empty()) {
        int u = q.top().u;
        q.pop();
        if (!vis[u]) {
            vis[u] = 1;
            for (auto a : e[u]) {
                int v = a.v, w = a.w;
                if (dis[v] > dis[u] + w) {
                    dis[v] = dis[u] + w;
                    q.emplace(dis[v], v);
                }
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
    int n, u, k, v, w;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> u >> k;
        while(k--) {
            cin >> v >> w;
            e[u].emplace_back(v, w);
        }
    }
    // spfa(n, 0);
    dijkstra(n, 0);
    for(int i = 0; i < n; i++)
        cout << i << ' ' << dis[i] << '\n';

    return 0;
}
