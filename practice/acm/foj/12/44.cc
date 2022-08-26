#include <algorithm>
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

int bfs(int bx, int by, int ex, int ey) {
    queue<node> q;
    node n = node(bx, by, 0);
    // for(int k = 0; k < h; k++) {
    // for(int l = 0; l < w; l++) {
    // n.mp[k][l] = mp[k][l];
    // }
    // }
    q.push(n);
    while(!q.empty()) {
        node front = q.front();
        if(front.step >= 10) {
            return -1;
        }
        q.pop();
        for(int i = 0; i < 4; i++) {
            int xx = front.x + dir[i][0], yy = front.y + dir[i][1];
            while(!mp[xx][yy] || (xx == front.prex && yy == front.prey)) {
                if(in(xx, yy)) {
                    if(xx == ex && yy == ey) {
                        return front.step + 1;
                    }
                    int xxx = xx + dir[i][0], yyy = yy + dir[i][1];
                    if(in(xxx, yyy) && mp[xxx][yyy] == 1 && (xxx != front.prex || yyy != front.prey)) {
                        node n = node(xx, yy, front.step + 1);
                        // for(int k = 0; k < h; k++) {
                        // for(int l = 0; l < w; l++) {
                        // n.mp[k][l] = front.mp[k][l];
                        // }
                        // }
                        n.prex = xxx, n.prey = yyy;
                        q.push(n);
                        break;
                    }
                    xx += dir[i][0], yy += dir[i][1];
                } else {
                    break;
                }
            }
        }
    }
    return -1;
}

int main(int argc, char* argv[]) {

    while(~scanf("%d%d", &w, &h)) {
        if(!w && !h) {
            break;
        }
        int bx = 0, by = 0, ex = 0, ey = 0;
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
        printf("%d\n", bfs(bx, by, ex, ey));
    }

    return 0;
}