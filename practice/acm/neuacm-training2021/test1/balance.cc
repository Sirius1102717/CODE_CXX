#include<bits/stdc++.h>
using namespace std;
#define ll long long
const double EPS = 1e-8;
const ll MAXN = 1e18;

int main(int argc, char *argv[])
{
    std::ios::sync_with_stdio(false);
    int t;
    while ( cin >> t ) {
        for ( int i = 0; i < t; i++ ) {
            int n;
            cin >> n;
            string s;
            cin >> s;
            if ( s[0] == '0' || s[n - 1] == '0') {
                cout << "NO\n";
            } else {
                int n0 = 0;
                string s1 = "(";
                string s2 = "(";
                int temp1 = 1;
                int temp0 = 1;
                for ( int i = 1; i < n - 1; i++ ) {
                    if ( s[i] == '0' ) {
                        if ( temp0 ) {
                            s1 += "(";
                            s2 += ")";
                            temp0 = 0;
                        } else {
                            s1 += ")";
                            s2 += "(";
                            temp0 = 1;
                        }
                        n0++;
                    } else {
                        if ( temp1 ) {
                            s1 += "(";
                            s2 += "(";
                            temp1 = 0;
                        } else {
                            s1 += ")";
                            s2 += ")";
                            temp1 = 1;
                        }
                    }
                }
                if ( n0 % 2 != 0 ) {
                    cout << "NO\n";
                } else {
                    s1 += ")";
                    s2 += ")";
                    cout << "YES\n";
                    cout << s1 << "\n";
                    cout << s2 << "\n";
                }
            }
        }
    }
    return 0;
}


