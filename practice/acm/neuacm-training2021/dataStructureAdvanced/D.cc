#include <cstring>
#include <iostream>
#include <string>
typedef long long ll;
using namespace std;
const int N = 2e6 + 10;
ll bit1[N];

inline ll lowbit(ll x)
{
    return x & -x;
}

inline void update(ll x, ll y)
{
    while (x <= N) {
        bit1[x] += y;
        x += lowbit(x);
    }
}
inline ll prefixSum(ll x)
{
    ll ans = 0;
    while (x) {
        ans += bit1[x];
        x -= lowbit(x);
    }
    return ans;
}

inline ll rangeSum(ll l, ll r)
{
    return prefixSum(r) - prefixSum(l - 1);
}

int main(int argc, char* argv[])
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, q, tmp, judge, l, r;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> tmp;
        update(i, tmp);
    }
    while (q--) {
        cin >> judge >> l >> r;
        if (judge == 1) {
            update(l, r);
        } else {
            cout << rangeSum(l, r) << "\n";
        }
    }

    return 0;
}
