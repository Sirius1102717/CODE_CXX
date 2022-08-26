#include <algorithm>
#include <cstring>
#include <deque>
#include <ios>
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

struct tree {
    int key;
    int priority;
    tree* left;
    tree* right;
    tree(int key, int priority) : key(key), priority(priority), left(nullptr), right(nullptr) {}
};

tree* right_rotate(tree* t) {
    tree* s = t->left;
    t->left = s->right;
    s->right = t;
    return s;
}

tree* left_rotate(tree* t) {
    tree* s = t->right;
    t->right = s->left;
    s->left = t;
    return s;
}

tree* insert(tree* t, int key, int priority) {
    if(!t) { return new tree(key, priority); }
    if(t->key == key) return t;
    if(key < t->key) {
        t->left = insert(t->left, key, priority);
        if(t->priority < t->left->priority) t = right_rotate(t);
    } else {
        t->right = insert(t->right, key, priority);
        if(t->priority < t->right->priority) t = left_rotate(t);
    }
    return t;
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

tree* __delete(tree* t, int key);

tree* del(tree* t, int key) {
    if(!t) return nullptr;
    if(key < t->key)
        t->left = del(t->left, key);
    else if(key > t->key)
        t->right = del(t->right, key);
    else
        return __delete(t, key);
    return t;
}

tree* __delete(tree* t, int key) {
    if(!t->left && !t->right)
        return nullptr;
    else if(!t->left)
        t = left_rotate(t);
    else if(!t->right)
        t = right_rotate(t);
    else {
        if(t->left->priority > t->right->priority)
            t = right_rotate(t);
        else
            t = left_rotate(t);
    }
    // return __delete(t, key);
    return del(t, key);
}

int main(int argc, char* argv[]) {
    freopen("/home/freaver/CODE_C/practice/input.txt", "r", stdin);
    freopen("/home/freaver/CODE_C/practice/output.txt", "w", stdout);
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, key, priority;
    string s;
    cin >> n;
    tree* root = nullptr;
    while(n--) {
        cin >> s;
        if(s[0] == 'i') {
            cin >> key >> priority;
            root = insert(root, key, priority);
        } else if(s[0] == 'p')
            print(root);
        else if(s[0] == 'd') {
            cin >> key;
            root = del(root, key);
        } else {
            cin >> key;
            if(find(root, key))
                cout << "yes\n";
            else
                cout << "no\n";
        }
    }

    return 0;
}
