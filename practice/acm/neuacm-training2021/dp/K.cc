#include<iostream>
using namespace std;

int dp[8][3] = { 0 };


void init()
{
    dp[0][0] = 1;
    for ( int i = 1; i <= 7; i++ ) {
        dp[i][0] = dp[i - 1][0] * 9 - dp[i - 1][1];
        dp[i][1] = dp[i - 1][0];
        dp[i][2] = dp[i - 1][2] * 10 + dp[i - 1][1] + dp[i - 1][0];
    }
}

int getDp(int x)
{
    int s[8] = { 0 };
    int index = 0;
    int sum = x;
    int unluckyNum = 0;
    bool isUnlucky = false;
    while ( x ) {
        s[++index] = x % 10;
        x /= 10;
    }
    for ( int i = index; i >= 1; i-- ) {
        unluckyNum += dp[i - 1][2] * s[i];

        if ( isUnlucky ) {
            unluckyNum += dp[i - 1][0] * s[i];
        } else {
            if ( s[i] > 4 ) {
                unluckyNum += dp[i - 1][0];
            }
            if ( s[i] > 6 ) {
                unluckyNum += dp[i - 1][1];
            }
            if ( s[i] > 2 && s[i + 1] == 6 ) {
                unluckyNum += dp[i][1];
            }
        }
        if ( s[i] == 4 || (s[i] == 2 && s[i + 1] == 6) ) {
            isUnlucky = true;
        }
    }
    return sum - unluckyNum;
}

int main(int argc, char *argv[])
{
    std::ios::sync_with_stdio(false);
    int n, m;
    init();
    while ( cin >> n >> m ) {
        if ( n == 0 && m == 0 ) {
            break;
        }
        cout << getDp(m + 1) - getDp(n) << "\n";
    }
    return 0;
}
