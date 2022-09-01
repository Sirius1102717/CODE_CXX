#include <algorithm>
#include <cstring>
#include <deque>
#include <iostream>
#include <iterator>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
using ll = long long;
const double EPS = 1e-8;
const ll MAXN = 1e18;
const int INF = 0x3f3f3f3f;

struct trie {
    bool flag = 0;
    trie *next[26];
};

void build(trie*& head, string s) {

    trie* p = head;
    for(int i = 0; i < s.size(); i++) {
        int c = s[i] - 'a';
        if(!p->next[c]) {
            p->next[c] = new trie;
        }
        p = p->next[c];
    }
}

int find(string s, trie*& head) {
    // bool flag = 1;
    trie* p = head;
    for(int i = 0; i < s.size(); i++) {
        int c = s[i] - 'a';
        if(!p->next[c]) {
            return 0;
        }
        p = p->next[c];
    }
    if(p->flag) {
        return 1;
    } else {
        p->flag = 1;
        return 2;
    }
}
int main(int argc, char* argv[]) {
    freopen("/home/freaver/CODE_C/input.txt", "r", stdin);
    freopen("/home/freaver/CODE_C/output.txt", "w", stdout);
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    string s;
    trie* head = new trie;
    while(n--) {
        cin >> s;
        build(head, s);
    }
    int m;
    cin >> m;
    while(m--) {
        cin >> s;
        int ans = find(s, head);
        if(ans == 2) {
            cout << "OK\n";
        } else if(ans == 1) {
            cout << "REPEAT\n";
        } else {
            cout << "WRONG\n";
        }
    }

    return 0;
}
