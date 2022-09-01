#include <algorithm>
#include <cmath>
#include <cstdio>
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
const int N = 1e2 + 5;
int n, k, num, u, v, w;
string be, ed, city, to, nex;
map<string, int> indx;
map<int, string> city_num;
bool vis[N];
int kill_num[N];
int dis[N];
int tot_num[N];
int tot_kill[N];

struct edge {
    int v;
    int w;
    edge(int v, int w) : v(v), w(w) {}
    edge() = default;
};

struct node {
    int u;
    int dis;
    int kill_num;
    int num;
    node(int u, int dis, int kill_num, int num) : u(u), dis(dis), kill_num(kill_num), num(num) {}
    node() = default;
    bool operator<(const node& n) const {
        return dis < n.dis || (dis == n.dis && num > n.num) || (dis == n.dis && num == n.num && kill_num > n.kill_num);
    }
};

vector<edge> e[N];

priority_queue<node> q;

void dijkstra(int be, int ed) {
    q.emplace(be, 0, 0, 0);
    memset(dis, INF, sizeof dis);
    vis[be] = 1;
    dis[be] = 0;
    while(!q.empty()) {
        u = q.top().u;
        q.pop();
        if(!vis[u]) {
            vis[u] = 1;
            for(edge ee : e[u]) {
                v = ee.v, w = ee.w;
                if(dis[u] > dis[v] + w || (dis[u] == dis[v] + w && tot_num[v] > tot_kill[u]) || (dis[u] == dis[v] + w && tot_num[v] == tot_num[u] && tot_kill[v])) {
                    dis[v] = dis[u] + w;
                    tot_num[v] = tot_num[u];
                    tot_kill[v] = tot_kill[u];
                    q.emplace(v, dis[v], tot_kill[v], tot_num[v]);
                }
            }
        }
    }
}


int main(int argc, char* argv[]) {
    freopen("/home/freaver/CODE_C/practice/input.txt", "r", stdin);
    freopen("/home/freaver/CODE_C/practice/output.txt", "w", stdout);
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k >> be >> ed;
    indx[be] = 0;
    city_num[0] = be;
    for(int i = 1; i < n; i++) {
        cin >> city >> num;
        indx[city] = i;
        city_num[i] = city;
        kill_num[i] = num;
    }
    for(int i = 0; i < k; i++) {
        cin >> to >> nex >> num;
        u = indx[to], v = indx[nex];
        e[u].emplace_back(v, num);
        e[v].emplace_back(u, num);
    }

    return 0;
}
