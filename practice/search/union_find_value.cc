#include <algorithm>
#include <cstdio>
#include <cstring>
#include <deque>
#include <iomanip>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <vector>
using namespace std;
using ll = long long;
const double EPS = 1e-8;
const ll MAXN = 1e18;
const ll INF = 0x3f3f3f3f;
const int N = 1e5 + 5;
ll fa[N];
ll sum[N];

ll get_fa(ll x) {
    if (x != fa[x]) {
        ll tmp = fa[x];
        fa[x] = get_fa(fa[x]);
        sum[x] += sum[tmp];
    }
    return fa[x];

    // return x == fa[x] ? x : (fa[x] = get_fa(fa[x]));
}

void join(ll x, ll y, ll z) {
    ll xx = get_fa(x), yy = get_fa(y);
    if(xx != yy) {
        fa[xx] = yy;
        sum[xx] = sum[y] - sum[x] + z;
    }
}

int main(int argc, char* argv[]) {
    freopen("/home/freaver/CODE_C/practice/input.txt", "r", stdin);
    freopen("/home/freaver/CODE_C/practice/output.txt", "w", stdout);
    ll n, q;
    ll o, x, y, z;
    scanf("%lld%lld", &n, &q);
    for(ll i = 0; i < n; i++) {
        fa[i] = i;
        sum[i] = 0;
    }
    while(q--) {
        scanf("%lld%lld%lld", &o, &x, &y);
        if(o) {
            if(get_fa(x) == get_fa(y)) {
                printf("%lld\n", sum[x] - sum[y]);
            } else {
                puts("?");
            }
            // cout << (get_fa(x) == get_fa(y)) << endl;
        } else {
            scanf("%lld", &z);
            join(x, y, z);
        }
    }

    return 0;
}
