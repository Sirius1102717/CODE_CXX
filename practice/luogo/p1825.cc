#include <algorithm>
#include <cstdio>
#include <cstring>
#include <deque>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;
using ll = long long;
const double EPS = 1e-8;
const ll MAXN = 1e18;
const int INF = 0x3f3f3f3f;
const int N = 305;
char mp[N][N];
bool vis[N][N];
int dist[4][2] = { 1, 0, -1, 0, 0, 1, 0, -1 };
int n, m;

bool in(int x, int y)
{
    return !vis[x][y] && x >= 0 && x < n && y >= 0 && y < m && mp[x][y] != '#';
}

struct node
{
    int x, y, t;
    node(int xx, int yy, int tt)
    {
        x = xx, y = yy, t = tt;
    }
    node()
    {
        t = 0;
    }
};

void bfs(node b)
{
    queue<node> q;
    q.emplace(b);
    vis[b.x][b.y] = 1;
    // dp[x][y] = 0;
    while (!q.empty()) {
        node pre = q.front();
        q.pop();
        if (mp[pre.x][pre.y] == '=') {
            cout << pre.t << endl;
            return;
        }
        if (mp[pre.x][pre.y] >= 'A' && mp[pre.x][pre.y] <= 'Z') {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (mp[pre.x][pre.y] == mp[i][j] && i != pre.x && j != pre.y) {
                        vis[i][j] = 1;
                        pre.x = i, pre.y = j;
                        goto label;
                    }
                }
            }
        }
    label:
        for (int i = 0; i < 4; i++) {
            node cur = node(pre.x + dist[i][0], pre.y + dist[i][1], pre.t + 1);
            if (in(cur.x, cur.y)) {
                q.emplace(cur);
                vis[cur.x][cur.y] = 1;
            }
        }
    }
}
int main(int argc, char* argv[])
{

    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("/home/freaver/CODE_C/input.txt", "r", stdin);
    freopen("/home/freaver/CODE_C/output.txt", "w", stdout);
    cin >> n >> m;
    memset(vis, 0, sizeof vis);
    node b;
    for (int i = 0; i < n; i++) {
        cin >> mp[i];
        for (int j = 0; j < m; j++) {
            if (mp[i][j] == '@') {
                b.x = i, b.y = j;
            }
        }
    }
    bfs(b);

    return 0;
}