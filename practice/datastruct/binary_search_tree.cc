#include <algorithm>
#include <cstdio>
#include <cstring>
#include <deque>
#include <future>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <sys/types.h>
#include <vector>
using namespace std;
using ll = long long;
const double EPS = 1e-8;
const ll MAXN = 1e18;
const int INF = 0x3f3f3f3f;

struct tree {
    int key;
    tree* left;
    tree* right;
    tree(int key) : key(key), left(nullptr), right(nullptr) {}
};

void insert(tree*& p, int key) {
    if(!p) {
        p = new tree(key);
        return;
    }
    if(p->key < key)
        insert(p->right, key);
    else
        insert(p->left, key);
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

bool find(tree* p, int key) {
    if(p) {
        if(p->key == key) return 1;
        if(p->key < key)
            return find(p->right, key);
        else
            return find(p->left, key);
    } else
        return 0;
}

void print(tree* p) {
    in_order(p);
    cout << '\n';
    pre_order(p);
    cout << '\n';
}

int find_max_in_left(tree* p) {
    if(!p) return 0;
    if(!p->right) return p->key;
    return find_max_in_left(p->right);
}


int find_min_in_right(tree* p) {
    if(!p) return 0;
    if(!p->left) return p->key;
    return find_min_in_right(p->left);
}

void del(tree*& p, int key) {
    if(p) {
        if(p->key == key) {
            if(!p->left && !p->right)
                p = nullptr;
            else if(p->left && !p->right)
                p = p->left;
            else if(p->right && !p->left)
                p = p->right;
            else {
                int val = find_min_in_right(p->right);
                p->key = val;
                del(p->right, val);
            }
        } else if(p->key < key)
            del(p->right, key);
        else
            del(p->left, key);
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
    string s;
    int x;
    tree* root = nullptr;
    while(n--) {
        cin >> s;
        if(s[0] == 'i') {
            cin >> x;
            insert(root, x);
        } else if(s[0] == 'p')
            print(root);
        else if(s[0] == 'd') {
            cin >> x;
            del(root, x);
        } else {
            cin >> x;
            if(find(root, x))
                cout << "yes\n";
            else
                cout << "no\n";
        }
    }

    return 0;
}
