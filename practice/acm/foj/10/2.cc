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

char mp[30][30];

bool vis[30][30];

int ans;
int w, h;

int dir[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};

void dfs(int x, int y) {
    for (int i = 0; i < 4; i++) {
        int xx = x + dir[i][0], yy = y + dir[i][1];
        if (xx >= 0 && xx < h && yy >= 0 && y < w && !vis[xx][yy] && mp[xx][yy] == '.') {
            ans++;
            vis[xx][yy] = 1;
            dfs(xx, yy);
        }
    }

}

int main(int argc, char *argv[]) {

    while (cin >> w >> h) {
        if (!w && !h) {
            break;
        }

        for (int i = 0; i < h; i++) {
            cin >> mp[i];
        }
        memset(vis, 0, sizeof vis);
        ans = 1;
        int x, y;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (mp[i][j] == '@') {
                    x = i, y = j;
                    break;
                }
            }
        }
        dfs(x, y);
        cout << ans << endl;
    }
    
    return 0;
}
