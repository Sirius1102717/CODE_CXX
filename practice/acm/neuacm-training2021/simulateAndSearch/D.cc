#include<stdio.h>
#include<algorithm>
using namespace std;
#define ll long long
const int N = 1e4 + 1;
const int M = 1e5 + 1;

int mp[N][N], l[N], r[N], al[N], ar[N];

struct operation
{
    int a, x, y;
}o[M];


int main(int argc, char *argv[])
{
    int t, n, m, q;
    scanf("%d", &t);
    while ( t-- ) {
        scanf("%d%d%d", &n, &m, &q);
        for ( int i = 1; i <= n; i++ ) {
            for ( int j = 1; j <= m; j++ ) {
                scanf("%d", &mp[i][j]);
            }
        }
        for ( int i = 1; i <= n; i++ ) {
            l[i] = i, al[i] = 0;
        }
        for ( int i = 1; i <= m; i++ ) {
            r[i] = i, ar[i] = 0;
        }

        for ( int i = 0; i < q; i++ ) {
            scanf("%d%d%d", &o[i].a, &o[i].x, &o[i].y);
        }
        for ( int i = 0; i < q; i++ ) {
            switch ( o[i].a ) {
            case 1:
                swap(l[o[i].x], l[o[i].y]);
                break;
            case 2:
                swap(r[o[i].x], r[o[i].y]);
                break;
            case 3:
                al[l[o[i].x]] += o[i].y;
                break;
            default:
                ar[r[o[i].x]] += o[i].y;
            }
        }
        for ( int i = 1; i <= n; i++ ) {
            for ( int j = 1; j < m; j++ ) {
                printf("%d ", mp[l[i]][r[j]] + al[l[i]] + ar[r[j]]);
            }
            printf("%d\n", mp[l[i]][r[m]] + al[l[i]] + ar[r[m]]);

        }

    }
    return 0;
}


