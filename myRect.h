#pragma once

#include <iostream>

class Rect {
	int m_left, m_right, m_top, m_bottom;
        
       
        
        public:
            Rect();
        
            Rect(int m_left, int m_right, int m_top, int m_bottom);
            
            void initialize(int m_left, int m_right, int m_top, int m_bottom);
            
            void normalize();
            
            void InflateRect(int size);
            
            void InflateRect(int sizeHor, int sizeVert);
            
            void InflateRect(int m_left, int m_right, int m_top, int m_bottom);
            
            void View();

};