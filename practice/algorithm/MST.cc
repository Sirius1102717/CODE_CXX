#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const double EPS = 1e-8;
const ll MAXN = 1e3;
const int INF = 0x3f3f3f3f;

int mp[MAXN][MAXN], dist[MAXN], n, f[MAXN];
bool visit[MAXN];

struct node
{
    int u, v, c;

    friend bool operator<(const node& a, const node& b)
    {
        return a.c < b.c;
    }
} edge[MAXN];

bool cmp(node a, node b)
{
    return a.c < b.c;
}

int getParent(int x)
{
    return x == f[x] ? x : f[x] = getParent(f[x]);
}

int kruskal()
{
    sort(edge + 1, edge + MAXN);
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        int u = getParent(edge[i].u);
        int v = getParent(edge[i].v);
        if (u == v) {
            continue;
        }
        f[v] = u;
        sum += edge[i].c;
    }
    return sum;
}

int prim(int pos)
{
    dist[pos] = 0;
    ll sum = 0;
    for (int i = 1; i <= n; i++) {
        int cur = -1;
        for (int j = 1; j <= n; j++) {
            if (!visit[j] && (cur == -1 || dist[j] < dist[cur])) {
                cur = j;
            }
        }

        if (dist[cur] >= INF) {
            return INF;
        }
        sum += dist[cur];
        visit[cur] = 1;
        for (int k = 1; k <= n; k++) {
            if (!visit[k]) {
                dist[k] = min(dist[k], mp[cur][k]);
            }
        }
    }
    return sum;
}

int main(int argc, char* argv[])
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    return 0;
}
