#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <iostream>
#include <cmath>
#include <queue>
#include <stack>
#include <stdexcept>
#include <string>
#include <vector>
using namespace std;
using ll = long long;
const double EPS = 1e-8;
const ll MAXN = 1e18;
const int INF = 0x3f3f3f3f;
const double PI = 3.1415926535897932384626;

struct point {
    double x;
    double y;
    point(double x, double y) : x(x), y(y) {}

    point operator+(point pp) {
        point p(*this);
        p.x += pp.x, p.y += pp.y;
        return p;
    }
    point operator-(point pp) {
        point p(*this);
        p.x -= pp.x, p.y -= pp.y;
        return p;
    }
    point operator*(double d) {
        point p(*this);
        p.x *= d, p.y *= d;
        return p;
    }
    point operator/(double d) {
        point p(*this);
        p.x /= d, p.y /= d;
        return p;
    }
};

double distance(point a, point b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

void koch(int n, point a, point b) {
    if(!n) return;
    point sub = (b - a) / 3;
    point s = sub + a;
    point t = b - sub;
    double th = PI / 3;
    double ux = (t.x - s.x) * cos(th) - (t.y - s.y) * sin(th) + s.x;
    double uy = (t.x - s.x) * sin(th) + (t.y - s.y) * cos(th) + s.y;
    // u.y
    point u(ux, uy);
    koch(n - 1, a, s);
    printf("%.8lf %.8lf\n", s.x, s.y);
    koch(n - 1, s, u);
    printf("%.8lf %.8lf\n", u.x, u.y);
    koch(n - 1, u, t);
    printf("%.8lf %.8lf\n", t.x, t.y);
    koch(n - 1, t, b);
}

int main(int argc, char* argv[]) {
    freopen("/home/freaver/CODE_C/practice/input.txt", "r", stdin);
    freopen("/home/freaver/CODE_C/practice/output.txt", "w", stdout);
    int n;
    scanf("%d", &n);

    point a(0, 0), b(100, 0);
    printf("%.8lf %.8lf\n", a.x, a.y);
    koch(n, a, b);
    printf("%.8lf %.8lf\n", b.x, b.y);

    return 0;
}
