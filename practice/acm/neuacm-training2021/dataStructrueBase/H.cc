#include<iostream>
#include<cstring>
using namespace std;
const double EPS = 1e-8;
const int N = 2e4 + 1;

struct 
{
    int to;
    int next;
}edges[N << 1];

int head[N], dp[N];
int ans, n, mins, id;

void update(int u, int v)
{
    edges[ans].to = v;
    edges[ans].next = head[u];
    head[u] = ans++;
}


void dfs(int u, int father)
{
    dp[u] = 1;
    int maxs = 0;
    for ( int i = head[u]; i != -1; i = edges[i].next ) {
        int v = edges[i].to;
        if ( v != father ) {
            dfs(v, u);
            dp[u] += dp[v];
            maxs = max(maxs, dp[v]);
        }
    }
    maxs = max(maxs, n - dp[u]);
    if ( maxs < mins ) {
        mins = maxs;
        id = u;
    }
}



int main(int argc, char *argv[])
{
    int t;
    cin >> t;
    while ( t-- ) {
        cin >> n;
        memset(head, -1, sizeof head);
        memset(dp, 0, sizeof dp);
        ans = 0;
        int u, v;
        for ( int i = 1; i < n; i++ ) {
            cin >> u >> v;
            update(u, v);
            update(v, u);
        }
        mins = N;
        dfs(1, 0);
        cout << id << " " << mins << "\n";
    }

    return 0;
}
