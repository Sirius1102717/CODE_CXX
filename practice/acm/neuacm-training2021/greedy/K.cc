#include<bits/stdc++.h>
using namespace std;
#define ll long long
const double EPS = 1e-8;
const ll MAXN = 1e18;

int p[26] = { 0 };

bool find(char c)
{
    int n = c - 'a';
    for ( int i = 0; i < n; i++ ) {
        if ( p[i] ) {
            return true;
        }
    }
    return false;
}

int main(int argc, char *argv[])
{
    std::ios::sync_with_stdio(false);
    stack<char> t;
    string s;
    cin >> s;
    string u = "";
    int len = s.size();
    for ( int i = 0; i < len; i++ ) {
        p[s[i] - 'a']++;
    }
    t.emplace(s[0]);
    p[s[0] - 'a']--;
    for ( int i = 1; i < len; i++ ) {
        while ( !t.empty() && !find(t.top()) ) {
            u += t.top();
            t.pop();
        }
        t.emplace(s[i]);
        p[s[i] - 'a']--;
    }
    while (!t.empty()) {
        u += t.top();
        t.pop();
    }
    cout << u << "\n";
    return 0;
}
