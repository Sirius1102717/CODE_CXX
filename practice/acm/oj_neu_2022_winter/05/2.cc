#include <algorithm>
#include <cstdio>
#include <cstring>
#include <deque>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <map>
using namespace std;
using ll = long long;
const double EPS = 1e-8;
const ll MAXN = 1e18;
const int INF = 0x3f3f3f3f;

const int N = 2e5 + 5;

ll rail[N], road[N];

ll get_fa(ll x, ll* f) {
    return x == f[x] ? x : (f[x] = get_fa(f[x], f));
}

void join(ll x, ll y, ll* f) {
    int xx = get_fa(x, f), yy = get_fa(y, f);
    if(xx != yy) f[xx] = yy;
}

int n, k, l;
ll x, y;

map<ll, int> ans;

inline ll get_index(ll x) {
    return get_fa(x, road) * N + get_fa(x, rail);
}
int main(int argc, char* argv[]) {
    freopen("/home/freaver/CODE_C/practice/input.txt", "r", stdin);
    freopen("/home/freaver/CODE_C/practice/output.txt", "w", stdout);
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    scanf("%d%d%d", &n, &k, &l);
    for(int i = 1; i <= n; i++)
        rail[i] = i, road[i] = i;
    for(int i = 0; i < k; i++) {
        scanf("%lld%lld", &x, &y);
        join(x, y, road);
    }
    for(int i = 0; i < l; i++) {
        scanf("%lld%lld", &x, &y);
        join(x, y, rail);
    }

    for (int i = 1; i <= n; i++) {
        ans[get_index(i)]++;
    }
    for (int i = 1; i <= n; i++) {
        printf("%d ", ans[get_index(i)]);
    }

    return 0;
}
