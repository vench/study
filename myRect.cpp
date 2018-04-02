#include "myRect.h"


Rect::Rect(){
    initialize(0,0,0,0);
};

Rect::Rect(int m_left, int m_right, int m_top, int m_bottom){
    initialize( m_left, m_right, m_top, m_bottom);
};
            
void Rect::initialize(int m_left, int m_right, int m_top, int m_bottom) {
    this->m_left = m_left;
    this->m_right = m_right;
    this->m_top = m_top;
    this->m_bottom = m_bottom;
    
    normalize();
};

void Rect::normalize() {
    
    if(m_left > m_right) {
        int tmp = m_left;
        m_left = m_right;
        m_right = tmp;
    }
    
    if(m_top > m_bottom) {
        int tmp = m_bottom;
        m_bottom = m_top;
        m_top = tmp;
    } 
};

void Rect::InflateRect(int size) {
    this->m_left -= size;
    this->m_right += size;
    this->m_top -= size;
    this->m_bottom += size;
};

void Rect::InflateRect(int sizeHor, int sizeVert) {
    this->m_left -= sizeHor;
    this->m_right += sizeHor;
    this->m_top -= sizeVert;
    this->m_bottom += sizeVert;
};

void Rect::InflateRect(int m_left, int m_right, int m_top, int m_bottom) {
    this->m_left -= m_left;
    this->m_right += m_right;
    this->m_top -= m_top;
    this->m_bottom += m_bottom;
};


void Rect::View(){

    std::cout << "\nRect{l: " << m_left << ", t: " << m_top << ", r: " << m_right << ", b: " << m_bottom <<  "}\n";
    
};