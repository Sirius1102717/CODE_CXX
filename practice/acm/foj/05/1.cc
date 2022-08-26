#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <iostream>
#include <math.h>
#include <queue>
#include <stack>
#include <string>
#include <vector>
using namespace std;
using ll = long long;
const double EPS = 1e-8;
const ll MAXN = 1e18;
const int INF = 0x3f3f3f3f;

int main(int argc, char* argv[])
{
    freopen("/home/freaver/CODE_C/input.txt", "r", stdin);
    freopen("/home/freaver/CODE_C/output.txt", "w", stdout);

    ll n;
    while (scanf("%lld", &n) != EOF) {
        if (n == 0) {
            break;
        }
        ll m = 0;
        for (ll i = 1; i <= n; i++) {
            for (ll j = 1; j <= n; j++) {
                ll tmp = i * i * i + j * j *j;
                if (tmp <= n * n * n) {
                    m = max(tmp, m);
                }
            }
        }
        printf("%lld\n", n * n * n - m);
    }
    return 0;
}
