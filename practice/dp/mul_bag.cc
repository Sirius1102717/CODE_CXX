#include <algorithm>
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
const int N = 1e9 + 5;
// int v[N], w[N], m[N];
ll v, w, m;

ll dp[N];

struct l{
    ll w, v;
}b[N << 1];

int main(int argc, char* argv[]) {
    freopen("/home/freaver/CODE_C/practice/input.txt", "r", stdin);
    freopen("/home/freaver/CODE_C/practice/output.txt", "w", stdout);
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, tot;
    cin >> n >> tot;
    // cin >> tot >> n;
    int index = 0;
    for(int i = 0; i < n; i++) {
        // cin >> v[i] >> w[i] >> m[i];
        cin >> v >> w >> m;
        // cin >> m >> w >> v;
        int c = 1;
        while(m - c > 0) {
            m -= c;
            b[index].v = c * v;
            b[index++].w = c * w;
            c <<= 1;
        }
        b[index].v = v * m;
        b[index++].w = w * m;
        
    }
    memset(dp, 0, sizeof dp);

    // for(int i = 0; i < n; i++) {
        // for(int k = 0; k < m[i]; k++) {
            // for(int j = tot; j >= w[i]; j--) {
                // dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
            // }
        // }
    // }
    for (int i = 0; i < index; i++) {
        for (int j = tot; j >= b[i].w; j--) {
            dp[j] = max(dp[j], dp[j - b[i].w] + b[i].v);
        }
    }
    cout << dp[tot] << endl;
    return 0;
}
