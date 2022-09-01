#include <algorithm>
#include <cstring>
#include <deque>
#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;
using ll = long long;
const double EPS = 1e-8;
const ll MAXN = 1e18;
const int INF = 0x3f3f3f3f;
int main(int argc, char* argv[])
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s;
    while (getline(cin, s), s[0] != '.') {
        stack<char> ss;
        bool flag = 0;
        int len = s.size();
        for (int i = 0; i < len; i++) {
            char c = s[i];
            if (c == '(' || c == '[' ) {
                ss.push(c);
                flag = 1;
            } else if (c == ')') {
                if (ss.empty() || ss.top() != '(') {
                    flag = 1;
                    break;
                } else {
                    ss.pop();
                    flag = 0;
                }
            } else if (c == ']') {
                if (ss.empty() || ss.top() != '[') {
                    flag = 1;
                    break;
                } else {
                    ss.pop();
                    flag = 0;
                }
            }
        }
        if (flag || ss.size()) {
            cout << "no\n";
        } else {
            cout << "yes\n";
        }
    }
    return 0;
}
