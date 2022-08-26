#include <algorithm>
#include <cstring>
#include <deque>
#include <initializer_list>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <vector>
using namespace std;
using ll = long long;
const double EPS = 1e-8;
const ll MAXN = 1e18;
const int INF = 0x3f3f3f3f;

map<char, int> mp;
map<int, char> pm;

void init() {
    mp['A'] = 0, mp['C'] = 1;
    mp['G'] = 2, mp['T'] = 3;
    pm[0] = 'A', pm[1] = 'C';
    pm[2] = 'G', pm[3] = 'T';
}

struct tree {

    tree* next[4];
    bool isWord;
    tree() {
        for(int i = 0; i < 4; i++) {
            next[i] = nullptr;
        }
        isWord = 0;
    }
};

void insert(tree*& p, string s) {
    tree* tmp = p;
    for(int i = 0; i < s.size(); i++) {
        int index = mp[s[i]];
        if(!tmp->next[index]) {
            tmp->next[index] = new tree;
        }
        tmp = tmp->next[index];
    }
    tmp->isWord = 1;
}

bool find(tree* p, string s) {

    for(int i = 0; i < s.size(); i++) {
        if(!p->next[mp[s[i]]])
            return 0;
        p = p->next[mp[s[i]]];
    }
    return p->isWord;
}

int main(int argc, char* argv[]) {
    freopen("/home/freaver/CODE_C/practice/input.txt", "r", stdin);
    freopen("/home/freaver/CODE_C/practice/output.txt", "w", stdout);
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    string o, s;
    cin >> n;
    tree* head = new tree;
    init();
    while(n--) {
        cin >> o >> s;
        if(o[0] == 'i') {
            insert(head, s);
        } else {
            cout << (find(head, s) ? "yes" : "no") << endl;
        }
    }

    return 0;
}
