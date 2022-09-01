#include <bits/stdc++.h>
#include <string>
using namespace std;
using ll = long long;
const double EPS = 1e-8;
const int N = 1e2 + 1;
int a[N];
int t, n, m, l, r, d, p;
string s;
char o;

struct tree
{
    int digits[12][10];
    int l, r;
    string lazy;
} node[N << 2];

inline int lc(int i)
{
    return i << 1;
}

inline int rc(int i)
{
    return i << 1 | 1;
}

void pushUp(int i)
{
    for (int i = 1; i <= 11; i++) {
        for (int j = 0; j <= 9; j++) {
            node[i].digits[i][j] = node[lc(i)].digits[i][j] + node[rc(i)].digits[i][j];
        }
    }
}

void pushSon(int i, int child, int len)
{
    for (int i = 1; i <= 11; i++) {
        for (int j = 0; j <= 9; j++) {
            node[child].digits[i][j] = node[i].digits[i][j] / (node[i].r - node[i].l + 1) * len;
        }
    }
}

void pushDown(int i)
{
    string lazy = node[i].lazy;
    if (lazy.size()) {
        int mid = (node[i].l + node[i].r) >> 1;
        pushSon(i, lc(i), mid - node[i].l + 1);
        pushSon(i, rc(i), node[i].r - mid);
        node[lc(i)].lazy = lazy;
        node[rc(i)].lazy = lazy;
        node[i].lazy = "";
    }
}

void build(int i, int l, int r)
{
    if (l == r) {
        string tmp = to_string(a[l]);
        for (int i = tmp.size(); i >= 0; i--) {
            node[i].digits[i + 1][s[i] - '0'] = 1;
            node[i].l = l;
            node[i].r = r;
        }
        return;
    }
    int mid = (l + r) >> 1;
    build(lc(i), l, mid);
    build(rc(i), mid + 1, r);
    pushUp(i);
}

void update(int i, int index, string s)
{
    if (node[i].l == index && node[i].r == index) {
        node[i].lazy = s;
        string tmp = to_string(a[index]);
        for (int i = tmp.size(); i >= 0; i--) {
            node[i].digits[i + 1][s[i] - '0'] = 1;
        }
        return;
    }
    pushDown(i);
    if (node[lc(i)].r >= index) {
        update(lc(i), index, s);
    } else {
        update(rc(i), index, s);
    }
    pushUp(i);
}

int query(int i, int l, int r, int d, int p)
{
    if (node[i].l <= l && node[i].r <= r) {
        return node[i].digits[d][p];
    }
    pushDown(i);
    int ans = 0;
    if (node[lc(i)].r >= l) {
        ans = query(lc(i), l, r, d, p);
    }
    if (node[rc(i)].l <= r) {
        ans = query(rc(i), l, r, d, p);
    }
    return ans;
}

int main(int argc, char* argv[])
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            // a[i] = s;
        }
        build(1, 1, n);
        while (m--) {
            cin >> o;
            if (o == 'Q') {
                cin >> l >> r >> d >> p;
                cout << query(1, l, r, p, d) << "\n";
            } else {
                cin >> l >> s;
                update(1, l, s);
            }
        }
    }

    return 0;
}
