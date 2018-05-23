#pragma once

class MyString;

class Counter {
    
    static Counter head; 
    
    char* m_pStr;
    int m_nOwners;
    Counter* pNext;
    
    void Optimize();
    
public:
    Counter();
    Counter(const  char * s);
    Counter(const Counter& orig);
    ~Counter();
    
    int CountOwner() const;
    void IncrementOwner();
    void DecrementOwner();
    const char* GetString() const; 
    Counter* GetCounter(const  char * s);
    void ChnageRegister();
   
    static void PrintAllString();
    static void ChnageRegisterAllString();
    static void ChnageSortAllString();
    static void Swap(Counter *, Counter*);
    
    friend MyString;
    
private:

};
 

