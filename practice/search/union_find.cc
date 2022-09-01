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
int fa[10005];

int get_fa(int x) {
    return x == fa[x] ? x : (fa[x] = get_fa(fa[x]));
}

void join(int x, int y) {
    int xx = get_fa(x), yy = get_fa(y);
    if (xx != yy) {
        fa[xx] = yy;
    }
}



int main(int argc, char *argv[]) {
    freopen("/home/freaver/CODE_C/practice/input.txt", "r", stdin);
    freopen("/home/freaver/CODE_C/practice/output.txt", "w", stdout);
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, q;
    int o, x, y;
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        fa[i] = i;
    }
    while(q--) {
        cin >> o >> x >> y;
        if (o) {
            cout << (get_fa(x) == get_fa(y)) << endl;
        } else {
            join(x, y);
        }

    }
    
    return 0;
}
