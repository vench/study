#pragma once

#include <iostream>
#include "Circle.h"

//
class List;

//
class Node {
    
public:
    enum N_TYPE {HEAD, TAIL, NODE};
    
private:    
    
    Node* pPrev;		//указатель на предыдущий элемент
    Node* pNext;		//указатель на следующий элемент
    Circle m_Data;
    N_TYPE type;
    
public: 
    Node(const Node& orig);
    Node(N_TYPE);
    Node(const Circle *);
    virtual ~Node();
    
    bool operator==(const Point&);
    
    bool isHead() const;    
    bool isTail() const; 
    Node *GetNext() const;
    
    friend List;
    friend std::ostream& operator<<(std::ostream&, const Node&);
private:

}; 

//
std::ostream& operator<< (std::ostream&, const Node&);

