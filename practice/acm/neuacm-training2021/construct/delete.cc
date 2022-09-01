#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define EPS 1e-8

int sg(int *n, int len, int *f, int lenf)
{
    if ( len > 0 ) {
        // sort(n, n + len);
        for ( int i = 0; i < lenf; i++ ) {
            if ( n[i] != f[i] ) {
                return n[i];
            }
        }
    }
    return len + 1;
}

void getDivisors(int t, int &len, int *judge)
{
    for ( int i = 2; i < t; i++ ) {
        if ( t % i == 0 ) {
            judge[len++] = i;
        }
    }

}

int getSg(int *ans, int len, int t)
{

    int j = 0;
    int toJudge[100];
    for ( int i = 0; i < len; i++ ) {
        if ( t - ans[i] >= 0 ) {
            toJudge[j++] = ans[i];
        }
    }
    return sg(ans, len, toJudge, j);
}

int judge[100];
int main(int argc, char *argv[])
{
    std::ios::sync_with_stdio(false);
    int t;
    int len = 0;
    while ( cin >> t ) {
        int n;
        for ( int k = 0; k < t; k++ ) {
            cin >> n;
            if (n % 2 != 0) {
                    cout << "Bob" << "\n"; 
            } else {
                int res = 0;
                while (n % 2 == 0) {
                    n /= 2;
                    res++;
                }
                if (n > 1) {
                        cout << "Alice" << "\n";
                } else {
                    if (res % 2 == 0) {
                        cout << "Alice" << "\n";
                    } else {
                        cout << "Bob" << "\n";
                    }
                }
            }
            // getDivisors(n, len, judge);

            // for ( int i = 2; i <= n; i++ ) {
            //     res ^= getSg(judge, len, i);
            // }

            // len = 0;
            // if ( res ) {
            //     cout << "Alice" << "\n";
            // } else {
            //     cout << "Bob" << "\n";
            // }
        }

    }
    return 0;
}
