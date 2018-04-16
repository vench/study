#pragma once

class Point {
    int x;
    int y;
public:
    Point(int x, int y);
    Point(const Point& orig);
    Point(Point &&p);
    virtual ~Point();
private:

};
 

