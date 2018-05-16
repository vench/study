#include <string>
#include "myString.h" 
#include <cstdarg> 
#include <cstring> 
#include <iostream>


using namespace std;

//как элемент каунтера
Counter MyString::head;




//
MyString::MyString() {
    this->pStr = nullptr;
};

// Определение конструктора.
 MyString::MyString(const  MyString &s) { 
    
    this->pStr = MyString::head.GetCounter(s.GetString());
    this->pStr->IncrementOwner(); 
 };
 
 //
 MyString::MyString(const char *c) {
    this->pStr = MyString::head.GetCounter(c);
    this->pStr->IncrementOwner(); 
 };

MyString::MyString(MyString &&s) {  
     this-> pStr = s.pStr; 
     s.pStr = nullptr; 
}


 

// Определение деструктора.
MyString::~MyString() {
    if(this-> pStr) {
        this-> pStr->DecrementOwner(); 
        if(this->pStr->CountOwner() <= 0) {
            MyString::head.Optimize();
        }        
    }
};

//
const char* MyString::GetString() const { 
    if(this-> pStr) { 
        return this-> pStr->GetString();
    }
    return nullptr;
};

//
void MyString::PrintAllString() {
    Counter *pStr = MyString::head.pNext;
    
    std::cout << "MyString::PrintAllString();\n";
    
    while(pStr) { 
        std::cout << pStr->m_pStr << "  " << pStr->m_nOwners << "\n";
        pStr = pStr->pNext;
    }    
}

//
void MyString::ChnageRegisterAllString() {
    Counter *pStr = MyString::head.pNext;
    
    std::cout << "MyString::ChnageRegisterAllString();\n";
    
    while(pStr) {         
        pStr->ChnageRegister();        
        pStr = pStr->pNext;
    }    
}



//
void MyString::ChnageSortAllString() {
    //TODO
    std::cout << "MyString::ChnageSortAllString();\n";
    Counter *head = &MyString::head;
    Counter *pStr = head->pNext;
    Counter *pStrNext = nullptr;
    
    //    xyz, abc, def 
    for(int i = 0; i < 9; i ++) {
        pStr = MyString::head.pNext;
      
        
        while((pStrNext = pStr->pNext)) {
            
            if(std::strcmp(pStrNext->m_pStr, pStr->m_pStr) < 0) {  //swap
                Counter *tmp = pStrNext->pNext;
                pStrNext->pNext = pStr;
                pStr->pNext = tmp;
                head->pNext = pStrNext; 
            } else { 
                head = pStr; 
            }
            pStr = pStrNext; 
        } 
        
        head = pStr; 
    }  
    //}
    
}


//
std::ostream& operator<<(std::ostream& stream, const MyString& s) {
    stream << s.GetString();
    return stream;
}
 