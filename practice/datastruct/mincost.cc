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
const int N = 1e4 + 5;

int a[N];
int b[N];
int p[N];
bool flag[N];


int main(int argc, char* argv[]) {
    freopen("/home/freaver/CODE_C/practice/input.txt", "r", stdin);
    freopen("/home/freaver/CODE_C/practice/output.txt", "w", stdout);
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int x = INF;
    int ans = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i], b[i] = a[i];
        flag[i] = 0;
        x = min(a[i], x);
    }
    sort(b, b + n);
    for(int i = 0; i < n; i++)
        p[b[i]] = i;
    for(int i = 0; i < n; i++) {
        if(flag[i]) continue;
        int cur = i;
        int s = 0, m = INF, num = 0;
        for(;;) {
            flag[cur] = 1;
            num++;
            int v = a[cur];
            s += v;
            m = min(m, v);
            cur = p[v];
            if(flag[cur]) break;
        }
        ans += min(s + (num - 2) * m, s + m + (num + 1) * x);
    }
    cout << ans << endl;

    return 0;
}
