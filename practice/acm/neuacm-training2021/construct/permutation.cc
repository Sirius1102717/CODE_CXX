#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define EPS 1e-8

int main(int argc, char *argv[])
{
    std::ios::sync_with_stdio(false);
    int n, k;
    while ( cin >> n >> k ) {
        int len = n * 2;

        // if ( k == 0 ) {
        //     for ( int i = 1; i <= len; i++ ) {
        //         cout << i << " ";
        //     }
        //     cout << "\n";
        // } else {
        //     int temp = n - (k - 1) * 2;
        //     for ( int i = len; i > temp; i-- ) {
        //         cout << i << " ";
        //     }

        //     for ( int i = 1; i <= temp; i++ ) {
        //         cout << i << " ";
        //     }
        //     cout << "\n";
        // }
        int temp = k * 2;
        for (int i = temp; i >= 1; i--) {
            cout << i << " ";
        }
        for (int i = temp + 1; i <= len; i++) {
            cout << i << " ";
        }
        cout << "\n";

    }
    return 0;
}