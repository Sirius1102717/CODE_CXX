#include <deque>
#include <iostream>
using namespace std;
const int INF = 0x3f3f3f3f;
const int N = 1e3 + 5;

int n, m;
char mp[N][N];
int dist[N][N][4], dir[5][2] = { 1, 0, -1, 0, 0, 1, 0, -1 };
deque<int> q;

void addFront(int x, int y, int d, int dis)
{
    if (dis < dist[x][y][d]) {
        dist[x][y][d] = dis;
        q.push_front(d);
        q.push_front(x);
        q.push_front(y);
    }
}

void addBack(int x, int y, int d, int dis)
{
    if (dis < dist[x][y][d]) {
        dist[x][y][d] = dis;
        q.push_back(x);
        q.push_back(y);
        q.push_back(d);
    }
}

void bfs()
{
    addFront(n - 1, m - 1, 3, 0);
    while (q.size()) {
        int x = q[0], y = q[1], d = q[2];
        q.pop_front();
        q.pop_front();
        q.pop_front();
        int dis = dist[x][y][d];
        int nx = x + dir[d][0], ny = y + dir[d][1];
        if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
            addFront(nx, ny, d, dis);
        }
        if (mp[x][y] == '#') {
            for (int i = 0; i < 4; i++) {
                if (i != d) {
                    addBack(x, y, i, dis + 1);
                }
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
    for (int i = 0; i < n; i++) {
        cin >> mp[i];
    }
    fill(dist, dist + N, INF);

    if (dist[0][0][3] == INF) {
        cout << -1 << endl;
    } else {
        cout << dist[0][0][3] << endl;
    }

    return 0;
}
