#include <bits/stdc++.h>
#define Mid ((l + r) / 2)
#define lson (rt << 1)
#define rson (rt << 1 | 1)
using namespace std;
int read()
{
    char c; int num, f = 1;
    while ( c = getchar(), !isdigit(c) ) if ( c == '-' ) f = -1; num = c - '0';
    while ( c = getchar(), isdigit(c) ) num = num * 10 + c - '0';
    return f * num;
}
const int N = 2e5 + 1009;
int n, a[N], b[N], cnt[N];
signed main()
{
    n = read();
    for ( int i = 1; i <= n; i++ ) cnt[a[i] = read()]++;
    for ( int i = 1; i <= n; i++ ) cnt[b[i] = read()]++;
    for ( int i = 1; i < N; i++ ) {
        if ( cnt[i] > n ) {
            printf("No\n");
            return 0;
        }
    }
    reverse(b + 1, b + 1 + n);
    int l = 1;
    for ( int i = 1; i <= n; i++ ) {
        if ( a[i] == b[i] ) {
            while ( l <= n && (a[l] == a[i] || b[l] == a[i]) ) l++;
            //		cout << l << endl;
            if ( l == n + 1 ) {
                printf("No\n");
                return 0;
            }
            swap(b[l], b[i]);
            l++;
        }
    }
    printf("Yes\n");
    for ( int i = 1; i <= n; i++ ) printf("%d ", b[i]);
    printf("\n");
    return 0;
}
