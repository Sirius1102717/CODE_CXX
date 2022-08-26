#include <algorithm>
#include <array>
#include <cstring>
#include <deque>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
using ll = long long;
const double EPS = 1e-8;
const ll MAXN = 1e18;
const int INF = 0x3f3f3f3f;
int h, w, c;
int mp[9][9], vis[9][9];
int dis[4][2] = { 1, 0, 0, 1, -1, 0, 0, -1 };
int ans;
int num;
bool in(int x, int y) {
    return x >= 0 && x < h && y >= 0 && y < w;
}

void dfs(int x, int y, int color, int num) {

    mp[x][y] = color;
    for(int i = 0; i < 4; i++) {
        int xx = x + dis[i][0], yy = y + dis[i][1];
        if(in(xx, yy) && color == mp[xx][yy] && !vis[xx][yy]) {
            vis[xx][yy] = 1;
            dfs(xx, yy, color, num + 1);
        }
    }
}
void dfs(int x, int y, int color, int tmp[][9]) {
    tmp[x][y] = color;
    for(int i = 0; i < 4; i++) {
        int xx = x + dis[i][0], yy = x + dis[i][1];
        if(in(xx, yy) && (tmp[x][y] == tmp[xx][yy] || tmp[xx][yy] == color) && !vis[xx][yy]) {
            vis[xx][yy] = 1;
            num++;
            dfs(xx, yy, color, tmp);
            num--;
        }
    }
    if(num > ans) {

        for(int i = 0; i < h; i++) {
            for(int j = 0; j < w; j++) {
                mp[i][j] = tmp[i][j];
            }
        }
        ans = num;
    }
}

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    while(cin >> h >> w >> c, h && w && c) {

        ans = -1;
        for(int i = 0; i < h; i++) {
            for(int j = 0; j < w; j++) {
                cin >> mp[i][j];
            }
        }
        num = 1, ans = 0;
        while(c--) {
            for(int k = 1; k <= 6; k++) {
                memset(vis, 0, sizeof vis);
                for(int i = 0; i < h; i++) {
                    for(int j = 0; j < w; j++) {
                        if(!vis[i][j]) {
                            dfs(i, j, k, mp);
                        }
                    }
                }
                ans = max(num, ans);
            }
        }
        cout << ans << endl;
    }

    return 0;
}
