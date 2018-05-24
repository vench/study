#pragma once

#include <iostream>
#include <exception>
#include "StackException.h"



template <class T>
class ArrayStack {
    
     T*list;
     unsigned int listCapa;
     unsigned int listSize;
public:
    ArrayStack(const unsigned int);
    ArrayStack(const ArrayStack& orig);
    ArrayStack(ArrayStack&& orig);
    virtual ~ArrayStack();
    
    void push(const T&);
    T& pop();
    T& operator[](int);
    bool isEmpty();
private:

   
};



//
template <class T>
ArrayStack<T>::ArrayStack(const unsigned int size) {
    this->listCapa = size;
    this->listSize = 0;
    this->list = new T[this->listCapa]();
} 


//copy
template <class T>
ArrayStack<T>::ArrayStack(const ArrayStack& orig) {
    
    if(this->list) { 
        delete[]this->list;
    }
    
    this->listCapa = orig.listCapa;
    this->listSize = orig.listSize;
    
    this->list = new T[this->listCapa]();
    for(int i = 0; i < this->listSize; i ++) {
           this->list[i] = orig.list[i];
    }
}
 
//move
template <class T>
ArrayStack<T>::ArrayStack(ArrayStack&& orig) {
    if(this->list) { 
        delete[]this->list;
    }
    
    this->listCapa = orig.listCapa;
    this->listSize = orig.listSize;
    this->list = orig.list;
    orig.list = nullptr;
}
 
//
template <class T>
ArrayStack<T>::~ArrayStack() {
    if(this->list) { 
        delete[]this->list;
    }
}

//
template <class T>
void ArrayStack<T>::push(const T &val) { 
    if(this->listCapa > this->listSize) {
        this->list[this->listSize] = val; 
        this->listSize ++;
    } else {
        throw StackException("Out of range");
    }    
}

//
template <class T>
T& ArrayStack<T>::pop() {
    if(this->listSize > 0) {
        this->listSize --;
        return this->list[this->listSize];
    } 
    throw StackException("Stack is empty");     
}

//
template <class T>
T& ArrayStack<T>::operator[](int index) {
    if(this->listSize > index && index >= 0) {
        return this->list[index];        
    }
    throw StackException("Stack is empty");
}

//
template <class T>
bool ArrayStack<T>::isEmpty() {
    return this->listSize <= 0;
}



 

