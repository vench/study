#pragma once

#include <iostream>
#include "Circle.h"

class Node {
    
    Node* pPrev;		//указатель на предыдущий элемент
    Node* pNext;		//указатель на следующий элемент
    Circle m_Data;
    
public: 
    Node(const Node& orig);
    Node(int);
    Node(const Circle *);
    virtual ~Node();
    
    friend std::ostream& operator<<(std::ostream&, const Node&);
private:

}; 

//
std::ostream& operator<< (std::ostream&, const Node&);

