#include <algorithm>
#include <cctype>
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

// bool vis[128];
int num[128];
int nonum[128];

bool cal(string s) {
    // cout << s << '\n';
    memset(num, 0, sizeof num);
    memset(nonum, 0, sizeof nonum);

    char pre;
    int flag;
    for(int i = 0; i < s.size(); i++) {
        char c = s[i];
        if(isalpha(c)) {
            if(i && s[i - 1] == '~')
                num[c]++;
            else
                nonum[c]++;
        }
    }
    for(int i = 0; i < 128; i++) {
        if (num[i] && nonum[i]) return 0;
    }
    return 1;
}

int main(int argc, char* argv[]) {
    freopen("/home/freaver/CODE_C/practice/input.txt", "r", stdin);
    freopen("/home/freaver/CODE_C/practice/output.txt", "w", stdout);
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    while(cin >> s) {
        if(s[0] == '#') break;
        int l;
        bool flag = 0;
        for(int i = 0; i < s.size(); i++) {
            char c = s[i];
            if(c == '(')
                l = i + 1;
            else if(c == ')')
                flag |= cal(s.substr(l, i - l));
        }
        if(flag)
            cout << "yes\n";
        else
            cout << "no\n";
    }
    return 0;
}
