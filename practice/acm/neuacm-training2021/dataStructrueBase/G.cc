#include<bits/stdc++.h>
using namespace std;
const double EPS = 1e-8;
const int MAXN = 1e6 + 1;


int dp[MAXN];
int main(int argc, char *argv[])
{
    int T;
    cin >> T;
    while ( T-- ) {
        int x, k, t;
        cin >> x >> k >> t;
        deque<int> q;
        memset(dp, MAXN, sizeof dp);
        dp[1] = 0;
        q.push_front(1);
        for ( int i = 2; i <= x; i++ ) {
            if ( i % k == 0 ) {
                dp[i] = min(dp[i / k] + 1, dp[i]);
            }
            while ( !q.empty() && i - q.back() > t ) {
                q.pop_back();
            }
            if ( !q.empty() ) {
                dp[i] = min(dp[i], dp[q.back()] + 1);
            }
            while ( !q.empty() && dp[q.front()] > dp[i] ) {
                q.pop_front();
            }
            q.push_front(i);

        }
        cout << dp[x] << "\n";
    }
    return 0;
}
