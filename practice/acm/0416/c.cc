#include <algorithm>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;
using ll = long long;
const double EPS = 1e-8;
const ll MAXN = 1e18;
const int INF = 0x3f3f3f3f;
const int N = 1e5 + 5;

map<char, pair<int, int>> mp;

int xxx[N], yyy[N];
int main(int argc, char* argv[]) {
    freopen("/home/freaver/CODE_C/practice/input.txt", "r", stdin);
    freopen("/home/freaver/CODE_C/practice/output.txt", "w", stdout);
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin.t
    mp['U'] = make_pair(0, 1);
    mp['D'] = make_pair(0, -1);
    mp['L'] = make_pair(-1, 0);
    mp['R'] = make_pair(1, 0);
    int t, n;
    ll k;
    string s;
    cin >> t;
    ll ans, x, y, mmax, xx, yy;
    while(t--) {
        ans = x = y = 0;
        mmax = 0;
        cin >> n >> k >> s;
        for(int i = 1; i < n; i++) {
            xxx[i] = mp[s[i]].first - xxx[i - 1];
            yyy[i] = mp[s[i]].second - yyy[i - 1];
            // xx = x + mp[s[i]].first * k;
            // yy = y + mp[s[i]].second * k;
            // ans = max((abs(xx) + abs(yy)), ans);
            // x += mp[s[i]].first;
            // y += mp[s[i]].second;
        }
        ans = max((abs(x) + abs(y)) * k, ans);
        cout << ans << '\n';
    }

    return 0;
}
