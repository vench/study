// LAB 6.

#include <fstream>
#include <typeinfo>
#include "Point.h"
#include "Circle.h" 
#include "Shape.h"
#include "Rect.h"
#include "Node.h"
#include "List.h"

#define	  stop 

//
int main(int argc, char* argv[])
{

    {
        Circle c1 (0,0, 1);
        Rect r1  (1,4,1,4); 
        Rect r2  (1,43,1,42);
        Rect *pR3 = new Rect(1,1,1,1);
        
        List list; 
        list.AddToHead(&r1);
        list.AddToHead(&r2);
        list.AddToHead(&c1);  
        list.AddToHead(pR3);
        delete pR3;
        pR3 = nullptr;
        
        std::cout << list << std::endl;   
        
        list.SortBySquare();
        std::cout << list << std::endl;
        
    }

    {
        
        Circle c1(0,0, 1);
        Circle c2(0,0, 2);
        Rect r1(0,0, 3,0);
        Circle c4(0,0, 4);
        Circle c5(0,0, 5);
        
        List min;
        min.AddToTail(&c1);
        List big; 
        big.AddToTail(&c2);
        big.AddToTail(&r1);
        big.AddToTail(&c4);
        big.AddToTail(&c5);
        
       
        List minCopy = min;
        std::cout << "testMoveList" << std::endl;
        minCopy = testMoveList();
        List bigCopy = List(big);
        
    
        std::cout << "Min copy\n" << minCopy << std::endl;
        //std::cout << "Big copy\n" << bigCopy << std::endl;
       
        minCopy = bigCopy;
        std::cout << "minCopy = bigCopy >>> " << std::endl;
        std::cout << "Min copy\n" << minCopy << std::endl;
        //std::cout << "Big copy\n" << bigCopy << std::endl;
        
        std::cout << "Min copy\n" << min << std::endl;
        std::cout << "Big copy\n" << big << std::endl;
         
        big = min;
        std::cout << "min = big >>> " << std::endl;
        std::cout << "Min copy\n" << min << std::endl;
        std::cout << "Big copy\n" << big << std::endl; 
         /* */
    }
    ///
    
    //1. сортировку по возрастанию площади объекта.
    {
    
        
        List list;
        for (int i = 0; i < 8; i ++) {
            Circle c(0,0, i*i);
            if (i % 2 == 0) {
                list.AddToTail(&c);
            } else {
                list.AddToHead(&c);
            } 
        }
        
        for (int i = 10; i < 18; i ++) {
            Rect r(0,i, 0, i, i % 2 == 0 ? Shape::BLUE : Shape::RED);
            if (i % 2 == 0) {                
                list.AddToTail(&r);
            } else {
                list.AddToHead(&r);
            } 
        }
        
        
        std::cout << list << std::endl;
        
        //list.SortBySquare();
        list.SortByColor();
        
        std::cout << list << std::endl;
        
        //save list
        { 
            std::cout << "Enter Output File Name  - " ;
            char ar[80] = "test.txt";
            //std::cin >> ar;
            std::cout << "Save data to - "  << ar << "\n";
            std::ofstream fout(ar);
            fout << list;
            fout.close();
            
            //LOAD
            std::cout << "Load data from - "  << ar << "\n";
            List nList;
            std::ifstream fin(ar, std::ifstream::in);           
            nList << fin;            
            fin.close();
            
            std::cout << nList;
          
        } 
    }/**/
/**/	
    return 0;
}//endmain

