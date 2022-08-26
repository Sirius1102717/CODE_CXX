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

const int N = 1e5 + 5;
int fa[N];

int get_fa(int x) {
    return x == fa[x] ? x : get_fa(fa[x]);
}

struct node {
    int u;
    int v;
    int w;

    node(int u, int v, int w) : u(u), v(v), w(w) {}

    bool operator<(const node& n) {
        return w < n.w;
    }
};

vector<node> e;

struct edge {
    int v;
    int w;
    edge(int v, int w) : v(v), w(w) {}
};

vector<edge> vv[N];

int mst(int n) {
    for(int i = 1; i <= n; i++)
        fa[i] = i;
    int ans = 0;
    int cnt = 0;
    for(node ee : e) {
        int xx = get_fa(ee.u), yy = get_fa(ee.v);
        if(xx != yy) {
            fa[xx] = yy;
            ans += ee.w;
            cnt++;
        }
        if(cnt == n - 1) return ans;
    }
    return -1;
}

int main(int argc, char* argv[]) {
    freopen("/home/freaver/CODE_C/practice/input.txt", "r", stdin);
    freopen("/home/freaver/CODE_C/practice/output.txt", "w", stdout);
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, n, u, v, w;
    cin >> t;
    while(t--) {
        cin >> n;
        for(int i = 1; i < n; i++) {
            cin >> u >> v >> w;
            if(u > v) swap(u, v);
            vv[u].emplace_back(v, w);
        }
        int cnt = 1;
        for(int i = 1; i <= n; i++) {
            for 
        }
    }
    return 0;
}
