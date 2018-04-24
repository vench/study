#pragma once

#include <iostream>
#include "Point.h"

class Circle  {
    
    Point p; 
    int radius;
    
public:
    Circle();
    Circle(int x, int y, int radius);
    Circle(const Circle& orig);
     
    void Inflate(int); 
     ~Circle();
     
    void WhereAmI();
    int GetSquare() const;
    int GetRadius() const;
    
    bool operator==(const Circle&);
    
    
    friend std::ostream& operator<<(std::ostream&, const Circle&);
private:

};

std::ostream& operator<< (std::ostream&, const Circle&);
