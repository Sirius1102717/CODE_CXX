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
int n, q;

int a[25];

int m;

bool dfs(int cur, int i) {
    if(i > n) return 0;
    if(cur == m)
        return 1;
    else {
        return (dfs(cur + a[i], i + 1) || dfs(cur, i + 1));
    }
}

int main(int argc, char* argv[]) {
    freopen("/home/freaver/CODE_C/practice/input.txt", "r", stdin);
    freopen("/home/freaver/CODE_C/practice/output.txt", "w", stdout);
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    cin >> q;
    while(q--) {
        cin >> m;
        if(dfs(0, 0))
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }

    return 0;
}
