#include <cstring>
#include <iostream>
using namespace std;
typedef pair<int, int> ipair;

ipair in[4];
int n;
bool vis[4][4];
void dfs(int c) {
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            if(!vis[i][j]) {
                vis[i][j] = 1;
                for(int k = 0; k < 4; k++) {
                    int xx = i + in[k].first, yy = j + in[k].second;
                    if(xx >= 0 && xx < 4 && yy >= 0 && yy < 4 && !vis[xx][yy]) {
                        if(c == 7) {
                            n++;
                            continue;
                        }
                        vis[xx][yy] = 1;
                        dfs(c + 1);
                        vis[xx][yy] = 0;
                    }
                }
                vis[i][j] = 0;
            }
        }
    }
}

int main(int argc, char* argv[]) {
    freopen("/home/freaver/CODE_C/input.txt", "r", stdin);
    freopen("/home/freaver/CODE_C/output.txt", "w", stdout);
    int x;
    while(~scanf("%d", &x) && abs(x) < 4) {
        memset(vis, 0, sizeof vis);

        in[0].first = x;
        scanf("%d", &in[0].second);
        for(int i = 1; i < 4; i++) {
            scanf("%d%d", &in[i].first, &in[i].second);
        }
        n = 0;
        dfs(0);

        printf("%d\n", n / 40300);
    }
    return 0;
}
