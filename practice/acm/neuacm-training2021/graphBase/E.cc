#include <iostream>
#include <string>
#include <type_traits>
using namespace std;
const int INF = 0x3f3f3f3f;
const int N = 1e4 + 5;

struct node
{
    int to, nex;
} e[N << 1];
int head[N], tot = 0;

void add(int x, int y)
{
    e[++tot].to = y;
    e[tot].nex = head[x];
    head[x] = tot;
}
int depth[N], f[N][20], lg[N];

void init(int n)
{
    for (int i = 1; i <= n; i++) {
        lg[i] = lg[i - 1] + (1 << lg[i - 1] == i);
    }
}

void dfs(int now, int father)
{
    f[now][0] = father;
    depth[now] = depth[father] + 1;
    for (int i = 1; i <= lg[depth[now]]; i++) {
        f[now][i] = f[f[now][i - 1]][i - 1];
    }
    for (int i = head[now]; i; i = e[i].nex) {
        if (e[i].to != father) {
            dfs(e[i].to, now);
        }
    }
}

int lca(int x, int y)
{
    if (depth[x] < depth[y]) {
        swap(x, y);
    }
    while (depth[x] > depth[y]) {
        x = f[x][lg[depth[x] - depth[y]] - 1];
    }
    if (x == y) {
        return x;
    }
    for (int i = lg[depth[x]] - 1; i >= 0; i--) {
        if (f[x][i] != f[y][i]) {
            x = f[x][i];
            y = f[y][i];
        }
    }
    return f[x][0];
}

int main(int argc, char* argv[])
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m, s, x, y;
    cin >> n >> m;
    for (int i = 1; i < n; i++) {
        cin >> x >> y;
        add(x, y);
        add(y, x);
    }
    init(n);
    dfs(0, 0);
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        cout << lca(x, y) << "\n";
    }

    return 0;
}
