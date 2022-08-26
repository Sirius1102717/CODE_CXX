#include<bits/stdc++.h>
using namespace std;
#define ll long long
const double EPS = 1e-8;
const ll MAXN = 1e18;


ll cal(string s)
{
    ll ans = 0;
    ll sn = 0;
    ll len = s.size();
    for ( int i = 0; i < len; i++ ) {
        if ( s[i] == 's' ) {
            sn++;
        } else {
            ans += sn;
        }
    }
    return ans;
}

struct comparable
{
    bool operator() (string s1, string s2)
    {
        return cal(s1 + s2) > cal(s2 + s1);
    }
};


vector<string> v;


int main(int argc, char *argv[])
{
    std::ios::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        v.emplace_back(s);
    }
    sort(v.begin(), v.end(), comparable());
    string final = "";
    for ( int i = 0; i < n; i++ ) {
        final += v[i];
    }
    cout << cal(final) << "\n";
    return 0;
}
