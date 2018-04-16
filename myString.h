#pragma once

#include <string> 
#include <cstdarg> 
#include <cstring> 
#include <iostream>

class MyString
{
    char* m_pStr;	//строка-член класса
    
    
    void copyValue(const char *c);

    public:
 
        MyString();
    
        MyString(const  MyString &s);
        MyString(MyString &&s);
    
        explicit MyString(const char *c);    
    
        ~MyString(); 
        
        const char* GetString();
        
        void SetNewString(const char*);
        
        void ConcatString(const char*);
        
        
        MyString& operator=(const MyString&);
        MyString& operator=(const char*);
        //operator=(MyString const&);
    
};


MyString CreateString(size_t number, ...);
