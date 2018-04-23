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
        
    }
	
    return 0;
}//endmain

