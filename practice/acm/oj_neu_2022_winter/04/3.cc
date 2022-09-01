#include <algorithm>
#include <cmath>
#include <cstdio>
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
const double INF = 1e18;
const int N = 1e3 + 5;

double x[N], y[N], r[N];

bool vis[N];
double dis[N];
struct edge {
    int v;
    double w;
    edge(int v, double w) : v(v), w(w) {}
};

inline double dist(double a, double b, double c, double d, double r) {
    double tmp = sqrt((pow(a - b, 2) + pow(c - d, 2)));
    return tmp > r ? tmp - r : 0;
}

vector<edge> e[N];

queue<int> q;

int n;
double spfa() {
    memset(vis, 0, sizeof vis);
    vis[0] = 1, dis[0] = 0;
    q.emplace(0);
    while(!q.empty()) {
        int u = q.front();
        q.pop(), vis[u] = 0;
        for(auto a : e[u]) {
            int v = a.v;
            double w = a.w;
            if(dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                if(!vis[v]) q.emplace(v), vis[v] = 1;
            }
        }
    }
    return dis[n];
}

int main(int argc, char* argv[]) {
    double xs, ys, xt, yt;

    while(~scanf("%lf%lf%lf%lf", &xs, &ys, &xt, &yt)) {
        scanf("%d", &n);
        x[0] = xs, y[0] = ys, x[n + 1] = xt, y[n + 1] = yt, r[0] = 0, r[n + 1] = 0;
        for(int i = 1; i <= n; i++) {
            scanf("%lf%lf%lf", &x[i], &y[i], &r[i]);
        }
        n++;
        for(int i = 0; i <= n; i++) {
            for(int j = 0; j <= n; j++) {
                if(i != j) {
                    e[i].emplace_back(j, dist(x[i], x[j], y[i], y[j], r[i] + r[j]));
                    e[j].emplace_back(i, dist(x[i], x[j], y[i], y[j], r[i] + r[j]));
                }
            }
            dis[i] = INF;
        }

        printf("%.9f\n", spfa());
    }

    return 0;
}
