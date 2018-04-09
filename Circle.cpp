#include "Circle.h"

//
Circle::Circle() {
}

//
Circle::Circle(const Circle& orig) {
}

//
Circle::Circle(int x, int y, int radius, Shape::COLOR color) : Shape(color) {
    this->x = x;
    this->y = y;
    this->radius = radius;
}

//
Circle::~Circle() {
    std::cout << "From desctructor ~Circle();\n";
}



