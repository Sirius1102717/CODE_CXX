#include <algorithm>
#include <climits>
#include <cstring>
#include <deque>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
const int INF = 0x3f3f3f3f;
const int N = 2e2 + 5;
#define ll long long
int f[N];
ll n, m, k, ans, cnt;
struct node
{
    int x, y;
    ll w;

    friend bool operator<(node n1, node n2)
    {
        return n1.w < n2.w;
    }
} e[N];

int getParent(int x)
{
    return x == f[x] ? x : f[x] = getParent(f[x]);
}

void unite(int x, int y)
{
    int xx = getParent(x), yy = getParent(y);
    if (xx != yy) {
        f[x] = yy;
    }
}

void kruskal(int b)
{
    sort(e, e + m);
    for (int i = 1; i <= n; i++) {
        f[i] = i;
    }
    cnt = ans = 0;
    for (int i = b; i < m; i++) {
        int xx = getParent(e[i].x), yy = getParent(e[i].y);
        if (xx != yy) {
            f[xx] = yy;
            ans += e[i].w > k ? e[i].w - k : 0;
            if (++cnt == n - 1) {
                if (e[i].w < k) {
                    ans = k - e[i].w;
                    f[xx] = xx;
                    for (int j = i + 1; j < m; j++) {
                        xx = getParent(e[j].x), yy = getParent(e[j].y);
                        if (xx != yy && e[j].w > k) {
                            ans = min(ans, e[j].w - k);
                            return;
                        }
                    }
                }
                return;
            }
        }
    }
}

int main(int argc, char* argv[])
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    freopen("/home/freaver/CODE_C/input.txt", "r", stdin);
    freopen("/home/freaver/CODE_C/output.txt", "w", stdout);
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++) {
        cin >> e[i].x >> e[i].y >> e[i].w;
    }
    kruskal(0);
    cout << ans << endl;

    return 0;
}
