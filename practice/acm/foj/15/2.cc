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

int w, h;

int mp[60][60];

int dir[8][2] = {1, 0, -1, 0, 0, 1, 0, -1, 1, 1, 1, -1, -1, 1, -1, -1};
bool vis[60][60];

bool in(int x, int y) {
    return x >= 0 && x < h && y >= 0 && y < w && mp[x][y];
}

void dfs(int x, int y) {
    vis[x][y] = 1;
    for (int i = 0; i < 8; i++) {
        int xx = x + dir[i][0];
        int yy = y + dir[i][1];
        if (in(xx, yy) && !vis[xx][yy]) {
            dfs(xx, yy);
        }
    }
}
int main(int argc, char *argv[]) {
    freopen("/home/freaver/CODE_C/input.txt", "r", stdin);
    freopen("/home/freaver/CODE_C/output.txt", "w", stdout);
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while(cin >> w >> h) {
        if (!w && !h) {
            break;
        }
        memset(vis, 0, sizeof vis);
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cin >> mp[i][j];
            }
        }
        
        int ans = 0;
        for (int i = 0; i < h ;i++) {
            for (int j = 0; j < w; j++) {
                if (!vis[i][j] && mp[i][j]) {
                    dfs(i, j);
                    ans++;
                }
            }
        }
        cout << ans << endl;

        
    }
    
    return 0;
}
