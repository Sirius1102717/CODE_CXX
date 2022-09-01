#include <cstring>
#include <iostream>
#include <string>
typedef long long ll;
using namespace std;
const int N = 1e6 + 10;
ll bit1[N] = {0}, bit2[N] = {0};
int n, q, judge, l, r;
ll x;

inline ll lowbit(int x)
{
    return x & -x;
}

inline void update(int x, ll y)
{
    int o = x;
    while (x <= n) {
        bit1[x] += y;
        bit2[x] += y * (o - 1);
        x += lowbit(x);
    }
}
inline ll prefixSum1(int x)
{
    ll ans = 0;
    while (x) {
        ans += bit1[x];
        x -= lowbit(x);
    }
    return ans;
}

inline ll prefixSum2(int x)
{
    ll ans = 0;
    while (x) {
        ans += bit2[x];
        x -= lowbit(x);
    }
    return ans;
}

inline ll rangeSum(int l, int r)
{
    return (prefixSum1(r) * r - prefixSum2(r)) - (prefixSum1(l - 1) * (l - 1) - prefixSum2(l - 1));
}

int main(int argc, char* argv[])
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
   
    cin >> n >> q;
    ll pre = 0, now;
    for (int i = 1; i <= n; i++) {
        cin >> now;
        update(i, now - pre);
        pre = now;
    }
    while (q--) {
        cin >> judge;
        if (judge == 1) {
            cin >> l >> r >> x;
            update(l, x);
            update(r + 1, -x);
        } else {
            cin >> l >> r;
            cout << rangeSum(l, r) << "\n";
        }
    }

    return 0;
}
