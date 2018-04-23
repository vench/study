
#include "Node.h"

//
Node::Node(N_TYPE t) {
    this->type = t;
    this->pPrev = nullptr;
    this->pNext = nullptr; 
}

//
Node::Node(const Node& orig) : m_Data(orig.m_Data) {
    this->type = orig.type;
}

//
Node::Node(const Circle *c) : m_Data(*c) {
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
bool Node::operator==(const Point&) {
    //TODO
    return false;
}

//
bool Node::isHead() const {
    return this->type == HEAD;
}
    
//
bool Node::isTail() const {
    return this->type == TAIL;
}



Node *Node::GetNext() const {
    return this->pNext;
}

//
std::ostream& operator<< (std::ostream& stream, const Node& n) {
     stream << "Node{data: " << n.m_Data <<"  }" << std::endl;
    return stream;
}
