#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
const int N = 1e6 + 10;
// const int M = 2e5 + 10;

int bits[N] = { 0 }, visit[N] = { 0 }, a[N], ans[N];
int n, m;

struct node
{
    int l, r, pos;
} ask[N];

bool cmp(node n1, node n2)
{
    return n1.r < n2.r;
}

inline int lowbit(int x)
{
    return x & -x;
}

inline void add(int x, int k)
{
    while (x <= n) {
        bits[x] += k;
        x += lowbit(x);
    }
}

inline int query(int x)
{
    int ans = 0;
    while (x) {
        ans += bits[x];
        x -= lowbit(x);
    }
    return ans;
}

inline int rangeSum(int l, int r)
{
    return query(r) - query(l - 1);
}

int main(int argc, char* argv[])
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    cin >> m;
    for (int i = 1; i <= m; i++) {
        cin >> ask[i].l >> ask[i].r;
        ask[i].pos = i;
    }
    sort(ask + 1, ask + 1 + m, cmp);
    int nex = 1;
    for (int i = 1; i <= m; i++) {
        for (int j = nex; j <= ask[i].r; j++) {
            if (visit[a[j]]) {
                add(visit[a[j]], -1);
            }
            add(j, 1);
            visit[a[j]] = j;
        }
        nex = ask[i].r + 1;
        ans[ask[i].pos] = rangeSum(ask[i].l, ask[i].r);
    }
    for (int i = 1; i <= m; i++) {
        cout << ans[i] << "\n";
    }
    return 0;
}
