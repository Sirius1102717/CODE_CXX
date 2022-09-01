#include <cstring>
#include <iostream>
#include <string>
using namespace std;
const int N = 505;
const int INF = 0x3f3f3f3f;
int grid[N][N], f[N], n, k, x, y;
bool vis[N];


bool match(int i)
{
    for (int j = 1; j <= n; j++) {
        if (grid[i][j] && !vis[j]) {
            vis[j] = 1;
            if (!f[j] || match(f[j])) {
                f[j] = i;
                return 1;
            }
        }
    }
    return 0;
}

int main(int argc, char* argv[])
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    memset(grid, 0, sizeof grid);
    memset(f, 0, sizeof f);
    while (k--) {
        cin >> x >> y;
        grid[x][y] = 1;
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        memset(vis, 0, sizeof vis);
        if (match(i)) {
            cnt++;
        }
    }
    cout << cnt << "\n";

    return 0;
}
