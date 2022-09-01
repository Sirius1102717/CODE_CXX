#include <algorithm>
#include <cstdio>
#include <cstring>
#include <deque>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;
using ll = long long;
const double EPS = 1e-8;
const ll MAXN = 1e18;
const int INF = 0x3f3f3f3f;
int ans[405][405];
bool vis[405][405];

int n, m, x, y;

int horse[8][2] = { 1, 2, 2, 1, 2, -1, 1, -2, -1, -2, -2, -1, -1, 2, -2, 1 };


int main(int argc, char* argv[])
{
    scanf("%d%d%d%d", &n, &m, &x, &y);
    memset(vis, 0, sizeof vis);
    memset(ans, -1, sizeof ans);

    queue<pair<int, int>> q;
    q.emplace(x, y);
    ans[x][y] = 0;
    vis[x][y] = 1;
    while (!q.empty()) {
        pair<int, int> pre = q.front();
        q.pop();
        for (int i = 0; i < 8; i++) {
            int xx = pre.first + horse[i][0], yy = pre.second + horse[i][1];
            if (xx > 0 && xx <= n && yy > 0 && yy <= m && !vis[xx][yy]) {
                ans[xx][yy] = ans[pre.first][pre.second] + 1;
                vis[xx][yy] = 1;
                q.emplace(xx, yy);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            printf("%-5d", ans[i][j]);
        }
        puts("");

    }
    return 0;
}
