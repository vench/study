#include "Rect.h"

//
Rect::Rect()  : 
    Shape(Shape::RED) {
    initialize(0,0,0,0);
};

//
Rect::Rect(int m_left, int m_right, int m_top, int m_bottom){
    initialize( m_left, m_right, m_top, m_bottom);
};

//
Rect::Rect(int m_left, int m_right, int m_top, int m_bottom, Shape::COLOR color) : 
    Shape(color) {
   // std::cout << "From constr Rect();\n";
    initialize( m_left, m_right, m_top, m_bottom);
};


void Rect::Inflate(int size) {
     InflateRect(size, size);
     std::cout << "Circle implementation Inflate!\n" ;
}

//
Rect::Rect(const  Rect &r) : Shape(r) {
    std::cout << "From Rect::Rect copy\n" ;
    
    initialize( r.m_left, r.m_right, r.m_top, r.m_bottom);
};

//
Rect::~Rect() {
    //std::cout << "Now I am in Rect's destructor!\n";
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
const char* Rect::WhereAmI() const {
    return "Now I am in class Rect";
};

//
void Rect::Serialuze(std::ostream& stream) const {
    stream << "Rect{ l:" << this->m_left << ", r:" << this->m_right 
            << ", b:" << this->m_bottom << ", t:" << this->m_top << ", c:" << this->color 
            << ", sq:" << this->GetSquare() << "}";
}

//
bool Rect::UnSerialuze(const char* str) {
    int l,r,b,t,c,z = 0;
    if(sscanf (str,"Rect{ l:%d, r:%d, b:%d, t:%d, c:%d, sq:%d}\n",&l,&r,&b,&t,&c,&z) > 0) {
        this->m_left = l;
        this->m_right = r;
        this->m_bottom = b;
        this->m_top = t;
        this->color = Shape::COLOR(c);
        return true;
    }
    return false;
}

//
Shape* Rect::Clone() const {
    return new Rect(*this); 
}

//
int Rect::GetSquare() const {
    return (m_right - m_left) * (m_bottom - m_top);
}

//
bool Rect::IsEqual( Shape*s) const{
    if(Rect *r = dynamic_cast<Rect*>(s)) {
        
        return this->m_left == r->m_left && 
               this->m_right == r->m_right && 
               this->m_top == r->m_top && 
               this->m_bottom == r->m_bottom &&
               this->Shape::IsEqual(s);
    }
    return false;
}

//
Shape& Rect::operator=(const Shape&) {
    return *this;
}

//
Shape& Rect::operator=(Shape&&) {
    return *this;
}

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


