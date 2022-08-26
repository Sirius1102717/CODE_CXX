#include <iostream>
#include <stdio.h>
using namespace std;
const int N = 1e3 + 5, inf = 0x7fffffff;
int n, m, q[N << 1], d[N << 1], mark[N << 1];
int tot, head[N << 1], Next[N * N << 2], vet[N * N << 2];
char g[N][N];
void add(int a, int b)
{
    Next[++tot] = head[a];
    vet[tot] = b;
    head[a] = tot;  
}
void bfs()
{
    for (int i = 1; i <= n + m; i++)
        d[i] = inf;  
    int le = 0, ri = 0;
    d[1] = 0, q[++ri] = 1, mark[1] = 1;
    while (le < ri)  
    {
        int x = q[++le];
        for (int i = head[x]; i; i = Next[i]) {
            int y = vet[i];
            if (mark[y])
                continue;
            d[y] = d[x] + 1;
            q[++ri] = y;
            mark[y] = 1;
        }
    }
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%s", g[i] + 1);  
        for (int j = 1; j <= m; j++)
            if (g[i][j] == '#')
                add(i, j + n), add(j + n, i);
    }
    bfs();
    if (d[n] == inf)
        printf("-1");
    else
        printf("%d", d[n]);
    return 0;
}