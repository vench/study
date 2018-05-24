#pragma once

#include <iostream>
#include <exception>
#include "StackException.h"

template <class T>
class ListStack {
    
    
    class Node {
    public:
        T data;
        Node *next;
        
        Node(T data) {
            this->data = data;
            this->next = nullptr;
        };
        
        ~Node() {
            if(this->next) {
                delete this->next;
                this->next = nullptr;
            }
        };
    };
    
    Node *top;
    
    
public:
    ListStack();
    ListStack(const ListStack& orig);
    virtual ~ListStack();
    
    void push(const T&);
    T pop(); 
    bool isEmpty();
private:

};
 

//
template <class T>
ListStack<T>::ListStack() { 
    this->top = nullptr;
} 

//
template <class T>
ListStack<T>::ListStack(const ListStack& orig) {
    //TODO copy list
}

//
template <class T>
ListStack<T>::~ListStack() { 
    if(this->top) {
        delete this->top;
        this->top = nullptr;
    }
}

//
template <class T>
void ListStack<T>::push(const T &val) { 
    Node* n = new Node(val);         
    n->next = this->top; 
    this->top = n;
}

//
template <class T>
T ListStack<T>::pop() {
    if(this->top) {
        Node *tmp = this->top;
        T data = tmp->data;
        this->top = tmp->next;
        tmp->next = nullptr;
        delete tmp;
        return data;
    } 
    throw StackException("Stack is empty");     
}

//
template <class T>
bool ListStack<T>::isEmpty() {
    return !(this->top);
}



