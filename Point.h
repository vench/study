#pragma once

#include <iostream>

class Circle;

class Point {
    int x;
    int y;
public:
    Point();
    Point(int x, int y);
    Point(const Point& orig);
    Point(Point &&p);
    virtual ~Point();
    
    int getX() const;
    int getY() const;
    void setXY(int, int);
    
    Point& operator+=(const int&);
    Point& operator+=(const Point&);
    Point& operator-=(const int&);
    Point& operator-=(const Point&);
    Point& operator=(const Point&);
    Point& operator=(Point&&);
    Point& operator=(int);
    
    Point operator+(const int&);
    Point operator+(const Point&);
    Point operator-(const int&);
    Point operator-(const Point&);
    
    Point& operator-();
    Point& operator+(); 
    
    friend Circle;
    friend bool operator==(const Point&, const Point& );
    friend bool operator<(const Point&, const Point& );
  //  friend bool operator<(const Point&, const Point& ) const;
    friend std::ostream& operator<<(std::ostream&, const Point&); 
    
    
private:

};
 

bool operator==(const Point&, const Point& );
Point operator+(const int&, const Point& );
Point operator-(const int&, const Point& );
bool operator<(const Point&, const Point& );
//bool operator<(const Point&, const Point& ) const;
std::ostream& operator<<(std::ostream&, const Point&); 
