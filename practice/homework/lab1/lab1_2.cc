#include <iostream>
using namespace std;

int Maxl(int a, int b) {
    return a > b ? a : b;
}

int Maxl(int a, int b, int c) {
    int aa = Maxl(a, b);
    int cc = Maxl(a, c);
    return aa > cc ? aa : cc;
}

float Maxl(float a, float b) {
    return a > b ? a : b;
}

float Maxl(float a, float b, float c) {
    float aa = Maxl(a, b);
    float cc = Maxl(a, c);
    return aa > cc ? aa : cc;
}

int main() {
    int a, b;
    cout << "Enter two integer\n";
    cin >> a >> b;
    cout << "the max num is:" << Maxl(a, b) << endl;
    int c, d, e;
    cout << "Enter three integer\n";
    cin >> c >> d >> e;
    cout << "the max num is: " << Maxl(c, d, e) << endl;
    float f, g;
    cout << "Enter two float\n";
    cin >> f >> g;
    cout <<  "the max num is: " << Maxl(f, g) << endl;
    float h, i, j;
    cout << "Enter tree Integer\n";
    cin >> h >> i >> j;
    cout << "the max num is: " << Maxl(h, i, j) << endl;
    return 0;
}