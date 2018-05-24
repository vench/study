#pragma once

#include <iostream>
#include <exception>
#include "StackException.h"

template <class T>
class ArrayQueue {
    
    T*list;
    unsigned int listSize = 0; 
    unsigned int listCapa; 
    unsigned int listFirst;
    unsigned int listLast;
    
public:
    ArrayQueue(const unsigned int);
    ArrayQueue(const ArrayQueue& orig);
    virtual ~ArrayQueue();
    
    void push(const T&);
    T& pop();
    T& operator[](int);
    bool isEmpty();
    bool isFull();
    
private:

};
 
//
template <class T>
ArrayQueue<T>::ArrayQueue(const unsigned int size) {
    this->listCapa = size; 
    this->listFirst = this->listCapa - 1;
    this->list = new T[this->listCapa]();
}


//
template <class T>
ArrayQueue<T>::~ArrayQueue() {
    if(this->list) { 
        delete[]this->list;
    }
}


//
template <class T>
void ArrayQueue<T>::push(const T& val) {
    //if(this->isFull()) {//TODO relocate size
      //  throw StackException("Queue is full");
    //}
    this->listFirst = (this->listFirst + 1) % this->listCapa;
    this->list[this->listFirst] = val;
    
   // this->listLast = 0;
    if(this->isFull()){
        this->listLast = (this->listLast + 1) % this->listCapa;
    } else {
        this->listSize ++;
    }    
}

//
template <class T>
T& ArrayQueue<T>::pop() {
    if(this->isEmpty()) {
        throw StackException("Queue is empty");
    }
    
    int index = this->listLast; 
    this->listLast = (this->listLast + 1) % this->listCapa;
    this->listSize --;
    return this->list[index];
}


//
template <class T>
T& ArrayQueue<T>::operator[](int index) {
    if(index >= 0 && index < this->listSize) {
        throw StackException("Out of range");
    }
    return this->list[index];
}

//
template <class T>
bool ArrayQueue<T>::isFull() {
    return this->listCapa == this->listSize;
}
//
template <class T>
bool ArrayQueue<T>::isEmpty() {
    return (this->listSize == 0);
}
