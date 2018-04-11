#pragma once

#include "Shape.h"
#include "myRect.h"
#include <iostream>

class Circle : public Shape {
    
    int x;
    int y;
    int radius;
    
public:
    Circle();
    Circle(int x, int y, int radius, Shape::COLOR color);
    Circle(const Circle& orig);
    Circle(const Rect& orig);
    void Inflate(int); 
     ~Circle();
     
    void WhereAmI();
private:

};


