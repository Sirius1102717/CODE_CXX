#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define EPS 1e-8


// int gcd(int x, int y)
// {
//     if ( y ) {
//         return gcd(y, x % y);
//     } else {
//         return x;
//     }
// }

int prime[10000] = { 0 };

int isPrime[10000] = { 0 };


// void EraPrime(int len)
// {
//     isPrime[1] = 1;
//     for ( int i = 2; i <= len; i++ ) {
//         if ( !isPrime[i] ) {
//             for ( int j = 2; i * j <= len; j++ ) {
//                 isPrime[i * j] = 1;
//             }
//         }
//     }
// }

// void EulerPrime(int len)
// {
//     int n = 1;
//     for ( int i = 2; i <= len; i++ ) {
//         if ( !isPrime[i] ) {
//             prime[n++] = i;
//         }
//         for ( int j = 1; j < n; j++ ) {
//             if ( i * prime[j] > len || !i % prime[j] ) {
//                 break;
//             } else {
//                 isPrime[i * prime[j]] = 1;
//             }
//         }
//     }
// }

int main(int argc, char *argv[])
{
    std::ios::sync_with_stdio(false);
    // EraPrime(10000);
    // EulerPrime(10000);
    int n, k;
    while ( cin >> n >> k ) {
        cout << (6 * n - 1) * k << "\n";
        for ( int i = 1; i <= n; i++ ) {
            cout << (6 * i - 5) * k << " " << (6 * i - 4) * k << " " << (6 * i - 3) * k << " " << (6 * i - 1) * k << "\n";
        }
    }
    return 0;
}
