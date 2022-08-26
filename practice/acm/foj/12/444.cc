
#include <algorithm>
#include <complex>
#include <cstdio>
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

int mp[30][30];

int dir[4][2] = { 1, 0, -1, 0, 0, 1, 0, -1 };

int w, h;
bool in(int x, int y) {
    return x >= 0 && x < h && y >= 0 && y < w;
}

struct node {
    int x, y, step;
    int prex, prey;
    // int mp[30][30];
    node(int xx, int yy, int sstep) {
        x = xx, y = yy, step = sstep;
        prex = prey = -1;
    }
};

int ans;

int bx = 0, by = 0, ex = 0, ey = 0;
void dfs(int x, int y, int step) {
    if(step > 10) {
        return;
    }
    for(int i = 0; i < 4; i++) {
        int xx = x + dir[i][0], yy = y + dir[i][1];
        while(in(xx, yy) && !mp[xx][yy]) {
            if(xx == ex && yy == ey) {
                ans = min(ans, step);
                return;
            }
            int xxx = xx + dir[i][0], yyy = yy + dir[i][1];
            if(in(xxx, yyy) && mp[xxx][yyy]) {
                mp[xxx][yyy] = 0;
                dfs(xx, yy, step + 1);
                mp[xxx][yyy] = 1;
                break;
            }
            xx += dir[i][0], yy += dir[i][1];
        }
    }
}

int bfs(int bx, int by, int ex, int ey) {
    queue<node> q;
    node n = node(bx, by, 0);
    q.push(n);
    while(!q.empty()) {
        node front = q.front();
        if(front.step >= 10) {
            return -1;
        }
        q.pop();
        if(front.prex != -1) {
            mp[front.prex][front.prey] = 0;
        }
        for(int i = 0; i < 4; i++) {
            int xx = front.x + dir[i][0], yy = front.y + dir[i][1];
            while(in(xx, yy) && !mp[xx][yy]) {
                if(xx == ex && yy == ey) {
                    return front.step + 1;
                }
                int xxx = xx + dir[i][0], yyy = yy + dir[i][1];
                if(in(xxx, yyy) && mp[xxx][yyy] == 1) {
                    node n = node(xx, yy, front.step + 1);
                    n.prex = xxx, n.prey = yyy;
                    q.push(n);
                    break;
                }
                xx += dir[i][0], yy += dir[i][1];
            }
        }
        if(front.prex != -1) {
            mp[front.prex][front.prey] = 1;
        }
    }
    return -1;
}

int main(int argc, char* argv[]) {
    freopen("/home/freaver/CODE_C/input.txt", "r", stdin);
    freopen("/home/freaver/CODE_C/output.txt", "w", stdout);
    while(~scanf("%d%d", &w, &h)) {
        if(!w && !h) {
            break;
        }
        for(int i = 0; i < h; i++) {
            for(int j = 0; j < w; j++) {
                scanf("%d", &mp[i][j]);
                if(mp[i][j] == 2) {
                    bx = i, by = j;
                    mp[i][j] = 0;
                } else if(mp[i][j] == 3) {
                    ex = i, ey = j;
                    mp[i][j] = 0;
                }
            }
        }
        ans = INF;
        dfs(bx, by, 1);
        printf("%d\n", ans > 10 ? -1 : ans);
    }

    return 0;
}
