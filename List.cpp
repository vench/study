

#include "List.h"

//
List::List() : Head(0), Tail(1){ 
    
    this->m_size = 0;
}

//
List::List(const List& orig) : Head(orig.Head), Tail(orig.Tail) { 
    this->m_size = orig.m_size;
}

//
List::~List() {
    //TODO
    
    this->Head = nullptr;
    this->Tail = nullptr;
}

//
void List::AddToHead(Circle* c) {
    
}
    
//
void List::AddToTail(Circle* c) {

}

//
bool List::Remove(Circle* c) {
    return false;
}
    
//
int List::RemoveAll(Circle* c) {
    return 0;
}
     
//
void List::Clear() {

} 

