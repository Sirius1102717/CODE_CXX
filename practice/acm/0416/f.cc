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

const int N = 1e6 + 5;
ll a[N];
int main(int argc, char* argv[]) {
    freopen("/home/freaver/CODE_C/practice/input.txt", "r", stdin);
    freopen("/home/freaver/CODE_C/practice/output.txt", "w", stdout);
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, n;
    ll avg, ans;
    cin >> t;
    while(t--) {
        cin >> n;
        ans = 0;
        avg = 0;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            avg += a[i];
        }
        avg /= n;
        for(int i = 0; i < n; i++)
            if(a[i] > avg) ans += a[i] - avg;

        cout << ans << '\n';
    }
    return 0;
}
