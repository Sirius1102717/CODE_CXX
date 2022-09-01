#include<iostream>
#include<string>
using namespace std;
typedef long long ll;
const int N = 1e6 + 10;

ll Next[N];

void init(string s, int len)
{
    Next[0] = -1;
    int j = 0, k = -1;
    while ( s[j] ) {
        if ( k == -1 || s[j] == s[k] ) {
            j++, k++;
            Next[j] = k;
        } else {
            k = Next[k];
        }
    }
}



int main(int argc, char *argv[])
{
    std::ios::sync_with_stdio(false);
    string s;
    int len;
    cin >> len >> s;
    init(s, len);
    ll ans = 0;
    for ( int i = 1; i <= len; i++ ) {
        while ( Next[i] ) {
            if ( !Next[Next[i]] ) {
                break;
            }
            Next[i] = Next[Next[i]];
        }
        if ( Next[i] ) {
            ans += i - Next[i];
        }
        // ans += Next[i] ? i - Next[i] : 0;
    }
    cout << ans << "\n";


    return 0;
}
