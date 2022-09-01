#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define EPS 1e-8

int main(int argc, char *argv[])
{
    std::ios::sync_with_stdio(false);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    string s;
    while ( cin >> s ) {
        stack<char> signal;
        int i = 0;
        int len = s.size();
        int ans = 0;
        while ( i < len ) {
            char c = s[i++];
            if ( c == '1' ) {
                signal.push(c);
            } else {
                if ( !signal.empty() && signal.top() == '1' ) {
                    ans++;
                    signal.pop();
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
