#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const double EPS = 1e-9;
const int N = 1e5 + 1;

double n, p1, p2, v1, v2;


double f(double p, double n, double v)
{
    return min((p + n) / v, (n - p + n) / v);
}

int main(int argc, char *argv[])
{
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    int t;
    scanf("%d", &t);
    while ( t-- ) {
        scanf("%lf%lf%lf%lf%lf", &n, &p1, &v1, &p2, &v2);
        double ans = INT_MAX;
        if ( p1 > p2 ) {
            swap(p1, p2);
            swap(v1, v2);
        }
        ans = min(f(p1, n, v1), ans);
        ans = min(f(p2, n, v2), ans);
        ans = min(ans, max((n - p1) / v1, p2 / v2));
        double l = p1, r = p2;
        for ( int i = 1; i <= 100; i++ ) {
            double mid = (l + r) / 2;
            double t1 = f(p1, mid, v1);
            double t2 = f(n - p2, n - mid, v2);
            ans = min(ans, max(t1, t2));
            if ( t1 < t2 ) {
                l = mid;
            } else {
                r = mid;
            }
        }

        printf("%.10f\n", ans);

    }

    return 0;
}
