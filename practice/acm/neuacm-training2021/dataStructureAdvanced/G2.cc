#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2100;
ll t1[N][N], t2[N][N], t3[N][N], t4[N][N];
ll n, m;
ll lowbit(ll x)
{
    return x & (-x);
}
void add(ll x, ll y, ll k)
{
    for (ll i = x; i <= n; i += lowbit(i))
        for (ll j = y; j <= m; j += lowbit(j)) {
            t1[i][j] += k;
            t2[i][j] += k * x;
            t3[i][j] += k * y;
            t4[i][j] += k * x * y;
        }
}
void update(ll x1, ll y1, ll x2, ll y2, ll k)
{
    add(x1, y1, k);
    add(x1, y2 + 1, -k);
    add(x2 + 1, y1, -k);
    add(x2 + 1, y2 + 1, k);
}
ll sum(ll x, ll y)
{
    ll res = 0;
    for (ll i = x; i > 0; i -= lowbit(i))
        for (ll j = y; j > 0; j -= lowbit(j))
            res += (x + 1) * (y + 1) * t1[i][j] - (y + 1) * t2[i][j] - (x + 1) * t3[i][j] + t4[i][j];
    return res;
}
ll query(ll x1, ll y1, ll x2, ll y2)
{
    return sum(x2, y2) + sum(x1 - 1, y1 - 1) - sum(x2, y1 - 1) - sum(x1 - 1, y2);
}
int main()
{
    scanf("%lld%lld", &n, &m);
    int op;
    while (~scanf("%d", &op)) {
        if (op == 1) {
            ll a, b, c, d, x;
            scanf("%lld%lld%lld%lld%lld", &a, &b, &c, &d, &x);
            update(a, b, c, d, x);
        } else {
            ll a, b, c, d;
            scanf("%lld%lld%lld%lld", &a, &b, &c, &d);
            printf("%lld\n", query(a, b, c, d));
        }
    }
    return 0;
}
