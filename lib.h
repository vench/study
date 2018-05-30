#pragma once

#include <iostream>
 
//Swap
template <class T> 
  void  Swap (T &a, T &b) {
  T tmp(std::move(a));  //move constructor
  a = std::move(b);     //move operator ==
  b = std::move(tmp);   //move operator ==
}


//MyStack Array



