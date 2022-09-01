#include "CPoint.h"
#include <cmath>
#include <iostream>
using namespace std;
class CLine {
private:
    CPoint pt1, pt2;

public:
    CLine();
    CLine(int x1, int y1, int x2, int y2);
    CLine(CPoint p1, CPoint p2);
    double Distance();
    void showLine();

};

CLine::CLine() {
    pt1 = CPoint();
    pt2 = CPoint();
}
CLine::CLine(int x1, int y1, int x2, int y2) {
    pt1 = CPoint(x1, y1);
    pt2 = CPoint(x2, y2);
}
CLine::CLine(CPoint p1, CPoint p2) {
    pt1 = p1, pt2 = p2;
}
double CLine::Distance() {
    return sqrt(pow(pt1.GetX() - pt2.GetX(), 2) + pow(pt1.GetY() - pt2.GetY(), 2));
}
void CLine::showLine() {
    cout << pt1 << pt2 << endl;
}