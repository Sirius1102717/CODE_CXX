#include<bits/stdc++.h>
using namespace std;
int a[1010];
int main()
{
    int n, r;
    scanf("%d%d", &n, &r);
    int i;
    for ( i = 1; i <= n; i++ ) scanf("%d", &a[i]);
    int ans = 0;
    for ( i = 1; i <= n; i++ ) {
        int x = i + r - 1;
        int j, f = 0, pos;
        for ( j = min(x, n); j >= max(1, i - r + 1); j-- ) {
            if ( a[j] == 1 ) {
                f = 1;
                pos = j;
                break;
            }
        }
        if ( f == 0 ) {
            printf("-1\n");
            goto L1;
        }
        ans++;
        i = pos + r - 1;
        // cout << i << endl;
    }
    printf("%d\n", ans);
L1:
    return 0;
}
