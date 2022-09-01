#include<bits/stdc++.h>
using namespace std;
const double EPS = 1e-8;
const int MAXN = 1e5 + 5;


vector<int> prime;

int isPrime[MAXN] = { 0 };

void EulerPrime()
{
    int m = 0;
    for ( int i = 1; i < MAXN; i++ ) {
        if ( !isPrime[i] ) {
            prime.emplace_back(i);
            m++;
        }
        for ( int j = 0; j < m; j++ ) {
            if ( prime[j] * i > MAXN || i % prime[j] == 0 ) {
                break;
            } else {
                isPrime[prime[j] * i] = 1;
            }
        }
    }
}


int main(int argc, char *argv[])
{
    std::ios::sync_with_stdio(false);
    EulerPrime();
    int t;
    cin >> t;
    int c = 0;
    while ( t-- ) {
        int x;
        cin >> x;
        bool flag = false;
        if ( x < 0 ) {
            x = -x;
            flag = true;
        }
        // for(int i = 1; i < )
        int res = 0;
        int len = prime.size();
        for ( int i = 1; i <= len; i++ ) {
            if ( prime[i] * prime[i] > x ) {
                break;
            }
            int temp = 0;
            while ( x % prime[i] == 0 ) {
                x /= prime[i];
                temp++;
            }
            if ( temp ) {
                res = __gcd(res, temp);
            } else {
                res = temp;
            }
        }
        if ( x != 1 ) {
            res = 1;
        }
        if ( flag ) {
            while ( res % 2 == 0) {
                res /= 2;
            }
        }
        printf("Case %d: %d\n", ++c, res);

    }
    return 0;
}
