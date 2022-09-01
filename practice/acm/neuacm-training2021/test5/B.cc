#include<bits/stdc++.h>
using namespace std;
#define ll long long
const double EPS = 1e-8;

typedef struct
{
    ll c;
    ll r;
}M;
M m[26] = { 0 };

typedef pair<ll, ll> ipair;

map<char, int> mp;

int main(int argc, char *argv[])
{
    int n;
    ll lr, rr;
    cin >> n;
    char c[1];
    for ( int i = 0; i < n; i++ ) {
        cin >> c >> lr >> rr;
        mp[c[0]] = i;
        m[i].c = lr;
        m[i].r = rr;
    }
    string ex;
    while ( cin >> ex ) {
        ll ans = 0;
        stack<ipair> si;
        int len = ex.size();
        bool flag = 1;
        if ( len == 1 ) {
            cout << "0\n";
            flag = 0;
        }
        for ( int i = 0; i < len; i++ ) {
            char c = ex[i];
            if ( c == '(' ) {
                continue;
            }
            if ( c == ')' ) {
                ipair r = si.top();
                si.pop();
                ipair l = si.top();
                si.pop();
                if ( l.second != r.first ) {
                    cout << "error\n";
                    flag = 0;
                    break;
                } else {
                    ans += l.first * l.second * r.second;
                    l.second = r.second;
                    si.push(l);
                }

            } else {
                si.push(make_pair(m[mp[c]].c, m[mp[c]].r));
            }
        }
        if ( flag ) {
            cout << ans << "\n";
        }
    }
    return 0;
}
