#include <iostream>
#include <string>
using namespace std;
const int N = 1e5 + 10;

struct node
{
    int to, nxt;
} e[N];

int bits[N], n, a, b, in[N], visit[N], m, u, out[N], inDegree = 0, head[N], tot = 1;
char c;

inline int lowbit(int x)
{
    return x & -x;
}

void initEdge(int u, int v)
{
    e[tot].to = v;
    e[tot].nxt = head[u];
    head[u] = tot;
    tot++;
}

void dfs(int x)
{
    in[x] = ++inDegree;
    for (int i = head[x]; i; i = e[i].nxt) {
        dfs(e[i].to);
    }
    out[x] = inDegree;
}

void update(int x, int k)
{
    while (x <= n) {
        bits[x] += k;
        x += lowbit(x);
    }
}

int sum(int x)
{
    int s = 0;
    while (x) {
        s += bits[x];
        x -= lowbit(x);
    }
    return s;
}

int main(int argc, char* argv[])
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i < n; i++) {
        cin >> a >> b;
        initEdge(a, b);
    }
    dfs(1);
    for (int i = 1; i <= n; i++) {
        update(in[i], 1);
        visit[i] = 1;
    }
    cin >> m;
    for (int i = 1; i <= m; i++) {
        cin >> c >> u;
        if (c == 'C') {
            if (visit[u]) {
                update(in[u], -1);
            } else {
                update(in[u], 1);
            }
            visit[u] = !visit[u];
        } else {
            cout << sum(out[u]) - sum(in[u] - 1) << "\n";
        }
    }

    return 0;
}
