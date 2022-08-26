#include <cstring>
#include <deque>
#include <iostream>
#include <queue>
#include <regex>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
using namespace std;
using ll = long long;
const double EPS = 1e-8;
const ll MAXN = 1e18;
const int INF = 0x3f3f3f3f;
int n, m;

struct order
{
    string s, sp, dp;
} o[2005];

struct node
{
    string s, sp, dp;
    bool flag;
} v[2005];

vector<string> ans;

bool isMatch(string s, string p)
{
    int i = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != p[i] && p[i] != '?') {
            return 0;
        }
    }
    return 1;
}
int main(int argc, char* argv[])
{

    freopen("/home/freaver/CODE_C/input.txt", "r", stdin);
    freopen("/home/freaver/CODE_C/output.txt", "w", stdout);
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    while (cin >> n >> m) {
        if (!n && !m) {
            break;
        }
        ans.clear();

        for (int i = 0; i < n; i++) {
            cin >> o[i].s >> o[i].sp >> o[i].dp;
        }
        for (int i = 0; i < m; i++) {
            cin >> v[i].sp >> v[i].dp >> v[i].s;
            v[i].flag = 1;
        }
        for (int i = 0; i < m; i++) {
            for (int j = n - 1; j >= 0; j--) {
                if (o[j].s[0] == 'd') {
                    if (isMatch(v[i].sp, o[j].sp) && isMatch(v[i].dp, o[j].dp)) {
                        v[i].flag = 0;
                    }
                } else {
                    if (isMatch(v[i].sp, o[j].sp) && isMatch(v[i].dp, o[j].dp) && v[i].flag) {
                        ans.push_back(v[i].sp + " " + v[i].dp + " " + v[i].s);
                    }
                }
            }
        }
        cout << ans.size() << endl;
        for (auto c : ans) {
            cout << c << endl;
        }
    }

    return 0;
}