#include<iostream>
using namespace std;

int add(int a, int b);

int Maxl(int a, int b) {
    return a > b ? a : b;
}

int Maxl(int a, int b, int c) {
    int aa = Maxl(a, b);
    int cc = Maxl(a, c);
    return aa > cc ? aa : cc;
}

int Maxl(float a, float b) {
    return a > b ? a : b;
}

int Maxl(float a, float b, float c) {
    int aa = Maxl(a, b);
    int cc = Maxl(a, c);
    return aa > cc ? aa : cc;
}

int main () {
    int x, y, sum;
    cout << "Enter two numbers:\n";
    cin >> x;
    cin >> y;
    sum = add(x, y);
    cout << "The sum is: " << sum << endl;
    return 0;
}

int add(int a, int b) {
    int c;
    c = a + b;
    return c;
}

