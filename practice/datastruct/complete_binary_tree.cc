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
const int INF = 0x7f7f7f7f;
const int N = 1e3 + 5;

struct tree {
    int key;
    int parent;
    tree* left;
    tree* right;
    tree(int key, int parent) : key(key), parent(parent), left(nullptr), right(nullptr) {}
    tree () {
        parent = key = INF;
        left = right = nullptr;
    }
}t[N];

inline int lc(int x) {
    return x << 1;
}

inline int rc(int x) {
    return x << 1 | 1;
}

void insert(tree*& p, int key, int parent) {
    if(!p) {
        p = new tree(key, parent);
        return;
    }
    if(p->key < key)
        insert(p->right, key, p->key);
    else
        insert(p->left, key, p->key);
}

void in_order(tree* p) {
    if(p) {
        in_order(p->left);
        cout << ' ' << p->key;
        in_order(p->right);
    }
}

void pre_order(tree* p) {
    if(p) {
        cout << ' ' << p->key;
        pre_order(p->left);
        pre_order(p->right);
    }
}

void print(tree* p) {
    in_order(p);
    cout << '\n';
    pre_order(p);
    cout << '\n';
}

void print(int n) {
    for (int i = 1; i <= n; i++) {
        printf("node %d: key = %d, ", i, t[i].key);
        if (t[i].parent != INF) printf("parent key = %d, ", t[i].parent);
        if (t[lc(i)].key != INF) printf("left key = %d, ", t[lc(i)].key);
        if (t[rc(i)].key != INF) printf("right key = %d, ", t[rc(i)].key);
        puts("");
    }

}

int main(int argc, char* argv[]) {
    freopen("/home/freaver/CODE_C/practice/input.txt", "r", stdin);
    freopen("/home/freaver/CODE_C/practice/output.txt", "w", stdout);
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, x;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        t[i].key = x;
        t[lc(i)].parent = x;
        t[rc(i)].parent = x;
    }
    print(n);

    return 0;
}
