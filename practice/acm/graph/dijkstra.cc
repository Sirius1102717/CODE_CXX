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
const int N = 100;

int mp[N][N];
int dis[N];

int dis1[N][N];

bool vis[N];
void dijkstra(int n, int begin) {
    for(int i = 0; i < n; i++) {
        dis[i] = mp[begin][i];
    }
    memset(vis, 0, sizeof vis);
    vis[begin] = 1;
    int pos;

    for(int i = 0; i < n; i++) {
        int mmin = INF;
        for(int j = 0; j < n; j++) {
            if(!vis[i] && mmin > dis[j]) {
                mmin = dis[j];
                pos = i;
            }
        }
        vis[pos] = 1;
        for(int j = 0; j < n; j++) {
            if(!vis[j]) {
                dis[j] = min(dis[j], dis[pos] + mp[pos][j]);
            }
        }
    }
}




int main(int argc, char* argv[]) {
    freopen("/home/freaver/CODE_C/input.txt", "r", stdin);
    freopen("/home/freaver/CODE_C/output.txt", "w", stdout);
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    return 0;
}
