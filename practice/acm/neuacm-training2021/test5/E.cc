#include<bits/stdc++.h>
using namespace std;
#define ll long long
const double EPS = 1e-8;
const int N = 1e5 + 1;

typedef struct
{
    ll sum = 0;
    int l;
    int r;
    // ll lazy, mmax, mmin;
}Tree;

Tree trees[N << 2];

ll a[N];


inline int lc(int n)
{
    return n << 1;
}

inline int rc(int n)
{
    return n << 1 | 1;
}

// inline void pushDown(int i)
// {
//     if ( trees[i].lazy ) {
//         ll lazy = trees[i].lazy;
//         trees[lc(i)].lazy += lazy;
//         trees[rc(i)].lazy += lazy;
//         int mid = (trees[i].l + trees[i].r) >> 1;
//         trees[lc(i)].sum -= (mid - trees[lc(i)].l + 1) * lazy;
//         trees[rc(i)].sum -= (trees[rc(i)].r - mid) * lazy;
//         trees[lc(i)].mmin -= lazy;
//         trees[lc(i)].mmax -= lazy;
//         trees[rc(i)].mmin -= lazy;
//         trees[rc(i)].mmin -= lazy;
//         trees[i].lazy = 0;
//     }
// }

inline void build(int i, int l, int r)
{
    trees[i].l = l;
    trees[i].r = r;
    if ( l == r ) {
        trees[i].sum = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(lc(i), l, mid);
    build(rc(i), mid + 1, r);
    trees[i].sum = trees[lc(i)].sum + trees[rc(i)].sum;

    // trees[i].mmin = min(trees[lc(i)].mmin, trees[rc(i)].mmin);
    // trees[i].mmax = max(trees[lc(i)].mmax, trees[rc(i)].mmax);

}

inline ll query(int i, int l, int r)
{
    if ( trees[i].l == l && trees[i].r == r ) {
        return trees[i].sum;
    }
    int mid = (trees[i].l + trees[i].r) >> 1;
    if ( mid >= r ) {
        return query(lc(i), l, r);
    }
    if ( mid < l ) {
        return query(rc(i), l, r);
    }
    return query(lc(i), l, mid) + query(rc(i), mid + 1, r);

}

inline void action(int i, int l, int r)
{
    if ( trees[i].r - trees[i].l + 1 == trees[i].sum ) {
        return;
    }
    if ( trees[i].l == trees[i].r ) {
        trees[i].sum = (ll)sqrt(trees[i].sum);
        return;
    }
    int mid = (trees[i].l + trees[i].r) >> 1;
    if ( mid >= r ) {
        action(lc(i), l, r);
    } else if ( mid < l ) {
        action(rc(i), l, r);
    } else {
        action(lc(i), l, mid);
        action(rc(i), mid + 1, r);
    }
    trees[i].sum = trees[lc(i)].sum + trees[rc(i)].sum;
}




int main(int argc, char *argv[])
{
    int n;
    int res = 0;
    while ( ~scanf("%d", &n) ) {
        int m, t, x, y;
        for ( int i = 1; i <= n; i++ ) {
            scanf("%lld", &a[i]);
        }
        build(1, 1, n);
        printf("Case #%d:\n", ++res);
        scanf("%d", &m);
        while ( m-- ) {
            scanf("%d%d%d", &t, &x, &y);
            if ( x > y ) {
                swap(x, y);
            }
            if ( t == 0 ) {
                action(1, x, y);
            } else {
                printf("%lld\n", query(1, x, y));
            }
        }
        printf("\n");
    }

    return 0;
}
