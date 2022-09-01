#include<bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[])
{
    std::ios::sync_with_stdio(false);
    string s;
    int len = s.length();
    int ans = 0;
    stack<char> names;
    for (int i = 0; i < len; i++) {
        if (s[i] == 'l') {
            names.push(s[i]);
        }
        if (s[i] == 'h' && !names.empty()) {
            names.top() == 'l';
            ans++;
            names.pop();
        }
    }
    cout << ans << "\n";
    return 0;
}
