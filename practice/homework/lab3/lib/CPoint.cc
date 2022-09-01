#include "CPoint.h"
CPoint::CPoint(int px, int py) {
    x = px, y = py;
    nCount++;
}

CPoint::CPoint(CPoint& c) : x(c.x), y(c.y) {}

// CPoint::CPoint(CPoint& c) {
// x = c.x;
// y = c.y;
// nCount = c.nCount;
// }

CPoint::~CPoint() {}

int CPoint::GetX() {
    return x;
}

int CPoint::GetY() {
    return y;
}

void CPoint::SetX(int xx) {
    x = xx;
}

void CPoint::ShowPoint() {
    cout << "(" << x << ", " << y << ")" << endl;
}

ostream& operator<<(ostream& os, CPoint& c) {
    os << "(" << c.x << ", " << c.y << ")" << endl;
    return os;
}

istream& operator>>(istream& is, CPoint& c) {
    is >> c.x >> c.y;
    return is;
}
CPoint CPoint::operator+(CPoint& b) const {
    CPoint c;
    c.x = x + b.x;
    c.y = y + b.y;
    c.nCount = nCount;
    return c;
}
CPoint CPoint::operator-(CPoint& b) const {
    CPoint c;
    c.x = x - b.x;
    c.y = y - b.y;
    c.nCount = nCount;
    return c;
}

// int main() {
    // CPoint c;
    // return 0;
// }