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

ll x;

int main(int argc, char* argv[]) {
    freopen("/home/freaver/CODE_C/practice/input.txt", "r", stdin);
    freopen("/home/freaver/CODE_C/practice/output.txt", "w", stdout);
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> x;
    if(x < 7) {
        cout << 1 << endl;
        return 0;
    }
    ll y = x / 11 * 2;
    x %= 11;
    if(x && x < 7)
        y++;
    else if(x > 6)
        y += 2;
    cout << y << endl;

    return 0;
}
