#include<bits/stdc++.h>
using namespace std;
#define ll long long
const double EPS = 1e-8;

typedef pair<ll, ll> ipair;

int main(int argc, char *argv[])
{
    int n;
    ll lr, rr;
    ll l[26], r[26];
    cin >> n;
    char c[1];
    for ( int i = 0; i < n; i++ ) {
        cin >> c >> lr >> rr;
        l[c[0] - '0'] = lr;
        r[c[0] - '0'] = rr;
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
                si.push(make_pair(l[c - '0'], r[c - '0']));
            }
        }
        if ( flag ) {
            cout << ans << "\n";
        }
    }
    return 0;
}