#pragma once

#include <iostream>

class Shape {
    
    
    
public:
    
    enum COLOR {RED, GREEN, BLUE, YELLOW, BLACK}; 
    
private:
    Shape::COLOR color;
    
public:
    
    Shape();
    Shape(Shape::COLOR c);
    Shape(const Shape& orig);
     virtual  ~Shape();
    
    virtual void WhereAmI();
    virtual void Inflate(int);
    const Shape::COLOR getColor() const;
    
private:

};
 

