#include <algorithm>
#include <cstdio>
using namespace std;
using ll = long long;
const int N = 1e6 + 5;
const int M = 1e9 + 5;
ll h, w, n, hh, ww;

ll cost[N];
ll cnt = 0;
ll ans[15];

int main(int argc, char* argv[]) {
    freopen("/home/freaver/CODE_C/practice/input.txt", "r", stdin);
    freopen("/home/freaver/CODE_C/practice/output.txt", "w", stdout);
    scanf("%lld%lld%lld", &h, &w, &n);
    ww = w - 2, hh = h - 2;
    ll aa, bb;
    ll a, b;
    ll zero = hh * ww;
    while(n--) {
        scanf("%lld%lld", &a, &b);
        for(ll i = -2; i < 1; i++) {
            for(ll j = -2; j < 1; j++) {
                aa = a + i;
                bb = b + j;
                if(aa >= 1 && aa <= hh && bb >= 1 && bb <= ww) cost[cnt++] = (a - 1) * M + bb;
            }
        }
    }

    sort(cost, cost + cnt);
    ll tmp = 1;

    for(ll i = 0; i < cnt; i++) {
        if(cost[i] == cost[i + 1]) {
            tmp++;
        } else {
            ans[tmp]++;
            tmp = 1, zero--;
        }
    }
    printf("%lld\n", zero);
    for(ll i = 1; i < 10; i++)
        printf("%lld\n", ans[i]);

    return 0;
}
