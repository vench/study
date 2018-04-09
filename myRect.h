#pragma once

#include <iostream>
#include "Shape.h"

class Rect  : public Shape {
	int m_left, m_right, m_top, m_bottom;
        
       
        
        public:
            Rect();
        
            Rect(const  Rect &r);
        
            Rect(int m_left, int m_right, int m_top, int m_bottom);
            Rect(int m_left, int m_right, int m_top, int m_bottom, Shape::COLOR color);
            
            ~Rect();
            
           
             
            
            void InflateRect(int sizeHor = 1, int sizeVert =  1);
            
            void InflateRect(int m_left, int m_right, int m_top, int m_bottom);
            
            void View();
            
            void SetAll(int m_left, int m_right, int m_top, int m_bottom);


            void GetAll(int &m_left, int &m_right, int &m_top, int &m_bottom) const;
            
            Rect BoundingRect(const Rect&, const Rect&);
         
        private:
            void initialize(int m_left, int m_right, int m_top, int m_bottom);
            
            void normalize();
};



Rect BoundingRect(Rect, Rect);
Rect BoundingRect2(const Rect &a, const Rect &b);
