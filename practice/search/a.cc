#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const double EPS = 1e-8;
const int N = 1e6 + 1;

struct tree {
    ll sum;
    ll l;
    ll r;
    ll lazy = 0;
};

tree tree[N << 2];

inline int lc(int x) {
    return x << 1;
}

inline int rc(int x) {
    return x << 1 | 1;
}

void pushDown(int i) {
    if(tree[i].lazy) {
        tree[lc(i)].lazy += tree[i].lazy;
        tree[rc(i)].lazy += tree[i].lazy;
        int mid = (tree[i].l + tree[i].r) / 2;
        tree[lc(i)].sum += tree[i].lazy * (mid - tree[lc(i)].l + 1);
        tree[rc(i)].sum += tree[i].lazy * (tree[rc(i)].r - mid);
        tree[i].lazy = 0;
    }
}

int a[N];

inline void build(int i, int l, int r) {
    tree[i].l = l;
    tree[i].r = r;
    if(l == r) {
        tree[i].sum = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(lc(i), l, mid);
    build(rc(i), mid + 1, r);
    tree[i].sum = tree[lc(i)].sum + tree[rc(i)].sum;
}

inline ll search(int i, int l, int r) {
    if(tree[i].l >= l && tree[i].r <= r) { return tree[i].sum; }
    if(tree[i].r < l || tree[i].l > r) { return 0; }
    pushDown(i);
    ll res = 0;
    if(tree[lc(i)].r >= l) { res += search(lc(i), l, r); }
    if(tree[rc(i)].l <= r) { res += search(rc(i), l, r); }
    return res;
}

// inline ll search(int i, int dis)
// {

//     if ( tree[i].l == tree[i].r ) {
//         return tree[i].sum;
//     }
//     if ( dis <= tree[lc(i)].r ) {
//         search(lc(i), dis);
//     }
//     if ( dis >= tree[rc(i)].l ) {
//         search(rc(i), dis);
//     }
//     return 0;
// }

// inline void add(int i, int dis, int k)
// {
//     if ( tree[i].l == tree[i].r ) {
//         tree[i].sum += k;
//         return;
//     }
//     if ( dis <= tree[lc(i)].r ) {
//         add(lc(i), dis, k);
//     } else {
//         add(rc(i), dis, k);
//     }
//     tree[i].sum = tree[lc(i)].sum + tree[rc(i)].sum;
//     return;
// }

inline void add(int i, int l, int r, int k) {
    if(tree[i].l >= l && tree[i].r <= r) {
        tree[i].sum += k * (tree[i].r - tree[i].l + 1);
        tree[i].lazy += k;
        return;
    }
    pushDown(i);
    if(tree[lc(i)].r >= l) { add(lc(i), l, r, k); }
    if(tree[rc(i)].l <= r) { add(rc(i), l, r, k); }
    tree[i].sum = tree[lc(i)].sum + tree[rc(i)].sum;
}

int main(int argc, char* argv[]) {

    freopen("/home/freaver/CODE_C/practice/input.txt", "r", stdin);
    freopen("/home/freaver/CODE_C/practice/output.txt", "w", stdout);
    int n, m;
    scanf("%d%d", &n, &m);
    memset(a, 0, sizeof a);
    int x, y, j;
    build(1, 1, n + 1);
    while(m--) {
        scanf("%d", &j);
        if(j) {
            int k;
            scanf("%d%d%d", &x, &y, &k);
            // add(1, x, y, k);
            add(1, x, y, k);
        } else {
            scanf("%d%d", &x, &y);
            printf("%lld\n", search(1, x, y));
        }
    }

    return 0;
}
