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
    T back();
    bool isEmpty() const;
    void reverse();
    void copy(const ListStack&);
    
    friend std::ostream& operator<<(std::ostream& out,  ListStack<T>& s) {
        out << "ListStack: <T>" << std::endl;
        Node *t = s.top;
        
        while (t) {
            out <<  t->data << ",";
            t = t->next;
        }
         
        
        return out; 
    };
    
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
    if(this->top) { //TEST memory
        delete this->top;
        this->top = nullptr;
    }
}

//
template <class T>
void ListStack<T>::copy(const ListStack& orig) {
     
    Node *tTop = this->top;
    Node *oTop = orig.top;
    Node *tTopPrev = nullptr;     
    
    while(tTop && oTop) {
        
        tTop->data = oTop->data; 
        
        tTopPrev = tTop;
        tTop = tTop->next;
        oTop = oTop->next;        
    }; 
    
    if(!oTop && tTop) { //удаляем хвост this
        
        delete tTop;
        tTopPrev->next = nullptr;
        
    } else if(oTop) { //дополняем элементами из orig
       
        do {
            
            if(!this->top) {
                this->top = new Node(oTop->data);
                tTopPrev = this->top;
            } else {
                tTopPrev->next = new Node(oTop->data);
                tTopPrev = tTopPrev->next; 
            } 
             
        } while((oTop = oTop->next));
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


//
template <class T>
T ListStack<T>::back() {
    if(this->top) {
        Node *tmp = this->top;
        Node *tmpPrev = tmp;
        while ( tmp->next) {
            tmpPrev = tmp;
            tmp = tmp->next;
        }; 
        T data = tmp->data; 
        if(tmpPrev != this->top) {
            tmpPrev->next = nullptr;
        } else {
            this->top = nullptr;
        }
        delete tmp;
        return data;
    } 
    throw StackException("Stack is empty");     
}

