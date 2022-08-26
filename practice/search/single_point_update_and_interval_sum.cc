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

int bits[N];
int t1[N], t2[N];
int n;

inline int lowbit(int x) {
    return x & -x;
}

void update(int i, int x) {
    while(i <= n) {
        // bits[i] += x;
        t1[i] += x, t2[i] += x;
        i += lowbit(i);
    }
}

void add(int l, int r, int v) {
    update(l, v), update(r + 1, -v);
}

int get(int i) {
    int sum = 0;
    while(i > 0) {
        sum += bits[i];
        i -= lowbit(i);
    }
    return sum;
}

int get_sum(int* t, int k) {
    int ret = 0;
    while(k) {
        ret += t[k];
        k -= lowbit(k);
    }
    return ret;
}

int get_interval_sum(int l, int r) {
    // return get(t) - get(s);
    return r * get_sum(t1, r) - l * get_sum(t2, l - 1) - (get_sum(t2, r) - get_sum(t2, l - 1));
}

int main(int argc, char* argv[]) {
    freopen("/home/freaver/CODE_C/practice/input.txt", "r", stdin);
    freopen("/home/freaver/CODE_C/practice/output.txt", "w", stdout);
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q;
    ll c;
    cin >> n >> q;
    int o, x, y;
    while(q--) {
        cin >> o >> x >> y;
        if(o)
            cout << get_interval_sum(x, y + 1) << '\n';
        else {
            cin >> c;
            add(x, y, c);
        }
    }

    return 0;
}
