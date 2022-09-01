#include<bits/stdc++.h>
using namespace std;
#define ll long long
const double EPS = 1e-8;
const int MAXN = 10001;
const double r = 0.5772156649;


double res[MAXN] = { 0 };
void init()
{
    for ( int i = 1; i <= MAXN; i++ ) {
        res[i] = 1.0 / i + res[i - 1];
    }
}

int main(int argc, char *argv[])
{
    std::ios::sync_with_stdio(false);
    init();
    int t;
    // for (int i = 0; i < 10; i++) {
    //     cout << res[i +1] << "\n";
    // }
    // init();
    while ( cin >> t ) {
        for ( int i = 1; i <= t; i++ ) {
            int in;
            cin >> in;
            if (in <= MAXN) {
                printf("Case %d: %.8f\n", i, res[in]);
            } else {
                double ans = log(in) + r + 1.0 / (2 * in);
                printf("Case %d: %.8f\n", i, ans);
            }
        }
    }
    return 0;
}