#include "Circle.h"

//
Circle::Circle() : p() {
    this->radius = 1; 
}

//
Circle::Circle(const Circle& orig) : p(orig.p)  { 
    this->radius = orig.radius; 
}

//
Circle::Circle(int x, int y, int radius) : p(x, y) { 
    this->radius = radius;
}

//
Circle::~Circle() {
   // std::cout << "Now I am in Circle's destructor!\n";
}

//
void Circle::Inflate(int size) {
     this->radius = size;
     std::cout << "Circle implementation Inflate!\n" ;
}
 

//
void Circle::WhereAmI() {
    std::cout << "Now I am in class Circle\n";
};

//
std::ostream& operator<< (std::ostream& stream, const Circle& c) {
    stream << "Circle{radius: " << c.radius << ", x: " << c.p.getX() << " , y: " << c.p.getY() << "  }" << std::endl;
    return stream;
}



