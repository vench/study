#include "Circle.h"

//
Circle::Circle() : p(), Shape(Shape::RED) {
    this->radius = 1; 
}

//
Circle::Circle(const Circle& orig) : p(orig.p), Shape(orig.color)  { 
    this->radius = orig.radius; 
}

//
Circle::Circle( Circle&& orig) : p(orig.p), Shape(orig.color)  {
    this->radius = orig.radius;
    
}

//
Circle::Circle(const Shape& orig) {}

//
Circle::Circle( Shape&& orig) {}

//
Circle::Circle(int x, int y, int radius) : p(x, y), Shape(Shape::RED) { 
    this->radius = radius;
}

//
Circle::Circle(int x, int y, int radius, Shape::COLOR color): p(x, y), Shape(color) {
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
    return ( c.radius == this->radius && c.p == this->p);
}

//
bool operator==(const Circle& b, const Circle& a) {
    return ( a.radius == b.radius && b.p == a.p);
}  

//
Circle& Circle::operator=(const Circle& c) {
    this->radius = c.GetRadius();
    this->p.x = c.p.x;
    this->p.y = c.p.y;
    return *this;
}




//
void Circle::Inflate(int size) {
     this->radius = size;
     std::cout << "Circle implementation Inflate!\n" ;
}
 

//
const char* Circle::WhereAmI() const {
    return "Now I am in class Circle";
};

//
void Circle::Serialuze(std::ostream& stream) const { 
    stream << "Circle{ r:" <<  this->radius << ", x:" << this->p.getX() 
            << ", y:" << this->p.getY() << ", c: " << this->color << ", sq: " << this->GetSquare() << "}";
}

//
bool Circle::UnSerialuze(const char* str)  {
    int r,x,y,c,z = 0;
    if(sscanf (str,"Circle{ r:%d, x:%d, y:%d, c: %d, sq: %d}\n",&r, &x, &y, &c, &z) > 0) {
        this->radius = r;
        this->color = Shape::COLOR(c);
        this->p.x = x;
        this->p.y = y;
        return true;
    }
    
    return false;
}

//
Shape* Circle::Clone() const {
    return new Circle(*this); 
}


//
bool Circle::IsEqual(Shape* s) const {
    if(Circle *c = dynamic_cast<Circle*>(s)) {
       return this->radius == c->radius &&
               this->p == c->p &&
               this->Shape::IsEqual(s);
    }
    return false;
}

//
Shape& Circle::operator=(const Shape&) {
    return *this;
}

//
Shape& Circle::operator=(Shape&&) {
    return *this;
}

//
std::ostream& operator<< (std::ostream& stream, const Circle& c) {
    c.Serialuze(stream);
    return stream;
}


