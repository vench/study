#include "Circle.h"

//
Circle::Circle() {
}

//
Circle::Circle(const Circle& orig) : Shape(orig) {
    this->x = orig.x;
    this->y = orig.y;
    this->radius = orig.radius;
    
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
Circle::Circle(const Rect& orig)  : Shape(orig)  {
    int l,r,t,b;
    orig.GetAll(l,r,t,b); 
    
    this->x =  r + l >> 1;
    this->y =  b + t >> 1;
     this->radius =       ((r - l > b - t ? b - t : r - l) >> 1);
}


//
void Circle::WhereAmI() {
    std::cout << "Now I am in class Circle\n";
};



