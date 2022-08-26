#include <algorithm>
#include <cstdio>
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
const int N = 1e5 + 5;
int V, E, r;

struct graph {
    int v, w;
    graph(int v, int w) : v(v), w(w) {}
};

struct node {
    int u, dis;
    node(int u, int dis) : u(u), dis(dis) {}
    bool friend operator>(node n1, node n2) {
        return n1.dis > n2.dis;
    }
};

vector<graph> e[N];
int dis[N];
int vis[N];
int u, v, w;

// priority_queue<node, vector<node>, greater<node>> q;
queue<int> q;
void dijkstra(int n, int s) {
    memset(dis, INF, sizeof dis);
    memset(vis, 0, sizeof vis);
    dis[s] = 0;
    q.emplace(s, 0);
    while(!q.empty()) {
        int u = q.top().u;
        q.pop();
        if(vis[u]) continue;
        vis[u] = 1;
        for(auto a : e[u]) {
            v = a.v, w = a.w;
            if(dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                q.emplace(v, dis[v]);
            }
        }
    }
}

int cnt[N];
bool spfa(int n, int s) {
    memset(dis, INF, sizeof dis);
    memset(vis, 0, sizeof vis);
    memset(cnt, 0, sizeof cnt);
    dis[s] = 0, vis[s] = 1;
    q.emplace(s);
    while(!q.empty()) {
        int u = q.front();
        q.pop(), vis[u] = 0;
        for(auto a : e[u]) {
            v = a.v, w = a.w;
            if(dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                cnt[v] = cnt[u] + 1;
                if(cnt[v] >= n) { return 0; }
                if(!vis[v]) { q.emplace(v), vis[v] = 1; }
            }
        }
    }
    return 1;
}

// void d(int n, int s) {
// memset(vis, 0, sizeof vis);
// dis[s] = 0;
// for(int i = 0; i < n; i++) {
// int mind = INF, u = 0;
// for(int j = 0; j < n; j++) {
// if(!vis[j] && dis[j] < mind) { u = j, mind = dis[j]; }
// }
// for(auto a : e[u]) {
// v = a.v, w = a.w;
// dis[v] = min(dis[v], dis[u] + w);
// }
// }
// }

int main(int argc, char* argv[]) {
    freopen("/home/freaver/CODE_C/practice/input.txt", "r", stdin);
    freopen("/home/freaver/CODE_C/practice/output.txt", "w", stdout);
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // memset(mp, INF, sizeof INF);
    scanf("%d%d%d", &V, &E, &r);
    for(int i = 0; i < E; i++) {
        scanf("%d%d%d", &u, &v, &w);
        e[u].emplace_back(v, w);
    }
    if(spfa(E, r)) {
        for(int i = 0; i < V; i++) {
            if(dis[i] == INF) {
                puts("INF");
            } else {
                printf("%d\n", dis[i]);
            }
        }
    } else {
        puts("NEGATIVE CYCLE");
    }
    // dijkstra(E, r);

    return 0;
}
