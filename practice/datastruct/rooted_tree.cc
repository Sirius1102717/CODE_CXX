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
const int N = 1e5 + 5;


struct tree {
    int parent;
    int child;
    int sibling;
} t[N];

// struct node {
// int id;
// int depth;
// int parent;
// vector<int> children;
// node() {
// id = INF;
// }
// } t[N];

// bool cmp(node t1, node t2) {
// return t1.id < t2.id;
// }



// void vis(tree p) {
// t[indx].id = p.id;
// t[indx].parent = p.parent;
// t[indx].depth = p.depth;
// for(auto a : p.children)
// t[indx].children.emplace_back(a.id);
// indx++;
// for(auto a : p.children)
// vis(a);
// }


int d[N];

void get_depth(int u, int depth) {
    d[u] = depth;
    if(~t[u].sibling) get_depth(t[u].sibling, depth);
    if(~t[u].child) get_depth(t[u].child, depth + 1);
}

void print(int u) {

    printf("node %d: ", u);
    printf("parent = %d, ", t[u].parent);
    printf("depth = %d, ", d[u]);

    if(t[u].parent == -1)
        printf("root, ");
    else if(t[u].child == -1)
        printf("leaf, ");
    else
        printf("internal node, ");
    printf("[");
    for(int i = 0, c = t[u].child; c != -1; i++, c = t[c].sibling) {
        if(i) printf(", ");
        printf("%d", c);
    }
    printf("]\n");
}

int main(int argc, char* argv[]) {
    freopen("/home/freaver/CODE_C/practice/input.txt", "r", stdin);
    freopen("/home/freaver/CODE_C/practice/output.txt", "w", stdout);
    int n, id, k, x, child, sibling;
    scanf("%d", &n);
    memset(d, 0, sizeof d);
    for (int i = 0; i < n; i++) t[i].parent = t[i].child = t[i].sibling = -1;
    for(int i = 0; i < n; i++) {

        scanf("%d%d", &id, &k);
        // if(!i) create(root, -1, id);
        for(int j = 0; j < k; j++) {
            scanf("%d", &x);
            if(j)
                t[child].sibling = x;
            else
                t[id].child = x;
            child = x;
            t[x].parent = id;
        }

        for(int i = 0; i < n; i++) {
            if(~t[i].parent) continue;
            sibling = i;
        }
    }
    get_depth(sibling, 0);

    for (int i = 0; i < n; i++) print(i);
    // vis(root);
    // sort(t + 1, t + 1 + indx, cmp);
    // vector<int> v;
    // for(int i = 1; i < indx; i++) {
    // printf("node %d: parent = %d, depth = %d, ", t[i].id, t[i].parent, t[i].depth);
    // v = t[i].children;
    // if(t[i].parent == -1)
    // printf("root");
    // else if(v.size())
    // printf("internal node");
    // else
    // printf("leaf");
    // printf(", [");
    // if(v.size()) printf("%d", v[0]);
    // for(int j = 1; j < v.size(); j++)
    // printf(", %d", v[j]);
    // printf("]\n");
    // }
    return 0;
}
