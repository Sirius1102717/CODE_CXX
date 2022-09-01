#include<bits/stdc++.h>
using namespace std;
#define ll long long
const double EPS = 1e-8;
const ll MAXN = 1e18;

struct comparable
{
    bool operator() (int a, int b)
    {
        return __gcd(a, b) + b - __gcd(b, a) - a;
    }
};

vector<int> v;
int main(int argc, char *argv[])
{
    std::ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while ( t-- ) {
        int n;
        cin >> n;
        for ( int i = 0; i < n; i++ ) {
            int in;
            cin >> in;
            v.emplace_back(in);
        }
        sort(v.begin(), v.end(), comparable());
        int ans = 0;
    }
    return 0;
}
