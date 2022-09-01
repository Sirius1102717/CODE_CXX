#include<bits/stdc++.h>
using namespace std;
#define ll long long
const double EPS = 1e-8;
const ll MAXN = 1e18;
int main(int argc, char *argv[])
{
    std::ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while ( t-- ) {
        string n;
        cin >> n;
        int len = n.size();
        if ( len == 1 ) {
            cout << n << "\n";
        } else {
            int n9 = 0;
            for ( int i = 0; i < len; i++ ) {
                if ( n[i] == '9' ) {
                    n9++;
                }
            }
            if ( n9 == len || (n9 == len - 1) && n[0] != '9' ) {
                cout << n << "\n";
            } else {
                string ans = "";
                if ( n[0] > '1' ) {
                    ans += (n[0] - 1);
                    for ( int j = 1; j < len; j++ ) {
                        ans += '9';
                    }
                    cout << ans << "\n";
                } else {
                    int i;
                    bool b = true;
                    for ( i = 1; i < len; i++ ) {
                        if ( n[i] != '0' ) {
                            b = false;
                            break;
                        }
                    }
                    if ( b ) {
                        for ( int j = 1; j < len; j++ ) {
                            ans += '9';
                        }
                    } else {
                        bool b = false;
                        for (int j = i + 1; j < len; j++) {
                            if (n[j] != '9') {
                                b = true;
                            }
                        }
                        if (b) {
                            ans += n.substr(0, i);
                            ans += (n[i] - 1);
                            for ( int j = i + 1; j < len; j++ ) {
                                ans += '9';
                            }
                        } else {
                            ans = n;
                        }
                    }
                    cout << ans << "\n";

                }

            }
        }
    }
    return 0;
}
