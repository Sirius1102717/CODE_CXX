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
const int N = 205;
const int INF = 0x3f3f3f3f;
int n, m, E;
int mp[N][N], f[N][N];

int fa[N];

int get_fa(int x) {
    return x == fa[x] ? x : (fa[x] = get_fa(fa[x]));
}

inline bool judge(int x, int y) {
    return mp[x][y] != INF && mp[y][x] != INF;
}

void join(int x, int y) {
    int xx = get_fa(x), yy = get_fa(y);
    if(xx != yy) {
        fa[x] = yy;
    }
}

void floyd() {
    for(int k = 0; k < n; k++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                mp[i][j] = min(mp[i][j], mp[i][k] + mp[k][j]);
            }
        }
    }
}

struct node {
    int u, v;
} e[10005];

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int a, b;
    while(cin >> n) {

        while(n--) {
            cin >> m >> E;
            memset(mp, INF, sizeof mp);
            memset(f, 0, sizeof f);
            for(int i = 0; i < m; i++) {
                fa[i] = i;
            }
            for(int i = 0; i < E; i++) {
                cin >> a >> b;
                e[i].u = a, e[i].v = b;
                mp[a][b] = 1;
                f[a][b] = 1;
            }
            floyd();
            int ans = 0;
            for(int i = 0; i < E; i++) {
                int u = e[i].u, v = e[i].v;
                if(f[v][u] || judge(u, v)) {
                    join(u, v);
                }
            }
            for(int i = 0; i < m; i++) {
                if(fa[i] == i) {
                    ans++;
                }
            }
            cout << ans << endl;
        }
    }
    return 0;
}