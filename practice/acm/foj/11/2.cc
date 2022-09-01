#include <algorithm>
#include <cctype>
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

int mcxi2int(string s) {
    int len = s.size();
    int ref = 0;
    int num = 1;
    for(int i = 0; i < len; i++) {
        char c = s[i];
        if(isdigit(c)) {
            num = c - '0';
        } else {
            if(c == 'm') {
                ref += num * 1000;
                num = 1;
            } else if(c == 'c') {
                ref += num * 100;
                num = 1;
            } else if(c == 'x') {
                ref += num * 10;
                num = 1;
            } else if(c == 'i') {
                ref += num;
            }
        }
    }
    return ref;
}

void add(string &ans, char c, int num) {
    if(num) {
        if(num > 1) {
            ans += to_string(num);
        }
        ans += c;
    }
}

string int2mcxi(int num) {
    string ans = "";
    int m = num / 1000;
    add(ans, 'm', m);
    num -= m * 1000;
    int c = num / 100;
    num -= c * 100;
    add(ans, 'c', c);
    int x = num / 10;
    num -= x * 10;
    add(ans, 'x', x);
    add(ans, 'i', num);
    return ans;
}

int main(int argc, char* argv[]) {
    freopen("/home/freaver/CODE_C/input.txt", "r", stdin);
    freopen("/home/freaver/CODE_C/output.txt", "w", stdout);
    int n;
    string l, r;
    int ln, lr;
    cin >> n;
    while(n--) {
        cin >> l >> r;
        ln = mcxi2int(l), lr = mcxi2int(r);
        ln += lr;
        cout << int2mcxi(ln) << endl;
    }

    return 0;
}
