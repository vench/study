// LAB 4.

#include "Point.h"
#include "Circle.h" 
#include "Node.h"
#include "List.h"

#define	  stop 

int main(int argc, char* argv[])
{


    {
    
        Circle c(10,10, 100);
        std::cout << c << std::endl;
        
    }
    
    //Node
    {
    
        Circle c(10,10, 100);
        Node n(&c);
        
        std::cout << n << std::endl; 
    }
    
    //list
    {
        
        Circle c(10,10, 100);
        Circle c1(10,10, 120);
        Circle c2(10,10, 140);
        Circle c3(10,10, 160);
        List list;
        list.AddToHead(&c);
        list.AddToHead(&c1);
        list.AddToHead(&c2);
        
        std::cout << list << std::endl; //140, 120, 100
        
        list.AddToTail(&c);
        list.AddToTail(&c1);
        list.AddToTail(&c2);
        
        std::cout << list << std::endl; //140, 120, 100, 100, 120, 140
        
        
        list.Remove(&c3);//nothing
        list.Remove(&c1);//
        std::cout << list << std::endl; //140,  100, 100, 120, 140
        list.RemoveAll(&c2);//
        std::cout << list << std::endl; // 100, 100, 120
        
        list.Clear();
        
        std::cout << list << std::endl; //empty
        
        list.AddToTail(&c3);
        
        std::cout << list << std::endl; //160
    }
	
    return 0;
}//endmain

