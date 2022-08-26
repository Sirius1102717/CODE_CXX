#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define EPS 1e-8

int main(int argc, char *argv[])
{
    std::ios::sync_with_stdio(false);
    // for ( int i = 2; i < 10; i++ ) {
    //     cout << 162 / i;
    //     cout << "\n";
    // }
    double n;
    while ( cin >> n ) {
        while ( n > 18 ) {
            n /= 18;
        }
        if ( n > 9 ) {
            cout << "Ollie wins." << "\n";
        } else {
            cout << "Stan wins." << "\n";
        }
    }
    // cout << 34012226 % 81;
    return 0;
}
