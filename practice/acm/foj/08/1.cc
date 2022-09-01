#include <algorithm>
#include <cstring>
#include <deque>
#include <iostream>
#include <queue>
#include <sched.h>
#include <stack>
#include <string>
#include <vector>
using namespace std;
using ll = long long;
const double EPS = 1e-8;
const ll MAXN = 1e18;
const int INF = 0x3f3f3f3f;

int main(int argc, char* argv[])
{
    freopen("/home/freaver/CODE_C/input.txt", "r", stdin);
    freopen("/home/freaver/CODE_C/output.txt", "w", stdout);
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int x, y;
    int ax = 0, ay = 0, tmpx = 0, tmpy = 0;
    while(n && cin >> x >> y) {
        if(!x && !y) {
            n--;
            cout << ax << " " << ay << endl;
            ax = 0, ay = 0, tmpx = 0, tmpy = 0;
            continue;
        }
        tmpx += x, tmpy += y;
        if(tmpx * tmpx + tmpy * tmpy > ax * ax + ay * ay || tmpx * tmpx + tmpy * tmpy == ax * ax + ay * ay && tmpx > ax) {
            ax = tmpx, ay = tmpy;
        }
    }
    return 0;
}
