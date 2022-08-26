#include <cstring>
#include <queue>
#include<cstdio>
using namespace std;
int dir[4][2] = { { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 } };
int maze[5][5], visited[5][5];
struct node
{
    int x, y;
};
node pre[10][10];
void bfs()
{
    queue<node> q;
    node i;
    i.x = i.y = 0;
    q.push(i);
    visited[0][0] = 1;
    while (!q.empty()) {
        node now = q.front();
        q.pop();
        if (now.x == 4 && now.y == 4) {
            return;
        }
        for (int j = 0; j < 4; j++) {
            node next;
            next.x = now.x + dir[j][0];
            next.y = now.y + dir[j][1];
            if (next.x >= 0 && next.x < 5 && next.y >= 0 && next.y < 5 && !maze[next.x][next.y] && !visited[next.x][next.y]) {
                visited[next.x][next.y] = 1;
                q.push(next);
                pre[next.x][next.y] = now;
            }
        }
    }
}
void print(node cur)
{
    if (cur.x == 0 && cur.y == 0) {
        printf("(0, 0)\n");
        return;
    }
    print(pre[cur.x][cur.y]);
    printf("(%d, %d)\n", cur.x, cur.y);
}
int main(int argc, char* argv[])
{
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            scanf("%d", &maze[i][j]);
        }
    }
    bfs();
    node ed;
    ed.x = ed.y = 4;
    print(ed);
    return 0;
}
