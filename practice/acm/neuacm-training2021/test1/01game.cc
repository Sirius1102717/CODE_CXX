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
            string s;
            cin >> s;
            int len = s.size();
            int n0 = 0;
            int n1 = 0;
            for ( int i = 0; i < len; i++ ) {
                if ( s[i] == '0' ) {
                    n0++;
                } else {
                    n1++;
                }
            }
            int mmin = min(n0, n1);
            if ( mmin == 0 || mmin % 2 == 0 ) {
                cout << "NET" << "\n";
            } else {
                cout << "DA" << "\n";
            }
        }
    }
    return 0;
}
