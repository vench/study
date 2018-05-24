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
    void reverse();
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
    this->top = nullptr;
    if(orig.isEmpty()) {
        return;
    }
    
    Node *tmp = orig.top; 
    Node *head = new Node(tmp->data);
    this->top = head;
    
    while((tmp = tmp->next)) {
        head->next = new Node(tmp->data);
        head = head->next;  
    };
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

//
template <class T>
void ListStack<T>::reverse() {
    ListStack<T> tmp;
    while(!this->isEmpty()) { 
        tmp.push( this->pop() );
    }
    
    delete this->top;
    this->top = tmp.top;
    tmp.top = nullptr;
}

