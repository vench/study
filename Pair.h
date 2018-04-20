#pragma once

#include <iostream>
#include "myString.h" 
#include "MyData.h" 

class Base;

class Pair {
    MyString key;
//ключ - фамилия
    MyData data; //данные о сотруднике
//Подумайте, все ли перечисленные ниже методы надо реализовывать
    //Pair(); Такой конструктор ненужен
    Pair(const char *k, const MyData& d);
    ~Pair();
    Pair(const Pair& other);
    Pair& operator=(const Pair& other);
    Pair(Pair&& other);
    Pair& operator=(Pair&& other);
    bool operator==(const char *k) const;
    
    
    friend class Base;    
    friend std::ostream& operator<<(std::ostream& os, const Pair& pair);

};


std::ostream& operator<< (std::ostream&, const Pair&);
 

