#include "Point.h"

#include <iostream>

//
Point::Point() {
    this->x = 0;
    this->y = 0;  
}

//
Point::Point(int x, int y) {
    this->x = x;
    this->y = y;
}

//
Point::Point(const Point& orig) {
    this->x = orig.x;
    this->y = orig.y;
}
 
//
Point::Point(Point &&p) {
    this->x = p.x;
    this->y = p.y;
}

//
Point::~Point() {
}
 

//
Point& Point::operator+=(const Point& orig) {
    this->x += orig.x;
    this->y += orig.y;
    
    return *this;
}

//
Point& Point::operator-=(const int& orig) {
    this->x -= orig;
    this->y -= orig;
    
    return *this;
}

//
Point& Point::operator-=(const Point & orig) {
    this->x -= orig.x;
    this->y -= orig.y;
    
    return *this;
}

//
Point Point::operator+(const Point& orig) {  
    return Point(this->x + orig.x, this->y + orig.y); // TODO std::move
}

//
Point Point::operator-(const int& orig) {
    return Point(this->x - orig, this->y - orig); // TODO std::move
}
    
//
Point Point::operator-(const Point& orig) {
    return Point(this->x - orig.x, this->y - orig.y); // TODO std::move
}

//
Point& Point::operator+=(const int& orig) {
    this->x += orig;
    this->y += orig;
    return *this;
}

//
Point Point::operator+(const int& orig) { 
    return Point(this->x + orig, this->y + orig); // TODO std::move
}

//
Point& Point::operator=(const Point& orig) {
    this->x = orig.x;
    this->y = orig.y;
    return *this;
}

//
Point& Point::operator=(int i) {
    this->x = i;
    this->y = i;
    return *this;
}

//
Point& Point::operator=(Point&& orig){
    this->x = orig.x;
    this->y = orig.y;
    return *this;
}

//
Point& Point::operator-() {
    this->x *=-1;
    this->y *=-1;
    return *this;
}

//
Point& Point::operator+() {
    if(this->x < 0){
        this->x *=-1;
    }
    if(this->y < 0) {
        this->y *=-1;
    }
    return *this;
}


//
int Point::getX() const {
    return this->x;
}

//
int Point::getY() const {
    return this->y;
}



//
Point operator+(const int& val, const Point& p) {
    return Point(p) + val;
}

//
Point operator-(const int& val, const Point& p) {
    return Point(p) - val;
}

//
bool operator==(const Point& a, const Point& b ) {
    return a.x == b.x && a.y == b.y;
}
