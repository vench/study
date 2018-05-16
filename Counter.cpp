

//Сместить всю логику

#include <cstring>
#include <iostream>

#include "Counter.h"

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
    if(this->pNext && this->pNext->m_nOwners <= 0) {
        Counter *updateNext = nullptr;
        if(this->pNext->pNext) {
            updateNext = this->pNext->pNext;
        }
        delete this->pNext;
        this->pNext = updateNext;
        
        if(this->pNext) {
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


