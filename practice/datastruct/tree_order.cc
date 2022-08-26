#include <algorithm>
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
    int left;
    int right;
    // int parent;
    // int degree;
    // int depth;
    // int height;
    // int sibling;
} t[N];

void pre_order(int u) {
    if(u == -1) return;
    printf(" %d", u);
    pre_order(t[u].left);
    pre_order(t[u].right);
}

void in_order(int u) {
    if(u == -1) return;
    in_order(t[u].left);
    printf(" %d", u);
    in_order(t[u].right);
}

void post_order(int u) {
    if(u == -1) return;
    post_order(t[u].left);
    post_order(t[u].right);
    printf(" %d", u);
}
int main(int argc, char* argv[]) {
    freopen("/home/freaver/CODE_C/practice/input.txt", "r", stdin);
    freopen("/home/freaver/CODE_C/practice/output.txt", "w", stdout);
    int n, id, left, right;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        t[i].parent = t[i].left = t[i].right = -1;
    for(int i = 0; i < n; i++) {
        scanf("%d%d%d", &id, &left, &right);
        t[id].left = left, t[id].right = right;
        if(~left) t[left].parent = id;
        if(~right) t[right].parent = id;
    }
    int root = 0;
    for(int i = 0; i < n; i++) {
        if(~t[i].parent) continue;
        root = i;
    }
    puts("Preorder");
    pre_order(root);
    puts("\nInorder");
    in_order(root);
    puts("\nPostorder");
    post_order(root);

    return 0;
}
