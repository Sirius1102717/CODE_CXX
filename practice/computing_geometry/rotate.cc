#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <iostream>
#include <locale>
#include <queue>
#include <stack>
#include <string>
#include <vector>
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

    point(int xx, int yy) : x(xx), y(yy) {}
    friend bool operator==(point p1, point p2) {
        return p1.x == p2.x && p1.y == p2.y;
    }
};

inline double dot(point x, point y) {
    return x.x * y.x + x.y * y.y;
}

inline double norm(point p) {
    return dot(p, p);
}

inline double cross(point a, point b) {
    return a.x * b.y - a.y * b.x;
}

inline double mold(point p) {
    return sqrt(norm(p));
}


void print(point p0, point p1, point p2) {
    point a = p1 - p0, b = p2 - p0;
    if(cross(a, b) > EPS) {
        puts("COUNTER_CLOCKWISE");
    } else if(cross(a, b) < -EPS) {
        puts("CLOCKWISE");
    } else if(dot(a, b) < -EPS) {
        puts("ONLINE_BACK");
    } else if(norm(a) < norm(b)) {
        puts("ONLINE_FRONT");
    } else {
        puts("ON_SEGMENT");
    }
}

int main(int argc, char* argv[]) {
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
        point c(x, y);
        print(a, b, c);
    }

    return 0;
}
