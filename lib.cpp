

#include "lib.h"

//
 void testArrayStack() {
    ArrayStack<int,10> min = makeArrayStackMax(); 
    ArrayStack<int,10> max = makeArrayStackMax();
    
    min = max;
}
 
 
//
 void testListStack() {
     std::cout << "=== testListStack ===" << std::endl;
    ListStack<int> min = makeListStackMin();
    ListStack<int> max = makeListStackMax();
    
    std::cout << min << std::endl;
    std::cout << max << std::endl;
    
    min = max;
    std::cout << "min = max" << std::endl;
    std::cout << min << std::endl;
    std::cout << max << std::endl;
    
    ListStack<int> min1 = makeListStackMin();
    ListStack<int> max1 = makeListStackMax();
    
    std::cout << min1 << std::endl;
    std::cout << max1 << std::endl;
    
    max1 = min1;
    std::cout << "max1 = min1" << std::endl;
    std::cout << min1 << std::endl;
    std::cout << max1 << std::endl;
    
    ListStack<int> max2 = makeListStackMax();
    ListStack<int> max21(max2);
    std::cout << "max21(max2)" << std::endl;
    std::cout << max21 << std::endl;
    
 } 
 
 
 //
 void testArrayQueue() {
    std::cout << "=== testArrayQueue ===" << std::endl;
    ArrayQueue<int> min = makeArrayQueue(5);
    ArrayQueue<int> max = makeArrayQueue(10);
    std::cout << min << std::endl;
    std::cout << max << std::endl;
    min = max;
    std::cout << "min = max" << std::endl;
    std::cout << min << std::endl;
    std::cout << max << std::endl;
    
    //
    ArrayQueue<int> min1 = makeArrayQueue(5);
    ArrayQueue<int> max1 = makeArrayQueue(10);
    
    std::cout << min1 << std::endl;
    std::cout << max1 << std::endl;
    
    max1 = min1;
    std::cout << "max1 = min1" << std::endl;
    std::cout << min1 << std::endl;
    std::cout << max1 << std::endl;
    
    //
    ArrayQueue<int> max2 = makeArrayQueue(10);
    ArrayQueue<int> max21(max2);
    std::cout << "max21(max2)" << std::endl;
    std::cout << max21 << std::endl;
    
    //
    std::cout << " max3 " << std::endl;
    ArrayQueue<int> max3 = makeArrayQueue(10);
    
    std::cout << max3 << std::endl;
    
    max3.pop(); 
    max3.pop(); 
    
    std::cout << max3 << std::endl;
    max3.push(100);
    max3.push(200);
    max3.push(300);
    max3.push(400);
    max3.push(500); /**/ 
    std::cout << max3 << std::endl; 
    
 };
 
 //
ListStack<int> makeListStackMin() {
    ListStack<int> l;
    for(int i = 0; i < AS_MIN; i ++) {
        l.push(i * i);
    }
    return std::move(l);
}

//
ListStack<int> makeListStackMax() {
   ListStack<int> l;
    for(int i = 0; i < AS_MAX; i ++) {
        l.push(i * i);
    }
    return std::move(l);
}
 
//
ArrayQueue<int> makeArrayQueue(const int size) {
    ArrayQueue<int> q(size);
    for(int i = 0; i < size; i ++) {
        q.push(i * i);
    }
    return q;
}

//
ArrayStack<int,AS_MAX> makeArrayStackMax(){
    ArrayStack<int,AS_MAX> max;
    for(int i = 0; i < AS_MAX; i ++) {
        max.push(i * i);
    }
    
    return max;      
}  
  
// 
ArrayStack<int,AS_MIN> makeArrayStackMin() {
    ArrayStack<int,AS_MIN> min;
    for(int i = 0; i < AS_MIN; i ++) {
        min.push(i * i);
    }
    
    return min;      
}  