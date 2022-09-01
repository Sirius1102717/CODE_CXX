#include<iostream>
#include<string>
#include<cstring>
#include<vector>
#include<algorithm>
#include<deque>
#include<queue>
#include<stack>
using namespace std;
using ll = long long;
const double EPS = 1e-8;
const ll MAXN = 1e18;
const int INF = 0x3f3f3f3f;
const int N =1e3 + 5;

int mp[N][N];

int main(int argc, char *argv[]) {
    freopen("/home/freaver/CODE_C/practice/input.txt", "r", stdin);
    freopen("/home/freaver/CODE_C/practice/output.txt", "w", stdout);
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, j, m, x;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> j >> m;
        while(m--) {
            cin >> x;
            mp[j][x] = 1;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) cout << mp[i][j] << ' ';
        cout << '\n';
    }
    
    return 0;
}
