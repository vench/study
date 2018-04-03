#pragma once

#include <iostream>

class Rect {
	int m_left, m_right, m_top, m_bottom;
        
       
        
        public:
            Rect();
        
            Rect(const  Rect &r);
        
            Rect(int m_left, int m_right, int m_top, int m_bottom);
            
            ~Rect();
            
           
             
            
            void InflateRect(int sizeHor = 1, int sizeVert =  1);
            
            void InflateRect(int m_left, int m_right, int m_top, int m_bottom);
            
            void View();
            
            void SetAll(int m_left, int m_right, int m_top, int m_bottom);

            void GetAll(int &m_left, int &m_right, int &m_top, int &m_bottom);
         
        private:
            void initialize(int m_left, int m_right, int m_top, int m_bottom);
            
            void normalize();
};



Rect BoundingRect(Rect, Rect);
Rect BoundingRect2(Rect &a, Rect &b);
