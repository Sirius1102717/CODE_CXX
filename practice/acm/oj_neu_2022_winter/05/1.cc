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

string append[4] = { "dream", "dreamer", "erase", "eraser" };

bool dfs(string s, string t) {
    if(t > s || t.size() > s.size()) return 0;
    if(s == t) return 1;
    return dfs(s, t + append[0]) || dfs(s, t + append[1]) || dfs(s, t + append[2]) || dfs(s, t + append[3]);
}

queue<string> q;

bool bfs(string s) {
    q.emplace("");
    while(!q.empty()) {
        string f = q.front();
        if(f == s) return 1;
        q.pop();
        for(int i = 0; i < 4; i++) {
            string tmp = f + append[i];
            if(tmp.size() <= s.size() && tmp <= s) q.emplace(tmp);
        }
    }
    return 0;
}

string dp;

bool f(string s) {
    int r = s.size() - 1;
    while(r >= 0) {
        if(s[r] == 'm') {
            if(r - 4 < 0 || s.substr(r - 4, 5) != "dream") return 0;
            r -= 5;
        } else if(s[r] == 'e') {
            if(r - 4 < 0 || s.substr(r - 4, 5) != "erase") return 0;
            r -= 5;
        } else if(s[r] == 'r') {
            if(r - 5 >= 0 && s.substr(r - 5, 6) == "eraser") {
                r -= 6;
            } else if(r - 6 >= 0 && s.substr(r - 6, 7) == "dreamer") {
                r -= 7;
            } else {
                return 0;
            }
        } else {
            return 0;
        }
    }
    return r == -1;
}

int main(int argc, char* argv[]) {
    freopen("/home/freaver/CODE_C/practice/input.txt", "r", stdin);
    freopen("/home/freaver/CODE_C/practice/output.txt", "w", stdout);
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> s;
    if(f(s))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}
