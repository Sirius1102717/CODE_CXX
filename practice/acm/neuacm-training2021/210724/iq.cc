#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define EPS 1e-8

int main(int argc, char *argv[])
{
    std::ios::sync_with_stdio(false);
    double a1, a2, a3, a4;
    while ( cin >> a1 >> a2 >> a3 >> a4 ) {
        if ( abs(a2 * 2 - a1 - a3) < EPS && abs(a3 * 2 - a4 - a2) < EPS ) {
            cout << int(a4 + a4 - a3) << "\n";
        } else {
            if ( abs (a1 - 0) < EPS) {
                cout << 42 << "\n";
            } else {
                double q = a2 / a1;
                if ( abs(q - a3 / a2) < EPS && abs(q - a4 / a3) < EPS  && q != 0 && q != 1) {
                    int ans = (int)a4 * q;
                    if ( ans > 0  && abs (ans * a2 - a3 * a4) < EPS) {
                        cout << ans << "\n";
                    } else {
                        cout << 42 << "\n";
                    }
                } else {
                    cout << 42 << "\n";
                }
            }
        }
    }

    return 0;
}
