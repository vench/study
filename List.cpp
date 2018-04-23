

#include "List.h"

//
List::List() : Head(Node::HEAD), Tail(Node::TAIL){ 
    
    this->m_size = 0;
    
    Head.pNext = &Tail;
    Tail.pPrev = &Head;
    
}

//
List::List(const List& orig) : Head(orig.Head), Tail(orig.Tail) { 
    this->m_size = orig.m_size;
}

//
List::~List() {
    this->Clear();
     
}

//
void List::AddToHead(Circle* c) {
    Node *pNewNode = new Node(c);
    
    Node *pTmpNext = this->Head.pNext;
    this->Head.pNext = pNewNode;
    pNewNode->pPrev = &this->Head;
    
    pNewNode->pNext = pTmpNext;
    pTmpNext->pPrev = pNewNode;
    
    this->m_size ++;
}
    
//
void List::AddToTail(Circle* c) {
    Node *pNewNode = new Node(c);
    
    Node *pTmpPrev = this->Tail.pPrev;
    this->Tail.pPrev = pNewNode;
    pNewNode->pNext = &this->Tail;
    
    pNewNode->pPrev = pTmpPrev;
    pTmpPrev->pNext = pNewNode;
    
    this->m_size ++;
}

//
bool List::Remove(Circle* c) {
    return RemoveAll(c, 1);
}
    
//
int List::RemoveAll(Circle* c) { 
    return RemoveAll(c, this->m_size);
}

//
int List::RemoveAll(Circle* c, int limit) {
    int count = 0;
    const Node *pNode = this->Head.GetNext();
    while(limit > 0 && pNode  && !pNode->isTail()) { 
        if(*c == pNode->m_Data) { 
            Node *pTmpNext = pNode->pNext;
            Node *pTmpPrev = pNode->pPrev;
            pTmpNext->pPrev = pTmpPrev;
            pTmpPrev->pNext = pTmpNext;
            delete pNode; 
            pNode = pTmpPrev;
            this->m_size --;
            count --;
            limit --;
        }         
        pNode = pNode->GetNext();
    }   
    
    return count;
}

     
//
void List::Clear() {
    const Node *pNode = this->Head.GetNext();
    while(pNode  && !pNode->isTail()) { 
        delete pNode;        
        pNode = pNode->GetNext();
    } 
    this->m_size = 0;
    Head.pNext = &Tail;
    Tail.pPrev = &Head;    
} 

//
std::ostream& operator<< (std::ostream& stream, const List& l) {
    stream << "List{ Items: "<< std::endl;
    const Node *pNode = l.Head.GetNext();
    while(pNode && !pNode->isTail()) {
        stream << *pNode;  
        pNode = pNode->GetNext();
    }
    
    stream << "}"<< std::endl;
     
    return stream;
}