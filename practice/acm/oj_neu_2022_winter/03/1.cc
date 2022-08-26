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

int main(int argc, char* argv[]) {
    freopen("/home/freaver/CODE_C/practice/input.txt", "r", stdin);
    freopen("/home/freaver/CODE_C/practice/output.txt", "w", stdout);
    string s;
    cin >> s;
    int len = s.size();
    int ans = 0;
    for(int i = 1; i < len; i++) {
        if(s[i] != s[i - 1]) ans++;
    }
    cout << ans << endl;

    return 0;
}
