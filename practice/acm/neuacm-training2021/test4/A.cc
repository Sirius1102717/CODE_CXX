#include<iostream>
#include<cstring>
using namespace std;
#define ll long long
const int MAXN = 1e6 + 1;
const double EPS = 1e-8;
const int MOD = 1e9;

int dp[MAXN] = { 0 };
int c[30];
int m = 0;


void init(int n)
{
    dp[0] = 1;
    c[0] = 1;
    while ( c[m] <= n ) {
        c[m + 1] = c[m] << 1;
        m++;
    }
}


int main(int argc, char *argv[])
{
    std::ios::sync_with_stdio(false);
    int n;
    cin >> n;
    init(n);


    for ( int i = 0; i < m; i++ ) {
        if ( c[i] > n ) {
            break;
        }
        for ( int j = c[i]; j <= n; j++ ) {
            dp[j] += dp[j - c[i]];
            if (dp[j] > MOD) {
                dp[j] %= MOD;
            }
        }
    }
    cout << dp[n] << "\n";

    return 0;
}
