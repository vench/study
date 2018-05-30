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
    ArrayQueue( ArrayQueue&& orig);
    virtual ~ArrayQueue();

    ArrayQueue& operator=(const ArrayQueue&);
    ArrayQueue& operator=( ArrayQueue&&);
    
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

//copy
template <class T>
ArrayQueue<T>::ArrayQueue(const ArrayQueue& orig) { 
    this->listCapa = orig.listCapa;
    this->listSize = orig.listSize;
    this->listFirst = orig.listFirst;
    this->listLast = orig.listLast;
    
    
    this->list = new T[this->listCapa]();
    for(int i = 0; i < this->listCapa; i ++) {
        this->list[i] = orig.list[i]; 
    }
}

//move
template <class T>
ArrayQueue<T>::ArrayQueue( ArrayQueue&& orig) {
    this->listCapa = orig.listCapa;
    this->listSize = orig.listSize;
    this->listFirst = orig.listFirst;
    this->listLast = orig.listLast;
    
    this->list = orig.list;
    orig.list = nullptr;
}

//
template <class T>
ArrayQueue<T>& ArrayQueue<T>::operator=(const ArrayQueue& orig) {
    if(this->list) { 
        delete[]this->list;
    }
    this->listCapa = orig.listCapa;
    this->listSize = orig.listSize;
    this->listFirst = orig.listFirst;
    this->listLast = orig.listLast;
    
    this->list = new T[this->listCapa]();
    for(int i = 0; i < this->listCapa; i ++) {
        this->list[i] = orig.list[i];
    }
    return *this;
}

//
template <class T>
ArrayQueue<T>& ArrayQueue<T>::operator=( ArrayQueue&& orig) {
    if(this->list) { 
        delete[]this->list;
    }
    this->listCapa = orig.listCapa;
    this->listSize = orig.listSize;
    this->listFirst = orig.listFirst;
    this->listLast = orig.listLast;
    
    this->list = orig.list;
    orig.list = nullptr;
    return *this;
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
    if(this->isFull()) { //resize
        int length = this->listCapa + this->listCapa;        
        T*l = new T[length]();
        //copy 
        for(int n = 0; n < this->listSize; n ++){            
            l[n] = this->list[this->listLast];
            this->listLast = (this->listLast + 1) % this->listSize;
        } 
        delete[] this->list;
        this->list = l; 
        this->listCapa = length;
        this->listLast = 0;
        this->listFirst = this->listCapa + this->listSize - 1;  
    }
    this->listFirst = (this->listFirst + 1) % this->listCapa;
    this->list[this->listFirst] = val;     
    this->listSize ++; 
}
/*
// Round queue
template <class T>
void ArrayQueue<T>::push(const T& val) {
    this->listFirst = (this->listFirst + 1) % this->listCapa;
    this->list[this->listFirst] = val;
     
    if(this->isFull()){
        this->listLast = (this->listLast + 1) % this->listCapa;
    } else {
        this->listSize ++;
    }    
}
*/

///
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
    if(index < 0 || index >= this->listSize) {
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
