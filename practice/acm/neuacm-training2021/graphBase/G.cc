#include <cstring>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

const int N = 110;

int inDegree[N], n, m, u, v;
vector<int> adj[N];

void solve()
{
    queue<int> q;
    int num = 0;
    for (int i = 0; i < n; i++) {
        if (!inDegree[i]) {
            q.push(i);
        }
    }
    while (q.size()) {
        int u = q.front();
        q.pop();
        num++;
        for (int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i];
            inDegree[v]--;
            if (!inDegree[v]) {
                q.push(v);
            }
        }
    }
    if (num == n) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main(int argc, char* argv[])
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    while (cin >> n, n) {
        cin >> m;
        memset(adj, 0, sizeof adj);
        memset(inDegree, 0, sizeof inDegree);
        while (m--) {
            cin >> u >> v;
            adj[u].push_back(v);
            inDegree[v]++;
        }
        solve();
    }
    return 0;
}
