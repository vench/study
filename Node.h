#pragma once

#include <iostream>
#include "Shape.h"

//
class List;

//
class Node {
    
public:
    enum N_TYPE {HEAD, TAIL, NODE};
    
private:    
    
    Node* pPrev;		//указатель на предыдущий элемент
    Node* pNext;		//указатель на следующий элемент
    Shape m_Data;
    N_TYPE type;
    bool deleted;
    

    Node();
    Node(const Node& orig);
    Node(const Node&& orig);
    Node(N_TYPE);
    Node(const Shape *);
    ~Node(); 
    
    bool isHead() const;    
    bool isTail() const; 
    Node *GetNext() const;  
    Node& operator=(const Node&);
    
    friend List;
    friend std::ostream& operator<<(std::ostream&, const Node&);
    friend std::ostream& operator<<(std::ostream&, const List&);
    friend bool operator< (const Node&, const Node&);
    friend bool operator> (const Node&, const Node&);
    


}; 

//
std::ostream& operator<< (std::ostream&, const Node&);

//
bool operator< (const Node&, const Node&);

//
bool operator> (const Node&, const Node&);

