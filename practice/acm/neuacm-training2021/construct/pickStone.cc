#include<iostream>
using namespace std;
#define ll long long
#define EPS 1e-8
#define MAXN 1024 * 1024 * 1024


ll f[92];
void getF(ll *f)
{
    f[1] = 1;
    f[2] = 1;
    for ( int i = 3; i <= 91; i++ ) {
        f[i] = f[i - 1] + f[i - 2];
    }
}

int main(int argc, char *argv[])
{
    std::ios::sync_with_stdio(false);
    ll n;
    getF(f);
    while ( cin >> n ) {
        if ( n == 0 ) {
            break;
        }
        int flag = 0;
        for ( int i = 3; i < 91; i++ ) {
            if ( n == f[i] ) {
                flag = 1;
                break;
            } else if ( f[i] > n ) {
                break;
            }
        }
    if ( !flag ) {
        cout << "First win" << "\n";
    } else {
        cout << "Second win" << "\n";
    }
    }

    return 0;
}
