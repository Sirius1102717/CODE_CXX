#include <algorithm>
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
const int INF = 0x3f3f3f3f;
const int N = 100;

int c[N], topo[N], t;

int mp[N][N];

int n;

int in[N];

void top_sort() {
    queue<int> q;
    vector<int> e[N];
    for (int i = 0; i < n; i++) {
        if (!in[i]) {
            q.push(i);
        }
    }
    vector<int> ans;
    while(!q.empty()) {
        int p = q.front(); q.pop();
        ans.push_back(p);
        for (int i  = 0; i < e[p].size(); i++) {
            int y = e[p][i];
            in[y]--;
            if (!in[y]) {
                q.push(y);
            }
        }
    }

    if (ans.size() == n) {
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        putchar('\n');
    } else {
        cout << "No Answer" << endl;
    }
}

bool dfs(int u) {
    c[u] = -1;
    for(int v = 0; v < n; v++) {
        if(mp[u][v]) {
            if(c[v] < 0 || !dfs(v)) {
                return 0;
            }
        }
    }
    c[u] = 1, topo[--t] = u;
    return 1;
}


bool topo_sort() {
    t = n;
    memset(c, 0, sizeof c);
    for (int u = 0; u < n; u++) {
        if (!c[u]) {
            if (!dfs(u)) {
                return 0;
            }
        }
    }
    return 1;
}

int main(int argc, char* argv[]) {
    

    return 0;
}
