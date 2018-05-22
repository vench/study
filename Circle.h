#pragma once

#include <iostream>
#include "Point.h"
#include "Shape.h"

//
class Circle : public Shape {
    
    Point p; 
    int radius;
    
public:
    Circle();
    Circle(int x, int y, int radius);
    Circle(int x, int y, int radius, Shape::COLOR color);
    Circle(const Circle& orig);
    Circle( Circle&& orig);
    Circle(const Shape&);
    Circle( Shape&&);
     
    void Inflate(int); 
     ~Circle();
     
    virtual const char* WhereAmI() const;
    virtual void Serialuze(std::ostream&) const;
    virtual bool UnSerialuze(const char*);
    virtual Shape* Clone() const;
    int GetSquare() const;
    int GetRadius() const;
     
    Circle& operator=(const Circle&);
    bool operator==(const Circle&);
    virtual bool IsEqual(Shape*) const;
    friend bool operator==(const Circle&,const Circle&);
    virtual Shape& operator=(const Shape&);
    virtual Shape& operator=(Shape&&);
    
    
    friend std::ostream& operator<<(std::ostream&, const Circle&);
private:

};


bool operator==(const Circle&,const Circle&);

std::ostream& operator<< (std::ostream&, const Circle&);
