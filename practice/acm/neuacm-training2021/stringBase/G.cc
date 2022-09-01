#include<iostream>
#include<string>
#include<cstring>
using namespace std;



string s[100];
int main(int argc, char *argv[])
{
    std::ios::sync_with_stdio(false);
    int t, n;
    cin >> t;
    string tmp;
    int mins = 0;
    while ( t-- ) {
        cin >> n;
        for ( int i = 0; i < n; i++ ) {
            cin >> s[i];
            mins = s[i].size() < s[mins].size() ? i : mins;
        }
        int ans = 0;
        string key = s[mins];
        int len = key.size();
        bool fg = 0;
        for ( int i = len; i >= 1; i-- ) {
            for ( int j = 0; j + i - 1 < len; j++ ) {
                tmp = key.substr(j, i);
                bool flag = 1;
                for ( int k = 0; k < n; k++ ) {
                    string tmp2 = string(tmp.rbegin(), tmp.rend());
                    size_t n1 = s[k].find(tmp);
                    size_t n2 = s[k].find(tmp2);
                    if ( n1 == string::npos && n2 == string::npos ) {
                        flag = 0;
                        break;
                    }
                }
                if ( flag ) {
                    cout << i << "\n";
                    fg = 1;
                    goto label1;
                }
            }

        }
    label1:
        if ( !fg ) {
            cout << 0 << "\n";
        }

    }
    return 0;
}
