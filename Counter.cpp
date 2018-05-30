

//Сместить всю логику

#include <cstring>
#include <iostream>

#include "Counter.h"


//как элемент каунтера
Counter Counter::head;

//
Counter::Counter() {
    char *c = new char[1];
    this->m_pStr = c;
    this->pNext = nullptr;
    this->m_nOwners = 1;
}

//
Counter::Counter(const  char *s) {
    int size = std::strlen(s) + 1; 
    this->m_pStr = new char[size]; 
    std::strcpy(this->m_pStr, s);
    this->pNext = nullptr;
    this->m_nOwners = 0;
}

//
Counter::Counter(const Counter& orig) {
    int size = std::strlen(orig.m_pStr) + 1; 
    this->m_pStr = new char[size]; 
    std::strcpy(this->m_pStr, orig.m_pStr);
    
    this->m_nOwners = orig.m_nOwners;
    this->pNext = orig.pNext;
}

//
Counter::~Counter() {
    if(this->m_pStr) {
        delete[] this->m_pStr;
        this->m_pStr = nullptr;
    } 
}

//
Counter* Counter::GetCounter(const  char * s) { 
    if(std::strcmp(s, this->m_pStr) == 0) {
        return this;
    }
    if(this->pNext) {
        return this->pNext->GetCounter(s);
    } 
    //new
    Counter *tmp = new Counter(s);
    this->pNext = tmp;
    return tmp;
}

//
void Counter::IncrementOwner() {
    this->m_nOwners ++;
}

//
void Counter::DecrementOwner() {
    this->m_nOwners --;  
    if(this->m_nOwners <= 0) {
        Counter::head.Optimize();
    } 
}

//
const char* Counter::GetString() const {
    return this->m_pStr;
}

//
int Counter::CountOwner() const {
    return this->m_nOwners;
}

//перестраиваем список от текущего элемента до конца
//удаляем следующий элемент если он неиспользуется
void Counter::Optimize() {
    if(this->pNext) { 
        if(this->pNext->m_nOwners <= 0) {
            Counter *updateNext = nullptr;
            if(this->pNext->pNext) {
                updateNext = this->pNext->pNext;
            }
            delete this->pNext;
            this->pNext = updateNext;
            
            if(this->pNext) {
                this->pNext->Optimize();
            }
            
        } else {
            this->pNext->Optimize();
        }  
    }    
}



//
void Counter::ChnageRegister() {
    for(int i = 0; i < std::strlen(this->m_pStr); i ++){ 
        if (std::isupper(this->m_pStr[i])) {
            this->m_pStr[i] = std::tolower(this->m_pStr[i]); 
        } else {
            this->m_pStr[i] = std::toupper(this->m_pStr[i]);
        }   
    }    
}


//statics

//
void Counter::PrintAllString() {
    Counter *pStr = Counter::head.pNext;
    
    std::cout << "Counter::PrintAllString();\n";
    
    while(pStr) { 
        std::cout << "Str: " << pStr->m_pStr << ", Owners: " << pStr->m_nOwners << ";\n";
        pStr = pStr->pNext;
    }    
}

//
void Counter::ChnageRegisterAllString() {
    Counter *pStr = Counter::head.pNext;
    
    std::cout << "Counter::ChnageRegisterAllString();\n";
    
    while(pStr) {         
        pStr->ChnageRegister();        
        pStr = pStr->pNext;
    }   
}

//
void Counter::Swap(Counter *a, Counter*b) {
    Counter *tmp = a->pNext;
    a->pNext = b;
    b->pNext = tmp;
}

//
void Counter::ChnageSortAllString() {
    
    std::cout << "--------- Counter Sort All---------- \n";
    Counter *root = Counter::head.pNext;
    Counter *q, *pNextNew = nullptr, *p, *pr;
    while (root !=nullptr) { 
        q = root; 
        root = root->pNext;
        for (p = pNextNew, pr = nullptr; 
                p != nullptr && std::strcmp(q->m_pStr,p->m_pStr) > 0; 
                pr = p,p = p->pNext); 
      
        if (pr == nullptr) {  //включение в начало | первый шаг
            q->pNext = pNextNew; 
            pNextNew = q; 
        } else { 
            q->pNext = p; 
            pr->pNext = q; 
        } //или после предыдущего
    } 
    Counter::head.pNext = pNextNew;
    
}

