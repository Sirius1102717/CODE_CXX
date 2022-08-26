#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const double EPS = 1e-8;
const int N = 1e5 + 1;

int a[N], up[N], down[N];

int main(int argc, char *argv[])
{
    int n, m, k;
    while ( cin >> n >> m >> k ) {
        int ul = 0, ur = 0, dl = 0, dr = 0;
        int  ans = 0, temp = 0, j;
        for ( int i = 0; i < n; i++ ) {
            cin >> a[i];
            while ( ul < ur && a[up[ur - 1]] <= a[i] ) {
                ur--;
            }
            while ( dl < dr && a[down[dr - 1]] >= a[i] ) {
                dr--;
            }
            while ( dl < dr && ul < ur && a[down[dr - 1]] - a[up[ur - 1]] > k || a[down[dr - 1]] - a[up[ur - 1]] < m ) {
                dl++;
                ul++;
                ans = max(temp, ans);
                temp--;
            }
            up[ur++] = i;
            down[dr++] = i;
            temp++;
        }
        ans = max(ans, temp);
        cout << ans << "\n";
    }
    return 0;
}
