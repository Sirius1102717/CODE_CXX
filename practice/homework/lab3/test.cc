#include "CPoint.h"
int main () {
    CPoint c;
    c = CPoint(1, 2);
    CPoint d;
    d = CPoint(c);
    cout << c <<  " " <<  &c << endl;
    cout << d << " " << &d << endl;
    return 0;
}