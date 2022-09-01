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
const int N = 1e5 + 5;
int v[N];

int n;
int x[N], o, q;
int sub[N];

int cal(int l, int r)
{
    int pre = 0;
    int ans = 1;
    for (int i = l; i <= r; i++) {
        pre += sub[i];

        if (pre > o) {
            pre = sub[i];
            ans++;
        }
    }
    return ans;
}
int main(int argc, char* argv[])
{
    freopen("/home/freaver/CODE_C/input.txt", "r", stdin);
    freopen("/home/freaver/CODE_C/output.txt", "w", stdout);
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    int pre = 0;
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
        sub[i] = x[i] - x[i - 1];
    }
    cin >> o >> q;
    int a, b;
    while (q--) {
        cin >> a >> b;
        int mm = min(a, b);
        int MM = max(a, b);
        cout << cal(mm, MM) << endl;
    }
    return 0;
}
