#pragma once

#include <iostream>
#include "ArrayStack.h"
#include "ListStack.h"
#include "ArrayQueue.h"
 
//Swap
template <class T> 
  void  Swap (T &a, T &b) {
  T tmp(std::move(a));  //move constructor
  a = std::move(b);     //move operator ==
  b = std::move(tmp);   //move operator ==
}


//MyStack Array

const unsigned int AS_MIN = 5; 
const unsigned int AS_MAX = 10; 
 
ArrayStack<int,AS_MIN> makeArrayStackMin();
ArrayStack<int,AS_MAX> makeArrayStackMax();

ListStack<int> makeListStackMin();
ListStack<int> makeListStackMax();
ArrayQueue<int> makeArrayQueue(const int);

void testArrayStack();
void testListStack();
void testArrayQueue();



