
#include "Node.h"

//
Node::Node(int) {
    //TODO
}

//
Node::Node(const Node& orig) : m_Data(orig.m_Data) {
    //TODO
}

//
Node::Node(const Circle *c) : m_Data(*c) {
    
}

//
Node::~Node() {
    this->pPrev = nullptr;
    this->pNext = nullptr; 
    //Изъяли текущий элемент из списка
    //TODO
}


//
std::ostream& operator<< (std::ostream& stream, const Node& n) {
     stream << "Node{data: " << n.m_Data <<"  }" << std::endl;
    return stream;
}
