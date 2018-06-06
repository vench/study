#pragma once

#include <iostream>
#include "Counter.h"


class MyString
{ 
    
     
    
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
        
        MyString& operator=(const MyString&);
        MyString& operator=( MyString&&);
        MyString& operator=(const char *c);
        const char operator[](int); 
        
        friend std::ostream& operator<<(std::ostream&, const MyString&); 
    
};

std::ostream& operator<<(std::ostream&, const MyString&);

 
