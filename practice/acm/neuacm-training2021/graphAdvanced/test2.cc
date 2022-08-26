// dfn[i]表示i点被访问的时间戳(次序编号)
// low[i]表示i点通过有向边所能回溯到的最小时间戳
// book[i]表示i点是否在栈中
// time为时间戳
// num[i]表示第i个强连通分量的个数
// in[i]表示i的进度
// out[i]表示i的出度
// head[i]表示以i为起点的最后一条边的编号，要初始为-1
#include <algorithm>
#include <stack>
#include <stdio.h>
#include <string.h>
using namespace std;
const int N = 2e2 + 100;  //
int dfn[N], low[N], book[N], head[N];
int num[N], in[N], out[N], a[N];
int cnt, time, n, m, sum, ans;
stack<int> s;
struct pp
{
    int to, next;
} e[N * 6];
void add(int u, int v)  //链式前向星建图
{
    e[cnt].to = v;          //相连点
    e[cnt].next = head[u];  // Next表示与这个边起点相同的上一条边的编号
    head[u] = cnt++;        //更新以u为起点的上一条边的编号
}
void tarjan(int x)
{
    dfn[x] = low[x] = ++time;  //给u设定初始时间戳
    s.push(x);                 // u进栈
    book[x] = 1;               //标记u，表明u在栈中
    // head[u]表示以u为起点的最后一条边的编号
    //然后通过e[i].next来找下一条边的编号
    for (int i = head[x]; ~i; i = e[i].next) {
        int to = e[i].to;  //当前点的邻点
        if (!dfn[to])      //目标点没有被访问过
        {
            tarjan(to);                     //继续向下找
            low[x] = min(low[to], low[x]);  //更新low
        }
        if (book[to])                       //在栈中
            low[x] = min(low[to], low[x]);  //更新low
    }
    if (dfn[x] == low[x])  //如果当前low==dfn，说明这个点是强连通分量的根节点
    {
        ans++;  //记录强连通分量个数
        while (!s.empty()) {
            num[ans]++;         //记录第几个强连通分量的个数
            int now = s.top();  //栈顶
            s.pop();            //出栈
            book[now] = 0;      //取消标记
            a[now] = ans;       //标记这个点是第几个强连通分量中的
            if (now == x)       //结束
                break;
        }
    }
}
int main()
{
    int u, v, i, j;
    scanf("%d%d", &n, &m);
    memset(head, -1, sizeof(head));
    for (i = 1; i <= n; i++)
        a[i] = i;
    sum = time = cnt = ans = 0;
    while (m--) {
        scanf("%d%d", &u, &v);
        add(u, v);
    }
    for (i = 1; i <= n; i++)
        if (!dfn[i])
            tarjan(i);
    for (i = 1; i <= n; i++)  //缩点
    {
        for (j = head[i]; j != -1; j = e[j].next) {
            if (a[i] == a[e[j].to])  //如果是同一个强连通分量中的不用管入出度
                continue;
            in[a[e[j].to]]++;
            out[a[i]]++;
        }
    }
    int sout = 0;
    for (i = 1; i <= ans; i++) {  // printf("%d  %d+++\n",in[i],out[i]);
        if (!out[i])              //出度为零
        {
            sout++;
            sum = num[i];  //所求数量
        }
        if (sout >= 2)  //多个出度为零的点
        {
            sum = 0;  //答案为0
            break;
        }
    }
    printf("%d\n", sum);
    return 0;
}
