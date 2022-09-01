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


int main(int argc, char* argv[])
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, q, judge, l, r, x;
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
            cin >> x;
            cout << prefixSum(x) << "\n";
        }
    }

    return 0;
}
