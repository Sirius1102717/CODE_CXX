#pragma once
enum ColorType {
    White, Black, Green, Blue, Yellow, Magenta, Cyan
};

class Shape {
    protected:
        ColorType color;
    public: 
        Shape(ColorType c);
        virtual void draw();
};