#include <cstring>
#include <iostream>
#include <queue>
#include <string>

using namespace std;
const int INF = 0x3f3f3f3f;
const int N = 1e3 + 5;
int head[N << 1], tot = 0, n, m, d[N << 1], visit[N << 1];
char mp[N][N];
struct node
{
    int to, nex;
} e[N * N << 2];

void add(int x, int y)
{
    e[++tot].nex = head[x];
    e[tot].to = y;
    head[x] = tot;
}

void bfs()
{
    memset(visit, 0, sizeof visit);
    for (int i = 1; i <= n + m; i++) {
        d[i] = INF;
    }
    queue<int> q;
    q.push(1);
    visit[1] = 1;
    d[1] = 0;
    while (q.size()) {
        int x = q.front();
        q.pop();
        for (int i = head[x]; i; i = e[i].nex) {
            int y = e[i].to;
            if (!visit[y]) {
                d[y] = d[x] + 1;
                q.push(y);
                visit[y] = 1;
            }
        }
    }
}

int main(int argc, char* argv[])
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> (mp[i] + 1);
        for (int j = 1; j <= m; j++) {
            if (mp[i][j] == '#') {
                add(i, j + n), add(j + n, i);
            }
        }
    }
    bfs();
    if (d[n] == INF) {
        cout << -1 << endl;
    } else {
        cout << d[n] << endl;
    }

    return 0;
}
