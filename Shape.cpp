#include "Shape.h"

Shape::Shape() {
}

Shape::Shape(const Shape& orig) {
}

Shape::~Shape() {
}

//
const Shape::COLOR Shape::getColor() const {
    return this->color;
}