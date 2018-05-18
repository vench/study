
#include "Node.h"

//
Node::Node(N_TYPE t) {
    this->type = t;
    this->pPrev = nullptr;
    this->pNext = nullptr; 
}

Node& Node::operator=(const Node& c) {
    this->pPrev = c.pPrev;
    this->pNext = c.pNext;
    this->m_Data = c.m_Data;
    return *this;
}

//
Node::Node(const Node& orig) : m_Data(orig.m_Data) {
    this->type = orig.type;
}

//
Node::Node( Node&& orig): m_Data(orig.m_Data)  {
    this->type = orig.type;
}


//
Node::Node() : Node(Node::HEAD) { 
}

//
Node::Node(const Shape *c) : m_Data(*c) {
    this->type = NODE;
}

//
Node::~Node() {
    
    this->pPrev = nullptr;
    this->pNext = nullptr; 
    //Изъяли текущий элемент из списка
    
    //TODO
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
     stream << n.m_Data << std::endl;
    return stream;
}

//
bool operator< (const Node& a, const Node& b) {
    return a.m_Data.GetSquare() < b.m_Data.GetSquare();
}

//
bool operator> (const Node& a, const Node& b) {
    return a.m_Data.GetSquare() > b.m_Data.GetSquare();
}
