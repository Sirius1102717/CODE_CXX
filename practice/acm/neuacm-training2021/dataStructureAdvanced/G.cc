#include <cstdio>
using namespace std;
using ll = long long;
const ll N = 2100;

ll a1[N][N], a2[N][N], a3[N][N], a4[N][N];
ll n, m;

inline ll lowbit(ll x)
{
    return x & -x;
}

template <class T>
void read(T& x)
{
    int f = 1;
    x = 0;
    char ch = getchar();

    while (ch < '0' || ch > '9') {
        if (ch == '-') {
            f = -1;
            ch = getchar();
        }
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    x *= f;
}

void add(ll x, ll y, ll k)
{
    for (ll i = x; i <= n; i += lowbit(i)) {
        for (ll j = y; j <= m; j += lowbit(j)) {
            a1[i][j] += k;
            a2[i][j] += k * x;
            a3[i][j] += k * y;
            a4[i][j] += k * x * y;
        }
    }
}

void add(ll x1, ll y1, ll x2, ll y2, ll k)
{
    add(x1, y1, k);
    add(x1, y2 + 1, -k);
    add(x2 + 1, y1, -k);
    add(x2 + 1, y2 + 1, k);
}

ll query(ll x, ll y)
{
    ll ans = 0;

    for (ll i = x; i <= n; i += lowbit(i)) {
        for (ll j = y; j <= m; j += lowbit(j)) {
            ans += (x + 1) * (y + 1) * a1[i][j] - (y + 1) * a2[i][j] - (x + 1) * a3[i][j] + a4[i][j];
        }
    }
    return ans;
}

ll matrixSum(ll x1, ll y1, ll x2, ll y2)
{
    return (query(x2, y2) - query(x2, y1 - 1)) - (query(x1 - 1, y2) - query(x1 - 1, y1 - 1));
}

int main(int argc, char* argv[])
{

    // scanf("%lld%lld", &n, &m);
    read(n);
    read(m);
    int o = 0;
    while (read(o), o) {
        if (o == 1) {
            ll a, b, c, d, x;
            read(a);
            read(b);
            read(c);
            read(d);
            read(x);
            // scanf("%lld%lld%lld%lld%lld", &a, &b, &c, &d, &x);
            add(a, b, c, d, x);
        } else {
            ll a, b, c, d;
            read(a);
            read(b);
            read(c);
            read(d);
            // scanf("%lld%lld%lld%lld", &a, &b, &c, &d);
            printf("%lld\n", matrixSum(a, b, c, d));
        }
    }

    return 0;
}
