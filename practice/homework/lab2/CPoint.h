#ifndef CPoint_h
#define CPoint_h

#include <iostream>
using namespace std;
class CPoint {
private:
    int x, y;
    static int nCount;

public:
    CPoint(int px = 0, int py = 0);
    CPoint(CPoint&);
    ~CPoint();
    int GetX();
    int GetY();
    void SetX(int);
    void SetY(int);
    void ShowPoint();
    friend ostream& operator<<(ostream&, const CPoint&);
    friend istream& operator>>(istream&, CPoint&);
    CPoint operator+(CPoint& b) const;
    CPoint operator-(CPoint& b) const;
};

#endif
