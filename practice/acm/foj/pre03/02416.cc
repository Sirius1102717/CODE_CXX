#include <cstring>
#include <iostream>
#include <string>
using namespace std;
const int N = 1005;
const int M = 1e5 + 5;
int dp[N][N];
int n1[M], n2[M];

int main(int argc, char* argv[])
{
    std::ios::sync_with_stdio(false);
    int q;
    cin >> q;
    string s1, s2;
    while (q--) {
        memset(dp, 0, sizeof dp);
        cin >> s1 >> s2;
        int l1 = s1.size(), l2 = s2.size();
        for (int i = 1; i <= l1; i++) {
            for (int j = 1; j <= l2; j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
                }
            }
        }
        cout << dp[l1][l2 ] << endl;
    }
    return 0;
}
