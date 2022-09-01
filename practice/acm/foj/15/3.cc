#include <algorithm>
#include <cstdio>
#include <cstring>
#include <deque>
#include <functional>
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
const int N = 505;

int m, n;
int b[N], r[N];
bool vis[N];
bool mat[N][N];


bool dfs(int x) {
    for (int i = 1; i <= m; i++) {
        if (mat[x][i] && !vis[i]) {
            vis[i] = 1;
            if (!b[i] || dfs(b[i])) {
                b[i] = x;
                return 1;
            }
        }
    }
    return 0;
}


int main(int argc, char* argv[]) {
    freopen("/home/freaver/CODE_C/input.txt", "r", stdin);
    freopen("/home/freaver/CODE_C/output.txt", "w", stdout);
    while(~scanf("%d%d", &m, &n)) {
        if(!m && !n) {
            break;
        }
        memset(mat, 0, sizeof mat);
        for(int i = 1; i <= m; i++) {
            scanf("%d", &b[i]);
        }

        for(int i = 1; i <= n; i++) {
            scanf("%d", &r[i]);
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m ; j++) {
                if (__gcd(r[i], b[j]) > 1) {
                    mat[i][j] = 1;
                    // mat[j][i] = 1;
                }
            }
        }
        memset(b, 0, sizeof b);
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            memset(vis, 0, sizeof vis);
            if (dfs(i)) {
                ans++;
            }
        }
        printf("%d\n", ans);
    }

    return 0;
}
