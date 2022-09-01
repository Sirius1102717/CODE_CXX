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
const ll INF = 0x3f3f3f3f;
const ll N = 1e5 + 5;
ll a[N];
ll sum[N];

int main(int argc, char* argv[]) {
    freopen("/home/freaver/CODE_C/practice/input.txt", "r", stdin);
    freopen("/home/freaver/CODE_C/practice/output.txt", "w", stdout);
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n, x;
    ll ans = 0;
    scanf("%lld%lld", &n, &x);
    scanf("%lld", &a[0]);
    if(a[0] > x) ans += a[0] - x, a[0] = x;
    for(ll i = 1; i < n; i++) {
        scanf("%lld", &a[i]);
        ll tmp = a[i] + a[i - 1];
        if(tmp > x) {
            a[i] -= tmp - x;
            ans += tmp - x;
        }
    }
    printf("%lld\n", ans);

    return 0;
}
