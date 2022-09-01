#include<bits/stdc++.h>
using namespace std;
#define ll long long
const double EPS = 1e-8;
const ll MAXN = 1e18;

int main(int argc, char *argv[])
{
    std::ios::sync_with_stdio(false);
    string s1 = "dream";
    string s2 = "dreamer";
    string s3 = "erase";
    string s4 = "eraser";
    string s;
    while ( cin >> s ) {
        string t = "";
        int len = s.size();
        int i = 0;
        while ( i < len ) {
            // if (i + 5 < len ) {
            if ( s[i] == 'd' ) {
                // if ( i + 7 < len ) {
                if ( i + 6 >= len || (s[i + 7] == 'a' || (s[i + 7] == 'e' && s[i + 5] == 'd')) ) {
                    t += s1;
                    i += 5;
                } else {
                    t += s2;
                    i += 7;
                }
                // t += s1;
            } else if ( s[i] == 'e' ) {
                if ( s[i + 5] != 'r' || i + 4 >= len ) {
                    t += s3;
                    i += 5;
                } else {
                    t += s4;
                    i += 6;
                }
            } else {
                cout << "NO\n";
                return 0;
            }
        }
        bool flag = 0;
        for ( int i = 0; i < t.size(); ++i ) {
            if ( s[i] != t[i] ) {
                flag = 1;
            }
        }
        if ( flag ) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }


    }

    return 0;
}
