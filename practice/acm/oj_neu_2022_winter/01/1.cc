#include <algorithm>
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


ll ans = 0;
string s;
void dfs(int b, ll tmp, ll sum) {
    int cnt = 0;
    if(b == s.size() - 1) {
        ans += sum + tmp;
        return;
    }
    dfs(b + 1, s[b + 1] - '0' + tmp * 10, sum);
    dfs(b + 1, s[b + 1] - '0', sum + tmp);
}

int main(int argc, char* argv[]) {
    freopen("/home/freaver/CODE_C/practice/input.txt", "r", stdin);
    freopen("/home/freaver/CODE_C/practice/output.txt", "w", stdout);
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> s;
    dfs(0, s[0] - '0', 0);
    cout << ans << endl;
    return 0;
}
