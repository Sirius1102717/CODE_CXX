#include <algorithm>
#include <cstring>
#include <deque>
#include <iostream>
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
    int x, y;
    point(int x, int y) : x(x), y(y) {}
    point() = default;
    point(const point &p) = default;

    point friend operator-(point p1, point p2) {
        point p(p1);
        p.x -= p2.x, p.y -= p2.y;
        return p;
    }
};

struct line {
    point a, b;
    // int x, y;
    // line(int x, int y) : x(x), y(y) {}
    line(point a, point b) : a(a), b(b) {}
};

typedef point Vector;

inline bool equals(double a, double b) {
    return a - b < EPS;
}

inline int dot(Vector x, Vector y) {
    return x.x * y.x + x.y * y.y;
}

inline int norm(Vector p) {
    return dot(p, p);
}

inline int cross(Vector a, Vector b) {
    return a.x * b.y - a.y * b.x;
}

bool isParallel(Vector l1, Vector l2) {
    return !cross(l1, l2);
}

bool isOrthogonal(Vector l1, Vector l2) {
    return !dot(l1, l2);
}

bool isIntersect(point a, point b, point c, point d) {
    if(max(c.x, d.x) < min(a.x, b.x) || max(a.x, b.x) < min(c.x, d.x) || max(c.y, d.y) < min(a.y, b.y) || max(a.y, b.y) < min(c.y, d.y)) {
        return 0;
    }
    if(cross(a - d, c - d) * cross(b - d, c - d) > 0 || cross(d - b, a - b) * cross(c - b, a - b) > 0) {
        return 0;
    }
    return 1;
}

int main(int argc, char* argv[]) {
    freopen("/home/freaver/CODE_C/practice/input.txt", "r", stdin);
    freopen("/home/freaver/CODE_C/practice/output.txt", "w", stdout);
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin >> q;
    int x1, x2, x3, x4, y1, y2, y3, y4;
    while(q--) {
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
        point a(x1, x2), b(x2, y2), c(x3, y3), d(x4, y4);
        cout << isIntersect(a, b, c, d) << endl;
    }

    return 0;
}
