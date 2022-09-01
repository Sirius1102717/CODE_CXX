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
const int N = 1e3 + 5;
int mp[N][N];

struct edge {
    int u;
    int v;
    int w;
} e[N << 1];
int cnt = 0;

int fa[N];

bool cmp(edge n1, edge n2) {
    return n1.w < n2.w;
}

int get_fa(int x) {
    return x == fa[x] ? x : fa[x] = get_fa(fa[x]);
}

bool join(int x, int y) {
    int xx = get_fa(x), yy = get_fa(y);
    if(xx != yy) {
        fa[xx] = yy;
        return 1;
    }
    return 0;
}

int mst(int n) {
    int tot = 0;
    int ans = 0;
    sort(e, e + cnt, cmp);
    for(int i = 0; i < cnt; i++) {
        if(join(e[i].u, e[i].v)) {
            tot++;
            ans += e[i].w;
        }
    }
    return tot == n - 1 ? ans : -1;
}

int main(int argc, char* argv[]) {
    freopen("/home/freaver/CODE_C/practice/input.txt", "r", stdin);
    freopen("/home/freaver/CODE_C/practice/output.txt", "w", stdout);
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    memset(mp, INF, sizeof mp);
    cin >> n;
    for(int i = 0; i < n; i++) {
        fa[i] = i;
        for(int j = 0; j < n; j++) {
            cin >> mp[i][j];
            if(~mp[i][j]) e[cnt].u = i, e[cnt].v = j, e[cnt++].w = mp[i][j];
        }
    }
    cout << mst(n) << endl;

    return 0;
}
