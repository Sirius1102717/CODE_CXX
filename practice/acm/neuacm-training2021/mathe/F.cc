#include<bits/stdc++.h>
using namespace std;
#define ll long long
const double EPS = 1e-8;
const int MAXN = 1e7;



vector<ll> prime;
bool isPrime[MAXN + 1] = { 0 };

void EulerPrime()
{
    isPrime[1] = 1;
    int m = 0;
    for ( int i = 2; i <= MAXN; i++ ) {
        if ( !isPrime[i] ) {
            prime.emplace_back(i);
            m++;
        }
        for ( int j = 0; j < m; j++ ) {
            if ( prime[j] * i > MAXN || !i % prime[j] ) {
                break;
            } else {
                isPrime[prime[j] * i] = 1;
            }
        }
    }
}

void getN(ll n, ll &ans)
{
    int len = prime.size();
    int temp = n / 2;
    for ( int i = 0; i < len; i++ ) {
        if ( prime[i] > temp ) {
            break;
        }
        if ( !isPrime[n - prime[i]] ) {
            ans++;
        } 
    }
}
int main(int argc, char *argv[])
{
    std::ios::sync_with_stdio(false);
    ll t;
    EulerPrime();
    while ( cin >> t ) {
        ll n;
        for ( int i = 1; i <= t; i++ ) {
            cin >> n;
            ll ans = 0;
            getN(n, ans);
            cout << "Case " << i << ": " << ans << "\n";
        }
    }
    return 0;
}
