#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstring>
#include <deque>
#include <ios>
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

string to_hex(int x) {
    string ans = "";
    int tmp;
    while(x) {
        tmp = x % 16;
        x /= 16;
        if(tmp > 9)
            ans += 'A' + tmp - 10;
        else
            ans += to_string(tmp);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main(int argc, char* argv[]) {
    freopen("/home/freaver/CODE_C/practice/input.txt", "r", stdin);
    freopen("/home/freaver/CODE_C/practice/output.txt", "w", stdout);
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s, cur, sub;
    while(cin >> s) {
        bool fflag = 0;
        char c = s[0];
        int cn = 1;
        for(int i = 1; i < s.size(); i++) {
            if(c == s[i])
                cn++;
            else {
                if(cn == 1) {
                    fflag = 1;
                    break;
                }
            }
        }
        if(cn == 1) fflag = 1;
        string ans = "";
        bool flag = 1;
        c = s[0];
        cn = 1;
        for(int i = 1; i < s.size(); i++) {
            if(fflag) {
                if(c == s[i])
                    cn++;
                else {
                    if(cn > 1) {
                        ans += c;
                        cur = to_hex(cn);
                        sub = to_hex(cn - 1);
                        if(sub.size() < cur.size() && flag) {
                            ans += sub;
                            flag = 0;
                        } else
                            ans += cur;
                    }
                    if(!flag && cn == 1) {
                        ans += c;
                        ans += '1';
                    }
                    c = s[i];
                    cn = 1;
                }
            } 
        }
        if(cn > 1) {
            ans += c;
            cur = to_hex(cn);
            sub = to_hex(cn - 1);
            if(sub.size() < cur.size() && flag) {
                ans += sub;
                flag = 0;
            } else
                ans += cur;
        }
        if(!flag && cn == 1) {
            ans += c;
            ans += '1';
        }
        cout << ans << '\n';
    }
    return 0;
}
