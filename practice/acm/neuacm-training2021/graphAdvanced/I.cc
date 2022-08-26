#include <cstdio>
#include <cstring>
const int N = 1e3 + 10;
int m, n;
bool vis[N], mp[N][N];
int girl[N];

bool match(int i)
{
    for (int j = 1; j <= n; j++) {
        if (mp[i][j] && !vis[j]) {
            vis[j] = 1;
            if (!girl[j] || match(girl[j])) {
                girl[j] = i;
                return 1;
            }
        }
    }
    return 0;
}

int main(int argc, char* argv[])
{

    int k, x, y;
    while (scanf("%d", &k), k) {
        memset(girl, 0, sizeof girl);
        memset(mp, 0, sizeof mp);
        scanf("%d%d", &m, &n);
        while (k--) {
            scanf("%d%d", &x, &y);
            mp[x][y] = 1;
        }
        int cnt = 0;
        for (int i = 1; i <= m; i++) {
            memset(vis, 0, sizeof vis);
            if (match(i)) {
                cnt++;
            }
        }
        printf("%d\n", cnt);
    }
    return 0;
}