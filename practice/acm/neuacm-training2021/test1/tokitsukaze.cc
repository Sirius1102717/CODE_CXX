#include<bits/stdc++.h>
using namespace std;
#define ll long long
const double EPS = 1e-8;
const ll MAXN = 1e18;
int main(int argc, char *argv[])
{
    std::ios::sync_with_stdio(false);
    int n;
    while ( cin >> n ) {
        int res = 0;
        int in[n];
        int judge = 0;
        int flag = 1;
        int num0 = 0;
        for ( int i = 0; i < n; i++ ) {
            cin >> in[i];
            res += in[i];
            res -= i;
            if ( in[i] == 0 ) {
                num0++;
            }
        }
        sort(in, in + n);
        for ( int i = 0; i < n - 1; i++ ) {
            if ( in[i] == in[i + 1] ) {
                if ( in[i] == in[i - 1] + 1 && i != 0 ) {
                    cout << "cslnb" << "\n";
                    flag = 0;
                    break;
                }
                judge++;
            }
        }

        if ( flag ) {
            if ( res % 2 != 0 && judge < 2 && num0 < 2) {
                cout << "sjfnb" << "\n";
            } else {
                cout << "cslnb" << "\n";
            }

        }
    }

    return 0;
}
