#include <algorithm>
#include <cmath>
#include <cstring>
#include <deque>
#include <iostream>
#include <queue>
#include <stack>
#include <stdexcept>
#include <string>
#include <vector>
using namespace std;
using ll = long long;
const double EPS = 1e-8;
const ll MAXN = 1e18;
const int INF = 0x3f3f3f3f;

const int RIGHT = 1;
const int LEFT = 0;

int get_direction(int x1, int x2, int y1, int y2) {
    if(y1) {
        if(y1 * x2 > 0) {
            return RIGHT;
        } else {
            return LEFT;
        }
    } else {
        if(x1 * y2 > 0) {
            return LEFT;
        } else {
            return RIGHT;
        }
    }
}

struct li {
    int length;
    int direction;
    li() {
        length = 0;
        direction = -1;
    }
};

struct line {
    int m;
    li l1[20];
    li l2[20];

    bool friend operator==(line l1, line l2) {
        bool flag1 = 1, flag2 = 1;
        if(l1.m == l2.m) {
            int m = l1.m - 1;
            for(int i = 0; i < m; i++) {
                if(l1.l1[i].length != l2.l1[i].length || l1.l1[i].direction != l2.l1[i].direction) {
                    flag1 = 0;
                    break;
                }
            }
            for(int i = 0; i < m; i++) {
                if(l1.l1[i].length != l2.l2[i].length || l1.l1[i].direction != l2.l2[i].direction) {
                    flag2 = 0;
                    break;
                }
            }
        } else {
            return 0;
        }
        return flag1 || flag2;
    }

} lines[100];

int main(int argc, char* argv[]) {
    freopen("/home/freaver/CODE_C/input.txt", "r", stdin);
    freopen("/home/freaver/CODE_C/output.txt", "w", stdout);
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    int x[20], y[20];
    while(cin >> n) {
        if(!n) {
            break;
        }
        int x1, y1, x2, y2, x3, y3;
        for(int k = 0; k <= n; k++) {
            cin >> m;
            lines[k].m = m;
            for(int i = 0; i < m; i++) {
                cin >> x[i] >> y[i];
            }

            x1 = x[0], y1 = y[0], x2 = x[1], y2 = y[1];
            lines[k].l1[0].length = abs(x2 + y2 - x1 - y1);
            int cnt = 1;
            for(int i = 2; i < m; i++) {
                x3 = x[i], y3 = y[i];
                lines[k].l1[cnt].length = abs(x3 + y3 - x2 - y2);
                lines[k].l1[cnt++].direction = get_direction(x2 - x1, x3 - x2, y2 - y1, y3 - y2);
                x1 = x2, y1 = y2, x2 = x3, y2 = y3;
            }
            cnt = 1;

            x1 = x[m - 1], y1 = y[m - 1], x2 = x[m - 2], y2 = y[m - 2];
            lines[k].l2[0].length = abs(x2 + y2 - x1 - y1);
            for(int i = m - 3; i >= 0; i--) {
                x3 = x[i], y3 = y[i];
                lines[k].l2[cnt].length = abs(x3 + y3 - x2 - y2);
                lines[k].l2[cnt++].direction = get_direction(x2 - x1, x3 - x2, y2 - y1, y3 - y2);
                x1 = x2, y1 = y2, x2 = x3, y2 = y3;
            }
        }
        for(int i = 1; i <= n; i++) {
            if(lines[0] == lines[i]) {
                cout << i << endl;
            }
        }
        cout << "+++++" << endl;
    }

    return 0;
}
