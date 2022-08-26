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
const int N = 1e6 + 5;
int a[N];
int main(int argc, char* argv[]) {
    freopen("/home/freaver/CODE_C/practice/input.txt", "r", stdin);
    freopen("/home/freaver/CODE_C/practice/output.txt", "w", stdout);
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    int k, n, m, u, v;
    string s;
    cin >> t;
    while(t--) {
        cin >> k;
        cin >> s;
        for(int i = 0; i < s.size(); i++)
            a[i] = s[i] - '0';
        cin >> n >> m;
        for(int i = 0; i < m; i++)
            cin >> u >> v;
        if(a[(m - n + 1) % k] == 1)
            cout << "2\n";
        else
            cout << "1\n";
    }
    return 0;
}
