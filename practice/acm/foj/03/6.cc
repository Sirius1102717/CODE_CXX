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
struct node
{
    int x, y, dir;
    node()
    {
        dir = 0;
        x = 1, y = 1;
    }
};
int main(int argc, char* argv[])
{
    freopen("/home/freaver/CODE_C/input.txt", "r", stdin);
    freopen("/home/freaver/CODE_C/output.txt", "w", stdout);
    int n, m;
    while (scanf("%d%d", &n, &m) != EOF) {
        if (!n && !m) {
            break;
        }
        node robot;
        string order;
        int t;
        while (cin >> order) {
            if (order == "FORWARD") {
                cin >> t;
                switch (robot.dir) {
                    case 0:
                        robot.y += t;
                        if (robot.y > m) {
                            robot.y = m;
                        }
                        break;
                    case 1:
                        robot.x += t;
                        if (robot.x > n) {
                            robot.x = n;
                        }
                        break;
                    case 2:
                        robot.y -= t;
                        if (robot.y < 1) {
                            robot.y = 1;
                        }
                        break;

                    case 3:
                        robot.x -= t;
                        if (robot.x < 1) {
                            robot.x = 1;
                            ;
                        }
                        break;
                }
            } else if (order == "RIGHT") {
                robot.dir += 1;
                robot.dir %= 4;
            } else if (order == "LEFT") {
                robot.dir -= 1;
                if (robot.dir == -1) {
                    robot.dir = 3;
                }
            } else if (order == "BACKWARD") {
                cin >> t;
                switch (robot.dir) {
                    case 0:
                        robot.y -= t;
                        if (robot.y < 1) {
                            robot.y = 1;
                        }
                        break;
                    case 1:
                        robot.x -= t;
                        if (robot.x < 1) {
                            robot.x = 1;
                        }
                        break;
                    case 2:
                        robot.y += t;
                        if (robot.y > m) {
                            robot.y = m;
                        }
                        break;

                    case 3:
                        robot.x += t;
                        if (robot.x > n) {
                            robot.x = n;
                            ;
                        }
                        break;
                }
            } else {
                cout << robot.x << " " << robot.y << endl;
                break;
            }
        }
    }
    return 0;
}
