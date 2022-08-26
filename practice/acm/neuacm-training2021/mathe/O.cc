#include<bits/stdc++.h>
using namespace std;
#define ll long long
const double EPS = 1e-8;
const ll MAXN = 1e18;


int main(int argc, char *argv[])
{
    // std::ios::sync_with_stdio(false);
    int n;
    scanf("%d", &n);
    getchar();
    while ( n-- ) {
        vector<ll> m;
        char str[1001];
        fgets(str, 1001, stdin);
        int strl = strlen(str);
        string temp = "";
        for ( int j = 0; j < strl; j++ ) {
            if ( str[j] >= '0' && str[j] <= '9' ) {
                temp += str[j];
            } else {
                if (!temp.empty()) {
                    m.emplace_back(stoi(temp));
                    temp = "";
                }
            }
        }
        if ( !temp.empty() ) {
            m.emplace_back(stoi(temp));
            // temp = "";
        }

        ll ans = 0;
        int len = m.size();
        for ( int i = 0; i < len; i++ ) {
            for ( int j = i + 1; j < len; j++ ) {
                ans = max(__gcd(m[i], m[j]), ans);
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
