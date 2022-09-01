#include <algorithm>
#include <cstddef>
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

const int N = 1e3 + 5;

struct tree {
    int id;
    int left;
    int right;
    int sibling;
    int parent;
    int degree;
    int depth;
    tree() {
        parent = left = right = sibling = -1;
        degree = depth = 0;
    }
} t[N];

int d[N], h[N];

void get_height(int id, int p, int height) {
    if(p == -1 || !t[p].degree) {
        h[id] = max(h[id], height);
        return;
    }
    get_height(id, t[p].left, height + 1);
    get_height(id, t[p].right, height + 1);
}

void get_depth(int u, int depth) {
    if(~u) {
        d[u] = depth;
        get_depth(t[u].left, depth + 1);
        get_depth(t[u].right, depth + 1);

    }
}

void print(int id) {
    printf("node %d: ", id);
    printf("parent = %d, ", t[id].parent);
    printf("sibling = %d, ", t[id].sibling);
    printf("degree = %d, ", t[id].degree);
    printf("depth = %d, ", d[id]);
    printf("height = %d, ", h[id]);
    if(t[id].parent == -1)
        printf("root\n");
    else if(t[id].degree)
        printf("internal node\n");
    else
        printf("leaf\n");
}

int main(int argc, char* argv[]) {
    freopen("/home/freaver/CODE_C/practice/input.txt", "r", stdin);
    freopen("/home/freaver/CODE_C/practice/output.txt", "w", stdout);
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, id, left, right;
    scanf("%d", &n);
    memset(h, 0, sizeof h);
    memset(d, 0, sizeof d);
    for(int i = 0; i < n; i++) {
        scanf("%d%d%d", &id, &left, &right);
        t[id].left = left, t[id].right = right;
        if(~left) {
            t[left].parent = id;
            t[id].degree++;
            t[left].sibling = right;
            // t[left].depth = t[id].depth + 1;
        }
        if(~right) {
            t[right].parent = id;
            t[id].degree++;
            t[right].sibling = left;
            // t[right].depth = t[id].depth + 1;
        }
    }
    int root = 0;
    for(int i = 0; i < n; i++) {
        get_height(i, i, 0);
        if (~t[i].parent) continue;
        root = i;
    }
    get_depth(root, 0);
    for(int i = 0; i < n; i++)
        print(i);

    return 0;
}
