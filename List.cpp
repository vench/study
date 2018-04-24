

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
void List::Swap(Node* a, Node* b)   {
    
    if(a->isHead() || a->isTail() || b->isHead() || b->isTail()) {
        return;
    } 
    
   
    
    if(a->pNext == b) { //A >>>> B 
        Node *tmpAPrev = a->pPrev;
        a->pNext = b->pNext;
        a->pPrev = b;
        b->pNext = a;
        b->pPrev = tmpAPrev;
        
        tmpAPrev->pNext = b;
        a->pNext->pPrev = a;
        
    } else if(b->pNext == a) { //B >>>>> A
       
        Node *tmpBPrev = b->pPrev;
        b->pNext = a->pNext;
        b->pPrev = a;
        a->pNext = b;
        a->pPrev = tmpBPrev;
        
        tmpBPrev->pNext = a;
        b->pNext->pPrev = b;
    }
    /*
     * 
     *  Node *tAn = a->pNext;//B
    Node *tAp = a->pPrev;//H
    Node *tBn = b->pNext;//T
    Node *tBp = b->pPrev;//A
    a->pNext = (tBn == a) ? b : tBn;;//T
   // a->pPrev = (tBp == a) ? b : tBp;//
    b->pNext = (tAn == b) ? a : tAn;//
   // b->pPrev = tAp;
   
    //tAn->pPrev = (tAp->pPrev == b) ? a : b; 
    tAp->pNext = (tAp->pNext == b) ? a : b;
   // tBn->pPrev = (tBn->pPrev == a) ? b : a;
    tBp->pNext = (tBp->pNext == a) ? b : a; */
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


//
void List::SortBySquare( ) {
 
    for (int i = 0; i < this->m_size; i ++) {
        Node *pNode = this->Head.pNext;

        do {
            Node *pNodeNext = pNode->pNext;

            if(*pNodeNext < *pNode) {   
                this->Swap(pNodeNext, pNode);  
            }
            pNode = pNodeNext; 

        } while(pNode && !pNode->isTail()) ;
     
    }
}