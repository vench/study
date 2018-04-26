#pragma once

#include <iostream>
#include "Counter.h"


class MyString
{ 
    
    static Counter head;  
    
    Counter *pStr;

    public:
 
        MyString();
    
        MyString(const  MyString &s);
        MyString(MyString &&s);    
        explicit MyString(const char *c);        
        ~MyString();         
        const char* GetString() const; 
        
        static void PrintAllString();
        static void ChnageRegisterAllString();
        static void ChnageSortAllString();
        
        friend std::ostream& operator<<(std::ostream&, const MyString&); 
    
};

std::ostream& operator<<(std::ostream&, const MyString&);

 
