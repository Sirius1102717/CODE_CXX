#include <algorithm>
#include <cmath>
#include <cstring>
#include <deque>
#include <iostream>
#include <queue>
#include <stack>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>
using namespace std;
using ll = long long;
const double EPS = 1e-8;
const ll MAXN = 1e18;
const int INF = 0x3f3f3f3f;
const int N = 25;

int post_arr[N];
int in_arr[N];

struct node {
    int val;
    node* left;
    node* right;
    node(int val) : val(val), left(nullptr), right(nullptr) {}
};

node* rebuild(int n) {
    stack<node*> s;
    int in_idx = n - 1;
    node* root = new node(post_arr[n - 1]);
    s.emplace(root);
    for(int i = n - 2; i >= 0; i--) {
        node* tmp = s.top();
        if(in_arr[in_idx] != tmp->val) {
            tmp->right = new node(post_arr[i]);
            s.emplace(tmp->right);
        } else {
            while(!s.empty() && in_arr[in_idx] == s.top()->val) {
                tmp = s.top();
                s.pop();
                in_idx--;
            }
            tmp->left = new node(post_arr[i]);
            s.emplace(tmp->left);
        }
    }
    return root;
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
        cin >> in_arr[i];
    for(int i = 0; i < n; i++)
        cin >> post_arr[i];
    node* root = rebuild(n);
    queue<node*> q;
    q.emplace(root);
    vector<int> left, right;
    while(!q.empty()) {
        int sz = q.size();
        int first = -1, second = -1;
        for(int i = 0; i < sz; i++) {
            auto tmp = q.front();
            q.pop();
            if(!i) first = tmp->val;
            if(i == sz - 1) second = tmp->val;
            if(tmp->left) q.emplace(tmp->left);
            if(tmp->right) q.emplace(tmp->right);
        }
        left.emplace_back(first);
        right.emplace_back(second);
    }
    cout << "R:";
    for(auto a : right)
        cout << ' ' << a;
    cout << "\nL:";

    for(auto a : left)
        cout << ' ' << a;
    cout << '\n';

    return 0;
}
