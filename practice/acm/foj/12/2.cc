#include <algorithm>
#include <cstring>
#include <deque>
#include <fstream>
#include <iostream>
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

using ump = unordered_map<string, int>;

ump mp;

void add(string l, string r, int& num) {
    string j = l + r;
    mp[j]++;
    if(mp[j] == 1) {
        num++;
    }
}

void add_all(string l, string r, int& num) {
    add(l, r, num);
    reverse(l.begin(), l.end());
    add(l, r, num);
    reverse(r.begin(), r.end());
    add(l, r, num);
    reverse(l.begin(), l.end());
    add(l, r, num);
}

int main(int argc, char* argv[]) {
    freopen("/home/freaver/CODE_C/input.txt", "r", stdin);
    freopen("/home/freaver/CODE_C/output.txt", "w", stdout);
    int m;
    while(cin >> m) {
        while(m--) {
            mp.clear();
            string s;
            cin >> s;
            int num = 0;
            int len = s.size() - 1;
            for(int i = 0; i < len; i++) {

                string l = s.substr(0, i + 1);
                string r = s.substr(i + 1);
                add_all(l, r, num);
                r = s.substr(0, i + 1);
                l = s.substr(i + 1);
                add_all(l, r, num);
            }
            cout << num << endl;
        }
    }

    return 0;
}
