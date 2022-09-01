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

int mp[5][4];
bool vis[5][4];
void init()
{

}
int dir[8][2] = { -1, -1, -1, 0, 1, 1, 1, 0, 1, -1, 0, 1, -1, 1, 0, -1 };
int ans;
void dfs(int x, int y, int n)
{

    for (int i = 0; i < 8; i++) {
        int xx = x + dir[i][0], yy = y + dir[i][1];
        if (mp[xx][yy] == mp[x][y] && mp[xx][yy] != INF && xx >= 0 & xx < 4 && yy >= 0 && y < 5) {
            mp[xx][yy] = INF;
            if (x < xx && x == xx && y < yy) {
                for (int i = 0; i < 5; i++) {
                    for (int j = 0; j < 4; j++) {
                    }
                }

            }
            for (int i = 0; i < 5; i++) {
                for (int j = 0; j < 4; j++) {
                    if (mp[i][j] == INF) {
                        mp[i][j] = mp[i][j + 1];
                        mp[i][j + 1] = INF;
                    }
                }
            }
            ans = min(n, ans);
            dfs(xx, yy, n - 2);
            for (int i = 0; i < 5; i++) {
                for (int j = 0; j < 4; j++) {

                }
            }
            
        }
    }
}

int main(int argc, char* argv[])
{
    freopen("/home/freaver/CODE_C/input.txt", "r", stdin);
    freopen("/home/freaver/CODE_C/output.txt", "w", stdout);
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    while (n--) {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 5; j++ ){
                cin >> mp[i][j];
            }
        }
        dfs(0, 0, 20);
    }

    return 0;
}
