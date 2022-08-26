#include<bits/stdc++.h>
using namespace std;
#define ll long long
const double EPS = 1e-8;
const ll MAXN = 1e18;


ll qmul(ll a, ll b, ll p)
{
    ll ans = 0;
    a %= p;
    b %= p;
    while ( b ) {
        if ( b & 1 ) {
            ans = (ans + a) % p;
        }
        a <<= 1;
        a %= p;
        b >>= 1;
    }
    return ans;

}

int exgcd(int a, int b, int &x, int &y)
{
    if ( b == 0 ) {
        x = 1;
        y = 0;
        return a;
    }
    int gcd = exgcd(b, a % b, x, y);
    int temp = x;
    x = y;
    y = temp - (a / b) * y;
    return gcd;
}

int cal(int a, int b, int x, int y)
{
    int gcd = exgcd(a, b, x, y);
    if ( 1 != gcd ) {
        return -1;
    }
    a /= gcd;
    b = abs(b);
    int ans = a % b;
    if ( ans < 0 ) {
        ans += b;
    }
    return ans;
}


int main(int argc, char *argv[])
{
    std::ios::sync_with_stdio(false);

    return 0;
}
