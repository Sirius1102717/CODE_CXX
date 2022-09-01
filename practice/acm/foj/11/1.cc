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
int m, year, n, type;
double rate;
ll base, fee;

ll simple_rate() {
    int y = year;
    ll interest = 0;
    ll b = base;
    while(y--) {
        interest += b * rate;
        b -= fee;
    }
    return interest + b;
}

ll complex_rate() {
    int y = year;
    ll interest = 0, b = base;
    while(y--) {
        interest = b * rate;
        b += interest;
        b -= fee;
    }
    return b;
}

int main(int argc, char* argv[]) {

    freopen("/home/freaver/CODE_C/input.txt", "r", stdin);
    freopen("/home/freaver/CODE_C/output.txt", "w", stdout);
    cin >> m;
    while(m--) {
        cin >> base >> year >> n;
        ll ans = 0;
        while(n--) {
            cin >> type >> rate >> fee;
            if(type) {
                ans = max(complex_rate(), ans);
            } else {
                ans = max(simple_rate(), ans);
            }
        }
        cout << ans << endl;
    }

    return 0;
}
