#include <algorithm>
#include <cstring>
#include <deque>
#include <iostream>
#include <math.h>
#include <queue>
#include <stack>
#include <string>
#include <vector>
using namespace std;
using ll = long long;
const double EPS = 1e-8;
const ll MAXN = 1e18;
const int INF = 0x3f3f3f3f;
const int N = 100;
const int M = 200;

struct edge {
    int to, nex, w;
} E[N];

int head[N];

struct graph {
    int v, u, w;

    friend bool operator==(graph g1, graph g2) {
        return g1.u == g2.u && g1.v == g2.v && g1.w == g2.w;
    }

    friend bool operator!=(graph g1, graph g2) {
        return !(g1 == g2);
    }

} e[N];


int dis[N];

bool vis[N];
void bellman_ford(int begin) {
    memset(dis, INF, sizeof dis);
    dis[begin] = 0;
    graph backup[N];
    for(int i = 0; i < N; i++) {
        copy(e, e + N, backup);
        for(int j = 0; j < M; j++) {
            dis[e[j].v] = min(dis[e[j].v], dis[e[j].u] + e[j].w);
        }
        bool flag;
        for(int i = 0; i < N; i++) {
            if(e[i] != backup[i]) {
                flag = 0;
                break;
            }
        }
        if(flag) {
            break;
        }
    }
}

void SPFA(int begin) {
    memset(dis, INF, sizeof dis);
    dis[begin] = 0, vis[begin] = 1;
    queue<int> q;
    q.push(begin);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        vis[u] = 0;
        for (int i = head[u]; ~i; i = E[i].nex) {
            int v = E[i].to, w = E[i].w;
            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                if (!vis[v]) {
                    q.push(v);
                    vis[v] = 1;
                }
            }
        }
    }
}


int main(int argc, char* argv[]) {
    freopen("/home/freaver/CODE_C/input.txt", "r", stdin);
    freopen("/home/freaver/CODE_C/output.txt", "w", stdout);
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    return 0;
}
