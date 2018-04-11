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
    std::cout << "Now I am in Circle's destructor!\n";
}

//
void Circle::Inflate(int size) {
     this->radius = size;
     std::cout << "Circle implementation Inflate!\n" ;
}

//
Circle::Circle(const Rect& orig) {
    int l,r,t,b;
    orig.GetAll(l,r,t,b); 
    
    Circle( r + l >> 1,
            b + t >> 1,
            (r - l > b - t ? b - t : r - l) >> 1, 
            orig.getColor());
}


//
void Circle::WhereAmI() {
    std::cout << "Now I am in class Circle\n";
};



