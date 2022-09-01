#include<iostream>
using namespace std;
class CPoint {
    private:
        int x, y;
        static int nCount;
    public:
        CPoint(int px = 0, int py = 0);
        CPoint(CPoint &);
        ~CPoint();
        int GetX();
        int GetY();
        void SetX(int);
        void SetY(int);
        void ShowPoint();
};
int main() {

    return 0;
}

CPoint::CPoint(int px, int py) {
    x = px, y = py;
    nCount++;

}

CPoint::~CPoint() {

}

int CPoint::GetX() {
    return x;
}

int CPoint::GetY() {
    return y;
}

void CPoint::SetX(int xx) {
    x = xx;
}

void CPoint::SetY(int yy) {
    x = yy;
}

void CPoint::ShowPoint() {
    cout << "(" << x << ", " << y << ")" << endl; 
}
