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
const int N = 1e5 + 5;
ll n, a, b;
ll x[N];

ll dp[N];

int main(int argc, char* argv[]) {
    freopen("/home/freaver/CODE_C/practice/input.txt", "r", stdin);
    freopen("/home/freaver/CODE_C/practice/output.txt", "w", stdout);
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> a >> b;
    memset(dp, 63, sizeof dp);
    for(int i = 1; i <= n; i++)
        cin >> x[i];

    dp[1] = 0;
    for(int i = 2; i <= n; i++) {
        dp[i] = min(dp[i - 1] + (x[i] - x[i - 1]) * a, dp[i - 1] + b);
    }
    cout << dp[n] << endl;

    return 0;
}
