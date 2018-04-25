

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
    } else {
        Node *tmpAPrev = a->pPrev;
        Node *tmpANext = a->pNext;
        Node *tmpBPrev = b->pPrev;
        Node *tmpBNext = b->pNext;
        
        b->pNext = tmpANext;
        b->pPrev = tmpAPrev;
        a->pNext = tmpBNext;
        a->pPrev = tmpBPrev;
        
        tmpANext->pPrev = b;
        tmpAPrev->pNext = b;
        tmpBNext->pPrev = a;
        tmpBPrev->pNext = a;
    } 
}

//
std::ostream& operator<< (std::ostream& stream, const List& l) {
    stream << "radius, x, y\n";
    const Node *pNode = l.Head.GetNext();
    while(pNode && !pNode->isTail()) {
        stream << *pNode;  
        pNode = pNode->GetNext();
    } 
     
    return stream;
}

//
void operator<<(List& l, std::istream& s) {
    const int n = 128;
    int r,x,y = 0;
  
    char *line = new char[n];
    s.getline(line, n);//skip header
    while(!s.eof()) { 
        s.getline(line, n);         
        if(sscanf (line,"%d,%d,%d\n",&r, &x, &y) >= 0) {
            Circle c(x, y, r);
            l.AddToTail(&c);
        }        
    }
    delete[] line;
}

//
void List::SortBySquare( ) { 
     Node *pNode = this->Head.pNext;
     Node *pNodeNext;

     while(!pNode->isTail() && !(pNodeNext = pNode->pNext)->isTail()) {  
        
        if(*pNodeNext < *pNode) {   
            this->Swap(pNodeNext, pNode); 
                
            if (pNodeNext->pPrev && !pNodeNext->pPrev->isHead()) {
                pNode = pNodeNext->pPrev;
                continue;
            }  
        } 
        
        pNode = pNodeNext; 
    }    
}