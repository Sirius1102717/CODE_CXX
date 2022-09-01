#include <algorithm>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <vector>
using namespace std;
using ll = long long;
const double EPS = 1e-8;
const ll MAXN = 1e18;
const int INF = 0x3f3f3f3f;
const int N = 2e4 + 5;

int fa[N];

int get_fa(int x) {
    return fa[x] == x ? x : fa[x] = get_fa(fa[x]);
}

void join(int x, int y) {
    int xx = get_fa(x), yy = get_fa(y);
    if(xx != yy) fa[xx] = yy;
}

map<int, bool> m;

int vis[N];

int a[N];

int main(int argc, char* argv[]) {
    freopen("/home/freaver/CODE_C/practice/input.txt", "r", stdin);
    freopen("/home/freaver/CODE_C/practice/output.txt", "w", stdout);
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int k, x, y, q, pre, num = 0;
    for (int i = 1; i <= N; i++) fa[i] = i;
    for(int i = 1; i <= n; i++) {
        cin >> k;
        if(k) {
            cin >> pre;
            if (!vis[pre]) {
                num++;
                vis[pre] = 1;
            }
            for(int i = 1; i < k; i++) {
                cin >> x;
                if (!vis[x]) {
                    num++;
                    vis[x] = 1;
                }
                join(x, pre);
            }
        }
        a[i] = get_fa(x);
    }
    m[get_fa(1)] = 1;
    int cnt = 1;
    for(int i = 2; i <= n; i++) {
        int ii = get_fa(i);
        if(m.find(ii) == m.end()) cnt++;
        m[ii] = 1;
    }
    cout << num << ' ' << cnt << '\n';
    cin >> q;
    while(q--) {
        cin >>x >> y;
        if (get_fa(x) != get_fa(y)) cout << "N\n";
        else cout << "Y\n";
    }

    return 0;
}
