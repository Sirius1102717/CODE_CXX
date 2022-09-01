#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 1e4 + 5;
// int con[N][N];
int f[N << 1];


struct node
{
    int x, y, c;
    friend bool operator<(const node& a, const node& b)
    {
        return a.c > b.c;
    }
} edge[N * 5];

bool cmp(node a, node b)
{
    return a.c > b.c;
}

int getParent(int x)
{
    return x == f[x] ? x : f[x] = getParent(f[x]);
}

int kruskal(int r)
{
    sort(edge, edge + r);
    int sum = 0;
    for (int i = 0; i < r; i++) {
        int x = getParent(edge[i].x);
        int y = getParent(edge[i].y);
        if (x != y) {
            f[y] = x;
            sum += edge[i].c;
        }
    }
    return sum;
}

int main(int argc, char* argv[])
{
    int t, n, m, r, x, y, c;
    scanf("%d", &t);
    while (t--) {
        // memset(f, -1, sizeof f);
        scanf("%d%d%d", &n, &m, &r);
        for (int i = 0; i < n + m; i++) {
            f[i] = i;
        }
        for (int i = 0; i < r; i++) {
            scanf("%d%d%d", &edge[i].x, &edge[i].y, &edge[i].c);
            edge[i].y += n;
        }

        printf("%d\n", (n + m) * 10000 - kruskal(r));
    }

    return 0;
}
