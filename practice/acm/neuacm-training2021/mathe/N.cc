#include<bits/stdc++.h>
using namespace std;
#define ll long long
const double EPS = 1e-8;
const ll MAXN = 1e8;

// ll prime[16000] = { 0 };
// vector<ll> prime;
int isPrime[16001] = { 0 };

// vector<bool> is;

const ll leng = 16000;

// void EulerPrime()
// {
//     int m = 0;
//     isPrime[1] = 1;
//     for ( int i = 2; i <= leng; i++ ) {
//         if ( !isPrime[i] ) {
//             // prime[m++] = i;
//             prime.emplace_back(i);
//             m++;
//         }
//         for ( int j = 0; j < m; j++ ) {
//             if ( prime[j] * i > leng || !i % prime[j] ) {
//                 break;
//             } else {
//                 isPrime[prime[j] * i] = 1;
//                 // is.insert(false, prime[j] * i );
//             }
//         }
//     }
//     isPrime[2] = 1;
// }

// void EraPrime()
// {
//     isPrime[1] = 1;
//     for ( int i = 2; i < 16001; i++ ) {
//         if ( !isPrime[i] ) {
//             for ( int j = 2; i * j < 16001; j++ ) {
//                 isPrime[i * j] = 1;
//             }
//         }
//     }
//     isPrime[2] = 1;
// }

int main(int argc, char *argv[])
{
    std::ios::sync_with_stdio(false);
    // EraPrime();
    int in[250];
    int n = 0;
    int temp;
    int res = 0;
    while ( cin >> temp ) {
        if ( temp > 0 ) {
            if ( temp == 1 || temp == 2 ) {
                cout << ++res << ": no\n";
            } else {
                int flag = 1;
                for ( int i = 2; i <= (int)sqrt(temp); i++ ) {
                    if ( temp % i == 0 ) {
                        cout << ++res << ": no\n";
                        flag = 0;
                        break;
                    }
                }
                if ( flag ) {
                    cout << ++res << ": yes\n";
                }
            }
        } else {
            break;
        }
    }


    return 0;
}
