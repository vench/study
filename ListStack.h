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
    ListStack(const ListStack&);
    ListStack(ListStack&&);
    virtual ~ListStack();
    
    ListStack& operator=(const ListStack&);
    ListStack& operator=( ListStack&&);
    
    void push(const T&);
    T pop(); 
    bool isEmpty() const;
    void reverse();
    void copy(const ListStack&);
private:

};
 

//
template <class T>
ListStack<T>::ListStack() { 
    this->top = nullptr;
} 

//move
template <class T>
ListStack<T>::ListStack(ListStack&& orig) {
    this->top = orig.top;
    orig.top = nullptr;
}

//copy
template <class T>
ListStack<T>::ListStack(const ListStack& orig) {
    this->top = nullptr;
    this->copy(orig);
}

//
template <class T>
ListStack<T>& ListStack<T>::operator=(const ListStack& orig) {
    if(this != &orig) {
        this->copy(orig);
    }
    return *this;
}

//
template <class T>
ListStack<T>& ListStack<T>::operator=( ListStack&& orig) {
    
    if(this != &orig) {
        if(this->top) {
            delete this->top;
        }
        this->top = orig.top;
        orig.top = nullptr;
    }    

    return *this;
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
void ListStack<T>::copy(const ListStack& orig) {
    if(this->top) { //TODO
        delete this->top;
    }
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
    }; /**/
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
bool ListStack<T>::isEmpty() const {
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

