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
const int N = 1e3 + 5;

int dp[N][N];

int main(int argc, char* argv[]) {
    freopen("/home/freaver/CODE_C/practice/input.txt", "r", stdin);
    freopen("/home/freaver/CODE_C/practice/output.txt", "w", stdout);
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin >> q;
    string x, y;
    while(q--) {
        cin >> x >> y;
        x.insert(x.begin(), 'x');
        y.insert(y.begin(), 'y');
        memset(dp, 0, sizeof dp);
        for(int i = 1; i < x.size(); i++) {
            for(int j = 1; j < y.size(); j++) {
                if(x[i] == y[j]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        cout << dp[x.size() - 1][y.size() - 1] << endl;
    }
    return 0;
}
