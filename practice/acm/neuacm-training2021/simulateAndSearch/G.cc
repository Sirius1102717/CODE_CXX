#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 1;
const int INF = 1e7;

char mp[N][N];

int tme[N][N];
bool visited[N][N];
int dir[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
int r, c, x, y;

struct Node
{
    int x, y, step;
    Node(int x0 = 0, int y0 = 0, int step0 = 0) : x(x0), y(y0), step(step0) { };
    friend bool operator < (Node a, Node b)
    {
        return a.step > b.step;
    }
};

queue<Node> q;

void init()
{
    memset(visited, 0, sizeof visited);
    memset(tme, 0, sizeof tme);
    while ( !q.empty() ) {
        Node now = q.front();
        q.pop();
        visited[now.x][now.y] = 1;
        for ( int i = 0; i < 4; i++ ) {
            int dx = now.x + dir[i][0];
            int dy = now.y + dir[i][1];
            if ( dx >= 0 && dx < r && dy >= 0 && dy < c
                && mp[dx][dy] != '#' && !visited[dx][dy] ) {
                q.push(Node(dx, dy));
                tme[dx][dy] = tme[now.x][now.y] + 1;
                visited[dx][dy] = 1;
            }
        }
    }
    for ( int i = 0; i < r; i++ ) {
        for ( int j = 0; j < c; j++ ) {
            if ( !tme[i][j] && mp[i][j] != '#' ) {
                tme[i][j] = INF;
            }
        }
    }
}

int bfs(int x, int y)
{
    memset(visited, 0, sizeof visited);
    priority_queue<Node> pq;
    pq.push(Node(x, y, 1));
    visited[x][y] = 1;
    while ( !pq.empty() ) {
        Node now = pq.top();
        pq.pop();
        if ( now.x == r - 1 || now.x == 0 || now.y == c - 1 || now.y == 0 ) {
            return now.step;
        }
        for ( int i = 0; i < 4; i++ ) {
            int dx = now.x + dir[i][0];
            int dy = now.y + dir[i][1];
            if ( dx >= 0 && dx < r && dy >= 0 && dy < c
                && !visited[dx][dy] && mp[dx][dy] != '#' && now.step < tme[dx][dy] ) {
                pq.push(Node(dx, dy, now.step + 1));
                visited[dx][dy] = 1;
            }
        }
    }
    return 0;
}



int main(int argc, char *argv[])
{
    std::ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while ( t-- ) {
        cin >> r >> c;
        while ( !q.empty() ) {
            q.pop();
        }
        for ( int i = 0; i < r; i++ ) {
            cin >> mp[i];
            for ( int j = 0; j < c; j++ ) {
                if ( mp[i][j] == 'J' ) {
                    x = i, y = j;
                } else if ( mp[i][j] == 'F' ) {
                    q.push(Node(i, j));
                }
            }
        }
        init();
        int ans = bfs(x, y);
        if ( ans ) {
            cout << ans;
        } else {
            cout << "IMPOSSIBLE";
        }
        cout << "\n";

    }

    return 0;
}
