#include <iostream>
const int maxn = 1e6 + 10;

int n, m, a[maxn];
struct node
{
    int l;
    int r;
    int sum;
    int lazy;
} nodes[maxn << 2];

void updateSum(int i)
{
    nodes[i].sum = nodes[i << 1].sum + nodes[i << 1 | 1].sum;
}
void pushdown(int i)
{
    if (nodes[i].lazy) {
        nodes[i << 1].sum = nodes[i].lazy * (nodes[i << 1].r - nodes[i << 1].l + 1);
        nodes[i << 1 | 1].sum = nodes[i].lazy * (nodes[i << 1 | 1].r - nodes[i << 1 | 1].l + 1);
        nodes[i << 1].lazy = nodes[i].lazy;
        nodes[i << 1 | 1].lazy = nodes[i].lazy;
        nodes[i].lazy = 0;
    }
}
void build(int i, int l, int r)
{
    nodes[i].l = l, nodes[i].r = r, nodes[i].lazy = 0;
    if (l == r) {
        nodes[i].sum = 1;
        return;
    }
    int mid = (l + r) >> 1;
    build(i << 1, l, mid);
    build(i << 1 | 1, mid + 1, r);
    updateSum(i);
}
void change(int i, int l, int r, int z)
{
    if (l <= nodes[i].l && nodes[i].r <= r) {
        nodes[i].sum = z * (nodes[i].r - nodes[i].l + 1);
        nodes[i].lazy = z;
        return;
    }
    pushdown(i);
    int mid = (nodes[i].l + nodes[i].r) >> 1;
    if (l <= mid)
        change(i << 1, l, r, z);
    if (r > mid)
        change(i << 1 | 1, l, r, z);
    updateSum(i);
}
int q, tot;

int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(0);cout.tie(0);
    scanf("%d", &m);
    while (m--) {
        scanf("%d", &n);
        build(1, 1, n);
        scanf("%d", &q);
        while (q--) {
            int x, y, z;
            scanf("%d%d%d", &x, &y, &z);
            change(1, x, y, z);
        }
        printf("Case %d: The total value of the hook is %d.\n", ++tot, nodes[1].sum);
    }
    return 0;
}
