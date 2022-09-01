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
const ll INF = 2e15;
const int N = 1e2 + 5;
int V, E, r;

ll dis[N];
bool vis[N];
int u, v;
ll w;
ll h[N];
ll mp[N][N];
ll tmp_mp[N][N];
bool floyd(int n) {
    for(int k = 0; k < n; k++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(mp[i][k] != INF && mp[k][j] != INF) mp[i][j] = min(mp[i][j], mp[i][k] + mp[k][j]);
            }
            if(mp[i][i] < 0) return 0;
        }
    }
    return 1;
}

struct edge {
    int v;
    ll w;
    edge(int v, ll w) : v(v), w(w) {}
};

struct node {
    int u;
    ll dis;
    node(int u, ll dis) : u(u), dis(dis) {}
    bool operator>(const node n) const {
        return dis > n.dis;
    }
};

priority_queue<node, vector<node>, greater<node>> pq;

vector<edge> e[N];

queue<int> q;

int cnt[N];

void dijkstra(int n, int r) {
    memset(dis, 63, sizeof dis);
    memset(vis, 0, sizeof vis);
    pq.emplace(r, 0);
    dis[r] = 0;
    while(!pq.empty()) {
        u = pq.top().u;
        pq.pop();
        if(vis[u]) continue;
        vis[u] = 1;
        for(auto a : e[u]) {
            v = a.v, w = a.w;
            if(dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                pq.emplace(v, dis[v]);
            }
        }
    }
}

bool spfa(int n, int s) {
    memset(h, 63, sizeof h);
    memset(vis, 0, sizeof vis);
    memset(cnt, 0, sizeof cnt);
    h[s] = 0, vis[s] = 1;
    q.emplace(s);
    while(!q.empty()) {
        int u = q.front();
        q.pop(), vis[u] = 0;
        for(auto a : e[u]) {
            v = a.v, w = a.w;
            if(h[v] > h[u] + w) {
                h[v] = h[u] + w;
                cnt[v] = cnt[u] + 1;
                if(cnt[v] >= n) return 0;
                if(!vis[v]) {
                    q.emplace(v);
                    vis[v] = 1;
                }
            }
        }
    }
    return 1;
}

bool johnson(int n) {
    memset(dis, 63, sizeof dis);
    for(int i = 0; i < n; i++) {
        e[n].emplace_back(i, 0);
    }
    spfa(n + 1, n);
    // for (int i = 0; i < 0; i++) {
    // for (int j = 0; j < n; j++) {
    // mp[i][j] += h[j] - h[i];
    // }
    // }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < e[i].size(); j++) {
            e[i][j].w += h[i] - h[j];
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            dis[j] = mp[i][j];
        }
        memset(vis, 0, sizeof vis);
        dijkstra(n, i);
        for(int j = 0; j < V; j++) {
            if(dis[j] == INF) {
                printf("INF ");
            } else {
                printf("%lld ", dis[j] + h[j] - h[i]);
            }
        }
        puts("");
    }
    return 1;
}

int main(int argc, char* argv[]) {
    freopen("/home/freaver/CODE_C/practice/input.txt", "r", stdin);
    freopen("/home/freaver/CODE_C/practice/output.txt", "w", stdout);
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    scanf("%d%d", &V, &E);
    for(int i = 0; i < V; i++) {
        for(int j = 0; j < V; j++) {
            mp[i][j] = i == j ? 0 : INF;
        }
    }
    for(int i = 0; i < E; i++) {
        scanf("%d%d%lld", &u, &v, &w);
        mp[u][v] = w;
        e[u].emplace_back(v, w);
        // e[u].emplace_back(v, w);
    }

    // if(!johnson(V)) { puts("NEGATIVE CYCLE"); }

    if(!floyd(V)) {
        puts("NEGATIVE CYCLE");
    } else {
        for(int i = 0; i < V; i++) {
            for(int j = 0; j < V; j++) {
                if(mp[i][j] == INF) {
                    printf("INF ");
                } else {
                    printf("%lld ", mp[i][j]);
                }
            }
            puts("");
        }
    }
    return 0;
}
