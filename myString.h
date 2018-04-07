#pragma once

class MyString
{
    char* m_pStr;	//строка-член класса
    
    
    void copyValue(const char *c);

    public:
 
        MyString();
    
        MyString(const  MyString &s);
    
        explicit MyString(const char *c);    
    
        ~MyString(); 
        
        const char* GetString();
        
        void SetNewString(const char*);
        
        void ConcatString(const char*);
    
};


MyString CreateString(size_t number, ...);
