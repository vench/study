#include <string>
#include "myString.h" 
#include <cstdarg> 
#include <cstring> 


using namespace std;

//
MyString::MyString() {
    this->copyValue("");
};

// Определение конструктора.
 MyString::MyString(const  MyString &s) {
      this->copyValue(s.m_pStr);
 };
 
 //
 MyString::MyString(const char *c) {
     this->copyValue(c); 
 };

//
void MyString::copyValue(const char *c) {
    int size = 1; 

    while(*c++) {
        size ++;
    }

    m_pStr = new char[size]; 
    for(; size >= 0; size --)   {
        m_pStr[size] = *c--;        
    }   
}; 
 

// Определение деструктора.
MyString::~MyString() {
    delete[] this->m_pStr;
};

//
const char* MyString::GetString() { 
    return this->m_pStr;
};

//
void MyString::SetNewString(const char *c) {
     delete[] this->m_pStr;
    this->copyValue(c);
};

//
void MyString::ConcatString(const char *c){
    std::strcat(m_pStr, c); 
};


//
MyString * CreateString(size_t number, ...) {
    MyString *s = new MyString("");
    va_list argList;
    va_start(argList, number);
    
    for(size_t i = 1; i <= number; i ++) {
        const char* c = va_arg(argList, const char*);
        s->ConcatString(c);
    }
    
    va_end(argList); 
    return s;
};
