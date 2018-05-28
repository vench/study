#pragma once

#include <iostream>
#include <exception>
#include "StackException.h"



template <class T, unsigned int SIZE>
class ArrayStack {
    
     T list[SIZE]; 
     unsigned int listSize;
public:
    ArrayStack();
    ArrayStack(const ArrayStack& orig);
    ArrayStack(ArrayStack&& orig);
    virtual ~ArrayStack();
    
    ArrayStack& operator=(const ArrayStack&);
    ArrayStack& operator=( ArrayStack&&);
    
    void push(const T&);
    T& pop();
    T& operator[](int);
    bool isEmpty();
private:

   
};



//
template <class T, unsigned int SIZE>
ArrayStack<T,SIZE>::ArrayStack() { 
    this->listSize = 0; 
} 


//copy
template <class T, unsigned int SIZE>
ArrayStack<T,SIZE>::ArrayStack(const ArrayStack& orig) { 
    this->listSize = orig.listSize;
    
    this->list = new T[SIZE]();
    for(int i = 0; i < this->listSize; i ++) {
           this->list[i] = orig.list[i];
    }
}
 
//move
template <class T, unsigned int SIZE>
ArrayStack<T,SIZE>::ArrayStack(ArrayStack&& orig) {      
    this->listSize = orig.listSize;
    this->list = orig.list;
    orig.list = nullptr;
}
 
//
template <class T, unsigned int SIZE>
ArrayStack<T,SIZE>& ArrayStack<T,SIZE>::operator=(const ArrayStack& orig) {
    if(this != &orig) {   
        for(int i = 0; i < SIZE; i ++) { 
           this->list[i] = orig.list[i];
        }  
        this->listSize = orig.listSize;
    }
    return *this;
}

//
template <class T, unsigned int SIZE>
ArrayStack<T,SIZE>& ArrayStack<T,SIZE>::operator=( ArrayStack&& orig) {
    if(this != &orig) { 
        this->listSize = orig.listSize;
        for(int i = 0; i < SIZE; i ++) { 
           this->list[i] = orig.list[i];
        }  
    }    
    return *this;
}

//
template <class T, unsigned int SIZE>
ArrayStack<T,SIZE>::~ArrayStack() { 
}

//
template <class T, unsigned int SIZE>
void ArrayStack<T,SIZE>::push(const T &val) { 
    if(SIZE > this->listSize) {
        this->list[this->listSize] = val; 
        this->listSize ++;
    } else {
        throw StackException("Out of range");
    }    
}

//
template <class T, unsigned int SIZE>
T& ArrayStack<T,SIZE>::pop() {
    if(this->listSize > 0) {
        this->listSize --;
        return this->list[this->listSize];
    } 
    throw StackException("Stack is empty");     
}

//
template <class T, unsigned int SIZE>
T& ArrayStack<T,SIZE>::operator[](int index) {
    if(this->listSize > index && index >= 0) {
        return this->list[index];        
    }
    throw StackException("Stack is empty");
}

//
template <class T, unsigned int SIZE>
bool ArrayStack<T,SIZE>::isEmpty() {
    return this->listSize <= 0;
}



 

