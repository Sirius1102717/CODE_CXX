#include<iostream>
#include<cmath>
using namespace std;
#define ll long long
const double EPS = 1e-8;
const ll MAXN = 1e18;

int main(int argc, char *argv[])
{
    std::ios::sync_with_stdio(false);
    int x, y, m, n, l;
    cin >> x >> y >> m >> n >> l;
    int sub = y - x;
    int step = n - m;
    if ( (sub >= 0 && step >= 0) || (sub < 0 && step < 0) ) {
        if ( (l - sub) % step == 0 ) {
            cout << (l - abs(sub)) / abs(step) << "\n";
        } else {
            cout << "Impossible\n";
        }
    } else {
        if ( abs(sub) % (abs(step) % l) == 0 ) {
            cout << abs(sub) / (abs(step) % l) << "\n";
        } else {
            cout << "Impossible\n";
        }
    }
    return 0;
}
