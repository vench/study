
#include "Node.h"
#include "Circle.h"

//
Node::Node(N_TYPE t) {
    this->type = t;
    this->m_Data = nullptr;
    this->pPrev = nullptr;
    this->pNext = nullptr; 
}

Node& Node::operator=(const Node& c) {
  
    this->pPrev = c.pPrev;
    this->pNext = c.pNext;
    this->type = c.type;
    if(this->type == Node::NODE && c.m_Data) {
        this->m_Data = c.m_Data->Clone();
    }
     
    return *this;
}

//
Node::Node(const Node& orig)  {
    this->type = orig.type;
    if(this->type == Node::NODE && orig.m_Data) {
        this->m_Data = orig.m_Data->Clone();
    }
    this->pPrev = nullptr;
    this->pNext = nullptr;
}

//
Node::Node( Node&& orig)  {
    this->type = orig.type;
    this->m_Data = orig.m_Data;
    this->pPrev = nullptr;
    this->pNext = nullptr; 
    orig.m_Data = nullptr;
}


//
Node::Node() : Node(Node::HEAD) { 
    this->pPrev = nullptr;
    this->pNext = nullptr;  
    this->m_Data = nullptr;
}

//
Node::Node( Shape *c)  {  
    this->m_Data = c->Clone();  
    this->type = NODE;
    this->pPrev = nullptr;
    this->pNext = nullptr;
}

//
Node::~Node() {
  
    this->pPrev = nullptr;
    this->pNext = nullptr; 
    
    if(this->m_Data) {
        delete this->m_Data;
        this->m_Data = nullptr; 
    }       
}
 

//
bool Node::isHead() const {
    return this->type == HEAD;
}
    
//
bool Node::isTail() const {
    return this->type == TAIL;
}

//
Node *Node::GetNext() const {
    return this->pNext;
}

//
std::ostream& operator<< (std::ostream& stream, const Node& n) {
    stream << *n.m_Data << std::endl;
    return stream;
}

//
bool operator< (const Node& a, const Node& b) {
    return a.m_Data->GetSquare() < b.m_Data->GetSquare();
}

//
bool operator> (const Node& a, const Node& b) {
    return a.m_Data->GetSquare() > b.m_Data->GetSquare();
}
