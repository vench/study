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
     std::cout << "Now I am in Shape's destructor!\n" ;
}

//
void Shape::Inflate(int size) {
    std::cout << "Base implementation Inflate!\n" ;
}


//
const Shape::COLOR Shape::getColor() const {
    return this->color;
}

//
void Shape::WhereAmI() {
    std::cout << "Now I am in class Shape\n";
};