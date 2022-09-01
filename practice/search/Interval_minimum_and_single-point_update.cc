#include <algorithm>
#include <cstdio>
#include <cstring>
#include <deque>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <vector>
using namespace std;
using ll = long long;
const double EPS = 1e-8;
const ll MAXN = 1e18;
const ll INF = 2e31 - 1;
const int N = 1e5 + 5;

ll bits[N];
int n;

struct tree {
    ll mmin;
    ll sum;
    int l;
    int r;
    ll flag;
    tree() {
        mmin = sum = flag = 0;
    }
} t[N << 2];

inline int lc(int x) {
    return x << 1;
}

inline int rc(int x) {
    return x << 1 | 1;
}

ll d[N << 2];
ll a[N];
ll b[N];

inline void update(int p) {
    t[p].mmin = min(t[lc(p)].mmin, t[rc(p)].mmin);
    t[p].sum = t[lc(p)].sum + t[rc(p)].sum;
}

void push_down(int p) {
    // t[p].sum = (t[p].r - t[p].l + 1) * t[p].flag;
    t[lc(p)].sum += t[p].flag * (t[lc(p)].r - t[lc(p)].l + 1);
    t[rc(p)].sum += t[p].flag * (t[rc(p)].r - t[rc(p)].l + 1);
    // t[lc(p)].flag = t[rc(p)].flag = t[p].flag;
    t[lc(p)].flag += t[p].flag, t[rc(p)].flag += t[p].flag;
    t[p].flag = 0;
}
// inline void update(int p) {
// d[p] = min(d[lc(p)], d[rc(p)]);
// }
//
void build(int l, int r, int p) {
    t[p].l = l, t[p].r = r;
    if(l == r) {
        t[p].sum = a[l];
        return;
    }
    // push_down(p);
    int mid = l + ((r - l) >> 1);
    build(l, mid, lc(p));
    build(mid + 1, r, rc(p));
    update(p);
}

ll get_sum(int l, int r, int p) {
    if(t[p].r < l || t[p].l > r) return 0;
    if(t[p].l >= l && t[p].r <= r) return t[p].sum;
    int mid = l + ((r - l) >> 1);
    push_down(p);
    ll sum = 0;
    if(l <= mid) sum += get_sum(l, r, lc(p));
    if(r > mid) sum += get_sum(l, r, rc(p));
    return sum;
}

void change(int l, int r, ll c, int p) {
    if(t[p].l >= l && t[p].r <= r) {
        t[p].sum += (t[p].r - t[p].l + 1) * c;
        t[p].flag += c;
        // a[p] = c;
        return;
    }
    push_down(p);
    int mid = t[p].l + ((t[p].r - t[p].l) >> 1);

    if(l <= mid) change(l, r, c, lc(p));
    if(r > mid) change(l, r, c, rc(p));
    update(p);
}
// void build(int p, int l, int r) {
// if(l == r) {
// d[l] = a[p];
// return;
// }
// int mid = l + ((r - l) >> 1);
// build(l, mid, lc(p));
// build(mid + 1, r, rc(p));
// update(p);
// }
//
// inline int lowbit(int x) {
// return x & -x;
// }
//
//
// ll get_min(int s, int t, int l, int r, int p) {
// if(l <= s && t <= r) return d[p];
// int m = s + ((t - s) >> 1);
// if(b[p]) {
// d[lc(p)] = b[p] * (m - s + 1);
// d[rc(p)] = b[p] * (t - m);
// b[lc(p)] = b[rc(p)] = b[p];
// b[p] = 0;
// }
// ll sum = INF;
// if(l <= m)
// sum = min(sum, get_min(l, r, s, m, lc(p)));
// else
// sum = min(sum, get_min(l, r, m + 1, t, rc(p)));
// return sum;
// }
//
// void change(int l, int r, int c, int s, int t, int p) {
// if(l <= s && t <= r) {
// d[p] = (t - s + 1) * c, b[p] = c;
// return;
// }
// int m = s + ((t - s) >> 1);
// if(b[p]) {
// d[lc(p)] = b[p] * (m - s + 1);
// d[rc(p)] = b[p] * (t - m);
// b[lc(p)] = b[rc(p)] = b[p];
// b[p] = 0;
// }
// if (l <= m) change(l, r, c, s, m, lc(p));
// else change(l, r, c, m + 1, t, rc(p));
// update(p);
// }

int main(int argc, char* argv[]) {
    freopen("/home/freaver/CODE_C/practice/input.txt", "r", stdin);
    freopen("/home/freaver/CODE_C/practice/output.txt", "w", stdout);
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q, o;
    int s, t;
    ll c;
    // memset(bits, 63, sizeof bits);
    cin >> n >> q;
    // for(int i = 1; i <= n; i++)
        // cin >> a[i];
    // for(int i = 1; i <= n; i++)
    // a[i] = INF;
    memset(a, 0, sizeof a);
    build(1, 100000, 1);
    while(q--) {
        cin >> o >> s >> t;
        if(o) {
            cout << get_sum(s, t, 1) << endl;
            // cout << get_min(s, t, 1, n, 0) << '\n';
        } else {
            // cin >> t >> c;
            cin >> c;
            change(s, t, c, 1);
            // change(s, s, 0, n, t, 0);
        }
    }

    return 0;
}
