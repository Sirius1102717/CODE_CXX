#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
#define maxn 1000119
int a[maxn], bits[maxn], visit[maxn], ans[maxn], n, m;
;
// num数组保存原数列，tree树状数组，nnn保存结果
struct node
{
    int l, r;  //左右边界
    int pos;   //原位置（因为我们要离线排序后处理）
};
node ask[maxn];
bool cmp(node n1, node n2)
{
    return n1.r < n2.r;
    //快排大法好，没有什么是快排解决不来哦
    //实在不行就加上一个cmp
}
inline int lowbit(int n)
{
    return n & (-n);
    //树状数组核心操作×1
}
inline void add(int x, int now)
{
    while (x <= n) {
        bits[x] += now;
        x += lowbit(x);
    }
    //树状数组核心操作×2-->更新操作
}
inline int query(int x)
{
    int ans = 0;
    while (x) {
        ans += bits[x];
        x -= lowbit(x);
    }
    return ans;
    //树状数组核心操作×3———>查询操作
}

inline int rangeSum(int l, int r)
{
    return query(r) - query(l - 1);
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    // scanf("%d", &n);
    // for (int i = 1; i <= n; i++)
    //     scanf("%d", &a[i]);
    // scanf("%d", &m);
    // for (int i = 1; i <= m; i++) {
    //     scanf("%d%d", &ask[i].l, &ask[i].r);
    //     ask[i].pos = i;  //存储初始位置
    // }
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    cin >> m;
    for (int i = 1; i <= m; i++) {
        cin >> ask[i].l >> ask[i].r;
        ask[i].pos = i;
    }
    sort(ask + 1, ask + 1 + m, cmp);  //按r排序
    int next = 1;
    for (int i = 1; i <= m; i++) {
        for (int j = next; j <= ask[i].r; j++) {
            if (visit[a[j]])
                add(visit[a[j]], -1);
            //之前打过标记，在之前的位置加上-1，保证无重复
            add(j, 1);
            visit[a[j]] = j;
        }
        next = ask[i].r + 1;
        //更新下一次查询的位置
        // ans[ask[i].pos] = query(ask[i].r) - query(ask[i].l - 1);
        ans[ask[i].pos] = rangeSum(ask[i].l, ask[i].r);
        //按询问编号存储每组询问的结果
    }
    for (int i = 1; i <= m; i++)
        cout << ans[i] << endl;
    return 0;
}