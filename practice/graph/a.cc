/**
  *@filename:最小树形图
  *@author: pursuit
  *@created: 2021-08-17 14:34
**/
#include <bits/stdc++.h>

#define debug(a) cout << "debug : " << (#a) << " = " << a << endl

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
const int N = 1e4 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int n, m, root;  //n个结点m条有向边，以root为根。
int u, v, w;
int g[N][N], inCost[N], pre[N];  //inCost[u]存储u的最小入边花费。pre[u]存储u的前驱结点。
int id[N], vis[N];               //id[u]表示u重新编号的点，这个数组是为了处理有向环的。vis[u]表示u是通过vis[u]来访问的。
struct tree {
    int u, v, w;
} e[N];
int zhuliu() {
    int res = 0;  //res统计边权和。
    while(true) {
        for(int i = 0; i < n; ++i)
            inCost[i] = INF, id[i] = vis[i] = -1;  //初始化入边消耗等。
        for(int i = 0; i < m; ++i) {
            u = e[i].u, v = e[i].v, w = e[i].w;
            if(u != v && w < inCost[v]) {
                inCost[v] = w;
                pre[v] = u;
            }
        }
        for(int i = 0; i < n; ++i) {
            if(i != root && inCost[i] == INF) {
                //说明不存在入边，无法构成树形图。
                return -1;
            }
        }
        inCost[root] = 0;
        int tn = 0;  //新的编号。
        for(int i = 0; i < n; ++i) {
            res += inCost[i];  //统计入边消耗。
            v = i;
            while(vis[v] != i && id[v] == -1 && v != root) {
                vis[v] = i;
                v = pre[v];  //不断迭代前驱结点，知道更新到根结点。若是环，当处于vis[v] = i时即会退出，即回到起点。
            }
            if(v != root && id[v] == -1) {
                //说明不是以root为根结点。即出现了有向环
                id[v] = tn++;
                for(u = pre[v]; u != v; u = pre[u])
                    id[u] = tn;  //重新给有向环编号，便于之后缩点。
            }
        }
        if(tn == 0) break;  //说明没有重新编号，即不存在有向环。
        for(int i = 0; i < n; ++i) {
            if(id[i] == -1) {
                id[i] = tn++;  //给未重新编号的也重新编号，便于处理。
            }
        }
        int i = 0;
        while(i < m) {
            int vv = e[i].v;  //由于入边还存着是原来的编号，所以这里取出入边终点。
            //获取重新的编号。
            e[i].u = id[e[i].u], e[i].v = id[e[i].v];
            if(e[i].u != e[i].v) {
                //这里看做是环外一点入环内的v点，所以我们需要减去环内入边权。
                //这样可以避免重复计算。
                e[i++].w -= inCost[vv];  //更新权值，因为这个已经被累加了。
            } else {
                //将有向环环边抛出。
                swap(e[i], e[--m]);
            }
        }
        n = tn;           //更新新的结点数量。
        root = id[root];  //更新根结点编号。
    }
    return res;
}
void solve() {
    printf("%d\n", zhuliu());
}
int main() {
    freopen("/home/freaver/CODE_C/practice/input.txt", "r", stdin);
    freopen("/home/freaver/CODE_C/practice/output.txt", "w", stdout);
    scanf("%d%d%d", &n, &m, &root);
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            g[i][j] = INF;
    for(int i = 0; i < m; ++i) {
        scanf("%d%d%d", &u, &v, &w);
        //去除自环。
        if(u == v) continue;
        //去除重边。
        g[u][v] = min(g[u][v], w);
    }
    m = 0;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            //将边存储起来。
            if(g[i][j] != INF) { e[m].u = i, e[m].v = j, e[m++].w = g[i][j]; }
        }
    }
    solve();
    return 0;
}
