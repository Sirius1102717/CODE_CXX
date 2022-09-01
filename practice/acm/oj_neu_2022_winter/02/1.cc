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
const ll INF = 0x3f3f3f3f;
const ll N = 1e3 + 5;
ll n;
ll t[N], a[N];

ll ans[N];

ll gcd(ll m, ll n) {
    while(n) {
        ll t = m % n;
        m = n, n = t;
    }
    return m;
}

void cal(ll& x, ll& y, ll l, ll r) {
    if(l >= x && r >= y)
        x = l, y = r;
    else {
        ll t1 = x / l, t2 = y / r;
        if (x % l) t1++;
        if (y % r) t2++;
        ll tmp = max(t1, t2);
        x = tmp * l;
        y = tmp * r;
    }
}

ll al, ar;

int main(int argc, char* argv[]) {
    freopen("/home/freaver/CODE_C/practice/input.txt", "r", stdin);
    freopen("/home/freaver/CODE_C/practice/output.txt", "w", stdout);
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(ll i = 0; i < n; i++)
        cin >> t[i] >> a[i];

    al = t[0], ar = a[0];
    for(ll i = 1; i < n; i++) {
        cal(al, ar, t[i], a[i]);
    }
    cout << al + ar << endl;

    return 0;
}
