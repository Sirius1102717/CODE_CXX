#include<bits/stdc++.h>
using namespace std;

//计算位置在p点这个人覆盖区间长度为n需要的最短时间
double fun(double p, double n, double v)
{               //先往左走  先往右走
    return min((p + n) / v, (n - p + n) / v);
}

void  solve()
{
    double n, p1, p2, v1, v2;
    scanf("%lf%lf%lf%lf%lf", &n, &p1, &v1, &p2, &v2);
    double ans = 9999999999;

    if ( p1 >= p2 ) {
        swap(p1, p2);
        swap(v1, v2);
    }

    //一个人走完
    ans = min(ans, fun(p1, n, v1));
    ans = min(ans, fun(p2, n, v2));

    //左边那个人走右边去，右边那个人走左边去
    ans = min(ans, max((n - p1) / v1, p2 / v2));

    double l = p1;
    double r = p2;
    for ( int i = 1; i <= 100; i++ ) {
        double mid = (l + r) / 2; //相遇的位置
        double ans1 = fun(p1, mid, v1);//左边那个人需要 的时间
        double ans2 = fun(n - p2, n - mid, v2);//右边那个人需要的时间
        ans = min(ans, max(ans1, ans2));

        if ( ans1 < ans2 ) {//左边的时间短，右边时间长，p往右移动
            l = mid;
        } else
            r = mid;
    }
    printf("%.10f\n", ans);
}

int main()
{
    int t;
    scanf("%d", &t);
    while ( t-- )
        solve();
    return 0;
}

