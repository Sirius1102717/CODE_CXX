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

int dp[1005][1005];

int main(int argc, char* argv[]) {
    freopen("/home/freaver/CODE_C/practice/input.txt", "r", stdin);
    freopen("/home/freaver/CODE_C/practice/output.txt", "w", stdout);
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s1, s2;
    cin >> s1 >> s2;
    int len1 = s1.size() + 1, len2 = s2.size() + 1;
    memset(dp, INF, sizeof dp);
    for(int i = 0; i < len1; i++) {
        for(int j = 0; j < len2; j++) {
            if(!i) {
                dp[i][j] = j;
            } else if(!j) {
                dp[i][j] = i;
            } else {
                int t = (s1[i - 1] == s2[j - 1] ? 0 : 1);
                dp[i][j] = min(min(dp[i][j - 1], dp[i - 1][j]) + 1, dp[i - 1][j - 1] + t);
            }
        }
    }
    cout << dp[len1 - 1][len2 - 1] << endl;

    return 0;
}
