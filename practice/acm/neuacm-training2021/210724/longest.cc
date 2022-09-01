#include<bits/stdc++.h>
using namespace std;
#define ll long long


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
        int fast = -1; //防止第一次if时对fslow和ffast进行修改，减少一次修改次数
        int ffast = 0, fslow = 0;
        int ans = 0;
        int res = 0;
        m.clear();
        while ( 1 ) {
            if ( res <= k && fast - slow + 1 > ans ) {
                fslow = slow;
                ffast = fast;
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
                // m[c]--;
                if ( !(--m[c]) ) {
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
