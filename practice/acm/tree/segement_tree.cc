#include <algorithm>
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
const int INF = 0x3f3f3f3f;
const int N = 1e5 + 5;

int a[N];

int b[N << 2];

int d[N << 2];

inline int lc(int x) {
    return x << 1;
}

inline int rc(int x) {
    return x << 1 | 1;
}

void build(int l, int r, int p) {
    if(l == r) {
        d[p] = a[l];
        return;
    }
    int mid = l + ((r - l) >> 1);
    build(l, mid, lc(p));
    build(mid + 1, r, rc(p));
    d[p] = d[lc(p)] + d[rc(p)];
}

int get_sum(int l, int r, int s, int t, int p) {
    if(l <= s && t <= r) {
        return d[p];
    }
    int mid = l + ((r - l) >> 1);
    int sum = 0;
    if (l <= mid) {
        sum += get_sum(l, r, s, mid, lc(p));
    }
    if (r > mid) {
        sum += get_sum(l, r, mid + 1, t, rc(p));
    }
    return sum;
}

void update(int l, int r, int c, int s, int t, int p) {
    if (l <= s && t <= r) {
        d[p] += (t - s + 1) * c, b[p] += c;
        return;
    }
    int m = s + ((t - s) >> 1);
    if (b[p] && s != t) {
        d[lc(p)] += b[p] * (m - s + 1)

    }
}

int main(int argc, char* argv[]) {
    freopen("/home/freaver/CODE_C/input.txt", "r", stdin);
    freopen("/home/freaver/CODE_C/output.txt", "w", stdout);
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    return 0;
}
