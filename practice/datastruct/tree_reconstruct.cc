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
const int N = 1e3 + 5;
struct tree {
    int id;
    tree* left;
    tree* right;
    tree(int id) : id(id), left(nullptr), right(nullptr) {}
    tree() : left(nullptr), right(nullptr) {}
};
int pre[N], in[N];

void rebuild(int a, int b, int n, tree*& p) {
    if(n == 1) {
        p = new tree(pre[a]);
        return;
    }
    if(n <= 0) return;
    int i = 0;
    tree *left, *right;
    while(pre[a] != in[b + i]) {
        i++;
    }
    rebuild(a + 1, b, i, left);
    rebuild(a + 1 + i, b + 1 + i, n - i - 1, right);
    p = new tree(pre[a]);
    p->left = left, p->right = right;
}

tree* build(int pb, int pe, int ib, int ie) {
    if(pb >= pe || ib >= ie) return nullptr;
    tree* root = new tree(pre[pb]);
    int r = 0;
    while(pre[pb] != in[ib + r]) {
        r++;
    }
    root->left = build(pb + 1, r - ib + pb + 1, ib, r);
    root->right = build(r - ib + pb + 1, pe, r + 1, ie);
    return root;
}

void pre_order(tree* p) {
    if(p) {
        pre_order(p->left);
        pre_order(p->right);
        cout << p->id << ' ';
    }
}
int main(int argc, char* argv[]) {
    freopen("/home/freaver/CODE_C/practice/input.txt", "r", stdin);
    freopen("/home/freaver/CODE_C/practice/output.txt", "w", stdout);
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> pre[i];
    for(int i = 0; i < n; i++)
        cin >> in[i];
    tree* root = build(0, n, 0, n);
    // tree *root;
    // rebuild(0, 0, n, root);
    pre_order(root);
    return 0;
}
