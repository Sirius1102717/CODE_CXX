#include <algorithm>
#include <cctype>
#include <cstdio>
#include <cstring>
#include <deque>
#include <functional>
#include <iostream>
#include <queue>
#include <sstream>
#include <stack>
#include <string>
#include <type_traits>
#include <vector>
using namespace std;
using ll = long long;
const double EPS = 1e-8;
const ll MAXN = 1e18;
const int INF = 0x3f3f3f3f;
const int N = 1e2 + 5;

struct node {
    int key;
    int parent;
    node* left;
    node* right;
    node(int key) : parent(-1), key(key), left(nullptr), right(nullptr) {}
};

void build(node*& p, int x) {
    if(!p) {
        p = new node(x);
        return;
    }
    if(x < p->key)
        build(p->left, x);
    else
        build(p->right, x);
}

int parent[N];
int d[N];

int main(int argc, char* argv[]) {
    freopen("/home/freaver/CODE_C/practice/input.txt", "r", stdin);
    freopen("/home/freaver/CODE_C/practice/output.txt", "w", stdout);
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, x;
    cin >> n;
    node* root = nullptr;
    string s;
    for(int i = 0; i < n; i++) {
        cin >> x;
        build(root, x);
    }
    int q;
    cin >> q;
    int a, b;
    string o;
    getline(cin, s);
    while(cin >> q) {
        int flag = -1;
        getline(cin, s);
        a = b = -1;
        istringstream is(s);
        while(is >> o) {
            if (isdigit(o[0])){
                if (~a) b = stoi(o);
                else a = stoi(o);
            } else {
                if (o == "root") {
                    flag = 1;
                } else if (o == "siblings") {
                    flag = 2;
                } else if (o == "same") {
                    flag = 3;
                } else if (o == "parent") {
                    flag = 4;
                } else if (o == "left") {
                    flag = 5;
                } else if (o == "right") {
                    flag = 6;
                }
            }
            switch (flag) {
                case 1:
                    if (~parent[a]) cout << "No\n";
                    else cout << "Yes\n";
            }

        }

        
    }

    return 0;
}
