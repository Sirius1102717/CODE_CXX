#include<iostream>
#include<string>
using namespace std;
const double EPS = 1e-8;
#define ll long long

string dp[1001] = { "0" };


string highAdd(string a, string b)
{
    int lenb = b.size();
    if ( lenb > a.size() ) {
        return highAdd(b, a);
    }
    string ans = a;
    ans.insert(0, 1, '0');
    int lena = ans.size();
    b.insert(0, lena - lenb, '0');
    int temp = 0;
    for ( int i = lena - 1; i >= 0; i-- ) {
        int sum = ans[i] + b[i] - '0' * 2 + temp;
        temp = sum / 10;
        sum %= 10;
        ans[i] = sum + '0';
    }
    if ( ans[0] == '0' ) {
        ans.erase(0, 1);
    }
    return ans;
}

int main(int argc, char *argv[])
{
    std::ios::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    // dp[1] = 1;
    dp[0] = "1";
    // dp[2] = 2;
    for ( int i = 1; i <= k; i++ ) {
        if ( i > n ) {
            break;
        }
        for ( int j = i; j <= n; j++ ) {
            dp[j] = highAdd(dp[j], dp[j - i]);
        }
    }
    cout << dp[n];
    return 0;
}
