#include <algorithm>
#include <cstring>
#include <deque>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
using ll = long long;
const double EPS = 1e-8;
const ll MAXN = 1e18;
const int INF = 0x3f3f3f3f;
const int N = 1e6 + 5;
int n, w;
// int h[5005];

struct node {
    int n, i;
    friend bool operator<(node n1, node n2) {
        return n1.n < n2.n;
    }
} h[5005];

int dp[5005];
bool vis[5005];

int main(int argc, char* argv[]) {
    freopen("/home/freaver/CODE_C/practice/input.txt", "r", stdin);
    freopen("/home/freaver/CODE_C/practice/output.txt", "w", stdout);
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int mmin = INF;
    while(cin >> n >> w) {
        for(int i = 0; i < n; i++) {
            cin >> h[i].n;
            h[i].i = i + 1;
        }
        sort(h, h + n);
        memset(dp, 0, sizeof dp);
        memset(vis, 0, sizeof vis);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                int tmp = h[j].n - h[i].n;
                if (!vis[j] && tmp <= h[i].i && tmp <= w) {
                    dp[j] = max(dp[i] + 1, dp[j]);
                    vis[j] = 1;
                } else {
                    dp[j] = max(dp[i], dp[j]);
                }
                
            }
        }
        // for(int i = 0; i < n - 1; i++) {
            // for(int j = 1; j <= h[i].i && j + i < n; j++) {
                // int tmp = h[i + j].n - h[i].n;
                // if(tmp && h[i + j].i - h[i].i <= w && tmp <= h[i].i) {
                    // i += j;
                    // i--;
                    // ans++;
                    // break;
                // }
            // }
        // }
        cout << dp[n - 1] << endl;
    }

    return 0;
}
