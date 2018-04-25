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
int Circle::GetSquare() const {
    return 3.14 * this->radius  * this->radius;
}

//
int Circle::GetRadius() const {
    return this->radius;
}

//
bool Circle::operator==(const Circle& c) { 
    return ( c.radius == this->radius && this->p.x == c.p.x && this->p.y == c.p.y);
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
    stream <<  c.radius << "," << c.p.getX() << "," << c.p.getY();
    return stream;
}



