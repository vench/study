#pragma once

#include <iostream>

class Shape {
    
    
    
public:
    
    enum COLOR {RED, GREEN, BLUE, YELLOW, BLACK}; 
    
protected:
    Shape::COLOR color;
    
public:
    
    Shape();
    Shape(Shape::COLOR c);
    Shape(const Shape& orig);
    virtual  ~Shape();
    
    virtual const char* WhereAmI() const;
    virtual void Serialuze(std::ostream&) const;
    virtual bool UnSerialuze(const char*);
    virtual void Inflate(int);
    virtual int GetSquare() const;
    virtual Shape* Clone() const =0;
    virtual bool IsEqual(Shape*) const;
    virtual Shape& operator=(const Shape&)=0;
    virtual Shape& operator=(Shape&&)=0;
    const Shape::COLOR getColor() const;
    
    
    
    
    friend std::ostream& operator<<(std::ostream&, const Shape&);
    
private:

};
 
//
std::ostream& operator<< (std::ostream&, const Shape&);