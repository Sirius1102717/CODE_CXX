#include <algorithm>
#include <cctype>
#include <complex>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iostream>
#include <memory>
#include <queue>
#include <stack>
#include <string>
#include <vector>
using namespace std;
using ll = long long;
const double EPS = 1e-8;
const ll MAXN = 1e18;
const int INF = 0x3f3f3f3f;

typedef complex<int> ci;

int get_int(string s, int& i) {
    int ret = 0;
    while(s[i]) {
        if(isdigit(s[i])) {
            ret *= 10;
            ret += s[i] - '0';
        } else {
            break;
        }
        i++;
    }
    i--;
    return ret;
}

void trans(string s, deque<ci>& num, deque<char>& oper) {

    stack<char> signal;
    int i = 0;

    while(s[i]) {
        char c = s[i];
        if(c == '(') {
            signal.push(c);
        } else if(c == '-' || c == '+') {
            while(!signal.empty()) {
                char e = signal.top();
                if(e == '-' || e == '+') {
                    oper.push_back(e);
                    signal.pop();
                } else {
                    break;
                }
            }
            signal.push(c);
        } else if(c == '*') {
            while(!signal.empty()) {
                char e = signal.top();
                signal.pop();
                if(e == '*') {
                    oper.push_back(e);
                } else {
                    break;
                }
            }
            signal.push(c);
        } else if(c == ')') {
            while(signal.top() != '(') {
                oper.push_back(signal.top());
                signal.pop();
            }
            signal.pop();
        } else if(s[i] >= '0' && s[i] <= '9') {
            int tnum = get_int(s, i);
            if(s[i + 2] == 'i' && s[i + 1] == '*') {
                ci c = ci(0, tnum);
                num.push_back(c);
                i += 2;
            } else {
                ci c = ci(tnum, 0);
                num.push_back(c);
            }
        }
        i++;
    }
    while(!signal.empty()) {
        oper.push_back(signal.top());
        signal.pop();
    }
}

int main(int argc, char* argv[]) {
    string s;

    while(cin >> s) {
        deque<char> prefix;
        deque<ci> num;
        int i = 0;
        trans(s, num, prefix);

        while(!prefix.empty()) {
            ci l = num.front();
            num.pop_front();
            ci r = num.front();
            num.pop_front();
            char c = prefix.front();
            prefix.pop_front();
            if(c == '+') {
                l += r;
            } else if(c == '-') {
                l -= r;
            } else {
                l *= r;
            }
            num.push_front(l);
        }
        ci ans = num.front();
        int real = ans.real(), img = ans.imag();
        if(abs(real) <= 10000 && abs(img) <= 10000) {
            if(real) {
                cout << real;
            }
            if(img > 1 && real) {
                cout << '+' << img << '*' << 'i';
            } else if(img > 0 && real) {
                cout << '+' << 'i';
            } else if(img > 1) {
                cout << img << 'i';
            } else if(img > 0) {
                cout << 'i';
            } else if(img < -1) {
                cout << img << 'i';
            } else if(img < 0) {
                cout << 'i';
            }
        } else {
            cout << "overflow";
        }
        cout << endl;
    }
    return 0;
}
