#include<bits/stdc++.h>
using namespace std;
const double EPS = 1e-8;



int main(int argc, char *argv[])
{
    // std::ios::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);
    string s;
    int res = 1;
    while ( cin >> s, s[0] != '-' ) {
        stack<char> brackets;
        int len = s.size();
        for ( int i = 0; i < len; i++ ) {
            char c = s[i];
            if ( brackets.empty() || c == '{' ) {
                brackets.push(c);
            } else {
                if ( brackets.top() == '{' ) {
                    brackets.pop();
                } else {
                    brackets.push(c);
                }
            }
        }
        int l = 1;
        int r = 1;
        while ( !brackets.empty() ) {
            if ( brackets.top() == '{' ) {
                l++;
            } else {
                r++;
            }
            brackets.pop();
        }
        cout << res++ << ". " << l / 2 + r / 2 << "\n";
    }

    return 0;
}
