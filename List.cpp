//
#include "List.h"

//
List::List() : Head(Node::HEAD), Tail(Node::TAIL){     
    this->m_size = 0;    
    Head.pNext = &Tail;
    Tail.pPrev = &Head;    
}

//copy constr
List::List(const List& orig) : Head(Node::HEAD), Tail(Node::TAIL){ 
    this->m_size = 0;
    
    Head.pNext = &Tail;
    Tail.pPrev = &Head;
    
   this->Copy(orig); 
}

//move constructor
List::List( List&& copy) {
    this->Clear();
    this->Head = copy.Head;
    this->Tail = copy.Tail;
    
    copy.Head.pNext = &copy.Tail;
    copy.Tail.pPrev = &copy.Head; 
}

//move 
List& List::operator=( List&& copy) {
    if(this != &copy) { 
        this->Clear(); 
        this->Head = copy.Head;
        this->Tail = copy.Tail;
        this->m_size = copy.m_size;

        copy.Head.pNext = &copy.Tail;
        copy.Tail.pPrev = &copy.Head;
        copy.m_size = 0;
    }
    return *this;
}

//copy
List& List::operator=(const List& copy) {  
    if(this != &copy) { 
        this->Copy(copy);
    }    
    return *this;
}

//
void List::Copy(const List& copy) {
    this->m_size = copy.m_size;
   
    Node *pNode = &this->Head; 
    const Node *pCopy = copy.Head.pNext; 
       
    while((pNode = pNode->pNext)  && !pNode->isTail()) { 
     
        if(!pCopy || pCopy->isTail()) {   //delete pNode
            Node *tmp = pNode->pPrev;
            this->Remove(pNode->m_Data);
            pNode = tmp;
        } else {  //copy  
            pNode->m_Data = pCopy->m_Data->Clone();//TODO thing
            pCopy = pCopy->pNext;
        }  
    }
     
    
    while(pCopy && !pCopy->isTail()) { 
        this->AddToTail(pCopy->m_Data->Clone());
        pCopy = pCopy->pNext; 
    }
}

//
List::~List() {
    this->Clear();     
}

//
void List::AddToHead(Shape *c) { 
    Node *pNewNode = new Node(c);
    
    Node *pTmpNext = this->Head.pNext;
    this->Head.pNext = pNewNode;
    pNewNode->pPrev = &this->Head;
    
    pNewNode->pNext = pTmpNext;
    pTmpNext->pPrev = pNewNode;
    
    this->m_size ++;
}
    
//
void List::AddToTail(Shape *c) {
    Node *pNewNode = new Node(c);    
    Node *pTmpPrev = this->Tail.pPrev;
    this->Tail.pPrev = pNewNode;
    pNewNode->pNext = &this->Tail;
    
    pNewNode->pPrev = pTmpPrev;
    pTmpPrev->pNext = pNewNode;
    
    this->m_size ++;
}

//
bool List::Remove(const Shape* c) {
    return RemoveAll(c, 1);
}
    
//
int List::RemoveAll(const Shape* c) { 
    return RemoveAll(c, this->m_size);
}

//
int List::RemoveAll(const Shape* c, int limit) {
    int count = 0; 
    Node *pNode = this->Head.pNext;
    while(limit > 0 && pNode  && !pNode->isTail()) { 
        if(c->IsEqual(pNode->m_Data)) {
            Node *pTmpNext = pNode->pNext;
            Node *pTmpPrev = pNode->pPrev;
            pTmpNext->pPrev = pTmpPrev;
            pTmpPrev->pNext = pTmpNext;
            
            delete pNode;  
            pNode = pTmpPrev;
            this->m_size --;
            count ++;
            limit --;
        }         
        pNode = pNode->pNext;
    }   
    
    return count;
}

     
//
void List::Clear() {
    Node *pNode = &this->Head;
    while((pNode = pNode->pNext)  && !pNode->isTail()) { 
       delete pNode;  
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
    stream << "List - size: " << l.m_size << "\n";
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
    Circle circle(0,0,0);
    Rect rect;
  
    char *line = new char[n];
    s.getline(line, n);//skip header
    while(!s.eof()) { 
        s.getline(line, n);         
        if(circle.UnSerialuze(line)) { 
            l.AddToTail(&circle);
        } else if(rect.UnSerialuze(line)) { 
            l.AddToTail(&rect);
        }         
    }
    delete[] line; 
}

//
bool List::cmpByColor(const Node* a, const Node* b) {
    return a->m_Data->getColor() < b->m_Data->getColor();
}

//
bool List::cmpBySquare(const Node* a, const Node* b) {
    return a->m_Data->GetSquare() < b->m_Data->GetSquare();
}

//
void List::SortBy( bool(List::*cmp)(const Node*, const Node*) ) {
    Node *pNode = this->Head.pNext;
    Node *pNodeNext;

    while(!pNode->isTail() && !(pNodeNext = pNode->pNext)->isTail()) {  
        
        if((this->*cmp)(pNodeNext, pNode)) {   
            this->Swap(pNodeNext, pNode); 
                
            if (pNodeNext->pPrev && !pNodeNext->pPrev->isHead()) {
                pNode = pNodeNext->pPrev;
                continue;
            }  
        } 
        
        pNode = pNodeNext; 
    }
}

//
void List::SortBySquare( ) {  
    this->SortBy(&List::cmpBySquare);
}

//
void List::SortByColor() {
    this->SortBy(&List::cmpByColor);
}


//
List testMoveList(){
    Circle c1 (10,10, 50);
    List list;
    list.AddToHead(&c1);
    return list;
}