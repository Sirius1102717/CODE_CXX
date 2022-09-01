#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const double EPS = 1e-8;
const ll MAXN = 1e18;

bool judge(string s, int len)
{
    for (int i = 0; i < len; i++) {
        if (s[i] != s[i + len]) {
            return false;
        }
    }

    return true;

}


int main(int argc, char *argv[])
{
    std::ios::sync_with_stdio(false);
    string s;
label:
    while ( cin >> s ) {
        int len = s.size();
        len--;
        len /= 2;
        for ( int i = len; i > 0; i-- ) {
            if ( judge(s, i) ) {
                cout << i * 2 << "\n";
                goto label;
            }
        }
        cout << 1 << "\n";

    }

    return 0;
}
