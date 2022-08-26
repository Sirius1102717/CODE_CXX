#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 1e8
#define EPS 1e-8


int isPrime[1001] = { 0 };
int isPrime1[1001] = { 0 };

int prime[100] = { 0 };

void EraPrime()
{
    isPrime1[1] = 1;
    for ( int i = 2; i < 1001; i++ ) {
        if ( !isPrime1[i] ) {
            for ( int j = 2; i * j < 1001; j++ ) {
                isPrime1[i * j] = 1;
            }
        }
    }
}

void EulerPrime()
{
    isPrime[1] = 1;
    int m = 0;
    for ( int i = 2; i < 1001; i++ ) {
        if ( !isPrime[i] ) {
            prime[m++] = i;
        }
        for ( int j = 0; j < m; j++ ) {
            if ( i * prime[j] > 1001 || !i % prime[j] ) {
                break;
            } else {
                isPrime[prime[j] * i] = 1;
            }
        }
    }
}

int main(int argc, char *argv[])
{
    // memset(isPrime, 1, sizeof(isPrime) * 1001);
    std::ios::sync_with_stdio(false);
    int n;

    // EraPrime();
    // EulerPrime();

    // for (int i = 0; i < 100; i++) {
    //     cout << prime[i] << " ";
    // }

    // for ( int i = 1; i < 1001; i++ ) {
    //     cout << isPrime[i] << "\n";
    // }
label:
    while ( cin >> n ) {
        // int judge = (pow(MAXN, 1.0 / 3.0));
        int judge1 = MAXN - 1;
        if ( n == 1 ) {
            cout << -1 << "\n";
            goto label;

        }
        // if (!isPrime[n]) {

        // }
    label1:
        // for ( double i = 1; i < 100000; i++ ) {
        //     for ( double j = i + 1; j < 100000; j++ ) {
        //         double k = (n * i * j) / (2 * i * j - n * (i + j));
        //         int k1 = (n * i * j) / (2 * i * j - n * (i + j));
        //         if ( abs(k1 - k) < EPS  && k1 > 0 && k1 != i && k1 != j) {
        //             cout << (int)i << " " << (int)j << " " << k1 << "\n";
        //             goto label;
        //         }

        //     }
        // }

        // cout << "-1 " << "\n";
        int x, y, z;
        if ( n % 2 == 0 ) {
            x = n;
            y = n / 2 * 3;
            z = 3 * n;
        } else {
            x = n;
            int temp = MAXN / x;
            for ( y = n + 1; y < temp; x++ ) {
                for ( z = y * n ; z < MAXN; z += y * n ) {
                    if ( z * y == (z + y) * n ) {
                        goto label2;
                    }
                }
            }
        }
    label2:
        // if ( n * (x * y + y * z + x * z) == 2 * x * y * z ) {
        //     cout << "true" << "\n";
        // } else {
        //     cout << "false" << "\n";
        // }
        cout << x << " " << y << " " << z << "\n";


    }
    return 0;
}

