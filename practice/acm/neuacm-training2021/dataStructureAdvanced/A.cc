#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
using namespace std;
const int N = 5e4 + 1;

int a[N];

struct node
{
    int l, r, sum, lazy;

    node()
    {
        l = r = sum = lazy = 0;
    }
} nodes[N << 2];

inline int lc(int i)
{
    return i << 1;
}

inline int rc(int i)
{
    return i << 1 | 1;
}

void updateSum(int i)
{
    nodes[i].sum = nodes[lc(i)].sum + nodes[rc(i)].sum;
}

void pushDown(int i)
{
    int lazy = nodes[i].lazy;
    if (lazy) {
        nodes[lc(i)].lazy += lazy;
        nodes[rc(i)].lazy += lazy;
        int mid = (nodes[i].l + nodes[i].r) >> 1;
        nodes[lc(i)].sum += lazy * (mid - nodes[i].l + 1);
        nodes[rc(i)].sum += lazy * (nodes[i].r - mid);
        nodes[i].lazy = 0;
    }
}

inline void build(int i, int l, int r)
{
    nodes[i].l = l;
    nodes[i].r = r;
    if (l == r) {
        nodes[i].sum = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(lc(i), l, mid);
    build(rc(i), mid + 1, r);
    updateSum(i);
}

inline int query(int i, int l, int r)
{
    if (nodes[i].l >= l && nodes[i].r <= r) {
        return nodes[i].sum;
    }
    if (nodes[i].r < l || nodes[i].l > r) {
        return 0;
    }
    pushDown(i);
    int ans = 0;
    if (nodes[lc(i)].r >= l) {
        ans += query(lc(i), l, r);
    }
    if (nodes[rc(i)].l <= r) {
        ans += query(rc(i), l, r);
    }
    return ans;
}

inline void add(int i, int l, int r, int k)
{
    if (nodes[i].l >= l && nodes[i].r <= r) {
        nodes[i].sum += k * (nodes[i].r - nodes[i].l + 1) * k;
        nodes[i].lazy = k;
        return;
    }
    pushDown(i);
    if (nodes[lc(i)].r >= l) {
        add(lc(i), l, r, k);
    }
    if (nodes[rc(i)].l <= r) {
        add(rc(i), l, r, k);
    }
    updateSum(i);
}

inline void add(int i, int dis, int k)
{
    if (nodes[i].l == dis && nodes[i].r == dis) {
        nodes[i].sum += k;
        return;
    }
    pushDown(i);
    if (nodes[lc(i)].r >= dis) {
        add(lc(i), dis, k);
    } else {
        add(rc(i), dis, k);
    }
    updateSum(i);
}

int main(int argc, char* argv[])
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t, res = 0, n, tmp, i, j;
    string order;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int k = 1; k <= n; k++) {
            cin >> a[k];
        }
        build(1, 1, n);
        cout << "Case " << ++res << ":\n";
        while (cin >> order, order != "End") {
            cin >> i >> j;
            if (order == "Query") {
                cout << query(1, i, j) << "\n";
            } else if (order == "Add") {
                add(1, i, j);
            } else {
                add(1, i, -j);
            }
        }
    }
    return 0;
}
