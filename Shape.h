#pragma once

class Shape {
    
    
    
public:
    
    enum COLOR {RED, GREEN, BLUE, YELLOW, BLACK}; 
    
private:
    Shape::COLOR color;
    
public:
    
    Shape();
    Shape(const Shape& orig);
    virtual ~Shape();
    
    
    const Shape::COLOR getColor() const;
    
private:

};
 

