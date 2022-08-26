#include<bits/stdc++.h>
using namespace std;
#define ll long long
const double EPS = 1e-8;
const ll MAXN = 1e18;
typedef pair<int, int> PAIR;


void f(string s, int &sn, int &hn)
{
    // mh[i] = 0;
    int len = s.length();
    for ( int j = 0; j < len; j++ ) {
        if ( s[j] == 's' ) {
            sn++;
        } else {
            hn++;
            // res += sn;
        }
    }
}

ll cal(string s)
{
    int len = s.size();
    int sn = 0;
    ll res = 0;
    for ( int i = 0; i < len; i++ ) {
        if ( s[i] == 's' ) {
            sn++;
        } else {
            res += sn;
        }

    }
    return res;
}

struct comparable
{
    bool operator()(string s1, string s2)
    {
        // !int sn1 = 0;
        // int sn2 = 0;
        // int hn1 = 0;
        // int hn2 = 0;
        // f(s1, sn1, hn1);
        // f(s2, sn2, hn2);
        // return hn1 >= hn2 && sn1 <= sn2;
        return cal(s1 + s2) < cal(s2 + s1);
    }
};



int main(int argc, char *argv[])
{
    std::ios::sync_with_stdio(false);
    int n;

    while ( cin >> n ) {
        // vector<string> strings;
        // map<int, int> ms;
        // map<int, int> mh;
        vector<string> vs;
        ll res = 0;
        for ( int i = 0; i < n; i++ ) {
            string s;
            cin >> s;
            // strings.emplace_back(s);
            vs.emplace_back(s);
            // mh[i] = 0;
            // ms[sn] = i;
            // vs.emplace_back(sn, hn);
            // mh[hn] = i;
        }
        sort(vs.begin(), vs.end(), comparable());

        int sn = 0;
        for ( int i = n - 1; i >= 0; i-- ) {
            string s = vs[i];
            int len = s.size();
            for ( int j = 0; j < len; j++ ) {
                if ( s[j] == 's' ) {
                    sn++;
                } else {
                    res += sn;
                }
            }
        }
        cout << res << "\n";
        // auto ih = mh.begin();
    }
    return 0;
}
