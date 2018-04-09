#include "Shape.h"

Shape::Shape() {
}

//
Shape::Shape(Shape::COLOR c) : color(c) {
    //std::cout << "From constr Shape();\n";
};

//
Shape::Shape(const Shape& orig) {
}

//
Shape::~Shape() {
    //std::cout << "From desctructor ~Shape();\n";
}

//
const Shape::COLOR Shape::getColor() const {
    return this->color;
}