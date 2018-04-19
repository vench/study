#pragma once

#include <iostream>
#include "myString.h" 

class MyData {
public:
    enum Sex { UNDEF, MALE, FMALE };
private:
    Sex sex;
    size_t m_age;
    MyString m_job;
    float m_salary;

public:
//Подумайте, все ли перечисленные ниже методы надо реализовывать
    MyData();
    MyData(Sex s, size_t age, const char* job, float sal);
    ~MyData ();
    MyData(const MyData& d);
    MyData & operator=(const MyData& d);
    MyData(MyData&& d);
    MyData & operator=(MyData&& d);
    
    friend std::ostream& operator<<(std::ostream& os, const MyData& d);

};
 
std::ostream& operator<< (std::ostream&, const MyData&);


