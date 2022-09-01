#include <algorithm>
#include <cstdio>
#include <cstring>
#include <deque>
#include <iostream>
#include <queue>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
using namespace std;
using ll = long long;
const double EPS = 1e-8;
const ll MAXN = 1e18;
const int INF = 0x3f3f3f3f;

stack<int> ss;
void inline get_int(int& x, int& y) {
    x = ss.top();
    ss.pop();
    y = ss.top();
    ss.pop();
}

int main(int argc, char* argv[]) {
    freopen("/home/freaver/CODE_C/practice/input.txt", "r", stdin);
    freopen("/home/freaver/CODE_C/practice/output.txt", "w", stdout);
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    int l, r;
    while(cin >> s) {
        if(s[0] >= '0' && s[0] <= '9') {
            ss.push(stoi(s));
        } else {
            get_int(r, l);
            if(s[0] == '+') {
                l += r;
            } else if(s[0] == '-') {
                l -= r;
            } else {
                l *= r;
            }
            ss.push(l);
        }
    }
    cout << ss.top() << endl;

    return 0;
}
