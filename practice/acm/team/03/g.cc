#include <algorithm>
#include <cmath>
#include <cstdint>
#include <cstdlib>
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
const int INF = 0x3f3f3f3f;

const int N = 1e5 + 5;

ll a[N], b[N], c[N], d[N];

int main(int argc, char* argv[]) {
    freopen("/home/freaver/CODE_C/practice/input.txt", "r", stdin);
    freopen("/home/freaver/CODE_C/practice/output.txt", "w", stdout);
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, n;
    cin >> t;
    while(t--) {
        cin >> n;
        for(int i = 1; i <= n; i++)
            cin >> a[i] >> b[i] >> c[i] >> d[i];

        ll ans = 0;
        for(int i = 1; i < n; i++) {
            ll tmp = MAXN;
            int j = i + 1;
            if(a[j] >= a[i] && a[j] <= b[i] || a[j] >= b[i] && a[j] <= a[i]) tmp += min(tmp, min(abs(b[j] - b[i]), abs(b[j] - a[i])));
            if(b[j] >= a[i] && b[j] <= b[i] || b[j] >= b[i] && b[j] <= a[i]) tmp += min(tmp, min(abs(a[j] - b[i]), abs(a[j] - a[i])));
            if(c[j] >= c[i] && c[j] <= d[i] || c[j] >= d[i] && c[j] <= c[i]) tmp += min(tmp, min(abs(d[j] - c[i]), abs(d[j] - d[i])));
            if(d[j] >= c[i] && d[j] <= d[i] || d[j] >= d[i] && d[j] <= c[i]) tmp += min(tmp, min(abs(c[j] - c[i]), abs(c[j] - c[i])));
            tmp = min(tmp, abs(a[i] - a[j]) + abs(b[i] - b[j]));
            tmp = min(tmp, abs(a[i] - c[j]) + abs(b[i] - d[j]));
            tmp = min(tmp, abs(c[i] - a[j]) + abs(d[i] - b[j]));
            tmp = min(tmp, abs(c[i] - c[j]) + abs(d[i] - d[j]));
            ans += tmp;
        }
        cout << ans << '\n';
    }
    return 0;
}
