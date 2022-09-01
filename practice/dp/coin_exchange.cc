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

int d[25];
int dp[50005];

int main(int argc, char* argv[]) {
    freopen("/home/freaver/CODE_C/practice/input.txt", "r", stdin);
    freopen("/home/freaver/CODE_C/practice/output.txt", "w", stdout);
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    memset(dp, INF, sizeof dp);
    dp[0] = 0;
    for(int i = 0; i < m; i++) {
        cin >> d[i];
        dp[d[i]] = 1;
    }
    for(int i = 1; i <= n; i++) {
        dp[i] = min(dp[i], dp[i - 1] + 1);
        for(int j = 1; j < m; j++) {
            int tmp = d[j];
            if(tmp <= i) {
                dp[i] = min(dp[i], dp[i - tmp] + 1);
            }
        }
    }
    cout << dp[n] << endl;
    return 0;
}
