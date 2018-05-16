// LAB 4.

#include <fstream>
#include "Point.h"
#include "Circle.h" 
#include "Node.h"
#include "List.h"

#define	  stop 

int main(int argc, char* argv[])
{


    {
    
        Circle c(10,10, 100);
      //  std::cout << c << std::endl;
        
    }
    
    //Node
    {
    
        Circle c(10,10, 100);
     //   Node n(&c);
        
        //std::cout << n << std::endl; 
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
        
        //std::cout << list << std::endl; //140, 120, 100
        
        list.AddToTail(&c);
        list.AddToTail(&c1);
        list.AddToTail(&c2);
        
        //std::cout << list << std::endl; //140, 120, 100, 100, 120, 140
        
        
        list.Remove(&c3);//nothing
        list.Remove(&c1);//
        //std::cout << list << std::endl; //140,  100, 100, 120, 140
        list.RemoveAll(&c2);//
        //std::cout << list << std::endl; // 100, 100, 120
        
        //list.Clear();
        
        //std::cout << list << std::endl; //empty
        
        list.AddToTail(&c3);
        
       // std::cout << list << std::endl; //160
        
       
        List list2; 
        Circle ct(10,10, 100);
        list2.AddToHead(&ct);
        
        list2 = list;
        std::cout << list << " ### " << std::endl;
        std::cout << list2 << " *** " << std::endl;
        
        List list3;
        list3.AddToHead(&c1);
        list3.AddToHead(&c2);
        list3.AddToHead(&c3); 
        
        /*
        std::cout << list << " *** " << std::endl;
        std::cout << list3 << " *** " << std::endl;
        list = std::move(list3);
        std::cout << list << "  list = list3 " << std::endl;
        std::cout << list3 << " list3 " << std::endl;
        */
        List list4(std::move(list)); //std::move
         std::cout << " list "  << list << std::endl;
         std::cout << " list4 "  << list4 << std::endl;
         
        list4 = std::move(list3);//std::move
        
        std::cout << " list3 "  << list3 << std::endl;
        std::cout << " list4 "  << list4 << std::endl;
        
        List list5(std::move(list));
        list5.AddToHead(&c1);
        std::cout << " list5 "  << list5 << std::endl;
        list5 = std::move(list3); //std::move
        
         std::cout << " list5 "  << list5 << std::endl;
        std::cout << " list3 "  << list3 << std::endl;
    }
    
    
    //
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
        
        //std::cout << list << std::endl; //140, 120, 100
        
        list.AddToTail(&c);
        list.AddToTail(&c1);
        list.AddToTail(&c2);
        
        //std::cout << list << std::endl; //140, 120, 100, 100, 120, 140
        
        
        list.Remove(&c3);//nothing
        list.Remove(&c1);//
        //std::cout << list << std::endl; //140,  100, 100, 120, 140
        list.RemoveAll(&c2);//
        //std::cout << list << std::endl; // 100, 100, 120
        
        //list.Clear();
        
        //std::cout << list << std::endl; //empty
        
        list.AddToTail(&c3);
        
       // std::cout << list << std::endl; //160
        
       
        List list2; 
        Circle ct(10,10, 100);
        list2.AddToHead(&ct);
        
        list2 = list;
        std::cout << list << " ### " << std::endl;
        std::cout << list2 << " *** " << std::endl;
        
        List list3;
        list3.AddToHead(&c1);
        list3.AddToHead(&c2);
        list3.AddToHead(&c3); 
        
        /*
        std::cout << list << " *** " << std::endl;
        std::cout << list3 << " *** " << std::endl;
        list = std::move(list3);
        std::cout << list << "  list = list3 " << std::endl;
        std::cout << list3 << " list3 " << std::endl;
        */
        List list4(list); //std::move
         std::cout << " list "  << list << std::endl;
         std::cout << " list4 "  << list4 << std::endl;
         
        list4 = list3;//std::move
        
        std::cout << " list3 "  << list3 << std::endl;
        std::cout << " list4 "  << list4 << std::endl;
        
        List list5(list);
        list5.AddToHead(&c1);
        std::cout << " list5 "  << list5 << std::endl;
        list5 = list3; //std::move
        
         std::cout << " list5 "  << list5 << std::endl;
        std::cout << " list3 "  << list3 << std::endl;
    }
    ///
    
    //1. сортировку по возрастанию площади объекта.
    {/*
    
        
        List list;
        for (int i = 0; i < 8; i ++) {
            Circle c(0,0, i);
            if (i % 2 == 0) {
                list.AddToTail(&c);
            } else {
                list.AddToHead(&c);
            } 
        }
        
        
        std::cout << list << std::endl;
        
        list.SortBySquare();
        
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
            
        } */
    }
	
    return 0;
}//endmain

