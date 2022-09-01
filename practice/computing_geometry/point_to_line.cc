#include <cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<vector>
#include<algorithm>
#include<deque>
#include<queue>
#include<stack>
#include<cmath>
using namespace std;
using ll = long long;
const double EPS = 1e-8;
const ll MAXN = 1e18;
const int INF = 0x3f3f3f3f;

struct point {
    double x, y;
    friend point operator-(point p1, point p2) {
        point p = point(p1);
        p.x -= p2.x, p.y -= p2.y;
        return p;
    }

    friend point operator+(point p1, point p2) {
        point p = point(p1);
        p.x += p2.x, p.y += p2.y;
        return p;
    }


    friend point operator*(point p, double d) {
        p.x *= d, p.y *= d;
        return p;
    }

    point(int xx, int yy): x(xx), y(yy) {}
};

double dot(point x, point y) {
    return x.x * y.x + x.y * y.y;
}



int main(int argc, char *argv[]) {  
    freopen("/home/freaver/CODE_C/practice/input.txt", "r", stdin);
    freopen("/home/freaver/CODE_C/practice/output.txt", "w", stdout);
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int x1, x2, y1, y2, x, y;
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    point a(x1, y1), b(x2, y2);
    int q;
    scanf("%d", &q);
    while(q--) {
        scanf("%d%d", &x, &y);
        point p(x ,y);
        point v = b - a, u = p - a;
        point tmp = a + v * (dot(v, u) / dot(v, v));
        point ans = tmp * 2 - p;
        printf("%.10lf %.10lf\n", ans.x, ans.y);
    }

    return 0;
}
