#include<bits/stdc++.h>
using namespace std;
#define ll long long
const double EPS = 1e-8;
const int MAXN = 1e9 + 1;



int main(int argc, char *argv[])
{
    std::ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while ( t-- ) {
        int gcd, lcm;
        cin >> gcd >> lcm;

        int low = gcd;
        int ans = MAXN;
        int mid = lcm / gcd;
        int flag = 0;
        /**
         * !@brief lcm = gcd * p * q;
         *  !      mid = lcm / gcd;
         *   !     所以我们只需要确保pq互质并且mid能够整除p就行
         *
         */
        for ( int a = 1; a <= mid / a; a++ ) {
            if ( mid % a == 0 && __gcd(a, mid / a) == 1 ) {
                ans = min(ans, a + mid / a);

            }
        }
        cout << ans * gcd << "\n";
    }

    return 0;
}

