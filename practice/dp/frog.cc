#include <algorithm>
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
int h[N];
int dp[N];
int main(int argc, char* argv[]) {
    freopen("/home/freaver/CODE_C/practice/input.txt", "r", stdin);
    freopen("/home/freaver/CODE_C/practice/output.txt", "w", stdout);
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
        cin >> h[i];
    memset(dp, INF, sizeof dp);
    dp[1] = 0;
    for(int i = 1; i < n; i++)
        for(int j = 1; j <= k; j++)
            dp[i + j] = min(dp[i + j], dp[i] + abs(h[i + j] - h[i]));
    cout << dp[n] << '\n';

    return 0;
}
