#include <algorithm>
#include <cctype>
#include <cstdio>
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

char mp[80][80];

int dir[2][2] = { 0, 1, 1, 0 };
int w, h;

void erase_pre_zero(string& s) {
    int c = 0;
    int len = s.size() - 1;
    for(int i = 0; i < len; i++) {
        if(s[i] != '0') {
            break;
        }
        c++;
    }
    s.erase(0, c);
}

string smax(string &a, string &b) {
    erase_pre_zero(a), erase_pre_zero(b);
    if(a.size() > b.size() || (a.size() == b.size() && a > b)) {
        return a;
    }
    return b;
}

string dp[80][80];
int main(int argc, char* argv[]) {
    while(cin >> w >> h) {
        if(!w && !h) {
            break;
        }
        for (int i = 0; i < h; i++) {
            for (int j = 0;j < w; j++) {
                dp[i][j] = "";
            }
        }
        for(int i = 0; i < h; i++) {
            cin >> mp[i];
        }

        if(isdigit(mp[0][0])) {
            dp[0][0] = mp[0][0];
        }
        for(int j = 1; j < w; j++) {
            if(isdigit(mp[0][j])) {
                dp[0][j] = dp[0][j - 1];
                dp[0][j] += mp[0][j];
            }
        }

        for(int i = 1; i < h; i++) {
            if(isdigit(mp[i][0])) {
                dp[i][0] = dp[i - 1][0];
                dp[i][0] += mp[i][0];
            }
        }
        for(int i = 1; i < h; i++) {
            for(int j = 1; j < w; j++) {
                if(isdigit(mp[i][j])) {
                    dp[i][j] = smax(dp[i][j - 1], dp[i - 1][j]);
                    dp[i][j] += mp[i][j];
                }
            }
        }
        string ans = "";

        for(int i = 0; i < h; i++) {
            for(int j = 0; j < w; j++) {
                ans = smax(ans, dp[i][j]);
            }
        }

        // for(int i = 0; i < h; i++) {
        // for(int j = 0; j < w; j++) {
        // if(mp[i][j] >= '1' && mp[i][j] <= '9') {
        // string tmp = "";
        // tmp += mp[i][j];
        // dfs(i, j, tmp);
        // }
        // }
        // }
        // cout << ans << endl;
        erase_pre_zero(ans);
        cout << ans << endl;
    }

    return 0;
}
