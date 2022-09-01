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
const int N = 1e5 + 5;

int fa[N];

int get_fa(int x) {
    return x == fa[x] ? x : fa[x] = get_fa(fa[x]);
}

void join(int x, int y) {
     int xx = get_fa(x), yy = get_fa(y);
     if (xx != yy)  fa[xx] = yy;
}

int main(int argc, char* argv[]) {
    freopen("/home/freaver/CODE_C/practice/input.txt", "r", stdin);
    freopen("/home/freaver/CODE_C/practice/output.txt", "w", stdout);
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    int x, y;
    for (int i = 0; i < n; i++) fa[i] = i;
    while(m--) {
        cin >> x >> y;
        join(x, y);
    }
    int q;
    cin >> q;
    while(q--) {
        cin >>x >> y;
        if (get_fa(x) == get_fa(y)) cout << "yes\n";
        else cout << "no\n";
    }

    return 0;
}
