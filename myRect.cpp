#include "myRect.h"




Rect::Rect(){
    initialize(0,0,0,0);
};

Rect::Rect(int m_left, int m_right, int m_top, int m_bottom){
    initialize( m_left, m_right, m_top, m_bottom);
};

Rect::Rect(const  Rect &r) {
    std::cout << "From Rect::Rect copy\n" ;
    
    initialize( r.m_left, r.m_right, r.m_top, r.m_bottom);
};

Rect::~Rect() {
    //std::cout << "From desctructor ~Rect();\n";
    //TODO
}; 

//
Rect Rect::BoundingRect(const Rect &a, const Rect &b) {
   int left1, right1, top1, bottom1,left2, right2, top2, bottom2;
    a.GetAll(left1, right1, top1, bottom1);
    b.GetAll(left2, right2, top2, bottom2);  
    
    return Rect( left1 < left2 ? left1 : left2, 
            right1 > right2 ? right1 : right2, 
            top1 < top2 ? top1 : top2,  
            bottom1 > bottom2 ? bottom1 : bottom2
            );     
}

//
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

    std::cout << "\nRect{left: " << m_left << ", top: " << m_top << ", right: " << m_right << ", bottom: " << m_bottom <<  "}\n";
    
};


/**
 * 
 * @param m_left
 * @param m_right
 * @param m_top
 * @param m_bottom
 */
void Rect::SetAll(int m_left, int m_right, int m_top, int m_bottom) {
    initialize(m_left, m_right, m_top, m_bottom);
};

/**
 * 
 * @param m_left
 * @param m_right
 * @param m_top
 * @param m_bottom
 */
void Rect::GetAll(int &m_left, int &m_right, int &m_top, int &m_bottom) const {
   m_left = this->m_left; 
   m_right = this->m_right; 
   m_top = this->m_top; 
   m_bottom = this->m_bottom; 
};


//
Rect BoundingRect(Rect a, Rect b) { 
    int left1, right1, top1, bottom1,left2, right2, top2, bottom2;
    a.GetAll(left1, right1, top1, bottom1);
    b.GetAll(left2, right2, top2, bottom2);
    
    return Rect( left1 < left2 ? left1 : left2, 
            right1 > right2 ? right1 : right2, 
            top1 < top2 ? top1 : top2,  
            bottom1 > bottom2 ? bottom1 : bottom2
            );
    
};

//
Rect BoundingRect2(const Rect &a, const Rect &b) {
 int left1, right1, top1, bottom1,left2, right2, top2, bottom2;
    a.GetAll(left1, right1, top1, bottom1);
    b.GetAll(left2, right2, top2, bottom2);
    
    return Rect ( left1 < left2 ? left1 : left2, 
            right1 > right2 ? right1 : right2, 
            top1 < top2 ? top1 : top2,  
            bottom1 > bottom2 ? bottom1 : bottom2
            );
        
};
