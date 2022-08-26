#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
const double EPS = 1e-8;
#define ull unsigned long long
const int N = 1e6 + 1;
const ull base = 131;

ull Hash1[N];
ull Hash2[N];
ull p[N];

int len1, len2;

vector<ull> n;

int init(string s, ull *Hash)
{
    int r = s.size();
    Hash[0] = 0;
    p[0] = 1;
    for ( int i = 1; i <= r; i++ ) {
        Hash[i] = Hash[i - 1] * base + s[i - 1];
        p[i] = p[i - 1] * base;
    }
    return r;
}

ull getHash(int l, int r, ull *Hash)
{
    return Hash[r] - Hash[l - 1] * p[r - l + 1];
}

bool check(int l)
{
    n.clear();
    for (int i = l; i <= len1; i++) {
        n.push_back(getHash(i + 1 - l, i, Hash1));
    }
    sort(n.begin(), n.end());
    for (int i = l; i <= len2; i++) {
        ull res = getHash(i + 1 - l, i, Hash2);
        if (binary_search(n.begin(), n.end(), res)) {
            return true;
        }
    }
    return false;
}



int main(int argc, char *argv[])
{
    std::ios::sync_with_stdio(false);
    string s1, s2;
    while ( cin >> s1 >> s2 ) {
        len1 = init(s1, Hash1);
        len2 = init(s2, Hash2);
        int l = 1, r = min(len1, len2) + 1, mid, ans = 0;
        while ( l < r ) {
            mid = l + (r - l) / 2;
            if ( check(mid) ) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        cout << ans << "\n";
    }

    return 0;
}
