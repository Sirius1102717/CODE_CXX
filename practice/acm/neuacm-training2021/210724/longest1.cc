#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD = 1000000007;
const double EPS = 1e-8;


map<char, int> m;
int main(int argc, char *argv[])
{
    std::ios::sync_with_stdio(false);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int k;
    string s;
    while ( cin >> k >> s ) {
        int len = s.size();
        int slow = 0;
        int fast = -1;
        int ffast;
        int fslow;
        int res = 0;
        int ans = 0;
        m.clear();
        while ( 1 ) {
            if ( res <= k && fast - slow + 1 > ans ) {
                ffast = fast;
                fslow = slow;
                ans = fast - slow + 1;
            }
            if ( res <= k ) {
                if ( fast == len - 1 ) {
                    break;
                }
                char c = s[++fast];
                if ( !m[c]++ ) {
                    res++;
                }
                // m[c]++;
            } else {
                char c = s[slow++];
                if ( !--m[c] ) {
                    res--;
                }
                if ( slow == len ) {
                    break;
                }
            }
        }
        cout << fslow + 1 << " " << ffast + 1 << "\n";
    }
    return 0;
}
