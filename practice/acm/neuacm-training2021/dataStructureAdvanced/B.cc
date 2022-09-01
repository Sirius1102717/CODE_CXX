#include <cstdio>
#include <cstring>
const int N = 1e5 + 1;
struct node
{
    int l, r, sum, lazy;
} nodes[N << 2];

inline int lc(int i)
{
    return i << 1;
}

inline int rc(int i)
{
    return i << 1 | 1;
}

inline void updateSum(int i)
{
    nodes[i].sum = nodes[lc(i)].sum + nodes[rc(i)].sum;
}

void pushDown(int i)
{
    int lazy = nodes[i].lazy;
    if (lazy) {
        nodes[lc(i)].sum = (nodes[lc(i)].r - nodes[lc(i)].l + 1) * lazy;
        nodes[rc(i)].sum = (nodes[rc(i)].r - nodes[rc(i)].l + 1) * lazy;
        nodes[lc(i)].lazy = lazy;
        nodes[rc(i)].lazy = lazy;
        nodes[i].lazy = 0;
    }
}

inline void build(int i, int l, int r)
{
    nodes[i].l = l, nodes[i].r = r, nodes[i].lazy = 0;
    if (l == r) {
        nodes[i].sum = 1;
        return;
    }
    int mid = (l + r) >> 1;
    build(lc(i), l, mid);
    build(rc(i), mid + 1, r);
    updateSum(i);
}

inline void update(int i, int l, int r, int k)
{
    if (nodes[i].l >= l && nodes[i].r <= r) {
        nodes[i].sum = k * (nodes[i].r - nodes[i].l + 1);
        nodes[i].lazy = k;
        return;
    }
    pushDown(i);
    if (nodes[lc(i)].r >= l) {
        update(lc(i), l, r, k);
    }
    if (nodes[rc(i)].l <= r) {
        update(rc(i), l, r, k);
    }
    updateSum(i);
}
int t, n, q, x, y, z, res = 0;
int main(int argc, char* argv[])
{
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        build(1, 1, n);
        scanf("%d", &q);
        while (q--) {
            scanf("%d%d%d", &x, &y, &z);
            update(1, x, y, z);
        }
        printf("Case %d: The total value of the hook is %d.\n", ++res, nodes[1].sum);
    }
    return 0;
}
