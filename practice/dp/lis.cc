#include<iostream>
#include <iterator>
#include<string>
#include<cstring>
#include<vector>
#include<algorithm>
#include<deque>
#include<queue>
#include<stack>
using namespace std;
using ll = long long;
const double EPS = 1e-8;
const ll MAXN = 1e18;
const int INF = 0x3f3f3f3f;

int a[100005];
int dp[100005];

int main(int argc, char *argv[]) {
    freopen("/home/freaver/CODE_C/practice/input.txt", "r", stdin);
    freopen("/home/freaver/CODE_C/practice/output.txt", "w", stdout);
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        dp[i] = 1;
    }
    int k = 1;
    dp[k] = a[0];
    int ans = -1;
    for (int i = 1; i < n; i++) {
        a[i] > dp[k] ? dp[++k] = a[i] : *lower_bound(dp + 1, dp + 1 + k, a[i]) = a[i];
    }
    // for (int i = 1; i < n; i++) {
        // for (int j = 0; j < i; j++) {
            // if (a[j] < a[i]) {
                // dp[i] = max(dp[i], dp[j] + 1);
            // }
        // }
        // ans = max(ans, dp[i]);
    // }
    cout << k << endl;
    
    return 0;
}
