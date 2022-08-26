#include "Shape.h"
#include <iostream>
using namespace std;
Shape::Shape(ColorType c) : color(c) {}

void Shape::draw() {
    cout << color << endl;
}

int main() {
    ColorType c;
    c = Black;
    Shape s = Shape(c);
    s.draw();
    return 0;
}