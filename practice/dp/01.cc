#include <iostream>
using namespace std;
const int N = 1e5 + 5;
int w[N], v[N];
int dp[N];

int main(int argc, char* argv[]) {
    freopen("/home/freaver/CODE_C/practice/input.txt", "r", stdin);
    freopen("/home/freaver/CODE_C/practice/output.txt", "w", stdout);
    int n, tot;
    cin >> n >> tot;
    // memset(dp, 0, sizeof dp);
    for(int i = 0; i < n; i++) {
        cin >> v[i] >> w[i];
    }
    for(int i = 0; i < n; i++) {
        for(int j = tot; j >= w[i]; j--) {
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
        }
    }
    cout << dp[tot] << endl;

    return 0;
}
