#include<bits/stdc++.h>
using namespace std;
#define ll long long
const double EPS = 1e-8;
const ll MAXN = 1e8;

int getAns(int n)
{
    int res = 0;
    while ( n ) {
        res += n / 5;
        n /= 5;
    }
    return res;
}

int main(int argc, char *argv[])
{
    std::ios::sync_with_stdio(false);
    int t;

    cin >> t;
    int c = 0;
    while ( t-- ) {
        int q;
        cin >> q;
        int lower = 1;
        int upper = 500000000;
        int res;
        int mid;
        while ( lower <= upper ) {
            mid = ((upper - lower) >> 1) + lower;
            if ( getAns(mid) < q ) {
                lower = mid + 1;
            } else {
                upper = mid - 1;
            }
        }

        if ( getAns(lower) == q ) {
            printf("Case %d: %d\n", ++c, lower);
        } else {
            printf("Case %d: impossible\n", ++c);
        }
    }
    return 0;
}
