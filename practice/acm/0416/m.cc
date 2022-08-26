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

int main(int argc, char* argv[]) {
    freopen("/home/freaver/CODE_C/practice/input.txt", "r", stdin);
    freopen("/home/freaver/CODE_C/practice/output.txt", "w", stdout);
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, n, k;
    cin >> t;
    while(t--) {
        cin >> n >> k;
        if(!n)
            cout << 0 << '\n';
        else {
            if(k > 40) {
                cout << 1 << '\n';
            } else {
                while(k--) {
                    n += 1;
                    n /= 2;
                }
                cout << n << '\n';
            }
        }
    }
    return 0;
}
