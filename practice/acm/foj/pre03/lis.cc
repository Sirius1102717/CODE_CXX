#include <algorithm>
#include <cstring>
#include <deque>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
using ll = long long;
const double EPS = 1e-8;
const ll MAXN = 1e18;
const int INF = 0x3f3f3f3f;
const int N = 1e3;
int a[N], d[N];
int main(int argc, char* argv[])
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    d[1] = a[1];
    int len = 1;
    for (int i = 2; i <= n; i++) {
        if (a[i] > d[len]) {
            d[++len] = a[i];
        } else {
            int pos = lower_bound(d, d + len, a[i]) - d;
            d[pos] = a[i];
        }
    }
    int ans = len;

    return 0;
}
