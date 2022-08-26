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

char mp[30][30];

int dir[4][2] = { 1, 0, -1, 0, 0, 1, 0, -1 };

int dp[500][30][30];
int w, h;

int x, y, cnt;

bool vis[30][30];
inline bool in(int x, int y) {
    return x >= 0 && x < h && y >= 0 && y < w && mp[x][y] != 'x' && !vis[x][y];
}

int x1[500], y1[500];

struct point {
    int x, y;
    point(int xx, int yy) {
        x = xx, y = yy;
    }
};

void min_dis(int cnt, int x, int y) {

    queue<point> q;
    memset(vis, 0, sizeof vis);
    q.emplace(x, y);
    vis[x][y] = 1;
    while(!q.empty()) {
        point front = q.front();
        int i = front.x, j = front.y;
        for(int k = 0; k < 4; k++) {
            int xx = i + dir[k][0], yy = j + dir[k][1];
            if(in(xx, yy)) {
                dp[cnt][xx][yy] = dp[cnt][i][j] + 1;
                q.emplace(xx, yy);
                vis[xx][yy] = 1;
            }
        }
        q.pop();
    }
}

int a[500];
int main(int argc, char* argv[]) {
    freopen("/home/freaver/CODE_C/input.txt", "r", stdin);
    freopen("/home/freaver/CODE_C/output.txt", "w", stdout);
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while(cin >> w >> h) {
        if(!w && !h) {
            break;
        }
        memset(dp, INF, sizeof dp);
        cnt = 0;
        for(int i = 0; i < h; i++) {
            cin >> mp[i];
        }

        for(int i = 0; i < h; i++) {
            for(int j = 0; j < w; j++) {
                if(mp[i][j] == 'o') {

                    x = i, y = j;
                } else if(mp[i][j] == '*') {
                    x1[cnt] = i, y1[cnt++] = j;
                }
            }
        }
        dp[0][x][y] = 0;
        min_dis(0, x, y);
        for(int i = 0; i < cnt; i++) {
            a[i] = i;
            x = x1[i], y = y1[i];
            dp[i + 1][x][y] = 0;
            min_dis(i + 1, x, y);
        }

        int m = 0;
        ll ans = INF;
        do {
            ll tmp = dp[0][x1[a[0]]][y1[a[0]]];
            int pre = a[0] + 1;
            for(int i = 1; i < cnt; i++) {
                int j = a[i];
                tmp += dp[pre][x1[j]][y1[j]];
                pre = j + 1;
            }
            ans = min(ans, tmp);
        } while(next_permutation(a, a + cnt));
        cout << (ans == INF ? -1 : ans) << endl;
    }

    return 0;
}
