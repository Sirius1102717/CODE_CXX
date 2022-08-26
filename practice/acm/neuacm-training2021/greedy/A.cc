#include<bits/stdc++.h>
using namespace std;
#define ll long long
const double EPS = 1e-8;
const ll MAXN = 1e18;

stack<char> brackets;

int main(int argc, char *argv[])
{
    std::ios::sync_with_stdio(false);
    int len;
    cin >> len;
    string s;
    cin >> s;
    if ( len & 1 || s[0] == ')' || s[len - 1] == '(' ) {
        cout << ":(" << "\n";
        return 0;
    } else {
        string ans = "(";
        int numl = 0;
        int numr = 0;
        for ( int i = 0; i < len; i++ ) {
            char c = s[i];
            if ( c == '(' ) {
                numl++;
            } else if ( c == ')' ) {
                numr++;
            }
        }
        numl = len / 2 - numl;
        numr = len / 2 - numr;
        if ( numl < 0 || numr < 0 ) {
            cout << ":(" << "\n";
            return 0;
        } else {
            for ( int i = 0; i < len; i++ ) {
                if ( s[i] == '?' && numl ) {
                    s[i] = '(';
                    numl--;
                } else if ( s[i] == '?' && numr ) {
                    s[i] = ')';
                    numr--;
                }
            }
            for ( int i = 0; i < len; i++ ) {
                char c = s[i];
                if ( c == '(' ) {
                    brackets.emplace(c);
                } else {
                    if ( !brackets.empty() ) {
                        brackets.pop();
                        if ( brackets.empty() && i < len - 1 ) {
                            cout << ":(" << "\n";
                            return 0;
                        }
                    }
                }
            }
            cout << s << "\n";
        }
    }
    return 0;

}
