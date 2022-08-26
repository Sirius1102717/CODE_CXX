
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
int w[105], v[105];

int dp[10005];

int main(int argc, char* argv[]) {
    freopen("/home/freaver/CODE_C/practice/input.txt", "r", stdin);
    freopen("/home/freaver/CODE_C/practice/output.txt", "w", stdout);
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, tot;
    cin >> n >> tot;
    memset(dp, 0, sizeof dp);
    for(int i = 0; i < n; i++) {
        cin >> v[i] >> w[i];
    }
    for(int i = 1; i <= tot; i++) {
        for (int j = n - 1; j >= 0; j--) {
            if (w[j] <= i) {
                dp[i] = max(dp[i], dp[i - w[j]] + v[j]);
            }
        }
    }
    cout << dp[tot] << endl;

    return 0;
}
