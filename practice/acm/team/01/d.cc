#include <algorithm>
#include <cmath>
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
const int N = 2e5 + 5;

int x[N], c[N];
int main(int argc, char* argv[]) {
    freopen("/home/freaver/CODE_C/practice/input.txt", "r", stdin);
    freopen("/home/freaver/CODE_C/practice/output.txt", "w", stdout);
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, n, h, H, tim;
    cin >> t;
    while(t--) {
        int idx, mmin = INF;
        cin >> n >> h >> H;
        for(int i = 1; i <= n; i++)
            cin >> x[i];
        for(int i = 1; i <= n; i++)
            cin >> c[i];
        for(int i = 1; i <= n; i++) {
            int cur = 0;
            bool flag = 1;
            if(x[i] / H & 1)
                cur = H - x[i] % H;
            else
                cur = x[i] % H;
            if(cur <= h)
                tim = c[i] + x[i];
            else
                tim = x[i] + c[i] + H * 2 - h - cur;
            if(tim < mmin) {
                idx = i;
                mmin = tim;
            }
        }
        cout << idx << '\n';
    }
    return 0;
}
