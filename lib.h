#pragma once

 

template <class T> 
  void  Swap (T &a, T &b) {
  T tmp = a;
  a = b;
  b = tmp; 
}