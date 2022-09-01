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

int main(int argc, char* argv[])
{
    freopen("/home/freaver/CODE_C/input.txt", "r", stdin);
    freopen("/home/freaver/CODE_C/output.txt", "w", stdout);
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n, s;
    while (cin >> n >> s) {
        bool flag = 1;
        if (s != n) {
            for (ll b = 2; b <= n; b++) {
                ll ans = 0;
                ll tmp = n;
                while (tmp) {
                    ans += tmp % b;
                    tmp /= b;
                } if (ans == s) {
                    cout << b << endl;
                    flag = 0;
                    break;
                }
            }
            if (flag) {

 }
        } else {
            cout << n + 1 << endl;
        }
    }
    return 0;
}
