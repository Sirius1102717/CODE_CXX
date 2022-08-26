#include <algorithm>
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

int main(int argc, char* argv[]) {
    freopen("/home/freaver/CODE_C/practice/input.txt", "r", stdin);
    freopen("/home/freaver/CODE_C/practice/output.txt", "w", stdout);
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s = "";
    string ans = "";
    getline(cin, s);
    int len = s.size();
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '6') {
            int r = i + 1;
            while(s[r] == '6') {
                r++;
            }
            int llen = r - i;
            if(llen > 3 && llen < 10)
                ans += "9";
            else if(llen > 9)
                // s.replace(i, llen, "27");
                ans += "27";
            else
                ans += s.substr(i, llen);
            i = r;
            if(i < s.size()) ans += s[i];

        } else
            ans += s[i];
    }
    cout << ans;

    return 0;
}
