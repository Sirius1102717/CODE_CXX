#include <algorithm>
#include <cmath>
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
const int N = 1e3 + 5;
int mp[N][N];
int main(int argc, char* argv[]) {
    freopen("/home/freaver/CODE_C/practice/input.txt", "r", stdin);
    freopen("/home/freaver/CODE_C/practice/output.txt", "w", stdout);
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    while(cin >> n) {
        int mmin = INF;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cin >> mp[i][j];
                if(mp[i][j]) mmin = min(mp[i][j], mmin);
            }
        }

        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                ans += (mmin == mp[i][j]);
            }
        }
        cout << ans / 2 << '\n';
    }

    return 0;
}
