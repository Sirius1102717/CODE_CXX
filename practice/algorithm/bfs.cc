#include<bits/stdc++.h>
using namespace std;
#define ll long long
const double EPS = 1e-8;
const ll MAXN = 100;


queue<int> q;

bool isVisited[MAXN];

typedef struct AMGraph
{
    int vexs[MAXN];
    int arcs[MAXN][MAXN];
    int vex, arc;

    int locateVex(int n)
    {
        for ( int i = 0; i < vex; i++ ) {
            if ( vexs[i] == i ) {
                return i;
            }
        }
        return -1;
    }

    void create()
    {
        int i, j, k;
        int v1, v2;
        cin >> vex >> arc;
        for ( i = 0; i < vex; i++ ) {
            cin >> vexs[i];
        }
        for ( i = 0; i < vex; i++ ) {
            for ( j = 0; j < vex; j++ ) {
                arcs[i][j] = 0;
            }
        }

        for ( k = 0; k < arc; k++ ) {
            cin >> v1 >> v2;
            i = locateVex(v1);
            j = locateVex(v2);

            arcs[i][j] = arcs[j][i] = 1;
        }
    }

    void bfs(int v0)
    {
        int u, i, v, w;
        v = locateVex(v0);
        cout << v0 << " ";

        isVisited[v] = true;
        q.push(v0);
        while ( !q.empty() ) {
            u = q.front();
            v = locateVex(u);
            q.pop();
            for ( int i = 0; i < vex; i++ ) {
                w = vexs[i];
                if ( arcs[v][i] && !isVisited[i] ) {
                    cout << w << " ";
                    q.push(w);
                    isVisited[i] = true;
                }
            }
        }
    }

}AMGraph;



typedef struct ArcNode
{
    int adjvex;
    struct ArcNode *nextArc;
    int info;
}ArcNode;

typedef struct VexNode
{
    int data;
    ArcNode *firstArc;
}VexNode, AdjList[MAXN];

// typedef struct 


int main(int argc, char *argv[])
{
    std::ios::sync_with_stdio(false);
    AMGraph a;
    a.create();
    return 0;
}
