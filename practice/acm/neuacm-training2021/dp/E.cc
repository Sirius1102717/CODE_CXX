#include<iostream>
#include<algorithm>
using namespace std;
const double EPS = 1e-8;

int dp[1001] = { 0 };

int n, m, r;
typedef struct
{
    int start;
    int end;
    int efficiency;
}Cow;


bool com(const Cow &c1, const Cow &c2)
{

    return c1.end < c2.end;

}



Cow cows[1000] = { 0 };

int main(int argc, char *argv[])
{
    std::ios::sync_with_stdio(false);
    cin >> n >> m >> r;
    for ( int i = 0; i < m; i++ ) {
        cin >> cows[i].start >> cows[i].end >> cows[i].efficiency;
        cows[i].end = min(cows[i].end + r, n);
    }
    int ans = 0;
    sort(cows, cows + m, com);
    for ( int i = 0; i < m; i++ ) {
        dp[i] = cows[i].efficiency;
        for ( int j = 0; j < i; j++ ) {
            if ( cows[j].end <= cows[i].start ) {
                dp[i] = max(dp[i], dp[j] + cows[i].efficiency);
            }
        }
        ans = max(dp[i], ans);
    }
    cout << ans << "\n";

    return 0;
}
